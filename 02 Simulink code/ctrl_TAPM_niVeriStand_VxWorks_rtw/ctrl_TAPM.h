/*
 * ctrl_TAPM.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_TAPM".
 *
 * Model version              : 1.190
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Apr 20 19:54:34 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_TAPM_h_
#define RTW_HEADER_ctrl_TAPM_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#include <string.h>
#ifndef ctrl_TAPM_COMMON_INCLUDES_
# define ctrl_TAPM_COMMON_INCLUDES_
#include <stdio.h>
#include <string.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_TAPM_COMMON_INCLUDES_ */

#include "ctrl_TAPM_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define ctrl_TAPM_rtModel              RT_MODEL_ctrl_TAPM_T

/* Block signals for system '<S44>/Kd' */
typedef struct {
  real_T K_d[9];                       /* '<S44>/Kd' */
} B_Kd_ctrl_TAPM_T;

/* Block signals for system '<S44>/Ki' */
typedef struct {
  real_T K_i[9];                       /* '<S44>/Ki' */
} B_Ki_ctrl_TAPM_T;

/* Block signals for system '<S44>/Kp' */
typedef struct {
  real_T K_p[9];                       /* '<S44>/Kp' */
} B_Kp_ctrl_TAPM_T;

/* Block signals for system '<S67>/CoreSubsys' */
typedef struct {
  real_T angle;                        /* '<S67>/Discrete-Time Integrator' */
  real_T Delay;                        /* '<S67>/Delay' */
  real_T MaxRotationRate;              /* '<S67>/Max Rotation Rate' */
} B_CoreSubsys_ctrl_TAPM_T;

/* Block states (auto storage) for system '<S67>/CoreSubsys' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S67>/Discrete-Time Integrator' */
  real_T Delay_DSTATE;                 /* '<S67>/Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S67>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S67>/Discrete-Time Integrator' */
} DW_CoreSubsys_ctrl_TAPM_T;

/* Block signals for system '<S74>/MATLAB Function2' */
typedef struct {
  real_T Tc_out;                       /* '<S74>/MATLAB Function2' */
} B_MATLABFunction2_ctrl_TAPM_T;

/* Block signals for system '<S92>/Core controller: Torque,Power and Combined Torque//Power' */
typedef struct {
  real_T Qcq;                          /* '<S92>/Core controller: Torque,Power and Combined Torque//Power' */
  real_T Qcp;                          /* '<S92>/Core controller: Torque,Power and Combined Torque//Power' */
  real_T Qcc;                          /* '<S92>/Core controller: Torque,Power and Combined Torque//Power' */
} B_CorecontrollerTorquePoweran_T;

/* Block signals for system '<S90>/Supervisor' */
typedef struct {
  real_T u;                            /* '<S90>/Supervisor' */
} B_Supervisor_ctrl_TAPM_T;

/* Block signals for system '<S97>/Actual Force and Torque' */
typedef struct {
  real_T Ta;                           /* '<S97>/Actual Force and Torque' */
  real_T Qa;                           /* '<S97>/Actual Force and Torque' */
} B_ActualForceandTorque_ctrl_T_T;

/* Block signals for system '<S99>/MATLAB Function' */
typedef struct {
  real_T n_d;                          /* '<S99>/MATLAB Function' */
  real_T T_r;                          /* '<S99>/MATLAB Function' */
} B_MATLABFunction_ctrl_TAPM_T;

