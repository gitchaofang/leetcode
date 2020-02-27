class Solution(object):
    def numIslands(self, grid):
        row = len(grid)
        if(row == 0):
            return 0
        col = len(grid[0])
        res = 0
        dire = [[0,-1],[-1,0],[0,1],[1,0]]
        for i in range (0,row):
            for j in range (0,col):
                if(grid[i][j] == '0'):
                    continue
                q = [[i,j]]
                res += 1
                while(len(q)!=0):
                    n = len(q)
                    for k in range (0,n):
                        p = q.pop(0)
                        for di in dire:
                            x = di[0] + p[0]
                            y = di[1] + p[1]
                            if(x<0 or x>=row or y<0 or y>=col or grid[x][y] == '0'):                                continue
                            q.append([x,y])
                            grid[x][y] = '0'
                
        return res
