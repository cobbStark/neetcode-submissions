class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::sort(hand.begin(), hand.end());
        int n=hand.size();
        if(n%groupSize!=0)
        return false;
        n/=groupSize;
        vector<stack<int>> a(n);
        for(int i=0; i<hand.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                if(a[j].empty()||(hand[i]-a[j].top()==1&& a[j].size()<groupSize))
                {
                cout<<j<<":"<<hand[i];
                a[j].push(hand[i]);
                break;
                }
            }
        }
        for(int i=0; i<n; i++)
        if(a[i].size()!=groupSize)
        return false;

        return true;
    }
};
