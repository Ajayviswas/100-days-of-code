class Solution {
     public:

 TreeNode*solve(vector<int>&v,int start ,int end)
    {
        if(start>end)
        return NULL;
        int mid=(end+start)/2;
        TreeNode*root=new TreeNode(v[mid]);
        root->left=solve(v,start,mid-1);
        root->right=solve(v,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& v) 
    {
        return solve(v,0,v.size()-1);
    }
 };