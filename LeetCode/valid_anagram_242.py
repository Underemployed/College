# class Solution:
#     def isAnagram(self, s: str, t: str) -> bool:
#         countS = {}
#         countT = {}
#         if len(s) != len(t): return False
#         for i in range(len(s)):
#             countS[s[i]] = 1 + countS.get(s[i],0)
#             countT[t[i]] = 1 + countT.get(t[i],0)

#         for i in range(len(s)):
#             if s[i] not in countT or countS[s[i]] != countT[s[i]]:
#                 return False
  
#         return True
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
            
# Create an instance of the Solution class
solution = Solution()

# Call the isAnagram method with example arguments
result = solution.isAnagram("jar", "car")

# Print the result
print(result)  
