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
    bool isValid(string word) {
        if (word.size() < 3) return false;
        bool v = false, c = false;
        for (char ch : word) {
            if (!isalnum(ch)) return false;
            if (isalpha(ch)) {
                if (string("aeiouAEIOU").find(ch) != string::npos) v = true;
                else c = true;
            }
        }
        return v && c;
    }
};
