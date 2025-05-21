class Solution {
public:
    int rowOneCount(const string &s){
        int count = 0;
        for(char c : s){
            if(c == '1') count++;
        }
        return count;
    } 

   int numberOfBeams(vector<string>& bank) {
    vector<int> device;
    for(const auto& row : bank){
        int c = rowOneCount(row);
        if(c > 0) device.push_back(c);
    }

    int ans = 0;
    if (device.size() >= 2) {
        for(int i = 0 ; i < device.size() - 1; i++){
            ans += device[i] * device[i + 1];
        }
    }

    return ans;
}
};
