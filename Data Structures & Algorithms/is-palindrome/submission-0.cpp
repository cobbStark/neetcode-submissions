class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0; s[i]!='\0'; i++)
        s[i]=tolower(s[i]);
        char *front=&s[0];
        char* end=&s[s.length()-1];
        while(front<end)
        {
            if(!isalnum(*front))
            {
                ++front;
                continue;
            }
            if(!isalnum(*end))
            {
                --end;
                continue;
            }
            if(*front!=*end)
            return false;
            ++front;
            --end;
        }
        return true;
    }
};
