#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define measurement_P                 measurement_P DataSection(".NIVS.defaultparams")
#endif

/*
 * measurement_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "measurement".
 *
 * Model version              : 1.10
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue May 03 13:46:20 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "measurement.h"
#include "measurement_private.h"

/* Block parameters (auto storage) */
P_measurement_T measurement_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Noise power position'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Noise power position'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Noise power position'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Noise power position'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Noise power position'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Noise power position'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Sampling frequency'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Sampling frequency'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Sampling frequency'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Sampling frequency'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Sampling frequency'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Sampling frequency'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Noise power heading'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Noise power heading'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Noise power heading'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Noise power heading'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Noise power heading'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Noise power heading'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/counter'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<Root>/Step size'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S9>/White Noise'
                                        */
  9024.0,                              /* Expression: 9024
                                        * Referenced by: '<S9>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_k
                                        * Referenced by: '<S10>/White Noise'
                                        */
  123.0,                               /* Expression: 123
                                        * Referenced by: '<S10>/White Noise'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/White Noise'
                                        */
  1.0,                                 /* Computed Parameter: WhiteNoise_StdDev_ko
                                        * Referenced by: '<S8>/White Noise'
                                        */
  9025.0,                              /* Expression: 9025
                                        * Referenced by: '<S8>/White Noise'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/x'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/psi'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/y'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Hold'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/enable'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/enable'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/enable'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/enable'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/enable'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/enable'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/x_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/x_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/x_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/y_m'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/y_m'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/y_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/psi_m'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/psi_m'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<S5>/psi_m'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : measurement
 * Model version : 1.10
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Tue May 03 13:46:20 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_measurement_T_sizes[] DataSection(".NIVS.defaultparamsizes")
  = {
  { sizeof(P_measurement_T), 1 },

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
