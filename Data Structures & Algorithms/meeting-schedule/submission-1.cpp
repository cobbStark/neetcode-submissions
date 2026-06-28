/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==0)
        return true;
        std::sort(intervals.begin(), intervals.end(), [](Interval& i1, Interval& i2){return i1.end<i2.end;});
        for(int i=0; i<intervals.size()-1; i++)
        {
            if(intervals[i+1].start<intervals[i].end)
            return false;
        }
        return true;
    }
};
