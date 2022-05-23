class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxsum = INT_MIN;
        for(int i=0;i<rows;i++)
        {
            vector<int>running(cols);
            for(int j=i;j<rows;j++)
            {
                for(int k=0;k<cols;k++)
                {
                    running[k] = running[k] + matrix[j][k];
                }
                maxsum = max(maxsum,kadanesum(running,k));
            }
        }
        return maxsum;
    }
    // Function to maximum required sum < K
int kadanesum(vector<int>arr, int K)
{
    int N = arr.size();
 
    // Hash to lookup for value (cum_sum - K)
    set<int> cum_set;
    cum_set.insert(0);
 
    int max_sum = INT_MIN, cSum = 0;
 
    for (int i = 0; i < N; i++) {
 
        // getting cumulative sum from [0 to i]
        cSum += arr[i];
 
        // lookup for upperbound
        // of (cSum-K) in hash
        set<int>::iterator sit
            = cum_set.lower_bound(cSum - K);
 
        // check if upper_bound
        // of (cSum-K) exists
        // then update max sum
        if (sit != cum_set.end())
 
            max_sum = max(max_sum, cSum - *sit);
 
        // insert cumulative value in hash
        cum_set.insert(cSum);
    }
 
    // return maximum sum
    // lesser than K
    return max_sum;
}
};