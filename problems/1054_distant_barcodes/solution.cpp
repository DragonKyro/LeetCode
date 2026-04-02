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
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> count;
        for (int b : barcodes) count[b]++;
        vector<pair<int,int>> items(count.begin(), count.end());
        sort(items.begin(), items.end(), [](auto& a, auto& b) { return a.second > b.second; });
        vector<int> result(barcodes.size());
        int idx = 0;
        for (auto& [val, cnt] : items) {
            for (int i = 0; i < cnt; i++) {
                result[idx] = val;
                idx += 2;
                if (idx >= (int)barcodes.size()) idx = 1;
            }
        }
        return result;
    }
};
