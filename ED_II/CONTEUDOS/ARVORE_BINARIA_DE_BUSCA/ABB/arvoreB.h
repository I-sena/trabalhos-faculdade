#ifndef ARVOREB_H
#define ARVOREB_H

typedef struct tree Btree;
Tno* Create_No(int);
Btree* Create_Tree();
Tno* Tree_Search(Tno*,int);
Tno* Iterative_tree_search(Tno*,int);
Tno* Tree_Mininum(Tno*);
Tno* Tree_Maximum(Tno*);
Tno* Tree_Successor(Tno*);
int Tree_insert(Btree*,Tno*);
void Transplant(Btree*,Tno*,Tno*);
void Tree_Delete(Btree*,Tno*);
#endif