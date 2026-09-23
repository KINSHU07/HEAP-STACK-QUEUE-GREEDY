//nearest smaller element
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmaller(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }

        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        st.push(nums[i]);
    }

    return ans;
}

int main() {

    vector<int> nums = {4, 5, 2, 10, 8};

    vector<int> ans = nearestSmaller(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}