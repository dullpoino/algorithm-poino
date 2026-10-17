// Source: https://github.com/dullpoino/algorithm-poino
// 本コードには、上記リポジトリで事前公開したコードを
// 問題に合わせて改変・組み合わせて使用した部分が含まれる場合があります。
#pragma once

#include <bits/stdc++.h>
using namespace std;

#ifdef _MSC_VER
#pragma warning(error:4456)
#pragma warning(error:4457)
#pragma warning(disable:5264)
#pragma warning(disable:4365)
#endif

////////////////////////////////////////////////////////////////
///// 型定義

typedef long long ll;
typedef long double ld;

////////////////////////////////////////////////////////////////
///// その他

#define LF cout << "\n"

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define sz(x) (ll)(x).size()
#define fst(x) (x).first
#define snd(x) (x).second

void YESNO(bool cond)
{
    cout << (cond == true ? "YES" : "NO") << "\n";
}
void yesno(bool cond)
{
    cout << (cond == true ? "yes" : "no") << "\n";
}
void YesNo(bool cond)
{
    cout << (cond == true ? "Yes" : "No") << "\n";
}

template<class T> bool chmax(T &a, const T &b)
{
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> bool chmin(T &a, const T &b)
{
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> using pqasc = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pqdesc = priority_queue<T>;

template<class T> T popb(deque<T> &q)
{
    T x = move(q.back()); q.pop_back(); return x;
}
template<class T> T popf(deque<T> &q)
{
    T x = move(q.front()); q.pop_front(); return x;
}
template<class T, class COMP> T poppq(priority_queue<T, vector<T>, COMP> &q)
{
    T x = q.top(); q.pop(); return x;
}

const ll MODP = 1000000007;
const ll MODM = 998244353;
const ll INF = (1ll << 62);
const ld PI = 3.141592653589793238462643383279502884L;

// RDLU(ESWN)
const ll dh[4] = { 0, 1, 0, -1 };
const ll dw[4] = { 1, 0, -1, 0 };
const ll dh8[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const ll dw8[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

////////////////////////////////////////////////////////////////
///// ループ

#define rep(i,l,r) for (ll i=(l); i<(r); ++i)
#define repd(i,l,r,d) for (ll i=(l); i<(r); i+=(d))
#define rrep(i,l,r) for (ll i=(r)-1; i>=(l); --i)
#define rrepd(i,l,r,d) for (ll i=(r)-1; i>=(l); i-=(d))
#define repr(i,l,r) for (ll i=(l); i<=(r); ++i)
#define repdr(i,l,r,d) for (ll i=(l); i<=(r); i+=(d))
#define rrepr(i,l,r) for (ll i=(r); i>=(l); --i)
#define rrepdr(i,l,r,d) for (ll i=(r); i>=(l); i-=(d))
#define vrep(x,v) for(auto&& x:(v))

////////////////////////////////////////////////////////////////
///// 入力関数

template <class... T> void in(T &...x)
{
    ((cin >> x), ...);
}
template <class... T> void ind(T &...x)
{
    ((cin >> x, --x), ...);
}

////////////////////////////////////////////////////////////////
///// 出力関数

template <class... T> void out(const T &...x)
{
    ((cout << x << ' '), ...);
}
template <class... T> void outT(const T &...x)
{
    ((cout << x), ...);
}
template <class... T> void outL(const T &...x)
{
    out(x...); LF;
}
template <class... T> void outTL(const T &...x)
{
    outT(x...); LF;
}
void setP()
{
    cout << setprecision(16);
}

////////////////////////////////////////////////////////////////
///// 宣言

template<class T> using VEC = vector<T>;
using VL = VEC<ll>;
using VS = VEC<string>;

template<class T> using VVEC = VEC<VEC<T>>;
using VVL = VVEC<ll>;
using VVS = VVEC<string>;

template<class T> using VVVEC = VVEC<VEC<T>>;
using VVVL = VVVEC<ll>;
using VVVS = VVVEC<string>;

template<class T1, class T2> using PR = pair<T1, T2>;
template<class T1, class T2> using VPR = VEC<PR<T1, T2>>;
using PLL = PR<ll, ll>;
using VPLL = VEC<PR<ll, ll>>;
using VVPLL = VVEC<PR<ll, ll>>;
using VVVPLL = VVVEC<PR<ll, ll>>;

template<class T> VEC<T> vec(size_t s1, const T &val = T{})
{
    return VEC<T>(s1, val);
}
template<class T> VVEC<T> vvec(size_t s1, size_t s2, const T &val = T{})
{
    return VVEC<T>(s1, VEC<T>(s2, val));
}
template<class T> VVVEC<T> vvvec(size_t s1, size_t s2, size_t s3, const T &val = T{})
{
    return VVVEC<T>(s1, VVEC<T>(s2, VEC<T>(s3, val)));
}
template<class T1, class T2> VPR<T1, T2> pvec(size_t s1)
{
    return VPR<T1, T2>(s1);
}

////////////////////////////////////////////////////////////////
///// 配列入力

template<class T> void vin(VEC<T> &v)
{
    vrep(x, v) in(x);
}
#define dvin(t,s,n1) VEC<t> n1(s); vin(n1);
template<class T1, class T2> void vin2(VEC<T1> &v1, VEC<T2> &v2)
{
    rep(i, 0, sz(v1)) {
        in(v1[i], v2[i]);
    }
}
#define dvin2(t,s,n1,n2) VEC<t> n1(s), n2(s); vin2(n1,n2);
template<class T1, class T2, class T3> void vin3(VEC<T1> &v1, VEC<T2> &v2, VEC<T3> &v3)
{
    rep(i, 0, sz(v1)) {
        in(v1[i], v2[i], v3[i]);
    }
}
#define dvin3(t,s,n1,n2,n3) VEC<t> n1(s), n2(s), n3(s); vin3(n1,n2,n3);
template<class T1, class T2, class T3, class T4> void vin4(VEC<T1> &v1, VEC<T2> &v2, VEC<T3> &v3, VEC<T4> &v4)
{
    rep(i, 0, sz(v1)) {
        in(v1[i], v2[i], v3[i], v4[i]);
    }
}
#define dvin4(t,s,n1,n2,n3,n4) VEC<t> n1(s), n2(s), n3(s), n4(s); vin4(n1,n2,n3,n4);
template<class T> void vvin(VVEC<T> &v)
{
    vrep(x, v) vrep(y, x) in(y);
}
template<class T> void vvvin(VVVEC<T> &v)
{
    vrep(x, v) vrep(y, x) vrep(z, y) in(z);
}
template<class T1, class T2> void pvin(VPR<T1, T2> &v)
{
    vrep(x, v) in(fst(x), snd(x));
}

////////////////////////////////////////////////////////////////
///// 宣言＋入力

#define vecin(t,x,s) VEC<t> x = vec<t>(s); vin(x);
#define vvecin(t,x,s1,s2) VVEC<t> x = vvec<t>(s1,s2); vvin(x);
#define vvvecin(t,x,s1,s2,s3) VVVEC<t> x = vvvec<t>(s1,s2,s3); vvvin(x);
#define pvecin(t1,t2,x,s) VPR<t1, t2> x = pvec<t1, t2>(s); pvin(x);

#define din(t,n1) t n1; in(n1);
#define din2(t,n1,n2) din(t,n1); din(t,n2);
#define din3(t,n1,n2,n3) din2(t,n1,n2); din(t,n3);
#define din4(t,n1,n2,n3,n4) din3(t,n1,n2,n3); din(t,n4);

#define dind(t,n1) t n1; ind(n1);
#define din2d(t,n1,n2) dind(t,n1); dind(t,n2);
#define din3d(t,n1,n2,n3) din2d(t,n1,n2); dind(t,n3);
#define din4d(t,n1,n2,n3,n4) din3d(t,n1,n2,n3); dind(t,n4);

////////////////////////////////////////////////////////////////
///// 配列出力

template<class T> void outV(const VEC<T> &v)
{
    vrep(x, v) out(x);
}
template<class T> void outVL(const VEC<T> &v)
{
    outV(v); LF;
}
template<class T> void outVT(const VEC<T> &v)
{
    vrep(x, v) outTL(x);
}
template<class T> void outVV(const VVEC<T> &v)
{
    vrep(x, v) outVL(x);
}
template<class T> void outVVT(const VVEC<T> &v)
{
    vrep(x, v) outVL(x); LF;
}
template<class T> void outVVV(const VVVEC<T> &v)
{
    vrep(x, v) outVVT(x);
}

////////////////////////////////////////////////////////////////
