class MyHashMap:

    def __init__(self):
        # Fixed the syntax error by removing the extra comma
        self.idx = [[] for _ in range(1000)]

    def put(self, key: int, value: int) -> None:
        index = key % 1000
        # Check if the key already exists to update it
        for pair in self.idx[index]:
            if pair[0] == key:
                pair[1] = value
                return
        # If the key is new, append it
        self.idx[index].append([key, value])
       
    def get(self, key: int) -> int:
        index = key % 1000
        # Search for the key in the bucket
        for pair in self.idx[index]:
            if pair[0] == key:
                return pair[1]
        # Return -1 if the key does not exist
        return -1

    def remove(self, key: int) -> None:
        index = key % 1000
        # Search and remove the key-value pair if found
        for i, pair in enumerate(self.idx[index]):
            if pair[0] == key:
                self.idx[index].pop(i)
                return
