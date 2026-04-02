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
    bool halvesAreAlike(string s) {
        string vowels = "aeiouAEIOU";
        int n = s.size(), count = 0;
        for (int i = 0; i < n / 2; i++) if (vowels.find(s[i]) != string::npos) count++;
        for (int i = n / 2; i < n; i++) if (vowels.find(s[i]) != string::npos) count--;
        return count == 0;
    }
};
