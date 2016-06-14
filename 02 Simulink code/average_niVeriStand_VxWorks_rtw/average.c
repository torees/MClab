/*
 * average.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "average".
 *
 * Model version              : 1.17
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed May 11 13:11:37 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "average.h"
#include "average_private.h"

/* Block signals (auto storage) */
B_average_T average_B;

/* Block states (auto storage) */
DW_average_T average_DW;

/* Real-time model */
RT_MODEL_average_T average_M_;
RT_MODEL_average_T *const average_M = &average_M_;

/*
 * Initial conditions for atomic system:
 *    '<Root>/MATLAB Function'
 *    '<Root>/MATLAB Function1'
 *    '<Root>/MATLAB Function2'
 *    '<Root>/MATLAB Function3'
 */
void average_MATLABFunction_Init(DW_MATLABFunction_average_T *localDW)
{
  memset(&localDW->buf[0], 0, 1000U * sizeof(real_T));
  localDW->bufSum = 0.0;
  localDW->i = 1.0;
  localDW->tmp = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<Root>/MATLAB Function'
 *    '<Root>/MATLAB Function1'
 *    '<Root>/MATLAB Function2'
 *    '<Root>/MATLAB Function3'
 */
void average_MATLABFunction(real_T rtu_signal, real_T rtu_u,
  B_MATLABFunction_average_T *localB, DW_MATLABFunction_average_T *localDW)
{
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* # codegen */
  /* '<S1>:1:9' */
  localDW->bufSum -= localDW->buf[(int32_T)localDW->i - 1];

  /* '<S1>:1:10' */
  localDW->buf[(int32_T)localDW->i - 1] = rtu_u;

  /* '<S1>:1:11' */
  localDW->bufSum += rtu_u;

  /* '<S1>:1:12' */
  localDW->i++;
  if (localDW->i > 1000.0) {
    /* '<S1>:1:13' */
    /* '<S1>:1:14' */
    localDW->i = 1.0;
  }

  if (rtu_signal != 0.0) {
    /* '<S1>:1:18' */
    /* '<S1>:1:19' */
    localB->y = localDW->bufSum / 1000.0;

    /* '<S1>:1:20' */
    localDW->tmp = localB->y;
  } else {
    /* '<S1>:1:22' */
    localB->y = localDW->tmp;

    /* '<S1>:1:23' */
  }
}

/* Model output function */
static void average_output(void)
{
  /* MATLAB Function: '<Root>/MATLAB Function' */
  average_MATLABFunction(average_B.signal, average_B.F_BB_in,
    &average_B.sf_MATLABFunction, &average_DW.sf_MATLABFunction);

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  average_MATLABFunction(average_B.signal, average_B.F_FB_in,
    &average_B.sf_MATLABFunction2, &average_DW.sf_MATLABFunction2);

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  average_MATLABFunction(average_B.signal, average_B.F_BS_in,
    &average_B.sf_MATLABFunction1, &average_DW.sf_MATLABFunction1);

  /* MATLAB Function: '<Root>/MATLAB Function3' */
  average_MATLABFunction(average_B.signal, average_B.F_FS_in,
    &average_B.sf_MATLABFunction3, &average_DW.sf_MATLABFunction3);
}

/* Model update function */
static void average_update(void)
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
  if (!(++average_M->Timing.clockTick0)) {
    ++average_M->Timing.clockTickH0;
  }

  average_M->Timing.t[0] = average_M->Timing.clockTick0 *
    average_M->Timing.stepSize0 + average_M->Timing.clockTickH0 *
    average_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void average_initialize(void)
{
  /* InitializeConditions for MATLAB Function: '<Root>/MATLAB Function' */
  average_MATLABFunction_Init(&average_DW.sf_MATLABFunction);

  /* InitializeConditions for MATLAB Function: '<Root>/MATLAB Function2' */
  average_MATLABFunction_Init(&average_DW.sf_MATLABFunction2);

  /* InitializeConditions for MATLAB Function: '<Root>/MATLAB Function1' */
  average_MATLABFunction_Init(&average_DW.sf_MATLABFunction1);

  /* InitializeConditions for MATLAB Function: '<Root>/MATLAB Function3' */
  average_MATLABFunction_Init(&average_DW.sf_MATLABFunction3);
}

/* Model terminate function */
static void average_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  average_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  average_update();
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
  average_initialize();
}

void MdlTerminate(void)
{
  average_terminate();
}

