/*
 * Thrustallocation_test.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Thrustallocation_test".
 *
 * Model version              : 1.10
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Jun 17 16:52:41 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Thrustallocation_test_h_
#define RTW_HEADER_Thrustallocation_test_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Thrustallocation_test_COMMON_INCLUDES_
# define Thrustallocation_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* Thrustallocation_test_COMMON_INCLUDES_ */

#include "Thrustallocation_test_types.h"

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
#define Thrustallocation_test_rtModel  RT_MODEL_Thrustallocation_tes_T

/* Block signals for system '<S12>/CoreSubsys' */
typedef struct {
  real_T angle;                        /* '<S12>/Discrete-Time Integrator' */
  real_T Delay;                        /* '<S12>/Delay' */
  real_T MaxRotationRate;              /* '<S12>/Max Rotation Rate' */
} B_CoreSubsys_Thrustallocation_T;

/* Block states (auto storage) for system '<S12>/CoreSubsys' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S12>/Discrete-Time Integrator' */
  real_T Delay_DSTATE;                 /* '<S12>/Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S12>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S12>/Discrete-Time Integrator' */
} DW_CoreSubsys_Thrustallocatio_T;

/* Block signals for system '<S27>/Actual Force and Torque' */
typedef struct {
  real_T Ta;                           /* '<S27>/Actual Force and Torque' */
  real_T Qa;                           /* '<S27>/Actual Force and Torque' */
} B_ActualForceandTorque_Thrust_T;

/* Block signals for system '<S31>/Core controller: Torque,Power and Combined Torque//Power' */
typedef struct {
  real_T Qcq;                          /* '<S31>/Core controller: Torque,Power and Combined Torque//Power' */
  real_T Qcp;                          /* '<S31>/Core controller: Torque,Power and Combined Torque//Power' */
  real_T Qcc;                          /* '<S31>/Core controller: Torque,Power and Combined Torque//Power' */
} B_CorecontrollerTorquePoweran_T;

/* Block signals for system '<S29>/Supervisor' */
typedef struct {
  real_T u;                            /* '<S29>/Supervisor' */
} B_Supervisor_Thrustallocation_T;

/* Block signals for system '<S38>/MATLAB Function' */
typedef struct {
  real_T n_d;                          /* '<S38>/MATLAB Function' */
  real_T T_r;                          /* '<S38>/MATLAB Function' */
} B_MATLABFunction_Thrustalloca_T;

