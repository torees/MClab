/*
 * ctrl_DP.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_DP".
 *
 * Model version              : 1.207
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Aug 23 17:03:42 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_DP.h"
#include "ctrl_DP_private.h"

/* Block signals (auto storage) */
B_ctrl_DP_T ctrl_DP_B;

/* Continuous states */
X_ctrl_DP_T ctrl_DP_X;

/* Block states (auto storage) */
DW_ctrl_DP_T ctrl_DP_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_DP_T ctrl_DP_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_DP_T ctrl_DP_M_;
RT_MODEL_ctrl_DP_T *const ctrl_DP_M = &ctrl_DP_M_;

/* Forward declaration for local functions */
static real_T ctrl_DP_norm_e(const real_T x[2]);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 21;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_DP_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ctrl_DP_output();
  ctrl_DP_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ctrl_DP_output();
  ctrl_DP_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S38>/MATLAB Function'
 *    '<S38>/MATLAB Function1'
 *    '<S38>/MATLAB Function2'
 *    '<S39>/MATLAB Function'
 *    '<S39>/MATLAB Function1'
 *    '<S40>/MATLAB Function'
 *    '<S40>/MATLAB Function1'
 *    '<S40>/MATLAB Function2'
 */
void ctrl_DP_MATLABFunction(real_T rtu_u, real_T rtu_u_f, real_T rtu_u_m,
  B_MATLABFunction_ctrl_DP_T *localB)
{
  /* MATLAB Function 'Operator input/Control Gains/MATLAB Function': '<S41>:1' */
  /* '<S41>:1:3' */
  memset(&localB->y[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S41>/TmpSignal ConversionAt SFunction Inport1' */
  localB->y[0] = rtu_u;
  localB->y[4] = rtu_u_f;
  localB->y[8] = rtu_u_m;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = u0 / u1;
      if (fabs(u1_0 - rt_roundd_snf(u1_0)) <= DBL_EPSILON * fabs(u1_0)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S11>/MATLAB Function11' */
static real_T ctrl_DP_norm_e(const real_T x[2])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 2.2250738585072014E-308;
  absxk = fabs(x[0]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void ctrl_DP_output(void)
{
  ZCEventType zcEvent;
  real_T x[9];
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  real_T rtb_psi_dot;
  real_T rtb_Row1_m;
  real_T rtb_TmpSignalConversionAtMatrix[3];
  real_T rtb_Row2_p;
  real_T rtb_Row3_f;
  real_T rtb_Row3_h;
  real_T rtb_Row2_j;
  real_T rtb_y_dot;
  real_T rtb_Sum3[3];
  real_T rtb_u_e[12];
  real_T rtb_alpha[6];
  real_T rtb_y_b[9];
  int32_T i;
  real_T tmp[3];
  real_T rtb_TmpSignalConversionAtMatr_0[4];
  real_T rtb_TmpSignalConversionAtMatr_1[4];
  real_T rtb_TmpSignalConversionAtMatr_2[4];
  real_T rtb_TmpSignalConversionAtMatr_3[4];
  real_T rtb_TmpSignalConversionAtMatr_4[4];
  real_T rtb_TmpSignalConversionAtMatr_5[4];
  real_T rtb_TmpSignalConversionAtMatr_6[4];
  real_T rtb_TmpSignalConversionAtMatr_7[4];
  real_T rtb_TmpSignalConversionAtMatr_8[4];
  real_T rtb_psi_dot_0[4];
  real_T rtb_psi_dot_1[4];
  real_T rtb_psi_dot_2[4];
  real_T rtb_psi_dot_3[4];
  real_T rtb_Row1_n[3];
  real_T tmp_0[3];
  real_T tmp_1[9];
  real_T tmp_2[3];
  real_T rtb_y_m[3];
  real_T rtb_Sum_idx_2;
  real_T rtb_Sum_idx_0;
  real_T rtb_Sum_idx_1;
  real_T tmp_3;
  real_T tmp_4;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* set solver stop time */
    if (!(ctrl_DP_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_DP_M->solverInfo,
                            ((ctrl_DP_M->Timing.clockTickH0 + 1) *
        ctrl_DP_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_DP_M->solverInfo,
                            ((ctrl_DP_M->Timing.clockTick0 + 1) *
        ctrl_DP_M->Timing.stepSize0 + ctrl_DP_M->Timing.clockTickH0 *
        ctrl_DP_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_DP_M)) {
    ctrl_DP_M->Timing.t[0] = rtsiGetT(&ctrl_DP_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* MATLAB Function: '<S40>/MATLAB Function2' incorporates:
     *  Constant: '<S40>/Constant6'
     *  Constant: '<S40>/Constant7'
     *  Constant: '<S40>/Constant8'
     */
    ctrl_DP_MATLABFunction(ctrl_DP_P.Constant6_Value, ctrl_DP_P.Constant7_Value,
      ctrl_DP_P.Constant8_Value, &ctrl_DP_B.sf_MATLABFunction2);
  }

  /* MATLAB Function: '<S38>/MATLAB Function' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.K_p_x, ctrl_DP_B.K_p_y, ctrl_DP_B.K_p_psi,
    &ctrl_DP_B.sf_MATLABFunction);

  /* MATLAB Function: '<S38>/MATLAB Function1' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.K_i_x, ctrl_DP_B.K_i_y, ctrl_DP_B.K_i_psi,
    &ctrl_DP_B.sf_MATLABFunction1);

  /* MATLAB Function: '<S38>/MATLAB Function2' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.K_d_x, ctrl_DP_B.K_d_y, ctrl_DP_B.K_d_psi,
    &ctrl_DP_B.sf_MATLABFunction2_c);

  /* MATLAB Function: '<S39>/MATLAB Function' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.w_d_x, ctrl_DP_B.w_d_y, ctrl_DP_B.w_d_psi,
    &ctrl_DP_B.sf_MATLABFunction_d);

  /* Gain: '<S15>/mm2m' */
  ctrl_DP_B.mm2m = ctrl_DP_P.mm2m_Gain * ctrl_DP_B.x_m;

  /* Gain: '<S15>/Gain1' */
  ctrl_DP_B.Gain1 = ctrl_DP_P.Gain1_Gain * ctrl_DP_B.y_m;

  /* Gain: '<S15>/deg2rad' */
  rtb_psi_dot = ctrl_DP_P.deg2rad_Gain * ctrl_DP_B.u80180deg;

  /* Saturate: '<S15>/Saturation' */
  if (rtb_psi_dot > ctrl_DP_P.Saturation_UpperSat) {
    rtb_psi_dot = ctrl_DP_P.Saturation_UpperSat;
  } else {
    if (rtb_psi_dot < ctrl_DP_P.Saturation_LowerSat) {
      rtb_psi_dot = ctrl_DP_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S15>/Saturation' */

  /* Signum: '<S15>/Sign' */
  if (rtb_psi_dot < 0.0) {
    rtb_Sum_idx_0 = -1.0;
  } else if (rtb_psi_dot > 0.0) {
    rtb_Sum_idx_0 = 1.0;
  } else if (rtb_psi_dot == 0.0) {
    rtb_Sum_idx_0 = 0.0;
  } else {
    rtb_Sum_idx_0 = rtb_psi_dot;
  }

  /* End of Signum: '<S15>/Sign' */

  /* Gain: '<S15>/Gain6' */
  rtb_Row1_m = ctrl_DP_P.Gain6_Gain * rtb_Sum_idx_0;

  /* Sum: '<S15>/Sum1' */
  rtb_psi_dot += rtb_Row1_m;

  /* Math: '<S15>/Math Function' incorporates:
   *  Constant: '<S15>/Constant1'
   */
  rtb_psi_dot = rt_remd_snf(rtb_psi_dot, ctrl_DP_P.Constant1_Value);

  /* Sum: '<S15>/Sum' */
  ctrl_DP_B.Sum = rtb_psi_dot - rtb_Row1_m;

  /* Integrator: '<S4>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (ctrl_DP_DW.Integrator_IWORK != 0)) {
      ctrl_DP_X.Integrator_CSTATE[0] = ctrl_DP_B.mm2m;
      ctrl_DP_X.Integrator_CSTATE[1] = ctrl_DP_B.Gain1;
      ctrl_DP_X.Integrator_CSTATE[2] = ctrl_DP_B.Sum;
    }
  }

  ctrl_DP_B.Integrator[0] = ctrl_DP_X.Integrator_CSTATE[0];
  ctrl_DP_B.Integrator[1] = ctrl_DP_X.Integrator_CSTATE[1];
  ctrl_DP_B.Integrator[2] = ctrl_DP_X.Integrator_CSTATE[2];

  /* End of Integrator: '<S4>/Integrator' */

  /* Saturate: '<S32>/Saturation' */
  if (ctrl_DP_B.Integrator[2] > ctrl_DP_P.Saturation_UpperSat_i) {
    rtb_Row1_m = ctrl_DP_P.Saturation_UpperSat_i;
  } else if (ctrl_DP_B.Integrator[2] < ctrl_DP_P.Saturation_LowerSat_o) {
    rtb_Row1_m = ctrl_DP_P.Saturation_LowerSat_o;
  } else {
    rtb_Row1_m = ctrl_DP_B.Integrator[2];
  }

  /* End of Saturate: '<S32>/Saturation' */

  /* Signum: '<S32>/Sign' */
  if (rtb_Row1_m < 0.0) {
    rtb_psi_dot = -1.0;
  } else if (rtb_Row1_m > 0.0) {
    rtb_psi_dot = 1.0;
  } else if (rtb_Row1_m == 0.0) {
    rtb_psi_dot = 0.0;
  } else {
    rtb_psi_dot = rtb_Row1_m;
  }

  /* End of Signum: '<S32>/Sign' */

  /* Gain: '<S32>/Gain' */
  rtb_psi_dot *= ctrl_DP_P.Gain_Gain;

  /* Sum: '<S32>/Sum1' */
  rtb_Row1_m += rtb_psi_dot;

  /* Math: '<S32>/Math Function' incorporates:
   *  Constant: '<S32>/Constant'
   */
  rtb_Row1_m = rt_remd_snf(rtb_Row1_m, ctrl_DP_P.Constant_Value);

  /* Sum: '<S32>/Sum' */
  ctrl_DP_B.Sum_e = rtb_Row1_m - rtb_psi_dot;

  /* Integrator: '<S4>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator1_Reset_ZCE,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator1_CSTATE[0] = ctrl_DP_P.Integrator1_IC[0];
      ctrl_DP_X.Integrator1_CSTATE[1] = ctrl_DP_P.Integrator1_IC[1];
      ctrl_DP_X.Integrator1_CSTATE[2] = ctrl_DP_P.Integrator1_IC[2];
    }
  }

  ctrl_DP_B.Integrator1[0] = ctrl_DP_X.Integrator1_CSTATE[0];
  ctrl_DP_B.Integrator1[1] = ctrl_DP_X.Integrator1_CSTATE[1];
  ctrl_DP_B.Integrator1[2] = ctrl_DP_X.Integrator1_CSTATE[2];

  /* End of Integrator: '<S4>/Integrator1' */

  /* Saturate: '<S33>/Saturation' */
  if (ctrl_DP_B.Sum > ctrl_DP_P.Saturation_UpperSat_e) {
    rtb_Row1_m = ctrl_DP_P.Saturation_UpperSat_e;
  } else if (ctrl_DP_B.Sum < ctrl_DP_P.Saturation_LowerSat_g) {
    rtb_Row1_m = ctrl_DP_P.Saturation_LowerSat_g;
  } else {
    rtb_Row1_m = ctrl_DP_B.Sum;
  }

  /* End of Saturate: '<S33>/Saturation' */

  /* Signum: '<S33>/Sign' */
  if (rtb_Row1_m < 0.0) {
    rtb_psi_dot = -1.0;
  } else if (rtb_Row1_m > 0.0) {
    rtb_psi_dot = 1.0;
  } else if (rtb_Row1_m == 0.0) {
    rtb_psi_dot = 0.0;
  } else {
    rtb_psi_dot = rtb_Row1_m;
  }

  /* End of Signum: '<S33>/Sign' */

  /* Gain: '<S33>/Gain' */
  rtb_psi_dot *= ctrl_DP_P.Gain_Gain_f;

  /* Sum: '<S33>/Sum1' */
  rtb_Row1_m += rtb_psi_dot;

  /* Math: '<S33>/Math Function' incorporates:
   *  Constant: '<S33>/Constant'
   */
  rtb_Row1_m = rt_remd_snf(rtb_Row1_m, ctrl_DP_P.Constant_Value_p);

  /* Sum: '<S33>/Sum' */
  rtb_Row1_m -= rtb_psi_dot;

  /* Fcn: '<S4>/Fcn' */
  rtb_psi_dot = rtb_Row1_m;

  /* Integrator: '<S4>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator2_Reset_ZCE,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator2_CSTATE[0] = ctrl_DP_P.Integrator2_IC[0];
      ctrl_DP_X.Integrator2_CSTATE[1] = ctrl_DP_P.Integrator2_IC[1];
      ctrl_DP_X.Integrator2_CSTATE[2] = ctrl_DP_P.Integrator2_IC[2];
    }
  }

  /* Sum: '<S4>/Sum' */
  rtb_Sum_idx_0 = ctrl_DP_B.mm2m - ctrl_DP_B.Integrator[0];
  rtb_Sum_idx_1 = ctrl_DP_B.Gain1 - ctrl_DP_B.Integrator[1];
  rtb_Sum_idx_2 = rtb_Row1_m - ctrl_DP_B.Sum_e;
  for (i = 0; i < 3; i++) {
    /* Integrator: '<S4>/Integrator2' */
    ctrl_DP_B.Integrator2[i] = ctrl_DP_X.Integrator2_CSTATE[i];

    /* Product: '<S4>/Matrix Multiply2' */
    rtb_TmpSignalConversionAtMatrix[i] = ctrl_DP_B.sf_MATLABFunction2.y[i + 6] *
      rtb_Sum_idx_2 + (ctrl_DP_B.sf_MATLABFunction2.y[i + 3] * rtb_Sum_idx_1 +
                       ctrl_DP_B.sf_MATLABFunction2.y[i] * rtb_Sum_idx_0);
  }

  /* Fcn: '<S30>/Row1' incorporates:
   *  Fcn: '<S4>/Fcn'
   */
  rtb_Row1_m = cos(rtb_Row1_m) * rtb_TmpSignalConversionAtMatrix[0] + sin
    (rtb_Row1_m) * rtb_TmpSignalConversionAtMatrix[1];

  /* Fcn: '<S30>/Row2' */
  rtb_Row2_p = -sin(rtb_psi_dot) * rtb_TmpSignalConversionAtMatrix[0] + cos
    (rtb_psi_dot) * rtb_TmpSignalConversionAtMatrix[1];

  /* Fcn: '<S30>/Row3' */
  rtb_Row3_f = rtb_TmpSignalConversionAtMatrix[2];

  /* Saturate: '<S19>/Saturation' incorporates:
   *  Fcn: '<S1>/yaw angle'
   */
  if (ctrl_DP_B.Sum > ctrl_DP_P.Saturation_UpperSat_l) {
    rtb_Row3_h = ctrl_DP_P.Saturation_UpperSat_l;
  } else if (ctrl_DP_B.Sum < ctrl_DP_P.Saturation_LowerSat_i) {
    rtb_Row3_h = ctrl_DP_P.Saturation_LowerSat_i;
  } else {
    rtb_Row3_h = ctrl_DP_B.Sum;
  }

  /* End of Saturate: '<S19>/Saturation' */

  /* Signum: '<S19>/Sign' */
  if (rtb_Row3_h < 0.0) {
    rtb_Row2_j = -1.0;
  } else if (rtb_Row3_h > 0.0) {
    rtb_Row2_j = 1.0;
  } else if (rtb_Row3_h == 0.0) {
    rtb_Row2_j = 0.0;
  } else {
    rtb_Row2_j = rtb_Row3_h;
  }

  /* End of Signum: '<S19>/Sign' */

  /* Gain: '<S19>/Gain' */
  rtb_Row2_j *= ctrl_DP_P.Gain_Gain_p;

  /* Sum: '<S19>/Sum1' */
  rtb_Row3_h += rtb_Row2_j;

  /* Math: '<S19>/Math Function' incorporates:
   *  Constant: '<S19>/Constant'
   */
  rtb_Row3_h = rt_remd_snf(rtb_Row3_h, ctrl_DP_P.Constant_Value_i);

  /* Sum: '<S19>/Sum' */
  rtb_Row3_h -= rtb_Row2_j;

  /* Integrator: '<S21>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_PrevZCX.Integrator1_Reset_ZCE_j,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (ctrl_DP_DW.Integrator1_IWORK != 0)) {
      ctrl_DP_X.Integrator1_CSTATE_g[0] = ctrl_DP_B.mm2m;
      ctrl_DP_X.Integrator1_CSTATE_g[1] = ctrl_DP_B.Gain1;
      ctrl_DP_X.Integrator1_CSTATE_g[2] = ctrl_DP_B.Sum;
    }
  }

  ctrl_DP_B.Integrator1_h[0] = ctrl_DP_X.Integrator1_CSTATE_g[0];
  ctrl_DP_B.Integrator1_h[1] = ctrl_DP_X.Integrator1_CSTATE_g[1];
  ctrl_DP_B.Integrator1_h[2] = ctrl_DP_X.Integrator1_CSTATE_g[2];

  /* End of Integrator: '<S21>/Integrator1' */

  /* Saturate: '<S22>/Saturation' */
  if (ctrl_DP_B.Integrator1_h[2] > ctrl_DP_P.Saturation_UpperSat_p) {
    rtb_Row2_j = ctrl_DP_P.Saturation_UpperSat_p;
  } else if (ctrl_DP_B.Integrator1_h[2] < ctrl_DP_P.Saturation_LowerSat_a) {
    rtb_Row2_j = ctrl_DP_P.Saturation_LowerSat_a;
  } else {
    rtb_Row2_j = ctrl_DP_B.Integrator1_h[2];
  }

  /* End of Saturate: '<S22>/Saturation' */

  /* Signum: '<S22>/Sign' */
  if (rtb_Row2_j < 0.0) {
    rtb_y_dot = -1.0;
  } else if (rtb_Row2_j > 0.0) {
    rtb_y_dot = 1.0;
  } else if (rtb_Row2_j == 0.0) {
    rtb_y_dot = 0.0;
  } else {
    rtb_y_dot = rtb_Row2_j;
  }

  /* End of Signum: '<S22>/Sign' */

  /* Gain: '<S22>/Gain' */
  rtb_y_dot *= ctrl_DP_P.Gain_Gain_a;

  /* Sum: '<S22>/Sum1' */
  rtb_Row2_j += rtb_y_dot;

  /* Math: '<S22>/Math Function' incorporates:
   *  Constant: '<S22>/Constant'
   */
  rtb_Row2_j = rt_remd_snf(rtb_Row2_j, ctrl_DP_P.Constant_Value_j);

  /* Sum: '<S22>/Sum' */
  ctrl_DP_B.Sum_a = rtb_Row2_j - rtb_y_dot;

  /* SignalConversion: '<S21>/TmpSignal ConversionAtMatrix Multiply2Inport2' */
  rtb_TmpSignalConversionAtMatrix[0] = ctrl_DP_B.Integrator1_h[0];
  rtb_TmpSignalConversionAtMatrix[1] = ctrl_DP_B.Integrator1_h[1];
  rtb_TmpSignalConversionAtMatrix[2] = ctrl_DP_B.Sum_a;

  /* Sum: '<S1>/Sum2' incorporates:
   *  SignalConversion: '<S21>/TmpSignal ConversionAtMatrix Multiply2Inport2'
   */
  ctrl_DP_B.Sum2[0] = ctrl_DP_B.mm2m - ctrl_DP_B.Integrator1_h[0];
  ctrl_DP_B.Sum2[1] = ctrl_DP_B.Gain1 - ctrl_DP_B.Integrator1_h[1];
  ctrl_DP_B.Sum2[2] = ctrl_DP_B.Sum - ctrl_DP_B.Sum_a;

  /* Saturate: '<S18>/Saturation' */
  if (ctrl_DP_B.Sum2[2] > ctrl_DP_P.Saturation_UpperSat_d) {
    rtb_y_dot = ctrl_DP_P.Saturation_UpperSat_d;
  } else if (ctrl_DP_B.Sum2[2] < ctrl_DP_P.Saturation_LowerSat_c) {
    rtb_y_dot = ctrl_DP_P.Saturation_LowerSat_c;
  } else {
    rtb_y_dot = ctrl_DP_B.Sum2[2];
  }

  /* End of Saturate: '<S18>/Saturation' */

  /* Signum: '<S18>/Sign' */
  if (rtb_y_dot < 0.0) {
    rtb_Row2_j = -1.0;
  } else if (rtb_y_dot > 0.0) {
    rtb_Row2_j = 1.0;
  } else if (rtb_y_dot == 0.0) {
    rtb_Row2_j = 0.0;
  } else {
    rtb_Row2_j = rtb_y_dot;
  }

  /* End of Signum: '<S18>/Sign' */

  /* Gain: '<S18>/Gain' */
  rtb_Row2_j *= ctrl_DP_P.Gain_Gain_ag;

  /* Sum: '<S18>/Sum1' */
  rtb_y_dot += rtb_Row2_j;

  /* Math: '<S18>/Math Function' incorporates:
   *  Constant: '<S18>/Constant'
   */
  rtb_y_dot = rt_remd_snf(rtb_y_dot, ctrl_DP_P.Constant_Value_l);

  /* Sum: '<S18>/Sum' */
  rtb_y_dot -= rtb_Row2_j;

  /* SignalConversion: '<S1>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Fcn: '<S16>/Row1'
   *  Fcn: '<S16>/Row2'
   *  Fcn: '<S16>/Row3'
   */
  ctrl_DP_B.TmpSignalConversionAtMatrixMult[0] = cos(rtb_Row3_h) *
    ctrl_DP_B.Sum2[0] + sin(rtb_Row3_h) * ctrl_DP_B.Sum2[1];
  ctrl_DP_B.TmpSignalConversionAtMatrixMult[1] = -sin(rtb_Row3_h) *
    ctrl_DP_B.Sum2[0] + cos(rtb_Row3_h) * ctrl_DP_B.Sum2[1];
  ctrl_DP_B.TmpSignalConversionAtMatrixMult[2] = rtb_y_dot;

  /* Integrator: '<S1>/Integrator' incorporates:
   *  Integrator: '<S21>/Integrator3'
   */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE_m,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_f[0] = ctrl_DP_P.Integrator_IC;
      ctrl_DP_X.Integrator_CSTATE_f[1] = ctrl_DP_P.Integrator_IC;
      ctrl_DP_X.Integrator_CSTATE_f[2] = ctrl_DP_P.Integrator_IC;
    }

    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator3_Reset_ZCE,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator3_CSTATE[0] = ctrl_DP_P.Integrator3_IC;
      ctrl_DP_X.Integrator3_CSTATE[1] = ctrl_DP_P.Integrator3_IC;
      ctrl_DP_X.Integrator3_CSTATE[2] = ctrl_DP_P.Integrator3_IC;
    }
  }

  /* Fcn: '<S17>/Row1' incorporates:
   *  SignalConversion: '<S21>/TmpSignal ConversionAtMatrix Multiply2Inport2'
   */
  rtb_TmpSignalConversionAtMatr_0[0] = ctrl_DP_B.Sum_a;
  rtb_TmpSignalConversionAtMatr_2[0] = ctrl_DP_B.Sum_a;

  /* Fcn: '<S17>/Row2' incorporates:
   *  SignalConversion: '<S21>/TmpSignal ConversionAtMatrix Multiply2Inport2'
   */
  rtb_TmpSignalConversionAtMatr_4[0] = ctrl_DP_B.Sum_a;
  rtb_TmpSignalConversionAtMatr_6[0] = ctrl_DP_B.Sum_a;
  for (i = 0; i < 3; i++) {
    /* Integrator: '<S21>/Integrator3' */
    ctrl_DP_B.Integrator3[i] = ctrl_DP_X.Integrator3_CSTATE[i];

    /* Sum: '<S1>/Sum3' incorporates:
     *  Product: '<S1>/Matrix Multiply'
     */
    tmp[i] = 0.0 - ((ctrl_DP_B.sf_MATLABFunction.y[i + 3] *
                     ctrl_DP_B.TmpSignalConversionAtMatrixMult[1] +
                     ctrl_DP_B.sf_MATLABFunction.y[i] *
                     ctrl_DP_B.TmpSignalConversionAtMatrixMult[0]) +
                    ctrl_DP_B.sf_MATLABFunction.y[i + 6] *
                    ctrl_DP_B.TmpSignalConversionAtMatrixMult[2]);

    /* Fcn: '<S17>/Row1' */
    rtb_TmpSignalConversionAtMatr_0[i + 1] = ctrl_DP_B.Integrator3[i];
    rtb_TmpSignalConversionAtMatr_1[i + 1] = ctrl_DP_B.Integrator3[i];
    rtb_TmpSignalConversionAtMatr_2[i + 1] = ctrl_DP_B.Integrator3[i];
    rtb_TmpSignalConversionAtMatr_3[i + 1] = ctrl_DP_B.Integrator3[i];

    /* Fcn: '<S17>/Row2' */
    rtb_TmpSignalConversionAtMatr_4[i + 1] = ctrl_DP_B.Integrator3[i];
    rtb_TmpSignalConversionAtMatr_5[i + 1] = ctrl_DP_B.Integrator3[i];
    rtb_TmpSignalConversionAtMatr_6[i + 1] = ctrl_DP_B.Integrator3[i];
    rtb_TmpSignalConversionAtMatr_7[i + 1] = ctrl_DP_B.Integrator3[i];

    /* Fcn: '<S17>/Row3' */
    rtb_TmpSignalConversionAtMatr_8[i + 1] = ctrl_DP_B.Integrator3[i];

    /* Product: '<S1>/Matrix Multiply1' incorporates:
     *  Integrator: '<S1>/Integrator'
     *  Sum: '<S1>/Sum3'
     */
    rtb_y_m[i] = ctrl_DP_B.sf_MATLABFunction1.y[i + 6] *
      ctrl_DP_X.Integrator_CSTATE_f[2] + (ctrl_DP_B.sf_MATLABFunction1.y[i + 3] *
      ctrl_DP_X.Integrator_CSTATE_f[1] + ctrl_DP_B.sf_MATLABFunction1.y[i] *
      ctrl_DP_X.Integrator_CSTATE_f[0]);
  }

  /* Sum: '<S1>/Sum4' incorporates:
   *  Fcn: '<S17>/Row1'
   *  Fcn: '<S17>/Row2'
   *  Fcn: '<S17>/Row3'
   *  Product: '<S1>/Matrix Multiply2'
   */
  rtb_y_dot = ctrl_DP_B.Integrator1[0] - (cos(rtb_TmpSignalConversionAtMatr_0[0])
    * rtb_TmpSignalConversionAtMatr_1[1] + sin(rtb_TmpSignalConversionAtMatr_2[0])
    * rtb_TmpSignalConversionAtMatr_3[2]);
  tmp_3 = ctrl_DP_B.Integrator1[1] - (-sin(rtb_TmpSignalConversionAtMatr_4[0]) *
    rtb_TmpSignalConversionAtMatr_5[1] + cos(rtb_TmpSignalConversionAtMatr_6[0])
    * rtb_TmpSignalConversionAtMatr_7[2]);
  tmp_4 = ctrl_DP_B.Integrator1[2] - rtb_TmpSignalConversionAtMatr_8[3];

  /* MATLAB Function: '<S4>/C(nu)*nu' */
  /* MATLAB Function 'Nonlinear Passisve Observer/D(nu)*nu': '<S28>:1' */
  /* '<S28>:1:3' */
  /* '<S28>:1:4' */
  /* '<S28>:1:5' */
  /*  DAMPING  */
  /*  Surge: */
  /*  Based on fitting of towing data from -0.8 < u < 0.8 m/s */
  /* '<S28>:1:11' */
  /* '<S28>:1:12' */
  /* '<S28>:1:13' */
  /*  Sway: */
  /*  Based on fitting of towing data from -0.45 < u < 0.45 m/s */
  /* '<S28>:1:17' */
  /* '<S28>:1:18' */
  /* '<S28>:1:19' */
  /*  Yaw: */
  /*  Based on fitting of towing data from -8 < u < 8 deg/s */
  /*  The fitting range is limited. Towing should be performed for higher */
  /*  velocities. */
  /* '<S28>:1:25' */
  /* '<S28>:1:26' */
  /* '<S28>:1:27' */
  /*  Y_vvv og N_rrr er fra curvefitting uten minus, men ser ut til å fungere */
  /*  med minus.  */
  /*  Assembly of the damping matrix */
  /* '<S28>:1:40' */
  /* '<S28>:1:41' */
  /* '<S28>:1:42' */
  /*  Y_r + Y_rr*abs(r) + Y_rrr*r^2 + Y_vr*abs(v); Not verified, temporarily disabled */
  /*  N_v + N_vv*abs(v) + N_vvv*v^2 + N_rv*abs(r); Not verified, temporarily disabled */
  /* '<S28>:1:47' */
  /* '<S28>:1:54' */
  /* MATLAB Function 'Nonlinear Passisve Observer/C(nu)*nu': '<S27>:1' */
  /* '<S27>:1:3' */
  /* '<S27>:1:4' */
  /* '<S27>:1:5' */
  /*  MATRICES */
  /* '<S27>:1:8' */
  /* 0.0432; */
  /*  Added mass */
  /* '<S27>:1:11' */
  /*  Correolis matrix */
  /* '<S27>:1:14' */
  rtb_Row3_h = -99.03 * ctrl_DP_B.Integrator1[1] - -0.525 *
    ctrl_DP_B.Integrator1[2];

  /* '<S27>:1:15' */
  rtb_Row2_j = 124.658 * ctrl_DP_B.Integrator1[0];

  /* Fcn: '<S31>/Row1' */
  /* '<S27>:1:17' */
  /* '<S27>:1:24' */
  rtb_psi_dot_0[0] = rtb_psi_dot;
  rtb_psi_dot_1[0] = rtb_psi_dot;

  /* Fcn: '<S31>/Row2' */
  rtb_psi_dot_2[0] = rtb_psi_dot;
  rtb_psi_dot_3[0] = rtb_psi_dot;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S1>/Sum3' incorporates:
     *  Product: '<S1>/Matrix Multiply2'
     */
    rtb_Sum3[i] = (tmp[i] - rtb_y_m[i]) - ((ctrl_DP_B.sf_MATLABFunction2_c.y[i +
      3] * tmp_3 + ctrl_DP_B.sf_MATLABFunction2_c.y[i] * rtb_y_dot) +
      ctrl_DP_B.sf_MATLABFunction2_c.y[i + 6] * tmp_4);

    /* Fcn: '<S31>/Row1' */
    rtb_psi_dot_0[i + 1] = ctrl_DP_B.Integrator2[i];
    rtb_TmpSignalConversionAtMatr_0[i + 1] = ctrl_DP_B.Integrator2[i];
    rtb_psi_dot_1[i + 1] = ctrl_DP_B.Integrator2[i];
    rtb_TmpSignalConversionAtMatr_1[i + 1] = ctrl_DP_B.Integrator2[i];

    /* Fcn: '<S31>/Row2' */
    rtb_psi_dot_2[i + 1] = ctrl_DP_B.Integrator2[i];
    rtb_TmpSignalConversionAtMatr_2[i + 1] = ctrl_DP_B.Integrator2[i];
    rtb_psi_dot_3[i + 1] = ctrl_DP_B.Integrator2[i];
    rtb_TmpSignalConversionAtMatr_3[i + 1] = ctrl_DP_B.Integrator2[i];

    /* Fcn: '<S31>/Row3' */
    rtb_TmpSignalConversionAtMatr_4[i + 1] = ctrl_DP_B.Integrator2[i];
  }

  /* Sum: '<S4>/Sum2' */
  rtb_Row1_n[0] = rtb_Row1_m;
  rtb_Row1_n[1] = rtb_Row2_p;
  rtb_Row1_n[2] = rtb_Row3_f;

  /* Sum: '<S4>/Sum3' incorporates:
   *  Fcn: '<S31>/Row1'
   *  Fcn: '<S31>/Row2'
   *  Fcn: '<S31>/Row3'
   */
  tmp_0[0] = cos(rtb_psi_dot_0[0]) * rtb_TmpSignalConversionAtMatr_0[1] + sin
    (rtb_psi_dot_1[0]) * rtb_TmpSignalConversionAtMatr_1[2];
  tmp_0[1] = -sin(rtb_psi_dot_2[0]) * rtb_TmpSignalConversionAtMatr_2[1] + cos
    (rtb_psi_dot_3[0]) * rtb_TmpSignalConversionAtMatr_3[2];
  tmp_0[2] = rtb_TmpSignalConversionAtMatr_4[3];

  /* MATLAB Function: '<S4>/D(nu)*nu' */
  x[0] = (0.0 * fabs(ctrl_DP_B.Integrator1[0]) + -2.332) +
    ctrl_DP_B.Integrator1[0] * ctrl_DP_B.Integrator1[0] * -8.557;
  x[3] = 0.0;
  x[6] = 0.0;
  x[1] = 0.0;
  x[4] = (0.3976 * fabs(ctrl_DP_B.Integrator1[1]) + -4.673) +
    ctrl_DP_B.Integrator1[1] * ctrl_DP_B.Integrator1[1] * -313.3;
  x[7] = 0.0;
  x[2] = 0.0;
  x[5] = 0.0;
  x[8] = (-0.01148 * fabs(ctrl_DP_B.Integrator1[2]) + -0.01675) +
    ctrl_DP_B.Integrator1[2] * ctrl_DP_B.Integrator1[2] * -0.0003578;
  for (i = 0; i < 3; i++) {
    rtb_y_b[3 * i] = -x[3 * i];
    rtb_y_b[1 + 3 * i] = -x[3 * i + 1];
    rtb_y_b[2 + 3 * i] = -x[3 * i + 2];
  }

  /* MATLAB Function: '<S4>/C(nu)*nu' */
  tmp_1[0] = 0.0;
  tmp_1[3] = 0.0;
  tmp_1[6] = rtb_Row3_h;
  tmp_1[1] = 0.0;
  tmp_1[4] = 0.0;
  tmp_1[7] = rtb_Row2_j;
  tmp_1[2] = -rtb_Row3_h;
  tmp_1[5] = -rtb_Row2_j;
  tmp_1[8] = 0.0;
  for (i = 0; i < 3; i++) {
    /* Sum: '<S4>/Sum3' incorporates:
     *  Gain: '<S4>/M^-1'
     *  MATLAB Function: '<S4>/C(nu)*nu'
     *  MATLAB Function: '<S4>/D(nu)*nu'
     *  Sum: '<S4>/Sum2'
     */
    tmp[i] = (((rtb_Row1_n[i] + rtb_Sum3[i]) + tmp_0[i]) - ((rtb_y_b[i + 3] *
                ctrl_DP_B.Integrator1[1] + rtb_y_b[i] * ctrl_DP_B.Integrator1[0])
               + rtb_y_b[i + 6] * ctrl_DP_B.Integrator1[2])) - (tmp_1[i + 6] *
      ctrl_DP_B.Integrator1[2] + (tmp_1[i + 3] * ctrl_DP_B.Integrator1[1] +
      tmp_1[i] * ctrl_DP_B.Integrator1[0]));
  }

  /* Gain: '<S4>/M^-1' */
  for (i = 0; i < 3; i++) {
    ctrl_DP_B.M1[i] = 0.0;
    ctrl_DP_B.M1[i] += ctrl_DP_P.M1_Gain[i] * tmp[0];
    ctrl_DP_B.M1[i] += ctrl_DP_P.M1_Gain[i + 3] * tmp[1];
    ctrl_DP_B.M1[i] += ctrl_DP_P.M1_Gain[i + 6] * tmp[2];
  }

  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Memory: '<S8>/Memory4' */
    for (i = 0; i < 6; i++) {
      ctrl_DP_B.Memory4[i] = ctrl_DP_DW.Memory4_PreviousInput[i];
    }

    /* End of Memory: '<S8>/Memory4' */
  }

  /* Gain: '<S11>/Gain' */
  for (i = 0; i < 12; i++) {
    rtb_u_e[i] = ctrl_DP_P.T_pinv[i + 24] * rtb_Sum3[2] + (ctrl_DP_P.T_pinv[i +
      12] * rtb_Sum3[1] + ctrl_DP_P.T_pinv[i] * rtb_Sum3[0]);
  }

  /* End of Gain: '<S11>/Gain' */

  /* MATLAB Function: '<S11>/MATLAB Function11' */
  /* MATLAB Function 'Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11': '<S57>:1' */
  /* '<S57>:1:2' */
  rtb_Row1_m = ctrl_DP_norm_e(&rtb_u_e[0]);
  rtb_Row2_p = ctrl_DP_norm_e(&rtb_u_e[2]);
  rtb_Row3_f = ctrl_DP_norm_e(&rtb_u_e[4]);
  rtb_Row3_h = ctrl_DP_norm_e(&rtb_u_e[6]);
  rtb_Row2_j = ctrl_DP_norm_e(&rtb_u_e[8]);
  rtb_y_dot = ctrl_DP_norm_e(&rtb_u_e[10]);
  ctrl_DP_B.u[0] = rtb_Row1_m;
  ctrl_DP_B.u[1] = rtb_Row2_p;
  ctrl_DP_B.u[2] = rtb_Row3_f;
  ctrl_DP_B.u[3] = rtb_Row3_h;
  ctrl_DP_B.u[4] = rtb_Row2_j;
  ctrl_DP_B.u[5] = rtb_y_dot;

  /* '<S57>:1:10' */
  rtb_alpha[0] = rt_atan2d_snf(rtb_u_e[1], rtb_u_e[0]);
  rtb_alpha[1] = rt_atan2d_snf(rtb_u_e[3], rtb_u_e[2]);
  rtb_alpha[2] = rt_atan2d_snf(rtb_u_e[5], rtb_u_e[4]);
  rtb_alpha[3] = rt_atan2d_snf(rtb_u_e[7], rtb_u_e[6]);
  rtb_alpha[4] = rt_atan2d_snf(rtb_u_e[9], rtb_u_e[8]);
  rtb_alpha[5] = rt_atan2d_snf(rtb_u_e[11], rtb_u_e[10]);

  /* MATLAB Function: '<S8>/MATLAB Function11' */
  /* MATLAB Function 'Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11': '<S49>:1' */
  /* '<S49>:1:1' */
  /* '<S49>:1:4' */
  for (i = 0; i < 6; i++) {
    /* '<S49>:1:4' */
    /*  current rotation */
    /* '<S49>:1:6' */
    /* '<S49>:1:8' */
    if (ctrl_DP_B.Memory4[i] < 0.0) {
      rtb_Row1_m = -1.0;
    } else if (ctrl_DP_B.Memory4[i] > 0.0) {
      rtb_Row1_m = 1.0;
    } else if (ctrl_DP_B.Memory4[i] == 0.0) {
      rtb_Row1_m = 0.0;
    } else {
      rtb_Row1_m = ctrl_DP_B.Memory4[i];
    }

    ctrl_DP_B.alpha_infinf[i] = floor((fabs(ctrl_DP_B.Memory4[i]) +
      3.1415926535897931) / 6.2831853071795862) * rtb_Row1_m *
      6.2831853071795862 + rtb_alpha[i];

    /* '<S49>:1:10' */
    rtb_Row1_m = ctrl_DP_B.alpha_infinf[i] - ctrl_DP_B.Memory4[i];

    /*  Shortest rotation */
    if (fabs(rtb_Row1_m) > 3.1415926535897931) {
      /* '<S49>:1:13' */
      /* '<S49>:1:14' */
      if (rtb_Row1_m < 0.0) {
        rtb_Row1_m = -1.0;
      } else if (rtb_Row1_m > 0.0) {
        rtb_Row1_m = 1.0;
      } else {
        if (rtb_Row1_m == 0.0) {
          rtb_Row1_m = 0.0;
        }
      }

      ctrl_DP_B.alpha_infinf[i] -= rtb_Row1_m * 2.0 * 3.1415926535897931;
    }
  }

  /* End of MATLAB Function: '<S8>/MATLAB Function11' */

  /* Integrator: '<S21>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_PrevZCX.Integrator2_Reset_ZCE_h,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator2_CSTATE_c[0] = ctrl_DP_P.Integrator2_IC_p;
      ctrl_DP_X.Integrator2_CSTATE_c[1] = ctrl_DP_P.Integrator2_IC_p;
      ctrl_DP_X.Integrator2_CSTATE_c[2] = ctrl_DP_P.Integrator2_IC_p;
    }
  }

  /* MATLAB Function: '<S21>/w_d^-2' */
  /* MATLAB Function 'Guidance/Reference model/w_d^3': '<S26>:1' */
  /* '<S26>:1:4' */
  /* MATLAB Function 'Guidance/Reference model/w_d^-2': '<S25>:1' */
  /* '<S25>:1:4' */
  for (i = 0; i < 3; i++) {
    for (p2 = 0; p2 < 3; p2++) {
      rtb_y_b[p2 + 3 * i] = 0.0;
      rtb_y_b[p2 + 3 * i] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * i] *
        ctrl_DP_B.sf_MATLABFunction_d.y[p2];
      rtb_y_b[p2 + 3 * i] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * i + 1] *
        ctrl_DP_B.sf_MATLABFunction_d.y[p2 + 3];
      rtb_y_b[p2 + 3 * i] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * i + 2] *
        ctrl_DP_B.sf_MATLABFunction_d.y[p2 + 6];
    }
  }

  memcpy(&x[0], &rtb_y_b[0], 9U * sizeof(real_T));
  i = 0;
  p2 = 3;
  p3 = 6;
  rtb_Row1_m = fabs(rtb_y_b[0]);
  rtb_Row2_p = fabs(rtb_y_b[1]);
  rtb_Row3_f = fabs(rtb_y_b[2]);
  if ((rtb_Row2_p > rtb_Row1_m) && (rtb_Row2_p > rtb_Row3_f)) {
    i = 3;
    p2 = 0;
    x[0] = rtb_y_b[1];
    x[1] = rtb_y_b[0];
    x[3] = rtb_y_b[4];
    x[4] = rtb_y_b[3];
    x[6] = rtb_y_b[7];
    x[7] = rtb_y_b[6];
  } else {
    if (rtb_Row3_f > rtb_Row1_m) {
      i = 6;
      p3 = 0;
      x[0] = rtb_y_b[2];
      x[2] = rtb_y_b[0];
      x[3] = rtb_y_b[5];
      x[5] = rtb_y_b[3];
      x[6] = rtb_y_b[8];
      x[8] = rtb_y_b[6];
    }
  }

  rtb_Row1_m = x[1] / x[0];
  x[1] /= x[0];
  rtb_Row2_p = x[2] / x[0];
  x[2] /= x[0];
  x[4] -= rtb_Row1_m * x[3];
  x[5] -= rtb_Row2_p * x[3];
  x[7] -= rtb_Row1_m * x[6];
  x[8] -= rtb_Row2_p * x[6];
  if (fabs(x[5]) > fabs(x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    x[1] = rtb_Row2_p;
    x[2] = rtb_Row1_m;
    rtb_Row1_m = x[4];
    x[4] = x[5];
    x[5] = rtb_Row1_m;
    rtb_Row1_m = x[7];
    x[7] = x[8];
    x[8] = rtb_Row1_m;
  }

  rtb_Row1_m = x[5] / x[4];
  x[5] /= x[4];
  x[8] -= rtb_Row1_m * x[7];
  rtb_Row1_m = (x[5] * x[1] - x[2]) / x[8];
  rtb_Row2_p = -(x[7] * rtb_Row1_m + x[1]) / x[4];
  rtb_y_b[i] = ((1.0 - x[3] * rtb_Row2_p) - x[6] * rtb_Row1_m) / x[0];
  rtb_y_b[i + 1] = rtb_Row2_p;
  rtb_y_b[i + 2] = rtb_Row1_m;
  rtb_Row1_m = -x[5] / x[8];
  rtb_Row2_p = (1.0 - x[7] * rtb_Row1_m) / x[4];
  rtb_y_b[p2] = -(x[3] * rtb_Row2_p + x[6] * rtb_Row1_m) / x[0];
  rtb_y_b[p2 + 1] = rtb_Row2_p;
  rtb_y_b[p2 + 2] = rtb_Row1_m;
  rtb_Row1_m = 1.0 / x[8];
  rtb_Row2_p = -x[7] * rtb_Row1_m / x[4];
  rtb_y_b[p3] = -(x[3] * rtb_Row2_p + x[6] * rtb_Row1_m) / x[0];
  rtb_y_b[p3 + 1] = rtb_Row2_p;
  rtb_y_b[p3 + 2] = rtb_Row1_m;

  /* End of MATLAB Function: '<S21>/w_d^-2' */

  /* Sum: '<S21>/Sum' incorporates:
   *  Gain: '<S6>/deg2rad'
   */
  tmp_2[0] = ctrl_DP_B.x_ref;
  tmp_2[1] = ctrl_DP_B.y_ref;
  tmp_2[2] = ctrl_DP_P.deg2rad_Gain_l * ctrl_DP_B.psi_refdeg;
  for (i = 0; i < 3; i++) {
    /* Product: '<S21>/Matrix Multiply1' incorporates:
     *  Sum: '<S21>/Sum'
     */
    rtb_y_m[i] = 0.0;
    for (p2 = 0; p2 < 3; p2++) {
      /* MATLAB Function: '<S21>/w_d^3' */
      x[i + 3 * p2] = 0.0;
      x[i + 3 * p2] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * p2] *
        ctrl_DP_B.sf_MATLABFunction_d.y[i];
      x[i + 3 * p2] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * p2 + 1] *
        ctrl_DP_B.sf_MATLABFunction_d.y[i + 3];
      x[i + 3 * p2] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * p2 + 2] *
        ctrl_DP_B.sf_MATLABFunction_d.y[i + 6];

      /* Product: '<S21>/Matrix Multiply1' incorporates:
       *  Integrator: '<S21>/Integrator2'
       *  Sum: '<S21>/Sum'
       */
      rtb_y_m[i] += rtb_y_b[3 * p2 + i] * ctrl_DP_X.Integrator2_CSTATE_c[p2];
    }
  }

  for (i = 0; i < 3; i++) {
    /* MATLAB Function: '<S21>/w_d^3' incorporates:
     *  Product: '<S21>/Matrix Multiply'
     */
    for (p2 = 0; p2 < 3; p2++) {
      rtb_y_b[i + 3 * p2] = 0.0;
      rtb_y_b[i + 3 * p2] += x[3 * p2] * ctrl_DP_B.sf_MATLABFunction_d.y[i];
      rtb_y_b[i + 3 * p2] += x[3 * p2 + 1] * ctrl_DP_B.sf_MATLABFunction_d.y[i +
        3];
      rtb_y_b[i + 3 * p2] += x[3 * p2 + 2] * ctrl_DP_B.sf_MATLABFunction_d.y[i +
        6];
    }

    /* Sum: '<S21>/Sum' incorporates:
     *  Product: '<S21>/Matrix Multiply'
     */
    tmp[i] = tmp_2[i] - rtb_y_m[i];
  }

  /* MATLAB Function 'Guidance/Reference model/w_d*w_d': '<S23>:1' */
  /* '<S23>:1:4' */
  for (i = 0; i < 3; i++) {
    /* Product: '<S21>/Matrix Multiply' */
    ctrl_DP_B.MatrixMultiply[i] = 0.0;

    /* Product: '<S21>/Matrix Multiply2' */
    rtb_Sum3[i] = 0.0;
    for (p2 = 0; p2 < 3; p2++) {
      /* Product: '<S21>/Matrix Multiply' */
      ctrl_DP_B.MatrixMultiply[i] += rtb_y_b[3 * p2 + i] * tmp[p2];

      /* MATLAB Function: '<S21>/w_d*w_d' incorporates:
       *  Product: '<S21>/Matrix Multiply2'
       */
      x[i + 3 * p2] = 0.0;
      x[i + 3 * p2] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * p2] *
        ctrl_DP_B.sf_MATLABFunction_d.y[i];
      x[i + 3 * p2] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * p2 + 1] *
        ctrl_DP_B.sf_MATLABFunction_d.y[i + 3];
      x[i + 3 * p2] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * p2 + 2] *
        ctrl_DP_B.sf_MATLABFunction_d.y[i + 6];

      /* Product: '<S21>/Matrix Multiply2' */
      rtb_Sum3[i] += x[3 * p2 + i] * rtb_TmpSignalConversionAtMatrix[p2];
    }
  }

  /* MATLAB Function: '<S39>/MATLAB Function1' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.zeta_x, ctrl_DP_B.zeta_y, ctrl_DP_B.zeta_psi,
    &ctrl_DP_B.sf_MATLABFunction1_c);  /* MATLAB Function 'Guidance/Reference model/w_d*w_d1': '<S24>:1' */

  /* '<S24>:1:4' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S21>/Sum5' */
    rtb_Row1_m = 0.0;
    for (p2 = 0; p2 < 3; p2++) {
      /* MATLAB Function: '<S21>/w_d*w_d1' incorporates:
       *  Product: '<S21>/Matrix Multiply5'
       */
      x[i + 3 * p2] = 0.0;
      x[i + 3 * p2] += 2.0 * ctrl_DP_B.sf_MATLABFunction1_c.y[i] *
        ctrl_DP_B.sf_MATLABFunction_d.y[3 * p2];
      x[i + 3 * p2] += ctrl_DP_B.sf_MATLABFunction1_c.y[i + 3] * 2.0 *
        ctrl_DP_B.sf_MATLABFunction_d.y[3 * p2 + 1];
      x[i + 3 * p2] += ctrl_DP_B.sf_MATLABFunction1_c.y[i + 6] * 2.0 *
        ctrl_DP_B.sf_MATLABFunction_d.y[3 * p2 + 2];

      /* Sum: '<S21>/Sum5' incorporates:
       *  Product: '<S21>/Matrix Multiply5'
       */
      rtb_Row1_m += x[3 * p2 + i] * ctrl_DP_B.Integrator3[p2];
    }

    /* Sum: '<S21>/Sum5' incorporates:
     *  Integrator: '<S21>/Integrator2'
     *  Product: '<S21>/Matrix Multiply5'
     *  Sum: '<S21>/Sum2'
     */
    ctrl_DP_B.Sum5[i] = (ctrl_DP_X.Integrator2_CSTATE_c[i] - rtb_Sum3[i]) -
      rtb_Row1_m;
  }

  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* MATLAB Function: '<S40>/MATLAB Function' incorporates:
     *  Constant: '<S40>/Constant'
     *  Constant: '<S40>/Constant1'
     *  Constant: '<S40>/Constant2'
     */
    ctrl_DP_MATLABFunction(ctrl_DP_P.Constant_Value_c,
      ctrl_DP_P.Constant1_Value_p, ctrl_DP_P.Constant2_Value,
      &ctrl_DP_B.sf_MATLABFunction_p);
  }

  /* Product: '<S4>/Matrix Multiply' */
  for (i = 0; i < 3; i++) {
    rtb_TmpSignalConversionAtMatrix[i] = ctrl_DP_B.sf_MATLABFunction_p.y[i + 6] *
      rtb_Sum_idx_2 + (ctrl_DP_B.sf_MATLABFunction_p.y[i + 3] * rtb_Sum_idx_1 +
                       ctrl_DP_B.sf_MATLABFunction_p.y[i] * rtb_Sum_idx_0);
  }

  /* End of Product: '<S4>/Matrix Multiply' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* MATLAB Function: '<S40>/MATLAB Function1' incorporates:
     *  Constant: '<S40>/Constant3'
     *  Constant: '<S40>/Constant4'
     *  Constant: '<S40>/Constant5'
     */
    ctrl_DP_MATLABFunction(ctrl_DP_P.Constant3_Value, ctrl_DP_P.Constant4_Value,
      ctrl_DP_P.Constant5_Value, &ctrl_DP_B.sf_MATLABFunction1_k);
  }

  /* Product: '<S4>/Matrix Multiply1' */
  for (i = 0; i < 3; i++) {
    ctrl_DP_B.MatrixMultiply1[i] = 0.0;
    ctrl_DP_B.MatrixMultiply1[i] += ctrl_DP_B.sf_MATLABFunction1_k.y[i] *
      rtb_Sum_idx_0;
    ctrl_DP_B.MatrixMultiply1[i] += ctrl_DP_B.sf_MATLABFunction1_k.y[i + 3] *
      rtb_Sum_idx_1;
    ctrl_DP_B.MatrixMultiply1[i] += ctrl_DP_B.sf_MATLABFunction1_k.y[i + 6] *
      rtb_Sum_idx_2;
  }

  /* End of Product: '<S4>/Matrix Multiply1' */

  /* Sum: '<S4>/Sum1' incorporates:
   *  Fcn: '<S29>/Fcn'
   *  Fcn: '<S29>/Fcn1'
   *  Fcn: '<S29>/Fcn2'
   */
  ctrl_DP_B.Sum1[0] = (cos(rtb_psi_dot) * ctrl_DP_B.Integrator1[0] - sin
                       (rtb_psi_dot) * ctrl_DP_B.Integrator1[1]) +
    rtb_TmpSignalConversionAtMatrix[0];
  ctrl_DP_B.Sum1[1] = (sin(rtb_psi_dot) * ctrl_DP_B.Integrator1[0] + cos
                       (rtb_psi_dot) * ctrl_DP_B.Integrator1[1]) +
    rtb_TmpSignalConversionAtMatrix[1];
  ctrl_DP_B.Sum1[2] = rtb_TmpSignalConversionAtMatrix[2] +
    ctrl_DP_B.Integrator1[2];
}

