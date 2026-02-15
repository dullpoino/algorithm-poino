#pragma once
#include "common.hpp"

/**********************************************************
DFS 非再帰版
**********************************************************/

void dfs_iterative(VVL&G, VEC<bool> &visited, ll start)
{
    deque<ll> q;
    q.push_back(start);
    visited[start] = true;

    while (!q.empty()) {
        auto p = popb(q);

        for (auto next : G[p]) {
            if (visited[next] == false) {
                q.push_back(next);
                visited[next] = true;
            }
        }
    }
}