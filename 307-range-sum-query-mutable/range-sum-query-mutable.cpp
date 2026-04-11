class NumArray {
public:
    vector<int>nums;
    vector<int>blocks;
    int n;
    int bl_size;
    NumArray(vector<int>& nums) {
        this -> nums = nums;
        n = nums.size();
        bl_size = ceil(sqrt(n));
        blocks.resize(bl_size,0);

        //build the blocks size
        for(int i = 0 ; i < n ; i++){
            blocks[i/bl_size] += nums[i];
        }
        
    }
    
    void update(int index, int val) {
        int ind = index / bl_size;
        blocks[ind] -= nums[index];
        blocks[ind] += val;
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
      
        int start_block = left / bl_size;
        int end_block =   right / bl_size;

          // case -1 same block
          if(start_block == end_block){
             for(int i = left ; i <= right ; i++){
                  sum += nums[i];
             }
             return sum;
          }

          // case - 2 diffrent blocks

          // left
          int endIndexOfStartBlock = ((start_block + 1) * bl_size)-1;
          for(int i = left ; i <=endIndexOfStartBlock ; i++){
               sum += nums[i];
          }
          // middle
          for(int b = start_block + 1 ; b <=end_block-1; b++){
               sum += blocks[b];
          }
          //right
          int startIndexOfEndBlock = end_block * bl_size;
          for(int i = startIndexOfEndBlock ; i <=right ; i++){
               sum += nums[i];
          }
    return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */