/*
 * rpm.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "rpm".
 *
 * Model version              : 1.68
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sun Jun 26 19:52:37 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rpm_h_
#define RTW_HEADER_rpm_h_
#include <string.h>
#include <stddef.h>
#ifndef rpm_COMMON_INCLUDES_
# define rpm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* rpm_COMMON_INCLUDES_ */

#include "rpm_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

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
#define rpm_rtModel                    RT_MODEL_rpm_T

/* Block signals for system '<Root>/MATLAB Function' */
typedef struct {
  real_T rpm_n;                        /* '<Root>/MATLAB Function' */
  real_T measurment_tmp;               /* '<Root>/MATLAB Function' */
  real_T revolutions_out;              /* '<Root>/MATLAB Function' */
  real_T timeold_out;                  /* '<Root>/MATLAB Function' */
} B_MATLABFunction_rpm_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Memory3;                      /* '<Root>/Memory3' */
  real_T revolutions1;                 /* '<Root>/revolutions1' */
  real_T Memory;                       /* '<Root>/Memory' */
  real_T Memory1;                      /* '<Root>/Memory1' */
  real_T Memory2;                      /* '<Root>/Memory2' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T revolutions2;                 /* '<Root>/revolutions2' */
  real_T revolutions3;                 /* '<Root>/revolutions3' */
  real_T Memory7;                      /* '<Root>/Memory7' */
  real_T Memory4;                      /* '<Root>/Memory4' */
  real_T Memory5;                      /* '<Root>/Memory5' */
  real_T Memory6;                      /* '<Root>/Memory6' */
  real_T revolutions4;                 /* '<Root>/revolutions4' */
  real_T revolutions5;                 /* '<Root>/revolutions5' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T revolutions6;                 /* '<Root>/revolutions6' */
  real_T Memory11;                     /* '<Root>/Memory11' */
  real_T Memory8;                      /* '<Root>/Memory8' */
  real_T Memory9;                      /* '<Root>/Memory9' */
  real_T Memory10;                     /* '<Root>/Memory10' */
  real_T Gain4;                        /* '<Root>/Gain4' */
  real_T Memory15;                     /* '<Root>/Memory15' */
  real_T Memory12;                     /* '<Root>/Memory12' */
  real_T Memory13;                     /* '<Root>/Memory13' */
  real_T Memory14;                     /* '<Root>/Memory14' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T Memory19;                     /* '<Root>/Memory19' */
  real_T Memory16;                     /* '<Root>/Memory16' */
  real_T Memory17;                     /* '<Root>/Memory17' */
  real_T Memory18;                     /* '<Root>/Memory18' */
  real_T Gain3;                        /* '<Root>/Gain3' */
  real_T Memory23;                     /* '<Root>/Memory23' */
  real_T Memory20;                     /* '<Root>/Memory20' */
  real_T Memory21;                     /* '<Root>/Memory21' */
  real_T Memory22;                     /* '<Root>/Memory22' */
  real_T Gain5;                        /* '<Root>/Gain5' */
  B_MATLABFunction_rpm_T sf_MATLABFunction5;/* '<Root>/MATLAB Function5' */
  B_MATLABFunction_rpm_T sf_MATLABFunction4;/* '<Root>/MATLAB Function4' */
  B_MATLABFunction_rpm_T sf_MATLABFunction3;/* '<Root>/MATLAB Function3' */
  B_MATLABFunction_rpm_T sf_MATLABFunction2;/* '<Root>/MATLAB Function2' */
  B_MATLABFunction_rpm_T sf_MATLABFunction1;/* '<Root>/MATLAB Function1' */
  B_MATLABFunction_rpm_T sf_MATLABFunction;/* '<Root>/MATLAB Function' */
} B_rpm_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Memory3_PreviousInput;        /* '<Root>/Memory3' */
  real_T revolutions1_DWORK1;          /* '<Root>/revolutions1' */
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  real_T Memory1_PreviousInput;        /* '<Root>/Memory1' */
  real_T Memory2_PreviousInput;        /* '<Root>/Memory2' */
  real_T rpm1_DWORK1;                  /* '<Root>/rpm1' */
  real_T measurment1_DWORK1;           /* '<Root>/measurment1' */
  real_T revolutions2_DWORK1;          /* '<Root>/revolutions2' */
  real_T revolution1_DWORK1;           /* '<Root>/revolution1' */
  real_T revolutions3_DWORK1;          /* '<Root>/revolutions3' */
  real_T Memory7_PreviousInput;        /* '<Root>/Memory7' */
  real_T Memory4_PreviousInput;        /* '<Root>/Memory4' */
  real_T Memory5_PreviousInput;        /* '<Root>/Memory5' */
  real_T Memory6_PreviousInput;        /* '<Root>/Memory6' */
  real_T measurment2_DWORK1;           /* '<Root>/measurment2' */
  real_T revolutions4_DWORK1;          /* '<Root>/revolutions4' */
  real_T revolution2_DWORK1;           /* '<Root>/revolution2' */
  real_T revolutions5_DWORK1;          /* '<Root>/revolutions5' */
  real_T rpm2_DWORK1;                  /* '<Root>/rpm2' */
  real_T revolutions6_DWORK1;          /* '<Root>/revolutions6' */
  real_T Memory11_PreviousInput;       /* '<Root>/Memory11' */
  real_T Memory8_PreviousInput;        /* '<Root>/Memory8' */
  real_T Memory9_PreviousInput;        /* '<Root>/Memory9' */
  real_T Memory10_PreviousInput;       /* '<Root>/Memory10' */
  real_T measurment3_DWORK1;           /* '<Root>/measurment3' */
  real_T revolution3_DWORK1;           /* '<Root>/revolution3' */
  real_T rpm3_DWORK1;                  /* '<Root>/rpm3' */
  real_T Memory15_PreviousInput;       /* '<Root>/Memory15' */
  real_T Memory12_PreviousInput;       /* '<Root>/Memory12' */
  real_T Memory13_PreviousInput;       /* '<Root>/Memory13' */
  real_T Memory14_PreviousInput;       /* '<Root>/Memory14' */
  real_T measurment4_DWORK1;           /* '<Root>/measurment4' */
  real_T revolution4_DWORK1;           /* '<Root>/revolution4' */
  real_T rpm4_DWORK1;                  /* '<Root>/rpm4' */
  real_T Memory19_PreviousInput;       /* '<Root>/Memory19' */
  real_T Memory16_PreviousInput;       /* '<Root>/Memory16' */
  real_T Memory17_PreviousInput;       /* '<Root>/Memory17' */
  real_T Memory18_PreviousInput;       /* '<Root>/Memory18' */
  real_T measurment5_DWORK1;           /* '<Root>/measurment5' */
  real_T revolution5_DWORK1;           /* '<Root>/revolution5' */
  real_T rpm5_DWORK1;                  /* '<Root>/rpm5' */
  real_T Memory23_PreviousInput;       /* '<Root>/Memory23' */
  real_T Memory20_PreviousInput;       /* '<Root>/Memory20' */
  real_T Memory21_PreviousInput;       /* '<Root>/Memory21' */
  real_T Memory22_PreviousInput;       /* '<Root>/Memory22' */
  real_T measurment6_DWORK1;           /* '<Root>/measurment6' */
  real_T revolution6_DWORK1;           /* '<Root>/revolution6' */
  real_T rpm6_DWORK1;                  /* '<Root>/rpm6' */
  uint8_T revolutions1_DWORK2[4];      /* '<Root>/revolutions1' */
  uint8_T rpm1_DWORK2[4];              /* '<Root>/rpm1' */
  uint8_T measurment1_DWORK2[4];       /* '<Root>/measurment1' */
  uint8_T revolutions2_DWORK2[4];      /* '<Root>/revolutions2' */
  uint8_T revolution1_DWORK2[4];       /* '<Root>/revolution1' */
  uint8_T revolutions3_DWORK2[4];      /* '<Root>/revolutions3' */
  uint8_T measurment2_DWORK2[4];       /* '<Root>/measurment2' */
  uint8_T revolutions4_DWORK2[4];      /* '<Root>/revolutions4' */
  uint8_T revolution2_DWORK2[4];       /* '<Root>/revolution2' */
  uint8_T revolutions5_DWORK2[4];      /* '<Root>/revolutions5' */
  uint8_T rpm2_DWORK2[4];              /* '<Root>/rpm2' */
  uint8_T revolutions6_DWORK2[4];      /* '<Root>/revolutions6' */
  uint8_T measurment3_DWORK2[4];       /* '<Root>/measurment3' */
  uint8_T revolution3_DWORK2[4];       /* '<Root>/revolution3' */
  uint8_T rpm3_DWORK2[4];              /* '<Root>/rpm3' */
  uint8_T measurment4_DWORK2[4];       /* '<Root>/measurment4' */
  uint8_T revolution4_DWORK2[4];       /* '<Root>/revolution4' */
  uint8_T rpm4_DWORK2[4];              /* '<Root>/rpm4' */
  uint8_T measurment5_DWORK2[4];       /* '<Root>/measurment5' */
  uint8_T revolution5_DWORK2[4];       /* '<Root>/revolution5' */
  uint8_T rpm5_DWORK2[4];              /* '<Root>/rpm5' */
  uint8_T measurment6_DWORK2[4];       /* '<Root>/measurment6' */
  uint8_T revolution6_DWORK2[4];       /* '<Root>/revolution6' */
  uint8_T rpm6_DWORK2[4];              /* '<Root>/rpm6' */
} DW_rpm_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<Root>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<Root>/Integrator5' */
} X_rpm_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<Root>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<Root>/Integrator5' */
} XDot_rpm_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
  boolean_T Integrator3_CSTATE;        /* '<Root>/Integrator3' */
  boolean_T Integrator4_CSTATE;        /* '<Root>/Integrator4' */
  boolean_T Integrator5_CSTATE;        /* '<Root>/Integrator5' */
} XDis_rpm_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            rpm_B
#define BlockIO                        B_rpm_T
#define rtX                            rpm_X
#define ContinuousStates               X_rpm_T
#define rtXdot                         rpm_XDot
#define StateDerivatives               XDot_rpm_T
#define tXdis                          rpm_XDis
#define StateDisabled                  XDis_rpm_T
#define rtP                            rpm_P
#define Parameters                     P_rpm_T
#define rtDWork                        rpm_DW
#define D_Work                         DW_rpm_T

