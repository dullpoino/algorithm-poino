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

#define all(name) (name).begin(), (name).end()
#define rall(name) (name).rbegin(), (name).rend()

#define sz(name) (ll)(name).size()
#define fst(name) (name).first
#define snd(name) (name).second

void YESNO(bool cond) {
    cout << (cond ? "YES" : "NO") << "\n";
}
void yesno(bool cond) {
    cout << (cond ? "yes" : "no") << "\n";
}
void YesNo(bool cond) {
    cout << (cond ? "Yes" : "No") << "\n";
}

template<class T> void chmax(T &a, const T &b) {
    if (a < b) a = b;
}
template<class T> void chmin(T &a, const T &b) {
    if (a > b) a = b;
}

template<class T> using pqasc = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pqdesc = priority_queue<T, vector<T>, less<T>>;

template<class T> T popb(deque<T> &q) {
    T x = move(q.back()); q.pop_back(); return x;
}
template<class T> T popf(deque<T> &q) {
    T x = move(q.front()); q.pop_front(); return x;
}
template<class T, class COMP> T poppq(priority_queue<T, vector<T>, COMP> &q) {
    T x = move(q.top()); q.pop(); return x;
}

const ll MODP = 1000000007;
const ll MODM = 998244353;
const ll INF = (1ll << 62);
const ld PI = 3.141592653589793238462643383279502884L;
const ll GSZ = 200009;

// RDLU(ESWN)
const ll dh[4] = { 0, 1, 0, -1 };
const ll dw[4] = { 1, 0, -1, 0 };
const ll dh8[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const ll dw8[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

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
#define vrep(x, v) for(auto& x : (v))

////////////////////////////////////////////////////////////////
///// 入力関数

template <class... Args> void in(Args&... args) {
    ((cin >> args), ...);
}
template <class... Args> void ind(Args&... args) {
    ((cin >> args, --args), ...);
}

////////////////////////////////////////////////////////////////
///// 出力関数

template <class... Args> void out(Args... args) {
    ((cout << args << " "), ...);
}
template <class... Args> void outT(Args... args) {
    ((cout << args), ...);
}
template <class Argf, class... Args> void outS(Argf argf, Args... args) {
    cout << argf; ((cout << " " << args), ...);
}
template <class... Args> void outL(Args... args) {
    ((cout << args << " "), ...); LF;
}
template <class... Args> void outTL(Args... args) {
    ((cout << args), ...); LF;
}
template <class Argf, class... Args> void outSL(Argf argf, Args... args) {
    cout << argf; ((cout << " " << args), ...); LF;
}
template <class... Args> void outP(Args... args) {
    ((cout << setprecision(16) << args << " "), ...);
}
template <class... Args> void outPL(Args... args) {
    ((cout << setprecision(16) << args << " "), ...); LF;
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

template<class T> VEC<T> vec(size_t s1, const T &val = T{}) {
    return VEC<T>(s1, val);
}
template<class T> VVEC<T> vvec(size_t s1, size_t s2, const T &val = T{}) {
    return VVEC<T>(s1, VEC<T>(s2, val));
}
template<class T> VVVEC<T> vvvec(size_t s1, size_t s2, size_t s3, const T &val = T{}) {
    return VVVEC<T>(s1, VVEC<T>(s2, VEC<T>(s3, val)));
}
template<class T1, class T2> VPR<T1, T2> pvec(size_t s1) {
    return VPR<T1, T2>(s1);
}

////////////////////////////////////////////////////////////////
///// 配列入力

template<class T> void vin(VEC<T> &v) {
    vrep(x, v) in(x);
}
#define dvin(type, size, n1) type n1(size); vin(n1);
template<class T1, class T2> void vin2(VEC<T1> &v1, VEC<T2> &v2) {
    rep(i, 0, sz(v1)) {
        in(v1[i], v2[i]);
    }
}
#define dvin2(type, size, n1, n2) type n1(size), n2(size); vin2(n1, n2);
template<class T1, class T2, class T3> void vin3(VEC<T1> &v1, VEC<T2> &v2, VEC<T3> &v3) {
    rep(i, 0, sz(v1)) {
        in(v1[i], v2[i], v3[i]);
    }
}
#define dvin3(type, size, n1, n2, n3) type n1(size), n2(size), n3(size); vin3(n1, n2, n3);
template<class T1, class T2, class T3, class T4> void vin4(VEC<T1> &v1, VEC<T2> &v2, VEC<T3> &v3, VEC<T4> &v4) {
    rep(i, 0, sz(v1)) {
        in(v1[i], v2[i], v3[i], v4[i]);
    }
}
#define dvin4(type, size, n1, n2, n3, n4) type n1(size), n2(size), n3(size), n4(size); vin4(n1, n2, n3, n4);
template<class T> void vvin(VVEC<T> &v) {
    vrep(x, v) vrep(y, x) in(y);
}
template<class T> void vvvin(VVVEC<T> &v) {
    vrep(x, v) vrep(y, x) vrep(z, y) in(z);
}
template<class T1, class T2> void pvin(VPR<T1, T2> &v) {
    vrep(x, v) in(fst(x), snd(x));
}

////////////////////////////////////////////////////////////////
///// 宣言＋入力

#define vecin(type,name,vsize) VEC<type> name = vec<type>(vsize); vin(name);
#define vvecin(type,name,vsize1,vsize2) VVEC<type> name = vvec<type>(vsize1,vsize2); vvin(name);
#define vvvecin(type,name,vsize1,vsize2,vsize3) VVVEC<type> name = vvvec<type>(vsize1,vsize2,vsize3); vvvin(name);
#define pvecin(type1,type2,name,vsize) PVEC<type1,type2> name = pvec<type1,type2>(vsize); pvin(name);

#define din(type, n1) type n1; in(n1);
#define din2(type, n1, n2) din(type, n1); din(type, n2);
#define din3(type, n1, n2, n3) din2(type, n1, n2); din(type, n3);
#define din4(type, n1, n2, n3, n4) din3(type, n1, n2, n3); din(type, n4);

#define dind(type, n1) type n1; ind(n1);
#define din2d(type, n1, n2) dind(type, n1); dind(type, n2);
#define din3d(type, n1, n2, n3) din2d(type, n1, n2); dind(type, n3);
#define din4d(type, n1, n2, n3, n4) din3d(type, n1, n2, n3); dind(type, n4);

////////////////////////////////////////////////////////////////
///// 配列出力

template<class T> void outV(const VEC<T> &v) {
    vrep(x, v) out(x);
}
template<class T> void outVL(const VEC<T> &v) {
    vrep(x, v) outL(x);
}
template<class T> void outVV(const VVEC<T> &v) {
    vrep(x, v) {
        outV(x); LF;
    }
}
template<class T> void outVVV(const VVVEC<T> &v) {
    vrep(x, v) {
        outVV(x); LF;
    }
}
template<class T1, class T2> void outPV(const VPR<T1, T2> &v) {
    vrep(x, v) outL(fst(x), snd(x));
}

////////////////////////////////////////////////////////////////