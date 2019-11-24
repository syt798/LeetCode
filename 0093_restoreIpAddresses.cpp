class Solution {
public:
    vector<string> restoreIpAddresses(string& s) {
        vector<string> res;
        helper(s, 4, "", res);
        return res;
    }
    void helper(string s, int k, string out, vector<string>& res) {
        if (k == 0) {
            if (s.empty()) res.push_back(out);
            return;
        } 
        for (int i = 1; i < 4; ++i) {
            if (s.size() < i) break;
            int val = stoi(s.substr(0, i));
            if (val > 255 || i != to_string(val).size()) continue;
            helper(s.substr(i), k - 1, out + s.substr(0, i) + (k == 1 ? "" : "."), res);
        }
    }
};