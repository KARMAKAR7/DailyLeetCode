class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penalty = 0;
        for(auto ch:customers){
            if(ch == 'Y'){
                penalty++;
            }
        }
        int mini_penalty =  penalty;
        int bestHour = 0;

        for(int i = 0 ; i < n ; i++){
            if(customers[i] == 'Y'){
                penalty --;
            }else{
                penalty ++;
            }
            if(penalty < mini_penalty){
                  mini_penalty = penalty;
                  bestHour = i+1;
            }
        }
        return bestHour;
    }
};