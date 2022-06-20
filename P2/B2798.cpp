//
// Created by HOME on 2022-06-16.
//

#include <iostream>
#include <vector>

using namespace std;

int n, m;
int solution(vector<int>& cards, vector<bool>& visited, int limit) {
    int arr[3];
    int MAX = -1;
    for (int i = 0; i < n; i++) { // 첫 번째로 뽑을 카드
        arr[0] = cards[i];
        visited[i] = true;
        for (int j = 0; j < n; j++) { // 두 번째..
            if (visited[j] == false) {
                arr[1] = cards[j];
                visited[j] = true;
                for (int k = 0; k < n; k++) { // 세 번째..
                    if (visited[k] == false) {
                        arr[2] = cards[k];
//                        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
                        int SUM = arr[0] + arr[1] + arr[2];
                        if (SUM > limit) continue;
                        MAX = MAX < SUM? SUM : MAX;
                    }
                }
                visited[j] = false;
            }

        }
        visited[i] = false;
    }
    return MAX;
}

int main() {

    cin >> n >> m;
    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }
    vector<bool> visited(n, false); // 뽑았던 카드 표시
    cout << solution(cards, visited, m);
    return 0;
}