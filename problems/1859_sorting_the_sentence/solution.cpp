#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> words;
        istringstream iss(s);
        string w;
        while (iss >> w) words.push_back(w);
        vector<string> result(words.size());
        for (auto& w : words) {
            int idx = w.back() - '1';
            result[idx] = w.substr(0, w.size() - 1);
        }
        string ans;
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) ans += " ";
            ans += result[i];
        }
        return ans;
    }
};
