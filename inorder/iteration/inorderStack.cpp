#include "../../binary_tree.h"
#include <vector>
#include <stack>

std::vector<int> inorderStack1<TreeNode* root){
        std::vector<int> res;
        if(!root){
                return res;
        }
        std::stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
                while(p){
                        s.push(p);
                        p = p->left;
                }
                p = s.top();
                s.pop();
                res.push_back(p->val);
                p = p->right;
        }
        return res;
}

std::vector<int> inorderStack1<TreeNode* root){
        std::vector<int> res;
        if(!root){
                return res;
        }
        std::stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
                if(p){
                        s.push(p);
                        p = p->left;
                }
                else{
                        p = s.top();
                        s.pop();
                        res.push_back(p->val);
                        p = p->right;
                }
        }
        return res;
}