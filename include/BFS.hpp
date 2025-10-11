#pragma once
#include "common.hpp"

/**********************************************************
BFS
**********************************************************/
void bfs(vector<vector<ll> > &G, ll start)
{
    deque<ll> q;
    vector<ll> visited(sz(G));

    q.push_back(start);
    visited[start] = 1;

    while (!q.empty()) {
        ll n = sz(q);
        while (n--) {
            auto p = popf(q);

            for (auto next : G[p]) {
                if (visited[next] == 0) {
                    q.push_back(next);
                    visited[next] = 1;
                }
            }
        }
    }
}