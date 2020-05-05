#include "../../binary_tree.h"
#include <vector>

static helper(TreeNode* node, int level, std::vector<std::vector<int>>& a){
        if(!node) return;
        if(level >= res.size()){
                a.resize(a.size()+1);
        }
        a[level].push_back(node->val);
        helper(node->left, level+1, a);
        helper(node->right, level+1, a);
}

std::vector<int> levelorderRecursion(TreeNode* root){
        std::vector<int> res;
        if(!root) return res;
        std::vector<std::vector<int>> a;
        helper(root, 0, a);
        for(int i=0; i<a.size(); ++i){
                for(int j=0; j<a[i].size(); ++j){
                        res.push_back(a[i][j]);
                }
        }
        return res;
}