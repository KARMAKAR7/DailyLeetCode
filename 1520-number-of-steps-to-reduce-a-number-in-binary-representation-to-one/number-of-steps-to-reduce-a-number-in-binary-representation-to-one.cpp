class Solution {
public:
    //  int convert(string &s) {
    //     long long decimalNo = 0;
    //     int pow = 1; // Represents 2^0 initially

    //     // Iterate the string in reverse order to handle least significant bit first
    //     for(auto it = s.rbegin(); it != s.rend(); ++it){
    //         if(*it == '1'){
    //             decimalNo += pow;
    //         }
    //         pow *= 2; // Move to the next bit (2^n)
    //     }
    //     return decimalNo;
    // }
    int numSteps(string s) {
        // int decimalNo = convert(s);
        // cout<< decimalNo <<endl;
        int countSteps = 0 ;
        while(s.size()> 1){
            if(s.back()=='0'){
                s.pop_back();
               countSteps++;
               continue;
            }
            bool check = false;
            for(int i = s.size()-1 ; i>=0 ; i--){
                if(s[i]=='0'){
                    s[i]='1';
                    check = true;
                    break;
                }else{
                     s[i] = '0';
                }
            }
            if(!check){
                s = "1"+ s;
            }
            countSteps++;
        }

        return countSteps ;
    }
};