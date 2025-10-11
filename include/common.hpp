#pragma once

#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////////
///// 型定義

typedef long long ll;
typedef long double ld;

////////////////////////////////////////////////////////////////
///// utildefine

#define LF cout << "\n"

#define all(name) (name).begin(), (name).end()
#define rall(name) (name).rbegin(), (name).rend()

#define YESNO(cond) { cout << (cond ? "YES" : "NO") << "\n"; }
#define yesno(cond) { cout << (cond ? "yes" : "no") << "\n"; }
#define YesNo(cond) { cout << (cond ? "Yes" : "No") << "\n"; }

#define sz(name) (ll)(name).size()

#define popb(qname) (qname).back(); (qname).pop_back()
#define popf(qname) (qname).front(); (qname).pop_front()
#define poppq(qname) (qname).top(); (qname).pop()

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
///// 宣言

#define vecd(type,name) vector<type> name
#define vecs1(type,name,vsize) vector<type> name(vsize)
#define vec(type,name,vsize,...) vector<type> name(vsize, __VA_ARGS__)
#define vvecd(type,name) vector<vector<type> > name
#define vvecs1(type,name,vsize) vector<vector<type> > name(vsize)
#define vvecs2(type,name,vsize,vsize2) vector<vector<type> > name(vsize, vector<type>(vsize2))
#define vvec(type,name,vsize,vsize2,...) vector<vector<type> > name(vsize, vector<type>(vsize2, __VA_ARGS__))
#define vvvecd(type,name) vector<vector<vector<type> > > name
#define vvvecs1(type,name,vsize) vector<vector<vector<type> > > name(vsize)
#define vvvecs2(type,name,vsize,vsize2) vector<vector<vector<type> > > name(vsize, vector<vector<type> >(vsize2))
#define vvvecs3(type,name,vsize,vsize2,vsize3) vector<vector<vector<type> > > name(vsize, vector<vector<type> >(vsize2, vector<type>(vsize3)))
#define vvvec(type,name,vsize,vsize2,vsize3,...) vector<vector<vector<type> > > name(vsize, vector<vector<type> >(vsize2, vector<type>(vsize3, __VA_ARGS__)))

#define vecp(type1,type2,name) vector<pair<type1, type2> > name
#define vecps1(type1,type2,name,vsize) vector<pair<type1, type2> > name(vsize)

#define vecm(type1,type2,name) vector<map<type1, type2> > name
#define vecms1(type1,type2,name,vsize) vector<map<type1, type2> > name(vsize)

////////////////////////////////////////////////////////////////
///// 配列入力

#define vecin(name,vsize) rep(lpcnt, 0, vsize) in(name[lpcnt])
#define vvecin(name,vsize,vsize2) rep(lpcnt, 0, vsize) rep(lpcnt2, 0, vsize2) in(name[lpcnt][lpcnt2])
#define vvvecin(name,vsize,vsize2,vsize3) rep(lpcnt, 0, vsize) rep(lpcnt2, 0, vsize2) rep(lpcnt3, 0, vsize3) in(name[lpcnt][lpcnt2][lpcnt3])

#define vecpin(name,vsize) rep(i, 0, vsize) in(name[i].first, name[i].second)

#define vecmin(name,vsize) rep(i, 0, vsize) in(name[i])

////////////////////////////////////////////////////////////////
///// 宣言＋入力

#define vecdin(type,name,vsize) vecs1(type,name,vsize); vecin(name,vsize)
#define vvecdin(type,name,vsize,vsize2) vvecs2(type,name,vsize,vsize2); vvecin(name,vsize,vsize2)
#define vvvecdin(type,name,vsize,vsize2,vsize3) vvvecs3(type,name,vsize,vsize2,vsize3); vvvecin(name,vsize,vsize2,vsize3)

#define vecpdin(type1,type2,name,vsize) vecps1(type1,type2,name,vsize); vecpin(name,vsize)

#define vecmdin(type1,type2,name,vsize) vecms1(type1,type2,name,vsize); vecmin(name,vsize)

