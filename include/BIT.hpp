#pragma once
#include "common.hpp"

/**********************************************************
Binary Index Tree (フェニック木)
**********************************************************/
struct BIT {
    ll n;
    VEC<ll> bit;
    BIT(ll n_) : n(n_), bit(n_ + 1, 0ll) {}

    // j : 1-idx
    void add(ll j, ll x)
    {
        repdr(i, j, n, (i & -i)) {
            bit[i] += x;
        }
    }

    // j : 1-idx
    ll sum(ll j)
    {
        ll s = 0;

        rrepdr(i, 1, j, (i & -i)) {
            s += bit[i];
        }

        return s;
    }

    // l, r : 1-idx
    ll sum(ll l, ll r)
    {
        if (r < l) return 0ll;
        return sum(r) - sum(l - 1);
    }
};

struct BITMOD {
    ll n;
    ll m = MODM;
    VEC<ll> bit;
    BITMOD(ll n_) : n(n_), bit(n_ + 1, 0ll) {}

    // j : 1-idx
    void add(ll j, ll x)
    {
        repdr(i, j, n, (i & -i)) {
            bit[i] += m + x;
            bit[i] %= m;
        }
    }

    // j : 1-idx
    ll sum(ll j)
    {
        ll s = 0;

        rrepdr(i, 1, j, (i & -i)) {
            s += bit[i];
            s %= m;
        }

        return s;
    }

    // l, r : 1-idx
    ll sum(ll l, ll r)
    {
        if (r < l) return 0ll;
        return (m + sum(r) - sum(l - 1)) % m;
    }
};