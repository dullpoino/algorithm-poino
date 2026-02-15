#pragma once
#include "common.hpp"

/**********************************************************
木の直径
**********************************************************/

ll treeDiameter(VVL &G)
{
    if (sz(G) <= 1) return 0;

    ll start = 1;
    ll res = 0;

    rep(i, 0, 2) {
        deque<PLL> q;
        ll d = 0;
        q.push_back({ start, -1 });

        while (!q.empty()) {
            ll n = sz(q);
            ++d;

            while(n--) {
                auto p = popf(q);
                start = fst(p);

                for (auto v : G[fst(p)]) {
                    if (v != snd(p)) {
                        q.push_back({ v, fst(p) });
                    }
                }
            }
        }

        res = d - 1;
    }

    return res;
}