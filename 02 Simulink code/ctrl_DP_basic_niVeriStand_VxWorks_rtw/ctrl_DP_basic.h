/*
 * ctrl_DP_basic.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_DP_basic".
 *
 * Model version              : 1.63
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue May 10 14:07:11 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_DP_basic_h_
#define RTW_HEADER_ctrl_DP_basic_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ctrl_DP_basic_COMMON_INCLUDES_
# define ctrl_DP_basic_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_DP_basic_COMMON_INCLUDES_ */

#include "ctrl_DP_basic_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
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
#define ctrl_DP_basic_rtModel          RT_MODEL_ctrl_DP_basic_T

/* Block signals for system '<S24>/MATLAB Function' */
typedef struct {
  real_T K_p[9];                       /* '<S24>/MATLAB Function' */
} B_MATLABFunction_ctrl_DP_basi_T;

/* Block signals for system '<S24>/MATLAB Function1' */
typedef struct {
  real_T K_i[9];                       /* '<S24>/MATLAB Function1' */
} B_MATLABFunction1_ctrl_DP_bas_T;

/* Block signals for system '<S24>/MATLAB Function2' */
typedef struct {
  real_T K_d[9];                       /* '<S24>/MATLAB Function2' */
} B_MATLABFunction2_ctrl_DP_bas_T;

/* Block signals for system '<S46>/CoreSubsys' */
typedef struct {
  real_T angle;                        /* '<S46>/Discrete-Time Integrator' */
  real_T Delay;                        /* '<S46>/Delay' */
  real_T MaxRotationRate;              /* '<S46>/Max Rotation Rate' */
} B_CoreSubsys_ctrl_DP_basic_T;

/* Block states (auto storage) for system '<S46>/CoreSubsys' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S46>/Discrete-Time Integrator' */
  real_T Delay_DSTATE;                 /* '<S46>/Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S46>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S46>/Discrete-Time Integrator' */
} DW_CoreSubsys_ctrl_DP_basic_T;

/* Block signals for system '<S61>/Actual Force and Torque' */
typedef struct {
  real_T Ta;                           /* '<S61>/Actual Force and Torque' */
  real_T Qa;                           /* '<S61>/Actual Force and Torque' */
} B_ActualForceandTorque_ctrl_D_T;

/* Block signals for system '<S65>/Core controller: Torque,Power and Combined Torque//Power' */
typedef struct {
  real_T Qcq;                          /* '<S65>/Core controller: Torque,Power and Combined Torque//Power' */
  real_T Qcp;                          /* '<S65>/Core controller: Torque,Power and Combined Torque//Power' */
  real_T Qcc;                          /* '<S65>/Core controller: Torque,Power and Combined Torque//Power' */
} B_CorecontrollerTorquePoweran_T;

/* Block signals for system '<S63>/Supervisor' */
typedef struct {
  real_T u;                            /* '<S63>/Supervisor' */
} B_Supervisor_ctrl_DP_basic_T;

/* Block signals for system '<S73>/MATLAB Function' */
typedef struct {
  real_T n_d;                          /* '<S73>/MATLAB Function' */
  real_T T_r;                          /* '<S73>/MATLAB Function' */
} B_MATLABFunction_ctrl_DP_ba_l_T;

/* Block signals for system '<S73>/Torque limit' */
typedef struct {
  real_T Q_c;                          /* '<S73>/Torque limit' */
} B_Torquelimit_ctrl_DP_basic_T;