/* Registration function */
RT_MODEL_average_T *average(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)average_M, 0,
                sizeof(RT_MODEL_average_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = average_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    average_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    average_M->Timing.sampleTimes = (&average_M->Timing.sampleTimesArray[0]);
    average_M->Timing.offsetTimes = (&average_M->Timing.offsetTimesArray[0]);

    /* task periods */
    average_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    average_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(average_M, &average_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = average_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    average_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(average_M, -1);
  average_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    average_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(average_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(average_M->rtwLogInfo, (NULL));
    rtliSetLogT(average_M->rtwLogInfo, "tout");
    rtliSetLogX(average_M->rtwLogInfo, "");
    rtliSetLogXFinal(average_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(average_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(average_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(average_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(average_M->rtwLogInfo, 1);
    rtliSetLogY(average_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(average_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(average_M->rtwLogInfo, (NULL));
  }

  average_M->solverInfoPtr = (&average_M->solverInfo);
  average_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&average_M->solverInfo, 0.01);
  rtsiSetSolverMode(&average_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  average_M->ModelData.blockIO = ((void *) &average_B);
  (void) memset(((void *) &average_B), 0,
                sizeof(B_average_T));

  /* parameters */
  average_M->ModelData.defaultParam = ((real_T *)&average_P);

  /* states (dwork) */
  average_M->ModelData.dwork = ((void *) &average_DW);
  (void) memset((void *)&average_DW, 0,
                sizeof(DW_average_T));

  /* Initialize Sizes */
  average_M->Sizes.numContStates = (0);/* Number of continuous states */
  average_M->Sizes.numY = (0);         /* Number of model outputs */
  average_M->Sizes.numU = (0);         /* Number of model inputs */
  average_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  average_M->Sizes.numSampTimes = (1); /* Number of sample times */
  average_M->Sizes.numBlocks = (14);   /* Number of blocks */
  average_M->Sizes.numBlockIO = (9);   /* Number of block outputs */
  average_M->Sizes.numBlockPrms = (54);/* Sum of parameter "widths" */
  return average_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : average
 * Model version : 1.17
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Wed May 11 13:11:37 2016
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_average
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

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

extern average_rtModel *S;
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

  // average/signal
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&average_B.signal, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // average/F_BB_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&average_B.F_BB_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // average/F_FB_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&average_B.F_FB_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // average/F_BS_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&average_B.F_BS_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // average/F_FS_in
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&average_B.F_FS_in, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 5;
}

int32_t NumOutputPorts(void)
{
  return 4;
}

double ni_extout[4];

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

  // average/F_BB_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&average_B.sf_MATLABFunction.y,
      0, 0, 0);
  } else {
    index += 1;
  }

  // average/F_FB_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&average_B.sf_MATLABFunction2.y,
      0, 0, 0);
  } else {
    index += 1;
  }

  // average/F_BS_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&average_B.sf_MATLABFunction1.y,
      0, 0, 0);
  } else {
    index += 1;
  }

  // average/F_FS_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&average_B.sf_MATLABFunction3.y,
      0, 0, 0);
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

  // average/F_BB_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&average_B.sf_MATLABFunction.y, 0,
    0, 0);

  // average/F_FB_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&average_B.sf_MATLABFunction2.y,
    0, 0, 0);

  // average/F_BS_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&average_B.sf_MATLABFunction1.y,
    0, 0, 0);

  // average/F_FS_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&average_B.sf_MATLABFunction3.y,
    0, 0, 0);
  UNUSED_PARAMETER(count);
  return NI_OK;
}

