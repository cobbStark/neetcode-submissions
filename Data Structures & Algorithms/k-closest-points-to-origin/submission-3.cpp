class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<float>, vector<vector<float>>, std::greater<vector<float>>> minHeap;
        for(int i=0; i<points.size(); i++)
        {
            vector<float> temp;
            temp.push_back((std::sqrt(pow(points[i][0], 2)+pow(points[i][1], 2))));
            temp.push_back(i);
            minHeap.push(temp);
        }
        vector<vector<int>> output;
        for(int i=0; i<k; i++)
        {
            output.push_back(points[(minHeap.top())[1]]);
            minHeap.pop();
        }
        return output;
    }
};
