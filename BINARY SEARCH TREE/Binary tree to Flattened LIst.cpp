void flatten(Node *root)
    {
        Node*curr=root;
        while(curr!=NULL)
        {
            if(curr->left)
            {
                Node*pre=curr->left;
                while(pre->right)
                pre=pre->right;
                pre->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }