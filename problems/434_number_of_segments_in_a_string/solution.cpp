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
    int countSegments(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) count++;
        }
        return count;
    }
};
