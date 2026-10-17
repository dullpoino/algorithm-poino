#pragma once
#include "common.hpp"

bool sortT(VVPLL &G, VL &order)
{
    ll N = sz(G);
    VL indeg(N, 0);

    rep(i, 0, N) {
        for (auto [next, cost] : G[i]) {
            ++indeg[next];
        }
    }

    deque<ll> q;
    rep(i, 0, N) {
        if (indeg[i] == 0) {
            q.push_back(i);
        }
    }

    while (q.empty() == false) {
        auto cur = popf(q);
        order.push_back(cur);

        for (auto &[next, cost] : G[cur]) {
            if (--indeg[next] == 0) {
                q.push_back(next);
            }
        }
    }

    return (sz(order) == N);
}
