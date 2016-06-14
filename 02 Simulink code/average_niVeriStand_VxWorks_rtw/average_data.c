/*
 * average_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "average".
 *
 * Model version              : 1.17
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed May 11 13:11:37 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "average.h"
#include "average_private.h"

/* Block parameters (auto storage) */
P_average_T average_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/signal'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/signal'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/signal'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/signal'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/signal'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/signal'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_BB_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_BB_in'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_BB_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_BB_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_BB_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_BB_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_BB_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_BB_out'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_BB_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_BB_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_BB_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_BB_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_FB_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_FB_in'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_FB_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_FB_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_FB_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_FB_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_FB_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_FB_out'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_FB_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_FB_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_FB_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_FB_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_BS_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_BS_in'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_BS_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_BS_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_BS_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_BS_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_BS_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_BS_out'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_BS_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_BS_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_BS_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_BS_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_FS_in'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_FS_in'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_FS_in'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_FS_in'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_FS_in'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_FS_in'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_FS_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_FS_out'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_FS_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_FS_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_FS_out'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<Root>/F_FS_out'
                                        */
};
