class Solution {
public:
    vector<int>hours = {1,2,4,8};
    vector<int>mins = {1,2,4,8,16,32};
    void fun(vector<string>&res , pair<int,int>time,int noOfLeds , int ind){
        if(noOfLeds == 0){
            if(time.second < 10){
                res.push_back(to_string(time.first)+":0"+to_string(time.second));
            }
            else{
                res.push_back(to_string(time.first)+":"+to_string(time.second));
            }
            return;
        }
        int n = hours.size();
        int m = mins.size();

        for(int i = ind;i <(m+n);i++){
            if(i<n){
                time.first +=hours[i];
                if(time.first < 12){
                    fun(res,time,noOfLeds-1,i+1);
                }
                time.first -=hours[i];
            }else{
                  // current minutes waale LED ko lelo
                time.second += mins[i-n];
                // agar minutes less than 60 hai toh aage bado
                if(time.second<60)
                {
                    fun(res,time,noOfLeds-1,i+1);
                }
                // backtracking step current minutes jo liya tha usse remove karo taaki kisi aur minutes waale LED ko use kar saken
                time.second -= mins[i-n];
            }
        }

    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>res;
        fun(res,{0,0},turnedOn,0);
        return res;
    }
};