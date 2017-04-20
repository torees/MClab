/*
 * ctrl_student.c
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

#include "ctrl_student.h"
#include "ctrl_student_private.h"

/* Block signals (auto storage) */
B_ctrl_student_T ctrl_student_B;

/* Continuous states */
X_ctrl_student_T ctrl_student_X;

/* Block states (auto storage) */
DW_ctrl_student_T ctrl_student_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_student_T ctrl_student_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_student_T ctrl_student_M_;
RT_MODEL_ctrl_student_T *const ctrl_student_M = &ctrl_student_M_;

/* Forward declaration for local functions */
static void ctrl_student_cosd(real_T *x);
static void ctrl_student_sind(real_T *x);

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
  int_T nXc = 25;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_student_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ctrl_student_output();
  ctrl_student_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ctrl_student_output();
  ctrl_student_derivatives();

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
 *    '<S3>/MATLAB Function'
 *    '<S3>/MATLAB Function4'
 */
void ctrl_student_MATLABFunction(real_T rtu_K_p1, real_T rtu_K_p1_n, real_T
  rtu_K_p1_f, B_MATLABFunction_ctrl_student_T *localB)
{
  /* MATLAB Function 'Input/MATLAB Function': '<S12>:1' */
  /* '<S12>:1:4' */
  memset(&localB->K_p[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S12>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_p[0] = rtu_K_p1;
  localB->K_p[4] = rtu_K_p1_n;
  localB->K_p[8] = rtu_K_p1_f;
}

/*
 * Output and update for atomic system:
 *    '<S3>/MATLAB Function1'
 *    '<S3>/MATLAB Function5'
 */
void ctrl_student_MATLABFunction1(real_T rtu_K_i1, real_T rtu_K_i1_j, real_T
  rtu_K_i1_l, B_MATLABFunction1_ctrl_studen_T *localB)
{
  /* MATLAB Function 'Input/MATLAB Function1': '<S13>:1' */
  /* '<S13>:1:4' */
  memset(&localB->K_i[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S13>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_i[0] = rtu_K_i1;
  localB->K_i[4] = rtu_K_i1_j;
  localB->K_i[8] = rtu_K_i1_l;
}

/*
 * Output and update for atomic system:
 *    '<S3>/MATLAB Function2'
 *    '<S3>/MATLAB Function6'
 */
void ctrl_student_MATLABFunction2(real_T rtu_K_d1, real_T rtu_K_d1_p, real_T
  rtu_K_d1_b, B_MATLABFunction2_ctrl_studen_T *localB)
{
  /* MATLAB Function 'Input/MATLAB Function2': '<S14>:1' */
  /* '<S14>:1:4' */
  memset(&localB->K_d[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S14>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_d[0] = rtu_K_d1;
  localB->K_d[4] = rtu_K_d1_p;
  localB->K_d[8] = rtu_K_d1_b;
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

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */
static void ctrl_student_cosd(real_T *x)
{
  int8_T n;
  real_T b_x;
  real_T absx;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    *x = (rtNaN);
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    if (n == 0) {
      *x = cos(b_x);
    } else if (n == 1) {
      *x = -sin(b_x);
    } else if (n == -1) {
      *x = sin(b_x);
    } else {
      *x = -cos(b_x);
    }
  }
}

/* Function for MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */
static void ctrl_student_sind(real_T *x)
{
  int8_T n;
  real_T c_x;
  real_T absx;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    c_x = (rtNaN);
  } else {
    c_x = rt_remd_snf(*x, 360.0);
    absx = fabs(c_x);
    if (absx > 180.0) {
      if (c_x > 0.0) {
        c_x -= 360.0;
      } else {
        c_x += 360.0;
      }

      absx = fabs(c_x);
    }

    if (absx <= 45.0) {
      c_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (c_x > 0.0) {
        c_x = (c_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        c_x = (c_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (c_x > 0.0) {
      c_x = (c_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      c_x = (c_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    if (n == 0) {
      c_x = sin(c_x);
    } else if (n == 1) {
      c_x = cos(c_x);
    } else if (n == -1) {
      c_x = -cos(c_x);
    } else {
      c_x = -sin(c_x);
    }
  }

  *x = c_x;
}

/* Model output function */
void ctrl_student_output(void)
{
  ZCEventType zcEvent;
  real_T offset;
  real_T scale;
  real_T absxk;
  static const real_T a[18] = { -0.375, -0.1752, -0.1276, 0.375, 0.1783, 0.1223,
    0.1251, -0.1818, 0.3831, -0.1251, 0.1719, -0.3668, 0.0027, -0.234, 0.3771,
    -0.0027, -0.2263, 0.3825 };

  real_T i;
  real_T j;
  real_T k;
  real_T l;
  real_T m;
  real_T n;
  real_T o;
  real_T p;
  real_T q;
  real_T r;
  real_T s;
  real_T u;
  real_T v;
  real_T w;
  real_T x;
  real_T y;
  real_T rtb_Gain1[6];
  real_T rtb_Row1;
  real_T rtb_Row3;
  int32_T i_0;
  real_T rtb_Row1_0[18];
  int32_T i_1;
  real_T tmp[4];
  real_T tmp_0[4];
  real_T tmp_1[4];
  real_T tmp_2[4];
  real_T tmp_3[4];
  real_T tmp_4[4];
  real_T tmp_5[4];
  real_T tmp_6[4];
  real_T tmp_7[4];
  real_T tmp_8[4];
  real_T tmp_9[4];
  real_T tmp_a[4];
  real_T tmp_b[4];
  real_T tmp_c[4];
  real_T tmp_d[4];
  real_T tmp_e[4];
  real_T tmp_f[4];
  real_T tmp_g[4];
  real_T tmp_h[3];
  real_T tmp_i[3];
  real_T tmp_j[3];
  real_T tmp_k[4];
  real_T tmp_l[4];
  real_T tmp_m[4];
  real_T tmp_n[4];
  real_T tmp_o[3];
  real_T rtb_TmpSignalConversionAtSFunct;
  real_T rtb_TmpSignalConversionAtSFun_0;
  real_T rtb_eta_w_idx_2;
  if (rtmIsMajorTimeStep(ctrl_student_M)) {
    /* set solver stop time */
    if (!(ctrl_student_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_student_M->solverInfo,
                            ((ctrl_student_M->Timing.clockTickH0 + 1) *
        ctrl_student_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_student_M->solverInfo,
                            ((ctrl_student_M->Timing.clockTick0 + 1) *
        ctrl_student_M->Timing.stepSize0 + ctrl_student_M->Timing.clockTickH0 *
        ctrl_student_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_student_M)) {
    ctrl_student_M->Timing.t[0] = rtsiGetT(&ctrl_student_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_student_M)) {
    /* Gain: '<S1>/Gain1' incorporates:
     *  Constant: '<Root>/constant angle'
     */
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Gain1[i_0] = ctrl_student_P.Gain1_Gain *
        ctrl_student_P.constantangle_Value[i_0];
    }

    /* End of Gain: '<S1>/Gain1' */

    /* Saturate: '<S6>/Saturation 1' */
    if (rtb_Gain1[0] > ctrl_student_P.Saturation1_UpperSat) {
      ctrl_student_B.Saturation1 = ctrl_student_P.Saturation1_UpperSat;
    } else if (rtb_Gain1[0] < ctrl_student_P.Saturation1_LowerSat) {
      ctrl_student_B.Saturation1 = ctrl_student_P.Saturation1_LowerSat;
    } else {
      ctrl_student_B.Saturation1 = rtb_Gain1[0];
    }

    /* End of Saturate: '<S6>/Saturation 1' */
  }

  if (rtmIsMajorTimeStep(ctrl_student_M)) {
    /* Saturate: '<S6>/Saturation 2' */
    if (rtb_Gain1[1] > ctrl_student_P.Saturation2_UpperSat) {
      ctrl_student_B.Saturation2 = ctrl_student_P.Saturation2_UpperSat;
    } else if (rtb_Gain1[1] < ctrl_student_P.Saturation2_LowerSat) {
      ctrl_student_B.Saturation2 = ctrl_student_P.Saturation2_LowerSat;
    } else {
      ctrl_student_B.Saturation2 = rtb_Gain1[1];
    }

    /* End of Saturate: '<S6>/Saturation 2' */

    /* Saturate: '<S6>/Saturation 3' */
    if (rtb_Gain1[2] > ctrl_student_P.Saturation3_UpperSat) {
      ctrl_student_B.Saturation3 = ctrl_student_P.Saturation3_UpperSat;
    } else if (rtb_Gain1[2] < ctrl_student_P.Saturation3_LowerSat) {
      ctrl_student_B.Saturation3 = ctrl_student_P.Saturation3_LowerSat;
    } else {
      ctrl_student_B.Saturation3 = rtb_Gain1[2];
    }

    /* End of Saturate: '<S6>/Saturation 3' */

    /* Saturate: '<S6>/Saturation 4' */
    if (rtb_Gain1[3] > ctrl_student_P.Saturation4_UpperSat) {
      ctrl_student_B.Saturation4 = ctrl_student_P.Saturation4_UpperSat;
    } else if (rtb_Gain1[3] < ctrl_student_P.Saturation4_LowerSat) {
      ctrl_student_B.Saturation4 = ctrl_student_P.Saturation4_LowerSat;
    } else {
      ctrl_student_B.Saturation4 = rtb_Gain1[3];
    }

    /* End of Saturate: '<S6>/Saturation 4' */

    /* Saturate: '<S6>/Saturation 5' */
    if (rtb_Gain1[4] > ctrl_student_P.Saturation5_UpperSat) {
      ctrl_student_B.Saturation5 = ctrl_student_P.Saturation5_UpperSat;
    } else if (rtb_Gain1[4] < ctrl_student_P.Saturation5_LowerSat) {
      ctrl_student_B.Saturation5 = ctrl_student_P.Saturation5_LowerSat;
    } else {
      ctrl_student_B.Saturation5 = rtb_Gain1[4];
    }

    /* End of Saturate: '<S6>/Saturation 5' */

    /* Saturate: '<S6>/Saturation 6' */
    if (rtb_Gain1[5] > ctrl_student_P.Saturation6_UpperSat) {
      ctrl_student_B.Saturation6 = ctrl_student_P.Saturation6_UpperSat;
    } else if (rtb_Gain1[5] < ctrl_student_P.Saturation6_LowerSat) {
      ctrl_student_B.Saturation6 = ctrl_student_P.Saturation6_LowerSat;
    } else {
      ctrl_student_B.Saturation6 = rtb_Gain1[5];
    }

    /* End of Saturate: '<S6>/Saturation 6' */

    /* Delay: '<S22>/Delay' */
    ctrl_student_B.Delay = ctrl_student_DW.Delay_DSTATE;
  }

  if (rtmIsMajorTimeStep(ctrl_student_M)) {
  }

  /* Integrator: '<S21>/Integrator' */
  ctrl_student_B.eta[0] = ctrl_student_X.Integrator_CSTATE[0];
  ctrl_student_B.eta[1] = ctrl_student_X.Integrator_CSTATE[1];
  ctrl_student_B.eta[2] = ctrl_student_X.Integrator_CSTATE[2];

  /* MATLAB Function: '<S22>/MATLAB Function' */
  /* MATLAB Function 'TAPM Controller w_observer/PID/MATLAB Function': '<S36>:1' */
  /* '<S36>:1:9' */
  i_0 = 0;

  /* '<S36>:1:11' */
  rtb_eta_w_idx_2 = sqrt(ctrl_student_B.eta[0] * ctrl_student_B.eta[0] +
    ctrl_student_B.eta[1] * ctrl_student_B.eta[1]);
  if ((rtb_eta_w_idx_2 > ctrl_student_B.r_max) && (ctrl_student_DW.controller !=
       2.0)) {
    /* '<S36>:1:13' */
    /* '<S36>:1:14' */
    ctrl_student_DW.controller = 2.0;

    /* '<S36>:1:15' */
    i_0 = 1;
  } else {
    if ((rtb_eta_w_idx_2 < 0.9 * ctrl_student_B.r_max) && (ctrl_student_B.Delay >
         40.0) && (ctrl_student_DW.controller != 1.0) && (ctrl_student_DW.tmp >
         190.0)) {
      /* '<S36>:1:16' */
      /* '<S36>:1:17' */
      ctrl_student_DW.controller = 1.0;

      /* '<S36>:1:18' */
      i_0 = 1;
    }
  }

  if (rtb_eta_w_idx_2 > ctrl_student_B.r_max) {
    /* '<S36>:1:21' */
    /* '<S36>:1:22' */
    i_0 = 1;

    /* '<S36>:1:23' */
    ctrl_student_DW.tmp = 0.0;
  } else {
    /* '<S36>:1:25' */
    ctrl_student_DW.tmp += 0.01;
  }

  /* '<S36>:1:28' */
  ctrl_student_B.y = ctrl_student_DW.controller;

  /* '<S36>:1:29' */
  ctrl_student_B.reset = i_0;

  /* End of MATLAB Function: '<S22>/MATLAB Function' */

  /* MATLAB Function: '<S3>/MATLAB Function' */
  ctrl_student_MATLABFunction(ctrl_student_B.K_p_x, ctrl_student_B.K_p_y,
    ctrl_student_B.K_p_psi, &ctrl_student_B.sf_MATLABFunction_f);

  /* Saturate: '<S39>/Saturation' incorporates:
   *  Fcn: '<S34>/yaw angle'
   */
  if (ctrl_student_B.eta[2] > ctrl_student_P.Saturation_UpperSat) {
    rtb_Row1 = ctrl_student_P.Saturation_UpperSat;
  } else if (ctrl_student_B.eta[2] < ctrl_student_P.Saturation_LowerSat) {
    rtb_Row1 = ctrl_student_P.Saturation_LowerSat;
  } else {
    rtb_Row1 = ctrl_student_B.eta[2];
  }

  /* End of Saturate: '<S39>/Saturation' */

  /* Signum: '<S39>/Sign' */
  if (rtb_Row1 < 0.0) {
    offset = -1.0;
  } else if (rtb_Row1 > 0.0) {
    offset = 1.0;
  } else if (rtb_Row1 == 0.0) {
    offset = 0.0;
  } else {
    offset = rtb_Row1;
  }

  /* Gain: '<S39>/Gain' incorporates:
   *  Signum: '<S39>/Sign'
   */
  rtb_Row3 = ctrl_student_P.Gain_Gain * offset;

  /* Sum: '<S39>/Sum1' */
  rtb_Row1 += rtb_Row3;

  /* Math: '<S39>/Math Function' incorporates:
   *  Constant: '<S39>/Constant'
   */
  rtb_Row1 = rt_remd_snf(rtb_Row1, ctrl_student_P.Constant_Value);

  /* Sum: '<S39>/Sum' */
  rtb_Row1 -= rtb_Row3;

  /* MATLAB Function: '<S23>/Set-Point Limiter' incorporates:
   *  Integrator: '<S23>/Integrator'
   *  MATLAB Function: '<S3>/MATLAB Function3'
   *  SignalConversion: '<S15>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Input/MATLAB Function3': '<S15>:1' */
  /* '<S15>:1:4' */
  /* MATLAB Function 'TAPM Controller w_observer/SP Generator/Set-Point Limiter': '<S43>:1' */
  /* '<S43>:1:3' */
  /* '<S43>:1:4' */
  scale = 2.2250738585072014E-308;
  rtb_TmpSignalConversionAtSFunct = ctrl_student_X.Integrator_CSTATE_l[0] -
    ctrl_student_B.fzp_x;
  absxk = fabs(rtb_TmpSignalConversionAtSFunct);
  if (absxk > 2.2250738585072014E-308) {
    offset = 1.0;
    scale = absxk;
  } else {
    rtb_eta_w_idx_2 = absxk / 2.2250738585072014E-308;
    offset = rtb_eta_w_idx_2 * rtb_eta_w_idx_2;
  }

  rtb_TmpSignalConversionAtSFun_0 = rtb_TmpSignalConversionAtSFunct;
  rtb_TmpSignalConversionAtSFunct = ctrl_student_X.Integrator_CSTATE_l[1] -
    ctrl_student_B.fzp_y;
  absxk = fabs(rtb_TmpSignalConversionAtSFunct);
  if (absxk > scale) {
    rtb_eta_w_idx_2 = scale / absxk;
    offset = offset * rtb_eta_w_idx_2 * rtb_eta_w_idx_2 + 1.0;
    scale = absxk;
  } else {
    rtb_eta_w_idx_2 = absxk / scale;
    offset += rtb_eta_w_idx_2 * rtb_eta_w_idx_2;
  }

  offset = scale * sqrt(offset);

  /* '<S43>:1:5' */
  /* '<S43>:1:6' */
  /* '<S43>:1:7' */
  rtb_eta_w_idx_2 = rt_powd_snf(offset / ctrl_student_B.r_max, 5.0);
  if (rtb_eta_w_idx_2 > 1.0) {
    /* '<S43>:1:10' */
    /* '<S43>:1:11' */
    rtb_eta_w_idx_2 = 1.0;
  }

  /* TransferFcn: '<S23>/Transfer Fcn2' */
  /* '<S43>:1:14' */
  rtb_Row3 = ctrl_student_P.TransferFcn2_C * ctrl_student_X.TransferFcn2_CSTATE;

  /* Saturate: '<S24>/Saturation' */
  if (rtb_Row3 > ctrl_student_P.Saturation_UpperSat_g) {
    rtb_Row3 = ctrl_student_P.Saturation_UpperSat_g;
  } else {
    if (rtb_Row3 < ctrl_student_P.Saturation_LowerSat_h) {
      rtb_Row3 = ctrl_student_P.Saturation_LowerSat_h;
    }
  }

  /* End of Saturate: '<S24>/Saturation' */

  /* SignalConversion: '<S8>/TmpSignal ConversionAtSPInport1' incorporates:
   *  MATLAB Function: '<S23>/Set-Point Limiter'
   *  MATLAB Function: '<S3>/MATLAB Function3'
   *  SignalConversion: '<S15>/TmpSignal ConversionAt SFunction Inport1'
   */
  ctrl_student_B.TmpSignalConversionAtSPInport1[0] = (ctrl_student_B.fzp_x +
    rtb_TmpSignalConversionAtSFun_0) - (rtb_TmpSignalConversionAtSFun_0 -
    rtb_TmpSignalConversionAtSFun_0 / offset * ctrl_student_B.r_max) *
    rtb_eta_w_idx_2;
  ctrl_student_B.TmpSignalConversionAtSPInport1[1] = (ctrl_student_B.fzp_y +
    rtb_TmpSignalConversionAtSFunct) - (rtb_TmpSignalConversionAtSFunct -
    rtb_TmpSignalConversionAtSFunct / offset * ctrl_student_B.r_max) *
    rtb_eta_w_idx_2;

  /* Signum: '<S24>/Sign' */
  if (rtb_Row3 < 0.0) {
    offset = -1.0;
  } else if (rtb_Row3 > 0.0) {
    offset = 1.0;
  } else if (rtb_Row3 == 0.0) {
    offset = 0.0;
  } else {
    offset = rtb_Row3;
  }

  /* Gain: '<S24>/Gain' incorporates:
   *  Signum: '<S24>/Sign'
   */
  rtb_eta_w_idx_2 = ctrl_student_P.Gain_Gain_p * offset;

  /* Sum: '<S24>/Sum1' */
  rtb_Row3 += rtb_eta_w_idx_2;

  /* Math: '<S24>/Math Function' incorporates:
   *  Constant: '<S24>/Constant'
   */
  rtb_Row3 = rt_remd_snf(rtb_Row3, ctrl_student_P.Constant_Value_k);

  /* Sum: '<S24>/Sum' */
  rtb_Row3 -= rtb_eta_w_idx_2;

  /* SignalConversion: '<S8>/TmpSignal ConversionAtSPInport1' */
  ctrl_student_B.TmpSignalConversionAtSPInport1[2] = rtb_Row3;

  /* Sum: '<S34>/Sum2' */
  scale = ctrl_student_B.TmpSignalConversionAtSPInport1[0] - ctrl_student_B.eta
    [0];
  absxk = ctrl_student_B.TmpSignalConversionAtSPInport1[1] - ctrl_student_B.eta
    [1];
  rtb_eta_w_idx_2 = ctrl_student_B.TmpSignalConversionAtSPInport1[2] -
    ctrl_student_B.eta[2];

  /* Saturate: '<S38>/Saturation' */
  if (rtb_eta_w_idx_2 > ctrl_student_P.Saturation_UpperSat_l) {
    rtb_eta_w_idx_2 = ctrl_student_P.Saturation_UpperSat_l;
  } else {
    if (rtb_eta_w_idx_2 < ctrl_student_P.Saturation_LowerSat_l) {
      rtb_eta_w_idx_2 = ctrl_student_P.Saturation_LowerSat_l;
    }
  }

  /* End of Saturate: '<S38>/Saturation' */

  /* Signum: '<S38>/Sign' */
  if (rtb_eta_w_idx_2 < 0.0) {
    rtb_Row3 = -1.0;
  } else if (rtb_eta_w_idx_2 > 0.0) {
    rtb_Row3 = 1.0;
  } else if (rtb_eta_w_idx_2 == 0.0) {
    rtb_Row3 = 0.0;
  } else {
    rtb_Row3 = rtb_eta_w_idx_2;
  }

  /* Gain: '<S38>/Gain' incorporates:
   *  Signum: '<S38>/Sign'
   */
  rtb_Row3 *= ctrl_student_P.Gain_Gain_l;

  /* Sum: '<S38>/Sum1' */
  rtb_eta_w_idx_2 += rtb_Row3;

  /* Math: '<S38>/Math Function' incorporates:
   *  Constant: '<S38>/Constant'
   */
  rtb_eta_w_idx_2 = rt_remd_snf(rtb_eta_w_idx_2, ctrl_student_P.Constant_Value_e);

  /* Sum: '<S38>/Sum' */
  rtb_eta_w_idx_2 -= rtb_Row3;

  /* SignalConversion: '<S34>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Fcn: '<S37>/Row1'
   *  Fcn: '<S37>/Row2'
   *  Fcn: '<S37>/Row3'
   */
  ctrl_student_B.TmpSignalConversionAtMatrixMult[0] = cos(rtb_Row1) * scale +
    sin(rtb_Row1) * absxk;
  ctrl_student_B.TmpSignalConversionAtMatrixMult[1] = -sin(rtb_Row1) * scale +
    cos(rtb_Row1) * absxk;
  ctrl_student_B.TmpSignalConversionAtMatrixMult[2] = rtb_eta_w_idx_2;

  /* MATLAB Function: '<S3>/MATLAB Function1' */
  ctrl_student_MATLABFunction1(ctrl_student_B.K_i_x, ctrl_student_B.K_i_y,
    ctrl_student_B.K_i_psi, &ctrl_student_B.sf_MATLABFunction1);

  /* MATLAB Function: '<S3>/MATLAB Function2' */
  ctrl_student_MATLABFunction2(ctrl_student_B.K_d_x, ctrl_student_B.K_d_y,
    ctrl_student_B.K_d_psi, &ctrl_student_B.sf_MATLABFunction2);

  /* Integrator: '<S21>/Integrator4' */
  ctrl_student_B.nu[0] = ctrl_student_X.Integrator4_CSTATE[0];
  ctrl_student_B.nu[1] = ctrl_student_X.Integrator4_CSTATE[1];
  ctrl_student_B.nu[2] = ctrl_student_X.Integrator4_CSTATE[2];

  /* MATLAB Function: '<S3>/MATLAB Function4' */
  ctrl_student_MATLABFunction(ctrl_student_B.K_p_x1, ctrl_student_B.K_p_y1,
    ctrl_student_B.K_p_psi1, &ctrl_student_B.sf_MATLABFunction4);

  /* Saturate: '<S42>/Saturation' incorporates:
   *  Fcn: '<S35>/yaw angle'
   */
  if (ctrl_student_B.eta[2] > ctrl_student_P.Saturation_UpperSat_h) {
    offset = ctrl_student_P.Saturation_UpperSat_h;
  } else if (ctrl_student_B.eta[2] < ctrl_student_P.Saturation_LowerSat_d) {
    offset = ctrl_student_P.Saturation_LowerSat_d;
  } else {
    offset = ctrl_student_B.eta[2];
  }

  /* End of Saturate: '<S42>/Saturation' */

  /* Signum: '<S42>/Sign' */
  if (offset < 0.0) {
    rtb_Row1 = -1.0;
  } else if (offset > 0.0) {
    rtb_Row1 = 1.0;
  } else if (offset == 0.0) {
    rtb_Row1 = 0.0;
  } else {
    rtb_Row1 = offset;
  }

  /* Gain: '<S42>/Gain' incorporates:
   *  Signum: '<S42>/Sign'
   */
  rtb_eta_w_idx_2 = ctrl_student_P.Gain_Gain_n * rtb_Row1;

  /* Sum: '<S42>/Sum1' */
  offset += rtb_eta_w_idx_2;

  /* Math: '<S42>/Math Function' incorporates:
   *  Constant: '<S42>/Constant'
   */
  offset = rt_remd_snf(offset, ctrl_student_P.Constant_Value_d);

  /* Sum: '<S42>/Sum' */
  offset -= rtb_eta_w_idx_2;

  /* Sum: '<S35>/Sum2' */
  scale = ctrl_student_B.TmpSignalConversionAtSPInport1[0] - ctrl_student_B.eta
    [0];
  absxk = ctrl_student_B.TmpSignalConversionAtSPInport1[1] - ctrl_student_B.eta
    [1];
  rtb_eta_w_idx_2 = ctrl_student_B.TmpSignalConversionAtSPInport1[2] -
    ctrl_student_B.eta[2];

  /* Saturate: '<S41>/Saturation' */
  if (rtb_eta_w_idx_2 > ctrl_student_P.Saturation_UpperSat_a) {
    rtb_eta_w_idx_2 = ctrl_student_P.Saturation_UpperSat_a;
  } else {
    if (rtb_eta_w_idx_2 < ctrl_student_P.Saturation_LowerSat_lh) {
      rtb_eta_w_idx_2 = ctrl_student_P.Saturation_LowerSat_lh;
    }
  }

  /* End of Saturate: '<S41>/Saturation' */

  /* Signum: '<S41>/Sign' */
  if (rtb_eta_w_idx_2 < 0.0) {
    rtb_Row3 = -1.0;
  } else if (rtb_eta_w_idx_2 > 0.0) {
    rtb_Row3 = 1.0;
  } else if (rtb_eta_w_idx_2 == 0.0) {
    rtb_Row3 = 0.0;
  } else {
    rtb_Row3 = rtb_eta_w_idx_2;
  }

  /* Gain: '<S41>/Gain' incorporates:
   *  Signum: '<S41>/Sign'
   */
  rtb_Row3 *= ctrl_student_P.Gain_Gain_j;

  /* Sum: '<S41>/Sum1' */
  rtb_eta_w_idx_2 += rtb_Row3;

  /* Math: '<S41>/Math Function' incorporates:
   *  Constant: '<S41>/Constant'
   */
  rtb_eta_w_idx_2 = rt_remd_snf(rtb_eta_w_idx_2, ctrl_student_P.Constant_Value_c);

  /* Sum: '<S41>/Sum' */
  rtb_eta_w_idx_2 -= rtb_Row3;

  /* SignalConversion: '<S35>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Fcn: '<S40>/Row1'
   *  Fcn: '<S40>/Row2'
   *  Fcn: '<S40>/Row3'
   */
  ctrl_student_B.TmpSignalConversionAtMatrixMu_b[0] = cos(offset) * scale + sin
    (offset) * absxk;
  ctrl_student_B.TmpSignalConversionAtMatrixMu_b[1] = -sin(offset) * scale + cos
    (offset) * absxk;
  ctrl_student_B.TmpSignalConversionAtMatrixMu_b[2] = rtb_eta_w_idx_2;

  /* MATLAB Function: '<S3>/MATLAB Function5' */
  ctrl_student_MATLABFunction1(ctrl_student_B.K_i_x1, ctrl_student_B.K_i_y1,
    ctrl_student_B.K_i_psi1, &ctrl_student_B.sf_MATLABFunction5);

  /* MATLAB Function: '<S3>/MATLAB Function6' */
  ctrl_student_MATLABFunction2(ctrl_student_B.K_d_x1, ctrl_student_B.K_d_y1,
    ctrl_student_B.K_d_psi1, &ctrl_student_B.sf_MATLABFunction6);

  /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
   *  Integrator: '<S34>/Integrator'
   *  Integrator: '<S35>/Integrator'
   *  Product: '<S34>/Matrix Multiply'
   *  Product: '<S34>/Matrix Multiply1'
   *  Product: '<S34>/Matrix Multiply2'
   *  Product: '<S35>/Matrix Multiply'
   *  Product: '<S35>/Matrix Multiply1'
   *  Product: '<S35>/Matrix Multiply2'
   *  Sum: '<S34>/Sum1'
   *  Sum: '<S34>/Sum3'
   *  Sum: '<S35>/Sum1'
   *  Sum: '<S35>/Sum3'
   */
  if ((int32_T)ctrl_student_B.y == 1) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      ctrl_student_B.MultiportSwitch[i_0] =
        ((ctrl_student_B.sf_MATLABFunction_f.K_p[i_0 + 6] *
          ctrl_student_B.TmpSignalConversionAtMatrixMult[2] +
          (ctrl_student_B.sf_MATLABFunction_f.K_p[i_0 + 3] *
           ctrl_student_B.TmpSignalConversionAtMatrixMult[1] +
           ctrl_student_B.sf_MATLABFunction_f.K_p[i_0] *
           ctrl_student_B.TmpSignalConversionAtMatrixMult[0])) +
         (ctrl_student_B.sf_MATLABFunction1.K_i[i_0 + 6] *
          ctrl_student_X.Integrator_CSTATE_g[2] +
          (ctrl_student_B.sf_MATLABFunction1.K_i[i_0 + 3] *
           ctrl_student_X.Integrator_CSTATE_g[1] +
           ctrl_student_B.sf_MATLABFunction1.K_i[i_0] *
           ctrl_student_X.Integrator_CSTATE_g[0]))) -
        ((ctrl_student_B.sf_MATLABFunction2.K_d[i_0 + 3] * ctrl_student_B.nu[1]
          + ctrl_student_B.sf_MATLABFunction2.K_d[i_0] * ctrl_student_B.nu[0]) +
         ctrl_student_B.sf_MATLABFunction2.K_d[i_0 + 6] * ctrl_student_B.nu[2]);
    }
  } else {
    for (i_0 = 0; i_0 < 3; i_0++) {
      ctrl_student_B.MultiportSwitch[i_0] =
        ((ctrl_student_B.sf_MATLABFunction4.K_p[i_0 + 6] *
          ctrl_student_B.TmpSignalConversionAtMatrixMu_b[2] +
          (ctrl_student_B.sf_MATLABFunction4.K_p[i_0 + 3] *
           ctrl_student_B.TmpSignalConversionAtMatrixMu_b[1] +
           ctrl_student_B.sf_MATLABFunction4.K_p[i_0] *
           ctrl_student_B.TmpSignalConversionAtMatrixMu_b[0])) +
         (ctrl_student_B.sf_MATLABFunction5.K_i[i_0 + 6] *
          ctrl_student_X.Integrator_CSTATE_k[2] +
          (ctrl_student_B.sf_MATLABFunction5.K_i[i_0 + 3] *
           ctrl_student_X.Integrator_CSTATE_k[1] +
           ctrl_student_B.sf_MATLABFunction5.K_i[i_0] *
           ctrl_student_X.Integrator_CSTATE_k[0]))) -
        ((ctrl_student_B.sf_MATLABFunction6.K_d[i_0 + 3] * ctrl_student_B.nu[1]
          + ctrl_student_B.sf_MATLABFunction6.K_d[i_0] * ctrl_student_B.nu[0]) +
         ctrl_student_B.sf_MATLABFunction6.K_d[i_0 + 6] * ctrl_student_B.nu[2]);
    }
  }

  /* End of MultiPortSwitch: '<S22>/Multiport Switch' */
  /* MATLAB Function 'TA fixed thrusters, pseudoinverse/MATLAB Function': '<S19>:1' */
  /* '<S19>:1:31' */
  /*  Pseudoinverse thrust allocation for fixed angles */
  /*  no thruster-thruster interaction */
  /*  Thruster configuration matrix */
  /*  number of thrusters */
  /*  Shells for faster computing */
  /* '<S19>:1:13' */
  /*  pseudoinverse */
  /*  Bpinv = pinv(B); */
  /* '<S19>:1:31' */
  for (i_0 = 0; i_0 < 6; i_0++) {
    /* Product: '<Root>/Product' incorporates:
     *  MATLAB Function: '<S7>/MATLAB Function'
     */
    ctrl_student_B.Product[i_0] = (a[i_0 + 12] * ctrl_student_B.MultiportSwitch
      [2] + (a[i_0 + 6] * ctrl_student_B.MultiportSwitch[1] + a[i_0] *
             ctrl_student_B.MultiportSwitch[0])) * ctrl_student_B.EnableThrust;
  }

  if (rtmIsMajorTimeStep(ctrl_student_M)) {
    /* Gain: '<S5>/Gain' */
    ctrl_student_B.Gain[0] = ctrl_student_P.Gain_Gain_f *
      ctrl_student_B.Saturation1;
    ctrl_student_B.Gain[1] = ctrl_student_P.Gain_Gain_f *
      ctrl_student_B.Saturation2;
    ctrl_student_B.Gain[2] = ctrl_student_P.Gain_Gain_f *
      ctrl_student_B.Saturation3;
    ctrl_student_B.Gain[3] = ctrl_student_P.Gain_Gain_f *
      ctrl_student_B.Saturation4;
    ctrl_student_B.Gain[4] = ctrl_student_P.Gain_Gain_f *
      ctrl_student_B.Saturation5;
    ctrl_student_B.Gain[5] = ctrl_student_P.Gain_Gain_f *
      ctrl_student_B.Saturation6;
  }

  /* MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' incorporates:
   *  Constant: '<Root>/X-position Thruster'
   *  Constant: '<Root>/Y-position Thruster'
   */
  /* MATLAB Function 'Finding commanded forces in: [Surge,Sway,Yaw]': '<S2>:1' */
  /* '<S2>:1:4' */
  /* '<S2>:1:5' */
  /* '<S2>:1:6' */
  /* '<S2>:1:10' */
  rtb_Row1 = ctrl_student_B.Gain[0];
  ctrl_student_cosd(&rtb_Row1);
  rtb_Row3 = ctrl_student_B.Gain[1];
  ctrl_student_cosd(&rtb_Row3);
  offset = ctrl_student_B.Gain[2];
  ctrl_student_cosd(&offset);
  scale = ctrl_student_B.Gain[3];
  ctrl_student_cosd(&scale);
  absxk = ctrl_student_B.Gain[4];
  ctrl_student_cosd(&absxk);
  rtb_TmpSignalConversionAtSFunct = ctrl_student_B.Gain[5];
  ctrl_student_cosd(&rtb_TmpSignalConversionAtSFunct);
  rtb_TmpSignalConversionAtSFun_0 = ctrl_student_B.Gain[0];
  ctrl_student_sind(&rtb_TmpSignalConversionAtSFun_0);
  i = ctrl_student_B.Gain[1];
  ctrl_student_sind(&i);
  j = ctrl_student_B.Gain[2];
  ctrl_student_sind(&j);
  k = ctrl_student_B.Gain[3];
  ctrl_student_sind(&k);
  l = ctrl_student_B.Gain[4];
  ctrl_student_sind(&l);
  m = ctrl_student_B.Gain[5];
  ctrl_student_sind(&m);
  n = ctrl_student_B.Gain[0];
  ctrl_student_sind(&n);
  o = ctrl_student_B.Gain[0];
  ctrl_student_cosd(&o);
  p = ctrl_student_B.Gain[1];
  ctrl_student_sind(&p);
  q = ctrl_student_B.Gain[1];
  ctrl_student_cosd(&q);
  r = ctrl_student_B.Gain[2];
  ctrl_student_sind(&r);
  s = ctrl_student_B.Gain[2];
  ctrl_student_cosd(&s);
  rtb_eta_w_idx_2 = ctrl_student_B.Gain[3];
  ctrl_student_sind(&rtb_eta_w_idx_2);
  u = ctrl_student_B.Gain[3];
  ctrl_student_cosd(&u);
  v = ctrl_student_B.Gain[4];
  ctrl_student_sind(&v);
  w = ctrl_student_B.Gain[4];
  ctrl_student_cosd(&w);
  x = ctrl_student_B.Gain[5];
  ctrl_student_sind(&x);
  y = ctrl_student_B.Gain[5];
  ctrl_student_cosd(&y);
  rtb_Row1_0[0] = rtb_Row1;
  rtb_Row1_0[3] = rtb_Row3;
  rtb_Row1_0[6] = offset;
  rtb_Row1_0[9] = scale;
  rtb_Row1_0[12] = absxk;
  rtb_Row1_0[15] = rtb_TmpSignalConversionAtSFunct;
  rtb_Row1_0[1] = rtb_TmpSignalConversionAtSFun_0;
  rtb_Row1_0[4] = i;
  rtb_Row1_0[7] = j;
  rtb_Row1_0[10] = k;
  rtb_Row1_0[13] = l;
  rtb_Row1_0[16] = m;
  rtb_Row1_0[2] = n * ctrl_student_P.XpositionThruster_Value_e[0] - o *
    ctrl_student_P.YpositionThruster_Value_o[0];
  rtb_Row1_0[5] = p * ctrl_student_P.XpositionThruster_Value_e[1] - q *
    ctrl_student_P.YpositionThruster_Value_o[1];
  rtb_Row1_0[8] = r * ctrl_student_P.XpositionThruster_Value_e[2] - s *
    ctrl_student_P.YpositionThruster_Value_o[2];
  rtb_Row1_0[11] = rtb_eta_w_idx_2 * ctrl_student_P.XpositionThruster_Value_e[3]
    - u * ctrl_student_P.YpositionThruster_Value_o[3];
  rtb_Row1_0[14] = v * ctrl_student_P.XpositionThruster_Value_e[4] - w *
    ctrl_student_P.YpositionThruster_Value_o[4];
  rtb_Row1_0[17] = x * ctrl_student_P.XpositionThruster_Value_e[5] - y *
    ctrl_student_P.YpositionThruster_Value_o[5];
  for (i_0 = 0; i_0 < 3; i_0++) {
    ctrl_student_B.commanded_tau[i_0] = 0.0;
    for (i_1 = 0; i_1 < 6; i_1++) {
      ctrl_student_B.commanded_tau[i_0] += rtb_Row1_0[3 * i_1 + i_0] *
        ctrl_student_B.Product[i_1];
    }
  }

  /* End of MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */

  /* Sum: '<S21>/Sum2' incorporates:
   *  Integrator: '<S21>/Integrator1'
   *  Sum: '<S21>/Sum4'
   */
  scale = ctrl_student_B.x_m - (ctrl_student_X.Integrator1_CSTATE[0] +
    ctrl_student_B.eta[0]);
  absxk = ctrl_student_B.y_m - (ctrl_student_X.Integrator1_CSTATE[1] +
    ctrl_student_B.eta[1]);
  rtb_eta_w_idx_2 = ctrl_student_B.psi_m - (ctrl_student_X.Integrator1_CSTATE[2]
    + ctrl_student_B.eta[2]);

  /* Fcn: '<S32>/Row1' */
  tmp[0] = ctrl_student_B.psi_m;
  tmp_1[0] = ctrl_student_B.psi_m;

  /* Fcn: '<S32>/Row2' */
  tmp_3[0] = ctrl_student_B.psi_m;
  tmp_5[0] = ctrl_student_B.psi_m;

  /* Fcn: '<S33>/Row1' */
  tmp_8[0] = ctrl_student_B.psi_m;
  tmp_a[0] = ctrl_student_B.psi_m;

  /* Fcn: '<S33>/Row2' */
  tmp_c[0] = ctrl_student_B.psi_m;
  tmp_e[0] = ctrl_student_B.psi_m;
  for (i_0 = 0; i_0 < 3; i_0++) {
    /* Gain: '<S21>/K4' */
    rtb_Row1 = ctrl_student_P.Nonlinearpassiveobserver_K4[i_0 + 6] *
      rtb_eta_w_idx_2 + (ctrl_student_P.Nonlinearpassiveobserver_K4[i_0 + 3] *
                         absxk + ctrl_student_P.Nonlinearpassiveobserver_K4[i_0]
                         * scale);

    /* Fcn: '<S32>/Row1' */
    tmp[i_0 + 1] = rtb_Row1;
    tmp_0[i_0 + 1] = rtb_Row1;
    tmp_1[i_0 + 1] = rtb_Row1;
    tmp_2[i_0 + 1] = rtb_Row1;

    /* Fcn: '<S32>/Row2' */
    tmp_3[i_0 + 1] = rtb_Row1;
    tmp_4[i_0 + 1] = rtb_Row1;
    tmp_5[i_0 + 1] = rtb_Row1;
    tmp_6[i_0 + 1] = rtb_Row1;

    /* Fcn: '<S32>/Row3' */
    tmp_7[i_0 + 1] = rtb_Row1;

    /* Fcn: '<S33>/Row1' incorporates:
     *  Integrator: '<S21>/Integrator3'
     */
    tmp_8[i_0 + 1] = ctrl_student_X.Integrator3_CSTATE[i_0];
    tmp_9[i_0 + 1] = ctrl_student_X.Integrator3_CSTATE[i_0];
    tmp_a[i_0 + 1] = ctrl_student_X.Integrator3_CSTATE[i_0];
    tmp_b[i_0 + 1] = ctrl_student_X.Integrator3_CSTATE[i_0];

    /* Fcn: '<S33>/Row2' incorporates:
     *  Integrator: '<S21>/Integrator3'
     */
    tmp_c[i_0 + 1] = ctrl_student_X.Integrator3_CSTATE[i_0];
    tmp_d[i_0 + 1] = ctrl_student_X.Integrator3_CSTATE[i_0];
    tmp_e[i_0 + 1] = ctrl_student_X.Integrator3_CSTATE[i_0];
    tmp_f[i_0 + 1] = ctrl_student_X.Integrator3_CSTATE[i_0];

    /* Fcn: '<S33>/Row3' incorporates:
     *  Integrator: '<S21>/Integrator3'
     */
    tmp_g[i_0 + 1] = ctrl_student_X.Integrator3_CSTATE[i_0];
  }

  /* Sum: '<S21>/Sum1' incorporates:
   *  Fcn: '<S33>/Row1'
   *  Fcn: '<S33>/Row2'
   *  Fcn: '<S33>/Row3'
   */
  tmp_h[0] = cos(tmp_8[0]) * tmp_9[1] + sin(tmp_a[0]) * tmp_b[2];
  tmp_h[1] = -sin(tmp_c[0]) * tmp_d[1] + cos(tmp_e[0]) * tmp_f[2];
  tmp_h[2] = tmp_g[3];

  /* Sum: '<S21>/Sum8' incorporates:
   *  Fcn: '<S32>/Row1'
   *  Fcn: '<S32>/Row2'
   *  Fcn: '<S32>/Row3'
   *  Gain: '<S21>/Gain3'
   *  Gain: '<S21>/Gain6'
   *  Sum: '<S21>/Sum1'
   */
  tmp_i[0] = cos(tmp[0]) * tmp_0[1] + sin(tmp_1[0]) * tmp_2[2];
  tmp_i[1] = -sin(tmp_3[0]) * tmp_4[1] + cos(tmp_5[0]) * tmp_6[2];
  tmp_i[2] = tmp_7[3];
  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_j[i_0] = ((tmp_h[i_0] + ctrl_student_B.commanded_tau[i_0]) + tmp_i[i_0])
      - ((ctrl_student_P.Nonlinearpassiveobserver_D[i_0 + 3] *
          ctrl_student_B.nu[1] + ctrl_student_P.Nonlinearpassiveobserver_D[i_0] *
          ctrl_student_B.nu[0]) + ctrl_student_P.Nonlinearpassiveobserver_D[i_0
         + 6] * ctrl_student_B.nu[2]);
  }

  /* End of Sum: '<S21>/Sum8' */

  /* Fcn: '<S31>/Fcn' */
  tmp_k[0] = ctrl_student_B.psi_m;
  tmp_l[0] = ctrl_student_B.psi_m;

  /* Fcn: '<S31>/Fcn1' */
  tmp_m[0] = ctrl_student_B.psi_m;
  tmp_n[0] = ctrl_student_B.psi_m;
  for (i_0 = 0; i_0 < 3; i_0++) {
    /* Gain: '<S21>/Gain3' */
    ctrl_student_B.Gain3[i_0] = 0.0;
    ctrl_student_B.Gain3[i_0] += ctrl_student_P.Gain3_Gain[i_0] * tmp_j[0];
    ctrl_student_B.Gain3[i_0] += ctrl_student_P.Gain3_Gain[i_0 + 3] * tmp_j[1];
    ctrl_student_B.Gain3[i_0] += ctrl_student_P.Gain3_Gain[i_0 + 6] * tmp_j[2];

    /* Fcn: '<S31>/Fcn' */
    tmp_k[i_0 + 1] = ctrl_student_B.nu[i_0];
    tmp[i_0 + 1] = ctrl_student_B.nu[i_0];
    tmp_l[i_0 + 1] = ctrl_student_B.nu[i_0];
    tmp_0[i_0 + 1] = ctrl_student_B.nu[i_0];

    /* Fcn: '<S31>/Fcn1' */
    tmp_m[i_0 + 1] = ctrl_student_B.nu[i_0];
    tmp_1[i_0 + 1] = ctrl_student_B.nu[i_0];
    tmp_n[i_0 + 1] = ctrl_student_B.nu[i_0];
    tmp_2[i_0 + 1] = ctrl_student_B.nu[i_0];

    /* Fcn: '<S31>/Fcn2' */
    tmp_3[i_0 + 1] = ctrl_student_B.nu[i_0];
  }

  /* Sum: '<S21>/Sum3' incorporates:
   *  Fcn: '<S31>/Fcn'
   *  Fcn: '<S31>/Fcn1'
   *  Fcn: '<S31>/Fcn2'
   *  Gain: '<S21>/K2'
   */
  tmp_o[0] = cos(tmp_k[0]) * tmp[1] - sin(tmp_l[0]) * tmp_0[2];
  tmp_o[1] = sin(tmp_m[0]) * tmp_1[1] + cos(tmp_n[0]) * tmp_2[2];
  tmp_o[2] = tmp_3[3];
  for (i_0 = 0; i_0 < 3; i_0++) {
    ctrl_student_B.Sum3[i_0] = ((ctrl_student_P.Nonlinearpassiveobserver_w_c[i_0
      + 3] * absxk + ctrl_student_P.Nonlinearpassiveobserver_w_c[i_0] * scale) +
      ctrl_student_P.Nonlinearpassiveobserver_w_c[i_0 + 6] * rtb_eta_w_idx_2) +
      tmp_o[i_0];

    /* Sum: '<S21>/Sum5' incorporates:
     *  Gain: '<S21>/K11'
     *  Gain: '<S21>/K2'
     *  Integrator: '<S21>/Integrator1'
     */
    ctrl_student_B.psi_WF[i_0] = ((ctrl_student_P.K11_Gain[i_0 + 3] * absxk +
      ctrl_student_P.K11_Gain[i_0] * scale) + ctrl_student_P.K11_Gain[i_0 + 6] *
      rtb_eta_w_idx_2) + ctrl_student_X.Integrator1_CSTATE[i_0];

    /* Sum: '<S21>/Sum6' incorporates:
     *  Gain: '<S21>/Gain1'
     *  Gain: '<S21>/Gain2'
     *  Gain: '<S21>/K12'
     *  Integrator: '<S21>/Integrator1'
     *  Integrator: '<S21>/Integrator2'
     */
    ctrl_student_B.Sum6[i_0] = ((ctrl_student_P.K12_Gain[i_0 + 6] *
      rtb_eta_w_idx_2 + (ctrl_student_P.K12_Gain[i_0 + 3] * absxk +
                         ctrl_student_P.K12_Gain[i_0] * scale)) -
      (ctrl_student_P.Gain2_Gain[i_0 + 6] * ctrl_student_X.Integrator2_CSTATE[2]
       + (ctrl_student_P.Gain2_Gain[i_0 + 3] *
          ctrl_student_X.Integrator2_CSTATE[1] + ctrl_student_P.Gain2_Gain[i_0] *
          ctrl_student_X.Integrator2_CSTATE[0]))) -
      ((ctrl_student_P.Gain1_Gain_i[i_0 + 3] *
        ctrl_student_X.Integrator1_CSTATE[1] + ctrl_student_P.Gain1_Gain_i[i_0] *
        ctrl_student_X.Integrator1_CSTATE[0]) + ctrl_student_P.Gain1_Gain_i[i_0
       + 6] * ctrl_student_X.Integrator1_CSTATE[2]);

    /* Sum: '<S21>/Sum7' incorporates:
     *  Gain: '<S21>/K3'
     *  Gain: '<S21>/inv(T_b)'
     *  Integrator: '<S21>/Integrator3'
     */
    ctrl_student_B.Sum7[i_0] = ((ctrl_student_P.Nonlinearpassiveobserver_K3[i_0
      + 3] * absxk + ctrl_student_P.Nonlinearpassiveobserver_K3[i_0] * scale) +
      ctrl_student_P.Nonlinearpassiveobserver_K3[i_0 + 6] * rtb_eta_w_idx_2) -
      (ctrl_student_P.invT_b_Gain[i_0 + 6] * ctrl_student_X.Integrator3_CSTATE[2]
       + (ctrl_student_P.invT_b_Gain[i_0 + 3] *
          ctrl_student_X.Integrator3_CSTATE[1] + ctrl_student_P.invT_b_Gain[i_0]
          * ctrl_student_X.Integrator3_CSTATE[0]));
  }

  /* End of Sum: '<S21>/Sum3' */
  if (rtmIsMajorTimeStep(ctrl_student_M)) {
  }

  /* Integrator: '<S22>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_student_M)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_student_PrevZCX.Integrator_Reset_ZCE,
                       (ctrl_student_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_student_X.Integrator_CSTATE_d = ctrl_student_P.Integrator_IC_d;
    }
  }

  ctrl_student_B.Integrator = ctrl_student_X.Integrator_CSTATE_d;

  /* End of Integrator: '<S22>/Integrator' */

  /* Sum: '<S23>/Sum' incorporates:
   *  Constant: '<S23>/Constant1'
   *  Gain: '<S3>/deg2rad'
   */
  ctrl_student_B.Sum = ctrl_student_P.deg2rad_Gain * ctrl_student_B.wave_dir +
    ctrl_student_P.Constant1_Value_p;

  /* Sum: '<S23>/Sum1' incorporates:
   *  Gain: '<S23>/Gain'
   *  Gain: '<S23>/Gain1'
   *  Integrator: '<S23>/Integrator'
   */
  ctrl_student_B.Sum1[0] = (ctrl_student_P.Gain1_Gain_ib[0] *
    ctrl_student_B.eta[0] + ctrl_student_P.Gain1_Gain_ib[2] *
    ctrl_student_B.eta[1]) - (ctrl_student_P.Gain_Gain_d[0] *
    ctrl_student_X.Integrator_CSTATE_l[0] + ctrl_student_P.Gain_Gain_d[2] *
    ctrl_student_X.Integrator_CSTATE_l[1]);
  ctrl_student_B.Sum1[1] = (ctrl_student_P.Gain1_Gain_ib[1] *
    ctrl_student_B.eta[0] + ctrl_student_P.Gain1_Gain_ib[3] *
    ctrl_student_B.eta[1]) - (ctrl_student_P.Gain_Gain_d[1] *
    ctrl_student_X.Integrator_CSTATE_l[0] + ctrl_student_P.Gain_Gain_d[3] *
    ctrl_student_X.Integrator_CSTATE_l[1]);
}

/* Model update function */
void ctrl_student_update(void)
{
  if (rtmIsMajorTimeStep(ctrl_student_M)) {
    /* Update for Delay: '<S22>/Delay' */
    ctrl_student_DW.Delay_DSTATE = ctrl_student_B.Integrator;
  }

  if (rtmIsMajorTimeStep(ctrl_student_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_student_M->solverInfo);
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
  if (!(++ctrl_student_M->Timing.clockTick0)) {
    ++ctrl_student_M->Timing.clockTickH0;
  }

  ctrl_student_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ctrl_student_M->solverInfo);

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
    if (!(++ctrl_student_M->Timing.clockTick1)) {
      ++ctrl_student_M->Timing.clockTickH1;
    }

    ctrl_student_M->Timing.t[1] = ctrl_student_M->Timing.clockTick1 *
      ctrl_student_M->Timing.stepSize1 + ctrl_student_M->Timing.clockTickH1 *
      ctrl_student_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_student_derivatives(void)
{
  XDot_ctrl_student_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_student_T *) ctrl_student_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S21>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_student_B.Sum3[0];
  _rtXdot->Integrator_CSTATE[1] = ctrl_student_B.Sum3[1];
  _rtXdot->Integrator_CSTATE[2] = ctrl_student_B.Sum3[2];

  /* Derivatives for Integrator: '<S23>/Integrator' */
  _rtXdot->Integrator_CSTATE_l[0] = ctrl_student_B.Sum1[0];
  _rtXdot->Integrator_CSTATE_l[1] = ctrl_student_B.Sum1[1];

  /* Derivatives for TransferFcn: '<S23>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += ctrl_student_P.TransferFcn2_A *
    ctrl_student_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += ctrl_student_B.Sum;

  /* Derivatives for Integrator: '<S34>/Integrator' */
  _rtXdot->Integrator_CSTATE_g[0] =
    ctrl_student_B.TmpSignalConversionAtMatrixMult[0];

  /* Derivatives for Integrator: '<S21>/Integrator4' */
  _rtXdot->Integrator4_CSTATE[0] = ctrl_student_B.Gain3[0];

  /* Derivatives for Integrator: '<S35>/Integrator' */
  _rtXdot->Integrator_CSTATE_k[0] =
    ctrl_student_B.TmpSignalConversionAtMatrixMu_b[0];

  /* Derivatives for Integrator: '<S21>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ctrl_student_B.Sum6[0];

  /* Derivatives for Integrator: '<S21>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_student_B.psi_WF[0];

  /* Derivatives for Integrator: '<S21>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[0] = ctrl_student_B.Sum7[0];

  /* Derivatives for Integrator: '<S34>/Integrator' */
  _rtXdot->Integrator_CSTATE_g[1] =
    ctrl_student_B.TmpSignalConversionAtMatrixMult[1];

  /* Derivatives for Integrator: '<S21>/Integrator4' */
  _rtXdot->Integrator4_CSTATE[1] = ctrl_student_B.Gain3[1];

  /* Derivatives for Integrator: '<S35>/Integrator' */
  _rtXdot->Integrator_CSTATE_k[1] =
    ctrl_student_B.TmpSignalConversionAtMatrixMu_b[1];

  /* Derivatives for Integrator: '<S21>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = ctrl_student_B.Sum6[1];

  /* Derivatives for Integrator: '<S21>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[1] = ctrl_student_B.psi_WF[1];

  /* Derivatives for Integrator: '<S21>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[1] = ctrl_student_B.Sum7[1];

  /* Derivatives for Integrator: '<S34>/Integrator' */
  _rtXdot->Integrator_CSTATE_g[2] =
    ctrl_student_B.TmpSignalConversionAtMatrixMult[2];

  /* Derivatives for Integrator: '<S21>/Integrator4' */
  _rtXdot->Integrator4_CSTATE[2] = ctrl_student_B.Gain3[2];

  /* Derivatives for Integrator: '<S35>/Integrator' */
  _rtXdot->Integrator_CSTATE_k[2] =
    ctrl_student_B.TmpSignalConversionAtMatrixMu_b[2];

  /* Derivatives for Integrator: '<S21>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[2] = ctrl_student_B.Sum6[2];

  /* Derivatives for Integrator: '<S21>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[2] = ctrl_student_B.psi_WF[2];

  /* Derivatives for Integrator: '<S21>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[2] = ctrl_student_B.Sum7[2];

  /* Derivatives for Integrator: '<S22>/Integrator' incorporates:
   *  Constant: '<S22>/Constant'
   */
  _rtXdot->Integrator_CSTATE_d = ctrl_student_P.Constant_Value_o;
}

/* Model initialize function */
void ctrl_student_initialize(void)
{
  ctrl_student_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Delay: '<S22>/Delay' */
  ctrl_student_DW.Delay_DSTATE = ctrl_student_P.Delay_InitialCondition;

  /* InitializeConditions for Integrator: '<S21>/Integrator' */
  ctrl_student_X.Integrator_CSTATE[0] = ctrl_student_P.Integrator_IC[0];
  ctrl_student_X.Integrator_CSTATE[1] = ctrl_student_P.Integrator_IC[1];
  ctrl_student_X.Integrator_CSTATE[2] = ctrl_student_P.Integrator_IC[2];

  /* InitializeConditions for Integrator: '<S23>/Integrator' */
  ctrl_student_X.Integrator_CSTATE_l[0] = ctrl_student_P.Integrator_IC_b[0];
  ctrl_student_X.Integrator_CSTATE_l[1] = ctrl_student_P.Integrator_IC_b[1];

  /* InitializeConditions for TransferFcn: '<S23>/Transfer Fcn2' */
  ctrl_student_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S34>/Integrator' */
  ctrl_student_X.Integrator_CSTATE_g[0] = ctrl_student_P.Integrator_IC_f;

  /* InitializeConditions for Integrator: '<S21>/Integrator4' */
  ctrl_student_X.Integrator4_CSTATE[0] = ctrl_student_P.Integrator4_IC[0];

  /* InitializeConditions for Integrator: '<S35>/Integrator' */
  ctrl_student_X.Integrator_CSTATE_k[0] = ctrl_student_P.Integrator_IC_p;

  /* InitializeConditions for Integrator: '<S21>/Integrator1' */
  ctrl_student_X.Integrator1_CSTATE[0] = ctrl_student_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S21>/Integrator2' */
  ctrl_student_X.Integrator2_CSTATE[0] = ctrl_student_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S21>/Integrator3' */
  ctrl_student_X.Integrator3_CSTATE[0] = ctrl_student_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S34>/Integrator' */
  ctrl_student_X.Integrator_CSTATE_g[1] = ctrl_student_P.Integrator_IC_f;

  /* InitializeConditions for Integrator: '<S21>/Integrator4' */
  ctrl_student_X.Integrator4_CSTATE[1] = ctrl_student_P.Integrator4_IC[1];

  /* InitializeConditions for Integrator: '<S35>/Integrator' */
  ctrl_student_X.Integrator_CSTATE_k[1] = ctrl_student_P.Integrator_IC_p;

  /* InitializeConditions for Integrator: '<S21>/Integrator1' */
  ctrl_student_X.Integrator1_CSTATE[1] = ctrl_student_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S21>/Integrator2' */
  ctrl_student_X.Integrator2_CSTATE[1] = ctrl_student_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S21>/Integrator3' */
  ctrl_student_X.Integrator3_CSTATE[1] = ctrl_student_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S34>/Integrator' */
  ctrl_student_X.Integrator_CSTATE_g[2] = ctrl_student_P.Integrator_IC_f;

  /* InitializeConditions for Integrator: '<S21>/Integrator4' */
  ctrl_student_X.Integrator4_CSTATE[2] = ctrl_student_P.Integrator4_IC[2];

  /* InitializeConditions for Integrator: '<S35>/Integrator' */
  ctrl_student_X.Integrator_CSTATE_k[2] = ctrl_student_P.Integrator_IC_p;

  /* InitializeConditions for Integrator: '<S21>/Integrator1' */
  ctrl_student_X.Integrator1_CSTATE[2] = ctrl_student_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S21>/Integrator2' */
  ctrl_student_X.Integrator2_CSTATE[2] = ctrl_student_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S21>/Integrator3' */
  ctrl_student_X.Integrator3_CSTATE[2] = ctrl_student_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S22>/Integrator' */
  ctrl_student_X.Integrator_CSTATE_d = ctrl_student_P.Integrator_IC_d;

  /* SystemInitialize for MATLAB Function: '<S22>/MATLAB Function' */
  ctrl_student_DW.controller = 1.0;
  ctrl_student_DW.tmp = 0.0;
}

/* Model terminate function */
void ctrl_student_terminate(void)
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
  ctrl_student_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_student_update();
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
  ctrl_student_initialize();
}

void MdlTerminate(void)
{
  ctrl_student_terminate();
}

/* Registration function */
RT_MODEL_ctrl_student_T *ctrl_student(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_student_M, 0,
                sizeof(RT_MODEL_ctrl_student_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_student_M->solverInfo,
                          &ctrl_student_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_student_M->solverInfo, &rtmGetTPtr(ctrl_student_M));
    rtsiSetStepSizePtr(&ctrl_student_M->solverInfo,
                       &ctrl_student_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_student_M->solverInfo, &ctrl_student_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_student_M->solverInfo, (real_T **)
                         &ctrl_student_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_student_M->solverInfo,
      &ctrl_student_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ctrl_student_M->solverInfo,
      &ctrl_student_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ctrl_student_M->solverInfo,
      &ctrl_student_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ctrl_student_M->solverInfo,
      &ctrl_student_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ctrl_student_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_student_M)));
    rtsiSetRTModelPtr(&ctrl_student_M->solverInfo, ctrl_student_M);
  }

  rtsiSetSimTimeStep(&ctrl_student_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_student_M->ModelData.intgData.y = ctrl_student_M->ModelData.odeY;
  ctrl_student_M->ModelData.intgData.f[0] = ctrl_student_M->ModelData.odeF[0];
  ctrl_student_M->ModelData.intgData.f[1] = ctrl_student_M->ModelData.odeF[1];
  ctrl_student_M->ModelData.intgData.f[2] = ctrl_student_M->ModelData.odeF[2];
  ctrl_student_M->ModelData.contStates = ((real_T *) &ctrl_student_X);
  rtsiSetSolverData(&ctrl_student_M->solverInfo, (void *)
                    &ctrl_student_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_student_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_student_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_student_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_student_M->Timing.sampleTimes =
      (&ctrl_student_M->Timing.sampleTimesArray[0]);
    ctrl_student_M->Timing.offsetTimes =
      (&ctrl_student_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_student_M->Timing.sampleTimes[0] = (0.0);
    ctrl_student_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_student_M->Timing.offsetTimes[0] = (0.0);
    ctrl_student_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_student_M, &ctrl_student_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_student_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_student_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_student_M, -1);
  ctrl_student_M->Timing.stepSize0 = 0.01;
  ctrl_student_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ctrl_student_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_student_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_student_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_student_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_student_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_student_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_student_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_student_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_student_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_student_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_student_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_student_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_student_M->rtwLogInfo, (NULL));
  }

  ctrl_student_M->solverInfoPtr = (&ctrl_student_M->solverInfo);
  ctrl_student_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_student_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_student_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_student_M->ModelData.blockIO = ((void *) &ctrl_student_B);
  (void) memset(((void *) &ctrl_student_B), 0,
                sizeof(B_ctrl_student_T));

  /* parameters */
  ctrl_student_M->ModelData.defaultParam = ((real_T *)&ctrl_student_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_student_X;
    ctrl_student_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_student_X, 0,
                  sizeof(X_ctrl_student_T));
  }

  /* states (dwork) */
  ctrl_student_M->ModelData.dwork = ((void *) &ctrl_student_DW);
  (void) memset((void *)&ctrl_student_DW, 0,
                sizeof(DW_ctrl_student_T));

  /* Initialize Sizes */
  ctrl_student_M->Sizes.numContStates = (25);/* Number of continuous states */
  ctrl_student_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_student_M->Sizes.numY = (0);    /* Number of model outputs */
  ctrl_student_M->Sizes.numU = (0);    /* Number of model inputs */
  ctrl_student_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_student_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_student_M->Sizes.numBlocks = (197);/* Number of blocks */
  ctrl_student_M->Sizes.numBlockIO = (59);/* Number of block outputs */
  ctrl_student_M->Sizes.numBlockPrms = (507);/* Sum of parameter "widths" */
  return ctrl_student_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_student
 * Model version : 1.150
 * VeriStand Model Framework version : 2015.1.0.76 (2015 SP1)
 * Source generated on : Thu Feb 02 14:51:44 2017
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_student
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

   case 14:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 35:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 47:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 48:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 49:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 50:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);
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
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 14:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 17:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 19:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 20:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 31:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 32:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 35:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 47:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 48:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 49:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 50:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_student_rtModel *S;
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

  // ctrl_student/Enable Thrust
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.EnableThrust, 0, data[index++], 47,
      0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/wave_dir
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.wave_dir, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/fzp_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.fzp_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/fzp_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.fzp_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/r_max
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.r_max, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/Core_controller
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_student_B.Core_controller, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_i_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_i_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_i_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_i_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_i_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_i_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_p_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_p_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_p_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_p_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_p_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_p_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_d_psi1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_d_psi1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_d_x1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_d_x1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_d_y1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_d_y1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_i_psi1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_i_psi1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_i_x1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_i_x1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_i_y1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_i_y1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_p_psi1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_p_psi1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_p_x1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_p_x1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Input/K_p_y1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.K_p_y1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Pos measurements/x_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.x_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Pos measurements/y_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.y_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/Pos measurements/psi_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_student_B.psi_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 27;
}

int32_t NumOutputPorts(void)
{
  return 35;
}

double ni_extout[35];

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

  // ctrl_student/alpha_1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Saturation1, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/pwm_2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_P.Constant1_Value,
      1, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_student/pwm_3: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_P.Constant1_Value,
      2, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_student/pwm_4: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_P.Constant1_Value,
      3, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_student/pwm_5: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_P.Constant1_Value,
      4, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_student/alpha_2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Saturation2, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/pwm_6: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_P.Constant1_Value,
      5, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_student/alpha_3: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Saturation3, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/alpha_4: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Saturation4, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/alpha_5: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Saturation5, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/alpha_6: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Saturation6, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/u_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Product, 0, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_student/u_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Product, 3, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_student/u_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Product, 4, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_student/u_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Product, 5, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_student/u_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Product, 1, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_student/u_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Product, 2, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_student/pwm_1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_P.Constant1_Value,
      0, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_student/tau_actual: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.commanded_tau,
      0, 23, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.commanded_tau,
      1, 23, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.commanded_tau,
      2, 23, 0);
  } else {
    index += 3;
  }

  // ctrl_student/TAPM Controller w_observer/eta_est: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.eta, 0, 23, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.eta, 1, 23, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.eta, 2, 23, 0);
  } else {
    index += 3;
  }

  // ctrl_student/TAPM Controller w_observer/nu_est: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.nu, 0, 26, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.nu, 1, 26, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.nu, 2, 26, 0);
  } else {
    index += 3;
  }

  // ctrl_student/TAPM Controller w_observer/SP: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_B.TmpSignalConversionAtSPInport1, 0, 23, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_B.TmpSignalConversionAtSPInport1, 1, 23, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_student_B.TmpSignalConversionAtSPInport1, 2, 23, 0);
  } else {
    index += 3;
  }

  // ctrl_student/TAPM Controller w_observer/tau_des: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.MultiportSwitch,
      0, 23, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.MultiportSwitch,
      1, 23, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.MultiportSwitch,
      2, 23, 0);
  } else {
    index += 3;
  }

  // ctrl_student/TAPM Controller w_observer/PID/controller: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.y, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_student/TAPM Controller w_observer/PID/timer: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Delay, 0, 0, 0);
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

  // ctrl_student/alpha_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Saturation1, 0, 0,
    0);

  // ctrl_student/pwm_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_P.Constant1_Value,
    1, 21, 0);

  // ctrl_student/pwm_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_P.Constant1_Value,
    2, 21, 0);

  // ctrl_student/pwm_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_P.Constant1_Value,
    3, 21, 0);

  // ctrl_student/pwm_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_P.Constant1_Value,
    4, 21, 0);

  // ctrl_student/alpha_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Saturation2, 0, 0,
    0);

  // ctrl_student/pwm_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_P.Constant1_Value,
    5, 21, 0);

  // ctrl_student/alpha_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Saturation3, 0, 0,
    0);

  // ctrl_student/alpha_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Saturation4, 0, 0,
    0);

  // ctrl_student/alpha_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Saturation5, 0, 0,
    0);

  // ctrl_student/alpha_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Saturation6, 0, 0,
    0);

  // ctrl_student/u_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Product, 0, 21, 0);

  // ctrl_student/u_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Product, 3, 21, 0);

  // ctrl_student/u_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Product, 4, 21, 0);

  // ctrl_student/u_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Product, 5, 21, 0);

  // ctrl_student/u_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Product, 1, 21, 0);

  // ctrl_student/u_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Product, 2, 21, 0);

  // ctrl_student/pwm_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_P.Constant1_Value,
    0, 21, 0);

  // ctrl_student/tau_actual: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.commanded_tau, 0,
    23, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.commanded_tau, 1,
    23, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.commanded_tau, 2,
    23, 0);

  // ctrl_student/TAPM Controller w_observer/eta_est: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.eta, 0, 23, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.eta, 1, 23, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.eta, 2, 23, 0);

  // ctrl_student/TAPM Controller w_observer/nu_est: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.nu, 0, 26, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.nu, 1, 26, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.nu, 2, 26, 0);

  // ctrl_student/TAPM Controller w_observer/SP: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_B.TmpSignalConversionAtSPInport1, 0, 23, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_B.TmpSignalConversionAtSPInport1, 1, 23, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_student_B.TmpSignalConversionAtSPInport1, 2, 23, 0);

  // ctrl_student/TAPM Controller w_observer/tau_des: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.MultiportSwitch,
    0, 23, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.MultiportSwitch,
    1, 23, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.MultiportSwitch,
    2, 23, 0);

  // ctrl_student/TAPM Controller w_observer/PID/controller: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.y, 0, 0, 0);

  // ctrl_student/TAPM Controller w_observer/PID/timer: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_student_B.Delay, 0, 0, 0);
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
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Gain6/Gain",
    offsetof(P_ctrl_student_T, Nonlinearpassiveobserver_D), 24, 9, 2, 0, 0 },

  { 1,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /K3/Gain",
    offsetof(P_ctrl_student_T, Nonlinearpassiveobserver_K3), 24, 9, 2, 2, 0 },

  { 2,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /K4/Gain",
    offsetof(P_ctrl_student_T, Nonlinearpassiveobserver_K4), 24, 9, 2, 4, 0 },

  { 3,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /K2/Gain",
    offsetof(P_ctrl_student_T, Nonlinearpassiveobserver_w_c), 24, 9, 2, 6, 0 },

  { 4, "ctrl_student/constant angle/Value", offsetof(P_ctrl_student_T,
    constantangle_Value), 31, 6, 2, 8, 0 },

  { 5, "ctrl_student/Degrees to Radians/Gain1/Gain", offsetof(P_ctrl_student_T,
    Gain1_Gain), 47, 1, 2, 10, 0 },

  { 6, "ctrl_student/Subsystem1/Saturation 1/UpperLimit", offsetof
    (P_ctrl_student_T, Saturation1_UpperSat), 47, 1, 2, 12, 0 },

  { 7, "ctrl_student/Subsystem1/Saturation 1/LowerLimit", offsetof
    (P_ctrl_student_T, Saturation1_LowerSat), 47, 1, 2, 14, 0 },

  { 8, "ctrl_student/Constant1/Value", offsetof(P_ctrl_student_T,
    Constant1_Value), 31, 6, 2, 16, 0 },

  { 9, "ctrl_student/Subsystem1/Saturation 2/UpperLimit", offsetof
    (P_ctrl_student_T, Saturation2_UpperSat), 47, 1, 2, 18, 0 },

  { 10, "ctrl_student/Subsystem1/Saturation 2/LowerLimit", offsetof
    (P_ctrl_student_T, Saturation2_LowerSat), 47, 1, 2, 20, 0 },

  { 11, "ctrl_student/Subsystem1/Saturation 3/UpperLimit", offsetof
    (P_ctrl_student_T, Saturation3_UpperSat), 47, 1, 2, 22, 0 },

  { 12, "ctrl_student/Subsystem1/Saturation 3/LowerLimit", offsetof
    (P_ctrl_student_T, Saturation3_LowerSat), 47, 1, 2, 24, 0 },

  { 13, "ctrl_student/Subsystem1/Saturation 4/UpperLimit", offsetof
    (P_ctrl_student_T, Saturation4_UpperSat), 47, 1, 2, 26, 0 },

  { 14, "ctrl_student/Subsystem1/Saturation 4/LowerLimit", offsetof
    (P_ctrl_student_T, Saturation4_LowerSat), 47, 1, 2, 28, 0 },

  { 15, "ctrl_student/Subsystem1/Saturation 5/UpperLimit", offsetof
    (P_ctrl_student_T, Saturation5_UpperSat), 47, 1, 2, 30, 0 },

  { 16, "ctrl_student/Subsystem1/Saturation 5/LowerLimit", offsetof
    (P_ctrl_student_T, Saturation5_LowerSat), 47, 1, 2, 32, 0 },

  { 17, "ctrl_student/Subsystem1/Saturation 6/UpperLimit", offsetof
    (P_ctrl_student_T, Saturation6_UpperSat), 47, 1, 2, 34, 0 },

  { 18, "ctrl_student/Subsystem1/Saturation 6/LowerLimit", offsetof
    (P_ctrl_student_T, Saturation6_LowerSat), 47, 1, 2, 36, 0 },

  { 19, "ctrl_student/TAPM Controller w_observer/PID/Delay/InitialCondition",
    offsetof(P_ctrl_student_T, Delay_InitialCondition), 47, 1, 2, 38, 0 },

  { 20,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Integrator/InitialCondition",
    offsetof(P_ctrl_student_T, Integrator_IC), 26, 3, 2, 40, 0 },

  { 21,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_student_T, Saturation_UpperSat), 47, 1, 2, 42, 0 },

  { 22,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_student_T, Saturation_LowerSat), 47, 1, 2, 44, 0 },

  { 23,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_student_T, Gain_Gain), 47, 1, 2, 46, 0 },

  { 24,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_student_T, Constant_Value), 47, 1, 2, 48, 0 },

  { 25,
    "ctrl_student/TAPM Controller w_observer/SP Generator/Integrator/InitialCondition",
    offsetof(P_ctrl_student_T, Integrator_IC_b), 32, 2, 2, 50, 0 },

  { 26, "ctrl_student/TAPM Controller w_observer/SP Generator/Transfer Fcn2/A",
    offsetof(P_ctrl_student_T, TransferFcn2_A), 47, 1, 2, 52, 0 },

  { 27, "ctrl_student/TAPM Controller w_observer/SP Generator/Transfer Fcn2/C",
    offsetof(P_ctrl_student_T, TransferFcn2_C), 47, 1, 2, 54, 0 },

  { 28,
    "ctrl_student/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_student_T, Saturation_UpperSat_g), 47, 1, 2, 56, 0 },

  { 29,
    "ctrl_student/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_student_T, Saturation_LowerSat_h), 47, 1, 2, 58, 0 },

  { 30,
    "ctrl_student/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_student_T, Gain_Gain_p), 47, 1, 2, 60, 0 },

  { 31,
    "ctrl_student/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_student_T, Constant_Value_k), 47, 1, 2, 62, 0 },

  { 32,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_student_T, Saturation_UpperSat_l), 47, 1, 2, 64, 0 },

  { 33,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_student_T, Saturation_LowerSat_l), 47, 1, 2, 66, 0 },

  { 34,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_student_T, Gain_Gain_l), 47, 1, 2, 68, 0 },

  { 35,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_student_T, Constant_Value_e), 47, 1, 2, 70, 0 },

  { 36,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller/Integrator/InitialCondition",
    offsetof(P_ctrl_student_T, Integrator_IC_f), 47, 1, 2, 72, 0 },

  { 37,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Integrator4/InitialCondition",
    offsetof(P_ctrl_student_T, Integrator4_IC), 26, 3, 2, 74, 0 },

  { 38,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_student_T, Saturation_UpperSat_h), 47, 1, 2, 76, 0 },

  { 39,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_student_T, Saturation_LowerSat_d), 47, 1, 2, 78, 0 },

  { 40,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_student_T, Gain_Gain_n), 47, 1, 2, 80, 0 },

  { 41,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_student_T, Constant_Value_d), 47, 1, 2, 82, 0 },

  { 42,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_student_T, Saturation_UpperSat_a), 47, 1, 2, 84, 0 },

  { 43,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_student_T, Saturation_LowerSat_lh), 47, 1, 2, 86, 0 },

  { 44,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_student_T, Gain_Gain_j), 47, 1, 2, 88, 0 },

  { 45,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_student_T, Constant_Value_c), 47, 1, 2, 90, 0 },

  { 46,
    "ctrl_student/TAPM Controller w_observer/PID/DP controller1/Integrator/InitialCondition",
    offsetof(P_ctrl_student_T, Integrator_IC_p), 47, 1, 2, 92, 0 },

  { 47,
    "ctrl_student/TA fixed thrusters, pseudoinverse/X-position Thruster/Value",
    offsetof(P_ctrl_student_T, XpositionThruster_Value), 31, 6, 2, 94, 0 },

  { 48,
    "ctrl_student/TA fixed thrusters, pseudoinverse/Y-position Thruster/Value",
    offsetof(P_ctrl_student_T, YpositionThruster_Value), 31, 6, 2, 96, 0 },

  { 49, "ctrl_student/TA fixed thrusters, pseudoinverse/constant angle1/Value",
    offsetof(P_ctrl_student_T, constantangle1_Value), 31, 6, 2, 98, 0 },

  { 50, "ctrl_student/Radians to Degrees/Gain/Gain", offsetof(P_ctrl_student_T,
    Gain_Gain_f), 47, 1, 2, 100, 0 },

  { 51, "ctrl_student/X-position Thruster/Value", offsetof(P_ctrl_student_T,
    XpositionThruster_Value_e), 31, 6, 2, 102, 0 },

  { 52, "ctrl_student/Y-position Thruster/Value", offsetof(P_ctrl_student_T,
    YpositionThruster_Value_o), 31, 6, 2, 104, 0 },

  { 53,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Integrator1/InitialCondition",
    offsetof(P_ctrl_student_T, Integrator1_IC), 47, 1, 2, 106, 0 },

  { 54,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Gain1/Gain",
    offsetof(P_ctrl_student_T, Gain1_Gain_i), 24, 9, 2, 108, 0 },

  { 55,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Integrator2/InitialCondition",
    offsetof(P_ctrl_student_T, Integrator2_IC), 47, 1, 2, 110, 0 },

  { 56,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Gain2/Gain",
    offsetof(P_ctrl_student_T, Gain2_Gain), 24, 9, 2, 112, 0 },

  { 57,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Integrator3/InitialCondition",
    offsetof(P_ctrl_student_T, Integrator3_IC), 47, 1, 2, 114, 0 },

  { 58,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Gain3/Gain",
    offsetof(P_ctrl_student_T, Gain3_Gain), 24, 9, 2, 116, 0 },

  { 59,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /K11/Gain",
    offsetof(P_ctrl_student_T, K11_Gain), 24, 9, 2, 118, 0 },

  { 60,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /K12/Gain",
    offsetof(P_ctrl_student_T, K12_Gain), 24, 9, 2, 120, 0 },

  { 61,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /inv(T_b)/Gain",
    offsetof(P_ctrl_student_T, invT_b_Gain), 24, 9, 2, 122, 0 },

  { 62, "ctrl_student/TAPM Controller w_observer/PID/Constant/Value", offsetof
    (P_ctrl_student_T, Constant_Value_o), 47, 1, 2, 124, 0 },

  { 63,
    "ctrl_student/TAPM Controller w_observer/PID/Integrator/InitialCondition",
    offsetof(P_ctrl_student_T, Integrator_IC_d), 47, 1, 2, 126, 0 },

  { 64, "ctrl_student/TAPM Controller w_observer/SP Generator/Constant1/Value",
    offsetof(P_ctrl_student_T, Constant1_Value_p), 47, 1, 2, 128, 0 },

  { 65, "ctrl_student/TAPM Controller w_observer/SP Generator/Gain/Gain",
    offsetof(P_ctrl_student_T, Gain_Gain_d), 33, 4, 2, 130, 0 },

  { 66, "ctrl_student/TAPM Controller w_observer/SP Generator/Gain1/Gain",
    offsetof(P_ctrl_student_T, Gain1_Gain_ib), 33, 4, 2, 132, 0 },

  { 67, "ctrl_student/Input/deg2rad/Gain", offsetof(P_ctrl_student_T,
    deg2rad_Gain), 47, 1, 2, 134, 0 },

  { 68, "ctrl_student/TAPM Controller w_observer/PID/Delay/DelayLength",
    offsetof(P_ctrl_student_T, Delay_DelayLength), 48, 1, 2, 136, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 69;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  3, 3,                                /* Parameter at index 0 */
  3, 3,                                /* Parameter at index 1 */
  3, 3,                                /* Parameter at index 2 */
  3, 3,                                /* Parameter at index 3 */
  1, 6,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 6,                                /* Parameter at index 8 */
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
  3, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 2,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
  1, 1,                                /* Parameter at index 36 */
  3, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
  1, 1,                                /* Parameter at index 39 */
  1, 1,                                /* Parameter at index 40 */
  1, 1,                                /* Parameter at index 41 */
  1, 1,                                /* Parameter at index 42 */
  1, 1,                                /* Parameter at index 43 */
  1, 1,                                /* Parameter at index 44 */
  1, 1,                                /* Parameter at index 45 */
  1, 1,                                /* Parameter at index 46 */
  1, 6,                                /* Parameter at index 47 */
  1, 6,                                /* Parameter at index 48 */
  1, 6,                                /* Parameter at index 49 */
  1, 1,                                /* Parameter at index 50 */
  1, 6,                                /* Parameter at index 51 */
  1, 6,                                /* Parameter at index 52 */
  1, 1,                                /* Parameter at index 53 */
  3, 3,                                /* Parameter at index 54 */
  1, 1,                                /* Parameter at index 55 */
  3, 3,                                /* Parameter at index 56 */
  1, 1,                                /* Parameter at index 57 */
  3, 3,                                /* Parameter at index 58 */
  3, 3,                                /* Parameter at index 59 */
  3, 3,                                /* Parameter at index 60 */
  3, 3,                                /* Parameter at index 61 */
  1, 1,                                /* Parameter at index 62 */
  1, 1,                                /* Parameter at index 63 */
  1, 1,                                /* Parameter at index 64 */
  2, 2,                                /* Parameter at index 65 */
  2, 2,                                /* Parameter at index 66 */
  1, 1,                                /* Parameter at index 67 */
  1, 1,                                /* Parameter at index 68 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_student/Subsystem1/Saturation 1", 0, "", offsetof(B_ctrl_student_T,
    Saturation1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_student/Enable Thrust", 0, "", offsetof(B_ctrl_student_T,
    EnableThrust) + (0*sizeof(real_T)), BLOCKIO_SIG, 47, 1, 2, 0, 0 },

  { 2, "ctrl_student/Subsystem1/Saturation 2", 0, "", offsetof(B_ctrl_student_T,
    Saturation2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "ctrl_student/Subsystem1/Saturation 3", 0, "", offsetof(B_ctrl_student_T,
    Saturation3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "ctrl_student/Subsystem1/Saturation 4", 0, "", offsetof(B_ctrl_student_T,
    Saturation4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "ctrl_student/Subsystem1/Saturation 5", 0, "", offsetof(B_ctrl_student_T,
    Saturation5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "ctrl_student/Subsystem1/Saturation 6", 0, "", offsetof(B_ctrl_student_T,
    Saturation6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "ctrl_student/TAPM Controller w_observer/PID/Delay", 0, "", offsetof
    (B_ctrl_student_T, Delay) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "ctrl_student/Input/wave_dir", 0, "", offsetof(B_ctrl_student_T, wave_dir)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "ctrl_student/Input/fzp_x", 0, "", offsetof(B_ctrl_student_T, fzp_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_student/Input/fzp_y", 0, "", offsetof(B_ctrl_student_T, fzp_y) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_student/Input/r_max", 0, "", offsetof(B_ctrl_student_T, r_max) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_student/Input/Core_controller", 0, "", offsetof(B_ctrl_student_T,
    Core_controller) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_student/Input/K_i_y", 0, "", offsetof(B_ctrl_student_T, K_i_y) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "ctrl_student/Input/K_d_psi", 0, "", offsetof(B_ctrl_student_T, K_d_psi)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "ctrl_student/Input/K_d_x", 0, "", offsetof(B_ctrl_student_T, K_d_x) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "ctrl_student/Input/K_d_y", 0, "", offsetof(B_ctrl_student_T, K_d_y) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "ctrl_student/Input/K_i_psi", 0, "", offsetof(B_ctrl_student_T, K_i_psi)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "ctrl_student/Input/K_i_x", 0, "", offsetof(B_ctrl_student_T, K_i_x) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 19, "ctrl_student/Input/K_p_psi", 0, "", offsetof(B_ctrl_student_T, K_p_psi)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "ctrl_student/Input/K_p_x", 0, "", offsetof(B_ctrl_student_T, K_p_x) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "ctrl_student/Input/K_p_y", 0, "", offsetof(B_ctrl_student_T, K_p_y) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "ctrl_student/Input/K_d_psi1", 0, "", offsetof(B_ctrl_student_T,
    K_d_psi1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 23, "ctrl_student/Input/K_d_x1", 0, "", offsetof(B_ctrl_student_T, K_d_x1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 24, "ctrl_student/Input/K_d_y1", 0, "", offsetof(B_ctrl_student_T, K_d_y1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 25, "ctrl_student/Input/K_i_psi1", 0, "", offsetof(B_ctrl_student_T,
    K_i_psi1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 26, "ctrl_student/Input/K_i_x1", 0, "", offsetof(B_ctrl_student_T, K_i_x1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 27, "ctrl_student/Input/K_i_y1", 0, "", offsetof(B_ctrl_student_T, K_i_y1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 28, "ctrl_student/Input/K_p_psi1", 0, "", offsetof(B_ctrl_student_T,
    K_p_psi1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 29, "ctrl_student/Input/K_p_x1", 0, "", offsetof(B_ctrl_student_T, K_p_x1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 30, "ctrl_student/Input/K_p_y1", 0, "", offsetof(B_ctrl_student_T, K_p_y1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 31,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Integrator",
    0, "eta(1, 1)", offsetof(B_ctrl_student_T, eta) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 32,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Integrator",
    0, "eta(1, 2)", offsetof(B_ctrl_student_T, eta) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 33,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Integrator",
    0, "eta(1, 3)", offsetof(B_ctrl_student_T, eta) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 34,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Integrator4",
    0, "nu(1, 1)", offsetof(B_ctrl_student_T, nu) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 35,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Integrator4",
    0, "nu(2, 1)", offsetof(B_ctrl_student_T, nu) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 36,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Integrator4",
    0, "nu(3, 1)", offsetof(B_ctrl_student_T, nu) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 37, "ctrl_student/TAPM Controller w_observer/PID/Multiport Switch/(1, 1)", 0,
    "", offsetof(B_ctrl_student_T, MultiportSwitch) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 38, "ctrl_student/TAPM Controller w_observer/PID/Multiport Switch/(1, 2)", 0,
    "", offsetof(B_ctrl_student_T, MultiportSwitch) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 39, "ctrl_student/TAPM Controller w_observer/PID/Multiport Switch/(1, 3)", 0,
    "", offsetof(B_ctrl_student_T, MultiportSwitch) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 40, "ctrl_student/Product/(1, 1)", 0, "", offsetof(B_ctrl_student_T, Product)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 41, "ctrl_student/Product/(1, 2)", 0, "", offsetof(B_ctrl_student_T, Product)
    + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 42, "ctrl_student/Product/(1, 3)", 0, "", offsetof(B_ctrl_student_T, Product)
    + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 43, "ctrl_student/Product/(1, 4)", 0, "", offsetof(B_ctrl_student_T, Product)
    + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 44, "ctrl_student/Product/(1, 5)", 0, "", offsetof(B_ctrl_student_T, Product)
    + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 45, "ctrl_student/Product/(1, 6)", 0, "", offsetof(B_ctrl_student_T, Product)
    + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 46, "ctrl_student/Radians to Degrees/Gain/(1, 1)", 0, "", offsetof
    (B_ctrl_student_T, Gain) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 47, "ctrl_student/Radians to Degrees/Gain/(1, 2)", 0, "", offsetof
    (B_ctrl_student_T, Gain) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 48, "ctrl_student/Radians to Degrees/Gain/(1, 3)", 0, "", offsetof
    (B_ctrl_student_T, Gain) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 49, "ctrl_student/Radians to Degrees/Gain/(1, 4)", 0, "", offsetof
    (B_ctrl_student_T, Gain) + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 50, "ctrl_student/Radians to Degrees/Gain/(1, 5)", 0, "", offsetof
    (B_ctrl_student_T, Gain) + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 51, "ctrl_student/Radians to Degrees/Gain/(1, 6)", 0, "", offsetof
    (B_ctrl_student_T, Gain) + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 52, "ctrl_student/Pos measurements/x_m", 0, "", offsetof(B_ctrl_student_T,
    x_m) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 53, "ctrl_student/Pos measurements/y_m", 0, "", offsetof(B_ctrl_student_T,
    y_m) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 54, "ctrl_student/Pos measurements/psi_m", 0, "", offsetof(B_ctrl_student_T,
    psi_m) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 55,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Gain3/(1, 1)",
    0, "", offsetof(B_ctrl_student_T, Gain3) + (0*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 56,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Gain3/(2, 1)",
    0, "", offsetof(B_ctrl_student_T, Gain3) + (1*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 57,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Gain3/(3, 1)",
    0, "", offsetof(B_ctrl_student_T, Gain3) + (2*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 58,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Sum3/(1, 1)",
    0, "", offsetof(B_ctrl_student_T, Sum3) + (0*sizeof(real_T)), BLOCKIO_SIG,
    23, 1, 2, 0, 0 },

  { 59,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Sum3/(1, 2)",
    0, "", offsetof(B_ctrl_student_T, Sum3) + (1*sizeof(real_T)), BLOCKIO_SIG,
    23, 1, 2, 0, 0 },

  { 60,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Sum3/(1, 3)",
    0, "", offsetof(B_ctrl_student_T, Sum3) + (2*sizeof(real_T)), BLOCKIO_SIG,
    23, 1, 2, 0, 0 },

  { 61,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Sum5",
    0, "psi_WF(1, 1)", offsetof(B_ctrl_student_T, psi_WF) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 62,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Sum5",
    0, "psi_WF(2, 1)", offsetof(B_ctrl_student_T, psi_WF) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 63,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Sum5",
    0, "psi_WF(3, 1)", offsetof(B_ctrl_student_T, psi_WF) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 64,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Sum6/(1, 1)",
    0, "", offsetof(B_ctrl_student_T, Sum6) + (0*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 65,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Sum6/(2, 1)",
    0, "", offsetof(B_ctrl_student_T, Sum6) + (1*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 66,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Sum6/(3, 1)",
    0, "", offsetof(B_ctrl_student_T, Sum6) + (2*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 67,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Sum7/(1, 1)",
    0, "", offsetof(B_ctrl_student_T, Sum7) + (0*sizeof(real_T)), BLOCKIO_SIG,
    23, 1, 2, 0, 0 },

  { 68,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Sum7/(1, 2)",
    0, "", offsetof(B_ctrl_student_T, Sum7) + (1*sizeof(real_T)), BLOCKIO_SIG,
    23, 1, 2, 0, 0 },

  { 69,
    "ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Sum7/(1, 3)",
    0, "", offsetof(B_ctrl_student_T, Sum7) + (2*sizeof(real_T)), BLOCKIO_SIG,
    23, 1, 2, 0, 0 },

  { 70, "ctrl_student/TAPM Controller w_observer/PID/Integrator", 0, "",
    offsetof(B_ctrl_student_T, Integrator) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 71, "ctrl_student/TAPM Controller w_observer/SP Generator/Sum", 0, "",
    offsetof(B_ctrl_student_T, Sum) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 72, "ctrl_student/TAPM Controller w_observer/SP Generator/Sum1/(1, 1)", 0,
    "", offsetof(B_ctrl_student_T, Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 73, "ctrl_student/TAPM Controller w_observer/SP Generator/Sum1/(1, 2)", 0,
    "", offsetof(B_ctrl_student_T, Sum1) + (1*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 74, "ctrl_student/TAPM Controller w_observer/PID/MATLAB Function", 0, "",
    offsetof(B_ctrl_student_T, reset) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 75, "ctrl_student/TAPM Controller w_observer/PID/MATLAB Function", 1, "",
    offsetof(B_ctrl_student_T, y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 76, "ctrl_student/Finding commanded forces in: [Surge,Sway,Yaw]", 0,
    "(1, 1)", offsetof(B_ctrl_student_T, commanded_tau) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 77, "ctrl_student/Finding commanded forces in: [Surge,Sway,Yaw]", 0,
    "(1, 2)", offsetof(B_ctrl_student_T, commanded_tau) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 78, "ctrl_student/Finding commanded forces in: [Surge,Sway,Yaw]", 0,
    "(1, 3)", offsetof(B_ctrl_student_T, commanded_tau) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 79, "ctrl_student/Input/MATLAB Function6", 0, "(1, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction6.K_d) + (0*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 80, "ctrl_student/Input/MATLAB Function6", 0, "(2, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction6.K_d) + (1*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 81, "ctrl_student/Input/MATLAB Function6", 0, "(3, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction6.K_d) + (2*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 82, "ctrl_student/Input/MATLAB Function6", 0, "(1, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction6.K_d) + (3*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 83, "ctrl_student/Input/MATLAB Function6", 0, "(2, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction6.K_d) + (4*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 84, "ctrl_student/Input/MATLAB Function6", 0, "(3, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction6.K_d) + (5*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 85, "ctrl_student/Input/MATLAB Function6", 0, "(1, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction6.K_d) + (6*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 86, "ctrl_student/Input/MATLAB Function6", 0, "(2, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction6.K_d) + (7*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 87, "ctrl_student/Input/MATLAB Function6", 0, "(3, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction6.K_d) + (8*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 88, "ctrl_student/Input/MATLAB Function5", 0, "(1, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction5.K_i) + (0*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 89, "ctrl_student/Input/MATLAB Function5", 0, "(2, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction5.K_i) + (1*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 90, "ctrl_student/Input/MATLAB Function5", 0, "(3, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction5.K_i) + (2*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 91, "ctrl_student/Input/MATLAB Function5", 0, "(1, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction5.K_i) + (3*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 92, "ctrl_student/Input/MATLAB Function5", 0, "(2, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction5.K_i) + (4*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 93, "ctrl_student/Input/MATLAB Function5", 0, "(3, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction5.K_i) + (5*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 94, "ctrl_student/Input/MATLAB Function5", 0, "(1, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction5.K_i) + (6*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 95, "ctrl_student/Input/MATLAB Function5", 0, "(2, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction5.K_i) + (7*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 96, "ctrl_student/Input/MATLAB Function5", 0, "(3, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction5.K_i) + (8*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 97, "ctrl_student/Input/MATLAB Function4", 0, "(1, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction4.K_p) + (0*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 98, "ctrl_student/Input/MATLAB Function4", 0, "(2, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction4.K_p) + (1*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 99, "ctrl_student/Input/MATLAB Function4", 0, "(3, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction4.K_p) + (2*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 100, "ctrl_student/Input/MATLAB Function4", 0, "(1, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction4.K_p) + (3*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 101, "ctrl_student/Input/MATLAB Function4", 0, "(2, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction4.K_p) + (4*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 102, "ctrl_student/Input/MATLAB Function4", 0, "(3, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction4.K_p) + (5*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 103, "ctrl_student/Input/MATLAB Function4", 0, "(1, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction4.K_p) + (6*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 104, "ctrl_student/Input/MATLAB Function4", 0, "(2, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction4.K_p) + (7*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 105, "ctrl_student/Input/MATLAB Function4", 0, "(3, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction4.K_p) + (8*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 106, "ctrl_student/Input/MATLAB Function2", 0, "(1, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction2.K_d) + (0*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 107, "ctrl_student/Input/MATLAB Function2", 0, "(2, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction2.K_d) + (1*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 108, "ctrl_student/Input/MATLAB Function2", 0, "(3, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction2.K_d) + (2*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 109, "ctrl_student/Input/MATLAB Function2", 0, "(1, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction2.K_d) + (3*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 110, "ctrl_student/Input/MATLAB Function2", 0, "(2, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction2.K_d) + (4*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 111, "ctrl_student/Input/MATLAB Function2", 0, "(3, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction2.K_d) + (5*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 112, "ctrl_student/Input/MATLAB Function2", 0, "(1, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction2.K_d) + (6*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 113, "ctrl_student/Input/MATLAB Function2", 0, "(2, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction2.K_d) + (7*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 114, "ctrl_student/Input/MATLAB Function2", 0, "(3, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction2.K_d) + (8*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 115, "ctrl_student/Input/MATLAB Function1", 0, "(1, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction1.K_i) + (0*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 116, "ctrl_student/Input/MATLAB Function1", 0, "(2, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction1.K_i) + (1*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 117, "ctrl_student/Input/MATLAB Function1", 0, "(3, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction1.K_i) + (2*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 118, "ctrl_student/Input/MATLAB Function1", 0, "(1, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction1.K_i) + (3*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 119, "ctrl_student/Input/MATLAB Function1", 0, "(2, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction1.K_i) + (4*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 120, "ctrl_student/Input/MATLAB Function1", 0, "(3, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction1.K_i) + (5*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 121, "ctrl_student/Input/MATLAB Function1", 0, "(1, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction1.K_i) + (6*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 122, "ctrl_student/Input/MATLAB Function1", 0, "(2, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction1.K_i) + (7*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 123, "ctrl_student/Input/MATLAB Function1", 0, "(3, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction1.K_i) + (8*sizeof(real_T)), BLOCKIO_SIG,
    24, 1, 2, 0, 0 },

  { 124, "ctrl_student/Input/MATLAB Function", 0, "(1, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction_f.K_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 125, "ctrl_student/Input/MATLAB Function", 0, "(2, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction_f.K_p) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 126, "ctrl_student/Input/MATLAB Function", 0, "(3, 1)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction_f.K_p) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 127, "ctrl_student/Input/MATLAB Function", 0, "(1, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction_f.K_p) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 128, "ctrl_student/Input/MATLAB Function", 0, "(2, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction_f.K_p) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 129, "ctrl_student/Input/MATLAB Function", 0, "(3, 2)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction_f.K_p) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 130, "ctrl_student/Input/MATLAB Function", 0, "(1, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction_f.K_p) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 131, "ctrl_student/Input/MATLAB Function", 0, "(2, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction_f.K_p) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 132, "ctrl_student/Input/MATLAB Function", 0, "(3, 3)", offsetof
    (B_ctrl_student_T, sf_MATLABFunction_f.K_p) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 133;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 52;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Enable Thrust", 0, EXT_IN, 1, 1, 1 },

  { 2, "Input/wave_dir", 0, EXT_IN, 1, 1, 1 },

  { 3, "Input/fzp_x", 0, EXT_IN, 1, 1, 1 },

  { 4, "Input/fzp_y", 0, EXT_IN, 1, 1, 1 },

  { 5, "Input/r_max", 0, EXT_IN, 1, 1, 1 },

  { 6, "Input/Core_controller", 1, EXT_IN, 1, 1, 1 },

  { 7, "Input/K_i_y", 0, EXT_IN, 1, 1, 1 },

  { 8, "Input/K_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 9, "Input/K_d_x", 0, EXT_IN, 1, 1, 1 },

  { 10, "Input/K_d_y", 0, EXT_IN, 1, 1, 1 },

  { 11, "Input/K_i_psi", 0, EXT_IN, 1, 1, 1 },

  { 12, "Input/K_i_x", 0, EXT_IN, 1, 1, 1 },

  { 13, "Input/K_p_psi", 0, EXT_IN, 1, 1, 1 },

  { 14, "Input/K_p_x", 0, EXT_IN, 1, 1, 1 },

  { 15, "Input/K_p_y", 0, EXT_IN, 1, 1, 1 },

  { 16, "Input/K_d_psi1", 0, EXT_IN, 1, 1, 1 },

  { 17, "Input/K_d_x1", 0, EXT_IN, 1, 1, 1 },

  { 18, "Input/K_d_y1", 0, EXT_IN, 1, 1, 1 },

  { 19, "Input/K_i_psi1", 0, EXT_IN, 1, 1, 1 },

  { 20, "Input/K_i_x1", 0, EXT_IN, 1, 1, 1 },

  { 21, "Input/K_i_y1", 0, EXT_IN, 1, 1, 1 },

  { 22, "Input/K_p_psi1", 0, EXT_IN, 1, 1, 1 },

  { 23, "Input/K_p_x1", 0, EXT_IN, 1, 1, 1 },

  { 24, "Input/K_p_y1", 0, EXT_IN, 1, 1, 1 },

  { 25, "Pos measurements/x_m", 0, EXT_IN, 1, 1, 1 },

  { 26, "Pos measurements/y_m", 0, EXT_IN, 1, 1, 1 },

  { 27, "Pos measurements/psi_m", 0, EXT_IN, 1, 1, 1 },

  { 1, "alpha_1", 1, EXT_OUT, 1, 1, 1 },

  { 2, "pwm_2", 1, EXT_OUT, 1, 1, 1 },

  { 3, "pwm_3", 1, EXT_OUT, 1, 1, 1 },

  { 4, "pwm_4", 1, EXT_OUT, 1, 1, 1 },

  { 5, "pwm_5", 1, EXT_OUT, 1, 1, 1 },

  { 6, "alpha_2", 1, EXT_OUT, 1, 1, 1 },

  { 7, "pwm_6", 1, EXT_OUT, 1, 1, 1 },

  { 8, "alpha_3", 1, EXT_OUT, 1, 1, 1 },

  { 9, "alpha_4", 1, EXT_OUT, 1, 1, 1 },

  { 10, "alpha_5", 1, EXT_OUT, 1, 1, 1 },

  { 11, "alpha_6", 1, EXT_OUT, 1, 1, 1 },

  { 12, "u_1", 0, EXT_OUT, 1, 1, 1 },

  { 13, "u_4", 0, EXT_OUT, 1, 1, 1 },

  { 14, "u_5", 0, EXT_OUT, 1, 1, 1 },

  { 15, "u_6", 0, EXT_OUT, 1, 1, 1 },

  { 16, "u_2", 0, EXT_OUT, 1, 1, 1 },

  { 17, "u_3", 0, EXT_OUT, 1, 1, 1 },

  { 18, "pwm_1", 1, EXT_OUT, 1, 1, 1 },

  { 19, "tau_actual", 0, EXT_OUT, 3, 3, 1 },

  { 20, "TAPM Controller w_observer/eta_est", 0, EXT_OUT, 3, 3, 1 },

  { 21, "TAPM Controller w_observer/nu_est", 0, EXT_OUT, 3, 3, 1 },

  { 22, "TAPM Controller w_observer/SP", 0, EXT_OUT, 3, 3, 1 },

  { 23, "TAPM Controller w_observer/tau_des", 0, EXT_OUT, 3, 3, 1 },

  { 24, "TAPM Controller w_observer/PID/controller", 0, EXT_OUT, 1, 1, 1 },

  { 25, "TAPM Controller w_observer/PID/timer", 1, EXT_OUT, 1, 1, 1 },

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
  "ctrl_student";
static const char* NI_CompiledModelVersion = "1.150";
static const char* NI_CompiledModelDateTime = "Thu Feb 02 14:51:44 2017";
static const char* NI_builder DataSection(".NIVS.builder") =
  "NI Model Framework 2015.1.0.76 (2015 SP1) for Simulink Coder 8.10 (R2016a)";
static const char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2015.1.0.76";

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
    char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ?
                        S->ModelData.blockIO : S->ModelData.inputs) + (uintptr_t)
      NI_SigList[idx].addr;
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
  memcpy(&rtParameter[0], &ctrl_student_P, sizeof(P_ctrl_student_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_student_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_student_T));
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
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* Commit parameter values */
  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_student_T));
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
               (P_ctrl_student_T));
      }

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /* If we have values to commit, then save to the write-side */
    if (WriteSideDirtyFlag == 1) {
      S->ModelData.defaultParam = (double *)&rtParameter[1-READSIDE];
      WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
      READSIDE = 1 - READSIDE;
      SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
      ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

      // Copy back the newly set parameters to the writeside.
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_student_T));
      WriteSideDirtyFlag = 0;
    }

    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr,subindex,value,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
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
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength != (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* If we have pending modified parameters, then copy to write-side */
  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_student_T));
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
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex >= (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr,subindex,paramvalue,NI_ParamList[index].
    datatype,NI_ParamList[index].IsComplex);
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
  *value = NIRT_GetValueByDataType(ptr,subindex,NI_ParamList[index].datatype,
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
      *numContStates = 25;
      *numDiscStates = 741;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_student_X.Integrator_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_student_X.Integrator_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_student_X.Integrator_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator_CSTATE_l), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator_CSTATE_l), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.TransferFcn2_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "TransferFcn2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator_CSTATE_g), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator_CSTATE_g), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator_CSTATE_g), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator4_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator4_CSTATE), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator4_CSTATE), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator_CSTATE_k), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_k");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator_CSTATE_k), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_k");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator_CSTATE_k), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_k");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator1_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator1_CSTATE), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator1_CSTATE), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator2_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator2_CSTATE), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator2_CSTATE), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator3_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator3_CSTATE), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator3_CSTATE), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_student_X.Integrator_CSTATE_d), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_d");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.Delay_DSTATE, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.Delay_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.alpha_1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.alpha_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_DW.EnableThrust_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_DW.EnableThrust_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.pwm_2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.pwm_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.pwm_3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.pwm_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.pwm_4_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.pwm_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.pwm_5_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.pwm_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.alpha_2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.alpha_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.pwm_6_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.pwm_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.alpha_3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.alpha_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.alpha_4_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.alpha_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.alpha_5_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.alpha_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.alpha_6_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.alpha_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.wave_dir_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.wave_dir_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.fzp_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.fzp_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.fzp_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.fzp_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.r_max_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.r_max_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_student_DW.Core_controller_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_student_DW.Core_controller_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_i_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_i_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_d_psi_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_d_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_d_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_i_psi_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_i_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_i_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_i_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_p_psi_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_p_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_p_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_p_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_p_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_p_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_d_psi1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_d_psi1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_d_x1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_d_x1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_d_y1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_d_y1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_i_psi1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_i_psi1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_i_x1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_i_x1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_i_y1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_i_y1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_p_psi1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_p_psi1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_p_x1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_p_x1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_p_y1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_p_y1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.u_1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.u_4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.u_5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.u_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.u_6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.u_2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.u_3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.pwm_1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.pwm_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.tau_actual_DWORK1,
      0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.tau_actual_DWORK1,
      1, 23, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.tau_actual_DWORK1,
      2, 23, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.x_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.y_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.psi_m_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.eta_est_DWORK1, 0,
      23, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.eta_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.eta_est_DWORK1, 1,
      23, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.eta_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.eta_est_DWORK1, 2,
      23, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.eta_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.nu_est_DWORK1, 0,
      23, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.nu_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.nu_est_DWORK1, 1,
      23, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.nu_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.nu_est_DWORK1, 2,
      23, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.nu_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.SP_DWORK1, 0, 23,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.SP_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.SP_DWORK1, 1, 23,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.SP_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.SP_DWORK1, 2, 23,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.SP_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.tau_des_DWORK1, 0,
      23, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.tau_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.tau_des_DWORK1, 1,
      23, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.tau_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.tau_des_DWORK1, 2,
      23, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.tau_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.controller_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.controller_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.timer_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.timer_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.controller, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.controller");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.tmp, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.tmp");
    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.alpha_1_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_DW.EnableThrust_DWORK2, count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_DW.EnableThrust_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.pwm_2_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.pwm_2_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.pwm_3_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.pwm_3_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.pwm_4_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.pwm_4_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.pwm_5_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.pwm_5_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.alpha_2_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.pwm_6_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.pwm_6_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.alpha_3_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.alpha_4_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.alpha_5_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.alpha_6_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.wave_dir_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.wave_dir_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.fzp_x_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.fzp_x_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.fzp_y_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.fzp_y_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.r_max_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.r_max_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_DW.Core_controller_DWORK2, count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_DW.Core_controller_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_i_y_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_i_y_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_d_psi_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_d_psi_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_d_x_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_d_x_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_d_y_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_d_y_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_i_psi_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_i_psi_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_i_x_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_i_x_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_p_psi_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_p_psi_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_p_x_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_p_x_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_p_y_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_p_y_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_d_psi1_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_d_psi1_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_d_x1_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_d_x1_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_d_y1_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_d_y1_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_i_psi1_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_i_psi1_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_i_x1_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_i_x1_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_i_y1_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_i_y1_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_p_psi1_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_p_psi1_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_p_x1_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_p_x1_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.K_p_y1_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.K_p_y1_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.u_1_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.u_1_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.u_4_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.u_4_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.u_5_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.u_5_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.u_6_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.u_6_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.u_2_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.u_2_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.u_3_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.u_3_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.pwm_1_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.pwm_1_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_DW.tau_actual_DWORK2, count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_DW.tau_actual_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.x_m_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.x_m_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.y_m_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.y_m_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.psi_m_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.eta_est_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.eta_est_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.nu_est_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.nu_est_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.SP_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.SP_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.tau_des_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.tau_des_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_student_DW.controller_DWORK2, count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_student_DW.controller_DWORK2");
    }

    for (count = 0; count < 13; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_student_DW.timer_DWORK2,
        count, 22, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_student_DW.timer_DWORK2");
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
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator_CSTATE_l), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator_CSTATE_l), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.TransferFcn2_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator_CSTATE_g), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator_CSTATE_g), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator_CSTATE_g), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator4_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator4_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator4_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator_CSTATE_k), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator_CSTATE_k), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator_CSTATE_k), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator1_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator1_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator1_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator2_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator2_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator2_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator3_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator3_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator3_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_student_X.Integrator_CSTATE_d), 0,
      contStates[idx++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_student_DW.Delay_DSTATE, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.alpha_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.EnableThrust_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.pwm_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.pwm_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.pwm_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.pwm_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.alpha_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.pwm_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.alpha_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.alpha_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.alpha_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.alpha_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.wave_dir_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.fzp_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.fzp_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.r_max_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.Core_controller_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_i_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_d_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_d_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_d_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_i_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_i_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_p_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_p_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_p_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_d_psi1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_d_x1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_d_y1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_i_psi1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_i_x1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_i_y1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_p_psi1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_p_x1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.K_p_y1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.u_1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_student_DW.u_4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_student_DW.u_5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_student_DW.u_6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_student_DW.u_2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_student_DW.u_3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_student_DW.pwm_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.tau_actual_DWORK1, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.tau_actual_DWORK1, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.tau_actual_DWORK1, 2,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.x_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_student_DW.y_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_student_DW.psi_m_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.eta_est_DWORK1, 0, discStates[idx++],
      23, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.eta_est_DWORK1, 1, discStates[idx++],
      23, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.eta_est_DWORK1, 2, discStates[idx++],
      23, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.nu_est_DWORK1, 0, discStates[idx++],
      23, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.nu_est_DWORK1, 1, discStates[idx++],
      23, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.nu_est_DWORK1, 2, discStates[idx++],
      23, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.SP_DWORK1, 0, discStates[idx++], 23,
      0);
    NIRT_SetValueByDataType(&ctrl_student_DW.SP_DWORK1, 1, discStates[idx++], 23,
      0);
    NIRT_SetValueByDataType(&ctrl_student_DW.SP_DWORK1, 2, discStates[idx++], 23,
      0);
    NIRT_SetValueByDataType(&ctrl_student_DW.tau_des_DWORK1, 0, discStates[idx++],
      23, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.tau_des_DWORK1, 1, discStates[idx++],
      23, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.tau_des_DWORK1, 2, discStates[idx++],
      23, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.controller_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.timer_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_student_DW.controller, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_student_DW.tmp, 0, discStates[idx++], 0, 0);
    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.alpha_1_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.EnableThrust_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.pwm_2_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.pwm_3_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.pwm_4_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.pwm_5_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.alpha_2_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.pwm_6_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.alpha_3_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.alpha_4_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.alpha_5_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.alpha_6_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.wave_dir_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.fzp_x_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.fzp_y_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.r_max_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.Core_controller_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_i_y_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_d_psi_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_d_x_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_d_y_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_i_psi_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_i_x_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_p_psi_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_p_x_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_p_y_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_d_psi1_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_d_x1_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_d_y1_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_i_psi1_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_i_x1_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_i_y1_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_p_psi1_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_p_x1_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.K_p_y1_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.u_1_DWORK2, count, discStates[idx
        ++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.u_4_DWORK2, count, discStates[idx
        ++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.u_5_DWORK2, count, discStates[idx
        ++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.u_6_DWORK2, count, discStates[idx
        ++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.u_2_DWORK2, count, discStates[idx
        ++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.u_3_DWORK2, count, discStates[idx
        ++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.pwm_1_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.tau_actual_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.x_m_DWORK2, count, discStates[idx
        ++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.y_m_DWORK2, count, discStates[idx
        ++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.psi_m_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.eta_est_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.nu_est_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.SP_DWORK2, count, discStates[idx
        ++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.tau_des_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.controller_DWORK2, count,
        discStates[idx++], 22, 0);
    }

    for (count = 0; count < 13; count++) {
      NIRT_SetValueByDataType(&ctrl_student_DW.timer_DWORK2, count,
        discStates[idx++], 22, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_student
