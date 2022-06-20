//
// Created by HOME on 2022-04-10.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<pair<int, int>> graph[20001];
int dist[20001];

int main() {
    int V, E, K;
    cin >> V >> E >> K;
    for (int i = 1, u, v, w; i <= E; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    for (int i = 1; i <= V; i++)
        dist[i] = INF;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, K));
    dist[K] = 0;

    while (!pq.empty()) {
        int tv = pq.top().second;
        int tw = -pq.top().first;
        pq.pop();

        for (int i = 0; i < graph[tv].size(); i++) {
            int nv = graph[tv][i].first;
            int nw = tw + graph[tv][i].second;

            if (nw < dist[nv]) {
                dist[nv] = nw;
                pq.push(make_pair(-nw, nv));
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}