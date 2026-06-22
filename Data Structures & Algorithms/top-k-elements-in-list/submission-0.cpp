class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>> heap;
        for(const auto& p: m)
        {
            heap.push({p.second, p.first});
        }
        vector<int> out;
        for(int i=0; i<k; i++)
        {
            out.push_back(heap.top().second);
            heap.pop();
        }
        return out;
        
        

    }
};
