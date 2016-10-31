/*
 * rpm.c
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

#include "rpm.h"
#include "rpm_private.h"

/* Block signals (auto storage) */
B_rpm_T rpm_B;

/* Continuous states */
X_rpm_T rpm_X;

/* Block states (auto storage) */
DW_rpm_T rpm_DW;

/* Real-time model */
RT_MODEL_rpm_T rpm_M_;
RT_MODEL_rpm_T *const rpm_M = &rpm_M_;

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
  int_T nXc = 6;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  rpm_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  rpm_output();
  rpm_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  rpm_output();
  rpm_derivatives();

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
 *    '<Root>/MATLAB Function'
 *    '<Root>/MATLAB Function1'
 *    '<Root>/MATLAB Function2'
 *    '<Root>/MATLAB Function3'
 *    '<Root>/MATLAB Function4'
 *    '<Root>/MATLAB Function5'
 */
void rpm_MATLABFunction(real_T rtu_rpm_tmp, real_T rtu_timer, real_T
  rtu_measurments, real_T rtu_measurment_old, real_T rtu_revolutions_tmp, real_T
  rtu_timeold_tmp, B_MATLABFunction_rpm_T *localB)
{
  real_T rpm_tmp;
  real_T revolutions_tmp;
  real_T timeold_tmp;
  rpm_tmp = rtu_rpm_tmp;
  revolutions_tmp = rtu_revolutions_tmp;
  timeold_tmp = rtu_timeold_tmp;

  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  if (rtu_measurments > rtu_measurment_old) {
    /* '<S1>:1:7' */
    if (rtu_revolutions_tmp >= 20.0) {
      /* '<S1>:1:8' */
      /* //Update RPM every 10 counts, increase this for better RPM resolution, */
      /* //decrease for faster update */
      /* '<S1>:1:11' */
      rpm_tmp = 600.0 * rtu_revolutions_tmp / (rtu_timer - rtu_timeold_tmp);

      /* '<S1>:1:12' */
      timeold_tmp = rtu_timer;

      /* '<S1>:1:13' */
      revolutions_tmp = 0.0;
    } else {
      /* '<S1>:1:15' */
      revolutions_tmp = rtu_revolutions_tmp + 1.0;
    }
  } else {
    if ((rtu_measurments == rtu_measurment_old) && (rtu_timer - rtu_timeold_tmp >
         100.0)) {
      /* '<S1>:1:17' */
      /* '<S1>:1:18' */
      rpm_tmp = 0.0;
    }
  }

  /* '<S1>:1:21' */
  localB->timeold_out = timeold_tmp;

  /* '<S1>:1:22' */
  localB->measurment_tmp = rtu_measurments;

  /* '<S1>:1:23' */
  localB->rpm_n = rpm_tmp;

  /* '<S1>:1:24' */
  localB->revolutions_out = revolutions_tmp;
}

/* Model output function */
void rpm_output(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator;
  real_T rtb_Integrator1;
  real_T rtb_Integrator2;
  real_T rtb_Integrator3;
  real_T rtb_Integrator4;
  real_T rtb_Integrator5;
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* set solver stop time */
    if (!(rpm_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&rpm_M->solverInfo, ((rpm_M->Timing.clockTickH0 + 1)
        * rpm_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&rpm_M->solverInfo, ((rpm_M->Timing.clockTick0 + 1) *
        rpm_M->Timing.stepSize0 + rpm_M->Timing.clockTickH0 *
        rpm_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(rpm_M)) {
    rpm_M->Timing.t[0] = rtsiGetT(&rpm_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Memory: '<Root>/Memory3' */
    rpm_B.Memory3 = rpm_DW.Memory3_PreviousInput;
  }

  /* Integrator: '<Root>/Integrator' */
  rtb_Integrator = rpm_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Memory: '<Root>/Memory' */
    rpm_B.Memory = rpm_DW.Memory_PreviousInput;

    /* Memory: '<Root>/Memory1' */
    rpm_B.Memory1 = rpm_DW.Memory1_PreviousInput;

    /* Memory: '<Root>/Memory2' */
    rpm_B.Memory2 = rpm_DW.Memory2_PreviousInput;
  }

  /* MATLAB Function: '<Root>/MATLAB Function' */
  rpm_MATLABFunction(rpm_B.Memory3, rtb_Integrator, rpm_B.revolutions1,
                     rpm_B.Memory, rpm_B.Memory1, rpm_B.Memory2,
                     &rpm_B.sf_MATLABFunction);

  /* Gain: '<Root>/Gain1' */
  rpm_B.Gain1 = rpm_P.Gain1_Gain * rpm_B.sf_MATLABFunction.rpm_n;
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Memory: '<Root>/Memory7' */
    rpm_B.Memory7 = rpm_DW.Memory7_PreviousInput;
  }

  /* Integrator: '<Root>/Integrator1' */
  rtb_Integrator1 = rpm_X.Integrator1_CSTATE;
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Memory: '<Root>/Memory4' */
    rpm_B.Memory4 = rpm_DW.Memory4_PreviousInput;

    /* Memory: '<Root>/Memory5' */
    rpm_B.Memory5 = rpm_DW.Memory5_PreviousInput;

    /* Memory: '<Root>/Memory6' */
    rpm_B.Memory6 = rpm_DW.Memory6_PreviousInput;
  }

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  rpm_MATLABFunction(rpm_B.Memory7, rtb_Integrator1, rpm_B.revolutions2,
                     rpm_B.Memory4, rpm_B.Memory5, rpm_B.Memory6,
                     &rpm_B.sf_MATLABFunction1);

  /* Gain: '<Root>/Gain2' */
  rpm_B.Gain2 = rpm_P.Gain2_Gain * rpm_B.sf_MATLABFunction1.rpm_n;
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Memory: '<Root>/Memory11' */
    rpm_B.Memory11 = rpm_DW.Memory11_PreviousInput;
  }

  /* Integrator: '<Root>/Integrator2' */
  rtb_Integrator2 = rpm_X.Integrator2_CSTATE;
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Memory: '<Root>/Memory8' */
    rpm_B.Memory8 = rpm_DW.Memory8_PreviousInput;

    /* Memory: '<Root>/Memory9' */
    rpm_B.Memory9 = rpm_DW.Memory9_PreviousInput;

    /* Memory: '<Root>/Memory10' */
    rpm_B.Memory10 = rpm_DW.Memory10_PreviousInput;
  }

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  rpm_MATLABFunction(rpm_B.Memory11, rtb_Integrator2, rpm_B.revolutions3,
                     rpm_B.Memory8, rpm_B.Memory9, rpm_B.Memory10,
                     &rpm_B.sf_MATLABFunction2);

  /* Gain: '<Root>/Gain4' */
  rpm_B.Gain4 = rpm_P.Gain4_Gain * rpm_B.sf_MATLABFunction2.rpm_n;
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Memory: '<Root>/Memory15' */
    rpm_B.Memory15 = rpm_DW.Memory15_PreviousInput;
  }

  /* Integrator: '<Root>/Integrator3' */
  rtb_Integrator3 = rpm_X.Integrator3_CSTATE;
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Memory: '<Root>/Memory12' */
    rpm_B.Memory12 = rpm_DW.Memory12_PreviousInput;

    /* Memory: '<Root>/Memory13' */
    rpm_B.Memory13 = rpm_DW.Memory13_PreviousInput;

    /* Memory: '<Root>/Memory14' */
    rpm_B.Memory14 = rpm_DW.Memory14_PreviousInput;
  }

  /* MATLAB Function: '<Root>/MATLAB Function3' */
  rpm_MATLABFunction(rpm_B.Memory15, rtb_Integrator3, rpm_B.revolutions4,
                     rpm_B.Memory12, rpm_B.Memory13, rpm_B.Memory14,
                     &rpm_B.sf_MATLABFunction3);

  /* Gain: '<Root>/Gain' */
  rpm_B.Gain = rpm_P.Gain_Gain * rpm_B.sf_MATLABFunction3.rpm_n;
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Memory: '<Root>/Memory19' */
    rpm_B.Memory19 = rpm_DW.Memory19_PreviousInput;
  }

  /* Integrator: '<Root>/Integrator4' */
  rtb_Integrator4 = rpm_X.Integrator4_CSTATE;
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Memory: '<Root>/Memory16' */
    rpm_B.Memory16 = rpm_DW.Memory16_PreviousInput;

    /* Memory: '<Root>/Memory17' */
    rpm_B.Memory17 = rpm_DW.Memory17_PreviousInput;

    /* Memory: '<Root>/Memory18' */
    rpm_B.Memory18 = rpm_DW.Memory18_PreviousInput;
  }

  /* MATLAB Function: '<Root>/MATLAB Function4' */
  rpm_MATLABFunction(rpm_B.Memory19, rtb_Integrator4, rpm_B.revolutions5,
                     rpm_B.Memory16, rpm_B.Memory17, rpm_B.Memory18,
                     &rpm_B.sf_MATLABFunction4);

  /* Gain: '<Root>/Gain3' */
  rpm_B.Gain3 = rpm_P.Gain3_Gain * rpm_B.sf_MATLABFunction4.rpm_n;
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Memory: '<Root>/Memory23' */
    rpm_B.Memory23 = rpm_DW.Memory23_PreviousInput;
  }

  /* Integrator: '<Root>/Integrator5' */
  rtb_Integrator5 = rpm_X.Integrator5_CSTATE;
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Memory: '<Root>/Memory20' */
    rpm_B.Memory20 = rpm_DW.Memory20_PreviousInput;

    /* Memory: '<Root>/Memory21' */
    rpm_B.Memory21 = rpm_DW.Memory21_PreviousInput;

    /* Memory: '<Root>/Memory22' */
    rpm_B.Memory22 = rpm_DW.Memory22_PreviousInput;
  }

  /* MATLAB Function: '<Root>/MATLAB Function5' */
  rpm_MATLABFunction(rpm_B.Memory23, rtb_Integrator5, rpm_B.revolutions6,
                     rpm_B.Memory20, rpm_B.Memory21, rpm_B.Memory22,
                     &rpm_B.sf_MATLABFunction5);

  /* Gain: '<Root>/Gain5' */
  rpm_B.Gain5 = rpm_P.Gain5_Gain * rpm_B.sf_MATLABFunction5.rpm_n;
}

