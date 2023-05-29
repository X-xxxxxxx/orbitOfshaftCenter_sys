//
// MATLAB Compiler: 8.3 (R2021b)
// Date: Mon May 29 11:07:18 2023
// Arguments:
// "-B""macro_default""-W""cpplib:data_resolve,all,version=1.0""-T""link:lib""-d
// ""C:\Users\X_xx\Desktop\ï¿½ï¿½Ê¦ï¿½ï¿½\ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½\data
// _resolve\for_testing""-v""C:\Users\X_xx\Desktop\ï¿½ï¿½Ê¦ï¿½ï¿½\ï¿½ï¿½ï¿½ï¿½ï¿
// ½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½\data_resolve.m"
//

#ifndef data_resolve_h
#define data_resolve_h 1

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
#ifndef LIB_data_resolve_C_API 
#define LIB_data_resolve_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_data_resolve_C_API 
bool MW_CALL_CONV data_resolveInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_data_resolve_C_API 
bool MW_CALL_CONV data_resolveInitialize(void);

extern LIB_data_resolve_C_API 
void MW_CALL_CONV data_resolveTerminate(void);

extern LIB_data_resolve_C_API 
void MW_CALL_CONV data_resolvePrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_data_resolve_C_API 
bool MW_CALL_CONV mlxData_resolve(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_data_resolve
#define PUBLIC_data_resolve_CPP_API __declspec(dllexport)
#else
#define PUBLIC_data_resolve_CPP_API __declspec(dllimport)
#endif

#define LIB_data_resolve_CPP_API PUBLIC_data_resolve_CPP_API

#else

#if !defined(LIB_data_resolve_CPP_API)
#if defined(LIB_data_resolve_C_API)
#define LIB_data_resolve_CPP_API LIB_data_resolve_C_API
#else
#define LIB_data_resolve_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_data_resolve_CPP_API void MW_CALL_CONV data_resolve(int nargout, mwArray& res, const mwArray& data_path, const mwArray& absolutepath_Net, const mwArray& NetName, const mwArray& time_str, const mwArray& options_index);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
