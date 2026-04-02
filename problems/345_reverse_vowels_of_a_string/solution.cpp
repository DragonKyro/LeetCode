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
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && vowels.find(s[l]) == string::npos) l++;
            while (l < r && vowels.find(s[r]) == string::npos) r--;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
