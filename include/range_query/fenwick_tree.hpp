#pragma once
#include "common.hpp"

struct BIT
{
    public:
    BIT(ll n, ll mod = MODM) : n(n), mod(mod), bit(n + 1, 0)
    {
    }
    BIT(VL &v, ll mod = MODM) : n(sz(v)), mod(mod), bit(sz(v) + 1, 0)
    {
        rep(i, 0, n) {
            add(i + 1, v[i]);
        }
    }

    void add(ll idx, ll x)
    {
        if (idx <= 0 || n < idx) {
            return;
        }

        x %= mod;
        if (x < 0) {
            x += mod;
        }
        repdr(i, idx, n, (i & -i)) {
            bit[i] += x;
            if (bit[i] >= mod) {
                bit[i] -= mod;
            }
        }
    }

    void set(ll idx, ll x)
    {
        if (idx <= 0 || n < idx) {
            return;
        }

        x %= mod;
        if (x < 0) {
            x += mod;
        }
        add(idx, x - sum(idx, idx));
    }

    ll sum(ll idx)
    {
        if (idx <= 0 || n < idx) {
            return 0;
        }

        ll res = 0;
        rrepdr(i, 1, idx, (i & -i)) {
            res += bit[i];
            if (res >= mod) {
                res -= mod;
            }
        }
        return res;
    }

    ll sum(ll l, ll r)
    {
        if (l > r) {
            swap(l, r);
        }

        if (r <= 0 || n < l) {
            return 0;
        }

        chmax(l, 1ll);
        chmin(r, n);

        ll res = (sum(r) - sum(l - 1)) % mod;
        if (res < 0) {
            res += mod;
        }
        return res;
    }

    private:
    ll n;
    ll mod;
    VL bit;
};
