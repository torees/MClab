/*
 * ctrl_student.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student".
 *
 * Model version              : 1.63
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu May 12 11:09:12 2016
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

/* Block signals for system '<S16>/MATLAB Function' */
typedef struct {
  real_T K_p[9];                       /* '<S16>/MATLAB Function' */
} B_MATLABFunction_ctrl_student_T;

/* Block signals for system '<S16>/MATLAB Function1' */
typedef struct {
  real_T K_i[9];                       /* '<S16>/MATLAB Function1' */
} B_MATLABFunction1_ctrl_studen_T;

/* Block signals for system '<S16>/MATLAB Function2' */
typedef struct {
  real_T K_d[9];                       /* '<S16>/MATLAB Function2' */
} B_MATLABFunction2_ctrl_studen_T;

/* Block signals for system '<S10>/MATLAB Function3' */
typedef struct {
  real_T fzp[2];                       /* '<S10>/MATLAB Function3' */
} B_MATLABFunction3_ctrl_studen_T;

/* Block signals for system '<S43>/CoreSubsys' */
typedef struct {
  real_T angle;                        /* '<S43>/Discrete-Time Integrator' */
  real_T Delay;                        /* '<S43>/Delay' */
  real_T MaxRotationRate;              /* '<S43>/Max Rotation Rate' */
} B_CoreSubsys_ctrl_student_T;

/* Block states (auto storage) for system '<S43>/CoreSubsys' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S43>/Discrete-Time Integrator' */
  real_T Delay_DSTATE;                 /* '<S43>/Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S43>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S43>/Discrete-Time Integrator' */
} DW_CoreSubsys_ctrl_student_T;

/* Block signals for system '<S59>/Actual Force and Torque' */
typedef struct {
  real_T Ta;                           /* '<S59>/Actual Force and Torque' */
  real_T Qa;                           /* '<S59>/Actual Force and Torque' */
} B_ActualForceandTorque_ctrl_s_T;

/* Block signals for system '<S63>/Core controller: Torque,Power and Combined Torque//Power' */
typedef struct {
  real_T Qcq;                          /* '<S63>/Core controller: Torque,Power and Combined Torque//Power' */
  real_T Qcp;                          /* '<S63>/Core controller: Torque,Power and Combined Torque//Power' */
  real_T Qcc;                          /* '<S63>/Core controller: Torque,Power and Combined Torque//Power' */
} B_CorecontrollerTorquePoweran_T;

/* Block signals for system '<S61>/Supervisor' */
typedef struct {
  real_T u;                            /* '<S61>/Supervisor' */
} B_Supervisor_ctrl_student_T;

/* Block signals for system '<S71>/MATLAB Function' */
typedef struct {
  real_T n_d;                          /* '<S71>/MATLAB Function' */
  real_T T_r;                          /* '<S71>/MATLAB Function' */
} B_MATLABFunction_ctrl_stude_m_T;

/* Block signals for system '<S71>/Torque limit' */
typedef struct {
  real_T Q_c;                          /* '<S71>/Torque limit' */
} B_Torquelimit_ctrl_student_T;

