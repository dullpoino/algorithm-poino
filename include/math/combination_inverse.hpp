#pragma once
#include "common.hpp"

class COMB_INV
{
    public:
    COMB_INV(ll N, ll M = MODM) : s(N), m(M), fact(s + 1, 1), finv(s + 1, 1)

    {
        repr(i, 1, s) {
            fact[i] = fact[i - 1] * i % m;
        }

        finv[s] = modpow(fact[N], m - 2);

        rrepr(i, 1, s) {
            finv[i - 1] = finv[i] * i % m;
        }
    }

    ll C(ll n, ll r)
    {
        if (n < 0 || r < 0 || n < r || s < n) {
            return 0;
        }

        return fact[n] * finv[r] % m * finv[n - r] % m;
    }

    private:
    ll s;
    ll m;
    VL fact;
    VL finv;

    ll modpow(ll a, ll b)
    {
        ll res = 1;
        while (b > 0) {
            if ((b & 1) == true) {
                res = res * a % m;
            }

            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

};
