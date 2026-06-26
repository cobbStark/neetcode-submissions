class Solution {
public:

    string encode(vector<string>& strs) {
            string s;
            for(int i=0; i<strs.size(); i++)
            {
                s+=strs[i];
                s+="#@!";
            }
            return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string temp;
        for(int i=0; i!=s.length(); i++)
        {
            if(s.substr(i, 3)=="#@!")
            {
                strs.push_back(temp);
                temp="";
                i+=2;
            }
            else
            {
                temp+=s[i];
            }
        }
        return strs;
    }
};
