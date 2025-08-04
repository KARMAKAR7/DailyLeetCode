class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int max_Len = 0 , i = 0;
        // this questions bolis down to max_len of the subarry that have only two unique elements

        unordered_map<int,int>mpp;
        int left = 0;
        for(int right = 0 ; right < n ; right++){
            mpp[fruits[right]]++;

            while(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0){
                    mpp.erase(fruits[left]);
                }
                left++;
            }

            max_Len = max(max_Len , right-left+1);
        }
        return max_Len;
    }
};