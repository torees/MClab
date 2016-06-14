#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_sixaxis2force_P          ctrl_sixaxis2force_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_sixaxis2force_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_sixaxis2force".
 *
 * Model version              : 1.45
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon May 09 18:24:11 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_sixaxis2force.h"
#include "ctrl_sixaxis2force_private.h"

/* Block parameters (auto storage) */
P_ctrl_sixaxis2force_T ctrl_sixaxis2force_P = {
  0.12,                                /* Variable: Max_thrust
                                        * Referenced by:
                                        *   '<S1>/Saturation 1'
                                        *   '<S1>/Saturation 2'
                                        *   '<S1>/Saturation 3'
                                        *   '<S1>/Saturation 4'
                                        *   '<S1>/Saturation 5'
                                        *   '<S1>/Saturation 6'
                                        *   '<S1>/Saturation 7'
                                        */

  /*  Variable: thrust_to_pwm_coeff
   * Referenced by:
   *   '<S1>/pwm thruster 1'
   *   '<S1>/pwm thruster 2'
   *   '<S1>/pwm thruster 3'
   *   '<S1>/pwm thruster 4'
   *   '<S1>/pwm thruster 5'
   *   '<S1>/pwm thruster 6'
   */
  { 0.049001709187525007, -0.39510945913232864, 1.1559741339627327,
    -1.5170203014582015, 1.214660465174924, 0.0 },
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
  12.0,                                /* Expression: portnum
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
  11.0,                                /* Expression: portnum
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
  13.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/L2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/L2_continuous'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/L2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/L2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/L2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/L2_continuous'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  -0.5,                                /* Expression: -.5
                                        * Referenced by: '<Root>/Gain'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/N'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/N'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/N'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/N'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/N'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/N'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/PosXLeft'
                                        */
  2.0,                                 /* Expression: portnum
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
  9.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/thr_angle_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/thr_angle_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/thr_angle_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/thr_angle_2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/thr_angle_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/thr_angle_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/thr_angle_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/thr_angle_3'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/thr_angle_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/thr_angle_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/thr_angle_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/thr_angle_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/thr_angle_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/thr_angle_4'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/thr_angle_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/thr_angle_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/thr_angle_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/thr_angle_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/thr_angle_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/thr_angle_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/thr_angle_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/thr_angle_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/thr_angle_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/thr_angle_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/thr_angle_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/thr_angle_6'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/thr_angle_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/thr_angle_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/thr_angle_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/thr_angle_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/body_rel'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/body_rel'
                                        */
  18.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/body_rel'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/body_rel'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/body_rel'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/body_rel'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/basin_rel'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/basin_rel'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/basin_rel'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/basin_rel'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/basin_rel'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/basin_rel'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/user_rel'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/user_rel'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/user_rel'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/user_rel'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/user_rel'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/user_rel'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi'
                                        */
  16.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/user_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/user_psi'
                                        */
  17.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/user_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/user_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/user_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/user_psi'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain2'
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
                                        * Referenced by: '<Root>/X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/X'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/X'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Y'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Y'
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
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  7.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  8.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  10.0,                                /* Expression: portnum
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  11.0,                                /* Expression: portnum
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
  12.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_4'
                                        */
  13.0,                                /* Expression: portnum
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
  14.0,                                /* Expression: portnum
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
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_limit'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_limit'
                                        */
  16.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/u_limit'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_limit'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_limit'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/u_limit'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_4'
                                        */
  17.0,                                /* Expression: portnum
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
  18.0,                                /* Expression: portnum
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
  19.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_1'
                                        */
  20.0,                                /* Expression: portnum
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
  21.0,                                /* Expression: portnum
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
  22.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/u_3'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<Root>/u_3'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_sixaxis2force
 * Model version : 1.45
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Mon May 09 18:24:11 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_sixaxis2force_T_sizes[] DataSection(
  ".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_sixaxis2force_T), 1 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
