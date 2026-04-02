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
    int repeatedStringMatch(string a, string b) {
        int times = (b.size() + a.size() - 1) / a.size();
        string repeated;
        for (int i = 0; i < times; i++) repeated += a;
        if (repeated.find(b) != string::npos) return times;
        repeated += a;
        if (repeated.find(b) != string::npos) return times + 1;
        return -1;
    }
};
