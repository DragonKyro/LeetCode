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
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        istringstream iss(s1 + " " + s2);
        string word;
        while (iss >> word) count[word]++;
        vector<string> result;
        for (auto& [w, c] : count) if (c == 1) result.push_back(w);
        return result;
    }
};
