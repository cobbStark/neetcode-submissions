using namespace std;
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        if(n==0)
        return false;
        vector<int> temp(3, 0);
        for(int i=0; i<n; i++)
        {
            if(max(temp[0],triplets[i][0])<=target[0]&&max(temp[1],triplets[i][1])<=target[1]&&max(temp[2],triplets[i][2])<=target[2])
            {
                //merge
                temp[0]=max(temp[0], triplets[i][0]);
                temp[1]=max(temp[1], triplets[i][1]);
                temp[2]=max(temp[2], triplets[i][2]);
            }
            if(temp[0]==target[0]&&temp[1]==target[1]&&temp[2]==target[2])
            return true;
        }
        return false;

    }
    
};
