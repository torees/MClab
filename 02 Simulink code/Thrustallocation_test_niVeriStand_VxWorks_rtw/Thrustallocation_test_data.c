#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define Thrustallocation_test_P       Thrustallocation_test_P DataSection(".NIVS.defaultparams")
#endif

/*
 * Thrustallocation_test_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Thrustallocation_test".
 *
 * Model version              : 1.10
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Jun 17 16:52:41 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Thrustallocation_test.h"
#include "Thrustallocation_test_private.h"

/* Block parameters (auto storage) */
P_Thrustallocation_test_T Thrustallocation_test_P = {
  /*  Variable: C
   * Referenced by:
   *   '<S4>/Constant1'
   *   '<S4>/Constant2'
   */
  { 48.6, 98.3, -98.3, -144.3, -97.1, 97.1, 30.5, 81.8, -81.8, -128.3, -82.9,
    82.9, -48.6, 149.5, -149.5, 144.3, -51.7, 51.7, -30.5, 131.4, -131.4, 128.3,
    -35.7, 35.7 },
  0.03,                                /* Variable: D
                                        * Referenced by: '<S2>/D'
                                        */
  0.033457124694703737,                /* Variable: I_s
                                        * Referenced by:
                                        *   '<S28>/Finding rotation speed'
                                        *   '<S29>/Inertia compensation'
                                        *   '<S37>/Finding rotation speed'
                                        *   '<S38>/Inertia compensation'
                                        *   '<S46>/Finding rotation speed'
                                        *   '<S47>/Inertia compensation'
                                        *   '<S55>/Finding rotation speed'
                                        *   '<S56>/Inertia compensation'
                                        *   '<S64>/Finding rotation speed'
                                        *   '<S65>/Inertia compensation'
                                        *   '<S73>/Finding rotation speed'
                                        *   '<S74>/Inertia compensation'
                                        */
  0.3,                                 /* Variable: K_omega
                                        * Referenced by:
                                        *   '<S28>/K_omega'
                                        *   '<S29>/Qff_1(nr)'
                                        *   '<S37>/K_omega'
                                        *   '<S38>/Qff_1(nr)'
                                        *   '<S46>/K_omega'
                                        *   '<S47>/Qff_1(nr)'
                                        *   '<S55>/K_omega'
                                        *   '<S56>/Qff_1(nr)'
                                        *   '<S64>/K_omega'
                                        *   '<S65>/Qff_1(nr)'
                                        *   '<S73>/K_omega'
                                        *   '<S74>/Qff_1(nr)'
                                        */
  3.3,                                 /* Variable: Kp
                                        * Referenced by:
                                        *   '<S31>/Ki'
                                        *   '<S31>/Kp'
                                        *   '<S40>/Ki'
                                        *   '<S40>/Kp'
                                        *   '<S49>/Ki'
                                        *   '<S49>/Kp'
                                        *   '<S58>/Ki'
                                        *   '<S58>/Kp'
                                        *   '<S67>/Ki'
                                        *   '<S67>/Kp'
                                        *   '<S76>/Ki'
                                        *   '<S76>/Kp'
                                        */
  0.266,                               /* Variable: Kq
                                        * Referenced by: '<S2>/Kq'
                                        */
  0.266,                               /* Variable: Kqr
                                        * Referenced by: '<S2>/Kqr'
                                        */
  0.445,                               /* Variable: Kt
                                        * Referenced by: '<S2>/Kt'
                                        */
  0.445,                               /* Variable: Ktr
                                        * Referenced by: '<S2>/Ktr'
                                        */
  113.84199576606166,                  /* Variable: Max_rotation
                                        * Referenced by: '<S12>/Max Rotation Rate'
                                        */
  1.5,                                 /* Variable: Max_thrust
                                        * Referenced by: '<S19>/Saturation 7'
                                        */
  0.3,                                 /* Variable: Q_f0
                                        * Referenced by:
                                        *   '<S29>/Qf_0'
                                        *   '<S38>/Qf_0'
                                        *   '<S47>/Qf_0'
                                        *   '<S56>/Qf_0'
                                        *   '<S65>/Qf_0'
                                        *   '<S74>/Qf_0'
                                        */
  1000.0,                              /* Variable: Rho
                                        * Referenced by: '<S2>/Rho'
                                        */
  1.0E-5,                              /* Variable: eps
                                        * Referenced by:
                                        *   '<S2>/Constant4'
                                        *   '<S4>/Constant to avoid singularities'
                                        */
  3.0,                                 /* Variable: eps_c
                                        * Referenced by: '<S2>/Constant'
                                        */
  0.5,                                 /* Variable: epsilon
                                        * Referenced by:
                                        *   '<S29>/Qff_0(nr)'
                                        *   '<S38>/Qff_0(nr)'
                                        *   '<S47>/Qff_0(nr)'
                                        *   '<S56>/Qff_0(nr)'
                                        *   '<S65>/Qff_0(nr)'
                                        *   '<S74>/Qff_0(nr)'
                                        */
  1.0,                                 /* Variable: k_cc
                                        * Referenced by: '<S2>/Constant1'
                                        */
  5.0,                                 /* Variable: n_c
                                        * Referenced by: '<S2>/Constant5'
                                        */
  1151.9725762041953,                  /* Variable: n_max
                                        * Referenced by:
                                        *   '<S29>/Qff_0(nr)'
                                        *   '<S38>/Qff_0(nr)'
                                        *   '<S47>/Qff_0(nr)'
                                        *   '<S56>/Qff_0(nr)'
                                        *   '<S65>/Qff_0(nr)'
                                        *   '<S74>/Qff_0(nr)'
                                        */
  0.5,                                 /* Variable: p_cc
                                        * Referenced by: '<S2>/Constant2'
                                        */
  2.0,                                 /* Variable: r_cc
                                        * Referenced by: '<S2>/Constant3'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S32>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                        * Referenced by: '<S41>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_c
                                        * Referenced by: '<S50>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_e
                                        * Referenced by: '<S59>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScal_f
                                        * Referenced by: '<S68>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevSca_es
                                        * Referenced by: '<S77>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S81>/Delay Input1'
                                        */
  0.0,                                 /* Mask Parameter: DetectIncrease1_vinit
                                        * Referenced by: '<S82>/Delay Input1'
                                        */
  0.0,                                 /* Mask Parameter: DetectIncrease2_vinit
                                        * Referenced by: '<S83>/Delay Input1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S28>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S28>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S28>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S28>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S28>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S28>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S28>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S37>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S37>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S37>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S37>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S37>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S37>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Losses (placeholder)'
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
                                        * Referenced by: '<S22>/Losses (placeholder)'
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
                                        * Referenced by: '<S23>/Losses (placeholder)'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S64>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S64>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S64>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S64>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S64>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S64>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S64>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/Losses (placeholder)'
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
                                        * Referenced by: '<S25>/Losses (placeholder)'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Shaft speed thruster 1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Shaft speed thruster 2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Shaft speed thruster 3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Shaft speed thruster 4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Shaft speed thruster 5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Shaft speed thruster 6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/core_controller'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/core_controller'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/core_controller'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/core_controller'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/core_controller'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/core_controller'
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
                                        * Referenced by: '<S9>/Memory'
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
                                        * Referenced by: '<S6>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/thr_angle_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/thr_angle_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/thr_angle_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/thr_angle_2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/thr_angle_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/thr_angle_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/thr_angle_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/thr_angle_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/thr_angle_3'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/thr_angle_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/thr_angle_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/thr_angle_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/thr_angle_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/thr_angle_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/thr_angle_4'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/thr_angle_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/thr_angle_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/thr_angle_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/thr_angle_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/thr_angle_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/thr_angle_5'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/thr_angle_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/thr_angle_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/thr_angle_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/thr_angle_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/thr_angle_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/thr_angle_6'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/thr_angle_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/thr_angle_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/thr_angle_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/thr_angle_6'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain'
                                        */

  /*  Expression: [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)]
   * Referenced by: '<S4>/X-position Thruster1'
   */
  { 1.0677777777777777, 0.93444444444444441, 0.93444444444444441,
    -1.1644444444444444, -0.99111111111111116, -0.99111111111111116 },

  /*  Expression: [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)]
   * Referenced by: '<S4>/Y-position Thruster2'
   */
  { 0.0, 0.11, -0.11, 0.0, -0.16555555555555557, 0.16555555555555557 },
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/PosYLeft'
                                        */
  5.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/R2_continuous'
                                        */
  6.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<S4>/Angle_controller'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Angle_controller'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Angle_controller'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Angle_controller'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Angle_controller'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Angle_controller'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/A1Matrix '
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/A1Matrix '
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/A1Matrix '
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/A1Matrix '
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/A1Matrix '
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/A1Matrix '
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/fmin'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/fmin'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/fmin'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/fmin'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/fmin'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/fmin'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/A2Matrix'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/A2Matrix'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/A2Matrix'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/A2Matrix'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/A2Matrix'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/A2Matrix'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/A3Matrix'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/A3Matrix'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/A3Matrix'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/A3Matrix'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/A3Matrix'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/A3Matrix'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/BMatrix'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/BMatrix'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/BMatrix'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/BMatrix'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/BMatrix'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/BMatrix'
                                        */

  /*  Expression: [Thruster.T1(3) Thruster.T2(3) Thruster.T3(3) Thruster.T4(3) Thruster.T5(3) Thruster.T6(3)]
   * Referenced by: '<S4>/constant angle'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Choosing Fixed // Azimuth angle'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/reset'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/reset'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S18>/Saturation 1'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation 1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S18>/Saturation 2'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation 2'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S18>/Saturation 3'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation 3'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S18>/Saturation 4'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation 4'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S18>/Saturation 5'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation 5'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S18>/Saturation 6'
                                        */
  -3.1415926535897931,                 /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation 6'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S3>/Gain'
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
  1.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/N'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/N'
                                        */
  2.0,                                 /* Expression: portnum
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
                                        * Referenced by: '<Root>/u_limit'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/u_limit'
                                        */
  5.0,                                 /* Expression: portnum
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

  /*  Expression: [0 0 0]'
   * Referenced by: '<Root>/Constant1'
   */
  { 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Delay'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S20>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S20>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S29>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S29>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S29>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S29>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S32>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: AccelerationLimit_RisingLim
                                        * Referenced by: '<S29>/Acceleration Limit'
                                        */
  -0.05,                               /* Computed Parameter: AccelerationLimit_FallingLim
                                        * Referenced by: '<S29>/Acceleration Limit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S29>/Acceleration Limit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S29>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S31>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S31>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S31>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S31>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S31>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S31>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S31>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S29>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S21>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S21>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S38>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S38>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_j
                                        * Referenced by: '<S41>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: AccelerationLimit_RisingLim_b
                                        * Referenced by: '<S38>/Acceleration Limit'
                                        */
  -0.05,                               /* Computed Parameter: AccelerationLimit_FallingLim_f
                                        * Referenced by: '<S38>/Acceleration Limit'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/Acceleration Limit'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S38>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S40>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S40>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S40>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S40>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S40>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S40>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S40>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S22>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S22>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S47>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S47>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S47>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S47>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_l
                                        * Referenced by: '<S50>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim
                                        * Referenced by: '<S47>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLim
                                        * Referenced by: '<S47>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S47>/Acceleration limiter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S47>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S49>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S49>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S49>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S49>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S49>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S49>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S49>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S47>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S22>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S23>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S23>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S56>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S56>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S56>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S56>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_n
                                        * Referenced by: '<S59>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim_n
                                        * Referenced by: '<S56>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLi_o
                                        * Referenced by: '<S56>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S56>/Acceleration limiter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S56>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S58>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S58>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S58>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S58>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S58>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S58>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S58>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S56>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S24>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S24>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S65>/Delay'
                                        */

  /*  Expression: hd.num{1,1}
   * Referenced by: '<S65>/Constant1'
   */
  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  /*  Expression: hd.den{1,1}
   * Referenced by: '<S65>/Constant2'
   */
  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S65>/Discrete Transfer Fcn'
                                        */
  100.0,                               /* Computed Parameter: TSamp_WtEt_m
                                        * Referenced by: '<S68>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLim_j
                                        * Referenced by: '<S65>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLi_i
                                        * Referenced by: '<S65>/Acceleration limiter'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S65>/Acceleration limiter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S65>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S67>/reset'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S67>/reset'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S67>/reset'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S67>/reset'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S67>/reset'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S67>/reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S67>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S65>/NaN'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S24>/Discrete Transfer Fcn'
                                        */

  /*  Expression: hd2.den{1,1}
   * Referenced by: '<S25>/Constant'
   */
  { 1.0, -0.60653065971263342 },

  /*  Expression: hd2.num{1,1}
   * Referenced by: '<S25>/Constant1'
   */
  { 0.0, 0.39346934028736652 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S25>/Delay'
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
  100.0,                               /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S77>/TSamp'
                                        */
  0.05,                                /* Computed Parameter: Accelerationlimiter_RisingLi_nn
                                        * Referenced by: '<S74>/Acceleration limiter'
                                        */
  -0.05,                               /* Computed Parameter: Accelerationlimiter_FallingLi_a
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
                                        * Referenced by: '<S25>/Discrete Transfer Fcn'
                                        */

  /*  Expression: [0 0 0]'
   * Referenced by: '<Root>/Velocity'
   */
  { 0.0, 0.0, 0.0 },
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S5>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_f
                                        * Referenced by: '<S20>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_o
                                        * Referenced by: '<S29>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_k
                                        * Referenced by: '<S21>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_d
                                        * Referenced by: '<S38>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_j
                                        * Referenced by: '<S22>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_n
                                        * Referenced by: '<S47>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_e
                                        * Referenced by: '<S23>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_l
                                        * Referenced by: '<S56>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_m
                                        * Referenced by: '<S24>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_g
                                        * Referenced by: '<S65>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_np
                                        * Referenced by: '<S25>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength_c
                                        * Referenced by: '<S74>/Delay'
                                        */

  /* Start of '<S12>/CoreSubsys' */
  {
    0.01,                              /* Computed Parameter: DiscreteTimeIntegrator_gainval
                                        * Referenced by: '<S12>/Discrete-Time Integrator'
                                        */
    0.017453292519943295,              /* Expression: pi/180
                                        * Referenced by: '<S15>/Gain1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S12>/Delay'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S12>/Delay'
                                        */
  }
  /* End of '<S12>/CoreSubsys' */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : Thrustallocation_test
 * Model version : 1.10
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Fri Jun 17 16:52:41 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_Thrustallocation_test_T_sizes[] DataSection(
  ".NIVS.defaultparamsizes") = {
  { sizeof(P_Thrustallocation_test_T), 1 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 3, 0 },

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
