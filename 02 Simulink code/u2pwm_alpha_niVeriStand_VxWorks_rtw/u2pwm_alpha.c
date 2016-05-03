/*
 * u2pwm_alpha.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "u2pwm_alpha".
 *
 * Model version              : 1.85
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Apr 21 16:16:56 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "u2pwm_alpha.h"
#include "u2pwm_alpha_private.h"

/* Block signals (auto storage) */
B_u2pwm_alpha_T u2pwm_alpha_B;

/* Block states (auto storage) */
DW_u2pwm_alpha_T u2pwm_alpha_DW;

/* Real-time model */
RT_MODEL_u2pwm_alpha_T u2pwm_alpha_M_;
RT_MODEL_u2pwm_alpha_T *const u2pwm_alpha_M = &u2pwm_alpha_M_;

/*
 * Output and update for atomic system:
 *    '<Root>/MATLAB Function1'
 *    '<Root>/MATLAB Function2'
 *    '<Root>/MATLAB Function3'
 *    '<Root>/MATLAB Function6'
 */
void u2pwm_alpha_MATLABFunction1(real_T rtu_u, B_MATLABFunction1_u2pwm_alpha_T
  *localB)
{
  /* MATLAB Function 'MATLAB Function1': '<S2>:1' */
  if (rtu_u == 7.5) {
    /* '<S2>:1:3' */
    /* '<S2>:1:4' */
    localB->y = 7.5;
  } else if (rtu_u < 7.5) {
    /* '<S2>:1:5' */
    /* '<S2>:1:6' */
    localB->y = rtu_u - 0.3;
  } else {
    /* '<S2>:1:8' */
    localB->y = rtu_u + 0.3;
  }
}

/*
 * Output and update for atomic system:
 *    '<Root>/MATLAB Function4'
 *    '<Root>/MATLAB Function5'
 */
void u2pwm_alpha_MATLABFunction4(real_T rtu_u, B_MATLABFunction4_u2pwm_alpha_T
  *localB)
{
  /* MATLAB Function 'MATLAB Function4': '<S5>:1' */
  if (rtu_u == 7.5) {
    /* '<S5>:1:3' */
    /* '<S5>:1:4' */
    localB->y = 7.5;
  } else if (rtu_u < 7.5) {
    /* '<S5>:1:5' */
    /* '<S5>:1:6' */
    localB->y = rtu_u - 0.2;
  } else {
    /* '<S5>:1:8' */
    localB->y = rtu_u + 0.2;
  }
}

