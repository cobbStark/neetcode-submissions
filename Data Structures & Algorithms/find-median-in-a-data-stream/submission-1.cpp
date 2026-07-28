class MedianFinder {
    vector<int> arr;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
    }
    
    double findMedian() {
        std::sort(arr.begin(), arr.end());
        int n=arr.size();
        if(n%2==0)
        return (arr[(n/2)-1]+arr[(n/2)])*1.0/2;
        else
        return arr[(n-1)/2];
    }
};
