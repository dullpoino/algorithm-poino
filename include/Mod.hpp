#pragma once
#include "common.hpp"

/**********************************************************
MOD
**********************************************************/
class modint
{
    ll value;
    static const ll MOD = MODM;

public:
    modint(ll x = 0ll) {
        value = x % MOD;
    }

    modint& set(ll x) {
        value = x % MOD;
        return *this;
    }

    ll get() const {
        return value;
    }

    modint operator+(const modint& x) const {
        return modint(value + x.value);
    }

    modint operator+(const ll x) const {
        return modint(value + x);
    }

    modint& operator+=(const modint& x) {
        value = (value + x.value) % MOD;
        return *this;
    }

    modint& operator+=(const ll x) {
        value = (value + x) % MOD;
        return *this;
    }

    modint& operator++() {
        value = (value + 1) % MOD;
        return *this;
    }

    modint operator++(int) {
        modint ret = *this;
        value = (value + 1) % MOD;
        return ret;
    }

    modint operator-(const modint& x) const {
        return modint(value + MOD - x.value);
    }

    modint operator-(const ll x) const {
        return modint(value + MOD - x);
    }

    modint& operator-=(const modint& x) {
        value = (value + MOD - x.value) % MOD;
        return *this;
    }

    modint& operator-=(const ll x) {
        value = (value + MOD - x) % MOD;
        return *this;
    }

    modint& operator--() {
        value = (value + MOD - 1) % MOD;
        return *this;
    }

    modint operator--(int) {
        modint ret = *this;
        value = (value + MOD - 1) % MOD;
        return ret;
    }

    modint operator-() const {
        return modint(value ? MOD - value : 0);
    }

    modint operator*(const modint& x) const {
        return modint(value * x.value);
    }

    modint operator*(const ll x) const {
        return modint(value * x);
    }

    modint& operator*=(const modint& x) {
        value = (value * x.value) % MOD;
        return *this;
    }

    modint& operator*=(const ll x) {
        value = (value * x) % MOD;
        return *this;
    }

    modint operator/(const modint& x) const {
        return modint(value * modinv(x.value));
    }

    modint operator/(const ll x) const {
        return modint(value * modinv(x));
    }

    modint& operator/=(const modint& x) {
        value = (value * modinv(x.value)) % MOD;
        return *this;
    }

    modint& operator/=(const ll x) {
        value = (value * modinv(x)) % MOD;
        return *this;
    }

    bool operator==(const modint& x) const {
        return (value == x.value);
    }

    bool operator==(const ll x) const {
        return (value == x);
    }

    bool operator!=(const modint& x) const {
        return (value != x.value);
    }

    bool operator!=(const ll x) const {
        return (value != x);
    }

    explicit operator ll() const {
        return value;
    }

    modint pow(const modint& x) const {
        modint res = 1, base = *this;
        ll y = x.value;
        while (y) {
            if (y & 1) res *= base;
            base *= base;
            y >>= 1;
        }

        return res;
    }

private:
    static ll modinv(ll a) {
        ll b = MOD, u = 1, v = 0;
        while (b) {
            ll t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= MOD;
        if (u < 0) u += MOD;
        return u;
    }

    friend inline modint operator+(ll lhs, const modint& rhs) {
        return modint(lhs + rhs.value);
    }

    friend inline modint operator-(ll lhs, const modint& rhs) {
        return modint(lhs + MOD - rhs.value);
    }

    friend inline modint operator*(ll lhs, const modint& rhs) {
        return modint(lhs * rhs.value);
    }

    friend inline modint operator/(ll lhs, const modint& rhs) {
        return modint(lhs * modinv(rhs.value));
    }

    friend inline bool operator==(ll lhs, const modint& rhs) {
        return lhs == rhs.value;
    }

    friend inline bool operator!=(ll lhs, const modint& rhs) {
        return lhs != rhs.value;
    }

    friend istream& operator>>(istream& is, modint& x) {
        ll tmp;
        is >> tmp;
        x.set(tmp);
        return is;
    }

    friend ostream& operator<<(ostream& os, const modint& x) {
        return os << x.value;
    }
};