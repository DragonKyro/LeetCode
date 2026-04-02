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
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> count;
        for (int n : arr) count[n]++;
        vector<int> counts;
        for (auto& [_, c] : count) counts.push_back(c);
        sort(counts.begin(), counts.end());
        int removed = 0;
        for (int c : counts) {
            if (k >= c) { k -= c; removed++; }
            else break;
        }
        return counts.size() - removed;
    }
};
