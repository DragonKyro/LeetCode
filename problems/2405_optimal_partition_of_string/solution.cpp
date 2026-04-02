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
    int partitionString(string s) {
        unordered_set<char> seen;
        int count = 1;
        for (char c : s) {
            if (seen.count(c)) { count++; seen.clear(); }
            seen.insert(c);
        }
        return count;
    }
};
