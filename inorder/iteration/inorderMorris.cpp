#include "../../binary_tree.h"
#include <vector>

std::vector<int> inorderMorris(TreeNode* root){
        std::vector<int> res;
        if(!root) return res;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while(cur){
                if(cur->left == NULL){
                        res.push_back(cur->val);
                        cur = cur->right;
                }
                else{
                        pre = cur->left;
                        while(pre->right != NULL && pre->right != cur){
                                pre = pre->right;
                        }
                        if(pre->right == NULL){
                                pre->right = cur;
                                cur = cur->left;
                        }
                        else{
                                pre->right = NULL;
                                res.push_back(cur->val);
                                cur = cur->right;
                        }
                }
        }
        return res;
}