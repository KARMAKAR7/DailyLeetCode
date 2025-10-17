class Solution {
public:
    /*Obserbations and Thiking Process ---->
      
      1.we can change at most one opeartion
      operation is to change at most one char in s

    2.then we have to find longest prefix at most k unique char in it 
    and then we delete it
    
    3. opertaions count will be the number of deletion we perfrom on this string 

    //obserbations 
         we can try to change the one char to any char 
         to a to z (total 26 char)

         // also we need to track total unique charpcters on that string 
         so we maintain the conditiom of at most k unique char 


         // so we have to try all possiblites for all the indexs on that string
         
         // we can use recursion to solve this
         // for memorization we can use a trick using bitmasking 

    */
    unordered_map<string,int>dp;
    int solve(int ind , string &s,int k,int uniqueCount,bool change){
        if(ind >= s.size()){
            return 0;
        }
        string state = to_string(ind) + " " + to_string(uniqueCount) + " " + to_string(change);
        if(dp.count(state)){
            return dp[state];
        }
        int charIndex = s[ind] - 'a';
        int newcharCount = uniqueCount |(1 << charIndex);
        // to go further without changing the current index charcter
        int uni = __builtin_popcount(newcharCount);
        // int notOp = solve(ind+1 ,s,k,change);
        int ans = 0;
        if(uni > k){
          ans = 1 + solve(ind+1 , s , k, (1 << charIndex),change);
        }else{
           ans = solve(ind+1 , s , k,newcharCount,change);
        } 
        // chech if we can change the one char in this strin if we can 
        // do so and pass on further that we previously change one charcter so we cant change any thing
       if(change){
             for(int i = 0 ; i < 26 ; i++){
                 int nw = uniqueCount | (1 << i);
                 int count =  __builtin_popcount(nw);

                 if(count > k){
                      ans = max(ans,1 + solve(ind+1 , s , k,(1 << i),false));
                 }else{
                      ans = max(ans , solve(ind+1 , s , k ,nw,false));
                 }
             }
       }
       return dp[state] = ans;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        dp.clear();
        return solve(0,s,k,0,true)+1;
    }
};