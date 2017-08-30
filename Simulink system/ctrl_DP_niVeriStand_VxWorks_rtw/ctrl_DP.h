/*
 * ctrl_DP.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_DP".
 *
 * Model version              : 1.207
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Aug 23 17:03:42 2017
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
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

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

/* Block signals for system '<S38>/MATLAB Function' */
typedef struct {
  real_T y[9];                         /* '<S38>/MATLAB Function' */
} B_MATLABFunction_ctrl_DP_T;

/* Block signals (auto storage) */
typedef struct {
  real_T reset;                        /* '<S6>/reset' */
  real_T K_p_x;                        /* '<S38>/K_p_x' */
  real_T K_p_y;                        /* '<S38>/K_p_y' */
  real_T K_p_psi;                      /* '<S38>/K_p_psi' */
  real_T K_i_psi;                      /* '<S38>/K_i_psi' */
  real_T K_i_x;                        /* '<S38>/K_i_x' */
  real_T K_i_y;                        /* '<S38>/K_i_y' */
  real_T K_d_psi;                      /* '<S38>/K_d_psi' */
  real_T K_d_x;                        /* '<S38>/K_d_x' */
  real_T K_d_y;                        /* '<S38>/K_d_y' */
  real_T w_d_x;                        /* '<S39>/w_d_x' */
  real_T w_d_y;                        /* '<S39>/w_d_y' */
  real_T w_d_psi;                      /* '<S39>/w_d_psi' */
  real_T zeta_psi;                     /* '<S39>/zeta_psi' */
  real_T zeta_x;                       /* '<S39>/zeta_x' */
  real_T zeta_y;                       /* '<S39>/zeta_y' */
  real_T psi_refdeg;                   /* '<S6>/psi_ref [deg]' */
  real_T x_ref;                        /* '<S6>/x_ref' */
  real_T y_ref;                        /* '<S6>/y_ref' */
  real_T x_m;                          /* '<S15>/x_m' */
  real_T mm2m;                         /* '<S15>/mm2m' */
  real_T y_m;                          /* '<S15>/y_m' */
  real_T Gain1;                        /* '<S15>/Gain1' */
  real_T u80180deg;                    /* '<S15>/psi_m' */
  real_T Sum;                          /* '<S15>/Sum' */
  real_T Integrator[3];                /* '<S4>/Integrator' */
  real_T Sum_e;                        /* '<S32>/Sum' */
  real_T Integrator1[3];               /* '<S4>/Integrator1' */
  real_T Integrator2[3];               /* '<S4>/Integrator2' */
  real_T Integrator1_h[3];             /* '<S21>/Integrator1' */
  real_T Sum_a;                        /* '<S22>/Sum' */
  real_T Sum2[3];                      /* '<S1>/Sum2' */
  real_T TmpSignalConversionAtMatrixMult[3];/* '<S1>/Transposed rotation  matrix in yaw1' */
  real_T Integrator3[3];               /* '<S21>/Integrator3' */
  real_T M1[3];                        /* '<S4>/M^-1' */
  real_T Memory4[6];                   /* '<S8>/Memory4' */
  real_T MatrixMultiply[3];            /* '<S21>/Matrix Multiply' */
  real_T Sum5[3];                      /* '<S21>/Sum5' */
  real_T MatrixMultiply1[3];           /* '<S4>/Matrix Multiply1' */
  real_T Sum1[3];                      /* '<S4>/Sum1' */
  real_T u[6];                         /* '<S11>/MATLAB Function11' */
  real_T alpha_infinf[6];              /* '<S8>/MATLAB Function11' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction2;/* '<S40>/MATLAB Function2' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction1_k;/* '<S40>/MATLAB Function1' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction_p;/* '<S40>/MATLAB Function' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction1_c;/* '<S39>/MATLAB Function1' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction_d;/* '<S39>/MATLAB Function' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction2_c;/* '<S38>/MATLAB Function2' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction1;/* '<S38>/MATLAB Function1' */
  B_MATLABFunction_ctrl_DP_T sf_MATLABFunction;/* '<S38>/MATLAB Function' */
} B_ctrl_DP_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T reset_DWORK1;                 /* '<S6>/reset' */
  real_T K_p_x_DWORK1;                 /* '<S38>/K_p_x' */
  real_T K_p_y_DWORK1;                 /* '<S38>/K_p_y' */
  real_T K_p_psi_DWORK1;               /* '<S38>/K_p_psi' */
  real_T K_i_psi_DWORK1;               /* '<S38>/K_i_psi' */
  real_T K_i_x_DWORK1;                 /* '<S38>/K_i_x' */
  real_T K_i_y_DWORK1;                 /* '<S38>/K_i_y' */
  real_T K_d_psi_DWORK1;               /* '<S38>/K_d_psi' */
  real_T K_d_x_DWORK1;                 /* '<S38>/K_d_x' */
  real_T K_d_y_DWORK1;                 /* '<S38>/K_d_y' */
  real_T w_d_x_DWORK1;                 /* '<S39>/w_d_x' */
  real_T w_d_y_DWORK1;                 /* '<S39>/w_d_y' */
  real_T w_d_psi_DWORK1;               /* '<S39>/w_d_psi' */
  real_T zeta_psi_DWORK1;              /* '<S39>/zeta_psi' */
  real_T zeta_x_DWORK1;                /* '<S39>/zeta_x' */
  real_T zeta_y_DWORK1;                /* '<S39>/zeta_y' */
  real_T psi_refdeg_DWORK1;            /* '<S6>/psi_ref [deg]' */
  real_T x_ref_DWORK1;                 /* '<S6>/x_ref' */
  real_T y_ref_DWORK1;                 /* '<S6>/y_ref' */
  real_T x_m_DWORK1;                   /* '<S15>/x_m' */
  real_T y_m_DWORK1;                   /* '<S15>/y_m' */
  real_T psi_m_DWORK1;                 /* '<S15>/psi_m' */
  real_T x_hat_DWORK1;                 /* '<S35>/x_hat' */
  real_T y_hat_DWORK1;                 /* '<S35>/y_hat' */
  real_T psi_hat_DWORK1;               /* '<S35>/psi_hat' */
  real_T u_hat_DWORK1;                 /* '<S37>/u_hat' */
  real_T v_hat_DWORK1;                 /* '<S37>/v_hat' */
  real_T r_hat_DWORK1;                 /* '<S37>/r_hat' */
  real_T u_dot_hat_DWORK1;             /* '<S36>/u_dot_hat' */
  real_T v_dot_hat_DWORK1;             /* '<S36>/v_dot_hat' */
  real_T r_dot_hat_DWORK1;             /* '<S36>/r_dot_hat' */
  real_T b_x_hat_DWORK1;               /* '<S34>/b_x_hat' */
  real_T b_y_hat_DWORK1;               /* '<S34>/b_y_hat' */
  real_T b_psi_hat_DWORK1;             /* '<S34>/b_psi_hat' */
  real_T Memory4_PreviousInput[6];     /* '<S8>/Memory4' */
  real_T alpha1_DWORK1;                /* '<S7>/alpha1' */
  real_T alpha2_DWORK1;                /* '<S7>/alpha2' */
  real_T alpha3_DWORK1;                /* '<S7>/alpha3' */
  real_T alpha4_DWORK1;                /* '<S7>/alpha4' */
  real_T alpha5_DWORK1;                /* '<S7>/alpha5' */
  real_T alpha6_DWORK1;                /* '<S7>/alpha6' */
  real_T u1_DWORK1;                    /* '<S7>/u1' */
  real_T u2_DWORK1;                    /* '<S7>/u2' */
  real_T u3_DWORK1;                    /* '<S7>/u3' */
  real_T u4_DWORK1;                    /* '<S7>/u4' */
  real_T u5_DWORK1;                    /* '<S7>/u5' */
  real_T u6_DWORK1;                    /* '<S7>/u6' */
  real_T x_tilde_DWORK1;               /* '<S20>/x_tilde' */
  real_T y_tilde_DWORK1;               /* '<S20>/y_tilde' */
  real_T psi_tilde_DWORK1;             /* '<S20>/psi_tilde' */
  real_T x_ref_out_DWORK1;             /* '<S3>/x_ref_out' */
  real_T y_ref_out_DWORK1;             /* '<S3>/y_ref_out' */
  real_T psi_ref_out_DWORK1;           /* '<S3>/psi_ref_out' */
  int_T Integrator_IWORK;              /* '<S4>/Integrator' */
  int_T Integrator1_IWORK;             /* '<S21>/Integrator1' */
  uint8_T reset_DWORK2[8];             /* '<S6>/reset' */
  uint8_T K_p_x_DWORK2[8];             /* '<S38>/K_p_x' */
  uint8_T K_p_y_DWORK2[8];             /* '<S38>/K_p_y' */
  uint8_T K_p_psi_DWORK2[8];           /* '<S38>/K_p_psi' */
  uint8_T K_i_psi_DWORK2[8];           /* '<S38>/K_i_psi' */
  uint8_T K_i_x_DWORK2[8];             /* '<S38>/K_i_x' */
  uint8_T K_i_y_DWORK2[8];             /* '<S38>/K_i_y' */
  uint8_T K_d_psi_DWORK2[8];           /* '<S38>/K_d_psi' */
  uint8_T K_d_x_DWORK2[8];             /* '<S38>/K_d_x' */
  uint8_T K_d_y_DWORK2[8];             /* '<S38>/K_d_y' */
  uint8_T w_d_x_DWORK2[8];             /* '<S39>/w_d_x' */
  uint8_T w_d_y_DWORK2[8];             /* '<S39>/w_d_y' */
  uint8_T w_d_psi_DWORK2[8];           /* '<S39>/w_d_psi' */
  uint8_T zeta_psi_DWORK2[8];          /* '<S39>/zeta_psi' */
  uint8_T zeta_x_DWORK2[8];            /* '<S39>/zeta_x' */
  uint8_T zeta_y_DWORK2[8];            /* '<S39>/zeta_y' */
  uint8_T psi_refdeg_DWORK2[8];        /* '<S6>/psi_ref [deg]' */
  uint8_T x_ref_DWORK2[8];             /* '<S6>/x_ref' */
  uint8_T y_ref_DWORK2[8];             /* '<S6>/y_ref' */
  uint8_T x_m_DWORK2[8];               /* '<S15>/x_m' */
  uint8_T y_m_DWORK2[8];               /* '<S15>/y_m' */
  uint8_T psi_m_DWORK2[8];             /* '<S15>/psi_m' */
  uint8_T x_hat_DWORK2[8];             /* '<S35>/x_hat' */
  uint8_T y_hat_DWORK2[8];             /* '<S35>/y_hat' */
  uint8_T psi_hat_DWORK2[8];           /* '<S35>/psi_hat' */
  uint8_T u_hat_DWORK2[8];             /* '<S37>/u_hat' */
  uint8_T v_hat_DWORK2[8];             /* '<S37>/v_hat' */
  uint8_T r_hat_DWORK2[8];             /* '<S37>/r_hat' */
  uint8_T u_dot_hat_DWORK2[8];         /* '<S36>/u_dot_hat' */
  uint8_T v_dot_hat_DWORK2[8];         /* '<S36>/v_dot_hat' */
  uint8_T r_dot_hat_DWORK2[8];         /* '<S36>/r_dot_hat' */
  uint8_T b_x_hat_DWORK2[8];           /* '<S34>/b_x_hat' */
  uint8_T b_y_hat_DWORK2[8];           /* '<S34>/b_y_hat' */
  uint8_T b_psi_hat_DWORK2[8];         /* '<S34>/b_psi_hat' */
  uint8_T alpha1_DWORK2[8];            /* '<S7>/alpha1' */
  uint8_T alpha2_DWORK2[8];            /* '<S7>/alpha2' */
  uint8_T alpha3_DWORK2[8];            /* '<S7>/alpha3' */
  uint8_T alpha4_DWORK2[8];            /* '<S7>/alpha4' */
  uint8_T alpha5_DWORK2[8];            /* '<S7>/alpha5' */
  uint8_T alpha6_DWORK2[8];            /* '<S7>/alpha6' */
  uint8_T u1_DWORK2[8];                /* '<S7>/u1' */
  uint8_T u2_DWORK2[8];                /* '<S7>/u2' */
  uint8_T u3_DWORK2[8];                /* '<S7>/u3' */
  uint8_T u4_DWORK2[8];                /* '<S7>/u4' */
  uint8_T u5_DWORK2[8];                /* '<S7>/u5' */
  uint8_T u6_DWORK2[8];                /* '<S7>/u6' */
  uint8_T x_tilde_DWORK2[8];           /* '<S20>/x_tilde' */
  uint8_T y_tilde_DWORK2[8];           /* '<S20>/y_tilde' */
  uint8_T psi_tilde_DWORK2[8];         /* '<S20>/psi_tilde' */
  uint8_T x_ref_out_DWORK2[8];         /* '<S3>/x_ref_out' */
  uint8_T y_ref_out_DWORK2[8];         /* '<S3>/y_ref_out' */
  uint8_T psi_ref_out_DWORK2[8];       /* '<S3>/psi_ref_out' */
} DW_ctrl_DP_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S4>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S4>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S4>/Integrator2' */
  real_T Integrator1_CSTATE_g[3];      /* '<S21>/Integrator1' */
  real_T Integrator_CSTATE_f[3];       /* '<S1>/Integrator' */
  real_T Integrator3_CSTATE[3];        /* '<S21>/Integrator3' */
  real_T Integrator2_CSTATE_c[3];      /* '<S21>/Integrator2' */
} X_ctrl_DP_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S4>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S4>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S4>/Integrator2' */
  real_T Integrator1_CSTATE_g[3];      /* '<S21>/Integrator1' */
  real_T Integrator_CSTATE_f[3];       /* '<S1>/Integrator' */
  real_T Integrator3_CSTATE[3];        /* '<S21>/Integrator3' */
  real_T Integrator2_CSTATE_c[3];      /* '<S21>/Integrator2' */
} XDot_ctrl_DP_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[3];      /* '<S4>/Integrator' */
  boolean_T Integrator1_CSTATE[3];     /* '<S4>/Integrator1' */
  boolean_T Integrator2_CSTATE[3];     /* '<S4>/Integrator2' */
  boolean_T Integrator1_CSTATE_g[3];   /* '<S21>/Integrator1' */
  boolean_T Integrator_CSTATE_f[3];    /* '<S1>/Integrator' */
  boolean_T Integrator3_CSTATE[3];     /* '<S21>/Integrator3' */
  boolean_T Integrator2_CSTATE_c[3];   /* '<S21>/Integrator2' */
} XDis_ctrl_DP_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S4>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE;    /* '<S4>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE;    /* '<S4>/Integrator2' */
  ZCSigState Integrator1_Reset_ZCE_j;  /* '<S21>/Integrator1' */
  ZCSigState Integrator_Reset_ZCE_m;   /* '<S1>/Integrator' */
  ZCSigState Integrator3_Reset_ZCE;    /* '<S21>/Integrator3' */
  ZCSigState Integrator2_Reset_ZCE_h;  /* '<S21>/Integrator2' */
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