/* Parameters (auto storage) */
struct P_rpm_T_ {
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<Root>/Memory3'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T revolutions1_P1;              /* Expression: width
                                        * Referenced by: '<Root>/revolutions1'
                                        */
  real_T revolutions1_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions1'
                                        */
  real_T revolutions1_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions1'
                                        */
  real_T revolutions1_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/revolutions1'
                                        */
  real_T revolutions1_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/revolutions1'
                                        */
  real_T revolutions1_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/revolutions1'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<Root>/Memory2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T rpm1_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/rpm1'
                                        */
  real_T rpm1_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/rpm1'
                                        */
  real_T rpm1_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/rpm1'
                                        */
  real_T rpm1_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/rpm1'
                                        */
  real_T rpm1_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/rpm1'
                                        */
  real_T rpm1_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/rpm1'
                                        */
  real_T measurment1_P1;               /* Expression: width
                                        * Referenced by: '<Root>/measurment1'
                                        */
  real_T measurment1_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/measurment1'
                                        */
  real_T measurment1_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/measurment1'
                                        */
  real_T measurment1_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/measurment1'
                                        */
  real_T measurment1_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/measurment1'
                                        */
  real_T measurment1_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/measurment1'
                                        */
  real_T revolutions2_P1;              /* Expression: width
                                        * Referenced by: '<Root>/revolutions2'
                                        */
  real_T revolutions2_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions2'
                                        */
  real_T revolutions2_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions2'
                                        */
  real_T revolutions2_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/revolutions2'
                                        */
  real_T revolutions2_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/revolutions2'
                                        */
  real_T revolutions2_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/revolutions2'
                                        */
  real_T revolution1_P1;               /* Expression: width
                                        * Referenced by: '<Root>/revolution1'
                                        */
  real_T revolution1_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/revolution1'
                                        */
  real_T revolution1_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/revolution1'
                                        */
  real_T revolution1_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/revolution1'
                                        */
  real_T revolution1_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/revolution1'
                                        */
  real_T revolution1_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/revolution1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T revolutions3_P1;              /* Expression: width
                                        * Referenced by: '<Root>/revolutions3'
                                        */
  real_T revolutions3_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions3'
                                        */
  real_T revolutions3_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions3'
                                        */
  real_T revolutions3_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/revolutions3'
                                        */
  real_T revolutions3_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/revolutions3'
                                        */
  real_T revolutions3_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/revolutions3'
                                        */
  real_T Memory7_X0;                   /* Expression: 0
                                        * Referenced by: '<Root>/Memory7'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Memory4_X0;                   /* Expression: 0
                                        * Referenced by: '<Root>/Memory4'
                                        */
  real_T Memory5_X0;                   /* Expression: 0
                                        * Referenced by: '<Root>/Memory5'
                                        */
  real_T Memory6_X0;                   /* Expression: 0
                                        * Referenced by: '<Root>/Memory6'
                                        */
  real_T measurment2_P1;               /* Expression: width
                                        * Referenced by: '<Root>/measurment2'
                                        */
  real_T measurment2_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/measurment2'
                                        */
  real_T measurment2_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/measurment2'
                                        */
  real_T measurment2_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/measurment2'
                                        */
  real_T measurment2_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/measurment2'
                                        */
  real_T measurment2_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/measurment2'
                                        */
  real_T revolutions4_P1;              /* Expression: width
                                        * Referenced by: '<Root>/revolutions4'
                                        */
  real_T revolutions4_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions4'
                                        */
  real_T revolutions4_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions4'
                                        */
  real_T revolutions4_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/revolutions4'
                                        */
  real_T revolutions4_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/revolutions4'
                                        */
  real_T revolutions4_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/revolutions4'
                                        */
  real_T revolution2_P1;               /* Expression: width
                                        * Referenced by: '<Root>/revolution2'
                                        */
  real_T revolution2_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/revolution2'
                                        */
  real_T revolution2_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/revolution2'
                                        */
  real_T revolution2_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/revolution2'
                                        */
  real_T revolution2_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/revolution2'
                                        */
  real_T revolution2_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/revolution2'
                                        */
  real_T revolutions5_P1;              /* Expression: width
                                        * Referenced by: '<Root>/revolutions5'
                                        */
  real_T revolutions5_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions5'
                                        */
  real_T revolutions5_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions5'
                                        */
  real_T revolutions5_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/revolutions5'
                                        */
  real_T revolutions5_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/revolutions5'
                                        */
  real_T revolutions5_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/revolutions5'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T rpm2_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/rpm2'
                                        */
  real_T rpm2_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/rpm2'
                                        */
  real_T rpm2_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/rpm2'
                                        */
  real_T rpm2_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/rpm2'
                                        */
  real_T rpm2_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/rpm2'
                                        */
  real_T rpm2_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/rpm2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T revolutions6_P1;              /* Expression: width
                                        * Referenced by: '<Root>/revolutions6'
                                        */
  real_T revolutions6_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions6'
                                        */
  real_T revolutions6_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions6'
                                        */
  real_T revolutions6_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/revolutions6'
                                        */
  real_T revolutions6_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/revolutions6'
                                        */
  real_T revolutions6_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/revolutions6'
                                        */
  real_T Memory11_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory11'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T Memory8_X0;                   /* Expression: 0
                                        * Referenced by: '<Root>/Memory8'
                                        */
  real_T Memory9_X0;                   /* Expression: 0
                                        * Referenced by: '<Root>/Memory9'
                                        */
  real_T Memory10_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory10'
                                        */
  real_T measurment3_P1;               /* Expression: width
                                        * Referenced by: '<Root>/measurment3'
                                        */
  real_T measurment3_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/measurment3'
                                        */
  real_T measurment3_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/measurment3'
                                        */
  real_T measurment3_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/measurment3'
                                        */
  real_T measurment3_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/measurment3'
                                        */
  real_T measurment3_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/measurment3'
                                        */
  real_T revolution3_P1;               /* Expression: width
                                        * Referenced by: '<Root>/revolution3'
                                        */
  real_T revolution3_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/revolution3'
                                        */
  real_T revolution3_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/revolution3'
                                        */
  real_T revolution3_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/revolution3'
                                        */
  real_T revolution3_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/revolution3'
                                        */
  real_T revolution3_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/revolution3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 2
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T rpm3_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/rpm3'
                                        */
  real_T rpm3_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/rpm3'
                                        */
  real_T rpm3_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/rpm3'
                                        */
  real_T rpm3_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/rpm3'
                                        */
  real_T rpm3_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/rpm3'
                                        */
  real_T rpm3_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/rpm3'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Memory15_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory15'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  real_T Memory12_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory12'
                                        */
  real_T Memory13_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory13'
                                        */
  real_T Memory14_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory14'
                                        */
  real_T measurment4_P1;               /* Expression: width
                                        * Referenced by: '<Root>/measurment4'
                                        */
  real_T measurment4_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/measurment4'
                                        */
  real_T measurment4_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/measurment4'
                                        */
  real_T measurment4_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/measurment4'
                                        */
  real_T measurment4_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/measurment4'
                                        */
  real_T measurment4_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/measurment4'
                                        */
  real_T revolution4_P1;               /* Expression: width
                                        * Referenced by: '<Root>/revolution4'
                                        */
  real_T revolution4_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/revolution4'
                                        */
  real_T revolution4_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/revolution4'
                                        */
  real_T revolution4_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/revolution4'
                                        */
  real_T revolution4_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/revolution4'
                                        */
  real_T revolution4_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/revolution4'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T rpm4_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/rpm4'
                                        */
  real_T rpm4_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/rpm4'
                                        */
  real_T rpm4_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/rpm4'
                                        */
  real_T rpm4_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/rpm4'
                                        */
  real_T rpm4_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/rpm4'
                                        */
  real_T rpm4_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/rpm4'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Memory19_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory19'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator4'
                                        */
  real_T Memory16_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory16'
                                        */
  real_T Memory17_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory17'
                                        */
  real_T Memory18_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory18'
                                        */
  real_T measurment5_P1;               /* Expression: width
                                        * Referenced by: '<Root>/measurment5'
                                        */
  real_T measurment5_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/measurment5'
                                        */
  real_T measurment5_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/measurment5'
                                        */
  real_T measurment5_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/measurment5'
                                        */
  real_T measurment5_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/measurment5'
                                        */
  real_T measurment5_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/measurment5'
                                        */
  real_T revolution5_P1;               /* Expression: width
                                        * Referenced by: '<Root>/revolution5'
                                        */
  real_T revolution5_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/revolution5'
                                        */
  real_T revolution5_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/revolution5'
                                        */
  real_T revolution5_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/revolution5'
                                        */
  real_T revolution5_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/revolution5'
                                        */
  real_T revolution5_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/revolution5'
                                        */
  real_T Gain3_Gain;                   /* Expression: 2
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T rpm5_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/rpm5'
                                        */
  real_T rpm5_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/rpm5'
                                        */
  real_T rpm5_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/rpm5'
                                        */
  real_T rpm5_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/rpm5'
                                        */
  real_T rpm5_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/rpm5'
                                        */
  real_T rpm5_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/rpm5'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Memory23_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory23'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator5'
                                        */
  real_T Memory20_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory20'
                                        */
  real_T Memory21_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory21'
                                        */
  real_T Memory22_X0;                  /* Expression: 0
                                        * Referenced by: '<Root>/Memory22'
                                        */
  real_T measurment6_P1;               /* Expression: width
                                        * Referenced by: '<Root>/measurment6'
                                        */
  real_T measurment6_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/measurment6'
                                        */
  real_T measurment6_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/measurment6'
                                        */
  real_T measurment6_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/measurment6'
                                        */
  real_T measurment6_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/measurment6'
                                        */
  real_T measurment6_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/measurment6'
                                        */
  real_T revolution6_P1;               /* Expression: width
                                        * Referenced by: '<Root>/revolution6'
                                        */
  real_T revolution6_P2;               /* Expression: dtype
                                        * Referenced by: '<Root>/revolution6'
                                        */
  real_T revolution6_P3;               /* Expression: portnum
                                        * Referenced by: '<Root>/revolution6'
                                        */
  real_T revolution6_P4;               /* Expression: stime
                                        * Referenced by: '<Root>/revolution6'
                                        */
  real_T revolution6_P5;               /* Expression: stype
                                        * Referenced by: '<Root>/revolution6'
                                        */
  real_T revolution6_P6;               /* Expression: btype
                                        * Referenced by: '<Root>/revolution6'
                                        */
  real_T Gain5_Gain;                   /* Expression: 2
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T rpm6_P1;                      /* Expression: width
                                        * Referenced by: '<Root>/rpm6'
                                        */
  real_T rpm6_P2;                      /* Expression: dtype
                                        * Referenced by: '<Root>/rpm6'
                                        */
  real_T rpm6_P3;                      /* Expression: portnum
                                        * Referenced by: '<Root>/rpm6'
                                        */
  real_T rpm6_P4;                      /* Expression: stime
                                        * Referenced by: '<Root>/rpm6'
                                        */
  real_T rpm6_P5;                      /* Expression: stype
                                        * Referenced by: '<Root>/rpm6'
                                        */
  real_T rpm6_P6;                      /* Expression: btype
                                        * Referenced by: '<Root>/rpm6'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_rpm_T {
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
    real_T odeY[6];
    real_T odeF[3][6];
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
extern P_rpm_T rpm_P;

/* Block signals (auto storage) */
extern B_rpm_T rpm_B;

/* Continuous states (auto storage) */
extern X_rpm_T rpm_X;

/* Block states (auto storage) */
extern DW_rpm_T rpm_DW;

/* Model entry point functions */
extern void rpm_initialize(void);
extern void rpm_output(void);
extern void rpm_update(void);
extern void rpm_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern rpm_rtModel *rpm(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_rpm_T *const rpm_M;

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
 * '<Root>' : 'rpm'
 * '<S1>'   : 'rpm/MATLAB Function'
 * '<S2>'   : 'rpm/MATLAB Function1'
 * '<S3>'   : 'rpm/MATLAB Function2'
 * '<S4>'   : 'rpm/MATLAB Function3'
 * '<S5>'   : 'rpm/MATLAB Function4'
 * '<S6>'   : 'rpm/MATLAB Function5'
 */
#endif                                 /* RTW_HEADER_rpm_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : rpm
 * Model version : 1.68
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Sun Jun 26 19:52:37 2016
 *========================================================================*/
#ifdef NI_ROOTMODEL_rpm

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* rpm.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_rpm_T rtParameter[NUMST+!TID01EQ];
P_rpm_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_rpm_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_rpm_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_rpm_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
