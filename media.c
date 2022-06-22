#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    FILE *fp;
    int N = 0;
    double x = 0.0, m_X = 0.0, y = 0.0, m_Y = 0.0;
    char *entrada = (char*)malloc(255 * (sizeof(char)));

    fp = fopen("table.txt", "r");
    if (fp == NULL) {
        printf("ERRO!\n");
        exit(1);
    }
    printf("\n");
    char *status = fgets(entrada, 255, fp);
    while (status) {
        N++;
        sscanf(entrada, "%lf \t %lf", &x, &y);
        printf("N = %d: x = %lf, y = %lf\n", N, x, y);
        m_X += x;
        m_Y += y;
        status = fgets(entrada, 255, fp);
    }
    m_X /= N;
    m_Y /= N;
    printf("m_X = %lf\nm_Y = %lf\n", m_X, m_Y);
    return 0;
}
