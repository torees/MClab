/*
 * ctrl_student_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student".
 *
 * Model version              : 1.150
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Thu Feb 02 14:51:44 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_student_private_h_
#define RTW_HEADER_ctrl_student_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "ctrl_student.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void ctrl_student_MATLABFunction(real_T rtu_K_p1, real_T rtu_K_p1_n,
  real_T rtu_K_p1_f, B_MATLABFunction_ctrl_student_T *localB);
extern void ctrl_student_MATLABFunction1(real_T rtu_K_i1, real_T rtu_K_i1_j,
  real_T rtu_K_i1_l, B_MATLABFunction1_ctrl_studen_T *localB);
extern void ctrl_student_MATLABFunction2(real_T rtu_K_d1, real_T rtu_K_d1_p,
  real_T rtu_K_d1_b, B_MATLABFunction2_ctrl_studen_T *localB);

/* private model entry point functions */
extern void ctrl_student_derivatives(void);

#endif                                 /* RTW_HEADER_ctrl_student_private_h_ */
