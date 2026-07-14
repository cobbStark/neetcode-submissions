class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int> freq(26, 0);
       int left=0, right=0, max=0;
        while(left<=right && right!=s.length())
        {
            freq[s[right]-'A']++;
            ++right;
            while(left<right && !isValid(freq, k))
            {
                freq[s[left]-'A']--;
                ++left;
            }
            if(right-left>max)
            max=right-left;
        } 
       return max;
    }
    int isValid(vector<int>& freq, int k)
    {
        int count=0, max=0;
        for(int i=0; i<26; i++)
        {
            count+=freq[i];
            if(freq[i]>max)
            max=freq[i];
        }
        count-=max;
        count-=k;
        if(count>0)
        return 0;
        return 1;
    }
};
