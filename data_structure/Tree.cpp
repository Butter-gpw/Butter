//
// Created by Butter on 2021/1/25.
//
#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <stack>
struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//树的层序遍历
class binary_tree_traversal {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>  ans;
        vector<int> v;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
        int currentLevelSize = q.size();
        ans.push_back(vector<int>());
            for (int i = 1; i <= currentLevelSize ; ++i) {
                auto node = q.front();q.pop();
                ans.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }

    //先序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node || !s.empty()){
            if(node){
                ans.push_back(node->val);
                s.push(node);
                node = node->left;
            }else{
                node = s.top();
                s.pop();
                node = node->right;
            }
        }
        return ans;
    }

    //中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node || !s.empty()){
            if(node){
                s.push(node);
                node = node->left;
            }else{
                node = s.top();
                ans.push_back(node->val);
                s.pop();
                node = node->right;
            }
        }
        return ans;
    }

    //后序遍历
    static vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* p = root;
        TreeNode* r = nullptr;
        while ( p || !s.empty()){
            if(p){
                s.push(p);
                p = p->left;   //走到最右边
            }else{            //向右
                p = s.top();          //读栈顶结点（非出栈）
                if(p->right && p->right!=r){  //若右子树存在，且未被访问
                    p = p->right;            //转向右
                    s.push(p);               //入栈
                    p = p->left;             //再走到最左
                }else{                       //否则，弹出结点并访问
                    p = s.top();             //将结点弹出
                    s.pop();
                    ans.push_back(p->val);   //访问该结点
                    r = p;                   //记录访问过的结点
                    p = nullptr;             //结束访问后，重置p指针
                }
            }
        }
        return ans;
    }
};