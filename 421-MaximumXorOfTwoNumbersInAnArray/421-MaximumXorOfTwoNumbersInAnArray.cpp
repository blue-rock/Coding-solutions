// Last updated: 11/2/2025, 10:31:50 PM
struct Node{
    Node* links[2];
};
class Trie{
    public:
    Node* root = new Node();
    Trie(){
        root = new Node();
    }
void insert(int num)
{
    Node* node = root;
    for(auto i=31;i>=0;i--)
    {
        int bit = (num>>i)&1;
        if(node->links[bit]==NULL)
        {
            Node* temp = new Node();
            node->links[bit] = temp;
        }
        node = node->links[bit];
    }
}
int maxxor(int num)
{
    Node* node = root;
    int ans = 0;
    for(auto i=31;i>=0;i--)
    {
        int bit = (num>>i)&1;
        if(node->links[!bit]!=NULL)
        {
            ans = ans | (1<<i);
            node = node->links[!bit];
        }
        else
        {
            node = node->links[bit];
        }
    }
    return ans;
}
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int res = 0;
        for(auto i:nums)
        {
            trie.insert(i);
        }
        for(auto i:nums)
        {
            res = max(res,trie.maxxor(i));
        }
        return res;
    }
};