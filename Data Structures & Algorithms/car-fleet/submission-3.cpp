class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> cars;
        int n=position.size();
        for(int i=0; i<n; i++)
        cars.push_back({position[i], speed[i]});
        std::sort(cars.begin(), cars.end());
        stack<double> s;
        for(int i=n-1; i>=0; i--)
        {
            double time=((target-cars[i][0])*1.0)/cars[i][1];
            if(s.empty()||time>s.top())
            s.push(time);
        }
        return s.size();

        
    }
};
