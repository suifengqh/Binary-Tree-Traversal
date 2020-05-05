#include "../../binary_tree.h"
#include <vector>
#include <stack>

std::vector<int> postorderStack1(TreeNode* root){
        std::vector<int> res;
        if(!root) return res;
        std::stack<std::pair<TreeNode*, int>> s;
        s.push({root, 0});
        while(!s.empty()){
                auto t = s.top();
                s.pop();
                if(t.second == 0){
                        s.push({t.first, 1});
                        if(t.first->left){
                                s.push({t.first->left, 0});
                        }
                }
                else if(t.second == 1){
                        s.push({t.first, 2});
                        if(t.first->right){
                                s.push({t.first->right, 0});
                        }
                }
                else{
                        res.push_back(t.first->val);
                }
        }
        return res;
}

std::vector<int> postorderStack2(TreeNode* root){
        std::vector<int> res;
        if(!root) return res;
        std::stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
                while(p){
                        s.push(p);
                        res.insert(res.begin(), p->val);
                        p = p->right;
                }
                p = s.top();
                s.pop();
                p = p->left;
        }
        return res;
}

std::vector<int> postorderStack3(TreeNode* root){
        std::vector<int> res;
        if(!root) return res;
        std::stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
                if(p){
                        s.push(p);
                        res.insert(res.begin(), p->val);
                        p = p->right;
                }
                else{
                        p = s.top();
                        s.pop();
                        p = p->left;
                }
        }
        return res;
}