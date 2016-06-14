/*
 * average_private.h
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

#ifndef RTW_HEADER_average_private_h_
#define RTW_HEADER_average_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern void average_MATLABFunction_Init(DW_MATLABFunction_average_T *localDW);
extern void average_MATLABFunction(real_T rtu_signal, real_T rtu_u,
  B_MATLABFunction_average_T *localB, DW_MATLABFunction_average_T *localDW);

#endif                                 /* RTW_HEADER_average_private_h_ */
