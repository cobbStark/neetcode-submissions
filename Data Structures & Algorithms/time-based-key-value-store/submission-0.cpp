class TimeMap {
    unordered_map<string, unordered_map<string, int>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][value]=timestamp;
    }
    
    string get(string key, int timestamp) {
        int max=0;
        string out;
        for(auto it=m[key].begin(); it!=m[key].end(); it++)
        {
            if(it->second<=timestamp && it->second>max)
            {
            max=it->second;
            out=it->first;
            }
        }
        return out;
    }
};
