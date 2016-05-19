class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        triplets = dict()
        rst = list()
        nums.sort()
        #print nums    
        for i in range (0, len(nums)):
            sum1 = 0 - nums[i]
            for j in range(i + 1, len(nums)):
                val = sum1 - nums[j]
                
                #print nums[i], nums[j], val
            
                idx = self.findVal(nums, val, j + 1, len(nums))
                if idx == -1:
                    continue
                else:
                    if nums[i] in triplets and nums[j] in triplets[nums[i]]:
                        continue
                    rst.append([nums[i], nums[j], nums[idx]])
                    if nums[i] not in triplets:
                        triplets[nums[i]] = set()
                    triplets[nums[i]].add(nums[j])
        return rst
        
    def findVal(self, nums, val, l, r):
        while l < r:
            mid = (l + r) / 2
            if nums[mid] == val: 
                return mid
            elif nums[mid] < val:
                l = mid + 1
            elif nums[mid] > val:
                r = mid
        return -1


if __name__ == '__main__':
    nums = [-1, 0, 1, 2, -1, -4]
    sc = Solution()
    print sc.threeSum(nums)
