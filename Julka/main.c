#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    int64_t x, t, m;
    int i;
    for(i=0; i<10; i++)
    {
        scanf("%" PRIu64"%" PRIu64"", &t, &m);
        x=(t-m)/2;
        printf("%" PRIu64"\n%" PRIu64"\n", x+m, x);
    }
    return 0;
}
