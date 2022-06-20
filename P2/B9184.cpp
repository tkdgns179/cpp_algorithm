//
// Created by HOME on 2022-06-16.
//

#include <iostream>

using namespace std;
int memo[21][21][21];

int solution(int a, int b, int c) {

    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return solution(20, 20, 20);

    if (memo[a][b][c] != 0) return memo[a][b][c];
    else {
        if (a < b && b < c) memo[a][b][c] = solution(a, b, c-1) + solution(a, b-1, c-1) - solution(a, b-1, c);
        else memo[a][b][c] = solution(a-1, b, c) + solution(a-1, b-1, c) + solution(a-1, b, c-1) - solution(a-1, b-1, c-1);
    }

    return memo[a][b][c];
}

int main()
{
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = ", a, b, c);
        cout << solution(a, b, c) << endl;
    }
    return 0;
}
