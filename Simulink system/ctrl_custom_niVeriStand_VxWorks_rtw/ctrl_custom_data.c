#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
#define ctrl_custom_P                  ctrl_custom_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_custom_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_custom".
 *
 * Model version              : 1.83
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Fri Sep 01 13:39:08 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_custom.h"
#include "ctrl_custom_private.h"

/* Block parameters (auto storage) */
P_ctrl_custom_T ctrl_custom_P = {
  /*  Variable: T_pinv
   * Referenced by: '<S8>/Gain'
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
                                        * Referenced by: '<Root>/Input to model'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Input to model'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Input to model'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Input to model'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Input to model'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Input to model'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Output to Workspace'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/x_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/x_ref'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/x_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/x_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/x_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/x_ref'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/y_ref'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/y_ref'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/y_ref'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/y_ref'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/y_ref'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/y_ref'
                                        */

  /*  Expression: [0 0 0 0 0 0]'
   * Referenced by: '<S6>/Memory4'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/k_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/k_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/k_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/k_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/k_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/k_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/psi_ref [deg]'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/deg2rad'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/x_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/x_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/x_m'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S9>/mm2m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/y_m'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/y_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/y_m'
                                        */
  0.001,                               /* Expression: 1/1000
                                        * Referenced by: '<S9>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/psi_m'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/psi_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/psi_m'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S9>/deg2rad'
                                        */
  1.0E+10,                             /* Expression: 1e10
                                        * Referenced by: '<S9>/Saturation'
                                        */
  -1.0E+10,                            /* Expression: -1e10
                                        * Referenced by: '<S9>/Saturation'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S9>/Gain6'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S9>/Constant1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/x_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/x_tilde'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/x_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/x_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/x_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/x_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/k_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/k_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/k_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/k_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/k_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/k_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/y_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/y_tilde'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/y_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/y_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/y_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/y_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/k_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/k_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/k_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/k_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/k_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/k_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/psi_tilde'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/psi_tilde'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/psi_tilde'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/psi_tilde'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/psi_tilde'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/psi_tilde'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/sigma_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/sigma_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/sigma_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/sigma_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/sigma_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/sigma_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/mu_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/mu_x'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/mu_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/mu_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/mu_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/mu_x'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/sigma_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/sigma_x'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/sigma_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/sigma_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/sigma_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/sigma_x'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/X'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/X'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/X'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/X'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/X'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/X'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/mu_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/mu_y'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/mu_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/mu_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/mu_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/mu_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/kappa_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/kappa_y'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/kappa_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/kappa_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/kappa_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/kappa_y'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/sigma_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/sigma_y'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/sigma_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/sigma_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/sigma_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/sigma_y'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Y'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Y'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/mu_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/mu_psi'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S1>/mu_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/mu_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/mu_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/mu_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/kappa_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/kappa_psi'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S1>/kappa_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/kappa_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/kappa_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/kappa_psi'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Integrator2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/N'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/N'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/N'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/N'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/N'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/N'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha3'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha6'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u2'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/u2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u3'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/u3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u4'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/u4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u5'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/u5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/u6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/u6'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S5>/u6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/u6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/u6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/u6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/sigma_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/sigma_psi'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/sigma_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/sigma_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/sigma_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/sigma_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/k1_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/k1_psi'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/k1_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/k1_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/k1_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/k1_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/k2_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/k2_psi'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/k2_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/k2_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/k2_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/k2_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/mu_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/mu_psi'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/mu_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/mu_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/mu_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/mu_psi'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/nu_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/nu_psi'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/nu_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/nu_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/nu_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/nu_psi'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S7>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S7>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Integrator2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S7>/alpha_psi'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S7>/alpha_psi'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S7>/alpha_psi'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S7>/alpha_psi'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S7>/alpha_psi'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S7>/alpha_psi'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S7>/Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S7>/Saturation'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Acc_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Acc_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Acc_z'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Gyro_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/Gyro_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
  1.0                                  /* Expression: btype
                                        * Referenced by: '<S3>/Gyro_z'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_custom
 * Model version : 1.83
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Fri Sep 01 13:39:07 2017
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_custom_T_sizes[] DataSection(".NIVS.defaultparamsizes")
  = {
  { sizeof(P_ctrl_custom_T), 1 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
