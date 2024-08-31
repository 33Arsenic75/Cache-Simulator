#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  TESTCASES 100
#define  START  500


void generate_random_matrix(int n, double **matrix) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX; // Random value between 0 and 1
        }
    }
}

void generate_zero_matrix(int n, double **matrix) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

void show_matrix(int n, double **matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices_order1(int n, double** A, double** B, double** C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiply_matrices_order2(int n, double** A, double** B, double** C) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiply_matrices_order3(int n, double** A, double** B, double** C) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiply_matrices_order4(int n, double** A, double** B, double** C) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiply_matrices_order5(int n, double** A, double** B, double** C) {
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiply_matrices_order6(int n, double** A, double** B, double** C) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transpose_inplace(int n, double**mat,double**dummy1,double**dummy2) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}/// 3n^2/2

void transpose_with_array(int n, double**mat, double**res,double**dummy1) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[j][i] = mat[i][j];
        }
    }
}/// n^2

double measure_execution_time(int n, void (*function)(int, double**, double**, double**), double** A, double** B, double** C) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    function(n, A, B, C);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

void help1(int n){
    double **A = (double **)malloc(n * sizeof(double *));
    double **B = (double **)malloc(n * sizeof(double *));
    double **C = (double **)malloc(n * sizeof(double *));

    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
        B[i] = (double *)malloc(n * sizeof(double));
        C[i] = (double *)malloc(n * sizeof(double));
    }
    generate_random_matrix(n, A);
    generate_random_matrix(n, B);
    generate_zero_matrix(n, C);
    float time1 = measure_execution_time(n, multiply_matrices_order1, A, B, C);
    float time2 = measure_execution_time(n, multiply_matrices_order2, A, B, C);
    float time3 = measure_execution_time(n, multiply_matrices_order3, A, B, C);
    float time4 = measure_execution_time(n, multiply_matrices_order4, A, B, C);
    float time5 = measure_execution_time(n, multiply_matrices_order5, A, B, C);
    float time6 = measure_execution_time(n, multiply_matrices_order6, A, B, C);
    printf("%d,%f,%f,%f,%f,%f,%f\n", n,time1,time2,time3,time4,time5,time6);
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}


void help2(int n){
    double **A = (double **)malloc(n * sizeof(double *));
    double **B = (double **)malloc(n * sizeof(double *));
    double **C = (double **)malloc(n * sizeof(double *));

    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
        B[i] = (double *)malloc(n * sizeof(double));
        C[i] = (double *)malloc(n * sizeof(double));
    }
    generate_random_matrix(n, A);
    generate_random_matrix(n, B);
    generate_zero_matrix(n, C);
    float time7 = measure_execution_time(n, transpose_inplace  , A, B, C);
    float time8 = measure_execution_time(n, transpose_with_array, A, B, C);
    printf("%d,%f,%f\n", n,time7,time8);
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number> <type>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    int typ = atoi(argv[2]);
    if(typ==1){
        help1(n);
    }
    else if(typ==2){
        help2(n);
    }
    printf("Size of double: %zu bytes\n", sizeof(double));

    return 0;
}

