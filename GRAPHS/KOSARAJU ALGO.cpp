void dfs(int node,vector<int>&vis,vector<vector<int>>& adj,stack<int>&s)
	{
	    vis[node]=1;
	    for(auto it : adj[node])
	    {
	        if(!vis[it])
	        {
	             dfs(it,vis,adj,s);
	        }
	    }
	    s.push(node);
	}
	
	void dfs3(int node,vector<int>&vis,vector<int>adjT[])
	{
	    vis[node]=1;
	    for(auto it : adjT[node])
	    {
	        if(!vis[it])
	        {
	             dfs3(it,vis,adjT);
	        }
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>vis(V,0);
        stack<int>s;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,s);
            }
        }
        
        vector<int>adjT[V];
        
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto  it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        
        int scc=0;
        while(!s.empty())
        {
            int node=s.top();
            s.pop();
            if(!vis[node])
            {
                dfs3(node,vis,adjT);
                 scc++;
            }
        }
        
        return scc;
    }