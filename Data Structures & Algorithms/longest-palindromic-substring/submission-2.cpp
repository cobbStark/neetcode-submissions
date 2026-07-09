class Solution {
public:
    string longestPalindrome(string s) {
        string temp;
        string out="";
        for(int i=0; i<s.length(); i++)
        {
            temp=expand(s, i, i);
            if(temp.length()>out.length())
            out=temp;
            temp=expand(s, i, i+1);
            if(temp.length()>out.length())
            out=temp;
        }
        return out;
    }
    string expand(string& s, int x, int y)
    {
        int i=x, j=y;
        while(i>=0 && j<s.length())
        {
            if(s[i]==s[j])
            {
                --i;
                ++j;
            }
            else
            break;
        }
        return s.substr(i+1, j-i-1);
    }
};
