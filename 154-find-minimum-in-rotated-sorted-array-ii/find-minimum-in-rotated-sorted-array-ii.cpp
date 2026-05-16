class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = nums.size()-1;
        int ans = 0;
        while(low <= high){
            while(low < high && nums[low] == nums[low+1]) low ++;
            while(low < high && nums[high] == nums[high-1]) high--;
            
            int mid = low + (high - low) / 2;
            if(nums[ans] > nums[mid]){
                ans = mid;
            }
            if(nums[mid] > nums[high]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return nums[ans];
    }
};