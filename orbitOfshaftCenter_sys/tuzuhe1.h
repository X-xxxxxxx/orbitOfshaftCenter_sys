//
// MATLAB Compiler: 8.3 (R2021b)
// Date: Tue Jun 13 22:22:48 2023
// Arguments:
// "-B""macro_default""-W""cpplib:tuzuhe1,all,version=1.0""-T""link:lib""-d""C:\
// Users\X_xx\Desktop\softB\matlab\���������ں�\͹���\
// tuzuhe1\for_testing""-v""C:\Users\X_xx\Desktop\softB\matlab\������
// ����ں�\͹���\tuzuhe1.m"
//

#ifndef tuzuhe1_h
#define tuzuhe1_h 1

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
#ifndef LIB_tuzuhe1_C_API 
#define LIB_tuzuhe1_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_tuzuhe1_C_API 
bool MW_CALL_CONV tuzuhe1InitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_tuzuhe1_C_API 
bool MW_CALL_CONV tuzuhe1Initialize(void);

extern LIB_tuzuhe1_C_API 
void MW_CALL_CONV tuzuhe1Terminate(void);

extern LIB_tuzuhe1_C_API 
void MW_CALL_CONV tuzuhe1PrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_tuzuhe1_C_API 
bool MW_CALL_CONV mlxTuzuhe1(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_tuzuhe1
#define PUBLIC_tuzuhe1_CPP_API __declspec(dllexport)
#else
#define PUBLIC_tuzuhe1_CPP_API __declspec(dllimport)
#endif

#define LIB_tuzuhe1_CPP_API PUBLIC_tuzuhe1_CPP_API

#else

#if !defined(LIB_tuzuhe1_CPP_API)
#if defined(LIB_tuzuhe1_C_API)
#define LIB_tuzuhe1_CPP_API LIB_tuzuhe1_C_API
#else
#define LIB_tuzuhe1_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_tuzuhe1_CPP_API void MW_CALL_CONV tuzuhe1(const mwArray& path, const mwArray& path1);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
