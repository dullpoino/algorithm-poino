#pragma once
#include "common.hpp"

/**********************************************************
フロイドの循環検出アルゴリズム
G : Functional Graph
**********************************************************/

ll RabbitAndTurtle(VL& G, ll start)
{
	ll rabbit = G[G[start]], turtle = G[start];

	while (rabbit != turtle) {
		rabbit = G[G[rabbit]];
		turtle = G[turtle];
	}

	rabbit = start;

	while (rabbit != turtle) {
		rabbit = G[rabbit];
		turtle = G[turtle];
	}

	out(rabbit);

	return rabbit;
}