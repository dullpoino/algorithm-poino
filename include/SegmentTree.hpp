#pragma once
#include "common.hpp"

// n は 1e6 以下を想定
const ll SEGSZMAX = 1ll << 21;

/**********************************************************
最小値セグメント木
**********************************************************/

class SEGMIN {
public:
    // 1-idx
    // segtree[1] : all
    VL segtree;

    ll SEGSZ = 1;
    ll SEGINF = INF;

    void init(ll n)
    {
        SEGSZ = 1;
        while (SEGSZ < n) {
            SEGSZ <<= 1;
        }

        segtree.assign(2 * SEGSZ, SEGINF);
    }

    // pos : 1-idx
    void update(ll pos, ll nvalue)
    {
        pos += SEGSZ - 1;
        segtree[pos] = nvalue;

        while (pos >= 2) {
            pos /= 2;
            segtree[pos] = min(segtree[pos * 2], segtree[pos * 2 + 1]);
        }
    }

    ll query(ll left, ll right, ll lts, ll rts, ll cur)
    {
        if (right <= lts || rts <= left) {
            return SEGINF;
        }

        if (left <= lts && rts <= right) {
            return segtree[cur];
        }

        ll mid = (lts + rts) / 2;

        ll res_Left = query(left, right, lts, mid, cur * 2);
        ll res_Right = query(left, right, mid, rts, cur * 2 + 1);

        return min(res_Left, res_Right);
    }

    // [left, right]
    // left : 1-idx
    // right : 1-idx
    ll query(ll left, ll right)
    {
        return query(left, right + 1, 1, SEGSZ + 1, 1);
    }
};

/**********************************************************
最大値セグメント木
**********************************************************/

class SEGMAX {
public:
    // 1-idx
    // segtree[1] : all
    VL segtree;

    ll SEGSZ = 1;
    ll SEGINF = -INF;

    void init(ll n)
    {
        SEGSZ = 1;
        while (SEGSZ < n) {
            SEGSZ <<= 1;
        }

        segtree.assign(2 * SEGSZ, SEGINF);
    }

    // pos : 1-idx
    void update(ll pos, ll nvalue)
    {
        pos += SEGSZ - 1;
        segtree[pos] = nvalue;

        while (pos >= 2) {
            pos /= 2;
            segtree[pos] = max(segtree[pos * 2], segtree[pos * 2 + 1]);
        }
    }

    ll query(ll left, ll right, ll lts, ll rts, ll cur)
    {
        if (right <= lts || rts <= left) {
            return SEGINF;
        }

        if (left <= lts && rts <= right) {
            return segtree[cur];
        }

        ll mid = (lts + rts) / 2;

        ll res_Left = query(left, right, lts, mid, cur * 2);
        ll res_Right = query(left, right, mid, rts, cur * 2 + 1);

        return max(res_Left, res_Right);
    }

    // [left, right]
    // left : 1-idx
    // right : 1-idx
    ll query(ll left, ll right)
    {
        return query(left, right + 1, 1, SEGSZ + 1, 1);
    }
};

/**********************************************************
総和セグメント木
**********************************************************/

class SEGSUM {
public:
    // 1-idx
    // segtree[1] : all
    VL segtree;

    ll SEGSZ = 1;
    ll SEGINF = 0;

    void init(ll n)
    {
        SEGSZ = 1;
        while (SEGSZ < n) {
            SEGSZ <<= 1;
        }

        segtree.assign(2 * SEGSZ, SEGINF);
    }

    // pos : 1-idx
    void update(ll pos, ll nvalue)
    {
        pos += SEGSZ - 1;
        segtree[pos] = nvalue;

        while (pos >= 2) {
            pos /= 2;
            segtree[pos] = segtree[pos * 2] + segtree[pos * 2 + 1];
        }
    }

    ll query(ll left, ll right, ll lts, ll rts, ll cur)
    {
        if (right <= lts || rts <= left) {
            return SEGINF;
        }

        if (left <= lts && rts <= right) {
            return segtree[cur];
        }

        ll mid = (lts + rts) / 2;

        ll res_Left = query(left, right, lts, mid, cur * 2);
        ll res_Right = query(left, right, mid, rts, cur * 2 + 1);

        return res_Left + res_Right;
    }

