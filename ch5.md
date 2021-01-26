# ch5
##### 1. For the binary tree of Figure 1, list the leaf nodes,the nonleaf nodes, and the level of each node.
the leaf nodes : A,B,C
nonleaf nodes : E,D
the level of each node:
A->1
B->2
C,D->3
E->4
##### 2. Write out the inorder, preorder, and level-order traversals for the binary tree of Figure 2
inorder(LVR) :
(a) E->D->C->B->A
(b) H->D->I->B->E->A->F->C->G

preorder(VLR) :
(a) A->B->C->D->E
(b) A->B->D->H->I->E->C->F->G

postorder(LRV) :
(a) E->D->C->B->A
(b) H->I->D->E->B->F->G->C->A

level-order :
(a) A->B->C->D->E
(b) A->B->C->D->E->F->G->H->I

##### 4.Suppose that we have the following key values:7, 16, 49, 82, 5, 31, 6, 2, 44.
(a) Write out the max heap after each value is insert into the heap.
```
          82
       /     \
      49      31
     /  \    /  \
    44   5  16   6
    / \
   2  7
```
(b) Write out the min heap after each value is insert into the heap.
```
          2
       /     \
       5      6
     /  \    /  \
    7   16  49   31
    / \
   82  44
```
##### 5.Write a C function that searches for an arbitrary element in a max heap . What is the computing time of your function?
```c
int searchHeap(int x)
{
  int i;
  for (i=1; i<=n; i++)
    if (heap[i].key == x) return i;
  return 0;
}
``` 
time complexity: O(n)
##### 6.Define the inverse transformation of the one that creats the associated binary tree from a forest. Are these transformations unique?
NO

##### 7.Prove that the preorder traversal of a forest and the preorder traversal of its associated binary tree give the same result.
The correspondence between the PreOrder traversal of a binary tree and its equivalent forest representation is fairly obvious if we look at the linked list representation of the tree.  For example, assume that we have the following binary tree:

                               A
                             /   \
                            B     C
                          /  \   /  \
                         D    E F    G
The linked representation of this tree would be: (A(B(D,E)C(F,G)).  This would produce the following forest of trees:

                A                 D                 F
               / \                |                 |
              B   C               E                 G

               T0                 T1                T2 


The PreOrder traversal of the binary tree produces the sequence: ABDECFG.  Notice that this corresponds to the list representation.  For the forest, we follow A (Node), B (left child),  Tree T1, C (right child), and Tree T2.
##### 8.Prove that every binary tree is unique defined by its preorder and inorder sequences.
½Ò¥»5-79