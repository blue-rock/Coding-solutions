class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size()<=1)
        {
            if(target[0]!=1)
            {
                return false;
            }
            return true;
        }
        priority_queue<int>pq(target.begin(),target.end());
        long long total = 0;
        for(auto x:target)
        {
            total = total + x;
        }
        while(pq.top()!=1)
        {
            int curr = pq.top();
            pq.pop();
            total = total - curr;
            if(total<0 || total>=curr)
            {
                return false;
            }
            curr = curr%total;
            if(curr==0 && total!=1)
            {
                return false;
            }
            total = total + curr;
            pq.push(curr);
        }
        return true;
    }
};