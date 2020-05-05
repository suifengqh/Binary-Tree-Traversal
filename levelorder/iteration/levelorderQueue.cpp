#include "../../binary_tree.h"
#include <vector>
#include <queue>

std::vector<int> levelorderQueue(TreeNode* root){
        std::vector<int> res;
        if(!root) return res;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
                int n = q.size();
                for(int i=0; i<n; ++i){
                        TreeNode* t = q.front();
                        q.pop();
                        res.push_back(t->val);
                        if(t->left) q.push(t->left);
                        if(t->right) q.push(t->right);
                }
        }
        return res;
}