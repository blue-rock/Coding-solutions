class Solution {
    public:
    double findMedianSortedArrays(vector<int>a, vector<int>b) {
        if(a.size() > b.size()) return findMedianSortedArrays(b,a);
        int n = a.size(), m = b.size(),j=0;
        int lo = 0, hi = n, realmid = (n+m+1)/2;
        while(lo <= hi)
        {
            int cut1 = (lo+hi)/2;
            int cut2 = realmid-cut1;
            int l1 = cut1 == 0 ? INT_MIN : a[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : b[cut2-1];
            int r1 = cut1 == n ? INT_MAX : a[cut1];
            int r2 = cut2 == m ? INT_MAX : b[cut2];
            if(l1 <= r2 and l2 <= r1)
            {
                if((n+m)%2 == 0)
                return (max(l1,l2) + min(r1,r2))/2.0;
                else return max(l1,l2);
            }
            if(l1 < r2) lo = cut1+1;
            else hi = cut1-1;
        }
        return 0.0;

    }
};

