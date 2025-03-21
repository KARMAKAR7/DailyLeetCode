class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string>mpp(supplies.begin(),supplies.end()); // for quick check;
        vector<string>res;
        vector<bool>cooked(n,false);
        int c = n;
        while(c--){
            for(int j = 0 ; j < n ; j++){
                if(cooked[j]) continue;

                bool ok = true;

                for(int k = 0 ; k < ingredients[j].size() ; k++){
                    if(mpp.find(ingredients[j][k]) == mpp.end()){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    mpp.insert(recipes[j]);
                    res.push_back(recipes[j]);
                    cooked[j] = true;
                }
            }
        }
      return res;
    }
};