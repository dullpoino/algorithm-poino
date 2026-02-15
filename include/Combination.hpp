#pragma once
#include "common.hpp"

/**********************************************************
組み合わせ
**********************************************************/

class COMBINATION
{
    private:
    ll s;
    VVL comb;

    public:
    COMBINATION(ll COMB_MAX, ll mod = MODM) : s(COMB_MAX), comb(s + 1, VL(s + 1, 0))
    {
        repr(i, 0, s) comb[i][0] = 1;
        repr(i, 1, s) {
            repr(j, 1, s) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
            }
        }
    }

    ll getComb(ll m, ll n) {
        if (m < n || m < 0 || s < m || n < 0 || s < n) {
            return 0;
        }
        else {
            return comb[m][n];
        }
    }
};