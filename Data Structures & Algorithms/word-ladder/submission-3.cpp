class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> m;
        
        wordList.push_back(beginWord);
        int n=wordList.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                
                if(wordList[j]!=wordList[i]&&valid(wordList[i], wordList[j]))
                {
                m[wordList[i]].push_back(wordList[j]);
                }
                
            }
        }
        if(m.count(endWord)==0)
        return 0;
        if(m[beginWord].size()==0)
        return 0;
        queue<string> q;
        unordered_map<string, vector<int>> visited;
        for(int i=0; i<n; i++)
        visited.insert({wordList[i], {0, 0}});
        q.push(beginWord);
        visited[beginWord][1]=1;
        visited[beginWord][0]=1;
        while(!q.empty())
        {
            string temp=q.front();
            q.pop();
            for(int i=0; i<m[temp].size(); i++)
            {
                if(!visited[m[temp][i]][0])
                {
                    visited[m[temp][i]][0]=1;
                    visited[m[temp][i]][1]=1+visited[temp][1];
                    q.push(m[temp][i]);
                }
            }
        }
        return visited[endWord][1];
    }
    bool valid(string& a, string& b)
    {
        int count=0;
        for(int i=0; i<a.length(); i++)
        {
            if(a[i]!=b[i])
            ++count;
        }
        return count==1;
    }
};
