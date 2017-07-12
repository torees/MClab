/*
 * ctrl_DP.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_DP".
 *
 * Model version              : 1.201
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Tue Jul 11 19:56:09 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_DP_h_
#define RTW_HEADER_ctrl_DP_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ctrl_DP_COMMON_INCLUDES_
# define ctrl_DP_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_DP_COMMON_INCLUDES_ */

#include "ctrl_DP_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
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
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
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
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
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
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
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
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
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

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
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
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
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
#define ctrl_DP_rtModel                RT_MODEL_ctrl_DP_T

/* Block signals for system '<S24>/MATLAB Function' */
typedef struct {
  real_T y[9];                         /* '<S24>/MATLAB Function' */
} B_MATLABFunction_ctrl_DP_T;

/* Block signals for system '<S47>/CoreSubsys' */
typedef struct {
  real_T angle;                        /* '<S47>/Discrete-Time Integrator' */
  real_T Delay;                        /* '<S47>/Delay' */
  real_T MaxRotationRate;              /* '<S47>/Max Rotation Rate' */
} B_CoreSubsys_ctrl_DP_T;

/* Block states (auto storage) for system '<S47>/CoreSubsys' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S47>/Discrete-Time Integrator' */
  real_T Delay_DSTATE;                 /* '<S47>/Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S47>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S47>/Discrete-Time Integrator' */
} DW_CoreSubsys_ctrl_DP_T;

/* Block signals for system '<S54>/MATLAB Function2' */
typedef struct {
  real_T Tc_out;                       /* '<S54>/MATLAB Function2' */
} B_MATLABFunction2_ctrl_DP_T;

/* Block signals for system '<S72>/Core controller: Torque,Power and Combined Torque//Power' */
typedef struct {
  real_T Qcq;                          /* '<S72>/Core controller: Torque,Power and Combined Torque//Power' */
  real_T Qcp;                          /* '<S72>/Core controller: Torque,Power and Combined Torque//Power' */
  real_T Qcc;                          /* '<S72>/Core controller: Torque,Power and Combined Torque//Power' */
} B_CorecontrollerTorquePoweran_T;

/* Block signals for system '<S70>/Supervisor' */
typedef struct {
  real_T u;                            /* '<S70>/Supervisor' */
} B_Supervisor_ctrl_DP_T;

/* Block signals for system '<S77>/Actual Force and Torque' */
typedef struct {
  real_T Ta;                           /* '<S77>/Actual Force and Torque' */
  real_T Qa;                           /* '<S77>/Actual Force and Torque' */
} B_ActualForceandTorque_ctrl_D_T;

/* Block signals for system '<S79>/MATLAB Function' */
typedef struct {
  real_T n_d;                          /* '<S79>/MATLAB Function' */
  real_T T_r;                          /* '<S79>/MATLAB Function' */
} B_MATLABFunction_ctrl_DP_a_T;

