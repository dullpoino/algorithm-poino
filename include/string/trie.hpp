#pragma once
#include "common.hpp"

struct Trie
{
    Trie()
    {
        newnode();
    }

    void reserve(ll N)

    {
        next.reserve(N);
        cnt.reserve(N);
        ed.reserve(N);
    }

    void insert(const string &str)

    {
        ll idx = 0;
        cnt[idx]++;
        vrep(ch, str) {
            ll c = ch - 'a';
            if (next[idx][c] == NUL) {
                next[idx][c] = newnode();
            }
            idx = next[idx][c];
            cnt[idx]++;
        }
        ed[idx]++;
    }

    // count : strと完全一致する単語数
    ll count(const string &str) const
    {
        ll idx = 0;
        vrep(ch, str) {
            ll u = next[idx][ch - 'a'];
            if (u == NUL) {
                return 0;
            }
            idx = u;
        }
        return ed[idx];
    }

    // prefix : strで始まる単語数
    ll prefix(const string &str) const
    {
        ll idx = 0;
        vrep(ch, str) {
            ll u = next[idx][ch - 'a'];
            if (u == NUL) {
                return 0;
            }
            idx = u;
        }
        return cnt[idx];
    }

    ll erase(const string &str)

    {
        ll num = count(str);
        if (num == 0) {
            return 0;
        }
        ll idx = 0;
        cnt[idx] -= num;
        vrep(ch, str) {
            ll u = next[idx][ch - 'a'];
            idx = u;
            cnt[idx] -= num;
        }
        ed[idx] -= num;
        return num;
    }

    private:
    static constexpr ll NUL = -1ll;
    VEC<array<ll, 26>> next;
    VL cnt;
    VL ed;

    ll newnode()

    {
        next.push_back({});
        next.back().fill(NUL);
        cnt.push_back(0);
        ed.push_back(0);
        return sz(next) - 1ll;
    }
};
