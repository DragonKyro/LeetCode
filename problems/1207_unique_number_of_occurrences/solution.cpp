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
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> cnt;
        for (int x : arr) cnt[x]++;
        unordered_set<int> seen;
        for (auto& [k,v] : cnt) seen.insert(v);
        return seen.size() == cnt.size();
    }
};
