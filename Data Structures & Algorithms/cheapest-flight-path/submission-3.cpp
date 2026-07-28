class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
     {
        vector<int> dist(n, INT_MAX/2);
        dist[src]=0;
        for(int i=0; i<k+1; i++)
        {
            vector<int> temp=dist;
            for(int j=0; j<flights.size(); j++)
            {
                if(dist[flights[j][0]]+flights[j][2]<temp[flights[j][1]])
                temp[flights[j][1]]=dist[flights[j][0]]+flights[j][2];
            }
            dist=temp;
        }
        return dist[dst]==INT_MAX/2?-1:dist[dst];
    }
};
