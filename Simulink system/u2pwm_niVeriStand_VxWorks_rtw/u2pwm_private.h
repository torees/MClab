/*
 * u2pwm_private.h
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

#ifndef RTW_HEADER_u2pwm_private_h_
#define RTW_HEADER_u2pwm_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "u2pwm.h"

extern void u2pwm_MATLABFunction13(real_T rtu_u, B_MATLABFunction13_u2pwm_T
  *localB);
extern void u2pwm_MATLABFunction(real_T rtu_u_pre, real_T rtu_u,
  B_MATLABFunction_u2pwm_T *localB);
extern void u2pwm_MATLABFunction11(real_T rtu_angle_d, real_T rtu_angle,
  B_MATLABFunction11_u2pwm_T *localB);

/* private model entry point functions */
extern void u2pwm_derivatives(void);

#endif                                 /* RTW_HEADER_u2pwm_private_h_ */
