from setuptools import setup, Extension
from Cython.Build import cythonize
import numpy as np

# Create some extension modules
dtw_extension = Extension(
    name="DTW_PyModel",
    sources=["DTW_PyModel.pyx", "DTW_model.c"],  # shall include .pyx and .c file
    include_dirs=[".", np.get_include()],  # Include the header file in the current directory and include directory of numpy
    libraries=["m"],  # like the lm in "gcc -o main main.c -lm"
    language="c",
)

setup(
    name="DTW_model",
    ext_modules=cythonize(dtw_extension),
)