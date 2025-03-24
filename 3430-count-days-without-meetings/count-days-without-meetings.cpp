class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(),meetings.end());
    
        vector<vector<int>> newMeetings;

        for(auto me :meetings){
            if(newMeetings.empty() || newMeetings.back()[1] < me[0]){
               newMeetings.push_back(me);
            }else{
                newMeetings.back()[1] = max(newMeetings.back()[1] , me[1]);
            }
        }
        int wkD = 0;
        for(auto in : newMeetings){
             wkD += in[1] - in[0] + 1;
        }
       return days - wkD;
    }    
};