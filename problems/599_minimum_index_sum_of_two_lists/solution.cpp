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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        for (int i = 0; i < (int)list1.size(); i++) mp[list1[i]] = i;
        vector<string> res;
        int minSum = INT_MAX;
        for (int j = 0; j < (int)list2.size(); j++) {
            if (mp.count(list2[j])) {
                int sum = j + mp[list2[j]];
                if (sum < minSum) { minSum = sum; res = {list2[j]}; }
                else if (sum == minSum) res.push_back(list2[j]);
            }
        }
        return res;
    }
};
