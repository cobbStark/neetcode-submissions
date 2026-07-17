class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n==1)
        {
            if(edges.size()==0)
            return true;
            else
            return false;
        }
        
        vector<vector<int>> neighbours(n);
        vector<int> count(n, 0);
        for(int i=0; i<edges.size(); i++)
        {
            neighbours[edges[i][0]].push_back(edges[i][1]);
            neighbours[edges[i][1]].push_back(edges[i][0]);
            count[edges[i][0]]++;
            count[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(count[i]==0)
            return false;
            if(count[i]==1)
            q.push(i);
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int t: neighbours[x])
            {
                count[t]--;
                count[x]--;
                if(count[t]==1)
                q.push(t);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(count[i]>1)
            return false;
        }
        
        queue<int> q1;
        vector<int> visited(n, 0);
        q1.push(0);
        while(!q1.empty())
        {
            int x=q1.front();
            visited[x]=1;
            q1.pop();
            for(int i=0; i<neighbours[x].size(); i++)
            {
                if(!visited[neighbours[x][i]])
                q1.push(neighbours[x][i]);
            }
        }
        for(int i=0; i<n; i++)
        if(!visited[i])
        return false;
        return true;
    }
};
