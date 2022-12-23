#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        vector<string> res;
        string path;
        vector<bool> used(s.size(), false);
        auto dfs = [&](auto &dfs, int start) -> bool {
            if (start == s.size()) {
                res.push_back(path);
                res.back().pop_back();
                return true;
            }
            if (used[start]) {
                return false;
            }
            bool flag = true;
            for (auto &word: wordDict) {
                if (s.substr(start, word.size()) == word) {
                    path += word+' ';
                    if (dfs(dfs, start + word.size())) flag = false;
                    for (int i = 0; i <= word.size(); ++i) path.pop_back();
                }
            }
            if (flag) {
                used[start] = true;
                return false;
            }
            return true;
        };
        dfs(dfs, 0);
        return res;
    }
};
int main() {
    Solution s;
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    auto res = s.wordBreak("catsanddog", wordDict);
    for (auto &str:res) {
        cout << str << endl;
    }
    return 0;
}
#pragma clang diagnostic pop