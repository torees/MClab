/*
 * u2pwm.c
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

#include "u2pwm.h"
#include "u2pwm_private.h"

/* Block signals (auto storage) */
B_u2pwm_T u2pwm_B;

/* Continuous states */
X_u2pwm_T u2pwm_X;

/* Block states (auto storage) */
DW_u2pwm_T u2pwm_DW;

/* Real-time model */
RT_MODEL_u2pwm_T u2pwm_M_;
RT_MODEL_u2pwm_T *const u2pwm_M = &u2pwm_M_;

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
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  u2pwm_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  u2pwm_output();
  u2pwm_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  u2pwm_output();
  u2pwm_derivatives();

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
 *    '<S12>/MATLAB Function13'
 *    '<S12>/MATLAB Function14'
 *    '<S12>/MATLAB Function15'
 *    '<S12>/MATLAB Function16'
 *    '<S12>/MATLAB Function17'
 *    '<S12>/MATLAB Function18'
 */
void u2pwm_MATLABFunction13(real_T rtu_u, B_MATLABFunction13_u2pwm_T *localB)
{
  /* MATLAB Function 'u2pwm/MATLAB Function13': '<S18>:1' */
  if (rtu_u == 7.5) {
    /* '<S18>:1:3' */
    /* '<S18>:1:4' */
    localB->y = 7.5;
  } else if (rtu_u < 7.5) {
    /* '<S18>:1:5' */
    /* '<S18>:1:6' */
    localB->y = rtu_u - 0.31;
  } else {
    /* '<S18>:1:8' */
    localB->y = rtu_u + 0.31;
  }
}

/*
 * Output and update for atomic system:
 *    '<S13>/MATLAB Function'
 *    '<S13>/MATLAB Function1'
 *    '<S13>/MATLAB Function10'
 *    '<S13>/MATLAB Function3'
 *    '<S13>/MATLAB Function6'
 *    '<S13>/MATLAB Function8'
 */
void u2pwm_MATLABFunction(real_T rtu_u_pre, real_T rtu_u,
  B_MATLABFunction_u2pwm_T *localB)
{
  /* MATLAB Function 'wrapping/MATLAB Function': '<S25>:1' */
  if (fabs(rtu_u - rtu_u_pre) > 180.0) {
    /* '<S25>:1:4' */
    /* '<S25>:1:5' */
    localB->y = rtu_u_pre;
  } else {
    /* '<S25>:1:7' */
    localB->y = rtu_u;
  }
}

/*
 * Output and update for atomic system:
 *    '<S13>/MATLAB Function11'
 *    '<S13>/MATLAB Function2'
 *    '<S13>/MATLAB Function4'
 *    '<S13>/MATLAB Function5'
 *    '<S13>/MATLAB Function7'
 *    '<S13>/MATLAB Function9'
 */
void u2pwm_MATLABFunction11(real_T rtu_angle_d, real_T rtu_angle,
  B_MATLABFunction11_u2pwm_T *localB)
{
  real_T theta_tilde;

  /* MATLAB Function 'wrapping/MATLAB Function11': '<S28>:1' */
  /* '<S28>:1:4' */
  /*  current rotation */
  /* '<S28>:1:6' */
  if (rtu_angle < 0.0) {
    theta_tilde = -1.0;
  } else if (rtu_angle > 0.0) {
    theta_tilde = 1.0;
  } else if (rtu_angle == 0.0) {
    theta_tilde = 0.0;
  } else {
    theta_tilde = rtu_angle;
  }

  localB->angle_out = floor((fabs(rtu_angle) + 180.0) / 360.0) * theta_tilde *
    360.0 + rtu_angle_d;

  /* '<S28>:1:8' */
  theta_tilde = localB->angle_out - rtu_angle;
  if (fabs(theta_tilde) > 180.0) {
    /* '<S28>:1:10' */
    /* '<S28>:1:11' */
    if (theta_tilde < 0.0) {
      theta_tilde = -1.0;
    } else if (theta_tilde > 0.0) {
      theta_tilde = 1.0;
    } else {
      if (theta_tilde == 0.0) {
        theta_tilde = 0.0;
      }
    }

    localB->angle_out -= theta_tilde * 360.0;
  }
}

