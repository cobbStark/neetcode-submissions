class Solution {
public:
    int reverse(int x) {
        int temp=x;
        int num=0;
        int flag=0;
        if(temp<0)
        {
            temp=-temp;
            flag=1;
        }
        while(temp>0)
        {
            if(num>INT_MAX/10)
            return 0;
            num=(num*10)+(temp%10);
            temp/=10;
        }
        if(flag==1)
        num=-num;
        return num;
    }
};
