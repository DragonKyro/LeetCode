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
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int> cnt;
        int total = 0;
        for (int i = 0; i < word.size(); i += k) {
            cnt[word.substr(i, k)]++;
            total++;
        }
        int mx = 0;
        for (auto& [_, v] : cnt) mx = max(mx, v);
        return total - mx;
    }
};