/* Model update function */
void rpm_update(void)
{
  if (rtmIsMajorTimeStep(rpm_M)) {
    /* Update for Memory: '<Root>/Memory3' */
    rpm_DW.Memory3_PreviousInput = rpm_B.sf_MATLABFunction.rpm_n;

    /* Update for Memory: '<Root>/Memory' */
    rpm_DW.Memory_PreviousInput = rpm_B.sf_MATLABFunction.measurment_tmp;

    /* Update for Memory: '<Root>/Memory1' */
    rpm_DW.Memory1_PreviousInput = rpm_B.sf_MATLABFunction.revolutions_out;

    /* Update for Memory: '<Root>/Memory2' */
    rpm_DW.Memory2_PreviousInput = rpm_B.sf_MATLABFunction.timeold_out;

    /* Update for Memory: '<Root>/Memory7' */
    rpm_DW.Memory7_PreviousInput = rpm_B.sf_MATLABFunction1.rpm_n;

    /* Update for Memory: '<Root>/Memory4' */
    rpm_DW.Memory4_PreviousInput = rpm_B.sf_MATLABFunction1.measurment_tmp;

    /* Update for Memory: '<Root>/Memory5' */
    rpm_DW.Memory5_PreviousInput = rpm_B.sf_MATLABFunction1.revolutions_out;

    /* Update for Memory: '<Root>/Memory6' */
    rpm_DW.Memory6_PreviousInput = rpm_B.sf_MATLABFunction1.timeold_out;

    /* Update for Memory: '<Root>/Memory11' */
    rpm_DW.Memory11_PreviousInput = rpm_B.sf_MATLABFunction2.rpm_n;

    /* Update for Memory: '<Root>/Memory8' */
    rpm_DW.Memory8_PreviousInput = rpm_B.sf_MATLABFunction2.measurment_tmp;

    /* Update for Memory: '<Root>/Memory9' */
    rpm_DW.Memory9_PreviousInput = rpm_B.sf_MATLABFunction2.revolutions_out;

    /* Update for Memory: '<Root>/Memory10' */
    rpm_DW.Memory10_PreviousInput = rpm_B.sf_MATLABFunction2.timeold_out;

    /* Update for Memory: '<Root>/Memory15' */
    rpm_DW.Memory15_PreviousInput = rpm_B.sf_MATLABFunction3.rpm_n;

    /* Update for Memory: '<Root>/Memory12' */
    rpm_DW.Memory12_PreviousInput = rpm_B.sf_MATLABFunction3.measurment_tmp;

    /* Update for Memory: '<Root>/Memory13' */
    rpm_DW.Memory13_PreviousInput = rpm_B.sf_MATLABFunction3.revolutions_out;

    /* Update for Memory: '<Root>/Memory14' */
    rpm_DW.Memory14_PreviousInput = rpm_B.sf_MATLABFunction3.timeold_out;

    /* Update for Memory: '<Root>/Memory19' */
    rpm_DW.Memory19_PreviousInput = rpm_B.sf_MATLABFunction4.rpm_n;

    /* Update for Memory: '<Root>/Memory16' */
    rpm_DW.Memory16_PreviousInput = rpm_B.sf_MATLABFunction4.measurment_tmp;

    /* Update for Memory: '<Root>/Memory17' */
    rpm_DW.Memory17_PreviousInput = rpm_B.sf_MATLABFunction4.revolutions_out;

    /* Update for Memory: '<Root>/Memory18' */
    rpm_DW.Memory18_PreviousInput = rpm_B.sf_MATLABFunction4.timeold_out;

    /* Update for Memory: '<Root>/Memory23' */
    rpm_DW.Memory23_PreviousInput = rpm_B.sf_MATLABFunction5.rpm_n;

    /* Update for Memory: '<Root>/Memory20' */
    rpm_DW.Memory20_PreviousInput = rpm_B.sf_MATLABFunction5.measurment_tmp;

    /* Update for Memory: '<Root>/Memory21' */
    rpm_DW.Memory21_PreviousInput = rpm_B.sf_MATLABFunction5.revolutions_out;

    /* Update for Memory: '<Root>/Memory22' */
    rpm_DW.Memory22_PreviousInput = rpm_B.sf_MATLABFunction5.timeold_out;
  }

  if (rtmIsMajorTimeStep(rpm_M)) {
    rt_ertODEUpdateContinuousStates(&rpm_M->solverInfo);
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
  if (!(++rpm_M->Timing.clockTick0)) {
    ++rpm_M->Timing.clockTickH0;
  }

  rpm_M->Timing.t[0] = rtsiGetSolverStopTime(&rpm_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++rpm_M->Timing.clockTick1)) {
      ++rpm_M->Timing.clockTickH1;
    }

    rpm_M->Timing.t[1] = rpm_M->Timing.clockTick1 * rpm_M->Timing.stepSize1 +
      rpm_M->Timing.clockTickH1 * rpm_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void rpm_derivatives(void)
{
  XDot_rpm_T *_rtXdot;
  _rtXdot = ((XDot_rpm_T *) rpm_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' incorporates:
   *  Constant: '<Root>/Constant'
   */
  _rtXdot->Integrator_CSTATE = rpm_P.Constant_Value;

  /* Derivatives for Integrator: '<Root>/Integrator1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  _rtXdot->Integrator1_CSTATE = rpm_P.Constant1_Value;

  /* Derivatives for Integrator: '<Root>/Integrator2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  _rtXdot->Integrator2_CSTATE = rpm_P.Constant2_Value;

  /* Derivatives for Integrator: '<Root>/Integrator3' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  _rtXdot->Integrator3_CSTATE = rpm_P.Constant3_Value;

  /* Derivatives for Integrator: '<Root>/Integrator4' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  _rtXdot->Integrator4_CSTATE = rpm_P.Constant4_Value;

  /* Derivatives for Integrator: '<Root>/Integrator5' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  _rtXdot->Integrator5_CSTATE = rpm_P.Constant5_Value;
}

/* Model initialize function */
void rpm_initialize(void)
{
  /* InitializeConditions for Memory: '<Root>/Memory3' */
  rpm_DW.Memory3_PreviousInput = rpm_P.Memory3_X0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  rpm_X.Integrator_CSTATE = rpm_P.Integrator_IC;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  rpm_DW.Memory_PreviousInput = rpm_P.Memory_X0;

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  rpm_DW.Memory1_PreviousInput = rpm_P.Memory1_X0;

  /* InitializeConditions for Memory: '<Root>/Memory2' */
  rpm_DW.Memory2_PreviousInput = rpm_P.Memory2_X0;

  /* InitializeConditions for Memory: '<Root>/Memory7' */
  rpm_DW.Memory7_PreviousInput = rpm_P.Memory7_X0;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  rpm_X.Integrator1_CSTATE = rpm_P.Integrator1_IC;

  /* InitializeConditions for Memory: '<Root>/Memory4' */
  rpm_DW.Memory4_PreviousInput = rpm_P.Memory4_X0;

  /* InitializeConditions for Memory: '<Root>/Memory5' */
  rpm_DW.Memory5_PreviousInput = rpm_P.Memory5_X0;

  /* InitializeConditions for Memory: '<Root>/Memory6' */
  rpm_DW.Memory6_PreviousInput = rpm_P.Memory6_X0;

  /* InitializeConditions for Memory: '<Root>/Memory11' */
  rpm_DW.Memory11_PreviousInput = rpm_P.Memory11_X0;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  rpm_X.Integrator2_CSTATE = rpm_P.Integrator2_IC;

  /* InitializeConditions for Memory: '<Root>/Memory8' */
  rpm_DW.Memory8_PreviousInput = rpm_P.Memory8_X0;

  /* InitializeConditions for Memory: '<Root>/Memory9' */
  rpm_DW.Memory9_PreviousInput = rpm_P.Memory9_X0;

  /* InitializeConditions for Memory: '<Root>/Memory10' */
  rpm_DW.Memory10_PreviousInput = rpm_P.Memory10_X0;

  /* InitializeConditions for Memory: '<Root>/Memory15' */
  rpm_DW.Memory15_PreviousInput = rpm_P.Memory15_X0;

  /* InitializeConditions for Integrator: '<Root>/Integrator3' */
  rpm_X.Integrator3_CSTATE = rpm_P.Integrator3_IC;

  /* InitializeConditions for Memory: '<Root>/Memory12' */
  rpm_DW.Memory12_PreviousInput = rpm_P.Memory12_X0;

  /* InitializeConditions for Memory: '<Root>/Memory13' */
  rpm_DW.Memory13_PreviousInput = rpm_P.Memory13_X0;

  /* InitializeConditions for Memory: '<Root>/Memory14' */
  rpm_DW.Memory14_PreviousInput = rpm_P.Memory14_X0;

  /* InitializeConditions for Memory: '<Root>/Memory19' */
  rpm_DW.Memory19_PreviousInput = rpm_P.Memory19_X0;

  /* InitializeConditions for Integrator: '<Root>/Integrator4' */
  rpm_X.Integrator4_CSTATE = rpm_P.Integrator4_IC;

  /* InitializeConditions for Memory: '<Root>/Memory16' */
  rpm_DW.Memory16_PreviousInput = rpm_P.Memory16_X0;

  /* InitializeConditions for Memory: '<Root>/Memory17' */
  rpm_DW.Memory17_PreviousInput = rpm_P.Memory17_X0;

  /* InitializeConditions for Memory: '<Root>/Memory18' */
  rpm_DW.Memory18_PreviousInput = rpm_P.Memory18_X0;

  /* InitializeConditions for Memory: '<Root>/Memory23' */
  rpm_DW.Memory23_PreviousInput = rpm_P.Memory23_X0;

  /* InitializeConditions for Integrator: '<Root>/Integrator5' */
  rpm_X.Integrator5_CSTATE = rpm_P.Integrator5_IC;

  /* InitializeConditions for Memory: '<Root>/Memory20' */
  rpm_DW.Memory20_PreviousInput = rpm_P.Memory20_X0;

  /* InitializeConditions for Memory: '<Root>/Memory21' */
  rpm_DW.Memory21_PreviousInput = rpm_P.Memory21_X0;

  /* InitializeConditions for Memory: '<Root>/Memory22' */
  rpm_DW.Memory22_PreviousInput = rpm_P.Memory22_X0;
}

/* Model terminate function */
void rpm_terminate(void)
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
  rpm_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  rpm_update();
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
  rpm_initialize();
}

void MdlTerminate(void)
{
  rpm_terminate();
}

/* Registration function */
RT_MODEL_rpm_T *rpm(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)rpm_M, 0,
                sizeof(RT_MODEL_rpm_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rpm_M->solverInfo, &rpm_M->Timing.simTimeStep);
    rtsiSetTPtr(&rpm_M->solverInfo, &rtmGetTPtr(rpm_M));
    rtsiSetStepSizePtr(&rpm_M->solverInfo, &rpm_M->Timing.stepSize0);
    rtsiSetdXPtr(&rpm_M->solverInfo, &rpm_M->ModelData.derivs);
    rtsiSetContStatesPtr(&rpm_M->solverInfo, (real_T **)
                         &rpm_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&rpm_M->solverInfo, &rpm_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&rpm_M->solverInfo, (&rtmGetErrorStatus(rpm_M)));
    rtsiSetRTModelPtr(&rpm_M->solverInfo, rpm_M);
  }

  rtsiSetSimTimeStep(&rpm_M->solverInfo, MAJOR_TIME_STEP);
  rpm_M->ModelData.intgData.y = rpm_M->ModelData.odeY;
  rpm_M->ModelData.intgData.f[0] = rpm_M->ModelData.odeF[0];
  rpm_M->ModelData.intgData.f[1] = rpm_M->ModelData.odeF[1];
  rpm_M->ModelData.intgData.f[2] = rpm_M->ModelData.odeF[2];
  rpm_M->ModelData.contStates = ((real_T *) &rpm_X);
  rtsiSetSolverData(&rpm_M->solverInfo, (void *)&rpm_M->ModelData.intgData);
  rtsiSetSolverName(&rpm_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = rpm_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    rpm_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    rpm_M->Timing.sampleTimes = (&rpm_M->Timing.sampleTimesArray[0]);
    rpm_M->Timing.offsetTimes = (&rpm_M->Timing.offsetTimesArray[0]);

    /* task periods */
    rpm_M->Timing.sampleTimes[0] = (0.0);
    rpm_M->Timing.sampleTimes[1] = (0.2);

    /* task offsets */
    rpm_M->Timing.offsetTimes[0] = (0.0);
    rpm_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(rpm_M, &rpm_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = rpm_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    rpm_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(rpm_M, -1);
  rpm_M->Timing.stepSize0 = 0.2;
  rpm_M->Timing.stepSize1 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rpm_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(rpm_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(rpm_M->rtwLogInfo, (NULL));
    rtliSetLogT(rpm_M->rtwLogInfo, "tout");
    rtliSetLogX(rpm_M->rtwLogInfo, "");
    rtliSetLogXFinal(rpm_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(rpm_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(rpm_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(rpm_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(rpm_M->rtwLogInfo, 1);
    rtliSetLogY(rpm_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(rpm_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(rpm_M->rtwLogInfo, (NULL));
  }

  rpm_M->solverInfoPtr = (&rpm_M->solverInfo);
  rpm_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&rpm_M->solverInfo, 0.2);
  rtsiSetSolverMode(&rpm_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  rpm_M->ModelData.blockIO = ((void *) &rpm_B);
  (void) memset(((void *) &rpm_B), 0,
                sizeof(B_rpm_T));

  /* parameters */
  rpm_M->ModelData.defaultParam = ((real_T *)&rpm_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &rpm_X;
    rpm_M->ModelData.contStates = (x);
    (void) memset((void *)&rpm_X, 0,
                  sizeof(X_rpm_T));
  }

  /* states (dwork) */
  rpm_M->ModelData.dwork = ((void *) &rpm_DW);
  (void) memset((void *)&rpm_DW, 0,
                sizeof(DW_rpm_T));

  /* Initialize Sizes */
  rpm_M->Sizes.numContStates = (6);    /* Number of continuous states */
  rpm_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  rpm_M->Sizes.numY = (0);             /* Number of model outputs */
  rpm_M->Sizes.numU = (0);             /* Number of model inputs */
  rpm_M->Sizes.sysDirFeedThru = (0);   /* The model is not direct feedthrough */
  rpm_M->Sizes.numSampTimes = (2);     /* Number of sample times */
  rpm_M->Sizes.numBlocks = (73);       /* Number of blocks */
  rpm_M->Sizes.numBlockIO = (60);      /* Number of block outputs */
  rpm_M->Sizes.numBlockPrms = (186);   /* Sum of parameter "widths" */
  return rpm_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : rpm
 * Model version : 1.68
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Sun Jun 26 19:52:37 2016
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_rpm
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

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 17:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern rpm_rtModel *S;
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

  // rpm/revolutions1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&rpm_B.revolutions1, 0, data[index++], 27, 0);
  } else {
    index += 1;
  }

  // rpm/revolutions2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&rpm_B.revolutions2, 0, data[index++], 27, 0);
  } else {
    index += 1;
  }

  // rpm/revolutions3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&rpm_B.revolutions3, 0, data[index++], 27, 0);
  } else {
    index += 1;
  }

  // rpm/revolutions4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&rpm_B.revolutions4, 0, data[index++], 27, 0);
  } else {
    index += 1;
  }

  // rpm/revolutions5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&rpm_B.revolutions5, 0, data[index++], 27, 0);
  } else {
    index += 1;
  }

  // rpm/revolutions6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&rpm_B.revolutions6, 0, data[index++], 27, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 6;
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

  // rpm/rpm1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&rpm_B.Gain1, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/measurment1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&rpm_B.sf_MATLABFunction.measurment_tmp, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/revolution1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&rpm_B.sf_MATLABFunction.revolutions_out, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/measurment2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&rpm_B.sf_MATLABFunction1.measurment_tmp, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/revolution2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&rpm_B.sf_MATLABFunction1.revolutions_out, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/rpm2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&rpm_B.Gain2, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/measurment3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&rpm_B.sf_MATLABFunction2.measurment_tmp, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/revolution3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&rpm_B.sf_MATLABFunction2.revolutions_out, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/rpm3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&rpm_B.Gain4, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/measurment4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&rpm_B.sf_MATLABFunction3.measurment_tmp, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/revolution4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&rpm_B.sf_MATLABFunction3.revolutions_out, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/rpm4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&rpm_B.Gain, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/measurment5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&rpm_B.sf_MATLABFunction4.measurment_tmp, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/revolution5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&rpm_B.sf_MATLABFunction4.revolutions_out, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/rpm5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&rpm_B.Gain3, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/measurment6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&rpm_B.sf_MATLABFunction5.measurment_tmp, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/revolution6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&rpm_B.sf_MATLABFunction5.revolutions_out, 0, 27, 0);
  } else {
    index += 1;
  }

  // rpm/rpm6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&rpm_B.Gain5, 0, 27, 0);
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

  // rpm/rpm1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&rpm_B.Gain1, 0, 27, 0);

  // rpm/measurment1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&rpm_B.sf_MATLABFunction.measurment_tmp, 0, 27, 0);

  // rpm/revolution1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&rpm_B.sf_MATLABFunction.revolutions_out, 0, 27, 0);

  // rpm/measurment2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&rpm_B.sf_MATLABFunction1.measurment_tmp, 0, 27, 0);

  // rpm/revolution2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&rpm_B.sf_MATLABFunction1.revolutions_out, 0, 27, 0);

  // rpm/rpm2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&rpm_B.Gain2, 0, 27, 0);

  // rpm/measurment3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&rpm_B.sf_MATLABFunction2.measurment_tmp, 0, 27, 0);

  // rpm/revolution3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&rpm_B.sf_MATLABFunction2.revolutions_out, 0, 27, 0);

  // rpm/rpm3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&rpm_B.Gain4, 0, 27, 0);

  // rpm/measurment4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&rpm_B.sf_MATLABFunction3.measurment_tmp, 0, 27, 0);

  // rpm/revolution4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&rpm_B.sf_MATLABFunction3.revolutions_out, 0, 27, 0);

  // rpm/rpm4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&rpm_B.Gain, 0, 27, 0);

  // rpm/measurment5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&rpm_B.sf_MATLABFunction4.measurment_tmp, 0, 27, 0);

  // rpm/revolution5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&rpm_B.sf_MATLABFunction4.revolutions_out, 0, 27, 0);

  // rpm/rpm5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&rpm_B.Gain3, 0, 27, 0);

  // rpm/measurment6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&rpm_B.sf_MATLABFunction5.measurment_tmp, 0, 27, 0);

  // rpm/revolution6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&rpm_B.sf_MATLABFunction5.revolutions_out, 0, 27, 0);

  // rpm/rpm6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&rpm_B.Gain5, 0, 27, 0);
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
  { 0, "rpm/Memory3/X0", offsetof(P_rpm_T, Memory3_X0), 27, 1, 2, 0, 0 },

  { 1, "rpm/Integrator/InitialCondition", offsetof(P_rpm_T, Integrator_IC), 27,
    1, 2, 2, 0 },

  { 2, "rpm/Memory/X0", offsetof(P_rpm_T, Memory_X0), 27, 1, 2, 4, 0 },

  { 3, "rpm/Memory1/X0", offsetof(P_rpm_T, Memory1_X0), 27, 1, 2, 6, 0 },

  { 4, "rpm/Memory2/X0", offsetof(P_rpm_T, Memory2_X0), 27, 1, 2, 8, 0 },

  { 5, "rpm/Gain1/Gain", offsetof(P_rpm_T, Gain1_Gain), 27, 1, 2, 10, 0 },

  { 6, "rpm/Constant/Value", offsetof(P_rpm_T, Constant_Value), 27, 1, 2, 12, 0
  },

  { 7, "rpm/Memory7/X0", offsetof(P_rpm_T, Memory7_X0), 27, 1, 2, 14, 0 },

  { 8, "rpm/Integrator1/InitialCondition", offsetof(P_rpm_T, Integrator1_IC), 27,
    1, 2, 16, 0 },

  { 9, "rpm/Memory4/X0", offsetof(P_rpm_T, Memory4_X0), 27, 1, 2, 18, 0 },

  { 10, "rpm/Memory5/X0", offsetof(P_rpm_T, Memory5_X0), 27, 1, 2, 20, 0 },

  { 11, "rpm/Memory6/X0", offsetof(P_rpm_T, Memory6_X0), 27, 1, 2, 22, 0 },

  { 12, "rpm/Gain2/Gain", offsetof(P_rpm_T, Gain2_Gain), 27, 1, 2, 24, 0 },

  { 13, "rpm/Constant1/Value", offsetof(P_rpm_T, Constant1_Value), 27, 1, 2, 26,
    0 },

  { 14, "rpm/Memory11/X0", offsetof(P_rpm_T, Memory11_X0), 27, 1, 2, 28, 0 },

  { 15, "rpm/Integrator2/InitialCondition", offsetof(P_rpm_T, Integrator2_IC),
    27, 1, 2, 30, 0 },

  { 16, "rpm/Memory8/X0", offsetof(P_rpm_T, Memory8_X0), 27, 1, 2, 32, 0 },

  { 17, "rpm/Memory9/X0", offsetof(P_rpm_T, Memory9_X0), 27, 1, 2, 34, 0 },

  { 18, "rpm/Memory10/X0", offsetof(P_rpm_T, Memory10_X0), 27, 1, 2, 36, 0 },

  { 19, "rpm/Gain4/Gain", offsetof(P_rpm_T, Gain4_Gain), 27, 1, 2, 38, 0 },

  { 20, "rpm/Constant2/Value", offsetof(P_rpm_T, Constant2_Value), 27, 1, 2, 40,
    0 },

  { 21, "rpm/Memory15/X0", offsetof(P_rpm_T, Memory15_X0), 27, 1, 2, 42, 0 },

  { 22, "rpm/Integrator3/InitialCondition", offsetof(P_rpm_T, Integrator3_IC),
    27, 1, 2, 44, 0 },

  { 23, "rpm/Memory12/X0", offsetof(P_rpm_T, Memory12_X0), 27, 1, 2, 46, 0 },

  { 24, "rpm/Memory13/X0", offsetof(P_rpm_T, Memory13_X0), 27, 1, 2, 48, 0 },

  { 25, "rpm/Memory14/X0", offsetof(P_rpm_T, Memory14_X0), 27, 1, 2, 50, 0 },

  { 26, "rpm/Gain/Gain", offsetof(P_rpm_T, Gain_Gain), 27, 1, 2, 52, 0 },

  { 27, "rpm/Constant3/Value", offsetof(P_rpm_T, Constant3_Value), 27, 1, 2, 54,
    0 },

  { 28, "rpm/Memory19/X0", offsetof(P_rpm_T, Memory19_X0), 27, 1, 2, 56, 0 },

  { 29, "rpm/Integrator4/InitialCondition", offsetof(P_rpm_T, Integrator4_IC),
    27, 1, 2, 58, 0 },

  { 30, "rpm/Memory16/X0", offsetof(P_rpm_T, Memory16_X0), 27, 1, 2, 60, 0 },

  { 31, "rpm/Memory17/X0", offsetof(P_rpm_T, Memory17_X0), 27, 1, 2, 62, 0 },

  { 32, "rpm/Memory18/X0", offsetof(P_rpm_T, Memory18_X0), 27, 1, 2, 64, 0 },

  { 33, "rpm/Gain3/Gain", offsetof(P_rpm_T, Gain3_Gain), 27, 1, 2, 66, 0 },

  { 34, "rpm/Constant4/Value", offsetof(P_rpm_T, Constant4_Value), 27, 1, 2, 68,
    0 },

  { 35, "rpm/Memory23/X0", offsetof(P_rpm_T, Memory23_X0), 27, 1, 2, 70, 0 },

  { 36, "rpm/Integrator5/InitialCondition", offsetof(P_rpm_T, Integrator5_IC),
    27, 1, 2, 72, 0 },

  { 37, "rpm/Memory20/X0", offsetof(P_rpm_T, Memory20_X0), 27, 1, 2, 74, 0 },

  { 38, "rpm/Memory21/X0", offsetof(P_rpm_T, Memory21_X0), 27, 1, 2, 76, 0 },

  { 39, "rpm/Memory22/X0", offsetof(P_rpm_T, Memory22_X0), 27, 1, 2, 78, 0 },

  { 40, "rpm/Gain5/Gain", offsetof(P_rpm_T, Gain5_Gain), 27, 1, 2, 80, 0 },

  { 41, "rpm/Constant5/Value", offsetof(P_rpm_T, Constant5_Value), 27, 1, 2, 82,
    0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 42;
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
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "rpm/Memory3", 0, "", offsetof(B_rpm_T, Memory3) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 1, "rpm/revolutions1", 0, "", offsetof(B_rpm_T, revolutions1) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 2, "rpm/Memory", 0, "", offsetof(B_rpm_T, Memory) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 3, "rpm/Memory1", 0, "", offsetof(B_rpm_T, Memory1) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 4, "rpm/Memory2", 0, "", offsetof(B_rpm_T, Memory2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "rpm/Gain1", 0, "", offsetof(B_rpm_T, Gain1) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 6, "rpm/revolutions2", 0, "", offsetof(B_rpm_T, revolutions2) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 7, "rpm/revolutions3", 0, "", offsetof(B_rpm_T, revolutions3) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 8, "rpm/Memory7", 0, "", offsetof(B_rpm_T, Memory7) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 9, "rpm/Memory4", 0, "", offsetof(B_rpm_T, Memory4) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 10, "rpm/Memory5", 0, "", offsetof(B_rpm_T, Memory5) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 11, "rpm/Memory6", 0, "", offsetof(B_rpm_T, Memory6) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "rpm/revolutions4", 0, "", offsetof(B_rpm_T, revolutions4) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 13, "rpm/revolutions5", 0, "", offsetof(B_rpm_T, revolutions5) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 14, "rpm/Gain2", 0, "", offsetof(B_rpm_T, Gain2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 15, "rpm/revolutions6", 0, "", offsetof(B_rpm_T, revolutions6) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 16, "rpm/Memory11", 0, "", offsetof(B_rpm_T, Memory11) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 17, "rpm/Memory8", 0, "", offsetof(B_rpm_T, Memory8) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 18, "rpm/Memory9", 0, "", offsetof(B_rpm_T, Memory9) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 19, "rpm/Memory10", 0, "", offsetof(B_rpm_T, Memory10) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "rpm/Gain4", 0, "", offsetof(B_rpm_T, Gain4) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 21, "rpm/Memory15", 0, "", offsetof(B_rpm_T, Memory15) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 22, "rpm/Memory12", 0, "", offsetof(B_rpm_T, Memory12) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 23, "rpm/Memory13", 0, "", offsetof(B_rpm_T, Memory13) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 24, "rpm/Memory14", 0, "", offsetof(B_rpm_T, Memory14) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 25, "rpm/Gain", 0, "", offsetof(B_rpm_T, Gain) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 26, "rpm/Memory19", 0, "", offsetof(B_rpm_T, Memory19) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 27, "rpm/Memory16", 0, "", offsetof(B_rpm_T, Memory16) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 28, "rpm/Memory17", 0, "", offsetof(B_rpm_T, Memory17) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 29, "rpm/Memory18", 0, "", offsetof(B_rpm_T, Memory18) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 30, "rpm/Gain3", 0, "", offsetof(B_rpm_T, Gain3) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 31, "rpm/Memory23", 0, "", offsetof(B_rpm_T, Memory23) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 32, "rpm/Memory20", 0, "", offsetof(B_rpm_T, Memory20) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 33, "rpm/Memory21", 0, "", offsetof(B_rpm_T, Memory21) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 34, "rpm/Memory22", 0, "", offsetof(B_rpm_T, Memory22) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 35, "rpm/Gain5", 0, "", offsetof(B_rpm_T, Gain5) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 36, "rpm/MATLAB Function5", 0, "", offsetof(B_rpm_T,
    sf_MATLABFunction5.rpm_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0
  },

  { 37, "rpm/MATLAB Function5", 1, "", offsetof(B_rpm_T,
    sf_MATLABFunction5.measurment_tmp) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1,
    2, 0, 0 },

  { 38, "rpm/MATLAB Function5", 2, "", offsetof(B_rpm_T,
    sf_MATLABFunction5.revolutions_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1,
    2, 0, 0 },

  { 39, "rpm/MATLAB Function5", 3, "", offsetof(B_rpm_T,
    sf_MATLABFunction5.timeold_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 40, "rpm/MATLAB Function4", 0, "", offsetof(B_rpm_T,
    sf_MATLABFunction4.rpm_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0
  },

  { 41, "rpm/MATLAB Function4", 1, "", offsetof(B_rpm_T,
    sf_MATLABFunction4.measurment_tmp) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1,
    2, 0, 0 },

  { 42, "rpm/MATLAB Function4", 2, "", offsetof(B_rpm_T,
    sf_MATLABFunction4.revolutions_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1,
    2, 0, 0 },

  { 43, "rpm/MATLAB Function4", 3, "", offsetof(B_rpm_T,
    sf_MATLABFunction4.timeold_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 44, "rpm/MATLAB Function3", 0, "", offsetof(B_rpm_T,
    sf_MATLABFunction3.rpm_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0
  },

  { 45, "rpm/MATLAB Function3", 1, "", offsetof(B_rpm_T,
    sf_MATLABFunction3.measurment_tmp) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1,
    2, 0, 0 },

  { 46, "rpm/MATLAB Function3", 2, "", offsetof(B_rpm_T,
    sf_MATLABFunction3.revolutions_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1,
    2, 0, 0 },

  { 47, "rpm/MATLAB Function3", 3, "", offsetof(B_rpm_T,
    sf_MATLABFunction3.timeold_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 48, "rpm/MATLAB Function2", 0, "", offsetof(B_rpm_T,
    sf_MATLABFunction2.rpm_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0
  },

  { 49, "rpm/MATLAB Function2", 1, "", offsetof(B_rpm_T,
    sf_MATLABFunction2.measurment_tmp) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1,
    2, 0, 0 },

  { 50, "rpm/MATLAB Function2", 2, "", offsetof(B_rpm_T,
    sf_MATLABFunction2.revolutions_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1,
    2, 0, 0 },

  { 51, "rpm/MATLAB Function2", 3, "", offsetof(B_rpm_T,
    sf_MATLABFunction2.timeold_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 52, "rpm/MATLAB Function1", 0, "", offsetof(B_rpm_T,
    sf_MATLABFunction1.rpm_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0
  },

  { 53, "rpm/MATLAB Function1", 1, "", offsetof(B_rpm_T,
    sf_MATLABFunction1.measurment_tmp) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1,
    2, 0, 0 },

  { 54, "rpm/MATLAB Function1", 2, "", offsetof(B_rpm_T,
    sf_MATLABFunction1.revolutions_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1,
    2, 0, 0 },

  { 55, "rpm/MATLAB Function1", 3, "", offsetof(B_rpm_T,
    sf_MATLABFunction1.timeold_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 56, "rpm/MATLAB Function", 0, "", offsetof(B_rpm_T, sf_MATLABFunction.rpm_n)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 57, "rpm/MATLAB Function", 1, "", offsetof(B_rpm_T,
    sf_MATLABFunction.measurment_tmp) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1,
    2, 0, 0 },

  { 58, "rpm/MATLAB Function", 2, "", offsetof(B_rpm_T,
    sf_MATLABFunction.revolutions_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1,
    2, 0, 0 },

  { 59, "rpm/MATLAB Function", 3, "", offsetof(B_rpm_T,
    sf_MATLABFunction.timeold_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 60;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 24;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "revolutions1", 0, EXT_IN, 1, 1, 1 },

  { 2, "revolutions2", 0, EXT_IN, 1, 1, 1 },

  { 3, "revolutions3", 0, EXT_IN, 1, 1, 1 },

  { 4, "revolutions4", 0, EXT_IN, 1, 1, 1 },

  { 5, "revolutions5", 0, EXT_IN, 1, 1, 1 },

  { 6, "revolutions6", 0, EXT_IN, 1, 1, 1 },

  { 1, "rpm1", 0, EXT_OUT, 1, 1, 1 },

  { 2, "measurment1", 0, EXT_OUT, 1, 1, 1 },

  { 3, "revolution1", 0, EXT_OUT, 1, 1, 1 },

  { 4, "measurment2", 0, EXT_OUT, 1, 1, 1 },

  { 5, "revolution2", 0, EXT_OUT, 1, 1, 1 },

  { 6, "rpm2", 0, EXT_OUT, 1, 1, 1 },

  { 7, "measurment3", 0, EXT_OUT, 1, 1, 1 },

  { 8, "revolution3", 0, EXT_OUT, 1, 1, 1 },

  { 9, "rpm3", 0, EXT_OUT, 1, 1, 1 },

  { 10, "measurment4", 0, EXT_OUT, 1, 1, 1 },

  { 11, "revolution4", 0, EXT_OUT, 1, 1, 1 },

  { 12, "rpm4", 0, EXT_OUT, 1, 1, 1 },

  { 13, "measurment5", 0, EXT_OUT, 1, 1, 1 },

  { 14, "revolution5", 0, EXT_OUT, 1, 1, 1 },

  { 15, "rpm5", 0, EXT_OUT, 1, 1, 1 },

  { 16, "measurment6", 0, EXT_OUT, 1, 1, 1 },

  { 17, "revolution6", 0, EXT_OUT, 1, 1, 1 },

  { 18, "rpm6", 0, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.2, 0 }
};

int32_t NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static const char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "rpm";
static const char* NI_CompiledModelVersion = "1.68";
static const char* NI_CompiledModelDateTime = "Sun Jun 26 19:52:37 2016";
static const char* NI_builder DataSection(".NIVS.builder") =
  "NI Model Framework 2015.0.1.0 (2015 f1) for Simulink Coder 8.8 (R2015a)";
static const char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2015.0.1.0";

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
 *		Helper function to probe one	signal. baseaddr must NOT be VIRTUAL_SIG
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
static int32_t NI_ProbeOneSignal(int32_t idx, double *value, int32_t len,
  int32_t *count, int32_t vOffset, int32_t vLength)
{
  char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ?
                      S->ModelData.blockIO : S->ModelData.inputs) + (uintptr_t)
    NI_SigList[idx].addr;
  int32_t subindex = (vLength == -1) ? 0 : vOffset;
  int32_t sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength +
    vOffset);
  while ((subindex < sublength) && (*count < len))
    value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++, NI_SigList[idx]
      .datatype, NI_SigList[idx].IsComplex);
  return *count;
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
  memcpy(&rtParameter[0], &rpm_P, sizeof(P_rpm_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka rpm_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_rpm_T));
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
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_rpm_T));
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
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof(P_rpm_T));
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
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_rpm_T));
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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_rpm_T));
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
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_rpm_T));
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
      *numContStates = 6;
      *numDiscStates = 144;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(rpm_X.Integrator_CSTATE), 0, 0,
      0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(rpm_X.Integrator1_CSTATE), 0, 0,
      0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(rpm_X.Integrator2_CSTATE), 0, 0,
      0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(rpm_X.Integrator3_CSTATE), 0, 0,
      0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(rpm_X.Integrator4_CSTATE), 0, 0,
      0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(rpm_X.Integrator5_CSTATE), 0, 0,
      0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator5_CSTATE");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory3_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory3_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory_PreviousInput, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory1_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory2_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory7_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory7_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory4_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory4_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory5_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory5_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory6_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory6_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory11_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory11_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory8_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory8_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory9_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory9_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory10_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory10_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory15_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory15_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory12_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory12_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory13_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory13_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory14_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory14_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory19_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory19_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory16_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory16_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory17_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory17_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory18_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory18_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory23_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory23_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory20_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory20_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory21_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory21_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.Memory22_PreviousInput, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.Memory22_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions1_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions1_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions1_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions1_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm1_DWORK2, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm1_DWORK2, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm1_DWORK2, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm1_DWORK2, 3, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment1_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment1_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment1_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment1_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions2_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions2_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions2_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions2_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution1_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution1_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution1_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution1_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution1_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions3_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions3_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions3_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions3_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment2_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment2_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment2_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment2_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions4_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions4_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions4_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions4_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution2_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution2_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution2_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution2_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions5_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions5_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions5_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions5_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm2_DWORK2, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm2_DWORK2, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm2_DWORK2, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm2_DWORK2, 3, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm2_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions6_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions6_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions6_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolutions6_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolutions6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment3_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment3_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment3_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment3_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution3_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution3_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution3_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution3_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm3_DWORK2, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm3_DWORK2, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm3_DWORK2, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm3_DWORK2, 3, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm3_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment4_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment4_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment4_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment4_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution4_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution4_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution4_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution4_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm4_DWORK2, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm4_DWORK2, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm4_DWORK2, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm4_DWORK2, 3, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm4_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment5_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment5_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment5_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment5_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution5_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution5_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution5_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution5_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm5_DWORK2, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm5_DWORK2, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm5_DWORK2, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm5_DWORK2, 3, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm5_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment6_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment6_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment6_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.measurment6_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.measurment6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution6_DWORK2, 0, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution6_DWORK2, 1, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution6_DWORK2, 2, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.revolution6_DWORK2, 3, 17,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.revolution6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm6_DWORK2, 0, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm6_DWORK2, 1, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm6_DWORK2, 2, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm6_DWORK2");
    discStates[idx] = NIRT_GetValueByDataType(&rpm_DW.rpm6_DWORK2, 3, 17, 0);
    strcpy(discStatesNames + (idx++ * 100), "&rpm_DW.rpm6_DWORK2");
  }

  if ((clockTicks != NULL) && (clockTicksNames != NULL)) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  UNUSED_PARAMETER(count);
  UNUSED_PARAMETER(idx);
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
    NIRT_SetValueByDataType(&(rpm_X.Integrator_CSTATE), 0, contStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&(rpm_X.Integrator1_CSTATE), 0, contStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&(rpm_X.Integrator2_CSTATE), 0, contStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&(rpm_X.Integrator3_CSTATE), 0, contStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&(rpm_X.Integrator4_CSTATE), 0, contStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&(rpm_X.Integrator5_CSTATE), 0, contStates[idx++], 0,
      0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&rpm_DW.Memory3_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.Memory_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory1_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory2_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&rpm_DW.measurment1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.Memory7_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory4_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory5_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory6_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.measurment2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.rpm2_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.Memory11_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory8_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory9_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory10_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.measurment3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.rpm3_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory15_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory12_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory13_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory14_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.measurment4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.rpm4_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory19_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory16_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory17_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory18_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.measurment5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.rpm5_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory23_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory20_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory21_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.Memory22_PreviousInput, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&rpm_DW.measurment6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&rpm_DW.rpm6_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions1_DWORK2, 0, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions1_DWORK2, 1, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions1_DWORK2, 2, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions1_DWORK2, 3, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm1_DWORK2, 0, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm1_DWORK2, 1, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm1_DWORK2, 2, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm1_DWORK2, 3, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.measurment1_DWORK2, 0, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment1_DWORK2, 1, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment1_DWORK2, 2, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment1_DWORK2, 3, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions2_DWORK2, 0, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions2_DWORK2, 1, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions2_DWORK2, 2, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions2_DWORK2, 3, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolution1_DWORK2, 0, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution1_DWORK2, 1, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution1_DWORK2, 2, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution1_DWORK2, 3, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions3_DWORK2, 0, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions3_DWORK2, 1, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions3_DWORK2, 2, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions3_DWORK2, 3, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.measurment2_DWORK2, 0, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment2_DWORK2, 1, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment2_DWORK2, 2, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment2_DWORK2, 3, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions4_DWORK2, 0, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions4_DWORK2, 1, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions4_DWORK2, 2, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions4_DWORK2, 3, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolution2_DWORK2, 0, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution2_DWORK2, 1, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution2_DWORK2, 2, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution2_DWORK2, 3, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions5_DWORK2, 0, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions5_DWORK2, 1, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions5_DWORK2, 2, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions5_DWORK2, 3, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm2_DWORK2, 0, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm2_DWORK2, 1, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm2_DWORK2, 2, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm2_DWORK2, 3, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions6_DWORK2, 0, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions6_DWORK2, 1, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions6_DWORK2, 2, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.revolutions6_DWORK2, 3, discStates[idx++],
      17, 0);
    NIRT_SetValueByDataType(&rpm_DW.measurment3_DWORK2, 0, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment3_DWORK2, 1, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment3_DWORK2, 2, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment3_DWORK2, 3, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution3_DWORK2, 0, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution3_DWORK2, 1, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution3_DWORK2, 2, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution3_DWORK2, 3, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.rpm3_DWORK2, 0, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm3_DWORK2, 1, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm3_DWORK2, 2, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm3_DWORK2, 3, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.measurment4_DWORK2, 0, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment4_DWORK2, 1, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment4_DWORK2, 2, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment4_DWORK2, 3, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution4_DWORK2, 0, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution4_DWORK2, 1, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution4_DWORK2, 2, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution4_DWORK2, 3, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.rpm4_DWORK2, 0, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm4_DWORK2, 1, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm4_DWORK2, 2, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm4_DWORK2, 3, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.measurment5_DWORK2, 0, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment5_DWORK2, 1, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment5_DWORK2, 2, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment5_DWORK2, 3, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution5_DWORK2, 0, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution5_DWORK2, 1, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution5_DWORK2, 2, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution5_DWORK2, 3, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.rpm5_DWORK2, 0, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm5_DWORK2, 1, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm5_DWORK2, 2, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm5_DWORK2, 3, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.measurment6_DWORK2, 0, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment6_DWORK2, 1, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment6_DWORK2, 2, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.measurment6_DWORK2, 3, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution6_DWORK2, 0, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution6_DWORK2, 1, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution6_DWORK2, 2, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.revolution6_DWORK2, 3, discStates[idx++], 17,
      0);
    NIRT_SetValueByDataType(&rpm_DW.rpm6_DWORK2, 0, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm6_DWORK2, 1, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm6_DWORK2, 2, discStates[idx++], 17, 0);
    NIRT_SetValueByDataType(&rpm_DW.rpm6_DWORK2, 3, discStates[idx++], 17, 0);
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  UNUSED_PARAMETER(count);
  UNUSED_PARAMETER(idx);
  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_rpm
