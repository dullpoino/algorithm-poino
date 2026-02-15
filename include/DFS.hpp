#pragma once
#include "common.hpp"

/**********************************************************
DFS 再帰版
**********************************************************/

ll dfs(VVL& G, VEC<bool>& visited, ll cur)
{
    ll ret = 1;

    visited[cur] = true;

    for (auto next : G[cur]) {
        if (visited[next] == false) {
            ret += dfs(G, visited, next);
        }
    }

    return ret;
}