class Solution {
    public int reachNumber(int target) {
        target = Math.abs(target);
        int sum = 0;
        int i = 1;
        for (i = 1; true; i++) {
            sum += i;
            if (sum >= target) {
                if ((sum - target) % 2 == 0) {
                    break;
                }
            }
        }
        return i;
    }
}