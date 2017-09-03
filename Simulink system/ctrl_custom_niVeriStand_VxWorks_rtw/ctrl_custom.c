/*
 * ctrl_custom.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_custom".
 *
 * Model version              : 1.85
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Sun Sep 03 17:58:51 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_custom.h"
#include "ctrl_custom_private.h"

const real_T ctrl_custom_RGND = 0.0;   /* real_T ground */

/* Block signals (auto storage) */
B_ctrl_custom_T ctrl_custom_B;

/* Continuous states */
X_ctrl_custom_T ctrl_custom_X;

/* Block states (auto storage) */
DW_ctrl_custom_T ctrl_custom_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_custom_T ctrl_custom_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_custom_T ctrl_custom_M_;
RT_MODEL_ctrl_custom_T *const ctrl_custom_M = &ctrl_custom_M_;

/* Forward declaration for local functions */
static real_T ctrl_custom_norm(const real_T x[2]);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 9;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_custom_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_custom_output();
  ctrl_custom_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_custom_output();
  ctrl_custom_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_custom_output();
  ctrl_custom_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
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

/* Function for MATLAB Function: '<S10>/MATLAB Function11' */
static real_T ctrl_custom_norm(const real_T x[2])
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
void ctrl_custom_output(void)
{
  /* local block i/o variables */
  real_T rtb_eta_ref[3];
  ZCEventType zcEvent;
  real_T alpha_tilde;
  real_T rtb_Integrator2_m;
  real_T rtb_Integrator;
  real_T rtb_Product13_h;
  real_T rtb_u_e[12];
  int32_T i;
  real_T tmp[9];
  real_T tmp_0[3];
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  real_T tmp_4;
  real_T tmp_5;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* set solver stop time */
    if (!(ctrl_custom_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_custom_M->solverInfo,
                            ((ctrl_custom_M->Timing.clockTickH0 + 1) *
        ctrl_custom_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_custom_M->solverInfo,
                            ((ctrl_custom_M->Timing.clockTick0 + 1) *
        ctrl_custom_M->Timing.stepSize0 + ctrl_custom_M->Timing.clockTickH0 *
        ctrl_custom_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_custom_M)) {
    ctrl_custom_M->Timing.t[0] = rtsiGetT(&ctrl_custom_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Memory: '<S6>/Memory4' */
    for (i = 0; i < 6; i++) {
      ctrl_custom_B.Memory4[i] = ctrl_custom_DW.Memory4_PreviousInput[i];
    }

    /* End of Memory: '<S6>/Memory4' */
  }

  /* Gain: '<Root>/deg2rad' */
  ctrl_custom_B.deg2rad = ctrl_custom_P.deg2rad_Gain * ctrl_custom_B.psi_refdeg;

  /* Gain: '<S11>/mm2m' */
  ctrl_custom_B.mm2m = ctrl_custom_P.mm2m_Gain * ctrl_custom_B.x_m;

  /* Gain: '<S11>/Gain1' */
  ctrl_custom_B.Gain1 = ctrl_custom_P.Gain1_Gain * ctrl_custom_B.y_m;

  /* Gain: '<S11>/deg2rad' */
  rtb_Integrator2_m = ctrl_custom_P.deg2rad_Gain_h * ctrl_custom_B.u80180deg;

  /* Saturate: '<S11>/Saturation' */
  if (rtb_Integrator2_m > ctrl_custom_P.Saturation_UpperSat) {
    rtb_Integrator2_m = ctrl_custom_P.Saturation_UpperSat;
  } else {
    if (rtb_Integrator2_m < ctrl_custom_P.Saturation_LowerSat) {
      rtb_Integrator2_m = ctrl_custom_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Signum: '<S11>/Sign' */
  if (rtb_Integrator2_m < 0.0) {
    rtb_Integrator = -1.0;
  } else if (rtb_Integrator2_m > 0.0) {
    rtb_Integrator = 1.0;
  } else if (rtb_Integrator2_m == 0.0) {
    rtb_Integrator = 0.0;
  } else {
    rtb_Integrator = rtb_Integrator2_m;
  }

  /* End of Signum: '<S11>/Sign' */

  /* Gain: '<S11>/Gain6' */
  rtb_Integrator *= ctrl_custom_P.Gain6_Gain;

  /* Sum: '<S11>/Sum1' */
  rtb_Integrator2_m += rtb_Integrator;

  /* Math: '<S11>/Math Function' incorporates:
   *  Constant: '<S11>/Constant1'
   */
  rtb_Integrator2_m = rt_remd_snf(rtb_Integrator2_m,
    ctrl_custom_P.Constant1_Value);

  /* Sum: '<S11>/Sum' */
  ctrl_custom_B.Sum = rtb_Integrator2_m - rtb_Integrator;

  /* MATLAB Function: '<Root>/Error in body frame !!!OBS Not marine error sign convention yet!!!' incorporates:
   *  SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport1'
   *  SignalConversion: '<S2>/TmpSignal ConversionAt SFunction Inport2'
   */
  /* MATLAB Function 'Error in body frame !!!OBS Not marine error sign convention yet!!!': '<S2>:1' */
  /* '<S2>:1:9' */
  /*  inertial frame error */
  /* '<S2>:1:3' */
  ctrl_custom_B.eta_tilde[0] = ctrl_custom_B.x_ref - ctrl_custom_B.mm2m;
  ctrl_custom_B.eta_tilde[1] = ctrl_custom_B.y_ref - ctrl_custom_B.Gain1;
  ctrl_custom_B.eta_tilde[2] = ctrl_custom_B.deg2rad - ctrl_custom_B.Sum;

  /*  body frame error */
  /* '<S2>:1:6' */
  /* '<S2>:1:7' */
  tmp[0] = cos(ctrl_custom_B.Sum);
  tmp[3] = sin(ctrl_custom_B.Sum);
  tmp[6] = 0.0;
  tmp[1] = -sin(ctrl_custom_B.Sum);
  tmp[4] = cos(ctrl_custom_B.Sum);
  tmp[7] = 0.0;
  tmp[2] = 0.0;
  tmp[5] = 0.0;
  tmp[8] = 1.0;
  for (i = 0; i < 3; i++) {
    tmp_0[i] = tmp[i + 6] * ctrl_custom_B.eta_tilde[2] + (tmp[i + 3] *
      ctrl_custom_B.eta_tilde[1] + tmp[i] * ctrl_custom_B.eta_tilde[0]);
  }

  ctrl_custom_B.eta_tilde[0] = tmp_0[0];
  ctrl_custom_B.eta_tilde[1] = tmp_0[1];
  ctrl_custom_B.eta_tilde[2] = tmp_0[2];

  /* End of MATLAB Function: '<Root>/Error in body frame !!!OBS Not marine error sign convention yet!!!' */

  /* Integrator: '<S8>/Integrator' incorporates:
   *  Integrator: '<S8>/Integrator2'
   */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator_Reset_ZCE,
                       (ctrl_custom_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_custom_X.Integrator_CSTATE = ctrl_custom_P.Integrator_IC;
    }

    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator2_Reset_ZCE,
                       (ctrl_custom_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_custom_X.Integrator2_CSTATE = ctrl_custom_P.Integrator2_IC;
    }
  }

  /* Product: '<S8>/Product13' incorporates:
   *  Integrator: '<S8>/Integrator'
   *  Integrator: '<S8>/Integrator2'
   *  Product: '<S8>/Product10'
   *  Product: '<S8>/Product14'
   *  Sum: '<S8>/Sum2'
   */
  rtb_Integrator2_m = ((ctrl_custom_B.k2_x * ctrl_custom_X.Integrator_CSTATE +
                        ctrl_custom_B.eta_tilde[0]) + ctrl_custom_B.k1_x *
                       ctrl_custom_X.Integrator2_CSTATE) * ctrl_custom_B.k0_x;

  /* Integrator: '<S8>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator1_Reset_ZCE,
                       (ctrl_custom_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_custom_X.Integrator1_CSTATE = ctrl_custom_P.Integrator1_IC;
    }
  }

  /* Sum: '<S8>/Sum3' incorporates:
   *  Integrator: '<S8>/Integrator1'
   *  Product: '<S8>/Product12'
   */
  ctrl_custom_B.Sum3 = rtb_Integrator2_m - ctrl_custom_B.gamma_x *
    ctrl_custom_X.Integrator1_CSTATE;

  /* Saturate: '<S8>/Saturation' */
  if (ctrl_custom_B.Sum3 > ctrl_custom_P.Saturation_UpperSat_d) {
    ctrl_custom_B.Saturation = ctrl_custom_P.Saturation_UpperSat_d;
  } else if (ctrl_custom_B.Sum3 < ctrl_custom_P.Saturation_LowerSat_d) {
    ctrl_custom_B.Saturation = ctrl_custom_P.Saturation_LowerSat_d;
  } else {
    ctrl_custom_B.Saturation = ctrl_custom_B.Sum3;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Integrator: '<S9>/Integrator' incorporates:
   *  Integrator: '<S9>/Integrator2'
   */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator_Reset_ZCE_e,
                       (ctrl_custom_B.reset_l));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_custom_X.Integrator_CSTATE_p = ctrl_custom_P.Integrator_IC_l;
    }

    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator2_Reset_ZCE_m,
                       (ctrl_custom_B.reset_l));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_custom_X.Integrator2_CSTATE_g = ctrl_custom_P.Integrator2_IC_k;
    }
  }

  /* Product: '<S9>/Product13' incorporates:
   *  Integrator: '<S9>/Integrator'
   *  Integrator: '<S9>/Integrator2'
   *  Product: '<S9>/Product10'
   *  Product: '<S9>/Product14'
   *  Sum: '<S9>/Sum2'
   */
  rtb_Integrator = ((ctrl_custom_B.k2_y * ctrl_custom_X.Integrator_CSTATE_p +
                     ctrl_custom_B.eta_tilde[1]) + ctrl_custom_B.k1_y *
                    ctrl_custom_X.Integrator2_CSTATE_g) * ctrl_custom_B.k0_y;

  /* Integrator: '<S9>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator1_Reset_ZCE_e,
                       (ctrl_custom_B.reset_l));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_custom_X.Integrator1_CSTATE_n = ctrl_custom_P.Integrator1_IC_p;
    }
  }

  /* Sum: '<S9>/Sum3' incorporates:
   *  Integrator: '<S9>/Integrator1'
   *  Product: '<S9>/Product12'
   */
  ctrl_custom_B.Sum3_k = rtb_Integrator - ctrl_custom_B.gamma_y *
    ctrl_custom_X.Integrator1_CSTATE_n;

  /* Saturate: '<S9>/Saturation' */
  if (ctrl_custom_B.Sum3_k > ctrl_custom_P.Saturation_UpperSat_g) {
    ctrl_custom_B.Saturation_e = ctrl_custom_P.Saturation_UpperSat_g;
  } else if (ctrl_custom_B.Sum3_k < ctrl_custom_P.Saturation_LowerSat_dv) {
    ctrl_custom_B.Saturation_e = ctrl_custom_P.Saturation_LowerSat_dv;
  } else {
    ctrl_custom_B.Saturation_e = ctrl_custom_B.Sum3_k;
  }

  /* End of Saturate: '<S9>/Saturation' */

  /* Integrator: '<S7>/Integrator' incorporates:
   *  Integrator: '<S7>/Integrator2'
   */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator_Reset_ZCE_a,
                       (ctrl_custom_B.reset_d));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_custom_X.Integrator_CSTATE_h = ctrl_custom_P.Integrator_IC_lf;
    }

    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator2_Reset_ZCE_o,
                       (ctrl_custom_B.reset_d));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_custom_X.Integrator2_CSTATE_l = ctrl_custom_P.Integrator2_IC_e;
    }
  }

  /* Product: '<S7>/Product13' incorporates:
   *  Integrator: '<S7>/Integrator'
   *  Integrator: '<S7>/Integrator2'
   *  Product: '<S7>/Product10'
   *  Product: '<S7>/Product14'
   *  Sum: '<S7>/Sum2'
   */
  rtb_Product13_h = ((ctrl_custom_B.k2_psi * ctrl_custom_X.Integrator_CSTATE_h +
                      ctrl_custom_B.eta_tilde[2]) + ctrl_custom_B.k1_psi *
                     ctrl_custom_X.Integrator2_CSTATE_l) * ctrl_custom_B.k0_psi;

  /* Integrator: '<S7>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_custom_PrevZCX.Integrator1_Reset_ZCE_l,
                       (ctrl_custom_B.reset_d));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_custom_X.Integrator1_CSTATE_p = ctrl_custom_P.Integrator1_IC_pm;
    }
  }

  /* Sum: '<S7>/Sum3' incorporates:
   *  Integrator: '<S7>/Integrator1'
   *  Product: '<S7>/Product12'
   */
  ctrl_custom_B.Sum3_o = rtb_Product13_h - ctrl_custom_B.gamma_psi *
    ctrl_custom_X.Integrator1_CSTATE_p;

  /* Saturate: '<S7>/Saturation' */
  if (ctrl_custom_B.Sum3_o > ctrl_custom_P.Saturation_UpperSat_i) {
    ctrl_custom_B.Saturation_m = ctrl_custom_P.Saturation_UpperSat_i;
  } else if (ctrl_custom_B.Sum3_o < ctrl_custom_P.Saturation_LowerSat_l) {
    ctrl_custom_B.Saturation_m = ctrl_custom_P.Saturation_LowerSat_l;
  } else {
    ctrl_custom_B.Saturation_m = ctrl_custom_B.Sum3_o;
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Gain: '<S10>/Gain' incorporates:
   *  SignalConversion: '<S10>/TmpSignal ConversionAtGainInport1'
   */
  for (i = 0; i < 12; i++) {
    rtb_u_e[i] = ctrl_custom_P.T_pinv[i + 24] * ctrl_custom_B.Saturation_m +
      (ctrl_custom_P.T_pinv[i + 12] * ctrl_custom_B.Saturation_e +
       ctrl_custom_P.T_pinv[i] * ctrl_custom_B.Saturation);
  }

  /* End of Gain: '<S10>/Gain' */

  /* MATLAB Function: '<S10>/MATLAB Function11' */
  /* MATLAB Function 'Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11': '<S14>:1' */
  /* '<S14>:1:2' */
  alpha_tilde = ctrl_custom_norm(&rtb_u_e[0]);
  tmp_1 = ctrl_custom_norm(&rtb_u_e[2]);
  tmp_2 = ctrl_custom_norm(&rtb_u_e[4]);
  tmp_3 = ctrl_custom_norm(&rtb_u_e[6]);
  tmp_4 = ctrl_custom_norm(&rtb_u_e[8]);
  tmp_5 = ctrl_custom_norm(&rtb_u_e[10]);
  ctrl_custom_B.u[0] = alpha_tilde;
  ctrl_custom_B.u[1] = tmp_1;
  ctrl_custom_B.u[2] = tmp_2;
  ctrl_custom_B.u[3] = tmp_3;
  ctrl_custom_B.u[4] = tmp_4;
  ctrl_custom_B.u[5] = tmp_5;

  /* '<S14>:1:10' */
  ctrl_custom_B.alpha[0] = rt_atan2d_snf(rtb_u_e[1], rtb_u_e[0]);
  ctrl_custom_B.alpha[1] = rt_atan2d_snf(rtb_u_e[3], rtb_u_e[2]);
  ctrl_custom_B.alpha[2] = rt_atan2d_snf(rtb_u_e[5], rtb_u_e[4]);
  ctrl_custom_B.alpha[3] = rt_atan2d_snf(rtb_u_e[7], rtb_u_e[6]);
  ctrl_custom_B.alpha[4] = rt_atan2d_snf(rtb_u_e[9], rtb_u_e[8]);
  ctrl_custom_B.alpha[5] = rt_atan2d_snf(rtb_u_e[11], rtb_u_e[10]);

  /* MATLAB Function: '<S6>/MATLAB Function11' */
  /* MATLAB Function 'Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11': '<S13>:1' */
  /* '<S13>:1:1' */
  /* '<S13>:1:4' */
  for (i = 0; i < 6; i++) {
    /* '<S13>:1:4' */
    /*  current rotation */
    /* '<S13>:1:6' */
    /* '<S13>:1:8' */
    if (ctrl_custom_B.Memory4[i] < 0.0) {
      alpha_tilde = -1.0;
    } else if (ctrl_custom_B.Memory4[i] > 0.0) {
      alpha_tilde = 1.0;
    } else if (ctrl_custom_B.Memory4[i] == 0.0) {
      alpha_tilde = 0.0;
    } else {
      alpha_tilde = ctrl_custom_B.Memory4[i];
    }

    ctrl_custom_B.alpha_infinf[i] = floor((fabs(ctrl_custom_B.Memory4[i]) +
      3.1415926535897931) / 6.2831853071795862) * alpha_tilde *
      6.2831853071795862 + ctrl_custom_B.alpha[i];

    /* '<S13>:1:10' */
    alpha_tilde = ctrl_custom_B.alpha_infinf[i] - ctrl_custom_B.Memory4[i];

    /*  Shortest rotation */
    if (fabs(alpha_tilde) > 3.1415926535897931) {
      /* '<S13>:1:13' */
      /* '<S13>:1:14' */
      if (alpha_tilde < 0.0) {
        alpha_tilde = -1.0;
      } else if (alpha_tilde > 0.0) {
        alpha_tilde = 1.0;
      } else {
        if (alpha_tilde == 0.0) {
          alpha_tilde = 0.0;
        }
      }

      ctrl_custom_B.alpha_infinf[i] -= alpha_tilde * 2.0 * 3.1415926535897931;
    }
  }

  /* End of MATLAB Function: '<S6>/MATLAB Function11' */
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo FileInport1' */
    rtb_eta_ref[0] = ctrl_custom_B.Saturation;
    rtb_eta_ref[1] = ctrl_custom_B.Saturation_e;
    rtb_eta_ref[2] = ctrl_custom_B.Saturation_m;

    /* ToFile: '<Root>/To File' */
    {
      if (!(++ctrl_custom_DW.ToFile_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile_IWORK.Count * (3 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[3 + 1];
          ctrl_custom_DW.ToFile_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = rtb_eta_ref[0];
          u[2] = rtb_eta_ref[1];
          u[3] = rtb_eta_ref[2];
          if (fwrite(u, sizeof(real_T), 3 + 1, fp) != 3 + 1) {
            rtmSetErrorStatus(ctrl_custom_M, "Error writing to MAT-file tau.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile_IWORK.Count) * (3 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file tau.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/To File1' */
    {
      if (!(++ctrl_custom_DW.ToFile1_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile1_IWORK.Count * (6 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[6 + 1];
          ctrl_custom_DW.ToFile1_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.u[0];
          u[2] = ctrl_custom_B.u[1];
          u[3] = ctrl_custom_B.u[2];
          u[4] = ctrl_custom_B.u[3];
          u[5] = ctrl_custom_B.u[4];
          u[6] = ctrl_custom_B.u[5];
          if (fwrite(u, sizeof(real_T), 6 + 1, fp) != 6 + 1) {
            rtmSetErrorStatus(ctrl_custom_M, "Error writing to MAT-file u.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile1_IWORK.Count) * (6 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file u.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/To File2' */
    {
      if (!(++ctrl_custom_DW.ToFile2_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile2_IWORK.Count * (6 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile2_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[6 + 1];
          ctrl_custom_DW.ToFile2_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.alpha_infinf[0];
          u[2] = ctrl_custom_B.alpha_infinf[1];
          u[3] = ctrl_custom_B.alpha_infinf[2];
          u[4] = ctrl_custom_B.alpha_infinf[3];
          u[5] = ctrl_custom_B.alpha_infinf[4];
          u[6] = ctrl_custom_B.alpha_infinf[5];
          if (fwrite(u, sizeof(real_T), 6 + 1, fp) != 6 + 1) {
            rtmSetErrorStatus(ctrl_custom_M,
                              "Error writing to MAT-file alpha_infinf.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile2_IWORK.Count) * (6 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file alpha_infinf.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/To File3' */
    {
      if (!(++ctrl_custom_DW.ToFile3_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile3_IWORK.Count * (6 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile3_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[6 + 1];
          ctrl_custom_DW.ToFile3_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.alpha[0];
          u[2] = ctrl_custom_B.alpha[1];
          u[3] = ctrl_custom_B.alpha[2];
          u[4] = ctrl_custom_B.alpha[3];
          u[5] = ctrl_custom_B.alpha[4];
          u[6] = ctrl_custom_B.alpha[5];
          if (fwrite(u, sizeof(real_T), 6 + 1, fp) != 6 + 1) {
            rtmSetErrorStatus(ctrl_custom_M,
                              "Error writing to MAT-file alpha_pipi.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile3_IWORK.Count) * (6 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file alpha_pipi.mat.\n");
          }
        }
      }
    }

    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo File4Inport1' */
    rtb_eta_ref[0] = ctrl_custom_B.mm2m;
    rtb_eta_ref[1] = ctrl_custom_B.Gain1;
    rtb_eta_ref[2] = ctrl_custom_B.Sum;

    /* ToFile: '<Root>/To File4' */
    {
      if (!(++ctrl_custom_DW.ToFile4_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile4_IWORK.Count * (3 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile4_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[3 + 1];
          ctrl_custom_DW.ToFile4_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = rtb_eta_ref[0];
          u[2] = rtb_eta_ref[1];
          u[3] = rtb_eta_ref[2];
          if (fwrite(u, sizeof(real_T), 3 + 1, fp) != 3 + 1) {
            rtmSetErrorStatus(ctrl_custom_M, "Error writing to MAT-file eta.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile4_IWORK.Count) * (3 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file eta.mat.\n");
          }
        }
      }
    }

    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo File5Inport1' */
    rtb_eta_ref[0] = ctrl_custom_B.x_ref;
    rtb_eta_ref[1] = ctrl_custom_B.y_ref;
    rtb_eta_ref[2] = ctrl_custom_B.deg2rad;

    /* ToFile: '<Root>/To File5' */
    {
      if (!(++ctrl_custom_DW.ToFile5_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile5_IWORK.Count * (3 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile5_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[3 + 1];
          ctrl_custom_DW.ToFile5_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = rtb_eta_ref[0];
          u[2] = rtb_eta_ref[1];
          u[3] = rtb_eta_ref[2];
          if (fwrite(u, sizeof(real_T), 3 + 1, fp) != 3 + 1) {
            rtmSetErrorStatus(ctrl_custom_M,
                              "Error writing to MAT-file eta_ref.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile5_IWORK.Count) * (3 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file eta_ref.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<Root>/To File6' */
    {
      if (!(++ctrl_custom_DW.ToFile6_IWORK.Decimation % 1) &&
          (ctrl_custom_DW.ToFile6_IWORK.Count * (3 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile6_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[3 + 1];
          ctrl_custom_DW.ToFile6_IWORK.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.eta_tilde[0];
          u[2] = ctrl_custom_B.eta_tilde[1];
          u[3] = ctrl_custom_B.eta_tilde[2];
          if (fwrite(u, sizeof(real_T), 3 + 1, fp) != 3 + 1) {
            rtmSetErrorStatus(ctrl_custom_M,
                              "Error writing to MAT-file eta_tilde.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile6_IWORK.Count) * (3 + 1))+1 >= 100000000)
          {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file eta_tilde.mat.\n");
          }
        }
      }
    }

    /* ToFile: '<S7>/To File3' */
    {
      if (!(++ctrl_custom_DW.ToFile3_IWORK_g.Decimation % 1) &&
          (ctrl_custom_DW.ToFile3_IWORK_g.Count * (1 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile3_PWORK_p.FilePtr;
        if (fp != (NULL)) {
          real_T u[1 + 1];
          ctrl_custom_DW.ToFile3_IWORK_g.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.Sum3_o;
          if (fwrite(u, sizeof(real_T), 1 + 1, fp) != 1 + 1) {
            rtmSetErrorStatus(ctrl_custom_M,
                              "Error writing to MAT-file N_unsaturated.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile3_IWORK_g.Count) * (1 + 1))+1 >=
              100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file N_unsaturated.mat.\n");
          }
        }
      }
    }
  }

  /* Sum: '<S7>/Sum' incorporates:
   *  Gain: '<S7>/Gain2'
   *  Integrator: '<S7>/Integrator'
   *  Integrator: '<S7>/Integrator2'
   *  Product: '<S7>/Product4'
   *  Product: '<S7>/Product5'
   *  Product: '<S7>/Product6'
   *  Product: '<S7>/Product7'
   */
  ctrl_custom_B.Sum_n = (ctrl_custom_B.sigma_psi * ctrl_custom_B.eta_tilde[2] *
    ctrl_custom_B.k2_psi + ctrl_custom_X.Integrator_CSTATE_h) +
    ctrl_custom_P.Gain2_Gain * ctrl_custom_B.sigma_psi *
    ctrl_custom_X.Integrator2_CSTATE_l * ctrl_custom_B.k2_psi;

  /* Sum: '<S7>/Sum1' incorporates:
   *  Gain: '<S7>/Gain1'
   *  Integrator: '<S7>/Integrator2'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product2'
   *  Product: '<S7>/Product3'
   *  Product: '<S7>/Product8'
   *  Product: '<S7>/Product9'
   */
  ctrl_custom_B.Sum1 = ctrl_custom_B.sigma_psi * ctrl_custom_B.sigma_psi *
    ctrl_custom_P.Gain1_Gain_b * ctrl_custom_X.Integrator2_CSTATE_l *
    ctrl_custom_B.k1_psi + ctrl_custom_B.sigma_psi * ctrl_custom_B.sigma_psi *
    ctrl_custom_B.eta_tilde[2] * ctrl_custom_B.k1_psi;

  /* Sum: '<S7>/Sum5' incorporates:
   *  Product: '<S7>/Product11'
   *  Sum: '<S7>/Sum4'
   */
  ctrl_custom_B.Sum5 = (ctrl_custom_B.Sum3_o - ctrl_custom_B.Saturation_m) *
    ctrl_custom_B.nu_psi - rtb_Product13_h;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* ToFile: '<S8>/To File3' */
    {
      if (!(++ctrl_custom_DW.ToFile3_IWORK_i.Decimation % 1) &&
          (ctrl_custom_DW.ToFile3_IWORK_i.Count * (1 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile3_PWORK_d.FilePtr;
        if (fp != (NULL)) {
          real_T u[1 + 1];
          ctrl_custom_DW.ToFile3_IWORK_i.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.Sum3;
          if (fwrite(u, sizeof(real_T), 1 + 1, fp) != 1 + 1) {
            rtmSetErrorStatus(ctrl_custom_M,
                              "Error writing to MAT-file X_unsaturated.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile3_IWORK_i.Count) * (1 + 1))+1 >=
              100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file X_unsaturated.mat.\n");
          }
        }
      }
    }
  }

  /* Sum: '<S8>/Sum' incorporates:
   *  Gain: '<S8>/Gain2'
   *  Integrator: '<S8>/Integrator'
   *  Integrator: '<S8>/Integrator2'
   *  Product: '<S8>/Product4'
   *  Product: '<S8>/Product5'
   *  Product: '<S8>/Product6'
   *  Product: '<S8>/Product7'
   */
  ctrl_custom_B.Sum_e = (ctrl_custom_B.sigma_x * ctrl_custom_B.eta_tilde[0] *
    ctrl_custom_B.k2_x + ctrl_custom_X.Integrator_CSTATE) +
    ctrl_custom_P.Gain2_Gain_f * ctrl_custom_B.sigma_x *
    ctrl_custom_X.Integrator2_CSTATE * ctrl_custom_B.k2_x;

  /* Sum: '<S8>/Sum1' incorporates:
   *  Gain: '<S8>/Gain1'
   *  Integrator: '<S8>/Integrator2'
   *  Product: '<S8>/Product'
   *  Product: '<S8>/Product1'
   *  Product: '<S8>/Product2'
   *  Product: '<S8>/Product3'
   *  Product: '<S8>/Product8'
   *  Product: '<S8>/Product9'
   */
  ctrl_custom_B.Sum1_j = ctrl_custom_B.sigma_x * ctrl_custom_B.sigma_x *
    ctrl_custom_P.Gain1_Gain_bw * ctrl_custom_X.Integrator2_CSTATE *
    ctrl_custom_B.k1_x + ctrl_custom_B.sigma_x * ctrl_custom_B.sigma_x *
    ctrl_custom_B.eta_tilde[0] * ctrl_custom_B.k1_x;

  /* Sum: '<S8>/Sum5' incorporates:
   *  Product: '<S8>/Product11'
   *  Sum: '<S8>/Sum4'
   */
  ctrl_custom_B.Sum5_b = (ctrl_custom_B.Sum3 - ctrl_custom_B.Saturation) *
    ctrl_custom_B.nu_x - rtb_Integrator2_m;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* ToFile: '<S9>/To File3' */
    {
      if (!(++ctrl_custom_DW.ToFile3_IWORK_d.Decimation % 1) &&
          (ctrl_custom_DW.ToFile3_IWORK_d.Count * (1 + 1)) + 1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_custom_DW.ToFile3_PWORK_h.FilePtr;
        if (fp != (NULL)) {
          real_T u[1 + 1];
          ctrl_custom_DW.ToFile3_IWORK_d.Decimation = 0;
          u[0] = ctrl_custom_M->Timing.t[1];
          u[1] = ctrl_custom_B.Sum3_k;
          if (fwrite(u, sizeof(real_T), 1 + 1, fp) != 1 + 1) {
            rtmSetErrorStatus(ctrl_custom_M,
                              "Error writing to MAT-file Y_unsaturated.mat");
            return;
          }

          if (((++ctrl_custom_DW.ToFile3_IWORK_d.Count) * (1 + 1))+1 >=
              100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file Y_unsaturated.mat.\n");
          }
        }
      }
    }
  }

  /* Sum: '<S9>/Sum' incorporates:
   *  Gain: '<S9>/Gain2'
   *  Integrator: '<S9>/Integrator'
   *  Integrator: '<S9>/Integrator2'
   *  Product: '<S9>/Product4'
   *  Product: '<S9>/Product5'
   *  Product: '<S9>/Product6'
   *  Product: '<S9>/Product7'
   */
  ctrl_custom_B.Sum_h = (ctrl_custom_B.sigma_y * ctrl_custom_B.eta_tilde[1] *
    ctrl_custom_B.k2_y + ctrl_custom_X.Integrator_CSTATE_p) +
    ctrl_custom_P.Gain2_Gain_c * ctrl_custom_B.sigma_y *
    ctrl_custom_X.Integrator2_CSTATE_g * ctrl_custom_B.k2_y;

  /* Sum: '<S9>/Sum1' incorporates:
   *  Gain: '<S9>/Gain1'
   *  Integrator: '<S9>/Integrator2'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  Product: '<S9>/Product2'
   *  Product: '<S9>/Product3'
   *  Product: '<S9>/Product8'
   *  Product: '<S9>/Product9'
   */
  ctrl_custom_B.Sum1_o = ctrl_custom_B.sigma_y * ctrl_custom_B.sigma_y *
    ctrl_custom_P.Gain1_Gain_c * ctrl_custom_X.Integrator2_CSTATE_g *
    ctrl_custom_B.k1_y + ctrl_custom_B.sigma_y * ctrl_custom_B.sigma_y *
    ctrl_custom_B.eta_tilde[1] * ctrl_custom_B.k1_y;

  /* Sum: '<S9>/Sum5' incorporates:
   *  Product: '<S9>/Product11'
   *  Sum: '<S9>/Sum4'
   */
  ctrl_custom_B.Sum5_e = (ctrl_custom_B.Sum3_k - ctrl_custom_B.Saturation_e) *
    ctrl_custom_B.nu_y - rtb_Integrator;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
  }
}

/* Model update function */
void ctrl_custom_update(void)
{
  int32_T i;
  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    /* Update for Memory: '<S6>/Memory4' */
    for (i = 0; i < 6; i++) {
      ctrl_custom_DW.Memory4_PreviousInput[i] = ctrl_custom_B.alpha_infinf[i];
    }

    /* End of Update for Memory: '<S6>/Memory4' */
  }

  if (rtmIsMajorTimeStep(ctrl_custom_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_custom_M->solverInfo);
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
  if (!(++ctrl_custom_M->Timing.clockTick0)) {
    ++ctrl_custom_M->Timing.clockTickH0;
  }

  ctrl_custom_M->Timing.t[0] = rtsiGetSolverStopTime(&ctrl_custom_M->solverInfo);

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
    if (!(++ctrl_custom_M->Timing.clockTick1)) {
      ++ctrl_custom_M->Timing.clockTickH1;
    }

    ctrl_custom_M->Timing.t[1] = ctrl_custom_M->Timing.clockTick1 *
      ctrl_custom_M->Timing.stepSize1 + ctrl_custom_M->Timing.clockTickH1 *
      ctrl_custom_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_custom_derivatives(void)
{
  XDot_ctrl_custom_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_custom_T *) ctrl_custom_M->derivs);

  /* Derivatives for Integrator: '<S8>/Integrator' */
  _rtXdot->Integrator_CSTATE = ctrl_custom_B.Sum1_j;

  /* Derivatives for Integrator: '<S8>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = ctrl_custom_B.Sum_e;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = ctrl_custom_B.Sum5_b;

  /* Derivatives for Integrator: '<S9>/Integrator' */
  _rtXdot->Integrator_CSTATE_p = ctrl_custom_B.Sum1_o;

  /* Derivatives for Integrator: '<S9>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_g = ctrl_custom_B.Sum_h;

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_n = ctrl_custom_B.Sum5_e;

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = ctrl_custom_B.Sum1;

  /* Derivatives for Integrator: '<S7>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_l = ctrl_custom_B.Sum_n;

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_p = ctrl_custom_B.Sum5;
}

/* Model initialize function */
void ctrl_custom_initialize(void)
{
  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "tau.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file tau.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 3 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file tau.mat");
      return;
    }

    ctrl_custom_DW.ToFile_IWORK.Count = 0;
    ctrl_custom_DW.ToFile_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "u.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file u.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 6 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file u.mat");
      return;
    }

    ctrl_custom_DW.ToFile1_IWORK.Count = 0;
    ctrl_custom_DW.ToFile1_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile1_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File2' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "alpha_infinf.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error creating .mat file alpha_infinf.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 6 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file alpha_infinf.mat");
      return;
    }

    ctrl_custom_DW.ToFile2_IWORK.Count = 0;
    ctrl_custom_DW.ToFile2_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile2_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File3' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "alpha_pipi.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file alpha_pipi.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 6 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file alpha_pipi.mat");
      return;
    }

    ctrl_custom_DW.ToFile3_IWORK.Count = 0;
    ctrl_custom_DW.ToFile3_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile3_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File4' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "eta.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file eta.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 3 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file eta.mat");
      return;
    }

    ctrl_custom_DW.ToFile4_IWORK.Count = 0;
    ctrl_custom_DW.ToFile4_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile4_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File5' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "eta_ref.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file eta_ref.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 3 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file eta_ref.mat");
      return;
    }

    ctrl_custom_DW.ToFile5_IWORK.Count = 0;
    ctrl_custom_DW.ToFile5_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile5_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File6' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "eta_tilde.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M, "Error creating .mat file eta_tilde.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 3 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file eta_tilde.mat");
      return;
    }

    ctrl_custom_DW.ToFile6_IWORK.Count = 0;
    ctrl_custom_DW.ToFile6_IWORK.Decimation = -1;
    ctrl_custom_DW.ToFile6_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<S7>/To File3' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "N_unsaturated.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error creating .mat file N_unsaturated.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 1 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file N_unsaturated.mat");
      return;
    }

    ctrl_custom_DW.ToFile3_IWORK_g.Count = 0;
    ctrl_custom_DW.ToFile3_IWORK_g.Decimation = -1;
    ctrl_custom_DW.ToFile3_PWORK_p.FilePtr = fp;
  }

  /* Start for ToFile: '<S8>/To File3' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "X_unsaturated.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error creating .mat file X_unsaturated.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 1 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file X_unsaturated.mat");
      return;
    }

    ctrl_custom_DW.ToFile3_IWORK_i.Count = 0;
    ctrl_custom_DW.ToFile3_IWORK_i.Decimation = -1;
    ctrl_custom_DW.ToFile3_PWORK_d.FilePtr = fp;
  }

  /* Start for ToFile: '<S9>/To File3' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Y_unsaturated.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error creating .mat file Y_unsaturated.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 1 + 1, 0, "ans")) {
      rtmSetErrorStatus(ctrl_custom_M,
                        "Error writing mat file header to file Y_unsaturated.mat");
      return;
    }

    ctrl_custom_DW.ToFile3_IWORK_d.Count = 0;
    ctrl_custom_DW.ToFile3_IWORK_d.Decimation = -1;
    ctrl_custom_DW.ToFile3_PWORK_h.FilePtr = fp;
  }

  ctrl_custom_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_custom_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_custom_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_custom_PrevZCX.Integrator_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
  ctrl_custom_PrevZCX.Integrator2_Reset_ZCE_m = UNINITIALIZED_ZCSIG;
  ctrl_custom_PrevZCX.Integrator1_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
  ctrl_custom_PrevZCX.Integrator_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
  ctrl_custom_PrevZCX.Integrator2_Reset_ZCE_o = UNINITIALIZED_ZCSIG;
  ctrl_custom_PrevZCX.Integrator1_Reset_ZCE_l = UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for Memory: '<S6>/Memory4' */
    for (i = 0; i < 6; i++) {
      ctrl_custom_DW.Memory4_PreviousInput[i] = ctrl_custom_P.Memory4_X0[i];
    }

    /* End of InitializeConditions for Memory: '<S6>/Memory4' */

    /* InitializeConditions for Integrator: '<S8>/Integrator' */
    ctrl_custom_X.Integrator_CSTATE = ctrl_custom_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S8>/Integrator2' */
    ctrl_custom_X.Integrator2_CSTATE = ctrl_custom_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S8>/Integrator1' */
    ctrl_custom_X.Integrator1_CSTATE = ctrl_custom_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<S9>/Integrator' */
    ctrl_custom_X.Integrator_CSTATE_p = ctrl_custom_P.Integrator_IC_l;

    /* InitializeConditions for Integrator: '<S9>/Integrator2' */
    ctrl_custom_X.Integrator2_CSTATE_g = ctrl_custom_P.Integrator2_IC_k;

    /* InitializeConditions for Integrator: '<S9>/Integrator1' */
    ctrl_custom_X.Integrator1_CSTATE_n = ctrl_custom_P.Integrator1_IC_p;

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    ctrl_custom_X.Integrator_CSTATE_h = ctrl_custom_P.Integrator_IC_lf;

    /* InitializeConditions for Integrator: '<S7>/Integrator2' */
    ctrl_custom_X.Integrator2_CSTATE_l = ctrl_custom_P.Integrator2_IC_e;

    /* InitializeConditions for Integrator: '<S7>/Integrator1' */
    ctrl_custom_X.Integrator1_CSTATE_p = ctrl_custom_P.Integrator1_IC_pm;
  }
}

/* Model terminate function */
void ctrl_custom_terminate(void)
{
  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "tau.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file tau.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M, "Error reopening MAT-file tau.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 3 + 1, ctrl_custom_DW.ToFile_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file tau.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file tau.mat");
        return;
      }

      ctrl_custom_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "u.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file u.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M, "Error reopening MAT-file u.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6 + 1, ctrl_custom_DW.ToFile1_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file u.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file u.mat");
        return;
      }

      ctrl_custom_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File2' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile2_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "alpha_infinf.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error closing MAT-file alpha_infinf.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error reopening MAT-file alpha_infinf.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6 + 1, ctrl_custom_DW.ToFile2_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file alpha_infinf.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error closing MAT-file alpha_infinf.mat");
        return;
      }

      ctrl_custom_DW.ToFile2_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File3' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile3_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "alpha_pipi.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file alpha_pipi.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error reopening MAT-file alpha_pipi.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6 + 1, ctrl_custom_DW.ToFile3_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file alpha_pipi.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file alpha_pipi.mat");
        return;
      }

      ctrl_custom_DW.ToFile3_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File4' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile4_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "eta.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file eta.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M, "Error reopening MAT-file eta.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 3 + 1, ctrl_custom_DW.ToFile4_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file eta.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file eta.mat");
        return;
      }

      ctrl_custom_DW.ToFile4_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File5' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile5_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "eta_ref.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file eta_ref.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M, "Error reopening MAT-file eta_ref.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 3 + 1, ctrl_custom_DW.ToFile5_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file eta_ref.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file eta_ref.mat");
        return;
      }

      ctrl_custom_DW.ToFile5_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File6' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile6_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "eta_tilde.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file eta_tilde.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error reopening MAT-file eta_tilde.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 3 + 1, ctrl_custom_DW.ToFile6_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file eta_tilde.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M, "Error closing MAT-file eta_tilde.mat");
        return;
      }

      ctrl_custom_DW.ToFile6_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S7>/To File3' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile3_PWORK_p.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "N_unsaturated.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error closing MAT-file N_unsaturated.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error reopening MAT-file N_unsaturated.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 1 + 1, ctrl_custom_DW.ToFile3_IWORK_g.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file N_unsaturated.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error closing MAT-file N_unsaturated.mat");
        return;
      }

      ctrl_custom_DW.ToFile3_PWORK_p.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S8>/To File3' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile3_PWORK_d.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "X_unsaturated.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error closing MAT-file X_unsaturated.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error reopening MAT-file X_unsaturated.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 1 + 1, ctrl_custom_DW.ToFile3_IWORK_i.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file X_unsaturated.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error closing MAT-file X_unsaturated.mat");
        return;
      }

      ctrl_custom_DW.ToFile3_PWORK_d.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S9>/To File3' */
  {
    FILE *fp = (FILE *) ctrl_custom_DW.ToFile3_PWORK_h.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Y_unsaturated.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error closing MAT-file Y_unsaturated.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error reopening MAT-file Y_unsaturated.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 1 + 1, ctrl_custom_DW.ToFile3_IWORK_d.Count,
           "ans")) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error writing header for ans to MAT-file Y_unsaturated.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_custom_M,
                          "Error closing MAT-file Y_unsaturated.mat");
        return;
      }

      ctrl_custom_DW.ToFile3_PWORK_h.FilePtr = (NULL);
    }
  }
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
  ctrl_custom_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_custom_update();
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
  ctrl_custom_initialize();
}

void MdlTerminate(void)
{
  ctrl_custom_terminate();
}

/* Registration function */
RT_MODEL_ctrl_custom_T *ctrl_custom(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_custom_M, 0,
                sizeof(RT_MODEL_ctrl_custom_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_custom_M->solverInfo,
                          &ctrl_custom_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_custom_M->solverInfo, &rtmGetTPtr(ctrl_custom_M));
    rtsiSetStepSizePtr(&ctrl_custom_M->solverInfo,
                       &ctrl_custom_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_custom_M->solverInfo, &ctrl_custom_M->derivs);
    rtsiSetContStatesPtr(&ctrl_custom_M->solverInfo, (real_T **)
                         &ctrl_custom_M->contStates);
    rtsiSetNumContStatesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ctrl_custom_M->solverInfo,
      &ctrl_custom_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ctrl_custom_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_custom_M)));
    rtsiSetRTModelPtr(&ctrl_custom_M->solverInfo, ctrl_custom_M);
  }

  rtsiSetSimTimeStep(&ctrl_custom_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_custom_M->intgData.y = ctrl_custom_M->odeY;
  ctrl_custom_M->intgData.f[0] = ctrl_custom_M->odeF[0];
  ctrl_custom_M->intgData.f[1] = ctrl_custom_M->odeF[1];
  ctrl_custom_M->intgData.f[2] = ctrl_custom_M->odeF[2];
  ctrl_custom_M->intgData.f[3] = ctrl_custom_M->odeF[3];
  ctrl_custom_M->contStates = ((real_T *) &ctrl_custom_X);
  rtsiSetSolverData(&ctrl_custom_M->solverInfo, (void *)&ctrl_custom_M->intgData);
  rtsiSetSolverName(&ctrl_custom_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_custom_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_custom_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_custom_M->Timing.sampleTimes = (&ctrl_custom_M->
      Timing.sampleTimesArray[0]);
    ctrl_custom_M->Timing.offsetTimes = (&ctrl_custom_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_custom_M->Timing.sampleTimes[0] = (0.0);
    ctrl_custom_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_custom_M->Timing.offsetTimes[0] = (0.0);
    ctrl_custom_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_custom_M, &ctrl_custom_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_custom_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_custom_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_custom_M, -1);
  ctrl_custom_M->Timing.stepSize0 = 0.01;
  ctrl_custom_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ctrl_custom_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_custom_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_custom_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_custom_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_custom_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_custom_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_custom_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_custom_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_custom_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_custom_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_custom_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_custom_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_custom_M->rtwLogInfo, (NULL));
  }

  ctrl_custom_M->solverInfoPtr = (&ctrl_custom_M->solverInfo);
  ctrl_custom_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_custom_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_custom_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_custom_M->blockIO = ((void *) &ctrl_custom_B);
  (void) memset(((void *) &ctrl_custom_B), 0,
                sizeof(B_ctrl_custom_T));

  /* parameters */
  ctrl_custom_M->defaultParam = ((real_T *)&ctrl_custom_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_custom_X;
    ctrl_custom_M->contStates = (x);
    (void) memset((void *)&ctrl_custom_X, 0,
                  sizeof(X_ctrl_custom_T));
  }

  /* states (dwork) */
  ctrl_custom_M->dwork = ((void *) &ctrl_custom_DW);
  (void) memset((void *)&ctrl_custom_DW, 0,
                sizeof(DW_ctrl_custom_T));

  /* Initialize Sizes */
  ctrl_custom_M->Sizes.numContStates = (9);/* Number of continuous states */
  ctrl_custom_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_custom_M->Sizes.numY = (0);     /* Number of model outputs */
  ctrl_custom_M->Sizes.numU = (0);     /* Number of model inputs */
  ctrl_custom_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_custom_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_custom_M->Sizes.numBlocks = (163);/* Number of blocks */
  ctrl_custom_M->Sizes.numBlockIO = (58);/* Number of block outputs */
  ctrl_custom_M->Sizes.numBlockPrms = (353);/* Sum of parameter "widths" */
  return ctrl_custom_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.85
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Sun Sep 03 17:58:51 2017
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_custom
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,10,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return (( double *)ptr)[subindex];

   case 28:
    return (( double *)ptr)[subindex];

   case 29:
    return (( double *)ptr)[subindex];

   case 30:
    return (( double *)ptr)[subindex];

   case 31:
    return (( double *)ptr)[subindex];

   case 32:
    return (( double *)ptr)[subindex];

   case 33:
    return (( double *)ptr)[subindex];

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 35:
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
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 10, Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 27:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 28:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 29:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 30:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 31:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 32:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 33:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 35:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_custom_rtModel *S;
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

  // ctrl_custom/Input to model
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Inputtomodel, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/x_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.x_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/y_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.y_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 x/sigma_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.sigma_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 x/k1_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.k1_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 x/k2_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.k2_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 x/k0_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.k0_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 x/nu_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.nu_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 x/gamma_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.gamma_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 x/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/psi_ref [deg]
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.psi_refdeg, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/eta_QTM/x_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.x_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/eta_QTM/y_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.y_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/eta_QTM/psi_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.u80180deg, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 y/sigma_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.sigma_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 y/k1_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.k1_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 y/k2_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.k2_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 y/k0_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.k0_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 y/nu_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.nu_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 y/gamma_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.gamma_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 y/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.reset_l, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 psi/sigma_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.sigma_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 psi/k1_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.k1_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 psi/k2_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.k2_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 psi/k0_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.k0_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 psi/nu_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.nu_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 psi/gamma_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.gamma_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Regulator 2 psi/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.reset_d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Acc_x
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Acc_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Acc_y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Acc_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Acc_z
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Acc_z, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Gyro_x
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Gyro_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Gyro_y
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Gyro_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/IMU/Gyro_z
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_custom_B.Gyro_z, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 34;
}

int32_t NumOutputPorts(void)
{
  return 13;
}

double ni_extout[13];

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

  // ctrl_custom/Output to Workspace: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_custom_RGND, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/alpha1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 0,
      20, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/alpha2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 1,
      20, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/alpha3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 2,
      20, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/alpha4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 3,
      20, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/alpha5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 4,
      20, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/alpha6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 5,
      20, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/u1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 0, 20, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/u2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 1, 20, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/u3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 2, 20, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/u4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 3, 20, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/u5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 4, 20, 0);
  } else {
    index += 1;
  }

  // ctrl_custom/Output/u6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 5, 20, 0);
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

  // ctrl_custom/Output to Workspace: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType((real_T*)&ctrl_custom_RGND, 0, 0,
    0);

  // ctrl_custom/Output/alpha1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 0,
    20, 0);

  // ctrl_custom/Output/alpha2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 1,
    20, 0);

  // ctrl_custom/Output/alpha3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 2,
    20, 0);

  // ctrl_custom/Output/alpha4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 3,
    20, 0);

  // ctrl_custom/Output/alpha5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 4,
    20, 0);

  // ctrl_custom/Output/alpha6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.alpha_infinf, 5,
    20, 0);

  // ctrl_custom/Output/u1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 0, 20, 0);

  // ctrl_custom/Output/u2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 1, 20, 0);

  // ctrl_custom/Output/u3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 2, 20, 0);

  // ctrl_custom/Output/u4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 3, 20, 0);

  // ctrl_custom/Output/u5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 4, 20, 0);

  // ctrl_custom/Output/u6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_custom_B.u, 5, 20, 0);
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
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/Gain/Gain",
    offsetof(P_ctrl_custom_T, T_pinv), 24, 36, 2, 0, 0 },

  { 1,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/X0",
    offsetof(P_ctrl_custom_T, Memory4_X0), 25, 6, 2, 2, 0 },

  { 2, "ctrl_custom/deg2rad/Gain", offsetof(P_ctrl_custom_T, deg2rad_Gain), 34,
    1, 2, 4, 0 },

  { 3, "ctrl_custom/eta_QTM/mm2m/Gain", offsetof(P_ctrl_custom_T, mm2m_Gain), 34,
    1, 2, 6, 0 },

  { 4, "ctrl_custom/eta_QTM/Gain1/Gain", offsetof(P_ctrl_custom_T, Gain1_Gain),
    34, 1, 2, 8, 0 },

  { 5, "ctrl_custom/eta_QTM/deg2rad/Gain", offsetof(P_ctrl_custom_T,
    deg2rad_Gain_h), 34, 1, 2, 10, 0 },

  { 6, "ctrl_custom/eta_QTM/Saturation/UpperLimit", offsetof(P_ctrl_custom_T,
    Saturation_UpperSat), 34, 1, 2, 12, 0 },

  { 7, "ctrl_custom/eta_QTM/Saturation/LowerLimit", offsetof(P_ctrl_custom_T,
    Saturation_LowerSat), 34, 1, 2, 14, 0 },

  { 8, "ctrl_custom/eta_QTM/Gain6/Gain", offsetof(P_ctrl_custom_T, Gain6_Gain),
    34, 1, 2, 16, 0 },

  { 9, "ctrl_custom/eta_QTM/Constant1/Value", offsetof(P_ctrl_custom_T,
    Constant1_Value), 34, 1, 2, 18, 0 },

  { 10, "ctrl_custom/Regulator 2 x/Integrator/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator_IC), 34, 1, 2, 20, 0 },

  { 11, "ctrl_custom/Regulator 2 x/Integrator2/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator2_IC), 34, 1, 2, 22, 0 },

  { 12, "ctrl_custom/Regulator 2 x/Integrator1/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator1_IC), 34, 1, 2, 24, 0 },

  { 13, "ctrl_custom/Regulator 2 x/Saturation/UpperLimit", offsetof
    (P_ctrl_custom_T, Saturation_UpperSat_d), 34, 1, 2, 26, 0 },

  { 14, "ctrl_custom/Regulator 2 x/Saturation/LowerLimit", offsetof
    (P_ctrl_custom_T, Saturation_LowerSat_d), 34, 1, 2, 28, 0 },

  { 15, "ctrl_custom/Regulator 2 y/Integrator/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator_IC_l), 34, 1, 2, 30, 0 },

  { 16, "ctrl_custom/Regulator 2 y/Integrator2/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator2_IC_k), 34, 1, 2, 32, 0 },

  { 17, "ctrl_custom/Regulator 2 y/Integrator1/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator1_IC_p), 34, 1, 2, 34, 0 },

  { 18, "ctrl_custom/Regulator 2 y/Saturation/UpperLimit", offsetof
    (P_ctrl_custom_T, Saturation_UpperSat_g), 34, 1, 2, 36, 0 },

  { 19, "ctrl_custom/Regulator 2 y/Saturation/LowerLimit", offsetof
    (P_ctrl_custom_T, Saturation_LowerSat_dv), 34, 1, 2, 38, 0 },

  { 20, "ctrl_custom/Regulator 2 psi/Integrator/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator_IC_lf), 34, 1, 2, 40, 0 },

  { 21, "ctrl_custom/Regulator 2 psi/Integrator2/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator2_IC_e), 34, 1, 2, 42, 0 },

  { 22, "ctrl_custom/Regulator 2 psi/Integrator1/InitialCondition", offsetof
    (P_ctrl_custom_T, Integrator1_IC_pm), 34, 1, 2, 44, 0 },

  { 23, "ctrl_custom/Regulator 2 psi/Saturation/UpperLimit", offsetof
    (P_ctrl_custom_T, Saturation_UpperSat_i), 34, 1, 2, 46, 0 },

  { 24, "ctrl_custom/Regulator 2 psi/Saturation/LowerLimit", offsetof
    (P_ctrl_custom_T, Saturation_LowerSat_l), 34, 1, 2, 48, 0 },

  { 25, "ctrl_custom/Regulator 2 psi/Gain1/Gain", offsetof(P_ctrl_custom_T,
    Gain1_Gain_b), 34, 1, 2, 50, 0 },

  { 26, "ctrl_custom/Regulator 2 psi/Gain2/Gain", offsetof(P_ctrl_custom_T,
    Gain2_Gain), 34, 1, 2, 52, 0 },

  { 27, "ctrl_custom/Regulator 2 x/Gain1/Gain", offsetof(P_ctrl_custom_T,
    Gain1_Gain_bw), 34, 1, 2, 54, 0 },

  { 28, "ctrl_custom/Regulator 2 x/Gain2/Gain", offsetof(P_ctrl_custom_T,
    Gain2_Gain_f), 34, 1, 2, 56, 0 },

  { 29, "ctrl_custom/Regulator 2 y/Gain1/Gain", offsetof(P_ctrl_custom_T,
    Gain1_Gain_c), 34, 1, 2, 58, 0 },

  { 30, "ctrl_custom/Regulator 2 y/Gain2/Gain", offsetof(P_ctrl_custom_T,
    Gain2_Gain_c), 34, 1, 2, 60, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 31;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  12, 3,                               /* Parameter at index 0 */
  6, 1,                                /* Parameter at index 1 */
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
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
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
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_custom/Input to model", 0, "", offsetof(B_ctrl_custom_T,
    Inputtomodel) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_custom/x_ref", 0, "", offsetof(B_ctrl_custom_T, x_ref) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_custom/y_ref", 0, "", offsetof(B_ctrl_custom_T, y_ref) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 1)",
    0, "", offsetof(B_ctrl_custom_T, Memory4) + (0*sizeof(real_T)), BLOCKIO_SIG,
    20, 1, 2, 0, 0 },

  { 4,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 2)",
    0, "", offsetof(B_ctrl_custom_T, Memory4) + (1*sizeof(real_T)), BLOCKIO_SIG,
    20, 1, 2, 0, 0 },

  { 5,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 3)",
    0, "", offsetof(B_ctrl_custom_T, Memory4) + (2*sizeof(real_T)), BLOCKIO_SIG,
    20, 1, 2, 0, 0 },

  { 6,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 4)",
    0, "", offsetof(B_ctrl_custom_T, Memory4) + (3*sizeof(real_T)), BLOCKIO_SIG,
    20, 1, 2, 0, 0 },

  { 7,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 5)",
    0, "", offsetof(B_ctrl_custom_T, Memory4) + (4*sizeof(real_T)), BLOCKIO_SIG,
    20, 1, 2, 0, 0 },

  { 8,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/Memory4/(1, 6)",
    0, "", offsetof(B_ctrl_custom_T, Memory4) + (5*sizeof(real_T)), BLOCKIO_SIG,
    20, 1, 2, 0, 0 },

  { 9, "ctrl_custom/Regulator 2 x/sigma_x", 0, "", offsetof(B_ctrl_custom_T,
    sigma_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_custom/Regulator 2 x/k1_x", 0, "", offsetof(B_ctrl_custom_T, k1_x)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_custom/Regulator 2 x/k2_x", 0, "", offsetof(B_ctrl_custom_T, k2_x)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_custom/Regulator 2 x/k0_x", 0, "", offsetof(B_ctrl_custom_T, k0_x)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_custom/Regulator 2 x/nu_x", 0, "", offsetof(B_ctrl_custom_T, nu_x)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "ctrl_custom/Regulator 2 x/gamma_x", 0, "", offsetof(B_ctrl_custom_T,
    gamma_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "ctrl_custom/Regulator 2 x/reset", 0, "", offsetof(B_ctrl_custom_T,
    reset) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "ctrl_custom/psi_ref [deg]", 0, "", offsetof(B_ctrl_custom_T, psi_refdeg)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "ctrl_custom/deg2rad", 0, "", offsetof(B_ctrl_custom_T, deg2rad) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "ctrl_custom/eta_QTM/x_m", 0, "", offsetof(B_ctrl_custom_T, x_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 19, "ctrl_custom/eta_QTM/mm2m", 0, "", offsetof(B_ctrl_custom_T, mm2m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "ctrl_custom/eta_QTM/y_m", 0, "", offsetof(B_ctrl_custom_T, y_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "ctrl_custom/eta_QTM/Gain1", 0, "", offsetof(B_ctrl_custom_T, Gain1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "ctrl_custom/eta_QTM/psi_m", 0, "[-180,180] [deg]", offsetof
    (B_ctrl_custom_T, u80180deg) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 23, "ctrl_custom/eta_QTM/Sum", 0, "", offsetof(B_ctrl_custom_T, Sum) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 24, "ctrl_custom/Regulator 2 x/Sum3", 0, "", offsetof(B_ctrl_custom_T, Sum3)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 25, "ctrl_custom/Regulator 2 x/Saturation", 0, "", offsetof(B_ctrl_custom_T,
    Saturation) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 26, "ctrl_custom/Regulator 2 y/sigma_y", 0, "", offsetof(B_ctrl_custom_T,
    sigma_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 27, "ctrl_custom/Regulator 2 y/k1_y", 0, "", offsetof(B_ctrl_custom_T, k1_y)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 28, "ctrl_custom/Regulator 2 y/k2_y", 0, "", offsetof(B_ctrl_custom_T, k2_y)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 29, "ctrl_custom/Regulator 2 y/k0_y", 0, "", offsetof(B_ctrl_custom_T, k0_y)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 30, "ctrl_custom/Regulator 2 y/nu_y", 0, "", offsetof(B_ctrl_custom_T, nu_y)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 31, "ctrl_custom/Regulator 2 y/gamma_y", 0, "", offsetof(B_ctrl_custom_T,
    gamma_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 32, "ctrl_custom/Regulator 2 y/reset", 0, "", offsetof(B_ctrl_custom_T,
    reset_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 33, "ctrl_custom/Regulator 2 y/Sum3", 0, "", offsetof(B_ctrl_custom_T,
    Sum3_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 34, "ctrl_custom/Regulator 2 y/Saturation", 0, "", offsetof(B_ctrl_custom_T,
    Saturation_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 35, "ctrl_custom/Regulator 2 psi/sigma_psi", 0, "", offsetof(B_ctrl_custom_T,
    sigma_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 36, "ctrl_custom/Regulator 2 psi/k1_psi", 0, "", offsetof(B_ctrl_custom_T,
    k1_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 37, "ctrl_custom/Regulator 2 psi/k2_psi", 0, "", offsetof(B_ctrl_custom_T,
    k2_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 38, "ctrl_custom/Regulator 2 psi/k0_psi", 0, "", offsetof(B_ctrl_custom_T,
    k0_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 39, "ctrl_custom/Regulator 2 psi/nu_psi", 0, "", offsetof(B_ctrl_custom_T,
    nu_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 40, "ctrl_custom/Regulator 2 psi/gamma_psi", 0, "", offsetof(B_ctrl_custom_T,
    gamma_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 41, "ctrl_custom/Regulator 2 psi/reset", 0, "", offsetof(B_ctrl_custom_T,
    reset_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 42, "ctrl_custom/Regulator 2 psi/Sum3", 0, "", offsetof(B_ctrl_custom_T,
    Sum3_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 43, "ctrl_custom/Regulator 2 psi/Saturation", 0, "", offsetof
    (B_ctrl_custom_T, Saturation_m) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 44, "ctrl_custom/Regulator 2 psi/Sum", 0, "", offsetof(B_ctrl_custom_T,
    Sum_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 45, "ctrl_custom/Regulator 2 psi/Sum1", 0, "", offsetof(B_ctrl_custom_T,
    Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 46, "ctrl_custom/Regulator 2 psi/Sum5", 0, "", offsetof(B_ctrl_custom_T,
    Sum5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 47, "ctrl_custom/Regulator 2 x/Sum", 0, "", offsetof(B_ctrl_custom_T, Sum_e)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 48, "ctrl_custom/Regulator 2 x/Sum1", 0, "", offsetof(B_ctrl_custom_T,
    Sum1_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 49, "ctrl_custom/Regulator 2 x/Sum5", 0, "", offsetof(B_ctrl_custom_T,
    Sum5_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 50, "ctrl_custom/Regulator 2 y/Sum", 0, "", offsetof(B_ctrl_custom_T, Sum_h)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 51, "ctrl_custom/Regulator 2 y/Sum1", 0, "", offsetof(B_ctrl_custom_T,
    Sum1_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 52, "ctrl_custom/Regulator 2 y/Sum5", 0, "", offsetof(B_ctrl_custom_T,
    Sum5_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 53, "ctrl_custom/IMU/Acc_x", 0, "", offsetof(B_ctrl_custom_T, Acc_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 54, "ctrl_custom/IMU/Acc_y", 0, "", offsetof(B_ctrl_custom_T, Acc_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 55, "ctrl_custom/IMU/Acc_z", 0, "", offsetof(B_ctrl_custom_T, Acc_z) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 56, "ctrl_custom/IMU/Gyro_x", 0, "", offsetof(B_ctrl_custom_T, Gyro_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 57, "ctrl_custom/IMU/Gyro_y", 0, "", offsetof(B_ctrl_custom_T, Gyro_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 58, "ctrl_custom/IMU/Gyro_z", 0, "", offsetof(B_ctrl_custom_T, Gyro_z) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 59,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 1)", offsetof(B_ctrl_custom_T, u) + (0*sizeof(real_T)), BLOCKIO_SIG,
    20, 1, 2, 0, 0 },

  { 60,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 2)", offsetof(B_ctrl_custom_T, u) + (1*sizeof(real_T)), BLOCKIO_SIG,
    20, 1, 2, 0, 0 },

  { 61,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 3)", offsetof(B_ctrl_custom_T, u) + (2*sizeof(real_T)), BLOCKIO_SIG,
    20, 1, 2, 0, 0 },

  { 62,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 4)", offsetof(B_ctrl_custom_T, u) + (3*sizeof(real_T)), BLOCKIO_SIG,
    20, 1, 2, 0, 0 },

  { 63,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 5)", offsetof(B_ctrl_custom_T, u) + (4*sizeof(real_T)), BLOCKIO_SIG,
    20, 1, 2, 0, 0 },

  { 64,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    0, "(1, 6)", offsetof(B_ctrl_custom_T, u) + (5*sizeof(real_T)), BLOCKIO_SIG,
    20, 1, 2, 0, 0 },

  { 65,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    1, "(1, 1)", offsetof(B_ctrl_custom_T, alpha) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 66,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    1, "(1, 2)", offsetof(B_ctrl_custom_T, alpha) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 67,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    1, "(1, 3)", offsetof(B_ctrl_custom_T, alpha) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 68,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    1, "(1, 4)", offsetof(B_ctrl_custom_T, alpha) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 69,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    1, "(1, 5)", offsetof(B_ctrl_custom_T, alpha) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 70,
    "ctrl_custom/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11",
    1, "(1, 6)", offsetof(B_ctrl_custom_T, alpha) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 71,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 1)", offsetof(B_ctrl_custom_T, alpha_infinf) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 72,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 2)", offsetof(B_ctrl_custom_T, alpha_infinf) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 73,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 3)", offsetof(B_ctrl_custom_T, alpha_infinf) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 74,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 4)", offsetof(B_ctrl_custom_T, alpha_infinf) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 75,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 5)", offsetof(B_ctrl_custom_T, alpha_infinf) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 76,
    "ctrl_custom/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11",
    0, "(1, 6)", offsetof(B_ctrl_custom_T, alpha_infinf) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 20, 1, 2, 0, 0 },

  { 77,
    "ctrl_custom/Error in body frame !!!OBS Not marine error sign convention yet!!!",
    0, "(1, 1)", offsetof(B_ctrl_custom_T, eta_tilde) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 78,
    "ctrl_custom/Error in body frame !!!OBS Not marine error sign convention yet!!!",
    0, "(1, 2)", offsetof(B_ctrl_custom_T, eta_tilde) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 79,
    "ctrl_custom/Error in body frame !!!OBS Not marine error sign convention yet!!!",
    0, "(1, 3)", offsetof(B_ctrl_custom_T, eta_tilde) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 80;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 47;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Input to model", 1, EXT_IN, 1, 1, 1 },

  { 2, "x_ref", 0, EXT_IN, 1, 1, 1 },

  { 3, "y_ref", 0, EXT_IN, 1, 1, 1 },

  { 4, "Regulator 2 x/sigma_x", 0, EXT_IN, 1, 1, 1 },

  { 5, "Regulator 2 x/k1_x", 0, EXT_IN, 1, 1, 1 },

  { 6, "Regulator 2 x/k2_x", 0, EXT_IN, 1, 1, 1 },

  { 7, "Regulator 2 x/k0_x", 0, EXT_IN, 1, 1, 1 },

  { 8, "Regulator 2 x/nu_x", 0, EXT_IN, 1, 1, 1 },

  { 9, "Regulator 2 x/gamma_x", 0, EXT_IN, 1, 1, 1 },

  { 10, "Regulator 2 x/reset", 0, EXT_IN, 1, 1, 1 },

  { 11, "psi_ref [deg]", 0, EXT_IN, 1, 1, 1 },

  { 12, "eta_QTM/x_m", 0, EXT_IN, 1, 1, 1 },

  { 13, "eta_QTM/y_m", 0, EXT_IN, 1, 1, 1 },

  { 14, "eta_QTM/psi_m", 0, EXT_IN, 1, 1, 1 },

  { 15, "Regulator 2 y/sigma_y", 0, EXT_IN, 1, 1, 1 },

  { 16, "Regulator 2 y/k1_y", 0, EXT_IN, 1, 1, 1 },

  { 17, "Regulator 2 y/k2_y", 0, EXT_IN, 1, 1, 1 },

  { 18, "Regulator 2 y/k0_y", 0, EXT_IN, 1, 1, 1 },

  { 19, "Regulator 2 y/nu_y", 0, EXT_IN, 1, 1, 1 },

  { 20, "Regulator 2 y/gamma_y", 0, EXT_IN, 1, 1, 1 },

  { 21, "Regulator 2 y/reset", 0, EXT_IN, 1, 1, 1 },

  { 22, "Regulator 2 psi/sigma_psi", 0, EXT_IN, 1, 1, 1 },

  { 23, "Regulator 2 psi/k1_psi", 0, EXT_IN, 1, 1, 1 },

  { 24, "Regulator 2 psi/k2_psi", 0, EXT_IN, 1, 1, 1 },

  { 25, "Regulator 2 psi/k0_psi", 0, EXT_IN, 1, 1, 1 },

  { 26, "Regulator 2 psi/nu_psi", 0, EXT_IN, 1, 1, 1 },

  { 27, "Regulator 2 psi/gamma_psi", 0, EXT_IN, 1, 1, 1 },

  { 28, "Regulator 2 psi/reset", 0, EXT_IN, 1, 1, 1 },

  { 29, "IMU/Acc_x", 1, EXT_IN, 1, 1, 1 },

  { 30, "IMU/Acc_y", 1, EXT_IN, 1, 1, 1 },

  { 31, "IMU/Acc_z", 1, EXT_IN, 1, 1, 1 },

  { 32, "IMU/Gyro_x", 1, EXT_IN, 1, 1, 1 },

  { 33, "IMU/Gyro_y", 1, EXT_IN, 1, 1, 1 },

  { 34, "IMU/Gyro_z", 1, EXT_IN, 1, 1, 1 },

  { 1, "Output to Workspace", 1, EXT_OUT, 1, 1, 1 },

  { 2, "Output/alpha1", 0, EXT_OUT, 1, 1, 1 },

  { 3, "Output/alpha2", 0, EXT_OUT, 1, 1, 1 },

  { 4, "Output/alpha3", 0, EXT_OUT, 1, 1, 1 },

  { 5, "Output/alpha4", 0, EXT_OUT, 1, 1, 1 },

  { 6, "Output/alpha5", 0, EXT_OUT, 1, 1, 1 },

  { 7, "Output/alpha6", 0, EXT_OUT, 1, 1, 1 },

  { 8, "Output/u1", 0, EXT_OUT, 1, 1, 1 },

  { 9, "Output/u2", 0, EXT_OUT, 1, 1, 1 },

  { 10, "Output/u3", 0, EXT_OUT, 1, 1, 1 },

  { 11, "Output/u4", 0, EXT_OUT, 1, 1, 1 },

  { 12, "Output/u5", 0, EXT_OUT, 1, 1, 1 },

  { 13, "Output/u6", 0, EXT_OUT, 1, 1, 1 },

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
  "ctrl_custom";
static const char* NI_CompiledModelVersion = "1.85";
static const char* NI_CompiledModelDateTime = "Sun Sep 03 17:58:51 2017";
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
  memcpy(&rtParameter[0], &ctrl_custom_P, sizeof(P_ctrl_custom_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_custom_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_custom_T));
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
             (P_ctrl_custom_T));
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
               (P_ctrl_custom_T));
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
             (P_ctrl_custom_T));
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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_custom_T));
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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_custom_T));
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
      *numContStates = 9;
      *numDiscStates = 647;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator_CSTATE_p), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_p");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator2_CSTATE_g), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator1_CSTATE_n), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_n");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator_CSTATE_h), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_h");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator2_CSTATE_l), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_custom_X.Integrator1_CSTATE_p), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_p");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.Inputtomodel_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.Inputtomodel_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.OutputtoWorkspace_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.OutputtoWorkspace_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_ref_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_ref_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_ref_DWORK1");
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.Memory4_PreviousInput, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.Memory4_PreviousInput");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.sigma_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.sigma_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k1_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k1_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k2_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k2_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k0_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k0_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.nu_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.nu_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.gamma_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.gamma_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.reset_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_refdeg_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_refdeg_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.sigma_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.sigma_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k1_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k1_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k2_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k2_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k0_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k0_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.nu_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.nu_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.gamma_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.gamma_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.reset_DWORK1_k, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.reset_DWORK1_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.sigma_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.sigma_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k1_psi_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k1_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k2_psi_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k2_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k0_psi_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k0_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.nu_psi_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.nu_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.gamma_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.gamma_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.reset_DWORK1_i, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.reset_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha4_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha5_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha6_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_z_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile1_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile1_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile2_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile2_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile3_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile3_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile4_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile4_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile5_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile5_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile6_PWORK, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile6_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile3_PWORK_p, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile3_PWORK_p");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile3_PWORK_d, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile3_PWORK_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile3_PWORK_h, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile3_PWORK_h");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.ToFile_IWORK.Count,
      0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.ToFile_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile1_IWORK.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile1_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile1_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile1_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile2_IWORK.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile2_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile2_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile2_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile3_IWORK.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile3_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile3_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile3_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile4_IWORK.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile4_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile4_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile4_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile5_IWORK.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile5_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile5_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile5_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile6_IWORK.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile6_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile6_IWORK.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile6_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile3_IWORK_g.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile3_IWORK_g.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile3_IWORK_g.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile3_IWORK_g.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile3_IWORK_i.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile3_IWORK_i.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile3_IWORK_i.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile3_IWORK_i.Decimation");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile3_IWORK_d.Count, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile3_IWORK_d.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_custom_DW.ToFile3_IWORK_d.Decimation, 0, 21, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_custom_DW.ToFile3_IWORK_d.Decimation");
    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.Inputtomodel_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.Inputtomodel_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.OutputtoWorkspace_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.OutputtoWorkspace_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_ref_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_ref_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_ref_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_ref_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.sigma_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.sigma_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k1_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k1_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k2_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k2_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k0_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k0_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.nu_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.nu_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.gamma_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.gamma_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.reset_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.reset_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_custom_DW.psi_refdeg_DWORK2, count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_custom_DW.psi_refdeg_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.x_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.x_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.y_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.y_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.psi_m_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.sigma_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.sigma_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k1_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k1_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k2_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k2_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k0_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k0_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.nu_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.nu_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.gamma_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.gamma_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.reset_DWORK2_h,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.reset_DWORK2_h");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.sigma_psi_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.sigma_psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k1_psi_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k1_psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k2_psi_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k2_psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.k0_psi_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.k0_psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.nu_psi_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.nu_psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.gamma_psi_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.gamma_psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.reset_DWORK2_l,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.reset_DWORK2_l");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha1_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha2_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha3_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha4_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha4_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha5_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha5_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.alpha6_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.alpha6_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u1_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u2_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u3_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u4_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u4_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u5_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u5_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.u6_DWORK2, count,
        19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.u6_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Acc_z_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK2,
        count, 19, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_custom_DW.Gyro_z_DWORK2");
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
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE_p), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE_g), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE_n), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator_CSTATE_h), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator2_CSTATE_l), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_custom_X.Integrator1_CSTATE_p), 0,
      contStates[idx++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_custom_DW.Inputtomodel_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.OutputtoWorkspace_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.x_ref_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.y_ref_DWORK1, 0, discStates[idx++],
      0, 0);
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Memory4_PreviousInput, count,
        discStates[idx++], 20, 0);
    }

    NIRT_SetValueByDataType(&ctrl_custom_DW.sigma_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.k1_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.k2_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.k0_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.nu_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.gamma_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.reset_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.psi_refdeg_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.x_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.y_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.psi_m_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.sigma_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.k1_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.k2_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.k0_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.nu_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.gamma_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.reset_DWORK1_k, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.sigma_psi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.k1_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.k2_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.k0_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.nu_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.gamma_psi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.reset_DWORK1_i, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.alpha6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.u6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile1_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile2_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile4_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile5_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile6_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_PWORK_p, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_PWORK_d, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_PWORK_h, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile1_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile1_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile2_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile2_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile4_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile4_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile5_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile5_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile6_IWORK.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile6_IWORK.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_IWORK_g.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_IWORK_g.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_IWORK_i.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_IWORK_i.Decimation, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_IWORK_d.Count, 0,
      discStates[idx++], 21, 0);
    NIRT_SetValueByDataType(&ctrl_custom_DW.ToFile3_IWORK_d.Decimation, 0,
      discStates[idx++], 21, 0);
    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Inputtomodel_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.OutputtoWorkspace_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.x_ref_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.y_ref_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.sigma_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.k1_x_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.k2_x_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.k0_x_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.nu_x_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.gamma_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.reset_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.psi_refdeg_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.x_m_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.y_m_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.psi_m_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.sigma_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.k1_y_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.k2_y_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.k0_y_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.nu_y_DWORK2, count, discStates[idx
        ++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.gamma_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.reset_DWORK2_h, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.sigma_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.k1_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.k2_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.k0_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.nu_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.gamma_psi_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.reset_DWORK2_l, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha1_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha2_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha3_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha4_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha5_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.alpha6_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u1_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u2_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u3_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u4_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u5_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.u6_DWORK2, count, discStates[idx++],
        19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Acc_z_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_x_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_y_DWORK2, count,
        discStates[idx++], 19, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_custom_DW.Gyro_z_DWORK2, count,
        discStates[idx++], 19, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_custom
