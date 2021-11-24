/**	@file Node.cpp
	@author Jimin Park
	@date 2019-12-06
*/

#pragma once
#include <string>
using namespace std;

class Node
{
public:
	int cntEdge_ = 0;
	Node* next_;
	int dest_; // destination

	Node(int des) : dest_(des), next_(nullptr) {}

};

