class Solution {
public:
    bool possible(int k , vector<int>&tasks,vector<int>&workers,int pills,int strength){
        multiset<int>avl(workers.end()-k,workers.end());

        for(int i = k - 1; i >= 0 ; i--){
            int taskS = tasks[i];
            auto it = avl.lower_bound(taskS);
            if(it != avl.end()){
                avl.erase(it);
            }else{
                if(pills == 0) return false;

                it = avl.lower_bound(taskS - strength);
                if(it == avl.end()) return false;

                avl.erase(it);
                pills--;
            }
        }
       return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());

        int left = 0 , right = min(tasks.size(),workers.size());
        int ans = 0;
        while(left <= right){
            int mid = left + (right - left)/ 2;
            if(possible(mid,tasks,workers,pills,strength)){
                ans = mid;
                left = mid+1;
            }else{
                right = mid - 1;
            }
        }
      return ans;
    }
};