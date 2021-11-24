/**	@file DiagnosisMain.cpp
	@author Jimin Park
	@date 2019-12-06

	1. Diagnosis of Breast Cancer using Decision Tree Data Mining Technique
		- By create binaryTree, determine diagnosis which is Benign(2) or Malignant(4) 
*/
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BinaryTree.hpp"
#include "WisconsinNode.hpp"


using namespace std;

void readCSVFile(BinaryTree* tree, vector<WisconsinNode*>& attributesV);

/*!	 \fn readCSVFile
	 \return none
	 \param BinaryTree* tree, vector<WisconsinNode*>& attributesV 

	 attributeV - Vector of all the data from wisconsin data.csv */
void readCSVFile(BinaryTree* tree, vector<WisconsinNode*>& attributesV) {

	ifstream ip("wisconsin data.csv");

	if (!ip.is_open()) cout << "Error: File Open" << endl;

	string id;
	string clumpThickness;
	string uniformityOfCellSize;
	string uniformityOfCellShape;
	string marginalAdhesion;
	string singleEpitheialCellSize;
	string bareNuclei;
	string blandChromatin;
	string normalNucleoli;
	string miroses;
	string bOrMClass;

	while (getline(ip, id, ',')) {
		getline(ip, clumpThickness, ',');
		getline(ip, uniformityOfCellSize, ',');
		getline(ip, uniformityOfCellShape, ',');
		getline(ip, marginalAdhesion, ',');
		getline(ip, singleEpitheialCellSize, ',');
		getline(ip, bareNuclei, ',');
		getline(ip, blandChromatin, ',');
		getline(ip, normalNucleoli, ',');
		getline(ip, miroses, ',');
		getline(ip, bOrMClass, '\n');

		WisconsinNode* att = new WisconsinNode(); // wisconsin breast cancer dataset attribute

		if (bareNuclei == "?") { // exception if the value is '?'
			bareNuclei = "1";
		}

		// All the string convert to int
		att->id_ = stoi(id);
		att->clumpThickness_ = stoi(clumpThickness);
		att->uniformityOfCellSize_ = stoi(uniformityOfCellSize);
		att->uniformityOfCellShape_ = stoi(uniformityOfCellShape);
		att->marginalAdhesion_ = stoi(marginalAdhesion);
		att->singleEpitheialCellSize_ = stoi(singleEpitheialCellSize);
		att->bareNuclei_ = stoi(bareNuclei);
		att->blandChromatin_ = stoi(blandChromatin);
		att->normalNucleoli_ = stoi(normalNucleoli);
		att->miroses_ = stoi(miroses);
		att->class_ = stoi(bOrMClass);

		// execute binaryTree to determine diagnosis
		att = tree->generatedTree(att);
		
		// push dataset attribute with diagnosis
		attributesV.push_back(att);
	}

	ip.close();
}

int main() {

#if defined(_DEBUG)
	// gets the state of the debug flags
	int dbgFlags = ::_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	// bitwise or - check block integrity on every memory call
	dbgFlags |= _CRTDBG_CHECK_ALWAYS_DF;
	// don't always remove the blocks on delete
	dbgFlags |= _CRTDBG_DELAY_FREE_MEM_DF;
	// check for memory leaks at process termination
	dbgFlags |= _CRTDBG_LEAK_CHECK_DF;
	// modifies the state of the debug flags
	_CrtSetDbgFlag(dbgFlags);
#endif

	/* Part A */
	vector<WisconsinNode*> attributesV;
	BinaryTree* tree = new BinaryTree();

	readCSVFile(tree, attributesV);
	tree->writeCSVWithDiagnosis(attributesV);

	// A summary of the total amount of patients with malignant and benign tumors 
	// in the format shown below output to console
	int cntMalignant = 0;
	int cntBenign = 0;
	for (auto a : attributesV) {
		if (a->class_ == 2) {
			cntBenign++;
		}
		else if (a->class_ == 4) {
			cntMalignant++;
		}
	}

	cout << "Benign: " << cntBenign << endl;
	cout << "Malignant: " << cntMalignant << endl;
	cout << "Total Patients: " << cntMalignant + cntBenign << endl;

	// Delete all the node to prevent memory leak.



	tree->deleteAllNode(attributesV);

	delete tree;

	_CrtSetDbgFlag(dbgFlags);

	return 0;
}
