class Solution {
    public int[] findErrorNums(int[] nums) {

        int repete = 0, not = 0;

        for (int i = 1; i <= nums.length; i++) {
            int count = 0;

            for (int j = 0; j < nums.length; j++) {
                if (nums[j] == i) {
                    count++;
                }
            }

            if (count == 2) {
                repete = i;
            }

            if (count == 0) {
                not = i;
            }
        }

        return new int[] { repete, not };
    }
}