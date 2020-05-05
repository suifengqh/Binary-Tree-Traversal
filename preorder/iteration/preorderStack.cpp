#include "../../binary_tree.h"
#include <vector>
#include <stack>

std::vector<int> preorderStack1(TreeNode* root){
        std::vector<int> res;
        if(!root){
                return res;
        }
        std::stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
                while(p){
                        res.push_back(p->val);
                        s.push(p);
                        p = p->left;
                }
                p = s.top();
                s.pop();
                p = p->right;
        }
        return res;
}

std::vector<int> preorderStack2(TreeNode* root){
        std::vector<int> res;
        if(!root){
                return res;
        }
        std::stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
                if(p){
                        res.push_back(p->val);
                        s.push(p);
                        p = p->left;
                }
                else{
                        p = s.top();
                        s.pop();
                        p = p->right;
                }
        }
        return res;
}

std::vector<int> preorderStack3(TreeNode* root){
        std::vector<int> res;
        if(!root){
                return res;
        }
        std::stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
                TreeNode* p = s.top();
                s.pop();
                res.push_back(p->val);
                if(p->right){
                        s.push(p->right);
                }
                if(p->left){
                        s.push(p->left);
                }
        }
        return res;
}