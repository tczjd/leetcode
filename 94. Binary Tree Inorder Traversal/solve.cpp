/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //递归方法
class Solution {
public:
    vector<int> resp;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return resp;
        if(root->left)
            inorderTraversal(root->left);
        resp.push_back(root->val);
        if(root->right)
            inorderTraversal(root->right);
        return resp;
    }
};


//非递归方法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> resp;
        stack<TreeNode*> mStack;
        TreeNode* temp = root;
        while(temp || !mStack.empty())
        {
            while(temp)
            {
                mStack.push(temp);
                temp = temp->left;
            }
            
            temp = mStack.top();
            mStack.pop();
            resp.push_back(temp->val);
            temp = temp->right;
        }
        return resp;
    }
};


//非递归方法2 Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        TreeNode *cur, *pre;
        cur = root;
        while(cur)
        {
            if(!cur->left)
            {
                res.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                pre = cur->left;
                while(pre->right && pre->right != cur)
                    pre = pre->right;
                if(!pre->right)
                {
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};