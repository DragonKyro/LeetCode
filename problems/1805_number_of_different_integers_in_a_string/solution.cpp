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
    int numDifferentIntegers(string word) {
        set<string> s;
        int i = 0, n = word.size();
        while (i < n) {
            if (isdigit(word[i])) {
                int j = i;
                while (j < n && isdigit(word[j])) j++;
                while (i < j - 1 && word[i] == '0') i++;
                s.insert(word.substr(i, j - i));
                i = j;
            } else {
                i++;
            }
        }
        return s.size();
    }
};
