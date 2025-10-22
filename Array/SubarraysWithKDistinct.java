import java.util.*;

public class SubarraysWithKDistinct {
    public int subarraysWithKDistinct(int[] nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    private int atMost(int[] nums, int k) {
        int left = 0, res = 0;
        Map<Integer, Integer> count = new HashMap<>();

        for (int right = 0; right < nums.length; right++) {
            count.put(nums[right], count.getOrDefault(nums[right], 0) + 1);
            if (count.get(nums[right]) == 1) k--;

            while (k < 0) {
                count.put(nums[left], count.get(nums[left]) - 1);
                if (count.get(nums[left]) == 0) k++;
                left++;
            }

            res += right - left + 1;
        }
        return res;
    }

    public static void main(String[] args) {
        SubarraysWithKDistinct sol = new SubarraysWithKDistinct();
        System.out.println(sol.subarraysWithKDistinct(new int[]{1, 2, 1, 2, 3}, 2));  // Output: 7
    }
}
