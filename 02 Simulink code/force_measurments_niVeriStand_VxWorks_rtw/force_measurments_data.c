/*
 * force_measurments_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "force_measurments".
 *
 * Model version              : 1.13
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed May 11 17:06:45 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "force_measurments.h"
#include "force_measurments_private.h"

/* Block parameters (auto storage) */
P_force_measurments_T force_measurments_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/8810'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/8810'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/8810'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/8810'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/8810'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/8810'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_FS_out_mean'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_FS_out_mean'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_FS_out_mean'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_FS_out_mean'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_FS_out_mean'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_FS_out_mean'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/8812'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/8812'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/8812'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/8812'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/8812'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/8812'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/8816'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/8816'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/8816'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/8816'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/8816'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/8816'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/8815'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/8815'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/8815'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/8815'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/8815'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/8815'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_FS_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_FS_out'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_FS_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_FS_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_FS_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_FS_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_FB_out_mean'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_FB_out_mean'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_FB_out_mean'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_FB_out_mean'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_FB_out_mean'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_FB_out_mean'
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
                                        * Referenced by: '<Root>/F_BB_out_mean'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_BB_out_mean'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_BB_out_mean'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_BB_out_mean'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_BB_out_mean'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_BB_out_mean'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_BB_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_BB_out'
                                        */
  3.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/F_BS_out_mean'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_BS_out_mean'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_BS_out_mean'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_BS_out_mean'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_BS_out_mean'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_BS_out_mean'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_BS_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_BS_out'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_BS_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_BS_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_BS_out'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<Root>/F_BS_out'
                                        */
};
