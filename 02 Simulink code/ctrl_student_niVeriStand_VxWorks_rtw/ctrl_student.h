/*
 * ctrl_student.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student".
 *
 * Model version              : 1.150
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Thu Feb 02 14:51:44 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ctrl_student_h_
#define RTW_HEADER_ctrl_student_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef ctrl_student_COMMON_INCLUDES_
# define ctrl_student_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* ctrl_student_COMMON_INCLUDES_ */

#include "ctrl_student_types.h"

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
#define ctrl_student_rtModel           RT_MODEL_ctrl_student_T

/* Block signals for system '<S3>/MATLAB Function' */
typedef struct {
  real_T K_p[9];                       /* '<S3>/MATLAB Function' */
} B_MATLABFunction_ctrl_student_T;

/* Block signals for system '<S3>/MATLAB Function1' */
typedef struct {
  real_T K_i[9];                       /* '<S3>/MATLAB Function1' */
} B_MATLABFunction1_ctrl_studen_T;

/* Block signals for system '<S3>/MATLAB Function2' */
typedef struct {
  real_T K_d[9];                       /* '<S3>/MATLAB Function2' */
} B_MATLABFunction2_ctrl_studen_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Saturation1;                  /* '<S6>/Saturation 1' */
  real_T EnableThrust;                 /* '<Root>/Enable Thrust' */
  real_T Saturation2;                  /* '<S6>/Saturation 2' */
  real_T Saturation3;                  /* '<S6>/Saturation 3' */
  real_T Saturation4;                  /* '<S6>/Saturation 4' */
  real_T Saturation5;                  /* '<S6>/Saturation 5' */
  real_T Saturation6;                  /* '<S6>/Saturation 6' */
  real_T Delay;                        /* '<S22>/Delay' */
  real_T wave_dir;                     /* '<S3>/wave_dir' */
  real_T fzp_x;                        /* '<S3>/fzp_x' */
  real_T fzp_y;                        /* '<S3>/fzp_y' */
  real_T r_max;                        /* '<S3>/r_max' */
  real_T Core_controller;              /* '<S3>/Core_controller' */
  real_T K_i_y;                        /* '<S3>/K_i_y' */
  real_T K_d_psi;                      /* '<S3>/K_d_psi' */
  real_T K_d_x;                        /* '<S3>/K_d_x' */
  real_T K_d_y;                        /* '<S3>/K_d_y' */
  real_T K_i_psi;                      /* '<S3>/K_i_psi' */
  real_T K_i_x;                        /* '<S3>/K_i_x' */
  real_T K_p_psi;                      /* '<S3>/K_p_psi' */
  real_T K_p_x;                        /* '<S3>/K_p_x' */
  real_T K_p_y;                        /* '<S3>/K_p_y' */
  real_T K_d_psi1;                     /* '<S3>/K_d_psi1' */
  real_T K_d_x1;                       /* '<S3>/K_d_x1' */
  real_T K_d_y1;                       /* '<S3>/K_d_y1' */
  real_T K_i_psi1;                     /* '<S3>/K_i_psi1' */
  real_T K_i_x1;                       /* '<S3>/K_i_x1' */
  real_T K_i_y1;                       /* '<S3>/K_i_y1' */
  real_T K_p_psi1;                     /* '<S3>/K_p_psi1' */
  real_T K_p_x1;                       /* '<S3>/K_p_x1' */
  real_T K_p_y1;                       /* '<S3>/K_p_y1' */
  real_T eta[3];                       /* '<S21>/Integrator' */
  real_T TmpSignalConversionAtSPInport1[3];
  real_T TmpSignalConversionAtMatrixMult[3];/* '<S34>/Transposed rotation  matrix in yaw1' */
  real_T nu[3];                        /* '<S21>/Integrator4' */
  real_T TmpSignalConversionAtMatrixMu_b[3];/* '<S35>/Transposed rotation  matrix in yaw1' */
  real_T MultiportSwitch[3];           /* '<S22>/Multiport Switch' */
  real_T Product[6];                   /* '<Root>/Product' */
  real_T Gain[6];                      /* '<S5>/Gain' */
  real_T x_m;                          /* '<S4>/x_m' */
  real_T y_m;                          /* '<S4>/y_m' */
  real_T psi_m;                        /* '<S4>/psi_m' */
  real_T Gain3[3];                     /* '<S21>/Gain3' */
  real_T Sum3[3];                      /* '<S21>/Sum3' */
  real_T psi_WF[3];                    /* '<S21>/Sum5' */
  real_T Sum6[3];                      /* '<S21>/Sum6' */
  real_T Sum7[3];                      /* '<S21>/Sum7' */
  real_T Integrator;                   /* '<S22>/Integrator' */
  real_T Sum;                          /* '<S23>/Sum' */
  real_T Sum1[2];                      /* '<S23>/Sum1' */
  real_T reset;                        /* '<S22>/MATLAB Function' */
  real_T y;                            /* '<S22>/MATLAB Function' */
  real_T commanded_tau[3];             /* '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */
  B_MATLABFunction2_ctrl_studen_T sf_MATLABFunction6;/* '<S3>/MATLAB Function6' */
  B_MATLABFunction1_ctrl_studen_T sf_MATLABFunction5;/* '<S3>/MATLAB Function5' */
  B_MATLABFunction_ctrl_student_T sf_MATLABFunction4;/* '<S3>/MATLAB Function4' */
  B_MATLABFunction2_ctrl_studen_T sf_MATLABFunction2;/* '<S3>/MATLAB Function2' */
  B_MATLABFunction1_ctrl_studen_T sf_MATLABFunction1;/* '<S3>/MATLAB Function1' */
  B_MATLABFunction_ctrl_student_T sf_MATLABFunction_f;/* '<S3>/MATLAB Function' */
} B_ctrl_student_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S22>/Delay' */
  real_T alpha_1_DWORK1;               /* '<Root>/alpha_1' */
  real_T EnableThrust_DWORK1;          /* '<Root>/Enable Thrust' */
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
  real_T wave_dir_DWORK1;              /* '<S3>/wave_dir' */
  real_T fzp_x_DWORK1;                 /* '<S3>/fzp_x' */
  real_T fzp_y_DWORK1;                 /* '<S3>/fzp_y' */
  real_T r_max_DWORK1;                 /* '<S3>/r_max' */
  real_T Core_controller_DWORK1;       /* '<S3>/Core_controller' */
  real_T K_i_y_DWORK1;                 /* '<S3>/K_i_y' */
  real_T K_d_psi_DWORK1;               /* '<S3>/K_d_psi' */
  real_T K_d_x_DWORK1;                 /* '<S3>/K_d_x' */
  real_T K_d_y_DWORK1;                 /* '<S3>/K_d_y' */
  real_T K_i_psi_DWORK1;               /* '<S3>/K_i_psi' */
  real_T K_i_x_DWORK1;                 /* '<S3>/K_i_x' */
  real_T K_p_psi_DWORK1;               /* '<S3>/K_p_psi' */
  real_T K_p_x_DWORK1;                 /* '<S3>/K_p_x' */
  real_T K_p_y_DWORK1;                 /* '<S3>/K_p_y' */
  real_T K_d_psi1_DWORK1;              /* '<S3>/K_d_psi1' */
  real_T K_d_x1_DWORK1;                /* '<S3>/K_d_x1' */
  real_T K_d_y1_DWORK1;                /* '<S3>/K_d_y1' */
  real_T K_i_psi1_DWORK1;              /* '<S3>/K_i_psi1' */
  real_T K_i_x1_DWORK1;                /* '<S3>/K_i_x1' */
  real_T K_i_y1_DWORK1;                /* '<S3>/K_i_y1' */
  real_T K_p_psi1_DWORK1;              /* '<S3>/K_p_psi1' */
  real_T K_p_x1_DWORK1;                /* '<S3>/K_p_x1' */
  real_T K_p_y1_DWORK1;                /* '<S3>/K_p_y1' */
  real_T u_1_DWORK1;                   /* '<Root>/u_1' */
  real_T u_4_DWORK1;                   /* '<Root>/u_4' */
  real_T u_5_DWORK1;                   /* '<Root>/u_5' */
  real_T u_6_DWORK1;                   /* '<Root>/u_6' */
  real_T u_2_DWORK1;                   /* '<Root>/u_2' */
  real_T u_3_DWORK1;                   /* '<Root>/u_3' */
  real_T pwm_1_DWORK1;                 /* '<Root>/pwm_1' */
  real_T tau_actual_DWORK1[3];         /* '<Root>/tau_actual' */
  real_T x_m_DWORK1;                   /* '<S4>/x_m' */
  real_T y_m_DWORK1;                   /* '<S4>/y_m' */
  real_T psi_m_DWORK1;                 /* '<S4>/psi_m' */
  real_T eta_est_DWORK1[3];            /* '<S8>/eta_est' */
  real_T nu_est_DWORK1[3];             /* '<S8>/nu_est' */
  real_T SP_DWORK1[3];                 /* '<S8>/SP' */
  real_T tau_des_DWORK1[3];            /* '<S8>/tau_des' */
  real_T controller_DWORK1;            /* '<S22>/controller' */
  real_T timer_DWORK1;                 /* '<S22>/timer' */
  real_T controller;                   /* '<S22>/MATLAB Function' */
  real_T tmp;                          /* '<S22>/MATLAB Function' */
  uint8_T alpha_1_DWORK2[13];          /* '<Root>/alpha_1' */
  uint8_T EnableThrust_DWORK2[13];     /* '<Root>/Enable Thrust' */
  uint8_T pwm_2_DWORK2[13];            /* '<Root>/pwm_2' */
  uint8_T pwm_3_DWORK2[13];            /* '<Root>/pwm_3' */
  uint8_T pwm_4_DWORK2[13];            /* '<Root>/pwm_4' */
  uint8_T pwm_5_DWORK2[13];            /* '<Root>/pwm_5' */
  uint8_T alpha_2_DWORK2[13];          /* '<Root>/alpha_2' */
  uint8_T pwm_6_DWORK2[13];            /* '<Root>/pwm_6' */
  uint8_T alpha_3_DWORK2[13];          /* '<Root>/alpha_3' */
  uint8_T alpha_4_DWORK2[13];          /* '<Root>/alpha_4' */
  uint8_T alpha_5_DWORK2[13];          /* '<Root>/alpha_5' */
  uint8_T alpha_6_DWORK2[13];          /* '<Root>/alpha_6' */
  uint8_T wave_dir_DWORK2[13];         /* '<S3>/wave_dir' */
  uint8_T fzp_x_DWORK2[13];            /* '<S3>/fzp_x' */
  uint8_T fzp_y_DWORK2[13];            /* '<S3>/fzp_y' */
  uint8_T r_max_DWORK2[13];            /* '<S3>/r_max' */
  uint8_T Core_controller_DWORK2[13];  /* '<S3>/Core_controller' */
  uint8_T K_i_y_DWORK2[13];            /* '<S3>/K_i_y' */
  uint8_T K_d_psi_DWORK2[13];          /* '<S3>/K_d_psi' */
  uint8_T K_d_x_DWORK2[13];            /* '<S3>/K_d_x' */
  uint8_T K_d_y_DWORK2[13];            /* '<S3>/K_d_y' */
  uint8_T K_i_psi_DWORK2[13];          /* '<S3>/K_i_psi' */
  uint8_T K_i_x_DWORK2[13];            /* '<S3>/K_i_x' */
  uint8_T K_p_psi_DWORK2[13];          /* '<S3>/K_p_psi' */
  uint8_T K_p_x_DWORK2[13];            /* '<S3>/K_p_x' */
  uint8_T K_p_y_DWORK2[13];            /* '<S3>/K_p_y' */
  uint8_T K_d_psi1_DWORK2[13];         /* '<S3>/K_d_psi1' */
  uint8_T K_d_x1_DWORK2[13];           /* '<S3>/K_d_x1' */
  uint8_T K_d_y1_DWORK2[13];           /* '<S3>/K_d_y1' */
  uint8_T K_i_psi1_DWORK2[13];         /* '<S3>/K_i_psi1' */
  uint8_T K_i_x1_DWORK2[13];           /* '<S3>/K_i_x1' */
  uint8_T K_i_y1_DWORK2[13];           /* '<S3>/K_i_y1' */
  uint8_T K_p_psi1_DWORK2[13];         /* '<S3>/K_p_psi1' */
  uint8_T K_p_x1_DWORK2[13];           /* '<S3>/K_p_x1' */
  uint8_T K_p_y1_DWORK2[13];           /* '<S3>/K_p_y1' */
  uint8_T u_1_DWORK2[13];              /* '<Root>/u_1' */
  uint8_T u_4_DWORK2[13];              /* '<Root>/u_4' */
  uint8_T u_5_DWORK2[13];              /* '<Root>/u_5' */
  uint8_T u_6_DWORK2[13];              /* '<Root>/u_6' */
  uint8_T u_2_DWORK2[13];              /* '<Root>/u_2' */
  uint8_T u_3_DWORK2[13];              /* '<Root>/u_3' */
  uint8_T pwm_1_DWORK2[13];            /* '<Root>/pwm_1' */
  uint8_T tau_actual_DWORK2[13];       /* '<Root>/tau_actual' */
  uint8_T x_m_DWORK2[13];              /* '<S4>/x_m' */
  uint8_T y_m_DWORK2[13];              /* '<S4>/y_m' */
  uint8_T psi_m_DWORK2[13];            /* '<S4>/psi_m' */
  uint8_T eta_est_DWORK2[13];          /* '<S8>/eta_est' */
  uint8_T nu_est_DWORK2[13];           /* '<S8>/nu_est' */
  uint8_T SP_DWORK2[13];               /* '<S8>/SP' */
  uint8_T tau_des_DWORK2[13];          /* '<S8>/tau_des' */
  uint8_T controller_DWORK2[13];       /* '<S22>/controller' */
  uint8_T timer_DWORK2[13];            /* '<S22>/timer' */
} DW_ctrl_student_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S21>/Integrator' */
  real_T Integrator_CSTATE_l[2];       /* '<S23>/Integrator' */
  real_T TransferFcn2_CSTATE;          /* '<S23>/Transfer Fcn2' */
  real_T Integrator_CSTATE_g[3];       /* '<S34>/Integrator' */
  real_T Integrator4_CSTATE[3];        /* '<S21>/Integrator4' */
  real_T Integrator_CSTATE_k[3];       /* '<S35>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S21>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S21>/Integrator2' */
  real_T Integrator3_CSTATE[3];        /* '<S21>/Integrator3' */
  real_T Integrator_CSTATE_d;          /* '<S22>/Integrator' */
} X_ctrl_student_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S21>/Integrator' */
  real_T Integrator_CSTATE_l[2];       /* '<S23>/Integrator' */
  real_T TransferFcn2_CSTATE;          /* '<S23>/Transfer Fcn2' */
  real_T Integrator_CSTATE_g[3];       /* '<S34>/Integrator' */
  real_T Integrator4_CSTATE[3];        /* '<S21>/Integrator4' */
  real_T Integrator_CSTATE_k[3];       /* '<S35>/Integrator' */
  real_T Integrator1_CSTATE[3];        /* '<S21>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S21>/Integrator2' */
  real_T Integrator3_CSTATE[3];        /* '<S21>/Integrator3' */
  real_T Integrator_CSTATE_d;          /* '<S22>/Integrator' */
} XDot_ctrl_student_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[3];      /* '<S21>/Integrator' */
  boolean_T Integrator_CSTATE_l[2];    /* '<S23>/Integrator' */
  boolean_T TransferFcn2_CSTATE;       /* '<S23>/Transfer Fcn2' */
  boolean_T Integrator_CSTATE_g[3];    /* '<S34>/Integrator' */
  boolean_T Integrator4_CSTATE[3];     /* '<S21>/Integrator4' */
  boolean_T Integrator_CSTATE_k[3];    /* '<S35>/Integrator' */
  boolean_T Integrator1_CSTATE[3];     /* '<S21>/Integrator1' */
  boolean_T Integrator2_CSTATE[3];     /* '<S21>/Integrator2' */
  boolean_T Integrator3_CSTATE[3];     /* '<S21>/Integrator3' */
  boolean_T Integrator_CSTATE_d;       /* '<S22>/Integrator' */
} XDis_ctrl_student_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S22>/Integrator' */
} PrevZCX_ctrl_student_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ctrl_student_B
#define BlockIO                        B_ctrl_student_T
#define rtX                            ctrl_student_X
#define ContinuousStates               X_ctrl_student_T
#define rtXdot                         ctrl_student_XDot
#define StateDerivatives               XDot_ctrl_student_T
#define tXdis                          ctrl_student_XDis
#define StateDisabled                  XDis_ctrl_student_T
#define rtP                            ctrl_student_P
#define Parameters                     P_ctrl_student_T
#define rtDWork                        ctrl_student_DW
#define D_Work                         DW_ctrl_student_T
#define rtPrevZCSigState               ctrl_student_PrevZCX
#define PrevZCSigStates                PrevZCX_ctrl_student_T

