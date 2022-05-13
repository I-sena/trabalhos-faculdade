#ifndef BT_H
#define BT_H

typedef struct no{
  int key;
  struct no *left;
  struct no *right;
  struct no *p;
}TNo;

typedef struct{
  TNo* root;
}BinTree;

BinTree* BinTree_create();
TNo* TNo_createNFill(int);
_Bool BinTree_insert_Right(TNo**, TNo*);
_Bool BinTree_insert_Left(TNo**, TNo*);
_Bool BinTree_insert_r(TNo**,TNo*,int*,int);
void BinTree_preorder(TNo*);
void BinTree_inorder(TNo*);

#endif