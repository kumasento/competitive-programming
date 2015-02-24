
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define MAXN 2010

using namespace std;

double dp[MAXN][MAXN];

int main()
{
    int n, t; double p; cin>>n>>p>>t;
    for (int i = 0; i <= n; i++)
        memset(dp[i], 0, sizeof(dp[i]));
    dp[0][1] = 1-p;
    dp[1][1] = p;
    for (int i = 2; i <= t; i++)
        dp[0][i] = (1-p) * dp[0][i-1];
    for (int j = 2; j <= t; j++)
        for (int i = 1; i <= n && i <= t; i++)
            dp[i][j] = p * dp[i-1][j-1] +
                       ((i == n) ? 1 : (1-p)) * dp[i][j-1];
    double sum = 0;
    for (int i = 1; i <= n; i++)
        sum += dp[i][t] * i;
    printf("%.8f\n", sum);
    return 0;
}
