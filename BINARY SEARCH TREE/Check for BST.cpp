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


    <---------------------METHOD TWO OPTIMISED WITHOUT USING VECTOR------------------------->

     bool solve(Node*root,int min,int max)
    {
        if(root==NULL)
        return true;
         if (root->data<=min ||root->data>=max) return false;
        if(root->data>=min&&root->data<=max)
        {
            bool left=solve(root->left,min,root->data);
            bool right=solve(root->right,root->data,max);
            return left&&right;
        }
        else
        {
            return false;
        }
        
    }
    bool isBST(Node* root) 
    {
        solve(root,INT_MIN,INT_MAX);
    }