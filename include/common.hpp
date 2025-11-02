#pragma once

#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////////
///// 型定義

typedef long long ll;
typedef long double ld;

////////////////////////////////////////////////////////////////
///// その他

#define LF cout << "\n"

#define all(name) (name).begin(), (name).end()
#define rall(name) (name).rbegin(), (name).rend()

#define sz(name) (ll)(name).size()

inline void YESNO(bool cond) { cout << (cond ? "YES" : "NO") << "\n"; }
inline void yesno(bool cond) { cout << (cond ? "yes" : "no") << "\n"; }
inline void YesNo(bool cond) { cout << (cond ? "Yes" : "No") << "\n"; }
inline void TF(bool cond, const string& t, const string& f) { cout << (cond ? t : f) << "\n"; }

template<class T> inline void chmax(T& a, const T& b) { if (a < b) a = b; }
template<class T> inline void chmin(T& a, const T& b) { if (a > b) a = b; }

template<class T> using pqasc = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pqdesc = priority_queue<T, vector<T>, less<T>>;

template<class T>
T popb(deque<T>& q)
{
    T x = move(q.back());
    q.pop_back();
    return x;
}
template<class T>
T popf(deque<T>& q)
{
    T x = move(q.front());
    q.pop_front();
    return x;
}
template<class T, class COMP>
T poppq(priority_queue<T, vector<T>, COMP>& q)
{
    T x = move(q.top());
    q.pop();
    return x;
}

inline constexpr ll MODP = 1000000007;
inline constexpr ll MODM = 998244353;
inline constexpr ll INF = (1ll << 62);
inline constexpr ld PI = 3.141592653589793238462643383279502884L;
inline constexpr ll GSZ = 200009;

