//
// Created by HOME on 2022-06-17.
//

#include <iostream>
using namespace std;

long long dp[101] = {-1, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

int main()
{
    for (int i = 11; i <= 100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }
    for (int i = 1; i <= 100; i++) {
        cout << dp[i] << endl;
    }
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cout << dp[a];
    }
    return 0;
}