/* Model update function */
void ctrl_DP_update(void)
{
  int32_T i;

  /* Update for Integrator: '<S4>/Integrator' */
  ctrl_DP_DW.Integrator_IWORK = 0;

  /* Update for Integrator: '<S21>/Integrator1' */
  ctrl_DP_DW.Integrator1_IWORK = 0;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Update for Memory: '<S8>/Memory4' */
    for (i = 0; i < 6; i++) {
      ctrl_DP_DW.Memory4_PreviousInput[i] = ctrl_DP_B.alpha_infinf[i];
    }

    /* End of Update for Memory: '<S8>/Memory4' */
  }

  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_DP_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_DP_M->Timing.clockTick0)) {
    ++ctrl_DP_M->Timing.clockTickH0;
  }

  ctrl_DP_M->Timing.t[0] = rtsiGetSolverStopTime(&ctrl_DP_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_DP_M->Timing.clockTick1)) {
      ++ctrl_DP_M->Timing.clockTickH1;
    }

    ctrl_DP_M->Timing.t[1] = ctrl_DP_M->Timing.clockTick1 *
      ctrl_DP_M->Timing.stepSize1 + ctrl_DP_M->Timing.clockTickH1 *
      ctrl_DP_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_DP_derivatives(void)
{
  XDot_ctrl_DP_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_DP_T *) ctrl_DP_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_DP_B.Sum1[0];

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ctrl_DP_B.M1[0];

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_DP_B.MatrixMultiply1[0];

  /* Derivatives for Integrator: '<S21>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_g[0] = ctrl_DP_B.Integrator3[0];

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE_f[0] = ctrl_DP_B.TmpSignalConversionAtMatrixMult[0];

  /* Derivatives for Integrator: '<S21>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[0] = ctrl_DP_B.Sum5[0];

  /* Derivatives for Integrator: '<S21>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_c[0] = ctrl_DP_B.MatrixMultiply[0];

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = ctrl_DP_B.Sum1[1];

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = ctrl_DP_B.M1[1];

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[1] = ctrl_DP_B.MatrixMultiply1[1];

  /* Derivatives for Integrator: '<S21>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_g[1] = ctrl_DP_B.Integrator3[1];

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE_f[1] = ctrl_DP_B.TmpSignalConversionAtMatrixMult[1];

  /* Derivatives for Integrator: '<S21>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[1] = ctrl_DP_B.Sum5[1];

  /* Derivatives for Integrator: '<S21>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_c[1] = ctrl_DP_B.MatrixMultiply[1];

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE[2] = ctrl_DP_B.Sum1[2];

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[2] = ctrl_DP_B.M1[2];

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[2] = ctrl_DP_B.MatrixMultiply1[2];

  /* Derivatives for Integrator: '<S21>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_g[2] = ctrl_DP_B.Integrator3[2];

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE_f[2] = ctrl_DP_B.TmpSignalConversionAtMatrixMult[2];

  /* Derivatives for Integrator: '<S21>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[2] = ctrl_DP_B.Sum5[2];

  /* Derivatives for Integrator: '<S21>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_c[2] = ctrl_DP_B.MatrixMultiply[2];
}

/* Model initialize function */
void ctrl_DP_initialize(void)
{
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator1_Reset_ZCE_j = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_m = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator3_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator2_Reset_ZCE_h = UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S4>/Integrator' incorporates:
     *  InitializeConditions for Integrator: '<S21>/Integrator1'
     */
    if (rtmIsFirstInitCond(ctrl_DP_M)) {
      ctrl_DP_X.Integrator_CSTATE[0] = 0.0;
      ctrl_DP_X.Integrator_CSTATE[1] = 0.0;
      ctrl_DP_X.Integrator_CSTATE[2] = 0.0;
      ctrl_DP_X.Integrator1_CSTATE_g[0] = 0.0;
      ctrl_DP_X.Integrator1_CSTATE_g[1] = 0.0;
      ctrl_DP_X.Integrator1_CSTATE_g[2] = 0.0;
    }

    ctrl_DP_DW.Integrator_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S4>/Integrator' */

    /* InitializeConditions for Integrator: '<S4>/Integrator1' */
    ctrl_DP_X.Integrator1_CSTATE[0] = ctrl_DP_P.Integrator1_IC[0];

    /* InitializeConditions for Integrator: '<S4>/Integrator2' */
    ctrl_DP_X.Integrator2_CSTATE[0] = ctrl_DP_P.Integrator2_IC[0];

    /* InitializeConditions for Integrator: '<S4>/Integrator1' */
    ctrl_DP_X.Integrator1_CSTATE[1] = ctrl_DP_P.Integrator1_IC[1];

    /* InitializeConditions for Integrator: '<S4>/Integrator2' */
    ctrl_DP_X.Integrator2_CSTATE[1] = ctrl_DP_P.Integrator2_IC[1];

    /* InitializeConditions for Integrator: '<S4>/Integrator1' */
    ctrl_DP_X.Integrator1_CSTATE[2] = ctrl_DP_P.Integrator1_IC[2];

    /* InitializeConditions for Integrator: '<S4>/Integrator2' */
    ctrl_DP_X.Integrator2_CSTATE[2] = ctrl_DP_P.Integrator2_IC[2];

    /* InitializeConditions for Integrator: '<S21>/Integrator1' */
    ctrl_DP_DW.Integrator1_IWORK = 1;

    /* InitializeConditions for Integrator: '<S1>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_f[0] = ctrl_DP_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S21>/Integrator3' */
    ctrl_DP_X.Integrator3_CSTATE[0] = ctrl_DP_P.Integrator3_IC;

    /* InitializeConditions for Integrator: '<S1>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_f[1] = ctrl_DP_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S21>/Integrator3' */
    ctrl_DP_X.Integrator3_CSTATE[1] = ctrl_DP_P.Integrator3_IC;

    /* InitializeConditions for Integrator: '<S1>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_f[2] = ctrl_DP_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S21>/Integrator3' */
    ctrl_DP_X.Integrator3_CSTATE[2] = ctrl_DP_P.Integrator3_IC;

    /* InitializeConditions for Memory: '<S8>/Memory4' */
    for (i = 0; i < 6; i++) {
      ctrl_DP_DW.Memory4_PreviousInput[i] = ctrl_DP_P.Memory4_X0[i];
    }

    /* End of InitializeConditions for Memory: '<S8>/Memory4' */

    /* InitializeConditions for Integrator: '<S21>/Integrator2' */
    ctrl_DP_X.Integrator2_CSTATE_c[0] = ctrl_DP_P.Integrator2_IC_p;
    ctrl_DP_X.Integrator2_CSTATE_c[1] = ctrl_DP_P.Integrator2_IC_p;
    ctrl_DP_X.Integrator2_CSTATE_c[2] = ctrl_DP_P.Integrator2_IC_p;

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(ctrl_DP_M)) {
      rtmSetFirstInitCond(ctrl_DP_M, 0);
    }
  }
}

