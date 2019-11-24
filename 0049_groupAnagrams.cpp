//对单词排序，以排序的单词为key 放入map，从map 中取值
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> dic;
        vector<vector<string>> ret;
        for (int i = 0; i < strs.size(); ++i) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            dic[tmp].push_back(strs[i]);
        }
        map<string, vector<string>>::iterator iter = dic.begin();
        while (iter != dic.end()) {
            vector<string> tmp;
            for (int i = 0; i < iter->second.size(); ++i) {
                tmp.push_back(iter->second[i]);
            }
            ret.push_back(tmp);
            ++iter;
        }
        return ret;
        
    }
};