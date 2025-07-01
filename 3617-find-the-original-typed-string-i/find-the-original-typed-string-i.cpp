class Solution {
public:
    int possibleStringCount(string word) {
        int count = 0;
        int i = 1;
        while(i < word.length()){
            if(word[i]==word[i-1]){
                count ++;
            }
            i++;
        }
        return count+1;
    }
};