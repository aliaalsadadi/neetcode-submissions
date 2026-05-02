class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for num in nums:
            if num not in count.keys():
                count[num] = 1
            else:
                count[num] += 1
        print(count)
        values = sorted(count.values(), reverse=True)
        values = values[:k]
        print(values)
        result = []
        for key, val in count.items():
            if val in values:
                result.append(key)
        return result