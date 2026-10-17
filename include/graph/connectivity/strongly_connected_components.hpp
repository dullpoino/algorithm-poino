#pragma once
#include "common.hpp"

void scc(VVL &G, VVL &groups, VL &id, ll &K, VVL &dag)
{
    ll N = sz(G);

    VVL RG(N);
    rep(i, 0, N) {
        for (auto &x : G[i]) {
            RG[x].push_back(i);
        }
    }

    VL visited(N, 0);
    VL order;
    rep(i, 0, N) {
        if (visited[i] == 0) {
            dfs(G, visited, i, false, order);
        }
    }

    visited.assign(N, 0);
    id.assign(N, -1);
    K = 0;

    VL vs;
    rrep(i, 0, N) {
        ll s = order[i];

        if (visited[s] != 0) {
            continue;
        }

        vs.clear();
        dfs(RG, visited, s, false, vs);

        for (auto v : vs) {
            id[v] = K;
        }

        ++K;
    }

    groups = VVL(K);
    rep(i, 0, N) {
        groups[id[i]].push_back(i);
    }

    dag = VVL(K);
    VL visited2(K, -1);
    rep(i, 0, K) {
        for (auto v : groups[i]) {
            for (auto next : G[v]) {
                ll j = id[next];

                if (i == j || visited2[j] == i) {
                    continue;
                }

                dag[i].push_back(j);
                visited2[j] = i;
            }
        }
    }
}
