#pragma once
#include "common.hpp"

struct SUM3
{
    public:
    SUM3(const VVVL &v) : X(sz(v)), Y(sz(v[0])), Z(sz(v[0][0])),
        s(X + 1, VVL(Y + 1, VL(Z + 1, 0ll)))
    {
        rep(x, 0, X) rep(y, 0, Y) rep(z, 0, Z) {
            s[x + 1][y + 1][z + 1] = v[x][y][z]
                + s[x][y + 1][z + 1]
                + s[x + 1][y][z + 1]
                + s[x + 1][y + 1][z]
                - s[x][y][z + 1]
                - s[x][y + 1][z]
                - s[x + 1][y][z]
                + s[x][y][z];
        }
    }

    ll get(ll x, ll y, ll z) const
    {
        if (x < 0 || X <= x || y < 0 || Y <= y || z < 0 || Z <= z) {
            return 0;
        }

        return s[x + 1][y + 1][z + 1];
    }

    ll get(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) const
    {
        if (x1 > x2) {
            swap(x1, x2);
        }
        if (y1 > y2) {
            swap(y1, y2);
        }
        if (z1 > z2) {
            swap(z1, z2);
        }
        if (x2 < 0 || X <= x1 || y2 < 0 || Y <= y1 || z2 < 0 || Z <= z1) {
            return 0;
        }

        chmax(x1, 0ll);
        chmax(y1, 0ll);
        chmax(z1, 0ll);
        chmin(x2, X - 1);
        chmin(y2, Y - 1);
        chmin(z2, Z - 1);

        return s[x2 + 1][y2 + 1][z2 + 1]
            - s[x1][y2 + 1][z2 + 1]
            - s[x2 + 1][y1][z2 + 1]
            - s[x2 + 1][y2 + 1][z1]
            + s[x1][y1][z2 + 1]
            + s[x1][y2 + 1][z1]
            + s[x2 + 1][y1][z1]
            - s[x1][y1][z1];
    }

    private:
    ll X, Y, Z;
    VVVL s;
};
