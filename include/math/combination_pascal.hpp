#pragma once
#include "common.hpp"

class COMB_PASCAL
{
    public:
    COMB_PASCAL(ll N, ll M = MODM) : s(N), c(s + 1, VL(s + 1, 0))

    {
        repr(i, 0, s) {
            c[i][0] = c[i][i] = 1 % M;

            rep(j, 1, i) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % M;
            }
        }
    }

    ll C(ll n, ll r)

    {
        if (n < r || n < 0 || s < n || r < 0) {
            return 0;
        }

        return c[n][r];
    }

    private:
    ll s;
    VVL c;
};
