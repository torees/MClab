/*
 * ctrl_TAPM2.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_TAPM2".
 *
 * Model version              : 1.39
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sun May 15 13:28:12 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_TAPM2_h_
#define RTW_HEADER_ctrl_TAPM2_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ctrl_TAPM2_COMMON_INCLUDES_
# define ctrl_TAPM2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_TAPM2_COMMON_INCLUDES_ */

#include "ctrl_TAPM2_types.h"

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
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
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
#define ctrl_TAPM2_rtModel             RT_MODEL_ctrl_TAPM2_T

/* Block signals for system '<S42>/Actual Force and Torque' */
typedef struct {
  real_T Ta;                           /* '<S42>/Actual Force and Torque' */
  real_T Qa;                           /* '<S42>/Actual Force and Torque' */
} B_ActualForceandTorque_ctrl_T_T;

/* Block signals for system '<S46>/Core controller: Torque,Power and Combined Torque//Power' */
typedef struct {
  real_T Qcq;                          /* '<S46>/Core controller: Torque,Power and Combined Torque//Power' */
  real_T Qcp;                          /* '<S46>/Core controller: Torque,Power and Combined Torque//Power' */
  real_T Qcc;                          /* '<S46>/Core controller: Torque,Power and Combined Torque//Power' */
} B_CorecontrollerTorquePoweran_T;

/* Block signals for system '<S44>/Supervisor' */
typedef struct {
  real_T u;                            /* '<S44>/Supervisor' */
} B_Supervisor_ctrl_TAPM2_T;

