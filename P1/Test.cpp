#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int x, int y, vector<vector<int>> &graph)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
//        cout << graph.size() << "/" << graph[1].size();
        while (true) {
            if (x < 0 || y < 0 || x > graph[1].size() || y > graph.size()) break;

            if (graph[x][y] == 1) {
                graph[x][y] = 0;
                cnt++;
                for (int i = 0; i < 4; i++) {
                    q.push({x + dir[i][0], y + dir[i][1]});
                }
            }

            break;
        }
    }
//    cout << cnt << endl;
    return cnt;
}

int main() {

    vector<vector<int>> v = {{1,1,0,1,1},{0,1,1,0,0},{0,0,0,0,0},{1,1,0,1,1},{1,0,1,1,1},{1,0,1,1,1}};
        int cnt = 0;
    int max = 0;
    for (int i = 0; i < v[1].size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (v[i][j] == 1) {
                cnt++;
                int temp = bfs(i, j, v);
                if (temp > max) {
                    max = temp;
                }
            }
        }
    }
    vector<int> answer;
    answer.push_back(cnt);
    answer.push_back(max);
    cout << cnt << " " << max << endl;
    return 0;
}
