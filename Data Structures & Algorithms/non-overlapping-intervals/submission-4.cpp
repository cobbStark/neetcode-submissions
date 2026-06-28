class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& i1, const vector<int>& i2){return i1[1]<i2[1];});
        int count=0, j=0;
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[j][1]>intervals[i][0])
            {
            ++count;
            }
            else
            j=i;
        }
        return count;
    }
};
