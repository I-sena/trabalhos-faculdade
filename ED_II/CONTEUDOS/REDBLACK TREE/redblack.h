#ifndef REDBLACK_H
#define REDBLACK_H
#define RED 1
#define BLACK 0

typedef struct no{
    struct no* left;
    struct no* right;
    struct no* parent;
    int color;
    int key;
}TNo;

typedef struct RB{
    TNo* root;
    TNo* Nill;
}redblack;

TNo* CreateNFill(int);
redblack* Create_RB();
void Left_Rotate(redblack*,TNo*);
void Right_Rotate(redblack*,TNo*);
int RB_Insert(redblack*,int);
void RB_Insert_Fixup(redblack*,TNo**);
void Redblack_inorder(TNo*,TNo*);
void Redblack_preorder(TNo*,TNo*);
void Redblack_simetrica(TNo*,TNo*);

#endif