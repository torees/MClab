#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define u2pwm_alpha_P                 u2pwm_alpha_P DataSection(".NIVS.defaultparams")
#endif

/*
 * u2pwm_alpha_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "u2pwm_alpha".
 *
 * Model version              : 1.103
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu May 05 10:59:25 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "u2pwm_alpha.h"
#include "u2pwm_alpha_private.h"

/* Block parameters (auto storage) */
P_u2pwm_alpha_T u2pwm_alpha_P = {
  -165.0,                              /* Variable: zero_alpha_1
                                        * Referenced by: '<Root>/alpha_Offset'
                                        */
  -154.0,                              /* Variable: zero_alpha_2
                                        * Referenced by: '<Root>/alpha_Offset1'
                                        */
  -147.0,                              /* Variable: zero_alpha_3
                                        * Referenced by: '<Root>/alpha_Offset2'
                                        */
  -8.0,                                /* Variable: zero_alpha_4
                                        * Referenced by: '<Root>/alpha_Offset3'
                                        */
  165.0,                               /* Variable: zero_alpha_5
                                        * Referenced by: '<Root>/alpha_Offset4'
                                        */
  -12.0,                               /* Variable: zero_alpha_6
                                        * Referenced by: '<Root>/alpha_Offset5'
                                        */
  7.5,                                 /* Variable: zero_pwm
                                        * Referenced by:
                                        *   '<Root>/PWM_Offset'
                                        *   '<Root>/PWM_Offset1'
                                        *   '<Root>/PWM_Offset2'
                                        *   '<Root>/PWM_Offset3'
                                        *   '<Root>/PWM_Offset4'
                                        *   '<Root>/PWM_Offset5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_1'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_2'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_3'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_4'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_5'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S14>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S14>/alpha_6'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S14>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S14>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S14>/alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S14>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/Need unwrapping thrusters'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/Need unwrapping thrusters'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/Need unwrapping thrusters'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/Need unwrapping thrusters'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/Need unwrapping thrusters'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/Need unwrapping thrusters'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/manual override pwm'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/manual override pwm'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/manual override pwm'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/manual override pwm'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/manual override pwm'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/manual override pwm'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/man_alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/man_alpha_5'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/man_alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/man_alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/man_alpha_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/man_alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/man_alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/man_alpha_4'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/man_alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/man_alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/man_alpha_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/man_alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/man_alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/man_alpha_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/man_alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/man_alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/man_alpha_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/man_alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/man_alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/man_alpha_2'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/man_alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/man_alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/man_alpha_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/man_alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/man_alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/man_alpha_3'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/man_alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/man_alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/man_alpha_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/man_alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S16>/man_alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S16>/man_alpha_6'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S16>/man_alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S16>/man_alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S16>/man_alpha_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S16>/man_alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/manual override alpha'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/manual override alpha'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/manual override alpha'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/manual override alpha'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/manual override alpha'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/manual override alpha'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/alpha_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/alpha_2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/alpha_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/alpha_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/alpha_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/alpha_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/alpha_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/alpha_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/alpha_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/alpha_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/alpha_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/alpha_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/alpha_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/alpha_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/alpha_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/alpha_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/alpha_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/alpha_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/alpha_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/alpha_6'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/alpha_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/alpha_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/alpha_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/alpha_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/alpha_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/alpha_4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/alpha_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/alpha_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/alpha_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/alpha_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S15>/alpha_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S15>/alpha_5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S15>/alpha_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S15>/alpha_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S15>/alpha_5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S15>/alpha_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S19>/u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S19>/u_5'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S19>/u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S19>/u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S19>/u_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S19>/u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S19>/u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S19>/u_4'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S19>/u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S19>/u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S19>/u_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S19>/u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S19>/u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S19>/u_6'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S19>/u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S19>/u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S19>/u_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S19>/u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S19>/u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S19>/u_1'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S19>/u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S19>/u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S19>/u_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S19>/u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S19>/u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S19>/u_2'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S19>/u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S19>/u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S19>/u_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S19>/u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S19>/u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S19>/u_3'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S19>/u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S19>/u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S19>/u_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S19>/u_3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation11'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation11'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/pwm_test'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/pwm_test'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/pwm_test'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/pwm_test'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/pwm_test'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/pwm_test'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<Root>/force_test'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<Root>/force_test'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<Root>/force_test'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<Root>/force_test'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<Root>/force_test'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<Root>/force_test'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/pwm_u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/pwm_u_5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/pwm_u_4'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/pwm_u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/pwm_u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/pwm_u_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/pwm_u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/pwm_u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/pwm_u_6'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/pwm_u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/pwm_u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/pwm_u_2'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/pwm_u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/pwm_u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S17>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S17>/pwm_u_3'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S17>/pwm_u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S17>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S17>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S17>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation10'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation10'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation9'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation9'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation8'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation8'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation7'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation7'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation4'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation4'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation5'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation5'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation6'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation6'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/pwm_u_2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/pwm_u_2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/pwm_u_2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/pwm_u_2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/pwm_u_3'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/pwm_u_3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/pwm_u_3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/pwm_u_3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/pwm_u_3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/pwm_u_1'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/pwm_u_1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/pwm_u_1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/pwm_u_1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/pwm_u_1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/pwm_u_6'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/pwm_u_6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/pwm_u_6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/pwm_u_6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/pwm_u_6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/pwm_u_4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/pwm_u_4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/pwm_u_4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/pwm_u_4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S18>/pwm_u_4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S18>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S18>/pwm_u_5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S18>/pwm_u_5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S18>/pwm_u_5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S18>/pwm_u_5'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<S18>/pwm_u_5'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : u2pwm_alpha
 * Model version : 1.103
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Thu May 05 10:59:24 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_u2pwm_alpha_T_sizes[] DataSection(".NIVS.defaultparamsizes")
  = {
  { sizeof(P_u2pwm_alpha_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