/* Model terminate function */
void ctrl_DP_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ctrl_DP_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_DP_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ctrl_DP_initialize();
}

void MdlTerminate(void)
{
  ctrl_DP_terminate();
}

/* Registration function */
RT_MODEL_ctrl_DP_T *ctrl_DP(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_DP_M, 0,
                sizeof(RT_MODEL_ctrl_DP_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_DP_M->solverInfo, &ctrl_DP_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_DP_M->solverInfo, &rtmGetTPtr(ctrl_DP_M));
    rtsiSetStepSizePtr(&ctrl_DP_M->solverInfo, &ctrl_DP_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_DP_M->solverInfo, &ctrl_DP_M->derivs);
    rtsiSetContStatesPtr(&ctrl_DP_M->solverInfo, (real_T **)
                         &ctrl_DP_M->contStates);
    rtsiSetNumContStatesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ctrl_DP_M->solverInfo, (&rtmGetErrorStatus(ctrl_DP_M)));
    rtsiSetRTModelPtr(&ctrl_DP_M->solverInfo, ctrl_DP_M);
  }

  rtsiSetSimTimeStep(&ctrl_DP_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_DP_M->intgData.y = ctrl_DP_M->odeY;
  ctrl_DP_M->intgData.f[0] = ctrl_DP_M->odeF[0];
  ctrl_DP_M->intgData.f[1] = ctrl_DP_M->odeF[1];
  ctrl_DP_M->intgData.f[2] = ctrl_DP_M->odeF[2];
  ctrl_DP_M->contStates = ((real_T *) &ctrl_DP_X);
  rtsiSetSolverData(&ctrl_DP_M->solverInfo, (void *)&ctrl_DP_M->intgData);
  rtsiSetSolverName(&ctrl_DP_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_DP_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_DP_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_DP_M->Timing.sampleTimes = (&ctrl_DP_M->Timing.sampleTimesArray[0]);
    ctrl_DP_M->Timing.offsetTimes = (&ctrl_DP_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_DP_M->Timing.sampleTimes[0] = (0.0);
    ctrl_DP_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_DP_M->Timing.offsetTimes[0] = (0.0);
    ctrl_DP_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_DP_M, &ctrl_DP_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_DP_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_DP_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_DP_M, -1);
  ctrl_DP_M->Timing.stepSize0 = 0.01;
  ctrl_DP_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_DP_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ctrl_DP_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_DP_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_DP_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_DP_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_DP_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_DP_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_DP_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_DP_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_DP_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_DP_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_DP_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_DP_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_DP_M->rtwLogInfo, (NULL));
  }

  ctrl_DP_M->solverInfoPtr = (&ctrl_DP_M->solverInfo);
  ctrl_DP_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_DP_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_DP_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_DP_M->blockIO = ((void *) &ctrl_DP_B);
  (void) memset(((void *) &ctrl_DP_B), 0,
                sizeof(B_ctrl_DP_T));

  /* parameters */
  ctrl_DP_M->defaultParam = ((real_T *)&ctrl_DP_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_DP_X;
    ctrl_DP_M->contStates = (x);
    (void) memset((void *)&ctrl_DP_X, 0,
                  sizeof(X_ctrl_DP_T));
  }

  /* states (dwork) */
  ctrl_DP_M->dwork = ((void *) &ctrl_DP_DW);
  (void) memset((void *)&ctrl_DP_DW, 0,
                sizeof(DW_ctrl_DP_T));

  /* Initialize Sizes */
  ctrl_DP_M->Sizes.numContStates = (21);/* Number of continuous states */
  ctrl_DP_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_DP_M->Sizes.numY = (0);         /* Number of model outputs */
  ctrl_DP_M->Sizes.numU = (0);         /* Number of model inputs */
  ctrl_DP_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_DP_M->Sizes.numSampTimes = (2); /* Number of sample times */
  ctrl_DP_M->Sizes.numBlocks = (183);  /* Number of blocks */
  ctrl_DP_M->Sizes.numBlockIO = (50);  /* Number of block outputs */
  ctrl_DP_M->Sizes.numBlockPrms = (409);/* Sum of parameter "widths" */
  return ctrl_DP_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_DP
 * Model version : 1.207
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Wed Aug 23 17:03:41 2017
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_DP
#include "ni_modelframework_ex.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;

