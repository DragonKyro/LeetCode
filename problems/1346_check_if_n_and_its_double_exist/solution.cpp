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
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for (int x : arr) {
            if (seen.count(2*x) || (x % 2 == 0 && seen.count(x/2))) return true;
            seen.insert(x);
        }
        return false;
    }
};
