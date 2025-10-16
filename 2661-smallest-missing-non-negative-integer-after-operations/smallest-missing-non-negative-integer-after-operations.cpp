class Solution {
public:
    /*
      Thoughts 
      1-> if all elemnents are presents in this array
      expect 0 so no matter what operations are perform mex always be 0

      other wise 
      we chcek the all elemmts whuch is not present that will be mex

      obserbations:
        if ele is already neg then dont need to perfrom operation is helps nothing 
        for other we can used modulo ele % val == its give last val after thet if we perfrom one more operation it will
        give negitive so after this mex will be 0 // not profitable

        // 
    */
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
         unordered_map<int,int>modValues;
            set<int>st;
            for(int i = 0 ; i < n ; i++){
                     int val = ((nums[i] % value) + value) % value;;
                     modValues[val]++;
            }
            int mex = 0;
            while(true){
                int val = mex % value;
                if(modValues[val] > 0){
                    modValues[val] --;
                    mex++;
                }else{
                    return mex;
                }
                
            }
          return 0;
        }
};