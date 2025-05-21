def twosum(nums,target):
    hashmap = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in hashmap:
            return [hashmap[complement],i]
        hashmap[num] = i



def solve():
    nums = [2,7,9,11]
    target = 9 
    print(twosum(nums,target))
