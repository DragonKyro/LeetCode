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
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* leftmost = root;
        while (leftmost->left) {
            Node* curr = leftmost;
            while (curr) {
                curr->left->next = curr->right;
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};
