/*
 * EquivalenceClass.cpp
 *
 *  Created on: Jul 18, 2019
 *      Author: alex
 */

#include <cmath>
#include "EquivalenceClass.h"
using std::sqrt;

EquivalenceClass::EquivalenceClass(pair<int,int>* coordArray, int size, int dist) {
	forest = new ParTree<pair<int,int>>(coordArray, size);
	numNodes = size;
	distance = dist;
}

EquivalenceClass::~EquivalenceClass() {}

bool EquivalenceClass::equivalent(int node1, int node2) {
	// Don't need to do anything if they're already in the same tree
	if (forest->differ(node1,node2)) {
		return true;
	}

	int x1; int y1; int x2; int y2;
	std::tie(x1, y1) = forest->getNode(node1)->getValue();
	std::tie(x2, y2) = forest->getNode(node2)->getValue();
	int xdist = x1 - x2;
	int ydist = y1 - y2;

	return sqrt(xdist*xdist + ydist*ydist) <= distance;
}

void EquivalenceClass::sort() {
	for (int i = 0; i < numNodes; ++i) {
		for (int j = i + 1; j < numNodes; ++j) {
			if (equivalent(i,j)) {
				forest->UNION(i,j);
			}
		}
	}
}
