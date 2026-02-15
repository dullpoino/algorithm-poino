#pragma once
#include "common.hpp"

/**********************************************************
重み付きUnionFind
**********************************************************/

struct WUnionFind {
    ll par[GSZ];
    ll weight[GSZ];

    WUnionFind(void) {
        fill(begin(par), end(par), -1);
        fill(begin(weight), end(weight), 0);
    }

    ll root(ll x)
    {
        if (par[x] < 0) return x;
        ll r = root(par[x]);
        weight[x] += weight[par[x]];
        return par[x] = r;
    }

    bool same(ll x, ll y)
    {
        return root(x) == root(y);
    }

    bool unite(ll x, ll y, ll d)
    {
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry) return weight[x] - weight[y] == d;

        if (-par[rx] < -par[ry]) {
            par[ry] += par[rx];
            par[rx] = ry;
            weight[rx] = weight[y] - weight[x] + d;
        }
        else {
            par[rx] += par[ry];
            par[ry] = rx;
            weight[ry] = weight[x] - weight[y] - d;
        }

        return true;
    }

    ll getSize(ll x)
    {
        return -par[root(x)];
    }
};