class Solution {
    public int search(int[] nums, int target) {
        int len = nums.length;
        int cnt = 0;
        int ret;

        while (!checkAscending(nums, len)) {
            int temp = nums[len - 1];

            for (int i = len - 1; i > 0; i--)
                nums[i] = nums[i - 1];

            nums[0] = temp;
            cnt++;
        }

        if (len == 1)
            return (nums[0] == target) ? 0 : -1;
        else {
            ret = binarySearch(nums, len, target);
            if (ret == -1)
                return ret;

            ret -= cnt;
            if (ret < 0)
                ret += len;

            return ret;
        }

    }

    public boolean checkAscending(int[] nums, int len) {
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > nums[i + 1])
                return false;
        }

        return true;
    }

    public int binarySearch(int[] nums, int len, int target) {
        int left = 0, right = len - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
}