/* Parameters (auto storage) */
struct P_ctrl_DP_T_ {
  real_T T_pinv[36];                   /* Variable: T_pinv
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T reset_P1;                     /* Expression: width
                                        * Referenced by: '<S6>/reset'
                                        */
  real_T reset_P2;                     /* Expression: dtype
                                        * Referenced by: '<S6>/reset'
                                        */
  real_T reset_P3;                     /* Expression: portnum
                                        * Referenced by: '<S6>/reset'
                                        */
  real_T reset_P4;                     /* Expression: stime
                                        * Referenced by: '<S6>/reset'
                                        */
  real_T reset_P5;                     /* Expression: stype
                                        * Referenced by: '<S6>/reset'
                                        */
  real_T reset_P6;                     /* Expression: btype
                                        * Referenced by: '<S6>/reset'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<S40>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S40>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S40>/Constant8'
                                        */
  real_T K_p_x_P1;                     /* Expression: width
                                        * Referenced by: '<S38>/K_p_x'
                                        */
  real_T K_p_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S38>/K_p_x'
                                        */
  real_T K_p_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S38>/K_p_x'
                                        */
  real_T K_p_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S38>/K_p_x'
                                        */
  real_T K_p_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S38>/K_p_x'
                                        */
  real_T K_p_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S38>/K_p_x'
                                        */
  real_T K_p_y_P1;                     /* Expression: width
                                        * Referenced by: '<S38>/K_p_y'
                                        */
  real_T K_p_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S38>/K_p_y'
                                        */
  real_T K_p_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S38>/K_p_y'
                                        */
  real_T K_p_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S38>/K_p_y'
                                        */
  real_T K_p_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S38>/K_p_y'
                                        */
  real_T K_p_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S38>/K_p_y'
                                        */
  real_T K_p_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S38>/K_p_psi'
                                        */
  real_T K_p_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S38>/K_p_psi'
                                        */
  real_T K_p_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S38>/K_p_psi'
                                        */
  real_T K_p_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S38>/K_p_psi'
                                        */
  real_T K_p_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S38>/K_p_psi'
                                        */
  real_T K_p_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S38>/K_p_psi'
                                        */
  real_T K_i_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S38>/K_i_psi'
                                        */
  real_T K_i_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S38>/K_i_psi'
                                        */
  real_T K_i_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S38>/K_i_psi'
                                        */
  real_T K_i_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S38>/K_i_psi'
                                        */
  real_T K_i_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S38>/K_i_psi'
                                        */
  real_T K_i_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S38>/K_i_psi'
                                        */
  real_T K_i_x_P1;                     /* Expression: width
                                        * Referenced by: '<S38>/K_i_x'
                                        */
  real_T K_i_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S38>/K_i_x'
                                        */
  real_T K_i_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S38>/K_i_x'
                                        */
  real_T K_i_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S38>/K_i_x'
                                        */
  real_T K_i_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S38>/K_i_x'
                                        */
  real_T K_i_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S38>/K_i_x'
                                        */
  real_T K_i_y_P1;                     /* Expression: width
                                        * Referenced by: '<S38>/K_i_y'
                                        */
  real_T K_i_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S38>/K_i_y'
                                        */
  real_T K_i_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S38>/K_i_y'
                                        */
  real_T K_i_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S38>/K_i_y'
                                        */
  real_T K_i_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S38>/K_i_y'
                                        */
  real_T K_i_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S38>/K_i_y'
                                        */
  real_T K_d_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S38>/K_d_psi'
                                        */
  real_T K_d_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S38>/K_d_psi'
                                        */
  real_T K_d_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S38>/K_d_psi'
                                        */
  real_T K_d_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S38>/K_d_psi'
                                        */
  real_T K_d_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S38>/K_d_psi'
                                        */
  real_T K_d_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S38>/K_d_psi'
                                        */
  real_T K_d_x_P1;                     /* Expression: width
                                        * Referenced by: '<S38>/K_d_x'
                                        */
  real_T K_d_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S38>/K_d_x'
                                        */
  real_T K_d_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S38>/K_d_x'
                                        */
  real_T K_d_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S38>/K_d_x'
                                        */
  real_T K_d_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S38>/K_d_x'
                                        */
  real_T K_d_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S38>/K_d_x'
                                        */
  real_T K_d_y_P1;                     /* Expression: width
                                        * Referenced by: '<S38>/K_d_y'
                                        */
  real_T K_d_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S38>/K_d_y'
                                        */
  real_T K_d_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S38>/K_d_y'
                                        */
  real_T K_d_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S38>/K_d_y'
                                        */
  real_T K_d_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S38>/K_d_y'
                                        */
  real_T K_d_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S38>/K_d_y'
                                        */
  real_T w_d_x_P1;                     /* Expression: width
                                        * Referenced by: '<S39>/w_d_x'
                                        */
  real_T w_d_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S39>/w_d_x'
                                        */
  real_T w_d_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S39>/w_d_x'
                                        */
  real_T w_d_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S39>/w_d_x'
                                        */
  real_T w_d_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S39>/w_d_x'
                                        */
  real_T w_d_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S39>/w_d_x'
                                        */
  real_T w_d_y_P1;                     /* Expression: width
                                        * Referenced by: '<S39>/w_d_y'
                                        */
  real_T w_d_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S39>/w_d_y'
                                        */
  real_T w_d_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S39>/w_d_y'
                                        */
  real_T w_d_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S39>/w_d_y'
                                        */
  real_T w_d_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S39>/w_d_y'
                                        */
  real_T w_d_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S39>/w_d_y'
                                        */
  real_T w_d_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S39>/w_d_psi'
                                        */
  real_T w_d_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S39>/w_d_psi'
                                        */
  real_T w_d_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S39>/w_d_psi'
                                        */
  real_T w_d_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S39>/w_d_psi'
                                        */
  real_T w_d_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S39>/w_d_psi'
                                        */
  real_T w_d_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S39>/w_d_psi'
                                        */
  real_T zeta_psi_P1;                  /* Expression: width
                                        * Referenced by: '<S39>/zeta_psi'
                                        */
  real_T zeta_psi_P2;                  /* Expression: dtype
                                        * Referenced by: '<S39>/zeta_psi'
                                        */
  real_T zeta_psi_P3;                  /* Expression: portnum
                                        * Referenced by: '<S39>/zeta_psi'
                                        */
  real_T zeta_psi_P4;                  /* Expression: stime
                                        * Referenced by: '<S39>/zeta_psi'
                                        */
  real_T zeta_psi_P5;                  /* Expression: stype
                                        * Referenced by: '<S39>/zeta_psi'
                                        */
  real_T zeta_psi_P6;                  /* Expression: btype
                                        * Referenced by: '<S39>/zeta_psi'
                                        */
  real_T zeta_x_P1;                    /* Expression: width
                                        * Referenced by: '<S39>/zeta_x'
                                        */
  real_T zeta_x_P2;                    /* Expression: dtype
                                        * Referenced by: '<S39>/zeta_x'
                                        */
  real_T zeta_x_P3;                    /* Expression: portnum
                                        * Referenced by: '<S39>/zeta_x'
                                        */
  real_T zeta_x_P4;                    /* Expression: stime
                                        * Referenced by: '<S39>/zeta_x'
                                        */
  real_T zeta_x_P5;                    /* Expression: stype
                                        * Referenced by: '<S39>/zeta_x'
                                        */
  real_T zeta_x_P6;                    /* Expression: btype
                                        * Referenced by: '<S39>/zeta_x'
                                        */
  real_T zeta_y_P1;                    /* Expression: width
                                        * Referenced by: '<S39>/zeta_y'
                                        */
  real_T zeta_y_P2;                    /* Expression: dtype
                                        * Referenced by: '<S39>/zeta_y'
                                        */
  real_T zeta_y_P3;                    /* Expression: portnum
                                        * Referenced by: '<S39>/zeta_y'
                                        */
  real_T zeta_y_P4;                    /* Expression: stime
                                        * Referenced by: '<S39>/zeta_y'
                                        */
  real_T zeta_y_P5;                    /* Expression: stype
                                        * Referenced by: '<S39>/zeta_y'
                                        */
  real_T zeta_y_P6;                    /* Expression: btype
                                        * Referenced by: '<S39>/zeta_y'
                                        */
  real_T psi_refdeg_P1;                /* Expression: width
                                        * Referenced by: '<S6>/psi_ref [deg]'
                                        */
  real_T psi_refdeg_P2;                /* Expression: dtype
                                        * Referenced by: '<S6>/psi_ref [deg]'
                                        */
  real_T psi_refdeg_P3;                /* Expression: portnum
                                        * Referenced by: '<S6>/psi_ref [deg]'
                                        */
  real_T psi_refdeg_P4;                /* Expression: stime
                                        * Referenced by: '<S6>/psi_ref [deg]'
                                        */
  real_T psi_refdeg_P5;                /* Expression: stype
                                        * Referenced by: '<S6>/psi_ref [deg]'
                                        */
  real_T psi_refdeg_P6;                /* Expression: btype
                                        * Referenced by: '<S6>/psi_ref [deg]'
                                        */
  real_T x_ref_P1;                     /* Expression: width
                                        * Referenced by: '<S6>/x_ref'
                                        */
  real_T x_ref_P2;                     /* Expression: dtype
                                        * Referenced by: '<S6>/x_ref'
                                        */
  real_T x_ref_P3;                     /* Expression: portnum
                                        * Referenced by: '<S6>/x_ref'
                                        */
  real_T x_ref_P4;                     /* Expression: stime
                                        * Referenced by: '<S6>/x_ref'
                                        */
  real_T x_ref_P5;                     /* Expression: stype
                                        * Referenced by: '<S6>/x_ref'
                                        */
  real_T x_ref_P6;                     /* Expression: btype
                                        * Referenced by: '<S6>/x_ref'
                                        */
  real_T y_ref_P1;                     /* Expression: width
                                        * Referenced by: '<S6>/y_ref'
                                        */
  real_T y_ref_P2;                     /* Expression: dtype
                                        * Referenced by: '<S6>/y_ref'
                                        */
  real_T y_ref_P3;                     /* Expression: portnum
                                        * Referenced by: '<S6>/y_ref'
                                        */
  real_T y_ref_P4;                     /* Expression: stime
                                        * Referenced by: '<S6>/y_ref'
                                        */
  real_T y_ref_P5;                     /* Expression: stype
                                        * Referenced by: '<S6>/y_ref'
                                        */
  real_T y_ref_P6;                     /* Expression: btype
                                        * Referenced by: '<S6>/y_ref'
                                        */
  real_T x_m_P1;                       /* Expression: width
                                        * Referenced by: '<S15>/x_m'
                                        */
  real_T x_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S15>/x_m'
                                        */
  real_T x_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S15>/x_m'
                                        */
  real_T x_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S15>/x_m'
                                        */
  real_T x_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S15>/x_m'
                                        */
  real_T x_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S15>/x_m'
                                        */
  real_T mm2m_Gain;                    /* Expression: 1/1000
                                        * Referenced by: '<S15>/mm2m'
                                        */
  real_T y_m_P1;                       /* Expression: width
                                        * Referenced by: '<S15>/y_m'
                                        */
  real_T y_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S15>/y_m'
                                        */
  real_T y_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S15>/y_m'
                                        */
  real_T y_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S15>/y_m'
                                        */
  real_T y_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S15>/y_m'
                                        */
  real_T y_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S15>/y_m'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/1000
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T psi_m_P1;                     /* Expression: width
                                        * Referenced by: '<S15>/psi_m'
                                        */
  real_T psi_m_P2;                     /* Expression: dtype
                                        * Referenced by: '<S15>/psi_m'
                                        */
  real_T psi_m_P3;                     /* Expression: portnum
                                        * Referenced by: '<S15>/psi_m'
                                        */
  real_T psi_m_P4;                     /* Expression: stime
                                        * Referenced by: '<S15>/psi_m'
                                        */
  real_T psi_m_P5;                     /* Expression: stype
                                        * Referenced by: '<S15>/psi_m'
                                        */
  real_T psi_m_P6;                     /* Expression: btype
                                        * Referenced by: '<S15>/psi_m'
                                        */
  real_T deg2rad_Gain;                 /* Expression: pi/180
                                        * Referenced by: '<S15>/deg2rad'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1e10
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1e10
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Gain6_Gain;                   /* Expression: pi
                                        * Referenced by: '<S15>/Gain6'
                                        */
  real_T Constant1_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T x_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S35>/x_hat'
                                        */
  real_T x_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S35>/x_hat'
                                        */
  real_T x_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S35>/x_hat'
                                        */
  real_T x_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S35>/x_hat'
                                        */
  real_T x_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S35>/x_hat'
                                        */
  real_T x_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S35>/x_hat'
                                        */
  real_T y_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S35>/y_hat'
                                        */
  real_T y_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S35>/y_hat'
                                        */
  real_T y_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S35>/y_hat'
                                        */
  real_T y_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S35>/y_hat'
                                        */
  real_T y_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S35>/y_hat'
                                        */
  real_T y_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S35>/y_hat'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 1e10
                                        * Referenced by: '<S32>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -1e10
                                        * Referenced by: '<S32>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: pi
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T psi_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S35>/psi_hat'
                                        */
  real_T psi_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S35>/psi_hat'
                                        */
  real_T psi_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S35>/psi_hat'
                                        */
  real_T psi_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S35>/psi_hat'
                                        */
  real_T psi_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S35>/psi_hat'
                                        */
  real_T psi_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S35>/psi_hat'
                                        */
  real_T Integrator1_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T u_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S37>/u_hat'
                                        */
  real_T u_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S37>/u_hat'
                                        */
  real_T u_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S37>/u_hat'
                                        */
  real_T u_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S37>/u_hat'
                                        */
  real_T u_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S37>/u_hat'
                                        */
  real_T u_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S37>/u_hat'
                                        */
  real_T v_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S37>/v_hat'
                                        */
  real_T v_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S37>/v_hat'
                                        */
  real_T v_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S37>/v_hat'
                                        */
  real_T v_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S37>/v_hat'
                                        */
  real_T v_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S37>/v_hat'
                                        */
  real_T v_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S37>/v_hat'
                                        */
  real_T r_hat_P1;                     /* Expression: width
                                        * Referenced by: '<S37>/r_hat'
                                        */
  real_T r_hat_P2;                     /* Expression: dtype
                                        * Referenced by: '<S37>/r_hat'
                                        */
  real_T r_hat_P3;                     /* Expression: portnum
                                        * Referenced by: '<S37>/r_hat'
                                        */
  real_T r_hat_P4;                     /* Expression: stime
                                        * Referenced by: '<S37>/r_hat'
                                        */
  real_T r_hat_P5;                     /* Expression: stype
                                        * Referenced by: '<S37>/r_hat'
                                        */
  real_T r_hat_P6;                     /* Expression: btype
                                        * Referenced by: '<S37>/r_hat'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: 1e10
                                        * Referenced by: '<S33>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: -1e10
                                        * Referenced by: '<S33>/Saturation'
                                        */
  real_T Gain_Gain_f;                  /* Expression: pi
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T Constant_Value_p;             /* Expression: 2*pi
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Integrator2_IC[3];            /* Expression: [0 0 0]'
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1e10
                                        * Referenced by: '<S19>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: -1e10
                                        * Referenced by: '<S19>/Saturation'
                                        */
  real_T Gain_Gain_p;                  /* Expression: pi
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Constant_Value_i;             /* Expression: 2*pi
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 1e10
                                        * Referenced by: '<S22>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -1e10
                                        * Referenced by: '<S22>/Saturation'
                                        */
  real_T Gain_Gain_a;                  /* Expression: pi
                                        * Referenced by: '<S22>/Gain'
                                        */
  real_T Constant_Value_j;             /* Expression: 2*pi
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1e10
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -1e10
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Gain_Gain_ag;                 /* Expression: pi
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Constant_Value_l;             /* Expression: 2*pi
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S21>/Integrator3'
                                        */
  real_T M1_Gain[9];                   /* Expression: [0.008021948049864 0 0;0 0.010098125265799 1.104781662647098e-04;0 3.303823257820844e-05 0.020839338676560]
                                        * Referenced by: '<S4>/M^-1'
                                        */
  real_T u_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S36>/u_dot_hat'
                                        */
  real_T u_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S36>/u_dot_hat'
                                        */
  real_T u_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S36>/u_dot_hat'
                                        */
  real_T u_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S36>/u_dot_hat'
                                        */
  real_T u_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S36>/u_dot_hat'
                                        */
  real_T u_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S36>/u_dot_hat'
                                        */
  real_T v_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S36>/v_dot_hat'
                                        */
  real_T v_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S36>/v_dot_hat'
                                        */
  real_T v_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S36>/v_dot_hat'
                                        */
  real_T v_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S36>/v_dot_hat'
                                        */
  real_T v_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S36>/v_dot_hat'
                                        */
  real_T v_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S36>/v_dot_hat'
                                        */
  real_T r_dot_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S36>/r_dot_hat'
                                        */
  real_T r_dot_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S36>/r_dot_hat'
                                        */
  real_T r_dot_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S36>/r_dot_hat'
                                        */
  real_T r_dot_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S36>/r_dot_hat'
                                        */
  real_T r_dot_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S36>/r_dot_hat'
                                        */
  real_T r_dot_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S36>/r_dot_hat'
                                        */
  real_T b_x_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S34>/b_x_hat'
                                        */
  real_T b_x_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S34>/b_x_hat'
                                        */
  real_T b_x_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S34>/b_x_hat'
                                        */
  real_T b_x_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S34>/b_x_hat'
                                        */
  real_T b_x_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S34>/b_x_hat'
                                        */
  real_T b_x_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S34>/b_x_hat'
                                        */
  real_T b_y_hat_P1;                   /* Expression: width
                                        * Referenced by: '<S34>/b_y_hat'
                                        */
  real_T b_y_hat_P2;                   /* Expression: dtype
                                        * Referenced by: '<S34>/b_y_hat'
                                        */
  real_T b_y_hat_P3;                   /* Expression: portnum
                                        * Referenced by: '<S34>/b_y_hat'
                                        */
  real_T b_y_hat_P4;                   /* Expression: stime
                                        * Referenced by: '<S34>/b_y_hat'
                                        */
  real_T b_y_hat_P5;                   /* Expression: stype
                                        * Referenced by: '<S34>/b_y_hat'
                                        */
  real_T b_y_hat_P6;                   /* Expression: btype
                                        * Referenced by: '<S34>/b_y_hat'
                                        */
  real_T b_psi_hat_P1;                 /* Expression: width
                                        * Referenced by: '<S34>/b_psi_hat'
                                        */
  real_T b_psi_hat_P2;                 /* Expression: dtype
                                        * Referenced by: '<S34>/b_psi_hat'
                                        */
  real_T b_psi_hat_P3;                 /* Expression: portnum
                                        * Referenced by: '<S34>/b_psi_hat'
                                        */
  real_T b_psi_hat_P4;                 /* Expression: stime
                                        * Referenced by: '<S34>/b_psi_hat'
                                        */
  real_T b_psi_hat_P5;                 /* Expression: stype
                                        * Referenced by: '<S34>/b_psi_hat'
                                        */
  real_T b_psi_hat_P6;                 /* Expression: btype
                                        * Referenced by: '<S34>/b_psi_hat'
                                        */
  real_T Memory4_X0[6];                /* Expression: [0 0 0 0 0 0]'
                                        * Referenced by: '<S8>/Memory4'
                                        */
  real_T alpha1_P1;                    /* Expression: width
                                        * Referenced by: '<S7>/alpha1'
                                        */
  real_T alpha1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S7>/alpha1'
                                        */
  real_T alpha1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S7>/alpha1'
                                        */
  real_T alpha1_P4;                    /* Expression: stime
                                        * Referenced by: '<S7>/alpha1'
                                        */
  real_T alpha1_P5;                    /* Expression: stype
                                        * Referenced by: '<S7>/alpha1'
                                        */
  real_T alpha1_P6;                    /* Expression: btype
                                        * Referenced by: '<S7>/alpha1'
                                        */
  real_T alpha2_P1;                    /* Expression: width
                                        * Referenced by: '<S7>/alpha2'
                                        */
  real_T alpha2_P2;                    /* Expression: dtype
                                        * Referenced by: '<S7>/alpha2'
                                        */
  real_T alpha2_P3;                    /* Expression: portnum
                                        * Referenced by: '<S7>/alpha2'
                                        */
  real_T alpha2_P4;                    /* Expression: stime
                                        * Referenced by: '<S7>/alpha2'
                                        */
  real_T alpha2_P5;                    /* Expression: stype
                                        * Referenced by: '<S7>/alpha2'
                                        */
  real_T alpha2_P6;                    /* Expression: btype
                                        * Referenced by: '<S7>/alpha2'
                                        */
  real_T alpha3_P1;                    /* Expression: width
                                        * Referenced by: '<S7>/alpha3'
                                        */
  real_T alpha3_P2;                    /* Expression: dtype
                                        * Referenced by: '<S7>/alpha3'
                                        */
  real_T alpha3_P3;                    /* Expression: portnum
                                        * Referenced by: '<S7>/alpha3'
                                        */
  real_T alpha3_P4;                    /* Expression: stime
                                        * Referenced by: '<S7>/alpha3'
                                        */
  real_T alpha3_P5;                    /* Expression: stype
                                        * Referenced by: '<S7>/alpha3'
                                        */
  real_T alpha3_P6;                    /* Expression: btype
                                        * Referenced by: '<S7>/alpha3'
                                        */
  real_T alpha4_P1;                    /* Expression: width
                                        * Referenced by: '<S7>/alpha4'
                                        */
  real_T alpha4_P2;                    /* Expression: dtype
                                        * Referenced by: '<S7>/alpha4'
                                        */
  real_T alpha4_P3;                    /* Expression: portnum
                                        * Referenced by: '<S7>/alpha4'
                                        */
  real_T alpha4_P4;                    /* Expression: stime
                                        * Referenced by: '<S7>/alpha4'
                                        */
  real_T alpha4_P5;                    /* Expression: stype
                                        * Referenced by: '<S7>/alpha4'
                                        */
  real_T alpha4_P6;                    /* Expression: btype
                                        * Referenced by: '<S7>/alpha4'
                                        */
  real_T alpha5_P1;                    /* Expression: width
                                        * Referenced by: '<S7>/alpha5'
                                        */
  real_T alpha5_P2;                    /* Expression: dtype
                                        * Referenced by: '<S7>/alpha5'
                                        */
  real_T alpha5_P3;                    /* Expression: portnum
                                        * Referenced by: '<S7>/alpha5'
                                        */
  real_T alpha5_P4;                    /* Expression: stime
                                        * Referenced by: '<S7>/alpha5'
                                        */
  real_T alpha5_P5;                    /* Expression: stype
                                        * Referenced by: '<S7>/alpha5'
                                        */
  real_T alpha5_P6;                    /* Expression: btype
                                        * Referenced by: '<S7>/alpha5'
                                        */
  real_T alpha6_P1;                    /* Expression: width
                                        * Referenced by: '<S7>/alpha6'
                                        */
  real_T alpha6_P2;                    /* Expression: dtype
                                        * Referenced by: '<S7>/alpha6'
                                        */
  real_T alpha6_P3;                    /* Expression: portnum
                                        * Referenced by: '<S7>/alpha6'
                                        */
  real_T alpha6_P4;                    /* Expression: stime
                                        * Referenced by: '<S7>/alpha6'
                                        */
  real_T alpha6_P5;                    /* Expression: stype
                                        * Referenced by: '<S7>/alpha6'
                                        */
  real_T alpha6_P6;                    /* Expression: btype
                                        * Referenced by: '<S7>/alpha6'
                                        */
  real_T u1_P1;                        /* Expression: width
                                        * Referenced by: '<S7>/u1'
                                        */
  real_T u1_P2;                        /* Expression: dtype
                                        * Referenced by: '<S7>/u1'
                                        */
  real_T u1_P3;                        /* Expression: portnum
                                        * Referenced by: '<S7>/u1'
                                        */
  real_T u1_P4;                        /* Expression: stime
                                        * Referenced by: '<S7>/u1'
                                        */
  real_T u1_P5;                        /* Expression: stype
                                        * Referenced by: '<S7>/u1'
                                        */
  real_T u1_P6;                        /* Expression: btype
                                        * Referenced by: '<S7>/u1'
                                        */
  real_T u2_P1;                        /* Expression: width
                                        * Referenced by: '<S7>/u2'
                                        */
  real_T u2_P2;                        /* Expression: dtype
                                        * Referenced by: '<S7>/u2'
                                        */
  real_T u2_P3;                        /* Expression: portnum
                                        * Referenced by: '<S7>/u2'
                                        */
  real_T u2_P4;                        /* Expression: stime
                                        * Referenced by: '<S7>/u2'
                                        */
  real_T u2_P5;                        /* Expression: stype
                                        * Referenced by: '<S7>/u2'
                                        */
  real_T u2_P6;                        /* Expression: btype
                                        * Referenced by: '<S7>/u2'
                                        */
  real_T u3_P1;                        /* Expression: width
                                        * Referenced by: '<S7>/u3'
                                        */
  real_T u3_P2;                        /* Expression: dtype
                                        * Referenced by: '<S7>/u3'
                                        */
  real_T u3_P3;                        /* Expression: portnum
                                        * Referenced by: '<S7>/u3'
                                        */
  real_T u3_P4;                        /* Expression: stime
                                        * Referenced by: '<S7>/u3'
                                        */
  real_T u3_P5;                        /* Expression: stype
                                        * Referenced by: '<S7>/u3'
                                        */
  real_T u3_P6;                        /* Expression: btype
                                        * Referenced by: '<S7>/u3'
                                        */
  real_T u4_P1;                        /* Expression: width
                                        * Referenced by: '<S7>/u4'
                                        */
  real_T u4_P2;                        /* Expression: dtype
                                        * Referenced by: '<S7>/u4'
                                        */
  real_T u4_P3;                        /* Expression: portnum
                                        * Referenced by: '<S7>/u4'
                                        */
  real_T u4_P4;                        /* Expression: stime
                                        * Referenced by: '<S7>/u4'
                                        */
  real_T u4_P5;                        /* Expression: stype
                                        * Referenced by: '<S7>/u4'
                                        */
  real_T u4_P6;                        /* Expression: btype
                                        * Referenced by: '<S7>/u4'
                                        */
  real_T u5_P1;                        /* Expression: width
                                        * Referenced by: '<S7>/u5'
                                        */
  real_T u5_P2;                        /* Expression: dtype
                                        * Referenced by: '<S7>/u5'
                                        */
  real_T u5_P3;                        /* Expression: portnum
                                        * Referenced by: '<S7>/u5'
                                        */
  real_T u5_P4;                        /* Expression: stime
                                        * Referenced by: '<S7>/u5'
                                        */
  real_T u5_P5;                        /* Expression: stype
                                        * Referenced by: '<S7>/u5'
                                        */
  real_T u5_P6;                        /* Expression: btype
                                        * Referenced by: '<S7>/u5'
                                        */
  real_T u6_P1;                        /* Expression: width
                                        * Referenced by: '<S7>/u6'
                                        */
  real_T u6_P2;                        /* Expression: dtype
                                        * Referenced by: '<S7>/u6'
                                        */
  real_T u6_P3;                        /* Expression: portnum
                                        * Referenced by: '<S7>/u6'
                                        */
  real_T u6_P4;                        /* Expression: stime
                                        * Referenced by: '<S7>/u6'
                                        */
  real_T u6_P5;                        /* Expression: stype
                                        * Referenced by: '<S7>/u6'
                                        */
  real_T u6_P6;                        /* Expression: btype
                                        * Referenced by: '<S7>/u6'
                                        */
  real_T x_tilde_P1;                   /* Expression: width
                                        * Referenced by: '<S20>/x_tilde'
                                        */
  real_T x_tilde_P2;                   /* Expression: dtype
                                        * Referenced by: '<S20>/x_tilde'
                                        */
  real_T x_tilde_P3;                   /* Expression: portnum
                                        * Referenced by: '<S20>/x_tilde'
                                        */
  real_T x_tilde_P4;                   /* Expression: stime
                                        * Referenced by: '<S20>/x_tilde'
                                        */
  real_T x_tilde_P5;                   /* Expression: stype
                                        * Referenced by: '<S20>/x_tilde'
                                        */
  real_T x_tilde_P6;                   /* Expression: btype
                                        * Referenced by: '<S20>/x_tilde'
                                        */
  real_T y_tilde_P1;                   /* Expression: width
                                        * Referenced by: '<S20>/y_tilde'
                                        */
  real_T y_tilde_P2;                   /* Expression: dtype
                                        * Referenced by: '<S20>/y_tilde'
                                        */
  real_T y_tilde_P3;                   /* Expression: portnum
                                        * Referenced by: '<S20>/y_tilde'
                                        */
  real_T y_tilde_P4;                   /* Expression: stime
                                        * Referenced by: '<S20>/y_tilde'
                                        */
  real_T y_tilde_P5;                   /* Expression: stype
                                        * Referenced by: '<S20>/y_tilde'
                                        */
  real_T y_tilde_P6;                   /* Expression: btype
                                        * Referenced by: '<S20>/y_tilde'
                                        */
  real_T psi_tilde_P1;                 /* Expression: width
                                        * Referenced by: '<S20>/psi_tilde'
                                        */
  real_T psi_tilde_P2;                 /* Expression: dtype
                                        * Referenced by: '<S20>/psi_tilde'
                                        */
  real_T psi_tilde_P3;                 /* Expression: portnum
                                        * Referenced by: '<S20>/psi_tilde'
                                        */
  real_T psi_tilde_P4;                 /* Expression: stime
                                        * Referenced by: '<S20>/psi_tilde'
                                        */
  real_T psi_tilde_P5;                 /* Expression: stype
                                        * Referenced by: '<S20>/psi_tilde'
                                        */
  real_T psi_tilde_P6;                 /* Expression: btype
                                        * Referenced by: '<S20>/psi_tilde'
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
                                        * Referenced by: '<S21>/Integrator2'
                                        */
  real_T deg2rad_Gain_l;               /* Expression: pi/180
                                        * Referenced by: '<S6>/deg2rad'
                                        */
  real_T Constant_Value_c;             /* Expression: 50
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Constant1_Value_p;            /* Expression: 50
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 50
                                        * Referenced by: '<S40>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S40>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S40>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S40>/Constant5'
                                        */
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
  real_T odeY[21];
  real_T odeF[3][21];
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
 * '<S4>'   : 'ctrl_DP/Nonlinear Passisve Observer'
 * '<S5>'   : 'ctrl_DP/Observer output '
 * '<S6>'   : 'ctrl_DP/Operator input'
 * '<S7>'   : 'ctrl_DP/Output'
 * '<S8>'   : 'ctrl_DP/Projection [-pi,pi] to [-inf,inf] + shortest rotation'
 * '<S9>'   : 'ctrl_DP/Radians to Degrees'
 * '<S10>'  : 'ctrl_DP/Thrust allocation'
 * '<S11>'  : 'ctrl_DP/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix'
 * '<S12>'  : 'ctrl_DP/Thruster Parameters '
 * '<S13>'  : 'ctrl_DP/Thruster control '
 * '<S14>'  : 'ctrl_DP/Thruster measurment'
 * '<S15>'  : 'ctrl_DP/eta_QTM'
 * '<S16>'  : 'ctrl_DP/Control/Transposed rotation  matrix in yaw1'
 * '<S17>'  : 'ctrl_DP/Control/Transposed rotation  matrix in yaw2'
 * '<S18>'  : 'ctrl_DP/Control/[-inf inf] to [-pi pi]'
 * '<S19>'  : 'ctrl_DP/Control/[-inf inf] to [-pi pi]1'
 * '<S20>'  : 'ctrl_DP/Control/eta_tilde'
 * '<S21>'  : 'ctrl_DP/Guidance/Reference model'
 * '<S22>'  : 'ctrl_DP/Guidance/Reference model/[-inf inf] to [-pi pi]1'
 * '<S23>'  : 'ctrl_DP/Guidance/Reference model/w_d*w_d'
 * '<S24>'  : 'ctrl_DP/Guidance/Reference model/w_d*w_d1'
 * '<S25>'  : 'ctrl_DP/Guidance/Reference model/w_d^-2'
 * '<S26>'  : 'ctrl_DP/Guidance/Reference model/w_d^3'
 * '<S27>'  : 'ctrl_DP/Nonlinear Passisve Observer/C(nu)*nu'
 * '<S28>'  : 'ctrl_DP/Nonlinear Passisve Observer/D(nu)*nu'
 * '<S29>'  : 'ctrl_DP/Nonlinear Passisve Observer/Rotation matrix in yaw 1'
 * '<S30>'  : 'ctrl_DP/Nonlinear Passisve Observer/Transpose Rotation Matrix'
 * '<S31>'  : 'ctrl_DP/Nonlinear Passisve Observer/Transpose Rotation matrix'
 * '<S32>'  : 'ctrl_DP/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]'
 * '<S33>'  : 'ctrl_DP/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1'
 * '<S34>'  : 'ctrl_DP/Observer output /b_hat output'
 * '<S35>'  : 'ctrl_DP/Observer output /eta_hat output'
 * '<S36>'  : 'ctrl_DP/Observer output /nu_dot_hat output'
 * '<S37>'  : 'ctrl_DP/Observer output /nu_hat output'
 * '<S38>'  : 'ctrl_DP/Operator input/Control Gains'
 * '<S39>'  : 'ctrl_DP/Operator input/Guidance gains'
 * '<S40>'  : 'ctrl_DP/Operator input/Observer Gains'
 * '<S41>'  : 'ctrl_DP/Operator input/Control Gains/MATLAB Function'
 * '<S42>'  : 'ctrl_DP/Operator input/Control Gains/MATLAB Function1'
 * '<S43>'  : 'ctrl_DP/Operator input/Control Gains/MATLAB Function2'
 * '<S44>'  : 'ctrl_DP/Operator input/Guidance gains/MATLAB Function'
 * '<S45>'  : 'ctrl_DP/Operator input/Guidance gains/MATLAB Function1'
 * '<S46>'  : 'ctrl_DP/Operator input/Observer Gains/MATLAB Function'
 * '<S47>'  : 'ctrl_DP/Operator input/Observer Gains/MATLAB Function1'
 * '<S48>'  : 'ctrl_DP/Operator input/Observer Gains/MATLAB Function2'
 * '<S49>'  : 'ctrl_DP/Projection [-pi,pi] to [-inf,inf] + shortest rotation/MATLAB Function11'
 * '<S50>'  : 'ctrl_DP/Thrust allocation/MATLAB Function'
 * '<S51>'  : 'ctrl_DP/Thrust allocation/Optimal angle path and  constraints on rotation speed'
 * '<S52>'  : 'ctrl_DP/Thrust allocation/Radians to Degrees'
 * '<S53>'  : 'ctrl_DP/Thrust allocation/angle between  [-180 180]'
 * '<S54>'  : 'ctrl_DP/Thrust allocation/Optimal angle path and  constraints on rotation speed/Degrees to Radians'
 * '<S55>'  : 'ctrl_DP/Thrust allocation/Optimal angle path and  constraints on rotation speed/Ensuring angle is  [-pi pi]'
 * '<S56>'  : 'ctrl_DP/Thrust allocation/Optimal angle path and  constraints on rotation speed/MATLAB Function1'
 * '<S57>'  : 'ctrl_DP/Thrust allocation: Pseudo-inverse of extended thrust configuration matrix/MATLAB Function11'
 * '<S58>'  : 'ctrl_DP/Thruster control /Subsystem1'
 * '<S59>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM'
 * '<S60>'  : 'ctrl_DP/Thruster control /Thruster 1'
 * '<S61>'  : 'ctrl_DP/Thruster control /Thruster 2'
 * '<S62>'  : 'ctrl_DP/Thruster control /Thruster 3'
 * '<S63>'  : 'ctrl_DP/Thruster control /Thruster 4'
 * '<S64>'  : 'ctrl_DP/Thruster control /Thruster 5'
 * '<S65>'  : 'ctrl_DP/Thruster control /Thruster 6'
 * '<S66>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function'
 * '<S67>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function1'
 * '<S68>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function2'
 * '<S69>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function3'
 * '<S70>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function4'
 * '<S71>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function5'
 * '<S72>'  : 'ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function6'
 * '<S73>'  : 'ctrl_DP/Thruster control /Thruster 1/Propeller Hydrodynamics'
 * '<S74>'  : 'ctrl_DP/Thruster control /Thruster 1/Shaft dynamics'
 * '<S75>'  : 'ctrl_DP/Thruster control /Thruster 1/Thruster control'
 * '<S76>'  : 'ctrl_DP/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S77>'  : 'ctrl_DP/Thruster control /Thruster 1/Thruster control/Core controller'
 * '<S78>'  : 'ctrl_DP/Thruster control /Thruster 1/Thruster control/MATLAB Function'
 * '<S79>'  : 'ctrl_DP/Thruster control /Thruster 1/Thruster control/Supervisor'
 * '<S80>'  : 'ctrl_DP/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S81>'  : 'ctrl_DP/Thruster control /Thruster 2/Propeller Hydrodynamics'
 * '<S82>'  : 'ctrl_DP/Thruster control /Thruster 2/Shaft dynamics'
 * '<S83>'  : 'ctrl_DP/Thruster control /Thruster 2/Thruster control'
 * '<S84>'  : 'ctrl_DP/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S85>'  : 'ctrl_DP/Thruster control /Thruster 2/Thruster control/Core controller'
 * '<S86>'  : 'ctrl_DP/Thruster control /Thruster 2/Thruster control/MATLAB Function'
 * '<S87>'  : 'ctrl_DP/Thruster control /Thruster 2/Thruster control/Supervisor'
 * '<S88>'  : 'ctrl_DP/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S89>'  : 'ctrl_DP/Thruster control /Thruster 3/Propeller Hydrodynamics'
 * '<S90>'  : 'ctrl_DP/Thruster control /Thruster 3/Shaft dynamics'
 * '<S91>'  : 'ctrl_DP/Thruster control /Thruster 3/Thruster control'
 * '<S92>'  : 'ctrl_DP/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S93>'  : 'ctrl_DP/Thruster control /Thruster 3/Thruster control/Core controller'
 * '<S94>'  : 'ctrl_DP/Thruster control /Thruster 3/Thruster control/MATLAB Function'
 * '<S95>'  : 'ctrl_DP/Thruster control /Thruster 3/Thruster control/Supervisor'
 * '<S96>'  : 'ctrl_DP/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S97>'  : 'ctrl_DP/Thruster control /Thruster 4/Propeller Hydrodynamics'
 * '<S98>'  : 'ctrl_DP/Thruster control /Thruster 4/Shaft dynamics'
 * '<S99>'  : 'ctrl_DP/Thruster control /Thruster 4/Thruster control'
 * '<S100>' : 'ctrl_DP/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S101>' : 'ctrl_DP/Thruster control /Thruster 4/Thruster control/Core controller'
 * '<S102>' : 'ctrl_DP/Thruster control /Thruster 4/Thruster control/MATLAB Function'
 * '<S103>' : 'ctrl_DP/Thruster control /Thruster 4/Thruster control/Supervisor'
 * '<S104>' : 'ctrl_DP/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S105>' : 'ctrl_DP/Thruster control /Thruster 5/Propeller Hydrodynamics'
 * '<S106>' : 'ctrl_DP/Thruster control /Thruster 5/Shaft dynamics'
 * '<S107>' : 'ctrl_DP/Thruster control /Thruster 5/Thruster control'
 * '<S108>' : 'ctrl_DP/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S109>' : 'ctrl_DP/Thruster control /Thruster 5/Thruster control/Core controller'
 * '<S110>' : 'ctrl_DP/Thruster control /Thruster 5/Thruster control/MATLAB Function'
 * '<S111>' : 'ctrl_DP/Thruster control /Thruster 5/Thruster control/Supervisor'
 * '<S112>' : 'ctrl_DP/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S113>' : 'ctrl_DP/Thruster control /Thruster 6/Propeller Hydrodynamics'
 * '<S114>' : 'ctrl_DP/Thruster control /Thruster 6/Shaft dynamics'
 * '<S115>' : 'ctrl_DP/Thruster control /Thruster 6/Thruster control'
 * '<S116>' : 'ctrl_DP/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S117>' : 'ctrl_DP/Thruster control /Thruster 6/Thruster control/Core controller'
 * '<S118>' : 'ctrl_DP/Thruster control /Thruster 6/Thruster control/MATLAB Function'
 * '<S119>' : 'ctrl_DP/Thruster control /Thruster 6/Thruster control/Supervisor'
 * '<S120>' : 'ctrl_DP/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 */
#endif                                 /* RTW_HEADER_ctrl_DP_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_DP
 * Model version : 1.207
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Wed Aug 23 17:03:41 2017
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
