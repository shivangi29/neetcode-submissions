class MyHashSet:

    def __init__(self):
        self.buck = [[] for _ in range(1000)]

    def get_hash(self, key: int) -> int:
        return key % 1000

    def add(self, key: int) -> None:
        idx = self.get_hash(key)
        if key not in self.buck[idx]:
            self.buck[idx].append(key)

    def remove(self, key: int) -> None:
        idx = self.get_hash(key)
        if key in self.buck[idx]:
            self.buck[idx].remove(key)

    def contains(self, key: int) -> bool:
        idx = self.get_hash(key)
        return key in self.buck[idx]

# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)