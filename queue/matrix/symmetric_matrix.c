#include <stdio.h>

#define     N                           10
#define     TRIDIAGONAL_MATRIX_DEFAULT  0
#define     SPARSE_MATRIX_NOT_FOUND     INT_MIN + 1

/*
 * index_row_first_symmetric_matrix - return the array index of a symmetric 
 * matrix (only lower triangular part is stored) that uses compressed storage
 * and adopts the row-major strategy
 *
 * if an error occurs, return -1
 */
int index_row_first_symmetric_matrix(int i, int j) {
    if (i < 0 || j < 0) 
        return -1;
    if (i < j) 
        return index_row_first_symmetric_matrix(j, i);

    return i * (i - 1) / 2 + j - 1;
}

/*
 * index_row_first_triangular_matrix - return the array index of a triangular
 * matrix (only upper triangular part is stored) that uses compressed storage
 * and adopts the row-major strategy
 *
 * if an error occurs, return -1
 */
int index_row_first_triangular_matrix(int i, int j) {
    if (i < 0 || j < 0) 
        return -1;
    if (i < j) 
        return N * (N + 1) / 2;

    return (i - 1) * (2 * N - i + 2) / 2 + j - i;
}

int index_row_first_tridiagonal_matrix(int i, int j) {
    if (i < 0 || j < 0) 
        return -1;
    if (i - j > 1 || j - i > 1)     /* outside the tridiagonal area */
        return TRIDIAGONAL_MATRIX_DEFAULT;
    return 3 * (i - 1) + j - i;
}

typedef struct sparse_matrix_entry {
    int i, j, value;
} sparse_matrix_entry, sparse_matrix;

/*
 * get_form_sparse_matrix - Get the value at (i,j) in the sparse matrix
 *
 * if an error occurs, return -1
 */
int get_form_sparse_matrix(sparse_matrix *sm, 
    int len, int i, int j) {
    int k;

    for (k = 0; k < len; k++) {
        if (sm[k].i == i && sm[k].j == j)
            return sm[k].value;
    }   
    return SPARSE_MATRIX_NOT_FOUND;
}
