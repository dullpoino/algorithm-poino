#pragma once
#include "common.hpp"

/**********************************************************
DFS 再帰版
**********************************************************/
ll dfs(vector<vector<ll> >& G, vector<bool>& visited, ll cur)
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