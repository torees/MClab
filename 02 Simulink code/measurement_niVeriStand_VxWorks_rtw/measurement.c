/*
 * measurement.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "measurement".
 *
 * Model version              : 1.10
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue May 03 13:46:20 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "measurement.h"
#include "measurement_private.h"

/* Block signals (auto storage) */
B_measurement_T measurement_B;

/* Block states (auto storage) */
DW_measurement_T measurement_DW;

/* Real-time model */
RT_MODEL_measurement_T measurement_M_;
RT_MODEL_measurement_T *const measurement_M = &measurement_M_;
real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model output function */
static void measurement_output(void)
{
  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Step size'
   *  Memory: '<S1>/counter'
   */
  /* MATLAB Function 'Downsample	signal/MATLAB Function': '<S6>:1' */
  /* '<S6>:1:3' */
  if ((measurement_DW.counter_PreviousInput + 1.0) *
      measurement_P.Stepsize_Value >= 1.0 / measurement_B.Samplingfrequency) {
    /* '<S6>:1:4' */
    /* '<S6>:1:5' */
    measurement_B.count = 0.0;
  } else {
    /* '<S6>:1:7' */
    measurement_B.count = measurement_DW.counter_PreviousInput + 1.0;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Step size'
   *  Memory: '<S2>/Hold'
   *  Product: '<S10>/Divide'
   *  Product: '<S10>/Product'
   *  Product: '<S8>/Divide'
   *  Product: '<S8>/Product'
   *  Product: '<S9>/Divide'
   *  Product: '<S9>/Product'
   *  RandomNumber: '<S10>/White Noise'
   *  RandomNumber: '<S8>/White Noise'
   *  RandomNumber: '<S9>/White Noise'
   *  Sqrt: '<S10>/Sqrt'
   *  Sqrt: '<S8>/Sqrt'
   *  Sqrt: '<S9>/Sqrt'
   *  Sum: '<Root>/Sum'
   */
  /* MATLAB Function 'Sample & hold/MATLAB Function1': '<S7>:1' */
  if (measurement_B.count == 0.0) {
    /* '<S7>:1:4' */
    /* '<S7>:1:5' */
    measurement_B.output[0] = sqrt(measurement_B.Noisepowerposition /
      measurement_P.Stepsize_Value) * measurement_DW.NextOutput +
      measurement_B.x;
    measurement_B.output[1] = sqrt(measurement_B.Noisepowerposition /
      measurement_P.Stepsize_Value) * measurement_DW.NextOutput_n +
      measurement_B.y;
    measurement_B.output[2] = sqrt(measurement_B.Noisepowerheading /
      measurement_P.Stepsize_Value) * measurement_DW.NextOutput_c +
      measurement_B.psi;
  } else {
    /* '<S7>:1:7' */
    measurement_B.output[0] = measurement_DW.Hold_PreviousInput[0];
    measurement_B.output[1] = measurement_DW.Hold_PreviousInput[1];
    measurement_B.output[2] = measurement_DW.Hold_PreviousInput[2];
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function1' */

  /* Switch: '<Root>/Switch' */
  if (measurement_B.enable != 0.0) {
    measurement_B.Switch[0] = measurement_B.output[0];
    measurement_B.Switch[1] = measurement_B.output[1];
    measurement_B.Switch[2] = measurement_B.output[2];
  } else {
    measurement_B.Switch[0] = measurement_B.x;
    measurement_B.Switch[1] = measurement_B.y;
    measurement_B.Switch[2] = measurement_B.psi;
  }

  /* End of Switch: '<Root>/Switch' */
}

/* Model update function */
static void measurement_update(void)
{
  /* Update for Memory: '<S1>/counter' */
  measurement_DW.counter_PreviousInput = measurement_B.count;

  /* Update for RandomNumber: '<S9>/White Noise' */
  measurement_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&measurement_DW.RandSeed) * measurement_P.WhiteNoise_StdDev +
    measurement_P.WhiteNoise_Mean;

  /* Update for RandomNumber: '<S10>/White Noise' */
  measurement_DW.NextOutput_n = rt_nrand_Upu32_Yd_f_pw_snf
    (&measurement_DW.RandSeed_c) * measurement_P.WhiteNoise_StdDev_k +
    measurement_P.WhiteNoise_Mean_a;

  /* Update for RandomNumber: '<S8>/White Noise' */
  measurement_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
    (&measurement_DW.RandSeed_g) * measurement_P.WhiteNoise_StdDev_ko +
    measurement_P.WhiteNoise_Mean_n;

  /* Update for Memory: '<S2>/Hold' */
  measurement_DW.Hold_PreviousInput[0] = measurement_B.output[0];
  measurement_DW.Hold_PreviousInput[1] = measurement_B.output[1];
  measurement_DW.Hold_PreviousInput[2] = measurement_B.output[2];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++measurement_M->Timing.clockTick0)) {
    ++measurement_M->Timing.clockTickH0;
  }

  measurement_M->Timing.t[0] = measurement_M->Timing.clockTick0 *
    measurement_M->Timing.stepSize0 + measurement_M->Timing.clockTickH0 *
    measurement_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void measurement_initialize(void)
{
  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Memory: '<S1>/counter' */
    measurement_DW.counter_PreviousInput = measurement_P.counter_X0;

    /* InitializeConditions for RandomNumber: '<S9>/White Noise' */
    tmp = floor(measurement_P.WhiteNoise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    measurement_DW.RandSeed = tseed;
    measurement_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&measurement_DW.RandSeed) * measurement_P.WhiteNoise_StdDev +
      measurement_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S9>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S10>/White Noise' */
    tmp = floor(measurement_P.WhiteNoise_Seed_k);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    measurement_DW.RandSeed_c = tseed;
    measurement_DW.NextOutput_n = rt_nrand_Upu32_Yd_f_pw_snf
      (&measurement_DW.RandSeed_c) * measurement_P.WhiteNoise_StdDev_k +
      measurement_P.WhiteNoise_Mean_a;

    /* End of InitializeConditions for RandomNumber: '<S10>/White Noise' */

    /* InitializeConditions for RandomNumber: '<S8>/White Noise' */
    tmp = floor(measurement_P.WhiteNoise_Seed_j);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    measurement_DW.RandSeed_g = tseed;
    measurement_DW.NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf
      (&measurement_DW.RandSeed_g) * measurement_P.WhiteNoise_StdDev_ko +
      measurement_P.WhiteNoise_Mean_n;

    /* End of InitializeConditions for RandomNumber: '<S8>/White Noise' */

    /* InitializeConditions for Memory: '<S2>/Hold' */
    measurement_DW.Hold_PreviousInput[0] = measurement_P.Hold_X0;
    measurement_DW.Hold_PreviousInput[1] = measurement_P.Hold_X0;
    measurement_DW.Hold_PreviousInput[2] = measurement_P.Hold_X0;
  }
}

