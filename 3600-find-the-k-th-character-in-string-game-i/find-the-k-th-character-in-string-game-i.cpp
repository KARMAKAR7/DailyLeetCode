class Solution {
public:
    char kthCharacter(int k) {
        if(k==1){
            return 'a';
        }
        int prevlen = (k+1)/2;
        char prevchar = kthCharacter(prevlen);
        if(k%2 == 0){
             return prevchar == 'z' ? 'a' : prevchar+1;
        }else{
            return prevchar;
        }
    }
};