#include <stdio.h>
#include <stdlib.h>

float getFloat (char mensaje[])
{
    float numero;

    printf(mensaje);
    scanf("%f", &numero);


    return numero;
}
float areaCirculo (float a)
{
    float area;

    area = 3.14 * a * a;

    return area;
}
