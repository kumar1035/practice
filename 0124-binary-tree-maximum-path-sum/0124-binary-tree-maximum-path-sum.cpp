class Solution {
public:
    int solve(TreeNode* root, int* result) {
        if (root == NULL) {
            return 0;
        }

        int left = solve(root->left, result);
        int right = solve(root->right, result);

        // Maximum path sum that can be extended to parent
        int temp = max(left, right) + root->val;

        // A path can also start from the current node
        temp = max(temp, root->val);

        // Maximum path passing through the current node
        int ans = left + right + root->val;

        // Update global maximum
        *result = max(*result, max(temp, ans));

        return temp;
    }

    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;

        solve(root, &result);

        return result;
    }
};