/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isIdentical(TreeNode* p, TreeNode* q) {
        if(p==nullptr || q==nullptr){
            return p==q;
        }
        return isIdentical(p->left,q->left) && isIdentical(p->right,q->right) && (p->val==q->val);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if(subRoot==nullptr){
        //     return true;
        // }
        if(!root){
            return false;
        }
        if(isIdentical(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot); 
    }
};