/* Block signals (auto storage) */
typedef struct {
  real_T reset;                        /* '<S62>/reset' */
  real_T DiscreteTimeIntegrator;       /* '<S62>/Discrete-Time Integrator' */
  real_T reset_n;                      /* '<S72>/reset' */
  real_T DiscreteTimeIntegrator_m;     /* '<S72>/Discrete-Time Integrator' */
  real_T reset_d;                      /* '<S82>/reset' */
  real_T DiscreteTimeIntegrator_p;     /* '<S82>/Discrete-Time Integrator' */
  real_T reset_l;                      /* '<S92>/reset' */
  real_T DiscreteTimeIntegrator_j;     /* '<S92>/Discrete-Time Integrator' */
  real_T reset_e;                      /* '<S102>/reset' */
  real_T DiscreteTimeIntegrator_c;     /* '<S102>/Discrete-Time Integrator' */
  real_T reset_a;                      /* '<S112>/reset' */
  real_T DiscreteTimeIntegrator_d;     /* '<S112>/Discrete-Time Integrator' */
  real_T pwmthruster1;                 /* '<S52>/pwm thruster 1' */
  real_T x;                            /* '<Root>/x' */
  real_T pwmthruster2;                 /* '<S52>/pwm thruster 2' */
  real_T y;                            /* '<Root>/y' */
  real_T pwmthruster3;                 /* '<S52>/pwm thruster 3' */
  real_T psi;                          /* '<Root>/psi' */
  real_T pwmthruster4;                 /* '<S52>/pwm thruster 4' */
  real_T pwmthruster5;                 /* '<S52>/pwm thruster 5' */
  real_T K_p_x;                        /* '<S24>/K_p_x' */
  real_T K_p_y;                        /* '<S24>/K_p_y' */
  real_T K_p_psi;                      /* '<S24>/K_p_psi' */
  real_T K_i_psi;                      /* '<S24>/K_i_psi' */
  real_T K_i_x;                        /* '<S24>/K_i_x' */
  real_T K_i_y;                        /* '<S24>/K_i_y' */
  real_T K_d_psi;                      /* '<S24>/K_d_psi' */
  real_T K_d_x;                        /* '<S24>/K_d_x' */
  real_T K_d_y;                        /* '<S24>/K_d_y' */
  real_T reset_g;                      /* '<S5>/reset' */
  real_T w_d_x;                        /* '<S25>/w_d_x' */
  real_T w_d_y;                        /* '<S25>/w_d_y' */
  real_T w_d_psi;                      /* '<S25>/w_d_psi' */
  real_T zeta_psi;                     /* '<S25>/zeta_psi' */
  real_T zeta_x;                       /* '<S25>/zeta_x' */
  real_T zeta_y;                       /* '<S25>/zeta_y' */
  real_T psi_ref;                      /* '<S5>/psi_ref' */
  real_T x_ref;                        /* '<S5>/x_ref' */
  real_T y_ref;                        /* '<S5>/y_ref' */
  real_T Integrator1[3];               /* '<S17>/Integrator1' */
  real_T Sum;                          /* '<S18>/Sum' */
  real_T TmpSignalConversionAtMatrixMult[3];
  real_T regulationerror[3];           /* '<S12>/Sum2' */
  real_T TmpSignalConversionAtMatrixMu_m[3];/* '<S12>/Transposed rotation  matrix in yaw1' */
  real_T Integrator1_g[3];             /* '<S6>/Integrator1' */
  real_T Integrator3[3];               /* '<S17>/Integrator3' */
  real_T Sum4[3];                      /* '<S12>/Sum4' */
  real_T Sum3[3];                      /* '<S12>/Sum3' */
  real_T thr_angle_2;                  /* '<S11>/thr_angle_2' */
  real_T thr_angle_3;                  /* '<S11>/thr_angle_3' */
  real_T thr_angle_4;                  /* '<S11>/thr_angle_4' */
  real_T thr_angle_5;                  /* '<S11>/thr_angle_5' */
  real_T thr_angle_6;                  /* '<S11>/thr_angle_6' */
  real_T thr_angle_1;                  /* '<S11>/thr_angle_1' */
  real_T ChoosingFixedAzimuthangle[6]; /* '<S9>/Choosing Fixed // Azimuth angle' */
  real_T reset_a3[6];                  /* '<S9>/reset' */
  real_T Saturation1;                  /* '<S53>/Saturation 1' */
  real_T pwmthruster6;                 /* '<S52>/pwm thruster 6' */
  real_T Saturation2;                  /* '<S53>/Saturation 2' */
  real_T Saturation3;                  /* '<S53>/Saturation 3' */
  real_T Saturation4;                  /* '<S53>/Saturation 4' */
  real_T Saturation5;                  /* '<S53>/Saturation 5' */
  real_T Saturation6;                  /* '<S53>/Saturation 6' */
  real_T Saturation7[6];               /* '<S52>/Saturation 7' */
  real_T Integrator[3];                /* '<S6>/Integrator' */
  real_T Sum_f;                        /* '<S40>/Sum' */
  real_T Integrator2[3];               /* '<S6>/Integrator2' */
  real_T M1[3];                        /* '<S6>/M^-1' */
  real_T MatrixMultiply[3];            /* '<S17>/Matrix Multiply' */
  real_T Sum5[3];                      /* '<S17>/Sum5' */
  real_T MatrixMultiply1[3];           /* '<S6>/Matrix Multiply1' */
  real_T Sum1[3];                      /* '<S6>/Sum1' */
  real_T Delay;                        /* '<S63>/Delay' */
  real_T DiscreteTransferFcn;          /* '<S63>/Discrete Transfer Fcn' */
  real_T TSamp;                        /* '<S66>/TSamp' */
  real_T Inertiacompensation;          /* '<S63>/Inertia compensation' */
  real_T Sum1_o;                       /* '<S63>/Sum1' */
  real_T Memory;                       /* '<S63>/Memory' */
  real_T reset_i;                      /* '<S65>/reset' */
  real_T Sum1_m;                       /* '<S65>/Sum1' */
  real_T Findingrotationspeed;         /* '<S62>/Finding rotation speed' */
  real_T Ki;                           /* '<S65>/Ki' */
  real_T Delay_o;                      /* '<S73>/Delay' */
  real_T DiscreteTransferFcn_p;        /* '<S73>/Discrete Transfer Fcn' */
  real_T TSamp_f;                      /* '<S76>/TSamp' */
  real_T Inertiacompensation_d;        /* '<S73>/Inertia compensation' */
  real_T Sum1_mw;                      /* '<S73>/Sum1' */
  real_T Memory_c;                     /* '<S73>/Memory' */
  real_T reset_ig;                     /* '<S75>/reset' */
  real_T Sum1_g;                       /* '<S75>/Sum1' */
  real_T Findingrotationspeed_i;       /* '<S72>/Finding rotation speed' */
  real_T Ki_j;                         /* '<S75>/Ki' */
  real_T Delay_oq;                     /* '<S83>/Delay' */
  real_T DiscreteTransferFcn_b;        /* '<S83>/Discrete Transfer Fcn' */
  real_T TSamp_d;                      /* '<S86>/TSamp' */
  real_T Inertiacompensation_f;        /* '<S83>/Inertia compensation' */
  real_T Sum1_a;                       /* '<S83>/Sum1' */
  real_T Memory_m;                     /* '<S83>/Memory' */
  real_T reset_j;                      /* '<S85>/reset' */
  real_T Sum1_n;                       /* '<S85>/Sum1' */
  real_T Findingrotationspeed_n;       /* '<S82>/Finding rotation speed' */
  real_T Ki_o;                         /* '<S85>/Ki' */
  real_T Delay_a;                      /* '<S93>/Delay' */
  real_T DiscreteTransferFcn_h;        /* '<S93>/Discrete Transfer Fcn' */
  real_T TSamp_p;                      /* '<S96>/TSamp' */
  real_T Inertiacompensation_a;        /* '<S93>/Inertia compensation' */
  real_T Sum1_f;                       /* '<S93>/Sum1' */
  real_T Memory_j;                     /* '<S93>/Memory' */
  real_T reset_o;                      /* '<S95>/reset' */
  real_T Sum1_b;                       /* '<S95>/Sum1' */
  real_T Findingrotationspeed_nl;      /* '<S92>/Finding rotation speed' */
  real_T Ki_c;                         /* '<S95>/Ki' */
  real_T Delay_i;                      /* '<S103>/Delay' */
  real_T DiscreteTransferFcn_j;        /* '<S103>/Discrete Transfer Fcn' */
  real_T TSamp_j;                      /* '<S106>/TSamp' */
  real_T Inertiacompensation_i;        /* '<S103>/Inertia compensation' */
  real_T Sum1_h;                       /* '<S103>/Sum1' */
  real_T Memory_i;                     /* '<S103>/Memory' */
  real_T reset_n5;                     /* '<S105>/reset' */
  real_T Sum1_hb;                      /* '<S105>/Sum1' */
  real_T Findingrotationspeed_b;       /* '<S102>/Finding rotation speed' */
  real_T Ki_b;                         /* '<S105>/Ki' */
  real_T Delay_od;                     /* '<S113>/Delay' */
  real_T DiscreteTransferFcn_jz;       /* '<S113>/Discrete Transfer Fcn' */
  real_T TSamp_o;                      /* '<S116>/TSamp' */
  real_T Inertiacompensation_p;        /* '<S113>/Inertia compensation' */
  real_T Sum1_c;                       /* '<S113>/Sum1' */
  real_T Memory_b;                     /* '<S113>/Memory' */
  real_T reset_b;                      /* '<S115>/reset' */
  real_T Sum1_d;                       /* '<S115>/Sum1' */
  real_T Findingrotationspeed_l;       /* '<S112>/Finding rotation speed' */
  real_T Ki_cv;                        /* '<S115>/Ki' */
  real_T Row3;                         /* '<S23>/Row3' */
  real_T Row1;                         /* '<S23>/Row1' */
  real_T Row2;                         /* '<S23>/Row2' */
  real_T n_d;                          /* '<S113>/MATLAB Function' */
  real_T Q_c;                          /* '<S63>/Torque limit' */
  real_T n_d_l;                        /* '<S63>/MATLAB Function' */
  B_Torquelimit_ctrl_DP_basic_T sf_Torquelimit_f;/* '<S113>/Torque limit' */
  B_Supervisor_ctrl_DP_basic_T sf_Supervisor_a;/* '<S113>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePower_ol;/* '<S115>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_D_T sf_ActualForceandTorque_a;/* '<S111>/Actual Force and Torque' */
  B_Torquelimit_ctrl_DP_basic_T sf_Torquelimit_c;/* '<S103>/Torque limit' */
  B_Supervisor_ctrl_DP_basic_T sf_Supervisor_n;/* '<S103>/Supervisor' */
  B_MATLABFunction_ctrl_DP_ba_l_T sf_MATLABFunction_c;/* '<S103>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePower_c1;/* '<S105>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_D_T sf_ActualForceandTorque_fi;/* '<S101>/Actual Force and Torque' */
  B_Torquelimit_ctrl_DP_basic_T sf_Torquelimit_g;/* '<S93>/Torque limit' */
  B_Supervisor_ctrl_DP_basic_T sf_Supervisor_cp;/* '<S93>/Supervisor' */
  B_MATLABFunction_ctrl_DP_ba_l_T sf_MATLABFunction_j;/* '<S93>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_o;/* '<S95>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_D_T sf_ActualForceandTorque_f;/* '<S91>/Actual Force and Torque' */
  B_Torquelimit_ctrl_DP_basic_T sf_Torquelimit_e;/* '<S83>/Torque limit' */
  B_Supervisor_ctrl_DP_basic_T sf_Supervisor_c;/* '<S83>/Supervisor' */
  B_MATLABFunction_ctrl_DP_ba_l_T sf_MATLABFunction_n;/* '<S83>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_c;/* '<S85>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_D_T sf_ActualForceandTorque_c;/* '<S81>/Actual Force and Torque' */
  B_Torquelimit_ctrl_DP_basic_T sf_Torquelimit_a;/* '<S73>/Torque limit' */
  B_Supervisor_ctrl_DP_basic_T sf_Supervisor_l;/* '<S73>/Supervisor' */
  B_MATLABFunction_ctrl_DP_ba_l_T sf_MATLABFunction_d;/* '<S73>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_a;/* '<S75>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_D_T sf_ActualForceandTorque_o;/* '<S71>/Actual Force and Torque' */
  B_Supervisor_ctrl_DP_basic_T sf_Supervisor;/* '<S63>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowerand;/* '<S65>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_D_T sf_ActualForceandTorque;/* '<S61>/Actual Force and Torque' */
  B_CoreSubsys_ctrl_DP_basic_T CoreSubsys[6];/* '<S46>/CoreSubsys' */
  B_MATLABFunction2_ctrl_DP_bas_T sf_MATLABFunction2_p;/* '<S26>/MATLAB Function2' */
  B_MATLABFunction1_ctrl_DP_bas_T sf_MATLABFunction1_c;/* '<S26>/MATLAB Function1' */
  B_MATLABFunction_ctrl_DP_basi_T sf_MATLABFunction_l;/* '<S26>/MATLAB Function' */
  B_MATLABFunction2_ctrl_DP_bas_T sf_MATLABFunction2;/* '<S24>/MATLAB Function2' */
  B_MATLABFunction1_ctrl_DP_bas_T sf_MATLABFunction1;/* '<S24>/MATLAB Function1' */
  B_MATLABFunction_ctrl_DP_basi_T sf_MATLABFunction_g;/* '<S24>/MATLAB Function' */
} B_ctrl_DP_basic_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S62>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_h;/* '<S72>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S82>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S92>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S102>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_hl;/* '<S112>/Discrete-Time Integrator' */
  real_T Delay_DSTATE;                 /* '<S54>/Delay' */
  real_T Delay_DSTATE_j;               /* '<S63>/Delay' */
  real_T DiscreteTransferFcn_states[2];/* '<S63>/Discrete Transfer Fcn' */
  real_T UD_DSTATE;                    /* '<S66>/UD' */
  real_T DiscreteTimeIntegrator_DSTAT_fu;/* '<S65>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_b; /* '<S54>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_l;               /* '<S55>/Delay' */
  real_T Delay_DSTATE_e;               /* '<S73>/Delay' */
  real_T DiscreteTransferFcn_states_j[2];/* '<S73>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_j;                  /* '<S76>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S75>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_e; /* '<S55>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_p;               /* '<S56>/Delay' */
  real_T Delay_DSTATE_f;               /* '<S83>/Delay' */
  real_T DiscreteTransferFcn_states_c[2];/* '<S83>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_g;                  /* '<S86>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S85>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_i; /* '<S56>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_d;               /* '<S57>/Delay' */
  real_T Delay_DSTATE_ev;              /* '<S93>/Delay' */
  real_T DiscreteTransferFcn_states_m[2];/* '<S93>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_o;                  /* '<S96>/UD' */
  real_T DiscreteTimeIntegrator_DSTAT_hx;/* '<S95>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_ms;/* '<S57>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_du;              /* '<S58>/Delay' */
  real_T Delay_DSTATE_n;               /* '<S103>/Delay' */
  real_T DiscreteTransferFcn_states_f[2];/* '<S103>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_n;                  /* '<S106>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S105>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_ix;/* '<S58>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_k;               /* '<S59>/Delay' */
  real_T Delay_DSTATE_o;               /* '<S113>/Delay' */
  real_T DiscreteTransferFcn_states_k[2];/* '<S113>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_d;                  /* '<S116>/UD' */
  real_T DiscreteTimeIntegrator_DSTAT_gt;/* '<S115>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_l; /* '<S59>/Discrete Transfer Fcn' */
  real_T reset_DWORK1;                 /* '<S62>/reset' */
  real_T reset_DWORK1_c;               /* '<S72>/reset' */
  real_T reset_DWORK1_j;               /* '<S82>/reset' */
  real_T reset_DWORK1_m;               /* '<S92>/reset' */
  real_T reset_DWORK1_a;               /* '<S102>/reset' */
  real_T reset_DWORK1_b;               /* '<S112>/reset' */
  real_T pwm_1_DWORK1;                 /* '<Root>/pwm_1' */
  real_T x_DWORK1;                     /* '<Root>/x' */
  real_T pwm_2_DWORK1;                 /* '<Root>/pwm_2' */
  real_T y_DWORK1;                     /* '<Root>/y' */
  real_T pwm_3_DWORK1;                 /* '<Root>/pwm_3' */
  real_T psi_DWORK1;                   /* '<Root>/psi' */
  real_T pwm_4_DWORK1;                 /* '<Root>/pwm_4' */
  real_T pwm_5_DWORK1;                 /* '<Root>/pwm_5' */
  real_T K_p_x_DWORK1;                 /* '<S24>/K_p_x' */
  real_T K_p_y_DWORK1;                 /* '<S24>/K_p_y' */
  real_T K_p_psi_DWORK1;               /* '<S24>/K_p_psi' */
  real_T K_i_psi_DWORK1;               /* '<S24>/K_i_psi' */
  real_T K_i_x_DWORK1;                 /* '<S24>/K_i_x' */
  real_T K_i_y_DWORK1;                 /* '<S24>/K_i_y' */
  real_T K_d_psi_DWORK1;               /* '<S24>/K_d_psi' */
  real_T K_d_x_DWORK1;                 /* '<S24>/K_d_x' */
  real_T K_d_y_DWORK1;                 /* '<S24>/K_d_y' */
  real_T reset_DWORK1_k;               /* '<S5>/reset' */
  real_T w_d_x_DWORK1;                 /* '<S25>/w_d_x' */
  real_T w_d_y_DWORK1;                 /* '<S25>/w_d_y' */
  real_T w_d_psi_DWORK1;               /* '<S25>/w_d_psi' */
  real_T zeta_psi_DWORK1;              /* '<S25>/zeta_psi' */
  real_T zeta_x_DWORK1;                /* '<S25>/zeta_x' */
  real_T zeta_y_DWORK1;                /* '<S25>/zeta_y' */
  real_T psi_ref_DWORK1;               /* '<S5>/psi_ref' */
  real_T x_ref_DWORK1;                 /* '<S5>/x_ref' */
  real_T y_ref_DWORK1;                 /* '<S5>/y_ref' */
  real_T thr_angle_2_DWORK1;           /* '<S11>/thr_angle_2' */
  real_T thr_angle_3_DWORK1;           /* '<S11>/thr_angle_3' */
  real_T thr_angle_4_DWORK1;           /* '<S11>/thr_angle_4' */
  real_T thr_angle_5_DWORK1;           /* '<S11>/thr_angle_5' */
  real_T thr_angle_6_DWORK1;           /* '<S11>/thr_angle_6' */
  real_T thr_angle_1_DWORK1;           /* '<S11>/thr_angle_1' */
  real_T reset_DWORK1_e[6];            /* '<S9>/reset' */
  real_T alpha_1_DWORK1;               /* '<Root>/alpha_1' */
  real_T pwm_6_DWORK1;                 /* '<Root>/pwm_6' */
  real_T alpha_2_DWORK1;               /* '<Root>/alpha_2' */
  real_T alpha_3_DWORK1;               /* '<Root>/alpha_3' */
  real_T alpha_4_DWORK1;               /* '<Root>/alpha_4' */
  real_T alpha_5_DWORK1;               /* '<Root>/alpha_5' */
  real_T alpha_6_DWORK1;               /* '<Root>/alpha_6' */
  real_T u_4_DWORK1;                   /* '<Root>/u_4' */
  real_T u_5_DWORK1;                   /* '<Root>/u_5' */
  real_T u_6_DWORK1;                   /* '<Root>/u_6' */
  real_T u_1_DWORK1;                   /* '<Root>/u_1' */
  real_T u_2_DWORK1;                   /* '<Root>/u_2' */
  real_T x_hat_DWORK1;                 /* '<S43>/x_hat' */
  real_T y_hat_DWORK1;                 /* '<S43>/y_hat' */
  real_T psi_hat_DWORK1;               /* '<S43>/psi_hat' */
  real_T u_hat_DWORK1;                 /* '<S45>/u_hat' */
  real_T v_hat_DWORK1;                 /* '<S45>/v_hat' */
  real_T r_hat_DWORK1;                 /* '<S45>/r_hat' */
  real_T u_dot_hat_DWORK1;             /* '<S44>/u_dot_hat' */
  real_T v_dot_hat_DWORK1;             /* '<S44>/v_dot_hat' */
  real_T r_dot_hat_DWORK1;             /* '<S44>/r_dot_hat' */
  real_T b_x_hat_DWORK1;               /* '<S42>/b_x_hat' */
  real_T b_y_hat_DWORK1;               /* '<S42>/b_y_hat' */
  real_T b_psi_hat_DWORK1;             /* '<S42>/b_psi_hat' */
  real_T u_3_DWORK1;                   /* '<Root>/u_3' */
  real_T eta_des_DWORK1[3];            /* '<S3>/eta_des' */
  real_T DiscreteTransferFcn_tmp;      /* '<S63>/Discrete Transfer Fcn' */
  real_T PrevY;                        /* '<S63>/Acceleration Limit' */
  real_T Memory_PreviousInput;         /* '<S63>/Memory' */
  real_T reset_DWORK1_o;               /* '<S65>/reset' */
  real_T DiscreteTransferFcn_tmp_m;    /* '<S54>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_k;    /* '<S73>/Discrete Transfer Fcn' */
  real_T PrevY_e;                      /* '<S73>/Acceleration Limit' */
  real_T Memory_PreviousInput_e;       /* '<S73>/Memory' */
  real_T reset_DWORK1_js;              /* '<S75>/reset' */
  real_T DiscreteTransferFcn_tmp_ku;   /* '<S55>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_k4;   /* '<S83>/Discrete Transfer Fcn' */
  real_T PrevY_f;                      /* '<S83>/Acceleration limiter' */
  real_T Memory_PreviousInput_i;       /* '<S83>/Memory' */
  real_T reset_DWORK1_h;               /* '<S85>/reset' */
  real_T DiscreteTransferFcn_tmp_i;    /* '<S56>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_o;    /* '<S93>/Discrete Transfer Fcn' */
  real_T PrevY_l;                      /* '<S93>/Acceleration limiter' */
  real_T Memory_PreviousInput_l;       /* '<S93>/Memory' */
  real_T reset_DWORK1_eg;              /* '<S95>/reset' */
  real_T DiscreteTransferFcn_tmp_b;    /* '<S57>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_a;    /* '<S103>/Discrete Transfer Fcn' */
  real_T PrevY_c;                      /* '<S103>/Acceleration limiter' */
  real_T Memory_PreviousInput_m;       /* '<S103>/Memory' */
  real_T reset_DWORK1_n;               /* '<S105>/reset' */
  real_T DiscreteTransferFcn_tmp_p;    /* '<S58>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_aj;   /* '<S113>/Discrete Transfer Fcn' */
  real_T PrevY_ca;                     /* '<S113>/Acceleration limiter' */
  real_T Memory_PreviousInput_p;       /* '<S113>/Memory' */
  real_T reset_DWORK1_g;               /* '<S115>/reset' */
  real_T DiscreteTransferFcn_tmp_d;    /* '<S59>/Discrete Transfer Fcn' */
  real_T tau_N_DWORK1;                 /* '<S2>/tau_N' */
  real_T tau_X_DWORK1;                 /* '<S2>/tau_X' */
  real_T tau_Y_DWORK1;                 /* '<S2>/tau_Y' */
  real_T psi_tilde_DWORK1;             /* '<S2>/psi_tilde' */
  real_T x_tilde_DWORK1;               /* '<S2>/x_tilde' */
  real_T y_tidle_DWORK1;               /* '<S2>/y_tidle' */
  real_T r_tilde_DWORK1;               /* '<S2>/r_tilde' */
  real_T u_tilde_DWORK1;               /* '<S2>/u_tilde' */
  real_T v_tilde_DWORK1;               /* '<S2>/v_tilde' */
  real_T x_d_DWORK1;                   /* '<S4>/x_d' */
  real_T y_d_DWORK1;                   /* '<S4>/y_d' */
  real_T psi_d_DWORK1;                 /* '<S4>/psi_d' */
  real_T r_d_DWORK1;                   /* '<S4>/r_d' */
  real_T u_d_DWORK1;                   /* '<S4>/u_d' */
  real_T v_d_DWORK1;                   /* '<S4>/v_d' */
  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK;                 /* '<S17>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S6>/Integrator' */

  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S62>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S72>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_n;/* '<S82>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_b;/* '<S92>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S102>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_m;/* '<S112>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_em;/* '<S65>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S75>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_k;/* '<S85>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S95>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S105>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S115>/Discrete-Time Integrator' */
  uint8_T reset_DWORK2[14];            /* '<S62>/reset' */
  uint8_T reset_DWORK2_k[14];          /* '<S72>/reset' */
  uint8_T reset_DWORK2_b[14];          /* '<S82>/reset' */
  uint8_T reset_DWORK2_o[14];          /* '<S92>/reset' */
  uint8_T reset_DWORK2_j[14];          /* '<S102>/reset' */
  uint8_T reset_DWORK2_j5[14];         /* '<S112>/reset' */
  uint8_T pwm_1_DWORK2[14];            /* '<Root>/pwm_1' */
  uint8_T x_DWORK2[14];                /* '<Root>/x' */
  uint8_T pwm_2_DWORK2[14];            /* '<Root>/pwm_2' */
  uint8_T y_DWORK2[14];                /* '<Root>/y' */
  uint8_T pwm_3_DWORK2[14];            /* '<Root>/pwm_3' */
  uint8_T psi_DWORK2[14];              /* '<Root>/psi' */
  uint8_T pwm_4_DWORK2[14];            /* '<Root>/pwm_4' */
  uint8_T pwm_5_DWORK2[14];            /* '<Root>/pwm_5' */
  uint8_T K_p_x_DWORK2[14];            /* '<S24>/K_p_x' */
  uint8_T K_p_y_DWORK2[14];            /* '<S24>/K_p_y' */
  uint8_T K_p_psi_DWORK2[14];          /* '<S24>/K_p_psi' */
  uint8_T K_i_psi_DWORK2[14];          /* '<S24>/K_i_psi' */
  uint8_T K_i_x_DWORK2[14];            /* '<S24>/K_i_x' */
  uint8_T K_i_y_DWORK2[14];            /* '<S24>/K_i_y' */
  uint8_T K_d_psi_DWORK2[14];          /* '<S24>/K_d_psi' */
  uint8_T K_d_x_DWORK2[14];            /* '<S24>/K_d_x' */
  uint8_T K_d_y_DWORK2[14];            /* '<S24>/K_d_y' */
  uint8_T reset_DWORK2_f[14];          /* '<S5>/reset' */
  uint8_T w_d_x_DWORK2[14];            /* '<S25>/w_d_x' */
  uint8_T w_d_y_DWORK2[14];            /* '<S25>/w_d_y' */
  uint8_T w_d_psi_DWORK2[14];          /* '<S25>/w_d_psi' */
  uint8_T zeta_psi_DWORK2[14];         /* '<S25>/zeta_psi' */
  uint8_T zeta_x_DWORK2[14];           /* '<S25>/zeta_x' */
  uint8_T zeta_y_DWORK2[14];           /* '<S25>/zeta_y' */
  uint8_T psi_ref_DWORK2[14];          /* '<S5>/psi_ref' */
  uint8_T x_ref_DWORK2[14];            /* '<S5>/x_ref' */
  uint8_T y_ref_DWORK2[14];            /* '<S5>/y_ref' */
  uint8_T thr_angle_2_DWORK2[14];      /* '<S11>/thr_angle_2' */
  uint8_T thr_angle_3_DWORK2[14];      /* '<S11>/thr_angle_3' */
  uint8_T thr_angle_4_DWORK2[14];      /* '<S11>/thr_angle_4' */
  uint8_T thr_angle_5_DWORK2[14];      /* '<S11>/thr_angle_5' */
  uint8_T thr_angle_6_DWORK2[14];      /* '<S11>/thr_angle_6' */
  uint8_T thr_angle_1_DWORK2[14];      /* '<S11>/thr_angle_1' */
  uint8_T reset_DWORK2_d[14];          /* '<S9>/reset' */
  uint8_T alpha_1_DWORK2[14];          /* '<Root>/alpha_1' */
  uint8_T pwm_6_DWORK2[14];            /* '<Root>/pwm_6' */
  uint8_T alpha_2_DWORK2[14];          /* '<Root>/alpha_2' */
  uint8_T alpha_3_DWORK2[14];          /* '<Root>/alpha_3' */
  uint8_T alpha_4_DWORK2[14];          /* '<Root>/alpha_4' */
  uint8_T alpha_5_DWORK2[14];          /* '<Root>/alpha_5' */
  uint8_T alpha_6_DWORK2[14];          /* '<Root>/alpha_6' */
  uint8_T u_4_DWORK2[14];              /* '<Root>/u_4' */
  uint8_T u_5_DWORK2[14];              /* '<Root>/u_5' */
  uint8_T u_6_DWORK2[14];              /* '<Root>/u_6' */
  uint8_T u_1_DWORK2[14];              /* '<Root>/u_1' */
  uint8_T u_2_DWORK2[14];              /* '<Root>/u_2' */
  uint8_T x_hat_DWORK2[14];            /* '<S43>/x_hat' */
  uint8_T y_hat_DWORK2[14];            /* '<S43>/y_hat' */
  uint8_T psi_hat_DWORK2[14];          /* '<S43>/psi_hat' */
  uint8_T u_hat_DWORK2[14];            /* '<S45>/u_hat' */
  uint8_T v_hat_DWORK2[14];            /* '<S45>/v_hat' */
  uint8_T r_hat_DWORK2[14];            /* '<S45>/r_hat' */
  uint8_T u_dot_hat_DWORK2[14];        /* '<S44>/u_dot_hat' */
  uint8_T v_dot_hat_DWORK2[14];        /* '<S44>/v_dot_hat' */
  uint8_T r_dot_hat_DWORK2[14];        /* '<S44>/r_dot_hat' */
  uint8_T b_x_hat_DWORK2[14];          /* '<S42>/b_x_hat' */
  uint8_T b_y_hat_DWORK2[14];          /* '<S42>/b_y_hat' */
  uint8_T b_psi_hat_DWORK2[14];        /* '<S42>/b_psi_hat' */
  uint8_T u_3_DWORK2[14];              /* '<Root>/u_3' */
  uint8_T eta_des_DWORK2[14];          /* '<S3>/eta_des' */
  uint8_T reset_DWORK2_p[14];          /* '<S65>/reset' */
  uint8_T reset_DWORK2_dw[14];         /* '<S75>/reset' */
  uint8_T reset_DWORK2_h[14];          /* '<S85>/reset' */
  uint8_T reset_DWORK2_a[14];          /* '<S95>/reset' */
  uint8_T reset_DWORK2_e[14];          /* '<S105>/reset' */
  uint8_T reset_DWORK2_aw[14];         /* '<S115>/reset' */
  uint8_T tau_N_DWORK2[14];            /* '<S2>/tau_N' */
  uint8_T tau_X_DWORK2[14];            /* '<S2>/tau_X' */
  uint8_T tau_Y_DWORK2[14];            /* '<S2>/tau_Y' */
  uint8_T psi_tilde_DWORK2[14];        /* '<S2>/psi_tilde' */
  uint8_T x_tilde_DWORK2[14];          /* '<S2>/x_tilde' */
  uint8_T y_tidle_DWORK2[14];          /* '<S2>/y_tidle' */
  uint8_T r_tilde_DWORK2[14];          /* '<S2>/r_tilde' */
  uint8_T u_tilde_DWORK2[14];          /* '<S2>/u_tilde' */
  uint8_T v_tilde_DWORK2[14];          /* '<S2>/v_tilde' */
  uint8_T x_d_DWORK2[14];              /* '<S4>/x_d' */
  uint8_T y_d_DWORK2[14];              /* '<S4>/y_d' */
  uint8_T psi_d_DWORK2[14];            /* '<S4>/psi_d' */
  uint8_T r_d_DWORK2[14];              /* '<S4>/r_d' */
  uint8_T u_d_DWORK2[14];              /* '<S4>/u_d' */
  uint8_T v_d_DWORK2[14];              /* '<S4>/v_d' */
  DW_CoreSubsys_ctrl_DP_basic_T CoreSubsys[6];/* '<S46>/CoreSubsys' */
} DW_ctrl_DP_basic_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S17>/Integrator1' */
  real_T Integrator_CSTATE[3];         /* '<S12>/Integrator' */
  real_T Integrator1_CSTATE_g[3];      /* '<S6>/Integrator1' */
  real_T Integrator3_CSTATE[3];        /* '<S17>/Integrator3' */
  real_T Integrator_CSTATE_l[3];       /* '<S6>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S6>/Integrator2' */
  real_T Integrator2_CSTATE_e[3];      /* '<S17>/Integrator2' */
} X_ctrl_DP_basic_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S17>/Integrator1' */
  real_T Integrator_CSTATE[3];         /* '<S12>/Integrator' */
  real_T Integrator1_CSTATE_g[3];      /* '<S6>/Integrator1' */
  real_T Integrator3_CSTATE[3];        /* '<S17>/Integrator3' */
  real_T Integrator_CSTATE_l[3];       /* '<S6>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S6>/Integrator2' */
  real_T Integrator2_CSTATE_e[3];      /* '<S17>/Integrator2' */
} XDot_ctrl_DP_basic_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE[3];     /* '<S17>/Integrator1' */
  boolean_T Integrator_CSTATE[3];      /* '<S12>/Integrator' */
  boolean_T Integrator1_CSTATE_g[3];   /* '<S6>/Integrator1' */
  boolean_T Integrator3_CSTATE[3];     /* '<S17>/Integrator3' */
  boolean_T Integrator_CSTATE_l[3];    /* '<S6>/Integrator' */
  boolean_T Integrator2_CSTATE[3];     /* '<S6>/Integrator2' */
  boolean_T Integrator2_CSTATE_e[3];   /* '<S17>/Integrator2' */
} XDis_ctrl_DP_basic_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator1_Reset_ZCE;    /* '<S17>/Integrator1' */
  ZCSigState Integrator_Reset_ZCE;     /* '<S12>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE_e;  /* '<S6>/Integrator1' */
  ZCSigState Integrator3_Reset_ZCE;    /* '<S17>/Integrator3' */
  ZCSigState Integrator_Reset_ZCE_n;   /* '<S6>/Integrator' */
  ZCSigState Integrator2_Reset_ZCE;    /* '<S6>/Integrator2' */
  ZCSigState Integrator2_Reset_ZCE_m;  /* '<S17>/Integrator2' */
} PrevZCX_ctrl_DP_basic_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_DP_basic_B
#define BlockIO                        B_ctrl_DP_basic_T
#define rtX                            ctrl_DP_basic_X
#define ContinuousStates               X_ctrl_DP_basic_T
#define rtXdot                         ctrl_DP_basic_XDot
#define StateDerivatives               XDot_ctrl_DP_basic_T
#define tXdis                          ctrl_DP_basic_XDis
#define StateDisabled                  XDis_ctrl_DP_basic_T
#define rtP                            ctrl_DP_basic_P
#define Parameters                     P_ctrl_DP_basic_T
#define rtDWork                        ctrl_DP_basic_DW
#define D_Work                         DW_ctrl_DP_basic_T
#define rtPrevZCSigState               ctrl_DP_basic_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_DP_basic_T

