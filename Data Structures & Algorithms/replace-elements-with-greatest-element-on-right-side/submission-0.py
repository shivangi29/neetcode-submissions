class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        lar = arr[len(arr)-1]
        arr[-1] = -1
        for i in range(len(arr)-2, -1, -1):
            temp = lar
            if arr[i] > lar:
                lar = arr[i]
            arr[i] = temp
        return arr

            