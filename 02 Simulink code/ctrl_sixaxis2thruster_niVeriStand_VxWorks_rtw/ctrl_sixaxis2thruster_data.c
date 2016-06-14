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
 * Model version              : 1.61
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon May 09 18:03:23 2016
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
  /*  Variable: thrust_to_pwm_coeff
   * Referenced by:
   *   '<S3>/pwm thruster'
   *   '<S4>/pwm thruster'
   */
  { 0.049001709187525007, -0.39510945913232864, 1.1559741339627327,
    -1.5170203014582015, 1.214660465174924, 0.0 },
  0.0,                                 /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S6>/Delay Input1'
                                        */
  0.0,                                 /* Mask Parameter: DetectIncrease1_vinit
                                        * Referenced by: '<S7>/Delay Input1'
                                        */
  0.0,                                 /* Mask Parameter: DetectIncrease2_vinit
                                        * Referenced by: '<S8>/Delay Input1'
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
                                        * Referenced by: '<S5>/Memory'
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
  1.1235955056179776,                  /* Expression: 1/0.89
                                        * Referenced by: '<S3>/U_1 limit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Saturation 1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S3>/Saturation 1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S2>/Constant'
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
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/pwm_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_3'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/pwm_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/pwm_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/pwm_3'
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
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S1>/Constant'
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  8.0,                                 /* Expression: portnum
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
  9.0,                                 /* Expression: portnum
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
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/u_limit_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_limit_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_limit_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_limit_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_1'
                                        */
  11.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_2'
                                        */
  12.0,                                /* Expression: portnum
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
  13.0,                                /* Expression: portnum
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
  14.0,                                /* Expression: portnum
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
  15.0,                                /* Expression: portnum
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
  16.0,                                /* Expression: portnum
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
  1.1235955056179776,                  /* Expression: 1/0.89
                                        * Referenced by: '<S4>/U_1 limit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Saturation 1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S4>/Saturation 1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  17.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/pwm_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_5'
                                        */
  18.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/pwm_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/pwm_5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/pwm_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  19.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<Root>/pwm_6'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_sixaxis2thruster
 * Model version : 1.61
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Mon May 09 18:03:22 2016
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

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
