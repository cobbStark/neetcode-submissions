class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int, int> m;
     for(int i=0; i<nums.size(); i++)
     {
        m[nums[i]]=i;
     }
     vector<int> output;
     int a=INT_MAX, b;
     for(int i=0; i<nums.size(); i++)
     {
        int res=target-nums[i];
        auto it=m.find(res);
        if(it!=m.end() && it->second!=i)
        {
            if(i<a)
            {
            a=i;
            b=it->second;
            }
        }
     }
    output.push_back(a);
    output.push_back(b);
    return output;
    }
    
};
