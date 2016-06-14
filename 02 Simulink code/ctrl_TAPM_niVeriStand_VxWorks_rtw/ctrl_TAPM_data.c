#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_TAPM_P                   ctrl_TAPM_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_TAPM_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_TAPM".
 *
 * Model version              : 1.39
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sun May 15 17:36:42 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_TAPM.h"
#include "ctrl_TAPM_private.h"

/* Block parameters (auto storage) */
P_ctrl_TAPM_T ctrl_TAPM_P = {
  /*  Variable: C
   * Referenced by: '<S7>/C'
   */
  { 48.6, 98.3, -98.3, -144.3, -97.1, 97.1, 30.5, 81.8, -81.8, -128.3, -82.9,
    82.9, -48.6, 149.5, -149.5, 144.3, -51.7, 51.7, -30.5, 131.4, -131.4, 128.3,
    -35.7, 35.7 },
  0.03,                                /* Variable: D
                                        * Referenced by: '<S3>/D'
                                        */
  0.033457124694703737,                /* Variable: I_s
                                        * Referenced by:
                                        *   '<S42>/Finding rotation speed'
                                        *   '<S43>/Inertia compensation'
                                        *   '<S52>/Finding rotation speed'
                                        *   '<S53>/Inertia compensation'
                                        *   '<S62>/Finding rotation speed'
                                        *   '<S63>/Inertia compensation'
                                        *   '<S72>/Finding rotation speed'
                                        *   '<S73>/Inertia compensation'
                                        *   '<S82>/Finding rotation speed'
                                        *   '<S83>/Inertia compensation'
                                        *   '<S92>/Finding rotation speed'
                                        *   '<S93>/Inertia compensation'
                                        */
  0.3,                                 /* Variable: K_omega
                                        * Referenced by:
                                        *   '<S42>/K_omega'
                                        *   '<S43>/Qff_1(nr)'
                                        *   '<S52>/K_omega'
                                        *   '<S53>/Qff_1(nr)'
                                        *   '<S62>/K_omega'
                                        *   '<S63>/Qff_1(nr)'
                                        *   '<S72>/K_omega'
                                        *   '<S73>/Qff_1(nr)'
                                        *   '<S82>/K_omega'
                                        *   '<S83>/Qff_1(nr)'
                                        *   '<S92>/K_omega'
                                        *   '<S93>/Qff_1(nr)'
                                        */
  3.3,                                 /* Variable: Kp
                                        * Referenced by:
                                        *   '<S45>/Ki'
                                        *   '<S45>/Kp'
                                        *   '<S55>/Ki'
                                        *   '<S55>/Kp'
                                        *   '<S65>/Ki'
                                        *   '<S65>/Kp'
                                        *   '<S75>/Ki'
                                        *   '<S75>/Kp'
                                        *   '<S85>/Ki'
                                        *   '<S85>/Kp'
                                        *   '<S95>/Ki'
                                        *   '<S95>/Kp'
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
  47.434164902525694,                  /* Variable: Max_rotation
                                        * Referenced by: '<S25>/Max Rotation Rate'
                                        */
  0.12,                                /* Variable: Max_thrust
                                        * Referenced by:
                                        *   '<S32>/Saturation 1'
                                        *   '<S32>/Saturation 2'
                                        *   '<S32>/Saturation 3'
                                        *   '<S32>/Saturation 4'
                                        *   '<S32>/Saturation 5'
                                        *   '<S32>/Saturation 6'
                                        *   '<S32>/Saturation 7'
                                        */
  0.3,                                 /* Variable: Q_f0
                                        * Referenced by:
                                        *   '<S43>/Qf_0'
                                        *   '<S53>/Qf_0'
                                        *   '<S63>/Qf_0'
                                        *   '<S73>/Qf_0'
                                        *   '<S83>/Qf_0'
                                        *   '<S93>/Qf_0'
                                        */
  1000.0,                              /* Variable: Rho
                                        * Referenced by: '<S3>/Rho'
                                        */
  1.0,                                 /* Variable: Thruster_control
                                        * Referenced by:
                                        *   '<S43>/Switch controller'
                                        *   '<S53>/Switch controller'
                                        *   '<S63>/Switch controller'
                                        *   '<S73>/Switch controller'
                                        *   '<S83>/Switch controller'
                                        *   '<S93>/Switch controller'
                                        */
  1.0,                                 /* Variable: Thruster_lock
                                        * Referenced by: '<S7>/Switch  Azimuth//Fixed angles'
                                        */
  1.0E-5,                              /* Variable: eps
                                        * Referenced by:
                                        *   '<S3>/Constant4'
                                        *   '<S7>/Constant to avoid singularities'
                                        */
  3.0,                                 /* Variable: eps_c
                                        * Referenced by: '<S3>/Constant'
                                        */
  0.5,                                 /* Variable: epsilon
                                        * Referenced by:
                                        *   '<S43>/Qff_0(nr)'
                                        *   '<S53>/Qff_0(nr)'
                                        *   '<S63>/Qff_0(nr)'
                                        *   '<S73>/Qff_0(nr)'
                                        *   '<S83>/Qff_0(nr)'
                                        *   '<S93>/Qff_0(nr)'
                                        */
  1.0,                                 /* Variable: k_cc
                                        * Referenced by: '<S3>/Constant1'
                                        */
  5.0,                                 /* Variable: n_c
                                        * Referenced by: '<S3>/Constant5'
                                        */
  1151.9725762041953,                  /* Variable: n_max
                                        * Referenced by:
                                        *   '<S43>/Qff_0(nr)'
                                        *   '<S53>/Qff_0(nr)'
                                        *   '<S63>/Qff_0(nr)'
                                        *   '<S73>/Qff_0(nr)'
                                        *   '<S83>/Qff_0(nr)'
                                        *   '<S93>/Qff_0(nr)'
                                        */
  0.5,                                 /* Variable: p_cc
                                        * Referenced by: '<S3>/Constant2'
                                        */
  2.0,                                 /* Variable: r_cc
                                        * Referenced by: '<S3>/Constant3'
                                        */

  /*  Variable: thrust_to_pwm_coeff
   * Referenced by:
   *   '<S32>/pwm thruster 1'
   *   '<S32>/pwm thruster 2'
   *   '<S32>/pwm thruster 3'
   *   '<S32>/pwm thruster 4'
   *   '<S32>/pwm thruster 5'
   *   '<S32>/pwm thruster 6'
   */
  { 0.049001709187525007, -0.39510945913232864, 1.1559741339627327,
    -1.5170203014582015, 1.214660465174924, 0.0 },

  /*  Mask Parameter: Nonlinearpassiveobserver_D
   * Referenced by: '<S12>/Gain6'
   */
  { 1.0776367786545441E-5, 0.0, 0.0, 0.0, 8.4445579E-5, 1.808866E-6, 0.0,
    1.808866E-6, 2.7368522E-5 },
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S46>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                        * Referenced by: '<S56>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevSca_pl
                                        * Referenced by: '<S66>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_f
                                        * Referenced by: '<S76>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_o
                                        * Referenced by: '<S86>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                        * Referenced by: '<S96>/UD'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Delay'
                                        */
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

  /*  Expression: [0,0,0]'
   * Referenced by: '<S12>/Integrator'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0,0,0]'
   * Referenced by: '<S12>/Integrator4'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [0 0]
   * Referenced by: '<S13>/Integrator'
   */
  { 0.0, 0.0 },
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Integrator3'
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
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S28>/Gain'
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
   * Referenced by: '<S7>/constant angle'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Choosing Fixed // Azimuth angle'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/reset'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S33>/Saturation 1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S33>/Saturation 1'
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
                                        * Referenced by: '<S42>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S42>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S42>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S42>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S42>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S42>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S42>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S34>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S52>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S52>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S52>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S52>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S52>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S52>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S52>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S35>/Losses (placeholder)'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S62>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/Losses (placeholder)'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S72>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/Losses (placeholder)'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S82>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/Losses (placeholder)'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S92>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S39>/Losses (placeholder)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Constant12'
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
                                        * Referenced by: '<S33>/Saturation 2'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S33>/Saturation 2'
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
                                        * Referenced by: '<S33>/Saturation 3'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S33>/Saturation 3'
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
                                        * Referenced by: '<S33>/Saturation 4'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S33>/Saturation 4'
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
                                        * Referenced by: '<S33>/Saturation 5'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S33>/Saturation 5'
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
                                        * Referenced by: '<S33>/Saturation 6'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S33>/Saturation 6'
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
                                        * Referenced by: '<S11>/controller'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/controller'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/controller'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/controller'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/controller'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/controller'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S11>/timer'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S11>/timer'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S11>/timer'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S11>/timer'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S11>/timer'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S11>/timer'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Delay'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S34>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S34>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S34>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S43>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S43>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S43>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S43>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S46>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: AccelerationLimit_RisingLim
                                        * Referenced by: '<S43>/Acceleration Limit'
                                        */
  -0.05,                               /* Computed Parameter: AccelerationLimit_FallingLim
                                        * Referenced by: '<S43>/Acceleration Limit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S43>/Acceleration Limit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S43>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S45>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S45>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S45>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S45>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S45>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S45>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S45>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S43>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S34>/Discrete Transfer Fcn'
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
                                        * Referenced by: '<S53>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S53>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S53>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S53>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S56>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: AccelerationLimit_RisingLim_n
                                        * Referenced by: '<S53>/Acceleration Limit'
                                        */
  -0.05,                               /* Computed Parameter: AccelerationLimit_FallingLim_n
                                        * Referenced by: '<S53>/Acceleration Limit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S53>/Acceleration Limit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S53>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S55>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S55>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S55>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S55>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S55>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S55>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S55>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S53>/NaN'
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
  100.0,                               /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S66>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim
                                        * Referenced by: '<S63>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLim
                                        * Referenced by: '<S63>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/Acceleration limiter'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S65>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S63>/NaN'
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
  100.0,                               /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S76>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim_e
                                        * Referenced by: '<S73>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLi_b
                                        * Referenced by: '<S73>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S73>/Acceleration limiter'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S75>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S73>/NaN'
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
  100.0,                               /* Computed Parameter: TSamp_WtEt_o
                                        * Referenced by: '<S86>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim_b
                                        * Referenced by: '<S83>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLi_d
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S85>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S83>/NaN'
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
  100.0,                               /* Computed Parameter: TSamp_WtEt_kk
                                        * Referenced by: '<S96>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLi_bi
                                        * Referenced by: '<S93>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLi_p
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S95>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S93>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S39>/Discrete Transfer Fcn'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S11>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S8>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S34>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_f
                                        * Referenced by: '<S43>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_m5
                                        * Referenced by: '<S35>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_p
                                        * Referenced by: '<S53>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_h
                                        * Referenced by: '<S36>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_b
                                        * Referenced by: '<S63>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_n
                                        * Referenced by: '<S37>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_mj
                                        * Referenced by: '<S73>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_a
                                        * Referenced by: '<S38>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S83>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S39>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S93>/Delay'
                                        */

  /* Start of '<S25>/CoreSubsys' */
  {
    0.01,                              /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S25>/Discrete-Time Integrator'
                                        */
    0.017453292519943295,              /* Expression: pi/180
                                        * Referenced by: '<S29>/Gain1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S25>/Delay'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S25>/Delay'
                                        */
  }
  /* End of '<S25>/CoreSubsys' */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_TAPM
 * Model version : 1.39
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Sun May 15 17:36:42 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_TAPM_T_sizes[] DataSection(".NIVS.defaultparamsizes") =
{
  { sizeof(P_ctrl_TAPM_T), 1 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 4, 0 },

  { sizeof(real_T), 4, 0 },

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

  { sizeof(uint32_T), 1, 7 },

  { sizeof(real_T), 1, 0 },
};

#endif
