#pragma once
#include "common.hpp"

/**********************************************************
BFS
**********************************************************/

void bfs(VVL &G, VEC<bool>& visited, ll start)
{
    deque<ll> q;

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