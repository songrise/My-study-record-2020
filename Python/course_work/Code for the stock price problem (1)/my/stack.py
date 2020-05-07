class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def hasItem(self):
        return self.items != []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        """return the top element of a stack"""
        return self.items[len(self.items)-1]

    def size(self):
        """return the height of stack"""
        return len(self.items)
