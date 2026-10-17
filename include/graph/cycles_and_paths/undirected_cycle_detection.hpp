#pragma once
#include "common.hpp"

bool hasCycle(VVL &G, ll start)
{
    ll N = sz(G);

    VL visited(N, 0);

    deque<tuple<ll, ll, ll>> q;

    visited[start] = 1;
    q.push_back({ start, 0, -1 });

    while (q.empty() == false) {
        auto &[cur, idx, par] = q.back();

        if (idx == sz(G[cur])) {
            q.pop_back();
            continue;
        }

        ll next = G[cur][idx++];

        if (next == par) {
            continue;
        }

        if (visited[next] != 0) {
            return true;
        }

        visited[next] = 1;
        q.push_back({ next, 0, cur });
    }

    return false;
}
