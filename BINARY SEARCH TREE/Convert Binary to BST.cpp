void inorder(Node*root,vector<int>&v)
    {
        if(root==NULL)
        return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    void solve(Node*root,vector<int>v,int &i)
    {
        //int i=0;
        if(root==NULL)
        {
            return;
        }
        solve(root->left,v,i);
        root->data=v[i];
        i++;
        solve(root->right,v,i);
    }
    Node *binaryTreeToBST (Node *root)
    {
        int i=0;
         vector<int>v;
        inorder(root,v);
        sort(v.begin(),v.end());
        solve(root,v,i);
        return root;
    }