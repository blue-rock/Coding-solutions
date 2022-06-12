class Solution {
public:
    string minWindow(string s, string t) {
    string result;
    if(s.empty() || t.empty()){
        return result;
    }
    unordered_map<char, int> map;
    unordered_map<char, int> window;
    for(int i = 0; i < t.length(); i++){
        map[t[i]]++;
    }
    int minLength = INT_MAX;
    int letterCounter = 0;
    
    for(int left = 0, right = 0; right < s.length(); right++){
        char c = s[right];
        if(map.find(c) != map.end()){
            window[c]++;
            if(window[c] <= map[c]){
                letterCounter++;
            }
        }
        if(letterCounter >= t.length()){
            while (map.find(s[left]) == map.end() || window[s[left]] > map[s[left]])
            {
                window[s[left]]--;
                left++;
            }
            if(right-left + 1 < minLength){
                minLength = right - left + 1;
                result = s.substr(left, minLength);
            }
        }
    }
    return result;
}
};