//
// MATLAB Compiler: 8.3 (R2021b)
// Date: Tue Jun 13 17:11:58 2023
// Arguments:
// "-B""macro_default""-W""cpplib:Mathematical_morphology,all,version=1.0""-T""l
// ink:lib""-d""C:\Users\X_xx\Desktop\softB\matlab\ͼ����\��̬ѧ\Mat
// hematical_morphology\for_testing""-v""C:\Users\X_xx\Desktop\softB\matlab\ͼ�
// ����\��̬ѧ\Mathematical_morphology.m"
//

#ifndef Mathematical_morphology_h
#define Mathematical_morphology_h 1

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
#ifndef LIB_Mathematical_morphology_C_API 
#define LIB_Mathematical_morphology_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_Mathematical_morphology_C_API 
bool MW_CALL_CONV Mathematical_morphologyInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_Mathematical_morphology_C_API 
bool MW_CALL_CONV Mathematical_morphologyInitialize(void);

extern LIB_Mathematical_morphology_C_API 
void MW_CALL_CONV Mathematical_morphologyTerminate(void);

extern LIB_Mathematical_morphology_C_API 
void MW_CALL_CONV Mathematical_morphologyPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_Mathematical_morphology_C_API 
bool MW_CALL_CONV mlxMathematical_morphology(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                             *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_Mathematical_morphology
#define PUBLIC_Mathematical_morphology_CPP_API __declspec(dllexport)
#else
#define PUBLIC_Mathematical_morphology_CPP_API __declspec(dllimport)
#endif

#define LIB_Mathematical_morphology_CPP_API PUBLIC_Mathematical_morphology_CPP_API

#else

#if !defined(LIB_Mathematical_morphology_CPP_API)
#if defined(LIB_Mathematical_morphology_C_API)
#define LIB_Mathematical_morphology_CPP_API LIB_Mathematical_morphology_C_API
#else
#define LIB_Mathematical_morphology_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_Mathematical_morphology_CPP_API void MW_CALL_CONV Mathematical_morphology(const mwArray& path, const mwArray& path1);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
