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
    int minMeetingRooms(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](Interval& i1, Interval& i2){if(i1.end==i2.end) return i1.start<i2.start;return i1.end<i2.end;});
        if(intervals.size()==0)
        return 0;
        vector<stack<Interval>> v;
        stack<Interval> temp;
        temp.push(intervals[0]);
        v.push_back(temp);
        for(int i=1; i<intervals.size(); i++)
        {
            int flag=0;
            for(int j=v.size()-1; j>=0; j--)
            {
            if(!conflict(v[j].top(),intervals[i] ))
            {
                v[j].push(intervals[i]);
                flag=1;
                break;
            }
            }
            if(flag==0)
            {
                stack<Interval> t;
                t.push(intervals[i]);
                v.push_back(t);
            }
            
        }
        return v.size();
    }
    bool conflict(Interval& i1, Interval& i2)
    {
        if(i1.end>i2.start)
        return true;

        return false;
    }
};