/*========================================================================*
 * Function: NIRT_GetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the source
 *      subindex : index value if vector
 *      type   : the source's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
double NIRT_GetValueByDataType(void* ptr, int32_t subindex, int32_t type,
  int32_t Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 33:
    return (( double *)ptr)[subindex];

   case 34:
    return (( double *)ptr)[subindex];

   case 35:
    return (( double *)ptr)[subindex];

   case 36:
    return (( double *)ptr)[subindex];

   case 37:
    return (( double *)ptr)[subindex];

   case 38:
    return (( double *)ptr)[subindex];

   case 39:
    return (( double *)ptr)[subindex];

   case 40:
    return (( double *)ptr)[subindex];

   case 41:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

/*========================================================================*
 * Function: NIRT_SetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the destination
 *      subindex : index value if vector
 *      value : value to set on the destination
 *      type   : the destination's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NIRT_SetValueByDataType(void* ptr, int32_t subindex, double value,
  int32_t type, int32_t Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 7, Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 17:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 31:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 8, Complex);

   case 32:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 33:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 34:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 35:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 36:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 37:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 38:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 39:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 40:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 41:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_DP_rtModel *S;
extern _SITexportglobals SITexportglobals;

/*========================================================================*
 * Function: SetExternalInputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalInputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  // ctrl_DP/Operator input/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Control Gains/K_p_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_p_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Control Gains/K_p_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_p_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Control Gains/K_p_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_p_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Control Gains/K_i_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_i_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Control Gains/K_i_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_i_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Control Gains/K_i_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_i_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Control Gains/K_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Control Gains/K_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Control Gains/K_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Guidance gains/w_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.w_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Guidance gains/w_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.w_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Guidance gains/w_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.w_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Guidance gains/zeta_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.zeta_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Guidance gains/zeta_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.zeta_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/Guidance gains/zeta_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.zeta_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/psi_ref [deg]
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.psi_refdeg, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/x_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.x_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Operator input/y_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.y_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/eta_QTM/x_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.x_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/eta_QTM/y_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.y_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/eta_QTM/psi_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.u80180deg, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 22;
}

int32_t NumOutputPorts(void)
{
  return 30;
}

double ni_extout[30];

/*========================================================================*
 * Function: SetExternalOutputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalOutputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  // ctrl_DP/Observer output /eta_hat output/x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator, 0, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /eta_hat output/y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator, 1, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum_e, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_hat output/u_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 0, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_hat output/v_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 1, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_hat output/r_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 2, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 0, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 1, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 2, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 0, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 1, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 2, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Output/alpha1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_infinf, 0, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Output/alpha2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_infinf, 1, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Output/alpha3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_infinf, 2, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Output/alpha4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_infinf, 3, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Output/alpha5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_infinf, 4, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Output/alpha6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_infinf, 5, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Output/u1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u, 0, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Output/u2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u, 1, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Output/u3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u, 2, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Output/u4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u, 3, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Output/u5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u, 4, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Output/u6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u, 5, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Control/eta_tilde/x_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum2, 0, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Control/eta_tilde/y_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum2, 1, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Control/eta_tilde/psi_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum2, 2, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Guidance/x_ref_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_h, 0, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Guidance/y_ref_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_h, 1, 18,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Guidance/psi_ref_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum_a, 0, 0, 0);
  } else {
    index += 1;
  }

  if (data != NULL) {
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
  }

  UNUSED_PARAMETER(count);
}

/*========================================================================*
 * Function: NI_InitExternalOutputs
 *
 * Abstract:
 *		Initialize model ports
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // ctrl_DP/Observer output /eta_hat output/x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator, 0, 18, 0);

  // ctrl_DP/Observer output /eta_hat output/y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator, 1, 18, 0);

  // ctrl_DP/Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum_e, 0, 0, 0);

  // ctrl_DP/Observer output /nu_hat output/u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 0, 18, 0);

  // ctrl_DP/Observer output /nu_hat output/v_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 1, 18, 0);

  // ctrl_DP/Observer output /nu_hat output/r_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 2, 18, 0);

  // ctrl_DP/Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 0, 18, 0);

  // ctrl_DP/Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 1, 18, 0);

  // ctrl_DP/Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 2, 18, 0);

  // ctrl_DP/Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 0, 18, 0);

  // ctrl_DP/Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 1, 18, 0);

  // ctrl_DP/Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 2, 18, 0);

  // ctrl_DP/Output/alpha1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_infinf, 0, 22, 0);

  // ctrl_DP/Output/alpha2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_infinf, 1, 22, 0);

  // ctrl_DP/Output/alpha3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_infinf, 2, 22, 0);

  // ctrl_DP/Output/alpha4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_infinf, 3, 22, 0);

  // ctrl_DP/Output/alpha5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_infinf, 4, 22, 0);

  // ctrl_DP/Output/alpha6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.alpha_infinf, 5, 22, 0);

  // ctrl_DP/Output/u1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u, 0, 22, 0);

  // ctrl_DP/Output/u2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u, 1, 22, 0);

  // ctrl_DP/Output/u3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u, 2, 22, 0);

  // ctrl_DP/Output/u4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u, 3, 22, 0);

  // ctrl_DP/Output/u5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u, 4, 22, 0);

  // ctrl_DP/Output/u6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.u, 5, 22, 0);

  // ctrl_DP/Control/eta_tilde/x_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum2, 0, 18, 0);

  // ctrl_DP/Control/eta_tilde/y_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum2, 1, 18, 0);

  // ctrl_DP/Control/eta_tilde/psi_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum2, 2, 18, 0);

  // ctrl_DP/Guidance/x_ref_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_h, 0, 18,
    0);

  // ctrl_DP/Guidance/y_ref_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_h, 1, 18,
    0);

  // ctrl_DP/Guidance/psi_ref_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum_a, 0, 0, 0);
  UNUSED_PARAMETER(count);
  return NI_OK;
}

/* Undefine parameter macros. The undef allows us to access the real declarations.
   In the Simulink(R) generated code, the parameters are redefined to be the read-side of rtParameter.*/
