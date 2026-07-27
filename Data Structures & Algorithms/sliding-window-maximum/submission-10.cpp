class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<vector<int>> q;
        int n=nums.size();
        for(int i=0; i<k; i++)
        {
            if(q.empty()||nums[i]>q.front()[0])
            q.push_front({nums[i], i});
            else
            {
                while(!q.empty()&&nums[i]>q.back()[0])
                q.pop_back();
            q.push_back({nums[i], i});
            }
        }
        vector<int> out;
        out.push_back(q.front()[0]);
        for(int i=k; i<n; i++)
        {
            while(!q.empty()&&(q.front()[1]<=i-k))
            q.pop_front();
             while(!q.empty()&&(q.back()[1]<=i-k))
            q.pop_back();
            if(q.empty()||nums[i]>q.front()[0])
            q.push_front({nums[i], i});
            else
            {
            while(!q.empty() && nums[i]>q.back()[0])
            q.pop_back();
            q.push_back({nums[i], i});
            }
            out.push_back(q.front()[0]);
        }
        return out;

    }
};
