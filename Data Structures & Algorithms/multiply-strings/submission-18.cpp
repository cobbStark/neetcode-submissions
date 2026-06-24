class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length()<num2.length())
        {
            string temp=num1;
            num1=num2;
            num2=temp;
        }
        //int n2=stringToInt(num2);
        string out(2*num1.length(), '0');
        for(int i=num1.length()-1; i>=0; i--)
        {

             string sum="";
            for(int j=num2.length()-1; j>=0; j--)
            {
                unsigned long long prod=(num1[i]-'0')*(num2[j]-'0');
                //sum+=prod*pow(10, num2.length()-1-j);
                string temp=intToString(prod);
                string t(num2.length()-1-j, '0');
                temp=temp+t;
                sum=addString(sum, temp);
                
            }
            string temp=sum;
            //appending ending zeroes
            if(i!=num1.length()-1)
            {
            string t(num1.length()-1-i, '0');
            temp=temp+t;
            }
            out=addString(out, temp);
        }
        //removing leading zeroes
        int i=0;
        while(out[i]=='0')
        {
            ++i;
        }
        out=out.substr(i);
        if(out.length()==0)
        out+="0";
        return out;

    }
    string addString(string a , string b)
    {
        int out_l=max(a.length(), b.length());
        if(a.length()<b.length())
        {
            string temp=a;
            a=b;
            b=temp;
        }
        out_l+=1;
        string out(out_l, '0');
        out_l-=1;
        int carry=0;
        //making length equal
        string t(a.length()-b.length(), '0');
        t=t+b;
        b=t;
        for(int i=a.length()-1; i>=0; i--, out_l--)
        {
            int sum=carry+(a[i]-'0')+(b[i]-'0');
            carry=sum/10;
            out[out_l]=((out[out_l]-'0')+sum%10)+'0';
        }
        if(carry!=0)
        out[out_l]=(out[out_l]-'0')+(carry+'0');
        if(out[0]=='0')
        out=out.substr(1);
        return out;
    }
    int stringToInt(string s)
    {
        int sum=0;
        for(int i=0; i!=s.length(); i++)
        {
            sum=(sum*10)+(s[i]-'0');
        }
        return sum;
    }
    string intToString(unsigned long long x)
    {
        string out="";
        while(x>0)
        {
            out+=(x%10)+'0';
            x/=10;
        }
        string outrev="";
        for(int i=out.length()-1; i>=0; i--)
        {
            outrev+=out[i];
        }
        return outrev;
    }
};
