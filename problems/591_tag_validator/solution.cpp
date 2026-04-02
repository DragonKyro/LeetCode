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
    bool isValid(string code) {
        regex cdata(R"(<!\[CDATA\[.*?\]\]>)");
        code = regex_replace(code, cdata, "c");
        string prev;
        regex tag(R"(<([A-Z]{1,9})>[^<]*</\1>)");
        while (code != prev) {
            prev = code;
            code = regex_replace(code, tag, "t");
        }
        return code == "t";
    }
};
