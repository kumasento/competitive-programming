
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cstdio>

using namespace std;

int main()
{
    int n, m, k; cin>>n>>m>>k;
    int pos[n];
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        scanf("%d", &pos[i]), hash[pos[i]]=i;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int id; scanf("%d", &id);
        int p = hash[id];

        sum += p / k + 1;
        int prev_id = (p == 0) ? pos[0] : pos[p-1];
        swap(pos[p], pos[p-1]);
        hash[id] = p-1;
        hash[prev_id] = p;
    }
    cout << sum << endl;
    return 0;
}
