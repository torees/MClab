#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_DP_basic_P               ctrl_DP_basic_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_DP_basic_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_DP_basic".
 *
 * Model version              : 1.48
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue May 03 13:33:01 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_DP_basic.h"
#include "ctrl_DP_basic_private.h"

/* Block parameters (auto storage) */
P_ctrl_DP_basic_T ctrl_DP_basic_P = {
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_p_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_p_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_p_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_i_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_i_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_i_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S22>/K_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi'
                                        */
  3.0,                                 /* Expression: portnum
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
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S14>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S14>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S14>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S14>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/reset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant6'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant7'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant8'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/w_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/w_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/w_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/zeta_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/zeta_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S23>/zeta_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/psi_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/x_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/x_ref'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/x_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/x_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/x_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/x_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/y_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/y_ref'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/y_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/y_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/y_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/y_ref'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S16>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S16>/Constant'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S13>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S13>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S13>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S13>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Integrator'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S6>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Integrator3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_3'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/thr_angle_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/thr_angle_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/thr_angle_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/thr_angle_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_4'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/thr_angle_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/thr_angle_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/thr_angle_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/thr_angle_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/thr_angle_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/thr_angle_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/thr_angle_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/thr_angle_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_6'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/thr_angle_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/thr_angle_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/thr_angle_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/thr_angle_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/thr_angle_1'
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
                                        * Referenced by: '<Root>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_2'
                                        */
  2.0,                                 /* Expression: portnum
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
  3.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_4'
                                        */
  4.0,                                 /* Expression: portnum
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
  5.0,                                 /* Expression: portnum
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
  6.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  7.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_2'
                                        */
  8.0,                                 /* Expression: portnum
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
  9.0,                                 /* Expression: portnum
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
  10.0,                                /* Expression: portnum
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
  11.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S41>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S41>/x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S41>/x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S41>/x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S41>/x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S41>/x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S41>/y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S41>/y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S41>/y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S41>/y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S41>/y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S41>/y_hat'
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S41>/psi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S43>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/u_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S43>/v_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/v_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/v_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/v_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/v_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/v_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S43>/r_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/r_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/r_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/r_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/r_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/r_hat'
                                        */
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

  /*  Expression: [0 0 0]'
   * Referenced by: '<S6>/Integrator2'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0.008021948049864 0 0;0 0.010098125265799 1.104781662647098e-04;0 3.303823257820844e-05 0.020839338676560]
   * Referenced by: '<S6>/M^-1'
   */
  { 0.008021948049864, 0.0, 0.0, 0.0, 0.010098125265799, 3.303823257820844E-5,
    0.0, 0.0001104781662647098, 0.02083933867656 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S42>/u_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S42>/v_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S42>/r_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S40>/b_x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S40>/b_y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S40>/b_psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S40>/b_psi_hat'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Integrator2'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S24>/Constant'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S24>/Constant1'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S24>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S24>/Constant5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/tau_N'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/tau_N'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/tau_N'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/tau_N'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/tau_N'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/tau_N'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/tau_X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/tau_X'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/tau_X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/tau_X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/tau_X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/tau_X'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/tau_Y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/psi_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/x_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/y_tidle'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/r_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/u_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S2>/v_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/x_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/x_d'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/x_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/x_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/x_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/x_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/y_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/y_d'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/y_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/y_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/y_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/y_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/psi_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/psi_d'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/psi_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/psi_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/psi_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/psi_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/r_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/r_d'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/r_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/r_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/r_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/r_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u_d'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u_d'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u_d'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/v_d'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/v_d'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/v_d'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/v_d'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/v_d'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<S4>/v_d'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_DP_basic
 * Model version : 1.48
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Tue May 03 13:33:00 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_DP_basic_T_sizes[] DataSection(
  ".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_DP_basic_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
