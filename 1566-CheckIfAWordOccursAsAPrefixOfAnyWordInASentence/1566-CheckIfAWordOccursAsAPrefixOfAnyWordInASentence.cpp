// Last updated: 11/2/2025, 10:28:05 PM
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1;
        for(int i=0;i<sentence.length();i++){
            string curr_word = "";
            while(i<sentence.length() && sentence[i]!=' '){
                curr_word+=sentence[i];
                i++;
            }
            if(curr_word.length()>=searchWord.length()){
                // cout<<curr_word.substr(0, searchWord.length())<<",";
                if(curr_word.substr(0, searchWord.length()) == searchWord){
                    return index;
                }
            }
            index++;
        }
        return -1;
    }
};