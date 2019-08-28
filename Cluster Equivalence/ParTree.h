/*
 * ParTree.h
 *
 *  Created on: Jul 18, 2019
 *      Author: alex
 */

#ifndef PARTREE_H_
#define PARTREE_H_

#include "ParTreeNode.h"

template <typename E>
class ParTree : public ParTreeNode<E> {
private:
	int size;
	ParTreeNode<E>** array;
	int findRoot(int curNode) {
		if (array[curNode]->getParent() == this->ROOT) {
			return curNode;
		}
		array[curNode]->setParent(findRoot(array[curNode]->getParent()));
		return array[curNode]->getParent();
	}
public:
	ParTree(E* valArray, int setSize) {
		array = new ParTreeNode<E>*[setSize];
		for (int i = 0; i < setSize; ++i) {
			array[i] = new ParTreeNode<E>;
			array[i]->setValue(valArray[i]);
			array[i]->setParent(this->ROOT);
		}
		size = setSize;
	}

	~ParTree() {
		delete [] array;
	}

	void UNION(int elem1, int elem2) {
		int root1 = findRoot(elem1);
		int root2 = findRoot(elem2);
		if (root1 != root2) {
			if (array[root1]->getWeight() < array[root2]->getWeight()) {
				array[root1]->setParent(root2);
				array[root2]->setWeight(array[root2]->getWeight() + array[root1]->getWeight());
			} else {
				array[root2]->setParent(root1);
				array[root1]->setWeight(array[root2]->getWeight() + array[root1]->getWeight());
			}
		}
	}

	bool differ(int elem1, int elem2) {
		return findRoot(elem1) != findRoot(elem2);
	}

	ParTreeNode<E>* getNode(int index) {
		return array[index];
	}
};



#endif /* PARTREE_H_ */
