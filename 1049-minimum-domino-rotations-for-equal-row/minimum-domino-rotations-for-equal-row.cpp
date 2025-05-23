class Solution{
public:
int find(vector<int>& A, vector<int>& B, int val) {
        int ansA = 0;
        int ansB = 0;
        int n = A.size();
        for(int i = 0; i<n; i++) {
            if(A[i] != val && B[i] != val)
                return -1;
            else if(A[i] != val)
                ansA++; //swap A
            else if(B[i] != val)
                ansB++; //swap B
        }
        return min(ansA, ansB);
    }
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int result = -1;
        for(int i = 1; i<=6; i++) {
            int ans = find(A, B, i);
            if(ans != -1 && (result == -1 || result > ans))
                result = ans;
        }
        return result;
    }
};