#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_TAPM2_P                  ctrl_TAPM2_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_TAPM2_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_TAPM2".
 *
 * Model version              : 1.39
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sun May 15 13:28:12 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_TAPM2.h"
#include "ctrl_TAPM2_private.h"

/* Block parameters (auto storage) */
P_ctrl_TAPM2_T ctrl_TAPM2_P = {
  0.03,                                /* Variable: D
                                        * Referenced by: '<S3>/D'
                                        */
  0.033457124694703737,                /* Variable: I_s
                                        * Referenced by:
                                        *   '<S43>/Finding rotation speed'
                                        *   '<S44>/Inertia compensation'
                                        *   '<S53>/Finding rotation speed'
                                        *   '<S54>/Inertia compensation'
                                        *   '<S63>/Finding rotation speed'
                                        *   '<S64>/Inertia compensation'
                                        *   '<S73>/Finding rotation speed'
                                        *   '<S74>/Inertia compensation'
                                        *   '<S83>/Finding rotation speed'
                                        *   '<S84>/Inertia compensation'
                                        *   '<S93>/Finding rotation speed'
                                        *   '<S94>/Inertia compensation'
                                        */
  0.3,                                 /* Variable: K_omega
                                        * Referenced by:
                                        *   '<S43>/K_omega'
                                        *   '<S44>/Qff_1(nr)'
                                        *   '<S53>/K_omega'
                                        *   '<S54>/Qff_1(nr)'
                                        *   '<S63>/K_omega'
                                        *   '<S64>/Qff_1(nr)'
                                        *   '<S73>/K_omega'
                                        *   '<S74>/Qff_1(nr)'
                                        *   '<S83>/K_omega'
                                        *   '<S84>/Qff_1(nr)'
                                        *   '<S93>/K_omega'
                                        *   '<S94>/Qff_1(nr)'
                                        */
  3.3,                                 /* Variable: Kp
                                        * Referenced by:
                                        *   '<S46>/Ki'
                                        *   '<S46>/Kp'
                                        *   '<S56>/Ki'
                                        *   '<S56>/Kp'
                                        *   '<S66>/Ki'
                                        *   '<S66>/Kp'
                                        *   '<S76>/Ki'
                                        *   '<S76>/Kp'
                                        *   '<S86>/Ki'
                                        *   '<S86>/Kp'
                                        *   '<S96>/Ki'
                                        *   '<S96>/Kp'
                                        */
  0.266,                               /* Variable: Kq
                                        * Referenced by: '<S3>/Kq'
                                        */
  0.266,                               /* Variable: Kqr
                                        * Referenced by: '<S3>/Kqr'
                                        */
  0.445,                               /* Variable: Kt
                                        * Referenced by: '<S3>/Kt'
                                        */
  0.445,                               /* Variable: Ktr
                                        * Referenced by: '<S3>/Ktr'
                                        */
  0.12,                                /* Variable: Max_thrust
                                        * Referenced by:
                                        *   '<S33>/Saturation 1'
                                        *   '<S33>/Saturation 2'
                                        *   '<S33>/Saturation 3'
                                        *   '<S33>/Saturation 4'
                                        *   '<S33>/Saturation 5'
                                        *   '<S33>/Saturation 6'
                                        *   '<S33>/Saturation 7'
                                        */
  0.3,                                 /* Variable: Q_f0
                                        * Referenced by:
                                        *   '<S44>/Qf_0'
                                        *   '<S54>/Qf_0'
                                        *   '<S64>/Qf_0'
                                        *   '<S74>/Qf_0'
                                        *   '<S84>/Qf_0'
                                        *   '<S94>/Qf_0'
                                        */
  1000.0,                              /* Variable: Rho
                                        * Referenced by: '<S3>/Rho'
                                        */
  1.0,                                 /* Variable: Thruster_control
                                        * Referenced by:
                                        *   '<S44>/Switch controller'
                                        *   '<S54>/Switch controller'
                                        *   '<S64>/Switch controller'
                                        *   '<S74>/Switch controller'
                                        *   '<S84>/Switch controller'
                                        *   '<S94>/Switch controller'
                                        */
  1.0E-5,                              /* Variable: eps
                                        * Referenced by: '<S3>/Constant4'
                                        */
  3.0,                                 /* Variable: eps_c
                                        * Referenced by: '<S3>/Constant'
                                        */
  0.5,                                 /* Variable: epsilon
                                        * Referenced by:
                                        *   '<S44>/Qff_0(nr)'
                                        *   '<S54>/Qff_0(nr)'
                                        *   '<S64>/Qff_0(nr)'
                                        *   '<S74>/Qff_0(nr)'
                                        *   '<S84>/Qff_0(nr)'
                                        *   '<S94>/Qff_0(nr)'
                                        */
  1.0,                                 /* Variable: k_cc
                                        * Referenced by: '<S3>/Constant1'
                                        */
  5.0,                                 /* Variable: n_c
                                        * Referenced by: '<S3>/Constant5'
                                        */
  1151.9725762041953,                  /* Variable: n_max
                                        * Referenced by:
                                        *   '<S44>/Qff_0(nr)'
                                        *   '<S54>/Qff_0(nr)'
                                        *   '<S64>/Qff_0(nr)'
                                        *   '<S74>/Qff_0(nr)'
                                        *   '<S84>/Qff_0(nr)'
                                        *   '<S94>/Qff_0(nr)'
                                        */
  0.5,                                 /* Variable: p_cc
                                        * Referenced by: '<S3>/Constant2'
                                        */
  2.0,                                 /* Variable: r_cc
                                        * Referenced by: '<S3>/Constant3'
                                        */

  /*  Variable: thrust_to_pwm_coeff
   * Referenced by:
   *   '<S33>/pwm thruster 1'
   *   '<S33>/pwm thruster 2'
   *   '<S33>/pwm thruster 3'
   *   '<S33>/pwm thruster 4'
   *   '<S33>/pwm thruster 5'
   *   '<S33>/pwm thruster 6'
   */
  { 0.049001709187525007, -0.39510945913232864, 1.1559741339627327,
    -1.5170203014582015, 1.214660465174924, 0.0 },

  /*  Mask Parameter: Nonlinearpassiveobserver_D
   * Referenced by: '<S12>/Gain6'
   */
  { 1.0776367786545441E-5, 0.0, 0.0, 0.0, 8.4445579E-5, 1.808866E-6, 0.0,
    1.808866E-6, 2.7368522E-5 },
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S47>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                        * Referenced by: '<S57>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevSca_pl
                                        * Referenced by: '<S67>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_f
                                        * Referenced by: '<S77>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_o
                                        * Referenced by: '<S87>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                        * Referenced by: '<S97>/UD'
                                        */

  /*  Mask Parameter: Nonlinearpassiveobserver_K3
   * Referenced by: '<S12>/K3'
   */
  { 10.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 10.0 },

  /*  Mask Parameter: Nonlinearpassiveobserver_K4
   * Referenced by: '<S12>/K4'
   */
  { 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0 },

  /*  Mask Parameter: Nonlinearpassiveobserver_w_c
   * Referenced by: '<S12>/K2'
   */
  { 1.3, 0.0, 0.0, 0.0, 1.3, 0.0, 0.0, 0.0, 1.3 },

  /*  Expression: [0 0 0 0 0 0 0 0 0 0 0 0]'
   * Referenced by: '<Root>/X-position Thruster1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S34>/Saturation 1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S34>/Saturation 1'
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S43>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S43>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S35>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S53>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S53>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S53>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S53>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S53>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S53>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S53>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S63>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S63>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S63>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S63>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S63>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S63>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S73>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S73>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S73>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S73>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S73>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S73>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S73>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S83>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S83>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S83>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S83>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S83>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S83>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S83>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S39>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S93>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S93>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S93>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S93>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S93>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S93>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S93>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S40>/Losses (placeholder)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S33>/Constant12'
                                        */
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
                                        * Referenced by: '<S34>/Saturation 2'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S34>/Saturation 2'
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
                                        * Referenced by: '<S34>/Saturation 3'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S34>/Saturation 3'
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
                                        * Referenced by: '<S34>/Saturation 4'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S34>/Saturation 4'
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
                                        * Referenced by: '<S34>/Saturation 5'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S34>/Saturation 5'
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
                                        * Referenced by: '<S34>/Saturation 6'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S34>/Saturation 6'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Delay'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S35>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S35>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S35>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S44>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S44>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S44>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S44>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S47>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: AccelerationLimit_RisingLim
                                        * Referenced by: '<S44>/Acceleration Limit'
                                        */
  -0.05,                               /* Computed Parameter: AccelerationLimit_FallingLim
                                        * Referenced by: '<S44>/Acceleration Limit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S44>/Acceleration Limit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S44>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S46>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S46>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S46>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S46>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S46>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S46>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S46>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S44>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S35>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S36>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S36>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S54>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S54>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S54>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S54>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S57>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: AccelerationLimit_RisingLim_n
                                        * Referenced by: '<S54>/Acceleration Limit'
                                        */
  -0.05,                               /* Computed Parameter: AccelerationLimit_FallingLim_n
                                        * Referenced by: '<S54>/Acceleration Limit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S54>/Acceleration Limit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S54>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S56>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S56>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S56>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S56>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S56>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S56>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S56>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S54>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S37>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S37>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S64>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S64>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S64>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S64>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S67>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim
                                        * Referenced by: '<S64>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLim
                                        * Referenced by: '<S64>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S64>/Acceleration limiter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S64>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S66>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S66>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S66>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S66>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S66>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S66>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S66>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S64>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S38>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S38>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S74>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S74>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S74>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S74>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S77>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim_e
                                        * Referenced by: '<S74>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLi_b
                                        * Referenced by: '<S74>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S74>/Acceleration limiter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S74>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S76>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S76>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S76>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S76>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S76>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S76>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S76>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S74>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S39>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S39>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S39>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S84>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S84>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S84>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S84>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_o
                                        * Referenced by: '<S87>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim_b
                                        * Referenced by: '<S84>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLi_d
                                        * Referenced by: '<S84>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S84>/Acceleration limiter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S84>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S86>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S86>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S86>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S86>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S86>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S86>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S86>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S84>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S39>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S40>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S40>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S40>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S94>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S94>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S94>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S94>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_kk
                                        * Referenced by: '<S97>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLi_bi
                                        * Referenced by: '<S94>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLi_p
                                        * Referenced by: '<S94>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S94>/Acceleration limiter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S94>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S96>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S96>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S96>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S96>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S96>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S96>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S96>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S94>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S40>/Discrete Transfer Fcn'
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

  /*  Expression: [0,0,0]'
   * Referenced by: '<S12>/Integrator'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/eta_est'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/eta_est'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/eta_est'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/eta_est'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/eta_est'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/eta_est'
                                        */

  /*  Expression: [0,0,0]'
   * Referenced by: '<S12>/Integrator4'
   */
  { 0.0, 0.0, 0.0 },
  3.0,                                 /* Expression: width
                                        * Referenced by: '<S6>/nu_est'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/nu_est'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/nu_est'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/nu_est'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/nu_est'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/nu_est'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<S13>/Integrator'
   */
  { 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/wave_dir'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/wave_dir'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/wave_dir'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/wave_dir'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/wave_dir'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/wave_dir'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/fzp_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/fzp_x'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/fzp_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/fzp_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/fzp_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/fzp_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/fzp_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/fzp_y'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/fzp_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/fzp_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/fzp_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/fzp_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/r_max'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/r_max'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/r_max'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/r_max'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/r_max'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/r_max'
                                        */
  -2.0,                                /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S13>/Transfer Fcn2'
                                        */
  2.0,                                 /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S13>/Transfer Fcn2'
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
                                        * Referenced by: '<S6>/SP'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/SP'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/SP'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/SP'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/SP'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/SP'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Integrator1'
                                        */

  /*  Expression: 2*lambda*w_o
   * Referenced by: '<S12>/Gain1'
   */
  { 11.66880456602132, 0.0, 0.0, 0.0, 11.66880456602132, 0.0, 0.0, 0.0,
    11.66880456602132 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Integrator2'
                                        */

  /*  Expression: w_o*w_o
   * Referenced by: '<S12>/Gain2'
   */
  { 34.04025, 0.0, 0.0, 0.0, 34.04025, 0.0, 0.0, 0.0, 34.04025 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Integrator3'
                                        */

  /*  Expression: inv(M)
   * Referenced by: '<S12>/Gain3'
   */
  { 0.00762139060459131, 0.0, 0.0, 0.0, 0.0063848449569688459,
    -5.0835267442179944E-5, -0.0, -9.9224975923314381E-5, 0.013445731502513774 },

  /*  Expression: -2*(eye(3)-lambda)*diag([w_c(1,1)/w_o(1,1) w_c(2,2)/w_o(2,2) w_c(3,3)/w_o(3,3)])
   * Referenced by: '<S12>/K11'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: 2*w_o*(eye(3)-lambda)
   * Referenced by: '<S12>/K12'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: diag([1/T_b(1,1) 1/T_b(2,2) 1/T_b(3,3)])
   * Referenced by: '<S12>/inv(T_b)'
   */
  { 0.094868329805051388, 0.0, 0.0, 0.0, 0.094868329805051388, 0.0, 0.0, 0.0,
    0.094868329805051388 },
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S13>/Constant1'
                                        */

  /*  Expression: diag([1/(1/sqrt(90)) 1/(1/sqrt(90))])
   * Referenced by: '<S13>/Gain'
   */
  { 9.4868329805051381, 0.0, 0.0, 9.4868329805051381 },

  /*  Expression: diag([1/(1/sqrt(90)) 1/(1/sqrt(90))])
   * Referenced by: '<S13>/Gain1'
   */
  { 9.4868329805051381, 0.0, 0.0, 9.4868329805051381 },
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S1>/deg2rad'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S6>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [1 1 0]'
   * Referenced by: '<S6>/Gain'
   */
  { 1.0, 1.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/tau_des'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/tau_des'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/tau_des'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/tau_des'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/tau_des'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/tau_des'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/thr_angle_2'
                                        */
  2.0,                                 /* Expression: portnum
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
  3.0,                                 /* Expression: portnum
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
  4.0,                                 /* Expression: portnum
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
  5.0,                                 /* Expression: portnum
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
  6.0,                                 /* Expression: portnum
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
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S8>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S35>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_f
                                        * Referenced by: '<S44>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S36>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_p
                                        * Referenced by: '<S54>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_h
                                        * Referenced by: '<S37>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_b
                                        * Referenced by: '<S64>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_n
                                        * Referenced by: '<S38>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_mj
                                        * Referenced by: '<S74>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S39>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S84>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S40>/Delay'
                                        */
  1U                                   /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S94>/Delay'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_TAPM2
 * Model version : 1.39
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Sun May 15 13:28:12 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_TAPM2_T_sizes[] DataSection(".NIVS.defaultparamsizes") =
{
  { sizeof(P_ctrl_TAPM2_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 12, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 2, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 3, 0 },

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

  { sizeof(uint32_T), 1, 7 },

  { sizeof(uint32_T), 1, 7 },

  { sizeof(uint32_T), 1, 7 },

  { sizeof(uint32_T), 1, 7 },

  { sizeof(uint32_T), 1, 7 },

  { sizeof(uint32_T), 1, 7 },

  { sizeof(uint32_T), 1, 7 },

  { sizeof(uint32_T), 1, 7 },

  { sizeof(uint32_T), 1, 7 },

  { sizeof(uint32_T), 1, 7 },

  { sizeof(uint32_T), 1, 7 },

  { sizeof(uint32_T), 1, 7 },

  { sizeof(uint32_T), 1, 7 },
};

#endif
