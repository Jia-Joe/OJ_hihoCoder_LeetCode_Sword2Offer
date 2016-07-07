class Solution {
public:
    int Add(int a, int b)
    {
        int c = a&b, d = a^b;
        while (c)
        {
            int cx = c << 1;
            c = d&cx;
            d = d^cx;
        }
        return d;
    }
};

int Add(int num1, int num2)
{
	if(num2==0)
		return num1;
	return Add(num1^num2, (num1&num2)<<1);
}