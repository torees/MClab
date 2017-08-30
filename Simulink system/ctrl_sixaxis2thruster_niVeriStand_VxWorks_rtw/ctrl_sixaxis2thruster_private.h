/*
 * ctrl_sixaxis2thruster_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_sixaxis2thruster".
 *
 * Model version              : 1.72
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Aug 21 16:42:38 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_sixaxis2thruster_private_h_
#define RTW_HEADER_ctrl_sixaxis2thruster_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "ctrl_sixaxis2thruster.h"

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void ctrl_sixaxis2t_MATLABFunction10(real_T rtu_alpha_prev, real_T rtu_u,
  real_T rtu_alpha, real_T rtu_u_threshold, B_MATLABFunction10_ctrl_sixax_T
  *localB);
extern void ctrl_sixaxis2t_MATLABFunction11(real_T rtu_alpha_prev, real_T
  rtu_alpha_pipi, B_MATLABFunction11_ctrl_sixax_T *localB);

#endif                                 /* RTW_HEADER_ctrl_sixaxis2thruster_private_h_ */
