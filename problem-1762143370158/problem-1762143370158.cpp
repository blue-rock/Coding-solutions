// Last updated: 11/3/2025, 9:46:10 AM
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars;
        for(int i=0;i<n;i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater<pair<int,int>>());
        stack<double>st;
        for(auto &car:cars){
            int pos = car.first;
            int spid = car.second;
            double time = ((target-pos)*1.0)/(spid*1.0);

            if(st.empty() || time>st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};