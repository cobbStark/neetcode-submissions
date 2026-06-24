class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val=nums[0];
        for(auto it=nums.begin()+1; it!=nums.end(); it++)
        val=val^(*it);
        return val;
    }
};
