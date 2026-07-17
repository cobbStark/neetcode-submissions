class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<vector<int>> neighbours(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++)
        {
            neighbours[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            order.push_back(x);
            for(int y: neighbours[x])
            {
                inDegree[y]--;
                if(inDegree[y]==0)
                q.push(y);
            }
        }
        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i]!=0)
            return {};
        }
        return order;
    }
};
