class Solution:
    def destCity(self, paths: List[List[str]]) -> str:

        allpath = []
        toPath = []

        for i in range(0, len(paths)):
            allpath.append(paths[i][0])
            allpath.append(paths[i][1])
            toPath.append(paths[i][0])
            
        for i in range(0, len(allpath)):
            if allpath[i] not in toPath:
                return allpath[i]
