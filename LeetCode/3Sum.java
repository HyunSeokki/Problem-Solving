class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> ret = new HashSet<>();
        int sz = nums.length;
        int idx = sz;
        Arrays.sort(nums);

        for (int i = 0; i < sz; i++) {
            if (nums[i] > 0) {
                idx = i;
                break;
            }
        }

        for (int i = 0; i < idx; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = sz - 1;

            while (l < r) {
                if (nums[l] + nums[r] == nums[i] * -1) {
                    ret.add(new ArrayList<Integer>(Arrays.asList(nums[i], nums[l], nums[r])));
                    l++;
                    r--;
                }
                else if (nums[l] + nums[r] < nums[i] * -1)
                    l++;
                else
                    r--;
            }
        }

        return new LinkedList<>(ret);
    }
}