/* Block signals (auto storage) */
typedef struct {
  real_T K_p_x;                        /* '<S44>/K_p_x' */
  real_T K_p_y;                        /* '<S44>/K_p_y' */
  real_T K_p_psi;                      /* '<S44>/K_p_psi' */
  real_T K_i_psi;                      /* '<S44>/K_i_psi' */
  real_T K_i_x;                        /* '<S44>/K_i_x' */
  real_T K_i_y;                        /* '<S44>/K_i_y' */
  real_T K_d_psi;                      /* '<S44>/K_d_psi' */
  real_T K_d_x;                        /* '<S44>/K_d_x' */
  real_T K_d_y;                        /* '<S44>/K_d_y' */
  real_T x_m;                          /* '<S8>/x_m' */
  real_T y_m;                          /* '<S8>/y_m' */
  real_T psi_m;                        /* '<S8>/psi_m' */
  real_T reset;                        /* '<S5>/reset' */
  real_T w_d_x;                        /* '<S45>/w_d_x' */
  real_T w_d_y;                        /* '<S45>/w_d_y' */
  real_T w_d_psi;                      /* '<S45>/w_d_psi' */
  real_T zeta_psi;                     /* '<S45>/zeta_psi' */
  real_T zeta_x;                       /* '<S45>/zeta_x' */
  real_T zeta_y;                       /* '<S45>/zeta_y' */
  real_T psi_ref;                      /* '<S5>/psi_ref' */
  real_T x_ref;                        /* '<S5>/x_ref' */
  real_T y_ref;                        /* '<S5>/y_ref' */
  real_T TmpSignalConversionAtMatrixMult[3];
  real_T regulationerror[3];           /* '<S14>/Sum2' */
  real_T TmpSignalConversionAtMatrixMu_m[3];/* '<S14>/Transposed rotation  matrix in yaw1' */
  real_T Integrator1[3];               /* '<S6>/Integrator1' */
  real_T Integrator3[3];               /* '<S19>/Integrator3' */
  real_T thr_angle_1;                  /* '<S13>/thr_angle_1' */
  real_T thr_angle_2;                  /* '<S13>/thr_angle_2' */
  real_T thr_angle_3;                  /* '<S13>/thr_angle_3' */
  real_T thr_angle_4;                  /* '<S13>/thr_angle_4' */
  real_T thr_angle_5;                  /* '<S13>/thr_angle_5' */
  real_T thr_angle_6;                  /* '<S13>/thr_angle_6' */
  real_T reset_g[6];                   /* '<S10>/reset' */
  real_T Angle_controller;             /* '<S10>/Angle_controller' */
  real_T ChoosingFixedAzimuthangle[6]; /* '<S10>/Choosing Fixed // Azimuth angle' */
  real_T Saturation1;                  /* '<S73>/Saturation 1' */
  real_T reset_o;                      /* '<S89>/reset' */
  real_T reset_c;                      /* '<S98>/reset' */
  real_T reset_j;                      /* '<S107>/reset' */
  real_T reset_p;                      /* '<S116>/reset' */
  real_T reset_k;                      /* '<S125>/reset' */
  real_T reset_i;                      /* '<S134>/reset' */
  real_T rpm1;                         /* '<S74>/rpm1 ' */
  real_T rpm2;                         /* '<S74>/rpm2' */
  real_T rpm3;                         /* '<S74>/rpm3' */
  real_T rpm4;                         /* '<S74>/rpm4' */
  real_T rpm5;                         /* '<S74>/rpm5' */
  real_T rpm6;                         /* '<S74>/rpm6' */
  real_T Saturation2;                  /* '<S73>/Saturation 2' */
  real_T Saturation3;                  /* '<S73>/Saturation 3' */
  real_T Saturation4;                  /* '<S73>/Saturation 4' */
  real_T Saturation5;                  /* '<S73>/Saturation 5' */
  real_T Saturation6;                  /* '<S73>/Saturation 6' */
  real_T Saturation7[6];               /* '<S74>/Saturation 7' */
  real_T Integrator[3];                /* '<S6>/Integrator' */
  real_T Sum;                          /* '<S60>/Sum' */
  real_T Integrator2[3];               /* '<S6>/Integrator2' */
  real_T M1[3];                        /* '<S6>/M^-1' */
  real_T Gain[6];                      /* '<S9>/Gain' */
  real_T MatrixMultiply[3];            /* '<S19>/Matrix Multiply' */
  real_T Sum5[3];                      /* '<S19>/Sum5' */
  real_T MatrixMultiply1[3];           /* '<S6>/Matrix Multiply1' */
  real_T Sum1[3];                      /* '<S6>/Sum1' */
  real_T X_oqus;                       /* '<S8>/X_oqus' */
  real_T Y_oqus;                       /* '<S8>/Y_oqus' */
  real_T Z_oqus;                       /* '<S8>/Z_oqus' */
  real_T roll_oqus;                    /* '<S8>/roll_oqus' */
  real_T pitch_oqus;                   /* '<S8>/pitch_oqus' */
  real_T yaw_oqus;                     /* '<S8>/yaw_oqus' */
  real_T Delay[6];                     /* '<S12>/Delay' */
  real_T Delay_e;                      /* '<S75>/Delay' */
  real_T Delay_a;                      /* '<S90>/Delay' */
  real_T DiscreteTransferFcn;          /* '<S90>/Discrete Transfer Fcn' */
  real_T TSamp;                        /* '<S93>/TSamp' */
  real_T Inertiacompensation;          /* '<S90>/Inertia compensation' */
  real_T Sum1_n;                       /* '<S90>/Sum1' */
  real_T Memory;                       /* '<S90>/Memory' */
  real_T Kp;                           /* '<S92>/Kp' */
  real_T reset_kk;                     /* '<S92>/reset' */
  real_T Sum_k;                        /* '<S90>/Sum' */
  real_T DiscreteTransferFcn_d;        /* '<S75>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed;         /* '<S89>/Finding rotation speed' */
  real_T Ki;                           /* '<S92>/Ki' */
  real_T Delay_b;                      /* '<S76>/Delay' */
  real_T Delay_bs;                     /* '<S99>/Delay' */
  real_T DiscreteTransferFcn_e;        /* '<S99>/Discrete Transfer Fcn' */
  real_T TSamp_n;                      /* '<S102>/TSamp' */
  real_T Inertiacompensation_e;        /* '<S99>/Inertia compensation' */
  real_T Sum1_nn;                      /* '<S99>/Sum1' */
  real_T Memory_c;                     /* '<S99>/Memory' */
  real_T Kp_p;                         /* '<S101>/Kp' */
  real_T reset_e;                      /* '<S101>/reset' */
  real_T Sum_h;                        /* '<S99>/Sum' */
  real_T DiscreteTransferFcn_k;        /* '<S76>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_a;       /* '<S98>/Finding rotation speed' */
  real_T Ki_o;                         /* '<S101>/Ki' */
  real_T Delay_i;                      /* '<S77>/Delay' */
  real_T Delay_by;                     /* '<S108>/Delay' */
  real_T DiscreteTransferFcn_f;        /* '<S108>/Discrete Transfer Fcn' */
  real_T TSamp_k;                      /* '<S111>/TSamp' */
  real_T Inertiacompensation_c;        /* '<S108>/Inertia compensation' */
  real_T Sum1_i;                       /* '<S108>/Sum1' */
  real_T Memory_i;                     /* '<S108>/Memory' */
  real_T Kp_i;                         /* '<S110>/Kp' */
  real_T reset_j2;                     /* '<S110>/reset' */
  real_T Sum_hf;                       /* '<S108>/Sum' */
  real_T DiscreteTransferFcn_n;        /* '<S77>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_m;       /* '<S107>/Finding rotation speed' */
  real_T Ki_n;                         /* '<S110>/Ki' */
  real_T Delay_g;                      /* '<S78>/Delay' */
  real_T Delay_l;                      /* '<S117>/Delay' */
  real_T DiscreteTransferFcn_l;        /* '<S117>/Discrete Transfer Fcn' */
  real_T TSamp_a;                      /* '<S120>/TSamp' */
  real_T Inertiacompensation_k;        /* '<S117>/Inertia compensation' */
  real_T Sum1_b;                       /* '<S117>/Sum1' */
  real_T Memory_j;                     /* '<S117>/Memory' */
  real_T Kp_c;                         /* '<S119>/Kp' */
  real_T reset_n;                      /* '<S119>/reset' */
  real_T Sum_k2;                       /* '<S117>/Sum' */
  real_T DiscreteTransferFcn_b;        /* '<S78>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_ms;      /* '<S116>/Finding rotation speed' */
  real_T Ki_b;                         /* '<S119>/Ki' */
  real_T Delay_a5;                     /* '<S79>/Delay' */
  real_T Delay_id;                     /* '<S126>/Delay' */
  real_T DiscreteTransferFcn_o;        /* '<S126>/Discrete Transfer Fcn' */
  real_T TSamp_m;                      /* '<S129>/TSamp' */
  real_T Inertiacompensation_f;        /* '<S126>/Inertia compensation' */
  real_T Sum1_o;                       /* '<S126>/Sum1' */
  real_T Memory_d;                     /* '<S126>/Memory' */
  real_T Kp_j;                         /* '<S128>/Kp' */
  real_T reset_f;                      /* '<S128>/reset' */
  real_T Sum_i;                        /* '<S126>/Sum' */
  real_T DiscreteTransferFcn_lz;       /* '<S79>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_ag;      /* '<S125>/Finding rotation speed' */
  real_T Ki_a;                         /* '<S128>/Ki' */
  real_T Delay_h;                      /* '<S80>/Delay' */
  real_T Delay_il;                     /* '<S135>/Delay' */
  real_T DiscreteTransferFcn_j;        /* '<S135>/Discrete Transfer Fcn' */
  real_T TSamp_o;                      /* '<S138>/TSamp' */
  real_T Inertiacompensation_e3;       /* '<S135>/Inertia compensation' */
  real_T Sum1_io;                      /* '<S135>/Sum1' */
  real_T Memory_o;                     /* '<S135>/Memory' */
  real_T Kp_l;                         /* '<S137>/Kp' */
  real_T reset_om;                     /* '<S137>/reset' */
  real_T Sum_f;                        /* '<S135>/Sum' */
  real_T DiscreteTransferFcn_ea;       /* '<S80>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_c;       /* '<S134>/Finding rotation speed' */
  real_T Ki_p;                         /* '<S137>/Ki' */
  real_T TmpSignalConversionAtDelayInpor[6];/* '<S12>/Thrust and Shaft speed mapped to PWM' */
  real_T IMU_AX1;                      /* '<S4>/IMU_AX1' */
  real_T IMU_AY1;                      /* '<S4>/IMU_AY1' */
  real_T IMU_AZ1;                      /* '<S4>/IMU_AZ1' */
  real_T IMU_RX1;                      /* '<S4>/IMU_RX1' */
  real_T IMU_RY1;                      /* '<S4>/IMU_RY1' */
  real_T IMU_RZ1;                      /* '<S4>/IMU_RZ1' */
  real_T IMU_V1;                       /* '<S4>/IMU_V1' */
  real_T IMU_AX2;                      /* '<S4>/IMU_AX2' */
  real_T IMU_AY2;                      /* '<S4>/IMU_AY2' */
  real_T IMU_AZ2;                      /* '<S4>/IMU_AZ2' */
  real_T IMU_RX2;                      /* '<S4>/IMU_RX2' */
  real_T IMU_RY2;                      /* '<S4>/IMU_RY2' */
  real_T IMU_RZ2;                      /* '<S4>/IMU_RZ2' */
  real_T IMU_V2;                       /* '<S4>/IMU_V2' */
  real_T IMU_AX3;                      /* '<S4>/IMU_AX3' */
  real_T IMU_AY3;                      /* '<S4>/IMU_AY3' */
  real_T IMU_AZ3;                      /* '<S4>/IMU_AZ3' */
  real_T IMU_RX3;                      /* '<S4>/IMU_RX3' */
  real_T IMU_RY3;                      /* '<S4>/IMU_RY3' */
  real_T IMU_RZ3;                      /* '<S4>/IMU_RZ3' */
  real_T IMU_V3;                       /* '<S4>/IMU_V3' */
  real_T IMU_AX4;                      /* '<S4>/IMU_AX4' */
  real_T IMU_AY4;                      /* '<S4>/IMU_AY4' */
  real_T IMU_AZ4;                      /* '<S4>/IMU_AZ4' */
  real_T IMU_RX4;                      /* '<S4>/IMU_RX4' */
  real_T IMU_RY4;                      /* '<S4>/IMU_RY4' */
  real_T IMU_RZ4;                      /* '<S4>/IMU_RZ4' */
  real_T IMU_V4;                       /* '<S4>/IMU_V4' */
  real_T n_d;                          /* '<S135>/MATLAB Function' */
  real_T n_d_p;                        /* '<S108>/MATLAB Function' */
  real_T n_d_h;                        /* '<S90>/MATLAB Function' */
  real_T Qa;                           /* '<S88>/Actual Force and Torque' */
  real_T Pa;                           /* '<S88>/Actual Force and Torque' */
  real_T Tc_out;                       /* '<S74>/MATLAB Function1' */
  real_T output[12];                   /* '<S74>/MATLAB Function' */
  real_T In1[28];                      /* '<S25>/In1' */
  real_T Merge1[5];                    /* '<S31>/Merge1' */
  real_T Merge1_e[5];                  /* '<S32>/Merge1' */
  real_T Merge1_k[5];                  /* '<S33>/Merge1' */
  real_T Merge1_h[5];                  /* '<S34>/Merge1' */
  real_T commanded_tau[3];             /* '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */
  B_Supervisor_ctrl_TAPM_T sf_Supervisor_e;/* '<S135>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePower_nf;/* '<S137>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_T_T sf_ActualForceandTorque_j;/* '<S133>/Actual Force and Torque' */
  B_Supervisor_ctrl_TAPM_T sf_Supervisor_b;/* '<S126>/Supervisor' */
  B_MATLABFunction_ctrl_TAPM_T sf_MATLABFunction_j;/* '<S126>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_h;/* '<S128>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_T_T sf_ActualForceandTorque_o;/* '<S124>/Actual Force and Torque' */
  B_Supervisor_ctrl_TAPM_T sf_Supervisor_n;/* '<S117>/Supervisor' */
  B_MATLABFunction_ctrl_TAPM_T sf_MATLABFunction_go;/* '<S117>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePower_n3;/* '<S119>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_T_T sf_ActualForceandTorque_m;/* '<S115>/Actual Force and Torque' */
  B_Supervisor_ctrl_TAPM_T sf_Supervisor_l;/* '<S108>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_n;/* '<S110>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_T_T sf_ActualForceandTorque_h;/* '<S106>/Actual Force and Torque' */
  B_Supervisor_ctrl_TAPM_T sf_Supervisor_h;/* '<S99>/Supervisor' */
  B_MATLABFunction_ctrl_TAPM_T sf_MATLABFunction_i;/* '<S99>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_o;/* '<S101>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_T_T sf_ActualForceandTorque_f;/* '<S97>/Actual Force and Torque' */
  B_Supervisor_ctrl_TAPM_T sf_Supervisor;/* '<S90>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowerand;/* '<S92>/Core controller: Torque,Power and Combined Torque//Power' */
  B_MATLABFunction2_ctrl_TAPM_T sf_MATLABFunction6;/* '<S74>/MATLAB Function6' */
  B_MATLABFunction2_ctrl_TAPM_T sf_MATLABFunction5;/* '<S74>/MATLAB Function5' */
  B_MATLABFunction2_ctrl_TAPM_T sf_MATLABFunction4;/* '<S74>/MATLAB Function4' */
  B_MATLABFunction2_ctrl_TAPM_T sf_MATLABFunction3;/* '<S74>/MATLAB Function3' */
  B_MATLABFunction2_ctrl_TAPM_T sf_MATLABFunction2;/* '<S74>/MATLAB Function2' */
  B_CoreSubsys_ctrl_TAPM_T CoreSubsys[6];/* '<S67>/CoreSubsys' */
  B_Kp_ctrl_TAPM_T sf_Kp_m;            /* '<S46>/Kp' */
  B_Ki_ctrl_TAPM_T sf_Ki_k;            /* '<S46>/Ki' */
  B_Kd_ctrl_TAPM_T sf_Kd_p;            /* '<S46>/Kd' */
  B_Kp_ctrl_TAPM_T sf_Kp;              /* '<S44>/Kp' */
  B_Ki_ctrl_TAPM_T sf_Ki;              /* '<S44>/Ki' */
  B_Kd_ctrl_TAPM_T sf_Kd;              /* '<S44>/Kd' */
} B_ctrl_TAPM_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[6];              /* '<S12>/Delay' */
  real_T Delay_DSTATE_f;               /* '<S75>/Delay' */
  real_T Delay_DSTATE_fu;              /* '<S90>/Delay' */
  real_T DiscreteTransferFcn_states[2];/* '<S90>/Discrete Transfer Fcn' */
  real_T UD_DSTATE;                    /* '<S93>/UD' */
  real_T DiscreteTransferFcn_states_d; /* '<S75>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_b;               /* '<S76>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S99>/Delay' */
  real_T DiscreteTransferFcn_states_h[2];/* '<S99>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_n;                  /* '<S102>/UD' */
  real_T DiscreteTransferFcn_states_m; /* '<S76>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_n;               /* '<S77>/Delay' */
  real_T Delay_DSTATE_no;              /* '<S108>/Delay' */
  real_T DiscreteTransferFcn_states_j[2];/* '<S108>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_i;                  /* '<S111>/UD' */
  real_T DiscreteTransferFcn_states_k; /* '<S77>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_e;               /* '<S78>/Delay' */
  real_T Delay_DSTATE_i;               /* '<S117>/Delay' */
  real_T DiscreteTransferFcn_states_i[2];/* '<S117>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_n4;                 /* '<S120>/UD' */
  real_T DiscreteTransferFcn_states_h0;/* '<S78>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_j;               /* '<S79>/Delay' */
  real_T Delay_DSTATE_a;               /* '<S126>/Delay' */
  real_T DiscreteTransferFcn_states_hb[2];/* '<S126>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_m;                  /* '<S129>/UD' */
  real_T DiscreteTransferFcn_states_dt;/* '<S79>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_dv;              /* '<S80>/Delay' */
  real_T Delay_DSTATE_m;               /* '<S135>/Delay' */
  real_T DiscreteTransferFcn_states_l[2];/* '<S135>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_l;                  /* '<S138>/UD' */
  real_T DiscreteTransferFcn_states_o; /* '<S80>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_fv[144];         /* '<S30>/Delay' */
  real_T Delay1_DSTATE[12];            /* '<S30>/Delay1' */
  real_T Delay_DSTATE_mc[144];         /* '<S27>/Delay' */
  real_T Delay1_DSTATE_f[12];          /* '<S27>/Delay1' */
  real_T Delay_DSTATE_dd[144];         /* '<S28>/Delay' */
  real_T Delay1_DSTATE_j[12];          /* '<S28>/Delay1' */
  real_T Delay_DSTATE_fg[144];         /* '<S29>/Delay' */
  real_T Delay1_DSTATE_i[12];          /* '<S29>/Delay1' */
  real_T K_p_x_DWORK1;                 /* '<S44>/K_p_x' */
  real_T K_p_y_DWORK1;                 /* '<S44>/K_p_y' */
  real_T K_p_psi_DWORK1;               /* '<S44>/K_p_psi' */
  real_T K_i_psi_DWORK1;               /* '<S44>/K_i_psi' */
  real_T K_i_x_DWORK1;                 /* '<S44>/K_i_x' */
  real_T K_i_y_DWORK1;                 /* '<S44>/K_i_y' */
  real_T K_d_psi_DWORK1;               /* '<S44>/K_d_psi' */
  real_T K_d_x_DWORK1;                 /* '<S44>/K_d_x' */
  real_T K_d_y_DWORK1;                 /* '<S44>/K_d_y' */
  real_T x_m_DWORK1;                   /* '<S8>/x_m' */
  real_T y_m_DWORK1;                   /* '<S8>/y_m' */
  real_T psi_m_DWORK1;                 /* '<S8>/psi_m' */
  real_T reset_DWORK1;                 /* '<S5>/reset' */
  real_T w_d_x_DWORK1;                 /* '<S45>/w_d_x' */
  real_T w_d_y_DWORK1;                 /* '<S45>/w_d_y' */
  real_T w_d_psi_DWORK1;               /* '<S45>/w_d_psi' */
  real_T zeta_psi_DWORK1;              /* '<S45>/zeta_psi' */
  real_T zeta_x_DWORK1;                /* '<S45>/zeta_x' */
  real_T zeta_y_DWORK1;                /* '<S45>/zeta_y' */
  real_T psi_ref_DWORK1;               /* '<S5>/psi_ref' */
  real_T x_ref_DWORK1;                 /* '<S5>/x_ref' */
  real_T y_ref_DWORK1;                 /* '<S5>/y_ref' */
  real_T thr_angle_1_DWORK1;           /* '<S13>/thr_angle_1' */
  real_T thr_angle_2_DWORK1;           /* '<S13>/thr_angle_2' */
  real_T thr_angle_3_DWORK1;           /* '<S13>/thr_angle_3' */
  real_T thr_angle_4_DWORK1;           /* '<S13>/thr_angle_4' */
  real_T thr_angle_5_DWORK1;           /* '<S13>/thr_angle_5' */
  real_T thr_angle_6_DWORK1;           /* '<S13>/thr_angle_6' */
  real_T reset_DWORK1_l[6];            /* '<S10>/reset' */
  real_T Angle_controller_DWORK1;      /* '<S10>/Angle_controller' */
  real_T alpha_1_DWORK1;               /* '<Root>/alpha_1' */
  real_T reset_DWORK1_g;               /* '<S89>/reset' */
  real_T reset_DWORK1_d;               /* '<S98>/reset' */
  real_T reset_DWORK1_e;               /* '<S107>/reset' */
  real_T reset_DWORK1_g4;              /* '<S116>/reset' */
  real_T reset_DWORK1_c;               /* '<S125>/reset' */
  real_T reset_DWORK1_a;               /* '<S134>/reset' */
  real_T rpm1_DWORK1;                  /* '<S74>/rpm1 ' */
  real_T rpm2_DWORK1;                  /* '<S74>/rpm2' */
  real_T rpm3_DWORK1;                  /* '<S74>/rpm3' */
  real_T rpm4_DWORK1;                  /* '<S74>/rpm4' */
  real_T rpm5_DWORK1;                  /* '<S74>/rpm5' */
  real_T rpm6_DWORK1;                  /* '<S74>/rpm6' */
  real_T pwm_2_DWORK1;                 /* '<Root>/pwm_2' */
  real_T pwm_3_DWORK1;                 /* '<Root>/pwm_3' */
  real_T pwm_4_DWORK1;                 /* '<Root>/pwm_4' */
  real_T pwm_5_DWORK1;                 /* '<Root>/pwm_5' */
  real_T alpha_2_DWORK1;               /* '<Root>/alpha_2' */
  real_T pwm_6_DWORK1;                 /* '<Root>/pwm_6' */
  real_T alpha_3_DWORK1;               /* '<Root>/alpha_3' */
  real_T alpha_4_DWORK1;               /* '<Root>/alpha_4' */
  real_T alpha_5_DWORK1;               /* '<Root>/alpha_5' */
  real_T alpha_6_DWORK1;               /* '<Root>/alpha_6' */
  real_T u_1_DWORK1;                   /* '<Root>/u_1' */
  real_T u_4_DWORK1;                   /* '<Root>/u_4' */
  real_T u_5_DWORK1;                   /* '<Root>/u_5' */
  real_T u_6_DWORK1;                   /* '<Root>/u_6' */
  real_T u_2_DWORK1;                   /* '<Root>/u_2' */
  real_T u_3_DWORK1;                   /* '<Root>/u_3' */
  real_T pwm_1_DWORK1;                 /* '<Root>/pwm_1' */
  real_T x_hat_DWORK1;                 /* '<S63>/x_hat' */
  real_T y_hat_DWORK1;                 /* '<S63>/y_hat' */
  real_T psi_hat_DWORK1;               /* '<S63>/psi_hat' */
  real_T u_hat_DWORK1;                 /* '<S65>/u_hat' */
  real_T v_hat_DWORK1;                 /* '<S65>/v_hat' */
  real_T r_hat_DWORK1;                 /* '<S65>/r_hat' */
  real_T u_dot_hat_DWORK1;             /* '<S64>/u_dot_hat' */
  real_T v_dot_hat_DWORK1;             /* '<S64>/v_dot_hat' */
  real_T r_dot_hat_DWORK1;             /* '<S64>/r_dot_hat' */
  real_T b_x_hat_DWORK1;               /* '<S62>/b_x_hat' */
  real_T b_y_hat_DWORK1;               /* '<S62>/b_y_hat' */
  real_T b_psi_hat_DWORK1;             /* '<S62>/b_psi_hat' */
  real_T tau_actual_DWORK1[3];         /* '<Root>/tau_actual' */
  real_T eta_tilde_DWORK1[3];          /* '<S14>/eta_tilde' */
  real_T eta_des_DWORK1[3];            /* '<S3>/eta_des' */
  real_T X_oqus_DWORK1;                /* '<S8>/X_oqus' */
  real_T Y_oqus_DWORK1;                /* '<S8>/Y_oqus' */
  real_T Z_oqus_DWORK1;                /* '<S8>/Z_oqus' */
  real_T roll_oqus_DWORK1;             /* '<S8>/roll_oqus' */
  real_T pitch_oqus_DWORK1;            /* '<S8>/pitch_oqus' */
  real_T yaw_oqus_DWORK1;              /* '<S8>/yaw_oqus' */
  real_T DiscreteTransferFcn_tmp;      /* '<S90>/Discrete Transfer Fcn' */
  real_T PrevY;                        /* '<S90>/Acceleration Limit' */
  real_T Memory_PreviousInput;         /* '<S90>/Memory' */
  real_T reset_DWORK1_ec;              /* '<S92>/reset' */
  real_T DiscreteTransferFcn_tmp_a;    /* '<S75>/Discrete Transfer Fcn' */
  real_T Control_test_Pa_DWORK1;       /* '<S88>/Control_test_Pa' */
  real_T DiscreteTransferFcn_tmp_d;    /* '<S99>/Discrete Transfer Fcn' */
  real_T PrevY_e;                      /* '<S99>/Acceleration Limit' */
  real_T Memory_PreviousInput_n;       /* '<S99>/Memory' */
  real_T reset_DWORK1_ln;              /* '<S101>/reset' */
  real_T DiscreteTransferFcn_tmp_h;    /* '<S76>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_e;    /* '<S108>/Discrete Transfer Fcn' */
  real_T PrevY_o;                      /* '<S108>/Acceleration limiter' */
  real_T Memory_PreviousInput_d;       /* '<S108>/Memory' */
  real_T reset_DWORK1_lw;              /* '<S110>/reset' */
  real_T DiscreteTransferFcn_tmp_hh;   /* '<S77>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_k;    /* '<S117>/Discrete Transfer Fcn' */
  real_T PrevY_c;                      /* '<S117>/Acceleration limiter' */
  real_T Memory_PreviousInput_a;       /* '<S117>/Memory' */
  real_T reset_DWORK1_ct;              /* '<S119>/reset' */
  real_T DiscreteTransferFcn_tmp_n;    /* '<S78>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_c;    /* '<S126>/Discrete Transfer Fcn' */
  real_T PrevY_j;                      /* '<S126>/Acceleration limiter' */
  real_T Memory_PreviousInput_b;       /* '<S126>/Memory' */
  real_T reset_DWORK1_i;               /* '<S128>/reset' */
  real_T DiscreteTransferFcn_tmp_f;    /* '<S79>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_h4;   /* '<S135>/Discrete Transfer Fcn' */
  real_T PrevY_h;                      /* '<S135>/Acceleration limiter' */
  real_T Memory_PreviousInput_a4;      /* '<S135>/Memory' */
  real_T reset_DWORK1_j;               /* '<S137>/reset' */
  real_T DiscreteTransferFcn_tmp_cw;   /* '<S80>/Discrete Transfer Fcn' */
  real_T IMU_AX1_DWORK1;               /* '<S4>/IMU_AX1' */
  real_T IMU_AY1_DWORK1;               /* '<S4>/IMU_AY1' */
  real_T IMU_AZ1_DWORK1;               /* '<S4>/IMU_AZ1' */
  real_T IMU_RX1_DWORK1;               /* '<S4>/IMU_RX1' */
  real_T IMU_RY1_DWORK1;               /* '<S4>/IMU_RY1' */
  real_T IMU_RZ1_DWORK1;               /* '<S4>/IMU_RZ1' */
  real_T IMU_V1_DWORK1;                /* '<S4>/IMU_V1' */
  real_T IMU_AX2_DWORK1;               /* '<S4>/IMU_AX2' */
  real_T IMU_AY2_DWORK1;               /* '<S4>/IMU_AY2' */
  real_T IMU_AZ2_DWORK1;               /* '<S4>/IMU_AZ2' */
  real_T IMU_RX2_DWORK1;               /* '<S4>/IMU_RX2' */
  real_T IMU_RY2_DWORK1;               /* '<S4>/IMU_RY2' */
  real_T IMU_RZ2_DWORK1;               /* '<S4>/IMU_RZ2' */
  real_T IMU_V2_DWORK1;                /* '<S4>/IMU_V2' */
  real_T IMU_AX3_DWORK1;               /* '<S4>/IMU_AX3' */
  real_T IMU_AY3_DWORK1;               /* '<S4>/IMU_AY3' */
  real_T IMU_AZ3_DWORK1;               /* '<S4>/IMU_AZ3' */
  real_T IMU_RX3_DWORK1;               /* '<S4>/IMU_RX3' */
  real_T IMU_RY3_DWORK1;               /* '<S4>/IMU_RY3' */
  real_T IMU_RZ3_DWORK1;               /* '<S4>/IMU_RZ3' */
  real_T IMU_V3_DWORK1;                /* '<S4>/IMU_V3' */
  real_T IMU_AX4_DWORK1;               /* '<S4>/IMU_AX4' */
  real_T IMU_AY4_DWORK1;               /* '<S4>/IMU_AY4' */
  real_T IMU_AZ4_DWORK1;               /* '<S4>/IMU_AZ4' */
  real_T IMU_RX4_DWORK1;               /* '<S4>/IMU_RX4' */
  real_T IMU_RY4_DWORK1;               /* '<S4>/IMU_RY4' */
  real_T IMU_RZ4_DWORK1;               /* '<S4>/IMU_RZ4' */
  real_T IMU_V4_DWORK1;                /* '<S4>/IMU_V4' */
  real_T Memory_PreviousInput_l[28];   /* '<S4>/Memory' */
  real_T MatrixMultiply_DWORK4[36];    /* '<S30>/Matrix Multiply' */
  real_T Memory2_PreviousInput[5];     /* '<S31>/Memory2' */
  real_T Memory3_PreviousInput[7];     /* '<S31>/Memory3' */
  real_T MatrixMultiply_DWORK4_a[36];  /* '<S27>/Matrix Multiply' */
  real_T Memory2_PreviousInput_d[5];   /* '<S32>/Memory2' */
  real_T Memory3_PreviousInput_p[7];   /* '<S32>/Memory3' */
  real_T MatrixMultiply_DWORK4_f[36];  /* '<S28>/Matrix Multiply' */
  real_T Memory2_PreviousInput_n[5];   /* '<S33>/Memory2' */
  real_T Memory3_PreviousInput_j[7];   /* '<S33>/Memory3' */
  real_T MatrixMultiply_DWORK4_e[36];  /* '<S29>/Matrix Multiply' */
  real_T Memory2_PreviousInput_c[5];   /* '<S34>/Memory2' */
  real_T Memory3_PreviousInput_k[7];   /* '<S34>/Memory3' */
  struct {
    void *FilePtr;
  } ToFile_PWORK;                      /* '<S8>/To File' */

  struct {
    void *FilePtr;
  } ToFile_PWORK_a;                    /* '<S25>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<S25>/To File1' */

  struct {
    void *FilePtr;
  } ToFile2_PWORK;                     /* '<S25>/To File2' */

  struct {
    void *FilePtr;
  } ToFile3_PWORK;                     /* '<S25>/To File3' */

  struct {
    void *FilePtr;
  } ToFile4_PWORK;                     /* '<S25>/To File4' */

  struct {
    void *FilePtr;
  } ToFile5_PWORK;                     /* '<S25>/To File5' */

  struct {
    void *FilePtr;
  } ToFile6_PWORK;                     /* '<S25>/To File6' */

  struct {
    void *FilePtr;
  } ToFile7_PWORK;                     /* '<S25>/To File7' */

  uint32_T Median_Index[5];            /* '<S31>/Median' */
  uint32_T Median1_Index[5];           /* '<S31>/Median1' */
  uint32_T Median_Index_f[5];          /* '<S32>/Median' */
  uint32_T Median1_Index_p[5];         /* '<S32>/Median1' */
  uint32_T Median_Index_j[5];          /* '<S33>/Median' */
  uint32_T Median1_Index_j[5];         /* '<S33>/Median1' */
  uint32_T Median_Index_d[5];          /* '<S34>/Median' */
  uint32_T Median1_Index_d[5];         /* '<S34>/Median1' */
  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK;                 /* '<S19>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S6>/Integrator' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<S8>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK_e;                    /* '<S25>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<S25>/To File1' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile2_IWORK;                     /* '<S25>/To File2' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile3_IWORK;                     /* '<S25>/To File3' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile4_IWORK;                     /* '<S25>/To File4' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile5_IWORK;                     /* '<S25>/To File5' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile6_IWORK;                     /* '<S25>/To File6' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile7_IWORK;                     /* '<S25>/To File7' */

  uint8_T K_p_x_DWORK2[10];            /* '<S44>/K_p_x' */
  uint8_T K_p_y_DWORK2[10];            /* '<S44>/K_p_y' */
  uint8_T K_p_psi_DWORK2[10];          /* '<S44>/K_p_psi' */
  uint8_T K_i_psi_DWORK2[10];          /* '<S44>/K_i_psi' */
  uint8_T K_i_x_DWORK2[10];            /* '<S44>/K_i_x' */
  uint8_T K_i_y_DWORK2[10];            /* '<S44>/K_i_y' */
  uint8_T K_d_psi_DWORK2[10];          /* '<S44>/K_d_psi' */
  uint8_T K_d_x_DWORK2[10];            /* '<S44>/K_d_x' */
  uint8_T K_d_y_DWORK2[10];            /* '<S44>/K_d_y' */
  uint8_T x_m_DWORK2[10];              /* '<S8>/x_m' */
  uint8_T y_m_DWORK2[10];              /* '<S8>/y_m' */
  uint8_T psi_m_DWORK2[10];            /* '<S8>/psi_m' */
  uint8_T reset_DWORK2[10];            /* '<S5>/reset' */
  uint8_T w_d_x_DWORK2[10];            /* '<S45>/w_d_x' */
  uint8_T w_d_y_DWORK2[10];            /* '<S45>/w_d_y' */
  uint8_T w_d_psi_DWORK2[10];          /* '<S45>/w_d_psi' */
  uint8_T zeta_psi_DWORK2[10];         /* '<S45>/zeta_psi' */
  uint8_T zeta_x_DWORK2[10];           /* '<S45>/zeta_x' */
  uint8_T zeta_y_DWORK2[10];           /* '<S45>/zeta_y' */
  uint8_T psi_ref_DWORK2[10];          /* '<S5>/psi_ref' */
  uint8_T x_ref_DWORK2[10];            /* '<S5>/x_ref' */
  uint8_T y_ref_DWORK2[10];            /* '<S5>/y_ref' */
  uint8_T thr_angle_1_DWORK2[10];      /* '<S13>/thr_angle_1' */
  uint8_T thr_angle_2_DWORK2[10];      /* '<S13>/thr_angle_2' */
  uint8_T thr_angle_3_DWORK2[10];      /* '<S13>/thr_angle_3' */
  uint8_T thr_angle_4_DWORK2[10];      /* '<S13>/thr_angle_4' */
  uint8_T thr_angle_5_DWORK2[10];      /* '<S13>/thr_angle_5' */
  uint8_T thr_angle_6_DWORK2[10];      /* '<S13>/thr_angle_6' */
  uint8_T reset_DWORK2_m[10];          /* '<S10>/reset' */
  uint8_T Angle_controller_DWORK2[10]; /* '<S10>/Angle_controller' */
  uint8_T alpha_1_DWORK2[10];          /* '<Root>/alpha_1' */
  uint8_T reset_DWORK2_j[10];          /* '<S89>/reset' */
  uint8_T reset_DWORK2_o[10];          /* '<S98>/reset' */
  uint8_T reset_DWORK2_i[10];          /* '<S107>/reset' */
  uint8_T reset_DWORK2_k[10];          /* '<S116>/reset' */
  uint8_T reset_DWORK2_a[10];          /* '<S125>/reset' */
  uint8_T reset_DWORK2_mm[10];         /* '<S134>/reset' */
  uint8_T rpm1_DWORK2[10];             /* '<S74>/rpm1 ' */
  uint8_T rpm2_DWORK2[10];             /* '<S74>/rpm2' */
  uint8_T rpm3_DWORK2[10];             /* '<S74>/rpm3' */
  uint8_T rpm4_DWORK2[10];             /* '<S74>/rpm4' */
  uint8_T rpm5_DWORK2[10];             /* '<S74>/rpm5' */
  uint8_T rpm6_DWORK2[10];             /* '<S74>/rpm6' */
  uint8_T pwm_2_DWORK2[10];            /* '<Root>/pwm_2' */
  uint8_T pwm_3_DWORK2[10];            /* '<Root>/pwm_3' */
  uint8_T pwm_4_DWORK2[10];            /* '<Root>/pwm_4' */
  uint8_T pwm_5_DWORK2[10];            /* '<Root>/pwm_5' */
  uint8_T alpha_2_DWORK2[10];          /* '<Root>/alpha_2' */
  uint8_T pwm_6_DWORK2[10];            /* '<Root>/pwm_6' */
  uint8_T alpha_3_DWORK2[10];          /* '<Root>/alpha_3' */
  uint8_T alpha_4_DWORK2[10];          /* '<Root>/alpha_4' */
  uint8_T alpha_5_DWORK2[10];          /* '<Root>/alpha_5' */
  uint8_T alpha_6_DWORK2[10];          /* '<Root>/alpha_6' */
  uint8_T u_1_DWORK2[10];              /* '<Root>/u_1' */
  uint8_T u_4_DWORK2[10];              /* '<Root>/u_4' */
  uint8_T u_5_DWORK2[10];              /* '<Root>/u_5' */
  uint8_T u_6_DWORK2[10];              /* '<Root>/u_6' */
  uint8_T u_2_DWORK2[10];              /* '<Root>/u_2' */
  uint8_T u_3_DWORK2[10];              /* '<Root>/u_3' */
  uint8_T pwm_1_DWORK2[10];            /* '<Root>/pwm_1' */
  uint8_T x_hat_DWORK2[10];            /* '<S63>/x_hat' */
  uint8_T y_hat_DWORK2[10];            /* '<S63>/y_hat' */
  uint8_T psi_hat_DWORK2[10];          /* '<S63>/psi_hat' */
  uint8_T u_hat_DWORK2[10];            /* '<S65>/u_hat' */
  uint8_T v_hat_DWORK2[10];            /* '<S65>/v_hat' */
  uint8_T r_hat_DWORK2[10];            /* '<S65>/r_hat' */
  uint8_T u_dot_hat_DWORK2[10];        /* '<S64>/u_dot_hat' */
  uint8_T v_dot_hat_DWORK2[10];        /* '<S64>/v_dot_hat' */
  uint8_T r_dot_hat_DWORK2[10];        /* '<S64>/r_dot_hat' */
  uint8_T b_x_hat_DWORK2[10];          /* '<S62>/b_x_hat' */
  uint8_T b_y_hat_DWORK2[10];          /* '<S62>/b_y_hat' */
  uint8_T b_psi_hat_DWORK2[10];        /* '<S62>/b_psi_hat' */
  uint8_T tau_actual_DWORK2[10];       /* '<Root>/tau_actual' */
  uint8_T eta_tilde_DWORK2[10];        /* '<S14>/eta_tilde' */
  uint8_T eta_des_DWORK2[10];          /* '<S3>/eta_des' */
  uint8_T X_oqus_DWORK2[10];           /* '<S8>/X_oqus' */
  uint8_T Y_oqus_DWORK2[10];           /* '<S8>/Y_oqus' */
  uint8_T Z_oqus_DWORK2[10];           /* '<S8>/Z_oqus' */
  uint8_T roll_oqus_DWORK2[10];        /* '<S8>/roll_oqus' */
  uint8_T pitch_oqus_DWORK2[10];       /* '<S8>/pitch_oqus' */
  uint8_T yaw_oqus_DWORK2[10];         /* '<S8>/yaw_oqus' */
  uint8_T reset_DWORK2_n[10];          /* '<S92>/reset' */
  uint8_T Control_test_Pa_DWORK2[10];  /* '<S88>/Control_test_Pa' */
  uint8_T reset_DWORK2_e[10];          /* '<S101>/reset' */
  uint8_T reset_DWORK2_l[10];          /* '<S110>/reset' */
  uint8_T reset_DWORK2_mb[10];         /* '<S119>/reset' */
  uint8_T reset_DWORK2_nu[10];         /* '<S128>/reset' */
  uint8_T reset_DWORK2_f[10];          /* '<S137>/reset' */
  uint8_T IMU_AX1_DWORK2[10];          /* '<S4>/IMU_AX1' */
  uint8_T IMU_AY1_DWORK2[10];          /* '<S4>/IMU_AY1' */
  uint8_T IMU_AZ1_DWORK2[10];          /* '<S4>/IMU_AZ1' */
  uint8_T IMU_RX1_DWORK2[10];          /* '<S4>/IMU_RX1' */
  uint8_T IMU_RY1_DWORK2[10];          /* '<S4>/IMU_RY1' */
  uint8_T IMU_RZ1_DWORK2[10];          /* '<S4>/IMU_RZ1' */
  uint8_T IMU_V1_DWORK2[10];           /* '<S4>/IMU_V1' */
  uint8_T IMU_AX2_DWORK2[10];          /* '<S4>/IMU_AX2' */
  uint8_T IMU_AY2_DWORK2[10];          /* '<S4>/IMU_AY2' */
  uint8_T IMU_AZ2_DWORK2[10];          /* '<S4>/IMU_AZ2' */
  uint8_T IMU_RX2_DWORK2[10];          /* '<S4>/IMU_RX2' */
  uint8_T IMU_RY2_DWORK2[10];          /* '<S4>/IMU_RY2' */
  uint8_T IMU_RZ2_DWORK2[10];          /* '<S4>/IMU_RZ2' */
  uint8_T IMU_V2_DWORK2[10];           /* '<S4>/IMU_V2' */
  uint8_T IMU_AX3_DWORK2[10];          /* '<S4>/IMU_AX3' */
  uint8_T IMU_AY3_DWORK2[10];          /* '<S4>/IMU_AY3' */
  uint8_T IMU_AZ3_DWORK2[10];          /* '<S4>/IMU_AZ3' */
  uint8_T IMU_RX3_DWORK2[10];          /* '<S4>/IMU_RX3' */
  uint8_T IMU_RY3_DWORK2[10];          /* '<S4>/IMU_RY3' */
  uint8_T IMU_RZ3_DWORK2[10];          /* '<S4>/IMU_RZ3' */
  uint8_T IMU_V3_DWORK2[10];           /* '<S4>/IMU_V3' */
  uint8_T IMU_AX4_DWORK2[10];          /* '<S4>/IMU_AX4' */
  uint8_T IMU_AY4_DWORK2[10];          /* '<S4>/IMU_AY4' */
  uint8_T IMU_AZ4_DWORK2[10];          /* '<S4>/IMU_AZ4' */
  uint8_T IMU_RX4_DWORK2[10];          /* '<S4>/IMU_RX4' */
  uint8_T IMU_RY4_DWORK2[10];          /* '<S4>/IMU_RY4' */
  uint8_T IMU_RZ4_DWORK2[10];          /* '<S4>/IMU_RZ4' */
  uint8_T IMU_V4_DWORK2[10];           /* '<S4>/IMU_V4' */
  DW_CoreSubsys_ctrl_TAPM_T CoreSubsys[6];/* '<S67>/CoreSubsys' */
} DW_ctrl_TAPM_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S19>/Integrator1' */
  real_T Integrator_CSTATE[3];         /* '<S14>/Integrator' */
  real_T Integrator1_CSTATE_g[3];      /* '<S6>/Integrator1' */
  real_T Integrator3_CSTATE[3];        /* '<S19>/Integrator3' */
  real_T Integrator_CSTATE_c;          /* '<S89>/Integrator' */
  real_T Integrator_CSTATE_p;          /* '<S98>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S107>/Integrator' */
  real_T Integrator_CSTATE_n;          /* '<S116>/Integrator' */
  real_T Integrator_CSTATE_cd;         /* '<S125>/Integrator' */
  real_T Integrator_CSTATE_h;          /* '<S134>/Integrator' */
  real_T Integrator_CSTATE_a[3];       /* '<S6>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S6>/Integrator2' */
  real_T Integrator2_CSTATE_c[3];      /* '<S19>/Integrator2' */
  real_T Integrator_CSTATE_e;          /* '<S92>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S101>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S110>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S119>/Integrator' */
  real_T Integrator_CSTATE_n4;         /* '<S128>/Integrator' */
  real_T Integrator_CSTATE_gj;         /* '<S137>/Integrator' */
} X_ctrl_TAPM_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S19>/Integrator1' */
  real_T Integrator_CSTATE[3];         /* '<S14>/Integrator' */
  real_T Integrator1_CSTATE_g[3];      /* '<S6>/Integrator1' */
  real_T Integrator3_CSTATE[3];        /* '<S19>/Integrator3' */
  real_T Integrator_CSTATE_c;          /* '<S89>/Integrator' */
  real_T Integrator_CSTATE_p;          /* '<S98>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S107>/Integrator' */
  real_T Integrator_CSTATE_n;          /* '<S116>/Integrator' */
  real_T Integrator_CSTATE_cd;         /* '<S125>/Integrator' */
  real_T Integrator_CSTATE_h;          /* '<S134>/Integrator' */
  real_T Integrator_CSTATE_a[3];       /* '<S6>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S6>/Integrator2' */
  real_T Integrator2_CSTATE_c[3];      /* '<S19>/Integrator2' */
  real_T Integrator_CSTATE_e;          /* '<S92>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S101>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S110>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S119>/Integrator' */
  real_T Integrator_CSTATE_n4;         /* '<S128>/Integrator' */
  real_T Integrator_CSTATE_gj;         /* '<S137>/Integrator' */
} XDot_ctrl_TAPM_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE[3];     /* '<S19>/Integrator1' */
  boolean_T Integrator_CSTATE[3];      /* '<S14>/Integrator' */
  boolean_T Integrator1_CSTATE_g[3];   /* '<S6>/Integrator1' */
  boolean_T Integrator3_CSTATE[3];     /* '<S19>/Integrator3' */
  boolean_T Integrator_CSTATE_c;       /* '<S89>/Integrator' */
  boolean_T Integrator_CSTATE_p;       /* '<S98>/Integrator' */
  boolean_T Integrator_CSTATE_k;       /* '<S107>/Integrator' */
  boolean_T Integrator_CSTATE_n;       /* '<S116>/Integrator' */
  boolean_T Integrator_CSTATE_cd;      /* '<S125>/Integrator' */
  boolean_T Integrator_CSTATE_h;       /* '<S134>/Integrator' */
  boolean_T Integrator_CSTATE_a[3];    /* '<S6>/Integrator' */
  boolean_T Integrator2_CSTATE[3];     /* '<S6>/Integrator2' */
  boolean_T Integrator2_CSTATE_c[3];   /* '<S19>/Integrator2' */
  boolean_T Integrator_CSTATE_e;       /* '<S92>/Integrator' */
  boolean_T Integrator_CSTATE_g;       /* '<S101>/Integrator' */
  boolean_T Integrator_CSTATE_i;       /* '<S110>/Integrator' */
  boolean_T Integrator_CSTATE_l;       /* '<S119>/Integrator' */
  boolean_T Integrator_CSTATE_n4;      /* '<S128>/Integrator' */
  boolean_T Integrator_CSTATE_gj;      /* '<S137>/Integrator' */
} XDis_ctrl_TAPM_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator1_Reset_ZCE;    /* '<S19>/Integrator1' */
  ZCSigState Integrator_Reset_ZCE;     /* '<S14>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE_i;  /* '<S6>/Integrator1' */
  ZCSigState Integrator3_Reset_ZCE;    /* '<S19>/Integrator3' */
  ZCSigState Integrator_Reset_ZCE_g;   /* '<S89>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_n;   /* '<S98>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_o;   /* '<S107>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_i;   /* '<S116>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_a;   /* '<S125>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_d;   /* '<S134>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_nt;  /* '<S6>/Integrator' */
  ZCSigState Integrator2_Reset_ZCE;    /* '<S6>/Integrator2' */
  ZCSigState Integrator2_Reset_ZCE_h;  /* '<S19>/Integrator2' */
  ZCSigState Integrator_Reset_ZCE_o3;  /* '<S92>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_db;  /* '<S101>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_l;   /* '<S110>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_h;   /* '<S119>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_f;   /* '<S128>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_i3;  /* '<S137>/Integrator' */
  ZCSigState Filtering_Trig_ZCE[28];   /* '<S4>/Filtering' */
} PrevZCX_ctrl_TAPM_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_TAPM_B
#define BlockIO                        B_ctrl_TAPM_T
#define rtX                            ctrl_TAPM_X
#define ContinuousStates               X_ctrl_TAPM_T
#define rtXdot                         ctrl_TAPM_XDot
#define StateDerivatives               XDot_ctrl_TAPM_T
#define tXdis                          ctrl_TAPM_XDis
#define StateDisabled                  XDis_ctrl_TAPM_T
#define rtP                            ctrl_TAPM_P
#define Parameters                     P_ctrl_TAPM_T
#define rtDWork                        ctrl_TAPM_DW
#define D_Work                         DW_ctrl_TAPM_T
#define rtPrevZCSigState               ctrl_TAPM_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_TAPM_T

