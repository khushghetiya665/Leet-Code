class Solution {
    public boolean isMiddleElementUnique(int[] nums) {
        int mid = nums.length / 2;
        for (int i = 0; i < nums.length; i++) {
            if (nums[mid] == nums[i] && i != mid) {
                return false;
            }
        }
        return true;
    }
}