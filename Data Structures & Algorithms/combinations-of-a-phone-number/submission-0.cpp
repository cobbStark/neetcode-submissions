class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> out;
        string path="";
        vector<vector<char>> letters(8, vector<char>(3, 0));
        char ch='a';
        for(int i=0; i<8; i++)
        {
        for(int j=0; j<3; j++)
        {
            letters[i][j]=ch++;
        }
        if(i+2==7 || i+2==9)
        letters[i].push_back(ch++);
        }
        if(digits.length()==0)
        return out;
        return backtrack(path, 0, digits, letters, out);
    }
    vector<string>& backtrack(string path, int i, string digits, vector<vector<char>>& letters, vector<string>& out)
    {
        if(i==digits.length())
        {
            out.push_back(path);
            return out;
        }
        for(int j=0; j<letters[((digits[i]-'0')-2)].size(); j++)
        {
            path+=letters[(digits[i]-'0')-2][j];
            backtrack(path, i+1, digits, letters, out);
            path=path.substr(0, path.length()-1);
        }
        return out;
    }
};
