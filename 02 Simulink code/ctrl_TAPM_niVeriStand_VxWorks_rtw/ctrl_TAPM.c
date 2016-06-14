/*
 * ctrl_TAPM.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_TAPM".
 *
 * Model version              : 1.39
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sun May 15 17:36:42 2016
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
static real_T ctrl_TAPM_eml_xnrm2(int32_T n, const real_T x[18], int32_T ix0);
static real_T ctrl_TAPM_eml_xnrm2_n(int32_T n, const real_T x[6], int32_T ix0);
static void ctrl_TAPM_eml_xaxpy_fy(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[18], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_f(int32_T n, real_T a, const real_T x[18],
  int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_TAPM_eml_xscal(real_T a, real_T x[9], int32_T ix0);
static void ctrl_TAPM_eml_xscal_f(real_T a, real_T x[36], int32_T ix0);
static void ctrl_TAPM_eml_xswap(real_T x[36], int32_T ix0, int32_T iy0);
static void ctrl_TAPM_eml_xswap_h(real_T x[9], int32_T ix0, int32_T iy0);
static void ctrl_TAPM_eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void ctrl_TAPM_eml_xrot(real_T x[36], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static void ctrl_TAPM_eml_xrot_b(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static real_T ctrl_TAPM_eml_xdotc_lv(int32_T n, const real_T x[36], int32_T ix0,
  const real_T y[36], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_fyqk(int32_T n, real_T a, int32_T ix0, real_T y
  [36], int32_T iy0);
static real_T ctrl_TAPM_eml_xdotc_l(int32_T n, const real_T x[9], int32_T ix0,
  const real_T y[9], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_fyq(int32_T n, real_T a, int32_T ix0, real_T y[9],
  int32_T iy0);
static real_T ctrl_TAPM_eml_xdotc(int32_T n, const real_T x[18], int32_T ix0,
  const real_T y[18], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[18],
  int32_T iy0);
static void ctrl_TAPM_eml_xgesvd(const real_T A[18], real_T U[9], real_T S[3],
  real_T V[18]);
static real_T ctrl_TAPM_eml_xnrm2_nc(int32_T n, const real_T x[36], int32_T ix0);
static real_T ctrl_TAPM_eml_xnrm2_ncc(int32_T n, const real_T x[12], int32_T ix0);
static void ctrl_TAPM_eml_xaxpy_fyqkbuz(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[36], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_fyqkbu(int32_T n, real_T a, const real_T x[36],
  int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_TAPM_eml_xscal_fc(real_T a, real_T x[144], int32_T ix0);
static void ctrl_TAPM_eml_xswap_hn(real_T x[144], int32_T ix0, int32_T iy0);
static void ctrl_TAPM_eml_xrot_b5(real_T x[144], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static real_T ctrl_TAPM_eml_xdotc_lvn2(int32_T n, const real_T x[144], int32_T
  ix0, const real_T y[144], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_fyqkbuzf(int32_T n, real_T a, int32_T ix0,
  real_T y[144], int32_T iy0);
static real_T ctrl_TAPM_eml_xdotc_lvn(int32_T n, const real_T x[36], int32_T ix0,
  const real_T y[36], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_fyqkb(int32_T n, real_T a, int32_T ix0, real_T
  y[36], int32_T iy0);
static void ctrl_TAPM_eml_xgesvd_i(const real_T A[36], real_T U[9], real_T S[3],
  real_T V[36]);
static void ctrl_TAPM_cosd(real_T *x);
static void ctrl_TAPM_sind(real_T *x);
static void ctrl_TAPM_cosd_c(real_T *x);
static void ctrl_TAPM_sind_b(real_T *x);

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
  int_T nXc = 31;
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
 *    '<S41>/Actual Force and Torque'
 *    '<S51>/Actual Force and Torque'
 *    '<S61>/Actual Force and Torque'
 *    '<S71>/Actual Force and Torque'
 *    '<S81>/Actual Force and Torque'
 *    '<S91>/Actual Force and Torque'
 */
void ctrl_TAPM_ActualForceandTorque(real_T rtu_n, real_T rtu_Kq, real_T rtu_Kt,
  real_T rtu_Ktr, real_T rtu_Kqr, real_T rtu_Rho, real_T rtu_D, real_T rtu_eps_c,
  real_T rtu_env, B_ActualForceandTorque_ctrl_T_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_0;

  /* MATLAB Function 'Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque': '<S44>:1' */
  /* '<S44>:1:3' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S44>:1:4' */
  /* '<S44>:1:5' */
  /* '<S44>:1:7' */
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

  /* '<S44>:1:8' */
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
 *    '<S45>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S55>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S65>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S75>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S85>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S95>/Core controller: Torque,Power and Combined Torque//Power'
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

  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power': '<S50>:1' */
  /* '<S50>:1:4' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /* '<S50>:1:5' */
  K_TC = (1.0 - lambda_c) * rtu_K_t0r + rtu_K_t0 * lambda_c;

  /* '<S50>:1:6' */
  lambda_c = (1.0 - lambda_c) * rtu_K_q0r + rtu_K_q0 * lambda_c;

  /* '<S50>:1:7' */
  Qcq = lambda_c / K_TC * rtu_D * rtu_Tr;

  /* '<S50>:1:8' */
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

  /* '<S50>:1:9' */
  K_TC = exp(rt_powd_snf(fabs(rtu_p_cc * rtu_n), rtu_r_cc) * -rtu_k_cc);

  /* '<S50>:1:11' */
  localB->Qcc = (1.0 - K_TC) * lambda_c + K_TC * Qcq;
  localB->Qcq = Qcq;
  localB->Qcp = lambda_c;
}

/*
 * Output and update for atomic system:
 *    '<S43>/Supervisor'
 *    '<S53>/Supervisor'
 *    '<S63>/Supervisor'
 *    '<S73>/Supervisor'
 *    '<S83>/Supervisor'
 *    '<S93>/Supervisor'
 */
