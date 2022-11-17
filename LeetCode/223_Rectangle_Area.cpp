class Solution 
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        int x1 = max(ax1, bx1);
        int y1 = max(ay1, by1);
        int x2 = min(ax2, bx2);
        int y2 = min(ay2, by2);
        int x = x2 - x1;
        x = (x > 0 ? x : 0);
        int y = y2 - y1;
        y = (y > 0 ? y : 0);
        return (ax2-ax1) * (ay2-ay1) + (bx2-bx1) * (by2-by1) - x * y;
    }
}