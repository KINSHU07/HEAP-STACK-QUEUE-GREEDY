#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {

    int n = nums.size();

    vector<int> ans(n, -1);
    stack<int> st;

    // Traverse twice because the array is circular
    for (int i = 2 * n - 1; i >= 0; i--) {

        int index = i % n;

        // Remove elements smaller than or equal to current
        while (!st.empty() && st.top() <= nums[index]) {
            st.pop();
        }

        // Only fill answer during the first traversal
        if (i < n) {
            if (!st.empty()) {
                ans[index] = st.top();
            }
        }

        st.push(nums[index]);
    }

    return ans;
}

int main() {

    vector<int> nums = {1, 2, 1};

    vector<int> ans = nextGreaterElements(nums);

    cout << "Next Greater Elements: ";

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}