/* Parameters for system: '<S46>/CoreSubsys' */
struct P_CoreSubsys_ctrl_DP_basic_T_ {
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S46>/Discrete-Time Integrator'
                                         */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S49>/Gain1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S46>/Delay'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S46>/Delay'
                                        */
};

/* Parameters (auto storage) */
struct P_ctrl_DP_basic_T_ {
  real_T C[24];                        /* Variable: C
                                        * Referenced by: '<S9>/C'
                                        */
  real_T D;                            /* Variable: D
                                        * Referenced by: '<S8>/D'
                                        */
  real_T I_s;                          /* Variable: I_s
                                        * Referenced by:
                                        *   '<S62>/Finding rotation speed'
                                        *   '<S63>/Inertia compensation'
                                        *   '<S72>/Finding rotation speed'
                                        *   '<S73>/Inertia compensation'
                                        *   '<S82>/Finding rotation speed'
                                        *   '<S83>/Inertia compensation'
                                        *   '<S92>/Finding rotation speed'
                                        *   '<S93>/Inertia compensation'
                                        *   '<S102>/Finding rotation speed'
                                        *   '<S103>/Inertia compensation'
                                        *   '<S112>/Finding rotation speed'
                                        *   '<S113>/Inertia compensation'
                                        */
  real_T K_omega;                      /* Variable: K_omega
                                        * Referenced by:
                                        *   '<S62>/K_omega'
                                        *   '<S63>/Qff_1(nr)'
                                        *   '<S72>/K_omega'
                                        *   '<S73>/Qff_1(nr)'
                                        *   '<S82>/K_omega'
                                        *   '<S83>/Qff_1(nr)'
                                        *   '<S92>/K_omega'
                                        *   '<S93>/Qff_1(nr)'
                                        *   '<S102>/K_omega'
                                        *   '<S103>/Qff_1(nr)'
                                        *   '<S112>/K_omega'
                                        *   '<S113>/Qff_1(nr)'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by:
                                        *   '<S65>/Ki'
                                        *   '<S65>/Kp'
                                        *   '<S75>/Ki'
                                        *   '<S75>/Kp'
                                        *   '<S85>/Ki'
                                        *   '<S85>/Kp'
                                        *   '<S95>/Ki'
                                        *   '<S95>/Kp'
                                        *   '<S105>/Ki'
                                        *   '<S105>/Kp'
                                        *   '<S115>/Ki'
                                        *   '<S115>/Kp'
                                        */
  real_T Kq;                           /* Variable: Kq
                                        * Referenced by: '<S8>/Kq'
                                        */
  real_T Kqr;                          /* Variable: Kqr
                                        * Referenced by: '<S8>/Kqr'
                                        */
  real_T Kt;                           /* Variable: Kt
                                        * Referenced by: '<S8>/Kt'
                                        */
  real_T Ktr;                          /* Variable: Ktr
                                        * Referenced by: '<S8>/Ktr'
                                        */
  real_T Max_rotation;                 /* Variable: Max_rotation
                                        * Referenced by: '<S46>/Max Rotation Rate'
                                        */
  real_T Max_thrust;                   /* Variable: Max_thrust
                                        * Referenced by:
                                        *   '<S52>/Saturation 1'
                                        *   '<S52>/Saturation 2'
                                        *   '<S52>/Saturation 3'
                                        *   '<S52>/Saturation 4'
                                        *   '<S52>/Saturation 5'
                                        *   '<S52>/Saturation 6'
                                        *   '<S52>/Saturation 7'
                                        */
  real_T P_max;                        /* Variable: P_max
                                        * Referenced by:
                                        *   '<S63>/P_max'
                                        *   '<S73>/P_max'
                                        *   '<S83>/P_max'
                                        *   '<S93>/P_max'
                                        *   '<S103>/P_max'
                                        *   '<S113>/P_max'
                                        */
  real_T Q_f0;                         /* Variable: Q_f0
                                        * Referenced by:
                                        *   '<S63>/Qf_0'
                                        *   '<S73>/Qf_0'
                                        *   '<S83>/Qf_0'
                                        *   '<S93>/Qf_0'
                                        *   '<S103>/Qf_0'
                                        *   '<S113>/Qf_0'
                                        */
  real_T Q_max;                        /* Variable: Q_max
                                        * Referenced by:
                                        *   '<S63>/Q_max'
                                        *   '<S73>/Q_max'
                                        *   '<S83>/Q_max'
                                        *   '<S93>/Q_max'
                                        *   '<S103>/Q_max'
                                        *   '<S113>/Q_max'
                                        *   '<S65>/Discrete-Time Integrator'
                                        */
  real_T Rho;                          /* Variable: Rho
                                        * Referenced by: '<S8>/Rho'
                                        */
  real_T Thruster_control;             /* Variable: Thruster_control
                                        * Referenced by:
                                        *   '<S63>/Switch controller'
                                        *   '<S73>/Switch controller'
                                        *   '<S83>/Switch controller'
                                        *   '<S93>/Switch controller'
                                        *   '<S103>/Switch controller'
                                        *   '<S113>/Switch controller'
                                        */
  real_T Thruster_lock;                /* Variable: Thruster_lock
                                        * Referenced by: '<S9>/Switch  Azimuth//Fixed angles'
                                        */
  real_T eps;                          /* Variable: eps
                                        * Referenced by:
                                        *   '<S8>/Constant4'
                                        *   '<S9>/Constant to avoid singularities'
                                        */
  real_T eps_c;                        /* Variable: eps_c
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T epsilon;                      /* Variable: epsilon
                                        * Referenced by:
                                        *   '<S63>/Qff_0(nr)'
                                        *   '<S73>/Qff_0(nr)'
                                        *   '<S83>/Qff_0(nr)'
                                        *   '<S93>/Qff_0(nr)'
                                        *   '<S103>/Qff_0(nr)'
                                        *   '<S113>/Qff_0(nr)'
                                        */
  real_T k_cc;                         /* Variable: k_cc
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T n_c;                          /* Variable: n_c
                                        * Referenced by: '<S8>/Constant5'
                                        */
  real_T n_max;                        /* Variable: n_max
                                        * Referenced by:
                                        *   '<S63>/Qff_0(nr)'
                                        *   '<S73>/Qff_0(nr)'
                                        *   '<S83>/Qff_0(nr)'
                                        *   '<S93>/Qff_0(nr)'
                                        *   '<S103>/Qff_0(nr)'
                                        *   '<S113>/Qff_0(nr)'
                                        */
  real_T p_cc;                         /* Variable: p_cc
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T r_cc;                         /* Variable: r_cc
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T thrust_to_pwm_coeff[6];       /* Variable: thrust_to_pwm_coeff
                                        * Referenced by:
                                        *   '<S52>/pwm thruster 1'
                                        *   '<S52>/pwm thruster 2'
                                        *   '<S52>/pwm thruster 3'
                                        *   '<S52>/pwm thruster 4'
                                        *   '<S52>/pwm thruster 5'
                                        *   '<S52>/pwm thruster 6'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S66>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_k;/* Mask Parameter: DiscreteDerivative_ICPrevScal_k
                                          * Referenced by: '<S76>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_l;/* Mask Parameter: DiscreteDerivative_ICPrevScal_l
                                          * Referenced by: '<S86>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_p;/* Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                          * Referenced by: '<S96>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_h;/* Mask Parameter: DiscreteDerivative_ICPrevScal_h
                                          * Referenced by: '<S106>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_b;/* Mask Parameter: DiscreteDerivative_ICPrevScal_b
                                          * Referenced by: '<S116>/UD'
                                          */
  real_T reset_P1;                     /* Expression: width
                                        * Referenced by: '<S62>/reset'
                                        */
  real_T reset_P2;                     /* Expression: dtype
                                        * Referenced by: '<S62>/reset'
                                        */
  real_T reset_P3;                     /* Expression: portnum
                                        * Referenced by: '<S62>/reset'
                                        */
  real_T reset_P4;                     /* Expression: stime
                                        * Referenced by: '<S62>/reset'
                                        */
  real_T reset_P5;                     /* Expression: stype
                                        * Referenced by: '<S62>/reset'
                                        */
  real_T reset_P6;                     /* Expression: btype
                                        * Referenced by: '<S62>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S62>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S62>/Discrete-Time Integrator'
                                        */
  real_T Lossesplaceholder_Value;      /* Expression: 0
                                        * Referenced by: '<S54>/Losses (placeholder)'
                                        */
  real_T reset_P1_m;                   /* Expression: width
                                        * Referenced by: '<S72>/reset'
                                        */
  real_T reset_P2_c;                   /* Expression: dtype
                                        * Referenced by: '<S72>/reset'
                                        */
  real_T reset_P3_g;                   /* Expression: portnum
                                        * Referenced by: '<S72>/reset'
                                        */
  real_T reset_P4_f;                   /* Expression: stime
                                        * Referenced by: '<S72>/reset'
                                        */
  real_T reset_P5_b;                   /* Expression: stype
                                        * Referenced by: '<S72>/reset'
                                        */
  real_T reset_P6_o;                   /* Expression: btype
                                        * Referenced by: '<S72>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_l;/* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                          * Referenced by: '<S72>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: 0
                                        * Referenced by: '<S72>/Discrete-Time Integrator'
                                        */
  real_T Lossesplaceholder_Value_a;    /* Expression: 0
                                        * Referenced by: '<S55>/Losses (placeholder)'
                                        */
  real_T reset_P1_c;                   /* Expression: width
                                        * Referenced by: '<S82>/reset'
                                        */
  real_T reset_P2_a;                   /* Expression: dtype
                                        * Referenced by: '<S82>/reset'
                                        */
  real_T reset_P3_d;                   /* Expression: portnum
                                        * Referenced by: '<S82>/reset'
                                        */
  real_T reset_P4_a;                   /* Expression: stime
                                        * Referenced by: '<S82>/reset'
                                        */
  real_T reset_P5_a;                   /* Expression: stype
                                        * Referenced by: '<S82>/reset'
                                        */
  real_T reset_P6_d;                   /* Expression: btype
                                        * Referenced by: '<S82>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_i;/* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                                          * Referenced by: '<S82>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_p;  /* Expression: 0
                                        * Referenced by: '<S82>/Discrete-Time Integrator'
                                        */
  real_T Lossesplaceholder_Value_m;    /* Expression: 0
                                        * Referenced by: '<S56>/Losses (placeholder)'
                                        */
  real_T reset_P1_i;                   /* Expression: width
                                        * Referenced by: '<S92>/reset'
                                        */
  real_T reset_P2_c5;                  /* Expression: dtype
                                        * Referenced by: '<S92>/reset'
                                        */
  real_T reset_P3_m;                   /* Expression: portnum
                                        * Referenced by: '<S92>/reset'
                                        */
  real_T reset_P4_h;                   /* Expression: stime
                                        * Referenced by: '<S92>/reset'
                                        */
  real_T reset_P5_o;                   /* Expression: stype
                                        * Referenced by: '<S92>/reset'
                                        */
  real_T reset_P6_n;                   /* Expression: btype
                                        * Referenced by: '<S92>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;/* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                          * Referenced by: '<S92>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_l;  /* Expression: 0
                                        * Referenced by: '<S92>/Discrete-Time Integrator'
                                        */
  real_T Lossesplaceholder_Value_i;    /* Expression: 0
                                        * Referenced by: '<S57>/Losses (placeholder)'
                                        */
  real_T reset_P1_b;                   /* Expression: width
                                        * Referenced by: '<S102>/reset'
                                        */
  real_T reset_P2_o;                   /* Expression: dtype
                                        * Referenced by: '<S102>/reset'
                                        */
  real_T reset_P3_b;                   /* Expression: portnum
                                        * Referenced by: '<S102>/reset'
                                        */
  real_T reset_P4_i;                   /* Expression: stime
                                        * Referenced by: '<S102>/reset'
                                        */
  real_T reset_P5_p;                   /* Expression: stype
                                        * Referenced by: '<S102>/reset'
                                        */
  real_T reset_P6_g;                   /* Expression: btype
                                        * Referenced by: '<S102>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_e;/* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                          * Referenced by: '<S102>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_me; /* Expression: 0
                                        * Referenced by: '<S102>/Discrete-Time Integrator'
                                        */
  real_T Lossesplaceholder_Value_md;   /* Expression: 0
                                        * Referenced by: '<S58>/Losses (placeholder)'
                                        */
  real_T reset_P1_p;                   /* Expression: width
                                        * Referenced by: '<S112>/reset'
                                        */
  real_T reset_P2_b;                   /* Expression: dtype
                                        * Referenced by: '<S112>/reset'
                                        */
  real_T reset_P3_k;                   /* Expression: portnum
                                        * Referenced by: '<S112>/reset'
                                        */
  real_T reset_P4_m;                   /* Expression: stime
                                        * Referenced by: '<S112>/reset'
                                        */
  real_T reset_P5_g;                   /* Expression: stype
                                        * Referenced by: '<S112>/reset'
                                        */
  real_T reset_P6_np;                  /* Expression: btype
                                        * Referenced by: '<S112>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_a;/* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                          * Referenced by: '<S112>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_e;  /* Expression: 0
                                        * Referenced by: '<S112>/Discrete-Time Integrator'
                                        */
  real_T Lossesplaceholder_Value_h;    /* Expression: 0
                                        * Referenced by: '<S59>/Losses (placeholder)'
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<S52>/Constant12'
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
  real_T x_P1;                         /* Expression: width
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P2;                         /* Expression: dtype
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P3;                         /* Expression: portnum
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P4;                         /* Expression: stime
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P5;                         /* Expression: stype
                                        * Referenced by: '<Root>/x'
                                        */
  real_T x_P6;                         /* Expression: btype
                                        * Referenced by: '<Root>/x'
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
  real_T y_P1;                         /* Expression: width
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P2;                         /* Expression: dtype
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P3;                         /* Expression: portnum
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P4;                         /* Expression: stime
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P5;                         /* Expression: stype
                                        * Referenced by: '<Root>/y'
                                        */
  real_T y_P6;                         /* Expression: btype
                                        * Referenced by: '<Root>/y'
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
  real_T psi_P1;                       /* Expression: width
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P2;                       /* Expression: dtype
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P3;                       /* Expression: portnum
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P4;                       /* Expression: stime
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P5;                       /* Expression: stype
                                        * Referenced by: '<Root>/psi'
                                        */
  real_T psi_P6;                       /* Expression: btype
                                        * Referenced by: '<Root>/psi'
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
  real_T K_p_x_P1;                     /* Expression: width
                                        * Referenced by: '<S24>/K_p_x'
                                        */
  real_T K_p_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S24>/K_p_x'
                                        */
  real_T K_p_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S24>/K_p_x'
                                        */
  real_T K_p_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S24>/K_p_x'
                                        */
  real_T K_p_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S24>/K_p_x'
                                        */
  real_T K_p_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S24>/K_p_x'
                                        */
  real_T K_p_y_P1;                     /* Expression: width
                                        * Referenced by: '<S24>/K_p_y'
                                        */
  real_T K_p_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S24>/K_p_y'
                                        */
  real_T K_p_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S24>/K_p_y'
                                        */
  real_T K_p_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S24>/K_p_y'
                                        */
  real_T K_p_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S24>/K_p_y'
                                        */
  real_T K_p_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S24>/K_p_y'
                                        */
  real_T K_p_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S24>/K_p_psi'
                                        */
  real_T K_p_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S24>/K_p_psi'
                                        */
  real_T K_p_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S24>/K_p_psi'
                                        */
  real_T K_p_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S24>/K_p_psi'
                                        */
  real_T K_p_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S24>/K_p_psi'
                                        */
  real_T K_p_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S24>/K_p_psi'
                                        */
  real_T K_i_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S24>/K_i_psi'
                                        */
  real_T K_i_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S24>/K_i_psi'
                                        */
  real_T K_i_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S24>/K_i_psi'
                                        */
  real_T K_i_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S24>/K_i_psi'
                                        */
  real_T K_i_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S24>/K_i_psi'
                                        */
  real_T K_i_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S24>/K_i_psi'
                                        */
  real_T K_i_x_P1;                     /* Expression: width
                                        * Referenced by: '<S24>/K_i_x'
                                        */
  real_T K_i_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S24>/K_i_x'
                                        */
  real_T K_i_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S24>/K_i_x'
                                        */
  real_T K_i_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S24>/K_i_x'
                                        */
  real_T K_i_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S24>/K_i_x'
                                        */
  real_T K_i_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S24>/K_i_x'
                                        */
  real_T K_i_y_P1;                     /* Expression: width
                                        * Referenced by: '<S24>/K_i_y'
                                        */
  real_T K_i_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S24>/K_i_y'
                                        */
  real_T K_i_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S24>/K_i_y'
                                        */
  real_T K_i_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S24>/K_i_y'
                                        */
  real_T K_i_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S24>/K_i_y'
                                        */
  real_T K_i_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S24>/K_i_y'
                                        */
  real_T K_d_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S24>/K_d_psi'
                                        */
  real_T K_d_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S24>/K_d_psi'
                                        */
  real_T K_d_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S24>/K_d_psi'
                                        */
  real_T K_d_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S24>/K_d_psi'
                                        */
  real_T K_d_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S24>/K_d_psi'
                                        */
  real_T K_d_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S24>/K_d_psi'
                                        */
  real_T K_d_x_P1;                     /* Expression: width
                                        * Referenced by: '<S24>/K_d_x'
                                        */
  real_T K_d_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S24>/K_d_x'
                                        */
  real_T K_d_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S24>/K_d_x'
                                        */
  real_T K_d_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S24>/K_d_x'
                                        */
  real_T K_d_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S24>/K_d_x'
                                        */
  real_T K_d_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S24>/K_d_x'
                                        */
  real_T K_d_y_P1;                     /* Expression: width
                                        * Referenced by: '<S24>/K_d_y'
                                        */
  real_T K_d_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S24>/K_d_y'
                                        */
  real_T K_d_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S24>/K_d_y'
                                        */
  real_T K_d_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S24>/K_d_y'
                                        */
  real_T K_d_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S24>/K_d_y'
                                        */
  real_T K_d_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S24>/K_d_y'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1e10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1e10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: pi
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T reset_P1_n;                   /* Expression: width
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P2_d;                   /* Expression: dtype
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P3_l;                   /* Expression: portnum
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P4_o;                   /* Expression: stime
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P5_ap;                  /* Expression: stype
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T reset_P6_j;                   /* Expression: btype
                                        * Referenced by: '<S5>/reset'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<S26>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S26>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S26>/Constant8'
                                        */
  real_T w_d_x_P1;                     /* Expression: width
                                        * Referenced by: '<S25>/w_d_x'
                                        */
  real_T w_d_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S25>/w_d_x'
                                        */
  real_T w_d_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S25>/w_d_x'
                                        */
  real_T w_d_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S25>/w_d_x'
                                        */
  real_T w_d_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S25>/w_d_x'
                                        */
  real_T w_d_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S25>/w_d_x'
                                        */
  real_T w_d_y_P1;                     /* Expression: width
                                        * Referenced by: '<S25>/w_d_y'
                                        */
  real_T w_d_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S25>/w_d_y'
                                        */
  real_T w_d_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S25>/w_d_y'
                                        */
  real_T w_d_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S25>/w_d_y'
                                        */
  real_T w_d_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S25>/w_d_y'
                                        */
  real_T w_d_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S25>/w_d_y'
                                        */
  real_T w_d_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S25>/w_d_psi'
                                        */
  real_T w_d_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S25>/w_d_psi'
                                        */
  real_T w_d_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S25>/w_d_psi'
                                        */
  real_T w_d_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S25>/w_d_psi'
                                        */
  real_T w_d_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S25>/w_d_psi'
                                        */
  real_T w_d_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S25>/w_d_psi'
                                        */
  real_T zeta_psi_P1;                  /* Expression: width
                                        * Referenced by: '<S25>/zeta_psi'
                                        */
  real_T zeta_psi_P2;                  /* Expression: dtype
                                        * Referenced by: '<S25>/zeta_psi'
                                        */
  real_T zeta_psi_P3;                  /* Expression: portnum
                                        * Referenced by: '<S25>/zeta_psi'
                                        */
  real_T zeta_psi_P4;                  /* Expression: stime
                                        * Referenced by: '<S25>/zeta_psi'
                                        */
  real_T zeta_psi_P5;                  /* Expression: stype
                                        * Referenced by: '<S25>/zeta_psi'
                                        */
  real_T zeta_psi_P6;                  /* Expression: btype
                                        * Referenced by: '<S25>/zeta_psi'
                                        */
  real_T zeta_x_P1;                    /* Expression: width
                                        * Referenced by: '<S25>/zeta_x'
                                        */
  real_T zeta_x_P2;                    /* Expression: dtype
                                        * Referenced by: '<S25>/zeta_x'
                                        */
  real_T zeta_x_P3;                    /* Expression: portnum
                                        * Referenced by: '<S25>/zeta_x'
                                        */
  real_T zeta_x_P4;                    /* Expression: stime
                                        * Referenced by: '<S25>/zeta_x'
                                        */
  real_T zeta_x_P5;                    /* Expression: stype
                                        * Referenced by: '<S25>/zeta_x'
                                        */
  real_T zeta_x_P6;                    /* Expression: btype
                                        * Referenced by: '<S25>/zeta_x'
                                        */
  real_T zeta_y_P1;                    /* Expression: width
                                        * Referenced by: '<S25>/zeta_y'
                                        */
  real_T zeta_y_P2;                    /* Expression: dtype
                                        * Referenced by: '<S25>/zeta_y'
                                        */
  real_T zeta_y_P3;                    /* Expression: portnum
                                        * Referenced by: '<S25>/zeta_y'
                                        */
  real_T zeta_y_P4;                    /* Expression: stime
                                        * Referenced by: '<S25>/zeta_y'
                                        */
  real_T zeta_y_P5;                    /* Expression: stype
                                        * Referenced by: '<S25>/zeta_y'
                                        */
  real_T zeta_y_P6;                    /* Expression: btype
                                        * Referenced by: '<S25>/zeta_y'
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
  real_T Saturation_UpperSat_j;        /* Expression: 1e10
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -1e10
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Gain_Gain_j;                  /* Expression: pi
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 2*pi
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 1e10
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -1e10
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Gain_Gain_g;                  /* Expression: pi
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Constant_Value_p;             /* Expression: 2*pi
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator1_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S17>/Integrator3'
                                        */
  real_T thr_angle_2_P1;               /* Expression: width
                                        * Referenced by: '<S11>/thr_angle_2'
                                        */
  real_T thr_angle_2_P2;               /* Expression: dtype
                                        * Referenced by: '<S11>/thr_angle_2'
                                        */
  real_T thr_angle_2_P3;               /* Expression: portnum
                                        * Referenced by: '<S11>/thr_angle_2'
                                        */
  real_T thr_angle_2_P4;               /* Expression: stime
                                        * Referenced by: '<S11>/thr_angle_2'
                                        */
  real_T thr_angle_2_P5;               /* Expression: stype
                                        * Referenced by: '<S11>/thr_angle_2'
                                        */
  real_T thr_angle_2_P6;               /* Expression: btype
                                        * Referenced by: '<S11>/thr_angle_2'
                                        */
  real_T thr_angle_3_P1;               /* Expression: width
                                        * Referenced by: '<S11>/thr_angle_3'
                                        */
  real_T thr_angle_3_P2;               /* Expression: dtype
                                        * Referenced by: '<S11>/thr_angle_3'
                                        */
  real_T thr_angle_3_P3;               /* Expression: portnum
                                        * Referenced by: '<S11>/thr_angle_3'
                                        */
  real_T thr_angle_3_P4;               /* Expression: stime
                                        * Referenced by: '<S11>/thr_angle_3'
                                        */
  real_T thr_angle_3_P5;               /* Expression: stype
                                        * Referenced by: '<S11>/thr_angle_3'
                                        */
  real_T thr_angle_3_P6;               /* Expression: btype
                                        * Referenced by: '<S11>/thr_angle_3'
                                        */
  real_T thr_angle_4_P1;               /* Expression: width
                                        * Referenced by: '<S11>/thr_angle_4'
                                        */
  real_T thr_angle_4_P2;               /* Expression: dtype
                                        * Referenced by: '<S11>/thr_angle_4'
                                        */
  real_T thr_angle_4_P3;               /* Expression: portnum
                                        * Referenced by: '<S11>/thr_angle_4'
                                        */
  real_T thr_angle_4_P4;               /* Expression: stime
                                        * Referenced by: '<S11>/thr_angle_4'
                                        */
  real_T thr_angle_4_P5;               /* Expression: stype
                                        * Referenced by: '<S11>/thr_angle_4'
                                        */
  real_T thr_angle_4_P6;               /* Expression: btype
                                        * Referenced by: '<S11>/thr_angle_4'
                                        */
  real_T thr_angle_5_P1;               /* Expression: width
                                        * Referenced by: '<S11>/thr_angle_5'
                                        */
  real_T thr_angle_5_P2;               /* Expression: dtype
                                        * Referenced by: '<S11>/thr_angle_5'
                                        */
  real_T thr_angle_5_P3;               /* Expression: portnum
                                        * Referenced by: '<S11>/thr_angle_5'
                                        */
  real_T thr_angle_5_P4;               /* Expression: stime
                                        * Referenced by: '<S11>/thr_angle_5'
                                        */
  real_T thr_angle_5_P5;               /* Expression: stype
                                        * Referenced by: '<S11>/thr_angle_5'
                                        */
  real_T thr_angle_5_P6;               /* Expression: btype
                                        * Referenced by: '<S11>/thr_angle_5'
                                        */
  real_T thr_angle_6_P1;               /* Expression: width
                                        * Referenced by: '<S11>/thr_angle_6'
                                        */
  real_T thr_angle_6_P2;               /* Expression: dtype
                                        * Referenced by: '<S11>/thr_angle_6'
                                        */
  real_T thr_angle_6_P3;               /* Expression: portnum
                                        * Referenced by: '<S11>/thr_angle_6'
                                        */
  real_T thr_angle_6_P4;               /* Expression: stime
                                        * Referenced by: '<S11>/thr_angle_6'
                                        */
  real_T thr_angle_6_P5;               /* Expression: stype
                                        * Referenced by: '<S11>/thr_angle_6'
                                        */
  real_T thr_angle_6_P6;               /* Expression: btype
                                        * Referenced by: '<S11>/thr_angle_6'
                                        */
  real_T thr_angle_1_P1;               /* Expression: width
                                        * Referenced by: '<S11>/thr_angle_1'
                                        */
  real_T thr_angle_1_P2;               /* Expression: dtype
                                        * Referenced by: '<S11>/thr_angle_1'
                                        */
  real_T thr_angle_1_P3;               /* Expression: portnum
                                        * Referenced by: '<S11>/thr_angle_1'
                                        */
  real_T thr_angle_1_P4;               /* Expression: stime
                                        * Referenced by: '<S11>/thr_angle_1'
                                        */
  real_T thr_angle_1_P5;               /* Expression: stype
                                        * Referenced by: '<S11>/thr_angle_1'
                                        */
  real_T thr_angle_1_P6;               /* Expression: btype
                                        * Referenced by: '<S11>/thr_angle_1'
                                        */
  real_T Gain_Gain_gz;                 /* Expression: 180/pi
                                        * Referenced by: '<S48>/Gain'
                                        */
  real_T XpositionThruster_Value[6];   /* Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
                                        * Referenced by: '<S9>/X-position Thruster'
                                        */
  real_T YpositionThruster_Value[6];   /* Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
                                        * Referenced by: '<S9>/Y-position Thruster'
                                        */
  real_T constantangle_Value[6];       /* Expression: [Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)]
                                        * Referenced by: '<S9>/constant angle'
                                        */
  real_T ChoosingFixedAzimuthangle_Thres;/* Expression: 1
                                          * Referenced by: '<S9>/Choosing Fixed // Azimuth angle'
                                          */
  real_T reset_P1_nr;                  /* Expression: width
                                        * Referenced by: '<S9>/reset'
                                        */
  real_T reset_P2_h;                   /* Expression: dtype
                                        * Referenced by: '<S9>/reset'
                                        */
  real_T reset_P3_gp;                  /* Expression: portnum
                                        * Referenced by: '<S9>/reset'
                                        */
  real_T reset_P4_g;                   /* Expression: stime
                                        * Referenced by: '<S9>/reset'
                                        */
  real_T reset_P5_n;                   /* Expression: stype
                                        * Referenced by: '<S9>/reset'
                                        */
  real_T reset_P6_i;                   /* Expression: btype
                                        * Referenced by: '<S9>/reset'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S53>/Saturation 1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S53>/Saturation 1'
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
  real_T Saturation2_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S53>/Saturation 2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S53>/Saturation 2'
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
  real_T Saturation3_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S53>/Saturation 3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S53>/Saturation 3'
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
  real_T Saturation4_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S53>/Saturation 4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S53>/Saturation 4'
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
                                        * Referenced by: '<S53>/Saturation 5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S53>/Saturation 5'
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
  real_T Saturation6_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S53>/Saturation 6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S53>/Saturation 6'
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
  real_T x_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S43>/x_hat'
                                        */
  real_T x_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S43>/x_hat'
                                        */
  real_T x_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S43>/x_hat'
                                        */
  real_T x_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S43>/x_hat'
                                        */
  real_T x_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S43>/x_hat'
                                        */
  real_T x_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S43>/x_hat'
                                        */
  real_T y_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S43>/y_hat'
                                        */
  real_T y_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S43>/y_hat'
                                        */
  real_T y_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S43>/y_hat'
                                        */
  real_T y_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S43>/y_hat'
                                        */
  real_T y_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S43>/y_hat'
                                        */
  real_T y_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S43>/y_hat'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1e10
                                        * Referenced by: '<S40>/Saturation'
                                        */
  real_T Saturation_LowerSat_cz;       /* Expression: -1e10
                                        * Referenced by: '<S40>/Saturation'
                                        */
  real_T Gain_Gain_d;                  /* Expression: pi
                                        * Referenced by: '<S40>/Gain'
                                        */
  real_T Constant_Value_p4;            /* Expression: 2*pi
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T psi_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S43>/psi_hat'
                                        */
  real_T psi_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S43>/psi_hat'
                                        */
  real_T psi_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S43>/psi_hat'
                                        */
  real_T psi_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S43>/psi_hat'
                                        */
  real_T psi_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S43>/psi_hat'
                                        */
  real_T psi_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S43>/psi_hat'
                                        */
  real_T u_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S45>/u_hat'
                                        */
  real_T u_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S45>/u_hat'
                                        */
  real_T u_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S45>/u_hat'
                                        */
  real_T u_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S45>/u_hat'
                                        */
  real_T u_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S45>/u_hat'
                                        */
  real_T u_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S45>/u_hat'
                                        */
  real_T v_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S45>/v_hat'
                                        */
  real_T v_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S45>/v_hat'
                                        */
  real_T v_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S45>/v_hat'
                                        */
  real_T v_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S45>/v_hat'
                                        */
  real_T v_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S45>/v_hat'
                                        */
  real_T v_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S45>/v_hat'
                                        */
  real_T r_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S45>/r_hat'
                                        */
  real_T r_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S45>/r_hat'
                                        */
  real_T r_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S45>/r_hat'
                                        */
  real_T r_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S45>/r_hat'
                                        */
  real_T r_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S45>/r_hat'
                                        */
  real_T r_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S45>/r_hat'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 1e10
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: -1e10
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T Gain_Gain_h;                  /* Expression: pi
                                        * Referenced by: '<S41>/Gain'
                                        */
  real_T Constant_Value_i;             /* Expression: 2*pi
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Integrator2_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  real_T M1_Gain[9];                   /* Expression: [0.008021948049864 0 0;0 0.010098125265799 1.104781662647098e-04;0 3.303823257820844e-05 0.020839338676560]
                                        * Referenced by: '<S6>/M^-1'
                                        */
  real_T u_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S44>/u_dot_hat'
                                        */
  real_T u_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S44>/u_dot_hat'
                                        */
  real_T u_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S44>/u_dot_hat'
                                        */
  real_T u_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S44>/u_dot_hat'
                                        */
  real_T u_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S44>/u_dot_hat'
                                        */
  real_T u_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S44>/u_dot_hat'
                                        */
  real_T v_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S44>/v_dot_hat'
                                        */
  real_T v_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S44>/v_dot_hat'
                                        */
  real_T v_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S44>/v_dot_hat'
                                        */
  real_T v_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S44>/v_dot_hat'
                                        */
  real_T v_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S44>/v_dot_hat'
                                        */
  real_T v_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S44>/v_dot_hat'
                                        */
  real_T r_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S44>/r_dot_hat'
                                        */
  real_T r_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S44>/r_dot_hat'
                                        */
  real_T r_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S44>/r_dot_hat'
                                        */
  real_T r_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S44>/r_dot_hat'
                                        */
  real_T r_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S44>/r_dot_hat'
                                        */
  real_T r_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S44>/r_dot_hat'
                                        */
  real_T b_x_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S42>/b_x_hat'
                                        */
  real_T b_x_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S42>/b_x_hat'
                                        */
  real_T b_x_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S42>/b_x_hat'
                                        */
  real_T b_x_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S42>/b_x_hat'
                                        */
  real_T b_x_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S42>/b_x_hat'
                                        */
  real_T b_x_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S42>/b_x_hat'
                                        */
  real_T b_y_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S42>/b_y_hat'
                                        */
  real_T b_y_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S42>/b_y_hat'
                                        */
  real_T b_y_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S42>/b_y_hat'
                                        */
  real_T b_y_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S42>/b_y_hat'
                                        */
  real_T b_y_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S42>/b_y_hat'
                                        */
  real_T b_y_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S42>/b_y_hat'
                                        */
  real_T b_psi_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S42>/b_psi_hat'
                                        */
  real_T b_psi_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S42>/b_psi_hat'
                                        */
  real_T b_psi_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S42>/b_psi_hat'
                                        */
  real_T b_psi_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S42>/b_psi_hat'
                                        */
  real_T b_psi_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S42>/b_psi_hat'
                                        */
  real_T b_psi_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S42>/b_psi_hat'
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
  real_T Integrator2_IC_h;             /* Expression: 0
                                        * Referenced by: '<S17>/Integrator2'
                                        */
  real_T Constant_Value_k;             /* Expression: 50
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 50
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 50
                                        * Referenced by: '<S26>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S26>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S26>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S26>/Constant5'
                                        */
  real_T Constant_Value_i3[2];         /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T Constant1_Value_h[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S54>/Constant1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S54>/Delay'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0
                                        * Referenced by: '<S63>/Delay'
                                        */
  real_T Constant1_Value_e[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S63>/Constant1'
                                        */
  real_T Constant2_Value_c[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S63>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S63>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S66>/TSamp'
                                        */
  real_T AccelerationLimit_RisingLim;  /* Computed Parameter: AccelerationLimit_RisingLim
                                        * Referenced by: '<S63>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_FallingLim; /* Computed Parameter: AccelerationLimit_FallingLim
                                        * Referenced by: '<S63>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_IC;         /* Expression: 0
                                        * Referenced by: '<S63>/Acceleration Limit'
                                        */
  real_T Memory_X0;                    /* Expression: 1
                                        * Referenced by: '<S63>/Memory'
                                        */
  real_T reset_P1_e;                   /* Expression: width
                                        * Referenced by: '<S65>/reset'
                                        */
  real_T reset_P2_ho;                  /* Expression: dtype
                                        * Referenced by: '<S65>/reset'
                                        */
  real_T reset_P3_e;                   /* Expression: portnum
                                        * Referenced by: '<S65>/reset'
                                        */
  real_T reset_P4_g2;                  /* Expression: stime
                                        * Referenced by: '<S65>/reset'
                                        */
  real_T reset_P5_f;                   /* Expression: stype
                                        * Referenced by: '<S65>/reset'
                                        */
  real_T reset_P6_a;                   /* Expression: btype
                                        * Referenced by: '<S65>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_f;/* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                                          * Referenced by: '<S65>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S65>/Discrete-Time Integrator'
                                        */
  real_T NaN_Value;                    /* Expression: 0
                                        * Referenced by: '<S63>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_o;/* Expression: 0
                                          * Referenced by: '<S54>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_b[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T Constant1_Value_l[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S55>/Constant1'
                                        */
  real_T Delay_InitialCondition_fk;    /* Expression: 0
                                        * Referenced by: '<S55>/Delay'
                                        */
  real_T Delay_InitialCondition_k;     /* Expression: 0
                                        * Referenced by: '<S73>/Delay'
                                        */
  real_T Constant1_Value_f[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S73>/Constant1'
                                        */
  real_T Constant2_Value_i[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S73>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_p;/* Expression: 0
                                          * Referenced by: '<S73>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_o;                 /* Computed Parameter: TSamp_WtEt_o
                                        * Referenced by: '<S76>/TSamp'
                                        */
  real_T AccelerationLimit_RisingLim_n;/* Computed Parameter: AccelerationLimit_RisingLim_n
                                        * Referenced by: '<S73>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_FallingLim_j;/* Computed Parameter: AccelerationLimit_FallingLim_j
                                         * Referenced by: '<S73>/Acceleration Limit'
                                         */
  real_T AccelerationLimit_IC_b;       /* Expression: 0
                                        * Referenced by: '<S73>/Acceleration Limit'
                                        */
  real_T Memory_X0_j;                  /* Expression: 1
                                        * Referenced by: '<S73>/Memory'
                                        */
  real_T reset_P1_a;                   /* Expression: width
                                        * Referenced by: '<S75>/reset'
                                        */
  real_T reset_P2_i;                   /* Expression: dtype
                                        * Referenced by: '<S75>/reset'
                                        */
  real_T reset_P3_j;                   /* Expression: portnum
                                        * Referenced by: '<S75>/reset'
                                        */
  real_T reset_P4_oq;                  /* Expression: stime
                                        * Referenced by: '<S75>/reset'
                                        */
  real_T reset_P5_bq;                  /* Expression: stype
                                        * Referenced by: '<S75>/reset'
                                        */
  real_T reset_P6_e;                   /* Expression: btype
                                        * Referenced by: '<S75>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainv_fz;/* Computed Parameter: DiscreteTimeIntegrator_gainv_fz
                                          * Referenced by: '<S75>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_a;  /* Expression: 0
                                        * Referenced by: '<S75>/Discrete-Time Integrator'
                                        */
  real_T NaN_Value_o;                  /* Expression: 0
                                        * Referenced by: '<S73>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_e;/* Expression: 0
                                          * Referenced by: '<S55>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_n[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T Constant1_Value_g[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S56>/Constant1'
                                        */
  real_T Delay_InitialCondition_o;     /* Expression: 0
                                        * Referenced by: '<S56>/Delay'
                                        */
  real_T Delay_InitialCondition_i;     /* Expression: 0
                                        * Referenced by: '<S83>/Delay'
                                        */
  real_T Constant1_Value_k[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S83>/Constant1'
                                        */
  real_T Constant2_Value_b[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S83>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_n;/* Expression: 0
                                          * Referenced by: '<S83>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_m;                 /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S86>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim;/* Computed Parameter: Accelerationlimiter_RisingLim
                                        * Referenced by: '<S83>/Acceleration limiter'
                                        */
  real_T Accelerationlimiter_FallingLim;/* Computed Parameter: Accelerationlimiter_FallingLim
                                         * Referenced by: '<S83>/Acceleration limiter'
                                         */
  real_T Accelerationlimiter_IC;       /* Expression: 0
                                        * Referenced by: '<S83>/Acceleration limiter'
                                        */
  real_T Memory_X0_b;                  /* Expression: 1
                                        * Referenced by: '<S83>/Memory'
                                        */
  real_T reset_P1_o;                   /* Expression: width
                                        * Referenced by: '<S85>/reset'
                                        */
  real_T reset_P2_dw;                  /* Expression: dtype
                                        * Referenced by: '<S85>/reset'
                                        */
  real_T reset_P3_h;                   /* Expression: portnum
                                        * Referenced by: '<S85>/reset'
                                        */
  real_T reset_P4_j;                   /* Expression: stime
                                        * Referenced by: '<S85>/reset'
                                        */
  real_T reset_P5_fn;                  /* Expression: stype
                                        * Referenced by: '<S85>/reset'
                                        */
  real_T reset_P6_m;                   /* Expression: btype
                                        * Referenced by: '<S85>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_m;/* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                          * Referenced by: '<S85>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_o;  /* Expression: 0
                                        * Referenced by: '<S85>/Discrete-Time Integrator'
                                        */
  real_T NaN_Value_g;                  /* Expression: 0
                                        * Referenced by: '<S83>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_m;/* Expression: 0
                                          * Referenced by: '<S56>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_a[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T Constant1_Value_fh[2];        /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S57>/Constant1'
                                        */
  real_T Delay_InitialCondition_n;     /* Expression: 0
                                        * Referenced by: '<S57>/Delay'
                                        */
  real_T Delay_InitialCondition_n0;    /* Expression: 0
                                        * Referenced by: '<S93>/Delay'
                                        */
  real_T Constant1_Value_m[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S93>/Constant1'
                                        */
  real_T Constant2_Value_m[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S93>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_l;/* Expression: 0
                                          * Referenced by: '<S93>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_mu;                /* Computed Parameter: TSamp_WtEt_mu
                                        * Referenced by: '<S96>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_c;/* Computed Parameter: Accelerationlimiter_RisingLim_c
                                          * Referenced by: '<S93>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_o;/* Computed Parameter: Accelerationlimiter_FallingLi_o
                                          * Referenced by: '<S93>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_j;     /* Expression: 0
                                        * Referenced by: '<S93>/Acceleration limiter'
                                        */
  real_T Memory_X0_h;                  /* Expression: 1
                                        * Referenced by: '<S93>/Memory'
                                        */
  real_T reset_P1_mi;                  /* Expression: width
                                        * Referenced by: '<S95>/reset'
                                        */
  real_T reset_P2_f;                   /* Expression: dtype
                                        * Referenced by: '<S95>/reset'
                                        */
  real_T reset_P3_f;                   /* Expression: portnum
                                        * Referenced by: '<S95>/reset'
                                        */
  real_T reset_P4_oi;                  /* Expression: stime
                                        * Referenced by: '<S95>/reset'
                                        */
  real_T reset_P5_h;                   /* Expression: stype
                                        * Referenced by: '<S95>/reset'
                                        */
  real_T reset_P6_e3;                  /* Expression: btype
                                        * Referenced by: '<S95>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainv_ay;/* Computed Parameter: DiscreteTimeIntegrator_gainv_ay
                                          * Referenced by: '<S95>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_k;  /* Expression: 0
                                        * Referenced by: '<S95>/Discrete-Time Integrator'
                                        */
  real_T NaN_Value_om;                 /* Expression: 0
                                        * Referenced by: '<S93>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialS_n4;/* Expression: 0
                                          * Referenced by: '<S57>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_d[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T Constant1_Value_p[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S58>/Constant1'
                                        */
  real_T Delay_InitialCondition_a;     /* Expression: 0
                                        * Referenced by: '<S58>/Delay'
                                        */
  real_T Delay_InitialCondition_fn;    /* Expression: 0
                                        * Referenced by: '<S103>/Delay'
                                        */
  real_T Constant1_Value_n[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S103>/Constant1'
                                        */
  real_T Constant2_Value_g[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S103>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_ev;/* Expression: 0
                                          * Referenced by: '<S103>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_b;                 /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S106>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_h;/* Computed Parameter: Accelerationlimiter_RisingLim_h
                                          * Referenced by: '<S103>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_l;/* Computed Parameter: Accelerationlimiter_FallingLi_l
                                          * Referenced by: '<S103>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_h;     /* Expression: 0
                                        * Referenced by: '<S103>/Acceleration limiter'
                                        */
  real_T Memory_X0_p;                  /* Expression: 1
                                        * Referenced by: '<S103>/Memory'
                                        */
  real_T reset_P1_g;                   /* Expression: width
                                        * Referenced by: '<S105>/reset'
                                        */
  real_T reset_P2_f4;                  /* Expression: dtype
                                        * Referenced by: '<S105>/reset'
                                        */
  real_T reset_P3_p;                   /* Expression: portnum
                                        * Referenced by: '<S105>/reset'
                                        */
  real_T reset_P4_n;                   /* Expression: stime
                                        * Referenced by: '<S105>/reset'
                                        */
  real_T reset_P5_j;                   /* Expression: stype
                                        * Referenced by: '<S105>/reset'
                                        */
  real_T reset_P6_l;                   /* Expression: btype
                                        * Referenced by: '<S105>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                          * Referenced by: '<S105>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_mk; /* Expression: 0
                                        * Referenced by: '<S105>/Discrete-Time Integrator'
                                        */
  real_T NaN_Value_od;                 /* Expression: 0
                                        * Referenced by: '<S103>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialS_oi;/* Expression: 0
                                          * Referenced by: '<S58>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_m[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T Constant1_Value_ly[2];        /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S59>/Constant1'
                                        */
  real_T Delay_InitialCondition_e;     /* Expression: 0
                                        * Referenced by: '<S59>/Delay'
                                        */
  real_T Delay_InitialCondition_g;     /* Expression: 0
                                        * Referenced by: '<S113>/Delay'
                                        */
  real_T Constant1_Value_li[3];        /* Expression: hd.num{1,1}
                                        * Referenced by: '<S113>/Constant1'
                                        */
  real_T Constant2_Value_d[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S113>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_a;/* Expression: 0
                                          * Referenced by: '<S113>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_j;                 /* Computed Parameter: TSamp_WtEt_j
                                        * Referenced by: '<S116>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_k;/* Computed Parameter: Accelerationlimiter_RisingLim_k
                                          * Referenced by: '<S113>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_b;/* Computed Parameter: Accelerationlimiter_FallingLi_b
                                          * Referenced by: '<S113>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_m;     /* Expression: 0
                                        * Referenced by: '<S113>/Acceleration limiter'
                                        */
  real_T Memory_X0_g;                  /* Expression: 1
                                        * Referenced by: '<S113>/Memory'
                                        */
  real_T reset_P1_mz;                  /* Expression: width
                                        * Referenced by: '<S115>/reset'
                                        */
  real_T reset_P2_da;                  /* Expression: dtype
                                        * Referenced by: '<S115>/reset'
                                        */
  real_T reset_P3_a;                   /* Expression: portnum
                                        * Referenced by: '<S115>/reset'
                                        */
  real_T reset_P4_if;                  /* Expression: stime
                                        * Referenced by: '<S115>/reset'
                                        */
  real_T reset_P5_d;                   /* Expression: stype
                                        * Referenced by: '<S115>/reset'
                                        */
  real_T reset_P6_op;                  /* Expression: btype
                                        * Referenced by: '<S115>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainv_ll;/* Computed Parameter: DiscreteTimeIntegrator_gainv_ll
                                          * Referenced by: '<S115>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_b;  /* Expression: 0
                                        * Referenced by: '<S115>/Discrete-Time Integrator'
                                        */
  real_T NaN_Value_c;                  /* Expression: 0
                                        * Referenced by: '<S113>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_f;/* Expression: 0
                                          * Referenced by: '<S59>/Discrete Transfer Fcn'
                                          */
  real_T tau_N_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/tau_N'
                                        */
  real_T tau_N_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/tau_N'
                                        */
  real_T tau_N_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/tau_N'
                                        */
  real_T tau_N_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/tau_N'
                                        */
  real_T tau_N_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/tau_N'
                                        */
  real_T tau_N_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/tau_N'
                                        */
  real_T tau_X_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/tau_X'
                                        */
  real_T tau_X_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/tau_X'
                                        */
  real_T tau_X_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/tau_X'
                                        */
  real_T tau_X_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/tau_X'
                                        */
  real_T tau_X_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/tau_X'
                                        */
  real_T tau_X_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/tau_X'
                                        */
  real_T tau_Y_P1;                     /* Expression: width
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  real_T tau_Y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  real_T tau_Y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  real_T tau_Y_P4;                     /* Expression: stime
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  real_T tau_Y_P5;                     /* Expression: stype
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  real_T tau_Y_P6;                     /* Expression: btype
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  real_T psi_tilde_P1;                 /* Expression: width
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  real_T psi_tilde_P2;                 /* Expression: dtype
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  real_T psi_tilde_P3;                 /* Expression: portnum
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  real_T psi_tilde_P4;                 /* Expression: stime
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  real_T psi_tilde_P5;                 /* Expression: stype
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  real_T psi_tilde_P6;                 /* Expression: btype
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  real_T x_tilde_P1;                   /* Expression: width
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  real_T x_tilde_P2;                   /* Expression: dtype
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  real_T x_tilde_P3;                   /* Expression: portnum
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  real_T x_tilde_P4;                   /* Expression: stime
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  real_T x_tilde_P5;                   /* Expression: stype
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  real_T x_tilde_P6;                   /* Expression: btype
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  real_T y_tidle_P1;                   /* Expression: width
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  real_T y_tidle_P2;                   /* Expression: dtype
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  real_T y_tidle_P3;                   /* Expression: portnum
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  real_T y_tidle_P4;                   /* Expression: stime
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  real_T y_tidle_P5;                   /* Expression: stype
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  real_T y_tidle_P6;                   /* Expression: btype
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  real_T r_tilde_P1;                   /* Expression: width
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  real_T r_tilde_P2;                   /* Expression: dtype
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  real_T r_tilde_P3;                   /* Expression: portnum
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  real_T r_tilde_P4;                   /* Expression: stime
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  real_T r_tilde_P5;                   /* Expression: stype
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  real_T r_tilde_P6;                   /* Expression: btype
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  real_T u_tilde_P1;                   /* Expression: width
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  real_T u_tilde_P2;                   /* Expression: dtype
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  real_T u_tilde_P3;                   /* Expression: portnum
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  real_T u_tilde_P4;                   /* Expression: stime
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  real_T u_tilde_P5;                   /* Expression: stype
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  real_T u_tilde_P6;                   /* Expression: btype
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  real_T v_tilde_P1;                   /* Expression: width
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  real_T v_tilde_P2;                   /* Expression: dtype
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  real_T v_tilde_P3;                   /* Expression: portnum
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  real_T v_tilde_P4;                   /* Expression: stime
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  real_T v_tilde_P5;                   /* Expression: stype
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  real_T v_tilde_P6;                   /* Expression: btype
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  real_T x_d_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/x_d'
                                        */
  real_T x_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/x_d'
                                        */
  real_T x_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/x_d'
                                        */
  real_T x_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/x_d'
                                        */
  real_T x_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/x_d'
                                        */
  real_T x_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/x_d'
                                        */
  real_T y_d_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/y_d'
                                        */
  real_T y_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/y_d'
                                        */
  real_T y_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/y_d'
                                        */
  real_T y_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/y_d'
                                        */
  real_T y_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/y_d'
                                        */
  real_T y_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/y_d'
                                        */
  real_T psi_d_P1;                     /* Expression: width
                                        * Referenced by: '<S4>/psi_d'
                                        */
  real_T psi_d_P2;                     /* Expression: dtype
                                        * Referenced by: '<S4>/psi_d'
                                        */
  real_T psi_d_P3;                     /* Expression: portnum
                                        * Referenced by: '<S4>/psi_d'
                                        */
  real_T psi_d_P4;                     /* Expression: stime
                                        * Referenced by: '<S4>/psi_d'
                                        */
  real_T psi_d_P5;                     /* Expression: stype
                                        * Referenced by: '<S4>/psi_d'
                                        */
  real_T psi_d_P6;                     /* Expression: btype
                                        * Referenced by: '<S4>/psi_d'
                                        */
  real_T r_d_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/r_d'
                                        */
  real_T r_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/r_d'
                                        */
  real_T r_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/r_d'
                                        */
  real_T r_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/r_d'
                                        */
  real_T r_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/r_d'
                                        */
  real_T r_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/r_d'
                                        */
  real_T u_d_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/u_d'
                                        */
  real_T u_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/u_d'
                                        */
  real_T u_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/u_d'
                                        */
  real_T u_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/u_d'
                                        */
  real_T u_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/u_d'
                                        */
  real_T u_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/u_d'
                                        */
  real_T v_d_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/v_d'
                                        */
  real_T v_d_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/v_d'
                                        */
  real_T v_d_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/v_d'
                                        */
  real_T v_d_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/v_d'
                                        */
  real_T v_d_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/v_d'
                                        */
  real_T v_d_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/v_d'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S54>/Delay'
                                        */
  uint32_T Delay_DelayLength_m;        /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S63>/Delay'
                                        */
  uint32_T Delay_DelayLength_l;        /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S55>/Delay'
                                        */
  uint32_T Delay_DelayLength_b;        /* Computed Parameter: Delay_DelayLength_b
                                        * Referenced by: '<S73>/Delay'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Delay_DelayLength_o;        /* Computed Parameter: Delay_DelayLength_o
                                        * Referenced by: '<S83>/Delay'
                                        */
  uint32_T Delay_DelayLength_ch;       /* Computed Parameter: Delay_DelayLength_ch
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Delay_DelayLength_cq;       /* Computed Parameter: Delay_DelayLength_cq
                                        * Referenced by: '<S93>/Delay'
                                        */
  uint32_T Delay_DelayLength_d;        /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S58>/Delay'
                                        */
  uint32_T Delay_DelayLength_e;        /* Computed Parameter: Delay_DelayLength_e
                                        * Referenced by: '<S103>/Delay'
                                        */
  uint32_T Delay_DelayLength_k;        /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S59>/Delay'
                                        */
  uint32_T Delay_DelayLength_i;        /* Computed Parameter: Delay_DelayLength_i
                                        * Referenced by: '<S113>/Delay'
                                        */
  P_CoreSubsys_ctrl_DP_basic_T CoreSubsys;/* '<S46>/CoreSubsys' */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_DP_basic_T {
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
    real_T odeY[21];
    real_T odeF[4][21];
    ODE4_IntgData intgData;
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
extern P_ctrl_DP_basic_T ctrl_DP_basic_P;

/* Block signals (auto storage) */
extern B_ctrl_DP_basic_T ctrl_DP_basic_B;

/* Continuous states (auto storage) */
extern X_ctrl_DP_basic_T ctrl_DP_basic_X;

/* Block states (auto storage) */
extern DW_ctrl_DP_basic_T ctrl_DP_basic_DW;

/* Model entry point functions */
extern void ctrl_DP_basic_initialize(void);
extern void ctrl_DP_basic_output(void);
extern void ctrl_DP_basic_update(void);
extern void ctrl_DP_basic_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_DP_basic_rtModel *ctrl_DP_basic(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_DP_basic_T *const ctrl_DP_basic_M;

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
 * '<Root>' : 'ctrl_DP_basic'
 * '<S1>'   : 'ctrl_DP_basic/Control'
 * '<S2>'   : 'ctrl_DP_basic/Control output'
 * '<S3>'   : 'ctrl_DP_basic/Guidance'
 * '<S4>'   : 'ctrl_DP_basic/Guidance output'
 * '<S5>'   : 'ctrl_DP_basic/Input'
 * '<S6>'   : 'ctrl_DP_basic/Nonlinear Passisve Observer'
 * '<S7>'   : 'ctrl_DP_basic/Observer output '
 * '<S8>'   : 'ctrl_DP_basic/Parameters From initfile distributed '
 * '<S9>'   : 'ctrl_DP_basic/Thrust allocation1'
 * '<S10>'  : 'ctrl_DP_basic/Thruster control '
 * '<S11>'  : 'ctrl_DP_basic/Thruster measurment'
 * '<S12>'  : 'ctrl_DP_basic/Control/DP Controller'
 * '<S13>'  : 'ctrl_DP_basic/Control/DP Controller/Transposed rotation  matrix in yaw1'
 * '<S14>'  : 'ctrl_DP_basic/Control/DP Controller/Transposed rotation  matrix in yaw2'
 * '<S15>'  : 'ctrl_DP_basic/Control/DP Controller/[-inf inf] to [-pi pi]'
 * '<S16>'  : 'ctrl_DP_basic/Control/DP Controller/[-inf inf] to [-pi pi]1'
 * '<S17>'  : 'ctrl_DP_basic/Guidance/Reference model'
 * '<S18>'  : 'ctrl_DP_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1'
 * '<S19>'  : 'ctrl_DP_basic/Guidance/Reference model/w_d*w_d'
 * '<S20>'  : 'ctrl_DP_basic/Guidance/Reference model/w_d*w_d1'
 * '<S21>'  : 'ctrl_DP_basic/Guidance/Reference model/w_d^-2'
 * '<S22>'  : 'ctrl_DP_basic/Guidance/Reference model/w_d^3'
 * '<S23>'  : 'ctrl_DP_basic/Guidance output/Transposed rotation  matrix in yaw2'
 * '<S24>'  : 'ctrl_DP_basic/Input/Control Gains'
 * '<S25>'  : 'ctrl_DP_basic/Input/Guidance gains'
 * '<S26>'  : 'ctrl_DP_basic/Input/Observer Gains'
 * '<S27>'  : 'ctrl_DP_basic/Input/Control Gains/MATLAB Function'
 * '<S28>'  : 'ctrl_DP_basic/Input/Control Gains/MATLAB Function1'
 * '<S29>'  : 'ctrl_DP_basic/Input/Control Gains/MATLAB Function2'
 * '<S30>'  : 'ctrl_DP_basic/Input/Guidance gains/diag'
 * '<S31>'  : 'ctrl_DP_basic/Input/Guidance gains/diag1'
 * '<S32>'  : 'ctrl_DP_basic/Input/Observer Gains/MATLAB Function'
 * '<S33>'  : 'ctrl_DP_basic/Input/Observer Gains/MATLAB Function1'
 * '<S34>'  : 'ctrl_DP_basic/Input/Observer Gains/MATLAB Function2'
 * '<S35>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/C(nu)*nu'
 * '<S36>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/D(nu)*nu'
 * '<S37>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/Rotation matrix in yaw 1'
 * '<S38>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/Transpose Rotation Matrix'
 * '<S39>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/Transpose Rotation matrix'
 * '<S40>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]'
 * '<S41>'  : 'ctrl_DP_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1'
 * '<S42>'  : 'ctrl_DP_basic/Observer output /b_hat output'
 * '<S43>'  : 'ctrl_DP_basic/Observer output /eta_hat output'
 * '<S44>'  : 'ctrl_DP_basic/Observer output /nu_dot_hat output'
 * '<S45>'  : 'ctrl_DP_basic/Observer output /nu_hat output'
 * '<S46>'  : 'ctrl_DP_basic/Thrust allocation1/For Each Subsystem'
 * '<S47>'  : 'ctrl_DP_basic/Thrust allocation1/MATLAB Function'
 * '<S48>'  : 'ctrl_DP_basic/Thrust allocation1/Radians to Degrees'
 * '<S49>'  : 'ctrl_DP_basic/Thrust allocation1/For Each Subsystem/Degrees to Radians'
 * '<S50>'  : 'ctrl_DP_basic/Thrust allocation1/For Each Subsystem/MATLAB Function'
 * '<S51>'  : 'ctrl_DP_basic/Thrust allocation1/For Each Subsystem/MATLAB Function1'
 * '<S52>'  : 'ctrl_DP_basic/Thruster control /Subsystem'
 * '<S53>'  : 'ctrl_DP_basic/Thruster control /Subsystem1'
 * '<S54>'  : 'ctrl_DP_basic/Thruster control /Thruster 1'
 * '<S55>'  : 'ctrl_DP_basic/Thruster control /Thruster 2'
 * '<S56>'  : 'ctrl_DP_basic/Thruster control /Thruster 3'
 * '<S57>'  : 'ctrl_DP_basic/Thruster control /Thruster 4'
 * '<S58>'  : 'ctrl_DP_basic/Thruster control /Thruster 5'
 * '<S59>'  : 'ctrl_DP_basic/Thruster control /Thruster 6'
 * '<S60>'  : 'ctrl_DP_basic/Thruster control /Subsystem/MATLAB Function'
 * '<S61>'  : 'ctrl_DP_basic/Thruster control /Thruster 1/Propeller Hydrodynamics'
 * '<S62>'  : 'ctrl_DP_basic/Thruster control /Thruster 1/Shaft dynamics'
 * '<S63>'  : 'ctrl_DP_basic/Thruster control /Thruster 1/Thruster control'
 * '<S64>'  : 'ctrl_DP_basic/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S65>'  : 'ctrl_DP_basic/Thruster control /Thruster 1/Thruster control/Core controller'
 * '<S66>'  : 'ctrl_DP_basic/Thruster control /Thruster 1/Thruster control/Discrete Derivative'
 * '<S67>'  : 'ctrl_DP_basic/Thruster control /Thruster 1/Thruster control/MATLAB Function'
 * '<S68>'  : 'ctrl_DP_basic/Thruster control /Thruster 1/Thruster control/Supervisor'
 * '<S69>'  : 'ctrl_DP_basic/Thruster control /Thruster 1/Thruster control/Torque limit'
 * '<S70>'  : 'ctrl_DP_basic/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S71>'  : 'ctrl_DP_basic/Thruster control /Thruster 2/Propeller Hydrodynamics'
 * '<S72>'  : 'ctrl_DP_basic/Thruster control /Thruster 2/Shaft dynamics'
 * '<S73>'  : 'ctrl_DP_basic/Thruster control /Thruster 2/Thruster control'
 * '<S74>'  : 'ctrl_DP_basic/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S75>'  : 'ctrl_DP_basic/Thruster control /Thruster 2/Thruster control/Core controller'
 * '<S76>'  : 'ctrl_DP_basic/Thruster control /Thruster 2/Thruster control/Discrete Derivative'
 * '<S77>'  : 'ctrl_DP_basic/Thruster control /Thruster 2/Thruster control/MATLAB Function'
 * '<S78>'  : 'ctrl_DP_basic/Thruster control /Thruster 2/Thruster control/Supervisor'
 * '<S79>'  : 'ctrl_DP_basic/Thruster control /Thruster 2/Thruster control/Torque limit'
 * '<S80>'  : 'ctrl_DP_basic/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S81>'  : 'ctrl_DP_basic/Thruster control /Thruster 3/Propeller Hydrodynamics'
 * '<S82>'  : 'ctrl_DP_basic/Thruster control /Thruster 3/Shaft dynamics'
 * '<S83>'  : 'ctrl_DP_basic/Thruster control /Thruster 3/Thruster control'
 * '<S84>'  : 'ctrl_DP_basic/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S85>'  : 'ctrl_DP_basic/Thruster control /Thruster 3/Thruster control/Core controller'
 * '<S86>'  : 'ctrl_DP_basic/Thruster control /Thruster 3/Thruster control/Discrete Derivative'
 * '<S87>'  : 'ctrl_DP_basic/Thruster control /Thruster 3/Thruster control/MATLAB Function'
 * '<S88>'  : 'ctrl_DP_basic/Thruster control /Thruster 3/Thruster control/Supervisor'
 * '<S89>'  : 'ctrl_DP_basic/Thruster control /Thruster 3/Thruster control/Torque limit'
 * '<S90>'  : 'ctrl_DP_basic/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S91>'  : 'ctrl_DP_basic/Thruster control /Thruster 4/Propeller Hydrodynamics'
 * '<S92>'  : 'ctrl_DP_basic/Thruster control /Thruster 4/Shaft dynamics'
 * '<S93>'  : 'ctrl_DP_basic/Thruster control /Thruster 4/Thruster control'
 * '<S94>'  : 'ctrl_DP_basic/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S95>'  : 'ctrl_DP_basic/Thruster control /Thruster 4/Thruster control/Core controller'
 * '<S96>'  : 'ctrl_DP_basic/Thruster control /Thruster 4/Thruster control/Discrete Derivative'
 * '<S97>'  : 'ctrl_DP_basic/Thruster control /Thruster 4/Thruster control/MATLAB Function'
 * '<S98>'  : 'ctrl_DP_basic/Thruster control /Thruster 4/Thruster control/Supervisor'
 * '<S99>'  : 'ctrl_DP_basic/Thruster control /Thruster 4/Thruster control/Torque limit'
 * '<S100>' : 'ctrl_DP_basic/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S101>' : 'ctrl_DP_basic/Thruster control /Thruster 5/Propeller Hydrodynamics'
 * '<S102>' : 'ctrl_DP_basic/Thruster control /Thruster 5/Shaft dynamics'
 * '<S103>' : 'ctrl_DP_basic/Thruster control /Thruster 5/Thruster control'
 * '<S104>' : 'ctrl_DP_basic/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S105>' : 'ctrl_DP_basic/Thruster control /Thruster 5/Thruster control/Core controller'
 * '<S106>' : 'ctrl_DP_basic/Thruster control /Thruster 5/Thruster control/Discrete Derivative'
 * '<S107>' : 'ctrl_DP_basic/Thruster control /Thruster 5/Thruster control/MATLAB Function'
 * '<S108>' : 'ctrl_DP_basic/Thruster control /Thruster 5/Thruster control/Supervisor'
 * '<S109>' : 'ctrl_DP_basic/Thruster control /Thruster 5/Thruster control/Torque limit'
 * '<S110>' : 'ctrl_DP_basic/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S111>' : 'ctrl_DP_basic/Thruster control /Thruster 6/Propeller Hydrodynamics'
 * '<S112>' : 'ctrl_DP_basic/Thruster control /Thruster 6/Shaft dynamics'
 * '<S113>' : 'ctrl_DP_basic/Thruster control /Thruster 6/Thruster control'
 * '<S114>' : 'ctrl_DP_basic/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S115>' : 'ctrl_DP_basic/Thruster control /Thruster 6/Thruster control/Core controller'
 * '<S116>' : 'ctrl_DP_basic/Thruster control /Thruster 6/Thruster control/Discrete Derivative'
 * '<S117>' : 'ctrl_DP_basic/Thruster control /Thruster 6/Thruster control/MATLAB Function'
 * '<S118>' : 'ctrl_DP_basic/Thruster control /Thruster 6/Thruster control/Supervisor'
 * '<S119>' : 'ctrl_DP_basic/Thruster control /Thruster 6/Thruster control/Torque limit'
 * '<S120>' : 'ctrl_DP_basic/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 */
#endif                                 /* RTW_HEADER_ctrl_DP_basic_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_DP_basic
 * Model version : 1.63
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Tue May 10 14:07:05 2016
 *========================================================================*/
#ifdef NI_ROOTMODEL_ctrl_DP_basic

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* ctrl_DP_basic.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_ctrl_DP_basic_T rtParameter[NUMST+!TID01EQ];
P_ctrl_DP_basic_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_ctrl_DP_basic_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_ctrl_DP_basic_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_ctrl_DP_basic_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