/* All elements by default (including scalars) have 2 dimensions [1,1] */
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "", 0, 0, 0, 0, 0, 0 }
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 0;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  0
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "average/signal", 0, "", offsetof(B_average_T, signal) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "average/F_BB_in", 0, "", offsetof(B_average_T, F_BB_in) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "average/F_FB_in", 0, "", offsetof(B_average_T, F_FB_in) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "average/F_BS_in", 0, "", offsetof(B_average_T, F_BS_in) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "average/F_FS_in", 0, "", offsetof(B_average_T, F_FS_in) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "average/MATLAB Function3", 0, "", offsetof(B_average_T,
    sf_MATLABFunction3.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "average/MATLAB Function2", 0, "", offsetof(B_average_T,
    sf_MATLABFunction2.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "average/MATLAB Function1", 0, "", offsetof(B_average_T,
    sf_MATLABFunction1.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "average/MATLAB Function", 0, "", offsetof(B_average_T,
    sf_MATLABFunction.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 9;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 9;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "signal", 0, EXT_IN, 1, 1, 1 },

  { 2, "F_BB_in", 0, EXT_IN, 1, 1, 1 },

  { 3, "F_FB_in", 0, EXT_IN, 1, 1, 1 },

  { 4, "F_BS_in", 0, EXT_IN, 1, 1, 1 },

  { 5, "F_FS_in", 0, EXT_IN, 1, 1, 1 },

  { 1, "F_BB_out", 0, EXT_OUT, 1, 1, 1 },

  { 2, "F_FB_out", 0, EXT_OUT, 1, 1, 1 },

  { 3, "F_BS_out", 0, EXT_OUT, 1, 1, 1 },

  { 4, "F_FS_out", 0, EXT_OUT, 1, 1, 1 },

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
  "average";
static const char* NI_CompiledModelVersion = "1.17";
static const char* NI_CompiledModelDateTime = "Wed May 11 13:11:37 2016";
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

int32_t NI_InitParamDoubleBuf(void)
{
  return NI_OK;
}

int32_t NI_InitializeParamStruct(void)
{
  return NI_OK;
}

DLL_EXPORT int32_t NIRT_SetParameter(int32_t index, int32_t subindex, double
  value)
{
  return NI_ERROR;
}

DLL_EXPORT int32_t NIRT_GetParameter(int32_t index, int32_t subindex, double
  *value)
{
  return NI_ERROR;
}

DLL_EXPORT int32_t NIRT_GetVectorParameter(uint32_t index, double* paramvalues,
  uint32_t paramlength)
{
  return NI_ERROR;
}

DLL_EXPORT int32_t NIRT_SetVectorParameter(uint32_t index, const double
  * paramvalues, uint32_t paramlength)
{
  return NI_ERROR;
}

DLL_EXPORT int32_t NIRT_SetScalarParameterInline(uint32_t index, uint32_t
  subindex, double paramvalue)
{
  return NI_ERROR;
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
      *numDiscStates = 4093;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.signal_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.signal_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_BB_in_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_BB_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_BB_out_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_BB_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_FB_in_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_FB_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_FB_out_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_FB_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_BS_in_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_BS_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_BS_out_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_BS_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_FS_in_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_FS_in_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_FS_out_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_FS_out_DWORK1");
    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&average_DW.signal_DWORK2, count,
        17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&average_DW.signal_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_BB_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_BB_in_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_BB_out_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_BB_out_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_FB_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_FB_in_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_FB_out_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_FB_out_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_BS_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_BS_in_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_BS_out_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_BS_out_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_FS_in_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_FS_in_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&average_DW.F_FS_out_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&average_DW.F_FS_out_DWORK2");
    }

    discStates[idx] = NIRT_GetValueByDataType(&average_DW.sf_MATLABFunction3.i,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.sf_MATLABFunction3.i");
    for (count = 0; count < 1000; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&average_DW.sf_MATLABFunction3.buf, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&average_DW.sf_MATLABFunction3.buf");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&average_DW.sf_MATLABFunction3.bufSum, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&average_DW.sf_MATLABFunction3.bufSum");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.sf_MATLABFunction3.tmp,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.sf_MATLABFunction3.tmp");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.sf_MATLABFunction2.i,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.sf_MATLABFunction2.i");
    for (count = 0; count < 1000; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&average_DW.sf_MATLABFunction2.buf, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&average_DW.sf_MATLABFunction2.buf");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&average_DW.sf_MATLABFunction2.bufSum, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&average_DW.sf_MATLABFunction2.bufSum");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.sf_MATLABFunction2.tmp,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.sf_MATLABFunction2.tmp");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.sf_MATLABFunction1.i,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.sf_MATLABFunction1.i");
    for (count = 0; count < 1000; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&average_DW.sf_MATLABFunction1.buf, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&average_DW.sf_MATLABFunction1.buf");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&average_DW.sf_MATLABFunction1.bufSum, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&average_DW.sf_MATLABFunction1.bufSum");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.sf_MATLABFunction1.tmp,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.sf_MATLABFunction1.tmp");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.sf_MATLABFunction.i, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.sf_MATLABFunction.i");
    for (count = 0; count < 1000; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&average_DW.sf_MATLABFunction.buf, count, 18, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&average_DW.sf_MATLABFunction.buf");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&average_DW.sf_MATLABFunction.bufSum, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&average_DW.sf_MATLABFunction.bufSum");
    discStates[idx] = NIRT_GetValueByDataType(&average_DW.sf_MATLABFunction.tmp,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&average_DW.sf_MATLABFunction.tmp");
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
    NIRT_SetValueByDataType(&average_DW.signal_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&average_DW.F_BB_in_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&average_DW.F_BB_out_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&average_DW.F_FB_in_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&average_DW.F_FB_out_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&average_DW.F_BS_in_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&average_DW.F_BS_out_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&average_DW.F_FS_in_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&average_DW.F_FS_out_DWORK1, 0, discStates[idx++], 0,
      0);
    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&average_DW.signal_DWORK2, count, discStates[idx++],
        17, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&average_DW.F_BB_in_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&average_DW.F_BB_out_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&average_DW.F_FB_in_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&average_DW.F_FB_out_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&average_DW.F_BS_in_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&average_DW.F_BS_out_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&average_DW.F_FS_in_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&average_DW.F_FS_out_DWORK2, count, discStates[idx
        ++], 17, 0);
    }

    NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction3.i, 0, discStates[idx
      ++], 0, 0);
    for (count = 0; count < 1000; count++) {
      NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction3.buf, count,
        discStates[idx++], 18, 0);
    }

    NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction3.bufSum, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction3.tmp, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction2.i, 0, discStates[idx
      ++], 0, 0);
    for (count = 0; count < 1000; count++) {
      NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction2.buf, count,
        discStates[idx++], 18, 0);
    }

    NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction2.bufSum, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction2.tmp, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction1.i, 0, discStates[idx
      ++], 0, 0);
    for (count = 0; count < 1000; count++) {
      NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction1.buf, count,
        discStates[idx++], 18, 0);
    }

    NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction1.bufSum, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction1.tmp, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction.i, 0, discStates[idx++],
      0, 0);
    for (count = 0; count < 1000; count++) {
      NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction.buf, count,
        discStates[idx++], 18, 0);
    }

    NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction.bufSum, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&average_DW.sf_MATLABFunction.tmp, 0, discStates[idx
      ++], 0, 0);
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_average
