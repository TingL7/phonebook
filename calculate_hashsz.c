#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    FILE *output = fopen("output.txt", "w");
    if(!output) {
        printf("ERRPR opening output file output.txt");
        exit(0);
    }
    int i = 0;
    char append[50], find[50];
    double sum_a[6], sum_f[6], a, f;
    int num = 0;
    char fileName[20];

    for(i = 0; i < 5; i++) {
        sum_a[i] = 0.0;
        sum_f[i] = 0.0;
    }

    for(num = 1; num < 7; num++) {
        if(num == 1)
            sprintf(fileName, "orig.txt");
        else
            sprintf(fileName, "hash%d.txt", num);
        fp = fopen(fileName, "r");
        if (!fp) {
            printf("ERROR opening input file %s\n",fileName);
            exit(0);
        }
        for (i = 0; i < 100; i++) {
            if (feof(fp)) {
                printf("ERROR: You need 100 datum instead of %d\n", i);
                printf("run 'make run' longer to get enough information\n\n");
                exit(0);
            }
            fscanf(fp, "%s %s %lf %lf\n", append, find, &a, &f);
            sum_a[num-1] += a;
            sum_f[num-1] += f;
        }
        fclose(fp);
    }

    fprintf(output, "append() %lf %lf %lf %lf %lf %lf\n",sum_a[0] / 100.0, sum_a[1] / 100.0, sum_a[2] / 100.0, sum_a[3] / 100.0, sum_a[4] / 100.0, sum_a[5] / 100.0);
    fprintf(output, "findName() %lf %lf %lf %lf %lf %lf", sum_f[0] / 100.0, sum_f[1] / 100.0, sum_f[2] / 100.0, sum_f[3] / 100.0, sum_f[4] / 100.0, sum_f[5] /100.0);
    fclose(output);
    //fclose(fp);
    return 0;
}
