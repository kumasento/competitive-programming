#include <bits/stdc++.h>

using namespace std;

struct Ride {
  int a, b, x, y, s, f;
};

using Mat = vector<vector<int>>;

int R, C, F, N, B, T;
vector<Ride> rides;

int score(const Mat &A) {
  int tot = 0;

  for (int i = 0; i < F; i++) {
    vector<int> tasks(N, -1);
    for (int j = 0; j < N; j++)
      if (A[i][j] >= 0)
        tasks[A[i][j]] = j;

    cout << "Tasks: ";
    for (int j = 0; j < N; j ++)
      cout << tasks[j] << " ";
    cout << endl;

    // simulate each task
    pair<int, int> pos = {0, 0};
    int time = 0;
    for (int j = 0; j < N; j++) {
      if (tasks[j] < 0)
        break;

      Ride &ride = rides[tasks[j]];

      int dist = abs(ride.a - ride.x) + abs(ride.b - ride.y);
      int time_to_start = abs(ride.a - pos.first) + abs(ride.b - pos.second);
      int time_to_dest = dist;

      int time_start = max(time + time_to_start, ride.s);
      int time_finish = time_start + time_to_dest;

      cout << "Vehicle " << i << " starts to handle ride " << tasks[j] << " at "
           << time << endl;
      cout << "Ride: (" << ride.a << " " << ride.b << ") -> (" << ride.x << ", "
           << ride.y << ") s = " << ride.s << " f = " << ride.f << endl;
      cout << "Time to the starting position: " << time_to_start << endl;
      cout << "Time starts: " << time_start << endl;
      cout << "Time to dest: " << time_to_dest << endl;
      cout << "Time finish: " << time_finish << endl;

      if (time_finish < ride.f) {
        tot += dist;
        cout << "Finished on time: " << tot << endl;
      }
      if (time_start == ride.s) {
        tot += B;
        cout << "Started on time: " << tot << endl;
      }

      cout << "New score! " << tot << endl;

      // Arrived
      pos = {ride.x, ride.y};
      time = time_finish;
    }
  }

  return tot;
}

int main(int argc, char *argv[]) {
  ifstream in(argv[1]);
  assert(in);

  in >> R >> C >> F >> N >> B >> T;

  rides.resize(N);
  for (int i = 0; i < N; i++)
    in >> rides[i].a >> rides[i].b >> rides[i].x >> rides[i].y >> rides[i].s >>
        rides[i].f;

  // A[i][j] - assign ride j to car i in the fleet, value represents execution
  // order.
  Mat A(F, vector<int>(N, -1));

  A[0][0] = 0;
  A[1][2] = 0;
  A[1][1] = 1;

  cout << score(A) << endl;

  in.close();
}