void ctrl_TAPM_Supervisor(real_T rtu_control, real_T rtu_input, real_T rtu_n,
  B_Supervisor_ctrl_TAPM_T *localB)
{
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Supervisor': '<S48>:1' */
  /* '<S48>:1:2' */
  localB->u = 1.0;
  if (rtu_control == 1.0) {
    /* '<S48>:1:3' */
    if (rtu_input == 1.0) {
      /* '<S48>:1:4' */
      /* '<S48>:1:5' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S48>:1:6' */
      /* '<S48>:1:7' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S48>:1:8' */
      /* '<S48>:1:9' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S48>:1:10' */
      /* '<S48>:1:11' */
      localB->u = 4.0;
    } else {
      /* '<S48>:1:13' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 2.0) {
    /* '<S48>:1:17' */
    if (rtu_input == 1.0) {
      /* '<S48>:1:18' */
      /* '<S48>:1:19' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S48>:1:20' */
      /* '<S48>:1:21' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S48>:1:22' */
      /* '<S48>:1:23' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S48>:1:24' */
      /* '<S48>:1:25' */
      localB->u = 4.0;
    } else {
      /* '<S48>:1:27' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 3.0) {
    /* '<S48>:1:31' */
    if (rtu_input == 1.0) {
      /* '<S48>:1:32' */
      /* '<S48>:1:33' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S48>:1:34' */
      /* '<S48>:1:35' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S48>:1:36' */
      /* '<S48>:1:37' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S48>:1:38' */
      /* '<S48>:1:39' */
      localB->u = 4.0;
    } else {
      /* '<S48>:1:41' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 4.0) {
    /* '<S48>:1:45' */
    if (rtu_input == 1.0) {
      /* '<S48>:1:46' */
      /* '<S48>:1:47' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S48>:1:48' */
      /* '<S48>:1:49' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S48>:1:50' */
      /* '<S48>:1:51' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S48>:1:52' */
      /* '<S48>:1:53' */
      localB->u = 4.0;
    } else {
      /* '<S48>:1:55' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 5.0) {
    /* '<S48>:1:59' */
    if (rtu_input == 1.0) {
      /* '<S48>:1:60' */
      /* '<S48>:1:61' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S48>:1:62' */
      /* '<S48>:1:63' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S48>:1:64' */
      /* '<S48>:1:65' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S48>:1:66' */
      /* '<S48>:1:67' */
      localB->u = 4.0;
    } else {
      /* '<S48>:1:69' */
      localB->u = 5.0;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S53>/MATLAB Function'
 *    '<S63>/MATLAB Function'
 *    '<S73>/MATLAB Function'
 *    '<S83>/MATLAB Function'
 */
void ctrl_TAPM_MATLABFunction(real_T rtu_Td, real_T rtu_K_t0, real_T rtu_K_t0r,
  real_T rtu_rho, real_T rtu_D, real_T rtu_eps_c, real_T rtu_n_r,
  B_MATLABFunction_ctrl_TAPM_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_r_0;
  real_T rtu_Td_0;

  /* MATLAB Function 'Thruster control /Thruster 2/Thruster control/MATLAB Function': '<S57>:1' */
  /* '<S57>:1:5' */
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

  /* '<S57>:1:7' */
  lambda_c = tanh(rtu_eps_c * rtu_Td_0 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S57>:1:8' */
  /* '<S57>:1:10' */
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xnrm2_n(int32_T n, const real_T x[6], int32_T ix0)
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_fy(int32_T n, real_T a, const real_T x[3],
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_f(int32_T n, real_T a, const real_T x[18],
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xscal(real_T a, real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xscal_f(real_T a, real_T x[36], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 5; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xswap_h(real_T x[9], int32_T ix0, int32_T iy0)
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xrot_b(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc_lv(int32_T n, const real_T x[36], int32_T ix0,
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_fyqk(int32_T n, real_T a, int32_T ix0, real_T y
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc_l(int32_T n, const real_T x[9], int32_T ix0,
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_fyq(int32_T n, real_T a, int32_T ix0, real_T y[9],
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
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

  ztest0 = ctrl_TAPM_eml_xnrm2_n(5, e, 2);
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
      ctrl_TAPM_eml_xaxpy_f(2, e[i], b_A, 3 * i + 2, work, 2);
    }

    for (i = 1; i + 1 < 7; i++) {
      ctrl_TAPM_eml_xaxpy_fy(2, -e[i] / e[1], work, 2, b_A, 3 * i + 2);
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

  ztest0 = ctrl_TAPM_eml_xnrm2_n(4, e, 3);
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
      ctrl_TAPM_eml_xaxpy_f(1, e[i], b_A, 3 * i + 3, work, 3);
    }

    for (i = 2; i + 1 < 7; i++) {
      ctrl_TAPM_eml_xaxpy_fy(1, -e[i] / e[2], work, 3, b_A, 3 * i + 3);
    }
  }

  for (i = 2; i + 1 < 7; i++) {
    Vf[i + 6] = e[i];
  }

  for (kase = 3; kase + 1 < 7; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_n(3, e, 4);
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
        ctrl_TAPM_eml_xaxpy_fyq(3 - qs, -(ctrl_TAPM_eml_xdotc_l(3 - qs, U, iter
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
        ctrl_TAPM_eml_xaxpy_fyqk(5 - qs, -(ctrl_TAPM_eml_xdotc_lv(5 - qs, Vf, i,
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
    ctrl_TAPM_eml_xscal_f(ztest0, Vf, 7);
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
    ctrl_TAPM_eml_xscal_f(ztest0, Vf, 13);
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
    ctrl_TAPM_eml_xscal_f(ztest0, Vf, 19);
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
        ctrl_TAPM_eml_xrot_b(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest, b);
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
          ctrl_TAPM_eml_xrot_b(U, 1 + 3 * (kase - 1), 1 + 3 * kase, ztest0,
                               ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_TAPM_eml_xscal_f(-1.0, Vf, 1 + 6 * q);
      }

      i = q + 1;
      while ((q + 1 < 4) && (s[q] < s[i])) {
        ztest = s[q];
        s[q] = s[i];
        s[i] = ztest;
        ctrl_TAPM_eml_xswap(Vf, 1 + 6 * q, 1 + 6 * (q + 1));
        if (q + 1 < 3) {
          ctrl_TAPM_eml_xswap_h(U, 1 + 3 * q, 1 + 3 * (q + 1));
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xnrm2_nc(int32_T n, const real_T x[36], int32_T ix0)
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xnrm2_ncc(int32_T n, const real_T x[12], int32_T ix0)
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_fyqkbuz(int32_T n, real_T a, const real_T x[3],
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_fyqkbu(int32_T n, real_T a, const real_T x[36],
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xscal_fc(real_T a, real_T x[144], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 11; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xswap_hn(real_T x[144], int32_T ix0, int32_T iy0)
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xrot_b5(real_T x[144], int32_T ix0, int32_T iy0,
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc_lvn2(int32_T n, const real_T x[144], int32_T
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_fyqkbuzf(int32_T n, real_T a, int32_T ix0,
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc_lvn(int32_T n, const real_T x[36], int32_T ix0,
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_fyqkb(int32_T n, real_T a, int32_T ix0, real_T
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_eml_xgesvd_i(const real_T A[36], real_T U[9], real_T S[3],
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
  ztest0 = ctrl_TAPM_eml_xnrm2_nc(3, b_A, 1);
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
      ctrl_TAPM_eml_xaxpy_fyqkb(3, -(ctrl_TAPM_eml_xdotc_lvn(3, b_A, 1, b_A,
        qp1jj + 1) / b_A[0]), 1, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 0; qp1 + 1 < 4; qp1++) {
    U[qp1] = b_A[qp1];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_ncc(11, e, 2);
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
      ctrl_TAPM_eml_xaxpy_fyqkbu(2, e[qp1], b_A, 3 * qp1 + 2, work, 2);
    }

    for (qp1 = 1; qp1 + 1 < 13; qp1++) {
      ctrl_TAPM_eml_xaxpy_fyqkbuz(2, -e[qp1] / e[1], work, 2, b_A, 3 * qp1 + 2);
    }
  }

  for (qp1 = 1; qp1 + 1 < 13; qp1++) {
    Vf[qp1] = e[qp1];
  }

  apply_transform = false;
  ztest0 = ctrl_TAPM_eml_xnrm2_nc(2, b_A, 5);
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
      ctrl_TAPM_eml_xaxpy_fyqkb(2, -(ctrl_TAPM_eml_xdotc_lvn(2, b_A, 5, b_A,
        qp1jj + 1) / b_A[4]), 5, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 1; qp1 + 1 < 4; qp1++) {
    U[qp1 + 3] = b_A[qp1 + 3];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_ncc(10, e, 3);
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
      ctrl_TAPM_eml_xaxpy_fyqkbu(1, e[qp1], b_A, 3 * qp1 + 3, work, 3);
    }

    for (qp1 = 2; qp1 + 1 < 13; qp1++) {
      ctrl_TAPM_eml_xaxpy_fyqkbuz(1, -e[qp1] / e[2], work, 3, b_A, 3 * qp1 + 3);
    }
  }

  for (qp1 = 2; qp1 + 1 < 13; qp1++) {
    Vf[qp1 + 12] = e[qp1];
  }

  for (kase = 3; kase + 1 < 13; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_ncc(9, e, 4);
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
        ctrl_TAPM_eml_xaxpy_fyq(3 - qs, -(ctrl_TAPM_eml_xdotc_l(3 - qs, U, iter
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
        ctrl_TAPM_eml_xaxpy_fyqkbuzf(11 - qs, -(ctrl_TAPM_eml_xdotc_lvn2(11 - qs,
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
    ctrl_TAPM_eml_xscal_fc(ztest0, Vf, 13);
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
    ctrl_TAPM_eml_xscal_fc(ztest0, Vf, 25);
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
    ctrl_TAPM_eml_xscal_fc(ztest0, Vf, 37);
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

        ctrl_TAPM_eml_xrot_b5(Vf, 1 + 12 * kase, 1 + 12 * (m + 1), ztest, b);
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
        ctrl_TAPM_eml_xrot_b(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest, b);
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
        ctrl_TAPM_eml_xrot_b5(Vf, 1 + 12 * (kase - 1), 1 + 12 * kase, ztest0,
                              ztest);
        ctrl_TAPM_eml_xrotg(&f, &b, &ztest0, &ztest);
        s[kase - 1] = f;
        f = e[kase - 1] * ztest0 + ztest * s[kase];
        s[kase] = e[kase - 1] * -ztest + ztest0 * s[kase];
        b = ztest * e[kase];
        e[kase] *= ztest0;
        if (kase < 3) {
          ctrl_TAPM_eml_xrot_b(U, 1 + 3 * (kase - 1), 1 + 3 * kase, ztest0,
                               ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_TAPM_eml_xscal_fc(-1.0, Vf, 1 + 12 * q);
      }

      qp1 = q + 1;
      while ((q + 1 < 4) && (s[q] < s[qp1])) {
        ztest = s[q];
        s[q] = s[qp1];
        s[qp1] = ztest;
        ctrl_TAPM_eml_xswap_hn(Vf, 1 + 12 * q, 1 + 12 * (q + 1));
        if (q + 1 < 3) {
          ctrl_TAPM_eml_xswap_h(U, 1 + 3 * q, 1 + 3 * (q + 1));
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_cosd_c(real_T *x)
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

/* Function for MATLAB Function: '<S7>/MATLAB Function' */
static void ctrl_TAPM_sind_b(real_T *x)
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
  real_T rtb_Integrator_g;
  real_T rtb_Integrator_f;
  real_T rtb_Integrator_h;
  real_T rtb_Integrator_a;
  real_T rtb_Integrator_i;
  real_T rtb_Integrator_l;
  real_T rtb_T_r;
  real_T rtb_T_r_c;
  real_T rtb_sys[12];
  real_T rtb_ImpSel_InsertedFor_reset_at;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T pos;
  int32_T res;
  real_T offset;
  static const real_T a[9] = { 0.0072, 0.0, 0.0, 0.0, 0.0072, 0.0, 0.0, -0.0011,
    0.72 };

  static const real_T b_a[18] = { 0.0072, 0.0, 0.0, 0.0, 0.0072, 0.0, 0.0,
    -0.0011, 0.72, 7.33, 0.0, 0.0, 0.0, 7.355, 0.0115, 0.0, 0.0195, 10.6236 };

  real_T R[9];
  int32_T r2;
  int32_T rtemp;
  static const real_T a_0[9] = { 6.4399, 0.0, 0.0, 0.0, 1.7636, 0.0015, 0.0,
    -0.0044, 5.0912 };

  static const real_T b_a_0[18] = { 6.4399, 0.0, 0.0, 0.0, 1.7636, 0.0015, 0.0,
    -0.0044, 5.0912, 41.7347, 0.0, 0.0, 0.0, 24.5829, 0.0663, 0.0, 0.1054,
    28.4457 };

  real_T s[6];
  real_T tc[3];
  real_T T_surge[6];
  real_T S_singular_cross[9];
  real_T T0[12];
  real_T y[18];
  real_T b_U[9];
  real_T b_V[36];
  static const int8_T d[12] = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 };

  static const int8_T e[12] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };

  static const int8_T b_b[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  boolean_T f[9];
  real_T m;
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
  real_T y_0;
  real_T rtb_Row2;
  real_T rtb_Row1;
  real_T rtb_MultiportSwitch[3];
  real_T rtb_y[6];
  real_T rtb_ImpAsg_InsertedFor_Out2_at_[6];
  real_T rtb_Sum_b;
  real_T rtb_TmpSignalConversionAtSFu_hx[6];
  real_T rtb_TmpSignalConversionAtSFun_p[10];
  real_T rtb_Out2_CoreSubsysCanOut;
  real_T rtb_Sum;
  real_T d_0[36];
  real_T T_surge_0[18];
  real_T a_1[3];
  real_T b_a_1[3];
  int32_T i;
  real_T T_surge_1[18];
  real_T pos_0[18];
  real_T tmp[3];
  real_T tmp_0[3];
  real_T tmp_1[3];
  int32_T b_data[9];
  int32_T c_data[9];
  real_T rtb_TmpSignalConversionAtSFu_a0;
  boolean_T f_0;
  real_T rtb_TmpSignalConversionAtSFun_c;
  real_T rtb_TmpSignalConversionAtSFun_0;
  real_T rtb_output_idx_2;
  real_T rtb_output_idx_4;
  real_T rtb_output_idx_6;
  real_T rtb_output_idx_8;
  real_T rtb_output_idx_10;
  real_T rtb_Integrator_idx_0;
  real_T rtb_Integrator_idx_1;
  real_T rtb_bias_idx_0;
  real_T rtb_bias_idx_1;
  real_T rtb_bias_idx_2;
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

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Delay: '<S11>/Delay' */
    ctrl_TAPM_B.Delay = ctrl_TAPM_DW.Delay_DSTATE;
  }

  /* Integrator: '<S12>/Integrator' */
  ctrl_TAPM_B.eta[0] = ctrl_TAPM_X.Integrator_CSTATE[0];
  ctrl_TAPM_B.eta[1] = ctrl_TAPM_X.Integrator_CSTATE[1];
  ctrl_TAPM_B.eta[2] = ctrl_TAPM_X.Integrator_CSTATE[2];

  /* Integrator: '<S12>/Integrator4' */
  ctrl_TAPM_B.nu[0] = ctrl_TAPM_X.Integrator4_CSTATE[0];
  ctrl_TAPM_B.nu[1] = ctrl_TAPM_X.Integrator4_CSTATE[1];
  ctrl_TAPM_B.nu[2] = ctrl_TAPM_X.Integrator4_CSTATE[2];

  /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
   *  SignalConversion: '<S17>/TmpSignal ConversionAt SFunction Inport3'
   */
  /* MATLAB Function 'TAPM Controller w_observer/LQR/MATLAB Function': '<S17>:1' */
  /* '<S17>:1:9' */
  res = 0;

  /* '<S17>:1:11' */
  pos = sqrt(ctrl_TAPM_B.eta[0] * ctrl_TAPM_B.eta[0] + ctrl_TAPM_B.eta[1] *
             ctrl_TAPM_B.eta[1]);
  if ((pos > ctrl_TAPM_B.r_max) && (ctrl_TAPM_DW.controller != 2.0)) {
    /* '<S17>:1:13' */
    /* '<S17>:1:14' */
    ctrl_TAPM_DW.controller = 2.0;

    /* '<S17>:1:15' */
    res = 1;
  } else {
    if ((pos < 0.9 * ctrl_TAPM_B.r_max) && (ctrl_TAPM_B.Delay > 40.0) &&
        (ctrl_TAPM_DW.controller != 1.0) && (ctrl_TAPM_DW.tmp > 190.0)) {
      /* '<S17>:1:16' */
      /* '<S17>:1:17' */
      ctrl_TAPM_DW.controller = 1.0;

      /* '<S17>:1:18' */
      res = 1;
    }
  }

  if (pos > ctrl_TAPM_B.r_max) {
    /* '<S17>:1:21' */
    /* '<S17>:1:22' */
    res = 1;

    /* '<S17>:1:23' */
    ctrl_TAPM_DW.tmp = 0.0;
  } else {
    /* '<S17>:1:25' */
    ctrl_TAPM_DW.tmp += 0.01;
  }

  /* '<S17>:1:28' */
  ctrl_TAPM_B.y_mz = ctrl_TAPM_DW.controller;

  /* '<S17>:1:29' */
  ctrl_TAPM_B.reset_h = res;

  /* End of MATLAB Function: '<S11>/MATLAB Function' */

  /* Integrator: '<S13>/Integrator' */
  rtb_Integrator_idx_0 = ctrl_TAPM_X.Integrator_CSTATE_l[0];
  rtb_Integrator_idx_1 = ctrl_TAPM_X.Integrator_CSTATE_l[1];

  /* MATLAB Function: '<S13>/Set-Point Limiter' incorporates:
   *  Integrator: '<S13>/Integrator'
   *  MATLAB Function: '<S1>/MATLAB Function3'
   *  SignalConversion: '<S10>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Input/MATLAB Function3': '<S10>:1' */
  /* '<S10>:1:4' */
  /* MATLAB Function 'TAPM Controller w_observer/SP Generator/Set-Point Limiter': '<S24>:1' */
  /* '<S24>:1:3' */
  rtb_TmpSignalConversionAtSFun_c = ctrl_TAPM_X.Integrator_CSTATE_l[0] -
    ctrl_TAPM_B.fzp_x;
  rtb_TmpSignalConversionAtSFun_0 = ctrl_TAPM_X.Integrator_CSTATE_l[1] -
    ctrl_TAPM_B.fzp_y;

  /* '<S24>:1:4' */
  pos = 2.2250738585072014E-308;
  rtb_Row1 = fabs(rtb_TmpSignalConversionAtSFun_c);
  if (rtb_Row1 > 2.2250738585072014E-308) {
    offset = 1.0;
    pos = rtb_Row1;
  } else {
    t = rtb_Row1 / 2.2250738585072014E-308;
    offset = t * t;
  }

  rtb_Row1 = fabs(rtb_TmpSignalConversionAtSFun_0);
  if (rtb_Row1 > pos) {
    t = pos / rtb_Row1;
    offset = offset * t * t + 1.0;
    pos = rtb_Row1;
  } else {
    t = rtb_Row1 / pos;
    offset += t * t;
  }

  offset = pos * sqrt(offset);

  /* '<S24>:1:5' */
  /* '<S24>:1:6' */
  /* '<S24>:1:7' */
  pos = rt_powd_snf(offset / ctrl_TAPM_B.r_max, 5.0);
  if (pos > 1.0) {
    /* '<S24>:1:10' */
    /* '<S24>:1:11' */
    pos = 1.0;
  }

  /* '<S24>:1:14' */
  rtb_TmpSignalConversionAtSFun_c = (ctrl_TAPM_B.fzp_x +
    rtb_TmpSignalConversionAtSFun_c) - (rtb_TmpSignalConversionAtSFun_c -
    rtb_TmpSignalConversionAtSFun_c / offset * ctrl_TAPM_B.r_max) * pos;
  rtb_TmpSignalConversionAtSFu_a0 = (ctrl_TAPM_B.fzp_y +
    rtb_TmpSignalConversionAtSFun_0) - (rtb_TmpSignalConversionAtSFun_0 -
    rtb_TmpSignalConversionAtSFun_0 / offset * ctrl_TAPM_B.r_max) * pos;

  /* End of MATLAB Function: '<S13>/Set-Point Limiter' */

  /* TransferFcn: '<S13>/Transfer Fcn2' */
  rtb_Row2 = ctrl_TAPM_P.TransferFcn2_C * ctrl_TAPM_X.TransferFcn2_CSTATE;

  /* Saturate: '<S14>/Saturation' */
  if (rtb_Row2 > ctrl_TAPM_P.Saturation_UpperSat) {
    rtb_Row2 = ctrl_TAPM_P.Saturation_UpperSat;
  } else {
    if (rtb_Row2 < ctrl_TAPM_P.Saturation_LowerSat) {
      rtb_Row2 = ctrl_TAPM_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* Signum: '<S14>/Sign' */
  if (rtb_Row2 < 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = -1.0;
  } else if (rtb_Row2 > 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = 1.0;
  } else if (rtb_Row2 == 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_0 = rtb_Row2;
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  Signum: '<S14>/Sign'
   */
  rtb_Row1 = ctrl_TAPM_P.Gain_Gain * rtb_TmpSignalConversionAtSFun_0;

  /* Sum: '<S14>/Sum1' */
  rtb_Row2 += rtb_Row1;

  /* Math: '<S14>/Math Function' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Row2 = rt_remd_snf(rtb_Row2, ctrl_TAPM_P.Constant_Value);

  /* Sum: '<S14>/Sum' */
  rtb_Sum = rtb_Row2 - rtb_Row1;

  /* Integrator: '<S12>/Integrator3' */
  rtb_bias_idx_0 = ctrl_TAPM_X.Integrator3_CSTATE[0];
  rtb_bias_idx_1 = ctrl_TAPM_X.Integrator3_CSTATE[1];
  rtb_bias_idx_2 = ctrl_TAPM_X.Integrator3_CSTATE[2];

  /* SignalConversion: '<S20>/TmpSignal ConversionAt SFunction Inport2' incorporates:
   *  MATLAB Function: '<S11>/MATLAB Function3'
   */
  /* MATLAB Function 'TAPM Controller w_observer/LQR/MATLAB Function1': '<S18>:1' */
  /* '<S18>:1:17' */
  rtb_TmpSignalConversionAtSFu_hx[0] = ctrl_TAPM_B.eta[0];
  rtb_TmpSignalConversionAtSFu_hx[1] = ctrl_TAPM_B.eta[1];
  rtb_TmpSignalConversionAtSFu_hx[2] = ctrl_TAPM_B.eta[2];
  rtb_TmpSignalConversionAtSFu_hx[3] = ctrl_TAPM_B.nu[0];
  rtb_TmpSignalConversionAtSFu_hx[4] = ctrl_TAPM_B.nu[1];
  rtb_TmpSignalConversionAtSFu_hx[5] = ctrl_TAPM_B.nu[2];

  /* MATLAB Function: '<S11>/MATLAB Function3' incorporates:
   *  Integrator: '<S12>/Integrator3'
   *  SignalConversion: '<S20>/TmpSignal ConversionAt SFunction Inport2'
   */
  /* MATLAB Function 'TAPM Controller w_observer/LQR/MATLAB Function3': '<S20>:1' */
  /* '<S20>:1:11' */
  /* '<S20>:1:13' */
  R[0] = cos(ctrl_TAPM_B.eta[2]);
  R[3] = -sin(ctrl_TAPM_B.eta[2]);
  R[6] = 0.0;
  R[1] = sin(ctrl_TAPM_B.eta[2]);
  R[4] = cos(ctrl_TAPM_B.eta[2]);
  R[7] = 0.0;
  R[2] = 0.0;
  R[5] = 0.0;
  R[8] = 1.0;

  /* '<S20>:1:17' */
  res = 0;
  r2 = 1;
  rtemp = 2;
  if (fabs(R[1]) > fabs(R[0])) {
    res = 1;
    r2 = 0;
  }

  R[r2] /= R[res];
  R[2] = 0.0 / R[res];
  R[3 + r2] -= R[3 + res] * R[r2];
  R[5] = 0.0 - R[3 + res] * R[2];
  R[6 + r2] = 0.0 - R[r2] * 0.0;
  R[8] = 1.0 - R[6 + res] * R[2];
  if (fabs(R[5]) > fabs(R[3 + r2])) {
    rtemp = r2;
    r2 = 2;
  }

  R[3 + rtemp] /= R[3 + r2];
  R[6 + rtemp] -= R[3 + rtemp] * R[6 + r2];
  tc[1] = ctrl_TAPM_X.Integrator3_CSTATE[r2] -
    ctrl_TAPM_X.Integrator3_CSTATE[res] * R[r2];
  tc[2] = (ctrl_TAPM_X.Integrator3_CSTATE[rtemp] -
           ctrl_TAPM_X.Integrator3_CSTATE[res] * R[rtemp]) - R[3 + rtemp] * tc[1];
  tc[2] /= R[6 + rtemp];
  tc[0] = ctrl_TAPM_X.Integrator3_CSTATE[res] - R[6 + res] * tc[2];
  tc[1] -= R[6 + r2] * tc[2];
  tc[1] /= R[3 + r2];
  tc[0] -= R[3 + res] * tc[1];
  tc[0] /= R[res];

  /* MultiPortSwitch: '<S11>/Multiport Switch' incorporates:
   *  MATLAB Function: '<S11>/MATLAB Function1'
   *  MATLAB Function: '<S11>/MATLAB Function3'
   */
  if ((int32_T)ctrl_TAPM_B.y_mz == 1) {
    /* SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport2' incorporates:
     *  MATLAB Function: '<S11>/MATLAB Function1'
     */
    rtb_y[0] = ctrl_TAPM_B.eta[0];
    rtb_y[1] = ctrl_TAPM_B.eta[1];
    rtb_y[2] = ctrl_TAPM_B.eta[2];
    rtb_y[3] = ctrl_TAPM_B.nu[0];
    rtb_y[4] = ctrl_TAPM_B.nu[1];
    rtb_y[5] = ctrl_TAPM_B.nu[2];

    /* MATLAB Function: '<S11>/MATLAB Function1' incorporates:
     *  SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport1'
     *  SignalConversion: '<S18>/TmpSignal ConversionAt SFunction Inport2'
     */
    for (i = 0; i < 3; i++) {
      a_1[i] = a[i + 6] * rtb_Sum + (a[i + 3] * rtb_TmpSignalConversionAtSFu_a0
        + a[i] * rtb_TmpSignalConversionAtSFun_c);
    }

    for (i = 0; i < 3; i++) {
      b_a_1[i] = 0.0;
      for (rtemp = 0; rtemp < 6; rtemp++) {
        b_a_1[i] += b_a[3 * rtemp + i] * rtb_y[rtemp];
      }
    }

    rtb_MultiportSwitch[0] = a_1[0] - b_a_1[0];
    rtb_MultiportSwitch[1] = a_1[1] - b_a_1[1];
    rtb_MultiportSwitch[2] = a_1[2] - b_a_1[2];
  } else {
    /* MATLAB Function: '<S11>/MATLAB Function3' incorporates:
     *  SignalConversion: '<S20>/TmpSignal ConversionAt SFunction Inport1'
     */
    for (i = 0; i < 3; i++) {
      a_1[i] = a_0[i + 6] * rtb_Sum + (a_0[i + 3] *
        rtb_TmpSignalConversionAtSFu_a0 + a_0[i] *
        rtb_TmpSignalConversionAtSFun_c);
    }

    for (i = 0; i < 3; i++) {
      b_a_1[i] = 0.0;
      for (rtemp = 0; rtemp < 6; rtemp++) {
        b_a_1[i] += b_a_0[3 * rtemp + i] * rtb_TmpSignalConversionAtSFu_hx[rtemp];
      }
    }

    rtb_MultiportSwitch[0] = (a_1[0] - b_a_1[0]) - tc[0];
    rtb_MultiportSwitch[1] = (a_1[1] - b_a_1[1]) - tc[1];
    rtb_MultiportSwitch[2] = (a_1[2] - b_a_1[2]) - tc[2];
  }

  /* End of MultiPortSwitch: '<S11>/Multiport Switch' */

  /* MATLAB Function: '<S11>/MATLAB Function2' */
  /* MATLAB Function 'TAPM Controller w_observer/LQR/MATLAB Function2': '<S19>:1' */
  if (rtb_MultiportSwitch[0] < 0.0) {
    /* '<S19>:1:4' */
    /* '<S19>:1:5' */
    pos = 0.0;
  } else {
    /* '<S19>:1:7' */
    pos = rtb_MultiportSwitch[0];
  }

  /* '<S19>:1:12' */
  ctrl_TAPM_B.y[0] = pos;
  ctrl_TAPM_B.y[1] = rtb_MultiportSwitch[1];
  ctrl_TAPM_B.y[2] = rtb_MultiportSwitch[2];

  /* End of MATLAB Function: '<S11>/MATLAB Function2' */

  /* SignalConversion: '<S27>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S7>/MATLAB Function1'
   */
  rtb_TmpSignalConversionAtSFu_hx[0] = ctrl_TAPM_B.thr_angle_1;
  rtb_TmpSignalConversionAtSFu_hx[1] = ctrl_TAPM_B.thr_angle_2;
  rtb_TmpSignalConversionAtSFu_hx[2] = ctrl_TAPM_B.thr_angle_3;
  rtb_TmpSignalConversionAtSFu_hx[3] = ctrl_TAPM_B.thr_angle_4;
  rtb_TmpSignalConversionAtSFu_hx[4] = ctrl_TAPM_B.thr_angle_5;
  rtb_TmpSignalConversionAtSFu_hx[5] = ctrl_TAPM_B.thr_angle_6;

  /* MATLAB Function: '<S7>/MATLAB Function1' */
  /* MATLAB Function 'Thrust allocation1/MATLAB Function1': '<S27>:1' */
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
  /* '<S27>:1:39' */
  /* '<S27>:1:40' */
  /*  s = sign(angle); */
  /* '<S27>:1:43' */
  for (rtemp = 0; rtemp < 6; rtemp++) {
    rtb_output_idx_2 = rt_remd_snf(rtb_TmpSignalConversionAtSFu_hx[rtemp] +
      3.1415926535897931, 6.2831853071795862) / 6.2831853071795862;
    rtb_TmpSignalConversionAtSFun_0 = fabs(rtb_output_idx_2);
    if (rtb_TmpSignalConversionAtSFun_0 > 0.0) {
      rtb_TmpSignalConversionAtSFun_0 = 1.0;
    } else {
      if (rtb_TmpSignalConversionAtSFun_0 == 0.0) {
        rtb_TmpSignalConversionAtSFun_0 = 0.0;
      }
    }

    if (rtb_TmpSignalConversionAtSFu_hx[rtemp] < 0.0) {
      rtb_output_idx_4 = -1.0;
    } else if (rtb_TmpSignalConversionAtSFu_hx[rtemp] > 0.0) {
      rtb_output_idx_4 = 1.0;
    } else if (rtb_TmpSignalConversionAtSFu_hx[rtemp] == 0.0) {
      rtb_output_idx_4 = 0.0;
    } else {
      rtb_output_idx_4 = rtb_TmpSignalConversionAtSFu_hx[rtemp];
    }

    s_0 = (rtb_TmpSignalConversionAtSFun_0 - 1.0) * 2.0 + rtb_output_idx_4;
    if (s_0 < 0.0) {
      s_0 = -1.0;
    } else if (s_0 > 0.0) {
      s_0 = 1.0;
    } else {
      if (s_0 == 0.0) {
        s_0 = 0.0;
      }
    }

    if (rtb_TmpSignalConversionAtSFu_hx[rtemp] < 0.0) {
      rtb_output_idx_4 = -1.0;
    } else if (rtb_TmpSignalConversionAtSFu_hx[rtemp] > 0.0) {
      rtb_output_idx_4 = 1.0;
    } else if (rtb_TmpSignalConversionAtSFu_hx[rtemp] == 0.0) {
      rtb_output_idx_4 = 0.0;
    } else {
      rtb_output_idx_4 = rtb_TmpSignalConversionAtSFu_hx[rtemp];
    }

    rtb_y[rtemp] = rt_remd_snf(rtb_output_idx_4 * 3.1415926535897931 +
      rtb_TmpSignalConversionAtSFu_hx[rtemp], 6.2831853071795862) - s_0 *
      3.1415926535897931;
    rtb_TmpSignalConversionAtSFu_hx[rtemp] = rtb_output_idx_2;
  }

  /* SignalConversion: '<S26>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Gain: '<S28>/Gain'
   *  MATLAB Function: '<S7>/MATLAB Function'
   */
  rtb_TmpSignalConversionAtSFun_p[0] = ctrl_TAPM_B.y[0];
  rtb_TmpSignalConversionAtSFun_p[1] = ctrl_TAPM_B.y[1];
  rtb_TmpSignalConversionAtSFun_p[2] = ctrl_TAPM_B.y[2];
  for (rtemp = 0; rtemp < 6; rtemp++) {
    rtb_TmpSignalConversionAtSFun_p[rtemp + 3] = ctrl_TAPM_P.Gain_Gain_o *
      rtb_y[rtemp];
  }

  /* End of SignalConversion: '<S26>/TmpSignal ConversionAt SFunction Inport1' */

  /* MATLAB Function: '<S7>/MATLAB Function' incorporates:
   *  Constant: '<S7>/X-position Thruster'
   *  Constant: '<S7>/Y-position Thruster'
   */
  /* MATLAB Function 'Thrust allocation1/MATLAB Function': '<S26>:1' */
  /*  Complete system goes here! */
  /*  ThrusterPosX = [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)];%[x(1),x(2),x(3),x(4),x(5),x(6)]'; */
  /*  ThrusterPosY = [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)];%[x(7),x(8),x(9),x(10),x(11),x(12)]'; */
  /*  Parameters thrusters */
  /* '<S26>:1:7' */
  tc[0] = rtb_TmpSignalConversionAtSFun_p[0];
  tc[1] = rtb_TmpSignalConversionAtSFun_p[1];
  tc[2] = rtb_TmpSignalConversionAtSFun_p[2];

  /* '<S26>:1:8' */
  rtb_TmpSignalConversionAtSFu_hx[0] = rtb_TmpSignalConversionAtSFun_p[3];
  rtb_TmpSignalConversionAtSFu_hx[1] = rtb_TmpSignalConversionAtSFun_p[4];
  rtb_TmpSignalConversionAtSFu_hx[2] = rtb_TmpSignalConversionAtSFun_p[5];
  rtb_TmpSignalConversionAtSFu_hx[3] = rtb_TmpSignalConversionAtSFun_p[6];
  rtb_TmpSignalConversionAtSFu_hx[4] = rtb_TmpSignalConversionAtSFun_p[7];
  rtb_TmpSignalConversionAtSFu_hx[5] = rtb_TmpSignalConversionAtSFun_p[8];

  /* alpha0 = [x(1),x(2),x(3),x(4),x(5),x(6)]'; */
  /*  Constraints for Thruster-Thruster interaction. Can be seen in "Initfile" */
  /*  how they are found */
  /*   */
  /*  % Ok 12.05/16 */
  /*  if (alpha(1) < C1(1)-0.1  && alpha(1) > C1(2)+0.1) || (alpha(1) > C1(3)+0.1 && alpha(1) < C1(4)-0.1) */
  /*      K(1) = 0; */
  /*  else  */
  /*      K(1) = K(1); */
  /*  end */
  /*  % OK 12.05/16 */
  /*  if (alpha(2) < C2(1)-0.1  && alpha(2) > C2(2)+0.1) || (alpha(2) < C2(3)-0.1 && alpha(2) > C2(4)+0.1) */
  /*      K(2) = 0; */
  /*  else  */
  /*      K(2) = K(2); */
  /*  end */
  /*  % OK 12.05/16 */
  /*  if (alpha(3) > C3(1)+0.1  && alpha(3) < C3(2)-0.1) || (alpha(3) > C3(3)+0.1 && alpha(3) < C3(4)-0.1) */
  /*      K(3) = 0; */
  /*  else  */
  /*      K(3) = K(3); */
  /*  end */
  /*  % OK 12.05/16 */
  /*  if (alpha(4) > C4(1)+0.1  && alpha(4) < C4(2)-0.1) || (alpha(4) < C4(3)- 0.1 && alpha(4) > C4(4)+0.1) */
  /*      K(4) = 0; */
  /*  else  */
  /*      K(4) = K(4); */
  /*  end */
  /*  % OK 12.05/16 */
  /*  if (alpha(5) > C5(1)+0.1  && alpha(5) < C5(2)-0.1) || (alpha(5) > C5(3)+0.1 && alpha(5) < C5(4)-0.1) */
  /*      K(5) = 0; */
  /*  else  */
  /*      K(5) = K(5); */
  /*  end */
  /*  % OK 12.05/16 */
  /*  if (alpha(6) < C6(1)-0.1  && alpha(6) > C6(2)+0.1) || (alpha(6) < C6(3)-0.1 && alpha(6) > C6(4)+0.1) */
  /*      K(6) = 0; */
  /*  else  */
  /*      K(6) = K(6); */
  /*  end */
  /*   */
  /*  K = [K(1) K(2) K(3) K(4) K(5) K(6)]; */
  /*  number of thrusters */
  /* '<S26>:1:63' */
  /*  Shells for faster computing */
  /* '<S26>:1:64' */
  /*  Shells for faster computing */
  /* '<S26>:1:65' */
  /*  Shells for faster computing */
  /* '<S26>:1:67' */
  for (res = 0; res < 6; res++) {
    /* '<S26>:1:67' */
    /* '<S26>:1:68' */
    T_surge[res] = rtb_TmpSignalConversionAtSFu_hx[res];
    ctrl_TAPM_cosd_c(&T_surge[res]);

    /* Thrust in x-direction for cartesian */
    /* '<S26>:1:69' */
    rtb_y[res] = rtb_TmpSignalConversionAtSFu_hx[res];
    ctrl_TAPM_sind_b(&rtb_y[res]);

    /* Thrust in y-direction for cartesian */
    /* '<S26>:1:70' */
    rtb_TmpSignalConversionAtSFun_0 = rtb_TmpSignalConversionAtSFu_hx[res];
    ctrl_TAPM_sind_b(&rtb_TmpSignalConversionAtSFun_0);
    rtb_output_idx_2 = rtb_TmpSignalConversionAtSFu_hx[res];
    ctrl_TAPM_cosd_c(&rtb_output_idx_2);
    s[res] = rtb_TmpSignalConversionAtSFun_0 *
      ctrl_TAPM_P.XpositionThruster_Value[res] - rtb_output_idx_2 *
      ctrl_TAPM_P.YpositionThruster_Value[res];

    /* '<S26>:1:67' */
  }

  /* '<S26>:1:74' */
  /* '<S26>:1:75' */
  for (i = 0; i < 6; i++) {
    T_surge_1[3 * i] = T_surge[i];
  }

  for (i = 0; i < 6; i++) {
    T_surge_1[1 + 3 * i] = rtb_y[i];
  }

  for (i = 0; i < 6; i++) {
    T_surge_1[2 + 3 * i] = s[i];
  }

  for (i = 0; i < 3; i++) {
    for (rtemp = 0; rtemp < 6; rtemp++) {
      T_surge_0[i + 3 * rtemp] = 0.0;
      for (r2 = 0; r2 < 6; r2++) {
        T_surge_0[i + 3 * rtemp] += T_surge_1[3 * r2 + i] * (real_T)b_b[6 *
          rtemp + r2];
      }
    }
  }

  ctrl_TAPM_eml_xgesvd(T_surge_0, R, rtb_MultiportSwitch, T_surge_1);
  memset(&S_singular_cross[0], 0, 9U * sizeof(real_T));
  S_singular_cross[0] = rtb_MultiportSwitch[0];
  S_singular_cross[4] = rtb_MultiportSwitch[1];
  S_singular_cross[8] = rtb_MultiportSwitch[2];

  /* '<S26>:1:77' */
  /* '<S26>:1:78' */
  res = 0;
  for (i = 0; i < 9; i++) {
    rtb_TmpSignalConversionAtSFun_0 = 1.0 / S_singular_cross[i];
    f_0 = !((!rtIsInf(rtb_TmpSignalConversionAtSFun_0)) && (!rtIsNaN
             (rtb_TmpSignalConversionAtSFun_0)));
    if (f_0) {
      res++;
    }

    f[i] = f_0;
    S_singular_cross[i] = rtb_TmpSignalConversionAtSFun_0;
  }

  rtemp = res;
  res = 0;
  for (r2 = 0; r2 < 9; r2++) {
    if (f[r2]) {
      b_data[res] = r2 + 1;
      res++;
    }
  }

  /* '<S26>:1:78' */
  for (i = 0; i < rtemp; i++) {
    S_singular_cross[b_data[i] - 1] = 0.0;
  }

  if (S_singular_cross[8] > 2.0 * S_singular_cross[4]) {
    /* '<S26>:1:79' */
    /* '<S26>:1:80' */
    S_singular_cross[8] = 0.0;
  }

  /* '<S26>:1:83' */
  for (i = 0; i < 6; i++) {
    for (rtemp = 0; rtemp < 3; rtemp++) {
      y[i + 6 * rtemp] = 0.0;
      y[i + 6 * rtemp] += S_singular_cross[3 * rtemp] * T_surge_1[i];
      y[i + 6 * rtemp] += S_singular_cross[3 * rtemp + 1] * T_surge_1[i + 6];
      y[i + 6 * rtemp] += S_singular_cross[3 * rtemp + 2] * T_surge_1[i + 12];
    }
  }

  /* '<S26>:1:84' */
  /*  Optimized Thrust */
  /* '<S26>:1:89' */
  for (i = 0; i < 12; i++) {
    d_0[3 * i] = d[i];
  }

  for (i = 0; i < 12; i++) {
    d_0[1 + 3 * i] = e[i];
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
  ctrl_TAPM_eml_xgesvd_i(d_0, b_U, rtb_MultiportSwitch, b_V);
  memset(&S_singular_cross[0], 0, 9U * sizeof(real_T));
  S_singular_cross[0] = rtb_MultiportSwitch[0];
  S_singular_cross[4] = rtb_MultiportSwitch[1];
  S_singular_cross[8] = rtb_MultiportSwitch[2];

  /* '<S26>:1:95' */
  /* '<S26>:1:96' */
  res = 0;
  for (i = 0; i < 9; i++) {
    rtb_TmpSignalConversionAtSFun_0 = 1.0 / S_singular_cross[i];
    f_0 = !((!rtIsInf(rtb_TmpSignalConversionAtSFun_0)) && (!rtIsNaN
             (rtb_TmpSignalConversionAtSFun_0)));
    if (f_0) {
      res++;
    }

    f[i] = f_0;
    S_singular_cross[i] = rtb_TmpSignalConversionAtSFun_0;
  }

  rtemp = res;
  res = 0;
  for (r2 = 0; r2 < 9; r2++) {
    if (f[r2]) {
      c_data[res] = r2 + 1;
      res++;
    }
  }

  /* '<S26>:1:96' */
  for (i = 0; i < rtemp; i++) {
    S_singular_cross[c_data[i] - 1] = 0.0;
  }

  if (S_singular_cross[8] > 2.0 * S_singular_cross[4]) {
    /* '<S26>:1:97' */
    /* '<S26>:1:98' */
    S_singular_cross[8] = 0.0;
  }

  /* '<S26>:1:100' */
  for (i = 0; i < 12; i++) {
    for (rtemp = 0; rtemp < 3; rtemp++) {
      d_0[i + 12 * rtemp] = 0.0;
      d_0[i + 12 * rtemp] += S_singular_cross[3 * rtemp] * b_V[i];
      d_0[i + 12 * rtemp] += S_singular_cross[3 * rtemp + 1] * b_V[i + 12];
      d_0[i + 12 * rtemp] += S_singular_cross[3 * rtemp + 2] * b_V[i + 24];
    }
  }

  for (i = 0; i < 12; i++) {
    for (rtemp = 0; rtemp < 3; rtemp++) {
      b_V[i + 12 * rtemp] = 0.0;
      b_V[i + 12 * rtemp] += d_0[i] * b_U[rtemp];
      b_V[i + 12 * rtemp] += d_0[i + 12] * b_U[rtemp + 3];
      b_V[i + 12 * rtemp] += d_0[i + 24] * b_U[rtemp + 6];
    }
  }

  for (i = 0; i < 12; i++) {
    T0[i] = b_V[i + 24] * tc[2] + (b_V[i + 12] * tc[1] + b_V[i] * tc[0]);
  }

  /* '<S26>:1:102' */
  /* alpha1 = [ 180 -90 90 0 25 -25]; */
  /*  for i=1:1:n_t */
  /*    if alpha1(i) > 180 */
  /*        alpha1(i) = alpha1(i) - 360; */
  /*    elseif alpha1(i) < -180 */
  /*        alpha1(i) = alpha1(i) + 360; */
  /*    else */
  /*        alpha1(i) = alpha(i); */
  /*    end */
  /*  end */
  /* alpha1 = [180 -90 90 atan2d(T0(8),T0(7)) 0 0]; */
  /* % Constraints */
  /*  % Thruster 1 OK 13.05/16 */
  /*  % %C1 = [49.7 29.4 -151 -130 ]; */
  /*   */
  /*  if (alpha1(1) < C1(1)  && alpha1(1) > C1(2)) %&& T_d(1) > 0) || (alpha1(1) < C1(1)  && alpha1(1) > C1(2) && T_d(1) < 0) */
  /*      c1 = [C1(1) C1(2)]; */
  /*      [C_1,alpha_new1] = min(abs(c1-alpha1(1))); */
  /*      Alpha1(1) = c1(alpha_new1); */
  /*  elseif (alpha1(1) > C1(3) && alpha1(1) < C1(4) && T_d(1) > 0) || (alpha1(1) > C1(3) && alpha1(1) < C1(4) && T_d(1) < 0) */
  /*      c1 = [C1(3) C1(4)]; */
  /*      [C_1,alpha_new1] = min(abs(c1-alpha1(1))); */
  /*      Alpha1(1) = c1(alpha_new1); */
  /*  else  */
  /*      Alpha1(1) = alpha1(1); */
  /*  end */
  /*  if alpha(1) < C1(1)-0.1  && alpha(1) > C1(2)+0.1 || alpha(1) > C1(3)+0.1 && alpha(1) < C1(4)-0.1 */
  /*      T_d(1) = 0; */
  /*  else  */
  /*      T_d(1) = T_d(1); */
  /*  end */
  /*    */
  /*  %% Thruster 2 OK 13.05/16 */
  /*  %C2 = [99.85 80.15 50 29]; */
  /*  if (alpha1(2) < C2(1)  && alpha1(2) > C2(2) && T_d(2) > 0) || (alpha1(2) < C2(1)  && alpha1(2) > C2(2) && T_d(2) < 0)  */
  /*      c2 = [C2(1) C2(2)]; */
  /*      [C_2,alpha_new2] = min(abs(c2-alpha1(2))); */
  /*      Alpha1(2) = c2(alpha_new2); */
  /*  elseif (alpha1(2) < C2(3) && alpha1(2) > C2(4) && T_d(2) > 0) || (alpha1(2) < C2(3) && alpha1(2) > C2(4) && T_d(2) < 0) */
  /*      c2 = [C2(3) C2(4)]; */
  /*      [C_2,alpha_new2] = min(abs(c2-alpha1(2))); */
  /*      Alpha1(2) = c2(alpha_new2); */
  /*  else  */
  /*      Alpha1(2) = alpha1(2); */
  /*  end */
  /*  if (alpha(2) < C2(1)-0.1  && alpha(2) > C2(2)+0.1) || (alpha(2) < C2(3)-0.1 && alpha(2) > C2(4)+0.1) */
  /*      T_d(2) = 0; */
  /*  else  */
  /*      T_d(2) = T_d(2); */
  /*  end */
  /*   */
  /*  %% Thruster 3 OK 13.05/16 */
  /*  % C3 = [-99.85 -80.15 -50 -29];  */
  /*   */
  /*  if (alpha1(3) > C3(1)  && alpha1(3) < C3(2) && T_d(3) > 0) || (alpha1(3) > C3(1)  && alpha1(3) < C3(2) && T_d(3) < 0) */
  /*      c3 = [C3(1) C3(2)]; */
  /*      [C_3,alpha_new3] = min(abs(c3-alpha1(3))); */
  /*      Alpha1(3) = c3(alpha_new3); */
  /*  elseif (alpha1(3) > C3(3) && alpha1(3) < C3(4) && T_d(3) > 0) || (alpha1(3) > C3(3) && alpha1(3) < C3(4) && T_d(3) < 0)  */
  /*      c3 = [C3(3) C3(4)]; */
  /*      [C_3,alpha_new3] = min(abs(c3-alpha1(3))); */
  /*      Alpha1(3) = c3(alpha_new3); */
  /*  else  */
  /*      Alpha1(3) = alpha1(3); */
  /*  end */
  /*  if (alpha(3) > C3(1) + 0.1  && alpha(3) < C3(2) - 0.1) || (alpha(3) > C3(3) + 0.1 && alpha(3) < C3(4) - 0.1) */
  /*      T_d(3) = 0; */
  /*  else  */
  /*      T_d(3) = T_d(3); */
  /*  end */
  /*   */
  /*  %% Thruster 4 OK 13.05/16 */
  /*  %C4 = [-52.8 -34.2 52.8 34.2];  */
  /*  if (alpha1(4) > C4(1)  && alpha1(4) < C4(2) && T_d(4) > 0) || (alpha1(4) > C4(1)  && alpha1(4) < C4(2) && T_d(4) < 0) */
  /*      c4 = [C4(1) C4(2)]; */
  /*      [C_4,alpha_new4] = min(abs(c4-alpha1(4))); */
  /*      Alpha1(4) = c4(alpha_new4); */
  /*  elseif (alpha1(4) < C4(3) && alpha1(4) > C4(4) && T_d(4) > 0) || (alpha1(4) < C4(3) && alpha1(4) > C4(4) && T_d(4) < 0)  */
  /*      c4 = [C4(3) C4(4)]; */
  /*      [C_4,alpha_new4] = min(abs(c4-alpha1(4))); */
  /*      Alpha1(4) = c4(alpha_new4); */
  /*  else  */
  /*      Alpha1(4) = alpha1(4); */
  /*  end */
  /*  if (alpha(4) > C4(1)+0.1  && alpha(4) < C4(2)-0.1) || (alpha(4) < C4(3)-0.1 && alpha(4) > C4(4)+0.1) */
  /*      T_d(4) = 0; */
  /*  else  */
  /*      T_d(4) = T_d(4); */
  /*  end */
  /*   */
  /*  %% Thruster 5 OK 13.05/16 */
  /*  %C5 = [-98.25 -81.75 -145.8 -127.2]; */
  /*  if (alpha1(5) > C5(1)  && alpha1(5) < C5(2) && T_d(5) > 0) || (alpha1(5) > C5(1)  && alpha1(5) < C5(2) && T_d(5) < 0) */
  /*      c5 = [C5(1) C5(2)]; */
  /*      [C_5,alpha_new5] = min(abs(c5-alpha1(5))); */
  /*      Alpha1(5) = c5(alpha_new5); */
  /*  elseif (alpha1(5) > C5(3) && alpha1(5) < C5(4) && T_d(5) > 0)  || (alpha1(5) > C5(3) && alpha1(5) < C5(4) && T_d(5) < 0) */
  /*      c5 = [C5(3) C5(4)]; */
  /*      [C_5,alpha_new5] = min(abs(c5-alpha1(5))); */
  /*      Alpha1(5) = c5(alpha_new5); */
  /*  else  */
  /*      Alpha1(5) = alpha1(5); */
  /*  end */
  /*  if (alpha(5) > C5(1)+0.1  && alpha(5) < C5(2)-0.1) || (alpha(5) > C5(3)+0.1 && alpha(5) < C5(4)-0.1) */
  /*      T_d(5) = 0; */
  /*  else  */
  /*      T_d(5) = T_d(5); */
  /*  end */
  /*   */
  /*  %% Thruster 6 OK 13.05/16 */
  /*  %C6 = [98.75 81.75 145.8 127.2]; */
  /*  if (alpha1(6) < C6(1)  && alpha1(6) > C6(2) && T_d(6) > 0) || (alpha1(6) < C6(1)  && alpha1(6) > C6(2) && T_d(6) < 0) */
  /*      c6 = [C6(1) C6(2)]; */
  /*      [C_6,alpha_new6] = min(abs(c6-alpha1(6))); */
  /*      Alpha1(6) = c6(alpha_new6); */
  /*  elseif (alpha1(6) < C6(3) && alpha1(6) > C6(4) && T_d(6) > 0) || (alpha1(6) < C6(3) && alpha1(6) > C6(4) && T_d(6) < 0) */
  /*      c6 = [C6(3) C6(4)]; */
  /*      [C_6,alpha_new6] = min(abs(c6-alpha1(6))); */
  /*      Alpha1(6) = c6(alpha_new6); */
  /*  else  */
  /*      Alpha1(6) = alpha1(6); */
  /*  end */
  /*  if (alpha(6) < C6(1)-0.1  && alpha(6) > C6(2)+0.1) || (alpha(6) < C6(3)-0.1 && alpha(6) > C6(4)+0.1) */
  /*      T_d(6) = 0; */
  /*  else  */
  /*      T_d(6) = T_d(6); */
  /*  end */
  /*   */
  /*  % Thruster 2&3  */
  /*  if Alpha1(2) == C2(2) */
  /*      Alpha1(3) = alpha1(2) - (C2(2) - alpha1(2)); */
  /*  elseif Alpha1(2) == C2(1) */
  /*      Alpha1(3) = alpha1(2) - (C2(1) - alpha1(2)); */
  /*  elseif Alpha1(2) == C2(3) */
  /*      Alpha1(3) = alpha1(2) - (C2(3) - alpha1(2)); */
  /*  elseif Alpha1(2) == C2(4) */
  /*      Alpha1(3) = alpha1(2) - (C2(4) - alpha1(2)); */
  /*       */
  /*  elseif Alpha1(3) == C3(2) */
  /*      Alpha1(2) = alpha1(3) - (C3(2) - alpha1(3)); */
  /*  elseif Alpha1(3) == C3(1) */
  /*      Alpha1(2) = alpha1(3) - (C3(1) - alpha1(3)); */
  /*  elseif Alpha1(3) == C3(3) */
  /*      Alpha1(2) = alpha1(3) - (C3(3) - alpha1(3)); */
  /*  elseif Alpha1(3) == C3(4) */
  /*      Alpha1(2) = alpha1(3) - (C3(4) - alpha1(3)); */
  /*  end */
  /*   */
  /*  % Thruster 5&6 */
  /*  if Alpha1(5) == C5(2) */
  /*      Alpha1(6) = alpha1(5) - (C5(2) - alpha1(5)); */
  /*  elseif Alpha1(5) == C5(1) */
  /*      Alpha1(6) = alpha1(5) - (C5(1) - alpha1(5)); */
  /*  elseif Alpha1(5) == C5(3) */
  /*      Alpha1(6) = alpha1(5) - (C5(3) - alpha1(5)); */
  /*  elseif Alpha1(5) == C5(4) */
  /*      Alpha1(6) = alpha1(5) - (C5(4) - alpha1(5)); */
  /*       */
  /*  elseif Alpha1(6) == C6(2) */
  /*      Alpha1(5) = alpha1(6) - (C6(2) - alpha1(6)); */
  /*  elseif Alpha1(6) == C6(1) */
  /*      Alpha1(5) = alpha1(6) - (C6(1) - alpha1(6)); */
  /*  elseif Alpha1(6) == C6(3) */
  /*      Alpha1(5) = alpha1(6) - (C6(3) - alpha1(6)); */
  /*  elseif Alpha1(6) == C6(4) */
  /*      Alpha1(5) = alpha1(6) - (C6(4) - alpha1(6)); */
  /*  end */
  /*  % Thruster 4 & 1 */
  /*  if     Alpha1(4) == C4(2) */
  /*      Alpha1(1) = alpha1(4) - (C4(2) - alpha1(4)); */
  /*  elseif Alpha1(4) == C4(1) */
  /*      Alpha1(1) = alpha1(4) - (C4(1) - alpha1(4)); */
  /*  elseif Alpha1(4) == C4(3) */
  /*      Alpha1(1) = alpha1(4) - (C4(3) - alpha1(4)); */
  /*  elseif Alpha1(4) == C4(4) */
  /*      Alpha1(1) = alpha1(4) - (C4(4) - alpha1(4)); */
  /*  end */
  /*   */
  /*  if     Alpha1(1) == C1(2) */
  /*      Alpha1(4) = alpha1(1) - (C1(2) - alpha1(1)); */
  /*  elseif Alpha1(1) == C1(1) */
  /*      Alpha1(4) = alpha1(1) - (C1(1) - alpha1(1)); */
  /*  elseif Alpha1(1) == C1(3) */
  /*      Alpha1(4) = alpha1(1) - (C1(3) - alpha1(1)); */
  /*  elseif Alpha1(1) == C1(4) */
  /*      Alpha1(4) = alpha1(1) - (C1(4) - alpha1(1)); */
  /*  end */
  /*   */
  /*  Alpha1 = [Alpha1(1) Alpha1(2) Alpha1(3) Alpha1(4) Alpha1(5) Alpha1(6)]';     */
  /*  Desired_thrust = [T_d(1) T_d(2) T_d(3) T_d(4) T_d(5) T_d(6)]'; */
  /*  alpha_desired = Alpha1; */
  /*  T_d = -Desired_thrust; */
  /* % Update outputs */
  /* '<S26>:1:299' */
  for (i = 0; i < 6; i++) {
    for (rtemp = 0; rtemp < 3; rtemp++) {
      T_surge_1[i + 6 * rtemp] = 0.0;
      T_surge_1[i + 6 * rtemp] += y[i] * R[rtemp];
      T_surge_1[i + 6 * rtemp] += y[i + 6] * R[rtemp + 3];
      T_surge_1[i + 6 * rtemp] += y[i + 12] * R[rtemp + 6];
    }
  }

  rtb_sys[0] = 57.295779513082323 * rt_atan2d_snf(T0[1], T0[0]);
  rtb_sys[1] = 57.295779513082323 * rt_atan2d_snf(T0[3], T0[2]);
  rtb_sys[2] = 57.295779513082323 * rt_atan2d_snf(T0[5], T0[4]);
  rtb_sys[3] = 57.295779513082323 * rt_atan2d_snf(T0[7], T0[6]);
  rtb_sys[4] = 57.295779513082323 * rt_atan2d_snf(T0[9], T0[8]);
  rtb_sys[5] = 57.295779513082323 * rt_atan2d_snf(T0[11], T0[10]);
  for (i = 0; i < 6; i++) {
    rtb_sys[i + 6] = T_surge_1[i + 12] * tc[2] + (T_surge_1[i + 6] * tc[1] +
      T_surge_1[i] * tc[0]);
  }

  /* Switch: '<S7>/Choosing Fixed // Azimuth angle' incorporates:
   *  Constant: '<S7>/Switch  Azimuth//Fixed angles'
   *  Constant: '<S7>/constant angle'
   */
  for (rtemp = 0; rtemp < 6; rtemp++) {
    if (ctrl_TAPM_P.Thruster_lock >= ctrl_TAPM_P.ChoosingFixedAzimuthangle_Thres)
    {
      ctrl_TAPM_B.ChoosingFixedAzimuthangle[rtemp] = rtb_sys[rtemp];
    } else {
      ctrl_TAPM_B.ChoosingFixedAzimuthangle[rtemp] =
        ctrl_TAPM_P.constantangle_Value[rtemp];
    }
  }

  /* End of Switch: '<S7>/Choosing Fixed // Azimuth angle' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
  }

  /* Outputs for Iterator SubSystem: '<S7>/For Each Subsystem' incorporates:
   *  ForEach: '<S25>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
    /* ForEachSliceSelector: '<S25>/ImpSel_InsertedFor_reset_at_outport_0' */
    rtb_ImpSel_InsertedFor_reset_at = ctrl_TAPM_B.reset[ForEach_itr];
    if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
      /* DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S7>/constant angle'
       *  ForEachSliceSelector: '<S25>/ImpSel_InsertedFor_initial angle _at_outport_0'
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

      /* End of DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */

      /* Gain: '<S29>/Gain1' */
      pos = ctrl_TAPM_P.CoreSubsys.Gain1_Gain *
        ctrl_TAPM_B.CoreSubsys[ForEach_itr].angle;

      /* Delay: '<S25>/Delay' */
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].Delay =
        ctrl_TAPM_DW.CoreSubsys[ForEach_itr].Delay_DSTATE;

      /* MATLAB Function: '<S25>/MATLAB Function' */
      /* MATLAB Function 'Thrust allocation1/For Each Subsystem/MATLAB Function': '<S30>:1' */
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
      /* '<S30>:1:39' */
      /* '<S30>:1:40' */
      /*  s = sign(angle); */
      /* '<S30>:1:43' */
      u = fabs(rt_remd_snf(pos + 3.1415926535897931, 6.2831853071795862) /
               6.2831853071795862);
      if (pos < 0.0) {
        rtb_TmpSignalConversionAtSFun_0 = -1.0;
      } else if (pos > 0.0) {
        rtb_TmpSignalConversionAtSFun_0 = 1.0;
      } else if (pos == 0.0) {
        rtb_TmpSignalConversionAtSFun_0 = 0.0;
      } else {
        rtb_TmpSignalConversionAtSFun_0 = pos;
      }

      if (u > 0.0) {
        u = 1.0;
      } else {
        if (u == 0.0) {
          u = 0.0;
        }
      }

      u = (u - 1.0) * 2.0 + rtb_TmpSignalConversionAtSFun_0;
      if (pos < 0.0) {
        rtb_TmpSignalConversionAtSFun_0 = -1.0;
      } else if (pos > 0.0) {
        rtb_TmpSignalConversionAtSFun_0 = 1.0;
      } else if (pos == 0.0) {
        rtb_TmpSignalConversionAtSFun_0 = 0.0;
      } else {
        rtb_TmpSignalConversionAtSFun_0 = pos;
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

      rtb_Out2_CoreSubsysCanOut = rt_remd_snf(rtb_TmpSignalConversionAtSFun_0 *
        3.1415926535897931 + pos, 6.2831853071795862) - u * 3.1415926535897931;

      /* End of MATLAB Function: '<S25>/MATLAB Function' */
    }

    /* MATLAB Function: '<S25>/MATLAB Function1' incorporates:
     *  ForEachSliceSelector: '<S25>/ImpSel_InsertedFor_Desired Angle_at_outport_0'
     */
    /* MATLAB Function 'Thrust allocation1/For Each Subsystem/MATLAB Function1': '<S31>:1' */
    /* '<S31>:1:3' */
    pos = ctrl_TAPM_B.ChoosingFixedAzimuthangle[ForEach_itr] -
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].Delay;
    if (fabs(pos) >= 360.0) {
      /* '<S31>:1:4' */
      /* '<S31>:1:5' */
      pos = rt_remd_snf(pos, 360.0);
    }

    if (fabs(pos) >= 180.0) {
      /* '<S31>:1:8' */
      /* '<S31>:1:9' */
      if (pos < 0.0) {
        rtb_TmpSignalConversionAtSFun_0 = -1.0;
      } else if (pos > 0.0) {
        rtb_TmpSignalConversionAtSFun_0 = 1.0;
      } else if (pos == 0.0) {
        rtb_TmpSignalConversionAtSFun_0 = 0.0;
      } else {
        rtb_TmpSignalConversionAtSFun_0 = pos;
      }

      pos -= rtb_TmpSignalConversionAtSFun_0 * 360.0;
    }

    /* End of MATLAB Function: '<S25>/MATLAB Function1' */

    /* Saturate: '<S25>/Max Rotation Rate' */
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
    if (pos > ctrl_TAPM_P.Max_rotation) {
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate =
        ctrl_TAPM_P.Max_rotation;
    } else if (pos < -ctrl_TAPM_P.Max_rotation) {
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate =
        -ctrl_TAPM_P.Max_rotation;
    } else {
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate = pos;
    }

    /* End of Saturate: '<S25>/Max Rotation Rate' */
    if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
      /* ForEachSliceAssignment: '<S25>/ImpAsg_InsertedFor_Out2 _at_inport_0' */
      rtb_ImpAsg_InsertedFor_Out2_at_[ForEach_itr] = rtb_Out2_CoreSubsysCanOut;
    }
  }

  /* End of Outputs for SubSystem: '<S7>/For Each Subsystem' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Saturate: '<S33>/Saturation 1' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[0] > ctrl_TAPM_P.Saturation1_UpperSat) {
      ctrl_TAPM_B.Saturation1 = ctrl_TAPM_P.Saturation1_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[0] <
               ctrl_TAPM_P.Saturation1_LowerSat) {
      ctrl_TAPM_B.Saturation1 = ctrl_TAPM_P.Saturation1_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation1 = rtb_ImpAsg_InsertedFor_Out2_at_[0];
    }

    /* End of Saturate: '<S33>/Saturation 1' */
  }

  /* Integrator: '<S42>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_TAPM_B.reset_o);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_c = ctrl_TAPM_P.Integrator_IC_f;
    }
  }

  ctrl_TAPM_B.Integrator = ctrl_TAPM_X.Integrator_CSTATE_c;

  /* MATLAB Function: '<S41>/Actual Force and Torque' incorporates:
   *  Constant: '<S34>/Losses (placeholder)'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM_ActualForceandTorque(ctrl_TAPM_B.Integrator, ctrl_TAPM_P.Kq,
    ctrl_TAPM_P.Kt, ctrl_TAPM_P.Ktr, ctrl_TAPM_P.Kqr, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value,
    &ctrl_TAPM_B.sf_ActualForceandTorque);

  /* Integrator: '<S52>/Integrator' */
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

  ctrl_TAPM_B.Integrator_h = ctrl_TAPM_X.Integrator_CSTATE_p;

  /* MATLAB Function: '<S51>/Actual Force and Torque' incorporates:
   *  Constant: '<S35>/Losses (placeholder)'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM_ActualForceandTorque(ctrl_TAPM_B.Integrator_h, ctrl_TAPM_P.Kq,
    ctrl_TAPM_P.Kt, ctrl_TAPM_P.Ktr, ctrl_TAPM_P.Kqr, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_k,
    &ctrl_TAPM_B.sf_ActualForceandTorque_f);

  /* Integrator: '<S62>/Integrator' */
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

  ctrl_TAPM_B.Integrator_a = ctrl_TAPM_X.Integrator_CSTATE_k;

  /* MATLAB Function: '<S61>/Actual Force and Torque' incorporates:
   *  Constant: '<S36>/Losses (placeholder)'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM_ActualForceandTorque(ctrl_TAPM_B.Integrator_a, ctrl_TAPM_P.Kq,
    ctrl_TAPM_P.Kt, ctrl_TAPM_P.Ktr, ctrl_TAPM_P.Kqr, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_n,
    &ctrl_TAPM_B.sf_ActualForceandTorque_h);

  /* Integrator: '<S72>/Integrator' */
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

  ctrl_TAPM_B.Integrator_k = ctrl_TAPM_X.Integrator_CSTATE_n;

  /* MATLAB Function: '<S71>/Actual Force and Torque' incorporates:
   *  Constant: '<S37>/Losses (placeholder)'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM_ActualForceandTorque(ctrl_TAPM_B.Integrator_k, ctrl_TAPM_P.Kq,
    ctrl_TAPM_P.Kt, ctrl_TAPM_P.Ktr, ctrl_TAPM_P.Kqr, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_d,
    &ctrl_TAPM_B.sf_ActualForceandTorque_m);

  /* Integrator: '<S82>/Integrator' */
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

  ctrl_TAPM_B.Integrator_c = ctrl_TAPM_X.Integrator_CSTATE_cd;

  /* MATLAB Function: '<S81>/Actual Force and Torque' incorporates:
   *  Constant: '<S38>/Losses (placeholder)'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM_ActualForceandTorque(ctrl_TAPM_B.Integrator_c, ctrl_TAPM_P.Kq,
    ctrl_TAPM_P.Kt, ctrl_TAPM_P.Ktr, ctrl_TAPM_P.Kqr, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_f,
    &ctrl_TAPM_B.sf_ActualForceandTorque_o);

  /* Integrator: '<S92>/Integrator' */
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

  ctrl_TAPM_B.Integrator_m = ctrl_TAPM_X.Integrator_CSTATE_h;

  /* MATLAB Function: '<S91>/Actual Force and Torque' incorporates:
   *  Constant: '<S39>/Losses (placeholder)'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM_ActualForceandTorque(ctrl_TAPM_B.Integrator_m, ctrl_TAPM_P.Kq,
    ctrl_TAPM_P.Kt, ctrl_TAPM_P.Ktr, ctrl_TAPM_P.Kqr, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_h,
    &ctrl_TAPM_B.sf_ActualForceandTorque_j);

  /* MATLAB Function: '<S32>/MATLAB Function' incorporates:
   *  Constant: '<S32>/Constant12'
   *  SignalConversion: '<S40>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Thruster control /Subsystem/MATLAB Function': '<S40>:1' */
  if (ctrl_TAPM_P.Constant12_Value == 1.0) {
    /* '<S40>:1:3' */
    /* '<S40>:1:4' */
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
    rtb_output_idx_2 = 0.0;
    rtb_output_idx_4 = 0.0;
    rtb_output_idx_6 = 0.0;
    rtb_output_idx_8 = 0.0;
    rtb_output_idx_10 = 0.0;
  } else {
    /* '<S40>:1:6' */
    rtb_TmpSignalConversionAtSFun_0 = ctrl_TAPM_B.sf_ActualForceandTorque.Ta;
    rtb_output_idx_2 = ctrl_TAPM_B.sf_ActualForceandTorque_f.Ta;
    rtb_output_idx_4 = ctrl_TAPM_B.sf_ActualForceandTorque_h.Ta;
    rtb_output_idx_6 = ctrl_TAPM_B.sf_ActualForceandTorque_m.Ta;
    rtb_output_idx_8 = ctrl_TAPM_B.sf_ActualForceandTorque_o.Ta;
    rtb_output_idx_10 = ctrl_TAPM_B.sf_ActualForceandTorque_j.Ta;
  }

  /* End of MATLAB Function: '<S32>/MATLAB Function' */

  /* Saturate: '<S32>/Saturation 2' */
  if (rtb_output_idx_2 > ctrl_TAPM_P.Max_thrust) {
    pos = ctrl_TAPM_P.Max_thrust;
  } else if (rtb_output_idx_2 < -ctrl_TAPM_P.Max_thrust) {
    pos = -ctrl_TAPM_P.Max_thrust;
  } else {
    pos = rtb_output_idx_2;
  }

  /* End of Saturate: '<S32>/Saturation 2' */

  /* Polyval: '<S32>/pwm thruster 2' */
  ctrl_TAPM_B.pwmthruster2 = ctrl_TAPM_P.thrust_to_pwm_coeff[0];
  for (res = 0; res < 5; res++) {
    ctrl_TAPM_B.pwmthruster2 = ctrl_TAPM_B.pwmthruster2 * pos +
      ctrl_TAPM_P.thrust_to_pwm_coeff[res + 1];
  }

  /* End of Polyval: '<S32>/pwm thruster 2' */

  /* Saturate: '<S32>/Saturation 3' */
  if (rtb_output_idx_4 > ctrl_TAPM_P.Max_thrust) {
    pos = ctrl_TAPM_P.Max_thrust;
  } else if (rtb_output_idx_4 < -ctrl_TAPM_P.Max_thrust) {
    pos = -ctrl_TAPM_P.Max_thrust;
  } else {
    pos = rtb_output_idx_4;
  }

  /* End of Saturate: '<S32>/Saturation 3' */

  /* Polyval: '<S32>/pwm thruster 3' */
  ctrl_TAPM_B.pwmthruster3 = ctrl_TAPM_P.thrust_to_pwm_coeff[0];
  for (res = 0; res < 5; res++) {
    ctrl_TAPM_B.pwmthruster3 = ctrl_TAPM_B.pwmthruster3 * pos +
      ctrl_TAPM_P.thrust_to_pwm_coeff[res + 1];
  }

  /* End of Polyval: '<S32>/pwm thruster 3' */

  /* Saturate: '<S32>/Saturation 4' */
  if (rtb_output_idx_6 > ctrl_TAPM_P.Max_thrust) {
    pos = ctrl_TAPM_P.Max_thrust;
  } else if (rtb_output_idx_6 < -ctrl_TAPM_P.Max_thrust) {
    pos = -ctrl_TAPM_P.Max_thrust;
  } else {
    pos = rtb_output_idx_6;
  }

  /* End of Saturate: '<S32>/Saturation 4' */

  /* Polyval: '<S32>/pwm thruster 4' */
  ctrl_TAPM_B.pwmthruster4 = ctrl_TAPM_P.thrust_to_pwm_coeff[0];
  for (res = 0; res < 5; res++) {
    ctrl_TAPM_B.pwmthruster4 = ctrl_TAPM_B.pwmthruster4 * pos +
      ctrl_TAPM_P.thrust_to_pwm_coeff[res + 1];
  }

  /* End of Polyval: '<S32>/pwm thruster 4' */

  /* Saturate: '<S32>/Saturation 5' */
  if (rtb_output_idx_8 > ctrl_TAPM_P.Max_thrust) {
    pos = ctrl_TAPM_P.Max_thrust;
  } else if (rtb_output_idx_8 < -ctrl_TAPM_P.Max_thrust) {
    pos = -ctrl_TAPM_P.Max_thrust;
  } else {
    pos = rtb_output_idx_8;
  }

  /* End of Saturate: '<S32>/Saturation 5' */

  /* Polyval: '<S32>/pwm thruster 5' */
  ctrl_TAPM_B.pwmthruster5 = ctrl_TAPM_P.thrust_to_pwm_coeff[0];
  for (res = 0; res < 5; res++) {
    ctrl_TAPM_B.pwmthruster5 = ctrl_TAPM_B.pwmthruster5 * pos +
      ctrl_TAPM_P.thrust_to_pwm_coeff[res + 1];
  }

  /* End of Polyval: '<S32>/pwm thruster 5' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Saturate: '<S33>/Saturation 2' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[1] > ctrl_TAPM_P.Saturation2_UpperSat) {
      ctrl_TAPM_B.Saturation2 = ctrl_TAPM_P.Saturation2_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[1] <
               ctrl_TAPM_P.Saturation2_LowerSat) {
      ctrl_TAPM_B.Saturation2 = ctrl_TAPM_P.Saturation2_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation2 = rtb_ImpAsg_InsertedFor_Out2_at_[1];
    }

    /* End of Saturate: '<S33>/Saturation 2' */
  }

  /* Saturate: '<S32>/Saturation 6' */
  if (rtb_output_idx_10 > ctrl_TAPM_P.Max_thrust) {
    pos = ctrl_TAPM_P.Max_thrust;
  } else if (rtb_output_idx_10 < -ctrl_TAPM_P.Max_thrust) {
    pos = -ctrl_TAPM_P.Max_thrust;
  } else {
    pos = rtb_output_idx_10;
  }

  /* End of Saturate: '<S32>/Saturation 6' */

  /* Polyval: '<S32>/pwm thruster 6' */
  ctrl_TAPM_B.pwmthruster6 = ctrl_TAPM_P.thrust_to_pwm_coeff[0];
  for (res = 0; res < 5; res++) {
    ctrl_TAPM_B.pwmthruster6 = ctrl_TAPM_B.pwmthruster6 * pos +
      ctrl_TAPM_P.thrust_to_pwm_coeff[res + 1];
  }

  /* End of Polyval: '<S32>/pwm thruster 6' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Saturate: '<S33>/Saturation 3' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[2] > ctrl_TAPM_P.Saturation3_UpperSat) {
      ctrl_TAPM_B.Saturation3 = ctrl_TAPM_P.Saturation3_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[2] <
               ctrl_TAPM_P.Saturation3_LowerSat) {
      ctrl_TAPM_B.Saturation3 = ctrl_TAPM_P.Saturation3_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation3 = rtb_ImpAsg_InsertedFor_Out2_at_[2];
    }

    /* End of Saturate: '<S33>/Saturation 3' */

    /* Saturate: '<S33>/Saturation 4' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[3] > ctrl_TAPM_P.Saturation4_UpperSat) {
      ctrl_TAPM_B.Saturation4 = ctrl_TAPM_P.Saturation4_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[3] <
               ctrl_TAPM_P.Saturation4_LowerSat) {
      ctrl_TAPM_B.Saturation4 = ctrl_TAPM_P.Saturation4_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation4 = rtb_ImpAsg_InsertedFor_Out2_at_[3];
    }

    /* End of Saturate: '<S33>/Saturation 4' */

    /* Saturate: '<S33>/Saturation 5' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[4] > ctrl_TAPM_P.Saturation5_UpperSat) {
      ctrl_TAPM_B.Saturation5 = ctrl_TAPM_P.Saturation5_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[4] <
               ctrl_TAPM_P.Saturation5_LowerSat) {
      ctrl_TAPM_B.Saturation5 = ctrl_TAPM_P.Saturation5_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation5 = rtb_ImpAsg_InsertedFor_Out2_at_[4];
    }

    /* End of Saturate: '<S33>/Saturation 5' */

    /* Saturate: '<S33>/Saturation 6' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[5] > ctrl_TAPM_P.Saturation6_UpperSat) {
      ctrl_TAPM_B.Saturation6 = ctrl_TAPM_P.Saturation6_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[5] <
               ctrl_TAPM_P.Saturation6_LowerSat) {
      ctrl_TAPM_B.Saturation6 = ctrl_TAPM_P.Saturation6_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation6 = rtb_ImpAsg_InsertedFor_Out2_at_[5];
    }

    /* End of Saturate: '<S33>/Saturation 6' */
  }

  /* Saturate: '<S32>/Saturation 7' */
  if (rtb_TmpSignalConversionAtSFun_0 > ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[0] = ctrl_TAPM_P.Max_thrust;
  } else if (rtb_TmpSignalConversionAtSFun_0 < -ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[0] = -ctrl_TAPM_P.Max_thrust;
  } else {
    ctrl_TAPM_B.Saturation7[0] = rtb_TmpSignalConversionAtSFun_0;
  }

  if (rtb_output_idx_2 > ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[1] = ctrl_TAPM_P.Max_thrust;
  } else if (rtb_output_idx_2 < -ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[1] = -ctrl_TAPM_P.Max_thrust;
  } else {
    ctrl_TAPM_B.Saturation7[1] = rtb_output_idx_2;
  }

  if (rtb_output_idx_4 > ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[2] = ctrl_TAPM_P.Max_thrust;
  } else if (rtb_output_idx_4 < -ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[2] = -ctrl_TAPM_P.Max_thrust;
  } else {
    ctrl_TAPM_B.Saturation7[2] = rtb_output_idx_4;
  }

  if (rtb_output_idx_6 > ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[3] = ctrl_TAPM_P.Max_thrust;
  } else if (rtb_output_idx_6 < -ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[3] = -ctrl_TAPM_P.Max_thrust;
  } else {
    ctrl_TAPM_B.Saturation7[3] = rtb_output_idx_6;
  }

  if (rtb_output_idx_8 > ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[4] = ctrl_TAPM_P.Max_thrust;
  } else if (rtb_output_idx_8 < -ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[4] = -ctrl_TAPM_P.Max_thrust;
  } else {
    ctrl_TAPM_B.Saturation7[4] = rtb_output_idx_8;
  }

  if (rtb_output_idx_10 > ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[5] = ctrl_TAPM_P.Max_thrust;
  } else if (rtb_output_idx_10 < -ctrl_TAPM_P.Max_thrust) {
    ctrl_TAPM_B.Saturation7[5] = -ctrl_TAPM_P.Max_thrust;
  } else {
    ctrl_TAPM_B.Saturation7[5] = rtb_output_idx_10;
  }

  /* End of Saturate: '<S32>/Saturation 7' */

  /* Saturate: '<S32>/Saturation 1' */
  if (rtb_TmpSignalConversionAtSFun_0 > ctrl_TAPM_P.Max_thrust) {
    pos = ctrl_TAPM_P.Max_thrust;
  } else if (rtb_TmpSignalConversionAtSFun_0 < -ctrl_TAPM_P.Max_thrust) {
    pos = -ctrl_TAPM_P.Max_thrust;
  } else {
    pos = rtb_TmpSignalConversionAtSFun_0;
  }

  /* End of Saturate: '<S32>/Saturation 1' */

  /* Polyval: '<S32>/pwm thruster 1' */
  ctrl_TAPM_B.pwmthruster1 = ctrl_TAPM_P.thrust_to_pwm_coeff[0];
  for (res = 0; res < 5; res++) {
    ctrl_TAPM_B.pwmthruster1 = ctrl_TAPM_B.pwmthruster1 * pos +
      ctrl_TAPM_P.thrust_to_pwm_coeff[res + 1];
  }

  /* End of Polyval: '<S32>/pwm thruster 1' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S5>/Gain' */
    ctrl_TAPM_B.Gain[0] = ctrl_TAPM_P.Gain_Gain_f * ctrl_TAPM_B.Saturation1;
    ctrl_TAPM_B.Gain[1] = ctrl_TAPM_P.Gain_Gain_f * ctrl_TAPM_B.Saturation2;
    ctrl_TAPM_B.Gain[2] = ctrl_TAPM_P.Gain_Gain_f * ctrl_TAPM_B.Saturation3;
    ctrl_TAPM_B.Gain[3] = ctrl_TAPM_P.Gain_Gain_f * ctrl_TAPM_B.Saturation4;
    ctrl_TAPM_B.Gain[4] = ctrl_TAPM_P.Gain_Gain_f * ctrl_TAPM_B.Saturation5;
    ctrl_TAPM_B.Gain[5] = ctrl_TAPM_P.Gain_Gain_f * ctrl_TAPM_B.Saturation6;
  }

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  Constant: '<Root>/X-position Thruster'
   *  Constant: '<Root>/Y-position Thruster'
   */
  /* MATLAB Function 'MATLAB Function': '<S2>:1' */
  /* '<S2>:1:4' */
  /* '<S2>:1:5' */
  /* '<S2>:1:6' */
  /*   T_dirx = [thrust_actual(1)*cosd(alpha_actual(1)) thrust_actual(2)*cosd(alpha_actual(2)) thrust_actual(3)*cosd(alpha_actual(3)) ... */
  /*             thrust_actual(4)*cosd(alpha_actual(4)) thrust_actual(5)*cosd(alpha_actual(5)) thrust_actual(6)*cosd(alpha_actual(6))]; */
  /*  T_diry = [thrust_actual(1)*sind(alpha_actual(1)) thrust_actual(2)*sind(alpha_actual(2)) thrust_actual(3)*sind(alpha_actual(3)) ... */
  /*            thrust_actual(4)*sind(alpha_actual(4)) thrust_actual(5)*sind(alpha_actual(5)) thrust_actual(6)*sind(alpha_actual(6))]; */
  /*  ANGLE = [atan2d(T_diry(1),T_dirx(1)) atan2d(T_diry(2),T_dirx(2)) atan2d(T_diry(3),T_dirx(3)) ... */
  /*           atan2d(T_diry(4),T_dirx(4)) atan2d(T_diry(5),T_dirx(5)) atan2d(T_diry(6),T_dirx(6))]'; */
  /* K = diag([ 5 5 5 5 5 5]); */
  /* '<S2>:1:17' */
  ctrl_TAPM_B.actual_tau[0] = 0.0;
  ctrl_TAPM_B.actual_tau[1] = 0.0;
  ctrl_TAPM_B.actual_tau[2] = 0.0;
  pos = ctrl_TAPM_B.Gain[0];
  ctrl_TAPM_cosd(&pos);
  rtb_Row1 = ctrl_TAPM_B.Gain[1];
  ctrl_TAPM_cosd(&rtb_Row1);
  offset = ctrl_TAPM_B.Gain[2];
  ctrl_TAPM_cosd(&offset);
  rtb_Row2 = ctrl_TAPM_B.Gain[3];
  ctrl_TAPM_cosd(&rtb_Row2);
  rtb_Out2_CoreSubsysCanOut = ctrl_TAPM_B.Gain[4];
  ctrl_TAPM_cosd(&rtb_Out2_CoreSubsysCanOut);
  rtb_TmpSignalConversionAtSFun_0 = ctrl_TAPM_B.Gain[5];
  ctrl_TAPM_cosd(&rtb_TmpSignalConversionAtSFun_0);
  rtb_output_idx_2 = ctrl_TAPM_B.Gain[0];
  ctrl_TAPM_sind(&rtb_output_idx_2);
  rtb_output_idx_4 = ctrl_TAPM_B.Gain[1];
  ctrl_TAPM_sind(&rtb_output_idx_4);
  rtb_output_idx_6 = ctrl_TAPM_B.Gain[2];
  ctrl_TAPM_sind(&rtb_output_idx_6);
  rtb_output_idx_8 = ctrl_TAPM_B.Gain[3];
  ctrl_TAPM_sind(&rtb_output_idx_8);
  rtb_output_idx_10 = ctrl_TAPM_B.Gain[4];
  ctrl_TAPM_sind(&rtb_output_idx_10);
  m = ctrl_TAPM_B.Gain[5];
  ctrl_TAPM_sind(&m);
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
  y_0 = ctrl_TAPM_B.Gain[5];
  ctrl_TAPM_cosd(&y_0);
  pos_0[0] = pos;
  pos_0[3] = rtb_Row1;
  pos_0[6] = offset;
  pos_0[9] = rtb_Row2;
  pos_0[12] = rtb_Out2_CoreSubsysCanOut;
  pos_0[15] = rtb_TmpSignalConversionAtSFun_0;
  pos_0[1] = rtb_output_idx_2;
  pos_0[4] = rtb_output_idx_4;
  pos_0[7] = rtb_output_idx_6;
  pos_0[10] = rtb_output_idx_8;
  pos_0[13] = rtb_output_idx_10;
  pos_0[16] = m;
  pos_0[2] = n * ctrl_TAPM_P.XpositionThruster_Value_e[0] - o *
    ctrl_TAPM_P.YpositionThruster_Value_o[0];
  pos_0[5] = p * ctrl_TAPM_P.XpositionThruster_Value_e[1] - q *
    ctrl_TAPM_P.YpositionThruster_Value_o[1];
  pos_0[8] = r * ctrl_TAPM_P.XpositionThruster_Value_e[2] - s_0 *
    ctrl_TAPM_P.YpositionThruster_Value_o[2];
  pos_0[11] = t * ctrl_TAPM_P.XpositionThruster_Value_e[3] - u *
    ctrl_TAPM_P.YpositionThruster_Value_o[3];
  pos_0[14] = v * ctrl_TAPM_P.XpositionThruster_Value_e[4] - w *
    ctrl_TAPM_P.YpositionThruster_Value_o[4];
  pos_0[17] = x * ctrl_TAPM_P.XpositionThruster_Value_e[5] - y_0 *
    ctrl_TAPM_P.YpositionThruster_Value_o[5];
  for (i = 0; i < 3; i++) {
    ctrl_TAPM_B.actual_tau[i] = 0.0;
    for (rtemp = 0; rtemp < 6; rtemp++) {
      ctrl_TAPM_B.actual_tau[i] += pos_0[3 * rtemp + i] *
        ctrl_TAPM_B.Saturation7[rtemp];
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* SignalConversion: '<S6>/TmpSignal ConversionAtSPInport1' */
  ctrl_TAPM_B.TmpSignalConversionAtSPInport1[0] =
    rtb_TmpSignalConversionAtSFun_c;
  ctrl_TAPM_B.TmpSignalConversionAtSPInport1[1] =
    rtb_TmpSignalConversionAtSFu_a0;
  ctrl_TAPM_B.TmpSignalConversionAtSPInport1[2] = rtb_Sum;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
  }

  /* Integrator: '<S11>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_ng,
                       ctrl_TAPM_B.reset_h);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_m = ctrl_TAPM_P.Integrator_IC_e;
    }
  }

  ctrl_TAPM_B.Integrator_l = ctrl_TAPM_X.Integrator_CSTATE_m;

  /* Sum: '<S12>/Sum2' incorporates:
   *  Integrator: '<S12>/Integrator1'
   *  Sum: '<S12>/Sum4'
   */
  rtb_MultiportSwitch[0] = ctrl_TAPM_B.x_m - (ctrl_TAPM_X.Integrator1_CSTATE[0]
    + ctrl_TAPM_B.eta[0]);
  rtb_MultiportSwitch[1] = ctrl_TAPM_B.y_m - (ctrl_TAPM_X.Integrator1_CSTATE[1]
    + ctrl_TAPM_B.eta[1]);
  rtb_MultiportSwitch[2] = ctrl_TAPM_B.psi_m - (ctrl_TAPM_X.Integrator1_CSTATE[2]
    + ctrl_TAPM_B.eta[2]);

  /* Gain: '<S12>/K4' */
  for (i = 0; i < 3; i++) {
    tc[i] = ctrl_TAPM_P.Nonlinearpassiveobserver_K4[i + 6] *
      rtb_MultiportSwitch[2] + (ctrl_TAPM_P.Nonlinearpassiveobserver_K4[i + 3] *
      rtb_MultiportSwitch[1] + ctrl_TAPM_P.Nonlinearpassiveobserver_K4[i] *
      rtb_MultiportSwitch[0]);
  }

  /* End of Gain: '<S12>/K4' */

  /* Sum: '<S12>/Sum1' incorporates:
   *  Fcn: '<S23>/Row1'
   *  Fcn: '<S23>/Row2'
   *  Fcn: '<S23>/Row3'
   */
  tmp[0] = cos(ctrl_TAPM_B.psi_m) * rtb_bias_idx_0 + sin(ctrl_TAPM_B.psi_m) *
    rtb_bias_idx_1;
  tmp[1] = -sin(ctrl_TAPM_B.psi_m) * rtb_bias_idx_0 + cos(ctrl_TAPM_B.psi_m) *
    rtb_bias_idx_1;
  tmp[2] = rtb_bias_idx_2;

  /* Sum: '<S12>/Sum8' incorporates:
   *  Fcn: '<S22>/Row1'
   *  Fcn: '<S22>/Row2'
   *  Fcn: '<S22>/Row3'
   *  Gain: '<S12>/Gain3'
   *  Gain: '<S12>/Gain6'
   *  Sum: '<S12>/Sum1'
   */
  tmp_0[0] = cos(ctrl_TAPM_B.psi_m) * tc[0] + sin(ctrl_TAPM_B.psi_m) * tc[1];
  tmp_0[1] = -sin(ctrl_TAPM_B.psi_m) * tc[0] + cos(ctrl_TAPM_B.psi_m) * tc[1];
  tmp_0[2] = tc[2];
  for (i = 0; i < 3; i++) {
    tc[i] = ((tmp[i] + ctrl_TAPM_B.actual_tau[i]) + tmp_0[i]) -
      ((ctrl_TAPM_P.Nonlinearpassiveobserver_D[i + 3] * ctrl_TAPM_B.nu[1] +
        ctrl_TAPM_P.Nonlinearpassiveobserver_D[i] * ctrl_TAPM_B.nu[0]) +
       ctrl_TAPM_P.Nonlinearpassiveobserver_D[i + 6] * ctrl_TAPM_B.nu[2]);
  }

  /* End of Sum: '<S12>/Sum8' */

  /* Gain: '<S12>/Gain3' */
  for (i = 0; i < 3; i++) {
    ctrl_TAPM_B.Gain3[i] = 0.0;
    ctrl_TAPM_B.Gain3[i] += ctrl_TAPM_P.Gain3_Gain[i] * tc[0];
    ctrl_TAPM_B.Gain3[i] += ctrl_TAPM_P.Gain3_Gain[i + 3] * tc[1];
    ctrl_TAPM_B.Gain3[i] += ctrl_TAPM_P.Gain3_Gain[i + 6] * tc[2];
  }

  /* Sum: '<S12>/Sum3' incorporates:
   *  Fcn: '<S21>/Fcn'
   *  Fcn: '<S21>/Fcn1'
   *  Fcn: '<S21>/Fcn2'
   *  Gain: '<S12>/K2'
   */
  tmp_1[0] = cos(ctrl_TAPM_B.psi_m) * ctrl_TAPM_B.nu[0] - sin(ctrl_TAPM_B.psi_m)
    * ctrl_TAPM_B.nu[1];
  tmp_1[1] = sin(ctrl_TAPM_B.psi_m) * ctrl_TAPM_B.nu[0] + cos(ctrl_TAPM_B.psi_m)
    * ctrl_TAPM_B.nu[1];
  tmp_1[2] = ctrl_TAPM_B.nu[2];
  for (i = 0; i < 3; i++) {
    ctrl_TAPM_B.Sum3[i] = ((ctrl_TAPM_P.Nonlinearpassiveobserver_w_c[i + 3] *
      rtb_MultiportSwitch[1] + ctrl_TAPM_P.Nonlinearpassiveobserver_w_c[i] *
      rtb_MultiportSwitch[0]) + ctrl_TAPM_P.Nonlinearpassiveobserver_w_c[i + 6] *
      rtb_MultiportSwitch[2]) + tmp_1[i];
  }

  /* End of Sum: '<S12>/Sum3' */

  /* Sum: '<S12>/Sum5' incorporates:
   *  Gain: '<S12>/K11'
   *  Integrator: '<S12>/Integrator1'
   */
  for (i = 0; i < 3; i++) {
    ctrl_TAPM_B.psi_WF[i] = ((ctrl_TAPM_P.K11_Gain[i + 3] * rtb_MultiportSwitch
      [1] + ctrl_TAPM_P.K11_Gain[i] * rtb_MultiportSwitch[0]) +
      ctrl_TAPM_P.K11_Gain[i + 6] * rtb_MultiportSwitch[2]) +
      ctrl_TAPM_X.Integrator1_CSTATE[i];
  }

  /* End of Sum: '<S12>/Sum5' */

  /* Gain: '<S12>/K12' incorporates:
   *  Sum: '<S12>/Sum6'
   */
  for (i = 0; i < 3; i++) {
    tmp[i] = ctrl_TAPM_P.K12_Gain[i + 6] * rtb_MultiportSwitch[2] +
      (ctrl_TAPM_P.K12_Gain[i + 3] * rtb_MultiportSwitch[1] +
       ctrl_TAPM_P.K12_Gain[i] * rtb_MultiportSwitch[0]);
  }

  /* End of Gain: '<S12>/K12' */

  /* Gain: '<S12>/Gain2' incorporates:
   *  Integrator: '<S12>/Integrator2'
   *  Sum: '<S12>/Sum6'
   */
  for (i = 0; i < 3; i++) {
    tmp_0[i] = ctrl_TAPM_P.Gain2_Gain[i + 6] * ctrl_TAPM_X.Integrator2_CSTATE[2]
      + (ctrl_TAPM_P.Gain2_Gain[i + 3] * ctrl_TAPM_X.Integrator2_CSTATE[1] +
         ctrl_TAPM_P.Gain2_Gain[i] * ctrl_TAPM_X.Integrator2_CSTATE[0]);
  }

  /* End of Gain: '<S12>/Gain2' */

  /* Sum: '<S12>/Sum6' incorporates:
   *  Gain: '<S12>/Gain1'
   *  Integrator: '<S12>/Integrator1'
   */
  for (i = 0; i < 3; i++) {
    ctrl_TAPM_B.Sum6[i] = (tmp[i] - tmp_0[i]) - ((ctrl_TAPM_P.Gain1_Gain[i + 3] *
      ctrl_TAPM_X.Integrator1_CSTATE[1] + ctrl_TAPM_P.Gain1_Gain[i] *
      ctrl_TAPM_X.Integrator1_CSTATE[0]) + ctrl_TAPM_P.Gain1_Gain[i + 6] *
      ctrl_TAPM_X.Integrator1_CSTATE[2]);
  }

  /* Gain: '<S12>/inv(T_b)' incorporates:
   *  Sum: '<S12>/Sum7'
   */
  for (i = 0; i < 3; i++) {
    tmp[i] = ctrl_TAPM_P.invT_b_Gain[i + 6] * rtb_bias_idx_2 +
      (ctrl_TAPM_P.invT_b_Gain[i + 3] * rtb_bias_idx_1 +
       ctrl_TAPM_P.invT_b_Gain[i] * rtb_bias_idx_0);
  }

  /* End of Gain: '<S12>/inv(T_b)' */

  /* Sum: '<S12>/Sum7' incorporates:
   *  Gain: '<S12>/K3'
   */
  for (i = 0; i < 3; i++) {
    ctrl_TAPM_B.Sum7[i] = ((ctrl_TAPM_P.Nonlinearpassiveobserver_K3[i + 3] *
      rtb_MultiportSwitch[1] + ctrl_TAPM_P.Nonlinearpassiveobserver_K3[i] *
      rtb_MultiportSwitch[0]) + ctrl_TAPM_P.Nonlinearpassiveobserver_K3[i + 6] *
      rtb_MultiportSwitch[2]) - tmp[i];
  }

  /* Sum: '<S13>/Sum' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Gain: '<S1>/deg2rad'
   */
  ctrl_TAPM_B.Sum = ctrl_TAPM_P.deg2rad_Gain * ctrl_TAPM_B.wave_dir +
    ctrl_TAPM_P.Constant1_Value;

  /* Sum: '<S13>/Sum1' incorporates:
   *  Gain: '<S13>/Gain'
   *  Gain: '<S13>/Gain1'
   */
  ctrl_TAPM_B.Sum1[0] = (ctrl_TAPM_P.Gain1_Gain_i[0] * ctrl_TAPM_B.eta[0] +
    ctrl_TAPM_P.Gain1_Gain_i[2] * ctrl_TAPM_B.eta[1]) -
    (ctrl_TAPM_P.Gain_Gain_d[0] * rtb_Integrator_idx_0 +
     ctrl_TAPM_P.Gain_Gain_d[2] * rtb_Integrator_idx_1);
  ctrl_TAPM_B.Sum1[1] = (ctrl_TAPM_P.Gain1_Gain_i[1] * ctrl_TAPM_B.eta[0] +
    ctrl_TAPM_P.Gain1_Gain_i[3] * ctrl_TAPM_B.eta[1]) -
    (ctrl_TAPM_P.Gain_Gain_d[1] * rtb_Integrator_idx_0 +
     ctrl_TAPM_P.Gain_Gain_d[3] * rtb_Integrator_idx_1);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Delay: '<S8>/Delay' */
    for (rtemp = 0; rtemp < 6; rtemp++) {
      ctrl_TAPM_B.Delay_n[rtemp] = ctrl_TAPM_DW.Delay_DSTATE_i[rtemp];
    }

    /* End of Delay: '<S8>/Delay' */

    /* Delay: '<S34>/Delay' */
    ctrl_TAPM_B.Delay_e = ctrl_TAPM_DW.Delay_DSTATE_f;

    /* Delay: '<S43>/Delay' */
    ctrl_TAPM_B.Delay_a = ctrl_TAPM_DW.Delay_DSTATE_fu;
  }

  /* MATLAB Function: '<S43>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/MATLAB Function': '<S47>:1' */
  /* '<S47>:1:5' */
  if (rtb_sys[6] < 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = -1.0;
  } else if (rtb_sys[6] > 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = 1.0;
  } else if (rtb_sys[6] == 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_0 = rtb_sys[6];
  }

  pos = sqrt(fabs(rtb_sys[6]) / (ctrl_TAPM_P.Rho * rt_powd_snf(ctrl_TAPM_P.D,
    4.0) * ctrl_TAPM_P.Kt)) * rtb_TmpSignalConversionAtSFun_0;

  /* '<S47>:1:7' */
  rtb_Row1 = tanh(ctrl_TAPM_P.eps_c * pos / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S47>:1:8' */
  /* '<S47>:1:10' */
  if (ctrl_TAPM_B.Delay_a < 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = -1.0;
  } else if (ctrl_TAPM_B.Delay_a > 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = 1.0;
  } else if (ctrl_TAPM_B.Delay_a == 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_0 = ctrl_TAPM_B.Delay_a;
  }

  rtb_T_r_c = ((1.0 - rtb_Row1) * ctrl_TAPM_P.Ktr + ctrl_TAPM_P.Kt * rtb_Row1) *
    rtb_TmpSignalConversionAtSFun_0 * ctrl_TAPM_P.Rho * rt_powd_snf
    (ctrl_TAPM_P.D, 4.0) * (ctrl_TAPM_B.Delay_a * ctrl_TAPM_B.Delay_a);
  ctrl_TAPM_B.n_d_b = pos;

  /* End of MATLAB Function: '<S43>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S43>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S43>/Constant1'
     *  Constant: '<S43>/Constant2'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp = (ctrl_TAPM_B.n_d_b -
      ctrl_TAPM_P.Constant2_Value[1] * ctrl_TAPM_DW.DiscreteTransferFcn_states[0])
      - ctrl_TAPM_P.Constant2_Value[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states[1];
    ctrl_TAPM_B.DiscreteTransferFcn = (ctrl_TAPM_P.Constant1_Value_o[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp + ctrl_TAPM_P.Constant1_Value_o[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states[0]) +
      ctrl_TAPM_P.Constant1_Value_o[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states[1];

    /* SampleTimeMath: '<S46>/TSamp'
     *
     * About '<S46>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp = ctrl_TAPM_B.DiscreteTransferFcn * ctrl_TAPM_P.TSamp_WtEt;

    /* Sum: '<S46>/Diff' incorporates:
     *  UnitDelay: '<S46>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp - ctrl_TAPM_DW.UD_DSTATE;

    /* RateLimiter: '<S43>/Acceleration Limit' */
    pos = rtb_Sum_b - ctrl_TAPM_DW.PrevY;
    if (pos > ctrl_TAPM_P.AccelerationLimit_RisingLim) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY + ctrl_TAPM_P.AccelerationLimit_RisingLim;
    } else {
      if (pos < ctrl_TAPM_P.AccelerationLimit_FallingLim) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY +
          ctrl_TAPM_P.AccelerationLimit_FallingLim;
      }
    }

    ctrl_TAPM_DW.PrevY = rtb_Sum_b;

    /* End of RateLimiter: '<S43>/Acceleration Limit' */

    /* Gain: '<S43>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation = ctrl_TAPM_P.I_s * 2.0 * 3.1415926535897931
      * rtb_Sum_b;

    /* Sum: '<S43>/Sum1' incorporates:
     *  Gain: '<S43>/Qf_0'
     *  Gain: '<S43>/Qff_0(nr)'
     *  Gain: '<S43>/Qff_1(nr)'
     *  Trigonometry: '<S43>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_n = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn) * ctrl_TAPM_P.Q_f0 + ctrl_TAPM_P.K_omega *
      2.0 * 3.1415926535897931 * ctrl_TAPM_B.DiscreteTransferFcn;

    /* Memory: '<S43>/Memory' */
    ctrl_TAPM_B.Memory = ctrl_TAPM_DW.Memory_PreviousInput;

    /* Sum: '<S45>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn - ctrl_TAPM_B.Delay_n[0];

    /* Gain: '<S45>/Kp' */
    ctrl_TAPM_B.Kp = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S45>/Integrator' */
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

  /* MATLAB Function: '<S45>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay_n[0], ctrl_TAPM_P.Kt, ctrl_TAPM_P.Kq,
    ctrl_TAPM_P.D, rtb_T_r_c, ctrl_TAPM_P.eps, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Ktr, ctrl_TAPM_P.Kqr,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePowerand);

  /* MultiPortSwitch: '<S43>/Controller chosen' incorporates:
   *  Constant: '<S43>/NaN'
   *  Sum: '<S45>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory) {
   case 1:
    pos = ctrl_TAPM_B.Kp + rtb_Integrator_g;
    break;

   case 2:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePowerand.Qcq;
    break;

   case 3:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePowerand.Qcp;
    break;

   case 4:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePowerand.Qcc;
    break;

   default:
    pos = ctrl_TAPM_P.NaN_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S43>/Controller chosen' */

  /* Sum: '<S43>/Sum' */
  ctrl_TAPM_B.Sum_k = (ctrl_TAPM_B.Inertiacompensation + ctrl_TAPM_B.Sum1_n) +
    pos;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S34>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S34>/Constant'
     *  Constant: '<S34>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a = ctrl_TAPM_B.Sum_k -
      ctrl_TAPM_P.Constant_Value_cs[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_d;
    ctrl_TAPM_B.DiscreteTransferFcn_d = ctrl_TAPM_P.Constant1_Value_k[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a + ctrl_TAPM_P.Constant1_Value_k[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_d;
  }

  /* Gain: '<S42>/Finding rotation speed' incorporates:
   *  Gain: '<S42>/K_omega'
   *  Sum: '<S42>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed = ((ctrl_TAPM_B.DiscreteTransferFcn_d -
    ctrl_TAPM_B.Delay_e) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_TAPM_B.Integrator) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S45>/Ki' */
    ctrl_TAPM_B.Ki = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S43>/Supervisor' incorporates:
     *  Constant: '<S43>/Switch controller'
     */
    ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory, ctrl_TAPM_P.Thruster_control,
                         ctrl_TAPM_B.Delay_n[0], &ctrl_TAPM_B.sf_Supervisor);

    /* Delay: '<S35>/Delay' */
    ctrl_TAPM_B.Delay_b = ctrl_TAPM_DW.Delay_DSTATE_b;

    /* Delay: '<S53>/Delay' */
    ctrl_TAPM_B.Delay_bs = ctrl_TAPM_DW.Delay_DSTATE_d;
  }

  /* MATLAB Function: '<S53>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM_MATLABFunction(rtb_sys[7], ctrl_TAPM_P.Kt, ctrl_TAPM_P.Ktr,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_B.Delay_bs,
    &ctrl_TAPM_B.sf_MATLABFunction_i);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S53>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S53>/Constant1'
     *  Constant: '<S53>/Constant2'
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

    /* SampleTimeMath: '<S56>/TSamp'
     *
     * About '<S56>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_n = ctrl_TAPM_B.DiscreteTransferFcn_e *
      ctrl_TAPM_P.TSamp_WtEt_k;

    /* Sum: '<S56>/Diff' incorporates:
     *  UnitDelay: '<S56>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_n - ctrl_TAPM_DW.UD_DSTATE_n;

    /* RateLimiter: '<S53>/Acceleration Limit' */
    pos = rtb_Sum_b - ctrl_TAPM_DW.PrevY_e;
    if (pos > ctrl_TAPM_P.AccelerationLimit_RisingLim_n) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_e +
        ctrl_TAPM_P.AccelerationLimit_RisingLim_n;
    } else {
      if (pos < ctrl_TAPM_P.AccelerationLimit_FallingLim_n) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_e +
          ctrl_TAPM_P.AccelerationLimit_FallingLim_n;
      }
    }

    ctrl_TAPM_DW.PrevY_e = rtb_Sum_b;

    /* End of RateLimiter: '<S53>/Acceleration Limit' */

    /* Gain: '<S53>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_e = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S53>/Sum1' incorporates:
     *  Gain: '<S53>/Qf_0'
     *  Gain: '<S53>/Qff_0(nr)'
     *  Gain: '<S53>/Qff_1(nr)'
     *  Trigonometry: '<S53>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_nn = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_e) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_e;

    /* Memory: '<S53>/Memory' */
    ctrl_TAPM_B.Memory_c = ctrl_TAPM_DW.Memory_PreviousInput_n;

    /* Sum: '<S55>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_e - ctrl_TAPM_B.Delay_n[1];

    /* Gain: '<S55>/Kp' */
    ctrl_TAPM_B.Kp_p = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S55>/Integrator' */
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

  /* MATLAB Function: '<S55>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay_n[1], ctrl_TAPM_P.Kt, ctrl_TAPM_P.Kq,
    ctrl_TAPM_P.D, ctrl_TAPM_B.sf_MATLABFunction_i.T_r, ctrl_TAPM_P.eps,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Ktr, ctrl_TAPM_P.Kqr,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePowera_o);

  /* MultiPortSwitch: '<S53>/Controller chosen' incorporates:
   *  Constant: '<S53>/NaN'
   *  Sum: '<S55>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_c) {
   case 1:
    pos = ctrl_TAPM_B.Kp_p + rtb_Integrator_f;
    break;

   case 2:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_o.Qcq;
    break;

   case 3:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_o.Qcp;
    break;

   case 4:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_o.Qcc;
    break;

   default:
    pos = ctrl_TAPM_P.NaN_Value_l;
    break;
  }

  /* End of MultiPortSwitch: '<S53>/Controller chosen' */

  /* Sum: '<S53>/Sum' */
  ctrl_TAPM_B.Sum_h = (ctrl_TAPM_B.Inertiacompensation_e + ctrl_TAPM_B.Sum1_nn)
    + pos;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S35>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S35>/Constant'
     *  Constant: '<S35>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h = ctrl_TAPM_B.Sum_h -
      ctrl_TAPM_P.Constant_Value_h[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_m;
    ctrl_TAPM_B.DiscreteTransferFcn_k = ctrl_TAPM_P.Constant1_Value_j[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h + ctrl_TAPM_P.Constant1_Value_j[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_m;
  }

  /* Gain: '<S52>/Finding rotation speed' incorporates:
   *  Gain: '<S52>/K_omega'
   *  Sum: '<S52>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_a = ((ctrl_TAPM_B.DiscreteTransferFcn_k -
    ctrl_TAPM_B.Delay_b) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_TAPM_B.Integrator_h) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S55>/Ki' */
    ctrl_TAPM_B.Ki_o = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S53>/Supervisor' incorporates:
     *  Constant: '<S53>/Switch controller'
     */
    ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_c, ctrl_TAPM_P.Thruster_control,
                         ctrl_TAPM_B.Delay_n[1], &ctrl_TAPM_B.sf_Supervisor_h);

    /* Delay: '<S36>/Delay' */
    ctrl_TAPM_B.Delay_i = ctrl_TAPM_DW.Delay_DSTATE_n;

    /* Delay: '<S63>/Delay' */
    ctrl_TAPM_B.Delay_by = ctrl_TAPM_DW.Delay_DSTATE_no;
  }

  /* MATLAB Function: '<S63>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM_MATLABFunction(rtb_sys[8], ctrl_TAPM_P.Kt, ctrl_TAPM_P.Ktr,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_B.Delay_by,
    &ctrl_TAPM_B.sf_MATLABFunction_m);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S63>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S63>/Constant1'
     *  Constant: '<S63>/Constant2'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_e =
      (ctrl_TAPM_B.sf_MATLABFunction_m.n_d - ctrl_TAPM_P.Constant2_Value_h[1] *
       ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0]) -
      ctrl_TAPM_P.Constant2_Value_h[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[1];
    ctrl_TAPM_B.DiscreteTransferFcn_f = (ctrl_TAPM_P.Constant1_Value_g[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_e + ctrl_TAPM_P.Constant1_Value_g[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0]) +
      ctrl_TAPM_P.Constant1_Value_g[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[1];

    /* SampleTimeMath: '<S66>/TSamp'
     *
     * About '<S66>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_k = ctrl_TAPM_B.DiscreteTransferFcn_f *
      ctrl_TAPM_P.TSamp_WtEt_m;

    /* Sum: '<S66>/Diff' incorporates:
     *  UnitDelay: '<S66>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_k - ctrl_TAPM_DW.UD_DSTATE_i;

    /* RateLimiter: '<S63>/Acceleration limiter' */
    pos = rtb_Sum_b - ctrl_TAPM_DW.PrevY_o;
    if (pos > ctrl_TAPM_P.Accelerationlimiter_RisingLim) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_o +
        ctrl_TAPM_P.Accelerationlimiter_RisingLim;
    } else {
      if (pos < ctrl_TAPM_P.Accelerationlimiter_FallingLim) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_o +
          ctrl_TAPM_P.Accelerationlimiter_FallingLim;
      }
    }

    ctrl_TAPM_DW.PrevY_o = rtb_Sum_b;

    /* End of RateLimiter: '<S63>/Acceleration limiter' */

    /* Gain: '<S63>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_c = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S63>/Sum1' incorporates:
     *  Gain: '<S63>/Qf_0'
     *  Gain: '<S63>/Qff_0(nr)'
     *  Gain: '<S63>/Qff_1(nr)'
     *  Trigonometry: '<S63>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_i = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_f) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_f;

    /* Memory: '<S63>/Memory' */
    ctrl_TAPM_B.Memory_i = ctrl_TAPM_DW.Memory_PreviousInput_d;

    /* Sum: '<S65>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_f - ctrl_TAPM_B.Delay_n[2];

    /* Gain: '<S65>/Kp' */
    ctrl_TAPM_B.Kp_i = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S65>/Integrator' */
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

  rtb_Integrator_h = ctrl_TAPM_X.Integrator_CSTATE_i;

  /* MATLAB Function: '<S65>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay_n[2], ctrl_TAPM_P.Kt, ctrl_TAPM_P.Kq,
    ctrl_TAPM_P.D, ctrl_TAPM_B.sf_MATLABFunction_m.T_r, ctrl_TAPM_P.eps,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Ktr, ctrl_TAPM_P.Kqr,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePowera_n);

  /* MultiPortSwitch: '<S63>/Controller chosen' incorporates:
   *  Constant: '<S63>/NaN'
   *  Sum: '<S65>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_i) {
   case 1:
    pos = ctrl_TAPM_B.Kp_i + rtb_Integrator_h;
    break;

   case 2:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_n.Qcq;
    break;

   case 3:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_n.Qcp;
    break;

   case 4:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_n.Qcc;
    break;

   default:
    pos = ctrl_TAPM_P.NaN_Value_g;
    break;
  }

  /* End of MultiPortSwitch: '<S63>/Controller chosen' */

  /* Sum: '<S63>/Sum' */
  ctrl_TAPM_B.Sum_hf = (ctrl_TAPM_B.Inertiacompensation_c + ctrl_TAPM_B.Sum1_i)
    + pos;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S36>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_hh = ctrl_TAPM_B.Sum_hf -
      ctrl_TAPM_P.Constant_Value_n[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_k;
    ctrl_TAPM_B.DiscreteTransferFcn_n = ctrl_TAPM_P.Constant1_Value_a[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_hh + ctrl_TAPM_P.Constant1_Value_a[1]
      * ctrl_TAPM_DW.DiscreteTransferFcn_states_k;
  }

  /* Gain: '<S62>/Finding rotation speed' incorporates:
   *  Gain: '<S62>/K_omega'
   *  Sum: '<S62>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_m = ((ctrl_TAPM_B.DiscreteTransferFcn_n -
    ctrl_TAPM_B.Delay_i) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_TAPM_B.Integrator_a) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S65>/Ki' */
    ctrl_TAPM_B.Ki_n = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S63>/Supervisor' incorporates:
     *  Constant: '<S63>/Switch controller'
     */
    ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_i, ctrl_TAPM_P.Thruster_control,
                         ctrl_TAPM_B.Delay_n[2], &ctrl_TAPM_B.sf_Supervisor_l);

    /* Delay: '<S37>/Delay' */
    ctrl_TAPM_B.Delay_g = ctrl_TAPM_DW.Delay_DSTATE_e;

    /* Delay: '<S73>/Delay' */
    ctrl_TAPM_B.Delay_l = ctrl_TAPM_DW.Delay_DSTATE_id;
  }

  /* MATLAB Function: '<S73>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM_MATLABFunction(rtb_sys[9], ctrl_TAPM_P.Kt, ctrl_TAPM_P.Ktr,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_B.Delay_l,
    &ctrl_TAPM_B.sf_MATLABFunction_go);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S73>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S73>/Constant1'
     *  Constant: '<S73>/Constant2'
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

    /* SampleTimeMath: '<S76>/TSamp'
     *
     * About '<S76>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_a = ctrl_TAPM_B.DiscreteTransferFcn_l *
      ctrl_TAPM_P.TSamp_WtEt_h;

    /* Sum: '<S76>/Diff' incorporates:
     *  UnitDelay: '<S76>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_a - ctrl_TAPM_DW.UD_DSTATE_n4;

    /* RateLimiter: '<S73>/Acceleration limiter' */
    pos = rtb_Sum_b - ctrl_TAPM_DW.PrevY_c;
    if (pos > ctrl_TAPM_P.Accelerationlimiter_RisingLim_e) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_c +
        ctrl_TAPM_P.Accelerationlimiter_RisingLim_e;
    } else {
      if (pos < ctrl_TAPM_P.Accelerationlimiter_FallingLi_b) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_c +
          ctrl_TAPM_P.Accelerationlimiter_FallingLi_b;
      }
    }

    ctrl_TAPM_DW.PrevY_c = rtb_Sum_b;

    /* End of RateLimiter: '<S73>/Acceleration limiter' */

    /* Gain: '<S73>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_k = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S73>/Sum1' incorporates:
     *  Gain: '<S73>/Qf_0'
     *  Gain: '<S73>/Qff_0(nr)'
     *  Gain: '<S73>/Qff_1(nr)'
     *  Trigonometry: '<S73>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_b = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_l) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_l;

    /* Memory: '<S73>/Memory' */
    ctrl_TAPM_B.Memory_j = ctrl_TAPM_DW.Memory_PreviousInput_a;

    /* Sum: '<S75>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_l - ctrl_TAPM_B.Delay_n[3];

    /* Gain: '<S75>/Kp' */
    ctrl_TAPM_B.Kp_c = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S75>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_h,
                       ctrl_TAPM_B.reset_n);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_le = ctrl_TAPM_P.Integrator_IC_g;
    }
  }

  rtb_Integrator_a = ctrl_TAPM_X.Integrator_CSTATE_le;

  /* MATLAB Function: '<S75>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay_n[3], ctrl_TAPM_P.Kt, ctrl_TAPM_P.Kq,
    ctrl_TAPM_P.D, ctrl_TAPM_B.sf_MATLABFunction_go.T_r, ctrl_TAPM_P.eps,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Ktr, ctrl_TAPM_P.Kqr,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePower_n3);

  /* MultiPortSwitch: '<S73>/Controller chosen' incorporates:
   *  Constant: '<S73>/NaN'
   *  Sum: '<S75>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_j) {
   case 1:
    pos = ctrl_TAPM_B.Kp_c + rtb_Integrator_a;
    break;

   case 2:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePower_n3.Qcq;
    break;

   case 3:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePower_n3.Qcp;
    break;

   case 4:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePower_n3.Qcc;
    break;

   default:
    pos = ctrl_TAPM_P.NaN_Value_p;
    break;
  }

  /* End of MultiPortSwitch: '<S73>/Controller chosen' */

  /* Sum: '<S73>/Sum' */
  ctrl_TAPM_B.Sum_k2 = (ctrl_TAPM_B.Inertiacompensation_k + ctrl_TAPM_B.Sum1_b)
    + pos;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S37>/Constant'
     *  Constant: '<S37>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_n = ctrl_TAPM_B.Sum_k2 -
      ctrl_TAPM_P.Constant_Value_j[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_h0;
    ctrl_TAPM_B.DiscreteTransferFcn_b = ctrl_TAPM_P.Constant1_Value_oi[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_n + ctrl_TAPM_P.Constant1_Value_oi[1]
      * ctrl_TAPM_DW.DiscreteTransferFcn_states_h0;
  }

  /* Gain: '<S72>/Finding rotation speed' incorporates:
   *  Gain: '<S72>/K_omega'
   *  Sum: '<S72>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_ms = ((ctrl_TAPM_B.DiscreteTransferFcn_b -
    ctrl_TAPM_B.Delay_g) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_TAPM_B.Integrator_k) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S75>/Ki' */
    ctrl_TAPM_B.Ki_b = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S73>/Supervisor' incorporates:
     *  Constant: '<S73>/Switch controller'
     */
    ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_j, ctrl_TAPM_P.Thruster_control,
                         ctrl_TAPM_B.Delay_n[3], &ctrl_TAPM_B.sf_Supervisor_n);

    /* Delay: '<S38>/Delay' */
    ctrl_TAPM_B.Delay_a5 = ctrl_TAPM_DW.Delay_DSTATE_j;

    /* Delay: '<S83>/Delay' */
    ctrl_TAPM_B.Delay_id = ctrl_TAPM_DW.Delay_DSTATE_a;
  }

  /* MATLAB Function: '<S83>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM_MATLABFunction(rtb_sys[10], ctrl_TAPM_P.Kt, ctrl_TAPM_P.Ktr,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_B.Delay_id,
    &ctrl_TAPM_B.sf_MATLABFunction_j);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S83>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S83>/Constant1'
     *  Constant: '<S83>/Constant2'
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

    /* SampleTimeMath: '<S86>/TSamp'
     *
     * About '<S86>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_m = ctrl_TAPM_B.DiscreteTransferFcn_o *
      ctrl_TAPM_P.TSamp_WtEt_o;

    /* Sum: '<S86>/Diff' incorporates:
     *  UnitDelay: '<S86>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_m - ctrl_TAPM_DW.UD_DSTATE_m;

    /* RateLimiter: '<S83>/Acceleration limiter' */
    pos = rtb_Sum_b - ctrl_TAPM_DW.PrevY_j;
    if (pos > ctrl_TAPM_P.Accelerationlimiter_RisingLim_b) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_j +
        ctrl_TAPM_P.Accelerationlimiter_RisingLim_b;
    } else {
      if (pos < ctrl_TAPM_P.Accelerationlimiter_FallingLi_d) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_j +
          ctrl_TAPM_P.Accelerationlimiter_FallingLi_d;
      }
    }

    ctrl_TAPM_DW.PrevY_j = rtb_Sum_b;

    /* End of RateLimiter: '<S83>/Acceleration limiter' */

    /* Gain: '<S83>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_f = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S83>/Sum1' incorporates:
     *  Gain: '<S83>/Qf_0'
     *  Gain: '<S83>/Qff_0(nr)'
     *  Gain: '<S83>/Qff_1(nr)'
     *  Trigonometry: '<S83>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_o = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_o) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_o;

    /* Memory: '<S83>/Memory' */
    ctrl_TAPM_B.Memory_d = ctrl_TAPM_DW.Memory_PreviousInput_b;

    /* Sum: '<S85>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_o - ctrl_TAPM_B.Delay_n[4];

    /* Gain: '<S85>/Kp' */
    ctrl_TAPM_B.Kp_j = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S85>/Integrator' */
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

  /* MATLAB Function: '<S85>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay_n[4], ctrl_TAPM_P.Kt, ctrl_TAPM_P.Kq,
    ctrl_TAPM_P.D, ctrl_TAPM_B.sf_MATLABFunction_j.T_r, ctrl_TAPM_P.eps,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Ktr, ctrl_TAPM_P.Kqr,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePowera_h);

  /* MultiPortSwitch: '<S83>/Controller chosen' incorporates:
   *  Constant: '<S83>/NaN'
   *  Sum: '<S85>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_d) {
   case 1:
    pos = ctrl_TAPM_B.Kp_j + rtb_Integrator_i;
    break;

   case 2:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_h.Qcq;
    break;

   case 3:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_h.Qcp;
    break;

   case 4:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_h.Qcc;
    break;

   default:
    pos = ctrl_TAPM_P.NaN_Value_lq;
    break;
  }

  /* End of MultiPortSwitch: '<S83>/Controller chosen' */

  /* Sum: '<S83>/Sum' */
  ctrl_TAPM_B.Sum_i = (ctrl_TAPM_B.Inertiacompensation_f + ctrl_TAPM_B.Sum1_o) +
    pos;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S38>/Constant'
     *  Constant: '<S38>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_f = ctrl_TAPM_B.Sum_i -
      ctrl_TAPM_P.Constant_Value_i[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_dt;
    ctrl_TAPM_B.DiscreteTransferFcn_lz = ctrl_TAPM_P.Constant1_Value_h[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_f + ctrl_TAPM_P.Constant1_Value_h[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_dt;
  }

  /* Gain: '<S82>/Finding rotation speed' incorporates:
   *  Gain: '<S82>/K_omega'
   *  Sum: '<S82>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_ag = ((ctrl_TAPM_B.DiscreteTransferFcn_lz -
    ctrl_TAPM_B.Delay_a5) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_TAPM_B.Integrator_c) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S85>/Ki' */
    ctrl_TAPM_B.Ki_a = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S83>/Supervisor' incorporates:
     *  Constant: '<S83>/Switch controller'
     */
    ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_d, ctrl_TAPM_P.Thruster_control,
                         ctrl_TAPM_B.Delay_n[4], &ctrl_TAPM_B.sf_Supervisor_b);

    /* Delay: '<S39>/Delay' */
    ctrl_TAPM_B.Delay_h = ctrl_TAPM_DW.Delay_DSTATE_dv;

    /* Delay: '<S93>/Delay' */
    ctrl_TAPM_B.Delay_il = ctrl_TAPM_DW.Delay_DSTATE_m;
  }

  /* MATLAB Function: '<S93>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 6/Thruster control/MATLAB Function': '<S97>:1' */
  /* '<S97>:1:5' */
  if (rtb_sys[11] < 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = -1.0;
  } else if (rtb_sys[11] > 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = 1.0;
  } else if (rtb_sys[11] == 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_0 = rtb_sys[11];
  }

  pos = sqrt(fabs(rtb_sys[11]) / (ctrl_TAPM_P.Rho * rt_powd_snf(ctrl_TAPM_P.D,
    4.0) * ctrl_TAPM_P.Kt)) * rtb_TmpSignalConversionAtSFun_0;

  /* '<S97>:1:7' */
  rtb_Row1 = tanh(ctrl_TAPM_P.eps_c * pos / 27.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S97>:1:8' */
  /* '<S97>:1:10' */
  if (ctrl_TAPM_B.Delay_il < 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = -1.0;
  } else if (ctrl_TAPM_B.Delay_il > 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = 1.0;
  } else if (ctrl_TAPM_B.Delay_il == 0.0) {
    rtb_TmpSignalConversionAtSFun_0 = 0.0;
  } else {
    rtb_TmpSignalConversionAtSFun_0 = ctrl_TAPM_B.Delay_il;
  }

  rtb_T_r = ((1.0 - rtb_Row1) * ctrl_TAPM_P.Ktr + ctrl_TAPM_P.Kt * rtb_Row1) *
    rtb_TmpSignalConversionAtSFun_0 * ctrl_TAPM_P.Rho * rt_powd_snf
    (ctrl_TAPM_P.D, 4.0) * (ctrl_TAPM_B.Delay_il * ctrl_TAPM_B.Delay_il);
  ctrl_TAPM_B.n_d = pos;

  /* End of MATLAB Function: '<S93>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S93>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S93>/Constant1'
     *  Constant: '<S93>/Constant2'
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

    /* SampleTimeMath: '<S96>/TSamp'
     *
     * About '<S96>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_o = ctrl_TAPM_B.DiscreteTransferFcn_j *
      ctrl_TAPM_P.TSamp_WtEt_kk;

    /* Sum: '<S96>/Diff' incorporates:
     *  UnitDelay: '<S96>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_o - ctrl_TAPM_DW.UD_DSTATE_l;

    /* RateLimiter: '<S93>/Acceleration limiter' */
    pos = rtb_Sum_b - ctrl_TAPM_DW.PrevY_h;
    if (pos > ctrl_TAPM_P.Accelerationlimiter_RisingLi_bi) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_h +
        ctrl_TAPM_P.Accelerationlimiter_RisingLi_bi;
    } else {
      if (pos < ctrl_TAPM_P.Accelerationlimiter_FallingLi_p) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_h +
          ctrl_TAPM_P.Accelerationlimiter_FallingLi_p;
      }
    }

    ctrl_TAPM_DW.PrevY_h = rtb_Sum_b;

    /* End of RateLimiter: '<S93>/Acceleration limiter' */

    /* Gain: '<S93>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_e3 = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S93>/Sum1' incorporates:
     *  Gain: '<S93>/Qf_0'
     *  Gain: '<S93>/Qff_0(nr)'
     *  Gain: '<S93>/Qff_1(nr)'
     *  Trigonometry: '<S93>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_io = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_j) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_j;

    /* Memory: '<S93>/Memory' */
    ctrl_TAPM_B.Memory_o = ctrl_TAPM_DW.Memory_PreviousInput_a4;

    /* Sum: '<S95>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_j - ctrl_TAPM_B.Delay_n[5];

    /* Gain: '<S95>/Kp' */
    ctrl_TAPM_B.Kp_l = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S95>/Integrator' */
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

  /* MATLAB Function: '<S95>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay_n[5], ctrl_TAPM_P.Kt, ctrl_TAPM_P.Kq,
    ctrl_TAPM_P.D, rtb_T_r, ctrl_TAPM_P.eps, ctrl_TAPM_P.Rho, ctrl_TAPM_P.eps_c,
    ctrl_TAPM_P.Ktr, ctrl_TAPM_P.Kqr,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePower_nf);

  /* MultiPortSwitch: '<S93>/Controller chosen' incorporates:
   *  Constant: '<S93>/NaN'
   *  Sum: '<S95>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_o) {
   case 1:
    pos = ctrl_TAPM_B.Kp_l + rtb_Integrator_l;
    break;

   case 2:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePower_nf.Qcq;
    break;

   case 3:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePower_nf.Qcp;
    break;

   case 4:
    pos = ctrl_TAPM_B.sf_CorecontrollerTorquePower_nf.Qcc;
    break;

   default:
    pos = ctrl_TAPM_P.NaN_Value_j;
    break;
  }

  /* End of MultiPortSwitch: '<S93>/Controller chosen' */

  /* Sum: '<S93>/Sum' */
  ctrl_TAPM_B.Sum_f = (ctrl_TAPM_B.Inertiacompensation_e3 + ctrl_TAPM_B.Sum1_io)
    + pos;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S39>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S39>/Constant'
     *  Constant: '<S39>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_cw = ctrl_TAPM_B.Sum_f -
      ctrl_TAPM_P.Constant_Value_ht[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_o;
    ctrl_TAPM_B.DiscreteTransferFcn_ea = ctrl_TAPM_P.Constant1_Value_gs[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_cw + ctrl_TAPM_P.Constant1_Value_gs[1]
      * ctrl_TAPM_DW.DiscreteTransferFcn_states_o;
  }

  /* Gain: '<S92>/Finding rotation speed' incorporates:
   *  Gain: '<S92>/K_omega'
   *  Sum: '<S92>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_c = ((ctrl_TAPM_B.DiscreteTransferFcn_ea -
    ctrl_TAPM_B.Delay_h) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_TAPM_B.Integrator_m) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S95>/Ki' */
    ctrl_TAPM_B.Ki_p = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S93>/Supervisor' incorporates:
     *  Constant: '<S93>/Switch controller'
     */
    ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_o, ctrl_TAPM_P.Thruster_control,
                         ctrl_TAPM_B.Delay_n[5], &ctrl_TAPM_B.sf_Supervisor_e);

    /* SignalConversion: '<S8>/TmpSignal ConversionAtDelayInport1' */
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[0] = ctrl_TAPM_B.Integrator;
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[1] = ctrl_TAPM_B.Integrator_h;
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[2] = ctrl_TAPM_B.Integrator_a;
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[3] = ctrl_TAPM_B.Integrator_k;
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[4] = ctrl_TAPM_B.Integrator_c;
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[5] = ctrl_TAPM_B.Integrator_m;
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
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for Delay: '<S11>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE = ctrl_TAPM_B.Integrator_l;
  }

  /* Update for Iterator SubSystem: '<S7>/For Each Subsystem' */
  for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
    /* Update for ForEachSliceSelector: '<S25>/ImpSel_InsertedFor_reset_at_outport_0' */
    rtb_ImpSel_InsertedFor_reset_at = ctrl_TAPM_B.reset[ForEach_itr];
    if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
      /* Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
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

      /* End of Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */

      /* Update for Delay: '<S25>/Delay' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_TAPM_B.CoreSubsys[ForEach_itr].angle;
    }
  }

  /* End of Update for SubSystem: '<S7>/For Each Subsystem' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for Delay: '<S8>/Delay' */
    for (i = 0; i < 6; i++) {
      ctrl_TAPM_DW.Delay_DSTATE_i[i] =
        ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[i];
    }

    /* End of Update for Delay: '<S8>/Delay' */

    /* Update for Delay: '<S34>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_f = ctrl_TAPM_B.sf_ActualForceandTorque.Qa;

    /* Update for Delay: '<S43>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_fu = ctrl_TAPM_B.DiscreteTransferFcn;

    /* Update for DiscreteTransferFcn: '<S43>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp;

    /* Update for UnitDelay: '<S46>/UD' */
    ctrl_TAPM_DW.UD_DSTATE = ctrl_TAPM_B.TSamp;

    /* Update for Memory: '<S43>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput = ctrl_TAPM_B.sf_Supervisor.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S34>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_d =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a;

    /* Update for Delay: '<S35>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_b = ctrl_TAPM_B.sf_ActualForceandTorque_f.Qa;

    /* Update for Delay: '<S53>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_d = ctrl_TAPM_B.DiscreteTransferFcn_e;

    /* Update for DiscreteTransferFcn: '<S53>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_h[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_d;

    /* Update for UnitDelay: '<S56>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_n = ctrl_TAPM_B.TSamp_n;

    /* Update for Memory: '<S53>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_n = ctrl_TAPM_B.sf_Supervisor_h.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S35>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_m =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h;

    /* Update for Delay: '<S36>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_n = ctrl_TAPM_B.sf_ActualForceandTorque_h.Qa;

    /* Update for Delay: '<S63>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_no = ctrl_TAPM_B.DiscreteTransferFcn_f;

    /* Update for DiscreteTransferFcn: '<S63>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_j[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_e;

    /* Update for UnitDelay: '<S66>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_i = ctrl_TAPM_B.TSamp_k;

    /* Update for Memory: '<S63>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_d = ctrl_TAPM_B.sf_Supervisor_l.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_k =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_hh;

    /* Update for Delay: '<S37>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_e = ctrl_TAPM_B.sf_ActualForceandTorque_m.Qa;

    /* Update for Delay: '<S73>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_id = ctrl_TAPM_B.DiscreteTransferFcn_l;

    /* Update for DiscreteTransferFcn: '<S73>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_i[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_i[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_i[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_k;

    /* Update for UnitDelay: '<S76>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_n4 = ctrl_TAPM_B.TSamp_a;

    /* Update for Memory: '<S73>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_a = ctrl_TAPM_B.sf_Supervisor_n.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h0 =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_n;

    /* Update for Delay: '<S38>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_j = ctrl_TAPM_B.sf_ActualForceandTorque_o.Qa;

    /* Update for Delay: '<S83>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_a = ctrl_TAPM_B.DiscreteTransferFcn_o;

    /* Update for DiscreteTransferFcn: '<S83>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_c;

    /* Update for UnitDelay: '<S86>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_m = ctrl_TAPM_B.TSamp_m;

    /* Update for Memory: '<S83>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_b = ctrl_TAPM_B.sf_Supervisor_b.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_dt =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_f;

    /* Update for Delay: '<S39>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_dv = ctrl_TAPM_B.sf_ActualForceandTorque_j.Qa;

    /* Update for Delay: '<S93>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_m = ctrl_TAPM_B.DiscreteTransferFcn_j;

    /* Update for DiscreteTransferFcn: '<S93>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_l[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_l[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_l[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h4;

    /* Update for UnitDelay: '<S96>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_l = ctrl_TAPM_B.TSamp_o;

    /* Update for Memory: '<S93>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_a4 = ctrl_TAPM_B.sf_Supervisor_e.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S39>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_o =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_cw;
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
  XDot_ctrl_TAPM_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S12>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_TAPM_B.Sum3[0];
  _rtXdot->Integrator_CSTATE[1] = ctrl_TAPM_B.Sum3[1];
  _rtXdot->Integrator_CSTATE[2] = ctrl_TAPM_B.Sum3[2];

  /* Derivatives for Integrator: '<S12>/Integrator4' */
  _rtXdot->Integrator4_CSTATE[0] = ctrl_TAPM_B.Gain3[0];
  _rtXdot->Integrator4_CSTATE[1] = ctrl_TAPM_B.Gain3[1];
  _rtXdot->Integrator4_CSTATE[2] = ctrl_TAPM_B.Gain3[2];

  /* Derivatives for Integrator: '<S13>/Integrator' */
  _rtXdot->Integrator_CSTATE_l[0] = ctrl_TAPM_B.Sum1[0];
  _rtXdot->Integrator_CSTATE_l[1] = ctrl_TAPM_B.Sum1[1];

  /* Derivatives for TransferFcn: '<S13>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += ctrl_TAPM_P.TransferFcn2_A *
    ctrl_TAPM_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += ctrl_TAPM_B.Sum;

  /* Derivatives for Integrator: '<S12>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[0] = ctrl_TAPM_B.Sum7[0];
  _rtXdot->Integrator3_CSTATE[1] = ctrl_TAPM_B.Sum7[1];
  _rtXdot->Integrator3_CSTATE[2] = ctrl_TAPM_B.Sum7[2];

  /* Derivatives for Integrator: '<S42>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_c =
      ctrl_TAPM_B.Findingrotationspeed;
  }

  /* Derivatives for Integrator: '<S52>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_p =
      ctrl_TAPM_B.Findingrotationspeed_a;
  }

  /* Derivatives for Integrator: '<S62>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_k =
      ctrl_TAPM_B.Findingrotationspeed_m;
  }

  /* Derivatives for Integrator: '<S72>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_n =
      ctrl_TAPM_B.Findingrotationspeed_ms;
  }

  /* Derivatives for Integrator: '<S82>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_cd =
      ctrl_TAPM_B.Findingrotationspeed_ag;
  }

  /* Derivatives for Integrator: '<S92>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_h =
      ctrl_TAPM_B.Findingrotationspeed_c;
  }

  /* Derivatives for Integrator: '<S11>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_m =
      ctrl_TAPM_P.Constant_Value_c;
  }

  /* Derivatives for Integrator: '<S12>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ctrl_TAPM_B.Sum6[0];
  _rtXdot->Integrator1_CSTATE[1] = ctrl_TAPM_B.Sum6[1];
  _rtXdot->Integrator1_CSTATE[2] = ctrl_TAPM_B.Sum6[2];

  /* Derivatives for Integrator: '<S12>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_TAPM_B.psi_WF[0];
  _rtXdot->Integrator2_CSTATE[1] = ctrl_TAPM_B.psi_WF[1];
  _rtXdot->Integrator2_CSTATE[2] = ctrl_TAPM_B.psi_WF[2];

  /* Derivatives for Integrator: '<S45>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_e =
      ctrl_TAPM_B.Ki;
  }

  /* Derivatives for Integrator: '<S55>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_g =
      ctrl_TAPM_B.Ki_o;
  }

  /* Derivatives for Integrator: '<S65>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_i =
      ctrl_TAPM_B.Ki_n;
  }

  /* Derivatives for Integrator: '<S75>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_le =
      ctrl_TAPM_B.Ki_b;
  }

  /* Derivatives for Integrator: '<S85>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_n4 =
      ctrl_TAPM_B.Ki_a;
  }

  /* Derivatives for Integrator: '<S95>/Integrator' */
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

    /* Start for Iterator SubSystem: '<S7>/For Each Subsystem' */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].angle = 0.0;
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE = 0.0;
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].Delay = 0.0;
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI = 1U;
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 2;

      /* InitializeConditions for Delay: '<S25>/Delay' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_TAPM_P.CoreSubsys.Delay_InitialCondition;
    }

    /* End of Start for SubSystem: '<S7>/For Each Subsystem' */
  }

  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_o = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_ng = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_o3 = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_db = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_f = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_i3 = UNINITIALIZED_ZCSIG;

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    int32_T i;

    /* InitializeConditions for Delay: '<S11>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE = ctrl_TAPM_P.Delay_InitialCondition;

    /* InitializeConditions for Integrator: '<S12>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE[0] = ctrl_TAPM_P.Integrator_IC[0];
    ctrl_TAPM_X.Integrator_CSTATE[1] = ctrl_TAPM_P.Integrator_IC[1];
    ctrl_TAPM_X.Integrator_CSTATE[2] = ctrl_TAPM_P.Integrator_IC[2];

    /* InitializeConditions for Integrator: '<S12>/Integrator4' */
    ctrl_TAPM_X.Integrator4_CSTATE[0] = ctrl_TAPM_P.Integrator4_IC[0];
    ctrl_TAPM_X.Integrator4_CSTATE[1] = ctrl_TAPM_P.Integrator4_IC[1];
    ctrl_TAPM_X.Integrator4_CSTATE[2] = ctrl_TAPM_P.Integrator4_IC[2];

    /* InitializeConditions for MATLAB Function: '<S11>/MATLAB Function' */
    ctrl_TAPM_DW.controller = 1.0;
    ctrl_TAPM_DW.tmp = 0.0;

    /* InitializeConditions for Integrator: '<S13>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_l[0] = ctrl_TAPM_P.Integrator_IC_b[0];
    ctrl_TAPM_X.Integrator_CSTATE_l[1] = ctrl_TAPM_P.Integrator_IC_b[1];

    /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn2' */
    ctrl_TAPM_X.TransferFcn2_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S12>/Integrator3' */
    ctrl_TAPM_X.Integrator3_CSTATE[0] = ctrl_TAPM_P.Integrator3_IC;
    ctrl_TAPM_X.Integrator3_CSTATE[1] = ctrl_TAPM_P.Integrator3_IC;
    ctrl_TAPM_X.Integrator3_CSTATE[2] = ctrl_TAPM_P.Integrator3_IC;

    /* InitializeConditions for Iterator SubSystem: '<S7>/For Each Subsystem' */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      /* InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI = 1U;
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 2;

      /* InitializeConditions for Delay: '<S25>/Delay' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_TAPM_P.CoreSubsys.Delay_InitialCondition;
    }

    /* End of InitializeConditions for SubSystem: '<S7>/For Each Subsystem' */
    /* InitializeConditions for Integrator: '<S42>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_c = ctrl_TAPM_P.Integrator_IC_f;

    /* InitializeConditions for Integrator: '<S52>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_p = ctrl_TAPM_P.Integrator_IC_fg;

    /* InitializeConditions for Integrator: '<S62>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_k = ctrl_TAPM_P.Integrator_IC_p;

    /* InitializeConditions for Integrator: '<S72>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_n = ctrl_TAPM_P.Integrator_IC_fv;

    /* InitializeConditions for Integrator: '<S82>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_cd = ctrl_TAPM_P.Integrator_IC_l;

    /* InitializeConditions for Integrator: '<S92>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_h = ctrl_TAPM_P.Integrator_IC_li;

    /* InitializeConditions for Integrator: '<S11>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_m = ctrl_TAPM_P.Integrator_IC_e;

    /* InitializeConditions for Integrator: '<S12>/Integrator1' */
    ctrl_TAPM_X.Integrator1_CSTATE[0] = ctrl_TAPM_P.Integrator1_IC;
    ctrl_TAPM_X.Integrator1_CSTATE[1] = ctrl_TAPM_P.Integrator1_IC;
    ctrl_TAPM_X.Integrator1_CSTATE[2] = ctrl_TAPM_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<S12>/Integrator2' */
    ctrl_TAPM_X.Integrator2_CSTATE[0] = ctrl_TAPM_P.Integrator2_IC;
    ctrl_TAPM_X.Integrator2_CSTATE[1] = ctrl_TAPM_P.Integrator2_IC;
    ctrl_TAPM_X.Integrator2_CSTATE[2] = ctrl_TAPM_P.Integrator2_IC;

    /* InitializeConditions for Delay: '<S8>/Delay' */
    for (i = 0; i < 6; i++) {
      ctrl_TAPM_DW.Delay_DSTATE_i[i] = ctrl_TAPM_P.Delay_InitialCondition_j;
    }

    /* End of InitializeConditions for Delay: '<S8>/Delay' */

    /* InitializeConditions for Delay: '<S34>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_f = ctrl_TAPM_P.Delay_InitialCondition_i;

    /* InitializeConditions for Delay: '<S43>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_fu = ctrl_TAPM_P.Delay_InitialCondition_f;

    /* InitializeConditions for DiscreteTransferFcn: '<S43>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialStat;
    ctrl_TAPM_DW.DiscreteTransferFcn_states[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialStat;

    /* InitializeConditions for UnitDelay: '<S46>/UD' */
    ctrl_TAPM_DW.UD_DSTATE = ctrl_TAPM_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for RateLimiter: '<S43>/Acceleration Limit' */
    ctrl_TAPM_DW.PrevY = ctrl_TAPM_P.AccelerationLimit_IC;

    /* InitializeConditions for Memory: '<S43>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput = ctrl_TAPM_P.Memory_X0;

    /* InitializeConditions for Integrator: '<S45>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_e = ctrl_TAPM_P.Integrator_IC_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S34>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_d =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_h;

    /* InitializeConditions for Delay: '<S35>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_b = ctrl_TAPM_P.Delay_InitialCondition_l;

    /* InitializeConditions for Delay: '<S53>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_d = ctrl_TAPM_P.Delay_InitialCondition_iv;

    /* InitializeConditions for DiscreteTransferFcn: '<S53>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_hu;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_hu;

    /* InitializeConditions for UnitDelay: '<S56>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_n = ctrl_TAPM_P.DiscreteDerivative_ICPrevScal_p;

    /* InitializeConditions for RateLimiter: '<S53>/Acceleration Limit' */
    ctrl_TAPM_DW.PrevY_e = ctrl_TAPM_P.AccelerationLimit_IC_m;

    /* InitializeConditions for Memory: '<S53>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_n = ctrl_TAPM_P.Memory_X0_e;

    /* InitializeConditions for Integrator: '<S55>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_g = ctrl_TAPM_P.Integrator_IC_fy;

    /* InitializeConditions for DiscreteTransferFcn: '<S35>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_m =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_f;

    /* InitializeConditions for Delay: '<S36>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_n = ctrl_TAPM_P.Delay_InitialCondition_d;

    /* InitializeConditions for Delay: '<S63>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_no = ctrl_TAPM_P.Delay_InitialCondition_h;

    /* InitializeConditions for DiscreteTransferFcn: '<S63>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_a;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_j[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_a;

    /* InitializeConditions for UnitDelay: '<S66>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_i = ctrl_TAPM_P.DiscreteDerivative_ICPrevSca_pl;

    /* InitializeConditions for RateLimiter: '<S63>/Acceleration limiter' */
    ctrl_TAPM_DW.PrevY_o = ctrl_TAPM_P.Accelerationlimiter_IC;

    /* InitializeConditions for Memory: '<S63>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_d = ctrl_TAPM_P.Memory_X0_g;

    /* InitializeConditions for Integrator: '<S65>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_i = ctrl_TAPM_P.Integrator_IC_j;

    /* InitializeConditions for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_k =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_c;

    /* InitializeConditions for Delay: '<S37>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_e = ctrl_TAPM_P.Delay_InitialCondition_fb;

    /* InitializeConditions for Delay: '<S73>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_id = ctrl_TAPM_P.Delay_InitialCondition_g;

    /* InitializeConditions for DiscreteTransferFcn: '<S73>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_i[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_a1;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_i[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_a1;

    /* InitializeConditions for UnitDelay: '<S76>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_n4 = ctrl_TAPM_P.DiscreteDerivative_ICPrevScal_f;

    /* InitializeConditions for RateLimiter: '<S73>/Acceleration limiter' */
    ctrl_TAPM_DW.PrevY_c = ctrl_TAPM_P.Accelerationlimiter_IC_h;

    /* InitializeConditions for Memory: '<S73>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_a = ctrl_TAPM_P.Memory_X0_k;

    /* InitializeConditions for Integrator: '<S75>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_le = ctrl_TAPM_P.Integrator_IC_g;

    /* InitializeConditions for DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h0 =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_p;

    /* InitializeConditions for Delay: '<S38>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_j = ctrl_TAPM_P.Delay_InitialCondition_fv;

    /* InitializeConditions for Delay: '<S83>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_a = ctrl_TAPM_P.Delay_InitialCondition_dz;

    /* InitializeConditions for DiscreteTransferFcn: '<S83>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_e;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_e;

    /* InitializeConditions for UnitDelay: '<S86>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_m = ctrl_TAPM_P.DiscreteDerivative_ICPrevScal_o;

    /* InitializeConditions for RateLimiter: '<S83>/Acceleration limiter' */
    ctrl_TAPM_DW.PrevY_j = ctrl_TAPM_P.Accelerationlimiter_IC_i;

    /* InitializeConditions for Memory: '<S83>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_b = ctrl_TAPM_P.Memory_X0_k3;

    /* InitializeConditions for Integrator: '<S85>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_n4 = ctrl_TAPM_P.Integrator_IC_aj;

    /* InitializeConditions for DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_dt =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_pj;

    /* InitializeConditions for Delay: '<S39>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_dv = ctrl_TAPM_P.Delay_InitialCondition_fi;

    /* InitializeConditions for Delay: '<S93>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_m = ctrl_TAPM_P.Delay_InitialCondition_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S93>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_l[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_a4;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_l[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_a4;

    /* InitializeConditions for UnitDelay: '<S96>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_l = ctrl_TAPM_P.DiscreteDerivative_ICPrevScal_n;

    /* InitializeConditions for RateLimiter: '<S93>/Acceleration limiter' */
    ctrl_TAPM_DW.PrevY_h = ctrl_TAPM_P.Accelerationlimiter_IC_p;

    /* InitializeConditions for Memory: '<S93>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_a4 = ctrl_TAPM_P.Memory_X0_c;

    /* InitializeConditions for Integrator: '<S95>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_gj = ctrl_TAPM_P.Integrator_IC_h;

    /* InitializeConditions for DiscreteTransferFcn: '<S39>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_o =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_b;
  }
}

/* Model terminate function */
void ctrl_TAPM_terminate(void)
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
  ctrl_TAPM_M->Sizes.numContStates = (31);/* Number of continuous states */
  ctrl_TAPM_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_TAPM_M->Sizes.numY = (0);       /* Number of model outputs */
  ctrl_TAPM_M->Sizes.numU = (0);       /* Number of model inputs */
  ctrl_TAPM_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_TAPM_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_TAPM_M->Sizes.numBlocks = (427);/* Number of blocks */
  ctrl_TAPM_M->Sizes.numBlockIO = (186);/* Number of block outputs */
  ctrl_TAPM_M->Sizes.numBlockPrms = (687);/* Sum of parameter "widths" */
  return ctrl_TAPM_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_TAPM
 * Model version : 1.39
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Sun May 15 17:36:42 2016
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
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 39:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 40:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 41:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 44:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 46:
    return NIRT_GetValueByDataType(ptr,subindex,45,Complex);

   case 53:
    return NIRT_GetValueByDataType(ptr,subindex,52,Complex);

   case 61:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 62:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 63:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 64:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

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
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 38:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 39:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 40:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 41:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 44:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 46:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,45,Complex);

   case 53:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,52,Complex);

   case 61:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 62:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 63:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 64:
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

  // ctrl_TAPM/Input/wave_dir
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.wave_dir, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/fzp_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.fzp_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/fzp_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.fzp_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/r_max
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.r_max, 0, data[index++], 0, 0);
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

  // ctrl_TAPM/Thrust allocation1/reset
  if (TaskSampleHit[1]) {
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_B.reset, count, data[index++], 21, 0);
    }
  } else {
    index += 6;
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
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 31;
}

int32_t NumOutputPorts(void)
{
  return 35;
}

double ni_extout[35];

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
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.pwmthruster2, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.pwmthruster3, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.pwmthruster4, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.pwmthruster5, 0, 0,
      0);
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
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.pwmthruster6, 0, 0,
      0);
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
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 0, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/u_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 3, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/u_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 4, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/u_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 5, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/u_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 1, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/u_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 2, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.pwmthruster1, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/tau_actual: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.actual_tau, 0, 22,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.actual_tau, 1, 22,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.actual_tau, 2, 22,
      0);
  } else {
    index += 3;
  }

  // ctrl_TAPM/TAPM Controller w_observer/eta_est: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.eta, 0, 22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.eta, 1, 22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.eta, 2, 22, 0);
  } else {
    index += 3;
  }

  // ctrl_TAPM/TAPM Controller w_observer/nu_est: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.nu, 0, 25, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.nu, 1, 25, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.nu, 2, 25, 0);
  } else {
    index += 3;
  }

  // ctrl_TAPM/TAPM Controller w_observer/SP: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.TmpSignalConversionAtSPInport1, 0, 22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.TmpSignalConversionAtSPInport1, 1, 22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.TmpSignalConversionAtSPInport1, 2, 22, 0);
  } else {
    index += 3;
  }

  // ctrl_TAPM/TAPM Controller w_observer/tau_des: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.y, 0, 26, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.y, 1, 26, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.y, 2, 26, 0);
  } else {
    index += 3;
  }

  // ctrl_TAPM/TAPM Controller w_observer/LQR/controller: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.y_mz, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/TAPM Controller w_observer/LQR/timer: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Delay, 0, 0, 0);
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
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.pwmthruster2, 0, 0,
    0);

  // ctrl_TAPM/pwm_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.pwmthruster3, 0, 0,
    0);

  // ctrl_TAPM/pwm_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.pwmthruster4, 0, 0,
    0);

  // ctrl_TAPM/pwm_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.pwmthruster5, 0, 0,
    0);

  // ctrl_TAPM/alpha_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation2, 0, 0, 0);

  // ctrl_TAPM/pwm_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.pwmthruster6, 0, 0,
    0);

  // ctrl_TAPM/alpha_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation3, 0, 0, 0);

  // ctrl_TAPM/alpha_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation4, 0, 0, 0);

  // ctrl_TAPM/alpha_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation5, 0, 0, 0);

  // ctrl_TAPM/alpha_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation6, 0, 0, 0);

  // ctrl_TAPM/u_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 0, 21,
    0);

  // ctrl_TAPM/u_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 3, 21,
    0);

  // ctrl_TAPM/u_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 4, 21,
    0);

  // ctrl_TAPM/u_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 5, 21,
    0);

  // ctrl_TAPM/u_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 1, 21,
    0);

  // ctrl_TAPM/u_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation7, 2, 21,
    0);

  // ctrl_TAPM/pwm_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.pwmthruster1, 0, 0,
    0);

  // ctrl_TAPM/tau_actual: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.actual_tau, 0, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.actual_tau, 1, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.actual_tau, 2, 22, 0);

  // ctrl_TAPM/TAPM Controller w_observer/eta_est: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.eta, 0, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.eta, 1, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.eta, 2, 22, 0);

  // ctrl_TAPM/TAPM Controller w_observer/nu_est: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.nu, 0, 25, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.nu, 1, 25, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.nu, 2, 25, 0);

  // ctrl_TAPM/TAPM Controller w_observer/SP: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.TmpSignalConversionAtSPInport1, 0, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.TmpSignalConversionAtSPInport1, 1, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.TmpSignalConversionAtSPInport1, 2, 22, 0);

  // ctrl_TAPM/TAPM Controller w_observer/tau_des: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.y, 0, 26, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.y, 1, 26, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.y, 2, 26, 0);

  // ctrl_TAPM/TAPM Controller w_observer/LQR/controller: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.y_mz, 0, 0, 0);

  // ctrl_TAPM/TAPM Controller w_observer/LQR/timer: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Delay, 0, 0, 0);
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
  { 0, "ctrl_tapm/Thrust allocation1/C/Value", offsetof(P_ctrl_TAPM_T, C), 29,
    24, 2, 0, 0 },

  { 1, "ctrl_tapm/Parameters From initfile distributed /D/Value", offsetof
    (P_ctrl_TAPM_T, D), 61, 1, 2, 2, 0 },

  { 2,
    "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 61, 1, 2, 4, 0 },

  { 3,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 61, 1, 2, 6, 0 },

  { 4,
    "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 61, 1, 2, 8, 0 },

  { 5,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 61, 1, 2, 10, 0 },

  { 6,
    "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 61, 1, 2, 12, 0 },

  { 7,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 61, 1, 2, 14, 0 },

  { 8,
    "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 61, 1, 2, 16, 0 },

  { 9,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 61, 1, 2, 18, 0 },

  { 10,
    "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 61, 1, 2, 20, 0 },

  { 11,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 61, 1, 2, 22, 0 },

  { 12,
    "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 61, 1, 2, 24, 0 },

  { 13,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 61, 1, 2, 26, 0 },

  { 14, "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 61, 1, 2, 28, 0 },

  { 15, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 61, 1, 2, 30, 0 },

  { 16, "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 61, 1, 2, 32, 0 },

  { 17, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 61, 1, 2, 34, 0 },

  { 18, "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 61, 1, 2, 36, 0 },

  { 19, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 61, 1, 2, 38, 0 },

  { 20, "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 61, 1, 2, 40, 0 },

  { 21, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 61, 1, 2, 42, 0 },

  { 22, "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 61, 1, 2, 44, 0 },

  { 23, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 61, 1, 2, 46, 0 },

  { 24, "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 61, 1, 2, 48, 0 },

  { 25, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 61, 1, 2, 50, 0 },

  { 26,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 61, 1, 2, 52, 0 },

  { 27,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 61, 1, 2, 54, 0 },

  { 28,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 61, 1, 2, 56, 0 },

  { 29,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 61, 1, 2, 58, 0 },

  { 30,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 61, 1, 2, 60, 0 },

  { 31,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 61, 1, 2, 62, 0 },

  { 32,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 61, 1, 2, 64, 0 },

  { 33,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 61, 1, 2, 66, 0 },

  { 34,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 61, 1, 2, 68, 0 },

  { 35,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 61, 1, 2, 70, 0 },

  { 36,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 61, 1, 2, 72, 0 },

  { 37,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 61, 1, 2, 74, 0 },

  { 38, "ctrl_tapm/Parameters From initfile distributed /Kq/Value", offsetof
    (P_ctrl_TAPM_T, Kq), 61, 1, 2, 76, 0 },

  { 39, "ctrl_tapm/Parameters From initfile distributed /Kqr/Value", offsetof
    (P_ctrl_TAPM_T, Kqr), 61, 1, 2, 78, 0 },

  { 40, "ctrl_tapm/Parameters From initfile distributed /Kt/Value", offsetof
    (P_ctrl_TAPM_T, Kt), 61, 1, 2, 80, 0 },

  { 41, "ctrl_tapm/Parameters From initfile distributed /Ktr/Value", offsetof
    (P_ctrl_TAPM_T, Ktr), 61, 1, 2, 82, 0 },

  { 42,
    "ctrl_tapm/Thrust allocation1/For Each Subsystem/Max Rotation Rate/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_rotation), 61, 1, 2, 84, 0 },

  { 43,
    "ctrl_tapm/Thrust allocation1/For Each Subsystem/Max Rotation Rate/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Max_rotation), 61, 1, 2, 86, 0 },

  { 44, "ctrl_tapm/Thruster control /Subsystem/Saturation 1/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 88, 0 },

  { 45, "ctrl_tapm/Thruster control /Subsystem/Saturation 1/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 90, 0 },

  { 46, "ctrl_tapm/Thruster control /Subsystem/Saturation 2/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 92, 0 },

  { 47, "ctrl_tapm/Thruster control /Subsystem/Saturation 2/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 94, 0 },

  { 48, "ctrl_tapm/Thruster control /Subsystem/Saturation 3/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 96, 0 },

  { 49, "ctrl_tapm/Thruster control /Subsystem/Saturation 3/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 98, 0 },

  { 50, "ctrl_tapm/Thruster control /Subsystem/Saturation 4/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 100, 0 },

  { 51, "ctrl_tapm/Thruster control /Subsystem/Saturation 4/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 102, 0 },

  { 52, "ctrl_tapm/Thruster control /Subsystem/Saturation 5/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 104, 0 },

  { 53, "ctrl_tapm/Thruster control /Subsystem/Saturation 5/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 106, 0 },

  { 54, "ctrl_tapm/Thruster control /Subsystem/Saturation 6/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 108, 0 },

  { 55, "ctrl_tapm/Thruster control /Subsystem/Saturation 6/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 110, 0 },

  { 56, "ctrl_tapm/Thruster control /Subsystem/Saturation 7/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 112, 0 },

  { 57, "ctrl_tapm/Thruster control /Subsystem/Saturation 7/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 61, 1, 2, 114, 0 },

  { 58, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 61, 1, 2, 116, 0 },

  { 59, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 61, 1, 2, 118, 0 },

  { 60, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 61, 1, 2, 120, 0 },

  { 61, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 61, 1, 2, 122, 0 },

  { 62, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 61, 1, 2, 124, 0 },

  { 63, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 61, 1, 2, 126, 0 },

  { 64, "ctrl_tapm/Parameters From initfile distributed /Rho/Value", offsetof
    (P_ctrl_TAPM_T, Rho), 61, 1, 2, 128, 0 },

  { 65,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_TAPM_T, Thruster_control), 61, 1, 2, 130, 0 },

  { 66,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_TAPM_T, Thruster_control), 61, 1, 2, 132, 0 },

  { 67,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_TAPM_T, Thruster_control), 61, 1, 2, 134, 0 },

  { 68,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_TAPM_T, Thruster_control), 61, 1, 2, 136, 0 },

  { 69,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_TAPM_T, Thruster_control), 61, 1, 2, 138, 0 },

  { 70,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_TAPM_T, Thruster_control), 61, 1, 2, 140, 0 },

  { 71, "ctrl_tapm/Thrust allocation1/Switch  Azimuth//Fixed angles/Value",
    offsetof(P_ctrl_TAPM_T, Thruster_lock), 61, 1, 2, 142, 0 },

  { 72, "ctrl_tapm/Parameters From initfile distributed /Constant4/Value",
    offsetof(P_ctrl_TAPM_T, eps), 61, 1, 2, 144, 0 },

  { 73, "ctrl_tapm/Thrust allocation1/Constant to avoid singularities/Value",
    offsetof(P_ctrl_TAPM_T, eps), 61, 1, 2, 146, 0 },

  { 74, "ctrl_tapm/Parameters From initfile distributed /Constant/Value",
    offsetof(P_ctrl_TAPM_T, eps_c), 61, 1, 2, 148, 0 },

  { 75, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 61, 1, 2, 150, 0 },

  { 76, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 61, 1, 2, 152, 0 },

  { 77, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 61, 1, 2, 154, 0 },

  { 78, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 61, 1, 2, 156, 0 },

  { 79, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 61, 1, 2, 158, 0 },

  { 80, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 61, 1, 2, 160, 0 },

  { 81, "ctrl_tapm/Parameters From initfile distributed /Constant1/Value",
    offsetof(P_ctrl_TAPM_T, k_cc), 61, 1, 2, 162, 0 },

  { 82, "ctrl_tapm/Parameters From initfile distributed /Constant5/Value",
    offsetof(P_ctrl_TAPM_T, n_c), 61, 1, 2, 164, 0 },

  { 83, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 61, 1, 2, 166, 0 },

  { 84, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 61, 1, 2, 168, 0 },

  { 85, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 61, 1, 2, 170, 0 },

  { 86, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 61, 1, 2, 172, 0 },

  { 87, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 61, 1, 2, 174, 0 },

  { 88, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 61, 1, 2, 176, 0 },

  { 89, "ctrl_tapm/Parameters From initfile distributed /Constant2/Value",
    offsetof(P_ctrl_TAPM_T, p_cc), 61, 1, 2, 178, 0 },

  { 90, "ctrl_tapm/Parameters From initfile distributed /Constant3/Value",
    offsetof(P_ctrl_TAPM_T, r_cc), 61, 1, 2, 180, 0 },

  { 91, "ctrl_tapm/Thruster control /Subsystem/pwm thruster 1/Coefs", offsetof
    (P_ctrl_TAPM_T, thrust_to_pwm_coeff), 34, 6, 2, 182, 0 },

  { 92, "ctrl_tapm/Thruster control /Subsystem/pwm thruster 2/Coefs", offsetof
    (P_ctrl_TAPM_T, thrust_to_pwm_coeff), 34, 6, 2, 184, 0 },

  { 93, "ctrl_tapm/Thruster control /Subsystem/pwm thruster 3/Coefs", offsetof
    (P_ctrl_TAPM_T, thrust_to_pwm_coeff), 34, 6, 2, 186, 0 },

  { 94, "ctrl_tapm/Thruster control /Subsystem/pwm thruster 4/Coefs", offsetof
    (P_ctrl_TAPM_T, thrust_to_pwm_coeff), 34, 6, 2, 188, 0 },

  { 95, "ctrl_tapm/Thruster control /Subsystem/pwm thruster 5/Coefs", offsetof
    (P_ctrl_TAPM_T, thrust_to_pwm_coeff), 34, 6, 2, 190, 0 },

  { 96, "ctrl_tapm/Thruster control /Subsystem/pwm thruster 6/Coefs", offsetof
    (P_ctrl_TAPM_T, thrust_to_pwm_coeff), 34, 6, 2, 192, 0 },

  { 97,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain6/Gain",
    offsetof(P_ctrl_TAPM_T, Nonlinearpassiveobserver_D), 36, 9, 2, 194, 0 },

  { 98,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScaled), 61, 1, 2, 196, 0 },

  { 99,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScal_p), 61, 1, 2, 198, 0 },

  { 100,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevSca_pl), 61, 1, 2, 200, 0 },

  { 101,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScal_f), 61, 1, 2, 202, 0 },

  { 102,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScal_o), 61, 1, 2, 204, 0 },

  { 103,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScal_n), 61, 1, 2, 206, 0 },

  { 104,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /K3/Gain",
    offsetof(P_ctrl_TAPM_T, Nonlinearpassiveobserver_K3), 36, 9, 2, 208, 0 },

  { 105,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /K4/Gain",
    offsetof(P_ctrl_TAPM_T, Nonlinearpassiveobserver_K4), 36, 9, 2, 210, 0 },

  { 106,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /K2/Gain",
    offsetof(P_ctrl_TAPM_T, Nonlinearpassiveobserver_w_c), 36, 9, 2, 212, 0 },

  { 107, "ctrl_tapm/TAPM Controller w_observer/LQR/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition), 61, 1, 2, 214, 0 },

  { 108,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC), 25, 3, 2, 216, 0 },

  { 109,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator4/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator4_IC), 25, 3, 2, 218, 0 },

  { 110,
    "ctrl_tapm/TAPM Controller w_observer/SP Generator/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_b), 37, 2, 2, 220, 0 },

  { 111, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Transfer Fcn2/A",
    offsetof(P_ctrl_TAPM_T, TransferFcn2_A), 61, 1, 2, 222, 0 },

  { 112, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Transfer Fcn2/C",
    offsetof(P_ctrl_TAPM_T, TransferFcn2_C), 61, 1, 2, 224, 0 },

  { 113,
    "ctrl_tapm/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_UpperSat), 61, 1, 2, 226, 0 },

  { 114,
    "ctrl_tapm/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_LowerSat), 61, 1, 2, 228, 0 },

  { 115,
    "ctrl_tapm/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain), 61, 1, 2, 230, 0 },

  { 116,
    "ctrl_tapm/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_TAPM_T, Constant_Value), 61, 1, 2, 232, 0 },

  { 117,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator3/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator3_IC), 61, 1, 2, 234, 0 },

  { 118, "ctrl_tapm/Thrust allocation1/Radians to Degrees/Gain/Gain", offsetof
    (P_ctrl_TAPM_T, Gain_Gain_o), 61, 1, 2, 236, 0 },

  { 119, "ctrl_tapm/Thrust allocation1/X-position Thruster/Value", offsetof
    (P_ctrl_TAPM_T, XpositionThruster_Value), 34, 6, 2, 238, 0 },

  { 120, "ctrl_tapm/Thrust allocation1/Y-position Thruster/Value", offsetof
    (P_ctrl_TAPM_T, YpositionThruster_Value), 34, 6, 2, 240, 0 },

  { 121, "ctrl_tapm/Thrust allocation1/constant angle/Value", offsetof
    (P_ctrl_TAPM_T, constantangle_Value), 34, 6, 2, 242, 0 },

  { 122,
    "ctrl_tapm/Thrust allocation1/Choosing Fixed // Azimuth angle/Threshold",
    offsetof(P_ctrl_TAPM_T, ChoosingFixedAzimuthangle_Thres), 61, 1, 2, 244, 0 },

  { 123, "ctrl_tapm/Thruster control /Subsystem1/Saturation 1/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation1_UpperSat), 61, 1, 2, 246, 0 },

  { 124, "ctrl_tapm/Thruster control /Subsystem1/Saturation 1/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation1_LowerSat), 61, 1, 2, 248, 0 },

  { 125,
    "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_f), 61, 1, 2, 250, 0 },

  { 126, "ctrl_tapm/Thruster control /Thruster 1/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value), 61, 1, 2, 252, 0 },

  { 127,
    "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_fg), 61, 1, 2, 254, 0 },

  { 128, "ctrl_tapm/Thruster control /Thruster 2/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_k), 61, 1, 2, 256, 0 },

  { 129,
    "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_p), 61, 1, 2, 258, 0 },

  { 130, "ctrl_tapm/Thruster control /Thruster 3/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_n), 61, 1, 2, 260, 0 },

  { 131,
    "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_fv), 61, 1, 2, 262, 0 },

  { 132, "ctrl_tapm/Thruster control /Thruster 4/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_d), 61, 1, 2, 264, 0 },

  { 133,
    "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_l), 61, 1, 2, 266, 0 },

  { 134, "ctrl_tapm/Thruster control /Thruster 5/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_f), 61, 1, 2, 268, 0 },

  { 135,
    "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_li), 61, 1, 2, 270, 0 },

  { 136, "ctrl_tapm/Thruster control /Thruster 6/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_h), 61, 1, 2, 272, 0 },

  { 137, "ctrl_tapm/Thruster control /Subsystem/Constant12/Value", offsetof
    (P_ctrl_TAPM_T, Constant12_Value), 61, 1, 2, 274, 0 },

  { 138, "ctrl_tapm/Thruster control /Subsystem1/Saturation 2/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation2_UpperSat), 61, 1, 2, 276, 0 },

  { 139, "ctrl_tapm/Thruster control /Subsystem1/Saturation 2/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation2_LowerSat), 61, 1, 2, 278, 0 },

  { 140, "ctrl_tapm/Thruster control /Subsystem1/Saturation 3/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation3_UpperSat), 61, 1, 2, 280, 0 },

  { 141, "ctrl_tapm/Thruster control /Subsystem1/Saturation 3/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation3_LowerSat), 61, 1, 2, 282, 0 },

  { 142, "ctrl_tapm/Thruster control /Subsystem1/Saturation 4/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation4_UpperSat), 61, 1, 2, 284, 0 },

  { 143, "ctrl_tapm/Thruster control /Subsystem1/Saturation 4/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation4_LowerSat), 61, 1, 2, 286, 0 },

  { 144, "ctrl_tapm/Thruster control /Subsystem1/Saturation 5/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation5_UpperSat), 61, 1, 2, 288, 0 },

  { 145, "ctrl_tapm/Thruster control /Subsystem1/Saturation 5/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation5_LowerSat), 61, 1, 2, 290, 0 },

  { 146, "ctrl_tapm/Thruster control /Subsystem1/Saturation 6/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation6_UpperSat), 61, 1, 2, 292, 0 },

  { 147, "ctrl_tapm/Thruster control /Subsystem1/Saturation 6/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation6_LowerSat), 61, 1, 2, 294, 0 },

  { 148, "ctrl_tapm/Radians to Degrees/Gain/Gain", offsetof(P_ctrl_TAPM_T,
    Gain_Gain_f), 61, 1, 2, 296, 0 },

  { 149, "ctrl_tapm/X-position Thruster/Value", offsetof(P_ctrl_TAPM_T,
    XpositionThruster_Value_e), 34, 6, 2, 298, 0 },

  { 150, "ctrl_tapm/Y-position Thruster/Value", offsetof(P_ctrl_TAPM_T,
    YpositionThruster_Value_o), 34, 6, 2, 300, 0 },

  { 151, "ctrl_tapm/TAPM Controller w_observer/LQR/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_c), 61, 1, 2, 302, 0 },

  { 152, "ctrl_tapm/TAPM Controller w_observer/LQR/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_e), 61, 1, 2, 304, 0 },

  { 153,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator1/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator1_IC), 61, 1, 2, 306, 0 },

  { 154,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain1/Gain",
    offsetof(P_ctrl_TAPM_T, Gain1_Gain), 36, 9, 2, 308, 0 },

  { 155,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator2/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator2_IC), 61, 1, 2, 310, 0 },

  { 156,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain2/Gain",
    offsetof(P_ctrl_TAPM_T, Gain2_Gain), 36, 9, 2, 312, 0 },

  { 157,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain3/Gain",
    offsetof(P_ctrl_TAPM_T, Gain3_Gain), 36, 9, 2, 314, 0 },

  { 158,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /K11/Gain",
    offsetof(P_ctrl_TAPM_T, K11_Gain), 36, 9, 2, 316, 0 },

  { 159,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /K12/Gain",
    offsetof(P_ctrl_TAPM_T, K12_Gain), 36, 9, 2, 318, 0 },

  { 160,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /inv(T_b)/Gain",
    offsetof(P_ctrl_TAPM_T, invT_b_Gain), 36, 9, 2, 320, 0 },

  { 161, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value), 61, 1, 2, 322, 0 },

  { 162, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Gain/Gain", offsetof
    (P_ctrl_TAPM_T, Gain_Gain_d), 38, 4, 2, 324, 0 },

  { 163, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Gain1/Gain",
    offsetof(P_ctrl_TAPM_T, Gain1_Gain_i), 38, 4, 2, 326, 0 },

  { 164, "ctrl_tapm/Input/deg2rad/Gain", offsetof(P_ctrl_TAPM_T, deg2rad_Gain),
    61, 1, 2, 328, 0 },

  { 165, "ctrl_tapm/Thruster control /Delay/InitialCondition", offsetof
    (P_ctrl_TAPM_T, Delay_InitialCondition_j), 61, 1, 2, 330, 0 },

  { 166, "ctrl_tapm/Thruster control /Thruster 1/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_cs), 37, 2, 2, 332, 0 },

  { 167, "ctrl_tapm/Thruster control /Thruster 1/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_k), 37, 2, 2, 334, 0 },

  { 168, "ctrl_tapm/Thruster control /Thruster 1/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_i), 61, 1, 2, 336, 0 },

  { 169,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_f), 61, 1, 2, 338, 0 },

  { 170,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_o), 26, 3, 2, 340, 0 },

  { 171,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value), 26, 3, 2, 342, 0 },

  { 172,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialStat), 61, 1, 2, 344, 0 },

  { 173,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt), 0, 1, 2, 346, 0 },

  { 174,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_RisingLim), 0, 1, 2, 348, 0 },

  { 175,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_FallingLim), 0, 1, 2, 350, 0 },

  { 176,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_IC), 61, 1, 2, 352, 0 },

  { 177, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0), 61, 1, 2, 354, 0 },

  { 178,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_a), 61, 1, 2, 356, 0 },

  { 179, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value), 61, 1, 2, 358, 0 },

  { 180,
    "ctrl_tapm/Thruster control /Thruster 1/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_h), 61, 1, 2, 360, 0 },

  { 181, "ctrl_tapm/Thruster control /Thruster 2/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_h), 37, 2, 2, 362, 0 },

  { 182, "ctrl_tapm/Thruster control /Thruster 2/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_j), 37, 2, 2, 364, 0 },

  { 183, "ctrl_tapm/Thruster control /Thruster 2/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_l), 61, 1, 2, 366, 0 },

  { 184,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_iv), 61, 1, 2, 368, 0 },

  { 185,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_b), 26, 3, 2, 370, 0 },

  { 186,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_i), 26, 3, 2, 372, 0 },

  { 187,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialS_hu), 61, 1, 2, 374, 0 },

  { 188,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_k), 0, 1, 2, 376, 0 },

  { 189,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_RisingLim_n), 0, 1, 2, 378, 0 },

  { 190,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_FallingLim_n), 0, 1, 2, 380, 0 },

  { 191,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_IC_m), 61, 1, 2, 382, 0 },

  { 192, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_e), 61, 1, 2, 384, 0 },

  { 193,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_fy), 61, 1, 2, 386, 0 },

  { 194, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_l), 61, 1, 2, 388, 0 },

  { 195,
    "ctrl_tapm/Thruster control /Thruster 2/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_f), 61, 1, 2, 390, 0 },

  { 196, "ctrl_tapm/Thruster control /Thruster 3/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_n), 37, 2, 2, 392, 0 },

  { 197, "ctrl_tapm/Thruster control /Thruster 3/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_a), 37, 2, 2, 394, 0 },

  { 198, "ctrl_tapm/Thruster control /Thruster 3/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_d), 61, 1, 2, 396, 0 },

  { 199,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_h), 61, 1, 2, 398, 0 },

  { 200,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_g), 26, 3, 2, 400, 0 },

  { 201,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_h), 26, 3, 2, 402, 0 },

  { 202,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_a), 61, 1, 2, 404, 0 },

  { 203,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_m), 0, 1, 2, 406, 0 },

  { 204,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_RisingLim), 0, 1, 2, 408, 0 },

  { 205,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_FallingLim), 0, 1, 2, 410, 0 },

  { 206,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_IC), 61, 1, 2, 412, 0 },

  { 207, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_g), 61, 1, 2, 414, 0 },

  { 208,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_j), 61, 1, 2, 416, 0 },

  { 209, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_g), 61, 1, 2, 418, 0 },

  { 210,
    "ctrl_tapm/Thruster control /Thruster 3/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_c), 61, 1, 2, 420, 0 },

  { 211, "ctrl_tapm/Thruster control /Thruster 4/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_j), 37, 2, 2, 422, 0 },

  { 212, "ctrl_tapm/Thruster control /Thruster 4/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_oi), 37, 2, 2, 424, 0 },

  { 213, "ctrl_tapm/Thruster control /Thruster 4/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_fb), 61, 1, 2, 426, 0 },

  { 214,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_g), 61, 1, 2, 428, 0 },

  { 215,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_m), 26, 3, 2, 430, 0 },

  { 216,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_l), 26, 3, 2, 432, 0 },

  { 217,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialS_a1), 61, 1, 2, 434, 0 },

  { 218,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_h), 0, 1, 2, 436, 0 },

  { 219,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_RisingLim_e), 0, 1, 2, 438, 0 },

  { 220,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_FallingLi_b), 0, 1, 2, 440, 0 },

  { 221,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_IC_h), 61, 1, 2, 442, 0 },

  { 222, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_k), 61, 1, 2, 444, 0 },

  { 223,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_g), 61, 1, 2, 446, 0 },

  { 224, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_p), 61, 1, 2, 448, 0 },

  { 225,
    "ctrl_tapm/Thruster control /Thruster 4/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_p), 61, 1, 2, 450, 0 },

  { 226, "ctrl_tapm/Thruster control /Thruster 5/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_i), 37, 2, 2, 452, 0 },

  { 227, "ctrl_tapm/Thruster control /Thruster 5/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_h), 37, 2, 2, 454, 0 },

  { 228, "ctrl_tapm/Thruster control /Thruster 5/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_fv), 61, 1, 2, 456, 0 },

  { 229,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_dz), 61, 1, 2, 458, 0 },

  { 230,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_mk), 26, 3, 2, 460, 0 },

  { 231,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_p), 26, 3, 2, 462, 0 },

  { 232,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_e), 61, 1, 2, 464, 0 },

  { 233,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_o), 0, 1, 2, 466, 0 },

  { 234,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_RisingLim_b), 0, 1, 2, 468, 0 },

  { 235,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_FallingLi_d), 0, 1, 2, 470, 0 },

  { 236,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_IC_i), 61, 1, 2, 472, 0 },

  { 237, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_k3), 61, 1, 2, 474, 0 },

  { 238,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_aj), 61, 1, 2, 476, 0 },

  { 239, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_lq), 61, 1, 2, 478, 0 },

  { 240,
    "ctrl_tapm/Thruster control /Thruster 5/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialS_pj), 61, 1, 2, 480, 0 },

  { 241, "ctrl_tapm/Thruster control /Thruster 6/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_ht), 37, 2, 2, 482, 0 },

  { 242, "ctrl_tapm/Thruster control /Thruster 6/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_gs), 37, 2, 2, 484, 0 },

  { 243, "ctrl_tapm/Thruster control /Thruster 6/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_fi), 61, 1, 2, 486, 0 },

  { 244,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_a), 61, 1, 2, 488, 0 },

  { 245,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_oa), 26, 3, 2, 490, 0 },

  { 246,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_p3), 26, 3, 2, 492, 0 },

  { 247,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialS_a4), 61, 1, 2, 494, 0 },

  { 248,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_kk), 0, 1, 2, 496, 0 },

  { 249,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_RisingLi_bi), 0, 1, 2, 498, 0 },

  { 250,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_FallingLi_p), 0, 1, 2, 500, 0 },

  { 251,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_IC_p), 61, 1, 2, 502, 0 },

  { 252, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_c), 61, 1, 2, 504, 0 },

  { 253,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_h), 61, 1, 2, 506, 0 },

  { 254, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_j), 61, 1, 2, 508, 0 },

  { 255,
    "ctrl_tapm/Thruster control /Thruster 6/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_b), 61, 1, 2, 510, 0 },

  { 256, "ctrl_tapm/TAPM Controller w_observer/LQR/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength), 62, 1, 2, 512, 0 },

  { 257, "ctrl_tapm/Thruster control /Delay/DelayLength", offsetof(P_ctrl_TAPM_T,
    Delay_DelayLength_m), 62, 1, 2, 514, 0 },

  { 258, "ctrl_tapm/Thruster control /Thruster 1/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_d), 62, 1, 2, 516, 0 },

  { 259,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_f), 62, 1, 2, 518, 0 },

  { 260, "ctrl_tapm/Thruster control /Thruster 2/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_m5), 62, 1, 2, 520, 0 },

  { 261,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_p), 62, 1, 2, 522, 0 },

  { 262, "ctrl_tapm/Thruster control /Thruster 3/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_h), 62, 1, 2, 524, 0 },

  { 263,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_b), 62, 1, 2, 526, 0 },

  { 264, "ctrl_tapm/Thruster control /Thruster 4/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_n), 62, 1, 2, 528, 0 },

  { 265,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_mj), 62, 1, 2, 530, 0 },

  { 266, "ctrl_tapm/Thruster control /Thruster 5/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_a), 62, 1, 2, 532, 0 },

  { 267,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_k), 62, 1, 2, 534, 0 },

  { 268, "ctrl_tapm/Thruster control /Thruster 6/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_l), 62, 1, 2, 536, 0 },

  { 269,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_c), 62, 1, 2, 538, 0 },

  { 270,
    "ctrl_tapm/Thrust allocation1/For Each Subsystem/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_TAPM_T, CoreSubsys.DiscreteTimeIntegrator_gainval), 0, 1, 2,
    540, 0 },

  { 271,
    "ctrl_tapm/Thrust allocation1/For Each Subsystem/Degrees to Radians/Gain1/Gain",
    offsetof(P_ctrl_TAPM_T, CoreSubsys.Gain1_Gain), 61, 1, 2, 542, 0 },

  { 272,
    "ctrl_tapm/Thrust allocation1/For Each Subsystem/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, CoreSubsys.Delay_InitialCondition), 61, 1, 2, 544, 0
  },

  { 273, "ctrl_tapm/Thrust allocation1/For Each Subsystem/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, CoreSubsys.Delay_DelayLength), 62, 1, 2, 546, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 274;
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
  1, 6,                                /* Parameter at index 91 */
  1, 6,                                /* Parameter at index 92 */
  1, 6,                                /* Parameter at index 93 */
  1, 6,                                /* Parameter at index 94 */
  1, 6,                                /* Parameter at index 95 */
  1, 6,                                /* Parameter at index 96 */
  3, 3,                                /* Parameter at index 97 */
  1, 1,                                /* Parameter at index 98 */
  1, 1,                                /* Parameter at index 99 */
  1, 1,                                /* Parameter at index 100 */
  1, 1,                                /* Parameter at index 101 */
  1, 1,                                /* Parameter at index 102 */
  1, 1,                                /* Parameter at index 103 */
  3, 3,                                /* Parameter at index 104 */
  3, 3,                                /* Parameter at index 105 */
  3, 3,                                /* Parameter at index 106 */
  1, 1,                                /* Parameter at index 107 */
  3, 1,                                /* Parameter at index 108 */
  3, 1,                                /* Parameter at index 109 */
  1, 2,                                /* Parameter at index 110 */
  1, 1,                                /* Parameter at index 111 */
  1, 1,                                /* Parameter at index 112 */
  1, 1,                                /* Parameter at index 113 */
  1, 1,                                /* Parameter at index 114 */
  1, 1,                                /* Parameter at index 115 */
  1, 1,                                /* Parameter at index 116 */
  1, 1,                                /* Parameter at index 117 */
  1, 1,                                /* Parameter at index 118 */
  1, 6,                                /* Parameter at index 119 */
  1, 6,                                /* Parameter at index 120 */
  1, 6,                                /* Parameter at index 121 */
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
  1, 6,                                /* Parameter at index 149 */
  1, 6,                                /* Parameter at index 150 */
  1, 1,                                /* Parameter at index 151 */
  1, 1,                                /* Parameter at index 152 */
  1, 1,                                /* Parameter at index 153 */
  3, 3,                                /* Parameter at index 154 */
  1, 1,                                /* Parameter at index 155 */
  3, 3,                                /* Parameter at index 156 */
  3, 3,                                /* Parameter at index 157 */
  3, 3,                                /* Parameter at index 158 */
  3, 3,                                /* Parameter at index 159 */
  3, 3,                                /* Parameter at index 160 */
  1, 1,                                /* Parameter at index 161 */
  2, 2,                                /* Parameter at index 162 */
  2, 2,                                /* Parameter at index 163 */
  1, 1,                                /* Parameter at index 164 */
  1, 1,                                /* Parameter at index 165 */
  1, 2,                                /* Parameter at index 166 */
  1, 2,                                /* Parameter at index 167 */
  1, 1,                                /* Parameter at index 168 */
  1, 1,                                /* Parameter at index 169 */
  1, 3,                                /* Parameter at index 170 */
  1, 3,                                /* Parameter at index 171 */
  1, 1,                                /* Parameter at index 172 */
  1, 1,                                /* Parameter at index 173 */
  1, 1,                                /* Parameter at index 174 */
  1, 1,                                /* Parameter at index 175 */
  1, 1,                                /* Parameter at index 176 */
  1, 1,                                /* Parameter at index 177 */
  1, 1,                                /* Parameter at index 178 */
  1, 1,                                /* Parameter at index 179 */
  1, 1,                                /* Parameter at index 180 */
  1, 2,                                /* Parameter at index 181 */
  1, 2,                                /* Parameter at index 182 */
  1, 1,                                /* Parameter at index 183 */
  1, 1,                                /* Parameter at index 184 */
  1, 3,                                /* Parameter at index 185 */
  1, 3,                                /* Parameter at index 186 */
  1, 1,                                /* Parameter at index 187 */
  1, 1,                                /* Parameter at index 188 */
  1, 1,                                /* Parameter at index 189 */
  1, 1,                                /* Parameter at index 190 */
  1, 1,                                /* Parameter at index 191 */
  1, 1,                                /* Parameter at index 192 */
  1, 1,                                /* Parameter at index 193 */
  1, 1,                                /* Parameter at index 194 */
  1, 1,                                /* Parameter at index 195 */
  1, 2,                                /* Parameter at index 196 */
  1, 2,                                /* Parameter at index 197 */
  1, 1,                                /* Parameter at index 198 */
  1, 1,                                /* Parameter at index 199 */
  1, 3,                                /* Parameter at index 200 */
  1, 3,                                /* Parameter at index 201 */
  1, 1,                                /* Parameter at index 202 */
  1, 1,                                /* Parameter at index 203 */
  1, 1,                                /* Parameter at index 204 */
  1, 1,                                /* Parameter at index 205 */
  1, 1,                                /* Parameter at index 206 */
  1, 1,                                /* Parameter at index 207 */
  1, 1,                                /* Parameter at index 208 */
  1, 1,                                /* Parameter at index 209 */
  1, 1,                                /* Parameter at index 210 */
  1, 2,                                /* Parameter at index 211 */
  1, 2,                                /* Parameter at index 212 */
  1, 1,                                /* Parameter at index 213 */
  1, 1,                                /* Parameter at index 214 */
  1, 3,                                /* Parameter at index 215 */
  1, 3,                                /* Parameter at index 216 */
  1, 1,                                /* Parameter at index 217 */
  1, 1,                                /* Parameter at index 218 */
  1, 1,                                /* Parameter at index 219 */
  1, 1,                                /* Parameter at index 220 */
  1, 1,                                /* Parameter at index 221 */
  1, 1,                                /* Parameter at index 222 */
  1, 1,                                /* Parameter at index 223 */
  1, 1,                                /* Parameter at index 224 */
  1, 1,                                /* Parameter at index 225 */
  1, 2,                                /* Parameter at index 226 */
  1, 2,                                /* Parameter at index 227 */
  1, 1,                                /* Parameter at index 228 */
  1, 1,                                /* Parameter at index 229 */
  1, 3,                                /* Parameter at index 230 */
  1, 3,                                /* Parameter at index 231 */
  1, 1,                                /* Parameter at index 232 */
  1, 1,                                /* Parameter at index 233 */
  1, 1,                                /* Parameter at index 234 */
  1, 1,                                /* Parameter at index 235 */
  1, 1,                                /* Parameter at index 236 */
  1, 1,                                /* Parameter at index 237 */
  1, 1,                                /* Parameter at index 238 */
  1, 1,                                /* Parameter at index 239 */
  1, 1,                                /* Parameter at index 240 */
  1, 2,                                /* Parameter at index 241 */
  1, 2,                                /* Parameter at index 242 */
  1, 1,                                /* Parameter at index 243 */
  1, 1,                                /* Parameter at index 244 */
  1, 3,                                /* Parameter at index 245 */
  1, 3,                                /* Parameter at index 246 */
  1, 1,                                /* Parameter at index 247 */
  1, 1,                                /* Parameter at index 248 */
  1, 1,                                /* Parameter at index 249 */
  1, 1,                                /* Parameter at index 250 */
  1, 1,                                /* Parameter at index 251 */
  1, 1,                                /* Parameter at index 252 */
  1, 1,                                /* Parameter at index 253 */
  1, 1,                                /* Parameter at index 254 */
  1, 1,                                /* Parameter at index 255 */
  1, 1,                                /* Parameter at index 256 */
  1, 1,                                /* Parameter at index 257 */
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
  1, 1,                                /* Parameter at index 268 */
  1, 1,                                /* Parameter at index 269 */
  1, 1,                                /* Parameter at index 270 */
  1, 1,                                /* Parameter at index 271 */
  1, 1,                                /* Parameter at index 272 */
  1, 1,                                /* Parameter at index 273 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_tapm/TAPM Controller w_observer/LQR/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_tapm/Input/wave_dir", 0, "", offsetof(B_ctrl_TAPM_T, wave_dir) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_tapm/Input/fzp_x", 0, "", offsetof(B_ctrl_TAPM_T, fzp_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "ctrl_tapm/Input/fzp_y", 0, "", offsetof(B_ctrl_TAPM_T, fzp_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "ctrl_tapm/Input/r_max", 0, "", offsetof(B_ctrl_TAPM_T, r_max) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator",
    0, "eta(1, 1)", offsetof(B_ctrl_TAPM_T, eta) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 6,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator",
    0, "eta(1, 2)", offsetof(B_ctrl_TAPM_T, eta) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 7,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator",
    0, "eta(1, 3)", offsetof(B_ctrl_TAPM_T, eta) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 8,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator4",
    0, "nu(1, 1)", offsetof(B_ctrl_TAPM_T, nu) + (0*sizeof(real_T)), BLOCKIO_SIG,
    25, 1, 2, 0, 0 },

  { 9,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator4",
    0, "nu(2, 1)", offsetof(B_ctrl_TAPM_T, nu) + (1*sizeof(real_T)), BLOCKIO_SIG,
    25, 1, 2, 0, 0 },

  { 10,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator4",
    0, "nu(3, 1)", offsetof(B_ctrl_TAPM_T, nu) + (2*sizeof(real_T)), BLOCKIO_SIG,
    25, 1, 2, 0, 0 },

  { 11, "ctrl_tapm/Thruster measurment/thr_angle_1", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 12, "ctrl_tapm/Thruster measurment/thr_angle_2", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 13, "ctrl_tapm/Thruster measurment/thr_angle_3", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 14, "ctrl_tapm/Thruster measurment/thr_angle_4", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 15, "ctrl_tapm/Thruster measurment/thr_angle_5", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 16, "ctrl_tapm/Thruster measurment/thr_angle_6", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 17, "ctrl_tapm/Thrust allocation1/Choosing Fixed // Azimuth angle/(1, 1)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 18, "ctrl_tapm/Thrust allocation1/Choosing Fixed // Azimuth angle/(1, 2)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 19, "ctrl_tapm/Thrust allocation1/Choosing Fixed // Azimuth angle/(1, 3)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 20, "ctrl_tapm/Thrust allocation1/Choosing Fixed // Azimuth angle/(1, 4)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 21, "ctrl_tapm/Thrust allocation1/Choosing Fixed // Azimuth angle/(1, 5)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 22, "ctrl_tapm/Thrust allocation1/Choosing Fixed // Azimuth angle/(1, 6)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 23, "ctrl_tapm/Thrust allocation1/reset/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 24, "ctrl_tapm/Thrust allocation1/reset/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 25, "ctrl_tapm/Thrust allocation1/reset/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 26, "ctrl_tapm/Thrust allocation1/reset/(1, 4)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset) + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 27, "ctrl_tapm/Thrust allocation1/reset/(1, 5)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset) + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 28, "ctrl_tapm/Thrust allocation1/reset/(1, 6)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset) + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 29, "ctrl_tapm/Thruster control /Subsystem1/Saturation 1", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 30, "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 31, "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/Integrator", 0,
    "", offsetof(B_ctrl_TAPM_T, Integrator) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 32, "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 33, "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/Integrator", 0,
    "", offsetof(B_ctrl_TAPM_T, Integrator_h) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 34, "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 35, "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/Integrator", 0,
    "", offsetof(B_ctrl_TAPM_T, Integrator_a) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 36, "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 37, "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/Integrator", 0,
    "", offsetof(B_ctrl_TAPM_T, Integrator_k) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 38, "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 39, "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/Integrator", 0,
    "", offsetof(B_ctrl_TAPM_T, Integrator_c) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 40, "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 41, "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/Integrator", 0,
    "", offsetof(B_ctrl_TAPM_T, Integrator_m) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 42, "ctrl_tapm/Thruster control /Subsystem/pwm thruster 2", 0, "", offsetof
    (B_ctrl_TAPM_T, pwmthruster2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 43, "ctrl_tapm/Thruster control /Subsystem/pwm thruster 3", 0, "", offsetof
    (B_ctrl_TAPM_T, pwmthruster3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 44, "ctrl_tapm/Thruster control /Subsystem/pwm thruster 4", 0, "", offsetof
    (B_ctrl_TAPM_T, pwmthruster4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 45, "ctrl_tapm/Thruster control /Subsystem/pwm thruster 5", 0, "", offsetof
    (B_ctrl_TAPM_T, pwmthruster5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 46, "ctrl_tapm/Thruster control /Subsystem1/Saturation 2", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 47, "ctrl_tapm/Thruster control /Subsystem/pwm thruster 6", 0, "", offsetof
    (B_ctrl_TAPM_T, pwmthruster6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 48, "ctrl_tapm/Thruster control /Subsystem1/Saturation 3", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 49, "ctrl_tapm/Thruster control /Subsystem1/Saturation 4", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 50, "ctrl_tapm/Thruster control /Subsystem1/Saturation 5", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 51, "ctrl_tapm/Thruster control /Subsystem1/Saturation 6", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 52, "ctrl_tapm/Thruster control /Subsystem/Saturation 7/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM_T, Saturation7) + (0*sizeof(real_T)), BLOCKIO_SIG, 21,
    1, 2, 0, 0 },

  { 53, "ctrl_tapm/Thruster control /Subsystem/Saturation 7/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM_T, Saturation7) + (1*sizeof(real_T)), BLOCKIO_SIG, 21,
    1, 2, 0, 0 },

  { 54, "ctrl_tapm/Thruster control /Subsystem/Saturation 7/(1, 3)", 0, "",
    offsetof(B_ctrl_TAPM_T, Saturation7) + (2*sizeof(real_T)), BLOCKIO_SIG, 21,
    1, 2, 0, 0 },

  { 55, "ctrl_tapm/Thruster control /Subsystem/Saturation 7/(1, 4)", 0, "",
    offsetof(B_ctrl_TAPM_T, Saturation7) + (3*sizeof(real_T)), BLOCKIO_SIG, 21,
    1, 2, 0, 0 },

  { 56, "ctrl_tapm/Thruster control /Subsystem/Saturation 7/(1, 5)", 0, "",
    offsetof(B_ctrl_TAPM_T, Saturation7) + (4*sizeof(real_T)), BLOCKIO_SIG, 21,
    1, 2, 0, 0 },

  { 57, "ctrl_tapm/Thruster control /Subsystem/Saturation 7/(1, 6)", 0, "",
    offsetof(B_ctrl_TAPM_T, Saturation7) + (5*sizeof(real_T)), BLOCKIO_SIG, 21,
    1, 2, 0, 0 },

  { 58, "ctrl_tapm/Thruster control /Subsystem/pwm thruster 1", 0, "", offsetof
    (B_ctrl_TAPM_T, pwmthruster1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 59, "ctrl_tapm/Radians to Degrees/Gain/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 60, "ctrl_tapm/Radians to Degrees/Gain/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 61, "ctrl_tapm/Radians to Degrees/Gain/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 62, "ctrl_tapm/Radians to Degrees/Gain/(1, 4)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 63, "ctrl_tapm/Radians to Degrees/Gain/(1, 5)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 64, "ctrl_tapm/Radians to Degrees/Gain/(1, 6)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 65, "ctrl_tapm/Pos measurements/x_m", 0, "", offsetof(B_ctrl_TAPM_T, x_m) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 66, "ctrl_tapm/Pos measurements/y_m", 0, "", offsetof(B_ctrl_TAPM_T, y_m) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 67, "ctrl_tapm/Pos measurements/psi_m", 0, "", offsetof(B_ctrl_TAPM_T, psi_m)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 68, "ctrl_tapm/TAPM Controller w_observer/LQR/Integrator", 0, "", offsetof
    (B_ctrl_TAPM_T, Integrator_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 69,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain3/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Gain3) + (0*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 70,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain3/(2, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Gain3) + (1*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 71,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain3/(3, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Gain3) + (2*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 72,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum3/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum3) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 73,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum3/(1, 2)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum3) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 74,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum3/(1, 3)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum3) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 75, "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum5",
    0, "psi_WF(1, 1)", offsetof(B_ctrl_TAPM_T, psi_WF) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 76, "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum5",
    0, "psi_WF(2, 1)", offsetof(B_ctrl_TAPM_T, psi_WF) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 77, "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum5",
    0, "psi_WF(3, 1)", offsetof(B_ctrl_TAPM_T, psi_WF) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 78,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum6/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum6) + (0*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 79,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum6/(2, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum6) + (1*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 80,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum6/(3, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum6) + (2*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 81,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum7/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum7) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 82,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum7/(1, 2)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum7) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 83,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum7/(1, 3)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum7) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 84, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Sum", 0, "", offsetof
    (B_ctrl_TAPM_T, Sum) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 85, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Sum1/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 86, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Sum1/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0,
    0 },

  { 87, "ctrl_tapm/Thruster control /Delay/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 88, "ctrl_tapm/Thruster control /Delay/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_n) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 89, "ctrl_tapm/Thruster control /Delay/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_n) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 90, "ctrl_tapm/Thruster control /Delay/(1, 4)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_n) + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 91, "ctrl_tapm/Thruster control /Delay/(1, 5)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_n) + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 92, "ctrl_tapm/Thruster control /Delay/(1, 6)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_n) + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 93, "ctrl_tapm/Thruster control /Thruster 1/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 94, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 95,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 96,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 97,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 98, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 99, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 100,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 101,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_kk) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 102, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 103, "ctrl_tapm/Thruster control /Thruster 1/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 104,
    "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 105,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 106, "ctrl_tapm/Thruster control /Thruster 2/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 107, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_bs) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 108,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 109,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 110,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 111, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_nn) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 112, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 113,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 114,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 115, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 116, "ctrl_tapm/Thruster control /Thruster 2/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 117,
    "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 118,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 119, "ctrl_tapm/Thruster control /Thruster 3/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 120, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_by) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 121,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 122,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 123,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 124, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 125, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 126,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 127,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_j2) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 128, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_hf) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 129, "ctrl_tapm/Thruster control /Thruster 3/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 130,
    "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 131,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 132, "ctrl_tapm/Thruster control /Thruster 4/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_g) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 133, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 134,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 135,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 136,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 137, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 138, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 139,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 140,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 141, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_k2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 142, "ctrl_tapm/Thruster control /Thruster 4/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 143,
    "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_ms) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 144,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 145, "ctrl_tapm/Thruster control /Thruster 5/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_a5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 146, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_id) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 147,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 148,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_m) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 149,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 150, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 151, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 152,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 153,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 154, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 155, "ctrl_tapm/Thruster control /Thruster 5/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_lz) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 156,
    "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_ag) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 157,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 158, "ctrl_tapm/Thruster control /Thruster 6/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 159, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_il) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 160,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 161,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 162,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_e3) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 163, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_io) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 164, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 165,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 166,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_om) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 167, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 168, "ctrl_tapm/Thruster control /Thruster 6/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_ea) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 169,
    "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 170,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 171,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, n_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 172,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, n_d_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 173, "ctrl_tapm/TAPM Controller w_observer/LQR/MATLAB Function2", 0,
    "(1, 1)", offsetof(B_ctrl_TAPM_T, y) + (0*sizeof(real_T)), BLOCKIO_SIG, 26,
    1, 2, 0, 0 },

  { 174, "ctrl_tapm/TAPM Controller w_observer/LQR/MATLAB Function2", 0,
    "(1, 2)", offsetof(B_ctrl_TAPM_T, y) + (1*sizeof(real_T)), BLOCKIO_SIG, 26,
    1, 2, 0, 0 },

  { 175, "ctrl_tapm/TAPM Controller w_observer/LQR/MATLAB Function2", 0,
    "(1, 3)", offsetof(B_ctrl_TAPM_T, y) + (2*sizeof(real_T)), BLOCKIO_SIG, 26,
    1, 2, 0, 0 },

  { 176, "ctrl_tapm/TAPM Controller w_observer/LQR/MATLAB Function", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 177, "ctrl_tapm/TAPM Controller w_observer/LQR/MATLAB Function", 1, "",
    offsetof(B_ctrl_TAPM_T, y_mz) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 178, "ctrl_tapm/MATLAB Function", 0, "(1, 1)", offsetof(B_ctrl_TAPM_T,
    actual_tau) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 179, "ctrl_tapm/MATLAB Function", 0, "(1, 2)", offsetof(B_ctrl_TAPM_T,
    actual_tau) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 180, "ctrl_tapm/MATLAB Function", 0, "(1, 3)", offsetof(B_ctrl_TAPM_T,
    actual_tau) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 181, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_e.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 182,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_nf.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 183,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_nf.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 184,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_nf.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 185,
    "ctrl_tapm/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_j.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 186,
    "ctrl_tapm/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_j.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 187, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_b.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 188,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_j.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 189,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/MATLAB Function", 1,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_j.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 190,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_h.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 191,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_h.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 192,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_h.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 193,
    "ctrl_tapm/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_o.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 194,
    "ctrl_tapm/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_o.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 195, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_n.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 196,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_go.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 197,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/MATLAB Function", 1,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_go.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 198,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_n3.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 199,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_n3.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 200,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_n3.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 201,
    "ctrl_tapm/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_m.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 202,
    "ctrl_tapm/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_m.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 203, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_l.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 204,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_m.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 205,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/MATLAB Function", 1,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_m.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 206,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_n.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 207,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_n.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 208,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_n.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 209,
    "ctrl_tapm/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_h.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 210,
    "ctrl_tapm/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_h.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 211, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_h.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 212,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_i.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 213,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/MATLAB Function", 1,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_i.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 214,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_o.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 215,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_o.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 216,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_o.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 217,
    "ctrl_tapm/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_f.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 218,
    "ctrl_tapm/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_f.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 219, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 220,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowerand.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 221,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowerand.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 222,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowerand.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 223,
    "ctrl_tapm/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 224,
    "ctrl_tapm/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 225,
    "ctrl_tapm/Thrust allocation1/For Each Subsystem/Discrete-Time Integrator",
    0, "angle", offsetof(B_ctrl_TAPM_T, CoreSubsys[5].angle) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 226, "ctrl_tapm/Thrust allocation1/For Each Subsystem/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, CoreSubsys[5].Delay) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 227, "ctrl_tapm/Thrust allocation1/For Each Subsystem/Max Rotation Rate", 0,
    "", offsetof(B_ctrl_TAPM_T, CoreSubsys[5].MaxRotationRate) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 228;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 51;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Input/wave_dir", 0, EXT_IN, 1, 1, 1 },

  { 2, "Input/fzp_x", 0, EXT_IN, 1, 1, 1 },

  { 3, "Input/fzp_y", 0, EXT_IN, 1, 1, 1 },

  { 4, "Input/r_max", 0, EXT_IN, 1, 1, 1 },

  { 5, "Thruster measurment/thr_angle_1", 0, EXT_IN, 1, 1, 1 },

  { 6, "Thruster measurment/thr_angle_2", 0, EXT_IN, 1, 1, 1 },

  { 7, "Thruster measurment/thr_angle_3", 0, EXT_IN, 1, 1, 1 },

  { 8, "Thruster measurment/thr_angle_4", 0, EXT_IN, 1, 1, 1 },

  { 9, "Thruster measurment/thr_angle_5", 0, EXT_IN, 1, 1, 1 },

  { 10, "Thruster measurment/thr_angle_6", 0, EXT_IN, 1, 1, 1 },

  { 11, "Thrust allocation1/reset", 1, EXT_IN, 6, 6, 1 },

  { 12, "Thruster control /Thruster 1/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 13, "Thruster control /Thruster 2/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 14, "Thruster control /Thruster 3/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 15, "Thruster control /Thruster 4/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 16, "Thruster control /Thruster 5/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 17, "Thruster control /Thruster 6/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 18, "Pos measurements/x_m", 0, EXT_IN, 1, 1, 1 },

  { 19, "Pos measurements/y_m", 0, EXT_IN, 1, 1, 1 },

  { 20, "Pos measurements/psi_m", 0, EXT_IN, 1, 1, 1 },

  { 21, "Thruster control /Thruster 1/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 22, "Thruster control /Thruster 2/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 23, "Thruster control /Thruster 3/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 24, "Thruster control /Thruster 4/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 25, "Thruster control /Thruster 5/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 26, "Thruster control /Thruster 6/Thruster control/Core controller/reset", 0,
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

  { 19, "tau_actual", 0, EXT_OUT, 3, 3, 1 },

  { 20, "TAPM Controller w_observer/eta_est", 0, EXT_OUT, 3, 3, 1 },

  { 21, "TAPM Controller w_observer/nu_est", 0, EXT_OUT, 3, 3, 1 },

  { 22, "TAPM Controller w_observer/SP", 0, EXT_OUT, 3, 3, 1 },

  { 23, "TAPM Controller w_observer/tau_des", 0, EXT_OUT, 3, 3, 1 },

  { 24, "TAPM Controller w_observer/LQR/controller", 0, EXT_OUT, 1, 1, 1 },

  { 25, "TAPM Controller w_observer/LQR/timer", 1, EXT_OUT, 1, 1, 1 },

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
static const char* NI_CompiledModelVersion = "1.39";
static const char* NI_CompiledModelDateTime = "Sun May 15 17:36:42 2016";
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
      *numContStates = 31;
      *numDiscStates = 669.0;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator4_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator4_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator4_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_l),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_l),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.TransferFcn2_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "TransferFcn2_CSTATE");
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
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_m),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_m");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_e),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_g),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_i),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_i");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_le),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_le");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_n4),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_n4");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_gj),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_gj");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE");
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_i,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_i");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_f, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_f");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_fu, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_fu");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states, 0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states, 1, 23, 0);
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
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_h, 0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_h, 1, 23, 0);
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
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_j, 0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_j, 1, 23, 0);
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_id, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.Delay_DSTATE_id");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_i, 0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_i, 1, 23, 0);
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
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb, 0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb, 1, 23, 0);
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
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_l, 0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_l, 1, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_l");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_l, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.UD_DSTATE_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_o");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.wave_dir_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.wave_dir_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.fzp_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.fzp_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.fzp_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.fzp_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.r_max_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.r_max_DWORK1");
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
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1");
    }

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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK1, 0,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK1, 1,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK1, 2,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.x_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.y_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.psi_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_est_DWORK1, 0,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_est_DWORK1, 1,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_est_DWORK1, 2,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.nu_est_DWORK1, 0, 22,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.nu_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.nu_est_DWORK1, 1, 22,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.nu_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.nu_est_DWORK1, 2, 22,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.nu_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.SP_DWORK1, 0, 22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.SP_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.SP_DWORK1, 1, 22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.SP_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.SP_DWORK1, 2, 22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.SP_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_des_DWORK1, 0,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_des_DWORK1, 1,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_des_DWORK1, 2,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.controller_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.controller_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.timer_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.timer_DWORK1");
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
      (&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.PrevY_e, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.PrevY_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.Memory_PreviousInput_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.Memory_PreviousInput_n");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_l, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK1_l");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.controller, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.controller");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tmp, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tmp");
    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.wave_dir_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.wave_dir_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.fzp_x_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.fzp_x_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.fzp_y_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.fzp_y_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.r_max_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.r_max_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_1_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_2_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_3_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_4_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_5_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_6_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_1_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_j,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_j");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_o,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_o");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_i,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_i");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_k,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_k");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_a,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_a");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_m,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_m");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_2_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_3_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_4_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_5_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_2_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_6_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_3_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_4_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_5_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_6_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_1_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_4_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_5_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_6_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_2_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_3_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_1_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_actual_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.x_m_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.x_m_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.y_m_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.y_m_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.psi_m_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_est_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_est_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.nu_est_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.nu_est_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.SP_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.SP_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_des_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_des_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.controller_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.controller_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.timer_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.timer_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_n,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_n");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_e,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_e");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_l,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_l");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_mb,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_mb");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_nu,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_nu");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_f,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_f");
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
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator4_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator4_CSTATE), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator4_CSTATE), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_l), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_l), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.TransferFcn2_CSTATE), 0,
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
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_m), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator1_CSTATE), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator2_CSTATE), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_e), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_g), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_i), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_le), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_n4), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_gj), 0,
      contStates[idx++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE, 0, discStates[idx++], 0,
      0);
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_i, count,
        discStates[idx++], 21, 0);
    }

    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_f, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_fu, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_b, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_d, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_h, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_h, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_n, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_n, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_no, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_j, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_j, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_i, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_e, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_id, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_i, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_i, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_n4, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_h0, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_j, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_a, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_m, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_dt, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_dv, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_m, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_l, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_l, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_l, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_o, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.wave_dir_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.fzp_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.fzp_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.r_max_DWORK1, 0, discStates[idx++], 0,
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
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1, count, discStates[idx
        ++], 21, 0);
    }

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
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK1, 2, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.x_m_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.y_m_DWORK1, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.psi_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_est_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_est_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_est_DWORK1, 2, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.nu_est_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.nu_est_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.nu_est_DWORK1, 2, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.SP_DWORK1, 0, discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.SP_DWORK1, 1, discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.SP_DWORK1, 2, discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_des_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_des_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_des_DWORK1, 2, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.controller_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.timer_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.PrevY, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_ec, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_tmp_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.PrevY_e, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Memory_PreviousInput_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK1_l, 0, discStates[idx++],
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
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.controller, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.tmp, 0, discStates[idx++], 0, 0);
    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.wave_dir_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.fzp_x_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.fzp_y_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.r_max_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_1_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_2_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_3_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_4_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_5_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_6_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_1_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_j, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_o, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_i, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_k, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_a, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_m, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_2_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_3_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_4_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_5_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_2_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_6_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_3_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_4_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_5_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_6_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_1_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_4_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_5_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_6_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_2_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_3_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_1_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.x_m_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.y_m_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.psi_m_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_est_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.nu_est_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.SP_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_des_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.controller_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.timer_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_n, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_e, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_l, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_mb, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_nu, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_f, count,
        discStates[idx++], 24, 0);
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
