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
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> idx;
        for (int i = 0; i < nums.size(); i++) if (nums[i] == x) idx.push_back(i);
        vector<int> res;
        for (int q : queries)
            res.push_back(q <= (int)idx.size() ? idx[q-1] : -1);
        return res;
    }
};
