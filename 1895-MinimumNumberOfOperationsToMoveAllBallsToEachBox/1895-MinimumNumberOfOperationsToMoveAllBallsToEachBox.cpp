// Last updated: 11/2/2025, 10:27:31 PM
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>arr;
        int sum = 0;
        for(int i=0;i<boxes.size();i++){
            sum = 0;
            for(int a=0;a<i;a++){
                if(boxes[a]=='1'){
                    sum = sum + abs(a-i);
                }
                
            }
            for(int b=i+1;b<boxes.size();b++)
            {
                if(boxes[b]=='1')
                {
                    sum = sum + abs(b-i);
                    
                }
            }
            arr.push_back(sum);
            
        }
        return arr;
    }
};