class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto it=nums.begin();
        set<vector<int>> output;
        for(; it!=nums.end(); it++)
        {
            if (it > nums.begin() && *it == *(it - 1)) continue;
            auto start=it+1;
            auto end=nums.end()-1;
            while(start<end)
            {
            int sum=*it+*start+*end;
            if(sum==0)
            {
               output.insert({*it, *start, *end });
               ++start;
            }
            else if(sum<0)
            ++start;
            else
            --end;
            }
        }
        vector<vector<int>> out(output.begin(), output.end());
        return out;
    }
};
