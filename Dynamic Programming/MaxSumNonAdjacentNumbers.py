def maxSum(n,nums):
    n = len(nums)
    if n < 3:
        print(max(nums))
    #  ----- tabulation ------
    # dp = [0] * n 
    # dp[0] = nums[0]
    # dp[1] = max(nums[0], nums[1])

    # for i in range(2, n):
    #     dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])
    
    # return dp[n - 1]

    # ----- space optimization ------
    ans = 0
    prev2 = nums[0]                 # prev2 is eqivalent to dp[i - 2]
    prev1 = max(nums[0], nums[1])   # prev1 is eqivalent to dp[i - 1]

    for i in range(2, n):
        ans = max(prev1, nums[i] + prev2)
        prev2, prev1 = prev1, ans 
    
    return ans
