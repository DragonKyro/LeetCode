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
    int compress(vector<char>& chars) {
        int write = 0, read = 0;
        while (read < chars.size()) {
            char current = chars[read];
            int count = 0;
            while (read < chars.size() && chars[read] == current) { read++; count++; }
            chars[write++] = current;
            if (count > 1) {
                string s = to_string(count);
                for (char c : s) chars[write++] = c;
            }
        }
        return write;
    }
};
