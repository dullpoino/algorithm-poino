#pragma once
#include "common.hpp"

struct SUM
{
    public:
    SUM(const VL &v) : N(sz(v)), s(N + 1, 0ll)
    {
        rep(i, 0, N) {
            s[i + 1] = s[i] + v[i];
        }
    }

    ll get(ll p) const
    {
        if (p < 0 || N - 1 < p) {
            return 0;
        }

        return s[p + 1];
    }

    ll get(ll l, ll r) const
    {
        if (l > r) {
            swap(l, r);
        }

        if (r < 0 || N - 1 < l) {
            return 0;
        }

        chmax(l, 0ll);
        chmin(r, N - 1);

        return s[r + 1] - s[l];
    }

    private:
    ll N;
    VL s;
};