    // [left, right]
    // left : 1-idx
    // right : 1-idx
    ll query(ll left, ll right)
    {
        return query(left, right + 1, 1, SEGSZ + 1, 1);
    }
};

/**********************************************************
最小値遅延セグメント木
**********************************************************/

class LAZYSEGMIN {
public:
    // 1-idx
    // segtree[1] : all
    VL segtree;
    VL lazyvalue;
    VEC<bool> lazyflag;

    ll SEGSZ = 1;
    ll SEGINF = INF;

    void init(ll n)
    {
        SEGSZ = 1;
        while (SEGSZ < n) {
            SEGSZ <<= 1;
        }

        segtree.assign(2 * SEGSZ, SEGINF);
        lazyvalue.assign(2 * SEGSZ, 0);
        lazyflag.assign(2 * SEGSZ, false);
    }

    void lazy_update(ll cur)
    {
        if (lazyflag[cur] == false) return;

        segtree[cur] = lazyvalue[cur];

        if (cur < SEGSZ) {
            lazyflag[cur * 2] = true;
            lazyflag[cur * 2 + 1] = true;
            lazyvalue[cur * 2] = lazyvalue[cur];
            lazyvalue[cur * 2 + 1] = lazyvalue[cur];
        }

        lazyflag[cur] = false;
    }

    void range_update(ll left, ll right, ll lts, ll rts, ll cur, ll nvalue)
    {
        lazy_update(cur);

        if (right <= lts || rts <= left) {
            return;
        }

        if (left <= lts && rts <= right) {
            lazyflag[cur] = true;
            lazyvalue[cur] = nvalue;
            segtree[cur] = nvalue;
            return;
        }

        ll mid = (lts + rts) / 2;

        range_update(left, right, lts, mid, cur * 2, nvalue);
        range_update(left, right, mid, rts, cur * 2 + 1, nvalue);

        segtree[cur] = min(segtree[cur * 2], segtree[cur * 2 + 1]);
    }

    // [left, right]
    // left : 1-idx
    // right : 1-idx
    void range_update(ll left, ll right, ll nvalue)
    {
        range_update(left, right + 1, 1, SEGSZ + 1, 1, nvalue);
    }

    ll query(ll left, ll right, ll lts, ll rts, ll cur)
    {
        if (right <= lts || rts <= left) {
            return SEGINF;
        }

        lazy_update(cur);

        if (left <= lts && rts <= right) {
            return segtree[cur];
        }

        ll mid = (lts + rts) / 2;

        ll res_Left = query(left, right, lts, mid, cur * 2);
        ll res_Right = query(left, right, mid, rts, cur * 2 + 1);

        return min(res_Left, res_Right);
    }

    // [left, right]
    // left : 1-idx
    // right : 1-idx
    ll query(ll left, ll right)
    {
        return query(left, right + 1, 1, SEGSZ + 1, 1);
    }
};

/**********************************************************
最大値遅延セグメント木
**********************************************************/

class LAZYSEGMAX {
public:
    // 1-idx
    // segtree[1] : all
    VL segtree;
    VL lazyvalue;
    VEC<bool> lazyflag;

    ll SEGSZ = 1;
    ll SEGINF = -INF;

    void init(ll n)
    {
        SEGSZ = 1;
        while (SEGSZ < n) {
            SEGSZ <<= 1;
        }

        segtree.assign(2 * SEGSZ, SEGINF);
        lazyvalue.assign(2 * SEGSZ, 0);
        lazyflag.assign(2 * SEGSZ, false);
    }

    void lazy_update(ll cur)
    {
        if (lazyflag[cur] == false) return;

        segtree[cur] = lazyvalue[cur];

        if (cur < SEGSZ) {
            lazyflag[cur * 2] = true;
            lazyflag[cur * 2 + 1] = true;
            lazyvalue[cur * 2] = lazyvalue[cur];
            lazyvalue[cur * 2 + 1] = lazyvalue[cur];
        }

        lazyflag[cur] = false;
    }

