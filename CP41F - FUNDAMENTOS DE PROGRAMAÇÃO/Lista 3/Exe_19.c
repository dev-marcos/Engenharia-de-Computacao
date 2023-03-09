/*

19)	Monte o teste de mesa e responda qual o valor final de x, y e z após todas operações.
int x,y,z; x=y=10;
z=++x; x=-x; y++;
x=x+y-(z--);
*/

#include <stdio.h>

int main()
{
    int x, y, z;

    printf("X: %d  Y: %d  Z: %d \n", x, y, z);
    x = y = 10;

    printf("X: %d  Y: %d  Z: %d \n", x, y, z);

    z = ++x;

    printf("X: %d  Y: %d  Z: %d \n", x, y, z);

    x = -x;

    printf("X: %d  Y: %d  Z: %d \n", x, y, z);

    y++;

    printf("X: %d  Y: %d  Z: %d \n", x, y, z);

    x=x+y-(z--);

    printf("X: %d  Y: %d  Z: %d \n", x, y, z);
    return 0;
}
