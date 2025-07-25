class Solution {
public:
    // 10e9 -- total digits count 9 
    int dp[10][2][6][6][20][2]; // {index,tight,oddcount,evencount,reminder,validnum}
    int fun(int index , bool tight , int oddCount , int evenCount , int reminder , bool validNum , int &k , string &s){
        if(index >= s.size()){
            return (oddCount == evenCount) && (reminder == 0);
        }

        if(oddCount > 5 || evenCount > 5) return 0;

        if(dp[index][tight][oddCount][evenCount][reminder][validNum] != -1){
            return dp[index][tight][oddCount][evenCount][reminder][validNum];
        }
        int ans = 0;
        int limit = tight ? s[index]-'0': 9;

        for(int d = 0 ; d <= limit ; d++){
            int newTight = tight & (d == limit);

            if(validNum == false && d == 0){  // leading zeros
               ans += fun(index+1 , newTight , oddCount , evenCount , reminder , false,k,s);
            }
            else if(d % 2 == 0){
                 ans += fun(index+1 , newTight , oddCount , evenCount + 1 ,( reminder * 10 + d) % k ,true,k,s);
            }
            else{
                ans += fun(index+1 , newTight , oddCount + 1 , evenCount ,( reminder * 10 + d) % k ,true,k,s);
            }
        }
        return dp[index][tight][oddCount][evenCount][reminder][validNum] = ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string l = to_string(low-1);
        memset(dp,-1,sizeof(dp));

        long count1 = fun(0,1,0,0,0,0,k,l);
        
        memset(dp,-1,sizeof(dp));

        string h = to_string(high);
     
        int count2 = fun(0,1,0,0,0,0,k,h);
       
        return count2 - count1;
    }
};