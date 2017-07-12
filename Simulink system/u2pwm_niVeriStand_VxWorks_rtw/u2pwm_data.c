#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
#define u2pwm_P                        u2pwm_P DataSection(".NIVS.defaultparams")
#endif

/*
 * u2pwm_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "u2pwm".
 *
 * Model version              : 1.9
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Jul 12 17:04:41 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "u2pwm.h"
#include "u2pwm_private.h"

/* Block parameters (auto storage) */
P_u2pwm_T u2pwm_P = {
  -149.0,                              /* Variable: zero_alpha_1
                                        * Referenced by: '<S3>/alpha_Offset'
                                        */
  -40.0,                               /* Variable: zero_alpha_2
                                        * Referenced by: '<S3>/alpha_Offset1'
                                        */
  5.0,                                 /* Variable: zero_alpha_3
                                        * Referenced by: '<S3>/alpha_Offset2'
                                        */
  -17.0,                               /* Variable: zero_alpha_4
                                        * Referenced by: '<S3>/alpha_Offset3'
                                        */
  127.0,                               /* Variable: zero_alpha_5
                                        * Referenced by: '<S3>/alpha_Offset4'
                                        */
  -36.0,                               /* Variable: zero_alpha_6
                                        * Referenced by: '<S3>/alpha_Offset5'
                                        */
  7.5,                                 /* Variable: zero_pwm
                                        * Referenced by:
                                        *   '<S12>/PWM_Offset'
                                        *   '<S12>/PWM_Offset1'
                                        *   '<S12>/PWM_Offset2'
                                        *   '<S12>/PWM_Offset3'
                                        *   '<S12>/PWM_Offset4'
                                        *   '<S12>/PWM_Offset5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Triangle1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Triangle1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Triangle1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Triangle1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Triangle1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Triangle1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Circle1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Circle1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Circle1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Circle1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Circle1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Circle1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Cross1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Cross1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Cross1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Cross1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Cross1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Cross1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/Square1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/Square1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/Square1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/Square1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/Square1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/Square1'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S2>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/u_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/u_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/u_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/u_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/u_6'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/u_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/alpha_1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/u_2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/u_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/u_4'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/u_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/u_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/u_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/alpha_2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/alpha_3'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/alpha_4'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S6>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/alpha_5'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S6>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/alpha_6'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S6>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_6'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_4'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_3'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_4'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_5'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_6'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_6'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_4'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_3'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_4'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_5'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_6'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/STOP'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/STOP'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/STOP'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/STOP'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/STOP'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/STOP'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ctrl_DP'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ctrl_DP'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/ctrl_DP'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ctrl_DP'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ctrl_DP'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ctrl_DP'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ctrl_sixaxis2thruster'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ctrl_sixaxis2thruster'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/ctrl_sixaxis2thruster'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ctrl_sixaxis2thruster'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ctrl_sixaxis2thruster'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ctrl_sixaxis2thruster'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/ctrl_custom'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/ctrl_custom'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/ctrl_custom'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/ctrl_custom'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/ctrl_custom'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/ctrl_custom'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/man_alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/man_alpha_5'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/man_alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/man_alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/man_alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/man_alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/man_alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/man_alpha_4'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/man_alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/man_alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/man_alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/man_alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/man_alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/man_alpha_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/man_alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/man_alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/man_alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/man_alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/man_alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/man_alpha_2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/man_alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/man_alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/man_alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/man_alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/man_alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/man_alpha_3'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/man_alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/man_alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/man_alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/man_alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/man_alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/man_alpha_6'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/man_alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/man_alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/man_alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/man_alpha_6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Integrator11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain6'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain7'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain8'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain9'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain10'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/no wrapping'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/no wrapping'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/no wrapping'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/no wrapping'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/no wrapping'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/no wrapping'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Memory5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha_deg_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha_deg_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha_deg_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha_deg_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha_deg_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha_deg_1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Memory4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha_deg_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha_deg_2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha_deg_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha_deg_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha_deg_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha_deg_2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Memory3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha_deg_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha_deg_3'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha_deg_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha_deg_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha_deg_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha_deg_3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Memory2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha_deg_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha_deg_4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha_deg_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha_deg_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha_deg_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha_deg_4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha_deg_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha_deg_5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha_deg_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha_deg_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha_deg_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha_deg_5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Memory1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/alpha_deg_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/alpha_deg_6'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/alpha_deg_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/alpha_deg_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/alpha_deg_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/alpha_deg_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Need unwrapping thrusters'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Need unwrapping thrusters'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Need unwrapping thrusters'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Need unwrapping thrusters'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Need unwrapping thrusters'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Need unwrapping thrusters'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/manual override alpha'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/manual override alpha'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/manual override alpha'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/manual override alpha'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/manual override alpha'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/manual override alpha'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_6'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/pwm_u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/pwm_u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/pwm_u_4'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/pwm_u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/pwm_u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/pwm_u_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/pwm_u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/pwm_u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/pwm_u_6'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/pwm_u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/pwm_u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/pwm_u_2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/pwm_u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/pwm_u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/pwm_u_3'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/pwm_u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/pwm_u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S12>/manual override pwm'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S12>/manual override pwm'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S12>/manual override pwm'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S12>/manual override pwm'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S12>/manual override pwm'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S12>/manual override pwm'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S12>/Saturation11'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S12>/Saturation11'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S12>/Saturation10'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S12>/Saturation10'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S12>/Gain1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S12>/Saturation9'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S12>/Saturation9'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Gain2'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S12>/Saturation8'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S12>/Saturation8'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S12>/Gain3'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S12>/Saturation7'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S12>/Saturation7'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S12>/Gain4'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S12>/Saturation6'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S12>/Saturation6'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S12>/Gain5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/pwm_u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/pwm_u_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/pwm_u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/pwm_u_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/pwm_u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/pwm_u_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/pwm_u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/pwm_u_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/pwm_u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/pwm_u_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/pwm_u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/pwm_u_6'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/pwm_u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/pwm_u_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/pwm_u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/pwm_u_4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/pwm_u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/pwm_u_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/pwm_u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/pwm_u_5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/pwm_u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/pwm_u_5'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<S11>/pwm_u_5'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : u2pwm
 * Model version : 1.9
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Wed Jul 12 17:04:41 2017
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_u2pwm_T_sizes[] DataSection(".NIVS.defaultparamsizes") = {
  { sizeof(P_u2pwm_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