#define _NI_UNDEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"

/* All elements by default (including scalars) have 2 dimensions [1,1] */
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0,
    "ctrl_dp/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/Gain/Gain",
    offsetof(P_ctrl_DP_T, T_pinv), 28, 36, 2, 0, 0 },

  { 1, "ctrl_dp/Operator input/Observer Gains/Constant6/Value", offsetof
    (P_ctrl_DP_T, Constant6_Value), 41, 1, 2, 2, 0 },

  { 2, "ctrl_dp/Operator input/Observer Gains/Constant7/Value", offsetof
    (P_ctrl_DP_T, Constant7_Value), 41, 1, 2, 4, 0 },

  { 3, "ctrl_dp/Operator input/Observer Gains/Constant8/Value", offsetof
    (P_ctrl_DP_T, Constant8_Value), 41, 1, 2, 6, 0 },

  { 4, "ctrl_dp/eta_QTM/mm2m/Gain", offsetof(P_ctrl_DP_T, mm2m_Gain), 41, 1, 2,
    8, 0 },

  { 5, "ctrl_dp/eta_QTM/Gain1/Gain", offsetof(P_ctrl_DP_T, Gain1_Gain), 41, 1, 2,
    10, 0 },

  { 6, "ctrl_dp/eta_QTM/deg2rad/Gain", offsetof(P_ctrl_DP_T, deg2rad_Gain), 41,
    1, 2, 12, 0 },

  { 7, "ctrl_dp/eta_QTM/Saturation/UpperLimit", offsetof(P_ctrl_DP_T,
    Saturation_UpperSat), 41, 1, 2, 14, 0 },

  { 8, "ctrl_dp/eta_QTM/Saturation/LowerLimit", offsetof(P_ctrl_DP_T,
    Saturation_LowerSat), 41, 1, 2, 16, 0 },

  { 9, "ctrl_dp/eta_QTM/Gain6/Gain", offsetof(P_ctrl_DP_T, Gain6_Gain), 41, 1, 2,
    18, 0 },

  { 10, "ctrl_dp/eta_QTM/Constant1/Value", offsetof(P_ctrl_DP_T, Constant1_Value),
    41, 1, 2, 20, 0 },

  { 11,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_i), 41, 1, 2, 22, 0 },

  { 12,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_o), 41, 1, 2, 24, 0 },

  { 13, "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain), 41, 1, 2, 26, 0 },

  { 14,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value), 41, 1, 2, 28, 0 },

  { 15, "ctrl_dp/Nonlinear Passisve Observer/Integrator1/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator1_IC), 29, 3, 2, 30, 0 },

  { 16,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_e), 41, 1, 2, 32, 0 },

  { 17,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_g), 41, 1, 2, 34, 0 },

  { 18, "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_f), 41, 1, 2, 36, 0 },

  { 19,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value_p), 41, 1, 2, 38, 0 },

  { 20, "ctrl_dp/Nonlinear Passisve Observer/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator2_IC), 29, 3, 2, 40, 0 },

  { 21, "ctrl_dp/Control/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_l), 41, 1, 2, 42, 0 },

  { 22, "ctrl_dp/Control/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_i), 41, 1, 2, 44, 0 },

  { 23, "ctrl_dp/Control/[-inf inf] to [-pi pi]1/Gain/Gain", offsetof
    (P_ctrl_DP_T, Gain_Gain_p), 41, 1, 2, 46, 0 },

  { 24, "ctrl_dp/Control/[-inf inf] to [-pi pi]1/Constant/Value", offsetof
    (P_ctrl_DP_T, Constant_Value_i), 41, 1, 2, 48, 0 },

  { 25,
    "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_p), 41, 1, 2, 50, 0 },

  { 26,
    "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_a), 41, 1, 2, 52, 0 },

  { 27, "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_a), 41, 1, 2, 54, 0 },

  { 28,
    "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value_j), 41, 1, 2, 56, 0 },

  { 29, "ctrl_dp/Control/[-inf inf] to [-pi pi]/Saturation/UpperLimit", offsetof
    (P_ctrl_DP_T, Saturation_UpperSat_d), 41, 1, 2, 58, 0 },

  { 30, "ctrl_dp/Control/[-inf inf] to [-pi pi]/Saturation/LowerLimit", offsetof
    (P_ctrl_DP_T, Saturation_LowerSat_c), 41, 1, 2, 60, 0 },

  { 31, "ctrl_dp/Control/[-inf inf] to [-pi pi]/Gain/Gain", offsetof(P_ctrl_DP_T,
    Gain_Gain_ag), 41, 1, 2, 62, 0 },

  { 32, "ctrl_dp/Control/[-inf inf] to [-pi pi]/Constant/Value", offsetof
    (P_ctrl_DP_T, Constant_Value_l), 41, 1, 2, 64, 0 },

  { 33, "ctrl_dp/Control/Integrator/InitialCondition", offsetof(P_ctrl_DP_T,
    Integrator_IC), 41, 1, 2, 66, 0 },

  { 34, "ctrl_dp/Guidance/Reference model/Integrator3/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator3_IC), 41, 1, 2, 68, 0 },

  { 35, "ctrl_dp/Nonlinear Passisve Observer/M^-1/Gain", offsetof(P_ctrl_DP_T,
    M1_Gain), 19, 9, 2, 70, 0 },

  { 36,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/X0",
    offsetof(P_ctrl_DP_T, Memory4_X0), 30, 6, 2, 72, 0 },

  { 37, "ctrl_dp/Guidance/Reference model/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator2_IC_p), 41, 1, 2, 74, 0 },

  { 38, "ctrl_dp/Operator input/deg2rad/Gain", offsetof(P_ctrl_DP_T,
    deg2rad_Gain_l), 41, 1, 2, 76, 0 },

  { 39, "ctrl_dp/Operator input/Observer Gains/Constant/Value", offsetof
    (P_ctrl_DP_T, Constant_Value_c), 41, 1, 2, 78, 0 },

  { 40, "ctrl_dp/Operator input/Observer Gains/Constant1/Value", offsetof
    (P_ctrl_DP_T, Constant1_Value_p), 41, 1, 2, 80, 0 },

  { 41, "ctrl_dp/Operator input/Observer Gains/Constant2/Value", offsetof
    (P_ctrl_DP_T, Constant2_Value), 41, 1, 2, 82, 0 },

  { 42, "ctrl_dp/Operator input/Observer Gains/Constant3/Value", offsetof
    (P_ctrl_DP_T, Constant3_Value), 41, 1, 2, 84, 0 },

  { 43, "ctrl_dp/Operator input/Observer Gains/Constant4/Value", offsetof
    (P_ctrl_DP_T, Constant4_Value), 41, 1, 2, 86, 0 },

  { 44, "ctrl_dp/Operator input/Observer Gains/Constant5/Value", offsetof
    (P_ctrl_DP_T, Constant5_Value), 41, 1, 2, 88, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 45;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  12, 3,                               /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  3, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  3, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
  3, 3,                                /* Parameter at index 35 */
  6, 1,                                /* Parameter at index 36 */
  1, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
  1, 1,                                /* Parameter at index 39 */
  1, 1,                                /* Parameter at index 40 */
  1, 1,                                /* Parameter at index 41 */
  1, 1,                                /* Parameter at index 42 */
  1, 1,                                /* Parameter at index 43 */
  1, 1,                                /* Parameter at index 44 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_dp/Operator input/reset", 0, "", offsetof(B_ctrl_DP_T, reset) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_dp/Operator input/Control Gains/K_p_x", 0, "", offsetof(B_ctrl_DP_T,
    K_p_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_dp/Operator input/Control Gains/K_p_y", 0, "", offsetof(B_ctrl_DP_T,
    K_p_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "ctrl_dp/Operator input/Control Gains/K_p_psi", 0, "", offsetof
    (B_ctrl_DP_T, K_p_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "ctrl_dp/Operator input/Control Gains/K_i_psi", 0, "", offsetof
    (B_ctrl_DP_T, K_i_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "ctrl_dp/Operator input/Control Gains/K_i_x", 0, "", offsetof(B_ctrl_DP_T,
    K_i_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "ctrl_dp/Operator input/Control Gains/K_i_y", 0, "", offsetof(B_ctrl_DP_T,
    K_i_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "ctrl_dp/Operator input/Control Gains/K_d_psi", 0, "", offsetof
    (B_ctrl_DP_T, K_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "ctrl_dp/Operator input/Control Gains/K_d_x", 0, "", offsetof(B_ctrl_DP_T,
    K_d_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "ctrl_dp/Operator input/Control Gains/K_d_y", 0, "", offsetof(B_ctrl_DP_T,
    K_d_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_dp/Operator input/Guidance gains/w_d_x", 0, "", offsetof
    (B_ctrl_DP_T, w_d_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_dp/Operator input/Guidance gains/w_d_y", 0, "", offsetof
    (B_ctrl_DP_T, w_d_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_dp/Operator input/Guidance gains/w_d_psi", 0, "", offsetof
    (B_ctrl_DP_T, w_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_dp/Operator input/Guidance gains/zeta_psi", 0, "", offsetof
    (B_ctrl_DP_T, zeta_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "ctrl_dp/Operator input/Guidance gains/zeta_x", 0, "", offsetof
    (B_ctrl_DP_T, zeta_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "ctrl_dp/Operator input/Guidance gains/zeta_y", 0, "", offsetof
    (B_ctrl_DP_T, zeta_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "ctrl_dp/Operator input/psi_ref [deg]", 0, "", offsetof(B_ctrl_DP_T,
    psi_refdeg) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "ctrl_dp/Operator input/x_ref", 0, "", offsetof(B_ctrl_DP_T, x_ref) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "ctrl_dp/Operator input/y_ref", 0, "", offsetof(B_ctrl_DP_T, y_ref) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 19, "ctrl_dp/eta_QTM/x_m", 0, "", offsetof(B_ctrl_DP_T, x_m) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "ctrl_dp/eta_QTM/mm2m", 0, "", offsetof(B_ctrl_DP_T, mm2m) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "ctrl_dp/eta_QTM/y_m", 0, "", offsetof(B_ctrl_DP_T, y_m) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "ctrl_dp/eta_QTM/Gain1", 0, "", offsetof(B_ctrl_DP_T, Gain1) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 23, "ctrl_dp/eta_QTM/psi_m", 0, "[-180,180] [deg]", offsetof(B_ctrl_DP_T,
    u80180deg) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 24, "ctrl_dp/eta_QTM/Sum", 0, "", offsetof(B_ctrl_DP_T, Sum) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 25, "ctrl_dp/Nonlinear Passisve Observer/Integrator/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 26, "ctrl_dp/Nonlinear Passisve Observer/Integrator/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 27, "ctrl_dp/Nonlinear Passisve Observer/Integrator/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 28, "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Sum", 0, "",
    offsetof(B_ctrl_DP_T, Sum_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 29, "ctrl_dp/Nonlinear Passisve Observer/Integrator1/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 30, "ctrl_dp/Nonlinear Passisve Observer/Integrator1/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 31, "ctrl_dp/Nonlinear Passisve Observer/Integrator1/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 32, "ctrl_dp/Nonlinear Passisve Observer/Integrator2/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator2) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 33, "ctrl_dp/Nonlinear Passisve Observer/Integrator2/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator2) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 34, "ctrl_dp/Nonlinear Passisve Observer/Integrator2/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator2) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 35, "ctrl_dp/Guidance/Reference model/Integrator1/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator1_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 36, "ctrl_dp/Guidance/Reference model/Integrator1/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator1_h) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 37, "ctrl_dp/Guidance/Reference model/Integrator1/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator1_h) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0,
    0 },

  { 38, "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Sum", 0, "",
    offsetof(B_ctrl_DP_T, Sum_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 39, "ctrl_dp/Control/Sum2/(1, 1)", 0, "", offsetof(B_ctrl_DP_T, Sum2) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 40, "ctrl_dp/Control/Sum2/(1, 2)", 0, "", offsetof(B_ctrl_DP_T, Sum2) + (1*
    sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 41, "ctrl_dp/Control/Sum2/(1, 3)", 0, "", offsetof(B_ctrl_DP_T, Sum2) + (2*
    sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 42, "ctrl_dp/Guidance/Reference model/Integrator3/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator3) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 43, "ctrl_dp/Guidance/Reference model/Integrator3/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator3) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 44, "ctrl_dp/Guidance/Reference model/Integrator3/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator3) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 45, "ctrl_dp/Nonlinear Passisve Observer/M^-1/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, M1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 46, "ctrl_dp/Nonlinear Passisve Observer/M^-1/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, M1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 47, "ctrl_dp/Nonlinear Passisve Observer/M^-1/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, M1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 48,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 1)",
    0, "", offsetof(B_ctrl_DP_T, Memory4) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 49,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 2)",
    0, "", offsetof(B_ctrl_DP_T, Memory4) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 50,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 3)",
    0, "", offsetof(B_ctrl_DP_T, Memory4) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 51,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 4)",
    0, "", offsetof(B_ctrl_DP_T, Memory4) + (3*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 52,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 5)",
    0, "", offsetof(B_ctrl_DP_T, Memory4) + (4*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 53,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 6)",
    0, "", offsetof(B_ctrl_DP_T, Memory4) + (5*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 54, "ctrl_dp/Guidance/Reference model/Matrix Multiply/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 55, "ctrl_dp/Guidance/Reference model/Matrix Multiply/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 56, "ctrl_dp/Guidance/Reference model/Matrix Multiply/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 57, "ctrl_dp/Guidance/Reference model/Sum5", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, Sum5) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 58, "ctrl_dp/Guidance/Reference model/Sum5", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, Sum5) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 59, "ctrl_dp/Guidance/Reference model/Sum5", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, Sum5) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 60, "ctrl_dp/Nonlinear Passisve Observer/Matrix Multiply1/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 61, "ctrl_dp/Nonlinear Passisve Observer/Matrix Multiply1/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 62, "ctrl_dp/Nonlinear Passisve Observer/Matrix Multiply1/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18,
    1, 2, 0, 0 },

  { 63, "ctrl_dp/Nonlinear Passisve Observer/Sum1/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 64, "ctrl_dp/Nonlinear Passisve Observer/Sum1/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, Sum1) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 65, "ctrl_dp/Nonlinear Passisve Observer/Sum1/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, Sum1) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 66,
    "ctrl_dp/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 1)", offsetof(B_ctrl_DP_T, u) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 67,
    "ctrl_dp/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 2)", offsetof(B_ctrl_DP_T, u) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 68,
    "ctrl_dp/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 3)", offsetof(B_ctrl_DP_T, u) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 69,
    "ctrl_dp/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 4)", offsetof(B_ctrl_DP_T, u) + (3*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 70,
    "ctrl_dp/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 5)", offsetof(B_ctrl_DP_T, u) + (4*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 71,
    "ctrl_dp/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 6)", offsetof(B_ctrl_DP_T, u) + (5*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 72,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 1)", offsetof(B_ctrl_DP_T, alpha_infinf) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 73,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 2)", offsetof(B_ctrl_DP_T, alpha_infinf) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 74,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 3)", offsetof(B_ctrl_DP_T, alpha_infinf) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 75,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 4)", offsetof(B_ctrl_DP_T, alpha_infinf) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 76,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 5)", offsetof(B_ctrl_DP_T, alpha_infinf) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 77,
    "ctrl_dp/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 6)", offsetof(B_ctrl_DP_T, alpha_infinf) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 78, "ctrl_dp/Operator input/Observer Gains/MATLAB Function2", 0, "(1, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2.y) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 79, "ctrl_dp/Operator input/Observer Gains/MATLAB Function2", 0, "(2, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2.y) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 80, "ctrl_dp/Operator input/Observer Gains/MATLAB Function2", 0, "(3, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2.y) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 81, "ctrl_dp/Operator input/Observer Gains/MATLAB Function2", 0, "(1, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2.y) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 82, "ctrl_dp/Operator input/Observer Gains/MATLAB Function2", 0, "(2, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2.y) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 83, "ctrl_dp/Operator input/Observer Gains/MATLAB Function2", 0, "(3, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2.y) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 84, "ctrl_dp/Operator input/Observer Gains/MATLAB Function2", 0, "(1, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2.y) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 85, "ctrl_dp/Operator input/Observer Gains/MATLAB Function2", 0, "(2, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2.y) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 86, "ctrl_dp/Operator input/Observer Gains/MATLAB Function2", 0, "(3, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2.y) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 87, "ctrl_dp/Operator input/Observer Gains/MATLAB Function1", 0, "(1, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 88, "ctrl_dp/Operator input/Observer Gains/MATLAB Function1", 0, "(2, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 89, "ctrl_dp/Operator input/Observer Gains/MATLAB Function1", 0, "(3, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 90, "ctrl_dp/Operator input/Observer Gains/MATLAB Function1", 0, "(1, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 91, "ctrl_dp/Operator input/Observer Gains/MATLAB Function1", 0, "(2, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 92, "ctrl_dp/Operator input/Observer Gains/MATLAB Function1", 0, "(3, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 93, "ctrl_dp/Operator input/Observer Gains/MATLAB Function1", 0, "(1, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 94, "ctrl_dp/Operator input/Observer Gains/MATLAB Function1", 0, "(2, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 95, "ctrl_dp/Operator input/Observer Gains/MATLAB Function1", 0, "(3, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 96, "ctrl_dp/Operator input/Observer Gains/MATLAB Function", 0, "(1, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_p.y) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 97, "ctrl_dp/Operator input/Observer Gains/MATLAB Function", 0, "(2, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_p.y) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 98, "ctrl_dp/Operator input/Observer Gains/MATLAB Function", 0, "(3, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_p.y) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 99, "ctrl_dp/Operator input/Observer Gains/MATLAB Function", 0, "(1, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_p.y) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 100, "ctrl_dp/Operator input/Observer Gains/MATLAB Function", 0, "(2, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_p.y) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 101, "ctrl_dp/Operator input/Observer Gains/MATLAB Function", 0, "(3, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_p.y) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 102, "ctrl_dp/Operator input/Observer Gains/MATLAB Function", 0, "(1, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_p.y) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 103, "ctrl_dp/Operator input/Observer Gains/MATLAB Function", 0, "(2, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_p.y) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 104, "ctrl_dp/Operator input/Observer Gains/MATLAB Function", 0, "(3, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_p.y) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 105, "ctrl_dp/Operator input/Guidance gains/MATLAB Function1", 0, "(1, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 106, "ctrl_dp/Operator input/Guidance gains/MATLAB Function1", 0, "(2, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 107, "ctrl_dp/Operator input/Guidance gains/MATLAB Function1", 0, "(3, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 108, "ctrl_dp/Operator input/Guidance gains/MATLAB Function1", 0, "(1, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 109, "ctrl_dp/Operator input/Guidance gains/MATLAB Function1", 0, "(2, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 110, "ctrl_dp/Operator input/Guidance gains/MATLAB Function1", 0, "(3, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 111, "ctrl_dp/Operator input/Guidance gains/MATLAB Function1", 0, "(1, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 112, "ctrl_dp/Operator input/Guidance gains/MATLAB Function1", 0, "(2, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 113, "ctrl_dp/Operator input/Guidance gains/MATLAB Function1", 0, "(3, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 114, "ctrl_dp/Operator input/Guidance gains/MATLAB Function", 0, "(1, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_d.y) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 115, "ctrl_dp/Operator input/Guidance gains/MATLAB Function", 0, "(2, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_d.y) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 116, "ctrl_dp/Operator input/Guidance gains/MATLAB Function", 0, "(3, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_d.y) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 117, "ctrl_dp/Operator input/Guidance gains/MATLAB Function", 0, "(1, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_d.y) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 118, "ctrl_dp/Operator input/Guidance gains/MATLAB Function", 0, "(2, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_d.y) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 119, "ctrl_dp/Operator input/Guidance gains/MATLAB Function", 0, "(3, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_d.y) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 120, "ctrl_dp/Operator input/Guidance gains/MATLAB Function", 0, "(1, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_d.y) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 121, "ctrl_dp/Operator input/Guidance gains/MATLAB Function", 0, "(2, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_d.y) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 122, "ctrl_dp/Operator input/Guidance gains/MATLAB Function", 0, "(3, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction_d.y) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 123, "ctrl_dp/Operator input/Control Gains/MATLAB Function2", 0, "(1, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2_c.y) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 124, "ctrl_dp/Operator input/Control Gains/MATLAB Function2", 0, "(2, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2_c.y) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 125, "ctrl_dp/Operator input/Control Gains/MATLAB Function2", 0, "(3, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2_c.y) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 126, "ctrl_dp/Operator input/Control Gains/MATLAB Function2", 0, "(1, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2_c.y) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 127, "ctrl_dp/Operator input/Control Gains/MATLAB Function2", 0, "(2, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2_c.y) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 128, "ctrl_dp/Operator input/Control Gains/MATLAB Function2", 0, "(3, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2_c.y) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 129, "ctrl_dp/Operator input/Control Gains/MATLAB Function2", 0, "(1, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2_c.y) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 130, "ctrl_dp/Operator input/Control Gains/MATLAB Function2", 0, "(2, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2_c.y) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 131, "ctrl_dp/Operator input/Control Gains/MATLAB Function2", 0, "(3, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction2_c.y) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 132, "ctrl_dp/Operator input/Control Gains/MATLAB Function1", 0, "(1, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1.y) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 133, "ctrl_dp/Operator input/Control Gains/MATLAB Function1", 0, "(2, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1.y) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 134, "ctrl_dp/Operator input/Control Gains/MATLAB Function1", 0, "(3, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1.y) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 135, "ctrl_dp/Operator input/Control Gains/MATLAB Function1", 0, "(1, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1.y) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 136, "ctrl_dp/Operator input/Control Gains/MATLAB Function1", 0, "(2, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1.y) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 137, "ctrl_dp/Operator input/Control Gains/MATLAB Function1", 0, "(3, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1.y) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 138, "ctrl_dp/Operator input/Control Gains/MATLAB Function1", 0, "(1, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1.y) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 139, "ctrl_dp/Operator input/Control Gains/MATLAB Function1", 0, "(2, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1.y) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 140, "ctrl_dp/Operator input/Control Gains/MATLAB Function1", 0, "(3, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction1.y) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 141, "ctrl_dp/Operator input/Control Gains/MATLAB Function", 0, "(1, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction.y) + (0*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 142, "ctrl_dp/Operator input/Control Gains/MATLAB Function", 0, "(2, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction.y) + (1*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 143, "ctrl_dp/Operator input/Control Gains/MATLAB Function", 0, "(3, 1)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction.y) + (2*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 144, "ctrl_dp/Operator input/Control Gains/MATLAB Function", 0, "(1, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction.y) + (3*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 145, "ctrl_dp/Operator input/Control Gains/MATLAB Function", 0, "(2, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction.y) + (4*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 146, "ctrl_dp/Operator input/Control Gains/MATLAB Function", 0, "(3, 2)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction.y) + (5*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 147, "ctrl_dp/Operator input/Control Gains/MATLAB Function", 0, "(1, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction.y) + (6*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 148, "ctrl_dp/Operator input/Control Gains/MATLAB Function", 0, "(2, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction.y) + (7*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { 149, "ctrl_dp/Operator input/Control Gains/MATLAB Function", 0, "(3, 3)",
    offsetof(B_ctrl_DP_T, sf_MATLABFunction.y) + (8*sizeof(real_T)), BLOCKIO_SIG,
    19, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 150;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 52;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Operator input/reset", 0, EXT_IN, 1, 1, 1 },

  { 2, "Operator input/Control Gains/K_p_x", 0, EXT_IN, 1, 1, 1 },

  { 3, "Operator input/Control Gains/K_p_y", 0, EXT_IN, 1, 1, 1 },

  { 4, "Operator input/Control Gains/K_p_psi", 0, EXT_IN, 1, 1, 1 },

  { 5, "Operator input/Control Gains/K_i_psi", 0, EXT_IN, 1, 1, 1 },

  { 6, "Operator input/Control Gains/K_i_x", 0, EXT_IN, 1, 1, 1 },

  { 7, "Operator input/Control Gains/K_i_y", 0, EXT_IN, 1, 1, 1 },

  { 8, "Operator input/Control Gains/K_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 9, "Operator input/Control Gains/K_d_x", 0, EXT_IN, 1, 1, 1 },

  { 10, "Operator input/Control Gains/K_d_y", 0, EXT_IN, 1, 1, 1 },

  { 11, "Operator input/Guidance gains/w_d_x", 0, EXT_IN, 1, 1, 1 },

  { 12, "Operator input/Guidance gains/w_d_y", 0, EXT_IN, 1, 1, 1 },

  { 13, "Operator input/Guidance gains/w_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 14, "Operator input/Guidance gains/zeta_psi", 0, EXT_IN, 1, 1, 1 },

  { 15, "Operator input/Guidance gains/zeta_x", 0, EXT_IN, 1, 1, 1 },

  { 16, "Operator input/Guidance gains/zeta_y", 0, EXT_IN, 1, 1, 1 },

  { 17, "Operator input/psi_ref [deg]", 0, EXT_IN, 1, 1, 1 },

  { 18, "Operator input/x_ref", 0, EXT_IN, 1, 1, 1 },

  { 19, "Operator input/y_ref", 0, EXT_IN, 1, 1, 1 },

  { 20, "eta_QTM/x_m", 0, EXT_IN, 1, 1, 1 },

  { 21, "eta_QTM/y_m", 0, EXT_IN, 1, 1, 1 },

  { 22, "eta_QTM/psi_m", 0, EXT_IN, 1, 1, 1 },

  { 1, "Observer output /eta_hat output/x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 2, "Observer output /eta_hat output/y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 3, "Observer output /eta_hat output/psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 4, "Observer output /nu_hat output/u_hat", 0, EXT_OUT, 1, 1, 1 },

  { 5, "Observer output /nu_hat output/v_hat", 0, EXT_OUT, 1, 1, 1 },

  { 6, "Observer output /nu_hat output/r_hat", 0, EXT_OUT, 1, 1, 1 },

  { 7, "Observer output /nu_dot_hat output/u_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 8, "Observer output /nu_dot_hat output/v_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 9, "Observer output /nu_dot_hat output/r_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 10, "Observer output /b_hat output/b_x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 11, "Observer output /b_hat output/b_y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 12, "Observer output /b_hat output/b_psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 13, "Output/alpha1", 0, EXT_OUT, 1, 1, 1 },

  { 14, "Output/alpha2", 0, EXT_OUT, 1, 1, 1 },

  { 15, "Output/alpha3", 0, EXT_OUT, 1, 1, 1 },

  { 16, "Output/alpha4", 0, EXT_OUT, 1, 1, 1 },

  { 17, "Output/alpha5", 0, EXT_OUT, 1, 1, 1 },

  { 18, "Output/alpha6", 0, EXT_OUT, 1, 1, 1 },

  { 19, "Output/u1", 0, EXT_OUT, 1, 1, 1 },

  { 20, "Output/u2", 0, EXT_OUT, 1, 1, 1 },

  { 21, "Output/u3", 0, EXT_OUT, 1, 1, 1 },

  { 22, "Output/u4", 0, EXT_OUT, 1, 1, 1 },

  { 23, "Output/u5", 0, EXT_OUT, 1, 1, 1 },

  { 24, "Output/u6", 0, EXT_OUT, 1, 1, 1 },

  { 25, "Control/eta_tilde/x_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 26, "Control/eta_tilde/y_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 27, "Control/eta_tilde/psi_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 28, "Guidance/x_ref_out", 0, EXT_OUT, 1, 1, 1 },

  { 29, "Guidance/y_ref_out", 0, EXT_OUT, 1, 1, 1 },

  { 30, "Guidance/psi_ref_out", 0, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.01, 0 }
};

int32_t NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static const char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_DP";
static const char* NI_CompiledModelVersion = "1.207";
static const char* NI_CompiledModelDateTime = "Wed Aug 23 17:03:41 2017";
static const char* NI_builder DataSection(".NIVS.builder") =
  "NI Model Framework 2017.0.0.143 (2017) for Simulink Coder 8.11 (R2016b)";
static const char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2017.0.0.143";

/*========================================================================*
 * Function: NIRT_GetBuildInfo
 *
 * Abstract:
 *	Get the DLL versioning etc information.
 *
 * Output Parameters:
 *	detail	: String containing model build information.
 *	len		: the build info string length. If a value of "-1" is specified, the minimum buffer size of "detail" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetBuildInfo(char* detail, int32_t* len)
{
  int32_t msgLength = 0;
  char *msgBuffer = NULL;

  /* Message */
  const char msg[] =
    "%s\nModel Name: %s\nModel Version: %s\nVeriStand Model Framework Version: %s\nCompiled On: %s";

  /* There are no console properties to set for VxWorks, because the console is simply serial output data.
     Just do printf for VxWorks and ignore all console properties. */
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  /* Print to screen */
  printf("\n*******************************************************************************\n");
  msgLength = printf(msg, NI_builder, NI_CompiledModelName,
                     NI_CompiledModelVersion, NI_BuilderVersion,
                     NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len == -1) {
    /* Return the required minimum buffer size */
    *len = msgLength;
  } else {
    /* allocate the buffer */
    msgBuffer = (char*)calloc(msgLength + 1, sizeof(char));
    sprintf (msgBuffer, msg, NI_builder, NI_CompiledModelName,
             NI_CompiledModelVersion, NI_BuilderVersion,
             NI_CompiledModelDateTime);
    if (*len >= msgLength) {
      *len = msgLength + 1;
    }

    /* Copy into external buffer */
    strncpy(detail, msgBuffer, *len);

    /* Release memory */
    free(msgBuffer);
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSignalSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	index		: index of the signal (in/out)
 *	ID			: ID of signal to be looked up (in), ID of signal at index (out)
 *	ID_len		: length of input ID(in), length of ID (out)
 *	bnlen		: length of buffer blkname (in), length of output blkname (out)
 *	snlen		: length of buffer signame (in), length of output signame (out)
 *
 * Output Parameters:
 *	blkname		: Name of the source block for the signal
 *	portnum		: port number of the block that is the source of the signal (0 indexed)
 *	signame		: Name of the signal
 *	datatype	: same as with parameters. Currently assuming all data to be double.
 *	dims		: The port's dimension of length 'numdims'.
 *	numdims		: the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error(if sigidx == -1, number of signals)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSignalSpec(int32_t* sidx, char* ID, int32_t* ID_len,
  char* blkname, int32_t *bnlen,
  int32_t *portnum, char* signame, int32_t *snlen, int32_t *dattype, int32_t*
  dims, int32_t* numdim)
{
  int32_t sigidx = *sidx;
  int32_t i = 0;
  char *addr = NULL;
  char *IDblk = 0;
  int32_t IDport = 0;
  if (sigidx < 0) {
    /* check if ID has been specified. */
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0)) {
      /* parse ID into blkname and port */
      addr = strrchr(ID, ':');
      if (addr == NULL) {
        return NI_SigListSize;
      }

      /* Calculate the char offset into the string after the port */
      i = addr - ID;

      /* malformed ID */
      if (i<=0) {
        return NI_SigListSize;
      }

      IDblk = ID;
      IDport = atoi(ID+i+1);

      /* lookup the table for matching ID */
      for (i=0; i<NI_SigListSize; i++) {
        /* 11 to accomodate ':','/', port number and null character */
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname) + 11, sizeof(char));
        if (strlen(NI_SigList[i].signalname)>0) {
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        } else {
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        }

        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1)) {
          break;
        }

        free(tempID);
      }

      if (i < NI_SigListSize) {
        sigidx = *sidx = i;
      } else {
        return NI_SigListSize;
      }
    } else {
      // no index or ID specified.
      return NI_SigListSize;
    }
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID != NULL) {
      // no need for return string to be null terminated!
      /* 11 to accomodate ':','/', port number and null character */
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0) {
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      } else {
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      }

      if ((int32_t)strlen(tempID)<*ID_len) {
        *ID_len = strlen(tempID);
      }

      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].blockname)<*bnlen) {
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      }

      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].signalname)<*snlen) {
        *snlen = strlen(NI_SigList[sigidx].signalname);
      }

      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum != NULL) {
      *portnum = NI_SigList[sigidx].portno;
    }

    if (dattype != NULL) {
      *dattype = NI_SigList[sigidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_SigList[sigidx].numofdims;
      } else if (dims != NULL) {
        for (i=0;i < *numdim; i++) {
          dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
        }
      }
    }

    return NI_OK;
  }

  return NI_SigListSize;
}

