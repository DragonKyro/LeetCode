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
    string sortVowels(string s) {
        string v = "aeiouAEIOU";
        string vowels;
        for (char c : s) if (v.find(c) != string::npos) vowels += c;
        sort(vowels.begin(), vowels.end());
        int j = 0;
        for (char& c : s) if (v.find(c) != string::npos) c = vowels[j++];
        return s;
    }
};
