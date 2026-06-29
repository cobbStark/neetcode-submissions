class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for(int i=0; i<nums.size(); i++)
        {
            heap.push(nums[i]);
        }
        for(int i=0; i<k-1; i++)
        {
            heap.pop();
        }
        return heap.top();
    }
};
