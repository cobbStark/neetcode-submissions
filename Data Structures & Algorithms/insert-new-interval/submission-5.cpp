class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       int start=0;
       vector<vector<int>> out;
       if(intervals.size()==0)
       {
        out.push_back(newInterval);
        return out;
       }
       while(start!=intervals.size()&&newInterval[0]>intervals[start][1])++start;
        
       for(int i=0; i<start; i++)
       out.push_back(intervals[i]);
       out.push_back(newInterval);
       for(int i=start; i<intervals.size(); i++)
       {
            if(intervals[i][0]<=out.back()[1]||intervals[i][1]<=out.back()[1])
            {
            out.back()[1]=std::max(intervals[i][1], out.back()[1]);
            out.back()[0]=std::min(intervals[i][0], out.back()[0]);
            }
            else
            out.push_back(intervals[i]);
       }
       return out;
       
    }
};
