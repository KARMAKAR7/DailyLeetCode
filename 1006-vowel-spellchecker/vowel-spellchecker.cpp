class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string>st(wordlist.begin(),wordlist.end());
        unordered_map<string,string>caseS;  // 2nd mapping for casesensative
        unordered_map<string,string>Vowl;   // vowel maching 
         
        auto toLower = [](const string &s){
               string res = s;
               for(auto &c:res) c = tolower(c);
            return res;
         };
        auto devowel = [&](const string& word) {
            string res = toLower(word);
            for (char &c : res) {
                if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                    c = '#';
            }
            return res;
        };

        for (const string& word : wordlist) {
            string lower = toLower(word);
            string vmask = devowel(word);
            if (!caseS.count(lower)) caseS[lower] = word;
            if (!Vowl.count(vmask)) Vowl[vmask] = word;
        }


        vector<string>ans;
        for(auto q : queries){
            if(st.count(q)){  // 1 st case exactly match
                ans.push_back(q);
                continue;
            }

            string lw = toLower(q);  // 2 nd case captilize
            if(caseS.count(lw)){
                ans.push_back(caseS[lw]);
                continue;
            }
            string v = devowel(q);   // 3 rd vowel captilize
            if(Vowl.count(v)){
                ans.push_back(Vowl[v]);
                continue;
            }
            ans.push_back("");   // las6 case dont match any thing empty string
        }
        return ans;
    }
};