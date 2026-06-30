class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int max=0;
        int n=heights.size();
        for(int  i=0; i<heights.size(); i++)
        {
            while(!s.empty() && heights[i]<heights[s.top()])
            {
                int h=s.top();
                s.pop();
    
                int w=(s.empty())?i:i-1-s.top();
                int area=heights[h]*w;
                if(area>max)
                max=area;
            }
            s.push(i);
        }
        while(!s.empty())
        {
            int curr=s.top();
            s.pop();
            int w=(s.empty())?n:n-s.top()-1;
            int area=w*heights[curr];
            if(area>max)
            max=area;
        }
        return max;
    }
};
