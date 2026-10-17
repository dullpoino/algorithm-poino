#pragma once
#include "common.hpp"

template<class T, class F, class Merge, class Mapping, class Composition>
class LAZYSEGTREE
{
    public:
    LAZYSEGTREE(T e, F id, Merge m, Mapping map, Composition comp)
        : E(e), ID(id), merge(m), mapping(map), composition(comp)
        {
    }

    void init(ll n, T value = T{})
    {
        SEGSZ = 1;
        while (SEGSZ < n) {
            SEGSZ <<= 1;
        }

        segtree.assign(2 * SEGSZ, E);
        lazy.assign(2 * SEGSZ, ID);
        pending.assign(2 * SEGSZ, false);

        rep(i, 0, n) {
            segtree[SEGSZ + i] = value;
        }

        rrep(i, 1, SEGSZ) {
            segtree[i] = merge(segtree[i * 2], segtree[i * 2 + 1]);
        }
    }

    void init(const VEC<T> &v)
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
        update(pos, value, 1, SEGSZ + 1, 1);
    }

    void range_update(ll left, ll right, F f)
    {
        range_update(left, right + 1, f, 1, SEGSZ + 1, 1);
    }

    T query(ll left, ll right)
    {
        return query(left, right + 1, 1, SEGSZ + 1, 1);
    }

    private:
    VEC<T> segtree;
    VEC<F> lazy;
    VEC<char> pending;
    ll SEGSZ = 1;
    T E;
    F ID;
    Merge merge;
    Mapping mapping;
    Composition composition;

    void apply(ll cur, F f, ll len)
    {
        segtree[cur] = mapping(segtree[cur], f, len);

        if (pending[cur] == true) {
            lazy[cur] = composition(f, lazy[cur]);
        }
        else {
            lazy[cur] = f;
            pending[cur] = true;
        }
    }

    void lazy_update(ll cur, ll lts, ll rts)
    {
        if (rts - lts == 1 || pending[cur] == false) {
            return;
        }

        ll len = (rts - lts) / 2;

        apply(cur * 2, lazy[cur], len);
        apply(cur * 2 + 1, lazy[cur], len);

        lazy[cur] = ID;
        pending[cur] = false;
    }

    void update(ll pos, T value, ll lts, ll rts, ll cur)
    {
        if (rts - lts == 1) {
            segtree[cur] = value;
            lazy[cur] = ID;
            pending[cur] = false;
            return;
        }

        lazy_update(cur, lts, rts);

        ll mid = midpoint(lts, rts);
        if (pos < mid) {
            update(pos, value, lts, mid, cur * 2);
        }
        else {
            update(pos, value, mid, rts, cur * 2 + 1);
        }

        segtree[cur] = merge(segtree[cur * 2], segtree[cur * 2 + 1]);
    }

    void range_update(ll left, ll right, F f,
                      ll lts, ll rts, ll cur)
    {
        if (right <= lts || rts <= left) {
            return;
        }

        if (left <= lts && rts <= right) {
            apply(cur, f, rts - lts);
            return;
        }

        lazy_update(cur, lts, rts);

        ll mid = midpoint(lts, rts);
        range_update(left, right, f, lts, mid, cur * 2);
        range_update(left, right, f, mid, rts, cur * 2 + 1);

        segtree[cur] = merge(segtree[cur * 2], segtree[cur * 2 + 1]);
    }

    T query(ll left, ll right, ll lts, ll rts, ll cur)
    {
        if (right <= lts || rts <= left) {
            return E;
        }

        if (left <= lts && rts <= right) {
            return segtree[cur];
        }

        lazy_update(cur, lts, rts);

        ll mid = midpoint(lts, rts);
        T res_Left = query(left, right, lts, mid, cur * 2);
        T res_Right = query(left, right, mid, rts, cur * 2 + 1);

        return merge(res_Left, res_Right);
    }
};
