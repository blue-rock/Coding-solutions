// Last updated: 11/5/2025, 11:20:09 PM
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        const int n = nums.size();
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first == b.first ? a.second > b.second : a.first > b.first;
        };
        unordered_map<int,int> freq;
        set<pair<int,int>, decltype(cmp)> topX(cmp), small(cmp);
        long long topsum = 0;

        auto promote = [&]() {
            if (topX.size() < x && !small.empty()) {
                auto it = small.begin();
                topsum += 1LL * it->first * it->second;
                topX.insert(*it);
                small.erase(it);
            }
        };

        auto demote = [&]() {
            if (topX.size() > x) {
                auto it = prev(topX.end());
                topsum -= 1LL * it->first * it->second;
                small.insert(*it);
                topX.erase(it);
            }
        };

        auto add = [&](int num) {
            int oldf = freq[num];
            if (oldf) {
                auto it = topX.find({oldf, num});
                if (it != topX.end()) {
                    topX.erase(it);
                    topsum -= 1LL * oldf * num;
                } 
                else small.erase(small.find({oldf, num}));
            }
            int newf = ++freq[num];
            topX.insert({newf, num});
            topsum += 1LL * newf * num;
            demote();
        };

        auto remove = [&](int num) {
            int oldf = freq[num];
            auto it = topX.find({oldf, num});
            if (it != topX.end()) {
                topX.erase(it);
                topsum -= 1LL * oldf * num;
            } 
            else small.erase(small.find({oldf, num}));
            int newf = --freq[num];
            if (!newf) freq.erase(num);
            else small.insert({newf, num});
            promote();
        };

        vector<long long> res(n - k + 1 , 0);
        for (int i = 0; i < k; ++i) add(nums[i]);
        res[0] = topsum;
        for (int i = k; i < n; ++i) {
            remove(nums[i - k]);
            add(nums[i]);
            res[i - k + 1] = topsum;
        }
        return res;
    }
};