class Solution {
public:
    struct TrieNode{
        bool isEndOfWord;
        vector<TrieNode*>children;

        TrieNode(){
            this->isEndOfWord = false;
            this->children = vector<TrieNode*>(27,NULL);
        }
    };

    void insertWord(TrieNode *root,string word){
        TrieNode*crawl = root;
        for(char c:word){
            if(c == '/'){
                if(crawl -> children[26] == NULL){
                    crawl->children[26] = new TrieNode();
                }
                crawl = crawl->children[26];
            }else{
                int index = c - 'a';
                if(crawl -> children[index] == NULL){
                    crawl->children[index] = new TrieNode();
                }
                crawl = crawl -> children[index];
            }
        }
        crawl -> children[26] = new TrieNode();
        crawl = crawl -> children[26];
        crawl->isEndOfWord = true;
    }

    bool checkWord(TrieNode*root , string word){
        TrieNode* crawl = root;
        for(char c : word){
         if(c == '/'){
            if(crawl->children[26] == NULL) return true;
            crawl = crawl -> children[26];
         }else{
            int index = c - 'a';
            if(crawl->isEndOfWord == true){
                return false;
            }
            if(crawl->children[index] == NULL){
                return true;
            }
            crawl = crawl ->children[index];
           }
        } 
       return true;
    }
    void insertAndCheck(TrieNode* root , string word , vector<string>&ans){
        if(checkWord(root,word)){
            insertWord(root,word);
            ans.push_back(word);
        }
    }
    vector<string> removeSubfolders(vector<string>& folder) {
       TrieNode * root = new TrieNode();
       vector<string>ans;
       sort(folder.begin(),folder.end());
        for(string word:folder){
            insertAndCheck(root,word,ans);
        }
       return ans;
    }
};