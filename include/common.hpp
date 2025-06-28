#pragma once

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define rep(i, a, n) for (ll i = (ll)(a); i < (ll)(n); ++i)
#define repd(i, a, n, d) for (ll i = (ll)(a); i < (ll)(n); i += (d))
#define rrep(i, a, n) for (ll i = ((ll)(n)-1); i >= (ll)(a); --i)
#define rrepd(i, a, n, d) for (ll i = ((ll)(n)-1); i >= (ll)(a); i -= (d))
#define repr(i, a, n) for (ll i = (ll)(a); i <= (ll)(n); ++i)
#define repdr(i, a, n, d) for (ll i = (ll)(a); i <= (ll)(n); i += (d))
#define rrepr(i, a, n) for (ll i = ((ll)(n)); i >= (ll)(a); --i)
#define rrepdr(i, a, n, d) for (ll i = ((ll)(n)); i >= (ll)(a); i -= (d))

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define YESNO(bool) {cout << (bool ? "YES" : "NO") << "\n";}
#define yesno(bool) {cout << (bool ? "yes" : "no") << "\n";}
#define YesNo(bool) {cout << (bool ? "Yes" : "No") << "\n";}

#define vec(type,name,vsize,...) vector<type> name(vsize, __VA_ARGS__)
#define vvec(type,name,vsize,vsize2,...) vector<vector<type> > name(vsize, vector<type>(vsize2, __VA_ARGS__))
#define vvvec(type,name,vsize,vsize2,vsize3,...) vector<vector<vector<type> > > name(vsize, vector<vector<type> >(vsize2, vector<type>(vsize3, __VA_ARGS__)))
#define vin(a, n) for (ll i = 0; i < (ll)(n); ++i) in(a[i]);
#define vind(a, m, n) for (ll i = 0; i < (ll)(m); ++i) for (ll j = 0; j < (ll)(n); ++j) in(a[i][j]);
#define vecin(type,name,vsize) vector<type> name(vsize); for (ll i = 0; i < (ll)(vsize); ++i) in(name[i]);
#define pvecin(type1,type2,name,vsize) vector<pair<type1, type2>> name(vsize); for (ll i = 0; i < (ll)(vsize); ++i) in(name[i].first, name[i].second);
#define vvecin(type,name,vsize) vector<vector<type> > name(vsize, vector<type>(vsize)); for (ll i = 0; i < (ll)(vsize); ++i) for (ll j = 0; j < (ll)(vsize); ++j) in(name[i][j]);
#define hwin(type,name,hsize,wsize) vector<vector<type> > name(hsize, vector<type>(wsize)); for (ll i = 0; i < (ll)(hsize); ++i) for (ll j = 0; j < (ll)(wsize); ++j) in(name[i][j]);

#define sz(a) (ll)(a).size()
#define outV(v) for(ll i = 0; i < (ll)((v).size()); ++i) cout << v[i] << " ";
#define outVL(v) for(ll i = 0; i < (ll)((v).size()); ++i) cout << v[i] << "\n";
#define outVV(v) for(ll i = 0; i < (ll)((v).size()); ++i) { for(ll j = 0; j < (ll)((v[i].size())); ++j) cout << v[i][j] << " "; cout << "\n"; }

#define popb(q) (q).back(); (q).pop_back();
#define popf(q) (q).front(); (q).pop_front();
#define poppq(q) (q).top(); (q).pop();

#define din(type, name1) type name1; in(name1);
#define din2(type, name1, name2) type name1, name2; in(name1, name2);
#define din3(type, name1, name2, name3) type name1, name2, name3; in(name1, name2, name3);
#define din4(type, name1, name2, name3, name4) type name1, name2, name3, name4; in(name1, name2, name3, name4);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> using pqasc = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pqdesc = priority_queue<T, vector<T>>;

template <class... Args>
void in(Args&&... args) {
    ((cin >> args), ...);
}
template <class... Args>
void out(Args... args) {
    ((cout << args << " "), ...);
}
template <class... Args>
void outT(Args... args) {
    ((cout << args), ...);
}
template <class... Args>
void outL(Args... args) {
    ((cout << args << " "), ...);
    cout << "\n";
}
template <class... Args>
void outLT(Args... args) {
    ((cout << args), ...);
    cout << "\n";
}
template <class... Args>
void outP(Args... args) {
    ((cout << setprecision(16) << args << " "), ...);
}
template <class... Args>
void outPT(Args... args) {
    ((cout << setprecision(16) << args), ...);
}
template <class... Args>
void outLP(Args... args) {
    ((cout << setprecision(16) << args << " "), ...);
    cout << "\n";
}
template <class... Args>
void outLPT(Args... args) {
    ((cout << setprecision(16) << args), ...);
    cout << "\n";
}

#define LF cout << "\n";

const ll MODP = (ll)1e9 + 7;
const ll MODM = 998244353;
const ll INF = (ll)1e18 + 9;
const ld PI = acos(-1.0);
const ll GSZ = 200009;

ll dh[4] = { 0, 1, 0, -1 }; // RDLU(ESWN)
ll dw[4] = { 1, 0, -1, 0 };
ll dh8[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }; // RDLU(ESWN)
ll dw8[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };