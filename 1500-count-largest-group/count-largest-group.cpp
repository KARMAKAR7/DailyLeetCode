class Solution {
public:
    inline int s(int digit){
        int sum = 0;  
        while(digit > 0){
            sum += digit % 10;
            digit /= 10;
        }
        return sum;
    }

    int solve(int n){
        unordered_map<int,vector<int>> sum_digits; 
        for(int i = 1 ; i <= n ; i++){
            int sum = s(i);
            sum_digits[sum].push_back(i);
        }

        int mx = 0, result = 0;
        for(auto &it : sum_digits){
            int size = it.second.size();
            if(size > mx){
                mx = size;
                result = 1;
            } else if(size == mx){
                result++;
            }
        }
        return result;
    }

    int countLargestGroup(int n) {
        return solve(n);
    }
};
