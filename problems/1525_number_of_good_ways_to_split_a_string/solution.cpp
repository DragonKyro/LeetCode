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
    int numSplits(string s) {
        unordered_map<char, int> left, right;
        for (char c : s) right[c]++;
        int res = 0;
        for (char c : s) {
            left[c]++;
            right[c]--;
            if (right[c] == 0) right.erase(c);
            if (left.size() == right.size()) res++;
        }
        return res;
    }
};
