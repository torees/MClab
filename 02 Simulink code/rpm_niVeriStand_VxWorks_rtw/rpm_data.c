#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define rpm_P                         rpm_P DataSection(".NIVS.defaultparams")
#endif

/*
 * rpm_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "rpm".
 *
 * Model version              : 1.46
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue May 03 20:13:47 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "rpm.h"
#include "rpm_private.h"

/* Block parameters (auto storage) */
P_rpm_T rpm_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolutions'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolutions'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolutions'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolutions'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory2'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/rpm'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/rpm'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/rpm'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/rpm'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/rpm'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/rpm'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/measurment'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/measurment'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/measurment'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/measurment'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/measurment'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/measurment'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolution'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolution'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/revolution'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolution'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolution'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolution'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : rpm
 * Model version : 1.46
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Tue May 03 20:13:47 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_rpm_T_sizes[] DataSection(".NIVS.defaultparamsizes") = {
  { sizeof(P_rpm_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
