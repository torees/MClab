/*
 * ctrl_TAPM.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_TAPM".
 *
 * Model version              : 1.190
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Apr 20 19:54:34 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_TAPM.h"
#include "ctrl_TAPM_private.h"

/* Block signals (auto storage) */
B_ctrl_TAPM_T ctrl_TAPM_B;

/* Continuous states */
X_ctrl_TAPM_T ctrl_TAPM_X;

/* Block states (auto storage) */
DW_ctrl_TAPM_T ctrl_TAPM_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_TAPM_T ctrl_TAPM_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_TAPM_T ctrl_TAPM_M_;
RT_MODEL_ctrl_TAPM_T *const ctrl_TAPM_M = &ctrl_TAPM_M_;

/* Forward declaration for local functions */
static void ctrl_TAPM_diag(const real_T v[6], real_T d[36]);
static real_T ctrl_TAPM_eml_xnrm2(int32_T n, const real_T x[18], int32_T ix0);
static real_T ctrl_TAPM_eml_xnrm2_g(int32_T n, const real_T x[6], int32_T ix0);
static void ctrl_TAPM_eml_xaxpy_a4(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[18], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_a(int32_T n, real_T a, const real_T x[18],
  int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_TAPM_eml_xscal(real_T a, real_T x[9], int32_T ix0);
static void ctrl_TAPM_eml_xscal_o(real_T a, real_T x[36], int32_T ix0);
static void ctrl_TAPM_eml_xswap(real_T x[36], int32_T ix0, int32_T iy0);
static void ctrl_TAPM_eml_xswap_n(real_T x[9], int32_T ix0, int32_T iy0);
static void ctrl_TAPM_eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void ctrl_TAPM_eml_xrot(real_T x[36], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static void ctrl_TAPM_eml_xrot_k(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static real_T ctrl_TAPM_eml_xdotc_pe(int32_T n, const real_T x[36], int32_T ix0,
  const real_T y[36], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_a4pl(int32_T n, real_T a, int32_T ix0, real_T y
  [36], int32_T iy0);
static real_T ctrl_TAPM_eml_xdotc_p(int32_T n, const real_T x[9], int32_T ix0,
  const real_T y[9], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_a4p(int32_T n, real_T a, int32_T ix0, real_T y[9],
  int32_T iy0);
static real_T ctrl_TAPM_eml_xdotc(int32_T n, const real_T x[18], int32_T ix0,
  const real_T y[18], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[18],
  int32_T iy0);
static void ctrl_TAPM_eml_xgesvd(const real_T A[18], real_T U[9], real_T S[3],
  real_T V[18]);
static void ctrl_TAPM_svd(const real_T A[18], real_T U[9], real_T S[9], real_T
  V[18]);
static void ctrl_TAPM_isfinite(const real_T x[9], boolean_T b[9]);
static real_T ctrl_TAPM_eml_xnrm2_gg(int32_T n, const real_T x[36], int32_T ix0);
static real_T ctrl_TAPM_eml_xnrm2_ggi(int32_T n, const real_T x[12], int32_T ix0);
static void ctrl_TAPM_eml_xaxpy_a4pl4l0(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[36], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_a4pl4l(int32_T n, real_T a, const real_T x[36],
  int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_TAPM_eml_xscal_ou(real_T a, real_T x[144], int32_T ix0);
static void ctrl_TAPM_eml_xswap_np(real_T x[144], int32_T ix0, int32_T iy0);
static void ctrl_TAPM_eml_xrot_k1(real_T x[144], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static real_T ctrl_TAPM_eml_xdotc_pe1u(int32_T n, const real_T x[144], int32_T
  ix0, const real_T y[144], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_a4pl4l0t(int32_T n, real_T a, int32_T ix0,
  real_T y[144], int32_T iy0);
static real_T ctrl_TAPM_eml_xdotc_pe1(int32_T n, const real_T x[36], int32_T ix0,
  const real_T y[36], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_a4pl4(int32_T n, real_T a, int32_T ix0, real_T
  y[36], int32_T iy0);
static void ctrl_TAPM_eml_xgesvd_a(const real_T A[36], real_T U[9], real_T S[3],
  real_T V[36]);
static void ctrl_TAPM_svd_l(const real_T A[36], real_T U[9], real_T S[9], real_T
  V[36]);
static void ctrl_TAPM_abs(const real_T x[2], real_T y[2]);
static void ctrl_TAPM_cosd(real_T *x);
static void ctrl_TAPM_sind(real_T *x);
static void ctrl_TAPM_cosd_e(real_T *x);
static void ctrl_TAPM_sind_f(real_T *x);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 33;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_TAPM_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ctrl_TAPM_output();
  ctrl_TAPM_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ctrl_TAPM_output();
  ctrl_TAPM_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for action system:
 *    '<S31>/Outlier detected'
 *    '<S32>/Outlier detected'
 *    '<S33>/Outlier detected'
 *    '<S34>/Outlier detected'
 */
void ctrl_TAPM_Outlierdetected(const real_T rtu_Y_previous[7], const real_T
  rtu_V[5], real_T rty_Y_filtered[7], real_T rty_V_hist[5])
{
  int32_T i;

  /* Inport: '<S36>/Y_previous' */
  for (i = 0; i < 7; i++) {
    rty_Y_filtered[i] = rtu_Y_previous[i];
  }

  /* End of Inport: '<S36>/Y_previous' */

  /* Inport: '<S36>/V' */
  for (i = 0; i < 5; i++) {
    rty_V_hist[i] = rtu_V[i];
  }

  /* End of Inport: '<S36>/V' */
}

/*
 * Output and update for action system:
 *    '<S31>/No outlier'
 *    '<S32>/No outlier'
 *    '<S33>/No outlier'
 *    '<S34>/No outlier'
 */
void ctrl_TAPM_Nooutlier(const real_T rtu_Y[7], const real_T rtu_V[5], real_T
  rty_Y_filtered[7], real_T rty_V_hist[5])
{
  int32_T i;

  /* SignalConversion: '<S35>/OutportBufferForV_hist' incorporates:
   *  Inport: '<S35>/V'
   *  Inport: '<S35>/Y'
   */
  rty_V_hist[0] = rtu_Y[6];
  rty_V_hist[1] = rtu_V[1];
  rty_V_hist[2] = rtu_V[2];
  rty_V_hist[3] = rtu_V[3];
  rty_V_hist[4] = rtu_V[4];

  /* SignalConversion: '<S35>/OutportBufferForY_filtered' incorporates:
   *  Inport: '<S35>/Y'
   */
  for (i = 0; i < 7; i++) {
    rty_Y_filtered[i] = rtu_Y[i];
  }

  /* End of SignalConversion: '<S35>/OutportBufferForY_filtered' */
}

/*
 * Output and update for atomic system:
 *    '<S44>/Kd'
 *    '<S46>/Kd'
 */
void ctrl_TAPM_Kd(real_T rtu_K_d1, real_T rtu_K_d1_i, real_T rtu_K_d1_k,
                  B_Kd_ctrl_TAPM_T *localB)
{
  /* MATLAB Function 'Input1/Control Gains/Kd': '<S47>:1' */
  /* '<S47>:1:4' */
  memset(&localB->K_d[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S47>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_d[0] = rtu_K_d1;
  localB->K_d[4] = rtu_K_d1_i;
  localB->K_d[8] = rtu_K_d1_k;
}

/*
 * Output and update for atomic system:
 *    '<S44>/Ki'
 *    '<S46>/Ki'
 */
void ctrl_TAPM_Ki(real_T rtu_K_i1, real_T rtu_K_i1_p, real_T rtu_K_i1_l,
                  B_Ki_ctrl_TAPM_T *localB)
{
  /* MATLAB Function 'Input1/Control Gains/Ki': '<S48>:1' */
  /* '<S48>:1:4' */
  memset(&localB->K_i[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S48>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_i[0] = rtu_K_i1;
  localB->K_i[4] = rtu_K_i1_p;
  localB->K_i[8] = rtu_K_i1_l;
}

/*
 * Output and update for atomic system:
 *    '<S44>/Kp'
 *    '<S46>/Kp'
 */
void ctrl_TAPM_Kp(real_T rtu_K_p1, real_T rtu_K_p1_a, real_T rtu_K_p1_i,
                  B_Kp_ctrl_TAPM_T *localB)
{
  /* MATLAB Function 'Input1/Control Gains/Kp': '<S49>:1' */
  /* '<S49>:1:4' */
  memset(&localB->K_p[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S49>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_p[0] = rtu_K_p1;
  localB->K_p[4] = rtu_K_p1_a;
  localB->K_p[8] = rtu_K_p1_i;
}

/*
 * Output and update for atomic system:
 *    '<S74>/MATLAB Function2'
 *    '<S74>/MATLAB Function3'
 *    '<S74>/MATLAB Function4'
 *    '<S74>/MATLAB Function5'
 *    '<S74>/MATLAB Function6'
 */
void ctrl_TAPM_MATLABFunction2(real_T rtu_Tc_in1, real_T rtu_signal, real_T
  rtu_Tc_in2, B_MATLABFunction2_ctrl_TAPM_T *localB)
{
  /* MATLAB Function 'Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function2': '<S83>:1' */
  if (rtu_signal >= 0.0) {
    /* '<S83>:1:4' */
    /* '<S83>:1:5' */
    localB->Tc_out = rtu_Tc_in1;
  } else {
    /* signal < 0 */
    /* '<S83>:1:7' */
    localB->Tc_out = rtu_Tc_in2;
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/*
 * Output and update for atomic system:
 *    '<S92>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S101>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S110>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S119>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S128>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S137>/Core controller: Torque,Power and Combined Torque//Power'
 */
void CorecontrollerTorquePowerandCom(real_T rtu_k_cc, real_T rtu_p_cc, real_T
  rtu_r_cc, real_T rtu_n, real_T rtu_K_t0, real_T rtu_K_q0, real_T rtu_D, real_T
  rtu_Tr, real_T rtu_rho, real_T rtu_eps_c, real_T rtu_K_t0r, real_T rtu_K_q0r,
  B_CorecontrollerTorquePoweran_T *localB)
{
  real_T Qcq;
  real_T lambda_c;
  real_T K_TC;
  real_T rtu_Tr_0;

  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power': '<S96>:1' */
  /* '<S96>:1:4' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /* '<S96>:1:5' */
  K_TC = (1.0 - lambda_c) * rtu_K_t0r + rtu_K_t0 * lambda_c;

  /* '<S96>:1:6' */
  lambda_c = (1.0 - lambda_c) * rtu_K_q0r + rtu_K_q0 * lambda_c;

  /* '<S96>:1:7' */
  Qcq = lambda_c / K_TC * rtu_D * rtu_Tr;
  if (rtu_n == 0.0) {
    /* '<S96>:1:8' */
    /* '<S96>:1:9' */
    lambda_c = 0.0;
  } else {
    /* '<S96>:1:11' */
    if (rtu_Tr < 0.0) {
      rtu_Tr_0 = -1.0;
    } else if (rtu_Tr > 0.0) {
      rtu_Tr_0 = 1.0;
    } else if (rtu_Tr == 0.0) {
      rtu_Tr_0 = 0.0;
    } else {
      rtu_Tr_0 = rtu_Tr;
    }

    lambda_c = rtu_Tr_0 * lambda_c * rt_powd_snf(fabs(rtu_Tr), 1.5) / (sqrt
      (rtu_rho) * rtu_D * rt_powd_snf(K_TC, 1.5) * fabs(rtu_n));
  }

  /* '<S96>:1:13' */
  K_TC = exp(rt_powd_snf(fabs(rtu_p_cc * rtu_n), rtu_r_cc) * -rtu_k_cc);

  /* '<S96>:1:15' */
  localB->Qcc = (1.0 - K_TC) * lambda_c + K_TC * Qcq;
  localB->Qcq = Qcq;
  localB->Qcp = lambda_c;
}

/*
 * Output and update for atomic system:
 *    '<S90>/Supervisor'
 *    '<S99>/Supervisor'
 *    '<S108>/Supervisor'
 *    '<S117>/Supervisor'
 *    '<S126>/Supervisor'
 *    '<S135>/Supervisor'
 */
void ctrl_TAPM_Supervisor(real_T rtu_control, real_T rtu_input, real_T rtu_n,
  B_Supervisor_ctrl_TAPM_T *localB)
{
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Supervisor': '<S95>:1' */
  /* '<S95>:1:2' */
  localB->u = 1.0;
  if (rtu_control == 1.0) {
    /* '<S95>:1:3' */
    if (rtu_input == 1.0) {
      /* '<S95>:1:4' */
      /* '<S95>:1:5' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S95>:1:6' */
      /* '<S95>:1:7' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S95>:1:8' */
      /* '<S95>:1:9' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S95>:1:10' */
      /* '<S95>:1:11' */
      localB->u = 4.0;
    } else {
      /* '<S95>:1:13' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 2.0) {
    /* '<S95>:1:17' */
    if (rtu_input == 1.0) {
      /* '<S95>:1:18' */
      /* '<S95>:1:19' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S95>:1:20' */
      /* '<S95>:1:21' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S95>:1:22' */
      /* '<S95>:1:23' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S95>:1:24' */
      /* '<S95>:1:25' */
      localB->u = 4.0;
    } else {
      /* '<S95>:1:27' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 3.0) {
    /* '<S95>:1:31' */
    if (rtu_input == 1.0) {
      /* '<S95>:1:32' */
      /* '<S95>:1:33' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S95>:1:34' */
      /* '<S95>:1:35' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S95>:1:36' */
      /* '<S95>:1:37' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S95>:1:38' */
      /* '<S95>:1:39' */
      localB->u = 4.0;
    } else {
      /* '<S95>:1:41' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 4.0) {
    /* '<S95>:1:45' */
    if (rtu_input == 1.0) {
      /* '<S95>:1:46' */
      /* '<S95>:1:47' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S95>:1:48' */
      /* '<S95>:1:49' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S95>:1:50' */
      /* '<S95>:1:51' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S95>:1:52' */
      /* '<S95>:1:53' */
      localB->u = 4.0;
    } else {
      /* '<S95>:1:55' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 5.0) {
    /* '<S95>:1:59' */
    if (rtu_input == 1.0) {
      /* '<S95>:1:60' */
      /* '<S95>:1:61' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S95>:1:62' */
      /* '<S95>:1:63' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S95>:1:64' */
      /* '<S95>:1:65' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S95>:1:66' */
      /* '<S95>:1:67' */
      localB->u = 4.0;
    } else {
      /* '<S95>:1:69' */
      localB->u = 5.0;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S97>/Actual Force and Torque'
 *    '<S106>/Actual Force and Torque'
 *    '<S115>/Actual Force and Torque'
 *    '<S124>/Actual Force and Torque'
 *    '<S133>/Actual Force and Torque'
 */
void ctrl_TAPM_ActualForceandTorque(real_T rtu_n, real_T rtu_Kq, real_T rtu_Kt,
  real_T rtu_Ktr, real_T rtu_Kqr, real_T rtu_Rho, real_T rtu_D, real_T rtu_eps_c,
  real_T rtu_env, B_ActualForceandTorque_ctrl_T_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_0;

  /* MATLAB Function 'Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque': '<S100>:1' */
  /* '<S100>:1:3' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S100>:1:4' */
  /* '<S100>:1:5' */
  /* '<S100>:1:7' */
  if (rtu_n < 0.0) {
    rtu_n_0 = -1.0;
  } else if (rtu_n > 0.0) {
    rtu_n_0 = 1.0;
  } else if (rtu_n == 0.0) {
    rtu_n_0 = 0.0;
  } else {
    rtu_n_0 = rtu_n;
  }

  localB->Ta = ((1.0 - lambda_c) * rtu_Ktr + rtu_Kt * lambda_c) * rtu_n_0 *
    rtu_Rho * rt_powd_snf(rtu_D, 4.0) * (rtu_n * rtu_n) - rtu_env;

  /* '<S100>:1:8' */
  if (rtu_n < 0.0) {
    rtu_n_0 = -1.0;
  } else if (rtu_n > 0.0) {
    rtu_n_0 = 1.0;
  } else if (rtu_n == 0.0) {
    rtu_n_0 = 0.0;
  } else {
    rtu_n_0 = rtu_n;
  }

  localB->Qa = ((1.0 - lambda_c) * rtu_Kqr + rtu_Kq * lambda_c) * rtu_n_0 *
    rtu_Rho * rt_powd_snf(rtu_D, 5.0) * (rtu_n * rtu_n) - rtu_env;
}

/*
 * Output and update for atomic system:
 *    '<S99>/MATLAB Function'
 *    '<S117>/MATLAB Function'
 *    '<S126>/MATLAB Function'
 */
void ctrl_TAPM_MATLABFunction(real_T rtu_Td, real_T rtu_K_t0, real_T rtu_K_t0r,
  real_T rtu_rho, real_T rtu_D, real_T rtu_eps_c, real_T rtu_n_r,
  B_MATLABFunction_ctrl_TAPM_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_r_0;
  real_T rtu_Td_0;

  /* MATLAB Function 'Thruster control /Thruster 2/Thruster control/MATLAB Function': '<S103>:1' */
  /* '<S103>:1:5' */
  if (rtu_Td < 0.0) {
    rtu_Td_0 = -1.0;
  } else if (rtu_Td > 0.0) {
    rtu_Td_0 = 1.0;
  } else if (rtu_Td == 0.0) {
    rtu_Td_0 = 0.0;
  } else {
    rtu_Td_0 = rtu_Td;
  }

  rtu_Td_0 *= sqrt(fabs(rtu_Td) / (rtu_rho * rt_powd_snf(rtu_D, 4.0) * rtu_K_t0));

  /* '<S103>:1:7' */
  lambda_c = tanh(rtu_eps_c * rtu_Td_0 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S103>:1:8' */
  /* '<S103>:1:10' */
  if (rtu_n_r < 0.0) {
    rtu_n_r_0 = -1.0;
  } else if (rtu_n_r > 0.0) {
    rtu_n_r_0 = 1.0;
  } else if (rtu_n_r == 0.0) {
    rtu_n_r_0 = 0.0;
  } else {
    rtu_n_r_0 = rtu_n_r;
  }

  localB->T_r = ((1.0 - lambda_c) * rtu_K_t0r + rtu_K_t0 * lambda_c) * rtu_n_r_0
    * rtu_rho * rt_powd_snf(rtu_D, 4.0) * (rtu_n_r * rtu_n_r);
  localB->n_d = rtu_Td_0;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      u1_0 = ceil(u1);
    } else {
      u1_0 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = u0 / u1;
      if (fabs(u1_0 - rt_roundd_snf(u1_0)) <= DBL_EPSILON * fabs(u1_0)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_diag(const real_T v[6], real_T d[36])
{
  int32_T j;
  memset(&d[0], 0, 36U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    d[j + 6 * j] = v[j];
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xnrm2(int32_T n, const real_T x[18], int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (n == 1) {
    y = fabs(x[ix0 - 1]);
  } else {
    scale = 2.2250738585072014E-308;
    kend = (ix0 + n) - 1;
    for (k = ix0; k <= kend; k++) {
      absxk = fabs(x[k - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
    }

    y = scale * sqrt(y);
  }

  return y;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xnrm2_g(int32_T n, const real_T x[6], int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_a4(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[18], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_a(int32_T n, real_T a, const real_T x[18],
  int32_T ix0, real_T y[3], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xscal(real_T a, real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xscal_o(real_T a, real_T x[36], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 5; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xswap(real_T x[36], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  int32_T k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 6; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xswap_n(real_T x[9], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
  ix++;
  iy++;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
  ix++;
  iy++;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale;
  real_T ads;
  real_T bds;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    ads = 0.0;
    scale = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    ads = sqrt(ads * ads + bds * bds) * scale;
    if (roe < 0.0) {
      ads = -ads;
    }

    *c = *a / ads;
    *s = *b / ads;
    if (absa > absb) {
      scale = *s;
    } else if (*c != 0.0) {
      scale = 1.0 / *c;
    } else {
      scale = 1.0;
    }
  }

  *a = ads;
  *b = scale;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xrot(real_T x[36], int32_T ix0, int32_T iy0, real_T c,
  real_T s)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  int32_T k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 6; k++) {
    temp = c * x[ix] + s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = temp;
    iy++;
    ix++;
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xrot_k(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
  real_T s)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  temp = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = temp;
  iy++;
  ix++;
  temp = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = temp;
  iy++;
  ix++;
  temp = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = temp;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc_pe(int32_T n, const real_T x[36], int32_T ix0,
  const real_T y[36], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (!(n < 1)) {
    ix = ix0;
    iy = iy0;
    for (k = 1; k <= n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_a4pl(int32_T n, real_T a, int32_T ix0, real_T y
  [36], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc_p(int32_T n, const real_T x[9], int32_T ix0,
  const real_T y[9], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  ix = ix0;
  iy = iy0;
  for (k = 1; k <= n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_a4p(int32_T n, real_T a, int32_T ix0, real_T y[9],
  int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!(a == 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc(int32_T n, const real_T x[18], int32_T ix0,
  const real_T y[18], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  ix = ix0;
  iy = iy0;
  for (k = 1; k <= n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[18],
  int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!(a == 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xgesvd(const real_T A[18], real_T U[9], real_T S[3],
  real_T V[18])
{
  real_T b_A[18];
  real_T s[4];
  real_T e[6];
  real_T work[3];
  real_T Vf[36];
  int32_T q;
  boolean_T apply_transform;
  int32_T qp1jj;
  int32_T m;
  int32_T iter;
  real_T snorm;
  real_T ztest0;
  int32_T kase;
  int32_T qs;
  real_T ztest;
  real_T f;
  real_T sqds;
  real_T b;
  real_T varargin_1[5];
  real_T mtmp;
  int32_T i;
  memcpy(&b_A[0], &A[0], 18U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    e[i] = 0.0;
  }

  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  memset(&U[0], 0, 9U * sizeof(real_T));
  memset(&Vf[0], 0, 36U * sizeof(real_T));
  apply_transform = false;
  ztest0 = ctrl_TAPM_eml_xnrm2(3, b_A, 1);
  if (ztest0 > 0.0) {
    apply_transform = true;
    if (b_A[0] < 0.0) {
      s[0] = -ztest0;
    } else {
      s[0] = ztest0;
    }

    if (fabs(s[0]) >= 1.0020841800044864E-292) {
      ztest0 = 1.0 / s[0];
      for (i = 0; i + 1 < 4; i++) {
        b_A[i] *= ztest0;
      }
    } else {
      for (i = 0; i + 1 < 4; i++) {
        b_A[i] /= s[0];
      }
    }

    b_A[0]++;
    s[0] = -s[0];
  } else {
    s[0] = 0.0;
  }

  for (kase = 1; kase + 1 < 7; kase++) {
    qp1jj = 3 * kase;
    if (apply_transform) {
      ctrl_TAPM_eml_xaxpy(3, -(ctrl_TAPM_eml_xdotc(3, b_A, 1, b_A, qp1jj + 1) /
        b_A[0]), 1, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (i = 0; i + 1 < 4; i++) {
    U[i] = b_A[i];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_g(5, e, 2);
  if (ztest0 == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      e[0] = -ztest0;
    } else {
      e[0] = ztest0;
    }

    ztest0 = e[0];
    if (fabs(e[0]) >= 1.0020841800044864E-292) {
      ztest0 = 1.0 / e[0];
      for (i = 1; i + 1 < 7; i++) {
        e[i] *= ztest0;
      }
    } else {
      for (i = 1; i + 1 < 7; i++) {
        e[i] /= ztest0;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (i = 1; i + 1 < 4; i++) {
      work[i] = 0.0;
    }

    for (i = 1; i + 1 < 7; i++) {
      ctrl_TAPM_eml_xaxpy_a(2, e[i], b_A, 3 * i + 2, work, 2);
    }

    for (i = 1; i + 1 < 7; i++) {
      ctrl_TAPM_eml_xaxpy_a4(2, -e[i] / e[1], work, 2, b_A, 3 * i + 2);
    }
  }

  for (i = 1; i + 1 < 7; i++) {
    Vf[i] = e[i];
  }

  apply_transform = false;
  ztest0 = ctrl_TAPM_eml_xnrm2(2, b_A, 5);
  if (ztest0 > 0.0) {
    apply_transform = true;
    if (b_A[4] < 0.0) {
      s[1] = -ztest0;
    } else {
      s[1] = ztest0;
    }

    if (fabs(s[1]) >= 1.0020841800044864E-292) {
      ztest0 = 1.0 / s[1];
      for (i = 4; i + 1 < 7; i++) {
        b_A[i] *= ztest0;
      }
    } else {
      for (i = 4; i + 1 < 7; i++) {
        b_A[i] /= s[1];
      }
    }

    b_A[4]++;
    s[1] = -s[1];
  } else {
    s[1] = 0.0;
  }

  for (kase = 2; kase + 1 < 7; kase++) {
    qp1jj = 3 * kase + 1;
    if (apply_transform) {
      ctrl_TAPM_eml_xaxpy(2, -(ctrl_TAPM_eml_xdotc(2, b_A, 5, b_A, qp1jj + 1) /
        b_A[4]), 5, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (i = 1; i + 1 < 4; i++) {
    U[i + 3] = b_A[i + 3];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_g(4, e, 3);
  if (ztest0 == 0.0) {
    e[1] = 0.0;
  } else {
    if (e[2] < 0.0) {
      e[1] = -ztest0;
    } else {
      e[1] = ztest0;
    }

    ztest0 = e[1];
    if (fabs(e[1]) >= 1.0020841800044864E-292) {
      ztest0 = 1.0 / e[1];
      for (i = 2; i + 1 < 7; i++) {
        e[i] *= ztest0;
      }
    } else {
      for (i = 2; i + 1 < 7; i++) {
        e[i] /= ztest0;
      }
    }

    e[2]++;
    e[1] = -e[1];
    for (i = 2; i + 1 < 4; i++) {
      work[i] = 0.0;
    }

    for (i = 2; i + 1 < 7; i++) {
      ctrl_TAPM_eml_xaxpy_a(1, e[i], b_A, 3 * i + 3, work, 3);
    }

    for (i = 2; i + 1 < 7; i++) {
      ctrl_TAPM_eml_xaxpy_a4(1, -e[i] / e[2], work, 3, b_A, 3 * i + 3);
    }
  }

  for (i = 2; i + 1 < 7; i++) {
    Vf[i + 6] = e[i];
  }

  for (kase = 3; kase + 1 < 7; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_g(3, e, 4);
  if (ztest0 == 0.0) {
    e[2] = 0.0;
  } else {
    if (e[3] < 0.0) {
      e[2] = -ztest0;
    } else {
      e[2] = ztest0;
    }

    ztest0 = e[2];
    if (fabs(e[2]) >= 1.0020841800044864E-292) {
      ztest0 = 1.0 / e[2];
      for (i = 3; i + 1 < 7; i++) {
        e[i] *= ztest0;
      }
    } else {
      for (i = 3; i + 1 < 7; i++) {
        e[i] /= ztest0;
      }
    }

    e[3]++;
    e[2] = -e[2];
  }

  for (i = 3; i + 1 < 7; i++) {
    Vf[i + 12] = e[i];
  }

  m = 2;
  s[2] = b_A[8];
  s[3] = 0.0;
  e[3] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (qs = 1; qs >= 0; qs += -1) {
    iter = 3 * qs + qs;
    if (s[qs] != 0.0) {
      for (i = qs + 1; i + 1 < 4; i++) {
        qp1jj = (3 * i + qs) + 1;
        ctrl_TAPM_eml_xaxpy_a4p(3 - qs, -(ctrl_TAPM_eml_xdotc_p(3 - qs, U, iter
          + 1, U, qp1jj) / U[iter]), iter + 1, U, qp1jj);
      }

      for (kase = qs; kase + 1 < 4; kase++) {
        U[kase + 3 * qs] = -U[3 * qs + kase];
      }

      U[iter]++;
      kase = 1;
      while (kase <= qs) {
        U[3] = 0.0;
        kase = 2;
      }
    } else {
      U[3 * qs] = 0.0;
      U[1 + 3 * qs] = 0.0;
      U[2 + 3 * qs] = 0.0;
      U[iter] = 1.0;
    }
  }

  for (qs = 5; qs >= 0; qs += -1) {
    if ((qs + 1 <= 3) && (e[qs] != 0.0)) {
      i = (6 * qs + qs) + 2;
      for (kase = qs + 1; kase + 1 < 7; kase++) {
        qp1jj = (6 * kase + qs) + 2;
        ctrl_TAPM_eml_xaxpy_a4pl(5 - qs, -(ctrl_TAPM_eml_xdotc_pe(5 - qs, Vf, i,
          Vf, qp1jj) / Vf[i - 1]), i, Vf, qp1jj);
      }
    }

    for (kase = 0; kase < 6; kase++) {
      Vf[kase + 6 * qs] = 0.0;
    }

    Vf[qs + 6 * qs] = 1.0;
  }

  b = e[0];
  if (s[0] != 0.0) {
    ztest = fabs(s[0]);
    ztest0 = s[0] / ztest;
    s[0] = ztest;
    b = e[0] / ztest0;
    ctrl_TAPM_eml_xscal(ztest0, U, 1);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[1] *= ztest0;
    ctrl_TAPM_eml_xscal_o(ztest0, Vf, 7);
  }

  e[0] = b;
  b = e[1];
  if (s[1] != 0.0) {
    ztest = fabs(s[1]);
    ztest0 = s[1] / ztest;
    s[1] = ztest;
    b = e[1] / ztest0;
    ctrl_TAPM_eml_xscal(ztest0, U, 4);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[2] = b_A[8] * ztest0;
    ctrl_TAPM_eml_xscal_o(ztest0, Vf, 13);
  }

  e[1] = b;
  b = e[2];
  if (s[2] != 0.0) {
    ztest = fabs(s[2]);
    ztest0 = s[2] / ztest;
    s[2] = ztest;
    b = e[2] / ztest0;
    ctrl_TAPM_eml_xscal(ztest0, U, 7);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[3] = 0.0 * ztest0;
    ctrl_TAPM_eml_xscal_o(ztest0, Vf, 19);
  }

  e[2] = b;
  e[3] = 0.0;
  iter = 0;
  snorm = 0.0;
  if ((s[0] >= e[0]) || rtIsNaN(e[0])) {
    f = s[0];
  } else {
    f = e[0];
  }

  if (!((0.0 >= f) || rtIsNaN(f))) {
    snorm = f;
  }

  if ((s[1] >= e[1]) || rtIsNaN(e[1])) {
    f = s[1];
  } else {
    f = e[1];
  }

  if (!((snorm >= f) || rtIsNaN(f))) {
    snorm = f;
  }

  if ((s[2] >= b) || rtIsNaN(b)) {
    b = s[2];
  }

  if (!((snorm >= b) || rtIsNaN(b))) {
    snorm = b;
  }

  if (s[3] >= 0.0) {
    f = s[3];
  } else {
    f = 0.0;
  }

  if (!((snorm >= f) || rtIsNaN(f))) {
    snorm = f;
  }

  while ((m + 2 > 0) && (!(iter >= 75))) {
    qp1jj = m + 1;
    do {
      kase = 0;
      q = qp1jj;
      if (qp1jj == 0) {
        kase = 1;
      } else {
        ztest0 = fabs(e[qp1jj - 1]);
        if ((ztest0 <= (fabs(s[qp1jj - 1]) + fabs(s[qp1jj])) *
             2.2204460492503131E-16) || (ztest0 <= 1.0020841800044864E-292) ||
            ((iter > 20) && (ztest0 <= 2.2204460492503131E-16 * snorm))) {
          e[qp1jj - 1] = 0.0;
          kase = 1;
        } else {
          qp1jj--;
        }
      }
    } while (kase == 0);

    if (m + 1 == qp1jj) {
      kase = 4;
    } else {
      qs = m + 2;
      i = m + 2;
      apply_transform = false;
      while ((!apply_transform) && (i >= qp1jj)) {
        qs = i;
        if (i == qp1jj) {
          apply_transform = true;
        } else {
          ztest0 = 0.0;
          if (i < m + 2) {
            ztest0 = fabs(e[i - 1]);
          }

          if (i > qp1jj + 1) {
            ztest0 += fabs(e[i - 2]);
          }

          ztest = fabs(s[i - 1]);
          if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <=
               1.0020841800044864E-292)) {
            s[i - 1] = 0.0;
            apply_transform = true;
          } else {
            i--;
          }
        }
      }

      if (qs == qp1jj) {
        kase = 3;
      } else {
        if (m + 2 != qs) {
          kase = 2;
          q = qs;
        }
      }
    }

    switch (kase) {
     case 1:
      f = e[m];
      e[m] = 0.0;
      for (kase = m; kase + 1 >= q + 1; kase--) {
        ztest0 = s[kase];
        ctrl_TAPM_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        if (kase + 1 > q + 1) {
          f = e[kase - 1] * -b;
          e[kase - 1] *= ztest;
        }

        ctrl_TAPM_eml_xrot(Vf, 1 + 6 * kase, 1 + 6 * (m + 1), ztest, b);
      }
      break;

     case 2:
      f = e[q - 1];
      e[q - 1] = 0.0;
      for (kase = q; kase + 1 <= m + 2; kase++) {
        ztest0 = s[kase];
        ctrl_TAPM_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        f = -b * e[kase];
        e[kase] *= ztest;
        ctrl_TAPM_eml_xrot_k(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest, b);
      }
      break;

     case 3:
      varargin_1[0] = fabs(s[m + 1]);
      varargin_1[1] = fabs(s[m]);
      varargin_1[2] = fabs(e[m]);
      varargin_1[3] = fabs(s[q]);
      varargin_1[4] = fabs(e[q]);
      i = 1;
      mtmp = varargin_1[0];
      if (rtIsNaN(varargin_1[0])) {
        kase = 2;
        apply_transform = false;
        while ((!apply_transform) && (kase < 6)) {
          i = kase;
          if (!rtIsNaN(varargin_1[kase - 1])) {
            mtmp = varargin_1[kase - 1];
            apply_transform = true;
          } else {
            kase++;
          }
        }
      }

      if (i < 5) {
        while (i + 1 < 6) {
          if (varargin_1[i] > mtmp) {
            mtmp = varargin_1[i];
          }

          i++;
        }
      }

      f = s[m + 1] / mtmp;
      ztest0 = s[m] / mtmp;
      ztest = e[m] / mtmp;
      sqds = s[q] / mtmp;
      b = ((ztest0 + f) * (ztest0 - f) + ztest * ztest) / 2.0;
      ztest0 = f * ztest;
      ztest0 *= ztest0;
      if ((b != 0.0) || (ztest0 != 0.0)) {
        ztest = sqrt(b * b + ztest0);
        if (b < 0.0) {
          ztest = -ztest;
        }

        ztest = ztest0 / (b + ztest);
      } else {
        ztest = 0.0;
      }

      f = (sqds + f) * (sqds - f) + ztest;
      b = e[q] / mtmp * sqds;
      for (kase = q + 1; kase <= m + 1; kase++) {
        ctrl_TAPM_eml_xrotg(&f, &b, &ztest0, &ztest);
        if (kase > q + 1) {
          e[kase - 2] = f;
        }

        f = s[kase - 1] * ztest0 + e[kase - 1] * ztest;
        e[kase - 1] = e[kase - 1] * ztest0 - s[kase - 1] * ztest;
        b = ztest * s[kase];
        s[kase] *= ztest0;
        ctrl_TAPM_eml_xrot(Vf, 1 + 6 * (kase - 1), 1 + 6 * kase, ztest0, ztest);
        ctrl_TAPM_eml_xrotg(&f, &b, &ztest0, &ztest);
        s[kase - 1] = f;
        f = e[kase - 1] * ztest0 + ztest * s[kase];
        s[kase] = e[kase - 1] * -ztest + ztest0 * s[kase];
        b = ztest * e[kase];
        e[kase] *= ztest0;
        if (kase < 3) {
          ctrl_TAPM_eml_xrot_k(U, 1 + 3 * (kase - 1), 1 + 3 * kase, ztest0,
                               ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_TAPM_eml_xscal_o(-1.0, Vf, 1 + 6 * q);
      }

      i = q + 1;
      while ((q + 1 < 4) && (s[q] < s[i])) {
        ztest = s[q];
        s[q] = s[i];
        s[i] = ztest;
        ctrl_TAPM_eml_xswap(Vf, 1 + 6 * q, 1 + 6 * (q + 1));
        if (q + 1 < 3) {
          ctrl_TAPM_eml_xswap_n(U, 1 + 3 * q, 1 + 3 * (q + 1));
        }

        q = i;
        i++;
      }

      iter = 0;
      m--;
      break;
    }
  }

  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
  for (i = 0; i < 3; i++) {
    for (kase = 0; kase < 6; kase++) {
      V[kase + 6 * i] = Vf[6 * i + kase];
    }
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_svd(const real_T A[18], real_T U[9], real_T S[9], real_T
  V[18])
{
  real_T s[3];
  ctrl_TAPM_eml_xgesvd(A, U, s, V);
  memset(&S[0], 0, 9U * sizeof(real_T));
  S[0] = s[0];
  S[4] = s[1];
  S[8] = s[2];
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_isfinite(const real_T x[9], boolean_T b[9])
{
  int32_T i;
  for (i = 0; i < 9; i++) {
    b[i] = ((!rtIsInf(x[i])) && (!rtIsNaN(x[i])));
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xnrm2_gg(int32_T n, const real_T x[36], int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (n == 1) {
    y = fabs(x[ix0 - 1]);
  } else {
    scale = 2.2250738585072014E-308;
    kend = (ix0 + n) - 1;
    for (k = ix0; k <= kend; k++) {
      absxk = fabs(x[k - 1]);
      if (absxk > scale) {
        t = scale / absxk;
        y = y * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        y += t * t;
      }
    }

    y = scale * sqrt(y);
  }

  return y;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xnrm2_ggi(int32_T n, const real_T x[12], int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_a4pl4l0(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[36], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_a4pl4l(int32_T n, real_T a, const real_T x[36],
  int32_T ix0, real_T y[3], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xscal_ou(real_T a, real_T x[144], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 11; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xswap_np(real_T x[144], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  int32_T k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 12; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xrot_k1(real_T x[144], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  int32_T k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 12; k++) {
    temp = c * x[ix] + s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = temp;
    iy++;
    ix++;
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc_pe1u(int32_T n, const real_T x[144], int32_T
  ix0, const real_T y[144], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (!(n < 1)) {
    ix = ix0;
    iy = iy0;
    for (k = 1; k <= n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_a4pl4l0t(int32_T n, real_T a, int32_T ix0,
  real_T y[144], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc_pe1(int32_T n, const real_T x[36], int32_T ix0,
  const real_T y[36], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  ix = ix0;
  iy = iy0;
  for (k = 1; k <= n; k++) {
    d += x[ix - 1] * y[iy - 1];
    ix++;
    iy++;
  }

  return d;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_a4pl4(int32_T n, real_T a, int32_T ix0, real_T
  y[36], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!(a == 0.0)) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_eml_xgesvd_a(const real_T A[36], real_T U[9], real_T S[3],
  real_T V[36])
{
  real_T b_A[36];
  real_T s[4];
  real_T e[12];
  real_T work[3];
  real_T Vf[144];
  int32_T q;
  int32_T qp1;
  boolean_T apply_transform;
  int32_T qp1jj;
  int32_T m;
  int32_T iter;
  real_T snorm;
  real_T ztest0;
  int32_T kase;
  int32_T qs;
  real_T ztest;
  real_T f;
  real_T sqds;
  real_T b;
  real_T varargin_1[5];
  real_T mtmp;
  memcpy(&b_A[0], &A[0], 36U * sizeof(real_T));
  memset(&e[0], 0, 12U * sizeof(real_T));
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  memset(&U[0], 0, 9U * sizeof(real_T));
  memset(&Vf[0], 0, 144U * sizeof(real_T));
  apply_transform = false;
  ztest0 = ctrl_TAPM_eml_xnrm2_gg(3, b_A, 1);
  if (ztest0 > 0.0) {
    apply_transform = true;
    if (b_A[0] < 0.0) {
      s[0] = -ztest0;
    } else {
      s[0] = ztest0;
    }

    if (fabs(s[0]) >= 1.0020841800044864E-292) {
      ztest0 = 1.0 / s[0];
      for (qp1 = 0; qp1 + 1 < 4; qp1++) {
        b_A[qp1] *= ztest0;
      }
    } else {
      for (qp1 = 0; qp1 + 1 < 4; qp1++) {
        b_A[qp1] /= s[0];
      }
    }

    b_A[0]++;
    s[0] = -s[0];
  } else {
    s[0] = 0.0;
  }

  for (kase = 1; kase + 1 < 13; kase++) {
    qp1jj = 3 * kase;
    if (apply_transform) {
      ctrl_TAPM_eml_xaxpy_a4pl4(3, -(ctrl_TAPM_eml_xdotc_pe1(3, b_A, 1, b_A,
        qp1jj + 1) / b_A[0]), 1, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 0; qp1 + 1 < 4; qp1++) {
    U[qp1] = b_A[qp1];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_ggi(11, e, 2);
  if (ztest0 == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      e[0] = -ztest0;
    } else {
      e[0] = ztest0;
    }

    ztest0 = e[0];
    if (fabs(e[0]) >= 1.0020841800044864E-292) {
      ztest0 = 1.0 / e[0];
      for (qp1 = 1; qp1 + 1 < 13; qp1++) {
        e[qp1] *= ztest0;
      }
    } else {
      for (qp1 = 1; qp1 + 1 < 13; qp1++) {
        e[qp1] /= ztest0;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (qp1 = 1; qp1 + 1 < 4; qp1++) {
      work[qp1] = 0.0;
    }

    for (qp1 = 1; qp1 + 1 < 13; qp1++) {
      ctrl_TAPM_eml_xaxpy_a4pl4l(2, e[qp1], b_A, 3 * qp1 + 2, work, 2);
    }

    for (qp1 = 1; qp1 + 1 < 13; qp1++) {
      ctrl_TAPM_eml_xaxpy_a4pl4l0(2, -e[qp1] / e[1], work, 2, b_A, 3 * qp1 + 2);
    }
  }

  for (qp1 = 1; qp1 + 1 < 13; qp1++) {
    Vf[qp1] = e[qp1];
  }

  apply_transform = false;
  ztest0 = ctrl_TAPM_eml_xnrm2_gg(2, b_A, 5);
  if (ztest0 > 0.0) {
    apply_transform = true;
    if (b_A[4] < 0.0) {
      s[1] = -ztest0;
    } else {
      s[1] = ztest0;
    }

    if (fabs(s[1]) >= 1.0020841800044864E-292) {
      ztest0 = 1.0 / s[1];
      for (qp1 = 4; qp1 + 1 < 7; qp1++) {
        b_A[qp1] *= ztest0;
      }
    } else {
      for (qp1 = 4; qp1 + 1 < 7; qp1++) {
        b_A[qp1] /= s[1];
      }
    }

    b_A[4]++;
    s[1] = -s[1];
  } else {
    s[1] = 0.0;
  }

  for (kase = 2; kase + 1 < 13; kase++) {
    qp1jj = 3 * kase + 1;
    if (apply_transform) {
      ctrl_TAPM_eml_xaxpy_a4pl4(2, -(ctrl_TAPM_eml_xdotc_pe1(2, b_A, 5, b_A,
        qp1jj + 1) / b_A[4]), 5, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 1; qp1 + 1 < 4; qp1++) {
    U[qp1 + 3] = b_A[qp1 + 3];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_ggi(10, e, 3);
  if (ztest0 == 0.0) {
    e[1] = 0.0;
  } else {
    if (e[2] < 0.0) {
      e[1] = -ztest0;
    } else {
      e[1] = ztest0;
    }

    ztest0 = e[1];
    if (fabs(e[1]) >= 1.0020841800044864E-292) {
      ztest0 = 1.0 / e[1];
      for (qp1 = 2; qp1 + 1 < 13; qp1++) {
        e[qp1] *= ztest0;
      }
    } else {
      for (qp1 = 2; qp1 + 1 < 13; qp1++) {
        e[qp1] /= ztest0;
      }
    }

    e[2]++;
    e[1] = -e[1];
    for (qp1 = 2; qp1 + 1 < 4; qp1++) {
      work[qp1] = 0.0;
    }

    for (qp1 = 2; qp1 + 1 < 13; qp1++) {
      ctrl_TAPM_eml_xaxpy_a4pl4l(1, e[qp1], b_A, 3 * qp1 + 3, work, 3);
    }

    for (qp1 = 2; qp1 + 1 < 13; qp1++) {
      ctrl_TAPM_eml_xaxpy_a4pl4l0(1, -e[qp1] / e[2], work, 3, b_A, 3 * qp1 + 3);
    }
  }

  for (qp1 = 2; qp1 + 1 < 13; qp1++) {
    Vf[qp1 + 12] = e[qp1];
  }

  for (kase = 3; kase + 1 < 13; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_ggi(9, e, 4);
  if (ztest0 == 0.0) {
    e[2] = 0.0;
  } else {
    if (e[3] < 0.0) {
      e[2] = -ztest0;
    } else {
      e[2] = ztest0;
    }

    ztest0 = e[2];
    if (fabs(e[2]) >= 1.0020841800044864E-292) {
      ztest0 = 1.0 / e[2];
      for (qp1 = 3; qp1 + 1 < 13; qp1++) {
        e[qp1] *= ztest0;
      }
    } else {
      for (qp1 = 3; qp1 + 1 < 13; qp1++) {
        e[qp1] /= ztest0;
      }
    }

    e[3]++;
    e[2] = -e[2];
  }

  for (qp1 = 3; qp1 + 1 < 13; qp1++) {
    Vf[qp1 + 24] = e[qp1];
  }

  m = 2;
  s[2] = b_A[8];
  s[3] = 0.0;
  e[3] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (qs = 1; qs >= 0; qs += -1) {
    iter = 3 * qs + qs;
    if (s[qs] != 0.0) {
      for (qp1 = qs + 1; qp1 + 1 < 4; qp1++) {
        qp1jj = (3 * qp1 + qs) + 1;
        ctrl_TAPM_eml_xaxpy_a4p(3 - qs, -(ctrl_TAPM_eml_xdotc_p(3 - qs, U, iter
          + 1, U, qp1jj) / U[iter]), iter + 1, U, qp1jj);
      }

      for (kase = qs; kase + 1 < 4; kase++) {
        U[kase + 3 * qs] = -U[3 * qs + kase];
      }

      U[iter]++;
      kase = 1;
      while (kase <= qs) {
        U[3] = 0.0;
        kase = 2;
      }
    } else {
      U[3 * qs] = 0.0;
      U[1 + 3 * qs] = 0.0;
      U[2 + 3 * qs] = 0.0;
      U[iter] = 1.0;
    }
  }

  for (qs = 11; qs >= 0; qs += -1) {
    if ((qs + 1 <= 3) && (e[qs] != 0.0)) {
      qp1 = (12 * qs + qs) + 2;
      for (kase = qs + 1; kase + 1 < 13; kase++) {
        qp1jj = (12 * kase + qs) + 2;
        ctrl_TAPM_eml_xaxpy_a4pl4l0t(11 - qs, -(ctrl_TAPM_eml_xdotc_pe1u(11 - qs,
          Vf, qp1, Vf, qp1jj) / Vf[qp1 - 1]), qp1, Vf, qp1jj);
      }
    }

    memset(&Vf[12 * qs], 0, 12U * sizeof(real_T));
    Vf[qs + 12 * qs] = 1.0;
  }

  b = e[0];
  if (s[0] != 0.0) {
    ztest = fabs(s[0]);
    ztest0 = s[0] / ztest;
    s[0] = ztest;
    b = e[0] / ztest0;
    ctrl_TAPM_eml_xscal(ztest0, U, 1);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[1] *= ztest0;
    ctrl_TAPM_eml_xscal_ou(ztest0, Vf, 13);
  }

  e[0] = b;
  b = e[1];
  if (s[1] != 0.0) {
    ztest = fabs(s[1]);
    ztest0 = s[1] / ztest;
    s[1] = ztest;
    b = e[1] / ztest0;
    ctrl_TAPM_eml_xscal(ztest0, U, 4);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[2] = b_A[8] * ztest0;
    ctrl_TAPM_eml_xscal_ou(ztest0, Vf, 25);
  }

  e[1] = b;
  b = e[2];
  if (s[2] != 0.0) {
    ztest = fabs(s[2]);
    ztest0 = s[2] / ztest;
    s[2] = ztest;
    b = e[2] / ztest0;
    ctrl_TAPM_eml_xscal(ztest0, U, 7);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[3] = 0.0 * ztest0;
    ctrl_TAPM_eml_xscal_ou(ztest0, Vf, 37);
  }

  e[2] = b;
  e[3] = 0.0;
  iter = 0;
  snorm = 0.0;
  f = fabs(e[0]);
  if ((s[0] >= f) || rtIsNaN(f)) {
    f = s[0];
  }

  if (!((0.0 >= f) || rtIsNaN(f))) {
    snorm = f;
  }

  f = fabs(e[1]);
  if ((s[1] >= f) || rtIsNaN(f)) {
    f = s[1];
  }

  if (!((snorm >= f) || rtIsNaN(f))) {
    snorm = f;
  }

  f = fabs(b);
  if ((s[2] >= f) || rtIsNaN(f)) {
    f = s[2];
  }

  if (!((snorm >= f) || rtIsNaN(f))) {
    snorm = f;
  }

  if (s[3] >= 0.0) {
    f = s[3];
  } else {
    f = 0.0;
  }

  if (!((snorm >= f) || rtIsNaN(f))) {
    snorm = f;
  }

  while ((m + 2 > 0) && (!(iter >= 75))) {
    qp1jj = m + 1;
    do {
      kase = 0;
      q = qp1jj;
      if (qp1jj == 0) {
        kase = 1;
      } else {
        ztest0 = fabs(e[qp1jj - 1]);
        if ((ztest0 <= (fabs(s[qp1jj - 1]) + fabs(s[qp1jj])) *
             2.2204460492503131E-16) || (ztest0 <= 1.0020841800044864E-292) ||
            ((iter > 20) && (ztest0 <= 2.2204460492503131E-16 * snorm))) {
          e[qp1jj - 1] = 0.0;
          kase = 1;
        } else {
          qp1jj--;
        }
      }
    } while (kase == 0);

    if (m + 1 == qp1jj) {
      kase = 4;
    } else {
      qs = m + 2;
      qp1 = m + 2;
      apply_transform = false;
      while ((!apply_transform) && (qp1 >= qp1jj)) {
        qs = qp1;
        if (qp1 == qp1jj) {
          apply_transform = true;
        } else {
          ztest0 = 0.0;
          if (qp1 < m + 2) {
            ztest0 = fabs(e[qp1 - 1]);
          }

          if (qp1 > qp1jj + 1) {
            ztest0 += fabs(e[qp1 - 2]);
          }

          ztest = fabs(s[qp1 - 1]);
          if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <=
               1.0020841800044864E-292)) {
            s[qp1 - 1] = 0.0;
            apply_transform = true;
          } else {
            qp1--;
          }
        }
      }

      if (qs == qp1jj) {
        kase = 3;
      } else {
        if (m + 2 != qs) {
          kase = 2;
          q = qs;
        }
      }
    }

    switch (kase) {
     case 1:
      f = e[m];
      e[m] = 0.0;
      for (kase = m; kase + 1 >= q + 1; kase--) {
        ztest0 = s[kase];
        ctrl_TAPM_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        if (kase + 1 > q + 1) {
          f = e[kase - 1] * -b;
          e[kase - 1] *= ztest;
        }

        ctrl_TAPM_eml_xrot_k1(Vf, 1 + 12 * kase, 1 + 12 * (m + 1), ztest, b);
      }
      break;

     case 2:
      f = e[q - 1];
      e[q - 1] = 0.0;
      for (kase = q; kase + 1 <= m + 2; kase++) {
        ztest0 = s[kase];
        ctrl_TAPM_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        f = -b * e[kase];
        e[kase] *= ztest;
        ctrl_TAPM_eml_xrot_k(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest, b);
      }
      break;

     case 3:
      varargin_1[0] = fabs(s[m + 1]);
      varargin_1[1] = fabs(s[m]);
      varargin_1[2] = fabs(e[m]);
      varargin_1[3] = fabs(s[q]);
      varargin_1[4] = fabs(e[q]);
      qp1 = 1;
      mtmp = varargin_1[0];
      if (rtIsNaN(varargin_1[0])) {
        kase = 2;
        apply_transform = false;
        while ((!apply_transform) && (kase < 6)) {
          qp1 = kase;
          if (!rtIsNaN(varargin_1[kase - 1])) {
            mtmp = varargin_1[kase - 1];
            apply_transform = true;
          } else {
            kase++;
          }
        }
      }

      if (qp1 < 5) {
        while (qp1 + 1 < 6) {
          if (varargin_1[qp1] > mtmp) {
            mtmp = varargin_1[qp1];
          }

          qp1++;
        }
      }

      f = s[m + 1] / mtmp;
      ztest0 = s[m] / mtmp;
      ztest = e[m] / mtmp;
      sqds = s[q] / mtmp;
      b = ((ztest0 + f) * (ztest0 - f) + ztest * ztest) / 2.0;
      ztest0 = f * ztest;
      ztest0 *= ztest0;
      if ((b != 0.0) || (ztest0 != 0.0)) {
        ztest = sqrt(b * b + ztest0);
        if (b < 0.0) {
          ztest = -ztest;
        }

        ztest = ztest0 / (b + ztest);
      } else {
        ztest = 0.0;
      }

      f = (sqds + f) * (sqds - f) + ztest;
      b = e[q] / mtmp * sqds;
      for (kase = q + 1; kase <= m + 1; kase++) {
        ctrl_TAPM_eml_xrotg(&f, &b, &ztest0, &ztest);
        if (kase > q + 1) {
          e[kase - 2] = f;
        }

        f = s[kase - 1] * ztest0 + e[kase - 1] * ztest;
        e[kase - 1] = e[kase - 1] * ztest0 - s[kase - 1] * ztest;
        b = ztest * s[kase];
        s[kase] *= ztest0;
        ctrl_TAPM_eml_xrot_k1(Vf, 1 + 12 * (kase - 1), 1 + 12 * kase, ztest0,
                              ztest);
        ctrl_TAPM_eml_xrotg(&f, &b, &ztest0, &ztest);
        s[kase - 1] = f;
        f = e[kase - 1] * ztest0 + ztest * s[kase];
        s[kase] = e[kase - 1] * -ztest + ztest0 * s[kase];
        b = ztest * e[kase];
        e[kase] *= ztest0;
        if (kase < 3) {
          ctrl_TAPM_eml_xrot_k(U, 1 + 3 * (kase - 1), 1 + 3 * kase, ztest0,
                               ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_TAPM_eml_xscal_ou(-1.0, Vf, 1 + 12 * q);
      }

      qp1 = q + 1;
      while ((q + 1 < 4) && (s[q] < s[qp1])) {
        ztest = s[q];
        s[q] = s[qp1];
        s[qp1] = ztest;
        ctrl_TAPM_eml_xswap_np(Vf, 1 + 12 * q, 1 + 12 * (q + 1));
        if (q + 1 < 3) {
          ctrl_TAPM_eml_xswap_n(U, 1 + 3 * q, 1 + 3 * (q + 1));
        }

        q = qp1;
        qp1++;
      }

      iter = 0;
      m--;
      break;
    }
  }

  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
  for (qp1 = 0; qp1 < 3; qp1++) {
    memcpy(&V[12 * qp1], &Vf[12 * qp1], 12U * sizeof(real_T));
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_svd_l(const real_T A[36], real_T U[9], real_T S[9], real_T
  V[36])
{
  real_T s[3];
  ctrl_TAPM_eml_xgesvd_a(A, U, s, V);
  memset(&S[0], 0, 9U * sizeof(real_T));
  S[0] = s[0];
  S[4] = s[1];
  S[8] = s[2];
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_abs(const real_T x[2], real_T y[2])
{
  y[0] = fabs(x[0]);
  y[1] = fabs(x[1]);
}

/* Function for MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */
static void ctrl_TAPM_cosd(real_T *x)
{
  int8_T n;
  real_T b_x;
  real_T absx;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    *x = (rtNaN);
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    if (n == 0) {
      *x = cos(b_x);
    } else if (n == 1) {
      *x = -sin(b_x);
    } else if (n == -1) {
      *x = sin(b_x);
    } else {
      *x = -cos(b_x);
    }
  }
}

/* Function for MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */
static void ctrl_TAPM_sind(real_T *x)
{
  int8_T n;
  real_T b_x;
  real_T absx;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    b_x = (rtNaN);
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    if (n == 0) {
      b_x = sin(b_x);
    } else if (n == 1) {
      b_x = cos(b_x);
    } else if (n == -1) {
      b_x = -cos(b_x);
    } else {
      b_x = -sin(b_x);
    }
  }

  *x = b_x;
}

void rt_invd6x6_snf(const real_T u[36], real_T y[36])
{
  int8_T p[6];
  int32_T c;
  real_T A[36];
  int8_T ipiv[6];
  int32_T j;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T jA;
  int32_T jBcol;
  int32_T kAcol;
  int32_T i;
  int32_T i_0;
  for (i_0 = 0; i_0 < 36; i_0++) {
    y[i_0] = 0.0;
    A[i_0] = u[i_0];
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    ipiv[i_0] = (int8_T)(1 + i_0);
  }

  for (j = 0; j < 5; j++) {
    c = j * 7;
    kAcol = j * 7;
    jBcol = 1;
    ix = c;
    smax = fabs(A[kAcol]);
    for (jA = 2; jA <= 6 - j; jA++) {
      ix++;
      s = fabs(A[ix]);
      if (s > smax) {
        jBcol = jA;
        smax = s;
      }
    }

    jBcol--;
    if (A[c + jBcol] != 0.0) {
      if (jBcol != 0) {
        ipiv[j] = (int8_T)((j + jBcol) + 1);
        ix = j;
        jBcol += j;
        for (jA = 0; jA < 6; jA++) {
          smax = A[ix];
          A[ix] = A[jBcol];
          A[jBcol] = smax;
          ix += 6;
          jBcol += 6;
        }
      }

      i_0 = c - j;
      for (i = c + 1; i + 1 <= i_0 + 6; i++) {
        A[i] /= A[c];
      }
    }

    jA = kAcol;
    jBcol = kAcol + 6;
    for (kAcol = 1; kAcol <= 5 - j; kAcol++) {
      if (A[jBcol] != 0.0) {
        smax = -A[jBcol];
        ix = c;
        i_0 = jA - j;
        for (i = jA + 7; i + 1 <= i_0 + 12; i++) {
          A[i] += A[ix + 1] * smax;
          ix++;
        }
      }

      jBcol += 6;
      jA += 6;
    }
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    p[i_0] = (int8_T)(1 + i_0);
  }

  for (jA = 0; jA < 5; jA++) {
    if (ipiv[jA] > 1 + jA) {
      jBcol = p[ipiv[jA] - 1];
      p[ipiv[jA] - 1] = p[jA];
      p[jA] = (int8_T)jBcol;
    }
  }

  for (jA = 0; jA < 6; jA++) {
    c = p[jA] - 1;
    y[jA + 6 * (p[jA] - 1)] = 1.0;
    for (j = jA; j + 1 < 7; j++) {
      if (y[6 * c + j] != 0.0) {
        for (i = j + 1; i + 1 < 7; i++) {
          y[i + 6 * c] -= y[6 * c + j] * A[6 * j + i];
        }
      }
    }
  }

  for (j = 0; j < 6; j++) {
    jBcol = 6 * j;
    for (jA = 5; jA >= 0; jA += -1) {
      kAcol = 6 * jA;
      if (y[jA + jBcol] != 0.0) {
        y[jA + jBcol] /= A[jA + kAcol];
        for (i = 0; i + 1 <= jA; i++) {
          y[i + jBcol] -= y[jA + jBcol] * A[i + kAcol];
        }
      }
    }
  }
}

boolean_T findpivotIdx_D(int32_T i, int32_T j, int32_T startIdx, int32_T pivot[],
  uint32_T midxPort[], const real_T mdataPort[])
{
  boolean_T pivotFind;
  int32_T mid;
  uint32_T sIdx;
  real_T tmp0;
  real_T tmp1;
  uint32_T t;

  /* S-Function (sdspmdn2): '<S31>/Median' */
  mid = (i + j) >> 1;
  sIdx = (uint32_T)startIdx;
  tmp0 = mdataPort[midxPort[i] + sIdx];
  tmp1 = mdataPort[midxPort[mid] + sIdx];
  if (tmp0 > mdataPort[midxPort[mid] + sIdx]) {
    t = midxPort[i];
    midxPort[i] = midxPort[mid];
    midxPort[mid] = t;
  }

  if (tmp0 > mdataPort[midxPort[j] + sIdx]) {
    t = midxPort[i];
    midxPort[i] = midxPort[j];
    midxPort[j] = t;
  }

  if (tmp1 > mdataPort[midxPort[j] + sIdx]) {
    t = midxPort[mid];
    midxPort[mid] = midxPort[j];
    midxPort[j] = t;
  }

  tmp0 = mdataPort[midxPort[i] + sIdx];
  tmp1 = mdataPort[midxPort[mid] + sIdx];
  pivotFind = false;
  if (tmp0 < tmp1) {
    pivot[0U] = mid;
    pivotFind = true;
  } else if (tmp1 < mdataPort[midxPort[j] + sIdx]) {
    pivot[0U] = j;
    pivotFind = true;
  } else {
    mid = i + 1;
    while ((mid <= j) && (!pivotFind)) {
      tmp1 = mdataPort[midxPort[mid] + sIdx];
      if (tmp1 != tmp0) {
        if (tmp1 < tmp0) {
          pivot[0U] = i;
        } else {
          pivot[0U] = mid;
        }

        pivotFind = true;
        mid = j + 1;
      }

      mid++;
    }
  }

  /* End of S-Function (sdspmdn2): '<S31>/Median' */
  return pivotFind;
}

int32_T partitionIdx_D(int32_T i, int32_T j, int32_T startIdx, const int32_T
  pivot[], uint32_T midxPort[], const real_T mdataPort[])
{
  int32_T idx;
  uint32_T sIdx;
  real_T tmp0;
  int32_T count;
  uint32_T t;

  /* S-Function (sdspmdn2): '<S31>/Median' */
  sIdx = (uint32_T)startIdx;
  tmp0 = mdataPort[midxPort[pivot[0U]] + sIdx];
  count = j - i;
  while ((i <= j) && (count >= 0)) {
    while (mdataPort[midxPort[i] + sIdx] < tmp0) {
      i++;
    }

    while (mdataPort[midxPort[j] + sIdx] >= tmp0) {
      j--;
    }

    if (i < j) {
      t = midxPort[i];
      midxPort[i] = midxPort[j];
      midxPort[j] = t;
      i++;
      j--;
    }

    count--;
  }

  idx = i;

  /* End of S-Function (sdspmdn2): '<S31>/Median' */
  return idx;
}

void MDNQSort_D(int32_T i, int32_T j, int32_T startIdx, uint32_T midxPort[],
                const real_T mdataPort[])
{
  int32_T pivot;

  /* S-Function (sdspmdn2): '<S31>/Median' */
  if (findpivotIdx_D(i, j, startIdx, &pivot, &midxPort[0U], &mdataPort[0U])) {
    pivot = partitionIdx_D(i, j, startIdx, &pivot, &midxPort[0U], &mdataPort[0U]);
    MDNQSort_D(i, pivot - 1, startIdx, &midxPort[0U], &mdataPort[0U]);
    MDNQSort_D(pivot, j, startIdx, &midxPort[0U], &mdataPort[0U]);
  }

  /* End of S-Function (sdspmdn2): '<S31>/Median' */
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_cosd_e(real_T *x)
{
  int8_T n;
  real_T b_x;
  real_T absx;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    *x = (rtNaN);
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    if (n == 0) {
      *x = cos(b_x);
    } else if (n == 1) {
      *x = -sin(b_x);
    } else if (n == -1) {
      *x = sin(b_x);
    } else {
      *x = -cos(b_x);
    }
  }
}

/* Function for MATLAB Function: '<S10>/MATLAB Function' */
static void ctrl_TAPM_sind_f(real_T *x)
{
  int8_T n;
  real_T b_x;
  real_T absx;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    b_x = (rtNaN);
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    absx = fabs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = fabs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    if (n == 0) {
      b_x = sin(b_x);
    } else if (n == 1) {
      b_x = cos(b_x);
    } else if (n == -1) {
      b_x = -cos(b_x);
    } else {
      b_x = -sin(b_x);
    }
  }

  *x = b_x;
}

/* Model output function */
void ctrl_TAPM_output(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator;
  real_T rtb_Integrator_h;
  real_T rtb_Integrator_a;
  real_T rtb_Integrator_k;
  real_T rtb_Integrator_c;
  real_T rtb_Integrator_m;
  real_T rtb_positivethrust2;
  real_T rtb_negativethrust2;
  real_T rtb_positivethrust3;
  real_T rtb_negativethrust3;
  real_T rtb_positivethrust4;
  real_T rtb_negativethrust4;
  real_T rtb_positivethrust5;
  real_T rtb_negativethrust5;
  real_T rtb_positivethrust6;
  real_T rtb_negativethrust6;
  real_T rtb_Integrator_g;
  real_T rtb_Integrator_f;
  real_T rtb_Integrator_hl;
  real_T rtb_Integrator_an;
  real_T rtb_Integrator_i;
  real_T rtb_Integrator_l;
  real_T rtb_T_r;
  real_T rtb_T_r_h;
  real_T rtb_T_r_e;
  real_T rtb_sys[12];
  real_T rtb_Memory2[5];
  real_T rtb_Memory3[7];
  real_T rtb_Merge[7];
  real_T rtb_Memory2_p[5];
  real_T rtb_Memory3_b[7];
  real_T rtb_Merge_i[7];
  real_T rtb_Memory2_g[5];
  real_T rtb_Memory3_m[7];
  real_T rtb_Merge_a[7];
  real_T rtb_Memory2_i[5];
  real_T rtb_Memory3_c[7];
  real_T rtb_Merge_c[7];
  real_T rtb_MatrixMultiply5[3];
  real_T rtb_MatrixMultiply2[3];
  real_T rtb_MatrixMultiply[3];
  real_T rtb_TmpSignalConversionAtToFi_i[6];
  real_T rtb_ImpSel_InsertedFor_reset_at;
  real_T rtb_TmpSignalConversionAtToFile[6];

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T s[6];
  real_T K[6];
  real_T B_surge[6];
  real_T S_singular_cross[9];
  real_T T0[12];
  real_T c1[2];
  real_T V_singular[18];
  real_T b_V_singular[36];
  real_T varargin_1[2];
  int32_T ixstart;
  int32_T b_ixstart;
  static const int8_T d[12] = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 };

  static const int8_T e[12] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };

  boolean_T f[9];
  boolean_T exitg11;
  real_T g;
  real_T h;
  real_T n;
  real_T o;
  real_T p;
  real_T q;
  real_T r;
  real_T s_0;
  real_T t;
  real_T u;
  real_T v;
  real_T w;
  real_T x;
  real_T y;
  int32_T p3;
  real_T rtb_Row2;
  real_T rtb_Row1;
  real_T rtb_psi_dot;
  real_T rtb_Row1_m;
  real_T rtb_y[6];
  real_T rtb_ImpAsg_InsertedFor_commande[6];
  real_T rtb_Sum3[3];
  real_T rtb_Sum_b;
  boolean_T rtb_RelationalOperator[28];
  real_T rtb_TmpSignalConversionAtSFu_ax[6];
  real_T rtb_TmpSignalConversionAtSFun_m[10];
  real_T rtb_commandedAngle_CoreSubsysCa;
  real_T rtb_Median1;
  real_T rtb_Abs[5];
  real_T rtb_Abs1;
  real_T rtb_Sum2_j[12];
  real_T rtb_Sum2_a[12];
  real_T rtb_Sum2_h[12];
  real_T rtb_y_j[9];
  real_T v1[144];
  real_T v1_0[144];
  real_T rtb_PHinvHPHR[72];
  real_T rtb_PHinvHPHR_o[72];
  real_T rtb_PHinvHPHR_i[72];
  real_T rtb_PHinvHPHR_du[72];
  real_T rtb_MathFunction4[144];
  real_T rtb_w_d[9];
  int32_T i;
  real_T c1_0[2];
  real_T c1_1[2];
  real_T c1_2[2];
  real_T c1_3[2];
  real_T c1_4[2];
  real_T c1_5[2];
  real_T d_0[36];
  boolean_T tmp[9];
  real_T B_surge_0[18];
  real_T B_surge_1[18];
  real_T tmp_0[3];
  real_T tmp_1[9];
  real_T tmp_2[9];
  real_T rtb_Row2_0[18];
  real_T tmp_3[72];
  real_T rtb_MathFunction4_0[144];
  real_T rtb_PHinvHPHR_d[144];
  real_T rtb_MathFunction4_1[144];
  real_T rtb_PHinvHPHR_e[144];
  real_T rtb_Sum5_0[144];
  int32_T b_data[9];
  int32_T c_data[9];
  real_T Alpha1_idx_4;
  real_T Alpha1_idx_3;
  real_T Alpha1_idx_2;
  real_T rtb_Sum_on_idx_1;
  real_T rtb_Sum_on_idx_0;
  real_T rtb_TmpSignalConversionAtSFun_0;
  real_T rtb_TmpSignalConversionAtSFun_1;
  real_T rtb_TmpSignalConversionAtSFun_2;
  real_T rtb_Sum_on_idx_2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* set solver stop time */
    if (!(ctrl_TAPM_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_TAPM_M->solverInfo,
                            ((ctrl_TAPM_M->Timing.clockTickH0 + 1) *
        ctrl_TAPM_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_TAPM_M->solverInfo,
                            ((ctrl_TAPM_M->Timing.clockTick0 + 1) *
        ctrl_TAPM_M->Timing.stepSize0 + ctrl_TAPM_M->Timing.clockTickH0 *
        ctrl_TAPM_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_TAPM_M)) {
    ctrl_TAPM_M->Timing.t[0] = rtsiGetT(&ctrl_TAPM_M->solverInfo);
  }

  /* MATLAB Function: '<S44>/Kp' */
  ctrl_TAPM_Kp(ctrl_TAPM_B.K_p_x, ctrl_TAPM_B.K_p_y, ctrl_TAPM_B.K_p_psi,
               &ctrl_TAPM_B.sf_Kp);

  /* Saturate: '<S18>/Saturation' incorporates:
   *  Fcn: '<S14>/yaw angle'
   */
  if (ctrl_TAPM_B.psi_m > ctrl_TAPM_P.Saturation_UpperSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation_UpperSat;
  } else if (ctrl_TAPM_B.psi_m < ctrl_TAPM_P.Saturation_LowerSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation_LowerSat;
  } else {
    rtb_Row2 = ctrl_TAPM_B.psi_m;
  }

  /* End of Saturate: '<S18>/Saturation' */

  /* Signum: '<S18>/Sign' */
  if (rtb_Row2 < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (rtb_Row2 > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (rtb_Row2 == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = rtb_Row2;
  }

  /* Gain: '<S18>/Gain' incorporates:
   *  Signum: '<S18>/Sign'
   */
  rtb_Row1 = ctrl_TAPM_P.Gain_Gain_p * rtb_TmpSignalConversionAtSFun_2;

  /* Sum: '<S18>/Sum1' */
  rtb_Row2 += rtb_Row1;

  /* Math: '<S18>/Math Function' incorporates:
   *  Constant: '<S18>/Constant'
   */
  rtb_Row2 = rt_remd_snf(rtb_Row2, ctrl_TAPM_P.Constant_Value_i);

  /* Sum: '<S18>/Sum' */
  rtb_Row2 -= rtb_Row1;

  /* MATLAB Function: '<S44>/Ki' */
  ctrl_TAPM_Ki(ctrl_TAPM_B.K_i_x, ctrl_TAPM_B.K_i_y, ctrl_TAPM_B.K_i_psi,
               &ctrl_TAPM_B.sf_Ki);

  /* MATLAB Function: '<S44>/Kd' */
  ctrl_TAPM_Kd(ctrl_TAPM_B.K_d_x, ctrl_TAPM_B.K_d_y, ctrl_TAPM_B.K_d_psi,
               &ctrl_TAPM_B.sf_Kd);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* MATLAB Function: '<S46>/Kd' incorporates:
     *  Constant: '<S46>/Constant6'
     *  Constant: '<S46>/Constant7'
     *  Constant: '<S46>/Constant8'
     */
    ctrl_TAPM_Kd(ctrl_TAPM_P.Constant6_Value_m, ctrl_TAPM_P.Constant7_Value,
                 ctrl_TAPM_P.Constant8_Value, &ctrl_TAPM_B.sf_Kd_p);
  }

  /* MATLAB Function: '<S45>/wd' incorporates:
   *  SignalConversion: '<S50>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Input1/Guidance gains/wd': '<S50>:1' */
  /* '<S50>:1:4' */
  memset(&rtb_w_d[0], 0, 9U * sizeof(real_T));
  rtb_w_d[0] = ctrl_TAPM_B.w_d_x;
  rtb_w_d[4] = ctrl_TAPM_B.w_d_y;
  rtb_w_d[8] = ctrl_TAPM_B.w_d_psi;

  /* Integrator: '<S19>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_TAPM_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_TAPM_DW.Integrator1_IWORK.IcNeedsLoading) {
      ctrl_TAPM_X.Integrator1_CSTATE[0] = 0.0;
      ctrl_TAPM_X.Integrator1_CSTATE[1] = 0.0;
      ctrl_TAPM_X.Integrator1_CSTATE[2] = 0.0;
    }
  }

  rtb_MatrixMultiply5[0] = ctrl_TAPM_X.Integrator1_CSTATE[0];
  rtb_MatrixMultiply5[1] = ctrl_TAPM_X.Integrator1_CSTATE[1];
  rtb_MatrixMultiply5[2] = ctrl_TAPM_X.Integrator1_CSTATE[2];

  /* Saturate: '<S20>/Saturation' */
  if (rtb_MatrixMultiply5[2] > ctrl_TAPM_P.Saturation_UpperSat_p) {
    rtb_Row1 = ctrl_TAPM_P.Saturation_UpperSat_p;
  } else if (rtb_MatrixMultiply5[2] < ctrl_TAPM_P.Saturation_LowerSat_a) {
    rtb_Row1 = ctrl_TAPM_P.Saturation_LowerSat_a;
  } else {
    rtb_Row1 = rtb_MatrixMultiply5[2];
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* Signum: '<S20>/Sign' */
  if (rtb_Row1 < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (rtb_Row1 > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (rtb_Row1 == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = rtb_Row1;
  }

  /* Gain: '<S20>/Gain' incorporates:
   *  Signum: '<S20>/Sign'
   */
  rtb_psi_dot = ctrl_TAPM_P.Gain_Gain_a * rtb_TmpSignalConversionAtSFun_2;

  /* Sum: '<S20>/Sum1' */
  rtb_Row1 += rtb_psi_dot;

  /* Math: '<S20>/Math Function' incorporates:
   *  Constant: '<S20>/Constant'
   */
  rtb_Row1 = rt_remd_snf(rtb_Row1, ctrl_TAPM_P.Constant_Value_j);

  /* Sum: '<S20>/Sum' */
  rtb_Row1 -= rtb_psi_dot;

  /* SignalConversion: '<S19>/TmpSignal ConversionAtMatrix Multiply2Inport2' */
  ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[0] = rtb_MatrixMultiply5[0];
  ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[1] = rtb_MatrixMultiply5[1];
  ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[2] = rtb_Row1;

  /* Sum: '<S14>/Sum2' */
  ctrl_TAPM_B.regulationerror[0] = ctrl_TAPM_B.x_m -
    ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[0];
  ctrl_TAPM_B.regulationerror[1] = ctrl_TAPM_B.y_m -
    ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[1];
  ctrl_TAPM_B.regulationerror[2] = ctrl_TAPM_B.psi_m -
    ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[2];

  /* Saturate: '<S17>/Saturation' */
  if (ctrl_TAPM_B.regulationerror[2] > ctrl_TAPM_P.Saturation_UpperSat_d) {
    rtb_psi_dot = ctrl_TAPM_P.Saturation_UpperSat_d;
  } else if (ctrl_TAPM_B.regulationerror[2] < ctrl_TAPM_P.Saturation_LowerSat_c)
  {
    rtb_psi_dot = ctrl_TAPM_P.Saturation_LowerSat_c;
  } else {
    rtb_psi_dot = ctrl_TAPM_B.regulationerror[2];
  }

  /* End of Saturate: '<S17>/Saturation' */

  /* Signum: '<S17>/Sign' */
  if (rtb_psi_dot < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (rtb_psi_dot > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (rtb_psi_dot == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = rtb_psi_dot;
  }

  /* Gain: '<S17>/Gain' incorporates:
   *  Signum: '<S17>/Sign'
   */
  rtb_Row1 = ctrl_TAPM_P.Gain_Gain_ag * rtb_TmpSignalConversionAtSFun_2;

  /* Sum: '<S17>/Sum1' */
  rtb_psi_dot += rtb_Row1;

  /* Math: '<S17>/Math Function' incorporates:
   *  Constant: '<S17>/Constant'
   */
  rtb_psi_dot = rt_remd_snf(rtb_psi_dot, ctrl_TAPM_P.Constant_Value_l);

  /* Sum: '<S17>/Sum' */
  rtb_psi_dot -= rtb_Row1;

  /* SignalConversion: '<S14>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Fcn: '<S15>/Row1'
   *  Fcn: '<S15>/Row2'
   *  Fcn: '<S15>/Row3'
   */
  ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_m[0] = cos(rtb_Row2) *
    ctrl_TAPM_B.regulationerror[0] + sin(rtb_Row2) *
    ctrl_TAPM_B.regulationerror[1];
  ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_m[1] = -sin(rtb_Row2) *
    ctrl_TAPM_B.regulationerror[0] + cos(rtb_Row2) *
    ctrl_TAPM_B.regulationerror[1];
  ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_m[2] = rtb_psi_dot;

  /* Product: '<S14>/Matrix Multiply' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_MatrixMultiply5[b_ixstart] = 0.0;
    rtb_MatrixMultiply5[b_ixstart] += ctrl_TAPM_B.sf_Kp.K_p[b_ixstart] *
      ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_m[0];
    rtb_MatrixMultiply5[b_ixstart] += ctrl_TAPM_B.sf_Kp.K_p[b_ixstart + 3] *
      ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_m[1];
    rtb_MatrixMultiply5[b_ixstart] += ctrl_TAPM_B.sf_Kp.K_p[b_ixstart + 6] *
      ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_m[2];
  }

  /* End of Product: '<S14>/Matrix Multiply' */

  /* Integrator: '<S14>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_TAPM_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE[0] = ctrl_TAPM_P.Integrator_IC;
      ctrl_TAPM_X.Integrator_CSTATE[1] = ctrl_TAPM_P.Integrator_IC;
      ctrl_TAPM_X.Integrator_CSTATE[2] = ctrl_TAPM_P.Integrator_IC;
    }
  }

  rtb_MatrixMultiply2[0] = ctrl_TAPM_X.Integrator_CSTATE[0];
  rtb_MatrixMultiply2[1] = ctrl_TAPM_X.Integrator_CSTATE[1];
  rtb_MatrixMultiply2[2] = ctrl_TAPM_X.Integrator_CSTATE[2];

  /* Product: '<S14>/Matrix Multiply1' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_MatrixMultiply[b_ixstart] = 0.0;
    rtb_MatrixMultiply[b_ixstart] += ctrl_TAPM_B.sf_Ki.K_i[b_ixstart] *
      rtb_MatrixMultiply2[0];
    rtb_MatrixMultiply[b_ixstart] += ctrl_TAPM_B.sf_Ki.K_i[b_ixstart + 3] *
      rtb_MatrixMultiply2[1];
    rtb_MatrixMultiply[b_ixstart] += ctrl_TAPM_B.sf_Ki.K_i[b_ixstart + 6] *
      rtb_MatrixMultiply2[2];
  }

  /* End of Product: '<S14>/Matrix Multiply1' */

  /* Integrator: '<S6>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator1_Reset_ZCE_i,
                       ctrl_TAPM_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator1_CSTATE_g[0] = (ctrl_TAPM_P.Integrator1_IC[0]);
      ctrl_TAPM_X.Integrator1_CSTATE_g[1] = (ctrl_TAPM_P.Integrator1_IC[1]);
      ctrl_TAPM_X.Integrator1_CSTATE_g[2] = (ctrl_TAPM_P.Integrator1_IC[2]);
    }
  }

  ctrl_TAPM_B.Integrator1[0] = ctrl_TAPM_X.Integrator1_CSTATE_g[0];
  ctrl_TAPM_B.Integrator1[1] = ctrl_TAPM_X.Integrator1_CSTATE_g[1];
  ctrl_TAPM_B.Integrator1[2] = ctrl_TAPM_X.Integrator1_CSTATE_g[2];

  /* Fcn: '<S14>/yaw angle1' */
  rtb_Row1_m = ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[2];

  /* Integrator: '<S19>/Integrator3' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator3_Reset_ZCE,
                       ctrl_TAPM_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator3_CSTATE[0] = ctrl_TAPM_P.Integrator3_IC;
      ctrl_TAPM_X.Integrator3_CSTATE[1] = ctrl_TAPM_P.Integrator3_IC;
      ctrl_TAPM_X.Integrator3_CSTATE[2] = ctrl_TAPM_P.Integrator3_IC;
    }
  }

  ctrl_TAPM_B.Integrator3[0] = ctrl_TAPM_X.Integrator3_CSTATE[0];
  ctrl_TAPM_B.Integrator3[1] = ctrl_TAPM_X.Integrator3_CSTATE[1];
  ctrl_TAPM_B.Integrator3[2] = ctrl_TAPM_X.Integrator3_CSTATE[2];

  /* Sum: '<S14>/Sum4' incorporates:
   *  Fcn: '<S16>/Row1'
   *  Fcn: '<S16>/Row2'
   *  Fcn: '<S16>/Row3'
   */
  rtb_MatrixMultiply2[0] = ctrl_TAPM_B.Integrator1[0] - (cos(rtb_Row1_m) *
    ctrl_TAPM_B.Integrator3[0] + sin(rtb_Row1_m) * ctrl_TAPM_B.Integrator3[1]);
  rtb_MatrixMultiply2[1] = ctrl_TAPM_B.Integrator1[1] - (-sin(rtb_Row1_m) *
    ctrl_TAPM_B.Integrator3[0] + cos(rtb_Row1_m) * ctrl_TAPM_B.Integrator3[1]);
  rtb_MatrixMultiply2[2] = ctrl_TAPM_B.Integrator1[2] - ctrl_TAPM_B.Integrator3
    [2];

  /* Sum: '<S14>/Sum3' incorporates:
   *  Product: '<S14>/Matrix Multiply2'
   */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_Sum3[b_ixstart] = ((0.0 - rtb_MatrixMultiply5[b_ixstart]) -
      rtb_MatrixMultiply[b_ixstart]) - ((ctrl_TAPM_B.sf_Kd.K_d[b_ixstart + 3] *
      rtb_MatrixMultiply2[1] + ctrl_TAPM_B.sf_Kd.K_d[b_ixstart] *
      rtb_MatrixMultiply2[0]) + ctrl_TAPM_B.sf_Kd.K_d[b_ixstart + 6] *
      rtb_MatrixMultiply2[2]);
  }

  /* End of Sum: '<S14>/Sum3' */

  /* SignalConversion: '<S69>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S10>/angle between  [-180 180]'
   */
  rtb_TmpSignalConversionAtSFu_ax[0] = ctrl_TAPM_B.thr_angle_1;
  rtb_TmpSignalConversionAtSFu_ax[1] = ctrl_TAPM_B.thr_angle_2;
  rtb_TmpSignalConversionAtSFu_ax[2] = ctrl_TAPM_B.thr_angle_3;
  rtb_TmpSignalConversionAtSFu_ax[3] = ctrl_TAPM_B.thr_angle_4;
  rtb_TmpSignalConversionAtSFu_ax[4] = ctrl_TAPM_B.thr_angle_5;
  rtb_TmpSignalConversionAtSFu_ax[5] = ctrl_TAPM_B.thr_angle_6;

  /* MATLAB Function: '<S10>/angle between  [-180 180]' */
  /* MATLAB Function 'Thrust allocation/angle between  [-180 180]': '<S69>:1' */
  /*  RAD2PIPI Converts an angle in rad to the interval (-pi pi] */
  /*           Should be applied to all heading errors in a feedback control system */
  /*           in order to avoid discontinuities. */
  /*  */
  /*  Author:     Roger Skjetne */
  /*  Date:       2003-09-05 */
  /*  Revisions:  2004-09-02 Thor I. Fossen - replaced input argument x with angle */
  /*              2005-01-05 Thor I. Fossen - ouput argument is set to y and not angle */
  /*              2005-04-13 Roger Skjetne  - changed the function s in order */
  /*                                          to account for correct mapping to */
  /*                                          (-pi pi]. */
  /*  */
  /*  ________________________________________________________________ */
  /*  */
  /*  MSS GNC is a Matlab toolbox for guidance, navigation and control. */
  /*  The toolbox is part of the Marine Systems Simulator (MSS). */
  /*  */
  /*  Copyright (C) 2008 Thor I. Fossen and Tristan Perez */
  /*   */
  /*  This program is free software: you can redistribute it and/or modify */
  /*  it under the terms of the GNU General Public License as published by */
  /*  the Free Software Foundation, either version 3 of the License, or */
  /*  (at your option) any later version. */
  /*   */
  /*  This program is distributed in the hope that it will be useful, but */
  /*  WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  */
  /*  GNU General Public License for more details. */
  /*   */
  /*  You should have received a copy of the GNU General Public License */
  /*  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
  /*   */
  /*  E-mail: contact@marinecontrol.org */
  /*  URL:    <http://www.marinecontrol.org> */
  /*  convert angle in rad to the interval <-pi pi>  */
  /* '<S69>:1:39' */
  /* '<S69>:1:40' */
  /*  s = sign(angle); */
  /* '<S69>:1:43' */
  for (i = 0; i < 6; i++) {
    rtb_TmpSignalConversionAtSFun_1 = rt_remd_snf
      (rtb_TmpSignalConversionAtSFu_ax[i] + 3.1415926535897931,
       6.2831853071795862) / 6.2831853071795862;
    rtb_TmpSignalConversionAtSFun_2 = fabs(rtb_TmpSignalConversionAtSFun_1);
    if (rtb_TmpSignalConversionAtSFun_2 > 0.0) {
      rtb_TmpSignalConversionAtSFun_2 = 1.0;
    } else {
      if (rtb_TmpSignalConversionAtSFun_2 == 0.0) {
        rtb_TmpSignalConversionAtSFun_2 = 0.0;
      }
    }

    if (rtb_TmpSignalConversionAtSFu_ax[i] < 0.0) {
      rtb_TmpSignalConversionAtSFun_0 = -1.0;
    } else if (rtb_TmpSignalConversionAtSFu_ax[i] > 0.0) {
      rtb_TmpSignalConversionAtSFun_0 = 1.0;
    } else if (rtb_TmpSignalConversionAtSFu_ax[i] == 0.0) {
      rtb_TmpSignalConversionAtSFun_0 = 0.0;
    } else {
      rtb_TmpSignalConversionAtSFun_0 = rtb_TmpSignalConversionAtSFu_ax[i];
    }

    s_0 = (rtb_TmpSignalConversionAtSFun_2 - 1.0) * 2.0 +
      rtb_TmpSignalConversionAtSFun_0;
    if (s_0 < 0.0) {
      s_0 = -1.0;
    } else if (s_0 > 0.0) {
      s_0 = 1.0;
    } else {
      if (s_0 == 0.0) {
        s_0 = 0.0;
      }
    }

    if (rtb_TmpSignalConversionAtSFu_ax[i] < 0.0) {
      rtb_TmpSignalConversionAtSFun_0 = -1.0;
    } else if (rtb_TmpSignalConversionAtSFu_ax[i] > 0.0) {
      rtb_TmpSignalConversionAtSFun_0 = 1.0;
    } else if (rtb_TmpSignalConversionAtSFu_ax[i] == 0.0) {
      rtb_TmpSignalConversionAtSFun_0 = 0.0;
    } else {
      rtb_TmpSignalConversionAtSFun_0 = rtb_TmpSignalConversionAtSFu_ax[i];
    }

    rtb_y[i] = rt_remd_snf(rtb_TmpSignalConversionAtSFun_0 * 3.1415926535897931
      + rtb_TmpSignalConversionAtSFu_ax[i], 6.2831853071795862) - s_0 *
      3.1415926535897931;
    rtb_TmpSignalConversionAtSFu_ax[i] = rtb_TmpSignalConversionAtSFun_1;
  }

  /* SignalConversion: '<S66>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Gain: '<S68>/Gain'
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  rtb_TmpSignalConversionAtSFun_m[0] = rtb_Sum3[0];
  rtb_TmpSignalConversionAtSFun_m[1] = rtb_Sum3[1];
  rtb_TmpSignalConversionAtSFun_m[2] = rtb_Sum3[2];
  for (i = 0; i < 6; i++) {
    rtb_TmpSignalConversionAtSFun_m[i + 3] = ctrl_TAPM_P.Gain_Gain_o * rtb_y[i];
  }

  /* End of SignalConversion: '<S66>/TmpSignal ConversionAt SFunction Inport1' */

  /* MATLAB Function: '<S10>/MATLAB Function' incorporates:
   *  Constant: '<S10>/C'
   *  Constant: '<S10>/X-position Thruster'
   *  Constant: '<S10>/Y-position Thruster'
   */
  /* MATLAB Function 'Thrust allocation/MATLAB Function': '<S66>:1' */
  /*  Complete system goes here! */
  /*  Allocating dimensions for faster computing */
  /*  Parameters thrusters */
  /* '<S66>:1:5' */
  rtb_TmpSignalConversionAtSFun_2 = rtb_TmpSignalConversionAtSFun_m[0];
  rtb_TmpSignalConversionAtSFun_1 = rtb_TmpSignalConversionAtSFun_m[1];
  rtb_TmpSignalConversionAtSFun_0 = rtb_TmpSignalConversionAtSFun_m[2];

  /* '<S66>:1:6' */
  rtb_TmpSignalConversionAtSFu_ax[0] = rtb_TmpSignalConversionAtSFun_m[3];
  rtb_TmpSignalConversionAtSFu_ax[1] = rtb_TmpSignalConversionAtSFun_m[4];
  rtb_TmpSignalConversionAtSFu_ax[2] = rtb_TmpSignalConversionAtSFun_m[5];
  rtb_TmpSignalConversionAtSFu_ax[3] = rtb_TmpSignalConversionAtSFun_m[6];
  rtb_TmpSignalConversionAtSFu_ax[4] = rtb_TmpSignalConversionAtSFun_m[7];
  rtb_TmpSignalConversionAtSFu_ax[5] = rtb_TmpSignalConversionAtSFun_m[8];

  /*  Constraints for Thruster-Thruster interaction. Can be seen in "Initfile" */
  /*  how they are found */
  /* '<S66>:1:10' */
  /* '<S66>:1:11' */
  /* '<S66>:1:12' */
  /* '<S66>:1:13' */
  /* '<S66>:1:14' */
  /* '<S66>:1:15' */
  if (((rtb_TmpSignalConversionAtSFun_m[3] < ctrl_TAPM_P.C[0] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[3] > ctrl_TAPM_P.C[6] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_m[3] > ctrl_TAPM_P.C[12] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[3] < ctrl_TAPM_P.C[18] - 0.1))) {
    /* '<S66>:1:21' */
    /* '<S66>:1:22' */
    K[0] = 0.0;
  } else {
    /* '<S66>:1:24' */
    K[0] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_m[4] > ctrl_TAPM_P.C[1] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[4] < ctrl_TAPM_P.C[7] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_m[4] > ctrl_TAPM_P.C[13] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[4] < ctrl_TAPM_P.C[19] + 0.1))) {
    /* '<S66>:1:27' */
    /* '<S66>:1:28' */
    K[1] = 0.0;
  } else {
    /* '<S66>:1:30' */
    K[1] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_m[5] < ctrl_TAPM_P.C[2] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[5] > ctrl_TAPM_P.C[8] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_m[5] < ctrl_TAPM_P.C[14] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[5] > ctrl_TAPM_P.C[20] - 0.1))) {
    /* '<S66>:1:33' */
    /* '<S66>:1:34' */
    K[2] = 0.0;
  } else {
    /* '<S66>:1:36' */
    K[2] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_m[6] > ctrl_TAPM_P.C[3] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[6] < ctrl_TAPM_P.C[9] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_m[6] < ctrl_TAPM_P.C[15] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[6] > ctrl_TAPM_P.C[21] + 0.1))) {
    /* '<S66>:1:39' */
    /* '<S66>:1:40' */
    K[3] = 0.0;
  } else {
    /* '<S66>:1:42' */
    K[3] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_m[7] < ctrl_TAPM_P.C[4] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[7] > ctrl_TAPM_P.C[10] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_m[7] < ctrl_TAPM_P.C[16] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[7] > ctrl_TAPM_P.C[22] + 0.1))) {
    /* '<S66>:1:45' */
    /* '<S66>:1:46' */
    K[4] = 0.0;
  } else {
    /* '<S66>:1:48' */
    K[4] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_m[8] > ctrl_TAPM_P.C[5] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[8] < ctrl_TAPM_P.C[11] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_m[8] > ctrl_TAPM_P.C[17] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[8] < ctrl_TAPM_P.C[23] - 0.1))) {
    /* '<S66>:1:51' */
    /* '<S66>:1:52' */
    K[5] = 0.0;
  } else {
    /* '<S66>:1:54' */
    K[5] = 1.0;
  }

  /*  number of thrusters */
  /* '<S66>:1:60' */
  /*  Shells for faster computing */
  /* '<S66>:1:61' */
  /*  Shells for faster computing */
  /* '<S66>:1:62' */
  /*  Shells for faster computing */
  /* '<S66>:1:64' */
  for (ixstart = 0; ixstart < 6; ixstart++) {
    /* '<S66>:1:64' */
    /* '<S66>:1:65' */
    B_surge[ixstart] = rtb_TmpSignalConversionAtSFu_ax[ixstart];
    ctrl_TAPM_cosd_e(&B_surge[ixstart]);

    /* Thrust in x-direction for cartesian */
    /* '<S66>:1:66' */
    rtb_y[ixstart] = rtb_TmpSignalConversionAtSFu_ax[ixstart];
    ctrl_TAPM_sind_f(&rtb_y[ixstart]);

    /* Thrust in y-direction for cartesian */
    /* '<S66>:1:67' */
    g = rtb_TmpSignalConversionAtSFu_ax[ixstart];
    ctrl_TAPM_sind_f(&g);
    h = rtb_TmpSignalConversionAtSFu_ax[ixstart];
    ctrl_TAPM_cosd_e(&h);
    s[ixstart] = g * ctrl_TAPM_P.XpositionThruster_Value[ixstart] - h *
      ctrl_TAPM_P.YpositionThruster_Value[ixstart];

    /* '<S66>:1:64' */
  }

  /* '<S66>:1:71' */
  /* '<S66>:1:72' */
  ctrl_TAPM_diag(K, d_0);
  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    B_surge_1[3 * b_ixstart] = B_surge[b_ixstart];
  }

  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    B_surge_1[1 + 3 * b_ixstart] = rtb_y[b_ixstart];
  }

  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    B_surge_1[2 + 3 * b_ixstart] = s[b_ixstart];
  }

  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    for (i = 0; i < 6; i++) {
      B_surge_0[b_ixstart + 3 * i] = 0.0;
      for (p3 = 0; p3 < 6; p3++) {
        B_surge_0[b_ixstart + 3 * i] += B_surge_1[3 * p3 + b_ixstart] * d_0[6 *
          i + p3];
      }
    }
  }

  ctrl_TAPM_svd(B_surge_0, rtb_y_j, S_singular_cross, V_singular);

  /* '<S66>:1:74' */
  for (b_ixstart = 0; b_ixstart < 9; b_ixstart++) {
    S_singular_cross[b_ixstart] = 1.0 / S_singular_cross[b_ixstart];
  }

  /* '<S66>:1:75' */
  ctrl_TAPM_isfinite(S_singular_cross, tmp);
  ixstart = 0;
  for (b_ixstart = 0; b_ixstart < 9; b_ixstart++) {
    exitg11 = !tmp[b_ixstart];
    if (exitg11) {
      ixstart++;
    }

    f[b_ixstart] = exitg11;
  }

  i = ixstart;
  ixstart = 0;
  for (b_ixstart = 0; b_ixstart < 9; b_ixstart++) {
    if (f[b_ixstart]) {
      b_data[ixstart] = b_ixstart + 1;
      ixstart++;
    }
  }

  /* '<S66>:1:75' */
  for (b_ixstart = 0; b_ixstart < i; b_ixstart++) {
    S_singular_cross[b_data[b_ixstart] - 1] = 0.0;
  }

  if (S_singular_cross[8] > 10.0 * S_singular_cross[4]) {
    /* '<S66>:1:76' */
    /* '<S66>:1:77' */
    S_singular_cross[8] = 0.0;
  }

  /* '<S66>:1:80' */
  /* '<S66>:1:82' */
  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      B_surge_1[b_ixstart + 6 * i] = 0.0;
      B_surge_1[b_ixstart + 6 * i] += S_singular_cross[3 * i] *
        V_singular[b_ixstart];
      B_surge_1[b_ixstart + 6 * i] += S_singular_cross[3 * i + 1] *
        V_singular[b_ixstart + 6];
      B_surge_1[b_ixstart + 6 * i] += S_singular_cross[3 * i + 2] *
        V_singular[b_ixstart + 12];
    }
  }

  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      V_singular[b_ixstart + 6 * i] = 0.0;
      V_singular[b_ixstart + 6 * i] += B_surge_1[b_ixstart] * rtb_y_j[i];
      V_singular[b_ixstart + 6 * i] += B_surge_1[b_ixstart + 6] * rtb_y_j[i + 3];
      V_singular[b_ixstart + 6 * i] += B_surge_1[b_ixstart + 12] * rtb_y_j[i + 6];
    }
  }

  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    B_surge[b_ixstart] = V_singular[b_ixstart + 12] *
      rtb_TmpSignalConversionAtSFun_0 + (V_singular[b_ixstart + 6] *
      rtb_TmpSignalConversionAtSFun_1 + V_singular[b_ixstart] *
      rtb_TmpSignalConversionAtSFun_2);
  }

  /*  Optimized Thrust */
  /* '<S66>:1:86' */
  for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
    d_0[3 * b_ixstart] = d[b_ixstart];
  }

  for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
    d_0[1 + 3 * b_ixstart] = e[b_ixstart];
  }

  d_0[2] = ctrl_TAPM_P.YpositionThruster_Value[0];
  d_0[5] = ctrl_TAPM_P.XpositionThruster_Value[0];
  d_0[8] = ctrl_TAPM_P.YpositionThruster_Value[1];
  d_0[11] = ctrl_TAPM_P.XpositionThruster_Value[1];
  d_0[14] = ctrl_TAPM_P.YpositionThruster_Value[2];
  d_0[17] = ctrl_TAPM_P.XpositionThruster_Value[2];
  d_0[20] = ctrl_TAPM_P.YpositionThruster_Value[3];
  d_0[23] = ctrl_TAPM_P.XpositionThruster_Value[3];
  d_0[26] = ctrl_TAPM_P.YpositionThruster_Value[4];
  d_0[29] = ctrl_TAPM_P.XpositionThruster_Value[4];
  d_0[32] = ctrl_TAPM_P.YpositionThruster_Value[5];
  d_0[35] = ctrl_TAPM_P.XpositionThruster_Value[5];
  ctrl_TAPM_svd_l(d_0, rtb_y_j, S_singular_cross, b_V_singular);

  /* '<S66>:1:92' */
  for (b_ixstart = 0; b_ixstart < 9; b_ixstart++) {
    S_singular_cross[b_ixstart] = 1.0 / S_singular_cross[b_ixstart];
  }

  /* '<S66>:1:93' */
  ctrl_TAPM_isfinite(S_singular_cross, tmp);
  ixstart = 0;
  for (b_ixstart = 0; b_ixstart < 9; b_ixstart++) {
    exitg11 = !tmp[b_ixstart];
    if (exitg11) {
      ixstart++;
    }

    f[b_ixstart] = exitg11;
  }

  i = ixstart;
  ixstart = 0;
  for (b_ixstart = 0; b_ixstart < 9; b_ixstart++) {
    if (f[b_ixstart]) {
      c_data[ixstart] = b_ixstart + 1;
      ixstart++;
    }
  }

  /* '<S66>:1:93' */
  for (b_ixstart = 0; b_ixstart < i; b_ixstart++) {
    S_singular_cross[c_data[b_ixstart] - 1] = 0.0;
  }

  if (S_singular_cross[8] > 2.0 * S_singular_cross[4]) {
    /* '<S66>:1:94' */
    /* '<S66>:1:95' */
    S_singular_cross[8] = 0.0;
  }

  /* '<S66>:1:97' */
  for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      d_0[b_ixstart + 12 * i] = 0.0;
      d_0[b_ixstart + 12 * i] += S_singular_cross[3 * i] *
        b_V_singular[b_ixstart];
      d_0[b_ixstart + 12 * i] += S_singular_cross[3 * i + 1] *
        b_V_singular[b_ixstart + 12];
      d_0[b_ixstart + 12 * i] += S_singular_cross[3 * i + 2] *
        b_V_singular[b_ixstart + 24];
    }
  }

  for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      b_V_singular[b_ixstart + 12 * i] = 0.0;
      b_V_singular[b_ixstart + 12 * i] += d_0[b_ixstart] * rtb_y_j[i];
      b_V_singular[b_ixstart + 12 * i] += d_0[b_ixstart + 12] * rtb_y_j[i + 3];
      b_V_singular[b_ixstart + 12 * i] += d_0[b_ixstart + 24] * rtb_y_j[i + 6];
    }
  }

  for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
    T0[b_ixstart] = b_V_singular[b_ixstart + 24] *
      rtb_TmpSignalConversionAtSFun_0 + (b_V_singular[b_ixstart + 12] *
      rtb_TmpSignalConversionAtSFun_1 + b_V_singular[b_ixstart] *
      rtb_TmpSignalConversionAtSFun_2);
  }

  /* '<S66>:1:99' */
  K[0] = 57.295779513082323 * rt_atan2d_snf(T0[1], T0[0]);
  K[1] = 57.295779513082323 * rt_atan2d_snf(T0[3], T0[2]);
  K[2] = 57.295779513082323 * rt_atan2d_snf(T0[5], T0[4]);
  K[3] = 57.295779513082323 * rt_atan2d_snf(T0[7], T0[6]);
  K[4] = 57.295779513082323 * rt_atan2d_snf(T0[9], T0[8]);
  K[5] = 57.295779513082323 * rt_atan2d_snf(T0[11], T0[10]);

  /* % Constraints */
  /*  Thruster 1 OK */
  /* C1 = [151 130 -151 -130 ]; */
  if (((K[0] < ctrl_TAPM_P.C[0]) && (K[0] > ctrl_TAPM_P.C[6]) && (B_surge[0] >
        0.0)) || ((K[0] < ctrl_TAPM_P.C[0]) && (K[0] > ctrl_TAPM_P.C[6]) &&
                  (B_surge[0] < 0.0))) {
    /* '<S66>:1:105' */
    /* '<S66>:1:106' */
    c1[0] = ctrl_TAPM_P.C[0];
    c1[1] = ctrl_TAPM_P.C[6];
    c1_5[0] = ctrl_TAPM_P.C[0] - K[0];
    c1_5[1] = ctrl_TAPM_P.C[6] - K[0];
    ctrl_TAPM_abs(c1_5, varargin_1);
    b_ixstart = 1;
    rtb_Row2 = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        b_ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row2 = varargin_1[1];
          ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((b_ixstart < 2) && (varargin_1[1] < rtb_Row2)) {
      ixstart = 1;
    }

    /* '<S66>:1:108' */
    rtb_TmpSignalConversionAtSFun_1 = c1[ixstart];
  } else if (((K[0] > ctrl_TAPM_P.C[12]) && (K[0] < ctrl_TAPM_P.C[18]) &&
              (B_surge[0] > 0.0)) || ((K[0] > ctrl_TAPM_P.C[12]) && (K[0] <
               ctrl_TAPM_P.C[18]) && (B_surge[0] < 0.0))) {
    /* '<S66>:1:109' */
    /* '<S66>:1:110' */
    c1[0] = ctrl_TAPM_P.C[12];
    c1[1] = ctrl_TAPM_P.C[18];
    c1_5[0] = ctrl_TAPM_P.C[12] - K[0];
    c1_5[1] = ctrl_TAPM_P.C[18] - K[0];
    ctrl_TAPM_abs(c1_5, varargin_1);
    ixstart = 1;
    rtb_Row2 = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row2 = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Row2)) {
      i = 1;
    }

    /* '<S66>:1:112' */
    rtb_TmpSignalConversionAtSFun_1 = c1[i];
  } else {
    /* '<S66>:1:114' */
    rtb_TmpSignalConversionAtSFun_1 = K[0];
  }

  if (((rtb_TmpSignalConversionAtSFun_m[3] < ctrl_TAPM_P.C[0] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[3] > ctrl_TAPM_P.C[6] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_m[3] > ctrl_TAPM_P.C[12] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[3] < ctrl_TAPM_P.C[18] - 0.1))) {
    /* '<S66>:1:116' */
    /* '<S66>:1:117' */
    B_surge[0] = 0.0;
  } else {
    /* '<S66>:1:119' */
  }

  /*  Thruster 2  */
  /* C2 = [-99.85 -80.15 -50 -29]; */
  if (((K[1] < ctrl_TAPM_P.C[1]) && (K[1] > ctrl_TAPM_P.C[7]) && (B_surge[1] >
        0.0)) || ((K[1] < ctrl_TAPM_P.C[1]) && (K[1] > ctrl_TAPM_P.C[7]) &&
                  (B_surge[1] < 0.0))) {
    /* '<S66>:1:124' */
    /* '<S66>:1:125' */
    c1[0] = ctrl_TAPM_P.C[1];
    c1[1] = ctrl_TAPM_P.C[7];
    c1_4[0] = ctrl_TAPM_P.C[1] - K[1];
    c1_4[1] = ctrl_TAPM_P.C[7] - K[1];
    ctrl_TAPM_abs(c1_4, varargin_1);
    ixstart = 1;
    rtb_Row2 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row2 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Row2)) {
      b_ixstart = 1;
    }

    /* '<S66>:1:127' */
    rtb_TmpSignalConversionAtSFun_0 = c1[b_ixstart];
  } else if (((K[1] < ctrl_TAPM_P.C[13]) && (K[1] > ctrl_TAPM_P.C[19]) &&
              (B_surge[1] > 0.0)) || ((K[1] < ctrl_TAPM_P.C[13]) && (K[1] >
               ctrl_TAPM_P.C[19]) && (B_surge[1] < 0.0))) {
    /* '<S66>:1:128' */
    /* '<S66>:1:129' */
    c1[0] = ctrl_TAPM_P.C[13];
    c1[1] = ctrl_TAPM_P.C[19];
    c1_4[0] = ctrl_TAPM_P.C[13] - K[1];
    c1_4[1] = ctrl_TAPM_P.C[19] - K[1];
    ctrl_TAPM_abs(c1_4, varargin_1);
    ixstart = 1;
    rtb_Row2 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row2 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Row2)) {
      b_ixstart = 1;
    }

    /* '<S66>:1:131' */
    rtb_TmpSignalConversionAtSFun_0 = c1[b_ixstart];
  } else {
    /* '<S66>:1:133' */
    rtb_TmpSignalConversionAtSFun_0 = K[1];
  }

  if (((rtb_TmpSignalConversionAtSFun_m[4] < ctrl_TAPM_P.C[1] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[4] > ctrl_TAPM_P.C[7] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_m[4] < ctrl_TAPM_P.C[13] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[4] > ctrl_TAPM_P.C[19] + 0.1))) {
    /* '<S66>:1:135' */
    /* '<S66>:1:136' */
    B_surge[1] = 0.0;
  } else {
    /* '<S66>:1:138' */
  }

  /*  Thruster 3  */
  /*  C3 = [99.85 80.15 50 29];  */
  if (((K[2] > ctrl_TAPM_P.C[2]) && (K[2] < ctrl_TAPM_P.C[8]) && (B_surge[2] >
        0.0)) || ((K[2] > ctrl_TAPM_P.C[2]) && (K[2] < ctrl_TAPM_P.C[8]) &&
                  (B_surge[2] < 0.0))) {
    /* '<S66>:1:144' */
    /* '<S66>:1:145' */
    c1[0] = ctrl_TAPM_P.C[2];
    c1[1] = ctrl_TAPM_P.C[8];
    c1_3[0] = ctrl_TAPM_P.C[2] - K[2];
    c1_3[1] = ctrl_TAPM_P.C[8] - K[2];
    ctrl_TAPM_abs(c1_3, varargin_1);
    ixstart = 1;
    rtb_Row2 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row2 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Row2)) {
      b_ixstart = 1;
    }

    /* '<S66>:1:147' */
    Alpha1_idx_2 = c1[b_ixstart];
  } else if (((K[2] > ctrl_TAPM_P.C[14]) && (K[2] < ctrl_TAPM_P.C[20]) &&
              (B_surge[2] > 0.0)) || ((K[2] > ctrl_TAPM_P.C[14]) && (K[2] <
               ctrl_TAPM_P.C[20]) && (B_surge[2] < 0.0))) {
    /* '<S66>:1:148' */
    /* '<S66>:1:149' */
    c1[0] = ctrl_TAPM_P.C[14];
    c1[1] = ctrl_TAPM_P.C[20];
    c1_3[0] = ctrl_TAPM_P.C[14] - K[2];
    c1_3[1] = ctrl_TAPM_P.C[20] - K[2];
    ctrl_TAPM_abs(c1_3, varargin_1);
    ixstart = 1;
    rtb_Row2 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row2 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Row2)) {
      b_ixstart = 1;
    }

    /* '<S66>:1:151' */
    Alpha1_idx_2 = c1[b_ixstart];
  } else {
    /* '<S66>:1:153' */
    Alpha1_idx_2 = K[2];
  }

  if (((rtb_TmpSignalConversionAtSFun_m[5] > ctrl_TAPM_P.C[2] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[5] < ctrl_TAPM_P.C[8] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_m[5] > ctrl_TAPM_P.C[14] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[5] < ctrl_TAPM_P.C[20] - 0.1))) {
    /* '<S66>:1:155' */
    /* '<S66>:1:156' */
    B_surge[2] = 0.0;
  } else {
    /* '<S66>:1:158' */
  }

  /*  Thruster 4 OK */
  /* C4 = [-52.8 -34.2 52.8 34.2];  */
  if (((K[3] > ctrl_TAPM_P.C[3]) && (K[3] < ctrl_TAPM_P.C[9]) && (B_surge[3] >
        0.0)) || ((K[3] > ctrl_TAPM_P.C[3]) && (K[3] < ctrl_TAPM_P.C[9]) &&
                  (B_surge[3] < 0.0))) {
    /* '<S66>:1:163' */
    /* '<S66>:1:164' */
    c1[0] = ctrl_TAPM_P.C[3];
    c1[1] = ctrl_TAPM_P.C[9];
    c1_2[0] = ctrl_TAPM_P.C[3] - K[3];
    c1_2[1] = ctrl_TAPM_P.C[9] - K[3];
    ctrl_TAPM_abs(c1_2, varargin_1);
    ixstart = 1;
    rtb_Row2 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row2 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Row2)) {
      b_ixstart = 1;
    }

    /* '<S66>:1:166' */
    Alpha1_idx_3 = c1[b_ixstart];
  } else if (((K[3] < ctrl_TAPM_P.C[15]) && (K[3] > ctrl_TAPM_P.C[21]) &&
              (B_surge[3] > 0.0)) || ((K[3] < ctrl_TAPM_P.C[15]) && (K[3] >
               ctrl_TAPM_P.C[21]) && (B_surge[3] < 0.0))) {
    /* '<S66>:1:167' */
    /* '<S66>:1:168' */
    c1[0] = ctrl_TAPM_P.C[15];
    c1[1] = ctrl_TAPM_P.C[21];
    c1_2[0] = ctrl_TAPM_P.C[15] - K[3];
    c1_2[1] = ctrl_TAPM_P.C[21] - K[3];
    ctrl_TAPM_abs(c1_2, varargin_1);
    ixstart = 1;
    rtb_Row2 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row2 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Row2)) {
      b_ixstart = 1;
    }

    /* '<S66>:1:170' */
    Alpha1_idx_3 = c1[b_ixstart];
  } else {
    /* '<S66>:1:172' */
    Alpha1_idx_3 = K[3];
  }

  if (((rtb_TmpSignalConversionAtSFun_m[6] > ctrl_TAPM_P.C[3] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[6] < ctrl_TAPM_P.C[9] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_m[6] < ctrl_TAPM_P.C[15] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[6] > ctrl_TAPM_P.C[21] + 0.1))) {
    /* '<S66>:1:174' */
    /* '<S66>:1:175' */
    B_surge[3] = 0.0;
  } else {
    /* '<S66>:1:177' */
  }

  /*  Thruster 5 */
  /* C5 = [-98.25 -81.75 -145.8 -127.2]; */
  if (((K[4] < ctrl_TAPM_P.C[4]) && (K[4] > ctrl_TAPM_P.C[10]) && (B_surge[4] >
        0.0)) || ((K[4] < ctrl_TAPM_P.C[4]) && (K[4] > ctrl_TAPM_P.C[10]) &&
                  (B_surge[4] < 0.0))) {
    /* '<S66>:1:182' */
    /* '<S66>:1:183' */
    c1[0] = ctrl_TAPM_P.C[4];
    c1[1] = ctrl_TAPM_P.C[10];
    c1_1[0] = ctrl_TAPM_P.C[4] - K[4];
    c1_1[1] = ctrl_TAPM_P.C[10] - K[4];
    ctrl_TAPM_abs(c1_1, varargin_1);
    ixstart = 1;
    rtb_Row2 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row2 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Row2)) {
      b_ixstart = 1;
    }

    /* '<S66>:1:185' */
    Alpha1_idx_4 = c1[b_ixstart];
  } else if (((K[4] < ctrl_TAPM_P.C[16]) && (K[4] > ctrl_TAPM_P.C[22]) &&
              (B_surge[4] > 0.0)) || ((K[4] < ctrl_TAPM_P.C[16]) && (K[4] >
               ctrl_TAPM_P.C[22]) && (B_surge[4] < 0.0))) {
    /* '<S66>:1:186' */
    /* '<S66>:1:187' */
    c1[0] = ctrl_TAPM_P.C[16];
    c1[1] = ctrl_TAPM_P.C[22];
    c1_1[0] = ctrl_TAPM_P.C[16] - K[4];
    c1_1[1] = ctrl_TAPM_P.C[22] - K[4];
    ctrl_TAPM_abs(c1_1, varargin_1);
    ixstart = 1;
    rtb_Row2 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row2 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Row2)) {
      b_ixstart = 1;
    }

    /* '<S66>:1:189' */
    Alpha1_idx_4 = c1[b_ixstart];
  } else {
    /* '<S66>:1:191' */
    Alpha1_idx_4 = K[4];
  }

  if (((rtb_TmpSignalConversionAtSFun_m[7] < ctrl_TAPM_P.C[4] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[7] > ctrl_TAPM_P.C[10] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_m[7] < ctrl_TAPM_P.C[16] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[7] > ctrl_TAPM_P.C[22] + 0.1))) {
    /* '<S66>:1:193' */
    /* '<S66>:1:194' */
    B_surge[4] = 0.0;
  } else {
    /* '<S66>:1:196' */
  }

  /*  Thruster 6 */
  /* C6 = [98.75 81.75 145.8 127.2]; */
  if (((K[5] > ctrl_TAPM_P.C[5]) && (K[5] < ctrl_TAPM_P.C[11]) && (B_surge[5] >
        0.0)) || ((K[5] > ctrl_TAPM_P.C[5]) && (K[5] < ctrl_TAPM_P.C[11]) &&
                  (B_surge[5] < 0.0))) {
    /* '<S66>:1:201' */
    /* '<S66>:1:202' */
    c1[0] = ctrl_TAPM_P.C[5];
    c1[1] = ctrl_TAPM_P.C[11];
    c1_0[0] = ctrl_TAPM_P.C[5] - K[5];
    c1_0[1] = ctrl_TAPM_P.C[11] - K[5];
    ctrl_TAPM_abs(c1_0, varargin_1);
    ixstart = 1;
    rtb_Row2 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row2 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Row2)) {
      b_ixstart = 1;
    }

    /* '<S66>:1:204' */
    rtb_TmpSignalConversionAtSFun_2 = c1[b_ixstart];
  } else if (((K[5] > ctrl_TAPM_P.C[17]) && (K[5] < ctrl_TAPM_P.C[23]) &&
              (B_surge[5] > 0.0)) || ((K[5] > ctrl_TAPM_P.C[17]) && (K[5] <
               ctrl_TAPM_P.C[23]) && (B_surge[5] < 0.0))) {
    /* '<S66>:1:205' */
    /* '<S66>:1:206' */
    c1[0] = ctrl_TAPM_P.C[17];
    c1[1] = ctrl_TAPM_P.C[23];
    c1_0[0] = ctrl_TAPM_P.C[17] - K[5];
    c1_0[1] = ctrl_TAPM_P.C[23] - K[5];
    ctrl_TAPM_abs(c1_0, varargin_1);
    ixstart = 1;
    rtb_Row2 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row2 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Row2)) {
      b_ixstart = 1;
    }

    /* '<S66>:1:208' */
    rtb_TmpSignalConversionAtSFun_2 = c1[b_ixstart];
  } else {
    /* '<S66>:1:210' */
    rtb_TmpSignalConversionAtSFun_2 = K[5];
  }

  if (((rtb_TmpSignalConversionAtSFun_m[8] > ctrl_TAPM_P.C[5] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[8] < ctrl_TAPM_P.C[11] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_m[8] > ctrl_TAPM_P.C[17] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_m[8] < ctrl_TAPM_P.C[23] - 0.1))) {
    /* '<S66>:1:212' */
    /* '<S66>:1:213' */
    B_surge[5] = 0.0;
  } else {
    /* '<S66>:1:215' */
  }

  /*  Thruster 2&3  */
  if (rtb_TmpSignalConversionAtSFun_0 == ctrl_TAPM_P.C[7]) {
    /* '<S66>:1:219' */
    /* '<S66>:1:220' */
    Alpha1_idx_2 = K[1] - (ctrl_TAPM_P.C[7] - K[1]);
  } else if (rtb_TmpSignalConversionAtSFun_0 == ctrl_TAPM_P.C[1]) {
    /* '<S66>:1:221' */
    /* '<S66>:1:222' */
    Alpha1_idx_2 = K[1] - (ctrl_TAPM_P.C[1] - K[1]);
  } else if (rtb_TmpSignalConversionAtSFun_0 == ctrl_TAPM_P.C[13]) {
    /* '<S66>:1:223' */
    /* '<S66>:1:224' */
    Alpha1_idx_2 = K[1] - (ctrl_TAPM_P.C[13] - K[1]);
  } else if (rtb_TmpSignalConversionAtSFun_0 == ctrl_TAPM_P.C[19]) {
    /* '<S66>:1:225' */
    /* '<S66>:1:226' */
    Alpha1_idx_2 = K[1] - (ctrl_TAPM_P.C[19] - K[1]);
  } else if (Alpha1_idx_2 == ctrl_TAPM_P.C[8]) {
    /* '<S66>:1:228' */
    /* '<S66>:1:229' */
    rtb_TmpSignalConversionAtSFun_0 = K[2] - (ctrl_TAPM_P.C[8] - K[2]);
  } else if (Alpha1_idx_2 == ctrl_TAPM_P.C[2]) {
    /* '<S66>:1:230' */
    /* '<S66>:1:231' */
    rtb_TmpSignalConversionAtSFun_0 = K[2] - (ctrl_TAPM_P.C[2] - K[2]);
  } else if (Alpha1_idx_2 == ctrl_TAPM_P.C[14]) {
    /* '<S66>:1:232' */
    /* '<S66>:1:233' */
    rtb_TmpSignalConversionAtSFun_0 = K[2] - (ctrl_TAPM_P.C[14] - K[2]);
  } else {
    if (Alpha1_idx_2 == ctrl_TAPM_P.C[20]) {
      /* '<S66>:1:234' */
      /* '<S66>:1:235' */
      rtb_TmpSignalConversionAtSFun_0 = K[2] - (ctrl_TAPM_P.C[20] - K[2]);
    }
  }

  /*  Thruster 5&6 */
  if (Alpha1_idx_4 == ctrl_TAPM_P.C[10]) {
    /* '<S66>:1:239' */
    /* '<S66>:1:240' */
    rtb_TmpSignalConversionAtSFun_2 = K[4] - (ctrl_TAPM_P.C[10] - K[4]);
  } else if (Alpha1_idx_4 == ctrl_TAPM_P.C[4]) {
    /* '<S66>:1:241' */
    /* '<S66>:1:242' */
    rtb_TmpSignalConversionAtSFun_2 = K[4] - (ctrl_TAPM_P.C[4] - K[4]);
  } else if (Alpha1_idx_4 == ctrl_TAPM_P.C[16]) {
    /* '<S66>:1:243' */
    /* '<S66>:1:244' */
    rtb_TmpSignalConversionAtSFun_2 = K[4] - (ctrl_TAPM_P.C[16] - K[4]);
  } else if (Alpha1_idx_4 == ctrl_TAPM_P.C[22]) {
    /* '<S66>:1:245' */
    /* '<S66>:1:246' */
    rtb_TmpSignalConversionAtSFun_2 = K[4] - (ctrl_TAPM_P.C[22] - K[4]);
  } else if (rtb_TmpSignalConversionAtSFun_2 == ctrl_TAPM_P.C[11]) {
    /* '<S66>:1:248' */
    /* '<S66>:1:249' */
    Alpha1_idx_4 = K[5] - (ctrl_TAPM_P.C[11] - K[5]);
  } else if (rtb_TmpSignalConversionAtSFun_2 == ctrl_TAPM_P.C[5]) {
    /* '<S66>:1:250' */
    /* '<S66>:1:251' */
    Alpha1_idx_4 = K[5] - (ctrl_TAPM_P.C[5] - K[5]);
  } else if (rtb_TmpSignalConversionAtSFun_2 == ctrl_TAPM_P.C[17]) {
    /* '<S66>:1:252' */
    /* '<S66>:1:253' */
    Alpha1_idx_4 = K[5] - (ctrl_TAPM_P.C[17] - K[5]);
  } else {
    if (rtb_TmpSignalConversionAtSFun_2 == ctrl_TAPM_P.C[23]) {
      /* '<S66>:1:254' */
      /* '<S66>:1:255' */
      Alpha1_idx_4 = K[5] - (ctrl_TAPM_P.C[23] - K[5]);
    }
  }

  /*  Thruster 4 & 1 */
  if (Alpha1_idx_3 == ctrl_TAPM_P.C[9]) {
    /* '<S66>:1:258' */
    /* '<S66>:1:259' */
    rtb_TmpSignalConversionAtSFun_1 = K[3] - (ctrl_TAPM_P.C[9] - K[3]);
  } else if (Alpha1_idx_3 == ctrl_TAPM_P.C[3]) {
    /* '<S66>:1:260' */
    /* '<S66>:1:261' */
    rtb_TmpSignalConversionAtSFun_1 = K[3] - (ctrl_TAPM_P.C[3] - K[3]);
  } else if (Alpha1_idx_3 == ctrl_TAPM_P.C[15]) {
    /* '<S66>:1:262' */
    /* '<S66>:1:263' */
    rtb_TmpSignalConversionAtSFun_1 = K[3] - (ctrl_TAPM_P.C[15] - K[3]);
  } else {
    if (Alpha1_idx_3 == ctrl_TAPM_P.C[21]) {
      /* '<S66>:1:264' */
      /* '<S66>:1:265' */
      rtb_TmpSignalConversionAtSFun_1 = K[3] - (ctrl_TAPM_P.C[21] - K[3]);
    }
  }

  if (rtb_TmpSignalConversionAtSFun_1 == ctrl_TAPM_P.C[6]) {
    /* '<S66>:1:268' */
    /* '<S66>:1:269' */
    Alpha1_idx_3 = K[0] - (ctrl_TAPM_P.C[6] - K[0]);
  } else if (rtb_TmpSignalConversionAtSFun_1 == ctrl_TAPM_P.C[0]) {
    /* '<S66>:1:270' */
    /* '<S66>:1:271' */
    Alpha1_idx_3 = K[0] - (ctrl_TAPM_P.C[0] - K[0]);
  } else if (rtb_TmpSignalConversionAtSFun_1 == ctrl_TAPM_P.C[12]) {
    /* '<S66>:1:272' */
    /* '<S66>:1:273' */
    Alpha1_idx_3 = K[0] - (ctrl_TAPM_P.C[12] - K[0]);
  } else {
    if (rtb_TmpSignalConversionAtSFun_1 == ctrl_TAPM_P.C[18]) {
      /* '<S66>:1:274' */
      /* '<S66>:1:275' */
      Alpha1_idx_3 = K[0] - (ctrl_TAPM_P.C[18] - K[0]);
    }
  }

  /* '<S66>:1:278' */
  /*  u_d = -Desired_thrust; */
  /* % Update outputs */
  /* '<S66>:1:285' */
  rtb_sys[0] = rtb_TmpSignalConversionAtSFun_1;
  rtb_sys[1] = rtb_TmpSignalConversionAtSFun_0;
  rtb_sys[2] = Alpha1_idx_2;
  rtb_sys[3] = Alpha1_idx_3;
  rtb_sys[4] = Alpha1_idx_4;
  rtb_sys[5] = rtb_TmpSignalConversionAtSFun_2;
  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    rtb_sys[b_ixstart + 6] = B_surge[b_ixstart];
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
  }

  /* Switch: '<S10>/Choosing Fixed // Azimuth angle' incorporates:
   *  Constant: '<S10>/constant angle'
   */
  for (i = 0; i < 6; i++) {
    if (ctrl_TAPM_B.Angle_controller >=
        ctrl_TAPM_P.ChoosingFixedAzimuthangle_Thres) {
      ctrl_TAPM_B.ChoosingFixedAzimuthangle[i] = rtb_sys[i];
    } else {
      ctrl_TAPM_B.ChoosingFixedAzimuthangle[i] =
        ctrl_TAPM_P.constantangle_Value[i];
    }
  }

  /* End of Switch: '<S10>/Choosing Fixed // Azimuth angle' */

  /* Outputs for Iterator SubSystem: '<S10>/Optimal angle path and  constraints on rotation speed' incorporates:
   *  ForEach: '<S67>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
    /* ForEachSliceSelector: '<S67>/ImpSel_InsertedFor_reset_at_outport_0' */
    rtb_ImpSel_InsertedFor_reset_at = ctrl_TAPM_B.reset_g[ForEach_itr];
    if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
      /* DiscreteIntegrator: '<S67>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S10>/constant angle'
       *  ForEachSliceSelector: '<S67>/ImpSel_InsertedFor_initial angle _at_outport_0'
       */
      if (ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI
          != 0) {
        ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE =
          ctrl_TAPM_P.constantangle_Value[ForEach_itr];
      }

      if (((rtb_ImpSel_InsertedFor_reset_at > 0.0) &&
           (ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese
            <= 0)) || ((rtb_ImpSel_InsertedFor_reset_at <= 0.0) &&
                       (ctrl_TAPM_DW.CoreSubsys[ForEach_itr].
                        DiscreteTimeIntegrator_PrevRese == 1))) {
        ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE =
          ctrl_TAPM_P.constantangle_Value[ForEach_itr];
      }

      ctrl_TAPM_B.CoreSubsys[ForEach_itr].angle =
        ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE;

      /* End of DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */

      /* Gain: '<S70>/Gain1' */
      rtb_Row2 = ctrl_TAPM_P.CoreSubsys.Gain1_Gain *
        ctrl_TAPM_B.CoreSubsys[ForEach_itr].angle;

      /* Delay: '<S67>/Delay' */
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].Delay =
        ctrl_TAPM_DW.CoreSubsys[ForEach_itr].Delay_DSTATE;

      /* MATLAB Function: '<S67>/Ensuring angle is  [-pi pi]' */
      /* MATLAB Function 'Thrust allocation/Optimal angle path and  constraints on rotation speed/Ensuring angle is  [-pi pi]': '<S71>:1' */
      /*  RAD2PIPI Converts an angle in rad to the interval (-pi pi] */
      /*           Should be applied to all heading errors in a feedback control system */
      /*           in order to avoid discontinuities. */
      /*  */
      /*  Author:     Roger Skjetne */
      /*  Date:       2003-09-05 */
      /*  Revisions:  2004-09-02 Thor I. Fossen - replaced input argument x with angle */
      /*              2005-01-05 Thor I. Fossen - ouput argument is set to y and not angle */
      /*              2005-04-13 Roger Skjetne  - changed the function s in order */
      /*                                          to account for correct mapping to */
      /*                                          (-pi pi]. */
      /*  */
      /*  ________________________________________________________________ */
      /*  */
      /*  MSS GNC is a Matlab toolbox for guidance, navigation and control. */
      /*  The toolbox is part of the Marine Systems Simulator (MSS). */
      /*  */
      /*  Copyright (C) 2008 Thor I. Fossen and Tristan Perez */
      /*   */
      /*  This program is free software: you can redistribute it and/or modify */
      /*  it under the terms of the GNU General Public License as published by */
      /*  the Free Software Foundation, either version 3 of the License, or */
      /*  (at your option) any later version. */
      /*   */
      /*  This program is distributed in the hope that it will be useful, but */
      /*  WITHOUT ANY WARRANTY; without even the implied warranty of */
      /*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  */
      /*  GNU General Public License for more details. */
      /*   */
      /*  You should have received a copy of the GNU General Public License */
      /*  along with this program.  If not, see <http://www.gnu.org/licenses/>. */
      /*   */
      /*  E-mail: contact@marinecontrol.org */
      /*  URL:    <http://www.marinecontrol.org> */
      /*  convert angle in rad to the interval <-pi pi>  */
      /* '<S71>:1:39' */
      /* '<S71>:1:40' */
      /*  s = sign(angle); */
      /* '<S71>:1:43' */
      u = fabs(rt_remd_snf(rtb_Row2 + 3.1415926535897931, 6.2831853071795862) /
               6.2831853071795862);
      if (rtb_Row2 < 0.0) {
        rtb_TmpSignalConversionAtSFun_2 = -1.0;
      } else if (rtb_Row2 > 0.0) {
        rtb_TmpSignalConversionAtSFun_2 = 1.0;
      } else if (rtb_Row2 == 0.0) {
        rtb_TmpSignalConversionAtSFun_2 = 0.0;
      } else {
        rtb_TmpSignalConversionAtSFun_2 = rtb_Row2;
      }

      if (u > 0.0) {
        u = 1.0;
      } else {
        if (u == 0.0) {
          u = 0.0;
        }
      }

      u = (u - 1.0) * 2.0 + rtb_TmpSignalConversionAtSFun_2;
      if (rtb_Row2 < 0.0) {
        rtb_TmpSignalConversionAtSFun_2 = -1.0;
      } else if (rtb_Row2 > 0.0) {
        rtb_TmpSignalConversionAtSFun_2 = 1.0;
      } else if (rtb_Row2 == 0.0) {
        rtb_TmpSignalConversionAtSFun_2 = 0.0;
      } else {
        rtb_TmpSignalConversionAtSFun_2 = rtb_Row2;
      }

      if (u < 0.0) {
        u = -1.0;
      } else if (u > 0.0) {
        u = 1.0;
      } else {
        if (u == 0.0) {
          u = 0.0;
        }
      }

      rtb_commandedAngle_CoreSubsysCa = rt_remd_snf
        (rtb_TmpSignalConversionAtSFun_2 * 3.1415926535897931 + rtb_Row2,
         6.2831853071795862) - u * 3.1415926535897931;

      /* End of MATLAB Function: '<S67>/Ensuring angle is  [-pi pi]' */
    }

    /* MATLAB Function: '<S67>/MATLAB Function1' incorporates:
     *  ForEachSliceSelector: '<S67>/ImpSel_InsertedFor_Desired Angle_at_outport_0'
     */
    /* MATLAB Function 'Thrust allocation/Optimal angle path and  constraints on rotation speed/MATLAB Function1': '<S72>:1' */
    /* '<S72>:1:3' */
    rtb_Row2 = ctrl_TAPM_B.ChoosingFixedAzimuthangle[ForEach_itr] -
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].Delay;
    if (fabs(rtb_Row2) >= 360.0) {
      /* '<S72>:1:4' */
      /* '<S72>:1:5' */
      rtb_Row2 = rt_remd_snf(rtb_Row2, 360.0);
    }

    if (fabs(rtb_Row2) >= 180.0) {
      /* '<S72>:1:8' */
      /* '<S72>:1:9' */
      if (rtb_Row2 < 0.0) {
        rtb_TmpSignalConversionAtSFun_2 = -1.0;
      } else if (rtb_Row2 > 0.0) {
        rtb_TmpSignalConversionAtSFun_2 = 1.0;
      } else if (rtb_Row2 == 0.0) {
        rtb_TmpSignalConversionAtSFun_2 = 0.0;
      } else {
        rtb_TmpSignalConversionAtSFun_2 = rtb_Row2;
      }

      rtb_Row2 -= rtb_TmpSignalConversionAtSFun_2 * 360.0;
    }

    /* End of MATLAB Function: '<S67>/MATLAB Function1' */

    /* Saturate: '<S67>/Max Rotation Rate' */
    /*  if desired < 0 %&& abs(desired+actual) > 180 */
    /*      y = actual+360; */
    /*  else */
    /*      y = abs(actual); */
    /*  end */
    /* if desired-actual > 180 */
    /*     u = desired - 360; */
    /* elseif desired-actual <= -180 */
    /*     u=actual + 360 ; */
    /* else */
    /*     u=desired;         */
    /* end */
    /* rotation = change-actual;% - actual; % If positive with clock, Negative against clock */
    /* if rotation >= 180 || rotation <= -180 */
    /*  u = desired; */
    /* else  */
    /*      u = actual; */
    /* end */
    /* change = abs(actual); */
    /*  if actual-desired > 180 && desired > 0 && rotation > 0 */
    /*      u = -180; */
    /*  elseif  actual-desired > 180 && desired > 0 && rotation < 0 */
    /*      u = 180; */
    /*  else  */
    /*      u = actual; */
    /*  end */
    /*  if change > abs(desired-actual) */
    /*      u = -actual; */
    /*  else */
    /*      u = actual; */
    /*  end */
    /*  if desired >= 0.98*actual || desired <= -0.98*actual  */
    /*      u = desired; */
    /*  else  */
    /*      u = actual;  */
    /*  end */
    /*  paths = [abs(actual-desired),abs(-1*actual-desired)]; */
    /*  fastest = min(paths); */
    /*  if paths(1) > paths(2) */
    /*      fastest = paths(2); */
    /*  elseif paths(1) < paths(2) */
    /*      fastest = paths(1); */
    /*  end */
    /*  % if desired > 0 && actual < 0 || desired < 0 && actual < 0 */
    /*  % u = fastest; */
    /*  % elseif desired > 0 && actual > 0 || desired < 0 && actual < 0 */
    /*  %     u = fastest; */
    /*  if desired-actual > 180 || desired-actual < -180 */
    /*      u = -actual; */
    /*  else  */
    /*      u = actual; */
    /*  end */
    if (rtb_Row2 > ctrl_TAPM_P.Max_rotation) {
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate =
        ctrl_TAPM_P.Max_rotation;
    } else if (rtb_Row2 < -ctrl_TAPM_P.Max_rotation) {
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate =
        -ctrl_TAPM_P.Max_rotation;
    } else {
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate = rtb_Row2;
    }

    /* End of Saturate: '<S67>/Max Rotation Rate' */
    if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
      /* ForEachSliceAssignment: '<S67>/ImpAsg_InsertedFor_commanded Angle_at_inport_0' */
      rtb_ImpAsg_InsertedFor_commande[ForEach_itr] =
        rtb_commandedAngle_CoreSubsysCa;
    }
  }

  /* End of Outputs for SubSystem: '<S10>/Optimal angle path and  constraints on rotation speed' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Saturate: '<S73>/Saturation 1' */
    if (rtb_ImpAsg_InsertedFor_commande[0] > ctrl_TAPM_P.Saturation1_UpperSat) {
      ctrl_TAPM_B.Saturation1 = ctrl_TAPM_P.Saturation1_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_commande[0] <
               ctrl_TAPM_P.Saturation1_LowerSat) {
      ctrl_TAPM_B.Saturation1 = ctrl_TAPM_P.Saturation1_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation1 = rtb_ImpAsg_InsertedFor_commande[0];
    }

    /* End of Saturate: '<S73>/Saturation 1' */
  }

  /* Integrator: '<S89>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_g,
                       ctrl_TAPM_B.reset_o);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_c = ctrl_TAPM_P.Integrator_IC_f;
    }
  }

  rtb_Integrator = ctrl_TAPM_X.Integrator_CSTATE_c;

  /* MATLAB Function: '<S88>/Actual Force and Torque' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Qr1'
   *  Constant: '<S11>/K_Qr7'
   *  Constant: '<S11>/K_Tf1'
   *  Constant: '<S11>/K_Tr1'
   *  Constant: '<S11>/Rho'
   *  Constant: '<S75>/Losses (placeholder)'
   */
  /* MATLAB Function 'Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque': '<S91>:1' */
  /* '<S91>:1:3' */
  rtb_Row1 = tanh(ctrl_TAPM_P.eps_c * rtb_Integrator / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S91>:1:4' */
  /* '<S91>:1:5' */
  /* '<S91>:1:7' */
  if (rtb_Integrator < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (rtb_Integrator > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (rtb_Integrator == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = rtb_Integrator;
  }

  rtb_Row1_m = ((1.0 - rtb_Row1) * ctrl_TAPM_P.K_T1r + ctrl_TAPM_P.K_T1f *
                rtb_Row1) * rtb_TmpSignalConversionAtSFun_2 * ctrl_TAPM_P.Rho *
    rt_powd_snf(ctrl_TAPM_P.D, 4.0) * (rtb_Integrator * rtb_Integrator) -
    ctrl_TAPM_P.Lossesplaceholder_Value;

  /* '<S91>:1:8' */
  if (rtb_Integrator < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (rtb_Integrator > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (rtb_Integrator == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = rtb_Integrator;
  }

  rtb_Row2 = ((1.0 - rtb_Row1) * ctrl_TAPM_P.K_q1r + ctrl_TAPM_P.K_q1f *
              rtb_Row1) * rtb_TmpSignalConversionAtSFun_2 * ctrl_TAPM_P.Rho *
    rt_powd_snf(ctrl_TAPM_P.D, 5.0) * (rtb_Integrator * rtb_Integrator) -
    ctrl_TAPM_P.Lossesplaceholder_Value;

  /* '<S91>:1:9' */
  ctrl_TAPM_B.Pa = 6.2831853071795862 * rtb_Integrator * rtb_Row2;
  ctrl_TAPM_B.Qa = rtb_Row2;

  /* End of MATLAB Function: '<S88>/Actual Force and Torque' */

  /* Integrator: '<S98>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_n,
                       ctrl_TAPM_B.reset_c);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_p = ctrl_TAPM_P.Integrator_IC_fg;
    }
  }

  rtb_Integrator_h = ctrl_TAPM_X.Integrator_CSTATE_p;

  /* MATLAB Function: '<S97>/Actual Force and Torque' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Qr2'
   *  Constant: '<S11>/K_Qr8'
   *  Constant: '<S11>/K_Tf2'
   *  Constant: '<S11>/K_Tr2'
   *  Constant: '<S11>/Rho'
   *  Constant: '<S76>/Losses (placeholder)'
   */
  ctrl_TAPM_ActualForceandTorque(rtb_Integrator_h, ctrl_TAPM_P.K_q2f,
    ctrl_TAPM_P.K_T2f, ctrl_TAPM_P.K_T2r, ctrl_TAPM_P.K_q2r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_k,
    &ctrl_TAPM_B.sf_ActualForceandTorque_f);

  /* Integrator: '<S107>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_o,
                       ctrl_TAPM_B.reset_j);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_k = ctrl_TAPM_P.Integrator_IC_p;
    }
  }

  rtb_Integrator_a = ctrl_TAPM_X.Integrator_CSTATE_k;

  /* MATLAB Function: '<S106>/Actual Force and Torque' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Qr3'
   *  Constant: '<S11>/K_Qr9'
   *  Constant: '<S11>/K_Tf3'
   *  Constant: '<S11>/K_Tr3'
   *  Constant: '<S11>/Rho'
   *  Constant: '<S77>/Losses (placeholder)'
   */
  ctrl_TAPM_ActualForceandTorque(rtb_Integrator_a, ctrl_TAPM_P.K_q3f,
    ctrl_TAPM_P.K_T3f, ctrl_TAPM_P.K_T3r, ctrl_TAPM_P.K_q3r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_n,
    &ctrl_TAPM_B.sf_ActualForceandTorque_h);

  /* Integrator: '<S116>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_i,
                       ctrl_TAPM_B.reset_p);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_n = ctrl_TAPM_P.Integrator_IC_fv;
    }
  }

  rtb_Integrator_k = ctrl_TAPM_X.Integrator_CSTATE_n;

  /* MATLAB Function: '<S115>/Actual Force and Torque' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Qr10'
   *  Constant: '<S11>/K_Qr4'
   *  Constant: '<S11>/K_Tf4'
   *  Constant: '<S11>/K_Tr4'
   *  Constant: '<S11>/Rho'
   *  Constant: '<S78>/Losses (placeholder)'
   */
  ctrl_TAPM_ActualForceandTorque(rtb_Integrator_k, ctrl_TAPM_P.K_q4f,
    ctrl_TAPM_P.K_T4f, ctrl_TAPM_P.K_T4r, ctrl_TAPM_P.K_q4r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_d,
    &ctrl_TAPM_B.sf_ActualForceandTorque_m);

  /* Integrator: '<S125>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_a,
                       ctrl_TAPM_B.reset_k);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_cd = ctrl_TAPM_P.Integrator_IC_l;
    }
  }

  rtb_Integrator_c = ctrl_TAPM_X.Integrator_CSTATE_cd;

  /* MATLAB Function: '<S124>/Actual Force and Torque' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Qr11'
   *  Constant: '<S11>/K_Qr5'
   *  Constant: '<S11>/K_Tf5'
   *  Constant: '<S11>/K_Tr5'
   *  Constant: '<S11>/Rho'
   *  Constant: '<S79>/Losses (placeholder)'
   */
  ctrl_TAPM_ActualForceandTorque(rtb_Integrator_c, ctrl_TAPM_P.K_q5f,
    ctrl_TAPM_P.K_T5f, ctrl_TAPM_P.K_T5r, ctrl_TAPM_P.K_q5r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_f,
    &ctrl_TAPM_B.sf_ActualForceandTorque_o);

  /* Integrator: '<S134>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_d,
                       ctrl_TAPM_B.reset_i);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_h = ctrl_TAPM_P.Integrator_IC_li;
    }
  }

  rtb_Integrator_m = ctrl_TAPM_X.Integrator_CSTATE_h;

  /* MATLAB Function: '<S133>/Actual Force and Torque' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Qr12'
   *  Constant: '<S11>/K_Qr6'
   *  Constant: '<S11>/K_Tf6'
   *  Constant: '<S11>/K_Tr6'
   *  Constant: '<S11>/Rho'
   *  Constant: '<S80>/Losses (placeholder)'
   */
  ctrl_TAPM_ActualForceandTorque(rtb_Integrator_m, ctrl_TAPM_P.K_q6f,
    ctrl_TAPM_P.K_T6f, ctrl_TAPM_P.K_T6r, ctrl_TAPM_P.K_q6r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_h,
    &ctrl_TAPM_B.sf_ActualForceandTorque_j);

  /* MATLAB Function: '<S74>/MATLAB Function' incorporates:
   *  SignalConversion: '<S81>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function': '<S81>:1' */
  /* '<S81>:1:8' */
  ctrl_TAPM_B.output[0] = rtb_Row1_m;
  ctrl_TAPM_B.output[1] = rtb_Integrator;
  ctrl_TAPM_B.output[2] = ctrl_TAPM_B.sf_ActualForceandTorque_f.Ta;
  ctrl_TAPM_B.output[3] = rtb_Integrator_h;
  ctrl_TAPM_B.output[4] = ctrl_TAPM_B.sf_ActualForceandTorque_h.Ta;
  ctrl_TAPM_B.output[5] = rtb_Integrator_a;
  ctrl_TAPM_B.output[6] = ctrl_TAPM_B.sf_ActualForceandTorque_m.Ta;
  ctrl_TAPM_B.output[7] = rtb_Integrator_k;
  ctrl_TAPM_B.output[8] = ctrl_TAPM_B.sf_ActualForceandTorque_o.Ta;
  ctrl_TAPM_B.output[9] = rtb_Integrator_c;
  ctrl_TAPM_B.output[10] = ctrl_TAPM_B.sf_ActualForceandTorque_j.Ta;
  ctrl_TAPM_B.output[11] = rtb_Integrator_m;

  /* Saturate: '<S74>/Saturation 8' */
  if (ctrl_TAPM_B.output[2] > ctrl_TAPM_P.Max_thrust) {
    rtb_Row2 = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[2] < ctrl_TAPM_P.Saturation8_LowerSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation8_LowerSat;
  } else {
    rtb_Row2 = ctrl_TAPM_B.output[2];
  }

  /* End of Saturate: '<S74>/Saturation 8' */

  /* Polyval: '<S74>/positive thrust 2' */
  rtb_positivethrust2 = ctrl_TAPM_P.pwm_thr2_forward[0];
  for (ixstart = 0; ixstart < 5; ixstart++) {
    rtb_positivethrust2 = rtb_positivethrust2 * rtb_Row2 +
      ctrl_TAPM_P.pwm_thr2_forward[ixstart + 1];
  }

  /* End of Polyval: '<S74>/positive thrust 2' */

  /* Saturate: '<S74>/Saturation 9' */
  if (ctrl_TAPM_B.output[2] > ctrl_TAPM_P.Saturation9_UpperSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation9_UpperSat;
  } else if (ctrl_TAPM_B.output[2] < ctrl_TAPM_P.Min_thrust) {
    rtb_Row2 = ctrl_TAPM_P.Min_thrust;
  } else {
    rtb_Row2 = ctrl_TAPM_B.output[2];
  }

  /* End of Saturate: '<S74>/Saturation 9' */

  /* Polyval: '<S74>/negative thrust 2' */
  rtb_negativethrust2 = ctrl_TAPM_P.pwm_thr2_backward[0];
  for (ixstart = 0; ixstart < 5; ixstart++) {
    rtb_negativethrust2 = rtb_negativethrust2 * rtb_Row2 +
      ctrl_TAPM_P.pwm_thr2_backward[ixstart + 1];
  }

  /* End of Polyval: '<S74>/negative thrust 2' */

  /* MATLAB Function: '<S74>/MATLAB Function2' */
  ctrl_TAPM_MATLABFunction2(rtb_positivethrust2, ctrl_TAPM_B.output[2],
    rtb_negativethrust2, &ctrl_TAPM_B.sf_MATLABFunction2);

  /* Saturate: '<S74>/Saturation 10' */
  if (ctrl_TAPM_B.output[4] > ctrl_TAPM_P.Max_thrust) {
    rtb_Row2 = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[4] < ctrl_TAPM_P.Saturation10_LowerSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation10_LowerSat;
  } else {
    rtb_Row2 = ctrl_TAPM_B.output[4];
  }

  /* End of Saturate: '<S74>/Saturation 10' */

  /* Polyval: '<S74>/positive thrust 3' */
  rtb_positivethrust3 = ctrl_TAPM_P.pwm_thr3_forward[0];
  for (ixstart = 0; ixstart < 5; ixstart++) {
    rtb_positivethrust3 = rtb_positivethrust3 * rtb_Row2 +
      ctrl_TAPM_P.pwm_thr3_forward[ixstart + 1];
  }

  /* End of Polyval: '<S74>/positive thrust 3' */

  /* Saturate: '<S74>/Saturation 11' */
  if (ctrl_TAPM_B.output[4] > ctrl_TAPM_P.Saturation11_UpperSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation11_UpperSat;
  } else if (ctrl_TAPM_B.output[4] < ctrl_TAPM_P.Min_thrust) {
    rtb_Row2 = ctrl_TAPM_P.Min_thrust;
  } else {
    rtb_Row2 = ctrl_TAPM_B.output[4];
  }

  /* End of Saturate: '<S74>/Saturation 11' */

  /* Polyval: '<S74>/negative thrust 3' */
  rtb_negativethrust3 = ctrl_TAPM_P.pwm_thr3_backward[0];
  for (ixstart = 0; ixstart < 5; ixstart++) {
    rtb_negativethrust3 = rtb_negativethrust3 * rtb_Row2 +
      ctrl_TAPM_P.pwm_thr3_backward[ixstart + 1];
  }

  /* End of Polyval: '<S74>/negative thrust 3' */

  /* MATLAB Function: '<S74>/MATLAB Function3' */
  ctrl_TAPM_MATLABFunction2(rtb_positivethrust3, ctrl_TAPM_B.output[4],
    rtb_negativethrust3, &ctrl_TAPM_B.sf_MATLABFunction3);

  /* Saturate: '<S74>/Saturation 3' */
  if (ctrl_TAPM_B.output[6] > ctrl_TAPM_P.Max_thrust) {
    rtb_Row2 = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[6] < ctrl_TAPM_P.Saturation3_LowerSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation3_LowerSat;
  } else {
    rtb_Row2 = ctrl_TAPM_B.output[6];
  }

  /* End of Saturate: '<S74>/Saturation 3' */

  /* Polyval: '<S74>/positive thrust 4' */
  rtb_positivethrust4 = ctrl_TAPM_P.pwm_thr4_forward[0];
  for (ixstart = 0; ixstart < 5; ixstart++) {
    rtb_positivethrust4 = rtb_positivethrust4 * rtb_Row2 +
      ctrl_TAPM_P.pwm_thr4_forward[ixstart + 1];
  }

  /* End of Polyval: '<S74>/positive thrust 4' */

  /* Saturate: '<S74>/Saturation 4' */
  if (ctrl_TAPM_B.output[6] > ctrl_TAPM_P.Saturation4_UpperSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation4_UpperSat;
  } else if (ctrl_TAPM_B.output[6] < ctrl_TAPM_P.Min_thrust) {
    rtb_Row2 = ctrl_TAPM_P.Min_thrust;
  } else {
    rtb_Row2 = ctrl_TAPM_B.output[6];
  }

  /* End of Saturate: '<S74>/Saturation 4' */

  /* Polyval: '<S74>/negative thrust 4' */
  rtb_negativethrust4 = ctrl_TAPM_P.pwm_thr4_backward[0];
  for (ixstart = 0; ixstart < 5; ixstart++) {
    rtb_negativethrust4 = rtb_negativethrust4 * rtb_Row2 +
      ctrl_TAPM_P.pwm_thr4_backward[ixstart + 1];
  }

  /* End of Polyval: '<S74>/negative thrust 4' */

  /* MATLAB Function: '<S74>/MATLAB Function4' */
  ctrl_TAPM_MATLABFunction2(rtb_positivethrust4, ctrl_TAPM_B.output[6],
    rtb_negativethrust4, &ctrl_TAPM_B.sf_MATLABFunction4);

  /* Saturate: '<S74>/Saturation 5' */
  if (ctrl_TAPM_B.output[8] > ctrl_TAPM_P.Max_thrust) {
    rtb_Row2 = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[8] < ctrl_TAPM_P.Saturation5_LowerSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation5_LowerSat;
  } else {
    rtb_Row2 = ctrl_TAPM_B.output[8];
  }

  /* End of Saturate: '<S74>/Saturation 5' */

  /* Polyval: '<S74>/positive thrust 5' */
  rtb_positivethrust5 = ctrl_TAPM_P.pwm_thr5_forward[0];
  for (ixstart = 0; ixstart < 5; ixstart++) {
    rtb_positivethrust5 = rtb_positivethrust5 * rtb_Row2 +
      ctrl_TAPM_P.pwm_thr5_forward[ixstart + 1];
  }

  /* End of Polyval: '<S74>/positive thrust 5' */

  /* Saturate: '<S74>/Saturation 6' */
  if (ctrl_TAPM_B.output[8] > ctrl_TAPM_P.Saturation6_UpperSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation6_UpperSat;
  } else if (ctrl_TAPM_B.output[8] < ctrl_TAPM_P.Min_thrust) {
    rtb_Row2 = ctrl_TAPM_P.Min_thrust;
  } else {
    rtb_Row2 = ctrl_TAPM_B.output[8];
  }

  /* End of Saturate: '<S74>/Saturation 6' */

  /* Polyval: '<S74>/negative thrust 5' */
  rtb_negativethrust5 = ctrl_TAPM_P.pwm_thr5_backward[0];
  for (ixstart = 0; ixstart < 5; ixstart++) {
    rtb_negativethrust5 = rtb_negativethrust5 * rtb_Row2 +
      ctrl_TAPM_P.pwm_thr5_backward[ixstart + 1];
  }

  /* End of Polyval: '<S74>/negative thrust 5' */

  /* MATLAB Function: '<S74>/MATLAB Function5' */
  ctrl_TAPM_MATLABFunction2(rtb_positivethrust5, ctrl_TAPM_B.output[8],
    rtb_negativethrust5, &ctrl_TAPM_B.sf_MATLABFunction5);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Saturate: '<S73>/Saturation 2' */
    if (rtb_ImpAsg_InsertedFor_commande[1] > ctrl_TAPM_P.Saturation2_UpperSat) {
      ctrl_TAPM_B.Saturation2 = ctrl_TAPM_P.Saturation2_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_commande[1] <
               ctrl_TAPM_P.Saturation2_LowerSat) {
      ctrl_TAPM_B.Saturation2 = ctrl_TAPM_P.Saturation2_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation2 = rtb_ImpAsg_InsertedFor_commande[1];
    }

    /* End of Saturate: '<S73>/Saturation 2' */
  }

  /* Saturate: '<S74>/Saturation 12' */
  if (ctrl_TAPM_B.output[10] > ctrl_TAPM_P.Max_thrust) {
    rtb_Row2 = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[10] < ctrl_TAPM_P.Saturation12_LowerSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation12_LowerSat;
  } else {
    rtb_Row2 = ctrl_TAPM_B.output[10];
  }

  /* End of Saturate: '<S74>/Saturation 12' */

  /* Polyval: '<S74>/positive thrust 6' */
  rtb_positivethrust6 = ctrl_TAPM_P.pwm_thr6_forward[0];
  for (ixstart = 0; ixstart < 5; ixstart++) {
    rtb_positivethrust6 = rtb_positivethrust6 * rtb_Row2 +
      ctrl_TAPM_P.pwm_thr6_forward[ixstart + 1];
  }

  /* End of Polyval: '<S74>/positive thrust 6' */

  /* Saturate: '<S74>/Saturation 13' */
  if (ctrl_TAPM_B.output[10] > ctrl_TAPM_P.Saturation13_UpperSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation13_UpperSat;
  } else if (ctrl_TAPM_B.output[10] < ctrl_TAPM_P.Min_thrust) {
    rtb_Row2 = ctrl_TAPM_P.Min_thrust;
  } else {
    rtb_Row2 = ctrl_TAPM_B.output[10];
  }

  /* End of Saturate: '<S74>/Saturation 13' */

  /* Polyval: '<S74>/negative thrust 6' */
  rtb_negativethrust6 = ctrl_TAPM_P.pwm_thr6_backward[0];
  for (ixstart = 0; ixstart < 5; ixstart++) {
    rtb_negativethrust6 = rtb_negativethrust6 * rtb_Row2 +
      ctrl_TAPM_P.pwm_thr6_backward[ixstart + 1];
  }

  /* End of Polyval: '<S74>/negative thrust 6' */

  /* MATLAB Function: '<S74>/MATLAB Function6' */
  ctrl_TAPM_MATLABFunction2(rtb_positivethrust6, ctrl_TAPM_B.output[10],
    rtb_negativethrust6, &ctrl_TAPM_B.sf_MATLABFunction6);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Saturate: '<S73>/Saturation 3' */
    if (rtb_ImpAsg_InsertedFor_commande[2] > ctrl_TAPM_P.Saturation3_UpperSat) {
      ctrl_TAPM_B.Saturation3 = ctrl_TAPM_P.Saturation3_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_commande[2] <
               ctrl_TAPM_P.Saturation3_LowerSat_f) {
      ctrl_TAPM_B.Saturation3 = ctrl_TAPM_P.Saturation3_LowerSat_f;
    } else {
      ctrl_TAPM_B.Saturation3 = rtb_ImpAsg_InsertedFor_commande[2];
    }

    /* End of Saturate: '<S73>/Saturation 3' */

    /* Saturate: '<S73>/Saturation 4' */
    if (rtb_ImpAsg_InsertedFor_commande[3] > ctrl_TAPM_P.Saturation4_UpperSat_p)
    {
      ctrl_TAPM_B.Saturation4 = ctrl_TAPM_P.Saturation4_UpperSat_p;
    } else if (rtb_ImpAsg_InsertedFor_commande[3] <
               ctrl_TAPM_P.Saturation4_LowerSat) {
      ctrl_TAPM_B.Saturation4 = ctrl_TAPM_P.Saturation4_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation4 = rtb_ImpAsg_InsertedFor_commande[3];
    }

    /* End of Saturate: '<S73>/Saturation 4' */

    /* Saturate: '<S73>/Saturation 5' */
    if (rtb_ImpAsg_InsertedFor_commande[4] > ctrl_TAPM_P.Saturation5_UpperSat) {
      ctrl_TAPM_B.Saturation5 = ctrl_TAPM_P.Saturation5_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_commande[4] <
               ctrl_TAPM_P.Saturation5_LowerSat_h) {
      ctrl_TAPM_B.Saturation5 = ctrl_TAPM_P.Saturation5_LowerSat_h;
    } else {
      ctrl_TAPM_B.Saturation5 = rtb_ImpAsg_InsertedFor_commande[4];
    }

    /* End of Saturate: '<S73>/Saturation 5' */

    /* Saturate: '<S73>/Saturation 6' */
    if (rtb_ImpAsg_InsertedFor_commande[5] > ctrl_TAPM_P.Saturation6_UpperSat_g)
    {
      ctrl_TAPM_B.Saturation6 = ctrl_TAPM_P.Saturation6_UpperSat_g;
    } else if (rtb_ImpAsg_InsertedFor_commande[5] <
               ctrl_TAPM_P.Saturation6_LowerSat) {
      ctrl_TAPM_B.Saturation6 = ctrl_TAPM_P.Saturation6_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation6 = rtb_ImpAsg_InsertedFor_commande[5];
    }

    /* End of Saturate: '<S73>/Saturation 6' */
  }

  /* Saturate: '<S74>/Saturation 7' */
  if (ctrl_TAPM_B.output[0] > ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[0] = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[0] < -ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[0] = -ctrl_TAPM_P.Max_thrust;
  } else {
    ctrl_TAPM_B.Saturation7[0] = ctrl_TAPM_B.output[0];
  }

  if (ctrl_TAPM_B.output[2] > ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[1] = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[2] < -ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[1] = -ctrl_TAPM_P.Max_thrust;
  } else {
    ctrl_TAPM_B.Saturation7[1] = ctrl_TAPM_B.output[2];
  }

  if (ctrl_TAPM_B.output[4] > ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[2] = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[4] < -ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[2] = -ctrl_TAPM_P.Max_thrust;
  } else {
    ctrl_TAPM_B.Saturation7[2] = ctrl_TAPM_B.output[4];
  }

  if (ctrl_TAPM_B.output[6] > ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[3] = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[6] < -ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[3] = -ctrl_TAPM_P.Max_thrust;
  } else {
    ctrl_TAPM_B.Saturation7[3] = ctrl_TAPM_B.output[6];
  }

  if (ctrl_TAPM_B.output[8] > ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[4] = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[8] < -ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[4] = -ctrl_TAPM_P.Max_thrust;
  } else {
    ctrl_TAPM_B.Saturation7[4] = ctrl_TAPM_B.output[8];
  }

  if (ctrl_TAPM_B.output[10] > ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[5] = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[10] < -ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[5] = -ctrl_TAPM_P.Max_thrust;
  } else {
    ctrl_TAPM_B.Saturation7[5] = ctrl_TAPM_B.output[10];
  }

  /* End of Saturate: '<S74>/Saturation 7' */

  /* Saturate: '<S74>/Saturation 1' */
  if (ctrl_TAPM_B.output[0] > ctrl_TAPM_P.Max_thrust) {
    rtb_Row2 = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[0] < ctrl_TAPM_P.Saturation1_LowerSat_h) {
    rtb_Row2 = ctrl_TAPM_P.Saturation1_LowerSat_h;
  } else {
    rtb_Row2 = ctrl_TAPM_B.output[0];
  }

  /* End of Saturate: '<S74>/Saturation 1' */

  /* Polyval: '<S74>/positive thrust 1' */
  rtb_Row1_m = ctrl_TAPM_P.pwm_thr1_forward[0];
  for (ixstart = 0; ixstart < 5; ixstart++) {
    rtb_Row1_m = rtb_Row1_m * rtb_Row2 + ctrl_TAPM_P.pwm_thr1_forward[ixstart +
      1];
  }

  /* End of Polyval: '<S74>/positive thrust 1' */

  /* Saturate: '<S74>/Saturation 2' */
  if (ctrl_TAPM_B.output[0] > ctrl_TAPM_P.Saturation2_UpperSat_p) {
    rtb_Row2 = ctrl_TAPM_P.Saturation2_UpperSat_p;
  } else if (ctrl_TAPM_B.output[0] < ctrl_TAPM_P.Min_thrust) {
    rtb_Row2 = ctrl_TAPM_P.Min_thrust;
  } else {
    rtb_Row2 = ctrl_TAPM_B.output[0];
  }

  /* End of Saturate: '<S74>/Saturation 2' */

  /* Polyval: '<S74>/negative thrust 1' */
  rtb_Row1 = ctrl_TAPM_P.pwm_thr1_backward[0];
  for (ixstart = 0; ixstart < 5; ixstart++) {
    rtb_Row1 = rtb_Row1 * rtb_Row2 + ctrl_TAPM_P.pwm_thr1_backward[ixstart + 1];
  }

  /* End of Polyval: '<S74>/negative thrust 1' */

  /* MATLAB Function: '<S74>/MATLAB Function1' */
  /* MATLAB Function 'Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function1': '<S82>:1' */
  if (ctrl_TAPM_B.output[0] >= 0.0) {
    /* '<S82>:1:4' */
    /* '<S82>:1:5' */
    ctrl_TAPM_B.Tc_out = rtb_Row1_m;
  } else {
    /* signal < 0 */
    /* '<S82>:1:7' */
    ctrl_TAPM_B.Tc_out = rtb_Row1;
  }

  /* End of MATLAB Function: '<S74>/MATLAB Function1' */

  /* Integrator: '<S6>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_nt,
                       ctrl_TAPM_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_TAPM_DW.Integrator_IWORK.IcNeedsLoading) {
      ctrl_TAPM_X.Integrator_CSTATE_a[0] = 0.0;
      ctrl_TAPM_X.Integrator_CSTATE_a[1] = 0.0;
      ctrl_TAPM_X.Integrator_CSTATE_a[2] = 0.0;
    }
  }

  ctrl_TAPM_B.Integrator[0] = ctrl_TAPM_X.Integrator_CSTATE_a[0];
  ctrl_TAPM_B.Integrator[1] = ctrl_TAPM_X.Integrator_CSTATE_a[1];
  ctrl_TAPM_B.Integrator[2] = ctrl_TAPM_X.Integrator_CSTATE_a[2];

  /* Saturate: '<S60>/Saturation' */
  if (ctrl_TAPM_B.Integrator[2] > ctrl_TAPM_P.Saturation_UpperSat_i) {
    rtb_Row1_m = ctrl_TAPM_P.Saturation_UpperSat_i;
  } else if (ctrl_TAPM_B.Integrator[2] < ctrl_TAPM_P.Saturation_LowerSat_o) {
    rtb_Row1_m = ctrl_TAPM_P.Saturation_LowerSat_o;
  } else {
    rtb_Row1_m = ctrl_TAPM_B.Integrator[2];
  }

  /* End of Saturate: '<S60>/Saturation' */

  /* Signum: '<S60>/Sign' */
  if (rtb_Row1_m < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (rtb_Row1_m > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (rtb_Row1_m == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = rtb_Row1_m;
  }

  /* Gain: '<S60>/Gain' incorporates:
   *  Signum: '<S60>/Sign'
   */
  rtb_psi_dot = ctrl_TAPM_P.Gain_Gain_pg * rtb_TmpSignalConversionAtSFun_2;

  /* Sum: '<S60>/Sum1' */
  rtb_Row1_m += rtb_psi_dot;

  /* Math: '<S60>/Math Function' incorporates:
   *  Constant: '<S60>/Constant'
   */
  rtb_Row1_m = rt_remd_snf(rtb_Row1_m, ctrl_TAPM_P.Constant_Value_kq);

  /* Sum: '<S60>/Sum' */
  ctrl_TAPM_B.Sum = rtb_Row1_m - rtb_psi_dot;

  /* Saturate: '<S61>/Saturation' */
  if (ctrl_TAPM_B.psi_m > ctrl_TAPM_P.Saturation_UpperSat_e) {
    rtb_Row1_m = ctrl_TAPM_P.Saturation_UpperSat_e;
  } else if (ctrl_TAPM_B.psi_m < ctrl_TAPM_P.Saturation_LowerSat_g) {
    rtb_Row1_m = ctrl_TAPM_P.Saturation_LowerSat_g;
  } else {
    rtb_Row1_m = ctrl_TAPM_B.psi_m;
  }

  /* End of Saturate: '<S61>/Saturation' */

  /* Signum: '<S61>/Sign' */
  if (rtb_Row1_m < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (rtb_Row1_m > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (rtb_Row1_m == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = rtb_Row1_m;
  }

  /* Gain: '<S61>/Gain' incorporates:
   *  Signum: '<S61>/Sign'
   */
  rtb_psi_dot = ctrl_TAPM_P.Gain_Gain_f * rtb_TmpSignalConversionAtSFun_2;

  /* Sum: '<S61>/Sum1' */
  rtb_Row1_m += rtb_psi_dot;

  /* Math: '<S61>/Math Function' incorporates:
   *  Constant: '<S61>/Constant'
   */
  rtb_Row1_m = rt_remd_snf(rtb_Row1_m, ctrl_TAPM_P.Constant_Value_p0);

  /* Sum: '<S61>/Sum' */
  rtb_Row1_m -= rtb_psi_dot;

  /* Fcn: '<S6>/Fcn' */
  rtb_psi_dot = rtb_Row1_m;

  /* Integrator: '<S6>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator2_Reset_ZCE,
                       ctrl_TAPM_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator2_CSTATE[0] = (ctrl_TAPM_P.Integrator2_IC[0]);
      ctrl_TAPM_X.Integrator2_CSTATE[1] = (ctrl_TAPM_P.Integrator2_IC[1]);
      ctrl_TAPM_X.Integrator2_CSTATE[2] = (ctrl_TAPM_P.Integrator2_IC[2]);
    }
  }

  ctrl_TAPM_B.Integrator2[0] = ctrl_TAPM_X.Integrator2_CSTATE[0];
  ctrl_TAPM_B.Integrator2[1] = ctrl_TAPM_X.Integrator2_CSTATE[1];
  ctrl_TAPM_B.Integrator2[2] = ctrl_TAPM_X.Integrator2_CSTATE[2];

  /* Sum: '<S6>/Sum' */
  rtb_Sum_on_idx_0 = ctrl_TAPM_B.x_m - ctrl_TAPM_B.Integrator[0];
  rtb_Sum_on_idx_1 = ctrl_TAPM_B.y_m - ctrl_TAPM_B.Integrator[1];
  rtb_Sum_on_idx_2 = rtb_Row1_m - ctrl_TAPM_B.Sum;

  /* Product: '<S6>/Matrix Multiply2' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_MatrixMultiply[b_ixstart] = 0.0;
    rtb_MatrixMultiply[b_ixstart] += ctrl_TAPM_B.sf_Kd_p.K_d[b_ixstart] *
      rtb_Sum_on_idx_0;
    rtb_MatrixMultiply[b_ixstart] += ctrl_TAPM_B.sf_Kd_p.K_d[b_ixstart + 3] *
      rtb_Sum_on_idx_1;
    rtb_MatrixMultiply[b_ixstart] += ctrl_TAPM_B.sf_Kd_p.K_d[b_ixstart + 6] *
      rtb_Sum_on_idx_2;
  }

  /* End of Product: '<S6>/Matrix Multiply2' */

  /* Fcn: '<S58>/Row2' */
  rtb_TmpSignalConversionAtSFun_2 = rtb_MatrixMultiply[0];
  rtb_TmpSignalConversionAtSFun_1 = rtb_MatrixMultiply[1];

  /* Fcn: '<S58>/Row3' */
  rtb_TmpSignalConversionAtSFun_0 = rtb_MatrixMultiply[2];

  /* Sum: '<S6>/Sum2' incorporates:
   *  Fcn: '<S58>/Row1'
   *  Fcn: '<S58>/Row2'
   *  Fcn: '<S58>/Row3'
   *  Fcn: '<S6>/Fcn'
   */
  rtb_MatrixMultiply[0] = (cos(rtb_Row1_m) * rtb_MatrixMultiply[0] + sin
    (rtb_Row1_m) * rtb_MatrixMultiply[1]) + rtb_Sum3[0];
  rtb_MatrixMultiply[1] = (-sin(rtb_Row1_m) * rtb_TmpSignalConversionAtSFun_2 +
    cos(rtb_Row1_m) * rtb_TmpSignalConversionAtSFun_1) + rtb_Sum3[1];
  rtb_MatrixMultiply[2] = rtb_TmpSignalConversionAtSFun_0 + rtb_Sum3[2];

  /* MATLAB Function: '<S6>/C(nu)*nu' */
  /* MATLAB Function 'Nonlinear Passisve Observer/D(nu)*nu': '<S56>:1' */
  /* '<S56>:1:3' */
  /* '<S56>:1:4' */
  /* '<S56>:1:5' */
  /* % DAMPING  */
  /*  Surge: */
  /*  Based on fitting of towing data from -0.8 < u < 0.8 m/s */
  /* '<S56>:1:11' */
  /*  Sway: */
  /*  Based on fitting of towing data from -0.45 < u < 0.45 m/s */
  /* '<S56>:1:17' */
  /*  Yaw: */
  /*  Based on fitting of towing data from -8 < u < 8 deg/s */
  /*  The fitting range is limited. Towing should be performed for higher */
  /*  velocities. */
  /* '<S56>:1:25' */
  /*  Y_vvv og N_rrr er fra curvefitting uten minus, men ser ut til å fungere */
  /*  med minus.  */
  /* % Assembly of the damping matrix */
  /* '<S56>:1:40' */
  /* '<S56>:1:41' */
  /* '<S56>:1:42' */
  /*  Y_r + Y_rr*abs(r) + Y_rrr*r^2 + Y_vr*abs(v); Not verified, temporarily disabled */
  /*  N_v + N_vv*abs(v) + N_vvv*v^2 + N_rv*abs(r); Not verified, temporarily disabled */
  /* '<S56>:1:47' */
  /* '<S56>:1:54' */
  /* MATLAB Function 'Nonlinear Passisve Observer/C(nu)*nu': '<S55>:1' */
  /* '<S55>:1:3' */
  /* '<S55>:1:4' */
  /* '<S55>:1:5' */
  /* % MATRICES */
  /* 0.0432; */
  /* % Added mass */
  /* % Correolis matrix */
  /* '<S55>:1:14' */
  rtb_Row2 = -99.03 * ctrl_TAPM_B.Integrator1[1] - -0.525 *
    ctrl_TAPM_B.Integrator1[2];

  /* '<S55>:1:15' */
  rtb_Row1 = 124.658 * ctrl_TAPM_B.Integrator1[0];

  /* Sum: '<S6>/Sum3' incorporates:
   *  Fcn: '<S59>/Row1'
   *  Fcn: '<S59>/Row2'
   *  Fcn: '<S59>/Row3'
   *  Fcn: '<S6>/Fcn'
   */
  /* '<S55>:1:17' */
  /* '<S55>:1:24' */
  tmp_0[0] = cos(rtb_Row1_m) * ctrl_TAPM_B.Integrator2[0] + sin(rtb_Row1_m) *
    ctrl_TAPM_B.Integrator2[1];
  tmp_0[1] = -sin(rtb_Row1_m) * ctrl_TAPM_B.Integrator2[0] + cos(rtb_Row1_m) *
    ctrl_TAPM_B.Integrator2[1];
  tmp_0[2] = ctrl_TAPM_B.Integrator2[2];

  /* MATLAB Function: '<S6>/D(nu)*nu' */
  tmp_1[0] = (0.0 * fabs(ctrl_TAPM_B.Integrator1[0]) + -2.332) +
    ctrl_TAPM_B.Integrator1[0] * ctrl_TAPM_B.Integrator1[0] * -8.557;
  tmp_1[3] = 0.0;
  tmp_1[6] = 0.0;
  tmp_1[1] = 0.0;
  tmp_1[4] = (0.3976 * fabs(ctrl_TAPM_B.Integrator1[1]) + -4.673) +
    ctrl_TAPM_B.Integrator1[1] * ctrl_TAPM_B.Integrator1[1] * -313.3;
  tmp_1[7] = 0.0;
  tmp_1[2] = 0.0;
  tmp_1[5] = 0.0;
  tmp_1[8] = (-0.01148 * fabs(ctrl_TAPM_B.Integrator1[2]) + -0.01675) +
    ctrl_TAPM_B.Integrator1[2] * ctrl_TAPM_B.Integrator1[2] * -0.0003578;
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    S_singular_cross[3 * b_ixstart] = -tmp_1[3 * b_ixstart];
    S_singular_cross[1 + 3 * b_ixstart] = -tmp_1[3 * b_ixstart + 1];
    S_singular_cross[2 + 3 * b_ixstart] = -tmp_1[3 * b_ixstart + 2];
  }

  /* MATLAB Function: '<S6>/C(nu)*nu' */
  tmp_2[0] = 0.0;
  tmp_2[3] = 0.0;
  tmp_2[6] = rtb_Row2;
  tmp_2[1] = 0.0;
  tmp_2[4] = 0.0;
  tmp_2[7] = rtb_Row1;
  tmp_2[2] = -rtb_Row2;
  tmp_2[5] = -rtb_Row1;
  tmp_2[8] = 0.0;

  /* Sum: '<S6>/Sum3' incorporates:
   *  MATLAB Function: '<S6>/D(nu)*nu'
   */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_Sum3[b_ixstart] = (tmp_0[b_ixstart] + rtb_MatrixMultiply[b_ixstart]) -
      ((S_singular_cross[b_ixstart + 3] * ctrl_TAPM_B.Integrator1[1] +
        S_singular_cross[b_ixstart] * ctrl_TAPM_B.Integrator1[0]) +
       S_singular_cross[b_ixstart + 6] * ctrl_TAPM_B.Integrator1[2]);
  }

  /* MATLAB Function: '<S6>/C(nu)*nu' incorporates:
   *  Sum: '<S6>/Sum3'
   */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    tmp_0[b_ixstart] = tmp_2[b_ixstart + 6] * ctrl_TAPM_B.Integrator1[2] +
      (tmp_2[b_ixstart + 3] * ctrl_TAPM_B.Integrator1[1] + tmp_2[b_ixstart] *
       ctrl_TAPM_B.Integrator1[0]);
  }

  /* Sum: '<S6>/Sum3' */
  rtb_MatrixMultiply[0] = rtb_Sum3[0] - tmp_0[0];
  rtb_MatrixMultiply[1] = rtb_Sum3[1] - tmp_0[1];
  rtb_MatrixMultiply[2] = rtb_Sum3[2] - tmp_0[2];

  /* Gain: '<S6>/M^-1' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    ctrl_TAPM_B.M1[b_ixstart] = 0.0;
    ctrl_TAPM_B.M1[b_ixstart] += ctrl_TAPM_P.M1_Gain[b_ixstart] *
      rtb_MatrixMultiply[0];
    ctrl_TAPM_B.M1[b_ixstart] += ctrl_TAPM_P.M1_Gain[b_ixstart + 3] *
      rtb_MatrixMultiply[1];
    ctrl_TAPM_B.M1[b_ixstart] += ctrl_TAPM_P.M1_Gain[b_ixstart + 6] *
      rtb_MatrixMultiply[2];
  }

  /* End of Gain: '<S6>/M^-1' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S9>/Gain' */
    ctrl_TAPM_B.Gain[0] = ctrl_TAPM_P.Gain_Gain_f0 * ctrl_TAPM_B.Saturation1;
    ctrl_TAPM_B.Gain[1] = ctrl_TAPM_P.Gain_Gain_f0 * ctrl_TAPM_B.Saturation2;
    ctrl_TAPM_B.Gain[2] = ctrl_TAPM_P.Gain_Gain_f0 * ctrl_TAPM_B.Saturation3;
    ctrl_TAPM_B.Gain[3] = ctrl_TAPM_P.Gain_Gain_f0 * ctrl_TAPM_B.Saturation4;
    ctrl_TAPM_B.Gain[4] = ctrl_TAPM_P.Gain_Gain_f0 * ctrl_TAPM_B.Saturation5;
    ctrl_TAPM_B.Gain[5] = ctrl_TAPM_P.Gain_Gain_f0 * ctrl_TAPM_B.Saturation6;
  }

  /* MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' incorporates:
   *  Constant: '<Root>/X-position Thruster'
   *  Constant: '<Root>/Y-position Thruster'
   */
  /* MATLAB Function 'Finding commanded forces in: [Surge,Sway,Yaw]': '<S2>:1' */
  /* '<S2>:1:4' */
  /* '<S2>:1:5' */
  /* '<S2>:1:6' */
  /* '<S2>:1:10' */
  ctrl_TAPM_B.commanded_tau[0] = 0.0;
  ctrl_TAPM_B.commanded_tau[1] = 0.0;
  ctrl_TAPM_B.commanded_tau[2] = 0.0;
  rtb_Row2 = ctrl_TAPM_B.Gain[0];
  ctrl_TAPM_cosd(&rtb_Row2);
  rtb_Row1 = ctrl_TAPM_B.Gain[1];
  ctrl_TAPM_cosd(&rtb_Row1);
  rtb_Row1_m = ctrl_TAPM_B.Gain[2];
  ctrl_TAPM_cosd(&rtb_Row1_m);
  rtb_commandedAngle_CoreSubsysCa = ctrl_TAPM_B.Gain[3];
  ctrl_TAPM_cosd(&rtb_commandedAngle_CoreSubsysCa);
  rtb_TmpSignalConversionAtSFun_2 = ctrl_TAPM_B.Gain[4];
  ctrl_TAPM_cosd(&rtb_TmpSignalConversionAtSFun_2);
  g = ctrl_TAPM_B.Gain[5];
  ctrl_TAPM_cosd(&g);
  h = ctrl_TAPM_B.Gain[0];
  ctrl_TAPM_sind(&h);
  rtb_TmpSignalConversionAtSFun_1 = ctrl_TAPM_B.Gain[1];
  ctrl_TAPM_sind(&rtb_TmpSignalConversionAtSFun_1);
  rtb_TmpSignalConversionAtSFun_0 = ctrl_TAPM_B.Gain[2];
  ctrl_TAPM_sind(&rtb_TmpSignalConversionAtSFun_0);
  Alpha1_idx_2 = ctrl_TAPM_B.Gain[3];
  ctrl_TAPM_sind(&Alpha1_idx_2);
  Alpha1_idx_3 = ctrl_TAPM_B.Gain[4];
  ctrl_TAPM_sind(&Alpha1_idx_3);
  Alpha1_idx_4 = ctrl_TAPM_B.Gain[5];
  ctrl_TAPM_sind(&Alpha1_idx_4);
  n = ctrl_TAPM_B.Gain[0];
  ctrl_TAPM_sind(&n);
  o = ctrl_TAPM_B.Gain[0];
  ctrl_TAPM_cosd(&o);
  p = ctrl_TAPM_B.Gain[1];
  ctrl_TAPM_sind(&p);
  q = ctrl_TAPM_B.Gain[1];
  ctrl_TAPM_cosd(&q);
  r = ctrl_TAPM_B.Gain[2];
  ctrl_TAPM_sind(&r);
  s_0 = ctrl_TAPM_B.Gain[2];
  ctrl_TAPM_cosd(&s_0);
  t = ctrl_TAPM_B.Gain[3];
  ctrl_TAPM_sind(&t);
  u = ctrl_TAPM_B.Gain[3];
  ctrl_TAPM_cosd(&u);
  v = ctrl_TAPM_B.Gain[4];
  ctrl_TAPM_sind(&v);
  w = ctrl_TAPM_B.Gain[4];
  ctrl_TAPM_cosd(&w);
  x = ctrl_TAPM_B.Gain[5];
  ctrl_TAPM_sind(&x);
  y = ctrl_TAPM_B.Gain[5];
  ctrl_TAPM_cosd(&y);
  rtb_Row2_0[0] = rtb_Row2;
  rtb_Row2_0[3] = rtb_Row1;
  rtb_Row2_0[6] = rtb_Row1_m;
  rtb_Row2_0[9] = rtb_commandedAngle_CoreSubsysCa;
  rtb_Row2_0[12] = rtb_TmpSignalConversionAtSFun_2;
  rtb_Row2_0[15] = g;
  rtb_Row2_0[1] = h;
  rtb_Row2_0[4] = rtb_TmpSignalConversionAtSFun_1;
  rtb_Row2_0[7] = rtb_TmpSignalConversionAtSFun_0;
  rtb_Row2_0[10] = Alpha1_idx_2;
  rtb_Row2_0[13] = Alpha1_idx_3;
  rtb_Row2_0[16] = Alpha1_idx_4;
  rtb_Row2_0[2] = n * ctrl_TAPM_P.XpositionThruster_Value_e[0] - o *
    ctrl_TAPM_P.YpositionThruster_Value_o[0];
  rtb_Row2_0[5] = p * ctrl_TAPM_P.XpositionThruster_Value_e[1] - q *
    ctrl_TAPM_P.YpositionThruster_Value_o[1];
  rtb_Row2_0[8] = r * ctrl_TAPM_P.XpositionThruster_Value_e[2] - s_0 *
    ctrl_TAPM_P.YpositionThruster_Value_o[2];
  rtb_Row2_0[11] = t * ctrl_TAPM_P.XpositionThruster_Value_e[3] - u *
    ctrl_TAPM_P.YpositionThruster_Value_o[3];
  rtb_Row2_0[14] = v * ctrl_TAPM_P.XpositionThruster_Value_e[4] - w *
    ctrl_TAPM_P.YpositionThruster_Value_o[4];
  rtb_Row2_0[17] = x * ctrl_TAPM_P.XpositionThruster_Value_e[5] - y *
    ctrl_TAPM_P.YpositionThruster_Value_o[5];
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    ctrl_TAPM_B.commanded_tau[b_ixstart] = 0.0;
    for (i = 0; i < 6; i++) {
      ctrl_TAPM_B.commanded_tau[b_ixstart] += rtb_Row2_0[3 * i + b_ixstart] *
        ctrl_TAPM_B.Saturation7[i];
    }
  }

  /* End of MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */

  /* Integrator: '<S19>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator2_Reset_ZCE_h,
                       ctrl_TAPM_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator2_CSTATE_c[0] = ctrl_TAPM_P.Integrator2_IC_p;
      ctrl_TAPM_X.Integrator2_CSTATE_c[1] = ctrl_TAPM_P.Integrator2_IC_p;
      ctrl_TAPM_X.Integrator2_CSTATE_c[2] = ctrl_TAPM_P.Integrator2_IC_p;
    }
  }

  rtb_MatrixMultiply[0] = ctrl_TAPM_X.Integrator2_CSTATE_c[0];
  rtb_MatrixMultiply[1] = ctrl_TAPM_X.Integrator2_CSTATE_c[1];
  rtb_MatrixMultiply[2] = ctrl_TAPM_X.Integrator2_CSTATE_c[2];

  /* MATLAB Function: '<S19>/w_d^-2' */
  /* MATLAB Function 'Guidance/Reference model/w_d^3': '<S24>:1' */
  /* '<S24>:1:4' */
  /* MATLAB Function 'Guidance/Reference model/w_d^-2': '<S23>:1' */
  /* '<S23>:1:4' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      rtb_y_j[b_ixstart + 3 * i] = 0.0;
      rtb_y_j[b_ixstart + 3 * i] += rtb_w_d[3 * i] * rtb_w_d[b_ixstart];
      rtb_y_j[b_ixstart + 3 * i] += rtb_w_d[3 * i + 1] * rtb_w_d[b_ixstart + 3];
      rtb_y_j[b_ixstart + 3 * i] += rtb_w_d[3 * i + 2] * rtb_w_d[b_ixstart + 6];
    }
  }

  memcpy(&S_singular_cross[0], &rtb_y_j[0], 9U * sizeof(real_T));
  ixstart = 0;
  b_ixstart = 3;
  p3 = 6;
  rtb_Row2 = fabs(rtb_y_j[0]);
  rtb_Row1 = fabs(rtb_y_j[1]);
  rtb_Row1_m = fabs(rtb_y_j[2]);
  if ((rtb_Row1 > rtb_Row2) && (rtb_Row1 > rtb_Row1_m)) {
    ixstart = 3;
    b_ixstart = 0;
    S_singular_cross[0] = rtb_y_j[1];
    S_singular_cross[1] = rtb_y_j[0];
    S_singular_cross[3] = rtb_y_j[4];
    S_singular_cross[4] = rtb_y_j[3];
    S_singular_cross[6] = rtb_y_j[7];
    S_singular_cross[7] = rtb_y_j[6];
  } else {
    if (rtb_Row1_m > rtb_Row2) {
      ixstart = 6;
      p3 = 0;
      S_singular_cross[0] = rtb_y_j[2];
      S_singular_cross[2] = rtb_y_j[0];
      S_singular_cross[3] = rtb_y_j[5];
      S_singular_cross[5] = rtb_y_j[3];
      S_singular_cross[6] = rtb_y_j[8];
      S_singular_cross[8] = rtb_y_j[6];
    }
  }

  rtb_Row2 = S_singular_cross[1] / S_singular_cross[0];
  S_singular_cross[1] /= S_singular_cross[0];
  rtb_Row1 = S_singular_cross[2] / S_singular_cross[0];
  S_singular_cross[2] /= S_singular_cross[0];
  S_singular_cross[4] -= rtb_Row2 * S_singular_cross[3];
  S_singular_cross[5] -= rtb_Row1 * S_singular_cross[3];
  S_singular_cross[7] -= rtb_Row2 * S_singular_cross[6];
  S_singular_cross[8] -= rtb_Row1 * S_singular_cross[6];
  if (fabs(S_singular_cross[5]) > fabs(S_singular_cross[4])) {
    i = b_ixstart;
    b_ixstart = p3;
    p3 = i;
    S_singular_cross[1] = rtb_Row1;
    S_singular_cross[2] = rtb_Row2;
    rtb_Row2 = S_singular_cross[4];
    S_singular_cross[4] = S_singular_cross[5];
    S_singular_cross[5] = rtb_Row2;
    rtb_Row2 = S_singular_cross[7];
    S_singular_cross[7] = S_singular_cross[8];
    S_singular_cross[8] = rtb_Row2;
  }

  rtb_Row1_m = S_singular_cross[5];
  rtb_commandedAngle_CoreSubsysCa = S_singular_cross[4];
  rtb_Row2 = S_singular_cross[5] / S_singular_cross[4];
  S_singular_cross[8] -= rtb_Row2 * S_singular_cross[7];
  rtb_Row2 = (rtb_Row2 * S_singular_cross[1] - S_singular_cross[2]) /
    S_singular_cross[8];
  rtb_Row1 = -(S_singular_cross[7] * rtb_Row2 + S_singular_cross[1]) /
    S_singular_cross[4];
  rtb_y_j[ixstart] = ((1.0 - S_singular_cross[3] * rtb_Row1) - S_singular_cross
                      [6] * rtb_Row2) / S_singular_cross[0];
  rtb_y_j[ixstart + 1] = rtb_Row1;
  rtb_y_j[ixstart + 2] = rtb_Row2;
  rtb_Row2 = -(rtb_Row1_m / rtb_commandedAngle_CoreSubsysCa) / S_singular_cross
    [8];
  rtb_Row1 = (1.0 - S_singular_cross[7] * rtb_Row2) / S_singular_cross[4];
  rtb_y_j[b_ixstart] = -(S_singular_cross[3] * rtb_Row1 + S_singular_cross[6] *
    rtb_Row2) / S_singular_cross[0];
  rtb_y_j[b_ixstart + 1] = rtb_Row1;
  rtb_y_j[b_ixstart + 2] = rtb_Row2;
  rtb_Row2 = 1.0 / S_singular_cross[8];
  rtb_Row1 = -S_singular_cross[7] * rtb_Row2 / S_singular_cross[4];
  rtb_y_j[p3] = -(S_singular_cross[3] * rtb_Row1 + S_singular_cross[6] *
                  rtb_Row2) / S_singular_cross[0];
  rtb_y_j[p3 + 1] = rtb_Row1;
  rtb_y_j[p3 + 2] = rtb_Row2;

  /* End of MATLAB Function: '<S19>/w_d^-2' */

  /* Product: '<S19>/Matrix Multiply1' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_MatrixMultiply2[b_ixstart] = 0.0;
    rtb_MatrixMultiply2[b_ixstart] += rtb_y_j[b_ixstart] * rtb_MatrixMultiply[0];
    rtb_MatrixMultiply2[b_ixstart] += rtb_y_j[b_ixstart + 3] *
      rtb_MatrixMultiply[1];
    rtb_MatrixMultiply2[b_ixstart] += rtb_y_j[b_ixstart + 6] *
      rtb_MatrixMultiply[2];
  }

  /* End of Product: '<S19>/Matrix Multiply1' */

  /* Sum: '<S19>/Sum' */
  rtb_MatrixMultiply2[0] = ctrl_TAPM_B.x_ref - rtb_MatrixMultiply2[0];
  rtb_MatrixMultiply2[1] = ctrl_TAPM_B.y_ref - rtb_MatrixMultiply2[1];
  rtb_MatrixMultiply2[2] = ctrl_TAPM_B.psi_ref - rtb_MatrixMultiply2[2];

  /* MATLAB Function: '<S19>/w_d^3' incorporates:
   *  Product: '<S19>/Matrix Multiply'
   */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      rtb_y_j[b_ixstart + 3 * i] = 0.0;
      rtb_y_j[b_ixstart + 3 * i] += rtb_w_d[3 * i] * rtb_w_d[b_ixstart];
      rtb_y_j[b_ixstart + 3 * i] += rtb_w_d[3 * i + 1] * rtb_w_d[b_ixstart + 3];
      rtb_y_j[b_ixstart + 3 * i] += rtb_w_d[3 * i + 2] * rtb_w_d[b_ixstart + 6];
    }
  }

  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      S_singular_cross[b_ixstart + 3 * i] = 0.0;
      S_singular_cross[b_ixstart + 3 * i] += rtb_y_j[3 * i] * rtb_w_d[b_ixstart];
      S_singular_cross[b_ixstart + 3 * i] += rtb_y_j[3 * i + 1] *
        rtb_w_d[b_ixstart + 3];
      S_singular_cross[b_ixstart + 3 * i] += rtb_y_j[3 * i + 2] *
        rtb_w_d[b_ixstart + 6];
    }
  }

  /* End of MATLAB Function: '<S19>/w_d^3' */

  /* Product: '<S19>/Matrix Multiply' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    ctrl_TAPM_B.MatrixMultiply[b_ixstart] = 0.0;
    ctrl_TAPM_B.MatrixMultiply[b_ixstart] += S_singular_cross[b_ixstart] *
      rtb_MatrixMultiply2[0];
    ctrl_TAPM_B.MatrixMultiply[b_ixstart] += S_singular_cross[b_ixstart + 3] *
      rtb_MatrixMultiply2[1];
    ctrl_TAPM_B.MatrixMultiply[b_ixstart] += S_singular_cross[b_ixstart + 6] *
      rtb_MatrixMultiply2[2];
  }

  /* MATLAB Function: '<S19>/w_d*w_d' incorporates:
   *  Product: '<S19>/Matrix Multiply2'
   */
  /* MATLAB Function 'Guidance/Reference model/w_d*w_d': '<S21>:1' */
  /* '<S21>:1:4' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      rtb_y_j[b_ixstart + 3 * i] = 0.0;
      rtb_y_j[b_ixstart + 3 * i] += rtb_w_d[3 * i] * rtb_w_d[b_ixstart];
      rtb_y_j[b_ixstart + 3 * i] += rtb_w_d[3 * i + 1] * rtb_w_d[b_ixstart + 3];
      rtb_y_j[b_ixstart + 3 * i] += rtb_w_d[3 * i + 2] * rtb_w_d[b_ixstart + 6];
    }
  }

  /* End of MATLAB Function: '<S19>/w_d*w_d' */

  /* Product: '<S19>/Matrix Multiply2' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_MatrixMultiply2[b_ixstart] = 0.0;
    rtb_MatrixMultiply2[b_ixstart] += rtb_y_j[b_ixstart] *
      ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[0];
    rtb_MatrixMultiply2[b_ixstart] += rtb_y_j[b_ixstart + 3] *
      ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[1];
    rtb_MatrixMultiply2[b_ixstart] += rtb_y_j[b_ixstart + 6] *
      ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[2];
  }

  /* MATLAB Function: '<S45>/zeta' incorporates:
   *  SignalConversion: '<S51>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Input1/Guidance gains/zeta': '<S51>:1' */
  /* '<S51>:1:4' */
  memset(&rtb_y_j[0], 0, 9U * sizeof(real_T));
  rtb_y_j[0] = ctrl_TAPM_B.zeta_x;
  rtb_y_j[4] = ctrl_TAPM_B.zeta_y;
  rtb_y_j[8] = ctrl_TAPM_B.zeta_psi;

  /* MATLAB Function: '<S19>/w_d*w_d1' incorporates:
   *  Product: '<S19>/Matrix Multiply5'
   */
  /* MATLAB Function 'Guidance/Reference model/w_d*w_d1': '<S22>:1' */
  /* '<S22>:1:4' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      tmp_1[b_ixstart + 3 * i] = 0.0;
      tmp_1[b_ixstart + 3 * i] += 2.0 * rtb_y_j[b_ixstart] * rtb_w_d[3 * i];
      tmp_1[b_ixstart + 3 * i] += rtb_y_j[b_ixstart + 3] * 2.0 * rtb_w_d[3 * i +
        1];
      tmp_1[b_ixstart + 3 * i] += rtb_y_j[b_ixstart + 6] * 2.0 * rtb_w_d[3 * i +
        2];
    }
  }

  /* End of MATLAB Function: '<S19>/w_d*w_d1' */

  /* Product: '<S19>/Matrix Multiply5' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_MatrixMultiply5[b_ixstart] = 0.0;
    rtb_MatrixMultiply5[b_ixstart] += tmp_1[b_ixstart] *
      ctrl_TAPM_B.Integrator3[0];
    rtb_MatrixMultiply5[b_ixstart] += tmp_1[b_ixstart + 3] *
      ctrl_TAPM_B.Integrator3[1];
    rtb_MatrixMultiply5[b_ixstart] += tmp_1[b_ixstart + 6] *
      ctrl_TAPM_B.Integrator3[2];
  }

  /* Sum: '<S19>/Sum5' incorporates:
   *  Sum: '<S19>/Sum2'
   */
  ctrl_TAPM_B.Sum5[0] = (rtb_MatrixMultiply[0] - rtb_MatrixMultiply2[0]) -
    rtb_MatrixMultiply5[0];
  ctrl_TAPM_B.Sum5[1] = (rtb_MatrixMultiply[1] - rtb_MatrixMultiply2[1]) -
    rtb_MatrixMultiply5[1];
  ctrl_TAPM_B.Sum5[2] = (rtb_MatrixMultiply[2] - rtb_MatrixMultiply2[2]) -
    rtb_MatrixMultiply5[2];
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* MATLAB Function: '<S46>/Kp' incorporates:
     *  Constant: '<S46>/Constant'
     *  Constant: '<S46>/Constant1'
     *  Constant: '<S46>/Constant2'
     */
    ctrl_TAPM_Kp(ctrl_TAPM_P.Constant_Value_c, ctrl_TAPM_P.Constant1_Value_p,
                 ctrl_TAPM_P.Constant2_Value, &ctrl_TAPM_B.sf_Kp_m);

    /* MATLAB Function: '<S46>/Ki' incorporates:
     *  Constant: '<S46>/Constant3'
     *  Constant: '<S46>/Constant4'
     *  Constant: '<S46>/Constant5'
     */
    ctrl_TAPM_Ki(ctrl_TAPM_P.Constant3_Value_f, ctrl_TAPM_P.Constant4_Value_a,
                 ctrl_TAPM_P.Constant5_Value_j, &ctrl_TAPM_B.sf_Ki_k);
  }

  /* Product: '<S6>/Matrix Multiply' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_MatrixMultiply[b_ixstart] = 0.0;
    rtb_MatrixMultiply[b_ixstart] += ctrl_TAPM_B.sf_Kp_m.K_p[b_ixstart] *
      rtb_Sum_on_idx_0;
    rtb_MatrixMultiply[b_ixstart] += ctrl_TAPM_B.sf_Kp_m.K_p[b_ixstart + 3] *
      rtb_Sum_on_idx_1;
    rtb_MatrixMultiply[b_ixstart] += ctrl_TAPM_B.sf_Kp_m.K_p[b_ixstart + 6] *
      rtb_Sum_on_idx_2;
  }

  /* End of Product: '<S6>/Matrix Multiply' */

  /* Product: '<S6>/Matrix Multiply1' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    ctrl_TAPM_B.MatrixMultiply1[b_ixstart] = 0.0;
    ctrl_TAPM_B.MatrixMultiply1[b_ixstart] += ctrl_TAPM_B.sf_Ki_k.K_i[b_ixstart]
      * rtb_Sum_on_idx_0;
    ctrl_TAPM_B.MatrixMultiply1[b_ixstart] += ctrl_TAPM_B.sf_Ki_k.K_i[b_ixstart
      + 3] * rtb_Sum_on_idx_1;
    ctrl_TAPM_B.MatrixMultiply1[b_ixstart] += ctrl_TAPM_B.sf_Ki_k.K_i[b_ixstart
      + 6] * rtb_Sum_on_idx_2;
  }

  /* End of Product: '<S6>/Matrix Multiply1' */

  /* Sum: '<S6>/Sum1' incorporates:
   *  Fcn: '<S57>/Fcn'
   *  Fcn: '<S57>/Fcn1'
   *  Fcn: '<S57>/Fcn2'
   */
  ctrl_TAPM_B.Sum1[0] = (cos(rtb_psi_dot) * ctrl_TAPM_B.Integrator1[0] - sin
    (rtb_psi_dot) * ctrl_TAPM_B.Integrator1[1]) + rtb_MatrixMultiply[0];
  ctrl_TAPM_B.Sum1[1] = (sin(rtb_psi_dot) * ctrl_TAPM_B.Integrator1[0] + cos
    (rtb_psi_dot) * ctrl_TAPM_B.Integrator1[1]) + rtb_MatrixMultiply[1];
  ctrl_TAPM_B.Sum1[2] = rtb_MatrixMultiply[2] + ctrl_TAPM_B.Integrator1[2];
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* SignalConversion: '<S8>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFile[0] = ctrl_TAPM_B.X_oqus;
    rtb_TmpSignalConversionAtToFile[1] = ctrl_TAPM_B.Y_oqus;
    rtb_TmpSignalConversionAtToFile[2] = ctrl_TAPM_B.Z_oqus;
    rtb_TmpSignalConversionAtToFile[3] = ctrl_TAPM_B.roll_oqus;
    rtb_TmpSignalConversionAtToFile[4] = ctrl_TAPM_B.pitch_oqus;
    rtb_TmpSignalConversionAtToFile[5] = ctrl_TAPM_B.yaw_oqus;

    /* ToFile: '<S8>/To File' */
    {
      if (!(++ctrl_TAPM_DW.ToFile_IWORK.Decimation % 1) &&
          (ctrl_TAPM_DW.ToFile_IWORK.Count*7)+1 < 100000000 ) {
        FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[7];
          ctrl_TAPM_DW.ToFile_IWORK.Decimation = 0;
          u[0] = ctrl_TAPM_M->Timing.t[1];
          u[1] = rtb_TmpSignalConversionAtToFile[0];
          u[2] = rtb_TmpSignalConversionAtToFile[1];
          u[3] = rtb_TmpSignalConversionAtToFile[2];
          u[4] = rtb_TmpSignalConversionAtToFile[3];
          u[5] = rtb_TmpSignalConversionAtToFile[4];
          u[6] = rtb_TmpSignalConversionAtToFile[5];
          if (fwrite(u, sizeof(real_T), 7, fp) != 7) {
            rtmSetErrorStatus(ctrl_TAPM_M,
                              "Error writing to MAT-file oqus_measured.mat");
            return;
          }

          if (((++ctrl_TAPM_DW.ToFile_IWORK.Count)*7)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file oqus_measured.mat.\n");
          }
        }
      }
    }

    /* Delay: '<S12>/Delay' */
    for (i = 0; i < 6; i++) {
      ctrl_TAPM_B.Delay[i] = ctrl_TAPM_DW.Delay_DSTATE[i];
    }

    /* End of Delay: '<S12>/Delay' */

    /* Delay: '<S75>/Delay' */
    ctrl_TAPM_B.Delay_e = ctrl_TAPM_DW.Delay_DSTATE_f;

    /* Delay: '<S90>/Delay' */
    ctrl_TAPM_B.Delay_a = ctrl_TAPM_DW.Delay_DSTATE_fu;
  }

  /* MATLAB Function: '<S90>/MATLAB Function' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Tf1'
   *  Constant: '<S11>/K_Tr1'
   *  Constant: '<S11>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/MATLAB Function': '<S94>:1' */
  /* '<S94>:1:5' */
  if (rtb_sys[6] < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (rtb_sys[6] > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (rtb_sys[6] == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = rtb_sys[6];
  }

  rtb_Row2 = sqrt(fabs(rtb_sys[6]) / (ctrl_TAPM_P.Rho * rt_powd_snf
    (ctrl_TAPM_P.D, 4.0) * ctrl_TAPM_P.K_T1f)) * rtb_TmpSignalConversionAtSFun_2;

  /* '<S94>:1:7' */
  rtb_Row1 = tanh(ctrl_TAPM_P.eps_c * rtb_Row2 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S94>:1:8' */
  /* '<S94>:1:10' */
  if (ctrl_TAPM_B.Delay_a < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (ctrl_TAPM_B.Delay_a > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (ctrl_TAPM_B.Delay_a == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = ctrl_TAPM_B.Delay_a;
  }

  rtb_T_r_e = ((1.0 - rtb_Row1) * ctrl_TAPM_P.K_T1r + ctrl_TAPM_P.K_T1f *
               rtb_Row1) * rtb_TmpSignalConversionAtSFun_2 * ctrl_TAPM_P.Rho *
    rt_powd_snf(ctrl_TAPM_P.D, 4.0) * (ctrl_TAPM_B.Delay_a * ctrl_TAPM_B.Delay_a);
  ctrl_TAPM_B.n_d_h = rtb_Row2;

  /* End of MATLAB Function: '<S90>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S90>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S90>/Constant1'
     *  Constant: '<S90>/Constant2'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp = (ctrl_TAPM_B.n_d_h -
      ctrl_TAPM_P.Constant2_Value_b[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states[0]) -
      ctrl_TAPM_P.Constant2_Value_b[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states[1];
    ctrl_TAPM_B.DiscreteTransferFcn = (ctrl_TAPM_P.Constant1_Value_o[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp + ctrl_TAPM_P.Constant1_Value_o[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states[0]) +
      ctrl_TAPM_P.Constant1_Value_o[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states[1];

    /* SampleTimeMath: '<S93>/TSamp'
     *
     * About '<S93>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp = ctrl_TAPM_B.DiscreteTransferFcn * ctrl_TAPM_P.TSamp_WtEt;

    /* Sum: '<S93>/Diff' incorporates:
     *  UnitDelay: '<S93>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp - ctrl_TAPM_DW.UD_DSTATE;

    /* RateLimiter: '<S90>/Acceleration Limit' */
    rtb_Row2 = rtb_Sum_b - ctrl_TAPM_DW.PrevY;
    if (rtb_Row2 > ctrl_TAPM_P.AccelerationLimit_RisingLim) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY + ctrl_TAPM_P.AccelerationLimit_RisingLim;
    } else {
      if (rtb_Row2 < ctrl_TAPM_P.AccelerationLimit_FallingLim) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY +
          ctrl_TAPM_P.AccelerationLimit_FallingLim;
      }
    }

    ctrl_TAPM_DW.PrevY = rtb_Sum_b;

    /* End of RateLimiter: '<S90>/Acceleration Limit' */

    /* Gain: '<S90>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation = ctrl_TAPM_P.I_s * 2.0 * 3.1415926535897931
      * rtb_Sum_b;

    /* Sum: '<S90>/Sum1' incorporates:
     *  Gain: '<S90>/Qf_0'
     *  Gain: '<S90>/Qff_0(nr)'
     *  Gain: '<S90>/Qff_1(nr)'
     *  Trigonometry: '<S90>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_n = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn) * ctrl_TAPM_P.Q_f0 + ctrl_TAPM_P.K_omega *
      2.0 * 3.1415926535897931 * ctrl_TAPM_B.DiscreteTransferFcn;

    /* Memory: '<S90>/Memory' */
    ctrl_TAPM_B.Memory = ctrl_TAPM_DW.Memory_PreviousInput;

    /* Sum: '<S92>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn - ctrl_TAPM_B.Delay[0];

    /* Gain: '<S92>/Kp' */
    ctrl_TAPM_B.Kp = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S92>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_o3,
                       ctrl_TAPM_B.reset_kk);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_e = ctrl_TAPM_P.Integrator_IC_a;
    }
  }

  rtb_Integrator_g = ctrl_TAPM_X.Integrator_CSTATE_e;

  /* MATLAB Function: '<S92>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant3'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Qr1'
   *  Constant: '<S11>/K_Qr7'
   *  Constant: '<S11>/K_Tf1'
   *  Constant: '<S11>/K_Tr1'
   *  Constant: '<S11>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay[0], ctrl_TAPM_P.K_T1f, ctrl_TAPM_P.K_q1f,
    ctrl_TAPM_P.D, rtb_T_r_e, ctrl_TAPM_P.Rho, ctrl_TAPM_P.eps_c,
    ctrl_TAPM_P.K_T1r, ctrl_TAPM_P.K_q1r,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePowerand);

  /* MultiPortSwitch: '<S90>/Controller chosen' incorporates:
   *  Constant: '<S90>/NaN'
   *  Sum: '<S92>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory) {
   case 1:
    rtb_Row2 = ctrl_TAPM_B.Kp + rtb_Integrator_g;
    break;

   case 2:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowerand.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowerand.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowerand.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_TAPM_P.NaN_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S90>/Controller chosen' */

  /* Sum: '<S90>/Sum' */
  ctrl_TAPM_B.Sum_k = (ctrl_TAPM_B.Inertiacompensation + ctrl_TAPM_B.Sum1_n) +
    rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S75>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S75>/Constant'
     *  Constant: '<S75>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a = ctrl_TAPM_B.Sum_k -
      ctrl_TAPM_P.Constant_Value_cs[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_d;
    ctrl_TAPM_B.DiscreteTransferFcn_d = ctrl_TAPM_P.Constant1_Value_k[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a + ctrl_TAPM_P.Constant1_Value_k[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_d;
  }

  /* Gain: '<S89>/Finding rotation speed' incorporates:
   *  Gain: '<S89>/K_omega'
   *  Sum: '<S89>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed = ((ctrl_TAPM_B.DiscreteTransferFcn_d -
    ctrl_TAPM_B.Delay_e) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S92>/Ki' */
    ctrl_TAPM_B.Ki = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S90>/Supervisor' */
    ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory, 0.0, ctrl_TAPM_B.Delay[0],
                         &ctrl_TAPM_B.sf_Supervisor);

    /* Delay: '<S76>/Delay' */
    ctrl_TAPM_B.Delay_b = ctrl_TAPM_DW.Delay_DSTATE_b;

    /* Delay: '<S99>/Delay' */
    ctrl_TAPM_B.Delay_bs = ctrl_TAPM_DW.Delay_DSTATE_d;
  }

  /* MATLAB Function: '<S99>/MATLAB Function' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Tf2'
   *  Constant: '<S11>/K_Tr2'
   *  Constant: '<S11>/Rho'
   */
  ctrl_TAPM_MATLABFunction(rtb_sys[7], ctrl_TAPM_P.K_T2f, ctrl_TAPM_P.K_T2r,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_B.Delay_bs,
    &ctrl_TAPM_B.sf_MATLABFunction_i);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S99>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S99>/Constant1'
     *  Constant: '<S99>/Constant2'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_d =
      (ctrl_TAPM_B.sf_MATLABFunction_i.n_d - ctrl_TAPM_P.Constant2_Value_i[1] *
       ctrl_TAPM_DW.DiscreteTransferFcn_states_h[0]) -
      ctrl_TAPM_P.Constant2_Value_i[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_h[1];
    ctrl_TAPM_B.DiscreteTransferFcn_e = (ctrl_TAPM_P.Constant1_Value_b[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_d + ctrl_TAPM_P.Constant1_Value_b[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_h[0]) +
      ctrl_TAPM_P.Constant1_Value_b[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_h[1];

    /* SampleTimeMath: '<S102>/TSamp'
     *
     * About '<S102>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_n = ctrl_TAPM_B.DiscreteTransferFcn_e *
      ctrl_TAPM_P.TSamp_WtEt_k;

    /* Sum: '<S102>/Diff' incorporates:
     *  UnitDelay: '<S102>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_n - ctrl_TAPM_DW.UD_DSTATE_n;

    /* RateLimiter: '<S99>/Acceleration Limit' */
    rtb_Row2 = rtb_Sum_b - ctrl_TAPM_DW.PrevY_e;
    if (rtb_Row2 > ctrl_TAPM_P.AccelerationLimit_RisingLim_n) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_e +
        ctrl_TAPM_P.AccelerationLimit_RisingLim_n;
    } else {
      if (rtb_Row2 < ctrl_TAPM_P.AccelerationLimit_FallingLim_n) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_e +
          ctrl_TAPM_P.AccelerationLimit_FallingLim_n;
      }
    }

    ctrl_TAPM_DW.PrevY_e = rtb_Sum_b;

    /* End of RateLimiter: '<S99>/Acceleration Limit' */

    /* Gain: '<S99>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_e = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S99>/Sum1' incorporates:
     *  Gain: '<S99>/Qf_0'
     *  Gain: '<S99>/Qff_0(nr)'
     *  Gain: '<S99>/Qff_1(nr)'
     *  Trigonometry: '<S99>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_nn = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_e) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_e;

    /* Memory: '<S99>/Memory' */
    ctrl_TAPM_B.Memory_c = ctrl_TAPM_DW.Memory_PreviousInput_n;

    /* Sum: '<S101>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_e - ctrl_TAPM_B.Delay[1];

    /* Gain: '<S101>/Kp' */
    ctrl_TAPM_B.Kp_p = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S101>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_db,
                       ctrl_TAPM_B.reset_e);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_g = ctrl_TAPM_P.Integrator_IC_fy;
    }
  }

  rtb_Integrator_f = ctrl_TAPM_X.Integrator_CSTATE_g;

  /* MATLAB Function: '<S101>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant3'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Qr2'
   *  Constant: '<S11>/K_Qr8'
   *  Constant: '<S11>/K_Tf2'
   *  Constant: '<S11>/K_Tr2'
   *  Constant: '<S11>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay[1], ctrl_TAPM_P.K_T2f, ctrl_TAPM_P.K_q2f,
    ctrl_TAPM_P.D, ctrl_TAPM_B.sf_MATLABFunction_i.T_r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.eps_c, ctrl_TAPM_P.K_T2r, ctrl_TAPM_P.K_q2r,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePowera_o);

  /* MultiPortSwitch: '<S99>/Controller chosen' incorporates:
   *  Constant: '<S99>/NaN'
   *  Sum: '<S101>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_c) {
   case 1:
    rtb_Row2 = ctrl_TAPM_B.Kp_p + rtb_Integrator_f;
    break;

   case 2:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_o.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_o.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_o.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_TAPM_P.NaN_Value_l;
    break;
  }

  /* End of MultiPortSwitch: '<S99>/Controller chosen' */

  /* Sum: '<S99>/Sum' */
  ctrl_TAPM_B.Sum_h = (ctrl_TAPM_B.Inertiacompensation_e + ctrl_TAPM_B.Sum1_nn)
    + rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S76>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S76>/Constant'
     *  Constant: '<S76>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h = ctrl_TAPM_B.Sum_h -
      ctrl_TAPM_P.Constant_Value_h[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_m;
    ctrl_TAPM_B.DiscreteTransferFcn_k = ctrl_TAPM_P.Constant1_Value_j[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h + ctrl_TAPM_P.Constant1_Value_j[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_m;
  }

  /* Gain: '<S98>/Finding rotation speed' incorporates:
   *  Gain: '<S98>/K_omega'
   *  Sum: '<S98>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_a = ((ctrl_TAPM_B.DiscreteTransferFcn_k -
    ctrl_TAPM_B.Delay_b) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_h) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S101>/Ki' */
    ctrl_TAPM_B.Ki_o = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S99>/Supervisor' */
    ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_c, 0.0, ctrl_TAPM_B.Delay[1],
                         &ctrl_TAPM_B.sf_Supervisor_h);

    /* Delay: '<S77>/Delay' */
    ctrl_TAPM_B.Delay_i = ctrl_TAPM_DW.Delay_DSTATE_n;

    /* Delay: '<S108>/Delay' */
    ctrl_TAPM_B.Delay_by = ctrl_TAPM_DW.Delay_DSTATE_no;
  }

  /* MATLAB Function: '<S108>/MATLAB Function' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Tf3'
   *  Constant: '<S11>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 3/Thruster control/MATLAB Function': '<S112>:1' */
  /* '<S112>:1:5' */
  if (rtb_sys[8] < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (rtb_sys[8] > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (rtb_sys[8] == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = rtb_sys[8];
  }

  rtb_Row2 = sqrt(fabs(rtb_sys[8]) / (ctrl_TAPM_P.Rho * rt_powd_snf
    (ctrl_TAPM_P.D, 4.0) * ctrl_TAPM_P.K_T3f)) * rtb_TmpSignalConversionAtSFun_2;

  /* '<S112>:1:7' */
  rtb_Row1 = tanh(ctrl_TAPM_P.eps_c * rtb_Row2 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S112>:1:8' */
  /* '<S112>:1:10' */
  if (ctrl_TAPM_B.Delay_by < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (ctrl_TAPM_B.Delay_by > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (ctrl_TAPM_B.Delay_by == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = ctrl_TAPM_B.Delay_by;
  }

  rtb_T_r_h = ((1.0 - rtb_Row1) * ctrl_TAPM_P.K_T3f + ctrl_TAPM_P.K_T3f *
               rtb_Row1) * rtb_TmpSignalConversionAtSFun_2 * ctrl_TAPM_P.Rho *
    rt_powd_snf(ctrl_TAPM_P.D, 4.0) * (ctrl_TAPM_B.Delay_by *
    ctrl_TAPM_B.Delay_by);
  ctrl_TAPM_B.n_d_p = rtb_Row2;

  /* End of MATLAB Function: '<S108>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S108>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S108>/Constant1'
     *  Constant: '<S108>/Constant2'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_e = (ctrl_TAPM_B.n_d_p -
      ctrl_TAPM_P.Constant2_Value_h[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0]) -
      ctrl_TAPM_P.Constant2_Value_h[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[1];
    ctrl_TAPM_B.DiscreteTransferFcn_f = (ctrl_TAPM_P.Constant1_Value_gf[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_e + ctrl_TAPM_P.Constant1_Value_gf[1]
      * ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0]) +
      ctrl_TAPM_P.Constant1_Value_gf[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[1];

    /* SampleTimeMath: '<S111>/TSamp'
     *
     * About '<S111>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_k = ctrl_TAPM_B.DiscreteTransferFcn_f *
      ctrl_TAPM_P.TSamp_WtEt_m;

    /* Sum: '<S111>/Diff' incorporates:
     *  UnitDelay: '<S111>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_k - ctrl_TAPM_DW.UD_DSTATE_i;

    /* RateLimiter: '<S108>/Acceleration limiter' */
    rtb_Row2 = rtb_Sum_b - ctrl_TAPM_DW.PrevY_o;
    if (rtb_Row2 > ctrl_TAPM_P.Accelerationlimiter_RisingLim) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_o +
        ctrl_TAPM_P.Accelerationlimiter_RisingLim;
    } else {
      if (rtb_Row2 < ctrl_TAPM_P.Accelerationlimiter_FallingLim) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_o +
          ctrl_TAPM_P.Accelerationlimiter_FallingLim;
      }
    }

    ctrl_TAPM_DW.PrevY_o = rtb_Sum_b;

    /* End of RateLimiter: '<S108>/Acceleration limiter' */

    /* Gain: '<S108>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_c = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S108>/Sum1' incorporates:
     *  Gain: '<S108>/Qf_0'
     *  Gain: '<S108>/Qff_0(nr)'
     *  Gain: '<S108>/Qff_1(nr)'
     *  Trigonometry: '<S108>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_i = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_f) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_f;

    /* Memory: '<S108>/Memory' */
    ctrl_TAPM_B.Memory_i = ctrl_TAPM_DW.Memory_PreviousInput_d;

    /* Sum: '<S110>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_f - ctrl_TAPM_B.Delay[2];

    /* Gain: '<S110>/Kp' */
    ctrl_TAPM_B.Kp_i = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S110>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_l,
                       ctrl_TAPM_B.reset_j2);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_i = ctrl_TAPM_P.Integrator_IC_j;
    }
  }

  rtb_Integrator_hl = ctrl_TAPM_X.Integrator_CSTATE_i;

  /* MATLAB Function: '<S110>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant3'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Qr3'
   *  Constant: '<S11>/K_Qr9'
   *  Constant: '<S11>/K_Tf3'
   *  Constant: '<S11>/K_Tr3'
   *  Constant: '<S11>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay[2], ctrl_TAPM_P.K_T3f, ctrl_TAPM_P.K_q3f,
    ctrl_TAPM_P.D, rtb_T_r_h, ctrl_TAPM_P.Rho, ctrl_TAPM_P.eps_c,
    ctrl_TAPM_P.K_T3r, ctrl_TAPM_P.K_q3r,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePowera_n);

  /* MultiPortSwitch: '<S108>/Controller chosen' incorporates:
   *  Constant: '<S108>/NaN'
   *  Sum: '<S110>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_i) {
   case 1:
    rtb_Row2 = ctrl_TAPM_B.Kp_i + rtb_Integrator_hl;
    break;

   case 2:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_n.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_n.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_n.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_TAPM_P.NaN_Value_g;
    break;
  }

  /* End of MultiPortSwitch: '<S108>/Controller chosen' */

  /* Sum: '<S108>/Sum' */
  ctrl_TAPM_B.Sum_hf = (ctrl_TAPM_B.Inertiacompensation_c + ctrl_TAPM_B.Sum1_i)
    + rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S77>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S77>/Constant'
     *  Constant: '<S77>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_hh = ctrl_TAPM_B.Sum_hf -
      ctrl_TAPM_P.Constant_Value_n[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_k;
    ctrl_TAPM_B.DiscreteTransferFcn_n = ctrl_TAPM_P.Constant1_Value_a[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_hh + ctrl_TAPM_P.Constant1_Value_a[1]
      * ctrl_TAPM_DW.DiscreteTransferFcn_states_k;
  }

  /* Gain: '<S107>/Finding rotation speed' incorporates:
   *  Gain: '<S107>/K_omega'
   *  Sum: '<S107>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_m = ((ctrl_TAPM_B.DiscreteTransferFcn_n -
    ctrl_TAPM_B.Delay_i) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_a) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S110>/Ki' */
    ctrl_TAPM_B.Ki_n = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S108>/Supervisor' */
    ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_i, 0.0, ctrl_TAPM_B.Delay[2],
                         &ctrl_TAPM_B.sf_Supervisor_l);

    /* Delay: '<S78>/Delay' */
    ctrl_TAPM_B.Delay_g = ctrl_TAPM_DW.Delay_DSTATE_e;

    /* Delay: '<S117>/Delay' */
    ctrl_TAPM_B.Delay_l = ctrl_TAPM_DW.Delay_DSTATE_i;
  }

  /* MATLAB Function: '<S117>/MATLAB Function' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Tf4'
   *  Constant: '<S11>/K_Tr4'
   *  Constant: '<S11>/Rho'
   */
  ctrl_TAPM_MATLABFunction(rtb_sys[9], ctrl_TAPM_P.K_T4f, ctrl_TAPM_P.K_T4r,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_B.Delay_l,
    &ctrl_TAPM_B.sf_MATLABFunction_go);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S117>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S117>/Constant1'
     *  Constant: '<S117>/Constant2'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_k =
      (ctrl_TAPM_B.sf_MATLABFunction_go.n_d - ctrl_TAPM_P.Constant2_Value_l[1] *
       ctrl_TAPM_DW.DiscreteTransferFcn_states_i[0]) -
      ctrl_TAPM_P.Constant2_Value_l[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_i[1];
    ctrl_TAPM_B.DiscreteTransferFcn_l = (ctrl_TAPM_P.Constant1_Value_m[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_k + ctrl_TAPM_P.Constant1_Value_m[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_i[0]) +
      ctrl_TAPM_P.Constant1_Value_m[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_i[1];

    /* SampleTimeMath: '<S120>/TSamp'
     *
     * About '<S120>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_a = ctrl_TAPM_B.DiscreteTransferFcn_l *
      ctrl_TAPM_P.TSamp_WtEt_h;

    /* Sum: '<S120>/Diff' incorporates:
     *  UnitDelay: '<S120>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_a - ctrl_TAPM_DW.UD_DSTATE_n4;

    /* RateLimiter: '<S117>/Acceleration limiter' */
    rtb_Row2 = rtb_Sum_b - ctrl_TAPM_DW.PrevY_c;
    if (rtb_Row2 > ctrl_TAPM_P.Accelerationlimiter_RisingLim_e) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_c +
        ctrl_TAPM_P.Accelerationlimiter_RisingLim_e;
    } else {
      if (rtb_Row2 < ctrl_TAPM_P.Accelerationlimiter_FallingLi_b) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_c +
          ctrl_TAPM_P.Accelerationlimiter_FallingLi_b;
      }
    }

    ctrl_TAPM_DW.PrevY_c = rtb_Sum_b;

    /* End of RateLimiter: '<S117>/Acceleration limiter' */

    /* Gain: '<S117>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_k = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S117>/Sum1' incorporates:
     *  Gain: '<S117>/Qf_0'
     *  Gain: '<S117>/Qff_0(nr)'
     *  Gain: '<S117>/Qff_1(nr)'
     *  Trigonometry: '<S117>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_b = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_l) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_l;

    /* Memory: '<S117>/Memory' */
    ctrl_TAPM_B.Memory_j = ctrl_TAPM_DW.Memory_PreviousInput_a;

    /* Sum: '<S119>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_l - ctrl_TAPM_B.Delay[3];

    /* Gain: '<S119>/Kp' */
    ctrl_TAPM_B.Kp_c = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S119>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_h,
                       ctrl_TAPM_B.reset_n);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_l = ctrl_TAPM_P.Integrator_IC_g;
    }
  }

  rtb_Integrator_an = ctrl_TAPM_X.Integrator_CSTATE_l;

  /* MATLAB Function: '<S119>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant3'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Qr10'
   *  Constant: '<S11>/K_Qr4'
   *  Constant: '<S11>/K_Tf4'
   *  Constant: '<S11>/K_Tr4'
   *  Constant: '<S11>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay[3], ctrl_TAPM_P.K_T4f, ctrl_TAPM_P.K_q4f,
    ctrl_TAPM_P.D, ctrl_TAPM_B.sf_MATLABFunction_go.T_r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.eps_c, ctrl_TAPM_P.K_T4r, ctrl_TAPM_P.K_q4r,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePower_n3);

  /* MultiPortSwitch: '<S117>/Controller chosen' incorporates:
   *  Constant: '<S117>/NaN'
   *  Sum: '<S119>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_j) {
   case 1:
    rtb_Row2 = ctrl_TAPM_B.Kp_c + rtb_Integrator_an;
    break;

   case 2:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePower_n3.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePower_n3.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePower_n3.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_TAPM_P.NaN_Value_p;
    break;
  }

  /* End of MultiPortSwitch: '<S117>/Controller chosen' */

  /* Sum: '<S117>/Sum' */
  ctrl_TAPM_B.Sum_k2 = (ctrl_TAPM_B.Inertiacompensation_k + ctrl_TAPM_B.Sum1_b)
    + rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S78>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S78>/Constant'
     *  Constant: '<S78>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_n = ctrl_TAPM_B.Sum_k2 -
      ctrl_TAPM_P.Constant_Value_j4[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_h0;
    ctrl_TAPM_B.DiscreteTransferFcn_b = ctrl_TAPM_P.Constant1_Value_oi[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_n + ctrl_TAPM_P.Constant1_Value_oi[1]
      * ctrl_TAPM_DW.DiscreteTransferFcn_states_h0;
  }

  /* Gain: '<S116>/Finding rotation speed' incorporates:
   *  Gain: '<S116>/K_omega'
   *  Sum: '<S116>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_ms = ((ctrl_TAPM_B.DiscreteTransferFcn_b -
    ctrl_TAPM_B.Delay_g) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_k) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S119>/Ki' */
    ctrl_TAPM_B.Ki_b = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S117>/Supervisor' */
    ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_j, 0.0, ctrl_TAPM_B.Delay[3],
                         &ctrl_TAPM_B.sf_Supervisor_n);

    /* Delay: '<S79>/Delay' */
    ctrl_TAPM_B.Delay_a5 = ctrl_TAPM_DW.Delay_DSTATE_j;

    /* Delay: '<S126>/Delay' */
    ctrl_TAPM_B.Delay_id = ctrl_TAPM_DW.Delay_DSTATE_a;
  }

  /* MATLAB Function: '<S126>/MATLAB Function' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Tf5'
   *  Constant: '<S11>/K_Tr5'
   *  Constant: '<S11>/Rho'
   */
  ctrl_TAPM_MATLABFunction(rtb_sys[10], ctrl_TAPM_P.K_T5f, ctrl_TAPM_P.K_T5r,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_B.Delay_id,
    &ctrl_TAPM_B.sf_MATLABFunction_j);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S126>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S126>/Constant1'
     *  Constant: '<S126>/Constant2'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_c =
      (ctrl_TAPM_B.sf_MATLABFunction_j.n_d - ctrl_TAPM_P.Constant2_Value_p[1] *
       ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[0]) -
      ctrl_TAPM_P.Constant2_Value_p[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[1];
    ctrl_TAPM_B.DiscreteTransferFcn_o = (ctrl_TAPM_P.Constant1_Value_mk[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_c + ctrl_TAPM_P.Constant1_Value_mk[1]
      * ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[0]) +
      ctrl_TAPM_P.Constant1_Value_mk[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[1];

    /* SampleTimeMath: '<S129>/TSamp'
     *
     * About '<S129>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_m = ctrl_TAPM_B.DiscreteTransferFcn_o *
      ctrl_TAPM_P.TSamp_WtEt_o;

    /* Sum: '<S129>/Diff' incorporates:
     *  UnitDelay: '<S129>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_m - ctrl_TAPM_DW.UD_DSTATE_m;

    /* RateLimiter: '<S126>/Acceleration limiter' */
    rtb_Row2 = rtb_Sum_b - ctrl_TAPM_DW.PrevY_j;
    if (rtb_Row2 > ctrl_TAPM_P.Accelerationlimiter_RisingLim_b) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_j +
        ctrl_TAPM_P.Accelerationlimiter_RisingLim_b;
    } else {
      if (rtb_Row2 < ctrl_TAPM_P.Accelerationlimiter_FallingLi_d) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_j +
          ctrl_TAPM_P.Accelerationlimiter_FallingLi_d;
      }
    }

    ctrl_TAPM_DW.PrevY_j = rtb_Sum_b;

    /* End of RateLimiter: '<S126>/Acceleration limiter' */

    /* Gain: '<S126>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_f = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S126>/Sum1' incorporates:
     *  Gain: '<S126>/Qf_0'
     *  Gain: '<S126>/Qff_0(nr)'
     *  Gain: '<S126>/Qff_1(nr)'
     *  Trigonometry: '<S126>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_o = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_o) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_o;

    /* Memory: '<S126>/Memory' */
    ctrl_TAPM_B.Memory_d = ctrl_TAPM_DW.Memory_PreviousInput_b;

    /* Sum: '<S128>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_o - ctrl_TAPM_B.Delay[4];

    /* Gain: '<S128>/Kp' */
    ctrl_TAPM_B.Kp_j = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S128>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_f,
                       ctrl_TAPM_B.reset_f);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_n4 = ctrl_TAPM_P.Integrator_IC_aj;
    }
  }

  rtb_Integrator_i = ctrl_TAPM_X.Integrator_CSTATE_n4;

  /* MATLAB Function: '<S128>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant3'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Qr11'
   *  Constant: '<S11>/K_Qr5'
   *  Constant: '<S11>/K_Tf5'
   *  Constant: '<S11>/K_Tr5'
   *  Constant: '<S11>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay[4], ctrl_TAPM_P.K_T5f, ctrl_TAPM_P.K_q5f,
    ctrl_TAPM_P.D, ctrl_TAPM_B.sf_MATLABFunction_j.T_r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.eps_c, ctrl_TAPM_P.K_T5r, ctrl_TAPM_P.K_q5r,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePowera_h);

  /* MultiPortSwitch: '<S126>/Controller chosen' incorporates:
   *  Constant: '<S126>/NaN'
   *  Sum: '<S128>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_d) {
   case 1:
    rtb_Row2 = ctrl_TAPM_B.Kp_j + rtb_Integrator_i;
    break;

   case 2:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_h.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_h.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_h.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_TAPM_P.NaN_Value_lq;
    break;
  }

  /* End of MultiPortSwitch: '<S126>/Controller chosen' */

  /* Sum: '<S126>/Sum' */
  ctrl_TAPM_B.Sum_i = (ctrl_TAPM_B.Inertiacompensation_f + ctrl_TAPM_B.Sum1_o) +
    rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S79>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S79>/Constant'
     *  Constant: '<S79>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_f = ctrl_TAPM_B.Sum_i -
      ctrl_TAPM_P.Constant_Value_ib[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_dt;
    ctrl_TAPM_B.DiscreteTransferFcn_lz = ctrl_TAPM_P.Constant1_Value_h[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_f + ctrl_TAPM_P.Constant1_Value_h[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_dt;
  }

  /* Gain: '<S125>/Finding rotation speed' incorporates:
   *  Gain: '<S125>/K_omega'
   *  Sum: '<S125>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_ag = ((ctrl_TAPM_B.DiscreteTransferFcn_lz -
    ctrl_TAPM_B.Delay_a5) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_c) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S128>/Ki' */
    ctrl_TAPM_B.Ki_a = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S126>/Supervisor' */
    ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_d, 0.0, ctrl_TAPM_B.Delay[4],
                         &ctrl_TAPM_B.sf_Supervisor_b);

    /* Delay: '<S80>/Delay' */
    ctrl_TAPM_B.Delay_h = ctrl_TAPM_DW.Delay_DSTATE_dv;

    /* Delay: '<S135>/Delay' */
    ctrl_TAPM_B.Delay_il = ctrl_TAPM_DW.Delay_DSTATE_m;
  }

  /* MATLAB Function: '<S135>/MATLAB Function' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Tf6'
   *  Constant: '<S11>/K_Tr6'
   *  Constant: '<S11>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 6/Thruster control/MATLAB Function': '<S139>:1' */
  /* '<S139>:1:5' */
  if (rtb_sys[11] < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (rtb_sys[11] > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (rtb_sys[11] == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = rtb_sys[11];
  }

  rtb_Row2 = sqrt(fabs(rtb_sys[11]) / (ctrl_TAPM_P.Rho * rt_powd_snf
    (ctrl_TAPM_P.D, 4.0) * ctrl_TAPM_P.K_T6f)) * rtb_TmpSignalConversionAtSFun_2;

  /* '<S139>:1:7' */
  rtb_Row1 = tanh(ctrl_TAPM_P.eps_c * rtb_Row2 / 27.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S139>:1:8' */
  /* '<S139>:1:10' */
  if (ctrl_TAPM_B.Delay_il < 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = -1.0;
  } else if (ctrl_TAPM_B.Delay_il > 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 1.0;
  } else if (ctrl_TAPM_B.Delay_il == 0.0) {
    rtb_TmpSignalConversionAtSFun_2 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_2 = ctrl_TAPM_B.Delay_il;
  }

  rtb_T_r = ((1.0 - rtb_Row1) * ctrl_TAPM_P.K_T6r + ctrl_TAPM_P.K_T6f * rtb_Row1)
    * rtb_TmpSignalConversionAtSFun_2 * ctrl_TAPM_P.Rho * rt_powd_snf
    (ctrl_TAPM_P.D, 4.0) * (ctrl_TAPM_B.Delay_il * ctrl_TAPM_B.Delay_il);
  ctrl_TAPM_B.n_d = rtb_Row2;

  /* End of MATLAB Function: '<S135>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S135>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S135>/Constant1'
     *  Constant: '<S135>/Constant2'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h4 = (ctrl_TAPM_B.n_d -
      ctrl_TAPM_P.Constant2_Value_p3[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_l[0]) -
      ctrl_TAPM_P.Constant2_Value_p3[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_l[1];
    ctrl_TAPM_B.DiscreteTransferFcn_j = (ctrl_TAPM_P.Constant1_Value_oa[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h4 + ctrl_TAPM_P.Constant1_Value_oa[1]
      * ctrl_TAPM_DW.DiscreteTransferFcn_states_l[0]) +
      ctrl_TAPM_P.Constant1_Value_oa[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_l[1];

    /* SampleTimeMath: '<S138>/TSamp'
     *
     * About '<S138>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_o = ctrl_TAPM_B.DiscreteTransferFcn_j *
      ctrl_TAPM_P.TSamp_WtEt_kk;

    /* Sum: '<S138>/Diff' incorporates:
     *  UnitDelay: '<S138>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_o - ctrl_TAPM_DW.UD_DSTATE_l;

    /* RateLimiter: '<S135>/Acceleration limiter' */
    rtb_Row2 = rtb_Sum_b - ctrl_TAPM_DW.PrevY_h;
    if (rtb_Row2 > ctrl_TAPM_P.Accelerationlimiter_RisingLi_bi) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_h +
        ctrl_TAPM_P.Accelerationlimiter_RisingLi_bi;
    } else {
      if (rtb_Row2 < ctrl_TAPM_P.Accelerationlimiter_FallingLi_p) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_h +
          ctrl_TAPM_P.Accelerationlimiter_FallingLi_p;
      }
    }

    ctrl_TAPM_DW.PrevY_h = rtb_Sum_b;

    /* End of RateLimiter: '<S135>/Acceleration limiter' */

    /* Gain: '<S135>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_e3 = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S135>/Sum1' incorporates:
     *  Gain: '<S135>/Qf_0'
     *  Gain: '<S135>/Qff_0(nr)'
     *  Gain: '<S135>/Qff_1(nr)'
     *  Trigonometry: '<S135>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_io = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_j) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_j;

    /* Memory: '<S135>/Memory' */
    ctrl_TAPM_B.Memory_o = ctrl_TAPM_DW.Memory_PreviousInput_a4;

    /* Sum: '<S137>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_j - ctrl_TAPM_B.Delay[5];

    /* Gain: '<S137>/Kp' */
    ctrl_TAPM_B.Kp_l = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S137>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_i3,
                       ctrl_TAPM_B.reset_om);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_gj = ctrl_TAPM_P.Integrator_IC_h;
    }
  }

  rtb_Integrator_l = ctrl_TAPM_X.Integrator_CSTATE_gj;

  /* MATLAB Function: '<S137>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant3'
   *  Constant: '<S11>/D'
   *  Constant: '<S11>/K_Qr12'
   *  Constant: '<S11>/K_Qr6'
   *  Constant: '<S11>/K_Tf6'
   *  Constant: '<S11>/K_Tr6'
   *  Constant: '<S11>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay[5], ctrl_TAPM_P.K_T6f, ctrl_TAPM_P.K_q6f,
    ctrl_TAPM_P.D, rtb_T_r, ctrl_TAPM_P.Rho, ctrl_TAPM_P.eps_c,
    ctrl_TAPM_P.K_T6r, ctrl_TAPM_P.K_q6r,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePower_nf);

  /* MultiPortSwitch: '<S135>/Controller chosen' incorporates:
   *  Constant: '<S135>/NaN'
   *  Sum: '<S137>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_o) {
   case 1:
    rtb_Row2 = ctrl_TAPM_B.Kp_l + rtb_Integrator_l;
    break;

   case 2:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePower_nf.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePower_nf.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_TAPM_B.sf_CorecontrollerTorquePower_nf.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_TAPM_P.NaN_Value_j;
    break;
  }

  /* End of MultiPortSwitch: '<S135>/Controller chosen' */

  /* Sum: '<S135>/Sum' */
  ctrl_TAPM_B.Sum_f = (ctrl_TAPM_B.Inertiacompensation_e3 + ctrl_TAPM_B.Sum1_io)
    + rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S80>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S80>/Constant'
     *  Constant: '<S80>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_cw = ctrl_TAPM_B.Sum_f -
      ctrl_TAPM_P.Constant_Value_ht[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_o;
    ctrl_TAPM_B.DiscreteTransferFcn_ea = ctrl_TAPM_P.Constant1_Value_gs[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_cw + ctrl_TAPM_P.Constant1_Value_gs[1]
      * ctrl_TAPM_DW.DiscreteTransferFcn_states_o;
  }

  /* Gain: '<S134>/Finding rotation speed' incorporates:
   *  Gain: '<S134>/K_omega'
   *  Sum: '<S134>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_c = ((ctrl_TAPM_B.DiscreteTransferFcn_ea -
    ctrl_TAPM_B.Delay_h) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_m) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S137>/Ki' */
    ctrl_TAPM_B.Ki_p = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S135>/Supervisor' */
    ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_o, 0.0, ctrl_TAPM_B.Delay[5],
                         &ctrl_TAPM_B.sf_Supervisor_e);

    /* SignalConversion: '<S12>/TmpSignal ConversionAtDelayInport1' */
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[0] = ctrl_TAPM_B.output[1];
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[1] = ctrl_TAPM_B.output[3];
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[2] = ctrl_TAPM_B.output[5];
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[3] = ctrl_TAPM_B.output[7];
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[4] = ctrl_TAPM_B.output[9];
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[5] = ctrl_TAPM_B.output[11];

    /* RelationalOperator: '<S4>/Relational Operator' incorporates:
     *  Memory: '<S4>/Memory'
     */
    rtb_RelationalOperator[0] = (ctrl_TAPM_B.IMU_AX1 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[0]);
    rtb_RelationalOperator[1] = (ctrl_TAPM_B.IMU_AY1 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[1]);
    rtb_RelationalOperator[2] = (ctrl_TAPM_B.IMU_AZ1 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[2]);
    rtb_RelationalOperator[3] = (ctrl_TAPM_B.IMU_RX1 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[3]);
    rtb_RelationalOperator[4] = (ctrl_TAPM_B.IMU_RY1 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[4]);
    rtb_RelationalOperator[5] = (ctrl_TAPM_B.IMU_RZ1 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[5]);
    rtb_RelationalOperator[6] = (ctrl_TAPM_B.IMU_V1 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[6]);
    rtb_RelationalOperator[7] = (ctrl_TAPM_B.IMU_AX2 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[7]);
    rtb_RelationalOperator[8] = (ctrl_TAPM_B.IMU_AY2 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[8]);
    rtb_RelationalOperator[9] = (ctrl_TAPM_B.IMU_AZ2 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[9]);
    rtb_RelationalOperator[10] = (ctrl_TAPM_B.IMU_RX2 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[10]);
    rtb_RelationalOperator[11] = (ctrl_TAPM_B.IMU_RY2 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[11]);
    rtb_RelationalOperator[12] = (ctrl_TAPM_B.IMU_RZ2 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[12]);
    rtb_RelationalOperator[13] = (ctrl_TAPM_B.IMU_V2 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[13]);
    rtb_RelationalOperator[14] = (ctrl_TAPM_B.IMU_AX3 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[14]);
    rtb_RelationalOperator[15] = (ctrl_TAPM_B.IMU_AY3 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[15]);
    rtb_RelationalOperator[16] = (ctrl_TAPM_B.IMU_AZ3 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[16]);
    rtb_RelationalOperator[17] = (ctrl_TAPM_B.IMU_RX3 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[17]);
    rtb_RelationalOperator[18] = (ctrl_TAPM_B.IMU_RY3 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[18]);
    rtb_RelationalOperator[19] = (ctrl_TAPM_B.IMU_RZ3 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[19]);
    rtb_RelationalOperator[20] = (ctrl_TAPM_B.IMU_V3 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[20]);
    rtb_RelationalOperator[21] = (ctrl_TAPM_B.IMU_AX4 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[21]);
    rtb_RelationalOperator[22] = (ctrl_TAPM_B.IMU_AY4 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[22]);
    rtb_RelationalOperator[23] = (ctrl_TAPM_B.IMU_AZ4 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[23]);
    rtb_RelationalOperator[24] = (ctrl_TAPM_B.IMU_RX4 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[24]);
    rtb_RelationalOperator[25] = (ctrl_TAPM_B.IMU_RY4 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[25]);
    rtb_RelationalOperator[26] = (ctrl_TAPM_B.IMU_RZ4 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[26]);
    rtb_RelationalOperator[27] = (ctrl_TAPM_B.IMU_V4 !=
      ctrl_TAPM_DW.Memory_PreviousInput_l[27]);

    /* Outputs for Triggered SubSystem: '<S4>/Filtering' incorporates:
     *  TriggerPort: '<S25>/Trigger'
     */
    if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
      exitg11 = false;
      for (b_ixstart = 0; b_ixstart < 28; b_ixstart++) {
        exitg11 = (exitg11 || (rtb_RelationalOperator[b_ixstart] &&
                    (ctrl_TAPM_PrevZCX.Filtering_Trig_ZCE[b_ixstart] !=
                     POS_ZCSIG)));
      }

      if (exitg11) {
        /* Product: '<S30>/H*P*H'' incorporates:
         *  Constant: '<S30>/Constant'
         *  Delay: '<S30>/Delay'
         *  Math: '<S30>/Math Function1'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            tmp_3[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              tmp_3[b_ixstart + 12 * i] += ctrl_TAPM_DW.Delay_DSTATE_fv[12 * p3
                + b_ixstart] * ctrl_TAPM_P.Constant_Value[6 * p3 + i];
            }
          }
        }

        /* Sum: '<S30>/Sum' incorporates:
         *  Constant: '<S30>/Constant'
         *  Constant: '<S30>/Constant1'
         *  Product: '<S30>/H*P*H''
         */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            rtb_TmpSignalConversionAtSFun_2 = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_TmpSignalConversionAtSFun_2 += ctrl_TAPM_P.Constant_Value[6 *
                p3 + b_ixstart] * tmp_3[12 * i + p3];
            }

            d_0[b_ixstart + 6 * i] = ctrl_TAPM_P.Constant1_Value[6 * i +
              b_ixstart] + rtb_TmpSignalConversionAtSFun_2;
          }
        }

        /* End of Sum: '<S30>/Sum' */

        /* Product: '<S30>/Matrix Multiply' */
        rt_invd6x6_snf(d_0, b_V_singular);

        /* Product: '<S30>/P*H'' incorporates:
         *  Constant: '<S30>/Constant'
         *  Delay: '<S30>/Delay'
         *  Math: '<S30>/Math Function'
         *  Product: '<S30>/P*H'*inv(H*P*H'+R)'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            tmp_3[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              tmp_3[b_ixstart + 12 * i] += ctrl_TAPM_DW.Delay_DSTATE_fv[12 * p3
                + b_ixstart] * ctrl_TAPM_P.Constant_Value[6 * p3 + i];
            }
          }
        }

        /* End of Product: '<S30>/P*H'' */

        /* Product: '<S30>/P*H'*inv(H*P*H'+R)' */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            rtb_PHinvHPHR[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              rtb_PHinvHPHR[b_ixstart + 12 * i] += tmp_3[12 * p3 + b_ixstart] *
                b_V_singular[6 * i + p3];
            }
          }
        }

        /* Gain: '<S30>/H' incorporates:
         *  Delay: '<S30>/Delay1'
         */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          rtb_TmpSignalConversionAtToFi_i[b_ixstart] = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TmpSignalConversionAtToFi_i[b_ixstart] += ctrl_TAPM_P.H_Gain[6 *
              i + b_ixstart] * ctrl_TAPM_DW.Delay1_DSTATE[i];
          }
        }

        /* End of Gain: '<S30>/H' */

        /* Memory: '<S31>/Memory2' */
        for (i = 0; i < 5; i++) {
          rtb_Memory2[i] = ctrl_TAPM_DW.Memory2_PreviousInput[i];
        }

        /* End of Memory: '<S31>/Memory2' */

        /* S-Function (sdspmdn2): '<S31>/Median' */
        for (ixstart = 0; ixstart < 5; ixstart += 5) {
          for (i = ixstart; i < ixstart + 1; i++) {
            MDNQSort_D(0, 4, i, ctrl_TAPM_DW.Median_Index, rtb_Memory2);
            rtb_Median1 = rtb_Memory2[ctrl_TAPM_DW.Median_Index[2] + i];
          }
        }

        /* End of S-Function (sdspmdn2): '<S31>/Median' */

        /* Abs: '<S31>/Abs' incorporates:
         *  Sum: '<S31>/Sum'
         */
        for (i = 0; i < 5; i++) {
          rtb_Abs[i] = fabs(rtb_Memory2[i] - rtb_Median1);
        }

        /* End of Abs: '<S31>/Abs' */

        /* S-Function (sdspmdn2): '<S31>/Median1' */
        for (ixstart = 0; ixstart < 5; ixstart += 5) {
          for (i = ixstart; i < ixstart + 1; i++) {
            MDNQSort_D(0, 4, i, ctrl_TAPM_DW.Median1_Index, rtb_Abs);
            rtb_Abs1 = rtb_Abs[ctrl_TAPM_DW.Median1_Index[2] + i];
          }
        }

        /* End of S-Function (sdspmdn2): '<S31>/Median1' */

        /* Inport: '<S25>/In1' */
        ctrl_TAPM_B.In1[0] = ctrl_TAPM_B.IMU_AX1;
        ctrl_TAPM_B.In1[1] = ctrl_TAPM_B.IMU_AY1;
        ctrl_TAPM_B.In1[2] = ctrl_TAPM_B.IMU_AZ1;
        ctrl_TAPM_B.In1[3] = ctrl_TAPM_B.IMU_RX1;
        ctrl_TAPM_B.In1[4] = ctrl_TAPM_B.IMU_RY1;
        ctrl_TAPM_B.In1[5] = ctrl_TAPM_B.IMU_RZ1;
        ctrl_TAPM_B.In1[6] = ctrl_TAPM_B.IMU_V1;
        ctrl_TAPM_B.In1[7] = ctrl_TAPM_B.IMU_AX2;
        ctrl_TAPM_B.In1[8] = ctrl_TAPM_B.IMU_AY2;
        ctrl_TAPM_B.In1[9] = ctrl_TAPM_B.IMU_AZ2;
        ctrl_TAPM_B.In1[10] = ctrl_TAPM_B.IMU_RX2;
        ctrl_TAPM_B.In1[11] = ctrl_TAPM_B.IMU_RY2;
        ctrl_TAPM_B.In1[12] = ctrl_TAPM_B.IMU_RZ2;
        ctrl_TAPM_B.In1[13] = ctrl_TAPM_B.IMU_V2;
        ctrl_TAPM_B.In1[14] = ctrl_TAPM_B.IMU_AX3;
        ctrl_TAPM_B.In1[15] = ctrl_TAPM_B.IMU_AY3;
        ctrl_TAPM_B.In1[16] = ctrl_TAPM_B.IMU_AZ3;
        ctrl_TAPM_B.In1[17] = ctrl_TAPM_B.IMU_RX3;
        ctrl_TAPM_B.In1[18] = ctrl_TAPM_B.IMU_RY3;
        ctrl_TAPM_B.In1[19] = ctrl_TAPM_B.IMU_RZ3;
        ctrl_TAPM_B.In1[20] = ctrl_TAPM_B.IMU_V3;
        ctrl_TAPM_B.In1[21] = ctrl_TAPM_B.IMU_AX4;
        ctrl_TAPM_B.In1[22] = ctrl_TAPM_B.IMU_AY4;
        ctrl_TAPM_B.In1[23] = ctrl_TAPM_B.IMU_AZ4;
        ctrl_TAPM_B.In1[24] = ctrl_TAPM_B.IMU_RX4;
        ctrl_TAPM_B.In1[25] = ctrl_TAPM_B.IMU_RY4;
        ctrl_TAPM_B.In1[26] = ctrl_TAPM_B.IMU_RZ4;
        ctrl_TAPM_B.In1[27] = ctrl_TAPM_B.IMU_V4;

        /* Sum: '<S31>/Sum1' */
        rtb_Median1 = ctrl_TAPM_B.In1[6] - rtb_Median1;

        /* Abs: '<S31>/Abs1' */
        rtb_Median1 = fabs(rtb_Median1);

        /* Memory: '<S31>/Memory3' */
        for (i = 0; i < 7; i++) {
          rtb_Memory3[i] = ctrl_TAPM_DW.Memory3_PreviousInput[i];
        }

        /* End of Memory: '<S31>/Memory3' */

        /* If: '<S31>/If' incorporates:
         *  Gain: '<S31>/Gain'
         */
        if (ctrl_TAPM_P.Gain_Gain * rtb_Abs1 < rtb_Median1) {
          /* Outputs for IfAction SubSystem: '<S31>/Outlier detected' incorporates:
           *  ActionPort: '<S36>/Action Port'
           */
          ctrl_TAPM_Outlierdetected(rtb_Memory3, rtb_Memory2, rtb_Merge,
            ctrl_TAPM_B.Merge1);

          /* End of Outputs for SubSystem: '<S31>/Outlier detected' */
        } else {
          /* Outputs for IfAction SubSystem: '<S31>/No outlier' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          ctrl_TAPM_Nooutlier(&ctrl_TAPM_B.In1[0], rtb_Memory2, rtb_Merge,
                              ctrl_TAPM_B.Merge1);

          /* End of Outputs for SubSystem: '<S31>/No outlier' */
        }

        /* End of If: '<S31>/If' */

        /* Sum: '<S30>/Sum1' */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          rtb_TmpSignalConversionAtToFi_i[b_ixstart] = rtb_Merge[b_ixstart] -
            rtb_TmpSignalConversionAtToFi_i[b_ixstart];
        }

        /* End of Sum: '<S30>/Sum1' */

        /* Sum: '<S30>/Sum2' incorporates:
         *  Delay: '<S30>/Delay1'
         *  Product: '<S30>/Product'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          rtb_TmpSignalConversionAtSFun_2 = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TmpSignalConversionAtSFun_2 += rtb_PHinvHPHR[12 * i + b_ixstart]
              * rtb_TmpSignalConversionAtToFi_i[i];
          }

          T0[b_ixstart] = rtb_TmpSignalConversionAtSFun_2 +
            ctrl_TAPM_DW.Delay1_DSTATE[b_ixstart];
        }

        /* End of Sum: '<S30>/Sum2' */

        /* SignalConversion: '<S25>/TmpSignal ConversionAtTo FileInport1' */
        rtb_TmpSignalConversionAtToFi_i[0] = T0[3];
        rtb_TmpSignalConversionAtToFi_i[1] = T0[4];
        rtb_TmpSignalConversionAtToFi_i[2] = T0[5];
        rtb_TmpSignalConversionAtToFi_i[3] = T0[9];
        rtb_TmpSignalConversionAtToFi_i[4] = T0[10];
        rtb_TmpSignalConversionAtToFi_i[5] = T0[11];

        /* ToFile: '<S25>/To File' */
        {
          if (!(++ctrl_TAPM_DW.ToFile_IWORK_e.Decimation % 1) &&
              (ctrl_TAPM_DW.ToFile_IWORK_e.Count*7)+1 < 100000000 ) {
            FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile_PWORK_a.FilePtr;
            if (fp != (NULL)) {
              real_T u[7];
              ctrl_TAPM_DW.ToFile_IWORK_e.Decimation = 0;
              u[0] = ctrl_TAPM_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFi_i[0];
              u[2] = rtb_TmpSignalConversionAtToFi_i[1];
              u[3] = rtb_TmpSignalConversionAtToFi_i[2];
              u[4] = rtb_TmpSignalConversionAtToFi_i[3];
              u[5] = rtb_TmpSignalConversionAtToFi_i[4];
              u[6] = rtb_TmpSignalConversionAtToFi_i[5];
              if (fwrite(u, sizeof(real_T), 7, fp) != 7) {
                rtmSetErrorStatus(ctrl_TAPM_M,
                                  "Error writing to MAT-file IMU1.mat");
                return;
              }

              if (((++ctrl_TAPM_DW.ToFile_IWORK_e.Count)*7)+1 >= 100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file IMU1.mat.\n");
              }
            }
          }
        }

        /* Product: '<S27>/H*P*H'' incorporates:
         *  Constant: '<S27>/Constant'
         *  Delay: '<S27>/Delay'
         *  Math: '<S27>/Math Function1'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            tmp_3[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              tmp_3[b_ixstart + 12 * i] += ctrl_TAPM_DW.Delay_DSTATE_mc[12 * p3
                + b_ixstart] * ctrl_TAPM_P.Constant_Value_p[6 * p3 + i];
            }
          }
        }

        /* Sum: '<S27>/Sum' incorporates:
         *  Constant: '<S27>/Constant'
         *  Constant: '<S27>/Constant1'
         *  Product: '<S27>/H*P*H''
         */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            rtb_TmpSignalConversionAtSFun_2 = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_TmpSignalConversionAtSFun_2 += ctrl_TAPM_P.Constant_Value_p[6 *
                p3 + b_ixstart] * tmp_3[12 * i + p3];
            }

            d_0[b_ixstart + 6 * i] = ctrl_TAPM_P.Constant1_Value_e[6 * i +
              b_ixstart] + rtb_TmpSignalConversionAtSFun_2;
          }
        }

        /* End of Sum: '<S27>/Sum' */

        /* Product: '<S27>/Matrix Multiply' */
        rt_invd6x6_snf(d_0, b_V_singular);

        /* Product: '<S27>/P*H'' incorporates:
         *  Constant: '<S27>/Constant'
         *  Delay: '<S27>/Delay'
         *  Math: '<S27>/Math Function'
         *  Product: '<S27>/P*H'*inv(H*P*H'+R)'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            tmp_3[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              tmp_3[b_ixstart + 12 * i] += ctrl_TAPM_DW.Delay_DSTATE_mc[12 * p3
                + b_ixstart] * ctrl_TAPM_P.Constant_Value_p[6 * p3 + i];
            }
          }
        }

        /* End of Product: '<S27>/P*H'' */

        /* Product: '<S27>/P*H'*inv(H*P*H'+R)' */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            rtb_PHinvHPHR_o[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              rtb_PHinvHPHR_o[b_ixstart + 12 * i] += tmp_3[12 * p3 + b_ixstart] *
                b_V_singular[6 * i + p3];
            }
          }
        }

        /* Gain: '<S27>/H' incorporates:
         *  Delay: '<S27>/Delay1'
         */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          rtb_TmpSignalConversionAtToFi_i[b_ixstart] = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TmpSignalConversionAtToFi_i[b_ixstart] += ctrl_TAPM_P.H_Gain_i[6
              * i + b_ixstart] * ctrl_TAPM_DW.Delay1_DSTATE_f[i];
          }
        }

        /* End of Gain: '<S27>/H' */

        /* Memory: '<S32>/Memory2' */
        for (i = 0; i < 5; i++) {
          rtb_Memory2_p[i] = ctrl_TAPM_DW.Memory2_PreviousInput_d[i];
        }

        /* End of Memory: '<S32>/Memory2' */

        /* S-Function (sdspmdn2): '<S32>/Median' */
        for (ixstart = 0; ixstart < 5; ixstart += 5) {
          for (i = ixstart; i < ixstart + 1; i++) {
            MDNQSort_D(0, 4, i, ctrl_TAPM_DW.Median_Index_f, rtb_Memory2_p);
            rtb_Abs1 = rtb_Memory2_p[ctrl_TAPM_DW.Median_Index_f[2] + i];
          }
        }

        /* End of S-Function (sdspmdn2): '<S32>/Median' */

        /* Abs: '<S32>/Abs' incorporates:
         *  Sum: '<S32>/Sum'
         */
        for (i = 0; i < 5; i++) {
          rtb_Abs[i] = fabs(rtb_Memory2_p[i] - rtb_Abs1);
        }

        /* End of Abs: '<S32>/Abs' */

        /* S-Function (sdspmdn2): '<S32>/Median1' */
        for (ixstart = 0; ixstart < 5; ixstart += 5) {
          for (i = ixstart; i < ixstart + 1; i++) {
            MDNQSort_D(0, 4, i, ctrl_TAPM_DW.Median1_Index_p, rtb_Abs);
            rtb_Median1 = rtb_Abs[ctrl_TAPM_DW.Median1_Index_p[2] + i];
          }
        }

        /* End of S-Function (sdspmdn2): '<S32>/Median1' */

        /* Sum: '<S32>/Sum1' */
        rtb_Abs1 = ctrl_TAPM_B.In1[13] - rtb_Abs1;

        /* Abs: '<S32>/Abs1' */
        rtb_Abs1 = fabs(rtb_Abs1);

        /* Memory: '<S32>/Memory3' */
        for (i = 0; i < 7; i++) {
          rtb_Memory3_b[i] = ctrl_TAPM_DW.Memory3_PreviousInput_p[i];
        }

        /* End of Memory: '<S32>/Memory3' */

        /* If: '<S32>/If' incorporates:
         *  Gain: '<S32>/Gain'
         */
        if (ctrl_TAPM_P.Gain_Gain_c * rtb_Median1 < rtb_Abs1) {
          /* Outputs for IfAction SubSystem: '<S32>/Outlier detected' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          ctrl_TAPM_Outlierdetected(rtb_Memory3_b, rtb_Memory2_p, rtb_Merge_i,
            ctrl_TAPM_B.Merge1_e);

          /* End of Outputs for SubSystem: '<S32>/Outlier detected' */
        } else {
          /* Outputs for IfAction SubSystem: '<S32>/No outlier' incorporates:
           *  ActionPort: '<S37>/Action Port'
           */
          ctrl_TAPM_Nooutlier(&ctrl_TAPM_B.In1[7], rtb_Memory2_p, rtb_Merge_i,
                              ctrl_TAPM_B.Merge1_e);

          /* End of Outputs for SubSystem: '<S32>/No outlier' */
        }

        /* End of If: '<S32>/If' */

        /* Sum: '<S27>/Sum1' */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          rtb_TmpSignalConversionAtToFi_i[b_ixstart] = rtb_Merge_i[b_ixstart] -
            rtb_TmpSignalConversionAtToFi_i[b_ixstart];
        }

        /* End of Sum: '<S27>/Sum1' */

        /* Sum: '<S27>/Sum2' incorporates:
         *  Delay: '<S27>/Delay1'
         *  Product: '<S27>/Product'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          rtb_TmpSignalConversionAtSFun_2 = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TmpSignalConversionAtSFun_2 += rtb_PHinvHPHR_o[12 * i +
              b_ixstart] * rtb_TmpSignalConversionAtToFi_i[i];
          }

          rtb_Sum2_j[b_ixstart] = rtb_TmpSignalConversionAtSFun_2 +
            ctrl_TAPM_DW.Delay1_DSTATE_f[b_ixstart];
        }

        /* End of Sum: '<S27>/Sum2' */

        /* SignalConversion: '<S25>/TmpSignal ConversionAtTo File1Inport1' */
        rtb_TmpSignalConversionAtToFi_i[0] = rtb_Sum2_j[3];
        rtb_TmpSignalConversionAtToFi_i[1] = rtb_Sum2_j[4];
        rtb_TmpSignalConversionAtToFi_i[2] = rtb_Sum2_j[5];
        rtb_TmpSignalConversionAtToFi_i[3] = rtb_Sum2_j[9];
        rtb_TmpSignalConversionAtToFi_i[4] = rtb_Sum2_j[10];
        rtb_TmpSignalConversionAtToFi_i[5] = rtb_Sum2_j[11];

        /* ToFile: '<S25>/To File1' */
        {
          if (!(++ctrl_TAPM_DW.ToFile1_IWORK.Decimation % 1) &&
              (ctrl_TAPM_DW.ToFile1_IWORK.Count*7)+1 < 100000000 ) {
            FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile1_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[7];
              ctrl_TAPM_DW.ToFile1_IWORK.Decimation = 0;
              u[0] = ctrl_TAPM_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFi_i[0];
              u[2] = rtb_TmpSignalConversionAtToFi_i[1];
              u[3] = rtb_TmpSignalConversionAtToFi_i[2];
              u[4] = rtb_TmpSignalConversionAtToFi_i[3];
              u[5] = rtb_TmpSignalConversionAtToFi_i[4];
              u[6] = rtb_TmpSignalConversionAtToFi_i[5];
              if (fwrite(u, sizeof(real_T), 7, fp) != 7) {
                rtmSetErrorStatus(ctrl_TAPM_M,
                                  "Error writing to MAT-file IMU2.mat");
                return;
              }

              if (((++ctrl_TAPM_DW.ToFile1_IWORK.Count)*7)+1 >= 100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file IMU2.mat.\n");
              }
            }
          }
        }

        /* Product: '<S28>/H*P*H'' incorporates:
         *  Constant: '<S28>/Constant'
         *  Delay: '<S28>/Delay'
         *  Math: '<S28>/Math Function1'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            tmp_3[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              tmp_3[b_ixstart + 12 * i] += ctrl_TAPM_DW.Delay_DSTATE_dd[12 * p3
                + b_ixstart] * ctrl_TAPM_P.Constant_Value_f[6 * p3 + i];
            }
          }
        }

        /* Sum: '<S28>/Sum' incorporates:
         *  Constant: '<S28>/Constant'
         *  Constant: '<S28>/Constant1'
         *  Product: '<S28>/H*P*H''
         */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            rtb_TmpSignalConversionAtSFun_2 = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_TmpSignalConversionAtSFun_2 += ctrl_TAPM_P.Constant_Value_f[6 *
                p3 + b_ixstart] * tmp_3[12 * i + p3];
            }

            d_0[b_ixstart + 6 * i] = ctrl_TAPM_P.Constant1_Value_f[6 * i +
              b_ixstart] + rtb_TmpSignalConversionAtSFun_2;
          }
        }

        /* End of Sum: '<S28>/Sum' */

        /* Product: '<S28>/Matrix Multiply' */
        rt_invd6x6_snf(d_0, b_V_singular);

        /* Product: '<S28>/P*H'' incorporates:
         *  Constant: '<S28>/Constant'
         *  Delay: '<S28>/Delay'
         *  Math: '<S28>/Math Function'
         *  Product: '<S28>/P*H'*inv(H*P*H'+R)'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            tmp_3[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              tmp_3[b_ixstart + 12 * i] += ctrl_TAPM_DW.Delay_DSTATE_dd[12 * p3
                + b_ixstart] * ctrl_TAPM_P.Constant_Value_f[6 * p3 + i];
            }
          }
        }

        /* End of Product: '<S28>/P*H'' */

        /* Product: '<S28>/P*H'*inv(H*P*H'+R)' */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            rtb_PHinvHPHR_i[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              rtb_PHinvHPHR_i[b_ixstart + 12 * i] += tmp_3[12 * p3 + b_ixstart] *
                b_V_singular[6 * i + p3];
            }
          }
        }

        /* Gain: '<S28>/H' incorporates:
         *  Delay: '<S28>/Delay1'
         */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          rtb_TmpSignalConversionAtToFi_i[b_ixstart] = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TmpSignalConversionAtToFi_i[b_ixstart] += ctrl_TAPM_P.H_Gain_b[6
              * i + b_ixstart] * ctrl_TAPM_DW.Delay1_DSTATE_j[i];
          }
        }

        /* End of Gain: '<S28>/H' */

        /* Memory: '<S33>/Memory2' */
        for (i = 0; i < 5; i++) {
          rtb_Memory2_g[i] = ctrl_TAPM_DW.Memory2_PreviousInput_n[i];
        }

        /* End of Memory: '<S33>/Memory2' */

        /* S-Function (sdspmdn2): '<S33>/Median' */
        for (ixstart = 0; ixstart < 5; ixstart += 5) {
          for (i = ixstart; i < ixstart + 1; i++) {
            MDNQSort_D(0, 4, i, ctrl_TAPM_DW.Median_Index_j, rtb_Memory2_g);
            rtb_Abs1 = rtb_Memory2_g[ctrl_TAPM_DW.Median_Index_j[2] + i];
          }
        }

        /* End of S-Function (sdspmdn2): '<S33>/Median' */

        /* Abs: '<S33>/Abs' incorporates:
         *  Sum: '<S33>/Sum'
         */
        for (i = 0; i < 5; i++) {
          rtb_Abs[i] = fabs(rtb_Memory2_g[i] - rtb_Abs1);
        }

        /* End of Abs: '<S33>/Abs' */

        /* S-Function (sdspmdn2): '<S33>/Median1' */
        for (ixstart = 0; ixstart < 5; ixstart += 5) {
          for (i = ixstart; i < ixstart + 1; i++) {
            MDNQSort_D(0, 4, i, ctrl_TAPM_DW.Median1_Index_j, rtb_Abs);
            rtb_Median1 = rtb_Abs[ctrl_TAPM_DW.Median1_Index_j[2] + i];
          }
        }

        /* End of S-Function (sdspmdn2): '<S33>/Median1' */

        /* Sum: '<S33>/Sum1' */
        rtb_Abs1 = ctrl_TAPM_B.In1[20] - rtb_Abs1;

        /* Abs: '<S33>/Abs1' */
        rtb_Abs1 = fabs(rtb_Abs1);

        /* Memory: '<S33>/Memory3' */
        for (i = 0; i < 7; i++) {
          rtb_Memory3_m[i] = ctrl_TAPM_DW.Memory3_PreviousInput_j[i];
        }

        /* End of Memory: '<S33>/Memory3' */

        /* If: '<S33>/If' incorporates:
         *  Gain: '<S33>/Gain'
         */
        if (ctrl_TAPM_P.Gain_Gain_j * rtb_Median1 < rtb_Abs1) {
          /* Outputs for IfAction SubSystem: '<S33>/Outlier detected' incorporates:
           *  ActionPort: '<S40>/Action Port'
           */
          ctrl_TAPM_Outlierdetected(rtb_Memory3_m, rtb_Memory2_g, rtb_Merge_a,
            ctrl_TAPM_B.Merge1_k);

          /* End of Outputs for SubSystem: '<S33>/Outlier detected' */
        } else {
          /* Outputs for IfAction SubSystem: '<S33>/No outlier' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          ctrl_TAPM_Nooutlier(&ctrl_TAPM_B.In1[14], rtb_Memory2_g, rtb_Merge_a,
                              ctrl_TAPM_B.Merge1_k);

          /* End of Outputs for SubSystem: '<S33>/No outlier' */
        }

        /* End of If: '<S33>/If' */

        /* Sum: '<S28>/Sum1' */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          rtb_TmpSignalConversionAtToFi_i[b_ixstart] = rtb_Merge_a[b_ixstart] -
            rtb_TmpSignalConversionAtToFi_i[b_ixstart];
        }

        /* End of Sum: '<S28>/Sum1' */

        /* Sum: '<S28>/Sum2' incorporates:
         *  Delay: '<S28>/Delay1'
         *  Product: '<S28>/Product'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          rtb_TmpSignalConversionAtSFun_2 = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TmpSignalConversionAtSFun_2 += rtb_PHinvHPHR_i[12 * i +
              b_ixstart] * rtb_TmpSignalConversionAtToFi_i[i];
          }

          rtb_Sum2_a[b_ixstart] = rtb_TmpSignalConversionAtSFun_2 +
            ctrl_TAPM_DW.Delay1_DSTATE_j[b_ixstart];
        }

        /* End of Sum: '<S28>/Sum2' */

        /* SignalConversion: '<S25>/TmpSignal ConversionAtTo File2Inport1' */
        rtb_TmpSignalConversionAtToFi_i[0] = rtb_Sum2_a[3];
        rtb_TmpSignalConversionAtToFi_i[1] = rtb_Sum2_a[4];
        rtb_TmpSignalConversionAtToFi_i[2] = rtb_Sum2_a[5];
        rtb_TmpSignalConversionAtToFi_i[3] = rtb_Sum2_a[9];
        rtb_TmpSignalConversionAtToFi_i[4] = rtb_Sum2_a[10];
        rtb_TmpSignalConversionAtToFi_i[5] = rtb_Sum2_a[11];

        /* ToFile: '<S25>/To File2' */
        {
          if (!(++ctrl_TAPM_DW.ToFile2_IWORK.Decimation % 1) &&
              (ctrl_TAPM_DW.ToFile2_IWORK.Count*7)+1 < 100000000 ) {
            FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile2_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[7];
              ctrl_TAPM_DW.ToFile2_IWORK.Decimation = 0;
              u[0] = ctrl_TAPM_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFi_i[0];
              u[2] = rtb_TmpSignalConversionAtToFi_i[1];
              u[3] = rtb_TmpSignalConversionAtToFi_i[2];
              u[4] = rtb_TmpSignalConversionAtToFi_i[3];
              u[5] = rtb_TmpSignalConversionAtToFi_i[4];
              u[6] = rtb_TmpSignalConversionAtToFi_i[5];
              if (fwrite(u, sizeof(real_T), 7, fp) != 7) {
                rtmSetErrorStatus(ctrl_TAPM_M,
                                  "Error writing to MAT-file IMU3.mat");
                return;
              }

              if (((++ctrl_TAPM_DW.ToFile2_IWORK.Count)*7)+1 >= 100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file IMU3.mat.\n");
              }
            }
          }
        }

        /* Product: '<S29>/H*P*H'' incorporates:
         *  Constant: '<S29>/Constant'
         *  Delay: '<S29>/Delay'
         *  Math: '<S29>/Math Function1'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            tmp_3[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              tmp_3[b_ixstart + 12 * i] += ctrl_TAPM_DW.Delay_DSTATE_fg[12 * p3
                + b_ixstart] * ctrl_TAPM_P.Constant_Value_k[6 * p3 + i];
            }
          }
        }

        /* Sum: '<S29>/Sum' incorporates:
         *  Constant: '<S29>/Constant'
         *  Constant: '<S29>/Constant1'
         *  Product: '<S29>/H*P*H''
         */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            rtb_TmpSignalConversionAtSFun_2 = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_TmpSignalConversionAtSFun_2 += ctrl_TAPM_P.Constant_Value_k[6 *
                p3 + b_ixstart] * tmp_3[12 * i + p3];
            }

            d_0[b_ixstart + 6 * i] = ctrl_TAPM_P.Constant1_Value_g[6 * i +
              b_ixstart] + rtb_TmpSignalConversionAtSFun_2;
          }
        }

        /* End of Sum: '<S29>/Sum' */

        /* Product: '<S29>/Matrix Multiply' */
        rt_invd6x6_snf(d_0, b_V_singular);

        /* Product: '<S29>/P*H'' incorporates:
         *  Constant: '<S29>/Constant'
         *  Delay: '<S29>/Delay'
         *  Math: '<S29>/Math Function'
         *  Product: '<S29>/P*H'*inv(H*P*H'+R)'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            tmp_3[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              tmp_3[b_ixstart + 12 * i] += ctrl_TAPM_DW.Delay_DSTATE_fg[12 * p3
                + b_ixstart] * ctrl_TAPM_P.Constant_Value_k[6 * p3 + i];
            }
          }
        }

        /* End of Product: '<S29>/P*H'' */

        /* Product: '<S29>/P*H'*inv(H*P*H'+R)' */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 6; i++) {
            rtb_PHinvHPHR_du[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              rtb_PHinvHPHR_du[b_ixstart + 12 * i] += tmp_3[12 * p3 + b_ixstart]
                * b_V_singular[6 * i + p3];
            }
          }
        }

        /* Gain: '<S29>/H' incorporates:
         *  Delay: '<S29>/Delay1'
         */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          rtb_TmpSignalConversionAtToFi_i[b_ixstart] = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TmpSignalConversionAtToFi_i[b_ixstart] += ctrl_TAPM_P.H_Gain_p[6
              * i + b_ixstart] * ctrl_TAPM_DW.Delay1_DSTATE_i[i];
          }
        }

        /* End of Gain: '<S29>/H' */

        /* Memory: '<S34>/Memory2' */
        for (i = 0; i < 5; i++) {
          rtb_Memory2_i[i] = ctrl_TAPM_DW.Memory2_PreviousInput_c[i];
        }

        /* End of Memory: '<S34>/Memory2' */

        /* S-Function (sdspmdn2): '<S34>/Median' */
        for (ixstart = 0; ixstart < 5; ixstart += 5) {
          for (i = ixstart; i < ixstart + 1; i++) {
            MDNQSort_D(0, 4, i, ctrl_TAPM_DW.Median_Index_d, rtb_Memory2_i);
            rtb_Abs1 = rtb_Memory2_i[ctrl_TAPM_DW.Median_Index_d[2] + i];
          }
        }

        /* End of S-Function (sdspmdn2): '<S34>/Median' */

        /* Abs: '<S34>/Abs' incorporates:
         *  Sum: '<S34>/Sum'
         */
        for (i = 0; i < 5; i++) {
          rtb_Abs[i] = fabs(rtb_Memory2_i[i] - rtb_Abs1);
        }

        /* End of Abs: '<S34>/Abs' */

        /* S-Function (sdspmdn2): '<S34>/Median1' */
        for (ixstart = 0; ixstart < 5; ixstart += 5) {
          for (i = ixstart; i < ixstart + 1; i++) {
            MDNQSort_D(0, 4, i, ctrl_TAPM_DW.Median1_Index_d, rtb_Abs);
            rtb_Median1 = rtb_Abs[ctrl_TAPM_DW.Median1_Index_d[2] + i];
          }
        }

        /* End of S-Function (sdspmdn2): '<S34>/Median1' */

        /* Sum: '<S34>/Sum1' */
        rtb_Abs1 = ctrl_TAPM_B.In1[27] - rtb_Abs1;

        /* Abs: '<S34>/Abs1' */
        rtb_Abs1 = fabs(rtb_Abs1);

        /* Memory: '<S34>/Memory3' */
        for (i = 0; i < 7; i++) {
          rtb_Memory3_c[i] = ctrl_TAPM_DW.Memory3_PreviousInput_k[i];
        }

        /* End of Memory: '<S34>/Memory3' */

        /* If: '<S34>/If' incorporates:
         *  Gain: '<S34>/Gain'
         */
        if (ctrl_TAPM_P.Gain_Gain_k * rtb_Median1 < rtb_Abs1) {
          /* Outputs for IfAction SubSystem: '<S34>/Outlier detected' incorporates:
           *  ActionPort: '<S42>/Action Port'
           */
          ctrl_TAPM_Outlierdetected(rtb_Memory3_c, rtb_Memory2_i, rtb_Merge_c,
            ctrl_TAPM_B.Merge1_h);

          /* End of Outputs for SubSystem: '<S34>/Outlier detected' */
        } else {
          /* Outputs for IfAction SubSystem: '<S34>/No outlier' incorporates:
           *  ActionPort: '<S41>/Action Port'
           */
          ctrl_TAPM_Nooutlier(&ctrl_TAPM_B.In1[21], rtb_Memory2_i, rtb_Merge_c,
                              ctrl_TAPM_B.Merge1_h);

          /* End of Outputs for SubSystem: '<S34>/No outlier' */
        }

        /* End of If: '<S34>/If' */

        /* Sum: '<S29>/Sum1' */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          rtb_TmpSignalConversionAtToFi_i[b_ixstart] = rtb_Merge_c[b_ixstart] -
            rtb_TmpSignalConversionAtToFi_i[b_ixstart];
        }

        /* End of Sum: '<S29>/Sum1' */

        /* Sum: '<S29>/Sum2' incorporates:
         *  Delay: '<S29>/Delay1'
         *  Product: '<S29>/Product'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          rtb_TmpSignalConversionAtSFun_2 = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TmpSignalConversionAtSFun_2 += rtb_PHinvHPHR_du[12 * i +
              b_ixstart] * rtb_TmpSignalConversionAtToFi_i[i];
          }

          rtb_Sum2_h[b_ixstart] = rtb_TmpSignalConversionAtSFun_2 +
            ctrl_TAPM_DW.Delay1_DSTATE_i[b_ixstart];
        }

        /* End of Sum: '<S29>/Sum2' */

        /* SignalConversion: '<S25>/TmpSignal ConversionAtTo File3Inport1' */
        rtb_TmpSignalConversionAtToFi_i[0] = rtb_Sum2_h[3];
        rtb_TmpSignalConversionAtToFi_i[1] = rtb_Sum2_h[4];
        rtb_TmpSignalConversionAtToFi_i[2] = rtb_Sum2_h[5];
        rtb_TmpSignalConversionAtToFi_i[3] = rtb_Sum2_h[9];
        rtb_TmpSignalConversionAtToFi_i[4] = rtb_Sum2_h[10];
        rtb_TmpSignalConversionAtToFi_i[5] = rtb_Sum2_h[11];

        /* ToFile: '<S25>/To File3' */
        {
          if (!(++ctrl_TAPM_DW.ToFile3_IWORK.Decimation % 1) &&
              (ctrl_TAPM_DW.ToFile3_IWORK.Count*7)+1 < 100000000 ) {
            FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile3_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[7];
              ctrl_TAPM_DW.ToFile3_IWORK.Decimation = 0;
              u[0] = ctrl_TAPM_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFi_i[0];
              u[2] = rtb_TmpSignalConversionAtToFi_i[1];
              u[3] = rtb_TmpSignalConversionAtToFi_i[2];
              u[4] = rtb_TmpSignalConversionAtToFi_i[3];
              u[5] = rtb_TmpSignalConversionAtToFi_i[4];
              u[6] = rtb_TmpSignalConversionAtToFi_i[5];
              if (fwrite(u, sizeof(real_T), 7, fp) != 7) {
                rtmSetErrorStatus(ctrl_TAPM_M,
                                  "Error writing to MAT-file IMU4.mat");
                return;
              }

              if (((++ctrl_TAPM_DW.ToFile3_IWORK.Count)*7)+1 >= 100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file IMU4.mat.\n");
              }
            }
          }
        }

        /* ToFile: '<S25>/To File4' */
        {
          if (!(++ctrl_TAPM_DW.ToFile4_IWORK.Decimation % 1) &&
              (ctrl_TAPM_DW.ToFile4_IWORK.Count*8)+1 < 100000000 ) {
            FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile4_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[8];
              ctrl_TAPM_DW.ToFile4_IWORK.Decimation = 0;
              u[0] = ctrl_TAPM_M->Timing.t[1];
              u[1] = ctrl_TAPM_B.In1[0];
              u[2] = ctrl_TAPM_B.In1[1];
              u[3] = ctrl_TAPM_B.In1[2];
              u[4] = ctrl_TAPM_B.In1[3];
              u[5] = ctrl_TAPM_B.In1[4];
              u[6] = ctrl_TAPM_B.In1[5];
              u[7] = ctrl_TAPM_B.In1[6];
              if (fwrite(u, sizeof(real_T), 8, fp) != 8) {
                rtmSetErrorStatus(ctrl_TAPM_M,
                                  "Error writing to MAT-file IMU1_raw.mat");
                return;
              }

              if (((++ctrl_TAPM_DW.ToFile4_IWORK.Count)*8)+1 >= 100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file IMU1_raw.mat.\n");
              }
            }
          }
        }

        /* ToFile: '<S25>/To File5' */
        {
          if (!(++ctrl_TAPM_DW.ToFile5_IWORK.Decimation % 1) &&
              (ctrl_TAPM_DW.ToFile5_IWORK.Count*8)+1 < 100000000 ) {
            FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile5_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[8];
              ctrl_TAPM_DW.ToFile5_IWORK.Decimation = 0;
              u[0] = ctrl_TAPM_M->Timing.t[1];
              u[1] = ctrl_TAPM_B.In1[7];
              u[2] = ctrl_TAPM_B.In1[8];
              u[3] = ctrl_TAPM_B.In1[9];
              u[4] = ctrl_TAPM_B.In1[10];
              u[5] = ctrl_TAPM_B.In1[11];
              u[6] = ctrl_TAPM_B.In1[12];
              u[7] = ctrl_TAPM_B.In1[13];
              if (fwrite(u, sizeof(real_T), 8, fp) != 8) {
                rtmSetErrorStatus(ctrl_TAPM_M,
                                  "Error writing to MAT-file IMU2_raw.mat");
                return;
              }

              if (((++ctrl_TAPM_DW.ToFile5_IWORK.Count)*8)+1 >= 100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file IMU2_raw.mat.\n");
              }
            }
          }
        }

        /* ToFile: '<S25>/To File6' */
        {
          if (!(++ctrl_TAPM_DW.ToFile6_IWORK.Decimation % 1) &&
              (ctrl_TAPM_DW.ToFile6_IWORK.Count*8)+1 < 100000000 ) {
            FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile6_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[8];
              ctrl_TAPM_DW.ToFile6_IWORK.Decimation = 0;
              u[0] = ctrl_TAPM_M->Timing.t[1];
              u[1] = ctrl_TAPM_B.In1[14];
              u[2] = ctrl_TAPM_B.In1[15];
              u[3] = ctrl_TAPM_B.In1[16];
              u[4] = ctrl_TAPM_B.In1[17];
              u[5] = ctrl_TAPM_B.In1[18];
              u[6] = ctrl_TAPM_B.In1[19];
              u[7] = ctrl_TAPM_B.In1[20];
              if (fwrite(u, sizeof(real_T), 8, fp) != 8) {
                rtmSetErrorStatus(ctrl_TAPM_M,
                                  "Error writing to MAT-file IMU3_raw.mat");
                return;
              }

              if (((++ctrl_TAPM_DW.ToFile6_IWORK.Count)*8)+1 >= 100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file IMU3_raw.mat.\n");
              }
            }
          }
        }

        /* ToFile: '<S25>/To File7' */
        {
          if (!(++ctrl_TAPM_DW.ToFile7_IWORK.Decimation % 1) &&
              (ctrl_TAPM_DW.ToFile7_IWORK.Count*8)+1 < 100000000 ) {
            FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile7_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[8];
              ctrl_TAPM_DW.ToFile7_IWORK.Decimation = 0;
              u[0] = ctrl_TAPM_M->Timing.t[1];
              u[1] = ctrl_TAPM_B.In1[21];
              u[2] = ctrl_TAPM_B.In1[22];
              u[3] = ctrl_TAPM_B.In1[23];
              u[4] = ctrl_TAPM_B.In1[24];
              u[5] = ctrl_TAPM_B.In1[25];
              u[6] = ctrl_TAPM_B.In1[26];
              u[7] = ctrl_TAPM_B.In1[27];
              if (fwrite(u, sizeof(real_T), 8, fp) != 8) {
                rtmSetErrorStatus(ctrl_TAPM_M,
                                  "Error writing to MAT-file IMU4_raw.mat");
                return;
              }

              if (((++ctrl_TAPM_DW.ToFile7_IWORK.Count)*8)+1 >= 100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file IMU4_raw.mat.\n");
              }
            }
          }
        }

        /* Sum: '<S27>/Sum4' incorporates:
         *  Constant: '<S27>/Constant3'
         *  Constant: '<S27>/Identity'
         *  Product: '<S27>/K*H'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_TmpSignalConversionAtSFun_2 = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              rtb_TmpSignalConversionAtSFun_2 += rtb_PHinvHPHR_o[12 * p3 +
                b_ixstart] * ctrl_TAPM_P.Constant3_Value[6 * i + p3];
            }

            rtb_Sum5_0[b_ixstart + 12 * i] = rtb_TmpSignalConversionAtSFun_2 -
              ctrl_TAPM_P.Identity_Value[12 * i + b_ixstart];
          }
        }

        /* End of Sum: '<S27>/Sum4' */

        /* Sum: '<S28>/Sum4' incorporates:
         *  Constant: '<S28>/Constant3'
         *  Constant: '<S28>/Identity'
         *  Product: '<S28>/K*H'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_TmpSignalConversionAtSFun_2 = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              rtb_TmpSignalConversionAtSFun_2 += rtb_PHinvHPHR_i[12 * p3 +
                b_ixstart] * ctrl_TAPM_P.Constant3_Value_j[6 * i + p3];
            }

            rtb_MathFunction4[b_ixstart + 12 * i] =
              rtb_TmpSignalConversionAtSFun_2 - ctrl_TAPM_P.Identity_Value_h[12 *
              i + b_ixstart];
          }
        }

        /* End of Sum: '<S28>/Sum4' */

        /* Product: '<S28>/Matrix Multiply1' incorporates:
         *  Delay: '<S28>/Delay'
         *  Math: '<S28>/Math Function2'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_PHinvHPHR_d[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_PHinvHPHR_d[b_ixstart + 12 * i] +=
                ctrl_TAPM_DW.Delay_DSTATE_dd[12 * p3 + b_ixstart] *
                rtb_MathFunction4[12 * p3 + i];
            }
          }
        }

        /* Product: '<S28>/K*R*K'' incorporates:
         *  Constant: '<S28>/Constant4'
         *  Math: '<S28>/Math Function3'
         */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            tmp_3[b_ixstart + 6 * i] = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              tmp_3[b_ixstart + 6 * i] += ctrl_TAPM_P.Constant4_Value_k[6 * p3 +
                b_ixstart] * rtb_PHinvHPHR_i[12 * p3 + i];
            }
          }
        }

        /* Product: '<S28>/Matrix Multiply1' incorporates:
         *  Sum: '<S28>/Sum5'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_MathFunction4_0[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_MathFunction4_0[b_ixstart + 12 * i] += rtb_MathFunction4[12 *
                p3 + b_ixstart] * rtb_PHinvHPHR_d[12 * i + p3];
            }
          }
        }

        /* Product: '<S28>/K*R*K'' incorporates:
         *  Sum: '<S28>/Sum5'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_PHinvHPHR_d[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              rtb_PHinvHPHR_d[b_ixstart + 12 * i] += rtb_PHinvHPHR_i[12 * p3 +
                b_ixstart] * tmp_3[6 * i + p3];
            }
          }
        }

        /* Sum: '<S28>/Sum5' incorporates:
         *  Product: '<S28>/A*P_hat*A''
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_MathFunction4_1[i + 12 * b_ixstart] = rtb_MathFunction4_0[12 *
              b_ixstart + i] + rtb_PHinvHPHR_d[12 * b_ixstart + i];
          }
        }

        /* Product: '<S28>/A*P_hat*A'' incorporates:
         *  Constant: '<S28>/Constant6'
         *  Math: '<S28>/Math Function4'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            v1[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              v1[b_ixstart + 12 * i] += rtb_MathFunction4_1[12 * p3 + b_ixstart]
                * ctrl_TAPM_P.Constant6_Value_c[12 * p3 + i];
            }
          }
        }

        /* Sum: '<S29>/Sum4' incorporates:
         *  Constant: '<S29>/Constant3'
         *  Constant: '<S29>/Identity'
         *  Product: '<S29>/K*H'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_TmpSignalConversionAtSFun_2 = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              rtb_TmpSignalConversionAtSFun_2 += rtb_PHinvHPHR_du[12 * p3 +
                b_ixstart] * ctrl_TAPM_P.Constant3_Value_o[6 * i + p3];
            }

            rtb_MathFunction4[b_ixstart + 12 * i] =
              rtb_TmpSignalConversionAtSFun_2 - ctrl_TAPM_P.Identity_Value_f[12 *
              i + b_ixstart];
          }
        }

        /* End of Sum: '<S29>/Sum4' */

        /* Product: '<S29>/Matrix Multiply1' incorporates:
         *  Delay: '<S29>/Delay'
         *  Math: '<S29>/Math Function2'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_PHinvHPHR_d[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_PHinvHPHR_d[b_ixstart + 12 * i] +=
                ctrl_TAPM_DW.Delay_DSTATE_fg[12 * p3 + b_ixstart] *
                rtb_MathFunction4[12 * p3 + i];
            }
          }
        }

        /* Product: '<S29>/K*R*K'' incorporates:
         *  Constant: '<S29>/Constant4'
         *  Math: '<S29>/Math Function3'
         */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            tmp_3[b_ixstart + 6 * i] = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              tmp_3[b_ixstart + 6 * i] += ctrl_TAPM_P.Constant4_Value_i[6 * p3 +
                b_ixstart] * rtb_PHinvHPHR_du[12 * p3 + i];
            }
          }
        }

        /* Product: '<S29>/Matrix Multiply1' incorporates:
         *  Sum: '<S29>/Sum5'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_MathFunction4_0[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_MathFunction4_0[b_ixstart + 12 * i] += rtb_MathFunction4[12 *
                p3 + b_ixstart] * rtb_PHinvHPHR_d[12 * i + p3];
            }
          }
        }

        /* Product: '<S29>/K*R*K'' incorporates:
         *  Sum: '<S29>/Sum5'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_PHinvHPHR_e[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              rtb_PHinvHPHR_e[b_ixstart + 12 * i] += rtb_PHinvHPHR_du[12 * p3 +
                b_ixstart] * tmp_3[6 * i + p3];
            }
          }
        }

        /* Sum: '<S29>/Sum5' incorporates:
         *  Product: '<S29>/A*P_hat*A''
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_MathFunction4_1[i + 12 * b_ixstart] = rtb_MathFunction4_0[12 *
              b_ixstart + i] + rtb_PHinvHPHR_e[12 * b_ixstart + i];
          }
        }

        /* Product: '<S29>/A*P_hat*A'' incorporates:
         *  Constant: '<S29>/Constant6'
         *  Math: '<S29>/Math Function4'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            v1_0[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              v1_0[b_ixstart + 12 * i] += rtb_MathFunction4_1[12 * p3 +
                b_ixstart] * ctrl_TAPM_P.Constant6_Value_a[12 * p3 + i];
            }
          }
        }

        /* Sum: '<S30>/Sum4' incorporates:
         *  Constant: '<S30>/Constant3'
         *  Constant: '<S30>/Identity'
         *  Product: '<S30>/K*H'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_TmpSignalConversionAtSFun_2 = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              rtb_TmpSignalConversionAtSFun_2 += rtb_PHinvHPHR[12 * p3 +
                b_ixstart] * ctrl_TAPM_P.Constant3_Value_b[6 * i + p3];
            }

            rtb_MathFunction4[b_ixstart + 12 * i] =
              rtb_TmpSignalConversionAtSFun_2 - ctrl_TAPM_P.Identity_Value_h4[12
              * i + b_ixstart];
          }
        }

        /* End of Sum: '<S30>/Sum4' */

        /* Product: '<S30>/Matrix Multiply1' incorporates:
         *  Delay: '<S30>/Delay'
         *  Math: '<S30>/Math Function2'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_PHinvHPHR_d[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_PHinvHPHR_d[b_ixstart + 12 * i] +=
                ctrl_TAPM_DW.Delay_DSTATE_fv[12 * p3 + b_ixstart] *
                rtb_MathFunction4[12 * p3 + i];
            }
          }
        }

        /* Product: '<S30>/K*R*K'' incorporates:
         *  Constant: '<S30>/Constant4'
         *  Math: '<S30>/Math Function3'
         */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            tmp_3[b_ixstart + 6 * i] = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              tmp_3[b_ixstart + 6 * i] += ctrl_TAPM_P.Constant4_Value_iu[6 * p3
                + b_ixstart] * rtb_PHinvHPHR[12 * p3 + i];
            }
          }
        }

        /* Product: '<S30>/Matrix Multiply1' incorporates:
         *  Sum: '<S30>/Sum5'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_MathFunction4_0[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_MathFunction4_0[b_ixstart + 12 * i] += rtb_MathFunction4[12 *
                p3 + b_ixstart] * rtb_PHinvHPHR_d[12 * i + p3];
            }
          }
        }

        /* Product: '<S30>/K*R*K'' incorporates:
         *  Sum: '<S30>/Sum5'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_PHinvHPHR_d[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              rtb_PHinvHPHR_d[b_ixstart + 12 * i] += rtb_PHinvHPHR[12 * p3 +
                b_ixstart] * tmp_3[6 * i + p3];
            }
          }
        }

        /* Sum: '<S30>/Sum5' incorporates:
         *  Product: '<S30>/A*P_hat*A''
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_MathFunction4_1[i + 12 * b_ixstart] = rtb_MathFunction4_0[12 *
              b_ixstart + i] + rtb_PHinvHPHR_d[12 * b_ixstart + i];
          }
        }

        /* Product: '<S30>/A*P_hat*A'' incorporates:
         *  Constant: '<S30>/Constant6'
         *  Math: '<S30>/Math Function4'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_MathFunction4_0[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_MathFunction4_0[b_ixstart + 12 * i] += rtb_MathFunction4_1[12 *
                p3 + b_ixstart] * ctrl_TAPM_P.Constant6_Value_j[12 * p3 + i];
            }
          }
        }

        /* Update for Delay: '<S30>/Delay' incorporates:
         *  Constant: '<S30>/Constant5'
         *  Constant: '<S30>/Constant6'
         *  Product: '<S30>/A*P_hat*A''
         *  Sum: '<S30>/Sum6'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_TmpSignalConversionAtSFun_2 = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_TmpSignalConversionAtSFun_2 += ctrl_TAPM_P.Constant6_Value_j
                [12 * p3 + b_ixstart] * rtb_MathFunction4_0[12 * i + p3];
            }

            ctrl_TAPM_DW.Delay_DSTATE_fv[b_ixstart + 12 * i] =
              ctrl_TAPM_P.Constant5_Value_nj[12 * i + b_ixstart] +
              rtb_TmpSignalConversionAtSFun_2;
          }
        }

        /* End of Update for Delay: '<S30>/Delay' */

        /* Update for Delay: '<S30>/Delay1' incorporates:
         *  Gain: '<S30>/A'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          ctrl_TAPM_DW.Delay1_DSTATE[b_ixstart] = 0.0;
          for (i = 0; i < 12; i++) {
            ctrl_TAPM_DW.Delay1_DSTATE[b_ixstart] += ctrl_TAPM_P.A_Gain_j[12 * i
              + b_ixstart] * T0[i];
          }
        }

        /* End of Update for Delay: '<S30>/Delay1' */

        /* Update for Memory: '<S31>/Memory2' */
        for (i = 0; i < 5; i++) {
          ctrl_TAPM_DW.Memory2_PreviousInput[i] = ctrl_TAPM_B.Merge1[i];
        }

        /* End of Update for Memory: '<S31>/Memory2' */

        /* Update for Memory: '<S31>/Memory3' */
        for (i = 0; i < 7; i++) {
          ctrl_TAPM_DW.Memory3_PreviousInput[i] = ctrl_TAPM_B.In1[i];
        }

        /* End of Update for Memory: '<S31>/Memory3' */

        /* Product: '<S27>/Matrix Multiply1' incorporates:
         *  Delay: '<S27>/Delay'
         *  Math: '<S27>/Math Function2'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_PHinvHPHR_d[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_PHinvHPHR_d[b_ixstart + 12 * i] +=
                ctrl_TAPM_DW.Delay_DSTATE_mc[12 * p3 + b_ixstart] * rtb_Sum5_0
                [12 * p3 + i];
            }
          }
        }

        /* Product: '<S27>/K*R*K'' incorporates:
         *  Constant: '<S27>/Constant4'
         *  Math: '<S27>/Math Function3'
         */
        for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            tmp_3[b_ixstart + 6 * i] = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              tmp_3[b_ixstart + 6 * i] += ctrl_TAPM_P.Constant4_Value[6 * p3 +
                b_ixstart] * rtb_PHinvHPHR_o[12 * p3 + i];
            }
          }
        }

        /* Product: '<S27>/Matrix Multiply1' incorporates:
         *  Sum: '<S27>/Sum5'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_PHinvHPHR_e[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_PHinvHPHR_e[b_ixstart + 12 * i] += rtb_Sum5_0[12 * p3 +
                b_ixstart] * rtb_PHinvHPHR_d[12 * i + p3];
            }
          }
        }

        /* Product: '<S27>/K*R*K'' incorporates:
         *  Sum: '<S27>/Sum5'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_PHinvHPHR_d[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 6; p3++) {
              rtb_PHinvHPHR_d[b_ixstart + 12 * i] += rtb_PHinvHPHR_o[12 * p3 +
                b_ixstart] * tmp_3[6 * i + p3];
            }
          }
        }

        /* Sum: '<S27>/Sum5' incorporates:
         *  Product: '<S27>/A*P_hat*A''
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_Sum5_0[i + 12 * b_ixstart] = rtb_PHinvHPHR_e[12 * b_ixstart + i]
              + rtb_PHinvHPHR_d[12 * b_ixstart + i];
          }
        }

        /* Product: '<S27>/A*P_hat*A'' incorporates:
         *  Constant: '<S27>/Constant6'
         *  Math: '<S27>/Math Function4'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_PHinvHPHR_e[b_ixstart + 12 * i] = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_PHinvHPHR_e[b_ixstart + 12 * i] += rtb_Sum5_0[12 * p3 +
                b_ixstart] * ctrl_TAPM_P.Constant6_Value[12 * p3 + i];
            }
          }
        }

        /* Update for Delay: '<S27>/Delay' incorporates:
         *  Constant: '<S27>/Constant5'
         *  Constant: '<S27>/Constant6'
         *  Product: '<S27>/A*P_hat*A''
         *  Sum: '<S27>/Sum6'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_TmpSignalConversionAtSFun_2 = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_TmpSignalConversionAtSFun_2 += ctrl_TAPM_P.Constant6_Value[12 *
                p3 + b_ixstart] * rtb_PHinvHPHR_e[12 * i + p3];
            }

            ctrl_TAPM_DW.Delay_DSTATE_mc[b_ixstart + 12 * i] =
              ctrl_TAPM_P.Constant5_Value[12 * i + b_ixstart] +
              rtb_TmpSignalConversionAtSFun_2;
          }
        }

        /* End of Update for Delay: '<S27>/Delay' */

        /* Update for Delay: '<S27>/Delay1' incorporates:
         *  Gain: '<S27>/A'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          ctrl_TAPM_DW.Delay1_DSTATE_f[b_ixstart] = 0.0;
          for (i = 0; i < 12; i++) {
            ctrl_TAPM_DW.Delay1_DSTATE_f[b_ixstart] += ctrl_TAPM_P.A_Gain[12 * i
              + b_ixstart] * rtb_Sum2_j[i];
          }
        }

        /* End of Update for Delay: '<S27>/Delay1' */

        /* Update for Memory: '<S32>/Memory2' */
        for (i = 0; i < 5; i++) {
          ctrl_TAPM_DW.Memory2_PreviousInput_d[i] = ctrl_TAPM_B.Merge1_e[i];
        }

        /* End of Update for Memory: '<S32>/Memory2' */

        /* Update for Memory: '<S32>/Memory3' */
        for (i = 0; i < 7; i++) {
          ctrl_TAPM_DW.Memory3_PreviousInput_p[i] = ctrl_TAPM_B.In1[i + 7];
        }

        /* End of Update for Memory: '<S32>/Memory3' */

        /* Update for Delay: '<S28>/Delay' incorporates:
         *  Constant: '<S28>/Constant5'
         *  Constant: '<S28>/Constant6'
         *  Product: '<S28>/A*P_hat*A''
         *  Sum: '<S28>/Sum6'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_TmpSignalConversionAtSFun_2 = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_TmpSignalConversionAtSFun_2 += ctrl_TAPM_P.Constant6_Value_c
                [12 * p3 + b_ixstart] * v1[12 * i + p3];
            }

            ctrl_TAPM_DW.Delay_DSTATE_dd[b_ixstart + 12 * i] =
              ctrl_TAPM_P.Constant5_Value_n[12 * i + b_ixstart] +
              rtb_TmpSignalConversionAtSFun_2;
          }
        }

        /* End of Update for Delay: '<S28>/Delay' */

        /* Update for Delay: '<S28>/Delay1' incorporates:
         *  Gain: '<S28>/A'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          ctrl_TAPM_DW.Delay1_DSTATE_j[b_ixstart] = 0.0;
          for (i = 0; i < 12; i++) {
            ctrl_TAPM_DW.Delay1_DSTATE_j[b_ixstart] += ctrl_TAPM_P.A_Gain_n[12 *
              i + b_ixstart] * rtb_Sum2_a[i];
          }
        }

        /* End of Update for Delay: '<S28>/Delay1' */

        /* Update for Memory: '<S33>/Memory2' */
        for (i = 0; i < 5; i++) {
          ctrl_TAPM_DW.Memory2_PreviousInput_n[i] = ctrl_TAPM_B.Merge1_k[i];
        }

        /* End of Update for Memory: '<S33>/Memory2' */

        /* Update for Memory: '<S33>/Memory3' */
        for (i = 0; i < 7; i++) {
          ctrl_TAPM_DW.Memory3_PreviousInput_j[i] = ctrl_TAPM_B.In1[i + 14];
        }

        /* End of Update for Memory: '<S33>/Memory3' */

        /* Update for Delay: '<S29>/Delay' incorporates:
         *  Constant: '<S29>/Constant5'
         *  Constant: '<S29>/Constant6'
         *  Product: '<S29>/A*P_hat*A''
         *  Sum: '<S29>/Sum6'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          for (i = 0; i < 12; i++) {
            rtb_TmpSignalConversionAtSFun_2 = 0.0;
            for (p3 = 0; p3 < 12; p3++) {
              rtb_TmpSignalConversionAtSFun_2 += ctrl_TAPM_P.Constant6_Value_a
                [12 * p3 + b_ixstart] * v1_0[12 * i + p3];
            }

            ctrl_TAPM_DW.Delay_DSTATE_fg[b_ixstart + 12 * i] =
              ctrl_TAPM_P.Constant5_Value_m[12 * i + b_ixstart] +
              rtb_TmpSignalConversionAtSFun_2;
          }
        }

        /* End of Update for Delay: '<S29>/Delay' */

        /* Update for Delay: '<S29>/Delay1' incorporates:
         *  Gain: '<S29>/A'
         */
        for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
          ctrl_TAPM_DW.Delay1_DSTATE_i[b_ixstart] = 0.0;
          for (i = 0; i < 12; i++) {
            ctrl_TAPM_DW.Delay1_DSTATE_i[b_ixstart] += ctrl_TAPM_P.A_Gain_k[12 *
              i + b_ixstart] * rtb_Sum2_h[i];
          }
        }

        /* End of Update for Delay: '<S29>/Delay1' */

        /* Update for Memory: '<S34>/Memory2' */
        for (i = 0; i < 5; i++) {
          ctrl_TAPM_DW.Memory2_PreviousInput_c[i] = ctrl_TAPM_B.Merge1_h[i];
        }

        /* End of Update for Memory: '<S34>/Memory2' */

        /* Update for Memory: '<S34>/Memory3' */
        for (i = 0; i < 7; i++) {
          ctrl_TAPM_DW.Memory3_PreviousInput_k[i] = ctrl_TAPM_B.In1[i + 21];
        }

        /* End of Update for Memory: '<S34>/Memory3' */
      }

      for (i = 0; i < 28; i++) {
        ctrl_TAPM_PrevZCX.Filtering_Trig_ZCE[i] = rtb_RelationalOperator[i];
      }
    }

    /* End of Outputs for SubSystem: '<S4>/Filtering' */
  }
}

/* Model update function */
void ctrl_TAPM_update(void)
{
  /* local block i/o variables */
  real_T rtb_ImpSel_InsertedFor_reset_at;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T i;

  /* Update for Integrator: '<S19>/Integrator1' */
  ctrl_TAPM_DW.Integrator1_IWORK.IcNeedsLoading = 0;

  /* Update for Iterator SubSystem: '<S10>/Optimal angle path and  constraints on rotation speed' */
  for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
    /* Update for ForEachSliceSelector: '<S67>/ImpSel_InsertedFor_reset_at_outport_0' */
    rtb_ImpSel_InsertedFor_reset_at = ctrl_TAPM_B.reset_g[ForEach_itr];
    if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
      /* Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI = 0U;
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE +=
        ctrl_TAPM_P.CoreSubsys.DiscreteTimeIntegrator_gainval *
        ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate;
      if (rtb_ImpSel_InsertedFor_reset_at > 0.0) {
        ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 1;
      } else if (rtb_ImpSel_InsertedFor_reset_at < 0.0) {
        ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese =
          -1;
      } else if (rtb_ImpSel_InsertedFor_reset_at == 0.0) {
        ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 0;
      } else {
        ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 2;
      }

      /* End of Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */

      /* Update for Delay: '<S67>/Delay' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_TAPM_B.CoreSubsys[ForEach_itr].angle;
    }
  }

  /* End of Update for SubSystem: '<S10>/Optimal angle path and  constraints on rotation speed' */
  /* Update for Integrator: '<S6>/Integrator' */
  ctrl_TAPM_DW.Integrator_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for Delay: '<S12>/Delay' */
    for (i = 0; i < 6; i++) {
      ctrl_TAPM_DW.Delay_DSTATE[i] =
        ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[i];
    }

    /* End of Update for Delay: '<S12>/Delay' */

    /* Update for Delay: '<S75>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_f = ctrl_TAPM_B.Qa;

    /* Update for Delay: '<S90>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_fu = ctrl_TAPM_B.DiscreteTransferFcn;

    /* Update for DiscreteTransferFcn: '<S90>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp;

    /* Update for UnitDelay: '<S93>/UD' */
    ctrl_TAPM_DW.UD_DSTATE = ctrl_TAPM_B.TSamp;

    /* Update for Memory: '<S90>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput = ctrl_TAPM_B.sf_Supervisor.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S75>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_d =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a;

    /* Update for Delay: '<S76>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_b = ctrl_TAPM_B.sf_ActualForceandTorque_f.Qa;

    /* Update for Delay: '<S99>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_d = ctrl_TAPM_B.DiscreteTransferFcn_e;

    /* Update for DiscreteTransferFcn: '<S99>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_h[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_d;

    /* Update for UnitDelay: '<S102>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_n = ctrl_TAPM_B.TSamp_n;

    /* Update for Memory: '<S99>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_n = ctrl_TAPM_B.sf_Supervisor_h.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S76>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_m =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h;

    /* Update for Delay: '<S77>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_n = ctrl_TAPM_B.sf_ActualForceandTorque_h.Qa;

    /* Update for Delay: '<S108>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_no = ctrl_TAPM_B.DiscreteTransferFcn_f;

    /* Update for DiscreteTransferFcn: '<S108>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_j[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_e;

    /* Update for UnitDelay: '<S111>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_i = ctrl_TAPM_B.TSamp_k;

    /* Update for Memory: '<S108>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_d = ctrl_TAPM_B.sf_Supervisor_l.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S77>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_k =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_hh;

    /* Update for Delay: '<S78>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_e = ctrl_TAPM_B.sf_ActualForceandTorque_m.Qa;

    /* Update for Delay: '<S117>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_i = ctrl_TAPM_B.DiscreteTransferFcn_l;

    /* Update for DiscreteTransferFcn: '<S117>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_i[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_i[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_i[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_k;

    /* Update for UnitDelay: '<S120>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_n4 = ctrl_TAPM_B.TSamp_a;

    /* Update for Memory: '<S117>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_a = ctrl_TAPM_B.sf_Supervisor_n.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S78>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h0 =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_n;

    /* Update for Delay: '<S79>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_j = ctrl_TAPM_B.sf_ActualForceandTorque_o.Qa;

    /* Update for Delay: '<S126>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_a = ctrl_TAPM_B.DiscreteTransferFcn_o;

    /* Update for DiscreteTransferFcn: '<S126>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_c;

    /* Update for UnitDelay: '<S129>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_m = ctrl_TAPM_B.TSamp_m;

    /* Update for Memory: '<S126>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_b = ctrl_TAPM_B.sf_Supervisor_b.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S79>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_dt =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_f;

    /* Update for Delay: '<S80>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_dv = ctrl_TAPM_B.sf_ActualForceandTorque_j.Qa;

    /* Update for Delay: '<S135>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_m = ctrl_TAPM_B.DiscreteTransferFcn_j;

    /* Update for DiscreteTransferFcn: '<S135>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_l[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_l[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_l[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h4;

    /* Update for UnitDelay: '<S138>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_l = ctrl_TAPM_B.TSamp_o;

    /* Update for Memory: '<S135>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_a4 = ctrl_TAPM_B.sf_Supervisor_e.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S80>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_o =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_cw;

    /* Update for Memory: '<S4>/Memory' */
    memcpy(&ctrl_TAPM_DW.Memory_PreviousInput_l[0], &ctrl_TAPM_B.In1[0], 28U *
           sizeof(real_T));
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_TAPM_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_TAPM_M->Timing.clockTick0)) {
    ++ctrl_TAPM_M->Timing.clockTickH0;
  }

  ctrl_TAPM_M->Timing.t[0] = rtsiGetSolverStopTime(&ctrl_TAPM_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ctrl_TAPM_M->Timing.clockTick1)) {
      ++ctrl_TAPM_M->Timing.clockTickH1;
    }

    ctrl_TAPM_M->Timing.t[1] = ctrl_TAPM_M->Timing.clockTick1 *
      ctrl_TAPM_M->Timing.stepSize1 + ctrl_TAPM_M->Timing.clockTickH1 *
      ctrl_TAPM_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_TAPM_derivatives(void)
{
  /* Derivatives for Integrator: '<S19>/Integrator1' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator1_CSTATE[0] =
      ctrl_TAPM_B.Integrator3[0];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator1_CSTATE[1] =
      ctrl_TAPM_B.Integrator3[1];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator1_CSTATE[2] =
      ctrl_TAPM_B.Integrator3[2];
  }

  /* Derivatives for Integrator: '<S14>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE[0] =
      ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_m[0];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE[1] =
      ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_m[1];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE[2] =
      ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_m[2];
  }

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator1_CSTATE_g[0]
      = ctrl_TAPM_B.M1[0];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator1_CSTATE_g[1]
      = ctrl_TAPM_B.M1[1];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator1_CSTATE_g[2]
      = ctrl_TAPM_B.M1[2];
  }

  /* Derivatives for Integrator: '<S19>/Integrator3' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator3_CSTATE[0] =
      ctrl_TAPM_B.Sum5[0];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator3_CSTATE[1] =
      ctrl_TAPM_B.Sum5[1];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator3_CSTATE[2] =
      ctrl_TAPM_B.Sum5[2];
  }

  /* Derivatives for Integrator: '<S89>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_c =
      ctrl_TAPM_B.Findingrotationspeed;
  }

  /* Derivatives for Integrator: '<S98>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_p =
      ctrl_TAPM_B.Findingrotationspeed_a;
  }

  /* Derivatives for Integrator: '<S107>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_k =
      ctrl_TAPM_B.Findingrotationspeed_m;
  }

  /* Derivatives for Integrator: '<S116>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_n =
      ctrl_TAPM_B.Findingrotationspeed_ms;
  }

  /* Derivatives for Integrator: '<S125>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_cd =
      ctrl_TAPM_B.Findingrotationspeed_ag;
  }

  /* Derivatives for Integrator: '<S134>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_h =
      ctrl_TAPM_B.Findingrotationspeed_c;
  }

  /* Derivatives for Integrator: '<S6>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_a[0]
      = ctrl_TAPM_B.Sum1[0];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_a[1]
      = ctrl_TAPM_B.Sum1[1];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_a[2]
      = ctrl_TAPM_B.Sum1[2];
  }

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator2_CSTATE[0] =
      ctrl_TAPM_B.MatrixMultiply1[0];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator2_CSTATE[1] =
      ctrl_TAPM_B.MatrixMultiply1[1];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator2_CSTATE[2] =
      ctrl_TAPM_B.MatrixMultiply1[2];
  }

  /* Derivatives for Integrator: '<S19>/Integrator2' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator2_CSTATE_c[0]
      = ctrl_TAPM_B.MatrixMultiply[0];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator2_CSTATE_c[1]
      = ctrl_TAPM_B.MatrixMultiply[1];
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator2_CSTATE_c[2]
      = ctrl_TAPM_B.MatrixMultiply[2];
  }

  /* Derivatives for Integrator: '<S92>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_e =
      ctrl_TAPM_B.Ki;
  }

  /* Derivatives for Integrator: '<S101>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_g =
      ctrl_TAPM_B.Ki_o;
  }

  /* Derivatives for Integrator: '<S110>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_i =
      ctrl_TAPM_B.Ki_n;
  }

  /* Derivatives for Integrator: '<S119>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_l =
      ctrl_TAPM_B.Ki_b;
  }

  /* Derivatives for Integrator: '<S128>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_n4 =
      ctrl_TAPM_B.Ki_a;
  }

  /* Derivatives for Integrator: '<S137>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_gj =
      ctrl_TAPM_B.Ki_p;
  }
}

/* Model initialize function */
void ctrl_TAPM_initialize(void)
{
  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    int32_T i;

    /* Start for Iterator SubSystem: '<S10>/Optimal angle path and  constraints on rotation speed' */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].angle = 0.0;
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE = 0.0;
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].Delay = 0.0;
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI = 1U;
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 2;

      /* InitializeConditions for Delay: '<S67>/Delay' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_TAPM_P.CoreSubsys.Delay_InitialCondition;
    }

    /* End of Start for SubSystem: '<S10>/Optimal angle path and  constraints on rotation speed' */
    /* Start for ToFile: '<S8>/To File' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "oqus_measured.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error creating .mat file oqus_measured.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,7,0,"ans")) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing mat file header to file oqus_measured.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile_IWORK.Count = 0;
      ctrl_TAPM_DW.ToFile_IWORK.Decimation = -1;
      ctrl_TAPM_DW.ToFile_PWORK.FilePtr = fp;
    }

    /* Start for Triggered SubSystem: '<S4>/Filtering' */
    /* Start for ToFile: '<S25>/To File' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "IMU1.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error creating .mat file IMU1.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,7,0,"ans")) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing mat file header to file IMU1.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile_IWORK_e.Count = 0;
      ctrl_TAPM_DW.ToFile_IWORK_e.Decimation = -1;
      ctrl_TAPM_DW.ToFile_PWORK_a.FilePtr = fp;
    }

    /* Start for ToFile: '<S25>/To File1' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "IMU2.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error creating .mat file IMU2.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,7,0,"ans")) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing mat file header to file IMU2.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile1_IWORK.Count = 0;
      ctrl_TAPM_DW.ToFile1_IWORK.Decimation = -1;
      ctrl_TAPM_DW.ToFile1_PWORK.FilePtr = fp;
    }

    /* Start for ToFile: '<S25>/To File2' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "IMU3.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error creating .mat file IMU3.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,7,0,"ans")) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing mat file header to file IMU3.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile2_IWORK.Count = 0;
      ctrl_TAPM_DW.ToFile2_IWORK.Decimation = -1;
      ctrl_TAPM_DW.ToFile2_PWORK.FilePtr = fp;
    }

    /* Start for ToFile: '<S25>/To File3' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "IMU4.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error creating .mat file IMU4.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,7,0,"ans")) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing mat file header to file IMU4.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile3_IWORK.Count = 0;
      ctrl_TAPM_DW.ToFile3_IWORK.Decimation = -1;
      ctrl_TAPM_DW.ToFile3_PWORK.FilePtr = fp;
    }

    /* Start for ToFile: '<S25>/To File4' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "IMU1_raw.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error creating .mat file IMU1_raw.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,8,0,"ans")) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing mat file header to file IMU1_raw.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile4_IWORK.Count = 0;
      ctrl_TAPM_DW.ToFile4_IWORK.Decimation = -1;
      ctrl_TAPM_DW.ToFile4_PWORK.FilePtr = fp;
    }

    /* Start for ToFile: '<S25>/To File5' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "IMU2_raw.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error creating .mat file IMU2_raw.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,8,0,"ans")) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing mat file header to file IMU2_raw.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile5_IWORK.Count = 0;
      ctrl_TAPM_DW.ToFile5_IWORK.Decimation = -1;
      ctrl_TAPM_DW.ToFile5_PWORK.FilePtr = fp;
    }

    /* Start for ToFile: '<S25>/To File6' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "IMU3_raw.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error creating .mat file IMU3_raw.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,8,0,"ans")) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing mat file header to file IMU3_raw.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile6_IWORK.Count = 0;
      ctrl_TAPM_DW.ToFile6_IWORK.Decimation = -1;
      ctrl_TAPM_DW.ToFile6_PWORK.FilePtr = fp;
    }

    /* Start for ToFile: '<S25>/To File7' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "IMU4_raw.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error creating .mat file IMU4_raw.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,8,0,"ans")) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing mat file header to file IMU4_raw.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile7_IWORK.Count = 0;
      ctrl_TAPM_DW.ToFile7_IWORK.Decimation = -1;
      ctrl_TAPM_DW.ToFile7_PWORK.FilePtr = fp;
    }

    /* VirtualOutportStart for Outport: '<S25>/Out1' */
    for (i = 0; i < 28; i++) {
      ctrl_TAPM_B.In1[i] = ctrl_TAPM_P.Out1_Y0;
    }

    /* End of VirtualOutportStart for Outport: '<S25>/Out1' */
    /* End of Start for SubSystem: '<S4>/Filtering' */
  }

  {
    int32_T i;
    ctrl_TAPM_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator1_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator3_Reset_ZCE = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_o = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_nt = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator2_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_o3 = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_db = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_f = UNINITIALIZED_ZCSIG;
    ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_i3 = UNINITIALIZED_ZCSIG;
    for (i = 0; i < 28; i++) {
      ctrl_TAPM_PrevZCX.Filtering_Trig_ZCE[i] = POS_ZCSIG;
    }
  }

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    uint32_T i;
    int32_T i_0;

    /* InitializeConditions for Integrator: '<S19>/Integrator1' */
    if (rtmIsFirstInitCond(ctrl_TAPM_M)) {
      ctrl_TAPM_X.Integrator1_CSTATE[0] = 0.0;
      ctrl_TAPM_X.Integrator1_CSTATE[1] = 0.0;
      ctrl_TAPM_X.Integrator1_CSTATE[2] = 0.0;
    }

    ctrl_TAPM_DW.Integrator1_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Integrator: '<S14>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE[0] = ctrl_TAPM_P.Integrator_IC;
    ctrl_TAPM_X.Integrator_CSTATE[1] = ctrl_TAPM_P.Integrator_IC;
    ctrl_TAPM_X.Integrator_CSTATE[2] = ctrl_TAPM_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S6>/Integrator1' */
    ctrl_TAPM_X.Integrator1_CSTATE_g[0] = (ctrl_TAPM_P.Integrator1_IC[0]);
    ctrl_TAPM_X.Integrator1_CSTATE_g[1] = (ctrl_TAPM_P.Integrator1_IC[1]);
    ctrl_TAPM_X.Integrator1_CSTATE_g[2] = (ctrl_TAPM_P.Integrator1_IC[2]);

    /* InitializeConditions for Integrator: '<S19>/Integrator3' */
    ctrl_TAPM_X.Integrator3_CSTATE[0] = ctrl_TAPM_P.Integrator3_IC;
    ctrl_TAPM_X.Integrator3_CSTATE[1] = ctrl_TAPM_P.Integrator3_IC;
    ctrl_TAPM_X.Integrator3_CSTATE[2] = ctrl_TAPM_P.Integrator3_IC;

    /* InitializeConditions for Iterator SubSystem: '<S10>/Optimal angle path and  constraints on rotation speed' */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      /* InitializeConditions for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI = 1U;
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 2;

      /* InitializeConditions for Delay: '<S67>/Delay' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_TAPM_P.CoreSubsys.Delay_InitialCondition;
    }

    /* End of InitializeConditions for SubSystem: '<S10>/Optimal angle path and  constraints on rotation speed' */
    /* InitializeConditions for Integrator: '<S89>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_c = ctrl_TAPM_P.Integrator_IC_f;

    /* InitializeConditions for Integrator: '<S98>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_p = ctrl_TAPM_P.Integrator_IC_fg;

    /* InitializeConditions for Integrator: '<S107>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_k = ctrl_TAPM_P.Integrator_IC_p;

    /* InitializeConditions for Integrator: '<S116>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_n = ctrl_TAPM_P.Integrator_IC_fv;

    /* InitializeConditions for Integrator: '<S125>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_cd = ctrl_TAPM_P.Integrator_IC_l;

    /* InitializeConditions for Integrator: '<S134>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_h = ctrl_TAPM_P.Integrator_IC_li;

    /* InitializeConditions for Integrator: '<S6>/Integrator' */
    if (rtmIsFirstInitCond(ctrl_TAPM_M)) {
      ctrl_TAPM_X.Integrator_CSTATE_a[0] = 0.0;
      ctrl_TAPM_X.Integrator_CSTATE_a[1] = 0.0;
      ctrl_TAPM_X.Integrator_CSTATE_a[2] = 0.0;
    }

    ctrl_TAPM_DW.Integrator_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Integrator: '<S6>/Integrator2' */
    ctrl_TAPM_X.Integrator2_CSTATE[0] = (ctrl_TAPM_P.Integrator2_IC[0]);
    ctrl_TAPM_X.Integrator2_CSTATE[1] = (ctrl_TAPM_P.Integrator2_IC[1]);
    ctrl_TAPM_X.Integrator2_CSTATE[2] = (ctrl_TAPM_P.Integrator2_IC[2]);

    /* InitializeConditions for Integrator: '<S19>/Integrator2' */
    ctrl_TAPM_X.Integrator2_CSTATE_c[0] = ctrl_TAPM_P.Integrator2_IC_p;
    ctrl_TAPM_X.Integrator2_CSTATE_c[1] = ctrl_TAPM_P.Integrator2_IC_p;
    ctrl_TAPM_X.Integrator2_CSTATE_c[2] = ctrl_TAPM_P.Integrator2_IC_p;

    /* InitializeConditions for Delay: '<S12>/Delay' */
    for (i_0 = 0; i_0 < 6; i_0++) {
      ctrl_TAPM_DW.Delay_DSTATE[i_0] = ctrl_TAPM_P.Delay_InitialCondition_j;
    }

    /* End of InitializeConditions for Delay: '<S12>/Delay' */

    /* InitializeConditions for Delay: '<S75>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_f = ctrl_TAPM_P.Delay_InitialCondition_i;

    /* InitializeConditions for Delay: '<S90>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_fu = ctrl_TAPM_P.Delay_InitialCondition_f;

    /* InitializeConditions for DiscreteTransferFcn: '<S90>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialStat;
    ctrl_TAPM_DW.DiscreteTransferFcn_states[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialStat;

    /* InitializeConditions for UnitDelay: '<S93>/UD' */
    ctrl_TAPM_DW.UD_DSTATE = ctrl_TAPM_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for RateLimiter: '<S90>/Acceleration Limit' */
    ctrl_TAPM_DW.PrevY = ctrl_TAPM_P.AccelerationLimit_IC;

    /* InitializeConditions for Memory: '<S90>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput = ctrl_TAPM_P.Memory_X0;

    /* InitializeConditions for Integrator: '<S92>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_e = ctrl_TAPM_P.Integrator_IC_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S75>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_d =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_h;

    /* InitializeConditions for Delay: '<S76>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_b = ctrl_TAPM_P.Delay_InitialCondition_l;

    /* InitializeConditions for Delay: '<S99>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_d = ctrl_TAPM_P.Delay_InitialCondition_iv;

    /* InitializeConditions for DiscreteTransferFcn: '<S99>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_hu;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_hu;

    /* InitializeConditions for UnitDelay: '<S102>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_n = ctrl_TAPM_P.DiscreteDerivative_ICPrevScal_p;

    /* InitializeConditions for RateLimiter: '<S99>/Acceleration Limit' */
    ctrl_TAPM_DW.PrevY_e = ctrl_TAPM_P.AccelerationLimit_IC_m;

    /* InitializeConditions for Memory: '<S99>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_n = ctrl_TAPM_P.Memory_X0_e;

    /* InitializeConditions for Integrator: '<S101>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_g = ctrl_TAPM_P.Integrator_IC_fy;

    /* InitializeConditions for DiscreteTransferFcn: '<S76>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_m =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_f;

    /* InitializeConditions for Delay: '<S77>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_n = ctrl_TAPM_P.Delay_InitialCondition_dp;

    /* InitializeConditions for Delay: '<S108>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_no = ctrl_TAPM_P.Delay_InitialCondition_h;

    /* InitializeConditions for DiscreteTransferFcn: '<S108>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_a;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_j[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_a;

    /* InitializeConditions for UnitDelay: '<S111>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_i = ctrl_TAPM_P.DiscreteDerivative_ICPrevSca_pl;

    /* InitializeConditions for RateLimiter: '<S108>/Acceleration limiter' */
    ctrl_TAPM_DW.PrevY_o = ctrl_TAPM_P.Accelerationlimiter_IC;

    /* InitializeConditions for Memory: '<S108>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_d = ctrl_TAPM_P.Memory_X0_g;

    /* InitializeConditions for Integrator: '<S110>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_i = ctrl_TAPM_P.Integrator_IC_j;

    /* InitializeConditions for DiscreteTransferFcn: '<S77>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_k =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_c;

    /* InitializeConditions for Delay: '<S78>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_e = ctrl_TAPM_P.Delay_InitialCondition_fb;

    /* InitializeConditions for Delay: '<S117>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_i = ctrl_TAPM_P.Delay_InitialCondition_gg;

    /* InitializeConditions for DiscreteTransferFcn: '<S117>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_i[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_a1;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_i[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_a1;

    /* InitializeConditions for UnitDelay: '<S120>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_n4 = ctrl_TAPM_P.DiscreteDerivative_ICPrevScal_f;

    /* InitializeConditions for RateLimiter: '<S117>/Acceleration limiter' */
    ctrl_TAPM_DW.PrevY_c = ctrl_TAPM_P.Accelerationlimiter_IC_h;

    /* InitializeConditions for Memory: '<S117>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_a = ctrl_TAPM_P.Memory_X0_k;

    /* InitializeConditions for Integrator: '<S119>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_l = ctrl_TAPM_P.Integrator_IC_g;

    /* InitializeConditions for DiscreteTransferFcn: '<S78>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h0 =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_p;

    /* InitializeConditions for Delay: '<S79>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_j = ctrl_TAPM_P.Delay_InitialCondition_fv;

    /* InitializeConditions for Delay: '<S126>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_a = ctrl_TAPM_P.Delay_InitialCondition_dz;

    /* InitializeConditions for DiscreteTransferFcn: '<S126>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_e;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_e;

    /* InitializeConditions for UnitDelay: '<S129>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_m = ctrl_TAPM_P.DiscreteDerivative_ICPrevScal_o;

    /* InitializeConditions for RateLimiter: '<S126>/Acceleration limiter' */
    ctrl_TAPM_DW.PrevY_j = ctrl_TAPM_P.Accelerationlimiter_IC_i;

    /* InitializeConditions for Memory: '<S126>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_b = ctrl_TAPM_P.Memory_X0_k3;

    /* InitializeConditions for Integrator: '<S128>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_n4 = ctrl_TAPM_P.Integrator_IC_aj;

    /* InitializeConditions for DiscreteTransferFcn: '<S79>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_dt =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_pj;

    /* InitializeConditions for Delay: '<S80>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_dv = ctrl_TAPM_P.Delay_InitialCondition_fi;

    /* InitializeConditions for Delay: '<S135>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_m = ctrl_TAPM_P.Delay_InitialCondition_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S135>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_l[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_a4;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_l[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_a4;

    /* InitializeConditions for UnitDelay: '<S138>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_l = ctrl_TAPM_P.DiscreteDerivative_ICPrevScal_n;

    /* InitializeConditions for RateLimiter: '<S135>/Acceleration limiter' */
    ctrl_TAPM_DW.PrevY_h = ctrl_TAPM_P.Accelerationlimiter_IC_p;

    /* InitializeConditions for Memory: '<S135>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_a4 = ctrl_TAPM_P.Memory_X0_c;

    /* InitializeConditions for Integrator: '<S137>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_gj = ctrl_TAPM_P.Integrator_IC_h;

    /* InitializeConditions for DiscreteTransferFcn: '<S80>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_o =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_b;

    /* InitializeConditions for Memory: '<S4>/Memory' */
    memcpy(&ctrl_TAPM_DW.Memory_PreviousInput_l[0], &ctrl_TAPM_P.Memory_X0_f[0],
           28U * sizeof(real_T));

    /* InitializeConditions for Triggered SubSystem: '<S4>/Filtering' */
    /* InitializeConditions for Delay: '<S30>/Delay' */
    memcpy(&ctrl_TAPM_DW.Delay_DSTATE_fv[0],
           &ctrl_TAPM_P.Delay_InitialCondition[0], 144U * sizeof(real_T));

    /* InitializeConditions for Delay: '<S30>/Delay1' */
    memcpy(&ctrl_TAPM_DW.Delay1_DSTATE[0], &ctrl_TAPM_P.Delay1_InitialCondition
           [0], 12U * sizeof(real_T));

    /* InitializeConditions for S-Function (sdspmdn2): '<S31>/Median' */
    i = 0U;
    for (i_0 = 0; i_0 < 5; i_0++) {
      /* InitializeConditions for Memory: '<S31>/Memory2' */
      ctrl_TAPM_DW.Memory2_PreviousInput[i_0] = ctrl_TAPM_P.Memory2_X0[i_0];
      ctrl_TAPM_DW.Median_Index[i_0] = i;
      i++;
    }

    /* End of InitializeConditions for S-Function (sdspmdn2): '<S31>/Median' */

    /* InitializeConditions for S-Function (sdspmdn2): '<S31>/Median1' */
    i = 0U;
    for (i_0 = 0; i_0 < 5; i_0++) {
      ctrl_TAPM_DW.Median1_Index[i_0] = i;
      i++;
    }

    /* End of InitializeConditions for S-Function (sdspmdn2): '<S31>/Median1' */

    /* InitializeConditions for Memory: '<S31>/Memory3' */
    for (i_0 = 0; i_0 < 7; i_0++) {
      ctrl_TAPM_DW.Memory3_PreviousInput[i_0] = ctrl_TAPM_P.Memory3_X0[i_0];
    }

    /* End of InitializeConditions for Memory: '<S31>/Memory3' */

    /* InitializeConditions for Delay: '<S27>/Delay' */
    memcpy(&ctrl_TAPM_DW.Delay_DSTATE_mc[0],
           &ctrl_TAPM_P.Delay_InitialCondition_g[0], 144U * sizeof(real_T));

    /* InitializeConditions for Delay: '<S27>/Delay1' */
    memcpy(&ctrl_TAPM_DW.Delay1_DSTATE_f[0],
           &ctrl_TAPM_P.Delay1_InitialCondition_h[0], 12U * sizeof(real_T));

    /* InitializeConditions for S-Function (sdspmdn2): '<S32>/Median' */
    i = 0U;
    for (i_0 = 0; i_0 < 5; i_0++) {
      /* InitializeConditions for Memory: '<S32>/Memory2' */
      ctrl_TAPM_DW.Memory2_PreviousInput_d[i_0] = ctrl_TAPM_P.Memory2_X0_d[i_0];
      ctrl_TAPM_DW.Median_Index_f[i_0] = i;
      i++;
    }

    /* End of InitializeConditions for S-Function (sdspmdn2): '<S32>/Median' */

    /* InitializeConditions for S-Function (sdspmdn2): '<S32>/Median1' */
    i = 0U;
    for (i_0 = 0; i_0 < 5; i_0++) {
      ctrl_TAPM_DW.Median1_Index_p[i_0] = i;
      i++;
    }

    /* End of InitializeConditions for S-Function (sdspmdn2): '<S32>/Median1' */

    /* InitializeConditions for Memory: '<S32>/Memory3' */
    for (i_0 = 0; i_0 < 7; i_0++) {
      ctrl_TAPM_DW.Memory3_PreviousInput_p[i_0] = ctrl_TAPM_P.Memory3_X0_o[i_0];
    }

    /* End of InitializeConditions for Memory: '<S32>/Memory3' */

    /* InitializeConditions for Delay: '<S28>/Delay' */
    memcpy(&ctrl_TAPM_DW.Delay_DSTATE_dd[0],
           &ctrl_TAPM_P.Delay_InitialCondition_p[0], 144U * sizeof(real_T));

    /* InitializeConditions for Delay: '<S28>/Delay1' */
    memcpy(&ctrl_TAPM_DW.Delay1_DSTATE_j[0],
           &ctrl_TAPM_P.Delay1_InitialCondition_b[0], 12U * sizeof(real_T));

    /* InitializeConditions for S-Function (sdspmdn2): '<S33>/Median' */
    i = 0U;
    for (i_0 = 0; i_0 < 5; i_0++) {
      /* InitializeConditions for Memory: '<S33>/Memory2' */
      ctrl_TAPM_DW.Memory2_PreviousInput_n[i_0] = ctrl_TAPM_P.Memory2_X0_d5[i_0];
      ctrl_TAPM_DW.Median_Index_j[i_0] = i;
      i++;
    }

    /* End of InitializeConditions for S-Function (sdspmdn2): '<S33>/Median' */

    /* InitializeConditions for S-Function (sdspmdn2): '<S33>/Median1' */
    i = 0U;
    for (i_0 = 0; i_0 < 5; i_0++) {
      ctrl_TAPM_DW.Median1_Index_j[i_0] = i;
      i++;
    }

    /* End of InitializeConditions for S-Function (sdspmdn2): '<S33>/Median1' */

    /* InitializeConditions for Memory: '<S33>/Memory3' */
    for (i_0 = 0; i_0 < 7; i_0++) {
      ctrl_TAPM_DW.Memory3_PreviousInput_j[i_0] = ctrl_TAPM_P.Memory3_X0_d[i_0];
    }

    /* End of InitializeConditions for Memory: '<S33>/Memory3' */

    /* InitializeConditions for Delay: '<S29>/Delay' */
    memcpy(&ctrl_TAPM_DW.Delay_DSTATE_fg[0],
           &ctrl_TAPM_P.Delay_InitialCondition_d[0], 144U * sizeof(real_T));

    /* InitializeConditions for Delay: '<S29>/Delay1' */
    memcpy(&ctrl_TAPM_DW.Delay1_DSTATE_i[0],
           &ctrl_TAPM_P.Delay1_InitialCondition_e[0], 12U * sizeof(real_T));

    /* InitializeConditions for S-Function (sdspmdn2): '<S34>/Median' */
    i = 0U;
    for (i_0 = 0; i_0 < 5; i_0++) {
      /* InitializeConditions for Memory: '<S34>/Memory2' */
      ctrl_TAPM_DW.Memory2_PreviousInput_c[i_0] = ctrl_TAPM_P.Memory2_X0_p[i_0];
      ctrl_TAPM_DW.Median_Index_d[i_0] = i;
      i++;
    }

    /* End of InitializeConditions for S-Function (sdspmdn2): '<S34>/Median' */

    /* InitializeConditions for S-Function (sdspmdn2): '<S34>/Median1' */
    i = 0U;
    for (i_0 = 0; i_0 < 5; i_0++) {
      ctrl_TAPM_DW.Median1_Index_d[i_0] = i;
      i++;
    }

    /* End of InitializeConditions for S-Function (sdspmdn2): '<S34>/Median1' */

    /* InitializeConditions for Memory: '<S34>/Memory3' */
    for (i_0 = 0; i_0 < 7; i_0++) {
      ctrl_TAPM_DW.Memory3_PreviousInput_k[i_0] = ctrl_TAPM_P.Memory3_X0_p[i_0];
    }

    /* End of InitializeConditions for Memory: '<S34>/Memory3' */
    /* End of InitializeConditions for SubSystem: '<S4>/Filtering' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(ctrl_TAPM_M)) {
      rtmSetFirstInitCond(ctrl_TAPM_M, 0);
    }
  }
}

/* Model terminate function */
void ctrl_TAPM_terminate(void)
{
  /* Terminate for ToFile: '<S8>/To File' */
  {
    FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "oqus_measured.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error closing MAT-file oqus_measured.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error reopening MAT-file oqus_measured.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 7, ctrl_TAPM_DW.ToFile_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing header for ans to MAT-file oqus_measured.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error closing MAT-file oqus_measured.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for Triggered SubSystem: '<S4>/Filtering' */

  /* Terminate for ToFile: '<S25>/To File' */
  {
    FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile_PWORK_a.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "IMU1.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU1.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error reopening MAT-file IMU1.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 7, ctrl_TAPM_DW.ToFile_IWORK_e.Count, "ans"))
      {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing header for ans to MAT-file IMU1.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU1.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile_PWORK_a.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S25>/To File1' */
  {
    FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "IMU2.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU2.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error reopening MAT-file IMU2.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 7, ctrl_TAPM_DW.ToFile1_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing header for ans to MAT-file IMU2.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU2.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S25>/To File2' */
  {
    FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile2_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "IMU3.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU3.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error reopening MAT-file IMU3.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 7, ctrl_TAPM_DW.ToFile2_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing header for ans to MAT-file IMU3.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU3.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile2_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S25>/To File3' */
  {
    FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile3_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "IMU4.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU4.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error reopening MAT-file IMU4.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 7, ctrl_TAPM_DW.ToFile3_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing header for ans to MAT-file IMU4.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU4.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile3_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S25>/To File4' */
  {
    FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile4_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "IMU1_raw.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU1_raw.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error reopening MAT-file IMU1_raw.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 8, ctrl_TAPM_DW.ToFile4_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing header for ans to MAT-file IMU1_raw.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU1_raw.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile4_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S25>/To File5' */
  {
    FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile5_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "IMU2_raw.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU2_raw.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error reopening MAT-file IMU2_raw.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 8, ctrl_TAPM_DW.ToFile5_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing header for ans to MAT-file IMU2_raw.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU2_raw.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile5_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S25>/To File6' */
  {
    FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile6_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "IMU3_raw.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU3_raw.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error reopening MAT-file IMU3_raw.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 8, ctrl_TAPM_DW.ToFile6_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing header for ans to MAT-file IMU3_raw.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU3_raw.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile6_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S25>/To File7' */
  {
    FILE *fp = (FILE *) ctrl_TAPM_DW.ToFile7_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "IMU4_raw.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU4_raw.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error reopening MAT-file IMU4_raw.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 8, ctrl_TAPM_DW.ToFile7_IWORK.Count, "ans"))
      {
        rtmSetErrorStatus(ctrl_TAPM_M,
                          "Error writing header for ans to MAT-file IMU4_raw.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(ctrl_TAPM_M, "Error closing MAT-file IMU4_raw.mat");
        return;
      }

      ctrl_TAPM_DW.ToFile7_PWORK.FilePtr = (NULL);
    }
  }

  /* End of Terminate for SubSystem: '<S4>/Filtering' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ctrl_TAPM_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_TAPM_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ctrl_TAPM_initialize();
}

void MdlTerminate(void)
{
  ctrl_TAPM_terminate();
}

/* Registration function */
RT_MODEL_ctrl_TAPM_T *ctrl_TAPM(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_TAPM_M, 0,
                sizeof(RT_MODEL_ctrl_TAPM_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_TAPM_M->solverInfo,
                          &ctrl_TAPM_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_TAPM_M->solverInfo, &rtmGetTPtr(ctrl_TAPM_M));
    rtsiSetStepSizePtr(&ctrl_TAPM_M->solverInfo, &ctrl_TAPM_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_TAPM_M->solverInfo, &ctrl_TAPM_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_TAPM_M->solverInfo, (real_T **)
                         &ctrl_TAPM_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_TAPM_M->solverInfo,
      &ctrl_TAPM_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_TAPM_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_TAPM_M)));
    rtsiSetRTModelPtr(&ctrl_TAPM_M->solverInfo, ctrl_TAPM_M);
  }

  rtsiSetSimTimeStep(&ctrl_TAPM_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_TAPM_M->ModelData.intgData.y = ctrl_TAPM_M->ModelData.odeY;
  ctrl_TAPM_M->ModelData.intgData.f[0] = ctrl_TAPM_M->ModelData.odeF[0];
  ctrl_TAPM_M->ModelData.intgData.f[1] = ctrl_TAPM_M->ModelData.odeF[1];
  ctrl_TAPM_M->ModelData.intgData.f[2] = ctrl_TAPM_M->ModelData.odeF[2];
  ctrl_TAPM_M->ModelData.contStates = ((real_T *) &ctrl_TAPM_X);
  rtsiSetSolverData(&ctrl_TAPM_M->solverInfo, (void *)
                    &ctrl_TAPM_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_TAPM_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_TAPM_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_TAPM_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_TAPM_M->Timing.sampleTimes = (&ctrl_TAPM_M->Timing.sampleTimesArray[0]);
    ctrl_TAPM_M->Timing.offsetTimes = (&ctrl_TAPM_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_TAPM_M->Timing.sampleTimes[0] = (0.0);
    ctrl_TAPM_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_TAPM_M->Timing.offsetTimes[0] = (0.0);
    ctrl_TAPM_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_TAPM_M, &ctrl_TAPM_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_TAPM_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_TAPM_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_TAPM_M, -1);
  ctrl_TAPM_M->Timing.stepSize0 = 0.01;
  ctrl_TAPM_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_TAPM_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_TAPM_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_TAPM_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_TAPM_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_TAPM_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_TAPM_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_TAPM_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_TAPM_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_TAPM_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_TAPM_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_TAPM_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_TAPM_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_TAPM_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_TAPM_M->rtwLogInfo, (NULL));
  }

  ctrl_TAPM_M->solverInfoPtr = (&ctrl_TAPM_M->solverInfo);
  ctrl_TAPM_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_TAPM_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_TAPM_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_TAPM_M->ModelData.blockIO = ((void *) &ctrl_TAPM_B);
  (void) memset(((void *) &ctrl_TAPM_B), 0,
                sizeof(B_ctrl_TAPM_T));

  /* parameters */
  ctrl_TAPM_M->ModelData.defaultParam = ((real_T *)&ctrl_TAPM_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_TAPM_X;
    ctrl_TAPM_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_TAPM_X, 0,
                  sizeof(X_ctrl_TAPM_T));
  }

  /* states (dwork) */
  ctrl_TAPM_M->ModelData.dwork = ((void *) &ctrl_TAPM_DW);
  (void) memset((void *)&ctrl_TAPM_DW, 0,
                sizeof(DW_ctrl_TAPM_T));

  /* Initialize Sizes */
  ctrl_TAPM_M->Sizes.numContStates = (33);/* Number of continuous states */
  ctrl_TAPM_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_TAPM_M->Sizes.numY = (0);       /* Number of model outputs */
  ctrl_TAPM_M->Sizes.numU = (0);       /* Number of model inputs */
  ctrl_TAPM_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_TAPM_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_TAPM_M->Sizes.numBlocks = (788);/* Number of blocks */
  ctrl_TAPM_M->Sizes.numBlockIO = (253);/* Number of block outputs */
  ctrl_TAPM_M->Sizes.numBlockPrms = (5274);/* Sum of parameter "widths" */
  return ctrl_TAPM_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_TAPM
 * Model version : 1.190
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Thu Apr 20 19:54:33 2017
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_TAPM
#include "ni_modelframework_ex.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;

/*========================================================================*
 * Function: NIRT_GetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the source
 *      subindex : index value if vector
 *      type   : the source's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
double NIRT_GetValueByDataType(void* ptr, int32_t subindex, int32_t type,
  int32_t Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 14:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 35:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 36:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 37:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 38:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 39:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 40:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 41:
    return NIRT_GetValueByDataType(ptr,subindex,10,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 43:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 44:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 45:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 48:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 49:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 50:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 51:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 52:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 53:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 54:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 55:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 56:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 57:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 58:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 60:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 61:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 62:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 63:
    return (double)(((real_T*)ptr)[subindex]);

   case 64:
    return NIRT_GetValueByDataType(ptr,subindex,63,Complex);

   case 69:
    return NIRT_GetValueByDataType(ptr,subindex,68,Complex);

   case 77:
    return NIRT_GetValueByDataType(ptr,subindex,76,Complex);

   case 85:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 86:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 87:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 88:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

/*========================================================================*
 * Function: NIRT_SetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the destination
 *      subindex : index value if vector
 *      value : value to set on the destination
 *      type   : the destination's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NIRT_SetValueByDataType(void* ptr, int32_t subindex, double value,
  int32_t type, int32_t Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 14:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 17:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 19:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 20:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 31:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 32:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 35:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 36:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 37:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 38:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 39:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 40:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 41:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,10,Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 43:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 44:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 45:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 48:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 49:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 50:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 51:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 52:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 53:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 54:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 55:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 56:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 57:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 58:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 60:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 61:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 62:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 63:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 64:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,63,Complex);

   case 69:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,68,Complex);

   case 77:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,76,Complex);

   case 85:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 86:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 87:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 88:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_TAPM_rtModel *S;
extern _SITexportglobals SITexportglobals;

/*========================================================================*
 * Function: SetExternalInputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalInputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  // ctrl_TAPM/Input1/Control Gains/K_p_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_p_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Control Gains/K_p_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_p_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Control Gains/K_p_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_p_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Control Gains/K_i_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_i_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Control Gains/K_i_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_i_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Control Gains/K_i_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_i_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Control Gains/K_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Control Gains/K_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Control Gains/K_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Pos measurements/x_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.x_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Pos measurements/y_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.y_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Pos measurements/psi_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.psi_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Guidance gains/w_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.w_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Guidance gains/w_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.w_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Guidance gains/w_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.w_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Guidance gains/zeta_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.zeta_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Guidance gains/zeta_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.zeta_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/Guidance gains/zeta_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.zeta_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/psi_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.psi_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/x_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.x_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input1/y_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.y_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster measurment/thr_angle_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.thr_angle_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster measurment/thr_angle_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.thr_angle_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster measurment/thr_angle_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.thr_angle_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster measurment/thr_angle_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.thr_angle_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster measurment/thr_angle_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.thr_angle_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster measurment/thr_angle_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.thr_angle_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thrust allocation/reset
  if (TaskSampleHit[1]) {
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_g, count, data[index++], 26, 0);
    }
  } else {
    index += 6;
  }

  // ctrl_TAPM/Thrust allocation/Angle_controller
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.Angle_controller, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thruster 1/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_o, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thruster 2/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_c, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thruster 3/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_j, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thruster 4/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_p, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thruster 5/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_k, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thruster 6/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_i, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/rpm1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.rpm1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/rpm2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.rpm2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/rpm3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.rpm3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/rpm4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.rpm4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/rpm5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.rpm5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thrust and Shaft speed mapped to PWM/rpm6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.rpm6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Pos measurements/X_oqus
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.X_oqus, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Pos measurements/Y_oqus
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.Y_oqus, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Pos measurements/Z_oqus
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.Z_oqus, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Pos measurements/roll_oqus
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.roll_oqus, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Pos measurements/pitch_oqus
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.pitch_oqus, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Pos measurements/yaw_oqus
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.yaw_oqus, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thruster 1/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_kk, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thruster 2/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_e, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thruster 3/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_j2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thruster 4/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_n, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thruster 5/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_f, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Thruster control /Thruster 6/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.reset_om, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_AX1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_AX1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_AY1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_AY1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_AZ1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_AZ1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_RX1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_RX1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_RY1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_RY1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_RZ1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_RZ1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_V1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_V1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_AX2
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_AX2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_AY2
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_AY2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_AZ2
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_AZ2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_RX2
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_RX2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_RY2
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_RY2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_RZ2
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_RZ2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_V2
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_V2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_AX3
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_AX3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_AY3
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_AY3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_AZ3
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_AZ3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_RX3
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_RX3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_RY3
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_RY3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_RZ3
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_RZ3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_V3
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_V3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_AX4
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_AX4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_AY4
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_AY4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_AZ4
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_AZ4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_RX4
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_RX4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_RY4
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_RY4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_RZ4
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_RZ4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/IMU/IMU_V4
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.IMU_V4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 87;
}

int32_t NumOutputPorts(void)
{
  return 40;
}

double ni_extout[40];

/*========================================================================*
 * Function: SetExternalOutputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalOutputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;

  // ctrl_TAPM/alpha_1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation1, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.sf_MATLABFunction2.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.sf_MATLABFunction3.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.sf_MATLABFunction4.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.sf_MATLABFunction5.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/alpha_2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation2, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.sf_MATLABFunction6.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/alpha_3: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation3, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/alpha_4: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation4, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/alpha_5: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation5, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/alpha_6: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation6, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/u_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 0, 26,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/u_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 3, 26,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/u_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 4, 26,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/u_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 5, 26,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/u_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 1, 26,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/u_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 2, 26,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Observer output /eta_hat output/x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator, 0, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Observer output /eta_hat output/y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator, 1, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Sum, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Observer output /nu_hat output/u_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator1, 0, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Observer output /nu_hat output/v_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator1, 1, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Observer output /nu_hat output/r_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator1, 2, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.M1, 0, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.M1, 1, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.M1, 2, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator2, 0, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator2, 1, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator2, 2, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/tau_actual: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.commanded_tau, 0,
      22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.commanded_tau, 1,
      22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.commanded_tau, 2,
      22, 0);
  } else {
    index += 3;
  }

  // ctrl_TAPM/Control/DP Controller/eta_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.regulationerror, 0,
      21, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.regulationerror, 1,
      21, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.regulationerror, 2,
      21, 0);
  } else {
    index += 3;
  }

  // ctrl_TAPM/Guidance/eta_des: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.TmpSignalConversionAtMatrixMult, 0, 21, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.TmpSignalConversionAtMatrixMult, 1, 21, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.TmpSignalConversionAtMatrixMult, 2, 21, 0);
  } else {
    index += 3;
  }

  // ctrl_TAPM/Thruster control /Thruster 1/Propeller Hydrodynamics/Control_test_Pa: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Pa, 0, 0, 0);
  } else {
    index += 1;
  }

  if (data != NULL) {
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
  }

  UNUSED_PARAMETER(count);
}

/*========================================================================*
 * Function: NI_InitExternalOutputs
 *
 * Abstract:
 *		Initialize model ports
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NI_InitExternalOutputs()
{
  int index = 0, count = 0;

  // ctrl_TAPM/alpha_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation1, 0, 0, 0);

  // ctrl_TAPM/pwm_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.sf_MATLABFunction2.Tc_out, 0, 0, 0);

  // ctrl_TAPM/pwm_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.sf_MATLABFunction3.Tc_out, 0, 0, 0);

  // ctrl_TAPM/pwm_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.sf_MATLABFunction4.Tc_out, 0, 0, 0);

  // ctrl_TAPM/pwm_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.sf_MATLABFunction5.Tc_out, 0, 0, 0);

  // ctrl_TAPM/alpha_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation2, 0, 0, 0);

  // ctrl_TAPM/pwm_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.sf_MATLABFunction6.Tc_out, 0, 0, 0);

  // ctrl_TAPM/alpha_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation3, 0, 0, 0);

  // ctrl_TAPM/alpha_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation4, 0, 0, 0);

  // ctrl_TAPM/alpha_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation5, 0, 0, 0);

  // ctrl_TAPM/alpha_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation6, 0, 0, 0);

  // ctrl_TAPM/u_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 0, 26,
    0);

  // ctrl_TAPM/u_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 3, 26,
    0);

  // ctrl_TAPM/u_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 4, 26,
    0);

  // ctrl_TAPM/u_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 5, 26,
    0);

  // ctrl_TAPM/u_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 1, 26,
    0);

  // ctrl_TAPM/u_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 2, 26,
    0);

  // ctrl_TAPM/pwm_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Tc_out, 0, 0, 0);

  // ctrl_TAPM/Observer output /eta_hat output/x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator, 0, 22, 0);

  // ctrl_TAPM/Observer output /eta_hat output/y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator, 1, 22, 0);

  // ctrl_TAPM/Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Sum, 0, 0, 0);

  // ctrl_TAPM/Observer output /nu_hat output/u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator1, 0, 22,
    0);

  // ctrl_TAPM/Observer output /nu_hat output/v_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator1, 1, 22,
    0);

  // ctrl_TAPM/Observer output /nu_hat output/r_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator1, 2, 22,
    0);

  // ctrl_TAPM/Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.M1, 0, 22, 0);

  // ctrl_TAPM/Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.M1, 1, 22, 0);

  // ctrl_TAPM/Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.M1, 2, 22, 0);

  // ctrl_TAPM/Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator2, 0, 22,
    0);

  // ctrl_TAPM/Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator2, 1, 22,
    0);

  // ctrl_TAPM/Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Integrator2, 2, 22,
    0);

  // ctrl_TAPM/tau_actual: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.commanded_tau, 0, 22,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.commanded_tau, 1, 22,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.commanded_tau, 2, 22,
    0);

  // ctrl_TAPM/Control/DP Controller/eta_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.regulationerror, 0,
    21, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.regulationerror, 1,
    21, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.regulationerror, 2,
    21, 0);

  // ctrl_TAPM/Guidance/eta_des: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.TmpSignalConversionAtMatrixMult, 0, 21, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.TmpSignalConversionAtMatrixMult, 1, 21, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.TmpSignalConversionAtMatrixMult, 2, 21, 0);

  // ctrl_TAPM/Thruster control /Thruster 1/Propeller Hydrodynamics/Control_test_Pa: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Pa, 0, 0, 0);
  UNUSED_PARAMETER(count);
  return NI_OK;
}

/* Undefine parameter macros. The undef allows us to access the real declarations.
   In the Simulink(R) generated code, the parameters are redefined to be the read-side of rtParameter.*/
#define _NI_UNDEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"

/* All elements by default (including scalars) have 2 dimensions [1,1] */
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "ctrl_tapm/Thrust allocation/C/Value", offsetof(P_ctrl_TAPM_T, C), 42, 24,
    2, 0, 0 },

  { 1, "ctrl_tapm/Thruster Parameters /D/Value", offsetof(P_ctrl_TAPM_T, D), 85,
    1, 2, 2, 0 },

  { 2,
    "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 85, 1, 2, 4, 0 },

  { 3,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 85, 1, 2, 6, 0 },

  { 4,
    "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 85, 1, 2, 8, 0 },

  { 5,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 85, 1, 2, 10, 0 },

  { 6,
    "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 85, 1, 2, 12, 0 },

  { 7,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 85, 1, 2, 14, 0 },

  { 8,
    "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 85, 1, 2, 16, 0 },

  { 9,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 85, 1, 2, 18, 0 },

  { 10,
    "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 85, 1, 2, 20, 0 },

  { 11,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 85, 1, 2, 22, 0 },

  { 12,
    "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 85, 1, 2, 24, 0 },

  { 13,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 85, 1, 2, 26, 0 },

  { 14, "ctrl_tapm/Thruster Parameters /K_Tf1/Value", offsetof(P_ctrl_TAPM_T,
    K_T1f), 85, 1, 2, 28, 0 },

  { 15, "ctrl_tapm/Thruster Parameters /K_Tr1/Value", offsetof(P_ctrl_TAPM_T,
    K_T1r), 85, 1, 2, 30, 0 },

  { 16, "ctrl_tapm/Thruster Parameters /K_Tf2/Value", offsetof(P_ctrl_TAPM_T,
    K_T2f), 85, 1, 2, 32, 0 },

  { 17, "ctrl_tapm/Thruster Parameters /K_Tr2/Value", offsetof(P_ctrl_TAPM_T,
    K_T2r), 85, 1, 2, 34, 0 },

  { 18, "ctrl_tapm/Thruster Parameters /K_Tf3/Value", offsetof(P_ctrl_TAPM_T,
    K_T3f), 85, 1, 2, 36, 0 },

  { 19, "ctrl_tapm/Thruster Parameters /K_Tr3/Value", offsetof(P_ctrl_TAPM_T,
    K_T3r), 85, 1, 2, 38, 0 },

  { 20, "ctrl_tapm/Thruster Parameters /K_Tf4/Value", offsetof(P_ctrl_TAPM_T,
    K_T4f), 85, 1, 2, 40, 0 },

  { 21, "ctrl_tapm/Thruster Parameters /K_Tr4/Value", offsetof(P_ctrl_TAPM_T,
    K_T4r), 85, 1, 2, 42, 0 },

  { 22, "ctrl_tapm/Thruster Parameters /K_Tf5/Value", offsetof(P_ctrl_TAPM_T,
    K_T5f), 85, 1, 2, 44, 0 },

  { 23, "ctrl_tapm/Thruster Parameters /K_Tr5/Value", offsetof(P_ctrl_TAPM_T,
    K_T5r), 85, 1, 2, 46, 0 },

  { 24, "ctrl_tapm/Thruster Parameters /K_Tf6/Value", offsetof(P_ctrl_TAPM_T,
    K_T6f), 85, 1, 2, 48, 0 },

  { 25, "ctrl_tapm/Thruster Parameters /K_Tr6/Value", offsetof(P_ctrl_TAPM_T,
    K_T6r), 85, 1, 2, 50, 0 },

  { 26, "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 85, 1, 2, 52, 0 },

  { 27, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 85, 1, 2, 54, 0 },

  { 28, "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 85, 1, 2, 56, 0 },

  { 29, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 85, 1, 2, 58, 0 },

  { 30, "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 85, 1, 2, 60, 0 },

  { 31, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 85, 1, 2, 62, 0 },

  { 32, "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 85, 1, 2, 64, 0 },

  { 33, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 85, 1, 2, 66, 0 },

  { 34, "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 85, 1, 2, 68, 0 },

  { 35, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 85, 1, 2, 70, 0 },

  { 36, "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 85, 1, 2, 72, 0 },

  { 37, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 85, 1, 2, 74, 0 },

  { 38, "ctrl_tapm/Thruster Parameters /K_Qr1/Value", offsetof(P_ctrl_TAPM_T,
    K_q1f), 85, 1, 2, 76, 0 },

  { 39, "ctrl_tapm/Thruster Parameters /K_Qr7/Value", offsetof(P_ctrl_TAPM_T,
    K_q1r), 85, 1, 2, 78, 0 },

  { 40, "ctrl_tapm/Thruster Parameters /K_Qr2/Value", offsetof(P_ctrl_TAPM_T,
    K_q2f), 85, 1, 2, 80, 0 },

  { 41, "ctrl_tapm/Thruster Parameters /K_Qr8/Value", offsetof(P_ctrl_TAPM_T,
    K_q2r), 85, 1, 2, 82, 0 },

  { 42, "ctrl_tapm/Thruster Parameters /K_Qr3/Value", offsetof(P_ctrl_TAPM_T,
    K_q3f), 85, 1, 2, 84, 0 },

  { 43, "ctrl_tapm/Thruster Parameters /K_Qr9/Value", offsetof(P_ctrl_TAPM_T,
    K_q3r), 85, 1, 2, 86, 0 },

  { 44, "ctrl_tapm/Thruster Parameters /K_Qr4/Value", offsetof(P_ctrl_TAPM_T,
    K_q4f), 85, 1, 2, 88, 0 },

  { 45, "ctrl_tapm/Thruster Parameters /K_Qr10/Value", offsetof(P_ctrl_TAPM_T,
    K_q4r), 85, 1, 2, 90, 0 },

  { 46, "ctrl_tapm/Thruster Parameters /K_Qr5/Value", offsetof(P_ctrl_TAPM_T,
    K_q5f), 85, 1, 2, 92, 0 },

  { 47, "ctrl_tapm/Thruster Parameters /K_Qr11/Value", offsetof(P_ctrl_TAPM_T,
    K_q5r), 85, 1, 2, 94, 0 },

  { 48, "ctrl_tapm/Thruster Parameters /K_Qr6/Value", offsetof(P_ctrl_TAPM_T,
    K_q6f), 85, 1, 2, 96, 0 },

  { 49, "ctrl_tapm/Thruster Parameters /K_Qr12/Value", offsetof(P_ctrl_TAPM_T,
    K_q6r), 85, 1, 2, 98, 0 },

  { 50,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 85, 1, 2, 100, 0 },

  { 51,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 85, 1, 2, 102, 0 },

  { 52,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 85, 1, 2, 104, 0 },

  { 53,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 85, 1, 2, 106, 0 },

  { 54,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 85, 1, 2, 108, 0 },

  { 55,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 85, 1, 2, 110, 0 },

  { 56,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 85, 1, 2, 112, 0 },

  { 57,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 85, 1, 2, 114, 0 },

  { 58,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 85, 1, 2, 116, 0 },

  { 59,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 85, 1, 2, 118, 0 },

  { 60,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 85, 1, 2, 120, 0 },

  { 61,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 85, 1, 2, 122, 0 },

  { 62,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Max Rotation Rate/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_rotation), 85, 1, 2, 124, 0 },

  { 63,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Max Rotation Rate/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Max_rotation), 85, 1, 2, 126, 0 },

  { 64,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 1/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 85, 1, 2, 128, 0 },

  { 65,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 10/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 85, 1, 2, 130, 0 },

  { 66,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 12/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 85, 1, 2, 132, 0 },

  { 67,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 3/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 85, 1, 2, 134, 0 },

  { 68,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 5/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 85, 1, 2, 136, 0 },

  { 69,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 85, 1, 2, 138, 0 },

  { 70,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 85, 1, 2, 140, 0 },

  { 71,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 8/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 85, 1, 2, 142, 0 },

  { 72,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 11/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Min_thrust), 85, 1, 2, 144, 0 },

  { 73,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 13/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Min_thrust), 85, 1, 2, 146, 0 },

  { 74,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 2/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Min_thrust), 85, 1, 2, 148, 0 },

  { 75,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 4/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Min_thrust), 85, 1, 2, 150, 0 },

  { 76,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 6/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Min_thrust), 85, 1, 2, 152, 0 },

  { 77,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 9/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Min_thrust), 85, 1, 2, 154, 0 },

  { 78, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 85, 1, 2, 156, 0 },

  { 79, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 85, 1, 2, 158, 0 },

  { 80, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 85, 1, 2, 160, 0 },

  { 81, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 85, 1, 2, 162, 0 },

  { 82, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 85, 1, 2, 164, 0 },

  { 83, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 85, 1, 2, 166, 0 },

  { 84, "ctrl_tapm/Thruster Parameters /Rho/Value", offsetof(P_ctrl_TAPM_T, Rho),
    85, 1, 2, 168, 0 },

  { 85, "ctrl_tapm/Thrust allocation/Constant to avoid singularities/Value",
    offsetof(P_ctrl_TAPM_T, eps), 85, 1, 2, 170, 0 },

  { 86, "ctrl_tapm/Thruster Parameters /Constant/Value", offsetof(P_ctrl_TAPM_T,
    eps_c), 85, 1, 2, 172, 0 },

  { 87, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 85, 1, 2, 174, 0 },

  { 88, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 85, 1, 2, 176, 0 },

  { 89, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 85, 1, 2, 178, 0 },

  { 90, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 85, 1, 2, 180, 0 },

  { 91, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 85, 1, 2, 182, 0 },

  { 92, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 85, 1, 2, 184, 0 },

  { 93, "ctrl_tapm/Thruster Parameters /Constant1/Value", offsetof(P_ctrl_TAPM_T,
    k_cc), 85, 1, 2, 186, 0 },

  { 94, "ctrl_tapm/Thruster Parameters /Constant5/Value", offsetof(P_ctrl_TAPM_T,
    n_c), 85, 1, 2, 188, 0 },

  { 95, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 85, 1, 2, 190, 0 },

  { 96, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 85, 1, 2, 192, 0 },

  { 97, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 85, 1, 2, 194, 0 },

  { 98, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 85, 1, 2, 196, 0 },

  { 99, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 85, 1, 2, 198, 0 },

  { 100,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 85, 1, 2, 200, 0 },

  { 101, "ctrl_tapm/Thruster Parameters /Constant2/Value", offsetof
    (P_ctrl_TAPM_T, p_cc), 85, 1, 2, 202, 0 },

  { 102,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 1/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr1_backward), 50, 6, 2, 204, 0 },

  { 103,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 1/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr1_forward), 50, 6, 2, 206, 0 },

  { 104,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 2/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr2_backward), 50, 6, 2, 208, 0 },

  { 105,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 2/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr2_forward), 50, 6, 2, 210, 0 },

  { 106,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 3/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr3_backward), 50, 6, 2, 212, 0 },

  { 107,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 3/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr3_forward), 50, 6, 2, 214, 0 },

  { 108,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 4/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr4_backward), 50, 6, 2, 216, 0 },

  { 109,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 4/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr4_forward), 50, 6, 2, 218, 0 },

  { 110,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 5/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr5_backward), 50, 6, 2, 220, 0 },

  { 111,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 5/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr5_forward), 50, 6, 2, 222, 0 },

  { 112,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 6/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr6_backward), 50, 6, 2, 224, 0 },

  { 113,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 6/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr6_forward), 50, 6, 2, 226, 0 },

  { 114, "ctrl_tapm/Thruster Parameters /Constant3/Value", offsetof
    (P_ctrl_TAPM_T, r_cc), 85, 1, 2, 228, 0 },

  { 115,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScaled), 85, 1, 2, 230, 0 },

  { 116,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScal_p), 85, 1, 2, 232, 0 },

  { 117,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevSca_pl), 85, 1, 2, 234, 0 },

  { 118,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScal_f), 85, 1, 2, 236, 0 },

  { 119,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScal_o), 85, 1, 2, 238, 0 },

  { 120,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScal_n), 85, 1, 2, 240, 0 },

  { 121, "ctrl_tapm/IMU/Filtering/Out1/InitialOutput", offsetof(P_ctrl_TAPM_T,
    Out1_Y0), 0, 1, 2, 242, 0 },

  { 122, "ctrl_tapm/IMU/Filtering/KalmanFilter3/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition), 30, 144, 2, 244, 0 },

  { 123, "ctrl_tapm/IMU/Filtering/KalmanFilter3/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value), 32, 72, 2, 246, 0 },

  { 124, "ctrl_tapm/IMU/Filtering/KalmanFilter3/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value), 33, 36, 2, 248, 0 },

  { 125, "ctrl_tapm/IMU/Filtering/KalmanFilter3/Delay1/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay1_InitialCondition), 51, 12, 2, 250, 0 },

  { 126, "ctrl_tapm/IMU/Filtering/KalmanFilter3/H/Gain", offsetof(P_ctrl_TAPM_T,
    H_Gain), 32, 72, 2, 252, 0 },

  { 127, "ctrl_tapm/IMU/Filtering/Outliner cleaner/Memory2/X0", offsetof
    (P_ctrl_TAPM_T, Memory2_X0), 52, 5, 2, 254, 0 },

  { 128, "ctrl_tapm/IMU/Filtering/Outliner cleaner/Gain/Gain", offsetof
    (P_ctrl_TAPM_T, Gain_Gain), 85, 1, 2, 256, 0 },

  { 129, "ctrl_tapm/IMU/Filtering/Outliner cleaner/Memory3/X0", offsetof
    (P_ctrl_TAPM_T, Memory3_X0), 53, 7, 2, 258, 0 },

  { 130, "ctrl_tapm/IMU/Filtering/KalmanFilter/Delay/InitialCondition", offsetof
    (P_ctrl_TAPM_T, Delay_InitialCondition_g), 30, 144, 2, 260, 0 },

  { 131, "ctrl_tapm/IMU/Filtering/KalmanFilter/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_p), 32, 72, 2, 262, 0 },

  { 132, "ctrl_tapm/IMU/Filtering/KalmanFilter/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_e), 33, 36, 2, 264, 0 },

  { 133, "ctrl_tapm/IMU/Filtering/KalmanFilter/Delay1/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay1_InitialCondition_h), 51, 12, 2, 266, 0 },

  { 134, "ctrl_tapm/IMU/Filtering/KalmanFilter/H/Gain", offsetof(P_ctrl_TAPM_T,
    H_Gain_i), 32, 72, 2, 268, 0 },

  { 135, "ctrl_tapm/IMU/Filtering/Outliner cleaner1/Memory2/X0", offsetof
    (P_ctrl_TAPM_T, Memory2_X0_d), 52, 5, 2, 270, 0 },

  { 136, "ctrl_tapm/IMU/Filtering/Outliner cleaner1/Gain/Gain", offsetof
    (P_ctrl_TAPM_T, Gain_Gain_c), 85, 1, 2, 272, 0 },

  { 137, "ctrl_tapm/IMU/Filtering/Outliner cleaner1/Memory3/X0", offsetof
    (P_ctrl_TAPM_T, Memory3_X0_o), 53, 7, 2, 274, 0 },

  { 138, "ctrl_tapm/IMU/Filtering/KalmanFilter1/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_p), 30, 144, 2, 276, 0 },

  { 139, "ctrl_tapm/IMU/Filtering/KalmanFilter1/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_f), 32, 72, 2, 278, 0 },

  { 140, "ctrl_tapm/IMU/Filtering/KalmanFilter1/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_f), 33, 36, 2, 280, 0 },

  { 141, "ctrl_tapm/IMU/Filtering/KalmanFilter1/Delay1/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay1_InitialCondition_b), 51, 12, 2, 282, 0 },

  { 142, "ctrl_tapm/IMU/Filtering/KalmanFilter1/H/Gain", offsetof(P_ctrl_TAPM_T,
    H_Gain_b), 32, 72, 2, 284, 0 },

  { 143, "ctrl_tapm/IMU/Filtering/Outliner cleaner2/Memory2/X0", offsetof
    (P_ctrl_TAPM_T, Memory2_X0_d5), 52, 5, 2, 286, 0 },

  { 144, "ctrl_tapm/IMU/Filtering/Outliner cleaner2/Gain/Gain", offsetof
    (P_ctrl_TAPM_T, Gain_Gain_j), 85, 1, 2, 288, 0 },

  { 145, "ctrl_tapm/IMU/Filtering/Outliner cleaner2/Memory3/X0", offsetof
    (P_ctrl_TAPM_T, Memory3_X0_d), 53, 7, 2, 290, 0 },

  { 146, "ctrl_tapm/IMU/Filtering/KalmanFilter2/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_d), 30, 144, 2, 292, 0 },

  { 147, "ctrl_tapm/IMU/Filtering/KalmanFilter2/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_k), 32, 72, 2, 294, 0 },

  { 148, "ctrl_tapm/IMU/Filtering/KalmanFilter2/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_g), 33, 36, 2, 296, 0 },

  { 149, "ctrl_tapm/IMU/Filtering/KalmanFilter2/Delay1/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay1_InitialCondition_e), 51, 12, 2, 298, 0 },

  { 150, "ctrl_tapm/IMU/Filtering/KalmanFilter2/H/Gain", offsetof(P_ctrl_TAPM_T,
    H_Gain_p), 32, 72, 2, 300, 0 },

  { 151, "ctrl_tapm/IMU/Filtering/Outliner cleaner3/Memory2/X0", offsetof
    (P_ctrl_TAPM_T, Memory2_X0_p), 52, 5, 2, 302, 0 },

  { 152, "ctrl_tapm/IMU/Filtering/Outliner cleaner3/Gain/Gain", offsetof
    (P_ctrl_TAPM_T, Gain_Gain_k), 85, 1, 2, 304, 0 },

  { 153, "ctrl_tapm/IMU/Filtering/Outliner cleaner3/Memory3/X0", offsetof
    (P_ctrl_TAPM_T, Memory3_X0_p), 53, 7, 2, 306, 0 },

  { 154, "ctrl_tapm/IMU/Filtering/KalmanFilter/A/Gain", offsetof(P_ctrl_TAPM_T,
    A_Gain), 30, 144, 2, 308, 0 },

  { 155, "ctrl_tapm/IMU/Filtering/KalmanFilter/Constant6/Value", offsetof
    (P_ctrl_TAPM_T, Constant6_Value), 30, 144, 2, 310, 0 },

  { 156, "ctrl_tapm/IMU/Filtering/KalmanFilter/Identity/Value", offsetof
    (P_ctrl_TAPM_T, Identity_Value), 30, 144, 2, 312, 0 },

  { 157, "ctrl_tapm/IMU/Filtering/KalmanFilter/Constant3/Value", offsetof
    (P_ctrl_TAPM_T, Constant3_Value), 32, 72, 2, 314, 0 },

  { 158, "ctrl_tapm/IMU/Filtering/KalmanFilter/Constant4/Value", offsetof
    (P_ctrl_TAPM_T, Constant4_Value), 33, 36, 2, 316, 0 },

  { 159, "ctrl_tapm/IMU/Filtering/KalmanFilter/Constant5/Value", offsetof
    (P_ctrl_TAPM_T, Constant5_Value), 30, 144, 2, 318, 0 },

  { 160, "ctrl_tapm/IMU/Filtering/KalmanFilter1/A/Gain", offsetof(P_ctrl_TAPM_T,
    A_Gain_n), 30, 144, 2, 320, 0 },

  { 161, "ctrl_tapm/IMU/Filtering/KalmanFilter1/Constant6/Value", offsetof
    (P_ctrl_TAPM_T, Constant6_Value_c), 30, 144, 2, 322, 0 },

  { 162, "ctrl_tapm/IMU/Filtering/KalmanFilter1/Identity/Value", offsetof
    (P_ctrl_TAPM_T, Identity_Value_h), 30, 144, 2, 324, 0 },

  { 163, "ctrl_tapm/IMU/Filtering/KalmanFilter1/Constant3/Value", offsetof
    (P_ctrl_TAPM_T, Constant3_Value_j), 32, 72, 2, 326, 0 },

  { 164, "ctrl_tapm/IMU/Filtering/KalmanFilter1/Constant4/Value", offsetof
    (P_ctrl_TAPM_T, Constant4_Value_k), 33, 36, 2, 328, 0 },

  { 165, "ctrl_tapm/IMU/Filtering/KalmanFilter1/Constant5/Value", offsetof
    (P_ctrl_TAPM_T, Constant5_Value_n), 30, 144, 2, 330, 0 },

  { 166, "ctrl_tapm/IMU/Filtering/KalmanFilter2/A/Gain", offsetof(P_ctrl_TAPM_T,
    A_Gain_k), 30, 144, 2, 332, 0 },

  { 167, "ctrl_tapm/IMU/Filtering/KalmanFilter2/Constant6/Value", offsetof
    (P_ctrl_TAPM_T, Constant6_Value_a), 30, 144, 2, 334, 0 },

  { 168, "ctrl_tapm/IMU/Filtering/KalmanFilter2/Identity/Value", offsetof
    (P_ctrl_TAPM_T, Identity_Value_f), 30, 144, 2, 336, 0 },

  { 169, "ctrl_tapm/IMU/Filtering/KalmanFilter2/Constant3/Value", offsetof
    (P_ctrl_TAPM_T, Constant3_Value_o), 32, 72, 2, 338, 0 },

  { 170, "ctrl_tapm/IMU/Filtering/KalmanFilter2/Constant4/Value", offsetof
    (P_ctrl_TAPM_T, Constant4_Value_i), 33, 36, 2, 340, 0 },

  { 171, "ctrl_tapm/IMU/Filtering/KalmanFilter2/Constant5/Value", offsetof
    (P_ctrl_TAPM_T, Constant5_Value_m), 30, 144, 2, 342, 0 },

  { 172, "ctrl_tapm/IMU/Filtering/KalmanFilter3/A/Gain", offsetof(P_ctrl_TAPM_T,
    A_Gain_j), 30, 144, 2, 344, 0 },

  { 173, "ctrl_tapm/IMU/Filtering/KalmanFilter3/Constant6/Value", offsetof
    (P_ctrl_TAPM_T, Constant6_Value_j), 30, 144, 2, 346, 0 },

  { 174, "ctrl_tapm/IMU/Filtering/KalmanFilter3/Identity/Value", offsetof
    (P_ctrl_TAPM_T, Identity_Value_h4), 30, 144, 2, 348, 0 },

  { 175, "ctrl_tapm/IMU/Filtering/KalmanFilter3/Constant3/Value", offsetof
    (P_ctrl_TAPM_T, Constant3_Value_b), 32, 72, 2, 350, 0 },

  { 176, "ctrl_tapm/IMU/Filtering/KalmanFilter3/Constant4/Value", offsetof
    (P_ctrl_TAPM_T, Constant4_Value_iu), 33, 36, 2, 352, 0 },

  { 177, "ctrl_tapm/IMU/Filtering/KalmanFilter3/Constant5/Value", offsetof
    (P_ctrl_TAPM_T, Constant5_Value_nj), 30, 144, 2, 354, 0 },

  { 178,
    "ctrl_tapm/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_UpperSat), 85, 1, 2, 356, 0 },

  { 179,
    "ctrl_tapm/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_LowerSat), 85, 1, 2, 358, 0 },

  { 180, "ctrl_tapm/Control/DP Controller/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain_p), 85, 1, 2, 360, 0 },

  { 181,
    "ctrl_tapm/Control/DP Controller/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_TAPM_T, Constant_Value_i), 85, 1, 2, 362, 0 },

  { 182, "ctrl_tapm/Input1/Observer Gains/Constant6/Value", offsetof
    (P_ctrl_TAPM_T, Constant6_Value_m), 85, 1, 2, 364, 0 },

  { 183, "ctrl_tapm/Input1/Observer Gains/Constant7/Value", offsetof
    (P_ctrl_TAPM_T, Constant7_Value), 85, 1, 2, 366, 0 },

  { 184, "ctrl_tapm/Input1/Observer Gains/Constant8/Value", offsetof
    (P_ctrl_TAPM_T, Constant8_Value), 85, 1, 2, 368, 0 },

  { 185,
    "ctrl_tapm/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_UpperSat_p), 85, 1, 2, 370, 0 },

  { 186,
    "ctrl_tapm/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_LowerSat_a), 85, 1, 2, 372, 0 },

  { 187, "ctrl_tapm/Guidance/Reference model/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain_a), 85, 1, 2, 374, 0 },

  { 188,
    "ctrl_tapm/Guidance/Reference model/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_TAPM_T, Constant_Value_j), 85, 1, 2, 376, 0 },

  { 189,
    "ctrl_tapm/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_UpperSat_d), 85, 1, 2, 378, 0 },

  { 190,
    "ctrl_tapm/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_LowerSat_c), 85, 1, 2, 380, 0 },

  { 191, "ctrl_tapm/Control/DP Controller/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain_ag), 85, 1, 2, 382, 0 },

  { 192, "ctrl_tapm/Control/DP Controller/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_TAPM_T, Constant_Value_l), 85, 1, 2, 384, 0 },

  { 193, "ctrl_tapm/Control/DP Controller/Integrator/InitialCondition", offsetof
    (P_ctrl_TAPM_T, Integrator_IC), 85, 1, 2, 386, 0 },

  { 194, "ctrl_tapm/Nonlinear Passisve Observer/Integrator1/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator1_IC), 21, 3, 2, 388, 0 },

  { 195, "ctrl_tapm/Guidance/Reference model/Integrator3/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator3_IC), 85, 1, 2, 390, 0 },

  { 196, "ctrl_tapm/Thrust allocation/Radians to Degrees/Gain/Gain", offsetof
    (P_ctrl_TAPM_T, Gain_Gain_o), 85, 1, 2, 392, 0 },

  { 197, "ctrl_tapm/Thrust allocation/X-position Thruster/Value", offsetof
    (P_ctrl_TAPM_T, XpositionThruster_Value), 50, 6, 2, 394, 0 },

  { 198, "ctrl_tapm/Thrust allocation/Y-position Thruster/Value", offsetof
    (P_ctrl_TAPM_T, YpositionThruster_Value), 50, 6, 2, 396, 0 },

  { 199, "ctrl_tapm/Thrust allocation/constant angle/Value", offsetof
    (P_ctrl_TAPM_T, constantangle_Value), 50, 6, 2, 398, 0 },

  { 200, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/Threshold",
    offsetof(P_ctrl_TAPM_T, ChoosingFixedAzimuthangle_Thres), 85, 1, 2, 400, 0 },

  { 201, "ctrl_tapm/Thruster control /Subsystem1/Saturation 1/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation1_UpperSat), 85, 1, 2, 402, 0 },

  { 202, "ctrl_tapm/Thruster control /Subsystem1/Saturation 1/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation1_LowerSat), 85, 1, 2, 404, 0 },

  { 203,
    "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_f), 85, 1, 2, 406, 0 },

  { 204, "ctrl_tapm/Thruster control /Thruster 1/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value), 85, 1, 2, 408, 0 },

  { 205,
    "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_fg), 85, 1, 2, 410, 0 },

  { 206, "ctrl_tapm/Thruster control /Thruster 2/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_k), 85, 1, 2, 412, 0 },

  { 207,
    "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_p), 85, 1, 2, 414, 0 },

  { 208, "ctrl_tapm/Thruster control /Thruster 3/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_n), 85, 1, 2, 416, 0 },

  { 209,
    "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_fv), 85, 1, 2, 418, 0 },

  { 210, "ctrl_tapm/Thruster control /Thruster 4/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_d), 85, 1, 2, 420, 0 },

  { 211,
    "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_l), 85, 1, 2, 422, 0 },

  { 212, "ctrl_tapm/Thruster control /Thruster 5/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_f), 85, 1, 2, 424, 0 },

  { 213,
    "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_li), 85, 1, 2, 426, 0 },

  { 214, "ctrl_tapm/Thruster control /Thruster 6/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_h), 85, 1, 2, 428, 0 },

  { 215,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain_d), 85, 1, 2, 430, 0 },

  { 216,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Gain1/Gain",
    offsetof(P_ctrl_TAPM_T, Gain1_Gain), 85, 1, 2, 432, 0 },

  { 217,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Gain2/Gain",
    offsetof(P_ctrl_TAPM_T, Gain2_Gain), 85, 1, 2, 434, 0 },

  { 218,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Gain3/Gain",
    offsetof(P_ctrl_TAPM_T, Gain3_Gain), 85, 1, 2, 436, 0 },

  { 219,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Gain4/Gain",
    offsetof(P_ctrl_TAPM_T, Gain4_Gain), 85, 1, 2, 438, 0 },

  { 220,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Gain5/Gain",
    offsetof(P_ctrl_TAPM_T, Gain5_Gain), 85, 1, 2, 440, 0 },

  { 221,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 8/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation8_LowerSat), 85, 1, 2, 442, 0 },

  { 222,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 9/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation9_UpperSat), 85, 1, 2, 444, 0 },

  { 223,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 10/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation10_LowerSat), 85, 1, 2, 446, 0 },

  { 224,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 11/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation11_UpperSat), 85, 1, 2, 448, 0 },

  { 225,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 3/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation3_LowerSat), 85, 1, 2, 450, 0 },

  { 226,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 4/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation4_UpperSat), 85, 1, 2, 452, 0 },

  { 227,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 5/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation5_LowerSat), 85, 1, 2, 454, 0 },

  { 228,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 6/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation6_UpperSat), 85, 1, 2, 456, 0 },

  { 229, "ctrl_tapm/Thruster control /Subsystem1/Saturation 2/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation2_UpperSat), 85, 1, 2, 458, 0 },

  { 230, "ctrl_tapm/Thruster control /Subsystem1/Saturation 2/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation2_LowerSat), 85, 1, 2, 460, 0 },

  { 231,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 12/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation12_LowerSat), 85, 1, 2, 462, 0 },

  { 232,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 13/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation13_UpperSat), 85, 1, 2, 464, 0 },

  { 233, "ctrl_tapm/Thruster control /Subsystem1/Saturation 3/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation3_UpperSat), 85, 1, 2, 466, 0 },

  { 234, "ctrl_tapm/Thruster control /Subsystem1/Saturation 3/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation3_LowerSat_f), 85, 1, 2, 468, 0 },

  { 235, "ctrl_tapm/Thruster control /Subsystem1/Saturation 4/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation4_UpperSat_p), 85, 1, 2, 470, 0 },

  { 236, "ctrl_tapm/Thruster control /Subsystem1/Saturation 4/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation4_LowerSat), 85, 1, 2, 472, 0 },

  { 237, "ctrl_tapm/Thruster control /Subsystem1/Saturation 5/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation5_UpperSat), 85, 1, 2, 474, 0 },

  { 238, "ctrl_tapm/Thruster control /Subsystem1/Saturation 5/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation5_LowerSat_h), 85, 1, 2, 476, 0 },

  { 239, "ctrl_tapm/Thruster control /Subsystem1/Saturation 6/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation6_UpperSat_g), 85, 1, 2, 478, 0 },

  { 240, "ctrl_tapm/Thruster control /Subsystem1/Saturation 6/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation6_LowerSat), 85, 1, 2, 480, 0 },

  { 241,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 1/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation1_LowerSat_h), 85, 1, 2, 482, 0 },

  { 242,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 2/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation2_UpperSat_p), 85, 1, 2, 484, 0 },

  { 243,
    "ctrl_tapm/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_UpperSat_i), 85, 1, 2, 486, 0 },

  { 244,
    "ctrl_tapm/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_LowerSat_o), 85, 1, 2, 488, 0 },

  { 245,
    "ctrl_tapm/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain_pg), 85, 1, 2, 490, 0 },

  { 246,
    "ctrl_tapm/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_TAPM_T, Constant_Value_kq), 85, 1, 2, 492, 0 },

  { 247,
    "ctrl_tapm/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_UpperSat_e), 85, 1, 2, 494, 0 },

  { 248,
    "ctrl_tapm/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_LowerSat_g), 85, 1, 2, 496, 0 },

  { 249,
    "ctrl_tapm/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain_f), 85, 1, 2, 498, 0 },

  { 250,
    "ctrl_tapm/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_TAPM_T, Constant_Value_p0), 85, 1, 2, 500, 0 },

  { 251, "ctrl_tapm/Nonlinear Passisve Observer/Integrator2/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator2_IC), 21, 3, 2, 502, 0 },

  { 252, "ctrl_tapm/Nonlinear Passisve Observer/M^-1/Gain", offsetof
    (P_ctrl_TAPM_T, M1_Gain), 23, 9, 2, 504, 0 },

  { 253, "ctrl_tapm/Radians to Degrees/Gain/Gain", offsetof(P_ctrl_TAPM_T,
    Gain_Gain_f0), 85, 1, 2, 506, 0 },

  { 254, "ctrl_tapm/X-position Thruster/Value", offsetof(P_ctrl_TAPM_T,
    XpositionThruster_Value_e), 50, 6, 2, 508, 0 },

  { 255, "ctrl_tapm/Y-position Thruster/Value", offsetof(P_ctrl_TAPM_T,
    YpositionThruster_Value_o), 50, 6, 2, 510, 0 },

  { 256, "ctrl_tapm/Guidance/Reference model/Integrator2/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator2_IC_p), 85, 1, 2, 512, 0 },

  { 257, "ctrl_tapm/Input1/Observer Gains/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_c), 85, 1, 2, 514, 0 },

  { 258, "ctrl_tapm/Input1/Observer Gains/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_p), 85, 1, 2, 516, 0 },

  { 259, "ctrl_tapm/Input1/Observer Gains/Constant2/Value", offsetof
    (P_ctrl_TAPM_T, Constant2_Value), 85, 1, 2, 518, 0 },

  { 260, "ctrl_tapm/Input1/Observer Gains/Constant3/Value", offsetof
    (P_ctrl_TAPM_T, Constant3_Value_f), 85, 1, 2, 520, 0 },

  { 261, "ctrl_tapm/Input1/Observer Gains/Constant4/Value", offsetof
    (P_ctrl_TAPM_T, Constant4_Value_a), 85, 1, 2, 522, 0 },

  { 262, "ctrl_tapm/Input1/Observer Gains/Constant5/Value", offsetof
    (P_ctrl_TAPM_T, Constant5_Value_j), 85, 1, 2, 524, 0 },

  { 263, "ctrl_tapm/Thruster control /Delay/InitialCondition", offsetof
    (P_ctrl_TAPM_T, Delay_InitialCondition_j), 85, 1, 2, 526, 0 },

  { 264, "ctrl_tapm/Thruster control /Thruster 1/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_cs), 54, 2, 2, 528, 0 },

  { 265, "ctrl_tapm/Thruster control /Thruster 1/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_k), 54, 2, 2, 530, 0 },

  { 266, "ctrl_tapm/Thruster control /Thruster 1/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_i), 85, 1, 2, 532, 0 },

  { 267,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_f), 85, 1, 2, 534, 0 },

  { 268,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_o), 45, 3, 2, 536, 0 },

  { 269,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_b), 45, 3, 2, 538, 0 },

  { 270,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialStat), 85, 1, 2, 540, 0 },

  { 271,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt), 0, 1, 2, 542, 0 },

  { 272,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_RisingLim), 0, 1, 2, 544, 0 },

  { 273,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_FallingLim), 0, 1, 2, 546, 0 },

  { 274,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_IC), 85, 1, 2, 548, 0 },

  { 275, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0), 85, 1, 2, 550, 0 },

  { 276,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_a), 85, 1, 2, 552, 0 },

  { 277, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value), 85, 1, 2, 554, 0 },

  { 278,
    "ctrl_tapm/Thruster control /Thruster 1/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_h), 85, 1, 2, 556, 0 },

  { 279, "ctrl_tapm/Thruster control /Thruster 2/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_h), 54, 2, 2, 558, 0 },

  { 280, "ctrl_tapm/Thruster control /Thruster 2/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_j), 54, 2, 2, 560, 0 },

  { 281, "ctrl_tapm/Thruster control /Thruster 2/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_l), 85, 1, 2, 562, 0 },

  { 282,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_iv), 85, 1, 2, 564, 0 },

  { 283,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_b), 45, 3, 2, 566, 0 },

  { 284,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_i), 45, 3, 2, 568, 0 },

  { 285,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialS_hu), 85, 1, 2, 570, 0 },

  { 286,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_k), 0, 1, 2, 572, 0 },

  { 287,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_RisingLim_n), 0, 1, 2, 574, 0 },

  { 288,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_FallingLim_n), 0, 1, 2, 576, 0 },

  { 289,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_IC_m), 85, 1, 2, 578, 0 },

  { 290, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_e), 85, 1, 2, 580, 0 },

  { 291,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_fy), 85, 1, 2, 582, 0 },

  { 292, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_l), 85, 1, 2, 584, 0 },

  { 293,
    "ctrl_tapm/Thruster control /Thruster 2/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_f), 85, 1, 2, 586, 0 },

  { 294, "ctrl_tapm/Thruster control /Thruster 3/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_n), 54, 2, 2, 588, 0 },

  { 295, "ctrl_tapm/Thruster control /Thruster 3/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_a), 54, 2, 2, 590, 0 },

  { 296, "ctrl_tapm/Thruster control /Thruster 3/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_dp), 85, 1, 2, 592, 0 },

  { 297,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_h), 85, 1, 2, 594, 0 },

  { 298,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_gf), 45, 3, 2, 596, 0 },

  { 299,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_h), 45, 3, 2, 598, 0 },

  { 300,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_a), 85, 1, 2, 600, 0 },

  { 301,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_m), 0, 1, 2, 602, 0 },

  { 302,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_RisingLim), 0, 1, 2, 604, 0 },

  { 303,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_FallingLim), 0, 1, 2, 606, 0 },

  { 304,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_IC), 85, 1, 2, 608, 0 },

  { 305, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_g), 85, 1, 2, 610, 0 },

  { 306,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_j), 85, 1, 2, 612, 0 },

  { 307, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_g), 85, 1, 2, 614, 0 },

  { 308,
    "ctrl_tapm/Thruster control /Thruster 3/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_c), 85, 1, 2, 616, 0 },

  { 309, "ctrl_tapm/Thruster control /Thruster 4/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_j4), 54, 2, 2, 618, 0 },

  { 310, "ctrl_tapm/Thruster control /Thruster 4/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_oi), 54, 2, 2, 620, 0 },

  { 311, "ctrl_tapm/Thruster control /Thruster 4/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_fb), 85, 1, 2, 622, 0 },

  { 312,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_gg), 85, 1, 2, 624, 0 },

  { 313,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_m), 45, 3, 2, 626, 0 },

  { 314,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_l), 45, 3, 2, 628, 0 },

  { 315,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialS_a1), 85, 1, 2, 630, 0 },

  { 316,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_h), 0, 1, 2, 632, 0 },

  { 317,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_RisingLim_e), 0, 1, 2, 634, 0 },

  { 318,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_FallingLi_b), 0, 1, 2, 636, 0 },

  { 319,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_IC_h), 85, 1, 2, 638, 0 },

  { 320, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_k), 85, 1, 2, 640, 0 },

  { 321,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_g), 85, 1, 2, 642, 0 },

  { 322, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_p), 85, 1, 2, 644, 0 },

  { 323,
    "ctrl_tapm/Thruster control /Thruster 4/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_p), 85, 1, 2, 646, 0 },

  { 324, "ctrl_tapm/Thruster control /Thruster 5/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_ib), 54, 2, 2, 648, 0 },

  { 325, "ctrl_tapm/Thruster control /Thruster 5/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_h), 54, 2, 2, 650, 0 },

  { 326, "ctrl_tapm/Thruster control /Thruster 5/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_fv), 85, 1, 2, 652, 0 },

  { 327,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_dz), 85, 1, 2, 654, 0 },

  { 328,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_mk), 45, 3, 2, 656, 0 },

  { 329,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_p), 45, 3, 2, 658, 0 },

  { 330,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_e), 85, 1, 2, 660, 0 },

  { 331,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_o), 0, 1, 2, 662, 0 },

  { 332,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_RisingLim_b), 0, 1, 2, 664, 0 },

  { 333,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_FallingLi_d), 0, 1, 2, 666, 0 },

  { 334,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_IC_i), 85, 1, 2, 668, 0 },

  { 335, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_k3), 85, 1, 2, 670, 0 },

  { 336,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_aj), 85, 1, 2, 672, 0 },

  { 337, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_lq), 85, 1, 2, 674, 0 },

  { 338,
    "ctrl_tapm/Thruster control /Thruster 5/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialS_pj), 85, 1, 2, 676, 0 },

  { 339, "ctrl_tapm/Thruster control /Thruster 6/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_ht), 54, 2, 2, 678, 0 },

  { 340, "ctrl_tapm/Thruster control /Thruster 6/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_gs), 54, 2, 2, 680, 0 },

  { 341, "ctrl_tapm/Thruster control /Thruster 6/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_fi), 85, 1, 2, 682, 0 },

  { 342,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_a), 85, 1, 2, 684, 0 },

  { 343,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_oa), 45, 3, 2, 686, 0 },

  { 344,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_p3), 45, 3, 2, 688, 0 },

  { 345,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialS_a4), 85, 1, 2, 690, 0 },

  { 346,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_kk), 0, 1, 2, 692, 0 },

  { 347,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_RisingLi_bi), 0, 1, 2, 694, 0 },

  { 348,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_FallingLi_p), 0, 1, 2, 696, 0 },

  { 349,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_IC_p), 85, 1, 2, 698, 0 },

  { 350, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_c), 85, 1, 2, 700, 0 },

  { 351,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_h), 85, 1, 2, 702, 0 },

  { 352, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_j), 85, 1, 2, 704, 0 },

  { 353,
    "ctrl_tapm/Thruster control /Thruster 6/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_b), 85, 1, 2, 706, 0 },

  { 354, "ctrl_tapm/IMU/Memory/X0", offsetof(P_ctrl_TAPM_T, Memory_X0_f), 55, 28,
    2, 708, 0 },

  { 355, "ctrl_tapm/IMU/Filtering/KalmanFilter3/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength), 86, 1, 2, 710, 0 },

  { 356, "ctrl_tapm/IMU/Filtering/KalmanFilter3/Delay1/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay1_DelayLength), 86, 1, 2, 712, 0 },

  { 357, "ctrl_tapm/IMU/Filtering/KalmanFilter/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_h), 86, 1, 2, 714, 0 },

  { 358, "ctrl_tapm/IMU/Filtering/KalmanFilter/Delay1/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay1_DelayLength_h), 86, 1, 2, 716, 0 },

  { 359, "ctrl_tapm/IMU/Filtering/KalmanFilter1/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_n), 86, 1, 2, 718, 0 },

  { 360, "ctrl_tapm/IMU/Filtering/KalmanFilter1/Delay1/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay1_DelayLength_i), 86, 1, 2, 720, 0 },

  { 361, "ctrl_tapm/IMU/Filtering/KalmanFilter2/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_i), 86, 1, 2, 722, 0 },

  { 362, "ctrl_tapm/IMU/Filtering/KalmanFilter2/Delay1/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay1_DelayLength_m), 86, 1, 2, 724, 0 },

  { 363, "ctrl_tapm/Thruster control /Delay/DelayLength", offsetof(P_ctrl_TAPM_T,
    Delay_DelayLength_m), 86, 1, 2, 726, 0 },

  { 364, "ctrl_tapm/Thruster control /Thruster 1/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_d), 86, 1, 2, 728, 0 },

  { 365,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_f), 86, 1, 2, 730, 0 },

  { 366, "ctrl_tapm/Thruster control /Thruster 2/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_m5), 86, 1, 2, 732, 0 },

  { 367,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_p), 86, 1, 2, 734, 0 },

  { 368, "ctrl_tapm/Thruster control /Thruster 3/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_hc), 86, 1, 2, 736, 0 },

  { 369,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_b), 86, 1, 2, 738, 0 },

  { 370, "ctrl_tapm/Thruster control /Thruster 4/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_nv), 86, 1, 2, 740, 0 },

  { 371,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_mj), 86, 1, 2, 742, 0 },

  { 372, "ctrl_tapm/Thruster control /Thruster 5/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_a), 86, 1, 2, 744, 0 },

  { 373,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_k), 86, 1, 2, 746, 0 },

  { 374, "ctrl_tapm/Thruster control /Thruster 6/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_l), 86, 1, 2, 748, 0 },

  { 375,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_c), 86, 1, 2, 750, 0 },

  { 376,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_TAPM_T, CoreSubsys.DiscreteTimeIntegrator_gainval), 0, 1, 2,
    752, 0 },

  { 377,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Degrees to Radians/Gain1/Gain",
    offsetof(P_ctrl_TAPM_T, CoreSubsys.Gain1_Gain), 85, 1, 2, 754, 0 },

  { 378,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, CoreSubsys.Delay_InitialCondition), 85, 1, 2, 756, 0
  },

  { 379,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, CoreSubsys.Delay_DelayLength), 86, 1, 2, 758, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 380;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  6, 4,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
  1, 1,                                /* Parameter at index 36 */
  1, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
  1, 1,                                /* Parameter at index 39 */
  1, 1,                                /* Parameter at index 40 */
  1, 1,                                /* Parameter at index 41 */
  1, 1,                                /* Parameter at index 42 */
  1, 1,                                /* Parameter at index 43 */
  1, 1,                                /* Parameter at index 44 */
  1, 1,                                /* Parameter at index 45 */
  1, 1,                                /* Parameter at index 46 */
  1, 1,                                /* Parameter at index 47 */
  1, 1,                                /* Parameter at index 48 */
  1, 1,                                /* Parameter at index 49 */
  1, 1,                                /* Parameter at index 50 */
  1, 1,                                /* Parameter at index 51 */
  1, 1,                                /* Parameter at index 52 */
  1, 1,                                /* Parameter at index 53 */
  1, 1,                                /* Parameter at index 54 */
  1, 1,                                /* Parameter at index 55 */
  1, 1,                                /* Parameter at index 56 */
  1, 1,                                /* Parameter at index 57 */
  1, 1,                                /* Parameter at index 58 */
  1, 1,                                /* Parameter at index 59 */
  1, 1,                                /* Parameter at index 60 */
  1, 1,                                /* Parameter at index 61 */
  1, 1,                                /* Parameter at index 62 */
  1, 1,                                /* Parameter at index 63 */
  1, 1,                                /* Parameter at index 64 */
  1, 1,                                /* Parameter at index 65 */
  1, 1,                                /* Parameter at index 66 */
  1, 1,                                /* Parameter at index 67 */
  1, 1,                                /* Parameter at index 68 */
  1, 1,                                /* Parameter at index 69 */
  1, 1,                                /* Parameter at index 70 */
  1, 1,                                /* Parameter at index 71 */
  1, 1,                                /* Parameter at index 72 */
  1, 1,                                /* Parameter at index 73 */
  1, 1,                                /* Parameter at index 74 */
  1, 1,                                /* Parameter at index 75 */
  1, 1,                                /* Parameter at index 76 */
  1, 1,                                /* Parameter at index 77 */
  1, 1,                                /* Parameter at index 78 */
  1, 1,                                /* Parameter at index 79 */
  1, 1,                                /* Parameter at index 80 */
  1, 1,                                /* Parameter at index 81 */
  1, 1,                                /* Parameter at index 82 */
  1, 1,                                /* Parameter at index 83 */
  1, 1,                                /* Parameter at index 84 */
  1, 1,                                /* Parameter at index 85 */
  1, 1,                                /* Parameter at index 86 */
  1, 1,                                /* Parameter at index 87 */
  1, 1,                                /* Parameter at index 88 */
  1, 1,                                /* Parameter at index 89 */
  1, 1,                                /* Parameter at index 90 */
  1, 1,                                /* Parameter at index 91 */
  1, 1,                                /* Parameter at index 92 */
  1, 1,                                /* Parameter at index 93 */
  1, 1,                                /* Parameter at index 94 */
  1, 1,                                /* Parameter at index 95 */
  1, 1,                                /* Parameter at index 96 */
  1, 1,                                /* Parameter at index 97 */
  1, 1,                                /* Parameter at index 98 */
  1, 1,                                /* Parameter at index 99 */
  1, 1,                                /* Parameter at index 100 */
  1, 1,                                /* Parameter at index 101 */
  1, 6,                                /* Parameter at index 102 */
  1, 6,                                /* Parameter at index 103 */
  1, 6,                                /* Parameter at index 104 */
  1, 6,                                /* Parameter at index 105 */
  1, 6,                                /* Parameter at index 106 */
  1, 6,                                /* Parameter at index 107 */
  1, 6,                                /* Parameter at index 108 */
  1, 6,                                /* Parameter at index 109 */
  1, 6,                                /* Parameter at index 110 */
  1, 6,                                /* Parameter at index 111 */
  1, 6,                                /* Parameter at index 112 */
  1, 6,                                /* Parameter at index 113 */
  1, 1,                                /* Parameter at index 114 */
  1, 1,                                /* Parameter at index 115 */
  1, 1,                                /* Parameter at index 116 */
  1, 1,                                /* Parameter at index 117 */
  1, 1,                                /* Parameter at index 118 */
  1, 1,                                /* Parameter at index 119 */
  1, 1,                                /* Parameter at index 120 */
  1, 1,                                /* Parameter at index 121 */
  12, 12,                              /* Parameter at index 122 */
  6, 12,                               /* Parameter at index 123 */
  6, 6,                                /* Parameter at index 124 */
  1, 12,                               /* Parameter at index 125 */
  6, 12,                               /* Parameter at index 126 */
  1, 5,                                /* Parameter at index 127 */
  1, 1,                                /* Parameter at index 128 */
  1, 7,                                /* Parameter at index 129 */
  12, 12,                              /* Parameter at index 130 */
  6, 12,                               /* Parameter at index 131 */
  6, 6,                                /* Parameter at index 132 */
  1, 12,                               /* Parameter at index 133 */
  6, 12,                               /* Parameter at index 134 */
  1, 5,                                /* Parameter at index 135 */
  1, 1,                                /* Parameter at index 136 */
  1, 7,                                /* Parameter at index 137 */
  12, 12,                              /* Parameter at index 138 */
  6, 12,                               /* Parameter at index 139 */
  6, 6,                                /* Parameter at index 140 */
  1, 12,                               /* Parameter at index 141 */
  6, 12,                               /* Parameter at index 142 */
  1, 5,                                /* Parameter at index 143 */
  1, 1,                                /* Parameter at index 144 */
  1, 7,                                /* Parameter at index 145 */
  12, 12,                              /* Parameter at index 146 */
  6, 12,                               /* Parameter at index 147 */
  6, 6,                                /* Parameter at index 148 */
  1, 12,                               /* Parameter at index 149 */
  6, 12,                               /* Parameter at index 150 */
  1, 5,                                /* Parameter at index 151 */
  1, 1,                                /* Parameter at index 152 */
  1, 7,                                /* Parameter at index 153 */
  12, 12,                              /* Parameter at index 154 */
  12, 12,                              /* Parameter at index 155 */
  12, 12,                              /* Parameter at index 156 */
  6, 12,                               /* Parameter at index 157 */
  6, 6,                                /* Parameter at index 158 */
  12, 12,                              /* Parameter at index 159 */
  12, 12,                              /* Parameter at index 160 */
  12, 12,                              /* Parameter at index 161 */
  12, 12,                              /* Parameter at index 162 */
  6, 12,                               /* Parameter at index 163 */
  6, 6,                                /* Parameter at index 164 */
  12, 12,                              /* Parameter at index 165 */
  12, 12,                              /* Parameter at index 166 */
  12, 12,                              /* Parameter at index 167 */
  12, 12,                              /* Parameter at index 168 */
  6, 12,                               /* Parameter at index 169 */
  6, 6,                                /* Parameter at index 170 */
  12, 12,                              /* Parameter at index 171 */
  12, 12,                              /* Parameter at index 172 */
  12, 12,                              /* Parameter at index 173 */
  12, 12,                              /* Parameter at index 174 */
  6, 12,                               /* Parameter at index 175 */
  6, 6,                                /* Parameter at index 176 */
  12, 12,                              /* Parameter at index 177 */
  1, 1,                                /* Parameter at index 178 */
  1, 1,                                /* Parameter at index 179 */
  1, 1,                                /* Parameter at index 180 */
  1, 1,                                /* Parameter at index 181 */
  1, 1,                                /* Parameter at index 182 */
  1, 1,                                /* Parameter at index 183 */
  1, 1,                                /* Parameter at index 184 */
  1, 1,                                /* Parameter at index 185 */
  1, 1,                                /* Parameter at index 186 */
  1, 1,                                /* Parameter at index 187 */
  1, 1,                                /* Parameter at index 188 */
  1, 1,                                /* Parameter at index 189 */
  1, 1,                                /* Parameter at index 190 */
  1, 1,                                /* Parameter at index 191 */
  1, 1,                                /* Parameter at index 192 */
  1, 1,                                /* Parameter at index 193 */
  3, 1,                                /* Parameter at index 194 */
  1, 1,                                /* Parameter at index 195 */
  1, 1,                                /* Parameter at index 196 */
  1, 6,                                /* Parameter at index 197 */
  1, 6,                                /* Parameter at index 198 */
  1, 6,                                /* Parameter at index 199 */
  1, 1,                                /* Parameter at index 200 */
  1, 1,                                /* Parameter at index 201 */
  1, 1,                                /* Parameter at index 202 */
  1, 1,                                /* Parameter at index 203 */
  1, 1,                                /* Parameter at index 204 */
  1, 1,                                /* Parameter at index 205 */
  1, 1,                                /* Parameter at index 206 */
  1, 1,                                /* Parameter at index 207 */
  1, 1,                                /* Parameter at index 208 */
  1, 1,                                /* Parameter at index 209 */
  1, 1,                                /* Parameter at index 210 */
  1, 1,                                /* Parameter at index 211 */
  1, 1,                                /* Parameter at index 212 */
  1, 1,                                /* Parameter at index 213 */
  1, 1,                                /* Parameter at index 214 */
  1, 1,                                /* Parameter at index 215 */
  1, 1,                                /* Parameter at index 216 */
  1, 1,                                /* Parameter at index 217 */
  1, 1,                                /* Parameter at index 218 */
  1, 1,                                /* Parameter at index 219 */
  1, 1,                                /* Parameter at index 220 */
  1, 1,                                /* Parameter at index 221 */
  1, 1,                                /* Parameter at index 222 */
  1, 1,                                /* Parameter at index 223 */
  1, 1,                                /* Parameter at index 224 */
  1, 1,                                /* Parameter at index 225 */
  1, 1,                                /* Parameter at index 226 */
  1, 1,                                /* Parameter at index 227 */
  1, 1,                                /* Parameter at index 228 */
  1, 1,                                /* Parameter at index 229 */
  1, 1,                                /* Parameter at index 230 */
  1, 1,                                /* Parameter at index 231 */
  1, 1,                                /* Parameter at index 232 */
  1, 1,                                /* Parameter at index 233 */
  1, 1,                                /* Parameter at index 234 */
  1, 1,                                /* Parameter at index 235 */
  1, 1,                                /* Parameter at index 236 */
  1, 1,                                /* Parameter at index 237 */
  1, 1,                                /* Parameter at index 238 */
  1, 1,                                /* Parameter at index 239 */
  1, 1,                                /* Parameter at index 240 */
  1, 1,                                /* Parameter at index 241 */
  1, 1,                                /* Parameter at index 242 */
  1, 1,                                /* Parameter at index 243 */
  1, 1,                                /* Parameter at index 244 */
  1, 1,                                /* Parameter at index 245 */
  1, 1,                                /* Parameter at index 246 */
  1, 1,                                /* Parameter at index 247 */
  1, 1,                                /* Parameter at index 248 */
  1, 1,                                /* Parameter at index 249 */
  1, 1,                                /* Parameter at index 250 */
  3, 1,                                /* Parameter at index 251 */
  3, 3,                                /* Parameter at index 252 */
  1, 1,                                /* Parameter at index 253 */
  1, 6,                                /* Parameter at index 254 */
  1, 6,                                /* Parameter at index 255 */
  1, 1,                                /* Parameter at index 256 */
  1, 1,                                /* Parameter at index 257 */
  1, 1,                                /* Parameter at index 258 */
  1, 1,                                /* Parameter at index 259 */
  1, 1,                                /* Parameter at index 260 */
  1, 1,                                /* Parameter at index 261 */
  1, 1,                                /* Parameter at index 262 */
  1, 1,                                /* Parameter at index 263 */
  1, 2,                                /* Parameter at index 264 */
  1, 2,                                /* Parameter at index 265 */
  1, 1,                                /* Parameter at index 266 */
  1, 1,                                /* Parameter at index 267 */
  1, 3,                                /* Parameter at index 268 */
  1, 3,                                /* Parameter at index 269 */
  1, 1,                                /* Parameter at index 270 */
  1, 1,                                /* Parameter at index 271 */
  1, 1,                                /* Parameter at index 272 */
  1, 1,                                /* Parameter at index 273 */
  1, 1,                                /* Parameter at index 274 */
  1, 1,                                /* Parameter at index 275 */
  1, 1,                                /* Parameter at index 276 */
  1, 1,                                /* Parameter at index 277 */
  1, 1,                                /* Parameter at index 278 */
  1, 2,                                /* Parameter at index 279 */
  1, 2,                                /* Parameter at index 280 */
  1, 1,                                /* Parameter at index 281 */
  1, 1,                                /* Parameter at index 282 */
  1, 3,                                /* Parameter at index 283 */
  1, 3,                                /* Parameter at index 284 */
  1, 1,                                /* Parameter at index 285 */
  1, 1,                                /* Parameter at index 286 */
  1, 1,                                /* Parameter at index 287 */
  1, 1,                                /* Parameter at index 288 */
  1, 1,                                /* Parameter at index 289 */
  1, 1,                                /* Parameter at index 290 */
  1, 1,                                /* Parameter at index 291 */
  1, 1,                                /* Parameter at index 292 */
  1, 1,                                /* Parameter at index 293 */
  1, 2,                                /* Parameter at index 294 */
  1, 2,                                /* Parameter at index 295 */
  1, 1,                                /* Parameter at index 296 */
  1, 1,                                /* Parameter at index 297 */
  1, 3,                                /* Parameter at index 298 */
  1, 3,                                /* Parameter at index 299 */
  1, 1,                                /* Parameter at index 300 */
  1, 1,                                /* Parameter at index 301 */
  1, 1,                                /* Parameter at index 302 */
  1, 1,                                /* Parameter at index 303 */
  1, 1,                                /* Parameter at index 304 */
  1, 1,                                /* Parameter at index 305 */
  1, 1,                                /* Parameter at index 306 */
  1, 1,                                /* Parameter at index 307 */
  1, 1,                                /* Parameter at index 308 */
  1, 2,                                /* Parameter at index 309 */
  1, 2,                                /* Parameter at index 310 */
  1, 1,                                /* Parameter at index 311 */
  1, 1,                                /* Parameter at index 312 */
  1, 3,                                /* Parameter at index 313 */
  1, 3,                                /* Parameter at index 314 */
  1, 1,                                /* Parameter at index 315 */
  1, 1,                                /* Parameter at index 316 */
  1, 1,                                /* Parameter at index 317 */
  1, 1,                                /* Parameter at index 318 */
  1, 1,                                /* Parameter at index 319 */
  1, 1,                                /* Parameter at index 320 */
  1, 1,                                /* Parameter at index 321 */
  1, 1,                                /* Parameter at index 322 */
  1, 1,                                /* Parameter at index 323 */
  1, 2,                                /* Parameter at index 324 */
  1, 2,                                /* Parameter at index 325 */
  1, 1,                                /* Parameter at index 326 */
  1, 1,                                /* Parameter at index 327 */
  1, 3,                                /* Parameter at index 328 */
  1, 3,                                /* Parameter at index 329 */
  1, 1,                                /* Parameter at index 330 */
  1, 1,                                /* Parameter at index 331 */
  1, 1,                                /* Parameter at index 332 */
  1, 1,                                /* Parameter at index 333 */
  1, 1,                                /* Parameter at index 334 */
  1, 1,                                /* Parameter at index 335 */
  1, 1,                                /* Parameter at index 336 */
  1, 1,                                /* Parameter at index 337 */
  1, 1,                                /* Parameter at index 338 */
  1, 2,                                /* Parameter at index 339 */
  1, 2,                                /* Parameter at index 340 */
  1, 1,                                /* Parameter at index 341 */
  1, 1,                                /* Parameter at index 342 */
  1, 3,                                /* Parameter at index 343 */
  1, 3,                                /* Parameter at index 344 */
  1, 1,                                /* Parameter at index 345 */
  1, 1,                                /* Parameter at index 346 */
  1, 1,                                /* Parameter at index 347 */
  1, 1,                                /* Parameter at index 348 */
  1, 1,                                /* Parameter at index 349 */
  1, 1,                                /* Parameter at index 350 */
  1, 1,                                /* Parameter at index 351 */
  1, 1,                                /* Parameter at index 352 */
  1, 1,                                /* Parameter at index 353 */
  1, 28,                               /* Parameter at index 354 */
  1, 1,                                /* Parameter at index 355 */
  1, 1,                                /* Parameter at index 356 */
  1, 1,                                /* Parameter at index 357 */
  1, 1,                                /* Parameter at index 358 */
  1, 1,                                /* Parameter at index 359 */
  1, 1,                                /* Parameter at index 360 */
  1, 1,                                /* Parameter at index 361 */
  1, 1,                                /* Parameter at index 362 */
  1, 1,                                /* Parameter at index 363 */
  1, 1,                                /* Parameter at index 364 */
  1, 1,                                /* Parameter at index 365 */
  1, 1,                                /* Parameter at index 366 */
  1, 1,                                /* Parameter at index 367 */
  1, 1,                                /* Parameter at index 368 */
  1, 1,                                /* Parameter at index 369 */
  1, 1,                                /* Parameter at index 370 */
  1, 1,                                /* Parameter at index 371 */
  1, 1,                                /* Parameter at index 372 */
  1, 1,                                /* Parameter at index 373 */
  1, 1,                                /* Parameter at index 374 */
  1, 1,                                /* Parameter at index 375 */
  1, 1,                                /* Parameter at index 376 */
  1, 1,                                /* Parameter at index 377 */
  1, 1,                                /* Parameter at index 378 */
  1, 1,                                /* Parameter at index 379 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_tapm/Input1/Control Gains/K_p_x", 0, "", offsetof(B_ctrl_TAPM_T,
    K_p_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_tapm/Input1/Control Gains/K_p_y", 0, "", offsetof(B_ctrl_TAPM_T,
    K_p_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_tapm/Input1/Control Gains/K_p_psi", 0, "", offsetof(B_ctrl_TAPM_T,
    K_p_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "ctrl_tapm/Input1/Control Gains/K_i_psi", 0, "", offsetof(B_ctrl_TAPM_T,
    K_i_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "ctrl_tapm/Input1/Control Gains/K_i_x", 0, "", offsetof(B_ctrl_TAPM_T,
    K_i_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "ctrl_tapm/Input1/Control Gains/K_i_y", 0, "", offsetof(B_ctrl_TAPM_T,
    K_i_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "ctrl_tapm/Input1/Control Gains/K_d_psi", 0, "", offsetof(B_ctrl_TAPM_T,
    K_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "ctrl_tapm/Input1/Control Gains/K_d_x", 0, "", offsetof(B_ctrl_TAPM_T,
    K_d_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "ctrl_tapm/Input1/Control Gains/K_d_y", 0, "", offsetof(B_ctrl_TAPM_T,
    K_d_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "ctrl_tapm/Pos measurements/x_m", 0, "", offsetof(B_ctrl_TAPM_T, x_m) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_tapm/Pos measurements/y_m", 0, "", offsetof(B_ctrl_TAPM_T, y_m) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_tapm/Pos measurements/psi_m", 0, "", offsetof(B_ctrl_TAPM_T, psi_m)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_tapm/Input1/reset", 0, "", offsetof(B_ctrl_TAPM_T, reset) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_tapm/Input1/Guidance gains/w_d_x", 0, "", offsetof(B_ctrl_TAPM_T,
    w_d_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "ctrl_tapm/Input1/Guidance gains/w_d_y", 0, "", offsetof(B_ctrl_TAPM_T,
    w_d_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "ctrl_tapm/Input1/Guidance gains/w_d_psi", 0, "", offsetof(B_ctrl_TAPM_T,
    w_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "ctrl_tapm/Input1/Guidance gains/zeta_psi", 0, "", offsetof
    (B_ctrl_TAPM_T, zeta_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "ctrl_tapm/Input1/Guidance gains/zeta_x", 0, "", offsetof(B_ctrl_TAPM_T,
    zeta_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "ctrl_tapm/Input1/Guidance gains/zeta_y", 0, "", offsetof(B_ctrl_TAPM_T,
    zeta_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 19, "ctrl_tapm/Input1/psi_ref", 0, "", offsetof(B_ctrl_TAPM_T, psi_ref) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "ctrl_tapm/Input1/x_ref", 0, "", offsetof(B_ctrl_TAPM_T, x_ref) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "ctrl_tapm/Input1/y_ref", 0, "", offsetof(B_ctrl_TAPM_T, y_ref) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "ctrl_tapm/Control/DP Controller/Sum2", 0, "regulation error(1, 1)",
    offsetof(B_ctrl_TAPM_T, regulationerror) + (0*sizeof(real_T)), BLOCKIO_SIG,
    21, 1, 2, 0, 0 },

  { 23, "ctrl_tapm/Control/DP Controller/Sum2", 0, "regulation error(2, 1)",
    offsetof(B_ctrl_TAPM_T, regulationerror) + (1*sizeof(real_T)), BLOCKIO_SIG,
    21, 1, 2, 0, 0 },

  { 24, "ctrl_tapm/Control/DP Controller/Sum2", 0, "regulation error(3, 1)",
    offsetof(B_ctrl_TAPM_T, regulationerror) + (2*sizeof(real_T)), BLOCKIO_SIG,
    21, 1, 2, 0, 0 },

  { 25, "ctrl_tapm/Nonlinear Passisve Observer/Integrator1/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM_T, Integrator1) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 26, "ctrl_tapm/Nonlinear Passisve Observer/Integrator1/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM_T, Integrator1) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 27, "ctrl_tapm/Nonlinear Passisve Observer/Integrator1/(1, 3)", 0, "",
    offsetof(B_ctrl_TAPM_T, Integrator1) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 28, "ctrl_tapm/Guidance/Reference model/Integrator3/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, Integrator3) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0,
    0 },

  { 29, "ctrl_tapm/Guidance/Reference model/Integrator3/(2, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, Integrator3) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0,
    0 },

  { 30, "ctrl_tapm/Guidance/Reference model/Integrator3/(3, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, Integrator3) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0,
    0 },

  { 31, "ctrl_tapm/Thruster measurment/thr_angle_1", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 32, "ctrl_tapm/Thruster measurment/thr_angle_2", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 33, "ctrl_tapm/Thruster measurment/thr_angle_3", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 34, "ctrl_tapm/Thruster measurment/thr_angle_4", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 35, "ctrl_tapm/Thruster measurment/thr_angle_5", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 36, "ctrl_tapm/Thruster measurment/thr_angle_6", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 37, "ctrl_tapm/Thrust allocation/reset/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset_g) + (0*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 38, "ctrl_tapm/Thrust allocation/reset/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset_g) + (1*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 39, "ctrl_tapm/Thrust allocation/reset/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset_g) + (2*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 40, "ctrl_tapm/Thrust allocation/reset/(1, 4)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset_g) + (3*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 41, "ctrl_tapm/Thrust allocation/reset/(1, 5)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset_g) + (4*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 42, "ctrl_tapm/Thrust allocation/reset/(1, 6)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset_g) + (5*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 43, "ctrl_tapm/Thrust allocation/Angle_controller", 0, "", offsetof
    (B_ctrl_TAPM_T, Angle_controller) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 44, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 1)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 45, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 2)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 46, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 3)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 47, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 4)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 48, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 5)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 49, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 6)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 50, "ctrl_tapm/Thruster control /Subsystem1/Saturation 1", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 51, "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 52, "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 53, "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 54, "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 55, "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 56, "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 57, "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/rpm1",
    0, "", offsetof(B_ctrl_TAPM_T, rpm1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 58, "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/rpm2",
    0, "", offsetof(B_ctrl_TAPM_T, rpm2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 59, "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/rpm3",
    0, "", offsetof(B_ctrl_TAPM_T, rpm3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 60, "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/rpm4",
    0, "", offsetof(B_ctrl_TAPM_T, rpm4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 61, "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/rpm5",
    0, "", offsetof(B_ctrl_TAPM_T, rpm5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 62, "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/rpm6",
    0, "", offsetof(B_ctrl_TAPM_T, rpm6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 63, "ctrl_tapm/Thruster control /Subsystem1/Saturation 2", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 64, "ctrl_tapm/Thruster control /Subsystem1/Saturation 3", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 65, "ctrl_tapm/Thruster control /Subsystem1/Saturation 4", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 66, "ctrl_tapm/Thruster control /Subsystem1/Saturation 5", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 67, "ctrl_tapm/Thruster control /Subsystem1/Saturation 6", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 68,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Saturation7) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 69,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 2)",
    0, "", offsetof(B_ctrl_TAPM_T, Saturation7) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 70,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 3)",
    0, "", offsetof(B_ctrl_TAPM_T, Saturation7) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 71,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 4)",
    0, "", offsetof(B_ctrl_TAPM_T, Saturation7) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 72,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 5)",
    0, "", offsetof(B_ctrl_TAPM_T, Saturation7) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 73,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 6)",
    0, "", offsetof(B_ctrl_TAPM_T, Saturation7) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 74, "ctrl_tapm/Nonlinear Passisve Observer/Integrator/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM_T, Integrator) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1,
    2, 0, 0 },

  { 75, "ctrl_tapm/Nonlinear Passisve Observer/Integrator/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM_T, Integrator) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1,
    2, 0, 0 },

  { 76, "ctrl_tapm/Nonlinear Passisve Observer/Integrator/(1, 3)", 0, "",
    offsetof(B_ctrl_TAPM_T, Integrator) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1,
    2, 0, 0 },

  { 77, "ctrl_tapm/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Sum", 0,
    "", offsetof(B_ctrl_TAPM_T, Sum) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 78, "ctrl_tapm/Nonlinear Passisve Observer/Integrator2/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM_T, Integrator2) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 79, "ctrl_tapm/Nonlinear Passisve Observer/Integrator2/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM_T, Integrator2) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 80, "ctrl_tapm/Nonlinear Passisve Observer/Integrator2/(1, 3)", 0, "",
    offsetof(B_ctrl_TAPM_T, Integrator2) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 81, "ctrl_tapm/Nonlinear Passisve Observer/M^-1/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, M1) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 82, "ctrl_tapm/Nonlinear Passisve Observer/M^-1/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM_T, M1) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 83, "ctrl_tapm/Nonlinear Passisve Observer/M^-1/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM_T, M1) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 84, "ctrl_tapm/Radians to Degrees/Gain/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (0*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 85, "ctrl_tapm/Radians to Degrees/Gain/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (1*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 86, "ctrl_tapm/Radians to Degrees/Gain/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (2*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 87, "ctrl_tapm/Radians to Degrees/Gain/(1, 4)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (3*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 88, "ctrl_tapm/Radians to Degrees/Gain/(1, 5)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (4*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 89, "ctrl_tapm/Radians to Degrees/Gain/(1, 6)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (5*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 90, "ctrl_tapm/Guidance/Reference model/Matrix Multiply/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM_T, MatrixMultiply) + (0*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 91, "ctrl_tapm/Guidance/Reference model/Matrix Multiply/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM_T, MatrixMultiply) + (1*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 92, "ctrl_tapm/Guidance/Reference model/Matrix Multiply/(1, 3)", 0, "",
    offsetof(B_ctrl_TAPM_T, MatrixMultiply) + (2*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 93, "ctrl_tapm/Guidance/Reference model/Sum5", 0, "(1, 1)", offsetof
    (B_ctrl_TAPM_T, Sum5) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 94, "ctrl_tapm/Guidance/Reference model/Sum5", 0, "(2, 1)", offsetof
    (B_ctrl_TAPM_T, Sum5) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 95, "ctrl_tapm/Guidance/Reference model/Sum5", 0, "(3, 1)", offsetof
    (B_ctrl_TAPM_T, Sum5) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 96, "ctrl_tapm/Nonlinear Passisve Observer/Matrix Multiply1/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM_T, MatrixMultiply1) + (0*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 97, "ctrl_tapm/Nonlinear Passisve Observer/Matrix Multiply1/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM_T, MatrixMultiply1) + (1*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 98, "ctrl_tapm/Nonlinear Passisve Observer/Matrix Multiply1/(1, 3)", 0, "",
    offsetof(B_ctrl_TAPM_T, MatrixMultiply1) + (2*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 99, "ctrl_tapm/Nonlinear Passisve Observer/Sum1/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 100, "ctrl_tapm/Nonlinear Passisve Observer/Sum1/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM_T, Sum1) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 101, "ctrl_tapm/Nonlinear Passisve Observer/Sum1/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM_T, Sum1) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 102, "ctrl_tapm/Pos measurements/X_oqus", 0, "", offsetof(B_ctrl_TAPM_T,
    X_oqus) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 103, "ctrl_tapm/Pos measurements/Y_oqus", 0, "", offsetof(B_ctrl_TAPM_T,
    Y_oqus) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 104, "ctrl_tapm/Pos measurements/Z_oqus", 0, "", offsetof(B_ctrl_TAPM_T,
    Z_oqus) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 105, "ctrl_tapm/Pos measurements/roll_oqus", 0, "", offsetof(B_ctrl_TAPM_T,
    roll_oqus) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 106, "ctrl_tapm/Pos measurements/pitch_oqus", 0, "", offsetof(B_ctrl_TAPM_T,
    pitch_oqus) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 107, "ctrl_tapm/Pos measurements/yaw_oqus", 0, "", offsetof(B_ctrl_TAPM_T,
    yaw_oqus) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 108, "ctrl_tapm/Thruster control /Delay/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay) + (0*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 109, "ctrl_tapm/Thruster control /Delay/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay) + (1*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 110, "ctrl_tapm/Thruster control /Delay/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay) + (2*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 111, "ctrl_tapm/Thruster control /Delay/(1, 4)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay) + (3*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 112, "ctrl_tapm/Thruster control /Delay/(1, 5)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay) + (4*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 113, "ctrl_tapm/Thruster control /Delay/(1, 6)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay) + (5*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 114, "ctrl_tapm/Thruster control /Thruster 1/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 115, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 116,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 117,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 118,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 119, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 120, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 121,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 122,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_kk) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 123, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 124, "ctrl_tapm/Thruster control /Thruster 1/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 125,
    "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 126,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 127, "ctrl_tapm/Thruster control /Thruster 2/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 128, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_bs) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 129,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 130,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 131,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 132, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_nn) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 133, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 134,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 135,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 136, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 137, "ctrl_tapm/Thruster control /Thruster 2/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 138,
    "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 139,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 140, "ctrl_tapm/Thruster control /Thruster 3/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 141, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_by) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 142,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 143,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 144,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 145, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 146, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 147,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 148,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_j2) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 149, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_hf) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 150, "ctrl_tapm/Thruster control /Thruster 3/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 151,
    "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 152,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 153, "ctrl_tapm/Thruster control /Thruster 4/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_g) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 154, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 155,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 156,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 157,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 158, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 159, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 160,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 161,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 162, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_k2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 163, "ctrl_tapm/Thruster control /Thruster 4/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 164,
    "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_ms) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 165,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 166, "ctrl_tapm/Thruster control /Thruster 5/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_a5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 167, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_id) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 168,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 169,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_m) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 170,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 171, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 172, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 173,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 174,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 175, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 176, "ctrl_tapm/Thruster control /Thruster 5/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_lz) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 177,
    "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_ag) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 178,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 179, "ctrl_tapm/Thruster control /Thruster 6/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 180, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_il) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 181,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 182,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 183,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_e3) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 184, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_io) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 185, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 186,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 187,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_om) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 188, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 189, "ctrl_tapm/Thruster control /Thruster 6/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_ea) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 190,
    "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 191,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 192, "ctrl_tapm/IMU/IMU_AX1", 0, "", offsetof(B_ctrl_TAPM_T, IMU_AX1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 193, "ctrl_tapm/IMU/IMU_AY1", 0, "", offsetof(B_ctrl_TAPM_T, IMU_AY1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 194, "ctrl_tapm/IMU/IMU_AZ1", 0, "", offsetof(B_ctrl_TAPM_T, IMU_AZ1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 195, "ctrl_tapm/IMU/IMU_RX1", 0, "", offsetof(B_ctrl_TAPM_T, IMU_RX1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 196, "ctrl_tapm/IMU/IMU_RY1", 0, "", offsetof(B_ctrl_TAPM_T, IMU_RY1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 197, "ctrl_tapm/IMU/IMU_RZ1", 0, "", offsetof(B_ctrl_TAPM_T, IMU_RZ1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 198, "ctrl_tapm/IMU/IMU_V1", 0, "", offsetof(B_ctrl_TAPM_T, IMU_V1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 199, "ctrl_tapm/IMU/IMU_AX2", 0, "", offsetof(B_ctrl_TAPM_T, IMU_AX2) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 200, "ctrl_tapm/IMU/IMU_AY2", 0, "", offsetof(B_ctrl_TAPM_T, IMU_AY2) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 201, "ctrl_tapm/IMU/IMU_AZ2", 0, "", offsetof(B_ctrl_TAPM_T, IMU_AZ2) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 202, "ctrl_tapm/IMU/IMU_RX2", 0, "", offsetof(B_ctrl_TAPM_T, IMU_RX2) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 203, "ctrl_tapm/IMU/IMU_RY2", 0, "", offsetof(B_ctrl_TAPM_T, IMU_RY2) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 204, "ctrl_tapm/IMU/IMU_RZ2", 0, "", offsetof(B_ctrl_TAPM_T, IMU_RZ2) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 205, "ctrl_tapm/IMU/IMU_V2", 0, "", offsetof(B_ctrl_TAPM_T, IMU_V2) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 206, "ctrl_tapm/IMU/IMU_AX3", 0, "", offsetof(B_ctrl_TAPM_T, IMU_AX3) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 207, "ctrl_tapm/IMU/IMU_AY3", 0, "", offsetof(B_ctrl_TAPM_T, IMU_AY3) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 208, "ctrl_tapm/IMU/IMU_AZ3", 0, "", offsetof(B_ctrl_TAPM_T, IMU_AZ3) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 209, "ctrl_tapm/IMU/IMU_RX3", 0, "", offsetof(B_ctrl_TAPM_T, IMU_RX3) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 210, "ctrl_tapm/IMU/IMU_RY3", 0, "", offsetof(B_ctrl_TAPM_T, IMU_RY3) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 211, "ctrl_tapm/IMU/IMU_RZ3", 0, "", offsetof(B_ctrl_TAPM_T, IMU_RZ3) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 212, "ctrl_tapm/IMU/IMU_V3", 0, "", offsetof(B_ctrl_TAPM_T, IMU_V3) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 213, "ctrl_tapm/IMU/IMU_AX4", 0, "", offsetof(B_ctrl_TAPM_T, IMU_AX4) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 214, "ctrl_tapm/IMU/IMU_AY4", 0, "", offsetof(B_ctrl_TAPM_T, IMU_AY4) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 215, "ctrl_tapm/IMU/IMU_AZ4", 0, "", offsetof(B_ctrl_TAPM_T, IMU_AZ4) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 216, "ctrl_tapm/IMU/IMU_RX4", 0, "", offsetof(B_ctrl_TAPM_T, IMU_RX4) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 217, "ctrl_tapm/IMU/IMU_RY4", 0, "", offsetof(B_ctrl_TAPM_T, IMU_RY4) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 218, "ctrl_tapm/IMU/IMU_RZ4", 0, "", offsetof(B_ctrl_TAPM_T, IMU_RZ4) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 219, "ctrl_tapm/IMU/IMU_V4", 0, "", offsetof(B_ctrl_TAPM_T, IMU_V4) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 220,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, n_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 221,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, n_d_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 222,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, n_d_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 223,
    "ctrl_tapm/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, Qa) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 224,
    "ctrl_tapm/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    2, "", offsetof(B_ctrl_TAPM_T, Pa) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 225,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function1",
    0, "", offsetof(B_ctrl_TAPM_T, Tc_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 226,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 1)", offsetof(B_ctrl_TAPM_T, output) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 29, 1, 2, 0, 0 },

  { 227,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 2)", offsetof(B_ctrl_TAPM_T, output) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 29, 1, 2, 0, 0 },

  { 228,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 3)", offsetof(B_ctrl_TAPM_T, output) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 29, 1, 2, 0, 0 },

  { 229,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 4)", offsetof(B_ctrl_TAPM_T, output) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 29, 1, 2, 0, 0 },

  { 230,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 5)", offsetof(B_ctrl_TAPM_T, output) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 29, 1, 2, 0, 0 },

  { 231,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 6)", offsetof(B_ctrl_TAPM_T, output) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 29, 1, 2, 0, 0 },

  { 232,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 7)", offsetof(B_ctrl_TAPM_T, output) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 29, 1, 2, 0, 0 },

  { 233,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 8)", offsetof(B_ctrl_TAPM_T, output) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 29, 1, 2, 0, 0 },

  { 234,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 9)", offsetof(B_ctrl_TAPM_T, output) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 29, 1, 2, 0, 0 },

  { 235,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 10)", offsetof(B_ctrl_TAPM_T, output) + (9*sizeof(real_T)),
    BLOCKIO_SIG, 29, 1, 2, 0, 0 },

  { 236,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 11)", offsetof(B_ctrl_TAPM_T, output) + (10*sizeof(real_T)),
    BLOCKIO_SIG, 29, 1, 2, 0, 0 },

  { 237,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 12)", offsetof(B_ctrl_TAPM_T, output) + (11*sizeof(real_T)),
    BLOCKIO_SIG, 29, 1, 2, 0, 0 },

  { 238, "ctrl_tapm/IMU/Filtering/In1/(1, 1)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (0*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 239, "ctrl_tapm/IMU/Filtering/In1/(1, 2)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (1*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 240, "ctrl_tapm/IMU/Filtering/In1/(1, 3)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (2*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 241, "ctrl_tapm/IMU/Filtering/In1/(1, 4)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (3*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 242, "ctrl_tapm/IMU/Filtering/In1/(1, 5)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (4*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 243, "ctrl_tapm/IMU/Filtering/In1/(1, 6)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (5*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 244, "ctrl_tapm/IMU/Filtering/In1/(1, 7)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (6*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 245, "ctrl_tapm/IMU/Filtering/In1/(1, 8)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (7*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 246, "ctrl_tapm/IMU/Filtering/In1/(1, 9)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (8*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 247, "ctrl_tapm/IMU/Filtering/In1/(1, 10)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (9*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 248, "ctrl_tapm/IMU/Filtering/In1/(1, 11)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (10*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 249, "ctrl_tapm/IMU/Filtering/In1/(1, 12)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (11*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 250, "ctrl_tapm/IMU/Filtering/In1/(1, 13)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (12*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 251, "ctrl_tapm/IMU/Filtering/In1/(1, 14)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (13*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 252, "ctrl_tapm/IMU/Filtering/In1/(1, 15)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (14*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 253, "ctrl_tapm/IMU/Filtering/In1/(1, 16)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (15*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 254, "ctrl_tapm/IMU/Filtering/In1/(1, 17)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (16*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 255, "ctrl_tapm/IMU/Filtering/In1/(1, 18)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (17*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 256, "ctrl_tapm/IMU/Filtering/In1/(1, 19)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (18*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 257, "ctrl_tapm/IMU/Filtering/In1/(1, 20)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (19*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 258, "ctrl_tapm/IMU/Filtering/In1/(1, 21)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (20*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 259, "ctrl_tapm/IMU/Filtering/In1/(1, 22)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (21*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 260, "ctrl_tapm/IMU/Filtering/In1/(1, 23)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (22*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 261, "ctrl_tapm/IMU/Filtering/In1/(1, 24)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (23*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 262, "ctrl_tapm/IMU/Filtering/In1/(1, 25)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (24*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 263, "ctrl_tapm/IMU/Filtering/In1/(1, 26)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (25*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 264, "ctrl_tapm/IMU/Filtering/In1/(1, 27)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (26*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 265, "ctrl_tapm/IMU/Filtering/In1/(1, 28)", 0, "", offsetof(B_ctrl_TAPM_T,
    In1) + (27*sizeof(real_T)), BLOCKIO_SIG, 27, 1, 2, 0, 0 },

  { 266, "ctrl_tapm/IMU/Filtering/Outliner cleaner/Merge1/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1) + (0*sizeof(real_T)), BLOCKIO_SIG, 39, 1, 2,
    0, 0 },

  { 267, "ctrl_tapm/IMU/Filtering/Outliner cleaner/Merge1/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1) + (1*sizeof(real_T)), BLOCKIO_SIG, 39, 1, 2,
    0, 0 },

  { 268, "ctrl_tapm/IMU/Filtering/Outliner cleaner/Merge1/(1, 3)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1) + (2*sizeof(real_T)), BLOCKIO_SIG, 39, 1, 2,
    0, 0 },

  { 269, "ctrl_tapm/IMU/Filtering/Outliner cleaner/Merge1/(1, 4)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1) + (3*sizeof(real_T)), BLOCKIO_SIG, 39, 1, 2,
    0, 0 },

  { 270, "ctrl_tapm/IMU/Filtering/Outliner cleaner/Merge1/(1, 5)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1) + (4*sizeof(real_T)), BLOCKIO_SIG, 39, 1, 2,
    0, 0 },

  { 271, "ctrl_tapm/IMU/Filtering/Outliner cleaner1/Merge1/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 272, "ctrl_tapm/IMU/Filtering/Outliner cleaner1/Merge1/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_e) + (1*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 273, "ctrl_tapm/IMU/Filtering/Outliner cleaner1/Merge1/(1, 3)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_e) + (2*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 274, "ctrl_tapm/IMU/Filtering/Outliner cleaner1/Merge1/(1, 4)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_e) + (3*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 275, "ctrl_tapm/IMU/Filtering/Outliner cleaner1/Merge1/(1, 5)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_e) + (4*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 276, "ctrl_tapm/IMU/Filtering/Outliner cleaner2/Merge1/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 277, "ctrl_tapm/IMU/Filtering/Outliner cleaner2/Merge1/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_k) + (1*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 278, "ctrl_tapm/IMU/Filtering/Outliner cleaner2/Merge1/(1, 3)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_k) + (2*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 279, "ctrl_tapm/IMU/Filtering/Outliner cleaner2/Merge1/(1, 4)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_k) + (3*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 280, "ctrl_tapm/IMU/Filtering/Outliner cleaner2/Merge1/(1, 5)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_k) + (4*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 281, "ctrl_tapm/IMU/Filtering/Outliner cleaner3/Merge1/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 282, "ctrl_tapm/IMU/Filtering/Outliner cleaner3/Merge1/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_h) + (1*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 283, "ctrl_tapm/IMU/Filtering/Outliner cleaner3/Merge1/(1, 3)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_h) + (2*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 284, "ctrl_tapm/IMU/Filtering/Outliner cleaner3/Merge1/(1, 4)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_h) + (3*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 285, "ctrl_tapm/IMU/Filtering/Outliner cleaner3/Merge1/(1, 5)", 0, "",
    offsetof(B_ctrl_TAPM_T, Merge1_h) + (4*sizeof(real_T)), BLOCKIO_SIG, 39, 1,
    2, 0, 0 },

  { 286, "ctrl_tapm/Finding commanded forces in: [Surge,Sway,Yaw]", 0, "(1, 1)",
    offsetof(B_ctrl_TAPM_T, commanded_tau) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 287, "ctrl_tapm/Finding commanded forces in: [Surge,Sway,Yaw]", 0, "(1, 2)",
    offsetof(B_ctrl_TAPM_T, commanded_tau) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 288, "ctrl_tapm/Finding commanded forces in: [Surge,Sway,Yaw]", 0, "(1, 3)",
    offsetof(B_ctrl_TAPM_T, commanded_tau) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 289, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_e.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 290,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_nf.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 291,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_nf.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 292,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_nf.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 293,
    "ctrl_tapm/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_j.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 294,
    "ctrl_tapm/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_j.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 295, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_b.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 296,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_j.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 297,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/MATLAB Function", 1,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_j.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 298,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_h.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 299,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_h.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 300,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_h.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 301,
    "ctrl_tapm/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_o.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 302,
    "ctrl_tapm/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_o.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 303, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_n.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 304,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_go.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 305,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/MATLAB Function", 1,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_go.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 306,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_n3.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 307,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_n3.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 308,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_n3.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 309,
    "ctrl_tapm/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_m.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 310,
    "ctrl_tapm/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_m.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 311, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_l.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 312,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_n.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 313,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_n.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 314,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_n.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 315,
    "ctrl_tapm/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_h.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 316,
    "ctrl_tapm/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_h.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 317, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_h.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 318,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_i.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 319,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/MATLAB Function", 1,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_i.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 320,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_o.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 321,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_o.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 322,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_o.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 323,
    "ctrl_tapm/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_f.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 324,
    "ctrl_tapm/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_f.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 325, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 326,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowerand.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 327,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowerand.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 328,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowerand.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 329,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function6",
    0, "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction6.Tc_out) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 330,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function5",
    0, "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction5.Tc_out) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 331,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function4",
    0, "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction4.Tc_out) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 332,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function3",
    0, "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction3.Tc_out) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 333,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function2",
    0, "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction2.Tc_out) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 334,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Discrete-Time Integrator",
    0, "angle", offsetof(B_ctrl_TAPM_T, CoreSubsys[5].angle) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 335,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Delay",
    0, "", offsetof(B_ctrl_TAPM_T, CoreSubsys[5].Delay) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 336,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Max Rotation Rate",
    0, "", offsetof(B_ctrl_TAPM_T, CoreSubsys[5].MaxRotationRate) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 337, "ctrl_tapm/Input1/Observer Gains/Kp", 0, "(1, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Kp_m.K_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 338, "ctrl_tapm/Input1/Observer Gains/Kp", 0, "(2, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Kp_m.K_p) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 339, "ctrl_tapm/Input1/Observer Gains/Kp", 0, "(3, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Kp_m.K_p) + (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 340, "ctrl_tapm/Input1/Observer Gains/Kp", 0, "(1, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Kp_m.K_p) + (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 341, "ctrl_tapm/Input1/Observer Gains/Kp", 0, "(2, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Kp_m.K_p) + (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 342, "ctrl_tapm/Input1/Observer Gains/Kp", 0, "(3, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Kp_m.K_p) + (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 343, "ctrl_tapm/Input1/Observer Gains/Kp", 0, "(1, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Kp_m.K_p) + (6*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 344, "ctrl_tapm/Input1/Observer Gains/Kp", 0, "(2, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Kp_m.K_p) + (7*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 345, "ctrl_tapm/Input1/Observer Gains/Kp", 0, "(3, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Kp_m.K_p) + (8*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 346, "ctrl_tapm/Input1/Observer Gains/Ki", 0, "(1, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Ki_k.K_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 347, "ctrl_tapm/Input1/Observer Gains/Ki", 0, "(2, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Ki_k.K_i) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 348, "ctrl_tapm/Input1/Observer Gains/Ki", 0, "(3, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Ki_k.K_i) + (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 349, "ctrl_tapm/Input1/Observer Gains/Ki", 0, "(1, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Ki_k.K_i) + (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 350, "ctrl_tapm/Input1/Observer Gains/Ki", 0, "(2, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Ki_k.K_i) + (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 351, "ctrl_tapm/Input1/Observer Gains/Ki", 0, "(3, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Ki_k.K_i) + (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 352, "ctrl_tapm/Input1/Observer Gains/Ki", 0, "(1, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Ki_k.K_i) + (6*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 353, "ctrl_tapm/Input1/Observer Gains/Ki", 0, "(2, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Ki_k.K_i) + (7*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 354, "ctrl_tapm/Input1/Observer Gains/Ki", 0, "(3, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Ki_k.K_i) + (8*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 355, "ctrl_tapm/Input1/Observer Gains/Kd", 0, "(1, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Kd_p.K_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 356, "ctrl_tapm/Input1/Observer Gains/Kd", 0, "(2, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Kd_p.K_d) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 357, "ctrl_tapm/Input1/Observer Gains/Kd", 0, "(3, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Kd_p.K_d) + (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 358, "ctrl_tapm/Input1/Observer Gains/Kd", 0, "(1, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Kd_p.K_d) + (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 359, "ctrl_tapm/Input1/Observer Gains/Kd", 0, "(2, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Kd_p.K_d) + (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 360, "ctrl_tapm/Input1/Observer Gains/Kd", 0, "(3, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Kd_p.K_d) + (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 361, "ctrl_tapm/Input1/Observer Gains/Kd", 0, "(1, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Kd_p.K_d) + (6*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 362, "ctrl_tapm/Input1/Observer Gains/Kd", 0, "(2, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Kd_p.K_d) + (7*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 363, "ctrl_tapm/Input1/Observer Gains/Kd", 0, "(3, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Kd_p.K_d) + (8*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 364, "ctrl_tapm/Input1/Control Gains/Kp", 0, "(1, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Kp.K_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 365, "ctrl_tapm/Input1/Control Gains/Kp", 0, "(2, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Kp.K_p) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 366, "ctrl_tapm/Input1/Control Gains/Kp", 0, "(3, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Kp.K_p) + (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 367, "ctrl_tapm/Input1/Control Gains/Kp", 0, "(1, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Kp.K_p) + (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 368, "ctrl_tapm/Input1/Control Gains/Kp", 0, "(2, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Kp.K_p) + (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 369, "ctrl_tapm/Input1/Control Gains/Kp", 0, "(3, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Kp.K_p) + (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 370, "ctrl_tapm/Input1/Control Gains/Kp", 0, "(1, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Kp.K_p) + (6*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 371, "ctrl_tapm/Input1/Control Gains/Kp", 0, "(2, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Kp.K_p) + (7*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 372, "ctrl_tapm/Input1/Control Gains/Kp", 0, "(3, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Kp.K_p) + (8*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 373, "ctrl_tapm/Input1/Control Gains/Ki", 0, "(1, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Ki.K_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 374, "ctrl_tapm/Input1/Control Gains/Ki", 0, "(2, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Ki.K_i) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 375, "ctrl_tapm/Input1/Control Gains/Ki", 0, "(3, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Ki.K_i) + (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 376, "ctrl_tapm/Input1/Control Gains/Ki", 0, "(1, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Ki.K_i) + (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 377, "ctrl_tapm/Input1/Control Gains/Ki", 0, "(2, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Ki.K_i) + (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 378, "ctrl_tapm/Input1/Control Gains/Ki", 0, "(3, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Ki.K_i) + (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 379, "ctrl_tapm/Input1/Control Gains/Ki", 0, "(1, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Ki.K_i) + (6*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 380, "ctrl_tapm/Input1/Control Gains/Ki", 0, "(2, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Ki.K_i) + (7*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 381, "ctrl_tapm/Input1/Control Gains/Ki", 0, "(3, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Ki.K_i) + (8*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 382, "ctrl_tapm/Input1/Control Gains/Kd", 0, "(1, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Kd.K_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 383, "ctrl_tapm/Input1/Control Gains/Kd", 0, "(2, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Kd.K_d) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 384, "ctrl_tapm/Input1/Control Gains/Kd", 0, "(3, 1)", offsetof
    (B_ctrl_TAPM_T, sf_Kd.K_d) + (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 385, "ctrl_tapm/Input1/Control Gains/Kd", 0, "(1, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Kd.K_d) + (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 386, "ctrl_tapm/Input1/Control Gains/Kd", 0, "(2, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Kd.K_d) + (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 387, "ctrl_tapm/Input1/Control Gains/Kd", 0, "(3, 2)", offsetof
    (B_ctrl_TAPM_T, sf_Kd.K_d) + (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 388, "ctrl_tapm/Input1/Control Gains/Kd", 0, "(1, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Kd.K_d) + (6*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 389, "ctrl_tapm/Input1/Control Gains/Kd", 0, "(2, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Kd.K_d) + (7*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { 390, "ctrl_tapm/Input1/Control Gains/Kd", 0, "(3, 3)", offsetof
    (B_ctrl_TAPM_T, sf_Kd.K_d) + (8*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0
  },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 391;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 116;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Input1/Control Gains/K_p_x", 0, EXT_IN, 1, 1, 1 },

  { 2, "Input1/Control Gains/K_p_y", 0, EXT_IN, 1, 1, 1 },

  { 3, "Input1/Control Gains/K_p_psi", 0, EXT_IN, 1, 1, 1 },

  { 4, "Input1/Control Gains/K_i_psi", 0, EXT_IN, 1, 1, 1 },

  { 5, "Input1/Control Gains/K_i_x", 0, EXT_IN, 1, 1, 1 },

  { 6, "Input1/Control Gains/K_i_y", 0, EXT_IN, 1, 1, 1 },

  { 7, "Input1/Control Gains/K_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 8, "Input1/Control Gains/K_d_x", 0, EXT_IN, 1, 1, 1 },

  { 9, "Input1/Control Gains/K_d_y", 0, EXT_IN, 1, 1, 1 },

  { 10, "Pos measurements/x_m", 0, EXT_IN, 1, 1, 1 },

  { 11, "Pos measurements/y_m", 0, EXT_IN, 1, 1, 1 },

  { 12, "Pos measurements/psi_m", 0, EXT_IN, 1, 1, 1 },

  { 13, "Input1/reset", 0, EXT_IN, 1, 1, 1 },

  { 14, "Input1/Guidance gains/w_d_x", 0, EXT_IN, 1, 1, 1 },

  { 15, "Input1/Guidance gains/w_d_y", 0, EXT_IN, 1, 1, 1 },

  { 16, "Input1/Guidance gains/w_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 17, "Input1/Guidance gains/zeta_psi", 0, EXT_IN, 1, 1, 1 },

  { 18, "Input1/Guidance gains/zeta_x", 0, EXT_IN, 1, 1, 1 },

  { 19, "Input1/Guidance gains/zeta_y", 0, EXT_IN, 1, 1, 1 },

  { 20, "Input1/psi_ref", 0, EXT_IN, 1, 1, 1 },

  { 21, "Input1/x_ref", 0, EXT_IN, 1, 1, 1 },

  { 22, "Input1/y_ref", 0, EXT_IN, 1, 1, 1 },

  { 23, "Thruster measurment/thr_angle_1", 0, EXT_IN, 1, 1, 1 },

  { 24, "Thruster measurment/thr_angle_2", 0, EXT_IN, 1, 1, 1 },

  { 25, "Thruster measurment/thr_angle_3", 0, EXT_IN, 1, 1, 1 },

  { 26, "Thruster measurment/thr_angle_4", 0, EXT_IN, 1, 1, 1 },

  { 27, "Thruster measurment/thr_angle_5", 0, EXT_IN, 1, 1, 1 },

  { 28, "Thruster measurment/thr_angle_6", 0, EXT_IN, 1, 1, 1 },

  { 29, "Thrust allocation/reset", 1, EXT_IN, 6, 6, 1 },

  { 30, "Thrust allocation/Angle_controller", 0, EXT_IN, 1, 1, 1 },

  { 31, "Thruster control /Thruster 1/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 32, "Thruster control /Thruster 2/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 33, "Thruster control /Thruster 3/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 34, "Thruster control /Thruster 4/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 35, "Thruster control /Thruster 5/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 36, "Thruster control /Thruster 6/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 37, "Thruster control /Thrust and Shaft speed mapped to PWM/rpm1 ", 0,
    EXT_IN, 1, 1, 1 },

  { 38, "Thruster control /Thrust and Shaft speed mapped to PWM/rpm2", 0, EXT_IN,
    1, 1, 1 },

  { 39, "Thruster control /Thrust and Shaft speed mapped to PWM/rpm3", 0, EXT_IN,
    1, 1, 1 },

  { 40, "Thruster control /Thrust and Shaft speed mapped to PWM/rpm4", 0, EXT_IN,
    1, 1, 1 },

  { 41, "Thruster control /Thrust and Shaft speed mapped to PWM/rpm5", 0, EXT_IN,
    1, 1, 1 },

  { 42, "Thruster control /Thrust and Shaft speed mapped to PWM/rpm6", 0, EXT_IN,
    1, 1, 1 },

  { 43, "Pos measurements/X_oqus", 1, EXT_IN, 1, 1, 1 },

  { 44, "Pos measurements/Y_oqus", 1, EXT_IN, 1, 1, 1 },

  { 45, "Pos measurements/Z_oqus", 1, EXT_IN, 1, 1, 1 },

  { 46, "Pos measurements/roll_oqus", 1, EXT_IN, 1, 1, 1 },

  { 47, "Pos measurements/pitch_oqus", 1, EXT_IN, 1, 1, 1 },

  { 48, "Pos measurements/yaw_oqus", 1, EXT_IN, 1, 1, 1 },

  { 49, "Thruster control /Thruster 1/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 50, "Thruster control /Thruster 2/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 51, "Thruster control /Thruster 3/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 52, "Thruster control /Thruster 4/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 53, "Thruster control /Thruster 5/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 54, "Thruster control /Thruster 6/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 55, "IMU/IMU_AX1", 1, EXT_IN, 1, 1, 1 },

  { 56, "IMU/IMU_AY1", 1, EXT_IN, 1, 1, 1 },

  { 57, "IMU/IMU_AZ1", 1, EXT_IN, 1, 1, 1 },

  { 58, "IMU/IMU_RX1", 1, EXT_IN, 1, 1, 1 },

  { 59, "IMU/IMU_RY1", 1, EXT_IN, 1, 1, 1 },

  { 60, "IMU/IMU_RZ1", 1, EXT_IN, 1, 1, 1 },

  { 61, "IMU/IMU_V1", 1, EXT_IN, 1, 1, 1 },

  { 62, "IMU/IMU_AX2", 1, EXT_IN, 1, 1, 1 },

  { 63, "IMU/IMU_AY2", 1, EXT_IN, 1, 1, 1 },

  { 64, "IMU/IMU_AZ2", 1, EXT_IN, 1, 1, 1 },

  { 65, "IMU/IMU_RX2", 1, EXT_IN, 1, 1, 1 },

  { 66, "IMU/IMU_RY2", 1, EXT_IN, 1, 1, 1 },

  { 67, "IMU/IMU_RZ2", 1, EXT_IN, 1, 1, 1 },

  { 68, "IMU/IMU_V2", 1, EXT_IN, 1, 1, 1 },

  { 69, "IMU/IMU_AX3", 1, EXT_IN, 1, 1, 1 },

  { 70, "IMU/IMU_AY3", 1, EXT_IN, 1, 1, 1 },

  { 71, "IMU/IMU_AZ3", 1, EXT_IN, 1, 1, 1 },

  { 72, "IMU/IMU_RX3", 1, EXT_IN, 1, 1, 1 },

  { 73, "IMU/IMU_RY3", 1, EXT_IN, 1, 1, 1 },

  { 74, "IMU/IMU_RZ3", 1, EXT_IN, 1, 1, 1 },

  { 75, "IMU/IMU_V3", 1, EXT_IN, 1, 1, 1 },

  { 76, "IMU/IMU_AX4", 1, EXT_IN, 1, 1, 1 },

  { 77, "IMU/IMU_AY4", 1, EXT_IN, 1, 1, 1 },

  { 78, "IMU/IMU_AZ4", 1, EXT_IN, 1, 1, 1 },

  { 79, "IMU/IMU_RX4", 1, EXT_IN, 1, 1, 1 },

  { 80, "IMU/IMU_RY4", 1, EXT_IN, 1, 1, 1 },

  { 81, "IMU/IMU_RZ4", 1, EXT_IN, 1, 1, 1 },

  { 82, "IMU/IMU_V4", 1, EXT_IN, 1, 1, 1 },

  { 1, "alpha_1", 1, EXT_OUT, 1, 1, 1 },

  { 2, "pwm_2", 0, EXT_OUT, 1, 1, 1 },

  { 3, "pwm_3", 0, EXT_OUT, 1, 1, 1 },

  { 4, "pwm_4", 0, EXT_OUT, 1, 1, 1 },

  { 5, "pwm_5", 0, EXT_OUT, 1, 1, 1 },

  { 6, "alpha_2", 1, EXT_OUT, 1, 1, 1 },

  { 7, "pwm_6", 0, EXT_OUT, 1, 1, 1 },

  { 8, "alpha_3", 1, EXT_OUT, 1, 1, 1 },

  { 9, "alpha_4", 1, EXT_OUT, 1, 1, 1 },

  { 10, "alpha_5", 1, EXT_OUT, 1, 1, 1 },

  { 11, "alpha_6", 1, EXT_OUT, 1, 1, 1 },

  { 12, "u_1", 0, EXT_OUT, 1, 1, 1 },

  { 13, "u_4", 0, EXT_OUT, 1, 1, 1 },

  { 14, "u_5", 0, EXT_OUT, 1, 1, 1 },

  { 15, "u_6", 0, EXT_OUT, 1, 1, 1 },

  { 16, "u_2", 0, EXT_OUT, 1, 1, 1 },

  { 17, "u_3", 0, EXT_OUT, 1, 1, 1 },

  { 18, "pwm_1", 0, EXT_OUT, 1, 1, 1 },

  { 19, "Observer output /eta_hat output/x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 20, "Observer output /eta_hat output/y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 21, "Observer output /eta_hat output/psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 22, "Observer output /nu_hat output/u_hat", 0, EXT_OUT, 1, 1, 1 },

  { 23, "Observer output /nu_hat output/v_hat", 0, EXT_OUT, 1, 1, 1 },

  { 24, "Observer output /nu_hat output/r_hat", 0, EXT_OUT, 1, 1, 1 },

  { 25, "Observer output /nu_dot_hat output/u_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 26, "Observer output /nu_dot_hat output/v_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 27, "Observer output /nu_dot_hat output/r_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 28, "Observer output /b_hat output/b_x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 29, "Observer output /b_hat output/b_y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 30, "Observer output /b_hat output/b_psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 31, "tau_actual", 0, EXT_OUT, 3, 3, 1 },

  { 32, "Control/DP Controller/eta_tilde", 0, EXT_OUT, 3, 3, 1 },

  { 33, "Guidance/eta_des", 0, EXT_OUT, 3, 3, 1 },

  { 34, "Thruster control /Thruster 1/Propeller Hydrodynamics/Control_test_Pa",
    0, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 0.01, 0 }
};

int32_t NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static const char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "ctrl_TAPM";
static const char* NI_CompiledModelVersion = "1.190";
static const char* NI_CompiledModelDateTime = "Thu Apr 20 19:54:33 2017";
static const char* NI_builder DataSection(".NIVS.builder") =
  "NI Model Framework 2015.0.1.0 (2015 f1) for Simulink Coder 8.8 (R2015a)";
static const char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2015.0.1.0";

/*========================================================================*
 * Function: NIRT_GetBuildInfo
 *
 * Abstract:
 *	Get the DLL versioning etc information.
 *
 * Output Parameters:
 *	detail	: String containing model build information.
 *	len		: the build info string length. If a value of "-1" is specified, the minimum buffer size of "detail" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetBuildInfo(char* detail, int32_t* len)
{
  int32_t msgLength = 0;
  char *msgBuffer = NULL;

  /* Message */
  const char msg[] =
    "%s\nModel Name: %s\nModel Version: %s\nVeriStand Model Framework Version: %s\nCompiled On: %s";

  /* There are no console properties to set for VxWorks, because the console is simply serial output data.
     Just do printf for VxWorks and ignore all console properties. */
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  /* Print to screen */
  printf("\n*******************************************************************************\n");
  msgLength = printf(msg, NI_builder, NI_CompiledModelName,
                     NI_CompiledModelVersion, NI_BuilderVersion,
                     NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len == -1) {
    /* Return the required minimum buffer size */
    *len = msgLength;
  } else {
    /* allocate the buffer */
    msgBuffer = (char*)calloc(msgLength + 1, sizeof(char));
    sprintf (msgBuffer, msg, NI_builder, NI_CompiledModelName,
             NI_CompiledModelVersion, NI_BuilderVersion,
             NI_CompiledModelDateTime);
    if (*len >= msgLength) {
      *len = msgLength + 1;
    }

    /* Copy into external buffer */
    strncpy(detail, msgBuffer, *len);

    /* Release memory */
    free(msgBuffer);
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSignalSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	index		: index of the signal (in/out)
 *	ID			: ID of signal to be looked up (in), ID of signal at index (out)
 *	ID_len		: length of input ID(in), length of ID (out)
 *	bnlen		: length of buffer blkname (in), length of output blkname (out)
 *	snlen		: length of buffer signame (in), length of output signame (out)
 *
 * Output Parameters:
 *	blkname		: Name of the source block for the signal
 *	portnum		: port number of the block that is the source of the signal (0 indexed)
 *	signame		: Name of the signal
 *	datatype	: same as with parameters. Currently assuming all data to be double.
 *	dims		: The port's dimension of length 'numdims'.
 *	numdims		: the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error(if sigidx == -1, number of signals)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSignalSpec(int32_t* sidx, char* ID, int32_t* ID_len,
  char* blkname, int32_t *bnlen,
  int32_t *portnum, char* signame, int32_t *snlen, int32_t *dattype, int32_t*
  dims, int32_t* numdim)
{
  int32_t sigidx = *sidx;
  int32_t i = 0;
  char *addr = NULL;
  char *IDblk = 0;
  int32_t IDport = 0;
  if (sigidx < 0) {
    /* check if ID has been specified. */
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0)) {
      /* parse ID into blkname and port */
      addr = strrchr(ID, ':');
      if (addr == NULL) {
        return NI_SigListSize;
      }

      /* Calculate the char offset into the string after the port */
      i = addr - ID;

      /* malformed ID */
      if (i<=0) {
        return NI_SigListSize;
      }

      IDblk = ID;
      IDport = atoi(ID+i+1);

      /* lookup the table for matching ID */
      for (i=0; i<NI_SigListSize; i++) {
        /* 11 to accomodate ':','/', port number and null character */
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname) + 11, sizeof(char));
        if (strlen(NI_SigList[i].signalname)>0) {
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        } else {
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        }

        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1)) {
          break;
        }

        free(tempID);
      }

      if (i < NI_SigListSize) {
        sigidx = *sidx = i;
      } else {
        return NI_SigListSize;
      }
    } else {
      // no index or ID specified.
      return NI_SigListSize;
    }
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID != NULL) {
      // no need for return string to be null terminated!
      /* 11 to accomodate ':','/', port number and null character */
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0) {
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      } else {
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      }

      if ((int32_t)strlen(tempID)<*ID_len) {
        *ID_len = strlen(tempID);
      }

      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].blockname)<*bnlen) {
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      }

      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].signalname)<*snlen) {
        *snlen = strlen(NI_SigList[sigidx].signalname);
      }

      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum != NULL) {
      *portnum = NI_SigList[sigidx].portno;
    }

    if (dattype != NULL) {
      *dattype = NI_SigList[sigidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_SigList[sigidx].numofdims;
      } else if (dims != NULL) {
        for (i=0;i < *numdim; i++) {
          dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
        }
      }
    }

    return NI_OK;
  }

  return NI_SigListSize;
}

/*========================================================================*
 * Function: NIRT_GetParameterIndices
 *
 * Abstract:
 *	Returns an array of indices to tunable parameters
 *
 * Output Parameters:
 *	indices	: buffer to store the parameter indices of length "len"
 *	len		: returns the number of indices. If a value of "-1" is specified, the minimum buffer size of "indices" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterIndices(int32_t* indices, int32_t* len)
{
  int32_t i;
  if ((len == NULL) || (indices == NULL)) {
    return NI_ERROR;
  }

  if (*len == -1) {
    *len = NI_ParamListSize;
  } else {
    for (i=0; (i < NI_ParamListSize) && (i < *len); i++) {
      indices[i] = NI_ParamList[i].idx;
    }

    *len = i;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetParameterSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	paramidx	: index of the parameter(in/out). If a value of "-1" is specified, the parameter's ID is used instead
 *	ID			: ID of parameter to be looked up (in), ID of parameter at index (out)
 *	ID_len		: length of input ID (in), length of ID (out)
 *	pnlen		: length of buffer paramname(in), length of the returned paramname (out)
 *	numdim		: length of buffer dimension(in), length of output dimension (out). If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value
 *
 * Output Parameters:
 *	paramname	: Name of the parameter
 *	datatype	: datatype of the parameter (currently assuming 0: double, .. )
 *	dims		: array of dimensions with length 'numdim'
 *
 * Returns:
 *	NI_OK if no error (if paramidx == -1, number of tunable parameters)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterSpec(int32_t* pidx, char* ID, int32_t*
  ID_len, char* paramname, int32_t *pnlen,
  int32_t *dattype, int32_t* dims, int32_t* numdim)
{
  int32_t i = 0;
  int32_t paramidx = *pidx;
  if (paramidx < 0) {
    // check if ID has been specified.
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0) ) {
      // lookup the table for matching ID
      for (i=0; i < NI_ParamListSize; i++) {
        if (strcmp(ID,NI_ParamList[i].paramname) == 0) {
          /* found matching string */
          break;
        }
      }

      if (i < NI_ParamListSize) {
        /* note the index into the rtParamAttribs */
        paramidx = *pidx = i;
      } else {
        return NI_ParamListSize;
      }
    } else {
      // no index or ID specified.
      return NI_ParamListSize;
    }
  }

  if ((paramidx >= 0) && (paramidx<NI_ParamListSize)) {
    if (ID != NULL) {
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *ID_len) {
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname != NULL) {
      /* no need for return string to be null terminated! */
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *pnlen) {
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype != NULL) {
      *dattype = NI_ParamList[paramidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_ParamList[paramidx].numofdims;
      } else if (dims != NULL) {
        for (i = 0; i < *numdim; i++) {
          dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset + i];
        }
      }
    }

    return NI_OK;
  }

  return NI_ParamListSize;
}

/*========================================================================*
 * Function: NIRT_GetExtIOSpec
 *
 * Abstract:
 *	Returns the model's inport or outport specification
 *
 * Input Parameters:
 *	index	: index of the task
 *
 * Output Parameters:
 *	idx		: idx of the IO.
 *	name	: Name of the IO block
 *	tid		: task id
 *	type	: EXT_IN or EXT_OUT
 *	dims	: The port's dimension of length 'numdims'.
 *	numdims : the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns
 *	NI_OK if no error. (if index == -1, return number of tasks in the model)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetExtIOSpec(int32_t index, int32_t *idx, char* name,
  int32_t* tid, int32_t *type, int32_t *dims, int32_t* numdims)
{
  if (index == -1) {
    return NI_ExtListSize;
  }

  if (idx != NULL) {
    *idx = NI_ExtList[index].idx;
  }

  if (name != NULL) {
    int32_t sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid != NULL) {
    *tid = NI_ExtList[index].TID;
  }

  if (type != NULL) {
    *type = NI_ExtList[index].type;
  }

  if (numdims != NULL) {
    if (*numdims == -1) {
      *numdims = 2;
    } else if (numdims != NULL) {
      /* Return port dimensions */
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    }
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NI_ProbeOneSignal
 *
 * Abstract:
 *		Helper function to probe one	signal. baseaddr must NOT be VIRTUAL_SIG
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
static int32_t NI_ProbeOneSignal(int32_t idx, double *value, int32_t len,
  int32_t *count, int32_t vOffset, int32_t vLength)
{
  char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ?
                      S->ModelData.blockIO : S->ModelData.inputs) + (uintptr_t)
    NI_SigList[idx].addr;
  int32_t subindex = (vLength == -1) ? 0 : vOffset;
  int32_t sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength +
    vOffset);
  while ((subindex < sublength) && (*count < len))
    value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++, NI_SigList[idx]
      .datatype, NI_SigList[idx].IsComplex);
  return *count;
}

/*========================================================================*
 * Function: NIRT_ProbeSignals
 *
 * Abstract:
 *	returns the latest signal values.
 *
 * Input Parameters:
 *	sigindices	: list of signal indices to be probed.
 *	numsigs		: length of sigindices array.
 *
 *		NOTE: (Implementation detail) the sigindices array that is passed in is delimited by a value of -1.
 *		Thus the # of valid indices in the sigindices table is min(numsigs, index of value -1) - 1.
 *		Reason for subtracting 1, the first index in the array is used for bookkeeping and should be copied
 *		into the 0th index in the signal values buffer.
 *		Also, the 1st index in the signal values buffer should contain the current timestamp. Hence valid
 *		signal data should be filled in starting from index 2. Any non-scalar signals should be added to the
 *		buffer in row-order.
 *
 * Input/Output Parameters
 *	num			: (in) length of sigvalues buffer (out) number of values returned in the buffer
 *
 * Output Parameters:
 *	value		: array of signal values
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_ProbeSignals(int32_t* sigindices, int32_t numsigs,
  double* value, int32_t* len)
{
  int32_t i = 0;
  int32_t idx = 0;
  int32_t count = 0;
  if (!SITexportglobals.inCriticalSection) {
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  }

  /* Get the index to the first signal */
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  /* Get the second and other signals */
  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0) {
      break;
    }

    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        int32_t vidx = NI_VirtualBlockSources[NI_SigList[idx].addr];
        NI_ProbeOneSignal(vidx, value, *len, &count, 0, -1);
      } else {
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
      }
    }
  }

  *len = count;
  return count;
}

int32_t NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &ctrl_TAPM_P, sizeof(P_ctrl_TAPM_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_TAPM_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_TAPM_T));
  return NI_OK;
}

static int32_t NI_SetParamTxStatus = NI_OK;

/*========================================================================*
 * Function: NIRT_SetParameter
 *
 * Abstract:
 *	Set parameter value. Called either in scheduler loop or a background loop.
 *
 * Input Parameters:
 *	index	: index of the parameter (as specified in Parameter Information)
 *	subindex: index in the flattened array, if parameter is n-D array
 *	val		: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetParameter(int32_t index, int32_t subindex, double
  value)
{
  char* ptr = NULL;

  /* Check bounds */
  if (index >= NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* Commit parameter values */
  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_TAPM_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0) {
        /* No values to commit */
        return NI_OK;
      } else {
        SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                           1);
        WriteSideDirtyFlag = 0;
        return NI_ERROR;
      }
    }

    /* If an error occurred and we have values to commit, then save to the write side and return error */
    if (NI_SetParamTxStatus == NI_ERROR) {
      // fail the transaction.
      // copy old list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1) {
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_ctrl_TAPM_T));
      }

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /* If we have values to commit, then save to the write-side */
    if (WriteSideDirtyFlag == 1) {
      S->ModelData.defaultParam = (double *)&rtParameter[1-READSIDE];
      WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
      READSIDE = 1 - READSIDE;
      SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
      ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

      // Copy back the newly set parameters to the writeside.
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_TAPM_T));
      WriteSideDirtyFlag = 0;
    }

    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex>=NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_TAPM_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr,subindex,value,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_SetVectorParameter
 *
 * Abstract:
 *	Sets the value to a parameter array.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	paramvalues	: array of values to set
 *	paramlength	: Length of parameter values.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetVectorParameter( uint32_t index, const double
  * paramvalues, uint32_t paramlength)
{
  uint32_t i = 0;
  int32_t retval = NI_OK;
  char* ptr = NULL;

  /* verify that index is within bounds*/
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength != (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* If we have pending modified parameters, then copy to write-side */
  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_ctrl_TAPM_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char*)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  while (i < paramlength) {
    /* Convert the incoming double datatype to the parameter's internal datatype and update value */
    retval = retval & NIRT_SetValueByDataType(ptr, i, paramvalues[i],
      NI_ParamList[index].datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

/*========================================================================*
 * Function: NIRT_SetScalarParameterInline
 *
 * Abstract:
 *	Sets the value to a parameter immediately without the need of a commit request.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	subindex	: offset of the element within the parameter
 *	paramvalue	: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetScalarParameterInline( uint32_t index, uint32_t
  subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex >= (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr,subindex,paramvalue,NI_ParamList[index].
    datatype,NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_GetParameter
 *
 * Abstract:
 *	Get the current value of a parameter.
 *
 * Input Parameters:
 *	index	: index of the parameter
 *	subindex: element index into the flattened array if an array
 *
 * Output Parameters:
 *	val		: value of the parameter
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameter(int32_t index, int32_t subindex, double
  *value)
{
  char* ptr = NULL;

  /* Check index boundaries */
  if (index >= NI_ParamListSize || index < 0 || (subindex>=NI_ParamList[index].
       width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;

  /* Convert the parameter's internal datatype to double and return its value */
  *value = NIRT_GetValueByDataType(ptr,subindex,NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetVectorParameter
 *
 * Abstract:
 *	Get the current value of a vector parameter.
 *
 * Input Parameters:
 *	index: index of the parameter
 *	paramLength: length of the parameter
 *
 * Output Parameters:
 *	paramValues: an array of the parameter's value
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetVectorParameter(uint32_t index, double* paramvalues,
  uint32_t paramlength)
{
  char* ptr = NULL;
  uint32_t i = 0;
  if (index >= (uint32_t)NI_ParamListSize || index < 0 || (paramlength !=
       (uint32_t)NI_ParamList[index].width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  while (i<paramlength) {
    /* Convert the parameter's internal datatype to double and return its value */
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSimState(int32_t* numContStates, char
  * contStatesNames, double* contStates, int32_t* numDiscStates, char
  * discStatesNames, double* discStates, int32_t* numClockTicks, char
  * clockTicksNames, int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  int32_t ForEach_itr1;
  if ((numContStates != NULL) && (numDiscStates != NULL) && (numClockTicks !=
       NULL)) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 33;
      *numDiscStates = 2290.0;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE_g),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE_g),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE_g),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator3_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator3_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator3_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_c),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_p),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_p");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_k),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_k");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_n),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_n");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_cd),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_cd");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_h),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_h");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_a),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_a");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_a),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_a");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_a),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_a");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE_c),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE_c),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE_c),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_e),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_g),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_i),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_i");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_l),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_n4),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_n4");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_gj),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_gj");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE,
        count, 26, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_f, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_f");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_fu, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_fu");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states, 0, 44, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states, 1, 44, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.UD_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_b, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_b");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_d, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_h, 0, 44, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_h, 1, 44, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_h");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.UD_DSTATE_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_m, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_m");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_n, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_n");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_no, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_no");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_j, 0, 44, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_j, 1, 44, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_i, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.UD_DSTATE_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_e, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_i, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_i, 0, 44, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_i, 1, 44, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_i");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_n4, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.UD_DSTATE_n4");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_h0, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_h0");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_j, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_a, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb, 0, 44, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb, 1, 44, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_m, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.UD_DSTATE_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_dt, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_dt");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_dv, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_dv");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_m, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_l, 0, 44, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_l, 1, 44, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_l");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_l, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.UD_DSTATE_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_o");
    for (count = 0; count < 144; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_fv,
        count, 31, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_fv");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay1_DSTATE,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay1_DSTATE");
    }

    for (count = 0; count < 144; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_mc,
        count, 31, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_mc");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay1_DSTATE_f,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay1_DSTATE_f");
    }

    for (count = 0; count < 144; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_dd,
        count, 31, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_dd");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay1_DSTATE_j,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay1_DSTATE_j");
    }

    for (count = 0; count < 144; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_fg,
        count, 31, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_fg");
    }

    for (count = 0; count < 12; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay1_DSTATE_i,
        count, 29, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay1_DSTATE_i");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.x_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.y_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.psi_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.w_d_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.w_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.w_d_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.w_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.w_d_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.w_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.zeta_psi_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.zeta_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.zeta_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.zeta_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.zeta_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.zeta_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.psi_ref_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.psi_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.x_ref_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.x_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.y_ref_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.y_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_3_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_4_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_5_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_6_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_6_DWORK1");
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_l,
        count, 26, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_l");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.Angle_controller_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.Angle_controller_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_g, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_d, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_e, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_g4, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_g4");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_c, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_a, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_a");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.x_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.y_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.psi_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.v_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.v_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.r_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.r_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_dot_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.v_dot_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.v_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.r_dot_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.r_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.b_x_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.b_x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.b_y_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.b_y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.b_psi_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.b_psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK1, 0,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK1, 1,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK1, 2,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_tilde_DWORK1, 0,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_tilde_DWORK1, 1,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_tilde_DWORK1, 2,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_des_DWORK1, 0,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_des_DWORK1, 1,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_des_DWORK1, 2,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.X_oqus_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.X_oqus_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Y_oqus_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Y_oqus_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Z_oqus_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Z_oqus_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.roll_oqus_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.roll_oqus_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pitch_oqus_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pitch_oqus_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.yaw_oqus_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.yaw_oqus_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.PrevY, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.PrevY");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Memory_PreviousInput,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_ec, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_ec");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.Control_test_Pa_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.Control_test_Pa_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.PrevY_e, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.PrevY_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.Memory_PreviousInput_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.Memory_PreviousInput_n");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_ln, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_ln");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_e, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.PrevY_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.PrevY_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.Memory_PreviousInput_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.Memory_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_lw, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_lw");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_hh, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_hh");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.PrevY_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.PrevY_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.Memory_PreviousInput_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.Memory_PreviousInput_a");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_ct, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_ct");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.PrevY_j, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.PrevY_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.Memory_PreviousInput_b, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.Memory_PreviousInput_b");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_i, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h4, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h4");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.PrevY_h, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.PrevY_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.Memory_PreviousInput_a4, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.Memory_PreviousInput_a4");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_j, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_cw, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_cw");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AX1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AX1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AY1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AY1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AZ1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AZ1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RX1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RX1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RY1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RY1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RZ1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RZ1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_V1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_V1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AX2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AX2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AY2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AY2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AZ2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AZ2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RX2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RX2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RY2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RY2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RZ2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RZ2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_V2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_V2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AX3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AX3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AY3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AY3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AZ3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AZ3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RX3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RX3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RY3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RY3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RZ3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RZ3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_V3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_V3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AX4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AX4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AY4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AY4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AZ4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AZ4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RX4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RX4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RY4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RY4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RZ4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RZ4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_V4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_V4_DWORK1");
    for (count = 0; count < 28; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Memory_PreviousInput_l, count, 27, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Memory_PreviousInput_l");
    }

    for (count = 0; count < 36; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.MatrixMultiply_DWORK4, count, 36, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.MatrixMultiply_DWORK4");
    }

    for (count = 0; count < 5; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Memory2_PreviousInput, count, 39, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Memory2_PreviousInput");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Memory3_PreviousInput, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Memory3_PreviousInput");
    }

    for (count = 0; count < 36; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.MatrixMultiply_DWORK4_a, count, 36, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.MatrixMultiply_DWORK4_a");
    }

    for (count = 0; count < 5; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Memory2_PreviousInput_d, count, 39, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Memory2_PreviousInput_d");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Memory3_PreviousInput_p, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Memory3_PreviousInput_p");
    }

    for (count = 0; count < 36; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.MatrixMultiply_DWORK4_f, count, 36, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.MatrixMultiply_DWORK4_f");
    }

    for (count = 0; count < 5; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Memory2_PreviousInput_n, count, 39, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Memory2_PreviousInput_n");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Memory3_PreviousInput_j, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Memory3_PreviousInput_j");
    }

    for (count = 0; count < 36; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.MatrixMultiply_DWORK4_e, count, 36, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.MatrixMultiply_DWORK4_e");
    }

    for (count = 0; count < 5; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Memory2_PreviousInput_c, count, 39, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Memory2_PreviousInput_c");
    }

    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Memory3_PreviousInput_k, count, 38, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Memory3_PreviousInput_k");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile_PWORK, 0, 11,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile_PWORK_a, 0,
      11, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile_PWORK_a");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile1_PWORK, 0, 11,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile1_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile2_PWORK, 0, 11,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile2_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile3_PWORK, 0, 11,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile3_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile4_PWORK, 0, 11,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile4_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile5_PWORK, 0, 11,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile5_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile6_PWORK, 0, 11,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile6_PWORK");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile7_PWORK, 0, 11,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile7_PWORK");
    for (count = 0; count < 5; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Median_Index,
        count, 40, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Median_Index");
    }

    for (count = 0; count < 5; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Median1_Index,
        count, 40, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Median1_Index");
    }

    for (count = 0; count < 5; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Median_Index_f,
        count, 40, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Median_Index_f");
    }

    for (count = 0; count < 5; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Median1_Index_p,
        count, 40, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Median1_Index_p");
    }

    for (count = 0; count < 5; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Median_Index_j,
        count, 40, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Median_Index_j");
    }

    for (count = 0; count < 5; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Median1_Index_j,
        count, 40, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Median1_Index_j");
    }

    for (count = 0; count < 5; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Median_Index_d,
        count, 40, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Median_Index_d");
    }

    for (count = 0; count < 5; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Median1_Index_d,
        count, 40, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Median1_Index_d");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.Integrator1_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.Integrator1_IWORK.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.Integrator_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.Integrator_IWORK.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile_IWORK.Count,
      0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.ToFile_IWORK.Decimation, 0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.ToFile_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile_IWORK_e.Count,
      0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile_IWORK_e.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.ToFile_IWORK_e.Decimation, 0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.ToFile_IWORK_e.Decimation");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile1_IWORK.Count,
      0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile1_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.ToFile1_IWORK.Decimation, 0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.ToFile1_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile2_IWORK.Count,
      0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile2_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.ToFile2_IWORK.Decimation, 0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.ToFile2_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile3_IWORK.Count,
      0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile3_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.ToFile3_IWORK.Decimation, 0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.ToFile3_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile4_IWORK.Count,
      0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile4_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.ToFile4_IWORK.Decimation, 0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.ToFile4_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile5_IWORK.Count,
      0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile5_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.ToFile5_IWORK.Decimation, 0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.ToFile5_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile6_IWORK.Count,
      0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile6_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.ToFile6_IWORK.Decimation, 0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.ToFile6_IWORK.Decimation");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.ToFile7_IWORK.Count,
      0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.ToFile7_IWORK.Count");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.ToFile7_IWORK.Decimation, 0, 41, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.ToFile7_IWORK.Decimation");
    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_x_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_x_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_y_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_y_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_psi_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_psi_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_psi_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_psi_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_x_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_x_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_y_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_y_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_psi_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_psi_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_x_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_x_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_y_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_y_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.x_m_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.x_m_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.y_m_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.y_m_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.psi_m_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.w_d_x_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.w_d_x_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.w_d_y_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.w_d_y_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.w_d_psi_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.w_d_psi_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.zeta_psi_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.zeta_psi_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.zeta_x_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.zeta_x_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.zeta_y_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.zeta_y_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.psi_ref_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.psi_ref_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.x_ref_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.x_ref_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.y_ref_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.y_ref_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_5_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_6_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_m,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_m");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Angle_controller_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Angle_controller_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_j,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_j");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_o,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_o");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_i,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_i");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_k,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_k");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_a,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_a");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_mm,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_mm");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm1_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm2_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm3_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm4_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm5_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm6_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_5_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_6_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_5_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_6_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_1_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_4_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_5_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_6_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_2_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_3_DWORK2, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.x_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.x_hat_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.y_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.y_hat_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.psi_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.psi_hat_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.v_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.v_hat_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.r_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.r_hat_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_dot_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_dot_hat_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.v_dot_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.v_dot_hat_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.r_dot_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.r_dot_hat_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.b_x_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.b_x_hat_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.b_y_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.b_y_hat_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.b_psi_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.b_psi_hat_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_actual_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_tilde_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_tilde_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_des_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_des_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.X_oqus_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.X_oqus_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Y_oqus_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Y_oqus_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Z_oqus_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Z_oqus_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.roll_oqus_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.roll_oqus_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pitch_oqus_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pitch_oqus_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.yaw_oqus_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.yaw_oqus_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_n,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_n");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Control_test_Pa_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Control_test_Pa_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_e,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_e");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_l,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_l");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_mb,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_mb");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_nu,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_nu");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_f,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_f");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AX1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AX1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AY1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AY1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AZ1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AZ1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RX1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RX1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RY1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RY1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RZ1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RZ1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_V1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_V1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AX2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AX2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AY2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AY2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AZ2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AZ2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RX2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RX2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RY2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RY2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RZ2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RZ2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_V2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_V2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AX3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AX3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AY3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AY3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AZ3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AZ3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RX3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RX3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RY3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RY3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RZ3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RZ3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_V3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_V3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AX4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AX4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AY4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AY4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_AZ4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_AZ4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RX4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RX4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RY4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RY4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_RZ4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_RZ4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.IMU_V4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.IMU_V4_DWORK2");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_DSTATE, 0,
         0, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_DSTATE");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.CoreSubsys[ForEach_itr1].Delay_DSTATE, 0, 0, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.CoreSubsys[ForEach_itr1].Delay_DSTATE");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_PrevRese,
         0, 2, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_PrevRese");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_IC_LOADI,
         0, 3, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_IC_LOADI");
    }
  }

  if ((clockTicks != NULL) && (clockTicksNames != NULL)) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_SetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetSimState(double* contStates, double* discStates,
  int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  int32_t ForEach_itr1;
  if (contStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE_g), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE_g), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE_g), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator3_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator3_CSTATE), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator3_CSTATE), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_c), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_p), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_k), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_n), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_cd), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_h), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_a), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_a), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_a), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE_c), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE_c), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE_c), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_e), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_g), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_i), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_l), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_n4), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_gj), 0,
      contStates[idx++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE, count, discStates[idx
        ++], 26, 0);
    }

    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_f, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_fu, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states, 0,
      discStates[idx++], 44, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states, 1,
      discStates[idx++], 44, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_b, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_d, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_h, 0,
      discStates[idx++], 44, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_h, 1,
      discStates[idx++], 44, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_n, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_n, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_no, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_j, 0,
      discStates[idx++], 44, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_j, 1,
      discStates[idx++], 44, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_i, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_e, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_i, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_i, 0,
      discStates[idx++], 44, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_i, 1,
      discStates[idx++], 44, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_n4, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_h0, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_j, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_a, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb, 0,
      discStates[idx++], 44, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb, 1,
      discStates[idx++], 44, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_m, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_dt, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_dv, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_m, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_l, 0,
      discStates[idx++], 44, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_l, 1,
      discStates[idx++], 44, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_l, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_o, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 144; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_fv, count,
        discStates[idx++], 31, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay1_DSTATE, count, discStates[idx
        ++], 29, 0);
    }

    for (count = 0; count < 144; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_mc, count,
        discStates[idx++], 31, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay1_DSTATE_f, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 144; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_dd, count,
        discStates[idx++], 31, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay1_DSTATE_j, count,
        discStates[idx++], 29, 0);
    }

    for (count = 0; count < 144; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_fg, count,
        discStates[idx++], 31, 0);
    }

    for (count = 0; count < 12; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay1_DSTATE_i, count,
        discStates[idx++], 29, 0);
    }

    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.x_m_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.y_m_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.psi_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.w_d_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.w_d_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.w_d_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.zeta_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.zeta_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.zeta_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.psi_ref_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.x_ref_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.y_ref_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_3_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_4_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_5_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_6_DWORK1, 0, discStates[idx
      ++], 0, 0);
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_l, count,
        discStates[idx++], 26, 0);
    }

    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Angle_controller_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_g, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_d, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_e, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_g4, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_c, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_a, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_4_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_5_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_6_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_2_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_3_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.x_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.y_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.psi_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.v_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.r_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_dot_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.v_dot_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.r_dot_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.b_x_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.b_y_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.b_psi_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK1, 2, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_tilde_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_tilde_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_tilde_DWORK1, 2, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_des_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_des_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_des_DWORK1, 2, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.X_oqus_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Y_oqus_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Z_oqus_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.roll_oqus_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.pitch_oqus_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.yaw_oqus_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.PrevY, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_ec, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Control_test_Pa_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.PrevY_e, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory_PreviousInput_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_ln, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_e, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.PrevY_o, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory_PreviousInput_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_lw, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_hh, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.PrevY_c, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory_PreviousInput_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_ct, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_c, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.PrevY_j, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory_PreviousInput_b, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_i, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_f, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h4, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.PrevY_h, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory_PreviousInput_a4, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_j, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_cw, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AX1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AY1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AZ1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RX1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RY1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RZ1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_V1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AX2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AY2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AZ2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RX2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RY2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RZ2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_V2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AX3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AY3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AZ3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RX3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RY3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RZ3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_V3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AX4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AY4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AZ4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RX4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RY4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RZ4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_V4_DWORK1, 0, discStates[idx++], 0,
      0);
    for (count = 0; count < 28; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory_PreviousInput_l, count,
        discStates[idx++], 27, 0);
    }

    for (count = 0; count < 36; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.MatrixMultiply_DWORK4, count,
        discStates[idx++], 36, 0);
    }

    for (count = 0; count < 5; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory2_PreviousInput, count,
        discStates[idx++], 39, 0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory3_PreviousInput, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 36; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.MatrixMultiply_DWORK4_a, count,
        discStates[idx++], 36, 0);
    }

    for (count = 0; count < 5; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory2_PreviousInput_d, count,
        discStates[idx++], 39, 0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory3_PreviousInput_p, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 36; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.MatrixMultiply_DWORK4_f, count,
        discStates[idx++], 36, 0);
    }

    for (count = 0; count < 5; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory2_PreviousInput_n, count,
        discStates[idx++], 39, 0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory3_PreviousInput_j, count,
        discStates[idx++], 38, 0);
    }

    for (count = 0; count < 36; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.MatrixMultiply_DWORK4_e, count,
        discStates[idx++], 36, 0);
    }

    for (count = 0; count < 5; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory2_PreviousInput_c, count,
        discStates[idx++], 39, 0);
    }

    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory3_PreviousInput_k, count,
        discStates[idx++], 38, 0);
    }

    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile_PWORK, 0, discStates[idx++], 11,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile_PWORK_a, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile1_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile2_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile3_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile4_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile5_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile6_PWORK, 0, discStates[idx++],
      11, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile7_PWORK, 0, discStates[idx++],
      11, 0);
    for (count = 0; count < 5; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Median_Index, count, discStates[idx
        ++], 40, 0);
    }

    for (count = 0; count < 5; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Median1_Index, count, discStates[idx
        ++], 40, 0);
    }

    for (count = 0; count < 5; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Median_Index_f, count,
        discStates[idx++], 40, 0);
    }

    for (count = 0; count < 5; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Median1_Index_p, count,
        discStates[idx++], 40, 0);
    }

    for (count = 0; count < 5; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Median_Index_j, count,
        discStates[idx++], 40, 0);
    }

    for (count = 0; count < 5; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Median1_Index_j, count,
        discStates[idx++], 40, 0);
    }

    for (count = 0; count < 5; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Median_Index_d, count,
        discStates[idx++], 40, 0);
    }

    for (count = 0; count < 5; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Median1_Index_d, count,
        discStates[idx++], 40, 0);
    }

    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Integrator1_IWORK.IcNeedsLoading, 0,
      discStates[idx++], 10, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Integrator_IWORK.IcNeedsLoading, 0,
      discStates[idx++], 10, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile_IWORK.Count, 0, discStates[idx
      ++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile_IWORK.Decimation, 0,
      discStates[idx++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile_IWORK_e.Count, 0,
      discStates[idx++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile_IWORK_e.Decimation, 0,
      discStates[idx++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile1_IWORK.Count, 0, discStates[idx
      ++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile1_IWORK.Decimation, 0,
      discStates[idx++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile2_IWORK.Count, 0, discStates[idx
      ++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile2_IWORK.Decimation, 0,
      discStates[idx++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile3_IWORK.Count, 0, discStates[idx
      ++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile3_IWORK.Decimation, 0,
      discStates[idx++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile4_IWORK.Count, 0, discStates[idx
      ++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile4_IWORK.Decimation, 0,
      discStates[idx++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile5_IWORK.Count, 0, discStates[idx
      ++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile5_IWORK.Decimation, 0,
      discStates[idx++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile6_IWORK.Count, 0, discStates[idx
      ++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile6_IWORK.Decimation, 0,
      discStates[idx++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile7_IWORK.Count, 0, discStates[idx
      ++], 41, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.ToFile7_IWORK.Decimation, 0,
      discStates[idx++], 41, 0);
    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_x_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_y_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_psi_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_psi_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_x_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_y_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_psi_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_x_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_y_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.x_m_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.y_m_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.psi_m_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.w_d_x_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.w_d_y_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.w_d_psi_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.zeta_psi_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.zeta_x_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.zeta_y_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.psi_ref_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.x_ref_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.y_ref_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_1_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_2_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_3_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_4_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_5_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_6_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_m, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Angle_controller_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_1_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_j, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_o, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_i, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_k, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_a, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_mm, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm1_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm2_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm3_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm4_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm5_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm6_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_2_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_3_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_4_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_5_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_2_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_6_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_3_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_4_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_5_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_6_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_1_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_4_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_5_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_6_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_2_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_3_DWORK2, count, discStates[idx++],
        25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_1_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.x_hat_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.y_hat_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.psi_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_hat_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.v_hat_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.r_hat_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_dot_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.v_dot_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.r_dot_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.b_x_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.b_y_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.b_psi_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_tilde_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_des_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.X_oqus_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Y_oqus_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Z_oqus_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.roll_oqus_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pitch_oqus_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.yaw_oqus_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_n, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Control_test_Pa_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_e, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_l, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_mb, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_nu, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_f, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AX1_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AY1_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AZ1_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RX1_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RY1_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RZ1_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_V1_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AX2_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AY2_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AZ2_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RX2_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RY2_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RZ2_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_V2_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AX3_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AY3_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AZ3_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RX3_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RY3_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RZ3_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_V3_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AX4_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AY4_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_AZ4_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RX4_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RY4_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_RZ4_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.IMU_V4_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.CoreSubsys[ForEach_itr1].
        DiscreteTimeIntegrator_DSTATE, 0, discStates[idx++], 0, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.CoreSubsys[ForEach_itr1].
        Delay_DSTATE, 0, discStates[idx++], 0, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.CoreSubsys[ForEach_itr1].
        DiscreteTimeIntegrator_PrevRese, 0, discStates[idx++], 2, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.CoreSubsys[ForEach_itr1].
        DiscreteTimeIntegrator_IC_LOADI, 0, discStates[idx++], 3, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_TAPM
