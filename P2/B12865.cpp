//
// Created by HOME on 2022-06-17.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

class COMP
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        else {
            return a.first < b.first;
        }
    }
};

int main()
{
    int a, b;
    cin >> a >> b;
    int dp[a+1][b+1];
    fill(&dp[0][0], &dp[a][b], 0);
    vector<pair<int, int>> stuf = {{0, 0}};
    for (int i = 0; i < a; i++) {
        int w, v;
        cin >> w >> v;
        stuf.push_back({w,v});
    }
    sort(stuf.begin(), stuf.end(), COMP());
    for (int n = 1; n <= a; n++)
    {
        for (int k = 1; k <= b; k++)
        {
            if (k >= stuf[n].first) {
                dp[n][k] = MAX(dp[n-1][k], (dp[n-1][k-stuf[n].first] + stuf[n].second));
            }
            else dp[n][k] = dp[n-1][k];
        }
    }
    int max = -1;
    for (int i = 1; i <= b; i++) {
        max = MAX(max, dp[a][i]);
    }
    cout << max;
    return 0;
}

