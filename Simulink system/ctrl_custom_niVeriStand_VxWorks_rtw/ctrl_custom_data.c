/*
 * ctrl_custom_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_custom".
 *
 * Model version              : 1.76
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Wed Jul 12 18:22:42 2017
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
                                        * Referenced by: '<S1>/Acc_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Acc_x'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Acc_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Acc_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Acc_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Acc_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Acc_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Acc_y'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Acc_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Acc_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Acc_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Acc_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Acc_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Acc_z'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Acc_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Acc_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Acc_z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Acc_z'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Gyro_x'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Gyro_x'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Gyro_x'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Gyro_x'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Gyro_x'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Gyro_x'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Gyro_y'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Gyro_y'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Gyro_y'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Gyro_y'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Gyro_y'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Gyro_y'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S1>/Gyro_z'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S1>/Gyro_z'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S1>/Gyro_z'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S1>/Gyro_z'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S1>/Gyro_z'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S1>/Gyro_z'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/x_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/x_m'
                                        */
  1.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/x_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/x_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/x_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/x_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/y_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/y_m'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/y_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/y_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/y_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/y_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S3>/psi_m'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S3>/psi_m'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S3>/psi_m'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S3>/psi_m'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S3>/psi_m'
                                        */
  1.0,                                 /* Expression: btype
                                        * Referenced by: '<S3>/psi_m'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha1'
                                        */
  2.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha2'
                                        */
  3.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha3'
                                        */
  4.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha4'
                                        */
  5.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha5'
                                        */
  6.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/alpha6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/alpha6'
                                        */
  7.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/alpha6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/alpha6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/alpha6'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/alpha6'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u1'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u1'
                                        */
  8.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u1'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u1'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u1'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u1'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u2'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u2'
                                        */
  9.0,                                 /* Expression: portnum
                                        * Referenced by: '<S4>/u2'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u2'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u2'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u2'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u3'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u3'
                                        */
  10.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/u3'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u3'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u3'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u3'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u4'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u4'
                                        */
  11.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/u4'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u4'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u4'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u4'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u5'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u5'
                                        */
  12.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/u5'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u5'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u5'
                                        */
  0.0,                                 /* Expression: btype
                                        * Referenced by: '<S4>/u5'
                                        */
  -1.0,                                /* Expression: width
                                        * Referenced by: '<S4>/u6'
                                        */
  1.0,                                 /* Expression: dtype
                                        * Referenced by: '<S4>/u6'
                                        */
  13.0,                                /* Expression: portnum
                                        * Referenced by: '<S4>/u6'
                                        */
  -1.0,                                /* Expression: stime
                                        * Referenced by: '<S4>/u6'
                                        */
  1.0,                                 /* Expression: stype
                                        * Referenced by: '<S4>/u6'
                                        */
  0.0                                  /* Expression: btype
                                        * Referenced by: '<S4>/u6'
                                        */
};
