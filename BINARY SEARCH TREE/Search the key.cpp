bool search(Node* root, int x) {
    while(root!=NULL)
    {
        if(root->data==x)
        return true;
        else if(root->data<x)
        root=root->right;
        else
        root=root->left;
    }
    return false;
}