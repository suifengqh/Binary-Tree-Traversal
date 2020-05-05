#include "../../binary_tree.h"
#include <vector>

static void helper(TreeNode* node, std::vector<int>& res){
        if(!node) return;
        helper(node->left, res);
        helper(node->right, res);
        res.push_back(node->val);
}

std::vector<int> postorderRecursion(TreeNode* root){
        std::vector<int> res;
        helper(root, res);
        return res;
}