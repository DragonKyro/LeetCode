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
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int a = 0, b = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) a = a * 10 + (s[i] - '0');
            else b = b * 10 + (s[i] - '0');
        }
        return a + b;
    }
};
