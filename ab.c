#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main () {
    FILE *fp;

    int N = 0;

    double x = 0.0, m_X = 0.0, y = 0.0, m_Y = 0.0, a = 0.0, b = 0.0;
    double x_deviation = 0.0;
    double x_deviation_y = 0.0;

    char *entrada = (char*)malloc(255 * (sizeof(char)));

    fp = fopen("table.txt", "r");
    if (fp == NULL) {
        printf("ERRO!\n");
        exit(1);
    }
    printf("\n");
    char *status = fgets(entrada, 255, fp);
    while (status) {
        if(N ==  0) {
            sscanf(entrada, "m_X = %lf", &m_X);
            status = fgets(entrada, 255, fp);
            sscanf(entrada, "m_Y = %lf", &m_Y);
            printf("m_X = %lf, m_Y = %lf\n\n", m_X, m_Y);
            N++;
        } else {
            if(strcmp(entrada, "\n") != 0) {
                sscanf(entrada, "%lf \t %lf", &x, &y);
                printf("N = %d: x = %lf, y = %lf / x - m_X = %lf\n", N, x, y, (x - m_X));
                N++;
                double x_mX = (x - m_X);
                x_deviation += (x_mX * x_mX);
                x_deviation_y += (x_mX * y);
            }
        }
        status = fgets(entrada, 255, fp);
    }

    printf("\nx_deviation = %lf, x_deviation_y = %lf\n\n", x_deviation, x_deviation_y);

    if((int) x_deviation != 0) {
        a =  (x_deviation_y / x_deviation);
    } else {
        a =  x_deviation_y;
    }
    b = (m_Y - (a * m_X));
    printf("a = %lf\nb = %lf\n", a, b);
    return 0;
} 
 /*
    mY = 24.92
    mX = 5

1
4.9
3
14.2
5
26.2
7
34.6
9
44.7
 */