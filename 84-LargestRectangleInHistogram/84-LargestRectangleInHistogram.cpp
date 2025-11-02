// Last updated: 11/2/2025, 10:34:40 PM
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
            {
                left[i] = 0;
                s.push(i);
            }
            else
            {
                while(!s.empty() && heights[s.top()]>=heights[i])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    left[i] = 0;
                }
                else
                {
                    left[i] = s.top()+1;
                }
                s.push(i);
            }
        }
        stack<int>s2;
        for(int i=n-1;i>=0;i--)
        {
            if(s2.empty())
            {
                right[i] = n-1;
                s2.push(i);
            }
            else
            {
                while(!s2.empty() && heights[s2.top()]>=heights[i])
                {
                    s2.pop();
                }
                if(s2.empty())
                {
                    right[i] = n-1;
                }
                else
                {
                    right[i] = s2.top()-1;
                }
                s2.push(i);
            }
        }
        int maxarea = 0;
        for(int i=0;i<n;i++)
        {
            maxarea = max(maxarea,heights[i]*(right[i]-left[i] +1));
        }
        return maxarea;
    }
};