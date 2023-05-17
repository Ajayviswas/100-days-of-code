<-----------------------CLONE A GRAPH---------------------------->

 unordered_map<Node*,Node*>m;
    void dfs(Node*clone,Node*node)
    {
        for(Node* n : node->neighbors)
        {
            if(m.find(n)==m.end())
            {
                Node * clonenode=new Node(n->val);
                m[n]=clonenode;
                clone->neighbors.push_back(m[n]);
                dfs(clonenode,n);
            }
            else
            {
                 clone->neighbors.push_back(m[n]);
            }
        }
    }
    Node* cloneGraph(Node* node)
    {
        if(node==NULL)
        return NULL;
        m.clear();
        Node*clone=new Node(node->val);
        m[node]=clone;
        dfs(clone,node);
        return clone;
    }   