/* Block signals (auto storage) */
typedef struct {
  real_T K_p_x;                        /* '<S24>/K_p_x' */
  real_T K_p_y;                        /* '<S24>/K_p_y' */
  real_T K_p_psi;                      /* '<S24>/K_p_psi' */
  real_T K_i_psi;                      /* '<S24>/K_i_psi' */
  real_T K_i_x;                        /* '<S24>/K_i_x' */
  real_T K_i_y;                        /* '<S24>/K_i_y' */
  real_T K_d_psi;                      /* '<S24>/K_d_psi' */
  real_T K_d_x;                        /* '<S24>/K_d_x' */
  real_T K_d_y;                        /* '<S24>/K_d_y' */
  real_T x_m;                          /* '<S7>/x_m' */
  real_T Gain;                         /* '<S7>/Gain' */
  real_T y_m;                          /* '<S7>/y_m' */
  real_T Gain1;                        /* '<S7>/Gain1' */
  real_T psi_m;                        /* '<S7>/psi_m' */
  real_T Sum;                          /* '<S7>/Sum' */
  real_T reset;                        /* '<S4>/reset' */
  real_T w_d_x;                        /* '<S25>/w_d_x' */
  real_T w_d_y;                        /* '<S25>/w_d_y' */
  real_T w_d_psi;                      /* '<S25>/w_d_psi' */
  real_T zeta_psi;                     /* '<S25>/zeta_psi' */
  real_T zeta_x;                       /* '<S25>/zeta_x' */
  real_T zeta_y;                       /* '<S25>/zeta_y' */
  real_T psi_ref;                      /* '<S4>/psi_ref' */
  real_T x_ref;                        /* '<S4>/x_ref' */
  real_T y_ref;                        /* '<S4>/y_ref' */
  real_T Integrator1[3];               /* '<S18>/Integrator1' */
  real_T Sum_a;                        /* '<S19>/Sum' */
  real_T regulationerror[3];           /* '<S13>/Sum2' */
  real_T TmpSignalConversionAtMatrixMult[3];/* '<S13>/Transposed rotation  matrix in yaw1' */
  real_T Integrator1_c[3];             /* '<S5>/Integrator1' */
  real_T Integrator3[3];               /* '<S18>/Integrator3' */
  real_T thr_angle_1;                  /* '<S12>/thr_angle_1' */
  real_T thr_angle_2;                  /* '<S12>/thr_angle_2' */
  real_T thr_angle_3;                  /* '<S12>/thr_angle_3' */
  real_T thr_angle_4;                  /* '<S12>/thr_angle_4' */
  real_T thr_angle_5;                  /* '<S12>/thr_angle_5' */
  real_T thr_angle_6;                  /* '<S12>/thr_angle_6' */
  real_T reset_g[6];                   /* '<S9>/reset' */
  real_T Angle_controller;             /* '<S9>/Angle_controller' */
  real_T ChoosingFixedAzimuthangle[6]; /* '<S9>/Choosing Fixed // Azimuth angle' */
  real_T Saturation1;                  /* '<S53>/Saturation 1' */
  real_T reset_o;                      /* '<S69>/reset' */
  real_T reset_c;                      /* '<S78>/reset' */
  real_T reset_j;                      /* '<S87>/reset' */
  real_T reset_p;                      /* '<S96>/reset' */
  real_T reset_k;                      /* '<S105>/reset' */
  real_T reset_i;                      /* '<S114>/reset' */
  real_T rpm1;                         /* '<S54>/rpm1 ' */
  real_T rpm2;                         /* '<S54>/rpm2' */
  real_T rpm3;                         /* '<S54>/rpm3' */
  real_T rpm4;                         /* '<S54>/rpm4' */
  real_T rpm5;                         /* '<S54>/rpm5' */
  real_T rpm6;                         /* '<S54>/rpm6' */
  real_T Saturation2;                  /* '<S53>/Saturation 2' */
  real_T Saturation3;                  /* '<S53>/Saturation 3' */
  real_T Saturation4;                  /* '<S53>/Saturation 4' */
  real_T Saturation5;                  /* '<S53>/Saturation 5' */
  real_T Saturation6;                  /* '<S53>/Saturation 6' */
  real_T Saturation7[6];               /* '<S54>/Saturation 7' */
  real_T Integrator[3];                /* '<S5>/Integrator' */
  real_T Sum_e;                        /* '<S40>/Sum' */
  real_T Integrator2[3];               /* '<S5>/Integrator2' */
  real_T M1[3];                        /* '<S5>/M^-1' */
  real_T Gain_g[6];                    /* '<S8>/Gain' */
  real_T MatrixMultiply[3];            /* '<S18>/Matrix Multiply' */
  real_T Sum5[3];                      /* '<S18>/Sum5' */
  real_T MatrixMultiply1[3];           /* '<S5>/Matrix Multiply1' */
  real_T Sum1[3];                      /* '<S5>/Sum1' */
  real_T Delay[6];                     /* '<S11>/Delay' */
  real_T Delay_e;                      /* '<S55>/Delay' */
  real_T Delay_a;                      /* '<S70>/Delay' */
  real_T DiscreteTransferFcn;          /* '<S70>/Discrete Transfer Fcn' */
  real_T TSamp;                        /* '<S73>/TSamp' */
  real_T Inertiacompensation;          /* '<S70>/Inertia compensation' */
  real_T Sum1_n;                       /* '<S70>/Sum1' */
  real_T Memory;                       /* '<S70>/Memory' */
  real_T Kp;                           /* '<S72>/Kp' */
  real_T reset_kk;                     /* '<S72>/reset' */
  real_T Sum_k;                        /* '<S70>/Sum' */
  real_T DiscreteTransferFcn_d;        /* '<S55>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed;         /* '<S69>/Finding rotation speed' */
  real_T Ki;                           /* '<S72>/Ki' */
  real_T Delay_b;                      /* '<S56>/Delay' */
  real_T Delay_bs;                     /* '<S79>/Delay' */
  real_T DiscreteTransferFcn_e;        /* '<S79>/Discrete Transfer Fcn' */
  real_T TSamp_n;                      /* '<S82>/TSamp' */
  real_T Inertiacompensation_e;        /* '<S79>/Inertia compensation' */
  real_T Sum1_nn;                      /* '<S79>/Sum1' */
  real_T Memory_c;                     /* '<S79>/Memory' */
  real_T Kp_p;                         /* '<S81>/Kp' */
  real_T reset_e;                      /* '<S81>/reset' */
  real_T Sum_h;                        /* '<S79>/Sum' */
  real_T DiscreteTransferFcn_k;        /* '<S56>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_a;       /* '<S78>/Finding rotation speed' */
  real_T Ki_o;                         /* '<S81>/Ki' */
  real_T Delay_i;                      /* '<S57>/Delay' */
  real_T Delay_by;                     /* '<S88>/Delay' */
  real_T DiscreteTransferFcn_f;        /* '<S88>/Discrete Transfer Fcn' */
  real_T TSamp_k;                      /* '<S91>/TSamp' */
  real_T Inertiacompensation_c;        /* '<S88>/Inertia compensation' */
  real_T Sum1_i;                       /* '<S88>/Sum1' */
  real_T Memory_i;                     /* '<S88>/Memory' */
  real_T Kp_i;                         /* '<S90>/Kp' */
  real_T reset_j2;                     /* '<S90>/reset' */
  real_T Sum_hf;                       /* '<S88>/Sum' */
  real_T DiscreteTransferFcn_n;        /* '<S57>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_m;       /* '<S87>/Finding rotation speed' */
  real_T Ki_n;                         /* '<S90>/Ki' */
  real_T Delay_g;                      /* '<S58>/Delay' */
  real_T Delay_l;                      /* '<S97>/Delay' */
  real_T DiscreteTransferFcn_l;        /* '<S97>/Discrete Transfer Fcn' */
  real_T TSamp_a;                      /* '<S100>/TSamp' */
  real_T Inertiacompensation_k;        /* '<S97>/Inertia compensation' */
  real_T Sum1_b;                       /* '<S97>/Sum1' */
  real_T Memory_j;                     /* '<S97>/Memory' */
  real_T Kp_c;                         /* '<S99>/Kp' */
  real_T reset_n;                      /* '<S99>/reset' */
  real_T Sum_k2;                       /* '<S97>/Sum' */
  real_T DiscreteTransferFcn_b;        /* '<S58>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_ms;      /* '<S96>/Finding rotation speed' */
  real_T Ki_b;                         /* '<S99>/Ki' */
  real_T Delay_a5;                     /* '<S59>/Delay' */
  real_T Delay_id;                     /* '<S106>/Delay' */
  real_T DiscreteTransferFcn_o;        /* '<S106>/Discrete Transfer Fcn' */
  real_T TSamp_m;                      /* '<S109>/TSamp' */
  real_T Inertiacompensation_f;        /* '<S106>/Inertia compensation' */
  real_T Sum1_o;                       /* '<S106>/Sum1' */
  real_T Memory_d;                     /* '<S106>/Memory' */
  real_T Kp_j;                         /* '<S108>/Kp' */
  real_T reset_f;                      /* '<S108>/reset' */
  real_T Sum_i;                        /* '<S106>/Sum' */
  real_T DiscreteTransferFcn_lz;       /* '<S59>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_ag;      /* '<S105>/Finding rotation speed' */
  real_T Ki_a;                         /* '<S108>/Ki' */
  real_T Delay_h;                      /* '<S60>/Delay' */
  real_T Delay_il;                     /* '<S115>/Delay' */
  real_T DiscreteTransferFcn_j;        /* '<S115>/Discrete Transfer Fcn' */
  real_T TSamp_o;                      /* '<S118>/TSamp' */
  real_T Inertiacompensation_e3;       /* '<S115>/Inertia compensation' */
  real_T Sum1_io;                      /* '<S115>/Sum1' */
  real_T Memory_o;                     /* '<S115>/Memory' */
  real_T Kp_l;                         /* '<S117>/Kp' */
  real_T reset_om;                     /* '<S117>/reset' */
  real_T Sum_f;                        /* '<S115>/Sum' */
  real_T DiscreteTransferFcn_ea;       /* '<S60>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_c;       /* '<S114>/Finding rotation speed' */
  real_T Ki_p;                         /* '<S117>/Ki' */
  real_T TmpSignalConversionAtDelayInpor[6];/* '<S11>/Thrust and Shaft speed mapped to PWM' */
  real_T n_d;                          /* '<S115>/MATLAB Function' */
  real_T n_d_j;                        /* '<S88>/MATLAB Function' */
  real_T n_d_l;                        /* '<S70>/MATLAB Function' */
  real_T Qa;                           /* '<S68>/Actual Force and Torque' */
  real_T Pa;                           /* '<S68>/Actual Force and Torque' */
  real_T Tc_out;                       /* '<S54>/MATLAB Function1' */
  real_T output[12];                   /* '<S54>/MATLAB Function' */
  real_T commanded_tau[3];             /* '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */
  B_Supervisor_ctrl_DP_T sf_Supervisor_e;/* '<S115>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePower_nf;/* '<S117>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_D_T sf_ActualForceandTorque_j;/* '<S113>/Actual Force and Torque' */
  B_Supervisor_ctrl_DP_T sf_Supervisor_b;/* '<S106>/Supervisor' */
  B_MATLABFunction_ctrl_DP_a_T sf_MATLABFunction_j;/* '<S106>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_h;/* '<S108>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_D_T sf_ActualForceandTorque_o;/* '<S104>/Actual Force and Torque' */
  B_Supervisor_ctrl_DP_T sf_Supervisor_n;/* '<S97>/Supervisor' */
  B_MATLABFunction_ctrl_DP_a_T sf_MATLABFunction_go;/* '<S97>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePower_n3;/* '<S99>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_D_T sf_ActualForceandTorque_m;/* '<S95>/Actual Force and Torque' */
  B_Supervisor_ctrl_DP_T sf_Supervisor_l;/* '<S88>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_n;/* '<S90>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_D_T sf_ActualForceandTorque_h;/* '<S86>/Actual Force and Torque' */
  B_Supervisor_ctrl_DP_T sf_Supervisor_h;/* '<S79>/Supervisor' */
  B_MATLABFunction_ctrl_DP_a_T sf_MATLABFunction_i;/* '<S79>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_o;/* '<S81>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_D_T sf_ActualForceandTorque_f;/* '<S77>/Actual Force and Torque' */
  B_Supervisor_ctrl_DP_T sf_Supervisor;/* '<S70>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowerand;/* '<S72>/Core controller: Torque,Power and Combined Torque//Power' */
  B_MATLABFunction2_ctrl_DP_T sf_MATLABFunction6;/* '<S54>/MATLAB Function6' */
  B_MATLABFunction2_ctrl_DP_T sf_MATLABFunction5;/* '<S54>/MATLAB Function5' */
  B_MATLABFunction2_ctrl_DP_T sf_MATLABFunction4;/* '<S54>/MATLAB Function4' */
  B_MATLABFunction2_ctrl_DP_T sf_MATLABFunction3;/* '<S54>/MATLAB Function3' */
  B_MATLABFunction2_ctrl_DP_T sf_MATLABFunction2_i;/* '<S54>/MATLAB Function2' */
  B_CoreSubsys_ctrl_DP_T CoreSubsys[6];/* '<S47>/CoreSubsys' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction2_a;/* '<S26>/MATLAB Function2' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction1_k;/* '<S26>/MATLAB Function1' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction_p;/* '<S26>/MATLAB Function' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction1_c;/* '<S25>/MATLAB Function1' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction_d;/* '<S25>/MATLAB Function' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction2;/* '<S24>/MATLAB Function2' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction1;/* '<S24>/MATLAB Function1' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction;/* '<S24>/MATLAB Function' */
} B_ctrl_DP_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[6];              /* '<S11>/Delay' */
  real_T Delay_DSTATE_f;               /* '<S55>/Delay' */
  real_T Delay_DSTATE_fu;              /* '<S70>/Delay' */
  real_T DiscreteTransferFcn_states[2];/* '<S70>/Discrete Transfer Fcn' */
  real_T UD_DSTATE;                    /* '<S73>/UD' */
  real_T DiscreteTransferFcn_states_d; /* '<S55>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_b;               /* '<S56>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S79>/Delay' */
  real_T DiscreteTransferFcn_states_h[2];/* '<S79>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_n;                  /* '<S82>/UD' */
  real_T DiscreteTransferFcn_states_m; /* '<S56>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_n;               /* '<S57>/Delay' */
  real_T Delay_DSTATE_no;              /* '<S88>/Delay' */
  real_T DiscreteTransferFcn_states_j[2];/* '<S88>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_i;                  /* '<S91>/UD' */
  real_T DiscreteTransferFcn_states_k; /* '<S57>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_e;               /* '<S58>/Delay' */
  real_T Delay_DSTATE_i;               /* '<S97>/Delay' */
  real_T DiscreteTransferFcn_states_i[2];/* '<S97>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_n4;                 /* '<S100>/UD' */
  real_T DiscreteTransferFcn_states_h0;/* '<S58>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_j;               /* '<S59>/Delay' */
  real_T Delay_DSTATE_a;               /* '<S106>/Delay' */
  real_T DiscreteTransferFcn_states_hb[2];/* '<S106>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_m;                  /* '<S109>/UD' */
  real_T DiscreteTransferFcn_states_dt;/* '<S59>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_dv;              /* '<S60>/Delay' */
  real_T Delay_DSTATE_m;               /* '<S115>/Delay' */
  real_T DiscreteTransferFcn_states_l[2];/* '<S115>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_l;                  /* '<S118>/UD' */
  real_T DiscreteTransferFcn_states_o; /* '<S60>/Discrete Transfer Fcn' */
  real_T K_p_x_DWORK1;                 /* '<S24>/K_p_x' */
  real_T K_p_y_DWORK1;                 /* '<S24>/K_p_y' */
  real_T K_p_psi_DWORK1;               /* '<S24>/K_p_psi' */
  real_T K_i_psi_DWORK1;               /* '<S24>/K_i_psi' */
  real_T K_i_x_DWORK1;                 /* '<S24>/K_i_x' */
  real_T K_i_y_DWORK1;                 /* '<S24>/K_i_y' */
  real_T K_d_psi_DWORK1;               /* '<S24>/K_d_psi' */
  real_T K_d_x_DWORK1;                 /* '<S24>/K_d_x' */
  real_T K_d_y_DWORK1;                 /* '<S24>/K_d_y' */
  real_T x_m_DWORK1;                   /* '<S7>/x_m' */
  real_T y_m_DWORK1;                   /* '<S7>/y_m' */
  real_T psi_m_DWORK1;                 /* '<S7>/psi_m' */
  real_T reset_DWORK1;                 /* '<S4>/reset' */
  real_T w_d_x_DWORK1;                 /* '<S25>/w_d_x' */
  real_T w_d_y_DWORK1;                 /* '<S25>/w_d_y' */
  real_T w_d_psi_DWORK1;               /* '<S25>/w_d_psi' */
  real_T zeta_psi_DWORK1;              /* '<S25>/zeta_psi' */
  real_T zeta_x_DWORK1;                /* '<S25>/zeta_x' */
  real_T zeta_y_DWORK1;                /* '<S25>/zeta_y' */
  real_T psi_ref_DWORK1;               /* '<S4>/psi_ref' */
  real_T x_ref_DWORK1;                 /* '<S4>/x_ref' */
  real_T y_ref_DWORK1;                 /* '<S4>/y_ref' */
  real_T thr_angle_1_DWORK1;           /* '<S12>/thr_angle_1' */
  real_T thr_angle_2_DWORK1;           /* '<S12>/thr_angle_2' */
  real_T thr_angle_3_DWORK1;           /* '<S12>/thr_angle_3' */
  real_T thr_angle_4_DWORK1;           /* '<S12>/thr_angle_4' */
  real_T thr_angle_5_DWORK1;           /* '<S12>/thr_angle_5' */
  real_T thr_angle_6_DWORK1;           /* '<S12>/thr_angle_6' */
  real_T reset_DWORK1_l[6];            /* '<S9>/reset' */
  real_T Angle_controller_DWORK1;      /* '<S9>/Angle_controller' */
  real_T alpha_1_DWORK1;               /* '<Root>/alpha_1' */
  real_T reset_DWORK1_g;               /* '<S69>/reset' */
  real_T reset_DWORK1_d;               /* '<S78>/reset' */
  real_T reset_DWORK1_e;               /* '<S87>/reset' */
  real_T reset_DWORK1_g4;              /* '<S96>/reset' */
  real_T reset_DWORK1_c;               /* '<S105>/reset' */
  real_T reset_DWORK1_a;               /* '<S114>/reset' */
  real_T rpm1_DWORK1;                  /* '<S54>/rpm1 ' */
  real_T rpm2_DWORK1;                  /* '<S54>/rpm2' */
  real_T rpm3_DWORK1;                  /* '<S54>/rpm3' */
  real_T rpm4_DWORK1;                  /* '<S54>/rpm4' */
  real_T rpm5_DWORK1;                  /* '<S54>/rpm5' */
  real_T rpm6_DWORK1;                  /* '<S54>/rpm6' */
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
  real_T tau_actual_DWORK1[3];         /* '<Root>/tau_actual' */
  real_T eta_tilde_DWORK1[3];          /* '<S13>/eta_tilde' */
  real_T x_ref_out_DWORK1;             /* '<S3>/x_ref_out' */
  real_T y_ref_out_DWORK1;             /* '<S3>/y_ref_out' */
  real_T psi_ref_out_DWORK1;           /* '<S3>/psi_ref_out' */
  real_T DiscreteTransferFcn_tmp;      /* '<S70>/Discrete Transfer Fcn' */
  real_T PrevY;                        /* '<S70>/Acceleration Limit' */
  real_T Memory_PreviousInput;         /* '<S70>/Memory' */
  real_T reset_DWORK1_ec;              /* '<S72>/reset' */
  real_T DiscreteTransferFcn_tmp_a;    /* '<S55>/Discrete Transfer Fcn' */
  real_T Control_test_Pa_DWORK1;       /* '<S68>/Control_test_Pa' */
  real_T DiscreteTransferFcn_tmp_d;    /* '<S79>/Discrete Transfer Fcn' */
  real_T PrevY_e;                      /* '<S79>/Acceleration Limit' */
  real_T Memory_PreviousInput_n;       /* '<S79>/Memory' */
  real_T reset_DWORK1_ln;              /* '<S81>/reset' */
  real_T DiscreteTransferFcn_tmp_h;    /* '<S56>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_e;    /* '<S88>/Discrete Transfer Fcn' */
  real_T PrevY_o;                      /* '<S88>/Acceleration limiter' */
  real_T Memory_PreviousInput_d;       /* '<S88>/Memory' */
  real_T reset_DWORK1_lw;              /* '<S90>/reset' */
  real_T DiscreteTransferFcn_tmp_hh;   /* '<S57>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_k;    /* '<S97>/Discrete Transfer Fcn' */
  real_T PrevY_c;                      /* '<S97>/Acceleration limiter' */
  real_T Memory_PreviousInput_a;       /* '<S97>/Memory' */
  real_T reset_DWORK1_ct;              /* '<S99>/reset' */
  real_T DiscreteTransferFcn_tmp_n;    /* '<S58>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_c;    /* '<S106>/Discrete Transfer Fcn' */
  real_T PrevY_j;                      /* '<S106>/Acceleration limiter' */
  real_T Memory_PreviousInput_b;       /* '<S106>/Memory' */
  real_T reset_DWORK1_i;               /* '<S108>/reset' */
  real_T DiscreteTransferFcn_tmp_f;    /* '<S59>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_h4;   /* '<S115>/Discrete Transfer Fcn' */
  real_T PrevY_h;                      /* '<S115>/Acceleration limiter' */
  real_T Memory_PreviousInput_a4;      /* '<S115>/Memory' */
  real_T reset_DWORK1_j;               /* '<S117>/reset' */
  real_T DiscreteTransferFcn_tmp_cw;   /* '<S60>/Discrete Transfer Fcn' */
  int_T Integrator1_IWORK;             /* '<S18>/Integrator1' */
  int_T Integrator_IWORK;              /* '<S5>/Integrator' */
  uint8_T K_p_x_DWORK2[8];             /* '<S24>/K_p_x' */
  uint8_T K_p_y_DWORK2[8];             /* '<S24>/K_p_y' */
  uint8_T K_p_psi_DWORK2[8];           /* '<S24>/K_p_psi' */
  uint8_T K_i_psi_DWORK2[8];           /* '<S24>/K_i_psi' */
  uint8_T K_i_x_DWORK2[8];             /* '<S24>/K_i_x' */
  uint8_T K_i_y_DWORK2[8];             /* '<S24>/K_i_y' */
  uint8_T K_d_psi_DWORK2[8];           /* '<S24>/K_d_psi' */
  uint8_T K_d_x_DWORK2[8];             /* '<S24>/K_d_x' */
  uint8_T K_d_y_DWORK2[8];             /* '<S24>/K_d_y' */
  uint8_T x_m_DWORK2[8];               /* '<S7>/x_m' */
  uint8_T y_m_DWORK2[8];               /* '<S7>/y_m' */
  uint8_T psi_m_DWORK2[8];             /* '<S7>/psi_m' */
  uint8_T reset_DWORK2[8];             /* '<S4>/reset' */
  uint8_T w_d_x_DWORK2[8];             /* '<S25>/w_d_x' */
  uint8_T w_d_y_DWORK2[8];             /* '<S25>/w_d_y' */
  uint8_T w_d_psi_DWORK2[8];           /* '<S25>/w_d_psi' */
  uint8_T zeta_psi_DWORK2[8];          /* '<S25>/zeta_psi' */
  uint8_T zeta_x_DWORK2[8];            /* '<S25>/zeta_x' */
  uint8_T zeta_y_DWORK2[8];            /* '<S25>/zeta_y' */
  uint8_T psi_ref_DWORK2[8];           /* '<S4>/psi_ref' */
  uint8_T x_ref_DWORK2[8];             /* '<S4>/x_ref' */
  uint8_T y_ref_DWORK2[8];             /* '<S4>/y_ref' */
  uint8_T thr_angle_1_DWORK2[8];       /* '<S12>/thr_angle_1' */
  uint8_T thr_angle_2_DWORK2[8];       /* '<S12>/thr_angle_2' */
  uint8_T thr_angle_3_DWORK2[8];       /* '<S12>/thr_angle_3' */
  uint8_T thr_angle_4_DWORK2[8];       /* '<S12>/thr_angle_4' */
  uint8_T thr_angle_5_DWORK2[8];       /* '<S12>/thr_angle_5' */
  uint8_T thr_angle_6_DWORK2[8];       /* '<S12>/thr_angle_6' */
  uint8_T reset_DWORK2_m[8];           /* '<S9>/reset' */
  uint8_T Angle_controller_DWORK2[8];  /* '<S9>/Angle_controller' */
  uint8_T alpha_1_DWORK2[8];           /* '<Root>/alpha_1' */
  uint8_T reset_DWORK2_j[8];           /* '<S69>/reset' */
  uint8_T reset_DWORK2_o[8];           /* '<S78>/reset' */
  uint8_T reset_DWORK2_i[8];           /* '<S87>/reset' */
  uint8_T reset_DWORK2_k[8];           /* '<S96>/reset' */
  uint8_T reset_DWORK2_a[8];           /* '<S105>/reset' */
  uint8_T reset_DWORK2_mm[8];          /* '<S114>/reset' */
  uint8_T rpm1_DWORK2[8];              /* '<S54>/rpm1 ' */
  uint8_T rpm2_DWORK2[8];              /* '<S54>/rpm2' */
  uint8_T rpm3_DWORK2[8];              /* '<S54>/rpm3' */
  uint8_T rpm4_DWORK2[8];              /* '<S54>/rpm4' */
  uint8_T rpm5_DWORK2[8];              /* '<S54>/rpm5' */
  uint8_T rpm6_DWORK2[8];              /* '<S54>/rpm6' */
  uint8_T pwm_2_DWORK2[8];             /* '<Root>/pwm_2' */
  uint8_T pwm_3_DWORK2[8];             /* '<Root>/pwm_3' */
  uint8_T pwm_4_DWORK2[8];             /* '<Root>/pwm_4' */
  uint8_T pwm_5_DWORK2[8];             /* '<Root>/pwm_5' */
  uint8_T alpha_2_DWORK2[8];           /* '<Root>/alpha_2' */
  uint8_T pwm_6_DWORK2[8];             /* '<Root>/pwm_6' */
  uint8_T alpha_3_DWORK2[8];           /* '<Root>/alpha_3' */
  uint8_T alpha_4_DWORK2[8];           /* '<Root>/alpha_4' */
  uint8_T alpha_5_DWORK2[8];           /* '<Root>/alpha_5' */
  uint8_T alpha_6_DWORK2[8];           /* '<Root>/alpha_6' */
  uint8_T u_1_DWORK2[8];               /* '<Root>/u_1' */
  uint8_T u_4_DWORK2[8];               /* '<Root>/u_4' */
  uint8_T u_5_DWORK2[8];               /* '<Root>/u_5' */
  uint8_T u_6_DWORK2[8];               /* '<Root>/u_6' */
  uint8_T u_2_DWORK2[8];               /* '<Root>/u_2' */
  uint8_T u_3_DWORK2[8];               /* '<Root>/u_3' */
  uint8_T pwm_1_DWORK2[8];             /* '<Root>/pwm_1' */
  uint8_T x_hat_DWORK2[8];             /* '<S43>/x_hat' */
  uint8_T y_hat_DWORK2[8];             /* '<S43>/y_hat' */
  uint8_T psi_hat_DWORK2[8];           /* '<S43>/psi_hat' */
  uint8_T u_hat_DWORK2[8];             /* '<S45>/u_hat' */
  uint8_T v_hat_DWORK2[8];             /* '<S45>/v_hat' */
  uint8_T r_hat_DWORK2[8];             /* '<S45>/r_hat' */
  uint8_T u_dot_hat_DWORK2[8];         /* '<S44>/u_dot_hat' */
  uint8_T v_dot_hat_DWORK2[8];         /* '<S44>/v_dot_hat' */
  uint8_T r_dot_hat_DWORK2[8];         /* '<S44>/r_dot_hat' */
  uint8_T b_x_hat_DWORK2[8];           /* '<S42>/b_x_hat' */
  uint8_T b_y_hat_DWORK2[8];           /* '<S42>/b_y_hat' */
  uint8_T b_psi_hat_DWORK2[8];         /* '<S42>/b_psi_hat' */
  uint8_T tau_actual_DWORK2[8];        /* '<Root>/tau_actual' */
  uint8_T eta_tilde_DWORK2[8];         /* '<S13>/eta_tilde' */
  uint8_T x_ref_out_DWORK2[8];         /* '<S3>/x_ref_out' */
  uint8_T y_ref_out_DWORK2[8];         /* '<S3>/y_ref_out' */
  uint8_T psi_ref_out_DWORK2[8];       /* '<S3>/psi_ref_out' */
  uint8_T reset_DWORK2_n[8];           /* '<S72>/reset' */
  uint8_T Control_test_Pa_DWORK2[8];   /* '<S68>/Control_test_Pa' */
  uint8_T reset_DWORK2_e[8];           /* '<S81>/reset' */
  uint8_T reset_DWORK2_l[8];           /* '<S90>/reset' */
  uint8_T reset_DWORK2_mb[8];          /* '<S99>/reset' */
  uint8_T reset_DWORK2_nu[8];          /* '<S108>/reset' */
  uint8_T reset_DWORK2_f[8];           /* '<S117>/reset' */
  DW_CoreSubsys_ctrl_DP_T CoreSubsys[6];/* '<S47>/CoreSubsys' */
} DW_ctrl_DP_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S18>/Integrator1' */
  real_T Integrator_CSTATE[3];         /* '<S13>/Integrator' */
  real_T Integrator1_CSTATE_g[3];      /* '<S5>/Integrator1' */
  real_T Integrator3_CSTATE[3];        /* '<S18>/Integrator3' */
  real_T Integrator_CSTATE_c;          /* '<S69>/Integrator' */
  real_T Integrator_CSTATE_p;          /* '<S78>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S87>/Integrator' */
  real_T Integrator_CSTATE_n;          /* '<S96>/Integrator' */
  real_T Integrator_CSTATE_cd;         /* '<S105>/Integrator' */
  real_T Integrator_CSTATE_h;          /* '<S114>/Integrator' */
  real_T Integrator_CSTATE_a[3];       /* '<S5>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S5>/Integrator2' */
  real_T Integrator2_CSTATE_c[3];      /* '<S18>/Integrator2' */
  real_T Integrator_CSTATE_e;          /* '<S72>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S81>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S90>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S99>/Integrator' */
  real_T Integrator_CSTATE_n4;         /* '<S108>/Integrator' */
  real_T Integrator_CSTATE_gj;         /* '<S117>/Integrator' */
} X_ctrl_DP_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S18>/Integrator1' */
  real_T Integrator_CSTATE[3];         /* '<S13>/Integrator' */
  real_T Integrator1_CSTATE_g[3];      /* '<S5>/Integrator1' */
  real_T Integrator3_CSTATE[3];        /* '<S18>/Integrator3' */
  real_T Integrator_CSTATE_c;          /* '<S69>/Integrator' */
  real_T Integrator_CSTATE_p;          /* '<S78>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S87>/Integrator' */
  real_T Integrator_CSTATE_n;          /* '<S96>/Integrator' */
  real_T Integrator_CSTATE_cd;         /* '<S105>/Integrator' */
  real_T Integrator_CSTATE_h;          /* '<S114>/Integrator' */
  real_T Integrator_CSTATE_a[3];       /* '<S5>/Integrator' */
  real_T Integrator2_CSTATE[3];        /* '<S5>/Integrator2' */
  real_T Integrator2_CSTATE_c[3];      /* '<S18>/Integrator2' */
  real_T Integrator_CSTATE_e;          /* '<S72>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S81>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S90>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S99>/Integrator' */
  real_T Integrator_CSTATE_n4;         /* '<S108>/Integrator' */
  real_T Integrator_CSTATE_gj;         /* '<S117>/Integrator' */
} XDot_ctrl_DP_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE[3];     /* '<S18>/Integrator1' */
  boolean_T Integrator_CSTATE[3];      /* '<S13>/Integrator' */
  boolean_T Integrator1_CSTATE_g[3];   /* '<S5>/Integrator1' */
  boolean_T Integrator3_CSTATE[3];     /* '<S18>/Integrator3' */
  boolean_T Integrator_CSTATE_c;       /* '<S69>/Integrator' */
  boolean_T Integrator_CSTATE_p;       /* '<S78>/Integrator' */
  boolean_T Integrator_CSTATE_k;       /* '<S87>/Integrator' */
  boolean_T Integrator_CSTATE_n;       /* '<S96>/Integrator' */
  boolean_T Integrator_CSTATE_cd;      /* '<S105>/Integrator' */
  boolean_T Integrator_CSTATE_h;       /* '<S114>/Integrator' */
  boolean_T Integrator_CSTATE_a[3];    /* '<S5>/Integrator' */
  boolean_T Integrator2_CSTATE[3];     /* '<S5>/Integrator2' */
  boolean_T Integrator2_CSTATE_c[3];   /* '<S18>/Integrator2' */
  boolean_T Integrator_CSTATE_e;       /* '<S72>/Integrator' */
  boolean_T Integrator_CSTATE_g;       /* '<S81>/Integrator' */
  boolean_T Integrator_CSTATE_i;       /* '<S90>/Integrator' */
  boolean_T Integrator_CSTATE_l;       /* '<S99>/Integrator' */
  boolean_T Integrator_CSTATE_n4;      /* '<S108>/Integrator' */
  boolean_T Integrator_CSTATE_gj;      /* '<S117>/Integrator' */
} XDis_ctrl_DP_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator1_Reset_ZCE;    /* '<S18>/Integrator1' */
  ZCSigState Integrator_Reset_ZCE;     /* '<S13>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE_i;  /* '<S5>/Integrator1' */
  ZCSigState Integrator3_Reset_ZCE;    /* '<S18>/Integrator3' */
  ZCSigState Integrator_Reset_ZCE_g;   /* '<S69>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_n;   /* '<S78>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_o;   /* '<S87>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_i;   /* '<S96>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_a;   /* '<S105>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_d;   /* '<S114>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_nt;  /* '<S5>/Integrator' */
  ZCSigState Integrator2_Reset_ZCE;    /* '<S5>/Integrator2' */
  ZCSigState Integrator2_Reset_ZCE_h;  /* '<S18>/Integrator2' */
  ZCSigState Integrator_Reset_ZCE_o3;  /* '<S72>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_db;  /* '<S81>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_l;   /* '<S90>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_h;   /* '<S99>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_f;   /* '<S108>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_i3;  /* '<S117>/Integrator' */
} PrevZCX_ctrl_DP_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_DP_B
#define BlockIO                        B_ctrl_DP_T
#define rtX                            ctrl_DP_X
#define ContinuousStates               X_ctrl_DP_T
#define rtXdot                         ctrl_DP_XDot
#define StateDerivatives               XDot_ctrl_DP_T
#define tXdis                          ctrl_DP_XDis
#define StateDisabled                  XDis_ctrl_DP_T
#define rtP                            ctrl_DP_P
#define Parameters                     P_ctrl_DP_T
#define rtDWork                        ctrl_DP_DW
#define D_Work                         DW_ctrl_DP_T
#define rtPrevZCSigState               ctrl_DP_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_DP_T

