#pragma once
#include "common.hpp"

class PRIME
{
    public:
    PRIME(ll n) : mx(n), prime(VEC<bool>(mx + 1, true))
    {
        if (mx >= 0) {
            prime[0] = false;
        }
        if (mx >= 1) {
            prime[1] = false;
        }

        repr(i, 2, mx) {
            if (i > mx / i) {
                break;
            }

            if (prime[i] == false) {
                continue;
            }

            repdr(j, i * i, mx, i) {
                prime[j] = false;
            }
        }
    }

    bool isPrime(ll x) const

    {
        if (x < 0 || mx < x) {
            return false;
        }

        return prime[x];
    }

    private:
    ll mx;
    VEC<bool> prime;
};
