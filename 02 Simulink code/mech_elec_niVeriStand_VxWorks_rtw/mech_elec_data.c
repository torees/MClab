#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define mech_elec_P                   mech_elec_P DataSection(".NIVS.defaultparams")
#endif

/*
 * mech_elec_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "mech_elec".
 *
 * Model version              : 1.30
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Apr 14 09:16:29 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "mech_elec.h"
#include "mech_elec_private.h"

/* Block parameters (auto storage) */
P_mech_elec_T mech_elec_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_5,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_5,d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_5,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_5,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_5,d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_5,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_4,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_4,d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_4,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_4,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_4,d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_4,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_1,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_1,d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_1,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_1,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_1,d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_1,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_6,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_6,d'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_6,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_6,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_6,d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_6,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_1,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_1,d'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_1,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_1,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_1,d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_1,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_2,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_2,d'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_2,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_2,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_2,d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_2,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/u_3,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/u_3,d'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/u_3,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/u_3,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/u_3,d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/u_3,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_2,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_2,d'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_2,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_2,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_2,d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_2,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_3,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_3,d'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_3,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_3,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_3,d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_3,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_4,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_4,d'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_4,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_4,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_4,d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_4,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_5,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_5,d'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_5,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_5,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_5,d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_5,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/alpha_6,d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/alpha_6,d'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/alpha_6,d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/alpha_6,d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/alpha_6,d'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/alpha_6,d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/alpha_2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/alpha_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/alpha_3'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/alpha_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/alpha_4'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/alpha_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/alpha_5'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/alpha_5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/alpha_6'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/alpha_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/u_2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/u_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/u_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/u_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/u_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/u_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/alpha_1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/alpha_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/u_6'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/u_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/u_4'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/u_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/u_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/u_5'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<S2>/u_5'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : mech_elec
 * Model version : 1.30
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Thu Apr 14 09:16:29 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_mech_elec_T_sizes[] DataSection(".NIVS.defaultparamsizes") =
{
  { sizeof(P_mech_elec_T), 1 },

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
