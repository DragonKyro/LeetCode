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
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> good(words.begin(), words.end());
        for (auto& word : words)
            for (int k = 1; k < word.size(); k++)
                good.erase(word.substr(k));
        int res = 0;
        for (auto& w : good) res += w.size() + 1;
        return res;
    }
};
