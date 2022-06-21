class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>um;
        for(auto c: s)
        {
            um[c]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto& it:um)
        {
            pq.push({it.second,it.first});
        }
        string output = "";
        while(pq.size()>1)
        {
            auto top1 = pq.top();
            pq.pop();
            output = output  +top1.second;
            auto top2 = pq.top();
            pq.pop();
            output = output + top2.second;
            if(--top1.first>0)
            {
                pq.push(top1);
            }
            if(--top2.first>0)
            {
                pq.push(top2);
            }
        }
        if(pq.size())
        {
            if(pq.top().first==1)
            {
                output = output + pq.top().second;
            }
            else
            {
                return "";
            }
        }
        return output;
    }
};