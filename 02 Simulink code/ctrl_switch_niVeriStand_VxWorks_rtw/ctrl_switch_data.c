#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_switch_P                 ctrl_switch_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_switch_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_switch".
 *
 * Model version              : 1.23
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Apr 12 14:08:25 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_switch.h"
#include "ctrl_switch_private.h"

/* Block parameters (auto storage) */
P_ctrl_switch_T ctrl_switch_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/Triangle'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/Triangle'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/Triangle'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/Triangle'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/Triangle'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/Triangle'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/Circle'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/Circle'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/Circle'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/Circle'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/Circle'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/Circle'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/Cross'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/Cross'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/Cross'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/Cross'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/Cross'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/Cross'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/Square'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/Square'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/Square'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/Square'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/Square'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/Square'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S1>/Memory'
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
                                        * Referenced by: '<S4>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_6'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha_1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_4'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha_2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha_3'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha_4'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha_5'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha_6'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_6'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_4'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_3'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_4'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_5'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_6'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_6'
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  8.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S7>/ctrl_student'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ctrl_student'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/ctrl_student'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ctrl_student'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ctrl_student'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ctrl_student'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/ctrl_DP_basic'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ctrl_DP_basic'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/ctrl_DP_basic'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ctrl_DP_basic'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ctrl_DP_basic'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ctrl_DP_basic'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/ctrl_sixaxis2force'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ctrl_sixaxis2force'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/ctrl_sixaxis2force'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ctrl_sixaxis2force'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ctrl_sixaxis2force'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ctrl_sixaxis2force'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/ctrl_sixaxis2thruster'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/ctrl_sixaxis2thruster'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/ctrl_sixaxis2thruster'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/ctrl_sixaxis2thruster'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/ctrl_sixaxis2thruster'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/ctrl_sixaxis2thruster'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Saturation4'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Saturation4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_5,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_5,d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_5,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_5,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_5,d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_5,d'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Saturation'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_1,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_1,d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_1,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_1,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_1,d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_1,d'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Saturation1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Saturation1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_2,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_2,d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_2,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_2,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_2,d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_2,d'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Saturation2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Saturation2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_3,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_3,d'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_3,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_3,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_3,d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_3,d'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Saturation3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Saturation3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_4,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_4,d'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_4,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_4,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_4,d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_4,d'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Saturation5'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Saturation5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_6,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_6,d'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_6,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_6,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_6,d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_6,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_1,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_1,d'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_1,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_1,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_1,d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_1,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_2,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_2,d'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_2,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_2,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_2,d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_2,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_3,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_3,d'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_3,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_3,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_3,d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_3,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_4,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_4,d'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_4,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_4,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_4,d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_4,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_5,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_5,d'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_5,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_5,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_5,d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_5,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_6,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_6,d'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_6,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_6,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_6,d'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<S9>/alpha_6,d'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_switch
 * Model version : 1.23
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Tue Apr 12 14:08:25 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_switch_T_sizes[] DataSection(".NIVS.defaultparamsizes")
  = {
  { sizeof(P_ctrl_switch_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
