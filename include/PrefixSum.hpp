#pragma once
#include "common.hpp"

/**********************************************************
1次元累積和
x1, x2 : 1-index
**********************************************************/

VL psum(VL& v)
{
    ll n = sz(v);
    VL s(n + 1, 0ll);
    rep(i, 0, n) {
        s[i + 1] = s[i] + v[i];
    }
    return s;
}
ll getPsum(VL& v, ll x1, ll x2)
{
    return v[x2] - v[x1 - 1];
}

/**********************************************************
2次元累積和
x1, y1, x2, y2 : 1-index
**********************************************************/

VVL psum2(VVL& v)
{
    ll n1 = sz(v);
    ll n2 = sz(v[0]);
    VVL s = VVL(n1 + 1, VL(n2 + 1, 0ll));
    rep(i, 0, n1) rep(j, 0, n2) {
        s[i + 1][j + 1] = s[i + 1][j]
            + s[i][j + 1]
            - s[i][j]
            + v[i][j];
    }
    return s;
}
ll getPsum2(VVL& v, ll x1, ll y1, ll x2, ll y2)
{
    return v[x2][y2]
        - v[x1 - 1][y2]
        - v[x2][y1 - 1]
        + v[x1 - 1][y1 - 1];
}

/**********************************************************
3次元累積和
x1, y1, z1, x2, y2, z2 : 1-index
**********************************************************/

VVVL psum3(VVVL& v)
{
    ll n1 = sz(v);
    ll n2 = sz(v[0]);
    ll n3 = sz(v[0][0]);
    VVVL s = VVVL(n1 + 1, VVL(n2 + 1, VL(n3 + 1, 0ll)));
    rep(i, 0, n1) rep(j, 0, n2) rep(k, 0, n3) {
        s[i + 1][j + 1][k + 1] = s[i + 1][j + 1][k]
            + s[i + 1][j][k + 1]
            + s[i][j + 1][k + 1]
            - s[i + 1][j][k]
            - s[i][j + 1][k]
            - s[i][j][k + 1]
            + s[i][j][k]
            + v[i][j][k];
    }
    return s;
}
ll getPsum3(VVVL& v, ll x1, ll y1, ll z1, ll x2, ll y2, ll z2)
{
    return  v[x2][y2][z2]
        - v[x1 - 1][y2][z2]
        - v[x2][y1 - 1][z2]
        - v[x2][y2][z1 - 1]
        + v[x1 - 1][y1 - 1][z2]
        + v[x1 - 1][y2][z1 - 1]
        + v[x2][y1 - 1][z1 - 1]
        - v[x1 - 1][y1 - 1][z1 - 1];
}