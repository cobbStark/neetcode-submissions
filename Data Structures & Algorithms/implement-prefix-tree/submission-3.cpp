typedef struct Node
{
    Node* child[26]={};
    bool isEnd=false;
}Node;
class PrefixTree {  
    Node* root=nullptr;
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        if(root==nullptr)
        root=new Node();
        Node* temp=root;
        for(int i=0; i<word.length(); i++)
        {
            if(temp->child[word[i]-'a']==nullptr)temp->child[word[i]-'a']=new Node();
            temp=temp->child[word[i]-'a'];
        }
        temp->isEnd=true;
        
    }
    
    bool search(string word) {
        if(root==nullptr) return false;
        Node* temp=root;
        for(char c: word)
        {
            if(temp->child[c-'a']!=nullptr)
            temp=temp->child[c-'a'];
            else
            return false;
        }
        return temp->isEnd;
    }
    

    bool startsWith(string prefix) {
        if(root==nullptr) return false;
        Node* temp=root;
        for(char c: prefix)
        {
            if(temp->child[c-'a']==nullptr)
            return false;
            else 
            temp=temp->child[c-'a'];
        }
        return true;
    }
};