/* Block signals (auto storage) */
typedef struct {
  real_T r_max;                        /* '<S10>/r_max' */
  real_T K_p_x_in;                     /* '<S16>/K_p_x_in' */
  real_T K_p_y_in;                     /* '<S16>/K_p_y_in' */
  real_T K_p_psi_in;                   /* '<S16>/K_p_psi_in' */
  real_T eta[3];                       /* '<S9>/Integrator' */
  real_T fzp_x;                        /* '<S11>/fzp_x' */
  real_T fzp_y;                        /* '<S11>/fzp_y' */
  real_T r_max_j;                      /* '<S11>/r_max' */
  real_T TransferFcn2;                 /* '<S11>/Transfer Fcn2' */
  real_T K_i_psi_in;                   /* '<S16>/K_i_psi_in' */
  real_T K_i_x_in;                     /* '<S16>/K_i_x_in' */
  real_T K_i_y_in;                     /* '<S16>/K_i_y_in' */
  real_T K_d_psi_in;                   /* '<S16>/K_d_psi_in' */
  real_T K_d_x_in;                     /* '<S16>/K_d_x_in' */
  real_T K_d_y_in;                     /* '<S16>/K_d_y_in' */
  real_T TmpSignalConversionAtProductInp[3];/* '<S16>/Transposed rotation  matrix in yaw1' */
  real_T nu[3];                        /* '<S9>/Integrator4' */
  real_T K_d_psi_out;                  /* '<S19>/K_d_psi_out' */
  real_T K_d_x_out;                    /* '<S19>/K_d_x_out' */
  real_T K_d_y_out;                    /* '<S19>/K_d_y_out' */
  real_T K_i_psi_out;                  /* '<S19>/K_i_psi_out' */
  real_T K_i_x_out;                    /* '<S19>/K_i_x_out' */
  real_T K_i_y_out;                    /* '<S19>/K_i_y_out' */
  real_T K_p_psi_out;                  /* '<S19>/K_p_psi_out' */
  real_T K_p_x_out;                    /* '<S19>/K_p_x_out' */
  real_T K_p_y_out;                    /* '<S19>/K_p_y_out' */
  real_T TmpSignalConversionAtProductI_d[3];/* '<S19>/Transposed rotation  matrix in yaw1' */
  real_T fzp_x_k;                      /* '<S10>/fzp_x' */
  real_T fzp_y_a;                      /* '<S10>/fzp_y' */
  real_T Delay;                        /* '<S10>/Delay' */
  real_T MultiportSwitch[3];           /* '<S10>/Multiport Switch' */
  real_T thr_angle_1;                  /* '<S8>/thr_angle_1' */
  real_T thr_angle_2;                  /* '<S8>/thr_angle_2' */
  real_T thr_angle_3;                  /* '<S8>/thr_angle_3' */
  real_T thr_angle_4;                  /* '<S8>/thr_angle_4' */
  real_T thr_angle_5;                  /* '<S8>/thr_angle_5' */
  real_T thr_angle_6;                  /* '<S8>/thr_angle_6' */
  real_T ChoosingFixedAzimuthangle[6]; /* '<S6>/Choosing Fixed // Azimuth angle' */
  real_T reset[6];                     /* '<S6>/reset' */
  real_T Saturation1;                  /* '<S51>/Saturation 1' */
  real_T reset_e;                      /* '<S60>/reset' */
  real_T reset_b;                      /* '<S70>/reset' */
  real_T reset_k;                      /* '<S80>/reset' */
  real_T reset_h;                      /* '<S90>/reset' */
  real_T reset_l;                      /* '<S100>/reset' */
  real_T reset_o;                      /* '<S110>/reset' */
  real_T pwmthruster2;                 /* '<S50>/pwm thruster 2' */
  real_T pwmthruster3;                 /* '<S50>/pwm thruster 3' */
  real_T pwmthruster4;                 /* '<S50>/pwm thruster 4' */
  real_T pwmthruster5;                 /* '<S50>/pwm thruster 5' */
  real_T Saturation2;                  /* '<S51>/Saturation 2' */
  real_T pwmthruster6;                 /* '<S50>/pwm thruster 6' */
  real_T Saturation3;                  /* '<S51>/Saturation 3' */
  real_T Saturation4;                  /* '<S51>/Saturation 4' */
  real_T Saturation5;                  /* '<S51>/Saturation 5' */
  real_T Saturation6;                  /* '<S51>/Saturation 6' */
  real_T Saturation7[6];               /* '<S50>/Saturation 7' */
  real_T pwmthruster1;                 /* '<S50>/pwm thruster 1' */
  real_T x_m;                          /* '<S3>/x_m' */
  real_T y_m;                          /* '<S3>/y_m' */
  real_T psi_m;                        /* '<S3>/psi_m' */
  real_T wave_dir;                     /* '<S5>/wave_dir' */
  real_T TmpSignalConversionAtSPInport1[3];
  real_T Gain3[3];                     /* '<S9>/Gain3' */
  real_T Sum3[3];                      /* '<S9>/Sum3' */
  real_T psi_WF[3];                    /* '<S9>/Sum5' */
  real_T Sum6[3];                      /* '<S9>/Sum6' */
  real_T Sum7[3];                      /* '<S9>/Sum7' */
  real_T Integrator;                   /* '<S10>/Integrator' */
  real_T Sum;                          /* '<S11>/Sum' */
  real_T Sum1[2];                      /* '<S11>/Sum1' */
  real_T Delay_j[6];                   /* '<S7>/Delay' */
  real_T Delay_h;                      /* '<S61>/Delay' */
  real_T DiscreteTransferFcn;          /* '<S61>/Discrete Transfer Fcn' */
  real_T TSamp;                        /* '<S64>/TSamp' */
  real_T Inertiacompensation;          /* '<S61>/Inertia compensation' */
  real_T Sum1_i;                       /* '<S61>/Sum1' */
  real_T Memory;                       /* '<S61>/Memory' */
  real_T reset_g;                      /* '<S63>/reset' */
  real_T Sum1_it;                      /* '<S63>/Sum1' */
  real_T Findingrotationspeed;         /* '<S60>/Finding rotation speed' */
  real_T Ki;                           /* '<S63>/Ki' */
  real_T Delay_p;                      /* '<S71>/Delay' */
  real_T DiscreteTransferFcn_i;        /* '<S71>/Discrete Transfer Fcn' */
  real_T TSamp_k;                      /* '<S74>/TSamp' */
  real_T Inertiacompensation_h;        /* '<S71>/Inertia compensation' */
  real_T Sum1_c;                       /* '<S71>/Sum1' */
  real_T Memory_p;                     /* '<S71>/Memory' */
  real_T reset_hc;                     /* '<S73>/reset' */
  real_T Sum1_n;                       /* '<S73>/Sum1' */
  real_T Findingrotationspeed_d;       /* '<S70>/Finding rotation speed' */
  real_T Ki_h;                         /* '<S73>/Ki' */
  real_T Delay_m;                      /* '<S81>/Delay' */
  real_T DiscreteTransferFcn_g;        /* '<S81>/Discrete Transfer Fcn' */
  real_T TSamp_e;                      /* '<S84>/TSamp' */
  real_T Inertiacompensation_n;        /* '<S81>/Inertia compensation' */
  real_T Sum1_h;                       /* '<S81>/Sum1' */
  real_T Memory_b;                     /* '<S81>/Memory' */
  real_T reset_c;                      /* '<S83>/reset' */
  real_T Sum1_g;                       /* '<S83>/Sum1' */
  real_T Findingrotationspeed_dl;      /* '<S80>/Finding rotation speed' */
  real_T Ki_f;                         /* '<S83>/Ki' */
  real_T Delay_pc;                     /* '<S91>/Delay' */
  real_T DiscreteTransferFcn_ia;       /* '<S91>/Discrete Transfer Fcn' */
  real_T TSamp_c;                      /* '<S94>/TSamp' */
  real_T Inertiacompensation_p;        /* '<S91>/Inertia compensation' */
  real_T Sum1_b;                       /* '<S91>/Sum1' */
  real_T Memory_k;                     /* '<S91>/Memory' */
  real_T reset_a;                      /* '<S93>/reset' */
  real_T Sum1_m;                       /* '<S93>/Sum1' */
  real_T Findingrotationspeed_m;       /* '<S90>/Finding rotation speed' */
  real_T Ki_c;                         /* '<S93>/Ki' */
  real_T Delay_l;                      /* '<S101>/Delay' */
  real_T DiscreteTransferFcn_j;        /* '<S101>/Discrete Transfer Fcn' */
  real_T TSamp_f;                      /* '<S104>/TSamp' */
  real_T Inertiacompensation_i;        /* '<S101>/Inertia compensation' */
  real_T Sum1_nq;                      /* '<S101>/Sum1' */
  real_T Memory_g;                     /* '<S101>/Memory' */
  real_T reset_i;                      /* '<S103>/reset' */
  real_T Sum1_j;                       /* '<S103>/Sum1' */
  real_T Findingrotationspeed_a;       /* '<S100>/Finding rotation speed' */
  real_T Ki_cz;                        /* '<S103>/Ki' */
  real_T Delay_k;                      /* '<S111>/Delay' */
  real_T DiscreteTransferFcn_ip;       /* '<S111>/Discrete Transfer Fcn' */
  real_T TSamp_ki;                     /* '<S114>/TSamp' */
  real_T Inertiacompensation_d;        /* '<S111>/Inertia compensation' */
  real_T Sum1_o;                       /* '<S111>/Sum1' */
  real_T Memory_e;                     /* '<S111>/Memory' */
  real_T reset_lm;                     /* '<S113>/reset' */
  real_T Sum1_l;                       /* '<S113>/Sum1' */
  real_T Findingrotationspeed_o;       /* '<S110>/Finding rotation speed' */
  real_T Ki_e;                         /* '<S113>/Ki' */
  real_T TmpSignalConversionAtDelayInpor[6];/* '<S7>/Subsystem' */
  real_T n_d;                          /* '<S111>/MATLAB Function' */
  real_T Q_c;                          /* '<S61>/Torque limit' */
  real_T n_d_f;                        /* '<S61>/MATLAB Function' */
  real_T sp_new[2];                    /* '<S11>/Set-Point Limiter' */
  real_T reset_p;                      /* '<S10>/MATLAB Function' */
  real_T y;                            /* '<S10>/MATLAB Function' */
  real_T actual_tau[3];                /* '<Root>/MATLAB Function' */
  B_Torquelimit_ctrl_student_T sf_Torquelimit_j;/* '<S111>/Torque limit' */
  B_Supervisor_ctrl_student_T sf_Supervisor_nw;/* '<S111>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_o;/* '<S113>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_s_T sf_ActualForceandTorque_b;/* '<S109>/Actual Force and Torque' */
  B_Torquelimit_ctrl_student_T sf_Torquelimit_h;/* '<S101>/Torque limit' */
  B_Supervisor_ctrl_student_T sf_Supervisor_pb;/* '<S101>/Supervisor' */
  B_MATLABFunction_ctrl_stude_m_T sf_MATLABFunction_oa;/* '<S101>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_g;/* '<S103>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_s_T sf_ActualForceandTorque_f4;/* '<S99>/Actual Force and Torque' */
  B_Torquelimit_ctrl_student_T sf_Torquelimit_a;/* '<S91>/Torque limit' */
  B_Supervisor_ctrl_student_T sf_Supervisor_p;/* '<S91>/Supervisor' */
  B_MATLABFunction_ctrl_stude_m_T sf_MATLABFunction_p;/* '<S91>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_h;/* '<S93>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_s_T sf_ActualForceandTorque_k;/* '<S89>/Actual Force and Torque' */
  B_Torquelimit_ctrl_student_T sf_Torquelimit_ey;/* '<S81>/Torque limit' */
  B_Supervisor_ctrl_student_T sf_Supervisor_n;/* '<S81>/Supervisor' */
  B_MATLABFunction_ctrl_stude_m_T sf_MATLABFunction_h;/* '<S81>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_p;/* '<S83>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_s_T sf_ActualForceandTorque_f;/* '<S79>/Actual Force and Torque' */
  B_Torquelimit_ctrl_student_T sf_Torquelimit_e;/* '<S71>/Torque limit' */
  B_Supervisor_ctrl_student_T sf_Supervisor_m;/* '<S71>/Supervisor' */
  B_MATLABFunction_ctrl_stude_m_T sf_MATLABFunction_c;/* '<S71>/MATLAB Function' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowera_k;/* '<S73>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_s_T sf_ActualForceandTorque_n;/* '<S69>/Actual Force and Torque' */
  B_Supervisor_ctrl_student_T sf_Supervisor;/* '<S61>/Supervisor' */
  B_CorecontrollerTorquePoweran_T sf_CorecontrollerTorquePowerand;/* '<S63>/Core controller: Torque,Power and Combined Torque//Power' */
  B_ActualForceandTorque_ctrl_s_T sf_ActualForceandTorque;/* '<S59>/Actual Force and Torque' */
  B_CoreSubsys_ctrl_student_T CoreSubsys[6];/* '<S43>/CoreSubsys' */
  B_MATLABFunction3_ctrl_studen_T sf_MATLABFunction3;/* '<S11>/MATLAB Function3' */
  B_MATLABFunction2_ctrl_studen_T sf_MATLABFunction6;/* '<S19>/MATLAB Function6' */
  B_MATLABFunction1_ctrl_studen_T sf_MATLABFunction5;/* '<S19>/MATLAB Function5' */
  B_MATLABFunction_ctrl_student_T sf_MATLABFunction4;/* '<S19>/MATLAB Function4' */
  B_MATLABFunction3_ctrl_studen_T sf_MATLABFunction3_f;/* '<S10>/MATLAB Function3' */
  B_MATLABFunction2_ctrl_studen_T sf_MATLABFunction2;/* '<S16>/MATLAB Function2' */
  B_MATLABFunction1_ctrl_studen_T sf_MATLABFunction1;/* '<S16>/MATLAB Function1' */
  B_MATLABFunction_ctrl_student_T sf_MATLABFunction;/* '<S16>/MATLAB Function' */
} B_ctrl_student_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S10>/Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S60>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S70>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S80>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S90>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S100>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S110>/Discrete-Time Integrator' */
  real_T Delay_DSTATE_o[6];            /* '<S7>/Delay' */
  real_T Delay_DSTATE_g;               /* '<S52>/Delay' */
  real_T Delay_DSTATE_ow;              /* '<S61>/Delay' */
  real_T DiscreteTransferFcn_states[2];/* '<S61>/Discrete Transfer Fcn' */
  real_T UD_DSTATE;                    /* '<S64>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S63>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_h; /* '<S52>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_l;               /* '<S53>/Delay' */
  real_T Delay_DSTATE_n;               /* '<S71>/Delay' */
  real_T DiscreteTransferFcn_states_h0[2];/* '<S71>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_m;                  /* '<S74>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S73>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_k; /* '<S53>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_d;               /* '<S54>/Delay' */
  real_T Delay_DSTATE_g1;              /* '<S81>/Delay' */
  real_T DiscreteTransferFcn_states_a[2];/* '<S81>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_e;                  /* '<S84>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S83>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_kb;/* '<S54>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_j;               /* '<S55>/Delay' */
  real_T Delay_DSTATE_na;              /* '<S91>/Delay' */
  real_T DiscreteTransferFcn_states_i[2];/* '<S91>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_c;                  /* '<S94>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S93>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_n; /* '<S55>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_c;               /* '<S56>/Delay' */
  real_T Delay_DSTATE_ok;              /* '<S101>/Delay' */
  real_T DiscreteTransferFcn_states_nd[2];/* '<S101>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_m1;                 /* '<S104>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S103>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_d; /* '<S56>/Discrete Transfer Fcn' */
  real_T Delay_DSTATE_cx;              /* '<S57>/Delay' */
  real_T Delay_DSTATE_e;               /* '<S111>/Delay' */
  real_T DiscreteTransferFcn_states_e[2];/* '<S111>/Discrete Transfer Fcn' */
  real_T UD_DSTATE_k;                  /* '<S114>/UD' */
  real_T DiscreteTimeIntegrator_DSTAT_ik;/* '<S113>/Discrete-Time Integrator' */
  real_T DiscreteTransferFcn_states_hr;/* '<S57>/Discrete Transfer Fcn' */
  real_T r_max_DWORK1;                 /* '<S10>/r_max' */
  real_T K_p_x_in_DWORK1;              /* '<S16>/K_p_x_in' */
  real_T K_p_y_in_DWORK1;              /* '<S16>/K_p_y_in' */
  real_T K_p_psi_in_DWORK1;            /* '<S16>/K_p_psi_in' */
  real_T fzp_x_DWORK1;                 /* '<S11>/fzp_x' */
  real_T fzp_y_DWORK1;                 /* '<S11>/fzp_y' */
  real_T r_max_DWORK1_f;               /* '<S11>/r_max' */
  real_T K_i_psi_in_DWORK1;            /* '<S16>/K_i_psi_in' */
  real_T K_i_x_in_DWORK1;              /* '<S16>/K_i_x_in' */
  real_T K_i_y_in_DWORK1;              /* '<S16>/K_i_y_in' */
  real_T K_d_psi_in_DWORK1;            /* '<S16>/K_d_psi_in' */
  real_T K_d_x_in_DWORK1;              /* '<S16>/K_d_x_in' */
  real_T K_d_y_in_DWORK1;              /* '<S16>/K_d_y_in' */
  real_T TimeStampA;                   /* '<S16>/Derivative' */
  real_T LastUAtTimeA[3];              /* '<S16>/Derivative' */
  real_T TimeStampB;                   /* '<S16>/Derivative' */
  real_T LastUAtTimeB[3];              /* '<S16>/Derivative' */
  real_T K_d_psi_out_DWORK1;           /* '<S19>/K_d_psi_out' */
  real_T K_d_x_out_DWORK1;             /* '<S19>/K_d_x_out' */
  real_T K_d_y_out_DWORK1;             /* '<S19>/K_d_y_out' */
  real_T K_i_psi_out_DWORK1;           /* '<S19>/K_i_psi_out' */
  real_T K_i_x_out_DWORK1;             /* '<S19>/K_i_x_out' */
  real_T K_i_y_out_DWORK1;             /* '<S19>/K_i_y_out' */
  real_T K_p_psi_out_DWORK1;           /* '<S19>/K_p_psi_out' */
  real_T K_p_x_out_DWORK1;             /* '<S19>/K_p_x_out' */
  real_T K_p_y_out_DWORK1;             /* '<S19>/K_p_y_out' */
  real_T TimeStampA_b;                 /* '<S19>/Derivative' */
  real_T LastUAtTimeA_l[3];            /* '<S19>/Derivative' */
  real_T TimeStampB_n;                 /* '<S19>/Derivative' */
  real_T LastUAtTimeB_h[3];            /* '<S19>/Derivative' */
  real_T fzp_x_DWORK1_i;               /* '<S10>/fzp_x' */
  real_T fzp_y_DWORK1_l;               /* '<S10>/fzp_y' */
  real_T controller_DWORK1;            /* '<S10>/controller' */
  real_T thr_angle_1_DWORK1;           /* '<S8>/thr_angle_1' */
  real_T thr_angle_2_DWORK1;           /* '<S8>/thr_angle_2' */
  real_T thr_angle_3_DWORK1;           /* '<S8>/thr_angle_3' */
  real_T thr_angle_4_DWORK1;           /* '<S8>/thr_angle_4' */
  real_T thr_angle_5_DWORK1;           /* '<S8>/thr_angle_5' */
  real_T thr_angle_6_DWORK1;           /* '<S8>/thr_angle_6' */
  real_T reset_DWORK1[6];              /* '<S6>/reset' */
  real_T alpha_1_DWORK1;               /* '<Root>/alpha_1' */
  real_T reset_DWORK1_g;               /* '<S60>/reset' */
  real_T reset_DWORK1_g5;              /* '<S70>/reset' */
  real_T reset_DWORK1_o;               /* '<S80>/reset' */
  real_T reset_DWORK1_h;               /* '<S90>/reset' */
  real_T reset_DWORK1_k;               /* '<S100>/reset' */
  real_T reset_DWORK1_a;               /* '<S110>/reset' */
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
  real_T x_m_DWORK1;                   /* '<S3>/x_m' */
  real_T y_m_DWORK1;                   /* '<S3>/y_m' */
  real_T psi_m_DWORK1;                 /* '<S3>/psi_m' */
  real_T eta_est_DWORK1[3];            /* '<S5>/eta_est' */
  real_T wave_dir_DWORK1;              /* '<S5>/wave_dir' */
  real_T nu_est_DWORK1[3];             /* '<S5>/nu_est' */
  real_T tau_des_DWORK1[3];            /* '<S5>/tau_des' */
  real_T SP_DWORK1[3];                 /* '<S5>/SP' */
  real_T DiscreteTransferFcn_tmp;      /* '<S61>/Discrete Transfer Fcn' */
  real_T PrevY;                        /* '<S61>/Acceleration Limit' */
  real_T Memory_PreviousInput;         /* '<S61>/Memory' */
  real_T reset_DWORK1_j;               /* '<S63>/reset' */
  real_T DiscreteTransferFcn_tmp_f;    /* '<S52>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_o;    /* '<S71>/Discrete Transfer Fcn' */
  real_T PrevY_a;                      /* '<S71>/Acceleration Limit' */
  real_T Memory_PreviousInput_f;       /* '<S71>/Memory' */
  real_T reset_DWORK1_e;               /* '<S73>/reset' */
  real_T DiscreteTransferFcn_tmp_g;    /* '<S53>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_p;    /* '<S81>/Discrete Transfer Fcn' */
  real_T PrevY_as;                     /* '<S81>/Acceleration limiter' */
  real_T Memory_PreviousInput_o;       /* '<S81>/Memory' */
  real_T reset_DWORK1_p;               /* '<S83>/reset' */
  real_T DiscreteTransferFcn_tmp_fb;   /* '<S54>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_i;    /* '<S91>/Discrete Transfer Fcn' */
  real_T PrevY_p;                      /* '<S91>/Acceleration limiter' */
  real_T Memory_PreviousInput_i;       /* '<S91>/Memory' */
  real_T reset_DWORK1_b;               /* '<S93>/reset' */
  real_T DiscreteTransferFcn_tmp_pk;   /* '<S55>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_j;    /* '<S101>/Discrete Transfer Fcn' */
  real_T PrevY_e;                      /* '<S101>/Acceleration limiter' */
  real_T Memory_PreviousInput_fy;      /* '<S101>/Memory' */
  real_T reset_DWORK1_m;               /* '<S103>/reset' */
  real_T DiscreteTransferFcn_tmp_j4;   /* '<S56>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn_tmp_n;    /* '<S111>/Discrete Transfer Fcn' */
  real_T PrevY_pm;                     /* '<S111>/Acceleration limiter' */
  real_T Memory_PreviousInput_ok;      /* '<S111>/Memory' */
  real_T reset_DWORK1_d;               /* '<S113>/reset' */
  real_T DiscreteTransferFcn_tmp_k;    /* '<S57>/Discrete Transfer Fcn' */
  real_T controller;                   /* '<S10>/MATLAB Function' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S60>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_n;/* '<S70>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_b;/* '<S80>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_ba;/* '<S90>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_p;/* '<S100>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_j;/* '<S110>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevR_pz;/* '<S63>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_f;/* '<S73>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_i;/* '<S83>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_c;/* '<S93>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_e;/* '<S103>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_o;/* '<S113>/Discrete-Time Integrator' */
  uint8_T r_max_DWORK2[13];            /* '<S10>/r_max' */
  uint8_T K_p_x_in_DWORK2[13];         /* '<S16>/K_p_x_in' */
  uint8_T K_p_y_in_DWORK2[13];         /* '<S16>/K_p_y_in' */
  uint8_T K_p_psi_in_DWORK2[13];       /* '<S16>/K_p_psi_in' */
  uint8_T fzp_x_DWORK2[13];            /* '<S11>/fzp_x' */
  uint8_T fzp_y_DWORK2[13];            /* '<S11>/fzp_y' */
  uint8_T r_max_DWORK2_g[13];          /* '<S11>/r_max' */
  uint8_T K_i_psi_in_DWORK2[13];       /* '<S16>/K_i_psi_in' */
  uint8_T K_i_x_in_DWORK2[13];         /* '<S16>/K_i_x_in' */
  uint8_T K_i_y_in_DWORK2[13];         /* '<S16>/K_i_y_in' */
  uint8_T K_d_psi_in_DWORK2[13];       /* '<S16>/K_d_psi_in' */
  uint8_T K_d_x_in_DWORK2[13];         /* '<S16>/K_d_x_in' */
  uint8_T K_d_y_in_DWORK2[13];         /* '<S16>/K_d_y_in' */
  uint8_T K_d_psi_out_DWORK2[13];      /* '<S19>/K_d_psi_out' */
  uint8_T K_d_x_out_DWORK2[13];        /* '<S19>/K_d_x_out' */
  uint8_T K_d_y_out_DWORK2[13];        /* '<S19>/K_d_y_out' */
  uint8_T K_i_psi_out_DWORK2[13];      /* '<S19>/K_i_psi_out' */
  uint8_T K_i_x_out_DWORK2[13];        /* '<S19>/K_i_x_out' */
  uint8_T K_i_y_out_DWORK2[13];        /* '<S19>/K_i_y_out' */
  uint8_T K_p_psi_out_DWORK2[13];      /* '<S19>/K_p_psi_out' */
  uint8_T K_p_x_out_DWORK2[13];        /* '<S19>/K_p_x_out' */
  uint8_T K_p_y_out_DWORK2[13];        /* '<S19>/K_p_y_out' */
  uint8_T fzp_x_DWORK2_j[13];          /* '<S10>/fzp_x' */
  uint8_T fzp_y_DWORK2_e[13];          /* '<S10>/fzp_y' */
  uint8_T controller_DWORK2[13];       /* '<S10>/controller' */
  uint8_T thr_angle_1_DWORK2[13];      /* '<S8>/thr_angle_1' */
  uint8_T thr_angle_2_DWORK2[13];      /* '<S8>/thr_angle_2' */
  uint8_T thr_angle_3_DWORK2[13];      /* '<S8>/thr_angle_3' */
  uint8_T thr_angle_4_DWORK2[13];      /* '<S8>/thr_angle_4' */
  uint8_T thr_angle_5_DWORK2[13];      /* '<S8>/thr_angle_5' */
  uint8_T thr_angle_6_DWORK2[13];      /* '<S8>/thr_angle_6' */
  uint8_T reset_DWORK2[13];            /* '<S6>/reset' */
  uint8_T alpha_1_DWORK2[13];          /* '<Root>/alpha_1' */
  uint8_T reset_DWORK2_b[13];          /* '<S60>/reset' */
  uint8_T reset_DWORK2_a[13];          /* '<S70>/reset' */
  uint8_T reset_DWORK2_i[13];          /* '<S80>/reset' */
  uint8_T reset_DWORK2_j[13];          /* '<S90>/reset' */
  uint8_T reset_DWORK2_h[13];          /* '<S100>/reset' */
  uint8_T reset_DWORK2_p[13];          /* '<S110>/reset' */
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
  uint8_T u_1_DWORK2[13];              /* '<Root>/u_1' */
  uint8_T u_4_DWORK2[13];              /* '<Root>/u_4' */
  uint8_T u_5_DWORK2[13];              /* '<Root>/u_5' */
  uint8_T u_6_DWORK2[13];              /* '<Root>/u_6' */
  uint8_T u_2_DWORK2[13];              /* '<Root>/u_2' */
  uint8_T u_3_DWORK2[13];              /* '<Root>/u_3' */
  uint8_T pwm_1_DWORK2[13];            /* '<Root>/pwm_1' */
  uint8_T tau_actual_DWORK2[13];       /* '<Root>/tau_actual' */
  uint8_T x_m_DWORK2[13];              /* '<S3>/x_m' */
  uint8_T y_m_DWORK2[13];              /* '<S3>/y_m' */
  uint8_T psi_m_DWORK2[13];            /* '<S3>/psi_m' */
  uint8_T eta_est_DWORK2[13];          /* '<S5>/eta_est' */
  uint8_T wave_dir_DWORK2[13];         /* '<S5>/wave_dir' */
  uint8_T nu_est_DWORK2[13];           /* '<S5>/nu_est' */
  uint8_T tau_des_DWORK2[13];          /* '<S5>/tau_des' */
  uint8_T SP_DWORK2[13];               /* '<S5>/SP' */
  uint8_T reset_DWORK2_bf[13];         /* '<S63>/reset' */
  uint8_T reset_DWORK2_ab[13];         /* '<S73>/reset' */
  uint8_T reset_DWORK2_i2[13];         /* '<S83>/reset' */
  uint8_T reset_DWORK2_pj[13];         /* '<S93>/reset' */
  uint8_T reset_DWORK2_p5[13];         /* '<S103>/reset' */
  uint8_T reset_DWORK2_e[13];          /* '<S113>/reset' */
  DW_CoreSubsys_ctrl_student_T CoreSubsys[6];/* '<S43>/CoreSubsys' */
} DW_ctrl_student_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S9>/Integrator' */
  real_T Integrator_CSTATE_g[2];       /* '<S11>/Integrator' */
  real_T TransferFcn2_CSTATE;          /* '<S11>/Transfer Fcn2' */
  real_T Integrator1_CSTATE[3];        /* '<S16>/Integrator1' */
  real_T Integrator4_CSTATE[3];        /* '<S9>/Integrator4' */
  real_T Integrator1_CSTATE_d[3];      /* '<S19>/Integrator1' */
  real_T Integrator1_CSTATE_h[3];      /* '<S9>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S9>/Integrator2' */
  real_T Integrator3_CSTATE[3];        /* '<S9>/Integrator3' */
  real_T Integrator_CSTATE_a;          /* '<S10>/Integrator' */
} X_ctrl_student_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[3];         /* '<S9>/Integrator' */
  real_T Integrator_CSTATE_g[2];       /* '<S11>/Integrator' */
  real_T TransferFcn2_CSTATE;          /* '<S11>/Transfer Fcn2' */
  real_T Integrator1_CSTATE[3];        /* '<S16>/Integrator1' */
  real_T Integrator4_CSTATE[3];        /* '<S9>/Integrator4' */
  real_T Integrator1_CSTATE_d[3];      /* '<S19>/Integrator1' */
  real_T Integrator1_CSTATE_h[3];      /* '<S9>/Integrator1' */
  real_T Integrator2_CSTATE[3];        /* '<S9>/Integrator2' */
  real_T Integrator3_CSTATE[3];        /* '<S9>/Integrator3' */
  real_T Integrator_CSTATE_a;          /* '<S10>/Integrator' */
} XDot_ctrl_student_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[3];      /* '<S9>/Integrator' */
  boolean_T Integrator_CSTATE_g[2];    /* '<S11>/Integrator' */
  boolean_T TransferFcn2_CSTATE;       /* '<S11>/Transfer Fcn2' */
  boolean_T Integrator1_CSTATE[3];     /* '<S16>/Integrator1' */
  boolean_T Integrator4_CSTATE[3];     /* '<S9>/Integrator4' */
  boolean_T Integrator1_CSTATE_d[3];   /* '<S19>/Integrator1' */
  boolean_T Integrator1_CSTATE_h[3];   /* '<S9>/Integrator1' */
  boolean_T Integrator2_CSTATE[3];     /* '<S9>/Integrator2' */
  boolean_T Integrator3_CSTATE[3];     /* '<S9>/Integrator3' */
  boolean_T Integrator_CSTATE_a;       /* '<S10>/Integrator' */
} XDis_ctrl_student_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S10>/Integrator' */
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

