/*
 * Thrustallocation_test_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Thrustallocation_test".
 *
 * Model version              : 1.10
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Jun 17 16:52:41 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Thrustallocation_test_private_h_
#define RTW_HEADER_Thrustallocation_test_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern void Thrustallo_ActualForceandTorque(real_T rtu_n, real_T rtu_Kq, real_T
  rtu_Kt, real_T rtu_Ktr, real_T rtu_Kqr, real_T rtu_Rho, real_T rtu_D, real_T
  rtu_eps_c, real_T rtu_env, B_ActualForceandTorque_Thrust_T *localB);
extern void CorecontrollerTorquePowerandCom(real_T rtu_k_cc, real_T rtu_p_cc,
  real_T rtu_r_cc, real_T rtu_n, real_T rtu_K_t0, real_T rtu_K_q0, real_T rtu_D,
  real_T rtu_Tr, real_T rtu_eps, real_T rtu_rho, real_T rtu_eps_c, real_T
  rtu_K_t0r, real_T rtu_K_q0r, B_CorecontrollerTorquePoweran_T *localB);
extern void Thrustallocation_tes_Supervisor(real_T rtu_control, real_T rtu_input,
  real_T rtu_n, B_Supervisor_Thrustallocation_T *localB);
extern void Thrustallocation_MATLABFunction(real_T rtu_Td, real_T rtu_K_t0,
  real_T rtu_K_t0r, real_T rtu_rho, real_T rtu_D, real_T rtu_eps_c, real_T
  rtu_n_r, B_MATLABFunction_Thrustalloca_T *localB);

/* private model entry point functions */
extern void Thrustallocation_test_derivatives(void);

#endif                                 /* RTW_HEADER_Thrustallocation_test_private_h_ */
