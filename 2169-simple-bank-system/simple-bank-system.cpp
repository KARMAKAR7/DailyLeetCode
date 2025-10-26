#include <vector>
using namespace std;

class Bank {
public:
    using ll = long long;
    vector<ll> bal; 

    Bank(vector<long long>& balance) {
        bal.resize(balance.size() + 1);          
        for (size_t i = 0; i < balance.size(); ++i) {
            bal[i + 1] = balance[i];        
        }
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 <= 0 || account1 >= (int)bal.size() ||
            account2 <= 0 || account2 >= (int)bal.size()) return false;
        if (bal[account1] < money) return false;
        bal[account1] -= money;
        bal[account2] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account <= 0 || account >= (int)bal.size()) return false;
        bal[account] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account <= 0 || account >= (int)bal.size()) return false;
        if (bal[account] < money) return false;
        bal[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */