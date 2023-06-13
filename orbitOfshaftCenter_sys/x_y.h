//
// MATLAB Compiler: 8.3 (R2021b)
// Date: Tue Jun 13 22:05:55 2023
// Arguments:
// "-B""macro_default""-W""cpplib:x_y,all,version=1.0""-T""link:lib""-d""C:\User
// s\X_xx\Desktop\softB\matlab\ï¿½ì¼£ï¿½ï¿½ï¿½ã´¦ï¿½ï¿½\X,Yï¿½ï¿½ï¿½ï¿½ï¿½Ïµï¿½ï
// ¿½Åºï¿½\x_y\for_testing""-v""C:\Users\X_xx\Desktop\softB\matlab\ï¿½ì¼£ï¿½ï¿½ï
// ¿½ã´¦ï¿½ï¿½\X,Yï¿½ï¿½ï¿½ï¿½ï¿½Ïµï¿½ï¿½Åºï¿½\x_y.m"
//

#ifndef x_y_h
#define x_y_h 1

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
#ifndef LIB_x_y_C_API 
#define LIB_x_y_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_x_y_C_API 
bool MW_CALL_CONV x_yInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_x_y_C_API 
bool MW_CALL_CONV x_yInitialize(void);

extern LIB_x_y_C_API 
void MW_CALL_CONV x_yTerminate(void);

extern LIB_x_y_C_API 
void MW_CALL_CONV x_yPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_x_y_C_API 
bool MW_CALL_CONV mlxX_y(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_x_y
#define PUBLIC_x_y_CPP_API __declspec(dllexport)
#else
#define PUBLIC_x_y_CPP_API __declspec(dllimport)
#endif

#define LIB_x_y_CPP_API PUBLIC_x_y_CPP_API

#else

#if !defined(LIB_x_y_CPP_API)
#if defined(LIB_x_y_C_API)
#define LIB_x_y_CPP_API LIB_x_y_C_API
#else
#define LIB_x_y_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_x_y_CPP_API void MW_CALL_CONV x_y(const mwArray& path1, const mwArray& path2, const mwArray& path3, const mwArray& path4);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
