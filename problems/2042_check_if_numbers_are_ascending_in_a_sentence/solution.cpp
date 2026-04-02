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
    bool areNumbersAscending(string s) {
        int prev = -1;
        istringstream iss(s);
        string word;
        while (iss >> word) {
            if (isdigit(word[0])) {
                int num = stoi(word);
                if (num <= prev) return false;
                prev = num;
            }
        }
        return true;
    }
};
