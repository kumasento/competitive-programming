#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <bits/stdc++.h>

using namespace std;

/** Example test case:
TEST_CASE("testing the factorial function") {
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}
*/

#define DEBUG
#ifndef DEBUG
#define LOG(msg) 
#else
#define LOG(msg) cerr << (msg) << endl;
#endif

struct Street;
struct Car;
struct Intersect;
struct Simulator;
struct Schedule;

/** Emulates the streets. */
struct Street {
  const int id;
  const int B, E, L; // begin and end, length of the street.
  const string name; // name of the street

  queue<int> cars;         // Queue of cars.
  bool has_popped = false; // Has popped out any car in the current tick

  Street(int id, int B, int E, const string &name, int L)
      : id(id), B(B), E(E), name(name), L(L) {}

  void reset();

  void push(int car, Simulator &sim);
  int pop(Simulator &sim);
};

/** Emulates the cars */
struct Car {
  const int id;           // car ID.
  const vector<int> path; // list of streets

  int pos, loc; // Street and its location
  bool inqueue; // Currently in a queue.

  Car(int id, const vector<int> &path) : id(id), path(path), pos(0) {}

  void init(Simulator &sim);
  void tick(Simulator &sim);
  void reset();
};

/** Model the intersection of streets. */
struct Intersect {
  const int id;
  vector<int> in, out;
  vector<int> ord, time;  // The schedule.
  int curr_tick, curr_id; // The id of the current end street, and the tick.

  Intersect(const int &id) : id(id) {}

  void tick();
  void init();
  void reset();

  optional<int> get_green() const;
  void set_sched(const Schedule &sched);
};

/** Model the scheduling of the each intersection. */
struct Schedule {
  // ords[i] the order of streets, indexed within the intersect.
  // times[i] for each street how many cycles they should take.
  vector<vector<int>> ords, times;

  Schedule() {}
  Schedule(const vector<vector<int>> &ords, const vector<vector<int>> &times)
      : ords(ords), times(times) {}
};

/** The main actor that simulates the world. */
class Simulator {
  vector<Street> streets;
  vector<Car> cars;
  vector<Intersect> intersects;
  map<string, int> name_to_street;

  int D, I, S, V, F;

public:
  Simulator(int I, int S, int V, int F) : I(I), S(S), V(V), F(F) {
    for (int i = 0; i < I; i++)
      intersects.emplace_back(i);
  }

  static Simulator read_file(const string &fname);

  void add_street(int B, int E, const string &name, int L) {
    int id = streets.size();

    streets.emplace_back(id, B, E, name, L);
    name_to_street[name] = id;

    intersects[B].in.push_back(id);
    intersects[E].out.push_back(id);
  }

  void add_car(const vector<string> &names) {
    int id = cars.size();
    vector<int> path(names.size());
    transform(names.begin(), names.end(), path.begin(),
              [&](const string &name) { return this->name_to_street[name]; });
    cars.emplace_back(id, path);
  }

  Street &get_street(size_t id) { return streets.at(id); }
  Car &get_car(size_t id) { return cars.at(id); }
  Intersect &get_intersect(size_t id) { return intersects.at(id); }

  void set_duration(int D) { this->D = D; }

  // reset the environment for each run.
  void reset();
  // Run simulation, return the total time.
  int run(const Schedule &sched);
  int run(int D, const Schedule &sched);
};

/** Car methods */
void Car::init(Simulator &sim) {
  Street &start = sim.get_street(path[pos]);

  loc = start.L;
  start.push(id, sim);
}

void Car::reset() { pos = 0, inqueue = false; }

void Car::tick(Simulator &sim) {
  if (pos == path.size()) // already terminated.
    return;

  auto enqueue_or_exit = [&]() {
    Street &street = sim.get_street(path[pos]);
    if (loc == street.L) {
      if (pos + 1 == path.size()) { // reaches to the end.
        pos++;
        return;
      }
      street.push(id, sim);
    }
  };

  Street &curr_street = sim.get_street(path[pos]);
  if (loc + 1 <= curr_street.L) {
    ++loc;
    enqueue_or_exit();
    return;
  }

  Intersect &intr = sim.get_intersect(curr_street.E);

  // The light is green and the car is at the front of the queue.
  if (intr.get_green() == curr_street.id &&
      (!curr_street.has_popped && id == curr_street.cars.front())) {
    curr_street.pop(sim);
    ++pos, loc = 1;

    enqueue_or_exit();
  }
}

/** Street methods */
void Street::reset() {
  has_popped = false;
  while (!cars.empty())
    cars.pop();
}

void Street::push(int car, Simulator &sim) {
  cars.push(car);
  sim.get_car(car).inqueue = true;
}

int Street::pop(Simulator &sim) {
  int car = cars.front();
  cars.pop();
  sim.get_car(car).inqueue = false;
  has_popped = true;
  return car;
}

/** Intersect methods */
void Intersect::reset() {
  ord.clear();
  time.clear();
}

