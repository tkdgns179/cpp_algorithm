//
// Created by HOME on 2022-05-21.
//
#include <stdlib.h>

typedef struct tagRBTNode {
    struct tagRBTNode* Left;
    struct tagRBTNode* Right;
    struct tagRBTNode* Parent;

    enum {RED, BLACK} Color;
    int data;
}RBTNode;



extern RBTNode* Nil;

void RBT_RotateRight(RBTNode** Root, RBTNode* Parent) {
    RBTNode* LeftChild = Parent->Left;
    Parent->Left = LeftChild->Right;

    if (LeftChild->Right != Nil)
        LeftChild->Right->Parent = Parent;

    LeftChild->Parent = Parent->Parent;

    if (Parent->Parent == NULL) {
        (*Root) = LeftChild;
    }
    else {
        if (Parent == Parent->Parent->Left) {
            Parent->Parent->Left = LeftChild;
        }
        else {
            Parent->Parent->Right = LeftChild;
        }
    }
}









