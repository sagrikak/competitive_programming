#include <stdio.h>
#include <stdlib.h>

int main()
{
    double mealCost;
    int tipPercent, taxPercent, totalCost;
    scanf("%lf%d%d", &mealCost, &tipPercent, &taxPercent);

    totalCost = round(mealCost + ((double)tipPercent/100)*mealCost + ((double)taxPercent/100)*mealCost);

    printf("The total meal cost is %d dollars.", totalCost);
    return 0;
}
