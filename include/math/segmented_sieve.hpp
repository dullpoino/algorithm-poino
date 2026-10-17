#pragma once
#include "common.hpp"
#include "integer_sqrt.hpp"
#include "sieve_eratosthenes.hpp"

class SEGSIEVE
{
    public:
    SEGSIEVE(ll l, ll r) : l(l), r(r), n(isqrt(r)), prime(r - l + 1, true)
    {
        PRIME small_prime(n + 1);

        if (l == 0) {
            prime[0] = false;
        }
        if (l <= 1 && r >= 1) {
            prime[1 - l] = false;
        }

        repr(i, 2, n) {
            if (small_prime.isPrime(i) == true) {
                ll start = max(i * i, ((l + i - 1) / i) * i);
                repdr(j, start, r, i) {
                    prime[j - l] = false;
                }
            }
        }
    }

    bool isPrime(ll x) const

    {
        if (x < l || r < x) {
            return false;
        }

        return prime[x - l];
    }

    private:
    ll n;
    ll l;
    ll r;
    VEC<bool> prime;
};
