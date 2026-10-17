#pragma once
#include "common.hpp"

template<class T, class Merge>
class SEGTREE
{
    public:
    VEC<T> segtree;

    ll SEGSZ = 1;

    T E;
    Merge merge;

    SEGTREE(T e, Merge f) : E(e), merge(f)
    {
    }

    void init(ll n)
    {
        SEGSZ = 1;
        while (SEGSZ < n) {
            SEGSZ <<= 1;
        }

        segtree.assign(2 * SEGSZ, E);
    }

    void init(VEC<T> &v)
    {
        init(sz(v));

        rep(i, 0, sz(v)) {
            segtree[SEGSZ + i] = v[i];
        }

        rrep(i, 1, SEGSZ) {
            segtree[i] = merge(segtree[i * 2], segtree[i * 2 + 1]);
        }
    }

    void update(ll pos, T value)
    {
        pos += SEGSZ - 1;
        segtree[pos] = value;

        while (pos >= 2) {
            pos /= 2;
            segtree[pos] = merge(segtree[pos * 2], segtree[pos * 2 + 1]);
        }
    }

    T query(ll left, ll right, ll lts, ll rts, ll cur)
    {
        if (right <= lts || rts <= left) {
            return E;
        }

        if (left <= lts && rts <= right) {
            return segtree[cur];
        }

        ll mid = midpoint(lts, rts);
        T res_Left = query(left, right, lts, mid, cur * 2);
        T res_Right = query(left, right, mid, rts, cur * 2 + 1);

        return merge(res_Left, res_Right);
    }

    T query(ll left, ll right)
    {
        return query(left, right + 1, 1, SEGSZ + 1, 1);
    }
};
