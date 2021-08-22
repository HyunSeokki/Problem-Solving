import java.util.*;

class Solution {
    public int maxProduct(int[] nums) {
        int sz = nums.length;
        int ret = nums[0];
        Vector<Integer> max = new Vector<>();
        Vector<Integer> min = new Vector<>();

        max.add(nums[0]);
        min.add(nums[0]);
        ret = nums[0];

        for (int i = 1; i < sz; i++) {
            max.add(Math.max(Math.max(max.get(i - 1) * nums[i], min.get(i - 1) * nums[i]), nums[i]));
            min.add(Math.min(Math.min(max.get(i - 1) * nums[i], min.get(i - 1) * nums[i]), nums[i]));

            ret = Math.max(ret, max.get(i));
        }

        return ret;
    }
}