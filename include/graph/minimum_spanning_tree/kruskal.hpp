#pragma once
#include "common.hpp"

bool comp(const tuple<ll, ll, ll> &e1, const tuple<ll, ll, ll> &e2)
{
    return get<2>(e1) < get<2>(e2);
}

bool kruskal(ll N, VEC<tuple<ll, ll, ll>> &E, ll &res)
{
    sort(all(E), comp);

    UnionFind Z;
    res = 0;
    ll cntedge = 0;

    for (auto &[from, to, cost] : E) {
        if (Z.same(from, to) == false) {
            Z.unite(from, to);
            res += cost;
            ++cntedge;

            if (cntedge == N - 1) {
                break;
            }
        }
    }

    return cntedge == N - 1;
}
