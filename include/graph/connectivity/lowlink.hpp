#pragma once
#include "common.hpp"

void LowLink(VVPLL &G, VL &order, VL &low, VL &parent_v, VL &parent_e, VL &childs)
{
    ll N = sz(G);
    ll idx = 0;

    order.assign(N, -1);
    low.assign(N, -1);
    parent_v.assign(N, -1);
    parent_e.assign(N, -1);
    childs.assign(N, 0);

    deque<PLL> q;

    rep(i, 0, N) {
        if (order[i] != -1) {
            continue;
        }

        order[i] = idx;
        low[i] = idx;
        ++idx;
        q.push_back({ i, 0 });

        while (q.empty() == false) {
            auto &[cur, pos] = q.back();

            if (pos == sz(G[cur])) {
                ll v = cur;
                q.pop_back();

                if (parent_v[v] != -1) {
                    chmin(low[parent_v[v]], low[v]);
                }

                continue;
            }

            auto [nextv, nexte] = G[cur][pos++];

            if (nexte == parent_e[cur]) {
                continue;
            }

            if (order[nextv] != -1) {
                if (order[nextv] < order[cur]) {
                    chmin(low[cur], order[nextv]);
                }
                continue;
            }

            parent_v[nextv] = cur;
            parent_e[nextv] = nexte;
            ++childs[cur];

            order[nextv] = idx;
            low[nextv] = idx;
            ++idx;
            q.push_back({ nextv, 0 });
        }
    }
}
