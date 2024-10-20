#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

inline double distance(double point1, double point2){
    // To compute the L2 norm
    // :param point1: The first point of value
    // :param point2: The second point of value
    // :return: A float of computation result
    return pow((point1 - point2), 2);
}

inline double** assign_matrix(int n_row, int n_col){
    // To malloc the matrix in heap memory structure
    // :param n_row: The row of this two-dim matrix
    // :param n_col: The col of this two-dim matrix
    // :return: A 2-d matrix pointer to pointer
    double **matrix = (double **)malloc(n_row*sizeof(float *));
    for(int i = 0; i < n_row; i++)matrix[i] = (double *)malloc(n_col*sizeof(double));
    return matrix;
}

inline void initialize_matrix(double** matrix, int n_row, int n_col){
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_col; j++)
            matrix[i][j] = DBL_MAX;
    }
    matrix[0][0] = 0.0;
}

inline void print_matrix(double** matrix, int n_row, int n_col){
    printf("\n[");
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_col; j++){
            if(j != n_col-1) printf("%lf, ",matrix[i][j]);
            else printf("%lf",matrix[i][j]);
        }
        if(i != n_row - 1)printf("\n ");
    }
    printf("]\n");
}

inline void free_matrix(double** matrix, int n_row, int n_col){
    for(int i = 0; i < n_row; i++)free(matrix[i]);
    free(matrix);
}

inline double* reindex_arr(double* arr, int st, int ed){
    double *matrix = (double *)malloc((ed - st)*sizeof(double));
    int idx = 0;
    for(int i = st; i < ed; i++){
        matrix[idx] = arr[i];
        idx ++;
    }
    return matrix;
}