/* Parameters for system: '<S43>/CoreSubsys' */
struct P_CoreSubsys_ctrl_student_T_ {
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S43>/Discrete-Time Integrator'
                                         */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S47>/Gain1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S43>/Delay'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S43>/Delay'
                                        */
};

/* Parameters (auto storage) */
struct P_ctrl_student_T_ {
  real_T C[24];                        /* Variable: C
                                        * Referenced by: '<S6>/C'
                                        */
  real_T D;                            /* Variable: D
                                        * Referenced by: '<S2>/D'
                                        */
  real_T I_s;                          /* Variable: I_s
                                        * Referenced by:
                                        *   '<S60>/Finding rotation speed'
                                        *   '<S61>/Inertia compensation'
                                        *   '<S70>/Finding rotation speed'
                                        *   '<S71>/Inertia compensation'
                                        *   '<S80>/Finding rotation speed'
                                        *   '<S81>/Inertia compensation'
                                        *   '<S90>/Finding rotation speed'
                                        *   '<S91>/Inertia compensation'
                                        *   '<S100>/Finding rotation speed'
                                        *   '<S101>/Inertia compensation'
                                        *   '<S110>/Finding rotation speed'
                                        *   '<S111>/Inertia compensation'
                                        */
  real_T K_omega;                      /* Variable: K_omega
                                        * Referenced by:
                                        *   '<S60>/K_omega'
                                        *   '<S61>/Qff_1(nr)'
                                        *   '<S70>/K_omega'
                                        *   '<S71>/Qff_1(nr)'
                                        *   '<S80>/K_omega'
                                        *   '<S81>/Qff_1(nr)'
                                        *   '<S90>/K_omega'
                                        *   '<S91>/Qff_1(nr)'
                                        *   '<S100>/K_omega'
                                        *   '<S101>/Qff_1(nr)'
                                        *   '<S110>/K_omega'
                                        *   '<S111>/Qff_1(nr)'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by:
                                        *   '<S63>/Ki'
                                        *   '<S63>/Kp'
                                        *   '<S73>/Ki'
                                        *   '<S73>/Kp'
                                        *   '<S83>/Ki'
                                        *   '<S83>/Kp'
                                        *   '<S93>/Ki'
                                        *   '<S93>/Kp'
                                        *   '<S103>/Ki'
                                        *   '<S103>/Kp'
                                        *   '<S113>/Ki'
                                        *   '<S113>/Kp'
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
                                        * Referenced by: '<S43>/Max Rotation Rate'
                                        */
  real_T Max_thrust;                   /* Variable: Max_thrust
                                        * Referenced by:
                                        *   '<S50>/Saturation 1'
                                        *   '<S50>/Saturation 2'
                                        *   '<S50>/Saturation 3'
                                        *   '<S50>/Saturation 4'
                                        *   '<S50>/Saturation 5'
                                        *   '<S50>/Saturation 6'
                                        *   '<S50>/Saturation 7'
                                        */
  real_T P_max;                        /* Variable: P_max
                                        * Referenced by:
                                        *   '<S61>/P_max'
                                        *   '<S71>/P_max'
                                        *   '<S81>/P_max'
                                        *   '<S91>/P_max'
                                        *   '<S101>/P_max'
                                        *   '<S111>/P_max'
                                        */
  real_T Q_f0;                         /* Variable: Q_f0
                                        * Referenced by:
                                        *   '<S61>/Qf_0'
                                        *   '<S71>/Qf_0'
                                        *   '<S81>/Qf_0'
                                        *   '<S91>/Qf_0'
                                        *   '<S101>/Qf_0'
                                        *   '<S111>/Qf_0'
                                        */
  real_T Q_max;                        /* Variable: Q_max
                                        * Referenced by:
                                        *   '<S61>/Q_max'
                                        *   '<S71>/Q_max'
                                        *   '<S81>/Q_max'
                                        *   '<S91>/Q_max'
                                        *   '<S101>/Q_max'
                                        *   '<S111>/Q_max'
                                        *   '<S63>/Discrete-Time Integrator'
                                        */
  real_T Rho;                          /* Variable: Rho
                                        * Referenced by: '<S2>/Rho'
                                        */
  real_T Thruster_control;             /* Variable: Thruster_control
                                        * Referenced by:
                                        *   '<S61>/Switch controller'
                                        *   '<S71>/Switch controller'
                                        *   '<S81>/Switch controller'
                                        *   '<S91>/Switch controller'
                                        *   '<S101>/Switch controller'
                                        *   '<S111>/Switch controller'
                                        */
  real_T Thruster_lock;                /* Variable: Thruster_lock
                                        * Referenced by: '<S6>/Switch  Azimuth//Fixed angles'
                                        */
  real_T eps;                          /* Variable: eps
                                        * Referenced by:
                                        *   '<S2>/Constant4'
                                        *   '<S6>/Constant to avoid singularities'
                                        */
  real_T eps_c;                        /* Variable: eps_c
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T epsilon;                      /* Variable: epsilon
                                        * Referenced by:
                                        *   '<S61>/Qff_0(nr)'
                                        *   '<S71>/Qff_0(nr)'
                                        *   '<S81>/Qff_0(nr)'
                                        *   '<S91>/Qff_0(nr)'
                                        *   '<S101>/Qff_0(nr)'
                                        *   '<S111>/Qff_0(nr)'
                                        */
  real_T k_cc;                         /* Variable: k_cc
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T n_c;                          /* Variable: n_c
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T n_max;                        /* Variable: n_max
                                        * Referenced by:
                                        *   '<S61>/Qff_0(nr)'
                                        *   '<S71>/Qff_0(nr)'
                                        *   '<S81>/Qff_0(nr)'
                                        *   '<S91>/Qff_0(nr)'
                                        *   '<S101>/Qff_0(nr)'
                                        *   '<S111>/Qff_0(nr)'
                                        */
  real_T p_cc;                         /* Variable: p_cc
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T r_cc;                         /* Variable: r_cc
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T thrust_to_pwm_coeff[6];       /* Variable: thrust_to_pwm_coeff
                                        * Referenced by:
                                        *   '<S50>/pwm thruster 1'
                                        *   '<S50>/pwm thruster 2'
                                        *   '<S50>/pwm thruster 3'
                                        *   '<S50>/pwm thruster 4'
                                        *   '<S50>/pwm thruster 5'
                                        *   '<S50>/pwm thruster 6'
                                        */
  real_T Nonlinearpassiveobserver_D[9];/* Mask Parameter: Nonlinearpassiveobserver_D
                                        * Referenced by: '<S9>/Gain6'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S64>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_k;/* Mask Parameter: DiscreteDerivative_ICPrevScal_k
                                          * Referenced by: '<S74>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_p;/* Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                          * Referenced by: '<S84>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_b;/* Mask Parameter: DiscreteDerivative_ICPrevScal_b
                                          * Referenced by: '<S94>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevScal_g;/* Mask Parameter: DiscreteDerivative_ICPrevScal_g
                                          * Referenced by: '<S104>/UD'
                                          */
  real_T DiscreteDerivative_ICPrevSca_g4;/* Mask Parameter: DiscreteDerivative_ICPrevSca_g4
                                          * Referenced by: '<S114>/UD'
                                          */
  real_T Nonlinearpassiveobserver_K3[9];/* Mask Parameter: Nonlinearpassiveobserver_K3
                                         * Referenced by: '<S9>/K3'
                                         */
  real_T Nonlinearpassiveobserver_K4[9];/* Mask Parameter: Nonlinearpassiveobserver_K4
                                         * Referenced by: '<S9>/K4'
                                         */
  real_T Nonlinearpassiveobserver_w_c[9];/* Mask Parameter: Nonlinearpassiveobserver_w_c
                                          * Referenced by: '<S9>/K2'
                                          */
  real_T r_max_P1;                     /* Expression: width
                                        * Referenced by: '<S10>/r_max'
                                        */
  real_T r_max_P2;                     /* Expression: dtype
                                        * Referenced by: '<S10>/r_max'
                                        */
  real_T r_max_P3;                     /* Expression: portnum
                                        * Referenced by: '<S10>/r_max'
                                        */
  real_T r_max_P4;                     /* Expression: stime
                                        * Referenced by: '<S10>/r_max'
                                        */
  real_T r_max_P5;                     /* Expression: stype
                                        * Referenced by: '<S10>/r_max'
                                        */
  real_T r_max_P6;                     /* Expression: btype
                                        * Referenced by: '<S10>/r_max'
                                        */
  real_T K_p_x_in_P1;                  /* Expression: width
                                        * Referenced by: '<S16>/K_p_x_in'
                                        */
  real_T K_p_x_in_P2;                  /* Expression: dtype
                                        * Referenced by: '<S16>/K_p_x_in'
                                        */
  real_T K_p_x_in_P3;                  /* Expression: portnum
                                        * Referenced by: '<S16>/K_p_x_in'
                                        */
  real_T K_p_x_in_P4;                  /* Expression: stime
                                        * Referenced by: '<S16>/K_p_x_in'
                                        */
  real_T K_p_x_in_P5;                  /* Expression: stype
                                        * Referenced by: '<S16>/K_p_x_in'
                                        */
  real_T K_p_x_in_P6;                  /* Expression: btype
                                        * Referenced by: '<S16>/K_p_x_in'
                                        */
  real_T K_p_y_in_P1;                  /* Expression: width
                                        * Referenced by: '<S16>/K_p_y_in'
                                        */
  real_T K_p_y_in_P2;                  /* Expression: dtype
                                        * Referenced by: '<S16>/K_p_y_in'
                                        */
  real_T K_p_y_in_P3;                  /* Expression: portnum
                                        * Referenced by: '<S16>/K_p_y_in'
                                        */
  real_T K_p_y_in_P4;                  /* Expression: stime
                                        * Referenced by: '<S16>/K_p_y_in'
                                        */
  real_T K_p_y_in_P5;                  /* Expression: stype
                                        * Referenced by: '<S16>/K_p_y_in'
                                        */
  real_T K_p_y_in_P6;                  /* Expression: btype
                                        * Referenced by: '<S16>/K_p_y_in'
                                        */
  real_T K_p_psi_in_P1;                /* Expression: width
                                        * Referenced by: '<S16>/K_p_psi_in'
                                        */
  real_T K_p_psi_in_P2;                /* Expression: dtype
                                        * Referenced by: '<S16>/K_p_psi_in'
                                        */
  real_T K_p_psi_in_P3;                /* Expression: portnum
                                        * Referenced by: '<S16>/K_p_psi_in'
                                        */
  real_T K_p_psi_in_P4;                /* Expression: stime
                                        * Referenced by: '<S16>/K_p_psi_in'
                                        */
  real_T K_p_psi_in_P5;                /* Expression: stype
                                        * Referenced by: '<S16>/K_p_psi_in'
                                        */
  real_T K_p_psi_in_P6;                /* Expression: btype
                                        * Referenced by: '<S16>/K_p_psi_in'
                                        */
  real_T Integrator_IC[3];             /* Expression: [0,0,0]'
                                        * Referenced by: '<S9>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1e10
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1e10
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: pi
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Integrator_IC_n[2];           /* Expression: [0 0]
                                        * Referenced by: '<S11>/Integrator'
                                        */
  real_T fzp_x_P1;                     /* Expression: width
                                        * Referenced by: '<S11>/fzp_x'
                                        */
  real_T fzp_x_P2;                     /* Expression: dtype
                                        * Referenced by: '<S11>/fzp_x'
                                        */
  real_T fzp_x_P3;                     /* Expression: portnum
                                        * Referenced by: '<S11>/fzp_x'
                                        */
  real_T fzp_x_P4;                     /* Expression: stime
                                        * Referenced by: '<S11>/fzp_x'
                                        */
  real_T fzp_x_P5;                     /* Expression: stype
                                        * Referenced by: '<S11>/fzp_x'
                                        */
  real_T fzp_x_P6;                     /* Expression: btype
                                        * Referenced by: '<S11>/fzp_x'
                                        */
  real_T fzp_y_P1;                     /* Expression: width
                                        * Referenced by: '<S11>/fzp_y'
                                        */
  real_T fzp_y_P2;                     /* Expression: dtype
                                        * Referenced by: '<S11>/fzp_y'
                                        */
  real_T fzp_y_P3;                     /* Expression: portnum
                                        * Referenced by: '<S11>/fzp_y'
                                        */
  real_T fzp_y_P4;                     /* Expression: stime
                                        * Referenced by: '<S11>/fzp_y'
                                        */
  real_T fzp_y_P5;                     /* Expression: stype
                                        * Referenced by: '<S11>/fzp_y'
                                        */
  real_T fzp_y_P6;                     /* Expression: btype
                                        * Referenced by: '<S11>/fzp_y'
                                        */
  real_T r_max_P1_g;                   /* Expression: width
                                        * Referenced by: '<S11>/r_max'
                                        */
  real_T r_max_P2_p;                   /* Expression: dtype
                                        * Referenced by: '<S11>/r_max'
                                        */
  real_T r_max_P3_j;                   /* Expression: portnum
                                        * Referenced by: '<S11>/r_max'
                                        */
  real_T r_max_P4_e;                   /* Expression: stime
                                        * Referenced by: '<S11>/r_max'
                                        */
  real_T r_max_P5_n;                   /* Expression: stype
                                        * Referenced by: '<S11>/r_max'
                                        */
  real_T r_max_P6_l;                   /* Expression: btype
                                        * Referenced by: '<S11>/r_max'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S11>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S11>/Transfer Fcn2'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 1e10
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -1e10
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real_T Gain_Gain_h;                  /* Expression: pi
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Constant_Value_b;             /* Expression: 2*pi
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T K_i_psi_in_P1;                /* Expression: width
                                        * Referenced by: '<S16>/K_i_psi_in'
                                        */
  real_T K_i_psi_in_P2;                /* Expression: dtype
                                        * Referenced by: '<S16>/K_i_psi_in'
                                        */
  real_T K_i_psi_in_P3;                /* Expression: portnum
                                        * Referenced by: '<S16>/K_i_psi_in'
                                        */
  real_T K_i_psi_in_P4;                /* Expression: stime
                                        * Referenced by: '<S16>/K_i_psi_in'
                                        */
  real_T K_i_psi_in_P5;                /* Expression: stype
                                        * Referenced by: '<S16>/K_i_psi_in'
                                        */
  real_T K_i_psi_in_P6;                /* Expression: btype
                                        * Referenced by: '<S16>/K_i_psi_in'
                                        */
  real_T K_i_x_in_P1;                  /* Expression: width
                                        * Referenced by: '<S16>/K_i_x_in'
                                        */
  real_T K_i_x_in_P2;                  /* Expression: dtype
                                        * Referenced by: '<S16>/K_i_x_in'
                                        */
  real_T K_i_x_in_P3;                  /* Expression: portnum
                                        * Referenced by: '<S16>/K_i_x_in'
                                        */
  real_T K_i_x_in_P4;                  /* Expression: stime
                                        * Referenced by: '<S16>/K_i_x_in'
                                        */
  real_T K_i_x_in_P5;                  /* Expression: stype
                                        * Referenced by: '<S16>/K_i_x_in'
                                        */
  real_T K_i_x_in_P6;                  /* Expression: btype
                                        * Referenced by: '<S16>/K_i_x_in'
                                        */
  real_T K_i_y_in_P1;                  /* Expression: width
                                        * Referenced by: '<S16>/K_i_y_in'
                                        */
  real_T K_i_y_in_P2;                  /* Expression: dtype
                                        * Referenced by: '<S16>/K_i_y_in'
                                        */
  real_T K_i_y_in_P3;                  /* Expression: portnum
                                        * Referenced by: '<S16>/K_i_y_in'
                                        */
  real_T K_i_y_in_P4;                  /* Expression: stime
                                        * Referenced by: '<S16>/K_i_y_in'
                                        */
  real_T K_i_y_in_P5;                  /* Expression: stype
                                        * Referenced by: '<S16>/K_i_y_in'
                                        */
  real_T K_i_y_in_P6;                  /* Expression: btype
                                        * Referenced by: '<S16>/K_i_y_in'
                                        */
  real_T K_d_psi_in_P1;                /* Expression: width
                                        * Referenced by: '<S16>/K_d_psi_in'
                                        */
  real_T K_d_psi_in_P2;                /* Expression: dtype
                                        * Referenced by: '<S16>/K_d_psi_in'
                                        */
  real_T K_d_psi_in_P3;                /* Expression: portnum
                                        * Referenced by: '<S16>/K_d_psi_in'
                                        */
  real_T K_d_psi_in_P4;                /* Expression: stime
                                        * Referenced by: '<S16>/K_d_psi_in'
                                        */
  real_T K_d_psi_in_P5;                /* Expression: stype
                                        * Referenced by: '<S16>/K_d_psi_in'
                                        */
  real_T K_d_psi_in_P6;                /* Expression: btype
                                        * Referenced by: '<S16>/K_d_psi_in'
                                        */
  real_T K_d_x_in_P1;                  /* Expression: width
                                        * Referenced by: '<S16>/K_d_x_in'
                                        */
  real_T K_d_x_in_P2;                  /* Expression: dtype
                                        * Referenced by: '<S16>/K_d_x_in'
                                        */
  real_T K_d_x_in_P3;                  /* Expression: portnum
                                        * Referenced by: '<S16>/K_d_x_in'
                                        */
  real_T K_d_x_in_P4;                  /* Expression: stime
                                        * Referenced by: '<S16>/K_d_x_in'
                                        */
  real_T K_d_x_in_P5;                  /* Expression: stype
                                        * Referenced by: '<S16>/K_d_x_in'
                                        */
  real_T K_d_x_in_P6;                  /* Expression: btype
                                        * Referenced by: '<S16>/K_d_x_in'
                                        */
  real_T K_d_y_in_P1;                  /* Expression: width
                                        * Referenced by: '<S16>/K_d_y_in'
                                        */
  real_T K_d_y_in_P2;                  /* Expression: dtype
                                        * Referenced by: '<S16>/K_d_y_in'
                                        */
  real_T K_d_y_in_P3;                  /* Expression: portnum
                                        * Referenced by: '<S16>/K_d_y_in'
                                        */
  real_T K_d_y_in_P4;                  /* Expression: stime
                                        * Referenced by: '<S16>/K_d_y_in'
                                        */
  real_T K_d_y_in_P5;                  /* Expression: stype
                                        * Referenced by: '<S16>/K_d_y_in'
                                        */
  real_T K_d_y_in_P6;                  /* Expression: btype
                                        * Referenced by: '<S16>/K_d_y_in'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S16>/Integrator1'
                                        */
  real_T Integrator4_IC[3];            /* Expression: [0,0,0]'
                                        * Referenced by: '<S9>/Integrator4'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 1e10
                                        * Referenced by: '<S33>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -1e10
                                        * Referenced by: '<S33>/Saturation'
                                        */
  real_T Gain_Gain_j;                  /* Expression: pi
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T Constant_Value_i;             /* Expression: 2*pi
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1e10
                                        * Referenced by: '<S32>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -1e10
                                        * Referenced by: '<S32>/Saturation'
                                        */
  real_T Gain_Gain_c;                  /* Expression: pi
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 2*pi
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T K_d_psi_out_P1;               /* Expression: width
                                        * Referenced by: '<S19>/K_d_psi_out'
                                        */
  real_T K_d_psi_out_P2;               /* Expression: dtype
                                        * Referenced by: '<S19>/K_d_psi_out'
                                        */
  real_T K_d_psi_out_P3;               /* Expression: portnum
                                        * Referenced by: '<S19>/K_d_psi_out'
                                        */
  real_T K_d_psi_out_P4;               /* Expression: stime
                                        * Referenced by: '<S19>/K_d_psi_out'
                                        */
  real_T K_d_psi_out_P5;               /* Expression: stype
                                        * Referenced by: '<S19>/K_d_psi_out'
                                        */
  real_T K_d_psi_out_P6;               /* Expression: btype
                                        * Referenced by: '<S19>/K_d_psi_out'
                                        */
  real_T K_d_x_out_P1;                 /* Expression: width
                                        * Referenced by: '<S19>/K_d_x_out'
                                        */
  real_T K_d_x_out_P2;                 /* Expression: dtype
                                        * Referenced by: '<S19>/K_d_x_out'
                                        */
  real_T K_d_x_out_P3;                 /* Expression: portnum
                                        * Referenced by: '<S19>/K_d_x_out'
                                        */
  real_T K_d_x_out_P4;                 /* Expression: stime
                                        * Referenced by: '<S19>/K_d_x_out'
                                        */
  real_T K_d_x_out_P5;                 /* Expression: stype
                                        * Referenced by: '<S19>/K_d_x_out'
                                        */
  real_T K_d_x_out_P6;                 /* Expression: btype
                                        * Referenced by: '<S19>/K_d_x_out'
                                        */
  real_T K_d_y_out_P1;                 /* Expression: width
                                        * Referenced by: '<S19>/K_d_y_out'
                                        */
  real_T K_d_y_out_P2;                 /* Expression: dtype
                                        * Referenced by: '<S19>/K_d_y_out'
                                        */
  real_T K_d_y_out_P3;                 /* Expression: portnum
                                        * Referenced by: '<S19>/K_d_y_out'
                                        */
  real_T K_d_y_out_P4;                 /* Expression: stime
                                        * Referenced by: '<S19>/K_d_y_out'
                                        */
  real_T K_d_y_out_P5;                 /* Expression: stype
                                        * Referenced by: '<S19>/K_d_y_out'
                                        */
  real_T K_d_y_out_P6;                 /* Expression: btype
                                        * Referenced by: '<S19>/K_d_y_out'
                                        */
  real_T K_i_psi_out_P1;               /* Expression: width
                                        * Referenced by: '<S19>/K_i_psi_out'
                                        */
  real_T K_i_psi_out_P2;               /* Expression: dtype
                                        * Referenced by: '<S19>/K_i_psi_out'
                                        */
  real_T K_i_psi_out_P3;               /* Expression: portnum
                                        * Referenced by: '<S19>/K_i_psi_out'
                                        */
  real_T K_i_psi_out_P4;               /* Expression: stime
                                        * Referenced by: '<S19>/K_i_psi_out'
                                        */
  real_T K_i_psi_out_P5;               /* Expression: stype
                                        * Referenced by: '<S19>/K_i_psi_out'
                                        */
  real_T K_i_psi_out_P6;               /* Expression: btype
                                        * Referenced by: '<S19>/K_i_psi_out'
                                        */
  real_T K_i_x_out_P1;                 /* Expression: width
                                        * Referenced by: '<S19>/K_i_x_out'
                                        */
  real_T K_i_x_out_P2;                 /* Expression: dtype
                                        * Referenced by: '<S19>/K_i_x_out'
                                        */
  real_T K_i_x_out_P3;                 /* Expression: portnum
                                        * Referenced by: '<S19>/K_i_x_out'
                                        */
  real_T K_i_x_out_P4;                 /* Expression: stime
                                        * Referenced by: '<S19>/K_i_x_out'
                                        */
  real_T K_i_x_out_P5;                 /* Expression: stype
                                        * Referenced by: '<S19>/K_i_x_out'
                                        */
  real_T K_i_x_out_P6;                 /* Expression: btype
                                        * Referenced by: '<S19>/K_i_x_out'
                                        */
  real_T K_i_y_out_P1;                 /* Expression: width
                                        * Referenced by: '<S19>/K_i_y_out'
                                        */
  real_T K_i_y_out_P2;                 /* Expression: dtype
                                        * Referenced by: '<S19>/K_i_y_out'
                                        */
  real_T K_i_y_out_P3;                 /* Expression: portnum
                                        * Referenced by: '<S19>/K_i_y_out'
                                        */
  real_T K_i_y_out_P4;                 /* Expression: stime
                                        * Referenced by: '<S19>/K_i_y_out'
                                        */
  real_T K_i_y_out_P5;                 /* Expression: stype
                                        * Referenced by: '<S19>/K_i_y_out'
                                        */
  real_T K_i_y_out_P6;                 /* Expression: btype
                                        * Referenced by: '<S19>/K_i_y_out'
                                        */
  real_T K_p_psi_out_P1;               /* Expression: width
                                        * Referenced by: '<S19>/K_p_psi_out'
                                        */
  real_T K_p_psi_out_P2;               /* Expression: dtype
                                        * Referenced by: '<S19>/K_p_psi_out'
                                        */
  real_T K_p_psi_out_P3;               /* Expression: portnum
                                        * Referenced by: '<S19>/K_p_psi_out'
                                        */
  real_T K_p_psi_out_P4;               /* Expression: stime
                                        * Referenced by: '<S19>/K_p_psi_out'
                                        */
  real_T K_p_psi_out_P5;               /* Expression: stype
                                        * Referenced by: '<S19>/K_p_psi_out'
                                        */
  real_T K_p_psi_out_P6;               /* Expression: btype
                                        * Referenced by: '<S19>/K_p_psi_out'
                                        */
  real_T K_p_x_out_P1;                 /* Expression: width
                                        * Referenced by: '<S19>/K_p_x_out'
                                        */
  real_T K_p_x_out_P2;                 /* Expression: dtype
                                        * Referenced by: '<S19>/K_p_x_out'
                                        */
  real_T K_p_x_out_P3;                 /* Expression: portnum
                                        * Referenced by: '<S19>/K_p_x_out'
                                        */
  real_T K_p_x_out_P4;                 /* Expression: stime
                                        * Referenced by: '<S19>/K_p_x_out'
                                        */
  real_T K_p_x_out_P5;                 /* Expression: stype
                                        * Referenced by: '<S19>/K_p_x_out'
                                        */
  real_T K_p_x_out_P6;                 /* Expression: btype
                                        * Referenced by: '<S19>/K_p_x_out'
                                        */
  real_T K_p_y_out_P1;                 /* Expression: width
                                        * Referenced by: '<S19>/K_p_y_out'
                                        */
  real_T K_p_y_out_P2;                 /* Expression: dtype
                                        * Referenced by: '<S19>/K_p_y_out'
                                        */
  real_T K_p_y_out_P3;                 /* Expression: portnum
                                        * Referenced by: '<S19>/K_p_y_out'
                                        */
  real_T K_p_y_out_P4;                 /* Expression: stime
                                        * Referenced by: '<S19>/K_p_y_out'
                                        */
  real_T K_p_y_out_P5;                 /* Expression: stype
                                        * Referenced by: '<S19>/K_p_y_out'
                                        */
  real_T K_p_y_out_P6;                 /* Expression: btype
                                        * Referenced by: '<S19>/K_p_y_out'
                                        */
  real_T Integrator1_IC_j;             /* Expression: 0
                                        * Referenced by: '<S19>/Integrator1'
                                        */
  real_T fzp_x_P1_f;                   /* Expression: width
                                        * Referenced by: '<S10>/fzp_x'
                                        */
  real_T fzp_x_P2_c;                   /* Expression: dtype
                                        * Referenced by: '<S10>/fzp_x'
                                        */
  real_T fzp_x_P3_b;                   /* Expression: portnum
                                        * Referenced by: '<S10>/fzp_x'
                                        */
  real_T fzp_x_P4_d;                   /* Expression: stime
                                        * Referenced by: '<S10>/fzp_x'
                                        */
  real_T fzp_x_P5_e;                   /* Expression: stype
                                        * Referenced by: '<S10>/fzp_x'
                                        */
  real_T fzp_x_P6_a;                   /* Expression: btype
                                        * Referenced by: '<S10>/fzp_x'
                                        */
  real_T fzp_y_P1_g;                   /* Expression: width
                                        * Referenced by: '<S10>/fzp_y'
                                        */
  real_T fzp_y_P2_e;                   /* Expression: dtype
                                        * Referenced by: '<S10>/fzp_y'
                                        */
  real_T fzp_y_P3_l;                   /* Expression: portnum
                                        * Referenced by: '<S10>/fzp_y'
                                        */
  real_T fzp_y_P4_i;                   /* Expression: stime
                                        * Referenced by: '<S10>/fzp_y'
                                        */
  real_T fzp_y_P5_d;                   /* Expression: stype
                                        * Referenced by: '<S10>/fzp_y'
                                        */
  real_T fzp_y_P6_l;                   /* Expression: btype
                                        * Referenced by: '<S10>/fzp_y'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S10>/Delay'
                                        */
  real_T controller_P1;                /* Expression: width
                                        * Referenced by: '<S10>/controller'
                                        */
  real_T controller_P2;                /* Expression: dtype
                                        * Referenced by: '<S10>/controller'
                                        */
  real_T controller_P3;                /* Expression: portnum
                                        * Referenced by: '<S10>/controller'
                                        */
  real_T controller_P4;                /* Expression: stime
                                        * Referenced by: '<S10>/controller'
                                        */
  real_T controller_P5;                /* Expression: stype
                                        * Referenced by: '<S10>/controller'
                                        */
  real_T controller_P6;                /* Expression: btype
                                        * Referenced by: '<S10>/controller'
                                        */
  real_T thr_angle_1_P1;               /* Expression: width
                                        * Referenced by: '<S8>/thr_angle_1'
                                        */
  real_T thr_angle_1_P2;               /* Expression: dtype
                                        * Referenced by: '<S8>/thr_angle_1'
                                        */
  real_T thr_angle_1_P3;               /* Expression: portnum
                                        * Referenced by: '<S8>/thr_angle_1'
                                        */
  real_T thr_angle_1_P4;               /* Expression: stime
                                        * Referenced by: '<S8>/thr_angle_1'
                                        */
  real_T thr_angle_1_P5;               /* Expression: stype
                                        * Referenced by: '<S8>/thr_angle_1'
                                        */
  real_T thr_angle_1_P6;               /* Expression: btype
                                        * Referenced by: '<S8>/thr_angle_1'
                                        */
  real_T thr_angle_2_P1;               /* Expression: width
                                        * Referenced by: '<S8>/thr_angle_2'
                                        */
  real_T thr_angle_2_P2;               /* Expression: dtype
                                        * Referenced by: '<S8>/thr_angle_2'
                                        */
  real_T thr_angle_2_P3;               /* Expression: portnum
                                        * Referenced by: '<S8>/thr_angle_2'
                                        */
  real_T thr_angle_2_P4;               /* Expression: stime
                                        * Referenced by: '<S8>/thr_angle_2'
                                        */
  real_T thr_angle_2_P5;               /* Expression: stype
                                        * Referenced by: '<S8>/thr_angle_2'
                                        */
  real_T thr_angle_2_P6;               /* Expression: btype
                                        * Referenced by: '<S8>/thr_angle_2'
                                        */
  real_T thr_angle_3_P1;               /* Expression: width
                                        * Referenced by: '<S8>/thr_angle_3'
                                        */
  real_T thr_angle_3_P2;               /* Expression: dtype
                                        * Referenced by: '<S8>/thr_angle_3'
                                        */
  real_T thr_angle_3_P3;               /* Expression: portnum
                                        * Referenced by: '<S8>/thr_angle_3'
                                        */
  real_T thr_angle_3_P4;               /* Expression: stime
                                        * Referenced by: '<S8>/thr_angle_3'
                                        */
  real_T thr_angle_3_P5;               /* Expression: stype
                                        * Referenced by: '<S8>/thr_angle_3'
                                        */
  real_T thr_angle_3_P6;               /* Expression: btype
                                        * Referenced by: '<S8>/thr_angle_3'
                                        */
  real_T thr_angle_4_P1;               /* Expression: width
                                        * Referenced by: '<S8>/thr_angle_4'
                                        */
  real_T thr_angle_4_P2;               /* Expression: dtype
                                        * Referenced by: '<S8>/thr_angle_4'
                                        */
  real_T thr_angle_4_P3;               /* Expression: portnum
                                        * Referenced by: '<S8>/thr_angle_4'
                                        */
  real_T thr_angle_4_P4;               /* Expression: stime
                                        * Referenced by: '<S8>/thr_angle_4'
                                        */
  real_T thr_angle_4_P5;               /* Expression: stype
                                        * Referenced by: '<S8>/thr_angle_4'
                                        */
  real_T thr_angle_4_P6;               /* Expression: btype
                                        * Referenced by: '<S8>/thr_angle_4'
                                        */
  real_T thr_angle_5_P1;               /* Expression: width
                                        * Referenced by: '<S8>/thr_angle_5'
                                        */
  real_T thr_angle_5_P2;               /* Expression: dtype
                                        * Referenced by: '<S8>/thr_angle_5'
                                        */
  real_T thr_angle_5_P3;               /* Expression: portnum
                                        * Referenced by: '<S8>/thr_angle_5'
                                        */
  real_T thr_angle_5_P4;               /* Expression: stime
                                        * Referenced by: '<S8>/thr_angle_5'
                                        */
  real_T thr_angle_5_P5;               /* Expression: stype
                                        * Referenced by: '<S8>/thr_angle_5'
                                        */
  real_T thr_angle_5_P6;               /* Expression: btype
                                        * Referenced by: '<S8>/thr_angle_5'
                                        */
  real_T thr_angle_6_P1;               /* Expression: width
                                        * Referenced by: '<S8>/thr_angle_6'
                                        */
  real_T thr_angle_6_P2;               /* Expression: dtype
                                        * Referenced by: '<S8>/thr_angle_6'
                                        */
  real_T thr_angle_6_P3;               /* Expression: portnum
                                        * Referenced by: '<S8>/thr_angle_6'
                                        */
  real_T thr_angle_6_P4;               /* Expression: stime
                                        * Referenced by: '<S8>/thr_angle_6'
                                        */
  real_T thr_angle_6_P5;               /* Expression: stype
                                        * Referenced by: '<S8>/thr_angle_6'
                                        */
  real_T thr_angle_6_P6;               /* Expression: btype
                                        * Referenced by: '<S8>/thr_angle_6'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 180/pi
                                        * Referenced by: '<S46>/Gain'
                                        */
  real_T XpositionThruster_Value[6];   /* Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
                                        * Referenced by: '<S6>/X-position Thruster'
                                        */
  real_T YpositionThruster_Value[6];   /* Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
                                        * Referenced by: '<S6>/Y-position Thruster'
                                        */
  real_T constantangle_Value[6];       /* Expression: [Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)]
                                        * Referenced by: '<S6>/constant angle'
                                        */
  real_T ChoosingFixedAzimuthangle_Thres;/* Expression: 1
                                          * Referenced by: '<S6>/Choosing Fixed // Azimuth angle'
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
  real_T Saturation1_UpperSat;         /* Expression: pi
                                        * Referenced by: '<S51>/Saturation 1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S51>/Saturation 1'
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
  real_T reset_P1_i;                   /* Expression: width
                                        * Referenced by: '<S60>/reset'
                                        */
  real_T reset_P2_j;                   /* Expression: dtype
                                        * Referenced by: '<S60>/reset'
                                        */
  real_T reset_P3_m;                   /* Expression: portnum
                                        * Referenced by: '<S60>/reset'
                                        */
  real_T reset_P4_e;                   /* Expression: stime
                                        * Referenced by: '<S60>/reset'
                                        */
  real_T reset_P5_b;                   /* Expression: stype
                                        * Referenced by: '<S60>/reset'
                                        */
  real_T reset_P6_b;                   /* Expression: btype
                                        * Referenced by: '<S60>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S60>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S60>/Discrete-Time Integrator'
                                        */
  real_T Lossesplaceholder_Value;      /* Expression: 0
                                        * Referenced by: '<S52>/Losses (placeholder)'
                                        */
  real_T reset_P1_m;                   /* Expression: width
                                        * Referenced by: '<S70>/reset'
                                        */
  real_T reset_P2_d;                   /* Expression: dtype
                                        * Referenced by: '<S70>/reset'
                                        */
  real_T reset_P3_a;                   /* Expression: portnum
                                        * Referenced by: '<S70>/reset'
                                        */
  real_T reset_P4_i;                   /* Expression: stime
                                        * Referenced by: '<S70>/reset'
                                        */
  real_T reset_P5_d;                   /* Expression: stype
                                        * Referenced by: '<S70>/reset'
                                        */
  real_T reset_P6_o;                   /* Expression: btype
                                        * Referenced by: '<S70>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_e;/* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                          * Referenced by: '<S70>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_e;  /* Expression: 0
                                        * Referenced by: '<S70>/Discrete-Time Integrator'
                                        */
  real_T Lossesplaceholder_Value_i;    /* Expression: 0
                                        * Referenced by: '<S53>/Losses (placeholder)'
                                        */
  real_T reset_P1_b;                   /* Expression: width
                                        * Referenced by: '<S80>/reset'
                                        */
  real_T reset_P2_o;                   /* Expression: dtype
                                        * Referenced by: '<S80>/reset'
                                        */
  real_T reset_P3_g;                   /* Expression: portnum
                                        * Referenced by: '<S80>/reset'
                                        */
  real_T reset_P4_a;                   /* Expression: stime
                                        * Referenced by: '<S80>/reset'
                                        */
  real_T reset_P5_h;                   /* Expression: stype
                                        * Referenced by: '<S80>/reset'
                                        */
  real_T reset_P6_f;                   /* Expression: btype
                                        * Referenced by: '<S80>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_o;/* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                                          * Referenced by: '<S80>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_n;  /* Expression: 0
                                        * Referenced by: '<S80>/Discrete-Time Integrator'
                                        */
  real_T Lossesplaceholder_Value_p;    /* Expression: 0
                                        * Referenced by: '<S54>/Losses (placeholder)'
                                        */
  real_T reset_P1_l;                   /* Expression: width
                                        * Referenced by: '<S90>/reset'
                                        */
  real_T reset_P2_c;                   /* Expression: dtype
                                        * Referenced by: '<S90>/reset'
                                        */
  real_T reset_P3_am;                  /* Expression: portnum
                                        * Referenced by: '<S90>/reset'
                                        */
  real_T reset_P4_g;                   /* Expression: stime
                                        * Referenced by: '<S90>/reset'
                                        */
  real_T reset_P5_bn;                  /* Expression: stype
                                        * Referenced by: '<S90>/reset'
                                        */
  real_T reset_P6_g;                   /* Expression: btype
                                        * Referenced by: '<S90>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;/* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                          * Referenced by: '<S90>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_k;  /* Expression: 0
                                        * Referenced by: '<S90>/Discrete-Time Integrator'
                                        */
  real_T Lossesplaceholder_Value_n;    /* Expression: 0
                                        * Referenced by: '<S55>/Losses (placeholder)'
                                        */
  real_T reset_P1_n;                   /* Expression: width
                                        * Referenced by: '<S100>/reset'
                                        */
  real_T reset_P2_e;                   /* Expression: dtype
                                        * Referenced by: '<S100>/reset'
                                        */
  real_T reset_P3_p;                   /* Expression: portnum
                                        * Referenced by: '<S100>/reset'
                                        */
  real_T reset_P4_c;                   /* Expression: stime
                                        * Referenced by: '<S100>/reset'
                                        */
  real_T reset_P5_l;                   /* Expression: stype
                                        * Referenced by: '<S100>/reset'
                                        */
  real_T reset_P6_f5;                  /* Expression: btype
                                        * Referenced by: '<S100>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_c;/* Computed Parameter: DiscreteTimeIntegrator_gainva_c
                                          * Referenced by: '<S100>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: 0
                                        * Referenced by: '<S100>/Discrete-Time Integrator'
                                        */
  real_T Lossesplaceholder_Value_j;    /* Expression: 0
                                        * Referenced by: '<S56>/Losses (placeholder)'
                                        */
  real_T reset_P1_k;                   /* Expression: width
                                        * Referenced by: '<S110>/reset'
                                        */
  real_T reset_P2_or;                  /* Expression: dtype
                                        * Referenced by: '<S110>/reset'
                                        */
  real_T reset_P3_pe;                  /* Expression: portnum
                                        * Referenced by: '<S110>/reset'
                                        */
  real_T reset_P4_d;                   /* Expression: stime
                                        * Referenced by: '<S110>/reset'
                                        */
  real_T reset_P5_a;                   /* Expression: stype
                                        * Referenced by: '<S110>/reset'
                                        */
  real_T reset_P6_br;                  /* Expression: btype
                                        * Referenced by: '<S110>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_g;/* Computed Parameter: DiscreteTimeIntegrator_gainva_g
                                          * Referenced by: '<S110>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_j;  /* Expression: 0
                                        * Referenced by: '<S110>/Discrete-Time Integrator'
                                        */
  real_T Lossesplaceholder_Value_k;    /* Expression: 0
                                        * Referenced by: '<S57>/Losses (placeholder)'
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<S50>/Constant12'
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
                                        * Referenced by: '<S51>/Saturation 2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S51>/Saturation 2'
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
                                        * Referenced by: '<S51>/Saturation 3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S51>/Saturation 3'
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
                                        * Referenced by: '<S51>/Saturation 4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S51>/Saturation 4'
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
                                        * Referenced by: '<S51>/Saturation 5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S51>/Saturation 5'
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
                                        * Referenced by: '<S51>/Saturation 6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: -pi
                                        * Referenced by: '<S51>/Saturation 6'
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
  real_T Gain_Gain_n;                  /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T XpositionThruster_Value_g[6]; /* Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
                                        * Referenced by: '<Root>/X-position Thruster'
                                        */
  real_T YpositionThruster_Value_j[6]; /* Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
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
                                        * Referenced by: '<S3>/x_m'
                                        */
  real_T x_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S3>/x_m'
                                        */
  real_T x_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S3>/x_m'
                                        */
  real_T x_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S3>/x_m'
                                        */
  real_T x_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S3>/x_m'
                                        */
  real_T x_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S3>/x_m'
                                        */
  real_T y_m_P1;                       /* Expression: width
                                        * Referenced by: '<S3>/y_m'
                                        */
  real_T y_m_P2;                       /* Expression: dtype
                                        * Referenced by: '<S3>/y_m'
                                        */
  real_T y_m_P3;                       /* Expression: portnum
                                        * Referenced by: '<S3>/y_m'
                                        */
  real_T y_m_P4;                       /* Expression: stime
                                        * Referenced by: '<S3>/y_m'
                                        */
  real_T y_m_P5;                       /* Expression: stype
                                        * Referenced by: '<S3>/y_m'
                                        */
  real_T y_m_P6;                       /* Expression: btype
                                        * Referenced by: '<S3>/y_m'
                                        */
  real_T psi_m_P1;                     /* Expression: width
                                        * Referenced by: '<S3>/psi_m'
                                        */
  real_T psi_m_P2;                     /* Expression: dtype
                                        * Referenced by: '<S3>/psi_m'
                                        */
  real_T psi_m_P3;                     /* Expression: portnum
                                        * Referenced by: '<S3>/psi_m'
                                        */
  real_T psi_m_P4;                     /* Expression: stime
                                        * Referenced by: '<S3>/psi_m'
                                        */
  real_T psi_m_P5;                     /* Expression: stype
                                        * Referenced by: '<S3>/psi_m'
                                        */
  real_T psi_m_P6;                     /* Expression: btype
                                        * Referenced by: '<S3>/psi_m'
                                        */
  real_T eta_est_P1;                   /* Expression: width
                                        * Referenced by: '<S5>/eta_est'
                                        */
  real_T eta_est_P2;                   /* Expression: dtype
                                        * Referenced by: '<S5>/eta_est'
                                        */
  real_T eta_est_P3;                   /* Expression: portnum
                                        * Referenced by: '<S5>/eta_est'
                                        */
  real_T eta_est_P4;                   /* Expression: stime
                                        * Referenced by: '<S5>/eta_est'
                                        */
  real_T eta_est_P5;                   /* Expression: stype
                                        * Referenced by: '<S5>/eta_est'
                                        */
  real_T eta_est_P6;                   /* Expression: btype
                                        * Referenced by: '<S5>/eta_est'
                                        */
  real_T wave_dir_P1;                  /* Expression: width
                                        * Referenced by: '<S5>/wave_dir'
                                        */
  real_T wave_dir_P2;                  /* Expression: dtype
                                        * Referenced by: '<S5>/wave_dir'
                                        */
  real_T wave_dir_P3;                  /* Expression: portnum
                                        * Referenced by: '<S5>/wave_dir'
                                        */
  real_T wave_dir_P4;                  /* Expression: stime
                                        * Referenced by: '<S5>/wave_dir'
                                        */
  real_T wave_dir_P5;                  /* Expression: stype
                                        * Referenced by: '<S5>/wave_dir'
                                        */
  real_T wave_dir_P6;                  /* Expression: btype
                                        * Referenced by: '<S5>/wave_dir'
                                        */
  real_T nu_est_P1;                    /* Expression: width
                                        * Referenced by: '<S5>/nu_est'
                                        */
  real_T nu_est_P2;                    /* Expression: dtype
                                        * Referenced by: '<S5>/nu_est'
                                        */
  real_T nu_est_P3;                    /* Expression: portnum
                                        * Referenced by: '<S5>/nu_est'
                                        */
  real_T nu_est_P4;                    /* Expression: stime
                                        * Referenced by: '<S5>/nu_est'
                                        */
  real_T nu_est_P5;                    /* Expression: stype
                                        * Referenced by: '<S5>/nu_est'
                                        */
  real_T nu_est_P6;                    /* Expression: btype
                                        * Referenced by: '<S5>/nu_est'
                                        */
  real_T tau_des_P1;                   /* Expression: width
                                        * Referenced by: '<S5>/tau_des'
                                        */
  real_T tau_des_P2;                   /* Expression: dtype
                                        * Referenced by: '<S5>/tau_des'
                                        */
  real_T tau_des_P3;                   /* Expression: portnum
                                        * Referenced by: '<S5>/tau_des'
                                        */
  real_T tau_des_P4;                   /* Expression: stime
                                        * Referenced by: '<S5>/tau_des'
                                        */
  real_T tau_des_P5;                   /* Expression: stype
                                        * Referenced by: '<S5>/tau_des'
                                        */
  real_T tau_des_P6;                   /* Expression: btype
                                        * Referenced by: '<S5>/tau_des'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 1e10
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -1e10
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Gain_Gain_cs;                 /* Expression: pi
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Constant_Value_ir;            /* Expression: 2*pi
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T SP_P1;                        /* Expression: width
                                        * Referenced by: '<S5>/SP'
                                        */
  real_T SP_P2;                        /* Expression: dtype
                                        * Referenced by: '<S5>/SP'
                                        */
  real_T SP_P3;                        /* Expression: portnum
                                        * Referenced by: '<S5>/SP'
                                        */
  real_T SP_P4;                        /* Expression: stime
                                        * Referenced by: '<S5>/SP'
                                        */
  real_T SP_P5;                        /* Expression: stype
                                        * Referenced by: '<S5>/SP'
                                        */
  real_T SP_P6;                        /* Expression: btype
                                        * Referenced by: '<S5>/SP'
                                        */
  real_T Integrator1_IC_i;             /* Expression: 0
                                        * Referenced by: '<S9>/Integrator1'
                                        */
  real_T Gain1_Gain[9];                /* Expression: 2*lambda*w_o
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S9>/Integrator2'
                                        */
  real_T Gain2_Gain[9];                /* Expression: w_o*w_o
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S9>/Integrator3'
                                        */
  real_T Gain3_Gain[9];                /* Expression: inv(M)
                                        * Referenced by: '<S9>/Gain3'
                                        */
  real_T K11_Gain[9];                  /* Expression: -2*(eye(3)-lambda)*diag([w_c(1,1)/w_o(1,1) w_c(2,2)/w_o(2,2) w_c(3,3)/w_o(3,3)])
                                        * Referenced by: '<S9>/K11'
                                        */
  real_T K12_Gain[9];                  /* Expression: 2*w_o*(eye(3)-lambda)
                                        * Referenced by: '<S9>/K12'
                                        */
  real_T invT_b_Gain[9];               /* Expression: diag([1/T_b(1,1) 1/T_b(2,2) 1/T_b(3,3)])
                                        * Referenced by: '<S9>/inv(T_b)'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Integrator_IC_b;              /* Expression: 0
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Constant1_Value;              /* Expression: pi
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Gain_Gain_o[4];               /* Expression: diag([1/(5/sqrt(90)) 1/(5/sqrt(90))])
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Gain1_Gain_d[4];              /* Expression: diag([1/(5/sqrt(90)) 1/(5/sqrt(90))])
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T gain_Gain;                    /* Expression: pi/180
                                        * Referenced by: '<S5>/gain'
                                        */
  real_T Delay_InitialCondition_o;     /* Expression: 0
                                        * Referenced by: '<S7>/Delay'
                                        */
  real_T Constant_Value_c[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T Constant1_Value_m[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S52>/Constant1'
                                        */
  real_T Delay_InitialCondition_oh;    /* Expression: 0
                                        * Referenced by: '<S52>/Delay'
                                        */
  real_T Delay_InitialCondition_m;     /* Expression: 0
                                        * Referenced by: '<S61>/Delay'
                                        */
  real_T Constant1_Value_j[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S61>/Constant1'
                                        */
  real_T Constant2_Value[3];           /* Expression: hd.den{1,1}
                                        * Referenced by: '<S61>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S61>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S64>/TSamp'
                                        */
  real_T AccelerationLimit_RisingLim;  /* Computed Parameter: AccelerationLimit_RisingLim
                                        * Referenced by: '<S61>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_FallingLim; /* Computed Parameter: AccelerationLimit_FallingLim
                                        * Referenced by: '<S61>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_IC;         /* Expression: 0
                                        * Referenced by: '<S61>/Acceleration Limit'
                                        */
  real_T Memory_X0;                    /* Expression: 1
                                        * Referenced by: '<S61>/Memory'
                                        */
  real_T reset_P1_d;                   /* Expression: width
                                        * Referenced by: '<S63>/reset'
                                        */
  real_T reset_P2_dg;                  /* Expression: dtype
                                        * Referenced by: '<S63>/reset'
                                        */
  real_T reset_P3_h;                   /* Expression: portnum
                                        * Referenced by: '<S63>/reset'
                                        */
  real_T reset_P4_l;                   /* Expression: stime
                                        * Referenced by: '<S63>/reset'
                                        */
  real_T reset_P5_f;                   /* Expression: stype
                                        * Referenced by: '<S63>/reset'
                                        */
  real_T reset_P6_p;                   /* Expression: btype
                                        * Referenced by: '<S63>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_i;/* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                                          * Referenced by: '<S63>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_a;  /* Expression: 0
                                        * Referenced by: '<S63>/Discrete-Time Integrator'
                                        */
  real_T NaN_Value;                    /* Expression: 0
                                        * Referenced by: '<S61>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_h;/* Expression: 0
                                          * Referenced by: '<S52>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_ba[2];         /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Constant1_Value_p[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S53>/Constant1'
                                        */
  real_T Delay_InitialCondition_f;     /* Expression: 0
                                        * Referenced by: '<S53>/Delay'
                                        */
  real_T Delay_InitialCondition_a;     /* Expression: 0
                                        * Referenced by: '<S71>/Delay'
                                        */
  real_T Constant1_Value_l[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S71>/Constant1'
                                        */
  real_T Constant2_Value_l[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S71>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_n;/* Expression: 0
                                          * Referenced by: '<S71>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_n;                 /* Computed Parameter: TSamp_WtEt_n
                                        * Referenced by: '<S74>/TSamp'
                                        */
  real_T AccelerationLimit_RisingLim_n;/* Computed Parameter: AccelerationLimit_RisingLim_n
                                        * Referenced by: '<S71>/Acceleration Limit'
                                        */
  real_T AccelerationLimit_FallingLim_l;/* Computed Parameter: AccelerationLimit_FallingLim_l
                                         * Referenced by: '<S71>/Acceleration Limit'
                                         */
  real_T AccelerationLimit_IC_i;       /* Expression: 0
                                        * Referenced by: '<S71>/Acceleration Limit'
                                        */
  real_T Memory_X0_b;                  /* Expression: 1
                                        * Referenced by: '<S71>/Memory'
                                        */
  real_T reset_P1_dh;                  /* Expression: width
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P2_k;                   /* Expression: dtype
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P3_k;                   /* Expression: portnum
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P4_o;                   /* Expression: stime
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P5_c;                   /* Expression: stype
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T reset_P6_i;                   /* Expression: btype
                                        * Referenced by: '<S73>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_d;/* Computed Parameter: DiscreteTimeIntegrator_gainva_d
                                          * Referenced by: '<S73>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_g;  /* Expression: 0
                                        * Referenced by: '<S73>/Discrete-Time Integrator'
                                        */
  real_T NaN_Value_b;                  /* Expression: 0
                                        * Referenced by: '<S71>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_e;/* Expression: 0
                                          * Referenced by: '<S53>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_e[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T Constant1_Value_jt[2];        /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S54>/Constant1'
                                        */
  real_T Delay_InitialCondition_ac;    /* Expression: 0
                                        * Referenced by: '<S54>/Delay'
                                        */
  real_T Delay_InitialCondition_h;     /* Expression: 0
                                        * Referenced by: '<S81>/Delay'
                                        */
  real_T Constant1_Value_k[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S81>/Constant1'
                                        */
  real_T Constant2_Value_n[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S81>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_g;/* Expression: 0
                                          * Referenced by: '<S81>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_nn;                /* Computed Parameter: TSamp_WtEt_nn
                                        * Referenced by: '<S84>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim;/* Computed Parameter: Accelerationlimiter_RisingLim
                                        * Referenced by: '<S81>/Acceleration limiter'
                                        */
  real_T Accelerationlimiter_FallingLim;/* Computed Parameter: Accelerationlimiter_FallingLim
                                         * Referenced by: '<S81>/Acceleration limiter'
                                         */
  real_T Accelerationlimiter_IC;       /* Expression: 0
                                        * Referenced by: '<S81>/Acceleration limiter'
                                        */
  real_T Memory_X0_d;                  /* Expression: 1
                                        * Referenced by: '<S81>/Memory'
                                        */
  real_T reset_P1_nu;                  /* Expression: width
                                        * Referenced by: '<S83>/reset'
                                        */
  real_T reset_P2_i;                   /* Expression: dtype
                                        * Referenced by: '<S83>/reset'
                                        */
  real_T reset_P3_o;                   /* Expression: portnum
                                        * Referenced by: '<S83>/reset'
                                        */
  real_T reset_P4_f;                   /* Expression: stime
                                        * Referenced by: '<S83>/reset'
                                        */
  real_T reset_P5_bc;                  /* Expression: stype
                                        * Referenced by: '<S83>/reset'
                                        */
  real_T reset_P6_l;                   /* Expression: btype
                                        * Referenced by: '<S83>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_n;/* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                                          * Referenced by: '<S83>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_nl; /* Expression: 0
                                        * Referenced by: '<S83>/Discrete-Time Integrator'
                                        */
  real_T NaN_Value_d;                  /* Expression: 0
                                        * Referenced by: '<S81>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_j;/* Expression: 0
                                          * Referenced by: '<S54>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_k[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T Constant1_Value_g[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S55>/Constant1'
                                        */
  real_T Delay_InitialCondition_k;     /* Expression: 0
                                        * Referenced by: '<S55>/Delay'
                                        */
  real_T Delay_InitialCondition_fb;    /* Expression: 0
                                        * Referenced by: '<S91>/Delay'
                                        */
  real_T Constant1_Value_lv[3];        /* Expression: hd.num{1,1}
                                        * Referenced by: '<S91>/Constant1'
                                        */
  real_T Constant2_Value_o[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S91>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_ny;/* Expression: 0
                                          * Referenced by: '<S91>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_p;                 /* Computed Parameter: TSamp_WtEt_p
                                        * Referenced by: '<S94>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_f;/* Computed Parameter: Accelerationlimiter_RisingLim_f
                                          * Referenced by: '<S91>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_b;/* Computed Parameter: Accelerationlimiter_FallingLi_b
                                          * Referenced by: '<S91>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_e;     /* Expression: 0
                                        * Referenced by: '<S91>/Acceleration limiter'
                                        */
  real_T Memory_X0_dj;                 /* Expression: 1
                                        * Referenced by: '<S91>/Memory'
                                        */
  real_T reset_P1_h;                   /* Expression: width
                                        * Referenced by: '<S93>/reset'
                                        */
  real_T reset_P2_ei;                  /* Expression: dtype
                                        * Referenced by: '<S93>/reset'
                                        */
  real_T reset_P3_gn;                  /* Expression: portnum
                                        * Referenced by: '<S93>/reset'
                                        */
  real_T reset_P4_ou;                  /* Expression: stime
                                        * Referenced by: '<S93>/reset'
                                        */
  real_T reset_P5_fm;                  /* Expression: stype
                                        * Referenced by: '<S93>/reset'
                                        */
  real_T reset_P6_p5;                  /* Expression: btype
                                        * Referenced by: '<S93>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;/* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                          * Referenced by: '<S93>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_d;  /* Expression: 0
                                        * Referenced by: '<S93>/Discrete-Time Integrator'
                                        */
  real_T NaN_Value_m;                  /* Expression: 0
                                        * Referenced by: '<S91>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_i;/* Expression: 0
                                          * Referenced by: '<S55>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_d[2];          /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T Constant1_Value_pe[2];        /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S56>/Constant1'
                                        */
  real_T Delay_InitialCondition_h5;    /* Expression: 0
                                        * Referenced by: '<S56>/Delay'
                                        */
  real_T Delay_InitialCondition_l;     /* Expression: 0
                                        * Referenced by: '<S101>/Delay'
                                        */
  real_T Constant1_Value_n[3];         /* Expression: hd.num{1,1}
                                        * Referenced by: '<S101>/Constant1'
                                        */
  real_T Constant2_Value_b[3];         /* Expression: hd.den{1,1}
                                        * Referenced by: '<S101>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_es;/* Expression: 0
                                          * Referenced by: '<S101>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_m;                 /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S104>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_o;/* Computed Parameter: Accelerationlimiter_RisingLim_o
                                          * Referenced by: '<S101>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_l;/* Computed Parameter: Accelerationlimiter_FallingLi_l
                                          * Referenced by: '<S101>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_l;     /* Expression: 0
                                        * Referenced by: '<S101>/Acceleration limiter'
                                        */
  real_T Memory_X0_bf;                 /* Expression: 1
                                        * Referenced by: '<S101>/Memory'
                                        */
  real_T reset_P1_g;                   /* Expression: width
                                        * Referenced by: '<S103>/reset'
                                        */
  real_T reset_P2_cq;                  /* Expression: dtype
                                        * Referenced by: '<S103>/reset'
                                        */
  real_T reset_P3_l;                   /* Expression: portnum
                                        * Referenced by: '<S103>/reset'
                                        */
  real_T reset_P4_p;                   /* Expression: stime
                                        * Referenced by: '<S103>/reset'
                                        */
  real_T reset_P5_bu;                  /* Expression: stype
                                        * Referenced by: '<S103>/reset'
                                        */
  real_T reset_P6_bl;                  /* Expression: btype
                                        * Referenced by: '<S103>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_h;/* Computed Parameter: DiscreteTimeIntegrator_gainva_h
                                          * Referenced by: '<S103>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_gu; /* Expression: 0
                                        * Referenced by: '<S103>/Discrete-Time Integrator'
                                        */
  real_T NaN_Value_k;                  /* Expression: 0
                                        * Referenced by: '<S101>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialSt_d;/* Expression: 0
                                          * Referenced by: '<S56>/Discrete Transfer Fcn'
                                          */
  real_T Constant_Value_kr[2];         /* Expression: hd2.den{1,1}
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T Constant1_Value_d[2];         /* Expression: hd2.num{1,1}
                                        * Referenced by: '<S57>/Constant1'
                                        */
  real_T Delay_InitialCondition_j;     /* Expression: 0
                                        * Referenced by: '<S57>/Delay'
                                        */
  real_T Delay_InitialCondition_h0;    /* Expression: 0
                                        * Referenced by: '<S111>/Delay'
                                        */
  real_T Constant1_Value_d1[3];        /* Expression: hd.num{1,1}
                                        * Referenced by: '<S111>/Constant1'
                                        */
  real_T Constant2_Value_ni[3];        /* Expression: hd.den{1,1}
                                        * Referenced by: '<S111>/Constant2'
                                        */
  real_T DiscreteTransferFcn_InitialS_nf;/* Expression: 0
                                          * Referenced by: '<S111>/Discrete Transfer Fcn'
                                          */
  real_T TSamp_WtEt_i;                 /* Computed Parameter: TSamp_WtEt_i
                                        * Referenced by: '<S114>/TSamp'
                                        */
  real_T Accelerationlimiter_RisingLim_b;/* Computed Parameter: Accelerationlimiter_RisingLim_b
                                          * Referenced by: '<S111>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_FallingLi_a;/* Computed Parameter: Accelerationlimiter_FallingLi_a
                                          * Referenced by: '<S111>/Acceleration limiter'
                                          */
  real_T Accelerationlimiter_IC_c;     /* Expression: 0
                                        * Referenced by: '<S111>/Acceleration limiter'
                                        */
  real_T Memory_X0_g;                  /* Expression: 1
                                        * Referenced by: '<S111>/Memory'
                                        */
  real_T reset_P1_f;                   /* Expression: width
                                        * Referenced by: '<S113>/reset'
                                        */
  real_T reset_P2_l;                   /* Expression: dtype
                                        * Referenced by: '<S113>/reset'
                                        */
  real_T reset_P3_c;                   /* Expression: portnum
                                        * Referenced by: '<S113>/reset'
                                        */
  real_T reset_P4_lu;                  /* Expression: stime
                                        * Referenced by: '<S113>/reset'
                                        */
  real_T reset_P5_e;                   /* Expression: stype
                                        * Referenced by: '<S113>/reset'
                                        */
  real_T reset_P6_a;                   /* Expression: btype
                                        * Referenced by: '<S113>/reset'
                                        */
  real_T DiscreteTimeIntegrator_gainva_k;/* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                          * Referenced by: '<S113>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_eo; /* Expression: 0
                                        * Referenced by: '<S113>/Discrete-Time Integrator'
                                        */
  real_T NaN_Value_db;                 /* Expression: 0
                                        * Referenced by: '<S111>/NaN'
                                        */
  real_T DiscreteTransferFcn_InitialS_iv;/* Expression: 0
                                          * Referenced by: '<S57>/Discrete Transfer Fcn'
                                          */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S10>/Delay'
                                        */
  uint32_T Delay_DelayLength_e;        /* Computed Parameter: Delay_DelayLength_e
                                        * Referenced by: '<S7>/Delay'
                                        */
  uint32_T Delay_DelayLength_f;        /* Computed Parameter: Delay_DelayLength_f
                                        * Referenced by: '<S52>/Delay'
                                        */
  uint32_T Delay_DelayLength_m;        /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S61>/Delay'
                                        */
  uint32_T Delay_DelayLength_l;        /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S53>/Delay'
                                        */
  uint32_T Delay_DelayLength_fj;       /* Computed Parameter: Delay_DelayLength_fj
                                        * Referenced by: '<S71>/Delay'
                                        */
  uint32_T Delay_DelayLength_ew;       /* Computed Parameter: Delay_DelayLength_ew
                                        * Referenced by: '<S54>/Delay'
                                        */
  uint32_T Delay_DelayLength_m5;       /* Computed Parameter: Delay_DelayLength_m5
                                        * Referenced by: '<S81>/Delay'
                                        */
  uint32_T Delay_DelayLength_h;        /* Computed Parameter: Delay_DelayLength_h
                                        * Referenced by: '<S55>/Delay'
                                        */
  uint32_T Delay_DelayLength_k;        /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S91>/Delay'
                                        */
  uint32_T Delay_DelayLength_hg;       /* Computed Parameter: Delay_DelayLength_hg
                                        * Referenced by: '<S56>/Delay'
                                        */
  uint32_T Delay_DelayLength_n;        /* Computed Parameter: Delay_DelayLength_n
                                        * Referenced by: '<S101>/Delay'
                                        */
  uint32_T Delay_DelayLength_b;        /* Computed Parameter: Delay_DelayLength_b
                                        * Referenced by: '<S57>/Delay'
                                        */
  uint32_T Delay_DelayLength_c;        /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S111>/Delay'
                                        */
  P_CoreSubsys_ctrl_student_T CoreSubsys;/* '<S43>/CoreSubsys' */
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
 * '<S1>'   : 'ctrl_student/MATLAB Function'
 * '<S2>'   : 'ctrl_student/Parameters From initfile distributed '
 * '<S3>'   : 'ctrl_student/Pos measurements'
 * '<S4>'   : 'ctrl_student/Radians to Degrees'
 * '<S5>'   : 'ctrl_student/TAPM Controller w_observer'
 * '<S6>'   : 'ctrl_student/Thrust allocation1'
 * '<S7>'   : 'ctrl_student/Thruster control '
 * '<S8>'   : 'ctrl_student/Thruster measurment'
 * '<S9>'   : 'ctrl_student/TAPM Controller w_observer/Non-linear passive observer '
 * '<S10>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller'
 * '<S11>'  : 'ctrl_student/TAPM Controller w_observer/SP Generator'
 * '<S12>'  : 'ctrl_student/TAPM Controller w_observer/[-inf inf] to [-pi pi]'
 * '<S13>'  : 'ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Rotation matrix in yaw 1'
 * '<S14>'  : 'ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Transposed rotation  matrix in yaw'
 * '<S15>'  : 'ctrl_student/TAPM Controller w_observer/Non-linear passive observer /Transposed rotation  matrix in yaw1'
 * '<S16>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Inside'
 * '<S17>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/MATLAB Function'
 * '<S18>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/MATLAB Function3'
 * '<S19>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Outside'
 * '<S20>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/PID Controller'
 * '<S21>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/PID Controller1'
 * '<S22>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Inside/MATLAB Function'
 * '<S23>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Inside/MATLAB Function1'
 * '<S24>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Inside/MATLAB Function2'
 * '<S25>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Inside/Transposed rotation  matrix in yaw1'
 * '<S26>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Inside/[-inf inf] to [-pi pi]'
 * '<S27>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Inside/[-inf inf] to [-pi pi]1'
 * '<S28>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Outside/MATLAB Function4'
 * '<S29>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Outside/MATLAB Function5'
 * '<S30>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Outside/MATLAB Function6'
 * '<S31>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Outside/Transposed rotation  matrix in yaw1'
 * '<S32>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Outside/[-inf inf] to [-pi pi]'
 * '<S33>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/Outside/[-inf inf] to [-pi pi]1'
 * '<S34>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/PID Controller/Transposed rotation  matrix in yaw1'
 * '<S35>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/PID Controller/[-inf inf] to [-pi pi]'
 * '<S36>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/PID Controller/[-inf inf] to [-pi pi]1'
 * '<S37>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/PID Controller1/MATLAB Function'
 * '<S38>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/PID Controller1/Transposed rotation  matrix in yaw1'
 * '<S39>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/PID Controller1/[-inf inf] to [-pi pi]'
 * '<S40>'  : 'ctrl_student/TAPM Controller w_observer/SP Controller/PID Controller1/[-inf inf] to [-pi pi]1'
 * '<S41>'  : 'ctrl_student/TAPM Controller w_observer/SP Generator/MATLAB Function3'
 * '<S42>'  : 'ctrl_student/TAPM Controller w_observer/SP Generator/Set-Point Limiter'
 * '<S43>'  : 'ctrl_student/Thrust allocation1/For Each Subsystem'
 * '<S44>'  : 'ctrl_student/Thrust allocation1/MATLAB Function'
 * '<S45>'  : 'ctrl_student/Thrust allocation1/MATLAB Function1'
 * '<S46>'  : 'ctrl_student/Thrust allocation1/Radians to Degrees'
 * '<S47>'  : 'ctrl_student/Thrust allocation1/For Each Subsystem/Degrees to Radians'
 * '<S48>'  : 'ctrl_student/Thrust allocation1/For Each Subsystem/MATLAB Function'
 * '<S49>'  : 'ctrl_student/Thrust allocation1/For Each Subsystem/MATLAB Function1'
 * '<S50>'  : 'ctrl_student/Thruster control /Subsystem'
 * '<S51>'  : 'ctrl_student/Thruster control /Subsystem1'
 * '<S52>'  : 'ctrl_student/Thruster control /Thruster 1'
 * '<S53>'  : 'ctrl_student/Thruster control /Thruster 2'
 * '<S54>'  : 'ctrl_student/Thruster control /Thruster 3'
 * '<S55>'  : 'ctrl_student/Thruster control /Thruster 4'
 * '<S56>'  : 'ctrl_student/Thruster control /Thruster 5'
 * '<S57>'  : 'ctrl_student/Thruster control /Thruster 6'
 * '<S58>'  : 'ctrl_student/Thruster control /Subsystem/MATLAB Function'
 * '<S59>'  : 'ctrl_student/Thruster control /Thruster 1/Propeller Hydrodynamics'
 * '<S60>'  : 'ctrl_student/Thruster control /Thruster 1/Shaft dynamics'
 * '<S61>'  : 'ctrl_student/Thruster control /Thruster 1/Thruster control'
 * '<S62>'  : 'ctrl_student/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S63>'  : 'ctrl_student/Thruster control /Thruster 1/Thruster control/Core controller'
 * '<S64>'  : 'ctrl_student/Thruster control /Thruster 1/Thruster control/Discrete Derivative'
 * '<S65>'  : 'ctrl_student/Thruster control /Thruster 1/Thruster control/MATLAB Function'
 * '<S66>'  : 'ctrl_student/Thruster control /Thruster 1/Thruster control/Supervisor'
 * '<S67>'  : 'ctrl_student/Thruster control /Thruster 1/Thruster control/Torque limit'
 * '<S68>'  : 'ctrl_student/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S69>'  : 'ctrl_student/Thruster control /Thruster 2/Propeller Hydrodynamics'
 * '<S70>'  : 'ctrl_student/Thruster control /Thruster 2/Shaft dynamics'
 * '<S71>'  : 'ctrl_student/Thruster control /Thruster 2/Thruster control'
 * '<S72>'  : 'ctrl_student/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S73>'  : 'ctrl_student/Thruster control /Thruster 2/Thruster control/Core controller'
 * '<S74>'  : 'ctrl_student/Thruster control /Thruster 2/Thruster control/Discrete Derivative'
 * '<S75>'  : 'ctrl_student/Thruster control /Thruster 2/Thruster control/MATLAB Function'
 * '<S76>'  : 'ctrl_student/Thruster control /Thruster 2/Thruster control/Supervisor'
 * '<S77>'  : 'ctrl_student/Thruster control /Thruster 2/Thruster control/Torque limit'
 * '<S78>'  : 'ctrl_student/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S79>'  : 'ctrl_student/Thruster control /Thruster 3/Propeller Hydrodynamics'
 * '<S80>'  : 'ctrl_student/Thruster control /Thruster 3/Shaft dynamics'
 * '<S81>'  : 'ctrl_student/Thruster control /Thruster 3/Thruster control'
 * '<S82>'  : 'ctrl_student/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S83>'  : 'ctrl_student/Thruster control /Thruster 3/Thruster control/Core controller'
 * '<S84>'  : 'ctrl_student/Thruster control /Thruster 3/Thruster control/Discrete Derivative'
 * '<S85>'  : 'ctrl_student/Thruster control /Thruster 3/Thruster control/MATLAB Function'
 * '<S86>'  : 'ctrl_student/Thruster control /Thruster 3/Thruster control/Supervisor'
 * '<S87>'  : 'ctrl_student/Thruster control /Thruster 3/Thruster control/Torque limit'
 * '<S88>'  : 'ctrl_student/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S89>'  : 'ctrl_student/Thruster control /Thruster 4/Propeller Hydrodynamics'
 * '<S90>'  : 'ctrl_student/Thruster control /Thruster 4/Shaft dynamics'
 * '<S91>'  : 'ctrl_student/Thruster control /Thruster 4/Thruster control'
 * '<S92>'  : 'ctrl_student/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S93>'  : 'ctrl_student/Thruster control /Thruster 4/Thruster control/Core controller'
 * '<S94>'  : 'ctrl_student/Thruster control /Thruster 4/Thruster control/Discrete Derivative'
 * '<S95>'  : 'ctrl_student/Thruster control /Thruster 4/Thruster control/MATLAB Function'
 * '<S96>'  : 'ctrl_student/Thruster control /Thruster 4/Thruster control/Supervisor'
 * '<S97>'  : 'ctrl_student/Thruster control /Thruster 4/Thruster control/Torque limit'
 * '<S98>'  : 'ctrl_student/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S99>'  : 'ctrl_student/Thruster control /Thruster 5/Propeller Hydrodynamics'
 * '<S100>' : 'ctrl_student/Thruster control /Thruster 5/Shaft dynamics'
 * '<S101>' : 'ctrl_student/Thruster control /Thruster 5/Thruster control'
 * '<S102>' : 'ctrl_student/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S103>' : 'ctrl_student/Thruster control /Thruster 5/Thruster control/Core controller'
 * '<S104>' : 'ctrl_student/Thruster control /Thruster 5/Thruster control/Discrete Derivative'
 * '<S105>' : 'ctrl_student/Thruster control /Thruster 5/Thruster control/MATLAB Function'
 * '<S106>' : 'ctrl_student/Thruster control /Thruster 5/Thruster control/Supervisor'
 * '<S107>' : 'ctrl_student/Thruster control /Thruster 5/Thruster control/Torque limit'
 * '<S108>' : 'ctrl_student/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 * '<S109>' : 'ctrl_student/Thruster control /Thruster 6/Propeller Hydrodynamics'
 * '<S110>' : 'ctrl_student/Thruster control /Thruster 6/Shaft dynamics'
 * '<S111>' : 'ctrl_student/Thruster control /Thruster 6/Thruster control'
 * '<S112>' : 'ctrl_student/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque'
 * '<S113>' : 'ctrl_student/Thruster control /Thruster 6/Thruster control/Core controller'
 * '<S114>' : 'ctrl_student/Thruster control /Thruster 6/Thruster control/Discrete Derivative'
 * '<S115>' : 'ctrl_student/Thruster control /Thruster 6/Thruster control/MATLAB Function'
 * '<S116>' : 'ctrl_student/Thruster control /Thruster 6/Thruster control/Supervisor'
 * '<S117>' : 'ctrl_student/Thruster control /Thruster 6/Thruster control/Torque limit'
 * '<S118>' : 'ctrl_student/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power'
 */
#endif                                 /* RTW_HEADER_ctrl_student_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_student
 * Model version : 1.63
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Thu May 12 11:09:11 2016
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
