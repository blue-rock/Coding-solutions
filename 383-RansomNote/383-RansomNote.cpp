// Last updated: 1/28/2026, 12:42:06 AM
1class Solution {
2public:
3    bool canConstruct(string ransomNote, string magazine) {
4        map<char,int> mp;
5        for(int i=0;i<magazine.length();i++){
6            mp[magazine[i]]++;
7        }
8        for(int i=0;i<ransomNote.length();i++){
9            if(mp.find(ransomNote[i])!=mp.end() && mp[ransomNote[i]]>0){
10            mp[ransomNote[i]]--;
11            }
12            else{
13                return false;
14            }
15        }
16        return true;
17    }
18};