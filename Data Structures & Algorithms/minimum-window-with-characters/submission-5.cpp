class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length())
        return "";
        unordered_set<char> u;
        for(char& ch: t)
        u.insert(ch);
        int i=0;
        while(!u.contains(s[i])&&i<s.length()-1)++i;
        int j=s.length()-1;
        while(!u.contains(s[j])&&j>0)--j;
        if(i>j || i>=s.length() || j<0)
        return "";
        s=s.substr(i, (j-i)+1);
        
        vector<int> freqt(200, 0);
        for(int i=0; i<t.length(); i++)
        freqt[t[i]-'A']++;
        for(int l=t.length(); l<=s.length(); l++)
        {
            string slider=s.substr(0, l);
            vector<int> freq2(200, 0);
            for(int i=0; i<slider.length(); i++)
            freq2[slider[i]-'A']++;
            if(vecEqual(freq2, freqt))
            return slider;
            for(int i=l; i<s.length(); i++)
            {
                slider+=s[i];
                slider=slider.substr(1);
                freq2[s[i]-'A']++;
                freq2[s[i-l]-'A']--;
                if(vecEqual(freq2, freqt))
                return slider;
            }
        }
        
        return "";
    }
    bool vecEqual(vector<int>& a, vector<int>& b)
    {
        for(int i=0; i<200; i++)
        if(a[i]<b[i])
        return false;

        return true;
    }
};
