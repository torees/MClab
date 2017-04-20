#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_student_P                ctrl_student_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_student_data.c
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
#include "ctrl_student.h"
#include "ctrl_student_private.h"

/* Block parameters (auto storage) */
P_ctrl_student_T ctrl_student_P = {
  /*  Mask Parameter: Nonlinearpassiveobserver_D
   * Referenced by: '<S21>/Gain6'
   */
  { 1.0776367786545441E-5, 0.0, 0.0, 0.0, 8.4445579E-5, 1.808866E-6, 0.0,
    1.808866E-6, 2.7368522E-5 },

  /*  Mask Parameter: Nonlinearpassiveobserver_K3
   * Referenced by: '<S21>/K3'
   */
  { 10.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 10.0 },

  /*  Mask Parameter: Nonlinearpassiveobserver_K4
   * Referenced by: '<S21>/K4'
   */
  { 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0 },

  /*  Mask Parameter: Nonlinearpassiveobserver_w_c
   * Referenced by: '<S21>/K2'
   */
  { 1.3, 0.0, 0.0, 0.0, 1.3, 0.0, 0.0, 0.0, 1.3 },

  /*  Expression: [Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)]
   * Referenced by: '<Root>/constant angle'
   */
  { 180.0, -135.0, 90.0, 0.0, 45.0, -90.0 },
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S1>/Gain1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S6>/Saturation 1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S6>/Saturation 1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  1.0,                                 /* Expression: portnum
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
  1.0,                                 /* Expression: width
                                        * Referenced by: '<Root>/Enable Thrust'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Enable Thrust'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Enable Thrust'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Enable Thrust'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Enable Thrust'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Enable Thrust'
                                        */

  /*  Expression: [0 0 0 0 0 0]
   * Referenced by: '<Root>/Constant1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_2'
                                        */
  2.0,                                 /* Expression: portnum
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
  3.0,                                 /* Expression: portnum
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
  4.0,                                 /* Expression: portnum
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
  5.0,                                 /* Expression: portnum
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
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S6>/Saturation 2'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S6>/Saturation 2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  6.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_6'
                                        */
  7.0,                                 /* Expression: portnum
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
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S6>/Saturation 3'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S6>/Saturation 3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_3'
                                        */
  8.0,                                 /* Expression: portnum
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
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S6>/Saturation 4'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S6>/Saturation 4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_4'
                                        */
  9.0,                                 /* Expression: portnum
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
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S6>/Saturation 5'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S6>/Saturation 5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_5'
                                        */
  10.0,                                /* Expression: portnum
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
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S6>/Saturation 6'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S6>/Saturation 6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_6'
                                        */
  11.0,                                /* Expression: portnum
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Delay'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/wave_dir'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/wave_dir'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/wave_dir'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/wave_dir'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/wave_dir'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/wave_dir'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/fzp_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/fzp_x'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/fzp_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/fzp_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/fzp_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/fzp_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/fzp_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/fzp_y'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/fzp_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/fzp_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/fzp_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/fzp_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/r_max'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/r_max'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/r_max'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/r_max'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/r_max'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/r_max'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Core_controller'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Core_controller'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Core_controller'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Core_controller'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Core_controller'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Core_controller'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_i_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_i_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/K_i_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_i_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_i_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_i_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_d_psi'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/K_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_d_x'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/K_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_d_y'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/K_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_i_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_i_psi'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_i_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_i_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_i_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_i_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_i_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_i_x'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_i_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_i_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_i_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_i_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_p_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_p_psi'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_p_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_p_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_p_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_p_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_p_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_p_x'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_p_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_p_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_p_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_p_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_p_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_p_y'
                                        */
  14.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_p_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_p_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_p_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_p_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_d_psi1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_d_psi1'
                                        */
  15.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_d_psi1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_d_psi1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_d_psi1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_d_psi1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_d_x1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_d_x1'
                                        */
  16.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_d_x1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_d_x1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_d_x1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_d_x1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_d_y1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_d_y1'
                                        */
  17.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_d_y1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_d_y1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_d_y1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_d_y1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_i_psi1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_i_psi1'
                                        */
  18.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_i_psi1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_i_psi1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_i_psi1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_i_psi1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_i_x1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_i_x1'
                                        */
  19.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_i_x1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_i_x1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_i_x1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_i_x1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_i_y1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_i_y1'
                                        */
  20.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_i_y1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_i_y1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_i_y1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_i_y1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_p_psi1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_p_psi1'
                                        */
  21.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_p_psi1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_p_psi1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_p_psi1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_p_psi1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_p_x1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_p_x1'
                                        */
  22.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_p_x1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_p_x1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_p_x1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_p_x1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/K_p_y1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/K_p_y1'
                                        */
  23.0,                                /* Expression: portnum
                                        * Referenced by: '<S3>/K_p_y1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/K_p_y1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/K_p_y1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/K_p_y1'
                                        */

  /*  Expression: [0,0,0]'
   * Referenced by: '<S21>/Integrator'
   */
  { 0.0, 0.0, 0.0 },
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S39>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S39>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S39>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S39>/Constant'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<S23>/Integrator'
   */
  { 0.0, 0.0 },
  -2.0,                                /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S23>/Transfer Fcn2'
                                        */
  2.0,                                 /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S23>/Transfer Fcn2'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S24>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S24>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S24>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S24>/Constant'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S38>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S38>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S38>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S38>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S34>/Integrator'
                                        */

  /*  Expression: [0,0,0]'
   * Referenced by: '<S21>/Integrator4'
   */
  { 0.0, 0.0, 0.0 },
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S42>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S42>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S42>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S42>/Constant'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S41>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S41>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S41>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S41>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S35>/Integrator'
                                        */

  /*  Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
   * Referenced by: '<S7>/X-position Thruster'
   */
  { 1.0677777777777777, 0.93444444444444441, 0.93444444444444441,
    -1.1644444444444444, -0.99111111111111116, -0.99111111111111116 },

  /*  Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
   * Referenced by: '<S7>/Y-position Thruster'
   */
  { 0.0, 0.11, -0.11, 0.0, -0.16555555555555557, 0.16555555555555557 },

  /*  Expression: [Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)]
   * Referenced by: '<S7>/constant angle1'
   */
  { 180.0, -135.0, 90.0, 0.0, 45.0, -90.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_1'
                                        */
  12.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_4'
                                        */
  13.0,                                /* Expression: portnum
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
  14.0,                                /* Expression: portnum
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
  15.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_2'
                                        */
  16.0,                                /* Expression: portnum
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
  17.0,                                /* Expression: portnum
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
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_1'
                                        */
  18.0,                                /* Expression: portnum
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
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain'
                                        */

  /*  Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
   * Referenced by: '<Root>/X-position Thruster'
   */
  { 1.0677777777777777, 0.93444444444444441, 0.93444444444444441,
    -1.1644444444444444, -0.99111111111111116, -0.99111111111111116 },

  /*  Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
   * Referenced by: '<Root>/Y-position Thruster'
   */
  { 0.0, 0.11, -0.11, 0.0, -0.16555555555555557, 0.16555555555555557 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/tau_actual'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/tau_actual'
                                        */
  19.0,                                /* Expression: portnum
                                        * Referenced by: '<Root>/tau_actual'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/tau_actual'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/tau_actual'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/tau_actual'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/x_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/x_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/x_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/y_m'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/y_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/y_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/psi_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/eta_est'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/eta_est'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/eta_est'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/eta_est'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/eta_est'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/eta_est'
                                        */
  3.0,                                 /* Expression: width
                                        * Referenced by: '<S8>/nu_est'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/nu_est'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/nu_est'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/nu_est'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/nu_est'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/nu_est'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/SP'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/SP'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/SP'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/SP'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/SP'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/SP'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/tau_des'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/tau_des'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/tau_des'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/tau_des'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/tau_des'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/tau_des'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Integrator1'
                                        */

  /*  Expression: 2*lambda*w_o
   * Referenced by: '<S21>/Gain1'
   */
  { 11.66880456602132, 0.0, 0.0, 0.0, 11.66880456602132, 0.0, 0.0, 0.0,
    11.66880456602132 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Integrator2'
                                        */

  /*  Expression: w_o*w_o
   * Referenced by: '<S21>/Gain2'
   */
  { 34.04025, 0.0, 0.0, 0.0, 34.04025, 0.0, 0.0, 0.0, 34.04025 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Integrator3'
                                        */

  /*  Expression: inv(M)
   * Referenced by: '<S21>/Gain3'
   */
  { 0.00762139060459131, 0.0, 0.0, 0.0, 0.0063848449569688459,
    -5.0835267442179944E-5, -0.0, -9.9224975923314381E-5, 0.013445731502513774 },

  /*  Expression: -2*(eye(3)-lambda)*diag([w_c(1,1)/w_o(1,1) w_c(2,2)/w_o(2,2) w_c(3,3)/w_o(3,3)])
   * Referenced by: '<S21>/K11'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: 2*w_o*(eye(3)-lambda)
   * Referenced by: '<S21>/K12'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: diag([1/T_b(1,1) 1/T_b(2,2) 1/T_b(3,3)])
   * Referenced by: '<S21>/inv(T_b)'
   */
  { 0.094868329805051388, 0.0, 0.0, 0.0, 0.094868329805051388, 0.0, 0.0, 0.0,
    0.094868329805051388 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/controller'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/controller'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/controller'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/controller'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/controller'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/controller'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/timer'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/timer'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/timer'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/timer'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/timer'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/timer'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S22>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Integrator'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S23>/Constant1'
                                        */

  /*  Expression: diag([1/(1/sqrt(90)) 1/(1/sqrt(90))])
   * Referenced by: '<S23>/Gain'
   */
  { 9.4868329805051381, 0.0, 0.0, 9.4868329805051381 },

  /*  Expression: diag([1/(1/sqrt(90)) 1/(1/sqrt(90))])
   * Referenced by: '<S23>/Gain1'
   */
  { 9.4868329805051381, 0.0, 0.0, 9.4868329805051381 },
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S3>/deg2rad'
                                        */
  1U                                   /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S22>/Delay'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_student
 * Model version : 1.150
 * VeriStand Model Framework version : 2015.1.0.76 (2015 SP1)
 * Source generated on : Thu Feb 02 14:51:44 2017
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_student_T_sizes[] DataSection(".NIVS.defaultparamsizes")
  = {
  { sizeof(P_ctrl_student_T), 1 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

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

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 6, 0 },

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

  { sizeof(real_T), 6, 0 },

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

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(uint32_T), 1, 7 },
};

#endif
