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
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) return "";
        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] != 'a') { palindrome[i] = 'a'; return palindrome; }
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};
