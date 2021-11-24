/**	@file WisconsinNode.cpp
	@author Jimin Park
	@date 2019-12-06
*/

#pragma once
using namespace std;

class WisconsinNode {
public:
	WisconsinNode* root_ = nullptr;
	WisconsinNode* left_ = nullptr;
	WisconsinNode* right_ = nullptr;

	int id_ = 0;
	int clumpThickness_ = 0;
	int uniformityOfCellSize_ = 0;
	int uniformityOfCellShape_ = 0;
	int marginalAdhesion_ = 0;
	int singleEpitheialCellSize_ = 0;
	int bareNuclei_ = 0;
	int blandChromatin_ = 0;
	int normalNucleoli_ = 0;
	int miroses_ = 0;
	int class_ = 0;

	// Default Constructor
	WisconsinNode() = default;

	// Copy Constructor
	WisconsinNode(WisconsinNode* c) {
		id_ = c->id_;
		clumpThickness_ = c->clumpThickness_;
		uniformityOfCellSize_ = c->uniformityOfCellSize_;
		uniformityOfCellShape_ = c->uniformityOfCellShape_;
		marginalAdhesion_ = c->marginalAdhesion_;
		singleEpitheialCellSize_ = c->singleEpitheialCellSize_;
		bareNuclei_ = c->bareNuclei_;
		blandChromatin_ = c->blandChromatin_;
		normalNucleoli_ = c->normalNucleoli_;
		miroses_ = c->miroses_;
		class_ = c->class_;
	}
};