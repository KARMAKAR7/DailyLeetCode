class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int>st;


        vector<int>ans(n,0);
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(st.count(A[i])) count++;
            else st.insert(A[i]);


            if(st.count(B[i])) count++;
            else st.insert(B[i]);

            ans[i] = count;
        }
        return ans;
    }
};