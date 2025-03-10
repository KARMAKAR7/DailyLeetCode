class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    long countOfSubstrings(string word, int k) {
        int n = word.length();

        unordered_map<char, int> mp;
        int consCnt = 0;

        //Preprocessing to store next consonant indexfor every index i
        vector<int> nextCons(word.size());
        int nextConsonantIndex = word.size();
        for (int idx = word.size() - 1; idx >= 0; idx--) {
            nextCons[idx] = nextConsonantIndex;
            if (!isVowel(word[idx])) {
                nextConsonantIndex = idx;
            }
        }

        int i = 0;
        int j = 0;
        long result = 0;
        while (j < n) {
            char newLetter = word[j];

            if (isVowel(newLetter)) {
                mp[newLetter]++;
            } else {
                consCnt++;
            }


            while (consCnt > k) { //consCnt count must be == k
                char ch = word[i];
                if (isVowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    consCnt--;
                }
                i++;
            }

            while (i < n && mp.size() == 5 && consCnt == k) {
                result += nextCons[j] - j; //Most important part
                char ch = word[i];
                if (isVowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    consCnt--;
                }
                i++;
            }
            j++;
        }

        return result;
    }
};