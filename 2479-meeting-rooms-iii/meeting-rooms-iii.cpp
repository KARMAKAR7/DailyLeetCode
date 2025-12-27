class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<int>useCount(n,0);
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long long , int>,vector<pair<long long , int>>,greater<pair<long long , int>>>use;
        priority_queue<int , vector<int>,greater<int>>avl; 

        for(int i = 0 ; i < n ; i++){
                avl.push(i);
        }  

        for(auto &meet:meetings){
             int start = meet[0];
             int end = meet[1];
             int dur = end - start;
             // its have to have to remove rooms which meeting has already done
             while(!use.empty() && use.top().first <= start){
                    int room = use.top().second;
                    use.pop();
                    avl.push(room);
             }
             //first check if avalibe rooms are there or not
             // if have then add on used room
             if(!avl.empty()){
                int room = avl.top();
                avl.pop();
                use.push({end,room}); // book the room for end time
                useCount[room]++;

             }else{
                 int room = use.top().second;
                 long long endTime =  use.top().first;
                 use.pop();
                 use.push({endTime+dur,room}); // use least time avilable room
                 useCount[room]++;
             }
        }
        int max_useRoom = -1;
        int maxuse =  0;
        for(int i = 0 ; i < n ; i++){
              if(useCount[i] > maxuse){
                    maxuse = useCount[i];
                    max_useRoom = i;
              }
        }

    return max_useRoom;
    }
};