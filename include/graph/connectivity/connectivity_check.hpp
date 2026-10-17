#pragma once
#include "common.hpp"

void isConnect(VVL &G, VL &visited, ll start)
{
    ll N = sz(G);

    deque<PLL> q;

    visited[start] = 1;
    q.push_back({ start, 0 });

    while (q.empty() == false) {
        auto &[cur, idx] = q.back();

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
