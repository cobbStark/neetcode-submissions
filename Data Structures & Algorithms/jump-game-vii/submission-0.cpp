class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<int> reachable(s.length(), 0);
        reachable[0]=1;
        for(int i=0; i<s.length(); i++)
        {
            if(reachable[i]==1)
            {
            for(int x=minJump; x<=maxJump; x++)
            {

                if(i+x<s.length() && s[i+x]=='0')
                reachable[i+x]=1;
            }
            }
        }
        return reachable[s.length()-1]==1;
    }
};