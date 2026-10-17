#pragma once
#include "common.hpp"

void dfs(VVL &G, VL &visited, ll start, bool init, VL &order)
{
    ll N = sz(G);
    if (init == true) {
        visited.assign(N, 0);
    }

    deque<PLL> q;

    visited[start] = 1;
    q.push_back({ start, 0 });

    while (q.empty() == false) {
        auto &[cur, idx] = q.back();

        // 行きがけ
        if (idx == 0) {
            order.push_back(cur);
        }

        // 帰りがけ
        if (idx == sz(G[cur])) {


            q.pop_back();
            continue;
        }

        ll next = G[cur][idx++];

        if (visited[next] != 0) {
            continue;
        }

        visited[next] = 1;
        q.push_back({ next, 0 });
    }
}