/* Model output function */
static void u2pwm_alpha_output(void)
{
  real_T rtb_Sum12;
  real_T rtb_Sum13;
  real_T rtb_Sum11;
  real_T rtb_Sum8;
  real_T rtb_Sum9;
  real_T rtb_Sum10;

  /* Saturate: '<Root>/Saturation' */
  if (u2pwm_alpha_B.u_1 > u2pwm_alpha_P.Saturation_UpperSat) {
    rtb_Sum12 = u2pwm_alpha_P.Saturation_UpperSat;
  } else if (u2pwm_alpha_B.u_1 < u2pwm_alpha_P.Saturation_LowerSat) {
    rtb_Sum12 = u2pwm_alpha_P.Saturation_LowerSat;
  } else {
    rtb_Sum12 = u2pwm_alpha_B.u_1;
  }

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/PWM_Offset'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/VPS_Speed_Gain1'
   *  Saturate: '<Root>/Saturation'
   *  Sum: '<Root>/Sum2'
   */
  u2pwm_alpha_MATLABFunction1(u2pwm_alpha_P.zero_pwm + u2pwm_alpha_P.u2pwm_gain *
    (u2pwm_alpha_P.Gain_Gain * rtb_Sum12), &u2pwm_alpha_B.sf_MATLABFunction1);

  /* Saturate: '<Root>/Saturation1' */
  if (u2pwm_alpha_B.u_2 > u2pwm_alpha_P.Saturation1_UpperSat) {
    rtb_Sum12 = u2pwm_alpha_P.Saturation1_UpperSat;
  } else if (u2pwm_alpha_B.u_2 < u2pwm_alpha_P.Saturation1_LowerSat) {
    rtb_Sum12 = u2pwm_alpha_P.Saturation1_LowerSat;
  } else {
    rtb_Sum12 = u2pwm_alpha_B.u_2;
  }

  /* MATLAB Function: '<Root>/MATLAB Function6' incorporates:
   *  Constant: '<Root>/PWM_Offset1'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/VPS_Speed_Gain3'
   *  Saturate: '<Root>/Saturation1'
   *  Sum: '<Root>/Sum3'
   */
  u2pwm_alpha_MATLABFunction1(u2pwm_alpha_P.zero_pwm + u2pwm_alpha_P.u2pwm_gain *
    (u2pwm_alpha_P.Gain1_Gain * rtb_Sum12), &u2pwm_alpha_B.sf_MATLABFunction6);

  /* Saturate: '<Root>/Saturation2' */
  if (u2pwm_alpha_B.u_3 > u2pwm_alpha_P.Saturation2_UpperSat) {
    rtb_Sum12 = u2pwm_alpha_P.Saturation2_UpperSat;
  } else if (u2pwm_alpha_B.u_3 < u2pwm_alpha_P.Saturation2_LowerSat) {
    rtb_Sum12 = u2pwm_alpha_P.Saturation2_LowerSat;
  } else {
    rtb_Sum12 = u2pwm_alpha_B.u_3;
  }

  /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
   *  Constant: '<Root>/PWM_Offset2'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/VPS_Speed_Gain2'
   *  Saturate: '<Root>/Saturation2'
   *  Sum: '<Root>/Sum1'
   */
  u2pwm_alpha_MATLABFunction1(u2pwm_alpha_P.zero_pwm + u2pwm_alpha_P.u2pwm_gain *
    (u2pwm_alpha_P.Gain2_Gain * rtb_Sum12), &u2pwm_alpha_B.sf_MATLABFunction2);

  /* Saturate: '<Root>/Saturation3' */
  if (u2pwm_alpha_B.u_4 > u2pwm_alpha_P.Saturation3_UpperSat) {
    rtb_Sum12 = u2pwm_alpha_P.Saturation3_UpperSat;
  } else if (u2pwm_alpha_B.u_4 < u2pwm_alpha_P.Saturation3_LowerSat) {
    rtb_Sum12 = u2pwm_alpha_P.Saturation3_LowerSat;
  } else {
    rtb_Sum12 = u2pwm_alpha_B.u_4;
  }

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  Constant: '<Root>/PWM_Offset3'
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/VPS_Speed_Gain4'
   *  Saturate: '<Root>/Saturation3'
   *  Sum: '<Root>/Sum4'
   */
  u2pwm_alpha_MATLABFunction1(u2pwm_alpha_P.zero_pwm + u2pwm_alpha_P.u2pwm_gain *
    (u2pwm_alpha_P.Gain3_Gain * rtb_Sum12), &u2pwm_alpha_B.sf_MATLABFunction3);

  /* Saturate: '<Root>/Saturation4' */
  if (u2pwm_alpha_B.u_5 > u2pwm_alpha_P.Saturation4_UpperSat) {
    rtb_Sum12 = u2pwm_alpha_P.Saturation4_UpperSat;
  } else if (u2pwm_alpha_B.u_5 < u2pwm_alpha_P.Saturation4_LowerSat) {
    rtb_Sum12 = u2pwm_alpha_P.Saturation4_LowerSat;
  } else {
    rtb_Sum12 = u2pwm_alpha_B.u_5;
  }

  /* MATLAB Function: '<Root>/MATLAB Function4' incorporates:
   *  Constant: '<Root>/PWM_Offset4'
   *  Gain: '<Root>/Gain4'
   *  Gain: '<Root>/VPS_Speed_Gain5'
   *  Saturate: '<Root>/Saturation4'
   *  Sum: '<Root>/Sum5'
   */
  u2pwm_alpha_MATLABFunction4(u2pwm_alpha_P.zero_pwm + u2pwm_alpha_P.u2pwm_gain *
    (u2pwm_alpha_P.Gain4_Gain * rtb_Sum12), &u2pwm_alpha_B.sf_MATLABFunction4);

  /* Saturate: '<Root>/Saturation5' */
  if (u2pwm_alpha_B.u_6 > u2pwm_alpha_P.Saturation5_UpperSat) {
    rtb_Sum12 = u2pwm_alpha_P.Saturation5_UpperSat;
  } else if (u2pwm_alpha_B.u_6 < u2pwm_alpha_P.Saturation5_LowerSat) {
    rtb_Sum12 = u2pwm_alpha_P.Saturation5_LowerSat;
  } else {
    rtb_Sum12 = u2pwm_alpha_B.u_6;
  }

  /* MATLAB Function: '<Root>/MATLAB Function5' incorporates:
   *  Constant: '<Root>/PWM_Offset5'
   *  Gain: '<Root>/Gain5'
   *  Gain: '<Root>/VPS_Speed_Gain6'
   *  Saturate: '<Root>/Saturation5'
   *  Sum: '<Root>/Sum6'
   */
  u2pwm_alpha_MATLABFunction4(u2pwm_alpha_P.zero_pwm + u2pwm_alpha_P.u2pwm_gain *
    (u2pwm_alpha_P.Gain5_Gain * rtb_Sum12), &u2pwm_alpha_B.sf_MATLABFunction5);

  /* Switch: '<Root>/Switch' */
  if (u2pwm_alpha_B.manualoverridepwm != 0.0) {
    u2pwm_alpha_B.Switch[0] = u2pwm_alpha_B.pwm_u_1;
    u2pwm_alpha_B.Switch[1] = u2pwm_alpha_B.pwm_u_2;
    u2pwm_alpha_B.Switch[2] = u2pwm_alpha_B.pwm_u_3;
    u2pwm_alpha_B.Switch[3] = u2pwm_alpha_B.pwm_u_4;
    u2pwm_alpha_B.Switch[4] = u2pwm_alpha_B.pwm_u_5;
    u2pwm_alpha_B.Switch[5] = u2pwm_alpha_B.pwm_u_6;
  } else {
    u2pwm_alpha_B.Switch[0] = u2pwm_alpha_B.sf_MATLABFunction1.y;
    u2pwm_alpha_B.Switch[1] = u2pwm_alpha_B.sf_MATLABFunction6.y;
    u2pwm_alpha_B.Switch[2] = u2pwm_alpha_B.sf_MATLABFunction2.y;
    u2pwm_alpha_B.Switch[3] = u2pwm_alpha_B.sf_MATLABFunction3.y;
    u2pwm_alpha_B.Switch[4] = u2pwm_alpha_B.sf_MATLABFunction4.y;
    u2pwm_alpha_B.Switch[5] = u2pwm_alpha_B.sf_MATLABFunction5.y;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<Root>/Sum12' incorporates:
   *  Constant: '<Root>/alpha_Offset'
   */
  rtb_Sum12 = u2pwm_alpha_P.zero_alpha_1 + u2pwm_alpha_B.alpha_1;

  /* Sum: '<Root>/Sum13' incorporates:
   *  Constant: '<Root>/alpha_Offset1'
   */
  rtb_Sum13 = u2pwm_alpha_P.zero_alpha_2 + u2pwm_alpha_B.alpha_2;

  /* Sum: '<Root>/Sum11' incorporates:
   *  Constant: '<Root>/alpha_Offset2'
   */
  rtb_Sum11 = u2pwm_alpha_P.zero_alpha_3 + u2pwm_alpha_B.alpha_3;

  /* Sum: '<Root>/Sum8' incorporates:
   *  Constant: '<Root>/alpha_Offset3'
   */
  rtb_Sum8 = u2pwm_alpha_P.zero_alpha_4 + u2pwm_alpha_B.alpha_4;

  /* Sum: '<Root>/Sum9' incorporates:
   *  Constant: '<Root>/alpha_Offset4'
   */
  rtb_Sum9 = u2pwm_alpha_P.zero_alpha_5 + u2pwm_alpha_B.alpha_5;

  /* Sum: '<Root>/Sum10' incorporates:
   *  Constant: '<Root>/alpha_Offset5'
   */
  rtb_Sum10 = u2pwm_alpha_P.zero_alpha_6 + u2pwm_alpha_B.alpha_6;

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* '<S1>:1:3' */
  if ((rtb_Sum12 > 3200.0) || (rtb_Sum12 < -9000.0)) {
    /* '<S1>:1:5' */
    /* '<S1>:1:6' */
    u2pwm_alpha_B.y = 1.0;
  } else if ((rtb_Sum13 > 9000.0) || (rtb_Sum13 < -9000.0)) {
    /* '<S1>:1:7' */
    /* '<S1>:1:8' */
    u2pwm_alpha_B.y = 1.0;
  } else if ((rtb_Sum11 > 9000.0) || (rtb_Sum11 < -9000.0)) {
    /* '<S1>:1:9' */
    /* '<S1>:1:10' */
    u2pwm_alpha_B.y = 1.0;
  } else if ((rtb_Sum8 > 9000.0) || (rtb_Sum8 < -9000.0)) {
    /* '<S1>:1:11' */
    /* '<S1>:1:12' */
    u2pwm_alpha_B.y = 1.0;
  } else if ((rtb_Sum9 > 9000.0) || (rtb_Sum9 < -9000.0)) {
    /* '<S1>:1:13' */
    /* '<S1>:1:14' */
    u2pwm_alpha_B.y = 1.0;
  } else if ((rtb_Sum10 > 9000.0) || (rtb_Sum10 < -9000.0)) {
    /* '<S1>:1:15' */
    /* '<S1>:1:16' */
    u2pwm_alpha_B.y = 1.0;
  } else {
    /* '<S1>:1:18' */
    u2pwm_alpha_B.y = 0.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Switch: '<Root>/Switch1' */
  if (u2pwm_alpha_B.manualoverridealpha != 0.0) {
    u2pwm_alpha_B.Switch1[0] = u2pwm_alpha_B.man_alpha_1;
    u2pwm_alpha_B.Switch1[1] = u2pwm_alpha_B.man_alpha_2;
    u2pwm_alpha_B.Switch1[2] = u2pwm_alpha_B.man_alpha_3;
    u2pwm_alpha_B.Switch1[3] = u2pwm_alpha_B.man_alpha_4;
    u2pwm_alpha_B.Switch1[4] = u2pwm_alpha_B.man_alpha_5;
    u2pwm_alpha_B.Switch1[5] = u2pwm_alpha_B.man_alpha_6;
  } else {
    u2pwm_alpha_B.Switch1[0] = rtb_Sum12;
    u2pwm_alpha_B.Switch1[1] = rtb_Sum13;
    u2pwm_alpha_B.Switch1[2] = rtb_Sum11;
    u2pwm_alpha_B.Switch1[3] = rtb_Sum8;
    u2pwm_alpha_B.Switch1[4] = rtb_Sum9;
    u2pwm_alpha_B.Switch1[5] = rtb_Sum10;
  }

  /* End of Switch: '<Root>/Switch1' */
}

/* Model update function */
static void u2pwm_alpha_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++u2pwm_alpha_M->Timing.clockTick0)) {
    ++u2pwm_alpha_M->Timing.clockTickH0;
  }

  u2pwm_alpha_M->Timing.t[0] = u2pwm_alpha_M->Timing.clockTick0 *
    u2pwm_alpha_M->Timing.stepSize0 + u2pwm_alpha_M->Timing.clockTickH0 *
    u2pwm_alpha_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void u2pwm_alpha_initialize(void)
{
}

