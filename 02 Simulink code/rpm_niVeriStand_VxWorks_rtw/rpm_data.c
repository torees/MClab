#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define rpm_P                         rpm_P DataSection(".NIVS.defaultparams")
#endif

/*
 * rpm_data.c
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
#include "rpm.h"
#include "rpm_private.h"

/* Block parameters (auto storage) */
P_rpm_T rpm_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolutions1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolutions1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolutions1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolutions1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory2'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain1'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/rpm1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/rpm1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/rpm1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/rpm1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/rpm1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/rpm1'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/measurment1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/measurment1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/measurment1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/measurment1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/measurment1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/measurment1'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolutions2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolutions2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolutions2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolutions2'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolution1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolution1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/revolution1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolution1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolution1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolution1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolutions3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions3'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolutions3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolutions3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolutions3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory6'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/measurment2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/measurment2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/measurment2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/measurment2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/measurment2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/measurment2'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolutions4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions4'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolutions4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolutions4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolutions4'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolution2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolution2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/revolution2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolution2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolution2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolution2'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolutions5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions5'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolutions5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolutions5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolutions5'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain2'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/rpm2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/rpm2'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/rpm2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/rpm2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/rpm2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/rpm2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolutions6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolutions6'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/revolutions6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolutions6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolutions6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolutions6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory11'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory10'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/measurment3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/measurment3'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/measurment3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/measurment3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/measurment3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/measurment3'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolution3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolution3'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/revolution3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolution3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolution3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolution3'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain4'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/rpm3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/rpm3'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/rpm3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/rpm3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/rpm3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/rpm3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory15'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory12'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory13'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory14'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/measurment4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/measurment4'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/measurment4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/measurment4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/measurment4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/measurment4'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolution4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolution4'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/revolution4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolution4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolution4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolution4'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/rpm4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/rpm4'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/rpm4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/rpm4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/rpm4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/rpm4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory19'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory16'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory17'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory18'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/measurment5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/measurment5'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/measurment5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/measurment5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/measurment5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/measurment5'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolution5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolution5'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/revolution5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolution5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolution5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolution5'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain3'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/rpm5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/rpm5'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/rpm5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/rpm5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/rpm5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/rpm5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory23'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory20'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory21'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory22'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/measurment6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/measurment6'
                                        */
  16.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/measurment6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/measurment6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/measurment6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/measurment6'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/revolution6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/revolution6'
                                        */
  17.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/revolution6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/revolution6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/revolution6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/revolution6'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain5'
                                        */
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/rpm6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/rpm6'
                                        */
  18.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/rpm6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/rpm6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/rpm6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/rpm6'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : rpm
 * Model version : 1.68
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Sun Jun 26 19:52:37 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_rpm_T_sizes[] DataSection(".NIVS.defaultparamsizes") = {
  { sizeof(P_rpm_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