#define din(type, name1) type name1; in(name1);
#define din2(type, name1, name2) type name1, name2; in(name1, name2);
#define din3(type, name1, name2, name3) type name1, name2, name3; in(name1, name2, name3);
#define din4(type, name1, name2, name3, name4) type name1, name2, name3, name4; in(name1, name2, name3, name4);

#define dind(type, name1) type name1; in(name1); --name1;
#define din2d(type, name1, name2) type name1, name2; in(name1, name2); --name1; --name2;
#define din3d(type, name1, name2, name3) type name1, name2, name3; in(name1, name2, name3); --name1; --name2; --name3;
#define din4d(type, name1, name2, name3, name4) type name1, name2, name3, name4; in(name1, name2, name3, name4); --name1; --name2; --name3; --name4;

////////////////////////////////////////////////////////////////
///// 配列出力

#define outV(name) rep(lpcnt,0,sz(name)) cout << name[lpcnt] << " "
#define outVL(name) rep(lpcnt,0,sz(name)) cout << name[lpcnt] << "\n"
#define outVV(name) rep(lpcnt,0,sz(name)) { rep(lpcnt2,0,sz(name[lpcnt])) cout << name[lpcnt][lpcnt2] << " "; LF; }
#define outVVV(name) rep(lpcnt,0,sz(name)) { rep(lpcnt2,0,sz(name[lpcnt])) { rep(lpcnt3,0,sz(name[lpcnt][lpcnt2])) cout << name[lpcnt][lpcnt2][lpcnt3] << " "; LF; } LF; LF; }

////////////////////////////////////////////////////////////////
///// 入力関数

template <class... Args>
void in(Args&... args) {
    ((cin >> args), ...);
}

////////////////////////////////////////////////////////////////
///// 出力関数

template <class Argf, class... Args>
void out(Argf argf, Args... args) {
    cout << argf;
    ((cout << " " << args), ...);
}
template <class... Args>
void outS(Args... args) {
    ((cout << args << " "), ...);
}
template <class... Args>
void outT(Args... args) {
    ((cout << args), ...);
}
template <class Argf, class... Args>
void outA(string str, Argf argf, Args... args) {
    cout << argf;
    ((cout << str << args), ...);
}
template <class Argf, class... Args>
void outL(Argf argf, Args... args) {
    cout << argf;
    ((cout << " " << args), ...);
    LF;
}
template <class... Args>
void outTL(Args... args) {
    ((cout << args), ...);
    LF;
}
template <class Argf, class... Args>
void outAL(string str, Argf argf, Args... args) {
    cout << argf;
    ((cout << str << args), ...);
    LF;
}
template <class Argf, class... Args>
void outP(Argf argf, Args... args) {
    cout << setprecision(16) << argf;
    ((cout << " " << args), ...);
}
template <class... Args>
void outPT(Args... args) {
    ((cout << setprecision(16) << args), ...);
}
template <class Argf, class... Args>
void outPL(Argf argf, Args... args) {
    cout << setprecision(16) << argf;
    ((cout << " " << args), ...);
    LF;
}
template <class... Args>
void outPTL(Args... args) {
    ((cout << setprecision(16) << args), ...);
    LF;
}
template <class Argf, class... Args>
void outPAL(string str, Argf argf, Args... args) {
    cout << setprecision(16) << argf;
    ((cout << str << args), ...);
    LF;
}

////////////////////////////////////////////////////////////////
///// その他

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> using pqasc = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pqdesc = priority_queue<T, vector<T>, less<T>>;

inline constexpr ll MODP = 1000000000ll + 7;
inline constexpr ll MODM = 998244353;
inline constexpr ll INF = 1000000000000000000ll + 9;
inline constexpr ld PI = 3.141592653589793238462643383279502884L;
inline constexpr ll GSZ = 200009;

inline constexpr ll dh[4] = { 0, 1, 0, -1 }; // RDLU(ESWN)
inline constexpr ll dw[4] = { 1, 0, -1, 0 };
inline constexpr ll dh8[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }; // RDLU(ESWN)
inline constexpr ll dw8[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
