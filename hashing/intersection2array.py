def intersection(nums1,nums2):
    hashmap = {}
    result = []
    for num in nums1:
        hashmap[num] = hashmap.get(num,0)+1
    for num in hashmap:
        if num in nums2:
            result.append(num)
    return result

def solve():
    nums1 = [4,9,5]
    nums2 = [9,4,9,8,4]
    print(intersection(nums1,nums2))