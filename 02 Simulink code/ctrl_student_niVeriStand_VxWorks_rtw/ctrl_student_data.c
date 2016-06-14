#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
# define ctrl_student_P                ctrl_student_P DataSection(".NIVS.defaultparams")
#endif

/*
 * ctrl_student_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_student".
 *
 * Model version              : 1.63
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu May 12 11:09:12 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ctrl_student.h"
#include "ctrl_student_private.h"

/* Block parameters (auto storage) */
P_ctrl_student_T ctrl_student_P = {
  { 49.7, 99.3, -99.3, -145.3, -98.0, 98.0, 29.4, 80.7, -80.7, -127.3, -82.0,
    82.0, -49.7, 150.6, -150.6, 145.3, -52.7, 52.7, -29.4, 130.3, -130.3, 127.3,
    -34.7, 34.7 },
  0.041111111111111112,
  0.033457124694703737,
  0.3,
  3.3,
  0.266,
  0.266,
  0.445,
  0.445,
  18.973665961010276,
  0.12,
  360052.01473385707,
  0.3,
  49.74429001071266,
  1000.0,
  1.0,
  1.0,
  1.0E-5,
  3.0,
  0.5,
  1.0,
  5.0,
  1151.9725762041953,
  0.5,
  2.0,

  { 0.049001709187525007, -0.39510945913232864, 1.1559741339627327,
    -1.5170203014582015, 1.214660465174924, 0.0 },

  { 1.0776367786545441E-5, 0.0, 0.0, 0.0, 8.4445579E-5, 1.808866E-6, 0.0,
    1.808866E-6, 2.7368522E-5 },
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,

  { 10.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 10.0 },

  { 100.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 100.0 },

  { 1.3, 0.0, 0.0, 0.0, 1.3, 0.0, 0.0, 0.0, 1.3 },
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  2.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  3.0,
  -1.0,
  1.0,
  1.0,

  { 0.0, 0.0, 0.0 },
  1.0E+10,
  -1.0E+10,
  3.1415926535897931,
  6.2831853071795862,

  { 0.0, 0.0 },
  -1.0,
  1.0,
  2.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  3.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -2.0,
  2.0,
  1.0E+10,
  -1.0E+10,
  3.1415926535897931,
  6.2831853071795862,
  -1.0,
  1.0,
  4.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  5.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  6.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  7.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  8.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  9.0,
  -1.0,
  1.0,
  1.0,
  0.0,

  { 0.0, 0.0, 0.0 },
  1.0E+10,
  -1.0E+10,
  3.1415926535897931,
  6.2831853071795862,
  1.0E+10,
  -1.0E+10,
  3.1415926535897931,
  6.2831853071795862,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  2.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  3.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  4.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  5.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  6.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  7.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  8.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  9.0,
  -1.0,
  1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  2.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  3.0,
  -1.0,
  1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  2.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  3.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  4.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  5.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  6.0,
  -1.0,
  1.0,
  1.0,
  57.295779513082323,

  { 1.0677777777777777, 0.93444444444444441, 0.93444444444444441,
    -1.1644444444444444, -0.99111111111111116, -0.99111111111111116 },

  { 0.0, 0.11, -0.11, 0.0, -0.16555555555555557, 0.16555555555555557 },

  { 0.0, 45.0, -45.0, 180.0, -135.0, 135.0 },
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  3.1415926535897931,
  -3.1415926535897931,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  0.01,
  0.0,
  0.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  0.01,
  0.0,
  0.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  0.01,
  0.0,
  0.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  0.01,
  0.0,
  0.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  0.01,
  0.0,
  0.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  0.01,
  0.0,
  0.0,
  0.0,
  -1.0,
  1.0,
  2.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  3.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  4.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  5.0,
  -1.0,
  1.0,
  0.0,
  3.1415926535897931,
  -3.1415926535897931,
  -1.0,
  1.0,
  6.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  7.0,
  -1.0,
  1.0,
  0.0,
  3.1415926535897931,
  -3.1415926535897931,
  -1.0,
  1.0,
  8.0,
  -1.0,
  1.0,
  0.0,
  3.1415926535897931,
  -3.1415926535897931,
  -1.0,
  1.0,
  9.0,
  -1.0,
  1.0,
  0.0,
  3.1415926535897931,
  -3.1415926535897931,
  -1.0,
  1.0,
  10.0,
  -1.0,
  1.0,
  0.0,
  3.1415926535897931,
  -3.1415926535897931,
  -1.0,
  1.0,
  11.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  12.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  13.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  14.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  15.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  16.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  17.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  18.0,
  -1.0,
  1.0,
  0.0,
  57.295779513082323,

  { 1.0677777777777777, 0.93444444444444441, 0.93444444444444441,
    -1.1644444444444444, -0.99111111111111116, -0.99111111111111116 },

  { 0.0, 0.11, -0.11, 0.0, -0.16555555555555557, 0.16555555555555557 },
  -1.0,
  1.0,
  19.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  2.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  3.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  3.0,
  1.0,
  2.0,
  -1.0,
  1.0,
  0.0,
  -1.0,
  1.0,
  3.0,
  -1.0,
  1.0,
  0.0,
  1.0E+10,
  -1.0E+10,
  3.1415926535897931,
  6.2831853071795862,
  -1.0,
  1.0,
  4.0,
  -1.0,
  1.0,
  0.0,
  0.0,

  { 11.66880456602132, 0.0, 0.0, 0.0, 11.66880456602132, 0.0, 0.0, 0.0,
    11.66880456602132 },
  0.0,

  { 34.04025, 0.0, 0.0, 0.0, 34.04025, 0.0, 0.0, 0.0, 34.04025 },
  0.0,

  { 0.00762139060459131, 0.0, 0.0, 0.0, 0.0063848449569688459,
    -5.0835267442179944E-5, -0.0, -9.9224975923314381E-5, 0.013445731502513774 },

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  { 0.094868329805051388, 0.0, 0.0, 0.0, 0.094868329805051388, 0.0, 0.0, 0.0,
    0.094868329805051388 },
  1.0,
  0.0,
  3.1415926535897931,

  { 1.8973665961010275, 0.0, 0.0, 1.8973665961010275 },

  { 1.8973665961010275, 0.0, 0.0, 1.8973665961010275 },
  0.017453292519943295,
  0.0,

  { 1.0, -0.60653065971263342 },

  { 0.0, 0.39346934028736652 },
  0.0,
  0.0,

  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,
  100.0,
  0.05,
  -0.05,
  0.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  0.01,
  0.0,
  0.0,
  0.0,

  { 1.0, -0.60653065971263342 },

  { 0.0, 0.39346934028736652 },
  0.0,
  0.0,

  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,
  100.0,
  0.05,
  -0.05,
  0.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  0.01,
  0.0,
  0.0,
  0.0,

  { 1.0, -0.60653065971263342 },

  { 0.0, 0.39346934028736652 },
  0.0,
  0.0,

  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,
  100.0,
  0.05,
  -0.05,
  0.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  0.01,
  0.0,
  0.0,
  0.0,

  { 1.0, -0.60653065971263342 },

  { 0.0, 0.39346934028736652 },
  0.0,
  0.0,

  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,
  100.0,
  0.05,
  -0.05,
  0.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  0.01,
  0.0,
  0.0,
  0.0,

  { 1.0, -0.60653065971263342 },

  { 0.0, 0.39346934028736652 },
  0.0,
  0.0,

  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,
  100.0,
  0.05,
  -0.05,
  0.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  0.01,
  0.0,
  0.0,
  0.0,

  { 1.0, -0.60653065971263342 },

  { 0.0, 0.39346934028736652 },
  0.0,
  0.0,

  { 1.3452693326565684E-5, 5.3622209501535209E-5, 1.335858607259404E-5 },

  { 1.0, -1.9859776676610581, 0.98605810114995884 },
  0.0,
  100.0,
  0.05,
  -0.05,
  0.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  1.0,
  0.01,
  0.0,
  0.0,
  0.0,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,

  /* Start of '<S43>/CoreSubsys' */
  {
    0.01,
    0.017453292519943295,
    0.0,
    1U
  }
  /* End of '<S43>/CoreSubsys' */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_student
 * Model version : 1.63
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Thu May 12 11:09:11 2016
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_ctrl_student_T_sizes[] DataSection(".NIVS.defaultparamsizes")
  = {
  { sizeof(P_ctrl_student_T), 1 },

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

  { sizeof(real_T), 3, 0 },

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

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 9, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

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
