#include "../../binary_tree.h"
#include <vector>

static void helper(TreeNode* node, std::vector<int>& res){
        if(!node) return;
        res.push_back(node->val);
        helper(node->left, res);
        helper(node->right, res);
}

std::vector<int> preorderRecursion(TreeNode* root){
        std::vector<int> res;
        helper(root, res);
        return res;
}