/* Model output function */
void u2pwm_output(void)
{
  /* local block i/o variables */
  real_T rtb_Gain6;
  real_T rtb_Gain7;
  real_T rtb_Gain8;
  real_T rtb_Gain9;
  real_T rtb_Gain10;
  real_T rtb_Gain11;
  real_T rtb_Sum2;
  real_T rtb_Sum3;
  real_T rtb_Sum1;
  real_T rtb_Sum4;
  real_T rtb_Sum5;
  real_T rtb_Sum6;
  real_T b_signal;
  real_T rtb_MultiportSwitch_idx_0;
  real_T rtb_MultiportSwitch_idx_1;
  real_T rtb_MultiportSwitch_idx_2;
  real_T rtb_MultiportSwitch_idx_3;
  real_T rtb_MultiportSwitch_idx_4;
  real_T rtb_MultiportSwitch_idx_5;
  real_T rtb_MultiportSwitch_idx_6;
  real_T rtb_MultiportSwitch_idx_7;
  real_T rtb_MultiportSwitch_idx_8;
  real_T rtb_MultiportSwitch_idx_9;
  real_T rtb_MultiportSwitch_idx_10;
  real_T rtb_MultiportSwitch_idx_11;
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  real_T rtb_Switch_idx_2;
  real_T rtb_Switch_idx_3;
  real_T rtb_Switch_idx_4;
  real_T rtb_Switch_idx_5;
  real_T rtb_Switch_idx_7;
  real_T rtb_Switch_idx_8;
  real_T rtb_Switch_idx_9;
  real_T rtb_Switch_idx_10;
  real_T rtb_Switch_idx_11;
  if (rtmIsMajorTimeStep(u2pwm_M)) {
    /* set solver stop time */
    if (!(u2pwm_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&u2pwm_M->solverInfo, ((u2pwm_M->Timing.clockTickH0
        + 1) * u2pwm_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&u2pwm_M->solverInfo, ((u2pwm_M->Timing.clockTick0 +
        1) * u2pwm_M->Timing.stepSize0 + u2pwm_M->Timing.clockTickH0 *
        u2pwm_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(u2pwm_M)) {
    u2pwm_M->Timing.t[0] = rtsiGetT(&u2pwm_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(u2pwm_M)) {
    /* Memory: '<S2>/Memory' */
    u2pwm_B.Memory = u2pwm_DW.Memory_PreviousInput;
  }

  /* MATLAB Function: '<S2>/Switch_function' */
  /* MATLAB Function 'Switch_subsystem/Switch_function': '<S14>:1' */
  /*  Function that takes in impulse button sigals [0,1] and sends out a  */
  /*  different signal depentent pn which button has been pressed */
  /* '<S14>:1:8' */
  b_signal = u2pwm_B.Memory;
  if (u2pwm_B.Cross1 != 0.0) {
    /* '<S14>:1:10' */
    /* '<S14>:1:11' */
    b_signal = 1.0;
  }

  if (u2pwm_B.Square1 != 0.0) {
    /* '<S14>:1:14' */
    /* '<S14>:1:15' */
    b_signal = 2.0;
  }

  if (u2pwm_B.Circle1 != 0.0) {
    /* '<S14>:1:18' */
    /* '<S14>:1:19' */
    b_signal = 3.0;
  }

  if (u2pwm_B.Triangle1 != 0.0) {
    /* '<S14>:1:22' */
    /* '<S14>:1:23' */
    b_signal = 4.0;
  }

  /* '<S14>:1:26' */
  u2pwm_B.switch_signal = b_signal;

  /* End of MATLAB Function: '<S2>/Switch_function' */

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant10'
   *  Constant: '<S1>/Constant11'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S1>/Constant7'
   *  Constant: '<S1>/Constant8'
   *  Constant: '<S1>/Constant9'
   */
  switch ((int32_T)u2pwm_B.switch_signal) {
   case 1:
    rtb_MultiportSwitch_idx_0 = u2pwm_B.u_1;
    rtb_MultiportSwitch_idx_1 = u2pwm_B.u_2;
    rtb_MultiportSwitch_idx_2 = u2pwm_B.u_3;
    rtb_MultiportSwitch_idx_3 = u2pwm_B.u_4;
    rtb_MultiportSwitch_idx_4 = u2pwm_B.u_5;
    rtb_MultiportSwitch_idx_5 = u2pwm_B.u_6;
    rtb_MultiportSwitch_idx_6 = u2pwm_B.alpha_1;
    rtb_MultiportSwitch_idx_7 = u2pwm_B.alpha_2;
    rtb_MultiportSwitch_idx_8 = u2pwm_B.alpha_3;
    rtb_MultiportSwitch_idx_9 = u2pwm_B.alpha_4;
    rtb_MultiportSwitch_idx_10 = u2pwm_B.alpha_5;
    rtb_MultiportSwitch_idx_11 = u2pwm_B.alpha_6;
    break;

   case 2:
    rtb_MultiportSwitch_idx_0 = u2pwm_B.u_1_i;
    rtb_MultiportSwitch_idx_1 = u2pwm_B.u_2_g;
    rtb_MultiportSwitch_idx_2 = u2pwm_B.u_3_k;
    rtb_MultiportSwitch_idx_3 = u2pwm_B.u_4_a;
    rtb_MultiportSwitch_idx_4 = u2pwm_B.u_5_l;
    rtb_MultiportSwitch_idx_5 = u2pwm_B.u_6_e;
    rtb_MultiportSwitch_idx_6 = u2pwm_B.alpha_1_e;
    rtb_MultiportSwitch_idx_7 = u2pwm_B.alpha_2_d;
    rtb_MultiportSwitch_idx_8 = u2pwm_B.alpha_3_m;
    rtb_MultiportSwitch_idx_9 = u2pwm_B.alpha_4_m;
    rtb_MultiportSwitch_idx_10 = u2pwm_B.alpha_5_g;
    rtb_MultiportSwitch_idx_11 = u2pwm_B.alpha_6_b;
    break;

   case 3:
    rtb_MultiportSwitch_idx_0 = u2pwm_P.Constant_Value;
    rtb_MultiportSwitch_idx_1 = u2pwm_P.Constant1_Value;
    rtb_MultiportSwitch_idx_2 = u2pwm_P.Constant2_Value;
    rtb_MultiportSwitch_idx_3 = u2pwm_P.Constant3_Value;
    rtb_MultiportSwitch_idx_4 = u2pwm_P.Constant4_Value;
    rtb_MultiportSwitch_idx_5 = u2pwm_P.Constant5_Value;
    rtb_MultiportSwitch_idx_6 = u2pwm_P.Constant6_Value;
    rtb_MultiportSwitch_idx_7 = u2pwm_P.Constant7_Value;
    rtb_MultiportSwitch_idx_8 = u2pwm_P.Constant8_Value;
    rtb_MultiportSwitch_idx_9 = u2pwm_P.Constant9_Value;
    rtb_MultiportSwitch_idx_10 = u2pwm_P.Constant10_Value;
    rtb_MultiportSwitch_idx_11 = u2pwm_P.Constant11_Value;
    break;

   default:
    rtb_MultiportSwitch_idx_0 = u2pwm_B.u_1_b;
    rtb_MultiportSwitch_idx_1 = u2pwm_B.u_2_a;
    rtb_MultiportSwitch_idx_2 = u2pwm_B.u_3_kf;
    rtb_MultiportSwitch_idx_3 = u2pwm_B.u_4_j;
    rtb_MultiportSwitch_idx_4 = u2pwm_B.u_5_n;
    rtb_MultiportSwitch_idx_5 = u2pwm_B.u_6_b;
    rtb_MultiportSwitch_idx_6 = u2pwm_B.alpha_1_d;
    rtb_MultiportSwitch_idx_7 = u2pwm_B.alpha_2_c;
    rtb_MultiportSwitch_idx_8 = u2pwm_B.alpha_3_b;
    rtb_MultiportSwitch_idx_9 = u2pwm_B.alpha_4_k;
    rtb_MultiportSwitch_idx_10 = u2pwm_B.alpha_5_i;
    rtb_MultiportSwitch_idx_11 = u2pwm_B.alpha_6_f;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* MATLAB Function: '<Root>/control limit checking' */
  /* MATLAB Function 'control limit checking': '<S4>:1' */
  /* '<S4>:1:2' */
  /* '<S4>:1:3' */
  /* '<S4>:1:4' */
  /* '<S4>:1:5' */
  /* '<S4>:1:6' */
  /* '<S4>:1:7' */
  /* '<S4>:1:9' */
  /* '<S4>:1:16' */
  u2pwm_B.fault = !((-1.0 <= rtb_MultiportSwitch_idx_0) &&
                    (rtb_MultiportSwitch_idx_0 <= 1.0) && (-1.0 <=
    rtb_MultiportSwitch_idx_1) && (rtb_MultiportSwitch_idx_1 <= 1.0) && (-1.0 <=
    rtb_MultiportSwitch_idx_2) && (rtb_MultiportSwitch_idx_2 <= 1.0) && (-1.0 <=
    rtb_MultiportSwitch_idx_3) && (rtb_MultiportSwitch_idx_3 <= 1.0) && (-1.0 <=
    rtb_MultiportSwitch_idx_4) && (rtb_MultiportSwitch_idx_4 <= 1.0) && (-1.0 <=
    rtb_MultiportSwitch_idx_5) && (rtb_MultiportSwitch_idx_5 <= 1.0));

  /* MATLAB Function: '<S9>/C' */
  /* MATLAB Function 'indicator/C': '<S17>:1' */
  /* '<S17>:1:3' */
  u2pwm_B.ctrl_sixaxis2thruster = false;

  /* '<S17>:1:4' */
  u2pwm_B.ctrl_DP = false;

  /* '<S17>:1:5' */
  u2pwm_B.STOP = false;

  /* '<S17>:1:6' */
  u2pwm_B.ctrl_custom = false;
  if (u2pwm_B.switch_signal == 1.0) {
    /* '<S17>:1:8' */
    /* '<S17>:1:9' */
    u2pwm_B.ctrl_custom = true;
  } else if (u2pwm_B.switch_signal == 2.0) {
    /* '<S17>:1:10' */
    /* '<S17>:1:11' */
    u2pwm_B.ctrl_DP = true;
  } else if (u2pwm_B.switch_signal == 3.0) {
    /* '<S17>:1:12' */
    /* '<S17>:1:13' */
    u2pwm_B.STOP = true;
  } else {
    if (u2pwm_B.switch_signal == 4.0) {
      /* '<S17>:1:14' */
      /* '<S17>:1:15' */
      u2pwm_B.ctrl_sixaxis2thruster = true;
    }
  }

  /* End of MATLAB Function: '<S9>/C' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Integrator: '<S8>/Integrator'
   *  Integrator: '<S8>/Integrator1'
   *  Integrator: '<S8>/Integrator10'
   *  Integrator: '<S8>/Integrator11'
   *  Integrator: '<S8>/Integrator2'
   *  Integrator: '<S8>/Integrator3'
   *  Integrator: '<S8>/Integrator4'
   *  Integrator: '<S8>/Integrator5'
   *  Integrator: '<S8>/Integrator6'
   *  Integrator: '<S8>/Integrator7'
   *  Integrator: '<S8>/Integrator8'
   *  Integrator: '<S8>/Integrator9'
   */
  if (u2pwm_B.mechelecenable != 0.0) {
    rtb_Switch_idx_0 = u2pwm_X.Integrator6_CSTATE;
    rtb_Switch_idx_1 = u2pwm_X.Integrator5_CSTATE;
    rtb_Switch_idx_2 = u2pwm_X.Integrator4_CSTATE;
    rtb_Switch_idx_3 = u2pwm_X.Integrator3_CSTATE;
    rtb_Switch_idx_4 = u2pwm_X.Integrator2_CSTATE;
    rtb_Switch_idx_5 = u2pwm_X.Integrator1_CSTATE;
    b_signal = u2pwm_X.Integrator_CSTATE;
    rtb_Switch_idx_7 = u2pwm_X.Integrator7_CSTATE;
    rtb_Switch_idx_8 = u2pwm_X.Integrator8_CSTATE;
    rtb_Switch_idx_9 = u2pwm_X.Integrator9_CSTATE;
    rtb_Switch_idx_10 = u2pwm_X.Integrator10_CSTATE;
    rtb_Switch_idx_11 = u2pwm_X.Integrator11_CSTATE;
  } else {
    rtb_Switch_idx_0 = rtb_MultiportSwitch_idx_0;
    rtb_Switch_idx_1 = rtb_MultiportSwitch_idx_1;
    rtb_Switch_idx_2 = rtb_MultiportSwitch_idx_2;
    rtb_Switch_idx_3 = rtb_MultiportSwitch_idx_3;
    rtb_Switch_idx_4 = rtb_MultiportSwitch_idx_4;
    rtb_Switch_idx_5 = rtb_MultiportSwitch_idx_5;
    b_signal = rtb_MultiportSwitch_idx_6;
    rtb_Switch_idx_7 = rtb_MultiportSwitch_idx_7;
    rtb_Switch_idx_8 = rtb_MultiportSwitch_idx_8;
    rtb_Switch_idx_9 = rtb_MultiportSwitch_idx_9;
    rtb_Switch_idx_10 = rtb_MultiportSwitch_idx_10;
    rtb_Switch_idx_11 = rtb_MultiportSwitch_idx_11;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Gain: '<S13>/Gain6' */
  rtb_Gain6 = u2pwm_P.Gain6_Gain * b_signal;

  /* Gain: '<S13>/Gain7' */
  rtb_Gain7 = u2pwm_P.Gain7_Gain * rtb_Switch_idx_7;

  /* Gain: '<S13>/Gain8' */
  rtb_Gain8 = u2pwm_P.Gain8_Gain * rtb_Switch_idx_8;

  /* Gain: '<S13>/Gain9' */
  rtb_Gain9 = u2pwm_P.Gain9_Gain * rtb_Switch_idx_9;

  /* Gain: '<S13>/Gain10' */
  rtb_Gain10 = u2pwm_P.Gain10_Gain * rtb_Switch_idx_10;

  /* Gain: '<S13>/Gain11' */
  rtb_Gain11 = u2pwm_P.Gain11_Gain * rtb_Switch_idx_11;
  if (rtmIsMajorTimeStep(u2pwm_M)) {
    /* Memory: '<S13>/Memory5' */
    u2pwm_B.Memory5 = u2pwm_DW.Memory5_PreviousInput;
  }

  /* MATLAB Function: '<S13>/MATLAB Function11' */
  u2pwm_MATLABFunction11(rtb_Gain6, u2pwm_B.alpha_deg_1,
    &u2pwm_B.sf_MATLABFunction11);

  /* MATLAB Function: '<S13>/MATLAB Function10' */
  u2pwm_MATLABFunction(u2pwm_B.Memory5, u2pwm_B.sf_MATLABFunction11.angle_out,
                       &u2pwm_B.sf_MATLABFunction10);
  if (rtmIsMajorTimeStep(u2pwm_M)) {
    /* Memory: '<S13>/Memory4' */
    u2pwm_B.Memory4 = u2pwm_DW.Memory4_PreviousInput;
  }

  /* MATLAB Function: '<S13>/MATLAB Function9' */
  u2pwm_MATLABFunction11(rtb_Gain7, u2pwm_B.alpha_deg_2,
    &u2pwm_B.sf_MATLABFunction9);

  /* MATLAB Function: '<S13>/MATLAB Function8' */
  u2pwm_MATLABFunction(u2pwm_B.Memory4, u2pwm_B.sf_MATLABFunction9.angle_out,
                       &u2pwm_B.sf_MATLABFunction8);
  if (rtmIsMajorTimeStep(u2pwm_M)) {
    /* Memory: '<S13>/Memory3' */
    u2pwm_B.Memory3 = u2pwm_DW.Memory3_PreviousInput;
  }

  /* MATLAB Function: '<S13>/MATLAB Function7' */
  u2pwm_MATLABFunction11(rtb_Gain8, u2pwm_B.alpha_deg_3,
    &u2pwm_B.sf_MATLABFunction7);

  /* MATLAB Function: '<S13>/MATLAB Function6' */
  u2pwm_MATLABFunction(u2pwm_B.Memory3, u2pwm_B.sf_MATLABFunction7.angle_out,
                       &u2pwm_B.sf_MATLABFunction6);
  if (rtmIsMajorTimeStep(u2pwm_M)) {
    /* Memory: '<S13>/Memory2' */
    u2pwm_B.Memory2 = u2pwm_DW.Memory2_PreviousInput;
  }

  /* MATLAB Function: '<S13>/MATLAB Function4' */
  u2pwm_MATLABFunction11(rtb_Gain9, u2pwm_B.alpha_deg_4,
    &u2pwm_B.sf_MATLABFunction4);

  /* MATLAB Function: '<S13>/MATLAB Function3' */
  u2pwm_MATLABFunction(u2pwm_B.Memory2, u2pwm_B.sf_MATLABFunction4.angle_out,
                       &u2pwm_B.sf_MATLABFunction3);
  if (rtmIsMajorTimeStep(u2pwm_M)) {
    /* Memory: '<S13>/Memory' */
    u2pwm_B.Memory_f = u2pwm_DW.Memory_PreviousInput_p;
  }

  /* MATLAB Function: '<S13>/MATLAB Function5' */
  u2pwm_MATLABFunction11(rtb_Gain10, u2pwm_B.alpha_deg_5,
    &u2pwm_B.sf_MATLABFunction5);

  /* MATLAB Function: '<S13>/MATLAB Function' */
  u2pwm_MATLABFunction(u2pwm_B.Memory_f, u2pwm_B.sf_MATLABFunction5.angle_out,
                       &u2pwm_B.sf_MATLABFunction);
  if (rtmIsMajorTimeStep(u2pwm_M)) {
    /* Memory: '<S13>/Memory1' */
    u2pwm_B.Memory1 = u2pwm_DW.Memory1_PreviousInput;
  }

  /* MATLAB Function: '<S13>/MATLAB Function2' */
  u2pwm_MATLABFunction11(rtb_Gain11, u2pwm_B.alpha_deg_6,
    &u2pwm_B.sf_MATLABFunction2);

  /* MATLAB Function: '<S13>/MATLAB Function1' */
  u2pwm_MATLABFunction(u2pwm_B.Memory1, u2pwm_B.sf_MATLABFunction2.angle_out,
                       &u2pwm_B.sf_MATLABFunction1);

  /* Switch: '<S13>/Switch1' */
  if (u2pwm_B.nowrapping != 0.0) {
    b_signal = rtb_Gain6;
    rtb_Switch_idx_9 = rtb_Gain7;
    rtb_Switch_idx_11 = rtb_Gain8;
    rtb_Switch_idx_10 = rtb_Gain9;
    rtb_Switch_idx_8 = rtb_Gain10;
    rtb_Switch_idx_7 = rtb_Gain11;
  } else {
    b_signal = u2pwm_B.sf_MATLABFunction10.y;
    rtb_Switch_idx_9 = u2pwm_B.sf_MATLABFunction8.y;
    rtb_Switch_idx_11 = u2pwm_B.sf_MATLABFunction6.y;
    rtb_Switch_idx_10 = u2pwm_B.sf_MATLABFunction3.y;
    rtb_Switch_idx_8 = u2pwm_B.sf_MATLABFunction.y;
    rtb_Switch_idx_7 = u2pwm_B.sf_MATLABFunction1.y;
  }

  /* End of Switch: '<S13>/Switch1' */

  /* Sum: '<S3>/Sum12' incorporates:
   *  Constant: '<S3>/alpha_Offset'
   */
  b_signal += u2pwm_P.zero_alpha_1;

  /* Sum: '<S3>/Sum13' incorporates:
   *  Constant: '<S3>/alpha_Offset1'
   */
  rtb_Switch_idx_9 += u2pwm_P.zero_alpha_2;

  /* Sum: '<S3>/Sum11' incorporates:
   *  Constant: '<S3>/alpha_Offset2'
   */
  rtb_Switch_idx_11 += u2pwm_P.zero_alpha_3;

  /* Sum: '<S3>/Sum8' incorporates:
   *  Constant: '<S3>/alpha_Offset3'
   */
  rtb_Switch_idx_10 += u2pwm_P.zero_alpha_4;

  /* Sum: '<S3>/Sum9' incorporates:
   *  Constant: '<S3>/alpha_Offset4'
   */
  rtb_Switch_idx_8 += u2pwm_P.zero_alpha_5;

  /* Sum: '<S3>/Sum10' incorporates:
   *  Constant: '<S3>/alpha_Offset5'
   */
  rtb_Switch_idx_7 += u2pwm_P.zero_alpha_6;

  /* MATLAB Function: '<S3>/MATLAB Function12' incorporates:
   *  SignalConversion: '<S15>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'alpha2pwm/MATLAB Function12': '<S15>:1' */
  /* '<S15>:1:3' */
  if ((b_signal > 3200.0) || (b_signal < -9000.0)) {
    /* '<S15>:1:5' */
    /* '<S15>:1:6' */
    u2pwm_B.y = 1.0;
  } else if ((rtb_Switch_idx_9 > 9000.0) || (rtb_Switch_idx_9 < -9000.0)) {
    /* '<S15>:1:7' */
    /* '<S15>:1:8' */
    u2pwm_B.y = 1.0;
  } else if ((rtb_Switch_idx_11 > 9000.0) || (rtb_Switch_idx_11 < -9000.0)) {
    /* '<S15>:1:9' */
    /* '<S15>:1:10' */
    u2pwm_B.y = 1.0;
  } else if ((rtb_Switch_idx_10 > 9000.0) || (rtb_Switch_idx_10 < -9000.0)) {
    /* '<S15>:1:11' */
    /* '<S15>:1:12' */
    u2pwm_B.y = 1.0;
  } else if ((rtb_Switch_idx_8 > 9000.0) || (rtb_Switch_idx_8 < -9000.0)) {
    /* '<S15>:1:13' */
    /* '<S15>:1:14' */
    u2pwm_B.y = 1.0;
  } else if ((rtb_Switch_idx_7 > 9000.0) || (rtb_Switch_idx_7 < -9000.0)) {
    /* '<S15>:1:15' */
    /* '<S15>:1:16' */
    u2pwm_B.y = 1.0;
  } else {
    /* '<S15>:1:18' */
    u2pwm_B.y = 0.0;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function12' */

  /* Switch: '<S3>/Switch2' */
  if (u2pwm_B.manualoverridealpha != 0.0) {
    u2pwm_B.Switch2[0] = u2pwm_B.man_alpha_1;
    u2pwm_B.Switch2[1] = u2pwm_B.man_alpha_2;
    u2pwm_B.Switch2[2] = u2pwm_B.man_alpha_3;
    u2pwm_B.Switch2[3] = u2pwm_B.man_alpha_4;
    u2pwm_B.Switch2[4] = u2pwm_B.man_alpha_5;
    u2pwm_B.Switch2[5] = u2pwm_B.man_alpha_6;
  } else {
    u2pwm_B.Switch2[0] = b_signal;
    u2pwm_B.Switch2[1] = rtb_Switch_idx_9;
    u2pwm_B.Switch2[2] = rtb_Switch_idx_11;
    u2pwm_B.Switch2[3] = rtb_Switch_idx_10;
    u2pwm_B.Switch2[4] = rtb_Switch_idx_8;
    u2pwm_B.Switch2[5] = rtb_Switch_idx_7;
  }

  /* End of Switch: '<S3>/Switch2' */

  /* Saturate: '<S12>/Saturation11' */
  if (rtb_Switch_idx_0 > u2pwm_P.Saturation11_UpperSat) {
    rtb_Switch_idx_0 = u2pwm_P.Saturation11_UpperSat;
  } else {
    if (rtb_Switch_idx_0 < u2pwm_P.Saturation11_LowerSat) {
      rtb_Switch_idx_0 = u2pwm_P.Saturation11_LowerSat;
    }
  }

  /* End of Saturate: '<S12>/Saturation11' */

  /* Sum: '<S12>/Sum2' incorporates:
   *  Constant: '<S12>/PWM_Offset'
   *  Gain: '<S12>/Gain'
   */
  rtb_Sum2 = u2pwm_P.Gain_Gain * rtb_Switch_idx_0 + u2pwm_P.zero_pwm;

  /* MATLAB Function: '<S12>/MATLAB Function13' */
  u2pwm_MATLABFunction13(rtb_Sum2, &u2pwm_B.sf_MATLABFunction13);

  /* Saturate: '<S12>/Saturation10' */
  if (rtb_Switch_idx_1 > u2pwm_P.Saturation10_UpperSat) {
    rtb_Switch_idx_1 = u2pwm_P.Saturation10_UpperSat;
  } else {
    if (rtb_Switch_idx_1 < u2pwm_P.Saturation10_LowerSat) {
      rtb_Switch_idx_1 = u2pwm_P.Saturation10_LowerSat;
    }
  }

  /* End of Saturate: '<S12>/Saturation10' */

  /* Sum: '<S12>/Sum3' incorporates:
   *  Constant: '<S12>/PWM_Offset1'
   *  Gain: '<S12>/Gain1'
   */
  rtb_Sum3 = u2pwm_P.Gain1_Gain * rtb_Switch_idx_1 + u2pwm_P.zero_pwm;

  /* MATLAB Function: '<S12>/MATLAB Function18' */
  u2pwm_MATLABFunction13(rtb_Sum3, &u2pwm_B.sf_MATLABFunction18);

  /* Saturate: '<S12>/Saturation9' */
  if (rtb_Switch_idx_2 > u2pwm_P.Saturation9_UpperSat) {
    rtb_Switch_idx_2 = u2pwm_P.Saturation9_UpperSat;
  } else {
    if (rtb_Switch_idx_2 < u2pwm_P.Saturation9_LowerSat) {
      rtb_Switch_idx_2 = u2pwm_P.Saturation9_LowerSat;
    }
  }

  /* End of Saturate: '<S12>/Saturation9' */

  /* Sum: '<S12>/Sum1' incorporates:
   *  Constant: '<S12>/PWM_Offset2'
   *  Gain: '<S12>/Gain2'
   */
  rtb_Sum1 = u2pwm_P.Gain2_Gain * rtb_Switch_idx_2 + u2pwm_P.zero_pwm;

  /* MATLAB Function: '<S12>/MATLAB Function17' */
  u2pwm_MATLABFunction13(rtb_Sum1, &u2pwm_B.sf_MATLABFunction17);

  /* Saturate: '<S12>/Saturation8' */
  if (rtb_Switch_idx_3 > u2pwm_P.Saturation8_UpperSat) {
    rtb_Switch_idx_3 = u2pwm_P.Saturation8_UpperSat;
  } else {
    if (rtb_Switch_idx_3 < u2pwm_P.Saturation8_LowerSat) {
      rtb_Switch_idx_3 = u2pwm_P.Saturation8_LowerSat;
    }
  }

  /* End of Saturate: '<S12>/Saturation8' */

  /* Sum: '<S12>/Sum4' incorporates:
   *  Constant: '<S12>/PWM_Offset3'
   *  Gain: '<S12>/Gain3'
   */
  rtb_Sum4 = u2pwm_P.Gain3_Gain * rtb_Switch_idx_3 + u2pwm_P.zero_pwm;

  /* MATLAB Function: '<S12>/MATLAB Function14' */
  u2pwm_MATLABFunction13(rtb_Sum4, &u2pwm_B.sf_MATLABFunction14);

  /* Saturate: '<S12>/Saturation7' */
  if (rtb_Switch_idx_4 > u2pwm_P.Saturation7_UpperSat) {
    rtb_Switch_idx_4 = u2pwm_P.Saturation7_UpperSat;
  } else {
    if (rtb_Switch_idx_4 < u2pwm_P.Saturation7_LowerSat) {
      rtb_Switch_idx_4 = u2pwm_P.Saturation7_LowerSat;
    }
  }

  /* End of Saturate: '<S12>/Saturation7' */

  /* Sum: '<S12>/Sum5' incorporates:
   *  Constant: '<S12>/PWM_Offset4'
   *  Gain: '<S12>/Gain4'
   */
  rtb_Sum5 = u2pwm_P.Gain4_Gain * rtb_Switch_idx_4 + u2pwm_P.zero_pwm;

  /* MATLAB Function: '<S12>/MATLAB Function15' */
  u2pwm_MATLABFunction13(rtb_Sum5, &u2pwm_B.sf_MATLABFunction15);

  /* Saturate: '<S12>/Saturation6' */
  if (rtb_Switch_idx_5 > u2pwm_P.Saturation6_UpperSat) {
    rtb_Switch_idx_5 = u2pwm_P.Saturation6_UpperSat;
  } else {
    if (rtb_Switch_idx_5 < u2pwm_P.Saturation6_LowerSat) {
      rtb_Switch_idx_5 = u2pwm_P.Saturation6_LowerSat;
    }
  }

  /* End of Saturate: '<S12>/Saturation6' */

  /* Sum: '<S12>/Sum6' incorporates:
   *  Constant: '<S12>/PWM_Offset5'
   *  Gain: '<S12>/Gain5'
   */
  rtb_Sum6 = u2pwm_P.Gain5_Gain * rtb_Switch_idx_5 + u2pwm_P.zero_pwm;

  /* MATLAB Function: '<S12>/MATLAB Function16' */
  u2pwm_MATLABFunction13(rtb_Sum6, &u2pwm_B.sf_MATLABFunction16);

  /* Switch: '<S12>/Switch' */
  if (u2pwm_B.manualoverridepwm != 0.0) {
    u2pwm_B.Switch[0] = u2pwm_B.pwm_u_1;
    u2pwm_B.Switch[1] = u2pwm_B.pwm_u_2;
    u2pwm_B.Switch[2] = u2pwm_B.pwm_u_3;
    u2pwm_B.Switch[3] = u2pwm_B.pwm_u_4;
    u2pwm_B.Switch[4] = u2pwm_B.pwm_u_5;
    u2pwm_B.Switch[5] = u2pwm_B.pwm_u_6;
  } else {
    u2pwm_B.Switch[0] = u2pwm_B.sf_MATLABFunction13.y;
    u2pwm_B.Switch[1] = u2pwm_B.sf_MATLABFunction18.y;
    u2pwm_B.Switch[2] = u2pwm_B.sf_MATLABFunction17.y;
    u2pwm_B.Switch[3] = u2pwm_B.sf_MATLABFunction14.y;
    u2pwm_B.Switch[4] = u2pwm_B.sf_MATLABFunction15.y;
    u2pwm_B.Switch[5] = u2pwm_B.sf_MATLABFunction16.y;
  }

  /* End of Switch: '<S12>/Switch' */

  /* Sum: '<S8>/Sum' incorporates:
   *  Integrator: '<S8>/Integrator'
   */
  u2pwm_B.Sum = rtb_MultiportSwitch_idx_6 - u2pwm_X.Integrator_CSTATE;

  /* Sum: '<S8>/Sum1' incorporates:
   *  Integrator: '<S8>/Integrator1'
   */
  u2pwm_B.Sum1 = rtb_MultiportSwitch_idx_5 - u2pwm_X.Integrator1_CSTATE;

  /* Sum: '<S8>/Sum10' incorporates:
   *  Integrator: '<S8>/Integrator10'
   */
  u2pwm_B.Sum10 = rtb_MultiportSwitch_idx_10 - u2pwm_X.Integrator10_CSTATE;

  /* Sum: '<S8>/Sum11' incorporates:
   *  Integrator: '<S8>/Integrator11'
   */
  u2pwm_B.Sum11 = rtb_MultiportSwitch_idx_11 - u2pwm_X.Integrator11_CSTATE;

  /* Sum: '<S8>/Sum2' incorporates:
   *  Integrator: '<S8>/Integrator2'
   */
  u2pwm_B.Sum2 = rtb_MultiportSwitch_idx_4 - u2pwm_X.Integrator2_CSTATE;

  /* Sum: '<S8>/Sum3' incorporates:
   *  Integrator: '<S8>/Integrator3'
   */
  u2pwm_B.Sum3 = rtb_MultiportSwitch_idx_3 - u2pwm_X.Integrator3_CSTATE;

  /* Sum: '<S8>/Sum4' incorporates:
   *  Integrator: '<S8>/Integrator4'
   */
  u2pwm_B.Sum4 = rtb_MultiportSwitch_idx_2 - u2pwm_X.Integrator4_CSTATE;

  /* Sum: '<S8>/Sum5' incorporates:
   *  Integrator: '<S8>/Integrator5'
   */
  u2pwm_B.Sum5 = rtb_MultiportSwitch_idx_1 - u2pwm_X.Integrator5_CSTATE;

  /* Sum: '<S8>/Sum6' incorporates:
   *  Integrator: '<S8>/Integrator6'
   */
  u2pwm_B.Sum6 = rtb_MultiportSwitch_idx_0 - u2pwm_X.Integrator6_CSTATE;

  /* Sum: '<S8>/Sum7' incorporates:
   *  Integrator: '<S8>/Integrator7'
   */
  u2pwm_B.Sum7 = rtb_MultiportSwitch_idx_7 - u2pwm_X.Integrator7_CSTATE;

  /* Sum: '<S8>/Sum8' incorporates:
   *  Integrator: '<S8>/Integrator8'
   */
  u2pwm_B.Sum8 = rtb_MultiportSwitch_idx_8 - u2pwm_X.Integrator8_CSTATE;

  /* Sum: '<S8>/Sum9' incorporates:
   *  Integrator: '<S8>/Integrator9'
   */
  u2pwm_B.Sum9 = rtb_MultiportSwitch_idx_9 - u2pwm_X.Integrator9_CSTATE;
}

/* Model update function */
void u2pwm_update(void)
{
  if (rtmIsMajorTimeStep(u2pwm_M)) {
    /* Update for Memory: '<S2>/Memory' */
    u2pwm_DW.Memory_PreviousInput = u2pwm_B.switch_signal;

    /* Update for Memory: '<S13>/Memory5' */
    u2pwm_DW.Memory5_PreviousInput = u2pwm_B.sf_MATLABFunction10.y;

    /* Update for Memory: '<S13>/Memory4' */
    u2pwm_DW.Memory4_PreviousInput = u2pwm_B.sf_MATLABFunction8.y;

    /* Update for Memory: '<S13>/Memory3' */
    u2pwm_DW.Memory3_PreviousInput = u2pwm_B.sf_MATLABFunction6.y;

    /* Update for Memory: '<S13>/Memory2' */
    u2pwm_DW.Memory2_PreviousInput = u2pwm_B.sf_MATLABFunction3.y;

    /* Update for Memory: '<S13>/Memory' */
    u2pwm_DW.Memory_PreviousInput_p = u2pwm_B.sf_MATLABFunction.y;

    /* Update for Memory: '<S13>/Memory1' */
    u2pwm_DW.Memory1_PreviousInput = u2pwm_B.sf_MATLABFunction1.y;
  }

  if (rtmIsMajorTimeStep(u2pwm_M)) {
    rt_ertODEUpdateContinuousStates(&u2pwm_M->solverInfo);
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
  if (!(++u2pwm_M->Timing.clockTick0)) {
    ++u2pwm_M->Timing.clockTickH0;
  }

  u2pwm_M->Timing.t[0] = rtsiGetSolverStopTime(&u2pwm_M->solverInfo);

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
    if (!(++u2pwm_M->Timing.clockTick1)) {
      ++u2pwm_M->Timing.clockTickH1;
    }

    u2pwm_M->Timing.t[1] = u2pwm_M->Timing.clockTick1 *
      u2pwm_M->Timing.stepSize1 + u2pwm_M->Timing.clockTickH1 *
      u2pwm_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void u2pwm_derivatives(void)
{
  XDot_u2pwm_T *_rtXdot;
  _rtXdot = ((XDot_u2pwm_T *) u2pwm_M->derivs);

  /* Derivatives for Integrator: '<S8>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = u2pwm_B.Sum6;

  /* Derivatives for Integrator: '<S8>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = u2pwm_B.Sum5;

  /* Derivatives for Integrator: '<S8>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = u2pwm_B.Sum4;

  /* Derivatives for Integrator: '<S8>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = u2pwm_B.Sum3;

  /* Derivatives for Integrator: '<S8>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = u2pwm_B.Sum2;

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = u2pwm_B.Sum1;

  /* Derivatives for Integrator: '<S8>/Integrator' */
  _rtXdot->Integrator_CSTATE = u2pwm_B.Sum;

  /* Derivatives for Integrator: '<S8>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = u2pwm_B.Sum7;

  /* Derivatives for Integrator: '<S8>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = u2pwm_B.Sum8;

  /* Derivatives for Integrator: '<S8>/Integrator9' */
  _rtXdot->Integrator9_CSTATE = u2pwm_B.Sum9;

  /* Derivatives for Integrator: '<S8>/Integrator10' */
  _rtXdot->Integrator10_CSTATE = u2pwm_B.Sum10;

  /* Derivatives for Integrator: '<S8>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = u2pwm_B.Sum11;
}

/* Model initialize function */
void u2pwm_initialize(void)
{
  /* InitializeConditions for Memory: '<S2>/Memory' */
  u2pwm_DW.Memory_PreviousInput = u2pwm_P.Memory_X0;

  /* InitializeConditions for Integrator: '<S8>/Integrator6' */
  u2pwm_X.Integrator6_CSTATE = u2pwm_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator5' */
  u2pwm_X.Integrator5_CSTATE = u2pwm_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator4' */
  u2pwm_X.Integrator4_CSTATE = u2pwm_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator3' */
  u2pwm_X.Integrator3_CSTATE = u2pwm_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator2' */
  u2pwm_X.Integrator2_CSTATE = u2pwm_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator1' */
  u2pwm_X.Integrator1_CSTATE = u2pwm_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator' */
  u2pwm_X.Integrator_CSTATE = u2pwm_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator7' */
  u2pwm_X.Integrator7_CSTATE = u2pwm_P.Integrator7_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator8' */
  u2pwm_X.Integrator8_CSTATE = u2pwm_P.Integrator8_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator9' */
  u2pwm_X.Integrator9_CSTATE = u2pwm_P.Integrator9_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator10' */
  u2pwm_X.Integrator10_CSTATE = u2pwm_P.Integrator10_IC;

  /* InitializeConditions for Integrator: '<S8>/Integrator11' */
  u2pwm_X.Integrator11_CSTATE = u2pwm_P.Integrator11_IC;

  /* InitializeConditions for Memory: '<S13>/Memory5' */
  u2pwm_DW.Memory5_PreviousInput = u2pwm_P.Memory5_X0;

  /* InitializeConditions for Memory: '<S13>/Memory4' */
  u2pwm_DW.Memory4_PreviousInput = u2pwm_P.Memory4_X0;

  /* InitializeConditions for Memory: '<S13>/Memory3' */
  u2pwm_DW.Memory3_PreviousInput = u2pwm_P.Memory3_X0;

  /* InitializeConditions for Memory: '<S13>/Memory2' */
  u2pwm_DW.Memory2_PreviousInput = u2pwm_P.Memory2_X0;

  /* InitializeConditions for Memory: '<S13>/Memory' */
  u2pwm_DW.Memory_PreviousInput_p = u2pwm_P.Memory_X0_o;

  /* InitializeConditions for Memory: '<S13>/Memory1' */
  u2pwm_DW.Memory1_PreviousInput = u2pwm_P.Memory1_X0;
}

/* Model terminate function */
void u2pwm_terminate(void)
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
  u2pwm_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  u2pwm_update();
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
  u2pwm_initialize();
}

void MdlTerminate(void)
{
  u2pwm_terminate();
}

/* Registration function */
RT_MODEL_u2pwm_T *u2pwm(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)u2pwm_M, 0,
                sizeof(RT_MODEL_u2pwm_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&u2pwm_M->solverInfo, &u2pwm_M->Timing.simTimeStep);
    rtsiSetTPtr(&u2pwm_M->solverInfo, &rtmGetTPtr(u2pwm_M));
    rtsiSetStepSizePtr(&u2pwm_M->solverInfo, &u2pwm_M->Timing.stepSize0);
    rtsiSetdXPtr(&u2pwm_M->solverInfo, &u2pwm_M->derivs);
    rtsiSetContStatesPtr(&u2pwm_M->solverInfo, (real_T **) &u2pwm_M->contStates);
    rtsiSetNumContStatesPtr(&u2pwm_M->solverInfo, &u2pwm_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&u2pwm_M->solverInfo,
      &u2pwm_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&u2pwm_M->solverInfo,
      &u2pwm_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&u2pwm_M->solverInfo,
      &u2pwm_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&u2pwm_M->solverInfo, (&rtmGetErrorStatus(u2pwm_M)));
    rtsiSetRTModelPtr(&u2pwm_M->solverInfo, u2pwm_M);
  }

  rtsiSetSimTimeStep(&u2pwm_M->solverInfo, MAJOR_TIME_STEP);
  u2pwm_M->intgData.y = u2pwm_M->odeY;
  u2pwm_M->intgData.f[0] = u2pwm_M->odeF[0];
  u2pwm_M->intgData.f[1] = u2pwm_M->odeF[1];
  u2pwm_M->intgData.f[2] = u2pwm_M->odeF[2];
  u2pwm_M->contStates = ((real_T *) &u2pwm_X);
  rtsiSetSolverData(&u2pwm_M->solverInfo, (void *)&u2pwm_M->intgData);
  rtsiSetSolverName(&u2pwm_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = u2pwm_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    u2pwm_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    u2pwm_M->Timing.sampleTimes = (&u2pwm_M->Timing.sampleTimesArray[0]);
    u2pwm_M->Timing.offsetTimes = (&u2pwm_M->Timing.offsetTimesArray[0]);

    /* task periods */
    u2pwm_M->Timing.sampleTimes[0] = (0.0);
    u2pwm_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    u2pwm_M->Timing.offsetTimes[0] = (0.0);
    u2pwm_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(u2pwm_M, &u2pwm_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = u2pwm_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    u2pwm_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(u2pwm_M, -1);
  u2pwm_M->Timing.stepSize0 = 0.01;
  u2pwm_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    u2pwm_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(u2pwm_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(u2pwm_M->rtwLogInfo, (NULL));
    rtliSetLogT(u2pwm_M->rtwLogInfo, "tout");
    rtliSetLogX(u2pwm_M->rtwLogInfo, "");
    rtliSetLogXFinal(u2pwm_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(u2pwm_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(u2pwm_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(u2pwm_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(u2pwm_M->rtwLogInfo, 1);
    rtliSetLogY(u2pwm_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(u2pwm_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(u2pwm_M->rtwLogInfo, (NULL));
  }

  u2pwm_M->solverInfoPtr = (&u2pwm_M->solverInfo);
  u2pwm_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&u2pwm_M->solverInfo, 0.01);
  rtsiSetSolverMode(&u2pwm_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  u2pwm_M->blockIO = ((void *) &u2pwm_B);
  (void) memset(((void *) &u2pwm_B), 0,
                sizeof(B_u2pwm_T));

  /* parameters */
  u2pwm_M->defaultParam = ((real_T *)&u2pwm_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &u2pwm_X;
    u2pwm_M->contStates = (x);
    (void) memset((void *)&u2pwm_X, 0,
                  sizeof(X_u2pwm_T));
  }

  /* states (dwork) */
  u2pwm_M->dwork = ((void *) &u2pwm_DW);
  (void) memset((void *)&u2pwm_DW, 0,
                sizeof(DW_u2pwm_T));

  /* Initialize Sizes */
  u2pwm_M->Sizes.numContStates = (12); /* Number of continuous states */
  u2pwm_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  u2pwm_M->Sizes.numY = (0);           /* Number of model outputs */
  u2pwm_M->Sizes.numU = (0);           /* Number of model inputs */
  u2pwm_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  u2pwm_M->Sizes.numSampTimes = (2);   /* Number of sample times */
  u2pwm_M->Sizes.numBlocks = (200);    /* Number of blocks */
  u2pwm_M->Sizes.numBlockIO = (108);   /* Number of block outputs */
  u2pwm_M->Sizes.numBlockPrms = (542); /* Sum of parameter "widths" */
  return u2pwm_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : u2pwm
 * Model version : 1.9
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Wed Jul 12 17:04:41 2017
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_u2pwm
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 23:
    return (( double *)ptr)[subindex];

   case 24:
    return (( double *)ptr)[subindex];

   case 25:
    return (( double *)ptr)[subindex];

   case 26:
    return (( double *)ptr)[subindex];

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
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 33:
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
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 23:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 24:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 25:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 26:
    //Type is struct. Call SetValueByDataType on its contained type
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
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern u2pwm_rtModel *S;
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

  // u2pwm/Switch_subsystem/Triangle1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.Triangle1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/Switch_subsystem/Circle1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.Circle1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/Switch_subsystem/Cross1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.Cross1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/Switch_subsystem/Square1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.Square1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_custom/u_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_custom/u_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_custom/u_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_custom/alpha_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_custom/u_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_custom/u_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_custom/u_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_custom/alpha_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_custom/alpha_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_custom/alpha_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_custom/alpha_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_custom/alpha_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_DP/u_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_1_i, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_DP/u_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_3_k, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_DP/u_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_6_e, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_DP/alpha_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_1_e, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_DP/u_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_2_g, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_DP/u_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_4_a, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_DP/u_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_5_l, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_DP/alpha_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_2_d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_DP/alpha_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_3_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_DP/alpha_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_4_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_DP/alpha_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_5_g, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_DP/alpha_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_6_b, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_sixaxis2thruster/u_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_1_b, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_sixaxis2thruster/u_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_3_kf, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_sixaxis2thruster/u_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_6_b, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_sixaxis2thruster/alpha_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_1_d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_sixaxis2thruster/u_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_2_a, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_sixaxis2thruster/u_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_4_j, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_sixaxis2thruster/u_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.u_5_n, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_sixaxis2thruster/alpha_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_2_c, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_sixaxis2thruster/alpha_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_3_b, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_sixaxis2thruster/alpha_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_4_k, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_sixaxis2thruster/alpha_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_5_i, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/ctrl_sixaxis2thruster/alpha_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_6_f, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/alpha2pwm/manual alpha/man_alpha_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.man_alpha_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/alpha2pwm/manual alpha/man_alpha_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.man_alpha_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/alpha2pwm/manual alpha/man_alpha_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.man_alpha_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/alpha2pwm/manual alpha/man_alpha_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.man_alpha_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/alpha2pwm/manual alpha/man_alpha_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.man_alpha_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/alpha2pwm/manual alpha/man_alpha_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.man_alpha_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/mech elec enable
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.mechelecenable, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/wrapping/no wrapping
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.nowrapping, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/wrapping/alpha_deg_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_deg_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/wrapping/alpha_deg_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_deg_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/wrapping/alpha_deg_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_deg_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/wrapping/alpha_deg_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_deg_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/wrapping/alpha_deg_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_deg_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/wrapping/alpha_deg_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.alpha_deg_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/alpha2pwm/manual override alpha
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.manualoverridealpha, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/u2pwm/manual pwm/pwm_u_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_u_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/u2pwm/manual pwm/pwm_u_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_u_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/u2pwm/manual pwm/pwm_u_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_u_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/u2pwm/manual pwm/pwm_u_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_u_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/u2pwm/manual pwm/pwm_u_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_u_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/u2pwm/manual pwm/pwm_u_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.pwm_u_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/u2pwm/manual override pwm
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_B.manualoverridepwm, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 62;
}

int32_t NumOutputPorts(void)
{
  return 18;
}

double ni_extout[18];

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

  // u2pwm/control input u exceeds bounds: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.fault, 0, 8, 0);
  } else {
    index += 1;
  }

  // u2pwm/indicator/STOP: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.STOP, 0, 8, 0);
  } else {
    index += 1;
  }

  // u2pwm/indicator/ctrl_DP: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.ctrl_DP, 0, 8, 0);
  } else {
    index += 1;
  }

  // u2pwm/indicator/ctrl_sixaxis2thruster: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.ctrl_sixaxis2thruster,
      0, 8, 0);
  } else {
    index += 1;
  }

  // u2pwm/indicator/ctrl_custom: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.ctrl_custom, 0, 8, 0);
  } else {
    index += 1;
  }

  // u2pwm/alpha2pwm/Need unwrapping thrusters: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.y, 0, 0, 0);
  } else {
    index += 1;
  }

  // u2pwm/pwm_output alpha/alpha_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch2, 1, 19, 0);
  } else {
    index += 1;
  }

  // u2pwm/pwm_output alpha/alpha_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch2, 2, 19, 0);
  } else {
    index += 1;
  }

  // u2pwm/pwm_output alpha/alpha_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch2, 0, 19, 0);
  } else {
    index += 1;
  }

  // u2pwm/pwm_output alpha/alpha_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch2, 5, 19, 0);
  } else {
    index += 1;
  }

  // u2pwm/pwm_output alpha/alpha_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch2, 3, 19, 0);
  } else {
    index += 1;
  }

  // u2pwm/pwm_output alpha/alpha_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch2, 4, 19, 0);
  } else {
    index += 1;
  }

  // u2pwm/pwm_output u/pwm_u_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch, 1, 19, 0);
  } else {
    index += 1;
  }

  // u2pwm/pwm_output u/pwm_u_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch, 2, 19, 0);
  } else {
    index += 1;
  }

  // u2pwm/pwm_output u/pwm_u_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch, 0, 19, 0);
  } else {
    index += 1;
  }

  // u2pwm/pwm_output u/pwm_u_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch, 5, 19, 0);
  } else {
    index += 1;
  }

  // u2pwm/pwm_output u/pwm_u_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch, 3, 19, 0);
  } else {
    index += 1;
  }

  // u2pwm/pwm_output u/pwm_u_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch, 4, 19, 0);
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

  // u2pwm/control input u exceeds bounds: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.fault, 0, 8, 0);

  // u2pwm/indicator/STOP: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.STOP, 0, 8, 0);

  // u2pwm/indicator/ctrl_DP: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.ctrl_DP, 0, 8, 0);

  // u2pwm/indicator/ctrl_sixaxis2thruster: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.ctrl_sixaxis2thruster, 0,
    8, 0);

  // u2pwm/indicator/ctrl_custom: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.ctrl_custom, 0, 8, 0);

  // u2pwm/alpha2pwm/Need unwrapping thrusters: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.y, 0, 0, 0);

  // u2pwm/pwm_output alpha/alpha_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch2, 1, 19, 0);

  // u2pwm/pwm_output alpha/alpha_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch2, 2, 19, 0);

  // u2pwm/pwm_output alpha/alpha_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch2, 0, 19, 0);

  // u2pwm/pwm_output alpha/alpha_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch2, 5, 19, 0);

  // u2pwm/pwm_output alpha/alpha_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch2, 3, 19, 0);

  // u2pwm/pwm_output alpha/alpha_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch2, 4, 19, 0);

  // u2pwm/pwm_output u/pwm_u_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch, 1, 19, 0);

  // u2pwm/pwm_output u/pwm_u_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch, 2, 19, 0);

  // u2pwm/pwm_output u/pwm_u_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch, 0, 19, 0);

  // u2pwm/pwm_output u/pwm_u_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch, 5, 19, 0);

  // u2pwm/pwm_output u/pwm_u_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch, 3, 19, 0);

  // u2pwm/pwm_output u/pwm_u_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_B.Switch, 4, 19, 0);
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
  { 0, "u2pwm/alpha2pwm/alpha_Offset/Value", offsetof(P_u2pwm_T, zero_alpha_1),
    32, 1, 2, 0, 0 },

  { 1, "u2pwm/alpha2pwm/alpha_Offset1/Value", offsetof(P_u2pwm_T, zero_alpha_2),
    32, 1, 2, 2, 0 },

  { 2, "u2pwm/alpha2pwm/alpha_Offset2/Value", offsetof(P_u2pwm_T, zero_alpha_3),
    32, 1, 2, 4, 0 },

  { 3, "u2pwm/alpha2pwm/alpha_Offset3/Value", offsetof(P_u2pwm_T, zero_alpha_4),
    32, 1, 2, 6, 0 },

  { 4, "u2pwm/alpha2pwm/alpha_Offset4/Value", offsetof(P_u2pwm_T, zero_alpha_5),
    32, 1, 2, 8, 0 },

  { 5, "u2pwm/alpha2pwm/alpha_Offset5/Value", offsetof(P_u2pwm_T, zero_alpha_6),
    32, 1, 2, 10, 0 },

  { 6, "u2pwm/u2pwm/PWM_Offset/Value", offsetof(P_u2pwm_T, zero_pwm), 32, 1, 2,
    12, 0 },

  { 7, "u2pwm/u2pwm/PWM_Offset1/Value", offsetof(P_u2pwm_T, zero_pwm), 32, 1, 2,
    14, 0 },

  { 8, "u2pwm/u2pwm/PWM_Offset2/Value", offsetof(P_u2pwm_T, zero_pwm), 32, 1, 2,
    16, 0 },

  { 9, "u2pwm/u2pwm/PWM_Offset3/Value", offsetof(P_u2pwm_T, zero_pwm), 32, 1, 2,
    18, 0 },

  { 10, "u2pwm/u2pwm/PWM_Offset4/Value", offsetof(P_u2pwm_T, zero_pwm), 32, 1, 2,
    20, 0 },

  { 11, "u2pwm/u2pwm/PWM_Offset5/Value", offsetof(P_u2pwm_T, zero_pwm), 32, 1, 2,
    22, 0 },

  { 12, "u2pwm/Switch_subsystem/Memory/X0", offsetof(P_u2pwm_T, Memory_X0), 32,
    1, 2, 24, 0 },

  { 13, "u2pwm/STOP/Constant/Value", offsetof(P_u2pwm_T, Constant_Value), 32, 1,
    2, 26, 0 },

  { 14, "u2pwm/STOP/Constant1/Value", offsetof(P_u2pwm_T, Constant1_Value), 32,
    1, 2, 28, 0 },

  { 15, "u2pwm/STOP/Constant2/Value", offsetof(P_u2pwm_T, Constant2_Value), 32,
    1, 2, 30, 0 },

  { 16, "u2pwm/STOP/Constant3/Value", offsetof(P_u2pwm_T, Constant3_Value), 32,
    1, 2, 32, 0 },

  { 17, "u2pwm/STOP/Constant4/Value", offsetof(P_u2pwm_T, Constant4_Value), 32,
    1, 2, 34, 0 },

  { 18, "u2pwm/STOP/Constant5/Value", offsetof(P_u2pwm_T, Constant5_Value), 32,
    1, 2, 36, 0 },

  { 19, "u2pwm/STOP/Constant6/Value", offsetof(P_u2pwm_T, Constant6_Value), 32,
    1, 2, 38, 0 },

  { 20, "u2pwm/STOP/Constant7/Value", offsetof(P_u2pwm_T, Constant7_Value), 32,
    1, 2, 40, 0 },

  { 21, "u2pwm/STOP/Constant8/Value", offsetof(P_u2pwm_T, Constant8_Value), 32,
    1, 2, 42, 0 },

  { 22, "u2pwm/STOP/Constant9/Value", offsetof(P_u2pwm_T, Constant9_Value), 32,
    1, 2, 44, 0 },

  { 23, "u2pwm/STOP/Constant10/Value", offsetof(P_u2pwm_T, Constant10_Value), 32,
    1, 2, 46, 0 },

  { 24, "u2pwm/STOP/Constant11/Value", offsetof(P_u2pwm_T, Constant11_Value), 32,
    1, 2, 48, 0 },

  { 25,
    "u2pwm/emulate mechanical and electrical system/Integrator6/InitialCondition",
    offsetof(P_u2pwm_T, Integrator6_IC), 32, 1, 2, 50, 0 },

  { 26,
    "u2pwm/emulate mechanical and electrical system/Integrator5/InitialCondition",
    offsetof(P_u2pwm_T, Integrator5_IC), 32, 1, 2, 52, 0 },

  { 27,
    "u2pwm/emulate mechanical and electrical system/Integrator4/InitialCondition",
    offsetof(P_u2pwm_T, Integrator4_IC), 32, 1, 2, 54, 0 },

  { 28,
    "u2pwm/emulate mechanical and electrical system/Integrator3/InitialCondition",
    offsetof(P_u2pwm_T, Integrator3_IC), 32, 1, 2, 56, 0 },

  { 29,
    "u2pwm/emulate mechanical and electrical system/Integrator2/InitialCondition",
    offsetof(P_u2pwm_T, Integrator2_IC), 32, 1, 2, 58, 0 },

  { 30,
    "u2pwm/emulate mechanical and electrical system/Integrator1/InitialCondition",
    offsetof(P_u2pwm_T, Integrator1_IC), 32, 1, 2, 60, 0 },

  { 31,
    "u2pwm/emulate mechanical and electrical system/Integrator/InitialCondition",
    offsetof(P_u2pwm_T, Integrator_IC), 32, 1, 2, 62, 0 },

  { 32,
    "u2pwm/emulate mechanical and electrical system/Integrator7/InitialCondition",
    offsetof(P_u2pwm_T, Integrator7_IC), 32, 1, 2, 64, 0 },

  { 33,
    "u2pwm/emulate mechanical and electrical system/Integrator8/InitialCondition",
    offsetof(P_u2pwm_T, Integrator8_IC), 32, 1, 2, 66, 0 },

  { 34,
    "u2pwm/emulate mechanical and electrical system/Integrator9/InitialCondition",
    offsetof(P_u2pwm_T, Integrator9_IC), 32, 1, 2, 68, 0 },

  { 35,
    "u2pwm/emulate mechanical and electrical system/Integrator10/InitialCondition",
    offsetof(P_u2pwm_T, Integrator10_IC), 32, 1, 2, 70, 0 },

  { 36,
    "u2pwm/emulate mechanical and electrical system/Integrator11/InitialCondition",
    offsetof(P_u2pwm_T, Integrator11_IC), 32, 1, 2, 72, 0 },

  { 37, "u2pwm/wrapping/Gain6/Gain", offsetof(P_u2pwm_T, Gain6_Gain), 32, 1, 2,
    74, 0 },

  { 38, "u2pwm/wrapping/Gain7/Gain", offsetof(P_u2pwm_T, Gain7_Gain), 32, 1, 2,
    76, 0 },

  { 39, "u2pwm/wrapping/Gain8/Gain", offsetof(P_u2pwm_T, Gain8_Gain), 32, 1, 2,
    78, 0 },

  { 40, "u2pwm/wrapping/Gain9/Gain", offsetof(P_u2pwm_T, Gain9_Gain), 32, 1, 2,
    80, 0 },

  { 41, "u2pwm/wrapping/Gain10/Gain", offsetof(P_u2pwm_T, Gain10_Gain), 32, 1, 2,
    82, 0 },

  { 42, "u2pwm/wrapping/Gain11/Gain", offsetof(P_u2pwm_T, Gain11_Gain), 32, 1, 2,
    84, 0 },

  { 43, "u2pwm/wrapping/Memory5/X0", offsetof(P_u2pwm_T, Memory5_X0), 32, 1, 2,
    86, 0 },

  { 44, "u2pwm/wrapping/Memory4/X0", offsetof(P_u2pwm_T, Memory4_X0), 32, 1, 2,
    88, 0 },

  { 45, "u2pwm/wrapping/Memory3/X0", offsetof(P_u2pwm_T, Memory3_X0), 32, 1, 2,
    90, 0 },

  { 46, "u2pwm/wrapping/Memory2/X0", offsetof(P_u2pwm_T, Memory2_X0), 32, 1, 2,
    92, 0 },

  { 47, "u2pwm/wrapping/Memory/X0", offsetof(P_u2pwm_T, Memory_X0_o), 32, 1, 2,
    94, 0 },

  { 48, "u2pwm/wrapping/Memory1/X0", offsetof(P_u2pwm_T, Memory1_X0), 32, 1, 2,
    96, 0 },

  { 49, "u2pwm/u2pwm/Saturation11/UpperLimit", offsetof(P_u2pwm_T,
    Saturation11_UpperSat), 32, 1, 2, 98, 0 },

  { 50, "u2pwm/u2pwm/Saturation11/LowerLimit", offsetof(P_u2pwm_T,
    Saturation11_LowerSat), 32, 1, 2, 100, 0 },

  { 51, "u2pwm/u2pwm/Gain/Gain", offsetof(P_u2pwm_T, Gain_Gain), 32, 1, 2, 102,
    0 },

  { 52, "u2pwm/u2pwm/Saturation10/UpperLimit", offsetof(P_u2pwm_T,
    Saturation10_UpperSat), 32, 1, 2, 104, 0 },

  { 53, "u2pwm/u2pwm/Saturation10/LowerLimit", offsetof(P_u2pwm_T,
    Saturation10_LowerSat), 32, 1, 2, 106, 0 },

  { 54, "u2pwm/u2pwm/Gain1/Gain", offsetof(P_u2pwm_T, Gain1_Gain), 32, 1, 2, 108,
    0 },

  { 55, "u2pwm/u2pwm/Saturation9/UpperLimit", offsetof(P_u2pwm_T,
    Saturation9_UpperSat), 32, 1, 2, 110, 0 },

  { 56, "u2pwm/u2pwm/Saturation9/LowerLimit", offsetof(P_u2pwm_T,
    Saturation9_LowerSat), 32, 1, 2, 112, 0 },

  { 57, "u2pwm/u2pwm/Gain2/Gain", offsetof(P_u2pwm_T, Gain2_Gain), 32, 1, 2, 114,
    0 },

  { 58, "u2pwm/u2pwm/Saturation8/UpperLimit", offsetof(P_u2pwm_T,
    Saturation8_UpperSat), 32, 1, 2, 116, 0 },

  { 59, "u2pwm/u2pwm/Saturation8/LowerLimit", offsetof(P_u2pwm_T,
    Saturation8_LowerSat), 32, 1, 2, 118, 0 },

  { 60, "u2pwm/u2pwm/Gain3/Gain", offsetof(P_u2pwm_T, Gain3_Gain), 32, 1, 2, 120,
    0 },

  { 61, "u2pwm/u2pwm/Saturation7/UpperLimit", offsetof(P_u2pwm_T,
    Saturation7_UpperSat), 32, 1, 2, 122, 0 },

  { 62, "u2pwm/u2pwm/Saturation7/LowerLimit", offsetof(P_u2pwm_T,
    Saturation7_LowerSat), 32, 1, 2, 124, 0 },

  { 63, "u2pwm/u2pwm/Gain4/Gain", offsetof(P_u2pwm_T, Gain4_Gain), 32, 1, 2, 126,
    0 },

  { 64, "u2pwm/u2pwm/Saturation6/UpperLimit", offsetof(P_u2pwm_T,
    Saturation6_UpperSat), 32, 1, 2, 128, 0 },

  { 65, "u2pwm/u2pwm/Saturation6/LowerLimit", offsetof(P_u2pwm_T,
    Saturation6_LowerSat), 32, 1, 2, 130, 0 },

  { 66, "u2pwm/u2pwm/Gain5/Gain", offsetof(P_u2pwm_T, Gain5_Gain), 32, 1, 2, 132,
    0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 67;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
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
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
  1, 1,                                /* Parameter at index 36 */
  1, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
  1, 1,                                /* Parameter at index 39 */
  1, 1,                                /* Parameter at index 40 */
  1, 1,                                /* Parameter at index 41 */
  1, 1,                                /* Parameter at index 42 */
  1, 1,                                /* Parameter at index 43 */
  1, 1,                                /* Parameter at index 44 */
  1, 1,                                /* Parameter at index 45 */
  1, 1,                                /* Parameter at index 46 */
  1, 1,                                /* Parameter at index 47 */
  1, 1,                                /* Parameter at index 48 */
  1, 1,                                /* Parameter at index 49 */
  1, 1,                                /* Parameter at index 50 */
  1, 1,                                /* Parameter at index 51 */
  1, 1,                                /* Parameter at index 52 */
  1, 1,                                /* Parameter at index 53 */
  1, 1,                                /* Parameter at index 54 */
  1, 1,                                /* Parameter at index 55 */
  1, 1,                                /* Parameter at index 56 */
  1, 1,                                /* Parameter at index 57 */
  1, 1,                                /* Parameter at index 58 */
  1, 1,                                /* Parameter at index 59 */
  1, 1,                                /* Parameter at index 60 */
  1, 1,                                /* Parameter at index 61 */
  1, 1,                                /* Parameter at index 62 */
  1, 1,                                /* Parameter at index 63 */
  1, 1,                                /* Parameter at index 64 */
  1, 1,                                /* Parameter at index 65 */
  1, 1,                                /* Parameter at index 66 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "u2pwm/Switch_subsystem/Triangle1", 0, "", offsetof(B_u2pwm_T, Triangle1)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "u2pwm/Switch_subsystem/Circle1", 0, "", offsetof(B_u2pwm_T, Circle1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "u2pwm/Switch_subsystem/Cross1", 0, "", offsetof(B_u2pwm_T, Cross1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "u2pwm/Switch_subsystem/Square1", 0, "", offsetof(B_u2pwm_T, Square1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "u2pwm/Switch_subsystem/Memory", 0, "", offsetof(B_u2pwm_T, Memory) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "u2pwm/ctrl_custom/u_1", 0, "", offsetof(B_u2pwm_T, u_1) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "u2pwm/ctrl_custom/u_3", 0, "", offsetof(B_u2pwm_T, u_3) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "u2pwm/ctrl_custom/u_6", 0, "", offsetof(B_u2pwm_T, u_6) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "u2pwm/ctrl_custom/alpha_1", 0, "", offsetof(B_u2pwm_T, alpha_1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "u2pwm/ctrl_custom/u_2", 0, "", offsetof(B_u2pwm_T, u_2) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "u2pwm/ctrl_custom/u_4", 0, "", offsetof(B_u2pwm_T, u_4) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "u2pwm/ctrl_custom/u_5", 0, "", offsetof(B_u2pwm_T, u_5) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "u2pwm/ctrl_custom/alpha_2", 0, "", offsetof(B_u2pwm_T, alpha_2) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "u2pwm/ctrl_custom/alpha_3", 0, "", offsetof(B_u2pwm_T, alpha_3) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "u2pwm/ctrl_custom/alpha_4", 0, "", offsetof(B_u2pwm_T, alpha_4) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "u2pwm/ctrl_custom/alpha_5", 0, "", offsetof(B_u2pwm_T, alpha_5) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "u2pwm/ctrl_custom/alpha_6", 0, "", offsetof(B_u2pwm_T, alpha_6) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "u2pwm/ctrl_DP/u_1", 0, "", offsetof(B_u2pwm_T, u_1_i) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "u2pwm/ctrl_DP/u_3", 0, "", offsetof(B_u2pwm_T, u_3_k) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 19, "u2pwm/ctrl_DP/u_6", 0, "", offsetof(B_u2pwm_T, u_6_e) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "u2pwm/ctrl_DP/alpha_1", 0, "", offsetof(B_u2pwm_T, alpha_1_e) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "u2pwm/ctrl_DP/u_2", 0, "", offsetof(B_u2pwm_T, u_2_g) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "u2pwm/ctrl_DP/u_4", 0, "", offsetof(B_u2pwm_T, u_4_a) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 23, "u2pwm/ctrl_DP/u_5", 0, "", offsetof(B_u2pwm_T, u_5_l) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 24, "u2pwm/ctrl_DP/alpha_2", 0, "", offsetof(B_u2pwm_T, alpha_2_d) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 25, "u2pwm/ctrl_DP/alpha_3", 0, "", offsetof(B_u2pwm_T, alpha_3_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 26, "u2pwm/ctrl_DP/alpha_4", 0, "", offsetof(B_u2pwm_T, alpha_4_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 27, "u2pwm/ctrl_DP/alpha_5", 0, "", offsetof(B_u2pwm_T, alpha_5_g) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 28, "u2pwm/ctrl_DP/alpha_6", 0, "", offsetof(B_u2pwm_T, alpha_6_b) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 29, "u2pwm/ctrl_sixaxis2thruster/u_1", 0, "", offsetof(B_u2pwm_T, u_1_b) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 30, "u2pwm/ctrl_sixaxis2thruster/u_3", 0, "", offsetof(B_u2pwm_T, u_3_kf) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 31, "u2pwm/ctrl_sixaxis2thruster/u_6", 0, "", offsetof(B_u2pwm_T, u_6_b) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 32, "u2pwm/ctrl_sixaxis2thruster/alpha_1", 0, "", offsetof(B_u2pwm_T,
    alpha_1_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 33, "u2pwm/ctrl_sixaxis2thruster/u_2", 0, "", offsetof(B_u2pwm_T, u_2_a) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 34, "u2pwm/ctrl_sixaxis2thruster/u_4", 0, "", offsetof(B_u2pwm_T, u_4_j) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 35, "u2pwm/ctrl_sixaxis2thruster/u_5", 0, "", offsetof(B_u2pwm_T, u_5_n) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 36, "u2pwm/ctrl_sixaxis2thruster/alpha_2", 0, "", offsetof(B_u2pwm_T,
    alpha_2_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 37, "u2pwm/ctrl_sixaxis2thruster/alpha_3", 0, "", offsetof(B_u2pwm_T,
    alpha_3_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 38, "u2pwm/ctrl_sixaxis2thruster/alpha_4", 0, "", offsetof(B_u2pwm_T,
    alpha_4_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 39, "u2pwm/ctrl_sixaxis2thruster/alpha_5", 0, "", offsetof(B_u2pwm_T,
    alpha_5_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 40, "u2pwm/ctrl_sixaxis2thruster/alpha_6", 0, "", offsetof(B_u2pwm_T,
    alpha_6_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 41, "u2pwm/alpha2pwm/manual alpha/man_alpha_5", 0, "", offsetof(B_u2pwm_T,
    man_alpha_5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 42, "u2pwm/alpha2pwm/manual alpha/man_alpha_4", 0, "", offsetof(B_u2pwm_T,
    man_alpha_4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 43, "u2pwm/alpha2pwm/manual alpha/man_alpha_1", 0, "", offsetof(B_u2pwm_T,
    man_alpha_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 44, "u2pwm/alpha2pwm/manual alpha/man_alpha_2", 0, "", offsetof(B_u2pwm_T,
    man_alpha_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 45, "u2pwm/alpha2pwm/manual alpha/man_alpha_3", 0, "", offsetof(B_u2pwm_T,
    man_alpha_3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 46, "u2pwm/alpha2pwm/manual alpha/man_alpha_6", 0, "", offsetof(B_u2pwm_T,
    man_alpha_6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 47, "u2pwm/mech elec enable", 0, "", offsetof(B_u2pwm_T, mechelecenable) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 48, "u2pwm/wrapping/no wrapping", 0, "", offsetof(B_u2pwm_T, nowrapping) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 49, "u2pwm/wrapping/Memory5", 0, "", offsetof(B_u2pwm_T, Memory5) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 50, "u2pwm/wrapping/alpha_deg_1", 0, "", offsetof(B_u2pwm_T, alpha_deg_1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 51, "u2pwm/wrapping/Memory4", 0, "", offsetof(B_u2pwm_T, Memory4) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 52, "u2pwm/wrapping/alpha_deg_2", 0, "", offsetof(B_u2pwm_T, alpha_deg_2) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 53, "u2pwm/wrapping/Memory3", 0, "", offsetof(B_u2pwm_T, Memory3) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 54, "u2pwm/wrapping/alpha_deg_3", 0, "", offsetof(B_u2pwm_T, alpha_deg_3) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 55, "u2pwm/wrapping/Memory2", 0, "", offsetof(B_u2pwm_T, Memory2) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 56, "u2pwm/wrapping/alpha_deg_4", 0, "", offsetof(B_u2pwm_T, alpha_deg_4) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 57, "u2pwm/wrapping/Memory", 0, "", offsetof(B_u2pwm_T, Memory_f) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 58, "u2pwm/wrapping/alpha_deg_5", 0, "", offsetof(B_u2pwm_T, alpha_deg_5) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 59, "u2pwm/wrapping/Memory1", 0, "", offsetof(B_u2pwm_T, Memory1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 60, "u2pwm/wrapping/alpha_deg_6", 0, "", offsetof(B_u2pwm_T, alpha_deg_6) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 61, "u2pwm/alpha2pwm/manual override alpha", 0, "", offsetof(B_u2pwm_T,
    manualoverridealpha) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 62, "u2pwm/alpha2pwm/Switch2/(1, 1)", 0, "", offsetof(B_u2pwm_T, Switch2) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 63, "u2pwm/alpha2pwm/Switch2/(1, 2)", 0, "", offsetof(B_u2pwm_T, Switch2) +
    (1*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 64, "u2pwm/alpha2pwm/Switch2/(1, 3)", 0, "", offsetof(B_u2pwm_T, Switch2) +
    (2*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 65, "u2pwm/alpha2pwm/Switch2/(1, 4)", 0, "", offsetof(B_u2pwm_T, Switch2) +
    (3*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 66, "u2pwm/alpha2pwm/Switch2/(1, 5)", 0, "", offsetof(B_u2pwm_T, Switch2) +
    (4*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 67, "u2pwm/alpha2pwm/Switch2/(1, 6)", 0, "", offsetof(B_u2pwm_T, Switch2) +
    (5*sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 68, "u2pwm/u2pwm/manual pwm/pwm_u_5", 0, "", offsetof(B_u2pwm_T, pwm_u_5) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 69, "u2pwm/u2pwm/manual pwm/pwm_u_4", 0, "", offsetof(B_u2pwm_T, pwm_u_4) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 70, "u2pwm/u2pwm/manual pwm/pwm_u_1", 0, "", offsetof(B_u2pwm_T, pwm_u_1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 71, "u2pwm/u2pwm/manual pwm/pwm_u_6", 0, "", offsetof(B_u2pwm_T, pwm_u_6) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 72, "u2pwm/u2pwm/manual pwm/pwm_u_2", 0, "", offsetof(B_u2pwm_T, pwm_u_2) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 73, "u2pwm/u2pwm/manual pwm/pwm_u_3", 0, "", offsetof(B_u2pwm_T, pwm_u_3) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 74, "u2pwm/u2pwm/manual override pwm", 0, "", offsetof(B_u2pwm_T,
    manualoverridepwm) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 75, "u2pwm/u2pwm/Switch/(1, 1)", 0, "", offsetof(B_u2pwm_T, Switch) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 76, "u2pwm/u2pwm/Switch/(1, 2)", 0, "", offsetof(B_u2pwm_T, Switch) + (1*
    sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 77, "u2pwm/u2pwm/Switch/(1, 3)", 0, "", offsetof(B_u2pwm_T, Switch) + (2*
    sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 78, "u2pwm/u2pwm/Switch/(1, 4)", 0, "", offsetof(B_u2pwm_T, Switch) + (3*
    sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 79, "u2pwm/u2pwm/Switch/(1, 5)", 0, "", offsetof(B_u2pwm_T, Switch) + (4*
    sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 80, "u2pwm/u2pwm/Switch/(1, 6)", 0, "", offsetof(B_u2pwm_T, Switch) + (5*
    sizeof(real_T)), BLOCKIO_SIG, 19, 1, 2, 0, 0 },

  { 81, "u2pwm/emulate mechanical and electrical system/Sum", 0, "", offsetof
    (B_u2pwm_T, Sum) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 82, "u2pwm/emulate mechanical and electrical system/Sum1", 0, "", offsetof
    (B_u2pwm_T, Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 83, "u2pwm/emulate mechanical and electrical system/Sum10", 0, "", offsetof
    (B_u2pwm_T, Sum10) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 84, "u2pwm/emulate mechanical and electrical system/Sum11", 0, "", offsetof
    (B_u2pwm_T, Sum11) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 85, "u2pwm/emulate mechanical and electrical system/Sum2", 0, "", offsetof
    (B_u2pwm_T, Sum2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 86, "u2pwm/emulate mechanical and electrical system/Sum3", 0, "", offsetof
    (B_u2pwm_T, Sum3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 87, "u2pwm/emulate mechanical and electrical system/Sum4", 0, "", offsetof
    (B_u2pwm_T, Sum4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 88, "u2pwm/emulate mechanical and electrical system/Sum5", 0, "", offsetof
    (B_u2pwm_T, Sum5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 89, "u2pwm/emulate mechanical and electrical system/Sum6", 0, "", offsetof
    (B_u2pwm_T, Sum6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 90, "u2pwm/emulate mechanical and electrical system/Sum7", 0, "", offsetof
    (B_u2pwm_T, Sum7) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 91, "u2pwm/emulate mechanical and electrical system/Sum8", 0, "", offsetof
    (B_u2pwm_T, Sum8) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 92, "u2pwm/emulate mechanical and electrical system/Sum9", 0, "", offsetof
    (B_u2pwm_T, Sum9) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 93, "u2pwm/alpha2pwm/MATLAB Function12", 0, "", offsetof(B_u2pwm_T, y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 94, "u2pwm/Switch_subsystem/Switch_function", 0, "", offsetof(B_u2pwm_T,
    switch_signal) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 95, "u2pwm/indicator/C", 0, "", offsetof(B_u2pwm_T, ctrl_custom) + (0*sizeof
    (boolean_T)), BLOCKIO_SIG, 8, 1, 2, 0, 0 },

  { 96, "u2pwm/indicator/C", 1, "", offsetof(B_u2pwm_T, STOP) + (0*sizeof
    (boolean_T)), BLOCKIO_SIG, 8, 1, 2, 0, 0 },

  { 97, "u2pwm/indicator/C", 2, "", offsetof(B_u2pwm_T, ctrl_DP) + (0*sizeof
    (boolean_T)), BLOCKIO_SIG, 8, 1, 2, 0, 0 },

  { 98, "u2pwm/indicator/C", 3, "", offsetof(B_u2pwm_T, ctrl_sixaxis2thruster) +
    (0*sizeof(boolean_T)), BLOCKIO_SIG, 8, 1, 2, 0, 0 },

  { 99, "u2pwm/control limit checking", 0, "", offsetof(B_u2pwm_T, fault) + (0*
    sizeof(boolean_T)), BLOCKIO_SIG, 8, 1, 2, 0, 0 },

  { 100, "u2pwm/wrapping/MATLAB Function9", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction9.angle_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 101, "u2pwm/wrapping/MATLAB Function8", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction8.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 102, "u2pwm/wrapping/MATLAB Function7", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction7.angle_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 103, "u2pwm/wrapping/MATLAB Function6", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction6.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 104, "u2pwm/wrapping/MATLAB Function5", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction5.angle_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 105, "u2pwm/wrapping/MATLAB Function4", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction4.angle_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 106, "u2pwm/wrapping/MATLAB Function3", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction3.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 107, "u2pwm/wrapping/MATLAB Function2", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction2.angle_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 108, "u2pwm/wrapping/MATLAB Function11", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction11.angle_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 109, "u2pwm/wrapping/MATLAB Function10", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction10.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 110, "u2pwm/wrapping/MATLAB Function1", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction1.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 111, "u2pwm/wrapping/MATLAB Function", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 112, "u2pwm/u2pwm/MATLAB Function18", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction18.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 113, "u2pwm/u2pwm/MATLAB Function17", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction17.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 114, "u2pwm/u2pwm/MATLAB Function16", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction16.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 115, "u2pwm/u2pwm/MATLAB Function15", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction15.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 116, "u2pwm/u2pwm/MATLAB Function14", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction14.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 117, "u2pwm/u2pwm/MATLAB Function13", 0, "", offsetof(B_u2pwm_T,
    sf_MATLABFunction13.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 118;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 80;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Switch_subsystem/Triangle1", 0, EXT_IN, 1, 1, 1 },

  { 2, "Switch_subsystem/Circle1", 0, EXT_IN, 1, 1, 1 },

  { 3, "Switch_subsystem/Cross1", 0, EXT_IN, 1, 1, 1 },

  { 4, "Switch_subsystem/Square1", 0, EXT_IN, 1, 1, 1 },

  { 5, "ctrl_custom/u_1", 0, EXT_IN, 1, 1, 1 },

  { 6, "ctrl_custom/u_3", 0, EXT_IN, 1, 1, 1 },

  { 7, "ctrl_custom/u_6", 0, EXT_IN, 1, 1, 1 },

  { 8, "ctrl_custom/alpha_1", 0, EXT_IN, 1, 1, 1 },

  { 9, "ctrl_custom/u_2", 0, EXT_IN, 1, 1, 1 },

  { 10, "ctrl_custom/u_4", 0, EXT_IN, 1, 1, 1 },

  { 11, "ctrl_custom/u_5", 0, EXT_IN, 1, 1, 1 },

  { 12, "ctrl_custom/alpha_2", 0, EXT_IN, 1, 1, 1 },

  { 13, "ctrl_custom/alpha_3", 0, EXT_IN, 1, 1, 1 },

  { 14, "ctrl_custom/alpha_4", 0, EXT_IN, 1, 1, 1 },

  { 15, "ctrl_custom/alpha_5", 0, EXT_IN, 1, 1, 1 },

  { 16, "ctrl_custom/alpha_6", 0, EXT_IN, 1, 1, 1 },

  { 17, "ctrl_DP/u_1", 0, EXT_IN, 1, 1, 1 },

  { 18, "ctrl_DP/u_3", 0, EXT_IN, 1, 1, 1 },

  { 19, "ctrl_DP/u_6", 0, EXT_IN, 1, 1, 1 },

  { 20, "ctrl_DP/alpha_1", 0, EXT_IN, 1, 1, 1 },

  { 21, "ctrl_DP/u_2", 0, EXT_IN, 1, 1, 1 },

  { 22, "ctrl_DP/u_4", 0, EXT_IN, 1, 1, 1 },

  { 23, "ctrl_DP/u_5", 0, EXT_IN, 1, 1, 1 },

  { 24, "ctrl_DP/alpha_2", 0, EXT_IN, 1, 1, 1 },

  { 25, "ctrl_DP/alpha_3", 0, EXT_IN, 1, 1, 1 },

  { 26, "ctrl_DP/alpha_4", 0, EXT_IN, 1, 1, 1 },

  { 27, "ctrl_DP/alpha_5", 0, EXT_IN, 1, 1, 1 },

  { 28, "ctrl_DP/alpha_6", 0, EXT_IN, 1, 1, 1 },

  { 29, "ctrl_sixaxis2thruster/u_1", 0, EXT_IN, 1, 1, 1 },

  { 30, "ctrl_sixaxis2thruster/u_3", 0, EXT_IN, 1, 1, 1 },

  { 31, "ctrl_sixaxis2thruster/u_6", 0, EXT_IN, 1, 1, 1 },

  { 32, "ctrl_sixaxis2thruster/alpha_1", 0, EXT_IN, 1, 1, 1 },

  { 33, "ctrl_sixaxis2thruster/u_2", 0, EXT_IN, 1, 1, 1 },

  { 34, "ctrl_sixaxis2thruster/u_4", 0, EXT_IN, 1, 1, 1 },

  { 35, "ctrl_sixaxis2thruster/u_5", 0, EXT_IN, 1, 1, 1 },

  { 36, "ctrl_sixaxis2thruster/alpha_2", 0, EXT_IN, 1, 1, 1 },

  { 37, "ctrl_sixaxis2thruster/alpha_3", 0, EXT_IN, 1, 1, 1 },

  { 38, "ctrl_sixaxis2thruster/alpha_4", 0, EXT_IN, 1, 1, 1 },

  { 39, "ctrl_sixaxis2thruster/alpha_5", 0, EXT_IN, 1, 1, 1 },

  { 40, "ctrl_sixaxis2thruster/alpha_6", 0, EXT_IN, 1, 1, 1 },

  { 41, "alpha2pwm/manual alpha/man_alpha_5", 0, EXT_IN, 1, 1, 1 },

  { 42, "alpha2pwm/manual alpha/man_alpha_4", 0, EXT_IN, 1, 1, 1 },

  { 43, "alpha2pwm/manual alpha/man_alpha_1", 0, EXT_IN, 1, 1, 1 },

  { 44, "alpha2pwm/manual alpha/man_alpha_2", 0, EXT_IN, 1, 1, 1 },

  { 45, "alpha2pwm/manual alpha/man_alpha_3", 0, EXT_IN, 1, 1, 1 },

  { 46, "alpha2pwm/manual alpha/man_alpha_6", 0, EXT_IN, 1, 1, 1 },

  { 47, "mech elec enable", 0, EXT_IN, 1, 1, 1 },

  { 48, "wrapping/no wrapping", 0, EXT_IN, 1, 1, 1 },

  { 49, "wrapping/alpha_deg_1", 0, EXT_IN, 1, 1, 1 },

  { 50, "wrapping/alpha_deg_2", 0, EXT_IN, 1, 1, 1 },

  { 51, "wrapping/alpha_deg_3", 0, EXT_IN, 1, 1, 1 },

  { 52, "wrapping/alpha_deg_4", 0, EXT_IN, 1, 1, 1 },

  { 53, "wrapping/alpha_deg_5", 0, EXT_IN, 1, 1, 1 },

  { 54, "wrapping/alpha_deg_6", 0, EXT_IN, 1, 1, 1 },

  { 55, "alpha2pwm/manual override alpha", 0, EXT_IN, 1, 1, 1 },

  { 56, "u2pwm/manual pwm/pwm_u_5", 0, EXT_IN, 1, 1, 1 },

  { 57, "u2pwm/manual pwm/pwm_u_4", 0, EXT_IN, 1, 1, 1 },

  { 58, "u2pwm/manual pwm/pwm_u_1", 0, EXT_IN, 1, 1, 1 },

  { 59, "u2pwm/manual pwm/pwm_u_6", 0, EXT_IN, 1, 1, 1 },

  { 60, "u2pwm/manual pwm/pwm_u_2", 0, EXT_IN, 1, 1, 1 },

  { 61, "u2pwm/manual pwm/pwm_u_3", 0, EXT_IN, 1, 1, 1 },

  { 62, "u2pwm/manual override pwm", 0, EXT_IN, 1, 1, 1 },

  { 1, "control input u exceeds bounds", 0, EXT_OUT, 1, 1, 1 },

  { 2, "indicator/STOP", 0, EXT_OUT, 1, 1, 1 },

  { 3, "indicator/ctrl_DP", 0, EXT_OUT, 1, 1, 1 },

  { 4, "indicator/ctrl_sixaxis2thruster", 0, EXT_OUT, 1, 1, 1 },

  { 5, "indicator/ctrl_custom", 0, EXT_OUT, 1, 1, 1 },

  { 6, "alpha2pwm/Need unwrapping thrusters", 0, EXT_OUT, 1, 1, 1 },

  { 7, "pwm_output alpha/alpha_2", 0, EXT_OUT, 1, 1, 1 },

  { 8, "pwm_output alpha/alpha_3", 0, EXT_OUT, 1, 1, 1 },

  { 9, "pwm_output alpha/alpha_1", 0, EXT_OUT, 1, 1, 1 },

  { 10, "pwm_output alpha/alpha_6", 0, EXT_OUT, 1, 1, 1 },

  { 11, "pwm_output alpha/alpha_4", 0, EXT_OUT, 1, 1, 1 },

  { 12, "pwm_output alpha/alpha_5", 0, EXT_OUT, 1, 1, 1 },

  { 13, "pwm_output u/pwm_u_2", 0, EXT_OUT, 1, 1, 1 },

  { 14, "pwm_output u/pwm_u_3", 0, EXT_OUT, 1, 1, 1 },

  { 15, "pwm_output u/pwm_u_1", 0, EXT_OUT, 1, 1, 1 },

  { 16, "pwm_output u/pwm_u_6", 0, EXT_OUT, 1, 1, 1 },

  { 17, "pwm_output u/pwm_u_4", 0, EXT_OUT, 1, 1, 1 },

  { 18, "pwm_output u/pwm_u_5", 0, EXT_OUT, 1, 1, 1 },

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
  "u2pwm";
static const char* NI_CompiledModelVersion = "1.9";
static const char* NI_CompiledModelDateTime = "Wed Jul 12 17:04:41 2017";
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
  memcpy(&rtParameter[0], &u2pwm_P, sizeof(P_u2pwm_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka u2pwm_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_u2pwm_T));
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
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_u2pwm_T));
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
               (P_u2pwm_T));
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
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_u2pwm_T));
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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_u2pwm_T));
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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_u2pwm_T));
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
      *numContStates = 12;
      *numDiscStates = 567;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(u2pwm_X.Integrator6_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator6_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(u2pwm_X.Integrator5_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator5_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(u2pwm_X.Integrator4_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(u2pwm_X.Integrator3_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(u2pwm_X.Integrator2_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(u2pwm_X.Integrator1_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(u2pwm_X.Integrator_CSTATE), 0, 0,
      0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(u2pwm_X.Integrator7_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator7_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(u2pwm_X.Integrator8_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator8_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(u2pwm_X.Integrator9_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator9_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(u2pwm_X.Integrator10_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator10_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(u2pwm_X.Integrator11_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator11_CSTATE");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Triangle1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Triangle1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Circle1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Circle1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Cross1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Cross1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Square1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Square1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Memory_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_1_DWORK1_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_1_DWORK1_o");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_3_DWORK1_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_3_DWORK1_k");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_6_DWORK1_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_6_DWORK1_n");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_1_DWORK1_p, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_1_DWORK1_p");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_2_DWORK1_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_2_DWORK1_d");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_4_DWORK1_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_4_DWORK1_n");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_5_DWORK1_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_5_DWORK1_f");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_2_DWORK1_l, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_2_DWORK1_l");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_3_DWORK1_b, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_3_DWORK1_b");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_4_DWORK1_p, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_4_DWORK1_p");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_5_DWORK1_h, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_5_DWORK1_h");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_6_DWORK1_c, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_6_DWORK1_c");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_1_DWORK1_g, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_1_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_3_DWORK1_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_3_DWORK1_d");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_6_DWORK1_j, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_6_DWORK1_j");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_1_DWORK1_b, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_1_DWORK1_b");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_2_DWORK1_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_2_DWORK1_k");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_4_DWORK1_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_4_DWORK1_k");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_5_DWORK1_fl, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_5_DWORK1_fl");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_2_DWORK1_o, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_2_DWORK1_o");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_3_DWORK1_a, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_3_DWORK1_a");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_4_DWORK1_n, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_4_DWORK1_n");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_5_DWORK1_i, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_5_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_6_DWORK1_p, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_6_DWORK1_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&u2pwm_DW.controlinputuexceedsbounds_DWOR, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&u2pwm_DW.controlinputuexceedsbounds_DWOR");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.STOP_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.STOP_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.ctrl_DP_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.ctrl_DP_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&u2pwm_DW.ctrl_sixaxis2thruster_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&u2pwm_DW.ctrl_sixaxis2thruster_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.ctrl_custom_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.ctrl_custom_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.man_alpha_5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.man_alpha_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.man_alpha_4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.man_alpha_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.man_alpha_1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.man_alpha_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.man_alpha_2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.man_alpha_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.man_alpha_3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.man_alpha_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.man_alpha_6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.man_alpha_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.mechelecenable_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.mechelecenable_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.nowrapping_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.nowrapping_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Memory5_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Memory5_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_deg_1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_deg_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Memory4_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Memory4_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_deg_2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_deg_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Memory3_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_deg_3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_deg_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Memory2_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_deg_4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_deg_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Memory_PreviousInput_p,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Memory_PreviousInput_p");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_deg_5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_deg_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Memory1_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_deg_6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_deg_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&u2pwm_DW.Needunwrappingthrusters_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&u2pwm_DW.Needunwrappingthrusters_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&u2pwm_DW.manualoverridealpha_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&u2pwm_DW.manualoverridealpha_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_2_DWORK1_g, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_2_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_3_DWORK1_d, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_3_DWORK1_d");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_1_DWORK1_j, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_1_DWORK1_j");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_6_DWORK1_d, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_6_DWORK1_d");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_4_DWORK1_a, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_4_DWORK1_a");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_5_DWORK1_g, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_5_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.manualoverridepwm_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.manualoverridepwm_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_2_DWORK1_g, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_2_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_3_DWORK1_n, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_3_DWORK1_n");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_1_DWORK1_m, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_1_DWORK1_m");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_6_DWORK1_i, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_6_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_4_DWORK1_e, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_4_DWORK1_e");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_5_DWORK1_e, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_5_DWORK1_e");
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Triangle1_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Triangle1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Circle1_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Circle1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Cross1_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Cross1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.Square1_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.Square1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_1_DWORK2, count, 20,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_3_DWORK2, count, 20,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_3_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_6_DWORK2, count, 20,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_6_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_1_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_2_DWORK2, count, 20,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_2_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_4_DWORK2, count, 20,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_4_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_5_DWORK2, count, 20,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_5_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_2_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_3_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_4_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_5_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_6_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_1_DWORK2_g, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_1_DWORK2_g");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_3_DWORK2_b, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_3_DWORK2_b");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_6_DWORK2_f, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_6_DWORK2_f");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_1_DWORK2_m,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_1_DWORK2_m");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_2_DWORK2_e, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_2_DWORK2_e");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_4_DWORK2_d, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_4_DWORK2_d");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_5_DWORK2_f, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_5_DWORK2_f");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_2_DWORK2_i,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_2_DWORK2_i");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_3_DWORK2_o,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_3_DWORK2_o");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_4_DWORK2_h,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_4_DWORK2_h");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_5_DWORK2_b,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_5_DWORK2_b");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_6_DWORK2_a,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_6_DWORK2_a");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_1_DWORK2_d, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_1_DWORK2_d");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_3_DWORK2_l, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_3_DWORK2_l");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_6_DWORK2_d, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_6_DWORK2_d");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_1_DWORK2_j,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_1_DWORK2_j");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_2_DWORK2_a, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_2_DWORK2_a");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_4_DWORK2_n, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_4_DWORK2_n");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.u_5_DWORK2_i, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.u_5_DWORK2_i");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_2_DWORK2_f,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_2_DWORK2_f");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_3_DWORK2_n,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_3_DWORK2_n");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_4_DWORK2_g,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_4_DWORK2_g");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_5_DWORK2_bd,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_5_DWORK2_bd");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_6_DWORK2_i,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_6_DWORK2_i");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_DW.controlinputuexceedsbounds_DW_c, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_DW.controlinputuexceedsbounds_DW_c");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.STOP_DWORK2, count, 20,
        0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.STOP_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.ctrl_DP_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.ctrl_DP_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_DW.ctrl_sixaxis2thruster_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_DW.ctrl_sixaxis2thruster_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.ctrl_custom_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.ctrl_custom_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.man_alpha_5_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.man_alpha_5_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.man_alpha_4_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.man_alpha_4_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.man_alpha_1_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.man_alpha_1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.man_alpha_2_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.man_alpha_2_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.man_alpha_3_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.man_alpha_3_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.man_alpha_6_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.man_alpha_6_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.mechelecenable_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.mechelecenable_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.nowrapping_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.nowrapping_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_deg_1_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_deg_1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_deg_2_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_deg_2_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_deg_3_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_deg_3_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_deg_4_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_deg_4_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_deg_5_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_deg_5_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_deg_6_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_deg_6_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_DW.Needunwrappingthrusters_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_DW.Needunwrappingthrusters_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_DW.manualoverridealpha_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_DW.manualoverridealpha_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_2_DWORK2_m,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_2_DWORK2_m");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_3_DWORK2_h,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_3_DWORK2_h");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_1_DWORK2_h,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_1_DWORK2_h");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_6_DWORK2_e,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_6_DWORK2_e");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_4_DWORK2_j,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_4_DWORK2_j");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.alpha_5_DWORK2_h,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.alpha_5_DWORK2_h");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_5_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_5_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_4_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_4_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_1_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_1_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_6_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_6_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_2_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_2_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_3_DWORK2, count,
        20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_3_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_DW.manualoverridepwm_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_DW.manualoverridepwm_DWORK2");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_2_DWORK2_n,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_2_DWORK2_n");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_3_DWORK2_e,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_3_DWORK2_e");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_1_DWORK2_i,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_1_DWORK2_i");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_6_DWORK2_e,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_6_DWORK2_e");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_4_DWORK2_b,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_4_DWORK2_b");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_DW.pwm_u_5_DWORK2_f,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_DW.pwm_u_5_DWORK2_f");
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
    NIRT_SetValueByDataType(&(u2pwm_X.Integrator6_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(u2pwm_X.Integrator5_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(u2pwm_X.Integrator4_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(u2pwm_X.Integrator3_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(u2pwm_X.Integrator2_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(u2pwm_X.Integrator1_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(u2pwm_X.Integrator_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(u2pwm_X.Integrator7_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(u2pwm_X.Integrator8_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(u2pwm_X.Integrator9_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(u2pwm_X.Integrator10_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(u2pwm_X.Integrator11_CSTATE), 0, contStates[idx++],
      0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&u2pwm_DW.Triangle1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.Circle1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.Cross1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.Square1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.Memory_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_3_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_6_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_2_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_4_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_5_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_2_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_3_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_4_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_5_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_6_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_1_DWORK1_o, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_3_DWORK1_k, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_6_DWORK1_n, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_1_DWORK1_p, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_2_DWORK1_d, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_4_DWORK1_n, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_5_DWORK1_f, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_2_DWORK1_l, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_3_DWORK1_b, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_4_DWORK1_p, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_5_DWORK1_h, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_6_DWORK1_c, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_1_DWORK1_g, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_3_DWORK1_d, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_6_DWORK1_j, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_1_DWORK1_b, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_2_DWORK1_k, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_4_DWORK1_k, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.u_5_DWORK1_fl, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_2_DWORK1_o, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_3_DWORK1_a, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_4_DWORK1_n, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_5_DWORK1_i, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_6_DWORK1_p, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.controlinputuexceedsbounds_DWOR, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.STOP_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.ctrl_DP_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.ctrl_sixaxis2thruster_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.ctrl_custom_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.man_alpha_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.man_alpha_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.man_alpha_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.man_alpha_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.man_alpha_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.man_alpha_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.mechelecenable_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.nowrapping_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.Memory5_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_deg_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.Memory4_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_deg_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.Memory3_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_deg_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.Memory2_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_deg_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.Memory_PreviousInput_p, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_deg_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.Memory1_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_deg_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.Needunwrappingthrusters_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.manualoverridealpha_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_2_DWORK1_g, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_3_DWORK1_d, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_1_DWORK1_j, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_6_DWORK1_d, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_4_DWORK1_a, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.alpha_5_DWORK1_g, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_5_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_4_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_6_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_2_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_3_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.manualoverridepwm_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_2_DWORK1_g, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_3_DWORK1_n, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_1_DWORK1_m, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_6_DWORK1_i, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_4_DWORK1_e, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_5_DWORK1_e, 0, discStates[idx++], 0,
      0);
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.Triangle1_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.Circle1_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.Cross1_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.Square1_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_1_DWORK2, count, discStates[idx++], 20,
        0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_3_DWORK2, count, discStates[idx++], 20,
        0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_6_DWORK2, count, discStates[idx++], 20,
        0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_1_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_2_DWORK2, count, discStates[idx++], 20,
        0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_4_DWORK2, count, discStates[idx++], 20,
        0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_5_DWORK2, count, discStates[idx++], 20,
        0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_2_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_3_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_4_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_5_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_6_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_1_DWORK2_g, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_3_DWORK2_b, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_6_DWORK2_f, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_1_DWORK2_m, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_2_DWORK2_e, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_4_DWORK2_d, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_5_DWORK2_f, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_2_DWORK2_i, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_3_DWORK2_o, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_4_DWORK2_h, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_5_DWORK2_b, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_6_DWORK2_a, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_1_DWORK2_d, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_3_DWORK2_l, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_6_DWORK2_d, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_1_DWORK2_j, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_2_DWORK2_a, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_4_DWORK2_n, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.u_5_DWORK2_i, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_2_DWORK2_f, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_3_DWORK2_n, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_4_DWORK2_g, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_5_DWORK2_bd, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_6_DWORK2_i, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.controlinputuexceedsbounds_DW_c, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.STOP_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.ctrl_DP_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.ctrl_sixaxis2thruster_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.ctrl_custom_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.man_alpha_5_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.man_alpha_4_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.man_alpha_1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.man_alpha_2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.man_alpha_3_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.man_alpha_6_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.mechelecenable_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.nowrapping_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_deg_1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_deg_2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_deg_3_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_deg_4_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_deg_5_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_deg_6_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.Needunwrappingthrusters_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.manualoverridealpha_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_2_DWORK2_m, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_3_DWORK2_h, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_1_DWORK2_h, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_6_DWORK2_e, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_4_DWORK2_j, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.alpha_5_DWORK2_h, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_5_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_4_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_1_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_6_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_2_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_3_DWORK2, count, discStates[idx++],
        20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.manualoverridepwm_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_2_DWORK2_n, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_3_DWORK2_e, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_1_DWORK2_i, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_6_DWORK2_e, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_4_DWORK2_b, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&u2pwm_DW.pwm_u_5_DWORK2_f, count, discStates[idx
        ++], 20, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_u2pwm
