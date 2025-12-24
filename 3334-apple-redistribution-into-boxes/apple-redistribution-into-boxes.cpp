class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int Total_apple=0;
        for(int i=0;i<apple.size();i++){
             Total_apple+=apple[i];
        }
        int total_box=0;
        sort(capacity.begin(),capacity.end(),greater<int>());
        for(int i=0;i<capacity.size();i++){
            Total_apple-=capacity[i];
            total_box++;
            if( Total_apple<=0){
                break;
            }
        }
        return total_box;
    }
};