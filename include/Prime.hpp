#pragma once
#include "common.hpp"

/**********************************************************
素数の試し割り法
**********************************************************/
inline bool trial_division(ll n)
{
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

/**********************************************************
エラトステネスの篩
**********************************************************/
inline VEC<bool> sieve_eratosthenes(ll n)
{
    VEC<bool> prime(n + 1, true);

    if (n >= 0) prime[0] = false;
    if (n >= 1) prime[1] = false;

    repr(i, 2, n) {
        if (!prime[i]) continue;
        repdr(j, i * i, n, i) {
            prime[j] = false;
        }
    }

    return prime;
}

/**********************************************************
区間篩
[l, r] をエラトステネスの篩で求める。
**********************************************************/
inline VEC<bool> segmented_sieve(ll l, ll r)
{
    ll sq = (ll)sqrtl((ld)r);
    while ((sq + 1) * (sq + 1) <= r) ++sq;
    while (sq * sq > r) --sq;

    VEC<bool> small_prime = sieve_eratosthenes(sq);
    VEC<bool> prime(r - l + 1, true);

    if (l == 0 || l == 1) prime[0] = false;
    if (l == 0 && r >= 1) prime[1] = false;

    rep(i, 2, sz(small_prime)) {
        if (small_prime[i]) {
            ll start = max(i * i, ((l + i - 1) / i) * i);

            repdr(j, start, r, i) {
                prime[j - l] = false;
            }
        }
    }

    return prime;
}