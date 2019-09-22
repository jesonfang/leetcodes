/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int u = 0, v = 0;
    
    if (root == NULL){
        return 0;
    }
    
    u = maxDepth(root->left);
    v = maxDepth(root->right);
    
    return (u > v ? (u+1) : (v+1));
}
