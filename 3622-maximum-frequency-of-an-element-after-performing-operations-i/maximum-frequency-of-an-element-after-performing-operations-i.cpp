class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mini =1e9;
        int maxi = -1e9;
        int ans =0;

        for(int i: nums){
            maxi = max(maxi,i);
            mini = min(mini,i);
            
        }

        vector<int> freq(maxi+1,0);
        for(int i: nums){
            freq[i]++;
            
        }

        for(int i=1;i<=maxi;i++){
            freq[i]+=freq[i-1];
        }

        for(int curr = mini;curr<=maxi;curr++){

            int l = max(mini,curr-k);
            int r = min(maxi,curr+k);

            int f = freq[curr]-freq[curr-1];

            int extra = min(numOperations,freq[r]-freq[l-1]-f);

            ans =max(ans,f+extra);
        }

        return ans;
    }
};