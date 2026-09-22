// Problem: Jump Game I
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int reach = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(i > reach)
            return false;

        reach = max(reach, i + nums[i]);
    }

    return true;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << canJump(nums);

    return 0;
}