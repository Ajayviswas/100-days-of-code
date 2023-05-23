public:
    int numIslands(vector<vector<char>>&v)
    {
        int c=0;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                if(v[i][j]=='1')
                {
                    solve(v,i,j);
                    c++;
                }
            }
        }
        return c;
    }
    void solve(vector<vector<char>>&v,int i,int j)
    {
        if(i<0||j<0||i>=v.size()||j>=v[0].size()||v[i][j]=='0')
        {
            return;
        }
             v[i][j]='0';
            solve(v,i+1,j);
            solve(v,i-1,j);
            solve(v,i,j+1);
            solve(v,i,j-1);
        
    }
};