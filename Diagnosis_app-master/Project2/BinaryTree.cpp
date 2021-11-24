/**	@file BinaryTree.cpp
	@author Jimin Park
	@date 2019-12-06

	Implement for BinaryTree.hpp
*/
#include "BinaryTree.hpp"

/*!	 \fn deleteAllNodes
	 \return none
	 \param WisconsinNode* node, vector<WisconsinNode*>& attributesV

	  Recursive function for delete all the node from binary tree*/
void BinaryTree::deleteAllNodes(WisconsinNode* node, vector<WisconsinNode*>& attributesV) {

	if (node == NULL)
		return;

	if (node->left_ != nullptr)
		deleteAllNodes(node->left_, attributesV);

	if (node->right_ != nullptr)
		deleteAllNodes(node->right_, attributesV);
	
	delete node;
}

/*!	 \fn deleteAllNode
	 \return none
	 \param vector<WisconsinNode*>& attributesV

	  Call from main()*/
void BinaryTree::deleteAllNode(vector<WisconsinNode*>& attributesV) {
	for (size_t i = 0; i < attributesV.size(); i++) {
		deleteAllNodes(attributesV[i], attributesV);
	}
}

/*!	 \fn generatedTree
	 \return none
	 \param WisconsinNode* leaf - node 
	 
	 binary decision tree and generate a report with the added diagnosis 
	 (benign or malignant) determined by the binary decision tree. */
