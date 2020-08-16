from heapq import *

hp = [7, 4, 2, 1, 3, 6]
heapify(hp)
print(nsmallest(1, hp))

min_ = heappop(hp)
print(min_)
print(hp)
