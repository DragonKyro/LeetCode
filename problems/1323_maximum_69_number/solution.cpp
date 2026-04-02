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
    int maximum69Number(int num) {
        string s = to_string(num);
        for (char& c : s) { if (c == '6') { c = '9'; break; } }
        return stoi(s);
    }
};
