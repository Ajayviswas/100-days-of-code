vector<int>v;
    int k=1;
    void inorder(Node*root)
    {
    if(root==NULL)
    {
        return;
    }
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
    }
    bool isBST(Node* root) 
    {
        inorder(root);
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i+1]>v[i])
            {
                continue;
            }
            else
            {
                k=0;
                break;
            }
        }
        if(k==1)
        return true;
        else
        return false;
    }