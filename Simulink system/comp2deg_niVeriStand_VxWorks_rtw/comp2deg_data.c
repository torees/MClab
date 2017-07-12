#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
#define comp2deg_P                     comp2deg_P DataSection(".NIVS.defaultparams")
#endif

/*
 * comp2deg_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "comp2deg".
 *
 * Model version              : 1.13
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Jul 12 17:05:39 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "comp2deg.h"
#include "comp2deg_private.h"

/* Block parameters (auto storage) */
P_comp2deg_T comp2deg_P = {
  -149.0,                              /* Variable: zero_alpha_1
                                        * Referenced by: '<Root>/Constant'
                                        */
  -40.0,                               /* Variable: zero_alpha_2
                                        * Referenced by: '<Root>/Constant1'
                                        */
  5.0,                                 /* Variable: zero_alpha_3
                                        * Referenced by: '<Root>/Constant2'
                                        */
  -17.0,                               /* Variable: zero_alpha_4
                                        * Referenced by: '<Root>/Constant3'
                                        */
  127.0,                               /* Variable: zero_alpha_5
                                        * Referenced by: '<Root>/Constant4'
                                        */
  -36.0,                               /* Variable: zero_alpha_6
                                        * Referenced by: '<Root>/Constant5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_step_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_step_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_step_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_step_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_step_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_step_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_step_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_step_2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_step_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_step_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_step_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_step_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_step_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_step_3'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_step_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_step_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_step_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_step_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_step_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_step_4'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_step_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_step_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_step_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_step_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_step_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_step_5'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_step_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_step_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_step_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_step_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_step_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_step_6'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_step_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_step_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_step_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_step_6'
                                        */
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
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_deg_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_deg_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_deg_2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_deg_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_deg_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_deg_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_deg_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_deg_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_deg_3'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_deg_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_deg_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_deg_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_deg_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_deg_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_deg_4'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_deg_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_deg_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_deg_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_deg_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_deg_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_deg_5'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_deg_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_deg_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_deg_5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_deg_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_deg_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_deg_6'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_deg_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_deg_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_deg_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_deg_6'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_rad_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_rad_1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_rad_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_rad_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_rad_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_rad_1'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_rad_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_rad_2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_rad_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_rad_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_rad_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_rad_2'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_rad_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_rad_3'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_rad_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_rad_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_rad_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_rad_3'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_rad_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_rad_4'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_rad_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_rad_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_rad_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_rad_4'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_rad_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_rad_5'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_rad_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_rad_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_rad_5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_rad_5'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_rad_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_rad_6'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_rad_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_rad_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_rad_6'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<Root>/alpha_rad_6'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : comp2deg
 * Model version : 1.13
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Wed Jul 12 17:05:39 2017
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_comp2deg_T_sizes[] DataSection(".NIVS.defaultparamsizes") =
  {
  { sizeof(P_comp2deg_T), 1 },

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
