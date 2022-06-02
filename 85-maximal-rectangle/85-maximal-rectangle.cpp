class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>>ma(r,vector<int>(c));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                ma[i][j] = int(matrix[i][j]) - 48;
            }
        }
        int maxinma = INT_MIN;
        vector<int>send(c,0);
        for(auto x: ma)
        {
                for(int i=0;i<c;i++)
                {
                    send[i] = send[i] + x[i];
                    if(x[i]==0)
                    {
                        send[i]=0;
                    }
                }
            int vall = getareabitches(send);
            if(vall>maxinma)
            {
                maxinma = vall;
            }
        }
        return maxinma;
    }
    int getareabitches(vector<int>& heights) {
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