class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<vector<pair<int, int>>> adj(n+1);
      for(int i=0; i<times.size(); i++)
      {
        adj[times[i][0]].push_back({times[i][1], times[i][2]});
      }  
      vector<int> dist(n+1, INT_MAX/2);
      dist[k]=0;
      priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> minh;
      minh.push({0, k});
      while(!minh.empty())
      {
        auto [d, u]=minh.top();
        minh.pop();
        if(d>dist[u])
        continue;
        for(auto& [v, w]: adj[u])
        {
            if(w+dist[u]<dist[v])
            {
                dist[v]=w+dist[u];
                minh.push({dist[v], v});
            }
        }
      }
      int max=-1;
      for(int i=1; i<=n; i++)
      max=std::max(max, dist[i]);
      if(max==INT_MAX/2)
      return -1;
      return max;

    }
};
