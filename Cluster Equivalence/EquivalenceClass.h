/*
 * EquivalenceClass.h
 *
 *  Created on: Jul 18, 2019
 *      Author: alex
 */

#ifndef EQUIVALENCECLASS_H_
#define EQUIVALENCECLASS_H_

#include <tuple>
#include "ParTree.h"
using std::pair;

class EquivalenceClass {
private:
	ParTree<pair<int,int>>* forest;
	int numNodes;
	double distance;
public:
	EquivalenceClass(pair<int,int>* coordArray, int size, int dist);
	virtual ~EquivalenceClass();
	bool equivalent(int node1, int node2);
	void sort();
};

#endif /* EQUIVALENCECLASS_H_ */