/* Parameters for system: '<S47>/CoreSubsys' */
struct P_CoreSubsys_ctrl_DP_T_ {
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S47>/Discrete-Time Integrator'
                                         */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S50>/Gain1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S47>/Delay'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S47>/Delay'
                                        */
};

/* Parameters (auto storage) */
struct P_ctrl_DP_T_ {
  real_T C[24];                        /* Variable: C
                                        * Referenced by: '<S9>/C'
                                        */
  real_T D;                            /* Variable: D
                                        * Referenced by: '<S10>/D'
                                        */
  real_T I_s;                          /* Variable: I_s
                                        * Referenced by:
                                        *   '<S69>/Finding rotation speed'
                                        *   '<S70>/Inertia compensation'
                                        *   '<S78>/Finding rotation speed'
                                        *   '<S79>/Inertia compensation'
                                        *   '<S87>/Finding rotation speed'
                                        *   '<S88>/Inertia compensation'
                                        *   '<S96>/Finding rotation speed'
                                        *   '<S97>/Inertia compensation'
                                        *   '<S105>/Finding rotation speed'
                                        *   '<S106>/Inertia compensation'
                                        *   '<S114>/Finding rotation speed'
                                        *   '<S115>/Inertia compensation'
                                        */
  real_T K_T1f;                        /* Variable: K_T1f
                                        * Referenced by: '<S10>/K_Tf1'
                                        */
  real_T K_T1r;                        /* Variable: K_T1r
                                        * Referenced by: '<S10>/K_Tr1'
                                        */
  real_T K_T2f;                        /* Variable: K_T2f
                                        * Referenced by: '<S10>/K_Tf2'
                                        */
  real_T K_T2r;                        /* Variable: K_T2r
                                        * Referenced by: '<S10>/K_Tr2'
                                        */
  real_T K_T3f;                        /* Variable: K_T3f
                                        * Referenced by: '<S10>/K_Tf3'
                                        */
  real_T K_T3r;                        /* Variable: K_T3r
                                        * Referenced by: '<S10>/K_Tr3'
                                        */
  real_T K_T4f;                        /* Variable: K_T4f
                                        * Referenced by: '<S10>/K_Tf4'
                                        */
  real_T K_T4r;                        /* Variable: K_T4r
                                        * Referenced by: '<S10>/K_Tr4'
                                        */
  real_T K_T5f;                        /* Variable: K_T5f
                                        * Referenced by: '<S10>/K_Tf5'
                                        */
  real_T K_T5r;                        /* Variable: K_T5r
                                        * Referenced by: '<S10>/K_Tr5'
                                        */
  real_T K_T6f;                        /* Variable: K_T6f
                                        * Referenced by: '<S10>/K_Tf6'
                                        */
  real_T K_T6r;                        /* Variable: K_T6r
                                        * Referenced by: '<S10>/K_Tr6'
                                        */
  real_T K_omega;                      /* Variable: K_omega
                                        * Referenced by:
                                        *   '<S69>/K_omega'
                                        *   '<S70>/Qff_1(nr)'
                                        *   '<S78>/K_omega'
                                        *   '<S79>/Qff_1(nr)'
                                        *   '<S87>/K_omega'
                                        *   '<S88>/Qff_1(nr)'
                                        *   '<S96>/K_omega'
                                        *   '<S97>/Qff_1(nr)'
                                        *   '<S105>/K_omega'
                                        *   '<S106>/Qff_1(nr)'
                                        *   '<S114>/K_omega'
                                        *   '<S115>/Qff_1(nr)'
                                        */
  real_T K_q1f;                        /* Variable: K_q1f
                                        * Referenced by: '<S10>/K_Qr1'
                                        */
  real_T K_q1r;                        /* Variable: K_q1r
                                        * Referenced by: '<S10>/K_Qr7'
                                        */
  real_T K_q2f;                        /* Variable: K_q2f
                                        * Referenced by: '<S10>/K_Qr2'
                                        */
  real_T K_q2r;                        /* Variable: K_q2r
                                        * Referenced by: '<S10>/K_Qr8'
                                        */
  real_T K_q3f;                        /* Variable: K_q3f
                                        * Referenced by: '<S10>/K_Qr3'
                                        */
  real_T K_q3r;                        /* Variable: K_q3r
                                        * Referenced by: '<S10>/K_Qr9'
                                        */
  real_T K_q4f;                        /* Variable: K_q4f
                                        * Referenced by: '<S10>/K_Qr4'
                                        */
  real_T K_q4r;                        /* Variable: K_q4r
                                        * Referenced by: '<S10>/K_Qr10'
                                        */
  real_T K_q5f;                        /* Variable: K_q5f
                                        * Referenced by: '<S10>/K_Qr5'
                                        */
  real_T K_q5r;                        /* Variable: K_q5r
                                        * Referenced by: '<S10>/K_Qr11'
                                        */
  real_T K_q6f;                        /* Variable: K_q6f
                                        * Referenced by: '<S10>/K_Qr6'
                                        */
  real_T K_q6r;                        /* Variable: K_q6r
                                        * Referenced by: '<S10>/K_Qr12'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by:
                                        *   '<S72>/Ki'
                                        *   '<S72>/Kp'
                                        *   '<S81>/Ki'
                                        *   '<S81>/Kp'
                                        *   '<S90>/Ki'
                                        *   '<S90>/Kp'
                                        *   '<S99>/Ki'
                                        *   '<S99>/Kp'
                                        *   '<S108>/Ki'
                                        *   '<S108>/Kp'
                                        *   '<S117>/Ki'
                                        *   '<S117>/Kp'
                                        */
  real_T Max_rotation;                 /* Variable: Max_rotation
                                        * Referenced by: '<S47>/Max Rotation Rate'
                                        */
  real_T Max_thrust;                   /* Variable: Max_thrust
                                        * Referenced by:
                                        *   '<S54>/Saturation 1'
                                        *   '<S54>/Saturation 10'
                                        *   '<S54>/Saturation 12'
                                        *   '<S54>/Saturation 3'
                                        *   '<S54>/Saturation 5'
                                        *   '<S54>/Saturation 7'
                                        *   '<S54>/Saturation 8'
                                        */
  real_T Min_thrust;                   /* Variable: Min_thrust
                                        * Referenced by:
                                        *   '<S54>/Saturation 11'
                                        *   '<S54>/Saturation 13'
                                        *   '<S54>/Saturation 2'
                                        *   '<S54>/Saturation 4'
                                        *   '<S54>/Saturation 6'
                                        *   '<S54>/Saturation 9'
                                        */
  real_T Q_f0;                         /* Variable: Q_f0
                                        * Referenced by:
                                        *   '<S70>/Qf_0'
                                        *   '<S79>/Qf_0'
                                        *   '<S88>/Qf_0'
                                        *   '<S97>/Qf_0'
                                        *   '<S106>/Qf_0'
                                        *   '<S115>/Qf_0'
                                        */
  real_T Rho;                          /* Variable: Rho
                                        * Referenced by: '<S10>/Rho'
                                        */
  real_T eps;                          /* Variable: eps
                                        * Referenced by: '<S9>/Constant to avoid singularities'
                                        */
  real_T eps_c;                        /* Variable: eps_c
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T epsilon;                      /* Variable: epsilon
                                        * Referenced by:
                                        *   '<S70>/Qff_0(nr)'
                                        *   '<S79>/Qff_0(nr)'
                                        *   '<S88>/Qff_0(nr)'
                                        *   '<S97>/Qff_0(nr)'
                                        *   '<S106>/Qff_0(nr)'
                                        *   '<S115>/Qff_0(nr)'
                                        */
  real_T k_cc;                         /* Variable: k_cc
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T n_c;                          /* Variable: n_c
                                        * Referenced by: '<S10>/Constant5'
                                        */
  real_T n_max;                        /* Variable: n_max
                                        * Referenced by:
                                        *   '<S70>/Qff_0(nr)'
                                        *   '<S79>/Qff_0(nr)'
                                        *   '<S88>/Qff_0(nr)'
                                        *   '<S97>/Qff_0(nr)'
                                        *   '<S106>/Qff_0(nr)'
                                        *   '<S115>/Qff_0(nr)'
                                        */
  real_T p_cc;                         /* Variable: p_cc
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T pwm_thr1_backward[6];         /* Variable: pwm_thr1_backward
                                        * Referenced by: '<S54>/negative thrust 1'
                                        */
  real_T pwm_thr1_forward[6];          /* Variable: pwm_thr1_forward
                                        * Referenced by: '<S54>/positive thrust 1'
                                        */
  real_T pwm_thr2_backward[6];         /* Variable: pwm_thr2_backward
                                        * Referenced by: '<S54>/negative thrust 2'
                                        */
  real_T pwm_thr2_forward[6];          /* Variable: pwm_thr2_forward
                                        * Referenced by: '<S54>/positive thrust 2'
                                        */
  real_T pwm_thr3_backward[6];         /* Variable: pwm_thr3_backward
                                        * Referenced by: '<S54>/negative thrust 3'
                                        */
  real_T pwm_thr3_forward[6];          /* Variable: pwm_thr3_forward
                                        * Referenced by: '<S54>/positive thrust 3'
                                        */
  real_T pwm_thr4_backward[6];         /* Variable: pwm_thr4_backward
                                        * Referenced by: '<S54>/negative thrust 4'
                                        */
  real_T pwm_thr4_forward[6];          /* Variable: pwm_thr4_forward
                                        * Referenced by: '<S54>/positive thrust 4'
                                        */
  real_T pwm_thr5_backward[6];         /* Variable: pwm_thr5_backward
                                        * Referenced by: '<S54>/negative thrust 5'
                                        */
  real_T pwm_thr5_forward[6];          /* Variable: pwm_thr5_forward
                                        * Referenced by: '<S54>/positive thrust 5'
                                        */
  real_T pwm_thr6_backward[6];         /* Variable: pwm_thr6_backward
                                        * Referenced by: '<S54>/negative thrust 6'
                                        */
  real_T pwm_thr6_forward[6];          /* Variable: pwm_thr6_forward
                                        * Referenced by: '<S54>/positive thrust 6'
                                        */
  real_T r_cc;                         /* Variable: r_cc
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S73>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_p;/* Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                          * Referenced by: '<S82>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevSca_pl;/* Mask Parameter: DiscreteDerivative_ICPrevSca_pl
                                          * Referenced by: '<S91>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_f;/* Mask Parameter: DiscreteDerivative_ICPrevScal_f
                                          * Referenced by: '<S100>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_o;/* Mask Parameter: DiscreteDerivative_ICPrevScal_o
                                          * Referenced by: '<S109>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_n;/* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                          * Referenced by: '<S118>/UD'
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
  real_T x_m_P1;                       /* Expression: width
                                        * Referenced by: '<S7>/x_m'
                                        */
  real_T x_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S7>/x_m'
                                        */
  real_T x_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S7>/x_m'
                                        */
  real_T x_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S7>/x_m'
                                        */
  real_T x_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S7>/x_m'
                                        */
  real_T x_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S7>/x_m'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/1000
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T y_m_P1;                       /* Expression: width
                                        * Referenced by: '<S7>/y_m'
                                        */
  real_T y_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S7>/y_m'
                                        */
  real_T y_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S7>/y_m'
                                        */
  real_T y_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S7>/y_m'
                                        */
  real_T y_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S7>/y_m'
                                        */
  real_T y_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S7>/y_m'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T psi_m_P1;                     /* Expression: width
                                        * Referenced by: '<S7>/psi_m'
                                        */
  real_T psi_m_P2;                     /* Expression: dtype
                                        * Referenced by: '<S7>/psi_m'
                                        */
  real_T psi_m_P3;                     /* Expression: portnum
                                        * Referenced by: '<S7>/psi_m'
                                        */
  real_T psi_m_P4;                     /* Expression: stime
                                        * Referenced by: '<S7>/psi_m'
                                        */
  real_T psi_m_P5;                     /* Expression: stype
                                        * Referenced by: '<S7>/psi_m'
                                        */
  real_T psi_m_P6;                     /* Expression: btype
                                        * Referenced by: '<S7>/psi_m'
                                        */
  real_T Gain5_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S7>/Gain5'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1e10
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1e10
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Gain6_Gain;                   /* Expression: pi
                                        * Referenced by: '<S7>/Gain6'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1e10
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: -1e10
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Gain_Gain_p;                  /* Expression: pi
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T reset_P1;                     /* Expression: width
                                        * Referenced by: '<S4>/reset'
                                        */
  real_T reset_P2;                     /* Expression: dtype
                                        * Referenced by: '<S4>/reset'
                                        */
  real_T reset_P3;                     /* Expression: portnum
                                        * Referenced by: '<S4>/reset'
                                        */
  real_T reset_P4;                     /* Expression: stime
                                        * Referenced by: '<S4>/reset'
                                        */
  real_T reset_P5;                     /* Expression: stype
                                        * Referenced by: '<S4>/reset'
                                        */
  real_T reset_P6;                     /* Expression: btype
                                        * Referenced by: '<S4>/reset'
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
                                        * Referenced by: '<S4>/psi_ref'
                                        */
  real_T psi_ref_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/psi_ref'
                                        */
  real_T psi_ref_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/psi_ref'
                                        */
  real_T psi_ref_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/psi_ref'
                                        */
  real_T psi_ref_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/psi_ref'
                                        */
  real_T psi_ref_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/psi_ref'
                                        */
  real_T x_ref_P1;                     /* Expression: width
                                        * Referenced by: '<S4>/x_ref'
                                        */
  real_T x_ref_P2;                     /* Expression: dtype
                                        * Referenced by: '<S4>/x_ref'
                                        */
  real_T x_ref_P3;                     /* Expression: portnum
                                        * Referenced by: '<S4>/x_ref'
                                        */
  real_T x_ref_P4;                     /* Expression: stime
                                        * Referenced by: '<S4>/x_ref'
                                        */
  real_T x_ref_P5;                     /* Expression: stype
                                        * Referenced by: '<S4>/x_ref'
                                        */
  real_T x_ref_P6;                     /* Expression: btype
                                        * Referenced by: '<S4>/x_ref'
                                        */
  real_T y_ref_P1;                     /* Expression: width
                                        * Referenced by: '<S4>/y_ref'
                                        */
  real_T y_ref_P2;                     /* Expression: dtype
                                        * Referenced by: '<S4>/y_ref'
                                        */
  real_T y_ref_P3;                     /* Expression: portnum
                                        * Referenced by: '<S4>/y_ref'
                                        */
  real_T y_ref_P4;                     /* Expression: stime
                                        * Referenced by: '<S4>/y_ref'
                                        */
  real_T y_ref_P5;                     /* Expression: stype
                                        * Referenced by: '<S4>/y_ref'
                                        */
  real_T y_ref_P6;                     /* Expression: btype
                                        * Referenced by: '<S4>/y_ref'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 1e10
                                        * Referenced by: '<S19>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -1e10
                                        * Referenced by: '<S19>/Saturation'
                                        */
  real_T Gain_Gain_a;                  /* Expression: pi
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Constant_Value_j;             /* Expression: 2*pi
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1e10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -1e10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Gain_Gain_ag;                 /* Expression: pi
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Constant_Value_l;             /* Expression: 2*pi
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Integrator1_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S18>/Integrator3'
                                        */
  real_T thr_angle_1_P1;               /* Expression: width
                                        * Referenced by: '<S12>/thr_angle_1'
                                        */
  real_T thr_angle_1_P2;               /* Expression: dtype
                                        * Referenced by: '<S12>/thr_angle_1'
                                        */
  real_T thr_angle_1_P3;               /* Expression: portnum
                                        * Referenced by: '<S12>/thr_angle_1'
                                        */
  real_T thr_angle_1_P4;               /* Expression: stime
                                        * Referenced by: '<S12>/thr_angle_1'
                                        */
  real_T thr_angle_1_P5;               /* Expression: stype
                                        * Referenced by: '<S12>/thr_angle_1'
                                        */
  real_T thr_angle_1_P6;               /* Expression: btype
                                        * Referenced by: '<S12>/thr_angle_1'
                                        */
  real_T thr_angle_2_P1;               /* Expression: width
                                        * Referenced by: '<S12>/thr_angle_2'
                                        */
  real_T thr_angle_2_P2;               /* Expression: dtype
                                        * Referenced by: '<S12>/thr_angle_2'
                                        */
  real_T thr_angle_2_P3;               /* Expression: portnum
                                        * Referenced by: '<S12>/thr_angle_2'
                                        */
  real_T thr_angle_2_P4;               /* Expression: stime
                                        * Referenced by: '<S12>/thr_angle_2'
                                        */
  real_T thr_angle_2_P5;               /* Expression: stype
                                        * Referenced by: '<S12>/thr_angle_2'
                                        */
  real_T thr_angle_2_P6;               /* Expression: btype
                                        * Referenced by: '<S12>/thr_angle_2'
                                        */
  real_T thr_angle_3_P1;               /* Expression: width
                                        * Referenced by: '<S12>/thr_angle_3'
                                        */
  real_T thr_angle_3_P2;               /* Expression: dtype
                                        * Referenced by: '<S12>/thr_angle_3'
                                        */
  real_T thr_angle_3_P3;               /* Expression: portnum
                                        * Referenced by: '<S12>/thr_angle_3'
                                        */
  real_T thr_angle_3_P4;               /* Expression: stime
                                        * Referenced by: '<S12>/thr_angle_3'
                                        */
  real_T thr_angle_3_P5;               /* Expression: stype
                                        * Referenced by: '<S12>/thr_angle_3'
                                        */
  real_T thr_angle_3_P6;               /* Expression: btype
                                        * Referenced by: '<S12>/thr_angle_3'
                                        */
  real_T thr_angle_4_P1;               /* Expression: width
                                        * Referenced by: '<S12>/thr_angle_4'
                                        */
  real_T thr_angle_4_P2;               /* Expression: dtype
                                        * Referenced by: '<S12>/thr_angle_4'
                                        */
  real_T thr_angle_4_P3;               /* Expression: portnum
                                        * Referenced by: '<S12>/thr_angle_4'
                                        */
  real_T thr_angle_4_P4;               /* Expression: stime
                                        * Referenced by: '<S12>/thr_angle_4'
                                        */
  real_T thr_angle_4_P5;               /* Expression: stype
                                        * Referenced by: '<S12>/thr_angle_4'
                                        */
  real_T thr_angle_4_P6;               /* Expression: btype
                                        * Referenced by: '<S12>/thr_angle_4'
                                        */
  real_T thr_angle_5_P1;               /* Expression: width
                                        * Referenced by: '<S12>/thr_angle_5'
                                        */
  real_T thr_angle_5_P2;               /* Expression: dtype
                                        * Referenced by: '<S12>/thr_angle_5'
                                        */
  real_T thr_angle_5_P3;               /* Expression: portnum
                                        * Referenced by: '<S12>/thr_angle_5'
                                        */
  real_T thr_angle_5_P4;               /* Expression: stime
                                        * Referenced by: '<S12>/thr_angle_5'
                                        */
  real_T thr_angle_5_P5;               /* Expression: stype
                                        * Referenced by: '<S12>/thr_angle_5'
                                        */
  real_T thr_angle_5_P6;               /* Expression: btype
                                        * Referenced by: '<S12>/thr_angle_5'
                                        */
  real_T thr_angle_6_P1;               /* Expression: width
                                        * Referenced by: '<S12>/thr_angle_6'
                                        */
  real_T thr_angle_6_P2;               /* Expression: dtype
                                        * Referenced by: '<S12>/thr_angle_6'
                                        */
  real_T thr_angle_6_P3;               /* Expression: portnum
                                        * Referenced by: '<S12>/thr_angle_6'
                                        */
  real_T thr_angle_6_P4;               /* Expression: stime
                                        * Referenced by: '<S12>/thr_angle_6'
                                        */
  real_T thr_angle_6_P5;               /* Expression: stype
                                        * Referenced by: '<S12>/thr_angle_6'
                                        */
  real_T thr_angle_6_P6;               /* Expression: btype
                                        * Referenced by: '<S12>/thr_angle_6'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 180/pi
                                        * Referenced by: '<S48>/Gain'
                                        */
  real_T XpositionThruster_Value[6];   /* Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
                                        * Referenced by: '<S9>/X-position Thruster'
                                        */
  real_T YpositionThruster_Value[6];   /* Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
                                        * Referenced by: '<S9>/Y-position Thruster'
                                        */
  real_T reset_P1_m;                   /* Expression: width
                                        * Referenced by: '<S9>/reset'
                                        */
  real_T reset_P2_f;                   /* Expression: dtype
                                        * Referenced by: '<S9>/reset'
                                        */
  real_T reset_P3_k;                   /* Expression: portnum
                                        * Referenced by: '<S9>/reset'
                                        */
  real_T reset_P4_e;                   /* Expression: stime
                                        * Referenced by: '<S9>/reset'
                                        */
  real_T reset_P5_f;                   /* Expression: stype
                                        * Referenced by: '<S9>/reset'
                                        */
  real_T reset_P6_h;                   /* Expression: btype
                                        * Referenced by: '<S9>/reset'
                                        */
  real_T Angle_controller_P1;          /* Expression: width
                                        * Referenced by: '<S9>/Angle_controller'
                                        */
  real_T Angle_controller_P2;          /* Expression: dtype
                                        * Referenced by: '<S9>/Angle_controller'
                                        */
  real_T Angle_controller_P3;          /* Expression: portnum
                                        * Referenced by: '<S9>/Angle_controller'
                                        */
  real_T Angle_controller_P4;          /* Expression: stime
                                        * Referenced by: '<S9>/Angle_controller'
                                        */
  real_T Angle_controller_P5;          /* Expression: stype
                                        * Referenced by: '<S9>/Angle_controller'
                                        */
  real_T Angle_controller_P6;          /* Expression: btype
                                        * Referenced by: '<S9>/Angle_controller'
                                        */
  real_T constantangle_Value[6];       /* Expression: [Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)]
                                        * Referenced by: '<S9>/constant angle'
                                        */
  real_T ChoosingFixedAzimuthangle_Thres;/* Expression: 1
                                          * Referenced by: '<S9>/Choosing Fixed // Azimuth angle'
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
  real_T reset_P1_e;                   /* Expression: width
                                        * Referenced by: '<S69>/reset'
                                        */
  real_T reset_P2_l;                   /* Expression: dtype
                                        * Referenced by: '<S69>/reset'
                                        */
  real_T reset_P3_h;                   /* Expression: portnum
                                        * Referenced by: '<S69>/reset'
                                        */
  real_T reset_P4_j;                   /* Expression: stime
                                        * Referenced by: '<S69>/reset'
                                        */
  real_T reset_P5_i;                   /* Expression: stype
                                        * Referenced by: '<S69>/reset'
                                        */
  real_T reset_P6_f;                   /* Expression: btype
                                        * Referenced by: '<S69>/reset'
                                        */
  real_T Integrator_IC_f;              /* Expression: 0
                                        * Referenced by: '<S69>/Integrator'
                                        */
  real_T Lossesplaceholder_Value;      /* Expression: 0
                                        * Referenced by: '<S55>/Losses (placeholder)'
                                        */
  real_T reset_P1_k;                   /* Expression: width
                                        * Referenced by: '<S78>/reset'
                                        */
  real_T reset_P2_n;                   /* Expression: dtype
                                        * Referenced by: '<S78>/reset'
                                        */
  real_T reset_P3_a;                   /* Expression: portnum
                                        * Referenced by: '<S78>/reset'
                                        */
  real_T reset_P4_eg;                  /* Expression: stime
                                        * Referenced by: '<S78>/reset'
                                        */
  real_T reset_P5_m;                   /* Expression: stype
                                        * Referenced by: '<S78>/reset'
                                        */
  real_T reset_P6_c;                   /* Expression: btype
                                        * Referenced by: '<S78>/reset'
                                        */
  real_T Integrator_IC_fg;             /* Expression: 0
                                        * Referenced by: '<S78>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_k;    /* Expression: 0
                                        * Referenced by: '<S56>/Losses (placeholder)'
                                        */
  real_T reset_P1_m2;                  /* Expression: width
                                        * Referenced by: '<S87>/reset'
                                        */
  real_T reset_P2_j;                   /* Expression: dtype
                                        * Referenced by: '<S87>/reset'
                                        */
  real_T reset_P3_i;                   /* Expression: portnum
                                        * Referenced by: '<S87>/reset'
                                        */
  real_T reset_P4_h;                   /* Expression: stime
                                        * Referenced by: '<S87>/reset'
                                        */
  real_T reset_P5_a;                   /* Expression: stype
                                        * Referenced by: '<S87>/reset'
                                        */
  real_T reset_P6_l;                   /* Expression: btype
                                        * Referenced by: '<S87>/reset'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S87>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_n;    /* Expression: 0
                                        * Referenced by: '<S57>/Losses (placeholder)'
                                        */
  real_T reset_P1_kz;                  /* Expression: width
                                        * Referenced by: '<S96>/reset'
                                        */
  real_T reset_P2_ng;                  /* Expression: dtype
                                        * Referenced by: '<S96>/reset'
                                        */
  real_T reset_P3_e;                   /* Expression: portnum
                                        * Referenced by: '<S96>/reset'
                                        */
  real_T reset_P4_b;                   /* Expression: stime
                                        * Referenced by: '<S96>/reset'
                                        */
  real_T reset_P5_g;                   /* Expression: stype
                                        * Referenced by: '<S96>/reset'
                                        */
  real_T reset_P6_n;                   /* Expression: btype
                                        * Referenced by: '<S96>/reset'
                                        */
  real_T Integrator_IC_fv;             /* Expression: 0
                                        * Referenced by: '<S96>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_d;    /* Expression: 0
                                        * Referenced by: '<S58>/Losses (placeholder)'
                                        */
  real_T reset_P1_j;                   /* Expression: width
                                        * Referenced by: '<S105>/reset'
                                        */
  real_T reset_P2_m;                   /* Expression: dtype
                                        * Referenced by: '<S105>/reset'
                                        */
  real_T reset_P3_p;                   /* Expression: portnum
                                        * Referenced by: '<S105>/reset'
                                        */
  real_T reset_P4_k;                   /* Expression: stime
                                        * Referenced by: '<S105>/reset'
                                        */
  real_T reset_P5_l;                   /* Expression: stype
                                        * Referenced by: '<S105>/reset'
                                        */
  real_T reset_P6_g;                   /* Expression: btype
                                        * Referenced by: '<S105>/reset'
                                        */
  real_T Integrator_IC_l;              /* Expression: 0
                                        * Referenced by: '<S105>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_f;    /* Expression: 0
                                        * Referenced by: '<S59>/Losses (placeholder)'
                                        */
  real_T reset_P1_d;                   /* Expression: width
                                        * Referenced by: '<S114>/reset'
                                        */
  real_T reset_P2_g;                   /* Expression: dtype
                                        * Referenced by: '<S114>/reset'
                                        */
  real_T reset_P3_ic;                  /* Expression: portnum
                                        * Referenced by: '<S114>/reset'
                                        */
  real_T reset_P4_o;                   /* Expression: stime
                                        * Referenced by: '<S114>/reset'
                                        */
  real_T reset_P5_ll;                  /* Expression: stype
                                        * Referenced by: '<S114>/reset'
                                        */
  real_T reset_P6_i;                   /* Expression: btype
                                        * Referenced by: '<S114>/reset'
                                        */
  real_T Integrator_IC_li;             /* Expression: 0
                                        * Referenced by: '<S114>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_h;    /* Expression: 0
                                        * Referenced by: '<S60>/Losses (placeholder)'
                                        */
  real_T rpm1_P1;                      /* Expression: width
                                        * Referenced by: '<S54>/rpm1 '
                                        */
  real_T rpm1_P2;                      /* Expression: dtype
                                        * Referenced by: '<S54>/rpm1 '
                                        */
  real_T rpm1_P3;                      /* Expression: portnum
                                        * Referenced by: '<S54>/rpm1 '
                                        */
  real_T rpm1_P4;                      /* Expression: stime
                                        * Referenced by: '<S54>/rpm1 '
                                        */
  real_T rpm1_P5;                      /* Expression: stype
                                        * Referenced by: '<S54>/rpm1 '
                                        */
  real_T rpm1_P6;                      /* Expression: btype
                                        * Referenced by: '<S54>/rpm1 '
                                        */
  real_T Gain_Gain_d;                  /* Expression: 1/60
                                        * Referenced by: '<S54>/Gain'
                                        */
  real_T rpm2_P1;                      /* Expression: width
                                        * Referenced by: '<S54>/rpm2'
                                        */
  real_T rpm2_P2;                      /* Expression: dtype
                                        * Referenced by: '<S54>/rpm2'
                                        */
  real_T rpm2_P3;                      /* Expression: portnum
                                        * Referenced by: '<S54>/rpm2'
                                        */
  real_T rpm2_P4;                      /* Expression: stime
                                        * Referenced by: '<S54>/rpm2'
                                        */
  real_T rpm2_P5;                      /* Expression: stype
                                        * Referenced by: '<S54>/rpm2'
                                        */
  real_T rpm2_P6;                      /* Expression: btype
                                        * Referenced by: '<S54>/rpm2'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 1/60
                                        * Referenced by: '<S54>/Gain1'
                                        */
  real_T rpm3_P1;                      /* Expression: width
                                        * Referenced by: '<S54>/rpm3'
                                        */
  real_T rpm3_P2;                      /* Expression: dtype
                                        * Referenced by: '<S54>/rpm3'
                                        */
  real_T rpm3_P3;                      /* Expression: portnum
                                        * Referenced by: '<S54>/rpm3'
                                        */
  real_T rpm3_P4;                      /* Expression: stime
                                        * Referenced by: '<S54>/rpm3'
                                        */
  real_T rpm3_P5;                      /* Expression: stype
                                        * Referenced by: '<S54>/rpm3'
                                        */
  real_T rpm3_P6;                      /* Expression: btype
                                        * Referenced by: '<S54>/rpm3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/60
                                        * Referenced by: '<S54>/Gain2'
                                        */
  real_T rpm4_P1;                      /* Expression: width
                                        * Referenced by: '<S54>/rpm4'
                                        */
  real_T rpm4_P2;                      /* Expression: dtype
                                        * Referenced by: '<S54>/rpm4'
                                        */
  real_T rpm4_P3;                      /* Expression: portnum
                                        * Referenced by: '<S54>/rpm4'
                                        */
  real_T rpm4_P4;                      /* Expression: stime
                                        * Referenced by: '<S54>/rpm4'
                                        */
  real_T rpm4_P5;                      /* Expression: stype
                                        * Referenced by: '<S54>/rpm4'
                                        */
  real_T rpm4_P6;                      /* Expression: btype
                                        * Referenced by: '<S54>/rpm4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/60
                                        * Referenced by: '<S54>/Gain3'
                                        */
  real_T rpm5_P1;                      /* Expression: width
                                        * Referenced by: '<S54>/rpm5'
                                        */
  real_T rpm5_P2;                      /* Expression: dtype
                                        * Referenced by: '<S54>/rpm5'
                                        */
  real_T rpm5_P3;                      /* Expression: portnum
                                        * Referenced by: '<S54>/rpm5'
                                        */
  real_T rpm5_P4;                      /* Expression: stime
                                        * Referenced by: '<S54>/rpm5'
                                        */
  real_T rpm5_P5;                      /* Expression: stype
                                        * Referenced by: '<S54>/rpm5'
                                        */
  real_T rpm5_P6;                      /* Expression: btype
                                        * Referenced by: '<S54>/rpm5'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/60
                                        * Referenced by: '<S54>/Gain4'
                                        */
  real_T rpm6_P1;                      /* Expression: width
                                        * Referenced by: '<S54>/rpm6'
                                        */
  real_T rpm6_P2;                      /* Expression: dtype
                                        * Referenced by: '<S54>/rpm6'
                                        */
  real_T rpm6_P3;                      /* Expression: portnum
                                        * Referenced by: '<S54>/rpm6'
                                        */
  real_T rpm6_P4;                      /* Expression: stime
                                        * Referenced by: '<S54>/rpm6'
                                        */
  real_T rpm6_P5;                      /* Expression: stype
                                        * Referenced by: '<S54>/rpm6'
                                        */
  real_T rpm6_P6;                      /* Expression: btype
                                        * Referenced by: '<S54>/rpm6'
                                        */
  real_T Gain5_Gain_m;                 /* Expression: 1/60
                                        * Referenced by: '<S54>/Gain5'
                                        */
  real_T Saturation8_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S54>/Saturation 8'
                                        */
  real_T Saturation9_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S54>/Saturation 9'
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
                                        * Referenced by: '<S54>/Saturation 10'
                                        */
  real_T Saturation11_UpperSat;        /* Expression: 0
                                        * Referenced by: '<S54>/Saturation 11'
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
                                        * Referenced by: '<S54>/Saturation 3'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S54>/Saturation 4'
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
                                        * Referenced by: '<S54>/Saturation 5'
                                        */
  real_T Saturation6_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S54>/Saturation 6'
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
  real_T Saturation12_LowerSat;        /* Expression: 0
                                        * Referenced by: '<S54>/Saturation 12'
                                        */
  real_T Saturation13_UpperSat;        /* Expression: 0
                                        * Referenced by: '<S54>/Saturation 13'
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
                                        * Referenced by: '<S53>/Saturation 3'
                                        */
  real_T Saturation3_LowerSat_f;       /* Expression: -pi
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
  real_T Saturation4_UpperSat_p;       /* Expression: pi
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
  real_T Saturation5_LowerSat_h;       /* Expression: -pi
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
  real_T Saturation6_UpperSat_g;       /* Expression: pi
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
                                        * Referenced by: '<S54>/Saturation 1'
                                        */
  real_T Saturation2_UpperSat_p;       /* Expression: 0
                                        * Referenced by: '<S54>/Saturation 2'
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
  real_T Saturation_UpperSat_i;        /* Expression: 1e10
                                        * Referenced by: '<S40>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -1e10
                                        * Referenced by: '<S40>/Saturation'
                                        */
  real_T Gain_Gain_pg;                 /* Expression: pi
                                        * Referenced by: '<S40>/Gain'
                                        */
  real_T Constant_Value_k;             /* Expression: 2*pi
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
  real_T Saturation_UpperSat_e;        /* Expression: 1e10
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: -1e10
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T Gain_Gain_f;                  /* Expression: pi
                                        * Referenced by: '<S41>/Gain'
                                        */
  real_T Constant_Value_p;             /* Expression: 2*pi
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Integrator2_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  real_T M1_Gain[9];                   /* Expression: [0.008021948049864 0 0;0 0.010098125265799 1.104781662647098e-04;0 3.303823257820844e-05 0.020839338676560]
                                        * Referenced by: '<S5>/M^-1'
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
  real_T Gain_Gain_f0;                 /* Expression: 180/pi
                                        * Referenced by: '<S8>/Gain'
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
                                        * Referenced by: '<S13>/eta_tilde'
                                        */
  real_T eta_tilde_P2;                 /* Expression: dtype
                                        * Referenced by: '<S13>/eta_tilde'
                                        */
  real_T eta_tilde_P3;                 /* Expression: portnum
                                        * Referenced by: '<S13>/eta_tilde'
                                        */
  real_T eta_tilde_P4;                 /* Expression: stime
                                        * Referenced by: '<S13>/eta_tilde'
                                        */
  real_T eta_tilde_P5;                 /* Expression: stype
                                        * Referenced by: '<S13>/eta_tilde'
                                        */
  real_T eta_tilde_P6;                 /* Expression: btype
                                        * Referenced by: '<S13>/eta_tilde'
                                        */
  real_T x_ref_out_P1;                 /* Expression: width
                                        * Referenced by: '<S3>/x_ref_out'
                                        */
  real_T x_ref_out_P2;                 /* Expression: dtype
                                        * Referenced by: '<S3>/x_ref_out'
                                        */
  real_T x_ref_out_P3;                 /* Expression: portnum
                                        * Referenced by: '<S3>/x_ref_out'
                                        */
  real_T x_ref_out_P4;                 /* Expression: stime
                                        * Referenced by: '<S3>/x_ref_out'
                                        */
  real_T x_ref_out_P5;                 /* Expression: stype
                                        * Referenced by: '<S3>/x_ref_out'
                                        */
  real_T x_ref_out_P6;                 /* Expression: btype
                                        * Referenced by: '<S3>/x_ref_out'
                                        */
  real_T y_ref_out_P1;                 /* Expression: width
                                        * Referenced by: '<S3>/y_ref_out'
                                        */
  real_T y_ref_out_P2;                 /* Expression: dtype
                                        * Referenced by: '<S3>/y_ref_out'
                                        */
  real_T y_ref_out_P3;                 /* Expression: portnum
                                        * Referenced by: '<S3>/y_ref_out'
                                        */
  real_T y_ref_out_P4;                 /* Expression: stime
                                        * Referenced by: '<S3>/y_ref_out'
                                        */
  real_T y_ref_out_P5;                 /* Expression: stype
                                        * Referenced by: '<S3>/y_ref_out'
                                        */
  real_T y_ref_out_P6;                 /* Expression: btype
                                        * Referenced by: '<S3>/y_ref_out'
                                        */
  real_T psi_ref_out_P1;               /* Expression: width
                                        * Referenced by: '<S3>/psi_ref_out'
                                        */
  real_T psi_ref_out_P2;               /* Expression: dtype
                                        * Referenced by: '<S3>/psi_ref_out'
                                        */
  real_T psi_ref_out_P3;               /* Expression: portnum
                                        * Referenced by: '<S3>/psi_ref_out'
                                        */
  real_T psi_ref_out_P4;               /* Expression: stime
                                        * Referenced by: '<S3>/psi_ref_out'
                                        */
  real_T psi_ref_out_P5;               /* Expression: stype
                                        * Referenced by: '<S3>/psi_ref_out'
                                        */
  real_T psi_ref_out_P6;               /* Expression: btype
                                        * Referenced by: '<S3>/psi_ref_out'
                                        */
  real_T Integrator2_IC_p;             /* Expression: 0
                                        * Referenced by: '<S18>/Integrator2'
                                        */
  real_T Constant_Value_c;             /* Expression: 50
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 50
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
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S11>/Delay'
                                        */
  real_T Constant_Value_cs[2];         /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T Constant1_Value_k[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S55>/Constant1'
                                        */
  real_T Delay_InitialCondition_i;     /* Expression: 0
                                        * Referenced by: '<S55>/Delay'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0
                                        * Referenced by: '<S70>/Delay'
                                        */
  real_T Constant1_Value_o[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S70>/Constant1'
                                        */
  real_T Constant2_Value_b[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S70>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S70>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S73>/TSamp'
                                        */
  real_T AccelerationLimit_RisingLim;  /* Computed Parameter: AccelerationLimit_RisingLim
                                        * Referenced by: '<S70>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_FallingLim; /* Computed Parameter: AccelerationLimit_FallingLim
                                        * Referenced by: '<S70>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_IC;         /* Expression: 0
                                        * Referenced by: '<S70>/Acceleration Limit'
                                        */
  real_T Memory_X0;                    /* Expression: 1
                                        * Referenced by: '<S70>/Memory'
                                        */
  real_T reset_P1_b;                   /* Expression: width
                                        * Referenced by: '<S72>/reset'
                                        */
  real_T reset_P2_h;                   /* Expression: dtype
                                        * Referenced by: '<S72>/reset'
                                        */
  real_T reset_P3_f;                   /* Expression: portnum
                                        * Referenced by: '<S72>/reset'
                                        */
  real_T reset_P4_c;                   /* Expression: stime
                                        * Referenced by: '<S72>/reset'
                                        */
  real_T reset_P5_k;                   /* Expression: stype
                                        * Referenced by: '<S72>/reset'
                                        */
  real_T reset_P6_d;                   /* Expression: btype
                                        * Referenced by: '<S72>/reset'
                                        */
  real_T Integrator_IC_a;              /* Expression: 0
                                        * Referenced by: '<S72>/Integrator'
                                        */
  real_T NaN_Value;                    /* Expression: 0
                                        * Referenced by: '<S70>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_h;/* Expression: 0
                                          * Referenced by: '<S55>/Discrete Transfer Fcn'
                                          */
  real_T Control_test_Pa_P1;           /* Expression: width
                                        * Referenced by: '<S68>/Control_test_Pa'
                                        */
  real_T Control_test_Pa_P2;           /* Expression: dtype
                                        * Referenced by: '<S68>/Control_test_Pa'
                                        */
  real_T Control_test_Pa_P3;           /* Expression: portnum
                                        * Referenced by: '<S68>/Control_test_Pa'
                                        */
  real_T Control_test_Pa_P4;           /* Expression: stime
                                        * Referenced by: '<S68>/Control_test_Pa'
                                        */
  real_T Control_test_Pa_P5;           /* Expression: stype
                                        * Referenced by: '<S68>/Control_test_Pa'
                                        */
  real_T Control_test_Pa_P6;           /* Expression: btype
                                        * Referenced by: '<S68>/Control_test_Pa'
                                        */
  real_T Constant_Value_h[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T Constant1_Value_j[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S56>/Constant1'
                                        */
  real_T Delay_InitialCondition_l;     /* Expression: 0
                                        * Referenced by: '<S56>/Delay'
                                        */
  real_T Delay_InitialCondition_iv;    /* Expression: 0
                                        * Referenced by: '<S79>/Delay'
                                        */
  real_T Constant1_Value_b[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S79>/Constant1'
                                        */
  real_T Constant2_Value_i[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S79>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_hu;/* Expression: 0
                                          * Referenced by: '<S79>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_k;                 /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S82>/TSamp'
                                        */
  real_T AccelerationLimit_RisingLim_n;/* Computed Parameter: AccelerationLimit_RisingLim_n
                                        * Referenced by: '<S79>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_FallingLim_n;/* Computed Parameter: AccelerationLimit_FallingLim_n
                                         * Referenced by: '<S79>/Acceleration Limit'
                                         */
  real_T AccelerationLimit_IC_m;       /* Expression: 0
                                        * Referenced by: '<S79>/Acceleration Limit'
                                        */
  real_T Memory_X0_e;                  /* Expression: 1
                                        * Referenced by: '<S79>/Memory'
                                        */
  real_T reset_P1_g;                   /* Expression: width
                                        * Referenced by: '<S81>/reset'
                                        */
  real_T reset_P2_i;                   /* Expression: dtype
                                        * Referenced by: '<S81>/reset'
                                        */
  real_T reset_P3_l;                   /* Expression: portnum
                                        * Referenced by: '<S81>/reset'
                                        */
  real_T reset_P4_n;                   /* Expression: stime
                                        * Referenced by: '<S81>/reset'
                                        */
  real_T reset_P5_b;                   /* Expression: stype
                                        * Referenced by: '<S81>/reset'
                                        */
  real_T reset_P6_g3;                  /* Expression: btype
                                        * Referenced by: '<S81>/reset'
                                        */
  real_T Integrator_IC_fy;             /* Expression: 0
                                        * Referenced by: '<S81>/Integrator'
                                        */
  real_T NaN_Value_l;                  /* Expression: 0
                                        * Referenced by: '<S79>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_f;/* Expression: 0
                                          * Referenced by: '<S56>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_n[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T Constant1_Value_a[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S57>/Constant1'
                                        */
  real_T Delay_InitialCondition_d;     /* Expression: 0
                                        * Referenced by: '<S57>/Delay'
                                        */
  real_T Delay_InitialCondition_h;     /* Expression: 0
                                        * Referenced by: '<S88>/Delay'
                                        */
  real_T Constant1_Value_g[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S88>/Constant1'
                                        */
  real_T Constant2_Value_h[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S88>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_a;/* Expression: 0
                                          * Referenced by: '<S88>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_m;                 /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S91>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim;/* Computed Parameter: Accelerationlimiter_RisingLim
                                        * Referenced by: '<S88>/Acceleration limiter'
                                        */
  real_T Accelerationlimiter_FallingLim;/* Computed Parameter: Accelerationlimiter_FallingLim
                                         * Referenced by: '<S88>/Acceleration limiter'
                                         */
  real_T Accelerationlimiter_IC;       /* Expression: 0
                                        * Referenced by: '<S88>/Acceleration limiter'
                                        */
  real_T Memory_X0_g;                  /* Expression: 1
                                        * Referenced by: '<S88>/Memory'
                                        */
  real_T reset_P1_f;                   /* Expression: width
                                        * Referenced by: '<S90>/reset'
                                        */
  real_T reset_P2_k;                   /* Expression: dtype
                                        * Referenced by: '<S90>/reset'
                                        */
  real_T reset_P3_d;                   /* Expression: portnum
                                        * Referenced by: '<S90>/reset'
                                        */
  real_T reset_P4_l;                   /* Expression: stime
                                        * Referenced by: '<S90>/reset'
                                        */
  real_T reset_P5_mc;                  /* Expression: stype
                                        * Referenced by: '<S90>/reset'
                                        */
  real_T reset_P6_f5;                  /* Expression: btype
                                        * Referenced by: '<S90>/reset'
                                        */
  real_T Integrator_IC_j;              /* Expression: 0
                                        * Referenced by: '<S90>/Integrator'
                                        */
  real_T NaN_Value_g;                  /* Expression: 0
                                        * Referenced by: '<S88>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_c;/* Expression: 0
                                          * Referenced by: '<S57>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_j4[2];         /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T Constant1_Value_oi[2];        /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S58>/Constant1'
                                        */
  real_T Delay_InitialCondition_fb;    /* Expression: 0
                                        * Referenced by: '<S58>/Delay'
                                        */
  real_T Delay_InitialCondition_g;     /* Expression: 0
                                        * Referenced by: '<S97>/Delay'
                                        */
  real_T Constant1_Value_m[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S97>/Constant1'
                                        */
  real_T Constant2_Value_l[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S97>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_a1;/* Expression: 0
                                          * Referenced by: '<S97>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_h;                 /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S100>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_e;/* Computed Parameter: Accelerationlimiter_RisingLim_e
                                          * Referenced by: '<S97>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_b;/* Computed Parameter: Accelerationlimiter_FallingLi_b
                                          * Referenced by: '<S97>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_h;     /* Expression: 0
                                        * Referenced by: '<S97>/Acceleration limiter'
                                        */
  real_T Memory_X0_k;                  /* Expression: 1
                                        * Referenced by: '<S97>/Memory'
                                        */
  real_T reset_P1_i;                   /* Expression: width
                                        * Referenced by: '<S99>/reset'
                                        */
  real_T reset_P2_g0;                  /* Expression: dtype
                                        * Referenced by: '<S99>/reset'
                                        */
  real_T reset_P3_eq;                  /* Expression: portnum
                                        * Referenced by: '<S99>/reset'
                                        */
  real_T reset_P4_p;                   /* Expression: stime
                                        * Referenced by: '<S99>/reset'
                                        */
  real_T reset_P5_f3;                  /* Expression: stype
                                        * Referenced by: '<S99>/reset'
                                        */
  real_T reset_P6_l2;                  /* Expression: btype
                                        * Referenced by: '<S99>/reset'
                                        */
  real_T Integrator_IC_g;              /* Expression: 0
                                        * Referenced by: '<S99>/Integrator'
                                        */
  real_T NaN_Value_p;                  /* Expression: 0
                                        * Referenced by: '<S97>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_p;/* Expression: 0
                                          * Referenced by: '<S58>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_i[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T Constant1_Value_h[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S59>/Constant1'
                                        */
  real_T Delay_InitialCondition_fv;    /* Expression: 0
                                        * Referenced by: '<S59>/Delay'
                                        */
  real_T Delay_InitialCondition_dz;    /* Expression: 0
                                        * Referenced by: '<S106>/Delay'
                                        */
  real_T Constant1_Value_mk[3];        /* Expression: hd.num{1,1}
                                        * Referenced by: '<S106>/Constant1'
                                        */
  real_T Constant2_Value_p[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S106>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_e;/* Expression: 0
                                          * Referenced by: '<S106>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_o;                 /* Computed Parameter: TSamp_WtEt_o
                                        * Referenced by: '<S109>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_b;/* Computed Parameter: Accelerationlimiter_RisingLim_b
                                          * Referenced by: '<S106>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_d;/* Computed Parameter: Accelerationlimiter_FallingLi_d
                                          * Referenced by: '<S106>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_i;     /* Expression: 0
                                        * Referenced by: '<S106>/Acceleration limiter'
                                        */
  real_T Memory_X0_k3;                 /* Expression: 1
                                        * Referenced by: '<S106>/Memory'
                                        */
  real_T reset_P1_md;                  /* Expression: width
                                        * Referenced by: '<S108>/reset'
                                        */
  real_T reset_P2_jk;                  /* Expression: dtype
                                        * Referenced by: '<S108>/reset'
                                        */
  real_T reset_P3_dp;                  /* Expression: portnum
                                        * Referenced by: '<S108>/reset'
                                        */
  real_T reset_P4_g;                   /* Expression: stime
                                        * Referenced by: '<S108>/reset'
                                        */
  real_T reset_P5_mg;                  /* Expression: stype
                                        * Referenced by: '<S108>/reset'
                                        */
  real_T reset_P6_g5;                  /* Expression: btype
                                        * Referenced by: '<S108>/reset'
                                        */
  real_T Integrator_IC_aj;             /* Expression: 0
                                        * Referenced by: '<S108>/Integrator'
                                        */
  real_T NaN_Value_lq;                 /* Expression: 0
                                        * Referenced by: '<S106>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialS_pj;/* Expression: 0
                                          * Referenced by: '<S59>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_ht[2];         /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S60>/Constant'
                                        */
  real_T Constant1_Value_gs[2];        /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S60>/Constant1'
                                        */
  real_T Delay_InitialCondition_fi;    /* Expression: 0
                                        * Referenced by: '<S60>/Delay'
                                        */
  real_T Delay_InitialCondition_a;     /* Expression: 0
                                        * Referenced by: '<S115>/Delay'
                                        */
  real_T Constant1_Value_oa[3];        /* Expression: hd.num{1,1}
                                        * Referenced by: '<S115>/Constant1'
                                        */
  real_T Constant2_Value_p3[3];        /* Expression: hd.den{1,1}
                                        * Referenced by: '<S115>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_a4;/* Expression: 0
                                          * Referenced by: '<S115>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_kk;                /* Computed Parameter: TSamp_WtEt_kk
                                        * Referenced by: '<S118>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLi_bi;/* Computed Parameter: Accelerationlimiter_RisingLi_bi
                                          * Referenced by: '<S115>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_p;/* Computed Parameter: Accelerationlimiter_FallingLi_p
                                          * Referenced by: '<S115>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_p;     /* Expression: 0
                                        * Referenced by: '<S115>/Acceleration limiter'
                                        */
  real_T Memory_X0_c;                  /* Expression: 1
                                        * Referenced by: '<S115>/Memory'
                                        */
  real_T reset_P1_kh;                  /* Expression: width
                                        * Referenced by: '<S117>/reset'
                                        */
  real_T reset_P2_hw;                  /* Expression: dtype
                                        * Referenced by: '<S117>/reset'
                                        */
  real_T reset_P3_fv;                  /* Expression: portnum
                                        * Referenced by: '<S117>/reset'
                                        */
  real_T reset_P4_a;                   /* Expression: stime
                                        * Referenced by: '<S117>/reset'
                                        */
  real_T reset_P5_e;                   /* Expression: stype
                                        * Referenced by: '<S117>/reset'
                                        */
  real_T reset_P6_a;                   /* Expression: btype
                                        * Referenced by: '<S117>/reset'
                                        */
  real_T Integrator_IC_h;              /* Expression: 0
                                        * Referenced by: '<S117>/Integrator'
                                        */
  real_T NaN_Value_j;                  /* Expression: 0
                                        * Referenced by: '<S115>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_b;/* Expression: 0
                                          * Referenced by: '<S60>/Discrete Transfer Fcn'
                                          */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S11>/Delay'
                                        */
  uint32_T Delay_DelayLength_d;        /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S55>/Delay'
                                        */
  uint32_T Delay_DelayLength_f;        /* Computed Parameter: Delay_DelayLength_f
                                        * Referenced by: '<S70>/Delay'
                                        */
  uint32_T Delay_DelayLength_m;        /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Delay_DelayLength_p;        /* Computed Parameter: Delay_DelayLength_p
                                        * Referenced by: '<S79>/Delay'
                                        */
  uint32_T Delay_DelayLength_h;        /* Computed Parameter: Delay_DelayLength_h
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Delay_DelayLength_b;        /* Computed Parameter: Delay_DelayLength_b
                                        * Referenced by: '<S88>/Delay'
                                        */
  uint32_T Delay_DelayLength_n;        /* Computed Parameter: Delay_DelayLength_n
                                        * Referenced by: '<S58>/Delay'
                                        */
  uint32_T Delay_DelayLength_mj;       /* Computed Parameter: Delay_DelayLength_mj
                                        * Referenced by: '<S97>/Delay'
                                        */
  uint32_T Delay_DelayLength_a;        /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S59>/Delay'
                                        */
  uint32_T Delay_DelayLength_k;        /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S106>/Delay'
                                        */
  uint32_T Delay_DelayLength_l;        /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S60>/Delay'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S115>/Delay'
                                        */
  P_CoreSubsys_ctrl_DP_T CoreSubsys;   /* '<S47>/CoreSubsys' */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_DP_T {
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
extern P_ctrl_DP_T ctrl_DP_P;

/* Block signals (auto storage) */
extern B_ctrl_DP_T ctrl_DP_B;

/* Continuous states (auto storage) */
extern X_ctrl_DP_T ctrl_DP_X;

/* Block states (auto storage) */
extern DW_ctrl_DP_T ctrl_DP_DW;

/* Model entry point functions */
extern void ctrl_DP_initialize(void);
extern void ctrl_DP_output(void);
extern void ctrl_DP_update(void);
extern void ctrl_DP_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_DP_rtModel *ctrl_DP(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_DP_T *const ctrl_DP_M;

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
 * '<Root>' : 'ctrl_DP'
 * '<S1>'   : 'ctrl_DP/Control'
 * '<S2>'   : 'ctrl_DP/Finding commanded forces in: [Surge,Sway,Yaw]'
 * '<S3>'   : 'ctrl_DP/Guidance'
 * '<S4>'   : 'ctrl_DP/Input1'
 * '<S5>'   : 'ctrl_DP/Nonlinear Passisve Observer'
 * '<S6>'   : 'ctrl_DP/Observer output '
 * '<S7>'   : 'ctrl_DP/Pos measurements'
 * '<S8>'   : 'ctrl_DP/Radians to Degrees'
 * '<S9>'   : 'ctrl_DP/Thrust allocation'
 * '<S10>'  : 'ctrl_DP/Thruster Parameters '
 * '<S11>'  : 'ctrl_DP/Thruster control '
 * '<S12>'  : 'ctrl_DP/Thruster measurment'
 * '<S13>'  : 'ctrl_DP/Control/DP Controller'
 * '<S14>'  : 'ctrl_DP/Control/DP Controller/Transposed rotation  matrix in yaw1'
 * '<S15>'  : 'ctrl_DP/Control/DP Controller/Transposed rotation  matrix in yaw2'
 * '<S16>'  : 'ctrl_DP/Control/DP Controller/[-inf inf] to [-pi pi]'
 * '<S17>'  : 'ctrl_DP/Control/DP Controller/[-inf inf] to [-pi pi]1'
 * '<S18>'  : 'ctrl_DP/Guidance/Reference model'
 * '<S19>'  : 'ctrl_DP/Guidance/Reference model/[-inf inf] to [-pi pi]1'
 * '<S20>'  : 'ctrl_DP/Guidance/Reference model/w_d*w_d'
 * '<S21>'  : 'ctrl_DP/Guidance/Reference model/w_d*w_d1'
 * '<S22>'  : 'ctrl_DP/Guidance/Reference model/w_d^-2'
 * '<S23>'  : 'ctrl_DP/Guidance/Reference model/w_d^3'
 * '<S24>'  : 'ctrl_DP/Input1/Control Gains'
 * '<S25>'  : 'ctrl_DP/Input1/Guidance gains'
 * '<S26>'  : 'ctrl_DP/Input1/Observer Gains'
 * '<S27>'  : 'ctrl_DP/Input1/Control Gains/MATLAB Function'
 * '<S28>'  : 'ctrl_DP/Input1/Control Gains/MATLAB Function1'
 * '<S29>'  : 'ctrl_DP/Input1/Control Gains/MATLAB Function2'
 * '<S30>'  : 'ctrl_DP/Input1/Guidance gains/MATLAB Function'
 * '<S31>'  : 'ctrl_DP/Input1/Guidance gains/MATLAB Function1'
 * '<S32>'  : 'ctrl_DP/Input1/Observer Gains/MATLAB Function'
 * '<S33>'  : 'ctrl_DP/Input1/Observer Gains/MATLAB Function1'
 * '<S34>'  : 'ctrl_DP/Input1/Observer Gains/MATLAB Function2'
 * '<S35>'  : 'ctrl_DP/Nonlinear Passisve Observer/C(nu)*nu'
 * '<S36>'  : 'ctrl_DP/Nonlinear Passisve Observer/D(nu)*nu'
 * '<S37>'  : 'ctrl_DP/Nonlinear Passisve Observer/Rotation matrix in yaw 1'
 * '<S38>'  : 'ctrl_DP/Nonlinear Passisve Observer/Transpose Rotation Matrix'
 * '<S39>'  : 'ctrl_DP/Nonlinear Passisve Observer/Transpose Rotation matrix'
 * '<S40>'  : 'ctrl_DP/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]'
 * '<S41>'  : 'ctrl_DP/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1'
 * '<S42>'  : 'ctrl_DP/Observer output /b_hat output'
 * '<S43>'  : 'ctrl_DP/Observer output /eta_hat output'
 * '<S44>'  : 'ctrl_DP/Observer output /nu_dot_hat output'
 * '<S45>'  : 'ctrl_DP/Observer output /nu_hat output'
 * '<S46>'  : 'ctrl_DP/Thrust allocation/MATLAB Function'
 * '<S47>'  : 'ctrl_DP/Thrust allocation/Optimal angle path and  constraints on rotation speed'
 * '<S48>'  : 'ctrl_DP/Thrust allocation/Radians to Degrees'
 * '<S49>'  : 'ctrl_DP/Thrust allocation/angle between  [-180 180]'
 * '<S50>'  : 'ctrl_DP/Thrust allocation/Optimal angle path and  constraints on rotation speed/Degrees to Radians'
 * '<S51>'  : 'ctrl_DP/Thrust allocation/Optimal angle path and  constraints on rotation speed/Ensuring angle is  [-pi pi]'
 * '<S52>'  : 'ctrl_DP/Thrust allocation/Optimal angle path and  constraints on rotation speed/MATLAB Function1'
 * '<S53>'  : 'ctrl_DP/Thruster control /Subsystem1'
 * '<S54>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM'
 * '<S55>'  : 'ctrl_DP/Thruster control /Thruster 1'
 * '<S56>'  : 'ctrl_DP/Thruster control /Thruster 2'
 * '<S57>'  : 'ctrl_DP/Thruster control /Thruster 3'
 * '<S58>'  : 'ctrl_DP/Thruster control /Thruster 4'
 * '<S59>'  : 'ctrl_DP/Thruster control /Thruster 5'
 * '<S60>'  : 'ctrl_DP/Thruster control /Thruster 6'
 * '<S61>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function'
 * '<S62>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function1'
 * '<S63>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function2'
 * '<S64>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function3'
 * '<S65>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function4'
 * '<S66>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function5'
 * '<S67>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function6'
 * '<S68>'  : 'ctrl_DP/Thruster control /Thruster 1/Propeller Hydrodynamics'
 * '<S69>'  : 'ctrl_DP/Thruster control /Thruster 1/Shaft dynamics'
 * '<S70>'  : 'ctrl_DP/Thruster control /Thruster 1/Thruster control'
 * '<S71>'  : 'ctrl_DP/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S72>'  : 'ctrl_DP/Thruster control /Thruster 1/Thruster control/Core controller'
 * '<S73>'  : 'ctrl_DP/Thruster control /Thruster 1/Thruster control/Discrete Derivative'
 * '<S74>'  : 'ctrl_DP/Thruster control /Thruster 1/Thruster control/MATLAB Function'
 * '<S75>'  : 'ctrl_DP/Thruster control /Thruster 1/Thruster control/Supervisor'
 * '<S76>'  : 'ctrl_DP/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S77>'  : 'ctrl_DP/Thruster control /Thruster 2/Propeller Hydrodynamics'
 * '<S78>'  : 'ctrl_DP/Thruster control /Thruster 2/Shaft dynamics'
 * '<S79>'  : 'ctrl_DP/Thruster control /Thruster 2/Thruster control'
 * '<S80>'  : 'ctrl_DP/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S81>'  : 'ctrl_DP/Thruster control /Thruster 2/Thruster control/Core controller'
 * '<S82>'  : 'ctrl_DP/Thruster control /Thruster 2/Thruster control/Discrete Derivative'
 * '<S83>'  : 'ctrl_DP/Thruster control /Thruster 2/Thruster control/MATLAB Function'
 * '<S84>'  : 'ctrl_DP/Thruster control /Thruster 2/Thruster control/Supervisor'
 * '<S85>'  : 'ctrl_DP/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S86>'  : 'ctrl_DP/Thruster control /Thruster 3/Propeller Hydrodynamics'
 * '<S87>'  : 'ctrl_DP/Thruster control /Thruster 3/Shaft dynamics'
 * '<S88>'  : 'ctrl_DP/Thruster control /Thruster 3/Thruster control'
 * '<S89>'  : 'ctrl_DP/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S90>'  : 'ctrl_DP/Thruster control /Thruster 3/Thruster control/Core controller'
 * '<S91>'  : 'ctrl_DP/Thruster control /Thruster 3/Thruster control/Discrete Derivative'
 * '<S92>'  : 'ctrl_DP/Thruster control /Thruster 3/Thruster control/MATLAB Function'
 * '<S93>'  : 'ctrl_DP/Thruster control /Thruster 3/Thruster control/Supervisor'
 * '<S94>'  : 'ctrl_DP/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S95>'  : 'ctrl_DP/Thruster control /Thruster 4/Propeller Hydrodynamics'
 * '<S96>'  : 'ctrl_DP/Thruster control /Thruster 4/Shaft dynamics'
 * '<S97>'  : 'ctrl_DP/Thruster control /Thruster 4/Thruster control'
 * '<S98>'  : 'ctrl_DP/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S99>'  : 'ctrl_DP/Thruster control /Thruster 4/Thruster control/Core controller'
 * '<S100>' : 'ctrl_DP/Thruster control /Thruster 4/Thruster control/Discrete Derivative'
 * '<S101>' : 'ctrl_DP/Thruster control /Thruster 4/Thruster control/MATLAB Function'
 * '<S102>' : 'ctrl_DP/Thruster control /Thruster 4/Thruster control/Supervisor'
 * '<S103>' : 'ctrl_DP/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S104>' : 'ctrl_DP/Thruster control /Thruster 5/Propeller Hydrodynamics'
 * '<S105>' : 'ctrl_DP/Thruster control /Thruster 5/Shaft dynamics'
 * '<S106>' : 'ctrl_DP/Thruster control /Thruster 5/Thruster control'
 * '<S107>' : 'ctrl_DP/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S108>' : 'ctrl_DP/Thruster control /Thruster 5/Thruster control/Core controller'
 * '<S109>' : 'ctrl_DP/Thruster control /Thruster 5/Thruster control/Discrete Derivative'
 * '<S110>' : 'ctrl_DP/Thruster control /Thruster 5/Thruster control/MATLAB Function'
 * '<S111>' : 'ctrl_DP/Thruster control /Thruster 5/Thruster control/Supervisor'
 * '<S112>' : 'ctrl_DP/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S113>' : 'ctrl_DP/Thruster control /Thruster 6/Propeller Hydrodynamics'
 * '<S114>' : 'ctrl_DP/Thruster control /Thruster 6/Shaft dynamics'
 * '<S115>' : 'ctrl_DP/Thruster control /Thruster 6/Thruster control'
 * '<S116>' : 'ctrl_DP/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S117>' : 'ctrl_DP/Thruster control /Thruster 6/Thruster control/Core controller'
 * '<S118>' : 'ctrl_DP/Thruster control /Thruster 6/Thruster control/Discrete Derivative'
 * '<S119>' : 'ctrl_DP/Thruster control /Thruster 6/Thruster control/MATLAB Function'
 * '<S120>' : 'ctrl_DP/Thruster control /Thruster 6/Thruster control/Supervisor'
 * '<S121>' : 'ctrl_DP/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 */
#endif                                 /* RTW_HEADER_ctrl_DP_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_DP
 * Model version : 1.201
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Tue Jul 11 19:56:08 2017
 *========================================================================*/
#if !defined(NI_HEADER_ctrl_DP_h_)
#define NI_HEADER_ctrl_DP_h_
#ifdef NI_ROOTMODEL_ctrl_DP

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* ctrl_DP.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_ctrl_DP_T rtParameter[NUMST+!TID01EQ];
P_ctrl_DP_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_ctrl_DP_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_ctrl_DP_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_ctrl_DP_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
#endif                                 /* NI_HEADER_ctrl_DP_h_ */
