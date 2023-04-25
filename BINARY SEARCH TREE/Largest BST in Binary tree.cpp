    class info{
        public:
        int minval;
        int maxval;
        int size;
        bool isbst;
    };
    info solve(Node*root,int&count)
    {
        if(root==0)
        {
            return {INT_MAX,INT_MIN,0,true};
        }
        info left=solve(root->left,count);
        info right=solve(root->right,count);
        info currentnode;
        currentnode.size=left.size+right.size+1;
        currentnode.minval=min(root->data,left.minval);
        currentnode.maxval=max(root->data,right.maxval);
        
        if(left.isbst&&right.isbst&&root->data>left.maxval&&root->data<right.minval)
        {
            currentnode.isbst=true;
        }
        else
        {
            currentnode.isbst=false;
        }
        if(currentnode.isbst)
        {
            count=max(count,currentnode.size);
        }
        return currentnode;
    }
    int largestBst(Node *root)
    {
    	int count=0;
    	solve(root,count);
    	return count;
    }