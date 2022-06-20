//
// Created by HOME on 2022-06-18.
//

#include <iostream>
#include <stack>
#define forn(i, a, b) for(int i = a; i <= b; i++)
using namespace std;

void n_push(stack<int>& s, int from, int to) {
    forn(i, from, to) {
        s.push(i);
    }
}

int main()
{
    int n;
    cin >> n;
    stack<int> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int idx = 0;
    int _idx = 0;
    int check = -1;
    int from = 1;
    char printText[n*2];
    do {
        if (!s.empty() && s.top() == arr[idx]) {
            printText[_idx++] = '-';
            s.pop();
            idx++;
        }
        else {
            if (from > arr[idx]) {
                cout << "NO";
                return 0;
            }
            for (int i = 0; i < (arr[idx] - from + 1); i++) {
                printText[_idx++] = '+';
            }
            n_push(s, from, arr[idx]);
            from = 1 + arr[idx];
            idx++;
            s.pop();
            printText[_idx++] = '-';
        }

    } while (!s.empty() || idx < n);
    forn(i, 0, 2*n -1) {
        cout << printText[i] << "\n";
    }
    return 0;
}