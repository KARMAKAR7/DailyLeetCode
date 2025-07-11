class Solution {
public:
typedef pair<long long,int>p;
    int mostBooked(int n, vector<vector<int>>& meetings) {
     int m = meetings.size();
     sort(begin(meetings),end(meetings)); // sort by starting of time
     vector<int>roomsUseCount(n,0); // roomusedCount[i] = room i used how many times
     
     priority_queue<p,vector<p> , greater<p>>usedRooms;
     priority_queue<int , vector<int> , greater<int>>availableRooms;

     for(int room = 0 ; room < n;room++){
         availableRooms.push(room);
     }

     for(vector<int>& meet :meetings){
         int start = meet[0];
         int end = meet[1];
         int durationTime = end - start;

         while(!usedRooms.empty() && usedRooms.top().first<=start ){
               int room = usedRooms.top().second;
               usedRooms.pop();
               availableRooms.push(room);
               }
        if(!availableRooms.empty()){
            int room = availableRooms.top();
            availableRooms.pop();
            usedRooms.push({end , room});
            roomsUseCount[room]++;
        }else{ // we dont have available room pick earliest one
             int room = usedRooms.top().second;
             long long endtime = usedRooms.top().first;
             usedRooms.pop();
             usedRooms.push({endtime+durationTime,room});
             roomsUseCount[room]++;
        }
     }

     int resultRoom = -1;
     int maxUse  = 0;
     for(int i = 0 ; i< n ;i++){
         if(roomsUseCount[i]>maxUse){
             maxUse = roomsUseCount[i];
             resultRoom = i;
         }
     }
     return resultRoom;
  }
};