/* Block signals (auto storage) */
typedef struct {
  real_T reset;                        /* '<S28>/reset' */
  real_T reset_e;                      /* '<S37>/reset' */
  real_T reset_l;                      /* '<S46>/reset' */
  real_T reset_o;                      /* '<S55>/reset' */
  real_T reset_k;                      /* '<S64>/reset' */
  real_T reset_km;                     /* '<S73>/reset' */
  real_T core_controller;              /* '<Root>/core_controller' */
  real_T Uk1;                          /* '<S81>/Delay Input1' */
  real_T ArrowUp;                      /* '<Root>/ArrowUp' */
  real_T Uk1_m;                        /* '<S82>/Delay Input1' */
  real_T ArrowDown;                    /* '<Root>/ArrowDown' */
  real_T Uk1_h;                        /* '<S83>/Delay Input1' */
  real_T Start;                        /* '<Root>/Start' */
  real_T Memory;                       /* '<S9>/Memory' */
  real_T L2_continuous;                /* '<Root>/L2_continuous' */
  real_T thr_angle_1;                  /* '<S6>/thr_angle_1' */
  real_T thr_angle_2;                  /* '<S6>/thr_angle_2' */
  real_T thr_angle_3;                  /* '<S6>/thr_angle_3' */
  real_T thr_angle_4;                  /* '<S6>/thr_angle_4' */
  real_T thr_angle_5;                  /* '<S6>/thr_angle_5' */
  real_T thr_angle_6;                  /* '<S6>/thr_angle_6' */
  real_T PosYLeft;                     /* '<Root>/PosYLeft' */
  real_T Product1;                     /* '<Root>/Product1' */
  real_T PosXLeft;                     /* '<Root>/PosXLeft' */
  real_T Product2;                     /* '<Root>/Product2' */
  real_T R2_continuous;                /* '<Root>/R2_continuous' */
  real_T Product;                      /* '<Root>/Product' */
  real_T Angle_controller;             /* '<S4>/Angle_controller' */
  real_T fmin[6];                      /* '<S4>/fmin' */
  real_T ChoosingFixedAzimuthangle[6]; /* '<S4>/Choosing Fixed // Azimuth angle' */
  real_T reset_c[6];                   /* '<Root>/reset' */
  real_T Gain[6];                      /* '<S3>/Gain' */
  real_T Constant1[3];                 /* '<Root>/Constant1' */
  real_T Delay[6];                     /* '<S5>/Delay' */
  real_T Delay_l;                      /* '<S20>/Delay' */
  real_T Delay_d;                      /* '<S29>/Delay' */
  real_T DiscreteTransferFcn;          /* '<S29>/Discrete Transfer Fcn' */
  real_T TSamp;                        /* '<S32>/TSamp' */
  real_T Inertiacompensation;          /* '<S29>/Inertia compensation' */
  real_T Sum1;                         /* '<S29>/Sum1' */
  real_T Memory_f;                     /* '<S29>/Memory' */
  real_T Kp;                           /* '<S31>/Kp' */
  real_T reset_j;                      /* '<S31>/reset' */
  real_T Sum;                          /* '<S29>/Sum' */
  real_T DiscreteTransferFcn_a;        /* '<S20>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed;         /* '<S28>/Finding rotation speed' */
  real_T Ki;                           /* '<S31>/Ki' */
  real_T Delay_j;                      /* '<S21>/Delay' */
  real_T Delay_jf;                     /* '<S38>/Delay' */
  real_T DiscreteTransferFcn_d;        /* '<S38>/Discrete Transfer Fcn' */
  real_T TSamp_d;                      /* '<S41>/TSamp' */
  real_T Inertiacompensation_a;        /* '<S38>/Inertia compensation' */
  real_T Sum1_f;                       /* '<S38>/Sum1' */
  real_T Memory_a;                     /* '<S38>/Memory' */
  real_T Kp_c;                         /* '<S40>/Kp' */
  real_T reset_i;                      /* '<S40>/reset' */
  real_T Sum_i;                        /* '<S38>/Sum' */
  real_T DiscreteTransferFcn_l;        /* '<S21>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_k;       /* '<S37>/Finding rotation speed' */
  real_T Ki_h;                         /* '<S40>/Ki' */
  real_T Delay_i;                      /* '<S22>/Delay' */
  real_T Delay_c;                      /* '<S47>/Delay' */
  real_T DiscreteTransferFcn_k;        /* '<S47>/Discrete Transfer Fcn' */
  real_T TSamp_f;                      /* '<S50>/TSamp' */
  real_T Inertiacompensation_j;        /* '<S47>/Inertia compensation' */
  real_T Sum1_b;                       /* '<S47>/Sum1' */
  real_T Memory_n;                     /* '<S47>/Memory' */
  real_T Kp_j;                         /* '<S49>/Kp' */
  real_T reset_e3;                     /* '<S49>/reset' */
  real_T Sum_o;                        /* '<S47>/Sum' */
  real_T DiscreteTransferFcn_o;        /* '<S22>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_j;       /* '<S46>/Finding rotation speed' */
  real_T Ki_e;                         /* '<S49>/Ki' */
  real_T Delay_g;                      /* '<S23>/Delay' */
  real_T Delay_m;                      /* '<S56>/Delay' */
  real_T DiscreteTransferFcn_ox;       /* '<S56>/Discrete Transfer Fcn' */
  real_T TSamp_j;                      /* '<S59>/TSamp' */
  real_T Inertiacompensation_jx;       /* '<S56>/Inertia compensation' */
  real_T Sum1_k;                       /* '<S56>/Sum1' */
  real_T Memory_aw;                    /* '<S56>/Memory' */
  real_T Kp_m;                         /* '<S58>/Kp' */
  real_T reset_j4;                     /* '<S58>/reset' */
  real_T Sum_j;                        /* '<S56>/Sum' */
  real_T DiscreteTransferFcn_c;        /* '<S23>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_n;       /* '<S55>/Finding rotation speed' */
  real_T Ki_j;                         /* '<S58>/Ki' */
  real_T Delay_f;                      /* '<S24>/Delay' */
  real_T Delay_fl;                     /* '<S65>/Delay' */
  real_T DiscreteTransferFcn_f;        /* '<S65>/Discrete Transfer Fcn' */
  real_T TSamp_n;                      /* '<S68>/TSamp' */
  real_T Inertiacompensation_o;        /* '<S65>/Inertia compensation' */
  real_T Sum1_c;                       /* '<S65>/Sum1' */
  real_T Memory_i;                     /* '<S65>/Memory' */
  real_T Kp_a;                         /* '<S67>/Kp' */
  real_T reset_p;                      /* '<S67>/reset' */
  real_T Sum_n;                        /* '<S65>/Sum' */
  real_T DiscreteTransferFcn_e;        /* '<S24>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_j0;      /* '<S64>/Finding rotation speed' */
  real_T Ki_jy;                        /* '<S67>/Ki' */
  real_T Delay_cn;                     /* '<S25>/Delay' */
  real_T Delay_n;                      /* '<S74>/Delay' */
  real_T DiscreteTransferFcn_h;        /* '<S74>/Discrete Transfer Fcn' */
  real_T TSamp_k;                      /* '<S77>/TSamp' */
  real_T Inertiacompensation_g;        /* '<S74>/Inertia compensation' */
  real_T Sum1_a;                       /* '<S74>/Sum1' */
  real_T Memory_o;                     /* '<S74>/Memory' */
  real_T Kp_me;                        /* '<S76>/Kp' */
  real_T reset_en;                     /* '<S76>/reset' */
  real_T Sum_id;                       /* '<S74>/Sum' */
  real_T DiscreteTransferFcn_p;        /* '<S25>/Discrete Transfer Fcn' */
  real_T Findingrotationspeed_h;       /* '<S73>/Finding rotation speed' */
  real_T Ki_k;                         /* '<S76>/Ki' */
  real_T TmpSignalConversionAtDelayInpor[6];/* '<S5>/Thrust and Shaft speed mapped to PWM' */
  real_T y;                            /* '<S9>/MATLAB Function' */
  real_T nu_dot[3];                    /* '<Root>/kinetics' */
  real_T eta_dot[3];                   /* '<Root>/kinematics' */
  real_T n_d;                          /* '<S74>/MATLAB Function' */
  real_T n_d_d;                        /* '<S29>/MATLAB Function' */
  real_T output[12];                   /* '<S19>/MATLAB Function' */
  real_T A1Matrix[9];                  /* '<S4>/MATLAB Function1' */
  real_T A2Matrix[9];                  /* '<S4>/MATLAB Function1' */
  real_T A3Matrix[9];                  /* '<S4>/MATLAB Function1' */
  real_T BMatrix[3];                   /* '<S4>/MATLAB Function1' */
  real_T commanded_tau[3];             /* '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */
  B_Supervisor_Thrustallocation_T sf_Supervisor_g;/* '<S74>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_f;/* '<S76>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_Thrust_T sf_ActualForceandTorque_n;/* '<S72>/Actual Force and Torque' */
  B_Supervisor_Thrustallocation_T sf_Supervisor_mw;/* '<S65>/Supervisor' */
  B_MATLABFunction_Thrustalloca_T sf_MATLABFunction_h;/* '<S65>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_i;/* '<S67>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_Thrust_T sf_ActualForceandTorque_m;/* '<S63>/Actual Force and Torque' */
  B_Supervisor_Thrustallocation_T sf_Supervisor_m;/* '<S56>/Supervisor' */
  B_MATLABFunction_Thrustalloca_T sf_MATLABFunction_f;/* '<S56>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_e;/* '<S58>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_Thrust_T sf_ActualForceandTorque_b;/* '<S54>/Actual Force and Torque' */
  B_Supervisor_Thrustallocation_T sf_Supervisor_b;/* '<S47>/Supervisor' */
  B_MATLABFunction_Thrustalloca_T sf_MATLABFunction_da;/* '<S47>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_j;/* '<S49>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_Thrust_T sf_ActualForceandTorque_g;/* '<S45>/Actual Force and Torque' */
  B_Supervisor_Thrustallocation_T sf_Supervisor_p;/* '<S38>/Supervisor' */
  B_MATLABFunction_Thrustalloca_T sf_MATLABFunction_a;/* '<S38>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_g;/* '<S40>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_Thrust_T sf_ActualForceandTorque_k;/* '<S36>/Actual Force and Torque' */
  B_Supervisor_Thrustallocation_T sf_Supervisor;/* '<S29>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowerand;/* '<S31>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_Thrust_T sf_ActualForceandTorque;/* '<S27>/Actual Force and Torque' */
  B_CoreSubsys_Thrustallocation_T CoreSubsys[6];/* '<S12>/CoreSubsys' */
} B_Thrustallocation_test_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S81>/Delay Input1' */
  real_T DelayInput1_DSTATE_d;         /* '<S82>/Delay Input1' */
  real_T DelayInput1_DSTATE_c;         /* '<S83>/Delay Input1' */
  real_T Delay_DSTATE[6];              /* '<S5>/Delay' */
  real_T Delay_DSTATE_l;               /* '<S20>/Delay' */
  real_T Delay_DSTATE_g;               /* '<S29>/Delay' */
  real_T DiscreteTransferFcn_states[2];/* '<S29>/Discrete Transfer Fcn' */
  real_T UD_DSTATE;                    /* '<S32>/UD' */
  real_T DiscreteTransferFcn_states_o; /* '<S20>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_c;               /* '<S21>/Delay' */
  real_T Delay_DSTATE_i;               /* '<S38>/Delay' */
  real_T DiscreteTransferFcn_states_f[2];/* '<S38>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_a;                  /* '<S41>/UD' */
  real_T DiscreteTransferFcn_states_a; /* '<S21>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_p;               /* '<S22>/Delay' */
  real_T Delay_DSTATE_f;               /* '<S47>/Delay' */
  real_T DiscreteTransferFcn_states_m[2];/* '<S47>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_j;                  /* '<S50>/UD' */
  real_T DiscreteTransferFcn_states_d; /* '<S22>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_ce;              /* '<S23>/Delay' */
  real_T Delay_DSTATE_h;               /* '<S56>/Delay' */
  real_T DiscreteTransferFcn_states_j[2];/* '<S56>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_c;                  /* '<S59>/UD' */
  real_T DiscreteTransferFcn_states_e; /* '<S23>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_m;               /* '<S24>/Delay' */
  real_T Delay_DSTATE_k;               /* '<S65>/Delay' */
  real_T DiscreteTransferFcn_states_du[2];/* '<S65>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_n;                  /* '<S68>/UD' */
  real_T DiscreteTransferFcn_states_fv;/* '<S24>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_cy;              /* '<S25>/Delay' */
  real_T Delay_DSTATE_n;               /* '<S74>/Delay' */
  real_T DiscreteTransferFcn_states_jo[2];/* '<S74>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_f;                  /* '<S77>/UD' */
  real_T DiscreteTransferFcn_states_df;/* '<S25>/Discrete Transfer Fcn' */
  real_T reset_DWORK1;                 /* '<S28>/reset' */
  real_T reset_DWORK1_k;               /* '<S37>/reset' */
  real_T reset_DWORK1_o;               /* '<S46>/reset' */
  real_T reset_DWORK1_f;               /* '<S55>/reset' */
  real_T reset_DWORK1_i;               /* '<S64>/reset' */
  real_T reset_DWORK1_j;               /* '<S73>/reset' */
  real_T core_controller_DWORK1;       /* '<Root>/core_controller' */
  real_T ArrowUp_DWORK1;               /* '<Root>/ArrowUp' */
  real_T ArrowDown_DWORK1;             /* '<Root>/ArrowDown' */
  real_T Start_DWORK1;                 /* '<Root>/Start' */
  real_T Memory_PreviousInput;         /* '<S9>/Memory' */
  real_T L2_continuous_DWORK1;         /* '<Root>/L2_continuous' */
  real_T thr_angle_1_DWORK1;           /* '<S6>/thr_angle_1' */
  real_T thr_angle_2_DWORK1;           /* '<S6>/thr_angle_2' */
  real_T thr_angle_3_DWORK1;           /* '<S6>/thr_angle_3' */
  real_T thr_angle_4_DWORK1;           /* '<S6>/thr_angle_4' */
  real_T thr_angle_5_DWORK1;           /* '<S6>/thr_angle_5' */
  real_T thr_angle_6_DWORK1;           /* '<S6>/thr_angle_6' */
  real_T PosYLeft_DWORK1;              /* '<Root>/PosYLeft' */
  real_T PosXLeft_DWORK1;              /* '<Root>/PosXLeft' */
  real_T R2_continuous_DWORK1;         /* '<Root>/R2_continuous' */
  real_T Angle_controller_DWORK1;      /* '<S4>/Angle_controller' */
  real_T A1Matrix_DWORK1[9];           /* '<S4>/A1Matrix ' */
  real_T fmin_DWORK1[6];               /* '<S4>/fmin' */
  real_T A2Matrix_DWORK1[9];           /* '<S4>/A2Matrix' */
  real_T A3Matrix_DWORK1[9];           /* '<S4>/A3Matrix' */
  real_T BMatrix_DWORK1[3];            /* '<S4>/BMatrix' */
  real_T reset_DWORK1_iq[6];           /* '<Root>/reset' */
  real_T tau_actual_DWORK1[3];         /* '<Root>/tau_actual' */
  real_T N_DWORK1;                     /* '<Root>/N' */
  real_T X_DWORK1;                     /* '<Root>/X' */
  real_T Y_DWORK1;                     /* '<Root>/Y' */
  real_T u_limit_DWORK1;               /* '<Root>/u_limit' */
  real_T DiscreteTransferFcn_tmp;      /* '<S29>/Discrete Transfer Fcn' */
  real_T PrevY;                        /* '<S29>/Acceleration Limit' */
  real_T Memory_PreviousInput_d;       /* '<S29>/Memory' */
  real_T reset_DWORK1_b;               /* '<S31>/reset' */
  real_T DiscreteTransferFcn_tmp_d;    /* '<S20>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_l;    /* '<S38>/Discrete Transfer Fcn' */
  real_T PrevY_i;                      /* '<S38>/Acceleration Limit' */
  real_T Memory_PreviousInput_c;       /* '<S38>/Memory' */
  real_T reset_DWORK1_m;               /* '<S40>/reset' */
  real_T DiscreteTransferFcn_tmp_c;    /* '<S21>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_i;    /* '<S47>/Discrete Transfer Fcn' */
  real_T PrevY_o;                      /* '<S47>/Acceleration limiter' */
  real_T Memory_PreviousInput_l;       /* '<S47>/Memory' */
  real_T reset_DWORK1_oc;              /* '<S49>/reset' */
  real_T DiscreteTransferFcn_tmp_ll;   /* '<S22>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_p;    /* '<S56>/Discrete Transfer Fcn' */
  real_T PrevY_a;                      /* '<S56>/Acceleration limiter' */
  real_T Memory_PreviousInput_a;       /* '<S56>/Memory' */
  real_T reset_DWORK1_a;               /* '<S58>/reset' */
  real_T DiscreteTransferFcn_tmp_o;    /* '<S23>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_c3;   /* '<S65>/Discrete Transfer Fcn' */
  real_T PrevY_m;                      /* '<S65>/Acceleration limiter' */
  real_T Memory_PreviousInput_f;       /* '<S65>/Memory' */
  real_T reset_DWORK1_f4;              /* '<S67>/reset' */
  real_T DiscreteTransferFcn_tmp_k;    /* '<S24>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_a;    /* '<S74>/Discrete Transfer Fcn' */
  real_T PrevY_f;                      /* '<S74>/Acceleration limiter' */
  real_T Memory_PreviousInput_k;       /* '<S74>/Memory' */
  real_T reset_DWORK1_c;               /* '<S76>/reset' */
  real_T DiscreteTransferFcn_tmp_ov;   /* '<S25>/Discrete Transfer Fcn' */
  struct {
    int_T IcNeedsLoading;
  } Position_IWORK;                    /* '<Root>/Position' */

  uint8_T reset_DWORK2[22];            /* '<S28>/reset' */
  uint8_T reset_DWORK2_g[22];          /* '<S37>/reset' */
  uint8_T reset_DWORK2_k[22];          /* '<S46>/reset' */
  uint8_T reset_DWORK2_ga[22];         /* '<S55>/reset' */
  uint8_T reset_DWORK2_b[22];          /* '<S64>/reset' */
  uint8_T reset_DWORK2_f[22];          /* '<S73>/reset' */
  uint8_T core_controller_DWORK2[22];  /* '<Root>/core_controller' */
  uint8_T ArrowUp_DWORK2[22];          /* '<Root>/ArrowUp' */
  uint8_T ArrowDown_DWORK2[22];        /* '<Root>/ArrowDown' */
  uint8_T Start_DWORK2[22];            /* '<Root>/Start' */
  uint8_T L2_continuous_DWORK2[22];    /* '<Root>/L2_continuous' */
  uint8_T thr_angle_1_DWORK2[22];      /* '<S6>/thr_angle_1' */
  uint8_T thr_angle_2_DWORK2[22];      /* '<S6>/thr_angle_2' */
  uint8_T thr_angle_3_DWORK2[22];      /* '<S6>/thr_angle_3' */
  uint8_T thr_angle_4_DWORK2[22];      /* '<S6>/thr_angle_4' */
  uint8_T thr_angle_5_DWORK2[22];      /* '<S6>/thr_angle_5' */
  uint8_T thr_angle_6_DWORK2[22];      /* '<S6>/thr_angle_6' */
  uint8_T PosYLeft_DWORK2[22];         /* '<Root>/PosYLeft' */
  uint8_T PosXLeft_DWORK2[22];         /* '<Root>/PosXLeft' */
  uint8_T R2_continuous_DWORK2[22];    /* '<Root>/R2_continuous' */
  uint8_T Angle_controller_DWORK2[22]; /* '<S4>/Angle_controller' */
  uint8_T A1Matrix_DWORK2[22];         /* '<S4>/A1Matrix ' */
  uint8_T fmin_DWORK2[22];             /* '<S4>/fmin' */
  uint8_T A2Matrix_DWORK2[22];         /* '<S4>/A2Matrix' */
  uint8_T A3Matrix_DWORK2[22];         /* '<S4>/A3Matrix' */
  uint8_T BMatrix_DWORK2[22];          /* '<S4>/BMatrix' */
  uint8_T reset_DWORK2_i[22];          /* '<Root>/reset' */
  uint8_T tau_actual_DWORK2[22];       /* '<Root>/tau_actual' */
  uint8_T N_DWORK2[22];                /* '<Root>/N' */
  uint8_T X_DWORK2[22];                /* '<Root>/X' */
  uint8_T Y_DWORK2[22];                /* '<Root>/Y' */
  uint8_T u_limit_DWORK2[22];          /* '<Root>/u_limit' */
  uint8_T reset_DWORK2_fa[22];         /* '<S31>/reset' */
  uint8_T reset_DWORK2_n[22];          /* '<S40>/reset' */
  uint8_T reset_DWORK2_c[22];          /* '<S49>/reset' */
  uint8_T reset_DWORK2_p[22];          /* '<S58>/reset' */
  uint8_T reset_DWORK2_iu[22];         /* '<S67>/reset' */
  uint8_T reset_DWORK2_o[22];          /* '<S76>/reset' */
  DW_CoreSubsys_Thrustallocatio_T CoreSubsys[6];/* '<S12>/CoreSubsys' */
} DW_Thrustallocation_test_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S28>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S37>/Integrator' */
  real_T Integrator_CSTATE_p;          /* '<S46>/Integrator' */
  real_T Integrator_CSTATE_a;          /* '<S55>/Integrator' */
  real_T Integrator_CSTATE_a0;         /* '<S64>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S73>/Integrator' */
  real_T Position_CSTATE[3];           /* '<Root>/Position' */
  real_T Integrator_CSTATE_j;          /* '<S31>/Integrator' */
  real_T Integrator_CSTATE_jg;         /* '<S40>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S49>/Integrator' */
  real_T Integrator_CSTATE_jz;         /* '<S58>/Integrator' */
  real_T Integrator_CSTATE_ai;         /* '<S67>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S76>/Integrator' */
  real_T Velocity_CSTATE[3];           /* '<Root>/Velocity' */
} X_Thrustallocation_test_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S28>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S37>/Integrator' */
  real_T Integrator_CSTATE_p;          /* '<S46>/Integrator' */
  real_T Integrator_CSTATE_a;          /* '<S55>/Integrator' */
  real_T Integrator_CSTATE_a0;         /* '<S64>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S73>/Integrator' */
  real_T Position_CSTATE[3];           /* '<Root>/Position' */
  real_T Integrator_CSTATE_j;          /* '<S31>/Integrator' */
  real_T Integrator_CSTATE_jg;         /* '<S40>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S49>/Integrator' */
  real_T Integrator_CSTATE_jz;         /* '<S58>/Integrator' */
  real_T Integrator_CSTATE_ai;         /* '<S67>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S76>/Integrator' */
  real_T Velocity_CSTATE[3];           /* '<Root>/Velocity' */
} XDot_Thrustallocation_test_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S28>/Integrator' */
  boolean_T Integrator_CSTATE_o;       /* '<S37>/Integrator' */
  boolean_T Integrator_CSTATE_p;       /* '<S46>/Integrator' */
  boolean_T Integrator_CSTATE_a;       /* '<S55>/Integrator' */
  boolean_T Integrator_CSTATE_a0;      /* '<S64>/Integrator' */
  boolean_T Integrator_CSTATE_d;       /* '<S73>/Integrator' */
  boolean_T Position_CSTATE[3];        /* '<Root>/Position' */
  boolean_T Integrator_CSTATE_j;       /* '<S31>/Integrator' */
  boolean_T Integrator_CSTATE_jg;      /* '<S40>/Integrator' */
  boolean_T Integrator_CSTATE_e;       /* '<S49>/Integrator' */
  boolean_T Integrator_CSTATE_jz;      /* '<S58>/Integrator' */
  boolean_T Integrator_CSTATE_ai;      /* '<S67>/Integrator' */
  boolean_T Integrator_CSTATE_g;       /* '<S76>/Integrator' */
  boolean_T Velocity_CSTATE[3];        /* '<Root>/Velocity' */
} XDis_Thrustallocation_test_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S28>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_b;   /* '<S37>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_m;   /* '<S46>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_d;   /* '<S55>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_g;   /* '<S64>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_f;   /* '<S73>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_c;   /* '<S31>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_j;   /* '<S40>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_d5;  /* '<S49>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_p;   /* '<S58>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_l;   /* '<S67>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_dt;  /* '<S76>/Integrator' */
} PrevZCX_Thrustallocation_test_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            Thrustallocation_test_B
#define BlockIO                        B_Thrustallocation_test_T
#define rtX                            Thrustallocation_test_X
#define ContinuousStates               X_Thrustallocation_test_T
#define rtXdot                         Thrustallocation_test_XDot
#define StateDerivatives               XDot_Thrustallocation_test_T
#define tXdis                          Thrustallocation_test_XDis
#define StateDisabled                  XDis_Thrustallocation_test_T
#define rtP                            Thrustallocation_test_P
#define Parameters                     P_Thrustallocation_test_T
#define rtDWork                        Thrustallocation_test_DW
#define D_Work                         DW_Thrustallocation_test_T
#define rtPrevZCSigState               Thrustallocation_test_PrevZCX
#define PrevZCSigStates                PrevZCX_Thrustallocation_test_T

