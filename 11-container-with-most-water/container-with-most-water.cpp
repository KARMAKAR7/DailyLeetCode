class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int i =0;
        int j = n-1;
        int water=0;
        while(i<j){
            int hi = min(height[i],height[j]);
            int width = (j-i);
             water = max(water,width*hi);
             while(height[i]<=hi && i < j ){
                 i++;
             }
             while(height[j]<=hi && i < j){
                 j--;
             }
        }
        return water;
    }
};