class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& vec) {
        if (!root)
            return;

        inOrder(root->left, vec);   // L
        vec.push_back(root->val);   // V
        inOrder(root->right, vec);  // R
    }

    TreeNode* construct(int l, int r, vector<int>& vec) {
        if (l > r)
            return NULL;

        int mid = l + (r - l) / 2;

        TreeNode* root = new TreeNode(vec[mid]);

        root->left = construct(l, mid - 1, vec);
        root->right = construct(mid + 1, r, vec);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;

        inOrder(root, vec);

        int l = 0;
        int r = vec.size() - 1;

        return construct(l, r, vec);
    }
};