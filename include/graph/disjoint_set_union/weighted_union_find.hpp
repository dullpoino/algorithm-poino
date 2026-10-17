#pragma once
#include "common.hpp"

struct WUnionFind
{
    ll par[200001];
    ll weight[200001];

    WUnionFind(void)
    {
        fill(begin(par), end(par), -1);
        fill(begin(weight), end(weight), 0);
    }

    ll root(ll x)
    {
        if (par[x] < 0) {
            return x;
        }
        ll p = par[x];
        par[x] = root(p);
        weight[x] += weight[p];
        return par[x];
    }

    bool same(ll x, ll y)
    {
        return root(x) == root(y);
    }

    bool isroot(ll x)
    {
        return root(x) == x;
    }

    bool unite(ll x, ll y, ll d)
    {
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry) {
            return weight[x] - weight[y] == d;
        }

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
