class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root && !root -> left && !root -> right){ 
            return 1;
        }
        if(!root) return 0;
        int left = INT_MAX, right = INT_MAX;

        if(root -> left){
            left = 1 + minDepth(root -> left);
        }
        if(root -> right)
        right = 1 + minDepth(root -> right);

        return min(left , right);
    }
};