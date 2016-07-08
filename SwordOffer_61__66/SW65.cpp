class Solution {
public:
    bool hp(char* matrix, int rows, int cols, char* str,int r,int c,int p, bool *mk)
    {
        int y = r, x = c, pt = p;
        if (c >= cols) { y = r + 1; x = 0; }
        if (c < 0) { y = r - 1; x = cols - 1; }
        if (y >= rows || y < 0) return false;

        int id = y*cols + x;
        if (matrix[id] != str[pt]||mk[id])
            return false;
        else if (str[++pt] == '\0')
            return true;
        mk[id] = true;
        bool f = hp(matrix, rows, cols, str, y, x + 1, pt, mk) ||
            hp(matrix, rows, cols, str, y, x - 1, pt, mk) ||
            hp(matrix, rows, cols, str, y + 1, x, pt, mk) || 
            hp(matrix, rows, cols, str, y - 1, x, pt, mk);
        mk[id] = false;
        return f;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (str == NULL || rows <= 0 || cols <= 0)
            return false;
        bool *mark = new bool[rows*cols]();
        for (int i = 0; i < rows; i++)
        {
            for (int k = 0; k < cols; k++)
            {
                //bool mark[160] = { true };
                if (hp(matrix, rows, cols, str, i, k, 0, mark))
                {
                    delete[]mark;
                    return true;
                }
            }
        }
        delete []mark;
        return false;
    }

};