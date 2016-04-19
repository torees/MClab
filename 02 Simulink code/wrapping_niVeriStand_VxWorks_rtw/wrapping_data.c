#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define wrapping_P                    wrapping_P DataSection(".NIVS.defaultparams")
#endif

/*
 * wrapping_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "wrapping".
 *
 * Model version              : 1.36
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Apr 19 18:43:05 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "wrapping.h"
#include "wrapping_private.h"

/* Block parameters (auto storage) */
P_wrapping_T wrapping_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_deg_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_deg_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_deg_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_deg_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_deg_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_deg_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/no wrapping'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/no wrapping'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/no wrapping'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/no wrapping'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/no wrapping'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/no wrapping'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_deg_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_deg_2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_deg_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_deg_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_deg_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_deg_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_deg_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_deg_3'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_deg_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_deg_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_deg_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_deg_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_deg_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_deg_4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_deg_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_deg_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_deg_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_deg_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_deg_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_deg_5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_deg_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_deg_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_deg_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_deg_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha_6'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha_1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha_2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha_3'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha_4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha_5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha_5'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain1'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain2'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain3'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain4'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_deg_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_deg_6'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_deg_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_deg_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_deg_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_deg_6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_6'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_5'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<S14>/alpha_5'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : wrapping
 * Model version : 1.36
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Tue Apr 19 18:43:05 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_wrapping_T_sizes[] DataSection(".NIVS.defaultparamsizes") =
  {
  { sizeof(P_wrapping_T), 1 },

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
