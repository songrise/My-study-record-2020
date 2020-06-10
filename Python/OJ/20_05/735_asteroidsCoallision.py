# #Buggy
# class Solution:
#     def asteroidCollision(self, asteroids: List[int]) -> List[int]:
#         stack = []
#         for a in asteroids:
#             if (not stack) or a < 0 or stack[-1] * a > 0:
#                 stack.append(a)
#             else:
#                 while stack and stack[-1] * a < 0:
#                     top = stack.pop()
#                     if abs(a) > abs(top):
            
#                     elif abs(a) < abs(top):
#                         a = top
#                     else:
#                         a = 0
#                         continue
#                     stack.append(a)
#                 else:
#                     stack.append(a)