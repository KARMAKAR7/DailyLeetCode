class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>countof_unique;
        countof_unique.insert(nums.begin(),nums.end());
        int total_count  = countof_unique.size();
        countof_unique.clear();  // clear the whole set to reuse that;
        
        unordered_map<int,int>freq;
        int result = 0;
        int left = 0;
        for(int right = 0 ; right < nums.size() ; right++){
                freq[nums[right]]++;
                while(freq.size() == total_count){
                    result +=(nums.size()- right);
                    freq[nums[left]]--;
                    if(freq[nums[left]] == 0){
                        freq.erase(nums[left]);
                    }
                    left++;
                }
        }
        return result;
    }
};