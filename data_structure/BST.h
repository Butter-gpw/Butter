//
// Created by Butter on 2020/8/24.
//

#ifndef ADT_BST_H
#define ADT_BST_H
struct BSTNode;

class BST{
public:
    int size= 0;
    BSTNode* root=nullptr;
    BSTNode* _bst_search(BSTNode* subtree,int value);
    bool get(int value);
    BSTNode* _bst_min_node(BSTNode* subtree);
    int bst_min();
    BSTNode* _insert_node(BSTNode* subtree,int value);
    void add(int value);
    BSTNode* _bst_remove(BSTNode* subtree,int value);
    BSTNode* remove(int value);
};

#endif //ADT_BST_H
