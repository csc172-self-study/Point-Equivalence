/*
 * ClusterTest.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: alex
 */

#include "EquivalenceClass.h"

#include <random>
#include <iostream>
#include <tuple>
using std::cout;

int main() {

	// Init variables and random distributions
	const int NUM_COORDS = 100;
	const int MAP_SIZE = 10;

	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<> posDistr(-MAP_SIZE,MAP_SIZE);

	// Set up cities to insert
	std::pair<int,int> pos[NUM_COORDS];
	for (int i = 0; i < NUM_COORDS; ++i) {
		pos[i] = std::make_pair(posDistr(eng), posDistr(eng));
	}

	EquivalenceClass equivs(pos, NUM_COORDS, 4);

	equivs.sort();
}
