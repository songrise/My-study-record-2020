class LRUCache:

    def __init__(self, capacity: int):
        self.queue = []
        self.kv = {}
        self.capacity = capacity

    def get(self, key: int) -> int:
        try:
            value = self.kv[key]
            self.queue.append(self.queue.pop(
                self.queue.index(key)))  # pop to queue head
            return value
        except:
            return -1
        finally:
            print(self.kv, self.capacity)

    def put(self, key: int, value: int) -> None:

        if key not in self.kv.keys():  # new entry
            if self.capacity > 0:
                self.kv[key] = value
                self.capacity -= 1
                self.queue.append(key)
            else:  # decide the victim, len(self.kv) == self.capacity:
                i = self.queue.pop(0)  # queue tail is the least recent used
                self.kv.pop(i)
                self.kv[key] = value
                self.queue.append(key)

        else:  # already exists, update value and used status
            self.kv[key] = value
            self.queue.append(self.queue.pop(
                self.queue.index(key)))  # pop to queue head


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