WisconsinNode* BinaryTree::generatedTree(WisconsinNode* leaf)
{
	this->root_ = leaf;
	leaf->root_ = leaf;

	if (leaf->uniformityOfCellSize_ <= 2) {
		WisconsinNode* newNode = new WisconsinNode(leaf);
		leaf->left_ = newNode;
		leaf = leaf->left_;

		if (leaf->bareNuclei_ <= 3) {
			WisconsinNode* newNode1 = new WisconsinNode(leaf);
			leaf->left_ = newNode1;
			leaf = leaf->left_;
			leaf->class_ = 2;
			this->root_->class_ = 2; // assign class_(diagnosis) of root then, return root for push_back to vector in main()
			return this->root_;
		}
		else if (leaf->bareNuclei_ > 3) {
			WisconsinNode* newNode1 = new WisconsinNode(leaf);
			leaf->right_ = newNode1;
			leaf = leaf->right_;
			if (leaf->clumpThickness_ <= 3) {
				WisconsinNode* newNode2 = new WisconsinNode(leaf);
				leaf->left_ = newNode2;
				leaf = leaf->left_;
				leaf->class_ = 2;
				this->root_->class_ = 2;
				return this->root_;
			}
			else if (leaf->clumpThickness_ > 3) {
				WisconsinNode* newNode3 = new WisconsinNode(leaf);
				leaf->right_ = newNode3;
				leaf = leaf->right_;
				if (leaf->blandChromatin_ <= 2) {
					WisconsinNode* newNode4 = new WisconsinNode(leaf);
					leaf->left_ = newNode4;
					leaf = leaf->left_;
					if (leaf->marginalAdhesion_ <= 3) {
						WisconsinNode* newNode5 = new WisconsinNode(leaf);
						leaf->left_ = newNode5;
						leaf = leaf->left_;
						leaf->class_ = 4;
						this->root_->class_ = 4;
						return this->root_;
					}
					else if (leaf->marginalAdhesion_ > 3) {
						WisconsinNode* newNode5 = new WisconsinNode(leaf);
						leaf->right_ = newNode5;
						leaf = leaf->right_;
						leaf->class_ = 2;
						this->root_->class_ = 2;
						return this->root_;
					}
				}
				else if (leaf->blandChromatin_ > 2) {
					WisconsinNode* newNode4 = new WisconsinNode(leaf);
					leaf->right_ = newNode4;
					leaf = leaf->right_;
					leaf->class_ = 4;
					this->root_->class_ = 4;
					return this->root_;
				}
			}
		}
	}
	else if (leaf->uniformityOfCellSize_ > 2){
		WisconsinNode* newNode = new WisconsinNode(leaf);
		leaf->right_ = newNode;
		leaf = leaf->right_;
		
		if (leaf->uniformityOfCellShape_ <= 2) {
			WisconsinNode* newNode1 = new WisconsinNode(leaf);
			leaf->left_ = newNode1;
			leaf = leaf->left_;

			if (leaf->clumpThickness_ <= 5) {
				WisconsinNode* newNode2 = new WisconsinNode(leaf);
				leaf->left_ = newNode2;
				leaf = leaf->left_;
				leaf->class_ = 2;
				this->root_->class_ = 2;
				return this->root_;
			}
			else if (leaf->clumpThickness_ > 5) {
				WisconsinNode* newNode2 = new WisconsinNode(leaf);
				leaf->right_ = newNode2;
				leaf = leaf->right_;
				leaf->class_ = 4;
				this->root_->class_ = 4;
				return this->root_;
			}
		}
		else if (leaf->uniformityOfCellShape_ > 2) {
			WisconsinNode* newNode1 = new WisconsinNode(leaf);
			leaf->right_ = newNode1;
			leaf = leaf->right_;
			if (leaf->uniformityOfCellSize_ <= 4) {
				WisconsinNode* newNode2 = new WisconsinNode(leaf);
				leaf->left_ = newNode2;
				leaf = leaf->left_;
				if (leaf->bareNuclei_ <= 2) {
					WisconsinNode* newNode3 = new WisconsinNode(leaf);
					leaf->left_ = newNode3;
					leaf = leaf->left_;
					if (leaf->marginalAdhesion_ <= 3) {
						WisconsinNode* newNode4 = new WisconsinNode(leaf);
						leaf->left_ = newNode4;
						leaf = leaf->left_;
						leaf->class_ = 2;
						this->root_->class_ = 2;
						return this->root_;
					}
					else if (leaf->marginalAdhesion_ > 3) {
						WisconsinNode* newNode4 = new WisconsinNode(leaf);
						leaf->right_ = newNode4;
						leaf = leaf->right_;
						leaf->class_ = 4;
						this->root_->class_ = 4;
						return this->root_;
					}
				}
				else if (leaf->bareNuclei_ > 2) {
					WisconsinNode* newNode3 = new WisconsinNode(leaf);
					leaf->right_ = newNode3;
					leaf = leaf->right_;
					if (leaf->clumpThickness_ <= 6) {
						WisconsinNode* newNode4 = new WisconsinNode(leaf);
						leaf->left_ = newNode4;
						leaf = leaf->left_;
						if (leaf->uniformityOfCellSize_ <= 3) {
							WisconsinNode* newNode5 = new WisconsinNode(leaf);
							leaf->left_ = newNode5;
							leaf = leaf->left_;
							leaf->class_ = 4;
							this->root_->class_ = 4;
							return this->root_;
						}
						else if (leaf->uniformityOfCellSize_ > 3) {
							WisconsinNode* newNode5 = new WisconsinNode(leaf);
							leaf->right_ = newNode5;
							leaf = leaf->right_;
							if (leaf->marginalAdhesion_ <= 5) {
								WisconsinNode* newNode6 = new WisconsinNode(leaf);
								leaf->left_ = newNode6;
								leaf = leaf->left_;
								leaf->class_ = 2;
								this->root_->class_ = 2;
								return this->root_;
							}
							else if (leaf->marginalAdhesion_ > 5) {
								WisconsinNode* newNode6 = new WisconsinNode(leaf);
								leaf->right_ = newNode6;
								leaf = leaf->right_;
								leaf->class_ = 4;
								this->root_->class_ = 4;
								return this->root_;
							}
						}
					}
					else if (leaf->clumpThickness_ > 6) {
						WisconsinNode* newNode4 = new WisconsinNode(leaf);
						leaf->right_ = newNode4;
						leaf = leaf->right_;
						leaf->class_ = 4;
						this->root_->class_ = 4;
						return this->root_;
					}
				}

			}
			else if (leaf->uniformityOfCellSize_ > 4) {
				WisconsinNode* newNode2 = new WisconsinNode(leaf);
				leaf->right_ = newNode2;
				leaf = leaf->right_;
				leaf->class_ = 4;
				this->root_->class_ = 4;
				return this->root_;
			}
		}
	}

}

/*!	 \fn writeCSVWithDiagnosis
	 \return none
	 \param vector<WisconsinNode*>& attributesV

	 attributeV - Vector of all the data from wisconsin data.csv
	 Write CSV File */
void BinaryTree::writeCSVWithDiagnosis(vector<WisconsinNode*>& attributesV) {
	ofstream op;
	op.open("wisconsin data-results.csv");

	if (!op.is_open()) cout << "Error: File Open" << endl;

	for (auto a : attributesV) {
		op << a->id_ << "," << a->clumpThickness_ << "," << a->uniformityOfCellSize_ << "," << a->uniformityOfCellShape_
			<< "," << a->marginalAdhesion_ << "," << a->singleEpitheialCellSize_ << "," << a->bareNuclei_
			<< "," << a->blandChromatin_ << "," << a->normalNucleoli_ << "," << a->miroses_ << "," << a->class_ << "\n";
	}
	op.close();
}
