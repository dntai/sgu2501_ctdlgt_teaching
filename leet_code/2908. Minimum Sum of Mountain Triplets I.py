print = lambda *argc, **argv: ()

class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        ans = -1
        
        print("nums: ", end = "")
        for ni in nums:
            print(ni, end = ", ")
        print("")
        
        # brute-force
        n = len(nums)
        # list all pairs (i,j,k): i<j<k
        for i in range(0, n-2):
            for j in range(i+1, n-1):
                for k in range(j+1, n):
                    print(f"({i}, {j}, {k}) = {nums[i]}, {nums[j]}, {nums[k]}", end = " ")
                    if nums[i]<nums[j] and nums[j]>nums[k]:
                        vsum = nums[i] + nums[j] + nums[k] 
                        if ans==-1 or vsum<ans:
                            ans = vsum
                        print(f" --> Ok --> {vsum} --> {ans}", end = "")
                        pass
                    print("")
                    pass # for k
                pass # for j
            pass # for i
        
        return ans
