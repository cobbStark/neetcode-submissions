class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];});
        if(intervals.size()==0||intervals.size()==1)
        return intervals;
        vector<vector<int>> out;
        out.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i][0]<=out.back()[1])
            {
                out.back()[0]=std::min(out.back()[0], intervals[i][0]);
                out.back()[1]=std::max(out.back()[1], intervals[i][1]);
            }
            else
            out.push_back(intervals[i]);
        }
        return out;
    }
};
