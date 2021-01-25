//
// Created by Butter on 2020/8/23.
//


#include <iostream>
using namespace std;
#include "BST.h"


typedef struct BSTNode{
    int value;
    BSTNode * left;
    BSTNode * rigth;
    explicit BSTNode(int x):value(x),left(nullptr),rigth(nullptr){}
}BSTNode;


    BSTNode* BST:: _bst_search(BSTNode* subtree,int value){
        if (!subtree){
            return nullptr;
        } else if(subtree->value > value){
            return _bst_search(subtree->left,value);
        }else if(subtree->value < value){
            return _bst_search(subtree->rigth,value);
        }else{
            return subtree;
        }
    }


    bool BST:: get(int value){
        BSTNode* node = _bst_search(root,value);
        if(!node){
            return false;
        }else{
            return node->value;
        }
    }


    BSTNode* BST:: _bst_min_node(BSTNode* subtree){//寻找BST中的最小节点，构造这个功能的目的主要是利用其进行删除操作
        if(!subtree){
            return nullptr;
        }else if(subtree->left){
            return _bst_min_node(subtree->left);
        }else if(!subtree->left){
            return subtree;
        }
        return nullptr;
    }


    int BST:: bst_min(){
        BSTNode* node = _bst_min_node(root);
        if(node){
            return node->value;
        }else{
            printf("树为空");
            return 0;
        }
    }


    BSTNode* BST:: _insert_node(BSTNode* subtree,int value){
        if(!subtree){
            subtree = new BSTNode(value);
        }else{
            if(value < subtree->value){
                subtree->left = _insert_node(subtree->left,value);
            }else if (value>subtree->value){
                subtree ->rigth = _insert_node(subtree->rigth,value);
            }
        }
        return subtree;
    }


    void BST:: add(int value){
        if(!root){
            root = _insert_node(root,value);
        }else{
            _insert_node(root,value);
        }
        size += 1;
    }


    BSTNode* BST:: _bst_remove(BSTNode* subtree,int value){
        BSTNode* temp;
        if(!subtree){
           printf("未找到要删除节点");
        }else if(value > subtree->value){
            subtree->rigth = _bst_remove(subtree->rigth,value);
        }else if(value < subtree->value){
            subtree->left = _bst_remove(subtree->left,value);
        }else{
            if(subtree->left && subtree->rigth){  //存在两个节点
                temp = _bst_min_node(subtree->rigth);   //右子树中找到最大结点
                subtree->value = temp->value;           //替换要删除的结点
                subtree->rigth = _bst_remove(subtree->rigth,subtree->value); //删除右子树中用来替换的结点
            } else{
                temp = subtree;
                if(!subtree->left){
                    subtree = subtree->rigth;
                }else if(!subtree->rigth){
                    subtree = subtree->left;
                }
                delete temp;
            }
        }
        return subtree;
    }


    BSTNode* BST:: remove(int value){
        size -= 1;
        return _bst_remove(root,value);
    }