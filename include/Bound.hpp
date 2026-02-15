#pragma once
#include "common.hpp"

/**********************************************************
Bound (vector)
**********************************************************/

template<class T, class COMP = less<>>
pair<typename VEC<T>::iterator, optional<T>>
boundLT(VEC<T>& v, T& key, COMP comp = COMP())
{
    auto it = lower_bound(all(v), key, comp);
    if (it == v.begin()) return { v.end(), nullopt };
    --it;
    return { it, *it };
}
template <class T, class COMP = less<>>
ll countLT(VEC<T>& v, T& key, COMP comp = COMP()) {
    auto it = lower_bound(all(v), key, comp);
    return distance(v.begin(), it);
}

template<class T, class COMP = less<>>
pair<typename VEC<T>::iterator, optional<T>>
boundLE(VEC<T>& v, T& key, COMP comp = COMP())
{
    auto it = upper_bound(all(v), key, comp);
    if (it == v.begin()) return { v.end(), nullopt };
    --it;
    return { it, *it };
}
template <class T, class COMP = less<>>
ll countLE(VEC<T>& v, T& key, COMP comp = COMP()) {
    auto it = upper_bound(all(v), key, comp);
    return distance(v.begin(), it);
}

template<class T, class COMP = less<>>
pair<typename VEC<T>::iterator, optional<T>>
boundGT(VEC<T>& v, T& key, COMP comp = COMP())
{
    auto it = upper_bound(all(v), key, comp);
    if (it == v.end()) return { v.end(), nullopt };
    return { it, *it };
}
template <class T, class COMP = less<>>
ll countGT(VEC<T>& v, T& key, COMP comp = COMP()) {
    auto it = upper_bound(all(v), key, comp);
    return distance(it, v.end());
}

template<class T, class COMP = less<>>
pair<typename VEC<T>::iterator, optional<T>>
boundGE(VEC<T>& v, T& key, COMP comp = COMP())
{
    auto it = lower_bound(all(v), key, comp);
    if (it == v.end()) return { v.end(), nullopt };
    return { it, *it };
}
template <class T, class COMP = less<>>
ll countGE(VEC<T>& v, T& key, COMP comp = COMP()) {
    auto it = lower_bound(all(v), key, comp);
    return distance(it, v.end());
}

/**********************************************************
Bound (set)
**********************************************************/

template<class T>
pair<typename set<T>::iterator, optional<T>>
boundLT(set<T>& s, T& key)
{
    auto it = s.lower_bound(key);
    if (it == s.begin()) return { s.end(), nullopt };
    --it;
    return { it, *it };
}
template <class T>
ll countLT(set<T>& s, T& key) {
    auto it = s.lower_bound(key);
    return distance(s.begin(), it);
}

template<class T>
pair<typename set<T>::iterator, optional<T>>
boundLE(set<T>& s, T& key)
{
    auto it = s.upper_bound(key);
    if (it == s.begin()) return { s.end(), nullopt };
    --it;
    return { it, *it };
}
template <class T>
ll countLE(set<T>& s, T& key) {
    auto it = s.upper_bound(key);
    return distance(s.begin(), it);
}

template<class T>
pair<typename set<T>::iterator, optional<T>>
boundGT(set<T>& s, T& key)
{
    auto it = s.upper_bound(key);
    if (it == s.end()) return { s.end(), nullopt };
    return { it, *it };
}
template <class T>
ll countGT(set<T>& s, T& key) {
    auto it = s.upper_bound(key);
    return distance(it, s.end());
}

template<class T>
pair<typename set<T>::iterator, optional<T>>
boundGE(set<T>& s, T& key)
{
    auto it = s.lower_bound(key);
    if (it == s.end()) return { s.end(), nullopt };
    return { it, *it };
}
template <class T>
ll countGE(set<T>& s, T& key) {
    auto it = s.lower_bound(key);
    return distance(it, s.end());
}