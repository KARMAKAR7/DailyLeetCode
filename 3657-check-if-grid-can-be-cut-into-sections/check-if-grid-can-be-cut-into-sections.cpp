class Solution {
public:
    bool check(int n , vector<vector<int>>&rectangles,int dim){
        int gapCount = 0;

        sort(rectangles.begin(),rectangles.end(),[dim](const vector<int>&a ,const vector<int>&b ){
              return a[dim] < b[dim];
        });

        int maXEnd = rectangles[0][dim + 2];

        for(size_t i = 0 ; i < rectangles.size(); i++){
            vector<int>&rect = rectangles[i];

            if(maXEnd <= rect[dim]){
                gapCount++;
            }
            maXEnd = max(maXEnd , rect[dim+2]);
        }
        return gapCount >= 2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return check(n,rectangles,0) || check(n,rectangles,1);
    }
};