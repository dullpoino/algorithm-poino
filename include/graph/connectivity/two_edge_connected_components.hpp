#pragma once
#include "common.hpp"

void ECC(VVPLL &G, VL &hasi, VVL &ecc, VL &id)
{
    ll N = sz(G);
    id.assign(N, -1);

    deque<ll> q;

    rep(i, 0, N) {
        if (id[i] != -1) {
            continue;
        }

        ll k = sz(ecc);
        ecc.push_back(VL());

        id[i] = k;
        q.push_back(i);

        while (q.empty() == false) {
            auto cur = popb(q);

            ecc[k].push_back(cur);

            for (auto &[next, e] : G[cur]) {
                if (hasi[e] != 0 || id[next] != -1) {
                    continue;
                }

                id[next] = k;
                q.push_back(next);
            }
        }
    }
}
