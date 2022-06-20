//
// Created by HOME on 2022-04-26.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

stack<int> s;
queue<int> q;
vector<int> adj[1001];
//bool visited[1001];

void dfs(int start, bool* visited) {
    s.push(start);
    visited[start] = true;
    cout << start << " ";
    while ( !s.empty() ) {
        int current = s.top();
        bool flag = false;
        for ( int i = 0; i < adj[current].size(); ++i )
        {
            if ( visited[adj[current][i]] != true && adj[current][i] != 0 ) {
                s.push(adj[current][i]);
                visited[adj[current][i]] = true;
                flag = true;
                cout << adj[current][i] << " ";
                break;
            }
        }
        if (!flag) s.pop();
    }
}

int main() {
    int cnt = 0;
    int n, m;
    scanf("%d %d", &n, &m);
    bool visited[n+1];
    memset(visited ,false ,n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    for (int i = 1; i < n + 1; i++)
    {
        if(visited[i] == false)
        {
            dfs(i, visited);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}