/* Model terminate function */
static void measurement_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  measurement_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  measurement_update();
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
  measurement_initialize();
}

void MdlTerminate(void)
{
  measurement_terminate();
}

/* Registration function */
RT_MODEL_measurement_T *measurement(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)measurement_M, 0,
                sizeof(RT_MODEL_measurement_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = measurement_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    measurement_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    measurement_M->Timing.sampleTimes = (&measurement_M->
      Timing.sampleTimesArray[0]);
    measurement_M->Timing.offsetTimes = (&measurement_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    measurement_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    measurement_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(measurement_M, &measurement_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = measurement_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    measurement_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(measurement_M, -1);
  measurement_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    measurement_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(measurement_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(measurement_M->rtwLogInfo, (NULL));
    rtliSetLogT(measurement_M->rtwLogInfo, "tout");
    rtliSetLogX(measurement_M->rtwLogInfo, "");
    rtliSetLogXFinal(measurement_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(measurement_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(measurement_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(measurement_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(measurement_M->rtwLogInfo, 1);
    rtliSetLogY(measurement_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(measurement_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(measurement_M->rtwLogInfo, (NULL));
  }

  measurement_M->solverInfoPtr = (&measurement_M->solverInfo);
  measurement_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&measurement_M->solverInfo, 0.01);
  rtsiSetSolverMode(&measurement_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  measurement_M->ModelData.blockIO = ((void *) &measurement_B);
  (void) memset(((void *) &measurement_B), 0,
                sizeof(B_measurement_T));

  /* parameters */
  measurement_M->ModelData.defaultParam = ((real_T *)&measurement_P);

  /* states (dwork) */
  measurement_M->ModelData.dwork = ((void *) &measurement_DW);
  (void) memset((void *)&measurement_DW, 0,
                sizeof(DW_measurement_T));

  /* Initialize Sizes */
  measurement_M->Sizes.numContStates = (0);/* Number of continuous states */
  measurement_M->Sizes.numY = (0);     /* Number of model outputs */
  measurement_M->Sizes.numU = (0);     /* Number of model inputs */
  measurement_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  measurement_M->Sizes.numSampTimes = (1);/* Number of sample times */
  measurement_M->Sizes.numBlocks = (31);/* Number of blocks */
  measurement_M->Sizes.numBlockIO = (10);/* Number of block outputs */
  measurement_M->Sizes.numBlockPrms = (72);/* Sum of parameter "widths" */
  return measurement_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : measurement
 * Model version : 1.10
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Tue May 03 13:46:20 2016
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_measurement
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

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
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

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern measurement_rtModel *S;
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

  // measurement/Noise power position
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.Noisepowerposition, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // measurement/Sampling frequency
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.Samplingfrequency, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // measurement/Noise power heading
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.Noisepowerheading, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // measurement/pose/x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // measurement/pose/psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // measurement/pose/y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // measurement/enable
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&measurement_B.enable, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 7;
}

int32_t NumOutputPorts(void)
{
  return 3;
}

double ni_extout[3];

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

  // measurement/pose measured/x_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&measurement_B.Switch, 0, 18, 0);
  } else {
    index += 1;
  }

  // measurement/pose measured/y_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&measurement_B.Switch, 1, 18, 0);
  } else {
    index += 1;
  }

  // measurement/pose measured/psi_m: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&measurement_B.Switch, 2, 18, 0);
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

  // measurement/pose measured/x_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&measurement_B.Switch, 0, 18, 0);

  // measurement/pose measured/y_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&measurement_B.Switch, 1, 18, 0);

  // measurement/pose measured/psi_m: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&measurement_B.Switch, 2, 18, 0);
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
  { 0, "measurement/Downsamplesignal/counter/X0", offsetof(P_measurement_T,
    counter_X0), 23, 1, 2, 0, 0 },

  { 1, "measurement/Step size/Value", offsetof(P_measurement_T, Stepsize_Value),
    23, 1, 2, 2, 0 },

  { 2, "measurement/noise generator/Band-limited white noise x/White Noise/Mean",
    offsetof(P_measurement_T, WhiteNoise_Mean), 23, 1, 2, 4, 0 },

  { 3,
    "measurement/noise generator/Band-limited white noise x/White Noise/StdDev",
    offsetof(P_measurement_T, WhiteNoise_StdDev), 23, 1, 2, 6, 0 },

  { 4, "measurement/noise generator/Band-limited white noise x/White Noise/Seed",
    offsetof(P_measurement_T, WhiteNoise_Seed), 23, 1, 2, 8, 0 },

  { 5, "measurement/noise generator/Band-limited white noise y/White Noise/Mean",
    offsetof(P_measurement_T, WhiteNoise_Mean_a), 23, 1, 2, 10, 0 },

  { 6,
    "measurement/noise generator/Band-limited white noise y/White Noise/StdDev",
    offsetof(P_measurement_T, WhiteNoise_StdDev_k), 23, 1, 2, 12, 0 },

  { 7, "measurement/noise generator/Band-limited white noise y/White Noise/Seed",
    offsetof(P_measurement_T, WhiteNoise_Seed_k), 23, 1, 2, 14, 0 },

  { 8,
    "measurement/noise generator/Band-limited white noise psi/White Noise/Mean",
    offsetof(P_measurement_T, WhiteNoise_Mean_n), 23, 1, 2, 16, 0 },

  { 9,
    "measurement/noise generator/Band-limited white noise psi/White Noise/StdDev",
    offsetof(P_measurement_T, WhiteNoise_StdDev_ko), 23, 1, 2, 18, 0 },

  { 10,
    "measurement/noise generator/Band-limited white noise psi/White Noise/Seed",
    offsetof(P_measurement_T, WhiteNoise_Seed_j), 23, 1, 2, 20, 0 },

  { 11, "measurement/Sample & hold/Hold/X0", offsetof(P_measurement_T, Hold_X0),
    23, 1, 2, 22, 0 },
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
  { 0, "measurement/Noise power position", 0, "", offsetof(B_measurement_T,
    Noisepowerposition) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "measurement/Sampling frequency", 0, "", offsetof(B_measurement_T,
    Samplingfrequency) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "measurement/Noise power heading", 0, "", offsetof(B_measurement_T,
    Noisepowerheading) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "measurement/pose/x", 0, "", offsetof(B_measurement_T, x) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "measurement/pose/psi", 0, "", offsetof(B_measurement_T, psi) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "measurement/pose/y", 0, "", offsetof(B_measurement_T, y) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "measurement/enable", 0, "", offsetof(B_measurement_T, enable) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "measurement/Switch/(1, 1)", 0, "", offsetof(B_measurement_T, Switch) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 8, "measurement/Switch/(1, 2)", 0, "", offsetof(B_measurement_T, Switch) +
    (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 9, "measurement/Switch/(1, 3)", 0, "", offsetof(B_measurement_T, Switch) +
    (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 10, "measurement/Sample & hold/MATLAB Function1", 0, "(1, 1)", offsetof
    (B_measurement_T, output) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 11, "measurement/Sample & hold/MATLAB Function1", 0, "(1, 2)", offsetof
    (B_measurement_T, output) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 12, "measurement/Sample & hold/MATLAB Function1", 0, "(1, 3)", offsetof
    (B_measurement_T, output) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2, 0, 0
  },

  { 13, "measurement/Downsamplesignal/MATLAB Function", 0, "", offsetof
    (B_measurement_T, count) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 14;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 10;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Noise power position", 0, EXT_IN, 1, 1, 1 },

  { 2, "Sampling frequency", 0, EXT_IN, 1, 1, 1 },

  { 3, "Noise power heading", 0, EXT_IN, 1, 1, 1 },

  { 4, "pose/x", 0, EXT_IN, 1, 1, 1 },

  { 5, "pose/psi", 0, EXT_IN, 1, 1, 1 },

  { 6, "pose/y", 0, EXT_IN, 1, 1, 1 },

  { 7, "enable", 0, EXT_IN, 1, 1, 1 },

  { 1, "pose measured/x_m", 0, EXT_OUT, 1, 1, 1 },

  { 2, "pose measured/y_m", 0, EXT_OUT, 1, 1, 1 },

  { 3, "pose measured/psi_m", 0, EXT_OUT, 1, 1, 1 },

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
  "measurement";
static const char* NI_CompiledModelVersion = "1.10";
static const char* NI_CompiledModelDateTime = "Tue May 03 13:46:20 2016";
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
  memcpy(&rtParameter[0], &measurement_P, sizeof(P_measurement_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka measurement_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_measurement_T));
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
             (P_measurement_T));
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
               (P_measurement_T));
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
             (P_measurement_T));
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
           (P_measurement_T));
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
           (P_measurement_T));
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
      *numDiscStates = 140;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&measurement_DW.Noisepowerposition_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&measurement_DW.Noisepowerposition_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&measurement_DW.Samplingfrequency_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&measurement_DW.Samplingfrequency_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&measurement_DW.Noisepowerheading_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&measurement_DW.Noisepowerheading_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&measurement_DW.counter_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&measurement_DW.counter_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.NextOutput, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.NextOutput");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.NextOutput_n, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.NextOutput_n");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.NextOutput_c, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.NextOutput_c");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.Hold_PreviousInput,
      0, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.Hold_PreviousInput,
      1, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.Hold_PreviousInput,
      2, 18, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.Hold_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.enable_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.enable_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.x_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.y_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.psi_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.RandSeed, 0, 7, 0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.RandSeed");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.RandSeed_c, 0, 7,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.RandSeed_c");
    discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.RandSeed_g, 0, 7,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.RandSeed_g");
    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&measurement_DW.Noisepowerposition_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&measurement_DW.Noisepowerposition_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&measurement_DW.Samplingfrequency_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&measurement_DW.Samplingfrequency_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&measurement_DW.Noisepowerheading_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&measurement_DW.Noisepowerheading_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.x_DWORK2, count,
        17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.x_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.psi_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.psi_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.y_DWORK2, count,
        17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.y_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.enable_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.enable_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.x_m_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.x_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.y_m_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.y_m_DWORK2");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&measurement_DW.psi_m_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&measurement_DW.psi_m_DWORK2");
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
    NIRT_SetValueByDataType(&measurement_DW.Noisepowerposition_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&measurement_DW.Samplingfrequency_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&measurement_DW.Noisepowerheading_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&measurement_DW.counter_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&measurement_DW.NextOutput, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&measurement_DW.NextOutput_n, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&measurement_DW.NextOutput_c, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&measurement_DW.x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&measurement_DW.psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&measurement_DW.y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&measurement_DW.Hold_PreviousInput, 0,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&measurement_DW.Hold_PreviousInput, 1,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&measurement_DW.Hold_PreviousInput, 2,
      discStates[idx++], 18, 0);
    NIRT_SetValueByDataType(&measurement_DW.enable_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&measurement_DW.x_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&measurement_DW.y_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&measurement_DW.psi_m_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&measurement_DW.RandSeed, 0, discStates[idx++], 7, 0);
    NIRT_SetValueByDataType(&measurement_DW.RandSeed_c, 0, discStates[idx++], 7,
      0);
    NIRT_SetValueByDataType(&measurement_DW.RandSeed_g, 0, discStates[idx++], 7,
      0);
    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.Noisepowerposition_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.Samplingfrequency_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.Noisepowerheading_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.x_DWORK2, count, discStates[idx++],
        17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.psi_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.y_DWORK2, count, discStates[idx++],
        17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.enable_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.x_m_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.y_m_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&measurement_DW.psi_m_DWORK2, count,
        discStates[idx++], 17, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_measurement