inline constexpr ll dh[4] = { 0, 1, 0, -1 }; // RDLU(ESWN)
inline constexpr ll dw[4] = { 1, 0, -1, 0 };
inline constexpr ll dh8[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }; // RDLU(ESWN)
inline constexpr ll dw8[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

////////////////////////////////////////////////////////////////
///// ループ

#define rep(lpcnt,name,lpsize) for (ll lpcnt = (ll)(name); lpcnt < (ll)(lpsize); ++lpcnt)
#define repd(lpcnt,name,lpsize,isize) for (ll lpcnt = (ll)(name); lpcnt < (ll)(lpsize); lpcnt += (isize))
#define rrep(lpcnt,name,lpsize) for (ll lpcnt = ((ll)(lpsize)-1); lpcnt >= (ll)(name); --lpcnt)
#define rrepd(lpcnt,name,lpsize,isize) for (ll lpcnt = ((ll)(lpsize)-1); lpcnt >= (ll)(name); lpcnt -= (isize))
#define repr(lpcnt,name,lpsize) for (ll lpcnt = (ll)(name); lpcnt <= (ll)(lpsize); ++lpcnt)
#define repdr(lpcnt,name,lpsize,isize) for (ll lpcnt = (ll)(name); lpcnt <= (ll)(lpsize); lpcnt += (isize))
#define rrepr(lpcnt,name,lpsize) for (ll lpcnt = ((ll)(lpsize)); lpcnt >= (ll)(name); --lpcnt)
#define rrepdr(lpcnt,name,lpsize,isize) for (ll lpcnt = ((ll)(lpsize)); lpcnt >= (ll)(name); lpcnt -= (isize))

////////////////////////////////////////////////////////////////
///// 入力関数

template <class... Args>
void in(Args&... args) {
    ((cin >> args), ...);
}
template <class... Args>
void ind(Args&... args) {
    ((cin >> args, --args), ...);
}

////////////////////////////////////////////////////////////////
///// 出力関数

template <class... Args>
void out(Args... args) {
    ((cout << args << " "), ...);
}
template <class... Args>
void outT(Args... args) {
    ((cout << args), ...);
}
template <class Argf, class... Args>
void outS(Argf argf, Args... args) {
    cout << argf;
    ((cout << " " << args), ...);
}
template <class... Args>
void outL(Args... args) {
    ((cout << args << " "), ...);
    LF;
}
template <class... Args>
void outTL(Args... args) {
    ((cout << args), ...);
    LF;
}
template <class Argf, class... Args>
void outSL(Argf argf, Args... args) {
    cout << argf;
    ((cout << " " << args), ...);
    LF;
}
template <class... Args>
void outP(Args... args) {
    ((cout << setprecision(16) << args << " "), ...);
}
template <class... Args>
void outPL(Args... args) {
    ((cout << setprecision(16) << args << " "), ...);
    LF;
}

////////////////////////////////////////////////////////////////
///// 宣言

template<class T> using VEC = vector<T>;
template<class T> using VVEC = vector<vector<T>>;
template<class T> using VVVEC = vector<vector<vector<T>>>;
template<class T1, class T2> using PVEC = vector<pair<T1, T2>>;

template<class T>
VEC<T> vec(size_t s1, const T& val = T{})
{
    return VEC<T>(s1, val);
}
template<class T>
VVEC<T> vvec(size_t s1, size_t s2, const T& val = T{})
{
    return VVEC<T>(s1, VEC<T>(s2, val));
}
template<class T>
VVVEC<T> vvvec(size_t s1, size_t s2, size_t s3, const T& val = T{})
{
    return VVVEC<T>(s1, VVEC<T>(s2, VEC<T>(s3, val)));
}
template<class T1, class T2>
PVEC<T1, T2> pvec(size_t s1)
{
    return PVEC<T1, T2>(s1);
}

////////////////////////////////////////////////////////////////
///// 配列入力

template<class T>
void vin(VEC<T>& v)
{
    for (auto& x : v) in(x);
}
template<class T1, class T2>
void vin2(VEC<T1>& v1, VEC<T2>& v2)
{
    rep(i, 0, sz(v1)) {
        in(v1[i], v2[i]);
    }
}
template<class T1, class T2, class T3>
void vin3(VEC<T1>& v1, VEC<T2>& v2, VEC<T3>& v3)
{
    rep(i, 0, sz(v1)) {
        in(v1[i], v2[i], v3[i]);
    }
}
template<class T1, class T2, class T3, class T4>
void vin4(VEC<T1>& v1, VEC<T2>& v2, VEC<T3>& v3, VEC<T4>& v4)
{
    rep(i, 0, sz(v1)) {
        in(v1[i], v2[i], v3[i], v4[i]);
    }
}
template<class T>
void vvin(VVEC<T>& v)
{
    for (auto& x : v) for (auto& y : x) in(y);
}
template<class T>
void vvvin(VVVEC<T>& v)
{
    for (auto& x : v) for (auto& y : x) for (auto& z : y) in(z);
}
template<class T1, class T2>
void pvin(PVEC<T1, T2>& v)
{
    for (auto& x : v) in(x.first, x.second);
}

////////////////////////////////////////////////////////////////
///// 宣言＋入力

#define vecin(type,name,vsize) VEC<type> name = vec<type>(vsize); vin(name);
#define vvecin(type,name,vsize1,vsize2) VVEC<type> name = vvec<type>(vsize1,vsize2); vvin(name);
#define vvvecin(type,name,vsize1,vsize2,vsize3) VVVEC<type> name = vvvec<type>(vsize1,vsize2,vsize3); vvvin(name);
#define pvecin(type1,type2,name,vsize) PVEC<type1,type2> name = pvec<type1,type2>(vsize); pvin(name);

#define din(type, name1) type name1; in(name1);
#define din2(type, name1, name2) type name1, name2; in(name1, name2);
#define din3(type, name1, name2, name3) type name1, name2, name3; in(name1, name2, name3);
#define din4(type, name1, name2, name3, name4) type name1, name2, name3, name4; in(name1, name2, name3, name4);

#define dind(type, name1) type name1; ind(name1);
#define din2d(type, name1, name2) type name1, name2; ind(name1, name2);
#define din3d(type, name1, name2, name3) type name1, name2, name3; ind(name1, name2, name3);
#define din4d(type, name1, name2, name3, name4) type name1, name2, name3, name4; ind(name1, name2, name3, name4);

////////////////////////////////////////////////////////////////
///// 配列出力

template<class T>
void outV(const VEC<T>& v)
{
    for (const auto& x : v) out(x);
}
template<class T>
void outVL(const VEC<T>& v)
{
    for (const auto& x : v) outL(x);
}
template<class T>
void outVV(const VVEC<T>& v)
{
    for (const auto& x : v) {
        for (const auto& y : x) {
            out(y);
        }
        LF;
    }
}
template<class T>
void outVVV(const VVVEC<T>& v)
{
    for (const auto& x : v) {
        for (const auto& y : x) {
            for (const auto& z : y) {
                out(z);
            }
            LF;
        }
        LF;
    }
}
template<class T1, class T2>
void outPV(const PVEC<T1, T2>& v)
{
    for (const auto& x : v) outL(x.first, x.second);
}

////////////////////////////////////////////////////////////////