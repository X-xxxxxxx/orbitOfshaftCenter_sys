//
// MATLAB Compiler: 8.3 (R2021b)
// Date: Sat May 27 17:10:06 2023
// Arguments:
// "-B""macro_default""-W""cpplib:mydlladd""-T""link:lib""eval_test.m"
//

#ifndef mydlladd_h
#define mydlladd_h 1

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
#ifndef LIB_mydlladd_C_API 
#define LIB_mydlladd_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_mydlladd_C_API 
bool MW_CALL_CONV mydlladdInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_mydlladd_C_API 
bool MW_CALL_CONV mydlladdInitialize(void);

extern LIB_mydlladd_C_API 
void MW_CALL_CONV mydlladdTerminate(void);

extern LIB_mydlladd_C_API 
void MW_CALL_CONV mydlladdPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_mydlladd_C_API 
bool MW_CALL_CONV mlxEval_test(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_mydlladd
#define PUBLIC_mydlladd_CPP_API __declspec(dllexport)
#else
#define PUBLIC_mydlladd_CPP_API __declspec(dllimport)
#endif

#define LIB_mydlladd_CPP_API PUBLIC_mydlladd_CPP_API

#else

#if !defined(LIB_mydlladd_CPP_API)
#if defined(LIB_mydlladd_C_API)
#define LIB_mydlladd_CPP_API LIB_mydlladd_C_API
#else
#define LIB_mydlladd_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_mydlladd_CPP_API void MW_CALL_CONV eval_test(int nargout, mwArray& c, mwArray& d, const mwArray& a, const mwArray& b);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
