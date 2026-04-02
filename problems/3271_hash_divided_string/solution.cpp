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
    string stringHash(string s, int k) {
        string res;
        for (int i = 0; i < s.size(); i += k) {
            int total = 0;
            for (int j = i; j < i + k; j++) total += s[j] - 'a';
            res += (char)(total % 26 + 'a');
        }
        return res;
    }
};
