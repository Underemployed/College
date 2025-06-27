class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = {}
        for i in range(len(nums)):
            hash[nums[i]] = i
        for i in range(len(nums)):
            rest = target - nums[i]
            potIdx = hash[rest]
            if potIdx != i:
                return [potIdx,i]
        return []