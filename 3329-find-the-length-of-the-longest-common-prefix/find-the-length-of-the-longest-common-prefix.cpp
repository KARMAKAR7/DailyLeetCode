class TrieNode{
    public:
    TrieNode *child[10];
    TrieNode(){
        for(int i = 0 ; i < 10 ; i++){
            child[i] = NULL;
        }
    }
};

class Trie{
     public:
       TrieNode *root;

        Trie(){
            root = new TrieNode();
        }
      void insert(int num){
            TrieNode *node = root;
            string str = to_string(num);
            
            for(char d:str){
                 int ind = d -'0';
                 if(node->child[ind] == NULL){
                    node->child[ind] = new TrieNode();
                 }
                 node = node->child[ind];
            }
      }
      int findLength(int num){
        TrieNode *node = root;
            string str = to_string(num);
            int len = 0;
            for(char d:str){
                 int ind = d -'0';
                 if(node->child[ind]){
                    len++;
                    node = node->child[ind];
                 }
                 else{
                    break;
                 }
                 
            }
            return len;
      }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for(int num:arr1){
            trie.insert(num);
        }
        int ans = 0;
        for(int num:arr2){
           int len = trie.findLength(num);
           ans = max(ans,len); 
        }
        return ans;
    }
};