/* Parameters (auto storage) */
struct P_ctrl_student_T_ {
  real_T Nonlinearpassiveobserver_D[9];/* Mask Parameter: Nonlinearpassiveobserver_D
                                        * Referenced by: '<S21>/Gain6'
                                        */
  real_T Nonlinearpassiveobserver_K3[9];/* Mask Parameter: Nonlinearpassiveobserver_K3
                                         * Referenced by: '<S21>/K3'
                                         */
  real_T Nonlinearpassiveobserver_K4[9];/* Mask Parameter: Nonlinearpassiveobserver_K4
                                         * Referenced by: '<S21>/K4'
                                         */
  real_T Nonlinearpassiveobserver_w_c[9];/* Mask Parameter: Nonlinearpassiveobserver_w_c
                                          * Referenced by: '<S21>/K2'
                                          */
  real_T constantangle_Value[6];       /* Expression: [Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)]
                                        * Referenced by: '<Root>/constant angle'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S6>/Saturation 1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S6>/Saturation 1'
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
  real_T EnableThrust_P1;              /* Expression: width
                                        * Referenced by: '<Root>/Enable Thrust'
                                        */
  real_T EnableThrust_P2;              /* Expression: dtype
                                        * Referenced by: '<Root>/Enable Thrust'
                                        */
  real_T EnableThrust_P3;              /* Expression: portnum
                                        * Referenced by: '<Root>/Enable Thrust'
                                        */
  real_T EnableThrust_P4;              /* Expression: stime
                                        * Referenced by: '<Root>/Enable Thrust'
                                        */
  real_T EnableThrust_P5;              /* Expression: stype
                                        * Referenced by: '<Root>/Enable Thrust'
                                        */
  real_T EnableThrust_P6;              /* Expression: btype
                                        * Referenced by: '<Root>/Enable Thrust'
                                        */
  real_T Constant1_Value[6];           /* Expression: [0 0 0 0 0 0]
                                        * Referenced by: '<Root>/Constant1'
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
                                        * Referenced by: '<S6>/Saturation 2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S6>/Saturation 2'
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
                                        * Referenced by: '<S6>/Saturation 3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S6>/Saturation 3'
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
                                        * Referenced by: '<S6>/Saturation 4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S6>/Saturation 4'
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
                                        * Referenced by: '<S6>/Saturation 5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S6>/Saturation 5'
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
                                        * Referenced by: '<S6>/Saturation 6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S6>/Saturation 6'
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
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S22>/Delay'
                                        */
  real_T wave_dir_P1;                  /* Expression: width
                                        * Referenced by: '<S3>/wave_dir'
                                        */
  real_T wave_dir_P2;                  /* Expression: dtype
                                        * Referenced by: '<S3>/wave_dir'
                                        */
  real_T wave_dir_P3;                  /* Expression: portnum
                                        * Referenced by: '<S3>/wave_dir'
                                        */
  real_T wave_dir_P4;                  /* Expression: stime
                                        * Referenced by: '<S3>/wave_dir'
                                        */
  real_T wave_dir_P5;                  /* Expression: stype
                                        * Referenced by: '<S3>/wave_dir'
                                        */
  real_T wave_dir_P6;                  /* Expression: btype
                                        * Referenced by: '<S3>/wave_dir'
                                        */
  real_T fzp_x_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/fzp_x'
                                        */
  real_T fzp_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/fzp_x'
                                        */
  real_T fzp_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/fzp_x'
                                        */
  real_T fzp_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/fzp_x'
                                        */
  real_T fzp_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/fzp_x'
                                        */
  real_T fzp_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/fzp_x'
                                        */
  real_T fzp_y_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/fzp_y'
                                        */
  real_T fzp_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/fzp_y'
                                        */
  real_T fzp_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/fzp_y'
                                        */
  real_T fzp_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/fzp_y'
                                        */
  real_T fzp_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/fzp_y'
                                        */
  real_T fzp_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/fzp_y'
                                        */
  real_T r_max_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/r_max'
                                        */
  real_T r_max_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/r_max'
                                        */
  real_T r_max_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/r_max'
                                        */
  real_T r_max_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/r_max'
                                        */
  real_T r_max_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/r_max'
                                        */
  real_T r_max_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/r_max'
                                        */
  real_T Core_controller_P1;           /* Expression: width
                                        * Referenced by: '<S3>/Core_controller'
                                        */
  real_T Core_controller_P2;           /* Expression: dtype
                                        * Referenced by: '<S3>/Core_controller'
                                        */
  real_T Core_controller_P3;           /* Expression: portnum
                                        * Referenced by: '<S3>/Core_controller'
                                        */
  real_T Core_controller_P4;           /* Expression: stime
                                        * Referenced by: '<S3>/Core_controller'
                                        */
  real_T Core_controller_P5;           /* Expression: stype
                                        * Referenced by: '<S3>/Core_controller'
                                        */
  real_T Core_controller_P6;           /* Expression: btype
                                        * Referenced by: '<S3>/Core_controller'
                                        */
  real_T K_i_y_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/K_i_y'
                                        */
  real_T K_i_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/K_i_y'
                                        */
  real_T K_i_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/K_i_y'
                                        */
  real_T K_i_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/K_i_y'
                                        */
  real_T K_i_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/K_i_y'
                                        */
  real_T K_i_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/K_i_y'
                                        */
  real_T K_d_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S3>/K_d_psi'
                                        */
  real_T K_d_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S3>/K_d_psi'
                                        */
  real_T K_d_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S3>/K_d_psi'
                                        */
  real_T K_d_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S3>/K_d_psi'
                                        */
  real_T K_d_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S3>/K_d_psi'
                                        */
  real_T K_d_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S3>/K_d_psi'
                                        */
  real_T K_d_x_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/K_d_x'
                                        */
  real_T K_d_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/K_d_x'
                                        */
  real_T K_d_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/K_d_x'
                                        */
  real_T K_d_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/K_d_x'
                                        */
  real_T K_d_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/K_d_x'
                                        */
  real_T K_d_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/K_d_x'
                                        */
  real_T K_d_y_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/K_d_y'
                                        */
  real_T K_d_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/K_d_y'
                                        */
  real_T K_d_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/K_d_y'
                                        */
  real_T K_d_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/K_d_y'
                                        */
  real_T K_d_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/K_d_y'
                                        */
  real_T K_d_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/K_d_y'
                                        */
  real_T K_i_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S3>/K_i_psi'
                                        */
  real_T K_i_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S3>/K_i_psi'
                                        */
  real_T K_i_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S3>/K_i_psi'
                                        */
  real_T K_i_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S3>/K_i_psi'
                                        */
  real_T K_i_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S3>/K_i_psi'
                                        */
  real_T K_i_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S3>/K_i_psi'
                                        */
  real_T K_i_x_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/K_i_x'
                                        */
  real_T K_i_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/K_i_x'
                                        */
  real_T K_i_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/K_i_x'
                                        */
  real_T K_i_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/K_i_x'
                                        */
  real_T K_i_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/K_i_x'
                                        */
  real_T K_i_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/K_i_x'
                                        */
  real_T K_p_psi_P1;                   /* Expression: width
                                        * Referenced by: '<S3>/K_p_psi'
                                        */
  real_T K_p_psi_P2;                   /* Expression: dtype
                                        * Referenced by: '<S3>/K_p_psi'
                                        */
  real_T K_p_psi_P3;                   /* Expression: portnum
                                        * Referenced by: '<S3>/K_p_psi'
                                        */
  real_T K_p_psi_P4;                   /* Expression: stime
                                        * Referenced by: '<S3>/K_p_psi'
                                        */
  real_T K_p_psi_P5;                   /* Expression: stype
                                        * Referenced by: '<S3>/K_p_psi'
                                        */
  real_T K_p_psi_P6;                   /* Expression: btype
                                        * Referenced by: '<S3>/K_p_psi'
                                        */
  real_T K_p_x_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/K_p_x'
                                        */
  real_T K_p_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/K_p_x'
                                        */
  real_T K_p_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/K_p_x'
                                        */
  real_T K_p_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/K_p_x'
                                        */
  real_T K_p_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/K_p_x'
                                        */
  real_T K_p_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/K_p_x'
                                        */
  real_T K_p_y_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/K_p_y'
                                        */
  real_T K_p_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/K_p_y'
                                        */
  real_T K_p_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/K_p_y'
                                        */
  real_T K_p_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/K_p_y'
                                        */
  real_T K_p_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/K_p_y'
                                        */
  real_T K_p_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/K_p_y'
                                        */
  real_T K_d_psi1_P1;                  /* Expression: width
                                        * Referenced by: '<S3>/K_d_psi1'
                                        */
  real_T K_d_psi1_P2;                  /* Expression: dtype
                                        * Referenced by: '<S3>/K_d_psi1'
                                        */
  real_T K_d_psi1_P3;                  /* Expression: portnum
                                        * Referenced by: '<S3>/K_d_psi1'
                                        */
  real_T K_d_psi1_P4;                  /* Expression: stime
                                        * Referenced by: '<S3>/K_d_psi1'
                                        */
  real_T K_d_psi1_P5;                  /* Expression: stype
                                        * Referenced by: '<S3>/K_d_psi1'
                                        */
  real_T K_d_psi1_P6;                  /* Expression: btype
                                        * Referenced by: '<S3>/K_d_psi1'
                                        */
  real_T K_d_x1_P1;                    /* Expression: width
                                        * Referenced by: '<S3>/K_d_x1'
                                        */
  real_T K_d_x1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S3>/K_d_x1'
                                        */
  real_T K_d_x1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S3>/K_d_x1'
                                        */
  real_T K_d_x1_P4;                    /* Expression: stime
                                        * Referenced by: '<S3>/K_d_x1'
                                        */
  real_T K_d_x1_P5;                    /* Expression: stype
                                        * Referenced by: '<S3>/K_d_x1'
                                        */
  real_T K_d_x1_P6;                    /* Expression: btype
                                        * Referenced by: '<S3>/K_d_x1'
                                        */
  real_T K_d_y1_P1;                    /* Expression: width
                                        * Referenced by: '<S3>/K_d_y1'
                                        */
  real_T K_d_y1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S3>/K_d_y1'
                                        */
  real_T K_d_y1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S3>/K_d_y1'
                                        */
  real_T K_d_y1_P4;                    /* Expression: stime
                                        * Referenced by: '<S3>/K_d_y1'
                                        */
  real_T K_d_y1_P5;                    /* Expression: stype
                                        * Referenced by: '<S3>/K_d_y1'
                                        */
  real_T K_d_y1_P6;                    /* Expression: btype
                                        * Referenced by: '<S3>/K_d_y1'
                                        */
  real_T K_i_psi1_P1;                  /* Expression: width
                                        * Referenced by: '<S3>/K_i_psi1'
                                        */
  real_T K_i_psi1_P2;                  /* Expression: dtype
                                        * Referenced by: '<S3>/K_i_psi1'
                                        */
  real_T K_i_psi1_P3;                  /* Expression: portnum
                                        * Referenced by: '<S3>/K_i_psi1'
                                        */
  real_T K_i_psi1_P4;                  /* Expression: stime
                                        * Referenced by: '<S3>/K_i_psi1'
                                        */
  real_T K_i_psi1_P5;                  /* Expression: stype
                                        * Referenced by: '<S3>/K_i_psi1'
                                        */
  real_T K_i_psi1_P6;                  /* Expression: btype
                                        * Referenced by: '<S3>/K_i_psi1'
                                        */
  real_T K_i_x1_P1;                    /* Expression: width
                                        * Referenced by: '<S3>/K_i_x1'
                                        */
  real_T K_i_x1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S3>/K_i_x1'
                                        */
  real_T K_i_x1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S3>/K_i_x1'
                                        */
  real_T K_i_x1_P4;                    /* Expression: stime
                                        * Referenced by: '<S3>/K_i_x1'
                                        */
  real_T K_i_x1_P5;                    /* Expression: stype
                                        * Referenced by: '<S3>/K_i_x1'
                                        */
  real_T K_i_x1_P6;                    /* Expression: btype
                                        * Referenced by: '<S3>/K_i_x1'
                                        */
  real_T K_i_y1_P1;                    /* Expression: width
                                        * Referenced by: '<S3>/K_i_y1'
                                        */
  real_T K_i_y1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S3>/K_i_y1'
                                        */
  real_T K_i_y1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S3>/K_i_y1'
                                        */
  real_T K_i_y1_P4;                    /* Expression: stime
                                        * Referenced by: '<S3>/K_i_y1'
                                        */
  real_T K_i_y1_P5;                    /* Expression: stype
                                        * Referenced by: '<S3>/K_i_y1'
                                        */
  real_T K_i_y1_P6;                    /* Expression: btype
                                        * Referenced by: '<S3>/K_i_y1'
                                        */
  real_T K_p_psi1_P1;                  /* Expression: width
                                        * Referenced by: '<S3>/K_p_psi1'
                                        */
  real_T K_p_psi1_P2;                  /* Expression: dtype
                                        * Referenced by: '<S3>/K_p_psi1'
                                        */
  real_T K_p_psi1_P3;                  /* Expression: portnum
                                        * Referenced by: '<S3>/K_p_psi1'
                                        */
  real_T K_p_psi1_P4;                  /* Expression: stime
                                        * Referenced by: '<S3>/K_p_psi1'
                                        */
  real_T K_p_psi1_P5;                  /* Expression: stype
                                        * Referenced by: '<S3>/K_p_psi1'
                                        */
  real_T K_p_psi1_P6;                  /* Expression: btype
                                        * Referenced by: '<S3>/K_p_psi1'
                                        */
  real_T K_p_x1_P1;                    /* Expression: width
                                        * Referenced by: '<S3>/K_p_x1'
                                        */
  real_T K_p_x1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S3>/K_p_x1'
                                        */
  real_T K_p_x1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S3>/K_p_x1'
                                        */
  real_T K_p_x1_P4;                    /* Expression: stime
                                        * Referenced by: '<S3>/K_p_x1'
                                        */
  real_T K_p_x1_P5;                    /* Expression: stype
                                        * Referenced by: '<S3>/K_p_x1'
                                        */
  real_T K_p_x1_P6;                    /* Expression: btype
                                        * Referenced by: '<S3>/K_p_x1'
                                        */
  real_T K_p_y1_P1;                    /* Expression: width
                                        * Referenced by: '<S3>/K_p_y1'
                                        */
  real_T K_p_y1_P2;                    /* Expression: dtype
                                        * Referenced by: '<S3>/K_p_y1'
                                        */
  real_T K_p_y1_P3;                    /* Expression: portnum
                                        * Referenced by: '<S3>/K_p_y1'
                                        */
  real_T K_p_y1_P4;                    /* Expression: stime
                                        * Referenced by: '<S3>/K_p_y1'
                                        */
  real_T K_p_y1_P5;                    /* Expression: stype
                                        * Referenced by: '<S3>/K_p_y1'
                                        */
  real_T K_p_y1_P6;                    /* Expression: btype
                                        * Referenced by: '<S3>/K_p_y1'
                                        */
  real_T Integrator_IC[3];             /* Expression: [0,0,0]'
                                        * Referenced by: '<S21>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1e10
                                        * Referenced by: '<S39>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1e10
                                        * Referenced by: '<S39>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: pi
                                        * Referenced by: '<S39>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Integrator_IC_b[2];           /* Expression: [0 0]
                                        * Referenced by: '<S23>/Integrator'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S23>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S23>/Transfer Fcn2'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 1e10
                                        * Referenced by: '<S24>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: -1e10
                                        * Referenced by: '<S24>/Saturation'
                                        */
  real_T Gain_Gain_p;                  /* Expression: pi
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T Constant_Value_k;             /* Expression: 2*pi
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 1e10
                                        * Referenced by: '<S38>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: -1e10
                                        * Referenced by: '<S38>/Saturation'
                                        */
  real_T Gain_Gain_l;                  /* Expression: pi
                                        * Referenced by: '<S38>/Gain'
                                        */
  real_T Constant_Value_e;             /* Expression: 2*pi
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T Integrator_IC_f;              /* Expression: 0
                                        * Referenced by: '<S34>/Integrator'
                                        */
  real_T Integrator4_IC[3];            /* Expression: [0,0,0]'
                                        * Referenced by: '<S21>/Integrator4'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 1e10
                                        * Referenced by: '<S42>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -1e10
                                        * Referenced by: '<S42>/Saturation'
                                        */
  real_T Gain_Gain_n;                  /* Expression: pi
                                        * Referenced by: '<S42>/Gain'
                                        */
  real_T Constant_Value_d;             /* Expression: 2*pi
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 1e10
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T Saturation_LowerSat_lh;       /* Expression: -1e10
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T Gain_Gain_j;                  /* Expression: pi
                                        * Referenced by: '<S41>/Gain'
                                        */
  real_T Constant_Value_c;             /* Expression: 2*pi
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S35>/Integrator'
                                        */
  real_T XpositionThruster_Value[6];   /* Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
                                        * Referenced by: '<S7>/X-position Thruster'
                                        */
  real_T YpositionThruster_Value[6];   /* Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
                                        * Referenced by: '<S7>/Y-position Thruster'
                                        */
  real_T constantangle1_Value[6];      /* Expression: [Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)]
                                        * Referenced by: '<S7>/constant angle1'
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
  real_T Gain_Gain_f;                  /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain'
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
  real_T eta_est_P1;                   /* Expression: width
                                        * Referenced by: '<S8>/eta_est'
                                        */
  real_T eta_est_P2;                   /* Expression: dtype
                                        * Referenced by: '<S8>/eta_est'
                                        */
  real_T eta_est_P3;                   /* Expression: portnum
                                        * Referenced by: '<S8>/eta_est'
                                        */
  real_T eta_est_P4;                   /* Expression: stime
                                        * Referenced by: '<S8>/eta_est'
                                        */
  real_T eta_est_P5;                   /* Expression: stype
                                        * Referenced by: '<S8>/eta_est'
                                        */
  real_T eta_est_P6;                   /* Expression: btype
                                        * Referenced by: '<S8>/eta_est'
                                        */
  real_T nu_est_P1;                    /* Expression: width
                                        * Referenced by: '<S8>/nu_est'
                                        */
  real_T nu_est_P2;                    /* Expression: dtype
                                        * Referenced by: '<S8>/nu_est'
                                        */
  real_T nu_est_P3;                    /* Expression: portnum
                                        * Referenced by: '<S8>/nu_est'
                                        */
  real_T nu_est_P4;                    /* Expression: stime
                                        * Referenced by: '<S8>/nu_est'
                                        */
  real_T nu_est_P5;                    /* Expression: stype
                                        * Referenced by: '<S8>/nu_est'
                                        */
  real_T nu_est_P6;                    /* Expression: btype
                                        * Referenced by: '<S8>/nu_est'
                                        */
  real_T SP_P1;                        /* Expression: width
                                        * Referenced by: '<S8>/SP'
                                        */
  real_T SP_P2;                        /* Expression: dtype
                                        * Referenced by: '<S8>/SP'
                                        */
  real_T SP_P3;                        /* Expression: portnum
                                        * Referenced by: '<S8>/SP'
                                        */
  real_T SP_P4;                        /* Expression: stime
                                        * Referenced by: '<S8>/SP'
                                        */
  real_T SP_P5;                        /* Expression: stype
                                        * Referenced by: '<S8>/SP'
                                        */
  real_T SP_P6;                        /* Expression: btype
                                        * Referenced by: '<S8>/SP'
                                        */
  real_T tau_des_P1;                   /* Expression: width
                                        * Referenced by: '<S8>/tau_des'
                                        */
  real_T tau_des_P2;                   /* Expression: dtype
                                        * Referenced by: '<S8>/tau_des'
                                        */
  real_T tau_des_P3;                   /* Expression: portnum
                                        * Referenced by: '<S8>/tau_des'
                                        */
  real_T tau_des_P4;                   /* Expression: stime
                                        * Referenced by: '<S8>/tau_des'
                                        */
  real_T tau_des_P5;                   /* Expression: stype
                                        * Referenced by: '<S8>/tau_des'
                                        */
  real_T tau_des_P6;                   /* Expression: btype
                                        * Referenced by: '<S8>/tau_des'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S21>/Integrator1'
                                        */
  real_T Gain1_Gain_i[9];              /* Expression: 2*lambda*w_o
                                        * Referenced by: '<S21>/Gain1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S21>/Integrator2'
                                        */
  real_T Gain2_Gain[9];                /* Expression: w_o*w_o
                                        * Referenced by: '<S21>/Gain2'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S21>/Integrator3'
                                        */
  real_T Gain3_Gain[9];                /* Expression: inv(M)
                                        * Referenced by: '<S21>/Gain3'
                                        */
  real_T K11_Gain[9];                  /* Expression: -2*(eye(3)-lambda)*diag([w_c(1,1)/w_o(1,1) w_c(2,2)/w_o(2,2) w_c(3,3)/w_o(3,3)])
                                        * Referenced by: '<S21>/K11'
                                        */
  real_T K12_Gain[9];                  /* Expression: 2*w_o*(eye(3)-lambda)
                                        * Referenced by: '<S21>/K12'
                                        */
  real_T invT_b_Gain[9];               /* Expression: diag([1/T_b(1,1) 1/T_b(2,2) 1/T_b(3,3)])
                                        * Referenced by: '<S21>/inv(T_b)'
                                        */
  real_T controller_P1;                /* Expression: width
                                        * Referenced by: '<S22>/controller'
                                        */
  real_T controller_P2;                /* Expression: dtype
                                        * Referenced by: '<S22>/controller'
                                        */
  real_T controller_P3;                /* Expression: portnum
                                        * Referenced by: '<S22>/controller'
                                        */
  real_T controller_P4;                /* Expression: stime
                                        * Referenced by: '<S22>/controller'
                                        */
  real_T controller_P5;                /* Expression: stype
                                        * Referenced by: '<S22>/controller'
                                        */
  real_T controller_P6;                /* Expression: btype
                                        * Referenced by: '<S22>/controller'
                                        */
  real_T timer_P1;                     /* Expression: width
                                        * Referenced by: '<S22>/timer'
                                        */
  real_T timer_P2;                     /* Expression: dtype
                                        * Referenced by: '<S22>/timer'
                                        */
  real_T timer_P3;                     /* Expression: portnum
                                        * Referenced by: '<S22>/timer'
                                        */
  real_T timer_P4;                     /* Expression: stime
                                        * Referenced by: '<S22>/timer'
                                        */
  real_T timer_P5;                     /* Expression: stype
                                        * Referenced by: '<S22>/timer'
                                        */
  real_T timer_P6;                     /* Expression: btype
                                        * Referenced by: '<S22>/timer'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Integrator_IC_d;              /* Expression: 0
                                        * Referenced by: '<S22>/Integrator'
                                        */
  real_T Constant1_Value_p;            /* Expression: pi
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T Gain_Gain_d[4];               /* Expression: diag([1/(1/sqrt(90)) 1/(1/sqrt(90))])
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Gain1_Gain_ib[4];             /* Expression: diag([1/(1/sqrt(90)) 1/(1/sqrt(90))])
                                        * Referenced by: '<S23>/Gain1'
                                        */
  real_T deg2rad_Gain;                 /* Expression: pi/180
                                        * Referenced by: '<S3>/deg2rad'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S22>/Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ctrl_student_T {
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
    real_T odeY[25];
    real_T odeF[3][25];
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
extern P_ctrl_student_T ctrl_student_P;

/* Block signals (auto storage) */
extern B_ctrl_student_T ctrl_student_B;

/* Continuous states (auto storage) */
extern X_ctrl_student_T ctrl_student_X;

/* Block states (auto storage) */
extern DW_ctrl_student_T ctrl_student_DW;

/* Model entry point functions */
extern void ctrl_student_initialize(void);
extern void ctrl_student_output(void);
extern void ctrl_student_update(void);
extern void ctrl_student_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ctrl_student_rtModel *ctrl_student(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ctrl_student_T *const ctrl_student_M;

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
 * '<Root>' : 'ctrl_student'
 * '<S1>'   : 'ctrl_student/Degrees to Radians'
 * '<S2>'   : 'ctrl_student/Finding commanded forces in: [Surge,Sway,Yaw]'
 * '<S3>'   : 'ctrl_student/Input'
 * '<S4>'   : 'ctrl_student/Pos measurements'
 * '<S5>'   : 'ctrl_student/Radians to Degrees'
 * '<S6>'   : 'ctrl_student/Subsystem1'
 * '<S7>'   : 'ctrl_student/TA fixed thrusters, pseudoinverse'
 * '<S8>'   : 'ctrl_student/TAPM Controller w_observer'
 * '<S9>'   : 'ctrl_student/Thrust allocation'
 * '<S10>'  : 'ctrl_student/Thruster Parameters '
 * '<S11>'  : 'ctrl_student/Thruster measurment'
 * '<S12>'  : 'ctrl_student/Input/MATLAB Function'
 * '<S13>'  : 'ctrl_student/Input/MATLAB Function1'
 * '<S14>'  : 'ctrl_student/Input/MATLAB Function2'
 * '<S15>'  : 'ctrl_student/Input/MATLAB Function3'
 * '<S16>'  : 'ctrl_student/Input/MATLAB Function4'
 * '<S17>'  : 'ctrl_student/Input/MATLAB Function5'
 * '<S18>'  : 'ctrl_student/Input/MATLAB Function6'
 * '<S19>'  : 'ctrl_student/TA fixed thrusters, pseudoinverse/MATLAB Function'
 * '<S20>'  : 'ctrl_student/TAPM Controller w_observer/LQR'
 * '<S21>'  : 'ctrl_student/TAPM Controller w_observer/Non-linear passive observer '
 * '<S22>'  : 'ctrl_student/TAPM Controller w_observer/PID'
 * '<S23>'  : 'ctrl_student/TAPM Controller w_observer/SP Generator'
 * '<S24>'  : 'ctrl_student/TAPM Controller w_observer/[-inf inf] to [-pi pi]1'
 * '<S25>'  : 'ctrl_student/TAPM Controller w_observer/heading'
 * '<S26>'  : 'ctrl_student/TAPM Controller w_observer/normalcontrol'
 * '<S27>'  : 'ctrl_student/TAPM Controller w_observer/LQR/MATLAB Function'
 * '<S28>'  : 'ctrl_student/TAPM Controller w_observer/LQR/MATLAB Function1'
 * '<S29>'  : 'ctrl_student/TAPM Controller w_observer/LQR/MATLAB Function2'
 * '<S30>'  : 'ctrl_student/TAPM Controller w_observer/LQR/MATLAB Function3'
 * '<S31>'  : 'ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Rotation matrix in yaw 1'
 * '<S32>'  : 'ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Transposed rotation  matrix in yaw'
 * '<S33>'  : 'ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Transposed rotation  matrix in yaw1'
 * '<S34>'  : 'ctrl_student/TAPM Controller w_observer/PID/DP controller'
 * '<S35>'  : 'ctrl_student/TAPM Controller w_observer/PID/DP controller1'
 * '<S36>'  : 'ctrl_student/TAPM Controller w_observer/PID/MATLAB Function'
 * '<S37>'  : 'ctrl_student/TAPM Controller w_observer/PID/DP controller/Transposed rotation  matrix in yaw1'
 * '<S38>'  : 'ctrl_student/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]'
 * '<S39>'  : 'ctrl_student/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]1'
 * '<S40>'  : 'ctrl_student/TAPM Controller w_observer/PID/DP controller1/Transposed rotation  matrix in yaw1'
 * '<S41>'  : 'ctrl_student/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]'
 * '<S42>'  : 'ctrl_student/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]1'
 * '<S43>'  : 'ctrl_student/TAPM Controller w_observer/SP Generator/Set-Point Limiter'
 * '<S44>'  : 'ctrl_student/Thrust allocation/MATLAB Function'
 * '<S45>'  : 'ctrl_student/Thrust allocation/Optimal angle path and  constraints on rotation speed'
 * '<S46>'  : 'ctrl_student/Thrust allocation/Radians to Degrees'
 * '<S47>'  : 'ctrl_student/Thrust allocation/angle between  [-180 180]'
 * '<S48>'  : 'ctrl_student/Thrust allocation/Optimal angle path and  constraints on rotation speed/Degrees to Radians'
 * '<S49>'  : 'ctrl_student/Thrust allocation/Optimal angle path and  constraints on rotation speed/Ensuring angle is  [-pi pi]'
 * '<S50>'  : 'ctrl_student/Thrust allocation/Optimal angle path and  constraints on rotation speed/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_ctrl_student_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_student
 * Model version : 1.150
 * VeriStand Model Framework version : 2015.1.0.76 (2015 SP1)
 * Source generated on : Thu Feb 02 14:51:44 2017
 *========================================================================*/
#ifdef NI_ROOTMODEL_ctrl_student

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* ctrl_student.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_ctrl_student_T rtParameter[NUMST+!TID01EQ];
P_ctrl_student_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },

  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_ctrl_student_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_ctrl_student_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_ctrl_student_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
