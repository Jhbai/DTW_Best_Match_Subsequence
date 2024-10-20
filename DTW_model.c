#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include "common_func.h"
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN3(a, b, c) (MIN(MIN(a, b), c))

extern inline double distance(double point1, double point2);
extern inline double** assign_matrix(int n_row, int n_col);
extern inline void initialize_matrix(double** matrix, int n_row, int n_col);
extern inline void free_matrix(double** matrix, int n_row, int n_col);
extern inline void print_matrix(double** matrix, int n_row, int n_col);
extern inline double* reindex_arr(double* arr, int st, int ed);

double dtw(double *query, double *serie, int lenQ, int lenS){
    double **dtw_matrix = assign_matrix((lenQ + 1), (lenS + 1));
    initialize_matrix(dtw_matrix, (lenQ + 1), (lenS + 1));

    for(int i = 1; i < (lenQ+1); i++){
        for(int j = 1; j < (lenS+1); j++){
            double cost = distance(query[i-1], serie[j-1]);
            dtw_matrix[i][j] = cost + MIN3(dtw_matrix[i-1][j], dtw_matrix[i][j-1], dtw_matrix[i-1][j-1]);
        }
    }
    double res = dtw_matrix[lenQ][lenS];
    free_matrix(dtw_matrix, lenQ+1, lenS+1);
    return sqrt(res);
}

double _dtw(double *query, double *serie, int lenQ, int lenS){
    double **dtw_matrix = assign_matrix((lenQ + 1), (lenS + 1));
    initialize_matrix(dtw_matrix, (lenQ + 1), (lenS + 1));

    for(int i = 1; i < (lenQ+1); i++){
        for(int j = 1; j < (lenS+1); j++){
            double cost = distance(query[i-1], serie[j-1]);
            dtw_matrix[i][j] = cost + MIN3(dtw_matrix[i-1][j], dtw_matrix[i][j-1], dtw_matrix[i-1][j-1]);
        }
    }
    double res = DBL_MAX;
    for(int i = 0; i < (lenS+1); i++){
        if(res > dtw_matrix[lenQ][i]){
            res = dtw_matrix[lenQ][i];
        }
    }
    free_matrix(dtw_matrix, lenQ+1, lenS+1);
    return sqrt(res);
}

double best_match(double *query, double *serie, int lenQ, int lenS){
    double min_dtw_distance = DBL_MAX;
    double *arr;
    // Find query in subpattern of serie
    for(int i = 0; i < lenS; i++){
         arr = reindex_arr(serie, i, lenS);
         double current_value = _dtw(query, arr, lenQ, lenS-i);
         if (current_value < min_dtw_distance){
            min_dtw_distance = current_value;
         }
    }
    return min_dtw_distance;
}
