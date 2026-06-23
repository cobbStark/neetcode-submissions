class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                set<char> s(board[i].begin(), board[i].end());
                if(s.size()-1!=countNum(board[i]))
                return false;
            }
        }
        for(int i=0; i<9; i++)
        {
            set<char> s;
            int count=9;
            for(int j=0; j<9; j++)
            {
                s.insert(board[j][i]);
                if(board[j][i]=='.')
                --count;
            }
            if(s.size()-1!=count)
            return false;
        }
            for(int k=0; k<9; k++)
            {
                int i, j;
                if(k<3)
                i=0;
                else if(k>5)
                i=6;
                else
                i=3;

                if(k==0||k==3||k==6)
                j=0;
                else if(k==1||k==4||k==7)
                j=3;
                else
                j=6;
                set<char> s;
                int count=9;
                for(int x=0; x<3;x++)
                {
                    for(int y=0; y<3; y++)
                    {
                        s.insert(board[x+i][y+j]);
                        if(board[x+i][y+j]=='.')
                        --count;
                    }
                }
                if(s.size()-1!=count)
                return false;
            }
            return true;
        }
    
    int countNum(vector<char> a)
    {
        int count=a.size();
        for(auto it=a.begin(); it!=a.end(); it++)
        {
            if(*it=='.')
            --count;
        }
        return count;
    }
};
