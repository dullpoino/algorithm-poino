#pragma once
#include "common.hpp"

class modint
{
    ll value;
    static const ll MOD = MODM;

    public:
    modint(ll x = 0ll)
    {
        value = x % MOD;
        if (value < 0) {
            value += MOD;
        }
    }

    modint &set(ll x)
    {
        value = x % MOD;

        if (value < 0) {
            value += MOD;
        }

        return *this;
    }

    ll get() const
    {
        return value;
    }

    modint operator+(const modint &x) const
    {
        return modint(*this) += x;
    }

    modint operator+(const ll x) const
    {
        return modint(*this) += x;
    }

    modint &operator+=(const modint &x)
    {
        value = (value + x.value) % MOD;
        return *this;
    }

    modint &operator+=(const ll x)
    {
        return *this += modint(x);
    }

    modint &operator++()
    {
        return *this += 1;
    }

    modint operator++(int)
    {
        modint ret = *this;
        ++(*this);
        return ret;
    }

    modint operator-(const modint &x) const
    {
        return modint(*this) -= x;
    }

    modint operator-(const ll x) const
    {
        return modint(*this) -= x;
    }

    modint &operator-=(const modint &x)
    {
        value = (value + MOD - x.value) % MOD;
        return *this;
    }

    modint &operator-=(const ll x)
    {
        return *this -= modint(x);
    }

    modint &operator--()
    {
        return *this -= 1;
    }

    modint operator--(int)
    {
        modint ret = *this;
        --(*this);
        return ret;
    }

    modint operator-() const
    {
        return modint(static_cast<bool>(value) == true ? MOD - value : 0);
    }

    modint operator*(const modint &x) const
    {
        return modint(*this) *= x;
    }

    modint operator*(const ll x) const
    {
        return modint(*this) *= x;
    }

    modint &operator*=(const modint &x)
    {
        value = (value * x.value) % MOD;
        return *this;
    }

    modint &operator*=(const ll x)
    {
        return *this *= modint(x);
    }

    modint operator/(const modint &x) const
    {
        return modint(*this) /= x;
    }

    modint operator/(const ll x) const
    {
        return modint(*this) /= x;
    }

    modint &operator/=(const modint &x)
    {
        value = (value * modinv(x.value)) % MOD;
        return *this;
    }

    modint &operator/=(const ll x)
    {
        value = (value * modinv(x)) % MOD;
        return *this;
    }

    bool operator==(const modint &x) const
    {
        return (value == x.value);
    }

    bool operator==(const ll x) const
    {
        return (value == modint(x).value);
    }

    bool operator!=(const modint &x) const
    {
        return (value != x.value);
    }

    bool operator!=(const ll x) const
    {
        return (value != modint(x).value);
    }

    explicit operator ll() const
    {
        return value;
    }

    modint pow(ll x) const
    {
        modint res = 1, base = *this;
        while (static_cast<bool>(x) == true) {
            if ((x & 1) == true) {
                res *= base;
            }
            base *= base;
            x >>= 1;
        }

        return res;
    }

    private:
    static ll modinv(ll a)
    {
        ll b = MOD, u = 1, v = 0;
        while (static_cast<bool>(b) == true) {
            ll t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= MOD;
        if (u < 0) {
            u += MOD;
        }
        return u;
    }

    friend modint operator+(ll lhs, const modint &rhs)
    {
        return modint(lhs + rhs.value);
    }

    friend modint operator-(ll lhs, const modint &rhs)
    {
        return modint(lhs + MOD - rhs.value);
    }

    friend modint operator*(ll lhs, const modint &rhs)
    {
        return modint(lhs * rhs.value);
    }

    friend modint operator/(ll lhs, const modint &rhs)
    {
        return modint(lhs * modinv(rhs.value));
    }

    friend bool operator==(ll lhs, const modint &rhs)
    {
        return modint(lhs).value == rhs.value;
    }

    friend bool operator!=(ll lhs, const modint &rhs)
    {
        return modint(lhs).value != rhs.value;
    }

    friend istream &operator>>(istream &is, modint &x)
    {
        ll tmp;
        is >> tmp;
        x.set(tmp);
        return is;
    }

    friend ostream &operator<<(ostream &os, const modint &x)
    {
        return os << x.value;
    }
};
