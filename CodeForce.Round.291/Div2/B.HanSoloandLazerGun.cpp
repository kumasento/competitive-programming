
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<pair<double, double>, double> StraightLine;

#define A(x) (x.first.first)
#define B(X) (x.first.second)
#define C(x) (x.second)

int main()
{
    int n, x0, y0; cin>>n>>x0>>y0;
    map<StraightLine, int> hash;
    for (int i = 0; i < n; i++)
    {
        StraightLine sline;
        int x, y; cin >> x >> y;
        sline.first.first  = (double)(-y - y0);
        sline.first.second = (double)(-x - x0);
        sline.second       = (double)(x0*y - x*y0);

        cout << sline.first.first << ' ' << sline.first.second << ' '
            << sline.second << endl;

        if (hash.find(sline) != hash.end())
            hash[sline] ++;
        else
            hash[sline] = 1;
    }
    cout << hash.size() << endl;
    return 0;
}
