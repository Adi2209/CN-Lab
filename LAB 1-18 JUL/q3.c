#include <stdio.h>
int main()
{
    int n = 258;

    for (int i = 0; i < sizeof(n); i++)
    {
        unsigned char byte = *((unsigned char *)&n + i);
        printf("Byte %d=%u\n", i, (unsigned)byte);
    }
    return 0;
}