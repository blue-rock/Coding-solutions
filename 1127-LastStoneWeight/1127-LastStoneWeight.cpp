// Last updated: 11/2/2025, 10:29:02 PM
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        if(pq.size()==1){
            return pq.top();
        }
        while(!pq.empty()){
            int first_stone = pq.top();
            pq.pop();
            int second_stone = pq.top();
            pq.pop();
            int remaining_stone = 0;
            if(second_stone > first_stone){
                remaining_stone = second_stone - first_stone;
            }
            else if(second_stone<first_stone){
                remaining_stone = first_stone - second_stone;
            }
            if(pq.empty()){
                return remaining_stone;
            }
            else{
                pq.push(remaining_stone);
            }
        }
        return 0;
    }
};