/*
 * ctrl_DP_basic.c
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

/* Block signals (auto storage) */
B_ctrl_DP_basic_T ctrl_DP_basic_B;

/* Continuous states */
X_ctrl_DP_basic_T ctrl_DP_basic_X;

/* Block states (auto storage) */
DW_ctrl_DP_basic_T ctrl_DP_basic_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_DP_basic_T ctrl_DP_basic_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_DP_basic_T ctrl_DP_basic_M_;
RT_MODEL_ctrl_DP_basic_T *const ctrl_DP_basic_M = &ctrl_DP_basic_M_;

/* Forward declaration for local functions */
static void ctrl_DP_basic_diag(const real_T v[6], real_T d[36]);
static real_T ctrl_DP_basic_eml_xnrm2(int32_T n, const real_T x[18], int32_T ix0);
static real_T ctrl_DP_basic_eml_xnrm2_l(int32_T n, const real_T x[6], int32_T
  ix0);
static void ctrl_DP_basic_eml_xaxpy_bs(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[18], int32_T iy0);
static void ctrl_DP_basic_eml_xaxpy_b(int32_T n, real_T a, const real_T x[18],
  int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_DP_basic_eml_xscal(real_T a, real_T x[9], int32_T ix0);
static void ctrl_DP_basic_eml_xscal_p(real_T a, real_T x[36], int32_T ix0);
static void ctrl_DP_basic_eml_xswap(real_T x[36], int32_T ix0, int32_T iy0);
static void ctrl_DP_basic_eml_xswap_c(real_T x[9], int32_T ix0, int32_T iy0);
static void ctrl_DP_basic_eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void ctrl_DP_basic_eml_xrot(real_T x[36], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void ctrl_DP_basic_eml_xrot_n(real_T x[9], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static real_T ctrl_DP_basic_eml_xdotc_od(int32_T n, const real_T x[36], int32_T
  ix0, const real_T y[36], int32_T iy0);
static void ctrl_DP_basic_eml_xaxpy_bsm3(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0);
static real_T ctrl_DP_basic_eml_xdotc_o(int32_T n, const real_T x[9], int32_T
  ix0, const real_T y[9], int32_T iy0);
static void ctrl_DP_basic_eml_xaxpy_bsm(int32_T n, real_T a, int32_T ix0, real_T
  y[9], int32_T iy0);
static real_T ctrl_DP_basic_eml_xdotc(int32_T n, const real_T x[18], int32_T ix0,
  const real_T y[18], int32_T iy0);
static void ctrl_DP_basic_eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y
  [18], int32_T iy0);
static void ctrl_DP_basic_eml_xgesvd(const real_T A[18], real_T U[9], real_T S[3],
  real_T V[18]);
static void ctrl_DP_basic_svd(const real_T A[18], real_T U[9], real_T S[9],
  real_T V[18]);
static void ctrl_DP_basic_isfinite(const real_T x[9], boolean_T b[9]);
static real_T ctrl_DP_basic_eml_xnrm2_l5(int32_T n, const real_T x[36], int32_T
  ix0);
static real_T ctrl_DP_basic_eml_xnrm2_l53(int32_T n, const real_T x[12], int32_T
  ix0);
static void ctrl_DP_basic_eml_xaxpy_bsm3y5a(int32_T n, real_T a, const real_T x
  [3], int32_T ix0, real_T y[36], int32_T iy0);
static void ctrl_DP_basic_eml_xaxpy_bsm3y5(int32_T n, real_T a, const real_T x
  [36], int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_DP_basic_eml_xscal_pi(real_T a, real_T x[144], int32_T ix0);
static void ctrl_DP_basic_eml_xswap_c1(real_T x[144], int32_T ix0, int32_T iy0);
static void ctrl_DP_basic_eml_xrot_ne(real_T x[144], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static real_T ctrl_DP_basic_eml_xdotc_odar(int32_T n, const real_T x[144],
  int32_T ix0, const real_T y[144], int32_T iy0);
static void ctrl_DP_basi_eml_xaxpy_bsm3y5a5(int32_T n, real_T a, int32_T ix0,
  real_T y[144], int32_T iy0);
static real_T ctrl_DP_basic_eml_xdotc_oda(int32_T n, const real_T x[36], int32_T
  ix0, const real_T y[36], int32_T iy0);
static void ctrl_DP_basic_eml_xaxpy_bsm3y(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0);
static void ctrl_DP_basic_eml_xgesvd_p(const real_T A[36], real_T U[9], real_T
  S[3], real_T V[36]);
static void ctrl_DP_basic_svd_m(const real_T A[36], real_T U[9], real_T S[9],
  real_T V[36]);
static void ctrl_DP_basic_abs(const real_T x[2], real_T y[2]);
static void ctrl_DP_basic_cosd(real_T *x);
static void ctrl_DP_basic_sind(real_T *x);

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 21;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_DP_basic_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  ctrl_DP_basic_output();
  ctrl_DP_basic_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  ctrl_DP_basic_output();
  ctrl_DP_basic_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  ctrl_DP_basic_output();
  ctrl_DP_basic_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S24>/MATLAB Function'
 *    '<S26>/MATLAB Function'
 */
void ctrl_DP_basic_MATLABFunction(real_T rtu_K_p1, real_T rtu_K_p1_e, real_T
  rtu_K_p1_f, B_MATLABFunction_ctrl_DP_basi_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function': '<S27>:1' */
  /* '<S27>:1:4' */
  memset(&localB->K_p[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S27>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_p[0] = rtu_K_p1;
  localB->K_p[4] = rtu_K_p1_e;
  localB->K_p[8] = rtu_K_p1_f;
}

/*
 * Output and update for atomic system:
 *    '<S24>/MATLAB Function1'
 *    '<S26>/MATLAB Function1'
 */
void ctrl_DP_basic_MATLABFunction1(real_T rtu_K_i1, real_T rtu_K_i1_m, real_T
  rtu_K_i1_n, B_MATLABFunction1_ctrl_DP_bas_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function1': '<S28>:1' */
  /* '<S28>:1:4' */
  memset(&localB->K_i[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S28>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_i[0] = rtu_K_i1;
  localB->K_i[4] = rtu_K_i1_m;
  localB->K_i[8] = rtu_K_i1_n;
}

/*
 * Output and update for atomic system:
 *    '<S24>/MATLAB Function2'
 *    '<S26>/MATLAB Function2'
 */
void ctrl_DP_basic_MATLABFunction2(real_T rtu_K_d1, real_T rtu_K_d1_p, real_T
  rtu_K_d1_i, B_MATLABFunction2_ctrl_DP_bas_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function2': '<S29>:1' */
  /* '<S29>:1:4' */
  memset(&localB->K_d[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S29>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_d[0] = rtu_K_d1;
  localB->K_d[4] = rtu_K_d1_p;
  localB->K_d[8] = rtu_K_d1_i;
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
 *    '<S61>/Actual Force and Torque'
 *    '<S71>/Actual Force and Torque'
 *    '<S81>/Actual Force and Torque'
 *    '<S91>/Actual Force and Torque'
 *    '<S101>/Actual Force and Torque'
 *    '<S111>/Actual Force and Torque'
 */
void ctrl_DP_ba_ActualForceandTorque(real_T rtu_n, real_T rtu_Kq, real_T rtu_Kt,
  real_T rtu_Ktr, real_T rtu_Kqr, real_T rtu_Rho, real_T rtu_D, real_T rtu_eps_c,
  real_T rtu_env, B_ActualForceandTorque_ctrl_D_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_0;

  /* MATLAB Function 'Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque': '<S64>:1' */
  /* '<S64>:1:3' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S64>:1:4' */
  /* '<S64>:1:5' */
  /* '<S64>:1:7' */
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

  /* '<S64>:1:8' */
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
 *    '<S65>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S75>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S85>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S95>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S105>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S115>/Core controller: Torque,Power and Combined Torque//Power'
 */
void CorecontrollerTorquePowerandCom(real_T rtu_k_cc, real_T rtu_p_cc, real_T
  rtu_r_cc, real_T rtu_n, real_T rtu_K_t0, real_T rtu_K_q0, real_T rtu_D, real_T
  rtu_Tr, real_T rtu_eps, real_T rtu_rho, real_T rtu_eps_c, real_T rtu_K_t0r,
  real_T rtu_K_q0r, B_CorecontrollerTorquePoweran_T *localB)
{
  real_T Qcq;
  real_T lambda_c;
  real_T K_TC;
  real_T rtu_Tr_0;

  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power': '<S70>:1' */
  /* '<S70>:1:4' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /* '<S70>:1:5' */
  K_TC = (1.0 - lambda_c) * rtu_K_t0r + rtu_K_t0 * lambda_c;

  /* '<S70>:1:6' */
  lambda_c = (1.0 - lambda_c) * rtu_K_q0r + rtu_K_q0 * lambda_c;

  /* '<S70>:1:7' */
  Qcq = lambda_c / K_TC * rtu_D * rtu_Tr;

  /* '<S70>:1:8' */
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
    (rtu_rho) * rtu_D * rt_powd_snf(K_TC, 1.5) * fabs(rtu_n + rtu_eps));

  /* '<S70>:1:9' */
  K_TC = exp(rt_powd_snf(fabs(rtu_p_cc * rtu_n), rtu_r_cc) * -rtu_k_cc);

  /* '<S70>:1:11' */
  localB->Qcc = (1.0 - K_TC) * lambda_c + K_TC * Qcq;
  localB->Qcq = Qcq;
  localB->Qcp = lambda_c;
}

/*
 * Output and update for atomic system:
 *    '<S63>/Supervisor'
 *    '<S73>/Supervisor'
 *    '<S83>/Supervisor'
 *    '<S93>/Supervisor'
 *    '<S103>/Supervisor'
 *    '<S113>/Supervisor'
 */
void ctrl_DP_basic_Supervisor(real_T rtu_control, real_T rtu_input, real_T rtu_n,
  B_Supervisor_ctrl_DP_basic_T *localB)
{
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Supervisor': '<S68>:1' */
  /* '<S68>:1:2' */
  localB->u = 1.0;
  if (rtu_control == 1.0) {
    /* '<S68>:1:3' */
    if (rtu_input == 1.0) {
      /* '<S68>:1:4' */
      /* '<S68>:1:5' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S68>:1:6' */
      /* '<S68>:1:7' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S68>:1:8' */
      /* '<S68>:1:9' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S68>:1:10' */
      /* '<S68>:1:11' */
      localB->u = 4.0;
    } else {
      /* '<S68>:1:13' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 2.0) {
    /* '<S68>:1:17' */
    if (rtu_input == 1.0) {
      /* '<S68>:1:18' */
      /* '<S68>:1:19' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S68>:1:20' */
      /* '<S68>:1:21' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S68>:1:22' */
      /* '<S68>:1:23' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S68>:1:24' */
      /* '<S68>:1:25' */
      localB->u = 4.0;
    } else {
      /* '<S68>:1:27' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 3.0) {
    /* '<S68>:1:31' */
    if (rtu_input == 1.0) {
      /* '<S68>:1:32' */
      /* '<S68>:1:33' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S68>:1:34' */
      /* '<S68>:1:35' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S68>:1:36' */
      /* '<S68>:1:37' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S68>:1:38' */
      /* '<S68>:1:39' */
      localB->u = 4.0;
    } else {
      /* '<S68>:1:41' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 4.0) {
    /* '<S68>:1:45' */
    if (rtu_input == 1.0) {
      /* '<S68>:1:46' */
      /* '<S68>:1:47' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S68>:1:48' */
      /* '<S68>:1:49' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S68>:1:50' */
      /* '<S68>:1:51' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S68>:1:52' */
      /* '<S68>:1:53' */
      localB->u = 4.0;
    } else {
      /* '<S68>:1:55' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 5.0) {
    /* '<S68>:1:59' */
    if (rtu_input == 1.0) {
      /* '<S68>:1:60' */
      /* '<S68>:1:61' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S68>:1:62' */
      /* '<S68>:1:63' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S68>:1:64' */
      /* '<S68>:1:65' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S68>:1:66' */
      /* '<S68>:1:67' */
      localB->u = 4.0;
    } else {
      /* '<S68>:1:69' */
      localB->u = 5.0;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S73>/MATLAB Function'
 *    '<S83>/MATLAB Function'
 *    '<S93>/MATLAB Function'
 *    '<S103>/MATLAB Function'
 */
void ctrl_DP_basic_MATLABFunction_d(real_T rtu_Td, real_T rtu_K_t0, real_T
  rtu_K_t0r, real_T rtu_rho, real_T rtu_D, real_T rtu_eps_c, real_T rtu_n_r,
  B_MATLABFunction_ctrl_DP_ba_l_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_r_0;
  real_T rtu_Td_0;

  /* MATLAB Function 'Thruster control /Thruster 2/Thruster control/MATLAB Function': '<S77>:1' */
  /* '<S77>:1:5' */
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

  /* '<S77>:1:7' */
  lambda_c = tanh(rtu_eps_c * rtu_Td_0 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S77>:1:8' */
  /* '<S77>:1:10' */
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

/*
 * Output and update for atomic system:
 *    '<S73>/Torque limit'
 *    '<S83>/Torque limit'
 *    '<S93>/Torque limit'
 *    '<S103>/Torque limit'
 *    '<S113>/Torque limit'
 */
void ctrl_DP_basic_Torquelimit(real_T rtu_Q_max, real_T rtu_P_max, real_T
  rtu_Q_c0, real_T rtu_n, B_Torquelimit_ctrl_DP_basic_T *localB)
{
  real_T Q_cm[3];
  real_T mtmp;
  int32_T ixstart;
  int32_T ix;
  boolean_T exitg1;
  real_T rtu_Q_c0_0;

  /* MATLAB Function 'Thruster control /Thruster 2/Thruster control/Torque limit': '<S79>:1' */
  /* '<S79>:1:3' */
  Q_cm[0] = fabs(rtu_Q_c0);
  Q_cm[1] = rtu_Q_max;
  Q_cm[2] = rtu_P_max / fabs(6.2831853071795862 * rtu_n);

  /* '<S79>:1:5' */
  ixstart = 1;
  mtmp = Q_cm[0];
  if (rtIsNaN(Q_cm[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 4)) {
      ixstart = ix;
      if (!rtIsNaN(Q_cm[ix - 1])) {
        mtmp = Q_cm[ix - 1];
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 3) {
    while (ixstart + 1 < 4) {
      if (Q_cm[ixstart] < mtmp) {
        mtmp = Q_cm[ixstart];
      }

      ixstart++;
    }
  }

  if (rtu_Q_c0 < 0.0) {
    rtu_Q_c0_0 = -1.0;
  } else if (rtu_Q_c0 > 0.0) {
    rtu_Q_c0_0 = 1.0;
  } else if (rtu_Q_c0 == 0.0) {
    rtu_Q_c0_0 = 0.0;
  } else {
    rtu_Q_c0_0 = rtu_Q_c0;
  }

  localB->Q_c = rtu_Q_c0_0 * mtmp;
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_diag(const real_T v[6], real_T d[36])
{
  int32_T j;
  memset(&d[0], 0, 36U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    d[j + 6 * j] = v[j];
  }
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_basic_eml_xnrm2(int32_T n, const real_T x[18], int32_T ix0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_basic_eml_xnrm2_l(int32_T n, const real_T x[6], int32_T
  ix0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xaxpy_bs(int32_T n, real_T a, const real_T x[3],
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xaxpy_b(int32_T n, real_T a, const real_T x[18],
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xscal(real_T a, real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xscal_p(real_T a, real_T x[36], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 5; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xswap(real_T x[36], int32_T ix0, int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xswap_c(real_T x[9], int32_T ix0, int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xrot(real_T x[36], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xrot_n(real_T x[9], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_basic_eml_xdotc_od(int32_T n, const real_T x[36], int32_T
  ix0, const real_T y[36], int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xaxpy_bsm3(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_basic_eml_xdotc_o(int32_T n, const real_T x[9], int32_T
  ix0, const real_T y[9], int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xaxpy_bsm(int32_T n, real_T a, int32_T ix0, real_T
  y[9], int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_basic_eml_xdotc(int32_T n, const real_T x[18], int32_T ix0,
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y
  [18], int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xgesvd(const real_T A[18], real_T U[9], real_T S[3],
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
  ztest0 = ctrl_DP_basic_eml_xnrm2(3, b_A, 1);
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
      ctrl_DP_basic_eml_xaxpy(3, -(ctrl_DP_basic_eml_xdotc(3, b_A, 1, b_A, qp1jj
        + 1) / b_A[0]), 1, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (i = 0; i + 1 < 4; i++) {
    U[i] = b_A[i];
  }

  ztest0 = ctrl_DP_basic_eml_xnrm2_l(5, e, 2);
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
      ctrl_DP_basic_eml_xaxpy_b(2, e[i], b_A, 3 * i + 2, work, 2);
    }

    for (i = 1; i + 1 < 7; i++) {
      ctrl_DP_basic_eml_xaxpy_bs(2, -e[i] / e[1], work, 2, b_A, 3 * i + 2);
    }
  }

  for (i = 1; i + 1 < 7; i++) {
    Vf[i] = e[i];
  }

  apply_transform = false;
  ztest0 = ctrl_DP_basic_eml_xnrm2(2, b_A, 5);
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
      ctrl_DP_basic_eml_xaxpy(2, -(ctrl_DP_basic_eml_xdotc(2, b_A, 5, b_A, qp1jj
        + 1) / b_A[4]), 5, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (i = 1; i + 1 < 4; i++) {
    U[i + 3] = b_A[i + 3];
  }

  ztest0 = ctrl_DP_basic_eml_xnrm2_l(4, e, 3);
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
      ctrl_DP_basic_eml_xaxpy_b(1, e[i], b_A, 3 * i + 3, work, 3);
    }

    for (i = 2; i + 1 < 7; i++) {
      ctrl_DP_basic_eml_xaxpy_bs(1, -e[i] / e[2], work, 3, b_A, 3 * i + 3);
    }
  }

  for (i = 2; i + 1 < 7; i++) {
    Vf[i + 6] = e[i];
  }

  for (kase = 3; kase + 1 < 7; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = ctrl_DP_basic_eml_xnrm2_l(3, e, 4);
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
        ctrl_DP_basic_eml_xaxpy_bsm(3 - qs, -(ctrl_DP_basic_eml_xdotc_o(3 - qs,
          U, iter + 1, U, qp1jj) / U[iter]), iter + 1, U, qp1jj);
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
        ctrl_DP_basic_eml_xaxpy_bsm3(5 - qs, -(ctrl_DP_basic_eml_xdotc_od(5 - qs,
          Vf, i, Vf, qp1jj) / Vf[i - 1]), i, Vf, qp1jj);
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
    ctrl_DP_basic_eml_xscal(ztest0, U, 1);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[1] *= ztest0;
    ctrl_DP_basic_eml_xscal_p(ztest0, Vf, 7);
  }

  e[0] = b;
  b = e[1];
  if (s[1] != 0.0) {
    ztest = fabs(s[1]);
    ztest0 = s[1] / ztest;
    s[1] = ztest;
    b = e[1] / ztest0;
    ctrl_DP_basic_eml_xscal(ztest0, U, 4);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[2] = b_A[8] * ztest0;
    ctrl_DP_basic_eml_xscal_p(ztest0, Vf, 13);
  }

  e[1] = b;
  b = e[2];
  if (s[2] != 0.0) {
    ztest = fabs(s[2]);
    ztest0 = s[2] / ztest;
    s[2] = ztest;
    b = e[2] / ztest0;
    ctrl_DP_basic_eml_xscal(ztest0, U, 7);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[3] = 0.0 * ztest0;
    ctrl_DP_basic_eml_xscal_p(ztest0, Vf, 19);
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
        ctrl_DP_basic_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        if (kase + 1 > q + 1) {
          f = e[kase - 1] * -b;
          e[kase - 1] *= ztest;
        }

        ctrl_DP_basic_eml_xrot(Vf, 1 + 6 * kase, 1 + 6 * (m + 1), ztest, b);
      }
      break;

     case 2:
      f = e[q - 1];
      e[q - 1] = 0.0;
      for (kase = q; kase + 1 <= m + 2; kase++) {
        ztest0 = s[kase];
        ctrl_DP_basic_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        f = -b * e[kase];
        e[kase] *= ztest;
        ctrl_DP_basic_eml_xrot_n(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest, b);
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
        ctrl_DP_basic_eml_xrotg(&f, &b, &ztest0, &ztest);
        if (kase > q + 1) {
          e[kase - 2] = f;
        }

        f = s[kase - 1] * ztest0 + e[kase - 1] * ztest;
        e[kase - 1] = e[kase - 1] * ztest0 - s[kase - 1] * ztest;
        b = ztest * s[kase];
        s[kase] *= ztest0;
        ctrl_DP_basic_eml_xrot(Vf, 1 + 6 * (kase - 1), 1 + 6 * kase, ztest0,
          ztest);
        ctrl_DP_basic_eml_xrotg(&f, &b, &ztest0, &ztest);
        s[kase - 1] = f;
        f = e[kase - 1] * ztest0 + ztest * s[kase];
        s[kase] = e[kase - 1] * -ztest + ztest0 * s[kase];
        b = ztest * e[kase];
        e[kase] *= ztest0;
        if (kase < 3) {
          ctrl_DP_basic_eml_xrot_n(U, 1 + 3 * (kase - 1), 1 + 3 * kase, ztest0,
            ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_DP_basic_eml_xscal_p(-1.0, Vf, 1 + 6 * q);
      }

      i = q + 1;
      while ((q + 1 < 4) && (s[q] < s[i])) {
        ztest = s[q];
        s[q] = s[i];
        s[i] = ztest;
        ctrl_DP_basic_eml_xswap(Vf, 1 + 6 * q, 1 + 6 * (q + 1));
        if (q + 1 < 3) {
          ctrl_DP_basic_eml_xswap_c(U, 1 + 3 * q, 1 + 3 * (q + 1));
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_svd(const real_T A[18], real_T U[9], real_T S[9],
  real_T V[18])
{
  real_T s[3];
  ctrl_DP_basic_eml_xgesvd(A, U, s, V);
  memset(&S[0], 0, 9U * sizeof(real_T));
  S[0] = s[0];
  S[4] = s[1];
  S[8] = s[2];
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_isfinite(const real_T x[9], boolean_T b[9])
{
  int32_T i;
  for (i = 0; i < 9; i++) {
    b[i] = ((!rtIsInf(x[i])) && (!rtIsNaN(x[i])));
  }
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_basic_eml_xnrm2_l5(int32_T n, const real_T x[36], int32_T
  ix0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_basic_eml_xnrm2_l53(int32_T n, const real_T x[12], int32_T
  ix0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xaxpy_bsm3y5a(int32_T n, real_T a, const real_T x
  [3], int32_T ix0, real_T y[36], int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xaxpy_bsm3y5(int32_T n, real_T a, const real_T x
  [36], int32_T ix0, real_T y[3], int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xscal_pi(real_T a, real_T x[144], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 11; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xswap_c1(real_T x[144], int32_T ix0, int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xrot_ne(real_T x[144], int32_T ix0, int32_T iy0,
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_basic_eml_xdotc_odar(int32_T n, const real_T x[144],
  int32_T ix0, const real_T y[144], int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basi_eml_xaxpy_bsm3y5a5(int32_T n, real_T a, int32_T ix0,
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_basic_eml_xdotc_oda(int32_T n, const real_T x[36], int32_T
  ix0, const real_T y[36], int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xaxpy_bsm3y(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_eml_xgesvd_p(const real_T A[36], real_T U[9], real_T
  S[3], real_T V[36])
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
  ztest0 = ctrl_DP_basic_eml_xnrm2_l5(3, b_A, 1);
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
      ctrl_DP_basic_eml_xaxpy_bsm3y(3, -(ctrl_DP_basic_eml_xdotc_oda(3, b_A, 1,
        b_A, qp1jj + 1) / b_A[0]), 1, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 0; qp1 + 1 < 4; qp1++) {
    U[qp1] = b_A[qp1];
  }

  ztest0 = ctrl_DP_basic_eml_xnrm2_l53(11, e, 2);
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
      ctrl_DP_basic_eml_xaxpy_bsm3y5(2, e[qp1], b_A, 3 * qp1 + 2, work, 2);
    }

    for (qp1 = 1; qp1 + 1 < 13; qp1++) {
      ctrl_DP_basic_eml_xaxpy_bsm3y5a(2, -e[qp1] / e[1], work, 2, b_A, 3 * qp1 +
        2);
    }
  }

  for (qp1 = 1; qp1 + 1 < 13; qp1++) {
    Vf[qp1] = e[qp1];
  }

  apply_transform = false;
  ztest0 = ctrl_DP_basic_eml_xnrm2_l5(2, b_A, 5);
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
      ctrl_DP_basic_eml_xaxpy_bsm3y(2, -(ctrl_DP_basic_eml_xdotc_oda(2, b_A, 5,
        b_A, qp1jj + 1) / b_A[4]), 5, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 1; qp1 + 1 < 4; qp1++) {
    U[qp1 + 3] = b_A[qp1 + 3];
  }

  ztest0 = ctrl_DP_basic_eml_xnrm2_l53(10, e, 3);
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
      ctrl_DP_basic_eml_xaxpy_bsm3y5(1, e[qp1], b_A, 3 * qp1 + 3, work, 3);
    }

    for (qp1 = 2; qp1 + 1 < 13; qp1++) {
      ctrl_DP_basic_eml_xaxpy_bsm3y5a(1, -e[qp1] / e[2], work, 3, b_A, 3 * qp1 +
        3);
    }
  }

  for (qp1 = 2; qp1 + 1 < 13; qp1++) {
    Vf[qp1 + 12] = e[qp1];
  }

  for (kase = 3; kase + 1 < 13; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = ctrl_DP_basic_eml_xnrm2_l53(9, e, 4);
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
        ctrl_DP_basic_eml_xaxpy_bsm(3 - qs, -(ctrl_DP_basic_eml_xdotc_o(3 - qs,
          U, iter + 1, U, qp1jj) / U[iter]), iter + 1, U, qp1jj);
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
        ctrl_DP_basi_eml_xaxpy_bsm3y5a5(11 - qs, -(ctrl_DP_basic_eml_xdotc_odar
          (11 - qs, Vf, qp1, Vf, qp1jj) / Vf[qp1 - 1]), qp1, Vf, qp1jj);
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
    ctrl_DP_basic_eml_xscal(ztest0, U, 1);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[1] *= ztest0;
    ctrl_DP_basic_eml_xscal_pi(ztest0, Vf, 13);
  }

  e[0] = b;
  b = e[1];
  if (s[1] != 0.0) {
    ztest = fabs(s[1]);
    ztest0 = s[1] / ztest;
    s[1] = ztest;
    b = e[1] / ztest0;
    ctrl_DP_basic_eml_xscal(ztest0, U, 4);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[2] = b_A[8] * ztest0;
    ctrl_DP_basic_eml_xscal_pi(ztest0, Vf, 25);
  }

  e[1] = b;
  b = e[2];
  if (s[2] != 0.0) {
    ztest = fabs(s[2]);
    ztest0 = s[2] / ztest;
    s[2] = ztest;
    b = e[2] / ztest0;
    ctrl_DP_basic_eml_xscal(ztest0, U, 7);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[3] = 0.0 * ztest0;
    ctrl_DP_basic_eml_xscal_pi(ztest0, Vf, 37);
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
        ctrl_DP_basic_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        if (kase + 1 > q + 1) {
          f = e[kase - 1] * -b;
          e[kase - 1] *= ztest;
        }

        ctrl_DP_basic_eml_xrot_ne(Vf, 1 + 12 * kase, 1 + 12 * (m + 1), ztest, b);
      }
      break;

     case 2:
      f = e[q - 1];
      e[q - 1] = 0.0;
      for (kase = q; kase + 1 <= m + 2; kase++) {
        ztest0 = s[kase];
        ctrl_DP_basic_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        f = -b * e[kase];
        e[kase] *= ztest;
        ctrl_DP_basic_eml_xrot_n(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest, b);
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
        ctrl_DP_basic_eml_xrotg(&f, &b, &ztest0, &ztest);
        if (kase > q + 1) {
          e[kase - 2] = f;
        }

        f = s[kase - 1] * ztest0 + e[kase - 1] * ztest;
        e[kase - 1] = e[kase - 1] * ztest0 - s[kase - 1] * ztest;
        b = ztest * s[kase];
        s[kase] *= ztest0;
        ctrl_DP_basic_eml_xrot_ne(Vf, 1 + 12 * (kase - 1), 1 + 12 * kase, ztest0,
          ztest);
        ctrl_DP_basic_eml_xrotg(&f, &b, &ztest0, &ztest);
        s[kase - 1] = f;
        f = e[kase - 1] * ztest0 + ztest * s[kase];
        s[kase] = e[kase - 1] * -ztest + ztest0 * s[kase];
        b = ztest * e[kase];
        e[kase] *= ztest0;
        if (kase < 3) {
          ctrl_DP_basic_eml_xrot_n(U, 1 + 3 * (kase - 1), 1 + 3 * kase, ztest0,
            ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_DP_basic_eml_xscal_pi(-1.0, Vf, 1 + 12 * q);
      }

      qp1 = q + 1;
      while ((q + 1 < 4) && (s[q] < s[qp1])) {
        ztest = s[q];
        s[q] = s[qp1];
        s[qp1] = ztest;
        ctrl_DP_basic_eml_xswap_c1(Vf, 1 + 12 * q, 1 + 12 * (q + 1));
        if (q + 1 < 3) {
          ctrl_DP_basic_eml_xswap_c(U, 1 + 3 * q, 1 + 3 * (q + 1));
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_svd_m(const real_T A[36], real_T U[9], real_T S[9],
  real_T V[36])
{
  real_T s[3];
  ctrl_DP_basic_eml_xgesvd_p(A, U, s, V);
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_abs(const real_T x[2], real_T y[2])
{
  y[0] = fabs(x[0]);
  y[1] = fabs(x[1]);
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_cosd(real_T *x)
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_basic_sind(real_T *x)
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
void ctrl_DP_basic_output(void)
{
  /* local block i/o variables */
  real_T rtb_Sum_n;
  real_T rtb_Sum_nhi;
  real_T rtb_Sum_hm;
  real_T rtb_Sum_c;
  real_T rtb_Sum_h2;
  real_T rtb_T_r;
  real_T rtb_T_r_f;
  real_T rtb_sys[12];
  real_T rtb_Integrator2[3];
  real_T rtb_ImpSel_InsertedFor_reset_at;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T alpha[6];
  real_T K[6];
  real_T T_surge[6];
  real_T T_sway[6];
  real_T T_yaw[6];
  real_T S_singular_cross[9];
  real_T c1[2];
  real_T U_singular[9];
  real_T V_singular[18];
  real_T b_V_singular[36];
  real_T varargin_1[2];
  int32_T ixstart;
  int32_T b_ixstart;
  static const int8_T d[12] = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 };

  static const int8_T e[12] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };

  boolean_T f[9];
  boolean_T exitg11;
  int32_T p3;
  real_T Q_cm[3];
  real_T rtb_Saturation1;
  real_T rtb_Row1;
  real_T rtb_psi_dot;
  real_T rtb_Row1_o;
  real_T rtb_Sum_nu[3];
  real_T rtb_ImpAsg_InsertedFor_Out2_at_[6];
  real_T rtb_DiscreteTransferFcn;
  real_T rtb_Sum_m;
  real_T rtb_Delay;
  real_T rtb_Delay_a;
  real_T rtb_Delay_k;
  real_T rtb_Delay_j;
  real_T rtb_Delay_an;
  real_T rtb_Delay_ac;
  real_T rtb_TmpSignalConversionAtSFunct[12];
  real_T rtb_TmpSignalConversionAtSFu_pa[3];
  real_T rtb_Out2_CoreSubsysCanOut;
  real_T rtb_y_n[9];
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
  real_T T_surge_0[18];
  real_T T_surge_1[18];
  real_T tmp_0[3];
  real_T tmp_1[9];
  real_T tmp_2[9];
  int32_T b_data[9];
  int32_T c_data[9];
  real_T rtb_output_idx_0;
  real_T rtb_output_idx_2;
  real_T rtb_output_idx_4;
  real_T rtb_output_idx_6;
  real_T rtb_output_idx_8;
  real_T rtb_output_idx_10;
  real_T rtb_TmpSignalConversionAtSFun_0;
  real_T rtb_TmpSignalConversionAtSFun_1;
  real_T rtb_TmpSignalConversionAtSFun_2;
  real_T rtb_TmpSignalConversionAtSFun_3;
  real_T rtb_TmpSignalConversionAtSFun_4;
  real_T rtb_TmpSignalConversionAtSFun_5;
  real_T rtb_TmpSignalConversionAtSFun_6;
  real_T rtb_TmpSignalConversionAtSFun_7;
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* set solver stop time */
    if (!(ctrl_DP_basic_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_DP_basic_M->solverInfo,
                            ((ctrl_DP_basic_M->Timing.clockTickH0 + 1) *
        ctrl_DP_basic_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_DP_basic_M->solverInfo,
                            ((ctrl_DP_basic_M->Timing.clockTick0 + 1) *
        ctrl_DP_basic_M->Timing.stepSize0 + ctrl_DP_basic_M->Timing.clockTickH0 *
        ctrl_DP_basic_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_DP_basic_M)) {
    ctrl_DP_basic_M->Timing.t[0] = rtsiGetT(&ctrl_DP_basic_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    if (((ctrl_DP_basic_B.reset > 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRese <= 0)) ||
        ((ctrl_DP_basic_B.reset <= 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRese == 1))) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE =
        ctrl_DP_basic_P.DiscreteTimeIntegrator_IC;
    }

    ctrl_DP_basic_B.DiscreteTimeIntegrator =
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE;

    /* End of DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */

    /* MATLAB Function: '<S61>/Actual Force and Torque' incorporates:
     *  Constant: '<S54>/Losses (placeholder)'
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/D'
     *  Constant: '<S8>/Kq'
     *  Constant: '<S8>/Kqr'
     *  Constant: '<S8>/Kt'
     *  Constant: '<S8>/Ktr'
     *  Constant: '<S8>/Rho'
     */
    ctrl_DP_ba_ActualForceandTorque(ctrl_DP_basic_B.DiscreteTimeIntegrator,
      ctrl_DP_basic_P.Kq, ctrl_DP_basic_P.Kt, ctrl_DP_basic_P.Ktr,
      ctrl_DP_basic_P.Kqr, ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.D,
      ctrl_DP_basic_P.eps_c, ctrl_DP_basic_P.Lossesplaceholder_Value,
      &ctrl_DP_basic_B.sf_ActualForceandTorque);

    /* DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */
    if (((ctrl_DP_basic_B.reset_n > 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_p <= 0)) ||
        ((ctrl_DP_basic_B.reset_n <= 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_p == 1))) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_h =
        ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_m;
    }

    ctrl_DP_basic_B.DiscreteTimeIntegrator_m =
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_h;

    /* End of DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */

    /* MATLAB Function: '<S71>/Actual Force and Torque' incorporates:
     *  Constant: '<S55>/Losses (placeholder)'
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/D'
     *  Constant: '<S8>/Kq'
     *  Constant: '<S8>/Kqr'
     *  Constant: '<S8>/Kt'
     *  Constant: '<S8>/Ktr'
     *  Constant: '<S8>/Rho'
     */
    ctrl_DP_ba_ActualForceandTorque(ctrl_DP_basic_B.DiscreteTimeIntegrator_m,
      ctrl_DP_basic_P.Kq, ctrl_DP_basic_P.Kt, ctrl_DP_basic_P.Ktr,
      ctrl_DP_basic_P.Kqr, ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.D,
      ctrl_DP_basic_P.eps_c, ctrl_DP_basic_P.Lossesplaceholder_Value_a,
      &ctrl_DP_basic_B.sf_ActualForceandTorque_o);

    /* DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */
    if (((ctrl_DP_basic_B.reset_d > 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_n <= 0)) ||
        ((ctrl_DP_basic_B.reset_d <= 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_n == 1))) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_d =
        ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_p;
    }

    ctrl_DP_basic_B.DiscreteTimeIntegrator_p =
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_d;

    /* End of DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */

    /* MATLAB Function: '<S81>/Actual Force and Torque' incorporates:
     *  Constant: '<S56>/Losses (placeholder)'
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/D'
     *  Constant: '<S8>/Kq'
     *  Constant: '<S8>/Kqr'
     *  Constant: '<S8>/Kt'
     *  Constant: '<S8>/Ktr'
     *  Constant: '<S8>/Rho'
     */
    ctrl_DP_ba_ActualForceandTorque(ctrl_DP_basic_B.DiscreteTimeIntegrator_p,
      ctrl_DP_basic_P.Kq, ctrl_DP_basic_P.Kt, ctrl_DP_basic_P.Ktr,
      ctrl_DP_basic_P.Kqr, ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.D,
      ctrl_DP_basic_P.eps_c, ctrl_DP_basic_P.Lossesplaceholder_Value_m,
      &ctrl_DP_basic_B.sf_ActualForceandTorque_c);

    /* DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
    if (((ctrl_DP_basic_B.reset_l > 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_b <= 0)) ||
        ((ctrl_DP_basic_B.reset_l <= 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_b == 1))) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_g =
        ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_l;
    }

    ctrl_DP_basic_B.DiscreteTimeIntegrator_j =
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_g;

    /* End of DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */

    /* MATLAB Function: '<S91>/Actual Force and Torque' incorporates:
     *  Constant: '<S57>/Losses (placeholder)'
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/D'
     *  Constant: '<S8>/Kq'
     *  Constant: '<S8>/Kqr'
     *  Constant: '<S8>/Kt'
     *  Constant: '<S8>/Ktr'
     *  Constant: '<S8>/Rho'
     */
    ctrl_DP_ba_ActualForceandTorque(ctrl_DP_basic_B.DiscreteTimeIntegrator_j,
      ctrl_DP_basic_P.Kq, ctrl_DP_basic_P.Kt, ctrl_DP_basic_P.Ktr,
      ctrl_DP_basic_P.Kqr, ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.D,
      ctrl_DP_basic_P.eps_c, ctrl_DP_basic_P.Lossesplaceholder_Value_i,
      &ctrl_DP_basic_B.sf_ActualForceandTorque_f);

    /* DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
    if (((ctrl_DP_basic_B.reset_e > 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_e <= 0)) ||
        ((ctrl_DP_basic_B.reset_e <= 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_e == 1))) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_f =
        ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_me;
    }

    ctrl_DP_basic_B.DiscreteTimeIntegrator_c =
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_f;

    /* End of DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */

    /* MATLAB Function: '<S101>/Actual Force and Torque' incorporates:
     *  Constant: '<S58>/Losses (placeholder)'
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/D'
     *  Constant: '<S8>/Kq'
     *  Constant: '<S8>/Kqr'
     *  Constant: '<S8>/Kt'
     *  Constant: '<S8>/Ktr'
     *  Constant: '<S8>/Rho'
     */
    ctrl_DP_ba_ActualForceandTorque(ctrl_DP_basic_B.DiscreteTimeIntegrator_c,
      ctrl_DP_basic_P.Kq, ctrl_DP_basic_P.Kt, ctrl_DP_basic_P.Ktr,
      ctrl_DP_basic_P.Kqr, ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.D,
      ctrl_DP_basic_P.eps_c, ctrl_DP_basic_P.Lossesplaceholder_Value_md,
      &ctrl_DP_basic_B.sf_ActualForceandTorque_fi);

    /* DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
    if (((ctrl_DP_basic_B.reset_a > 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_m <= 0)) ||
        ((ctrl_DP_basic_B.reset_a <= 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_m == 1))) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hl =
        ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_e;
    }

    ctrl_DP_basic_B.DiscreteTimeIntegrator_d =
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hl;

    /* End of DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */

    /* MATLAB Function: '<S111>/Actual Force and Torque' incorporates:
     *  Constant: '<S59>/Losses (placeholder)'
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/D'
     *  Constant: '<S8>/Kq'
     *  Constant: '<S8>/Kqr'
     *  Constant: '<S8>/Kt'
     *  Constant: '<S8>/Ktr'
     *  Constant: '<S8>/Rho'
     */
    ctrl_DP_ba_ActualForceandTorque(ctrl_DP_basic_B.DiscreteTimeIntegrator_d,
      ctrl_DP_basic_P.Kq, ctrl_DP_basic_P.Kt, ctrl_DP_basic_P.Ktr,
      ctrl_DP_basic_P.Kqr, ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.D,
      ctrl_DP_basic_P.eps_c, ctrl_DP_basic_P.Lossesplaceholder_Value_h,
      &ctrl_DP_basic_B.sf_ActualForceandTorque_a);

    /* MATLAB Function: '<S52>/MATLAB Function' incorporates:
     *  Constant: '<S52>/Constant12'
     *  SignalConversion: '<S60>/TmpSignal ConversionAt SFunction Inport1'
     */
    /* MATLAB Function 'Thruster control /Subsystem/MATLAB Function': '<S60>:1' */
    if (ctrl_DP_basic_P.Constant12_Value == 1.0) {
      /* '<S60>:1:3' */
      /* '<S60>:1:4' */
      rtb_output_idx_0 = 0.0;
      rtb_output_idx_2 = 0.0;
      rtb_output_idx_4 = 0.0;
      rtb_output_idx_6 = 0.0;
      rtb_output_idx_8 = 0.0;
      rtb_output_idx_10 = 0.0;
    } else {
      /* '<S60>:1:6' */
      rtb_output_idx_0 = ctrl_DP_basic_B.sf_ActualForceandTorque.Ta;
      rtb_output_idx_2 = ctrl_DP_basic_B.sf_ActualForceandTorque_o.Ta;
      rtb_output_idx_4 = ctrl_DP_basic_B.sf_ActualForceandTorque_c.Ta;
      rtb_output_idx_6 = ctrl_DP_basic_B.sf_ActualForceandTorque_f.Ta;
      rtb_output_idx_8 = ctrl_DP_basic_B.sf_ActualForceandTorque_fi.Ta;
      rtb_output_idx_10 = ctrl_DP_basic_B.sf_ActualForceandTorque_a.Ta;
    }

    /* End of MATLAB Function: '<S52>/MATLAB Function' */

    /* Saturate: '<S52>/Saturation 1' */
    if (rtb_output_idx_0 > ctrl_DP_basic_P.Max_thrust) {
      rtb_Saturation1 = ctrl_DP_basic_P.Max_thrust;
    } else if (rtb_output_idx_0 < -ctrl_DP_basic_P.Max_thrust) {
      rtb_Saturation1 = -ctrl_DP_basic_P.Max_thrust;
    } else {
      rtb_Saturation1 = rtb_output_idx_0;
    }

    /* End of Saturate: '<S52>/Saturation 1' */

    /* Polyval: '<S52>/pwm thruster 1' */
    ctrl_DP_basic_B.pwmthruster1 = ctrl_DP_basic_P.thrust_to_pwm_coeff[0];
    for (ixstart = 0; ixstart < 5; ixstart++) {
      ctrl_DP_basic_B.pwmthruster1 = ctrl_DP_basic_B.pwmthruster1 *
        rtb_Saturation1 + ctrl_DP_basic_P.thrust_to_pwm_coeff[ixstart + 1];
    }

    /* End of Polyval: '<S52>/pwm thruster 1' */
  }

  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* Saturate: '<S52>/Saturation 2' */
    if (rtb_output_idx_2 > ctrl_DP_basic_P.Max_thrust) {
      rtb_Saturation1 = ctrl_DP_basic_P.Max_thrust;
    } else if (rtb_output_idx_2 < -ctrl_DP_basic_P.Max_thrust) {
      rtb_Saturation1 = -ctrl_DP_basic_P.Max_thrust;
    } else {
      rtb_Saturation1 = rtb_output_idx_2;
    }

    /* End of Saturate: '<S52>/Saturation 2' */

    /* Polyval: '<S52>/pwm thruster 2' */
    ctrl_DP_basic_B.pwmthruster2 = ctrl_DP_basic_P.thrust_to_pwm_coeff[0];
    for (ixstart = 0; ixstart < 5; ixstart++) {
      ctrl_DP_basic_B.pwmthruster2 = ctrl_DP_basic_B.pwmthruster2 *
        rtb_Saturation1 + ctrl_DP_basic_P.thrust_to_pwm_coeff[ixstart + 1];
    }

    /* End of Polyval: '<S52>/pwm thruster 2' */
  }

  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* Saturate: '<S52>/Saturation 3' */
    if (rtb_output_idx_4 > ctrl_DP_basic_P.Max_thrust) {
      rtb_Saturation1 = ctrl_DP_basic_P.Max_thrust;
    } else if (rtb_output_idx_4 < -ctrl_DP_basic_P.Max_thrust) {
      rtb_Saturation1 = -ctrl_DP_basic_P.Max_thrust;
    } else {
      rtb_Saturation1 = rtb_output_idx_4;
    }

    /* End of Saturate: '<S52>/Saturation 3' */

    /* Polyval: '<S52>/pwm thruster 3' */
    ctrl_DP_basic_B.pwmthruster3 = ctrl_DP_basic_P.thrust_to_pwm_coeff[0];
    for (ixstart = 0; ixstart < 5; ixstart++) {
      ctrl_DP_basic_B.pwmthruster3 = ctrl_DP_basic_B.pwmthruster3 *
        rtb_Saturation1 + ctrl_DP_basic_P.thrust_to_pwm_coeff[ixstart + 1];
    }

    /* End of Polyval: '<S52>/pwm thruster 3' */
  }

  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* Saturate: '<S52>/Saturation 4' */
    if (rtb_output_idx_6 > ctrl_DP_basic_P.Max_thrust) {
      rtb_Saturation1 = ctrl_DP_basic_P.Max_thrust;
    } else if (rtb_output_idx_6 < -ctrl_DP_basic_P.Max_thrust) {
      rtb_Saturation1 = -ctrl_DP_basic_P.Max_thrust;
    } else {
      rtb_Saturation1 = rtb_output_idx_6;
    }

    /* End of Saturate: '<S52>/Saturation 4' */

    /* Polyval: '<S52>/pwm thruster 4' */
    ctrl_DP_basic_B.pwmthruster4 = ctrl_DP_basic_P.thrust_to_pwm_coeff[0];
    for (ixstart = 0; ixstart < 5; ixstart++) {
      ctrl_DP_basic_B.pwmthruster4 = ctrl_DP_basic_B.pwmthruster4 *
        rtb_Saturation1 + ctrl_DP_basic_P.thrust_to_pwm_coeff[ixstart + 1];
    }

    /* End of Polyval: '<S52>/pwm thruster 4' */

    /* Saturate: '<S52>/Saturation 5' */
    if (rtb_output_idx_8 > ctrl_DP_basic_P.Max_thrust) {
      rtb_Saturation1 = ctrl_DP_basic_P.Max_thrust;
    } else if (rtb_output_idx_8 < -ctrl_DP_basic_P.Max_thrust) {
      rtb_Saturation1 = -ctrl_DP_basic_P.Max_thrust;
    } else {
      rtb_Saturation1 = rtb_output_idx_8;
    }

    /* End of Saturate: '<S52>/Saturation 5' */

    /* Polyval: '<S52>/pwm thruster 5' */
    ctrl_DP_basic_B.pwmthruster5 = ctrl_DP_basic_P.thrust_to_pwm_coeff[0];
    for (ixstart = 0; ixstart < 5; ixstart++) {
      ctrl_DP_basic_B.pwmthruster5 = ctrl_DP_basic_B.pwmthruster5 *
        rtb_Saturation1 + ctrl_DP_basic_P.thrust_to_pwm_coeff[ixstart + 1];
    }

    /* End of Polyval: '<S52>/pwm thruster 5' */
  }

  /* MATLAB Function: '<S24>/MATLAB Function' */
  ctrl_DP_basic_MATLABFunction(ctrl_DP_basic_B.K_p_x, ctrl_DP_basic_B.K_p_y,
    ctrl_DP_basic_B.K_p_psi, &ctrl_DP_basic_B.sf_MATLABFunction_g);

  /* Saturate: '<S16>/Saturation' incorporates:
   *  Fcn: '<S12>/yaw angle'
   */
  if (ctrl_DP_basic_B.psi > ctrl_DP_basic_P.Saturation_UpperSat) {
    rtb_Saturation1 = ctrl_DP_basic_P.Saturation_UpperSat;
  } else if (ctrl_DP_basic_B.psi < ctrl_DP_basic_P.Saturation_LowerSat) {
    rtb_Saturation1 = ctrl_DP_basic_P.Saturation_LowerSat;
  } else {
    rtb_Saturation1 = ctrl_DP_basic_B.psi;
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* Signum: '<S16>/Sign' */
  if (rtb_Saturation1 < 0.0) {
    rtb_TmpSignalConversionAtSFun_6 = -1.0;
  } else if (rtb_Saturation1 > 0.0) {
    rtb_TmpSignalConversionAtSFun_6 = 1.0;
  } else if (rtb_Saturation1 == 0.0) {
    rtb_TmpSignalConversionAtSFun_6 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_6 = rtb_Saturation1;
  }

  /* Gain: '<S16>/Gain' incorporates:
   *  Signum: '<S16>/Sign'
   */
  rtb_Row1 = ctrl_DP_basic_P.Gain_Gain * rtb_TmpSignalConversionAtSFun_6;

  /* Sum: '<S16>/Sum1' */
  rtb_Saturation1 += rtb_Row1;

  /* Math: '<S16>/Math Function' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_Saturation1 = rt_remd_snf(rtb_Saturation1, ctrl_DP_basic_P.Constant_Value);

  /* Sum: '<S16>/Sum' */
  rtb_Saturation1 -= rtb_Row1;

  /* MATLAB Function: '<S24>/MATLAB Function1' */
  ctrl_DP_basic_MATLABFunction1(ctrl_DP_basic_B.K_i_x, ctrl_DP_basic_B.K_i_y,
    ctrl_DP_basic_B.K_i_psi, &ctrl_DP_basic_B.sf_MATLABFunction1);

  /* MATLAB Function: '<S24>/MATLAB Function2' */
  ctrl_DP_basic_MATLABFunction2(ctrl_DP_basic_B.K_d_x, ctrl_DP_basic_B.K_d_y,
    ctrl_DP_basic_B.K_d_psi, &ctrl_DP_basic_B.sf_MATLABFunction2);
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* MATLAB Function: '<S26>/MATLAB Function2' incorporates:
     *  Constant: '<S26>/Constant6'
     *  Constant: '<S26>/Constant7'
     *  Constant: '<S26>/Constant8'
     */
    ctrl_DP_basic_MATLABFunction2(ctrl_DP_basic_P.Constant6_Value,
      ctrl_DP_basic_P.Constant7_Value, ctrl_DP_basic_P.Constant8_Value,
      &ctrl_DP_basic_B.sf_MATLABFunction2_p);
  }

  /* MATLAB Function: '<S25>/diag' incorporates:
   *  SignalConversion: '<S30>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Input/Guidance gains/diag': '<S30>:1' */
  /* '<S30>:1:4' */
  memset(&rtb_w_d[0], 0, 9U * sizeof(real_T));
  rtb_w_d[0] = ctrl_DP_basic_B.w_d_x;
  rtb_w_d[4] = ctrl_DP_basic_B.w_d_y;
  rtb_w_d[8] = ctrl_DP_basic_B.w_d_psi;

  /* Integrator: '<S17>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_DP_basic_B.reset_g);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading) {
      ctrl_DP_basic_X.Integrator1_CSTATE[0] = ctrl_DP_basic_B.x;
      ctrl_DP_basic_X.Integrator1_CSTATE[1] = ctrl_DP_basic_B.y;
      ctrl_DP_basic_X.Integrator1_CSTATE[2] = ctrl_DP_basic_B.psi;
    }
  }

  ctrl_DP_basic_B.Integrator1[0] = ctrl_DP_basic_X.Integrator1_CSTATE[0];
  ctrl_DP_basic_B.Integrator1[1] = ctrl_DP_basic_X.Integrator1_CSTATE[1];
  ctrl_DP_basic_B.Integrator1[2] = ctrl_DP_basic_X.Integrator1_CSTATE[2];

  /* Saturate: '<S18>/Saturation' */
  if (ctrl_DP_basic_B.Integrator1[2] > ctrl_DP_basic_P.Saturation_UpperSat_j) {
    rtb_Row1 = ctrl_DP_basic_P.Saturation_UpperSat_j;
  } else if (ctrl_DP_basic_B.Integrator1[2] <
             ctrl_DP_basic_P.Saturation_LowerSat_c) {
    rtb_Row1 = ctrl_DP_basic_P.Saturation_LowerSat_c;
  } else {
    rtb_Row1 = ctrl_DP_basic_B.Integrator1[2];
  }

  /* End of Saturate: '<S18>/Saturation' */

  /* Signum: '<S18>/Sign' */
  if (rtb_Row1 < 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = -1.0;
  } else if (rtb_Row1 > 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 1.0;
  } else if (rtb_Row1 == 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_7 = rtb_Row1;
  }

  /* Gain: '<S18>/Gain' incorporates:
   *  Signum: '<S18>/Sign'
   */
  rtb_psi_dot = ctrl_DP_basic_P.Gain_Gain_j * rtb_TmpSignalConversionAtSFun_7;

  /* Sum: '<S18>/Sum1' */
  rtb_Row1 += rtb_psi_dot;

  /* Math: '<S18>/Math Function' incorporates:
   *  Constant: '<S18>/Constant'
   */
  rtb_Row1 = rt_remd_snf(rtb_Row1, ctrl_DP_basic_P.Constant_Value_f);

  /* Sum: '<S18>/Sum' */
  ctrl_DP_basic_B.Sum = rtb_Row1 - rtb_psi_dot;

  /* SignalConversion: '<S17>/TmpSignal ConversionAtMatrix Multiply2Inport2' */
  ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[0] =
    ctrl_DP_basic_B.Integrator1[0];
  ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[1] =
    ctrl_DP_basic_B.Integrator1[1];
  ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[2] = ctrl_DP_basic_B.Sum;

  /* Sum: '<S12>/Sum2' */
  ctrl_DP_basic_B.regulationerror[0] = ctrl_DP_basic_B.x -
    ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[0];
  ctrl_DP_basic_B.regulationerror[1] = ctrl_DP_basic_B.y -
    ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[1];
  ctrl_DP_basic_B.regulationerror[2] = ctrl_DP_basic_B.psi -
    ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[2];

  /* Saturate: '<S15>/Saturation' */
  if (ctrl_DP_basic_B.regulationerror[2] > ctrl_DP_basic_P.Saturation_UpperSat_a)
  {
    rtb_psi_dot = ctrl_DP_basic_P.Saturation_UpperSat_a;
  } else if (ctrl_DP_basic_B.regulationerror[2] <
             ctrl_DP_basic_P.Saturation_LowerSat_d) {
    rtb_psi_dot = ctrl_DP_basic_P.Saturation_LowerSat_d;
  } else {
    rtb_psi_dot = ctrl_DP_basic_B.regulationerror[2];
  }

  /* End of Saturate: '<S15>/Saturation' */

  /* Signum: '<S15>/Sign' */
  if (rtb_psi_dot < 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = -1.0;
  } else if (rtb_psi_dot > 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = 1.0;
  } else if (rtb_psi_dot == 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_0 = rtb_psi_dot;
  }

  /* Gain: '<S15>/Gain' incorporates:
   *  Signum: '<S15>/Sign'
   */
  rtb_Row1 = ctrl_DP_basic_P.Gain_Gain_g * rtb_TmpSignalConversionAtSFun_0;

  /* Sum: '<S15>/Sum1' */
  rtb_psi_dot += rtb_Row1;

  /* Math: '<S15>/Math Function' incorporates:
   *  Constant: '<S15>/Constant'
   */
  rtb_psi_dot = rt_remd_snf(rtb_psi_dot, ctrl_DP_basic_P.Constant_Value_p);

  /* Sum: '<S15>/Sum' */
  rtb_psi_dot -= rtb_Row1;

  /* SignalConversion: '<S12>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Fcn: '<S13>/Row1'
   *  Fcn: '<S13>/Row2'
   *  Fcn: '<S13>/Row3'
   */
  ctrl_DP_basic_B.TmpSignalConversionAtMatrixMu_m[0] = cos(rtb_Saturation1) *
    ctrl_DP_basic_B.regulationerror[0] + sin(rtb_Saturation1) *
    ctrl_DP_basic_B.regulationerror[1];
  ctrl_DP_basic_B.TmpSignalConversionAtMatrixMu_m[1] = -sin(rtb_Saturation1) *
    ctrl_DP_basic_B.regulationerror[0] + cos(rtb_Saturation1) *
    ctrl_DP_basic_B.regulationerror[1];
  ctrl_DP_basic_B.TmpSignalConversionAtMatrixMu_m[2] = rtb_psi_dot;

  /* Product: '<S12>/Matrix Multiply' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_TmpSignalConversionAtSFu_pa[b_ixstart] =
      ctrl_DP_basic_B.sf_MATLABFunction_g.K_p[b_ixstart + 6] *
      ctrl_DP_basic_B.TmpSignalConversionAtMatrixMu_m[2] +
      (ctrl_DP_basic_B.sf_MATLABFunction_g.K_p[b_ixstart + 3] *
       ctrl_DP_basic_B.TmpSignalConversionAtMatrixMu_m[1] +
       ctrl_DP_basic_B.sf_MATLABFunction_g.K_p[b_ixstart] *
       ctrl_DP_basic_B.TmpSignalConversionAtMatrixMu_m[0]);
  }

  /* End of Product: '<S12>/Matrix Multiply' */

  /* Integrator: '<S12>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_DP_basic_B.reset_g);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_basic_X.Integrator_CSTATE[0] = ctrl_DP_basic_P.Integrator_IC;
      ctrl_DP_basic_X.Integrator_CSTATE[1] = ctrl_DP_basic_P.Integrator_IC;
      ctrl_DP_basic_X.Integrator_CSTATE[2] = ctrl_DP_basic_P.Integrator_IC;
    }
  }

  rtb_Integrator2[0] = ctrl_DP_basic_X.Integrator_CSTATE[0];
  rtb_Integrator2[1] = ctrl_DP_basic_X.Integrator_CSTATE[1];
  rtb_Integrator2[2] = ctrl_DP_basic_X.Integrator_CSTATE[2];

  /* Product: '<S12>/Matrix Multiply1' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_Sum_nu[b_ixstart] = ctrl_DP_basic_B.sf_MATLABFunction1.K_i[b_ixstart + 6]
      * rtb_Integrator2[2] + (ctrl_DP_basic_B.sf_MATLABFunction1.K_i[b_ixstart +
      3] * rtb_Integrator2[1] + ctrl_DP_basic_B.sf_MATLABFunction1.K_i[b_ixstart]
      * rtb_Integrator2[0]);
  }

  /* End of Product: '<S12>/Matrix Multiply1' */

  /* Integrator: '<S6>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator1_Reset_ZCE_e,
                       ctrl_DP_basic_B.reset_g);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_basic_X.Integrator1_CSTATE_g[0] = (ctrl_DP_basic_P.Integrator1_IC
        [0]);
      ctrl_DP_basic_X.Integrator1_CSTATE_g[1] = (ctrl_DP_basic_P.Integrator1_IC
        [1]);
      ctrl_DP_basic_X.Integrator1_CSTATE_g[2] = (ctrl_DP_basic_P.Integrator1_IC
        [2]);
    }
  }

  ctrl_DP_basic_B.Integrator1_g[0] = ctrl_DP_basic_X.Integrator1_CSTATE_g[0];
  ctrl_DP_basic_B.Integrator1_g[1] = ctrl_DP_basic_X.Integrator1_CSTATE_g[1];
  ctrl_DP_basic_B.Integrator1_g[2] = ctrl_DP_basic_X.Integrator1_CSTATE_g[2];

  /* Fcn: '<S12>/yaw angle1' */
  rtb_Row1_o = ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[2];

  /* Integrator: '<S17>/Integrator3' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator3_Reset_ZCE,
                       ctrl_DP_basic_B.reset_g);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_basic_X.Integrator3_CSTATE[0] = ctrl_DP_basic_P.Integrator3_IC;
      ctrl_DP_basic_X.Integrator3_CSTATE[1] = ctrl_DP_basic_P.Integrator3_IC;
      ctrl_DP_basic_X.Integrator3_CSTATE[2] = ctrl_DP_basic_P.Integrator3_IC;
    }
  }

  ctrl_DP_basic_B.Integrator3[0] = ctrl_DP_basic_X.Integrator3_CSTATE[0];
  ctrl_DP_basic_B.Integrator3[1] = ctrl_DP_basic_X.Integrator3_CSTATE[1];
  ctrl_DP_basic_B.Integrator3[2] = ctrl_DP_basic_X.Integrator3_CSTATE[2];

  /* Sum: '<S12>/Sum4' incorporates:
   *  Fcn: '<S14>/Row1'
   *  Fcn: '<S14>/Row2'
   *  Fcn: '<S14>/Row3'
   */
  ctrl_DP_basic_B.Sum4[0] = ctrl_DP_basic_B.Integrator1_g[0] - (cos(rtb_Row1_o) *
    ctrl_DP_basic_B.Integrator3[0] + sin(rtb_Row1_o) *
    ctrl_DP_basic_B.Integrator3[1]);
  ctrl_DP_basic_B.Sum4[1] = ctrl_DP_basic_B.Integrator1_g[1] - (-sin(rtb_Row1_o)
    * ctrl_DP_basic_B.Integrator3[0] + cos(rtb_Row1_o) *
    ctrl_DP_basic_B.Integrator3[1]);
  ctrl_DP_basic_B.Sum4[2] = ctrl_DP_basic_B.Integrator1_g[2] -
    ctrl_DP_basic_B.Integrator3[2];

  /* Product: '<S12>/Matrix Multiply2' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_Integrator2[b_ixstart] = 0.0;
    rtb_Integrator2[b_ixstart] +=
      ctrl_DP_basic_B.sf_MATLABFunction2.K_d[b_ixstart] * ctrl_DP_basic_B.Sum4[0];
    rtb_Integrator2[b_ixstart] +=
      ctrl_DP_basic_B.sf_MATLABFunction2.K_d[b_ixstart + 3] *
      ctrl_DP_basic_B.Sum4[1];
    rtb_Integrator2[b_ixstart] +=
      ctrl_DP_basic_B.sf_MATLABFunction2.K_d[b_ixstart + 6] *
      ctrl_DP_basic_B.Sum4[2];
  }

  /* End of Product: '<S12>/Matrix Multiply2' */

  /* Sum: '<S12>/Sum3' */
  ctrl_DP_basic_B.Sum3[0] = ((0.0 - rtb_TmpSignalConversionAtSFu_pa[0]) -
    rtb_Sum_nu[0]) - rtb_Integrator2[0];
  ctrl_DP_basic_B.Sum3[1] = ((0.0 - rtb_TmpSignalConversionAtSFu_pa[1]) -
    rtb_Sum_nu[1]) - rtb_Integrator2[1];
  ctrl_DP_basic_B.Sum3[2] = ((0.0 - rtb_TmpSignalConversionAtSFu_pa[2]) -
    rtb_Sum_nu[2]) - rtb_Integrator2[2];

  /* SignalConversion: '<S47>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Gain: '<S48>/Gain'
   *  MATLAB Function: '<S9>/MATLAB Function'
   */
  rtb_TmpSignalConversionAtSFun_6 = ctrl_DP_basic_B.Sum3[0];
  rtb_Row1_o = ctrl_DP_basic_B.Sum3[1];
  rtb_TmpSignalConversionAtSFun_7 = ctrl_DP_basic_B.Sum3[2];
  rtb_TmpSignalConversionAtSFun_0 = ctrl_DP_basic_P.Gain_Gain_gz *
    ctrl_DP_basic_B.thr_angle_1;
  rtb_TmpSignalConversionAtSFun_1 = ctrl_DP_basic_P.Gain_Gain_gz *
    ctrl_DP_basic_B.thr_angle_2;
  rtb_TmpSignalConversionAtSFun_2 = ctrl_DP_basic_P.Gain_Gain_gz *
    ctrl_DP_basic_B.thr_angle_3;
  rtb_TmpSignalConversionAtSFun_3 = ctrl_DP_basic_P.Gain_Gain_gz *
    ctrl_DP_basic_B.thr_angle_4;
  rtb_TmpSignalConversionAtSFun_4 = ctrl_DP_basic_P.Gain_Gain_gz *
    ctrl_DP_basic_B.thr_angle_5;
  rtb_TmpSignalConversionAtSFun_5 = ctrl_DP_basic_P.Gain_Gain_gz *
    ctrl_DP_basic_B.thr_angle_6;

  /* MATLAB Function: '<S9>/MATLAB Function' incorporates:
   *  Constant: '<S9>/C'
   *  Constant: '<S9>/X-position Thruster'
   *  Constant: '<S9>/Y-position Thruster'
   *  Gain: '<S48>/Gain'
   */
  /* MATLAB Function 'Thrust allocation1/MATLAB Function': '<S47>:1' */
  /*  Complete system goes here! */
  /*  ThrusterPosX = [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)];%[x(1),x(2),x(3),x(4),x(5),x(6)]'; */
  /*  ThrusterPosY = [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)];%[x(7),x(8),x(9),x(10),x(11),x(12)]'; */
  /*  Parameters thrusters */
  /* '<S47>:1:7' */
  /* '<S47>:1:8' */
  alpha[0] = ctrl_DP_basic_P.Gain_Gain_gz * ctrl_DP_basic_B.thr_angle_1;
  alpha[1] = ctrl_DP_basic_P.Gain_Gain_gz * ctrl_DP_basic_B.thr_angle_2;
  alpha[2] = ctrl_DP_basic_P.Gain_Gain_gz * ctrl_DP_basic_B.thr_angle_3;
  alpha[3] = ctrl_DP_basic_P.Gain_Gain_gz * ctrl_DP_basic_B.thr_angle_4;
  alpha[4] = ctrl_DP_basic_P.Gain_Gain_gz * ctrl_DP_basic_B.thr_angle_5;
  alpha[5] = ctrl_DP_basic_P.Gain_Gain_gz * ctrl_DP_basic_B.thr_angle_6;

  /* alpha0 = [x(1),x(2),x(3),x(4),x(5),x(6)]'; */
  /*  Constraints for Thruster-Thruster interaction. Can be seen in "Initfile" */
  /*  how they are found */
  /* '<S47>:1:13' */
  /* '<S47>:1:14' */
  /* '<S47>:1:15' */
  /* '<S47>:1:16' */
  /* '<S47>:1:17' */
  /* '<S47>:1:18' */
  if (((rtb_TmpSignalConversionAtSFun_0 < ctrl_DP_basic_P.C[0] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_0 > ctrl_DP_basic_P.C[6] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_0 > ctrl_DP_basic_P.C[12] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_0 < ctrl_DP_basic_P.C[18] - 0.1))) {
    /* '<S47>:1:24' */
    /* '<S47>:1:25' */
    K[0] = 0.0;
  } else {
    /* '<S47>:1:27' */
    K[0] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_1 > ctrl_DP_basic_P.C[1] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_1 < ctrl_DP_basic_P.C[7] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_1 > ctrl_DP_basic_P.C[13] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_1 < ctrl_DP_basic_P.C[19] + 0.1))) {
    /* '<S47>:1:30' */
    /* '<S47>:1:31' */
    K[1] = 0.0;
  } else {
    /* '<S47>:1:33' */
    K[1] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_2 < ctrl_DP_basic_P.C[2] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_2 > ctrl_DP_basic_P.C[8] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_2 < ctrl_DP_basic_P.C[14] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_2 > ctrl_DP_basic_P.C[20] - 0.1))) {
    /* '<S47>:1:36' */
    /* '<S47>:1:37' */
    K[2] = 0.0;
  } else {
    /* '<S47>:1:39' */
    K[2] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_3 > ctrl_DP_basic_P.C[3] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_3 < ctrl_DP_basic_P.C[9] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_3 < ctrl_DP_basic_P.C[15] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_3 > ctrl_DP_basic_P.C[21] + 0.1))) {
    /* '<S47>:1:42' */
    /* '<S47>:1:43' */
    K[3] = 0.0;
  } else {
    /* '<S47>:1:45' */
    K[3] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_4 < ctrl_DP_basic_P.C[4] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_4 > ctrl_DP_basic_P.C[10] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_4 < ctrl_DP_basic_P.C[16] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_4 > ctrl_DP_basic_P.C[22] + 0.1))) {
    /* '<S47>:1:48' */
    /* '<S47>:1:49' */
    K[4] = 0.0;
  } else {
    /* '<S47>:1:51' */
    K[4] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_5 > ctrl_DP_basic_P.C[5] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_5 < ctrl_DP_basic_P.C[11] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_5 > ctrl_DP_basic_P.C[17] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_5 < ctrl_DP_basic_P.C[23] - 0.1))) {
    /* '<S47>:1:54' */
    /* '<S47>:1:55' */
    K[5] = 0.0;
  } else {
    /* '<S47>:1:57' */
    K[5] = 1.0;
  }

  /*  number of thrusters */
  /* '<S47>:1:63' */
  /*  Shells for faster computing */
  /* '<S47>:1:64' */
  /*  Shells for faster computing */
  /* '<S47>:1:65' */
  /*  Shells for faster computing */
  /* '<S47>:1:67' */
  for (ixstart = 0; ixstart < 6; ixstart++) {
    /* '<S47>:1:67' */
    /* '<S47>:1:68' */
    T_surge[ixstart] = alpha[ixstart];
    ctrl_DP_basic_cosd(&T_surge[ixstart]);

    /* Thrust in x-direction for cartesian */
    /* '<S47>:1:69' */
    T_sway[ixstart] = alpha[ixstart];
    ctrl_DP_basic_sind(&T_sway[ixstart]);

    /* Thrust in y-direction for cartesian */
    /* '<S47>:1:70' */
    rtb_Saturation1 = alpha[ixstart];
    ctrl_DP_basic_sind(&rtb_Saturation1);
    rtb_Row1 = alpha[ixstart];
    ctrl_DP_basic_cosd(&rtb_Row1);
    T_yaw[ixstart] = rtb_Saturation1 *
      ctrl_DP_basic_P.XpositionThruster_Value[ixstart] - rtb_Row1 *
      ctrl_DP_basic_P.YpositionThruster_Value[ixstart];

    /* '<S47>:1:67' */
  }

  /* '<S47>:1:74' */
  /* '<S47>:1:75' */
  ctrl_DP_basic_diag(K, d_0);
  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    T_surge_1[3 * b_ixstart] = T_surge[b_ixstart];
  }

  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    T_surge_1[1 + 3 * b_ixstart] = T_sway[b_ixstart];
  }

  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    T_surge_1[2 + 3 * b_ixstart] = T_yaw[b_ixstart];
  }

  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    for (i = 0; i < 6; i++) {
      T_surge_0[b_ixstart + 3 * i] = 0.0;
      for (p3 = 0; p3 < 6; p3++) {
        T_surge_0[b_ixstart + 3 * i] += T_surge_1[3 * p3 + b_ixstart] * d_0[6 *
          i + p3];
      }
    }
  }

  ctrl_DP_basic_svd(T_surge_0, U_singular, S_singular_cross, V_singular);

  /* '<S47>:1:77' */
  for (b_ixstart = 0; b_ixstart < 9; b_ixstart++) {
    S_singular_cross[b_ixstart] = 1.0 / S_singular_cross[b_ixstart];
  }

  /* '<S47>:1:78' */
  ctrl_DP_basic_isfinite(S_singular_cross, tmp);
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

  /* '<S47>:1:78' */
  for (b_ixstart = 0; b_ixstart < i; b_ixstart++) {
    S_singular_cross[b_data[b_ixstart] - 1] = 0.0;
  }

  if (S_singular_cross[8] > 2.0 * S_singular_cross[4]) {
    /* '<S47>:1:79' */
    /* '<S47>:1:80' */
    S_singular_cross[8] = 0.0;
  }

  /*    if (S_singular_cross(2,2)<1*S_singular_cross(1,1))  */
  /*       S_singular_cross(2,2)=0; */
  /*    end */
  /*     if (S_singular_cross(1,1)>10*S_singular_cross(2,2))  */
  /*       S_singular_cross(1,1)=0; */
  /*     end */
  /*   disp(S_singular_cross) */
  /* '<S47>:1:89' */
  /* K = eye(n_t);%diag([ 5 5 5 5 5 5]); */
  /* '<S47>:1:91' */
  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      T_surge_1[b_ixstart + 6 * i] = 0.0;
      T_surge_1[b_ixstart + 6 * i] += S_singular_cross[3 * i] *
        V_singular[b_ixstart];
      T_surge_1[b_ixstart + 6 * i] += S_singular_cross[3 * i + 1] *
        V_singular[b_ixstart + 6];
      T_surge_1[b_ixstart + 6 * i] += S_singular_cross[3 * i + 2] *
        V_singular[b_ixstart + 12];
    }
  }

  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      V_singular[b_ixstart + 6 * i] = 0.0;
      V_singular[b_ixstart + 6 * i] += T_surge_1[b_ixstart] * U_singular[i];
      V_singular[b_ixstart + 6 * i] += T_surge_1[b_ixstart + 6] * U_singular[i +
        3];
      V_singular[b_ixstart + 6 * i] += T_surge_1[b_ixstart + 12] * U_singular[i
        + 6];
    }
  }

  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    T_surge[b_ixstart] = V_singular[b_ixstart + 12] *
      rtb_TmpSignalConversionAtSFun_7 + (V_singular[b_ixstart + 6] * rtb_Row1_o
      + V_singular[b_ixstart] * rtb_TmpSignalConversionAtSFun_6);
  }

  /*  Optimized Thrust */
  /*  if alpha(1) < 90 && alpha(1) > 70 */
  /*      T_d(1) = 0; */
  /*  else */
  /*      T_d(1); */
  /*  end */
  /*   */
  /*  T_dirx = zeros(1,n_t); */
  /*  T_diry = zeros(1,n_t); */
  /*  for i = 1:1:n_t */
  /*  T_dirx(i) = [T_d(i)'*cosd(alpha(i))];%+cosd(alpha(i))*ThrusterPosY(i)]; */
  /*  T_diry(i) = [T_d(i)'*sind(alpha(i))];%+sind(alpha(i))*ThrusterPosX(i)]; */
  /*  end */
  /*   */
  /*  Alpha_surge =[T_d(1)*cosd(alpha(1)) T_d(2)*cosd(alpha(2)) T_d(3)*cosd(alpha(3)) T_d(4)*cosd(alpha(4)) T_d(5)*cosd(alpha(5)) T_d(6)*cosd(alpha(6))];   */
  /*  Alpha_sway = [T_d(1)*sind(alpha(1)) T_d(2)*sind(alpha(2)) T_d(3)*sind(alpha(3)) T_d(4)*sind(alpha(4)) T_d(5)*sind(alpha(5)) T_d(6)*sind(alpha(6))]; */
  /*   */
  /*  T_dir = [Alpha_surge' ; Alpha_sway']; */
  /*  T1 = [T_dir(1),T_dir(7),atan2d(T_dir(7),T_dir(1))]; */
  /*  T2 = [T_dir(2),T_dir(8),atan2d(T_dir(8),T_dir(2))]; */
  /*  T3 = [T_dir(3),T_dir(9),atan2d(T_dir(9),T_dir(3))]; */
  /*  T4 = [T_dir(4),T_dir(10),atan2d(T_dir(10),T_dir(4))]; */
  /*  T5 = [T_dir(5),T_dir(11),atan2d(T_dir(11),T_dir(5))]; */
  /*  T6 = [T_dir(6),T_dir(12),atan2d(T_dir(12),T_dir(6))]; */
  /*   */
  /*  %% Finding Desired angle for optimal thrust */
  /*   */
  /*  % Without yaw motion */
  /*  if tc(3) == 0   */
  /*   if tc(1) >= 0 && tc(2) >= 0 */
  /*    alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180;    */
  /*   elseif tc(1) < 0 && tc(2) >= 0 */
  /*       alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180; */
  /*   elseif tc(1) < 0 && tc(2) < 0 */
  /*       alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180; */
  /*   elseif tc(1) >= 0 && tc(2) < 0 */
  /*       alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180; */
  /*   end */
  /*  end */
  /*   % With positive yaw motion */
  /*   if tc(3) < 0  */
  /*       if  tc(2) == 0 && tc(1) == 0 */
  /*          alpha1 = [90 90 90 -90 -90 -90]'; */
  /*       elseif tc(2) >= 0 && tc(1) >= 0  */
  /*          alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180; */
  /*          alpha1 = [90 alpha1(2) alpha1(3) -90 alpha1(5) alpha1(6)]'+180; */
  /*       elseif tc(2) >= 0 && tc(1) < 0 */
  /*          alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180; */
  /*          alpha1 = [90 alpha1(2) alpha1(3) -90 alpha1(5) alpha1(6)]'; */
  /*       elseif tc(1) < 0 && tc(2) < 0 */
  /*          alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180; */
  /*          alpha1 = [90 alpha1(2) alpha1(3) -90 alpha1(5) alpha1(6)]'; */
  /*       elseif tc(1) >= 0 && tc(2) < 0 */
  /*          alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180; */
  /*          alpha1 = [90 alpha1(2) alpha1(3) -90 alpha1(5) alpha1(6)]'; */
  /*       end */
  /*   end */
  /*    */
  /*   % With negative yaw motion */
  /*    if tc(3) > 0  */
  /*       if  tc(2) == 0 && tc(1) == 0 */
  /*          alpha1 = [-90 -90 -90 90 90 90]'; */
  /*       elseif tc(2) >= 0 && tc(1) >= 0  */
  /*          alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180; */
  /*          alpha1 = [-90 alpha1(2) alpha1(3) 90 alpha1(5) alpha1(6)]'; */
  /*       elseif tc(2) >= 0 && tc(1) < 0 */
  /*          alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180; */
  /*          alpha1 = [-90 alpha1(2) alpha1(3) 90 alpha1(5) alpha1(6)]'; */
  /*       elseif tc(1) < 0 && tc(2) < 0 */
  /*          alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180; */
  /*          alpha1 = [-90 alpha1(2) alpha1(3) 90 alpha1(5) alpha1(6)]'; */
  /*       elseif tc(1) >= 0 && tc(2) < 0 */
  /*          alpha1 = ones(n_t,1)*atan2d(tc(2),tc(1))+180; */
  /*          alpha1 = [-90 alpha1(2) alpha1(3) 90 alpha1(5) alpha1(6)]'; */
  /*       end */
  /*    end */
  /*  for i=1:1:n_t */
  /*    if alpha1(i) > 180 */
  /*        alpha1(i) = alpha1(i) - 360; */
  /*    elseif alpha1(i) < -180 */
  /*        alpha1(i) = alpha1(i) + 360; */
  /*    else */
  /*        alpha1(i); */
  /*    end */
  /*  end */
  /*   */
  /*  B = [T_surge,T_sway,T_yaw]'; */
  /*  B = B*diag(K);  */
  /*  Te = [1 0 1 0 1 0 1 0 1 0 1 0; */
  /*        0 1 0 1 0 1 0 1 0 1 0 1; */
  /*        ThrusterPosY(1) ThrusterPosX(1) ThrusterPosY(2) ThrusterPosX(2) ThrusterPosY(3) ThrusterPosX(3) ... */
  /*        ThrusterPosY(4) ThrusterPosX(4) ThrusterPosY(5) ThrusterPosX(5) ThrusterPosY(6) ThrusterPosX(6)]; */
  /* '<S47>:1:188' */
  for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
    d_0[3 * b_ixstart] = d[b_ixstart];
  }

  for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
    d_0[1 + 3 * b_ixstart] = e[b_ixstart];
  }

  d_0[2] = ctrl_DP_basic_P.YpositionThruster_Value[0];
  d_0[5] = ctrl_DP_basic_P.XpositionThruster_Value[0];
  d_0[8] = ctrl_DP_basic_P.YpositionThruster_Value[1];
  d_0[11] = ctrl_DP_basic_P.XpositionThruster_Value[1];
  d_0[14] = ctrl_DP_basic_P.YpositionThruster_Value[2];
  d_0[17] = ctrl_DP_basic_P.XpositionThruster_Value[2];
  d_0[20] = ctrl_DP_basic_P.YpositionThruster_Value[3];
  d_0[23] = ctrl_DP_basic_P.XpositionThruster_Value[3];
  d_0[26] = ctrl_DP_basic_P.YpositionThruster_Value[4];
  d_0[29] = ctrl_DP_basic_P.XpositionThruster_Value[4];
  d_0[32] = ctrl_DP_basic_P.YpositionThruster_Value[5];
  d_0[35] = ctrl_DP_basic_P.XpositionThruster_Value[5];
  ctrl_DP_basic_svd_m(d_0, U_singular, S_singular_cross, b_V_singular);

  /* '<S47>:1:194' */
  for (b_ixstart = 0; b_ixstart < 9; b_ixstart++) {
    S_singular_cross[b_ixstart] = 1.0 / S_singular_cross[b_ixstart];
  }

  /* '<S47>:1:195' */
  ctrl_DP_basic_isfinite(S_singular_cross, tmp);
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

  /* '<S47>:1:195' */
  for (b_ixstart = 0; b_ixstart < i; b_ixstart++) {
    S_singular_cross[c_data[b_ixstart] - 1] = 0.0;
  }

  if (S_singular_cross[8] > 2.0 * S_singular_cross[4]) {
    /* '<S47>:1:196' */
    /* '<S47>:1:197' */
    S_singular_cross[8] = 0.0;
  }

  /* '<S47>:1:199' */
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
      b_V_singular[b_ixstart + 12 * i] += d_0[b_ixstart] * U_singular[i];
      b_V_singular[b_ixstart + 12 * i] += d_0[b_ixstart + 12] * U_singular[i + 3];
      b_V_singular[b_ixstart + 12 * i] += d_0[b_ixstart + 24] * U_singular[i + 6];
    }
  }

  for (b_ixstart = 0; b_ixstart < 12; b_ixstart++) {
    rtb_TmpSignalConversionAtSFunct[b_ixstart] = b_V_singular[b_ixstart + 24] *
      rtb_TmpSignalConversionAtSFun_7 + (b_V_singular[b_ixstart + 12] *
      rtb_Row1_o + b_V_singular[b_ixstart] * rtb_TmpSignalConversionAtSFun_6);
  }

  /*  alpha1 = [atan2d(T0(2),T0(1)) atan2d(T0(4),T0(3)) atan2d(T0(6),T0(5)) atan2d(T0(8),T0(7)) atan2d(T0(10),T0(9)) atan2d(T0(12),T0(11))]; */
  /* '<S47>:1:203' */
  K[3] = 57.295779513082323 * rt_atan2d_snf(rtb_TmpSignalConversionAtSFunct[7],
    rtb_TmpSignalConversionAtSFunct[6]);
  K[4] = 57.295779513082323 * rt_atan2d_snf(rtb_TmpSignalConversionAtSFunct[9],
    rtb_TmpSignalConversionAtSFunct[8]);
  K[5] = 57.295779513082323 * rt_atan2d_snf(rtb_TmpSignalConversionAtSFunct[11],
    rtb_TmpSignalConversionAtSFunct[10]);

  /* % Constraints */
  /*  Thruster 1 OK */
  /* C1 = [151 130 -151 -130 ]; */
  if (((180.0 < ctrl_DP_basic_P.C[0]) && (180.0 > ctrl_DP_basic_P.C[6]) &&
       (T_surge[0] > 0.0)) || ((180.0 < ctrl_DP_basic_P.C[0]) && (180.0 >
        ctrl_DP_basic_P.C[6]) && (T_surge[0] < 0.0))) {
    /* '<S47>:1:207' */
    /* '<S47>:1:208' */
    c1[0] = ctrl_DP_basic_P.C[0];
    c1[1] = ctrl_DP_basic_P.C[6];
    c1_5[0] = ctrl_DP_basic_P.C[0] - 180.0;
    c1_5[1] = ctrl_DP_basic_P.C[6] - 180.0;
    ctrl_DP_basic_abs(c1_5, varargin_1);
    b_ixstart = 1;
    rtb_Saturation1 = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        b_ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Saturation1 = varargin_1[1];
          ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((b_ixstart < 2) && (varargin_1[1] < rtb_Saturation1)) {
      ixstart = 1;
    }

    /* '<S47>:1:210' */
    rtb_Row1 = c1[ixstart];
  } else if (((180.0 > ctrl_DP_basic_P.C[12]) && (180.0 < ctrl_DP_basic_P.C[18])
              && (T_surge[0] > 0.0)) || ((180.0 > ctrl_DP_basic_P.C[12]) &&
              (180.0 < ctrl_DP_basic_P.C[18]) && (T_surge[0] < 0.0))) {
    /* '<S47>:1:211' */
    /* '<S47>:1:212' */
    c1[0] = ctrl_DP_basic_P.C[12];
    c1[1] = ctrl_DP_basic_P.C[18];
    c1_5[0] = ctrl_DP_basic_P.C[12] - 180.0;
    c1_5[1] = ctrl_DP_basic_P.C[18] - 180.0;
    ctrl_DP_basic_abs(c1_5, varargin_1);
    ixstart = 1;
    rtb_Row1 = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Row1 = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Row1)) {
      i = 1;
    }

    /* '<S47>:1:214' */
    rtb_Row1 = c1[i];
  } else {
    /* '<S47>:1:216' */
    rtb_Row1 = 180.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_0 < ctrl_DP_basic_P.C[0] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_0 > ctrl_DP_basic_P.C[6] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_0 > ctrl_DP_basic_P.C[12] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_0 < ctrl_DP_basic_P.C[18] - 0.1))) {
    /* '<S47>:1:218' */
    /* '<S47>:1:219' */
    T_surge[0] = 0.0;
  } else {
    /* '<S47>:1:221' */
  }

  /*  Thruster 2  */
  /* C2 = [-99.85 -80.15 -50 -29]; */
  if (((-90.0 < ctrl_DP_basic_P.C[1]) && (-90.0 > ctrl_DP_basic_P.C[7]) &&
       (T_surge[1] > 0.0)) || ((-90.0 < ctrl_DP_basic_P.C[1]) && (-90.0 >
        ctrl_DP_basic_P.C[7]) && (T_surge[1] < 0.0))) {
    /* '<S47>:1:226' */
    /* '<S47>:1:227' */
    c1[0] = ctrl_DP_basic_P.C[1];
    c1[1] = ctrl_DP_basic_P.C[7];
    c1_4[0] = ctrl_DP_basic_P.C[1] - -90.0;
    c1_4[1] = ctrl_DP_basic_P.C[7] - -90.0;
    ctrl_DP_basic_abs(c1_4, varargin_1);
    ixstart = 1;
    rtb_Saturation1 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Saturation1 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Saturation1)) {
      b_ixstart = 1;
    }

    /* '<S47>:1:229' */
    rtb_psi_dot = c1[b_ixstart];
  } else if (((-90.0 < ctrl_DP_basic_P.C[7]) && (-90.0 > ctrl_DP_basic_P.C[19]) &&
              (T_surge[1] > 0.0)) || ((-90.0 < ctrl_DP_basic_P.C[7]) && (-90.0 >
    ctrl_DP_basic_P.C[19]) && (T_surge[1] < 0.0))) {
    /* '<S47>:1:230' */
    /* '<S47>:1:231' */
    c1[0] = ctrl_DP_basic_P.C[7];
    c1[1] = ctrl_DP_basic_P.C[19];
    c1_4[0] = ctrl_DP_basic_P.C[7] - -90.0;
    c1_4[1] = ctrl_DP_basic_P.C[19] - -90.0;
    ctrl_DP_basic_abs(c1_4, varargin_1);
    ixstart = 1;
    rtb_Saturation1 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Saturation1 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Saturation1)) {
      b_ixstart = 1;
    }

    /* '<S47>:1:233' */
    rtb_psi_dot = c1[b_ixstart];
  } else {
    /* '<S47>:1:235' */
    rtb_psi_dot = -90.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_1 < ctrl_DP_basic_P.C[1] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_1 > ctrl_DP_basic_P.C[7] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_1 < ctrl_DP_basic_P.C[7] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_1 > ctrl_DP_basic_P.C[19] + 0.1))) {
    /* '<S47>:1:237' */
    /* '<S47>:1:238' */
    T_surge[1] = 0.0;
  } else {
    /* '<S47>:1:240' */
  }

  /*  Thruster 3  */
  /*  C3 = [99.85 80.15 50 29];  */
  if (((90.0 > ctrl_DP_basic_P.C[2]) && (90.0 < ctrl_DP_basic_P.C[14]) &&
       (T_surge[2] > 0.0)) || ((90.0 > ctrl_DP_basic_P.C[2]) && (90.0 <
        ctrl_DP_basic_P.C[14]) && (T_surge[2] < 0.0))) {
    /* '<S47>:1:246' */
    /* '<S47>:1:247' */
    c1[0] = ctrl_DP_basic_P.C[2];
    c1[1] = ctrl_DP_basic_P.C[14];
    c1_3[0] = ctrl_DP_basic_P.C[2] - 90.0;
    c1_3[1] = ctrl_DP_basic_P.C[14] - 90.0;
    ctrl_DP_basic_abs(c1_3, varargin_1);
    ixstart = 1;
    rtb_Saturation1 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Saturation1 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Saturation1)) {
      b_ixstart = 1;
    }

    /* '<S47>:1:249' */
    rtb_Row1_o = c1[b_ixstart];
  } else if (((90.0 > ctrl_DP_basic_P.C[14]) && (90.0 < ctrl_DP_basic_P.C[20]) &&
              (T_surge[2] > 0.0)) || ((90.0 > ctrl_DP_basic_P.C[14]) && (90.0 <
               ctrl_DP_basic_P.C[20]) && (T_surge[2] < 0.0))) {
    /* '<S47>:1:250' */
    /* '<S47>:1:251' */
    c1[0] = ctrl_DP_basic_P.C[14];
    c1[1] = ctrl_DP_basic_P.C[20];
    c1_3[0] = ctrl_DP_basic_P.C[14] - 90.0;
    c1_3[1] = ctrl_DP_basic_P.C[20] - 90.0;
    ctrl_DP_basic_abs(c1_3, varargin_1);
    ixstart = 1;
    rtb_Saturation1 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Saturation1 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Saturation1)) {
      b_ixstart = 1;
    }

    /* '<S47>:1:253' */
    rtb_Row1_o = c1[b_ixstart];
  } else {
    /* '<S47>:1:255' */
    rtb_Row1_o = 90.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_2 > ctrl_DP_basic_P.C[2] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_2 < ctrl_DP_basic_P.C[14] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_2 > ctrl_DP_basic_P.C[14] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_2 < ctrl_DP_basic_P.C[20] - 0.1))) {
    /* '<S47>:1:257' */
    /* '<S47>:1:258' */
    T_surge[2] = 0.0;
  } else {
    /* '<S47>:1:260' */
  }

  /*  Thruster 4 OK */
  /* C4 = [-52.8 -34.2 52.8 34.2];  */
  if (((K[3] > ctrl_DP_basic_P.C[3]) && (K[3] < ctrl_DP_basic_P.C[9]) &&
       (T_surge[3] > 0.0)) || ((K[3] > ctrl_DP_basic_P.C[3]) && (K[3] <
        ctrl_DP_basic_P.C[9]) && (T_surge[3] < 0.0))) {
    /* '<S47>:1:265' */
    /* '<S47>:1:266' */
    c1[0] = ctrl_DP_basic_P.C[3];
    c1[1] = ctrl_DP_basic_P.C[9];
    c1_2[0] = ctrl_DP_basic_P.C[3] - K[3];
    c1_2[1] = ctrl_DP_basic_P.C[9] - K[3];
    ctrl_DP_basic_abs(c1_2, varargin_1);
    ixstart = 1;
    rtb_Saturation1 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Saturation1 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Saturation1)) {
      b_ixstart = 1;
    }

    /* '<S47>:1:268' */
    rtb_TmpSignalConversionAtSFun_0 = c1[b_ixstart];
  } else if (((K[3] < ctrl_DP_basic_P.C[15]) && (K[3] > ctrl_DP_basic_P.C[21]) &&
              (T_surge[3] > 0.0)) || ((K[3] < ctrl_DP_basic_P.C[15]) && (K[3] >
               ctrl_DP_basic_P.C[21]) && (T_surge[3] < 0.0))) {
    /* '<S47>:1:269' */
    /* '<S47>:1:270' */
    c1[0] = ctrl_DP_basic_P.C[15];
    c1[1] = ctrl_DP_basic_P.C[21];
    c1_2[0] = ctrl_DP_basic_P.C[15] - K[3];
    c1_2[1] = ctrl_DP_basic_P.C[21] - K[3];
    ctrl_DP_basic_abs(c1_2, varargin_1);
    ixstart = 1;
    rtb_Saturation1 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Saturation1 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Saturation1)) {
      b_ixstart = 1;
    }

    /* '<S47>:1:272' */
    rtb_TmpSignalConversionAtSFun_0 = c1[b_ixstart];
  } else {
    /* '<S47>:1:274' */
    rtb_TmpSignalConversionAtSFun_0 = K[3];
  }

  if (((rtb_TmpSignalConversionAtSFun_3 > ctrl_DP_basic_P.C[3] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_3 < ctrl_DP_basic_P.C[9] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_3 < ctrl_DP_basic_P.C[15] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_3 > ctrl_DP_basic_P.C[21] + 0.1))) {
    /* '<S47>:1:276' */
    /* '<S47>:1:277' */
    T_surge[3] = 0.0;
  } else {
    /* '<S47>:1:279' */
  }

  /*  Thruster 5 */
  /* C5 = [-98.25 -81.75 -145.8 -127.2]; */
  if (((K[4] < ctrl_DP_basic_P.C[4]) && (K[4] > ctrl_DP_basic_P.C[10]) &&
       (T_surge[4] > 0.0)) || ((K[4] < ctrl_DP_basic_P.C[4]) && (K[4] >
        ctrl_DP_basic_P.C[10]) && (T_surge[4] < 0.0))) {
    /* '<S47>:1:284' */
    /* '<S47>:1:285' */
    c1[0] = ctrl_DP_basic_P.C[4];
    c1[1] = ctrl_DP_basic_P.C[10];
    c1_1[0] = ctrl_DP_basic_P.C[4] - K[4];
    c1_1[1] = ctrl_DP_basic_P.C[10] - K[4];
    ctrl_DP_basic_abs(c1_1, varargin_1);
    ixstart = 1;
    rtb_Saturation1 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Saturation1 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Saturation1)) {
      b_ixstart = 1;
    }

    /* '<S47>:1:287' */
    rtb_TmpSignalConversionAtSFun_7 = c1[b_ixstart];
  } else if (((K[4] < ctrl_DP_basic_P.C[16]) && (K[4] > ctrl_DP_basic_P.C[22]) &&
              (T_surge[4] > 0.0)) || ((K[4] < ctrl_DP_basic_P.C[16]) && (K[4] >
               ctrl_DP_basic_P.C[22]) && (T_surge[4] < 0.0))) {
    /* '<S47>:1:288' */
    /* '<S47>:1:289' */
    c1[0] = ctrl_DP_basic_P.C[16];
    c1[1] = ctrl_DP_basic_P.C[22];
    c1_1[0] = ctrl_DP_basic_P.C[16] - K[4];
    c1_1[1] = ctrl_DP_basic_P.C[22] - K[4];
    ctrl_DP_basic_abs(c1_1, varargin_1);
    ixstart = 1;
    rtb_Saturation1 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Saturation1 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Saturation1)) {
      b_ixstart = 1;
    }

    /* '<S47>:1:291' */
    rtb_TmpSignalConversionAtSFun_7 = c1[b_ixstart];
  } else {
    /* '<S47>:1:293' */
    rtb_TmpSignalConversionAtSFun_7 = K[4];
  }

  if (((rtb_TmpSignalConversionAtSFun_4 < ctrl_DP_basic_P.C[4] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_4 > ctrl_DP_basic_P.C[10] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_4 < ctrl_DP_basic_P.C[16] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_4 > ctrl_DP_basic_P.C[22] + 0.1))) {
    /* '<S47>:1:295' */
    /* '<S47>:1:296' */
    T_surge[4] = 0.0;
  } else {
    /* '<S47>:1:298' */
  }

  /*  Thruster 6 */
  /* C6 = [98.75 81.75 145.8 127.2]; */
  if (((K[5] > ctrl_DP_basic_P.C[5]) && (K[5] < ctrl_DP_basic_P.C[11]) &&
       (T_surge[5] > 0.0)) || ((K[5] > ctrl_DP_basic_P.C[5]) && (K[5] <
        ctrl_DP_basic_P.C[11]) && (T_surge[5] < 0.0))) {
    /* '<S47>:1:303' */
    /* '<S47>:1:304' */
    c1[0] = ctrl_DP_basic_P.C[5];
    c1[1] = ctrl_DP_basic_P.C[11];
    c1_0[0] = ctrl_DP_basic_P.C[5] - K[5];
    c1_0[1] = ctrl_DP_basic_P.C[11] - K[5];
    ctrl_DP_basic_abs(c1_0, varargin_1);
    ixstart = 1;
    rtb_Saturation1 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Saturation1 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Saturation1)) {
      b_ixstart = 1;
    }

    /* '<S47>:1:306' */
    rtb_TmpSignalConversionAtSFun_6 = c1[b_ixstart];
  } else if (((K[5] > ctrl_DP_basic_P.C[17]) && (K[5] < ctrl_DP_basic_P.C[23]) &&
              (T_surge[5] > 0.0)) || ((K[5] > ctrl_DP_basic_P.C[17]) && (K[5] <
               ctrl_DP_basic_P.C[23]) && (T_surge[5] < 0.0))) {
    /* '<S47>:1:307' */
    /* '<S47>:1:308' */
    c1[0] = ctrl_DP_basic_P.C[17];
    c1[1] = ctrl_DP_basic_P.C[23];
    c1_0[0] = ctrl_DP_basic_P.C[17] - K[5];
    c1_0[1] = ctrl_DP_basic_P.C[23] - K[5];
    ctrl_DP_basic_abs(c1_0, varargin_1);
    ixstart = 1;
    rtb_Saturation1 = varargin_1[0];
    b_ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p3 = 2;
      exitg11 = false;
      while ((!exitg11) && (p3 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_Saturation1 = varargin_1[1];
          b_ixstart = 1;
          exitg11 = true;
        } else {
          p3 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_Saturation1)) {
      b_ixstart = 1;
    }

    /* '<S47>:1:310' */
    rtb_TmpSignalConversionAtSFun_6 = c1[b_ixstart];
  } else {
    /* '<S47>:1:312' */
    rtb_TmpSignalConversionAtSFun_6 = K[5];
  }

  if (((rtb_TmpSignalConversionAtSFun_5 > ctrl_DP_basic_P.C[5] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_5 < ctrl_DP_basic_P.C[11] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_5 > ctrl_DP_basic_P.C[17] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_5 < ctrl_DP_basic_P.C[23] - 0.1))) {
    /* '<S47>:1:314' */
    /* '<S47>:1:315' */
    T_surge[5] = 0.0;
  } else {
    /* '<S47>:1:317' */
  }

  /*  Thruster 2&3  */
  if (rtb_psi_dot == ctrl_DP_basic_P.C[7]) {
    /* '<S47>:1:321' */
    /* '<S47>:1:322' */
    rtb_Row1_o = -90.0 - (ctrl_DP_basic_P.C[7] - -90.0);
  } else if (rtb_psi_dot == ctrl_DP_basic_P.C[1]) {
    /* '<S47>:1:323' */
    /* '<S47>:1:324' */
    rtb_Row1_o = -90.0 - (ctrl_DP_basic_P.C[1] - -90.0);
  } else if (rtb_psi_dot == ctrl_DP_basic_P.C[13]) {
    /* '<S47>:1:325' */
    /* '<S47>:1:326' */
    rtb_Row1_o = -90.0 - (ctrl_DP_basic_P.C[13] - -90.0);
  } else if (rtb_psi_dot == ctrl_DP_basic_P.C[19]) {
    /* '<S47>:1:327' */
    /* '<S47>:1:328' */
    rtb_Row1_o = -90.0 - (ctrl_DP_basic_P.C[19] - -90.0);
  } else if (rtb_Row1_o == ctrl_DP_basic_P.C[8]) {
    /* '<S47>:1:330' */
    /* '<S47>:1:331' */
    rtb_psi_dot = 90.0 - (ctrl_DP_basic_P.C[8] - 90.0);
  } else if (rtb_Row1_o == ctrl_DP_basic_P.C[2]) {
    /* '<S47>:1:332' */
    /* '<S47>:1:333' */
    rtb_psi_dot = 90.0 - (ctrl_DP_basic_P.C[2] - 90.0);
  } else if (rtb_Row1_o == ctrl_DP_basic_P.C[14]) {
    /* '<S47>:1:334' */
    /* '<S47>:1:335' */
    rtb_psi_dot = 90.0 - (ctrl_DP_basic_P.C[14] - 90.0);
  } else {
    if (rtb_Row1_o == ctrl_DP_basic_P.C[20]) {
      /* '<S47>:1:336' */
      /* '<S47>:1:337' */
      rtb_psi_dot = 90.0 - (ctrl_DP_basic_P.C[20] - 90.0);
    }
  }

  /*  Thruster 5&6 */
  if (rtb_TmpSignalConversionAtSFun_7 == ctrl_DP_basic_P.C[10]) {
    /* '<S47>:1:341' */
    /* '<S47>:1:342' */
    rtb_TmpSignalConversionAtSFun_6 = K[4] - (ctrl_DP_basic_P.C[10] - K[4]);
  } else if (rtb_TmpSignalConversionAtSFun_7 == ctrl_DP_basic_P.C[4]) {
    /* '<S47>:1:343' */
    /* '<S47>:1:344' */
    rtb_TmpSignalConversionAtSFun_6 = K[4] - (ctrl_DP_basic_P.C[4] - K[4]);
  } else if (rtb_TmpSignalConversionAtSFun_7 == ctrl_DP_basic_P.C[16]) {
    /* '<S47>:1:345' */
    /* '<S47>:1:346' */
    rtb_TmpSignalConversionAtSFun_6 = K[4] - (ctrl_DP_basic_P.C[16] - K[4]);
  } else if (rtb_TmpSignalConversionAtSFun_7 == ctrl_DP_basic_P.C[22]) {
    /* '<S47>:1:347' */
    /* '<S47>:1:348' */
    rtb_TmpSignalConversionAtSFun_6 = K[4] - (ctrl_DP_basic_P.C[22] - K[4]);
  } else if (rtb_TmpSignalConversionAtSFun_6 == ctrl_DP_basic_P.C[11]) {
    /* '<S47>:1:350' */
    /* '<S47>:1:351' */
    rtb_TmpSignalConversionAtSFun_7 = K[5] - (ctrl_DP_basic_P.C[11] - K[5]);
  } else if (rtb_TmpSignalConversionAtSFun_6 == ctrl_DP_basic_P.C[5]) {
    /* '<S47>:1:352' */
    /* '<S47>:1:353' */
    rtb_TmpSignalConversionAtSFun_7 = K[5] - (ctrl_DP_basic_P.C[5] - K[5]);
  } else if (rtb_TmpSignalConversionAtSFun_6 == ctrl_DP_basic_P.C[17]) {
    /* '<S47>:1:354' */
    /* '<S47>:1:355' */
    rtb_TmpSignalConversionAtSFun_7 = K[5] - (ctrl_DP_basic_P.C[17] - K[5]);
  } else {
    if (rtb_TmpSignalConversionAtSFun_6 == ctrl_DP_basic_P.C[23]) {
      /* '<S47>:1:356' */
      /* '<S47>:1:357' */
      rtb_TmpSignalConversionAtSFun_7 = K[5] - (ctrl_DP_basic_P.C[23] - K[5]);
    }
  }

  /*  Thruster 4 & 1 */
  if (rtb_TmpSignalConversionAtSFun_0 == ctrl_DP_basic_P.C[9]) {
    /* '<S47>:1:360' */
    /* '<S47>:1:361' */
    rtb_Row1 = K[3] - (ctrl_DP_basic_P.C[9] - K[3]);
  } else if (rtb_TmpSignalConversionAtSFun_0 == ctrl_DP_basic_P.C[3]) {
    /* '<S47>:1:362' */
    /* '<S47>:1:363' */
    rtb_Row1 = K[3] - (ctrl_DP_basic_P.C[3] - K[3]);
  } else if (rtb_TmpSignalConversionAtSFun_0 == ctrl_DP_basic_P.C[15]) {
    /* '<S47>:1:364' */
    /* '<S47>:1:365' */
    rtb_Row1 = K[3] - (ctrl_DP_basic_P.C[15] - K[3]);
  } else {
    if (rtb_TmpSignalConversionAtSFun_0 == ctrl_DP_basic_P.C[21]) {
      /* '<S47>:1:366' */
      /* '<S47>:1:367' */
      rtb_Row1 = K[3] - (ctrl_DP_basic_P.C[21] - K[3]);
    }
  }

  if (rtb_Row1 == ctrl_DP_basic_P.C[6]) {
    /* '<S47>:1:370' */
    /* '<S47>:1:371' */
    rtb_TmpSignalConversionAtSFun_0 = 180.0 - (ctrl_DP_basic_P.C[6] - 180.0);
  } else if (rtb_Row1 == ctrl_DP_basic_P.C[0]) {
    /* '<S47>:1:372' */
    /* '<S47>:1:373' */
    rtb_TmpSignalConversionAtSFun_0 = 180.0 - (ctrl_DP_basic_P.C[0] - 180.0);
  } else if (rtb_Row1 == ctrl_DP_basic_P.C[12]) {
    /* '<S47>:1:374' */
    /* '<S47>:1:375' */
    rtb_TmpSignalConversionAtSFun_0 = 180.0 - (ctrl_DP_basic_P.C[12] - 180.0);
  } else {
    if (rtb_Row1 == ctrl_DP_basic_P.C[18]) {
      /* '<S47>:1:376' */
      /* '<S47>:1:377' */
      rtb_TmpSignalConversionAtSFun_0 = 180.0 - (ctrl_DP_basic_P.C[18] - 180.0);
    }
  }

  /* '<S47>:1:380' */
  /*  T_d = -Desired_thrust; */
  /* % Update outputs */
  /* '<S47>:1:387' */
  rtb_sys[0] = rtb_Row1;
  rtb_sys[1] = rtb_psi_dot;
  rtb_sys[2] = rtb_Row1_o;
  rtb_sys[3] = rtb_TmpSignalConversionAtSFun_0;
  rtb_sys[4] = rtb_TmpSignalConversionAtSFun_7;
  rtb_sys[5] = rtb_TmpSignalConversionAtSFun_6;
  for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
    rtb_sys[b_ixstart + 6] = T_surge[b_ixstart];
  }

  /* Switch: '<S9>/Choosing Fixed // Azimuth angle' incorporates:
   *  Constant: '<S9>/Switch  Azimuth//Fixed angles'
   *  Constant: '<S9>/constant angle'
   */
  for (i = 0; i < 6; i++) {
    if (ctrl_DP_basic_P.Thruster_lock >=
        ctrl_DP_basic_P.ChoosingFixedAzimuthangle_Thres) {
      ctrl_DP_basic_B.ChoosingFixedAzimuthangle[i] = rtb_sys[i];
    } else {
      ctrl_DP_basic_B.ChoosingFixedAzimuthangle[i] =
        ctrl_DP_basic_P.constantangle_Value[i];
    }
  }

  /* End of Switch: '<S9>/Choosing Fixed // Azimuth angle' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
  }

  /* Outputs for Iterator SubSystem: '<S9>/For Each Subsystem' incorporates:
   *  ForEach: '<S46>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
    /* ForEachSliceSelector: '<S46>/ImpSel_InsertedFor_reset_at_outport_0' */
    rtb_ImpSel_InsertedFor_reset_at = ctrl_DP_basic_B.reset_a3[ForEach_itr];
    if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
      /* DiscreteIntegrator: '<S46>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S9>/constant angle'
       *  ForEachSliceSelector: '<S46>/ImpSel_InsertedFor_initial angle _at_outport_0'
       */
      if (ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].
          DiscreteTimeIntegrator_IC_LOADI != 0) {
        ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE =
          ctrl_DP_basic_P.constantangle_Value[ForEach_itr];
      }

      if (((rtb_ImpSel_InsertedFor_reset_at > 0.0) &&
           (ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].
            DiscreteTimeIntegrator_PrevRese <= 0)) ||
          ((rtb_ImpSel_InsertedFor_reset_at <= 0.0) &&
           (ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].
            DiscreteTimeIntegrator_PrevRese == 1))) {
        ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE =
          ctrl_DP_basic_P.constantangle_Value[ForEach_itr];
      }

      ctrl_DP_basic_B.CoreSubsys[ForEach_itr].angle =
        ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE;

      /* End of DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */

      /* Gain: '<S49>/Gain1' */
      rtb_Saturation1 = ctrl_DP_basic_P.CoreSubsys.Gain1_Gain *
        ctrl_DP_basic_B.CoreSubsys[ForEach_itr].angle;

      /* Delay: '<S46>/Delay' */
      ctrl_DP_basic_B.CoreSubsys[ForEach_itr].Delay =
        ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].Delay_DSTATE;

      /* MATLAB Function: '<S46>/MATLAB Function' */
      /* MATLAB Function 'Thrust allocation1/For Each Subsystem/MATLAB Function': '<S50>:1' */
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
      /* '<S50>:1:39' */
      /* '<S50>:1:40' */
      /*  s = sign(angle); */
      /* '<S50>:1:43' */
      rtb_TmpSignalConversionAtSFun_7 = fabs(rt_remd_snf(rtb_Saturation1 +
        3.1415926535897931, 6.2831853071795862) / 6.2831853071795862);
      if (rtb_Saturation1 < 0.0) {
        rtb_TmpSignalConversionAtSFun_6 = -1.0;
      } else if (rtb_Saturation1 > 0.0) {
        rtb_TmpSignalConversionAtSFun_6 = 1.0;
      } else if (rtb_Saturation1 == 0.0) {
        rtb_TmpSignalConversionAtSFun_6 = 0.0;
      } else {
        rtb_TmpSignalConversionAtSFun_6 = rtb_Saturation1;
      }

      if (rtb_TmpSignalConversionAtSFun_7 > 0.0) {
        rtb_TmpSignalConversionAtSFun_7 = 1.0;
      } else {
        if (rtb_TmpSignalConversionAtSFun_7 == 0.0) {
          rtb_TmpSignalConversionAtSFun_7 = 0.0;
        }
      }

      rtb_TmpSignalConversionAtSFun_7 = (rtb_TmpSignalConversionAtSFun_7 - 1.0) *
        2.0 + rtb_TmpSignalConversionAtSFun_6;
      if (rtb_Saturation1 < 0.0) {
        rtb_TmpSignalConversionAtSFun_6 = -1.0;
      } else if (rtb_Saturation1 > 0.0) {
        rtb_TmpSignalConversionAtSFun_6 = 1.0;
      } else if (rtb_Saturation1 == 0.0) {
        rtb_TmpSignalConversionAtSFun_6 = 0.0;
      } else {
        rtb_TmpSignalConversionAtSFun_6 = rtb_Saturation1;
      }

      if (rtb_TmpSignalConversionAtSFun_7 < 0.0) {
        rtb_TmpSignalConversionAtSFun_7 = -1.0;
      } else if (rtb_TmpSignalConversionAtSFun_7 > 0.0) {
        rtb_TmpSignalConversionAtSFun_7 = 1.0;
      } else {
        if (rtb_TmpSignalConversionAtSFun_7 == 0.0) {
          rtb_TmpSignalConversionAtSFun_7 = 0.0;
        }
      }

      rtb_Out2_CoreSubsysCanOut = rt_remd_snf(rtb_TmpSignalConversionAtSFun_6 *
        3.1415926535897931 + rtb_Saturation1, 6.2831853071795862) -
        rtb_TmpSignalConversionAtSFun_7 * 3.1415926535897931;

      /* End of MATLAB Function: '<S46>/MATLAB Function' */
    }

    /* MATLAB Function: '<S46>/MATLAB Function1' incorporates:
     *  ForEachSliceSelector: '<S46>/ImpSel_InsertedFor_Desired Angle_at_outport_0'
     */
    /* MATLAB Function 'Thrust allocation1/For Each Subsystem/MATLAB Function1': '<S51>:1' */
    /* '<S51>:1:3' */
    rtb_Saturation1 = ctrl_DP_basic_B.ChoosingFixedAzimuthangle[ForEach_itr] -
      ctrl_DP_basic_B.CoreSubsys[ForEach_itr].Delay;
    if (fabs(rtb_Saturation1) >= 360.0) {
      /* '<S51>:1:4' */
      /* '<S51>:1:5' */
      rtb_Saturation1 = rt_remd_snf(rtb_Saturation1, 360.0);
    }

    if (fabs(rtb_Saturation1) >= 180.0) {
      /* '<S51>:1:8' */
      /* '<S51>:1:9' */
      if (rtb_Saturation1 < 0.0) {
        rtb_TmpSignalConversionAtSFun_6 = -1.0;
      } else if (rtb_Saturation1 > 0.0) {
        rtb_TmpSignalConversionAtSFun_6 = 1.0;
      } else if (rtb_Saturation1 == 0.0) {
        rtb_TmpSignalConversionAtSFun_6 = 0.0;
      } else {
        rtb_TmpSignalConversionAtSFun_6 = rtb_Saturation1;
      }

      rtb_Saturation1 -= rtb_TmpSignalConversionAtSFun_6 * 360.0;
    }

    /* End of MATLAB Function: '<S46>/MATLAB Function1' */

    /* Saturate: '<S46>/Max Rotation Rate' */
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
    if (rtb_Saturation1 > ctrl_DP_basic_P.Max_rotation) {
      ctrl_DP_basic_B.CoreSubsys[ForEach_itr].MaxRotationRate =
        ctrl_DP_basic_P.Max_rotation;
    } else if (rtb_Saturation1 < -ctrl_DP_basic_P.Max_rotation) {
      ctrl_DP_basic_B.CoreSubsys[ForEach_itr].MaxRotationRate =
        -ctrl_DP_basic_P.Max_rotation;
    } else {
      ctrl_DP_basic_B.CoreSubsys[ForEach_itr].MaxRotationRate = rtb_Saturation1;
    }

    /* End of Saturate: '<S46>/Max Rotation Rate' */
    if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
      /* ForEachSliceAssignment: '<S46>/ImpAsg_InsertedFor_Out2 _at_inport_0' */
      rtb_ImpAsg_InsertedFor_Out2_at_[ForEach_itr] = rtb_Out2_CoreSubsysCanOut;
    }
  }

  /* End of Outputs for SubSystem: '<S9>/For Each Subsystem' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* Saturate: '<S53>/Saturation 1' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[0] >
        ctrl_DP_basic_P.Saturation1_UpperSat) {
      ctrl_DP_basic_B.Saturation1 = ctrl_DP_basic_P.Saturation1_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[0] <
               ctrl_DP_basic_P.Saturation1_LowerSat) {
      ctrl_DP_basic_B.Saturation1 = ctrl_DP_basic_P.Saturation1_LowerSat;
    } else {
      ctrl_DP_basic_B.Saturation1 = rtb_ImpAsg_InsertedFor_Out2_at_[0];
    }

    /* End of Saturate: '<S53>/Saturation 1' */

    /* Saturate: '<S52>/Saturation 6' */
    if (rtb_output_idx_10 > ctrl_DP_basic_P.Max_thrust) {
      rtb_Saturation1 = ctrl_DP_basic_P.Max_thrust;
    } else if (rtb_output_idx_10 < -ctrl_DP_basic_P.Max_thrust) {
      rtb_Saturation1 = -ctrl_DP_basic_P.Max_thrust;
    } else {
      rtb_Saturation1 = rtb_output_idx_10;
    }

    /* End of Saturate: '<S52>/Saturation 6' */

    /* Polyval: '<S52>/pwm thruster 6' */
    ctrl_DP_basic_B.pwmthruster6 = ctrl_DP_basic_P.thrust_to_pwm_coeff[0];
    for (ixstart = 0; ixstart < 5; ixstart++) {
      ctrl_DP_basic_B.pwmthruster6 = ctrl_DP_basic_B.pwmthruster6 *
        rtb_Saturation1 + ctrl_DP_basic_P.thrust_to_pwm_coeff[ixstart + 1];
    }

    /* End of Polyval: '<S52>/pwm thruster 6' */

    /* Saturate: '<S53>/Saturation 2' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[1] >
        ctrl_DP_basic_P.Saturation2_UpperSat) {
      ctrl_DP_basic_B.Saturation2 = ctrl_DP_basic_P.Saturation2_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[1] <
               ctrl_DP_basic_P.Saturation2_LowerSat) {
      ctrl_DP_basic_B.Saturation2 = ctrl_DP_basic_P.Saturation2_LowerSat;
    } else {
      ctrl_DP_basic_B.Saturation2 = rtb_ImpAsg_InsertedFor_Out2_at_[1];
    }

    /* End of Saturate: '<S53>/Saturation 2' */

    /* Saturate: '<S53>/Saturation 3' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[2] >
        ctrl_DP_basic_P.Saturation3_UpperSat) {
      ctrl_DP_basic_B.Saturation3 = ctrl_DP_basic_P.Saturation3_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[2] <
               ctrl_DP_basic_P.Saturation3_LowerSat) {
      ctrl_DP_basic_B.Saturation3 = ctrl_DP_basic_P.Saturation3_LowerSat;
    } else {
      ctrl_DP_basic_B.Saturation3 = rtb_ImpAsg_InsertedFor_Out2_at_[2];
    }

    /* End of Saturate: '<S53>/Saturation 3' */

    /* Saturate: '<S53>/Saturation 4' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[3] >
        ctrl_DP_basic_P.Saturation4_UpperSat) {
      ctrl_DP_basic_B.Saturation4 = ctrl_DP_basic_P.Saturation4_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[3] <
               ctrl_DP_basic_P.Saturation4_LowerSat) {
      ctrl_DP_basic_B.Saturation4 = ctrl_DP_basic_P.Saturation4_LowerSat;
    } else {
      ctrl_DP_basic_B.Saturation4 = rtb_ImpAsg_InsertedFor_Out2_at_[3];
    }

    /* End of Saturate: '<S53>/Saturation 4' */

    /* Saturate: '<S53>/Saturation 5' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[4] >
        ctrl_DP_basic_P.Saturation5_UpperSat) {
      ctrl_DP_basic_B.Saturation5 = ctrl_DP_basic_P.Saturation5_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[4] <
               ctrl_DP_basic_P.Saturation5_LowerSat) {
      ctrl_DP_basic_B.Saturation5 = ctrl_DP_basic_P.Saturation5_LowerSat;
    } else {
      ctrl_DP_basic_B.Saturation5 = rtb_ImpAsg_InsertedFor_Out2_at_[4];
    }

    /* End of Saturate: '<S53>/Saturation 5' */

    /* Saturate: '<S53>/Saturation 6' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[5] >
        ctrl_DP_basic_P.Saturation6_UpperSat) {
      ctrl_DP_basic_B.Saturation6 = ctrl_DP_basic_P.Saturation6_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[5] <
               ctrl_DP_basic_P.Saturation6_LowerSat) {
      ctrl_DP_basic_B.Saturation6 = ctrl_DP_basic_P.Saturation6_LowerSat;
    } else {
      ctrl_DP_basic_B.Saturation6 = rtb_ImpAsg_InsertedFor_Out2_at_[5];
    }

    /* End of Saturate: '<S53>/Saturation 6' */

    /* Saturate: '<S52>/Saturation 7' */
    if (rtb_output_idx_0 > ctrl_DP_basic_P.Max_thrust) {
      ctrl_DP_basic_B.Saturation7[0] = ctrl_DP_basic_P.Max_thrust;
    } else if (rtb_output_idx_0 < -ctrl_DP_basic_P.Max_thrust) {
      ctrl_DP_basic_B.Saturation7[0] = -ctrl_DP_basic_P.Max_thrust;
    } else {
      ctrl_DP_basic_B.Saturation7[0] = rtb_output_idx_0;
    }

    if (rtb_output_idx_2 > ctrl_DP_basic_P.Max_thrust) {
      ctrl_DP_basic_B.Saturation7[1] = ctrl_DP_basic_P.Max_thrust;
    } else if (rtb_output_idx_2 < -ctrl_DP_basic_P.Max_thrust) {
      ctrl_DP_basic_B.Saturation7[1] = -ctrl_DP_basic_P.Max_thrust;
    } else {
      ctrl_DP_basic_B.Saturation7[1] = rtb_output_idx_2;
    }

    if (rtb_output_idx_4 > ctrl_DP_basic_P.Max_thrust) {
      ctrl_DP_basic_B.Saturation7[2] = ctrl_DP_basic_P.Max_thrust;
    } else if (rtb_output_idx_4 < -ctrl_DP_basic_P.Max_thrust) {
      ctrl_DP_basic_B.Saturation7[2] = -ctrl_DP_basic_P.Max_thrust;
    } else {
      ctrl_DP_basic_B.Saturation7[2] = rtb_output_idx_4;
    }

    if (rtb_output_idx_6 > ctrl_DP_basic_P.Max_thrust) {
      ctrl_DP_basic_B.Saturation7[3] = ctrl_DP_basic_P.Max_thrust;
    } else if (rtb_output_idx_6 < -ctrl_DP_basic_P.Max_thrust) {
      ctrl_DP_basic_B.Saturation7[3] = -ctrl_DP_basic_P.Max_thrust;
    } else {
      ctrl_DP_basic_B.Saturation7[3] = rtb_output_idx_6;
    }

    if (rtb_output_idx_8 > ctrl_DP_basic_P.Max_thrust) {
      ctrl_DP_basic_B.Saturation7[4] = ctrl_DP_basic_P.Max_thrust;
    } else if (rtb_output_idx_8 < -ctrl_DP_basic_P.Max_thrust) {
      ctrl_DP_basic_B.Saturation7[4] = -ctrl_DP_basic_P.Max_thrust;
    } else {
      ctrl_DP_basic_B.Saturation7[4] = rtb_output_idx_8;
    }

    if (rtb_output_idx_10 > ctrl_DP_basic_P.Max_thrust) {
      ctrl_DP_basic_B.Saturation7[5] = ctrl_DP_basic_P.Max_thrust;
    } else if (rtb_output_idx_10 < -ctrl_DP_basic_P.Max_thrust) {
      ctrl_DP_basic_B.Saturation7[5] = -ctrl_DP_basic_P.Max_thrust;
    } else {
      ctrl_DP_basic_B.Saturation7[5] = rtb_output_idx_10;
    }

    /* End of Saturate: '<S52>/Saturation 7' */
  }

  /* Integrator: '<S6>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator_Reset_ZCE_n,
                       ctrl_DP_basic_B.reset_g);

    /* evaluate zero-crossings */
    if (zcEvent || ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading) {
      ctrl_DP_basic_X.Integrator_CSTATE_l[0] = ctrl_DP_basic_B.x;
      ctrl_DP_basic_X.Integrator_CSTATE_l[1] = ctrl_DP_basic_B.y;
      ctrl_DP_basic_X.Integrator_CSTATE_l[2] = ctrl_DP_basic_B.psi;
    }
  }

  ctrl_DP_basic_B.Integrator[0] = ctrl_DP_basic_X.Integrator_CSTATE_l[0];
  ctrl_DP_basic_B.Integrator[1] = ctrl_DP_basic_X.Integrator_CSTATE_l[1];
  ctrl_DP_basic_B.Integrator[2] = ctrl_DP_basic_X.Integrator_CSTATE_l[2];

  /* Saturate: '<S40>/Saturation' */
  if (ctrl_DP_basic_B.Integrator[2] > ctrl_DP_basic_P.Saturation_UpperSat_l) {
    rtb_Row1_o = ctrl_DP_basic_P.Saturation_UpperSat_l;
  } else if (ctrl_DP_basic_B.Integrator[2] <
             ctrl_DP_basic_P.Saturation_LowerSat_cz) {
    rtb_Row1_o = ctrl_DP_basic_P.Saturation_LowerSat_cz;
  } else {
    rtb_Row1_o = ctrl_DP_basic_B.Integrator[2];
  }

  /* End of Saturate: '<S40>/Saturation' */

  /* Signum: '<S40>/Sign' */
  if (rtb_Row1_o < 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = -1.0;
  } else if (rtb_Row1_o > 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 1.0;
  } else if (rtb_Row1_o == 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_7 = rtb_Row1_o;
  }

  /* Gain: '<S40>/Gain' incorporates:
   *  Signum: '<S40>/Sign'
   */
  rtb_psi_dot = ctrl_DP_basic_P.Gain_Gain_d * rtb_TmpSignalConversionAtSFun_7;

  /* Sum: '<S40>/Sum1' */
  rtb_Row1_o += rtb_psi_dot;

  /* Math: '<S40>/Math Function' incorporates:
   *  Constant: '<S40>/Constant'
   */
  rtb_Row1_o = rt_remd_snf(rtb_Row1_o, ctrl_DP_basic_P.Constant_Value_p4);

  /* Sum: '<S40>/Sum' */
  ctrl_DP_basic_B.Sum_f = rtb_Row1_o - rtb_psi_dot;

  /* Saturate: '<S41>/Saturation' */
  if (ctrl_DP_basic_B.psi > ctrl_DP_basic_P.Saturation_UpperSat_o) {
    rtb_Row1_o = ctrl_DP_basic_P.Saturation_UpperSat_o;
  } else if (ctrl_DP_basic_B.psi < ctrl_DP_basic_P.Saturation_LowerSat_j) {
    rtb_Row1_o = ctrl_DP_basic_P.Saturation_LowerSat_j;
  } else {
    rtb_Row1_o = ctrl_DP_basic_B.psi;
  }

  /* End of Saturate: '<S41>/Saturation' */

  /* Signum: '<S41>/Sign' */
  if (rtb_Row1_o < 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = -1.0;
  } else if (rtb_Row1_o > 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 1.0;
  } else if (rtb_Row1_o == 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_7 = rtb_Row1_o;
  }

  /* Gain: '<S41>/Gain' incorporates:
   *  Signum: '<S41>/Sign'
   */
  rtb_psi_dot = ctrl_DP_basic_P.Gain_Gain_h * rtb_TmpSignalConversionAtSFun_7;

  /* Sum: '<S41>/Sum1' */
  rtb_Row1_o += rtb_psi_dot;

  /* Math: '<S41>/Math Function' incorporates:
   *  Constant: '<S41>/Constant'
   */
  rtb_Row1_o = rt_remd_snf(rtb_Row1_o, ctrl_DP_basic_P.Constant_Value_i);

  /* Sum: '<S41>/Sum' */
  rtb_Row1_o -= rtb_psi_dot;

  /* Fcn: '<S6>/Fcn' */
  rtb_psi_dot = rtb_Row1_o;

  /* Integrator: '<S6>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator2_Reset_ZCE,
                       ctrl_DP_basic_B.reset_g);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_basic_X.Integrator2_CSTATE[0] = (ctrl_DP_basic_P.Integrator2_IC[0]);
      ctrl_DP_basic_X.Integrator2_CSTATE[1] = (ctrl_DP_basic_P.Integrator2_IC[1]);
      ctrl_DP_basic_X.Integrator2_CSTATE[2] = (ctrl_DP_basic_P.Integrator2_IC[2]);
    }
  }

  ctrl_DP_basic_B.Integrator2[0] = ctrl_DP_basic_X.Integrator2_CSTATE[0];
  ctrl_DP_basic_B.Integrator2[1] = ctrl_DP_basic_X.Integrator2_CSTATE[1];
  ctrl_DP_basic_B.Integrator2[2] = ctrl_DP_basic_X.Integrator2_CSTATE[2];

  /* Sum: '<S6>/Sum' */
  rtb_Sum_nu[0] = ctrl_DP_basic_B.x - ctrl_DP_basic_B.Integrator[0];
  rtb_Sum_nu[1] = ctrl_DP_basic_B.y - ctrl_DP_basic_B.Integrator[1];
  rtb_Sum_nu[2] = rtb_Row1_o - ctrl_DP_basic_B.Sum_f;

  /* Product: '<S6>/Matrix Multiply2' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_Integrator2[b_ixstart] = 0.0;
    rtb_Integrator2[b_ixstart] +=
      ctrl_DP_basic_B.sf_MATLABFunction2_p.K_d[b_ixstart] * rtb_Sum_nu[0];
    rtb_Integrator2[b_ixstart] +=
      ctrl_DP_basic_B.sf_MATLABFunction2_p.K_d[b_ixstart + 3] * rtb_Sum_nu[1];
    rtb_Integrator2[b_ixstart] +=
      ctrl_DP_basic_B.sf_MATLABFunction2_p.K_d[b_ixstart + 6] * rtb_Sum_nu[2];
  }

  /* End of Product: '<S6>/Matrix Multiply2' */

  /* Fcn: '<S38>/Row2' */
  rtb_TmpSignalConversionAtSFun_7 = rtb_Integrator2[0];
  rtb_TmpSignalConversionAtSFun_6 = rtb_Integrator2[1];

  /* Fcn: '<S38>/Row3' */
  rtb_TmpSignalConversionAtSFun_0 = rtb_Integrator2[2];

  /* Sum: '<S6>/Sum2' incorporates:
   *  Fcn: '<S38>/Row1'
   *  Fcn: '<S38>/Row2'
   *  Fcn: '<S38>/Row3'
   *  Fcn: '<S6>/Fcn'
   */
  rtb_Integrator2[0] = (cos(rtb_Row1_o) * rtb_Integrator2[0] + sin(rtb_Row1_o) *
                        rtb_Integrator2[1]) + ctrl_DP_basic_B.Sum3[0];
  rtb_Integrator2[1] = (-sin(rtb_Row1_o) * rtb_TmpSignalConversionAtSFun_7 + cos
                        (rtb_Row1_o) * rtb_TmpSignalConversionAtSFun_6) +
    ctrl_DP_basic_B.Sum3[1];
  rtb_Integrator2[2] = rtb_TmpSignalConversionAtSFun_0 + ctrl_DP_basic_B.Sum3[2];

  /* MATLAB Function: '<S6>/C(nu)*nu' */
  /* MATLAB Function 'Nonlinear Passisve Observer/D(nu)*nu': '<S36>:1' */
  /* '<S36>:1:3' */
  /* '<S36>:1:4' */
  /* '<S36>:1:5' */
  /* % DAMPING  */
  /*  Surge: */
  /*  Based on fitting of towing data from -0.8 < u < 0.8 m/s */
  /* '<S36>:1:11' */
  /*  Sway: */
  /*  Based on fitting of towing data from -0.45 < u < 0.45 m/s */
  /* '<S36>:1:17' */
  /*  Yaw: */
  /*  Based on fitting of towing data from -8 < u < 8 deg/s */
  /*  The fitting range is limited. Towing should be performed for higher */
  /*  velocities. */
  /* '<S36>:1:25' */
  /*  Y_vvv og N_rrr er fra curvefitting uten minus, men ser ut til å fungere */
  /*  med minus.  */
  /* % Assembly of the damping matrix */
  /* '<S36>:1:40' */
  /* '<S36>:1:41' */
  /* '<S36>:1:42' */
  /*  Y_r + Y_rr*abs(r) + Y_rrr*r^2 + Y_vr*abs(v); Not verified, temporarily disabled */
  /*  N_v + N_vv*abs(v) + N_vvv*v^2 + N_rv*abs(r); Not verified, temporarily disabled */
  /* '<S36>:1:47' */
  /* '<S36>:1:54' */
  /* MATLAB Function 'Nonlinear Passisve Observer/C(nu)*nu': '<S35>:1' */
  /* '<S35>:1:3' */
  /* '<S35>:1:4' */
  /* '<S35>:1:5' */
  /* % MATRICES */
  /* 0.0432; */
  /* % Added mass */
  /* % Correolis matrix */
  /* '<S35>:1:14' */
  rtb_Saturation1 = -99.03 * ctrl_DP_basic_B.Integrator1_g[1] - -0.525 *
    ctrl_DP_basic_B.Integrator1_g[2];

  /* '<S35>:1:15' */
  rtb_Row1 = 124.658 * ctrl_DP_basic_B.Integrator1_g[0];

  /* Sum: '<S6>/Sum3' incorporates:
   *  Fcn: '<S39>/Row1'
   *  Fcn: '<S39>/Row2'
   *  Fcn: '<S39>/Row3'
   *  Fcn: '<S6>/Fcn'
   */
  /* '<S35>:1:17' */
  /* '<S35>:1:24' */
  tmp_0[0] = cos(rtb_Row1_o) * ctrl_DP_basic_B.Integrator2[0] + sin(rtb_Row1_o) *
    ctrl_DP_basic_B.Integrator2[1];
  tmp_0[1] = -sin(rtb_Row1_o) * ctrl_DP_basic_B.Integrator2[0] + cos(rtb_Row1_o)
    * ctrl_DP_basic_B.Integrator2[1];
  tmp_0[2] = ctrl_DP_basic_B.Integrator2[2];

  /* MATLAB Function: '<S6>/D(nu)*nu' */
  tmp_1[0] = (0.0 * fabs(ctrl_DP_basic_B.Integrator1_g[0]) + -2.332) +
    ctrl_DP_basic_B.Integrator1_g[0] * ctrl_DP_basic_B.Integrator1_g[0] * -8.557;
  tmp_1[3] = 0.0;
  tmp_1[6] = 0.0;
  tmp_1[1] = 0.0;
  tmp_1[4] = (0.3976 * fabs(ctrl_DP_basic_B.Integrator1_g[1]) + -4.673) +
    ctrl_DP_basic_B.Integrator1_g[1] * ctrl_DP_basic_B.Integrator1_g[1] * -313.3;
  tmp_1[7] = 0.0;
  tmp_1[2] = 0.0;
  tmp_1[5] = 0.0;
  tmp_1[8] = (-0.01148 * fabs(ctrl_DP_basic_B.Integrator1_g[2]) + -0.01675) +
    ctrl_DP_basic_B.Integrator1_g[2] * ctrl_DP_basic_B.Integrator1_g[2] *
    -0.0003578;
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_y_n[3 * b_ixstart] = -tmp_1[3 * b_ixstart];
    rtb_y_n[1 + 3 * b_ixstart] = -tmp_1[3 * b_ixstart + 1];
    rtb_y_n[2 + 3 * b_ixstart] = -tmp_1[3 * b_ixstart + 2];
  }

  /* MATLAB Function: '<S6>/C(nu)*nu' */
  tmp_2[0] = 0.0;
  tmp_2[3] = 0.0;
  tmp_2[6] = rtb_Saturation1;
  tmp_2[1] = 0.0;
  tmp_2[4] = 0.0;
  tmp_2[7] = rtb_Row1;
  tmp_2[2] = -rtb_Saturation1;
  tmp_2[5] = -rtb_Row1;
  tmp_2[8] = 0.0;

  /* Sum: '<S6>/Sum3' incorporates:
   *  MATLAB Function: '<S6>/D(nu)*nu'
   */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_TmpSignalConversionAtSFu_pa[b_ixstart] = (tmp_0[b_ixstart] +
      rtb_Integrator2[b_ixstart]) - ((rtb_y_n[b_ixstart + 3] *
      ctrl_DP_basic_B.Integrator1_g[1] + rtb_y_n[b_ixstart] *
      ctrl_DP_basic_B.Integrator1_g[0]) + rtb_y_n[b_ixstart + 6] *
      ctrl_DP_basic_B.Integrator1_g[2]);
  }

  /* MATLAB Function: '<S6>/C(nu)*nu' incorporates:
   *  Sum: '<S6>/Sum3'
   */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    tmp_0[b_ixstart] = tmp_2[b_ixstart + 6] * ctrl_DP_basic_B.Integrator1_g[2] +
      (tmp_2[b_ixstart + 3] * ctrl_DP_basic_B.Integrator1_g[1] + tmp_2[b_ixstart]
       * ctrl_DP_basic_B.Integrator1_g[0]);
  }

  /* Sum: '<S6>/Sum3' */
  rtb_Integrator2[0] = rtb_TmpSignalConversionAtSFu_pa[0] - tmp_0[0];
  rtb_Integrator2[1] = rtb_TmpSignalConversionAtSFu_pa[1] - tmp_0[1];
  rtb_Integrator2[2] = rtb_TmpSignalConversionAtSFu_pa[2] - tmp_0[2];

  /* Gain: '<S6>/M^-1' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    ctrl_DP_basic_B.M1[b_ixstart] = 0.0;
    ctrl_DP_basic_B.M1[b_ixstart] += ctrl_DP_basic_P.M1_Gain[b_ixstart] *
      rtb_Integrator2[0];
    ctrl_DP_basic_B.M1[b_ixstart] += ctrl_DP_basic_P.M1_Gain[b_ixstart + 3] *
      rtb_Integrator2[1];
    ctrl_DP_basic_B.M1[b_ixstart] += ctrl_DP_basic_P.M1_Gain[b_ixstart + 6] *
      rtb_Integrator2[2];
  }

  /* End of Gain: '<S6>/M^-1' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
  }

  /* Integrator: '<S17>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator2_Reset_ZCE_m,
                       ctrl_DP_basic_B.reset_g);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_basic_X.Integrator2_CSTATE_e[0] = ctrl_DP_basic_P.Integrator2_IC_h;
      ctrl_DP_basic_X.Integrator2_CSTATE_e[1] = ctrl_DP_basic_P.Integrator2_IC_h;
      ctrl_DP_basic_X.Integrator2_CSTATE_e[2] = ctrl_DP_basic_P.Integrator2_IC_h;
    }
  }

  rtb_Integrator2[0] = ctrl_DP_basic_X.Integrator2_CSTATE_e[0];
  rtb_Integrator2[1] = ctrl_DP_basic_X.Integrator2_CSTATE_e[1];
  rtb_Integrator2[2] = ctrl_DP_basic_X.Integrator2_CSTATE_e[2];

  /* MATLAB Function: '<S17>/w_d^-2' */
  /* MATLAB Function 'Guidance/Reference model/w_d^3': '<S22>:1' */
  /* '<S22>:1:4' */
  /* MATLAB Function 'Guidance/Reference model/w_d^-2': '<S21>:1' */
  /* '<S21>:1:4' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      U_singular[b_ixstart + 3 * i] = 0.0;
      U_singular[b_ixstart + 3 * i] += rtb_w_d[3 * i] * rtb_w_d[b_ixstart];
      U_singular[b_ixstart + 3 * i] += rtb_w_d[3 * i + 1] * rtb_w_d[b_ixstart +
        3];
      U_singular[b_ixstart + 3 * i] += rtb_w_d[3 * i + 2] * rtb_w_d[b_ixstart +
        6];
    }
  }

  memcpy(&S_singular_cross[0], &U_singular[0], 9U * sizeof(real_T));
  ixstart = 0;
  b_ixstart = 3;
  p3 = 6;
  rtb_Saturation1 = fabs(U_singular[0]);
  rtb_Row1 = fabs(U_singular[1]);
  rtb_Row1_o = fabs(U_singular[2]);
  if ((rtb_Row1 > rtb_Saturation1) && (rtb_Row1 > rtb_Row1_o)) {
    ixstart = 3;
    b_ixstart = 0;
    S_singular_cross[0] = U_singular[1];
    S_singular_cross[1] = U_singular[0];
    S_singular_cross[3] = U_singular[4];
    S_singular_cross[4] = U_singular[3];
    S_singular_cross[6] = U_singular[7];
    S_singular_cross[7] = U_singular[6];
  } else {
    if (rtb_Row1_o > rtb_Saturation1) {
      ixstart = 6;
      p3 = 0;
      S_singular_cross[0] = U_singular[2];
      S_singular_cross[2] = U_singular[0];
      S_singular_cross[3] = U_singular[5];
      S_singular_cross[5] = U_singular[3];
      S_singular_cross[6] = U_singular[8];
      S_singular_cross[8] = U_singular[6];
    }
  }

  rtb_Saturation1 = S_singular_cross[1] / S_singular_cross[0];
  S_singular_cross[1] /= S_singular_cross[0];
  rtb_Row1 = S_singular_cross[2] / S_singular_cross[0];
  S_singular_cross[2] /= S_singular_cross[0];
  S_singular_cross[4] -= rtb_Saturation1 * S_singular_cross[3];
  S_singular_cross[5] -= rtb_Row1 * S_singular_cross[3];
  S_singular_cross[7] -= rtb_Saturation1 * S_singular_cross[6];
  S_singular_cross[8] -= rtb_Row1 * S_singular_cross[6];
  if (fabs(S_singular_cross[5]) > fabs(S_singular_cross[4])) {
    i = b_ixstart;
    b_ixstart = p3;
    p3 = i;
    S_singular_cross[1] = rtb_Row1;
    S_singular_cross[2] = rtb_Saturation1;
    rtb_Saturation1 = S_singular_cross[4];
    S_singular_cross[4] = S_singular_cross[5];
    S_singular_cross[5] = rtb_Saturation1;
    rtb_Saturation1 = S_singular_cross[7];
    S_singular_cross[7] = S_singular_cross[8];
    S_singular_cross[8] = rtb_Saturation1;
  }

  rtb_Row1_o = S_singular_cross[5];
  rtb_Out2_CoreSubsysCanOut = S_singular_cross[4];
  rtb_Saturation1 = S_singular_cross[5] / S_singular_cross[4];
  S_singular_cross[8] -= rtb_Saturation1 * S_singular_cross[7];
  rtb_Saturation1 = (rtb_Saturation1 * S_singular_cross[1] - S_singular_cross[2])
    / S_singular_cross[8];
  rtb_Row1 = -(S_singular_cross[7] * rtb_Saturation1 + S_singular_cross[1]) /
    S_singular_cross[4];
  rtb_y_n[ixstart] = ((1.0 - S_singular_cross[3] * rtb_Row1) - S_singular_cross
                      [6] * rtb_Saturation1) / S_singular_cross[0];
  rtb_y_n[ixstart + 1] = rtb_Row1;
  rtb_y_n[ixstart + 2] = rtb_Saturation1;
  rtb_Saturation1 = -(rtb_Row1_o / rtb_Out2_CoreSubsysCanOut) /
    S_singular_cross[8];
  rtb_Row1 = (1.0 - S_singular_cross[7] * rtb_Saturation1) / S_singular_cross[4];
  rtb_y_n[b_ixstart] = -(S_singular_cross[3] * rtb_Row1 + S_singular_cross[6] *
    rtb_Saturation1) / S_singular_cross[0];
  rtb_y_n[b_ixstart + 1] = rtb_Row1;
  rtb_y_n[b_ixstart + 2] = rtb_Saturation1;
  rtb_Saturation1 = 1.0 / S_singular_cross[8];
  rtb_Row1 = -S_singular_cross[7] * rtb_Saturation1 / S_singular_cross[4];
  rtb_y_n[p3] = -(S_singular_cross[3] * rtb_Row1 + S_singular_cross[6] *
                  rtb_Saturation1) / S_singular_cross[0];
  rtb_y_n[p3 + 1] = rtb_Row1;
  rtb_y_n[p3 + 2] = rtb_Saturation1;

  /* End of MATLAB Function: '<S17>/w_d^-2' */

  /* MATLAB Function: '<S17>/w_d^3' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      U_singular[b_ixstart + 3 * i] = 0.0;
      U_singular[b_ixstart + 3 * i] += rtb_w_d[3 * i] * rtb_w_d[b_ixstart];
      U_singular[b_ixstart + 3 * i] += rtb_w_d[3 * i + 1] * rtb_w_d[b_ixstart +
        3];
      U_singular[b_ixstart + 3 * i] += rtb_w_d[3 * i + 2] * rtb_w_d[b_ixstart +
        6];
    }
  }

  /* Product: '<S17>/Matrix Multiply1' incorporates:
   *  Sum: '<S17>/Sum'
   */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_TmpSignalConversionAtSFu_pa[b_ixstart] = rtb_y_n[b_ixstart + 6] *
      rtb_Integrator2[2] + (rtb_y_n[b_ixstart + 3] * rtb_Integrator2[1] +
      rtb_y_n[b_ixstart] * rtb_Integrator2[0]);
  }

  /* End of Product: '<S17>/Matrix Multiply1' */

  /* MATLAB Function: '<S17>/w_d^3' incorporates:
   *  Product: '<S17>/Matrix Multiply'
   */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      rtb_y_n[b_ixstart + 3 * i] = 0.0;
      rtb_y_n[b_ixstart + 3 * i] += U_singular[3 * i] * rtb_w_d[b_ixstart];
      rtb_y_n[b_ixstart + 3 * i] += U_singular[3 * i + 1] * rtb_w_d[b_ixstart +
        3];
      rtb_y_n[b_ixstart + 3 * i] += U_singular[3 * i + 2] * rtb_w_d[b_ixstart +
        6];
    }
  }

  /* Sum: '<S17>/Sum' incorporates:
   *  Product: '<S17>/Matrix Multiply'
   */
  rtb_TmpSignalConversionAtSFun_7 = ctrl_DP_basic_B.x_ref -
    rtb_TmpSignalConversionAtSFu_pa[0];
  rtb_TmpSignalConversionAtSFun_6 = ctrl_DP_basic_B.y_ref -
    rtb_TmpSignalConversionAtSFu_pa[1];
  rtb_TmpSignalConversionAtSFun_0 = ctrl_DP_basic_B.psi_ref -
    rtb_TmpSignalConversionAtSFu_pa[2];

  /* Product: '<S17>/Matrix Multiply' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    ctrl_DP_basic_B.MatrixMultiply[b_ixstart] = 0.0;
    ctrl_DP_basic_B.MatrixMultiply[b_ixstart] += rtb_y_n[b_ixstart] *
      rtb_TmpSignalConversionAtSFun_7;
    ctrl_DP_basic_B.MatrixMultiply[b_ixstart] += rtb_y_n[b_ixstart + 3] *
      rtb_TmpSignalConversionAtSFun_6;
    ctrl_DP_basic_B.MatrixMultiply[b_ixstart] += rtb_y_n[b_ixstart + 6] *
      rtb_TmpSignalConversionAtSFun_0;
  }

  /* MATLAB Function: '<S25>/diag1' incorporates:
   *  SignalConversion: '<S31>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Guidance/Reference model/w_d*w_d': '<S19>:1' */
  /* '<S19>:1:4' */
  /* MATLAB Function 'Input/Guidance gains/diag1': '<S31>:1' */
  /* '<S31>:1:4' */
  memset(&rtb_y_n[0], 0, 9U * sizeof(real_T));
  rtb_y_n[0] = ctrl_DP_basic_B.zeta_x;
  rtb_y_n[4] = ctrl_DP_basic_B.zeta_y;
  rtb_y_n[8] = ctrl_DP_basic_B.zeta_psi;

  /* MATLAB Function: '<S17>/w_d*w_d' incorporates:
   *  Product: '<S17>/Matrix Multiply2'
   */
  /* MATLAB Function 'Guidance/Reference model/w_d*w_d1': '<S20>:1' */
  /* '<S20>:1:4' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      U_singular[b_ixstart + 3 * i] = 0.0;
      U_singular[b_ixstart + 3 * i] += rtb_w_d[3 * i] * rtb_w_d[b_ixstart];
      U_singular[b_ixstart + 3 * i] += rtb_w_d[3 * i + 1] * rtb_w_d[b_ixstart +
        3];
      U_singular[b_ixstart + 3 * i] += rtb_w_d[3 * i + 2] * rtb_w_d[b_ixstart +
        6];
    }
  }

  /* End of MATLAB Function: '<S17>/w_d*w_d' */

  /* MATLAB Function: '<S17>/w_d*w_d1' incorporates:
   *  Product: '<S17>/Matrix Multiply5'
   */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    for (i = 0; i < 3; i++) {
      tmp_1[b_ixstart + 3 * i] = 0.0;
      tmp_1[b_ixstart + 3 * i] += 2.0 * rtb_y_n[b_ixstart] * rtb_w_d[3 * i];
      tmp_1[b_ixstart + 3 * i] += rtb_y_n[b_ixstart + 3] * 2.0 * rtb_w_d[3 * i +
        1];
      tmp_1[b_ixstart + 3 * i] += rtb_y_n[b_ixstart + 6] * 2.0 * rtb_w_d[3 * i +
        2];
    }
  }

  /* End of MATLAB Function: '<S17>/w_d*w_d1' */

  /* Sum: '<S17>/Sum2' incorporates:
   *  Product: '<S17>/Matrix Multiply2'
   *  Sum: '<S17>/Sum5'
   */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    tmp_0[b_ixstart] = rtb_Integrator2[b_ixstart] - ((U_singular[b_ixstart + 3] *
      ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[1] + U_singular[b_ixstart]
      * ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[0]) +
      U_singular[b_ixstart + 6] *
      ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[2]);
  }

  /* End of Sum: '<S17>/Sum2' */

  /* Product: '<S17>/Matrix Multiply5' incorporates:
   *  Sum: '<S17>/Sum5'
   */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    rtb_TmpSignalConversionAtSFu_pa[b_ixstart] = tmp_1[b_ixstart + 6] *
      ctrl_DP_basic_B.Integrator3[2] + (tmp_1[b_ixstart + 3] *
      ctrl_DP_basic_B.Integrator3[1] + tmp_1[b_ixstart] *
      ctrl_DP_basic_B.Integrator3[0]);
  }

  /* Sum: '<S17>/Sum5' */
  ctrl_DP_basic_B.Sum5[0] = tmp_0[0] - rtb_TmpSignalConversionAtSFu_pa[0];
  ctrl_DP_basic_B.Sum5[1] = tmp_0[1] - rtb_TmpSignalConversionAtSFu_pa[1];
  ctrl_DP_basic_B.Sum5[2] = tmp_0[2] - rtb_TmpSignalConversionAtSFu_pa[2];
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* MATLAB Function: '<S26>/MATLAB Function' incorporates:
     *  Constant: '<S26>/Constant'
     *  Constant: '<S26>/Constant1'
     *  Constant: '<S26>/Constant2'
     */
    ctrl_DP_basic_MATLABFunction(ctrl_DP_basic_P.Constant_Value_k,
      ctrl_DP_basic_P.Constant1_Value, ctrl_DP_basic_P.Constant2_Value,
      &ctrl_DP_basic_B.sf_MATLABFunction_l);

    /* MATLAB Function: '<S26>/MATLAB Function1' incorporates:
     *  Constant: '<S26>/Constant3'
     *  Constant: '<S26>/Constant4'
     *  Constant: '<S26>/Constant5'
     */
    ctrl_DP_basic_MATLABFunction1(ctrl_DP_basic_P.Constant3_Value,
      ctrl_DP_basic_P.Constant4_Value, ctrl_DP_basic_P.Constant5_Value,
      &ctrl_DP_basic_B.sf_MATLABFunction1_c);
  }

  /* Product: '<S6>/Matrix Multiply1' */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    ctrl_DP_basic_B.MatrixMultiply1[b_ixstart] = 0.0;
    ctrl_DP_basic_B.MatrixMultiply1[b_ixstart] +=
      ctrl_DP_basic_B.sf_MATLABFunction1_c.K_i[b_ixstart] * rtb_Sum_nu[0];
    ctrl_DP_basic_B.MatrixMultiply1[b_ixstart] +=
      ctrl_DP_basic_B.sf_MATLABFunction1_c.K_i[b_ixstart + 3] * rtb_Sum_nu[1];
    ctrl_DP_basic_B.MatrixMultiply1[b_ixstart] +=
      ctrl_DP_basic_B.sf_MATLABFunction1_c.K_i[b_ixstart + 6] * rtb_Sum_nu[2];
  }

  /* End of Product: '<S6>/Matrix Multiply1' */

  /* Product: '<S6>/Matrix Multiply' incorporates:
   *  Sum: '<S6>/Sum1'
   */
  for (b_ixstart = 0; b_ixstart < 3; b_ixstart++) {
    tmp_0[b_ixstart] = ctrl_DP_basic_B.sf_MATLABFunction_l.K_p[b_ixstart + 6] *
      rtb_Sum_nu[2] + (ctrl_DP_basic_B.sf_MATLABFunction_l.K_p[b_ixstart + 3] *
                       rtb_Sum_nu[1] +
                       ctrl_DP_basic_B.sf_MATLABFunction_l.K_p[b_ixstart] *
                       rtb_Sum_nu[0]);
  }

  /* End of Product: '<S6>/Matrix Multiply' */

  /* Sum: '<S6>/Sum1' incorporates:
   *  Fcn: '<S37>/Fcn'
   *  Fcn: '<S37>/Fcn1'
   *  Fcn: '<S37>/Fcn2'
   */
  ctrl_DP_basic_B.Sum1[0] = (cos(rtb_psi_dot) * ctrl_DP_basic_B.Integrator1_g[0]
    - sin(rtb_psi_dot) * ctrl_DP_basic_B.Integrator1_g[1]) + tmp_0[0];
  ctrl_DP_basic_B.Sum1[1] = (sin(rtb_psi_dot) * ctrl_DP_basic_B.Integrator1_g[0]
    + cos(rtb_psi_dot) * ctrl_DP_basic_B.Integrator1_g[1]) + tmp_0[1];
  ctrl_DP_basic_B.Sum1[2] = tmp_0[2] + ctrl_DP_basic_B.Integrator1_g[2];
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* Delay: '<S54>/Delay' */
    rtb_Delay = ctrl_DP_basic_DW.Delay_DSTATE;

    /* Delay: '<S63>/Delay' */
    ctrl_DP_basic_B.Delay = ctrl_DP_basic_DW.Delay_DSTATE_j;
  }

  /* MATLAB Function: '<S63>/MATLAB Function' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/D'
   *  Constant: '<S8>/Kt'
   *  Constant: '<S8>/Ktr'
   *  Constant: '<S8>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/MATLAB Function': '<S67>:1' */
  /* '<S67>:1:5' */
  if (rtb_sys[6] < 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = -1.0;
  } else if (rtb_sys[6] > 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 1.0;
  } else if (rtb_sys[6] == 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_7 = rtb_sys[6];
  }

  rtb_Saturation1 = sqrt(fabs(rtb_sys[6]) / (ctrl_DP_basic_P.Rho * rt_powd_snf
    (ctrl_DP_basic_P.D, 4.0) * ctrl_DP_basic_P.Kt)) *
    rtb_TmpSignalConversionAtSFun_7;

  /* '<S67>:1:7' */
  rtb_Row1 = tanh(ctrl_DP_basic_P.eps_c * rtb_Saturation1 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S67>:1:8' */
  /* '<S67>:1:10' */
  if (ctrl_DP_basic_B.Delay < 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = -1.0;
  } else if (ctrl_DP_basic_B.Delay > 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 1.0;
  } else if (ctrl_DP_basic_B.Delay == 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_7 = ctrl_DP_basic_B.Delay;
  }

  rtb_T_r_f = ((1.0 - rtb_Row1) * ctrl_DP_basic_P.Ktr + ctrl_DP_basic_P.Kt *
               rtb_Row1) * rtb_TmpSignalConversionAtSFun_7 * ctrl_DP_basic_P.Rho
    * rt_powd_snf(ctrl_DP_basic_P.D, 4.0) * (ctrl_DP_basic_B.Delay *
    ctrl_DP_basic_B.Delay);
  ctrl_DP_basic_B.n_d_l = rtb_Saturation1;

  /* End of MATLAB Function: '<S63>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteTransferFcn: '<S63>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S63>/Constant1'
     *  Constant: '<S63>/Constant2'
     */
    ctrl_DP_basic_DW.DiscreteTransferFcn_tmp = (ctrl_DP_basic_B.n_d_l -
      ctrl_DP_basic_P.Constant2_Value_c[1] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states[0]) -
      ctrl_DP_basic_P.Constant2_Value_c[2] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states[1];
    ctrl_DP_basic_B.DiscreteTransferFcn = (ctrl_DP_basic_P.Constant1_Value_e[0] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp +
      ctrl_DP_basic_P.Constant1_Value_e[1] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states[0]) +
      ctrl_DP_basic_P.Constant1_Value_e[2] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states[1];

    /* SampleTimeMath: '<S66>/TSamp'
     *
     * About '<S66>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_DP_basic_B.TSamp = ctrl_DP_basic_B.DiscreteTransferFcn *
      ctrl_DP_basic_P.TSamp_WtEt;

    /* Sum: '<S66>/Diff' incorporates:
     *  UnitDelay: '<S66>/UD'
     */
    rtb_DiscreteTransferFcn = ctrl_DP_basic_B.TSamp - ctrl_DP_basic_DW.UD_DSTATE;

    /* RateLimiter: '<S63>/Acceleration Limit' */
    rtb_Saturation1 = rtb_DiscreteTransferFcn - ctrl_DP_basic_DW.PrevY;
    if (rtb_Saturation1 > ctrl_DP_basic_P.AccelerationLimit_RisingLim) {
      rtb_DiscreteTransferFcn = ctrl_DP_basic_DW.PrevY +
        ctrl_DP_basic_P.AccelerationLimit_RisingLim;
    } else {
      if (rtb_Saturation1 < ctrl_DP_basic_P.AccelerationLimit_FallingLim) {
        rtb_DiscreteTransferFcn = ctrl_DP_basic_DW.PrevY +
          ctrl_DP_basic_P.AccelerationLimit_FallingLim;
      }
    }

    ctrl_DP_basic_DW.PrevY = rtb_DiscreteTransferFcn;

    /* End of RateLimiter: '<S63>/Acceleration Limit' */

    /* Gain: '<S63>/Inertia compensation' */
    ctrl_DP_basic_B.Inertiacompensation = ctrl_DP_basic_P.I_s * 2.0 *
      3.1415926535897931 * rtb_DiscreteTransferFcn;

    /* Sum: '<S63>/Sum1' incorporates:
     *  Gain: '<S63>/Qf_0'
     *  Gain: '<S63>/Qff_0(nr)'
     *  Gain: '<S63>/Qff_1(nr)'
     *  Trigonometry: '<S63>/Trigonometric Function'
     */
    ctrl_DP_basic_B.Sum1_o = tanh(ctrl_DP_basic_P.epsilon /
      ctrl_DP_basic_P.n_max * ctrl_DP_basic_B.DiscreteTransferFcn) *
      ctrl_DP_basic_P.Q_f0 + ctrl_DP_basic_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_DP_basic_B.DiscreteTransferFcn;

    /* Memory: '<S63>/Memory' */
    ctrl_DP_basic_B.Memory = ctrl_DP_basic_DW.Memory_PreviousInput;

    /* Sum: '<S65>/Sum' */
    rtb_DiscreteTransferFcn = ctrl_DP_basic_B.DiscreteTransferFcn -
      ctrl_DP_basic_B.DiscreteTimeIntegrator;

    /* DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
    if (((ctrl_DP_basic_B.reset_i > 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevR_em <= 0)) ||
        ((ctrl_DP_basic_B.reset_i <= 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevR_em == 1))) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu =
        ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_c;
    }

    if (ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu >=
        ctrl_DP_basic_P.Q_max) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu = ctrl_DP_basic_P.Q_max;
    } else {
      if (ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu <=
          -ctrl_DP_basic_P.Q_max) {
        ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu =
          -ctrl_DP_basic_P.Q_max;
      }
    }

    rtb_Sum_m = ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu;

    /* Sum: '<S65>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S65>/Discrete-Time Integrator'
     *  Gain: '<S65>/Kp'
     */
    ctrl_DP_basic_B.Sum1_m = ctrl_DP_basic_P.Kp * rtb_DiscreteTransferFcn +
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu;
  }

  /* MATLAB Function: '<S65>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   *  Constant: '<S8>/D'
   *  Constant: '<S8>/Kq'
   *  Constant: '<S8>/Kqr'
   *  Constant: '<S8>/Kt'
   *  Constant: '<S8>/Ktr'
   *  Constant: '<S8>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_DP_basic_P.k_cc, ctrl_DP_basic_P.p_cc,
    ctrl_DP_basic_P.r_cc, ctrl_DP_basic_B.DiscreteTimeIntegrator,
    ctrl_DP_basic_P.Kt, ctrl_DP_basic_P.Kq, ctrl_DP_basic_P.D, rtb_T_r_f,
    ctrl_DP_basic_P.eps, ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.eps_c,
    ctrl_DP_basic_P.Ktr, ctrl_DP_basic_P.Kqr,
    &ctrl_DP_basic_B.sf_CorecontrollerTorquePowerand);

  /* MultiPortSwitch: '<S63>/Controller chosen' incorporates:
   *  Constant: '<S63>/NaN'
   */
  switch ((int32_T)ctrl_DP_basic_B.Memory) {
   case 1:
    rtb_Saturation1 = ctrl_DP_basic_B.Sum1_m;
    break;

   case 2:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePowerand.Qcq;
    break;

   case 3:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePowerand.Qcp;
    break;

   case 4:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePowerand.Qcc;
    break;

   default:
    rtb_Saturation1 = ctrl_DP_basic_P.NaN_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S63>/Controller chosen' */

  /* Sum: '<S63>/Sum' */
  rtb_Saturation1 += ctrl_DP_basic_B.Inertiacompensation +
    ctrl_DP_basic_B.Sum1_o;

  /* MATLAB Function: '<S63>/Torque limit' incorporates:
   *  Constant: '<S63>/P_max'
   *  Constant: '<S63>/Q_max'
   */
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Torque limit': '<S69>:1' */
  /* '<S69>:1:4' */
  Q_cm[0] = fabs(rtb_Saturation1);
  Q_cm[1] = ctrl_DP_basic_P.Q_max;
  Q_cm[2] = ctrl_DP_basic_P.P_max / fabs(6.2831853071795862 *
    ctrl_DP_basic_B.DiscreteTimeIntegrator);

  /* '<S69>:1:6' */
  ixstart = 1;
  rtb_Row1 = Q_cm[0];
  if (rtIsNaN(Q_cm[0])) {
    b_ixstart = 2;
    exitg11 = false;
    while ((!exitg11) && (b_ixstart < 4)) {
      ixstart = b_ixstart;
      if (!rtIsNaN(Q_cm[b_ixstart - 1])) {
        rtb_Row1 = Q_cm[b_ixstart - 1];
        exitg11 = true;
      } else {
        b_ixstart++;
      }
    }
  }

  if (ixstart < 3) {
    while (ixstart + 1 < 4) {
      if (Q_cm[ixstart] < rtb_Row1) {
        rtb_Row1 = Q_cm[ixstart];
      }

      ixstart++;
    }
  }

  if (rtb_Saturation1 < 0.0) {
    rtb_Saturation1 = -1.0;
  } else if (rtb_Saturation1 > 0.0) {
    rtb_Saturation1 = 1.0;
  } else {
    if (rtb_Saturation1 == 0.0) {
      rtb_Saturation1 = 0.0;
    }
  }

  ctrl_DP_basic_B.Q_c = rtb_Saturation1 * rtb_Row1;

  /* End of MATLAB Function: '<S63>/Torque limit' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteTransferFcn: '<S54>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S54>/Constant'
     *  Constant: '<S54>/Constant1'
     */
    ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_m = ctrl_DP_basic_B.Q_c -
      ctrl_DP_basic_P.Constant_Value_i3[1] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_b;
    rtb_Sum_m = ctrl_DP_basic_P.Constant1_Value_h[0] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_m +
      ctrl_DP_basic_P.Constant1_Value_h[1] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_b;

    /* Gain: '<S62>/Finding rotation speed' incorporates:
     *  Gain: '<S62>/K_omega'
     *  Sum: '<S62>/Sum'
     */
    ctrl_DP_basic_B.Findingrotationspeed = ((rtb_Sum_m - rtb_Delay) -
      ctrl_DP_basic_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_DP_basic_B.DiscreteTimeIntegrator) * (1.0 / (6.2831853071795862 *
      ctrl_DP_basic_P.I_s));

    /* Gain: '<S65>/Ki' */
    ctrl_DP_basic_B.Ki = ctrl_DP_basic_P.Kp / 0.05 * rtb_DiscreteTransferFcn;

    /* MATLAB Function: '<S63>/Supervisor' incorporates:
     *  Constant: '<S63>/Switch controller'
     */
    ctrl_DP_basic_Supervisor(ctrl_DP_basic_B.Memory,
      ctrl_DP_basic_P.Thruster_control, ctrl_DP_basic_B.DiscreteTimeIntegrator,
      &ctrl_DP_basic_B.sf_Supervisor);

    /* Delay: '<S55>/Delay' */
    rtb_Delay_a = ctrl_DP_basic_DW.Delay_DSTATE_l;

    /* Delay: '<S73>/Delay' */
    ctrl_DP_basic_B.Delay_o = ctrl_DP_basic_DW.Delay_DSTATE_e;
  }

  /* MATLAB Function: '<S73>/MATLAB Function' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/D'
   *  Constant: '<S8>/Kt'
   *  Constant: '<S8>/Ktr'
   *  Constant: '<S8>/Rho'
   */
  ctrl_DP_basic_MATLABFunction_d(rtb_sys[7], ctrl_DP_basic_P.Kt,
    ctrl_DP_basic_P.Ktr, ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.D,
    ctrl_DP_basic_P.eps_c, ctrl_DP_basic_B.Delay_o,
    &ctrl_DP_basic_B.sf_MATLABFunction_d);
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteTransferFcn: '<S73>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S73>/Constant1'
     *  Constant: '<S73>/Constant2'
     */
    ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_k =
      (ctrl_DP_basic_B.sf_MATLABFunction_d.n_d -
       ctrl_DP_basic_P.Constant2_Value_i[1] *
       ctrl_DP_basic_DW.DiscreteTransferFcn_states_j[0]) -
      ctrl_DP_basic_P.Constant2_Value_i[2] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_j[1];
    ctrl_DP_basic_B.DiscreteTransferFcn_p = (ctrl_DP_basic_P.Constant1_Value_f[0]
      * ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_k +
      ctrl_DP_basic_P.Constant1_Value_f[1] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_j[0]) +
      ctrl_DP_basic_P.Constant1_Value_f[2] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_j[1];

    /* SampleTimeMath: '<S76>/TSamp'
     *
     * About '<S76>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_DP_basic_B.TSamp_f = ctrl_DP_basic_B.DiscreteTransferFcn_p *
      ctrl_DP_basic_P.TSamp_WtEt_o;

    /* Sum: '<S76>/Diff' incorporates:
     *  UnitDelay: '<S76>/UD'
     */
    rtb_Sum_m = ctrl_DP_basic_B.TSamp_f - ctrl_DP_basic_DW.UD_DSTATE_j;

    /* RateLimiter: '<S73>/Acceleration Limit' */
    rtb_Saturation1 = rtb_Sum_m - ctrl_DP_basic_DW.PrevY_e;
    if (rtb_Saturation1 > ctrl_DP_basic_P.AccelerationLimit_RisingLim_n) {
      rtb_Sum_m = ctrl_DP_basic_DW.PrevY_e +
        ctrl_DP_basic_P.AccelerationLimit_RisingLim_n;
    } else {
      if (rtb_Saturation1 < ctrl_DP_basic_P.AccelerationLimit_FallingLim_j) {
        rtb_Sum_m = ctrl_DP_basic_DW.PrevY_e +
          ctrl_DP_basic_P.AccelerationLimit_FallingLim_j;
      }
    }

    ctrl_DP_basic_DW.PrevY_e = rtb_Sum_m;

    /* End of RateLimiter: '<S73>/Acceleration Limit' */

    /* Gain: '<S73>/Inertia compensation' */
    ctrl_DP_basic_B.Inertiacompensation_d = ctrl_DP_basic_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_m;

    /* Sum: '<S73>/Sum1' incorporates:
     *  Gain: '<S73>/Qf_0'
     *  Gain: '<S73>/Qff_0(nr)'
     *  Gain: '<S73>/Qff_1(nr)'
     *  Trigonometry: '<S73>/Trigonometric Function'
     */
    ctrl_DP_basic_B.Sum1_mw = tanh(ctrl_DP_basic_P.epsilon /
      ctrl_DP_basic_P.n_max * ctrl_DP_basic_B.DiscreteTransferFcn_p) *
      ctrl_DP_basic_P.Q_f0 + ctrl_DP_basic_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_DP_basic_B.DiscreteTransferFcn_p;

    /* Memory: '<S73>/Memory' */
    ctrl_DP_basic_B.Memory_c = ctrl_DP_basic_DW.Memory_PreviousInput_e;

    /* Sum: '<S75>/Sum' */
    rtb_Sum_m = ctrl_DP_basic_B.DiscreteTransferFcn_p -
      ctrl_DP_basic_B.DiscreteTimeIntegrator_m;

    /* DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
    if (((ctrl_DP_basic_B.reset_ig > 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_o <= 0)) ||
        ((ctrl_DP_basic_B.reset_ig <= 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_o == 1))) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_n =
        ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_a;
    }

    /* Sum: '<S75>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S75>/Discrete-Time Integrator'
     *  Gain: '<S75>/Kp'
     */
    ctrl_DP_basic_B.Sum1_g = ctrl_DP_basic_P.Kp * rtb_Sum_m +
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_n;
  }

  /* MATLAB Function: '<S75>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   *  Constant: '<S8>/D'
   *  Constant: '<S8>/Kq'
   *  Constant: '<S8>/Kqr'
   *  Constant: '<S8>/Kt'
   *  Constant: '<S8>/Ktr'
   *  Constant: '<S8>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_DP_basic_P.k_cc, ctrl_DP_basic_P.p_cc,
    ctrl_DP_basic_P.r_cc, ctrl_DP_basic_B.DiscreteTimeIntegrator_m,
    ctrl_DP_basic_P.Kt, ctrl_DP_basic_P.Kq, ctrl_DP_basic_P.D,
    ctrl_DP_basic_B.sf_MATLABFunction_d.T_r, ctrl_DP_basic_P.eps,
    ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.eps_c, ctrl_DP_basic_P.Ktr,
    ctrl_DP_basic_P.Kqr, &ctrl_DP_basic_B.sf_CorecontrollerTorquePowera_a);

  /* MultiPortSwitch: '<S73>/Controller chosen' incorporates:
   *  Constant: '<S73>/NaN'
   */
  switch ((int32_T)ctrl_DP_basic_B.Memory_c) {
   case 1:
    rtb_Saturation1 = ctrl_DP_basic_B.Sum1_g;
    break;

   case 2:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePowera_a.Qcq;
    break;

   case 3:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePowera_a.Qcp;
    break;

   case 4:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePowera_a.Qcc;
    break;

   default:
    rtb_Saturation1 = ctrl_DP_basic_P.NaN_Value_o;
    break;
  }

  /* End of MultiPortSwitch: '<S73>/Controller chosen' */

  /* Sum: '<S73>/Sum' */
  rtb_Sum_n = (ctrl_DP_basic_B.Inertiacompensation_d + ctrl_DP_basic_B.Sum1_mw)
    + rtb_Saturation1;

  /* MATLAB Function: '<S73>/Torque limit' incorporates:
   *  Constant: '<S73>/P_max'
   *  Constant: '<S73>/Q_max'
   */
  ctrl_DP_basic_Torquelimit(ctrl_DP_basic_P.Q_max, ctrl_DP_basic_P.P_max,
    rtb_Sum_n, ctrl_DP_basic_B.DiscreteTimeIntegrator_m,
    &ctrl_DP_basic_B.sf_Torquelimit_a);
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteTransferFcn: '<S55>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S55>/Constant'
     */
    ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_ku =
      ctrl_DP_basic_B.sf_Torquelimit_a.Q_c - ctrl_DP_basic_P.Constant_Value_b[1]
      * ctrl_DP_basic_DW.DiscreteTransferFcn_states_e;

    /* Gain: '<S72>/Finding rotation speed' incorporates:
     *  Constant: '<S55>/Constant1'
     *  DiscreteTransferFcn: '<S55>/Discrete Transfer Fcn'
     *  Gain: '<S72>/K_omega'
     *  Sum: '<S72>/Sum'
     */
    ctrl_DP_basic_B.Findingrotationspeed_i =
      (((ctrl_DP_basic_P.Constant1_Value_l[0] *
         ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_ku +
         ctrl_DP_basic_P.Constant1_Value_l[1] *
         ctrl_DP_basic_DW.DiscreteTransferFcn_states_e) - rtb_Delay_a) -
       ctrl_DP_basic_P.K_omega * 2.0 * 3.1415926535897931 *
       ctrl_DP_basic_B.DiscreteTimeIntegrator_m) * (1.0 / (6.2831853071795862 *
      ctrl_DP_basic_P.I_s));

    /* Gain: '<S75>/Ki' */
    ctrl_DP_basic_B.Ki_j = ctrl_DP_basic_P.Kp / 0.05 * rtb_Sum_m;

    /* MATLAB Function: '<S73>/Supervisor' incorporates:
     *  Constant: '<S73>/Switch controller'
     */
    ctrl_DP_basic_Supervisor(ctrl_DP_basic_B.Memory_c,
      ctrl_DP_basic_P.Thruster_control, ctrl_DP_basic_B.DiscreteTimeIntegrator_m,
      &ctrl_DP_basic_B.sf_Supervisor_l);

    /* Delay: '<S56>/Delay' */
    rtb_Delay_k = ctrl_DP_basic_DW.Delay_DSTATE_p;

    /* Delay: '<S83>/Delay' */
    ctrl_DP_basic_B.Delay_oq = ctrl_DP_basic_DW.Delay_DSTATE_f;
  }

  /* MATLAB Function: '<S83>/MATLAB Function' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/D'
   *  Constant: '<S8>/Kt'
   *  Constant: '<S8>/Ktr'
   *  Constant: '<S8>/Rho'
   */
  ctrl_DP_basic_MATLABFunction_d(rtb_sys[8], ctrl_DP_basic_P.Kt,
    ctrl_DP_basic_P.Ktr, ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.D,
    ctrl_DP_basic_P.eps_c, ctrl_DP_basic_B.Delay_oq,
    &ctrl_DP_basic_B.sf_MATLABFunction_n);
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteTransferFcn: '<S83>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S83>/Constant1'
     *  Constant: '<S83>/Constant2'
     */
    ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_k4 =
      (ctrl_DP_basic_B.sf_MATLABFunction_n.n_d -
       ctrl_DP_basic_P.Constant2_Value_b[1] *
       ctrl_DP_basic_DW.DiscreteTransferFcn_states_c[0]) -
      ctrl_DP_basic_P.Constant2_Value_b[2] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_c[1];
    ctrl_DP_basic_B.DiscreteTransferFcn_b = (ctrl_DP_basic_P.Constant1_Value_k[0]
      * ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_k4 +
      ctrl_DP_basic_P.Constant1_Value_k[1] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_c[0]) +
      ctrl_DP_basic_P.Constant1_Value_k[2] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_c[1];

    /* SampleTimeMath: '<S86>/TSamp'
     *
     * About '<S86>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_DP_basic_B.TSamp_d = ctrl_DP_basic_B.DiscreteTransferFcn_b *
      ctrl_DP_basic_P.TSamp_WtEt_m;

    /* Sum: '<S86>/Diff' incorporates:
     *  UnitDelay: '<S86>/UD'
     */
    rtb_Sum_m = ctrl_DP_basic_B.TSamp_d - ctrl_DP_basic_DW.UD_DSTATE_g;

    /* RateLimiter: '<S83>/Acceleration limiter' */
    rtb_Saturation1 = rtb_Sum_m - ctrl_DP_basic_DW.PrevY_f;
    if (rtb_Saturation1 > ctrl_DP_basic_P.Accelerationlimiter_RisingLim) {
      rtb_Sum_m = ctrl_DP_basic_DW.PrevY_f +
        ctrl_DP_basic_P.Accelerationlimiter_RisingLim;
    } else {
      if (rtb_Saturation1 < ctrl_DP_basic_P.Accelerationlimiter_FallingLim) {
        rtb_Sum_m = ctrl_DP_basic_DW.PrevY_f +
          ctrl_DP_basic_P.Accelerationlimiter_FallingLim;
      }
    }

    ctrl_DP_basic_DW.PrevY_f = rtb_Sum_m;

    /* End of RateLimiter: '<S83>/Acceleration limiter' */

    /* Gain: '<S83>/Inertia compensation' */
    ctrl_DP_basic_B.Inertiacompensation_f = ctrl_DP_basic_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_m;

    /* Sum: '<S83>/Sum1' incorporates:
     *  Gain: '<S83>/Qf_0'
     *  Gain: '<S83>/Qff_0(nr)'
     *  Gain: '<S83>/Qff_1(nr)'
     *  Trigonometry: '<S83>/Trigonometric Function'
     */
    ctrl_DP_basic_B.Sum1_a = tanh(ctrl_DP_basic_P.epsilon /
      ctrl_DP_basic_P.n_max * ctrl_DP_basic_B.DiscreteTransferFcn_b) *
      ctrl_DP_basic_P.Q_f0 + ctrl_DP_basic_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_DP_basic_B.DiscreteTransferFcn_b;

    /* Memory: '<S83>/Memory' */
    ctrl_DP_basic_B.Memory_m = ctrl_DP_basic_DW.Memory_PreviousInput_i;

    /* Sum: '<S85>/Sum' */
    rtb_Sum_m = ctrl_DP_basic_B.DiscreteTransferFcn_b -
      ctrl_DP_basic_B.DiscreteTimeIntegrator_p;

    /* DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */
    if (((ctrl_DP_basic_B.reset_j > 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_k <= 0)) ||
        ((ctrl_DP_basic_B.reset_j <= 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_k == 1))) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_l =
        ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_o;
    }

    /* Sum: '<S85>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S85>/Discrete-Time Integrator'
     *  Gain: '<S85>/Kp'
     */
    ctrl_DP_basic_B.Sum1_n = ctrl_DP_basic_P.Kp * rtb_Sum_m +
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_l;
  }

  /* MATLAB Function: '<S85>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   *  Constant: '<S8>/D'
   *  Constant: '<S8>/Kq'
   *  Constant: '<S8>/Kqr'
   *  Constant: '<S8>/Kt'
   *  Constant: '<S8>/Ktr'
   *  Constant: '<S8>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_DP_basic_P.k_cc, ctrl_DP_basic_P.p_cc,
    ctrl_DP_basic_P.r_cc, ctrl_DP_basic_B.DiscreteTimeIntegrator_p,
    ctrl_DP_basic_P.Kt, ctrl_DP_basic_P.Kq, ctrl_DP_basic_P.D,
    ctrl_DP_basic_B.sf_MATLABFunction_n.T_r, ctrl_DP_basic_P.eps,
    ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.eps_c, ctrl_DP_basic_P.Ktr,
    ctrl_DP_basic_P.Kqr, &ctrl_DP_basic_B.sf_CorecontrollerTorquePowera_c);

  /* MultiPortSwitch: '<S83>/Controller chosen' incorporates:
   *  Constant: '<S83>/NaN'
   */
  switch ((int32_T)ctrl_DP_basic_B.Memory_m) {
   case 1:
    rtb_Saturation1 = ctrl_DP_basic_B.Sum1_n;
    break;

   case 2:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePowera_c.Qcq;
    break;

   case 3:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePowera_c.Qcp;
    break;

   case 4:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePowera_c.Qcc;
    break;

   default:
    rtb_Saturation1 = ctrl_DP_basic_P.NaN_Value_g;
    break;
  }

  /* End of MultiPortSwitch: '<S83>/Controller chosen' */

  /* Sum: '<S83>/Sum' */
  rtb_Sum_nhi = (ctrl_DP_basic_B.Inertiacompensation_f + ctrl_DP_basic_B.Sum1_a)
    + rtb_Saturation1;

  /* MATLAB Function: '<S83>/Torque limit' incorporates:
   *  Constant: '<S83>/P_max'
   *  Constant: '<S83>/Q_max'
   */
  ctrl_DP_basic_Torquelimit(ctrl_DP_basic_P.Q_max, ctrl_DP_basic_P.P_max,
    rtb_Sum_nhi, ctrl_DP_basic_B.DiscreteTimeIntegrator_p,
    &ctrl_DP_basic_B.sf_Torquelimit_e);
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteTransferFcn: '<S56>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S56>/Constant'
     */
    ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_i =
      ctrl_DP_basic_B.sf_Torquelimit_e.Q_c - ctrl_DP_basic_P.Constant_Value_n[1]
      * ctrl_DP_basic_DW.DiscreteTransferFcn_states_i;

    /* Gain: '<S82>/Finding rotation speed' incorporates:
     *  Constant: '<S56>/Constant1'
     *  DiscreteTransferFcn: '<S56>/Discrete Transfer Fcn'
     *  Gain: '<S82>/K_omega'
     *  Sum: '<S82>/Sum'
     */
    ctrl_DP_basic_B.Findingrotationspeed_n =
      (((ctrl_DP_basic_P.Constant1_Value_g[0] *
         ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_i +
         ctrl_DP_basic_P.Constant1_Value_g[1] *
         ctrl_DP_basic_DW.DiscreteTransferFcn_states_i) - rtb_Delay_k) -
       ctrl_DP_basic_P.K_omega * 2.0 * 3.1415926535897931 *
       ctrl_DP_basic_B.DiscreteTimeIntegrator_p) * (1.0 / (6.2831853071795862 *
      ctrl_DP_basic_P.I_s));

    /* Gain: '<S85>/Ki' */
    ctrl_DP_basic_B.Ki_o = ctrl_DP_basic_P.Kp / 0.05 * rtb_Sum_m;

    /* MATLAB Function: '<S83>/Supervisor' incorporates:
     *  Constant: '<S83>/Switch controller'
     */
    ctrl_DP_basic_Supervisor(ctrl_DP_basic_B.Memory_m,
      ctrl_DP_basic_P.Thruster_control, ctrl_DP_basic_B.DiscreteTimeIntegrator_p,
      &ctrl_DP_basic_B.sf_Supervisor_c);

    /* Delay: '<S57>/Delay' */
    rtb_Delay_j = ctrl_DP_basic_DW.Delay_DSTATE_d;

    /* Delay: '<S93>/Delay' */
    ctrl_DP_basic_B.Delay_a = ctrl_DP_basic_DW.Delay_DSTATE_ev;
  }

  /* MATLAB Function: '<S93>/MATLAB Function' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/D'
   *  Constant: '<S8>/Kt'
   *  Constant: '<S8>/Ktr'
   *  Constant: '<S8>/Rho'
   */
  ctrl_DP_basic_MATLABFunction_d(rtb_sys[9], ctrl_DP_basic_P.Kt,
    ctrl_DP_basic_P.Ktr, ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.D,
    ctrl_DP_basic_P.eps_c, ctrl_DP_basic_B.Delay_a,
    &ctrl_DP_basic_B.sf_MATLABFunction_j);
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteTransferFcn: '<S93>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S93>/Constant1'
     *  Constant: '<S93>/Constant2'
     */
    ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_o =
      (ctrl_DP_basic_B.sf_MATLABFunction_j.n_d -
       ctrl_DP_basic_P.Constant2_Value_m[1] *
       ctrl_DP_basic_DW.DiscreteTransferFcn_states_m[0]) -
      ctrl_DP_basic_P.Constant2_Value_m[2] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_m[1];
    ctrl_DP_basic_B.DiscreteTransferFcn_h = (ctrl_DP_basic_P.Constant1_Value_m[0]
      * ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_o +
      ctrl_DP_basic_P.Constant1_Value_m[1] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_m[0]) +
      ctrl_DP_basic_P.Constant1_Value_m[2] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_m[1];

    /* SampleTimeMath: '<S96>/TSamp'
     *
     * About '<S96>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_DP_basic_B.TSamp_p = ctrl_DP_basic_B.DiscreteTransferFcn_h *
      ctrl_DP_basic_P.TSamp_WtEt_mu;

    /* Sum: '<S96>/Diff' incorporates:
     *  UnitDelay: '<S96>/UD'
     */
    rtb_Sum_m = ctrl_DP_basic_B.TSamp_p - ctrl_DP_basic_DW.UD_DSTATE_o;

    /* RateLimiter: '<S93>/Acceleration limiter' */
    rtb_Saturation1 = rtb_Sum_m - ctrl_DP_basic_DW.PrevY_l;
    if (rtb_Saturation1 > ctrl_DP_basic_P.Accelerationlimiter_RisingLim_c) {
      rtb_Sum_m = ctrl_DP_basic_DW.PrevY_l +
        ctrl_DP_basic_P.Accelerationlimiter_RisingLim_c;
    } else {
      if (rtb_Saturation1 < ctrl_DP_basic_P.Accelerationlimiter_FallingLi_o) {
        rtb_Sum_m = ctrl_DP_basic_DW.PrevY_l +
          ctrl_DP_basic_P.Accelerationlimiter_FallingLi_o;
      }
    }

    ctrl_DP_basic_DW.PrevY_l = rtb_Sum_m;

    /* End of RateLimiter: '<S93>/Acceleration limiter' */

    /* Gain: '<S93>/Inertia compensation' */
    ctrl_DP_basic_B.Inertiacompensation_a = ctrl_DP_basic_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_m;

    /* Sum: '<S93>/Sum1' incorporates:
     *  Gain: '<S93>/Qf_0'
     *  Gain: '<S93>/Qff_0(nr)'
     *  Gain: '<S93>/Qff_1(nr)'
     *  Trigonometry: '<S93>/Trigonometric Function'
     */
    ctrl_DP_basic_B.Sum1_f = tanh(ctrl_DP_basic_P.epsilon /
      ctrl_DP_basic_P.n_max * ctrl_DP_basic_B.DiscreteTransferFcn_h) *
      ctrl_DP_basic_P.Q_f0 + ctrl_DP_basic_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_DP_basic_B.DiscreteTransferFcn_h;

    /* Memory: '<S93>/Memory' */
    ctrl_DP_basic_B.Memory_j = ctrl_DP_basic_DW.Memory_PreviousInput_l;

    /* Sum: '<S95>/Sum' */
    rtb_Sum_m = ctrl_DP_basic_B.DiscreteTransferFcn_h -
      ctrl_DP_basic_B.DiscreteTimeIntegrator_j;

    /* DiscreteIntegrator: '<S95>/Discrete-Time Integrator' */
    if (((ctrl_DP_basic_B.reset_o > 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_g <= 0)) ||
        ((ctrl_DP_basic_B.reset_o <= 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_g == 1))) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hx =
        ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_k;
    }

    /* Sum: '<S95>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S95>/Discrete-Time Integrator'
     *  Gain: '<S95>/Kp'
     */
    ctrl_DP_basic_B.Sum1_b = ctrl_DP_basic_P.Kp * rtb_Sum_m +
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hx;
  }

  /* MATLAB Function: '<S95>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   *  Constant: '<S8>/D'
   *  Constant: '<S8>/Kq'
   *  Constant: '<S8>/Kqr'
   *  Constant: '<S8>/Kt'
   *  Constant: '<S8>/Ktr'
   *  Constant: '<S8>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_DP_basic_P.k_cc, ctrl_DP_basic_P.p_cc,
    ctrl_DP_basic_P.r_cc, ctrl_DP_basic_B.DiscreteTimeIntegrator_j,
    ctrl_DP_basic_P.Kt, ctrl_DP_basic_P.Kq, ctrl_DP_basic_P.D,
    ctrl_DP_basic_B.sf_MATLABFunction_j.T_r, ctrl_DP_basic_P.eps,
    ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.eps_c, ctrl_DP_basic_P.Ktr,
    ctrl_DP_basic_P.Kqr, &ctrl_DP_basic_B.sf_CorecontrollerTorquePowera_o);

  /* MultiPortSwitch: '<S93>/Controller chosen' incorporates:
   *  Constant: '<S93>/NaN'
   */
  switch ((int32_T)ctrl_DP_basic_B.Memory_j) {
   case 1:
    rtb_Saturation1 = ctrl_DP_basic_B.Sum1_b;
    break;

   case 2:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePowera_o.Qcq;
    break;

   case 3:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePowera_o.Qcp;
    break;

   case 4:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePowera_o.Qcc;
    break;

   default:
    rtb_Saturation1 = ctrl_DP_basic_P.NaN_Value_om;
    break;
  }

  /* End of MultiPortSwitch: '<S93>/Controller chosen' */

  /* Sum: '<S93>/Sum' */
  rtb_Sum_hm = (ctrl_DP_basic_B.Inertiacompensation_a + ctrl_DP_basic_B.Sum1_f)
    + rtb_Saturation1;

  /* MATLAB Function: '<S93>/Torque limit' incorporates:
   *  Constant: '<S93>/P_max'
   *  Constant: '<S93>/Q_max'
   */
  ctrl_DP_basic_Torquelimit(ctrl_DP_basic_P.Q_max, ctrl_DP_basic_P.P_max,
    rtb_Sum_hm, ctrl_DP_basic_B.DiscreteTimeIntegrator_j,
    &ctrl_DP_basic_B.sf_Torquelimit_g);
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteTransferFcn: '<S57>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S57>/Constant'
     */
    ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_b =
      ctrl_DP_basic_B.sf_Torquelimit_g.Q_c - ctrl_DP_basic_P.Constant_Value_a[1]
      * ctrl_DP_basic_DW.DiscreteTransferFcn_states_ms;

    /* Gain: '<S92>/Finding rotation speed' incorporates:
     *  Constant: '<S57>/Constant1'
     *  DiscreteTransferFcn: '<S57>/Discrete Transfer Fcn'
     *  Gain: '<S92>/K_omega'
     *  Sum: '<S92>/Sum'
     */
    ctrl_DP_basic_B.Findingrotationspeed_nl =
      (((ctrl_DP_basic_P.Constant1_Value_fh[0] *
         ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_b +
         ctrl_DP_basic_P.Constant1_Value_fh[1] *
         ctrl_DP_basic_DW.DiscreteTransferFcn_states_ms) - rtb_Delay_j) -
       ctrl_DP_basic_P.K_omega * 2.0 * 3.1415926535897931 *
       ctrl_DP_basic_B.DiscreteTimeIntegrator_j) * (1.0 / (6.2831853071795862 *
      ctrl_DP_basic_P.I_s));

    /* Gain: '<S95>/Ki' */
    ctrl_DP_basic_B.Ki_c = ctrl_DP_basic_P.Kp / 0.05 * rtb_Sum_m;

    /* MATLAB Function: '<S93>/Supervisor' incorporates:
     *  Constant: '<S93>/Switch controller'
     */
    ctrl_DP_basic_Supervisor(ctrl_DP_basic_B.Memory_j,
      ctrl_DP_basic_P.Thruster_control, ctrl_DP_basic_B.DiscreteTimeIntegrator_j,
      &ctrl_DP_basic_B.sf_Supervisor_cp);

    /* Delay: '<S58>/Delay' */
    rtb_Delay_an = ctrl_DP_basic_DW.Delay_DSTATE_du;

    /* Delay: '<S103>/Delay' */
    ctrl_DP_basic_B.Delay_i = ctrl_DP_basic_DW.Delay_DSTATE_n;
  }

  /* MATLAB Function: '<S103>/MATLAB Function' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/D'
   *  Constant: '<S8>/Kt'
   *  Constant: '<S8>/Ktr'
   *  Constant: '<S8>/Rho'
   */
  ctrl_DP_basic_MATLABFunction_d(rtb_sys[10], ctrl_DP_basic_P.Kt,
    ctrl_DP_basic_P.Ktr, ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.D,
    ctrl_DP_basic_P.eps_c, ctrl_DP_basic_B.Delay_i,
    &ctrl_DP_basic_B.sf_MATLABFunction_c);
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteTransferFcn: '<S103>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S103>/Constant1'
     *  Constant: '<S103>/Constant2'
     */
    ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_a =
      (ctrl_DP_basic_B.sf_MATLABFunction_c.n_d -
       ctrl_DP_basic_P.Constant2_Value_g[1] *
       ctrl_DP_basic_DW.DiscreteTransferFcn_states_f[0]) -
      ctrl_DP_basic_P.Constant2_Value_g[2] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_f[1];
    ctrl_DP_basic_B.DiscreteTransferFcn_j = (ctrl_DP_basic_P.Constant1_Value_n[0]
      * ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_a +
      ctrl_DP_basic_P.Constant1_Value_n[1] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_f[0]) +
      ctrl_DP_basic_P.Constant1_Value_n[2] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_f[1];

    /* SampleTimeMath: '<S106>/TSamp'
     *
     * About '<S106>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_DP_basic_B.TSamp_j = ctrl_DP_basic_B.DiscreteTransferFcn_j *
      ctrl_DP_basic_P.TSamp_WtEt_b;

    /* Sum: '<S106>/Diff' incorporates:
     *  UnitDelay: '<S106>/UD'
     */
    rtb_Sum_m = ctrl_DP_basic_B.TSamp_j - ctrl_DP_basic_DW.UD_DSTATE_n;

    /* RateLimiter: '<S103>/Acceleration limiter' */
    rtb_Saturation1 = rtb_Sum_m - ctrl_DP_basic_DW.PrevY_c;
    if (rtb_Saturation1 > ctrl_DP_basic_P.Accelerationlimiter_RisingLim_h) {
      rtb_Sum_m = ctrl_DP_basic_DW.PrevY_c +
        ctrl_DP_basic_P.Accelerationlimiter_RisingLim_h;
    } else {
      if (rtb_Saturation1 < ctrl_DP_basic_P.Accelerationlimiter_FallingLi_l) {
        rtb_Sum_m = ctrl_DP_basic_DW.PrevY_c +
          ctrl_DP_basic_P.Accelerationlimiter_FallingLi_l;
      }
    }

    ctrl_DP_basic_DW.PrevY_c = rtb_Sum_m;

    /* End of RateLimiter: '<S103>/Acceleration limiter' */

    /* Gain: '<S103>/Inertia compensation' */
    ctrl_DP_basic_B.Inertiacompensation_i = ctrl_DP_basic_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_m;

    /* Sum: '<S103>/Sum1' incorporates:
     *  Gain: '<S103>/Qf_0'
     *  Gain: '<S103>/Qff_0(nr)'
     *  Gain: '<S103>/Qff_1(nr)'
     *  Trigonometry: '<S103>/Trigonometric Function'
     */
    ctrl_DP_basic_B.Sum1_h = tanh(ctrl_DP_basic_P.epsilon /
      ctrl_DP_basic_P.n_max * ctrl_DP_basic_B.DiscreteTransferFcn_j) *
      ctrl_DP_basic_P.Q_f0 + ctrl_DP_basic_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_DP_basic_B.DiscreteTransferFcn_j;

    /* Memory: '<S103>/Memory' */
    ctrl_DP_basic_B.Memory_i = ctrl_DP_basic_DW.Memory_PreviousInput_m;

    /* Sum: '<S105>/Sum' */
    rtb_Sum_m = ctrl_DP_basic_B.DiscreteTransferFcn_j -
      ctrl_DP_basic_B.DiscreteTimeIntegrator_c;

    /* DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
    if (((ctrl_DP_basic_B.reset_n5 > 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_f <= 0)) ||
        ((ctrl_DP_basic_B.reset_n5 <= 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_f == 1))) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_p =
        ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_mk;
    }

    /* Sum: '<S105>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S105>/Discrete-Time Integrator'
     *  Gain: '<S105>/Kp'
     */
    ctrl_DP_basic_B.Sum1_hb = ctrl_DP_basic_P.Kp * rtb_Sum_m +
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_p;
  }

  /* MATLAB Function: '<S105>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   *  Constant: '<S8>/D'
   *  Constant: '<S8>/Kq'
   *  Constant: '<S8>/Kqr'
   *  Constant: '<S8>/Kt'
   *  Constant: '<S8>/Ktr'
   *  Constant: '<S8>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_DP_basic_P.k_cc, ctrl_DP_basic_P.p_cc,
    ctrl_DP_basic_P.r_cc, ctrl_DP_basic_B.DiscreteTimeIntegrator_c,
    ctrl_DP_basic_P.Kt, ctrl_DP_basic_P.Kq, ctrl_DP_basic_P.D,
    ctrl_DP_basic_B.sf_MATLABFunction_c.T_r, ctrl_DP_basic_P.eps,
    ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.eps_c, ctrl_DP_basic_P.Ktr,
    ctrl_DP_basic_P.Kqr, &ctrl_DP_basic_B.sf_CorecontrollerTorquePower_c1);

  /* MultiPortSwitch: '<S103>/Controller chosen' incorporates:
   *  Constant: '<S103>/NaN'
   */
  switch ((int32_T)ctrl_DP_basic_B.Memory_i) {
   case 1:
    rtb_Saturation1 = ctrl_DP_basic_B.Sum1_hb;
    break;

   case 2:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePower_c1.Qcq;
    break;

   case 3:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePower_c1.Qcp;
    break;

   case 4:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePower_c1.Qcc;
    break;

   default:
    rtb_Saturation1 = ctrl_DP_basic_P.NaN_Value_od;
    break;
  }

  /* End of MultiPortSwitch: '<S103>/Controller chosen' */

  /* Sum: '<S103>/Sum' */
  rtb_Sum_c = (ctrl_DP_basic_B.Inertiacompensation_i + ctrl_DP_basic_B.Sum1_h) +
    rtb_Saturation1;

  /* MATLAB Function: '<S103>/Torque limit' incorporates:
   *  Constant: '<S103>/P_max'
   *  Constant: '<S103>/Q_max'
   */
  ctrl_DP_basic_Torquelimit(ctrl_DP_basic_P.Q_max, ctrl_DP_basic_P.P_max,
    rtb_Sum_c, 0.0, &ctrl_DP_basic_B.sf_Torquelimit_c);
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteTransferFcn: '<S58>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S58>/Constant'
     */
    ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_p =
      ctrl_DP_basic_B.sf_Torquelimit_c.Q_c - ctrl_DP_basic_P.Constant_Value_d[1]
      * ctrl_DP_basic_DW.DiscreteTransferFcn_states_ix;

    /* Gain: '<S102>/Finding rotation speed' incorporates:
     *  Constant: '<S58>/Constant1'
     *  DiscreteTransferFcn: '<S58>/Discrete Transfer Fcn'
     *  Gain: '<S102>/K_omega'
     *  Sum: '<S102>/Sum'
     */
    ctrl_DP_basic_B.Findingrotationspeed_b =
      (((ctrl_DP_basic_P.Constant1_Value_p[0] *
         ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_p +
         ctrl_DP_basic_P.Constant1_Value_p[1] *
         ctrl_DP_basic_DW.DiscreteTransferFcn_states_ix) - rtb_Delay_an) -
       ctrl_DP_basic_P.K_omega * 2.0 * 3.1415926535897931 *
       ctrl_DP_basic_B.DiscreteTimeIntegrator_c) * (1.0 / (6.2831853071795862 *
      ctrl_DP_basic_P.I_s));

    /* Gain: '<S105>/Ki' */
    ctrl_DP_basic_B.Ki_b = ctrl_DP_basic_P.Kp / 0.05 * rtb_Sum_m;

    /* MATLAB Function: '<S103>/Supervisor' incorporates:
     *  Constant: '<S103>/Switch controller'
     */
    ctrl_DP_basic_Supervisor(ctrl_DP_basic_B.Memory_i,
      ctrl_DP_basic_P.Thruster_control, ctrl_DP_basic_B.DiscreteTimeIntegrator_c,
      &ctrl_DP_basic_B.sf_Supervisor_n);

    /* Delay: '<S59>/Delay' */
    rtb_Delay_ac = ctrl_DP_basic_DW.Delay_DSTATE_k;

    /* Delay: '<S113>/Delay' */
    ctrl_DP_basic_B.Delay_od = ctrl_DP_basic_DW.Delay_DSTATE_o;
  }

  /* MATLAB Function: '<S113>/MATLAB Function' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/D'
   *  Constant: '<S8>/Kt'
   *  Constant: '<S8>/Ktr'
   *  Constant: '<S8>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 6/Thruster control/MATLAB Function': '<S117>:1' */
  /* '<S117>:1:5' */
  if (rtb_sys[11] < 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = -1.0;
  } else if (rtb_sys[11] > 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 1.0;
  } else if (rtb_sys[11] == 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_7 = rtb_sys[11];
  }

  rtb_Saturation1 = sqrt(fabs(rtb_sys[11]) / (ctrl_DP_basic_P.Rho * rt_powd_snf
    (ctrl_DP_basic_P.D, 4.0) * ctrl_DP_basic_P.Kt)) *
    rtb_TmpSignalConversionAtSFun_7;

  /* '<S117>:1:7' */
  rtb_Row1 = tanh(ctrl_DP_basic_P.eps_c * rtb_Saturation1 / 27.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S117>:1:8' */
  /* '<S117>:1:10' */
  if (ctrl_DP_basic_B.Delay_od < 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = -1.0;
  } else if (ctrl_DP_basic_B.Delay_od > 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 1.0;
  } else if (ctrl_DP_basic_B.Delay_od == 0.0) {
    rtb_TmpSignalConversionAtSFun_7 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_7 = ctrl_DP_basic_B.Delay_od;
  }

  rtb_T_r = ((1.0 - rtb_Row1) * ctrl_DP_basic_P.Ktr + ctrl_DP_basic_P.Kt *
             rtb_Row1) * rtb_TmpSignalConversionAtSFun_7 * ctrl_DP_basic_P.Rho *
    rt_powd_snf(ctrl_DP_basic_P.D, 4.0) * (ctrl_DP_basic_B.Delay_od *
    ctrl_DP_basic_B.Delay_od);
  ctrl_DP_basic_B.n_d = rtb_Saturation1;

  /* End of MATLAB Function: '<S113>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteTransferFcn: '<S113>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S113>/Constant1'
     *  Constant: '<S113>/Constant2'
     */
    ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_aj = (ctrl_DP_basic_B.n_d -
      ctrl_DP_basic_P.Constant2_Value_d[1] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_k[0]) -
      ctrl_DP_basic_P.Constant2_Value_d[2] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_k[1];
    ctrl_DP_basic_B.DiscreteTransferFcn_jz =
      (ctrl_DP_basic_P.Constant1_Value_li[0] *
       ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_aj +
       ctrl_DP_basic_P.Constant1_Value_li[1] *
       ctrl_DP_basic_DW.DiscreteTransferFcn_states_k[0]) +
      ctrl_DP_basic_P.Constant1_Value_li[2] *
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_k[1];

    /* SampleTimeMath: '<S116>/TSamp'
     *
     * About '<S116>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_DP_basic_B.TSamp_o = ctrl_DP_basic_B.DiscreteTransferFcn_jz *
      ctrl_DP_basic_P.TSamp_WtEt_j;

    /* Sum: '<S116>/Diff' incorporates:
     *  UnitDelay: '<S116>/UD'
     */
    rtb_Sum_m = ctrl_DP_basic_B.TSamp_o - ctrl_DP_basic_DW.UD_DSTATE_d;

    /* RateLimiter: '<S113>/Acceleration limiter' */
    rtb_Saturation1 = rtb_Sum_m - ctrl_DP_basic_DW.PrevY_ca;
    if (rtb_Saturation1 > ctrl_DP_basic_P.Accelerationlimiter_RisingLim_k) {
      rtb_Sum_m = ctrl_DP_basic_DW.PrevY_ca +
        ctrl_DP_basic_P.Accelerationlimiter_RisingLim_k;
    } else {
      if (rtb_Saturation1 < ctrl_DP_basic_P.Accelerationlimiter_FallingLi_b) {
        rtb_Sum_m = ctrl_DP_basic_DW.PrevY_ca +
          ctrl_DP_basic_P.Accelerationlimiter_FallingLi_b;
      }
    }

    ctrl_DP_basic_DW.PrevY_ca = rtb_Sum_m;

    /* End of RateLimiter: '<S113>/Acceleration limiter' */

    /* Gain: '<S113>/Inertia compensation' */
    ctrl_DP_basic_B.Inertiacompensation_p = ctrl_DP_basic_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_m;

    /* Sum: '<S113>/Sum1' incorporates:
     *  Gain: '<S113>/Qf_0'
     *  Gain: '<S113>/Qff_0(nr)'
     *  Gain: '<S113>/Qff_1(nr)'
     *  Trigonometry: '<S113>/Trigonometric Function'
     */
    ctrl_DP_basic_B.Sum1_c = tanh(ctrl_DP_basic_P.epsilon /
      ctrl_DP_basic_P.n_max * ctrl_DP_basic_B.DiscreteTransferFcn_jz) *
      ctrl_DP_basic_P.Q_f0 + ctrl_DP_basic_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_DP_basic_B.DiscreteTransferFcn_jz;

    /* Memory: '<S113>/Memory' */
    ctrl_DP_basic_B.Memory_b = ctrl_DP_basic_DW.Memory_PreviousInput_p;

    /* Sum: '<S115>/Sum' */
    rtb_Sum_m = ctrl_DP_basic_B.DiscreteTransferFcn_jz -
      ctrl_DP_basic_B.DiscreteTimeIntegrator_d;

    /* DiscreteIntegrator: '<S115>/Discrete-Time Integrator' */
    if (((ctrl_DP_basic_B.reset_b > 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_c <= 0)) ||
        ((ctrl_DP_basic_B.reset_b <= 0.0) &&
         (ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_c == 1))) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_gt =
        ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_b;
    }

    /* Sum: '<S115>/Sum1' incorporates:
     *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator'
     *  Gain: '<S115>/Kp'
     */
    ctrl_DP_basic_B.Sum1_d = ctrl_DP_basic_P.Kp * rtb_Sum_m +
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_gt;
  }

  /* MATLAB Function: '<S115>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   *  Constant: '<S8>/D'
   *  Constant: '<S8>/Kq'
   *  Constant: '<S8>/Kqr'
   *  Constant: '<S8>/Kt'
   *  Constant: '<S8>/Ktr'
   *  Constant: '<S8>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_DP_basic_P.k_cc, ctrl_DP_basic_P.p_cc,
    ctrl_DP_basic_P.r_cc, ctrl_DP_basic_B.DiscreteTimeIntegrator_d,
    ctrl_DP_basic_P.Kt, ctrl_DP_basic_P.Kq, ctrl_DP_basic_P.D, rtb_T_r,
    ctrl_DP_basic_P.eps, ctrl_DP_basic_P.Rho, ctrl_DP_basic_P.eps_c,
    ctrl_DP_basic_P.Ktr, ctrl_DP_basic_P.Kqr,
    &ctrl_DP_basic_B.sf_CorecontrollerTorquePower_ol);

  /* MultiPortSwitch: '<S113>/Controller chosen' incorporates:
   *  Constant: '<S113>/NaN'
   */
  switch ((int32_T)ctrl_DP_basic_B.Memory_b) {
   case 1:
    rtb_Saturation1 = ctrl_DP_basic_B.Sum1_d;
    break;

   case 2:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePower_ol.Qcq;
    break;

   case 3:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePower_ol.Qcp;
    break;

   case 4:
    rtb_Saturation1 = ctrl_DP_basic_B.sf_CorecontrollerTorquePower_ol.Qcc;
    break;

   default:
    rtb_Saturation1 = ctrl_DP_basic_P.NaN_Value_c;
    break;
  }

  /* End of MultiPortSwitch: '<S113>/Controller chosen' */

  /* Sum: '<S113>/Sum' */
  rtb_Sum_h2 = (ctrl_DP_basic_B.Inertiacompensation_p + ctrl_DP_basic_B.Sum1_c)
    + rtb_Saturation1;

  /* MATLAB Function: '<S113>/Torque limit' incorporates:
   *  Constant: '<S113>/P_max'
   *  Constant: '<S113>/Q_max'
   */
  ctrl_DP_basic_Torquelimit(ctrl_DP_basic_P.Q_max, ctrl_DP_basic_P.P_max,
    rtb_Sum_h2, ctrl_DP_basic_B.DiscreteTimeIntegrator_d,
    &ctrl_DP_basic_B.sf_Torquelimit_f);
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* DiscreteTransferFcn: '<S59>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S59>/Constant'
     */
    ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_d =
      ctrl_DP_basic_B.sf_Torquelimit_f.Q_c - ctrl_DP_basic_P.Constant_Value_m[1]
      * ctrl_DP_basic_DW.DiscreteTransferFcn_states_l;

    /* Gain: '<S112>/Finding rotation speed' incorporates:
     *  Constant: '<S59>/Constant1'
     *  DiscreteTransferFcn: '<S59>/Discrete Transfer Fcn'
     *  Gain: '<S112>/K_omega'
     *  Sum: '<S112>/Sum'
     */
    ctrl_DP_basic_B.Findingrotationspeed_l =
      (((ctrl_DP_basic_P.Constant1_Value_ly[0] *
         ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_d +
         ctrl_DP_basic_P.Constant1_Value_ly[1] *
         ctrl_DP_basic_DW.DiscreteTransferFcn_states_l) - rtb_Delay_ac) -
       ctrl_DP_basic_P.K_omega * 2.0 * 3.1415926535897931 *
       ctrl_DP_basic_B.DiscreteTimeIntegrator_d) * (1.0 / (6.2831853071795862 *
      ctrl_DP_basic_P.I_s));

    /* Gain: '<S115>/Ki' */
    ctrl_DP_basic_B.Ki_cv = ctrl_DP_basic_P.Kp / 0.05 * rtb_Sum_m;

    /* MATLAB Function: '<S113>/Supervisor' incorporates:
     *  Constant: '<S113>/Switch controller'
     */
    ctrl_DP_basic_Supervisor(ctrl_DP_basic_B.Memory_b,
      ctrl_DP_basic_P.Thruster_control, ctrl_DP_basic_B.DiscreteTimeIntegrator_d,
      &ctrl_DP_basic_B.sf_Supervisor_a);
  }

  /* Fcn: '<S23>/Row3' */
  ctrl_DP_basic_B.Row3 = ctrl_DP_basic_B.Integrator3[2];

  /* Fcn: '<S23>/Row1' */
  ctrl_DP_basic_B.Row1 = cos(ctrl_DP_basic_B.Sum) * ctrl_DP_basic_B.Integrator3
    [0] + sin(ctrl_DP_basic_B.Sum) * ctrl_DP_basic_B.Integrator3[1];

  /* Fcn: '<S23>/Row2' */
  ctrl_DP_basic_B.Row2 = -sin(ctrl_DP_basic_B.Sum) *
    ctrl_DP_basic_B.Integrator3[0] + cos(ctrl_DP_basic_B.Sum) *
    ctrl_DP_basic_B.Integrator3[1];
}

/* Model update function */
void ctrl_DP_basic_update(void)
{
  /* local block i/o variables */
  real_T rtb_ImpSel_InsertedFor_reset_at;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE +=
      ctrl_DP_basic_P.DiscreteTimeIntegrator_gainval *
      ctrl_DP_basic_B.Findingrotationspeed;
    if (ctrl_DP_basic_B.reset > 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRese = 1;
    } else if (ctrl_DP_basic_B.reset < 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRese = -1;
    } else if (ctrl_DP_basic_B.reset == 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRese = 0;
    } else {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRese = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_h +=
      ctrl_DP_basic_P.DiscreteTimeIntegrator_gainva_l *
      ctrl_DP_basic_B.Findingrotationspeed_i;
    if (ctrl_DP_basic_B.reset_n > 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_p = 1;
    } else if (ctrl_DP_basic_B.reset_n < 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_p = -1;
    } else if (ctrl_DP_basic_B.reset_n == 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_p = 0;
    } else {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_p = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_d +=
      ctrl_DP_basic_P.DiscreteTimeIntegrator_gainva_i *
      ctrl_DP_basic_B.Findingrotationspeed_n;
    if (ctrl_DP_basic_B.reset_d > 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_n = 1;
    } else if (ctrl_DP_basic_B.reset_d < 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_n = -1;
    } else if (ctrl_DP_basic_B.reset_d == 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_n = 0;
    } else {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_n = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_g +=
      ctrl_DP_basic_P.DiscreteTimeIntegrator_gainva_b *
      ctrl_DP_basic_B.Findingrotationspeed_nl;
    if (ctrl_DP_basic_B.reset_l > 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_b = 1;
    } else if (ctrl_DP_basic_B.reset_l < 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_b = -1;
    } else if (ctrl_DP_basic_B.reset_l == 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_b = 0;
    } else {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_b = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_f +=
      ctrl_DP_basic_P.DiscreteTimeIntegrator_gainva_e *
      ctrl_DP_basic_B.Findingrotationspeed_b;
    if (ctrl_DP_basic_B.reset_e > 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_e = 1;
    } else if (ctrl_DP_basic_B.reset_e < 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_e = -1;
    } else if (ctrl_DP_basic_B.reset_e == 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_e = 0;
    } else {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_e = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */

    /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hl +=
      ctrl_DP_basic_P.DiscreteTimeIntegrator_gainva_a *
      ctrl_DP_basic_B.Findingrotationspeed_l;
    if (ctrl_DP_basic_B.reset_a > 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_m = 1;
    } else if (ctrl_DP_basic_B.reset_a < 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_m = -1;
    } else if (ctrl_DP_basic_B.reset_a == 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_m = 0;
    } else {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_m = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
  }

  /* Update for Integrator: '<S17>/Integrator1' */
  ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading = 0;

  /* Update for Iterator SubSystem: '<S9>/For Each Subsystem' */
  for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
    /* Update for ForEachSliceSelector: '<S46>/ImpSel_InsertedFor_reset_at_outport_0' */
    rtb_ImpSel_InsertedFor_reset_at = ctrl_DP_basic_B.reset_a3[ForEach_itr];
    if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
      /* Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */
      ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI =
        0U;
      ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE +=
        ctrl_DP_basic_P.CoreSubsys.DiscreteTimeIntegrator_gainval *
        ctrl_DP_basic_B.CoreSubsys[ForEach_itr].MaxRotationRate;
      if (rtb_ImpSel_InsertedFor_reset_at > 0.0) {
        ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese
          = 1;
      } else if (rtb_ImpSel_InsertedFor_reset_at < 0.0) {
        ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese
          = -1;
      } else if (rtb_ImpSel_InsertedFor_reset_at == 0.0) {
        ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese
          = 0;
      } else {
        ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese
          = 2;
      }

      /* End of Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */

      /* Update for Delay: '<S46>/Delay' */
      ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_DP_basic_B.CoreSubsys[ForEach_itr].angle;
    }
  }

  /* End of Update for SubSystem: '<S9>/For Each Subsystem' */
  /* Update for Integrator: '<S6>/Integrator' */
  ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* Update for Delay: '<S54>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE = ctrl_DP_basic_B.sf_ActualForceandTorque.Qa;

    /* Update for Delay: '<S63>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_j = ctrl_DP_basic_B.DiscreteTransferFcn;

    /* Update for DiscreteTransferFcn: '<S63>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states[1] =
      ctrl_DP_basic_DW.DiscreteTransferFcn_states[0];
    ctrl_DP_basic_DW.DiscreteTransferFcn_states[0] =
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp;

    /* Update for UnitDelay: '<S66>/UD' */
    ctrl_DP_basic_DW.UD_DSTATE = ctrl_DP_basic_B.TSamp;

    /* Update for Memory: '<S63>/Memory' */
    ctrl_DP_basic_DW.Memory_PreviousInput = ctrl_DP_basic_B.sf_Supervisor.u;

    /* Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu +=
      ctrl_DP_basic_P.DiscreteTimeIntegrator_gainva_f * ctrl_DP_basic_B.Ki;
    if (ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu >=
        ctrl_DP_basic_P.Q_max) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu = ctrl_DP_basic_P.Q_max;
    } else {
      if (ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu <=
          -ctrl_DP_basic_P.Q_max) {
        ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu =
          -ctrl_DP_basic_P.Q_max;
      }
    }

    if (ctrl_DP_basic_B.reset_i > 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevR_em = 1;
    } else if (ctrl_DP_basic_B.reset_i < 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevR_em = -1;
    } else if (ctrl_DP_basic_B.reset_i == 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevR_em = 0;
    } else {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevR_em = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */

    /* Update for DiscreteTransferFcn: '<S54>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_b =
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_m;

    /* Update for Delay: '<S55>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_l =
      ctrl_DP_basic_B.sf_ActualForceandTorque_o.Qa;

    /* Update for Delay: '<S73>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_e = ctrl_DP_basic_B.DiscreteTransferFcn_p;

    /* Update for DiscreteTransferFcn: '<S73>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_j[1] =
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_j[0];
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_j[0] =
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_k;

    /* Update for UnitDelay: '<S76>/UD' */
    ctrl_DP_basic_DW.UD_DSTATE_j = ctrl_DP_basic_B.TSamp_f;

    /* Update for Memory: '<S73>/Memory' */
    ctrl_DP_basic_DW.Memory_PreviousInput_e = ctrl_DP_basic_B.sf_Supervisor_l.u;

    /* Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_n +=
      ctrl_DP_basic_P.DiscreteTimeIntegrator_gainv_fz * ctrl_DP_basic_B.Ki_j;
    if (ctrl_DP_basic_B.reset_ig > 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_o = 1;
    } else if (ctrl_DP_basic_B.reset_ig < 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_o = -1;
    } else if (ctrl_DP_basic_B.reset_ig == 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_o = 0;
    } else {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_o = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */

    /* Update for DiscreteTransferFcn: '<S55>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_e =
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_ku;

    /* Update for Delay: '<S56>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_p =
      ctrl_DP_basic_B.sf_ActualForceandTorque_c.Qa;

    /* Update for Delay: '<S83>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_f = ctrl_DP_basic_B.DiscreteTransferFcn_b;

    /* Update for DiscreteTransferFcn: '<S83>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_c[1] =
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_c[0];
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_c[0] =
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_k4;

    /* Update for UnitDelay: '<S86>/UD' */
    ctrl_DP_basic_DW.UD_DSTATE_g = ctrl_DP_basic_B.TSamp_d;

    /* Update for Memory: '<S83>/Memory' */
    ctrl_DP_basic_DW.Memory_PreviousInput_i = ctrl_DP_basic_B.sf_Supervisor_c.u;

    /* Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_l +=
      ctrl_DP_basic_P.DiscreteTimeIntegrator_gainva_m * ctrl_DP_basic_B.Ki_o;
    if (ctrl_DP_basic_B.reset_j > 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_k = 1;
    } else if (ctrl_DP_basic_B.reset_j < 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_k = -1;
    } else if (ctrl_DP_basic_B.reset_j == 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_k = 0;
    } else {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_k = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */

    /* Update for DiscreteTransferFcn: '<S56>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_i =
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_i;

    /* Update for Delay: '<S57>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_d =
      ctrl_DP_basic_B.sf_ActualForceandTorque_f.Qa;

    /* Update for Delay: '<S93>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_ev = ctrl_DP_basic_B.DiscreteTransferFcn_h;

    /* Update for DiscreteTransferFcn: '<S93>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_m[1] =
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_m[0];
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_m[0] =
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_o;

    /* Update for UnitDelay: '<S96>/UD' */
    ctrl_DP_basic_DW.UD_DSTATE_o = ctrl_DP_basic_B.TSamp_p;

    /* Update for Memory: '<S93>/Memory' */
    ctrl_DP_basic_DW.Memory_PreviousInput_l = ctrl_DP_basic_B.sf_Supervisor_cp.u;

    /* Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hx +=
      ctrl_DP_basic_P.DiscreteTimeIntegrator_gainv_ay * ctrl_DP_basic_B.Ki_c;
    if (ctrl_DP_basic_B.reset_o > 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_g = 1;
    } else if (ctrl_DP_basic_B.reset_o < 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_g = -1;
    } else if (ctrl_DP_basic_B.reset_o == 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_g = 0;
    } else {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_g = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' */

    /* Update for DiscreteTransferFcn: '<S57>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_ms =
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_b;

    /* Update for Delay: '<S58>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_du =
      ctrl_DP_basic_B.sf_ActualForceandTorque_fi.Qa;

    /* Update for Delay: '<S103>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_n = ctrl_DP_basic_B.DiscreteTransferFcn_j;

    /* Update for DiscreteTransferFcn: '<S103>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_f[1] =
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_f[0];
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_f[0] =
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_a;

    /* Update for UnitDelay: '<S106>/UD' */
    ctrl_DP_basic_DW.UD_DSTATE_n = ctrl_DP_basic_B.TSamp_j;

    /* Update for Memory: '<S103>/Memory' */
    ctrl_DP_basic_DW.Memory_PreviousInput_m = ctrl_DP_basic_B.sf_Supervisor_n.u;

    /* Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_p +=
      ctrl_DP_basic_P.DiscreteTimeIntegrator_gainva_j * ctrl_DP_basic_B.Ki_b;
    if (ctrl_DP_basic_B.reset_n5 > 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_f = 1;
    } else if (ctrl_DP_basic_B.reset_n5 < 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_f = -1;
    } else if (ctrl_DP_basic_B.reset_n5 == 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_f = 0;
    } else {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_f = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */

    /* Update for DiscreteTransferFcn: '<S58>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_ix =
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_p;

    /* Update for Delay: '<S59>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_k =
      ctrl_DP_basic_B.sf_ActualForceandTorque_a.Qa;

    /* Update for Delay: '<S113>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_o = ctrl_DP_basic_B.DiscreteTransferFcn_jz;

    /* Update for DiscreteTransferFcn: '<S113>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_k[1] =
      ctrl_DP_basic_DW.DiscreteTransferFcn_states_k[0];
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_k[0] =
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_aj;

    /* Update for UnitDelay: '<S116>/UD' */
    ctrl_DP_basic_DW.UD_DSTATE_d = ctrl_DP_basic_B.TSamp_o;

    /* Update for Memory: '<S113>/Memory' */
    ctrl_DP_basic_DW.Memory_PreviousInput_p = ctrl_DP_basic_B.sf_Supervisor_a.u;

    /* Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_gt +=
      ctrl_DP_basic_P.DiscreteTimeIntegrator_gainv_ll * ctrl_DP_basic_B.Ki_cv;
    if (ctrl_DP_basic_B.reset_b > 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_c = 1;
    } else if (ctrl_DP_basic_B.reset_b < 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_c = -1;
    } else if (ctrl_DP_basic_B.reset_b == 0.0) {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_c = 0;
    } else {
      ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_c = 2;
    }

    /* End of Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator' */

    /* Update for DiscreteTransferFcn: '<S59>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_l =
      ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_d;
  }

  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_DP_basic_M->solverInfo);
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
  if (!(++ctrl_DP_basic_M->Timing.clockTick0)) {
    ++ctrl_DP_basic_M->Timing.clockTickH0;
  }

  ctrl_DP_basic_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ctrl_DP_basic_M->solverInfo);

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
    if (!(++ctrl_DP_basic_M->Timing.clockTick1)) {
      ++ctrl_DP_basic_M->Timing.clockTickH1;
    }

    ctrl_DP_basic_M->Timing.t[1] = ctrl_DP_basic_M->Timing.clockTick1 *
      ctrl_DP_basic_M->Timing.stepSize1 + ctrl_DP_basic_M->Timing.clockTickH1 *
      ctrl_DP_basic_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_DP_basic_derivatives(void)
{
  /* Derivatives for Integrator: '<S17>/Integrator1' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE[0] = ctrl_DP_basic_B.Integrator3[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE[1] = ctrl_DP_basic_B.Integrator3[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE[2] = ctrl_DP_basic_B.Integrator3[2];
  }

  /* Derivatives for Integrator: '<S12>/Integrator' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE[0] = ctrl_DP_basic_B.TmpSignalConversionAtMatrixMu_m[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE[1] = ctrl_DP_basic_B.TmpSignalConversionAtMatrixMu_m[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE[2] = ctrl_DP_basic_B.TmpSignalConversionAtMatrixMu_m[2];
  }

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE_g[0] = ctrl_DP_basic_B.M1[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE_g[1] = ctrl_DP_basic_B.M1[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE_g[2] = ctrl_DP_basic_B.M1[2];
  }

  /* Derivatives for Integrator: '<S17>/Integrator3' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator3_CSTATE[0] = ctrl_DP_basic_B.Sum5[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator3_CSTATE[1] = ctrl_DP_basic_B.Sum5[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator3_CSTATE[2] = ctrl_DP_basic_B.Sum5[2];
  }

  /* Derivatives for Integrator: '<S6>/Integrator' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE_l[0] = ctrl_DP_basic_B.Sum1[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE_l[1] = ctrl_DP_basic_B.Sum1[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE_l[2] = ctrl_DP_basic_B.Sum1[2];
  }

  /* Derivatives for Integrator: '<S6>/Integrator2' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator2_CSTATE[0] = ctrl_DP_basic_B.MatrixMultiply1[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator2_CSTATE[1] = ctrl_DP_basic_B.MatrixMultiply1[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator2_CSTATE[2] = ctrl_DP_basic_B.MatrixMultiply1[2];
  }

  /* Derivatives for Integrator: '<S17>/Integrator2' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator2_CSTATE_e[0] = ctrl_DP_basic_B.MatrixMultiply[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator2_CSTATE_e[1] = ctrl_DP_basic_B.MatrixMultiply[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator2_CSTATE_e[2] = ctrl_DP_basic_B.MatrixMultiply[2];
  }
}

/* Model initialize function */
void ctrl_DP_basic_initialize(void)
{
  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;

    /* Start for Iterator SubSystem: '<S9>/For Each Subsystem' */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      ctrl_DP_basic_B.CoreSubsys[ForEach_itr].angle = 0.0;
      ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE =
        0.0;
      ctrl_DP_basic_B.CoreSubsys[ForEach_itr].Delay = 0.0;
      ctrl_DP_basic_B.CoreSubsys[ForEach_itr].MaxRotationRate = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */
      ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI =
        1U;
      ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese =
        2;

      /* InitializeConditions for Delay: '<S46>/Delay' */
      ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_DP_basic_P.CoreSubsys.Delay_InitialCondition;
    }

    /* End of Start for SubSystem: '<S9>/For Each Subsystem' */
  }

  ctrl_DP_basic_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator1_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator3_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator2_Reset_ZCE_m = UNINITIALIZED_ZCSIG;

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;

    /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE =
      ctrl_DP_basic_P.DiscreteTimeIntegrator_IC;
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S72>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_h =
      ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_m;
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_p = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_d =
      ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_p;
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_n = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S92>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_g =
      ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_l;
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_b = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S102>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_f =
      ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_me;
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_e = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hl =
      ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_e;
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_m = 2;

    /* InitializeConditions for Integrator: '<S17>/Integrator1' */
    if (rtmIsFirstInitCond(ctrl_DP_basic_M)) {
      ctrl_DP_basic_X.Integrator1_CSTATE[0] = 0.0;
      ctrl_DP_basic_X.Integrator1_CSTATE[1] = 0.0;
      ctrl_DP_basic_X.Integrator1_CSTATE[2] = 0.0;
    }

    ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Integrator: '<S12>/Integrator' */
    ctrl_DP_basic_X.Integrator_CSTATE[0] = ctrl_DP_basic_P.Integrator_IC;
    ctrl_DP_basic_X.Integrator_CSTATE[1] = ctrl_DP_basic_P.Integrator_IC;
    ctrl_DP_basic_X.Integrator_CSTATE[2] = ctrl_DP_basic_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S6>/Integrator1' */
    ctrl_DP_basic_X.Integrator1_CSTATE_g[0] = (ctrl_DP_basic_P.Integrator1_IC[0]);
    ctrl_DP_basic_X.Integrator1_CSTATE_g[1] = (ctrl_DP_basic_P.Integrator1_IC[1]);
    ctrl_DP_basic_X.Integrator1_CSTATE_g[2] = (ctrl_DP_basic_P.Integrator1_IC[2]);

    /* InitializeConditions for Integrator: '<S17>/Integrator3' */
    ctrl_DP_basic_X.Integrator3_CSTATE[0] = ctrl_DP_basic_P.Integrator3_IC;
    ctrl_DP_basic_X.Integrator3_CSTATE[1] = ctrl_DP_basic_P.Integrator3_IC;
    ctrl_DP_basic_X.Integrator3_CSTATE[2] = ctrl_DP_basic_P.Integrator3_IC;

    /* InitializeConditions for Iterator SubSystem: '<S9>/For Each Subsystem' */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      /* InitializeConditions for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' */
      ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI =
        1U;
      ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese =
        2;

      /* InitializeConditions for Delay: '<S46>/Delay' */
      ctrl_DP_basic_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_DP_basic_P.CoreSubsys.Delay_InitialCondition;
    }

    /* End of InitializeConditions for SubSystem: '<S9>/For Each Subsystem' */
    /* InitializeConditions for Integrator: '<S6>/Integrator' */
    if (rtmIsFirstInitCond(ctrl_DP_basic_M)) {
      ctrl_DP_basic_X.Integrator_CSTATE_l[0] = 0.0;
      ctrl_DP_basic_X.Integrator_CSTATE_l[1] = 0.0;
      ctrl_DP_basic_X.Integrator_CSTATE_l[2] = 0.0;
    }

    ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Integrator: '<S6>/Integrator2' */
    ctrl_DP_basic_X.Integrator2_CSTATE[0] = (ctrl_DP_basic_P.Integrator2_IC[0]);
    ctrl_DP_basic_X.Integrator2_CSTATE[1] = (ctrl_DP_basic_P.Integrator2_IC[1]);
    ctrl_DP_basic_X.Integrator2_CSTATE[2] = (ctrl_DP_basic_P.Integrator2_IC[2]);

    /* InitializeConditions for Integrator: '<S17>/Integrator2' */
    ctrl_DP_basic_X.Integrator2_CSTATE_e[0] = ctrl_DP_basic_P.Integrator2_IC_h;
    ctrl_DP_basic_X.Integrator2_CSTATE_e[1] = ctrl_DP_basic_P.Integrator2_IC_h;
    ctrl_DP_basic_X.Integrator2_CSTATE_e[2] = ctrl_DP_basic_P.Integrator2_IC_h;

    /* InitializeConditions for Delay: '<S54>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE = ctrl_DP_basic_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S63>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_j = ctrl_DP_basic_P.Delay_InitialCondition_f;

    /* InitializeConditions for DiscreteTransferFcn: '<S63>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states[0] =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialStat;
    ctrl_DP_basic_DW.DiscreteTransferFcn_states[1] =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialStat;

    /* InitializeConditions for UnitDelay: '<S66>/UD' */
    ctrl_DP_basic_DW.UD_DSTATE = ctrl_DP_basic_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for RateLimiter: '<S63>/Acceleration Limit' */
    ctrl_DP_basic_DW.PrevY = ctrl_DP_basic_P.AccelerationLimit_IC;

    /* InitializeConditions for Memory: '<S63>/Memory' */
    ctrl_DP_basic_DW.Memory_PreviousInput = ctrl_DP_basic_P.Memory_X0;

    /* InitializeConditions for DiscreteIntegrator: '<S65>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu =
      ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_c;
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevR_em = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S54>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_b =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialSt_o;

    /* InitializeConditions for Delay: '<S55>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_l = ctrl_DP_basic_P.Delay_InitialCondition_fk;

    /* InitializeConditions for Delay: '<S73>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_e = ctrl_DP_basic_P.Delay_InitialCondition_k;

    /* InitializeConditions for DiscreteTransferFcn: '<S73>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_j[0] =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialSt_p;
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_j[1] =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialSt_p;

    /* InitializeConditions for UnitDelay: '<S76>/UD' */
    ctrl_DP_basic_DW.UD_DSTATE_j =
      ctrl_DP_basic_P.DiscreteDerivative_ICPrevScal_k;

    /* InitializeConditions for RateLimiter: '<S73>/Acceleration Limit' */
    ctrl_DP_basic_DW.PrevY_e = ctrl_DP_basic_P.AccelerationLimit_IC_b;

    /* InitializeConditions for Memory: '<S73>/Memory' */
    ctrl_DP_basic_DW.Memory_PreviousInput_e = ctrl_DP_basic_P.Memory_X0_j;

    /* InitializeConditions for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_n =
      ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_a;
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_o = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S55>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_e =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialSt_e;

    /* InitializeConditions for Delay: '<S56>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_p = ctrl_DP_basic_P.Delay_InitialCondition_o;

    /* InitializeConditions for Delay: '<S83>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_f = ctrl_DP_basic_P.Delay_InitialCondition_i;

    /* InitializeConditions for DiscreteTransferFcn: '<S83>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_c[0] =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialSt_n;
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_c[1] =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialSt_n;

    /* InitializeConditions for UnitDelay: '<S86>/UD' */
    ctrl_DP_basic_DW.UD_DSTATE_g =
      ctrl_DP_basic_P.DiscreteDerivative_ICPrevScal_l;

    /* InitializeConditions for RateLimiter: '<S83>/Acceleration limiter' */
    ctrl_DP_basic_DW.PrevY_f = ctrl_DP_basic_P.Accelerationlimiter_IC;

    /* InitializeConditions for Memory: '<S83>/Memory' */
    ctrl_DP_basic_DW.Memory_PreviousInput_i = ctrl_DP_basic_P.Memory_X0_b;

    /* InitializeConditions for DiscreteIntegrator: '<S85>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_l =
      ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_o;
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_k = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S56>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_i =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialSt_m;

    /* InitializeConditions for Delay: '<S57>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_d = ctrl_DP_basic_P.Delay_InitialCondition_n;

    /* InitializeConditions for Delay: '<S93>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_ev = ctrl_DP_basic_P.Delay_InitialCondition_n0;

    /* InitializeConditions for DiscreteTransferFcn: '<S93>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_m[0] =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialSt_l;
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_m[1] =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialSt_l;

    /* InitializeConditions for UnitDelay: '<S96>/UD' */
    ctrl_DP_basic_DW.UD_DSTATE_o =
      ctrl_DP_basic_P.DiscreteDerivative_ICPrevScal_p;

    /* InitializeConditions for RateLimiter: '<S93>/Acceleration limiter' */
    ctrl_DP_basic_DW.PrevY_l = ctrl_DP_basic_P.Accelerationlimiter_IC_j;

    /* InitializeConditions for Memory: '<S93>/Memory' */
    ctrl_DP_basic_DW.Memory_PreviousInput_l = ctrl_DP_basic_P.Memory_X0_h;

    /* InitializeConditions for DiscreteIntegrator: '<S95>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hx =
      ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_k;
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_g = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S57>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_ms =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialS_n4;

    /* InitializeConditions for Delay: '<S58>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_du = ctrl_DP_basic_P.Delay_InitialCondition_a;

    /* InitializeConditions for Delay: '<S103>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_n = ctrl_DP_basic_P.Delay_InitialCondition_fn;

    /* InitializeConditions for DiscreteTransferFcn: '<S103>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_f[0] =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialS_ev;
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_f[1] =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialS_ev;

    /* InitializeConditions for UnitDelay: '<S106>/UD' */
    ctrl_DP_basic_DW.UD_DSTATE_n =
      ctrl_DP_basic_P.DiscreteDerivative_ICPrevScal_h;

    /* InitializeConditions for RateLimiter: '<S103>/Acceleration limiter' */
    ctrl_DP_basic_DW.PrevY_c = ctrl_DP_basic_P.Accelerationlimiter_IC_h;

    /* InitializeConditions for Memory: '<S103>/Memory' */
    ctrl_DP_basic_DW.Memory_PreviousInput_m = ctrl_DP_basic_P.Memory_X0_p;

    /* InitializeConditions for DiscreteIntegrator: '<S105>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_p =
      ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_mk;
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_f = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S58>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_ix =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialS_oi;

    /* InitializeConditions for Delay: '<S59>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_k = ctrl_DP_basic_P.Delay_InitialCondition_e;

    /* InitializeConditions for Delay: '<S113>/Delay' */
    ctrl_DP_basic_DW.Delay_DSTATE_o = ctrl_DP_basic_P.Delay_InitialCondition_g;

    /* InitializeConditions for DiscreteTransferFcn: '<S113>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_k[0] =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialSt_a;
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_k[1] =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialSt_a;

    /* InitializeConditions for UnitDelay: '<S116>/UD' */
    ctrl_DP_basic_DW.UD_DSTATE_d =
      ctrl_DP_basic_P.DiscreteDerivative_ICPrevScal_b;

    /* InitializeConditions for RateLimiter: '<S113>/Acceleration limiter' */
    ctrl_DP_basic_DW.PrevY_ca = ctrl_DP_basic_P.Accelerationlimiter_IC_m;

    /* InitializeConditions for Memory: '<S113>/Memory' */
    ctrl_DP_basic_DW.Memory_PreviousInput_p = ctrl_DP_basic_P.Memory_X0_g;

    /* InitializeConditions for DiscreteIntegrator: '<S115>/Discrete-Time Integrator' */
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_gt =
      ctrl_DP_basic_P.DiscreteTimeIntegrator_IC_b;
    ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_c = 2;

    /* InitializeConditions for DiscreteTransferFcn: '<S59>/Discrete Transfer Fcn' */
    ctrl_DP_basic_DW.DiscreteTransferFcn_states_l =
      ctrl_DP_basic_P.DiscreteTransferFcn_InitialSt_f;

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(ctrl_DP_basic_M)) {
      rtmSetFirstInitCond(ctrl_DP_basic_M, 0);
    }
  }
}

/* Model terminate function */
void ctrl_DP_basic_terminate(void)
{
  /* (no terminate code required) */
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
  ctrl_DP_basic_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_DP_basic_update();
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
  ctrl_DP_basic_initialize();
}

void MdlTerminate(void)
{
  ctrl_DP_basic_terminate();
}

/* Registration function */
RT_MODEL_ctrl_DP_basic_T *ctrl_DP_basic(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_DP_basic_M, 0,
                sizeof(RT_MODEL_ctrl_DP_basic_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_DP_basic_M->solverInfo,
                          &ctrl_DP_basic_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_DP_basic_M->solverInfo, &rtmGetTPtr(ctrl_DP_basic_M));
    rtsiSetStepSizePtr(&ctrl_DP_basic_M->solverInfo,
                       &ctrl_DP_basic_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_DP_basic_M->solverInfo,
                 &ctrl_DP_basic_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_DP_basic_M->solverInfo, (real_T **)
                         &ctrl_DP_basic_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_DP_basic_M->solverInfo,
      &ctrl_DP_basic_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_DP_basic_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_DP_basic_M)));
    rtsiSetRTModelPtr(&ctrl_DP_basic_M->solverInfo, ctrl_DP_basic_M);
  }

  rtsiSetSimTimeStep(&ctrl_DP_basic_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_DP_basic_M->ModelData.intgData.y = ctrl_DP_basic_M->ModelData.odeY;
  ctrl_DP_basic_M->ModelData.intgData.f[0] = ctrl_DP_basic_M->ModelData.odeF[0];
  ctrl_DP_basic_M->ModelData.intgData.f[1] = ctrl_DP_basic_M->ModelData.odeF[1];
  ctrl_DP_basic_M->ModelData.intgData.f[2] = ctrl_DP_basic_M->ModelData.odeF[2];
  ctrl_DP_basic_M->ModelData.intgData.f[3] = ctrl_DP_basic_M->ModelData.odeF[3];
  ctrl_DP_basic_M->ModelData.contStates = ((real_T *) &ctrl_DP_basic_X);
  rtsiSetSolverData(&ctrl_DP_basic_M->solverInfo, (void *)
                    &ctrl_DP_basic_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_DP_basic_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_DP_basic_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_DP_basic_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_DP_basic_M->Timing.sampleTimes =
      (&ctrl_DP_basic_M->Timing.sampleTimesArray[0]);
    ctrl_DP_basic_M->Timing.offsetTimes =
      (&ctrl_DP_basic_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_DP_basic_M->Timing.sampleTimes[0] = (0.0);
    ctrl_DP_basic_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_DP_basic_M->Timing.offsetTimes[0] = (0.0);
    ctrl_DP_basic_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_DP_basic_M, &ctrl_DP_basic_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_DP_basic_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_DP_basic_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_DP_basic_M, -1);
  ctrl_DP_basic_M->Timing.stepSize0 = 0.01;
  ctrl_DP_basic_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_DP_basic_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_DP_basic_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_DP_basic_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_DP_basic_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_DP_basic_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_DP_basic_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_DP_basic_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_DP_basic_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_DP_basic_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_DP_basic_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_DP_basic_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_DP_basic_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_DP_basic_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_DP_basic_M->rtwLogInfo, (NULL));
  }

  ctrl_DP_basic_M->solverInfoPtr = (&ctrl_DP_basic_M->solverInfo);
  ctrl_DP_basic_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_DP_basic_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_DP_basic_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_DP_basic_M->ModelData.blockIO = ((void *) &ctrl_DP_basic_B);
  (void) memset(((void *) &ctrl_DP_basic_B), 0,
                sizeof(B_ctrl_DP_basic_T));

  /* parameters */
  ctrl_DP_basic_M->ModelData.defaultParam = ((real_T *)&ctrl_DP_basic_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_DP_basic_X;
    ctrl_DP_basic_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_DP_basic_X, 0,
                  sizeof(X_ctrl_DP_basic_T));
  }

  /* states (dwork) */
  ctrl_DP_basic_M->ModelData.dwork = ((void *) &ctrl_DP_basic_DW);
  (void) memset((void *)&ctrl_DP_basic_DW, 0,
                sizeof(DW_ctrl_DP_basic_T));

  /* Initialize Sizes */
  ctrl_DP_basic_M->Sizes.numContStates = (21);/* Number of continuous states */
  ctrl_DP_basic_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_DP_basic_M->Sizes.numY = (0);   /* Number of model outputs */
  ctrl_DP_basic_M->Sizes.numU = (0);   /* Number of model inputs */
  ctrl_DP_basic_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_DP_basic_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_DP_basic_M->Sizes.numBlocks = (522);/* Number of blocks */
  ctrl_DP_basic_M->Sizes.numBlockIO = (196);/* Number of block outputs */
  ctrl_DP_basic_M->Sizes.numBlockPrms = (828);/* Sum of parameter "widths" */
  return ctrl_DP_basic_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_DP_basic
 * Model version : 1.63
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Tue May 10 14:07:05 2016
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_DP_basic
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
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 35:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 36:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 37:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 38:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 39:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 40:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 43:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 48:
    return NIRT_GetValueByDataType(ptr,subindex,47,Complex);

   case 56:
    return NIRT_GetValueByDataType(ptr,subindex,55,Complex);

   case 64:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 65:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 66:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 67:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 31:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 38:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 39:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 40:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 43:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 48:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,47,Complex);

   case 56:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,55,Complex);

   case 64:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 65:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 66:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 67:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_DP_basic_rtModel *S;
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

  // ctrl_DP_basic/Thruster control /Thruster 1/Shaft dynamics/reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster control /Thruster 2/Shaft dynamics/reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_n, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster control /Thruster 3/Shaft dynamics/reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_d, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster control /Thruster 4/Shaft dynamics/reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_l, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster control /Thruster 5/Shaft dynamics/reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_e, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster control /Thruster 6/Shaft dynamics/reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_a, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Control Gains/K_p_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_p_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Control Gains/K_p_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_p_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Control Gains/K_p_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_p_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Control Gains/K_i_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_i_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Control Gains/K_i_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_i_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Control Gains/K_i_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_i_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Control Gains/K_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Control Gains/K_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Control Gains/K_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.K_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_g, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Guidance gains/w_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.w_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Guidance gains/w_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.w_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Guidance gains/w_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.w_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Guidance gains/zeta_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.zeta_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Guidance gains/zeta_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.zeta_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/Guidance gains/zeta_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.zeta_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/psi_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.psi_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/x_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.x_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Input/y_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.y_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster measurment/thr_angle_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.thr_angle_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster measurment/thr_angle_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.thr_angle_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster measurment/thr_angle_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.thr_angle_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster measurment/thr_angle_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.thr_angle_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster measurment/thr_angle_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.thr_angle_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster measurment/thr_angle_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.thr_angle_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thrust allocation1/reset
  if (TaskSampleHit[1]) {
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_a3, count, data[index++],
        26, 0);
    }
  } else {
    index += 6;
  }

  // ctrl_DP_basic/Thruster control /Thruster 1/Thruster control/Core controller/reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_i, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster control /Thruster 2/Thruster control/Core controller/reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_ig, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster control /Thruster 3/Thruster control/Core controller/reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_j, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster control /Thruster 4/Thruster control/Core controller/reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_o, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster control /Thruster 5/Thruster control/Core controller/reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_n5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Thruster control /Thruster 6/Thruster control/Core controller/reset
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset_b, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 46;
}

int32_t NumOutputPorts(void)
{
  return 48;
}

double ni_extout[48];

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

  // ctrl_DP_basic/pwm_1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.pwmthruster1,
      0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/pwm_2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.pwmthruster2,
      0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/pwm_3: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.pwmthruster3,
      0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/pwm_4: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.pwmthruster4,
      0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/pwm_5: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.pwmthruster5,
      0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/alpha_1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation1, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/pwm_6: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.pwmthruster6,
      0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/alpha_2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation2, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/alpha_3: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation3, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/alpha_4: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation4, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/alpha_5: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation5, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/alpha_6: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation6, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/u_4: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation7, 3,
      26, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/u_5: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation7, 4,
      26, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/u_6: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation7, 5,
      26, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/u_1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation7, 0,
      26, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/u_2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation7, 1,
      26, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /eta_hat output/x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator, 0,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /eta_hat output/y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator, 1,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum_f, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /nu_hat output/u_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g,
      0, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /nu_hat output/v_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g,
      1, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /nu_hat output/r_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g,
      2, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1, 0, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1, 1, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1, 2, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2, 0,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2, 1,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2, 2,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/u_3: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation7, 2,
      26, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance/eta_des: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult, 0, 21, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult, 1, 21, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult, 2, 21, 0);
  } else {
    index += 3;
  }

  // ctrl_DP_basic/Control output/tau_N: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3, 2, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/tau_X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3, 0, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/tau_Y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3, 1, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/psi_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_B.regulationerror, 2, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/x_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_B.regulationerror, 0, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/y_tidle: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_B.regulationerror, 1, 21, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/r_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4, 2, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/u_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4, 0, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/v_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4, 1, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance output/x_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1, 0,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance output/y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1, 1,
      22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance output/psi_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum, 0, 64, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance output/r_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row3, 0, 64, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance output/u_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row1, 0, 64, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance output/v_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row2, 0, 64, 0);
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

  // ctrl_DP_basic/pwm_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.pwmthruster1, 0,
    0, 0);

  // ctrl_DP_basic/pwm_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.pwmthruster2, 0,
    0, 0);

  // ctrl_DP_basic/pwm_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.pwmthruster3, 0,
    0, 0);

  // ctrl_DP_basic/pwm_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.pwmthruster4, 0,
    0, 0);

  // ctrl_DP_basic/pwm_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.pwmthruster5, 0,
    0, 0);

  // ctrl_DP_basic/alpha_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation1, 0,
    0, 0);

  // ctrl_DP_basic/pwm_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.pwmthruster6, 0,
    0, 0);

  // ctrl_DP_basic/alpha_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation2, 0,
    0, 0);

  // ctrl_DP_basic/alpha_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation3, 0,
    0, 0);

  // ctrl_DP_basic/alpha_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation4, 0,
    0, 0);

  // ctrl_DP_basic/alpha_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation5, 0,
    0, 0);

  // ctrl_DP_basic/alpha_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation6, 0,
    0, 0);

  // ctrl_DP_basic/u_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation7, 3,
    26, 0);

  // ctrl_DP_basic/u_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation7, 4,
    26, 0);

  // ctrl_DP_basic/u_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation7, 5,
    26, 0);

  // ctrl_DP_basic/u_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation7, 0,
    26, 0);

  // ctrl_DP_basic/u_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation7, 1,
    26, 0);

  // ctrl_DP_basic/Observer output /eta_hat output/x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator, 0,
    22, 0);

  // ctrl_DP_basic/Observer output /eta_hat output/y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator, 1,
    22, 0);

  // ctrl_DP_basic/Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum_f, 0, 0, 0);

  // ctrl_DP_basic/Observer output /nu_hat output/u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g, 0,
    22, 0);

  // ctrl_DP_basic/Observer output /nu_hat output/v_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g, 1,
    22, 0);

  // ctrl_DP_basic/Observer output /nu_hat output/r_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g, 2,
    22, 0);

  // ctrl_DP_basic/Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1, 0, 22, 0);

  // ctrl_DP_basic/Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1, 1, 22, 0);

  // ctrl_DP_basic/Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1, 2, 22, 0);

  // ctrl_DP_basic/Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2, 0,
    22, 0);

  // ctrl_DP_basic/Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2, 1,
    22, 0);

  // ctrl_DP_basic/Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2, 2,
    22, 0);

  // ctrl_DP_basic/u_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Saturation7, 2,
    26, 0);

  // ctrl_DP_basic/Guidance/eta_des: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult, 0, 21, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult, 1, 21, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult, 2, 21, 0);

  // ctrl_DP_basic/Control output/tau_N: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3, 2, 22, 0);

  // ctrl_DP_basic/Control output/tau_X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3, 0, 22, 0);

  // ctrl_DP_basic/Control output/tau_Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3, 1, 22, 0);

  // ctrl_DP_basic/Control output/psi_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.regulationerror,
    2, 21, 0);

  // ctrl_DP_basic/Control output/x_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.regulationerror,
    0, 21, 0);

  // ctrl_DP_basic/Control output/y_tidle: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.regulationerror,
    1, 21, 0);

  // ctrl_DP_basic/Control output/r_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4, 2, 22, 0);

  // ctrl_DP_basic/Control output/u_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4, 0, 22, 0);

  // ctrl_DP_basic/Control output/v_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4, 1, 22, 0);

  // ctrl_DP_basic/Guidance output/x_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1, 0,
    22, 0);

  // ctrl_DP_basic/Guidance output/y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1, 1,
    22, 0);

  // ctrl_DP_basic/Guidance output/psi_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum, 0, 64, 0);

  // ctrl_DP_basic/Guidance output/r_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row3, 0, 64, 0);

  // ctrl_DP_basic/Guidance output/u_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row1, 0, 64, 0);

  // ctrl_DP_basic/Guidance output/v_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row2, 0, 64, 0);
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
  { 0, "ctrl_dp_basic/Thrust allocation1/C/Value", offsetof(P_ctrl_DP_basic_T, C),
    28, 24, 2, 0, 0 },

  { 1, "ctrl_dp_basic/Parameters From initfile distributed /D/Value", offsetof
    (P_ctrl_DP_basic_T, D), 64, 1, 2, 2, 0 },

  { 2,
    "ctrl_dp_basic/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_DP_basic_T, I_s), 64, 1, 2, 4, 0 },

  { 3,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_DP_basic_T, I_s), 64, 1, 2, 6, 0 },

  { 4,
    "ctrl_dp_basic/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_DP_basic_T, I_s), 64, 1, 2, 8, 0 },

  { 5,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_DP_basic_T, I_s), 64, 1, 2, 10, 0 },

  { 6,
    "ctrl_dp_basic/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_DP_basic_T, I_s), 64, 1, 2, 12, 0 },

  { 7,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_DP_basic_T, I_s), 64, 1, 2, 14, 0 },

  { 8,
    "ctrl_dp_basic/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_DP_basic_T, I_s), 64, 1, 2, 16, 0 },

  { 9,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_DP_basic_T, I_s), 64, 1, 2, 18, 0 },

  { 10,
    "ctrl_dp_basic/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_DP_basic_T, I_s), 64, 1, 2, 20, 0 },

  { 11,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_DP_basic_T, I_s), 64, 1, 2, 22, 0 },

  { 12,
    "ctrl_dp_basic/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_DP_basic_T, I_s), 64, 1, 2, 24, 0 },

  { 13,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_DP_basic_T, I_s), 64, 1, 2, 26, 0 },

  { 14, "ctrl_dp_basic/Thruster control /Thruster 1/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_DP_basic_T, K_omega), 64, 1, 2, 28, 0 },

  { 15,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, K_omega), 64, 1, 2, 30, 0 },

  { 16, "ctrl_dp_basic/Thruster control /Thruster 2/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_DP_basic_T, K_omega), 64, 1, 2, 32, 0 },

  { 17,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, K_omega), 64, 1, 2, 34, 0 },

  { 18, "ctrl_dp_basic/Thruster control /Thruster 3/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_DP_basic_T, K_omega), 64, 1, 2, 36, 0 },

  { 19,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, K_omega), 64, 1, 2, 38, 0 },

  { 20, "ctrl_dp_basic/Thruster control /Thruster 4/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_DP_basic_T, K_omega), 64, 1, 2, 40, 0 },

  { 21,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, K_omega), 64, 1, 2, 42, 0 },

  { 22, "ctrl_dp_basic/Thruster control /Thruster 5/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_DP_basic_T, K_omega), 64, 1, 2, 44, 0 },

  { 23,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, K_omega), 64, 1, 2, 46, 0 },

  { 24, "ctrl_dp_basic/Thruster control /Thruster 6/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_DP_basic_T, K_omega), 64, 1, 2, 48, 0 },

  { 25,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, K_omega), 64, 1, 2, 50, 0 },

  { 26,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_DP_basic_T, Kp), 64, 1, 2, 52, 0 },

  { 27,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_DP_basic_T, Kp), 64, 1, 2, 54, 0 },

  { 28,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_DP_basic_T, Kp), 64, 1, 2, 56, 0 },

  { 29,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_DP_basic_T, Kp), 64, 1, 2, 58, 0 },

  { 30,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_DP_basic_T, Kp), 64, 1, 2, 60, 0 },

  { 31,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_DP_basic_T, Kp), 64, 1, 2, 62, 0 },

  { 32,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_DP_basic_T, Kp), 64, 1, 2, 64, 0 },

  { 33,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_DP_basic_T, Kp), 64, 1, 2, 66, 0 },

  { 34,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_DP_basic_T, Kp), 64, 1, 2, 68, 0 },

  { 35,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_DP_basic_T, Kp), 64, 1, 2, 70, 0 },

  { 36,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_DP_basic_T, Kp), 64, 1, 2, 72, 0 },

  { 37,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_DP_basic_T, Kp), 64, 1, 2, 74, 0 },

  { 38, "ctrl_dp_basic/Parameters From initfile distributed /Kq/Value", offsetof
    (P_ctrl_DP_basic_T, Kq), 64, 1, 2, 76, 0 },

  { 39, "ctrl_dp_basic/Parameters From initfile distributed /Kqr/Value",
    offsetof(P_ctrl_DP_basic_T, Kqr), 64, 1, 2, 78, 0 },

  { 40, "ctrl_dp_basic/Parameters From initfile distributed /Kt/Value", offsetof
    (P_ctrl_DP_basic_T, Kt), 64, 1, 2, 80, 0 },

  { 41, "ctrl_dp_basic/Parameters From initfile distributed /Ktr/Value",
    offsetof(P_ctrl_DP_basic_T, Ktr), 64, 1, 2, 82, 0 },

  { 42,
    "ctrl_dp_basic/Thrust allocation1/For Each Subsystem/Max Rotation Rate/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Max_rotation), 64, 1, 2, 84, 0 },

  { 43,
    "ctrl_dp_basic/Thrust allocation1/For Each Subsystem/Max Rotation Rate/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Max_rotation), 64, 1, 2, 86, 0 },

  { 44, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 1/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 88, 0 },

  { 45, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 1/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 90, 0 },

  { 46, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 2/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 92, 0 },

  { 47, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 2/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 94, 0 },

  { 48, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 3/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 96, 0 },

  { 49, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 3/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 98, 0 },

  { 50, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 4/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 100, 0 },

  { 51, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 4/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 102, 0 },

  { 52, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 5/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 104, 0 },

  { 53, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 5/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 106, 0 },

  { 54, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 6/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 108, 0 },

  { 55, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 6/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 110, 0 },

  { 56, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 7/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 112, 0 },

  { 57, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 7/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Max_thrust), 64, 1, 2, 114, 0 },

  { 58,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/P_max/Value",
    offsetof(P_ctrl_DP_basic_T, P_max), 64, 1, 2, 116, 0 },

  { 59,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/P_max/Value",
    offsetof(P_ctrl_DP_basic_T, P_max), 64, 1, 2, 118, 0 },

  { 60,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/P_max/Value",
    offsetof(P_ctrl_DP_basic_T, P_max), 64, 1, 2, 120, 0 },

  { 61,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/P_max/Value",
    offsetof(P_ctrl_DP_basic_T, P_max), 64, 1, 2, 122, 0 },

  { 62,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/P_max/Value",
    offsetof(P_ctrl_DP_basic_T, P_max), 64, 1, 2, 124, 0 },

  { 63,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/P_max/Value",
    offsetof(P_ctrl_DP_basic_T, P_max), 64, 1, 2, 126, 0 },

  { 64, "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_DP_basic_T, Q_f0), 64, 1, 2, 128, 0 },

  { 65, "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_DP_basic_T, Q_f0), 64, 1, 2, 130, 0 },

  { 66, "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_DP_basic_T, Q_f0), 64, 1, 2, 132, 0 },

  { 67, "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_DP_basic_T, Q_f0), 64, 1, 2, 134, 0 },

  { 68, "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_DP_basic_T, Q_f0), 64, 1, 2, 136, 0 },

  { 69, "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_DP_basic_T, Q_f0), 64, 1, 2, 138, 0 },

  { 70,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Q_max/Value",
    offsetof(P_ctrl_DP_basic_T, Q_max), 64, 1, 2, 140, 0 },

  { 71,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Q_max/Value",
    offsetof(P_ctrl_DP_basic_T, Q_max), 64, 1, 2, 142, 0 },

  { 72,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Q_max/Value",
    offsetof(P_ctrl_DP_basic_T, Q_max), 64, 1, 2, 144, 0 },

  { 73,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Q_max/Value",
    offsetof(P_ctrl_DP_basic_T, Q_max), 64, 1, 2, 146, 0 },

  { 74,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Q_max/Value",
    offsetof(P_ctrl_DP_basic_T, Q_max), 64, 1, 2, 148, 0 },

  { 75,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Q_max/Value",
    offsetof(P_ctrl_DP_basic_T, Q_max), 64, 1, 2, 150, 0 },

  { 76,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Core controller/Discrete-Time Integrator/UpperSaturationLimit",
    offsetof(P_ctrl_DP_basic_T, Q_max), 64, 1, 2, 152, 0 },

  { 77,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Core controller/Discrete-Time Integrator/LowerSaturationLimit",
    offsetof(P_ctrl_DP_basic_T, Q_max), 64, 1, 2, 154, 0 },

  { 78, "ctrl_dp_basic/Parameters From initfile distributed /Rho/Value",
    offsetof(P_ctrl_DP_basic_T, Rho), 64, 1, 2, 156, 0 },

  { 79,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_DP_basic_T, Thruster_control), 64, 1, 2, 158, 0 },

  { 80,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_DP_basic_T, Thruster_control), 64, 1, 2, 160, 0 },

  { 81,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_DP_basic_T, Thruster_control), 64, 1, 2, 162, 0 },

  { 82,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_DP_basic_T, Thruster_control), 64, 1, 2, 164, 0 },

  { 83,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_DP_basic_T, Thruster_control), 64, 1, 2, 166, 0 },

  { 84,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_DP_basic_T, Thruster_control), 64, 1, 2, 168, 0 },

  { 85, "ctrl_dp_basic/Thrust allocation1/Switch  Azimuth//Fixed angles/Value",
    offsetof(P_ctrl_DP_basic_T, Thruster_lock), 64, 1, 2, 170, 0 },

  { 86, "ctrl_dp_basic/Parameters From initfile distributed /Constant4/Value",
    offsetof(P_ctrl_DP_basic_T, eps), 64, 1, 2, 172, 0 },

  { 87, "ctrl_dp_basic/Thrust allocation1/Constant to avoid singularities/Value",
    offsetof(P_ctrl_DP_basic_T, eps), 64, 1, 2, 174, 0 },

  { 88, "ctrl_dp_basic/Parameters From initfile distributed /Constant/Value",
    offsetof(P_ctrl_DP_basic_T, eps_c), 64, 1, 2, 176, 0 },

  { 89,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, epsilon), 64, 1, 2, 178, 0 },

  { 90,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, epsilon), 64, 1, 2, 180, 0 },

  { 91,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, epsilon), 64, 1, 2, 182, 0 },

  { 92,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, epsilon), 64, 1, 2, 184, 0 },

  { 93,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, epsilon), 64, 1, 2, 186, 0 },

  { 94,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, epsilon), 64, 1, 2, 188, 0 },

  { 95, "ctrl_dp_basic/Parameters From initfile distributed /Constant1/Value",
    offsetof(P_ctrl_DP_basic_T, k_cc), 64, 1, 2, 190, 0 },

  { 96, "ctrl_dp_basic/Parameters From initfile distributed /Constant5/Value",
    offsetof(P_ctrl_DP_basic_T, n_c), 64, 1, 2, 192, 0 },

  { 97,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, n_max), 64, 1, 2, 194, 0 },

  { 98,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, n_max), 64, 1, 2, 196, 0 },

  { 99,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, n_max), 64, 1, 2, 198, 0 },

  { 100,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, n_max), 64, 1, 2, 200, 0 },

  { 101,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, n_max), 64, 1, 2, 202, 0 },

  { 102,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_DP_basic_T, n_max), 64, 1, 2, 204, 0 },

  { 103, "ctrl_dp_basic/Parameters From initfile distributed /Constant2/Value",
    offsetof(P_ctrl_DP_basic_T, p_cc), 64, 1, 2, 206, 0 },

  { 104, "ctrl_dp_basic/Parameters From initfile distributed /Constant3/Value",
    offsetof(P_ctrl_DP_basic_T, r_cc), 64, 1, 2, 208, 0 },

  { 105, "ctrl_dp_basic/Thruster control /Subsystem/pwm thruster 1/Coefs",
    offsetof(P_ctrl_DP_basic_T, thrust_to_pwm_coeff), 36, 6, 2, 210, 0 },

  { 106, "ctrl_dp_basic/Thruster control /Subsystem/pwm thruster 2/Coefs",
    offsetof(P_ctrl_DP_basic_T, thrust_to_pwm_coeff), 36, 6, 2, 212, 0 },

  { 107, "ctrl_dp_basic/Thruster control /Subsystem/pwm thruster 3/Coefs",
    offsetof(P_ctrl_DP_basic_T, thrust_to_pwm_coeff), 36, 6, 2, 214, 0 },

  { 108, "ctrl_dp_basic/Thruster control /Subsystem/pwm thruster 4/Coefs",
    offsetof(P_ctrl_DP_basic_T, thrust_to_pwm_coeff), 36, 6, 2, 216, 0 },

  { 109, "ctrl_dp_basic/Thruster control /Subsystem/pwm thruster 5/Coefs",
    offsetof(P_ctrl_DP_basic_T, thrust_to_pwm_coeff), 36, 6, 2, 218, 0 },

  { 110, "ctrl_dp_basic/Thruster control /Subsystem/pwm thruster 6/Coefs",
    offsetof(P_ctrl_DP_basic_T, thrust_to_pwm_coeff), 36, 6, 2, 220, 0 },

  { 111,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteDerivative_ICPrevScaled), 64, 1, 2, 222,
    0 },

  { 112,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteDerivative_ICPrevScal_k), 64, 1, 2, 224,
    0 },

  { 113,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteDerivative_ICPrevScal_l), 64, 1, 2, 226,
    0 },

  { 114,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteDerivative_ICPrevScal_p), 64, 1, 2, 228,
    0 },

  { 115,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteDerivative_ICPrevScal_h), 64, 1, 2, 230,
    0 },

  { 116,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteDerivative_ICPrevScal_b), 64, 1, 2, 232,
    0 },

  { 117,
    "ctrl_dp_basic/Thruster control /Thruster 1/Shaft dynamics/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_gainval), 0, 1, 2, 234, 0
  },

  { 118,
    "ctrl_dp_basic/Thruster control /Thruster 1/Shaft dynamics/Discrete-Time Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_IC), 64, 1, 2, 236, 0 },

  { 119, "ctrl_dp_basic/Thruster control /Thruster 1/Losses (placeholder)/Value",
    offsetof(P_ctrl_DP_basic_T, Lossesplaceholder_Value), 64, 1, 2, 238, 0 },

  { 120,
    "ctrl_dp_basic/Thruster control /Thruster 2/Shaft dynamics/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_gainva_l), 0, 1, 2, 240,
    0 },

  { 121,
    "ctrl_dp_basic/Thruster control /Thruster 2/Shaft dynamics/Discrete-Time Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_IC_m), 64, 1, 2, 242, 0 },

  { 122, "ctrl_dp_basic/Thruster control /Thruster 2/Losses (placeholder)/Value",
    offsetof(P_ctrl_DP_basic_T, Lossesplaceholder_Value_a), 64, 1, 2, 244, 0 },

  { 123,
    "ctrl_dp_basic/Thruster control /Thruster 3/Shaft dynamics/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_gainva_i), 0, 1, 2, 246,
    0 },

  { 124,
    "ctrl_dp_basic/Thruster control /Thruster 3/Shaft dynamics/Discrete-Time Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_IC_p), 64, 1, 2, 248, 0 },

  { 125, "ctrl_dp_basic/Thruster control /Thruster 3/Losses (placeholder)/Value",
    offsetof(P_ctrl_DP_basic_T, Lossesplaceholder_Value_m), 64, 1, 2, 250, 0 },

  { 126,
    "ctrl_dp_basic/Thruster control /Thruster 4/Shaft dynamics/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_gainva_b), 0, 1, 2, 252,
    0 },

  { 127,
    "ctrl_dp_basic/Thruster control /Thruster 4/Shaft dynamics/Discrete-Time Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_IC_l), 64, 1, 2, 254, 0 },

  { 128, "ctrl_dp_basic/Thruster control /Thruster 4/Losses (placeholder)/Value",
    offsetof(P_ctrl_DP_basic_T, Lossesplaceholder_Value_i), 64, 1, 2, 256, 0 },

  { 129,
    "ctrl_dp_basic/Thruster control /Thruster 5/Shaft dynamics/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_gainva_e), 0, 1, 2, 258,
    0 },

  { 130,
    "ctrl_dp_basic/Thruster control /Thruster 5/Shaft dynamics/Discrete-Time Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_IC_me), 64, 1, 2, 260, 0
  },

  { 131, "ctrl_dp_basic/Thruster control /Thruster 5/Losses (placeholder)/Value",
    offsetof(P_ctrl_DP_basic_T, Lossesplaceholder_Value_md), 64, 1, 2, 262, 0 },

  { 132,
    "ctrl_dp_basic/Thruster control /Thruster 6/Shaft dynamics/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_gainva_a), 0, 1, 2, 264,
    0 },

  { 133,
    "ctrl_dp_basic/Thruster control /Thruster 6/Shaft dynamics/Discrete-Time Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_IC_e), 64, 1, 2, 266, 0 },

  { 134, "ctrl_dp_basic/Thruster control /Thruster 6/Losses (placeholder)/Value",
    offsetof(P_ctrl_DP_basic_T, Lossesplaceholder_Value_h), 64, 1, 2, 268, 0 },

  { 135, "ctrl_dp_basic/Thruster control /Subsystem/Constant12/Value", offsetof
    (P_ctrl_DP_basic_T, Constant12_Value), 64, 1, 2, 270, 0 },

  { 136,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat), 64, 1, 2, 272, 0 },

  { 137,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat), 64, 1, 2, 274, 0 },

  { 138, "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain), 64, 1, 2, 276, 0 },

  { 139,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value), 64, 1, 2, 278, 0 },

  { 140, "ctrl_dp_basic/Input/Observer Gains/Constant6/Value", offsetof
    (P_ctrl_DP_basic_T, Constant6_Value), 64, 1, 2, 280, 0 },

  { 141, "ctrl_dp_basic/Input/Observer Gains/Constant7/Value", offsetof
    (P_ctrl_DP_basic_T, Constant7_Value), 64, 1, 2, 282, 0 },

  { 142, "ctrl_dp_basic/Input/Observer Gains/Constant8/Value", offsetof
    (P_ctrl_DP_basic_T, Constant8_Value), 64, 1, 2, 284, 0 },

  { 143,
    "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat_j), 64, 1, 2, 286, 0 },

  { 144,
    "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat_c), 64, 1, 2, 288, 0 },

  { 145,
    "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_j), 64, 1, 2, 290, 0 },

  { 146,
    "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value_f), 64, 1, 2, 292, 0 },

  { 147,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat_a), 64, 1, 2, 294, 0 },

  { 148,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat_d), 64, 1, 2, 296, 0 },

  { 149, "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_g), 64, 1, 2, 298, 0 },

  { 150,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value_p), 64, 1, 2, 300, 0 },

  { 151, "ctrl_dp_basic/Control/DP Controller/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator_IC), 64, 1, 2, 302, 0 },

  { 152,
    "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator1/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator1_IC), 21, 3, 2, 304, 0 },

  { 153, "ctrl_dp_basic/Guidance/Reference model/Integrator3/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator3_IC), 64, 1, 2, 306, 0 },

  { 154, "ctrl_dp_basic/Thrust allocation1/Radians to Degrees/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_gz), 64, 1, 2, 308, 0 },

  { 155, "ctrl_dp_basic/Thrust allocation1/X-position Thruster/Value", offsetof
    (P_ctrl_DP_basic_T, XpositionThruster_Value), 36, 6, 2, 310, 0 },

  { 156, "ctrl_dp_basic/Thrust allocation1/Y-position Thruster/Value", offsetof
    (P_ctrl_DP_basic_T, YpositionThruster_Value), 36, 6, 2, 312, 0 },

  { 157, "ctrl_dp_basic/Thrust allocation1/constant angle/Value", offsetof
    (P_ctrl_DP_basic_T, constantangle_Value), 36, 6, 2, 314, 0 },

  { 158,
    "ctrl_dp_basic/Thrust allocation1/Choosing Fixed // Azimuth angle/Threshold",
    offsetof(P_ctrl_DP_basic_T, ChoosingFixedAzimuthangle_Thres), 64, 1, 2, 316,
    0 },

  { 159, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 1/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation1_UpperSat), 64, 1, 2, 318, 0 },

  { 160, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 1/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation1_LowerSat), 64, 1, 2, 320, 0 },

  { 161, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 2/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation2_UpperSat), 64, 1, 2, 322, 0 },

  { 162, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 2/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation2_LowerSat), 64, 1, 2, 324, 0 },

  { 163, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 3/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation3_UpperSat), 64, 1, 2, 326, 0 },

  { 164, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 3/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation3_LowerSat), 64, 1, 2, 328, 0 },

  { 165, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 4/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation4_UpperSat), 64, 1, 2, 330, 0 },

  { 166, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 4/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation4_LowerSat), 64, 1, 2, 332, 0 },

  { 167, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 5/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation5_UpperSat), 64, 1, 2, 334, 0 },

  { 168, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 5/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation5_LowerSat), 64, 1, 2, 336, 0 },

  { 169, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 6/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation6_UpperSat), 64, 1, 2, 338, 0 },

  { 170, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 6/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation6_LowerSat), 64, 1, 2, 340, 0 },

  { 171,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat_l), 64, 1, 2, 342, 0 },

  { 172,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat_cz), 64, 1, 2, 344, 0 },

  { 173,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_d), 64, 1, 2, 346, 0 },

  { 174,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value_p4), 64, 1, 2, 348, 0 },

  { 175,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat_o), 64, 1, 2, 350, 0 },

  { 176,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat_j), 64, 1, 2, 352, 0 },

  { 177,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_h), 64, 1, 2, 354, 0 },

  { 178,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value_i), 64, 1, 2, 356, 0 },

  { 179,
    "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator2_IC), 21, 3, 2, 358, 0 },

  { 180, "ctrl_dp_basic/Nonlinear Passisve Observer/M^-1/Gain", offsetof
    (P_ctrl_DP_basic_T, M1_Gain), 23, 9, 2, 360, 0 },

  { 181, "ctrl_dp_basic/Guidance/Reference model/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator2_IC_h), 64, 1, 2, 362, 0 },

  { 182, "ctrl_dp_basic/Input/Observer Gains/Constant/Value", offsetof
    (P_ctrl_DP_basic_T, Constant_Value_k), 64, 1, 2, 364, 0 },

  { 183, "ctrl_dp_basic/Input/Observer Gains/Constant1/Value", offsetof
    (P_ctrl_DP_basic_T, Constant1_Value), 64, 1, 2, 366, 0 },

  { 184, "ctrl_dp_basic/Input/Observer Gains/Constant2/Value", offsetof
    (P_ctrl_DP_basic_T, Constant2_Value), 64, 1, 2, 368, 0 },

  { 185, "ctrl_dp_basic/Input/Observer Gains/Constant3/Value", offsetof
    (P_ctrl_DP_basic_T, Constant3_Value), 64, 1, 2, 370, 0 },

  { 186, "ctrl_dp_basic/Input/Observer Gains/Constant4/Value", offsetof
    (P_ctrl_DP_basic_T, Constant4_Value), 64, 1, 2, 372, 0 },

  { 187, "ctrl_dp_basic/Input/Observer Gains/Constant5/Value", offsetof
    (P_ctrl_DP_basic_T, Constant5_Value), 64, 1, 2, 374, 0 },

  { 188, "ctrl_dp_basic/Thruster control /Thruster 1/Constant/Value", offsetof
    (P_ctrl_DP_basic_T, Constant_Value_i3), 37, 2, 2, 376, 0 },

  { 189, "ctrl_dp_basic/Thruster control /Thruster 1/Constant1/Value", offsetof
    (P_ctrl_DP_basic_T, Constant1_Value_h), 37, 2, 2, 378, 0 },

  { 190, "ctrl_dp_basic/Thruster control /Thruster 1/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Delay_InitialCondition), 64, 1, 2, 380, 0 },

  { 191,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Delay_InitialCondition_f), 64, 1, 2, 382, 0 },

  { 192,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Constant1/Value",
    offsetof(P_ctrl_DP_basic_T, Constant1_Value_e), 31, 3, 2, 384, 0 },

  { 193,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Constant2/Value",
    offsetof(P_ctrl_DP_basic_T, Constant2_Value_c), 31, 3, 2, 386, 0 },

  { 194,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_basic_T, DiscreteTransferFcn_InitialStat), 64, 1, 2, 388,
    0 },

  { 195,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_DP_basic_T, TSamp_WtEt), 0, 1, 2, 390, 0 },

  { 196,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_ctrl_DP_basic_T, AccelerationLimit_RisingLim), 0, 1, 2, 392, 0 },

  { 197,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_ctrl_DP_basic_T, AccelerationLimit_FallingLim), 0, 1, 2, 394, 0 },

  { 198,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, AccelerationLimit_IC), 64, 1, 2, 396, 0 },

  { 199, "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Memory/X0",
    offsetof(P_ctrl_DP_basic_T, Memory_X0), 64, 1, 2, 398, 0 },

  { 200,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Core controller/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_gainva_f), 0, 1, 2, 400,
    0 },

  { 201,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Core controller/Discrete-Time Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_IC_c), 64, 1, 2, 402, 0 },

  { 202, "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/NaN/Value",
    offsetof(P_ctrl_DP_basic_T, NaN_Value), 64, 1, 2, 404, 0 },

  { 203,
    "ctrl_dp_basic/Thruster control /Thruster 1/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_basic_T, DiscreteTransferFcn_InitialSt_o), 64, 1, 2, 406,
    0 },

  { 204, "ctrl_dp_basic/Thruster control /Thruster 2/Constant/Value", offsetof
    (P_ctrl_DP_basic_T, Constant_Value_b), 37, 2, 2, 408, 0 },

  { 205, "ctrl_dp_basic/Thruster control /Thruster 2/Constant1/Value", offsetof
    (P_ctrl_DP_basic_T, Constant1_Value_l), 37, 2, 2, 410, 0 },

  { 206, "ctrl_dp_basic/Thruster control /Thruster 2/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Delay_InitialCondition_fk), 64, 1, 2, 412, 0 },

  { 207,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Delay_InitialCondition_k), 64, 1, 2, 414, 0 },

  { 208,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Constant1/Value",
    offsetof(P_ctrl_DP_basic_T, Constant1_Value_f), 31, 3, 2, 416, 0 },

  { 209,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Constant2/Value",
    offsetof(P_ctrl_DP_basic_T, Constant2_Value_i), 31, 3, 2, 418, 0 },

  { 210,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_basic_T, DiscreteTransferFcn_InitialSt_p), 64, 1, 2, 420,
    0 },

  { 211,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_DP_basic_T, TSamp_WtEt_o), 0, 1, 2, 422, 0 },

  { 212,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_ctrl_DP_basic_T, AccelerationLimit_RisingLim_n), 0, 1, 2, 424, 0
  },

  { 213,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_ctrl_DP_basic_T, AccelerationLimit_FallingLim_j), 0, 1, 2, 426, 0
  },

  { 214,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, AccelerationLimit_IC_b), 64, 1, 2, 428, 0 },

  { 215, "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Memory/X0",
    offsetof(P_ctrl_DP_basic_T, Memory_X0_j), 64, 1, 2, 430, 0 },

  { 216,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Core controller/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_gainv_fz), 0, 1, 2, 432,
    0 },

  { 217,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Core controller/Discrete-Time Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_IC_a), 64, 1, 2, 434, 0 },

  { 218, "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/NaN/Value",
    offsetof(P_ctrl_DP_basic_T, NaN_Value_o), 64, 1, 2, 436, 0 },

  { 219,
    "ctrl_dp_basic/Thruster control /Thruster 2/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_basic_T, DiscreteTransferFcn_InitialSt_e), 64, 1, 2, 438,
    0 },

  { 220, "ctrl_dp_basic/Thruster control /Thruster 3/Constant/Value", offsetof
    (P_ctrl_DP_basic_T, Constant_Value_n), 37, 2, 2, 440, 0 },

  { 221, "ctrl_dp_basic/Thruster control /Thruster 3/Constant1/Value", offsetof
    (P_ctrl_DP_basic_T, Constant1_Value_g), 37, 2, 2, 442, 0 },

  { 222, "ctrl_dp_basic/Thruster control /Thruster 3/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Delay_InitialCondition_o), 64, 1, 2, 444, 0 },

  { 223,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Delay_InitialCondition_i), 64, 1, 2, 446, 0 },

  { 224,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Constant1/Value",
    offsetof(P_ctrl_DP_basic_T, Constant1_Value_k), 31, 3, 2, 448, 0 },

  { 225,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Constant2/Value",
    offsetof(P_ctrl_DP_basic_T, Constant2_Value_b), 31, 3, 2, 450, 0 },

  { 226,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_basic_T, DiscreteTransferFcn_InitialSt_n), 64, 1, 2, 452,
    0 },

  { 227,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_DP_basic_T, TSamp_WtEt_m), 0, 1, 2, 454, 0 },

  { 228,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_DP_basic_T, Accelerationlimiter_RisingLim), 0, 1, 2, 456, 0
  },

  { 229,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_DP_basic_T, Accelerationlimiter_FallingLim), 0, 1, 2, 458, 0
  },

  { 230,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Accelerationlimiter_IC), 64, 1, 2, 460, 0 },

  { 231, "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Memory/X0",
    offsetof(P_ctrl_DP_basic_T, Memory_X0_b), 64, 1, 2, 462, 0 },

  { 232,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Core controller/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_gainva_m), 0, 1, 2, 464,
    0 },

  { 233,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Core controller/Discrete-Time Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_IC_o), 64, 1, 2, 466, 0 },

  { 234, "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/NaN/Value",
    offsetof(P_ctrl_DP_basic_T, NaN_Value_g), 64, 1, 2, 468, 0 },

  { 235,
    "ctrl_dp_basic/Thruster control /Thruster 3/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_basic_T, DiscreteTransferFcn_InitialSt_m), 64, 1, 2, 470,
    0 },

  { 236, "ctrl_dp_basic/Thruster control /Thruster 4/Constant/Value", offsetof
    (P_ctrl_DP_basic_T, Constant_Value_a), 37, 2, 2, 472, 0 },

  { 237, "ctrl_dp_basic/Thruster control /Thruster 4/Constant1/Value", offsetof
    (P_ctrl_DP_basic_T, Constant1_Value_fh), 37, 2, 2, 474, 0 },

  { 238, "ctrl_dp_basic/Thruster control /Thruster 4/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Delay_InitialCondition_n), 64, 1, 2, 476, 0 },

  { 239,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Delay_InitialCondition_n0), 64, 1, 2, 478, 0 },

  { 240,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Constant1/Value",
    offsetof(P_ctrl_DP_basic_T, Constant1_Value_m), 31, 3, 2, 480, 0 },

  { 241,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Constant2/Value",
    offsetof(P_ctrl_DP_basic_T, Constant2_Value_m), 31, 3, 2, 482, 0 },

  { 242,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_basic_T, DiscreteTransferFcn_InitialSt_l), 64, 1, 2, 484,
    0 },

  { 243,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_DP_basic_T, TSamp_WtEt_mu), 0, 1, 2, 486, 0 },

  { 244,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_DP_basic_T, Accelerationlimiter_RisingLim_c), 0, 1, 2, 488,
    0 },

  { 245,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_DP_basic_T, Accelerationlimiter_FallingLi_o), 0, 1, 2, 490,
    0 },

  { 246,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Accelerationlimiter_IC_j), 64, 1, 2, 492, 0 },

  { 247, "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Memory/X0",
    offsetof(P_ctrl_DP_basic_T, Memory_X0_h), 64, 1, 2, 494, 0 },

  { 248,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Core controller/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_gainv_ay), 0, 1, 2, 496,
    0 },

  { 249,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Core controller/Discrete-Time Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_IC_k), 64, 1, 2, 498, 0 },

  { 250, "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/NaN/Value",
    offsetof(P_ctrl_DP_basic_T, NaN_Value_om), 64, 1, 2, 500, 0 },

  { 251,
    "ctrl_dp_basic/Thruster control /Thruster 4/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_basic_T, DiscreteTransferFcn_InitialS_n4), 64, 1, 2, 502,
    0 },

  { 252, "ctrl_dp_basic/Thruster control /Thruster 5/Constant/Value", offsetof
    (P_ctrl_DP_basic_T, Constant_Value_d), 37, 2, 2, 504, 0 },

  { 253, "ctrl_dp_basic/Thruster control /Thruster 5/Constant1/Value", offsetof
    (P_ctrl_DP_basic_T, Constant1_Value_p), 37, 2, 2, 506, 0 },

  { 254, "ctrl_dp_basic/Thruster control /Thruster 5/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Delay_InitialCondition_a), 64, 1, 2, 508, 0 },

  { 255,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Delay_InitialCondition_fn), 64, 1, 2, 510, 0 },

  { 256,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Constant1/Value",
    offsetof(P_ctrl_DP_basic_T, Constant1_Value_n), 31, 3, 2, 512, 0 },

  { 257,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Constant2/Value",
    offsetof(P_ctrl_DP_basic_T, Constant2_Value_g), 31, 3, 2, 514, 0 },

  { 258,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_basic_T, DiscreteTransferFcn_InitialS_ev), 64, 1, 2, 516,
    0 },

  { 259,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_DP_basic_T, TSamp_WtEt_b), 0, 1, 2, 518, 0 },

  { 260,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_DP_basic_T, Accelerationlimiter_RisingLim_h), 0, 1, 2, 520,
    0 },

  { 261,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_DP_basic_T, Accelerationlimiter_FallingLi_l), 0, 1, 2, 522,
    0 },

  { 262,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Accelerationlimiter_IC_h), 64, 1, 2, 524, 0 },

  { 263, "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Memory/X0",
    offsetof(P_ctrl_DP_basic_T, Memory_X0_p), 64, 1, 2, 526, 0 },

  { 264,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Core controller/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_gainva_j), 0, 1, 2, 528,
    0 },

  { 265,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Core controller/Discrete-Time Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_IC_mk), 64, 1, 2, 530, 0
  },

  { 266, "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/NaN/Value",
    offsetof(P_ctrl_DP_basic_T, NaN_Value_od), 64, 1, 2, 532, 0 },

  { 267,
    "ctrl_dp_basic/Thruster control /Thruster 5/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_basic_T, DiscreteTransferFcn_InitialS_oi), 64, 1, 2, 534,
    0 },

  { 268, "ctrl_dp_basic/Thruster control /Thruster 6/Constant/Value", offsetof
    (P_ctrl_DP_basic_T, Constant_Value_m), 37, 2, 2, 536, 0 },

  { 269, "ctrl_dp_basic/Thruster control /Thruster 6/Constant1/Value", offsetof
    (P_ctrl_DP_basic_T, Constant1_Value_ly), 37, 2, 2, 538, 0 },

  { 270, "ctrl_dp_basic/Thruster control /Thruster 6/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Delay_InitialCondition_e), 64, 1, 2, 540, 0 },

  { 271,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Delay_InitialCondition_g), 64, 1, 2, 542, 0 },

  { 272,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Constant1/Value",
    offsetof(P_ctrl_DP_basic_T, Constant1_Value_li), 31, 3, 2, 544, 0 },

  { 273,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Constant2/Value",
    offsetof(P_ctrl_DP_basic_T, Constant2_Value_d), 31, 3, 2, 546, 0 },

  { 274,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_basic_T, DiscreteTransferFcn_InitialSt_a), 64, 1, 2, 548,
    0 },

  { 275,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_DP_basic_T, TSamp_WtEt_j), 0, 1, 2, 550, 0 },

  { 276,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_DP_basic_T, Accelerationlimiter_RisingLim_k), 0, 1, 2, 552,
    0 },

  { 277,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_DP_basic_T, Accelerationlimiter_FallingLi_b), 0, 1, 2, 554,
    0 },

  { 278,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Accelerationlimiter_IC_m), 64, 1, 2, 556, 0 },

  { 279, "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Memory/X0",
    offsetof(P_ctrl_DP_basic_T, Memory_X0_g), 64, 1, 2, 558, 0 },

  { 280,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Core controller/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_gainv_ll), 0, 1, 2, 560,
    0 },

  { 281,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Core controller/Discrete-Time Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, DiscreteTimeIntegrator_IC_b), 64, 1, 2, 562, 0 },

  { 282, "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/NaN/Value",
    offsetof(P_ctrl_DP_basic_T, NaN_Value_c), 64, 1, 2, 564, 0 },

  { 283,
    "ctrl_dp_basic/Thruster control /Thruster 6/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_basic_T, DiscreteTransferFcn_InitialSt_f), 64, 1, 2, 566,
    0 },

  { 284, "ctrl_dp_basic/Thruster control /Thruster 1/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, Delay_DelayLength), 65, 1, 2, 568, 0 },

  { 285,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, Delay_DelayLength_m), 65, 1, 2, 570, 0 },

  { 286, "ctrl_dp_basic/Thruster control /Thruster 2/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, Delay_DelayLength_l), 65, 1, 2, 572, 0 },

  { 287,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, Delay_DelayLength_b), 65, 1, 2, 574, 0 },

  { 288, "ctrl_dp_basic/Thruster control /Thruster 3/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, Delay_DelayLength_c), 65, 1, 2, 576, 0 },

  { 289,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, Delay_DelayLength_o), 65, 1, 2, 578, 0 },

  { 290, "ctrl_dp_basic/Thruster control /Thruster 4/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, Delay_DelayLength_ch), 65, 1, 2, 580, 0 },

  { 291,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, Delay_DelayLength_cq), 65, 1, 2, 582, 0 },

  { 292, "ctrl_dp_basic/Thruster control /Thruster 5/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, Delay_DelayLength_d), 65, 1, 2, 584, 0 },

  { 293,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, Delay_DelayLength_e), 65, 1, 2, 586, 0 },

  { 294, "ctrl_dp_basic/Thruster control /Thruster 6/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, Delay_DelayLength_k), 65, 1, 2, 588, 0 },

  { 295,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, Delay_DelayLength_i), 65, 1, 2, 590, 0 },

  { 296,
    "ctrl_dp_basic/Thrust allocation1/For Each Subsystem/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_basic_T, CoreSubsys.DiscreteTimeIntegrator_gainval), 0, 1,
    2, 592, 0 },

  { 297,
    "ctrl_dp_basic/Thrust allocation1/For Each Subsystem/Degrees to Radians/Gain1/Gain",
    offsetof(P_ctrl_DP_basic_T, CoreSubsys.Gain1_Gain), 64, 1, 2, 594, 0 },

  { 298,
    "ctrl_dp_basic/Thrust allocation1/For Each Subsystem/Delay/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, CoreSubsys.Delay_InitialCondition), 64, 1, 2,
    596, 0 },

  { 299, "ctrl_dp_basic/Thrust allocation1/For Each Subsystem/Delay/DelayLength",
    offsetof(P_ctrl_DP_basic_T, CoreSubsys.Delay_DelayLength), 65, 1, 2, 598, 0
  },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 300;
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
  1, 1,                                /* Parameter at index 102 */
  1, 1,                                /* Parameter at index 103 */
  1, 1,                                /* Parameter at index 104 */
  1, 6,                                /* Parameter at index 105 */
  1, 6,                                /* Parameter at index 106 */
  1, 6,                                /* Parameter at index 107 */
  1, 6,                                /* Parameter at index 108 */
  1, 6,                                /* Parameter at index 109 */
  1, 6,                                /* Parameter at index 110 */
  1, 1,                                /* Parameter at index 111 */
  1, 1,                                /* Parameter at index 112 */
  1, 1,                                /* Parameter at index 113 */
  1, 1,                                /* Parameter at index 114 */
  1, 1,                                /* Parameter at index 115 */
  1, 1,                                /* Parameter at index 116 */
  1, 1,                                /* Parameter at index 117 */
  1, 1,                                /* Parameter at index 118 */
  1, 1,                                /* Parameter at index 119 */
  1, 1,                                /* Parameter at index 120 */
  1, 1,                                /* Parameter at index 121 */
  1, 1,                                /* Parameter at index 122 */
  1, 1,                                /* Parameter at index 123 */
  1, 1,                                /* Parameter at index 124 */
  1, 1,                                /* Parameter at index 125 */
  1, 1,                                /* Parameter at index 126 */
  1, 1,                                /* Parameter at index 127 */
  1, 1,                                /* Parameter at index 128 */
  1, 1,                                /* Parameter at index 129 */
  1, 1,                                /* Parameter at index 130 */
  1, 1,                                /* Parameter at index 131 */
  1, 1,                                /* Parameter at index 132 */
  1, 1,                                /* Parameter at index 133 */
  1, 1,                                /* Parameter at index 134 */
  1, 1,                                /* Parameter at index 135 */
  1, 1,                                /* Parameter at index 136 */
  1, 1,                                /* Parameter at index 137 */
  1, 1,                                /* Parameter at index 138 */
  1, 1,                                /* Parameter at index 139 */
  1, 1,                                /* Parameter at index 140 */
  1, 1,                                /* Parameter at index 141 */
  1, 1,                                /* Parameter at index 142 */
  1, 1,                                /* Parameter at index 143 */
  1, 1,                                /* Parameter at index 144 */
  1, 1,                                /* Parameter at index 145 */
  1, 1,                                /* Parameter at index 146 */
  1, 1,                                /* Parameter at index 147 */
  1, 1,                                /* Parameter at index 148 */
  1, 1,                                /* Parameter at index 149 */
  1, 1,                                /* Parameter at index 150 */
  1, 1,                                /* Parameter at index 151 */
  3, 1,                                /* Parameter at index 152 */
  1, 1,                                /* Parameter at index 153 */
  1, 1,                                /* Parameter at index 154 */
  1, 6,                                /* Parameter at index 155 */
  1, 6,                                /* Parameter at index 156 */
  1, 6,                                /* Parameter at index 157 */
  1, 1,                                /* Parameter at index 158 */
  1, 1,                                /* Parameter at index 159 */
  1, 1,                                /* Parameter at index 160 */
  1, 1,                                /* Parameter at index 161 */
  1, 1,                                /* Parameter at index 162 */
  1, 1,                                /* Parameter at index 163 */
  1, 1,                                /* Parameter at index 164 */
  1, 1,                                /* Parameter at index 165 */
  1, 1,                                /* Parameter at index 166 */
  1, 1,                                /* Parameter at index 167 */
  1, 1,                                /* Parameter at index 168 */
  1, 1,                                /* Parameter at index 169 */
  1, 1,                                /* Parameter at index 170 */
  1, 1,                                /* Parameter at index 171 */
  1, 1,                                /* Parameter at index 172 */
  1, 1,                                /* Parameter at index 173 */
  1, 1,                                /* Parameter at index 174 */
  1, 1,                                /* Parameter at index 175 */
  1, 1,                                /* Parameter at index 176 */
  1, 1,                                /* Parameter at index 177 */
  1, 1,                                /* Parameter at index 178 */
  3, 1,                                /* Parameter at index 179 */
  3, 3,                                /* Parameter at index 180 */
  1, 1,                                /* Parameter at index 181 */
  1, 1,                                /* Parameter at index 182 */
  1, 1,                                /* Parameter at index 183 */
  1, 1,                                /* Parameter at index 184 */
  1, 1,                                /* Parameter at index 185 */
  1, 1,                                /* Parameter at index 186 */
  1, 1,                                /* Parameter at index 187 */
  1, 2,                                /* Parameter at index 188 */
  1, 2,                                /* Parameter at index 189 */
  1, 1,                                /* Parameter at index 190 */
  1, 1,                                /* Parameter at index 191 */
  1, 3,                                /* Parameter at index 192 */
  1, 3,                                /* Parameter at index 193 */
  1, 1,                                /* Parameter at index 194 */
  1, 1,                                /* Parameter at index 195 */
  1, 1,                                /* Parameter at index 196 */
  1, 1,                                /* Parameter at index 197 */
  1, 1,                                /* Parameter at index 198 */
  1, 1,                                /* Parameter at index 199 */
  1, 1,                                /* Parameter at index 200 */
  1, 1,                                /* Parameter at index 201 */
  1, 1,                                /* Parameter at index 202 */
  1, 1,                                /* Parameter at index 203 */
  1, 2,                                /* Parameter at index 204 */
  1, 2,                                /* Parameter at index 205 */
  1, 1,                                /* Parameter at index 206 */
  1, 1,                                /* Parameter at index 207 */
  1, 3,                                /* Parameter at index 208 */
  1, 3,                                /* Parameter at index 209 */
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
  1, 2,                                /* Parameter at index 220 */
  1, 2,                                /* Parameter at index 221 */
  1, 1,                                /* Parameter at index 222 */
  1, 1,                                /* Parameter at index 223 */
  1, 3,                                /* Parameter at index 224 */
  1, 3,                                /* Parameter at index 225 */
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
  1, 2,                                /* Parameter at index 236 */
  1, 2,                                /* Parameter at index 237 */
  1, 1,                                /* Parameter at index 238 */
  1, 1,                                /* Parameter at index 239 */
  1, 3,                                /* Parameter at index 240 */
  1, 3,                                /* Parameter at index 241 */
  1, 1,                                /* Parameter at index 242 */
  1, 1,                                /* Parameter at index 243 */
  1, 1,                                /* Parameter at index 244 */
  1, 1,                                /* Parameter at index 245 */
  1, 1,                                /* Parameter at index 246 */
  1, 1,                                /* Parameter at index 247 */
  1, 1,                                /* Parameter at index 248 */
  1, 1,                                /* Parameter at index 249 */
  1, 1,                                /* Parameter at index 250 */
  1, 1,                                /* Parameter at index 251 */
  1, 2,                                /* Parameter at index 252 */
  1, 2,                                /* Parameter at index 253 */
  1, 1,                                /* Parameter at index 254 */
  1, 1,                                /* Parameter at index 255 */
  1, 3,                                /* Parameter at index 256 */
  1, 3,                                /* Parameter at index 257 */
  1, 1,                                /* Parameter at index 258 */
  1, 1,                                /* Parameter at index 259 */
  1, 1,                                /* Parameter at index 260 */
  1, 1,                                /* Parameter at index 261 */
  1, 1,                                /* Parameter at index 262 */
  1, 1,                                /* Parameter at index 263 */
  1, 1,                                /* Parameter at index 264 */
  1, 1,                                /* Parameter at index 265 */
  1, 1,                                /* Parameter at index 266 */
  1, 1,                                /* Parameter at index 267 */
  1, 2,                                /* Parameter at index 268 */
  1, 2,                                /* Parameter at index 269 */
  1, 1,                                /* Parameter at index 270 */
  1, 1,                                /* Parameter at index 271 */
  1, 3,                                /* Parameter at index 272 */
  1, 3,                                /* Parameter at index 273 */
  1, 1,                                /* Parameter at index 274 */
  1, 1,                                /* Parameter at index 275 */
  1, 1,                                /* Parameter at index 276 */
  1, 1,                                /* Parameter at index 277 */
  1, 1,                                /* Parameter at index 278 */
  1, 1,                                /* Parameter at index 279 */
  1, 1,                                /* Parameter at index 280 */
  1, 1,                                /* Parameter at index 281 */
  1, 1,                                /* Parameter at index 282 */
  1, 1,                                /* Parameter at index 283 */
  1, 1,                                /* Parameter at index 284 */
  1, 1,                                /* Parameter at index 285 */
  1, 1,                                /* Parameter at index 286 */
  1, 1,                                /* Parameter at index 287 */
  1, 1,                                /* Parameter at index 288 */
  1, 1,                                /* Parameter at index 289 */
  1, 1,                                /* Parameter at index 290 */
  1, 1,                                /* Parameter at index 291 */
  1, 1,                                /* Parameter at index 292 */
  1, 1,                                /* Parameter at index 293 */
  1, 1,                                /* Parameter at index 294 */
  1, 1,                                /* Parameter at index 295 */
  1, 1,                                /* Parameter at index 296 */
  1, 1,                                /* Parameter at index 297 */
  1, 1,                                /* Parameter at index 298 */
  1, 1,                                /* Parameter at index 299 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_dp_basic/Thruster control /Thruster 1/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_DP_basic_T, reset) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 1,
    "ctrl_dp_basic/Thruster control /Thruster 1/Shaft dynamics/Discrete-Time Integrator",
    0, "", offsetof(B_ctrl_DP_basic_T, DiscreteTimeIntegrator) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_dp_basic/Thruster control /Thruster 2/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_DP_basic_T, reset_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 3,
    "ctrl_dp_basic/Thruster control /Thruster 2/Shaft dynamics/Discrete-Time Integrator",
    0, "", offsetof(B_ctrl_DP_basic_T, DiscreteTimeIntegrator_m) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "ctrl_dp_basic/Thruster control /Thruster 3/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_DP_basic_T, reset_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 5,
    "ctrl_dp_basic/Thruster control /Thruster 3/Shaft dynamics/Discrete-Time Integrator",
    0, "", offsetof(B_ctrl_DP_basic_T, DiscreteTimeIntegrator_p) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "ctrl_dp_basic/Thruster control /Thruster 4/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_DP_basic_T, reset_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 7,
    "ctrl_dp_basic/Thruster control /Thruster 4/Shaft dynamics/Discrete-Time Integrator",
    0, "", offsetof(B_ctrl_DP_basic_T, DiscreteTimeIntegrator_j) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "ctrl_dp_basic/Thruster control /Thruster 5/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_DP_basic_T, reset_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 9,
    "ctrl_dp_basic/Thruster control /Thruster 5/Shaft dynamics/Discrete-Time Integrator",
    0, "", offsetof(B_ctrl_DP_basic_T, DiscreteTimeIntegrator_c) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_dp_basic/Thruster control /Thruster 6/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_DP_basic_T, reset_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 11,
    "ctrl_dp_basic/Thruster control /Thruster 6/Shaft dynamics/Discrete-Time Integrator",
    0, "", offsetof(B_ctrl_DP_basic_T, DiscreteTimeIntegrator_d) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_dp_basic/Thruster control /Subsystem/pwm thruster 1", 0, "",
    offsetof(B_ctrl_DP_basic_T, pwmthruster1) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 13, "ctrl_dp_basic/x", 0, "", offsetof(B_ctrl_DP_basic_T, x) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "ctrl_dp_basic/Thruster control /Subsystem/pwm thruster 2", 0, "",
    offsetof(B_ctrl_DP_basic_T, pwmthruster2) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 15, "ctrl_dp_basic/y", 0, "", offsetof(B_ctrl_DP_basic_T, y) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "ctrl_dp_basic/Thruster control /Subsystem/pwm thruster 3", 0, "",
    offsetof(B_ctrl_DP_basic_T, pwmthruster3) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 17, "ctrl_dp_basic/psi", 0, "", offsetof(B_ctrl_DP_basic_T, psi) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "ctrl_dp_basic/Thruster control /Subsystem/pwm thruster 4", 0, "",
    offsetof(B_ctrl_DP_basic_T, pwmthruster4) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 19, "ctrl_dp_basic/Thruster control /Subsystem/pwm thruster 5", 0, "",
    offsetof(B_ctrl_DP_basic_T, pwmthruster5) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 20, "ctrl_dp_basic/Input/Control Gains/K_p_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_p_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 21, "ctrl_dp_basic/Input/Control Gains/K_p_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_p_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 22, "ctrl_dp_basic/Input/Control Gains/K_p_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_p_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 23, "ctrl_dp_basic/Input/Control Gains/K_i_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_i_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 24, "ctrl_dp_basic/Input/Control Gains/K_i_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_i_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 25, "ctrl_dp_basic/Input/Control Gains/K_i_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_i_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 26, "ctrl_dp_basic/Input/Control Gains/K_d_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 27, "ctrl_dp_basic/Input/Control Gains/K_d_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_d_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 28, "ctrl_dp_basic/Input/Control Gains/K_d_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_d_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 29, "ctrl_dp_basic/Input/reset", 0, "", offsetof(B_ctrl_DP_basic_T, reset_g)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 30, "ctrl_dp_basic/Input/Guidance gains/w_d_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, w_d_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 31, "ctrl_dp_basic/Input/Guidance gains/w_d_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, w_d_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 32, "ctrl_dp_basic/Input/Guidance gains/w_d_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, w_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 33, "ctrl_dp_basic/Input/Guidance gains/zeta_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, zeta_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 34, "ctrl_dp_basic/Input/Guidance gains/zeta_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, zeta_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 35, "ctrl_dp_basic/Input/Guidance gains/zeta_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, zeta_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 36, "ctrl_dp_basic/Input/psi_ref", 0, "", offsetof(B_ctrl_DP_basic_T,
    psi_ref) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 37, "ctrl_dp_basic/Input/x_ref", 0, "", offsetof(B_ctrl_DP_basic_T, x_ref) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 38, "ctrl_dp_basic/Input/y_ref", 0, "", offsetof(B_ctrl_DP_basic_T, y_ref) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 39, "ctrl_dp_basic/Guidance/Reference model/Integrator1/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator1) + (0*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 40, "ctrl_dp_basic/Guidance/Reference model/Integrator1/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator1) + (1*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 41, "ctrl_dp_basic/Guidance/Reference model/Integrator1/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator1) + (2*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 42, "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Sum", 0,
    "", offsetof(B_ctrl_DP_basic_T, Sum) + (0*sizeof(real_T)), BLOCKIO_SIG, 64,
    1, 2, 0, 0 },

  { 43, "ctrl_dp_basic/Control/DP Controller/Sum2", 0, "regulation error(1, 1)",
    offsetof(B_ctrl_DP_basic_T, regulationerror) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 44, "ctrl_dp_basic/Control/DP Controller/Sum2", 0, "regulation error(2, 1)",
    offsetof(B_ctrl_DP_basic_T, regulationerror) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 45, "ctrl_dp_basic/Control/DP Controller/Sum2", 0, "regulation error(3, 1)",
    offsetof(B_ctrl_DP_basic_T, regulationerror) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 46, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator1/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator1_g) + (0*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 47, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator1/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator1_g) + (1*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 48, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator1/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator1_g) + (2*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 49, "ctrl_dp_basic/Guidance/Reference model/Integrator3/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator3) + (0*sizeof(real_T)), BLOCKIO_SIG,
    21, 1, 2, 0, 0 },

  { 50, "ctrl_dp_basic/Guidance/Reference model/Integrator3/(2, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator3) + (1*sizeof(real_T)), BLOCKIO_SIG,
    21, 1, 2, 0, 0 },

  { 51, "ctrl_dp_basic/Guidance/Reference model/Integrator3/(3, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator3) + (2*sizeof(real_T)), BLOCKIO_SIG,
    21, 1, 2, 0, 0 },

  { 52, "ctrl_dp_basic/Control/DP Controller/Sum4/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum4) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 53, "ctrl_dp_basic/Control/DP Controller/Sum4/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum4) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 54, "ctrl_dp_basic/Control/DP Controller/Sum4/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum4) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 55, "ctrl_dp_basic/Control/DP Controller/Sum3/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum3) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 56, "ctrl_dp_basic/Control/DP Controller/Sum3/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum3) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 57, "ctrl_dp_basic/Control/DP Controller/Sum3/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum3) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 58, "ctrl_dp_basic/Thruster measurment/thr_angle_2", 0, "", offsetof
    (B_ctrl_DP_basic_T, thr_angle_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 59, "ctrl_dp_basic/Thruster measurment/thr_angle_3", 0, "", offsetof
    (B_ctrl_DP_basic_T, thr_angle_3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 60, "ctrl_dp_basic/Thruster measurment/thr_angle_4", 0, "", offsetof
    (B_ctrl_DP_basic_T, thr_angle_4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 61, "ctrl_dp_basic/Thruster measurment/thr_angle_5", 0, "", offsetof
    (B_ctrl_DP_basic_T, thr_angle_5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 62, "ctrl_dp_basic/Thruster measurment/thr_angle_6", 0, "", offsetof
    (B_ctrl_DP_basic_T, thr_angle_6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 63, "ctrl_dp_basic/Thruster measurment/thr_angle_1", 0, "", offsetof
    (B_ctrl_DP_basic_T, thr_angle_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 64,
    "ctrl_dp_basic/Thrust allocation1/Choosing Fixed // Azimuth angle/(1, 1)", 0,
    "", offsetof(B_ctrl_DP_basic_T, ChoosingFixedAzimuthangle) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 65,
    "ctrl_dp_basic/Thrust allocation1/Choosing Fixed // Azimuth angle/(1, 2)", 0,
    "", offsetof(B_ctrl_DP_basic_T, ChoosingFixedAzimuthangle) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 66,
    "ctrl_dp_basic/Thrust allocation1/Choosing Fixed // Azimuth angle/(1, 3)", 0,
    "", offsetof(B_ctrl_DP_basic_T, ChoosingFixedAzimuthangle) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 67,
    "ctrl_dp_basic/Thrust allocation1/Choosing Fixed // Azimuth angle/(1, 4)", 0,
    "", offsetof(B_ctrl_DP_basic_T, ChoosingFixedAzimuthangle) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 68,
    "ctrl_dp_basic/Thrust allocation1/Choosing Fixed // Azimuth angle/(1, 5)", 0,
    "", offsetof(B_ctrl_DP_basic_T, ChoosingFixedAzimuthangle) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 69,
    "ctrl_dp_basic/Thrust allocation1/Choosing Fixed // Azimuth angle/(1, 6)", 0,
    "", offsetof(B_ctrl_DP_basic_T, ChoosingFixedAzimuthangle) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 70, "ctrl_dp_basic/Thrust allocation1/reset/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_basic_T, reset_a3) + (0*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0,
    0 },

  { 71, "ctrl_dp_basic/Thrust allocation1/reset/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_basic_T, reset_a3) + (1*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0,
    0 },

  { 72, "ctrl_dp_basic/Thrust allocation1/reset/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_basic_T, reset_a3) + (2*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0,
    0 },

  { 73, "ctrl_dp_basic/Thrust allocation1/reset/(1, 4)", 0, "", offsetof
    (B_ctrl_DP_basic_T, reset_a3) + (3*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0,
    0 },

  { 74, "ctrl_dp_basic/Thrust allocation1/reset/(1, 5)", 0, "", offsetof
    (B_ctrl_DP_basic_T, reset_a3) + (4*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0,
    0 },

  { 75, "ctrl_dp_basic/Thrust allocation1/reset/(1, 6)", 0, "", offsetof
    (B_ctrl_DP_basic_T, reset_a3) + (5*sizeof(real_T)), BLOCKIO_SIG, 26, 1, 2, 0,
    0 },

  { 76, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 1", 0, "",
    offsetof(B_ctrl_DP_basic_T, Saturation1) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 77, "ctrl_dp_basic/Thruster control /Subsystem/pwm thruster 6", 0, "",
    offsetof(B_ctrl_DP_basic_T, pwmthruster6) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 78, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 2", 0, "",
    offsetof(B_ctrl_DP_basic_T, Saturation2) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 79, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 3", 0, "",
    offsetof(B_ctrl_DP_basic_T, Saturation3) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 80, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 4", 0, "",
    offsetof(B_ctrl_DP_basic_T, Saturation4) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 81, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 5", 0, "",
    offsetof(B_ctrl_DP_basic_T, Saturation5) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 82, "ctrl_dp_basic/Thruster control /Subsystem1/Saturation 6", 0, "",
    offsetof(B_ctrl_DP_basic_T, Saturation6) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 83, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 7/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Saturation7) + (0*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 84, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 7/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Saturation7) + (1*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 85, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 7/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Saturation7) + (2*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 86, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 7/(1, 4)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Saturation7) + (3*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 87, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 7/(1, 5)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Saturation7) + (4*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 88, "ctrl_dp_basic/Thruster control /Subsystem/Saturation 7/(1, 6)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Saturation7) + (5*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 89, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator) + (0*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 90, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator) + (1*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 91, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator) + (2*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 92, "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Sum",
    0, "", offsetof(B_ctrl_DP_basic_T, Sum_f) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 93, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator2/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator2) + (0*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 94, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator2/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator2) + (1*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 95, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator2/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator2) + (2*sizeof(real_T)), BLOCKIO_SIG,
    22, 1, 2, 0, 0 },

  { 96, "ctrl_dp_basic/Nonlinear Passisve Observer/M^-1/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_basic_T, M1) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 97, "ctrl_dp_basic/Nonlinear Passisve Observer/M^-1/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_basic_T, M1) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 98, "ctrl_dp_basic/Nonlinear Passisve Observer/M^-1/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_basic_T, M1) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 99, "ctrl_dp_basic/Guidance/Reference model/Matrix Multiply/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, MatrixMultiply) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 100, "ctrl_dp_basic/Guidance/Reference model/Matrix Multiply/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, MatrixMultiply) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 101, "ctrl_dp_basic/Guidance/Reference model/Matrix Multiply/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, MatrixMultiply) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 102, "ctrl_dp_basic/Guidance/Reference model/Sum5", 0, "(1, 1)", offsetof
    (B_ctrl_DP_basic_T, Sum5) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 103, "ctrl_dp_basic/Guidance/Reference model/Sum5", 0, "(2, 1)", offsetof
    (B_ctrl_DP_basic_T, Sum5) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 104, "ctrl_dp_basic/Guidance/Reference model/Sum5", 0, "(3, 1)", offsetof
    (B_ctrl_DP_basic_T, Sum5) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 105, "ctrl_dp_basic/Nonlinear Passisve Observer/Matrix Multiply1/(1, 1)", 0,
    "", offsetof(B_ctrl_DP_basic_T, MatrixMultiply1) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 106, "ctrl_dp_basic/Nonlinear Passisve Observer/Matrix Multiply1/(1, 2)", 0,
    "", offsetof(B_ctrl_DP_basic_T, MatrixMultiply1) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 107, "ctrl_dp_basic/Nonlinear Passisve Observer/Matrix Multiply1/(1, 3)", 0,
    "", offsetof(B_ctrl_DP_basic_T, MatrixMultiply1) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 108, "ctrl_dp_basic/Nonlinear Passisve Observer/Sum1/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1,
    2, 0, 0 },

  { 109, "ctrl_dp_basic/Nonlinear Passisve Observer/Sum1/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Sum1) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1,
    2, 0, 0 },

  { 110, "ctrl_dp_basic/Nonlinear Passisve Observer/Sum1/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Sum1) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1,
    2, 0, 0 },

  { 111, "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Delay", 0,
    "", offsetof(B_ctrl_DP_basic_T, Delay) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 112,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_DP_basic_T, DiscreteTransferFcn) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 113,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_DP_basic_T, TSamp) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 114,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_DP_basic_T, Inertiacompensation) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 115, "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Sum1", 0,
    "", offsetof(B_ctrl_DP_basic_T, Sum1_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 116, "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Memory", 0,
    "", offsetof(B_ctrl_DP_basic_T, Memory) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 117,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_DP_basic_T, reset_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 118,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Core controller/Sum1",
    0, "", offsetof(B_ctrl_DP_basic_T, Sum1_m) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 119,
    "ctrl_dp_basic/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_DP_basic_T, Findingrotationspeed) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 120,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_DP_basic_T, Ki) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 121, "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Delay", 0,
    "", offsetof(B_ctrl_DP_basic_T, Delay_o) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 122,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_DP_basic_T, DiscreteTransferFcn_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 123,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_DP_basic_T, TSamp_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 124,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_DP_basic_T, Inertiacompensation_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 125, "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Sum1", 0,
    "", offsetof(B_ctrl_DP_basic_T, Sum1_mw) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 126, "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Memory", 0,
    "", offsetof(B_ctrl_DP_basic_T, Memory_c) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 127,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_DP_basic_T, reset_ig) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 128,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Core controller/Sum1",
    0, "", offsetof(B_ctrl_DP_basic_T, Sum1_g) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 129,
    "ctrl_dp_basic/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_DP_basic_T, Findingrotationspeed_i) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 130,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_DP_basic_T, Ki_j) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 131, "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Delay", 0,
    "", offsetof(B_ctrl_DP_basic_T, Delay_oq) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 132,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_DP_basic_T, DiscreteTransferFcn_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 133,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_DP_basic_T, TSamp_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 134,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_DP_basic_T, Inertiacompensation_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 135, "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Sum1", 0,
    "", offsetof(B_ctrl_DP_basic_T, Sum1_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 136, "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Memory", 0,
    "", offsetof(B_ctrl_DP_basic_T, Memory_m) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 137,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_DP_basic_T, reset_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 138,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Core controller/Sum1",
    0, "", offsetof(B_ctrl_DP_basic_T, Sum1_n) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 139,
    "ctrl_dp_basic/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_DP_basic_T, Findingrotationspeed_n) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 140,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_DP_basic_T, Ki_o) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 141, "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Delay", 0,
    "", offsetof(B_ctrl_DP_basic_T, Delay_a) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 142,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_DP_basic_T, DiscreteTransferFcn_h) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 143,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_DP_basic_T, TSamp_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 144,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_DP_basic_T, Inertiacompensation_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 145, "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Sum1", 0,
    "", offsetof(B_ctrl_DP_basic_T, Sum1_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 146, "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Memory", 0,
    "", offsetof(B_ctrl_DP_basic_T, Memory_j) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 147,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_DP_basic_T, reset_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 148,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Core controller/Sum1",
    0, "", offsetof(B_ctrl_DP_basic_T, Sum1_b) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 149,
    "ctrl_dp_basic/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_DP_basic_T, Findingrotationspeed_nl) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 150,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_DP_basic_T, Ki_c) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 151, "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Delay", 0,
    "", offsetof(B_ctrl_DP_basic_T, Delay_i) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 152,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_DP_basic_T, DiscreteTransferFcn_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 153,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_DP_basic_T, TSamp_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 154,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_DP_basic_T, Inertiacompensation_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 155, "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Sum1", 0,
    "", offsetof(B_ctrl_DP_basic_T, Sum1_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 156, "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Memory", 0,
    "", offsetof(B_ctrl_DP_basic_T, Memory_i) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 157,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_DP_basic_T, reset_n5) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 158,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Core controller/Sum1",
    0, "", offsetof(B_ctrl_DP_basic_T, Sum1_hb) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 159,
    "ctrl_dp_basic/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_DP_basic_T, Findingrotationspeed_b) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 160,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_DP_basic_T, Ki_b) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 161, "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Delay", 0,
    "", offsetof(B_ctrl_DP_basic_T, Delay_od) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 162,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_DP_basic_T, DiscreteTransferFcn_jz) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 163,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_DP_basic_T, TSamp_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 164,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_DP_basic_T, Inertiacompensation_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 165, "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Sum1", 0,
    "", offsetof(B_ctrl_DP_basic_T, Sum1_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 166, "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Memory", 0,
    "", offsetof(B_ctrl_DP_basic_T, Memory_b) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 167,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_DP_basic_T, reset_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 168,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Core controller/Sum1",
    0, "", offsetof(B_ctrl_DP_basic_T, Sum1_d) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 169,
    "ctrl_dp_basic/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_DP_basic_T, Findingrotationspeed_l) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 170,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_DP_basic_T, Ki_cv) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 171,
    "ctrl_dp_basic/Guidance output/Transposed rotation  matrix in yaw2/Row3", 0,
    "", offsetof(B_ctrl_DP_basic_T, Row3) + (0*sizeof(real_T)), BLOCKIO_SIG, 64,
    1, 2, 0, 0 },

  { 172,
    "ctrl_dp_basic/Guidance output/Transposed rotation  matrix in yaw2/Row1", 0,
    "", offsetof(B_ctrl_DP_basic_T, Row1) + (0*sizeof(real_T)), BLOCKIO_SIG, 64,
    1, 2, 0, 0 },

  { 173,
    "ctrl_dp_basic/Guidance output/Transposed rotation  matrix in yaw2/Row2", 0,
    "", offsetof(B_ctrl_DP_basic_T, Row2) + (0*sizeof(real_T)), BLOCKIO_SIG, 64,
    1, 2, 0, 0 },

  { 174,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_DP_basic_T, n_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 175,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Torque limit",
    0, "", offsetof(B_ctrl_DP_basic_T, Q_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 176,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_DP_basic_T, n_d_l) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 177,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Torque limit",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_Torquelimit_f.Q_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 178,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_DP_basic_T, sf_Supervisor_a.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 179,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePower_ol.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 180,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePower_ol.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 181,
    "ctrl_dp_basic/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePower_ol.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 182,
    "ctrl_dp_basic/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_ActualForceandTorque_a.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 183,
    "ctrl_dp_basic/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_ActualForceandTorque_a.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 184,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Torque limit",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_Torquelimit_c.Q_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 185,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_DP_basic_T, sf_Supervisor_n.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 186,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_c.n_d) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 187,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/MATLAB Function",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_c.T_r) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 188,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePower_c1.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 189,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePower_c1.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 190,
    "ctrl_dp_basic/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePower_c1.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 191,
    "ctrl_dp_basic/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_ActualForceandTorque_fi.Ta) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 192,
    "ctrl_dp_basic/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_ActualForceandTorque_fi.Qa) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 193,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Torque limit",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_Torquelimit_g.Q_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 194,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_DP_basic_T, sf_Supervisor_cp.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 195,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_j.n_d) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 196,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/MATLAB Function",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_j.T_r) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 197,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePowera_o.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 198,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePowera_o.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 199,
    "ctrl_dp_basic/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePowera_o.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 200,
    "ctrl_dp_basic/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_ActualForceandTorque_f.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 201,
    "ctrl_dp_basic/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_ActualForceandTorque_f.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 202,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Torque limit",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_Torquelimit_e.Q_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 203,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_DP_basic_T, sf_Supervisor_c.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 204,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_n.n_d) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 205,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/MATLAB Function",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_n.T_r) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 206,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePowera_c.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 207,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePowera_c.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 208,
    "ctrl_dp_basic/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePowera_c.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 209,
    "ctrl_dp_basic/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_ActualForceandTorque_c.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 210,
    "ctrl_dp_basic/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_ActualForceandTorque_c.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 211,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Torque limit",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_Torquelimit_a.Q_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 212,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_DP_basic_T, sf_Supervisor_l.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 213,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_d.n_d) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 214,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/MATLAB Function",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_d.T_r) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 215,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePowera_a.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 216,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePowera_a.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 217,
    "ctrl_dp_basic/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePowera_a.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 218,
    "ctrl_dp_basic/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_ActualForceandTorque_o.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 219,
    "ctrl_dp_basic/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_ActualForceandTorque_o.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 220,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_DP_basic_T, sf_Supervisor.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 221,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePowerand.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 222,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePowerand.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 223,
    "ctrl_dp_basic/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_DP_basic_T, sf_CorecontrollerTorquePowerand.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 224,
    "ctrl_dp_basic/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_DP_basic_T, sf_ActualForceandTorque.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 225,
    "ctrl_dp_basic/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_DP_basic_T, sf_ActualForceandTorque.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 226,
    "ctrl_dp_basic/Thrust allocation1/For Each Subsystem/Discrete-Time Integrator",
    0, "angle", offsetof(B_ctrl_DP_basic_T, CoreSubsys[5].angle) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 227, "ctrl_dp_basic/Thrust allocation1/For Each Subsystem/Delay", 0, "",
    offsetof(B_ctrl_DP_basic_T, CoreSubsys[5].Delay) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 228, "ctrl_dp_basic/Thrust allocation1/For Each Subsystem/Max Rotation Rate",
    0, "", offsetof(B_ctrl_DP_basic_T, CoreSubsys[5].MaxRotationRate) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 229, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(1, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 230, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(2, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 231, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(3, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 232, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(1, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 233, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(2, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 234, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(3, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 235, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(1, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 236, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(2, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 237, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(3, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 238, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(1, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 239, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(2, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 240, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(3, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 241, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(1, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 242, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(2, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 243, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(3, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 244, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(1, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 245, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(2, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 246, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(3, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 247, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(1, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 248, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(2, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 249, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(3, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 250, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(1, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 251, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(2, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 252, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(3, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 253, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(1, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 254, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(2, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 255, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(3, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 256, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(1, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 257, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(2, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 258, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(3, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 259, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(1, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 260, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(2, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 261, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(3, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 262, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(1, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 263, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(2, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 264, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(3, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 265, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(1, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 266, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(2, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 267, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(3, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 268, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(1, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 269, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(2, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 270, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(3, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 271, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(1, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 272, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(2, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 273, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(3, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 274, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(1, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_g.K_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 275, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(2, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_g.K_p) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 276, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(3, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_g.K_p) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 277, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(1, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_g.K_p) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 278, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(2, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_g.K_p) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 279, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(3, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_g.K_p) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 280, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(1, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_g.K_p) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 281, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(2, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_g.K_p) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 282, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(3, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_g.K_p) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 283;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 87;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Thruster control /Thruster 1/Shaft dynamics/reset", 1, EXT_IN, 1, 1, 1 },

  { 2, "Thruster control /Thruster 2/Shaft dynamics/reset", 1, EXT_IN, 1, 1, 1 },

  { 3, "Thruster control /Thruster 3/Shaft dynamics/reset", 1, EXT_IN, 1, 1, 1 },

  { 4, "Thruster control /Thruster 4/Shaft dynamics/reset", 1, EXT_IN, 1, 1, 1 },

  { 5, "Thruster control /Thruster 5/Shaft dynamics/reset", 1, EXT_IN, 1, 1, 1 },

  { 6, "Thruster control /Thruster 6/Shaft dynamics/reset", 1, EXT_IN, 1, 1, 1 },

  { 7, "x", 0, EXT_IN, 1, 1, 1 },

  { 8, "y", 0, EXT_IN, 1, 1, 1 },

  { 9, "psi", 0, EXT_IN, 1, 1, 1 },

  { 10, "Input/Control Gains/K_p_x", 0, EXT_IN, 1, 1, 1 },

  { 11, "Input/Control Gains/K_p_y", 0, EXT_IN, 1, 1, 1 },

  { 12, "Input/Control Gains/K_p_psi", 0, EXT_IN, 1, 1, 1 },

  { 13, "Input/Control Gains/K_i_psi", 0, EXT_IN, 1, 1, 1 },

  { 14, "Input/Control Gains/K_i_x", 0, EXT_IN, 1, 1, 1 },

  { 15, "Input/Control Gains/K_i_y", 0, EXT_IN, 1, 1, 1 },

  { 16, "Input/Control Gains/K_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 17, "Input/Control Gains/K_d_x", 0, EXT_IN, 1, 1, 1 },

  { 18, "Input/Control Gains/K_d_y", 0, EXT_IN, 1, 1, 1 },

  { 19, "Input/reset", 0, EXT_IN, 1, 1, 1 },

  { 20, "Input/Guidance gains/w_d_x", 0, EXT_IN, 1, 1, 1 },

  { 21, "Input/Guidance gains/w_d_y", 0, EXT_IN, 1, 1, 1 },

  { 22, "Input/Guidance gains/w_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 23, "Input/Guidance gains/zeta_psi", 0, EXT_IN, 1, 1, 1 },

  { 24, "Input/Guidance gains/zeta_x", 0, EXT_IN, 1, 1, 1 },

  { 25, "Input/Guidance gains/zeta_y", 0, EXT_IN, 1, 1, 1 },

  { 26, "Input/psi_ref", 0, EXT_IN, 1, 1, 1 },

  { 27, "Input/x_ref", 0, EXT_IN, 1, 1, 1 },

  { 28, "Input/y_ref", 0, EXT_IN, 1, 1, 1 },

  { 29, "Thruster measurment/thr_angle_2", 0, EXT_IN, 1, 1, 1 },

  { 30, "Thruster measurment/thr_angle_3", 0, EXT_IN, 1, 1, 1 },

  { 31, "Thruster measurment/thr_angle_4", 0, EXT_IN, 1, 1, 1 },

  { 32, "Thruster measurment/thr_angle_5", 0, EXT_IN, 1, 1, 1 },

  { 33, "Thruster measurment/thr_angle_6", 0, EXT_IN, 1, 1, 1 },

  { 34, "Thruster measurment/thr_angle_1", 0, EXT_IN, 1, 1, 1 },

  { 35, "Thrust allocation1/reset", 1, EXT_IN, 6, 6, 1 },

  { 36, "Thruster control /Thruster 1/Thruster control/Core controller/reset", 1,
    EXT_IN, 1, 1, 1 },

  { 37, "Thruster control /Thruster 2/Thruster control/Core controller/reset", 1,
    EXT_IN, 1, 1, 1 },

  { 38, "Thruster control /Thruster 3/Thruster control/Core controller/reset", 1,
    EXT_IN, 1, 1, 1 },

  { 39, "Thruster control /Thruster 4/Thruster control/Core controller/reset", 1,
    EXT_IN, 1, 1, 1 },

  { 40, "Thruster control /Thruster 5/Thruster control/Core controller/reset", 1,
    EXT_IN, 1, 1, 1 },

  { 41, "Thruster control /Thruster 6/Thruster control/Core controller/reset", 1,
    EXT_IN, 1, 1, 1 },

  { 1, "pwm_1", 1, EXT_OUT, 1, 1, 1 },

  { 2, "pwm_2", 1, EXT_OUT, 1, 1, 1 },

  { 3, "pwm_3", 1, EXT_OUT, 1, 1, 1 },

  { 4, "pwm_4", 1, EXT_OUT, 1, 1, 1 },

  { 5, "pwm_5", 1, EXT_OUT, 1, 1, 1 },

  { 6, "alpha_1", 1, EXT_OUT, 1, 1, 1 },

  { 7, "pwm_6", 1, EXT_OUT, 1, 1, 1 },

  { 8, "alpha_2", 1, EXT_OUT, 1, 1, 1 },

  { 9, "alpha_3", 1, EXT_OUT, 1, 1, 1 },

  { 10, "alpha_4", 1, EXT_OUT, 1, 1, 1 },

  { 11, "alpha_5", 1, EXT_OUT, 1, 1, 1 },

  { 12, "alpha_6", 1, EXT_OUT, 1, 1, 1 },

  { 13, "u_4", 1, EXT_OUT, 1, 1, 1 },

  { 14, "u_5", 1, EXT_OUT, 1, 1, 1 },

  { 15, "u_6", 1, EXT_OUT, 1, 1, 1 },

  { 16, "u_1", 1, EXT_OUT, 1, 1, 1 },

  { 17, "u_2", 1, EXT_OUT, 1, 1, 1 },

  { 18, "Observer output /eta_hat output/x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 19, "Observer output /eta_hat output/y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 20, "Observer output /eta_hat output/psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 21, "Observer output /nu_hat output/u_hat", 0, EXT_OUT, 1, 1, 1 },

  { 22, "Observer output /nu_hat output/v_hat", 0, EXT_OUT, 1, 1, 1 },

  { 23, "Observer output /nu_hat output/r_hat", 0, EXT_OUT, 1, 1, 1 },

  { 24, "Observer output /nu_dot_hat output/u_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 25, "Observer output /nu_dot_hat output/v_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 26, "Observer output /nu_dot_hat output/r_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 27, "Observer output /b_hat output/b_x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 28, "Observer output /b_hat output/b_y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 29, "Observer output /b_hat output/b_psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 30, "u_3", 1, EXT_OUT, 1, 1, 1 },

  { 31, "Guidance/eta_des", 0, EXT_OUT, 3, 3, 1 },

  { 32, "Control output/tau_N", 0, EXT_OUT, 1, 1, 1 },

  { 33, "Control output/tau_X", 0, EXT_OUT, 1, 1, 1 },

  { 34, "Control output/tau_Y", 0, EXT_OUT, 1, 1, 1 },

  { 35, "Control output/psi_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 36, "Control output/x_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 37, "Control output/y_tidle", 0, EXT_OUT, 1, 1, 1 },

  { 38, "Control output/r_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 39, "Control output/u_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 40, "Control output/v_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 41, "Guidance output/x_d", 0, EXT_OUT, 1, 1, 1 },

  { 42, "Guidance output/y_d", 0, EXT_OUT, 1, 1, 1 },

  { 43, "Guidance output/psi_d", 0, EXT_OUT, 1, 1, 1 },

  { 44, "Guidance output/r_d", 0, EXT_OUT, 1, 1, 1 },

  { 45, "Guidance output/u_d", 0, EXT_OUT, 1, 1, 1 },

  { 46, "Guidance output/v_d", 0, EXT_OUT, 1, 1, 1 },

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
  "ctrl_DP_basic";
static const char* NI_CompiledModelVersion = "1.63";
static const char* NI_CompiledModelDateTime = "Tue May 10 14:07:05 2016";
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
  memcpy(&rtParameter[0], &ctrl_DP_basic_P, sizeof(P_ctrl_DP_basic_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_DP_basic_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_DP_basic_T));
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
             (P_ctrl_DP_basic_T));
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
               (P_ctrl_DP_basic_T));
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
             (P_ctrl_DP_basic_T));
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
           (P_ctrl_DP_basic_T));
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
           (P_ctrl_DP_basic_T));
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
      *numContStates = 21;
      *numDiscStates = 1422.0;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator1_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator1_CSTATE), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator1_CSTATE), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator_CSTATE), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator_CSTATE), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator1_CSTATE_g), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator1_CSTATE_g), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator1_CSTATE_g), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator3_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator3_CSTATE), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator3_CSTATE), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator_CSTATE_l), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator_CSTATE_l), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator_CSTATE_l), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator2_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator2_CSTATE), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator2_CSTATE), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator2_CSTATE_e), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator2_CSTATE_e), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_DP_basic_X.Integrator2_CSTATE_e), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_e");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_h, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_g, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hl, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hl");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.Delay_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_j,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.Delay_DSTATE_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.UD_DSTATE, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.UD_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_b, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_b");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_l,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.Delay_DSTATE_l");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_e,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.Delay_DSTATE_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_j, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_j, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.UD_DSTATE_j, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.UD_DSTATE_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_e, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_p,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.Delay_DSTATE_p");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_f,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.Delay_DSTATE_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_c, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_c, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.UD_DSTATE_g, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.UD_DSTATE_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_l, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_i, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_i");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_d,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.Delay_DSTATE_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_ev,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.Delay_DSTATE_ev");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_m, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_m, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_m");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.UD_DSTATE_o, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.UD_DSTATE_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hx, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hx");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_ms, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_ms");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_du,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.Delay_DSTATE_du");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_n,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.Delay_DSTATE_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_f, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_f, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_f");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.UD_DSTATE_n, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.UD_DSTATE_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_ix, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_ix");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_k,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.Delay_DSTATE_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_o,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.Delay_DSTATE_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_k, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_k");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_k, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.UD_DSTATE_d, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.UD_DSTATE_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_gt, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_gt");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_states_l, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_states_l");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_c,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_j,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_m,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_m");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_a,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_a");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_b,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_b");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.pwm_1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.pwm_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.pwm_2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.pwm_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.pwm_3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.pwm_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.pwm_4_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.pwm_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.pwm_5_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.pwm_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_k,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.zeta_psi_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.zeta_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.zeta_x_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.zeta_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.zeta_y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.zeta_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_ref_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_ref_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_ref_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.thr_angle_2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.thr_angle_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.thr_angle_3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.thr_angle_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.thr_angle_4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.thr_angle_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.thr_angle_5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.thr_angle_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.thr_angle_6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.thr_angle_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.thr_angle_1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.thr_angle_1_DWORK1");
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_e,
        count, 26, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_e");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.pwm_6_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.pwm_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_3_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_4_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_5_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_6_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_hat_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_dot_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_dot_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_dot_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.b_x_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.b_x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.b_y_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.b_y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.b_psi_hat_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.b_psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.eta_des_DWORK1,
      0, 22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.eta_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.eta_des_DWORK1,
      1, 22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.eta_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.eta_des_DWORK1,
      2, 22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.eta_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.PrevY, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.PrevY");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.Memory_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_o,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_m, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.PrevY_e, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.PrevY_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.Memory_PreviousInput_e, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.Memory_PreviousInput_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_js,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_js");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_ku, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_ku");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_k4, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_k4");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.PrevY_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.PrevY_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.Memory_PreviousInput_i, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.Memory_PreviousInput_i");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_h,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_i, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_o");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.PrevY_l, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.PrevY_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.Memory_PreviousInput_l, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.Memory_PreviousInput_l");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_eg,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_eg");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_b, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_b");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_a");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.PrevY_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.PrevY_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.Memory_PreviousInput_m, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.Memory_PreviousInput_m");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_n,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_aj, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_aj");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.PrevY_ca, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.PrevY_ca");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.Memory_PreviousInput_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.Memory_PreviousInput_p");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_g,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_N_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_N_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_X_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_Y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_Y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_tilde_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_tilde_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_tidle_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_tidle_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_tilde_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_tilde_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_tilde_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_d_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_d_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_d_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRese, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRese");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_p, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_n, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_b, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_b");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_e, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_m, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevR_em, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevR_em");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_o, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_k, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_k");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_g, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_f, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_c, 0, 2, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_c");
    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_k,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2_k");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_b,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2_b");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_o,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2_o");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_j,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2_j");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.reset_DWORK2_j5, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.reset_DWORK2_j5");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.pwm_1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.pwm_1_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.pwm_2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.pwm_2_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.pwm_3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.pwm_3_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.pwm_4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.pwm_4_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.pwm_5_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.pwm_5_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_x_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_y_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_psi_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_psi_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_x_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_y_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_psi_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_x_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_y_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_f,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2_f");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_x_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_y_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_psi_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.zeta_psi_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.zeta_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.zeta_x_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.zeta_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.zeta_y_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.zeta_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_ref_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_ref_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_ref_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_ref_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_ref_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_ref_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.thr_angle_2_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.thr_angle_2_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.thr_angle_3_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.thr_angle_3_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.thr_angle_4_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.thr_angle_4_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.thr_angle_5_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.thr_angle_5_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.thr_angle_6_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.thr_angle_6_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.thr_angle_1_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.thr_angle_1_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_d,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2_d");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.pwm_6_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.pwm_6_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_5_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_6_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_4_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_4_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_5_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_5_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_6_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_6_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_1_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_1_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_2_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_2_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.u_dot_hat_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.u_dot_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.v_dot_hat_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.v_dot_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.r_dot_hat_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.r_dot_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.b_x_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.b_x_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.b_y_hat_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.b_y_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.b_psi_hat_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.b_psi_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_3_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_3_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.eta_des_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.eta_des_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_p,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2_p");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.reset_DWORK2_dw, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.reset_DWORK2_dw");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_h,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2_h");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_a,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2_a");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_e,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2_e");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.reset_DWORK2_aw, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.reset_DWORK2_aw");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_N_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_N_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_X_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_X_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_Y_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_Y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.psi_tilde_DWORK2, count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.psi_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_tilde_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_tidle_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_tidle_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_tilde_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_tilde_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_tilde_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_d_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_d_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_d_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_d_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_d_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_d_DWORK2,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_d_DWORK2");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.CoreSubsys[ForEach_itr1].
         DiscreteTimeIntegrator_DSTATE, 0, 0, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_DSTATE");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.CoreSubsys[ForEach_itr1].Delay_DSTATE, 0, 0, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.CoreSubsys[ForEach_itr1].Delay_DSTATE");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.CoreSubsys[ForEach_itr1].
         DiscreteTimeIntegrator_PrevRese, 0, 2, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_PrevRese");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.CoreSubsys[ForEach_itr1].
         DiscreteTimeIntegrator_IC_LOADI, 0, 3, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_IC_LOADI");
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
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator1_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator1_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator1_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator1_CSTATE_g), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator1_CSTATE_g), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator1_CSTATE_g), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator3_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator3_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator3_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator_CSTATE_l), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator_CSTATE_l), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator_CSTATE_l), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator2_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator2_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator2_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator2_CSTATE_e), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator2_CSTATE_e), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_basic_X.Integrator2_CSTATE_e), 2,
      contStates[idx++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_h, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_g, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_f, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hl, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_j, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.UD_DSTATE, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_fu, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_b, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_l, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_e, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_j, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_j, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.UD_DSTATE_j, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_e, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_p, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_f, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_c, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_c, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.UD_DSTATE_g, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_l, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_i, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_d, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_ev, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_m, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_m, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.UD_DSTATE_o, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_hx, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_ms, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_du, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_n, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_f, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_f, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.UD_DSTATE_n, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTATE_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_ix, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_k, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Delay_DSTATE_o, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_k, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_k, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.UD_DSTATE_d, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_DSTAT_gt, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_states_l, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_c, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_j, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_m, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_a, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_b, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.pwm_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.pwm_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.pwm_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.pwm_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.pwm_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_psi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_psi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_psi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_k, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_psi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_psi_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_x_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_ref_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_ref_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_ref_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_3_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_4_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_5_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_6_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_1_DWORK1, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_e, count,
        discStates[idx++], 26, 0);
    }

    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.pwm_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_3_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_4_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_5_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_6_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_dot_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_dot_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_dot_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_x_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_y_hat_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_psi_hat_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.eta_des_DWORK1, 0, discStates[idx
      ++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.eta_des_DWORK1, 1, discStates[idx
      ++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.eta_des_DWORK1, 2, discStates[idx
      ++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.PrevY, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_o, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.PrevY_e, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Memory_PreviousInput_e, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_js, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_ku, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_k4, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.PrevY_f, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Memory_PreviousInput_i, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_h, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_i, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_o, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.PrevY_l, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Memory_PreviousInput_l, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_eg, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_b, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.PrevY_c, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Memory_PreviousInput_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_n, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_aj, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.PrevY_ca, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Memory_PreviousInput_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1_g, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTransferFcn_tmp_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_N_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_X_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_Y_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_tilde_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_tilde_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_tidle_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_tilde_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_tilde_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_tilde_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_d_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading,
      0, discStates[idx++], 10, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading, 0,
      discStates[idx++], 10, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRese, 0,
      discStates[idx++], 2, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_p, 0,
      discStates[idx++], 2, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_n, 0,
      discStates[idx++], 2, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_b, 0,
      discStates[idx++], 2, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_e, 0,
      discStates[idx++], 2, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_m, 0,
      discStates[idx++], 2, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevR_em, 0,
      discStates[idx++], 2, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_o, 0,
      discStates[idx++], 2, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_k, 0,
      discStates[idx++], 2, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_g, 0,
      discStates[idx++], 2, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_f, 0,
      discStates[idx++], 2, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.DiscreteTimeIntegrator_PrevRe_c, 0,
      discStates[idx++], 2, 0);
    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_k, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_b, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_o, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_j, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_j5, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.pwm_1_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.pwm_2_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_DWORK2, count, discStates[idx
        ++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.pwm_3_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.pwm_4_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.pwm_5_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_x_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_y_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_psi_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_psi_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_x_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_y_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_psi_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_x_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_y_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_f, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_x_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_y_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_psi_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_psi_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_x_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_y_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_ref_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_ref_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_ref_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_2_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_3_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_4_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_5_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_6_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_1_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_d, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_1_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.pwm_6_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_2_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_3_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_4_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_5_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_6_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_4_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_5_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_6_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_1_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_2_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_dot_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_dot_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_dot_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_x_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_y_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_psi_hat_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_3_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.eta_des_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_p, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_dw, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_h, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_a, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_e, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2_aw, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_N_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_X_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_Y_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_tilde_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_tilde_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_tidle_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_tilde_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_tilde_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_tilde_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_d_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_d_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_d_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_d_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_d_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_d_DWORK2, count,
        discStates[idx++], 25, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.CoreSubsys[ForEach_itr1].
        DiscreteTimeIntegrator_DSTATE, 0, discStates[idx++], 0, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.CoreSubsys[ForEach_itr1].
        Delay_DSTATE, 0, discStates[idx++], 0, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.CoreSubsys[ForEach_itr1].
        DiscreteTimeIntegrator_PrevRese, 0, discStates[idx++], 2, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.CoreSubsys[ForEach_itr1].
        DiscreteTimeIntegrator_IC_LOADI, 0, discStates[idx++], 3, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_DP_basic
