#pragma once
//자료형의 정의
typedef int BTData;

struct BTreeNode {
	BTData data;
	struct BTreeNode* left;
	struct BTreeNode* right;
};

BTreeNode* MakeBTreeNode(void);
void DeleteBTreeNode(BTreeNode* bt);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);
void MakeSubTree(BTreeNode* main[]);

void PreorderTraverse(BTreeNode* bt);
void InorderTraverse(BTreeNode* bt);
void PostorderTraverse(BTreeNode* bt);
