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
 * Model version              : 1.63
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue May 10 14:07:11 2016
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
  /*  Variable: C
   * Referenced by: '<S9>/C'
   */
  { 49.7, 99.3, -99.3, -52.7, -98.0, 98.0, 29.4, 80.7, -80.7, -34.7, -82.0, 82.0,
    -49.7, 150.6, -150.6, 52.7, -52.7, 52.7, -29.4, 130.3, -130.3, 34.7, -34.7,
    34.7 },
  0.041111111111111112,                /* Variable: D
                                        * Referenced by: '<S8>/D'
                                        */
  0.033457124694703737,                /* Variable: I_s
                                        * Referenced by:
                                        *   '<S62>/Finding rotation speed'
                                        *   '<S63>/Inertia compensation'
                                        *   '<S72>/Finding rotation speed'
                                        *   '<S73>/Inertia compensation'
                                        *   '<S82>/Finding rotation speed'
                                        *   '<S83>/Inertia compensation'
                                        *   '<S92>/Finding rotation speed'
                                        *   '<S93>/Inertia compensation'
                                        *   '<S102>/Finding rotation speed'
                                        *   '<S103>/Inertia compensation'
                                        *   '<S112>/Finding rotation speed'
                                        *   '<S113>/Inertia compensation'
                                        */
  0.3,                                 /* Variable: K_omega
                                        * Referenced by:
                                        *   '<S62>/K_omega'
                                        *   '<S63>/Qff_1(nr)'
                                        *   '<S72>/K_omega'
                                        *   '<S73>/Qff_1(nr)'
                                        *   '<S82>/K_omega'
                                        *   '<S83>/Qff_1(nr)'
                                        *   '<S92>/K_omega'
                                        *   '<S93>/Qff_1(nr)'
                                        *   '<S102>/K_omega'
                                        *   '<S103>/Qff_1(nr)'
                                        *   '<S112>/K_omega'
                                        *   '<S113>/Qff_1(nr)'
                                        */
  3.3,                                 /* Variable: Kp
                                        * Referenced by:
                                        *   '<S65>/Ki'
                                        *   '<S65>/Kp'
                                        *   '<S75>/Ki'
                                        *   '<S75>/Kp'
                                        *   '<S85>/Ki'
                                        *   '<S85>/Kp'
                                        *   '<S95>/Ki'
                                        *   '<S95>/Kp'
                                        *   '<S105>/Ki'
                                        *   '<S105>/Kp'
                                        *   '<S115>/Ki'
                                        *   '<S115>/Kp'
                                        */
  0.266,                               /* Variable: Kq
                                        * Referenced by: '<S8>/Kq'
                                        */
  0.266,                               /* Variable: Kqr
                                        * Referenced by: '<S8>/Kqr'
                                        */
  0.445,                               /* Variable: Kt
                                        * Referenced by: '<S8>/Kt'
                                        */
  0.445,                               /* Variable: Ktr
                                        * Referenced by: '<S8>/Ktr'
                                        */
  18.973665961010276,                  /* Variable: Max_rotation
                                        * Referenced by: '<S46>/Max Rotation Rate'
                                        */
  0.12,                                /* Variable: Max_thrust
                                        * Referenced by:
                                        *   '<S52>/Saturation 1'
                                        *   '<S52>/Saturation 2'
                                        *   '<S52>/Saturation 3'
                                        *   '<S52>/Saturation 4'
                                        *   '<S52>/Saturation 5'
                                        *   '<S52>/Saturation 6'
                                        *   '<S52>/Saturation 7'
                                        */
  360052.01473385707,                  /* Variable: P_max
                                        * Referenced by:
                                        *   '<S63>/P_max'
                                        *   '<S73>/P_max'
                                        *   '<S83>/P_max'
                                        *   '<S93>/P_max'
                                        *   '<S103>/P_max'
                                        *   '<S113>/P_max'
                                        */
  0.3,                                 /* Variable: Q_f0
                                        * Referenced by:
                                        *   '<S63>/Qf_0'
                                        *   '<S73>/Qf_0'
                                        *   '<S83>/Qf_0'
                                        *   '<S93>/Qf_0'
                                        *   '<S103>/Qf_0'
                                        *   '<S113>/Qf_0'
                                        */
  49.74429001071266,                   /* Variable: Q_max
                                        * Referenced by:
                                        *   '<S63>/Q_max'
                                        *   '<S73>/Q_max'
                                        *   '<S83>/Q_max'
                                        *   '<S93>/Q_max'
                                        *   '<S103>/Q_max'
                                        *   '<S113>/Q_max'
                                        *   '<S65>/Discrete-Time Integrator'
                                        */
  1000.0,                              /* Variable: Rho
                                        * Referenced by: '<S8>/Rho'
                                        */
  1.0,                                 /* Variable: Thruster_control
                                        * Referenced by:
                                        *   '<S63>/Switch controller'
                                        *   '<S73>/Switch controller'
                                        *   '<S83>/Switch controller'
                                        *   '<S93>/Switch controller'
                                        *   '<S103>/Switch controller'
                                        *   '<S113>/Switch controller'
                                        */
  1.0,                                 /* Variable: Thruster_lock
                                        * Referenced by: '<S9>/Switch  Azimuth//Fixed angles'
                                        */
  1.0E-5,                              /* Variable: eps
                                        * Referenced by:
                                        *   '<S8>/Constant4'
                                        *   '<S9>/Constant to avoid singularities'
                                        */
  3.0,                                 /* Variable: eps_c
                                        * Referenced by: '<S8>/Constant'
                                        */
  0.5,                                 /* Variable: epsilon
                                        * Referenced by:
                                        *   '<S63>/Qff_0(nr)'
                                        *   '<S73>/Qff_0(nr)'
                                        *   '<S83>/Qff_0(nr)'
                                        *   '<S93>/Qff_0(nr)'
                                        *   '<S103>/Qff_0(nr)'
                                        *   '<S113>/Qff_0(nr)'
                                        */
  1.0,                                 /* Variable: k_cc
                                        * Referenced by: '<S8>/Constant1'
                                        */
  5.0,                                 /* Variable: n_c
                                        * Referenced by: '<S8>/Constant5'
                                        */
  1151.9725762041953,                  /* Variable: n_max
                                        * Referenced by:
                                        *   '<S63>/Qff_0(nr)'
                                        *   '<S73>/Qff_0(nr)'
                                        *   '<S83>/Qff_0(nr)'
                                        *   '<S93>/Qff_0(nr)'
                                        *   '<S103>/Qff_0(nr)'
                                        *   '<S113>/Qff_0(nr)'
                                        */
  0.5,                                 /* Variable: p_cc
                                        * Referenced by: '<S8>/Constant2'
                                        */
  2.0,                                 /* Variable: r_cc
                                        * Referenced by: '<S8>/Constant3'
                                        */

  /*  Variable: thrust_to_pwm_coeff
   * Referenced by:
   *   '<S52>/pwm thruster 1'
   *   '<S52>/pwm thruster 2'
   *   '<S52>/pwm thruster 3'
   *   '<S52>/pwm thruster 4'
   *   '<S52>/pwm thruster 5'
   *   '<S52>/pwm thruster 6'
   */
  { 0.049001709187525007, -0.39510945913232864, 1.1559741339627327,
    -1.5170203014582015, 1.214660465174924, 0.0 },
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S66>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_k
                                        * Referenced by: '<S76>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_l
                                        * Referenced by: '<S86>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                        * Referenced by: '<S96>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_h
                                        * Referenced by: '<S106>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_b
                                        * Referenced by: '<S116>/UD'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S62>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S62>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S62>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S62>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S62>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S62>/reset'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S62>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S62>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S54>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S72>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S72>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S72>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S72>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S72>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S72>/reset'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                        * Referenced by: '<S72>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S72>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S55>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S82>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S82>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S82>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S82>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S82>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S82>/reset'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                                        * Referenced by: '<S82>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S82>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S56>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S92>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S92>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S92>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S92>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S92>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S92>/reset'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                        * Referenced by: '<S92>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S92>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S57>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S102>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S102>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S102>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S102>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S102>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S102>/reset'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                        * Referenced by: '<S102>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S102>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S58>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S112>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S112>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S112>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S112>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S112>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S112>/reset'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                        * Referenced by: '<S112>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S112>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S59>/Losses (placeholder)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S52>/Constant12'
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
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/K_p_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/K_p_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/K_p_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/K_p_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/K_p_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/K_p_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/K_p_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/K_p_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/K_p_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/K_p_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/K_p_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/K_p_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/K_p_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/K_p_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/K_p_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/K_p_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/K_p_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/K_p_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/K_i_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/K_i_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/K_i_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/K_i_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/K_i_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/K_i_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/K_i_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/K_i_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/K_i_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/K_i_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/K_i_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/K_i_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/K_i_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/K_i_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/K_i_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/K_i_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/K_i_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/K_i_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/K_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/K_d_psi'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/K_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/K_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/K_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/K_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/K_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/K_d_x'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/K_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/K_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/K_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/K_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S24>/K_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S24>/K_d_y'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S24>/K_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S24>/K_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S24>/K_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S24>/K_d_y'
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
                                        * Referenced by: '<S26>/Constant6'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S26>/Constant7'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S26>/Constant8'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/w_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/w_d_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/w_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/w_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/w_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/w_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/w_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/w_d_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/w_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/w_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/w_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/w_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/w_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/w_d_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/w_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/w_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/w_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/w_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/zeta_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/zeta_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/zeta_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/zeta_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/zeta_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/zeta_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/zeta_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/zeta_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/zeta_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/zeta_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/zeta_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/zeta_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S25>/zeta_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S25>/zeta_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S25>/zeta_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S25>/zeta_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S25>/zeta_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S25>/zeta_y'
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
                                        * Referenced by: '<S18>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S18>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S18>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S18>/Constant'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S15>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S15>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S15>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S15>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Integrator'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S6>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Integrator3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/thr_angle_2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/thr_angle_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/thr_angle_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/thr_angle_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/thr_angle_3'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/thr_angle_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/thr_angle_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/thr_angle_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/thr_angle_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/thr_angle_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/thr_angle_4'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/thr_angle_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/thr_angle_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/thr_angle_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/thr_angle_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/thr_angle_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/thr_angle_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/thr_angle_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/thr_angle_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/thr_angle_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/thr_angle_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/thr_angle_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/thr_angle_6'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/thr_angle_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/thr_angle_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/thr_angle_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/thr_angle_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/thr_angle_1'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/thr_angle_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/thr_angle_1'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S48>/Gain'
                                        */

  /*  Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
   * Referenced by: '<S9>/X-position Thruster'
   */
  { 1.0677777777777777, 0.93444444444444441, 0.93444444444444441,
    -1.1644444444444444, -0.99111111111111116, -0.99111111111111116 },

  /*  Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
   * Referenced by: '<S9>/Y-position Thruster'
   */
  { 0.0, 0.11, -0.11, 0.0, -0.16555555555555557, 0.16555555555555557 },

  /*  Expression: [Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)]
   * Referenced by: '<S9>/constant angle'
   */
  { 0.0, 45.0, -45.0, 180.0, -135.0, 135.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Choosing Fixed // Azimuth angle'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/reset'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S53>/Saturation 1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S53>/Saturation 1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/alpha_1'
                                        */
  6.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S53>/Saturation 2'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S53>/Saturation 2'
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
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S53>/Saturation 3'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S53>/Saturation 3'
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
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S53>/Saturation 4'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S53>/Saturation 4'
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
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S53>/Saturation 5'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S53>/Saturation 5'
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
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S53>/Saturation 6'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S53>/Saturation 6'
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
                                        * Referenced by: '<Root>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_1'
                                        */
  16.0,                                /* Expression: portnum
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
  17.0,                                /* Expression: portnum
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
                                        * Referenced by: '<S43>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S43>/y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/y_hat'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S40>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S40>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S40>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S40>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S43>/psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S43>/psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S43>/psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S43>/psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S43>/psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S43>/psi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S45>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S45>/u_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S45>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S45>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S45>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S45>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S45>/v_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S45>/v_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S45>/v_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S45>/v_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S45>/v_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S45>/v_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S45>/r_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S45>/r_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S45>/r_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S45>/r_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S45>/r_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S45>/r_hat'
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
                                        * Referenced by: '<S44>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S44>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S44>/u_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S44>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S44>/u_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S44>/u_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S44>/v_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S44>/v_dot_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S44>/v_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S44>/v_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S44>/v_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S44>/v_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S44>/r_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S44>/r_dot_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S44>/r_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S44>/r_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S44>/r_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S44>/r_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S42>/b_x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S42>/b_x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S42>/b_x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S42>/b_x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S42>/b_x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S42>/b_x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S42>/b_y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S42>/b_y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S42>/b_y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S42>/b_y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S42>/b_y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S42>/b_y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S42>/b_psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S42>/b_psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S42>/b_psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S42>/b_psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S42>/b_psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S42>/b_psi_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_3'
                                        */
  18.0,                                /* Expression: portnum
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
  3.0,                                 /* Expression: width
                                        * Referenced by: '<S3>/eta_des'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/eta_des'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/eta_des'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/eta_des'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/eta_des'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/eta_des'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Integrator2'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S26>/Constant'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S26>/Constant1'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S26>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S26>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S26>/Constant4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S26>/Constant5'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S54>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S54>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S54>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S63>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S63>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S66>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: AccelerationLimit_RisingLim
                                        * Referenced by: '<S63>/Acceleration Limit'
                                        */
  -0.05,                               /* Computed Parameter: AccelerationLimit_FallingLim
                                        * Referenced by: '<S63>/Acceleration Limit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/Acceleration Limit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S63>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S65>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S65>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S65>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S65>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S65>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S65>/reset'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                                        * Referenced by: '<S65>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S65>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S54>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S55>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S55>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S55>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S73>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S73>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S73>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S73>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_o
                                        * Referenced by: '<S76>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: AccelerationLimit_RisingLim_n
                                        * Referenced by: '<S73>/Acceleration Limit'
                                        */
  -0.05,                               /* Computed Parameter: AccelerationLimit_FallingLim_j
                                        * Referenced by: '<S73>/Acceleration Limit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S73>/Acceleration Limit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S73>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S75>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S75>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S75>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S75>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S75>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S75>/reset'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainv_fz
                                        * Referenced by: '<S75>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S75>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S73>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S55>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S56>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S56>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S56>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S83>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S83>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S83>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S83>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S86>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim
                                        * Referenced by: '<S83>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLim
                                        * Referenced by: '<S83>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S83>/Acceleration limiter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S83>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S85>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S85>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S85>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S85>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S85>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S85>/reset'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                        * Referenced by: '<S85>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S85>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S83>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S56>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S57>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S57>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S57>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S93>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S93>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S93>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S93>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_mu
                                        * Referenced by: '<S96>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim_c
                                        * Referenced by: '<S93>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLi_o
                                        * Referenced by: '<S93>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S93>/Acceleration limiter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S93>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S95>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S95>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S95>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S95>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S95>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S95>/reset'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainv_ay
                                        * Referenced by: '<S95>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S95>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S93>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S57>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S58>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S58>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S58>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S103>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S103>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S103>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S103>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S106>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim_h
                                        * Referenced by: '<S103>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLi_l
                                        * Referenced by: '<S103>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S103>/Acceleration limiter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S103>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S105>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S105>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S105>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S105>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S105>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S105>/reset'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                                        * Referenced by: '<S105>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S105>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S103>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S58>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S59>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S59>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S59>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S113>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S113>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S113>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S113>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_j
                                        * Referenced by: '<S116>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim_k
                                        * Referenced by: '<S113>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLi_b
                                        * Referenced by: '<S113>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S113>/Acceleration limiter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S113>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S115>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S115>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S115>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S115>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S115>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S115>/reset'
                                        */
  0.01,                                /* Computed Parameter: DiscreteTimeIntegrator_gainv_ll
                                        * Referenced by: '<S115>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S115>/Discrete-Time Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S113>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S59>/Discrete Transfer Fcn'
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
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/v_d'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S54>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S63>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S55>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_b
                                        * Referenced by: '<S73>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S56>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_o
                                        * Referenced by: '<S83>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_ch
                                        * Referenced by: '<S57>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_cq
                                        * Referenced by: '<S93>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S58>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_e
                                        * Referenced by: '<S103>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S59>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_i
                                        * Referenced by: '<S113>/Delay'
                                        */

  /* Start of '<S46>/CoreSubsys' */
  {
    0.01,                              /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S46>/Discrete-Time Integrator'
                                        */
    0.017453292519943295,              /* Expression: pi/180
                                        * Referenced by: '<S49>/Gain1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S46>/Delay'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S46>/Delay'
                                        */
  }
  /* End of '<S46>/CoreSubsys' */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_DP_basic
 * Model version : 1.63
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Tue May 10 14:07:05 2016
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

  { sizeof(real_T), 24, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },
};

#endif
