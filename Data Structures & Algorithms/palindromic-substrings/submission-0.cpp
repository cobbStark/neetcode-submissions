class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        for(int i=0; i<s.length(); i++)
        {
            count+=expand(s, i, i);
            count+=expand(s, i, i+1);
        }
        return count;
    }
    int expand(string& s, int x, int y)
    {
        int i=x, j=y;
        int count=0;
        while(i>=0 && j<s.length())
        {
            if(s[i]==s[j])
            {
                ++count;
                --i;
                ++j;
            }
            else
            break;
        }
        return count;
    }

};
