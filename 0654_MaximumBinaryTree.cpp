/*
654.最大二叉树
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

Example 1:
输入: [3,2,1,6,0,5]
输入: 返回下面这棵树的根节点：
      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1

作者：syt
日期：2019-01-19
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    static int maxIndex(vector<int>& nums, int l, int r)
    {
        int index = l;
        while(l < r)
        {
            if(nums[index] < nums[l])
                index = l;
            l++;
        }
        return index;
    }
    
    static TreeNode* construct(vector<int>& nums, int l, int r)
    {
        if(l == r)
            return NULL;
        int mIndex = maxIndex(nums, l, r);
        TreeNode* root = new TreeNode(nums[mIndex]);
        root->left = construct(nums, l, mIndex);
        root->right = construct(nums, mIndex + 1, r);
        return root;
                                           
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
};