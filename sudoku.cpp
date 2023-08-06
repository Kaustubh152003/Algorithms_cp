#define n 9
class Solution 
{
    public:
    int get_dabba(int x,int y)
    {
        if(x/3<1)
        {
            if(y/3<1)
            return 0;
            else
            {
                if(y/3<2)
                return 1;
                else
                return 2;
            }
        }
        else
        {
            if(x/3<2)
            {
                if(y/3<1)
                return 3;
                else
                {
                    if(y/3<2)
                    return 4;
                    else
                    return 5;
                }
            }
            else
            {
                if(y/3<1)
                return 6;
                else
                {
                    if(y/3<2)
                    return 7;
                    else
                    return 8;
                }
            }
        }
    }
    int everything_filled(int grid[N][N])
    {
        int j=0;
        while(j<n)
        {
            int k=0;
            while(k<n && grid[j][k]!=0)
            k++;
            if(k!=n)
            break;
            j++;
            
        }
        if(j==n)
        return 1;
        else
        return 0;
    }
    int validate(int row[n][n],int col[n][n],int dabba[n][n])
    {
        int j=0;
        while(j<n)
        {
            int k=0;
            while(k<n && row[j][k]<=1 && col[j][k]<=1 && dabba[j][k]<=1)
            k++;
            if(k!=n)
            break;
            j++;
            
        }
        if(j==n)
        return 1;
        else
        return 0;
    }
    void copy_grid(int newgrid[n][n],int grid[n][n])
    {
        int j=0;
        while(j<n)
        {
            int k=0;
            while(k<n)
            {
                newgrid[j][k]=grid[j][k];
                k++;
            }
            j++;
        }
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    {
        
        {
            int row[n][n];
            int col[n][n];
            int dabba[n][n];
            int j=0;
            while(j<n)
            {
                int k=0;
                while(k<n)
                {
                    row[j][k]=0;
                    col[j][k]=0;
                    dabba[j][k]=0;
                    k++;
                }
                j++;
            }
            j=0;
            while(j<n)
            {
                int k=0;
                while(k<n)
                {
                    if(grid[j][k]!=0)
                    {
                        row[j][grid[j][k]-1]++;
                        col[k][grid[j][k]-1]++;
                        int dv=get_dabba(j,k);
                        dabba[dv][grid[j][k]-1]++;
                    }
                    k++;
                }
                j++;
            }
            if(validate(row,col,dabba)==1)
            {
                int j=0;
                while(j<n)
                {
                    int k=0;
                    while(k<n && grid[j][k]!=0)
                    k++;
                    if(k<n)
                    {
                        int newgrid[n][n];
                        copy_grid(newgrid,grid);
                        int x=1;
                        while(x<=9)
                        {
                            if(row[j][x-1]==0 && col[k][x-1]==0 && dabba[get_dabba(j,k)][x-1]==0)
                            {
                                newgrid[j][k]=x;
                                if(SolveSudoku(newgrid)==true)
                                {
                                    copy_grid(grid,newgrid);
                                    return true;
                                }
                            }
                            x++;
                        }
                        if(x==10)
                        return false;
                    }
                    j++;
                }
                if(j==n)
                return true;
                else
                return false;
                
            }
            else
            {
                return false;
            }
        }
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        int j=0;
        while(j<n)
        {
            int k=0;
            while(k<n)
            {
                printf("%d ",grid[j][k]);
                k++;
            }
            // printf("\n");
            j++;
        }
    }
};
