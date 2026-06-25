class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int max=0, count;
        for(int i=0; i<nums.size(); i++)
        {
            count=1;
            if(!s.contains(nums[i]-1))
            {
                for(int x=nums[i]+1; s.contains(x); x++)
                ++count;
            }
            if(count>max)
            max=count;
        }
        return max;
    }
};
