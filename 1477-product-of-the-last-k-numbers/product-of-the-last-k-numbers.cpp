class ProductOfNumbers {
public:
    vector<int>arr;
    int n;
    ProductOfNumbers() {
      arr.clear();   
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        n = arr.size();
        if(k > n) return 0;
        int ans = 1;
        for(int i = n-1 ; i >= n-k ; i--){
             ans *= arr[i];
             if(arr[i] == 0) return 0;
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */