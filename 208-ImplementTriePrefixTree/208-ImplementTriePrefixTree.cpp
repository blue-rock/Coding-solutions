// Last updated: 11/2/2025, 10:33:04 PM
class TrieNode
{
  public:
    vector<TrieNode*>child;
    bool isEnd;
    TrieNode(){
        isEnd = false;
        child.resize(26,nullptr);
    }
};
class Trie {
public:

        TrieNode* root;
        Trie()
        {
            root = new TrieNode();
        }
    void insert(string s) {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++)
        {
            if(node->child[s[i]-'a']==nullptr)
            {
                node->child[s[i]-'a'] = new TrieNode();
            }
            node = node->child[s[i]-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string s) {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++)
        {
            if(node->child[s[i]-'a']==nullptr)
            {
                return false;
            }
            node = node->child[s[i]-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string s) {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++)
        {
            if(node->child[s[i]-'a']==nullptr)
            {
                return false;
            }
            node = node->child[s[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */