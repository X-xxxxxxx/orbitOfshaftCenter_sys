//
// MATLAB Compiler: 8.3 (R2021b)
// Date: Sat May 27 21:15:22 2023
// Arguments:
// "-B""macro_default""-W""cpplib:get_data_demesions,all,version=1.0""-T""link:l
// ib""-d""C:\Users\X_xx\Desktop\ï¿½ï¿½Ê¦ï¿½ï¿½\ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿
// ½\get_data_demesions\for_testing""-v""C:\Users\X_xx\Desktop\ï¿½ï¿½Ê¦ï¿½ï¿½\ï¿
// ½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½\get_data_demesions.m"
//

#ifndef get_data_demesions_h
#define get_data_demesions_h 1

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
#ifndef LIB_get_data_demesions_C_API 
#define LIB_get_data_demesions_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_get_data_demesions_C_API 
bool MW_CALL_CONV get_data_demesionsInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_get_data_demesions_C_API 
bool MW_CALL_CONV get_data_demesionsInitialize(void);

extern LIB_get_data_demesions_C_API 
void MW_CALL_CONV get_data_demesionsTerminate(void);

extern LIB_get_data_demesions_C_API 
void MW_CALL_CONV get_data_demesionsPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_get_data_demesions_C_API 
bool MW_CALL_CONV mlxGet_data_demesions(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                        *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_get_data_demesions
#define PUBLIC_get_data_demesions_CPP_API __declspec(dllexport)
#else
#define PUBLIC_get_data_demesions_CPP_API __declspec(dllimport)
#endif

#define LIB_get_data_demesions_CPP_API PUBLIC_get_data_demesions_CPP_API

#else

#if !defined(LIB_get_data_demesions_CPP_API)
#if defined(LIB_get_data_demesions_C_API)
#define LIB_get_data_demesions_CPP_API LIB_get_data_demesions_C_API
#else
#define LIB_get_data_demesions_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_get_data_demesions_CPP_API void MW_CALL_CONV get_data_demesions(int nargout, mwArray& row, mwArray& col, const mwArray& data_path);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
