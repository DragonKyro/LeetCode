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
    int numSpecialEquivGroups(vector<string>& words) {
        set<pair<string,string>> groups;
        for (auto& w : words) {
            string even, odd;
            for (int i = 0; i < w.size(); i++) {
                if (i % 2 == 0) even += w[i]; else odd += w[i];
            }
            sort(even.begin(), even.end()); sort(odd.begin(), odd.end());
            groups.insert({even, odd});
        }
        return groups.size();
    }
};
