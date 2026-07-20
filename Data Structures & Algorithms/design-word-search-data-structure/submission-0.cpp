typedef struct Node
{
    Node* child[26]={};
    bool isEnd=false;
}Node;
class WordDictionary {
    Node* root=nullptr;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* temp=root;
        for(int c: word)
        {
            int i=c-'a';
            if(temp->child[i]==nullptr) temp->child[i]=new Node();
            temp=temp->child[i];
        }
        temp->isEnd=true;
    }
    
    bool search(string word) {
        Node* temp=root;
        return dfs(temp, word, 0);
    }
    bool dfs(Node* temp, string& word, int k)
    {
        for(int i=k; i<word.length(); i++)
        {
            char c=word[i];
            if(c=='.')
            {
                for(int j=0; j<26; j++)
                {
                    if(temp->child[j]!=nullptr && dfs(temp->child[j], word,  i+1))
                    return true;
                }
                return false;
            }
            else if(temp->child[c-'a']==nullptr) 
            return false;
            else
            temp=temp->child[c-'a'];
        }
        return temp->isEnd;

    }
};
