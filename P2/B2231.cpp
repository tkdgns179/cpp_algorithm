//
// Created by HOME on 2022-06-16.
//

#include <iostream>

using namespace std;

int solution(long n, int cnt)
{
    int radix = 1e1;

    for (int i = n - cnt*9; i < n; ++i) {
        int tmp = i;
        long sum = 0;
        do {
            sum += tmp%radix;
            tmp = (int)tmp/radix;
        } while (tmp != 0);
        sum += i;
        if ( sum == n ) return i;
    }

    return 0;
}

int main()
{
    long n, cnt = 0;
    long radix = 1e1;
    cin >> n;
    int tmp = n;
    do {
        cnt++;
    } while ( ( tmp = (int)tmp/radix ) != 0);
//    cout << cnt;
    cout << solution(n, cnt);

    return 0;
}
