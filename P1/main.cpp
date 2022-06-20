#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
class LESS
{
public:
    bool operator()(int a, int b)
    {
        return a < b;
    }
};

int main() {
//    int N;
//    scanf("%d", &N);
//    vector<int> v;
//    for (int i=0; i<N; i++) {
//        int n;
//        scanf("%d", &n);
//        v.push_back(n);
//    }
//    sort(v.begin(), v.end(), LESS());
//    for (auto iter=v.begin(); iter != v.end(); iter++) {
//        cout << *iter << " ";
//    }

    vector<pair<int, int>> vector[5];
    vector[0].push_back(make_pair(1, 2));
    vector[0].push_back(make_pair(1, 3));
    vector[1].push_back({1, 2});
    vector[1].push_back({2, 3});
    int arr[3] = {1, 2, 3};
    int* ptr_arr = arr;
    ptr_arr[2] = 4;
    cout << ptr_arr[2] << endl;
    return 0;
}
