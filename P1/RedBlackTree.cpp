// Created by HOME on 2022-05-20.
// referenced blog
// https://blog.naver.com/PostView.nhn?blogId=leeinje66&logNo=221945641530&parentCategoryNo=&categoryNo=26&viewDate=&isShowPopularPosts=false&from=postView

#include <iostream>
#include <string>
using namespace std;


namespace Color
{
    const enum NODE_COLOR : bool { BLACK = false, RED = true };
}

class Node
{
private:
    int key;
    bool color;
    Node* parent, * left, * right;
    friend class RedBlackTree;

public:
    explicit Node(const int& paramKey = NULL, const bool paramColor = Color::BLACK, Node* paramParent = nullptr, Node* paramLeft = nullptr, Node* paramRight = nullptr)
    : key(paramKey), color(paramColor), parent(paramParent), left(paramLeft), right(paramRight) {}
};

class RedBlackTree
{
private:
    int numOfElement;
    Node* nil; // dummyHead

private:
    Node* getGrandNode(Node* cur);
    Node* getUncleNode(Node* cur);
    void leftRotate(Node* cur);
    void RightRotate(Node* cur);
    void insertFix(Node* cur);
    void insertNode(Node* root, const int& data);
    void preOrderTraverse(Node* root, string* stringBuilder, string padding, const string& pointer, const bool hasRightChild) const;
    string showTree(Node* root) const;

public:
    explicit RedBlackTree() : numOfElement(0), nil(new Node(-1, Color::BLACK)) {
        nil->left = nil->right = nil->parent = nil;
    }
    void insertNode(const int& data) { insertNode(nil, data); }
    string showTree() const { return showTree(nil->right); }
};

Node* RedBlackTree::getGrandNode(Node *cur)
{
    if (cur == nullptr || cur->parent == nullptr) return nullptr;
    return cur->parent->parent;
}

Node* RedBlackTree::getUncleNode(Node *cur)
{
    Node* tempGrand(getGrandNode(cur));
    if (tempGrand == nullptr) return nullptr;

    if (cur->parent == tempGrand->left) return tempGrand->right;
    else return tempGrand->left;
}

// 트리 회전
void RedBlackTree::leftRotate(Node *cur)
{
    Node* temp = cur->right;
    cur->right = temp
}










