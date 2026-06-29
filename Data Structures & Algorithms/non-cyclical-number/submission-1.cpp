class Solution {
public:
    bool isHappy(int n) {
        while(n!=1)
        {
            int temp=n;
            int n1=n;
            n=0;
            while(n1>0)
            {
                n+=(n1%10)*(n1%10);
                n1/=10;
            }
            if(n<10 )
            {
                if(n==1)
                return true;
                else
            return false;
            }
            
        }
        return true;
    }
};
