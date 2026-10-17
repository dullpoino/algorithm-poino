#pragma once
#include "common.hpp"

struct SUM2
{
    public:
    SUM2(const VVL &v) : H(sz(v)), W(sz(v[0])), s(H + 1, VL(W + 1, 0ll))
    {
        rep(h, 0, H) rep(w, 0, W) {
            s[h + 1][w + 1] = v[h][w]
                + s[h][w + 1]
                + s[h + 1][w]
                - s[h][w];
        }
    }

    ll get(ll h, ll w) const
    {
        if (h < 0 || H <= h || w < 0 || W <= w) {
            return 0;
        }

        return s[h + 1][w + 1];
    }

    ll get(ll h1, ll w1, ll h2, ll w2) const
    {
        if (h1 > h2) {
            swap(h1, h2);
        }
        if (w1 > w2) {
            swap(w1, w2);
        }

        if (h2 < 0 || H <= h1 || w2 < 0 || W <= w1) {
            return 0;
        }

        chmax(h1, 0ll);
        chmax(w1, 0ll);
        chmin(h2, H - 1);
        chmin(w2, W - 1);

        return s[h2 + 1][w2 + 1]
            - s[h1][w2 + 1]
            - s[h2 + 1][w1]
            + s[h1][w1];
    }

    private:
    ll H, W;
    VVL s;
};
