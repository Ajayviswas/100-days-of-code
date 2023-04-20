Node* LCA(Node *root, int n1, int n2)
{
    while(root!=NULL)
    {
        if(n1<root->data&&n2<root->data)
        {
            root=root->left;
        }
        else if(n1>root->data&&n2>root->data)
        {
            root=root->right;
        }
        else
        {
            break;
        }
    }
    return root;
}

