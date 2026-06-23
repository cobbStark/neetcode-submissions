class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto it=tokens.begin(); it!=tokens.end(); it++)
        {
            if(*it=="+")
            {
                int sum=s.top();
                s.pop();
                sum+=s.top();
                s.pop();
                s.push(sum);
            }
            else if(*it=="-")
            {
                int a=s.top();
                s.pop();
                int sum=s.top();
                sum-=a;
                s.pop();
                s.push(sum);
            }
            else if(*it=="*")
            {
                int sum=s.top();
                s.pop();
                sum*=s.top();
                s.pop();
                s.push(sum);
            }
            else if(*it=="/")
            {
                int a=s.top();
                s.pop();
                int sum=s.top();
                sum/=a;
                s.pop();
                s.push(sum);
            }
            else
            s.push(stoi(*it));
        }
        return s.top();
    }
    
};
