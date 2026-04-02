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
    bool canTransform(string start, string end) {
        string s1, s2;
        for (char c : start) if (c != 'X') s1 += c;
        for (char c : end) if (c != 'X') s2 += c;
        if (s1 != s2) return false;
        int n = start.size(), i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == 'X') i++;
            while (j < n && end[j] == 'X') j++;
            if (i == n || j == n) return i == n && j == n;
            if (start[i] != end[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            i++; j++;
        }
        while (i < n && start[i] == 'X') i++;
        while (j < n && end[j] == 'X') j++;
        return i == n && j == n;
    }
};
