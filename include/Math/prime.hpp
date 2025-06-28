#pragma once

#include "../common.hpp"

namespace Math {

    class PRIME
    {
    private:
        ll n;
        ll sq = 0;
        vector<bool> prime;
        vector<ll> primes;

    public:
        PRIME(ll PRIME_SIZE, ll type) : n(PRIME_SIZE), prime(n + 1, false)
        {
            // エラトステネスの篩
            if (type == 1) {
                if (n >= 2) {
                    prime[2] = true;
                    primes.push_back(2);
                }

                repdr(i, 3, n, 2) prime[i] = true;
                repdr(i, 3, n, 2) {
                    if (prime[i]) {
                        repdr(j, i * i, n, i) prime[j] = false;
                        primes.push_back(i);
                    }
                }
            }

            // アトキンの篩
            if (type == 2) {
                sq = (ll)sqrt(n);

                repr(i, 1, sq) {
                    repr(j, 1, sq) {
                        ll m = 4 * i * i + j * j;
                        if (m > n) break;
                        if (m % 12 == 1 || m % 12 == 5) {
                            prime[m] = !prime[m];
                        }
                    }

                    repr(j, 1, sq) {
                        ll m = 3 * i * i + j * j;
                        if (m > n) break;
                        if (m % 12 == 7) {
                            prime[m] = !prime[m];
                        }
                    }

                    rrepr(j, 1, i) {
                        ll m = 3 * i * i - j * j;
                        if (m > n) break;
                        if (m % 12 == 11) {
                            prime[m] = !prime[m];
                        }
                    }
                }

                repr(i, 5, sq) {
                    if (prime[i]) {
                        repdr(j, i * i, n, i * i) {
                            prime[j] = false;
                        }
                    }
                }

                if (n >= 2) {
                    prime[2] = true;
                    primes.push_back(2);
                }
                if (n >= 3) {
                    prime[3] = true;
                    primes.push_back(3);
                }
                repdr(i, 5, n, 2) {
                    if (prime[i]) {
                        primes.push_back(i);
                    }
                }
            }
        }

        bool isPrime(ll x)
        {
            if (0 <= x && x <= n) return prime[x];
            else return false;
        }

        vector<ll>& getPrime() {
            return primes;
        }
    };

}