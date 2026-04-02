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
    string ones[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens_arr[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousands[4] = {"", "Thousand", "Million", "Billion"};

    string helper(int num) {
        if (num == 0) return "";
        else if (num < 20) return ones[num] + " ";
        else if (num < 100) return tens_arr[num / 10] + " " + helper(num % 10);
        else return ones[num / 100] + " Hundred " + helper(num % 100);
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res;
        for (int i = 0; num > 0; i++) {
            if (num % 1000 != 0) {
                res = helper(num % 1000) + thousands[i] + " " + res;
            }
            num /= 1000;
        }
        while (res.back() == ' ') res.pop_back();
        return res;
    }
};
