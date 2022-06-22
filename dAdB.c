#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main () {
        FILE *fp;

    int N = 0;

    double x = 0.0, m_X = 0.0, y = 0.0, m_Y = 0.0, a = 0.0, b = 0.0, dY = 0.0, dA = 0.0, dB = 0.0;
    double sum = 0.0, sum_p_2 = 0.0, x_sqr_sum = 0.0, x_sqr_deviation = 0.0;

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
            status = fgets(entrada, 255, fp);
            sscanf(entrada, "dY = %lf", &dY);
            printf("m_X = %lf, m_Y = %lf\na = %lf, b =%lf\ndY = %lf\n\n", m_X, m_Y, a, b, dY);
            N++;
        } else {
            if(strcmp(entrada, "\n") != 0) {
                sscanf(entrada, "%lf \t %lf", &x, &y);
                printf("N = %d: x = %lf, y = %lf\n", N, x, y);
                N++;
                sum_p_2 = x - m_X;
                sum += sum_p_2 * sum_p_2;
                x_sqr_sum += x * x;
                x_sqr_deviation += (x - m_X) * (x - m_X);
            }
        }
        status = fgets(entrada, 255, fp);
    }

    if ((int) sum != 0) {
         dA = (dY / sqrt(sum));
    } else {
        dA = dY;
    }

    if ((int) x_sqr_deviation != 0) {
        dB = (sqrt(x_sqr_sum / (N * x_sqr_deviation)) * dY);
    } else {
        dB = sqrt(x_sqr_sum/ N) * dY;
    }
       
    printf("\ndA = %lf\ndB = %lf\n", dA, dB);
    return 0;
}
