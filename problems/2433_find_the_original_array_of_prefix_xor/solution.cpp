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
    vector<int> findArray(vector<int>& pref) {
        vector<int> result = {pref[0]};
        for (int i = 1; i < pref.size(); i++) result.push_back(pref[i] ^ pref[i-1]);
        return result;
    }
};
