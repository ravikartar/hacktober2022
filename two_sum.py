class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
#         Solution taken from: https://medium.com/@havbgbg68/leetcode-1-two-sum-python-8d77c223abd3
        
#         Map nums values to indices
        hash_table = {}
        for i in range(len(nums)):
        	hash_table[nums[i]] = i
#       	Loop through nums values and check if target-values exist in nums
        for i in range(len(nums)):
        	if target-nums[i] in hash_table:
            	if hash_table[target-nums[i]] != i:
	            	return i, hash_table[target-nums[i]]
	            	break