/* Block signals for system '<S54>/MATLAB Function' */
typedef struct {
  real_T n_d;                          /* '<S54>/MATLAB Function' */
  real_T T_r;                          /* '<S54>/MATLAB Function' */
} B_MATLABFunction_ctrl_TAPM2_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Saturation1;                  /* '<S34>/Saturation 1' */
  real_T reset;                        /* '<S43>/reset' */
  real_T Integrator;                   /* '<S43>/Integrator' */
  real_T reset_c;                      /* '<S53>/reset' */
  real_T Integrator_h;                 /* '<S53>/Integrator' */
  real_T reset_j;                      /* '<S63>/reset' */
  real_T Integrator_a;                 /* '<S63>/Integrator' */
  real_T reset_p;                      /* '<S73>/reset' */
  real_T Integrator_k;                 /* '<S73>/Integrator' */
  real_T reset_k;                      /* '<S83>/reset' */
  real_T Integrator_c;                 /* '<S83>/Integrator' */
  real_T reset_i;                      /* '<S93>/reset' */
  real_T Integrator_m;                 /* '<S93>/Integrator' */
  real_T pwmthruster2;                 /* '<S33>/pwm thruster 2' */
  real_T pwmthruster3;                 /* '<S33>/pwm thruster 3' */
  real_T pwmthruster4;                 /* '<S33>/pwm thruster 4' */
  real_T pwmthruster5;                 /* '<S33>/pwm thruster 5' */
  real_T Saturation2;                  /* '<S34>/Saturation 2' */
  real_T pwmthruster6;                 /* '<S33>/pwm thruster 6' */
  real_T Saturation3;                  /* '<S34>/Saturation 3' */
  real_T Saturation4;                  /* '<S34>/Saturation 4' */
  real_T Saturation5;                  /* '<S34>/Saturation 5' */
  real_T Saturation6;                  /* '<S34>/Saturation 6' */
  real_T Saturation7[6];               /* '<S33>/Saturation 7' */
  real_T pwmthruster1;                 /* '<S33>/pwm thruster 1' */
  real_T Gain[6];                      /* '<S5>/Gain' */
  real_T Delay;                        /* '<S35>/Delay' */
  real_T DiscreteTransferFcn;          /* '<S44>/Discrete Transfer Fcn' */
  real_T TSamp;                        /* '<S47>/TSamp' */
  real_T Inertiacompensation;          /* '<S44>/Inertia compensation' */
  real_T Sum1;                         /* '<S44>/Sum1' */
  real_T Memory;                       /* '<S44>/Memory' */
  real_T Kp;                           /* '<S46>/Kp' */
  real_T reset_kk;                     /* '<S46>/reset' */
  real_T Sum;                          /* '<S44>/Sum' */
  real_T DiscreteTransferFcn_d;        /* '<S35>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed;         /* '<S43>/Finding rotation speed' */
  real_T Ki;                           /* '<S46>/Ki' */
  real_T Delay_b;                      /* '<S36>/Delay' */
  real_T DiscreteTransferFcn_e;        /* '<S54>/Discrete Transfer Fcn' */
  real_T TSamp_n;                      /* '<S57>/TSamp' */
  real_T Inertiacompensation_e;        /* '<S54>/Inertia compensation' */
  real_T Sum1_n;                       /* '<S54>/Sum1' */
  real_T Memory_c;                     /* '<S54>/Memory' */
  real_T Kp_p;                         /* '<S56>/Kp' */
  real_T reset_e;                      /* '<S56>/reset' */
  real_T Sum_h;                        /* '<S54>/Sum' */
  real_T DiscreteTransferFcn_k;        /* '<S36>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_a;       /* '<S53>/Finding rotation speed' */
  real_T Ki_o;                         /* '<S56>/Ki' */
  real_T Delay_i;                      /* '<S37>/Delay' */
  real_T DiscreteTransferFcn_f;        /* '<S64>/Discrete Transfer Fcn' */
  real_T TSamp_k;                      /* '<S67>/TSamp' */
  real_T Inertiacompensation_c;        /* '<S64>/Inertia compensation' */
  real_T Sum1_i;                       /* '<S64>/Sum1' */
  real_T Memory_i;                     /* '<S64>/Memory' */
  real_T Kp_i;                         /* '<S66>/Kp' */
  real_T reset_j2;                     /* '<S66>/reset' */
  real_T Sum_hf;                       /* '<S64>/Sum' */
  real_T DiscreteTransferFcn_n;        /* '<S37>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_m;       /* '<S63>/Finding rotation speed' */
  real_T Ki_n;                         /* '<S66>/Ki' */
  real_T Delay_g;                      /* '<S38>/Delay' */
  real_T DiscreteTransferFcn_l;        /* '<S74>/Discrete Transfer Fcn' */
  real_T TSamp_a;                      /* '<S77>/TSamp' */
  real_T Inertiacompensation_k;        /* '<S74>/Inertia compensation' */
  real_T Sum1_b;                       /* '<S74>/Sum1' */
  real_T Memory_j;                     /* '<S74>/Memory' */
  real_T Kp_c;                         /* '<S76>/Kp' */
  real_T reset_n;                      /* '<S76>/reset' */
  real_T Sum_k;                        /* '<S74>/Sum' */
  real_T DiscreteTransferFcn_b;        /* '<S38>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_ms;      /* '<S73>/Finding rotation speed' */
  real_T Ki_b;                         /* '<S76>/Ki' */
  real_T Delay_a;                      /* '<S39>/Delay' */
  real_T DiscreteTransferFcn_o;        /* '<S84>/Discrete Transfer Fcn' */
  real_T TSamp_m;                      /* '<S87>/TSamp' */
  real_T Inertiacompensation_f;        /* '<S84>/Inertia compensation' */
  real_T Sum1_o;                       /* '<S84>/Sum1' */
  real_T Memory_d;                     /* '<S84>/Memory' */
  real_T Kp_j;                         /* '<S86>/Kp' */
  real_T reset_f;                      /* '<S86>/reset' */
  real_T Sum_i;                        /* '<S84>/Sum' */
  real_T DiscreteTransferFcn_lz;       /* '<S39>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_ag;      /* '<S83>/Finding rotation speed' */
  real_T Ki_a;                         /* '<S86>/Ki' */
  real_T Delay_h;                      /* '<S40>/Delay' */
  real_T DiscreteTransferFcn_j;        /* '<S94>/Discrete Transfer Fcn' */
  real_T TSamp_o;                      /* '<S97>/TSamp' */
  real_T Inertiacompensation_e3;       /* '<S94>/Inertia compensation' */
  real_T Sum1_io;                      /* '<S94>/Sum1' */
  real_T Memory_o;                     /* '<S94>/Memory' */
  real_T Kp_l;                         /* '<S96>/Kp' */
  real_T reset_o;                      /* '<S96>/reset' */
  real_T Sum_f;                        /* '<S94>/Sum' */
  real_T DiscreteTransferFcn_ea;       /* '<S40>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_c;       /* '<S93>/Finding rotation speed' */
  real_T Ki_p;                         /* '<S96>/Ki' */
  real_T TmpSignalConversionAtDelayInpor[6];/* '<S8>/Subsystem' */
  real_T x_m;                          /* '<S4>/x_m' */
  real_T y_m;                          /* '<S4>/y_m' */
  real_T psi_m;                        /* '<S4>/psi_m' */
  real_T eta[3];                       /* '<S12>/Integrator' */
  real_T nu[3];                        /* '<S12>/Integrator4' */
  real_T wave_dir;                     /* '<S1>/wave_dir' */
  real_T fzp_x;                        /* '<S1>/fzp_x' */
  real_T fzp_y;                        /* '<S1>/fzp_y' */
  real_T r_max;                        /* '<S1>/r_max' */
  real_T TmpSignalConversionAtSPInport1[3];
  real_T Gain3[3];                     /* '<S12>/Gain3' */
  real_T Sum3[3];                      /* '<S12>/Sum3' */
  real_T psi_WF[3];                    /* '<S12>/Sum5' */
  real_T Sum6[3];                      /* '<S12>/Sum6' */
  real_T Sum7[3];                      /* '<S12>/Sum7' */
  real_T Sum_j;                        /* '<S13>/Sum' */
  real_T Sum1_bn[2];                   /* '<S13>/Sum1' */
  real_T Gain_d[3];                    /* '<S6>/Gain' */
  real_T thr_angle_1;                  /* '<S9>/thr_angle_1' */
  real_T thr_angle_2;                  /* '<S9>/thr_angle_2' */
  real_T thr_angle_3;                  /* '<S9>/thr_angle_3' */
  real_T thr_angle_4;                  /* '<S9>/thr_angle_4' */
  real_T thr_angle_5;                  /* '<S9>/thr_angle_5' */
  real_T thr_angle_6;                  /* '<S9>/thr_angle_6' */
  real_T actual_tau[3];                /* '<Root>/MATLAB Function' */
  B_Supervisor_ctrl_TAPM2_T sf_Supervisor_e;/* '<S94>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePower_nf;/* '<S96>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_T_T sf_ActualForceandTorque_j;/* '<S92>/Actual Force and Torque' */
  B_Supervisor_ctrl_TAPM2_T sf_Supervisor_b;/* '<S84>/Supervisor' */
  B_MATLABFunction_ctrl_TAPM2_T sf_MATLABFunction_j;/* '<S84>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_h;/* '<S86>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_T_T sf_ActualForceandTorque_o;/* '<S82>/Actual Force and Torque' */
  B_Supervisor_ctrl_TAPM2_T sf_Supervisor_n;/* '<S74>/Supervisor' */
  B_MATLABFunction_ctrl_TAPM2_T sf_MATLABFunction_g;/* '<S74>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePower_n3;/* '<S76>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_T_T sf_ActualForceandTorque_m;/* '<S72>/Actual Force and Torque' */
  B_Supervisor_ctrl_TAPM2_T sf_Supervisor_l;/* '<S64>/Supervisor' */
  B_MATLABFunction_ctrl_TAPM2_T sf_MATLABFunction_m;/* '<S64>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_n;/* '<S66>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_T_T sf_ActualForceandTorque_h;/* '<S62>/Actual Force and Torque' */
  B_Supervisor_ctrl_TAPM2_T sf_Supervisor_h;/* '<S54>/Supervisor' */
  B_MATLABFunction_ctrl_TAPM2_T sf_MATLABFunction_i;/* '<S54>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_o;/* '<S56>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_T_T sf_ActualForceandTorque_f;/* '<S52>/Actual Force and Torque' */
  B_Supervisor_ctrl_TAPM2_T sf_Supervisor;/* '<S44>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowerand;/* '<S46>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_T_T sf_ActualForceandTorque;/* '<S42>/Actual Force and Torque' */
} B_ctrl_TAPM2_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[6];              /* '<S8>/Delay' */
  real_T Delay_DSTATE_f;               /* '<S35>/Delay' */
  real_T Delay_DSTATE_fu;              /* '<S44>/Delay' */
  real_T DiscreteTransferFcn_states[2];/* '<S44>/Discrete Transfer Fcn' */
  real_T UD_DSTATE;                    /* '<S47>/UD' */
  real_T DiscreteTransferFcn_states_d; /* '<S35>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_b;               /* '<S36>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S54>/Delay' */
  real_T DiscreteTransferFcn_states_h[2];/* '<S54>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_n;                  /* '<S57>/UD' */
  real_T DiscreteTransferFcn_states_m; /* '<S36>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_n;               /* '<S37>/Delay' */
  real_T Delay_DSTATE_no;              /* '<S64>/Delay' */
  real_T DiscreteTransferFcn_states_j[2];/* '<S64>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_i;                  /* '<S67>/UD' */
  real_T DiscreteTransferFcn_states_k; /* '<S37>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_e;               /* '<S38>/Delay' */
  real_T Delay_DSTATE_i;               /* '<S74>/Delay' */
  real_T DiscreteTransferFcn_states_i[2];/* '<S74>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_n4;                 /* '<S77>/UD' */
  real_T DiscreteTransferFcn_states_h0;/* '<S38>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_j;               /* '<S39>/Delay' */
  real_T Delay_DSTATE_a;               /* '<S84>/Delay' */
  real_T DiscreteTransferFcn_states_hb[2];/* '<S84>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_m;                  /* '<S87>/UD' */
  real_T DiscreteTransferFcn_states_dt;/* '<S39>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_dv;              /* '<S40>/Delay' */
  real_T Delay_DSTATE_m;               /* '<S94>/Delay' */
  real_T DiscreteTransferFcn_states_l[2];/* '<S94>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_l;                  /* '<S97>/UD' */
  real_T DiscreteTransferFcn_states_o; /* '<S40>/Discrete Transfer Fcn' */
  real_T alpha_1_DWORK1;               /* '<Root>/alpha_1' */
  real_T reset_DWORK1;                 /* '<S43>/reset' */
  real_T reset_DWORK1_d;               /* '<S53>/reset' */
  real_T reset_DWORK1_e;               /* '<S63>/reset' */
  real_T reset_DWORK1_g;               /* '<S73>/reset' */
  real_T reset_DWORK1_c;               /* '<S83>/reset' */
  real_T reset_DWORK1_a;               /* '<S93>/reset' */
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
  real_T tau_actual_DWORK1[3];         /* '<Root>/tau_actual' */
  real_T DiscreteTransferFcn_tmp;      /* '<S44>/Discrete Transfer Fcn' */
  real_T PrevY;                        /* '<S44>/Acceleration Limit' */
  real_T Memory_PreviousInput;         /* '<S44>/Memory' */
  real_T reset_DWORK1_ec;              /* '<S46>/reset' */
  real_T DiscreteTransferFcn_tmp_a;    /* '<S35>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_d;    /* '<S54>/Discrete Transfer Fcn' */
  real_T PrevY_e;                      /* '<S54>/Acceleration Limit' */
  real_T Memory_PreviousInput_n;       /* '<S54>/Memory' */
  real_T reset_DWORK1_l;               /* '<S56>/reset' */
  real_T DiscreteTransferFcn_tmp_h;    /* '<S36>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_e;    /* '<S64>/Discrete Transfer Fcn' */
  real_T PrevY_o;                      /* '<S64>/Acceleration limiter' */
  real_T Memory_PreviousInput_d;       /* '<S64>/Memory' */
  real_T reset_DWORK1_lw;              /* '<S66>/reset' */
  real_T DiscreteTransferFcn_tmp_hh;   /* '<S37>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_k;    /* '<S74>/Discrete Transfer Fcn' */
  real_T PrevY_c;                      /* '<S74>/Acceleration limiter' */
  real_T Memory_PreviousInput_a;       /* '<S74>/Memory' */
  real_T reset_DWORK1_ct;              /* '<S76>/reset' */
  real_T DiscreteTransferFcn_tmp_n;    /* '<S38>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_c;    /* '<S84>/Discrete Transfer Fcn' */
  real_T PrevY_j;                      /* '<S84>/Acceleration limiter' */
  real_T Memory_PreviousInput_b;       /* '<S84>/Memory' */
  real_T reset_DWORK1_i;               /* '<S86>/reset' */
  real_T DiscreteTransferFcn_tmp_f;    /* '<S39>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_h4;   /* '<S94>/Discrete Transfer Fcn' */
  real_T PrevY_h;                      /* '<S94>/Acceleration limiter' */
  real_T Memory_PreviousInput_a4;      /* '<S94>/Memory' */
  real_T reset_DWORK1_j;               /* '<S96>/reset' */
  real_T DiscreteTransferFcn_tmp_cw;   /* '<S40>/Discrete Transfer Fcn' */
  real_T x_m_DWORK1;                   /* '<S4>/x_m' */
  real_T y_m_DWORK1;                   /* '<S4>/y_m' */
  real_T psi_m_DWORK1;                 /* '<S4>/psi_m' */
  real_T eta_est_DWORK1[3];            /* '<S6>/eta_est' */
  real_T nu_est_DWORK1[3];             /* '<S6>/nu_est' */
  real_T wave_dir_DWORK1;              /* '<S1>/wave_dir' */
  real_T fzp_x_DWORK1;                 /* '<S1>/fzp_x' */
  real_T fzp_y_DWORK1;                 /* '<S1>/fzp_y' */
  real_T r_max_DWORK1;                 /* '<S1>/r_max' */
  real_T SP_DWORK1[3];                 /* '<S6>/SP' */
  real_T tau_des_DWORK1[3];            /* '<S6>/tau_des' */
  real_T thr_angle_1_DWORK1;           /* '<S9>/thr_angle_1' */
  real_T thr_angle_2_DWORK1;           /* '<S9>/thr_angle_2' */
  real_T thr_angle_3_DWORK1;           /* '<S9>/thr_angle_3' */
  real_T thr_angle_4_DWORK1;           /* '<S9>/thr_angle_4' */
  real_T thr_angle_5_DWORK1;           /* '<S9>/thr_angle_5' */
  real_T thr_angle_6_DWORK1;           /* '<S9>/thr_angle_6' */
  uint8_T alpha_1_DWORK2[11];          /* '<Root>/alpha_1' */
  uint8_T reset_DWORK2[11];            /* '<S43>/reset' */
  uint8_T reset_DWORK2_o[11];          /* '<S53>/reset' */
  uint8_T reset_DWORK2_i[11];          /* '<S63>/reset' */
  uint8_T reset_DWORK2_k[11];          /* '<S73>/reset' */
  uint8_T reset_DWORK2_a[11];          /* '<S83>/reset' */
  uint8_T reset_DWORK2_m[11];          /* '<S93>/reset' */
  uint8_T pwm_2_DWORK2[11];            /* '<Root>/pwm_2' */
  uint8_T pwm_3_DWORK2[11];            /* '<Root>/pwm_3' */
  uint8_T pwm_4_DWORK2[11];            /* '<Root>/pwm_4' */
  uint8_T pwm_5_DWORK2[11];            /* '<Root>/pwm_5' */
  uint8_T alpha_2_DWORK2[11];          /* '<Root>/alpha_2' */
  uint8_T pwm_6_DWORK2[11];            /* '<Root>/pwm_6' */
  uint8_T alpha_3_DWORK2[11];          /* '<Root>/alpha_3' */
  uint8_T alpha_4_DWORK2[11];          /* '<Root>/alpha_4' */
  uint8_T alpha_5_DWORK2[11];          /* '<Root>/alpha_5' */
  uint8_T alpha_6_DWORK2[11];          /* '<Root>/alpha_6' */
  uint8_T u_1_DWORK2[11];              /* '<Root>/u_1' */
  uint8_T u_4_DWORK2[11];              /* '<Root>/u_4' */
  uint8_T u_5_DWORK2[11];              /* '<Root>/u_5' */
  uint8_T u_6_DWORK2[11];              /* '<Root>/u_6' */
  uint8_T u_2_DWORK2[11];              /* '<Root>/u_2' */
  uint8_T u_3_DWORK2[11];              /* '<Root>/u_3' */
  uint8_T pwm_1_DWORK2[11];            /* '<Root>/pwm_1' */
  uint8_T tau_actual_DWORK2[11];       /* '<Root>/tau_actual' */
  uint8_T reset_DWORK2_n[11];          /* '<S46>/reset' */
  uint8_T reset_DWORK2_e[11];          /* '<S56>/reset' */
  uint8_T reset_DWORK2_l[11];          /* '<S66>/reset' */
  uint8_T reset_DWORK2_mb[11];         /* '<S76>/reset' */
  uint8_T reset_DWORK2_nu[11];         /* '<S86>/reset' */
  uint8_T reset_DWORK2_f[11];          /* '<S96>/reset' */
  uint8_T x_m_DWORK2[11];              /* '<S4>/x_m' */
  uint8_T y_m_DWORK2[11];              /* '<S4>/y_m' */
  uint8_T psi_m_DWORK2[11];            /* '<S4>/psi_m' */
  uint8_T eta_est_DWORK2[11];          /* '<S6>/eta_est' */
  uint8_T nu_est_DWORK2[11];           /* '<S6>/nu_est' */
  uint8_T wave_dir_DWORK2[11];         /* '<S1>/wave_dir' */
  uint8_T fzp_x_DWORK2[11];            /* '<S1>/fzp_x' */
  uint8_T fzp_y_DWORK2[11];            /* '<S1>/fzp_y' */
  uint8_T r_max_DWORK2[11];            /* '<S1>/r_max' */
  uint8_T SP_DWORK2[11];               /* '<S6>/SP' */
  uint8_T tau_des_DWORK2[11];          /* '<S6>/tau_des' */
  uint8_T thr_angle_1_DWORK2[11];      /* '<S9>/thr_angle_1' */
  uint8_T thr_angle_2_DWORK2[11];      /* '<S9>/thr_angle_2' */
  uint8_T thr_angle_3_DWORK2[11];      /* '<S9>/thr_angle_3' */
  uint8_T thr_angle_4_DWORK2[11];      /* '<S9>/thr_angle_4' */
  uint8_T thr_angle_5_DWORK2[11];      /* '<S9>/thr_angle_5' */
  uint8_T thr_angle_6_DWORK2[11];      /* '<S9>/thr_angle_6' */
} DW_ctrl_TAPM2_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S43>/Integrator' */
  real_T Integrator_CSTATE_p;          /* '<S53>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S63>/Integrator' */
  real_T Integrator_CSTATE_n;          /* '<S73>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S83>/Integrator' */
  real_T Integrator_CSTATE_h;          /* '<S93>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S46>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S56>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S66>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S76>/Integrator' */
  real_T Integrator_CSTATE_n4;         /* '<S86>/Integrator' */
  real_T Integrator_CSTATE_gj;         /* '<S96>/Integrator' */
  real_T Integrator_CSTATE_c5[3];      /* '<S12>/Integrator' */
  real_T Integrator4_CSTATE[3];        /* '<S12>/Integrator4' */
  real_T Integrator_CSTATE_l0[2];      /* '<S13>/Integrator' */
  real_T TransferFcn2_CSTATE;          /* '<S13>/Transfer Fcn2' */
  real_T Integrator1_CSTATE[3];        /* '<S12>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S12>/Integrator2' */
  real_T Integrator3_CSTATE[3];        /* '<S12>/Integrator3' */
} X_ctrl_TAPM2_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S43>/Integrator' */
  real_T Integrator_CSTATE_p;          /* '<S53>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S63>/Integrator' */
  real_T Integrator_CSTATE_n;          /* '<S73>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S83>/Integrator' */
  real_T Integrator_CSTATE_h;          /* '<S93>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S46>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S56>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S66>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S76>/Integrator' */
  real_T Integrator_CSTATE_n4;         /* '<S86>/Integrator' */
  real_T Integrator_CSTATE_gj;         /* '<S96>/Integrator' */
  real_T Integrator_CSTATE_c5[3];      /* '<S12>/Integrator' */
  real_T Integrator4_CSTATE[3];        /* '<S12>/Integrator4' */
  real_T Integrator_CSTATE_l0[2];      /* '<S13>/Integrator' */
  real_T TransferFcn2_CSTATE;          /* '<S13>/Transfer Fcn2' */
  real_T Integrator1_CSTATE[3];        /* '<S12>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S12>/Integrator2' */
  real_T Integrator3_CSTATE[3];        /* '<S12>/Integrator3' */
} XDot_ctrl_TAPM2_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S43>/Integrator' */
  boolean_T Integrator_CSTATE_p;       /* '<S53>/Integrator' */
  boolean_T Integrator_CSTATE_k;       /* '<S63>/Integrator' */
  boolean_T Integrator_CSTATE_n;       /* '<S73>/Integrator' */
  boolean_T Integrator_CSTATE_c;       /* '<S83>/Integrator' */
  boolean_T Integrator_CSTATE_h;       /* '<S93>/Integrator' */
  boolean_T Integrator_CSTATE_e;       /* '<S46>/Integrator' */
  boolean_T Integrator_CSTATE_g;       /* '<S56>/Integrator' */
  boolean_T Integrator_CSTATE_i;       /* '<S66>/Integrator' */
  boolean_T Integrator_CSTATE_l;       /* '<S76>/Integrator' */
  boolean_T Integrator_CSTATE_n4;      /* '<S86>/Integrator' */
  boolean_T Integrator_CSTATE_gj;      /* '<S96>/Integrator' */
  boolean_T Integrator_CSTATE_c5[3];   /* '<S12>/Integrator' */
  boolean_T Integrator4_CSTATE[3];     /* '<S12>/Integrator4' */
  boolean_T Integrator_CSTATE_l0[2];   /* '<S13>/Integrator' */
  boolean_T TransferFcn2_CSTATE;       /* '<S13>/Transfer Fcn2' */
  boolean_T Integrator1_CSTATE[3];     /* '<S12>/Integrator1' */
  boolean_T Integrator2_CSTATE[3];     /* '<S12>/Integrator2' */
  boolean_T Integrator3_CSTATE[3];     /* '<S12>/Integrator3' */
} XDis_ctrl_TAPM2_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S43>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_n;   /* '<S53>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_o;   /* '<S63>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_i;   /* '<S73>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_a;   /* '<S83>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_d;   /* '<S93>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_o3;  /* '<S46>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_db;  /* '<S56>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_l;   /* '<S66>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_h;   /* '<S76>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_f;   /* '<S86>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_i3;  /* '<S96>/Integrator' */
} PrevZCX_ctrl_TAPM2_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_TAPM2_B
#define BlockIO                        B_ctrl_TAPM2_T
#define rtX                            ctrl_TAPM2_X
#define ContinuousStates               X_ctrl_TAPM2_T
#define rtXdot                         ctrl_TAPM2_XDot
#define StateDerivatives               XDot_ctrl_TAPM2_T
#define tXdis                          ctrl_TAPM2_XDis
#define StateDisabled                  XDis_ctrl_TAPM2_T
#define rtP                            ctrl_TAPM2_P
#define Parameters                     P_ctrl_TAPM2_T
#define rtDWork                        ctrl_TAPM2_DW
#define D_Work                         DW_ctrl_TAPM2_T
#define rtPrevZCSigState               ctrl_TAPM2_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_TAPM2_T

