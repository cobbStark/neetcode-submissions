class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> size(n, 1);
        vector<int> parent(n);
        for(int i=0; i<n; i++) parent[i]=i;
        for(int i=0; i<n; i++)
        {
            if(!union_set(parent, size, edges[i][0]-1, edges[i][1]-1))
            return {edges[i][0], edges[i][1]};
        }
        return {};

    }
    int find_parent(vector<int>& parent, int a)
    {
        if(parent[a]==a)
        return a;
        return parent[a]=find_parent(parent, parent[a]);
    }
    bool union_set(vector<int>& parent, vector<int>& size, int a, int b)
    {
        a=find_parent(parent, a);
        b=find_parent(parent, b);
        if(a!=b)
        {
            if(size[a]<size[b])
            {
                parent[a]=b;
                size[b]+=size[a];
            }
            else
            {
                parent[b]=a;
                size[a]+=size[b];
            }
            return true;
        }
        return false;
    }

};
