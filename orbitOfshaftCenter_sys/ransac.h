//
// MATLAB Compiler: 8.3 (R2021b)
// Date: Sat May 27 21:58:26 2023
// Arguments:
// "-B""macro_default""-W""cpplib:ransac,all,version=1.0""-T""link:lib""-d""C:\U
// sers\X_xx\Desktop\ï¿½ï¿½Ê¦ï¿½ï¿½\ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½\ransac\for
// _testing""-v""C:\Users\X_xx\Desktop\ï¿½ï¿½Ê¦ï¿½ï¿½\ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿
// ½ï¿½ï¿½\ransac.m"
//

#ifndef ransac_h
#define ransac_h 1

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
#ifndef LIB_ransac_C_API 
#define LIB_ransac_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_ransac_C_API 
bool MW_CALL_CONV ransacInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_ransac_C_API 
bool MW_CALL_CONV ransacInitialize(void);

extern LIB_ransac_C_API 
void MW_CALL_CONV ransacTerminate(void);

extern LIB_ransac_C_API 
void MW_CALL_CONV ransacPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_ransac_C_API 
bool MW_CALL_CONV mlxRansac(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_ransac
#define PUBLIC_ransac_CPP_API __declspec(dllexport)
#else
#define PUBLIC_ransac_CPP_API __declspec(dllimport)
#endif

#define LIB_ransac_CPP_API PUBLIC_ransac_CPP_API

#else

#if !defined(LIB_ransac_CPP_API)
#if defined(LIB_ransac_C_API)
#define LIB_ransac_CPP_API LIB_ransac_C_API
#else
#define LIB_ransac_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_ransac_CPP_API void MW_CALL_CONV ransac(int nargout, mwArray& d, const mwArray& x);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
