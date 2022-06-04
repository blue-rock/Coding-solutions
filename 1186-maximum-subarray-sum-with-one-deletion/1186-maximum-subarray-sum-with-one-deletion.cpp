class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int>forward(n);
        vector<int>backward(n);
        int netmax = INT_MIN;
        int bestmax = 0;
        for(int i=0;i<n;i++)
        {
            netmax = max(netmax,arr[i]);
        }
        if(netmax<0)
        {
            return netmax;
        }
        int currmax = 0;
        for(int i=0;i<n;i++)
        {
            currmax = max(arr[i],arr[i] + currmax);
            bestmax = max(bestmax,currmax);
            forward[i] = currmax;
        }
        //backward sum
        currmax = 0;
        for(int i=n-1;i>=0;i--)
        {
            currmax = max(arr[i],arr[i] + currmax);
            bestmax = max(bestmax,currmax);
            backward[i] = currmax; 
        }
        //now find max;
        for(int i=1;i<n-1;i++)
        {
            int sum = forward[i-1] + backward[i+1];
            bestmax = max(bestmax,sum);
        }
        return bestmax;
    }
};