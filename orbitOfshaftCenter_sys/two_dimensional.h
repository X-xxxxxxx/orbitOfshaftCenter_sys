//
// MATLAB Compiler: 8.3 (R2021b)
// Date: Tue Jun 13 21:49:42 2023
// Arguments:
// "-B""macro_default""-W""cpplib:two_dimensional,all,version=1.0""-T""link:lib"
// "-d""C:\Users\X_xx\Desktop\softB\matlab\�켣���㴦��\��ά\two
// _dimensional\for_testing""-v""C:\Users\X_xx\Desktop\softB\matlab\�켣��
// �㴦��\��ά\two_dimensional.m"
//

#ifndef two_dimensional_h
#define two_dimensional_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" { // sbcheck:ok:extern_c
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_two_dimensional_C_API 
#define LIB_two_dimensional_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_two_dimensional_C_API 
bool MW_CALL_CONV two_dimensionalInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_two_dimensional_C_API 
bool MW_CALL_CONV two_dimensionalInitialize(void);

extern LIB_two_dimensional_C_API 
void MW_CALL_CONV two_dimensionalTerminate(void);

extern LIB_two_dimensional_C_API 
void MW_CALL_CONV two_dimensionalPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_two_dimensional_C_API 
bool MW_CALL_CONV mlxTwo_dimensional(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                     *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_two_dimensional
#define PUBLIC_two_dimensional_CPP_API __declspec(dllexport)
#else
#define PUBLIC_two_dimensional_CPP_API __declspec(dllimport)
#endif

#define LIB_two_dimensional_CPP_API PUBLIC_two_dimensional_CPP_API

#else

#if !defined(LIB_two_dimensional_CPP_API)
#if defined(LIB_two_dimensional_C_API)
#define LIB_two_dimensional_CPP_API LIB_two_dimensional_C_API
#else
#define LIB_two_dimensional_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_two_dimensional_CPP_API void MW_CALL_CONV two_dimensional(const mwArray& path1, const mwArray& path2, const mwArray& path3, const mwArray& path4);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
