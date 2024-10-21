#include <stdio.h>
#include <math.h>

#define MAXNUM 10000000

int main()
{
    int n;
    int ca = 0; 	/* count of abudant */
    int cu = 0; 	/* count of unique childs */
    int cb = 0; 	/* count of both */
    int base = 10; 	/* defines limit where count of digits increases */
    int c = 1; 		/* count of digits */
    int e = 0, f = 0;

    for(n = 1; n <= MAXNUM; n++)
    {
        int isa = 0;
        int x;
        int p, i, j, s;
        
        if (n >= base) 
		{
			c++;
			base *= 10;
		}
        
        s = 1;
        for (j = 2; j*j < n; j++)
        {
            if (n % j == 0)
            {
                s += (j + n/j);
                if (s > n)
                {
                    ca++;
                    isa = 1;
                    break;
                }
            }
        }
		if (j*j == n && isa != 1)
		{
		    s += j;
            if (s > n)
            {
                ca++;
                isa = 1;
            }
        }
        if (n % 100 == 0) continue;
        if (f == 2 && n <= e) continue;
        
        x = 0;
        p = 1;
        for (i = 1; i <= c && x <= 1; i++)
        {
        	int t = n;

            p = p * 10;
            for (j = i; j <= c && x <= 1; j++)
            {
                int d;
                
                d = t % p;
                if (d %c == 0)
                {
					if (i == 1 && x == 0 && j != 1)
					{
						e = n + ((int)pow(10, j-1) - n % (int)pow(10, j-1)) -d;
						f = 1;
					}
                	x++;
				}
				t = t / 10;
            }
			if (x == 2 && f == 1)
			{
				f = 2;
			}
			else
			{
				f = 0;
			}
        }
        if (x == 1)
        {
            cu++;
            if (isa == 1)
            {
                cb++;
                printf("unique and abudant: %d\n", n);
            }
        }
    }
    printf("cp = %d cu = %d cb = %d\n", ca, cu, cb);

    return 0;
}
