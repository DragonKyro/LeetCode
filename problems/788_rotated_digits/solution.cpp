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
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            if (s.find_first_of("347") != string::npos) continue;
            if (s.find_first_of("2569") != string::npos) count++;
        }
        return count;
    }
};
