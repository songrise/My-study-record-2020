class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        len_ = len(rooms)
        enterable = [False]*len_
        enterable[0] = True
        queue = [0]
        while len(queue):
            level = len(queue)
            for i in range(level):
                key = rooms[queue.pop(0)]  # key is a list
                lenkey = len(key)

                for j in range(lenkey):  # update enterable arr.
                    if not enterable[key[j]]:
                        queue.append(key[j])
                    enterable[key[j]] = True

        return all(enterable)
