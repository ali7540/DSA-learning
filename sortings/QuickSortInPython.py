def quick_sort(nums, start, end):

    def partition(nums, low, high):
        pivot = nums[high]
        i = low - 1
        for j in range(low, high):
            if nums[j] <= pivot:
                i += 1
                nums[i], nums[j] = nums[j], nums[i]
        nums[i + 1], nums[high] = nums[high], nums[i + 1]
        return i + 1

    def sorts(nums, start, end):
        if start < end:
            pi = partition(nums, start, end)
            sorts(nums, start, pi - 1)
            sorts(nums, pi + 1, end)

    sorts(nums, start, end)
    return nums
