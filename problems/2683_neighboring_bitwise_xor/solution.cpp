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
    bool doesValidArrayExist(vector<int>& derived) {
        int x = 0;
        for (int d : derived) x ^= d;
        return x == 0;
    }
};
