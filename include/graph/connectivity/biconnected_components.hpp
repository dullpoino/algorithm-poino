#pragma once
#include "common.hpp"

void BCC(VVPLL &G, VL &order, VL &low, VL &parent_v, VL &parent_e, VL &childs, VVL &bcc)
{
    ll N = sz(G);

    VL mark(N, -1);
    deque<tuple<ll, ll, ll>> eq;
    deque<PLL> q;

    rep(i, 0, N) {
        if (parent_v[i] != -1) {
            continue;
        }

        q.push_back({ i, 0 });

        while (q.empty() == false) {
            auto &[cur, pos] = q.back();

            if (pos == sz(G[cur])) {
                ll done = cur;
                q.pop_back();

                ll p = parent_v[done];

                if (p != -1 && order[p] <= low[done]) {
                    ll id = sz(bcc);
                    VL vs;

                    while (true) {
                        auto [e, u, v] = eq.back();
                        eq.pop_back();

                        if (mark[u] != id) {
                            mark[u] = id;
                            vs.push_back(u);
                        }

                        if (mark[v] != id) {
                            mark[v] = id;
                            vs.push_back(v);
                        }

                        if (e == parent_e[done]) {
                            break;
                        }
                    }

                    bcc.push_back(vs);
                }

                continue;
            }

            auto [next, e] = G[cur][pos++];

            if (e == parent_e[cur]) {
                continue;
            }

            if (parent_v[next] == cur && parent_e[next] == e) {
                eq.push_back({ e, cur, next });
                q.push_back({ next, 0 });
            }
            else if (order[next] < order[cur]) {
                eq.push_back({ e, cur, next });
            }
        }
    }
}
