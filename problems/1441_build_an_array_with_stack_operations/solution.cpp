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
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int j = 0;
        for (int i = 1; i <= n && j < (int)target.size(); i++) {
            res.push_back("Push");
            if (target[j] == i) j++;
            else res.push_back("Pop");
        }
        return res;
    }
};
