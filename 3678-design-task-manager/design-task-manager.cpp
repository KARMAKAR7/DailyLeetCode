using T = tuple<int,int,int>; 
// user id , task id , priority
struct comp{
     bool operator()(const T &a ,const T &b){
        if(get<2>(a) == get<2>(b)){
            return get<1>(a) < get<1>(b);
        }
       return get<2>(a) < get<2>(b);
    }
};
class TaskManager {
    priority_queue<T,vector<T>,comp>pq;
    unordered_map<int,pair<int,int>>mpp; //  // taskId -> {userId, priority}
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &t:tasks){
            int userid = t[0] , taskid = t[1] , p = t[2];
            add(userid,taskid,p);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mpp[taskId] = {userId,priority};
        pq.emplace(userId,taskId,priority);
    }
    
    void edit(int taskId, int newPriority) {
         if(!mpp.count(taskId)) return;
         auto [id,_] = mpp[taskId];
         mpp[taskId] = {id,newPriority};
         pq.emplace(id,taskId,newPriority);
    }
    
    void rmv(int taskId) {
         mpp.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [id , tid , p] = pq.top();
            pq.pop();
            auto it = mpp.find(tid);
            if(it != mpp.end() && it->second.first == id && it->second.second == p){
                mpp.erase(it);
                return id;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */