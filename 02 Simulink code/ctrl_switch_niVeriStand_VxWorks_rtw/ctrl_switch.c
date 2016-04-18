/*
 * ctrl_switch.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_switch".
 *
 * Model version              : 1.23
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Apr 12 14:08:25 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_switch.h"
#include "ctrl_switch_private.h"

/* Block signals (auto storage) */
B_ctrl_switch_T ctrl_switch_B;

/* Block states (auto storage) */
DW_ctrl_switch_T ctrl_switch_DW;

/* Real-time model */
RT_MODEL_ctrl_switch_T ctrl_switch_M_;
RT_MODEL_ctrl_switch_T *const ctrl_switch_M = &ctrl_switch_M_;

/* Model output function */
static void ctrl_switch_output(void)
{
  real_T b_signal;

  /* MATLAB Function: '<S1>/Switch_function' incorporates:
   *  Memory: '<S1>/Memory'
   */
  /* MATLAB Function 'Switch_subsystem/Switch_function': '<S10>:1' */
  /* % Function that takes in impulse button sigals [0,1] and sends out a  */
  /*  different signal depentent pn which button has been pressed */
  /* '<S10>:1:8' */
  b_signal = ctrl_switch_DW.Memory_PreviousInput;
  if (ctrl_switch_B.Cross != 0.0) {
    /* '<S10>:1:10' */
    /* '<S10>:1:11' */
    b_signal = 1.0;
  }

  if (ctrl_switch_B.Square != 0.0) {
    /* '<S10>:1:14' */
    /* '<S10>:1:15' */
    b_signal = 2.0;
  }

  if (ctrl_switch_B.Circle != 0.0) {
    /* '<S10>:1:18' */
    /* '<S10>:1:19' */
    b_signal = 3.0;
  }

  if (ctrl_switch_B.Triangle != 0.0) {
    /* '<S10>:1:22' */
    /* '<S10>:1:23' */
    b_signal = 4.0;
  }

  /* '<S10>:1:26' */
  ctrl_switch_B.switch_signal = b_signal;

  /* End of MATLAB Function: '<S1>/Switch_function' */

  /* MultiPortSwitch: '<Root>/Multiport Switch' */
  switch ((int32_T)ctrl_switch_B.switch_signal) {
   case 1:
    ctrl_switch_B.MultiportSwitch[0] = ctrl_switch_B.u_1;
    ctrl_switch_B.MultiportSwitch[1] = ctrl_switch_B.u_2;
    ctrl_switch_B.MultiportSwitch[2] = ctrl_switch_B.u_3;
    ctrl_switch_B.MultiportSwitch[3] = ctrl_switch_B.u_4;
    ctrl_switch_B.MultiportSwitch[4] = ctrl_switch_B.u_5;
    ctrl_switch_B.MultiportSwitch[5] = ctrl_switch_B.u_6;
    ctrl_switch_B.MultiportSwitch[6] = ctrl_switch_B.alpha_1;
    ctrl_switch_B.MultiportSwitch[7] = ctrl_switch_B.alpha_2;
    ctrl_switch_B.MultiportSwitch[8] = ctrl_switch_B.alpha_3;
    ctrl_switch_B.MultiportSwitch[9] = ctrl_switch_B.alpha_4;
    ctrl_switch_B.MultiportSwitch[10] = ctrl_switch_B.alpha_5;
    ctrl_switch_B.MultiportSwitch[11] = ctrl_switch_B.alpha_6;
    break;

   case 2:
    ctrl_switch_B.MultiportSwitch[0] = ctrl_switch_B.u_1_l;
    ctrl_switch_B.MultiportSwitch[1] = ctrl_switch_B.u_2_e;
    ctrl_switch_B.MultiportSwitch[2] = ctrl_switch_B.u_3_p;
    ctrl_switch_B.MultiportSwitch[3] = ctrl_switch_B.u_4_f;
    ctrl_switch_B.MultiportSwitch[4] = ctrl_switch_B.u_5_i;
    ctrl_switch_B.MultiportSwitch[5] = ctrl_switch_B.u_6_e;
    ctrl_switch_B.MultiportSwitch[6] = ctrl_switch_B.alpha_1_i;
    ctrl_switch_B.MultiportSwitch[7] = ctrl_switch_B.alpha_2_p;
    ctrl_switch_B.MultiportSwitch[8] = ctrl_switch_B.alpha_3_d;
    ctrl_switch_B.MultiportSwitch[9] = ctrl_switch_B.alpha_4_b;
    ctrl_switch_B.MultiportSwitch[10] = ctrl_switch_B.alpha_5_m;
    ctrl_switch_B.MultiportSwitch[11] = ctrl_switch_B.alpha_6_j;
    break;

   case 3:
    ctrl_switch_B.MultiportSwitch[0] = ctrl_switch_B.u_1_o;
    ctrl_switch_B.MultiportSwitch[1] = ctrl_switch_B.u_2_i;
    ctrl_switch_B.MultiportSwitch[2] = ctrl_switch_B.u_3_o;
    ctrl_switch_B.MultiportSwitch[3] = ctrl_switch_B.u_4_b;
    ctrl_switch_B.MultiportSwitch[4] = ctrl_switch_B.u_5_k;
    ctrl_switch_B.MultiportSwitch[5] = ctrl_switch_B.u_6_b;
    ctrl_switch_B.MultiportSwitch[6] = ctrl_switch_B.alpha_1_h;
    ctrl_switch_B.MultiportSwitch[7] = ctrl_switch_B.alpha_2_d;
    ctrl_switch_B.MultiportSwitch[8] = ctrl_switch_B.alpha_3_k;
    ctrl_switch_B.MultiportSwitch[9] = ctrl_switch_B.alpha_4_n;
    ctrl_switch_B.MultiportSwitch[10] = ctrl_switch_B.alpha_5_i;
    ctrl_switch_B.MultiportSwitch[11] = ctrl_switch_B.alpha_6_o;
    break;

   default:
    ctrl_switch_B.MultiportSwitch[0] = ctrl_switch_B.u_1_m;
    ctrl_switch_B.MultiportSwitch[1] = ctrl_switch_B.u_2_a;
    ctrl_switch_B.MultiportSwitch[2] = ctrl_switch_B.u_3_l;
    ctrl_switch_B.MultiportSwitch[3] = ctrl_switch_B.u_4_c;
    ctrl_switch_B.MultiportSwitch[4] = ctrl_switch_B.u_5_o;
    ctrl_switch_B.MultiportSwitch[5] = ctrl_switch_B.u_6_f;
    ctrl_switch_B.MultiportSwitch[6] = ctrl_switch_B.alpha_1_j;
    ctrl_switch_B.MultiportSwitch[7] = ctrl_switch_B.alpha_2_py;
    ctrl_switch_B.MultiportSwitch[8] = ctrl_switch_B.alpha_3_o;
    ctrl_switch_B.MultiportSwitch[9] = ctrl_switch_B.alpha_4_k;
    ctrl_switch_B.MultiportSwitch[10] = ctrl_switch_B.alpha_5_n;
    ctrl_switch_B.MultiportSwitch[11] = ctrl_switch_B.alpha_6_i;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

  /* MATLAB Function: '<Root>/control limit checking' */
  /* MATLAB Function 'control limit checking': '<S2>:1' */
  /* '<S2>:1:2' */
  /* '<S2>:1:3' */
  /* '<S2>:1:4' */
  /* '<S2>:1:5' */
  /* '<S2>:1:6' */
  /* '<S2>:1:7' */
  /* '<S2>:1:9' */
  /* '<S2>:1:16' */
  ctrl_switch_B.fault = !((-1.0 <= ctrl_switch_B.MultiportSwitch[0]) &&
    (ctrl_switch_B.MultiportSwitch[0] <= 1.0) && (-1.0 <=
    ctrl_switch_B.MultiportSwitch[1]) && (ctrl_switch_B.MultiportSwitch[1] <=
    1.0) && (-1.0 <= ctrl_switch_B.MultiportSwitch[2]) &&
    (ctrl_switch_B.MultiportSwitch[2] <= 1.0) && (-1.0 <=
    ctrl_switch_B.MultiportSwitch[3]) && (ctrl_switch_B.MultiportSwitch[3] <=
    1.0) && (-1.0 <= ctrl_switch_B.MultiportSwitch[4]) &&
    (ctrl_switch_B.MultiportSwitch[4] <= 1.0) && (-1.0 <=
    ctrl_switch_B.MultiportSwitch[5]) && (ctrl_switch_B.MultiportSwitch[5] <=
    1.0));

  /* MATLAB Function: '<S7>/C' */
  /* MATLAB Function 'indicator/C': '<S11>:1' */
  /* '<S11>:1:3' */
  ctrl_switch_B.ctrl_sixaxis2thruster = false;

  /* '<S11>:1:4' */
  ctrl_switch_B.ctrl_sixaxis2force = false;

  /* '<S11>:1:5' */
  ctrl_switch_B.ctrl_DP_basic = false;

  /* '<S11>:1:6' */
  ctrl_switch_B.ctrl_student = false;
  if (ctrl_switch_B.switch_signal == 1.0) {
    /* '<S11>:1:8' */
    /* '<S11>:1:9' */
    ctrl_switch_B.ctrl_student = true;
  } else if (ctrl_switch_B.switch_signal == 2.0) {
    /* '<S11>:1:10' */
    /* '<S11>:1:11' */
    ctrl_switch_B.ctrl_sixaxis2force = true;
  } else if (ctrl_switch_B.switch_signal == 3.0) {
    /* '<S11>:1:12' */
    /* '<S11>:1:13' */
    ctrl_switch_B.ctrl_DP_basic = true;
  } else {
    if (ctrl_switch_B.switch_signal == 4.0) {
      /* '<S11>:1:14' */
      /* '<S11>:1:15' */
      ctrl_switch_B.ctrl_sixaxis2thruster = true;
    }
  }

  /* End of MATLAB Function: '<S7>/C' */

  /* Saturate: '<S9>/Saturation4' */
  if (ctrl_switch_B.MultiportSwitch[4] > ctrl_switch_P.Saturation4_UpperSat) {
    ctrl_switch_B.Saturation4 = ctrl_switch_P.Saturation4_UpperSat;
  } else if (ctrl_switch_B.MultiportSwitch[4] <
             ctrl_switch_P.Saturation4_LowerSat) {
    ctrl_switch_B.Saturation4 = ctrl_switch_P.Saturation4_LowerSat;
  } else {
    ctrl_switch_B.Saturation4 = ctrl_switch_B.MultiportSwitch[4];
  }

  /* End of Saturate: '<S9>/Saturation4' */

  /* Saturate: '<S9>/Saturation' */
  if (ctrl_switch_B.MultiportSwitch[0] > ctrl_switch_P.Saturation_UpperSat) {
    ctrl_switch_B.Saturation = ctrl_switch_P.Saturation_UpperSat;
  } else if (ctrl_switch_B.MultiportSwitch[0] <
             ctrl_switch_P.Saturation_LowerSat) {
    ctrl_switch_B.Saturation = ctrl_switch_P.Saturation_LowerSat;
  } else {
    ctrl_switch_B.Saturation = ctrl_switch_B.MultiportSwitch[0];
  }

  /* End of Saturate: '<S9>/Saturation' */

  /* Saturate: '<S9>/Saturation1' */
  if (ctrl_switch_B.MultiportSwitch[1] > ctrl_switch_P.Saturation1_UpperSat) {
    ctrl_switch_B.Saturation1 = ctrl_switch_P.Saturation1_UpperSat;
  } else if (ctrl_switch_B.MultiportSwitch[1] <
             ctrl_switch_P.Saturation1_LowerSat) {
    ctrl_switch_B.Saturation1 = ctrl_switch_P.Saturation1_LowerSat;
  } else {
    ctrl_switch_B.Saturation1 = ctrl_switch_B.MultiportSwitch[1];
  }

  /* End of Saturate: '<S9>/Saturation1' */

  /* Saturate: '<S9>/Saturation2' */
  if (ctrl_switch_B.MultiportSwitch[2] > ctrl_switch_P.Saturation2_UpperSat) {
    ctrl_switch_B.Saturation2 = ctrl_switch_P.Saturation2_UpperSat;
  } else if (ctrl_switch_B.MultiportSwitch[2] <
             ctrl_switch_P.Saturation2_LowerSat) {
    ctrl_switch_B.Saturation2 = ctrl_switch_P.Saturation2_LowerSat;
  } else {
    ctrl_switch_B.Saturation2 = ctrl_switch_B.MultiportSwitch[2];
  }

  /* End of Saturate: '<S9>/Saturation2' */

  /* Saturate: '<S9>/Saturation3' */
  if (ctrl_switch_B.MultiportSwitch[3] > ctrl_switch_P.Saturation3_UpperSat) {
    ctrl_switch_B.Saturation3 = ctrl_switch_P.Saturation3_UpperSat;
  } else if (ctrl_switch_B.MultiportSwitch[3] <
             ctrl_switch_P.Saturation3_LowerSat) {
    ctrl_switch_B.Saturation3 = ctrl_switch_P.Saturation3_LowerSat;
  } else {
    ctrl_switch_B.Saturation3 = ctrl_switch_B.MultiportSwitch[3];
  }

  /* End of Saturate: '<S9>/Saturation3' */

  /* Saturate: '<S9>/Saturation5' */
  if (ctrl_switch_B.MultiportSwitch[5] > ctrl_switch_P.Saturation5_UpperSat) {
    ctrl_switch_B.Saturation5 = ctrl_switch_P.Saturation5_UpperSat;
  } else if (ctrl_switch_B.MultiportSwitch[5] <
             ctrl_switch_P.Saturation5_LowerSat) {
    ctrl_switch_B.Saturation5 = ctrl_switch_P.Saturation5_LowerSat;
  } else {
    ctrl_switch_B.Saturation5 = ctrl_switch_B.MultiportSwitch[5];
  }

  /* End of Saturate: '<S9>/Saturation5' */
}

/* Model update function */
static void ctrl_switch_update(void)
{
  /* Update for Memory: '<S1>/Memory' */
  ctrl_switch_DW.Memory_PreviousInput = ctrl_switch_B.switch_signal;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_switch_M->Timing.clockTick0)) {
    ++ctrl_switch_M->Timing.clockTickH0;
  }

  ctrl_switch_M->Timing.t[0] = ctrl_switch_M->Timing.clockTick0 *
    ctrl_switch_M->Timing.stepSize0 + ctrl_switch_M->Timing.clockTickH0 *
    ctrl_switch_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void ctrl_switch_initialize(void)
{
  /* InitializeConditions for Memory: '<S1>/Memory' */
  ctrl_switch_DW.Memory_PreviousInput = ctrl_switch_P.Memory_X0;
}

/* Model terminate function */
static void ctrl_switch_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  ctrl_switch_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_switch_update();
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
  ctrl_switch_initialize();
}

void MdlTerminate(void)
{
  ctrl_switch_terminate();
}

/* Registration function */
RT_MODEL_ctrl_switch_T *ctrl_switch(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_switch_M, 0,
                sizeof(RT_MODEL_ctrl_switch_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_switch_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    ctrl_switch_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_switch_M->Timing.sampleTimes = (&ctrl_switch_M->
      Timing.sampleTimesArray[0]);
    ctrl_switch_M->Timing.offsetTimes = (&ctrl_switch_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_switch_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    ctrl_switch_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(ctrl_switch_M, &ctrl_switch_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_switch_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    ctrl_switch_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_switch_M, -1);
  ctrl_switch_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_switch_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_switch_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_switch_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_switch_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_switch_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_switch_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_switch_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_switch_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_switch_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_switch_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_switch_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_switch_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_switch_M->rtwLogInfo, (NULL));
  }

  ctrl_switch_M->solverInfoPtr = (&ctrl_switch_M->solverInfo);
  ctrl_switch_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_switch_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_switch_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_switch_M->ModelData.blockIO = ((void *) &ctrl_switch_B);
  (void) memset(((void *) &ctrl_switch_B), 0,
                sizeof(B_ctrl_switch_T));

  /* parameters */
  ctrl_switch_M->ModelData.defaultParam = ((real_T *)&ctrl_switch_P);

  /* states (dwork) */
  ctrl_switch_M->ModelData.dwork = ((void *) &ctrl_switch_DW);
  (void) memset((void *)&ctrl_switch_DW, 0,
                sizeof(DW_ctrl_switch_T));

  /* Initialize Sizes */
  ctrl_switch_M->Sizes.numContStates = (0);/* Number of continuous states */
  ctrl_switch_M->Sizes.numY = (0);     /* Number of model outputs */
  ctrl_switch_M->Sizes.numU = (0);     /* Number of model inputs */
  ctrl_switch_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_switch_M->Sizes.numSampTimes = (1);/* Number of sample times */
  ctrl_switch_M->Sizes.numBlocks = (83);/* Number of blocks */
  ctrl_switch_M->Sizes.numBlockIO = (65);/* Number of block outputs */
  ctrl_switch_M->Sizes.numBlockPrms = (427);/* Sum of parameter "widths" */
  return ctrl_switch_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_switch
 * Model version : 1.23
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Tue Apr 12 14:08:25 2016
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_switch
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

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
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

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_switch_rtModel *S;
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

  // ctrl_switch/sixaxis/Triangle
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.Triangle, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/sixaxis/Circle
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.Circle, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/sixaxis/Cross
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.Cross, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/sixaxis/Square
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.Square, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_student/u_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_student/u_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_student/u_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_student/alpha_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_student/u_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_student/u_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_student/u_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_student/alpha_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_student/alpha_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_student/alpha_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_student/alpha_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_student/alpha_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2force/u_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_1_l, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2force/u_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_3_p, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2force/u_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_6_e, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2force/alpha_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_1_i, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2force/u_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_2_e, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2force/u_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_4_f, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2force/u_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_5_i, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2force/alpha_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_2_p, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2force/alpha_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_3_d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2force/alpha_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_4_b, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2force/alpha_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_5_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2force/alpha_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_6_j, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_DP_basic/u_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_1_o, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_DP_basic/u_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_3_o, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_DP_basic/u_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_6_b, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_DP_basic/alpha_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_1_h, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_DP_basic/u_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_2_i, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_DP_basic/u_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_4_b, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_DP_basic/u_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_5_k, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_DP_basic/alpha_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_2_d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_DP_basic/alpha_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_3_k, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_DP_basic/alpha_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_4_n, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_DP_basic/alpha_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_5_i, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_DP_basic/alpha_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_6_o, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2thruster/u_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_1_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2thruster/u_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_3_l, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2thruster/u_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_6_f, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2thruster/alpha_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_1_j, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2thruster/u_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_2_a, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2thruster/u_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_4_c, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2thruster/u_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.u_5_o, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2thruster/alpha_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_2_py, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2thruster/alpha_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_3_o, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2thruster/alpha_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_4_k, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2thruster/alpha_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_5_n, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/ctrl_sixaxis2thruster/alpha_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_switch_B.alpha_6_i, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 52;
}

int32_t NumOutputPorts(void)
{
  return 17;
}

double ni_extout[17];

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

  // ctrl_switch/control input u exceeds bounds: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.fault, 0, 8, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/indicator/ctrl_student: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.ctrl_student, 0,
      8, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/indicator/ctrl_DP_basic: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.ctrl_DP_basic, 0,
      8, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/indicator/ctrl_sixaxis2force: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_switch_B.ctrl_sixaxis2force, 0, 8, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/indicator/ctrl_sixaxis2thruster: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_switch_B.ctrl_sixaxis2thruster, 0, 8, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/u_d/u_5,d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.Saturation4, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/u_d/u_1,d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.Saturation, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_switch/u_d/u_2,d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.Saturation1, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/u_d/u_3,d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.Saturation2, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/u_d/u_4,d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.Saturation3, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/u_d/u_6,d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.Saturation5, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/u_d/alpha_1,d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.MultiportSwitch,
      6, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/u_d/alpha_2,d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.MultiportSwitch,
      7, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/u_d/alpha_3,d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.MultiportSwitch,
      8, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/u_d/alpha_4,d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.MultiportSwitch,
      9, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/u_d/alpha_5,d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.MultiportSwitch,
      10, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_switch/u_d/alpha_6,d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.MultiportSwitch,
      11, 17, 0);
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

  // ctrl_switch/control input u exceeds bounds: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.fault, 0, 8, 0);

  // ctrl_switch/indicator/ctrl_student: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.ctrl_student, 0, 8,
    0);

  // ctrl_switch/indicator/ctrl_DP_basic: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.ctrl_DP_basic, 0,
    8, 0);

  // ctrl_switch/indicator/ctrl_sixaxis2force: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.ctrl_sixaxis2force,
    0, 8, 0);

  // ctrl_switch/indicator/ctrl_sixaxis2thruster: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_switch_B.ctrl_sixaxis2thruster, 0, 8, 0);

  // ctrl_switch/u_d/u_5,d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.Saturation4, 0, 0,
    0);

  // ctrl_switch/u_d/u_1,d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.Saturation, 0, 0,
    0);

  // ctrl_switch/u_d/u_2,d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.Saturation1, 0, 0,
    0);

  // ctrl_switch/u_d/u_3,d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.Saturation2, 0, 0,
    0);

  // ctrl_switch/u_d/u_4,d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.Saturation3, 0, 0,
    0);

  // ctrl_switch/u_d/u_6,d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.Saturation5, 0, 0,
    0);

  // ctrl_switch/u_d/alpha_1,d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.MultiportSwitch, 6,
    17, 0);

  // ctrl_switch/u_d/alpha_2,d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.MultiportSwitch, 7,
    17, 0);

  // ctrl_switch/u_d/alpha_3,d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.MultiportSwitch, 8,
    17, 0);

  // ctrl_switch/u_d/alpha_4,d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.MultiportSwitch, 9,
    17, 0);

  // ctrl_switch/u_d/alpha_5,d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.MultiportSwitch,
    10, 17, 0);

  // ctrl_switch/u_d/alpha_6,d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_switch_B.MultiportSwitch,
    11, 17, 0);
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
  { 0, "ctrl_switch/Switch_subsystem/Memory/X0", offsetof(P_ctrl_switch_T,
    Memory_X0), 22, 1, 2, 0, 0 },

  { 1, "ctrl_switch/u_d/Saturation4/UpperLimit", offsetof(P_ctrl_switch_T,
    Saturation4_UpperSat), 22, 1, 2, 2, 0 },

  { 2, "ctrl_switch/u_d/Saturation4/LowerLimit", offsetof(P_ctrl_switch_T,
    Saturation4_LowerSat), 22, 1, 2, 4, 0 },

  { 3, "ctrl_switch/u_d/Saturation/UpperLimit", offsetof(P_ctrl_switch_T,
    Saturation_UpperSat), 22, 1, 2, 6, 0 },

  { 4, "ctrl_switch/u_d/Saturation/LowerLimit", offsetof(P_ctrl_switch_T,
    Saturation_LowerSat), 22, 1, 2, 8, 0 },

  { 5, "ctrl_switch/u_d/Saturation1/UpperLimit", offsetof(P_ctrl_switch_T,
    Saturation1_UpperSat), 22, 1, 2, 10, 0 },

  { 6, "ctrl_switch/u_d/Saturation1/LowerLimit", offsetof(P_ctrl_switch_T,
    Saturation1_LowerSat), 22, 1, 2, 12, 0 },

  { 7, "ctrl_switch/u_d/Saturation2/UpperLimit", offsetof(P_ctrl_switch_T,
    Saturation2_UpperSat), 22, 1, 2, 14, 0 },

  { 8, "ctrl_switch/u_d/Saturation2/LowerLimit", offsetof(P_ctrl_switch_T,
    Saturation2_LowerSat), 22, 1, 2, 16, 0 },

  { 9, "ctrl_switch/u_d/Saturation3/UpperLimit", offsetof(P_ctrl_switch_T,
    Saturation3_UpperSat), 22, 1, 2, 18, 0 },

  { 10, "ctrl_switch/u_d/Saturation3/LowerLimit", offsetof(P_ctrl_switch_T,
    Saturation3_LowerSat), 22, 1, 2, 20, 0 },

  { 11, "ctrl_switch/u_d/Saturation5/UpperLimit", offsetof(P_ctrl_switch_T,
    Saturation5_UpperSat), 22, 1, 2, 22, 0 },

  { 12, "ctrl_switch/u_d/Saturation5/LowerLimit", offsetof(P_ctrl_switch_T,
    Saturation5_LowerSat), 22, 1, 2, 24, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 13;
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
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_switch/sixaxis/Triangle", 0, "", offsetof(B_ctrl_switch_T, Triangle)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_switch/sixaxis/Circle", 0, "", offsetof(B_ctrl_switch_T, Circle) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_switch/sixaxis/Cross", 0, "", offsetof(B_ctrl_switch_T, Cross) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "ctrl_switch/sixaxis/Square", 0, "", offsetof(B_ctrl_switch_T, Square) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "ctrl_switch/ctrl_student/u_1", 0, "", offsetof(B_ctrl_switch_T, u_1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "ctrl_switch/ctrl_student/u_3", 0, "", offsetof(B_ctrl_switch_T, u_3) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "ctrl_switch/ctrl_student/u_6", 0, "", offsetof(B_ctrl_switch_T, u_6) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "ctrl_switch/ctrl_student/alpha_1", 0, "", offsetof(B_ctrl_switch_T,
    alpha_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "ctrl_switch/ctrl_student/u_2", 0, "", offsetof(B_ctrl_switch_T, u_2) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "ctrl_switch/ctrl_student/u_4", 0, "", offsetof(B_ctrl_switch_T, u_4) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_switch/ctrl_student/u_5", 0, "", offsetof(B_ctrl_switch_T, u_5) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_switch/ctrl_student/alpha_2", 0, "", offsetof(B_ctrl_switch_T,
    alpha_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_switch/ctrl_student/alpha_3", 0, "", offsetof(B_ctrl_switch_T,
    alpha_3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_switch/ctrl_student/alpha_4", 0, "", offsetof(B_ctrl_switch_T,
    alpha_4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "ctrl_switch/ctrl_student/alpha_5", 0, "", offsetof(B_ctrl_switch_T,
    alpha_5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "ctrl_switch/ctrl_student/alpha_6", 0, "", offsetof(B_ctrl_switch_T,
    alpha_6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "ctrl_switch/ctrl_sixaxis2force/u_1", 0, "", offsetof(B_ctrl_switch_T,
    u_1_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "ctrl_switch/ctrl_sixaxis2force/u_3", 0, "", offsetof(B_ctrl_switch_T,
    u_3_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "ctrl_switch/ctrl_sixaxis2force/u_6", 0, "", offsetof(B_ctrl_switch_T,
    u_6_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 19, "ctrl_switch/ctrl_sixaxis2force/alpha_1", 0, "", offsetof
    (B_ctrl_switch_T, alpha_1_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 20, "ctrl_switch/ctrl_sixaxis2force/u_2", 0, "", offsetof(B_ctrl_switch_T,
    u_2_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "ctrl_switch/ctrl_sixaxis2force/u_4", 0, "", offsetof(B_ctrl_switch_T,
    u_4_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "ctrl_switch/ctrl_sixaxis2force/u_5", 0, "", offsetof(B_ctrl_switch_T,
    u_5_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 23, "ctrl_switch/ctrl_sixaxis2force/alpha_2", 0, "", offsetof
    (B_ctrl_switch_T, alpha_2_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 24, "ctrl_switch/ctrl_sixaxis2force/alpha_3", 0, "", offsetof
    (B_ctrl_switch_T, alpha_3_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 25, "ctrl_switch/ctrl_sixaxis2force/alpha_4", 0, "", offsetof
    (B_ctrl_switch_T, alpha_4_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 26, "ctrl_switch/ctrl_sixaxis2force/alpha_5", 0, "", offsetof
    (B_ctrl_switch_T, alpha_5_m) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 27, "ctrl_switch/ctrl_sixaxis2force/alpha_6", 0, "", offsetof
    (B_ctrl_switch_T, alpha_6_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 28, "ctrl_switch/ctrl_DP_basic/u_1", 0, "", offsetof(B_ctrl_switch_T, u_1_o)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 29, "ctrl_switch/ctrl_DP_basic/u_3", 0, "", offsetof(B_ctrl_switch_T, u_3_o)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 30, "ctrl_switch/ctrl_DP_basic/u_6", 0, "", offsetof(B_ctrl_switch_T, u_6_b)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 31, "ctrl_switch/ctrl_DP_basic/alpha_1", 0, "", offsetof(B_ctrl_switch_T,
    alpha_1_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 32, "ctrl_switch/ctrl_DP_basic/u_2", 0, "", offsetof(B_ctrl_switch_T, u_2_i)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 33, "ctrl_switch/ctrl_DP_basic/u_4", 0, "", offsetof(B_ctrl_switch_T, u_4_b)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 34, "ctrl_switch/ctrl_DP_basic/u_5", 0, "", offsetof(B_ctrl_switch_T, u_5_k)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 35, "ctrl_switch/ctrl_DP_basic/alpha_2", 0, "", offsetof(B_ctrl_switch_T,
    alpha_2_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 36, "ctrl_switch/ctrl_DP_basic/alpha_3", 0, "", offsetof(B_ctrl_switch_T,
    alpha_3_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 37, "ctrl_switch/ctrl_DP_basic/alpha_4", 0, "", offsetof(B_ctrl_switch_T,
    alpha_4_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 38, "ctrl_switch/ctrl_DP_basic/alpha_5", 0, "", offsetof(B_ctrl_switch_T,
    alpha_5_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 39, "ctrl_switch/ctrl_DP_basic/alpha_6", 0, "", offsetof(B_ctrl_switch_T,
    alpha_6_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 40, "ctrl_switch/ctrl_sixaxis2thruster/u_1", 0, "", offsetof(B_ctrl_switch_T,
    u_1_m) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 41, "ctrl_switch/ctrl_sixaxis2thruster/u_3", 0, "", offsetof(B_ctrl_switch_T,
    u_3_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 42, "ctrl_switch/ctrl_sixaxis2thruster/u_6", 0, "", offsetof(B_ctrl_switch_T,
    u_6_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 43, "ctrl_switch/ctrl_sixaxis2thruster/alpha_1", 0, "", offsetof
    (B_ctrl_switch_T, alpha_1_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 44, "ctrl_switch/ctrl_sixaxis2thruster/u_2", 0, "", offsetof(B_ctrl_switch_T,
    u_2_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 45, "ctrl_switch/ctrl_sixaxis2thruster/u_4", 0, "", offsetof(B_ctrl_switch_T,
    u_4_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 46, "ctrl_switch/ctrl_sixaxis2thruster/u_5", 0, "", offsetof(B_ctrl_switch_T,
    u_5_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 47, "ctrl_switch/ctrl_sixaxis2thruster/alpha_2", 0, "", offsetof
    (B_ctrl_switch_T, alpha_2_py) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 48, "ctrl_switch/ctrl_sixaxis2thruster/alpha_3", 0, "", offsetof
    (B_ctrl_switch_T, alpha_3_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 49, "ctrl_switch/ctrl_sixaxis2thruster/alpha_4", 0, "", offsetof
    (B_ctrl_switch_T, alpha_4_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 50, "ctrl_switch/ctrl_sixaxis2thruster/alpha_5", 0, "", offsetof
    (B_ctrl_switch_T, alpha_5_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 51, "ctrl_switch/ctrl_sixaxis2thruster/alpha_6", 0, "", offsetof
    (B_ctrl_switch_T, alpha_6_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 52, "ctrl_switch/Multiport Switch/(1, 1)", 0, "", offsetof(B_ctrl_switch_T,
    MultiportSwitch) + (0*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 53, "ctrl_switch/Multiport Switch/(1, 2)", 0, "", offsetof(B_ctrl_switch_T,
    MultiportSwitch) + (1*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 54, "ctrl_switch/Multiport Switch/(1, 3)", 0, "", offsetof(B_ctrl_switch_T,
    MultiportSwitch) + (2*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 55, "ctrl_switch/Multiport Switch/(1, 4)", 0, "", offsetof(B_ctrl_switch_T,
    MultiportSwitch) + (3*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 56, "ctrl_switch/Multiport Switch/(1, 5)", 0, "", offsetof(B_ctrl_switch_T,
    MultiportSwitch) + (4*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 57, "ctrl_switch/Multiport Switch/(1, 6)", 0, "", offsetof(B_ctrl_switch_T,
    MultiportSwitch) + (5*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 58, "ctrl_switch/Multiport Switch/(1, 7)", 0, "", offsetof(B_ctrl_switch_T,
    MultiportSwitch) + (6*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 59, "ctrl_switch/Multiport Switch/(1, 8)", 0, "", offsetof(B_ctrl_switch_T,
    MultiportSwitch) + (7*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 60, "ctrl_switch/Multiport Switch/(1, 9)", 0, "", offsetof(B_ctrl_switch_T,
    MultiportSwitch) + (8*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 61, "ctrl_switch/Multiport Switch/(1, 10)", 0, "", offsetof(B_ctrl_switch_T,
    MultiportSwitch) + (9*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 62, "ctrl_switch/Multiport Switch/(1, 11)", 0, "", offsetof(B_ctrl_switch_T,
    MultiportSwitch) + (10*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 63, "ctrl_switch/Multiport Switch/(1, 12)", 0, "", offsetof(B_ctrl_switch_T,
    MultiportSwitch) + (11*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 64, "ctrl_switch/u_d/Saturation4", 0, "", offsetof(B_ctrl_switch_T,
    Saturation4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 65, "ctrl_switch/u_d/Saturation", 0, "", offsetof(B_ctrl_switch_T,
    Saturation) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 66, "ctrl_switch/u_d/Saturation1", 0, "", offsetof(B_ctrl_switch_T,
    Saturation1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 67, "ctrl_switch/u_d/Saturation2", 0, "", offsetof(B_ctrl_switch_T,
    Saturation2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 68, "ctrl_switch/u_d/Saturation3", 0, "", offsetof(B_ctrl_switch_T,
    Saturation3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 69, "ctrl_switch/u_d/Saturation5", 0, "", offsetof(B_ctrl_switch_T,
    Saturation5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 70, "ctrl_switch/Switch_subsystem/Switch_function", 0, "", offsetof
    (B_ctrl_switch_T, switch_signal) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 71, "ctrl_switch/indicator/C", 0, "", offsetof(B_ctrl_switch_T, ctrl_student)
    + (0*sizeof(boolean_T)), BLOCKIO_SIG, 8, 1, 2, 0, 0 },

  { 72, "ctrl_switch/indicator/C", 1, "", offsetof(B_ctrl_switch_T,
    ctrl_DP_basic) + (0*sizeof(boolean_T)), BLOCKIO_SIG, 8, 1, 2, 0, 0 },

  { 73, "ctrl_switch/indicator/C", 2, "", offsetof(B_ctrl_switch_T,
    ctrl_sixaxis2force) + (0*sizeof(boolean_T)), BLOCKIO_SIG, 8, 1, 2, 0, 0 },

  { 74, "ctrl_switch/indicator/C", 3, "", offsetof(B_ctrl_switch_T,
    ctrl_sixaxis2thruster) + (0*sizeof(boolean_T)), BLOCKIO_SIG, 8, 1, 2, 0, 0 },

  { 75, "ctrl_switch/control limit checking", 0, "", offsetof(B_ctrl_switch_T,
    fault) + (0*sizeof(boolean_T)), BLOCKIO_SIG, 8, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 76;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 69;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "sixaxis/Triangle", 0, EXT_IN, 1, 1, 1 },

  { 2, "sixaxis/Circle", 0, EXT_IN, 1, 1, 1 },

  { 3, "sixaxis/Cross", 0, EXT_IN, 1, 1, 1 },

  { 4, "sixaxis/Square", 0, EXT_IN, 1, 1, 1 },

  { 5, "ctrl_student/u_1", 0, EXT_IN, 1, 1, 1 },

  { 6, "ctrl_student/u_3", 0, EXT_IN, 1, 1, 1 },

  { 7, "ctrl_student/u_6", 0, EXT_IN, 1, 1, 1 },

  { 8, "ctrl_student/alpha_1", 0, EXT_IN, 1, 1, 1 },

  { 9, "ctrl_student/u_2", 0, EXT_IN, 1, 1, 1 },

  { 10, "ctrl_student/u_4", 0, EXT_IN, 1, 1, 1 },

  { 11, "ctrl_student/u_5", 0, EXT_IN, 1, 1, 1 },

  { 12, "ctrl_student/alpha_2", 0, EXT_IN, 1, 1, 1 },

  { 13, "ctrl_student/alpha_3", 0, EXT_IN, 1, 1, 1 },

  { 14, "ctrl_student/alpha_4", 0, EXT_IN, 1, 1, 1 },

  { 15, "ctrl_student/alpha_5", 0, EXT_IN, 1, 1, 1 },

  { 16, "ctrl_student/alpha_6", 0, EXT_IN, 1, 1, 1 },

  { 17, "ctrl_sixaxis2force/u_1", 0, EXT_IN, 1, 1, 1 },

  { 18, "ctrl_sixaxis2force/u_3", 0, EXT_IN, 1, 1, 1 },

  { 19, "ctrl_sixaxis2force/u_6", 0, EXT_IN, 1, 1, 1 },

  { 20, "ctrl_sixaxis2force/alpha_1", 0, EXT_IN, 1, 1, 1 },

  { 21, "ctrl_sixaxis2force/u_2", 0, EXT_IN, 1, 1, 1 },

  { 22, "ctrl_sixaxis2force/u_4", 0, EXT_IN, 1, 1, 1 },

  { 23, "ctrl_sixaxis2force/u_5", 0, EXT_IN, 1, 1, 1 },

  { 24, "ctrl_sixaxis2force/alpha_2", 0, EXT_IN, 1, 1, 1 },

  { 25, "ctrl_sixaxis2force/alpha_3", 0, EXT_IN, 1, 1, 1 },

  { 26, "ctrl_sixaxis2force/alpha_4", 0, EXT_IN, 1, 1, 1 },

  { 27, "ctrl_sixaxis2force/alpha_5", 0, EXT_IN, 1, 1, 1 },

  { 28, "ctrl_sixaxis2force/alpha_6", 0, EXT_IN, 1, 1, 1 },

  { 29, "ctrl_DP_basic/u_1", 0, EXT_IN, 1, 1, 1 },

  { 30, "ctrl_DP_basic/u_3", 0, EXT_IN, 1, 1, 1 },

  { 31, "ctrl_DP_basic/u_6", 0, EXT_IN, 1, 1, 1 },

  { 32, "ctrl_DP_basic/alpha_1", 0, EXT_IN, 1, 1, 1 },

  { 33, "ctrl_DP_basic/u_2", 0, EXT_IN, 1, 1, 1 },

  { 34, "ctrl_DP_basic/u_4", 0, EXT_IN, 1, 1, 1 },

  { 35, "ctrl_DP_basic/u_5", 0, EXT_IN, 1, 1, 1 },

  { 36, "ctrl_DP_basic/alpha_2", 0, EXT_IN, 1, 1, 1 },

  { 37, "ctrl_DP_basic/alpha_3", 0, EXT_IN, 1, 1, 1 },

  { 38, "ctrl_DP_basic/alpha_4", 0, EXT_IN, 1, 1, 1 },

  { 39, "ctrl_DP_basic/alpha_5", 0, EXT_IN, 1, 1, 1 },

  { 40, "ctrl_DP_basic/alpha_6", 0, EXT_IN, 1, 1, 1 },

  { 41, "ctrl_sixaxis2thruster/u_1", 0, EXT_IN, 1, 1, 1 },

  { 42, "ctrl_sixaxis2thruster/u_3", 0, EXT_IN, 1, 1, 1 },

  { 43, "ctrl_sixaxis2thruster/u_6", 0, EXT_IN, 1, 1, 1 },

  { 44, "ctrl_sixaxis2thruster/alpha_1", 0, EXT_IN, 1, 1, 1 },

  { 45, "ctrl_sixaxis2thruster/u_2", 0, EXT_IN, 1, 1, 1 },

  { 46, "ctrl_sixaxis2thruster/u_4", 0, EXT_IN, 1, 1, 1 },

  { 47, "ctrl_sixaxis2thruster/u_5", 0, EXT_IN, 1, 1, 1 },

  { 48, "ctrl_sixaxis2thruster/alpha_2", 0, EXT_IN, 1, 1, 1 },

  { 49, "ctrl_sixaxis2thruster/alpha_3", 0, EXT_IN, 1, 1, 1 },

  { 50, "ctrl_sixaxis2thruster/alpha_4", 0, EXT_IN, 1, 1, 1 },

  { 51, "ctrl_sixaxis2thruster/alpha_5", 0, EXT_IN, 1, 1, 1 },

  { 52, "ctrl_sixaxis2thruster/alpha_6", 0, EXT_IN, 1, 1, 1 },

  { 1, "control input u exceeds bounds", 0, EXT_OUT, 1, 1, 1 },

  { 2, "indicator/ctrl_student", 0, EXT_OUT, 1, 1, 1 },

  { 3, "indicator/ctrl_DP_basic", 0, EXT_OUT, 1, 1, 1 },

  { 4, "indicator/ctrl_sixaxis2force", 0, EXT_OUT, 1, 1, 1 },

  { 5, "indicator/ctrl_sixaxis2thruster", 0, EXT_OUT, 1, 1, 1 },

  { 6, "u_d/u_5,d", 0, EXT_OUT, 1, 1, 1 },

  { 7, "u_d/u_1,d", 0, EXT_OUT, 1, 1, 1 },

  { 8, "u_d/u_2,d", 0, EXT_OUT, 1, 1, 1 },

  { 9, "u_d/u_3,d", 0, EXT_OUT, 1, 1, 1 },

  { 10, "u_d/u_4,d", 0, EXT_OUT, 1, 1, 1 },

  { 11, "u_d/u_6,d", 0, EXT_OUT, 1, 1, 1 },

  { 12, "u_d/alpha_1,d", 0, EXT_OUT, 1, 1, 1 },

  { 13, "u_d/alpha_2,d", 0, EXT_OUT, 1, 1, 1 },

  { 14, "u_d/alpha_3,d", 0, EXT_OUT, 1, 1, 1 },

  { 15, "u_d/alpha_4,d", 0, EXT_OUT, 1, 1, 1 },

  { 16, "u_d/alpha_5,d", 0, EXT_OUT, 1, 1, 1 },

  { 17, "u_d/alpha_6,d", 0, EXT_OUT, 1, 1, 1 },

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
  "ctrl_switch";
static const char* NI_CompiledModelVersion = "1.23";
static const char* NI_CompiledModelDateTime = "Tue Apr 12 14:08:25 2016";
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
  memcpy(&rtParameter[0], &ctrl_switch_P, sizeof(P_ctrl_switch_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_switch_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_switch_T));
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
             (P_ctrl_switch_T));
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
               (P_ctrl_switch_T));
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
             (P_ctrl_switch_T));
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
           (P_ctrl_switch_T));
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
           (P_ctrl_switch_T));
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
      *numDiscStates = 898;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.Triangle_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.Triangle_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.Circle_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.Circle_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.Cross_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.Cross_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.Square_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.Square_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_switch_DW.Memory_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_switch_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_1_DWORK1_h, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_1_DWORK1_h");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_3_DWORK1_p, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_3_DWORK1_p");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_6_DWORK1_f, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_6_DWORK1_f");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK1_g,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_1_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_2_DWORK1_d, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_2_DWORK1_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_4_DWORK1_g, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_4_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_5_DWORK1_e, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_5_DWORK1_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK1_e,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_2_DWORK1_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK1_o,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_3_DWORK1_o");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK1_n,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_4_DWORK1_n");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK1_a,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_5_DWORK1_a");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK1_f,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_6_DWORK1_f");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_1_DWORK1_o, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_1_DWORK1_o");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_3_DWORK1_o, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_3_DWORK1_o");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_6_DWORK1_e, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_6_DWORK1_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK1_k,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_1_DWORK1_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_2_DWORK1_f, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_2_DWORK1_f");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_4_DWORK1_o, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_4_DWORK1_o");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_5_DWORK1_i, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_5_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK1_m,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_2_DWORK1_m");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK1_j,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_3_DWORK1_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK1_b,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_4_DWORK1_b");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK1_l,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_5_DWORK1_l");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK1_j,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_6_DWORK1_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_1_DWORK1_i, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_1_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_3_DWORK1_i, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_3_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_6_DWORK1_h, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_6_DWORK1_h");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK1_c,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_1_DWORK1_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_2_DWORK1_dz, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_2_DWORK1_dz");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_4_DWORK1_n, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_4_DWORK1_n");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_5_DWORK1_g, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_5_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK1_h,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_2_DWORK1_h");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK1_p,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_3_DWORK1_p");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK1_bn,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_4_DWORK1_bn");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK1_p,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_5_DWORK1_p");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK1_e,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_6_DWORK1_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_switch_DW.controlinputuexceedsbounds_DWOR, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_switch_DW.controlinputuexceedsbounds_DWOR");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_switch_DW.ctrl_student_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_switch_DW.ctrl_student_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_switch_DW.ctrl_DP_basic_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_switch_DW.ctrl_DP_basic_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_switch_DW.ctrl_sixaxis2force_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_switch_DW.ctrl_sixaxis2force_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_switch_DW.ctrl_sixaxis2thruster_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_switch_DW.ctrl_sixaxis2thruster_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_5d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_5d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_1d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_1d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_2d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_2d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_3d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_3d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_4d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_4d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_6d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_6d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_1d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_1d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_2d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_2d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_3d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_3d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_4d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_4d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_5d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_5d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_6d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_6d_DWORK1");
    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.Triangle_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.Triangle_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.Circle_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.Circle_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.Cross_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.Cross_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.Square_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.Square_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_3_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_6_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_6_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_2_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_4_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_4_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_5_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_5_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_1_DWORK2_b,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_1_DWORK2_b");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_3_DWORK2_o,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_3_DWORK2_o");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_6_DWORK2_f,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_6_DWORK2_f");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK2_f,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_1_DWORK2_f");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_2_DWORK2_b,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_2_DWORK2_b");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_4_DWORK2_g,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_4_DWORK2_g");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_5_DWORK2_f,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_5_DWORK2_f");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK2_g,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_2_DWORK2_g");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK2_e,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_3_DWORK2_e");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK2_g,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_4_DWORK2_g");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK2_i,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_5_DWORK2_i");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK2_d,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_6_DWORK2_d");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_1_DWORK2_i,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_1_DWORK2_i");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_3_DWORK2_d,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_3_DWORK2_d");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_6_DWORK2_e,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_6_DWORK2_e");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK2_p,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_1_DWORK2_p");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_2_DWORK2_bf,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_2_DWORK2_bf");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_4_DWORK2_e,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_4_DWORK2_e");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_5_DWORK2_h,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_5_DWORK2_h");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK2_j,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_2_DWORK2_j");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK2_m,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_3_DWORK2_m");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK2_b,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_4_DWORK2_b");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK2_e,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_5_DWORK2_e");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK2_p,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_6_DWORK2_p");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_1_DWORK2_d,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_1_DWORK2_d");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_3_DWORK2_c,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_3_DWORK2_c");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_6_DWORK2_n,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_6_DWORK2_n");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK2_d,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_1_DWORK2_d");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_2_DWORK2_p,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_2_DWORK2_p");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_4_DWORK2_d,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_4_DWORK2_d");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_5_DWORK2_a,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_5_DWORK2_a");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK2_a,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_2_DWORK2_a");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK2_d,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_3_DWORK2_d");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK2_d,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_4_DWORK2_d");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK2_b,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_5_DWORK2_b");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK2_b,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_6_DWORK2_b");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_switch_DW.controlinputuexceedsbounds_DW_p, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_switch_DW.controlinputuexceedsbounds_DW_p");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_switch_DW.ctrl_student_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_switch_DW.ctrl_student_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_switch_DW.ctrl_DP_basic_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_switch_DW.ctrl_DP_basic_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_switch_DW.ctrl_sixaxis2force_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_switch_DW.ctrl_sixaxis2force_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_switch_DW.ctrl_sixaxis2thruster_DWORK2, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_switch_DW.ctrl_sixaxis2thruster_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_5d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_5d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_1d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_1d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_2d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_2d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_3d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_3d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_4d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_4d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.u_6d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.u_6d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_1d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_1d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_2d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_2d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_3d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_3d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_4d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_4d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_5d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_5d_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_switch_DW.alpha_6d_DWORK2,
        count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_switch_DW.alpha_6d_DWORK2");
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
    NIRT_SetValueByDataType(&ctrl_switch_DW.Triangle_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.Circle_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.Cross_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.Square_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_1_DWORK1_h, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_3_DWORK1_p, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_6_DWORK1_f, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK1_g, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_2_DWORK1_d, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_4_DWORK1_g, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_5_DWORK1_e, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK1_e, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK1_o, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK1_n, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK1_a, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK1_f, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_1_DWORK1_o, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_3_DWORK1_o, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_6_DWORK1_e, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK1_k, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_2_DWORK1_f, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_4_DWORK1_o, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_5_DWORK1_i, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK1_m, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK1_j, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK1_b, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK1_l, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK1_j, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_1_DWORK1_i, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_3_DWORK1_i, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_6_DWORK1_h, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK1_c, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_2_DWORK1_dz, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_4_DWORK1_n, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_5_DWORK1_g, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK1_h, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK1_p, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK1_bn, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK1_p, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK1_e, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.controlinputuexceedsbounds_DWOR, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.ctrl_student_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.ctrl_DP_basic_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.ctrl_sixaxis2force_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.ctrl_sixaxis2thruster_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_5d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_1d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_2d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_3d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_4d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.u_6d_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_1d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_2d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_3d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_4d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_5d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_6d_DWORK1, 0, discStates[idx++],
      0, 0);
    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.Triangle_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.Circle_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.Cross_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.Square_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_1_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_3_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_6_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_2_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_4_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_5_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_1_DWORK2_b, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_3_DWORK2_o, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_6_DWORK2_f, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK2_f, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_2_DWORK2_b, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_4_DWORK2_g, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_5_DWORK2_f, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK2_g, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK2_e, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK2_g, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK2_i, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK2_d, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_1_DWORK2_i, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_3_DWORK2_d, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_6_DWORK2_e, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK2_p, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_2_DWORK2_bf, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_4_DWORK2_e, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_5_DWORK2_h, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK2_j, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK2_m, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK2_b, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK2_e, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK2_p, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_1_DWORK2_d, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_3_DWORK2_c, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_6_DWORK2_n, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_1_DWORK2_d, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_2_DWORK2_p, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_4_DWORK2_d, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_5_DWORK2_a, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_2_DWORK2_a, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_3_DWORK2_d, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_4_DWORK2_d, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_5_DWORK2_b, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_6_DWORK2_b, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.controlinputuexceedsbounds_DW_p,
        count, discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.ctrl_student_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.ctrl_DP_basic_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.ctrl_sixaxis2force_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.ctrl_sixaxis2thruster_DWORK2,
        count, discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_5d_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_1d_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_2d_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_3d_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_4d_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.u_6d_DWORK2, count, discStates[idx
        ++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_1d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_2d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_3d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_4d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_5d_DWORK2, count,
        discStates[idx++], 18, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_switch_DW.alpha_6d_DWORK2, count,
        discStates[idx++], 18, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_switch
