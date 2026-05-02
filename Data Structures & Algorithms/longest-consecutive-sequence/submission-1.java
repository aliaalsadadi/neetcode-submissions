class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> numSet = new HashSet<Integer>();
        for (int n : nums)
        {
            numSet.add(n);
        }
        int longest = 0;

        for (int num : nums)
        {
            if (!numSet.contains(num-1))
            {
                int length = 0;
                while (numSet.contains(length + num))
                {
                    length++;
                }
                longest = Math.max(length,longest);
            }
        }
        return longest;
    }
}
