class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        return 0;
        int mn=nums[0], mx=nums[0], out=nums[0];
        for(int i=1; i<n; i++)
        {
            cout<<mx<<" "<<mn<<endl;
            int t=mx;
            mx=std::max(nums[i], std::max(nums[i]*mn, nums[i]*mx));
            mn=std::min(nums[i], std::min(nums[i]*mn, nums[i]*t));
            out=std::max(mx, out);
        }
        return out;
    }
};
