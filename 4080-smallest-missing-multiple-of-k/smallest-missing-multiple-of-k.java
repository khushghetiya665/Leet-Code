class Solution {
    public int missingMultiple(int[] nums, int k) {
        int n = 0;
        while (true) {
            int flag = 0;
            n += k;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] == n) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        return n;
    }
}