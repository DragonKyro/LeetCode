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
    int maximumScore(int a, int b, int c) {
        int s[] = {a, b, c};
        sort(s, s + 3);
        if (s[0] + s[1] <= s[2]) return s[0] + s[1];
        return (a + b + c) / 2;
    }
};
