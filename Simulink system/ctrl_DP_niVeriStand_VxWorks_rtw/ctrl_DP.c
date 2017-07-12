/*
 * ctrl_DP.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_DP".
 *
 * Model version              : 1.201
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Tue Jul 11 19:56:09 2017
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_DP.h"
#include "ctrl_DP_private.h"

/* Block signals (auto storage) */
B_ctrl_DP_T ctrl_DP_B;

/* Continuous states */
X_ctrl_DP_T ctrl_DP_X;

/* Block states (auto storage) */
DW_ctrl_DP_T ctrl_DP_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_DP_T ctrl_DP_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_DP_T ctrl_DP_M_;
RT_MODEL_ctrl_DP_T *const ctrl_DP_M = &ctrl_DP_M_;

/* Forward declaration for local functions */
static void ctrl_DP_diag(const real_T v[6], real_T d[36]);
static real_T ctrl_DP_xnrm2(int32_T n, const real_T x[18], int32_T ix0);
static real_T ctrl_DP_xnrm2_k(int32_T n, const real_T x[6], int32_T ix0);
static void ctrl_DP_xaxpy_bj(int32_T n, real_T a, const real_T x[3], int32_T ix0,
  real_T y[18], int32_T iy0);
static void ctrl_DP_xaxpy_b(int32_T n, real_T a, const real_T x[18], int32_T ix0,
  real_T y[3], int32_T iy0);
static void ctrl_DP_xscal(real_T a, real_T x[9], int32_T ix0);
static void ctrl_DP_xscal_j(real_T a, real_T x[36], int32_T ix0);
static void ctrl_DP_xswap(real_T x[36], int32_T ix0, int32_T iy0);
static void ctrl_DP_xswap_a(real_T x[9], int32_T ix0, int32_T iy0);
static void ctrl_DP_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void ctrl_DP_xrot(real_T x[36], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static void ctrl_DP_xrot_a(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static real_T ctrl_DP_xdotc_ii(int32_T n, const real_T x[36], int32_T ix0, const
  real_T y[36], int32_T iy0);
static void ctrl_DP_xaxpy_bjyy(int32_T n, real_T a, int32_T ix0, real_T y[36],
  int32_T iy0);
static real_T ctrl_DP_xdotc_i(int32_T n, const real_T x[9], int32_T ix0, const
  real_T y[9], int32_T iy0);
static void ctrl_DP_xaxpy_bjy(int32_T n, real_T a, int32_T ix0, real_T y[9],
  int32_T iy0);
static real_T ctrl_DP_xdotc(int32_T n, const real_T x[18], int32_T ix0, const
  real_T y[18], int32_T iy0);
static void ctrl_DP_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[18],
  int32_T iy0);
static void ctrl_DP_svd_m(const real_T A[18], real_T U[9], real_T S[9], real_T
  V[18]);
static void ctrl_DP_svd(const real_T A[18], real_T U[9], real_T S[9], real_T V
  [18]);
static void ctrl_DP_isfinite(const real_T x[9], boolean_T b[9]);
static real_T ctrl_DP_xnrm2_ke(int32_T n, const real_T x[36], int32_T ix0);
static real_T ctrl_DP_xnrm2_ke4(int32_T n, const real_T x[12], int32_T ix0);
static void ctrl_DP_xaxpy_bjyy3c4(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[36], int32_T iy0);
static void ctrl_DP_xaxpy_bjyy3c(int32_T n, real_T a, const real_T x[36],
  int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_DP_xscal_jc(real_T a, real_T x[144], int32_T ix0);
static void ctrl_DP_xswap_am(real_T x[144], int32_T ix0, int32_T iy0);
static void ctrl_DP_xrot_ai(real_T x[144], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static real_T ctrl_DP_xdotc_iiu4(int32_T n, const real_T x[144], int32_T ix0,
  const real_T y[144], int32_T iy0);
static void ctrl_DP_xaxpy_bjyy3c4d(int32_T n, real_T a, int32_T ix0, real_T y
  [144], int32_T iy0);
static real_T ctrl_DP_xdotc_iiu(int32_T n, const real_T x[36], int32_T ix0,
  const real_T y[36], int32_T iy0);
static void ctrl_DP_xaxpy_bjyy3(int32_T n, real_T a, int32_T ix0, real_T y[36],
  int32_T iy0);
static void ctrl_DP_svd_m4e(const real_T A[36], real_T U[9], real_T S[9], real_T
  V[36]);
static void ctrl_DP_svd_m4(const real_T A[36], real_T U[9], real_T S[9], real_T
  V[36]);
static void ctrl_DP_abs(const real_T x[2], real_T y[2]);
static void ctrl_DP_cosd(real_T *x);
static void ctrl_DP_sind(real_T *x);
static void ctrl_DP_cosd_k(real_T *x);
static void ctrl_DP_sind_n(real_T *x);

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
  ctrl_DP_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ctrl_DP_output();
  ctrl_DP_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ctrl_DP_output();
  ctrl_DP_derivatives();

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
 * Output and update for atomic system:
 *    '<S24>/MATLAB Function'
 *    '<S24>/MATLAB Function1'
 *    '<S24>/MATLAB Function2'
 *    '<S25>/MATLAB Function'
 *    '<S25>/MATLAB Function1'
 *    '<S26>/MATLAB Function'
 *    '<S26>/MATLAB Function1'
 *    '<S26>/MATLAB Function2'
 */
void ctrl_DP_MATLABFunction(real_T rtu_u, real_T rtu_u_f, real_T rtu_u_m,
  B_MATLABFunction_ctrl_DP_T *localB)
{
  /* MATLAB Function 'Input1/Control Gains/MATLAB Function': '<S27>:1' */
  /* '<S27>:1:3' */
  memset(&localB->y[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S27>/TmpSignal ConversionAt SFunction Inport1' */
  localB->y[0] = rtu_u;
  localB->y[4] = rtu_u_f;
  localB->y[8] = rtu_u_m;
}

/*
 * Output and update for atomic system:
 *    '<S54>/MATLAB Function2'
 *    '<S54>/MATLAB Function3'
 *    '<S54>/MATLAB Function4'
 *    '<S54>/MATLAB Function5'
 *    '<S54>/MATLAB Function6'
 */
void ctrl_DP_MATLABFunction2(real_T rtu_Tc_in1, real_T rtu_signal, real_T
  rtu_Tc_in2, B_MATLABFunction2_ctrl_DP_T *localB)
{
  /* MATLAB Function 'Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function2': '<S63>:1' */
  if (rtu_signal >= 0.0) {
    /* '<S63>:1:4' */
    /* '<S63>:1:5' */
    localB->Tc_out = rtu_Tc_in1;
  } else {
    /* signal < 0 */
    /* '<S63>:1:7' */
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
 *    '<S72>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S81>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S90>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S99>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S108>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S117>/Core controller: Torque,Power and Combined Torque//Power'
 */
void CorecontrollerTorquePowerandCom(real_T rtu_k_cc, real_T rtu_p_cc, real_T
  rtu_r_cc, real_T rtu_n, real_T rtu_K_t0, real_T rtu_K_q0, real_T rtu_D, real_T
  rtu_Tr, real_T rtu_rho, real_T rtu_eps_c, real_T rtu_K_t0r, real_T rtu_K_q0r,
  B_CorecontrollerTorquePoweran_T *localB)
{
  real_T lambda_c;
  real_T K_TC;
  real_T K_QC;
  real_T rtu_Tr_0;

  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power': '<S76>:1' */
  /* '<S76>:1:4' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /* '<S76>:1:5' */
  K_TC = (1.0 - lambda_c) * rtu_K_t0r + rtu_K_t0 * lambda_c;

  /* '<S76>:1:6' */
  K_QC = (1.0 - lambda_c) * rtu_K_q0r + rtu_K_q0 * lambda_c;

  /* '<S76>:1:7' */
  lambda_c = K_QC / K_TC * rtu_D * rtu_Tr;
  if (rtu_n == 0.0) {
    /* '<S76>:1:8' */
    /* '<S76>:1:9' */
    K_TC = 0.0;
  } else {
    /* '<S76>:1:11' */
    if (rtu_Tr < 0.0) {
      rtu_Tr_0 = -1.0;
    } else if (rtu_Tr > 0.0) {
      rtu_Tr_0 = 1.0;
    } else if (rtu_Tr == 0.0) {
      rtu_Tr_0 = 0.0;
    } else {
      rtu_Tr_0 = rtu_Tr;
    }

    K_TC = rtu_Tr_0 * K_QC * rt_powd_snf(fabs(rtu_Tr), 1.5) / (sqrt(rtu_rho) *
      rtu_D * rt_powd_snf(K_TC, 1.5) * fabs(rtu_n));
  }

  /* '<S76>:1:13' */
  K_QC = exp(rt_powd_snf(fabs(rtu_p_cc * rtu_n), rtu_r_cc) * -rtu_k_cc);

  /* '<S76>:1:15' */
  localB->Qcc = (1.0 - K_QC) * K_TC + K_QC * lambda_c;
  localB->Qcq = lambda_c;
  localB->Qcp = K_TC;
}

/*
 * Output and update for atomic system:
 *    '<S70>/Supervisor'
 *    '<S79>/Supervisor'
 *    '<S88>/Supervisor'
 *    '<S97>/Supervisor'
 *    '<S106>/Supervisor'
 *    '<S115>/Supervisor'
 */
void ctrl_DP_Supervisor(real_T rtu_control, real_T rtu_input, real_T rtu_n,
  B_Supervisor_ctrl_DP_T *localB)
{
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Supervisor': '<S75>:1' */
  /* '<S75>:1:2' */
  localB->u = 1.0;
  if (rtu_control == 1.0) {
    /* '<S75>:1:3' */
    if (rtu_input == 1.0) {
      /* '<S75>:1:4' */
      /* '<S75>:1:5' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S75>:1:6' */
      /* '<S75>:1:7' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S75>:1:8' */
      /* '<S75>:1:9' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S75>:1:10' */
      /* '<S75>:1:11' */
      localB->u = 4.0;
    } else {
      /* '<S75>:1:13' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 2.0) {
    /* '<S75>:1:17' */
    if (rtu_input == 1.0) {
      /* '<S75>:1:18' */
      /* '<S75>:1:19' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S75>:1:20' */
      /* '<S75>:1:21' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S75>:1:22' */
      /* '<S75>:1:23' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S75>:1:24' */
      /* '<S75>:1:25' */
      localB->u = 4.0;
    } else {
      /* '<S75>:1:27' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 3.0) {
    /* '<S75>:1:31' */
    if (rtu_input == 1.0) {
      /* '<S75>:1:32' */
      /* '<S75>:1:33' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S75>:1:34' */
      /* '<S75>:1:35' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S75>:1:36' */
      /* '<S75>:1:37' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S75>:1:38' */
      /* '<S75>:1:39' */
      localB->u = 4.0;
    } else {
      /* '<S75>:1:41' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 4.0) {
    /* '<S75>:1:45' */
    if (rtu_input == 1.0) {
      /* '<S75>:1:46' */
      /* '<S75>:1:47' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S75>:1:48' */
      /* '<S75>:1:49' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S75>:1:50' */
      /* '<S75>:1:51' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S75>:1:52' */
      /* '<S75>:1:53' */
      localB->u = 4.0;
    } else {
      /* '<S75>:1:55' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 5.0) {
    /* '<S75>:1:59' */
    if (rtu_input == 1.0) {
      /* '<S75>:1:60' */
      /* '<S75>:1:61' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S75>:1:62' */
      /* '<S75>:1:63' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S75>:1:64' */
      /* '<S75>:1:65' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S75>:1:66' */
      /* '<S75>:1:67' */
      localB->u = 4.0;
    } else {
      /* '<S75>:1:69' */
      localB->u = 5.0;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S77>/Actual Force and Torque'
 *    '<S86>/Actual Force and Torque'
 *    '<S95>/Actual Force and Torque'
 *    '<S104>/Actual Force and Torque'
 *    '<S113>/Actual Force and Torque'
 */
void ctrl_DP_ActualForceandTorque(real_T rtu_n, real_T rtu_Kq, real_T rtu_Kt,
  real_T rtu_Ktr, real_T rtu_Kqr, real_T rtu_Rho, real_T rtu_D, real_T rtu_eps_c,
  real_T rtu_env, B_ActualForceandTorque_ctrl_D_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_0;

  /* MATLAB Function 'Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque': '<S80>:1' */
  /* '<S80>:1:3' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S80>:1:4' */
  /* '<S80>:1:5' */
  /* '<S80>:1:7' */
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

  /* '<S80>:1:8' */
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
 *    '<S79>/MATLAB Function'
 *    '<S97>/MATLAB Function'
 *    '<S106>/MATLAB Function'
 */
void ctrl_DP_MATLABFunction_i(real_T rtu_Td, real_T rtu_K_t0, real_T rtu_K_t0r,
  real_T rtu_rho, real_T rtu_D, real_T rtu_eps_c, real_T rtu_n_r,
  B_MATLABFunction_ctrl_DP_a_T *localB)
{
  real_T lambda_c;
  real_T rtu_Td_0;
  real_T rtu_n_r_0;

  /* MATLAB Function 'Thruster control /Thruster 2/Thruster control/MATLAB Function': '<S83>:1' */
  /* '<S83>:1:5' */
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

  /* '<S83>:1:7' */
  lambda_c = tanh(rtu_eps_c * rtu_Td_0 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S83>:1:8' */
  /* '<S83>:1:10' */
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_diag(const real_T v[6], real_T d[36])
{
  int32_T j;
  memset(&d[0], 0, 36U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    d[j + 6 * j] = v[j];
  }
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_xnrm2(int32_T n, const real_T x[18], int32_T ix0)
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
static real_T ctrl_DP_xnrm2_k(int32_T n, const real_T x[6], int32_T ix0)
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
static void ctrl_DP_xaxpy_bj(int32_T n, real_T a, const real_T x[3], int32_T ix0,
  real_T y[18], int32_T iy0)
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
static void ctrl_DP_xaxpy_b(int32_T n, real_T a, const real_T x[18], int32_T ix0,
  real_T y[3], int32_T iy0)
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
static void ctrl_DP_xscal(real_T a, real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_xscal_j(real_T a, real_T x[36], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 5; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_xswap(real_T x[36], int32_T ix0, int32_T iy0)
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
static void ctrl_DP_xswap_a(real_T x[9], int32_T ix0, int32_T iy0)
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
static void ctrl_DP_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
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
    scale = 0.0;
    absa = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      absa = *s;
    } else if (*c != 0.0) {
      absa = 1.0 / *c;
    } else {
      absa = 1.0;
    }
  }

  *a = scale;
  *b = absa;
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_xrot(real_T x[36], int32_T ix0, int32_T iy0, real_T c,
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_xrot_a(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_xdotc_ii(int32_T n, const real_T x[36], int32_T ix0, const
  real_T y[36], int32_T iy0)
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
static void ctrl_DP_xaxpy_bjyy(int32_T n, real_T a, int32_T ix0, real_T y[36],
  int32_T iy0)
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
static real_T ctrl_DP_xdotc_i(int32_T n, const real_T x[9], int32_T ix0, const
  real_T y[9], int32_T iy0)
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
static void ctrl_DP_xaxpy_bjy(int32_T n, real_T a, int32_T ix0, real_T y[9],
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_xdotc(int32_T n, const real_T x[18], int32_T ix0, const
  real_T y[18], int32_T iy0)
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
static void ctrl_DP_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[18],
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_svd_m(const real_T A[18], real_T U[9], real_T S[9], real_T
  V[18])
{
  real_T b_A[18];
  real_T s[4];
  real_T e[6];
  real_T work[3];
  real_T Vf[36];
  int32_T q;
  boolean_T apply_transform;
  int32_T m;
  real_T snorm;
  real_T ztest0;
  int32_T kase;
  int32_T qs;
  real_T ztest;
  real_T smm1;
  real_T emm1;
  real_T sqds;
  real_T shift;
  int32_T k_ii;
  real_T varargin_1[5];
  int32_T i;
  boolean_T exitg1;
  boolean_T exitg2;
  int32_T exitg3;
  memcpy(&b_A[0], &A[0], 18U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    e[i] = 0.0;
  }

  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  memset(&U[0], 0, 9U * sizeof(real_T));
  memset(&Vf[0], 0, 36U * sizeof(real_T));
  i = 0;
  apply_transform = false;
  snorm = ctrl_DP_xnrm2(3, b_A, 1);
  if (snorm > 0.0) {
    apply_transform = true;
    if (b_A[0] < 0.0) {
      s[0] = -snorm;
    } else {
      s[0] = snorm;
    }

    if (fabs(s[0]) >= 1.0020841800044864E-292) {
      snorm = 1.0 / s[0];
      for (qs = 0; qs + 1 < 4; qs++) {
        b_A[qs] *= snorm;
      }
    } else {
      for (qs = 0; qs + 1 < 4; qs++) {
        b_A[qs] /= s[0];
      }
    }

    b_A[0]++;
    s[0] = -s[0];
  } else {
    s[0] = 0.0;
  }

  for (q = 1; q + 1 < 7; q++) {
    qs = 3 * q;
    if (apply_transform) {
      ctrl_DP_xaxpy(3, -(ctrl_DP_xdotc(3, b_A, 1, b_A, qs + 1) / b_A[0]), 1, b_A,
                    qs + 1);
    }

    e[q] = b_A[qs];
  }

  while (i + 1 < 4) {
    U[i] = b_A[i];
    i++;
  }

  snorm = ctrl_DP_xnrm2_k(5, e, 2);
  if (snorm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      e[0] = -snorm;
    } else {
      e[0] = snorm;
    }

    snorm = e[0];
    if (fabs(e[0]) >= 1.0020841800044864E-292) {
      snorm = 1.0 / e[0];
      for (i = 1; i + 1 < 7; i++) {
        e[i] *= snorm;
      }
    } else {
      for (i = 1; i + 1 < 7; i++) {
        e[i] /= snorm;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (i = 1; i + 1 < 4; i++) {
      work[i] = 0.0;
    }

    for (i = 1; i + 1 < 7; i++) {
      ctrl_DP_xaxpy_b(2, e[i], b_A, 3 * i + 2, work, 2);
    }

    for (i = 1; i + 1 < 7; i++) {
      ctrl_DP_xaxpy_bj(2, -e[i] / e[1], work, 2, b_A, 3 * i + 2);
    }
  }

  for (i = 1; i + 1 < 7; i++) {
    Vf[i] = e[i];
  }

  apply_transform = false;
  snorm = ctrl_DP_xnrm2(2, b_A, 5);
  if (snorm > 0.0) {
    apply_transform = true;
    if (b_A[4] < 0.0) {
      s[1] = -snorm;
    } else {
      s[1] = snorm;
    }

    if (fabs(s[1]) >= 1.0020841800044864E-292) {
      snorm = 1.0 / s[1];
      for (qs = 4; qs + 1 < 7; qs++) {
        b_A[qs] *= snorm;
      }
    } else {
      for (qs = 4; qs + 1 < 7; qs++) {
        b_A[qs] /= s[1];
      }
    }

    b_A[4]++;
    s[1] = -s[1];
  } else {
    s[1] = 0.0;
  }

  for (q = 2; q + 1 < 7; q++) {
    qs = 3 * q + 1;
    if (apply_transform) {
      ctrl_DP_xaxpy(2, -(ctrl_DP_xdotc(2, b_A, 5, b_A, qs + 1) / b_A[4]), 5, b_A,
                    qs + 1);
    }

    e[q] = b_A[qs];
  }

  for (i = 1; i + 1 < 4; i++) {
    U[i + 3] = b_A[i + 3];
  }

  snorm = ctrl_DP_xnrm2_k(4, e, 3);
  if (snorm == 0.0) {
    e[1] = 0.0;
  } else {
    if (e[2] < 0.0) {
      e[1] = -snorm;
    } else {
      e[1] = snorm;
    }

    snorm = e[1];
    if (fabs(e[1]) >= 1.0020841800044864E-292) {
      snorm = 1.0 / e[1];
      for (i = 2; i + 1 < 7; i++) {
        e[i] *= snorm;
      }
    } else {
      for (i = 2; i + 1 < 7; i++) {
        e[i] /= snorm;
      }
    }

    e[2]++;
    e[1] = -e[1];
    for (i = 2; i + 1 < 4; i++) {
      work[i] = 0.0;
    }

    for (i = 2; i + 1 < 7; i++) {
      ctrl_DP_xaxpy_b(1, e[i], b_A, 3 * i + 3, work, 3);
    }

    for (i = 2; i + 1 < 7; i++) {
      ctrl_DP_xaxpy_bj(1, -e[i] / e[2], work, 3, b_A, 3 * i + 3);
    }
  }

  for (i = 2; i + 1 < 7; i++) {
    Vf[i + 6] = e[i];
  }

  for (q = 3; q + 1 < 7; q++) {
    e[q] = b_A[3 * q + 2];
  }

  snorm = ctrl_DP_xnrm2_k(3, e, 4);
  if (snorm == 0.0) {
    e[2] = 0.0;
  } else {
    if (e[3] < 0.0) {
      e[2] = -snorm;
    } else {
      e[2] = snorm;
    }

    snorm = e[2];
    if (fabs(e[2]) >= 1.0020841800044864E-292) {
      snorm = 1.0 / e[2];
      for (i = 3; i + 1 < 7; i++) {
        e[i] *= snorm;
      }
    } else {
      for (i = 3; i + 1 < 7; i++) {
        e[i] /= snorm;
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
  for (q = 1; q >= 0; q += -1) {
    i = 3 * q + q;
    if (s[q] != 0.0) {
      for (kase = q + 1; kase + 1 < 4; kase++) {
        qs = (3 * kase + q) + 1;
        ctrl_DP_xaxpy_bjy(3 - q, -(ctrl_DP_xdotc_i(3 - q, U, i + 1, U, qs) / U[i]),
                          i + 1, U, qs);
      }

      for (qs = q; qs + 1 < 4; qs++) {
        U[qs + 3 * q] = -U[3 * q + qs];
      }

      U[i]++;
      i = 1;
      while (i <= q) {
        U[3] = 0.0;
        i = 2;
      }
    } else {
      U[3 * q] = 0.0;
      U[1 + 3 * q] = 0.0;
      U[2 + 3 * q] = 0.0;
      U[i] = 1.0;
    }
  }

  for (i = 5; i >= 0; i += -1) {
    if ((i + 1 <= 3) && (e[i] != 0.0)) {
      q = (6 * i + i) + 2;
      for (qs = i + 1; qs + 1 < 7; qs++) {
        kase = (6 * qs + i) + 2;
        ctrl_DP_xaxpy_bjyy(5 - i, -(ctrl_DP_xdotc_ii(5 - i, Vf, q, Vf, kase) /
          Vf[q - 1]), q, Vf, kase);
      }
    }

    for (q = 0; q < 6; q++) {
      Vf[q + 6 * i] = 0.0;
    }

    Vf[i + 6 * i] = 1.0;
  }

  ztest = e[0];
  if (s[0] != 0.0) {
    ztest0 = fabs(s[0]);
    snorm = s[0] / ztest0;
    s[0] = ztest0;
    ztest = e[0] / snorm;
    ctrl_DP_xscal(snorm, U, 1);
  }

  if (ztest != 0.0) {
    ztest0 = fabs(ztest);
    snorm = ztest0 / ztest;
    ztest = ztest0;
    s[1] *= snorm;
    ctrl_DP_xscal_j(snorm, Vf, 7);
  }

  e[0] = ztest;
  ztest = e[1];
  if (s[1] != 0.0) {
    ztest0 = fabs(s[1]);
    snorm = s[1] / ztest0;
    s[1] = ztest0;
    ztest = e[1] / snorm;
    ctrl_DP_xscal(snorm, U, 4);
  }

  if (ztest != 0.0) {
    ztest0 = fabs(ztest);
    snorm = ztest0 / ztest;
    ztest = ztest0;
    s[2] = b_A[8] * snorm;
    ctrl_DP_xscal_j(snorm, Vf, 13);
  }

  e[1] = ztest;
  ztest = e[2];
  if (s[2] != 0.0) {
    ztest0 = fabs(s[2]);
    snorm = s[2] / ztest0;
    s[2] = ztest0;
    ztest = e[2] / snorm;
    ctrl_DP_xscal(snorm, U, 7);
  }

  if (ztest != 0.0) {
    ztest0 = fabs(ztest);
    snorm = ztest0 / ztest;
    ztest = ztest0;
    s[3] = 0.0 * snorm;
    ctrl_DP_xscal_j(snorm, Vf, 19);
  }

  e[2] = ztest;
  e[3] = 0.0;
  i = 0;
  snorm = 0.0;
  if ((s[0] >= e[0]) || rtIsNaN(e[0])) {
    ztest0 = s[0];
  } else {
    ztest0 = e[0];
  }

  if (!((0.0 >= ztest0) || rtIsNaN(ztest0))) {
    snorm = ztest0;
  }

  if ((s[1] >= e[1]) || rtIsNaN(e[1])) {
    ztest0 = s[1];
  } else {
    ztest0 = e[1];
  }

  if (!((snorm >= ztest0) || rtIsNaN(ztest0))) {
    snorm = ztest0;
  }

  if ((s[2] >= ztest) || rtIsNaN(ztest)) {
    ztest = s[2];
  }

  if (!((snorm >= ztest) || rtIsNaN(ztest))) {
    snorm = ztest;
  }

  if (s[3] >= 0.0) {
    ztest0 = s[3];
  } else {
    ztest0 = 0.0;
  }

  if (!((snorm >= ztest0) || rtIsNaN(ztest0))) {
    snorm = ztest0;
  }

  while ((m + 2 > 0) && (!(i >= 75))) {
    kase = m + 1;
    do {
      exitg3 = 0;
      q = kase;
      if (kase == 0) {
        exitg3 = 1;
      } else {
        ztest0 = fabs(e[kase - 1]);
        if ((ztest0 <= (fabs(s[kase - 1]) + fabs(s[kase])) *
             2.2204460492503131E-16) || ((ztest0 <= 1.0020841800044864E-292) ||
             ((i > 20) && (ztest0 <= 2.2204460492503131E-16 * snorm)))) {
          e[kase - 1] = 0.0;
          exitg3 = 1;
        } else {
          kase--;
        }
      }
    } while (exitg3 == 0);

    if (m + 1 == kase) {
      kase = 4;
    } else {
      qs = m + 2;
      k_ii = m + 2;
      exitg2 = false;
      while ((!exitg2) && (k_ii >= kase)) {
        qs = k_ii;
        if (k_ii == kase) {
          exitg2 = true;
        } else {
          ztest0 = 0.0;
          if (k_ii < m + 2) {
            ztest0 = fabs(e[k_ii - 1]);
          }

          if (k_ii > kase + 1) {
            ztest0 += fabs(e[k_ii - 2]);
          }

          ztest = fabs(s[k_ii - 1]);
          if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <=
               1.0020841800044864E-292)) {
            s[k_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            k_ii--;
          }
        }
      }

      if (qs == kase) {
        kase = 3;
      } else if (m + 2 == qs) {
        kase = 1;
      } else {
        kase = 2;
        q = qs;
      }
    }

    switch (kase) {
     case 1:
      ztest0 = e[m];
      e[m] = 0.0;
      for (qs = m; qs + 1 >= q + 1; qs--) {
        ztest = s[qs];
        ctrl_DP_xrotg(&ztest, &ztest0, &sqds, &smm1);
        s[qs] = ztest;
        if (qs + 1 > q + 1) {
          ztest0 = e[qs - 1] * -smm1;
          e[qs - 1] *= sqds;
        }

        ctrl_DP_xrot(Vf, 1 + 6 * qs, 1 + 6 * (m + 1), sqds, smm1);
      }
      break;

     case 2:
      ztest0 = e[q - 1];
      e[q - 1] = 0.0;
      for (qs = q; qs + 1 <= m + 2; qs++) {
        ztest = s[qs];
        ctrl_DP_xrotg(&ztest, &ztest0, &sqds, &smm1);
        s[qs] = ztest;
        ztest0 = -smm1 * e[qs];
        e[qs] *= sqds;
        ctrl_DP_xrot_a(U, 1 + 3 * qs, 1 + 3 * (q - 1), sqds, smm1);
      }
      break;

     case 3:
      varargin_1[0] = fabs(s[m + 1]);
      varargin_1[1] = fabs(s[m]);
      varargin_1[2] = fabs(e[m]);
      varargin_1[3] = fabs(s[q]);
      varargin_1[4] = fabs(e[q]);
      qs = 1;
      ztest = varargin_1[0];
      if (rtIsNaN(varargin_1[0])) {
        kase = 2;
        exitg1 = false;
        while ((!exitg1) && (kase < 6)) {
          qs = kase;
          if (!rtIsNaN(varargin_1[kase - 1])) {
            ztest = varargin_1[kase - 1];
            exitg1 = true;
          } else {
            kase++;
          }
        }
      }

      if (qs < 5) {
        while (qs + 1 < 6) {
          if (varargin_1[qs] > ztest) {
            ztest = varargin_1[qs];
          }

          qs++;
        }
      }

      ztest0 = s[m + 1] / ztest;
      smm1 = s[m] / ztest;
      emm1 = e[m] / ztest;
      sqds = s[q] / ztest;
      smm1 = ((smm1 + ztest0) * (smm1 - ztest0) + emm1 * emm1) / 2.0;
      emm1 *= ztest0;
      emm1 *= emm1;
      if ((smm1 != 0.0) || (emm1 != 0.0)) {
        shift = sqrt(smm1 * smm1 + emm1);
        if (smm1 < 0.0) {
          shift = -shift;
        }

        shift = emm1 / (smm1 + shift);
      } else {
        shift = 0.0;
      }

      ztest0 = (sqds + ztest0) * (sqds - ztest0) + shift;
      ztest = e[q] / ztest * sqds;
      for (qs = q + 1; qs <= m + 1; qs++) {
        ctrl_DP_xrotg(&ztest0, &ztest, &sqds, &smm1);
        if (qs > q + 1) {
          e[qs - 2] = ztest0;
        }

        ztest0 = s[qs - 1] * sqds + e[qs - 1] * smm1;
        e[qs - 1] = e[qs - 1] * sqds - s[qs - 1] * smm1;
        ztest = smm1 * s[qs];
        s[qs] *= sqds;
        ctrl_DP_xrot(Vf, 1 + 6 * (qs - 1), 1 + 6 * qs, sqds, smm1);
        ctrl_DP_xrotg(&ztest0, &ztest, &sqds, &smm1);
        s[qs - 1] = ztest0;
        ztest0 = e[qs - 1] * sqds + smm1 * s[qs];
        s[qs] = e[qs - 1] * -smm1 + sqds * s[qs];
        ztest = smm1 * e[qs];
        e[qs] *= sqds;
        if (qs < 3) {
          ctrl_DP_xrot_a(U, 1 + 3 * (qs - 1), 1 + 3 * qs, sqds, smm1);
        }
      }

      e[m] = ztest0;
      i++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_DP_xscal_j(-1.0, Vf, 1 + 6 * q);
      }

      i = q + 1;
      while ((q + 1 < 4) && (s[q] < s[i])) {
        ztest0 = s[q];
        s[q] = s[i];
        s[i] = ztest0;
        ctrl_DP_xswap(Vf, 1 + 6 * q, 1 + 6 * (q + 1));
        if (q + 1 < 3) {
          ctrl_DP_xswap_a(U, 1 + 3 * q, 1 + 3 * (q + 1));
        }

        q = i;
        i++;
      }

      i = 0;
      m--;
      break;
    }
  }

  for (m = 0; m < 3; m++) {
    work[m] = s[m];
    for (i = 0; i < 6; i++) {
      V[i + 6 * m] = Vf[6 * m + i];
    }
  }

  memset(&S[0], 0, 9U * sizeof(real_T));
  S[0] = work[0];
  S[4] = work[1];
  S[8] = work[2];
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_svd(const real_T A[18], real_T U[9], real_T S[9], real_T V
  [18])
{
  boolean_T b_p;
  int32_T k;
  b_p = true;
  for (k = 0; k < 18; k++) {
    if (b_p && ((!rtIsInf(A[k])) && (!rtIsNaN(A[k])))) {
    } else {
      b_p = false;
    }
  }

  if (b_p) {
    ctrl_DP_svd_m(A, U, S, V);
  } else {
    for (k = 0; k < 9; k++) {
      U[k] = (rtNaN);
      S[k] = 0.0;
    }

    S[0] = (rtNaN);
    S[4] = (rtNaN);
    S[8] = (rtNaN);
    for (k = 0; k < 18; k++) {
      V[k] = (rtNaN);
    }
  }
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_isfinite(const real_T x[9], boolean_T b[9])
{
  int32_T i;
  for (i = 0; i < 9; i++) {
    b[i] = ((!rtIsInf(x[i])) && (!rtIsNaN(x[i])));
  }
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static real_T ctrl_DP_xnrm2_ke(int32_T n, const real_T x[36], int32_T ix0)
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
static real_T ctrl_DP_xnrm2_ke4(int32_T n, const real_T x[12], int32_T ix0)
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
static void ctrl_DP_xaxpy_bjyy3c4(int32_T n, real_T a, const real_T x[3],
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_xaxpy_bjyy3c(int32_T n, real_T a, const real_T x[36],
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
static void ctrl_DP_xscal_jc(real_T a, real_T x[144], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 11; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_xswap_am(real_T x[144], int32_T ix0, int32_T iy0)
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
static void ctrl_DP_xrot_ai(real_T x[144], int32_T ix0, int32_T iy0, real_T c,
  real_T s)
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
static real_T ctrl_DP_xdotc_iiu4(int32_T n, const real_T x[144], int32_T ix0,
  const real_T y[144], int32_T iy0)
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
static void ctrl_DP_xaxpy_bjyy3c4d(int32_T n, real_T a, int32_T ix0, real_T y
  [144], int32_T iy0)
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
static real_T ctrl_DP_xdotc_iiu(int32_T n, const real_T x[36], int32_T ix0,
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_xaxpy_bjyy3(int32_T n, real_T a, int32_T ix0, real_T y[36],
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

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_svd_m4e(const real_T A[36], real_T U[9], real_T S[9], real_T
  V[36])
{
  real_T b_A[36];
  real_T s[4];
  real_T e[12];
  real_T work[3];
  real_T Vf[144];
  int32_T q;
  boolean_T apply_transform;
  int32_T m;
  int32_T iter;
  real_T snorm;
  real_T ztest0;
  int32_T kase;
  int32_T qs;
  real_T ztest;
  real_T smm1;
  real_T emm1;
  real_T sqds;
  real_T shift;
  int32_T k_ii;
  real_T varargin_1[5];
  boolean_T exitg1;
  boolean_T exitg2;
  int32_T exitg3;
  memcpy(&b_A[0], &A[0], 36U * sizeof(real_T));
  memset(&e[0], 0, 12U * sizeof(real_T));
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  memset(&U[0], 0, 9U * sizeof(real_T));
  memset(&Vf[0], 0, 144U * sizeof(real_T));
  iter = 0;
  apply_transform = false;
  snorm = ctrl_DP_xnrm2_ke(3, b_A, 1);
  if (snorm > 0.0) {
    apply_transform = true;
    if (b_A[0] < 0.0) {
      s[0] = -snorm;
    } else {
      s[0] = snorm;
    }

    if (fabs(s[0]) >= 1.0020841800044864E-292) {
      snorm = 1.0 / s[0];
      for (qs = 0; qs + 1 < 4; qs++) {
        b_A[qs] *= snorm;
      }
    } else {
      for (qs = 0; qs + 1 < 4; qs++) {
        b_A[qs] /= s[0];
      }
    }

    b_A[0]++;
    s[0] = -s[0];
  } else {
    s[0] = 0.0;
  }

  for (q = 1; q + 1 < 13; q++) {
    qs = 3 * q;
    if (apply_transform) {
      ctrl_DP_xaxpy_bjyy3(3, -(ctrl_DP_xdotc_iiu(3, b_A, 1, b_A, qs + 1) / b_A[0]),
                          1, b_A, qs + 1);
    }

    e[q] = b_A[qs];
  }

  while (iter + 1 < 4) {
    U[iter] = b_A[iter];
    iter++;
  }

  snorm = ctrl_DP_xnrm2_ke4(11, e, 2);
  if (snorm == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      e[0] = -snorm;
    } else {
      e[0] = snorm;
    }

    snorm = e[0];
    if (fabs(e[0]) >= 1.0020841800044864E-292) {
      snorm = 1.0 / e[0];
      for (iter = 1; iter + 1 < 13; iter++) {
        e[iter] *= snorm;
      }
    } else {
      for (iter = 1; iter + 1 < 13; iter++) {
        e[iter] /= snorm;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (iter = 1; iter + 1 < 4; iter++) {
      work[iter] = 0.0;
    }

    for (iter = 1; iter + 1 < 13; iter++) {
      ctrl_DP_xaxpy_bjyy3c(2, e[iter], b_A, 3 * iter + 2, work, 2);
    }

    for (iter = 1; iter + 1 < 13; iter++) {
      ctrl_DP_xaxpy_bjyy3c4(2, -e[iter] / e[1], work, 2, b_A, 3 * iter + 2);
    }
  }

  for (iter = 1; iter + 1 < 13; iter++) {
    Vf[iter] = e[iter];
  }

  apply_transform = false;
  snorm = ctrl_DP_xnrm2_ke(2, b_A, 5);
  if (snorm > 0.0) {
    apply_transform = true;
    if (b_A[4] < 0.0) {
      s[1] = -snorm;
    } else {
      s[1] = snorm;
    }

    if (fabs(s[1]) >= 1.0020841800044864E-292) {
      snorm = 1.0 / s[1];
      for (qs = 4; qs + 1 < 7; qs++) {
        b_A[qs] *= snorm;
      }
    } else {
      for (qs = 4; qs + 1 < 7; qs++) {
        b_A[qs] /= s[1];
      }
    }

    b_A[4]++;
    s[1] = -s[1];
  } else {
    s[1] = 0.0;
  }

  for (q = 2; q + 1 < 13; q++) {
    qs = 3 * q + 1;
    if (apply_transform) {
      ctrl_DP_xaxpy_bjyy3(2, -(ctrl_DP_xdotc_iiu(2, b_A, 5, b_A, qs + 1) / b_A[4]),
                          5, b_A, qs + 1);
    }

    e[q] = b_A[qs];
  }

  for (iter = 1; iter + 1 < 4; iter++) {
    U[iter + 3] = b_A[iter + 3];
  }

  snorm = ctrl_DP_xnrm2_ke4(10, e, 3);
  if (snorm == 0.0) {
    e[1] = 0.0;
  } else {
    if (e[2] < 0.0) {
      e[1] = -snorm;
    } else {
      e[1] = snorm;
    }

    snorm = e[1];
    if (fabs(e[1]) >= 1.0020841800044864E-292) {
      snorm = 1.0 / e[1];
      for (iter = 2; iter + 1 < 13; iter++) {
        e[iter] *= snorm;
      }
    } else {
      for (iter = 2; iter + 1 < 13; iter++) {
        e[iter] /= snorm;
      }
    }

    e[2]++;
    e[1] = -e[1];
    for (iter = 2; iter + 1 < 4; iter++) {
      work[iter] = 0.0;
    }

    for (iter = 2; iter + 1 < 13; iter++) {
      ctrl_DP_xaxpy_bjyy3c(1, e[iter], b_A, 3 * iter + 3, work, 3);
    }

    for (iter = 2; iter + 1 < 13; iter++) {
      ctrl_DP_xaxpy_bjyy3c4(1, -e[iter] / e[2], work, 3, b_A, 3 * iter + 3);
    }
  }

  for (iter = 2; iter + 1 < 13; iter++) {
    Vf[iter + 12] = e[iter];
  }

  for (q = 3; q + 1 < 13; q++) {
    e[q] = b_A[3 * q + 2];
  }

  snorm = ctrl_DP_xnrm2_ke4(9, e, 4);
  if (snorm == 0.0) {
    e[2] = 0.0;
  } else {
    if (e[3] < 0.0) {
      e[2] = -snorm;
    } else {
      e[2] = snorm;
    }

    snorm = e[2];
    if (fabs(e[2]) >= 1.0020841800044864E-292) {
      snorm = 1.0 / e[2];
      for (iter = 3; iter + 1 < 13; iter++) {
        e[iter] *= snorm;
      }
    } else {
      for (iter = 3; iter + 1 < 13; iter++) {
        e[iter] /= snorm;
      }
    }

    e[3]++;
    e[2] = -e[2];
  }

  for (iter = 3; iter + 1 < 13; iter++) {
    Vf[iter + 24] = e[iter];
  }

  m = 2;
  s[2] = b_A[8];
  s[3] = 0.0;
  e[3] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (q = 1; q >= 0; q += -1) {
    iter = 3 * q + q;
    if (s[q] != 0.0) {
      for (kase = q + 1; kase + 1 < 4; kase++) {
        qs = (3 * kase + q) + 1;
        ctrl_DP_xaxpy_bjy(3 - q, -(ctrl_DP_xdotc_i(3 - q, U, iter + 1, U, qs) /
          U[iter]), iter + 1, U, qs);
      }

      for (qs = q; qs + 1 < 4; qs++) {
        U[qs + 3 * q] = -U[3 * q + qs];
      }

      U[iter]++;
      iter = 1;
      while (iter <= q) {
        U[3] = 0.0;
        iter = 2;
      }
    } else {
      U[3 * q] = 0.0;
      U[1 + 3 * q] = 0.0;
      U[2 + 3 * q] = 0.0;
      U[iter] = 1.0;
    }
  }

  for (iter = 11; iter >= 0; iter += -1) {
    if ((iter + 1 <= 3) && (e[iter] != 0.0)) {
      q = (12 * iter + iter) + 2;
      for (qs = iter + 1; qs + 1 < 13; qs++) {
        kase = (12 * qs + iter) + 2;
        ctrl_DP_xaxpy_bjyy3c4d(11 - iter, -(ctrl_DP_xdotc_iiu4(11 - iter, Vf, q,
          Vf, kase) / Vf[q - 1]), q, Vf, kase);
      }
    }

    memset(&Vf[iter * 12], 0, 12U * sizeof(real_T));
    Vf[iter + 12 * iter] = 1.0;
  }

  ztest = e[0];
  if (s[0] != 0.0) {
    ztest0 = fabs(s[0]);
    snorm = s[0] / ztest0;
    s[0] = ztest0;
    ztest = e[0] / snorm;
    ctrl_DP_xscal(snorm, U, 1);
  }

  if (ztest != 0.0) {
    ztest0 = fabs(ztest);
    snorm = ztest0 / ztest;
    ztest = ztest0;
    s[1] *= snorm;
    ctrl_DP_xscal_jc(snorm, Vf, 13);
  }

  e[0] = ztest;
  ztest = e[1];
  if (s[1] != 0.0) {
    ztest0 = fabs(s[1]);
    snorm = s[1] / ztest0;
    s[1] = ztest0;
    ztest = e[1] / snorm;
    ctrl_DP_xscal(snorm, U, 4);
  }

  if (ztest != 0.0) {
    ztest0 = fabs(ztest);
    snorm = ztest0 / ztest;
    ztest = ztest0;
    s[2] = b_A[8] * snorm;
    ctrl_DP_xscal_jc(snorm, Vf, 25);
  }

  e[1] = ztest;
  ztest = e[2];
  if (s[2] != 0.0) {
    ztest0 = fabs(s[2]);
    snorm = s[2] / ztest0;
    s[2] = ztest0;
    ztest = e[2] / snorm;
    ctrl_DP_xscal(snorm, U, 7);
  }

  if (ztest != 0.0) {
    ztest0 = fabs(ztest);
    snorm = ztest0 / ztest;
    ztest = ztest0;
    s[3] = 0.0 * snorm;
    ctrl_DP_xscal_jc(snorm, Vf, 37);
  }

  e[2] = ztest;
  e[3] = 0.0;
  iter = 0;
  snorm = 0.0;
  ztest0 = fabs(e[0]);
  if ((s[0] >= ztest0) || rtIsNaN(ztest0)) {
    ztest0 = s[0];
  }

  if (!((0.0 >= ztest0) || rtIsNaN(ztest0))) {
    snorm = ztest0;
  }

  ztest0 = fabs(e[1]);
  if ((s[1] >= ztest0) || rtIsNaN(ztest0)) {
    ztest0 = s[1];
  }

  if (!((snorm >= ztest0) || rtIsNaN(ztest0))) {
    snorm = ztest0;
  }

  ztest0 = fabs(ztest);
  if ((s[2] >= ztest0) || rtIsNaN(ztest0)) {
    ztest0 = s[2];
  }

  if (!((snorm >= ztest0) || rtIsNaN(ztest0))) {
    snorm = ztest0;
  }

  if (s[3] >= 0.0) {
    ztest0 = s[3];
  } else {
    ztest0 = 0.0;
  }

  if (!((snorm >= ztest0) || rtIsNaN(ztest0))) {
    snorm = ztest0;
  }

  while ((m + 2 > 0) && (!(iter >= 75))) {
    kase = m + 1;
    do {
      exitg3 = 0;
      q = kase;
      if (kase == 0) {
        exitg3 = 1;
      } else {
        ztest0 = fabs(e[kase - 1]);
        if ((ztest0 <= (fabs(s[kase - 1]) + fabs(s[kase])) *
             2.2204460492503131E-16) || ((ztest0 <= 1.0020841800044864E-292) ||
             ((iter > 20) && (ztest0 <= 2.2204460492503131E-16 * snorm)))) {
          e[kase - 1] = 0.0;
          exitg3 = 1;
        } else {
          kase--;
        }
      }
    } while (exitg3 == 0);

    if (m + 1 == kase) {
      kase = 4;
    } else {
      qs = m + 2;
      k_ii = m + 2;
      exitg2 = false;
      while ((!exitg2) && (k_ii >= kase)) {
        qs = k_ii;
        if (k_ii == kase) {
          exitg2 = true;
        } else {
          ztest0 = 0.0;
          if (k_ii < m + 2) {
            ztest0 = fabs(e[k_ii - 1]);
          }

          if (k_ii > kase + 1) {
            ztest0 += fabs(e[k_ii - 2]);
          }

          ztest = fabs(s[k_ii - 1]);
          if ((ztest <= 2.2204460492503131E-16 * ztest0) || (ztest <=
               1.0020841800044864E-292)) {
            s[k_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            k_ii--;
          }
        }
      }

      if (qs == kase) {
        kase = 3;
      } else if (m + 2 == qs) {
        kase = 1;
      } else {
        kase = 2;
        q = qs;
      }
    }

    switch (kase) {
     case 1:
      ztest0 = e[m];
      e[m] = 0.0;
      for (qs = m; qs + 1 >= q + 1; qs--) {
        ztest = s[qs];
        ctrl_DP_xrotg(&ztest, &ztest0, &sqds, &smm1);
        s[qs] = ztest;
        if (qs + 1 > q + 1) {
          ztest0 = e[qs - 1] * -smm1;
          e[qs - 1] *= sqds;
        }

        ctrl_DP_xrot_ai(Vf, 1 + 12 * qs, 1 + 12 * (m + 1), sqds, smm1);
      }
      break;

     case 2:
      ztest0 = e[q - 1];
      e[q - 1] = 0.0;
      for (qs = q; qs + 1 <= m + 2; qs++) {
        ztest = s[qs];
        ctrl_DP_xrotg(&ztest, &ztest0, &sqds, &smm1);
        s[qs] = ztest;
        ztest0 = -smm1 * e[qs];
        e[qs] *= sqds;
        ctrl_DP_xrot_a(U, 1 + 3 * qs, 1 + 3 * (q - 1), sqds, smm1);
      }
      break;

     case 3:
      varargin_1[0] = fabs(s[m + 1]);
      varargin_1[1] = fabs(s[m]);
      varargin_1[2] = fabs(e[m]);
      varargin_1[3] = fabs(s[q]);
      varargin_1[4] = fabs(e[q]);
      qs = 1;
      ztest = varargin_1[0];
      if (rtIsNaN(varargin_1[0])) {
        kase = 2;
        exitg1 = false;
        while ((!exitg1) && (kase < 6)) {
          qs = kase;
          if (!rtIsNaN(varargin_1[kase - 1])) {
            ztest = varargin_1[kase - 1];
            exitg1 = true;
          } else {
            kase++;
          }
        }
      }

      if (qs < 5) {
        while (qs + 1 < 6) {
          if (varargin_1[qs] > ztest) {
            ztest = varargin_1[qs];
          }

          qs++;
        }
      }

      ztest0 = s[m + 1] / ztest;
      smm1 = s[m] / ztest;
      emm1 = e[m] / ztest;
      sqds = s[q] / ztest;
      smm1 = ((smm1 + ztest0) * (smm1 - ztest0) + emm1 * emm1) / 2.0;
      emm1 *= ztest0;
      emm1 *= emm1;
      if ((smm1 != 0.0) || (emm1 != 0.0)) {
        shift = sqrt(smm1 * smm1 + emm1);
        if (smm1 < 0.0) {
          shift = -shift;
        }

        shift = emm1 / (smm1 + shift);
      } else {
        shift = 0.0;
      }

      ztest0 = (sqds + ztest0) * (sqds - ztest0) + shift;
      ztest = e[q] / ztest * sqds;
      for (qs = q + 1; qs <= m + 1; qs++) {
        ctrl_DP_xrotg(&ztest0, &ztest, &sqds, &smm1);
        if (qs > q + 1) {
          e[qs - 2] = ztest0;
        }

        ztest0 = s[qs - 1] * sqds + e[qs - 1] * smm1;
        e[qs - 1] = e[qs - 1] * sqds - s[qs - 1] * smm1;
        ztest = smm1 * s[qs];
        s[qs] *= sqds;
        ctrl_DP_xrot_ai(Vf, 1 + 12 * (qs - 1), 1 + 12 * qs, sqds, smm1);
        ctrl_DP_xrotg(&ztest0, &ztest, &sqds, &smm1);
        s[qs - 1] = ztest0;
        ztest0 = e[qs - 1] * sqds + smm1 * s[qs];
        s[qs] = e[qs - 1] * -smm1 + sqds * s[qs];
        ztest = smm1 * e[qs];
        e[qs] *= sqds;
        if (qs < 3) {
          ctrl_DP_xrot_a(U, 1 + 3 * (qs - 1), 1 + 3 * qs, sqds, smm1);
        }
      }

      e[m] = ztest0;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_DP_xscal_jc(-1.0, Vf, 1 + 12 * q);
      }

      iter = q + 1;
      while ((q + 1 < 4) && (s[q] < s[iter])) {
        ztest0 = s[q];
        s[q] = s[iter];
        s[iter] = ztest0;
        ctrl_DP_xswap_am(Vf, 1 + 12 * q, 1 + 12 * (q + 1));
        if (q + 1 < 3) {
          ctrl_DP_xswap_a(U, 1 + 3 * q, 1 + 3 * (q + 1));
        }

        q = iter;
        iter++;
      }

      iter = 0;
      m--;
      break;
    }
  }

  for (m = 0; m < 3; m++) {
    work[m] = s[m];
    memcpy(&V[m * 12], &Vf[m * 12], 12U * sizeof(real_T));
  }

  memset(&S[0], 0, 9U * sizeof(real_T));
  S[0] = work[0];
  S[4] = work[1];
  S[8] = work[2];
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_svd_m4(const real_T A[36], real_T U[9], real_T S[9], real_T
  V[36])
{
  boolean_T b_p;
  int32_T k;
  b_p = true;
  for (k = 0; k < 36; k++) {
    if (b_p && ((!rtIsInf(A[k])) && (!rtIsNaN(A[k])))) {
    } else {
      b_p = false;
    }
  }

  if (b_p) {
    ctrl_DP_svd_m4e(A, U, S, V);
  } else {
    for (k = 0; k < 9; k++) {
      U[k] = (rtNaN);
      S[k] = 0.0;
    }

    S[0] = (rtNaN);
    S[4] = (rtNaN);
    S[8] = (rtNaN);
    for (k = 0; k < 36; k++) {
      V[k] = (rtNaN);
    }
  }
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
static void ctrl_DP_abs(const real_T x[2], real_T y[2])
{
  y[0] = fabs(x[0]);
  y[1] = fabs(x[1]);
}

/* Function for MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */
static void ctrl_DP_cosd(real_T *x)
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
static void ctrl_DP_sind(real_T *x)
{
  int8_T n;
  real_T c_x;
  real_T absx;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    c_x = (rtNaN);
  } else {
    c_x = rt_remd_snf(*x, 360.0);
    absx = fabs(c_x);
    if (absx > 180.0) {
      if (c_x > 0.0) {
        c_x -= 360.0;
      } else {
        c_x += 360.0;
      }

      absx = fabs(c_x);
    }

    if (absx <= 45.0) {
      c_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (c_x > 0.0) {
        c_x = (c_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        c_x = (c_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (c_x > 0.0) {
      c_x = (c_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      c_x = (c_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    if (n == 0) {
      c_x = sin(c_x);
    } else if (n == 1) {
      c_x = cos(c_x);
    } else if (n == -1) {
      c_x = -cos(c_x);
    } else {
      c_x = -sin(c_x);
    }
  }

  *x = c_x;
}

/* Function for MATLAB Function: '<S9>/MATLAB Function' */
static void ctrl_DP_cosd_k(real_T *x)
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
static void ctrl_DP_sind_n(real_T *x)
{
  int8_T n;
  real_T c_x;
  real_T absx;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    c_x = (rtNaN);
  } else {
    c_x = rt_remd_snf(*x, 360.0);
    absx = fabs(c_x);
    if (absx > 180.0) {
      if (c_x > 0.0) {
        c_x -= 360.0;
      } else {
        c_x += 360.0;
      }

      absx = fabs(c_x);
    }

    if (absx <= 45.0) {
      c_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (c_x > 0.0) {
        c_x = (c_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        c_x = (c_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (c_x > 0.0) {
      c_x = (c_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      c_x = (c_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    if (n == 0) {
      c_x = sin(c_x);
    } else if (n == 1) {
      c_x = cos(c_x);
    } else if (n == -1) {
      c_x = -cos(c_x);
    } else {
      c_x = -sin(c_x);
    }
  }

  *x = c_x;
}

/* Model output function */
void ctrl_DP_output(void)
{
  /* local block i/o variables */
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
  real_T rtb_T_r;
  real_T rtb_T_r_p;
  real_T rtb_T_r_l;
  real_T rtb_sys[12];
  real_T rtb_ImpSel_InsertedFor_reset_at;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  ZCEventType zcEvent;
  real_T s[6];
  real_T tc[3];
  real_T alpha[6];
  real_T K[6];
  real_T S_singular_cross[9];
  real_T T0[12];
  real_T c1[2];
  real_T U_singular[9];
  real_T b_V_singular[36];
  real_T varargin_1[2];
  static const int8_T d[12] = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 };

  static const int8_T e[12] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };

  boolean_T f[9];
  real_T e_0;
  real_T f_0;
  real_T i;
  real_T j;
  real_T k;
  real_T l;
  real_T m;
  real_T n;
  real_T o;
  real_T p;
  real_T q;
  real_T r;
  real_T s_0;
  real_T t;
  real_T v;
  real_T w;
  real_T x;
  real_T y;
  int32_T p2;
  int32_T p3;
  real_T absx31;
  real_T rtb_Row2;
  real_T rtb_Row1;
  real_T rtb_psi_dot;
  real_T rtb_TmpSignalConversionAtMatrix[3];
  real_T rtb_y[6];
  real_T rtb_ImpAsg_InsertedFor_commande[6];
  real_T rtb_Sum3[3];
  real_T rtb_Sum_b;
  real_T rtb_TmpSignalConversionAtSFun_o[6];
  real_T rtb_TmpSignalConversionAtSFun_b[10];
  real_T rtb_y_b[9];
  int32_T i_0;
  real_T c1_0[2];
  real_T c1_1[2];
  real_T c1_2[2];
  real_T c1_3[2];
  real_T c1_4[2];
  real_T c1_5[2];
  real_T d_0[36];
  boolean_T tmp[9];
  real_T rtb_y_1[18];
  real_T tmp_0[3];
  real_T rtb_TmpSignalConversionAtMatr_0[4];
  real_T rtb_TmpSignalConversionAtMatr_1[4];
  real_T rtb_TmpSignalConversionAtMatr_2[4];
  real_T rtb_TmpSignalConversionAtMatr_3[4];
  real_T rtb_TmpSignalConversionAtMatr_4[4];
  real_T rtb_TmpSignalConversionAtMatr_5[4];
  real_T rtb_TmpSignalConversionAtMatr_6[4];
  real_T rtb_TmpSignalConversionAtMatr_7[4];
  real_T rtb_TmpSignalConversionAtMatr_8[4];
  real_T rtb_y_2[18];
  int32_T ixstart;
  real_T V_singular[18];
  real_T b_V_singular_0[36];
  real_T rtb_psi_dot_0[4];
  real_T rtb_psi_dot_1[4];
  real_T rtb_psi_dot_2[4];
  real_T rtb_psi_dot_3[4];
  real_T rtb_psi_dot_4[4];
  real_T rtb_psi_dot_5[4];
  real_T rtb_psi_dot_6[4];
  real_T rtb_psi_dot_7[4];
  real_T rtb_psi_dot_8[4];
  real_T tmp_1[3];
  real_T tmp_2[3];
  real_T tmp_3[9];
  real_T absx31_0[18];
  real_T tmp_4[3];
  real_T rtb_y_m[3];
  real_T rtb_Row2_0[3];
  int32_T b_data[9];
  int32_T c_data[9];
  boolean_T f_1;
  real_T Alpha1_idx_2;
  real_T Alpha1_idx_3;
  real_T Alpha1_idx_4;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T exitg6;
  boolean_T exitg7;
  boolean_T exitg8;
  boolean_T exitg9;
  boolean_T exitg10;
  boolean_T exitg11;
  boolean_T exitg12;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* set solver stop time */
    if (!(ctrl_DP_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_DP_M->solverInfo,
                            ((ctrl_DP_M->Timing.clockTickH0 + 1) *
        ctrl_DP_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_DP_M->solverInfo,
                            ((ctrl_DP_M->Timing.clockTick0 + 1) *
        ctrl_DP_M->Timing.stepSize0 + ctrl_DP_M->Timing.clockTickH0 *
        ctrl_DP_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_DP_M)) {
    ctrl_DP_M->Timing.t[0] = rtsiGetT(&ctrl_DP_M->solverInfo);
  }

  /* MATLAB Function: '<S24>/MATLAB Function' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.K_p_x, ctrl_DP_B.K_p_y, ctrl_DP_B.K_p_psi,
    &ctrl_DP_B.sf_MATLABFunction);

  /* Gain: '<S7>/Gain' */
  ctrl_DP_B.Gain = ctrl_DP_P.Gain_Gain * ctrl_DP_B.x_m;

  /* Gain: '<S7>/Gain1' */
  ctrl_DP_B.Gain1 = ctrl_DP_P.Gain1_Gain * ctrl_DP_B.y_m;

  /* Gain: '<S7>/Gain5' */
  rtb_Row2 = ctrl_DP_P.Gain5_Gain * ctrl_DP_B.psi_m;

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Row2 > ctrl_DP_P.Saturation_UpperSat) {
    rtb_Row2 = ctrl_DP_P.Saturation_UpperSat;
  } else {
    if (rtb_Row2 < ctrl_DP_P.Saturation_LowerSat) {
      rtb_Row2 = ctrl_DP_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Signum: '<S7>/Sign' */
  if (rtb_Row2 < 0.0) {
    rtb_psi_dot = -1.0;
  } else if (rtb_Row2 > 0.0) {
    rtb_psi_dot = 1.0;
  } else if (rtb_Row2 == 0.0) {
    rtb_psi_dot = 0.0;
  } else {
    rtb_psi_dot = rtb_Row2;
  }

  /* End of Signum: '<S7>/Sign' */

  /* Gain: '<S7>/Gain6' */
  rtb_Row1 = ctrl_DP_P.Gain6_Gain * rtb_psi_dot;

  /* Sum: '<S7>/Sum1' */
  rtb_Row2 += rtb_Row1;

  /* Math: '<S7>/Math Function' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  rtb_Row2 = rt_remd_snf(rtb_Row2, ctrl_DP_P.Constant1_Value);

  /* Sum: '<S7>/Sum' */
  ctrl_DP_B.Sum = rtb_Row2 - rtb_Row1;

  /* Saturate: '<S17>/Saturation' */
  if (ctrl_DP_B.Sum > ctrl_DP_P.Saturation_UpperSat_l) {
    rtb_Row1 = ctrl_DP_P.Saturation_UpperSat_l;
  } else if (ctrl_DP_B.Sum < ctrl_DP_P.Saturation_LowerSat_i) {
    rtb_Row1 = ctrl_DP_P.Saturation_LowerSat_i;
  } else {
    rtb_Row1 = ctrl_DP_B.Sum;
  }

  /* End of Saturate: '<S17>/Saturation' */

  /* Signum: '<S17>/Sign' */
  if (rtb_Row1 < 0.0) {
    rtb_psi_dot = -1.0;
  } else if (rtb_Row1 > 0.0) {
    rtb_psi_dot = 1.0;
  } else if (rtb_Row1 == 0.0) {
    rtb_psi_dot = 0.0;
  } else {
    rtb_psi_dot = rtb_Row1;
  }

  /* End of Signum: '<S17>/Sign' */

  /* Gain: '<S17>/Gain' */
  rtb_Row2 = ctrl_DP_P.Gain_Gain_p * rtb_psi_dot;

  /* Sum: '<S17>/Sum1' */
  rtb_Row1 += rtb_Row2;

  /* Math: '<S17>/Math Function' incorporates:
   *  Constant: '<S17>/Constant'
   */
  rtb_Row1 = rt_remd_snf(rtb_Row1, ctrl_DP_P.Constant_Value);

  /* Sum: '<S17>/Sum' */
  rtb_Row1 -= rtb_Row2;

  /* MATLAB Function: '<S24>/MATLAB Function1' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.K_i_x, ctrl_DP_B.K_i_y, ctrl_DP_B.K_i_psi,
    &ctrl_DP_B.sf_MATLABFunction1);

  /* MATLAB Function: '<S24>/MATLAB Function2' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.K_d_x, ctrl_DP_B.K_d_y, ctrl_DP_B.K_d_psi,
    &ctrl_DP_B.sf_MATLABFunction2);
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* MATLAB Function: '<S26>/MATLAB Function2' incorporates:
     *  Constant: '<S26>/Constant6'
     *  Constant: '<S26>/Constant7'
     *  Constant: '<S26>/Constant8'
     */
    ctrl_DP_MATLABFunction(ctrl_DP_P.Constant6_Value, ctrl_DP_P.Constant7_Value,
      ctrl_DP_P.Constant8_Value, &ctrl_DP_B.sf_MATLABFunction2_a);
  }

  /* MATLAB Function: '<S25>/MATLAB Function' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.w_d_x, ctrl_DP_B.w_d_y, ctrl_DP_B.w_d_psi,
    &ctrl_DP_B.sf_MATLABFunction_d);

  /* Integrator: '<S18>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator1_Reset_ZCE,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (ctrl_DP_DW.Integrator1_IWORK != 0)) {
      ctrl_DP_X.Integrator1_CSTATE[0] = ctrl_DP_B.Gain;
      ctrl_DP_X.Integrator1_CSTATE[1] = ctrl_DP_B.Gain1;
      ctrl_DP_X.Integrator1_CSTATE[2] = ctrl_DP_B.Sum;
    }
  }

  ctrl_DP_B.Integrator1[0] = ctrl_DP_X.Integrator1_CSTATE[0];
  ctrl_DP_B.Integrator1[1] = ctrl_DP_X.Integrator1_CSTATE[1];
  ctrl_DP_B.Integrator1[2] = ctrl_DP_X.Integrator1_CSTATE[2];

  /* End of Integrator: '<S18>/Integrator1' */

  /* Saturate: '<S19>/Saturation' */
  if (ctrl_DP_B.Integrator1[2] > ctrl_DP_P.Saturation_UpperSat_p) {
    rtb_Row2 = ctrl_DP_P.Saturation_UpperSat_p;
  } else if (ctrl_DP_B.Integrator1[2] < ctrl_DP_P.Saturation_LowerSat_a) {
    rtb_Row2 = ctrl_DP_P.Saturation_LowerSat_a;
  } else {
    rtb_Row2 = ctrl_DP_B.Integrator1[2];
  }

  /* End of Saturate: '<S19>/Saturation' */

  /* Signum: '<S19>/Sign' */
  if (rtb_Row2 < 0.0) {
    rtb_psi_dot = -1.0;
  } else if (rtb_Row2 > 0.0) {
    rtb_psi_dot = 1.0;
  } else if (rtb_Row2 == 0.0) {
    rtb_psi_dot = 0.0;
  } else {
    rtb_psi_dot = rtb_Row2;
  }

  /* End of Signum: '<S19>/Sign' */

  /* Gain: '<S19>/Gain' */
  rtb_psi_dot *= ctrl_DP_P.Gain_Gain_a;

  /* Sum: '<S19>/Sum1' */
  rtb_Row2 += rtb_psi_dot;

  /* Math: '<S19>/Math Function' incorporates:
   *  Constant: '<S19>/Constant'
   */
  rtb_Row2 = rt_remd_snf(rtb_Row2, ctrl_DP_P.Constant_Value_j);

  /* Sum: '<S19>/Sum' */
  ctrl_DP_B.Sum_a = rtb_Row2 - rtb_psi_dot;

  /* SignalConversion: '<S18>/TmpSignal ConversionAtMatrix Multiply2Inport2' */
  rtb_TmpSignalConversionAtMatrix[0] = ctrl_DP_B.Integrator1[0];
  rtb_TmpSignalConversionAtMatrix[1] = ctrl_DP_B.Integrator1[1];
  rtb_TmpSignalConversionAtMatrix[2] = ctrl_DP_B.Sum_a;

  /* Sum: '<S13>/Sum2' incorporates:
   *  SignalConversion: '<S18>/TmpSignal ConversionAtMatrix Multiply2Inport2'
   */
  ctrl_DP_B.regulationerror[0] = ctrl_DP_B.Gain - ctrl_DP_B.Integrator1[0];
  ctrl_DP_B.regulationerror[1] = ctrl_DP_B.Gain1 - ctrl_DP_B.Integrator1[1];
  ctrl_DP_B.regulationerror[2] = ctrl_DP_B.Sum - ctrl_DP_B.Sum_a;

  /* Saturate: '<S16>/Saturation' */
  if (ctrl_DP_B.regulationerror[2] > ctrl_DP_P.Saturation_UpperSat_d) {
    rtb_psi_dot = ctrl_DP_P.Saturation_UpperSat_d;
  } else if (ctrl_DP_B.regulationerror[2] < ctrl_DP_P.Saturation_LowerSat_c) {
    rtb_psi_dot = ctrl_DP_P.Saturation_LowerSat_c;
  } else {
    rtb_psi_dot = ctrl_DP_B.regulationerror[2];
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* Signum: '<S16>/Sign' */
  if (rtb_psi_dot < 0.0) {
    rtb_Row2 = -1.0;
  } else if (rtb_psi_dot > 0.0) {
    rtb_Row2 = 1.0;
  } else if (rtb_psi_dot == 0.0) {
    rtb_Row2 = 0.0;
  } else {
    rtb_Row2 = rtb_psi_dot;
  }

  /* End of Signum: '<S16>/Sign' */

  /* Gain: '<S16>/Gain' */
  rtb_Row2 *= ctrl_DP_P.Gain_Gain_ag;

  /* Sum: '<S16>/Sum1' */
  rtb_psi_dot += rtb_Row2;

  /* Math: '<S16>/Math Function' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_psi_dot = rt_remd_snf(rtb_psi_dot, ctrl_DP_P.Constant_Value_l);

  /* Sum: '<S16>/Sum' */
  rtb_psi_dot -= rtb_Row2;

  /* SignalConversion: '<S13>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Fcn: '<S14>/Row1'
   *  Fcn: '<S14>/Row2'
   *  Fcn: '<S14>/Row3'
   */
  ctrl_DP_B.TmpSignalConversionAtMatrixMult[0] = cos(rtb_Row1) *
    ctrl_DP_B.regulationerror[0] + sin(rtb_Row1) * ctrl_DP_B.regulationerror[1];
  ctrl_DP_B.TmpSignalConversionAtMatrixMult[1] = -sin(rtb_Row1) *
    ctrl_DP_B.regulationerror[0] + cos(rtb_Row1) * ctrl_DP_B.regulationerror[1];
  ctrl_DP_B.TmpSignalConversionAtMatrixMult[2] = rtb_psi_dot;

  /* Integrator: '<S13>/Integrator' incorporates:
   *  Integrator: '<S5>/Integrator1'
   */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE[0] = ctrl_DP_P.Integrator_IC;
      ctrl_DP_X.Integrator_CSTATE[1] = ctrl_DP_P.Integrator_IC;
      ctrl_DP_X.Integrator_CSTATE[2] = ctrl_DP_P.Integrator_IC;
    }

    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_PrevZCX.Integrator1_Reset_ZCE_i,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator1_CSTATE_g[0] = ctrl_DP_P.Integrator1_IC[0];
      ctrl_DP_X.Integrator1_CSTATE_g[1] = ctrl_DP_P.Integrator1_IC[1];
      ctrl_DP_X.Integrator1_CSTATE_g[2] = ctrl_DP_P.Integrator1_IC[2];
    }
  }

  /* Integrator: '<S5>/Integrator1' */
  ctrl_DP_B.Integrator1_c[0] = ctrl_DP_X.Integrator1_CSTATE_g[0];
  ctrl_DP_B.Integrator1_c[1] = ctrl_DP_X.Integrator1_CSTATE_g[1];
  ctrl_DP_B.Integrator1_c[2] = ctrl_DP_X.Integrator1_CSTATE_g[2];

  /* Integrator: '<S18>/Integrator3' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator3_Reset_ZCE,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator3_CSTATE[0] = ctrl_DP_P.Integrator3_IC;
      ctrl_DP_X.Integrator3_CSTATE[1] = ctrl_DP_P.Integrator3_IC;
      ctrl_DP_X.Integrator3_CSTATE[2] = ctrl_DP_P.Integrator3_IC;
    }
  }

  /* Fcn: '<S15>/Row1' incorporates:
   *  SignalConversion: '<S18>/TmpSignal ConversionAtMatrix Multiply2Inport2'
   */
  rtb_TmpSignalConversionAtMatr_0[0] = ctrl_DP_B.Sum_a;
  rtb_TmpSignalConversionAtMatr_2[0] = ctrl_DP_B.Sum_a;

  /* Fcn: '<S15>/Row2' incorporates:
   *  SignalConversion: '<S18>/TmpSignal ConversionAtMatrix Multiply2Inport2'
   */
  rtb_TmpSignalConversionAtMatr_4[0] = ctrl_DP_B.Sum_a;
  rtb_TmpSignalConversionAtMatr_6[0] = ctrl_DP_B.Sum_a;
  for (i_0 = 0; i_0 < 3; i_0++) {
    /* Integrator: '<S18>/Integrator3' */
    ctrl_DP_B.Integrator3[i_0] = ctrl_DP_X.Integrator3_CSTATE[i_0];

    /* Sum: '<S13>/Sum3' incorporates:
     *  Product: '<S13>/Matrix Multiply'
     */
    tmp_0[i_0] = 0.0 - ((ctrl_DP_B.sf_MATLABFunction.y[i_0 + 3] *
                         ctrl_DP_B.TmpSignalConversionAtMatrixMult[1] +
                         ctrl_DP_B.sf_MATLABFunction.y[i_0] *
                         ctrl_DP_B.TmpSignalConversionAtMatrixMult[0]) +
                        ctrl_DP_B.sf_MATLABFunction.y[i_0 + 6] *
                        ctrl_DP_B.TmpSignalConversionAtMatrixMult[2]);

    /* Fcn: '<S15>/Row1' */
    rtb_TmpSignalConversionAtMatr_0[i_0 + 1] = ctrl_DP_B.Integrator3[i_0];
    rtb_TmpSignalConversionAtMatr_1[i_0 + 1] = ctrl_DP_B.Integrator3[i_0];
    rtb_TmpSignalConversionAtMatr_2[i_0 + 1] = ctrl_DP_B.Integrator3[i_0];
    rtb_TmpSignalConversionAtMatr_3[i_0 + 1] = ctrl_DP_B.Integrator3[i_0];

    /* Fcn: '<S15>/Row2' */
    rtb_TmpSignalConversionAtMatr_4[i_0 + 1] = ctrl_DP_B.Integrator3[i_0];
    rtb_TmpSignalConversionAtMatr_5[i_0 + 1] = ctrl_DP_B.Integrator3[i_0];
    rtb_TmpSignalConversionAtMatr_6[i_0 + 1] = ctrl_DP_B.Integrator3[i_0];
    rtb_TmpSignalConversionAtMatr_7[i_0 + 1] = ctrl_DP_B.Integrator3[i_0];

    /* Fcn: '<S15>/Row3' */
    rtb_TmpSignalConversionAtMatr_8[i_0 + 1] = ctrl_DP_B.Integrator3[i_0];

    /* Product: '<S13>/Matrix Multiply1' incorporates:
     *  Integrator: '<S13>/Integrator'
     *  Sum: '<S13>/Sum3'
     */
    rtb_y_m[i_0] = ctrl_DP_B.sf_MATLABFunction1.y[i_0 + 6] *
      ctrl_DP_X.Integrator_CSTATE[2] + (ctrl_DP_B.sf_MATLABFunction1.y[i_0 + 3] *
      ctrl_DP_X.Integrator_CSTATE[1] + ctrl_DP_B.sf_MATLABFunction1.y[i_0] *
      ctrl_DP_X.Integrator_CSTATE[0]);
  }

  /* Sum: '<S13>/Sum4' incorporates:
   *  Fcn: '<S15>/Row1'
   *  Fcn: '<S15>/Row2'
   *  Fcn: '<S15>/Row3'
   *  Product: '<S13>/Matrix Multiply2'
   */
  rtb_psi_dot = ctrl_DP_B.Integrator1_c[0] - (cos
    (rtb_TmpSignalConversionAtMatr_0[0]) * rtb_TmpSignalConversionAtMatr_1[1] +
    sin(rtb_TmpSignalConversionAtMatr_2[0]) * rtb_TmpSignalConversionAtMatr_3[2]);
  rtb_Row1 = ctrl_DP_B.Integrator1_c[1] - (-sin(rtb_TmpSignalConversionAtMatr_4
    [0]) * rtb_TmpSignalConversionAtMatr_5[1] + cos
    (rtb_TmpSignalConversionAtMatr_6[0]) * rtb_TmpSignalConversionAtMatr_7[2]);
  rtb_Row2 = ctrl_DP_B.Integrator1_c[2] - rtb_TmpSignalConversionAtMatr_8[3];

  /* Sum: '<S13>/Sum3' incorporates:
   *  Product: '<S13>/Matrix Multiply2'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_Sum3[i_0] = (tmp_0[i_0] - rtb_y_m[i_0]) -
      ((ctrl_DP_B.sf_MATLABFunction2.y[i_0 + 3] * rtb_Row1 +
        ctrl_DP_B.sf_MATLABFunction2.y[i_0] * rtb_psi_dot) +
       ctrl_DP_B.sf_MATLABFunction2.y[i_0 + 6] * rtb_Row2);
  }

  /* SignalConversion: '<S49>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S9>/angle between  [-180 180]'
   */
  rtb_TmpSignalConversionAtSFun_o[0] = ctrl_DP_B.thr_angle_1;
  rtb_TmpSignalConversionAtSFun_o[1] = ctrl_DP_B.thr_angle_2;
  rtb_TmpSignalConversionAtSFun_o[2] = ctrl_DP_B.thr_angle_3;
  rtb_TmpSignalConversionAtSFun_o[3] = ctrl_DP_B.thr_angle_4;
  rtb_TmpSignalConversionAtSFun_o[4] = ctrl_DP_B.thr_angle_5;
  rtb_TmpSignalConversionAtSFun_o[5] = ctrl_DP_B.thr_angle_6;

  /* MATLAB Function: '<S9>/angle between  [-180 180]' */
  /* MATLAB Function 'Thrust allocation/angle between  [-180 180]': '<S49>:1' */
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
  /* '<S49>:1:39' */
  /* '<S49>:1:40' */
  for (i_0 = 0; i_0 < 6; i_0++) {
    if (rtb_TmpSignalConversionAtSFun_o[i_0] < 0.0) {
      rtb_psi_dot = -1.0;
    } else if (rtb_TmpSignalConversionAtSFun_o[i_0] > 0.0) {
      rtb_psi_dot = 1.0;
    } else if (rtb_TmpSignalConversionAtSFun_o[i_0] == 0.0) {
      rtb_psi_dot = 0.0;
    } else {
      rtb_psi_dot = rtb_TmpSignalConversionAtSFun_o[i_0];
    }

    rtb_y[i_0] = rt_remd_snf(rtb_psi_dot * 3.1415926535897931 +
      rtb_TmpSignalConversionAtSFun_o[i_0], 6.2831853071795862);
    alpha[i_0] = rtb_TmpSignalConversionAtSFun_o[i_0] + 3.1415926535897931;
    if (rtb_TmpSignalConversionAtSFun_o[i_0] < 0.0) {
      s[i_0] = -1.0;
    } else if (rtb_TmpSignalConversionAtSFun_o[i_0] > 0.0) {
      s[i_0] = 1.0;
    } else if (rtb_TmpSignalConversionAtSFun_o[i_0] == 0.0) {
      s[i_0] = 0.0;
    } else {
      s[i_0] = rtb_TmpSignalConversionAtSFun_o[i_0];
    }
  }

  /* SignalConversion: '<S46>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S9>/MATLAB Function'
   */
  /*  s = sign(angle); */
  /* '<S49>:1:43' */
  rtb_TmpSignalConversionAtSFun_b[0] = rtb_Sum3[0];
  rtb_TmpSignalConversionAtSFun_b[1] = rtb_Sum3[1];
  rtb_TmpSignalConversionAtSFun_b[2] = rtb_Sum3[2];
  for (i_0 = 0; i_0 < 6; i_0++) {
    /* MATLAB Function: '<S9>/angle between  [-180 180]' */
    rtb_psi_dot = fabs(rt_remd_snf(alpha[i_0], 6.2831853071795862) /
                       6.2831853071795862);
    if (rtb_psi_dot > 0.0) {
      rtb_psi_dot = 1.0;
    } else {
      if (rtb_psi_dot == 0.0) {
        rtb_psi_dot = 0.0;
      }
    }

    s_0 = (rtb_psi_dot - 1.0) * 2.0 + s[i_0];
    if (s_0 < 0.0) {
      s_0 = -1.0;
    } else if (s_0 > 0.0) {
      s_0 = 1.0;
    } else {
      if (s_0 == 0.0) {
        s_0 = 0.0;
      }
    }

    /* SignalConversion: '<S46>/TmpSignal ConversionAt SFunction Inport1' incorporates:
     *  Gain: '<S48>/Gain'
     *  MATLAB Function: '<S9>/MATLAB Function'
     *  MATLAB Function: '<S9>/angle between  [-180 180]'
     */
    rtb_TmpSignalConversionAtSFun_b[i_0 + 3] = ctrl_DP_P.Gain_Gain_o *
      (rtb_y[i_0] - s_0 * 3.1415926535897931);
  }

  /* MATLAB Function: '<S9>/MATLAB Function' incorporates:
   *  Constant: '<S9>/C'
   *  Constant: '<S9>/X-position Thruster'
   *  Constant: '<S9>/Y-position Thruster'
   */
  /* MATLAB Function 'Thrust allocation/MATLAB Function': '<S46>:1' */
  /* '<S46>:1:87' */
  /* '<S46>:1:86' */
  /*  Complete system goes here! */
  /*  Allocating dimensions for faster computing */
  /*  Parameters thrusters */
  /* '<S46>:1:5' */
  tc[0] = rtb_TmpSignalConversionAtSFun_b[0];
  tc[1] = rtb_TmpSignalConversionAtSFun_b[1];
  tc[2] = rtb_TmpSignalConversionAtSFun_b[2];

  /* '<S46>:1:6' */
  alpha[0] = rtb_TmpSignalConversionAtSFun_b[3];
  alpha[1] = rtb_TmpSignalConversionAtSFun_b[4];
  alpha[2] = rtb_TmpSignalConversionAtSFun_b[5];
  alpha[3] = rtb_TmpSignalConversionAtSFun_b[6];
  alpha[4] = rtb_TmpSignalConversionAtSFun_b[7];
  alpha[5] = rtb_TmpSignalConversionAtSFun_b[8];

  /*  Constraints for Thruster-Thruster interaction. Can be seen in "Initfile" */
  /*  how they are found */
  /* '<S46>:1:10' */
  /* '<S46>:1:11' */
  /* '<S46>:1:12' */
  /* '<S46>:1:13' */
  /* '<S46>:1:14' */
  /* '<S46>:1:15' */
  if (((rtb_TmpSignalConversionAtSFun_b[3] < ctrl_DP_P.C[0] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[3] > ctrl_DP_P.C[6] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[3] > ctrl_DP_P.C[12] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[3] < ctrl_DP_P.C[18] - 0.1))) {
    /* '<S46>:1:21' */
    /* '<S46>:1:22' */
    K[0] = 0.0;
  } else {
    /* '<S46>:1:24' */
    K[0] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_b[4] > ctrl_DP_P.C[1] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[4] < ctrl_DP_P.C[7] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[4] > ctrl_DP_P.C[13] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[4] < ctrl_DP_P.C[19] + 0.1))) {
    /* '<S46>:1:27' */
    /* '<S46>:1:28' */
    K[1] = 0.0;
  } else {
    /* '<S46>:1:30' */
    K[1] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_b[5] < ctrl_DP_P.C[2] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[5] > ctrl_DP_P.C[8] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[5] < ctrl_DP_P.C[14] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[5] > ctrl_DP_P.C[20] - 0.1))) {
    /* '<S46>:1:33' */
    /* '<S46>:1:34' */
    K[2] = 0.0;
  } else {
    /* '<S46>:1:36' */
    K[2] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_b[6] > ctrl_DP_P.C[3] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[6] < ctrl_DP_P.C[9] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[6] < ctrl_DP_P.C[15] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[6] > ctrl_DP_P.C[21] + 0.1))) {
    /* '<S46>:1:39' */
    /* '<S46>:1:40' */
    K[3] = 0.0;
  } else {
    /* '<S46>:1:42' */
    K[3] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_b[7] < ctrl_DP_P.C[4] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[7] > ctrl_DP_P.C[10] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[7] < ctrl_DP_P.C[16] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[7] > ctrl_DP_P.C[22] + 0.1))) {
    /* '<S46>:1:45' */
    /* '<S46>:1:46' */
    K[4] = 0.0;
  } else {
    /* '<S46>:1:48' */
    K[4] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_b[8] > ctrl_DP_P.C[5] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[8] < ctrl_DP_P.C[11] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[8] > ctrl_DP_P.C[17] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[8] < ctrl_DP_P.C[23] - 0.1))) {
    /* '<S46>:1:51' */
    /* '<S46>:1:52' */
    K[5] = 0.0;
  } else {
    /* '<S46>:1:54' */
    K[5] = 1.0;
  }

  /*  number of thrusters */
  /*  Shells for faster computing */
  /* '<S46>:1:60' */
  /* '<S46>:1:61' */
  /* '<S46>:1:62' */
  /* '<S46>:1:64' */
  for (i_0 = 0; i_0 < 6; i_0++) {
    /* '<S46>:1:64' */
    /* '<S46>:1:65' */
    rtb_y[i_0] = alpha[i_0];
    ctrl_DP_cosd_k(&rtb_y[i_0]);

    /* Thrust in x-direction for cartesian */
    /* '<S46>:1:66' */
    s[i_0] = alpha[i_0];
    ctrl_DP_sind_n(&s[i_0]);

    /* Thrust in y-direction for cartesian */
    /* '<S46>:1:67' */
    rtb_Row2 = alpha[i_0];
    ctrl_DP_sind_n(&rtb_Row2);
    rtb_Row1 = alpha[i_0];
    ctrl_DP_cosd_k(&rtb_Row1);
    rtb_TmpSignalConversionAtSFun_o[i_0] = rtb_Row2 *
      ctrl_DP_P.XpositionThruster_Value[i_0] - rtb_Row1 *
      ctrl_DP_P.YpositionThruster_Value[i_0];
  }

  /* '<S46>:1:71' */
  /* '<S46>:1:72' */
  /* '<S46>:1:73' */
  ctrl_DP_diag(K, b_V_singular);
  for (i_0 = 0; i_0 < 6; i_0++) {
    rtb_y_2[3 * i_0] = rtb_y[i_0];
    rtb_y_2[1 + 3 * i_0] = s[i_0];
    rtb_y_2[2 + 3 * i_0] = rtb_TmpSignalConversionAtSFun_o[i_0];
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    for (ixstart = 0; ixstart < 3; ixstart++) {
      rtb_y_1[ixstart + 3 * i_0] = 0.0;
      for (p2 = 0; p2 < 6; p2++) {
        rtb_y_1[ixstart + 3 * i_0] += rtb_y_2[3 * p2 + ixstart] * b_V_singular[6
          * i_0 + p2];
      }
    }
  }

  ctrl_DP_svd(rtb_y_1, U_singular, S_singular_cross, rtb_y_2);

  /* '<S46>:1:74' */
  for (i_0 = 0; i_0 < 9; i_0++) {
    S_singular_cross[i_0] = 1.0 / S_singular_cross[i_0];
  }

  /* '<S46>:1:75' */
  ctrl_DP_isfinite(S_singular_cross, tmp);
  i_0 = 0;
  for (ixstart = 0; ixstart < 9; ixstart++) {
    f_1 = !tmp[ixstart];
    if (f_1) {
      i_0++;
    }

    f[ixstart] = f_1;
  }

  p2 = i_0;
  i_0 = 0;
  for (ixstart = 0; ixstart < 9; ixstart++) {
    if (f[ixstart]) {
      b_data[i_0] = ixstart + 1;
      i_0++;
    }
  }

  /* '<S46>:1:75' */
  for (i_0 = 0; i_0 < p2; i_0++) {
    S_singular_cross[b_data[i_0] - 1] = 0.0;
  }

  if (S_singular_cross[8] > 10.0 * S_singular_cross[4]) {
    /* '<S46>:1:76' */
    /* '<S46>:1:77' */
    S_singular_cross[8] = 0.0;
  }

  /* '<S46>:1:80' */
  /* '<S46>:1:82' */
  for (i_0 = 0; i_0 < 6; i_0++) {
    for (ixstart = 0; ixstart < 3; ixstart++) {
      rtb_y_1[i_0 + 6 * ixstart] = 0.0;
      rtb_y_1[i_0 + 6 * ixstart] += S_singular_cross[3 * ixstart] * rtb_y_2[i_0];
      rtb_y_1[i_0 + 6 * ixstart] += S_singular_cross[3 * ixstart + 1] *
        rtb_y_2[i_0 + 6];
      rtb_y_1[i_0 + 6 * ixstart] += S_singular_cross[3 * ixstart + 2] *
        rtb_y_2[i_0 + 12];
    }

    rtb_y[i_0] = 0.0;
    for (ixstart = 0; ixstart < 3; ixstart++) {
      V_singular[i_0 + 6 * ixstart] = 0.0;
      V_singular[i_0 + 6 * ixstart] += rtb_y_1[i_0] * U_singular[ixstart];
      V_singular[i_0 + 6 * ixstart] += rtb_y_1[i_0 + 6] * U_singular[ixstart + 3];
      V_singular[i_0 + 6 * ixstart] += rtb_y_1[i_0 + 12] * U_singular[ixstart +
        6];
      rtb_y[i_0] += V_singular[6 * ixstart + i_0] * tc[ixstart];
    }
  }

  /*  Optimized Thrust */
  /* '<S46>:1:86' */
  /* '<S46>:1:91' */
  for (i_0 = 0; i_0 < 12; i_0++) {
    d_0[3 * i_0] = d[i_0];
    d_0[1 + 3 * i_0] = e[i_0];
  }

  d_0[2] = ctrl_DP_P.YpositionThruster_Value[0];
  d_0[5] = ctrl_DP_P.XpositionThruster_Value[0];
  d_0[8] = ctrl_DP_P.YpositionThruster_Value[1];
  d_0[11] = ctrl_DP_P.XpositionThruster_Value[1];
  d_0[14] = ctrl_DP_P.YpositionThruster_Value[2];
  d_0[17] = ctrl_DP_P.XpositionThruster_Value[2];
  d_0[20] = ctrl_DP_P.YpositionThruster_Value[3];
  d_0[23] = ctrl_DP_P.XpositionThruster_Value[3];
  d_0[26] = ctrl_DP_P.YpositionThruster_Value[4];
  d_0[29] = ctrl_DP_P.XpositionThruster_Value[4];
  d_0[32] = ctrl_DP_P.YpositionThruster_Value[5];
  d_0[35] = ctrl_DP_P.XpositionThruster_Value[5];
  ctrl_DP_svd_m4(d_0, U_singular, S_singular_cross, b_V_singular);

  /* '<S46>:1:92' */
  for (i_0 = 0; i_0 < 9; i_0++) {
    S_singular_cross[i_0] = 1.0 / S_singular_cross[i_0];
  }

  /* '<S46>:1:93' */
  ctrl_DP_isfinite(S_singular_cross, tmp);
  i_0 = 0;
  for (ixstart = 0; ixstart < 9; ixstart++) {
    f_1 = !tmp[ixstart];
    if (f_1) {
      i_0++;
    }

    f[ixstart] = f_1;
  }

  p2 = i_0;
  i_0 = 0;
  for (ixstart = 0; ixstart < 9; ixstart++) {
    if (f[ixstart]) {
      c_data[i_0] = ixstart + 1;
      i_0++;
    }
  }

  /* '<S46>:1:93' */
  for (i_0 = 0; i_0 < p2; i_0++) {
    S_singular_cross[c_data[i_0] - 1] = 0.0;
  }

  if (S_singular_cross[8] > 2.0 * S_singular_cross[4]) {
    /* '<S46>:1:94' */
    /* '<S46>:1:95' */
    S_singular_cross[8] = 0.0;
  }

  /* '<S46>:1:97' */
  for (i_0 = 0; i_0 < 12; i_0++) {
    for (ixstart = 0; ixstart < 3; ixstart++) {
      d_0[i_0 + 12 * ixstart] = 0.0;
      d_0[i_0 + 12 * ixstart] += S_singular_cross[3 * ixstart] *
        b_V_singular[i_0];
      d_0[i_0 + 12 * ixstart] += S_singular_cross[3 * ixstart + 1] *
        b_V_singular[i_0 + 12];
      d_0[i_0 + 12 * ixstart] += S_singular_cross[3 * ixstart + 2] *
        b_V_singular[i_0 + 24];
    }

    T0[i_0] = 0.0;
    for (ixstart = 0; ixstart < 3; ixstart++) {
      b_V_singular_0[i_0 + 12 * ixstart] = 0.0;
      b_V_singular_0[i_0 + 12 * ixstart] += d_0[i_0] * U_singular[ixstart];
      b_V_singular_0[i_0 + 12 * ixstart] += d_0[i_0 + 12] * U_singular[ixstart +
        3];
      b_V_singular_0[i_0 + 12 * ixstart] += d_0[i_0 + 24] * U_singular[ixstart +
        6];
      T0[i_0] += b_V_singular_0[12 * ixstart + i_0] * tc[ixstart];
    }
  }

  /* '<S46>:1:99' */
  K[0] = 57.295779513082323 * rt_atan2d_snf(T0[1], T0[0]);
  K[1] = 57.295779513082323 * rt_atan2d_snf(T0[3], T0[2]);
  K[2] = 57.295779513082323 * rt_atan2d_snf(T0[5], T0[4]);
  K[3] = 57.295779513082323 * rt_atan2d_snf(T0[7], T0[6]);
  K[4] = 57.295779513082323 * rt_atan2d_snf(T0[9], T0[8]);
  K[5] = 57.295779513082323 * rt_atan2d_snf(T0[11], T0[10]);

  /*  Constraints */
  /*  Thruster 1 OK */
  /* C1 = [151 130 -151 -130 ]; */
  if (((K[0] < ctrl_DP_P.C[0]) && (K[0] > ctrl_DP_P.C[6]) && (rtb_y[0] > 0.0)) ||
      ((K[0] < ctrl_DP_P.C[0]) && (K[0] > ctrl_DP_P.C[6]) && (rtb_y[0] < 0.0)))
  {
    /* '<S46>:1:105' */
    /* '<S46>:1:106' */
    c1[0] = ctrl_DP_P.C[0];
    c1[1] = ctrl_DP_P.C[6];

    /* '<S46>:1:107' */
    c1_5[0] = ctrl_DP_P.C[0] - K[0];
    c1_5[1] = ctrl_DP_P.C[6] - K[0];
    ctrl_DP_abs(c1_5, varargin_1);
    i_0 = 1;
    rtb_psi_dot = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p2 = 2;
      exitg12 = false;
      while ((!exitg12) && (p2 < 3)) {
        i_0 = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_psi_dot = varargin_1[1];
          ixstart = 1;
          exitg12 = true;
        } else {
          p2 = 3;
        }
      }
    }

    if ((i_0 < 2) && (varargin_1[1] < rtb_psi_dot)) {
      ixstart = 1;
    }

    /* '<S46>:1:108' */
    rtb_Row1 = c1[ixstart];
  } else if (((K[0] > ctrl_DP_P.C[12]) && (K[0] < ctrl_DP_P.C[18]) && (rtb_y[0] >
    0.0)) || ((K[0] > ctrl_DP_P.C[12]) && (K[0] < ctrl_DP_P.C[18]) && (rtb_y[0] <
    0.0))) {
    /* '<S46>:1:109' */
    /* '<S46>:1:110' */
    c1[0] = ctrl_DP_P.C[12];
    c1[1] = ctrl_DP_P.C[18];

    /* '<S46>:1:111' */
    c1_5[0] = ctrl_DP_P.C[12] - K[0];
    c1_5[1] = ctrl_DP_P.C[18] - K[0];
    ctrl_DP_abs(c1_5, varargin_1);
    ixstart = 1;
    rtb_psi_dot = varargin_1[0];
    i_0 = 0;
    if (rtIsNaN(varargin_1[0])) {
      p2 = 2;
      exitg11 = false;
      while ((!exitg11) && (p2 < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_psi_dot = varargin_1[1];
          i_0 = 1;
          exitg11 = true;
        } else {
          p2 = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < rtb_psi_dot)) {
      i_0 = 1;
    }

    /* '<S46>:1:112' */
    rtb_Row1 = c1[i_0];
  } else {
    /* '<S46>:1:114' */
    rtb_Row1 = K[0];
  }

  if (((rtb_TmpSignalConversionAtSFun_b[3] < ctrl_DP_P.C[0] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[3] > ctrl_DP_P.C[6] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[3] > ctrl_DP_P.C[12] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[3] < ctrl_DP_P.C[18] - 0.1))) {
    /* '<S46>:1:116' */
    /* '<S46>:1:117' */
    rtb_y[0] = 0.0;
  } else {
    /* '<S46>:1:119' */
  }

  /*  Thruster 2  */
  /* C2 = [-99.85 -80.15 -50 -29]; */
  if (((K[1] < ctrl_DP_P.C[1]) && (K[1] > ctrl_DP_P.C[7]) && (rtb_y[1] > 0.0)) ||
      ((K[1] < ctrl_DP_P.C[1]) && (K[1] > ctrl_DP_P.C[7]) && (rtb_y[1] < 0.0)))
  {
    /* '<S46>:1:124' */
    /* '<S46>:1:125' */
    c1[0] = ctrl_DP_P.C[1];
    c1[1] = ctrl_DP_P.C[7];

    /* '<S46>:1:126' */
    c1_4[0] = ctrl_DP_P.C[1] - K[1];
    c1_4[1] = ctrl_DP_P.C[7] - K[1];
    ctrl_DP_abs(c1_4, varargin_1);
    i_0 = 1;
    rtb_psi_dot = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p2 = 2;
      exitg10 = false;
      while ((!exitg10) && (p2 < 3)) {
        i_0 = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_psi_dot = varargin_1[1];
          ixstart = 1;
          exitg10 = true;
        } else {
          p2 = 3;
        }
      }
    }

    if ((i_0 < 2) && (varargin_1[1] < rtb_psi_dot)) {
      ixstart = 1;
    }

    /* '<S46>:1:127' */
    rtb_Row2 = c1[ixstart];
  } else if (((K[1] < ctrl_DP_P.C[13]) && (K[1] > ctrl_DP_P.C[19]) && (rtb_y[1] >
    0.0)) || ((K[1] < ctrl_DP_P.C[13]) && (K[1] > ctrl_DP_P.C[19]) && (rtb_y[1] <
    0.0))) {
    /* '<S46>:1:128' */
    /* '<S46>:1:129' */
    c1[0] = ctrl_DP_P.C[13];
    c1[1] = ctrl_DP_P.C[19];

    /* '<S46>:1:130' */
    c1_4[0] = ctrl_DP_P.C[13] - K[1];
    c1_4[1] = ctrl_DP_P.C[19] - K[1];
    ctrl_DP_abs(c1_4, varargin_1);
    i_0 = 1;
    rtb_psi_dot = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p2 = 2;
      exitg9 = false;
      while ((!exitg9) && (p2 < 3)) {
        i_0 = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_psi_dot = varargin_1[1];
          ixstart = 1;
          exitg9 = true;
        } else {
          p2 = 3;
        }
      }
    }

    if ((i_0 < 2) && (varargin_1[1] < rtb_psi_dot)) {
      ixstart = 1;
    }

    /* '<S46>:1:131' */
    rtb_Row2 = c1[ixstart];
  } else {
    /* '<S46>:1:133' */
    rtb_Row2 = K[1];
  }

  if (((rtb_TmpSignalConversionAtSFun_b[4] < ctrl_DP_P.C[1] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[4] > ctrl_DP_P.C[7] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[4] < ctrl_DP_P.C[13] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[4] > ctrl_DP_P.C[19] + 0.1))) {
    /* '<S46>:1:135' */
    /* '<S46>:1:136' */
    rtb_y[1] = 0.0;
  } else {
    /* '<S46>:1:138' */
  }

  /*  Thruster 3  */
  /*  C3 = [99.85 80.15 50 29];  */
  if (((K[2] > ctrl_DP_P.C[2]) && (K[2] < ctrl_DP_P.C[8]) && (rtb_y[2] > 0.0)) ||
      ((K[2] > ctrl_DP_P.C[2]) && (K[2] < ctrl_DP_P.C[8]) && (rtb_y[2] < 0.0)))
  {
    /* '<S46>:1:144' */
    /* '<S46>:1:145' */
    c1[0] = ctrl_DP_P.C[2];
    c1[1] = ctrl_DP_P.C[8];

    /* '<S46>:1:146' */
    c1_3[0] = ctrl_DP_P.C[2] - K[2];
    c1_3[1] = ctrl_DP_P.C[8] - K[2];
    ctrl_DP_abs(c1_3, varargin_1);
    i_0 = 1;
    rtb_psi_dot = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p2 = 2;
      exitg8 = false;
      while ((!exitg8) && (p2 < 3)) {
        i_0 = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_psi_dot = varargin_1[1];
          ixstart = 1;
          exitg8 = true;
        } else {
          p2 = 3;
        }
      }
    }

    if ((i_0 < 2) && (varargin_1[1] < rtb_psi_dot)) {
      ixstart = 1;
    }

    /* '<S46>:1:147' */
    Alpha1_idx_2 = c1[ixstart];
  } else if (((K[2] > ctrl_DP_P.C[14]) && (K[2] < ctrl_DP_P.C[20]) && (rtb_y[2] >
    0.0)) || ((K[2] > ctrl_DP_P.C[14]) && (K[2] < ctrl_DP_P.C[20]) && (rtb_y[2] <
    0.0))) {
    /* '<S46>:1:148' */
    /* '<S46>:1:149' */
    c1[0] = ctrl_DP_P.C[14];
    c1[1] = ctrl_DP_P.C[20];

    /* '<S46>:1:150' */
    c1_3[0] = ctrl_DP_P.C[14] - K[2];
    c1_3[1] = ctrl_DP_P.C[20] - K[2];
    ctrl_DP_abs(c1_3, varargin_1);
    i_0 = 1;
    rtb_psi_dot = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p2 = 2;
      exitg7 = false;
      while ((!exitg7) && (p2 < 3)) {
        i_0 = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_psi_dot = varargin_1[1];
          ixstart = 1;
          exitg7 = true;
        } else {
          p2 = 3;
        }
      }
    }

    if ((i_0 < 2) && (varargin_1[1] < rtb_psi_dot)) {
      ixstart = 1;
    }

    /* '<S46>:1:151' */
    Alpha1_idx_2 = c1[ixstart];
  } else {
    /* '<S46>:1:153' */
    Alpha1_idx_2 = K[2];
  }

  if (((rtb_TmpSignalConversionAtSFun_b[5] > ctrl_DP_P.C[2] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[5] < ctrl_DP_P.C[8] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[5] > ctrl_DP_P.C[14] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[5] < ctrl_DP_P.C[20] - 0.1))) {
    /* '<S46>:1:155' */
    /* '<S46>:1:156' */
    rtb_y[2] = 0.0;
  } else {
    /* '<S46>:1:158' */
  }

  /*  Thruster 4 OK */
  /* C4 = [-52.8 -34.2 52.8 34.2];  */
  if (((K[3] > ctrl_DP_P.C[3]) && (K[3] < ctrl_DP_P.C[9]) && (rtb_y[3] > 0.0)) ||
      ((K[3] > ctrl_DP_P.C[3]) && (K[3] < ctrl_DP_P.C[9]) && (rtb_y[3] < 0.0)))
  {
    /* '<S46>:1:163' */
    /* '<S46>:1:164' */
    c1[0] = ctrl_DP_P.C[3];
    c1[1] = ctrl_DP_P.C[9];

    /* '<S46>:1:165' */
    c1_2[0] = ctrl_DP_P.C[3] - K[3];
    c1_2[1] = ctrl_DP_P.C[9] - K[3];
    ctrl_DP_abs(c1_2, varargin_1);
    i_0 = 1;
    rtb_psi_dot = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p2 = 2;
      exitg6 = false;
      while ((!exitg6) && (p2 < 3)) {
        i_0 = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_psi_dot = varargin_1[1];
          ixstart = 1;
          exitg6 = true;
        } else {
          p2 = 3;
        }
      }
    }

    if ((i_0 < 2) && (varargin_1[1] < rtb_psi_dot)) {
      ixstart = 1;
    }

    /* '<S46>:1:166' */
    Alpha1_idx_3 = c1[ixstart];
  } else if (((K[3] < ctrl_DP_P.C[15]) && (K[3] > ctrl_DP_P.C[21]) && (rtb_y[3] >
    0.0)) || ((K[3] < ctrl_DP_P.C[15]) && (K[3] > ctrl_DP_P.C[21]) && (rtb_y[3] <
    0.0))) {
    /* '<S46>:1:167' */
    /* '<S46>:1:168' */
    c1[0] = ctrl_DP_P.C[15];
    c1[1] = ctrl_DP_P.C[21];

    /* '<S46>:1:169' */
    c1_2[0] = ctrl_DP_P.C[15] - K[3];
    c1_2[1] = ctrl_DP_P.C[21] - K[3];
    ctrl_DP_abs(c1_2, varargin_1);
    i_0 = 1;
    rtb_psi_dot = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p2 = 2;
      exitg5 = false;
      while ((!exitg5) && (p2 < 3)) {
        i_0 = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_psi_dot = varargin_1[1];
          ixstart = 1;
          exitg5 = true;
        } else {
          p2 = 3;
        }
      }
    }

    if ((i_0 < 2) && (varargin_1[1] < rtb_psi_dot)) {
      ixstart = 1;
    }

    /* '<S46>:1:170' */
    Alpha1_idx_3 = c1[ixstart];
  } else {
    /* '<S46>:1:172' */
    Alpha1_idx_3 = K[3];
  }

  if (((rtb_TmpSignalConversionAtSFun_b[6] > ctrl_DP_P.C[3] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[6] < ctrl_DP_P.C[9] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[6] < ctrl_DP_P.C[15] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[6] > ctrl_DP_P.C[21] + 0.1))) {
    /* '<S46>:1:174' */
    /* '<S46>:1:175' */
    rtb_y[3] = 0.0;
  } else {
    /* '<S46>:1:177' */
  }

  /*  Thruster 5 */
  /* C5 = [-98.25 -81.75 -145.8 -127.2]; */
  if (((K[4] < ctrl_DP_P.C[4]) && (K[4] > ctrl_DP_P.C[10]) && (rtb_y[4] > 0.0)) ||
      ((K[4] < ctrl_DP_P.C[4]) && (K[4] > ctrl_DP_P.C[10]) && (rtb_y[4] < 0.0)))
  {
    /* '<S46>:1:182' */
    /* '<S46>:1:183' */
    c1[0] = ctrl_DP_P.C[4];
    c1[1] = ctrl_DP_P.C[10];

    /* '<S46>:1:184' */
    c1_1[0] = ctrl_DP_P.C[4] - K[4];
    c1_1[1] = ctrl_DP_P.C[10] - K[4];
    ctrl_DP_abs(c1_1, varargin_1);
    i_0 = 1;
    rtb_psi_dot = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p2 = 2;
      exitg4 = false;
      while ((!exitg4) && (p2 < 3)) {
        i_0 = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_psi_dot = varargin_1[1];
          ixstart = 1;
          exitg4 = true;
        } else {
          p2 = 3;
        }
      }
    }

    if ((i_0 < 2) && (varargin_1[1] < rtb_psi_dot)) {
      ixstart = 1;
    }

    /* '<S46>:1:185' */
    Alpha1_idx_4 = c1[ixstart];
  } else if (((K[4] < ctrl_DP_P.C[16]) && (K[4] > ctrl_DP_P.C[22]) && (rtb_y[4] >
    0.0)) || ((K[4] < ctrl_DP_P.C[16]) && (K[4] > ctrl_DP_P.C[22]) && (rtb_y[4] <
    0.0))) {
    /* '<S46>:1:186' */
    /* '<S46>:1:187' */
    c1[0] = ctrl_DP_P.C[16];
    c1[1] = ctrl_DP_P.C[22];

    /* '<S46>:1:188' */
    c1_1[0] = ctrl_DP_P.C[16] - K[4];
    c1_1[1] = ctrl_DP_P.C[22] - K[4];
    ctrl_DP_abs(c1_1, varargin_1);
    i_0 = 1;
    rtb_psi_dot = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p2 = 2;
      exitg3 = false;
      while ((!exitg3) && (p2 < 3)) {
        i_0 = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_psi_dot = varargin_1[1];
          ixstart = 1;
          exitg3 = true;
        } else {
          p2 = 3;
        }
      }
    }

    if ((i_0 < 2) && (varargin_1[1] < rtb_psi_dot)) {
      ixstart = 1;
    }

    /* '<S46>:1:189' */
    Alpha1_idx_4 = c1[ixstart];
  } else {
    /* '<S46>:1:191' */
    Alpha1_idx_4 = K[4];
  }

  if (((rtb_TmpSignalConversionAtSFun_b[7] < ctrl_DP_P.C[4] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[7] > ctrl_DP_P.C[10] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[7] < ctrl_DP_P.C[16] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[7] > ctrl_DP_P.C[22] + 0.1))) {
    /* '<S46>:1:193' */
    /* '<S46>:1:194' */
    rtb_y[4] = 0.0;
  } else {
    /* '<S46>:1:196' */
  }

  /*  Thruster 6 */
  /* C6 = [98.75 81.75 145.8 127.2]; */
  if (((K[5] > ctrl_DP_P.C[5]) && (K[5] < ctrl_DP_P.C[11]) && (rtb_y[5] > 0.0)) ||
      ((K[5] > ctrl_DP_P.C[5]) && (K[5] < ctrl_DP_P.C[11]) && (rtb_y[5] < 0.0)))
  {
    /* '<S46>:1:201' */
    /* '<S46>:1:202' */
    c1[0] = ctrl_DP_P.C[5];
    c1[1] = ctrl_DP_P.C[11];

    /* '<S46>:1:203' */
    c1_0[0] = ctrl_DP_P.C[5] - K[5];
    c1_0[1] = ctrl_DP_P.C[11] - K[5];
    ctrl_DP_abs(c1_0, varargin_1);
    i_0 = 1;
    rtb_psi_dot = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p2 = 2;
      exitg2 = false;
      while ((!exitg2) && (p2 < 3)) {
        i_0 = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_psi_dot = varargin_1[1];
          ixstart = 1;
          exitg2 = true;
        } else {
          p2 = 3;
        }
      }
    }

    if ((i_0 < 2) && (varargin_1[1] < rtb_psi_dot)) {
      ixstart = 1;
    }

    /* '<S46>:1:204' */
    rtb_psi_dot = c1[ixstart];
  } else if (((K[5] > ctrl_DP_P.C[17]) && (K[5] < ctrl_DP_P.C[23]) && (rtb_y[5] >
    0.0)) || ((K[5] > ctrl_DP_P.C[17]) && (K[5] < ctrl_DP_P.C[23]) && (rtb_y[5] <
    0.0))) {
    /* '<S46>:1:205' */
    /* '<S46>:1:206' */
    c1[0] = ctrl_DP_P.C[17];
    c1[1] = ctrl_DP_P.C[23];

    /* '<S46>:1:207' */
    c1_0[0] = ctrl_DP_P.C[17] - K[5];
    c1_0[1] = ctrl_DP_P.C[23] - K[5];
    ctrl_DP_abs(c1_0, varargin_1);
    i_0 = 1;
    rtb_psi_dot = varargin_1[0];
    ixstart = 0;
    if (rtIsNaN(varargin_1[0])) {
      p2 = 2;
      exitg1 = false;
      while ((!exitg1) && (p2 < 3)) {
        i_0 = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_psi_dot = varargin_1[1];
          ixstart = 1;
          exitg1 = true;
        } else {
          p2 = 3;
        }
      }
    }

    if ((i_0 < 2) && (varargin_1[1] < rtb_psi_dot)) {
      ixstart = 1;
    }

    /* '<S46>:1:208' */
    rtb_psi_dot = c1[ixstart];
  } else {
    /* '<S46>:1:210' */
    rtb_psi_dot = K[5];
  }

  if (((rtb_TmpSignalConversionAtSFun_b[8] > ctrl_DP_P.C[5] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[8] < ctrl_DP_P.C[11] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[8] > ctrl_DP_P.C[17] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[8] < ctrl_DP_P.C[23] - 0.1))) {
    /* '<S46>:1:212' */
    /* '<S46>:1:213' */
    rtb_y[5] = 0.0;
  } else {
    /* '<S46>:1:215' */
  }

  /*  Thruster 2&3  */
  if (rtb_Row2 == ctrl_DP_P.C[7]) {
    /* '<S46>:1:219' */
    /* '<S46>:1:220' */
    Alpha1_idx_2 = K[1] - (ctrl_DP_P.C[7] - K[1]);
  } else if (rtb_Row2 == ctrl_DP_P.C[1]) {
    /* '<S46>:1:221' */
    /* '<S46>:1:222' */
    Alpha1_idx_2 = K[1] - (ctrl_DP_P.C[1] - K[1]);
  } else if (rtb_Row2 == ctrl_DP_P.C[13]) {
    /* '<S46>:1:223' */
    /* '<S46>:1:224' */
    Alpha1_idx_2 = K[1] - (ctrl_DP_P.C[13] - K[1]);
  } else if (rtb_Row2 == ctrl_DP_P.C[19]) {
    /* '<S46>:1:225' */
    /* '<S46>:1:226' */
    Alpha1_idx_2 = K[1] - (ctrl_DP_P.C[19] - K[1]);
  } else if (Alpha1_idx_2 == ctrl_DP_P.C[8]) {
    /* '<S46>:1:228' */
    /* '<S46>:1:229' */
    rtb_Row2 = K[2] - (ctrl_DP_P.C[8] - K[2]);
  } else if (Alpha1_idx_2 == ctrl_DP_P.C[2]) {
    /* '<S46>:1:230' */
    /* '<S46>:1:231' */
    rtb_Row2 = K[2] - (ctrl_DP_P.C[2] - K[2]);
  } else if (Alpha1_idx_2 == ctrl_DP_P.C[14]) {
    /* '<S46>:1:232' */
    /* '<S46>:1:233' */
    rtb_Row2 = K[2] - (ctrl_DP_P.C[14] - K[2]);
  } else {
    if (Alpha1_idx_2 == ctrl_DP_P.C[20]) {
      /* '<S46>:1:234' */
      /* '<S46>:1:235' */
      rtb_Row2 = K[2] - (ctrl_DP_P.C[20] - K[2]);
    }
  }

  /*  Thruster 5&6 */
  if (Alpha1_idx_4 == ctrl_DP_P.C[10]) {
    /* '<S46>:1:239' */
    /* '<S46>:1:240' */
    rtb_psi_dot = K[4] - (ctrl_DP_P.C[10] - K[4]);
  } else if (Alpha1_idx_4 == ctrl_DP_P.C[4]) {
    /* '<S46>:1:241' */
    /* '<S46>:1:242' */
    rtb_psi_dot = K[4] - (ctrl_DP_P.C[4] - K[4]);
  } else if (Alpha1_idx_4 == ctrl_DP_P.C[16]) {
    /* '<S46>:1:243' */
    /* '<S46>:1:244' */
    rtb_psi_dot = K[4] - (ctrl_DP_P.C[16] - K[4]);
  } else if (Alpha1_idx_4 == ctrl_DP_P.C[22]) {
    /* '<S46>:1:245' */
    /* '<S46>:1:246' */
    rtb_psi_dot = K[4] - (ctrl_DP_P.C[22] - K[4]);
  } else if (rtb_psi_dot == ctrl_DP_P.C[11]) {
    /* '<S46>:1:248' */
    /* '<S46>:1:249' */
    Alpha1_idx_4 = K[5] - (ctrl_DP_P.C[11] - K[5]);
  } else if (rtb_psi_dot == ctrl_DP_P.C[5]) {
    /* '<S46>:1:250' */
    /* '<S46>:1:251' */
    Alpha1_idx_4 = K[5] - (ctrl_DP_P.C[5] - K[5]);
  } else if (rtb_psi_dot == ctrl_DP_P.C[17]) {
    /* '<S46>:1:252' */
    /* '<S46>:1:253' */
    Alpha1_idx_4 = K[5] - (ctrl_DP_P.C[17] - K[5]);
  } else {
    if (rtb_psi_dot == ctrl_DP_P.C[23]) {
      /* '<S46>:1:254' */
      /* '<S46>:1:255' */
      Alpha1_idx_4 = K[5] - (ctrl_DP_P.C[23] - K[5]);
    }
  }

  /*  Thruster 4 & 1 */
  if (Alpha1_idx_3 == ctrl_DP_P.C[9]) {
    /* '<S46>:1:258' */
    /* '<S46>:1:259' */
    rtb_Row1 = K[3] - (ctrl_DP_P.C[9] - K[3]);
  } else if (Alpha1_idx_3 == ctrl_DP_P.C[3]) {
    /* '<S46>:1:260' */
    /* '<S46>:1:261' */
    rtb_Row1 = K[3] - (ctrl_DP_P.C[3] - K[3]);
  } else if (Alpha1_idx_3 == ctrl_DP_P.C[15]) {
    /* '<S46>:1:262' */
    /* '<S46>:1:263' */
    rtb_Row1 = K[3] - (ctrl_DP_P.C[15] - K[3]);
  } else {
    if (Alpha1_idx_3 == ctrl_DP_P.C[21]) {
      /* '<S46>:1:264' */
      /* '<S46>:1:265' */
      rtb_Row1 = K[3] - (ctrl_DP_P.C[21] - K[3]);
    }
  }

  if (rtb_Row1 == ctrl_DP_P.C[6]) {
    /* '<S46>:1:268' */
    /* '<S46>:1:269' */
    Alpha1_idx_3 = K[0] - (ctrl_DP_P.C[6] - K[0]);
  } else if (rtb_Row1 == ctrl_DP_P.C[0]) {
    /* '<S46>:1:270' */
    /* '<S46>:1:271' */
    Alpha1_idx_3 = K[0] - (ctrl_DP_P.C[0] - K[0]);
  } else if (rtb_Row1 == ctrl_DP_P.C[12]) {
    /* '<S46>:1:272' */
    /* '<S46>:1:273' */
    Alpha1_idx_3 = K[0] - (ctrl_DP_P.C[12] - K[0]);
  } else {
    if (rtb_Row1 == ctrl_DP_P.C[18]) {
      /* '<S46>:1:274' */
      /* '<S46>:1:275' */
      Alpha1_idx_3 = K[0] - (ctrl_DP_P.C[18] - K[0]);
    }
  }

  /* '<S46>:1:278' */
  /*  u_d = -Desired_thrust; */
  /*  Update outputs */
  /* '<S46>:1:285' */
  rtb_sys[0] = rtb_Row1;
  rtb_sys[1] = rtb_Row2;
  rtb_sys[2] = Alpha1_idx_2;
  rtb_sys[3] = Alpha1_idx_3;
  rtb_sys[4] = Alpha1_idx_4;
  rtb_sys[5] = rtb_psi_dot;
  for (i_0 = 0; i_0 < 6; i_0++) {
    rtb_sys[i_0 + 6] = rtb_y[i_0];
  }

  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
  }

  /* Switch: '<S9>/Choosing Fixed // Azimuth angle' incorporates:
   *  Constant: '<S9>/constant angle'
   */
  for (i_0 = 0; i_0 < 6; i_0++) {
    if (ctrl_DP_B.Angle_controller >= ctrl_DP_P.ChoosingFixedAzimuthangle_Thres)
    {
      ctrl_DP_B.ChoosingFixedAzimuthangle[i_0] = rtb_sys[i_0];
    } else {
      ctrl_DP_B.ChoosingFixedAzimuthangle[i_0] =
        ctrl_DP_P.constantangle_Value[i_0];
    }
  }

  /* End of Switch: '<S9>/Choosing Fixed // Azimuth angle' */

  /* Outputs for Iterator SubSystem: '<S9>/Optimal angle path and  constraints on rotation speed' incorporates:
   *  ForEach: '<S47>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
    /* ForEachSliceSelector: '<S47>/ImpSel_InsertedFor_reset_at_outport_0' */
    rtb_ImpSel_InsertedFor_reset_at = ctrl_DP_B.reset_g[ForEach_itr];
    if (rtmIsMajorTimeStep(ctrl_DP_M)) {
      /* DiscreteIntegrator: '<S47>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S9>/constant angle'
       *  ForEachSliceSelector: '<S47>/ImpSel_InsertedFor_initial angle _at_outport_0'
       */
      if (ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI !=
          0) {
        ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE =
          ctrl_DP_P.constantangle_Value[ForEach_itr];
      }

      if (((rtb_ImpSel_InsertedFor_reset_at > 0.0) &&
           (ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese <=
            0)) || ((rtb_ImpSel_InsertedFor_reset_at <= 0.0) &&
                    (ctrl_DP_DW.CoreSubsys[ForEach_itr].
                     DiscreteTimeIntegrator_PrevRese == 1))) {
        ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE =
          ctrl_DP_P.constantangle_Value[ForEach_itr];
      }

      ctrl_DP_B.CoreSubsys[ForEach_itr].angle =
        ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE;

      /* End of DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */

      /* Gain: '<S50>/Gain1' */
      rtb_psi_dot = ctrl_DP_P.CoreSubsys.Gain1_Gain *
        ctrl_DP_B.CoreSubsys[ForEach_itr].angle;

      /* Delay: '<S47>/Delay' */
      ctrl_DP_B.CoreSubsys[ForEach_itr].Delay =
        ctrl_DP_DW.CoreSubsys[ForEach_itr].Delay_DSTATE;

      /* MATLAB Function: '<S47>/Ensuring angle is  [-pi pi]' */
      /* MATLAB Function 'Thrust allocation/Optimal angle path and  constraints on rotation speed/Ensuring angle is  [-pi pi]': '<S51>:1' */
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
      /* '<S51>:1:39' */
      /* '<S51>:1:40' */
      /*  s = sign(angle); */
      /* '<S51>:1:43' */
      Alpha1_idx_3 = fabs(rt_remd_snf(rtb_psi_dot + 3.1415926535897931,
        6.2831853071795862) / 6.2831853071795862);
      if (rtb_psi_dot < 0.0) {
        rtb_Row2 = -1.0;
      } else if (rtb_psi_dot > 0.0) {
        rtb_Row2 = 1.0;
      } else if (rtb_psi_dot == 0.0) {
        rtb_Row2 = 0.0;
      } else {
        rtb_Row2 = rtb_psi_dot;
      }

      if (Alpha1_idx_3 > 0.0) {
        Alpha1_idx_3 = 1.0;
      } else {
        if (Alpha1_idx_3 == 0.0) {
          Alpha1_idx_3 = 0.0;
        }
      }

      Alpha1_idx_3 = (Alpha1_idx_3 - 1.0) * 2.0 + rtb_Row2;
      if (rtb_psi_dot < 0.0) {
        rtb_Row2 = -1.0;
      } else if (rtb_psi_dot > 0.0) {
        rtb_Row2 = 1.0;
      } else if (rtb_psi_dot == 0.0) {
        rtb_Row2 = 0.0;
      } else {
        rtb_Row2 = rtb_psi_dot;
      }

      if (Alpha1_idx_3 < 0.0) {
        Alpha1_idx_3 = -1.0;
      } else if (Alpha1_idx_3 > 0.0) {
        Alpha1_idx_3 = 1.0;
      } else {
        if (Alpha1_idx_3 == 0.0) {
          Alpha1_idx_3 = 0.0;
        }
      }

      absx31 = rt_remd_snf(rtb_Row2 * 3.1415926535897931 + rtb_psi_dot,
                           6.2831853071795862) - Alpha1_idx_3 *
        3.1415926535897931;

      /* End of MATLAB Function: '<S47>/Ensuring angle is  [-pi pi]' */
    }

    /* MATLAB Function: '<S47>/MATLAB Function1' incorporates:
     *  ForEachSliceSelector: '<S47>/ImpSel_InsertedFor_Desired Angle_at_outport_0'
     */
    /* MATLAB Function 'Thrust allocation/Optimal angle path and  constraints on rotation speed/MATLAB Function1': '<S52>:1' */
    /* '<S52>:1:3' */
    rtb_psi_dot = ctrl_DP_B.ChoosingFixedAzimuthangle[ForEach_itr] -
      ctrl_DP_B.CoreSubsys[ForEach_itr].Delay;
    if (fabs(rtb_psi_dot) >= 360.0) {
      /* '<S52>:1:4' */
      /* '<S52>:1:5' */
      rtb_psi_dot = rt_remd_snf(rtb_psi_dot, 360.0);
    }

    if (fabs(rtb_psi_dot) >= 180.0) {
      /* '<S52>:1:8' */
      /* '<S52>:1:9' */
      if (rtb_psi_dot < 0.0) {
        rtb_Row2 = -1.0;
      } else if (rtb_psi_dot > 0.0) {
        rtb_Row2 = 1.0;
      } else if (rtb_psi_dot == 0.0) {
        rtb_Row2 = 0.0;
      } else {
        rtb_Row2 = rtb_psi_dot;
      }

      rtb_psi_dot -= rtb_Row2 * 360.0;
    }

    /* End of MATLAB Function: '<S47>/MATLAB Function1' */

    /* Saturate: '<S47>/Max Rotation Rate' */
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
    if (rtb_psi_dot > ctrl_DP_P.Max_rotation) {
      ctrl_DP_B.CoreSubsys[ForEach_itr].MaxRotationRate = ctrl_DP_P.Max_rotation;
    } else if (rtb_psi_dot < -ctrl_DP_P.Max_rotation) {
      ctrl_DP_B.CoreSubsys[ForEach_itr].MaxRotationRate =
        -ctrl_DP_P.Max_rotation;
    } else {
      ctrl_DP_B.CoreSubsys[ForEach_itr].MaxRotationRate = rtb_psi_dot;
    }

    /* End of Saturate: '<S47>/Max Rotation Rate' */
    if (rtmIsMajorTimeStep(ctrl_DP_M)) {
      /* ForEachSliceAssignment: '<S47>/ImpAsg_InsertedFor_commanded Angle_at_inport_0' */
      rtb_ImpAsg_InsertedFor_commande[ForEach_itr] = absx31;
    }
  }

  /* End of Outputs for SubSystem: '<S9>/Optimal angle path and  constraints on rotation speed' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Saturate: '<S53>/Saturation 1' */
    if (rtb_ImpAsg_InsertedFor_commande[0] > ctrl_DP_P.Saturation1_UpperSat) {
      ctrl_DP_B.Saturation1 = ctrl_DP_P.Saturation1_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_commande[0] <
               ctrl_DP_P.Saturation1_LowerSat) {
      ctrl_DP_B.Saturation1 = ctrl_DP_P.Saturation1_LowerSat;
    } else {
      ctrl_DP_B.Saturation1 = rtb_ImpAsg_InsertedFor_commande[0];
    }

    /* End of Saturate: '<S53>/Saturation 1' */
  }

  /* Integrator: '<S69>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE_g,
                       (ctrl_DP_B.reset_o));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_c = ctrl_DP_P.Integrator_IC_f;
    }
  }

  /* MATLAB Function: '<S68>/Actual Force and Torque' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Qr1'
   *  Constant: '<S10>/K_Qr7'
   *  Constant: '<S10>/Rho'
   *  Constant: '<S55>/Losses (placeholder)'
   *  Integrator: '<S69>/Integrator'
   */
  /* MATLAB Function 'Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque': '<S71>:1' */
  /* '<S71>:1:3' */
  rtb_psi_dot = tanh(ctrl_DP_P.eps_c * ctrl_DP_X.Integrator_CSTATE_c / 5.0) *
    0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S71>:1:4' */
  /* '<S71>:1:5' */
  /* '<S71>:1:7' */
  /* '<S71>:1:8' */
  if (ctrl_DP_X.Integrator_CSTATE_c < 0.0) {
    absx31 = -1.0;
  } else if (ctrl_DP_X.Integrator_CSTATE_c > 0.0) {
    absx31 = 1.0;
  } else if (ctrl_DP_X.Integrator_CSTATE_c == 0.0) {
    absx31 = 0.0;
  } else {
    absx31 = ctrl_DP_X.Integrator_CSTATE_c;
  }

  rtb_Row2 = ((1.0 - rtb_psi_dot) * ctrl_DP_P.K_q1r + ctrl_DP_P.K_q1f *
              rtb_psi_dot) * absx31 * ctrl_DP_P.Rho * rt_powd_snf(ctrl_DP_P.D,
    5.0) * (ctrl_DP_X.Integrator_CSTATE_c * ctrl_DP_X.Integrator_CSTATE_c) -
    ctrl_DP_P.Lossesplaceholder_Value;

  /* '<S71>:1:9' */
  ctrl_DP_B.Pa = 6.2831853071795862 * ctrl_DP_X.Integrator_CSTATE_c * rtb_Row2;
  ctrl_DP_B.Qa = rtb_Row2;

  /* Integrator: '<S78>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE_n,
                       (ctrl_DP_B.reset_c));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_p = ctrl_DP_P.Integrator_IC_fg;
    }
  }

  rtb_Integrator_h = ctrl_DP_X.Integrator_CSTATE_p;

  /* End of Integrator: '<S78>/Integrator' */

  /* MATLAB Function: '<S77>/Actual Force and Torque' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Qr2'
   *  Constant: '<S10>/K_Qr8'
   *  Constant: '<S10>/K_Tf2'
   *  Constant: '<S10>/K_Tr2'
   *  Constant: '<S10>/Rho'
   *  Constant: '<S56>/Losses (placeholder)'
   */
  ctrl_DP_ActualForceandTorque(rtb_Integrator_h, ctrl_DP_P.K_q2f,
    ctrl_DP_P.K_T2f, ctrl_DP_P.K_T2r, ctrl_DP_P.K_q2r, ctrl_DP_P.Rho,
    ctrl_DP_P.D, ctrl_DP_P.eps_c, ctrl_DP_P.Lossesplaceholder_Value_k,
    &ctrl_DP_B.sf_ActualForceandTorque_f);

  /* Integrator: '<S87>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE_o,
                       (ctrl_DP_B.reset_j));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_k = ctrl_DP_P.Integrator_IC_p;
    }
  }

  rtb_Integrator_a = ctrl_DP_X.Integrator_CSTATE_k;

  /* End of Integrator: '<S87>/Integrator' */

  /* MATLAB Function: '<S86>/Actual Force and Torque' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Qr3'
   *  Constant: '<S10>/K_Qr9'
   *  Constant: '<S10>/K_Tf3'
   *  Constant: '<S10>/K_Tr3'
   *  Constant: '<S10>/Rho'
   *  Constant: '<S57>/Losses (placeholder)'
   */
  ctrl_DP_ActualForceandTorque(rtb_Integrator_a, ctrl_DP_P.K_q3f,
    ctrl_DP_P.K_T3f, ctrl_DP_P.K_T3r, ctrl_DP_P.K_q3r, ctrl_DP_P.Rho,
    ctrl_DP_P.D, ctrl_DP_P.eps_c, ctrl_DP_P.Lossesplaceholder_Value_n,
    &ctrl_DP_B.sf_ActualForceandTorque_h);

  /* Integrator: '<S96>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE_i,
                       (ctrl_DP_B.reset_p));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_n = ctrl_DP_P.Integrator_IC_fv;
    }
  }

  rtb_Integrator_k = ctrl_DP_X.Integrator_CSTATE_n;

  /* End of Integrator: '<S96>/Integrator' */

  /* MATLAB Function: '<S95>/Actual Force and Torque' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Qr10'
   *  Constant: '<S10>/K_Qr4'
   *  Constant: '<S10>/K_Tf4'
   *  Constant: '<S10>/K_Tr4'
   *  Constant: '<S10>/Rho'
   *  Constant: '<S58>/Losses (placeholder)'
   */
  ctrl_DP_ActualForceandTorque(rtb_Integrator_k, ctrl_DP_P.K_q4f,
    ctrl_DP_P.K_T4f, ctrl_DP_P.K_T4r, ctrl_DP_P.K_q4r, ctrl_DP_P.Rho,
    ctrl_DP_P.D, ctrl_DP_P.eps_c, ctrl_DP_P.Lossesplaceholder_Value_d,
    &ctrl_DP_B.sf_ActualForceandTorque_m);

  /* Integrator: '<S105>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE_a,
                       (ctrl_DP_B.reset_k));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_cd = ctrl_DP_P.Integrator_IC_l;
    }
  }

  rtb_Integrator_c = ctrl_DP_X.Integrator_CSTATE_cd;

  /* End of Integrator: '<S105>/Integrator' */

  /* MATLAB Function: '<S104>/Actual Force and Torque' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Qr11'
   *  Constant: '<S10>/K_Qr5'
   *  Constant: '<S10>/K_Tf5'
   *  Constant: '<S10>/K_Tr5'
   *  Constant: '<S10>/Rho'
   *  Constant: '<S59>/Losses (placeholder)'
   */
  ctrl_DP_ActualForceandTorque(rtb_Integrator_c, ctrl_DP_P.K_q5f,
    ctrl_DP_P.K_T5f, ctrl_DP_P.K_T5r, ctrl_DP_P.K_q5r, ctrl_DP_P.Rho,
    ctrl_DP_P.D, ctrl_DP_P.eps_c, ctrl_DP_P.Lossesplaceholder_Value_f,
    &ctrl_DP_B.sf_ActualForceandTorque_o);

  /* Integrator: '<S114>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE_d,
                       (ctrl_DP_B.reset_i));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_h = ctrl_DP_P.Integrator_IC_li;
    }
  }

  rtb_Integrator_m = ctrl_DP_X.Integrator_CSTATE_h;

  /* End of Integrator: '<S114>/Integrator' */

  /* MATLAB Function: '<S113>/Actual Force and Torque' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Qr12'
   *  Constant: '<S10>/K_Qr6'
   *  Constant: '<S10>/K_Tf6'
   *  Constant: '<S10>/K_Tr6'
   *  Constant: '<S10>/Rho'
   *  Constant: '<S60>/Losses (placeholder)'
   */
  ctrl_DP_ActualForceandTorque(rtb_Integrator_m, ctrl_DP_P.K_q6f,
    ctrl_DP_P.K_T6f, ctrl_DP_P.K_T6r, ctrl_DP_P.K_q6r, ctrl_DP_P.Rho,
    ctrl_DP_P.D, ctrl_DP_P.eps_c, ctrl_DP_P.Lossesplaceholder_Value_h,
    &ctrl_DP_B.sf_ActualForceandTorque_j);

  /* MATLAB Function: '<S68>/Actual Force and Torque' incorporates:
   *  Integrator: '<S69>/Integrator'
   */
  /* MATLAB Function 'Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function': '<S61>:1' */
  /* '<S61>:1:8' */
  if (ctrl_DP_X.Integrator_CSTATE_c < 0.0) {
    absx31 = -1.0;
  } else if (ctrl_DP_X.Integrator_CSTATE_c > 0.0) {
    absx31 = 1.0;
  } else if (ctrl_DP_X.Integrator_CSTATE_c == 0.0) {
    absx31 = 0.0;
  } else {
    absx31 = ctrl_DP_X.Integrator_CSTATE_c;
  }

  /* MATLAB Function: '<S54>/MATLAB Function' incorporates:
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Tf1'
   *  Constant: '<S10>/K_Tr1'
   *  Constant: '<S10>/Rho'
   *  Constant: '<S55>/Losses (placeholder)'
   *  Integrator: '<S69>/Integrator'
   *  MATLAB Function: '<S68>/Actual Force and Torque'
   *  SignalConversion: '<S61>/TmpSignal ConversionAt SFunction Inport1'
   */
  ctrl_DP_B.output[0] = ((1.0 - rtb_psi_dot) * ctrl_DP_P.K_T1r + ctrl_DP_P.K_T1f
    * rtb_psi_dot) * absx31 * ctrl_DP_P.Rho * rt_powd_snf(ctrl_DP_P.D, 4.0) *
    (ctrl_DP_X.Integrator_CSTATE_c * ctrl_DP_X.Integrator_CSTATE_c) -
    ctrl_DP_P.Lossesplaceholder_Value;
  ctrl_DP_B.output[1] = ctrl_DP_X.Integrator_CSTATE_c;
  ctrl_DP_B.output[2] = ctrl_DP_B.sf_ActualForceandTorque_f.Ta;
  ctrl_DP_B.output[3] = rtb_Integrator_h;
  ctrl_DP_B.output[4] = ctrl_DP_B.sf_ActualForceandTorque_h.Ta;
  ctrl_DP_B.output[5] = rtb_Integrator_a;
  ctrl_DP_B.output[6] = ctrl_DP_B.sf_ActualForceandTorque_m.Ta;
  ctrl_DP_B.output[7] = rtb_Integrator_k;
  ctrl_DP_B.output[8] = ctrl_DP_B.sf_ActualForceandTorque_o.Ta;
  ctrl_DP_B.output[9] = rtb_Integrator_c;
  ctrl_DP_B.output[10] = ctrl_DP_B.sf_ActualForceandTorque_j.Ta;
  ctrl_DP_B.output[11] = rtb_Integrator_m;

  /* Saturate: '<S54>/Saturation 8' */
  if (ctrl_DP_B.output[2] > ctrl_DP_P.Max_thrust) {
    rtb_psi_dot = ctrl_DP_P.Max_thrust;
  } else if (ctrl_DP_B.output[2] < ctrl_DP_P.Saturation8_LowerSat) {
    rtb_psi_dot = ctrl_DP_P.Saturation8_LowerSat;
  } else {
    rtb_psi_dot = ctrl_DP_B.output[2];
  }

  /* End of Saturate: '<S54>/Saturation 8' */

  /* Polyval: '<S54>/positive thrust 2' */
  rtb_positivethrust2 = ctrl_DP_P.pwm_thr2_forward[0];
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_positivethrust2 = rtb_positivethrust2 * rtb_psi_dot +
      ctrl_DP_P.pwm_thr2_forward[i_0 + 1];
  }

  /* End of Polyval: '<S54>/positive thrust 2' */

  /* Saturate: '<S54>/Saturation 9' */
  if (ctrl_DP_B.output[2] > ctrl_DP_P.Saturation9_UpperSat) {
    rtb_psi_dot = ctrl_DP_P.Saturation9_UpperSat;
  } else if (ctrl_DP_B.output[2] < ctrl_DP_P.Min_thrust) {
    rtb_psi_dot = ctrl_DP_P.Min_thrust;
  } else {
    rtb_psi_dot = ctrl_DP_B.output[2];
  }

  /* End of Saturate: '<S54>/Saturation 9' */

  /* Polyval: '<S54>/negative thrust 2' */
  rtb_negativethrust2 = ctrl_DP_P.pwm_thr2_backward[0];
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_negativethrust2 = rtb_negativethrust2 * rtb_psi_dot +
      ctrl_DP_P.pwm_thr2_backward[i_0 + 1];
  }

  /* End of Polyval: '<S54>/negative thrust 2' */

  /* MATLAB Function: '<S54>/MATLAB Function2' */
  ctrl_DP_MATLABFunction2(rtb_positivethrust2, ctrl_DP_B.output[2],
    rtb_negativethrust2, &ctrl_DP_B.sf_MATLABFunction2_i);

  /* Saturate: '<S54>/Saturation 10' */
  if (ctrl_DP_B.output[4] > ctrl_DP_P.Max_thrust) {
    rtb_psi_dot = ctrl_DP_P.Max_thrust;
  } else if (ctrl_DP_B.output[4] < ctrl_DP_P.Saturation10_LowerSat) {
    rtb_psi_dot = ctrl_DP_P.Saturation10_LowerSat;
  } else {
    rtb_psi_dot = ctrl_DP_B.output[4];
  }

  /* End of Saturate: '<S54>/Saturation 10' */

  /* Polyval: '<S54>/positive thrust 3' */
  rtb_positivethrust3 = ctrl_DP_P.pwm_thr3_forward[0];
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_positivethrust3 = rtb_positivethrust3 * rtb_psi_dot +
      ctrl_DP_P.pwm_thr3_forward[i_0 + 1];
  }

  /* End of Polyval: '<S54>/positive thrust 3' */

  /* Saturate: '<S54>/Saturation 11' */
  if (ctrl_DP_B.output[4] > ctrl_DP_P.Saturation11_UpperSat) {
    rtb_psi_dot = ctrl_DP_P.Saturation11_UpperSat;
  } else if (ctrl_DP_B.output[4] < ctrl_DP_P.Min_thrust) {
    rtb_psi_dot = ctrl_DP_P.Min_thrust;
  } else {
    rtb_psi_dot = ctrl_DP_B.output[4];
  }

  /* End of Saturate: '<S54>/Saturation 11' */

  /* Polyval: '<S54>/negative thrust 3' */
  rtb_negativethrust3 = ctrl_DP_P.pwm_thr3_backward[0];
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_negativethrust3 = rtb_negativethrust3 * rtb_psi_dot +
      ctrl_DP_P.pwm_thr3_backward[i_0 + 1];
  }

  /* End of Polyval: '<S54>/negative thrust 3' */

  /* MATLAB Function: '<S54>/MATLAB Function3' */
  ctrl_DP_MATLABFunction2(rtb_positivethrust3, ctrl_DP_B.output[4],
    rtb_negativethrust3, &ctrl_DP_B.sf_MATLABFunction3);

  /* Saturate: '<S54>/Saturation 3' */
  if (ctrl_DP_B.output[6] > ctrl_DP_P.Max_thrust) {
    rtb_psi_dot = ctrl_DP_P.Max_thrust;
  } else if (ctrl_DP_B.output[6] < ctrl_DP_P.Saturation3_LowerSat) {
    rtb_psi_dot = ctrl_DP_P.Saturation3_LowerSat;
  } else {
    rtb_psi_dot = ctrl_DP_B.output[6];
  }

  /* End of Saturate: '<S54>/Saturation 3' */

  /* Polyval: '<S54>/positive thrust 4' */
  rtb_positivethrust4 = ctrl_DP_P.pwm_thr4_forward[0];
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_positivethrust4 = rtb_positivethrust4 * rtb_psi_dot +
      ctrl_DP_P.pwm_thr4_forward[i_0 + 1];
  }

  /* End of Polyval: '<S54>/positive thrust 4' */

  /* Saturate: '<S54>/Saturation 4' */
  if (ctrl_DP_B.output[6] > ctrl_DP_P.Saturation4_UpperSat) {
    rtb_psi_dot = ctrl_DP_P.Saturation4_UpperSat;
  } else if (ctrl_DP_B.output[6] < ctrl_DP_P.Min_thrust) {
    rtb_psi_dot = ctrl_DP_P.Min_thrust;
  } else {
    rtb_psi_dot = ctrl_DP_B.output[6];
  }

  /* End of Saturate: '<S54>/Saturation 4' */

  /* Polyval: '<S54>/negative thrust 4' */
  rtb_negativethrust4 = ctrl_DP_P.pwm_thr4_backward[0];
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_negativethrust4 = rtb_negativethrust4 * rtb_psi_dot +
      ctrl_DP_P.pwm_thr4_backward[i_0 + 1];
  }

  /* End of Polyval: '<S54>/negative thrust 4' */

  /* MATLAB Function: '<S54>/MATLAB Function4' */
  ctrl_DP_MATLABFunction2(rtb_positivethrust4, ctrl_DP_B.output[6],
    rtb_negativethrust4, &ctrl_DP_B.sf_MATLABFunction4);

  /* Saturate: '<S54>/Saturation 5' */
  if (ctrl_DP_B.output[8] > ctrl_DP_P.Max_thrust) {
    rtb_psi_dot = ctrl_DP_P.Max_thrust;
  } else if (ctrl_DP_B.output[8] < ctrl_DP_P.Saturation5_LowerSat) {
    rtb_psi_dot = ctrl_DP_P.Saturation5_LowerSat;
  } else {
    rtb_psi_dot = ctrl_DP_B.output[8];
  }

  /* End of Saturate: '<S54>/Saturation 5' */

  /* Polyval: '<S54>/positive thrust 5' */
  rtb_positivethrust5 = ctrl_DP_P.pwm_thr5_forward[0];
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_positivethrust5 = rtb_positivethrust5 * rtb_psi_dot +
      ctrl_DP_P.pwm_thr5_forward[i_0 + 1];
  }

  /* End of Polyval: '<S54>/positive thrust 5' */

  /* Saturate: '<S54>/Saturation 6' */
  if (ctrl_DP_B.output[8] > ctrl_DP_P.Saturation6_UpperSat) {
    rtb_psi_dot = ctrl_DP_P.Saturation6_UpperSat;
  } else if (ctrl_DP_B.output[8] < ctrl_DP_P.Min_thrust) {
    rtb_psi_dot = ctrl_DP_P.Min_thrust;
  } else {
    rtb_psi_dot = ctrl_DP_B.output[8];
  }

  /* End of Saturate: '<S54>/Saturation 6' */

  /* Polyval: '<S54>/negative thrust 5' */
  rtb_negativethrust5 = ctrl_DP_P.pwm_thr5_backward[0];
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_negativethrust5 = rtb_negativethrust5 * rtb_psi_dot +
      ctrl_DP_P.pwm_thr5_backward[i_0 + 1];
  }

  /* End of Polyval: '<S54>/negative thrust 5' */

  /* MATLAB Function: '<S54>/MATLAB Function5' */
  ctrl_DP_MATLABFunction2(rtb_positivethrust5, ctrl_DP_B.output[8],
    rtb_negativethrust5, &ctrl_DP_B.sf_MATLABFunction5);
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Saturate: '<S53>/Saturation 2' */
    if (rtb_ImpAsg_InsertedFor_commande[1] > ctrl_DP_P.Saturation2_UpperSat) {
      ctrl_DP_B.Saturation2 = ctrl_DP_P.Saturation2_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_commande[1] <
               ctrl_DP_P.Saturation2_LowerSat) {
      ctrl_DP_B.Saturation2 = ctrl_DP_P.Saturation2_LowerSat;
    } else {
      ctrl_DP_B.Saturation2 = rtb_ImpAsg_InsertedFor_commande[1];
    }

    /* End of Saturate: '<S53>/Saturation 2' */
  }

  /* Saturate: '<S54>/Saturation 12' */
  if (ctrl_DP_B.output[10] > ctrl_DP_P.Max_thrust) {
    rtb_psi_dot = ctrl_DP_P.Max_thrust;
  } else if (ctrl_DP_B.output[10] < ctrl_DP_P.Saturation12_LowerSat) {
    rtb_psi_dot = ctrl_DP_P.Saturation12_LowerSat;
  } else {
    rtb_psi_dot = ctrl_DP_B.output[10];
  }

  /* End of Saturate: '<S54>/Saturation 12' */

  /* Polyval: '<S54>/positive thrust 6' */
  rtb_positivethrust6 = ctrl_DP_P.pwm_thr6_forward[0];
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_positivethrust6 = rtb_positivethrust6 * rtb_psi_dot +
      ctrl_DP_P.pwm_thr6_forward[i_0 + 1];
  }

  /* End of Polyval: '<S54>/positive thrust 6' */

  /* Saturate: '<S54>/Saturation 13' */
  if (ctrl_DP_B.output[10] > ctrl_DP_P.Saturation13_UpperSat) {
    rtb_psi_dot = ctrl_DP_P.Saturation13_UpperSat;
  } else if (ctrl_DP_B.output[10] < ctrl_DP_P.Min_thrust) {
    rtb_psi_dot = ctrl_DP_P.Min_thrust;
  } else {
    rtb_psi_dot = ctrl_DP_B.output[10];
  }

  /* End of Saturate: '<S54>/Saturation 13' */

  /* Polyval: '<S54>/negative thrust 6' */
  rtb_negativethrust6 = ctrl_DP_P.pwm_thr6_backward[0];
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_negativethrust6 = rtb_negativethrust6 * rtb_psi_dot +
      ctrl_DP_P.pwm_thr6_backward[i_0 + 1];
  }

  /* End of Polyval: '<S54>/negative thrust 6' */

  /* MATLAB Function: '<S54>/MATLAB Function6' */
  ctrl_DP_MATLABFunction2(rtb_positivethrust6, ctrl_DP_B.output[10],
    rtb_negativethrust6, &ctrl_DP_B.sf_MATLABFunction6);
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Saturate: '<S53>/Saturation 3' */
    if (rtb_ImpAsg_InsertedFor_commande[2] > ctrl_DP_P.Saturation3_UpperSat) {
      ctrl_DP_B.Saturation3 = ctrl_DP_P.Saturation3_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_commande[2] <
               ctrl_DP_P.Saturation3_LowerSat_f) {
      ctrl_DP_B.Saturation3 = ctrl_DP_P.Saturation3_LowerSat_f;
    } else {
      ctrl_DP_B.Saturation3 = rtb_ImpAsg_InsertedFor_commande[2];
    }

    /* End of Saturate: '<S53>/Saturation 3' */

    /* Saturate: '<S53>/Saturation 4' */
    if (rtb_ImpAsg_InsertedFor_commande[3] > ctrl_DP_P.Saturation4_UpperSat_p) {
      ctrl_DP_B.Saturation4 = ctrl_DP_P.Saturation4_UpperSat_p;
    } else if (rtb_ImpAsg_InsertedFor_commande[3] <
               ctrl_DP_P.Saturation4_LowerSat) {
      ctrl_DP_B.Saturation4 = ctrl_DP_P.Saturation4_LowerSat;
    } else {
      ctrl_DP_B.Saturation4 = rtb_ImpAsg_InsertedFor_commande[3];
    }

    /* End of Saturate: '<S53>/Saturation 4' */

    /* Saturate: '<S53>/Saturation 5' */
    if (rtb_ImpAsg_InsertedFor_commande[4] > ctrl_DP_P.Saturation5_UpperSat) {
      ctrl_DP_B.Saturation5 = ctrl_DP_P.Saturation5_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_commande[4] <
               ctrl_DP_P.Saturation5_LowerSat_h) {
      ctrl_DP_B.Saturation5 = ctrl_DP_P.Saturation5_LowerSat_h;
    } else {
      ctrl_DP_B.Saturation5 = rtb_ImpAsg_InsertedFor_commande[4];
    }

    /* End of Saturate: '<S53>/Saturation 5' */

    /* Saturate: '<S53>/Saturation 6' */
    if (rtb_ImpAsg_InsertedFor_commande[5] > ctrl_DP_P.Saturation6_UpperSat_g) {
      ctrl_DP_B.Saturation6 = ctrl_DP_P.Saturation6_UpperSat_g;
    } else if (rtb_ImpAsg_InsertedFor_commande[5] <
               ctrl_DP_P.Saturation6_LowerSat) {
      ctrl_DP_B.Saturation6 = ctrl_DP_P.Saturation6_LowerSat;
    } else {
      ctrl_DP_B.Saturation6 = rtb_ImpAsg_InsertedFor_commande[5];
    }

    /* End of Saturate: '<S53>/Saturation 6' */
  }

  /* Saturate: '<S54>/Saturation 7' */
  if (ctrl_DP_B.output[0] > ctrl_DP_P.Max_thrust) {
    ctrl_DP_B.Saturation7[0] = ctrl_DP_P.Max_thrust;
  } else if (ctrl_DP_B.output[0] < -ctrl_DP_P.Max_thrust) {
    ctrl_DP_B.Saturation7[0] = -ctrl_DP_P.Max_thrust;
  } else {
    ctrl_DP_B.Saturation7[0] = ctrl_DP_B.output[0];
  }

  if (ctrl_DP_B.output[2] > ctrl_DP_P.Max_thrust) {
    ctrl_DP_B.Saturation7[1] = ctrl_DP_P.Max_thrust;
  } else if (ctrl_DP_B.output[2] < -ctrl_DP_P.Max_thrust) {
    ctrl_DP_B.Saturation7[1] = -ctrl_DP_P.Max_thrust;
  } else {
    ctrl_DP_B.Saturation7[1] = ctrl_DP_B.output[2];
  }

  if (ctrl_DP_B.output[4] > ctrl_DP_P.Max_thrust) {
    ctrl_DP_B.Saturation7[2] = ctrl_DP_P.Max_thrust;
  } else if (ctrl_DP_B.output[4] < -ctrl_DP_P.Max_thrust) {
    ctrl_DP_B.Saturation7[2] = -ctrl_DP_P.Max_thrust;
  } else {
    ctrl_DP_B.Saturation7[2] = ctrl_DP_B.output[4];
  }

  if (ctrl_DP_B.output[6] > ctrl_DP_P.Max_thrust) {
    ctrl_DP_B.Saturation7[3] = ctrl_DP_P.Max_thrust;
  } else if (ctrl_DP_B.output[6] < -ctrl_DP_P.Max_thrust) {
    ctrl_DP_B.Saturation7[3] = -ctrl_DP_P.Max_thrust;
  } else {
    ctrl_DP_B.Saturation7[3] = ctrl_DP_B.output[6];
  }

  if (ctrl_DP_B.output[8] > ctrl_DP_P.Max_thrust) {
    ctrl_DP_B.Saturation7[4] = ctrl_DP_P.Max_thrust;
  } else if (ctrl_DP_B.output[8] < -ctrl_DP_P.Max_thrust) {
    ctrl_DP_B.Saturation7[4] = -ctrl_DP_P.Max_thrust;
  } else {
    ctrl_DP_B.Saturation7[4] = ctrl_DP_B.output[8];
  }

  if (ctrl_DP_B.output[10] > ctrl_DP_P.Max_thrust) {
    ctrl_DP_B.Saturation7[5] = ctrl_DP_P.Max_thrust;
  } else if (ctrl_DP_B.output[10] < -ctrl_DP_P.Max_thrust) {
    ctrl_DP_B.Saturation7[5] = -ctrl_DP_P.Max_thrust;
  } else {
    ctrl_DP_B.Saturation7[5] = ctrl_DP_B.output[10];
  }

  /* End of Saturate: '<S54>/Saturation 7' */

  /* Saturate: '<S54>/Saturation 1' */
  if (ctrl_DP_B.output[0] > ctrl_DP_P.Max_thrust) {
    rtb_Row2 = ctrl_DP_P.Max_thrust;
  } else if (ctrl_DP_B.output[0] < ctrl_DP_P.Saturation1_LowerSat_h) {
    rtb_Row2 = ctrl_DP_P.Saturation1_LowerSat_h;
  } else {
    rtb_Row2 = ctrl_DP_B.output[0];
  }

  /* End of Saturate: '<S54>/Saturation 1' */

  /* Polyval: '<S54>/positive thrust 1' */
  rtb_psi_dot = ctrl_DP_P.pwm_thr1_forward[0];
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_psi_dot = rtb_psi_dot * rtb_Row2 + ctrl_DP_P.pwm_thr1_forward[i_0 + 1];
  }

  /* End of Polyval: '<S54>/positive thrust 1' */

  /* Saturate: '<S54>/Saturation 2' */
  if (ctrl_DP_B.output[0] > ctrl_DP_P.Saturation2_UpperSat_p) {
    rtb_Row2 = ctrl_DP_P.Saturation2_UpperSat_p;
  } else if (ctrl_DP_B.output[0] < ctrl_DP_P.Min_thrust) {
    rtb_Row2 = ctrl_DP_P.Min_thrust;
  } else {
    rtb_Row2 = ctrl_DP_B.output[0];
  }

  /* End of Saturate: '<S54>/Saturation 2' */

  /* Polyval: '<S54>/negative thrust 1' */
  rtb_Row1 = ctrl_DP_P.pwm_thr1_backward[0];
  for (i_0 = 0; i_0 < 5; i_0++) {
    rtb_Row1 = rtb_Row1 * rtb_Row2 + ctrl_DP_P.pwm_thr1_backward[i_0 + 1];
  }

  /* End of Polyval: '<S54>/negative thrust 1' */

  /* MATLAB Function: '<S54>/MATLAB Function1' */
  /* MATLAB Function 'Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function1': '<S62>:1' */
  if (ctrl_DP_B.output[0] >= 0.0) {
    /* '<S62>:1:4' */
    /* '<S62>:1:5' */
    ctrl_DP_B.Tc_out = rtb_psi_dot;
  } else {
    /* signal < 0 */
    /* '<S62>:1:7' */
    ctrl_DP_B.Tc_out = rtb_Row1;
  }

  /* End of MATLAB Function: '<S54>/MATLAB Function1' */

  /* Integrator: '<S5>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_PrevZCX.Integrator_Reset_ZCE_nt,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if ((zcEvent != NO_ZCEVENT) || (ctrl_DP_DW.Integrator_IWORK != 0)) {
      ctrl_DP_X.Integrator_CSTATE_a[0] = ctrl_DP_B.Gain;
      ctrl_DP_X.Integrator_CSTATE_a[1] = ctrl_DP_B.Gain1;
      ctrl_DP_X.Integrator_CSTATE_a[2] = ctrl_DP_B.Sum;
    }
  }

  ctrl_DP_B.Integrator[0] = ctrl_DP_X.Integrator_CSTATE_a[0];
  ctrl_DP_B.Integrator[1] = ctrl_DP_X.Integrator_CSTATE_a[1];
  ctrl_DP_B.Integrator[2] = ctrl_DP_X.Integrator_CSTATE_a[2];

  /* End of Integrator: '<S5>/Integrator' */

  /* Saturate: '<S40>/Saturation' */
  if (ctrl_DP_B.Integrator[2] > ctrl_DP_P.Saturation_UpperSat_i) {
    Alpha1_idx_2 = ctrl_DP_P.Saturation_UpperSat_i;
  } else if (ctrl_DP_B.Integrator[2] < ctrl_DP_P.Saturation_LowerSat_o) {
    Alpha1_idx_2 = ctrl_DP_P.Saturation_LowerSat_o;
  } else {
    Alpha1_idx_2 = ctrl_DP_B.Integrator[2];
  }

  /* End of Saturate: '<S40>/Saturation' */

  /* Signum: '<S40>/Sign' */
  if (Alpha1_idx_2 < 0.0) {
    absx31 = -1.0;
  } else if (Alpha1_idx_2 > 0.0) {
    absx31 = 1.0;
  } else if (Alpha1_idx_2 == 0.0) {
    absx31 = 0.0;
  } else {
    absx31 = Alpha1_idx_2;
  }

  /* End of Signum: '<S40>/Sign' */

  /* Gain: '<S40>/Gain' */
  rtb_psi_dot = ctrl_DP_P.Gain_Gain_pg * absx31;

  /* Sum: '<S40>/Sum1' */
  Alpha1_idx_2 += rtb_psi_dot;

  /* Math: '<S40>/Math Function' incorporates:
   *  Constant: '<S40>/Constant'
   */
  Alpha1_idx_2 = rt_remd_snf(Alpha1_idx_2, ctrl_DP_P.Constant_Value_k);

  /* Sum: '<S40>/Sum' */
  ctrl_DP_B.Sum_e = Alpha1_idx_2 - rtb_psi_dot;

  /* Saturate: '<S41>/Saturation' */
  if (ctrl_DP_B.Sum > ctrl_DP_P.Saturation_UpperSat_e) {
    Alpha1_idx_2 = ctrl_DP_P.Saturation_UpperSat_e;
  } else if (ctrl_DP_B.Sum < ctrl_DP_P.Saturation_LowerSat_g) {
    Alpha1_idx_2 = ctrl_DP_P.Saturation_LowerSat_g;
  } else {
    Alpha1_idx_2 = ctrl_DP_B.Sum;
  }

  /* End of Saturate: '<S41>/Saturation' */

  /* Signum: '<S41>/Sign' */
  if (Alpha1_idx_2 < 0.0) {
    absx31 = -1.0;
  } else if (Alpha1_idx_2 > 0.0) {
    absx31 = 1.0;
  } else if (Alpha1_idx_2 == 0.0) {
    absx31 = 0.0;
  } else {
    absx31 = Alpha1_idx_2;
  }

  /* End of Signum: '<S41>/Sign' */

  /* Gain: '<S41>/Gain' */
  rtb_psi_dot = ctrl_DP_P.Gain_Gain_f * absx31;

  /* Sum: '<S41>/Sum1' */
  Alpha1_idx_2 += rtb_psi_dot;

  /* Math: '<S41>/Math Function' incorporates:
   *  Constant: '<S41>/Constant'
   */
  Alpha1_idx_2 = rt_remd_snf(Alpha1_idx_2, ctrl_DP_P.Constant_Value_p);

  /* Sum: '<S41>/Sum' */
  Alpha1_idx_2 -= rtb_psi_dot;

  /* Fcn: '<S5>/Fcn' */
  rtb_psi_dot = Alpha1_idx_2;

  /* Integrator: '<S5>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator2_Reset_ZCE,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator2_CSTATE[0] = ctrl_DP_P.Integrator2_IC[0];
      ctrl_DP_X.Integrator2_CSTATE[1] = ctrl_DP_P.Integrator2_IC[1];
      ctrl_DP_X.Integrator2_CSTATE[2] = ctrl_DP_P.Integrator2_IC[2];
    }
  }

  /* Sum: '<S5>/Sum' */
  tc[0] = ctrl_DP_B.Gain - ctrl_DP_B.Integrator[0];
  tc[1] = ctrl_DP_B.Gain1 - ctrl_DP_B.Integrator[1];
  tc[2] = Alpha1_idx_2 - ctrl_DP_B.Sum_e;

  /* MATLAB Function: '<S5>/C(nu)*nu' */
  /* MATLAB Function 'Nonlinear Passisve Observer/D(nu)*nu': '<S36>:1' */
  /* '<S36>:1:3' */
  /* '<S36>:1:4' */
  /* '<S36>:1:5' */
  /*  DAMPING  */
  /*  Surge: */
  /*  Based on fitting of towing data from -0.8 < u < 0.8 m/s */
  /* '<S36>:1:11' */
  /* '<S36>:1:12' */
  /* '<S36>:1:13' */
  /*  Sway: */
  /*  Based on fitting of towing data from -0.45 < u < 0.45 m/s */
  /* '<S36>:1:17' */
  /* '<S36>:1:18' */
  /* '<S36>:1:19' */
  /*  Yaw: */
  /*  Based on fitting of towing data from -8 < u < 8 deg/s */
  /*  The fitting range is limited. Towing should be performed for higher */
  /*  velocities. */
  /* '<S36>:1:25' */
  /* '<S36>:1:26' */
  /* '<S36>:1:27' */
  /*  Y_vvv og N_rrr er fra curvefitting uten minus, men ser ut til å fungere */
  /*  med minus.  */
  /*  Assembly of the damping matrix */
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
  /*  MATRICES */
  /* '<S35>:1:8' */
  /* 0.0432; */
  /*  Added mass */
  /* '<S35>:1:11' */
  /*  Correolis matrix */
  /* '<S35>:1:14' */
  rtb_Row2 = -99.03 * ctrl_DP_B.Integrator1_c[1] - -0.525 *
    ctrl_DP_B.Integrator1_c[2];

  /* '<S35>:1:15' */
  rtb_Row1 = 124.658 * ctrl_DP_B.Integrator1_c[0];

  /* Fcn: '<S39>/Row1' incorporates:
   *  Fcn: '<S5>/Fcn'
   */
  /* '<S35>:1:17' */
  /* '<S35>:1:24' */
  rtb_psi_dot_0[0] = Alpha1_idx_2;
  rtb_psi_dot_1[0] = Alpha1_idx_2;

  /* Fcn: '<S39>/Row2' incorporates:
   *  Fcn: '<S5>/Fcn'
   */
  rtb_psi_dot_2[0] = Alpha1_idx_2;
  rtb_psi_dot_3[0] = Alpha1_idx_2;

  /* Fcn: '<S38>/Row1' incorporates:
   *  Fcn: '<S5>/Fcn'
   */
  rtb_psi_dot_4[0] = Alpha1_idx_2;
  rtb_psi_dot_5[0] = Alpha1_idx_2;

  /* Fcn: '<S38>/Row2' incorporates:
   *  Fcn: '<S5>/Fcn'
   */
  rtb_psi_dot_6[0] = Alpha1_idx_2;
  rtb_psi_dot_7[0] = Alpha1_idx_2;
  for (i_0 = 0; i_0 < 3; i_0++) {
    /* Integrator: '<S5>/Integrator2' */
    ctrl_DP_B.Integrator2[i_0] = ctrl_DP_X.Integrator2_CSTATE[i_0];

    /* Product: '<S5>/Matrix Multiply2' */
    absx31 = ctrl_DP_B.sf_MATLABFunction2_a.y[i_0 + 6] * tc[2] +
      (ctrl_DP_B.sf_MATLABFunction2_a.y[i_0 + 3] * tc[1] +
       ctrl_DP_B.sf_MATLABFunction2_a.y[i_0] * tc[0]);

    /* Fcn: '<S39>/Row1' */
    rtb_psi_dot_0[i_0 + 1] = ctrl_DP_B.Integrator2[i_0];
    rtb_TmpSignalConversionAtMatr_0[i_0 + 1] = ctrl_DP_B.Integrator2[i_0];
    rtb_psi_dot_1[i_0 + 1] = ctrl_DP_B.Integrator2[i_0];
    rtb_TmpSignalConversionAtMatr_1[i_0 + 1] = ctrl_DP_B.Integrator2[i_0];

    /* Fcn: '<S39>/Row2' */
    rtb_psi_dot_2[i_0 + 1] = ctrl_DP_B.Integrator2[i_0];
    rtb_TmpSignalConversionAtMatr_2[i_0 + 1] = ctrl_DP_B.Integrator2[i_0];
    rtb_psi_dot_3[i_0 + 1] = ctrl_DP_B.Integrator2[i_0];
    rtb_TmpSignalConversionAtMatr_3[i_0 + 1] = ctrl_DP_B.Integrator2[i_0];

    /* Fcn: '<S39>/Row3' */
    rtb_TmpSignalConversionAtMatr_4[i_0 + 1] = ctrl_DP_B.Integrator2[i_0];

    /* Fcn: '<S38>/Row1' */
    rtb_psi_dot_4[i_0 + 1] = absx31;
    rtb_TmpSignalConversionAtMatr_5[i_0 + 1] = absx31;
    rtb_psi_dot_5[i_0 + 1] = absx31;
    rtb_TmpSignalConversionAtMatr_6[i_0 + 1] = absx31;

    /* Fcn: '<S38>/Row2' */
    rtb_psi_dot_6[i_0 + 1] = absx31;
    rtb_TmpSignalConversionAtMatr_7[i_0 + 1] = absx31;
    rtb_psi_dot_7[i_0 + 1] = absx31;
    rtb_TmpSignalConversionAtMatr_8[i_0 + 1] = absx31;

    /* Fcn: '<S38>/Row3' */
    rtb_psi_dot_8[i_0 + 1] = absx31;
  }

  /* Sum: '<S5>/Sum2' incorporates:
   *  Fcn: '<S38>/Row1'
   *  Fcn: '<S38>/Row2'
   *  Fcn: '<S38>/Row3'
   */
  tmp_1[0] = cos(rtb_psi_dot_4[0]) * rtb_TmpSignalConversionAtMatr_5[1] + sin
    (rtb_psi_dot_5[0]) * rtb_TmpSignalConversionAtMatr_6[2];
  tmp_1[1] = -sin(rtb_psi_dot_6[0]) * rtb_TmpSignalConversionAtMatr_7[1] + cos
    (rtb_psi_dot_7[0]) * rtb_TmpSignalConversionAtMatr_8[2];
  tmp_1[2] = rtb_psi_dot_8[3];

  /* Sum: '<S5>/Sum3' incorporates:
   *  Fcn: '<S39>/Row1'
   *  Fcn: '<S39>/Row2'
   *  Fcn: '<S39>/Row3'
   */
  tmp_2[0] = cos(rtb_psi_dot_0[0]) * rtb_TmpSignalConversionAtMatr_0[1] + sin
    (rtb_psi_dot_1[0]) * rtb_TmpSignalConversionAtMatr_1[2];
  tmp_2[1] = -sin(rtb_psi_dot_2[0]) * rtb_TmpSignalConversionAtMatr_2[1] + cos
    (rtb_psi_dot_3[0]) * rtb_TmpSignalConversionAtMatr_3[2];
  tmp_2[2] = rtb_TmpSignalConversionAtMatr_4[3];

  /* MATLAB Function: '<S5>/D(nu)*nu' */
  tmp_3[0] = (0.0 * fabs(ctrl_DP_B.Integrator1_c[0]) + -2.332) +
    ctrl_DP_B.Integrator1_c[0] * ctrl_DP_B.Integrator1_c[0] * -8.557;
  tmp_3[3] = 0.0;
  tmp_3[6] = 0.0;
  tmp_3[1] = 0.0;
  tmp_3[4] = (0.3976 * fabs(ctrl_DP_B.Integrator1_c[1]) + -4.673) +
    ctrl_DP_B.Integrator1_c[1] * ctrl_DP_B.Integrator1_c[1] * -313.3;
  tmp_3[7] = 0.0;
  tmp_3[2] = 0.0;
  tmp_3[5] = 0.0;
  tmp_3[8] = (-0.01148 * fabs(ctrl_DP_B.Integrator1_c[2]) + -0.01675) +
    ctrl_DP_B.Integrator1_c[2] * ctrl_DP_B.Integrator1_c[2] * -0.0003578;
  for (i_0 = 0; i_0 < 3; i_0++) {
    S_singular_cross[3 * i_0] = -tmp_3[3 * i_0];
    S_singular_cross[1 + 3 * i_0] = -tmp_3[3 * i_0 + 1];
    S_singular_cross[2 + 3 * i_0] = -tmp_3[3 * i_0 + 2];
  }

  /* MATLAB Function: '<S5>/C(nu)*nu' */
  rtb_y_b[0] = 0.0;
  rtb_y_b[3] = 0.0;
  rtb_y_b[6] = rtb_Row2;
  rtb_y_b[1] = 0.0;
  rtb_y_b[4] = 0.0;
  rtb_y_b[7] = rtb_Row1;
  rtb_y_b[2] = -rtb_Row2;
  rtb_y_b[5] = -rtb_Row1;
  rtb_y_b[8] = 0.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    /* Sum: '<S5>/Sum3' incorporates:
     *  Gain: '<S5>/M^-1'
     *  MATLAB Function: '<S5>/C(nu)*nu'
     *  MATLAB Function: '<S5>/D(nu)*nu'
     *  Sum: '<S5>/Sum2'
     */
    tmp_0[i_0] = (((tmp_1[i_0] + rtb_Sum3[i_0]) + tmp_2[i_0]) -
                  ((S_singular_cross[i_0 + 3] * ctrl_DP_B.Integrator1_c[1] +
                    S_singular_cross[i_0] * ctrl_DP_B.Integrator1_c[0]) +
                   S_singular_cross[i_0 + 6] * ctrl_DP_B.Integrator1_c[2])) -
      (rtb_y_b[i_0 + 6] * ctrl_DP_B.Integrator1_c[2] + (rtb_y_b[i_0 + 3] *
        ctrl_DP_B.Integrator1_c[1] + rtb_y_b[i_0] * ctrl_DP_B.Integrator1_c[0]));
  }

  /* Gain: '<S5>/M^-1' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    ctrl_DP_B.M1[i_0] = 0.0;
    ctrl_DP_B.M1[i_0] += ctrl_DP_P.M1_Gain[i_0] * tmp_0[0];
    ctrl_DP_B.M1[i_0] += ctrl_DP_P.M1_Gain[i_0 + 3] * tmp_0[1];
    ctrl_DP_B.M1[i_0] += ctrl_DP_P.M1_Gain[i_0 + 6] * tmp_0[2];
  }

  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Gain: '<S8>/Gain' */
    ctrl_DP_B.Gain_g[0] = ctrl_DP_P.Gain_Gain_f0 * ctrl_DP_B.Saturation1;
    ctrl_DP_B.Gain_g[1] = ctrl_DP_P.Gain_Gain_f0 * ctrl_DP_B.Saturation2;
    ctrl_DP_B.Gain_g[2] = ctrl_DP_P.Gain_Gain_f0 * ctrl_DP_B.Saturation3;
    ctrl_DP_B.Gain_g[3] = ctrl_DP_P.Gain_Gain_f0 * ctrl_DP_B.Saturation4;
    ctrl_DP_B.Gain_g[4] = ctrl_DP_P.Gain_Gain_f0 * ctrl_DP_B.Saturation5;
    ctrl_DP_B.Gain_g[5] = ctrl_DP_P.Gain_Gain_f0 * ctrl_DP_B.Saturation6;
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
  absx31 = ctrl_DP_B.Gain_g[0];
  ctrl_DP_cosd(&absx31);
  Alpha1_idx_2 = ctrl_DP_B.Gain_g[1];
  ctrl_DP_cosd(&Alpha1_idx_2);
  Alpha1_idx_4 = ctrl_DP_B.Gain_g[2];
  ctrl_DP_cosd(&Alpha1_idx_4);
  e_0 = ctrl_DP_B.Gain_g[3];
  ctrl_DP_cosd(&e_0);
  f_0 = ctrl_DP_B.Gain_g[4];
  ctrl_DP_cosd(&f_0);
  rtb_Row2 = ctrl_DP_B.Gain_g[5];
  ctrl_DP_cosd(&rtb_Row2);
  rtb_Row1 = ctrl_DP_B.Gain_g[0];
  ctrl_DP_sind(&rtb_Row1);
  i = ctrl_DP_B.Gain_g[1];
  ctrl_DP_sind(&i);
  j = ctrl_DP_B.Gain_g[2];
  ctrl_DP_sind(&j);
  k = ctrl_DP_B.Gain_g[3];
  ctrl_DP_sind(&k);
  l = ctrl_DP_B.Gain_g[4];
  ctrl_DP_sind(&l);
  m = ctrl_DP_B.Gain_g[5];
  ctrl_DP_sind(&m);
  n = ctrl_DP_B.Gain_g[0];
  ctrl_DP_sind(&n);
  o = ctrl_DP_B.Gain_g[0];
  ctrl_DP_cosd(&o);
  p = ctrl_DP_B.Gain_g[1];
  ctrl_DP_sind(&p);
  q = ctrl_DP_B.Gain_g[1];
  ctrl_DP_cosd(&q);
  r = ctrl_DP_B.Gain_g[2];
  ctrl_DP_sind(&r);
  s_0 = ctrl_DP_B.Gain_g[2];
  ctrl_DP_cosd(&s_0);
  t = ctrl_DP_B.Gain_g[3];
  ctrl_DP_sind(&t);
  Alpha1_idx_3 = ctrl_DP_B.Gain_g[3];
  ctrl_DP_cosd(&Alpha1_idx_3);
  v = ctrl_DP_B.Gain_g[4];
  ctrl_DP_sind(&v);
  w = ctrl_DP_B.Gain_g[4];
  ctrl_DP_cosd(&w);
  x = ctrl_DP_B.Gain_g[5];
  ctrl_DP_sind(&x);
  y = ctrl_DP_B.Gain_g[5];
  ctrl_DP_cosd(&y);
  absx31_0[0] = absx31;
  absx31_0[3] = Alpha1_idx_2;
  absx31_0[6] = Alpha1_idx_4;
  absx31_0[9] = e_0;
  absx31_0[12] = f_0;
  absx31_0[15] = rtb_Row2;
  absx31_0[1] = rtb_Row1;
  absx31_0[4] = i;
  absx31_0[7] = j;
  absx31_0[10] = k;
  absx31_0[13] = l;
  absx31_0[16] = m;
  absx31_0[2] = n * ctrl_DP_P.XpositionThruster_Value_e[0] - o *
    ctrl_DP_P.YpositionThruster_Value_o[0];
  absx31_0[5] = p * ctrl_DP_P.XpositionThruster_Value_e[1] - q *
    ctrl_DP_P.YpositionThruster_Value_o[1];
  absx31_0[8] = r * ctrl_DP_P.XpositionThruster_Value_e[2] - s_0 *
    ctrl_DP_P.YpositionThruster_Value_o[2];
  absx31_0[11] = t * ctrl_DP_P.XpositionThruster_Value_e[3] - Alpha1_idx_3 *
    ctrl_DP_P.YpositionThruster_Value_o[3];
  absx31_0[14] = v * ctrl_DP_P.XpositionThruster_Value_e[4] - w *
    ctrl_DP_P.YpositionThruster_Value_o[4];
  absx31_0[17] = x * ctrl_DP_P.XpositionThruster_Value_e[5] - y *
    ctrl_DP_P.YpositionThruster_Value_o[5];
  for (i_0 = 0; i_0 < 3; i_0++) {
    ctrl_DP_B.commanded_tau[i_0] = 0.0;
    for (ixstart = 0; ixstart < 6; ixstart++) {
      ctrl_DP_B.commanded_tau[i_0] += absx31_0[3 * ixstart + i_0] *
        ctrl_DP_B.Saturation7[ixstart];
    }
  }

  /* End of MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */

  /* Integrator: '<S18>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_PrevZCX.Integrator2_Reset_ZCE_h,
                       (ctrl_DP_B.reset));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator2_CSTATE_c[0] = ctrl_DP_P.Integrator2_IC_p;
      ctrl_DP_X.Integrator2_CSTATE_c[1] = ctrl_DP_P.Integrator2_IC_p;
      ctrl_DP_X.Integrator2_CSTATE_c[2] = ctrl_DP_P.Integrator2_IC_p;
    }
  }

  /* MATLAB Function: '<S18>/w_d^-2' */
  /* MATLAB Function 'Guidance/Reference model/w_d^3': '<S23>:1' */
  /* '<S23>:1:4' */
  /* MATLAB Function 'Guidance/Reference model/w_d^-2': '<S22>:1' */
  /* '<S22>:1:4' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (ixstart = 0; ixstart < 3; ixstart++) {
      U_singular[ixstart + 3 * i_0] = 0.0;
      U_singular[ixstart + 3 * i_0] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * i_0] *
        ctrl_DP_B.sf_MATLABFunction_d.y[ixstart];
      U_singular[ixstart + 3 * i_0] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * i_0 +
        1] * ctrl_DP_B.sf_MATLABFunction_d.y[ixstart + 3];
      U_singular[ixstart + 3 * i_0] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * i_0 +
        2] * ctrl_DP_B.sf_MATLABFunction_d.y[ixstart + 6];
    }
  }

  memcpy(&S_singular_cross[0], &U_singular[0], 9U * sizeof(real_T));
  ixstart = 0;
  p2 = 3;
  p3 = 6;
  rtb_Row2 = fabs(U_singular[0]);
  rtb_Row1 = fabs(U_singular[1]);
  absx31 = fabs(U_singular[2]);
  if ((rtb_Row1 > rtb_Row2) && (rtb_Row1 > absx31)) {
    ixstart = 3;
    p2 = 0;
    S_singular_cross[0] = U_singular[1];
    S_singular_cross[1] = U_singular[0];
    S_singular_cross[3] = U_singular[4];
    S_singular_cross[4] = U_singular[3];
    S_singular_cross[6] = U_singular[7];
    S_singular_cross[7] = U_singular[6];
  } else {
    if (absx31 > rtb_Row2) {
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

  rtb_Row2 = S_singular_cross[1] / S_singular_cross[0];
  S_singular_cross[1] /= S_singular_cross[0];
  rtb_Row1 = S_singular_cross[2] / S_singular_cross[0];
  S_singular_cross[2] /= S_singular_cross[0];
  S_singular_cross[4] -= rtb_Row2 * S_singular_cross[3];
  S_singular_cross[5] -= rtb_Row1 * S_singular_cross[3];
  S_singular_cross[7] -= rtb_Row2 * S_singular_cross[6];
  S_singular_cross[8] -= rtb_Row1 * S_singular_cross[6];
  if (fabs(S_singular_cross[5]) > fabs(S_singular_cross[4])) {
    i_0 = p2;
    p2 = p3;
    p3 = i_0;
    S_singular_cross[1] = rtb_Row1;
    S_singular_cross[2] = rtb_Row2;
    rtb_Row2 = S_singular_cross[4];
    S_singular_cross[4] = S_singular_cross[5];
    S_singular_cross[5] = rtb_Row2;
    rtb_Row2 = S_singular_cross[7];
    S_singular_cross[7] = S_singular_cross[8];
    S_singular_cross[8] = rtb_Row2;
  }

  rtb_Row2 = S_singular_cross[5] / S_singular_cross[4];
  S_singular_cross[5] /= S_singular_cross[4];
  S_singular_cross[8] -= rtb_Row2 * S_singular_cross[7];
  rtb_Row2 = (S_singular_cross[5] * S_singular_cross[1] - S_singular_cross[2]) /
    S_singular_cross[8];
  rtb_Row1 = -(S_singular_cross[7] * rtb_Row2 + S_singular_cross[1]) /
    S_singular_cross[4];
  rtb_y_b[ixstart] = ((1.0 - S_singular_cross[3] * rtb_Row1) - S_singular_cross
                      [6] * rtb_Row2) / S_singular_cross[0];
  rtb_y_b[ixstart + 1] = rtb_Row1;
  rtb_y_b[ixstart + 2] = rtb_Row2;
  rtb_Row2 = -S_singular_cross[5] / S_singular_cross[8];
  rtb_Row1 = (1.0 - S_singular_cross[7] * rtb_Row2) / S_singular_cross[4];
  rtb_y_b[p2] = -(S_singular_cross[3] * rtb_Row1 + S_singular_cross[6] *
                  rtb_Row2) / S_singular_cross[0];
  rtb_y_b[p2 + 1] = rtb_Row1;
  rtb_y_b[p2 + 2] = rtb_Row2;
  rtb_Row2 = 1.0 / S_singular_cross[8];
  rtb_Row1 = -S_singular_cross[7] * rtb_Row2 / S_singular_cross[4];
  rtb_y_b[p3] = -(S_singular_cross[3] * rtb_Row1 + S_singular_cross[6] *
                  rtb_Row2) / S_singular_cross[0];
  rtb_y_b[p3 + 1] = rtb_Row1;
  rtb_y_b[p3 + 2] = rtb_Row2;

  /* End of MATLAB Function: '<S18>/w_d^-2' */

  /* Sum: '<S18>/Sum' */
  tmp_4[0] = ctrl_DP_B.x_ref;
  tmp_4[1] = ctrl_DP_B.y_ref;
  tmp_4[2] = ctrl_DP_B.psi_ref;
  for (i_0 = 0; i_0 < 3; i_0++) {
    /* Product: '<S18>/Matrix Multiply1' incorporates:
     *  Sum: '<S18>/Sum'
     */
    rtb_y_m[i_0] = 0.0;
    for (ixstart = 0; ixstart < 3; ixstart++) {
      /* MATLAB Function: '<S18>/w_d^3' */
      tmp_3[i_0 + 3 * ixstart] = 0.0;
      tmp_3[i_0 + 3 * ixstart] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * ixstart] *
        ctrl_DP_B.sf_MATLABFunction_d.y[i_0];
      tmp_3[i_0 + 3 * ixstart] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * ixstart +
        1] * ctrl_DP_B.sf_MATLABFunction_d.y[i_0 + 3];
      tmp_3[i_0 + 3 * ixstart] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * ixstart +
        2] * ctrl_DP_B.sf_MATLABFunction_d.y[i_0 + 6];

      /* Product: '<S18>/Matrix Multiply1' incorporates:
       *  Integrator: '<S18>/Integrator2'
       *  Sum: '<S18>/Sum'
       */
      rtb_y_m[i_0] += rtb_y_b[3 * ixstart + i_0] *
        ctrl_DP_X.Integrator2_CSTATE_c[ixstart];
    }
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    /* MATLAB Function: '<S18>/w_d^3' incorporates:
     *  Product: '<S18>/Matrix Multiply'
     */
    for (ixstart = 0; ixstart < 3; ixstart++) {
      S_singular_cross[i_0 + 3 * ixstart] = 0.0;
      S_singular_cross[i_0 + 3 * ixstart] += tmp_3[3 * ixstart] *
        ctrl_DP_B.sf_MATLABFunction_d.y[i_0];
      S_singular_cross[i_0 + 3 * ixstart] += tmp_3[3 * ixstart + 1] *
        ctrl_DP_B.sf_MATLABFunction_d.y[i_0 + 3];
      S_singular_cross[i_0 + 3 * ixstart] += tmp_3[3 * ixstart + 2] *
        ctrl_DP_B.sf_MATLABFunction_d.y[i_0 + 6];
    }

    /* Sum: '<S18>/Sum' incorporates:
     *  Product: '<S18>/Matrix Multiply'
     */
    tmp_0[i_0] = tmp_4[i_0] - rtb_y_m[i_0];
  }

  /* MATLAB Function 'Guidance/Reference model/w_d*w_d': '<S20>:1' */
  /* '<S20>:1:4' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    /* Product: '<S18>/Matrix Multiply' */
    ctrl_DP_B.MatrixMultiply[i_0] = 0.0;

    /* Product: '<S18>/Matrix Multiply2' */
    rtb_Sum3[i_0] = 0.0;
    for (ixstart = 0; ixstart < 3; ixstart++) {
      /* Product: '<S18>/Matrix Multiply' */
      ctrl_DP_B.MatrixMultiply[i_0] += S_singular_cross[3 * ixstart + i_0] *
        tmp_0[ixstart];

      /* MATLAB Function: '<S18>/w_d*w_d' incorporates:
       *  Product: '<S18>/Matrix Multiply2'
       */
      tmp_3[i_0 + 3 * ixstart] = 0.0;
      tmp_3[i_0 + 3 * ixstart] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * ixstart] *
        ctrl_DP_B.sf_MATLABFunction_d.y[i_0];
      tmp_3[i_0 + 3 * ixstart] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * ixstart +
        1] * ctrl_DP_B.sf_MATLABFunction_d.y[i_0 + 3];
      tmp_3[i_0 + 3 * ixstart] += ctrl_DP_B.sf_MATLABFunction_d.y[3 * ixstart +
        2] * ctrl_DP_B.sf_MATLABFunction_d.y[i_0 + 6];

      /* Product: '<S18>/Matrix Multiply2' */
      rtb_Sum3[i_0] += tmp_3[3 * ixstart + i_0] *
        rtb_TmpSignalConversionAtMatrix[ixstart];
    }
  }

  /* MATLAB Function: '<S25>/MATLAB Function1' */
  ctrl_DP_MATLABFunction(ctrl_DP_B.zeta_x, ctrl_DP_B.zeta_y, ctrl_DP_B.zeta_psi,
    &ctrl_DP_B.sf_MATLABFunction1_c);  /* MATLAB Function 'Guidance/Reference model/w_d*w_d1': '<S21>:1' */

  /* '<S21>:1:4' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    /* Sum: '<S18>/Sum5' */
    absx31 = 0.0;
    for (ixstart = 0; ixstart < 3; ixstart++) {
      /* MATLAB Function: '<S18>/w_d*w_d1' incorporates:
       *  Product: '<S18>/Matrix Multiply5'
       */
      tmp_3[i_0 + 3 * ixstart] = 0.0;
      tmp_3[i_0 + 3 * ixstart] += 2.0 * ctrl_DP_B.sf_MATLABFunction1_c.y[i_0] *
        ctrl_DP_B.sf_MATLABFunction_d.y[3 * ixstart];
      tmp_3[i_0 + 3 * ixstart] += ctrl_DP_B.sf_MATLABFunction1_c.y[i_0 + 3] *
        2.0 * ctrl_DP_B.sf_MATLABFunction_d.y[3 * ixstart + 1];
      tmp_3[i_0 + 3 * ixstart] += ctrl_DP_B.sf_MATLABFunction1_c.y[i_0 + 6] *
        2.0 * ctrl_DP_B.sf_MATLABFunction_d.y[3 * ixstart + 2];

      /* Sum: '<S18>/Sum5' incorporates:
       *  Product: '<S18>/Matrix Multiply5'
       */
      absx31 += tmp_3[3 * ixstart + i_0] * ctrl_DP_B.Integrator3[ixstart];
    }

    /* Sum: '<S18>/Sum5' incorporates:
     *  Integrator: '<S18>/Integrator2'
     *  Product: '<S18>/Matrix Multiply5'
     *  Sum: '<S18>/Sum2'
     */
    ctrl_DP_B.Sum5[i_0] = (ctrl_DP_X.Integrator2_CSTATE_c[i_0] - rtb_Sum3[i_0])
      - absx31;
  }

  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* MATLAB Function: '<S26>/MATLAB Function' incorporates:
     *  Constant: '<S26>/Constant'
     *  Constant: '<S26>/Constant1'
     *  Constant: '<S26>/Constant2'
     */
    ctrl_DP_MATLABFunction(ctrl_DP_P.Constant_Value_c,
      ctrl_DP_P.Constant1_Value_p, ctrl_DP_P.Constant2_Value,
      &ctrl_DP_B.sf_MATLABFunction_p);

    /* MATLAB Function: '<S26>/MATLAB Function1' incorporates:
     *  Constant: '<S26>/Constant3'
     *  Constant: '<S26>/Constant4'
     *  Constant: '<S26>/Constant5'
     */
    ctrl_DP_MATLABFunction(ctrl_DP_P.Constant3_Value, ctrl_DP_P.Constant4_Value,
      ctrl_DP_P.Constant5_Value, &ctrl_DP_B.sf_MATLABFunction1_k);
  }

  /* Sum: '<S5>/Sum1' incorporates:
   *  Fcn: '<S37>/Fcn'
   *  Fcn: '<S37>/Fcn1'
   *  Fcn: '<S37>/Fcn2'
   */
  rtb_Row2_0[0] = cos(rtb_psi_dot) * ctrl_DP_B.Integrator1_c[0] - sin
    (rtb_psi_dot) * ctrl_DP_B.Integrator1_c[1];
  rtb_Row2_0[1] = sin(rtb_psi_dot) * ctrl_DP_B.Integrator1_c[0] + cos
    (rtb_psi_dot) * ctrl_DP_B.Integrator1_c[1];
  rtb_Row2_0[2] = ctrl_DP_B.Integrator1_c[2];
  for (i_0 = 0; i_0 < 3; i_0++) {
    /* Product: '<S5>/Matrix Multiply1' */
    ctrl_DP_B.MatrixMultiply1[i_0] = 0.0;
    ctrl_DP_B.MatrixMultiply1[i_0] += ctrl_DP_B.sf_MATLABFunction1_k.y[i_0] *
      tc[0];
    ctrl_DP_B.MatrixMultiply1[i_0] += ctrl_DP_B.sf_MATLABFunction1_k.y[i_0 + 3] *
      tc[1];
    ctrl_DP_B.MatrixMultiply1[i_0] += ctrl_DP_B.sf_MATLABFunction1_k.y[i_0 + 6] *
      tc[2];

    /* Sum: '<S5>/Sum1' incorporates:
     *  Product: '<S5>/Matrix Multiply'
     */
    ctrl_DP_B.Sum1[i_0] = (ctrl_DP_B.sf_MATLABFunction_p.y[i_0 + 6] * tc[2] +
      (ctrl_DP_B.sf_MATLABFunction_p.y[i_0 + 3] * tc[1] +
       ctrl_DP_B.sf_MATLABFunction_p.y[i_0] * tc[0])) + rtb_Row2_0[i_0];
  }

  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Delay: '<S11>/Delay' */
    for (i_0 = 0; i_0 < 6; i_0++) {
      ctrl_DP_B.Delay[i_0] = ctrl_DP_DW.Delay_DSTATE[i_0];
    }

    /* End of Delay: '<S11>/Delay' */

    /* Delay: '<S55>/Delay' */
    ctrl_DP_B.Delay_e = ctrl_DP_DW.Delay_DSTATE_f;

    /* Delay: '<S70>/Delay' */
    ctrl_DP_B.Delay_a = ctrl_DP_DW.Delay_DSTATE_fu;
  }

  /* MATLAB Function: '<S70>/MATLAB Function' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Tf1'
   *  Constant: '<S10>/K_Tr1'
   *  Constant: '<S10>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/MATLAB Function': '<S74>:1' */
  /* '<S74>:1:5' */
  if (rtb_sys[6] < 0.0) {
    absx31 = -1.0;
  } else if (rtb_sys[6] > 0.0) {
    absx31 = 1.0;
  } else if (rtb_sys[6] == 0.0) {
    absx31 = 0.0;
  } else {
    absx31 = rtb_sys[6];
  }

  rtb_Row2 = sqrt(fabs(rtb_sys[6]) / (ctrl_DP_P.Rho * rt_powd_snf(ctrl_DP_P.D,
    4.0) * ctrl_DP_P.K_T1f)) * absx31;

  /* '<S74>:1:7' */
  rtb_psi_dot = tanh(ctrl_DP_P.eps_c * rtb_Row2 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S74>:1:8' */
  /* '<S74>:1:10' */
  if (ctrl_DP_B.Delay_a < 0.0) {
    absx31 = -1.0;
  } else if (ctrl_DP_B.Delay_a > 0.0) {
    absx31 = 1.0;
  } else if (ctrl_DP_B.Delay_a == 0.0) {
    absx31 = 0.0;
  } else {
    absx31 = ctrl_DP_B.Delay_a;
  }

  rtb_T_r_l = ((1.0 - rtb_psi_dot) * ctrl_DP_P.K_T1r + ctrl_DP_P.K_T1f *
               rtb_psi_dot) * absx31 * ctrl_DP_P.Rho * rt_powd_snf(ctrl_DP_P.D,
    4.0) * (ctrl_DP_B.Delay_a * ctrl_DP_B.Delay_a);
  ctrl_DP_B.n_d_l = rtb_Row2;

  /* End of MATLAB Function: '<S70>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* DiscreteTransferFcn: '<S70>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S70>/Constant1'
     *  Constant: '<S70>/Constant2'
     */
    ctrl_DP_DW.DiscreteTransferFcn_tmp = (ctrl_DP_B.n_d_l -
      ctrl_DP_P.Constant2_Value_b[1] * ctrl_DP_DW.DiscreteTransferFcn_states[0])
      - ctrl_DP_P.Constant2_Value_b[2] * ctrl_DP_DW.DiscreteTransferFcn_states[1];
    ctrl_DP_B.DiscreteTransferFcn = (ctrl_DP_P.Constant1_Value_o[0] *
      ctrl_DP_DW.DiscreteTransferFcn_tmp + ctrl_DP_P.Constant1_Value_o[1] *
      ctrl_DP_DW.DiscreteTransferFcn_states[0]) + ctrl_DP_P.Constant1_Value_o[2]
      * ctrl_DP_DW.DiscreteTransferFcn_states[1];

    /* SampleTimeMath: '<S73>/TSamp'
     *
     * About '<S73>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_DP_B.TSamp = ctrl_DP_B.DiscreteTransferFcn * ctrl_DP_P.TSamp_WtEt;

    /* Sum: '<S73>/Diff' incorporates:
     *  UnitDelay: '<S73>/UD'
     */
    rtb_Sum_b = ctrl_DP_B.TSamp - ctrl_DP_DW.UD_DSTATE;

    /* RateLimiter: '<S70>/Acceleration Limit' */
    rtb_psi_dot = rtb_Sum_b - ctrl_DP_DW.PrevY;
    if (rtb_psi_dot > ctrl_DP_P.AccelerationLimit_RisingLim) {
      rtb_Sum_b = ctrl_DP_DW.PrevY + ctrl_DP_P.AccelerationLimit_RisingLim;
    } else {
      if (rtb_psi_dot < ctrl_DP_P.AccelerationLimit_FallingLim) {
        rtb_Sum_b = ctrl_DP_DW.PrevY + ctrl_DP_P.AccelerationLimit_FallingLim;
      }
    }

    ctrl_DP_DW.PrevY = rtb_Sum_b;

    /* End of RateLimiter: '<S70>/Acceleration Limit' */

    /* Gain: '<S70>/Inertia compensation' */
    ctrl_DP_B.Inertiacompensation = ctrl_DP_P.I_s * 2.0 * 3.1415926535897931 *
      rtb_Sum_b;

    /* Sum: '<S70>/Sum1' incorporates:
     *  Gain: '<S70>/Qf_0'
     *  Gain: '<S70>/Qff_0(nr)'
     *  Gain: '<S70>/Qff_1(nr)'
     *  Trigonometry: '<S70>/Trigonometric Function'
     */
    ctrl_DP_B.Sum1_n = tanh(ctrl_DP_P.epsilon / ctrl_DP_P.n_max *
      ctrl_DP_B.DiscreteTransferFcn) * ctrl_DP_P.Q_f0 + ctrl_DP_P.K_omega * 2.0 *
      3.1415926535897931 * ctrl_DP_B.DiscreteTransferFcn;

    /* Memory: '<S70>/Memory' */
    ctrl_DP_B.Memory = ctrl_DP_DW.Memory_PreviousInput;

    /* Sum: '<S72>/Sum' */
    rtb_Sum_b = ctrl_DP_B.DiscreteTransferFcn - ctrl_DP_B.Delay[0];

    /* Gain: '<S72>/Kp' */
    ctrl_DP_B.Kp = ctrl_DP_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S72>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_PrevZCX.Integrator_Reset_ZCE_o3,
                       (ctrl_DP_B.reset_kk));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_e = ctrl_DP_P.Integrator_IC_a;
    }
  }

  /* MATLAB Function: '<S72>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Qr1'
   *  Constant: '<S10>/K_Qr7'
   *  Constant: '<S10>/K_Tf1'
   *  Constant: '<S10>/K_Tr1'
   *  Constant: '<S10>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_DP_P.k_cc, ctrl_DP_P.p_cc, ctrl_DP_P.r_cc,
    ctrl_DP_B.Delay[0], ctrl_DP_P.K_T1f, ctrl_DP_P.K_q1f, ctrl_DP_P.D, rtb_T_r_l,
    ctrl_DP_P.Rho, ctrl_DP_P.eps_c, ctrl_DP_P.K_T1r, ctrl_DP_P.K_q1r,
    &ctrl_DP_B.sf_CorecontrollerTorquePowerand);

  /* MultiPortSwitch: '<S70>/Controller chosen' incorporates:
   *  Constant: '<S70>/NaN'
   *  Integrator: '<S72>/Integrator'
   *  Sum: '<S72>/Sum1'
   */
  switch ((int32_T)ctrl_DP_B.Memory) {
   case 1:
    rtb_Row2 = ctrl_DP_B.Kp + ctrl_DP_X.Integrator_CSTATE_e;
    break;

   case 2:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePowerand.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePowerand.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePowerand.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_DP_P.NaN_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S70>/Controller chosen' */

  /* Sum: '<S70>/Sum' */
  ctrl_DP_B.Sum_k = (ctrl_DP_B.Inertiacompensation + ctrl_DP_B.Sum1_n) +
    rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* DiscreteTransferFcn: '<S55>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S55>/Constant'
     *  Constant: '<S55>/Constant1'
     */
    ctrl_DP_DW.DiscreteTransferFcn_tmp_a = ctrl_DP_B.Sum_k -
      ctrl_DP_P.Constant_Value_cs[1] * ctrl_DP_DW.DiscreteTransferFcn_states_d;
    ctrl_DP_B.DiscreteTransferFcn_d = ctrl_DP_P.Constant1_Value_k[0] *
      ctrl_DP_DW.DiscreteTransferFcn_tmp_a + ctrl_DP_P.Constant1_Value_k[1] *
      ctrl_DP_DW.DiscreteTransferFcn_states_d;
  }

  /* Gain: '<S69>/Finding rotation speed' incorporates:
   *  Gain: '<S69>/K_omega'
   *  Integrator: '<S69>/Integrator'
   *  Sum: '<S69>/Sum'
   */
  ctrl_DP_B.Findingrotationspeed = ((ctrl_DP_B.DiscreteTransferFcn_d -
    ctrl_DP_B.Delay_e) - ctrl_DP_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_DP_X.Integrator_CSTATE_c) * (1.0 / (6.2831853071795862 * ctrl_DP_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Gain: '<S72>/Ki' */
    ctrl_DP_B.Ki = ctrl_DP_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S70>/Supervisor' */
    ctrl_DP_Supervisor(ctrl_DP_B.Memory, 0.0, ctrl_DP_B.Delay[0],
                       &ctrl_DP_B.sf_Supervisor);

    /* Delay: '<S56>/Delay' */
    ctrl_DP_B.Delay_b = ctrl_DP_DW.Delay_DSTATE_b;

    /* Delay: '<S79>/Delay' */
    ctrl_DP_B.Delay_bs = ctrl_DP_DW.Delay_DSTATE_d;
  }

  /* MATLAB Function: '<S79>/MATLAB Function' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Tf2'
   *  Constant: '<S10>/K_Tr2'
   *  Constant: '<S10>/Rho'
   */
  ctrl_DP_MATLABFunction_i(rtb_sys[7], ctrl_DP_P.K_T2f, ctrl_DP_P.K_T2r,
    ctrl_DP_P.Rho, ctrl_DP_P.D, ctrl_DP_P.eps_c, ctrl_DP_B.Delay_bs,
    &ctrl_DP_B.sf_MATLABFunction_i);
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* DiscreteTransferFcn: '<S79>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S79>/Constant1'
     *  Constant: '<S79>/Constant2'
     */
    ctrl_DP_DW.DiscreteTransferFcn_tmp_d = (ctrl_DP_B.sf_MATLABFunction_i.n_d -
      ctrl_DP_P.Constant2_Value_i[1] * ctrl_DP_DW.DiscreteTransferFcn_states_h[0])
      - ctrl_DP_P.Constant2_Value_i[2] *
      ctrl_DP_DW.DiscreteTransferFcn_states_h[1];
    ctrl_DP_B.DiscreteTransferFcn_e = (ctrl_DP_P.Constant1_Value_b[0] *
      ctrl_DP_DW.DiscreteTransferFcn_tmp_d + ctrl_DP_P.Constant1_Value_b[1] *
      ctrl_DP_DW.DiscreteTransferFcn_states_h[0]) + ctrl_DP_P.Constant1_Value_b
      [2] * ctrl_DP_DW.DiscreteTransferFcn_states_h[1];

    /* SampleTimeMath: '<S82>/TSamp'
     *
     * About '<S82>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_DP_B.TSamp_n = ctrl_DP_B.DiscreteTransferFcn_e * ctrl_DP_P.TSamp_WtEt_k;

    /* Sum: '<S82>/Diff' incorporates:
     *  UnitDelay: '<S82>/UD'
     */
    rtb_Sum_b = ctrl_DP_B.TSamp_n - ctrl_DP_DW.UD_DSTATE_n;

    /* RateLimiter: '<S79>/Acceleration Limit' */
    rtb_psi_dot = rtb_Sum_b - ctrl_DP_DW.PrevY_e;
    if (rtb_psi_dot > ctrl_DP_P.AccelerationLimit_RisingLim_n) {
      rtb_Sum_b = ctrl_DP_DW.PrevY_e + ctrl_DP_P.AccelerationLimit_RisingLim_n;
    } else {
      if (rtb_psi_dot < ctrl_DP_P.AccelerationLimit_FallingLim_n) {
        rtb_Sum_b = ctrl_DP_DW.PrevY_e +
          ctrl_DP_P.AccelerationLimit_FallingLim_n;
      }
    }

    ctrl_DP_DW.PrevY_e = rtb_Sum_b;

    /* End of RateLimiter: '<S79>/Acceleration Limit' */

    /* Gain: '<S79>/Inertia compensation' */
    ctrl_DP_B.Inertiacompensation_e = ctrl_DP_P.I_s * 2.0 * 3.1415926535897931 *
      rtb_Sum_b;

    /* Sum: '<S79>/Sum1' incorporates:
     *  Gain: '<S79>/Qf_0'
     *  Gain: '<S79>/Qff_0(nr)'
     *  Gain: '<S79>/Qff_1(nr)'
     *  Trigonometry: '<S79>/Trigonometric Function'
     */
    ctrl_DP_B.Sum1_nn = tanh(ctrl_DP_P.epsilon / ctrl_DP_P.n_max *
      ctrl_DP_B.DiscreteTransferFcn_e) * ctrl_DP_P.Q_f0 + ctrl_DP_P.K_omega *
      2.0 * 3.1415926535897931 * ctrl_DP_B.DiscreteTransferFcn_e;

    /* Memory: '<S79>/Memory' */
    ctrl_DP_B.Memory_c = ctrl_DP_DW.Memory_PreviousInput_n;

    /* Sum: '<S81>/Sum' */
    rtb_Sum_b = ctrl_DP_B.DiscreteTransferFcn_e - ctrl_DP_B.Delay[1];

    /* Gain: '<S81>/Kp' */
    ctrl_DP_B.Kp_p = ctrl_DP_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S81>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_PrevZCX.Integrator_Reset_ZCE_db,
                       (ctrl_DP_B.reset_e));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_g = ctrl_DP_P.Integrator_IC_fy;
    }
  }

  /* MATLAB Function: '<S81>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Qr2'
   *  Constant: '<S10>/K_Qr8'
   *  Constant: '<S10>/K_Tf2'
   *  Constant: '<S10>/K_Tr2'
   *  Constant: '<S10>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_DP_P.k_cc, ctrl_DP_P.p_cc, ctrl_DP_P.r_cc,
    ctrl_DP_B.Delay[1], ctrl_DP_P.K_T2f, ctrl_DP_P.K_q2f, ctrl_DP_P.D,
    ctrl_DP_B.sf_MATLABFunction_i.T_r, ctrl_DP_P.Rho, ctrl_DP_P.eps_c,
    ctrl_DP_P.K_T2r, ctrl_DP_P.K_q2r, &ctrl_DP_B.sf_CorecontrollerTorquePowera_o);

  /* MultiPortSwitch: '<S79>/Controller chosen' incorporates:
   *  Constant: '<S79>/NaN'
   *  Integrator: '<S81>/Integrator'
   *  Sum: '<S81>/Sum1'
   */
  switch ((int32_T)ctrl_DP_B.Memory_c) {
   case 1:
    rtb_Row2 = ctrl_DP_B.Kp_p + ctrl_DP_X.Integrator_CSTATE_g;
    break;

   case 2:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePowera_o.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePowera_o.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePowera_o.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_DP_P.NaN_Value_l;
    break;
  }

  /* End of MultiPortSwitch: '<S79>/Controller chosen' */

  /* Sum: '<S79>/Sum' */
  ctrl_DP_B.Sum_h = (ctrl_DP_B.Inertiacompensation_e + ctrl_DP_B.Sum1_nn) +
    rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* DiscreteTransferFcn: '<S56>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S56>/Constant'
     *  Constant: '<S56>/Constant1'
     */
    ctrl_DP_DW.DiscreteTransferFcn_tmp_h = ctrl_DP_B.Sum_h -
      ctrl_DP_P.Constant_Value_h[1] * ctrl_DP_DW.DiscreteTransferFcn_states_m;
    ctrl_DP_B.DiscreteTransferFcn_k = ctrl_DP_P.Constant1_Value_j[0] *
      ctrl_DP_DW.DiscreteTransferFcn_tmp_h + ctrl_DP_P.Constant1_Value_j[1] *
      ctrl_DP_DW.DiscreteTransferFcn_states_m;
  }

  /* Gain: '<S78>/Finding rotation speed' incorporates:
   *  Gain: '<S78>/K_omega'
   *  Sum: '<S78>/Sum'
   */
  ctrl_DP_B.Findingrotationspeed_a = ((ctrl_DP_B.DiscreteTransferFcn_k -
    ctrl_DP_B.Delay_b) - ctrl_DP_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_h) * (1.0 / (6.2831853071795862 * ctrl_DP_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Gain: '<S81>/Ki' */
    ctrl_DP_B.Ki_o = ctrl_DP_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S79>/Supervisor' */
    ctrl_DP_Supervisor(ctrl_DP_B.Memory_c, 0.0, ctrl_DP_B.Delay[1],
                       &ctrl_DP_B.sf_Supervisor_h);

    /* Delay: '<S57>/Delay' */
    ctrl_DP_B.Delay_i = ctrl_DP_DW.Delay_DSTATE_n;

    /* Delay: '<S88>/Delay' */
    ctrl_DP_B.Delay_by = ctrl_DP_DW.Delay_DSTATE_no;
  }

  /* MATLAB Function: '<S88>/MATLAB Function' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Tf3'
   *  Constant: '<S10>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 3/Thruster control/MATLAB Function': '<S92>:1' */
  /* '<S92>:1:5' */
  if (rtb_sys[8] < 0.0) {
    absx31 = -1.0;
  } else if (rtb_sys[8] > 0.0) {
    absx31 = 1.0;
  } else if (rtb_sys[8] == 0.0) {
    absx31 = 0.0;
  } else {
    absx31 = rtb_sys[8];
  }

  rtb_Row2 = sqrt(fabs(rtb_sys[8]) / (ctrl_DP_P.Rho * rt_powd_snf(ctrl_DP_P.D,
    4.0) * ctrl_DP_P.K_T3f)) * absx31;

  /* '<S92>:1:7' */
  rtb_psi_dot = tanh(ctrl_DP_P.eps_c * rtb_Row2 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S92>:1:8' */
  /* '<S92>:1:10' */
  if (ctrl_DP_B.Delay_by < 0.0) {
    absx31 = -1.0;
  } else if (ctrl_DP_B.Delay_by > 0.0) {
    absx31 = 1.0;
  } else if (ctrl_DP_B.Delay_by == 0.0) {
    absx31 = 0.0;
  } else {
    absx31 = ctrl_DP_B.Delay_by;
  }

  rtb_T_r_p = ((1.0 - rtb_psi_dot) * ctrl_DP_P.K_T3f + ctrl_DP_P.K_T3f *
               rtb_psi_dot) * absx31 * ctrl_DP_P.Rho * rt_powd_snf(ctrl_DP_P.D,
    4.0) * (ctrl_DP_B.Delay_by * ctrl_DP_B.Delay_by);
  ctrl_DP_B.n_d_j = rtb_Row2;

  /* End of MATLAB Function: '<S88>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* DiscreteTransferFcn: '<S88>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S88>/Constant1'
     *  Constant: '<S88>/Constant2'
     */
    ctrl_DP_DW.DiscreteTransferFcn_tmp_e = (ctrl_DP_B.n_d_j -
      ctrl_DP_P.Constant2_Value_h[1] * ctrl_DP_DW.DiscreteTransferFcn_states_j[0])
      - ctrl_DP_P.Constant2_Value_h[2] *
      ctrl_DP_DW.DiscreteTransferFcn_states_j[1];
    ctrl_DP_B.DiscreteTransferFcn_f = (ctrl_DP_P.Constant1_Value_g[0] *
      ctrl_DP_DW.DiscreteTransferFcn_tmp_e + ctrl_DP_P.Constant1_Value_g[1] *
      ctrl_DP_DW.DiscreteTransferFcn_states_j[0]) + ctrl_DP_P.Constant1_Value_g
      [2] * ctrl_DP_DW.DiscreteTransferFcn_states_j[1];

    /* SampleTimeMath: '<S91>/TSamp'
     *
     * About '<S91>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_DP_B.TSamp_k = ctrl_DP_B.DiscreteTransferFcn_f * ctrl_DP_P.TSamp_WtEt_m;

    /* Sum: '<S91>/Diff' incorporates:
     *  UnitDelay: '<S91>/UD'
     */
    rtb_Sum_b = ctrl_DP_B.TSamp_k - ctrl_DP_DW.UD_DSTATE_i;

    /* RateLimiter: '<S88>/Acceleration limiter' */
    rtb_psi_dot = rtb_Sum_b - ctrl_DP_DW.PrevY_o;
    if (rtb_psi_dot > ctrl_DP_P.Accelerationlimiter_RisingLim) {
      rtb_Sum_b = ctrl_DP_DW.PrevY_o + ctrl_DP_P.Accelerationlimiter_RisingLim;
    } else {
      if (rtb_psi_dot < ctrl_DP_P.Accelerationlimiter_FallingLim) {
        rtb_Sum_b = ctrl_DP_DW.PrevY_o +
          ctrl_DP_P.Accelerationlimiter_FallingLim;
      }
    }

    ctrl_DP_DW.PrevY_o = rtb_Sum_b;

    /* End of RateLimiter: '<S88>/Acceleration limiter' */

    /* Gain: '<S88>/Inertia compensation' */
    ctrl_DP_B.Inertiacompensation_c = ctrl_DP_P.I_s * 2.0 * 3.1415926535897931 *
      rtb_Sum_b;

    /* Sum: '<S88>/Sum1' incorporates:
     *  Gain: '<S88>/Qf_0'
     *  Gain: '<S88>/Qff_0(nr)'
     *  Gain: '<S88>/Qff_1(nr)'
     *  Trigonometry: '<S88>/Trigonometric Function'
     */
    ctrl_DP_B.Sum1_i = tanh(ctrl_DP_P.epsilon / ctrl_DP_P.n_max *
      ctrl_DP_B.DiscreteTransferFcn_f) * ctrl_DP_P.Q_f0 + ctrl_DP_P.K_omega *
      2.0 * 3.1415926535897931 * ctrl_DP_B.DiscreteTransferFcn_f;

    /* Memory: '<S88>/Memory' */
    ctrl_DP_B.Memory_i = ctrl_DP_DW.Memory_PreviousInput_d;

    /* Sum: '<S90>/Sum' */
    rtb_Sum_b = ctrl_DP_B.DiscreteTransferFcn_f - ctrl_DP_B.Delay[2];

    /* Gain: '<S90>/Kp' */
    ctrl_DP_B.Kp_i = ctrl_DP_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S90>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE_l,
                       (ctrl_DP_B.reset_j2));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_i = ctrl_DP_P.Integrator_IC_j;
    }
  }

  /* MATLAB Function: '<S90>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Qr3'
   *  Constant: '<S10>/K_Qr9'
   *  Constant: '<S10>/K_Tf3'
   *  Constant: '<S10>/K_Tr3'
   *  Constant: '<S10>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_DP_P.k_cc, ctrl_DP_P.p_cc, ctrl_DP_P.r_cc,
    ctrl_DP_B.Delay[2], ctrl_DP_P.K_T3f, ctrl_DP_P.K_q3f, ctrl_DP_P.D, rtb_T_r_p,
    ctrl_DP_P.Rho, ctrl_DP_P.eps_c, ctrl_DP_P.K_T3r, ctrl_DP_P.K_q3r,
    &ctrl_DP_B.sf_CorecontrollerTorquePowera_n);

  /* MultiPortSwitch: '<S88>/Controller chosen' incorporates:
   *  Constant: '<S88>/NaN'
   *  Integrator: '<S90>/Integrator'
   *  Sum: '<S90>/Sum1'
   */
  switch ((int32_T)ctrl_DP_B.Memory_i) {
   case 1:
    rtb_Row2 = ctrl_DP_B.Kp_i + ctrl_DP_X.Integrator_CSTATE_i;
    break;

   case 2:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePowera_n.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePowera_n.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePowera_n.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_DP_P.NaN_Value_g;
    break;
  }

  /* End of MultiPortSwitch: '<S88>/Controller chosen' */

  /* Sum: '<S88>/Sum' */
  ctrl_DP_B.Sum_hf = (ctrl_DP_B.Inertiacompensation_c + ctrl_DP_B.Sum1_i) +
    rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* DiscreteTransferFcn: '<S57>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S57>/Constant'
     *  Constant: '<S57>/Constant1'
     */
    ctrl_DP_DW.DiscreteTransferFcn_tmp_hh = ctrl_DP_B.Sum_hf -
      ctrl_DP_P.Constant_Value_n[1] * ctrl_DP_DW.DiscreteTransferFcn_states_k;
    ctrl_DP_B.DiscreteTransferFcn_n = ctrl_DP_P.Constant1_Value_a[0] *
      ctrl_DP_DW.DiscreteTransferFcn_tmp_hh + ctrl_DP_P.Constant1_Value_a[1] *
      ctrl_DP_DW.DiscreteTransferFcn_states_k;
  }

  /* Gain: '<S87>/Finding rotation speed' incorporates:
   *  Gain: '<S87>/K_omega'
   *  Sum: '<S87>/Sum'
   */
  ctrl_DP_B.Findingrotationspeed_m = ((ctrl_DP_B.DiscreteTransferFcn_n -
    ctrl_DP_B.Delay_i) - ctrl_DP_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_a) * (1.0 / (6.2831853071795862 * ctrl_DP_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Gain: '<S90>/Ki' */
    ctrl_DP_B.Ki_n = ctrl_DP_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S88>/Supervisor' */
    ctrl_DP_Supervisor(ctrl_DP_B.Memory_i, 0.0, ctrl_DP_B.Delay[2],
                       &ctrl_DP_B.sf_Supervisor_l);

    /* Delay: '<S58>/Delay' */
    ctrl_DP_B.Delay_g = ctrl_DP_DW.Delay_DSTATE_e;

    /* Delay: '<S97>/Delay' */
    ctrl_DP_B.Delay_l = ctrl_DP_DW.Delay_DSTATE_i;
  }

  /* MATLAB Function: '<S97>/MATLAB Function' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Tf4'
   *  Constant: '<S10>/K_Tr4'
   *  Constant: '<S10>/Rho'
   */
  ctrl_DP_MATLABFunction_i(rtb_sys[9], ctrl_DP_P.K_T4f, ctrl_DP_P.K_T4r,
    ctrl_DP_P.Rho, ctrl_DP_P.D, ctrl_DP_P.eps_c, ctrl_DP_B.Delay_l,
    &ctrl_DP_B.sf_MATLABFunction_go);
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* DiscreteTransferFcn: '<S97>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S97>/Constant1'
     *  Constant: '<S97>/Constant2'
     */
    ctrl_DP_DW.DiscreteTransferFcn_tmp_k = (ctrl_DP_B.sf_MATLABFunction_go.n_d -
      ctrl_DP_P.Constant2_Value_l[1] * ctrl_DP_DW.DiscreteTransferFcn_states_i[0])
      - ctrl_DP_P.Constant2_Value_l[2] *
      ctrl_DP_DW.DiscreteTransferFcn_states_i[1];
    ctrl_DP_B.DiscreteTransferFcn_l = (ctrl_DP_P.Constant1_Value_m[0] *
      ctrl_DP_DW.DiscreteTransferFcn_tmp_k + ctrl_DP_P.Constant1_Value_m[1] *
      ctrl_DP_DW.DiscreteTransferFcn_states_i[0]) + ctrl_DP_P.Constant1_Value_m
      [2] * ctrl_DP_DW.DiscreteTransferFcn_states_i[1];

    /* SampleTimeMath: '<S100>/TSamp'
     *
     * About '<S100>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_DP_B.TSamp_a = ctrl_DP_B.DiscreteTransferFcn_l * ctrl_DP_P.TSamp_WtEt_h;

    /* Sum: '<S100>/Diff' incorporates:
     *  UnitDelay: '<S100>/UD'
     */
    rtb_Sum_b = ctrl_DP_B.TSamp_a - ctrl_DP_DW.UD_DSTATE_n4;

    /* RateLimiter: '<S97>/Acceleration limiter' */
    rtb_psi_dot = rtb_Sum_b - ctrl_DP_DW.PrevY_c;
    if (rtb_psi_dot > ctrl_DP_P.Accelerationlimiter_RisingLim_e) {
      rtb_Sum_b = ctrl_DP_DW.PrevY_c + ctrl_DP_P.Accelerationlimiter_RisingLim_e;
    } else {
      if (rtb_psi_dot < ctrl_DP_P.Accelerationlimiter_FallingLi_b) {
        rtb_Sum_b = ctrl_DP_DW.PrevY_c +
          ctrl_DP_P.Accelerationlimiter_FallingLi_b;
      }
    }

    ctrl_DP_DW.PrevY_c = rtb_Sum_b;

    /* End of RateLimiter: '<S97>/Acceleration limiter' */

    /* Gain: '<S97>/Inertia compensation' */
    ctrl_DP_B.Inertiacompensation_k = ctrl_DP_P.I_s * 2.0 * 3.1415926535897931 *
      rtb_Sum_b;

    /* Sum: '<S97>/Sum1' incorporates:
     *  Gain: '<S97>/Qf_0'
     *  Gain: '<S97>/Qff_0(nr)'
     *  Gain: '<S97>/Qff_1(nr)'
     *  Trigonometry: '<S97>/Trigonometric Function'
     */
    ctrl_DP_B.Sum1_b = tanh(ctrl_DP_P.epsilon / ctrl_DP_P.n_max *
      ctrl_DP_B.DiscreteTransferFcn_l) * ctrl_DP_P.Q_f0 + ctrl_DP_P.K_omega *
      2.0 * 3.1415926535897931 * ctrl_DP_B.DiscreteTransferFcn_l;

    /* Memory: '<S97>/Memory' */
    ctrl_DP_B.Memory_j = ctrl_DP_DW.Memory_PreviousInput_a;

    /* Sum: '<S99>/Sum' */
    rtb_Sum_b = ctrl_DP_B.DiscreteTransferFcn_l - ctrl_DP_B.Delay[3];

    /* Gain: '<S99>/Kp' */
    ctrl_DP_B.Kp_c = ctrl_DP_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S99>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE_h,
                       (ctrl_DP_B.reset_n));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_l = ctrl_DP_P.Integrator_IC_g;
    }
  }

  /* MATLAB Function: '<S99>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Qr10'
   *  Constant: '<S10>/K_Qr4'
   *  Constant: '<S10>/K_Tf4'
   *  Constant: '<S10>/K_Tr4'
   *  Constant: '<S10>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_DP_P.k_cc, ctrl_DP_P.p_cc, ctrl_DP_P.r_cc,
    ctrl_DP_B.Delay[3], ctrl_DP_P.K_T4f, ctrl_DP_P.K_q4f, ctrl_DP_P.D,
    ctrl_DP_B.sf_MATLABFunction_go.T_r, ctrl_DP_P.Rho, ctrl_DP_P.eps_c,
    ctrl_DP_P.K_T4r, ctrl_DP_P.K_q4r, &ctrl_DP_B.sf_CorecontrollerTorquePower_n3);

  /* MultiPortSwitch: '<S97>/Controller chosen' incorporates:
   *  Constant: '<S97>/NaN'
   *  Integrator: '<S99>/Integrator'
   *  Sum: '<S99>/Sum1'
   */
  switch ((int32_T)ctrl_DP_B.Memory_j) {
   case 1:
    rtb_Row2 = ctrl_DP_B.Kp_c + ctrl_DP_X.Integrator_CSTATE_l;
    break;

   case 2:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePower_n3.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePower_n3.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePower_n3.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_DP_P.NaN_Value_p;
    break;
  }

  /* End of MultiPortSwitch: '<S97>/Controller chosen' */

  /* Sum: '<S97>/Sum' */
  ctrl_DP_B.Sum_k2 = (ctrl_DP_B.Inertiacompensation_k + ctrl_DP_B.Sum1_b) +
    rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* DiscreteTransferFcn: '<S58>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S58>/Constant'
     *  Constant: '<S58>/Constant1'
     */
    ctrl_DP_DW.DiscreteTransferFcn_tmp_n = ctrl_DP_B.Sum_k2 -
      ctrl_DP_P.Constant_Value_j4[1] * ctrl_DP_DW.DiscreteTransferFcn_states_h0;
    ctrl_DP_B.DiscreteTransferFcn_b = ctrl_DP_P.Constant1_Value_oi[0] *
      ctrl_DP_DW.DiscreteTransferFcn_tmp_n + ctrl_DP_P.Constant1_Value_oi[1] *
      ctrl_DP_DW.DiscreteTransferFcn_states_h0;
  }

  /* Gain: '<S96>/Finding rotation speed' incorporates:
   *  Gain: '<S96>/K_omega'
   *  Sum: '<S96>/Sum'
   */
  ctrl_DP_B.Findingrotationspeed_ms = ((ctrl_DP_B.DiscreteTransferFcn_b -
    ctrl_DP_B.Delay_g) - ctrl_DP_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_k) * (1.0 / (6.2831853071795862 * ctrl_DP_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Gain: '<S99>/Ki' */
    ctrl_DP_B.Ki_b = ctrl_DP_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S97>/Supervisor' */
    ctrl_DP_Supervisor(ctrl_DP_B.Memory_j, 0.0, ctrl_DP_B.Delay[3],
                       &ctrl_DP_B.sf_Supervisor_n);

    /* Delay: '<S59>/Delay' */
    ctrl_DP_B.Delay_a5 = ctrl_DP_DW.Delay_DSTATE_j;

    /* Delay: '<S106>/Delay' */
    ctrl_DP_B.Delay_id = ctrl_DP_DW.Delay_DSTATE_a;
  }

  /* MATLAB Function: '<S106>/MATLAB Function' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Tf5'
   *  Constant: '<S10>/K_Tr5'
   *  Constant: '<S10>/Rho'
   */
  ctrl_DP_MATLABFunction_i(rtb_sys[10], ctrl_DP_P.K_T5f, ctrl_DP_P.K_T5r,
    ctrl_DP_P.Rho, ctrl_DP_P.D, ctrl_DP_P.eps_c, ctrl_DP_B.Delay_id,
    &ctrl_DP_B.sf_MATLABFunction_j);
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* DiscreteTransferFcn: '<S106>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S106>/Constant1'
     *  Constant: '<S106>/Constant2'
     */
    ctrl_DP_DW.DiscreteTransferFcn_tmp_c = (ctrl_DP_B.sf_MATLABFunction_j.n_d -
      ctrl_DP_P.Constant2_Value_p[1] * ctrl_DP_DW.DiscreteTransferFcn_states_hb
      [0]) - ctrl_DP_P.Constant2_Value_p[2] *
      ctrl_DP_DW.DiscreteTransferFcn_states_hb[1];
    ctrl_DP_B.DiscreteTransferFcn_o = (ctrl_DP_P.Constant1_Value_mk[0] *
      ctrl_DP_DW.DiscreteTransferFcn_tmp_c + ctrl_DP_P.Constant1_Value_mk[1] *
      ctrl_DP_DW.DiscreteTransferFcn_states_hb[0]) +
      ctrl_DP_P.Constant1_Value_mk[2] *
      ctrl_DP_DW.DiscreteTransferFcn_states_hb[1];

    /* SampleTimeMath: '<S109>/TSamp'
     *
     * About '<S109>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_DP_B.TSamp_m = ctrl_DP_B.DiscreteTransferFcn_o * ctrl_DP_P.TSamp_WtEt_o;

    /* Sum: '<S109>/Diff' incorporates:
     *  UnitDelay: '<S109>/UD'
     */
    rtb_Sum_b = ctrl_DP_B.TSamp_m - ctrl_DP_DW.UD_DSTATE_m;

    /* RateLimiter: '<S106>/Acceleration limiter' */
    rtb_psi_dot = rtb_Sum_b - ctrl_DP_DW.PrevY_j;
    if (rtb_psi_dot > ctrl_DP_P.Accelerationlimiter_RisingLim_b) {
      rtb_Sum_b = ctrl_DP_DW.PrevY_j + ctrl_DP_P.Accelerationlimiter_RisingLim_b;
    } else {
      if (rtb_psi_dot < ctrl_DP_P.Accelerationlimiter_FallingLi_d) {
        rtb_Sum_b = ctrl_DP_DW.PrevY_j +
          ctrl_DP_P.Accelerationlimiter_FallingLi_d;
      }
    }

    ctrl_DP_DW.PrevY_j = rtb_Sum_b;

    /* End of RateLimiter: '<S106>/Acceleration limiter' */

    /* Gain: '<S106>/Inertia compensation' */
    ctrl_DP_B.Inertiacompensation_f = ctrl_DP_P.I_s * 2.0 * 3.1415926535897931 *
      rtb_Sum_b;

    /* Sum: '<S106>/Sum1' incorporates:
     *  Gain: '<S106>/Qf_0'
     *  Gain: '<S106>/Qff_0(nr)'
     *  Gain: '<S106>/Qff_1(nr)'
     *  Trigonometry: '<S106>/Trigonometric Function'
     */
    ctrl_DP_B.Sum1_o = tanh(ctrl_DP_P.epsilon / ctrl_DP_P.n_max *
      ctrl_DP_B.DiscreteTransferFcn_o) * ctrl_DP_P.Q_f0 + ctrl_DP_P.K_omega *
      2.0 * 3.1415926535897931 * ctrl_DP_B.DiscreteTransferFcn_o;

    /* Memory: '<S106>/Memory' */
    ctrl_DP_B.Memory_d = ctrl_DP_DW.Memory_PreviousInput_b;

    /* Sum: '<S108>/Sum' */
    rtb_Sum_b = ctrl_DP_B.DiscreteTransferFcn_o - ctrl_DP_B.Delay[4];

    /* Gain: '<S108>/Kp' */
    ctrl_DP_B.Kp_j = ctrl_DP_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S108>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_DP_PrevZCX.Integrator_Reset_ZCE_f,
                       (ctrl_DP_B.reset_f));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_n4 = ctrl_DP_P.Integrator_IC_aj;
    }
  }

  /* MATLAB Function: '<S108>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Qr11'
   *  Constant: '<S10>/K_Qr5'
   *  Constant: '<S10>/K_Tf5'
   *  Constant: '<S10>/K_Tr5'
   *  Constant: '<S10>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_DP_P.k_cc, ctrl_DP_P.p_cc, ctrl_DP_P.r_cc,
    ctrl_DP_B.Delay[4], ctrl_DP_P.K_T5f, ctrl_DP_P.K_q5f, ctrl_DP_P.D,
    ctrl_DP_B.sf_MATLABFunction_j.T_r, ctrl_DP_P.Rho, ctrl_DP_P.eps_c,
    ctrl_DP_P.K_T5r, ctrl_DP_P.K_q5r, &ctrl_DP_B.sf_CorecontrollerTorquePowera_h);

  /* MultiPortSwitch: '<S106>/Controller chosen' incorporates:
   *  Constant: '<S106>/NaN'
   *  Integrator: '<S108>/Integrator'
   *  Sum: '<S108>/Sum1'
   */
  switch ((int32_T)ctrl_DP_B.Memory_d) {
   case 1:
    rtb_Row2 = ctrl_DP_B.Kp_j + ctrl_DP_X.Integrator_CSTATE_n4;
    break;

   case 2:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePowera_h.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePowera_h.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePowera_h.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_DP_P.NaN_Value_lq;
    break;
  }

  /* End of MultiPortSwitch: '<S106>/Controller chosen' */

  /* Sum: '<S106>/Sum' */
  ctrl_DP_B.Sum_i = (ctrl_DP_B.Inertiacompensation_f + ctrl_DP_B.Sum1_o) +
    rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* DiscreteTransferFcn: '<S59>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S59>/Constant'
     *  Constant: '<S59>/Constant1'
     */
    ctrl_DP_DW.DiscreteTransferFcn_tmp_f = ctrl_DP_B.Sum_i -
      ctrl_DP_P.Constant_Value_i[1] * ctrl_DP_DW.DiscreteTransferFcn_states_dt;
    ctrl_DP_B.DiscreteTransferFcn_lz = ctrl_DP_P.Constant1_Value_h[0] *
      ctrl_DP_DW.DiscreteTransferFcn_tmp_f + ctrl_DP_P.Constant1_Value_h[1] *
      ctrl_DP_DW.DiscreteTransferFcn_states_dt;
  }

  /* Gain: '<S105>/Finding rotation speed' incorporates:
   *  Gain: '<S105>/K_omega'
   *  Sum: '<S105>/Sum'
   */
  ctrl_DP_B.Findingrotationspeed_ag = ((ctrl_DP_B.DiscreteTransferFcn_lz -
    ctrl_DP_B.Delay_a5) - ctrl_DP_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_c) * (1.0 / (6.2831853071795862 * ctrl_DP_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Gain: '<S108>/Ki' */
    ctrl_DP_B.Ki_a = ctrl_DP_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S106>/Supervisor' */
    ctrl_DP_Supervisor(ctrl_DP_B.Memory_d, 0.0, ctrl_DP_B.Delay[4],
                       &ctrl_DP_B.sf_Supervisor_b);

    /* Delay: '<S60>/Delay' */
    ctrl_DP_B.Delay_h = ctrl_DP_DW.Delay_DSTATE_dv;

    /* Delay: '<S115>/Delay' */
    ctrl_DP_B.Delay_il = ctrl_DP_DW.Delay_DSTATE_m;
  }

  /* MATLAB Function: '<S115>/MATLAB Function' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Tf6'
   *  Constant: '<S10>/K_Tr6'
   *  Constant: '<S10>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 6/Thruster control/MATLAB Function': '<S119>:1' */
  /* '<S119>:1:5' */
  if (rtb_sys[11] < 0.0) {
    absx31 = -1.0;
  } else if (rtb_sys[11] > 0.0) {
    absx31 = 1.0;
  } else if (rtb_sys[11] == 0.0) {
    absx31 = 0.0;
  } else {
    absx31 = rtb_sys[11];
  }

  rtb_Row2 = sqrt(fabs(rtb_sys[11]) / (ctrl_DP_P.Rho * rt_powd_snf(ctrl_DP_P.D,
    4.0) * ctrl_DP_P.K_T6f)) * absx31;

  /* '<S119>:1:7' */
  rtb_psi_dot = tanh(ctrl_DP_P.eps_c * rtb_Row2 / 27.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S119>:1:8' */
  /* '<S119>:1:10' */
  if (ctrl_DP_B.Delay_il < 0.0) {
    absx31 = -1.0;
  } else if (ctrl_DP_B.Delay_il > 0.0) {
    absx31 = 1.0;
  } else if (ctrl_DP_B.Delay_il == 0.0) {
    absx31 = 0.0;
  } else {
    absx31 = ctrl_DP_B.Delay_il;
  }

  rtb_T_r = ((1.0 - rtb_psi_dot) * ctrl_DP_P.K_T6r + ctrl_DP_P.K_T6f *
             rtb_psi_dot) * absx31 * ctrl_DP_P.Rho * rt_powd_snf(ctrl_DP_P.D,
    4.0) * (ctrl_DP_B.Delay_il * ctrl_DP_B.Delay_il);
  ctrl_DP_B.n_d = rtb_Row2;

  /* End of MATLAB Function: '<S115>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* DiscreteTransferFcn: '<S115>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S115>/Constant1'
     *  Constant: '<S115>/Constant2'
     */
    ctrl_DP_DW.DiscreteTransferFcn_tmp_h4 = (ctrl_DP_B.n_d -
      ctrl_DP_P.Constant2_Value_p3[1] * ctrl_DP_DW.DiscreteTransferFcn_states_l
      [0]) - ctrl_DP_P.Constant2_Value_p3[2] *
      ctrl_DP_DW.DiscreteTransferFcn_states_l[1];
    ctrl_DP_B.DiscreteTransferFcn_j = (ctrl_DP_P.Constant1_Value_oa[0] *
      ctrl_DP_DW.DiscreteTransferFcn_tmp_h4 + ctrl_DP_P.Constant1_Value_oa[1] *
      ctrl_DP_DW.DiscreteTransferFcn_states_l[0]) +
      ctrl_DP_P.Constant1_Value_oa[2] * ctrl_DP_DW.DiscreteTransferFcn_states_l
      [1];

    /* SampleTimeMath: '<S118>/TSamp'
     *
     * About '<S118>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_DP_B.TSamp_o = ctrl_DP_B.DiscreteTransferFcn_j *
      ctrl_DP_P.TSamp_WtEt_kk;

    /* Sum: '<S118>/Diff' incorporates:
     *  UnitDelay: '<S118>/UD'
     */
    rtb_Sum_b = ctrl_DP_B.TSamp_o - ctrl_DP_DW.UD_DSTATE_l;

    /* RateLimiter: '<S115>/Acceleration limiter' */
    rtb_psi_dot = rtb_Sum_b - ctrl_DP_DW.PrevY_h;
    if (rtb_psi_dot > ctrl_DP_P.Accelerationlimiter_RisingLi_bi) {
      rtb_Sum_b = ctrl_DP_DW.PrevY_h + ctrl_DP_P.Accelerationlimiter_RisingLi_bi;
    } else {
      if (rtb_psi_dot < ctrl_DP_P.Accelerationlimiter_FallingLi_p) {
        rtb_Sum_b = ctrl_DP_DW.PrevY_h +
          ctrl_DP_P.Accelerationlimiter_FallingLi_p;
      }
    }

    ctrl_DP_DW.PrevY_h = rtb_Sum_b;

    /* End of RateLimiter: '<S115>/Acceleration limiter' */

    /* Gain: '<S115>/Inertia compensation' */
    ctrl_DP_B.Inertiacompensation_e3 = ctrl_DP_P.I_s * 2.0 * 3.1415926535897931 *
      rtb_Sum_b;

    /* Sum: '<S115>/Sum1' incorporates:
     *  Gain: '<S115>/Qf_0'
     *  Gain: '<S115>/Qff_0(nr)'
     *  Gain: '<S115>/Qff_1(nr)'
     *  Trigonometry: '<S115>/Trigonometric Function'
     */
    ctrl_DP_B.Sum1_io = tanh(ctrl_DP_P.epsilon / ctrl_DP_P.n_max *
      ctrl_DP_B.DiscreteTransferFcn_j) * ctrl_DP_P.Q_f0 + ctrl_DP_P.K_omega *
      2.0 * 3.1415926535897931 * ctrl_DP_B.DiscreteTransferFcn_j;

    /* Memory: '<S115>/Memory' */
    ctrl_DP_B.Memory_o = ctrl_DP_DW.Memory_PreviousInput_a4;

    /* Sum: '<S117>/Sum' */
    rtb_Sum_b = ctrl_DP_B.DiscreteTransferFcn_j - ctrl_DP_B.Delay[5];

    /* Gain: '<S117>/Kp' */
    ctrl_DP_B.Kp_l = ctrl_DP_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S117>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_PrevZCX.Integrator_Reset_ZCE_i3,
                       (ctrl_DP_B.reset_om));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      ctrl_DP_X.Integrator_CSTATE_gj = ctrl_DP_P.Integrator_IC_h;
    }
  }

  /* MATLAB Function: '<S117>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Constant: '<S10>/Constant3'
   *  Constant: '<S10>/D'
   *  Constant: '<S10>/K_Qr12'
   *  Constant: '<S10>/K_Qr6'
   *  Constant: '<S10>/K_Tf6'
   *  Constant: '<S10>/K_Tr6'
   *  Constant: '<S10>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_DP_P.k_cc, ctrl_DP_P.p_cc, ctrl_DP_P.r_cc,
    ctrl_DP_B.Delay[5], ctrl_DP_P.K_T6f, ctrl_DP_P.K_q6f, ctrl_DP_P.D, rtb_T_r,
    ctrl_DP_P.Rho, ctrl_DP_P.eps_c, ctrl_DP_P.K_T6r, ctrl_DP_P.K_q6r,
    &ctrl_DP_B.sf_CorecontrollerTorquePower_nf);

  /* MultiPortSwitch: '<S115>/Controller chosen' incorporates:
   *  Constant: '<S115>/NaN'
   *  Integrator: '<S117>/Integrator'
   *  Sum: '<S117>/Sum1'
   */
  switch ((int32_T)ctrl_DP_B.Memory_o) {
   case 1:
    rtb_Row2 = ctrl_DP_B.Kp_l + ctrl_DP_X.Integrator_CSTATE_gj;
    break;

   case 2:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePower_nf.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePower_nf.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_DP_B.sf_CorecontrollerTorquePower_nf.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_DP_P.NaN_Value_j;
    break;
  }

  /* End of MultiPortSwitch: '<S115>/Controller chosen' */

  /* Sum: '<S115>/Sum' */
  ctrl_DP_B.Sum_f = (ctrl_DP_B.Inertiacompensation_e3 + ctrl_DP_B.Sum1_io) +
    rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* DiscreteTransferFcn: '<S60>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S60>/Constant'
     *  Constant: '<S60>/Constant1'
     */
    ctrl_DP_DW.DiscreteTransferFcn_tmp_cw = ctrl_DP_B.Sum_f -
      ctrl_DP_P.Constant_Value_ht[1] * ctrl_DP_DW.DiscreteTransferFcn_states_o;
    ctrl_DP_B.DiscreteTransferFcn_ea = ctrl_DP_P.Constant1_Value_gs[0] *
      ctrl_DP_DW.DiscreteTransferFcn_tmp_cw + ctrl_DP_P.Constant1_Value_gs[1] *
      ctrl_DP_DW.DiscreteTransferFcn_states_o;
  }

  /* Gain: '<S114>/Finding rotation speed' incorporates:
   *  Gain: '<S114>/K_omega'
   *  Sum: '<S114>/Sum'
   */
  ctrl_DP_B.Findingrotationspeed_c = ((ctrl_DP_B.DiscreteTransferFcn_ea -
    ctrl_DP_B.Delay_h) - ctrl_DP_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_m) * (1.0 / (6.2831853071795862 * ctrl_DP_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Gain: '<S117>/Ki' */
    ctrl_DP_B.Ki_p = ctrl_DP_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S115>/Supervisor' */
    ctrl_DP_Supervisor(ctrl_DP_B.Memory_o, 0.0, ctrl_DP_B.Delay[5],
                       &ctrl_DP_B.sf_Supervisor_e);

    /* SignalConversion: '<S11>/TmpSignal ConversionAtDelayInport1' */
    ctrl_DP_B.TmpSignalConversionAtDelayInpor[0] = ctrl_DP_B.output[1];
    ctrl_DP_B.TmpSignalConversionAtDelayInpor[1] = ctrl_DP_B.output[3];
    ctrl_DP_B.TmpSignalConversionAtDelayInpor[2] = ctrl_DP_B.output[5];
    ctrl_DP_B.TmpSignalConversionAtDelayInpor[3] = ctrl_DP_B.output[7];
    ctrl_DP_B.TmpSignalConversionAtDelayInpor[4] = ctrl_DP_B.output[9];
    ctrl_DP_B.TmpSignalConversionAtDelayInpor[5] = ctrl_DP_B.output[11];
  }
}

/* Model update function */
void ctrl_DP_update(void)
{
  /* local block i/o variables */
  real_T rtb_ImpSel_InsertedFor_reset_at;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T i;

  /* Update for Integrator: '<S18>/Integrator1' */
  ctrl_DP_DW.Integrator1_IWORK = 0;

  /* Update for Iterator SubSystem: '<S9>/Optimal angle path and  constraints on rotation speed' */
  for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
    /* Update for ForEachSliceSelector: '<S47>/ImpSel_InsertedFor_reset_at_outport_0' */
    rtb_ImpSel_InsertedFor_reset_at = ctrl_DP_B.reset_g[ForEach_itr];
    if (rtmIsMajorTimeStep(ctrl_DP_M)) {
      /* Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
      ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI = 0U;
      ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE +=
        ctrl_DP_P.CoreSubsys.DiscreteTimeIntegrator_gainval *
        ctrl_DP_B.CoreSubsys[ForEach_itr].MaxRotationRate;
      if (rtb_ImpSel_InsertedFor_reset_at > 0.0) {
        ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 1;
      } else if (rtb_ImpSel_InsertedFor_reset_at < 0.0) {
        ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = -1;
      } else if (rtb_ImpSel_InsertedFor_reset_at == 0.0) {
        ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 0;
      } else {
        ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 2;
      }

      /* End of Update for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */

      /* Update for Delay: '<S47>/Delay' */
      ctrl_DP_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_DP_B.CoreSubsys[ForEach_itr].angle;
    }
  }

  /* End of Update for SubSystem: '<S9>/Optimal angle path and  constraints on rotation speed' */

  /* Update for Integrator: '<S5>/Integrator' */
  ctrl_DP_DW.Integrator_IWORK = 0;
  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    /* Update for Delay: '<S11>/Delay' */
    for (i = 0; i < 6; i++) {
      ctrl_DP_DW.Delay_DSTATE[i] = ctrl_DP_B.TmpSignalConversionAtDelayInpor[i];
    }

    /* End of Update for Delay: '<S11>/Delay' */

    /* Update for Delay: '<S55>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_f = ctrl_DP_B.Qa;

    /* Update for Delay: '<S70>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_fu = ctrl_DP_B.DiscreteTransferFcn;

    /* Update for DiscreteTransferFcn: '<S70>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states[1] =
      ctrl_DP_DW.DiscreteTransferFcn_states[0];
    ctrl_DP_DW.DiscreteTransferFcn_states[0] =
      ctrl_DP_DW.DiscreteTransferFcn_tmp;

    /* Update for UnitDelay: '<S73>/UD' */
    ctrl_DP_DW.UD_DSTATE = ctrl_DP_B.TSamp;

    /* Update for Memory: '<S70>/Memory' */
    ctrl_DP_DW.Memory_PreviousInput = ctrl_DP_B.sf_Supervisor.u;

    /* Update for DiscreteTransferFcn: '<S55>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_d =
      ctrl_DP_DW.DiscreteTransferFcn_tmp_a;

    /* Update for Delay: '<S56>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_b = ctrl_DP_B.sf_ActualForceandTorque_f.Qa;

    /* Update for Delay: '<S79>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_d = ctrl_DP_B.DiscreteTransferFcn_e;

    /* Update for DiscreteTransferFcn: '<S79>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_h[1] =
      ctrl_DP_DW.DiscreteTransferFcn_states_h[0];
    ctrl_DP_DW.DiscreteTransferFcn_states_h[0] =
      ctrl_DP_DW.DiscreteTransferFcn_tmp_d;

    /* Update for UnitDelay: '<S82>/UD' */
    ctrl_DP_DW.UD_DSTATE_n = ctrl_DP_B.TSamp_n;

    /* Update for Memory: '<S79>/Memory' */
    ctrl_DP_DW.Memory_PreviousInput_n = ctrl_DP_B.sf_Supervisor_h.u;

    /* Update for DiscreteTransferFcn: '<S56>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_m =
      ctrl_DP_DW.DiscreteTransferFcn_tmp_h;

    /* Update for Delay: '<S57>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_n = ctrl_DP_B.sf_ActualForceandTorque_h.Qa;

    /* Update for Delay: '<S88>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_no = ctrl_DP_B.DiscreteTransferFcn_f;

    /* Update for DiscreteTransferFcn: '<S88>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_j[1] =
      ctrl_DP_DW.DiscreteTransferFcn_states_j[0];
    ctrl_DP_DW.DiscreteTransferFcn_states_j[0] =
      ctrl_DP_DW.DiscreteTransferFcn_tmp_e;

    /* Update for UnitDelay: '<S91>/UD' */
    ctrl_DP_DW.UD_DSTATE_i = ctrl_DP_B.TSamp_k;

    /* Update for Memory: '<S88>/Memory' */
    ctrl_DP_DW.Memory_PreviousInput_d = ctrl_DP_B.sf_Supervisor_l.u;

    /* Update for DiscreteTransferFcn: '<S57>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_k =
      ctrl_DP_DW.DiscreteTransferFcn_tmp_hh;

    /* Update for Delay: '<S58>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_e = ctrl_DP_B.sf_ActualForceandTorque_m.Qa;

    /* Update for Delay: '<S97>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_i = ctrl_DP_B.DiscreteTransferFcn_l;

    /* Update for DiscreteTransferFcn: '<S97>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_i[1] =
      ctrl_DP_DW.DiscreteTransferFcn_states_i[0];
    ctrl_DP_DW.DiscreteTransferFcn_states_i[0] =
      ctrl_DP_DW.DiscreteTransferFcn_tmp_k;

    /* Update for UnitDelay: '<S100>/UD' */
    ctrl_DP_DW.UD_DSTATE_n4 = ctrl_DP_B.TSamp_a;

    /* Update for Memory: '<S97>/Memory' */
    ctrl_DP_DW.Memory_PreviousInput_a = ctrl_DP_B.sf_Supervisor_n.u;

    /* Update for DiscreteTransferFcn: '<S58>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_h0 =
      ctrl_DP_DW.DiscreteTransferFcn_tmp_n;

    /* Update for Delay: '<S59>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_j = ctrl_DP_B.sf_ActualForceandTorque_o.Qa;

    /* Update for Delay: '<S106>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_a = ctrl_DP_B.DiscreteTransferFcn_o;

    /* Update for DiscreteTransferFcn: '<S106>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_hb[1] =
      ctrl_DP_DW.DiscreteTransferFcn_states_hb[0];
    ctrl_DP_DW.DiscreteTransferFcn_states_hb[0] =
      ctrl_DP_DW.DiscreteTransferFcn_tmp_c;

    /* Update for UnitDelay: '<S109>/UD' */
    ctrl_DP_DW.UD_DSTATE_m = ctrl_DP_B.TSamp_m;

    /* Update for Memory: '<S106>/Memory' */
    ctrl_DP_DW.Memory_PreviousInput_b = ctrl_DP_B.sf_Supervisor_b.u;

    /* Update for DiscreteTransferFcn: '<S59>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_dt =
      ctrl_DP_DW.DiscreteTransferFcn_tmp_f;

    /* Update for Delay: '<S60>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_dv = ctrl_DP_B.sf_ActualForceandTorque_j.Qa;

    /* Update for Delay: '<S115>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_m = ctrl_DP_B.DiscreteTransferFcn_j;

    /* Update for DiscreteTransferFcn: '<S115>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_l[1] =
      ctrl_DP_DW.DiscreteTransferFcn_states_l[0];
    ctrl_DP_DW.DiscreteTransferFcn_states_l[0] =
      ctrl_DP_DW.DiscreteTransferFcn_tmp_h4;

    /* Update for UnitDelay: '<S118>/UD' */
    ctrl_DP_DW.UD_DSTATE_l = ctrl_DP_B.TSamp_o;

    /* Update for Memory: '<S115>/Memory' */
    ctrl_DP_DW.Memory_PreviousInput_a4 = ctrl_DP_B.sf_Supervisor_e.u;

    /* Update for DiscreteTransferFcn: '<S60>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_o =
      ctrl_DP_DW.DiscreteTransferFcn_tmp_cw;
  }

  if (rtmIsMajorTimeStep(ctrl_DP_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_DP_M->solverInfo);
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
  if (!(++ctrl_DP_M->Timing.clockTick0)) {
    ++ctrl_DP_M->Timing.clockTickH0;
  }

  ctrl_DP_M->Timing.t[0] = rtsiGetSolverStopTime(&ctrl_DP_M->solverInfo);

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
    if (!(++ctrl_DP_M->Timing.clockTick1)) {
      ++ctrl_DP_M->Timing.clockTickH1;
    }

    ctrl_DP_M->Timing.t[1] = ctrl_DP_M->Timing.clockTick1 *
      ctrl_DP_M->Timing.stepSize1 + ctrl_DP_M->Timing.clockTickH1 *
      ctrl_DP_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_DP_derivatives(void)
{
  XDot_ctrl_DP_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_DP_T *) ctrl_DP_M->derivs);

  /* Derivatives for Integrator: '<S69>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = ctrl_DP_B.Findingrotationspeed;

  /* Derivatives for Integrator: '<S78>/Integrator' */
  _rtXdot->Integrator_CSTATE_p = ctrl_DP_B.Findingrotationspeed_a;

  /* Derivatives for Integrator: '<S87>/Integrator' */
  _rtXdot->Integrator_CSTATE_k = ctrl_DP_B.Findingrotationspeed_m;

  /* Derivatives for Integrator: '<S96>/Integrator' */
  _rtXdot->Integrator_CSTATE_n = ctrl_DP_B.Findingrotationspeed_ms;

  /* Derivatives for Integrator: '<S105>/Integrator' */
  _rtXdot->Integrator_CSTATE_cd = ctrl_DP_B.Findingrotationspeed_ag;

  /* Derivatives for Integrator: '<S114>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = ctrl_DP_B.Findingrotationspeed_c;

  /* Derivatives for Integrator: '<S18>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ctrl_DP_B.Integrator3[0];

  /* Derivatives for Integrator: '<S13>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_DP_B.TmpSignalConversionAtMatrixMult[0];

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_g[0] = ctrl_DP_B.M1[0];

  /* Derivatives for Integrator: '<S18>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[0] = ctrl_DP_B.Sum5[0];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_a[0] = ctrl_DP_B.Sum1[0];

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_DP_B.MatrixMultiply1[0];

  /* Derivatives for Integrator: '<S18>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_c[0] = ctrl_DP_B.MatrixMultiply[0];

  /* Derivatives for Integrator: '<S18>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = ctrl_DP_B.Integrator3[1];

  /* Derivatives for Integrator: '<S13>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = ctrl_DP_B.TmpSignalConversionAtMatrixMult[1];

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_g[1] = ctrl_DP_B.M1[1];

  /* Derivatives for Integrator: '<S18>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[1] = ctrl_DP_B.Sum5[1];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_a[1] = ctrl_DP_B.Sum1[1];

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[1] = ctrl_DP_B.MatrixMultiply1[1];

  /* Derivatives for Integrator: '<S18>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_c[1] = ctrl_DP_B.MatrixMultiply[1];

  /* Derivatives for Integrator: '<S18>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[2] = ctrl_DP_B.Integrator3[2];

  /* Derivatives for Integrator: '<S13>/Integrator' */
  _rtXdot->Integrator_CSTATE[2] = ctrl_DP_B.TmpSignalConversionAtMatrixMult[2];

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_g[2] = ctrl_DP_B.M1[2];

  /* Derivatives for Integrator: '<S18>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[2] = ctrl_DP_B.Sum5[2];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_a[2] = ctrl_DP_B.Sum1[2];

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[2] = ctrl_DP_B.MatrixMultiply1[2];

  /* Derivatives for Integrator: '<S18>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_c[2] = ctrl_DP_B.MatrixMultiply[2];

  /* Derivatives for Integrator: '<S72>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = ctrl_DP_B.Ki;

  /* Derivatives for Integrator: '<S81>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = ctrl_DP_B.Ki_o;

  /* Derivatives for Integrator: '<S90>/Integrator' */
  _rtXdot->Integrator_CSTATE_i = ctrl_DP_B.Ki_n;

  /* Derivatives for Integrator: '<S99>/Integrator' */
  _rtXdot->Integrator_CSTATE_l = ctrl_DP_B.Ki_b;

  /* Derivatives for Integrator: '<S108>/Integrator' */
  _rtXdot->Integrator_CSTATE_n4 = ctrl_DP_B.Ki_a;

  /* Derivatives for Integrator: '<S117>/Integrator' */
  _rtXdot->Integrator_CSTATE_gj = ctrl_DP_B.Ki_p;
}

/* Model initialize function */
void ctrl_DP_initialize(void)
{
  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;

    /* Start for Iterator SubSystem: '<S9>/Optimal angle path and  constraints on rotation speed' */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      ctrl_DP_B.CoreSubsys[ForEach_itr].angle = 0.0;
      ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE = 0.0;
      ctrl_DP_B.CoreSubsys[ForEach_itr].Delay = 0.0;
      ctrl_DP_DW.CoreSubsys[ForEach_itr].Delay_DSTATE = 0.0;
      ctrl_DP_B.CoreSubsys[ForEach_itr].MaxRotationRate = 0.0;
    }

    /* End of Start for SubSystem: '<S9>/Optimal angle path and  constraints on rotation speed' */
  }

  ctrl_DP_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator1_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator3_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_o = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_nt = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator2_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_o3 = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_db = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_f = UNINITIALIZED_ZCSIG;
  ctrl_DP_PrevZCX.Integrator_Reset_ZCE_i3 = UNINITIALIZED_ZCSIG;

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    int32_T i;

    /* InitializeConditions for Integrator: '<S18>/Integrator1' incorporates:
     *  InitializeConditions for Integrator: '<S5>/Integrator'
     */
    if (rtmIsFirstInitCond(ctrl_DP_M)) {
      ctrl_DP_X.Integrator1_CSTATE[0] = 0.0;
      ctrl_DP_X.Integrator1_CSTATE[1] = 0.0;
      ctrl_DP_X.Integrator1_CSTATE[2] = 0.0;
      ctrl_DP_X.Integrator_CSTATE_a[0] = 0.0;
      ctrl_DP_X.Integrator_CSTATE_a[1] = 0.0;
      ctrl_DP_X.Integrator_CSTATE_a[2] = 0.0;
    }

    ctrl_DP_DW.Integrator1_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S18>/Integrator1' */

    /* InitializeConditions for Integrator: '<S13>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE[0] = ctrl_DP_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S5>/Integrator1' */
    ctrl_DP_X.Integrator1_CSTATE_g[0] = ctrl_DP_P.Integrator1_IC[0];

    /* InitializeConditions for Integrator: '<S18>/Integrator3' */
    ctrl_DP_X.Integrator3_CSTATE[0] = ctrl_DP_P.Integrator3_IC;

    /* InitializeConditions for Integrator: '<S13>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE[1] = ctrl_DP_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S5>/Integrator1' */
    ctrl_DP_X.Integrator1_CSTATE_g[1] = ctrl_DP_P.Integrator1_IC[1];

    /* InitializeConditions for Integrator: '<S18>/Integrator3' */
    ctrl_DP_X.Integrator3_CSTATE[1] = ctrl_DP_P.Integrator3_IC;

    /* InitializeConditions for Integrator: '<S13>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE[2] = ctrl_DP_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S5>/Integrator1' */
    ctrl_DP_X.Integrator1_CSTATE_g[2] = ctrl_DP_P.Integrator1_IC[2];

    /* InitializeConditions for Integrator: '<S18>/Integrator3' */
    ctrl_DP_X.Integrator3_CSTATE[2] = ctrl_DP_P.Integrator3_IC;

    /* InitializeConditions for Integrator: '<S69>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_c = ctrl_DP_P.Integrator_IC_f;

    /* InitializeConditions for Integrator: '<S78>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_p = ctrl_DP_P.Integrator_IC_fg;

    /* InitializeConditions for Integrator: '<S87>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_k = ctrl_DP_P.Integrator_IC_p;

    /* InitializeConditions for Integrator: '<S96>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_n = ctrl_DP_P.Integrator_IC_fv;

    /* InitializeConditions for Integrator: '<S105>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_cd = ctrl_DP_P.Integrator_IC_l;

    /* InitializeConditions for Integrator: '<S114>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_h = ctrl_DP_P.Integrator_IC_li;

    /* InitializeConditions for Integrator: '<S5>/Integrator' */
    ctrl_DP_DW.Integrator_IWORK = 1;

    /* InitializeConditions for Integrator: '<S5>/Integrator2' */
    ctrl_DP_X.Integrator2_CSTATE[0] = ctrl_DP_P.Integrator2_IC[0];

    /* InitializeConditions for Integrator: '<S18>/Integrator2' */
    ctrl_DP_X.Integrator2_CSTATE_c[0] = ctrl_DP_P.Integrator2_IC_p;

    /* InitializeConditions for Integrator: '<S5>/Integrator2' */
    ctrl_DP_X.Integrator2_CSTATE[1] = ctrl_DP_P.Integrator2_IC[1];

    /* InitializeConditions for Integrator: '<S18>/Integrator2' */
    ctrl_DP_X.Integrator2_CSTATE_c[1] = ctrl_DP_P.Integrator2_IC_p;

    /* InitializeConditions for Integrator: '<S5>/Integrator2' */
    ctrl_DP_X.Integrator2_CSTATE[2] = ctrl_DP_P.Integrator2_IC[2];

    /* InitializeConditions for Integrator: '<S18>/Integrator2' */
    ctrl_DP_X.Integrator2_CSTATE_c[2] = ctrl_DP_P.Integrator2_IC_p;

    /* InitializeConditions for Delay: '<S11>/Delay' */
    for (i = 0; i < 6; i++) {
      ctrl_DP_DW.Delay_DSTATE[i] = ctrl_DP_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S11>/Delay' */

    /* InitializeConditions for Delay: '<S55>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_f = ctrl_DP_P.Delay_InitialCondition_i;

    /* InitializeConditions for Delay: '<S70>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_fu = ctrl_DP_P.Delay_InitialCondition_f;

    /* InitializeConditions for UnitDelay: '<S73>/UD' */
    ctrl_DP_DW.UD_DSTATE = ctrl_DP_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for RateLimiter: '<S70>/Acceleration Limit' */
    ctrl_DP_DW.PrevY = ctrl_DP_P.AccelerationLimit_IC;

    /* InitializeConditions for Memory: '<S70>/Memory' */
    ctrl_DP_DW.Memory_PreviousInput = ctrl_DP_P.Memory_X0;

    /* InitializeConditions for Integrator: '<S72>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_e = ctrl_DP_P.Integrator_IC_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S55>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_d =
      ctrl_DP_P.DiscreteTransferFcn_InitialSt_h;

    /* InitializeConditions for Delay: '<S56>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_b = ctrl_DP_P.Delay_InitialCondition_l;

    /* InitializeConditions for Delay: '<S79>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_d = ctrl_DP_P.Delay_InitialCondition_iv;

    /* InitializeConditions for UnitDelay: '<S82>/UD' */
    ctrl_DP_DW.UD_DSTATE_n = ctrl_DP_P.DiscreteDerivative_ICPrevScal_p;

    /* InitializeConditions for RateLimiter: '<S79>/Acceleration Limit' */
    ctrl_DP_DW.PrevY_e = ctrl_DP_P.AccelerationLimit_IC_m;

    /* InitializeConditions for Memory: '<S79>/Memory' */
    ctrl_DP_DW.Memory_PreviousInput_n = ctrl_DP_P.Memory_X0_e;

    /* InitializeConditions for Integrator: '<S81>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_g = ctrl_DP_P.Integrator_IC_fy;

    /* InitializeConditions for DiscreteTransferFcn: '<S56>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_m =
      ctrl_DP_P.DiscreteTransferFcn_InitialSt_f;

    /* InitializeConditions for Delay: '<S57>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_n = ctrl_DP_P.Delay_InitialCondition_d;

    /* InitializeConditions for Delay: '<S88>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_no = ctrl_DP_P.Delay_InitialCondition_h;

    /* InitializeConditions for UnitDelay: '<S91>/UD' */
    ctrl_DP_DW.UD_DSTATE_i = ctrl_DP_P.DiscreteDerivative_ICPrevSca_pl;

    /* InitializeConditions for RateLimiter: '<S88>/Acceleration limiter' */
    ctrl_DP_DW.PrevY_o = ctrl_DP_P.Accelerationlimiter_IC;

    /* InitializeConditions for Memory: '<S88>/Memory' */
    ctrl_DP_DW.Memory_PreviousInput_d = ctrl_DP_P.Memory_X0_g;

    /* InitializeConditions for Integrator: '<S90>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_i = ctrl_DP_P.Integrator_IC_j;

    /* InitializeConditions for DiscreteTransferFcn: '<S57>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_k =
      ctrl_DP_P.DiscreteTransferFcn_InitialSt_c;

    /* InitializeConditions for Delay: '<S58>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_e = ctrl_DP_P.Delay_InitialCondition_fb;

    /* InitializeConditions for Delay: '<S97>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_i = ctrl_DP_P.Delay_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S100>/UD' */
    ctrl_DP_DW.UD_DSTATE_n4 = ctrl_DP_P.DiscreteDerivative_ICPrevScal_f;

    /* InitializeConditions for RateLimiter: '<S97>/Acceleration limiter' */
    ctrl_DP_DW.PrevY_c = ctrl_DP_P.Accelerationlimiter_IC_h;

    /* InitializeConditions for Memory: '<S97>/Memory' */
    ctrl_DP_DW.Memory_PreviousInput_a = ctrl_DP_P.Memory_X0_k;

    /* InitializeConditions for Integrator: '<S99>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_l = ctrl_DP_P.Integrator_IC_g;

    /* InitializeConditions for DiscreteTransferFcn: '<S58>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_h0 =
      ctrl_DP_P.DiscreteTransferFcn_InitialSt_p;

    /* InitializeConditions for Delay: '<S59>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_j = ctrl_DP_P.Delay_InitialCondition_fv;

    /* InitializeConditions for Delay: '<S106>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_a = ctrl_DP_P.Delay_InitialCondition_dz;

    /* InitializeConditions for UnitDelay: '<S109>/UD' */
    ctrl_DP_DW.UD_DSTATE_m = ctrl_DP_P.DiscreteDerivative_ICPrevScal_o;

    /* InitializeConditions for RateLimiter: '<S106>/Acceleration limiter' */
    ctrl_DP_DW.PrevY_j = ctrl_DP_P.Accelerationlimiter_IC_i;

    /* InitializeConditions for Memory: '<S106>/Memory' */
    ctrl_DP_DW.Memory_PreviousInput_b = ctrl_DP_P.Memory_X0_k3;

    /* InitializeConditions for Integrator: '<S108>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_n4 = ctrl_DP_P.Integrator_IC_aj;

    /* InitializeConditions for DiscreteTransferFcn: '<S59>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_dt =
      ctrl_DP_P.DiscreteTransferFcn_InitialS_pj;

    /* InitializeConditions for Delay: '<S60>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_dv = ctrl_DP_P.Delay_InitialCondition_fi;

    /* InitializeConditions for Delay: '<S115>/Delay' */
    ctrl_DP_DW.Delay_DSTATE_m = ctrl_DP_P.Delay_InitialCondition_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S70>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states[0] =
      ctrl_DP_P.DiscreteTransferFcn_InitialStat;

    /* InitializeConditions for DiscreteTransferFcn: '<S79>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_h[0] =
      ctrl_DP_P.DiscreteTransferFcn_InitialS_hu;

    /* InitializeConditions for DiscreteTransferFcn: '<S88>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_j[0] =
      ctrl_DP_P.DiscreteTransferFcn_InitialSt_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S97>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_i[0] =
      ctrl_DP_P.DiscreteTransferFcn_InitialS_a1;

    /* InitializeConditions for DiscreteTransferFcn: '<S106>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_hb[0] =
      ctrl_DP_P.DiscreteTransferFcn_InitialSt_e;

    /* InitializeConditions for DiscreteTransferFcn: '<S115>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_l[0] =
      ctrl_DP_P.DiscreteTransferFcn_InitialS_a4;

    /* InitializeConditions for DiscreteTransferFcn: '<S70>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states[1] =
      ctrl_DP_P.DiscreteTransferFcn_InitialStat;

    /* InitializeConditions for DiscreteTransferFcn: '<S79>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_h[1] =
      ctrl_DP_P.DiscreteTransferFcn_InitialS_hu;

    /* InitializeConditions for DiscreteTransferFcn: '<S88>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_j[1] =
      ctrl_DP_P.DiscreteTransferFcn_InitialSt_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S97>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_i[1] =
      ctrl_DP_P.DiscreteTransferFcn_InitialS_a1;

    /* InitializeConditions for DiscreteTransferFcn: '<S106>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_hb[1] =
      ctrl_DP_P.DiscreteTransferFcn_InitialSt_e;

    /* InitializeConditions for DiscreteTransferFcn: '<S115>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_l[1] =
      ctrl_DP_P.DiscreteTransferFcn_InitialS_a4;

    /* InitializeConditions for UnitDelay: '<S118>/UD' */
    ctrl_DP_DW.UD_DSTATE_l = ctrl_DP_P.DiscreteDerivative_ICPrevScal_n;

    /* InitializeConditions for RateLimiter: '<S115>/Acceleration limiter' */
    ctrl_DP_DW.PrevY_h = ctrl_DP_P.Accelerationlimiter_IC_p;

    /* InitializeConditions for Memory: '<S115>/Memory' */
    ctrl_DP_DW.Memory_PreviousInput_a4 = ctrl_DP_P.Memory_X0_c;

    /* InitializeConditions for Integrator: '<S117>/Integrator' */
    ctrl_DP_X.Integrator_CSTATE_gj = ctrl_DP_P.Integrator_IC_h;

    /* InitializeConditions for DiscreteTransferFcn: '<S60>/Discrete Transfer Fcn' */
    ctrl_DP_DW.DiscreteTransferFcn_states_o =
      ctrl_DP_P.DiscreteTransferFcn_InitialSt_b;

    /* SystemInitialize for Iterator SubSystem: '<S9>/Optimal angle path and  constraints on rotation speed' */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      /* InitializeConditions for DiscreteIntegrator: '<S47>/Discrete-Time Integrator' */
      ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI = 1U;
      ctrl_DP_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 2;

      /* InitializeConditions for Delay: '<S47>/Delay' */
      ctrl_DP_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_DP_P.CoreSubsys.Delay_InitialCondition;
    }

    /* End of SystemInitialize for SubSystem: '<S9>/Optimal angle path and  constraints on rotation speed' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(ctrl_DP_M)) {
      rtmSetFirstInitCond(ctrl_DP_M, 0);
    }
  }
}

/* Model terminate function */
void ctrl_DP_terminate(void)
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
  ctrl_DP_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_DP_update();
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
  ctrl_DP_initialize();
}

void MdlTerminate(void)
{
  ctrl_DP_terminate();
}

/* Registration function */
RT_MODEL_ctrl_DP_T *ctrl_DP(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_DP_M, 0,
                sizeof(RT_MODEL_ctrl_DP_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_DP_M->solverInfo, &ctrl_DP_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_DP_M->solverInfo, &rtmGetTPtr(ctrl_DP_M));
    rtsiSetStepSizePtr(&ctrl_DP_M->solverInfo, &ctrl_DP_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_DP_M->solverInfo, &ctrl_DP_M->derivs);
    rtsiSetContStatesPtr(&ctrl_DP_M->solverInfo, (real_T **)
                         &ctrl_DP_M->contStates);
    rtsiSetNumContStatesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ctrl_DP_M->solverInfo,
      &ctrl_DP_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&ctrl_DP_M->solverInfo, (&rtmGetErrorStatus(ctrl_DP_M)));
    rtsiSetRTModelPtr(&ctrl_DP_M->solverInfo, ctrl_DP_M);
  }

  rtsiSetSimTimeStep(&ctrl_DP_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_DP_M->intgData.y = ctrl_DP_M->odeY;
  ctrl_DP_M->intgData.f[0] = ctrl_DP_M->odeF[0];
  ctrl_DP_M->intgData.f[1] = ctrl_DP_M->odeF[1];
  ctrl_DP_M->intgData.f[2] = ctrl_DP_M->odeF[2];
  ctrl_DP_M->contStates = ((real_T *) &ctrl_DP_X);
  rtsiSetSolverData(&ctrl_DP_M->solverInfo, (void *)&ctrl_DP_M->intgData);
  rtsiSetSolverName(&ctrl_DP_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_DP_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_DP_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_DP_M->Timing.sampleTimes = (&ctrl_DP_M->Timing.sampleTimesArray[0]);
    ctrl_DP_M->Timing.offsetTimes = (&ctrl_DP_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_DP_M->Timing.sampleTimes[0] = (0.0);
    ctrl_DP_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_DP_M->Timing.offsetTimes[0] = (0.0);
    ctrl_DP_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_DP_M, &ctrl_DP_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_DP_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_DP_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_DP_M, -1);
  ctrl_DP_M->Timing.stepSize0 = 0.01;
  ctrl_DP_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(ctrl_DP_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    ctrl_DP_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_DP_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_DP_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_DP_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_DP_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_DP_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_DP_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_DP_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_DP_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_DP_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_DP_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_DP_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_DP_M->rtwLogInfo, (NULL));
  }

  ctrl_DP_M->solverInfoPtr = (&ctrl_DP_M->solverInfo);
  ctrl_DP_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_DP_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_DP_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_DP_M->blockIO = ((void *) &ctrl_DP_B);
  (void) memset(((void *) &ctrl_DP_B), 0,
                sizeof(B_ctrl_DP_T));

  /* parameters */
  ctrl_DP_M->defaultParam = ((real_T *)&ctrl_DP_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_DP_X;
    ctrl_DP_M->contStates = (x);
    (void) memset((void *)&ctrl_DP_X, 0,
                  sizeof(X_ctrl_DP_T));
  }

  /* states (dwork) */
  ctrl_DP_M->dwork = ((void *) &ctrl_DP_DW);
  (void) memset((void *)&ctrl_DP_DW, 0,
                sizeof(DW_ctrl_DP_T));

  /* Initialize Sizes */
  ctrl_DP_M->Sizes.numContStates = (33);/* Number of continuous states */
  ctrl_DP_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_DP_M->Sizes.numY = (0);         /* Number of model outputs */
  ctrl_DP_M->Sizes.numU = (0);         /* Number of model inputs */
  ctrl_DP_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_DP_M->Sizes.numSampTimes = (2); /* Number of sample times */
  ctrl_DP_M->Sizes.numBlocks = (554);  /* Number of blocks */
  ctrl_DP_M->Sizes.numBlockIO = (212); /* Number of block outputs */
  ctrl_DP_M->Sizes.numBlockPrms = (920);/* Sum of parameter "widths" */
  return ctrl_DP_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_DP
 * Model version : 1.201
 * VeriStand Model Framework version : 2017.0.0.143 (2017)
 * Source generated on : Tue Jul 11 19:56:08 2017
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_DP
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

   case 15:
    return (( double *)ptr)[subindex];

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 18:
    return (( double *)ptr)[subindex];

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

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

   case 33:
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

   case 44:
    return (( double *)ptr)[subindex];

   case 45:
    return (( double *)ptr)[subindex];

   case 46:
    return NIRT_GetValueByDataType(ptr,subindex,45,Complex);

   case 47:
    return (( double *)ptr)[subindex];

   case 48:
    return (( double *)ptr)[subindex];

   case 49:
    return (( double *)ptr)[subindex];

   case 50:
    return (( double *)ptr)[subindex];

   case 51:
    return (( double *)ptr)[subindex];

   case 52:
    return (( double *)ptr)[subindex];

   case 53:
    return (( double *)ptr)[subindex];

   case 54:
    return NIRT_GetValueByDataType(ptr,subindex,53,Complex);

   case 55:
    return (( double *)ptr)[subindex];

   case 56:
    return (( double *)ptr)[subindex];

   case 57:
    return (( double *)ptr)[subindex];

   case 58:
    return (( double *)ptr)[subindex];

   case 59:
    return (( double *)ptr)[subindex];

   case 60:
    return (( double *)ptr)[subindex];

   case 61:
    return (( double *)ptr)[subindex];

   case 62:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 63:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 64:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 65:
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
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 7, Complex);

   case 14:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 15:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 17:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 18:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 19:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 20:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 21:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 35:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 36:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 37:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 38:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 8, Complex);

   case 39:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 40:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 8, Complex);

   case 43:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 44:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 45:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 46:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 45, Complex);

   case 47:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 48:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 49:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 50:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 51:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 52:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 53:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 54:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 53, Complex);

   case 55:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 56:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 57:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 58:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 59:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 60:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 61:
    //Type is struct. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 62:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 63:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 7, Complex);

   case 64:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 65:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 7, Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_DP_rtModel *S;
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

  // ctrl_DP/Input1/Control Gains/K_p_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_p_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Control Gains/K_p_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_p_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Control Gains/K_p_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_p_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Control Gains/K_i_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_i_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Control Gains/K_i_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_i_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Control Gains/K_i_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_i_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Control Gains/K_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Control Gains/K_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Control Gains/K_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.K_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Pos measurements/x_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.x_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Pos measurements/y_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.y_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Pos measurements/psi_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.psi_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Guidance gains/w_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.w_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Guidance gains/w_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.w_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Guidance gains/w_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.w_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Guidance gains/zeta_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.zeta_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Guidance gains/zeta_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.zeta_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/Guidance gains/zeta_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.zeta_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/psi_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.psi_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/x_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.x_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Input1/y_ref
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.y_ref, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster measurment/thr_angle_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.thr_angle_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster measurment/thr_angle_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.thr_angle_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster measurment/thr_angle_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.thr_angle_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster measurment/thr_angle_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.thr_angle_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster measurment/thr_angle_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.thr_angle_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster measurment/thr_angle_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.thr_angle_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thrust allocation/reset
  if (TaskSampleHit[1]) {
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_B.reset_g, count, data[index++], 25, 0);
    }
  } else {
    index += 6;
  }

  // ctrl_DP/Thrust allocation/Angle_controller
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.Angle_controller, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 1/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset_o, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 2/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset_c, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 3/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset_j, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 4/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset_p, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 5/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset_k, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 6/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset_i, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/rpm1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.rpm1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/rpm2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.rpm2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/rpm3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.rpm3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/rpm4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.rpm4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/rpm5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.rpm5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thrust and Shaft speed mapped to PWM/rpm6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.rpm6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 1/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset_kk, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 2/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset_e, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 3/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset_j2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 4/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset_n, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 5/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset_f, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 6/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_B.reset_om, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 53;
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

  // ctrl_DP/alpha_1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation1, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/pwm_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_B.sf_MATLABFunction2_i.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/pwm_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_B.sf_MATLABFunction3.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/pwm_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_B.sf_MATLABFunction4.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/pwm_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_B.sf_MATLABFunction5.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/alpha_2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation2, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/pwm_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_B.sf_MATLABFunction6.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/alpha_3: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation3, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/alpha_4: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation4, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/alpha_5: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation5, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/alpha_6: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation6, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/u_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation7, 0, 25,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/u_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation7, 3, 25,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/u_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation7, 4, 25,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/u_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation7, 5, 25,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/u_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation7, 1, 25,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/u_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation7, 2, 25,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/pwm_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /eta_hat output/x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator, 0, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /eta_hat output/y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator, 1, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum_e, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_hat output/u_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_c, 0, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_hat output/v_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_c, 1, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_hat output/r_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_c, 2, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 0, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 1, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 2, 22, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 0, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 1, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 2, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/tau_actual: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.commanded_tau, 0, 22,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.commanded_tau, 1, 22,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.commanded_tau, 2, 22,
      0);
  } else {
    index += 3;
  }

  // ctrl_DP/Control/DP Controller/eta_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.regulationerror, 0,
      22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.regulationerror, 1,
      22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.regulationerror, 2,
      22, 0);
  } else {
    index += 3;
  }

  // ctrl_DP/Guidance/x_ref_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 0, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Guidance/y_ref_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 1, 22,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP/Guidance/psi_ref_out: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum_a, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP/Thruster control /Thruster 1/Propeller Hydrodynamics/Control_test_Pa: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Pa, 0, 0, 0);
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

  // ctrl_DP/alpha_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation1, 0, 0, 0);

  // ctrl_DP/pwm_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_DP_B.sf_MATLABFunction2_i.Tc_out, 0, 0, 0);

  // ctrl_DP/pwm_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_DP_B.sf_MATLABFunction3.Tc_out, 0, 0, 0);

  // ctrl_DP/pwm_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_DP_B.sf_MATLABFunction4.Tc_out, 0, 0, 0);

  // ctrl_DP/pwm_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_DP_B.sf_MATLABFunction5.Tc_out, 0, 0, 0);

  // ctrl_DP/alpha_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation2, 0, 0, 0);

  // ctrl_DP/pwm_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_DP_B.sf_MATLABFunction6.Tc_out, 0, 0, 0);

  // ctrl_DP/alpha_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation3, 0, 0, 0);

  // ctrl_DP/alpha_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation4, 0, 0, 0);

  // ctrl_DP/alpha_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation5, 0, 0, 0);

  // ctrl_DP/alpha_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation6, 0, 0, 0);

  // ctrl_DP/u_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation7, 0, 25, 0);

  // ctrl_DP/u_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation7, 3, 25, 0);

  // ctrl_DP/u_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation7, 4, 25, 0);

  // ctrl_DP/u_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation7, 5, 25, 0);

  // ctrl_DP/u_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation7, 1, 25, 0);

  // ctrl_DP/u_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Saturation7, 2, 25, 0);

  // ctrl_DP/pwm_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Tc_out, 0, 0, 0);

  // ctrl_DP/Observer output /eta_hat output/x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator, 0, 22, 0);

  // ctrl_DP/Observer output /eta_hat output/y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator, 1, 22, 0);

  // ctrl_DP/Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum_e, 0, 0, 0);

  // ctrl_DP/Observer output /nu_hat output/u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_c, 0, 22,
    0);

  // ctrl_DP/Observer output /nu_hat output/v_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_c, 1, 22,
    0);

  // ctrl_DP/Observer output /nu_hat output/r_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1_c, 2, 22,
    0);

  // ctrl_DP/Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 0, 22, 0);

  // ctrl_DP/Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 1, 22, 0);

  // ctrl_DP/Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.M1, 2, 22, 0);

  // ctrl_DP/Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 0, 22, 0);

  // ctrl_DP/Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 1, 22, 0);

  // ctrl_DP/Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator2, 2, 22, 0);

  // ctrl_DP/tau_actual: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.commanded_tau, 0, 22,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.commanded_tau, 1, 22,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.commanded_tau, 2, 22,
    0);

  // ctrl_DP/Control/DP Controller/eta_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.regulationerror, 0, 22,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.regulationerror, 1, 22,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.regulationerror, 2, 22,
    0);

  // ctrl_DP/Guidance/x_ref_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 0, 22, 0);

  // ctrl_DP/Guidance/y_ref_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Integrator1, 1, 22, 0);

  // ctrl_DP/Guidance/psi_ref_out: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Sum_a, 0, 0, 0);

  // ctrl_DP/Thruster control /Thruster 1/Propeller Hydrodynamics/Control_test_Pa: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_B.Pa, 0, 0, 0);
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
  { 0, "ctrl_dp/Thrust allocation/C/Value", offsetof(P_ctrl_DP_T, C[0]), 27, 24,
    2, 0, 0 },

  { 1, "ctrl_dp/Thruster Parameters /D/Value", offsetof(P_ctrl_DP_T, D), 62, 1,
    2, 2, 0 },

  { 2,
    "ctrl_dp/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed/Gain/I_s",
    offsetof(P_ctrl_DP_T, I_s), 62, 1, 2, 4, 0 },

  { 3,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Inertia compensation/Gain/I_s",
    offsetof(P_ctrl_DP_T, I_s), 62, 1, 2, 6, 0 },

  { 4,
    "ctrl_dp/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed/Gain/I_s",
    offsetof(P_ctrl_DP_T, I_s), 62, 1, 2, 8, 0 },

  { 5,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Inertia compensation/Gain/I_s",
    offsetof(P_ctrl_DP_T, I_s), 62, 1, 2, 10, 0 },

  { 6,
    "ctrl_dp/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed/Gain/I_s",
    offsetof(P_ctrl_DP_T, I_s), 62, 1, 2, 12, 0 },

  { 7,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Inertia compensation/Gain/I_s",
    offsetof(P_ctrl_DP_T, I_s), 62, 1, 2, 14, 0 },

  { 8,
    "ctrl_dp/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed/Gain/I_s",
    offsetof(P_ctrl_DP_T, I_s), 62, 1, 2, 16, 0 },

  { 9,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Inertia compensation/Gain/I_s",
    offsetof(P_ctrl_DP_T, I_s), 62, 1, 2, 18, 0 },

  { 10,
    "ctrl_dp/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed/Gain/I_s",
    offsetof(P_ctrl_DP_T, I_s), 62, 1, 2, 20, 0 },

  { 11,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Inertia compensation/Gain/I_s",
    offsetof(P_ctrl_DP_T, I_s), 62, 1, 2, 22, 0 },

  { 12,
    "ctrl_dp/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed/Gain/I_s",
    offsetof(P_ctrl_DP_T, I_s), 62, 1, 2, 24, 0 },

  { 13,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Inertia compensation/Gain/I_s",
    offsetof(P_ctrl_DP_T, I_s), 62, 1, 2, 26, 0 },

  { 14, "ctrl_dp/Thruster Parameters /K_Tf1/Value", offsetof(P_ctrl_DP_T, K_T1f),
    62, 1, 2, 28, 0 },

  { 15, "ctrl_dp/Thruster Parameters /K_Tr1/Value", offsetof(P_ctrl_DP_T, K_T1r),
    62, 1, 2, 30, 0 },

  { 16, "ctrl_dp/Thruster Parameters /K_Tf2/Value", offsetof(P_ctrl_DP_T, K_T2f),
    62, 1, 2, 32, 0 },

  { 17, "ctrl_dp/Thruster Parameters /K_Tr2/Value", offsetof(P_ctrl_DP_T, K_T2r),
    62, 1, 2, 34, 0 },

  { 18, "ctrl_dp/Thruster Parameters /K_Tf3/Value", offsetof(P_ctrl_DP_T, K_T3f),
    62, 1, 2, 36, 0 },

  { 19, "ctrl_dp/Thruster Parameters /K_Tr3/Value", offsetof(P_ctrl_DP_T, K_T3r),
    62, 1, 2, 38, 0 },

  { 20, "ctrl_dp/Thruster Parameters /K_Tf4/Value", offsetof(P_ctrl_DP_T, K_T4f),
    62, 1, 2, 40, 0 },

  { 21, "ctrl_dp/Thruster Parameters /K_Tr4/Value", offsetof(P_ctrl_DP_T, K_T4r),
    62, 1, 2, 42, 0 },

  { 22, "ctrl_dp/Thruster Parameters /K_Tf5/Value", offsetof(P_ctrl_DP_T, K_T5f),
    62, 1, 2, 44, 0 },

  { 23, "ctrl_dp/Thruster Parameters /K_Tr5/Value", offsetof(P_ctrl_DP_T, K_T5r),
    62, 1, 2, 46, 0 },

  { 24, "ctrl_dp/Thruster Parameters /K_Tf6/Value", offsetof(P_ctrl_DP_T, K_T6f),
    62, 1, 2, 48, 0 },

  { 25, "ctrl_dp/Thruster Parameters /K_Tr6/Value", offsetof(P_ctrl_DP_T, K_T6r),
    62, 1, 2, 50, 0 },

  { 26,
    "ctrl_dp/Thruster control /Thruster 1/Shaft dynamics/K_omega/Gain/K_omega",
    offsetof(P_ctrl_DP_T, K_omega), 62, 1, 2, 52, 0 },

  { 27,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Qff_1(nr)/Gain/K_omega",
    offsetof(P_ctrl_DP_T, K_omega), 62, 1, 2, 54, 0 },

  { 28,
    "ctrl_dp/Thruster control /Thruster 2/Shaft dynamics/K_omega/Gain/K_omega",
    offsetof(P_ctrl_DP_T, K_omega), 62, 1, 2, 56, 0 },

  { 29,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Qff_1(nr)/Gain/K_omega",
    offsetof(P_ctrl_DP_T, K_omega), 62, 1, 2, 58, 0 },

  { 30,
    "ctrl_dp/Thruster control /Thruster 3/Shaft dynamics/K_omega/Gain/K_omega",
    offsetof(P_ctrl_DP_T, K_omega), 62, 1, 2, 60, 0 },

  { 31,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Qff_1(nr)/Gain/K_omega",
    offsetof(P_ctrl_DP_T, K_omega), 62, 1, 2, 62, 0 },

  { 32,
    "ctrl_dp/Thruster control /Thruster 4/Shaft dynamics/K_omega/Gain/K_omega",
    offsetof(P_ctrl_DP_T, K_omega), 62, 1, 2, 64, 0 },

  { 33,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Qff_1(nr)/Gain/K_omega",
    offsetof(P_ctrl_DP_T, K_omega), 62, 1, 2, 66, 0 },

  { 34,
    "ctrl_dp/Thruster control /Thruster 5/Shaft dynamics/K_omega/Gain/K_omega",
    offsetof(P_ctrl_DP_T, K_omega), 62, 1, 2, 68, 0 },

  { 35,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Qff_1(nr)/Gain/K_omega",
    offsetof(P_ctrl_DP_T, K_omega), 62, 1, 2, 70, 0 },

  { 36,
    "ctrl_dp/Thruster control /Thruster 6/Shaft dynamics/K_omega/Gain/K_omega",
    offsetof(P_ctrl_DP_T, K_omega), 62, 1, 2, 72, 0 },

  { 37,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Qff_1(nr)/Gain/K_omega",
    offsetof(P_ctrl_DP_T, K_omega), 62, 1, 2, 74, 0 },

  { 38, "ctrl_dp/Thruster Parameters /K_Qr1/Value", offsetof(P_ctrl_DP_T, K_q1f),
    62, 1, 2, 76, 0 },

  { 39, "ctrl_dp/Thruster Parameters /K_Qr7/Value", offsetof(P_ctrl_DP_T, K_q1r),
    62, 1, 2, 78, 0 },

  { 40, "ctrl_dp/Thruster Parameters /K_Qr2/Value", offsetof(P_ctrl_DP_T, K_q2f),
    62, 1, 2, 80, 0 },

  { 41, "ctrl_dp/Thruster Parameters /K_Qr8/Value", offsetof(P_ctrl_DP_T, K_q2r),
    62, 1, 2, 82, 0 },

  { 42, "ctrl_dp/Thruster Parameters /K_Qr3/Value", offsetof(P_ctrl_DP_T, K_q3f),
    62, 1, 2, 84, 0 },

  { 43, "ctrl_dp/Thruster Parameters /K_Qr9/Value", offsetof(P_ctrl_DP_T, K_q3r),
    62, 1, 2, 86, 0 },

  { 44, "ctrl_dp/Thruster Parameters /K_Qr4/Value", offsetof(P_ctrl_DP_T, K_q4f),
    62, 1, 2, 88, 0 },

  { 45, "ctrl_dp/Thruster Parameters /K_Qr10/Value", offsetof(P_ctrl_DP_T, K_q4r),
    62, 1, 2, 90, 0 },

  { 46, "ctrl_dp/Thruster Parameters /K_Qr5/Value", offsetof(P_ctrl_DP_T, K_q5f),
    62, 1, 2, 92, 0 },

  { 47, "ctrl_dp/Thruster Parameters /K_Qr11/Value", offsetof(P_ctrl_DP_T, K_q5r),
    62, 1, 2, 94, 0 },

  { 48, "ctrl_dp/Thruster Parameters /K_Qr6/Value", offsetof(P_ctrl_DP_T, K_q6f),
    62, 1, 2, 96, 0 },

  { 49, "ctrl_dp/Thruster Parameters /K_Qr12/Value", offsetof(P_ctrl_DP_T, K_q6r),
    62, 1, 2, 98, 0 },

  { 50,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Core controller/Ki/Gain/Kp",
    offsetof(P_ctrl_DP_T, Kp), 62, 1, 2, 100, 0 },

  { 51,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_DP_T, Kp), 62, 1, 2, 102, 0 },

  { 52,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Core controller/Ki/Gain/Kp",
    offsetof(P_ctrl_DP_T, Kp), 62, 1, 2, 104, 0 },

  { 53,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_DP_T, Kp), 62, 1, 2, 106, 0 },

  { 54,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Core controller/Ki/Gain/Kp",
    offsetof(P_ctrl_DP_T, Kp), 62, 1, 2, 108, 0 },

  { 55,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_DP_T, Kp), 62, 1, 2, 110, 0 },

  { 56,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Core controller/Ki/Gain/Kp",
    offsetof(P_ctrl_DP_T, Kp), 62, 1, 2, 112, 0 },

  { 57,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_DP_T, Kp), 62, 1, 2, 114, 0 },

  { 58,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Core controller/Ki/Gain/Kp",
    offsetof(P_ctrl_DP_T, Kp), 62, 1, 2, 116, 0 },

  { 59,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_DP_T, Kp), 62, 1, 2, 118, 0 },

  { 60,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Core controller/Ki/Gain/Kp",
    offsetof(P_ctrl_DP_T, Kp), 62, 1, 2, 120, 0 },

  { 61,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_DP_T, Kp), 62, 1, 2, 122, 0 },

  { 62,
    "ctrl_dp/Thrust allocation/Optimal angle path and  constraints on rotation speed/Max Rotation Rate/UpperLimit",
    offsetof(P_ctrl_DP_T, Max_rotation), 62, 1, 2, 124, 0 },

  { 63,
    "ctrl_dp/Thrust allocation/Optimal angle path and  constraints on rotation speed/Max Rotation Rate/LowerLimit",
    offsetof(P_ctrl_DP_T, Max_rotation), 62, 1, 2, 126, 0 },

  { 64,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 1/UpperLimit",
    offsetof(P_ctrl_DP_T, Max_thrust), 62, 1, 2, 128, 0 },

  { 65,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 10/UpperLimit",
    offsetof(P_ctrl_DP_T, Max_thrust), 62, 1, 2, 130, 0 },

  { 66,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 12/UpperLimit",
    offsetof(P_ctrl_DP_T, Max_thrust), 62, 1, 2, 132, 0 },

  { 67,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 3/UpperLimit",
    offsetof(P_ctrl_DP_T, Max_thrust), 62, 1, 2, 134, 0 },

  { 68,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 5/UpperLimit",
    offsetof(P_ctrl_DP_T, Max_thrust), 62, 1, 2, 136, 0 },

  { 69,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/UpperLimit",
    offsetof(P_ctrl_DP_T, Max_thrust), 62, 1, 2, 138, 0 },

  { 70,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/LowerLimit",
    offsetof(P_ctrl_DP_T, Max_thrust), 62, 1, 2, 140, 0 },

  { 71,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 8/UpperLimit",
    offsetof(P_ctrl_DP_T, Max_thrust), 62, 1, 2, 142, 0 },

  { 72,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 11/LowerLimit",
    offsetof(P_ctrl_DP_T, Min_thrust), 62, 1, 2, 144, 0 },

  { 73,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 13/LowerLimit",
    offsetof(P_ctrl_DP_T, Min_thrust), 62, 1, 2, 146, 0 },

  { 74,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 2/LowerLimit",
    offsetof(P_ctrl_DP_T, Min_thrust), 62, 1, 2, 148, 0 },

  { 75,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 4/LowerLimit",
    offsetof(P_ctrl_DP_T, Min_thrust), 62, 1, 2, 150, 0 },

  { 76,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 6/LowerLimit",
    offsetof(P_ctrl_DP_T, Min_thrust), 62, 1, 2, 152, 0 },

  { 77,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 9/LowerLimit",
    offsetof(P_ctrl_DP_T, Min_thrust), 62, 1, 2, 154, 0 },

  { 78, "ctrl_dp/Thruster control /Thruster 1/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_DP_T, Q_f0), 62, 1, 2, 156, 0 },

  { 79, "ctrl_dp/Thruster control /Thruster 2/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_DP_T, Q_f0), 62, 1, 2, 158, 0 },

  { 80, "ctrl_dp/Thruster control /Thruster 3/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_DP_T, Q_f0), 62, 1, 2, 160, 0 },

  { 81, "ctrl_dp/Thruster control /Thruster 4/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_DP_T, Q_f0), 62, 1, 2, 162, 0 },

  { 82, "ctrl_dp/Thruster control /Thruster 5/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_DP_T, Q_f0), 62, 1, 2, 164, 0 },

  { 83, "ctrl_dp/Thruster control /Thruster 6/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_DP_T, Q_f0), 62, 1, 2, 166, 0 },

  { 84, "ctrl_dp/Thruster Parameters /Rho/Value", offsetof(P_ctrl_DP_T, Rho), 62,
    1, 2, 168, 0 },

  { 85, "ctrl_dp/Thrust allocation/Constant to avoid singularities/Value",
    offsetof(P_ctrl_DP_T, eps), 62, 1, 2, 170, 0 },

  { 86, "ctrl_dp/Thruster Parameters /Constant/Value", offsetof(P_ctrl_DP_T,
    eps_c), 62, 1, 2, 172, 0 },

  { 87,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain/epsilon",
    offsetof(P_ctrl_DP_T, epsilon), 62, 1, 2, 174, 0 },

  { 88,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain/n_max",
    offsetof(P_ctrl_DP_T, n_max), 62, 1, 2, 176, 0 },

  { 89,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain/epsilon",
    offsetof(P_ctrl_DP_T, epsilon), 62, 1, 2, 178, 0 },

  { 90,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain/n_max",
    offsetof(P_ctrl_DP_T, n_max), 62, 1, 2, 180, 0 },

  { 91,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain/epsilon",
    offsetof(P_ctrl_DP_T, epsilon), 62, 1, 2, 182, 0 },

  { 92,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain/n_max",
    offsetof(P_ctrl_DP_T, n_max), 62, 1, 2, 184, 0 },

  { 93,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain/epsilon",
    offsetof(P_ctrl_DP_T, epsilon), 62, 1, 2, 186, 0 },

  { 94,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain/n_max",
    offsetof(P_ctrl_DP_T, n_max), 62, 1, 2, 188, 0 },

  { 95,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain/epsilon",
    offsetof(P_ctrl_DP_T, epsilon), 62, 1, 2, 190, 0 },

  { 96,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain/n_max",
    offsetof(P_ctrl_DP_T, n_max), 62, 1, 2, 192, 0 },

  { 97,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain/epsilon",
    offsetof(P_ctrl_DP_T, epsilon), 62, 1, 2, 194, 0 },

  { 98,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain/n_max",
    offsetof(P_ctrl_DP_T, n_max), 62, 1, 2, 196, 0 },

  { 99, "ctrl_dp/Thruster Parameters /Constant1/Value", offsetof(P_ctrl_DP_T,
    k_cc), 62, 1, 2, 198, 0 },

  { 100, "ctrl_dp/Thruster Parameters /Constant5/Value", offsetof(P_ctrl_DP_T,
    n_c), 62, 1, 2, 200, 0 },

  { 101, "ctrl_dp/Thruster Parameters /Constant2/Value", offsetof(P_ctrl_DP_T,
    p_cc), 62, 1, 2, 202, 0 },

  { 102,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 1/Coefs",
    offsetof(P_ctrl_DP_T, pwm_thr1_backward), 35, 6, 2, 204, 0 },

  { 103,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 1/Coefs",
    offsetof(P_ctrl_DP_T, pwm_thr1_forward), 35, 6, 2, 206, 0 },

  { 104,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 2/Coefs",
    offsetof(P_ctrl_DP_T, pwm_thr2_backward), 35, 6, 2, 208, 0 },

  { 105,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 2/Coefs",
    offsetof(P_ctrl_DP_T, pwm_thr2_forward), 35, 6, 2, 210, 0 },

  { 106,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 3/Coefs",
    offsetof(P_ctrl_DP_T, pwm_thr3_backward), 35, 6, 2, 212, 0 },

  { 107,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 3/Coefs",
    offsetof(P_ctrl_DP_T, pwm_thr3_forward), 35, 6, 2, 214, 0 },

  { 108,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 4/Coefs",
    offsetof(P_ctrl_DP_T, pwm_thr4_backward), 35, 6, 2, 216, 0 },

  { 109,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 4/Coefs",
    offsetof(P_ctrl_DP_T, pwm_thr4_forward), 35, 6, 2, 218, 0 },

  { 110,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 5/Coefs",
    offsetof(P_ctrl_DP_T, pwm_thr5_backward), 35, 6, 2, 220, 0 },

  { 111,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 5/Coefs",
    offsetof(P_ctrl_DP_T, pwm_thr5_forward), 35, 6, 2, 222, 0 },

  { 112,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 6/Coefs",
    offsetof(P_ctrl_DP_T, pwm_thr6_backward), 35, 6, 2, 224, 0 },

  { 113,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 6/Coefs",
    offsetof(P_ctrl_DP_T, pwm_thr6_forward), 35, 6, 2, 226, 0 },

  { 114, "ctrl_dp/Thruster Parameters /Constant3/Value", offsetof(P_ctrl_DP_T,
    r_cc), 62, 1, 2, 228, 0 },

  { 115, "ctrl_dp/Pos measurements/Gain/Gain", offsetof(P_ctrl_DP_T, Gain_Gain),
    62, 1, 2, 230, 0 },

  { 116, "ctrl_dp/Pos measurements/Gain1/Gain", offsetof(P_ctrl_DP_T, Gain1_Gain),
    62, 1, 2, 232, 0 },

  { 117, "ctrl_dp/Pos measurements/Gain5/Gain", offsetof(P_ctrl_DP_T, Gain5_Gain),
    62, 1, 2, 234, 0 },

  { 118, "ctrl_dp/Pos measurements/Saturation/UpperLimit", offsetof(P_ctrl_DP_T,
    Saturation_UpperSat), 62, 1, 2, 236, 0 },

  { 119, "ctrl_dp/Pos measurements/Saturation/LowerLimit", offsetof(P_ctrl_DP_T,
    Saturation_LowerSat), 62, 1, 2, 238, 0 },

  { 120, "ctrl_dp/Pos measurements/Gain6/Gain", offsetof(P_ctrl_DP_T, Gain6_Gain),
    62, 1, 2, 240, 0 },

  { 121, "ctrl_dp/Pos measurements/Constant1/Value", offsetof(P_ctrl_DP_T,
    Constant1_Value), 62, 1, 2, 242, 0 },

  { 122,
    "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_l), 62, 1, 2, 244, 0 },

  { 123,
    "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_i), 62, 1, 2, 246, 0 },

  { 124, "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_p), 62, 1, 2, 248, 0 },

  { 125, "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value), 62, 1, 2, 250, 0 },

  { 126, "ctrl_dp/Input1/Observer Gains/Constant6/Value", offsetof(P_ctrl_DP_T,
    Constant6_Value), 62, 1, 2, 252, 0 },

  { 127, "ctrl_dp/Input1/Observer Gains/Constant7/Value", offsetof(P_ctrl_DP_T,
    Constant7_Value), 62, 1, 2, 254, 0 },

  { 128, "ctrl_dp/Input1/Observer Gains/Constant8/Value", offsetof(P_ctrl_DP_T,
    Constant8_Value), 62, 1, 2, 256, 0 },

  { 129,
    "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_p), 62, 1, 2, 258, 0 },

  { 130,
    "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_a), 62, 1, 2, 260, 0 },

  { 131, "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_a), 62, 1, 2, 262, 0 },

  { 132,
    "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value_j), 62, 1, 2, 264, 0 },

  { 133,
    "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_d), 62, 1, 2, 266, 0 },

  { 134,
    "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_c), 62, 1, 2, 268, 0 },

  { 135, "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_ag), 62, 1, 2, 270, 0 },

  { 136, "ctrl_dp/Control/DP Controller/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value_l), 62, 1, 2, 272, 0 },

  { 137, "ctrl_dp/Control/DP Controller/Integrator/InitialCondition", offsetof
    (P_ctrl_DP_T, Integrator_IC), 62, 1, 2, 274, 0 },

  { 138, "ctrl_dp/Nonlinear Passisve Observer/Integrator1/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator1_IC), 36, 3, 2, 276, 0 },

  { 139, "ctrl_dp/Guidance/Reference model/Integrator3/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator3_IC), 62, 1, 2, 278, 0 },

  { 140, "ctrl_dp/Thrust allocation/Radians to Degrees/Gain/Gain", offsetof
    (P_ctrl_DP_T, Gain_Gain_o), 62, 1, 2, 280, 0 },

  { 141, "ctrl_dp/Thrust allocation/X-position Thruster/Value", offsetof
    (P_ctrl_DP_T, XpositionThruster_Value[0]), 35, 6, 2, 282, 0 },

  { 142, "ctrl_dp/Thrust allocation/Y-position Thruster/Value", offsetof
    (P_ctrl_DP_T, YpositionThruster_Value[0]), 35, 6, 2, 284, 0 },

  { 143, "ctrl_dp/Thrust allocation/constant angle/Value", offsetof(P_ctrl_DP_T,
    constantangle_Value[0]), 35, 6, 2, 286, 0 },

  { 144, "ctrl_dp/Thrust allocation/Choosing Fixed // Azimuth angle/Threshold",
    offsetof(P_ctrl_DP_T, ChoosingFixedAzimuthangle_Thres), 62, 1, 2, 288, 0 },

  { 145, "ctrl_dp/Thruster control /Subsystem1/Saturation 1/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation1_UpperSat), 62, 1, 2, 290, 0 },

  { 146, "ctrl_dp/Thruster control /Subsystem1/Saturation 1/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation1_LowerSat), 62, 1, 2, 292, 0 },

  { 147,
    "ctrl_dp/Thruster control /Thruster 1/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator_IC_f), 62, 1, 2, 294, 0 },

  { 148, "ctrl_dp/Thruster control /Thruster 1/Losses (placeholder)/Value",
    offsetof(P_ctrl_DP_T, Lossesplaceholder_Value), 62, 1, 2, 296, 0 },

  { 149,
    "ctrl_dp/Thruster control /Thruster 2/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator_IC_fg), 62, 1, 2, 298, 0 },

  { 150, "ctrl_dp/Thruster control /Thruster 2/Losses (placeholder)/Value",
    offsetof(P_ctrl_DP_T, Lossesplaceholder_Value_k), 62, 1, 2, 300, 0 },

  { 151,
    "ctrl_dp/Thruster control /Thruster 3/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator_IC_p), 62, 1, 2, 302, 0 },

  { 152, "ctrl_dp/Thruster control /Thruster 3/Losses (placeholder)/Value",
    offsetof(P_ctrl_DP_T, Lossesplaceholder_Value_n), 62, 1, 2, 304, 0 },

  { 153,
    "ctrl_dp/Thruster control /Thruster 4/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator_IC_fv), 62, 1, 2, 306, 0 },

  { 154, "ctrl_dp/Thruster control /Thruster 4/Losses (placeholder)/Value",
    offsetof(P_ctrl_DP_T, Lossesplaceholder_Value_d), 62, 1, 2, 308, 0 },

  { 155,
    "ctrl_dp/Thruster control /Thruster 5/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator_IC_l), 62, 1, 2, 310, 0 },

  { 156, "ctrl_dp/Thruster control /Thruster 5/Losses (placeholder)/Value",
    offsetof(P_ctrl_DP_T, Lossesplaceholder_Value_f), 62, 1, 2, 312, 0 },

  { 157,
    "ctrl_dp/Thruster control /Thruster 6/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator_IC_li), 62, 1, 2, 314, 0 },

  { 158, "ctrl_dp/Thruster control /Thruster 6/Losses (placeholder)/Value",
    offsetof(P_ctrl_DP_T, Lossesplaceholder_Value_h), 62, 1, 2, 316, 0 },

  { 159,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_d), 62, 1, 2, 318, 0 },

  { 160,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Gain1/Gain",
    offsetof(P_ctrl_DP_T, Gain1_Gain_d), 62, 1, 2, 320, 0 },

  { 161,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Gain2/Gain",
    offsetof(P_ctrl_DP_T, Gain2_Gain), 62, 1, 2, 322, 0 },

  { 162,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Gain3/Gain",
    offsetof(P_ctrl_DP_T, Gain3_Gain), 62, 1, 2, 324, 0 },

  { 163,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Gain4/Gain",
    offsetof(P_ctrl_DP_T, Gain4_Gain), 62, 1, 2, 326, 0 },

  { 164,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Gain5/Gain",
    offsetof(P_ctrl_DP_T, Gain5_Gain_m), 62, 1, 2, 328, 0 },

  { 165,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 8/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation8_LowerSat), 62, 1, 2, 330, 0 },

  { 166,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 9/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation9_UpperSat), 62, 1, 2, 332, 0 },

  { 167,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 10/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation10_LowerSat), 62, 1, 2, 334, 0 },

  { 168,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 11/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation11_UpperSat), 62, 1, 2, 336, 0 },

  { 169,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 3/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation3_LowerSat), 62, 1, 2, 338, 0 },

  { 170,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 4/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation4_UpperSat), 62, 1, 2, 340, 0 },

  { 171,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 5/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation5_LowerSat), 62, 1, 2, 342, 0 },

  { 172,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 6/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation6_UpperSat), 62, 1, 2, 344, 0 },

  { 173, "ctrl_dp/Thruster control /Subsystem1/Saturation 2/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation2_UpperSat), 62, 1, 2, 346, 0 },

  { 174, "ctrl_dp/Thruster control /Subsystem1/Saturation 2/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation2_LowerSat), 62, 1, 2, 348, 0 },

  { 175,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 12/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation12_LowerSat), 62, 1, 2, 350, 0 },

  { 176,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 13/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation13_UpperSat), 62, 1, 2, 352, 0 },

  { 177, "ctrl_dp/Thruster control /Subsystem1/Saturation 3/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation3_UpperSat), 62, 1, 2, 354, 0 },

  { 178, "ctrl_dp/Thruster control /Subsystem1/Saturation 3/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation3_LowerSat_f), 62, 1, 2, 356, 0 },

  { 179, "ctrl_dp/Thruster control /Subsystem1/Saturation 4/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation4_UpperSat_p), 62, 1, 2, 358, 0 },

  { 180, "ctrl_dp/Thruster control /Subsystem1/Saturation 4/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation4_LowerSat), 62, 1, 2, 360, 0 },

  { 181, "ctrl_dp/Thruster control /Subsystem1/Saturation 5/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation5_UpperSat), 62, 1, 2, 362, 0 },

  { 182, "ctrl_dp/Thruster control /Subsystem1/Saturation 5/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation5_LowerSat_h), 62, 1, 2, 364, 0 },

  { 183, "ctrl_dp/Thruster control /Subsystem1/Saturation 6/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation6_UpperSat_g), 62, 1, 2, 366, 0 },

  { 184, "ctrl_dp/Thruster control /Subsystem1/Saturation 6/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation6_LowerSat), 62, 1, 2, 368, 0 },

  { 185,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 1/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation1_LowerSat_h), 62, 1, 2, 370, 0 },

  { 186,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 2/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation2_UpperSat_p), 62, 1, 2, 372, 0 },

  { 187,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_i), 62, 1, 2, 374, 0 },

  { 188,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_o), 62, 1, 2, 376, 0 },

  { 189, "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_pg), 62, 1, 2, 378, 0 },

  { 190,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value_k), 62, 1, 2, 380, 0 },

  { 191,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_T, Saturation_UpperSat_e), 62, 1, 2, 382, 0 },

  { 192,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_T, Saturation_LowerSat_g), 62, 1, 2, 384, 0 },

  { 193, "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_T, Gain_Gain_f), 62, 1, 2, 386, 0 },

  { 194,
    "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_T, Constant_Value_p), 62, 1, 2, 388, 0 },

  { 195, "ctrl_dp/Nonlinear Passisve Observer/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator2_IC), 36, 3, 2, 390, 0 },

  { 196, "ctrl_dp/Nonlinear Passisve Observer/M^-1/Gain", offsetof(P_ctrl_DP_T,
    M1_Gain), 23, 9, 2, 392, 0 },

  { 197, "ctrl_dp/Radians to Degrees/Gain/Gain", offsetof(P_ctrl_DP_T,
    Gain_Gain_f0), 62, 1, 2, 394, 0 },

  { 198, "ctrl_dp/X-position Thruster/Value", offsetof(P_ctrl_DP_T,
    XpositionThruster_Value_e[0]), 35, 6, 2, 396, 0 },

  { 199, "ctrl_dp/Y-position Thruster/Value", offsetof(P_ctrl_DP_T,
    YpositionThruster_Value_o[0]), 35, 6, 2, 398, 0 },

  { 200, "ctrl_dp/Guidance/Reference model/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator2_IC_p), 62, 1, 2, 400, 0 },

  { 201, "ctrl_dp/Input1/Observer Gains/Constant/Value", offsetof(P_ctrl_DP_T,
    Constant_Value_c), 62, 1, 2, 402, 0 },

  { 202, "ctrl_dp/Input1/Observer Gains/Constant1/Value", offsetof(P_ctrl_DP_T,
    Constant1_Value_p), 62, 1, 2, 404, 0 },

  { 203, "ctrl_dp/Input1/Observer Gains/Constant2/Value", offsetof(P_ctrl_DP_T,
    Constant2_Value), 62, 1, 2, 406, 0 },

  { 204, "ctrl_dp/Input1/Observer Gains/Constant3/Value", offsetof(P_ctrl_DP_T,
    Constant3_Value), 62, 1, 2, 408, 0 },

  { 205, "ctrl_dp/Input1/Observer Gains/Constant4/Value", offsetof(P_ctrl_DP_T,
    Constant4_Value), 62, 1, 2, 410, 0 },

  { 206, "ctrl_dp/Input1/Observer Gains/Constant5/Value", offsetof(P_ctrl_DP_T,
    Constant5_Value), 62, 1, 2, 412, 0 },

  { 207, "ctrl_dp/Thruster control /Delay/InitialCondition", offsetof
    (P_ctrl_DP_T, Delay_InitialCondition), 62, 1, 2, 414, 0 },

  { 208, "ctrl_dp/Thruster control /Thruster 1/Constant/Value", offsetof
    (P_ctrl_DP_T, Constant_Value_cs[0]), 37, 2, 2, 416, 0 },

  { 209, "ctrl_dp/Thruster control /Thruster 1/Constant1/Value", offsetof
    (P_ctrl_DP_T, Constant1_Value_k[0]), 37, 2, 2, 418, 0 },

  { 210, "ctrl_dp/Thruster control /Thruster 1/Delay/InitialCondition", offsetof
    (P_ctrl_DP_T, Delay_InitialCondition_i), 62, 1, 2, 420, 0 },

  { 211,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_DP_T, Delay_InitialCondition_f), 62, 1, 2, 422, 0 },

  { 212, "ctrl_dp/Thruster control /Thruster 1/Thruster control/Constant1/Value",
    offsetof(P_ctrl_DP_T, Constant1_Value_o[0]), 30, 3, 2, 424, 0 },

  { 213, "ctrl_dp/Thruster control /Thruster 1/Thruster control/Constant2/Value",
    offsetof(P_ctrl_DP_T, Constant2_Value_b[0]), 30, 3, 2, 426, 0 },

  { 214,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_T, DiscreteTransferFcn_InitialStat), 62, 1, 2, 428, 0 },

  { 215,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_DP_T, TSamp_WtEt), 0, 1, 2, 430, 0 },

  { 216,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_ctrl_DP_T, AccelerationLimit_RisingLim), 0, 1, 2, 432, 0 },

  { 217,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_ctrl_DP_T, AccelerationLimit_FallingLim), 0, 1, 2, 434, 0 },

  { 218,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_ctrl_DP_T, AccelerationLimit_IC), 62, 1, 2, 436, 0 },

  { 219, "ctrl_dp/Thruster control /Thruster 1/Thruster control/Memory/X0",
    offsetof(P_ctrl_DP_T, Memory_X0), 62, 1, 2, 438, 0 },

  { 220,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator_IC_a), 62, 1, 2, 440, 0 },

  { 221, "ctrl_dp/Thruster control /Thruster 1/Thruster control/NaN/Value",
    offsetof(P_ctrl_DP_T, NaN_Value), 62, 1, 2, 442, 0 },

  { 222, "ctrl_dp/Thruster control /Thruster 1/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_T, DiscreteTransferFcn_InitialSt_h), 62, 1, 2, 444, 0 },

  { 223, "ctrl_dp/Thruster control /Thruster 2/Constant/Value", offsetof
    (P_ctrl_DP_T, Constant_Value_h[0]), 37, 2, 2, 446, 0 },

  { 224, "ctrl_dp/Thruster control /Thruster 2/Constant1/Value", offsetof
    (P_ctrl_DP_T, Constant1_Value_j[0]), 37, 2, 2, 448, 0 },

  { 225, "ctrl_dp/Thruster control /Thruster 2/Delay/InitialCondition", offsetof
    (P_ctrl_DP_T, Delay_InitialCondition_l), 62, 1, 2, 450, 0 },

  { 226,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_DP_T, Delay_InitialCondition_iv), 62, 1, 2, 452, 0 },

  { 227, "ctrl_dp/Thruster control /Thruster 2/Thruster control/Constant1/Value",
    offsetof(P_ctrl_DP_T, Constant1_Value_b[0]), 30, 3, 2, 454, 0 },

  { 228, "ctrl_dp/Thruster control /Thruster 2/Thruster control/Constant2/Value",
    offsetof(P_ctrl_DP_T, Constant2_Value_i[0]), 30, 3, 2, 456, 0 },

  { 229,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_T, DiscreteTransferFcn_InitialS_hu), 62, 1, 2, 458, 0 },

  { 230,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_DP_T, TSamp_WtEt_k), 0, 1, 2, 460, 0 },

  { 231,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_ctrl_DP_T, AccelerationLimit_RisingLim_n), 0, 1, 2, 462, 0 },

  { 232,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_ctrl_DP_T, AccelerationLimit_FallingLim_n), 0, 1, 2, 464, 0 },

  { 233,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_ctrl_DP_T, AccelerationLimit_IC_m), 62, 1, 2, 466, 0 },

  { 234, "ctrl_dp/Thruster control /Thruster 2/Thruster control/Memory/X0",
    offsetof(P_ctrl_DP_T, Memory_X0_e), 62, 1, 2, 468, 0 },

  { 235,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator_IC_fy), 62, 1, 2, 470, 0 },

  { 236, "ctrl_dp/Thruster control /Thruster 2/Thruster control/NaN/Value",
    offsetof(P_ctrl_DP_T, NaN_Value_l), 62, 1, 2, 472, 0 },

  { 237, "ctrl_dp/Thruster control /Thruster 2/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_T, DiscreteTransferFcn_InitialSt_f), 62, 1, 2, 474, 0 },

  { 238, "ctrl_dp/Thruster control /Thruster 3/Constant/Value", offsetof
    (P_ctrl_DP_T, Constant_Value_n[0]), 37, 2, 2, 476, 0 },

  { 239, "ctrl_dp/Thruster control /Thruster 3/Constant1/Value", offsetof
    (P_ctrl_DP_T, Constant1_Value_a[0]), 37, 2, 2, 478, 0 },

  { 240, "ctrl_dp/Thruster control /Thruster 3/Delay/InitialCondition", offsetof
    (P_ctrl_DP_T, Delay_InitialCondition_d), 62, 1, 2, 480, 0 },

  { 241,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_DP_T, Delay_InitialCondition_h), 62, 1, 2, 482, 0 },

  { 242, "ctrl_dp/Thruster control /Thruster 3/Thruster control/Constant1/Value",
    offsetof(P_ctrl_DP_T, Constant1_Value_g[0]), 30, 3, 2, 484, 0 },

  { 243, "ctrl_dp/Thruster control /Thruster 3/Thruster control/Constant2/Value",
    offsetof(P_ctrl_DP_T, Constant2_Value_h[0]), 30, 3, 2, 486, 0 },

  { 244,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_T, DiscreteTransferFcn_InitialSt_a), 62, 1, 2, 488, 0 },

  { 245,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_DP_T, TSamp_WtEt_m), 0, 1, 2, 490, 0 },

  { 246,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_DP_T, Accelerationlimiter_RisingLim), 0, 1, 2, 492, 0 },

  { 247,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_DP_T, Accelerationlimiter_FallingLim), 0, 1, 2, 494, 0 },

  { 248,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_DP_T, Accelerationlimiter_IC), 62, 1, 2, 496, 0 },

  { 249, "ctrl_dp/Thruster control /Thruster 3/Thruster control/Memory/X0",
    offsetof(P_ctrl_DP_T, Memory_X0_g), 62, 1, 2, 498, 0 },

  { 250,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator_IC_j), 62, 1, 2, 500, 0 },

  { 251, "ctrl_dp/Thruster control /Thruster 3/Thruster control/NaN/Value",
    offsetof(P_ctrl_DP_T, NaN_Value_g), 62, 1, 2, 502, 0 },

  { 252, "ctrl_dp/Thruster control /Thruster 3/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_T, DiscreteTransferFcn_InitialSt_c), 62, 1, 2, 504, 0 },

  { 253, "ctrl_dp/Thruster control /Thruster 4/Constant/Value", offsetof
    (P_ctrl_DP_T, Constant_Value_j4[0]), 37, 2, 2, 506, 0 },

  { 254, "ctrl_dp/Thruster control /Thruster 4/Constant1/Value", offsetof
    (P_ctrl_DP_T, Constant1_Value_oi[0]), 37, 2, 2, 508, 0 },

  { 255, "ctrl_dp/Thruster control /Thruster 4/Delay/InitialCondition", offsetof
    (P_ctrl_DP_T, Delay_InitialCondition_fb), 62, 1, 2, 510, 0 },

  { 256,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_DP_T, Delay_InitialCondition_g), 62, 1, 2, 512, 0 },

  { 257, "ctrl_dp/Thruster control /Thruster 4/Thruster control/Constant1/Value",
    offsetof(P_ctrl_DP_T, Constant1_Value_m[0]), 30, 3, 2, 514, 0 },

  { 258, "ctrl_dp/Thruster control /Thruster 4/Thruster control/Constant2/Value",
    offsetof(P_ctrl_DP_T, Constant2_Value_l[0]), 30, 3, 2, 516, 0 },

  { 259,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_T, DiscreteTransferFcn_InitialS_a1), 62, 1, 2, 518, 0 },

  { 260,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_DP_T, TSamp_WtEt_h), 0, 1, 2, 520, 0 },

  { 261,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_DP_T, Accelerationlimiter_RisingLim_e), 0, 1, 2, 522, 0 },

  { 262,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_DP_T, Accelerationlimiter_FallingLi_b), 0, 1, 2, 524, 0 },

  { 263,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_DP_T, Accelerationlimiter_IC_h), 62, 1, 2, 526, 0 },

  { 264, "ctrl_dp/Thruster control /Thruster 4/Thruster control/Memory/X0",
    offsetof(P_ctrl_DP_T, Memory_X0_k), 62, 1, 2, 528, 0 },

  { 265,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator_IC_g), 62, 1, 2, 530, 0 },

  { 266, "ctrl_dp/Thruster control /Thruster 4/Thruster control/NaN/Value",
    offsetof(P_ctrl_DP_T, NaN_Value_p), 62, 1, 2, 532, 0 },

  { 267, "ctrl_dp/Thruster control /Thruster 4/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_T, DiscreteTransferFcn_InitialSt_p), 62, 1, 2, 534, 0 },

  { 268, "ctrl_dp/Thruster control /Thruster 5/Constant/Value", offsetof
    (P_ctrl_DP_T, Constant_Value_i[0]), 37, 2, 2, 536, 0 },

  { 269, "ctrl_dp/Thruster control /Thruster 5/Constant1/Value", offsetof
    (P_ctrl_DP_T, Constant1_Value_h[0]), 37, 2, 2, 538, 0 },

  { 270, "ctrl_dp/Thruster control /Thruster 5/Delay/InitialCondition", offsetof
    (P_ctrl_DP_T, Delay_InitialCondition_fv), 62, 1, 2, 540, 0 },

  { 271,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_DP_T, Delay_InitialCondition_dz), 62, 1, 2, 542, 0 },

  { 272, "ctrl_dp/Thruster control /Thruster 5/Thruster control/Constant1/Value",
    offsetof(P_ctrl_DP_T, Constant1_Value_mk[0]), 30, 3, 2, 544, 0 },

  { 273, "ctrl_dp/Thruster control /Thruster 5/Thruster control/Constant2/Value",
    offsetof(P_ctrl_DP_T, Constant2_Value_p[0]), 30, 3, 2, 546, 0 },

  { 274,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_T, DiscreteTransferFcn_InitialSt_e), 62, 1, 2, 548, 0 },

  { 275,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_DP_T, TSamp_WtEt_o), 0, 1, 2, 550, 0 },

  { 276,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_DP_T, Accelerationlimiter_RisingLim_b), 0, 1, 2, 552, 0 },

  { 277,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_DP_T, Accelerationlimiter_FallingLi_d), 0, 1, 2, 554, 0 },

  { 278,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_DP_T, Accelerationlimiter_IC_i), 62, 1, 2, 556, 0 },

  { 279, "ctrl_dp/Thruster control /Thruster 5/Thruster control/Memory/X0",
    offsetof(P_ctrl_DP_T, Memory_X0_k3), 62, 1, 2, 558, 0 },

  { 280,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator_IC_aj), 62, 1, 2, 560, 0 },

  { 281, "ctrl_dp/Thruster control /Thruster 5/Thruster control/NaN/Value",
    offsetof(P_ctrl_DP_T, NaN_Value_lq), 62, 1, 2, 562, 0 },

  { 282, "ctrl_dp/Thruster control /Thruster 5/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_T, DiscreteTransferFcn_InitialS_pj), 62, 1, 2, 564, 0 },

  { 283, "ctrl_dp/Thruster control /Thruster 6/Constant/Value", offsetof
    (P_ctrl_DP_T, Constant_Value_ht[0]), 37, 2, 2, 566, 0 },

  { 284, "ctrl_dp/Thruster control /Thruster 6/Constant1/Value", offsetof
    (P_ctrl_DP_T, Constant1_Value_gs[0]), 37, 2, 2, 568, 0 },

  { 285, "ctrl_dp/Thruster control /Thruster 6/Delay/InitialCondition", offsetof
    (P_ctrl_DP_T, Delay_InitialCondition_fi), 62, 1, 2, 570, 0 },

  { 286,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_DP_T, Delay_InitialCondition_a), 62, 1, 2, 572, 0 },

  { 287, "ctrl_dp/Thruster control /Thruster 6/Thruster control/Constant1/Value",
    offsetof(P_ctrl_DP_T, Constant1_Value_oa[0]), 30, 3, 2, 574, 0 },

  { 288, "ctrl_dp/Thruster control /Thruster 6/Thruster control/Constant2/Value",
    offsetof(P_ctrl_DP_T, Constant2_Value_p3[0]), 30, 3, 2, 576, 0 },

  { 289,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_T, DiscreteTransferFcn_InitialS_a4), 62, 1, 2, 578, 0 },

  { 290,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_DP_T, TSamp_WtEt_kk), 0, 1, 2, 580, 0 },

  { 291,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_DP_T, Accelerationlimiter_RisingLi_bi), 0, 1, 2, 582, 0 },

  { 292,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_DP_T, Accelerationlimiter_FallingLi_p), 0, 1, 2, 584, 0 },

  { 293,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_DP_T, Accelerationlimiter_IC_p), 62, 1, 2, 586, 0 },

  { 294, "ctrl_dp/Thruster control /Thruster 6/Thruster control/Memory/X0",
    offsetof(P_ctrl_DP_T, Memory_X0_c), 62, 1, 2, 588, 0 },

  { 295,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_T, Integrator_IC_h), 62, 1, 2, 590, 0 },

  { 296, "ctrl_dp/Thruster control /Thruster 6/Thruster control/NaN/Value",
    offsetof(P_ctrl_DP_T, NaN_Value_j), 62, 1, 2, 592, 0 },

  { 297, "ctrl_dp/Thruster control /Thruster 6/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_DP_T, DiscreteTransferFcn_InitialSt_b), 62, 1, 2, 594, 0 },

  { 298, "ctrl_dp/Thruster control /Delay/DelayLength", offsetof(P_ctrl_DP_T,
    Delay_DelayLength), 63, 1, 2, 596, 0 },

  { 299, "ctrl_dp/Thruster control /Thruster 1/Delay/DelayLength", offsetof
    (P_ctrl_DP_T, Delay_DelayLength_d), 63, 1, 2, 598, 0 },

  { 300,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_DP_T, Delay_DelayLength_f), 63, 1, 2, 600, 0 },

  { 301, "ctrl_dp/Thruster control /Thruster 2/Delay/DelayLength", offsetof
    (P_ctrl_DP_T, Delay_DelayLength_m), 63, 1, 2, 602, 0 },

  { 302,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_DP_T, Delay_DelayLength_p), 63, 1, 2, 604, 0 },

  { 303, "ctrl_dp/Thruster control /Thruster 3/Delay/DelayLength", offsetof
    (P_ctrl_DP_T, Delay_DelayLength_h), 63, 1, 2, 606, 0 },

  { 304,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_DP_T, Delay_DelayLength_b), 63, 1, 2, 608, 0 },

  { 305, "ctrl_dp/Thruster control /Thruster 4/Delay/DelayLength", offsetof
    (P_ctrl_DP_T, Delay_DelayLength_n), 63, 1, 2, 610, 0 },

  { 306,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_DP_T, Delay_DelayLength_mj), 63, 1, 2, 612, 0 },

  { 307, "ctrl_dp/Thruster control /Thruster 5/Delay/DelayLength", offsetof
    (P_ctrl_DP_T, Delay_DelayLength_a), 63, 1, 2, 614, 0 },

  { 308,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_DP_T, Delay_DelayLength_k), 63, 1, 2, 616, 0 },

  { 309, "ctrl_dp/Thruster control /Thruster 6/Delay/DelayLength", offsetof
    (P_ctrl_DP_T, Delay_DelayLength_l), 63, 1, 2, 618, 0 },

  { 310,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_DP_T, Delay_DelayLength_c), 63, 1, 2, 620, 0 },

  { 311,
    "ctrl_dp/Thrust allocation/Optimal angle path and  constraints on rotation speed/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_DP_T, CoreSubsys.DiscreteTimeIntegrator_gainval), 0, 1, 2,
    622, 0 },

  { 312,
    "ctrl_dp/Thrust allocation/Optimal angle path and  constraints on rotation speed/Degrees to Radians/Gain1/Gain",
    offsetof(P_ctrl_DP_T, CoreSubsys.Gain1_Gain), 62, 1, 2, 624, 0 },

  { 313,
    "ctrl_dp/Thrust allocation/Optimal angle path and  constraints on rotation speed/Delay/InitialCondition",
    offsetof(P_ctrl_DP_T, CoreSubsys.Delay_InitialCondition), 62, 1, 2, 626, 0 },

  { 314,
    "ctrl_dp/Thrust allocation/Optimal angle path and  constraints on rotation speed/Delay/DelayLength",
    offsetof(P_ctrl_DP_T, CoreSubsys.Delay_DelayLength), 63, 1, 2, 628, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 315;
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
  3, 1,                                /* Parameter at index 138 */
  1, 1,                                /* Parameter at index 139 */
  1, 1,                                /* Parameter at index 140 */
  1, 6,                                /* Parameter at index 141 */
  1, 6,                                /* Parameter at index 142 */
  1, 6,                                /* Parameter at index 143 */
  1, 1,                                /* Parameter at index 144 */
  1, 1,                                /* Parameter at index 145 */
  1, 1,                                /* Parameter at index 146 */
  1, 1,                                /* Parameter at index 147 */
  1, 1,                                /* Parameter at index 148 */
  1, 1,                                /* Parameter at index 149 */
  1, 1,                                /* Parameter at index 150 */
  1, 1,                                /* Parameter at index 151 */
  1, 1,                                /* Parameter at index 152 */
  1, 1,                                /* Parameter at index 153 */
  1, 1,                                /* Parameter at index 154 */
  1, 1,                                /* Parameter at index 155 */
  1, 1,                                /* Parameter at index 156 */
  1, 1,                                /* Parameter at index 157 */
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
  1, 1,                                /* Parameter at index 194 */
  3, 1,                                /* Parameter at index 195 */
  3, 3,                                /* Parameter at index 196 */
  1, 1,                                /* Parameter at index 197 */
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
  1, 2,                                /* Parameter at index 208 */
  1, 2,                                /* Parameter at index 209 */
  1, 1,                                /* Parameter at index 210 */
  1, 1,                                /* Parameter at index 211 */
  1, 3,                                /* Parameter at index 212 */
  1, 3,                                /* Parameter at index 213 */
  1, 1,                                /* Parameter at index 214 */
  1, 1,                                /* Parameter at index 215 */
  1, 1,                                /* Parameter at index 216 */
  1, 1,                                /* Parameter at index 217 */
  1, 1,                                /* Parameter at index 218 */
  1, 1,                                /* Parameter at index 219 */
  1, 1,                                /* Parameter at index 220 */
  1, 1,                                /* Parameter at index 221 */
  1, 1,                                /* Parameter at index 222 */
  1, 2,                                /* Parameter at index 223 */
  1, 2,                                /* Parameter at index 224 */
  1, 1,                                /* Parameter at index 225 */
  1, 1,                                /* Parameter at index 226 */
  1, 3,                                /* Parameter at index 227 */
  1, 3,                                /* Parameter at index 228 */
  1, 1,                                /* Parameter at index 229 */
  1, 1,                                /* Parameter at index 230 */
  1, 1,                                /* Parameter at index 231 */
  1, 1,                                /* Parameter at index 232 */
  1, 1,                                /* Parameter at index 233 */
  1, 1,                                /* Parameter at index 234 */
  1, 1,                                /* Parameter at index 235 */
  1, 1,                                /* Parameter at index 236 */
  1, 1,                                /* Parameter at index 237 */
  1, 2,                                /* Parameter at index 238 */
  1, 2,                                /* Parameter at index 239 */
  1, 1,                                /* Parameter at index 240 */
  1, 1,                                /* Parameter at index 241 */
  1, 3,                                /* Parameter at index 242 */
  1, 3,                                /* Parameter at index 243 */
  1, 1,                                /* Parameter at index 244 */
  1, 1,                                /* Parameter at index 245 */
  1, 1,                                /* Parameter at index 246 */
  1, 1,                                /* Parameter at index 247 */
  1, 1,                                /* Parameter at index 248 */
  1, 1,                                /* Parameter at index 249 */
  1, 1,                                /* Parameter at index 250 */
  1, 1,                                /* Parameter at index 251 */
  1, 1,                                /* Parameter at index 252 */
  1, 2,                                /* Parameter at index 253 */
  1, 2,                                /* Parameter at index 254 */
  1, 1,                                /* Parameter at index 255 */
  1, 1,                                /* Parameter at index 256 */
  1, 3,                                /* Parameter at index 257 */
  1, 3,                                /* Parameter at index 258 */
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
  1, 2,                                /* Parameter at index 283 */
  1, 2,                                /* Parameter at index 284 */
  1, 1,                                /* Parameter at index 285 */
  1, 1,                                /* Parameter at index 286 */
  1, 3,                                /* Parameter at index 287 */
  1, 3,                                /* Parameter at index 288 */
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
  1, 1,                                /* Parameter at index 300 */
  1, 1,                                /* Parameter at index 301 */
  1, 1,                                /* Parameter at index 302 */
  1, 1,                                /* Parameter at index 303 */
  1, 1,                                /* Parameter at index 304 */
  1, 1,                                /* Parameter at index 305 */
  1, 1,                                /* Parameter at index 306 */
  1, 1,                                /* Parameter at index 307 */
  1, 1,                                /* Parameter at index 308 */
  1, 1,                                /* Parameter at index 309 */
  1, 1,                                /* Parameter at index 310 */
  1, 1,                                /* Parameter at index 311 */
  1, 1,                                /* Parameter at index 312 */
  1, 1,                                /* Parameter at index 313 */
  1, 1,                                /* Parameter at index 314 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_dp/Input1/Control Gains/K_p_x", 0, "", offsetof(B_ctrl_DP_T, K_p_x)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_dp/Input1/Control Gains/K_p_y", 0, "", offsetof(B_ctrl_DP_T, K_p_y)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_dp/Input1/Control Gains/K_p_psi", 0, "", offsetof(B_ctrl_DP_T,
    K_p_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "ctrl_dp/Input1/Control Gains/K_i_psi", 0, "", offsetof(B_ctrl_DP_T,
    K_i_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "ctrl_dp/Input1/Control Gains/K_i_x", 0, "", offsetof(B_ctrl_DP_T, K_i_x)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "ctrl_dp/Input1/Control Gains/K_i_y", 0, "", offsetof(B_ctrl_DP_T, K_i_y)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "ctrl_dp/Input1/Control Gains/K_d_psi", 0, "", offsetof(B_ctrl_DP_T,
    K_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "ctrl_dp/Input1/Control Gains/K_d_x", 0, "", offsetof(B_ctrl_DP_T, K_d_x)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "ctrl_dp/Input1/Control Gains/K_d_y", 0, "", offsetof(B_ctrl_DP_T, K_d_y)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "ctrl_dp/Pos measurements/x_m", 0, "", offsetof(B_ctrl_DP_T, x_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_dp/Pos measurements/Gain", 0, "", offsetof(B_ctrl_DP_T, Gain) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_dp/Pos measurements/y_m", 0, "", offsetof(B_ctrl_DP_T, y_m) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_dp/Pos measurements/Gain1", 0, "", offsetof(B_ctrl_DP_T, Gain1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_dp/Pos measurements/psi_m", 0, "", offsetof(B_ctrl_DP_T, psi_m) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "ctrl_dp/Pos measurements/Sum", 0, "", offsetof(B_ctrl_DP_T, Sum) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "ctrl_dp/Input1/reset", 0, "", offsetof(B_ctrl_DP_T, reset) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "ctrl_dp/Input1/Guidance gains/w_d_x", 0, "", offsetof(B_ctrl_DP_T,
    w_d_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "ctrl_dp/Input1/Guidance gains/w_d_y", 0, "", offsetof(B_ctrl_DP_T,
    w_d_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "ctrl_dp/Input1/Guidance gains/w_d_psi", 0, "", offsetof(B_ctrl_DP_T,
    w_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 19, "ctrl_dp/Input1/Guidance gains/zeta_psi", 0, "", offsetof(B_ctrl_DP_T,
    zeta_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "ctrl_dp/Input1/Guidance gains/zeta_x", 0, "", offsetof(B_ctrl_DP_T,
    zeta_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "ctrl_dp/Input1/Guidance gains/zeta_y", 0, "", offsetof(B_ctrl_DP_T,
    zeta_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "ctrl_dp/Input1/psi_ref", 0, "", offsetof(B_ctrl_DP_T, psi_ref) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 23, "ctrl_dp/Input1/x_ref", 0, "", offsetof(B_ctrl_DP_T, x_ref) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 24, "ctrl_dp/Input1/y_ref", 0, "", offsetof(B_ctrl_DP_T, y_ref) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 25, "ctrl_dp/Guidance/Reference model/Integrator1/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator1) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 26, "ctrl_dp/Guidance/Reference model/Integrator1/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator1) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 27, "ctrl_dp/Guidance/Reference model/Integrator1/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator1) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 28, "ctrl_dp/Guidance/Reference model/[-inf inf] to [-pi pi]1/Sum", 0, "",
    offsetof(B_ctrl_DP_T, Sum_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 29, "ctrl_dp/Control/DP Controller/Sum2", 0, "regulation error(1, 1)",
    offsetof(B_ctrl_DP_T, regulationerror) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 30, "ctrl_dp/Control/DP Controller/Sum2", 0, "regulation error(1, 2)",
    offsetof(B_ctrl_DP_T, regulationerror) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 31, "ctrl_dp/Control/DP Controller/Sum2", 0, "regulation error(1, 3)",
    offsetof(B_ctrl_DP_T, regulationerror) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 32, "ctrl_dp/Nonlinear Passisve Observer/Integrator1/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator1_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 33, "ctrl_dp/Nonlinear Passisve Observer/Integrator1/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator1_c) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 34, "ctrl_dp/Nonlinear Passisve Observer/Integrator1/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator1_c) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 35, "ctrl_dp/Guidance/Reference model/Integrator3/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator3) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 36, "ctrl_dp/Guidance/Reference model/Integrator3/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator3) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 37, "ctrl_dp/Guidance/Reference model/Integrator3/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator3) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 38, "ctrl_dp/Thruster measurment/thr_angle_1", 0, "", offsetof(B_ctrl_DP_T,
    thr_angle_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 39, "ctrl_dp/Thruster measurment/thr_angle_2", 0, "", offsetof(B_ctrl_DP_T,
    thr_angle_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 40, "ctrl_dp/Thruster measurment/thr_angle_3", 0, "", offsetof(B_ctrl_DP_T,
    thr_angle_3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 41, "ctrl_dp/Thruster measurment/thr_angle_4", 0, "", offsetof(B_ctrl_DP_T,
    thr_angle_4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 42, "ctrl_dp/Thruster measurment/thr_angle_5", 0, "", offsetof(B_ctrl_DP_T,
    thr_angle_5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 43, "ctrl_dp/Thruster measurment/thr_angle_6", 0, "", offsetof(B_ctrl_DP_T,
    thr_angle_6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 44, "ctrl_dp/Thrust allocation/reset/(1, 1)", 0, "", offsetof(B_ctrl_DP_T,
    reset_g) + (0*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 45, "ctrl_dp/Thrust allocation/reset/(1, 2)", 0, "", offsetof(B_ctrl_DP_T,
    reset_g) + (1*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 46, "ctrl_dp/Thrust allocation/reset/(1, 3)", 0, "", offsetof(B_ctrl_DP_T,
    reset_g) + (2*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 47, "ctrl_dp/Thrust allocation/reset/(1, 4)", 0, "", offsetof(B_ctrl_DP_T,
    reset_g) + (3*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 48, "ctrl_dp/Thrust allocation/reset/(1, 5)", 0, "", offsetof(B_ctrl_DP_T,
    reset_g) + (4*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 49, "ctrl_dp/Thrust allocation/reset/(1, 6)", 0, "", offsetof(B_ctrl_DP_T,
    reset_g) + (5*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 50, "ctrl_dp/Thrust allocation/Angle_controller", 0, "", offsetof
    (B_ctrl_DP_T, Angle_controller) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 51, "ctrl_dp/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 1)", 0,
    "", offsetof(B_ctrl_DP_T, ChoosingFixedAzimuthangle) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 52, "ctrl_dp/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 2)", 0,
    "", offsetof(B_ctrl_DP_T, ChoosingFixedAzimuthangle) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 53, "ctrl_dp/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 3)", 0,
    "", offsetof(B_ctrl_DP_T, ChoosingFixedAzimuthangle) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 54, "ctrl_dp/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 4)", 0,
    "", offsetof(B_ctrl_DP_T, ChoosingFixedAzimuthangle) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 55, "ctrl_dp/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 5)", 0,
    "", offsetof(B_ctrl_DP_T, ChoosingFixedAzimuthangle) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 56, "ctrl_dp/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 6)", 0,
    "", offsetof(B_ctrl_DP_T, ChoosingFixedAzimuthangle) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 57, "ctrl_dp/Thruster control /Subsystem1/Saturation 1", 0, "", offsetof
    (B_ctrl_DP_T, Saturation1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 58, "ctrl_dp/Thruster control /Thruster 1/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_DP_T, reset_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 59, "ctrl_dp/Thruster control /Thruster 2/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_DP_T, reset_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 60, "ctrl_dp/Thruster control /Thruster 3/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_DP_T, reset_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 61, "ctrl_dp/Thruster control /Thruster 4/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_DP_T, reset_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 62, "ctrl_dp/Thruster control /Thruster 5/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_DP_T, reset_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 63, "ctrl_dp/Thruster control /Thruster 6/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_DP_T, reset_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 64, "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/rpm1", 0,
    "", offsetof(B_ctrl_DP_T, rpm1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 65, "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/rpm2", 0,
    "", offsetof(B_ctrl_DP_T, rpm2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 66, "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/rpm3", 0,
    "", offsetof(B_ctrl_DP_T, rpm3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 67, "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/rpm4", 0,
    "", offsetof(B_ctrl_DP_T, rpm4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 68, "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/rpm5", 0,
    "", offsetof(B_ctrl_DP_T, rpm5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 69, "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/rpm6", 0,
    "", offsetof(B_ctrl_DP_T, rpm6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 70, "ctrl_dp/Thruster control /Subsystem1/Saturation 2", 0, "", offsetof
    (B_ctrl_DP_T, Saturation2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 71, "ctrl_dp/Thruster control /Subsystem1/Saturation 3", 0, "", offsetof
    (B_ctrl_DP_T, Saturation3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 72, "ctrl_dp/Thruster control /Subsystem1/Saturation 4", 0, "", offsetof
    (B_ctrl_DP_T, Saturation4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 73, "ctrl_dp/Thruster control /Subsystem1/Saturation 5", 0, "", offsetof
    (B_ctrl_DP_T, Saturation5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 74, "ctrl_dp/Thruster control /Subsystem1/Saturation 6", 0, "", offsetof
    (B_ctrl_DP_T, Saturation6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 75,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 1)",
    0, "", offsetof(B_ctrl_DP_T, Saturation7) + (0*sizeof(real_T)), BLOCKIO_SIG,
    25, 1, 2, 0, 0 },

  { 76,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 2)",
    0, "", offsetof(B_ctrl_DP_T, Saturation7) + (1*sizeof(real_T)), BLOCKIO_SIG,
    25, 1, 2, 0, 0 },

  { 77,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 3)",
    0, "", offsetof(B_ctrl_DP_T, Saturation7) + (2*sizeof(real_T)), BLOCKIO_SIG,
    25, 1, 2, 0, 0 },

  { 78,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 4)",
    0, "", offsetof(B_ctrl_DP_T, Saturation7) + (3*sizeof(real_T)), BLOCKIO_SIG,
    25, 1, 2, 0, 0 },

  { 79,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 5)",
    0, "", offsetof(B_ctrl_DP_T, Saturation7) + (4*sizeof(real_T)), BLOCKIO_SIG,
    25, 1, 2, 0, 0 },

  { 80,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 6)",
    0, "", offsetof(B_ctrl_DP_T, Saturation7) + (5*sizeof(real_T)), BLOCKIO_SIG,
    25, 1, 2, 0, 0 },

  { 81, "ctrl_dp/Nonlinear Passisve Observer/Integrator/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 82, "ctrl_dp/Nonlinear Passisve Observer/Integrator/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 83, "ctrl_dp/Nonlinear Passisve Observer/Integrator/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, Integrator) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0
  },

  { 84, "ctrl_dp/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Sum", 0, "",
    offsetof(B_ctrl_DP_T, Sum_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 85, "ctrl_dp/Nonlinear Passisve Observer/Integrator2/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator2) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1,
    2, 0, 0 },

  { 86, "ctrl_dp/Nonlinear Passisve Observer/Integrator2/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator2) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1,
    2, 0, 0 },

  { 87, "ctrl_dp/Nonlinear Passisve Observer/Integrator2/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, Integrator2) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1,
    2, 0, 0 },

  { 88, "ctrl_dp/Nonlinear Passisve Observer/M^-1/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, M1) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 89, "ctrl_dp/Nonlinear Passisve Observer/M^-1/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, M1) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 90, "ctrl_dp/Nonlinear Passisve Observer/M^-1/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, M1) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 91, "ctrl_dp/Radians to Degrees/Gain/(1, 1)", 0, "", offsetof(B_ctrl_DP_T,
    Gain_g) + (0*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 92, "ctrl_dp/Radians to Degrees/Gain/(1, 2)", 0, "", offsetof(B_ctrl_DP_T,
    Gain_g) + (1*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 93, "ctrl_dp/Radians to Degrees/Gain/(1, 3)", 0, "", offsetof(B_ctrl_DP_T,
    Gain_g) + (2*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 94, "ctrl_dp/Radians to Degrees/Gain/(1, 4)", 0, "", offsetof(B_ctrl_DP_T,
    Gain_g) + (3*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 95, "ctrl_dp/Radians to Degrees/Gain/(1, 5)", 0, "", offsetof(B_ctrl_DP_T,
    Gain_g) + (4*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 96, "ctrl_dp/Radians to Degrees/Gain/(1, 6)", 0, "", offsetof(B_ctrl_DP_T,
    Gain_g) + (5*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 97, "ctrl_dp/Guidance/Reference model/Matrix Multiply/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 98, "ctrl_dp/Guidance/Reference model/Matrix Multiply/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 99, "ctrl_dp/Guidance/Reference model/Matrix Multiply/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 100, "ctrl_dp/Guidance/Reference model/Sum5", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, Sum5) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 101, "ctrl_dp/Guidance/Reference model/Sum5", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, Sum5) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 102, "ctrl_dp/Guidance/Reference model/Sum5", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, Sum5) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 103, "ctrl_dp/Nonlinear Passisve Observer/Matrix Multiply1/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply1) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 104, "ctrl_dp/Nonlinear Passisve Observer/Matrix Multiply1/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply1) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 105, "ctrl_dp/Nonlinear Passisve Observer/Matrix Multiply1/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_T, MatrixMultiply1) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 106, "ctrl_dp/Nonlinear Passisve Observer/Sum1/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_T, Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 107, "ctrl_dp/Nonlinear Passisve Observer/Sum1/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_T, Sum1) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 108, "ctrl_dp/Nonlinear Passisve Observer/Sum1/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_T, Sum1) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 109, "ctrl_dp/Thruster control /Delay/(1, 1)", 0, "", offsetof(B_ctrl_DP_T,
    Delay) + (0*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 110, "ctrl_dp/Thruster control /Delay/(1, 2)", 0, "", offsetof(B_ctrl_DP_T,
    Delay) + (1*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 111, "ctrl_dp/Thruster control /Delay/(1, 3)", 0, "", offsetof(B_ctrl_DP_T,
    Delay) + (2*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 112, "ctrl_dp/Thruster control /Delay/(1, 4)", 0, "", offsetof(B_ctrl_DP_T,
    Delay) + (3*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 113, "ctrl_dp/Thruster control /Delay/(1, 5)", 0, "", offsetof(B_ctrl_DP_T,
    Delay) + (4*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 114, "ctrl_dp/Thruster control /Delay/(1, 6)", 0, "", offsetof(B_ctrl_DP_T,
    Delay) + (5*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 115, "ctrl_dp/Thruster control /Thruster 1/Delay", 0, "", offsetof
    (B_ctrl_DP_T, Delay_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 116, "ctrl_dp/Thruster control /Thruster 1/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_DP_T, Delay_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 117,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_DP_T, DiscreteTransferFcn) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 118,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_DP_T, TSamp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 119,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_DP_T, Inertiacompensation) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 120, "ctrl_dp/Thruster control /Thruster 1/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_DP_T, Sum1_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 121, "ctrl_dp/Thruster control /Thruster 1/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_DP_T, Memory) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 122,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_DP_T, Kp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 123,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_DP_T, reset_kk) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 124, "ctrl_dp/Thruster control /Thruster 1/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_DP_T, Sum_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 125, "ctrl_dp/Thruster control /Thruster 1/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_DP_T, DiscreteTransferFcn_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 126,
    "ctrl_dp/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_DP_T, Findingrotationspeed) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 127,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_DP_T, Ki) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 128, "ctrl_dp/Thruster control /Thruster 2/Delay", 0, "", offsetof
    (B_ctrl_DP_T, Delay_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 129, "ctrl_dp/Thruster control /Thruster 2/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_DP_T, Delay_bs) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 130,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_DP_T, DiscreteTransferFcn_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 131,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_DP_T, TSamp_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 132,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_DP_T, Inertiacompensation_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 133, "ctrl_dp/Thruster control /Thruster 2/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_DP_T, Sum1_nn) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 134, "ctrl_dp/Thruster control /Thruster 2/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_DP_T, Memory_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 135,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_DP_T, Kp_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 136,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_DP_T, reset_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 137, "ctrl_dp/Thruster control /Thruster 2/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_DP_T, Sum_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 138, "ctrl_dp/Thruster control /Thruster 2/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_DP_T, DiscreteTransferFcn_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 139,
    "ctrl_dp/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_DP_T, Findingrotationspeed_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 140,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_DP_T, Ki_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 141, "ctrl_dp/Thruster control /Thruster 3/Delay", 0, "", offsetof
    (B_ctrl_DP_T, Delay_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 142, "ctrl_dp/Thruster control /Thruster 3/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_DP_T, Delay_by) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 143,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_DP_T, DiscreteTransferFcn_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 144,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_DP_T, TSamp_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 145,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_DP_T, Inertiacompensation_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 146, "ctrl_dp/Thruster control /Thruster 3/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_DP_T, Sum1_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 147, "ctrl_dp/Thruster control /Thruster 3/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_DP_T, Memory_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 148,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_DP_T, Kp_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 149,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_DP_T, reset_j2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 150, "ctrl_dp/Thruster control /Thruster 3/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_DP_T, Sum_hf) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 151, "ctrl_dp/Thruster control /Thruster 3/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_DP_T, DiscreteTransferFcn_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 152,
    "ctrl_dp/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_DP_T, Findingrotationspeed_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 153,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_DP_T, Ki_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 154, "ctrl_dp/Thruster control /Thruster 4/Delay", 0, "", offsetof
    (B_ctrl_DP_T, Delay_g) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 155, "ctrl_dp/Thruster control /Thruster 4/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_DP_T, Delay_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 156,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_DP_T, DiscreteTransferFcn_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 157,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_DP_T, TSamp_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 158,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_DP_T, Inertiacompensation_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 159, "ctrl_dp/Thruster control /Thruster 4/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_DP_T, Sum1_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 160, "ctrl_dp/Thruster control /Thruster 4/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_DP_T, Memory_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 161,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_DP_T, Kp_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 162,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_DP_T, reset_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 163, "ctrl_dp/Thruster control /Thruster 4/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_DP_T, Sum_k2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 164, "ctrl_dp/Thruster control /Thruster 4/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_DP_T, DiscreteTransferFcn_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 165,
    "ctrl_dp/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_DP_T, Findingrotationspeed_ms) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 166,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_DP_T, Ki_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 167, "ctrl_dp/Thruster control /Thruster 5/Delay", 0, "", offsetof
    (B_ctrl_DP_T, Delay_a5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 168, "ctrl_dp/Thruster control /Thruster 5/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_DP_T, Delay_id) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 169,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_DP_T, DiscreteTransferFcn_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 170,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_DP_T, TSamp_m) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 171,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_DP_T, Inertiacompensation_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 172, "ctrl_dp/Thruster control /Thruster 5/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_DP_T, Sum1_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 173, "ctrl_dp/Thruster control /Thruster 5/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_DP_T, Memory_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 174,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_DP_T, Kp_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 175,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_DP_T, reset_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 176, "ctrl_dp/Thruster control /Thruster 5/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_DP_T, Sum_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 177, "ctrl_dp/Thruster control /Thruster 5/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_DP_T, DiscreteTransferFcn_lz) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 178,
    "ctrl_dp/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_DP_T, Findingrotationspeed_ag) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 179,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_DP_T, Ki_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 180, "ctrl_dp/Thruster control /Thruster 6/Delay", 0, "", offsetof
    (B_ctrl_DP_T, Delay_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 181, "ctrl_dp/Thruster control /Thruster 6/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_DP_T, Delay_il) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 182,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_DP_T, DiscreteTransferFcn_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 183,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_DP_T, TSamp_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 184,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_DP_T, Inertiacompensation_e3) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 185, "ctrl_dp/Thruster control /Thruster 6/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_DP_T, Sum1_io) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 186, "ctrl_dp/Thruster control /Thruster 6/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_DP_T, Memory_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 187,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_DP_T, Kp_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 188,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_DP_T, reset_om) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 189, "ctrl_dp/Thruster control /Thruster 6/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_DP_T, Sum_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 190, "ctrl_dp/Thruster control /Thruster 6/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_DP_T, DiscreteTransferFcn_ea) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 191,
    "ctrl_dp/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_DP_T, Findingrotationspeed_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 192,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_DP_T, Ki_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 193, "ctrl_dp/Thruster control /Thruster 6/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_DP_T, n_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 194, "ctrl_dp/Thruster control /Thruster 3/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_DP_T, n_d_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 195, "ctrl_dp/Thruster control /Thruster 1/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_DP_T, n_d_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 196,
    "ctrl_dp/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_DP_T, Qa) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 197,
    "ctrl_dp/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    2, "", offsetof(B_ctrl_DP_T, Pa) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 198,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function1",
    0, "", offsetof(B_ctrl_DP_T, Tc_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 199,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 1)", offsetof(B_ctrl_DP_T, output) + (0*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 200,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 2)", offsetof(B_ctrl_DP_T, output) + (1*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 201,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 3)", offsetof(B_ctrl_DP_T, output) + (2*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 202,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 4)", offsetof(B_ctrl_DP_T, output) + (3*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 203,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 5)", offsetof(B_ctrl_DP_T, output) + (4*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 204,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 6)", offsetof(B_ctrl_DP_T, output) + (5*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 205,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 7)", offsetof(B_ctrl_DP_T, output) + (6*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 206,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 8)", offsetof(B_ctrl_DP_T, output) + (7*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 207,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 9)", offsetof(B_ctrl_DP_T, output) + (8*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 208,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 10)", offsetof(B_ctrl_DP_T, output) + (9*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 209,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 11)", offsetof(B_ctrl_DP_T, output) + (10*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 210,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 12)", offsetof(B_ctrl_DP_T, output) + (11*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 211, "ctrl_dp/Finding commanded forces in: [Surge,Sway,Yaw]", 0, "(1, 1)",
    offsetof(B_ctrl_DP_T, commanded_tau) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 212, "ctrl_dp/Finding commanded forces in: [Surge,Sway,Yaw]", 0, "(1, 2)",
    offsetof(B_ctrl_DP_T, commanded_tau) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 213, "ctrl_dp/Finding commanded forces in: [Surge,Sway,Yaw]", 0, "(1, 3)",
    offsetof(B_ctrl_DP_T, commanded_tau) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 214, "ctrl_dp/Thruster control /Thruster 6/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_DP_T, sf_Supervisor_e.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 215,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePower_nf.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 216,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePower_nf.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 217,
    "ctrl_dp/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePower_nf.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 218,
    "ctrl_dp/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_DP_T, sf_ActualForceandTorque_j.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 219,
    "ctrl_dp/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_DP_T, sf_ActualForceandTorque_j.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 220, "ctrl_dp/Thruster control /Thruster 5/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_DP_T, sf_Supervisor_b.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 221, "ctrl_dp/Thruster control /Thruster 5/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_DP_T, sf_MATLABFunction_j.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 222, "ctrl_dp/Thruster control /Thruster 5/Thruster control/MATLAB Function",
    1, "", offsetof(B_ctrl_DP_T, sf_MATLABFunction_j.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 223,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePowera_h.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 224,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePowera_h.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 225,
    "ctrl_dp/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePowera_h.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 226,
    "ctrl_dp/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_DP_T, sf_ActualForceandTorque_o.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 227,
    "ctrl_dp/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_DP_T, sf_ActualForceandTorque_o.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 228, "ctrl_dp/Thruster control /Thruster 4/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_DP_T, sf_Supervisor_n.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 229, "ctrl_dp/Thruster control /Thruster 4/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_DP_T, sf_MATLABFunction_go.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 230, "ctrl_dp/Thruster control /Thruster 4/Thruster control/MATLAB Function",
    1, "", offsetof(B_ctrl_DP_T, sf_MATLABFunction_go.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 231,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePower_n3.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 232,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePower_n3.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 233,
    "ctrl_dp/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePower_n3.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 234,
    "ctrl_dp/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_DP_T, sf_ActualForceandTorque_m.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 235,
    "ctrl_dp/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_DP_T, sf_ActualForceandTorque_m.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 236, "ctrl_dp/Thruster control /Thruster 3/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_DP_T, sf_Supervisor_l.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 237,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePowera_n.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 238,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePowera_n.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 239,
    "ctrl_dp/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePowera_n.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 240,
    "ctrl_dp/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_DP_T, sf_ActualForceandTorque_h.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 241,
    "ctrl_dp/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_DP_T, sf_ActualForceandTorque_h.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 242, "ctrl_dp/Thruster control /Thruster 2/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_DP_T, sf_Supervisor_h.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 243, "ctrl_dp/Thruster control /Thruster 2/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_DP_T, sf_MATLABFunction_i.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 244, "ctrl_dp/Thruster control /Thruster 2/Thruster control/MATLAB Function",
    1, "", offsetof(B_ctrl_DP_T, sf_MATLABFunction_i.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 245,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePowera_o.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 246,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePowera_o.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 247,
    "ctrl_dp/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePowera_o.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 248,
    "ctrl_dp/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_DP_T, sf_ActualForceandTorque_f.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 249,
    "ctrl_dp/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_DP_T, sf_ActualForceandTorque_f.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 250, "ctrl_dp/Thruster control /Thruster 1/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_DP_T, sf_Supervisor.u) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 251,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePowerand.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 252,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePowerand.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 253,
    "ctrl_dp/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_DP_T, sf_CorecontrollerTorquePowerand.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 254,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function6",
    0, "", offsetof(B_ctrl_DP_T, sf_MATLABFunction6.Tc_out) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 255,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function5",
    0, "", offsetof(B_ctrl_DP_T, sf_MATLABFunction5.Tc_out) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 256,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function4",
    0, "", offsetof(B_ctrl_DP_T, sf_MATLABFunction4.Tc_out) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 257,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function3",
    0, "", offsetof(B_ctrl_DP_T, sf_MATLABFunction3.Tc_out) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 258,
    "ctrl_dp/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function2",
    0, "", offsetof(B_ctrl_DP_T, sf_MATLABFunction2_i.Tc_out) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 259,
    "ctrl_dp/Thrust allocation/Optimal angle path and  constraints on rotation speed/Discrete-Time Integrator",
    0, "angle", offsetof(B_ctrl_DP_T, CoreSubsys[5].angle) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 260,
    "ctrl_dp/Thrust allocation/Optimal angle path and  constraints on rotation speed/Delay",
    0, "", offsetof(B_ctrl_DP_T, CoreSubsys[5].Delay) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 261,
    "ctrl_dp/Thrust allocation/Optimal angle path and  constraints on rotation speed/Max Rotation Rate",
    0, "", offsetof(B_ctrl_DP_T, CoreSubsys[5].MaxRotationRate) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 262, "ctrl_dp/Input1/Observer Gains/MATLAB Function2", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_a.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 263, "ctrl_dp/Input1/Observer Gains/MATLAB Function2", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_a.y) + (1*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 264, "ctrl_dp/Input1/Observer Gains/MATLAB Function2", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_a.y) + (2*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 265, "ctrl_dp/Input1/Observer Gains/MATLAB Function2", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_a.y) + (3*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 266, "ctrl_dp/Input1/Observer Gains/MATLAB Function2", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_a.y) + (4*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 267, "ctrl_dp/Input1/Observer Gains/MATLAB Function2", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_a.y) + (5*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 268, "ctrl_dp/Input1/Observer Gains/MATLAB Function2", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_a.y) + (6*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 269, "ctrl_dp/Input1/Observer Gains/MATLAB Function2", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_a.y) + (7*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 270, "ctrl_dp/Input1/Observer Gains/MATLAB Function2", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2_a.y) + (8*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 271, "ctrl_dp/Input1/Observer Gains/MATLAB Function1", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 272, "ctrl_dp/Input1/Observer Gains/MATLAB Function1", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (1*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 273, "ctrl_dp/Input1/Observer Gains/MATLAB Function1", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (2*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 274, "ctrl_dp/Input1/Observer Gains/MATLAB Function1", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (3*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 275, "ctrl_dp/Input1/Observer Gains/MATLAB Function1", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (4*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 276, "ctrl_dp/Input1/Observer Gains/MATLAB Function1", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (5*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 277, "ctrl_dp/Input1/Observer Gains/MATLAB Function1", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (6*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 278, "ctrl_dp/Input1/Observer Gains/MATLAB Function1", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (7*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 279, "ctrl_dp/Input1/Observer Gains/MATLAB Function1", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_k.y) + (8*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 280, "ctrl_dp/Input1/Observer Gains/MATLAB Function", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_p.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 281, "ctrl_dp/Input1/Observer Gains/MATLAB Function", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_p.y) + (1*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 282, "ctrl_dp/Input1/Observer Gains/MATLAB Function", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_p.y) + (2*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 283, "ctrl_dp/Input1/Observer Gains/MATLAB Function", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_p.y) + (3*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 284, "ctrl_dp/Input1/Observer Gains/MATLAB Function", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_p.y) + (4*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 285, "ctrl_dp/Input1/Observer Gains/MATLAB Function", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_p.y) + (5*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 286, "ctrl_dp/Input1/Observer Gains/MATLAB Function", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_p.y) + (6*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 287, "ctrl_dp/Input1/Observer Gains/MATLAB Function", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_p.y) + (7*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 288, "ctrl_dp/Input1/Observer Gains/MATLAB Function", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_p.y) + (8*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 289, "ctrl_dp/Input1/Guidance gains/MATLAB Function1", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 290, "ctrl_dp/Input1/Guidance gains/MATLAB Function1", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (1*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 291, "ctrl_dp/Input1/Guidance gains/MATLAB Function1", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (2*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 292, "ctrl_dp/Input1/Guidance gains/MATLAB Function1", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (3*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 293, "ctrl_dp/Input1/Guidance gains/MATLAB Function1", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (4*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 294, "ctrl_dp/Input1/Guidance gains/MATLAB Function1", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (5*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 295, "ctrl_dp/Input1/Guidance gains/MATLAB Function1", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (6*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 296, "ctrl_dp/Input1/Guidance gains/MATLAB Function1", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (7*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 297, "ctrl_dp/Input1/Guidance gains/MATLAB Function1", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1_c.y) + (8*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 298, "ctrl_dp/Input1/Guidance gains/MATLAB Function", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_d.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 299, "ctrl_dp/Input1/Guidance gains/MATLAB Function", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_d.y) + (1*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 300, "ctrl_dp/Input1/Guidance gains/MATLAB Function", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_d.y) + (2*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 301, "ctrl_dp/Input1/Guidance gains/MATLAB Function", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_d.y) + (3*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 302, "ctrl_dp/Input1/Guidance gains/MATLAB Function", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_d.y) + (4*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 303, "ctrl_dp/Input1/Guidance gains/MATLAB Function", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_d.y) + (5*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 304, "ctrl_dp/Input1/Guidance gains/MATLAB Function", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_d.y) + (6*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 305, "ctrl_dp/Input1/Guidance gains/MATLAB Function", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_d.y) + (7*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 306, "ctrl_dp/Input1/Guidance gains/MATLAB Function", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction_d.y) + (8*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 307, "ctrl_dp/Input1/Control Gains/MATLAB Function2", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 308, "ctrl_dp/Input1/Control Gains/MATLAB Function2", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.y) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 309, "ctrl_dp/Input1/Control Gains/MATLAB Function2", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.y) + (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 310, "ctrl_dp/Input1/Control Gains/MATLAB Function2", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.y) + (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 311, "ctrl_dp/Input1/Control Gains/MATLAB Function2", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.y) + (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 312, "ctrl_dp/Input1/Control Gains/MATLAB Function2", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.y) + (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 313, "ctrl_dp/Input1/Control Gains/MATLAB Function2", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.y) + (6*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 314, "ctrl_dp/Input1/Control Gains/MATLAB Function2", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.y) + (7*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 315, "ctrl_dp/Input1/Control Gains/MATLAB Function2", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction2.y) + (8*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 316, "ctrl_dp/Input1/Control Gains/MATLAB Function1", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 317, "ctrl_dp/Input1/Control Gains/MATLAB Function1", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.y) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 318, "ctrl_dp/Input1/Control Gains/MATLAB Function1", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.y) + (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 319, "ctrl_dp/Input1/Control Gains/MATLAB Function1", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.y) + (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 320, "ctrl_dp/Input1/Control Gains/MATLAB Function1", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.y) + (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 321, "ctrl_dp/Input1/Control Gains/MATLAB Function1", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.y) + (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 322, "ctrl_dp/Input1/Control Gains/MATLAB Function1", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.y) + (6*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 323, "ctrl_dp/Input1/Control Gains/MATLAB Function1", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.y) + (7*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 324, "ctrl_dp/Input1/Control Gains/MATLAB Function1", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction1.y) + (8*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 325, "ctrl_dp/Input1/Control Gains/MATLAB Function", 0, "(1, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.y) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 326, "ctrl_dp/Input1/Control Gains/MATLAB Function", 0, "(2, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.y) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 327, "ctrl_dp/Input1/Control Gains/MATLAB Function", 0, "(3, 1)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.y) + (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 328, "ctrl_dp/Input1/Control Gains/MATLAB Function", 0, "(1, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.y) + (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 329, "ctrl_dp/Input1/Control Gains/MATLAB Function", 0, "(2, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.y) + (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 330, "ctrl_dp/Input1/Control Gains/MATLAB Function", 0, "(3, 2)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.y) + (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 331, "ctrl_dp/Input1/Control Gains/MATLAB Function", 0, "(1, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.y) + (6*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 332, "ctrl_dp/Input1/Control Gains/MATLAB Function", 0, "(2, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.y) + (7*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 333, "ctrl_dp/Input1/Control Gains/MATLAB Function", 0, "(3, 3)", offsetof
    (B_ctrl_DP_T, sf_MATLABFunction.y) + (8*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 334;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 84;
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

  { 43, "Thruster control /Thruster 1/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 44, "Thruster control /Thruster 2/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 45, "Thruster control /Thruster 3/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 46, "Thruster control /Thruster 4/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 47, "Thruster control /Thruster 5/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 48, "Thruster control /Thruster 6/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

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

  { 33, "Guidance/x_ref_out", 0, EXT_OUT, 1, 1, 1 },

  { 34, "Guidance/y_ref_out", 0, EXT_OUT, 1, 1, 1 },

  { 35, "Guidance/psi_ref_out", 0, EXT_OUT, 1, 1, 1 },

  { 36, "Thruster control /Thruster 1/Propeller Hydrodynamics/Control_test_Pa",
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
  "ctrl_DP";
static const char* NI_CompiledModelVersion = "1.201";
static const char* NI_CompiledModelDateTime = "Tue Jul 11 19:56:08 2017";
static const char* NI_builder DataSection(".NIVS.builder") =
  "NI Model Framework 2017.0.0.143 (2017) for Simulink Coder 8.11 (R2016b)";
static const char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2017.0.0.143";

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
 *		Helper function to probe one signal. baseaddr must NOT be VIRTUAL_SIG
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: Returns the last index value probed in a vector signal
 *========================================================================*/
static int32_t NI_ProbeOneSignal(int32_t idx, double *value, int32_t len,
  int32_t *count, int32_t vOffset, int32_t vLength)
{
  if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
    SetSITErrorMessage("NI_ProbeOneSignal: Received request to probe a virtual signal, but was expecting a ground source. Ignoring virtual signal probe. Report this behavior to National Instruments.",
                       0);
    return 0;
  } else {
    char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ? S->blockIO :
                        S->inputs) + (uintptr_t)NI_SigList[idx].addr;
    int32_t subindex = (vLength == -1) ? 0 : vOffset;
    int32_t sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength +
      vOffset);
    while ((subindex < sublength) && (*count < len))
      value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++,
        NI_SigList[idx].datatype, NI_SigList[idx].IsComplex);
    return *count;
  }
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
  memcpy(&rtParameter[0], &ctrl_DP_P, sizeof(P_ctrl_DP_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_DP_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_DP_T));
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
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* Commit parameter values */
  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_DP_T));
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
               (P_ctrl_DP_T));
      }

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /* If we have values to commit, then save to the write-side */
    if (WriteSideDirtyFlag == 1) {
      S->defaultParam = (double *)&rtParameter[1-READSIDE];
      WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
      READSIDE = 1 - READSIDE;
      SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
      ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

      // Copy back the newly set parameters to the writeside.
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_ctrl_DP_T));
      WriteSideDirtyFlag = 0;
    }

    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex >= NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_ctrl_DP_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, value, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
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
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength != (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* If we have pending modified parameters, then copy to write-side */
  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof(P_ctrl_DP_T));
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
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex >= (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, paramvalue, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
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
  *value = NIRT_GetValueByDataType(ptr, subindex, NI_ParamList[index].datatype,
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
      *numDiscStates = 855.0;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_c),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_p),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_p");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_k),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_k");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_n),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_n");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_cd),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_cd");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_h),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_h");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_a),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_a");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_a),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_a");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_a),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_a");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 0,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 1,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 2,
      0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_c),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_c),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_c),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_e),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_g),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_i),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_i");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_l),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_n4),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_n4");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_gj),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_gj");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE, count,
        25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_f, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE_f");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_fu, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE_fu");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states, 0, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states, 1, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.UD_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.UD_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_b, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE_b");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_d, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_h, 0, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_h, 1, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_h");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.UD_DSTATE_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.UD_DSTATE_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_m, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_m");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_n, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE_n");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_no, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE_no");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_j, 0, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_j, 1, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.UD_DSTATE_i, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.UD_DSTATE_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_e, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_i, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_i, 0, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_i, 1, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_i");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.UD_DSTATE_n4, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.UD_DSTATE_n4");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_h0, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_h0");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_j, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_a, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_hb, 0, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_hb");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_hb, 1, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_hb");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.UD_DSTATE_m, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.UD_DSTATE_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_dt, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_dt");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_dv, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE_dv");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_m, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Delay_DSTATE_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_l, 0, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_l, 1, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_l");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.UD_DSTATE_l, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.UD_DSTATE_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_states_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_states_o");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_ref_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_ref_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_ref_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_ref_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.thr_angle_1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.thr_angle_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.thr_angle_2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.thr_angle_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.thr_angle_3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.thr_angle_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.thr_angle_4_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.thr_angle_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.thr_angle_5_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.thr_angle_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.thr_angle_6_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.thr_angle_6_DWORK1");
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_l,
        count, 25, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_l");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.Angle_controller_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.Angle_controller_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_g, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_d, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_e, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_g4, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_g4");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_c, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_a, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_a");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.rpm1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.rpm1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.rpm2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.rpm2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.rpm3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.rpm3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.rpm4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.rpm4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.rpm5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.rpm5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.rpm6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.rpm6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.pwm_2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.pwm_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.pwm_3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.pwm_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.pwm_4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.pwm_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.pwm_5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.pwm_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.pwm_6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.pwm_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.pwm_1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.pwm_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_hat_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_dot_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_dot_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_dot_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_dot_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_x_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_x_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_y_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_y_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_psi_hat_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_psi_hat_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_actual_DWORK1, 0,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_actual_DWORK1, 1,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_actual_DWORK1, 2,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.eta_tilde_DWORK1, 0,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.eta_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.eta_tilde_DWORK1, 1,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.eta_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.eta_tilde_DWORK1, 2,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.eta_tilde_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_ref_out_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_ref_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_ref_out_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_ref_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_ref_out_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_ref_out_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_tmp, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_tmp");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.PrevY, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.PrevY");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_ec, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_ec");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_tmp_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_tmp_a");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Control_test_Pa_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Control_test_Pa_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_tmp_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_tmp_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.PrevY_e, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.PrevY_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput_n,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Memory_PreviousInput_n");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_ln, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_ln");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_tmp_h, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_tmp_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_tmp_e, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_tmp_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.PrevY_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.PrevY_o");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput_d,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Memory_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_lw, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_lw");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_tmp_hh, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_tmp_hh");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_tmp_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_tmp_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.PrevY_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.PrevY_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput_a,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Memory_PreviousInput_a");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_ct, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_ct");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_tmp_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_tmp_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_tmp_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_tmp_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.PrevY_j, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.PrevY_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput_b,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.Memory_PreviousInput_b");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_i, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_tmp_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_tmp_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_tmp_h4, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_tmp_h4");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.PrevY_h, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.PrevY_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.Memory_PreviousInput_a4, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.Memory_PreviousInput_a4");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK1_j, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK1_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_DP_DW.DiscreteTransferFcn_tmp_cw, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_DP_DW.DiscreteTransferFcn_tmp_cw");
    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_p_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_i_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.K_d_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_m_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_m_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_m_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_m_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_m_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.w_d_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_psi_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_x_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.zeta_y_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_ref_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_ref_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_ref_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_ref_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_ref_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_ref_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.thr_angle_1_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.thr_angle_1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.thr_angle_2_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.thr_angle_2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.thr_angle_3_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.thr_angle_3_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.thr_angle_4_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.thr_angle_4_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.thr_angle_5_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.thr_angle_5_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.thr_angle_6_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.thr_angle_6_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_m,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_m");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_DW.Angle_controller_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_DW.Angle_controller_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_1_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_j,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_j");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_o,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_o");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_i,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_i");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_k,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_k");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_a,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_a");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_mm,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_mm");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.rpm1_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.rpm1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.rpm2_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.rpm2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.rpm3_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.rpm3_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.rpm4_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.rpm4_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.rpm5_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.rpm5_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.rpm6_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.rpm6_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.pwm_2_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.pwm_2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.pwm_3_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.pwm_3_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.pwm_4_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.pwm_4_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.pwm_5_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.pwm_5_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_2_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.pwm_6_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.pwm_6_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_3_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_4_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_5_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.alpha_6_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_1_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_4_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_4_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_5_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_5_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_6_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_6_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_2_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_2_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_3_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_3_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.pwm_1_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.pwm_1_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_hat_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_hat_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_hat_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_hat_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_hat_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_hat_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.u_dot_hat_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.u_dot_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.v_dot_hat_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.v_dot_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.r_dot_hat_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.r_dot_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_x_hat_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_x_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_y_hat_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_y_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.b_psi_hat_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.b_psi_hat_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.tau_actual_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.tau_actual_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.eta_tilde_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.eta_tilde_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.x_ref_out_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.x_ref_out_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.y_ref_out_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.y_ref_out_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.psi_ref_out_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.psi_ref_out_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_n,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_n");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_DW.Control_test_Pa_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_DW.Control_test_Pa_DWORK2");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_e,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_e");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_l,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_l");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_mb,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_mb");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_nu,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_nu");
    }

    for (count = 0; count < 8; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_DW.reset_DWORK2_f,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_DW.reset_DWORK2_f");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_DSTATE, 0,
         0, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_DSTATE");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_DW.CoreSubsys[ForEach_itr1].Delay_DSTATE, 0, 0, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_DW.CoreSubsys[ForEach_itr1].Delay_DSTATE");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_PrevRese, 0,
         2, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_PrevRese");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_IC_LOADI, 0,
         3, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_IC_LOADI");
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
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator1_CSTATE_g), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator3_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_c), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_p), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_k), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_n), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_cd), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_h), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_a), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_a), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_a), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 0, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 1, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE), 2, contStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_c), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_c), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator2_CSTATE_c), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_e), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_g), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_i), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_l), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_n4), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_DP_X.Integrator_CSTATE_gj), 0, contStates[idx
      ++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE, count, discStates[idx++],
        25, 0);
    }

    NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_f, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_fu, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states, 0,
      discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states, 1,
      discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.UD_DSTATE, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_b, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_d, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_h, 0,
      discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_h, 1,
      discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.UD_DSTATE_n, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_n, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_no, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_j, 0,
      discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_j, 1,
      discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.UD_DSTATE_i, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_e, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_i, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_i, 0,
      discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_i, 1,
      discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.UD_DSTATE_n4, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_h0, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_j, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_a, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_hb, 0,
      discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_hb, 1,
      discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.UD_DSTATE_m, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_dt, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_dv, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Delay_DSTATE_m, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_l, 0,
      discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_l, 1,
      discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.UD_DSTATE_l, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_states_o, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_m_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_m_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_m_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_ref_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_ref_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_ref_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.thr_angle_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.thr_angle_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.thr_angle_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.thr_angle_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.thr_angle_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.thr_angle_6_DWORK1, 0, discStates[idx++],
      0, 0);
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_l, count, discStates[idx
        ++], 25, 0);
    }

    NIRT_SetValueByDataType(&ctrl_DP_DW.Angle_controller_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_g, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_d, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_e, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_g4, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_c, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_a, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.rpm1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.rpm2_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.rpm3_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.rpm4_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.rpm5_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.rpm6_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.pwm_2_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.pwm_3_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.pwm_4_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.pwm_5_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.pwm_6_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_4_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_5_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_6_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_2_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_3_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.pwm_1_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.v_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.r_hat_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.u_dot_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.v_dot_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.r_dot_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.b_x_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.b_y_hat_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.b_psi_hat_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.tau_actual_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.tau_actual_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.tau_actual_DWORK1, 2, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.eta_tilde_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.eta_tilde_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.eta_tilde_DWORK1, 2, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.x_ref_out_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.y_ref_out_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.psi_ref_out_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_tmp, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.PrevY, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_ec, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_tmp_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Control_test_Pa_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_tmp_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.PrevY_e, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_ln, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_tmp_h, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_tmp_e, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.PrevY_o, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_lw, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_tmp_hh, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_tmp_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.PrevY_c, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_ct, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_tmp_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_tmp_c, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.PrevY_j, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput_b, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_i, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_tmp_f, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_tmp_h4, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.PrevY_h, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.Memory_PreviousInput_a4, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK1_j, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_DW.DiscreteTransferFcn_tmp_cw, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_x_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_y_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_p_psi_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_psi_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_x_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_i_y_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_psi_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_x_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.K_d_y_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_m_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_m_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_m_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_x_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_y_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.w_d_psi_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_psi_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_x_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.zeta_y_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_ref_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_ref_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_ref_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.thr_angle_1_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.thr_angle_2_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.thr_angle_3_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.thr_angle_4_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.thr_angle_5_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.thr_angle_6_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_m, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.Angle_controller_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_1_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_j, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_o, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_i, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_k, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_a, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_mm, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.rpm1_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.rpm2_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.rpm3_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.rpm4_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.rpm5_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.rpm6_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.pwm_2_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.pwm_3_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.pwm_4_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.pwm_5_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_2_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.pwm_6_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_3_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_4_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_5_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.alpha_6_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_1_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_4_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_5_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_6_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_2_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_3_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.pwm_1_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_hat_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_hat_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_hat_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_hat_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.v_hat_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.r_hat_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.u_dot_hat_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.v_dot_hat_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.r_dot_hat_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.b_x_hat_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.b_y_hat_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.b_psi_hat_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.tau_actual_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.eta_tilde_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.x_ref_out_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.y_ref_out_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.psi_ref_out_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_n, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.Control_test_Pa_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_e, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_l, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_mb, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_nu, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 8; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.reset_DWORK2_f, count, discStates[idx
        ++], 24, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.CoreSubsys[ForEach_itr1].
        DiscreteTimeIntegrator_DSTATE, 0, discStates[idx++], 0, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.CoreSubsys[ForEach_itr1].Delay_DSTATE,
        0, discStates[idx++], 0, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.CoreSubsys[ForEach_itr1].
        DiscreteTimeIntegrator_PrevRese, 0, discStates[idx++], 2, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&ctrl_DP_DW.CoreSubsys[ForEach_itr1].
        DiscreteTimeIntegrator_IC_LOADI, 0, discStates[idx++], 3, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_DP
