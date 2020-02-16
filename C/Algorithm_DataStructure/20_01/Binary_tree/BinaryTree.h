/*Write in 2020/1/3
  Basic Binary search tree */
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

//provide definations
struct Treenode;
typedef struct Treenode *tree; //pointer to a tree(root). Do pay attention to recursive defination of tree.
typedef struct Treenode treeNode;
tree newTree(int root);
tree find(int toFind, const tree);
tree findMin(const tree);
tree findMax(const tree);
tree makeEmpty(tree);
tree insert(int toInsert, tree); //Not self-banlanced, suppose no duplicates. return ptr to inserted tree.
tree delTree(int toDel, tree);   //Actually only del the root. Rearrangement will be made to provide access to subtrees.
int retrieve(tree);
void InTraverse(tree); //inorder traverse a tree.

#endif

//provide concrete implementation.
struct Treenode
{
  int element;
  tree left;
  tree right;
};