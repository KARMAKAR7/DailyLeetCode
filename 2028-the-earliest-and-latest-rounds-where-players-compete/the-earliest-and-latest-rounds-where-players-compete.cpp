class Solution {
public:
     int mx = INT_MIN, mn = INT_MAX;
    int N = 0, f = 0, s = 0;
    void calc(int mask,int round,int i,int j){
        if(i>=j){
            calc(mask,round+1,0,N); // increment round and reset pointers
        }
        else if((mask&(1<<i)) == 0){
            calc(mask,round,i+1,j); 
        }
        else if((mask&(1<<j)) == 0){
            calc(mask,round,i,j-1);
        }
        else if(i==f && j==s){ // best players comes head to head
            mx = max(mx,round);
            mn = min(mn,round); 
        }
        else{ 
            if(i!=f && i!=s){ 
                calc(mask^(1<<i),round,i+1,j-1);
            }
            if(j!=f && j!=s){
                calc(mask^(1<<j),round,i+1,j-1); 
            }
        }
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        N = n-1; f = firstPlayer - 1; s = secondPlayer -1;
        calc((1<<n)-1,1,0,n-1);
        return {mn,mx};
    }
};