class MyHashMap:

    def __init__(self):
        self.idx = bytearray(1000002)
        self.val = [0] * 1000002

    def put(self, key: int, value: int) -> None:
        self.idx[key] = 1
        self.val[key] = value
    
    def get(self, key: int) -> int:
        if self.idx[key] == 0:
            return -1
        return self.val[key]

    def remove(self, key: int) -> None:
        self.idx[key] = 0


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)