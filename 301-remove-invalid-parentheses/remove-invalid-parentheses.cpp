class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto i : s) {
            if (i == '(' or i == '{' or i == '[')
                st.push(i);
            else if (i == ')' or i == '}' or i == ']') {
                if (st.empty() or 
                    (st.top() == '(' and i != ')') or 
                    (st.top() == '{' and i != '}') or 
                    (st.top() == '[' and i != ']'))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        if (s.empty()) {
            return {""};
        }

        set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                if (found) continue;  // Stop processing once we find valid expressions

                for (int i = 0; i < curr.size(); i++) {
                    if (curr[i] != '(' && curr[i] != ')') continue; // Ignore non-parenthesis characters

                    string temp = curr.substr(0, i) + curr.substr(i + 1);
                    if (visited.find(temp) == visited.end()) {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            if (found) break;
        }
        return ans;
    }
};
