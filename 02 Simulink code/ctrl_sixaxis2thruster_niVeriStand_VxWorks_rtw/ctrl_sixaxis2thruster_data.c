#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_sixaxis2thruster_P       ctrl_sixaxis2thruster_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_sixaxis2thruster_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_sixaxis2thruster".
 *
 * Model version              : 1.58
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed May 04 12:57:15 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_sixaxis2thruster.h"
#include "ctrl_sixaxis2thruster_private.h"

/* Block parameters (auto storage) */
P_ctrl_sixaxis2thruster_T ctrl_sixaxis2thruster_P = {
  0.0,                                 /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S4>/Delay Input1'
                                        */
  0.0,                                 /* Mask Parameter: DetectIncrease1_vinit
                                        * Referenced by: '<S5>/Delay Input1'
                                        */
  0.0,                                 /* Mask Parameter: DetectIncrease2_vinit
                                        * Referenced by: '<S6>/Delay Input1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/ArrowUp'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ArrowUp'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/ArrowUp'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/ArrowUp'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/ArrowUp'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/ArrowUp'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/ArrowDown'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/ArrowDown'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/ArrowDown'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/ArrowDown'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/ArrowDown'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/ArrowDown'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Start'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Start'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Start'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Start'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Start'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Start'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_3'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/PosYRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/PosYRight'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/PosYRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/PosYRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/PosYRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/PosYRight'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/PosXRight'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/PosXRight'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/PosXRight'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/PosXRight'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/PosXRight'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/PosXRight'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_4'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_5'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_6'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_limit_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_limit_out'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/u_limit_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_limit_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_limit_out'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<Root>/u_limit_out'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_sixaxis2thruster
 * Model version : 1.58
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Wed May 04 12:57:15 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_sixaxis2thruster_T_sizes[] DataSection(
  ".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_sixaxis2thruster_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
