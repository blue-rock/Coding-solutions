// Last updated: 2/3/2026, 10:57:56 PM
1class Solution {
2public:
3    bool isTrionic(vector<int>& nums) {
4        int n = nums.size();
5        if (n < 3) return false;
6
7        int foundp = 0;
8        int foundq = 0;
9        int foundn = 0;
10
11        for (int i = 0; i < n - 1; i++) {
12            if (foundq == 0 && foundn == 0 && nums[i] < nums[i + 1]) {
13                foundp = 1;
14            }
15            else if (foundp == 1 && foundn == 0 && nums[i] > nums[i + 1]) {
16                foundq = 1;
17            }
18            else if (foundp == 1 && foundq == 1 && nums[i] < nums[i + 1]) {
19                foundn = 1;
20            }
21            else {
22                return false;
23            }
24        }
25
26        return foundp == 1 && foundq == 1 && foundn == 1;
27    }
28};
29