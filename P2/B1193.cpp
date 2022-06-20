//
// Created by HOME on 2022-06-15.
//

#include <iostream>
#include <vector>

using namespace std;
const long INF = 1e9;

void solution(vector<int>& vec, int n) {
    vector<int>::iterator it = vec.begin();
    while (it != vec.end()) {
        if (n > *it) it++;
        else break;
    }
    int row = distance(vec.begin(), it) + 1;
    int dist = *it - n;
//    cout << "row = " << row << "/" << "dist = " << dist << endl;

    int a, b;

    if (row % 2 == 0) {
        a = row - dist; b = 1 + dist;
    } else {
        a = 1 + dist; b = row - dist;
    }

    cout << a << "/" << b;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 1; i < n + 1; i++) {
        int sum = i*(i+1)/2;
//        cout << sum << endl;
        if (sum > INF) break;
        vec.push_back(sum);
    }
    solution(vec, n);

    return 0;
}