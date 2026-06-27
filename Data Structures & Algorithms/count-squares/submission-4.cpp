class CountSquares {
public:
int x, y;
    map<vector<int> , int> points;
    CountSquares(int x=0, int y=0) {
        this->x=x;
        this->y=y;
    };
    
    void add(vector<int> point) {
        points[point]++;
    }
    
    int count(vector<int> point) {
        int c=0;
        for(const auto& [key, value] : points)
        {
            if(key[0]==point[0]||key[1]==point[1])
            continue;
            //int val1=0, val2=0;
            //if(points.contains({key[0], point[1]}))
            int val1=points[{key[0], point[1]}];
            //if(points.contains({key[1], point[0]}))
            int val2=points[{point[0], key[1]}];
            c+=val1*val2*value;
        
        }
        return c;

    }
};
