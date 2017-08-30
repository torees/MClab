#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
#define ctrl_DP_P                      ctrl_DP_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_DP_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_DP".
 *
 * Model version              : 1.207
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Aug 23 17:03:42 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_DP.h"
#include "ctrl_DP_private.h"

/* Block parameters (auto storage) */
P_ctrl_DP_T ctrl_DP_P = {
  /*  Variable: T_pinv
   * Referenced by: '<S11>/Gain'
   */
  { 0.290140228409367, 0.0049618745516802846, 0.30038732539613983,
    0.0046670240844234939, 0.2915231516072464, 0.004517478324220228,
    0.43494048058922113, -0.00409922642319548, 0.37074227769966916,
    -0.0027253337061956774, 0.430012258763733, -0.0031734037820840681,
    0.0012802139234394129, 0.45458834267977311, -0.011706705864021153,
    0.45545287240157872, 0.013900860449174383, 0.44085876600573215,
    0.0019191301467238182, 0.29899274383846575, 0.025596560222822074,
    0.27962499960008025, -0.026002673611565979, 0.32559793660455272,
    0.0034478934521828728, 0.4429984076372469, -0.031528695131473945,
    0.41667402435721734, 0.0374380287894787, 0.40332251114402784,
    0.0051686332616964082, -0.36598079195798555, 0.0689370821351245,
    -0.24331902782910067, -0.070030833474847509, -0.28332292717420593 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/reset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S40>/Constant6'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S40>/Constant7'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S40>/Constant8'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S38>/K_p_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S38>/K_p_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S38>/K_p_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S38>/K_p_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S38>/K_p_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S38>/K_p_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S38>/K_p_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S38>/K_p_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S38>/K_p_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S38>/K_p_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S38>/K_p_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S38>/K_p_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S38>/K_p_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S38>/K_p_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S38>/K_p_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S38>/K_p_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S38>/K_p_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S38>/K_p_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S38>/K_i_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S38>/K_i_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S38>/K_i_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S38>/K_i_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S38>/K_i_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S38>/K_i_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S38>/K_i_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S38>/K_i_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S38>/K_i_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S38>/K_i_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S38>/K_i_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S38>/K_i_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S38>/K_i_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S38>/K_i_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S38>/K_i_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S38>/K_i_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S38>/K_i_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S38>/K_i_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S38>/K_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S38>/K_d_psi'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S38>/K_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S38>/K_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S38>/K_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S38>/K_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S38>/K_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S38>/K_d_x'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S38>/K_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S38>/K_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S38>/K_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S38>/K_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S38>/K_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S38>/K_d_y'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S38>/K_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S38>/K_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S38>/K_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S38>/K_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S39>/w_d_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S39>/w_d_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S39>/w_d_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S39>/w_d_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S39>/w_d_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S39>/w_d_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S39>/w_d_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S39>/w_d_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S39>/w_d_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S39>/w_d_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S39>/w_d_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S39>/w_d_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S39>/w_d_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S39>/w_d_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S39>/w_d_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S39>/w_d_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S39>/w_d_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S39>/w_d_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S39>/zeta_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S39>/zeta_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S39>/zeta_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S39>/zeta_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S39>/zeta_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S39>/zeta_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S39>/zeta_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S39>/zeta_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S39>/zeta_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S39>/zeta_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S39>/zeta_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S39>/zeta_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S39>/zeta_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S39>/zeta_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S39>/zeta_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S39>/zeta_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S39>/zeta_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S39>/zeta_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/psi_ref [deg]'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/psi_ref [deg]'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/psi_ref [deg]'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/psi_ref [deg]'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/psi_ref [deg]'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/psi_ref [deg]'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/x_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/x_ref'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/x_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/x_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/x_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/x_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/y_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/y_ref'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/y_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/y_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/y_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/y_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/x_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/x_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/x_m'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S15>/mm2m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/y_m'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/y_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/y_m'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S15>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/psi_m'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/psi_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/psi_m'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S15>/deg2rad'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S15>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S15>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S15>/Gain6'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S15>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S35>/x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S35>/x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S35>/x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S35>/x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S35>/x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S35>/x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S35>/y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S35>/y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S35>/y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S35>/y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S35>/y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S35>/y_hat'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S32>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S32>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S32>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S32>/Constant'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S35>/psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S35>/psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S35>/psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S35>/psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S35>/psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S35>/psi_hat'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S4>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/u_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/u_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/u_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/u_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/u_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/u_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/v_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/v_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/v_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/v_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/v_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/v_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/r_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/r_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/r_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/r_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/r_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/r_hat'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S33>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S33>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S33>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S33>/Constant'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<S4>/Integrator2'
   */
  { 0.0, 0.0, 0.0 },
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S19>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S19>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S19>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S19>/Constant'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S22>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S22>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S22>/Gain'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S22>/Constant'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Integrator3'
                                        */

  /*  Expression: [0.008021948049864 0 0;0 0.010098125265799 1.104781662647098e-04;0 3.303823257820844e-05 0.020839338676560]
   * Referenced by: '<S4>/M^-1'
   */
  { 0.008021948049864, 0.0, 0.0, 0.0, 0.010098125265799, 3.303823257820844E-5,
    0.0, 0.0001104781662647098, 0.02083933867656 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S36>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S36>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S36>/u_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S36>/u_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S36>/u_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S36>/u_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S36>/v_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S36>/v_dot_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S36>/v_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S36>/v_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S36>/v_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S36>/v_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S36>/r_dot_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S36>/r_dot_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S36>/r_dot_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S36>/r_dot_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S36>/r_dot_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S36>/r_dot_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S34>/b_x_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S34>/b_x_hat'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S34>/b_x_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S34>/b_x_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S34>/b_x_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S34>/b_x_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S34>/b_y_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S34>/b_y_hat'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S34>/b_y_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S34>/b_y_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S34>/b_y_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S34>/b_y_hat'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S34>/b_psi_hat'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S34>/b_psi_hat'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S34>/b_psi_hat'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S34>/b_psi_hat'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S34>/b_psi_hat'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S34>/b_psi_hat'
                                        */

  /*  Expression: [0 0 0 0 0 0]'
   * Referenced by: '<S8>/Memory4'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha3'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha4'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha5'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha6'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u1'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u3'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/u3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u4'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/u4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u5'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/u5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/u6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/u6'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S7>/u6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/u6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/u6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/u6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S20>/x_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S20>/x_tilde'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S20>/x_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S20>/x_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S20>/x_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S20>/x_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S20>/y_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S20>/y_tilde'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S20>/y_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S20>/y_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S20>/y_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S20>/y_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S20>/psi_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S20>/psi_tilde'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S20>/psi_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S20>/psi_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S20>/psi_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S20>/psi_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/x_ref_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/x_ref_out'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/x_ref_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/x_ref_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/x_ref_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/x_ref_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/y_ref_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/y_ref_out'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/y_ref_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/y_ref_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/y_ref_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/y_ref_out'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/psi_ref_out'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/psi_ref_out'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/psi_ref_out'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/psi_ref_out'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/psi_ref_out'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/psi_ref_out'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Integrator2'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S6>/deg2rad'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S40>/Constant'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S40>/Constant1'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<S40>/Constant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S40>/Constant3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S40>/Constant4'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<S40>/Constant5'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_DP
 * Model version : 1.207
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Wed Aug 23 17:03:41 2017
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_DP_T_sizes[] DataSection(".NIVS.defaultparamsizes") = {
  { sizeof(P_ctrl_DP_T), 1 },

  { sizeof(real_T), 36, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
};

#endif
