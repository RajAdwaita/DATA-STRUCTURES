class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        n = len(image)
        reversedMatrix = []
        for i in range(n):
            temp = []
            for j in range(n):
                curr = image[i][j]
                if(curr == 1):
                    curr = 0
                elif(curr == 0):
                    curr = 1
                temp.insert(0, curr)
            reversedMatrix.append(temp)
        return reversedMatrix