/* Parameters (auto storage) */
struct P_ctrl_TAPM2_T_ {
  real_T D;                            /* Variable: D
                                        * Referenced by: '<S3>/D'
                                        */
  real_T I_s;                          /* Variable: I_s
                                        * Referenced by:
                                        *   '<S43>/Finding rotation speed'
                                        *   '<S44>/Inertia compensation'
                                        *   '<S53>/Finding rotation speed'
                                        *   '<S54>/Inertia compensation'
                                        *   '<S63>/Finding rotation speed'
                                        *   '<S64>/Inertia compensation'
                                        *   '<S73>/Finding rotation speed'
                                        *   '<S74>/Inertia compensation'
                                        *   '<S83>/Finding rotation speed'
                                        *   '<S84>/Inertia compensation'
                                        *   '<S93>/Finding rotation speed'
                                        *   '<S94>/Inertia compensation'
                                        */
  real_T K_omega;                      /* Variable: K_omega
                                        * Referenced by:
                                        *   '<S43>/K_omega'
                                        *   '<S44>/Qff_1(nr)'
                                        *   '<S53>/K_omega'
                                        *   '<S54>/Qff_1(nr)'
                                        *   '<S63>/K_omega'
                                        *   '<S64>/Qff_1(nr)'
                                        *   '<S73>/K_omega'
                                        *   '<S74>/Qff_1(nr)'
                                        *   '<S83>/K_omega'
                                        *   '<S84>/Qff_1(nr)'
                                        *   '<S93>/K_omega'
                                        *   '<S94>/Qff_1(nr)'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by:
                                        *   '<S46>/Ki'
                                        *   '<S46>/Kp'
                                        *   '<S56>/Ki'
                                        *   '<S56>/Kp'
                                        *   '<S66>/Ki'
                                        *   '<S66>/Kp'
                                        *   '<S76>/Ki'
                                        *   '<S76>/Kp'
                                        *   '<S86>/Ki'
                                        *   '<S86>/Kp'
                                        *   '<S96>/Ki'
                                        *   '<S96>/Kp'
                                        */
  real_T Kq;                           /* Variable: Kq
                                        * Referenced by: '<S3>/Kq'
                                        */
  real_T Kqr;                          /* Variable: Kqr
                                        * Referenced by: '<S3>/Kqr'
                                        */
  real_T Kt;                           /* Variable: Kt
                                        * Referenced by: '<S3>/Kt'
                                        */
  real_T Ktr;                          /* Variable: Ktr
                                        * Referenced by: '<S3>/Ktr'
                                        */
  real_T Max_thrust;                   /* Variable: Max_thrust
                                        * Referenced by:
                                        *   '<S33>/Saturation 1'
                                        *   '<S33>/Saturation 2'
                                        *   '<S33>/Saturation 3'
                                        *   '<S33>/Saturation 4'
                                        *   '<S33>/Saturation 5'
                                        *   '<S33>/Saturation 6'
                                        *   '<S33>/Saturation 7'
                                        */
  real_T Q_f0;                         /* Variable: Q_f0
                                        * Referenced by:
                                        *   '<S44>/Qf_0'
                                        *   '<S54>/Qf_0'
                                        *   '<S64>/Qf_0'
                                        *   '<S74>/Qf_0'
                                        *   '<S84>/Qf_0'
                                        *   '<S94>/Qf_0'
                                        */
  real_T Rho;                          /* Variable: Rho
                                        * Referenced by: '<S3>/Rho'
                                        */
  real_T Thruster_control;             /* Variable: Thruster_control
                                        * Referenced by:
                                        *   '<S44>/Switch controller'
                                        *   '<S54>/Switch controller'
                                        *   '<S64>/Switch controller'
                                        *   '<S74>/Switch controller'
                                        *   '<S84>/Switch controller'
                                        *   '<S94>/Switch controller'
                                        */
  real_T eps;                          /* Variable: eps
                                        * Referenced by: '<S3>/Constant4'
                                        */
  real_T eps_c;                        /* Variable: eps_c
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T epsilon;                      /* Variable: epsilon
                                        * Referenced by:
                                        *   '<S44>/Qff_0(nr)'
                                        *   '<S54>/Qff_0(nr)'
                                        *   '<S64>/Qff_0(nr)'
                                        *   '<S74>/Qff_0(nr)'
                                        *   '<S84>/Qff_0(nr)'
                                        *   '<S94>/Qff_0(nr)'
                                        */
  real_T k_cc;                         /* Variable: k_cc
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T n_c;                          /* Variable: n_c
                                        * Referenced by: '<S3>/Constant5'
                                        */
  real_T n_max;                        /* Variable: n_max
                                        * Referenced by:
                                        *   '<S44>/Qff_0(nr)'
                                        *   '<S54>/Qff_0(nr)'
                                        *   '<S64>/Qff_0(nr)'
                                        *   '<S74>/Qff_0(nr)'
                                        *   '<S84>/Qff_0(nr)'
                                        *   '<S94>/Qff_0(nr)'
                                        */
  real_T p_cc;                         /* Variable: p_cc
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T r_cc;                         /* Variable: r_cc
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T thrust_to_pwm_coeff[6];       /* Variable: thrust_to_pwm_coeff
                                        * Referenced by:
                                        *   '<S33>/pwm thruster 1'
                                        *   '<S33>/pwm thruster 2'
                                        *   '<S33>/pwm thruster 3'
                                        *   '<S33>/pwm thruster 4'
                                        *   '<S33>/pwm thruster 5'
                                        *   '<S33>/pwm thruster 6'
                                        */
  real_T Nonlinearpassiveobserver_D[9];/* Mask Parameter: Nonlinearpassiveobserver_D
                                        * Referenced by: '<S12>/Gain6'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S47>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_p;/* Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                          * Referenced by: '<S57>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevSca_pl;/* Mask Parameter: DiscreteDerivative_ICPrevSca_pl
                                          * Referenced by: '<S67>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_f;/* Mask Parameter: DiscreteDerivative_ICPrevScal_f
                                          * Referenced by: '<S77>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_o;/* Mask Parameter: DiscreteDerivative_ICPrevScal_o
                                          * Referenced by: '<S87>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_n;/* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                          * Referenced by: '<S97>/UD'
                                          */
  real_T Nonlinearpassiveobserver_K3[9];/* Mask Parameter: Nonlinearpassiveobserver_K3
                                         * Referenced by: '<S12>/K3'
                                         */
  real_T Nonlinearpassiveobserver_K4[9];/* Mask Parameter: Nonlinearpassiveobserver_K4
                                         * Referenced by: '<S12>/K4'
                                         */
  real_T Nonlinearpassiveobserver_w_c[9];/* Mask Parameter: Nonlinearpassiveobserver_w_c
                                          * Referenced by: '<S12>/K2'
                                          */
  real_T XpositionThruster1_Value[12]; /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0]'
                                        * Referenced by: '<Root>/X-position Thruster1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S34>/Saturation 1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S34>/Saturation 1'
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
  real_T reset_P1;                     /* Expression: width
                                        * Referenced by: '<S43>/reset'
                                        */
  real_T reset_P2;                     /* Expression: dtype
                                        * Referenced by: '<S43>/reset'
                                        */
  real_T reset_P3;                     /* Expression: portnum
                                        * Referenced by: '<S43>/reset'
                                        */
  real_T reset_P4;                     /* Expression: stime
                                        * Referenced by: '<S43>/reset'
                                        */
  real_T reset_P5;                     /* Expression: stype
                                        * Referenced by: '<S43>/reset'
                                        */
  real_T reset_P6;                     /* Expression: btype
                                        * Referenced by: '<S43>/reset'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S43>/Integrator'
                                        */
  real_T Lossesplaceholder_Value;      /* Expression: 0
                                        * Referenced by: '<S35>/Losses (placeholder)'
                                        */
  real_T reset_P1_k;                   /* Expression: width
                                        * Referenced by: '<S53>/reset'
                                        */
  real_T reset_P2_n;                   /* Expression: dtype
                                        * Referenced by: '<S53>/reset'
                                        */
  real_T reset_P3_a;                   /* Expression: portnum
                                        * Referenced by: '<S53>/reset'
                                        */
  real_T reset_P4_e;                   /* Expression: stime
                                        * Referenced by: '<S53>/reset'
                                        */
  real_T reset_P5_m;                   /* Expression: stype
                                        * Referenced by: '<S53>/reset'
                                        */
  real_T reset_P6_c;                   /* Expression: btype
                                        * Referenced by: '<S53>/reset'
                                        */
  real_T Integrator_IC_f;              /* Expression: 0
                                        * Referenced by: '<S53>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_k;    /* Expression: 0
                                        * Referenced by: '<S36>/Losses (placeholder)'
                                        */
  real_T reset_P1_m;                   /* Expression: width
                                        * Referenced by: '<S63>/reset'
                                        */
  real_T reset_P2_j;                   /* Expression: dtype
                                        * Referenced by: '<S63>/reset'
                                        */
  real_T reset_P3_i;                   /* Expression: portnum
                                        * Referenced by: '<S63>/reset'
                                        */
  real_T reset_P4_h;                   /* Expression: stime
                                        * Referenced by: '<S63>/reset'
                                        */
  real_T reset_P5_a;                   /* Expression: stype
                                        * Referenced by: '<S63>/reset'
                                        */
  real_T reset_P6_l;                   /* Expression: btype
                                        * Referenced by: '<S63>/reset'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S63>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_n;    /* Expression: 0
                                        * Referenced by: '<S37>/Losses (placeholder)'
                                        */
  real_T reset_P1_kz;                  /* Expression: width
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P2_ng;                  /* Expression: dtype
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P3_e;                   /* Expression: portnum
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P4_b;                   /* Expression: stime
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P5_g;                   /* Expression: stype
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P6_n;                   /* Expression: btype
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T Integrator_IC_fv;             /* Expression: 0
                                        * Referenced by: '<S73>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_d;    /* Expression: 0
                                        * Referenced by: '<S38>/Losses (placeholder)'
                                        */
  real_T reset_P1_j;                   /* Expression: width
                                        * Referenced by: '<S83>/reset'
                                        */
  real_T reset_P2_m;                   /* Expression: dtype
                                        * Referenced by: '<S83>/reset'
                                        */
  real_T reset_P3_p;                   /* Expression: portnum
                                        * Referenced by: '<S83>/reset'
                                        */
  real_T reset_P4_k;                   /* Expression: stime
                                        * Referenced by: '<S83>/reset'
                                        */
  real_T reset_P5_l;                   /* Expression: stype
                                        * Referenced by: '<S83>/reset'
                                        */
  real_T reset_P6_g;                   /* Expression: btype
                                        * Referenced by: '<S83>/reset'
                                        */
  real_T Integrator_IC_l;              /* Expression: 0
                                        * Referenced by: '<S83>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_f;    /* Expression: 0
                                        * Referenced by: '<S39>/Losses (placeholder)'
                                        */
  real_T reset_P1_d;                   /* Expression: width
                                        * Referenced by: '<S93>/reset'
                                        */
  real_T reset_P2_g;                   /* Expression: dtype
                                        * Referenced by: '<S93>/reset'
                                        */
  real_T reset_P3_ic;                  /* Expression: portnum
                                        * Referenced by: '<S93>/reset'
                                        */
  real_T reset_P4_o;                   /* Expression: stime
                                        * Referenced by: '<S93>/reset'
                                        */
  real_T reset_P5_ll;                  /* Expression: stype
                                        * Referenced by: '<S93>/reset'
                                        */
  real_T reset_P6_i;                   /* Expression: btype
                                        * Referenced by: '<S93>/reset'
                                        */
  real_T Integrator_IC_li;             /* Expression: 0
                                        * Referenced by: '<S93>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_h;    /* Expression: 0
                                        * Referenced by: '<S40>/Losses (placeholder)'
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<S33>/Constant12'
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
  real_T Saturation2_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S34>/Saturation 2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S34>/Saturation 2'
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
                                        * Referenced by: '<S34>/Saturation 3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S34>/Saturation 3'
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
                                        * Referenced by: '<S34>/Saturation 4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S34>/Saturation 4'
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
                                        * Referenced by: '<S34>/Saturation 5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S34>/Saturation 5'
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
                                        * Referenced by: '<S34>/Saturation 6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S34>/Saturation 6'
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
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T XpositionThruster_Value[6];   /* Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
                                        * Referenced by: '<Root>/X-position Thruster'
                                        */
  real_T YpositionThruster_Value[6];   /* Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
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
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S8>/Delay'
                                        */
  real_T Constant_Value[2];            /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Constant1_Value[2];           /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real_T Delay_InitialCondition_i;     /* Expression: 0
                                        * Referenced by: '<S35>/Delay'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0
                                        * Referenced by: '<S44>/Delay'
                                        */
  real_T Constant1_Value_o[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S44>/Constant1'
                                        */
  real_T Constant2_Value[3];           /* Expression: hd.den{1,1}
                                        * Referenced by: '<S44>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S44>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S47>/TSamp'
                                        */
  real_T AccelerationLimit_RisingLim;  /* Computed Parameter: AccelerationLimit_RisingLim
                                        * Referenced by: '<S44>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_FallingLim; /* Computed Parameter: AccelerationLimit_FallingLim
                                        * Referenced by: '<S44>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_IC;         /* Expression: 0
                                        * Referenced by: '<S44>/Acceleration Limit'
                                        */
  real_T Memory_X0;                    /* Expression: 1
                                        * Referenced by: '<S44>/Memory'
                                        */
  real_T reset_P1_b;                   /* Expression: width
                                        * Referenced by: '<S46>/reset'
                                        */
  real_T reset_P2_h;                   /* Expression: dtype
                                        * Referenced by: '<S46>/reset'
                                        */
  real_T reset_P3_f;                   /* Expression: portnum
                                        * Referenced by: '<S46>/reset'
                                        */
  real_T reset_P4_c;                   /* Expression: stime
                                        * Referenced by: '<S46>/reset'
                                        */
  real_T reset_P5_k;                   /* Expression: stype
                                        * Referenced by: '<S46>/reset'
                                        */
  real_T reset_P6_d;                   /* Expression: btype
                                        * Referenced by: '<S46>/reset'
                                        */
  real_T Integrator_IC_a;              /* Expression: 0
                                        * Referenced by: '<S46>/Integrator'
                                        */
  real_T NaN_Value;                    /* Expression: 0
                                        * Referenced by: '<S44>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_h;/* Expression: 0
                                          * Referenced by: '<S35>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_h[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Constant1_Value_j[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real_T Delay_InitialCondition_l;     /* Expression: 0
                                        * Referenced by: '<S36>/Delay'
                                        */
  real_T Delay_InitialCondition_iv;    /* Expression: 0
                                        * Referenced by: '<S54>/Delay'
                                        */
  real_T Constant1_Value_b[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S54>/Constant1'
                                        */
  real_T Constant2_Value_i[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S54>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_hu;/* Expression: 0
                                          * Referenced by: '<S54>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_k;                 /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S57>/TSamp'
                                        */
  real_T AccelerationLimit_RisingLim_n;/* Computed Parameter: AccelerationLimit_RisingLim_n
                                        * Referenced by: '<S54>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_FallingLim_n;/* Computed Parameter: AccelerationLimit_FallingLim_n
                                         * Referenced by: '<S54>/Acceleration Limit'
                                         */
  real_T AccelerationLimit_IC_m;       /* Expression: 0
                                        * Referenced by: '<S54>/Acceleration Limit'
                                        */
  real_T Memory_X0_e;                  /* Expression: 1
                                        * Referenced by: '<S54>/Memory'
                                        */
  real_T reset_P1_g;                   /* Expression: width
                                        * Referenced by: '<S56>/reset'
                                        */
  real_T reset_P2_i;                   /* Expression: dtype
                                        * Referenced by: '<S56>/reset'
                                        */
  real_T reset_P3_l;                   /* Expression: portnum
                                        * Referenced by: '<S56>/reset'
                                        */
  real_T reset_P4_n;                   /* Expression: stime
                                        * Referenced by: '<S56>/reset'
                                        */
  real_T reset_P5_b;                   /* Expression: stype
                                        * Referenced by: '<S56>/reset'
                                        */
  real_T reset_P6_g3;                  /* Expression: btype
                                        * Referenced by: '<S56>/reset'
                                        */
  real_T Integrator_IC_fy;             /* Expression: 0
                                        * Referenced by: '<S56>/Integrator'
                                        */
  real_T NaN_Value_l;                  /* Expression: 0
                                        * Referenced by: '<S54>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_f;/* Expression: 0
                                          * Referenced by: '<S36>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_n[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Constant1_Value_a[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S37>/Constant1'
                                        */
  real_T Delay_InitialCondition_d;     /* Expression: 0
                                        * Referenced by: '<S37>/Delay'
                                        */
  real_T Delay_InitialCondition_h;     /* Expression: 0
                                        * Referenced by: '<S64>/Delay'
                                        */
  real_T Constant1_Value_g[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S64>/Constant1'
                                        */
  real_T Constant2_Value_h[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S64>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_a;/* Expression: 0
                                          * Referenced by: '<S64>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_m;                 /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S67>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim;/* Computed Parameter: Accelerationlimiter_RisingLim
                                        * Referenced by: '<S64>/Acceleration limiter'
                                        */
  real_T Accelerationlimiter_FallingLim;/* Computed Parameter: Accelerationlimiter_FallingLim
                                         * Referenced by: '<S64>/Acceleration limiter'
                                         */
  real_T Accelerationlimiter_IC;       /* Expression: 0
                                        * Referenced by: '<S64>/Acceleration limiter'
                                        */
  real_T Memory_X0_g;                  /* Expression: 1
                                        * Referenced by: '<S64>/Memory'
                                        */
  real_T reset_P1_f;                   /* Expression: width
                                        * Referenced by: '<S66>/reset'
                                        */
  real_T reset_P2_k;                   /* Expression: dtype
                                        * Referenced by: '<S66>/reset'
                                        */
  real_T reset_P3_d;                   /* Expression: portnum
                                        * Referenced by: '<S66>/reset'
                                        */
  real_T reset_P4_l;                   /* Expression: stime
                                        * Referenced by: '<S66>/reset'
                                        */
  real_T reset_P5_mc;                  /* Expression: stype
                                        * Referenced by: '<S66>/reset'
                                        */
  real_T reset_P6_f;                   /* Expression: btype
                                        * Referenced by: '<S66>/reset'
                                        */
  real_T Integrator_IC_j;              /* Expression: 0
                                        * Referenced by: '<S66>/Integrator'
                                        */
  real_T NaN_Value_g;                  /* Expression: 0
                                        * Referenced by: '<S64>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_c;/* Expression: 0
                                          * Referenced by: '<S37>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_j[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T Constant1_Value_oi[2];        /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T Delay_InitialCondition_fb;    /* Expression: 0
                                        * Referenced by: '<S38>/Delay'
                                        */
  real_T Delay_InitialCondition_g;     /* Expression: 0
                                        * Referenced by: '<S74>/Delay'
                                        */
  real_T Constant1_Value_m[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S74>/Constant1'
                                        */
  real_T Constant2_Value_l[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S74>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_a1;/* Expression: 0
                                          * Referenced by: '<S74>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_h;                 /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S77>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_e;/* Computed Parameter: Accelerationlimiter_RisingLim_e
                                          * Referenced by: '<S74>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_b;/* Computed Parameter: Accelerationlimiter_FallingLi_b
                                          * Referenced by: '<S74>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_h;     /* Expression: 0
                                        * Referenced by: '<S74>/Acceleration limiter'
                                        */
  real_T Memory_X0_k;                  /* Expression: 1
                                        * Referenced by: '<S74>/Memory'
                                        */
  real_T reset_P1_i;                   /* Expression: width
                                        * Referenced by: '<S76>/reset'
                                        */
  real_T reset_P2_g0;                  /* Expression: dtype
                                        * Referenced by: '<S76>/reset'
                                        */
  real_T reset_P3_eq;                  /* Expression: portnum
                                        * Referenced by: '<S76>/reset'
                                        */
  real_T reset_P4_p;                   /* Expression: stime
                                        * Referenced by: '<S76>/reset'
                                        */
  real_T reset_P5_f;                   /* Expression: stype
                                        * Referenced by: '<S76>/reset'
                                        */
  real_T reset_P6_l2;                  /* Expression: btype
                                        * Referenced by: '<S76>/reset'
                                        */
  real_T Integrator_IC_g;              /* Expression: 0
                                        * Referenced by: '<S76>/Integrator'
                                        */
  real_T NaN_Value_p;                  /* Expression: 0
                                        * Referenced by: '<S74>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_p;/* Expression: 0
                                          * Referenced by: '<S38>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_i[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Constant1_Value_h[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S39>/Constant1'
                                        */
  real_T Delay_InitialCondition_fv;    /* Expression: 0
                                        * Referenced by: '<S39>/Delay'
                                        */
  real_T Delay_InitialCondition_dz;    /* Expression: 0
                                        * Referenced by: '<S84>/Delay'
                                        */
  real_T Constant1_Value_mk[3];        /* Expression: hd.num{1,1}
                                        * Referenced by: '<S84>/Constant1'
                                        */
  real_T Constant2_Value_p[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S84>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_e;/* Expression: 0
                                          * Referenced by: '<S84>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_o;                 /* Computed Parameter: TSamp_WtEt_o
                                        * Referenced by: '<S87>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_b;/* Computed Parameter: Accelerationlimiter_RisingLim_b
                                          * Referenced by: '<S84>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_d;/* Computed Parameter: Accelerationlimiter_FallingLi_d
                                          * Referenced by: '<S84>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_i;     /* Expression: 0
                                        * Referenced by: '<S84>/Acceleration limiter'
                                        */
  real_T Memory_X0_k3;                 /* Expression: 1
                                        * Referenced by: '<S84>/Memory'
                                        */
  real_T reset_P1_md;                  /* Expression: width
                                        * Referenced by: '<S86>/reset'
                                        */
  real_T reset_P2_jk;                  /* Expression: dtype
                                        * Referenced by: '<S86>/reset'
                                        */
  real_T reset_P3_dp;                  /* Expression: portnum
                                        * Referenced by: '<S86>/reset'
                                        */
  real_T reset_P4_g;                   /* Expression: stime
                                        * Referenced by: '<S86>/reset'
                                        */
  real_T reset_P5_mg;                  /* Expression: stype
                                        * Referenced by: '<S86>/reset'
                                        */
  real_T reset_P6_g5;                  /* Expression: btype
                                        * Referenced by: '<S86>/reset'
                                        */
  real_T Integrator_IC_aj;             /* Expression: 0
                                        * Referenced by: '<S86>/Integrator'
                                        */
  real_T NaN_Value_lq;                 /* Expression: 0
                                        * Referenced by: '<S84>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialS_pj;/* Expression: 0
                                          * Referenced by: '<S39>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_ht[2];         /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Constant1_Value_gs[2];        /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Delay_InitialCondition_fi;    /* Expression: 0
                                        * Referenced by: '<S40>/Delay'
                                        */
  real_T Delay_InitialCondition_a;     /* Expression: 0
                                        * Referenced by: '<S94>/Delay'
                                        */
  real_T Constant1_Value_oa[3];        /* Expression: hd.num{1,1}
                                        * Referenced by: '<S94>/Constant1'
                                        */
  real_T Constant2_Value_p3[3];        /* Expression: hd.den{1,1}
                                        * Referenced by: '<S94>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_a4;/* Expression: 0
                                          * Referenced by: '<S94>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_kk;                /* Computed Parameter: TSamp_WtEt_kk
                                        * Referenced by: '<S97>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLi_bi;/* Computed Parameter: Accelerationlimiter_RisingLi_bi
                                          * Referenced by: '<S94>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_p;/* Computed Parameter: Accelerationlimiter_FallingLi_p
                                          * Referenced by: '<S94>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_p;     /* Expression: 0
                                        * Referenced by: '<S94>/Acceleration limiter'
                                        */
  real_T Memory_X0_c;                  /* Expression: 1
                                        * Referenced by: '<S94>/Memory'
                                        */
  real_T reset_P1_kh;                  /* Expression: width
                                        * Referenced by: '<S96>/reset'
                                        */
  real_T reset_P2_hw;                  /* Expression: dtype
                                        * Referenced by: '<S96>/reset'
                                        */
  real_T reset_P3_fv;                  /* Expression: portnum
                                        * Referenced by: '<S96>/reset'
                                        */
  real_T reset_P4_a;                   /* Expression: stime
                                        * Referenced by: '<S96>/reset'
                                        */
  real_T reset_P5_e;                   /* Expression: stype
                                        * Referenced by: '<S96>/reset'
                                        */
  real_T reset_P6_a;                   /* Expression: btype
                                        * Referenced by: '<S96>/reset'
                                        */
  real_T Integrator_IC_h;              /* Expression: 0
                                        * Referenced by: '<S96>/Integrator'
                                        */
  real_T NaN_Value_j;                  /* Expression: 0
                                        * Referenced by: '<S94>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_b;/* Expression: 0
                                          * Referenced by: '<S40>/Discrete Transfer Fcn'
                                          */
  real_T x_m_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T x_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/x_m'
                                        */
  real_T y_m_P1;                       /* Expression: width
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T y_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S4>/y_m'
                                        */
  real_T psi_m_P1;                     /* Expression: width
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P2;                     /* Expression: dtype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P3;                     /* Expression: portnum
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P4;                     /* Expression: stime
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P5;                     /* Expression: stype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T psi_m_P6;                     /* Expression: btype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  real_T Integrator_IC_i[3];           /* Expression: [0,0,0]'
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T eta_est_P1;                   /* Expression: width
                                        * Referenced by: '<S6>/eta_est'
                                        */
  real_T eta_est_P2;                   /* Expression: dtype
                                        * Referenced by: '<S6>/eta_est'
                                        */
  real_T eta_est_P3;                   /* Expression: portnum
                                        * Referenced by: '<S6>/eta_est'
                                        */
  real_T eta_est_P4;                   /* Expression: stime
                                        * Referenced by: '<S6>/eta_est'
                                        */
  real_T eta_est_P5;                   /* Expression: stype
                                        * Referenced by: '<S6>/eta_est'
                                        */
  real_T eta_est_P6;                   /* Expression: btype
                                        * Referenced by: '<S6>/eta_est'
                                        */
  real_T Integrator4_IC[3];            /* Expression: [0,0,0]'
                                        * Referenced by: '<S12>/Integrator4'
                                        */
  real_T nu_est_P1;                    /* Expression: width
                                        * Referenced by: '<S6>/nu_est'
                                        */
  real_T nu_est_P2;                    /* Expression: dtype
                                        * Referenced by: '<S6>/nu_est'
                                        */
  real_T nu_est_P3;                    /* Expression: portnum
                                        * Referenced by: '<S6>/nu_est'
                                        */
  real_T nu_est_P4;                    /* Expression: stime
                                        * Referenced by: '<S6>/nu_est'
                                        */
  real_T nu_est_P5;                    /* Expression: stype
                                        * Referenced by: '<S6>/nu_est'
                                        */
  real_T nu_est_P6;                    /* Expression: btype
                                        * Referenced by: '<S6>/nu_est'
                                        */
  real_T Integrator_IC_b[2];           /* Expression: [0 0]
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T wave_dir_P1;                  /* Expression: width
                                        * Referenced by: '<S1>/wave_dir'
                                        */
  real_T wave_dir_P2;                  /* Expression: dtype
                                        * Referenced by: '<S1>/wave_dir'
                                        */
  real_T wave_dir_P3;                  /* Expression: portnum
                                        * Referenced by: '<S1>/wave_dir'
                                        */
  real_T wave_dir_P4;                  /* Expression: stime
                                        * Referenced by: '<S1>/wave_dir'
                                        */
  real_T wave_dir_P5;                  /* Expression: stype
                                        * Referenced by: '<S1>/wave_dir'
                                        */
  real_T wave_dir_P6;                  /* Expression: btype
                                        * Referenced by: '<S1>/wave_dir'
                                        */
  real_T fzp_x_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/fzp_x'
                                        */
  real_T fzp_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/fzp_x'
                                        */
  real_T fzp_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/fzp_x'
                                        */
  real_T fzp_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/fzp_x'
                                        */
  real_T fzp_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/fzp_x'
                                        */
  real_T fzp_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/fzp_x'
                                        */
  real_T fzp_y_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/fzp_y'
                                        */
  real_T fzp_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/fzp_y'
                                        */
  real_T fzp_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/fzp_y'
                                        */
  real_T fzp_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/fzp_y'
                                        */
  real_T fzp_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/fzp_y'
                                        */
  real_T fzp_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/fzp_y'
                                        */
  real_T r_max_P1;                     /* Expression: width
                                        * Referenced by: '<S1>/r_max'
                                        */
  real_T r_max_P2;                     /* Expression: dtype
                                        * Referenced by: '<S1>/r_max'
                                        */
  real_T r_max_P3;                     /* Expression: portnum
                                        * Referenced by: '<S1>/r_max'
                                        */
  real_T r_max_P4;                     /* Expression: stime
                                        * Referenced by: '<S1>/r_max'
                                        */
  real_T r_max_P5;                     /* Expression: stype
                                        * Referenced by: '<S1>/r_max'
                                        */
  real_T r_max_P6;                     /* Expression: btype
                                        * Referenced by: '<S1>/r_max'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S13>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S13>/Transfer Fcn2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1e10
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1e10
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Gain_Gain_p;                  /* Expression: pi
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Constant_Value_k;             /* Expression: 2*pi
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T SP_P1;                        /* Expression: width
                                        * Referenced by: '<S6>/SP'
                                        */
  real_T SP_P2;                        /* Expression: dtype
                                        * Referenced by: '<S6>/SP'
                                        */
  real_T SP_P3;                        /* Expression: portnum
                                        * Referenced by: '<S6>/SP'
                                        */
  real_T SP_P4;                        /* Expression: stime
                                        * Referenced by: '<S6>/SP'
                                        */
  real_T SP_P5;                        /* Expression: stype
                                        * Referenced by: '<S6>/SP'
                                        */
  real_T SP_P6;                        /* Expression: btype
                                        * Referenced by: '<S6>/SP'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S12>/Integrator1'
                                        */
  real_T Gain1_Gain[9];                /* Expression: 2*lambda*w_o
                                        * Referenced by: '<S12>/Gain1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S12>/Integrator2'
                                        */
  real_T Gain2_Gain[9];                /* Expression: w_o*w_o
                                        * Referenced by: '<S12>/Gain2'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S12>/Integrator3'
                                        */
  real_T Gain3_Gain[9];                /* Expression: inv(M)
                                        * Referenced by: '<S12>/Gain3'
                                        */
  real_T K11_Gain[9];                  /* Expression: -2*(eye(3)-lambda)*diag([w_c(1,1)/w_o(1,1) w_c(2,2)/w_o(2,2) w_c(3,3)/w_o(3,3)])
                                        * Referenced by: '<S12>/K11'
                                        */
  real_T K12_Gain[9];                  /* Expression: 2*w_o*(eye(3)-lambda)
                                        * Referenced by: '<S12>/K12'
                                        */
  real_T invT_b_Gain[9];               /* Expression: diag([1/T_b(1,1) 1/T_b(2,2) 1/T_b(3,3)])
                                        * Referenced by: '<S12>/inv(T_b)'
                                        */
  real_T Constant1_Value_p;            /* Expression: pi
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T Gain_Gain_d[4];               /* Expression: diag([1/(1/sqrt(90)) 1/(1/sqrt(90))])
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Gain1_Gain_i[4];              /* Expression: diag([1/(1/sqrt(90)) 1/(1/sqrt(90))])
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T deg2rad_Gain;                 /* Expression: pi/180
                                        * Referenced by: '<S1>/deg2rad'
                                        */
  real_T Constant_Value_hs[3];         /* Expression: [0 0 0]
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Gain_Gain_l[3];               /* Expression: [1 1 0]'
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T tau_des_P1;                   /* Expression: width
                                        * Referenced by: '<S6>/tau_des'
                                        */
  real_T tau_des_P2;                   /* Expression: dtype
                                        * Referenced by: '<S6>/tau_des'
                                        */
  real_T tau_des_P3;                   /* Expression: portnum
                                        * Referenced by: '<S6>/tau_des'
                                        */
  real_T tau_des_P4;                   /* Expression: stime
                                        * Referenced by: '<S6>/tau_des'
                                        */
  real_T tau_des_P5;                   /* Expression: stype
                                        * Referenced by: '<S6>/tau_des'
                                        */
  real_T tau_des_P6;                   /* Expression: btype
                                        * Referenced by: '<S6>/tau_des'
                                        */
  real_T thr_angle_1_P1;               /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  real_T thr_angle_1_P2;               /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  real_T thr_angle_1_P3;               /* Expression: portnum
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  real_T thr_angle_1_P4;               /* Expression: stime
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  real_T thr_angle_1_P5;               /* Expression: stype
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  real_T thr_angle_1_P6;               /* Expression: btype
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  real_T thr_angle_2_P1;               /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  real_T thr_angle_2_P2;               /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  real_T thr_angle_2_P3;               /* Expression: portnum
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  real_T thr_angle_2_P4;               /* Expression: stime
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  real_T thr_angle_2_P5;               /* Expression: stype
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  real_T thr_angle_2_P6;               /* Expression: btype
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  real_T thr_angle_3_P1;               /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_3'
                                        */
  real_T thr_angle_3_P2;               /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_3'
                                        */
  real_T thr_angle_3_P3;               /* Expression: portnum
                                        * Referenced by: '<S9>/thr_angle_3'
                                        */
  real_T thr_angle_3_P4;               /* Expression: stime
                                        * Referenced by: '<S9>/thr_angle_3'
                                        */
  real_T thr_angle_3_P5;               /* Expression: stype
                                        * Referenced by: '<S9>/thr_angle_3'
                                        */
  real_T thr_angle_3_P6;               /* Expression: btype
                                        * Referenced by: '<S9>/thr_angle_3'
                                        */
  real_T thr_angle_4_P1;               /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_4'
                                        */
  real_T thr_angle_4_P2;               /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_4'
                                        */
  real_T thr_angle_4_P3;               /* Expression: portnum
                                        * Referenced by: '<S9>/thr_angle_4'
                                        */
  real_T thr_angle_4_P4;               /* Expression: stime
                                        * Referenced by: '<S9>/thr_angle_4'
                                        */
  real_T thr_angle_4_P5;               /* Expression: stype
                                        * Referenced by: '<S9>/thr_angle_4'
                                        */
  real_T thr_angle_4_P6;               /* Expression: btype
                                        * Referenced by: '<S9>/thr_angle_4'
                                        */
  real_T thr_angle_5_P1;               /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_5'
                                        */
  real_T thr_angle_5_P2;               /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_5'
                                        */
  real_T thr_angle_5_P3;               /* Expression: portnum
                                        * Referenced by: '<S9>/thr_angle_5'
                                        */
  real_T thr_angle_5_P4;               /* Expression: stime
                                        * Referenced by: '<S9>/thr_angle_5'
                                        */
  real_T thr_angle_5_P5;               /* Expression: stype
                                        * Referenced by: '<S9>/thr_angle_5'
                                        */
  real_T thr_angle_5_P6;               /* Expression: btype
                                        * Referenced by: '<S9>/thr_angle_5'
                                        */
  real_T thr_angle_6_P1;               /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_6'
                                        */
  real_T thr_angle_6_P2;               /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_6'
                                        */
  real_T thr_angle_6_P3;               /* Expression: portnum
                                        * Referenced by: '<S9>/thr_angle_6'
                                        */
  real_T thr_angle_6_P4;               /* Expression: stime
                                        * Referenced by: '<S9>/thr_angle_6'
                                        */
  real_T thr_angle_6_P5;               /* Expression: stype
                                        * Referenced by: '<S9>/thr_angle_6'
                                        */
  real_T thr_angle_6_P6;               /* Expression: btype
                                        * Referenced by: '<S9>/thr_angle_6'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S8>/Delay'
                                        */
  uint32_T Delay_DelayLength_d;        /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S35>/Delay'
                                        */
  uint32_T Delay_DelayLength_f;        /* Computed Parameter: Delay_DelayLength_f
                                        * Referenced by: '<S44>/Delay'
                                        */
  uint32_T Delay_DelayLength_m;        /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S36>/Delay'
                                        */
  uint32_T Delay_DelayLength_p;        /* Computed Parameter: Delay_DelayLength_p
                                        * Referenced by: '<S54>/Delay'
                                        */
  uint32_T Delay_DelayLength_h;        /* Computed Parameter: Delay_DelayLength_h
                                        * Referenced by: '<S37>/Delay'
                                        */
  uint32_T Delay_DelayLength_b;        /* Computed Parameter: Delay_DelayLength_b
                                        * Referenced by: '<S64>/Delay'
                                        */
  uint32_T Delay_DelayLength_n;        /* Computed Parameter: Delay_DelayLength_n
                                        * Referenced by: '<S38>/Delay'
                                        */
  uint32_T Delay_DelayLength_mj;       /* Computed Parameter: Delay_DelayLength_mj
                                        * Referenced by: '<S74>/Delay'
                                        */
  uint32_T Delay_DelayLength_a;        /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S39>/Delay'
                                        */
  uint32_T Delay_DelayLength_k;        /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S84>/Delay'
                                        */
  uint32_T Delay_DelayLength_l;        /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S40>/Delay'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S94>/Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_TAPM2_T {
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
    real_T odeY[30];
    real_T odeF[3][30];
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
extern P_ctrl_TAPM2_T ctrl_TAPM2_P;

/* Block signals (auto storage) */
extern B_ctrl_TAPM2_T ctrl_TAPM2_B;

/* Continuous states (auto storage) */
extern X_ctrl_TAPM2_T ctrl_TAPM2_X;

/* Block states (auto storage) */
extern DW_ctrl_TAPM2_T ctrl_TAPM2_DW;

/* Model entry point functions */
extern void ctrl_TAPM2_initialize(void);
extern void ctrl_TAPM2_output(void);
extern void ctrl_TAPM2_update(void);
extern void ctrl_TAPM2_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_TAPM2_rtModel *ctrl_TAPM2(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_TAPM2_T *const ctrl_TAPM2_M;

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
 * '<Root>' : 'ctrl_TAPM2'
 * '<S1>'   : 'ctrl_TAPM2/Input'
 * '<S2>'   : 'ctrl_TAPM2/MATLAB Function'
 * '<S3>'   : 'ctrl_TAPM2/Parameters From initfile distributed '
 * '<S4>'   : 'ctrl_TAPM2/Pos measurements'
 * '<S5>'   : 'ctrl_TAPM2/Radians to Degrees'
 * '<S6>'   : 'ctrl_TAPM2/TAPM Controller w_observer'
 * '<S7>'   : 'ctrl_TAPM2/Thrust allocation1'
 * '<S8>'   : 'ctrl_TAPM2/Thruster control '
 * '<S9>'   : 'ctrl_TAPM2/Thruster measurment'
 * '<S10>'  : 'ctrl_TAPM2/Input/MATLAB Function3'
 * '<S11>'  : 'ctrl_TAPM2/TAPM Controller w_observer/LQR'
 * '<S12>'  : 'ctrl_TAPM2/TAPM Controller w_observer/Non-linear passive observer '
 * '<S13>'  : 'ctrl_TAPM2/TAPM Controller w_observer/SP Generator'
 * '<S14>'  : 'ctrl_TAPM2/TAPM Controller w_observer/[-inf inf] to [-pi pi]1'
 * '<S15>'  : 'ctrl_TAPM2/TAPM Controller w_observer/heading'
 * '<S16>'  : 'ctrl_TAPM2/TAPM Controller w_observer/normalcontrol'
 * '<S17>'  : 'ctrl_TAPM2/TAPM Controller w_observer/surgeswaydampingrestoring'
 * '<S18>'  : 'ctrl_TAPM2/TAPM Controller w_observer/LQR/MATLAB Function'
 * '<S19>'  : 'ctrl_TAPM2/TAPM Controller w_observer/LQR/MATLAB Function1'
 * '<S20>'  : 'ctrl_TAPM2/TAPM Controller w_observer/LQR/MATLAB Function2'
 * '<S21>'  : 'ctrl_TAPM2/TAPM Controller w_observer/LQR/MATLAB Function3'
 * '<S22>'  : 'ctrl_TAPM2/TAPM Controller w_observer/Non-linear passive observer /Rotation matrix in yaw 1'
 * '<S23>'  : 'ctrl_TAPM2/TAPM Controller w_observer/Non-linear passive observer /Transposed rotation  matrix in yaw'
 * '<S24>'  : 'ctrl_TAPM2/TAPM Controller w_observer/Non-linear passive observer /Transposed rotation  matrix in yaw1'
 * '<S25>'  : 'ctrl_TAPM2/TAPM Controller w_observer/SP Generator/Set-Point Limiter'
 * '<S26>'  : 'ctrl_TAPM2/Thrust allocation1/For Each Subsystem'
 * '<S27>'  : 'ctrl_TAPM2/Thrust allocation1/MATLAB Function'
 * '<S28>'  : 'ctrl_TAPM2/Thrust allocation1/MATLAB Function1'
 * '<S29>'  : 'ctrl_TAPM2/Thrust allocation1/Radians to Degrees'
 * '<S30>'  : 'ctrl_TAPM2/Thrust allocation1/For Each Subsystem/Degrees to Radians'
 * '<S31>'  : 'ctrl_TAPM2/Thrust allocation1/For Each Subsystem/MATLAB Function'
 * '<S32>'  : 'ctrl_TAPM2/Thrust allocation1/For Each Subsystem/MATLAB Function1'
 * '<S33>'  : 'ctrl_TAPM2/Thruster control /Subsystem'
 * '<S34>'  : 'ctrl_TAPM2/Thruster control /Subsystem1'
 * '<S35>'  : 'ctrl_TAPM2/Thruster control /Thruster 1'
 * '<S36>'  : 'ctrl_TAPM2/Thruster control /Thruster 2'
 * '<S37>'  : 'ctrl_TAPM2/Thruster control /Thruster 3'
 * '<S38>'  : 'ctrl_TAPM2/Thruster control /Thruster 4'
 * '<S39>'  : 'ctrl_TAPM2/Thruster control /Thruster 5'
 * '<S40>'  : 'ctrl_TAPM2/Thruster control /Thruster 6'
 * '<S41>'  : 'ctrl_TAPM2/Thruster control /Subsystem/MATLAB Function'
 * '<S42>'  : 'ctrl_TAPM2/Thruster control /Thruster 1/Propeller Hydrodynamics'
 * '<S43>'  : 'ctrl_TAPM2/Thruster control /Thruster 1/Shaft dynamics'
 * '<S44>'  : 'ctrl_TAPM2/Thruster control /Thruster 1/Thruster control'
 * '<S45>'  : 'ctrl_TAPM2/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S46>'  : 'ctrl_TAPM2/Thruster control /Thruster 1/Thruster control/Core controller'
 * '<S47>'  : 'ctrl_TAPM2/Thruster control /Thruster 1/Thruster control/Discrete Derivative'
 * '<S48>'  : 'ctrl_TAPM2/Thruster control /Thruster 1/Thruster control/MATLAB Function'
 * '<S49>'  : 'ctrl_TAPM2/Thruster control /Thruster 1/Thruster control/Supervisor'
 * '<S50>'  : 'ctrl_TAPM2/Thruster control /Thruster 1/Thruster control/Torque limit'
 * '<S51>'  : 'ctrl_TAPM2/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S52>'  : 'ctrl_TAPM2/Thruster control /Thruster 2/Propeller Hydrodynamics'
 * '<S53>'  : 'ctrl_TAPM2/Thruster control /Thruster 2/Shaft dynamics'
 * '<S54>'  : 'ctrl_TAPM2/Thruster control /Thruster 2/Thruster control'
 * '<S55>'  : 'ctrl_TAPM2/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S56>'  : 'ctrl_TAPM2/Thruster control /Thruster 2/Thruster control/Core controller'
 * '<S57>'  : 'ctrl_TAPM2/Thruster control /Thruster 2/Thruster control/Discrete Derivative'
 * '<S58>'  : 'ctrl_TAPM2/Thruster control /Thruster 2/Thruster control/MATLAB Function'
 * '<S59>'  : 'ctrl_TAPM2/Thruster control /Thruster 2/Thruster control/Supervisor'
 * '<S60>'  : 'ctrl_TAPM2/Thruster control /Thruster 2/Thruster control/Torque limit'
 * '<S61>'  : 'ctrl_TAPM2/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S62>'  : 'ctrl_TAPM2/Thruster control /Thruster 3/Propeller Hydrodynamics'
 * '<S63>'  : 'ctrl_TAPM2/Thruster control /Thruster 3/Shaft dynamics'
 * '<S64>'  : 'ctrl_TAPM2/Thruster control /Thruster 3/Thruster control'
 * '<S65>'  : 'ctrl_TAPM2/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S66>'  : 'ctrl_TAPM2/Thruster control /Thruster 3/Thruster control/Core controller'
 * '<S67>'  : 'ctrl_TAPM2/Thruster control /Thruster 3/Thruster control/Discrete Derivative'
 * '<S68>'  : 'ctrl_TAPM2/Thruster control /Thruster 3/Thruster control/MATLAB Function'
 * '<S69>'  : 'ctrl_TAPM2/Thruster control /Thruster 3/Thruster control/Supervisor'
 * '<S70>'  : 'ctrl_TAPM2/Thruster control /Thruster 3/Thruster control/Torque limit'
 * '<S71>'  : 'ctrl_TAPM2/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S72>'  : 'ctrl_TAPM2/Thruster control /Thruster 4/Propeller Hydrodynamics'
 * '<S73>'  : 'ctrl_TAPM2/Thruster control /Thruster 4/Shaft dynamics'
 * '<S74>'  : 'ctrl_TAPM2/Thruster control /Thruster 4/Thruster control'
 * '<S75>'  : 'ctrl_TAPM2/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S76>'  : 'ctrl_TAPM2/Thruster control /Thruster 4/Thruster control/Core controller'
 * '<S77>'  : 'ctrl_TAPM2/Thruster control /Thruster 4/Thruster control/Discrete Derivative'
 * '<S78>'  : 'ctrl_TAPM2/Thruster control /Thruster 4/Thruster control/MATLAB Function'
 * '<S79>'  : 'ctrl_TAPM2/Thruster control /Thruster 4/Thruster control/Supervisor'
 * '<S80>'  : 'ctrl_TAPM2/Thruster control /Thruster 4/Thruster control/Torque limit'
 * '<S81>'  : 'ctrl_TAPM2/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S82>'  : 'ctrl_TAPM2/Thruster control /Thruster 5/Propeller Hydrodynamics'
 * '<S83>'  : 'ctrl_TAPM2/Thruster control /Thruster 5/Shaft dynamics'
 * '<S84>'  : 'ctrl_TAPM2/Thruster control /Thruster 5/Thruster control'
 * '<S85>'  : 'ctrl_TAPM2/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S86>'  : 'ctrl_TAPM2/Thruster control /Thruster 5/Thruster control/Core controller'
 * '<S87>'  : 'ctrl_TAPM2/Thruster control /Thruster 5/Thruster control/Discrete Derivative'
 * '<S88>'  : 'ctrl_TAPM2/Thruster control /Thruster 5/Thruster control/MATLAB Function'
 * '<S89>'  : 'ctrl_TAPM2/Thruster control /Thruster 5/Thruster control/Supervisor'
 * '<S90>'  : 'ctrl_TAPM2/Thruster control /Thruster 5/Thruster control/Torque limit'
 * '<S91>'  : 'ctrl_TAPM2/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S92>'  : 'ctrl_TAPM2/Thruster control /Thruster 6/Propeller Hydrodynamics'
 * '<S93>'  : 'ctrl_TAPM2/Thruster control /Thruster 6/Shaft dynamics'
 * '<S94>'  : 'ctrl_TAPM2/Thruster control /Thruster 6/Thruster control'
 * '<S95>'  : 'ctrl_TAPM2/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S96>'  : 'ctrl_TAPM2/Thruster control /Thruster 6/Thruster control/Core controller'
 * '<S97>'  : 'ctrl_TAPM2/Thruster control /Thruster 6/Thruster control/Discrete Derivative'
 * '<S98>'  : 'ctrl_TAPM2/Thruster control /Thruster 6/Thruster control/MATLAB Function'
 * '<S99>'  : 'ctrl_TAPM2/Thruster control /Thruster 6/Thruster control/Supervisor'
 * '<S100>' : 'ctrl_TAPM2/Thruster control /Thruster 6/Thruster control/Torque limit'
 * '<S101>' : 'ctrl_TAPM2/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 */
#endif                                 /* RTW_HEADER_ctrl_TAPM2_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_TAPM2
 * Model version : 1.39
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Sun May 15 13:28:12 2016
 *========================================================================*/
#ifdef NI_ROOTMODEL_ctrl_TAPM2

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* ctrl_TAPM2.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_ctrl_TAPM2_T rtParameter[NUMST+!TID01EQ];
P_ctrl_TAPM2_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_ctrl_TAPM2_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_ctrl_TAPM2_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_ctrl_TAPM2_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
