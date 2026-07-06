class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int sum=nums[0];
            int max=sum;
            for(int i=1; i<nums.size(); i++)
            {
                if(sum<0)
                sum=0;
                sum+=nums[i];
                
                if(sum>max)
                max=sum;
            }
            return max;
    }
};
