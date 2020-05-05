#include "../../binary_tree.h"
#include <vector>

static void helper(TreeNode* node, std::vector<int>& res){
        if(!node) return;
        helper(node->left, res);
        res.push_back(node->val);
        helper(node->right, res);
}

std::vector<int> inorderRecursion(TreeNode* root){
        std::vector<int> res;
        helper(root, res);
        return res;
}