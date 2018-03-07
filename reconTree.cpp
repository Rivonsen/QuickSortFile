/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0)
            return NULL;
        TreeNode* head=new TreeNode(pre[0]);
        int preZeroPos=0;
        for(int j=0;j<pre.size();j++)
        {
            if(pre[0]==vin[j])
            {
                preZeroPos=j;
            }
        }
        vector<int> left_pre,left_vin,right_pre,right_vin;
        for(int i=0;i<preZeroPos;i++)
        {
            left_vin.push_back(vin[i]);
            left_pre.push_back(pre[i+1]);
        }
        for(int i=preZeroPos+1;i<pre.size();i++)
        {
            right_vin.push_back(vin[i]);
            right_pre.push_back(pre[i]);
        }
        head->left=reConstructBinaryTree(left_pre,left_vin);
        head->right=reConstructBinaryTree(right_pre,right_vin);
        return head;
    }
}