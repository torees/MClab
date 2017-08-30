#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
#define u2pwm_P                        u2pwm_P DataSection(".NIVS.defaultparams")
#endif

/*
 * u2pwm_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "u2pwm".
 *
 * Model version              : 1.18
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Mon Aug 21 16:04:15 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "u2pwm.h"
#include "u2pwm_private.h"

/* Block parameters (auto storage) */
P_u2pwm_T u2pwm_P = {
  1.5,                                 /* Variable: Max_thrust
                                        * Referenced by:
                                        *   '<S12>/Saturation 1'
                                        *   '<S12>/Saturation 10'
                                        *   '<S12>/Saturation 12'
                                        *   '<S12>/Saturation 3'
                                        *   '<S12>/Saturation 5'
                                        *   '<S12>/Saturation 8'
                                        */
  -0.8,                                /* Variable: Min_thrust
                                        * Referenced by:
                                        *   '<S12>/Saturation 11'
                                        *   '<S12>/Saturation 13'
                                        *   '<S12>/Saturation 2'
                                        *   '<S12>/Saturation 4'
                                        *   '<S12>/Saturation 6'
                                        *   '<S12>/Saturation 9'
                                        */

  /*  Variable: pwm_thr1_backward
   * Referenced by: '<S12>/negative thrust 1'
   */
  { 23.858914520951675, 45.487296349541758, 32.584102171246734,
    11.321799189832443, 2.6257008718619148, 0.0 },

  /*  Variable: pwm_thr1_forward
   * Referenced by: '<S12>/positive thrust 1'
   */
  { 1.0437188757069087, -4.10008469444801, 5.9676587487121653,
    -4.0556175414295863, 1.6981486523891973, 0.0 },

  /*  Variable: pwm_thr2_backward
   * Referenced by: '<S12>/negative thrust 2'
   */
  { 29.28190056232728, 48.6796996344427, 30.964450957766427, 9.8961003665057685,
    2.3538417726621028, 0.0 },

  /*  Variable: pwm_thr2_forward
   * Referenced by: '<S12>/positive thrust 2'
   */
  { 1.890960989689388, -7.26721394653808, 10.26706684230728, -6.5866315093490115,
    2.2382976000126908, 0.0 },

  /*  Variable: pwm_thr3_backward
   * Referenced by: '<S12>/negative thrust 3'
   */
  { 5.2933350764377467, 14.470101945380295, 14.4505772814463, 6.6893449552111992,
    1.9982315262022992, 0.0 },

  /*  Variable: pwm_thr3_forward
   * Referenced by: '<S12>/positive thrust 3'
   */
  { 0.59698789481905279, -2.6647929382815767, 4.3639359174399379,
    -3.2359585036650267, 1.4134488071785341, 0.0 },

  /*  Variable: pwm_thr4_backward
   * Referenced by: '<S12>/negative thrust 4'
   */
  { 10.188960322383711, 21.543797347285327, 17.5946608663671, 6.9960214191312735,
    1.9833768869949366, 0.0 },

  /*  Variable: pwm_thr4_forward
   * Referenced by: '<S12>/positive thrust 4'
   */
  { 0.59250110337560435, -2.6682793167830323, 4.3839656064579033,
    -3.280925565471656, 1.4315636484406693, 0.0 },

  /*  Variable: pwm_thr5_backward
   * Referenced by: '<S12>/negative thrust 5'
   */
  { -4.5659540415934572, -3.9398286334753525, 2.0549373573279652,
    3.1267224384042631, 1.6413495574372636, 0.0 },

  /*  Variable: pwm_thr5_forward
   * Referenced by: '<S12>/positive thrust 5'
   */
  { 0.38422544884586179, -1.8313184733173447, 3.1790261931696282,
    -2.5146416771703, 1.2272252829155301, 0.0 },

  /*  Variable: pwm_thr6_backward
   * Referenced by: '<S12>/negative thrust 6'
   */
  { -4.0408837176575458, -4.2759218204694731, 0.72627126782596219,
    2.4673330414921106, 1.5907799268739142, 0.0 },

  /*  Variable: pwm_thr6_forward
   * Referenced by: '<S12>/positive thrust 6'
   */
  { 0.34170819920782325, -1.6507668316464681, 2.9570827674984934,
    -2.4532796938007815, 1.2290292377141927, 0.0 },
  -149.0,                              /* Variable: zero_alpha_1
                                        * Referenced by: '<S6>/alpha_Offset'
                                        */
  -40.0,                               /* Variable: zero_alpha_2
                                        * Referenced by: '<S6>/alpha_Offset1'
                                        */
  5.0,                                 /* Variable: zero_alpha_3
                                        * Referenced by: '<S6>/alpha_Offset2'
                                        */
  -17.0,                               /* Variable: zero_alpha_4
                                        * Referenced by: '<S6>/alpha_Offset3'
                                        */
  127.0,                               /* Variable: zero_alpha_5
                                        * Referenced by: '<S6>/alpha_Offset4'
                                        */
  -36.0,                               /* Variable: zero_alpha_6
                                        * Referenced by: '<S6>/alpha_Offset5'
                                        */
  7.5,                                 /* Variable: zero_pwm
                                        * Referenced by:
                                        *   '<S14>/PWM_Offset'
                                        *   '<S14>/PWM_Offset1'
                                        *   '<S14>/PWM_Offset2'
                                        *   '<S14>/PWM_Offset3'
                                        *   '<S14>/PWM_Offset4'
                                        *   '<S14>/PWM_Offset5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Triangle1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Triangle1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Triangle1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Triangle1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Triangle1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Triangle1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Circle1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Circle1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Circle1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Circle1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Circle1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Circle1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Cross1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Cross1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Cross1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Cross1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Cross1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Cross1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/Square1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/Square1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/Square1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/Square1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/Square1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/Square1'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S4>/Memory'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_6'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_4'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/u_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/u_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_3'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_4'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_5'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S9>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S9>/alpha_6'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S9>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S9>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S9>/alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S9>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_6'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_4'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/u_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/u_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_3'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_4'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_5'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S8>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S8>/alpha_6'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S8>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S8>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S8>/alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S8>/alpha_6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Constant11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_6'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_1'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_4'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/u_5'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/u_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_2'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_3'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_4'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_5'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S10>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S10>/alpha_6'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S10>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S10>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S10>/alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S10>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/control input u exceeds bounds'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/mech elec enable'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S30>/man_alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S30>/man_alpha_5'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S30>/man_alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S30>/man_alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S30>/man_alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S30>/man_alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S30>/man_alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S30>/man_alpha_4'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S30>/man_alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S30>/man_alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S30>/man_alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S30>/man_alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S30>/man_alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S30>/man_alpha_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S30>/man_alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S30>/man_alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S30>/man_alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S30>/man_alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S30>/man_alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S30>/man_alpha_2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S30>/man_alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S30>/man_alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S30>/man_alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S30>/man_alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S30>/man_alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S30>/man_alpha_3'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S30>/man_alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S30>/man_alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S30>/man_alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S30>/man_alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S30>/man_alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S30>/man_alpha_6'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S30>/man_alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S30>/man_alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S30>/man_alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S30>/man_alpha_6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Integrator11'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/Need unwrapping thrusters'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/Need unwrapping thrusters'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/Need unwrapping thrusters'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/Need unwrapping thrusters'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/Need unwrapping thrusters'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/Need unwrapping thrusters'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S6>/manual override alpha'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S6>/manual override alpha'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S6>/manual override alpha'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S6>/manual override alpha'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S6>/manual override alpha'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S6>/manual override alpha'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_6'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S5>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S5>/alpha_5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S5>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S5>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S5>/alpha_5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S5>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/STOP'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/STOP'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/STOP'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/STOP'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/STOP'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/STOP'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/ctrl_DP'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/ctrl_DP'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/ctrl_DP'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/ctrl_DP'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/ctrl_DP'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/ctrl_DP'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/ctrl_sixaxis2thruster'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/ctrl_sixaxis2thruster'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/ctrl_sixaxis2thruster'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/ctrl_sixaxis2thruster'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/ctrl_sixaxis2thruster'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/ctrl_sixaxis2thruster'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S13>/ctrl_custom'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S13>/ctrl_custom'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S13>/ctrl_custom'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S13>/ctrl_custom'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S13>/ctrl_custom'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S13>/ctrl_custom'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/out_centered'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/out_centered'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/out_centered'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/out_centered'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/out_centered'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/out_centered'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S44>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S44>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S44>/pwm_u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S44>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S44>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S44>/pwm_u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S44>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S44>/pwm_u_4'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S44>/pwm_u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S44>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S44>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S44>/pwm_u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S44>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S44>/pwm_u_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S44>/pwm_u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S44>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S44>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S44>/pwm_u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S44>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S44>/pwm_u_6'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S44>/pwm_u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S44>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S44>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S44>/pwm_u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S44>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S44>/pwm_u_2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S44>/pwm_u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S44>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S44>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S44>/pwm_u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S44>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S44>/pwm_u_3'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S44>/pwm_u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S44>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S44>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S44>/pwm_u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/manual override pwm'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/manual override pwm'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/manual override pwm'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/manual override pwm'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/manual override pwm'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/manual override pwm'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation 1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation 2'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S14>/Saturation11'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S14>/Saturation11'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation 8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation 9'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S14>/Saturation10'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S14>/Saturation10'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S14>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation 10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation 11'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S14>/Saturation9'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S14>/Saturation9'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation 3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation 4'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S14>/Saturation8'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S14>/Saturation8'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation 5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation 6'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S14>/Saturation7'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S14>/Saturation7'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S14>/Gain4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation 12'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Saturation 13'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S14>/Saturation6'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S14>/Saturation6'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S14>/Gain5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/pwm_u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/pwm_u_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/pwm_u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/pwm_u_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/pwm_u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/pwm_u_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/pwm_u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/pwm_u_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/pwm_u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/pwm_u_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/pwm_u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/pwm_u_6'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/pwm_u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/pwm_u_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/pwm_u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/pwm_u_4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/pwm_u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/pwm_u_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/pwm_u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/pwm_u_5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/pwm_u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/pwm_u_5'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<S15>/pwm_u_5'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : u2pwm
 * Model version : 1.18
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Mon Aug 21 16:04:14 2017
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_u2pwm_T_sizes[] DataSection(".NIVS.defaultparamsizes") = {
  { sizeof(P_u2pwm_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 6, 0 },

  { sizeof(real_T), 6, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
