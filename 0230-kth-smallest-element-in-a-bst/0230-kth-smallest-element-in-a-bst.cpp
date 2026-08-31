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
public:

    int cnt = 0;

    int solve(TreeNode* root, int k){

        if(root == NULL)
            return -1;

        int leftAns = solve(root->left, k);

        if(leftAns != -1)
            return leftAns;

        cnt++;

        if(cnt == k)
            return root->val;

        int rightAns = solve(root->right, k);

        if(rightAns != -1)
            return rightAns;

        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {

        return solve(root, k);
    }
};