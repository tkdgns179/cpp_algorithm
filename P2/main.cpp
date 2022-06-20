//
// Created by HOME on 2022-05-25.
//

#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;
using ll = long long;
const int MAX = 501;
int dp[MAX][MAX];

int main()
{
    int N, r[MAX], c[MAX];
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &r[i], &c[i]);
        dp[i][i] = 0;
    }
    for (int s = 0; s < N; s++) {
        for (int i = 0; i < N-s; i++) {
            int j = s + i;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + r[i]*r[k+1]*c[j]);
            }
        }
    }
    return 0;
}
