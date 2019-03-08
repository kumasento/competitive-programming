
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
    int a[n];
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]), pos[a[i]]=i;
    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        int num; scanf("%d", &num);
        sum += (long long)pos[num]/k + 1;
        if (pos[num] != 0)
        {
            int swapped_num = a[pos[num]-1];
            swap(a[pos[num]], a[pos[num]-1]);
            pos[swapped_num] ++;
            pos[num] --;
        }
        //for (int i = 0; i < n; i++)
        //    cout << a[i] << ' ';
        //cout << endl;
    }
    cout << sum << endl;
    return 0;
}
