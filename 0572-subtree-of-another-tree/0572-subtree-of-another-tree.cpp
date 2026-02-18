/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    
    // Step 1: Serialize tree using preorder
    void serialize(TreeNode* root, string &s) {
        if (!root) {
            s += "#,";          // null marker
            return;
        }
        
        s += "," + to_string(root->val);  // add delimiter
        serialize(root->left, s);
        serialize(root->right, s);
    }
    
    // Step 2: Build LPS array for KMP
    vector<int> buildLPS(const string &pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        
        int len = 0;   // length of previous longest prefix suffix
        int i = 1;
        
        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } 
            else {
                if (len != 0) {
                    len = lps[len - 1];
                } 
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
    
    // Step 3: KMP search
    bool KMP(const string &text, const string &pattern) {
        vector<int> lps = buildLPS(pattern);
        
        int i = 0; // index for text
        int j = 0; // index for pattern
        
        while (i < text.size()) {
            
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            
            if (j == pattern.size()) {
                return true;   // pattern found
            }
            else if (i < text.size() && text[i] != pattern[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        
        return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1, s2;
        
        serialize(root, s1);
        serialize(subRoot, s2);
        
        return KMP(s1, s2);
    }
};