/* Parameters for system: '<S12>/CoreSubsys' */
struct P_CoreSubsys_Thrustallocation_T_ {
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S12>/Discrete-Time Integrator'
                                         */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S12>/Delay'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S12>/Delay'
                                        */
};

/* Parameters (auto storage) */
struct P_Thrustallocation_test_T_ {
  real_T C[24];                        /* Variable: C
                                        * Referenced by:
                                        *   '<S4>/Constant1'
                                        *   '<S4>/Constant2'
                                        */
  real_T D;                            /* Variable: D
                                        * Referenced by: '<S2>/D'
                                        */
  real_T I_s;                          /* Variable: I_s
                                        * Referenced by:
                                        *   '<S28>/Finding rotation speed'
                                        *   '<S29>/Inertia compensation'
                                        *   '<S37>/Finding rotation speed'
                                        *   '<S38>/Inertia compensation'
                                        *   '<S46>/Finding rotation speed'
                                        *   '<S47>/Inertia compensation'
                                        *   '<S55>/Finding rotation speed'
                                        *   '<S56>/Inertia compensation'
                                        *   '<S64>/Finding rotation speed'
                                        *   '<S65>/Inertia compensation'
                                        *   '<S73>/Finding rotation speed'
                                        *   '<S74>/Inertia compensation'
                                        */
  real_T K_omega;                      /* Variable: K_omega
                                        * Referenced by:
                                        *   '<S28>/K_omega'
                                        *   '<S29>/Qff_1(nr)'
                                        *   '<S37>/K_omega'
                                        *   '<S38>/Qff_1(nr)'
                                        *   '<S46>/K_omega'
                                        *   '<S47>/Qff_1(nr)'
                                        *   '<S55>/K_omega'
                                        *   '<S56>/Qff_1(nr)'
                                        *   '<S64>/K_omega'
                                        *   '<S65>/Qff_1(nr)'
                                        *   '<S73>/K_omega'
                                        *   '<S74>/Qff_1(nr)'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by:
                                        *   '<S31>/Ki'
                                        *   '<S31>/Kp'
                                        *   '<S40>/Ki'
                                        *   '<S40>/Kp'
                                        *   '<S49>/Ki'
                                        *   '<S49>/Kp'
                                        *   '<S58>/Ki'
                                        *   '<S58>/Kp'
                                        *   '<S67>/Ki'
                                        *   '<S67>/Kp'
                                        *   '<S76>/Ki'
                                        *   '<S76>/Kp'
                                        */
  real_T Kq;                           /* Variable: Kq
                                        * Referenced by: '<S2>/Kq'
                                        */
  real_T Kqr;                          /* Variable: Kqr
                                        * Referenced by: '<S2>/Kqr'
                                        */
  real_T Kt;                           /* Variable: Kt
                                        * Referenced by: '<S2>/Kt'
                                        */
  real_T Ktr;                          /* Variable: Ktr
                                        * Referenced by: '<S2>/Ktr'
                                        */
  real_T Max_rotation;                 /* Variable: Max_rotation
                                        * Referenced by: '<S12>/Max Rotation Rate'
                                        */
  real_T Max_thrust;                   /* Variable: Max_thrust
                                        * Referenced by: '<S19>/Saturation 7'
                                        */
  real_T Q_f0;                         /* Variable: Q_f0
                                        * Referenced by:
                                        *   '<S29>/Qf_0'
                                        *   '<S38>/Qf_0'
                                        *   '<S47>/Qf_0'
                                        *   '<S56>/Qf_0'
                                        *   '<S65>/Qf_0'
                                        *   '<S74>/Qf_0'
                                        */
  real_T Rho;                          /* Variable: Rho
                                        * Referenced by: '<S2>/Rho'
                                        */
  real_T eps;                          /* Variable: eps
                                        * Referenced by:
                                        *   '<S2>/Constant4'
                                        *   '<S4>/Constant to avoid singularities'
                                        */
  real_T eps_c;                        /* Variable: eps_c
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T epsilon;                      /* Variable: epsilon
                                        * Referenced by:
                                        *   '<S29>/Qff_0(nr)'
                                        *   '<S38>/Qff_0(nr)'
                                        *   '<S47>/Qff_0(nr)'
                                        *   '<S56>/Qff_0(nr)'
                                        *   '<S65>/Qff_0(nr)'
                                        *   '<S74>/Qff_0(nr)'
                                        */
  real_T k_cc;                         /* Variable: k_cc
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T n_c;                          /* Variable: n_c
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T n_max;                        /* Variable: n_max
                                        * Referenced by:
                                        *   '<S29>/Qff_0(nr)'
                                        *   '<S38>/Qff_0(nr)'
                                        *   '<S47>/Qff_0(nr)'
                                        *   '<S56>/Qff_0(nr)'
                                        *   '<S65>/Qff_0(nr)'
                                        *   '<S74>/Qff_0(nr)'
                                        */
  real_T p_cc;                         /* Variable: p_cc
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T r_cc;                         /* Variable: r_cc
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S32>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_p;/* Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                          * Referenced by: '<S41>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_c;/* Mask Parameter: DiscreteDerivative_ICPrevScal_c
                                          * Referenced by: '<S50>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_e;/* Mask Parameter: DiscreteDerivative_ICPrevScal_e
                                          * Referenced by: '<S59>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_f;/* Mask Parameter: DiscreteDerivative_ICPrevScal_f
                                          * Referenced by: '<S68>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevSca_es;/* Mask Parameter: DiscreteDerivative_ICPrevSca_es
                                          * Referenced by: '<S77>/UD'
                                          */
  real_T DetectIncrease_vinit;         /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S81>/Delay Input1'
                                        */
  real_T DetectIncrease1_vinit;        /* Mask Parameter: DetectIncrease1_vinit
                                        * Referenced by: '<S82>/Delay Input1'
                                        */
  real_T DetectIncrease2_vinit;        /* Mask Parameter: DetectIncrease2_vinit
                                        * Referenced by: '<S83>/Delay Input1'
                                        */
  real_T reset_P1;                     /* Expression: width
                                        * Referenced by: '<S28>/reset'
                                        */
  real_T reset_P2;                     /* Expression: dtype
                                        * Referenced by: '<S28>/reset'
                                        */
  real_T reset_P3;                     /* Expression: portnum
                                        * Referenced by: '<S28>/reset'
                                        */
  real_T reset_P4;                     /* Expression: stime
                                        * Referenced by: '<S28>/reset'
                                        */
  real_T reset_P5;                     /* Expression: stype
                                        * Referenced by: '<S28>/reset'
                                        */
  real_T reset_P6;                     /* Expression: btype
                                        * Referenced by: '<S28>/reset'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S28>/Integrator'
                                        */
  real_T Lossesplaceholder_Value;      /* Expression: 0
                                        * Referenced by: '<S20>/Losses (placeholder)'
                                        */
  real_T reset_P1_g;                   /* Expression: width
                                        * Referenced by: '<S37>/reset'
                                        */
  real_T reset_P2_p;                   /* Expression: dtype
                                        * Referenced by: '<S37>/reset'
                                        */
  real_T reset_P3_i;                   /* Expression: portnum
                                        * Referenced by: '<S37>/reset'
                                        */
  real_T reset_P4_h;                   /* Expression: stime
                                        * Referenced by: '<S37>/reset'
                                        */
  real_T reset_P5_h;                   /* Expression: stype
                                        * Referenced by: '<S37>/reset'
                                        */
  real_T reset_P6_p;                   /* Expression: btype
                                        * Referenced by: '<S37>/reset'
                                        */
  real_T Integrator_IC_c;              /* Expression: 0
                                        * Referenced by: '<S37>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_f;    /* Expression: 0
                                        * Referenced by: '<S21>/Losses (placeholder)'
                                        */
  real_T reset_P1_a;                   /* Expression: width
                                        * Referenced by: '<S46>/reset'
                                        */
  real_T reset_P2_f;                   /* Expression: dtype
                                        * Referenced by: '<S46>/reset'
                                        */
  real_T reset_P3_m;                   /* Expression: portnum
                                        * Referenced by: '<S46>/reset'
                                        */
  real_T reset_P4_g;                   /* Expression: stime
                                        * Referenced by: '<S46>/reset'
                                        */
  real_T reset_P5_l;                   /* Expression: stype
                                        * Referenced by: '<S46>/reset'
                                        */
  real_T reset_P6_j;                   /* Expression: btype
                                        * Referenced by: '<S46>/reset'
                                        */
  real_T Integrator_IC_g;              /* Expression: 0
                                        * Referenced by: '<S46>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_fv;   /* Expression: 0
                                        * Referenced by: '<S22>/Losses (placeholder)'
                                        */
  real_T reset_P1_i;                   /* Expression: width
                                        * Referenced by: '<S55>/reset'
                                        */
  real_T reset_P2_m;                   /* Expression: dtype
                                        * Referenced by: '<S55>/reset'
                                        */
  real_T reset_P3_p;                   /* Expression: portnum
                                        * Referenced by: '<S55>/reset'
                                        */
  real_T reset_P4_f;                   /* Expression: stime
                                        * Referenced by: '<S55>/reset'
                                        */
  real_T reset_P5_f;                   /* Expression: stype
                                        * Referenced by: '<S55>/reset'
                                        */
  real_T reset_P6_b;                   /* Expression: btype
                                        * Referenced by: '<S55>/reset'
                                        */
  real_T Integrator_IC_e;              /* Expression: 0
                                        * Referenced by: '<S55>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_e;    /* Expression: 0
                                        * Referenced by: '<S23>/Losses (placeholder)'
                                        */
  real_T reset_P1_p;                   /* Expression: width
                                        * Referenced by: '<S64>/reset'
                                        */
  real_T reset_P2_h;                   /* Expression: dtype
                                        * Referenced by: '<S64>/reset'
                                        */
  real_T reset_P3_h;                   /* Expression: portnum
                                        * Referenced by: '<S64>/reset'
                                        */
  real_T reset_P4_b;                   /* Expression: stime
                                        * Referenced by: '<S64>/reset'
                                        */
  real_T reset_P5_n;                   /* Expression: stype
                                        * Referenced by: '<S64>/reset'
                                        */
  real_T reset_P6_d;                   /* Expression: btype
                                        * Referenced by: '<S64>/reset'
                                        */
  real_T Integrator_IC_l;              /* Expression: 0
                                        * Referenced by: '<S64>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_a;    /* Expression: 0
                                        * Referenced by: '<S24>/Losses (placeholder)'
                                        */
  real_T reset_P1_c;                   /* Expression: width
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P2_d;                   /* Expression: dtype
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P3_j;                   /* Expression: portnum
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P4_c;                   /* Expression: stime
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P5_e;                   /* Expression: stype
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P6_o;                   /* Expression: btype
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T Integrator_IC_j;              /* Expression: 0
                                        * Referenced by: '<S73>/Integrator'
                                        */
  real_T Lossesplaceholder_Value_i;    /* Expression: 0
                                        * Referenced by: '<S25>/Losses (placeholder)'
                                        */
  real_T Shaftspeedthruster1_Value;    /* Expression: 1
                                        * Referenced by: '<S19>/Shaft speed thruster 1'
                                        */
  real_T Shaftspeedthruster2_Value;    /* Expression: 1
                                        * Referenced by: '<S19>/Shaft speed thruster 2'
                                        */
  real_T Shaftspeedthruster3_Value;    /* Expression: 1
                                        * Referenced by: '<S19>/Shaft speed thruster 3'
                                        */
  real_T Shaftspeedthruster4_Value;    /* Expression: 1
                                        * Referenced by: '<S19>/Shaft speed thruster 4'
                                        */
  real_T Shaftspeedthruster5_Value;    /* Expression: 1
                                        * Referenced by: '<S19>/Shaft speed thruster 5'
                                        */
  real_T Shaftspeedthruster6_Value;    /* Expression: 1
                                        * Referenced by: '<S19>/Shaft speed thruster 6'
                                        */
  real_T core_controller_P1;           /* Expression: width
                                        * Referenced by: '<Root>/core_controller'
                                        */
  real_T core_controller_P2;           /* Expression: dtype
                                        * Referenced by: '<Root>/core_controller'
                                        */
  real_T core_controller_P3;           /* Expression: portnum
                                        * Referenced by: '<Root>/core_controller'
                                        */
  real_T core_controller_P4;           /* Expression: stime
                                        * Referenced by: '<Root>/core_controller'
                                        */
  real_T core_controller_P5;           /* Expression: stype
                                        * Referenced by: '<Root>/core_controller'
                                        */
  real_T core_controller_P6;           /* Expression: btype
                                        * Referenced by: '<Root>/core_controller'
                                        */
  real_T ArrowUp_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/ArrowUp'
                                        */
  real_T ArrowUp_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/ArrowUp'
                                        */
  real_T ArrowUp_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/ArrowUp'
                                        */
  real_T ArrowUp_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/ArrowUp'
                                        */
  real_T ArrowUp_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/ArrowUp'
                                        */
  real_T ArrowUp_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/ArrowUp'
                                        */
  real_T ArrowDown_P1;                 /* Expression: width
                                        * Referenced by: '<Root>/ArrowDown'
                                        */
  real_T ArrowDown_P2;                 /* Expression: dtype
                                        * Referenced by: '<Root>/ArrowDown'
                                        */
  real_T ArrowDown_P3;                 /* Expression: portnum
                                        * Referenced by: '<Root>/ArrowDown'
                                        */
  real_T ArrowDown_P4;                 /* Expression: stime
                                        * Referenced by: '<Root>/ArrowDown'
                                        */
  real_T ArrowDown_P5;                 /* Expression: stype
                                        * Referenced by: '<Root>/ArrowDown'
                                        */
  real_T ArrowDown_P6;                 /* Expression: btype
                                        * Referenced by: '<Root>/ArrowDown'
                                        */
  real_T Start_P1;                     /* Expression: width
                                        * Referenced by: '<Root>/Start'
                                        */
  real_T Start_P2;                     /* Expression: dtype
                                        * Referenced by: '<Root>/Start'
                                        */
  real_T Start_P3;                     /* Expression: portnum
                                        * Referenced by: '<Root>/Start'
                                        */
  real_T Start_P4;                     /* Expression: stime
                                        * Referenced by: '<Root>/Start'
                                        */
  real_T Start_P5;                     /* Expression: stype
                                        * Referenced by: '<Root>/Start'
                                        */
  real_T Start_P6;                     /* Expression: btype
                                        * Referenced by: '<Root>/Start'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S9>/Memory'
                                        */
  real_T L2_continuous_P1;             /* Expression: width
                                        * Referenced by: '<Root>/L2_continuous'
                                        */
  real_T L2_continuous_P2;             /* Expression: dtype
                                        * Referenced by: '<Root>/L2_continuous'
                                        */
  real_T L2_continuous_P3;             /* Expression: portnum
                                        * Referenced by: '<Root>/L2_continuous'
                                        */
  real_T L2_continuous_P4;             /* Expression: stime
                                        * Referenced by: '<Root>/L2_continuous'
                                        */
  real_T L2_continuous_P5;             /* Expression: stype
                                        * Referenced by: '<Root>/L2_continuous'
                                        */
  real_T L2_continuous_P6;             /* Expression: btype
                                        * Referenced by: '<Root>/L2_continuous'
                                        */
  real_T thr_angle_1_P1;               /* Expression: width
                                        * Referenced by: '<S6>/thr_angle_1'
                                        */
  real_T thr_angle_1_P2;               /* Expression: dtype
                                        * Referenced by: '<S6>/thr_angle_1'
                                        */
  real_T thr_angle_1_P3;               /* Expression: portnum
                                        * Referenced by: '<S6>/thr_angle_1'
                                        */
  real_T thr_angle_1_P4;               /* Expression: stime
                                        * Referenced by: '<S6>/thr_angle_1'
                                        */
  real_T thr_angle_1_P5;               /* Expression: stype
                                        * Referenced by: '<S6>/thr_angle_1'
                                        */
  real_T thr_angle_1_P6;               /* Expression: btype
                                        * Referenced by: '<S6>/thr_angle_1'
                                        */
  real_T thr_angle_2_P1;               /* Expression: width
                                        * Referenced by: '<S6>/thr_angle_2'
                                        */
  real_T thr_angle_2_P2;               /* Expression: dtype
                                        * Referenced by: '<S6>/thr_angle_2'
                                        */
  real_T thr_angle_2_P3;               /* Expression: portnum
                                        * Referenced by: '<S6>/thr_angle_2'
                                        */
  real_T thr_angle_2_P4;               /* Expression: stime
                                        * Referenced by: '<S6>/thr_angle_2'
                                        */
  real_T thr_angle_2_P5;               /* Expression: stype
                                        * Referenced by: '<S6>/thr_angle_2'
                                        */
  real_T thr_angle_2_P6;               /* Expression: btype
                                        * Referenced by: '<S6>/thr_angle_2'
                                        */
  real_T thr_angle_3_P1;               /* Expression: width
                                        * Referenced by: '<S6>/thr_angle_3'
                                        */
  real_T thr_angle_3_P2;               /* Expression: dtype
                                        * Referenced by: '<S6>/thr_angle_3'
                                        */
  real_T thr_angle_3_P3;               /* Expression: portnum
                                        * Referenced by: '<S6>/thr_angle_3'
                                        */
  real_T thr_angle_3_P4;               /* Expression: stime
                                        * Referenced by: '<S6>/thr_angle_3'
                                        */
  real_T thr_angle_3_P5;               /* Expression: stype
                                        * Referenced by: '<S6>/thr_angle_3'
                                        */
  real_T thr_angle_3_P6;               /* Expression: btype
                                        * Referenced by: '<S6>/thr_angle_3'
                                        */
  real_T thr_angle_4_P1;               /* Expression: width
                                        * Referenced by: '<S6>/thr_angle_4'
                                        */
  real_T thr_angle_4_P2;               /* Expression: dtype
                                        * Referenced by: '<S6>/thr_angle_4'
                                        */
  real_T thr_angle_4_P3;               /* Expression: portnum
                                        * Referenced by: '<S6>/thr_angle_4'
                                        */
  real_T thr_angle_4_P4;               /* Expression: stime
                                        * Referenced by: '<S6>/thr_angle_4'
                                        */
  real_T thr_angle_4_P5;               /* Expression: stype
                                        * Referenced by: '<S6>/thr_angle_4'
                                        */
  real_T thr_angle_4_P6;               /* Expression: btype
                                        * Referenced by: '<S6>/thr_angle_4'
                                        */
  real_T thr_angle_5_P1;               /* Expression: width
                                        * Referenced by: '<S6>/thr_angle_5'
                                        */
  real_T thr_angle_5_P2;               /* Expression: dtype
                                        * Referenced by: '<S6>/thr_angle_5'
                                        */
  real_T thr_angle_5_P3;               /* Expression: portnum
                                        * Referenced by: '<S6>/thr_angle_5'
                                        */
  real_T thr_angle_5_P4;               /* Expression: stime
                                        * Referenced by: '<S6>/thr_angle_5'
                                        */
  real_T thr_angle_5_P5;               /* Expression: stype
                                        * Referenced by: '<S6>/thr_angle_5'
                                        */
  real_T thr_angle_5_P6;               /* Expression: btype
                                        * Referenced by: '<S6>/thr_angle_5'
                                        */
  real_T thr_angle_6_P1;               /* Expression: width
                                        * Referenced by: '<S6>/thr_angle_6'
                                        */
  real_T thr_angle_6_P2;               /* Expression: dtype
                                        * Referenced by: '<S6>/thr_angle_6'
                                        */
  real_T thr_angle_6_P3;               /* Expression: portnum
                                        * Referenced by: '<S6>/thr_angle_6'
                                        */
  real_T thr_angle_6_P4;               /* Expression: stime
                                        * Referenced by: '<S6>/thr_angle_6'
                                        */
  real_T thr_angle_6_P5;               /* Expression: stype
                                        * Referenced by: '<S6>/thr_angle_6'
                                        */
  real_T thr_angle_6_P6;               /* Expression: btype
                                        * Referenced by: '<S6>/thr_angle_6'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T XpositionThruster1_Value[6];  /* Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
                                        * Referenced by: '<S4>/X-position Thruster1'
                                        */
  real_T YpositionThruster2_Value[6];  /* Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
                                        * Referenced by: '<S4>/Y-position Thruster2'
                                        */
  real_T PosYLeft_P1;                  /* Expression: width
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  real_T PosYLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  real_T PosYLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  real_T PosYLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  real_T PosYLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  real_T PosYLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T PosXLeft_P1;                  /* Expression: width
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  real_T PosXLeft_P2;                  /* Expression: dtype
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  real_T PosXLeft_P3;                  /* Expression: portnum
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  real_T PosXLeft_P4;                  /* Expression: stime
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  real_T PosXLeft_P5;                  /* Expression: stype
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  real_T PosXLeft_P6;                  /* Expression: btype
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  real_T R2_continuous_P1;             /* Expression: width
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  real_T R2_continuous_P2;             /* Expression: dtype
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  real_T R2_continuous_P3;             /* Expression: portnum
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  real_T R2_continuous_P4;             /* Expression: stime
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  real_T R2_continuous_P5;             /* Expression: stype
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  real_T R2_continuous_P6;             /* Expression: btype
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -.5
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Angle_controller_P1;          /* Expression: width
                                        * Referenced by: '<S4>/Angle_controller'
                                        */
  real_T Angle_controller_P2;          /* Expression: dtype
                                        * Referenced by: '<S4>/Angle_controller'
                                        */
  real_T Angle_controller_P3;          /* Expression: portnum
                                        * Referenced by: '<S4>/Angle_controller'
                                        */
  real_T Angle_controller_P4;          /* Expression: stime
                                        * Referenced by: '<S4>/Angle_controller'
                                        */
  real_T Angle_controller_P5;          /* Expression: stype
                                        * Referenced by: '<S4>/Angle_controller'
                                        */
  real_T Angle_controller_P6;          /* Expression: btype
                                        * Referenced by: '<S4>/Angle_controller'
                                        */
  real_T A1Matrix_P1;                  /* Expression: width
                                        * Referenced by: '<S4>/A1Matrix '
                                        */
  real_T A1Matrix_P2;                  /* Expression: dtype
                                        * Referenced by: '<S4>/A1Matrix '
                                        */
  real_T A1Matrix_P3;                  /* Expression: portnum
                                        * Referenced by: '<S4>/A1Matrix '
                                        */
  real_T A1Matrix_P4;                  /* Expression: stime
                                        * Referenced by: '<S4>/A1Matrix '
                                        */
  real_T A1Matrix_P5;                  /* Expression: stype
                                        * Referenced by: '<S4>/A1Matrix '
                                        */
  real_T A1Matrix_P6;                  /* Expression: btype
                                        * Referenced by: '<S4>/A1Matrix '
                                        */
  real_T fmin_P1;                      /* Expression: width
                                        * Referenced by: '<S4>/fmin'
                                        */
  real_T fmin_P2;                      /* Expression: dtype
                                        * Referenced by: '<S4>/fmin'
                                        */
  real_T fmin_P3;                      /* Expression: portnum
                                        * Referenced by: '<S4>/fmin'
                                        */
  real_T fmin_P4;                      /* Expression: stime
                                        * Referenced by: '<S4>/fmin'
                                        */
  real_T fmin_P5;                      /* Expression: stype
                                        * Referenced by: '<S4>/fmin'
                                        */
  real_T fmin_P6;                      /* Expression: btype
                                        * Referenced by: '<S4>/fmin'
                                        */
  real_T A2Matrix_P1;                  /* Expression: width
                                        * Referenced by: '<S4>/A2Matrix'
                                        */
  real_T A2Matrix_P2;                  /* Expression: dtype
                                        * Referenced by: '<S4>/A2Matrix'
                                        */
  real_T A2Matrix_P3;                  /* Expression: portnum
                                        * Referenced by: '<S4>/A2Matrix'
                                        */
  real_T A2Matrix_P4;                  /* Expression: stime
                                        * Referenced by: '<S4>/A2Matrix'
                                        */
  real_T A2Matrix_P5;                  /* Expression: stype
                                        * Referenced by: '<S4>/A2Matrix'
                                        */
  real_T A2Matrix_P6;                  /* Expression: btype
                                        * Referenced by: '<S4>/A2Matrix'
                                        */
  real_T A3Matrix_P1;                  /* Expression: width
                                        * Referenced by: '<S4>/A3Matrix'
                                        */
  real_T A3Matrix_P2;                  /* Expression: dtype
                                        * Referenced by: '<S4>/A3Matrix'
                                        */
  real_T A3Matrix_P3;                  /* Expression: portnum
                                        * Referenced by: '<S4>/A3Matrix'
                                        */
  real_T A3Matrix_P4;                  /* Expression: stime
                                        * Referenced by: '<S4>/A3Matrix'
                                        */
  real_T A3Matrix_P5;                  /* Expression: stype
                                        * Referenced by: '<S4>/A3Matrix'
                                        */
  real_T A3Matrix_P6;                  /* Expression: btype
                                        * Referenced by: '<S4>/A3Matrix'
                                        */
  real_T BMatrix_P1;                   /* Expression: width
                                        * Referenced by: '<S4>/BMatrix'
                                        */
  real_T BMatrix_P2;                   /* Expression: dtype
                                        * Referenced by: '<S4>/BMatrix'
                                        */
  real_T BMatrix_P3;                   /* Expression: portnum
                                        * Referenced by: '<S4>/BMatrix'
                                        */
  real_T BMatrix_P4;                   /* Expression: stime
                                        * Referenced by: '<S4>/BMatrix'
                                        */
  real_T BMatrix_P5;                   /* Expression: stype
                                        * Referenced by: '<S4>/BMatrix'
                                        */
  real_T BMatrix_P6;                   /* Expression: btype
                                        * Referenced by: '<S4>/BMatrix'
                                        */
  real_T constantangle_Value[6];       /* Expression: [Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)]
                                        * Referenced by: '<S4>/constant angle'
                                        */
  real_T ChoosingFixedAzimuthangle_Thres;/* Expression: 1
                                          * Referenced by: '<S4>/Choosing Fixed // Azimuth angle'
                                          */
  real_T reset_P1_j;                   /* Expression: width
                                        * Referenced by: '<Root>/reset'
                                        */
  real_T reset_P2_l;                   /* Expression: dtype
                                        * Referenced by: '<Root>/reset'
                                        */
  real_T reset_P3_hh;                  /* Expression: portnum
                                        * Referenced by: '<Root>/reset'
                                        */
  real_T reset_P4_d;                   /* Expression: stime
                                        * Referenced by: '<Root>/reset'
                                        */
  real_T reset_P5_o;                   /* Expression: stype
                                        * Referenced by: '<Root>/reset'
                                        */
  real_T reset_P6_g;                   /* Expression: btype
                                        * Referenced by: '<Root>/reset'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S18>/Saturation 1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation 1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S18>/Saturation 2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation 2'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S18>/Saturation 3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation 3'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S18>/Saturation 4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation 4'
                                        */
  real_T Saturation5_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S18>/Saturation 5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation 5'
                                        */
  real_T Saturation6_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S18>/Saturation 6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation 6'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 180/pi
                                        * Referenced by: '<S3>/Gain'
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
  real_T N_P1;                         /* Expression: width
                                        * Referenced by: '<Root>/N'
                                        */
  real_T N_P2;                         /* Expression: dtype
                                        * Referenced by: '<Root>/N'
                                        */
  real_T N_P3;                         /* Expression: portnum
                                        * Referenced by: '<Root>/N'
                                        */
  real_T N_P4;                         /* Expression: stime
                                        * Referenced by: '<Root>/N'
                                        */
  real_T N_P5;                         /* Expression: stype
                                        * Referenced by: '<Root>/N'
                                        */
  real_T N_P6;                         /* Expression: btype
                                        * Referenced by: '<Root>/N'
                                        */
  real_T X_P1;                         /* Expression: width
                                        * Referenced by: '<Root>/X'
                                        */
  real_T X_P2;                         /* Expression: dtype
                                        * Referenced by: '<Root>/X'
                                        */
  real_T X_P3;                         /* Expression: portnum
                                        * Referenced by: '<Root>/X'
                                        */
  real_T X_P4;                         /* Expression: stime
                                        * Referenced by: '<Root>/X'
                                        */
  real_T X_P5;                         /* Expression: stype
                                        * Referenced by: '<Root>/X'
                                        */
  real_T X_P6;                         /* Expression: btype
                                        * Referenced by: '<Root>/X'
                                        */
  real_T Y_P1;                         /* Expression: width
                                        * Referenced by: '<Root>/Y'
                                        */
  real_T Y_P2;                         /* Expression: dtype
                                        * Referenced by: '<Root>/Y'
                                        */
  real_T Y_P3;                         /* Expression: portnum
                                        * Referenced by: '<Root>/Y'
                                        */
  real_T Y_P4;                         /* Expression: stime
                                        * Referenced by: '<Root>/Y'
                                        */
  real_T Y_P5;                         /* Expression: stype
                                        * Referenced by: '<Root>/Y'
                                        */
  real_T Y_P6;                         /* Expression: btype
                                        * Referenced by: '<Root>/Y'
                                        */
  real_T u_limit_P1;                   /* Expression: width
                                        * Referenced by: '<Root>/u_limit'
                                        */
  real_T u_limit_P2;                   /* Expression: dtype
                                        * Referenced by: '<Root>/u_limit'
                                        */
  real_T u_limit_P3;                   /* Expression: portnum
                                        * Referenced by: '<Root>/u_limit'
                                        */
  real_T u_limit_P4;                   /* Expression: stime
                                        * Referenced by: '<Root>/u_limit'
                                        */
  real_T u_limit_P5;                   /* Expression: stype
                                        * Referenced by: '<Root>/u_limit'
                                        */
  real_T u_limit_P6;                   /* Expression: btype
                                        * Referenced by: '<Root>/u_limit'
                                        */
  real_T Constant1_Value[3];           /* Expression: [0 0 0]'
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S5>/Delay'
                                        */
  real_T Constant_Value[2];            /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Constant1_Value_p[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T Delay_InitialCondition_m;     /* Expression: 0
                                        * Referenced by: '<S20>/Delay'
                                        */
  real_T Delay_InitialCondition_mz;    /* Expression: 0
                                        * Referenced by: '<S29>/Delay'
                                        */
  real_T Constant1_Value_i[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T Constant2_Value[3];           /* Expression: hd.den{1,1}
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S29>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S32>/TSamp'
                                        */
  real_T AccelerationLimit_RisingLim;  /* Computed Parameter: AccelerationLimit_RisingLim
                                        * Referenced by: '<S29>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_FallingLim; /* Computed Parameter: AccelerationLimit_FallingLim
                                        * Referenced by: '<S29>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_IC;         /* Expression: 0
                                        * Referenced by: '<S29>/Acceleration Limit'
                                        */
  real_T Memory_X0_f;                  /* Expression: 1
                                        * Referenced by: '<S29>/Memory'
                                        */
  real_T reset_P1_c2;                  /* Expression: width
                                        * Referenced by: '<S31>/reset'
                                        */
  real_T reset_P2_g;                   /* Expression: dtype
                                        * Referenced by: '<S31>/reset'
                                        */
  real_T reset_P3_mi;                  /* Expression: portnum
                                        * Referenced by: '<S31>/reset'
                                        */
  real_T reset_P4_l;                   /* Expression: stime
                                        * Referenced by: '<S31>/reset'
                                        */
  real_T reset_P5_c;                   /* Expression: stype
                                        * Referenced by: '<S31>/reset'
                                        */
  real_T reset_P6_n;                   /* Expression: btype
                                        * Referenced by: '<S31>/reset'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S31>/Integrator'
                                        */
  real_T NaN_Value;                    /* Expression: 0
                                        * Referenced by: '<S29>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_n;/* Expression: 0
                                          * Referenced by: '<S20>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_i[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant1_Value_b[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real_T Delay_InitialCondition_k;     /* Expression: 0
                                        * Referenced by: '<S21>/Delay'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0
                                        * Referenced by: '<S38>/Delay'
                                        */
  real_T Constant1_Value_g[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T Constant2_Value_a[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S38>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_c;/* Expression: 0
                                          * Referenced by: '<S38>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_j;                 /* Computed Parameter: TSamp_WtEt_j
                                        * Referenced by: '<S41>/TSamp'
                                        */
  real_T AccelerationLimit_RisingLim_b;/* Computed Parameter: AccelerationLimit_RisingLim_b
                                        * Referenced by: '<S38>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_FallingLim_f;/* Computed Parameter: AccelerationLimit_FallingLim_f
                                         * Referenced by: '<S38>/Acceleration Limit'
                                         */
  real_T AccelerationLimit_IC_e;       /* Expression: 0
                                        * Referenced by: '<S38>/Acceleration Limit'
                                        */
  real_T Memory_X0_h;                  /* Expression: 1
                                        * Referenced by: '<S38>/Memory'
                                        */
  real_T reset_P1_p5;                  /* Expression: width
                                        * Referenced by: '<S40>/reset'
                                        */
  real_T reset_P2_my;                  /* Expression: dtype
                                        * Referenced by: '<S40>/reset'
                                        */
  real_T reset_P3_o;                   /* Expression: portnum
                                        * Referenced by: '<S40>/reset'
                                        */
  real_T reset_P4_g4;                  /* Expression: stime
                                        * Referenced by: '<S40>/reset'
                                        */
  real_T reset_P5_n2;                  /* Expression: stype
                                        * Referenced by: '<S40>/reset'
                                        */
  real_T reset_P6_ni;                  /* Expression: btype
                                        * Referenced by: '<S40>/reset'
                                        */
  real_T Integrator_IC_o;              /* Expression: 0
                                        * Referenced by: '<S40>/Integrator'
                                        */
  real_T NaN_Value_j;                  /* Expression: 0
                                        * Referenced by: '<S38>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_d;/* Expression: 0
                                          * Referenced by: '<S21>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_g[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Constant1_Value_a[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S22>/Constant1'
                                        */
  real_T Delay_InitialCondition_b;     /* Expression: 0
                                        * Referenced by: '<S22>/Delay'
                                        */
  real_T Delay_InitialCondition_h;     /* Expression: 0
                                        * Referenced by: '<S47>/Delay'
                                        */
  real_T Constant1_Value_h[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S47>/Constant1'
                                        */
  real_T Constant2_Value_g[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S47>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_m;/* Expression: 0
                                          * Referenced by: '<S47>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_l;                 /* Computed Parameter: TSamp_WtEt_l
                                        * Referenced by: '<S50>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim;/* Computed Parameter: Accelerationlimiter_RisingLim
                                        * Referenced by: '<S47>/Acceleration limiter'
                                        */
  real_T Accelerationlimiter_FallingLim;/* Computed Parameter: Accelerationlimiter_FallingLim
                                         * Referenced by: '<S47>/Acceleration limiter'
                                         */
  real_T Accelerationlimiter_IC;       /* Expression: 0
                                        * Referenced by: '<S47>/Acceleration limiter'
                                        */
  real_T Memory_X0_e;                  /* Expression: 1
                                        * Referenced by: '<S47>/Memory'
                                        */
  real_T reset_P1_h;                   /* Expression: width
                                        * Referenced by: '<S49>/reset'
                                        */
  real_T reset_P2_n;                   /* Expression: dtype
                                        * Referenced by: '<S49>/reset'
                                        */
  real_T reset_P3_d;                   /* Expression: portnum
                                        * Referenced by: '<S49>/reset'
                                        */
  real_T reset_P4_hr;                  /* Expression: stime
                                        * Referenced by: '<S49>/reset'
                                        */
  real_T reset_P5_m;                   /* Expression: stype
                                        * Referenced by: '<S49>/reset'
                                        */
  real_T reset_P6_or;                  /* Expression: btype
                                        * Referenced by: '<S49>/reset'
                                        */
  real_T Integrator_IC_pf;             /* Expression: 0
                                        * Referenced by: '<S49>/Integrator'
                                        */
  real_T NaN_Value_e;                  /* Expression: 0
                                        * Referenced by: '<S47>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialS_nl;/* Expression: 0
                                          * Referenced by: '<S22>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_j[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Constant1_Value_bp[2];        /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T Delay_InitialCondition_g;     /* Expression: 0
                                        * Referenced by: '<S23>/Delay'
                                        */
  real_T Delay_InitialCondition_e;     /* Expression: 0
                                        * Referenced by: '<S56>/Delay'
                                        */
  real_T Constant1_Value_f[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S56>/Constant1'
                                        */
  real_T Constant2_Value_i[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S56>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_mq;/* Expression: 0
                                          * Referenced by: '<S56>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_n;                 /* Computed Parameter: TSamp_WtEt_n
                                        * Referenced by: '<S59>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_n;/* Computed Parameter: Accelerationlimiter_RisingLim_n
                                          * Referenced by: '<S56>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_o;/* Computed Parameter: Accelerationlimiter_FallingLi_o
                                          * Referenced by: '<S56>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_m;     /* Expression: 0
                                        * Referenced by: '<S56>/Acceleration limiter'
                                        */
  real_T Memory_X0_d;                  /* Expression: 1
                                        * Referenced by: '<S56>/Memory'
                                        */
  real_T reset_P1_l;                   /* Expression: width
                                        * Referenced by: '<S58>/reset'
                                        */
  real_T reset_P2_fz;                  /* Expression: dtype
                                        * Referenced by: '<S58>/reset'
                                        */
  real_T reset_P3_hw;                  /* Expression: portnum
                                        * Referenced by: '<S58>/reset'
                                        */
  real_T reset_P4_cd;                  /* Expression: stime
                                        * Referenced by: '<S58>/reset'
                                        */
  real_T reset_P5_eo;                  /* Expression: stype
                                        * Referenced by: '<S58>/reset'
                                        */
  real_T reset_P6_niy;                 /* Expression: btype
                                        * Referenced by: '<S58>/reset'
                                        */
  real_T Integrator_IC_f;              /* Expression: 0
                                        * Referenced by: '<S58>/Integrator'
                                        */
  real_T NaN_Value_o;                  /* Expression: 0
                                        * Referenced by: '<S56>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_i;/* Expression: 0
                                          * Referenced by: '<S23>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_k[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Constant1_Value_n[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T Delay_InitialCondition_i;     /* Expression: 0
                                        * Referenced by: '<S24>/Delay'
                                        */
  real_T Delay_InitialCondition_o;     /* Expression: 0
                                        * Referenced by: '<S65>/Delay'
                                        */
  real_T Constant1_Value_e[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S65>/Constant1'
                                        */
  real_T Constant2_Value_n[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S65>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_mc;/* Expression: 0
                                          * Referenced by: '<S65>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_m;                 /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S68>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_j;/* Computed Parameter: Accelerationlimiter_RisingLim_j
                                          * Referenced by: '<S65>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_i;/* Computed Parameter: Accelerationlimiter_FallingLi_i
                                          * Referenced by: '<S65>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_e;     /* Expression: 0
                                        * Referenced by: '<S65>/Acceleration limiter'
                                        */
  real_T Memory_X0_b;                  /* Expression: 1
                                        * Referenced by: '<S65>/Memory'
                                        */
  real_T reset_P1_b;                   /* Expression: width
                                        * Referenced by: '<S67>/reset'
                                        */
  real_T reset_P2_mv;                  /* Expression: dtype
                                        * Referenced by: '<S67>/reset'
                                        */
  real_T reset_P3_j5;                  /* Expression: portnum
                                        * Referenced by: '<S67>/reset'
                                        */
  real_T reset_P4_i;                   /* Expression: stime
                                        * Referenced by: '<S67>/reset'
                                        */
  real_T reset_P5_ez;                  /* Expression: stype
                                        * Referenced by: '<S67>/reset'
                                        */
  real_T reset_P6_ji;                  /* Expression: btype
                                        * Referenced by: '<S67>/reset'
                                        */
  real_T Integrator_IC_e2;             /* Expression: 0
                                        * Referenced by: '<S67>/Integrator'
                                        */
  real_T NaN_Value_d;                  /* Expression: 0
                                        * Referenced by: '<S65>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_h;/* Expression: 0
                                          * Referenced by: '<S24>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_gp[2];         /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Constant1_Value_c[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S25>/Constant1'
                                        */
  real_T Delay_InitialCondition_bd;    /* Expression: 0
                                        * Referenced by: '<S25>/Delay'
                                        */
  real_T Delay_InitialCondition_j;     /* Expression: 0
                                        * Referenced by: '<S74>/Delay'
                                        */
  real_T Constant1_Value_j[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S74>/Constant1'
                                        */
  real_T Constant2_Value_l[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S74>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_l;/* Expression: 0
                                          * Referenced by: '<S74>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_b;                 /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S77>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLi_nn;/* Computed Parameter: Accelerationlimiter_RisingLi_nn
                                          * Referenced by: '<S74>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_a;/* Computed Parameter: Accelerationlimiter_FallingLi_a
                                          * Referenced by: '<S74>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_k;     /* Expression: 0
                                        * Referenced by: '<S74>/Acceleration limiter'
                                        */
  real_T Memory_X0_g;                  /* Expression: 1
                                        * Referenced by: '<S74>/Memory'
                                        */
  real_T reset_P1_p0;                  /* Expression: width
                                        * Referenced by: '<S76>/reset'
                                        */
  real_T reset_P2_fe;                  /* Expression: dtype
                                        * Referenced by: '<S76>/reset'
                                        */
  real_T reset_P3_n;                   /* Expression: portnum
                                        * Referenced by: '<S76>/reset'
                                        */
  real_T reset_P4_b0;                  /* Expression: stime
                                        * Referenced by: '<S76>/reset'
                                        */
  real_T reset_P5_ho;                  /* Expression: stype
                                        * Referenced by: '<S76>/reset'
                                        */
  real_T reset_P6_f;                   /* Expression: btype
                                        * Referenced by: '<S76>/reset'
                                        */
  real_T Integrator_IC_eh;             /* Expression: 0
                                        * Referenced by: '<S76>/Integrator'
                                        */
  real_T NaN_Value_eh;                 /* Expression: 0
                                        * Referenced by: '<S74>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialS_dp;/* Expression: 0
                                          * Referenced by: '<S25>/Discrete Transfer Fcn'
                                          */
  real_T Velocity_IC[3];               /* Expression: [0 0 0]'
                                        * Referenced by: '<Root>/Velocity'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S5>/Delay'
                                        */
  uint32_T Delay_DelayLength_f;        /* Computed Parameter: Delay_DelayLength_f
                                        * Referenced by: '<S20>/Delay'
                                        */
  uint32_T Delay_DelayLength_o;        /* Computed Parameter: Delay_DelayLength_o
                                        * Referenced by: '<S29>/Delay'
                                        */
  uint32_T Delay_DelayLength_k;        /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S21>/Delay'
                                        */
  uint32_T Delay_DelayLength_d;        /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S38>/Delay'
                                        */
  uint32_T Delay_DelayLength_j;        /* Computed Parameter: Delay_DelayLength_j
                                        * Referenced by: '<S22>/Delay'
                                        */
  uint32_T Delay_DelayLength_n;        /* Computed Parameter: Delay_DelayLength_n
                                        * Referenced by: '<S47>/Delay'
                                        */
  uint32_T Delay_DelayLength_e;        /* Computed Parameter: Delay_DelayLength_e
                                        * Referenced by: '<S23>/Delay'
                                        */
  uint32_T Delay_DelayLength_l;        /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Delay_DelayLength_m;        /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S24>/Delay'
                                        */
  uint32_T Delay_DelayLength_g;        /* Computed Parameter: Delay_DelayLength_g
                                        * Referenced by: '<S65>/Delay'
                                        */
  uint32_T Delay_DelayLength_np;       /* Computed Parameter: Delay_DelayLength_np
                                        * Referenced by: '<S25>/Delay'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S74>/Delay'
                                        */
  P_CoreSubsys_Thrustallocation_T CoreSubsys;/* '<S12>/CoreSubsys' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Thrustallocation_test_T {
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
    real_T odeY[18];
    real_T odeF[3][18];
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
extern P_Thrustallocation_test_T Thrustallocation_test_P;

/* Block signals (auto storage) */
extern B_Thrustallocation_test_T Thrustallocation_test_B;

/* Continuous states (auto storage) */
extern X_Thrustallocation_test_T Thrustallocation_test_X;

/* Block states (auto storage) */
extern DW_Thrustallocation_test_T Thrustallocation_test_DW;

/* Model entry point functions */
extern void Thrustallocation_test_initialize(void);
extern void Thrustallocation_test_output(void);
extern void Thrustallocation_test_update(void);
extern void Thrustallocation_test_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Thrustallocation_test_rtModel *Thrustallocation_test(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Thrustallocation_tes_T *const Thrustallocation_test_M;

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
 * '<Root>' : 'Thrustallocation_test'
 * '<S1>'   : 'Thrustallocation_test/Finding commanded forces in: [Surge,Sway,Yaw]'
 * '<S2>'   : 'Thrustallocation_test/Parameters From initfile distributed '
 * '<S3>'   : 'Thrustallocation_test/Radians to Degrees'
 * '<S4>'   : 'Thrustallocation_test/Thrust allocation'
 * '<S5>'   : 'Thrustallocation_test/Thruster control '
 * '<S6>'   : 'Thrustallocation_test/Thruster measurment'
 * '<S7>'   : 'Thrustallocation_test/kinematics'
 * '<S8>'   : 'Thrustallocation_test/kinetics'
 * '<S9>'   : 'Thrustallocation_test/u_limiter'
 * '<S10>'  : 'Thrustallocation_test/Thrust allocation/MATLAB Function1'
 * '<S11>'  : 'Thrustallocation_test/Thrust allocation/MATLAB Function2'
 * '<S12>'  : 'Thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed'
 * '<S13>'  : 'Thrustallocation_test/Thrust allocation/Radians to Degrees'
 * '<S14>'  : 'Thrustallocation_test/Thrust allocation/angle between  [180 -180]'
 * '<S15>'  : 'Thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed/Degrees to Radians'
 * '<S16>'  : 'Thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed/MATLAB Function'
 * '<S17>'  : 'Thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed/MATLAB Function1'
 * '<S18>'  : 'Thrustallocation_test/Thruster control /Subsystem1'
 * '<S19>'  : 'Thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM'
 * '<S20>'  : 'Thrustallocation_test/Thruster control /Thruster 1'
 * '<S21>'  : 'Thrustallocation_test/Thruster control /Thruster 2'
 * '<S22>'  : 'Thrustallocation_test/Thruster control /Thruster 3'
 * '<S23>'  : 'Thrustallocation_test/Thruster control /Thruster 4'
 * '<S24>'  : 'Thrustallocation_test/Thruster control /Thruster 5'
 * '<S25>'  : 'Thrustallocation_test/Thruster control /Thruster 6'
 * '<S26>'  : 'Thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function'
 * '<S27>'  : 'Thrustallocation_test/Thruster control /Thruster 1/Propeller Hydrodynamics'
 * '<S28>'  : 'Thrustallocation_test/Thruster control /Thruster 1/Shaft dynamics'
 * '<S29>'  : 'Thrustallocation_test/Thruster control /Thruster 1/Thruster control'
 * '<S30>'  : 'Thrustallocation_test/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S31>'  : 'Thrustallocation_test/Thruster control /Thruster 1/Thruster control/Core controller'
 * '<S32>'  : 'Thrustallocation_test/Thruster control /Thruster 1/Thruster control/Discrete Derivative'
 * '<S33>'  : 'Thrustallocation_test/Thruster control /Thruster 1/Thruster control/MATLAB Function'
 * '<S34>'  : 'Thrustallocation_test/Thruster control /Thruster 1/Thruster control/Supervisor'
 * '<S35>'  : 'Thrustallocation_test/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S36>'  : 'Thrustallocation_test/Thruster control /Thruster 2/Propeller Hydrodynamics'
 * '<S37>'  : 'Thrustallocation_test/Thruster control /Thruster 2/Shaft dynamics'
 * '<S38>'  : 'Thrustallocation_test/Thruster control /Thruster 2/Thruster control'
 * '<S39>'  : 'Thrustallocation_test/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S40>'  : 'Thrustallocation_test/Thruster control /Thruster 2/Thruster control/Core controller'
 * '<S41>'  : 'Thrustallocation_test/Thruster control /Thruster 2/Thruster control/Discrete Derivative'
 * '<S42>'  : 'Thrustallocation_test/Thruster control /Thruster 2/Thruster control/MATLAB Function'
 * '<S43>'  : 'Thrustallocation_test/Thruster control /Thruster 2/Thruster control/Supervisor'
 * '<S44>'  : 'Thrustallocation_test/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S45>'  : 'Thrustallocation_test/Thruster control /Thruster 3/Propeller Hydrodynamics'
 * '<S46>'  : 'Thrustallocation_test/Thruster control /Thruster 3/Shaft dynamics'
 * '<S47>'  : 'Thrustallocation_test/Thruster control /Thruster 3/Thruster control'
 * '<S48>'  : 'Thrustallocation_test/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S49>'  : 'Thrustallocation_test/Thruster control /Thruster 3/Thruster control/Core controller'
 * '<S50>'  : 'Thrustallocation_test/Thruster control /Thruster 3/Thruster control/Discrete Derivative'
 * '<S51>'  : 'Thrustallocation_test/Thruster control /Thruster 3/Thruster control/MATLAB Function'
 * '<S52>'  : 'Thrustallocation_test/Thruster control /Thruster 3/Thruster control/Supervisor'
 * '<S53>'  : 'Thrustallocation_test/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S54>'  : 'Thrustallocation_test/Thruster control /Thruster 4/Propeller Hydrodynamics'
 * '<S55>'  : 'Thrustallocation_test/Thruster control /Thruster 4/Shaft dynamics'
 * '<S56>'  : 'Thrustallocation_test/Thruster control /Thruster 4/Thruster control'
 * '<S57>'  : 'Thrustallocation_test/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S58>'  : 'Thrustallocation_test/Thruster control /Thruster 4/Thruster control/Core controller'
 * '<S59>'  : 'Thrustallocation_test/Thruster control /Thruster 4/Thruster control/Discrete Derivative'
 * '<S60>'  : 'Thrustallocation_test/Thruster control /Thruster 4/Thruster control/MATLAB Function'
 * '<S61>'  : 'Thrustallocation_test/Thruster control /Thruster 4/Thruster control/Supervisor'
 * '<S62>'  : 'Thrustallocation_test/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S63>'  : 'Thrustallocation_test/Thruster control /Thruster 5/Propeller Hydrodynamics'
 * '<S64>'  : 'Thrustallocation_test/Thruster control /Thruster 5/Shaft dynamics'
 * '<S65>'  : 'Thrustallocation_test/Thruster control /Thruster 5/Thruster control'
 * '<S66>'  : 'Thrustallocation_test/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S67>'  : 'Thrustallocation_test/Thruster control /Thruster 5/Thruster control/Core controller'
 * '<S68>'  : 'Thrustallocation_test/Thruster control /Thruster 5/Thruster control/Discrete Derivative'
 * '<S69>'  : 'Thrustallocation_test/Thruster control /Thruster 5/Thruster control/MATLAB Function'
 * '<S70>'  : 'Thrustallocation_test/Thruster control /Thruster 5/Thruster control/Supervisor'
 * '<S71>'  : 'Thrustallocation_test/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S72>'  : 'Thrustallocation_test/Thruster control /Thruster 6/Propeller Hydrodynamics'
 * '<S73>'  : 'Thrustallocation_test/Thruster control /Thruster 6/Shaft dynamics'
 * '<S74>'  : 'Thrustallocation_test/Thruster control /Thruster 6/Thruster control'
 * '<S75>'  : 'Thrustallocation_test/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S76>'  : 'Thrustallocation_test/Thruster control /Thruster 6/Thruster control/Core controller'
 * '<S77>'  : 'Thrustallocation_test/Thruster control /Thruster 6/Thruster control/Discrete Derivative'
 * '<S78>'  : 'Thrustallocation_test/Thruster control /Thruster 6/Thruster control/MATLAB Function'
 * '<S79>'  : 'Thrustallocation_test/Thruster control /Thruster 6/Thruster control/Supervisor'
 * '<S80>'  : 'Thrustallocation_test/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S81>'  : 'Thrustallocation_test/u_limiter/Detect Increase'
 * '<S82>'  : 'Thrustallocation_test/u_limiter/Detect Increase1'
 * '<S83>'  : 'Thrustallocation_test/u_limiter/Detect Increase2'
 * '<S84>'  : 'Thrustallocation_test/u_limiter/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Thrustallocation_test_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : Thrustallocation_test
 * Model version : 1.10
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Fri Jun 17 16:52:41 2016
 *========================================================================*/
#ifdef NI_ROOTMODEL_Thrustallocation_test

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* Thrustallocation_test.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_Thrustallocation_test_T rtParameter[NUMST+!TID01EQ];
P_Thrustallocation_test_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_Thrustallocation_test_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_Thrustallocation_test_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_Thrustallocation_test_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
