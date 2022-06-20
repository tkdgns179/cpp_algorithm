//
// Created by HOME on 2022-04-26.
//
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

int number = 9;
bool visit[9];
vector<int> a[10];

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            if(!visit[y]) {
                q.push(y);
                visit[y] = true;
            }
        }
    }
}

bool visited[1001];
vector<int> graph[1001];
stack<int> s;
queue<int> q;

void dfs(int start) {
    s.push(start);
    visited[start] = true;
    cout << start << " ";
    while (!s.empty()) {
        int current = s.top();
        bool flag = false;
        for (int i = 0; i < graph[current].size(); ++i) {
            if (visited[graph[current][i]] != true && graph[current][i] != 0) // graph[current][i] != 0 -> 간선이 연결되어있다
            {
                s.push(graph[current][i]);
                visited[graph[current][i]] = true;
                flag = true;
                cout << graph[current][i] << " ";
                break;
            }
        }
        if (flag == false)
            s.pop();

    }
}
int main() {
//    a[1].push_back(2); a[2].push_back(1);
//    a[1].push_back(3); a[3].push_back(1);
//    a[2].push_back(4); a[4].push_back(2);
//    a[2].push_back(5); a[5].push_back(2);
//    a[4].push_back(8); a[8].push_back(4);
//    a[5].push_back(9); a[9].push_back(5);
//    a[3].push_back(6); a[6].push_back(3);
//    a[3].push_back(7); a[7].push_back(3);
//    bfs(1);
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);
    memset(visited, false, n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    memset(visited, false, n + 1);
    cout << endl;
    dfs(start);


    return 0;
}