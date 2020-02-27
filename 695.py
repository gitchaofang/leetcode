class Solution(object):
    def maxAreaOfIsland(self, grid):
        row = len(grid)
        col = len(grid[0])
        res = 0;
        dire = [[0,-1],[-1,0],[0,1],[1,0]]
        for i in range(0,row):
            for j in range(0,col):
                if(grid[i][j] == 0): 
                    continue;
                grid[i][j] = 0
                q = [[i,j]]
                cnt = 0
                while(len(q) != 0):
                    n = len(q)
                    cnt += n
                    for k in range(0,n):
                        p = q.pop(0)
                        for di in dire:
                            x = di[0] + p[0]
                            y = di[1] + p[1]
                            if(x<0 or x>=row or y<0 or y>=col or grid[x][y] == 0):
                                continue;                         
                            grid[x][y] = 0
                            q.append([x,y]);
                res = max(res,cnt)
        return res
    
