import numpy as np
cimport numpy as cnp
from cpython.mem cimport PyMem_Malloc, PyMem_Free

# distutils: language = c

cdef extern from "DTW_model.c":
    double best_match(double *query, double *serie, int lenQ, int lenS);

def best_match(list query, list serie):
    # Assign array length and arraies element
    cdef int lenQ = len(query)
    cdef int lenS = len(serie)
    cdef double* c_query = <double *>PyMem_Malloc(lenQ*sizeof(double))
    cdef double* c_serie = <double *>PyMem_Malloc(lenS*sizeof(double))

    # Copy python list values to c_array
    for i in range(lenQ):
        c_query[i] = query[i]
    for i in range(lenS):
        c_serie[i] = serie[i]

    # C function call
    # cdef double res = best_match(c_query, c_serie, lenQ, lenS)
    print(res)

    # Free memory allocation
    PyMem_Free(c_query)
    PyMem_Free(c_serie)

    # Return values
    return res