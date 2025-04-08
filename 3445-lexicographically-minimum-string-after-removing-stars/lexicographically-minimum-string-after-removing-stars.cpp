class Solution {
public:
   string clearStars(string s) {
    auto comp = [](const pair<int, int>& a, const pair<int, int>& b){  //comparator to sort in priority queue
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq;
    string ans = "";
    for(int i = 0; i < s.size(); ++i){   
        if(s[i] != '*') {                 // when not '*' then simply push the ith char and index i to the priority queue
            pq.push({s[i], i});  
        }else{
            s[pq.top().second] = '*';     // when its '*', find the smallest index and rpelace that char with '*'
            pq.pop();
        }
    }
    for(auto  c: s){
        if(c != '*'){
            ans += c;
        }
    } // take all chars as ans except the '*' chars
    
    return ans;
}
};