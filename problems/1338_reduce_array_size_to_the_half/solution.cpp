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
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> cnt;
        for (int x : arr) cnt[x]++;
        vector<int> counts;
        for (auto& [k,v] : cnt) counts.push_back(v);
        sort(counts.rbegin(), counts.rend());
        int total = 0, half = arr.size() / 2;
        for (int i = 0; i < (int)counts.size(); i++) {
            total += counts[i];
            if (total >= half) return i + 1;
        }
        return counts.size();
    }
};
