void inorder(Node*root,vector<int>&v)
{
    if(root==NULL)
    return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
Node*solve(vector<int>&v,int i,int j)
{
    if(i>j)
    return NULL;
    int mid=(i+j)/2;
    Node*TreeNode=new Node(v[mid]);
    TreeNode->left=solve(v,i,mid-1);
    TreeNode->right=solve(v,mid+1,j);
    return TreeNode;
}
Node* buildBalancedTree(Node* root)
{
    vector<int>v;
    inorder(root,v);
    return solve(v,0,v.size()-1);
}