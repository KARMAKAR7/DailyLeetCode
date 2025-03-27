class Solution {
public:
    int findMajorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    }

    return -1; 
   }
    int minimumIndex(vector<int>& nums) {
    int n = nums.size();
    
    int dominant = findMajorityElement(nums);
    int totalCount = 0;
    for (int num : nums) {
        if (num == dominant) {
            totalCount++;
        }
    }

    int leftCount = 0;
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == dominant) {
            leftCount++;
        }
        
        int leftSize = i + 1;
        int rightCount = totalCount - leftCount;
        int rightSize = n - leftSize;

        if (leftCount > leftSize/2 && rightCount  > rightSize/2) {
            return i;
        }
    }

    return -1;
    }
};