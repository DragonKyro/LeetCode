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
    int maximumNumberOfStringPairs(vector<string>& words) {
        set<string> seen;
        int count = 0;
        for (auto& w : words) {
            string rev(w.rbegin(), w.rend());
            if (seen.count(rev)) count++;
            seen.insert(w);
        }
        return count;
    }
};
