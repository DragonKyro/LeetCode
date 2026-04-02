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
    int compareVersion(string version1, string version2) {
        istringstream s1(version1), s2(version2);
        while (s1.good() || s2.good()) {
            int a = 0, b = 0;
            string tok;
            if (getline(s1, tok, '.')) a = stoi(tok);
            if (getline(s2, tok, '.')) b = stoi(tok);
            if (a > b) return 1;
            if (a < b) return -1;
        }
        return 0;
    }
};
