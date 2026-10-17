#pragma once
#include "common.hpp"

bool FloydWarshall(VVL &G)
{
    ll N = sz(G);

    rep(k, 0, N) {
        rep(i, 0, N) {
            rep(j, 0, N) {
                if (G[i][k] == INF || G[k][j] == INF) {
                    continue;
                }

                chmin(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    rep(i, 0, N) {
        if (G[i][i] < 0) {
            return false;
        }
    }

    return true;
}
