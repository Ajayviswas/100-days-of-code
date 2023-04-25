int c=0;
    bool search(Node*root2,int k)
    {
        if(root2==NULL)
        return false;
        Node*temp=root2;
        while(temp!=NULL)
        {
            if(temp->data==k)
            return true;
            else if(temp->data<k)
            temp=temp->right;
            else
            temp=temp->left;
        }
    }
    void solve(Node*root1,int x,Node*root2)
    {
        if(root1==NULL)
        return;
        solve(root1->left,x,root2);
        int k=x-(root1->data);
        if(search(root2,k))
        c++;
        solve(root1->right,x,root2);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        solve(root1,x,root2) ;
        return c;
    }