#pragma once
#include "common.hpp"

/**********************************************************
ダイクストラ
**********************************************************/
void Dijkstra(vector<vector<pair<ll, ll> > >& G, ll N, ll start)
{
	vector<bool> kakutei(N, false);
	vector<ll> cur(N, INF);
	pqasc<pair<ll, ll> > q;

	cur[start] = 0;
	q.push({ cur[start], start });

	while (!q.empty()) {
		auto [curv, curp] = poppq(q);

		if (kakutei[curp] == false) {
			kakutei[curp] = true;

			for (auto [next, cost] : G[curp]) {
				if (cur[next] > curv + cost) {
					cur[next] = curv + cost;
					q.push({ cur[next], next });
				}
			}
		}
	}

	rep(i, 0, N) {
		if (cur[i] == INF) {
			outL(-1);
		}
		else {
			outL(cur[i]);
		}
	}
}