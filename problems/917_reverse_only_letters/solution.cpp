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
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (!isalpha(s[left])) left++;
            else if (!isalpha(s[right])) right--;
            else swap(s[left++], s[right--]);
        }
        return s;
    }
};
