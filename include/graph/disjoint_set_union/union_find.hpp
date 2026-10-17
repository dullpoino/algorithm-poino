#pragma once
#include "common.hpp"

struct UnionFind
{
    ll par[200001];

    UnionFind(void)
    {
        fill(begin(par), end(par), -1);
    }

    ll root(ll x)
    {
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }

    bool same(ll x, ll y)
    {
        return root(x) == root(y);
    }

    bool isroot(ll x)
    {
        return root(x) == x;
    }

    void unite(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if (x == y) {
            return;
        }

        if (-par[x] < -par[y]) {
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
    }

    ll getSize(ll x)
    {
        return -par[root(x)];
    }
};