void Intersect::set_sched(const Schedule &sched) {
  ord = sched.ords.at(id);
  time = sched.times.at(id);

  assert(ord.size() == time.size());
  assert(all_of(ord.begin(), ord.end(),
                [&](const int &i) {
                  return i == clamp(i, 0, (int)this->out.size() - 1);
                }) &&
         "ord should be within range.");
  assert(
      all_of(time.begin(), time.end(), [&](const int &tm) { return tm > 0; }) &&
      "Time should be positive.");
  assert(unique(ord.begin(), ord.end()) == ord.end() &&
         "All values in ord should be unique");
}

void Intersect::tick() {
  if (ord.empty()) // no effect.
    return;

  ++curr_tick;
  if (curr_tick == time[curr_id]) {
    curr_id = (curr_id + 1) % ord.size();
    curr_tick = 0;
  }
}

void Intersect::init() {
  curr_id = 0;
  curr_tick = 0;
}

optional<int> Intersect::get_green() const {
  if (ord.empty())
    return {};
  return out[ord[curr_id]];
}

TEST_CASE("Intersect::tick") {
  Intersect intr(0);
  intr.out = {3, 1, 2, 0};
  intr.set_sched({{{0, 1, 3}}, {{2, 1, 3}}});

  intr.init();
  CHECK(intr.get_green() == 3);

  intr.tick();
  CHECK(intr.get_green() == 3);
  intr.tick();
  CHECK(intr.get_green() == 1);
  intr.tick();
  CHECK(intr.get_green() == 0);
  intr.tick();
  intr.tick();
  intr.tick();
  CHECK(intr.get_green() == 3);
}

TEST_CASE("Intersect::tick single light") {
  Intersect intr(0);
  intr.out = {2, 5, 4, 7};
  intr.set_sched({{{1}}, {{2}}});

  intr.init();
  CHECK(intr.get_green() == 5);
  intr.tick();
  CHECK(intr.get_green() == 5);
  intr.tick();
  CHECK(intr.get_green() == 5);
  intr.tick();
  CHECK(intr.get_green() == 5);
}

TEST_CASE("Intersect::tick all red") {
  Intersect intr(0);
  intr.init();
  CHECK(!intr.get_green().has_value());
  intr.tick();
  CHECK(!intr.get_green().has_value());
}

/** Simulator methods */
void Simulator::reset() {
  for (Car &car : cars)
    car.reset();
  for (Street &street : streets)
    street.reset();
  for (Intersect &intersect : intersects)
    intersect.reset();
}

int Simulator::run(const Schedule &sched) { return run(D, sched); }

int Simulator::run(int D, const Schedule &sched) {
  reset();
  // initialize car positions.
  for (Car &car : cars)
    car.init(*this);

  for (Intersect &intersect : intersects) {
    intersect.init();
    intersect.set_sched(sched);
  }

  for (Street &street : streets)
    street.has_popped = false;

  for (int T = 0; T < D; T++) {
    for (Street &street : streets)
      street.has_popped = false;
    // Read light T = 0
    for (Car &car : cars)
      car.tick(*this);
    for (Intersect &intersect : intersects)
      intersect.tick();
  }

  return 0;
}

Simulator Simulator::read_file(const string &fname) {
  ifstream in(fname);
  assert(in);

  int D, I, S, V, F;
  in >> D >> I >> S >> V >> F;

  Simulator sim(I, S, V, F);
  sim.set_duration(D);
  for (int i = 0; i < S; i++) {
    int B, E, L;
    string S;
    in >> B >> E >> S >> L;
    sim.add_street(B, E, S, L);
  }
  for (int i = 0; i < V; i++) {
    int P;
    in >> P;
    vector<string> path(P);
    for (string &s : path)
      in >> s;
    sim.add_car(path);
  }

  return sim;
}

// --- Tests

TEST_CASE("Car::tick two streets") {
  Simulator sim(/*I=*/3, /*S=*/2, /*V=*/3, 1);
  sim.add_street(0, 1, "s1", 1);
  sim.add_street(1, 2, "s2", 2);
  for (int i = 0; i < 3; i++)
    sim.add_car({"s1", "s2"});

  Schedule sched{{{}, {0}, {}}, {{}, {1}, {}}};

  sim.run(0, sched);
  CHECK(sim.get_car(0).pos == 0);
  CHECK(sim.get_car(0).loc == 1);
  CHECK(sim.get_car(1).pos == 0);
  CHECK(sim.get_car(1).loc == 1);
  CHECK(sim.get_car(2).pos == 0);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(1, sched);
  CHECK(sim.get_intersect(1).get_green() == 0);
  CHECK(sim.get_car(0).pos == 1);
  CHECK(sim.get_car(0).loc == 1);
  CHECK(sim.get_car(1).pos == 0);
  CHECK(sim.get_car(1).loc == 1);
  CHECK(sim.get_car(2).pos == 0);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(2, sched);
  CHECK(sim.get_intersect(1).get_green() == 0);
  CHECK(sim.get_car(0).pos == 2);
  CHECK(sim.get_car(1).pos == 1);
  CHECK(sim.get_car(1).loc == 1);
  CHECK(sim.get_car(2).pos == 0);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(3, sched);
  CHECK(sim.get_car(0).pos == 2);
  CHECK(sim.get_car(1).pos == 2);
  CHECK(sim.get_car(2).pos == 1);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(4, sched);
  CHECK(sim.get_car(0).pos == 2);
  CHECK(sim.get_car(1).pos == 2);
  CHECK(sim.get_car(2).pos == 2);
}

