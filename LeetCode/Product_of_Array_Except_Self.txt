class Solution {
    public int[] productExceptSelf(int[] nums) {
        int mul = 1;
        int mulNonZero = 1;
        int zeroNum = 0;

        int len = nums.length;
        int[] ret = new int[len];

        for (int i = 0; i < len; i++) {
            mul *= nums[i];

            if (nums[i] != 0)
                mulNonZero *= nums[i];
            else if (nums[i] == 0)
                zeroNum++;
        }


        for (int i = 0; i < len; i++) {
            if (zeroNum == 0) {
                ret[i] = mul / nums[i];
            } else if (zeroNum == 1) {
                if (nums[i] != 0)
                    ret[i] = mul / nums[i];
                else if (nums[i] == 0)
                    ret[i] = mulNonZero;
            } else if (zeroNum >= 2) {
                ret[i] = 0;
            }
        }

        return ret;
    }
}