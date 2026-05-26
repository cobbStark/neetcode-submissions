class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        int l=s.length();
        for(int i=0; i<l; i++)
        {
            t.push(s[i]);   
                if(t.top()==')')
                {
                    t.pop();
                    if(t.empty())
                    return false;

                    if(t.top()!='(')
                    return false;
                    t.pop();
                }
                else if(t.top()=='}')
                {
                    t.pop();
                    if(t.empty())
                    return false;

                    if(t.top()!='{')
                    return false;
                    t.pop();
                }
                else if(t.top()==']')
                {
                    t.pop();
                    if(t.empty())
                    return false;

                    if(t.top()!='[')
                    return false;
                    t.pop();
                }
            
        }
        if(!t.empty())
        return false;
        else
        return true;
    }
};