TEST_CASE("Car::tick two streets") {
  Simulator sim(/*I=*/4, /*S=*/3, /*V=*/3, 1);
  sim.add_street(0, 1, "s1", 1);
  sim.add_street(1, 2, "s2", 1);
  sim.add_street(2, 3, "s3", 1);
  for (int i = 0; i < 3; i++)
    sim.add_car({"s1", "s2", "s3"});

  Schedule sched{{{}, {0}, {0}, {}}, {{}, {1}, {1}, {}}};

  sim.run(0, sched);
  CHECK(sim.get_car(0).pos == 0);
  CHECK(sim.get_car(0).loc == 1);
  CHECK(sim.get_car(1).pos == 0);
  CHECK(sim.get_car(1).loc == 1);
  CHECK(sim.get_car(2).pos == 0);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(1, sched);
  CHECK(sim.get_car(0).pos == 1);
  CHECK(sim.get_car(0).loc == 1);
  CHECK(sim.get_car(1).pos == 0);
  CHECK(sim.get_car(1).loc == 1);
  CHECK(sim.get_car(2).pos == 0);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(2, sched);
  CHECK(sim.get_car(0).pos == 3);
  CHECK(sim.get_car(1).pos == 1);
  CHECK(sim.get_car(1).loc == 1);
  CHECK(sim.get_car(2).pos == 0);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(3, sched);
  CHECK(sim.get_car(0).pos == 3);
  CHECK(sim.get_car(1).pos == 3);
  CHECK(sim.get_car(2).pos == 1);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(4, sched);
  CHECK(sim.get_car(0).pos == 3);
  CHECK(sim.get_car(1).pos == 3);
  CHECK(sim.get_car(2).pos == 3);
}

TEST_CASE("Car::tick two street intersect") {
  Simulator sim(/*I=*/4, /*S=*/3, /*V=*/2, 1);
  sim.add_street(0, 2, "s02", 1);
  sim.add_street(1, 2, "s12", 1);
  sim.add_street(2, 3, "s23", 2);

  sim.add_car({"s02", "s23"});
  sim.add_car({"s12", "s23"});
  sim.add_car({"s12", "s23"});

  Schedule sched{{{}, {}, {0, 1}, {}}, {{}, {}, {2, 1}, {}}};
  sim.run(0, sched);
  CHECK(sim.get_car(0).pos == 0);
  CHECK(sim.get_car(0).loc == 1);
  CHECK(sim.get_car(1).pos == 0);
  CHECK(sim.get_car(1).loc == 1);
  CHECK(sim.get_car(2).pos == 0);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(1, sched);
  CHECK(sim.get_car(0).pos == 1);
  CHECK(sim.get_car(0).loc == 1);
  CHECK(sim.get_car(1).pos == 0);
  CHECK(sim.get_car(1).loc == 1);
  CHECK(sim.get_car(2).pos == 0);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(2, sched);
  CHECK(sim.get_car(0).pos == 2);
  CHECK(sim.get_car(1).pos == 0);
  CHECK(sim.get_car(1).loc == 1);
  CHECK(sim.get_car(2).pos == 0);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(3, sched);
  CHECK(sim.get_car(0).pos == 2);
  CHECK(sim.get_car(1).pos == 1);
  CHECK(sim.get_car(1).loc == 1);
  CHECK(sim.get_car(2).pos == 0);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(4, sched);
  CHECK(sim.get_car(0).pos == 2);
  CHECK(sim.get_car(1).pos == 2);
  CHECK(sim.get_car(2).pos == 0);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(5, sched);
  CHECK(sim.get_car(0).pos == 2);
  CHECK(sim.get_car(1).pos == 2);
  CHECK(sim.get_car(2).pos == 0);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(6, sched);
  CHECK(sim.get_car(0).pos == 2);
  CHECK(sim.get_car(1).pos == 2);
  CHECK(sim.get_car(2).pos == 1);
  CHECK(sim.get_car(2).loc == 1);

  sim.run(7, sched);
  CHECK(sim.get_car(0).pos == 2);
  CHECK(sim.get_car(1).pos == 2);
  CHECK(sim.get_car(2).pos == 2);
}

TEST_CASE("Test data a.txt") {
  auto sim = Simulator::read_file("../a.txt");

  Schedule sched{{{0}, {1, 0}, {0}, {}}, {{2}, {2, 1}, {1}, {}}};

  sim.run(sched);
}
