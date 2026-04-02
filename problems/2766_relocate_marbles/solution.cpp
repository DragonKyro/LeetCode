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
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> s(nums.begin(), nums.end());
        for (int i = 0; i < moveFrom.size(); i++) { s.erase(moveFrom[i]); s.insert(moveTo[i]); }
        return vector<int>(s.begin(), s.end());
    }
};
