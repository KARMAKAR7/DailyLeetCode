class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        vector<string>res;
        sort(folder.begin(),folder.end());

        res.push_back(folder[0]);

        for(int i = 1 ; i < n ; i++){
            string last = res.back() + '/';

            if(folder[i].find(last) !=  0){
                res.push_back(folder[i]);
            } 
        } 
        return res;
    }
};