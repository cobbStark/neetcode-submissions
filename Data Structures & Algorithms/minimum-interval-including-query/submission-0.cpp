class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> out;
        for(int i=0; i<queries.size(); i++)
        {
            int min=INT_MAX;
            for(int j=0; j<intervals.size(); j++)
            {
                if(queries[i]>=intervals[j][0]&&queries[i]<=intervals[j][1])
                {
                    if(intervals[j][1]-intervals[j][0]+1<min)
                    min=intervals[j][1]-intervals[j][0]+1;
                }
                
            }
            if(min==INT_MAX)
                min=-1;
                out.push_back(min);
        }
        return out;
    }
};
