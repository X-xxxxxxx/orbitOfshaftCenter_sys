//
// MATLAB Compiler: 8.3 (R2021b)
// Date: Tue Jun 13 17:17:07 2023
// Arguments:
// "-B""macro_default""-W""cpplib:my_bianyuantu,all,version=1.0""-T""link:lib""-
// d""C:\Users\X_xx\Desktop\softB\matlab\Í¼ï¿½ï¿½ï¿½ï¿½\ï¿½ï¿½Ôµï¿½ï¿½ï¿½ï¿½ï¿½ï
// ¿½ï¿½ï¿½\my_bianyuantu\for_testing""-v""C:\Users\X_xx\Desktop\softB\matlab\Í¼
// ï¿½ï¿½ï¿½ï¿½\ï¿½ï¿½Ôµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½\my_bianyuantu.m"
//

#ifndef my_bianyuantu_h
#define my_bianyuantu_h 1

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
#ifndef LIB_my_bianyuantu_C_API 
#define LIB_my_bianyuantu_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_my_bianyuantu_C_API 
bool MW_CALL_CONV my_bianyuantuInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_my_bianyuantu_C_API 
bool MW_CALL_CONV my_bianyuantuInitialize(void);

extern LIB_my_bianyuantu_C_API 
void MW_CALL_CONV my_bianyuantuTerminate(void);

extern LIB_my_bianyuantu_C_API 
void MW_CALL_CONV my_bianyuantuPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_my_bianyuantu_C_API 
bool MW_CALL_CONV mlxMy_bianyuantu(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_my_bianyuantu
#define PUBLIC_my_bianyuantu_CPP_API __declspec(dllexport)
#else
#define PUBLIC_my_bianyuantu_CPP_API __declspec(dllimport)
#endif

#define LIB_my_bianyuantu_CPP_API PUBLIC_my_bianyuantu_CPP_API

#else

#if !defined(LIB_my_bianyuantu_CPP_API)
#if defined(LIB_my_bianyuantu_C_API)
#define LIB_my_bianyuantu_CPP_API LIB_my_bianyuantu_C_API
#else
#define LIB_my_bianyuantu_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_my_bianyuantu_CPP_API void MW_CALL_CONV my_bianyuantu(const mwArray& path, const mwArray& path1);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
