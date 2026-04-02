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
    int primePalindrome(int n) {
        if (n >= 8 && n <= 11) return 11;
        for (int len = 1; len <= 5; len++) {
            for (int root = pow(10, len - 1); root < pow(10, len); root++) {
                string s = to_string(root);
                string pal = s + string(s.rbegin() + 1, s.rend());
                int num = stoi(pal);
                if (num >= n && isPrime(num)) return num;
            }
        }
        return -1;
    }
    bool isPrime(int x) {
        if (x < 2) return false;
        if (x < 4) return true;
        if (x % 2 == 0 || x % 3 == 0) return false;
        for (int i = 5; i * i <= x; i += 6)
            if (x % i == 0 || x % (i + 2) == 0) return false;
        return true;
    }
};
