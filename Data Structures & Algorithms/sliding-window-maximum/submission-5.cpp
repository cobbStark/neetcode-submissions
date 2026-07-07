class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
int n=nums.size();
        priority_queue<int> maxHeap;
        vector<int> exists(n, 0);
        for(int i=0; i<k; i++)
        {
        maxHeap.push(nums[i]);
        exists[i]=1;
        }
        vector<int> out;
        out.push_back(maxHeap.top());
        for(int i=k; i<n; i++)
        {
            for(int x=0; x<=i-k; x++)
            {
                if(!maxHeap.empty() && maxHeap.top()==nums[i-k-x] && exists[i-k-x]==1)
                {
                maxHeap.pop();
                exists[i-k-x]=0;
                }
            }
            
            maxHeap.push(nums[i]);
            exists[i]=1;
            out.push_back(maxHeap.top());
        }
        return out;
    }
};
