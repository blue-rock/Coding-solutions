// Last updated: 11/2/2025, 10:31:23 PM
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int s = nums.size(); //total number of elements
        stack<int> stk; //stack to carry out the operations 
        vector<int>v(s,-1);
        if(s==1)
        {
            return v;
        }
        for(int i=s-2;i>=0;i--)
        {
            if(stk.empty())
            {
                stk.push(nums[i]); //is stack empty just push it
            }
            else
            {
                if(stk.top() <= nums[i])
                {
                    while(!stk.empty() && stk.top() <= nums[i])
                    {
                        stk.pop(); //pop until we get a smaller element
                    }
                    stk.push(nums[i]); //push the current element 
                }
                else
                {
                    stk.push(nums[i]);
                }
                
            }
        } 

        for(int i=s-1;i>=0;i--)
        {
                while(!stk.empty() && stk.top() <= nums[i])
                {
                    stk.pop();
                }
                if(!stk.empty())
                {
                v[i] = stk.top();
                }
                stk.push(nums[i]);
        }
        return v;
    }
};