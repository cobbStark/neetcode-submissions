class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto front=numbers.begin();
        auto end=numbers.end()-1;
        vector<int> output;
        while(front<end)
        {
            if(*front+*end==target)
            {
             output.push_back(front-numbers.begin()+1);
             output.push_back(end-numbers.begin()+1); 
             return output;  
            }
            if(*front+*end<target)
            {
                ++front;
            }
            else
            {
                --end;
            }
        }
        output.push_back(-1);
        output.push_back(-1);
        return output;
    }
};
