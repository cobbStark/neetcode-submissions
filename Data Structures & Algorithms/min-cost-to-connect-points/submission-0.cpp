class Solution {
public:
    int find(int a, vector<int>& parent)
    {
        if(parent[a]==a)
        return a;
        return parent[a]=find(parent[a], parent);
    }
    bool unite(int a, int b, vector<int>& parent, vector<int>& size)
    {
        a=find(a, parent);
        b=find(b, parent);
        if(a==b)
        return false;
        if(size[a]<size[b])
        {
            parent[a]=b;
            size[b]+=a;
        }
        else
        {
            parent[b]=a;
            size[a]+=b;
        }
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> parent(n);
        for(int i=0; i<n; i++)
        parent[i]=i;
        vector<int> size(n, 1);
        int out=0;
        int x=points[0][0], y=points[0][1];
        priority_queue<vector<int>, vector<vector<int>>, std::greater<vector<int>>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                    int x1=points[i][0], y1=points[i][1], x2=points[j][0], y2=points[j][1];
                    int dist=abs(x1-x2)+abs(y1-y2);
                    q.push({dist, i, j});
            }
        }
        while(!q.empty())
        {
            int p1=q.top()[1], p2=q.top()[2], dist=q.top()[0];
            q.pop();
            if(unite(p1, p2, parent, size))
            out+=dist;
        }
        return out;
    }
};
