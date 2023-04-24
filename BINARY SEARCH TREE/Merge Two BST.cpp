vector<int>v,v1,v2,ans;
    void  solve(Node*root,vector<int>&v)
    {
        if(root==NULL)
        return;
        solve(root->left,v);
        v.push_back(root->data);
        solve(root->right,v);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        if(root1==NULL&&root2==NULL)
        return {};
       solve(root1,v1);
       solve(root2,v2);
       int i=0,j=0;
       while(i<v1.size()&&j<v2.size())
       {
           if(v1[i]<v2[j])
           {
               ans.push_back(v1[i++]);
           }
           else
           {
               ans.push_back(v2[j++]);
           }
       }
       while(i<v1.size())
       {
           ans.push_back(v1[i++]);
       }
       while(j<v2.size())
       {
           ans.push_back(v2[j++]);
       }
       return ans;
    }