/* Model terminate function */
static void u2pwm_alpha_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  u2pwm_alpha_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  u2pwm_alpha_update();
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
  u2pwm_alpha_initialize();
}

void MdlTerminate(void)
{
  u2pwm_alpha_terminate();
}

/* Registration function */
RT_MODEL_u2pwm_alpha_T *u2pwm_alpha(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)u2pwm_alpha_M, 0,
                sizeof(RT_MODEL_u2pwm_alpha_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = u2pwm_alpha_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    u2pwm_alpha_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    u2pwm_alpha_M->Timing.sampleTimes = (&u2pwm_alpha_M->
      Timing.sampleTimesArray[0]);
    u2pwm_alpha_M->Timing.offsetTimes = (&u2pwm_alpha_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    u2pwm_alpha_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    u2pwm_alpha_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(u2pwm_alpha_M, &u2pwm_alpha_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = u2pwm_alpha_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    u2pwm_alpha_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(u2pwm_alpha_M, -1);
  u2pwm_alpha_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    u2pwm_alpha_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(u2pwm_alpha_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(u2pwm_alpha_M->rtwLogInfo, (NULL));
    rtliSetLogT(u2pwm_alpha_M->rtwLogInfo, "tout");
    rtliSetLogX(u2pwm_alpha_M->rtwLogInfo, "");
    rtliSetLogXFinal(u2pwm_alpha_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(u2pwm_alpha_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(u2pwm_alpha_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(u2pwm_alpha_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(u2pwm_alpha_M->rtwLogInfo, 1);
    rtliSetLogY(u2pwm_alpha_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(u2pwm_alpha_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(u2pwm_alpha_M->rtwLogInfo, (NULL));
  }

  u2pwm_alpha_M->solverInfoPtr = (&u2pwm_alpha_M->solverInfo);
  u2pwm_alpha_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&u2pwm_alpha_M->solverInfo, 0.01);
  rtsiSetSolverMode(&u2pwm_alpha_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  u2pwm_alpha_M->ModelData.blockIO = ((void *) &u2pwm_alpha_B);
  (void) memset(((void *) &u2pwm_alpha_B), 0,
                sizeof(B_u2pwm_alpha_T));

  /* parameters */
  u2pwm_alpha_M->ModelData.defaultParam = ((real_T *)&u2pwm_alpha_P);

  /* states (dwork) */
  u2pwm_alpha_M->ModelData.dwork = ((void *) &u2pwm_alpha_DW);
  (void) memset((void *)&u2pwm_alpha_DW, 0,
                sizeof(DW_u2pwm_alpha_T));

  /* Initialize Sizes */
  u2pwm_alpha_M->Sizes.numContStates = (0);/* Number of continuous states */
  u2pwm_alpha_M->Sizes.numY = (0);     /* Number of model outputs */
  u2pwm_alpha_M->Sizes.numU = (0);     /* Number of model inputs */
  u2pwm_alpha_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  u2pwm_alpha_M->Sizes.numSampTimes = (1);/* Number of sample times */
  u2pwm_alpha_M->Sizes.numBlocks = (94);/* Number of blocks */
  u2pwm_alpha_M->Sizes.numBlockIO = (35);/* Number of block outputs */
  u2pwm_alpha_M->Sizes.numBlockPrms = (260);/* Sum of parameter "widths" */
  return u2pwm_alpha_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : u2pwm_alpha
 * Model version : 1.85
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Thu Apr 21 16:16:56 2016
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_u2pwm_alpha
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

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
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

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern u2pwm_alpha_rtModel *S;
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

  // u2pwm_alpha/manual pwm/pwm_u_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.pwm_u_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual pwm/pwm_u_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.pwm_u_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual pwm/pwm_u_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.pwm_u_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual pwm/pwm_u_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.pwm_u_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual pwm/pwm_u_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.pwm_u_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual pwm/pwm_u_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.pwm_u_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual override pwm
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.manualoverridepwm, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/u_in/u_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.u_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/u_in/u_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.u_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/u_in/u_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.u_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/u_in/u_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.u_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/u_in/u_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.u_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/u_in/u_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.u_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/alpha_in/alpha_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.alpha_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/alpha_in/alpha_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.alpha_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/alpha_in/alpha_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.alpha_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/alpha_in/alpha_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.alpha_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/alpha_in/alpha_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.alpha_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/alpha_in/alpha_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.alpha_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual alpha/man_alpha_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.man_alpha_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual alpha/man_alpha_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.man_alpha_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual alpha/man_alpha_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.man_alpha_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual alpha/man_alpha_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.man_alpha_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual alpha/man_alpha_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.man_alpha_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual alpha/man_alpha_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.man_alpha_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/manual override alpha
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&u2pwm_alpha_B.manualoverridealpha, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 26;
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

  // u2pwm_alpha/pwm/pwm_u_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch, 1, 17, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/pwm/pwm_u_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch, 2, 17, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/pwm/pwm_u_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch, 0, 17, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/pwm/pwm_u_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch, 5, 17, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/pwm/pwm_u_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch, 3, 17, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/pwm/pwm_u_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch, 4, 17, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/Need unwrapping thrusters: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.y, 0, 0, 0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/alpha_out/alpha_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch1, 1, 17,
      0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/alpha_out/alpha_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch1, 2, 17,
      0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/alpha_out/alpha_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch1, 0, 17,
      0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/alpha_out/alpha_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch1, 5, 17,
      0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/alpha_out/alpha_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch1, 3, 17,
      0);
  } else {
    index += 1;
  }

  // u2pwm_alpha/alpha_out/alpha_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch1, 4, 17,
      0);
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

  // u2pwm_alpha/pwm/pwm_u_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch, 1, 17, 0);

  // u2pwm_alpha/pwm/pwm_u_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch, 2, 17, 0);

  // u2pwm_alpha/pwm/pwm_u_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch, 0, 17, 0);

  // u2pwm_alpha/pwm/pwm_u_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch, 5, 17, 0);

  // u2pwm_alpha/pwm/pwm_u_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch, 3, 17, 0);

  // u2pwm_alpha/pwm/pwm_u_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch, 4, 17, 0);

  // u2pwm_alpha/Need unwrapping thrusters: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.y, 0, 0, 0);

  // u2pwm_alpha/alpha_out/alpha_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch1, 1, 17, 0);

  // u2pwm_alpha/alpha_out/alpha_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch1, 2, 17, 0);

  // u2pwm_alpha/alpha_out/alpha_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch1, 0, 17, 0);

  // u2pwm_alpha/alpha_out/alpha_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch1, 5, 17, 0);

  // u2pwm_alpha/alpha_out/alpha_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch1, 3, 17, 0);

  // u2pwm_alpha/alpha_out/alpha_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&u2pwm_alpha_B.Switch1, 4, 17, 0);
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
  { 0, "u2pwm_alpha/VPS_Speed_Gain1/Gain", offsetof(P_u2pwm_alpha_T, u2pwm_gain),
    26, 1, 2, 0, 0 },

  { 1, "u2pwm_alpha/VPS_Speed_Gain2/Gain", offsetof(P_u2pwm_alpha_T, u2pwm_gain),
    26, 1, 2, 2, 0 },

  { 2, "u2pwm_alpha/VPS_Speed_Gain3/Gain", offsetof(P_u2pwm_alpha_T, u2pwm_gain),
    26, 1, 2, 4, 0 },

  { 3, "u2pwm_alpha/VPS_Speed_Gain4/Gain", offsetof(P_u2pwm_alpha_T, u2pwm_gain),
    26, 1, 2, 6, 0 },

  { 4, "u2pwm_alpha/VPS_Speed_Gain5/Gain", offsetof(P_u2pwm_alpha_T, u2pwm_gain),
    26, 1, 2, 8, 0 },

  { 5, "u2pwm_alpha/VPS_Speed_Gain6/Gain", offsetof(P_u2pwm_alpha_T, u2pwm_gain),
    26, 1, 2, 10, 0 },

  { 6, "u2pwm_alpha/alpha_Offset/Value", offsetof(P_u2pwm_alpha_T, zero_alpha_1),
    26, 1, 2, 12, 0 },

  { 7, "u2pwm_alpha/alpha_Offset1/Value", offsetof(P_u2pwm_alpha_T, zero_alpha_2),
    26, 1, 2, 14, 0 },

  { 8, "u2pwm_alpha/alpha_Offset2/Value", offsetof(P_u2pwm_alpha_T, zero_alpha_3),
    26, 1, 2, 16, 0 },

  { 9, "u2pwm_alpha/alpha_Offset3/Value", offsetof(P_u2pwm_alpha_T, zero_alpha_4),
    26, 1, 2, 18, 0 },

  { 10, "u2pwm_alpha/alpha_Offset4/Value", offsetof(P_u2pwm_alpha_T,
    zero_alpha_5), 26, 1, 2, 20, 0 },

  { 11, "u2pwm_alpha/alpha_Offset5/Value", offsetof(P_u2pwm_alpha_T,
    zero_alpha_6), 26, 1, 2, 22, 0 },

  { 12, "u2pwm_alpha/PWM_Offset/Value", offsetof(P_u2pwm_alpha_T, zero_pwm), 26,
    1, 2, 24, 0 },

  { 13, "u2pwm_alpha/PWM_Offset1/Value", offsetof(P_u2pwm_alpha_T, zero_pwm), 26,
    1, 2, 26, 0 },

  { 14, "u2pwm_alpha/PWM_Offset2/Value", offsetof(P_u2pwm_alpha_T, zero_pwm), 26,
    1, 2, 28, 0 },

  { 15, "u2pwm_alpha/PWM_Offset3/Value", offsetof(P_u2pwm_alpha_T, zero_pwm), 26,
    1, 2, 30, 0 },

  { 16, "u2pwm_alpha/PWM_Offset4/Value", offsetof(P_u2pwm_alpha_T, zero_pwm), 26,
    1, 2, 32, 0 },

  { 17, "u2pwm_alpha/PWM_Offset5/Value", offsetof(P_u2pwm_alpha_T, zero_pwm), 26,
    1, 2, 34, 0 },

  { 18, "u2pwm_alpha/Saturation/UpperLimit", offsetof(P_u2pwm_alpha_T,
    Saturation_UpperSat), 26, 1, 2, 36, 0 },

  { 19, "u2pwm_alpha/Saturation/LowerLimit", offsetof(P_u2pwm_alpha_T,
    Saturation_LowerSat), 26, 1, 2, 38, 0 },

  { 20, "u2pwm_alpha/Gain/Gain", offsetof(P_u2pwm_alpha_T, Gain_Gain), 26, 1, 2,
    40, 0 },

  { 21, "u2pwm_alpha/Saturation1/UpperLimit", offsetof(P_u2pwm_alpha_T,
    Saturation1_UpperSat), 26, 1, 2, 42, 0 },

  { 22, "u2pwm_alpha/Saturation1/LowerLimit", offsetof(P_u2pwm_alpha_T,
    Saturation1_LowerSat), 26, 1, 2, 44, 0 },

  { 23, "u2pwm_alpha/Gain1/Gain", offsetof(P_u2pwm_alpha_T, Gain1_Gain), 26, 1,
    2, 46, 0 },

  { 24, "u2pwm_alpha/Saturation2/UpperLimit", offsetof(P_u2pwm_alpha_T,
    Saturation2_UpperSat), 26, 1, 2, 48, 0 },

  { 25, "u2pwm_alpha/Saturation2/LowerLimit", offsetof(P_u2pwm_alpha_T,
    Saturation2_LowerSat), 26, 1, 2, 50, 0 },

  { 26, "u2pwm_alpha/Gain2/Gain", offsetof(P_u2pwm_alpha_T, Gain2_Gain), 26, 1,
    2, 52, 0 },

  { 27, "u2pwm_alpha/Saturation3/UpperLimit", offsetof(P_u2pwm_alpha_T,
    Saturation3_UpperSat), 26, 1, 2, 54, 0 },

  { 28, "u2pwm_alpha/Saturation3/LowerLimit", offsetof(P_u2pwm_alpha_T,
    Saturation3_LowerSat), 26, 1, 2, 56, 0 },

  { 29, "u2pwm_alpha/Gain3/Gain", offsetof(P_u2pwm_alpha_T, Gain3_Gain), 26, 1,
    2, 58, 0 },

  { 30, "u2pwm_alpha/Saturation4/UpperLimit", offsetof(P_u2pwm_alpha_T,
    Saturation4_UpperSat), 26, 1, 2, 60, 0 },

  { 31, "u2pwm_alpha/Saturation4/LowerLimit", offsetof(P_u2pwm_alpha_T,
    Saturation4_LowerSat), 26, 1, 2, 62, 0 },

  { 32, "u2pwm_alpha/Gain4/Gain", offsetof(P_u2pwm_alpha_T, Gain4_Gain), 26, 1,
    2, 64, 0 },

  { 33, "u2pwm_alpha/Saturation5/UpperLimit", offsetof(P_u2pwm_alpha_T,
    Saturation5_UpperSat), 26, 1, 2, 66, 0 },

  { 34, "u2pwm_alpha/Saturation5/LowerLimit", offsetof(P_u2pwm_alpha_T,
    Saturation5_LowerSat), 26, 1, 2, 68, 0 },

  { 35, "u2pwm_alpha/Gain5/Gain", offsetof(P_u2pwm_alpha_T, Gain5_Gain), 26, 1,
    2, 70, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 36;
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
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "u2pwm_alpha/manual pwm/pwm_u_5", 0, "", offsetof(B_u2pwm_alpha_T,
    pwm_u_5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "u2pwm_alpha/manual pwm/pwm_u_4", 0, "", offsetof(B_u2pwm_alpha_T,
    pwm_u_4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "u2pwm_alpha/manual pwm/pwm_u_1", 0, "", offsetof(B_u2pwm_alpha_T,
    pwm_u_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "u2pwm_alpha/manual pwm/pwm_u_6", 0, "", offsetof(B_u2pwm_alpha_T,
    pwm_u_6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "u2pwm_alpha/manual pwm/pwm_u_2", 0, "", offsetof(B_u2pwm_alpha_T,
    pwm_u_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "u2pwm_alpha/manual pwm/pwm_u_3", 0, "", offsetof(B_u2pwm_alpha_T,
    pwm_u_3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "u2pwm_alpha/manual override pwm", 0, "", offsetof(B_u2pwm_alpha_T,
    manualoverridepwm) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "u2pwm_alpha/u_in/u_5", 0, "", offsetof(B_u2pwm_alpha_T, u_5) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "u2pwm_alpha/u_in/u_4", 0, "", offsetof(B_u2pwm_alpha_T, u_4) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "u2pwm_alpha/u_in/u_6", 0, "", offsetof(B_u2pwm_alpha_T, u_6) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "u2pwm_alpha/u_in/u_1", 0, "", offsetof(B_u2pwm_alpha_T, u_1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "u2pwm_alpha/u_in/u_2", 0, "", offsetof(B_u2pwm_alpha_T, u_2) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "u2pwm_alpha/u_in/u_3", 0, "", offsetof(B_u2pwm_alpha_T, u_3) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "u2pwm_alpha/Switch/(1, 1)", 0, "", offsetof(B_u2pwm_alpha_T, Switch) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 14, "u2pwm_alpha/Switch/(1, 2)", 0, "", offsetof(B_u2pwm_alpha_T, Switch) +
    (1*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 15, "u2pwm_alpha/Switch/(1, 3)", 0, "", offsetof(B_u2pwm_alpha_T, Switch) +
    (2*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 16, "u2pwm_alpha/Switch/(1, 4)", 0, "", offsetof(B_u2pwm_alpha_T, Switch) +
    (3*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 17, "u2pwm_alpha/Switch/(1, 5)", 0, "", offsetof(B_u2pwm_alpha_T, Switch) +
    (4*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 18, "u2pwm_alpha/Switch/(1, 6)", 0, "", offsetof(B_u2pwm_alpha_T, Switch) +
    (5*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 19, "u2pwm_alpha/alpha_in/alpha_1", 0, "", offsetof(B_u2pwm_alpha_T, alpha_1)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "u2pwm_alpha/alpha_in/alpha_2", 0, "", offsetof(B_u2pwm_alpha_T, alpha_2)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "u2pwm_alpha/alpha_in/alpha_3", 0, "", offsetof(B_u2pwm_alpha_T, alpha_3)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "u2pwm_alpha/alpha_in/alpha_4", 0, "", offsetof(B_u2pwm_alpha_T, alpha_4)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 23, "u2pwm_alpha/alpha_in/alpha_5", 0, "", offsetof(B_u2pwm_alpha_T, alpha_5)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 24, "u2pwm_alpha/alpha_in/alpha_6", 0, "", offsetof(B_u2pwm_alpha_T, alpha_6)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 25, "u2pwm_alpha/manual alpha/man_alpha_5", 0, "", offsetof(B_u2pwm_alpha_T,
    man_alpha_5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 26, "u2pwm_alpha/manual alpha/man_alpha_4", 0, "", offsetof(B_u2pwm_alpha_T,
    man_alpha_4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 27, "u2pwm_alpha/manual alpha/man_alpha_1", 0, "", offsetof(B_u2pwm_alpha_T,
    man_alpha_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 28, "u2pwm_alpha/manual alpha/man_alpha_2", 0, "", offsetof(B_u2pwm_alpha_T,
    man_alpha_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 29, "u2pwm_alpha/manual alpha/man_alpha_3", 0, "", offsetof(B_u2pwm_alpha_T,
    man_alpha_3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 30, "u2pwm_alpha/manual alpha/man_alpha_6", 0, "", offsetof(B_u2pwm_alpha_T,
    man_alpha_6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 31, "u2pwm_alpha/manual override alpha", 0, "", offsetof(B_u2pwm_alpha_T,
    manualoverridealpha) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 32, "u2pwm_alpha/Switch1/(1, 1)", 0, "", offsetof(B_u2pwm_alpha_T, Switch1)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 33, "u2pwm_alpha/Switch1/(1, 2)", 0, "", offsetof(B_u2pwm_alpha_T, Switch1)
    + (1*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 34, "u2pwm_alpha/Switch1/(1, 3)", 0, "", offsetof(B_u2pwm_alpha_T, Switch1)
    + (2*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 35, "u2pwm_alpha/Switch1/(1, 4)", 0, "", offsetof(B_u2pwm_alpha_T, Switch1)
    + (3*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 36, "u2pwm_alpha/Switch1/(1, 5)", 0, "", offsetof(B_u2pwm_alpha_T, Switch1)
    + (4*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 37, "u2pwm_alpha/Switch1/(1, 6)", 0, "", offsetof(B_u2pwm_alpha_T, Switch1)
    + (5*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 38, "u2pwm_alpha/MATLAB Function", 0, "", offsetof(B_u2pwm_alpha_T, y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 39, "u2pwm_alpha/MATLAB Function6", 0, "", offsetof(B_u2pwm_alpha_T,
    sf_MATLABFunction6.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 40, "u2pwm_alpha/MATLAB Function5", 0, "", offsetof(B_u2pwm_alpha_T,
    sf_MATLABFunction5.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 41, "u2pwm_alpha/MATLAB Function4", 0, "", offsetof(B_u2pwm_alpha_T,
    sf_MATLABFunction4.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 42, "u2pwm_alpha/MATLAB Function3", 0, "", offsetof(B_u2pwm_alpha_T,
    sf_MATLABFunction3.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 43, "u2pwm_alpha/MATLAB Function2", 0, "", offsetof(B_u2pwm_alpha_T,
    sf_MATLABFunction2.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 44, "u2pwm_alpha/MATLAB Function1", 0, "", offsetof(B_u2pwm_alpha_T,
    sf_MATLABFunction1.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 45;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 39;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "manual pwm/pwm_u_5", 0, EXT_IN, 1, 1, 1 },

  { 2, "manual pwm/pwm_u_4", 0, EXT_IN, 1, 1, 1 },

  { 3, "manual pwm/pwm_u_1", 0, EXT_IN, 1, 1, 1 },

  { 4, "manual pwm/pwm_u_6", 0, EXT_IN, 1, 1, 1 },

  { 5, "manual pwm/pwm_u_2", 0, EXT_IN, 1, 1, 1 },

  { 6, "manual pwm/pwm_u_3", 0, EXT_IN, 1, 1, 1 },

  { 7, "manual override pwm", 0, EXT_IN, 1, 1, 1 },

  { 8, "u_in/u_5", 0, EXT_IN, 1, 1, 1 },

  { 9, "u_in/u_4", 0, EXT_IN, 1, 1, 1 },

  { 10, "u_in/u_6", 0, EXT_IN, 1, 1, 1 },

  { 11, "u_in/u_1", 0, EXT_IN, 1, 1, 1 },

  { 12, "u_in/u_2", 0, EXT_IN, 1, 1, 1 },

  { 13, "u_in/u_3", 0, EXT_IN, 1, 1, 1 },

  { 14, "alpha_in/alpha_1", 0, EXT_IN, 1, 1, 1 },

  { 15, "alpha_in/alpha_2", 0, EXT_IN, 1, 1, 1 },

  { 16, "alpha_in/alpha_3", 0, EXT_IN, 1, 1, 1 },

  { 17, "alpha_in/alpha_4", 0, EXT_IN, 1, 1, 1 },

  { 18, "alpha_in/alpha_5", 0, EXT_IN, 1, 1, 1 },

  { 19, "alpha_in/alpha_6", 0, EXT_IN, 1, 1, 1 },

  { 20, "manual alpha/man_alpha_5", 0, EXT_IN, 1, 1, 1 },

  { 21, "manual alpha/man_alpha_4", 0, EXT_IN, 1, 1, 1 },

  { 22, "manual alpha/man_alpha_1", 0, EXT_IN, 1, 1, 1 },

  { 23, "manual alpha/man_alpha_2", 0, EXT_IN, 1, 1, 1 },

  { 24, "manual alpha/man_alpha_3", 0, EXT_IN, 1, 1, 1 },

  { 25, "manual alpha/man_alpha_6", 0, EXT_IN, 1, 1, 1 },

  { 26, "manual override alpha", 0, EXT_IN, 1, 1, 1 },

  { 1, "pwm/pwm_u_2", 0, EXT_OUT, 1, 1, 1 },

  { 2, "pwm/pwm_u_3", 0, EXT_OUT, 1, 1, 1 },

  { 3, "pwm/pwm_u_1", 0, EXT_OUT, 1, 1, 1 },

  { 4, "pwm/pwm_u_6", 0, EXT_OUT, 1, 1, 1 },

  { 5, "pwm/pwm_u_4", 0, EXT_OUT, 1, 1, 1 },

  { 6, "pwm/pwm_u_5", 0, EXT_OUT, 1, 1, 1 },

  { 7, "Need unwrapping thrusters", 0, EXT_OUT, 1, 1, 1 },

  { 8, "alpha_out/alpha_2", 0, EXT_OUT, 1, 1, 1 },

  { 9, "alpha_out/alpha_3", 0, EXT_OUT, 1, 1, 1 },

  { 10, "alpha_out/alpha_1", 0, EXT_OUT, 1, 1, 1 },

  { 11, "alpha_out/alpha_6", 0, EXT_OUT, 1, 1, 1 },

  { 12, "alpha_out/alpha_4", 0, EXT_OUT, 1, 1, 1 },

  { 13, "alpha_out/alpha_5", 0, EXT_OUT, 1, 1, 1 },

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
  "u2pwm_alpha";
static const char* NI_CompiledModelVersion = "1.85";
static const char* NI_CompiledModelDateTime = "Thu Apr 21 16:16:56 2016";
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
  memcpy(&rtParameter[0], &u2pwm_alpha_P, sizeof(P_u2pwm_alpha_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka u2pwm_alpha_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_u2pwm_alpha_T));
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
             (P_u2pwm_alpha_T));
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
               (P_u2pwm_alpha_T));
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
             (P_u2pwm_alpha_T));
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
           (P_u2pwm_alpha_T));
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
           (P_u2pwm_alpha_T));
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
      *numContStates = 0;
      *numDiscStates = 507;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_5_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_4_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_6_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&u2pwm_alpha_DW.manualoverridepwm_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&u2pwm_alpha_DW.manualoverridepwm_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.u_5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.u_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.u_4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.u_6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.u_1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.u_2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.u_3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_2_DWORK1_c,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_2_DWORK1_c");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_3_DWORK1_p,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_3_DWORK1_p");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_1_DWORK1_a,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_1_DWORK1_a");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_6_DWORK1_l,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_6_DWORK1_l");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_4_DWORK1_k,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_4_DWORK1_k");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_5_DWORK1_n,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_5_DWORK1_n");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_4_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_5_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_6_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&u2pwm_alpha_DW.Needunwrappingthrusters_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&u2pwm_alpha_DW.Needunwrappingthrusters_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.man_alpha_5_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.man_alpha_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.man_alpha_4_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.man_alpha_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.man_alpha_1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.man_alpha_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.man_alpha_2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.man_alpha_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.man_alpha_3_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.man_alpha_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.man_alpha_6_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.man_alpha_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&u2pwm_alpha_DW.manualoverridealpha_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&u2pwm_alpha_DW.manualoverridealpha_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_2_DWORK1_g,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_2_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_3_DWORK1_m,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_3_DWORK1_m");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_1_DWORK1_o,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_1_DWORK1_o");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_6_DWORK1_g,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_6_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_4_DWORK1_a,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_4_DWORK1_a");
    discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_5_DWORK1_c,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_5_DWORK1_c");
    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_5_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_5_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_4_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_4_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_6_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_6_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_2_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_3_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_alpha_DW.manualoverridepwm_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_alpha_DW.manualoverridepwm_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.u_5_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.u_5_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.u_4_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.u_4_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.u_6_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.u_6_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.u_1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.u_1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.u_2_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.u_2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.u_3_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.u_3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_2_DWORK2_o,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_2_DWORK2_o");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_3_DWORK2_e,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_3_DWORK2_e");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_1_DWORK2_f,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_1_DWORK2_f");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_6_DWORK2_k,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_6_DWORK2_k");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_4_DWORK2_k,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_4_DWORK2_k");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.pwm_u_5_DWORK2_l,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.pwm_u_5_DWORK2_l");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_2_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_3_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_4_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_5_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_6_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_alpha_DW.Needunwrappingthrusters_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_alpha_DW.Needunwrappingthrusters_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_alpha_DW.man_alpha_5_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_alpha_DW.man_alpha_5_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_alpha_DW.man_alpha_4_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_alpha_DW.man_alpha_4_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_alpha_DW.man_alpha_1_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_alpha_DW.man_alpha_1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_alpha_DW.man_alpha_2_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_alpha_DW.man_alpha_2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_alpha_DW.man_alpha_3_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_alpha_DW.man_alpha_3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_alpha_DW.man_alpha_6_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_alpha_DW.man_alpha_6_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&u2pwm_alpha_DW.manualoverridealpha_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&u2pwm_alpha_DW.manualoverridealpha_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_2_DWORK2_d,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_2_DWORK2_d");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_3_DWORK2_i,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_3_DWORK2_i");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_1_DWORK2_j,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_1_DWORK2_j");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_6_DWORK2_b,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_6_DWORK2_b");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_4_DWORK2_b,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_4_DWORK2_b");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&u2pwm_alpha_DW.alpha_5_DWORK2_h,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&u2pwm_alpha_DW.alpha_5_DWORK2_h");
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
  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.manualoverridepwm_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.u_5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.u_4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.u_6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.u_1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.u_2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.u_3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_2_DWORK1_c, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_3_DWORK1_p, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_1_DWORK1_a, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_6_DWORK1_l, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_4_DWORK1_k, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_5_DWORK1_n, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.Needunwrappingthrusters_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.man_alpha_5_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.man_alpha_4_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.man_alpha_1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.man_alpha_2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.man_alpha_3_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.man_alpha_6_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.manualoverridealpha_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_2_DWORK1_g, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_3_DWORK1_m, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_1_DWORK1_o, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_6_DWORK1_g, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_4_DWORK1_a, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_5_DWORK1_c, 0, discStates[idx
      ++], 0, 0);
    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_5_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_4_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_6_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_2_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_3_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.manualoverridepwm_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.u_5_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.u_4_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.u_6_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.u_1_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.u_2_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.u_3_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_2_DWORK2_o, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_3_DWORK2_e, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_1_DWORK2_f, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_6_DWORK2_k, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_4_DWORK2_k, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.pwm_u_5_DWORK2_l, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_2_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_3_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_4_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_5_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_6_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.Needunwrappingthrusters_DWORK2,
        count, discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.man_alpha_5_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.man_alpha_4_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.man_alpha_1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.man_alpha_2_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.man_alpha_3_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.man_alpha_6_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.manualoverridealpha_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_2_DWORK2_d, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_3_DWORK2_i, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_1_DWORK2_j, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_6_DWORK2_b, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_4_DWORK2_b, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&u2pwm_alpha_DW.alpha_5_DWORK2_h, count,
        discStates[idx++], 18, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_u2pwm_alpha
