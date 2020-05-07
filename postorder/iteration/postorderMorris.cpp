#include "../../binary_tree.h"
#include <vector>
#include <cstdlib>

void reverse(TreeNode* from, TreeNode* to){
	if(from == to) return;
	TreeNode* x = from;
	TreeNode* y = from->right;
	TreeNode* z = NULL;
	while(x != to){
		z = y->right;
		y->right = x;
		x = y;
		y = z;
	}
}

void outReverse(TreeNode* from, TreeNode* to, std::vector<int>& res){
	reverse(from, to);
	TreeNode* p = to;
	while(true){
		res.push_back(p->val);
		if(p == from){
			break;
		}
		p = p->right;
	}
	reverse(to, from);
}

std::vector<int> postorderMorris(TreeNode* root){
        std::vector<int> res;
        if(!root) return res;
	TreeNode* dummy = new TreeNode(-1);
	dummy->left = root;
	TreeNode* cur = dummy;
	TreeNode* pre = NULL;
	while(cur){
		if(cur->left == NULL){
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
				outReverse(cur->left, pre, res);
				pre->right = NULL;
				cur = cur->right;
			}
		}
	}
	return res;
}