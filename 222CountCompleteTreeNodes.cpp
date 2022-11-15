#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth = findDepth(root);
        if (depth == 1) {
            return 1;
        }
        TreeNode* p = root;
        int subDepth = depth -1;
        int leaseLevelNodeNum = 0;
        int half = 1<<(depth-2);
        while(p) {
            if (isExistNode(p->left,subDepth)) {
                leaseLevelNodeNum += half;
                p = p->right;
            } else {
                p = p->left;
            }
            half >>= 1;
            --subDepth;
        }
        return leaseLevelNodeNum + (1<<(depth-1))-1;
    }
    
    int findDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return findDepth(node->left)+1;
    }
    
    bool isExistNode(TreeNode* node, int length) {
        if (length == 0 && node) {
            return true;
        }
        if (!node) {
            return false;
        }
        return isExistNode(node->right, length-1);
    }
};