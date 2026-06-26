class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int l=s1.length();
        if(l>s2.length())
        return false;
        int left=0, right=l;
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        
        for(int i=0; i<s1.length(); i++)
        {
            count1[s1[i]-'a']++;
            count2[s2[i]-'a']++;
        }
        
            if(count1==count2)
            return true;  
        while(right!=s2.length())
        {
          

            count2[s2[left]-'a']--;
            count2[s2[right]-'a']++;
            ++left;
            ++right;
            if(count1==count2)
            return true;  
        }
        return false;


    }
};
