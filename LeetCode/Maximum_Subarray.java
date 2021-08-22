import java.util.*;

class Solution {
    public int maxSubArray(int[] nums) {
        int sz = nums.length;
        int ret = nums[0];
        Vector<Integer> v = new Vector<>();

        v.add(nums[0]);
        ret = nums[0];

        for (int i = 1; i < sz; i++) {
            if (v.get(i - 1) + nums[i] > 0)
                v.add(Math.max(v.get(i - 1) + nums[i], nums[i]));
            else
                v.add(nums[i]);

            ret = Math.max(ret, v.get(i));

        }

        return ret;
    }
}