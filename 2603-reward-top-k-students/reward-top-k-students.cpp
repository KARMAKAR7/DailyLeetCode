class Solution {
public:
    using P = pair<int,int>;
    int solve(unordered_set<string>&p,unordered_set<string>&n, string &rep){
        string word = "";
        int score = 0;
        for(int i = 0 ; i < rep.length() ; i++){
            if(rep[i] == ' '){
                if(p.find(word) != p.end()){
                     score += 3;
                }else if(n.find(word) != n.end()){
                     score -= 1;
                }
               word = "";
            }else{
                word+= rep[i];
            }
        }
        if (!word.empty()) {
            if (p.find(word) != p.end()) score += 3;
            else if (n.find(word) != n.end()) score -= 1;
        }
     return score;
    }
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        int n = student_id.size();
        vector<int>studentRes(n,0);
        unordered_set<string>p(positive_feedback.begin(),positive_feedback.end());
        unordered_set<string>N(negative_feedback.begin(),negative_feedback.end());
        auto comp = [](pair<int, int> &a, pair<int, int> &b){
          if(a.first == b.first) return a.second > b.second;
          return a.first < b.first;
        };
       priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (int i = 0; i < n; i++) {
            int current_score = solve(p, N, report[i]);
            pq.push({current_score, student_id[i]});
        }
        vector<int> ans;
        while(pq.size() > 0 && k--){
            ans.push_back(pq.top().second); 
            pq.pop();
        }
        return ans;
    }
};