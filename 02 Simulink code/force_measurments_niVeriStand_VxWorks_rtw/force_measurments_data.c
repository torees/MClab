/*
 * force_measurments_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "force_measurments".
 *
 * Model version              : 1.8
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue May 03 10:40:09 2016
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
                                        * Referenced by: '<Root>/Fx'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Fx'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Fx'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Fx'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Fx'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Fx'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Fx_out_mean'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Fx_out_mean'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Fx_out_mean'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Fx_out_mean'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Fx_out_mean'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Fx_out_mean'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Fy'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Fy'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Fy'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Fy'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Fy'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Fy'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Fz'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Fz'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Fz'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Fz'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Fz'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Fz'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Fx_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Fx_out'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Fx_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Fx_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Fx_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Fx_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Fy_out_mean'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Fy_out_mean'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Fy_out_mean'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Fy_out_mean'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Fy_out_mean'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Fy_out_mean'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Fy_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Fy_out'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Fy_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Fy_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Fy_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Fy_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Fz_out_mean'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Fz_out_mean'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Fz_out_mean'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Fz_out_mean'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Fz_out_mean'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Fz_out_mean'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/F_total'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/F_total'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/F_total'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/F_total'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/F_total'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/F_total'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Fz_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Fz_out'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Fz_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Fz_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Fz_out'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<Root>/Fz_out'
                                        */
};
