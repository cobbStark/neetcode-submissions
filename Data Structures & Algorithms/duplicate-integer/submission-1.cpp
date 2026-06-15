class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      unordered_set<int> s;
      for(int x: nums)
      {
        s.insert(x);
      }  
      if(s.size()!=nums.size())
      return true;

      return false;
    }
};