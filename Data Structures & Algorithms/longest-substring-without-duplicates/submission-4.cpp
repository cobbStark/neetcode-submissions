class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> t;
        int length=0;
        int k=0;
        int max=0;
        for(int i=0; s[i]!='\0'; i++)
        {

            t.insert(s[i]);
            ++k;
            if(t.size()!=k||i==s.length()-1)
            {
                length=t.size();
                t.clear();
                if(length>max)
                max=length;
                k=0;
                if(i!=s.length()-1)
                i=i-length;
            }
        }
        return max;
    }
};
