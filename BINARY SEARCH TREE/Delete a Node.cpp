int minval(Node*root)
{
    Node*curr=root;
    while(curr->left)
    {
        curr=curr->left;
    }
     return curr->data;
}
Node *deleteNode(Node *root, int x) 
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==x)
    {
        // 0 child
        if(root->right==NULL && root->left==NULL)
        {
            delete(root);
            return NULL;
        }
        //left 1 child
        if(root->left && root->right==NULL)
        {
            Node*temp=root->left;
            delete(root);
            return temp;
        }
        //right one child 
        if(root->right && root->left==NULL)
        {
            Node*temp=root->right;
            delete(root);
            return temp;
        }
        //Having 2 child
        if(root->left && root->right)
        {
            int val=minval(root->right);
            root->data=val;
            root->right=deleteNode(root->right,val);
            return  root;
        }
    }
    else if(root->data<x)
    {
        root->right=deleteNode(root->right,x);
        return root;
    }
    else
    {
        root->left=deleteNode(root->left,x);
        return root;
    }
    return root;
}