/*========================================================================*
 * Function: NIRT_GetParameterIndices
 *
 * Abstract:
 *	Returns an array of indices to tunable parameters
 *
 * Output Parameters:
 *	indices	: buffer to store the parameter indices of length "len"
 *	len		: returns the number of indices. If a value of "-1" is specified, the minimum buffer size of "indices" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterIndices(int32_t* indices, int32_t* len)
{
  int32_t i;
  if ((len == NULL) || (indices == NULL)) {
    return NI_ERROR;
  }

  if (*len == -1) {
    *len = NI_ParamListSize;
  } else {
    for (i=0; (i < NI_ParamListSize) && (i < *len); i++) {
      indices[i] = NI_ParamList[i].idx;
    }

    *len = i;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetParameterSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	paramidx	: index of the parameter(in/out). If a value of "-1" is specified, the parameter's ID is used instead
 *	ID			: ID of parameter to be looked up (in), ID of parameter at index (out)
 *	ID_len		: length of input ID (in), length of ID (out)
 *	pnlen		: length of buffer paramname(in), length of the returned paramname (out)
 *	numdim		: length of buffer dimension(in), length of output dimension (out). If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value
 *
 * Output Parameters:
 *	paramname	: Name of the parameter
 *	datatype	: datatype of the parameter (currently assuming 0: double, .. )
 *	dims		: array of dimensions with length 'numdim'
 *
 * Returns:
 *	NI_OK if no error (if paramidx == -1, number of tunable parameters)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterSpec(int32_t* pidx, char* ID, int32_t*
  ID_len, char* paramname, int32_t *pnlen,
  int32_t *dattype, int32_t* dims, int32_t* numdim)
{
  int32_t i = 0;
  int32_t paramidx = *pidx;
  if (paramidx < 0) {
    // check if ID has been specified.
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0) ) {
      // lookup the table for matching ID
      for (i=0; i < NI_ParamListSize; i++) {
        if (strcmp(ID,NI_ParamList[i].paramname) == 0) {
          /* found matching string */
          break;
        }
      }

      if (i < NI_ParamListSize) {
        /* note the index into the rtParamAttribs */
        paramidx = *pidx = i;
      } else {
        return NI_ParamListSize;
      }
    } else {
      // no index or ID specified.
      return NI_ParamListSize;
    }
  }

  if ((paramidx >= 0) && (paramidx<NI_ParamListSize)) {
    if (ID != NULL) {
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *ID_len) {
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname != NULL) {
      /* no need for return string to be null terminated! */
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *pnlen) {
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype != NULL) {
      *dattype = NI_ParamList[paramidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_ParamList[paramidx].numofdims;
      } else if (dims != NULL) {
        for (i = 0; i < *numdim; i++) {
          dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset + i];
        }
      }
    }

    return NI_OK;
  }

  return NI_ParamListSize;
}

