class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string path="";
        return backtrack(path, n, out, 0);
    }
    vector<string>& backtrack(string path, int n, vector<string>& out, int closers)
    {
       if(n==0&&closers==0)
       {
        out.push_back(path);
        return out;
       }
       if(n!=0)
       {

        path+='(';
        backtrack(path, n-1, out, closers+1);
        path=path.substr(0, path.length()-1);
       }
       
       if(closers!=0)
       {
        path+=')';
        backtrack(path, n, out, closers-1);
        path=path.substr(0, path.length()-1);
       }
       return out;

    }
};
