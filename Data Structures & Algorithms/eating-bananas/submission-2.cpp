class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int x)
    {
        int time=0;
        for(int i=0; i<piles.size(); i++)
        {
        time+=piles[i]/x;
        if(piles[i]%x!=0)
        ++time;
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=0, mid;
        
        for(int& x: piles)
        high=std::max(high, x);
        int val=high;
        while(low<high)
        {
            mid=low+((high-low)/2);
            if(isPossible(piles, h, mid))
            {
                val=mid;
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return val;
    }
};