/*========================================================================*
 * Function: NIRT_GetExtIOSpec
 *
 * Abstract:
 *	Returns the model's inport or outport specification
 *
 * Input Parameters:
 *	index	: index of the task
 *
 * Output Parameters:
 *	idx		: idx of the IO.
 *	name	: Name of the IO block
 *	tid		: task id
 *	type	: EXT_IN or EXT_OUT
 *	dims	: The port's dimension of length 'numdims'.
 *	numdims : the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns
 *	NI_OK if no error. (if index == -1, return number of tasks in the model)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetExtIOSpec(int32_t index, int32_t *idx, char* name,
  int32_t* tid, int32_t *type, int32_t *dims, int32_t* numdims)
{
  if (index == -1) {
    return NI_ExtListSize;
  }

  if (idx != NULL) {
    *idx = NI_ExtList[index].idx;
  }

  if (name != NULL) {
    int32_t sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid != NULL) {
    *tid = NI_ExtList[index].TID;
  }

  if (type != NULL) {
    *type = NI_ExtList[index].type;
  }

  if (numdims != NULL) {
    if (*numdims == -1) {
      *numdims = 2;
    } else if (numdims != NULL) {
      /* Return port dimensions */
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    }
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NI_ProbeOneSignal
 *
 * Abstract:
 *		Helper function to probe one signal. baseaddr must NOT be VIRTUAL_SIG
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: Returns the last index value probed in a vector signal
 *========================================================================*/
