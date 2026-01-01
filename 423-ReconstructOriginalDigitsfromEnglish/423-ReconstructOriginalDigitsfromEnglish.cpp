// Last updated: 1/1/2026, 7:44:48 PM
1class Solution {
2public:
3    string originalDigits(string s) 
4    {
5        vector<char> ans;
6        unordered_map<char,int> mp;
7        for(int i=0;i<s.length();i++){
8            mp[s[i]]++;
9        }
10
11        while(mp['z'])
12        {
13            ans.push_back('0');
14            mp['z']--;
15            mp['e']--;
16            mp['r']--;
17            mp['o']--;
18        }
19        while(mp['w']) 
20        {
21            ans.push_back('2');
22            mp['t']--;
23            mp['w']--;
24            mp['o']--;
25        }
26        
27        while(mp['x'])
28        {
29            ans.push_back('6');
30            mp['s']--;
31            mp['i']--;
32            mp['x']--;
33        }
34        while(mp['g'])
35        {
36            ans.push_back('8');
37            mp['e']--;
38            mp['i']--;
39            mp['g']--;
40            mp['h']--;
41            mp['t']--;
42        }
43
44        while(mp['t'])
45        {
46            ans.push_back('3');
47            mp['t']--;
48            mp['h']--;
49            mp['r']--;
50            mp['e']-=2;
51        }
52        while(mp['r'])
53        {
54            ans.push_back('4');
55            mp['f']--;
56            mp['o']--;
57            mp['u']--;
58            mp['r']--;
59        }
60        
61        while(mp['f'])
62        {
63            ans.push_back('5');
64            mp['f']--;
65            mp['i']--;
66            mp['v']--;
67            mp['e']--;
68        }
69        while(mp['v'])
70        {
71            ans.push_back('7');
72            mp['s']--;
73            mp['e']-=2;
74            mp['v']--;
75            mp['n']--;
76        }
77        while(mp['o'])
78        {
79            ans.push_back('1');
80            mp['o']--;
81            mp['n']--;
82            mp['e']--;
83        }
84        while(mp['i'])
85        {
86            ans.push_back('9');
87            mp['n']-=2;
88            mp['i']--;
89            mp['e']--;
90        }
91
92        sort(ans.begin(),ans.end());
93        string answer="";
94        for(char ch : ans)
95        {
96            answer+=ch;
97        }
98        return answer;
99    }
100};
101
102// zero
103// one
104// two
105// three
106// four
107// five
108// six
109// seven
110// eight
111// nine
112
113// no. of z represents 0
114// w - represents 2
115// u - represents 4
116// x - represents 6
117// g represents 8
118