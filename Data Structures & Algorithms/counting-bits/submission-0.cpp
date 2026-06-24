class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> out;
        for(int i=0; i<=n; i++)
        {
            int count=0;
            int x=i;
            while(x>0)
            {
                count+=x&1;
                x=x>>1;
            }
            out.push_back(count);
        }
        return out;
    }
};
