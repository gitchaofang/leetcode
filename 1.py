class Solution(object):
    def twoSum(self, nums, target):
        dic = {}
        for i in range(0,len(nums)):
            d = target - nums[i]
            if d in dic:
                return [dic[d],i]
            dic[nums[i]] = i
        return []
