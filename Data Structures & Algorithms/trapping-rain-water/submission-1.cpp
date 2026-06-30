class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size(), 0);
        vector<int> suffix(height.size(), 0);
        prefix[0]=0;
        int n=height.size();
        for(int i=0; i<n-1; i++)
        {
            prefix[i+1]=max(height[i], prefix[i]);
        }
        suffix[n-1]=0;
        for(int i=n-1; i>0; i--)
        {
            suffix[i-1]=max(height[i], suffix[i]);
        }
        int out=0;
        for(int i=0; i<n; i++)
        {
            int temp=min(prefix[i], suffix[i]);
            if(temp-height[i]>0)
            out+=temp-height[i];
        }
        return out;
    }
};
