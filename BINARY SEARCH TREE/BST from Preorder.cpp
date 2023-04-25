 Node*solve(int &i,int a[],int bound,int n)
    {
        if(i==n||a[i]>bound)
        return NULL;
        Node*root=newNode(a[i++]);
        root->left=solve(i,a,root->data,n);
        root->right=solve(i,a,bound,n);
        return root;
    }
    Node* post_order(int pre[], int n)
    {
        int i=0;
        return solve(i,pre,INT_MAX,n);
    }