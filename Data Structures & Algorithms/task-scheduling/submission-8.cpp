class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(int i=0; i<tasks.size(); i++)
        freq[tasks[i]-'A']++;
        int maxFreq=0, count=0;
        for(int i=0; i<26; i++)
        {
            if(freq[i]>maxFreq)
            maxFreq=freq[i];
        }
        for(int i=0; i<26; i++)
        {
            if(freq[i]==maxFreq)
            ++count;
        }
        int x=(maxFreq-1)*(n+1)+(count);
        int gaps=x-maxFreq*count;
        int leftovers=tasks.size()-(maxFreq*count);
        if(leftovers>gaps)
        return x+(leftovers-gaps);
        else
        return x;
    }
};
