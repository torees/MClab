/*
 * rpm_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "rpm".
 *
 * Model version              : 1.68
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sun Jun 26 19:52:37 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rpm_private_h_
#define RTW_HEADER_rpm_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern void rpm_MATLABFunction(real_T rtu_rpm_tmp, real_T rtu_timer, real_T
  rtu_measurments, real_T rtu_measurment_old, real_T rtu_revolutions_tmp, real_T
  rtu_timeold_tmp, B_MATLABFunction_rpm_T *localB);

/* private model entry point functions */
extern void rpm_derivatives(void);

#endif                                 /* RTW_HEADER_rpm_private_h_ */
