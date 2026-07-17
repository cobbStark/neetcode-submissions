class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);
        int count=0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                ++count;
           queue<int> q;
           q.push(i);
           while(!q.empty())
           {
            int x=q.front();
            visited[x]=1;
            q.pop();
            for(int y: adj[x])
            {
                if(!visited[y])
                q.push(y);
            }
           }
            }
        }
        return count;
    }
};
