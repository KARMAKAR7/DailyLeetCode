class Solution {
public:
    int largestHistogram(vector<int>& hist) {
    int n = hist.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int curHeight = (i == n ? 0 : hist[i]);

        while (!st.empty() && hist[st.top()] > curHeight) {
            int height = hist[st.top()];
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
} 
int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if(m == 0) return 0;
    int n = matrix[0].size();
    vector<int>hist(n,0);
    int res = 0;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
             if(matrix[i][j] == '1'){
                hist[j] += 1; 
             }else{
                hist[j] = 0;
             }
        }
        res = max(res,largestHistogram(hist));
    }
    return res;
    }
};