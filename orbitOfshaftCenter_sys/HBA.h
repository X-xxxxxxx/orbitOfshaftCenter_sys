//
// MATLAB Compiler: 8.3 (R2021b)
// Date: Tue Jun 13 16:26:35 2023
// Arguments:
// "-B""macro_default""-W""cpplib:HBA,all,version=1.0""-T""link:lib""-d""C:\User
// s\X_xx\Desktop\softB\matlab\��������Ż�\HBA\HBA\for_testing
// ""-v""C:\Users\X_xx\Desktop\softB\matlab\��������Ż�\HBA\HB
// A.m"
//

#ifndef HBA_h
#define HBA_h 1

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
#ifndef LIB_HBA_C_API 
#define LIB_HBA_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_HBA_C_API 
bool MW_CALL_CONV HBAInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_HBA_C_API 
bool MW_CALL_CONV HBAInitialize(void);

extern LIB_HBA_C_API 
void MW_CALL_CONV HBATerminate(void);

extern LIB_HBA_C_API 
void MW_CALL_CONV HBAPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_HBA_C_API 
bool MW_CALL_CONV mlxHBA(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_HBA
#define PUBLIC_HBA_CPP_API __declspec(dllexport)
#else
#define PUBLIC_HBA_CPP_API __declspec(dllimport)
#endif

#define LIB_HBA_CPP_API PUBLIC_HBA_CPP_API

#else

#if !defined(LIB_HBA_CPP_API)
#if defined(LIB_HBA_C_API)
#define LIB_HBA_CPP_API LIB_HBA_C_API
#else
#define LIB_HBA_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_HBA_CPP_API void MW_CALL_CONV HBA(int nargout, mwArray& best_x, const mwArray& path);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
