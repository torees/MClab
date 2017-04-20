/*
 * ctrl_TAPM_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_TAPM".
 *
 * Model version              : 1.190
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Apr 20 19:54:34 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_TAPM_private_h_
#define RTW_HEADER_ctrl_TAPM_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void rt_invd6x6_snf(const real_T u[36], real_T y[36]);
extern boolean_T findpivotIdx_D(int32_T i, int32_T j, int32_T startIdx, int32_T
  pivot[], uint32_T midxPort[], const real_T mdataPort[]);
extern int32_T partitionIdx_D(int32_T i, int32_T j, int32_T startIdx, const
  int32_T pivot[], uint32_T midxPort[], const real_T mdataPort[]);
extern void MDNQSort_D(int32_T i, int32_T j, int32_T startIdx, uint32_T
  midxPort[], const real_T mdataPort[]);
int_T rt_WriteMat4FileHeader(FILE *fp,
  int32_T m,
  int32_T n,
  const char_T *name);
extern void ctrl_TAPM_Outlierdetected(const real_T rtu_Y_previous[7], const
  real_T rtu_V[5], real_T rty_Y_filtered[7], real_T rty_V_hist[5]);
extern void ctrl_TAPM_Nooutlier(const real_T rtu_Y[7], const real_T rtu_V[5],
  real_T rty_Y_filtered[7], real_T rty_V_hist[5]);
extern void ctrl_TAPM_Kd(real_T rtu_K_d1, real_T rtu_K_d1_i, real_T rtu_K_d1_k,
  B_Kd_ctrl_TAPM_T *localB);
extern void ctrl_TAPM_Ki(real_T rtu_K_i1, real_T rtu_K_i1_p, real_T rtu_K_i1_l,
  B_Ki_ctrl_TAPM_T *localB);
extern void ctrl_TAPM_Kp(real_T rtu_K_p1, real_T rtu_K_p1_a, real_T rtu_K_p1_i,
  B_Kp_ctrl_TAPM_T *localB);
extern void ctrl_TAPM_MATLABFunction2(real_T rtu_Tc_in1, real_T rtu_signal,
  real_T rtu_Tc_in2, B_MATLABFunction2_ctrl_TAPM_T *localB);
extern void CorecontrollerTorquePowerandCom(real_T rtu_k_cc, real_T rtu_p_cc,
  real_T rtu_r_cc, real_T rtu_n, real_T rtu_K_t0, real_T rtu_K_q0, real_T rtu_D,
  real_T rtu_Tr, real_T rtu_rho, real_T rtu_eps_c, real_T rtu_K_t0r, real_T
  rtu_K_q0r, B_CorecontrollerTorquePoweran_T *localB);
extern void ctrl_TAPM_Supervisor(real_T rtu_control, real_T rtu_input, real_T
  rtu_n, B_Supervisor_ctrl_TAPM_T *localB);
extern void ctrl_TAPM_ActualForceandTorque(real_T rtu_n, real_T rtu_Kq, real_T
  rtu_Kt, real_T rtu_Ktr, real_T rtu_Kqr, real_T rtu_Rho, real_T rtu_D, real_T
  rtu_eps_c, real_T rtu_env, B_ActualForceandTorque_ctrl_T_T *localB);
extern void ctrl_TAPM_MATLABFunction(real_T rtu_Td, real_T rtu_K_t0, real_T
  rtu_K_t0r, real_T rtu_rho, real_T rtu_D, real_T rtu_eps_c, real_T rtu_n_r,
  B_MATLABFunction_ctrl_TAPM_T *localB);

/* private model entry point functions */
extern void ctrl_TAPM_derivatives(void);

#endif                                 /* RTW_HEADER_ctrl_TAPM_private_h_ */
