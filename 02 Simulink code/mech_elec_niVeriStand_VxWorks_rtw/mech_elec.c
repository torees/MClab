/*
 * mech_elec.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "mech_elec".
 *
 * Model version              : 1.30
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Apr 14 09:16:29 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mech_elec.h"
#include "mech_elec_private.h"

/* Block signals (auto storage) */
B_mech_elec_T mech_elec_B;

/* Continuous states */
X_mech_elec_T mech_elec_X;

/* Block states (auto storage) */
DW_mech_elec_T mech_elec_DW;

/* Real-time model */
RT_MODEL_mech_elec_T mech_elec_M_;
RT_MODEL_mech_elec_T *const mech_elec_M = &mech_elec_M_;

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
  mech_elec_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  mech_elec_output();
  mech_elec_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  mech_elec_output();
  mech_elec_derivatives();

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

/* Model output function */
void mech_elec_output(void)
{
  if (rtmIsMajorTimeStep(mech_elec_M)) {
    /* set solver stop time */
    if (!(mech_elec_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&mech_elec_M->solverInfo,
                            ((mech_elec_M->Timing.clockTickH0 + 1) *
        mech_elec_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&mech_elec_M->solverInfo,
                            ((mech_elec_M->Timing.clockTick0 + 1) *
        mech_elec_M->Timing.stepSize0 + mech_elec_M->Timing.clockTickH0 *
        mech_elec_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(mech_elec_M)) {
    mech_elec_M->Timing.t[0] = rtsiGetT(&mech_elec_M->solverInfo);
  }

  /* Switch: '<Root>/Switch' incorporates:
   *  Integrator: '<S1>/Integrator'
   *  Integrator: '<S1>/Integrator1'
   *  Integrator: '<S1>/Integrator10'
   *  Integrator: '<S1>/Integrator11'
   *  Integrator: '<S1>/Integrator2'
   *  Integrator: '<S1>/Integrator3'
   *  Integrator: '<S1>/Integrator4'
   *  Integrator: '<S1>/Integrator5'
   *  Integrator: '<S1>/Integrator6'
   *  Integrator: '<S1>/Integrator7'
   *  Integrator: '<S1>/Integrator8'
   *  Integrator: '<S1>/Integrator9'
   */
  if (mech_elec_B.mechelecenable != 0.0) {
    mech_elec_B.Switch[0] = mech_elec_X.Integrator6_CSTATE;
    mech_elec_B.Switch[1] = mech_elec_X.Integrator5_CSTATE;
    mech_elec_B.Switch[2] = mech_elec_X.Integrator4_CSTATE;
    mech_elec_B.Switch[3] = mech_elec_X.Integrator3_CSTATE;
    mech_elec_B.Switch[4] = mech_elec_X.Integrator2_CSTATE;
    mech_elec_B.Switch[5] = mech_elec_X.Integrator1_CSTATE;
    mech_elec_B.Switch[6] = mech_elec_X.Integrator_CSTATE;
    mech_elec_B.Switch[7] = mech_elec_X.Integrator7_CSTATE;
    mech_elec_B.Switch[8] = mech_elec_X.Integrator8_CSTATE;
    mech_elec_B.Switch[9] = mech_elec_X.Integrator9_CSTATE;
    mech_elec_B.Switch[10] = mech_elec_X.Integrator10_CSTATE;
    mech_elec_B.Switch[11] = mech_elec_X.Integrator11_CSTATE;
  } else {
    mech_elec_B.Switch[0] = mech_elec_B.u_1d;
    mech_elec_B.Switch[1] = mech_elec_B.u_2d;
    mech_elec_B.Switch[2] = mech_elec_B.u_3d;
    mech_elec_B.Switch[3] = mech_elec_B.u_4d;
    mech_elec_B.Switch[4] = mech_elec_B.u_5d;
    mech_elec_B.Switch[5] = mech_elec_B.u_6d;
    mech_elec_B.Switch[6] = mech_elec_B.alpha_1d;
    mech_elec_B.Switch[7] = mech_elec_B.alpha_2d;
    mech_elec_B.Switch[8] = mech_elec_B.alpha_3d;
    mech_elec_B.Switch[9] = mech_elec_B.alpha_4d;
    mech_elec_B.Switch[10] = mech_elec_B.alpha_5d;
    mech_elec_B.Switch[11] = mech_elec_B.alpha_6d;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Integrator: '<S1>/Integrator'
   */
  mech_elec_B.Sum = mech_elec_B.alpha_1d - mech_elec_X.Integrator_CSTATE;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Integrator: '<S1>/Integrator1'
   */
  mech_elec_B.Sum1 = mech_elec_B.u_6d - mech_elec_X.Integrator1_CSTATE;

  /* Sum: '<S1>/Sum10' incorporates:
   *  Integrator: '<S1>/Integrator10'
   */
  mech_elec_B.Sum10 = mech_elec_B.alpha_5d - mech_elec_X.Integrator10_CSTATE;

  /* Sum: '<S1>/Sum11' incorporates:
   *  Integrator: '<S1>/Integrator11'
   */
  mech_elec_B.Sum11 = mech_elec_B.alpha_6d - mech_elec_X.Integrator11_CSTATE;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Integrator: '<S1>/Integrator2'
   */
  mech_elec_B.Sum2 = mech_elec_B.u_5d - mech_elec_X.Integrator2_CSTATE;

  /* Sum: '<S1>/Sum3' incorporates:
   *  Integrator: '<S1>/Integrator3'
   */
  mech_elec_B.Sum3 = mech_elec_B.u_4d - mech_elec_X.Integrator3_CSTATE;

  /* Sum: '<S1>/Sum4' incorporates:
   *  Integrator: '<S1>/Integrator4'
   */
  mech_elec_B.Sum4 = mech_elec_B.u_3d - mech_elec_X.Integrator4_CSTATE;

  /* Sum: '<S1>/Sum5' incorporates:
   *  Integrator: '<S1>/Integrator5'
   */
  mech_elec_B.Sum5 = mech_elec_B.u_2d - mech_elec_X.Integrator5_CSTATE;

  /* Sum: '<S1>/Sum6' incorporates:
   *  Integrator: '<S1>/Integrator6'
   */
  mech_elec_B.Sum6 = mech_elec_B.u_1d - mech_elec_X.Integrator6_CSTATE;

  /* Sum: '<S1>/Sum7' incorporates:
   *  Integrator: '<S1>/Integrator7'
   */
  mech_elec_B.Sum7 = mech_elec_B.alpha_2d - mech_elec_X.Integrator7_CSTATE;

  /* Sum: '<S1>/Sum8' incorporates:
   *  Integrator: '<S1>/Integrator8'
   */
  mech_elec_B.Sum8 = mech_elec_B.alpha_3d - mech_elec_X.Integrator8_CSTATE;

  /* Sum: '<S1>/Sum9' incorporates:
   *  Integrator: '<S1>/Integrator9'
   */
  mech_elec_B.Sum9 = mech_elec_B.alpha_4d - mech_elec_X.Integrator9_CSTATE;
}

/* Model update function */
void mech_elec_update(void)
{
  if (rtmIsMajorTimeStep(mech_elec_M)) {
    rt_ertODEUpdateContinuousStates(&mech_elec_M->solverInfo);
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
  if (!(++mech_elec_M->Timing.clockTick0)) {
    ++mech_elec_M->Timing.clockTickH0;
  }

  mech_elec_M->Timing.t[0] = rtsiGetSolverStopTime(&mech_elec_M->solverInfo);

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
    if (!(++mech_elec_M->Timing.clockTick1)) {
      ++mech_elec_M->Timing.clockTickH1;
    }

    mech_elec_M->Timing.t[1] = mech_elec_M->Timing.clockTick1 *
      mech_elec_M->Timing.stepSize1 + mech_elec_M->Timing.clockTickH1 *
      mech_elec_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void mech_elec_derivatives(void)
{
  XDot_mech_elec_T *_rtXdot;
  _rtXdot = ((XDot_mech_elec_T *) mech_elec_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S1>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = mech_elec_B.Sum6;

  /* Derivatives for Integrator: '<S1>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = mech_elec_B.Sum5;

  /* Derivatives for Integrator: '<S1>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = mech_elec_B.Sum4;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = mech_elec_B.Sum3;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = mech_elec_B.Sum2;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = mech_elec_B.Sum1;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = mech_elec_B.Sum;

  /* Derivatives for Integrator: '<S1>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = mech_elec_B.Sum7;

  /* Derivatives for Integrator: '<S1>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = mech_elec_B.Sum8;

  /* Derivatives for Integrator: '<S1>/Integrator9' */
  _rtXdot->Integrator9_CSTATE = mech_elec_B.Sum9;

  /* Derivatives for Integrator: '<S1>/Integrator10' */
  _rtXdot->Integrator10_CSTATE = mech_elec_B.Sum10;

  /* Derivatives for Integrator: '<S1>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = mech_elec_B.Sum11;
}

/* Model initialize function */
void mech_elec_initialize(void)
{
  /* InitializeConditions for Integrator: '<S1>/Integrator6' */
  mech_elec_X.Integrator6_CSTATE = mech_elec_P.Integrator6_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator5' */
  mech_elec_X.Integrator5_CSTATE = mech_elec_P.Integrator5_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator4' */
  mech_elec_X.Integrator4_CSTATE = mech_elec_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  mech_elec_X.Integrator3_CSTATE = mech_elec_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  mech_elec_X.Integrator2_CSTATE = mech_elec_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  mech_elec_X.Integrator1_CSTATE = mech_elec_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  mech_elec_X.Integrator_CSTATE = mech_elec_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator7' */
  mech_elec_X.Integrator7_CSTATE = mech_elec_P.Integrator7_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator8' */
  mech_elec_X.Integrator8_CSTATE = mech_elec_P.Integrator8_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator9' */
  mech_elec_X.Integrator9_CSTATE = mech_elec_P.Integrator9_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator10' */
  mech_elec_X.Integrator10_CSTATE = mech_elec_P.Integrator10_IC;

  /* InitializeConditions for Integrator: '<S1>/Integrator11' */
  mech_elec_X.Integrator11_CSTATE = mech_elec_P.Integrator11_IC;
}

/* Model terminate function */
void mech_elec_terminate(void)
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
  mech_elec_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  mech_elec_update();
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
  mech_elec_initialize();
}

void MdlTerminate(void)
{
  mech_elec_terminate();
}

/* Registration function */
RT_MODEL_mech_elec_T *mech_elec(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mech_elec_M, 0,
                sizeof(RT_MODEL_mech_elec_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&mech_elec_M->solverInfo,
                          &mech_elec_M->Timing.simTimeStep);
    rtsiSetTPtr(&mech_elec_M->solverInfo, &rtmGetTPtr(mech_elec_M));
    rtsiSetStepSizePtr(&mech_elec_M->solverInfo, &mech_elec_M->Timing.stepSize0);
    rtsiSetdXPtr(&mech_elec_M->solverInfo, &mech_elec_M->ModelData.derivs);
    rtsiSetContStatesPtr(&mech_elec_M->solverInfo, (real_T **)
                         &mech_elec_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&mech_elec_M->solverInfo,
      &mech_elec_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&mech_elec_M->solverInfo, (&rtmGetErrorStatus
      (mech_elec_M)));
    rtsiSetRTModelPtr(&mech_elec_M->solverInfo, mech_elec_M);
  }

  rtsiSetSimTimeStep(&mech_elec_M->solverInfo, MAJOR_TIME_STEP);
  mech_elec_M->ModelData.intgData.y = mech_elec_M->ModelData.odeY;
  mech_elec_M->ModelData.intgData.f[0] = mech_elec_M->ModelData.odeF[0];
  mech_elec_M->ModelData.intgData.f[1] = mech_elec_M->ModelData.odeF[1];
  mech_elec_M->ModelData.intgData.f[2] = mech_elec_M->ModelData.odeF[2];
  mech_elec_M->ModelData.contStates = ((real_T *) &mech_elec_X);
  rtsiSetSolverData(&mech_elec_M->solverInfo, (void *)
                    &mech_elec_M->ModelData.intgData);
  rtsiSetSolverName(&mech_elec_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = mech_elec_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mech_elec_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    mech_elec_M->Timing.sampleTimes = (&mech_elec_M->Timing.sampleTimesArray[0]);
    mech_elec_M->Timing.offsetTimes = (&mech_elec_M->Timing.offsetTimesArray[0]);

    /* task periods */
    mech_elec_M->Timing.sampleTimes[0] = (0.0);
    mech_elec_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    mech_elec_M->Timing.offsetTimes[0] = (0.0);
    mech_elec_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(mech_elec_M, &mech_elec_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = mech_elec_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mech_elec_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(mech_elec_M, -1);
  mech_elec_M->Timing.stepSize0 = 0.01;
  mech_elec_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    mech_elec_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(mech_elec_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(mech_elec_M->rtwLogInfo, (NULL));
    rtliSetLogT(mech_elec_M->rtwLogInfo, "tout");
    rtliSetLogX(mech_elec_M->rtwLogInfo, "");
    rtliSetLogXFinal(mech_elec_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(mech_elec_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(mech_elec_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(mech_elec_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(mech_elec_M->rtwLogInfo, 1);
    rtliSetLogY(mech_elec_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(mech_elec_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(mech_elec_M->rtwLogInfo, (NULL));
  }

  mech_elec_M->solverInfoPtr = (&mech_elec_M->solverInfo);
  mech_elec_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&mech_elec_M->solverInfo, 0.01);
  rtsiSetSolverMode(&mech_elec_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  mech_elec_M->ModelData.blockIO = ((void *) &mech_elec_B);
  (void) memset(((void *) &mech_elec_B), 0,
                sizeof(B_mech_elec_T));

  /* parameters */
  mech_elec_M->ModelData.defaultParam = ((real_T *)&mech_elec_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &mech_elec_X;
    mech_elec_M->ModelData.contStates = (x);
    (void) memset((void *)&mech_elec_X, 0,
                  sizeof(X_mech_elec_T));
  }

  /* states (dwork) */
  mech_elec_M->ModelData.dwork = ((void *) &mech_elec_DW);
  (void) memset((void *)&mech_elec_DW, 0,
                sizeof(DW_mech_elec_T));

  /* Initialize Sizes */
  mech_elec_M->Sizes.numContStates = (12);/* Number of continuous states */
  mech_elec_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  mech_elec_M->Sizes.numY = (0);       /* Number of model outputs */
  mech_elec_M->Sizes.numU = (0);       /* Number of model inputs */
  mech_elec_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  mech_elec_M->Sizes.numSampTimes = (2);/* Number of sample times */
  mech_elec_M->Sizes.numBlocks = (50); /* Number of blocks */
  mech_elec_M->Sizes.numBlockIO = (26);/* Number of block outputs */
  mech_elec_M->Sizes.numBlockPrms = (162);/* Sum of parameter "widths" */
  return mech_elec_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : mech_elec
 * Model version : 1.30
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Thu Apr 14 09:16:29 2016
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_mech_elec
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
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern mech_elec_rtModel *S;
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

  // mech_elec/mech elec enable
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.mechelecenable, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // mech_elec/u_d/u_5,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.u_5d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // mech_elec/u_d/u_4,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.u_4d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // mech_elec/u_d/alpha_1,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.alpha_1d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // mech_elec/u_d/u_6,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.u_6d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // mech_elec/u_d/u_1,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.u_1d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // mech_elec/u_d/u_2,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.u_2d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // mech_elec/u_d/u_3,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.u_3d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // mech_elec/u_d/alpha_2,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.alpha_2d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // mech_elec/u_d/alpha_3,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.alpha_3d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // mech_elec/u_d/alpha_4,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.alpha_4d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // mech_elec/u_d/alpha_5,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.alpha_5d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // mech_elec/u_d/alpha_6,d
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&mech_elec_B.alpha_6d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 13;
}

int32_t NumOutputPorts(void)
{
  return 12;
}

double ni_extout[12];

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

  // mech_elec/u/alpha_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 7, 17, 0);
  } else {
    index += 1;
  }

  // mech_elec/u/alpha_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 8, 17, 0);
  } else {
    index += 1;
  }

  // mech_elec/u/alpha_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 9, 17, 0);
  } else {
    index += 1;
  }

  // mech_elec/u/alpha_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 10, 17, 0);
  } else {
    index += 1;
  }

  // mech_elec/u/alpha_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 11, 17, 0);
  } else {
    index += 1;
  }

  // mech_elec/u/u_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 1, 17, 0);
  } else {
    index += 1;
  }

  // mech_elec/u/u_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 2, 17, 0);
  } else {
    index += 1;
  }

  // mech_elec/u/u_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 0, 17, 0);
  } else {
    index += 1;
  }

  // mech_elec/u/alpha_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 6, 17, 0);
  } else {
    index += 1;
  }

  // mech_elec/u/u_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 5, 17, 0);
  } else {
    index += 1;
  }

  // mech_elec/u/u_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 3, 17, 0);
  } else {
    index += 1;
  }

  // mech_elec/u/u_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 4, 17, 0);
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

  // mech_elec/u/alpha_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 7, 17, 0);

  // mech_elec/u/alpha_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 8, 17, 0);

  // mech_elec/u/alpha_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 9, 17, 0);

  // mech_elec/u/alpha_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 10, 17, 0);

  // mech_elec/u/alpha_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 11, 17, 0);

  // mech_elec/u/u_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 1, 17, 0);

  // mech_elec/u/u_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 2, 17, 0);

  // mech_elec/u/u_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 0, 17, 0);

  // mech_elec/u/alpha_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 6, 17, 0);

  // mech_elec/u/u_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 5, 17, 0);

  // mech_elec/u/u_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 3, 17, 0);

  // mech_elec/u/u_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&mech_elec_B.Switch, 4, 17, 0);
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
    "mech_elec/emulate mechanical and electrical system/Integrator6/InitialCondition",
    offsetof(P_mech_elec_T, Integrator6_IC), 25, 1, 2, 0, 0 },

  { 1,
    "mech_elec/emulate mechanical and electrical system/Integrator5/InitialCondition",
    offsetof(P_mech_elec_T, Integrator5_IC), 25, 1, 2, 2, 0 },

  { 2,
    "mech_elec/emulate mechanical and electrical system/Integrator4/InitialCondition",
    offsetof(P_mech_elec_T, Integrator4_IC), 25, 1, 2, 4, 0 },

  { 3,
    "mech_elec/emulate mechanical and electrical system/Integrator3/InitialCondition",
    offsetof(P_mech_elec_T, Integrator3_IC), 25, 1, 2, 6, 0 },

  { 4,
    "mech_elec/emulate mechanical and electrical system/Integrator2/InitialCondition",
    offsetof(P_mech_elec_T, Integrator2_IC), 25, 1, 2, 8, 0 },

  { 5,
    "mech_elec/emulate mechanical and electrical system/Integrator1/InitialCondition",
    offsetof(P_mech_elec_T, Integrator1_IC), 25, 1, 2, 10, 0 },

  { 6,
    "mech_elec/emulate mechanical and electrical system/Integrator/InitialCondition",
    offsetof(P_mech_elec_T, Integrator_IC), 25, 1, 2, 12, 0 },

  { 7,
    "mech_elec/emulate mechanical and electrical system/Integrator7/InitialCondition",
    offsetof(P_mech_elec_T, Integrator7_IC), 25, 1, 2, 14, 0 },

  { 8,
    "mech_elec/emulate mechanical and electrical system/Integrator8/InitialCondition",
    offsetof(P_mech_elec_T, Integrator8_IC), 25, 1, 2, 16, 0 },

  { 9,
    "mech_elec/emulate mechanical and electrical system/Integrator9/InitialCondition",
    offsetof(P_mech_elec_T, Integrator9_IC), 25, 1, 2, 18, 0 },

  { 10,
    "mech_elec/emulate mechanical and electrical system/Integrator10/InitialCondition",
    offsetof(P_mech_elec_T, Integrator10_IC), 25, 1, 2, 20, 0 },

  { 11,
    "mech_elec/emulate mechanical and electrical system/Integrator11/InitialCondition",
    offsetof(P_mech_elec_T, Integrator11_IC), 25, 1, 2, 22, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 12;
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
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "mech_elec/mech elec enable", 0, "", offsetof(B_mech_elec_T,
    mechelecenable) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "mech_elec/u_d/u_5,d", 0, "", offsetof(B_mech_elec_T, u_5d) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "mech_elec/u_d/u_4,d", 0, "", offsetof(B_mech_elec_T, u_4d) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "mech_elec/u_d/alpha_1,d", 0, "", offsetof(B_mech_elec_T, alpha_1d) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "mech_elec/u_d/u_6,d", 0, "", offsetof(B_mech_elec_T, u_6d) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "mech_elec/u_d/u_1,d", 0, "", offsetof(B_mech_elec_T, u_1d) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "mech_elec/u_d/u_2,d", 0, "", offsetof(B_mech_elec_T, u_2d) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "mech_elec/u_d/u_3,d", 0, "", offsetof(B_mech_elec_T, u_3d) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "mech_elec/u_d/alpha_2,d", 0, "", offsetof(B_mech_elec_T, alpha_2d) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "mech_elec/u_d/alpha_3,d", 0, "", offsetof(B_mech_elec_T, alpha_3d) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "mech_elec/u_d/alpha_4,d", 0, "", offsetof(B_mech_elec_T, alpha_4d) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "mech_elec/u_d/alpha_5,d", 0, "", offsetof(B_mech_elec_T, alpha_5d) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "mech_elec/u_d/alpha_6,d", 0, "", offsetof(B_mech_elec_T, alpha_6d) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "mech_elec/Switch/(1, 1)", 0, "", offsetof(B_mech_elec_T, Switch) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 14, "mech_elec/Switch/(1, 2)", 0, "", offsetof(B_mech_elec_T, Switch) + (1*
    sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 15, "mech_elec/Switch/(1, 3)", 0, "", offsetof(B_mech_elec_T, Switch) + (2*
    sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 16, "mech_elec/Switch/(1, 4)", 0, "", offsetof(B_mech_elec_T, Switch) + (3*
    sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 17, "mech_elec/Switch/(1, 5)", 0, "", offsetof(B_mech_elec_T, Switch) + (4*
    sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 18, "mech_elec/Switch/(1, 6)", 0, "", offsetof(B_mech_elec_T, Switch) + (5*
    sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 19, "mech_elec/Switch/(1, 7)", 0, "", offsetof(B_mech_elec_T, Switch) + (6*
    sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 20, "mech_elec/Switch/(1, 8)", 0, "", offsetof(B_mech_elec_T, Switch) + (7*
    sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 21, "mech_elec/Switch/(1, 9)", 0, "", offsetof(B_mech_elec_T, Switch) + (8*
    sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 22, "mech_elec/Switch/(1, 10)", 0, "", offsetof(B_mech_elec_T, Switch) + (9*
    sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 23, "mech_elec/Switch/(1, 11)", 0, "", offsetof(B_mech_elec_T, Switch) + (10*
    sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 24, "mech_elec/Switch/(1, 12)", 0, "", offsetof(B_mech_elec_T, Switch) + (11*
    sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 25, "mech_elec/emulate mechanical and electrical system/Sum", 0, "",
    offsetof(B_mech_elec_T, Sum) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 26, "mech_elec/emulate mechanical and electrical system/Sum1", 0, "",
    offsetof(B_mech_elec_T, Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 27, "mech_elec/emulate mechanical and electrical system/Sum10", 0, "",
    offsetof(B_mech_elec_T, Sum10) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 28, "mech_elec/emulate mechanical and electrical system/Sum11", 0, "",
    offsetof(B_mech_elec_T, Sum11) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 29, "mech_elec/emulate mechanical and electrical system/Sum2", 0, "",
    offsetof(B_mech_elec_T, Sum2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 30, "mech_elec/emulate mechanical and electrical system/Sum3", 0, "",
    offsetof(B_mech_elec_T, Sum3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 31, "mech_elec/emulate mechanical and electrical system/Sum4", 0, "",
    offsetof(B_mech_elec_T, Sum4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 32, "mech_elec/emulate mechanical and electrical system/Sum5", 0, "",
    offsetof(B_mech_elec_T, Sum5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 33, "mech_elec/emulate mechanical and electrical system/Sum6", 0, "",
    offsetof(B_mech_elec_T, Sum6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 34, "mech_elec/emulate mechanical and electrical system/Sum7", 0, "",
    offsetof(B_mech_elec_T, Sum7) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 35, "mech_elec/emulate mechanical and electrical system/Sum8", 0, "",
    offsetof(B_mech_elec_T, Sum8) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 36, "mech_elec/emulate mechanical and electrical system/Sum9", 0, "",
    offsetof(B_mech_elec_T, Sum9) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 37;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 25;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "mech elec enable", 0, EXT_IN, 1, 1, 1 },

  { 2, "u_d/u_5,d", 0, EXT_IN, 1, 1, 1 },

  { 3, "u_d/u_4,d", 0, EXT_IN, 1, 1, 1 },

  { 4, "u_d/alpha_1,d", 0, EXT_IN, 1, 1, 1 },

  { 5, "u_d/u_6,d", 0, EXT_IN, 1, 1, 1 },

  { 6, "u_d/u_1,d", 0, EXT_IN, 1, 1, 1 },

  { 7, "u_d/u_2,d", 0, EXT_IN, 1, 1, 1 },

  { 8, "u_d/u_3,d", 0, EXT_IN, 1, 1, 1 },

  { 9, "u_d/alpha_2,d", 0, EXT_IN, 1, 1, 1 },

  { 10, "u_d/alpha_3,d", 0, EXT_IN, 1, 1, 1 },

  { 11, "u_d/alpha_4,d", 0, EXT_IN, 1, 1, 1 },

  { 12, "u_d/alpha_5,d", 0, EXT_IN, 1, 1, 1 },

  { 13, "u_d/alpha_6,d", 0, EXT_IN, 1, 1, 1 },

  { 1, "u/alpha_2", 0, EXT_OUT, 1, 1, 1 },

  { 2, "u/alpha_3", 0, EXT_OUT, 1, 1, 1 },

  { 3, "u/alpha_4", 0, EXT_OUT, 1, 1, 1 },

  { 4, "u/alpha_5", 0, EXT_OUT, 1, 1, 1 },

  { 5, "u/alpha_6", 0, EXT_OUT, 1, 1, 1 },

  { 6, "u/u_2", 0, EXT_OUT, 1, 1, 1 },

  { 7, "u/u_3", 0, EXT_OUT, 1, 1, 1 },

  { 8, "u/u_1", 0, EXT_OUT, 1, 1, 1 },

  { 9, "u/alpha_1", 0, EXT_OUT, 1, 1, 1 },

  { 10, "u/u_6", 0, EXT_OUT, 1, 1, 1 },

  { 11, "u/u_4", 0, EXT_OUT, 1, 1, 1 },

  { 12, "u/u_5", 0, EXT_OUT, 1, 1, 1 },

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
  "mech_elec";
static const char* NI_CompiledModelVersion = "1.30";
static const char* NI_CompiledModelDateTime = "Thu Apr 14 09:16:29 2016";
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
  memcpy(&rtParameter[0], &mech_elec_P, sizeof(P_mech_elec_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka mech_elec_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_mech_elec_T));
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
             (P_mech_elec_T));
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
               (P_mech_elec_T));
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
             (P_mech_elec_T));
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
           (P_mech_elec_T));
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
           (P_mech_elec_T));
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
      *numContStates = 12;
      *numDiscStates = 275;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(mech_elec_X.Integrator6_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator6_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(mech_elec_X.Integrator5_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator5_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(mech_elec_X.Integrator4_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(mech_elec_X.Integrator3_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(mech_elec_X.Integrator2_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(mech_elec_X.Integrator1_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(mech_elec_X.Integrator_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(mech_elec_X.Integrator7_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator7_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(mech_elec_X.Integrator8_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator8_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(mech_elec_X.Integrator9_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator9_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(mech_elec_X.Integrator10_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator10_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(mech_elec_X.Integrator11_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator11_CSTATE");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&mech_elec_DW.mechelecenable_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&mech_elec_DW.mechelecenable_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_5d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_5d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_4d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_4d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_1d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_1d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_6d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_6d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_1d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_1d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_2d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_2d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_3d_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_3d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_2d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_2d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_3d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_3d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_4d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_4d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_5d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_5d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_6d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_6d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_5_DWORK1");
    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&mech_elec_DW.mechelecenable_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&mech_elec_DW.mechelecenable_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_5d_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_5d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_4d_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_4d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_1d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_1d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_6d_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_6d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_1d_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_1d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_2d_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_2d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_3d_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_3d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_2d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_2d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_3d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_3d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_4d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_4d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_5d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_5d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_6d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_6d_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_2_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_3_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_4_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_5_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_6_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_2_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_3_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_1_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.alpha_1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_6_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_4_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&mech_elec_DW.u_5_DWORK2, count,
        18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&mech_elec_DW.u_5_DWORK2");
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
    NIRT_SetValueByDataType(&(mech_elec_X.Integrator6_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(mech_elec_X.Integrator5_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(mech_elec_X.Integrator4_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(mech_elec_X.Integrator3_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(mech_elec_X.Integrator2_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(mech_elec_X.Integrator1_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(mech_elec_X.Integrator_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(mech_elec_X.Integrator7_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(mech_elec_X.Integrator8_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(mech_elec_X.Integrator9_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(mech_elec_X.Integrator10_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(mech_elec_X.Integrator11_CSTATE), 0,
      contStates[idx++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&mech_elec_DW.mechelecenable_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_5d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_4d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_1d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_6d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_1d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_2d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_3d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_2d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_3d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_4d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_5d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_6d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_2_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_3_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.alpha_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_6_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_4_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&mech_elec_DW.u_5_DWORK1, 0, discStates[idx++], 0, 0);
    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.mechelecenable_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_5d_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_4d_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_1d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_6d_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_1d_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_2d_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_3d_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_2d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_3d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_4d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_5d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_6d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_2_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_3_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_4_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_5_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_6_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_2_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_3_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_1_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.alpha_1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_6_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_4_DWORK2, count, discStates[idx++],
        18, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&mech_elec_DW.u_5_DWORK2, count, discStates[idx++],
        18, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_mech_elec