static int32_t NI_ProbeOneSignal(int32_t idx, double *value, int32_t len,
  int32_t *count, int32_t vOffset, int32_t vLength)
{
  if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
    SetSITErrorMessage("NI_ProbeOneSignal: Received request to probe a virtual signal, but was expecting a ground source. Ignoring virtual signal probe. Report this behavior to National Instruments.",
                       0);
    return 0;
  } else {
    char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ? S->blockIO :
                        S->inputs) + (uintptr_t)NI_SigList[idx].addr;
    int32_t subindex = (vLength == -1) ? 0 : vOffset;
    int32_t sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength +
      vOffset);
    while ((subindex < sublength) && (*count < len))
      value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++,
        NI_SigList[idx].datatype, NI_SigList[idx].IsComplex);
    return *count;
  }
}

/*========================================================================*
 * Function: NIRT_ProbeSignals
 *
 * Abstract:
 *	returns the latest signal values.
 *
 * Input Parameters:
 *	sigindices	: list of signal indices to be probed.
 *	numsigs		: length of sigindices array.
 *
 *		NOTE: (Implementation detail) the sigindices array that is passed in is delimited by a value of -1.
 *		Thus the # of valid indices in the sigindices table is min(numsigs, index of value -1) - 1.
 *		Reason for subtracting 1, the first index in the array is used for bookkeeping and should be copied
 *		into the 0th index in the signal values buffer.
 *		Also, the 1st index in the signal values buffer should contain the current timestamp. Hence valid
 *		signal data should be filled in starting from index 2. Any non-scalar signals should be added to the
 *		buffer in row-order.
 *
 * Input/Output Parameters
 *	num			: (in) length of sigvalues buffer (out) number of values returned in the buffer
 *
 * Output Parameters:
 *	value		: array of signal values
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_ProbeSignals(int32_t* sigindices, int32_t numsigs,
  double* value, int32_t* len)
{
  int32_t i = 0;
  int32_t idx = 0;
  int32_t count = 0;
  if (!SITexportglobals.inCriticalSection) {
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  }

  /* Get the index to the first signal */
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  /* Get the second and other signals */
  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0) {
      break;
    }

    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        int32_t vidx = NI_VirtualBlockSources[NI_SigList[idx].addr];
        NI_ProbeOneSignal(vidx, value, *len, &count, 0, -1);
      } else {
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
      }
    }
  }

  *len = count;
  return count;
}

int32_t NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_DP_P, sizeof(P_ctrl_DP_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_DP_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_DP_T));
  return NI_OK;
}

static int32_t NI_SetParamTxStatus = NI_OK;

/*========================================================================*
 * Function: NIRT_SetParameter
 *
 * Abstract:
 *	Set parameter value. Called either in scheduler loop or a background loop.
 *
 * Input Parameters:
 *	index	: index of the parameter (as specified in Parameter Information)
 *	subindex: index in the flattened array, if parameter is n-D array
 *	val		: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetParameter(int32_t index, int32_t subindex, double
  value)
{
  char* ptr = NULL;

  /* Check bounds */
  if (index >= NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* Commit parameter values */
  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_DP_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0) {
        /* No values to commit */
        return NI_OK;
      } else {
        SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                           1);
        WriteSideDirtyFlag = 0;
        return NI_ERROR;
      }
    }

    /* If an error occurred and we have values to commit, then save to the write side and return error */
    if (NI_SetParamTxStatus == NI_ERROR) {
      // fail the transaction.
      // copy old list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1) {
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_ctrl_DP_T));
      }

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /* If we have values to commit, then save to the write-side */
    if (WriteSideDirtyFlag == 1) {
      S->defaultParam = (double *)&rtParameter[1-READSIDE];
      WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
      READSIDE = 1 - READSIDE;
      SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
      ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

      // Copy back the newly set parameters to the writeside.
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_DP_T));
      WriteSideDirtyFlag = 0;
    }

    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex >= NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_ctrl_DP_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, value, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_SetVectorParameter
 *
 * Abstract:
 *	Sets the value to a parameter array.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	paramvalues	: array of values to set
 *	paramlength	: Length of parameter values.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetVectorParameter( uint32_t index, const double
  * paramvalues, uint32_t paramlength)
{
  uint32_t i = 0;
  int32_t retval = NI_OK;
  char* ptr = NULL;

  /* verify that index is within bounds*/
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength != (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* If we have pending modified parameters, then copy to write-side */
  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_ctrl_DP_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char*)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  while (i < paramlength) {
    /* Convert the incoming double datatype to the parameter's internal datatype and update value */
    retval = retval & NIRT_SetValueByDataType(ptr, i, paramvalues[i],
      NI_ParamList[index].datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

/*========================================================================*
 * Function: NIRT_SetScalarParameterInline
 *
 * Abstract:
 *	Sets the value to a parameter immediately without the need of a commit request.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	subindex	: offset of the element within the parameter
 *	paramvalue	: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetScalarParameterInline( uint32_t index, uint32_t
  subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex >= (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, paramvalue, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_GetParameter
 *
 * Abstract:
 *	Get the current value of a parameter.
 *
 * Input Parameters:
 *	index	: index of the parameter
 *	subindex: element index into the flattened array if an array
 *
 * Output Parameters:
 *	val		: value of the parameter
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameter(int32_t index, int32_t subindex, double
  *value)
{
  char* ptr = NULL;

  /* Check index boundaries */
  if (index >= NI_ParamListSize || index < 0 || (subindex>=NI_ParamList[index].
       width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;

  /* Convert the parameter's internal datatype to double and return its value */
  *value = NIRT_GetValueByDataType(ptr, subindex, NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetVectorParameter
 *
 * Abstract:
 *	Get the current value of a vector parameter.
 *
 * Input Parameters:
 *	index: index of the parameter
 *	paramLength: length of the parameter
 *
 * Output Parameters:
 *	paramValues: an array of the parameter's value
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetVectorParameter(uint32_t index, double* paramvalues,
  uint32_t paramlength)
{
  char* ptr = NULL;
  uint32_t i = 0;
  if (index >= (uint32_t)NI_ParamListSize || index < 0 || (paramlength !=
       (uint32_t)NI_ParamList[index].width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  while (i<paramlength) {
    /* Convert the parameter's internal datatype to double and return its value */
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSimState(int32_t* numContStates, char
  * contStatesNames, double* contStates, int32_t* numDiscStates, char
  * discStatesNames, double* discStates, int32_t* numClockTicks, char
  * clockTicksNames, int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if ((numContStates != NULL) && (numDiscStates != NULL) && (numClockTicks !=
       NULL)) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 21;
      *numDiscStates = 474;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_f),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_f");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_f),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_f");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_f),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_f");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_c),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_c),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_c),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_c");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_refdeg_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_refdeg_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_ref_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_ref_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_dot_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_dot_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_dot_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_x_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_y_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_psi_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_psi_hat_DWORK1");
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_DW.Memory4_PreviousInput, count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_DW.Memory4_PreviousInput");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_tilde_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_tilde_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_tilde_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_ref_out_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_ref_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_ref_out_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_ref_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_ref_out_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_ref_out_DWORK1");
    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_refdeg_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_refdeg_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_ref_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_ref_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_ref_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_ref_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_m_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_m_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_m_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_m_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_m_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_hat_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_hat_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_hat_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_hat_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_hat_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_dot_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_dot_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_dot_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_dot_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_dot_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_dot_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_x_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_x_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_y_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_y_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_psi_hat_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_psi_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha1_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha2_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha3_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha3_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha4_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha4_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha5_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha5_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha6_DWORK2, count,
        21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha6_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u1_DWORK2, count, 21,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u2_DWORK2, count, 21,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u3_DWORK2, count, 21,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u3_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u4_DWORK2, count, 21,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u4_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u5_DWORK2, count, 21,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u5_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u6_DWORK2, count, 21,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u6_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_tilde_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_tilde_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_tilde_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_tilde_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_tilde_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_tilde_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_ref_out_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_ref_out_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_ref_out_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_ref_out_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_ref_out_DWORK2,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_ref_out_DWORK2");
    }
  }

  if ((clockTicks != NULL) && (clockTicksNames != NULL)) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_SetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetSimState(double* contStates, double* discStates,
  int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if (contStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_f), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_f), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_f), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_c), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_c), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_c), 2, contStates[idx
      ++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_refdeg_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_ref_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_ref_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_m_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_m_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_m_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.v_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.r_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_dot_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.v_dot_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.r_dot_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.b_x_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.b_y_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.b_psi_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.Memory4_PreviousInput, count,
        discStates[idx++], 22, 0);
    }

    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u2_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u3_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u4_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u5_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u6_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_tilde_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_tilde_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_tilde_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_ref_out_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_ref_out_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_ref_out_DWORK1, 0, discStates[idx++],
      0, 0);
    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_refdeg_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_ref_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_ref_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_m_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_m_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_m_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_hat_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_hat_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_hat_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_hat_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.v_hat_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.r_hat_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_dot_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.v_dot_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.r_dot_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.b_x_hat_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.b_y_hat_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.b_psi_hat_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha1_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha2_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha3_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha4_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha5_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha6_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u1_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u2_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u3_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u4_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u5_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u6_DWORK2, count, discStates[idx++],
        21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_tilde_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_tilde_DWORK2, count, discStates[idx
        ++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_tilde_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_ref_out_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_ref_out_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_ref_out_DWORK2, count,
        discStates[idx++], 21, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_DP
