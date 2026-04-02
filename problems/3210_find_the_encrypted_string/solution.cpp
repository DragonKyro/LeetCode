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
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string res(n, ' ');
        for (int i = 0; i < n; i++) res[i] = s[(i+k)%n];
        return res;
    }
};
