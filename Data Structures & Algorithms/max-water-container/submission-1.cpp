class Solution {
public:

    int getArea(int w, int h1, int h2)
    {
        int h=(h1<h2)?h1:h2;
        return h*w;
    }
    int maxArea(vector<int>& heights) {
        int max=0, area;
        auto start=heights.begin();
        auto end=heights.end()-1;
        while(start<end)
        {
         area=getArea(end-start, *start, *end);
         if(area>max)
         max=area;
         if(*(start)<*(end))
         ++start;
         else
         --end;
        }
        return max;
    }
};
