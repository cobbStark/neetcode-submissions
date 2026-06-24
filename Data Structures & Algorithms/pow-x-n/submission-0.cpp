class Solution {
public:
    double myPow(double x, int n) {

        if(n>0)
        {
        if(n==1)
        return x;

        return x*myPow(x, n-1);
        }
        else
        {
            if(n==-1)
            return 1/x;

            return myPow(x, n+1)/x;
        }
    }
};
