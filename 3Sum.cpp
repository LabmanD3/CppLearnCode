class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.begin() + nums.size());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (left > i + 1 && nums[left] == nums[left - 1]) {
                    left++;
                    continue;
                }
                if (right < nums.size() - 2 && nums[right] == nums[right - 1]) {
                    right--;
                    continue;
                }
                int target = nums[i] + nums[left] + nums[right];
                if (target == 0) {
                    vector<int> temp = {i, left, right};
                    result.push_back(temp);
                } else if (target < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};