    void range_update(ll left, ll right, ll lts, ll rts, ll cur, ll nvalue)
    {
        lazy_update(cur);

        if (right <= lts || rts <= left) {
            return;
        }

        if (left <= lts && rts <= right) {
            lazyflag[cur] = true;
            lazyvalue[cur] = nvalue;
            segtree[cur] = nvalue;
            return;
        }

        ll mid = (lts + rts) / 2;

        range_update(left, right, lts, mid, cur * 2, nvalue);
        range_update(left, right, mid, rts, cur * 2 + 1, nvalue);

        segtree[cur] = max(segtree[cur * 2], segtree[cur * 2 + 1]);
    }

    // [left, right]
    // left : 1-idx
    // right : 1-idx
    void range_update(ll left, ll right, ll nvalue)
    {
        range_update(left, right + 1, 1, SEGSZ + 1, 1, nvalue);
    }

    ll query(ll left, ll right, ll lts, ll rts, ll cur)
    {
        if (right <= lts || rts <= left) {
            return SEGINF;
        }

        lazy_update(cur);

        if (left <= lts && rts <= right) {
            return segtree[cur];
        }

        ll mid = (lts + rts) / 2;

        ll res_Left = query(left, right, lts, mid, cur * 2);
        ll res_Right = query(left, right, mid, rts, cur * 2 + 1);

        return max(res_Left, res_Right);
    }

    // [left, right]
    // left : 1-idx
    // right : 1-idx
    ll query(ll left, ll right)
    {
        return query(left, right + 1, 1, SEGSZ + 1, 1);
    }
};

/**********************************************************
総和遅延セグメント木
**********************************************************/

class LAZYSEGSUM {
public:
    // 1-idx
    // segtree[1] : all
    VL segtree;
    VL lazyvalue;
    VEC<bool> lazyflag;

    ll SEGSZ = 1;
    ll SEGINF = 0;

    void init(ll n)
    {
        SEGSZ = 1;
        while (SEGSZ < n) {
            SEGSZ <<= 1;
        }

        segtree.assign(2 * SEGSZ, SEGINF);
        lazyvalue.assign(2 * SEGSZ, 0);
        lazyflag.assign(2 * SEGSZ, false);
    }

    void lazy_update(ll cur, ll lts, ll rts)
    {
        if (lazyflag[cur] == false) return;

        segtree[cur] = lazyvalue[cur] * (rts - lts);

        if (cur < SEGSZ) {
            lazyflag[cur * 2] = true;
            lazyflag[cur * 2 + 1] = true;
            lazyvalue[cur * 2] = lazyvalue[cur];
            lazyvalue[cur * 2 + 1] = lazyvalue[cur];
        }

        lazyflag[cur] = false;
    }

    void range_update(ll left, ll right, ll lts, ll rts, ll cur, ll nvalue)
    {
        lazy_update(cur, lts, rts);

        if (right <= lts || rts <= left) {
            return;
        }

        if (left <= lts && rts <= right) {
            lazyflag[cur] = true;
            lazyvalue[cur] = nvalue;
            segtree[cur] = nvalue * (rts - lts);
            return;
        }

        ll mid = (lts + rts) / 2;

        range_update(left, right, lts, mid, cur * 2, nvalue);
        range_update(left, right, mid, rts, cur * 2 + 1, nvalue);

        segtree[cur] = segtree[cur * 2] + segtree[cur * 2 + 1];
    }

    // [left, right]
    // left : 1-idx
    // right : 1-idx
    void range_update(ll left, ll right, ll nvalue)
    {
        range_update(left, right + 1, 1, SEGSZ + 1, 1, nvalue);
    }

    ll query(ll left, ll right, ll lts, ll rts, ll cur)
    {
        if (right <= lts || rts <= left) {
            return SEGINF;
        }

        lazy_update(cur, lts, rts);

        if (left <= lts && rts <= right) {
            return segtree[cur];
        }

        ll mid = (lts + rts) / 2;

        ll res_Left = query(left, right, lts, mid, cur * 2);
        ll res_Right = query(left, right, mid, rts, cur * 2 + 1);

        return res_Left + res_Right;
    }

    // [left, right]
    // left : 1-idx
    // right : 1-idx
    ll query(ll left, ll right)
    {
        return query(left, right + 1, 1, SEGSZ + 1, 1);
    }
};