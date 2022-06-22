#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main () {
        FILE *fp;

    int N = 0;

    double x = 0.0, m_X = 0.0, y = 0.0, m_Y = 0.0, a = 0.0, b = 0.0, dY = 0.0;
    double sum = 0.0;

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
            status = fgets(entrada, 255, fp);
            sscanf(entrada, "a = %lf", &a);
            status = fgets(entrada, 255, fp);
            sscanf(entrada, "b = %lf", &b);
            printf("m_X = %lf, m_Y = %lf\na = %lf, b = %lf\n\n", m_X, m_Y, a, b);
            N++;
        } else {
            if(strcmp(entrada, "\n") != 0) {
                sscanf(entrada, "%lf \t %lf", &x, &y);
                printf("N = %d: x = %lf, y = %lf\n", N, x, y);
                N++;
                sum += (a * x + b - y) * (a * x + b - y);
            }
        }
        status = fgets(entrada, 255, fp);
    }
    dY = sqrt(sum / (N - 2));
    printf("\ndY = %lf\n", dY);
    return 0;
}
