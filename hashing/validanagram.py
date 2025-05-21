def isAnagram(s,t):
    if len(s) != len(t):
        return False
    hashmap = {}
    for char in s:
        hashmap[char] = hashmap.get(char,0) + 1
    
    for char in t:
        if char not in hashmap or hashmap[char] == 0:
            return False
        hashmap[char] -=1
    return True

def solve():
    s = "anagram"
    t = "naagram"
    print(isAnagram(s,t))