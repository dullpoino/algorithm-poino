#pragma once
#include "common.hpp"

/**********************************************************
Bound
**********************************************************/
const ll ITRINF = -1;

pair<vector<ll>::iterator, ll> boundLTV(vector<ll>& v, ll key)
{
    auto it = lower_bound(all(v), key);
    it == v.begin() ? (it = v.end()) : --it;
    auto val = (it != v.end() ? *it : ITRINF);
    return { it, val };
}
ll countLTV(vector<ll>& v, ll key)
{
    return distance(v.begin(), lower_bound(all(v), key));
}
pair<set<ll>::iterator, ll> boundLTS(set<ll>& v, ll key)
{
    auto it = v.lower_bound(key);
    it == v.begin() ? (it = v.end()) : --it;
    auto val = (it != v.end() ? *it : ITRINF);
    return { it, val };
}
ll countLTS(set<ll>& v, ll key)
{
    return distance(v.begin(), v.lower_bound(key));
}
pair<vector<ll>::iterator, ll> boundLEV(vector<ll>& v, ll key)
{
    auto it = upper_bound(all(v), key);
    it == v.begin() ? (it = v.end()) : --it;
    auto val = (it != v.end() ? *it : ITRINF);
    return { it, val };
}
ll countLEV(vector<ll>& v, ll key)
{
    return distance(v.begin(), upper_bound(all(v), key));
}
pair<set<ll>::iterator, ll> boundLES(set<ll>& v, ll key)
{
    auto it = v.upper_bound(key);
    it == v.begin() ? (it = v.end()) : --it;
    auto val = (it != v.end() ? *it : ITRINF);
    return { it, val };
}
ll countLES(set<ll>& v, ll key)
{
    return distance(v.begin(), v.upper_bound(key));
}
pair<vector<ll>::iterator, ll> boundGTV(vector<ll>& v, ll key)
{
    auto it = upper_bound(all(v), key);
    auto val = (it != v.end() ? *it : ITRINF);
    return { it, val };
}
ll countGTV(vector<ll>& v, ll key)
{
    return distance(upper_bound(all(v), key), v.end());
}
pair<set<ll>::iterator, ll> boundGTS(set<ll>& v, ll key)
{
    auto it = v.upper_bound(key);
    auto val = (it != v.end() ? *it : ITRINF);
    return { it, val };
}
ll countGTS(set<ll>& v, ll key)
{
    return distance(v.upper_bound(key), v.end());
}
pair<vector<ll>::iterator, ll> boundGEV(vector<ll>& v, ll key)
{
    auto it = lower_bound(all(v), key);
    auto val = (it != v.end() ? *it : ITRINF);
    return { it, val };
}
ll countGEV(vector<ll>& v, ll key)
{
    return distance(lower_bound(all(v), key), v.end());
}
pair<set<ll>::iterator, ll> boundGES(set<ll>& v, ll key)
{
    auto it = v.lower_bound(key);
    auto val = (it != v.end() ? *it : ITRINF);
    return { it, val };
}
ll countGES(set<ll>& v, ll key)
{
    return distance(v.lower_bound(key), v.end());
}