/* Parameters for system: '<S67>/CoreSubsys' */
struct P_CoreSubsys_ctrl_TAPM_T_ {
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S67>/Discrete-Time Integrator'
                                         */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S70>/Gain1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S67>/Delay'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S67>/Delay'
                                        */
};

/* Parameters (auto storage) */
struct P_ctrl_TAPM_T_ {
  real_T C[24];                        /* Variable: C
                                        * Referenced by: '<S10>/C'
                                        */
  real_T D;                            /* Variable: D
                                        * Referenced by: '<S11>/D'
                                        */
  real_T I_s;                          /* Variable: I_s
                                        * Referenced by:
                                        *   '<S89>/Finding rotation speed'
                                        *   '<S90>/Inertia compensation'
                                        *   '<S98>/Finding rotation speed'
                                        *   '<S99>/Inertia compensation'
                                        *   '<S107>/Finding rotation speed'
                                        *   '<S108>/Inertia compensation'
                                        *   '<S116>/Finding rotation speed'
                                        *   '<S117>/Inertia compensation'
                                        *   '<S125>/Finding rotation speed'
                                        *   '<S126>/Inertia compensation'
                                        *   '<S134>/Finding rotation speed'
                                        *   '<S135>/Inertia compensation'
                                        */
  real_T K_T1f;                        /* Variable: K_T1f
                                        * Referenced by: '<S11>/K_Tf1'
                                        */
  real_T K_T1r;                        /* Variable: K_T1r
                                        * Referenced by: '<S11>/K_Tr1'
                                        */
  real_T K_T2f;                        /* Variable: K_T2f
                                        * Referenced by: '<S11>/K_Tf2'
                                        */
  real_T K_T2r;                        /* Variable: K_T2r
                                        * Referenced by: '<S11>/K_Tr2'
                                        */
  real_T K_T3f;                        /* Variable: K_T3f
                                        * Referenced by: '<S11>/K_Tf3'
                                        */
  real_T K_T3r;                        /* Variable: K_T3r
                                        * Referenced by: '<S11>/K_Tr3'
                                        */
  real_T K_T4f;                        /* Variable: K_T4f
                                        * Referenced by: '<S11>/K_Tf4'
                                        */
  real_T K_T4r;                        /* Variable: K_T4r
                                        * Referenced by: '<S11>/K_Tr4'
                                        */
  real_T K_T5f;                        /* Variable: K_T5f
                                        * Referenced by: '<S11>/K_Tf5'
                                        */
  real_T K_T5r;                        /* Variable: K_T5r
                                        * Referenced by: '<S11>/K_Tr5'
                                        */
  real_T K_T6f;                        /* Variable: K_T6f
                                        * Referenced by: '<S11>/K_Tf6'
                                        */
  real_T K_T6r;                        /* Variable: K_T6r
                                        * Referenced by: '<S11>/K_Tr6'
                                        */
  real_T K_omega;                      /* Variable: K_omega
                                        * Referenced by:
                                        *   '<S89>/K_omega'
                                        *   '<S90>/Qff_1(nr)'
                                        *   '<S98>/K_omega'
                                        *   '<S99>/Qff_1(nr)'
                                        *   '<S107>/K_omega'
                                        *   '<S108>/Qff_1(nr)'
                                        *   '<S116>/K_omega'
                                        *   '<S117>/Qff_1(nr)'
                                        *   '<S125>/K_omega'
                                        *   '<S126>/Qff_1(nr)'
                                        *   '<S134>/K_omega'
                                        *   '<S135>/Qff_1(nr)'
                                        */
  real_T K_q1f;                        /* Variable: K_q1f
                                        * Referenced by: '<S11>/K_Qr1'
                                        */
  real_T K_q1r;                        /* Variable: K_q1r
                                        * Referenced by: '<S11>/K_Qr7'
                                        */
  real_T K_q2f;                        /* Variable: K_q2f
                                        * Referenced by: '<S11>/K_Qr2'
                                        */
  real_T K_q2r;                        /* Variable: K_q2r
                                        * Referenced by: '<S11>/K_Qr8'
                                        */
  real_T K_q3f;                        /* Variable: K_q3f
                                        * Referenced by: '<S11>/K_Qr3'
                                        */
  real_T K_q3r;                        /* Variable: K_q3r
                                        * Referenced by: '<S11>/K_Qr9'
                                        */
  real_T K_q4f;                        /* Variable: K_q4f
                                        * Referenced by: '<S11>/K_Qr4'
                                        */
  real_T K_q4r;                        /* Variable: K_q4r
                                        * Referenced by: '<S11>/K_Qr10'
                                        */
  real_T K_q5f;                        /* Variable: K_q5f
                                        * Referenced by: '<S11>/K_Qr5'
                                        */
  real_T K_q5r;                        /* Variable: K_q5r
                                        * Referenced by: '<S11>/K_Qr11'
                                        */
  real_T K_q6f;                        /* Variable: K_q6f
                                        * Referenced by: '<S11>/K_Qr6'
                                        */
  real_T K_q6r;                        /* Variable: K_q6r
                                        * Referenced by: '<S11>/K_Qr12'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by:
                                        *   '<S92>/Ki'
                                        *   '<S92>/Kp'
                                        *   '<S101>/Ki'
                                        *   '<S101>/Kp'
                                        *   '<S110>/Ki'
                                        *   '<S110>/Kp'
                                        *   '<S119>/Ki'
                                        *   '<S119>/Kp'
                                        *   '<S128>/Ki'
                                        *   '<S128>/Kp'
                                        *   '<S137>/Ki'
                                        *   '<S137>/Kp'
                                        */
  real_T Max_rotation;                 /* Variable: Max_rotation
                                        * Referenced by: '<S67>/Max Rotation Rate'
                                        */
  real_T Max_thrust;                   /* Variable: Max_thrust
                                        * Referenced by:
                                        *   '<S74>/Saturation 1'
                                        *   '<S74>/Saturation 10'
                                        *   '<S74>/Saturation 12'
                                        *   '<S74>/Saturation 3'
                                        *   '<S74>/Saturation 5'
                                        *   '<S74>/Saturation 7'
                                        *   '<S74>/Saturation 8'
                                        */
  real_T Min_thrust;                   /* Variable: Min_thrust
                                        * Referenced by:
                                        *   '<S74>/Saturation 11'
                                        *   '<S74>/Saturation 13'
                                        *   '<S74>/Saturation 2'
                                        *   '<S74>/Saturation 4'
                                        *   '<S74>/Saturation 6'
                                        *   '<S74>/Saturation 9'
                                        */
  real_T Q_f0;                         /* Variable: Q_f0
                                        * Referenced by:
                                        *   '<S90>/Qf_0'
                                        *   '<S99>/Qf_0'
                                        *   '<S108>/Qf_0'
                                        *   '<S117>/Qf_0'
                                        *   '<S126>/Qf_0'
                                        *   '<S135>/Qf_0'
                                        */
  real_T Rho;                          /* Variable: Rho
                                        * Referenced by: '<S11>/Rho'
                                        */
  real_T eps;                          /* Variable: eps
                                        * Referenced by: '<S10>/Constant to avoid singularities'
                                        */
  real_T eps_c;                        /* Variable: eps_c
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T epsilon;                      /* Variable: epsilon
                                        * Referenced by:
                                        *   '<S90>/Qff_0(nr)'
                                        *   '<S99>/Qff_0(nr)'
                                        *   '<S108>/Qff_0(nr)'
                                        *   '<S117>/Qff_0(nr)'
                                        *   '<S126>/Qff_0(nr)'
                                        *   '<S135>/Qff_0(nr)'
                                        */
  real_T k_cc;                         /* Variable: k_cc
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T n_c;                          /* Variable: n_c
                                        * Referenced by: '<S11>/Constant5'
                                        */
  real_T n_max;                        /* Variable: n_max
                                        * Referenced by:
                                        *   '<S90>/Qff_0(nr)'
                                        *   '<S99>/Qff_0(nr)'
                                        *   '<S108>/Qff_0(nr)'
                                        *   '<S117>/Qff_0(nr)'
                                        *   '<S126>/Qff_0(nr)'
                                        *   '<S135>/Qff_0(nr)'
                                        */
  real_T p_cc;                         /* Variable: p_cc
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T pwm_thr1_backward[6];         /* Variable: pwm_thr1_backward
                                        * Referenced by: '<S74>/negative thrust 1'
                                        */
  real_T pwm_thr1_forward[6];          /* Variable: pwm_thr1_forward
                                        * Referenced by: '<S74>/positive thrust 1'
                                        */
  real_T pwm_thr2_backward[6];         /* Variable: pwm_thr2_backward
                                        * Referenced by: '<S74>/negative thrust 2'
                                        */
  real_T pwm_thr2_forward[6];          /* Variable: pwm_thr2_forward
                                        * Referenced by: '<S74>/positive thrust 2'
                                        */
  real_T pwm_thr3_backward[6];         /* Variable: pwm_thr3_backward
                                        * Referenced by: '<S74>/negative thrust 3'
                                        */
  real_T pwm_thr3_forward[6];          /* Variable: pwm_thr3_forward
                                        * Referenced by: '<S74>/positive thrust 3'
                                        */
  real_T pwm_thr4_backward[6];         /* Variable: pwm_thr4_backward
                                        * Referenced by: '<S74>/negative thrust 4'
                                        */
  real_T pwm_thr4_forward[6];          /* Variable: pwm_thr4_forward
                                        * Referenced by: '<S74>/positive thrust 4'
                                        */
  real_T pwm_thr5_backward[6];         /* Variable: pwm_thr5_backward
                                        * Referenced by: '<S74>/negative thrust 5'
                                        */
  real_T pwm_thr5_forward[6];          /* Variable: pwm_thr5_forward
                                        * Referenced by: '<S74>/positive thrust 5'
                                        */
  real_T pwm_thr6_backward[6];         /* Variable: pwm_thr6_backward
                                        * Referenced by: '<S74>/negative thrust 6'
                                        */
  real_T pwm_thr6_forward[6];          /* Variable: pwm_thr6_forward
                                        * Referenced by: '<S74>/positive thrust 6'
                                        */
  real_T r_cc;                         /* Variable: r_cc
                                        * Referenced by: '<S11>/Constant3'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S93>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_p;/* Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                          * Referenced by: '<S102>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevSca_pl;/* Mask Parameter: DiscreteDerivative_ICPrevSca_pl
                                          * Referenced by: '<S111>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_f;/* Mask Parameter: DiscreteDerivative_ICPrevScal_f
                                          * Referenced by: '<S120>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_o;/* Mask Parameter: DiscreteDerivative_ICPrevScal_o
                                          * Referenced by: '<S129>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_n;/* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                          * Referenced by: '<S138>/UD'
                                          */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S25>/Out1'
                                        */
  real_T Delay_InitialCondition[144];  /* Expression: eye(12)
                                        * Referenced by: '<S30>/Delay'
                                        */
  real_T Constant_Value[72];           /* Expression: H
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Constant1_Value[36];          /* Expression: R
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T Delay1_InitialCondition[12];  /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S30>/Delay1'
                                        */
  real_T H_Gain[72];                   /* Expression: H
                                        * Referenced by: '<S30>/H'
                                        */
  real_T Memory2_X0[5];                /* Expression: [4.968, 4.965, 4.97, 4.975, 4.96]
                                        * Referenced by: '<S31>/Memory2'
                                        */
  real_T Gain_Gain;                    /* Expression: 2*1.4826
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T Memory3_X0[7];                /* Expression: [0, 0, 0, 0, 0, 0, 0]
                                        * Referenced by: '<S31>/Memory3'
                                        */
  real_T Delay_InitialCondition_g[144];/* Expression: eye(12)
                                        * Referenced by: '<S27>/Delay'
                                        */
  real_T Constant_Value_p[72];         /* Expression: H
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Constant1_Value_e[36];        /* Expression: R
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real_T Delay1_InitialCondition_h[12];/* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S27>/Delay1'
                                        */
  real_T H_Gain_i[72];                 /* Expression: H
                                        * Referenced by: '<S27>/H'
                                        */
  real_T Memory2_X0_d[5];              /* Expression: [4.968, 4.965, 4.97, 4.975, 4.96]
                                        * Referenced by: '<S32>/Memory2'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 2*1.4826
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Memory3_X0_o[7];              /* Expression: [0, 0, 0, 0, 0, 0, 0]
                                        * Referenced by: '<S32>/Memory3'
                                        */
  real_T Delay_InitialCondition_p[144];/* Expression: eye(12)
                                        * Referenced by: '<S28>/Delay'
                                        */
  real_T Constant_Value_f[72];         /* Expression: H
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T Constant1_Value_f[36];        /* Expression: R
                                        * Referenced by: '<S28>/Constant1'
                                        */
  real_T Delay1_InitialCondition_b[12];/* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S28>/Delay1'
                                        */
  real_T H_Gain_b[72];                 /* Expression: H
                                        * Referenced by: '<S28>/H'
                                        */
  real_T Memory2_X0_d5[5];             /* Expression: [4.968, 4.965, 4.97, 4.975, 4.96]
                                        * Referenced by: '<S33>/Memory2'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 2*1.4826
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T Memory3_X0_d[7];              /* Expression: [0, 0, 0, 0, 0, 0, 0]
                                        * Referenced by: '<S33>/Memory3'
                                        */
  real_T Delay_InitialCondition_d[144];/* Expression: eye(12)
                                        * Referenced by: '<S29>/Delay'
                                        */
  real_T Constant_Value_k[72];         /* Expression: H
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T Constant1_Value_g[36];        /* Expression: R
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T Delay1_InitialCondition_e[12];/* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]
                                        * Referenced by: '<S29>/Delay1'
                                        */
  real_T H_Gain_p[72];                 /* Expression: H
                                        * Referenced by: '<S29>/H'
                                        */
  real_T Memory2_X0_p[5];              /* Expression: [4.968, 4.965, 4.97, 4.975, 4.96]
                                        * Referenced by: '<S34>/Memory2'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 2*1.4826
                                        * Referenced by: '<S34>/Gain'
                                        */
  real_T Memory3_X0_p[7];              /* Expression: [0, 0, 0, 0, 0, 0, 0]
                                        * Referenced by: '<S34>/Memory3'
                                        */
  real_T A_Gain[144];                  /* Expression: A
                                        * Referenced by: '<S27>/A'
                                        */
  real_T Constant6_Value[144];         /* Expression: A
                                        * Referenced by: '<S27>/Constant6'
                                        */
  real_T Identity_Value[144];          /* Expression: eye(12)
                                        * Referenced by: '<S27>/Identity'
                                        */
  real_T Constant3_Value[72];          /* Expression: H
                                        * Referenced by: '<S27>/Constant3'
                                        */
  real_T Constant4_Value[36];          /* Expression: R
                                        * Referenced by: '<S27>/Constant4'
                                        */
  real_T Constant5_Value[144];         /* Expression: Q
                                        * Referenced by: '<S27>/Constant5'
                                        */
  real_T A_Gain_n[144];                /* Expression: A
                                        * Referenced by: '<S28>/A'
                                        */
  real_T Constant6_Value_c[144];       /* Expression: A
                                        * Referenced by: '<S28>/Constant6'
                                        */
  real_T Identity_Value_h[144];        /* Expression: eye(12)
                                        * Referenced by: '<S28>/Identity'
                                        */
  real_T Constant3_Value_j[72];        /* Expression: H
                                        * Referenced by: '<S28>/Constant3'
                                        */
  real_T Constant4_Value_k[36];        /* Expression: R
                                        * Referenced by: '<S28>/Constant4'
                                        */
  real_T Constant5_Value_n[144];       /* Expression: Q
                                        * Referenced by: '<S28>/Constant5'
                                        */
  real_T A_Gain_k[144];                /* Expression: A
                                        * Referenced by: '<S29>/A'
                                        */
  real_T Constant6_Value_a[144];       /* Expression: A
                                        * Referenced by: '<S29>/Constant6'
                                        */
  real_T Identity_Value_f[144];        /* Expression: eye(12)
                                        * Referenced by: '<S29>/Identity'
                                        */
  real_T Constant3_Value_o[72];        /* Expression: H
                                        * Referenced by: '<S29>/Constant3'
                                        */
  real_T Constant4_Value_i[36];        /* Expression: R
                                        * Referenced by: '<S29>/Constant4'
                                        */
  real_T Constant5_Value_m[144];       /* Expression: Q
                                        * Referenced by: '<S29>/Constant5'
                                        */
  real_T A_Gain_j[144];                /* Expression: A
                                        * Referenced by: '<S30>/A'
                                        */
  real_T Constant6_Value_j[144];       /* Expression: A
                                        * Referenced by: '<S30>/Constant6'
                                        */
  real_T Identity_Value_h4[144];       /* Expression: eye(12)
                                        * Referenced by: '<S30>/Identity'
                                        */
  real_T Constant3_Value_b[72];        /* Expression: H
                                        * Referenced by: '<S30>/Constant3'
                                        */
  real_T Constant4_Value_iu[36];       /* Expression: R
                                        * Referenced by: '<S30>/Constant4'
                                        */
  real_T Constant5_Value_nj[144];      /* Expression: Q
                                        * Referenced by: '<S30>/Constant5'
                                        */
  real_T K_p_x_P1;                     /* Expression: width
                                        * Referenced by: '<S44>/K_p_x'
                                        */
  real_T K_p_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S44>/K_p_x'
                                        */
  real_T K_p_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S44>/K_p_x'
                                        */
  real_T K_p_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S44>/K_p_x'
                                        */
  real_T K_p_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S44>/K_p_x'
                                        */
  real_T K_p_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S44>/K_p_x'
                                        */
  real_T K_p_y_P1;                     /* Expression: width
                                        * Referenced by: '<S44>/K_p_y'
                                        */
  real_T K_p_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S44>/K_p_y'
                                        */
  real_T K_p_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S44>/K_p_y'
                                        */
  real_T K_p_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S44>/K_p_y'
                                        */
  real_T K_p_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S44>/K_p_y'
                                        */
  real_T K_p_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S44>/K_p_y'
                                        */
  real_T K_p_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S44>/K_p_psi'
                                        */
  real_T K_p_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S44>/K_p_psi'
                                        */
  real_T K_p_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S44>/K_p_psi'
                                        */
  real_T K_p_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S44>/K_p_psi'
                                        */
  real_T K_p_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S44>/K_p_psi'
                                        */
  real_T K_p_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S44>/K_p_psi'
                                        */
  real_T K_i_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S44>/K_i_psi'
                                        */
  real_T K_i_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S44>/K_i_psi'
                                        */
  real_T K_i_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S44>/K_i_psi'
                                        */
  real_T K_i_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S44>/K_i_psi'
                                        */
  real_T K_i_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S44>/K_i_psi'
                                        */
  real_T K_i_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S44>/K_i_psi'
                                        */
  real_T K_i_x_P1;                     /* Expression: width
                                        * Referenced by: '<S44>/K_i_x'
                                        */
  real_T K_i_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S44>/K_i_x'
                                        */
  real_T K_i_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S44>/K_i_x'
                                        */
  real_T K_i_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S44>/K_i_x'
                                        */
  real_T K_i_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S44>/K_i_x'
                                        */
  real_T K_i_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S44>/K_i_x'
                                        */
  real_T K_i_y_P1;                     /* Expression: width
                                        * Referenced by: '<S44>/K_i_y'
                                        */
  real_T K_i_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S44>/K_i_y'
                                        */
  real_T K_i_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S44>/K_i_y'
                                        */
  real_T K_i_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S44>/K_i_y'
                                        */
  real_T K_i_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S44>/K_i_y'
                                        */
  real_T K_i_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S44>/K_i_y'
                                        */
  real_T K_d_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S44>/K_d_psi'
                                        */
  real_T K_d_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S44>/K_d_psi'
                                        */
  real_T K_d_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S44>/K_d_psi'
                                        */
  real_T K_d_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S44>/K_d_psi'
                                        */
  real_T K_d_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S44>/K_d_psi'
                                        */
  real_T K_d_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S44>/K_d_psi'
                                        */
  real_T K_d_x_P1;                     /* Expression: width
                                        * Referenced by: '<S44>/K_d_x'
                                        */
  real_T K_d_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S44>/K_d_x'
                                        */
  real_T K_d_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S44>/K_d_x'
                                        */
  real_T K_d_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S44>/K_d_x'
                                        */
  real_T K_d_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S44>/K_d_x'
                                        */
  real_T K_d_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S44>/K_d_x'
                                        */
  real_T K_d_y_P1;                     /* Expression: width
                                        * Referenced by: '<S44>/K_d_y'
                                        */
  real_T K_d_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S44>/K_d_y'
                                        */
  real_T K_d_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S44>/K_d_y'
                                        */
  real_T K_d_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S44>/K_d_y'
                                        */
  real_T K_d_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S44>/K_d_y'
                                        */
  real_T K_d_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S44>/K_d_y'
                                        */
  real_T x_m_P1;                       /* Expression: width
                                        * Referenced by: '<S8>/x_m'
                                        */
  real_T x_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S8>/x_m'
                                        */
  real_T x_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S8>/x_m'
                                        */
  real_T x_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S8>/x_m'
                                        */
  real_T x_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S8>/x_m'
                                        */
  real_T x_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S8>/x_m'
                                        */
  real_T y_m_P1;                       /* Expression: width
                                        * Referenced by: '<S8>/y_m'
                                        */
  real_T y_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S8>/y_m'
                                        */
  real_T y_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S8>/y_m'
                                        */
  real_T y_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S8>/y_m'
                                        */
  real_T y_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S8>/y_m'
                                        */
  real_T y_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S8>/y_m'
                                        */
  real_T psi_m_P1;                     /* Expression: width
                                        * Referenced by: '<S8>/psi_m'
                                        */
  real_T psi_m_P2;                     /* Expression: dtype
                                        * Referenced by: '<S8>/psi_m'
                                        */
  real_T psi_m_P3;                     /* Expression: portnum
                                        * Referenced by: '<S8>/psi_m'
                                        */
  real_T psi_m_P4;                     /* Expression: stime
                                        * Referenced by: '<S8>/psi_m'
                                        */
  real_T psi_m_P5;                     /* Expression: stype
                                        * Referenced by: '<S8>/psi_m'
                                        */
  real_T psi_m_P6;                     /* Expression: btype
                                        * Referenced by: '<S8>/psi_m'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1e10
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1e10
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Gain_Gain_p;                  /* Expression: pi
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Constant_Value_i;             /* Expression: 2*pi
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T reset_P1;                     /* Expression: width
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P2;                     /* Expression: dtype
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P3;                     /* Expression: portnum
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P4;                     /* Expression: stime
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P5;                     /* Expression: stype
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P6;                     /* Expression: btype
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T Constant6_Value_m;            /* Expression: 1
                                        * Referenced by: '<S46>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S46>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S46>/Constant8'
                                        */
  real_T w_d_x_P1;                     /* Expression: width
                                        * Referenced by: '<S45>/w_d_x'
                                        */
  real_T w_d_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S45>/w_d_x'
                                        */
  real_T w_d_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S45>/w_d_x'
                                        */
  real_T w_d_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S45>/w_d_x'
                                        */
  real_T w_d_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S45>/w_d_x'
                                        */
  real_T w_d_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S45>/w_d_x'
                                        */
  real_T w_d_y_P1;                     /* Expression: width
                                        * Referenced by: '<S45>/w_d_y'
                                        */
  real_T w_d_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S45>/w_d_y'
                                        */
  real_T w_d_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S45>/w_d_y'
                                        */
  real_T w_d_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S45>/w_d_y'
                                        */
  real_T w_d_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S45>/w_d_y'
                                        */
  real_T w_d_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S45>/w_d_y'
                                        */
  real_T w_d_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S45>/w_d_psi'
                                        */
  real_T w_d_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S45>/w_d_psi'
                                        */
  real_T w_d_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S45>/w_d_psi'
                                        */
  real_T w_d_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S45>/w_d_psi'
                                        */
  real_T w_d_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S45>/w_d_psi'
                                        */
  real_T w_d_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S45>/w_d_psi'
                                        */
  real_T zeta_psi_P1;                  /* Expression: width
                                        * Referenced by: '<S45>/zeta_psi'
                                        */
  real_T zeta_psi_P2;                  /* Expression: dtype
                                        * Referenced by: '<S45>/zeta_psi'
                                        */
  real_T zeta_psi_P3;                  /* Expression: portnum
                                        * Referenced by: '<S45>/zeta_psi'
                                        */
  real_T zeta_psi_P4;                  /* Expression: stime
                                        * Referenced by: '<S45>/zeta_psi'
                                        */
  real_T zeta_psi_P5;                  /* Expression: stype
                                        * Referenced by: '<S45>/zeta_psi'
                                        */
  real_T zeta_psi_P6;                  /* Expression: btype
                                        * Referenced by: '<S45>/zeta_psi'
                                        */
  real_T zeta_x_P1;                    /* Expression: width
                                        * Referenced by: '<S45>/zeta_x'
                                        */
  real_T zeta_x_P2;                    /* Expression: dtype
                                        * Referenced by: '<S45>/zeta_x'
                                        */
  real_T zeta_x_P3;                    /* Expression: portnum
                                        * Referenced by: '<S45>/zeta_x'
                                        */
  real_T zeta_x_P4;                    /* Expression: stime
                                        * Referenced by: '<S45>/zeta_x'
                                        */
  real_T zeta_x_P5;                    /* Expression: stype
                                        * Referenced by: '<S45>/zeta_x'
                                        */
  real_T zeta_x_P6;                    /* Expression: btype
                                        * Referenced by: '<S45>/zeta_x'
                                        */
  real_T zeta_y_P1;                    /* Expression: width
                                        * Referenced by: '<S45>/zeta_y'
                                        */
  real_T zeta_y_P2;                    /* Expression: dtype
                                        * Referenced by: '<S45>/zeta_y'
                                        */
  real_T zeta_y_P3;                    /* Expression: portnum
                                        * Referenced by: '<S45>/zeta_y'
                                        */
  real_T zeta_y_P4;                    /* Expression: stime
                                        * Referenced by: '<S45>/zeta_y'
                                        */
  real_T zeta_y_P5;                    /* Expression: stype
                                        * Referenced by: '<S45>/zeta_y'
                                        */
  real_T zeta_y_P6;                    /* Expression: btype
                                        * Referenced by: '<S45>/zeta_y'
                                        */
  real_T psi_ref_P1;                   /* Expression: width
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  real_T psi_ref_P2;                   /* Expression: dtype
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  real_T psi_ref_P3;                   /* Expression: portnum
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  real_T psi_ref_P4;                   /* Expression: stime
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  real_T psi_ref_P5;                   /* Expression: stype
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  real_T psi_ref_P6;                   /* Expression: btype
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  real_T x_ref_P1;                     /* Expression: width
                                        * Referenced by: '<S5>/x_ref'
                                        */
  real_T x_ref_P2;                     /* Expression: dtype
                                        * Referenced by: '<S5>/x_ref'
                                        */
  real_T x_ref_P3;                     /* Expression: portnum
                                        * Referenced by: '<S5>/x_ref'
                                        */
  real_T x_ref_P4;                     /* Expression: stime
                                        * Referenced by: '<S5>/x_ref'
                                        */
  real_T x_ref_P5;                     /* Expression: stype
                                        * Referenced by: '<S5>/x_ref'
                                        */
  real_T x_ref_P6;                     /* Expression: btype
                                        * Referenced by: '<S5>/x_ref'
                                        */
  real_T y_ref_P1;                     /* Expression: width
                                        * Referenced by: '<S5>/y_ref'
                                        */
  real_T y_ref_P2;                     /* Expression: dtype
                                        * Referenced by: '<S5>/y_ref'
                                        */
  real_T y_ref_P3;                     /* Expression: portnum
                                        * Referenced by: '<S5>/y_ref'
                                        */
  real_T y_ref_P4;                     /* Expression: stime
                                        * Referenced by: '<S5>/y_ref'
                                        */
  real_T y_ref_P5;                     /* Expression: stype
                                        * Referenced by: '<S5>/y_ref'
                                        */
  real_T y_ref_P6;                     /* Expression: btype
                                        * Referenced by: '<S5>/y_ref'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 1e10
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -1e10
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T Gain_Gain_a;                  /* Expression: pi
                                        * Referenced by: '<S20>/Gain'
                                        */
  real_T Constant_Value_j;             /* Expression: 2*pi
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1e10
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -1e10
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Gain_Gain_ag;                 /* Expression: pi
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Constant_Value_l;             /* Expression: 2*pi
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S14>/Integrator'
                                        */
  real_T Integrator1_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S19>/Integrator3'
                                        */
  real_T thr_angle_1_P1;               /* Expression: width
                                        * Referenced by: '<S13>/thr_angle_1'
                                        */
  real_T thr_angle_1_P2;               /* Expression: dtype
                                        * Referenced by: '<S13>/thr_angle_1'
                                        */
  real_T thr_angle_1_P3;               /* Expression: portnum
                                        * Referenced by: '<S13>/thr_angle_1'
                                        */
  real_T thr_angle_1_P4;               /* Expression: stime
                                        * Referenced by: '<S13>/thr_angle_1'
                                        */
  real_T thr_angle_1_P5;               /* Expression: stype
                                        * Referenced by: '<S13>/thr_angle_1'
                                        */
  real_T thr_angle_1_P6;               /* Expression: btype
                                        * Referenced by: '<S13>/thr_angle_1'
                                        */
  real_T thr_angle_2_P1;               /* Expression: width
                                        * Referenced by: '<S13>/thr_angle_2'
                                        */
  real_T thr_angle_2_P2;               /* Expression: dtype
                                        * Referenced by: '<S13>/thr_angle_2'
                                        */
  real_T thr_angle_2_P3;               /* Expression: portnum
                                        * Referenced by: '<S13>/thr_angle_2'
                                        */
  real_T thr_angle_2_P4;               /* Expression: stime
                                        * Referenced by: '<S13>/thr_angle_2'
                                        */
  real_T thr_angle_2_P5;               /* Expression: stype
                                        * Referenced by: '<S13>/thr_angle_2'
                                        */
  real_T thr_angle_2_P6;               /* Expression: btype
                                        * Referenced by: '<S13>/thr_angle_2'
                                        */
  real_T thr_angle_3_P1;               /* Expression: width
                                        * Referenced by: '<S13>/thr_angle_3'
                                        */
  real_T thr_angle_3_P2;               /* Expression: dtype
                                        * Referenced by: '<S13>/thr_angle_3'
                                        */
  real_T thr_angle_3_P3;               /* Expression: portnum
                                        * Referenced by: '<S13>/thr_angle_3'
                                        */
  real_T thr_angle_3_P4;               /* Expression: stime
                                        * Referenced by: '<S13>/thr_angle_3'
                                        */
  real_T thr_angle_3_P5;               /* Expression: stype
                                        * Referenced by: '<S13>/thr_angle_3'
                                        */
  real_T thr_angle_3_P6;               /* Expression: btype
                                        * Referenced by: '<S13>/thr_angle_3'
                                        */
  real_T thr_angle_4_P1;               /* Expression: width
                                        * Referenced by: '<S13>/thr_angle_4'
                                        */
  real_T thr_angle_4_P2;               /* Expression: dtype
                                        * Referenced by: '<S13>/thr_angle_4'
                                        */
  real_T thr_angle_4_P3;               /* Expression: portnum
                                        * Referenced by: '<S13>/thr_angle_4'
                                        */
  real_T thr_angle_4_P4;               /* Expression: stime
                                        * Referenced by: '<S13>/thr_angle_4'
                                        */
  real_T thr_angle_4_P5;               /* Expression: stype
                                        * Referenced by: '<S13>/thr_angle_4'
                                        */
  real_T thr_angle_4_P6;               /* Expression: btype
                                        * Referenced by: '<S13>/thr_angle_4'
                                        */
  real_T thr_angle_5_P1;               /* Expression: width
                                        * Referenced by: '<S13>/thr_angle_5'
                                        */
  real_T thr_angle_5_P2;               /* Expression: dtype
                                        * Referenced by: '<S13>/thr_angle_5'
                                        */
  real_T thr_angle_5_P3;               /* Expression: portnum
                                        * Referenced by: '<S13>/thr_angle_5'
                                        */
  real_T thr_angle_5_P4;               /* Expression: stime
                                        * Referenced by: '<S13>/thr_angle_5'
                                        */
  real_T thr_angle_5_P5;               /* Expression: stype
                                        * Referenced by: '<S13>/thr_angle_5'
                                        */
  real_T thr_angle_5_P6;               /* Expression: btype
                                        * Referenced by: '<S13>/thr_angle_5'
                                        */
  real_T thr_angle_6_P1;               /* Expression: width
                                        * Referenced by: '<S13>/thr_angle_6'
                                        */
  real_T thr_angle_6_P2;               /* Expression: dtype
                                        * Referenced by: '<S13>/thr_angle_6'
                                        */
  real_T thr_angle_6_P3;               /* Expression: portnum
                                        * Referenced by: '<S13>/thr_angle_6'
                                        */
  real_T thr_angle_6_P4;               /* Expression: stime
                                        * Referenced by: '<S13>/thr_angle_6'
                                        */
  real_T thr_angle_6_P5;               /* Expression: stype
                                        * Referenced by: '<S13>/thr_angle_6'
                                        */
  real_T thr_angle_6_P6;               /* Expression: btype
                                        * Referenced by: '<S13>/thr_angle_6'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180/pi
                                        * Referenced by: '<S68>/Gain'
                                        */
  real_T XpositionThruster_Value[6];   /* Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
                                        * Referenced by: '<S10>/X-position Thruster'
                                        */
  real_T YpositionThruster_Value[6];   /* Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
                                        * Referenced by: '<S10>/Y-position Thruster'
                                        */
  real_T reset_P1_m;                   /* Expression: width
                                        * Referenced by: '<S10>/reset'
                                        */
  real_T reset_P2_f;                   /* Expression: dtype
                                        * Referenced by: '<S10>/reset'
                                        */
  real_T reset_P3_k;                   /* Expression: portnum
                                        * Referenced by: '<S10>/reset'
                                        */
  real_T reset_P4_e;                   /* Expression: stime
                                        * Referenced by: '<S10>/reset'
                                        */
  real_T reset_P5_f;                   /* Expression: stype
                                        * Referenced by: '<S10>/reset'
                                        */
  real_T reset_P6_h;                   /* Expression: btype
                                        * Referenced by: '<S10>/reset'
                                        */
  real_T Angle_controller_P1;          /* Expression: width
                                        * Referenced by: '<S10>/Angle_controller'
                                        */
  real_T Angle_controller_P2;          /* Expression: dtype
                                        * Referenced by: '<S10>/Angle_controller'
                                        */
  real_T Angle_controller_P3;          /* Expression: portnum
                                        * Referenced by: '<S10>/Angle_controller'
                                        */
  real_T Angle_controller_P4;          /* Expression: stime
                                        * Referenced by: '<S10>/Angle_controller'
                                        */
  real_T Angle_controller_P5;          /* Expression: stype
                                        * Referenced by: '<S10>/Angle_controller'
                                        */
  real_T Angle_controller_P6;          /* Expression: btype
                                        * Referenced by: '<S10>/Angle_controller'
                                        */
  real_T constantangle_Value[6];       /* Expression: [Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)]
                                        * Referenced by: '<S10>/constant angle'
                                        */
  real_T ChoosingFixedAzimuthangle_Thres;/* Expression: 1
                                          * Referenced by: '<S10>/Choosing Fixed // Azimuth angle'
                                          */
  real_T Saturation1_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S73>/Saturation 1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S73>/Saturation 1'
                                        */
  real_T alpha_1_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  real_T alpha_1_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  real_T alpha_1_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  real_T alpha_1_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  real_T alpha_1_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  real_T alpha_1_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  real_T reset_P1_e;                   /* Expression: width
                                        * Referenced by: '<S89>/reset'
                                        */
  real_T reset_P2_l;                   /* Expression: dtype
                                        * Referenced by: '<S89>/reset'
                                        */
  real_T reset_P3_h;                   /* Expression: portnum
                                        * Referenced by: '<S89>/reset'
                                        */
  real_T reset_P4_j;                   /* Expression: stime
                                        * Referenced by: '<S89>/reset'
                                        */
  real_T reset_P5_i;                   /* Expression: stype
                                        * Referenced by: '<S89>/reset'
                                        */
  real_T reset_P6_f;                   /* Expression: btype
                                        * Referenced by: '<S89>/reset'
                                        */
  real_T Integrator_IC_f;              /* Expression: 0
                                        * Referenced by: '<S89>/Integrator'
                                        */
  real_T Lossesplaceholder_Value;      /* Expression: 0
                                        * Referenced by: '<S75>/Losses (placeholder)'
                                        */
  real_T reset_P1_k;                   /* Expression: width
                                        * Referenced by: '<S98>/reset'
                                        */
  real_T reset_P2_n;                   /* Expression: dtype
                                        * Referenced by: '<S98>/reset'
                                        */
  real_T reset_P3_a;                   /* Expression: portnum
                                        * Referenced by: '<S98>/reset'
                                        */
  real_T reset_P4_eg;                  /* Expression: stime
                                        * Referenced by: '<S98>/reset'
                                        */
  real_T reset_P5_m;                   /* Expression: stype
                                        * Referenced by: '<S98>/reset'
                                        */
  real_T reset_P6_c;                   /* Expression: btype
                                        * Referenced by: '<S98>/reset'
                                        */
  real_T Integrator_IC_fg;             /* Expression: 0
                                        * Referenced by: '<S98>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_k;    /* Expression: 0
                                        * Referenced by: '<S76>/Losses (placeholder)'
                                        */
  real_T reset_P1_m2;                  /* Expression: width
                                        * Referenced by: '<S107>/reset'
                                        */
  real_T reset_P2_j;                   /* Expression: dtype
                                        * Referenced by: '<S107>/reset'
                                        */
  real_T reset_P3_i;                   /* Expression: portnum
                                        * Referenced by: '<S107>/reset'
                                        */
  real_T reset_P4_h;                   /* Expression: stime
                                        * Referenced by: '<S107>/reset'
                                        */
  real_T reset_P5_a;                   /* Expression: stype
                                        * Referenced by: '<S107>/reset'
                                        */
  real_T reset_P6_l;                   /* Expression: btype
                                        * Referenced by: '<S107>/reset'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S107>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_n;    /* Expression: 0
                                        * Referenced by: '<S77>/Losses (placeholder)'
                                        */
  real_T reset_P1_kz;                  /* Expression: width
                                        * Referenced by: '<S116>/reset'
                                        */
  real_T reset_P2_ng;                  /* Expression: dtype
                                        * Referenced by: '<S116>/reset'
                                        */
  real_T reset_P3_e;                   /* Expression: portnum
                                        * Referenced by: '<S116>/reset'
                                        */
  real_T reset_P4_b;                   /* Expression: stime
                                        * Referenced by: '<S116>/reset'
                                        */
  real_T reset_P5_g;                   /* Expression: stype
                                        * Referenced by: '<S116>/reset'
                                        */
  real_T reset_P6_n;                   /* Expression: btype
                                        * Referenced by: '<S116>/reset'
                                        */
  real_T Integrator_IC_fv;             /* Expression: 0
                                        * Referenced by: '<S116>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_d;    /* Expression: 0
                                        * Referenced by: '<S78>/Losses (placeholder)'
                                        */
  real_T reset_P1_j;                   /* Expression: width
                                        * Referenced by: '<S125>/reset'
                                        */
  real_T reset_P2_m;                   /* Expression: dtype
                                        * Referenced by: '<S125>/reset'
                                        */
  real_T reset_P3_p;                   /* Expression: portnum
                                        * Referenced by: '<S125>/reset'
                                        */
  real_T reset_P4_k;                   /* Expression: stime
                                        * Referenced by: '<S125>/reset'
                                        */
  real_T reset_P5_l;                   /* Expression: stype
                                        * Referenced by: '<S125>/reset'
                                        */
  real_T reset_P6_g;                   /* Expression: btype
                                        * Referenced by: '<S125>/reset'
                                        */
  real_T Integrator_IC_l;              /* Expression: 0
                                        * Referenced by: '<S125>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_f;    /* Expression: 0
                                        * Referenced by: '<S79>/Losses (placeholder)'
                                        */
  real_T reset_P1_d;                   /* Expression: width
                                        * Referenced by: '<S134>/reset'
                                        */
  real_T reset_P2_g;                   /* Expression: dtype
                                        * Referenced by: '<S134>/reset'
                                        */
  real_T reset_P3_ic;                  /* Expression: portnum
                                        * Referenced by: '<S134>/reset'
                                        */
  real_T reset_P4_o;                   /* Expression: stime
                                        * Referenced by: '<S134>/reset'
                                        */
  real_T reset_P5_ll;                  /* Expression: stype
                                        * Referenced by: '<S134>/reset'
                                        */
  real_T reset_P6_i;                   /* Expression: btype
                                        * Referenced by: '<S134>/reset'
                                        */
  real_T Integrator_IC_li;             /* Expression: 0
                                        * Referenced by: '<S134>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_h;    /* Expression: 0
                                        * Referenced by: '<S80>/Losses (placeholder)'
                                        */
  real_T rpm1_P1;                      /* Expression: width
                                        * Referenced by: '<S74>/rpm1 '
                                        */
  real_T rpm1_P2;                      /* Expression: dtype
                                        * Referenced by: '<S74>/rpm1 '
                                        */
  real_T rpm1_P3;                      /* Expression: portnum
                                        * Referenced by: '<S74>/rpm1 '
                                        */
  real_T rpm1_P4;                      /* Expression: stime
                                        * Referenced by: '<S74>/rpm1 '
                                        */
  real_T rpm1_P5;                      /* Expression: stype
                                        * Referenced by: '<S74>/rpm1 '
                                        */
  real_T rpm1_P6;                      /* Expression: btype
                                        * Referenced by: '<S74>/rpm1 '
                                        */
  real_T Gain_Gain_d;                  /* Expression: 1/60
                                        * Referenced by: '<S74>/Gain'
                                        */
  real_T rpm2_P1;                      /* Expression: width
                                        * Referenced by: '<S74>/rpm2'
                                        */
  real_T rpm2_P2;                      /* Expression: dtype
                                        * Referenced by: '<S74>/rpm2'
                                        */
  real_T rpm2_P3;                      /* Expression: portnum
                                        * Referenced by: '<S74>/rpm2'
                                        */
  real_T rpm2_P4;                      /* Expression: stime
                                        * Referenced by: '<S74>/rpm2'
                                        */
  real_T rpm2_P5;                      /* Expression: stype
                                        * Referenced by: '<S74>/rpm2'
                                        */
  real_T rpm2_P6;                      /* Expression: btype
                                        * Referenced by: '<S74>/rpm2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/60
                                        * Referenced by: '<S74>/Gain1'
                                        */
  real_T rpm3_P1;                      /* Expression: width
                                        * Referenced by: '<S74>/rpm3'
                                        */
  real_T rpm3_P2;                      /* Expression: dtype
                                        * Referenced by: '<S74>/rpm3'
                                        */
  real_T rpm3_P3;                      /* Expression: portnum
                                        * Referenced by: '<S74>/rpm3'
                                        */
  real_T rpm3_P4;                      /* Expression: stime
                                        * Referenced by: '<S74>/rpm3'
                                        */
  real_T rpm3_P5;                      /* Expression: stype
                                        * Referenced by: '<S74>/rpm3'
                                        */
  real_T rpm3_P6;                      /* Expression: btype
                                        * Referenced by: '<S74>/rpm3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/60
                                        * Referenced by: '<S74>/Gain2'
                                        */
  real_T rpm4_P1;                      /* Expression: width
                                        * Referenced by: '<S74>/rpm4'
                                        */
  real_T rpm4_P2;                      /* Expression: dtype
                                        * Referenced by: '<S74>/rpm4'
                                        */
  real_T rpm4_P3;                      /* Expression: portnum
                                        * Referenced by: '<S74>/rpm4'
                                        */
  real_T rpm4_P4;                      /* Expression: stime
                                        * Referenced by: '<S74>/rpm4'
                                        */
  real_T rpm4_P5;                      /* Expression: stype
                                        * Referenced by: '<S74>/rpm4'
                                        */
  real_T rpm4_P6;                      /* Expression: btype
                                        * Referenced by: '<S74>/rpm4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/60
                                        * Referenced by: '<S74>/Gain3'
                                        */
  real_T rpm5_P1;                      /* Expression: width
                                        * Referenced by: '<S74>/rpm5'
                                        */
  real_T rpm5_P2;                      /* Expression: dtype
                                        * Referenced by: '<S74>/rpm5'
                                        */
  real_T rpm5_P3;                      /* Expression: portnum
                                        * Referenced by: '<S74>/rpm5'
                                        */
  real_T rpm5_P4;                      /* Expression: stime
                                        * Referenced by: '<S74>/rpm5'
                                        */
  real_T rpm5_P5;                      /* Expression: stype
                                        * Referenced by: '<S74>/rpm5'
                                        */
  real_T rpm5_P6;                      /* Expression: btype
                                        * Referenced by: '<S74>/rpm5'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/60
                                        * Referenced by: '<S74>/Gain4'
                                        */
  real_T rpm6_P1;                      /* Expression: width
                                        * Referenced by: '<S74>/rpm6'
                                        */
  real_T rpm6_P2;                      /* Expression: dtype
                                        * Referenced by: '<S74>/rpm6'
                                        */
  real_T rpm6_P3;                      /* Expression: portnum
                                        * Referenced by: '<S74>/rpm6'
                                        */
  real_T rpm6_P4;                      /* Expression: stime
                                        * Referenced by: '<S74>/rpm6'
                                        */
  real_T rpm6_P5;                      /* Expression: stype
                                        * Referenced by: '<S74>/rpm6'
                                        */
  real_T rpm6_P6;                      /* Expression: btype
                                        * Referenced by: '<S74>/rpm6'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/60
                                        * Referenced by: '<S74>/Gain5'
                                        */
  real_T Saturation8_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S74>/Saturation 8'
                                        */
  real_T Saturation9_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S74>/Saturation 9'
                                        */
  real_T pwm_2_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  real_T pwm_2_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  real_T pwm_2_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  real_T pwm_2_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  real_T pwm_2_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  real_T pwm_2_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  real_T Saturation10_LowerSat;        /* Expression: 0
                                        * Referenced by: '<S74>/Saturation 10'
                                        */
  real_T Saturation11_UpperSat;        /* Expression: 0
                                        * Referenced by: '<S74>/Saturation 11'
                                        */
  real_T pwm_3_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/pwm_3'
                                        */
  real_T pwm_3_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_3'
                                        */
  real_T pwm_3_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_3'
                                        */
  real_T pwm_3_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/pwm_3'
                                        */
  real_T pwm_3_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/pwm_3'
                                        */
  real_T pwm_3_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/pwm_3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S74>/Saturation 3'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S74>/Saturation 4'
                                        */
  real_T pwm_4_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  real_T pwm_4_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  real_T pwm_4_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  real_T pwm_4_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  real_T pwm_4_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  real_T pwm_4_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S74>/Saturation 5'
                                        */
  real_T Saturation6_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S74>/Saturation 6'
                                        */
  real_T pwm_5_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/pwm_5'
                                        */
  real_T pwm_5_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_5'
                                        */
  real_T pwm_5_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_5'
                                        */
  real_T pwm_5_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/pwm_5'
                                        */
  real_T pwm_5_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/pwm_5'
                                        */
  real_T pwm_5_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/pwm_5'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S73>/Saturation 2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S73>/Saturation 2'
                                        */
  real_T alpha_2_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  real_T alpha_2_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  real_T alpha_2_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  real_T alpha_2_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  real_T alpha_2_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  real_T alpha_2_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  real_T Saturation12_LowerSat;        /* Expression: 0
                                        * Referenced by: '<S74>/Saturation 12'
                                        */
  real_T Saturation13_UpperSat;        /* Expression: 0
                                        * Referenced by: '<S74>/Saturation 13'
                                        */
  real_T pwm_6_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  real_T pwm_6_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  real_T pwm_6_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  real_T pwm_6_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  real_T pwm_6_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  real_T pwm_6_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S73>/Saturation 3'
                                        */
  real_T Saturation3_LowerSat_f;       /* Expression: -pi
                                        * Referenced by: '<S73>/Saturation 3'
                                        */
  real_T alpha_3_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  real_T alpha_3_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  real_T alpha_3_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  real_T alpha_3_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  real_T alpha_3_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  real_T alpha_3_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  real_T Saturation4_UpperSat_p;       /* Expression: pi
                                        * Referenced by: '<S73>/Saturation 4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S73>/Saturation 4'
                                        */
  real_T alpha_4_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  real_T alpha_4_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  real_T alpha_4_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  real_T alpha_4_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  real_T alpha_4_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  real_T alpha_4_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  real_T Saturation5_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S73>/Saturation 5'
                                        */
  real_T Saturation5_LowerSat_h;       /* Expression: -pi
                                        * Referenced by: '<S73>/Saturation 5'
                                        */
  real_T alpha_5_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  real_T alpha_5_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  real_T alpha_5_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  real_T alpha_5_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  real_T alpha_5_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  real_T alpha_5_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  real_T Saturation6_UpperSat_g;       /* Expression: pi
                                        * Referenced by: '<S73>/Saturation 6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S73>/Saturation 6'
                                        */
  real_T alpha_6_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  real_T alpha_6_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  real_T alpha_6_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  real_T alpha_6_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  real_T alpha_6_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  real_T alpha_6_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  real_T u_1_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/u_1'
                                        */
  real_T u_1_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/u_1'
                                        */
  real_T u_1_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/u_1'
                                        */
  real_T u_1_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/u_1'
                                        */
  real_T u_1_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/u_1'
                                        */
  real_T u_1_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/u_1'
                                        */
  real_T u_4_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/u_4'
                                        */
  real_T u_4_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/u_4'
                                        */
  real_T u_4_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/u_4'
                                        */
  real_T u_4_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/u_4'
                                        */
  real_T u_4_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/u_4'
                                        */
  real_T u_4_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/u_4'
                                        */
  real_T u_5_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/u_5'
                                        */
  real_T u_5_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/u_5'
                                        */
  real_T u_5_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/u_5'
                                        */
  real_T u_5_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/u_5'
                                        */
  real_T u_5_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/u_5'
                                        */
  real_T u_5_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/u_5'
                                        */
  real_T u_6_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/u_6'
                                        */
  real_T u_6_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/u_6'
                                        */
  real_T u_6_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/u_6'
                                        */
  real_T u_6_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/u_6'
                                        */
  real_T u_6_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/u_6'
                                        */
  real_T u_6_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/u_6'
                                        */
  real_T u_2_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/u_2'
                                        */
  real_T u_2_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/u_2'
                                        */
  real_T u_2_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/u_2'
                                        */
  real_T u_2_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/u_2'
                                        */
  real_T u_2_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/u_2'
                                        */
  real_T u_2_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/u_2'
                                        */
  real_T u_3_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/u_3'
                                        */
  real_T u_3_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/u_3'
                                        */
  real_T u_3_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/u_3'
                                        */
  real_T u_3_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/u_3'
                                        */
  real_T u_3_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/u_3'
                                        */
  real_T u_3_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/u_3'
                                        */
  real_T Saturation1_LowerSat_h;       /* Expression: 0
                                        * Referenced by: '<S74>/Saturation 1'
                                        */
  real_T Saturation2_UpperSat_p;       /* Expression: 0
                                        * Referenced by: '<S74>/Saturation 2'
                                        */
  real_T pwm_1_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  real_T pwm_1_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  real_T pwm_1_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  real_T pwm_1_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  real_T pwm_1_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  real_T pwm_1_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  real_T x_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S63>/x_hat'
                                        */
  real_T x_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S63>/x_hat'
                                        */
  real_T x_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S63>/x_hat'
                                        */
  real_T x_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S63>/x_hat'
                                        */
  real_T x_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S63>/x_hat'
                                        */
  real_T x_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S63>/x_hat'
                                        */
  real_T y_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S63>/y_hat'
                                        */
  real_T y_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S63>/y_hat'
                                        */
  real_T y_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S63>/y_hat'
                                        */
  real_T y_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S63>/y_hat'
                                        */
  real_T y_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S63>/y_hat'
                                        */
  real_T y_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S63>/y_hat'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 1e10
                                        * Referenced by: '<S60>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -1e10
                                        * Referenced by: '<S60>/Saturation'
                                        */
  real_T Gain_Gain_pg;                 /* Expression: pi
                                        * Referenced by: '<S60>/Gain'
                                        */
  real_T Constant_Value_kq;            /* Expression: 2*pi
                                        * Referenced by: '<S60>/Constant'
                                        */
  real_T psi_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S63>/psi_hat'
                                        */
  real_T psi_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S63>/psi_hat'
                                        */
  real_T psi_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S63>/psi_hat'
                                        */
  real_T psi_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S63>/psi_hat'
                                        */
  real_T psi_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S63>/psi_hat'
                                        */
  real_T psi_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S63>/psi_hat'
                                        */
  real_T u_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S65>/u_hat'
                                        */
  real_T u_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S65>/u_hat'
                                        */
  real_T u_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S65>/u_hat'
                                        */
  real_T u_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S65>/u_hat'
                                        */
  real_T u_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S65>/u_hat'
                                        */
  real_T u_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S65>/u_hat'
                                        */
  real_T v_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S65>/v_hat'
                                        */
  real_T v_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S65>/v_hat'
                                        */
  real_T v_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S65>/v_hat'
                                        */
  real_T v_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S65>/v_hat'
                                        */
  real_T v_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S65>/v_hat'
                                        */
  real_T v_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S65>/v_hat'
                                        */
  real_T r_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S65>/r_hat'
                                        */
  real_T r_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S65>/r_hat'
                                        */
  real_T r_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S65>/r_hat'
                                        */
  real_T r_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S65>/r_hat'
                                        */
  real_T r_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S65>/r_hat'
                                        */
  real_T r_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S65>/r_hat'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: 1e10
                                        * Referenced by: '<S61>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: -1e10
                                        * Referenced by: '<S61>/Saturation'
                                        */
  real_T Gain_Gain_f;                  /* Expression: pi
                                        * Referenced by: '<S61>/Gain'
                                        */
  real_T Constant_Value_p0;            /* Expression: 2*pi
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T Integrator2_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  real_T M1_Gain[9];                   /* Expression: [0.008021948049864 0 0;0 0.010098125265799 1.104781662647098e-04;0 3.303823257820844e-05 0.020839338676560]
                                        * Referenced by: '<S6>/M^-1'
                                        */
  real_T u_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S64>/u_dot_hat'
                                        */
  real_T u_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S64>/u_dot_hat'
                                        */
  real_T u_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S64>/u_dot_hat'
                                        */
  real_T u_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S64>/u_dot_hat'
                                        */
  real_T u_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S64>/u_dot_hat'
                                        */
  real_T u_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S64>/u_dot_hat'
                                        */
  real_T v_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S64>/v_dot_hat'
                                        */
  real_T v_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S64>/v_dot_hat'
                                        */
  real_T v_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S64>/v_dot_hat'
                                        */
  real_T v_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S64>/v_dot_hat'
                                        */
  real_T v_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S64>/v_dot_hat'
                                        */
  real_T v_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S64>/v_dot_hat'
                                        */
  real_T r_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S64>/r_dot_hat'
                                        */
  real_T r_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S64>/r_dot_hat'
                                        */
  real_T r_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S64>/r_dot_hat'
                                        */
  real_T r_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S64>/r_dot_hat'
                                        */
  real_T r_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S64>/r_dot_hat'
                                        */
  real_T r_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S64>/r_dot_hat'
                                        */
  real_T b_x_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S62>/b_x_hat'
                                        */
  real_T b_x_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S62>/b_x_hat'
                                        */
  real_T b_x_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S62>/b_x_hat'
                                        */
  real_T b_x_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S62>/b_x_hat'
                                        */
  real_T b_x_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S62>/b_x_hat'
                                        */
  real_T b_x_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S62>/b_x_hat'
                                        */
  real_T b_y_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S62>/b_y_hat'
                                        */
  real_T b_y_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S62>/b_y_hat'
                                        */
  real_T b_y_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S62>/b_y_hat'
                                        */
  real_T b_y_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S62>/b_y_hat'
                                        */
  real_T b_y_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S62>/b_y_hat'
                                        */
  real_T b_y_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S62>/b_y_hat'
                                        */
  real_T b_psi_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S62>/b_psi_hat'
                                        */
  real_T b_psi_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S62>/b_psi_hat'
                                        */
  real_T b_psi_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S62>/b_psi_hat'
                                        */
  real_T b_psi_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S62>/b_psi_hat'
                                        */
  real_T b_psi_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S62>/b_psi_hat'
                                        */
  real_T b_psi_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S62>/b_psi_hat'
                                        */
  real_T Gain_Gain_f0;                 /* Expression: 180/pi
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T XpositionThruster_Value_e[6]; /* Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
                                        * Referenced by: '<Root>/X-position Thruster'
                                        */
  real_T YpositionThruster_Value_o[6]; /* Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
                                        * Referenced by: '<Root>/Y-position Thruster'
                                        */
  real_T tau_actual_P1;                /* Expression: width
                                        * Referenced by: '<Root>/tau_actual'
                                        */
  real_T tau_actual_P2;                /* Expression: dtype
                                        * Referenced by: '<Root>/tau_actual'
                                        */
  real_T tau_actual_P3;                /* Expression: portnum
                                        * Referenced by: '<Root>/tau_actual'
                                        */
  real_T tau_actual_P4;                /* Expression: stime
                                        * Referenced by: '<Root>/tau_actual'
                                        */
  real_T tau_actual_P5;                /* Expression: stype
                                        * Referenced by: '<Root>/tau_actual'
                                        */
  real_T tau_actual_P6;                /* Expression: btype
                                        * Referenced by: '<Root>/tau_actual'
                                        */
  real_T eta_tilde_P1;                 /* Expression: width
                                        * Referenced by: '<S14>/eta_tilde'
                                        */
  real_T eta_tilde_P2;                 /* Expression: dtype
                                        * Referenced by: '<S14>/eta_tilde'
                                        */
  real_T eta_tilde_P3;                 /* Expression: portnum
                                        * Referenced by: '<S14>/eta_tilde'
                                        */
  real_T eta_tilde_P4;                 /* Expression: stime
                                        * Referenced by: '<S14>/eta_tilde'
                                        */
  real_T eta_tilde_P5;                 /* Expression: stype
                                        * Referenced by: '<S14>/eta_tilde'
                                        */
  real_T eta_tilde_P6;                 /* Expression: btype
                                        * Referenced by: '<S14>/eta_tilde'
                                        */
  real_T eta_des_P1;                   /* Expression: width
                                        * Referenced by: '<S3>/eta_des'
                                        */
  real_T eta_des_P2;                   /* Expression: dtype
                                        * Referenced by: '<S3>/eta_des'
                                        */
  real_T eta_des_P3;                   /* Expression: portnum
                                        * Referenced by: '<S3>/eta_des'
                                        */
  real_T eta_des_P4;                   /* Expression: stime
                                        * Referenced by: '<S3>/eta_des'
                                        */
  real_T eta_des_P5;                   /* Expression: stype
                                        * Referenced by: '<S3>/eta_des'
                                        */
  real_T eta_des_P6;                   /* Expression: btype
                                        * Referenced by: '<S3>/eta_des'
                                        */
  real_T Integrator2_IC_p;             /* Expression: 0
                                        * Referenced by: '<S19>/Integrator2'
                                        */
  real_T Constant_Value_c;             /* Expression: 50
                                        * Referenced by: '<S46>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 50
                                        * Referenced by: '<S46>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 50
                                        * Referenced by: '<S46>/Constant2'
                                        */
  real_T Constant3_Value_f;            /* Expression: 1
                                        * Referenced by: '<S46>/Constant3'
                                        */
  real_T Constant4_Value_a;            /* Expression: 1
                                        * Referenced by: '<S46>/Constant4'
                                        */
  real_T Constant5_Value_j;            /* Expression: 1
                                        * Referenced by: '<S46>/Constant5'
                                        */
  real_T X_oqus_P1;                    /* Expression: width
                                        * Referenced by: '<S8>/X_oqus'
                                        */
  real_T X_oqus_P2;                    /* Expression: dtype
                                        * Referenced by: '<S8>/X_oqus'
                                        */
  real_T X_oqus_P3;                    /* Expression: portnum
                                        * Referenced by: '<S8>/X_oqus'
                                        */
  real_T X_oqus_P4;                    /* Expression: stime
                                        * Referenced by: '<S8>/X_oqus'
                                        */
  real_T X_oqus_P5;                    /* Expression: stype
                                        * Referenced by: '<S8>/X_oqus'
                                        */
  real_T X_oqus_P6;                    /* Expression: btype
                                        * Referenced by: '<S8>/X_oqus'
                                        */
  real_T Y_oqus_P1;                    /* Expression: width
                                        * Referenced by: '<S8>/Y_oqus'
                                        */
  real_T Y_oqus_P2;                    /* Expression: dtype
                                        * Referenced by: '<S8>/Y_oqus'
                                        */
  real_T Y_oqus_P3;                    /* Expression: portnum
                                        * Referenced by: '<S8>/Y_oqus'
                                        */
  real_T Y_oqus_P4;                    /* Expression: stime
                                        * Referenced by: '<S8>/Y_oqus'
                                        */
  real_T Y_oqus_P5;                    /* Expression: stype
                                        * Referenced by: '<S8>/Y_oqus'
                                        */
  real_T Y_oqus_P6;                    /* Expression: btype
                                        * Referenced by: '<S8>/Y_oqus'
                                        */
  real_T Z_oqus_P1;                    /* Expression: width
                                        * Referenced by: '<S8>/Z_oqus'
                                        */
  real_T Z_oqus_P2;                    /* Expression: dtype
                                        * Referenced by: '<S8>/Z_oqus'
                                        */
  real_T Z_oqus_P3;                    /* Expression: portnum
                                        * Referenced by: '<S8>/Z_oqus'
                                        */
  real_T Z_oqus_P4;                    /* Expression: stime
                                        * Referenced by: '<S8>/Z_oqus'
                                        */
  real_T Z_oqus_P5;                    /* Expression: stype
                                        * Referenced by: '<S8>/Z_oqus'
                                        */
  real_T Z_oqus_P6;                    /* Expression: btype
                                        * Referenced by: '<S8>/Z_oqus'
                                        */
  real_T roll_oqus_P1;                 /* Expression: width
                                        * Referenced by: '<S8>/roll_oqus'
                                        */
  real_T roll_oqus_P2;                 /* Expression: dtype
                                        * Referenced by: '<S8>/roll_oqus'
                                        */
  real_T roll_oqus_P3;                 /* Expression: portnum
                                        * Referenced by: '<S8>/roll_oqus'
                                        */
  real_T roll_oqus_P4;                 /* Expression: stime
                                        * Referenced by: '<S8>/roll_oqus'
                                        */
  real_T roll_oqus_P5;                 /* Expression: stype
                                        * Referenced by: '<S8>/roll_oqus'
                                        */
  real_T roll_oqus_P6;                 /* Expression: btype
                                        * Referenced by: '<S8>/roll_oqus'
                                        */
  real_T pitch_oqus_P1;                /* Expression: width
                                        * Referenced by: '<S8>/pitch_oqus'
                                        */
  real_T pitch_oqus_P2;                /* Expression: dtype
                                        * Referenced by: '<S8>/pitch_oqus'
                                        */
  real_T pitch_oqus_P3;                /* Expression: portnum
                                        * Referenced by: '<S8>/pitch_oqus'
                                        */
  real_T pitch_oqus_P4;                /* Expression: stime
                                        * Referenced by: '<S8>/pitch_oqus'
                                        */
  real_T pitch_oqus_P5;                /* Expression: stype
                                        * Referenced by: '<S8>/pitch_oqus'
                                        */
  real_T pitch_oqus_P6;                /* Expression: btype
                                        * Referenced by: '<S8>/pitch_oqus'
                                        */
  real_T yaw_oqus_P1;                  /* Expression: width
                                        * Referenced by: '<S8>/yaw_oqus'
                                        */
  real_T yaw_oqus_P2;                  /* Expression: dtype
                                        * Referenced by: '<S8>/yaw_oqus'
                                        */
  real_T yaw_oqus_P3;                  /* Expression: portnum
                                        * Referenced by: '<S8>/yaw_oqus'
                                        */
  real_T yaw_oqus_P4;                  /* Expression: stime
                                        * Referenced by: '<S8>/yaw_oqus'
                                        */
  real_T yaw_oqus_P5;                  /* Expression: stype
                                        * Referenced by: '<S8>/yaw_oqus'
                                        */
  real_T yaw_oqus_P6;                  /* Expression: btype
                                        * Referenced by: '<S8>/yaw_oqus'
                                        */
  real_T Delay_InitialCondition_j;     /* Expression: 0
                                        * Referenced by: '<S12>/Delay'
                                        */
  real_T Constant_Value_cs[2];         /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S75>/Constant'
                                        */
  real_T Constant1_Value_k[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S75>/Constant1'
                                        */
  real_T Delay_InitialCondition_i;     /* Expression: 0
                                        * Referenced by: '<S75>/Delay'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0
                                        * Referenced by: '<S90>/Delay'
                                        */
  real_T Constant1_Value_o[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S90>/Constant1'
                                        */
  real_T Constant2_Value_b[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S90>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S90>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S93>/TSamp'
                                        */
  real_T AccelerationLimit_RisingLim;  /* Computed Parameter: AccelerationLimit_RisingLim
                                        * Referenced by: '<S90>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_FallingLim; /* Computed Parameter: AccelerationLimit_FallingLim
                                        * Referenced by: '<S90>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_IC;         /* Expression: 0
                                        * Referenced by: '<S90>/Acceleration Limit'
                                        */
  real_T Memory_X0;                    /* Expression: 1
                                        * Referenced by: '<S90>/Memory'
                                        */
  real_T reset_P1_b;                   /* Expression: width
                                        * Referenced by: '<S92>/reset'
                                        */
  real_T reset_P2_h;                   /* Expression: dtype
                                        * Referenced by: '<S92>/reset'
                                        */
  real_T reset_P3_f;                   /* Expression: portnum
                                        * Referenced by: '<S92>/reset'
                                        */
  real_T reset_P4_c;                   /* Expression: stime
                                        * Referenced by: '<S92>/reset'
                                        */
  real_T reset_P5_k;                   /* Expression: stype
                                        * Referenced by: '<S92>/reset'
                                        */
  real_T reset_P6_d;                   /* Expression: btype
                                        * Referenced by: '<S92>/reset'
                                        */
  real_T Integrator_IC_a;              /* Expression: 0
                                        * Referenced by: '<S92>/Integrator'
                                        */
  real_T NaN_Value;                    /* Expression: 0
                                        * Referenced by: '<S90>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_h;/* Expression: 0
                                          * Referenced by: '<S75>/Discrete Transfer Fcn'
                                          */
  real_T Control_test_Pa_P1;           /* Expression: width
                                        * Referenced by: '<S88>/Control_test_Pa'
                                        */
  real_T Control_test_Pa_P2;           /* Expression: dtype
                                        * Referenced by: '<S88>/Control_test_Pa'
                                        */
  real_T Control_test_Pa_P3;           /* Expression: portnum
                                        * Referenced by: '<S88>/Control_test_Pa'
                                        */
  real_T Control_test_Pa_P4;           /* Expression: stime
                                        * Referenced by: '<S88>/Control_test_Pa'
                                        */
  real_T Control_test_Pa_P5;           /* Expression: stype
                                        * Referenced by: '<S88>/Control_test_Pa'
                                        */
  real_T Control_test_Pa_P6;           /* Expression: btype
                                        * Referenced by: '<S88>/Control_test_Pa'
                                        */
  real_T Constant_Value_h[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S76>/Constant'
                                        */
  real_T Constant1_Value_j[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S76>/Constant1'
                                        */
  real_T Delay_InitialCondition_l;     /* Expression: 0
                                        * Referenced by: '<S76>/Delay'
                                        */
  real_T Delay_InitialCondition_iv;    /* Expression: 0
                                        * Referenced by: '<S99>/Delay'
                                        */
  real_T Constant1_Value_b[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S99>/Constant1'
                                        */
  real_T Constant2_Value_i[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S99>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_hu;/* Expression: 0
                                          * Referenced by: '<S99>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_k;                 /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S102>/TSamp'
                                        */
  real_T AccelerationLimit_RisingLim_n;/* Computed Parameter: AccelerationLimit_RisingLim_n
                                        * Referenced by: '<S99>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_FallingLim_n;/* Computed Parameter: AccelerationLimit_FallingLim_n
                                         * Referenced by: '<S99>/Acceleration Limit'
                                         */
  real_T AccelerationLimit_IC_m;       /* Expression: 0
                                        * Referenced by: '<S99>/Acceleration Limit'
                                        */
  real_T Memory_X0_e;                  /* Expression: 1
                                        * Referenced by: '<S99>/Memory'
                                        */
  real_T reset_P1_g;                   /* Expression: width
                                        * Referenced by: '<S101>/reset'
                                        */
  real_T reset_P2_i;                   /* Expression: dtype
                                        * Referenced by: '<S101>/reset'
                                        */
  real_T reset_P3_l;                   /* Expression: portnum
                                        * Referenced by: '<S101>/reset'
                                        */
  real_T reset_P4_n;                   /* Expression: stime
                                        * Referenced by: '<S101>/reset'
                                        */
  real_T reset_P5_b;                   /* Expression: stype
                                        * Referenced by: '<S101>/reset'
                                        */
  real_T reset_P6_g3;                  /* Expression: btype
                                        * Referenced by: '<S101>/reset'
                                        */
  real_T Integrator_IC_fy;             /* Expression: 0
                                        * Referenced by: '<S101>/Integrator'
                                        */
  real_T NaN_Value_l;                  /* Expression: 0
                                        * Referenced by: '<S99>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_f;/* Expression: 0
                                          * Referenced by: '<S76>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_n[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S77>/Constant'
                                        */
  real_T Constant1_Value_a[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S77>/Constant1'
                                        */
  real_T Delay_InitialCondition_dp;    /* Expression: 0
                                        * Referenced by: '<S77>/Delay'
                                        */
  real_T Delay_InitialCondition_h;     /* Expression: 0
                                        * Referenced by: '<S108>/Delay'
                                        */
  real_T Constant1_Value_gf[3];        /* Expression: hd.num{1,1}
                                        * Referenced by: '<S108>/Constant1'
                                        */
  real_T Constant2_Value_h[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S108>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_a;/* Expression: 0
                                          * Referenced by: '<S108>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_m;                 /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S111>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim;/* Computed Parameter: Accelerationlimiter_RisingLim
                                        * Referenced by: '<S108>/Acceleration limiter'
                                        */
  real_T Accelerationlimiter_FallingLim;/* Computed Parameter: Accelerationlimiter_FallingLim
                                         * Referenced by: '<S108>/Acceleration limiter'
                                         */
  real_T Accelerationlimiter_IC;       /* Expression: 0
                                        * Referenced by: '<S108>/Acceleration limiter'
                                        */
  real_T Memory_X0_g;                  /* Expression: 1
                                        * Referenced by: '<S108>/Memory'
                                        */
  real_T reset_P1_f;                   /* Expression: width
                                        * Referenced by: '<S110>/reset'
                                        */
  real_T reset_P2_k;                   /* Expression: dtype
                                        * Referenced by: '<S110>/reset'
                                        */
  real_T reset_P3_d;                   /* Expression: portnum
                                        * Referenced by: '<S110>/reset'
                                        */
  real_T reset_P4_l;                   /* Expression: stime
                                        * Referenced by: '<S110>/reset'
                                        */
  real_T reset_P5_mc;                  /* Expression: stype
                                        * Referenced by: '<S110>/reset'
                                        */
  real_T reset_P6_f5;                  /* Expression: btype
                                        * Referenced by: '<S110>/reset'
                                        */
  real_T Integrator_IC_j;              /* Expression: 0
                                        * Referenced by: '<S110>/Integrator'
                                        */
  real_T NaN_Value_g;                  /* Expression: 0
                                        * Referenced by: '<S108>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_c;/* Expression: 0
                                          * Referenced by: '<S77>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_j4[2];         /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S78>/Constant'
                                        */
  real_T Constant1_Value_oi[2];        /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S78>/Constant1'
                                        */
  real_T Delay_InitialCondition_fb;    /* Expression: 0
                                        * Referenced by: '<S78>/Delay'
                                        */
  real_T Delay_InitialCondition_gg;    /* Expression: 0
                                        * Referenced by: '<S117>/Delay'
                                        */
  real_T Constant1_Value_m[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S117>/Constant1'
                                        */
  real_T Constant2_Value_l[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S117>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_a1;/* Expression: 0
                                          * Referenced by: '<S117>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_h;                 /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S120>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_e;/* Computed Parameter: Accelerationlimiter_RisingLim_e
                                          * Referenced by: '<S117>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_b;/* Computed Parameter: Accelerationlimiter_FallingLi_b
                                          * Referenced by: '<S117>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_h;     /* Expression: 0
                                        * Referenced by: '<S117>/Acceleration limiter'
                                        */
  real_T Memory_X0_k;                  /* Expression: 1
                                        * Referenced by: '<S117>/Memory'
                                        */
  real_T reset_P1_i;                   /* Expression: width
                                        * Referenced by: '<S119>/reset'
                                        */
  real_T reset_P2_g0;                  /* Expression: dtype
                                        * Referenced by: '<S119>/reset'
                                        */
  real_T reset_P3_eq;                  /* Expression: portnum
                                        * Referenced by: '<S119>/reset'
                                        */
  real_T reset_P4_p;                   /* Expression: stime
                                        * Referenced by: '<S119>/reset'
                                        */
  real_T reset_P5_f3;                  /* Expression: stype
                                        * Referenced by: '<S119>/reset'
                                        */
  real_T reset_P6_l2;                  /* Expression: btype
                                        * Referenced by: '<S119>/reset'
                                        */
  real_T Integrator_IC_g;              /* Expression: 0
                                        * Referenced by: '<S119>/Integrator'
                                        */
  real_T NaN_Value_p;                  /* Expression: 0
                                        * Referenced by: '<S117>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_p;/* Expression: 0
                                          * Referenced by: '<S78>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_ib[2];         /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T Constant1_Value_h[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S79>/Constant1'
                                        */
  real_T Delay_InitialCondition_fv;    /* Expression: 0
                                        * Referenced by: '<S79>/Delay'
                                        */
  real_T Delay_InitialCondition_dz;    /* Expression: 0
                                        * Referenced by: '<S126>/Delay'
                                        */
  real_T Constant1_Value_mk[3];        /* Expression: hd.num{1,1}
                                        * Referenced by: '<S126>/Constant1'
                                        */
  real_T Constant2_Value_p[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S126>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_e;/* Expression: 0
                                          * Referenced by: '<S126>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_o;                 /* Computed Parameter: TSamp_WtEt_o
                                        * Referenced by: '<S129>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_b;/* Computed Parameter: Accelerationlimiter_RisingLim_b
                                          * Referenced by: '<S126>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_d;/* Computed Parameter: Accelerationlimiter_FallingLi_d
                                          * Referenced by: '<S126>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_i;     /* Expression: 0
                                        * Referenced by: '<S126>/Acceleration limiter'
                                        */
  real_T Memory_X0_k3;                 /* Expression: 1
                                        * Referenced by: '<S126>/Memory'
                                        */
  real_T reset_P1_md;                  /* Expression: width
                                        * Referenced by: '<S128>/reset'
                                        */
  real_T reset_P2_jk;                  /* Expression: dtype
                                        * Referenced by: '<S128>/reset'
                                        */
  real_T reset_P3_dp;                  /* Expression: portnum
                                        * Referenced by: '<S128>/reset'
                                        */
  real_T reset_P4_g;                   /* Expression: stime
                                        * Referenced by: '<S128>/reset'
                                        */
  real_T reset_P5_mg;                  /* Expression: stype
                                        * Referenced by: '<S128>/reset'
                                        */
  real_T reset_P6_g5;                  /* Expression: btype
                                        * Referenced by: '<S128>/reset'
                                        */
  real_T Integrator_IC_aj;             /* Expression: 0
                                        * Referenced by: '<S128>/Integrator'
                                        */
  real_T NaN_Value_lq;                 /* Expression: 0
                                        * Referenced by: '<S126>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialS_pj;/* Expression: 0
                                          * Referenced by: '<S79>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_ht[2];         /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S80>/Constant'
                                        */
  real_T Constant1_Value_gs[2];        /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S80>/Constant1'
                                        */
  real_T Delay_InitialCondition_fi;    /* Expression: 0
                                        * Referenced by: '<S80>/Delay'
                                        */
  real_T Delay_InitialCondition_a;     /* Expression: 0
                                        * Referenced by: '<S135>/Delay'
                                        */
  real_T Constant1_Value_oa[3];        /* Expression: hd.num{1,1}
                                        * Referenced by: '<S135>/Constant1'
                                        */
  real_T Constant2_Value_p3[3];        /* Expression: hd.den{1,1}
                                        * Referenced by: '<S135>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_a4;/* Expression: 0
                                          * Referenced by: '<S135>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_kk;                /* Computed Parameter: TSamp_WtEt_kk
                                        * Referenced by: '<S138>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLi_bi;/* Computed Parameter: Accelerationlimiter_RisingLi_bi
                                          * Referenced by: '<S135>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_p;/* Computed Parameter: Accelerationlimiter_FallingLi_p
                                          * Referenced by: '<S135>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_p;     /* Expression: 0
                                        * Referenced by: '<S135>/Acceleration limiter'
                                        */
  real_T Memory_X0_c;                  /* Expression: 1
                                        * Referenced by: '<S135>/Memory'
                                        */
  real_T reset_P1_kh;                  /* Expression: width
                                        * Referenced by: '<S137>/reset'
                                        */
  real_T reset_P2_hw;                  /* Expression: dtype
                                        * Referenced by: '<S137>/reset'
                                        */
  real_T reset_P3_fv;                  /* Expression: portnum
                                        * Referenced by: '<S137>/reset'
                                        */
  real_T reset_P4_a;                   /* Expression: stime
                                        * Referenced by: '<S137>/reset'
                                        */
  real_T reset_P5_e;                   /* Expression: stype
                                        * Referenced by: '<S137>/reset'
                                        */
  real_T reset_P6_a;                   /* Expression: btype
                                        * Referenced by: '<S137>/reset'
                                        */
  real_T Integrator_IC_h;              /* Expression: 0
                                        * Referenced by: '<S137>/Integrator'
                                        */
  real_T NaN_Value_j;                  /* Expression: 0
                                        * Referenced by: '<S135>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_b;/* Expression: 0
                                          * Referenced by: '<S80>/Discrete Transfer Fcn'
                                          */
  real_T IMU_AX1_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_AX1'
                                        */
  real_T IMU_AX1_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_AX1'
                                        */
  real_T IMU_AX1_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_AX1'
                                        */
  real_T IMU_AX1_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_AX1'
                                        */
  real_T IMU_AX1_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_AX1'
                                        */
  real_T IMU_AX1_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_AX1'
                                        */
  real_T IMU_AY1_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_AY1'
                                        */
  real_T IMU_AY1_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_AY1'
                                        */
  real_T IMU_AY1_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_AY1'
                                        */
  real_T IMU_AY1_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_AY1'
                                        */
  real_T IMU_AY1_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_AY1'
                                        */
  real_T IMU_AY1_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_AY1'
                                        */
  real_T IMU_AZ1_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_AZ1'
                                        */
  real_T IMU_AZ1_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_AZ1'
                                        */
  real_T IMU_AZ1_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_AZ1'
                                        */
  real_T IMU_AZ1_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_AZ1'
                                        */
  real_T IMU_AZ1_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_AZ1'
                                        */
  real_T IMU_AZ1_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_AZ1'
                                        */
  real_T IMU_RX1_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_RX1'
                                        */
  real_T IMU_RX1_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_RX1'
                                        */
  real_T IMU_RX1_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_RX1'
                                        */
  real_T IMU_RX1_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_RX1'
                                        */
  real_T IMU_RX1_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_RX1'
                                        */
  real_T IMU_RX1_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_RX1'
                                        */
  real_T IMU_RY1_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_RY1'
                                        */
  real_T IMU_RY1_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_RY1'
                                        */
  real_T IMU_RY1_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_RY1'
                                        */
  real_T IMU_RY1_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_RY1'
                                        */
  real_T IMU_RY1_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_RY1'
                                        */
  real_T IMU_RY1_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_RY1'
                                        */
  real_T IMU_RZ1_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_RZ1'
                                        */
  real_T IMU_RZ1_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_RZ1'
                                        */
  real_T IMU_RZ1_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_RZ1'
                                        */
  real_T IMU_RZ1_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_RZ1'
                                        */
  real_T IMU_RZ1_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_RZ1'
                                        */
  real_T IMU_RZ1_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_RZ1'
                                        */
  real_T IMU_V1_P1;                    /* Expression: width
                                        * Referenced by: '<S4>/IMU_V1'
                                        */
  real_T IMU_V1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_V1'
                                        */
  real_T IMU_V1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_V1'
                                        */
  real_T IMU_V1_P4;                    /* Expression: stime
                                        * Referenced by: '<S4>/IMU_V1'
                                        */
  real_T IMU_V1_P5;                    /* Expression: stype
                                        * Referenced by: '<S4>/IMU_V1'
                                        */
  real_T IMU_V1_P6;                    /* Expression: btype
                                        * Referenced by: '<S4>/IMU_V1'
                                        */
  real_T IMU_AX2_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_AX2'
                                        */
  real_T IMU_AX2_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_AX2'
                                        */
  real_T IMU_AX2_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_AX2'
                                        */
  real_T IMU_AX2_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_AX2'
                                        */
  real_T IMU_AX2_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_AX2'
                                        */
  real_T IMU_AX2_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_AX2'
                                        */
  real_T IMU_AY2_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_AY2'
                                        */
  real_T IMU_AY2_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_AY2'
                                        */
  real_T IMU_AY2_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_AY2'
                                        */
  real_T IMU_AY2_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_AY2'
                                        */
  real_T IMU_AY2_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_AY2'
                                        */
  real_T IMU_AY2_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_AY2'
                                        */
  real_T IMU_AZ2_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_AZ2'
                                        */
  real_T IMU_AZ2_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_AZ2'
                                        */
  real_T IMU_AZ2_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_AZ2'
                                        */
  real_T IMU_AZ2_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_AZ2'
                                        */
  real_T IMU_AZ2_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_AZ2'
                                        */
  real_T IMU_AZ2_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_AZ2'
                                        */
  real_T IMU_RX2_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_RX2'
                                        */
  real_T IMU_RX2_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_RX2'
                                        */
  real_T IMU_RX2_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_RX2'
                                        */
  real_T IMU_RX2_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_RX2'
                                        */
  real_T IMU_RX2_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_RX2'
                                        */
  real_T IMU_RX2_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_RX2'
                                        */
  real_T IMU_RY2_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_RY2'
                                        */
  real_T IMU_RY2_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_RY2'
                                        */
  real_T IMU_RY2_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_RY2'
                                        */
  real_T IMU_RY2_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_RY2'
                                        */
  real_T IMU_RY2_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_RY2'
                                        */
  real_T IMU_RY2_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_RY2'
                                        */
  real_T IMU_RZ2_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_RZ2'
                                        */
  real_T IMU_RZ2_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_RZ2'
                                        */
  real_T IMU_RZ2_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_RZ2'
                                        */
  real_T IMU_RZ2_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_RZ2'
                                        */
  real_T IMU_RZ2_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_RZ2'
                                        */
  real_T IMU_RZ2_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_RZ2'
                                        */
  real_T IMU_V2_P1;                    /* Expression: width
                                        * Referenced by: '<S4>/IMU_V2'
                                        */
  real_T IMU_V2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_V2'
                                        */
  real_T IMU_V2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_V2'
                                        */
  real_T IMU_V2_P4;                    /* Expression: stime
                                        * Referenced by: '<S4>/IMU_V2'
                                        */
  real_T IMU_V2_P5;                    /* Expression: stype
                                        * Referenced by: '<S4>/IMU_V2'
                                        */
  real_T IMU_V2_P6;                    /* Expression: btype
                                        * Referenced by: '<S4>/IMU_V2'
                                        */
  real_T IMU_AX3_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_AX3'
                                        */
  real_T IMU_AX3_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_AX3'
                                        */
  real_T IMU_AX3_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_AX3'
                                        */
  real_T IMU_AX3_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_AX3'
                                        */
  real_T IMU_AX3_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_AX3'
                                        */
  real_T IMU_AX3_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_AX3'
                                        */
  real_T IMU_AY3_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_AY3'
                                        */
  real_T IMU_AY3_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_AY3'
                                        */
  real_T IMU_AY3_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_AY3'
                                        */
  real_T IMU_AY3_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_AY3'
                                        */
  real_T IMU_AY3_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_AY3'
                                        */
  real_T IMU_AY3_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_AY3'
                                        */
  real_T IMU_AZ3_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_AZ3'
                                        */
  real_T IMU_AZ3_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_AZ3'
                                        */
  real_T IMU_AZ3_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_AZ3'
                                        */
  real_T IMU_AZ3_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_AZ3'
                                        */
  real_T IMU_AZ3_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_AZ3'
                                        */
  real_T IMU_AZ3_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_AZ3'
                                        */
  real_T IMU_RX3_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_RX3'
                                        */
  real_T IMU_RX3_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_RX3'
                                        */
  real_T IMU_RX3_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_RX3'
                                        */
  real_T IMU_RX3_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_RX3'
                                        */
  real_T IMU_RX3_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_RX3'
                                        */
  real_T IMU_RX3_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_RX3'
                                        */
  real_T IMU_RY3_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_RY3'
                                        */
  real_T IMU_RY3_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_RY3'
                                        */
  real_T IMU_RY3_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_RY3'
                                        */
  real_T IMU_RY3_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_RY3'
                                        */
  real_T IMU_RY3_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_RY3'
                                        */
  real_T IMU_RY3_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_RY3'
                                        */
  real_T IMU_RZ3_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_RZ3'
                                        */
  real_T IMU_RZ3_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_RZ3'
                                        */
  real_T IMU_RZ3_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_RZ3'
                                        */
  real_T IMU_RZ3_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_RZ3'
                                        */
  real_T IMU_RZ3_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_RZ3'
                                        */
  real_T IMU_RZ3_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_RZ3'
                                        */
  real_T IMU_V3_P1;                    /* Expression: width
                                        * Referenced by: '<S4>/IMU_V3'
                                        */
  real_T IMU_V3_P2;                    /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_V3'
                                        */
  real_T IMU_V3_P3;                    /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_V3'
                                        */
  real_T IMU_V3_P4;                    /* Expression: stime
                                        * Referenced by: '<S4>/IMU_V3'
                                        */
  real_T IMU_V3_P5;                    /* Expression: stype
                                        * Referenced by: '<S4>/IMU_V3'
                                        */
  real_T IMU_V3_P6;                    /* Expression: btype
                                        * Referenced by: '<S4>/IMU_V3'
                                        */
  real_T IMU_AX4_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_AX4'
                                        */
  real_T IMU_AX4_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_AX4'
                                        */
  real_T IMU_AX4_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_AX4'
                                        */
  real_T IMU_AX4_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_AX4'
                                        */
  real_T IMU_AX4_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_AX4'
                                        */
  real_T IMU_AX4_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_AX4'
                                        */
  real_T IMU_AY4_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_AY4'
                                        */
  real_T IMU_AY4_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_AY4'
                                        */
  real_T IMU_AY4_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_AY4'
                                        */
  real_T IMU_AY4_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_AY4'
                                        */
  real_T IMU_AY4_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_AY4'
                                        */
  real_T IMU_AY4_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_AY4'
                                        */
  real_T IMU_AZ4_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_AZ4'
                                        */
  real_T IMU_AZ4_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_AZ4'
                                        */
  real_T IMU_AZ4_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_AZ4'
                                        */
  real_T IMU_AZ4_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_AZ4'
                                        */
  real_T IMU_AZ4_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_AZ4'
                                        */
  real_T IMU_AZ4_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_AZ4'
                                        */
  real_T IMU_RX4_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_RX4'
                                        */
  real_T IMU_RX4_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_RX4'
                                        */
  real_T IMU_RX4_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_RX4'
                                        */
  real_T IMU_RX4_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_RX4'
                                        */
  real_T IMU_RX4_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_RX4'
                                        */
  real_T IMU_RX4_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_RX4'
                                        */
  real_T IMU_RY4_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_RY4'
                                        */
  real_T IMU_RY4_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_RY4'
                                        */
  real_T IMU_RY4_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_RY4'
                                        */
  real_T IMU_RY4_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_RY4'
                                        */
  real_T IMU_RY4_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_RY4'
                                        */
  real_T IMU_RY4_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_RY4'
                                        */
  real_T IMU_RZ4_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/IMU_RZ4'
                                        */
  real_T IMU_RZ4_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_RZ4'
                                        */
  real_T IMU_RZ4_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_RZ4'
                                        */
  real_T IMU_RZ4_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/IMU_RZ4'
                                        */
  real_T IMU_RZ4_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/IMU_RZ4'
                                        */
  real_T IMU_RZ4_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/IMU_RZ4'
                                        */
  real_T IMU_V4_P1;                    /* Expression: width
                                        * Referenced by: '<S4>/IMU_V4'
                                        */
  real_T IMU_V4_P2;                    /* Expression: dtype
                                        * Referenced by: '<S4>/IMU_V4'
                                        */
  real_T IMU_V4_P3;                    /* Expression: portnum
                                        * Referenced by: '<S4>/IMU_V4'
                                        */
  real_T IMU_V4_P4;                    /* Expression: stime
                                        * Referenced by: '<S4>/IMU_V4'
                                        */
  real_T IMU_V4_P5;                    /* Expression: stype
                                        * Referenced by: '<S4>/IMU_V4'
                                        */
  real_T IMU_V4_P6;                    /* Expression: btype
                                        * Referenced by: '<S4>/IMU_V4'
                                        */
  real_T Memory_X0_f[28];              /* Expression: zeros(1,28)
                                        * Referenced by: '<S4>/Memory'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S30>/Delay'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S30>/Delay1'
                                        */
  uint32_T Delay_DelayLength_h;        /* Computed Parameter: Delay_DelayLength_h
                                        * Referenced by: '<S27>/Delay'
                                        */
  uint32_T Delay1_DelayLength_h;       /* Computed Parameter: Delay1_DelayLength_h
                                        * Referenced by: '<S27>/Delay1'
                                        */
  uint32_T Delay_DelayLength_n;        /* Computed Parameter: Delay_DelayLength_n
                                        * Referenced by: '<S28>/Delay'
                                        */
  uint32_T Delay1_DelayLength_i;       /* Computed Parameter: Delay1_DelayLength_i
                                        * Referenced by: '<S28>/Delay1'
                                        */
  uint32_T Delay_DelayLength_i;        /* Computed Parameter: Delay_DelayLength_i
                                        * Referenced by: '<S29>/Delay'
                                        */
  uint32_T Delay1_DelayLength_m;       /* Computed Parameter: Delay1_DelayLength_m
                                        * Referenced by: '<S29>/Delay1'
                                        */
  uint32_T Delay_DelayLength_m;        /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S12>/Delay'
                                        */
  uint32_T Delay_DelayLength_d;        /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S75>/Delay'
                                        */
  uint32_T Delay_DelayLength_f;        /* Computed Parameter: Delay_DelayLength_f
                                        * Referenced by: '<S90>/Delay'
                                        */
  uint32_T Delay_DelayLength_m5;       /* Computed Parameter: Delay_DelayLength_m5
                                        * Referenced by: '<S76>/Delay'
                                        */
  uint32_T Delay_DelayLength_p;        /* Computed Parameter: Delay_DelayLength_p
                                        * Referenced by: '<S99>/Delay'
                                        */
  uint32_T Delay_DelayLength_hc;       /* Computed Parameter: Delay_DelayLength_hc
                                        * Referenced by: '<S77>/Delay'
                                        */
  uint32_T Delay_DelayLength_b;        /* Computed Parameter: Delay_DelayLength_b
                                        * Referenced by: '<S108>/Delay'
                                        */
  uint32_T Delay_DelayLength_nv;       /* Computed Parameter: Delay_DelayLength_nv
                                        * Referenced by: '<S78>/Delay'
                                        */
  uint32_T Delay_DelayLength_mj;       /* Computed Parameter: Delay_DelayLength_mj
                                        * Referenced by: '<S117>/Delay'
                                        */
  uint32_T Delay_DelayLength_a;        /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S79>/Delay'
                                        */
  uint32_T Delay_DelayLength_k;        /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S126>/Delay'
                                        */
  uint32_T Delay_DelayLength_l;        /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S80>/Delay'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S135>/Delay'
                                        */
  P_CoreSubsys_ctrl_TAPM_T CoreSubsys; /* '<S67>/CoreSubsys' */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_TAPM_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[33];
    real_T odeF[3][33];
    ODE3_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_ctrl_TAPM_T ctrl_TAPM_P;

/* Block signals (auto storage) */
extern B_ctrl_TAPM_T ctrl_TAPM_B;

/* Continuous states (auto storage) */
extern X_ctrl_TAPM_T ctrl_TAPM_X;

/* Block states (auto storage) */
extern DW_ctrl_TAPM_T ctrl_TAPM_DW;

/* Model entry point functions */
extern void ctrl_TAPM_initialize(void);
extern void ctrl_TAPM_output(void);
extern void ctrl_TAPM_update(void);
extern void ctrl_TAPM_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_TAPM_rtModel *ctrl_TAPM(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_TAPM_T *const ctrl_TAPM_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ctrl_TAPM'
 * '<S1>'   : 'ctrl_TAPM/Control'
 * '<S2>'   : 'ctrl_TAPM/Finding commanded forces in: [Surge,Sway,Yaw]'
 * '<S3>'   : 'ctrl_TAPM/Guidance'
 * '<S4>'   : 'ctrl_TAPM/IMU'
 * '<S5>'   : 'ctrl_TAPM/Input1'
 * '<S6>'   : 'ctrl_TAPM/Nonlinear Passisve Observer'
 * '<S7>'   : 'ctrl_TAPM/Observer output '
 * '<S8>'   : 'ctrl_TAPM/Pos measurements'
 * '<S9>'   : 'ctrl_TAPM/Radians to Degrees'
 * '<S10>'  : 'ctrl_TAPM/Thrust allocation'
 * '<S11>'  : 'ctrl_TAPM/Thruster Parameters '
 * '<S12>'  : 'ctrl_TAPM/Thruster control '
 * '<S13>'  : 'ctrl_TAPM/Thruster measurment'
 * '<S14>'  : 'ctrl_TAPM/Control/DP Controller'
 * '<S15>'  : 'ctrl_TAPM/Control/DP Controller/Transposed rotation  matrix in yaw1'
 * '<S16>'  : 'ctrl_TAPM/Control/DP Controller/Transposed rotation  matrix in yaw2'
 * '<S17>'  : 'ctrl_TAPM/Control/DP Controller/[-inf inf] to [-pi pi]'
 * '<S18>'  : 'ctrl_TAPM/Control/DP Controller/[-inf inf] to [-pi pi]1'
 * '<S19>'  : 'ctrl_TAPM/Guidance/Reference model'
 * '<S20>'  : 'ctrl_TAPM/Guidance/Reference model/[-inf inf] to [-pi pi]1'
 * '<S21>'  : 'ctrl_TAPM/Guidance/Reference model/w_d*w_d'
 * '<S22>'  : 'ctrl_TAPM/Guidance/Reference model/w_d*w_d1'
 * '<S23>'  : 'ctrl_TAPM/Guidance/Reference model/w_d^-2'
 * '<S24>'  : 'ctrl_TAPM/Guidance/Reference model/w_d^3'
 * '<S25>'  : 'ctrl_TAPM/IMU/Filtering'
 * '<S26>'  : 'ctrl_TAPM/IMU/Wild point cleaner'
 * '<S27>'  : 'ctrl_TAPM/IMU/Filtering/KalmanFilter'
 * '<S28>'  : 'ctrl_TAPM/IMU/Filtering/KalmanFilter1'
 * '<S29>'  : 'ctrl_TAPM/IMU/Filtering/KalmanFilter2'
 * '<S30>'  : 'ctrl_TAPM/IMU/Filtering/KalmanFilter3'
 * '<S31>'  : 'ctrl_TAPM/IMU/Filtering/Outliner cleaner'
 * '<S32>'  : 'ctrl_TAPM/IMU/Filtering/Outliner cleaner1'
 * '<S33>'  : 'ctrl_TAPM/IMU/Filtering/Outliner cleaner2'
 * '<S34>'  : 'ctrl_TAPM/IMU/Filtering/Outliner cleaner3'
 * '<S35>'  : 'ctrl_TAPM/IMU/Filtering/Outliner cleaner/No outlier'
 * '<S36>'  : 'ctrl_TAPM/IMU/Filtering/Outliner cleaner/Outlier detected'
 * '<S37>'  : 'ctrl_TAPM/IMU/Filtering/Outliner cleaner1/No outlier'
 * '<S38>'  : 'ctrl_TAPM/IMU/Filtering/Outliner cleaner1/Outlier detected'
 * '<S39>'  : 'ctrl_TAPM/IMU/Filtering/Outliner cleaner2/No outlier'
 * '<S40>'  : 'ctrl_TAPM/IMU/Filtering/Outliner cleaner2/Outlier detected'
 * '<S41>'  : 'ctrl_TAPM/IMU/Filtering/Outliner cleaner3/No outlier'
 * '<S42>'  : 'ctrl_TAPM/IMU/Filtering/Outliner cleaner3/Outlier detected'
 * '<S43>'  : 'ctrl_TAPM/IMU/Wild point cleaner/MATLAB Function'
 * '<S44>'  : 'ctrl_TAPM/Input1/Control Gains'
 * '<S45>'  : 'ctrl_TAPM/Input1/Guidance gains'
 * '<S46>'  : 'ctrl_TAPM/Input1/Observer Gains'
 * '<S47>'  : 'ctrl_TAPM/Input1/Control Gains/Kd'
 * '<S48>'  : 'ctrl_TAPM/Input1/Control Gains/Ki'
 * '<S49>'  : 'ctrl_TAPM/Input1/Control Gains/Kp'
 * '<S50>'  : 'ctrl_TAPM/Input1/Guidance gains/wd'
 * '<S51>'  : 'ctrl_TAPM/Input1/Guidance gains/zeta'
 * '<S52>'  : 'ctrl_TAPM/Input1/Observer Gains/Kd'
 * '<S53>'  : 'ctrl_TAPM/Input1/Observer Gains/Ki'
 * '<S54>'  : 'ctrl_TAPM/Input1/Observer Gains/Kp'
 * '<S55>'  : 'ctrl_TAPM/Nonlinear Passisve Observer/C(nu)*nu'
 * '<S56>'  : 'ctrl_TAPM/Nonlinear Passisve Observer/D(nu)*nu'
 * '<S57>'  : 'ctrl_TAPM/Nonlinear Passisve Observer/Rotation matrix in yaw 1'
 * '<S58>'  : 'ctrl_TAPM/Nonlinear Passisve Observer/Transpose Rotation Matrix'
 * '<S59>'  : 'ctrl_TAPM/Nonlinear Passisve Observer/Transpose Rotation matrix'
 * '<S60>'  : 'ctrl_TAPM/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]'
 * '<S61>'  : 'ctrl_TAPM/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1'
 * '<S62>'  : 'ctrl_TAPM/Observer output /b_hat output'
 * '<S63>'  : 'ctrl_TAPM/Observer output /eta_hat output'
 * '<S64>'  : 'ctrl_TAPM/Observer output /nu_dot_hat output'
 * '<S65>'  : 'ctrl_TAPM/Observer output /nu_hat output'
 * '<S66>'  : 'ctrl_TAPM/Thrust allocation/MATLAB Function'
 * '<S67>'  : 'ctrl_TAPM/Thrust allocation/Optimal angle path and  constraints on rotation speed'
 * '<S68>'  : 'ctrl_TAPM/Thrust allocation/Radians to Degrees'
 * '<S69>'  : 'ctrl_TAPM/Thrust allocation/angle between  [-180 180]'
 * '<S70>'  : 'ctrl_TAPM/Thrust allocation/Optimal angle path and  constraints on rotation speed/Degrees to Radians'
 * '<S71>'  : 'ctrl_TAPM/Thrust allocation/Optimal angle path and  constraints on rotation speed/Ensuring angle is  [-pi pi]'
 * '<S72>'  : 'ctrl_TAPM/Thrust allocation/Optimal angle path and  constraints on rotation speed/MATLAB Function1'
 * '<S73>'  : 'ctrl_TAPM/Thruster control /Subsystem1'
 * '<S74>'  : 'ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM'
 * '<S75>'  : 'ctrl_TAPM/Thruster control /Thruster 1'
 * '<S76>'  : 'ctrl_TAPM/Thruster control /Thruster 2'
 * '<S77>'  : 'ctrl_TAPM/Thruster control /Thruster 3'
 * '<S78>'  : 'ctrl_TAPM/Thruster control /Thruster 4'
 * '<S79>'  : 'ctrl_TAPM/Thruster control /Thruster 5'
 * '<S80>'  : 'ctrl_TAPM/Thruster control /Thruster 6'
 * '<S81>'  : 'ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function'
 * '<S82>'  : 'ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function1'
 * '<S83>'  : 'ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function2'
 * '<S84>'  : 'ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function3'
 * '<S85>'  : 'ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function4'
 * '<S86>'  : 'ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function5'
 * '<S87>'  : 'ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function6'
 * '<S88>'  : 'ctrl_TAPM/Thruster control /Thruster 1/Propeller Hydrodynamics'
 * '<S89>'  : 'ctrl_TAPM/Thruster control /Thruster 1/Shaft dynamics'
 * '<S90>'  : 'ctrl_TAPM/Thruster control /Thruster 1/Thruster control'
 * '<S91>'  : 'ctrl_TAPM/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S92>'  : 'ctrl_TAPM/Thruster control /Thruster 1/Thruster control/Core controller'
 * '<S93>'  : 'ctrl_TAPM/Thruster control /Thruster 1/Thruster control/Discrete Derivative'
 * '<S94>'  : 'ctrl_TAPM/Thruster control /Thruster 1/Thruster control/MATLAB Function'
 * '<S95>'  : 'ctrl_TAPM/Thruster control /Thruster 1/Thruster control/Supervisor'
 * '<S96>'  : 'ctrl_TAPM/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S97>'  : 'ctrl_TAPM/Thruster control /Thruster 2/Propeller Hydrodynamics'
 * '<S98>'  : 'ctrl_TAPM/Thruster control /Thruster 2/Shaft dynamics'
 * '<S99>'  : 'ctrl_TAPM/Thruster control /Thruster 2/Thruster control'
 * '<S100>' : 'ctrl_TAPM/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S101>' : 'ctrl_TAPM/Thruster control /Thruster 2/Thruster control/Core controller'
 * '<S102>' : 'ctrl_TAPM/Thruster control /Thruster 2/Thruster control/Discrete Derivative'
 * '<S103>' : 'ctrl_TAPM/Thruster control /Thruster 2/Thruster control/MATLAB Function'
 * '<S104>' : 'ctrl_TAPM/Thruster control /Thruster 2/Thruster control/Supervisor'
 * '<S105>' : 'ctrl_TAPM/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S106>' : 'ctrl_TAPM/Thruster control /Thruster 3/Propeller Hydrodynamics'
 * '<S107>' : 'ctrl_TAPM/Thruster control /Thruster 3/Shaft dynamics'
 * '<S108>' : 'ctrl_TAPM/Thruster control /Thruster 3/Thruster control'
 * '<S109>' : 'ctrl_TAPM/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S110>' : 'ctrl_TAPM/Thruster control /Thruster 3/Thruster control/Core controller'
 * '<S111>' : 'ctrl_TAPM/Thruster control /Thruster 3/Thruster control/Discrete Derivative'
 * '<S112>' : 'ctrl_TAPM/Thruster control /Thruster 3/Thruster control/MATLAB Function'
 * '<S113>' : 'ctrl_TAPM/Thruster control /Thruster 3/Thruster control/Supervisor'
 * '<S114>' : 'ctrl_TAPM/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S115>' : 'ctrl_TAPM/Thruster control /Thruster 4/Propeller Hydrodynamics'
 * '<S116>' : 'ctrl_TAPM/Thruster control /Thruster 4/Shaft dynamics'
 * '<S117>' : 'ctrl_TAPM/Thruster control /Thruster 4/Thruster control'
 * '<S118>' : 'ctrl_TAPM/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S119>' : 'ctrl_TAPM/Thruster control /Thruster 4/Thruster control/Core controller'
 * '<S120>' : 'ctrl_TAPM/Thruster control /Thruster 4/Thruster control/Discrete Derivative'
 * '<S121>' : 'ctrl_TAPM/Thruster control /Thruster 4/Thruster control/MATLAB Function'
 * '<S122>' : 'ctrl_TAPM/Thruster control /Thruster 4/Thruster control/Supervisor'
 * '<S123>' : 'ctrl_TAPM/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S124>' : 'ctrl_TAPM/Thruster control /Thruster 5/Propeller Hydrodynamics'
 * '<S125>' : 'ctrl_TAPM/Thruster control /Thruster 5/Shaft dynamics'
 * '<S126>' : 'ctrl_TAPM/Thruster control /Thruster 5/Thruster control'
 * '<S127>' : 'ctrl_TAPM/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S128>' : 'ctrl_TAPM/Thruster control /Thruster 5/Thruster control/Core controller'
 * '<S129>' : 'ctrl_TAPM/Thruster control /Thruster 5/Thruster control/Discrete Derivative'
 * '<S130>' : 'ctrl_TAPM/Thruster control /Thruster 5/Thruster control/MATLAB Function'
 * '<S131>' : 'ctrl_TAPM/Thruster control /Thruster 5/Thruster control/Supervisor'
 * '<S132>' : 'ctrl_TAPM/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S133>' : 'ctrl_TAPM/Thruster control /Thruster 6/Propeller Hydrodynamics'
 * '<S134>' : 'ctrl_TAPM/Thruster control /Thruster 6/Shaft dynamics'
 * '<S135>' : 'ctrl_TAPM/Thruster control /Thruster 6/Thruster control'
 * '<S136>' : 'ctrl_TAPM/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S137>' : 'ctrl_TAPM/Thruster control /Thruster 6/Thruster control/Core controller'
 * '<S138>' : 'ctrl_TAPM/Thruster control /Thruster 6/Thruster control/Discrete Derivative'
 * '<S139>' : 'ctrl_TAPM/Thruster control /Thruster 6/Thruster control/MATLAB Function'
 * '<S140>' : 'ctrl_TAPM/Thruster control /Thruster 6/Thruster control/Supervisor'
 * '<S141>' : 'ctrl_TAPM/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 */
#endif                                 /* RTW_HEADER_ctrl_TAPM_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_TAPM
 * Model version : 1.190
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Thu Apr 20 19:54:33 2017
 *========================================================================*/
#ifdef NI_ROOTMODEL_ctrl_TAPM

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* ctrl_TAPM.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_ctrl_TAPM_T rtParameter[NUMST+!TID01EQ];
P_ctrl_TAPM_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_ctrl_TAPM_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_ctrl_TAPM_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_ctrl_TAPM_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
