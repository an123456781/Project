/**	@file BinaryTree.cpp
	@author Jimin Park
	@date 2019-12-06
*/

#pragma once
#include <iostream>
#include <vector> 
#include <fstream>
#include "WisconsinNode.hpp"
using namespace std;

class BinaryTree
{
public:
	BinaryTree() : root_(nullptr) {}

	WisconsinNode* generatedTree(WisconsinNode*);
	void deleteAllNode(vector<WisconsinNode*>& attributesV);
	void deleteAllNodes(WisconsinNode* node, vector<WisconsinNode*>& attributesV);
	void writeCSVWithDiagnosis(vector<WisconsinNode*>& attributesV);

private:
	WisconsinNode* root_;
};

