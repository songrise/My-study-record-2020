class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        adjacency = []
        #init adjacency table
        invalid = len(arr)
        for i in range(len(arr)):
            left = i - arr[i] if i - arr[i] > 0  else invalid
            right = i + arr[i] if i - arr[i] < invalid else invalid
            adjacency.append([left,right])

        stack = [start]
        while stack:
            node = stack.pop(-1)
            if node == 0:
                return True
            for next_node in adjacency[node]:
                if next_node != invalid:
                    stack.append(next_node)

        return False