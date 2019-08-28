/*
 * ParTreeNode.h
 *
 *  Created on: Jul 18, 2019
 *      Author: alex
 */

#ifndef PARTREENODE_H_
#define PARTREENODE_H_

template <typename E>
class ParTreeNode {
protected:
	E value;
	int parent;
	int weight;
public:
	const static int ROOT = -999;
	ParTreeNode() {
		parent = -1;
		weight = 0;
	}

	ParTreeNode(const E& val) {
		value = val;
		parent = ROOT;
		weight = 1;
	}

	int getParent() {
		return parent;
	}

	void setParent(int par) {
		parent = par;
	}

	E getValue() {
		return value;
	}

	void setValue(const E& val) {
		value = val;
	}

	int getWeight() {
		return weight;
	}

	void setWeight(int wgt) {
		weight = wgt;
	}
};

#endif /* PARTREENODE_H_ */
