/*
 * ctrl_TAPM.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_TAPM".
 *
 * Model version              : 1.145
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Fri Jul 08 20:12:54 2016
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
static real_T ctrl_TAPM_eml_xnrm2_p(int32_T n, const real_T x[6], int32_T ix0);
static void ctrl_TAPM_eml_xaxpy_bg(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[18], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_b(int32_T n, real_T a, const real_T x[18],
  int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_TAPM_eml_xscal(real_T a, real_T x[9], int32_T ix0);
static void ctrl_TAPM_eml_xscal_b(real_T a, real_T x[36], int32_T ix0);
static void ctrl_TAPM_eml_xswap(real_T x[36], int32_T ix0, int32_T iy0);
static void ctrl_TAPM_eml_xswap_m(real_T x[9], int32_T ix0, int32_T iy0);
static void ctrl_TAPM_eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void ctrl_TAPM_eml_xrot(real_T x[36], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static void ctrl_TAPM_eml_xrot_o(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static real_T ctrl_TAPM_eml_xdotc_ik(int32_T n, const real_T x[36], int32_T ix0,
  const real_T y[36], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_bg2a(int32_T n, real_T a, int32_T ix0, real_T y
  [36], int32_T iy0);
static real_T ctrl_TAPM_eml_xdotc_i(int32_T n, const real_T x[9], int32_T ix0,
  const real_T y[9], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_bg2(int32_T n, real_T a, int32_T ix0, real_T y[9],
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
static real_T ctrl_TAPM_eml_xnrm2_pt(int32_T n, const real_T x[36], int32_T ix0);
static real_T ctrl_TAPM_eml_xnrm2_ptp(int32_T n, const real_T x[12], int32_T ix0);
static void ctrl_TAPM_eml_xaxpy_bg2arnk(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[36], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_bg2arn(int32_T n, real_T a, const real_T x[36],
  int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_TAPM_eml_xscal_bd(real_T a, real_T x[144], int32_T ix0);
static void ctrl_TAPM_eml_xswap_mw(real_T x[144], int32_T ix0, int32_T iy0);
static void ctrl_TAPM_eml_xrot_o5(real_T x[144], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static real_T ctrl_TAPM_eml_xdotc_ikmz(int32_T n, const real_T x[144], int32_T
  ix0, const real_T y[144], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_bg2arnka(int32_T n, real_T a, int32_T ix0,
  real_T y[144], int32_T iy0);
static real_T ctrl_TAPM_eml_xdotc_ikm(int32_T n, const real_T x[36], int32_T ix0,
  const real_T y[36], int32_T iy0);
static void ctrl_TAPM_eml_xaxpy_bg2ar(int32_T n, real_T a, int32_T ix0, real_T
  y[36], int32_T iy0);
static void ctrl_TAPM_eml_xgesvd_g(const real_T A[36], real_T U[9], real_T S[3],
  real_T V[36]);
static void ctrl_TAPM_svd_j(const real_T A[36], real_T U[9], real_T S[9], real_T
  V[36]);
static void ctrl_TAPM_abs(const real_T x[2], real_T y[2]);
static void ctrl_TAPM_cosd(real_T *x);
static void ctrl_TAPM_sind(real_T *x);
static void ctrl_TAPM_cosd_g(real_T *x);
static void ctrl_TAPM_sind_c(real_T *x);

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
  int_T nXc = 37;
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
 * Output and update for atomic system:
 *    '<S2>/MATLAB Function'
 *    '<S2>/MATLAB Function4'
 */
void ctrl_TAPM_MATLABFunction(real_T rtu_K_p1, real_T rtu_K_p1_n, real_T
  rtu_K_p1_f, B_MATLABFunction_ctrl_TAPM_T *localB)
{
  /* MATLAB Function 'Input/MATLAB Function': '<S10>:1' */
  /* '<S10>:1:4' */
  memset(&localB->K_p[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S10>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_p[0] = rtu_K_p1;
  localB->K_p[4] = rtu_K_p1_n;
  localB->K_p[8] = rtu_K_p1_f;
}

/*
 * Output and update for atomic system:
 *    '<S2>/MATLAB Function1'
 *    '<S2>/MATLAB Function5'
 */
void ctrl_TAPM_MATLABFunction1(real_T rtu_K_i1, real_T rtu_K_i1_j, real_T
  rtu_K_i1_l, B_MATLABFunction1_ctrl_TAPM_T *localB)
{
  /* MATLAB Function 'Input/MATLAB Function1': '<S11>:1' */
  /* '<S11>:1:4' */
  memset(&localB->K_i[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S11>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_i[0] = rtu_K_i1;
  localB->K_i[4] = rtu_K_i1_j;
  localB->K_i[8] = rtu_K_i1_l;
}

/*
 * Output and update for atomic system:
 *    '<S2>/MATLAB Function2'
 *    '<S2>/MATLAB Function6'
 */
void ctrl_TAPM_MATLABFunction2(real_T rtu_K_d1, real_T rtu_K_d1_p, real_T
  rtu_K_d1_b, B_MATLABFunction2_ctrl_TAPM_T *localB)
{
  /* MATLAB Function 'Input/MATLAB Function2': '<S12>:1' */
  /* '<S12>:1:4' */
  memset(&localB->K_d[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S12>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_d[0] = rtu_K_d1;
  localB->K_d[4] = rtu_K_d1_p;
  localB->K_d[8] = rtu_K_d1_b;
}

/*
 * Output and update for atomic system:
 *    '<S49>/MATLAB Function2'
 *    '<S49>/MATLAB Function3'
 *    '<S49>/MATLAB Function4'
 *    '<S49>/MATLAB Function5'
 *    '<S49>/MATLAB Function6'
 */
void ctrl_TAPM_MATLABFunction2_i(real_T rtu_Tc_in1, real_T rtu_signal, real_T
  rtu_Tc_in2, B_MATLABFunction2_ctrl_TAPM_d_T *localB)
{
  /* MATLAB Function 'Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function2': '<S58>:1' */
  if (rtu_signal >= 0.0) {
    /* '<S58>:1:4' */
    /* '<S58>:1:5' */
    localB->Tc_out = rtu_Tc_in1;
  } else {
    /* signal < 0 */
    /* '<S58>:1:7' */
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
 *    '<S67>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S76>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S85>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S94>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S103>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S112>/Core controller: Torque,Power and Combined Torque//Power'
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

  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power': '<S71>:1' */
  /* '<S71>:1:4' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /* '<S71>:1:5' */
  K_TC = (1.0 - lambda_c) * rtu_K_t0r + rtu_K_t0 * lambda_c;

  /* '<S71>:1:6' */
  lambda_c = (1.0 - lambda_c) * rtu_K_q0r + rtu_K_q0 * lambda_c;

  /* '<S71>:1:7' */
  Qcq = lambda_c / K_TC * rtu_D * rtu_Tr;
  if (rtu_n == 0.0) {
    /* '<S71>:1:8' */
    /* '<S71>:1:9' */
    lambda_c = 0.0;
  } else {
    /* '<S71>:1:11' */
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

  /* '<S71>:1:13' */
  K_TC = exp(rt_powd_snf(fabs(rtu_p_cc * rtu_n), rtu_r_cc) * -rtu_k_cc);

  /* '<S71>:1:15' */
  localB->Qcc = (1.0 - K_TC) * lambda_c + K_TC * Qcq;
  localB->Qcq = Qcq;
  localB->Qcp = lambda_c;
}

/*
 * Output and update for atomic system:
 *    '<S65>/Supervisor'
 *    '<S74>/Supervisor'
 *    '<S83>/Supervisor'
 *    '<S92>/Supervisor'
 *    '<S101>/Supervisor'
 *    '<S110>/Supervisor'
 */
void ctrl_TAPM_Supervisor(real_T rtu_control, real_T rtu_input, real_T rtu_n,
  B_Supervisor_ctrl_TAPM_T *localB)
{
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Supervisor': '<S70>:1' */
  /* '<S70>:1:2' */
  localB->u = 1.0;
  if (rtu_control == 1.0) {
    /* '<S70>:1:3' */
    if (rtu_input == 1.0) {
      /* '<S70>:1:4' */
      /* '<S70>:1:5' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S70>:1:6' */
      /* '<S70>:1:7' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S70>:1:8' */
      /* '<S70>:1:9' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S70>:1:10' */
      /* '<S70>:1:11' */
      localB->u = 4.0;
    } else {
      /* '<S70>:1:13' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 2.0) {
    /* '<S70>:1:17' */
    if (rtu_input == 1.0) {
      /* '<S70>:1:18' */
      /* '<S70>:1:19' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S70>:1:20' */
      /* '<S70>:1:21' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S70>:1:22' */
      /* '<S70>:1:23' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S70>:1:24' */
      /* '<S70>:1:25' */
      localB->u = 4.0;
    } else {
      /* '<S70>:1:27' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 3.0) {
    /* '<S70>:1:31' */
    if (rtu_input == 1.0) {
      /* '<S70>:1:32' */
      /* '<S70>:1:33' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S70>:1:34' */
      /* '<S70>:1:35' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S70>:1:36' */
      /* '<S70>:1:37' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S70>:1:38' */
      /* '<S70>:1:39' */
      localB->u = 4.0;
    } else {
      /* '<S70>:1:41' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 4.0) {
    /* '<S70>:1:45' */
    if (rtu_input == 1.0) {
      /* '<S70>:1:46' */
      /* '<S70>:1:47' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S70>:1:48' */
      /* '<S70>:1:49' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S70>:1:50' */
      /* '<S70>:1:51' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S70>:1:52' */
      /* '<S70>:1:53' */
      localB->u = 4.0;
    } else {
      /* '<S70>:1:55' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 5.0) {
    /* '<S70>:1:59' */
    if (rtu_input == 1.0) {
      /* '<S70>:1:60' */
      /* '<S70>:1:61' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S70>:1:62' */
      /* '<S70>:1:63' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S70>:1:64' */
      /* '<S70>:1:65' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S70>:1:66' */
      /* '<S70>:1:67' */
      localB->u = 4.0;
    } else {
      /* '<S70>:1:69' */
      localB->u = 5.0;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S72>/Actual Force and Torque'
 *    '<S81>/Actual Force and Torque'
 *    '<S90>/Actual Force and Torque'
 *    '<S99>/Actual Force and Torque'
 *    '<S108>/Actual Force and Torque'
 */
void ctrl_TAPM_ActualForceandTorque(real_T rtu_n, real_T rtu_Kq, real_T rtu_Kt,
  real_T rtu_Ktr, real_T rtu_Kqr, real_T rtu_Rho, real_T rtu_D, real_T rtu_eps_c,
  real_T rtu_env, B_ActualForceandTorque_ctrl_T_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_0;

  /* MATLAB Function 'Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque': '<S75>:1' */
  /* '<S75>:1:3' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S75>:1:4' */
  /* '<S75>:1:5' */
  /* '<S75>:1:7' */
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

  /* '<S75>:1:8' */
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
 *    '<S74>/MATLAB Function'
 *    '<S92>/MATLAB Function'
 *    '<S101>/MATLAB Function'
 */
void ctrl_TAPM_MATLABFunction_i(real_T rtu_Td, real_T rtu_K_t0, real_T rtu_K_t0r,
  real_T rtu_rho, real_T rtu_D, real_T rtu_eps_c, real_T rtu_n_r,
  B_MATLABFunction_ctrl_TAPM_a_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_r_0;
  real_T rtu_Td_0;

  /* MATLAB Function 'Thruster control /Thruster 2/Thruster control/MATLAB Function': '<S78>:1' */
  /* '<S78>:1:5' */
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

  /* '<S78>:1:7' */
  lambda_c = tanh(rtu_eps_c * rtu_Td_0 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S78>:1:8' */
  /* '<S78>:1:10' */
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_diag(const real_T v[6], real_T d[36])
{
  int32_T j;
  memset(&d[0], 0, 36U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    d[j + 6 * j] = v[j];
  }
}

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xnrm2_p(int32_T n, const real_T x[6], int32_T ix0)
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_bg(int32_T n, real_T a, const real_T x[3],
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_b(int32_T n, real_T a, const real_T x[18],
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xscal(real_T a, real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xscal_b(real_T a, real_T x[36], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 5; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xswap_m(real_T x[9], int32_T ix0, int32_T iy0)
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xrot_o(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc_ik(int32_T n, const real_T x[36], int32_T ix0,
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_bg2a(int32_T n, real_T a, int32_T ix0, real_T y
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc_i(int32_T n, const real_T x[9], int32_T ix0,
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_bg2(int32_T n, real_T a, int32_T ix0, real_T y[9],
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
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

  ztest0 = ctrl_TAPM_eml_xnrm2_p(5, e, 2);
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
      ctrl_TAPM_eml_xaxpy_b(2, e[i], b_A, 3 * i + 2, work, 2);
    }

    for (i = 1; i + 1 < 7; i++) {
      ctrl_TAPM_eml_xaxpy_bg(2, -e[i] / e[1], work, 2, b_A, 3 * i + 2);
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

  ztest0 = ctrl_TAPM_eml_xnrm2_p(4, e, 3);
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
      ctrl_TAPM_eml_xaxpy_b(1, e[i], b_A, 3 * i + 3, work, 3);
    }

    for (i = 2; i + 1 < 7; i++) {
      ctrl_TAPM_eml_xaxpy_bg(1, -e[i] / e[2], work, 3, b_A, 3 * i + 3);
    }
  }

  for (i = 2; i + 1 < 7; i++) {
    Vf[i + 6] = e[i];
  }

  for (kase = 3; kase + 1 < 7; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_p(3, e, 4);
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
        ctrl_TAPM_eml_xaxpy_bg2(3 - qs, -(ctrl_TAPM_eml_xdotc_i(3 - qs, U, iter
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
        ctrl_TAPM_eml_xaxpy_bg2a(5 - qs, -(ctrl_TAPM_eml_xdotc_ik(5 - qs, Vf, i,
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
    ctrl_TAPM_eml_xscal_b(ztest0, Vf, 7);
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
    ctrl_TAPM_eml_xscal_b(ztest0, Vf, 13);
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
    ctrl_TAPM_eml_xscal_b(ztest0, Vf, 19);
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
        ctrl_TAPM_eml_xrot_o(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest, b);
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
          ctrl_TAPM_eml_xrot_o(U, 1 + 3 * (kase - 1), 1 + 3 * kase, ztest0,
                               ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_TAPM_eml_xscal_b(-1.0, Vf, 1 + 6 * q);
      }

      i = q + 1;
      while ((q + 1 < 4) && (s[q] < s[i])) {
        ztest = s[q];
        s[q] = s[i];
        s[i] = ztest;
        ctrl_TAPM_eml_xswap(Vf, 1 + 6 * q, 1 + 6 * (q + 1));
        if (q + 1 < 3) {
          ctrl_TAPM_eml_xswap_m(U, 1 + 3 * q, 1 + 3 * (q + 1));
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_isfinite(const real_T x[9], boolean_T b[9])
{
  int32_T i;
  for (i = 0; i < 9; i++) {
    b[i] = ((!rtIsInf(x[i])) && (!rtIsNaN(x[i])));
  }
}

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xnrm2_pt(int32_T n, const real_T x[36], int32_T ix0)
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xnrm2_ptp(int32_T n, const real_T x[12], int32_T ix0)
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_bg2arnk(int32_T n, real_T a, const real_T x[3],
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_bg2arn(int32_T n, real_T a, const real_T x[36],
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xscal_bd(real_T a, real_T x[144], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 11; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xswap_mw(real_T x[144], int32_T ix0, int32_T iy0)
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xrot_o5(real_T x[144], int32_T ix0, int32_T iy0,
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc_ikmz(int32_T n, const real_T x[144], int32_T
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_bg2arnka(int32_T n, real_T a, int32_T ix0,
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static real_T ctrl_TAPM_eml_xdotc_ikm(int32_T n, const real_T x[36], int32_T ix0,
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xaxpy_bg2ar(int32_T n, real_T a, int32_T ix0, real_T
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_eml_xgesvd_g(const real_T A[36], real_T U[9], real_T S[3],
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
  ztest0 = ctrl_TAPM_eml_xnrm2_pt(3, b_A, 1);
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
      ctrl_TAPM_eml_xaxpy_bg2ar(3, -(ctrl_TAPM_eml_xdotc_ikm(3, b_A, 1, b_A,
        qp1jj + 1) / b_A[0]), 1, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 0; qp1 + 1 < 4; qp1++) {
    U[qp1] = b_A[qp1];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_ptp(11, e, 2);
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
      ctrl_TAPM_eml_xaxpy_bg2arn(2, e[qp1], b_A, 3 * qp1 + 2, work, 2);
    }

    for (qp1 = 1; qp1 + 1 < 13; qp1++) {
      ctrl_TAPM_eml_xaxpy_bg2arnk(2, -e[qp1] / e[1], work, 2, b_A, 3 * qp1 + 2);
    }
  }

  for (qp1 = 1; qp1 + 1 < 13; qp1++) {
    Vf[qp1] = e[qp1];
  }

  apply_transform = false;
  ztest0 = ctrl_TAPM_eml_xnrm2_pt(2, b_A, 5);
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
      ctrl_TAPM_eml_xaxpy_bg2ar(2, -(ctrl_TAPM_eml_xdotc_ikm(2, b_A, 5, b_A,
        qp1jj + 1) / b_A[4]), 5, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 1; qp1 + 1 < 4; qp1++) {
    U[qp1 + 3] = b_A[qp1 + 3];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_ptp(10, e, 3);
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
      ctrl_TAPM_eml_xaxpy_bg2arn(1, e[qp1], b_A, 3 * qp1 + 3, work, 3);
    }

    for (qp1 = 2; qp1 + 1 < 13; qp1++) {
      ctrl_TAPM_eml_xaxpy_bg2arnk(1, -e[qp1] / e[2], work, 3, b_A, 3 * qp1 + 3);
    }
  }

  for (qp1 = 2; qp1 + 1 < 13; qp1++) {
    Vf[qp1 + 12] = e[qp1];
  }

  for (kase = 3; kase + 1 < 13; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = ctrl_TAPM_eml_xnrm2_ptp(9, e, 4);
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
        ctrl_TAPM_eml_xaxpy_bg2(3 - qs, -(ctrl_TAPM_eml_xdotc_i(3 - qs, U, iter
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
        ctrl_TAPM_eml_xaxpy_bg2arnka(11 - qs, -(ctrl_TAPM_eml_xdotc_ikmz(11 - qs,
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
    ctrl_TAPM_eml_xscal_bd(ztest0, Vf, 13);
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
    ctrl_TAPM_eml_xscal_bd(ztest0, Vf, 25);
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
    ctrl_TAPM_eml_xscal_bd(ztest0, Vf, 37);
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

        ctrl_TAPM_eml_xrot_o5(Vf, 1 + 12 * kase, 1 + 12 * (m + 1), ztest, b);
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
        ctrl_TAPM_eml_xrot_o(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest, b);
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
        ctrl_TAPM_eml_xrot_o5(Vf, 1 + 12 * (kase - 1), 1 + 12 * kase, ztest0,
                              ztest);
        ctrl_TAPM_eml_xrotg(&f, &b, &ztest0, &ztest);
        s[kase - 1] = f;
        f = e[kase - 1] * ztest0 + ztest * s[kase];
        s[kase] = e[kase - 1] * -ztest + ztest0 * s[kase];
        b = ztest * e[kase];
        e[kase] *= ztest0;
        if (kase < 3) {
          ctrl_TAPM_eml_xrot_o(U, 1 + 3 * (kase - 1), 1 + 3 * kase, ztest0,
                               ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_TAPM_eml_xscal_bd(-1.0, Vf, 1 + 12 * q);
      }

      qp1 = q + 1;
      while ((q + 1 < 4) && (s[q] < s[qp1])) {
        ztest = s[q];
        s[q] = s[qp1];
        s[qp1] = ztest;
        ctrl_TAPM_eml_xswap_mw(Vf, 1 + 12 * q, 1 + 12 * (q + 1));
        if (q + 1 < 3) {
          ctrl_TAPM_eml_xswap_m(U, 1 + 3 * q, 1 + 3 * (q + 1));
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_svd_j(const real_T A[36], real_T U[9], real_T S[9], real_T
  V[36])
{
  real_T s[3];
  ctrl_TAPM_eml_xgesvd_g(A, U, s, V);
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_cosd_g(real_T *x)
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

/* Function for MATLAB Function: '<S6>/MATLAB Function' */
static void ctrl_TAPM_sind_c(real_T *x)
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
  real_T rtb_Integrator_p;
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
  real_T rtb_Integrator_gu;
  real_T rtb_Integrator_f;
  real_T rtb_Integrator_hl;
  real_T rtb_Integrator_an;
  real_T rtb_Integrator_i;
  real_T rtb_Integrator_ld;
  real_T rtb_T_r;
  real_T rtb_T_r_b;
  real_T rtb_T_r_c;
  real_T rtb_sys[12];
  real_T rtb_ImpSel_InsertedFor_reset_at;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T res;
  real_T offset;
  int32_T k;
  real_T s[6];
  real_T K[6];
  real_T B_surge[6];
  real_T S_singular_cross[9];
  real_T T0[12];
  real_T c1[2];
  real_T U_singular[9];
  real_T V_singular[18];
  real_T b_V_singular[36];
  real_T varargin_1[2];
  static const int8_T d[12] = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 };

  static const int8_T e[12] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };

  boolean_T f[9];
  boolean_T exitg11;
  real_T g;
  real_T h;
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
  real_T rtb_Row1;
  real_T rtb_Row3;
  real_T rtb_y[6];
  real_T rtb_ImpAsg_InsertedFor_Out2_at_[6];
  real_T rtb_bias[3];
  real_T rtb_Sum_b;
  real_T rtb_TmpSignalConversionAtSFun_o[6];
  real_T rtb_Out2_CoreSubsysCanOut;
  real_T rtb_Ta;
  real_T rtb_TmpSignalConversionAtSFun_b[10];
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
  real_T tmp_0[3];
  int32_T i_0;
  real_T B_surge_1[18];
  real_T pos[18];
  real_T tmp_1[3];
  real_T tmp_2[3];
  real_T tmp_3[3];
  int32_T b_data[9];
  int32_T c_data[9];
  real_T rtb_TmpSignalConversionAtSFu__0;
  real_T rtb_TmpSignalConversionAtSFu__1;
  real_T rtb_eta_w_idx_2;
  real_T rtb_eta_w_idx_0;
  real_T Alpha1_idx_0;
  real_T Alpha1_idx_3;
  real_T Alpha1_idx_4;
  real_T rtb_Integrator_idx_0;
  real_T rtb_Integrator_idx_1;
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
    /* Delay: '<S19>/Delay' */
    ctrl_TAPM_B.Delay = ctrl_TAPM_DW.Delay_DSTATE;
  }

  /* Integrator: '<S18>/Integrator' */
  ctrl_TAPM_B.eta[0] = ctrl_TAPM_X.Integrator_CSTATE[0];
  ctrl_TAPM_B.eta[1] = ctrl_TAPM_X.Integrator_CSTATE[1];
  ctrl_TAPM_B.eta[2] = ctrl_TAPM_X.Integrator_CSTATE[2];

  /* MATLAB Function: '<S19>/MATLAB Function' */
  /* MATLAB Function 'TAPM Controller w_observer/PID/MATLAB Function': '<S33>:1' */
  /* '<S33>:1:9' */
  res = 0;

  /* '<S33>:1:11' */
  rtb_eta_w_idx_2 = sqrt(ctrl_TAPM_B.eta[0] * ctrl_TAPM_B.eta[0] +
    ctrl_TAPM_B.eta[1] * ctrl_TAPM_B.eta[1]);
  if ((rtb_eta_w_idx_2 > ctrl_TAPM_B.r_max) && (ctrl_TAPM_DW.controller != 2.0))
  {
    /* '<S33>:1:13' */
    /* '<S33>:1:14' */
    ctrl_TAPM_DW.controller = 2.0;

    /* '<S33>:1:15' */
    res = 1;
  } else {
    if ((rtb_eta_w_idx_2 < 0.9 * ctrl_TAPM_B.r_max) && (ctrl_TAPM_B.Delay > 40.0)
        && (ctrl_TAPM_DW.controller != 1.0) && (ctrl_TAPM_DW.tmp > 190.0)) {
      /* '<S33>:1:16' */
      /* '<S33>:1:17' */
      ctrl_TAPM_DW.controller = 1.0;

      /* '<S33>:1:18' */
      res = 1;
    }
  }

  if (rtb_eta_w_idx_2 > ctrl_TAPM_B.r_max) {
    /* '<S33>:1:21' */
    /* '<S33>:1:22' */
    res = 1;

    /* '<S33>:1:23' */
    ctrl_TAPM_DW.tmp = 0.0;
  } else {
    /* '<S33>:1:25' */
    ctrl_TAPM_DW.tmp += 0.01;
  }

  /* '<S33>:1:28' */
  ctrl_TAPM_B.y = ctrl_TAPM_DW.controller;

  /* '<S33>:1:29' */
  ctrl_TAPM_B.reset_n0 = res;

  /* End of MATLAB Function: '<S19>/MATLAB Function' */

  /* MATLAB Function: '<S2>/MATLAB Function' */
  ctrl_TAPM_MATLABFunction(ctrl_TAPM_B.K_p_x, ctrl_TAPM_B.K_p_y,
    ctrl_TAPM_B.K_p_psi, &ctrl_TAPM_B.sf_MATLABFunction_f);

  /* Saturate: '<S36>/Saturation' incorporates:
   *  Fcn: '<S31>/yaw angle'
   */
  if (ctrl_TAPM_B.eta[2] > ctrl_TAPM_P.Saturation_UpperSat) {
    rtb_Row1 = ctrl_TAPM_P.Saturation_UpperSat;
  } else if (ctrl_TAPM_B.eta[2] < ctrl_TAPM_P.Saturation_LowerSat) {
    rtb_Row1 = ctrl_TAPM_P.Saturation_LowerSat;
  } else {
    rtb_Row1 = ctrl_TAPM_B.eta[2];
  }

  /* End of Saturate: '<S36>/Saturation' */

  /* Signum: '<S36>/Sign' */
  if (rtb_Row1 < 0.0) {
    rtb_eta_w_idx_0 = -1.0;
  } else if (rtb_Row1 > 0.0) {
    rtb_eta_w_idx_0 = 1.0;
  } else if (rtb_Row1 == 0.0) {
    rtb_eta_w_idx_0 = 0.0;
  } else {
    rtb_eta_w_idx_0 = rtb_Row1;
  }

  /* Gain: '<S36>/Gain' incorporates:
   *  Signum: '<S36>/Sign'
   */
  rtb_Row3 = ctrl_TAPM_P.Gain_Gain * rtb_eta_w_idx_0;

  /* Sum: '<S36>/Sum1' */
  rtb_Row1 += rtb_Row3;

  /* Math: '<S36>/Math Function' incorporates:
   *  Constant: '<S36>/Constant'
   */
  rtb_Row1 = rt_remd_snf(rtb_Row1, ctrl_TAPM_P.Constant_Value);

  /* Sum: '<S36>/Sum' */
  rtb_Row1 -= rtb_Row3;

  /* Integrator: '<S20>/Integrator' */
  rtb_Integrator_idx_0 = ctrl_TAPM_X.Integrator_CSTATE_l[0];
  rtb_Integrator_idx_1 = ctrl_TAPM_X.Integrator_CSTATE_l[1];

  /* MATLAB Function: '<S20>/Set-Point Limiter' incorporates:
   *  Integrator: '<S20>/Integrator'
   *  MATLAB Function: '<S2>/MATLAB Function3'
   *  SignalConversion: '<S13>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Input/MATLAB Function3': '<S13>:1' */
  /* '<S13>:1:4' */
  /* MATLAB Function 'TAPM Controller w_observer/SP Generator/Set-Point Limiter': '<S40>:1' */
  /* '<S40>:1:3' */
  rtb_TmpSignalConversionAtSFu__0 = ctrl_TAPM_X.Integrator_CSTATE_l[0] -
    ctrl_TAPM_B.fzp_x;
  rtb_TmpSignalConversionAtSFu__1 = ctrl_TAPM_X.Integrator_CSTATE_l[1] -
    ctrl_TAPM_B.fzp_y;

  /* '<S40>:1:4' */
  rtb_eta_w_idx_2 = 2.2250738585072014E-308;
  rtb_Ta = fabs(rtb_TmpSignalConversionAtSFu__0);
  if (rtb_Ta > 2.2250738585072014E-308) {
    offset = 1.0;
    rtb_eta_w_idx_2 = rtb_Ta;
  } else {
    t = rtb_Ta / 2.2250738585072014E-308;
    offset = t * t;
  }

  rtb_Ta = fabs(rtb_TmpSignalConversionAtSFu__1);
  if (rtb_Ta > rtb_eta_w_idx_2) {
    t = rtb_eta_w_idx_2 / rtb_Ta;
    offset = offset * t * t + 1.0;
    rtb_eta_w_idx_2 = rtb_Ta;
  } else {
    t = rtb_Ta / rtb_eta_w_idx_2;
    offset += t * t;
  }

  offset = rtb_eta_w_idx_2 * sqrt(offset);

  /* '<S40>:1:5' */
  /* '<S40>:1:6' */
  /* '<S40>:1:7' */
  rtb_eta_w_idx_2 = rt_powd_snf(offset / ctrl_TAPM_B.r_max, 5.0);
  if (rtb_eta_w_idx_2 > 1.0) {
    /* '<S40>:1:10' */
    /* '<S40>:1:11' */
    rtb_eta_w_idx_2 = 1.0;
  }

  /* '<S40>:1:14' */
  rtb_TmpSignalConversionAtSFu__0 = (ctrl_TAPM_B.fzp_x +
    rtb_TmpSignalConversionAtSFu__0) - (rtb_TmpSignalConversionAtSFu__0 -
    rtb_TmpSignalConversionAtSFu__0 / offset * ctrl_TAPM_B.r_max) *
    rtb_eta_w_idx_2;
  Alpha1_idx_0 = (ctrl_TAPM_B.fzp_y + rtb_TmpSignalConversionAtSFu__1) -
    (rtb_TmpSignalConversionAtSFu__1 - rtb_TmpSignalConversionAtSFu__1 / offset *
     ctrl_TAPM_B.r_max) * rtb_eta_w_idx_2;

  /* End of MATLAB Function: '<S20>/Set-Point Limiter' */

  /* TransferFcn: '<S20>/Transfer Fcn2' */
  rtb_Row3 = ctrl_TAPM_P.TransferFcn2_C * ctrl_TAPM_X.TransferFcn2_CSTATE;

  /* Saturate: '<S21>/Saturation' */
  if (rtb_Row3 > ctrl_TAPM_P.Saturation_UpperSat_g) {
    rtb_Row3 = ctrl_TAPM_P.Saturation_UpperSat_g;
  } else {
    if (rtb_Row3 < ctrl_TAPM_P.Saturation_LowerSat_h) {
      rtb_Row3 = ctrl_TAPM_P.Saturation_LowerSat_h;
    }
  }

  /* End of Saturate: '<S21>/Saturation' */

  /* Signum: '<S21>/Sign' */
  if (rtb_Row3 < 0.0) {
    rtb_eta_w_idx_0 = -1.0;
  } else if (rtb_Row3 > 0.0) {
    rtb_eta_w_idx_0 = 1.0;
  } else if (rtb_Row3 == 0.0) {
    rtb_eta_w_idx_0 = 0.0;
  } else {
    rtb_eta_w_idx_0 = rtb_Row3;
  }

  /* Gain: '<S21>/Gain' incorporates:
   *  Signum: '<S21>/Sign'
   */
  rtb_eta_w_idx_2 = ctrl_TAPM_P.Gain_Gain_p * rtb_eta_w_idx_0;

  /* Sum: '<S21>/Sum1' */
  rtb_Row3 += rtb_eta_w_idx_2;

  /* Math: '<S21>/Math Function' incorporates:
   *  Constant: '<S21>/Constant'
   */
  rtb_Row3 = rt_remd_snf(rtb_Row3, ctrl_TAPM_P.Constant_Value_k);

  /* Sum: '<S21>/Sum' */
  rtb_Row3 -= rtb_eta_w_idx_2;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtSPInport1' */
  ctrl_TAPM_B.TmpSignalConversionAtSPInport1[0] =
    rtb_TmpSignalConversionAtSFu__0;
  ctrl_TAPM_B.TmpSignalConversionAtSPInport1[1] = Alpha1_idx_0;
  ctrl_TAPM_B.TmpSignalConversionAtSPInport1[2] = rtb_Row3;

  /* Sum: '<S31>/Sum2' */
  rtb_eta_w_idx_0 = ctrl_TAPM_B.TmpSignalConversionAtSPInport1[0] -
    ctrl_TAPM_B.eta[0];
  rtb_TmpSignalConversionAtSFu__1 = ctrl_TAPM_B.TmpSignalConversionAtSPInport1[1]
    - ctrl_TAPM_B.eta[1];
  rtb_eta_w_idx_2 = ctrl_TAPM_B.TmpSignalConversionAtSPInport1[2] -
    ctrl_TAPM_B.eta[2];

  /* Saturate: '<S35>/Saturation' */
  if (rtb_eta_w_idx_2 > ctrl_TAPM_P.Saturation_UpperSat_l) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation_UpperSat_l;
  } else {
    if (rtb_eta_w_idx_2 < ctrl_TAPM_P.Saturation_LowerSat_l) {
      rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation_LowerSat_l;
    }
  }

  /* End of Saturate: '<S35>/Saturation' */

  /* Signum: '<S35>/Sign' */
  if (rtb_eta_w_idx_2 < 0.0) {
    Alpha1_idx_0 = -1.0;
  } else if (rtb_eta_w_idx_2 > 0.0) {
    Alpha1_idx_0 = 1.0;
  } else if (rtb_eta_w_idx_2 == 0.0) {
    Alpha1_idx_0 = 0.0;
  } else {
    Alpha1_idx_0 = rtb_eta_w_idx_2;
  }

  /* Gain: '<S35>/Gain' incorporates:
   *  Signum: '<S35>/Sign'
   */
  rtb_Row3 = ctrl_TAPM_P.Gain_Gain_l * Alpha1_idx_0;

  /* Sum: '<S35>/Sum1' */
  rtb_eta_w_idx_2 += rtb_Row3;

  /* Math: '<S35>/Math Function' incorporates:
   *  Constant: '<S35>/Constant'
   */
  rtb_eta_w_idx_2 = rt_remd_snf(rtb_eta_w_idx_2, ctrl_TAPM_P.Constant_Value_e);

  /* Sum: '<S35>/Sum' */
  rtb_eta_w_idx_2 -= rtb_Row3;

  /* SignalConversion: '<S31>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Fcn: '<S34>/Row1'
   *  Fcn: '<S34>/Row2'
   *  Fcn: '<S34>/Row3'
   */
  ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[0] = cos(rtb_Row1) *
    rtb_eta_w_idx_0 + sin(rtb_Row1) * rtb_TmpSignalConversionAtSFu__1;
  ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[1] = -sin(rtb_Row1) *
    rtb_eta_w_idx_0 + cos(rtb_Row1) * rtb_TmpSignalConversionAtSFu__1;
  ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[2] = rtb_eta_w_idx_2;

  /* MATLAB Function: '<S2>/MATLAB Function1' */
  ctrl_TAPM_MATLABFunction1(ctrl_TAPM_B.K_i_x, ctrl_TAPM_B.K_i_y,
    ctrl_TAPM_B.K_i_psi, &ctrl_TAPM_B.sf_MATLABFunction1);

  /* MATLAB Function: '<S2>/MATLAB Function2' */
  ctrl_TAPM_MATLABFunction2(ctrl_TAPM_B.K_d_x, ctrl_TAPM_B.K_d_y,
    ctrl_TAPM_B.K_d_psi, &ctrl_TAPM_B.sf_MATLABFunction2);

  /* Integrator: '<S18>/Integrator4' */
  ctrl_TAPM_B.nu[0] = ctrl_TAPM_X.Integrator4_CSTATE[0];
  ctrl_TAPM_B.nu[1] = ctrl_TAPM_X.Integrator4_CSTATE[1];
  ctrl_TAPM_B.nu[2] = ctrl_TAPM_X.Integrator4_CSTATE[2];

  /* MATLAB Function: '<S2>/MATLAB Function4' */
  ctrl_TAPM_MATLABFunction(ctrl_TAPM_B.K_p_x1, ctrl_TAPM_B.K_p_y1,
    ctrl_TAPM_B.K_p_psi1, &ctrl_TAPM_B.sf_MATLABFunction4);

  /* Saturate: '<S39>/Saturation' incorporates:
   *  Fcn: '<S32>/yaw angle'
   */
  if (ctrl_TAPM_B.eta[2] > ctrl_TAPM_P.Saturation_UpperSat_h) {
    offset = ctrl_TAPM_P.Saturation_UpperSat_h;
  } else if (ctrl_TAPM_B.eta[2] < ctrl_TAPM_P.Saturation_LowerSat_d) {
    offset = ctrl_TAPM_P.Saturation_LowerSat_d;
  } else {
    offset = ctrl_TAPM_B.eta[2];
  }

  /* End of Saturate: '<S39>/Saturation' */

  /* Signum: '<S39>/Sign' */
  if (offset < 0.0) {
    rtb_eta_w_idx_0 = -1.0;
  } else if (offset > 0.0) {
    rtb_eta_w_idx_0 = 1.0;
  } else if (offset == 0.0) {
    rtb_eta_w_idx_0 = 0.0;
  } else {
    rtb_eta_w_idx_0 = offset;
  }

  /* Gain: '<S39>/Gain' incorporates:
   *  Signum: '<S39>/Sign'
   */
  rtb_eta_w_idx_2 = ctrl_TAPM_P.Gain_Gain_n * rtb_eta_w_idx_0;

  /* Sum: '<S39>/Sum1' */
  offset += rtb_eta_w_idx_2;

  /* Math: '<S39>/Math Function' incorporates:
   *  Constant: '<S39>/Constant'
   */
  offset = rt_remd_snf(offset, ctrl_TAPM_P.Constant_Value_d);

  /* Sum: '<S39>/Sum' */
  offset -= rtb_eta_w_idx_2;

  /* Sum: '<S32>/Sum2' */
  rtb_eta_w_idx_0 = ctrl_TAPM_B.TmpSignalConversionAtSPInport1[0] -
    ctrl_TAPM_B.eta[0];
  rtb_TmpSignalConversionAtSFu__1 = ctrl_TAPM_B.TmpSignalConversionAtSPInport1[1]
    - ctrl_TAPM_B.eta[1];
  rtb_eta_w_idx_2 = ctrl_TAPM_B.TmpSignalConversionAtSPInport1[2] -
    ctrl_TAPM_B.eta[2];

  /* Saturate: '<S38>/Saturation' */
  if (rtb_eta_w_idx_2 > ctrl_TAPM_P.Saturation_UpperSat_a) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation_UpperSat_a;
  } else {
    if (rtb_eta_w_idx_2 < ctrl_TAPM_P.Saturation_LowerSat_lh) {
      rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation_LowerSat_lh;
    }
  }

  /* End of Saturate: '<S38>/Saturation' */

  /* Signum: '<S38>/Sign' */
  if (rtb_eta_w_idx_2 < 0.0) {
    Alpha1_idx_0 = -1.0;
  } else if (rtb_eta_w_idx_2 > 0.0) {
    Alpha1_idx_0 = 1.0;
  } else if (rtb_eta_w_idx_2 == 0.0) {
    Alpha1_idx_0 = 0.0;
  } else {
    Alpha1_idx_0 = rtb_eta_w_idx_2;
  }

  /* Gain: '<S38>/Gain' incorporates:
   *  Signum: '<S38>/Sign'
   */
  rtb_Row3 = ctrl_TAPM_P.Gain_Gain_j * Alpha1_idx_0;

  /* Sum: '<S38>/Sum1' */
  rtb_eta_w_idx_2 += rtb_Row3;

  /* Math: '<S38>/Math Function' incorporates:
   *  Constant: '<S38>/Constant'
   */
  rtb_eta_w_idx_2 = rt_remd_snf(rtb_eta_w_idx_2, ctrl_TAPM_P.Constant_Value_c);

  /* Sum: '<S38>/Sum' */
  rtb_eta_w_idx_2 -= rtb_Row3;

  /* SignalConversion: '<S32>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Fcn: '<S37>/Row1'
   *  Fcn: '<S37>/Row2'
   *  Fcn: '<S37>/Row3'
   */
  ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_b[0] = cos(offset) * rtb_eta_w_idx_0
    + sin(offset) * rtb_TmpSignalConversionAtSFu__1;
  ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_b[1] = -sin(offset) *
    rtb_eta_w_idx_0 + cos(offset) * rtb_TmpSignalConversionAtSFu__1;
  ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_b[2] = rtb_eta_w_idx_2;

  /* MATLAB Function: '<S2>/MATLAB Function5' */
  ctrl_TAPM_MATLABFunction1(ctrl_TAPM_B.K_i_x1, ctrl_TAPM_B.K_i_y1,
    ctrl_TAPM_B.K_i_psi1, &ctrl_TAPM_B.sf_MATLABFunction5);

  /* MATLAB Function: '<S2>/MATLAB Function6' */
  ctrl_TAPM_MATLABFunction2(ctrl_TAPM_B.K_d_x1, ctrl_TAPM_B.K_d_y1,
    ctrl_TAPM_B.K_d_psi1, &ctrl_TAPM_B.sf_MATLABFunction6);

  /* MultiPortSwitch: '<S19>/Multiport Switch' incorporates:
   *  Product: '<S31>/Matrix Multiply2'
   *  Product: '<S32>/Matrix Multiply2'
   *  Sum: '<S31>/Sum1'
   *  Sum: '<S31>/Sum3'
   *  Sum: '<S32>/Sum1'
   *  Sum: '<S32>/Sum3'
   */
  if ((int32_T)ctrl_TAPM_B.y == 1) {
    /* Product: '<S31>/Matrix Multiply' incorporates:
     *  Sum: '<S31>/Sum3'
     */
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_bias[i_0] = ctrl_TAPM_B.sf_MATLABFunction_f.K_p[i_0 + 6] *
        ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[2] +
        (ctrl_TAPM_B.sf_MATLABFunction_f.K_p[i_0 + 3] *
         ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[1] +
         ctrl_TAPM_B.sf_MATLABFunction_f.K_p[i_0] *
         ctrl_TAPM_B.TmpSignalConversionAtMatrixMult[0]);
    }

    /* End of Product: '<S31>/Matrix Multiply' */

    /* Product: '<S31>/Matrix Multiply1' incorporates:
     *  Integrator: '<S31>/Integrator'
     *  Sum: '<S31>/Sum3'
     */
    for (i_0 = 0; i_0 < 3; i_0++) {
      tmp_0[i_0] = ctrl_TAPM_B.sf_MATLABFunction1.K_i[i_0 + 6] *
        ctrl_TAPM_X.Integrator_CSTATE_g[2] +
        (ctrl_TAPM_B.sf_MATLABFunction1.K_i[i_0 + 3] *
         ctrl_TAPM_X.Integrator_CSTATE_g[1] +
         ctrl_TAPM_B.sf_MATLABFunction1.K_i[i_0] *
         ctrl_TAPM_X.Integrator_CSTATE_g[0]);
    }

    /* End of Product: '<S31>/Matrix Multiply1' */
    for (i_0 = 0; i_0 < 3; i_0++) {
      ctrl_TAPM_B.MultiportSwitch[i_0] = (rtb_bias[i_0] + tmp_0[i_0]) -
        ((ctrl_TAPM_B.sf_MATLABFunction2.K_d[i_0 + 3] * ctrl_TAPM_B.nu[1] +
          ctrl_TAPM_B.sf_MATLABFunction2.K_d[i_0] * ctrl_TAPM_B.nu[0]) +
         ctrl_TAPM_B.sf_MATLABFunction2.K_d[i_0 + 6] * ctrl_TAPM_B.nu[2]);
    }
  } else {
    /* Product: '<S32>/Matrix Multiply' incorporates:
     *  Sum: '<S32>/Sum3'
     */
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_bias[i_0] = ctrl_TAPM_B.sf_MATLABFunction4.K_p[i_0 + 6] *
        ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_b[2] +
        (ctrl_TAPM_B.sf_MATLABFunction4.K_p[i_0 + 3] *
         ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_b[1] +
         ctrl_TAPM_B.sf_MATLABFunction4.K_p[i_0] *
         ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_b[0]);
    }

    /* End of Product: '<S32>/Matrix Multiply' */

    /* Product: '<S32>/Matrix Multiply1' incorporates:
     *  Integrator: '<S32>/Integrator'
     *  Sum: '<S32>/Sum3'
     */
    for (i_0 = 0; i_0 < 3; i_0++) {
      tmp_0[i_0] = ctrl_TAPM_B.sf_MATLABFunction5.K_i[i_0 + 6] *
        ctrl_TAPM_X.Integrator_CSTATE_k[2] +
        (ctrl_TAPM_B.sf_MATLABFunction5.K_i[i_0 + 3] *
         ctrl_TAPM_X.Integrator_CSTATE_k[1] +
         ctrl_TAPM_B.sf_MATLABFunction5.K_i[i_0] *
         ctrl_TAPM_X.Integrator_CSTATE_k[0]);
    }

    /* End of Product: '<S32>/Matrix Multiply1' */
    for (i_0 = 0; i_0 < 3; i_0++) {
      ctrl_TAPM_B.MultiportSwitch[i_0] = (rtb_bias[i_0] + tmp_0[i_0]) -
        ((ctrl_TAPM_B.sf_MATLABFunction6.K_d[i_0 + 3] * ctrl_TAPM_B.nu[1] +
          ctrl_TAPM_B.sf_MATLABFunction6.K_d[i_0] * ctrl_TAPM_B.nu[0]) +
         ctrl_TAPM_B.sf_MATLABFunction6.K_d[i_0 + 6] * ctrl_TAPM_B.nu[2]);
    }
  }

  /* End of MultiPortSwitch: '<S19>/Multiport Switch' */

  /* SignalConversion: '<S44>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S6>/angle between  [-180 180]'
   */
  rtb_TmpSignalConversionAtSFun_o[0] = ctrl_TAPM_B.thr_angle_1;
  rtb_TmpSignalConversionAtSFun_o[1] = ctrl_TAPM_B.thr_angle_2;
  rtb_TmpSignalConversionAtSFun_o[2] = ctrl_TAPM_B.thr_angle_3;
  rtb_TmpSignalConversionAtSFun_o[3] = ctrl_TAPM_B.thr_angle_4;
  rtb_TmpSignalConversionAtSFun_o[4] = ctrl_TAPM_B.thr_angle_5;
  rtb_TmpSignalConversionAtSFun_o[5] = ctrl_TAPM_B.thr_angle_6;

  /* MATLAB Function: '<S6>/angle between  [-180 180]' */
  /* MATLAB Function 'Thrust allocation/angle between  [-180 180]': '<S44>:1' */
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
  /* '<S44>:1:39' */
  /* '<S44>:1:40' */
  /*  s = sign(angle); */
  /* '<S44>:1:43' */
  for (i = 0; i < 6; i++) {
    Alpha1_idx_0 = rt_remd_snf(rtb_TmpSignalConversionAtSFun_o[i] +
      3.1415926535897931, 6.2831853071795862) / 6.2831853071795862;
    rtb_eta_w_idx_0 = fabs(Alpha1_idx_0);
    if (rtb_eta_w_idx_0 > 0.0) {
      rtb_eta_w_idx_0 = 1.0;
    } else {
      if (rtb_eta_w_idx_0 == 0.0) {
        rtb_eta_w_idx_0 = 0.0;
      }
    }

    if (rtb_TmpSignalConversionAtSFun_o[i] < 0.0) {
      rtb_TmpSignalConversionAtSFu__1 = -1.0;
    } else if (rtb_TmpSignalConversionAtSFun_o[i] > 0.0) {
      rtb_TmpSignalConversionAtSFu__1 = 1.0;
    } else if (rtb_TmpSignalConversionAtSFun_o[i] == 0.0) {
      rtb_TmpSignalConversionAtSFu__1 = 0.0;
    } else {
      rtb_TmpSignalConversionAtSFu__1 = rtb_TmpSignalConversionAtSFun_o[i];
    }

    s_0 = (rtb_eta_w_idx_0 - 1.0) * 2.0 + rtb_TmpSignalConversionAtSFu__1;
    if (s_0 < 0.0) {
      s_0 = -1.0;
    } else if (s_0 > 0.0) {
      s_0 = 1.0;
    } else {
      if (s_0 == 0.0) {
        s_0 = 0.0;
      }
    }

    if (rtb_TmpSignalConversionAtSFun_o[i] < 0.0) {
      rtb_TmpSignalConversionAtSFu__1 = -1.0;
    } else if (rtb_TmpSignalConversionAtSFun_o[i] > 0.0) {
      rtb_TmpSignalConversionAtSFu__1 = 1.0;
    } else if (rtb_TmpSignalConversionAtSFun_o[i] == 0.0) {
      rtb_TmpSignalConversionAtSFu__1 = 0.0;
    } else {
      rtb_TmpSignalConversionAtSFu__1 = rtb_TmpSignalConversionAtSFun_o[i];
    }

    rtb_y[i] = rt_remd_snf(rtb_TmpSignalConversionAtSFu__1 * 3.1415926535897931
      + rtb_TmpSignalConversionAtSFun_o[i], 6.2831853071795862) - s_0 *
      3.1415926535897931;
    rtb_TmpSignalConversionAtSFun_o[i] = Alpha1_idx_0;
  }

  /* SignalConversion: '<S41>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Gain: '<S43>/Gain'
   *  MATLAB Function: '<S6>/MATLAB Function'
   */
  rtb_TmpSignalConversionAtSFun_b[0] = ctrl_TAPM_B.MultiportSwitch[0];
  rtb_TmpSignalConversionAtSFun_b[1] = ctrl_TAPM_B.MultiportSwitch[1];
  rtb_TmpSignalConversionAtSFun_b[2] = ctrl_TAPM_B.MultiportSwitch[2];
  for (i = 0; i < 6; i++) {
    rtb_TmpSignalConversionAtSFun_b[i + 3] = ctrl_TAPM_P.Gain_Gain_o * rtb_y[i];
  }

  /* End of SignalConversion: '<S41>/TmpSignal ConversionAt SFunction Inport1' */

  /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
   *  Constant: '<S6>/C'
   *  Constant: '<S6>/X-position Thruster'
   *  Constant: '<S6>/Y-position Thruster'
   */
  /* MATLAB Function 'Thrust allocation/MATLAB Function': '<S41>:1' */
  /*  Complete system goes here! */
  /*  Allocating dimensions for faster computing */
  /*  Parameters thrusters */
  /* '<S41>:1:5' */
  rtb_eta_w_idx_0 = rtb_TmpSignalConversionAtSFun_b[0];
  rtb_TmpSignalConversionAtSFu__1 = rtb_TmpSignalConversionAtSFun_b[1];
  rtb_eta_w_idx_2 = rtb_TmpSignalConversionAtSFun_b[2];

  /* '<S41>:1:6' */
  rtb_TmpSignalConversionAtSFun_o[0] = rtb_TmpSignalConversionAtSFun_b[3];
  rtb_TmpSignalConversionAtSFun_o[1] = rtb_TmpSignalConversionAtSFun_b[4];
  rtb_TmpSignalConversionAtSFun_o[2] = rtb_TmpSignalConversionAtSFun_b[5];
  rtb_TmpSignalConversionAtSFun_o[3] = rtb_TmpSignalConversionAtSFun_b[6];
  rtb_TmpSignalConversionAtSFun_o[4] = rtb_TmpSignalConversionAtSFun_b[7];
  rtb_TmpSignalConversionAtSFun_o[5] = rtb_TmpSignalConversionAtSFun_b[8];

  /*  Constraints for Thruster-Thruster interaction. Can be seen in "Initfile" */
  /*  how they are found */
  /* '<S41>:1:10' */
  /* '<S41>:1:11' */
  /* '<S41>:1:12' */
  /* '<S41>:1:13' */
  /* '<S41>:1:14' */
  /* '<S41>:1:15' */
  if (((rtb_TmpSignalConversionAtSFun_b[3] < ctrl_TAPM_P.C[0] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[3] > ctrl_TAPM_P.C[6] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[3] > ctrl_TAPM_P.C[12] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[3] < ctrl_TAPM_P.C[18] - 0.1))) {
    /* '<S41>:1:21' */
    /* '<S41>:1:22' */
    K[0] = 0.0;
  } else {
    /* '<S41>:1:24' */
    K[0] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_b[4] > ctrl_TAPM_P.C[1] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[4] < ctrl_TAPM_P.C[7] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[4] > ctrl_TAPM_P.C[13] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[4] < ctrl_TAPM_P.C[19] + 0.1))) {
    /* '<S41>:1:27' */
    /* '<S41>:1:28' */
    K[1] = 0.0;
  } else {
    /* '<S41>:1:30' */
    K[1] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_b[5] < ctrl_TAPM_P.C[2] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[5] > ctrl_TAPM_P.C[8] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[5] < ctrl_TAPM_P.C[14] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[5] > ctrl_TAPM_P.C[20] - 0.1))) {
    /* '<S41>:1:33' */
    /* '<S41>:1:34' */
    K[2] = 0.0;
  } else {
    /* '<S41>:1:36' */
    K[2] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_b[6] > ctrl_TAPM_P.C[3] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[6] < ctrl_TAPM_P.C[9] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[6] < ctrl_TAPM_P.C[15] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[6] > ctrl_TAPM_P.C[21] + 0.1))) {
    /* '<S41>:1:39' */
    /* '<S41>:1:40' */
    K[3] = 0.0;
  } else {
    /* '<S41>:1:42' */
    K[3] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_b[7] < ctrl_TAPM_P.C[4] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[7] > ctrl_TAPM_P.C[10] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[7] < ctrl_TAPM_P.C[16] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[7] > ctrl_TAPM_P.C[22] + 0.1))) {
    /* '<S41>:1:45' */
    /* '<S41>:1:46' */
    K[4] = 0.0;
  } else {
    /* '<S41>:1:48' */
    K[4] = 1.0;
  }

  if (((rtb_TmpSignalConversionAtSFun_b[8] > ctrl_TAPM_P.C[5] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[8] < ctrl_TAPM_P.C[11] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[8] > ctrl_TAPM_P.C[17] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[8] < ctrl_TAPM_P.C[23] - 0.1))) {
    /* '<S41>:1:51' */
    /* '<S41>:1:52' */
    K[5] = 0.0;
  } else {
    /* '<S41>:1:54' */
    K[5] = 1.0;
  }

  /*  number of thrusters */
  /* '<S41>:1:60' */
  /*  Shells for faster computing */
  /* '<S41>:1:61' */
  /*  Shells for faster computing */
  /* '<S41>:1:62' */
  /*  Shells for faster computing */
  /* '<S41>:1:64' */
  for (res = 0; res < 6; res++) {
    /* '<S41>:1:64' */
    /* '<S41>:1:65' */
    B_surge[res] = rtb_TmpSignalConversionAtSFun_o[res];
    ctrl_TAPM_cosd_g(&B_surge[res]);

    /* Thrust in x-direction for cartesian */
    /* '<S41>:1:66' */
    rtb_y[res] = rtb_TmpSignalConversionAtSFun_o[res];
    ctrl_TAPM_sind_c(&rtb_y[res]);

    /* Thrust in y-direction for cartesian */
    /* '<S41>:1:67' */
    g = rtb_TmpSignalConversionAtSFun_o[res];
    ctrl_TAPM_sind_c(&g);
    h = rtb_TmpSignalConversionAtSFun_o[res];
    ctrl_TAPM_cosd_g(&h);
    s[res] = g * ctrl_TAPM_P.XpositionThruster_Value[res] - h *
      ctrl_TAPM_P.YpositionThruster_Value[res];

    /* '<S41>:1:64' */
  }

  /* '<S41>:1:71' */
  /* '<S41>:1:72' */
  ctrl_TAPM_diag(K, d_0);
  for (i_0 = 0; i_0 < 6; i_0++) {
    B_surge_1[3 * i_0] = B_surge[i_0];
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    B_surge_1[1 + 3 * i_0] = rtb_y[i_0];
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    B_surge_1[2 + 3 * i_0] = s[i_0];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 6; i++) {
      B_surge_0[i_0 + 3 * i] = 0.0;
      for (k = 0; k < 6; k++) {
        B_surge_0[i_0 + 3 * i] += B_surge_1[3 * k + i_0] * d_0[6 * i + k];
      }
    }
  }

  ctrl_TAPM_svd(B_surge_0, U_singular, S_singular_cross, V_singular);

  /* '<S41>:1:74' */
  for (i_0 = 0; i_0 < 9; i_0++) {
    S_singular_cross[i_0] = 1.0 / S_singular_cross[i_0];
  }

  /* '<S41>:1:75' */
  ctrl_TAPM_isfinite(S_singular_cross, tmp);
  res = 0;
  for (i_0 = 0; i_0 < 9; i_0++) {
    exitg11 = !tmp[i_0];
    if (exitg11) {
      res++;
    }

    f[i_0] = exitg11;
  }

  i = res;
  res = 0;
  for (k = 0; k < 9; k++) {
    if (f[k]) {
      b_data[res] = k + 1;
      res++;
    }
  }

  /* '<S41>:1:75' */
  for (i_0 = 0; i_0 < i; i_0++) {
    S_singular_cross[b_data[i_0] - 1] = 0.0;
  }

  if (S_singular_cross[8] > 10.0 * S_singular_cross[4]) {
    /* '<S41>:1:76' */
    /* '<S41>:1:77' */
    S_singular_cross[8] = 0.0;
  }

  /* '<S41>:1:80' */
  /* '<S41>:1:82' */
  for (i_0 = 0; i_0 < 6; i_0++) {
    for (i = 0; i < 3; i++) {
      B_surge_1[i_0 + 6 * i] = 0.0;
      B_surge_1[i_0 + 6 * i] += S_singular_cross[3 * i] * V_singular[i_0];
      B_surge_1[i_0 + 6 * i] += S_singular_cross[3 * i + 1] * V_singular[i_0 + 6];
      B_surge_1[i_0 + 6 * i] += S_singular_cross[3 * i + 2] * V_singular[i_0 +
        12];
    }
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    for (i = 0; i < 3; i++) {
      V_singular[i_0 + 6 * i] = 0.0;
      V_singular[i_0 + 6 * i] += B_surge_1[i_0] * U_singular[i];
      V_singular[i_0 + 6 * i] += B_surge_1[i_0 + 6] * U_singular[i + 3];
      V_singular[i_0 + 6 * i] += B_surge_1[i_0 + 12] * U_singular[i + 6];
    }
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    B_surge[i_0] = V_singular[i_0 + 12] * rtb_eta_w_idx_2 + (V_singular[i_0 + 6]
      * rtb_TmpSignalConversionAtSFu__1 + V_singular[i_0] * rtb_eta_w_idx_0);
  }

  /*  Optimized Thrust */
  /* '<S41>:1:86' */
  for (i_0 = 0; i_0 < 12; i_0++) {
    d_0[3 * i_0] = d[i_0];
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    d_0[1 + 3 * i_0] = e[i_0];
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
  ctrl_TAPM_svd_j(d_0, U_singular, S_singular_cross, b_V_singular);

  /* '<S41>:1:92' */
  for (i_0 = 0; i_0 < 9; i_0++) {
    S_singular_cross[i_0] = 1.0 / S_singular_cross[i_0];
  }

  /* '<S41>:1:93' */
  ctrl_TAPM_isfinite(S_singular_cross, tmp);
  res = 0;
  for (i_0 = 0; i_0 < 9; i_0++) {
    exitg11 = !tmp[i_0];
    if (exitg11) {
      res++;
    }

    f[i_0] = exitg11;
  }

  i = res;
  res = 0;
  for (k = 0; k < 9; k++) {
    if (f[k]) {
      c_data[res] = k + 1;
      res++;
    }
  }

  /* '<S41>:1:93' */
  for (i_0 = 0; i_0 < i; i_0++) {
    S_singular_cross[c_data[i_0] - 1] = 0.0;
  }

  if (S_singular_cross[8] > 2.0 * S_singular_cross[4]) {
    /* '<S41>:1:94' */
    /* '<S41>:1:95' */
    S_singular_cross[8] = 0.0;
  }

  /* '<S41>:1:97' */
  for (i_0 = 0; i_0 < 12; i_0++) {
    for (i = 0; i < 3; i++) {
      d_0[i_0 + 12 * i] = 0.0;
      d_0[i_0 + 12 * i] += S_singular_cross[3 * i] * b_V_singular[i_0];
      d_0[i_0 + 12 * i] += S_singular_cross[3 * i + 1] * b_V_singular[i_0 + 12];
      d_0[i_0 + 12 * i] += S_singular_cross[3 * i + 2] * b_V_singular[i_0 + 24];
    }
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    for (i = 0; i < 3; i++) {
      b_V_singular[i_0 + 12 * i] = 0.0;
      b_V_singular[i_0 + 12 * i] += d_0[i_0] * U_singular[i];
      b_V_singular[i_0 + 12 * i] += d_0[i_0 + 12] * U_singular[i + 3];
      b_V_singular[i_0 + 12 * i] += d_0[i_0 + 24] * U_singular[i + 6];
    }
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    T0[i_0] = b_V_singular[i_0 + 24] * rtb_eta_w_idx_2 + (b_V_singular[i_0 + 12]
      * rtb_TmpSignalConversionAtSFu__1 + b_V_singular[i_0] * rtb_eta_w_idx_0);
  }

  /* '<S41>:1:99' */
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
    /* '<S41>:1:105' */
    /* '<S41>:1:106' */
    c1[0] = ctrl_TAPM_P.C[0];
    c1[1] = ctrl_TAPM_P.C[6];
    c1_5[0] = ctrl_TAPM_P.C[0] - K[0];
    c1_5[1] = ctrl_TAPM_P.C[6] - K[0];
    ctrl_TAPM_abs(c1_5, varargin_1);
    res = 1;
    rtb_eta_w_idx_2 = varargin_1[0];
    k = 0;
    if (rtIsNaN(varargin_1[0])) {
      i = 2;
      exitg11 = false;
      while ((!exitg11) && (i < 3)) {
        res = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_eta_w_idx_2 = varargin_1[1];
          k = 1;
          exitg11 = true;
        } else {
          i = 3;
        }
      }
    }

    if ((res < 2) && (varargin_1[1] < rtb_eta_w_idx_2)) {
      k = 1;
    }

    /* '<S41>:1:108' */
    Alpha1_idx_0 = c1[k];
  } else if (((K[0] > ctrl_TAPM_P.C[12]) && (K[0] < ctrl_TAPM_P.C[18]) &&
              (B_surge[0] > 0.0)) || ((K[0] > ctrl_TAPM_P.C[12]) && (K[0] <
               ctrl_TAPM_P.C[18]) && (B_surge[0] < 0.0))) {
    /* '<S41>:1:109' */
    /* '<S41>:1:110' */
    c1[0] = ctrl_TAPM_P.C[12];
    c1[1] = ctrl_TAPM_P.C[18];
    c1_5[0] = ctrl_TAPM_P.C[12] - K[0];
    c1_5[1] = ctrl_TAPM_P.C[18] - K[0];
    ctrl_TAPM_abs(c1_5, varargin_1);
    res = 1;
    rtb_eta_w_idx_2 = varargin_1[0];
    k = 0;
    if (rtIsNaN(varargin_1[0])) {
      i = 2;
      exitg11 = false;
      while ((!exitg11) && (i < 3)) {
        res = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_eta_w_idx_2 = varargin_1[1];
          k = 1;
          exitg11 = true;
        } else {
          i = 3;
        }
      }
    }

    if ((res < 2) && (varargin_1[1] < rtb_eta_w_idx_2)) {
      k = 1;
    }

    /* '<S41>:1:112' */
    Alpha1_idx_0 = c1[k];
  } else {
    /* '<S41>:1:114' */
    Alpha1_idx_0 = K[0];
  }

  if (((rtb_TmpSignalConversionAtSFun_b[3] < ctrl_TAPM_P.C[0] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[3] > ctrl_TAPM_P.C[6] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[3] > ctrl_TAPM_P.C[12] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[3] < ctrl_TAPM_P.C[18] - 0.1))) {
    /* '<S41>:1:116' */
    /* '<S41>:1:117' */
    B_surge[0] = 0.0;
  } else {
    /* '<S41>:1:119' */
  }

  /*  Thruster 2  */
  /* C2 = [-99.85 -80.15 -50 -29]; */
  if (((K[1] < ctrl_TAPM_P.C[1]) && (K[1] > ctrl_TAPM_P.C[7]) && (B_surge[1] >
        0.0)) || ((K[1] < ctrl_TAPM_P.C[1]) && (K[1] > ctrl_TAPM_P.C[7]) &&
                  (B_surge[1] < 0.0))) {
    /* '<S41>:1:124' */
    /* '<S41>:1:125' */
    c1[0] = ctrl_TAPM_P.C[1];
    c1[1] = ctrl_TAPM_P.C[7];
    c1_4[0] = ctrl_TAPM_P.C[1] - K[1];
    c1_4[1] = ctrl_TAPM_P.C[7] - K[1];
    ctrl_TAPM_abs(c1_4, varargin_1);
    res = 1;
    rtb_eta_w_idx_2 = varargin_1[0];
    k = 0;
    if (rtIsNaN(varargin_1[0])) {
      i = 2;
      exitg11 = false;
      while ((!exitg11) && (i < 3)) {
        res = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_eta_w_idx_2 = varargin_1[1];
          k = 1;
          exitg11 = true;
        } else {
          i = 3;
        }
      }
    }

    if ((res < 2) && (varargin_1[1] < rtb_eta_w_idx_2)) {
      k = 1;
    }

    /* '<S41>:1:127' */
    rtb_TmpSignalConversionAtSFu__1 = c1[k];
  } else if (((K[1] < ctrl_TAPM_P.C[13]) && (K[1] > ctrl_TAPM_P.C[19]) &&
              (B_surge[1] > 0.0)) || ((K[1] < ctrl_TAPM_P.C[13]) && (K[1] >
               ctrl_TAPM_P.C[19]) && (B_surge[1] < 0.0))) {
    /* '<S41>:1:128' */
    /* '<S41>:1:129' */
    c1[0] = ctrl_TAPM_P.C[13];
    c1[1] = ctrl_TAPM_P.C[19];
    c1_4[0] = ctrl_TAPM_P.C[13] - K[1];
    c1_4[1] = ctrl_TAPM_P.C[19] - K[1];
    ctrl_TAPM_abs(c1_4, varargin_1);
    res = 1;
    rtb_eta_w_idx_2 = varargin_1[0];
    k = 0;
    if (rtIsNaN(varargin_1[0])) {
      i = 2;
      exitg11 = false;
      while ((!exitg11) && (i < 3)) {
        res = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_eta_w_idx_2 = varargin_1[1];
          k = 1;
          exitg11 = true;
        } else {
          i = 3;
        }
      }
    }

    if ((res < 2) && (varargin_1[1] < rtb_eta_w_idx_2)) {
      k = 1;
    }

    /* '<S41>:1:131' */
    rtb_TmpSignalConversionAtSFu__1 = c1[k];
  } else {
    /* '<S41>:1:133' */
    rtb_TmpSignalConversionAtSFu__1 = K[1];
  }

  if (((rtb_TmpSignalConversionAtSFun_b[4] < ctrl_TAPM_P.C[1] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[4] > ctrl_TAPM_P.C[7] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[4] < ctrl_TAPM_P.C[13] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[4] > ctrl_TAPM_P.C[19] + 0.1))) {
    /* '<S41>:1:135' */
    /* '<S41>:1:136' */
    B_surge[1] = 0.0;
  } else {
    /* '<S41>:1:138' */
  }

  /*  Thruster 3  */
  /*  C3 = [99.85 80.15 50 29];  */
  if (((K[2] > ctrl_TAPM_P.C[2]) && (K[2] < ctrl_TAPM_P.C[8]) && (B_surge[2] >
        0.0)) || ((K[2] > ctrl_TAPM_P.C[2]) && (K[2] < ctrl_TAPM_P.C[8]) &&
                  (B_surge[2] < 0.0))) {
    /* '<S41>:1:144' */
    /* '<S41>:1:145' */
    c1[0] = ctrl_TAPM_P.C[2];
    c1[1] = ctrl_TAPM_P.C[8];
    c1_3[0] = ctrl_TAPM_P.C[2] - K[2];
    c1_3[1] = ctrl_TAPM_P.C[8] - K[2];
    ctrl_TAPM_abs(c1_3, varargin_1);
    res = 1;
    rtb_eta_w_idx_2 = varargin_1[0];
    k = 0;
    if (rtIsNaN(varargin_1[0])) {
      i = 2;
      exitg11 = false;
      while ((!exitg11) && (i < 3)) {
        res = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_eta_w_idx_2 = varargin_1[1];
          k = 1;
          exitg11 = true;
        } else {
          i = 3;
        }
      }
    }

    if ((res < 2) && (varargin_1[1] < rtb_eta_w_idx_2)) {
      k = 1;
    }

    /* '<S41>:1:147' */
    rtb_TmpSignalConversionAtSFu__0 = c1[k];
  } else if (((K[2] > ctrl_TAPM_P.C[14]) && (K[2] < ctrl_TAPM_P.C[20]) &&
              (B_surge[2] > 0.0)) || ((K[2] > ctrl_TAPM_P.C[14]) && (K[2] <
               ctrl_TAPM_P.C[20]) && (B_surge[2] < 0.0))) {
    /* '<S41>:1:148' */
    /* '<S41>:1:149' */
    c1[0] = ctrl_TAPM_P.C[14];
    c1[1] = ctrl_TAPM_P.C[20];
    c1_3[0] = ctrl_TAPM_P.C[14] - K[2];
    c1_3[1] = ctrl_TAPM_P.C[20] - K[2];
    ctrl_TAPM_abs(c1_3, varargin_1);
    res = 1;
    rtb_eta_w_idx_2 = varargin_1[0];
    k = 0;
    if (rtIsNaN(varargin_1[0])) {
      i = 2;
      exitg11 = false;
      while ((!exitg11) && (i < 3)) {
        res = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_eta_w_idx_2 = varargin_1[1];
          k = 1;
          exitg11 = true;
        } else {
          i = 3;
        }
      }
    }

    if ((res < 2) && (varargin_1[1] < rtb_eta_w_idx_2)) {
      k = 1;
    }

    /* '<S41>:1:151' */
    rtb_TmpSignalConversionAtSFu__0 = c1[k];
  } else {
    /* '<S41>:1:153' */
    rtb_TmpSignalConversionAtSFu__0 = K[2];
  }

  if (((rtb_TmpSignalConversionAtSFun_b[5] > ctrl_TAPM_P.C[2] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[5] < ctrl_TAPM_P.C[8] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[5] > ctrl_TAPM_P.C[14] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[5] < ctrl_TAPM_P.C[20] - 0.1))) {
    /* '<S41>:1:155' */
    /* '<S41>:1:156' */
    B_surge[2] = 0.0;
  } else {
    /* '<S41>:1:158' */
  }

  /*  Thruster 4 OK */
  /* C4 = [-52.8 -34.2 52.8 34.2];  */
  if (((K[3] > ctrl_TAPM_P.C[3]) && (K[3] < ctrl_TAPM_P.C[9]) && (B_surge[3] >
        0.0)) || ((K[3] > ctrl_TAPM_P.C[3]) && (K[3] < ctrl_TAPM_P.C[9]) &&
                  (B_surge[3] < 0.0))) {
    /* '<S41>:1:163' */
    /* '<S41>:1:164' */
    c1[0] = ctrl_TAPM_P.C[3];
    c1[1] = ctrl_TAPM_P.C[9];
    c1_2[0] = ctrl_TAPM_P.C[3] - K[3];
    c1_2[1] = ctrl_TAPM_P.C[9] - K[3];
    ctrl_TAPM_abs(c1_2, varargin_1);
    res = 1;
    rtb_eta_w_idx_2 = varargin_1[0];
    k = 0;
    if (rtIsNaN(varargin_1[0])) {
      i = 2;
      exitg11 = false;
      while ((!exitg11) && (i < 3)) {
        res = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_eta_w_idx_2 = varargin_1[1];
          k = 1;
          exitg11 = true;
        } else {
          i = 3;
        }
      }
    }

    if ((res < 2) && (varargin_1[1] < rtb_eta_w_idx_2)) {
      k = 1;
    }

    /* '<S41>:1:166' */
    Alpha1_idx_3 = c1[k];
  } else if (((K[3] < ctrl_TAPM_P.C[15]) && (K[3] > ctrl_TAPM_P.C[21]) &&
              (B_surge[3] > 0.0)) || ((K[3] < ctrl_TAPM_P.C[15]) && (K[3] >
               ctrl_TAPM_P.C[21]) && (B_surge[3] < 0.0))) {
    /* '<S41>:1:167' */
    /* '<S41>:1:168' */
    c1[0] = ctrl_TAPM_P.C[15];
    c1[1] = ctrl_TAPM_P.C[21];
    c1_2[0] = ctrl_TAPM_P.C[15] - K[3];
    c1_2[1] = ctrl_TAPM_P.C[21] - K[3];
    ctrl_TAPM_abs(c1_2, varargin_1);
    res = 1;
    rtb_eta_w_idx_2 = varargin_1[0];
    k = 0;
    if (rtIsNaN(varargin_1[0])) {
      i = 2;
      exitg11 = false;
      while ((!exitg11) && (i < 3)) {
        res = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_eta_w_idx_2 = varargin_1[1];
          k = 1;
          exitg11 = true;
        } else {
          i = 3;
        }
      }
    }

    if ((res < 2) && (varargin_1[1] < rtb_eta_w_idx_2)) {
      k = 1;
    }

    /* '<S41>:1:170' */
    Alpha1_idx_3 = c1[k];
  } else {
    /* '<S41>:1:172' */
    Alpha1_idx_3 = K[3];
  }

  if (((rtb_TmpSignalConversionAtSFun_b[6] > ctrl_TAPM_P.C[3] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[6] < ctrl_TAPM_P.C[9] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[6] < ctrl_TAPM_P.C[15] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[6] > ctrl_TAPM_P.C[21] + 0.1))) {
    /* '<S41>:1:174' */
    /* '<S41>:1:175' */
    B_surge[3] = 0.0;
  } else {
    /* '<S41>:1:177' */
  }

  /*  Thruster 5 */
  /* C5 = [-98.25 -81.75 -145.8 -127.2]; */
  if (((K[4] < ctrl_TAPM_P.C[4]) && (K[4] > ctrl_TAPM_P.C[10]) && (B_surge[4] >
        0.0)) || ((K[4] < ctrl_TAPM_P.C[4]) && (K[4] > ctrl_TAPM_P.C[10]) &&
                  (B_surge[4] < 0.0))) {
    /* '<S41>:1:182' */
    /* '<S41>:1:183' */
    c1[0] = ctrl_TAPM_P.C[4];
    c1[1] = ctrl_TAPM_P.C[10];
    c1_1[0] = ctrl_TAPM_P.C[4] - K[4];
    c1_1[1] = ctrl_TAPM_P.C[10] - K[4];
    ctrl_TAPM_abs(c1_1, varargin_1);
    res = 1;
    rtb_eta_w_idx_2 = varargin_1[0];
    k = 0;
    if (rtIsNaN(varargin_1[0])) {
      i = 2;
      exitg11 = false;
      while ((!exitg11) && (i < 3)) {
        res = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_eta_w_idx_2 = varargin_1[1];
          k = 1;
          exitg11 = true;
        } else {
          i = 3;
        }
      }
    }

    if ((res < 2) && (varargin_1[1] < rtb_eta_w_idx_2)) {
      k = 1;
    }

    /* '<S41>:1:185' */
    Alpha1_idx_4 = c1[k];
  } else if (((K[4] < ctrl_TAPM_P.C[16]) && (K[4] > ctrl_TAPM_P.C[22]) &&
              (B_surge[4] > 0.0)) || ((K[4] < ctrl_TAPM_P.C[16]) && (K[4] >
               ctrl_TAPM_P.C[22]) && (B_surge[4] < 0.0))) {
    /* '<S41>:1:186' */
    /* '<S41>:1:187' */
    c1[0] = ctrl_TAPM_P.C[16];
    c1[1] = ctrl_TAPM_P.C[22];
    c1_1[0] = ctrl_TAPM_P.C[16] - K[4];
    c1_1[1] = ctrl_TAPM_P.C[22] - K[4];
    ctrl_TAPM_abs(c1_1, varargin_1);
    res = 1;
    rtb_eta_w_idx_2 = varargin_1[0];
    k = 0;
    if (rtIsNaN(varargin_1[0])) {
      i = 2;
      exitg11 = false;
      while ((!exitg11) && (i < 3)) {
        res = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_eta_w_idx_2 = varargin_1[1];
          k = 1;
          exitg11 = true;
        } else {
          i = 3;
        }
      }
    }

    if ((res < 2) && (varargin_1[1] < rtb_eta_w_idx_2)) {
      k = 1;
    }

    /* '<S41>:1:189' */
    Alpha1_idx_4 = c1[k];
  } else {
    /* '<S41>:1:191' */
    Alpha1_idx_4 = K[4];
  }

  if (((rtb_TmpSignalConversionAtSFun_b[7] < ctrl_TAPM_P.C[4] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[7] > ctrl_TAPM_P.C[10] + 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[7] < ctrl_TAPM_P.C[16] - 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[7] > ctrl_TAPM_P.C[22] + 0.1))) {
    /* '<S41>:1:193' */
    /* '<S41>:1:194' */
    B_surge[4] = 0.0;
  } else {
    /* '<S41>:1:196' */
  }

  /*  Thruster 6 */
  /* C6 = [98.75 81.75 145.8 127.2]; */
  if (((K[5] > ctrl_TAPM_P.C[5]) && (K[5] < ctrl_TAPM_P.C[11]) && (B_surge[5] >
        0.0)) || ((K[5] > ctrl_TAPM_P.C[5]) && (K[5] < ctrl_TAPM_P.C[11]) &&
                  (B_surge[5] < 0.0))) {
    /* '<S41>:1:201' */
    /* '<S41>:1:202' */
    c1[0] = ctrl_TAPM_P.C[5];
    c1[1] = ctrl_TAPM_P.C[11];
    c1_0[0] = ctrl_TAPM_P.C[5] - K[5];
    c1_0[1] = ctrl_TAPM_P.C[11] - K[5];
    ctrl_TAPM_abs(c1_0, varargin_1);
    res = 1;
    rtb_eta_w_idx_2 = varargin_1[0];
    k = 0;
    if (rtIsNaN(varargin_1[0])) {
      i = 2;
      exitg11 = false;
      while ((!exitg11) && (i < 3)) {
        res = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_eta_w_idx_2 = varargin_1[1];
          k = 1;
          exitg11 = true;
        } else {
          i = 3;
        }
      }
    }

    if ((res < 2) && (varargin_1[1] < rtb_eta_w_idx_2)) {
      k = 1;
    }

    /* '<S41>:1:204' */
    rtb_eta_w_idx_0 = c1[k];
  } else if (((K[5] > ctrl_TAPM_P.C[17]) && (K[5] < ctrl_TAPM_P.C[23]) &&
              (B_surge[5] > 0.0)) || ((K[5] > ctrl_TAPM_P.C[17]) && (K[5] <
               ctrl_TAPM_P.C[23]) && (B_surge[5] < 0.0))) {
    /* '<S41>:1:205' */
    /* '<S41>:1:206' */
    c1[0] = ctrl_TAPM_P.C[17];
    c1[1] = ctrl_TAPM_P.C[23];
    c1_0[0] = ctrl_TAPM_P.C[17] - K[5];
    c1_0[1] = ctrl_TAPM_P.C[23] - K[5];
    ctrl_TAPM_abs(c1_0, varargin_1);
    res = 1;
    rtb_eta_w_idx_2 = varargin_1[0];
    k = 0;
    if (rtIsNaN(varargin_1[0])) {
      i = 2;
      exitg11 = false;
      while ((!exitg11) && (i < 3)) {
        res = 2;
        if (!rtIsNaN(varargin_1[1])) {
          rtb_eta_w_idx_2 = varargin_1[1];
          k = 1;
          exitg11 = true;
        } else {
          i = 3;
        }
      }
    }

    if ((res < 2) && (varargin_1[1] < rtb_eta_w_idx_2)) {
      k = 1;
    }

    /* '<S41>:1:208' */
    rtb_eta_w_idx_0 = c1[k];
  } else {
    /* '<S41>:1:210' */
    rtb_eta_w_idx_0 = K[5];
  }

  if (((rtb_TmpSignalConversionAtSFun_b[8] > ctrl_TAPM_P.C[5] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[8] < ctrl_TAPM_P.C[11] - 0.1)) ||
      ((rtb_TmpSignalConversionAtSFun_b[8] > ctrl_TAPM_P.C[17] + 0.1) &&
       (rtb_TmpSignalConversionAtSFun_b[8] < ctrl_TAPM_P.C[23] - 0.1))) {
    /* '<S41>:1:212' */
    /* '<S41>:1:213' */
    B_surge[5] = 0.0;
  } else {
    /* '<S41>:1:215' */
  }

  /*  Thruster 2&3  */
  if (rtb_TmpSignalConversionAtSFu__1 == ctrl_TAPM_P.C[7]) {
    /* '<S41>:1:219' */
    /* '<S41>:1:220' */
    rtb_TmpSignalConversionAtSFu__0 = K[1] - (ctrl_TAPM_P.C[7] - K[1]);
  } else if (rtb_TmpSignalConversionAtSFu__1 == ctrl_TAPM_P.C[1]) {
    /* '<S41>:1:221' */
    /* '<S41>:1:222' */
    rtb_TmpSignalConversionAtSFu__0 = K[1] - (ctrl_TAPM_P.C[1] - K[1]);
  } else if (rtb_TmpSignalConversionAtSFu__1 == ctrl_TAPM_P.C[13]) {
    /* '<S41>:1:223' */
    /* '<S41>:1:224' */
    rtb_TmpSignalConversionAtSFu__0 = K[1] - (ctrl_TAPM_P.C[13] - K[1]);
  } else if (rtb_TmpSignalConversionAtSFu__1 == ctrl_TAPM_P.C[19]) {
    /* '<S41>:1:225' */
    /* '<S41>:1:226' */
    rtb_TmpSignalConversionAtSFu__0 = K[1] - (ctrl_TAPM_P.C[19] - K[1]);
  } else if (rtb_TmpSignalConversionAtSFu__0 == ctrl_TAPM_P.C[8]) {
    /* '<S41>:1:228' */
    /* '<S41>:1:229' */
    rtb_TmpSignalConversionAtSFu__1 = K[2] - (ctrl_TAPM_P.C[8] - K[2]);
  } else if (rtb_TmpSignalConversionAtSFu__0 == ctrl_TAPM_P.C[2]) {
    /* '<S41>:1:230' */
    /* '<S41>:1:231' */
    rtb_TmpSignalConversionAtSFu__1 = K[2] - (ctrl_TAPM_P.C[2] - K[2]);
  } else if (rtb_TmpSignalConversionAtSFu__0 == ctrl_TAPM_P.C[14]) {
    /* '<S41>:1:232' */
    /* '<S41>:1:233' */
    rtb_TmpSignalConversionAtSFu__1 = K[2] - (ctrl_TAPM_P.C[14] - K[2]);
  } else {
    if (rtb_TmpSignalConversionAtSFu__0 == ctrl_TAPM_P.C[20]) {
      /* '<S41>:1:234' */
      /* '<S41>:1:235' */
      rtb_TmpSignalConversionAtSFu__1 = K[2] - (ctrl_TAPM_P.C[20] - K[2]);
    }
  }

  /*  Thruster 5&6 */
  if (Alpha1_idx_4 == ctrl_TAPM_P.C[10]) {
    /* '<S41>:1:239' */
    /* '<S41>:1:240' */
    rtb_eta_w_idx_0 = K[4] - (ctrl_TAPM_P.C[10] - K[4]);
  } else if (Alpha1_idx_4 == ctrl_TAPM_P.C[4]) {
    /* '<S41>:1:241' */
    /* '<S41>:1:242' */
    rtb_eta_w_idx_0 = K[4] - (ctrl_TAPM_P.C[4] - K[4]);
  } else if (Alpha1_idx_4 == ctrl_TAPM_P.C[16]) {
    /* '<S41>:1:243' */
    /* '<S41>:1:244' */
    rtb_eta_w_idx_0 = K[4] - (ctrl_TAPM_P.C[16] - K[4]);
  } else if (Alpha1_idx_4 == ctrl_TAPM_P.C[22]) {
    /* '<S41>:1:245' */
    /* '<S41>:1:246' */
    rtb_eta_w_idx_0 = K[4] - (ctrl_TAPM_P.C[22] - K[4]);
  } else if (rtb_eta_w_idx_0 == ctrl_TAPM_P.C[11]) {
    /* '<S41>:1:248' */
    /* '<S41>:1:249' */
    Alpha1_idx_4 = K[5] - (ctrl_TAPM_P.C[11] - K[5]);
  } else if (rtb_eta_w_idx_0 == ctrl_TAPM_P.C[5]) {
    /* '<S41>:1:250' */
    /* '<S41>:1:251' */
    Alpha1_idx_4 = K[5] - (ctrl_TAPM_P.C[5] - K[5]);
  } else if (rtb_eta_w_idx_0 == ctrl_TAPM_P.C[17]) {
    /* '<S41>:1:252' */
    /* '<S41>:1:253' */
    Alpha1_idx_4 = K[5] - (ctrl_TAPM_P.C[17] - K[5]);
  } else {
    if (rtb_eta_w_idx_0 == ctrl_TAPM_P.C[23]) {
      /* '<S41>:1:254' */
      /* '<S41>:1:255' */
      Alpha1_idx_4 = K[5] - (ctrl_TAPM_P.C[23] - K[5]);
    }
  }

  /*  Thruster 4 & 1 */
  if (Alpha1_idx_3 == ctrl_TAPM_P.C[9]) {
    /* '<S41>:1:258' */
    /* '<S41>:1:259' */
    Alpha1_idx_0 = K[3] - (ctrl_TAPM_P.C[9] - K[3]);
  } else if (Alpha1_idx_3 == ctrl_TAPM_P.C[3]) {
    /* '<S41>:1:260' */
    /* '<S41>:1:261' */
    Alpha1_idx_0 = K[3] - (ctrl_TAPM_P.C[3] - K[3]);
  } else if (Alpha1_idx_3 == ctrl_TAPM_P.C[15]) {
    /* '<S41>:1:262' */
    /* '<S41>:1:263' */
    Alpha1_idx_0 = K[3] - (ctrl_TAPM_P.C[15] - K[3]);
  } else {
    if (Alpha1_idx_3 == ctrl_TAPM_P.C[21]) {
      /* '<S41>:1:264' */
      /* '<S41>:1:265' */
      Alpha1_idx_0 = K[3] - (ctrl_TAPM_P.C[21] - K[3]);
    }
  }

  if (Alpha1_idx_0 == ctrl_TAPM_P.C[6]) {
    /* '<S41>:1:268' */
    /* '<S41>:1:269' */
    Alpha1_idx_3 = K[0] - (ctrl_TAPM_P.C[6] - K[0]);
  } else if (Alpha1_idx_0 == ctrl_TAPM_P.C[0]) {
    /* '<S41>:1:270' */
    /* '<S41>:1:271' */
    Alpha1_idx_3 = K[0] - (ctrl_TAPM_P.C[0] - K[0]);
  } else if (Alpha1_idx_0 == ctrl_TAPM_P.C[12]) {
    /* '<S41>:1:272' */
    /* '<S41>:1:273' */
    Alpha1_idx_3 = K[0] - (ctrl_TAPM_P.C[12] - K[0]);
  } else {
    if (Alpha1_idx_0 == ctrl_TAPM_P.C[18]) {
      /* '<S41>:1:274' */
      /* '<S41>:1:275' */
      Alpha1_idx_3 = K[0] - (ctrl_TAPM_P.C[18] - K[0]);
    }
  }

  /* '<S41>:1:278' */
  /*  u_d = -Desired_thrust; */
  /* % Update outputs */
  /* '<S41>:1:285' */
  rtb_sys[0] = Alpha1_idx_0;
  rtb_sys[1] = rtb_TmpSignalConversionAtSFu__1;
  rtb_sys[2] = rtb_TmpSignalConversionAtSFu__0;
  rtb_sys[3] = Alpha1_idx_3;
  rtb_sys[4] = Alpha1_idx_4;
  rtb_sys[5] = rtb_eta_w_idx_0;
  for (i_0 = 0; i_0 < 6; i_0++) {
    rtb_sys[i_0 + 6] = B_surge[i_0];
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
  }

  /* Switch: '<S6>/Choosing Fixed // Azimuth angle' incorporates:
   *  Constant: '<S6>/constant angle'
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

  /* End of Switch: '<S6>/Choosing Fixed // Azimuth angle' */

  /* Outputs for Iterator SubSystem: '<S6>/Optimal angle path and  constraints on rotation speed' incorporates:
   *  ForEach: '<S42>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
    /* ForEachSliceSelector: '<S42>/ImpSel_InsertedFor_reset_at_outport_0' */
    rtb_ImpSel_InsertedFor_reset_at = ctrl_TAPM_B.reset[ForEach_itr];
    if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
      /* DiscreteIntegrator: '<S42>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S6>/constant angle'
       *  ForEachSliceSelector: '<S42>/ImpSel_InsertedFor_initial angle _at_outport_0'
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

      /* End of DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */

      /* Gain: '<S45>/Gain1' */
      rtb_eta_w_idx_2 = ctrl_TAPM_P.CoreSubsys.Gain1_Gain *
        ctrl_TAPM_B.CoreSubsys[ForEach_itr].angle;

      /* Delay: '<S42>/Delay' */
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].Delay =
        ctrl_TAPM_DW.CoreSubsys[ForEach_itr].Delay_DSTATE;

      /* MATLAB Function: '<S42>/MATLAB Function' */
      /* MATLAB Function 'Thrust allocation/Optimal angle path and  constraints on rotation speed/MATLAB Function': '<S46>:1' */
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
      /* '<S46>:1:39' */
      /* '<S46>:1:40' */
      /*  s = sign(angle); */
      /* '<S46>:1:43' */
      u = fabs(rt_remd_snf(rtb_eta_w_idx_2 + 3.1415926535897931,
                           6.2831853071795862) / 6.2831853071795862);
      if (rtb_eta_w_idx_2 < 0.0) {
        Alpha1_idx_0 = -1.0;
      } else if (rtb_eta_w_idx_2 > 0.0) {
        Alpha1_idx_0 = 1.0;
      } else if (rtb_eta_w_idx_2 == 0.0) {
        Alpha1_idx_0 = 0.0;
      } else {
        Alpha1_idx_0 = rtb_eta_w_idx_2;
      }

      if (u > 0.0) {
        u = 1.0;
      } else {
        if (u == 0.0) {
          u = 0.0;
        }
      }

      u = (u - 1.0) * 2.0 + Alpha1_idx_0;
      if (rtb_eta_w_idx_2 < 0.0) {
        Alpha1_idx_0 = -1.0;
      } else if (rtb_eta_w_idx_2 > 0.0) {
        Alpha1_idx_0 = 1.0;
      } else if (rtb_eta_w_idx_2 == 0.0) {
        Alpha1_idx_0 = 0.0;
      } else {
        Alpha1_idx_0 = rtb_eta_w_idx_2;
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

      rtb_Out2_CoreSubsysCanOut = rt_remd_snf(Alpha1_idx_0 * 3.1415926535897931
        + rtb_eta_w_idx_2, 6.2831853071795862) - u * 3.1415926535897931;

      /* End of MATLAB Function: '<S42>/MATLAB Function' */
    }

    /* MATLAB Function: '<S42>/MATLAB Function1' incorporates:
     *  ForEachSliceSelector: '<S42>/ImpSel_InsertedFor_Desired Angle_at_outport_0'
     */
    /* MATLAB Function 'Thrust allocation/Optimal angle path and  constraints on rotation speed/MATLAB Function1': '<S47>:1' */
    /* '<S47>:1:3' */
    rtb_eta_w_idx_2 = ctrl_TAPM_B.ChoosingFixedAzimuthangle[ForEach_itr] -
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].Delay;
    if (fabs(rtb_eta_w_idx_2) >= 360.0) {
      /* '<S47>:1:4' */
      /* '<S47>:1:5' */
      rtb_eta_w_idx_2 = rt_remd_snf(rtb_eta_w_idx_2, 360.0);
    }

    if (fabs(rtb_eta_w_idx_2) >= 180.0) {
      /* '<S47>:1:8' */
      /* '<S47>:1:9' */
      if (rtb_eta_w_idx_2 < 0.0) {
        Alpha1_idx_0 = -1.0;
      } else if (rtb_eta_w_idx_2 > 0.0) {
        Alpha1_idx_0 = 1.0;
      } else if (rtb_eta_w_idx_2 == 0.0) {
        Alpha1_idx_0 = 0.0;
      } else {
        Alpha1_idx_0 = rtb_eta_w_idx_2;
      }

      rtb_eta_w_idx_2 -= Alpha1_idx_0 * 360.0;
    }

    /* End of MATLAB Function: '<S42>/MATLAB Function1' */

    /* Saturate: '<S42>/Max Rotation Rate' */
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
    if (rtb_eta_w_idx_2 > ctrl_TAPM_P.Max_rotation) {
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate =
        ctrl_TAPM_P.Max_rotation;
    } else if (rtb_eta_w_idx_2 < -ctrl_TAPM_P.Max_rotation) {
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate =
        -ctrl_TAPM_P.Max_rotation;
    } else {
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate = rtb_eta_w_idx_2;
    }

    /* End of Saturate: '<S42>/Max Rotation Rate' */
    if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
      /* ForEachSliceAssignment: '<S42>/ImpAsg_InsertedFor_Out2 _at_inport_0' */
      rtb_ImpAsg_InsertedFor_Out2_at_[ForEach_itr] = rtb_Out2_CoreSubsysCanOut;
    }
  }

  /* End of Outputs for SubSystem: '<S6>/Optimal angle path and  constraints on rotation speed' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Saturate: '<S48>/Saturation 1' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[0] > ctrl_TAPM_P.Saturation1_UpperSat) {
      ctrl_TAPM_B.Saturation1 = ctrl_TAPM_P.Saturation1_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[0] <
               ctrl_TAPM_P.Saturation1_LowerSat) {
      ctrl_TAPM_B.Saturation1 = ctrl_TAPM_P.Saturation1_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation1 = rtb_ImpAsg_InsertedFor_Out2_at_[0];
    }

    /* End of Saturate: '<S48>/Saturation 1' */
  }

  /* Integrator: '<S64>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_TAPM_B.reset_o);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_c = ctrl_TAPM_P.Integrator_IC_fg;
    }
  }

  rtb_Integrator_p = ctrl_TAPM_X.Integrator_CSTATE_c;

  /* MATLAB Function: '<S63>/Actual Force and Torque' incorporates:
   *  Constant: '<S50>/Losses (placeholder)'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Qr1'
   *  Constant: '<S7>/K_Qr7'
   *  Constant: '<S7>/K_Tf1'
   *  Constant: '<S7>/K_Tr1'
   *  Constant: '<S7>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque': '<S66>:1' */
  /* '<S66>:1:3' */
  offset = tanh(ctrl_TAPM_P.eps_c * rtb_Integrator_p / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S66>:1:4' */
  /* '<S66>:1:5' */
  /* '<S66>:1:7' */
  if (rtb_Integrator_p < 0.0) {
    rtb_eta_w_idx_0 = -1.0;
  } else if (rtb_Integrator_p > 0.0) {
    rtb_eta_w_idx_0 = 1.0;
  } else if (rtb_Integrator_p == 0.0) {
    rtb_eta_w_idx_0 = 0.0;
  } else {
    rtb_eta_w_idx_0 = rtb_Integrator_p;
  }

  rtb_Ta = ((1.0 - offset) * ctrl_TAPM_P.K_T1r + ctrl_TAPM_P.K_T1f * offset) *
    rtb_eta_w_idx_0 * ctrl_TAPM_P.Rho * rt_powd_snf(ctrl_TAPM_P.D, 4.0) *
    (rtb_Integrator_p * rtb_Integrator_p) - ctrl_TAPM_P.Lossesplaceholder_Value;

  /* '<S66>:1:8' */
  if (rtb_Integrator_p < 0.0) {
    rtb_eta_w_idx_0 = -1.0;
  } else if (rtb_Integrator_p > 0.0) {
    rtb_eta_w_idx_0 = 1.0;
  } else if (rtb_Integrator_p == 0.0) {
    rtb_eta_w_idx_0 = 0.0;
  } else {
    rtb_eta_w_idx_0 = rtb_Integrator_p;
  }

  rtb_eta_w_idx_2 = ((1.0 - offset) * ctrl_TAPM_P.K_q1r + ctrl_TAPM_P.K_q1f *
                     offset) * rtb_eta_w_idx_0 * ctrl_TAPM_P.Rho * rt_powd_snf
    (ctrl_TAPM_P.D, 5.0) * (rtb_Integrator_p * rtb_Integrator_p) -
    ctrl_TAPM_P.Lossesplaceholder_Value;

  /* '<S66>:1:9' */
  ctrl_TAPM_B.Pa = 6.2831853071795862 * rtb_Integrator_p * rtb_eta_w_idx_2;
  ctrl_TAPM_B.Qa = rtb_eta_w_idx_2;

  /* End of MATLAB Function: '<S63>/Actual Force and Torque' */

  /* Integrator: '<S73>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_n,
                       ctrl_TAPM_B.reset_c);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_p = ctrl_TAPM_P.Integrator_IC_fgw;
    }
  }

  rtb_Integrator_h = ctrl_TAPM_X.Integrator_CSTATE_p;

  /* MATLAB Function: '<S72>/Actual Force and Torque' incorporates:
   *  Constant: '<S51>/Losses (placeholder)'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Qr2'
   *  Constant: '<S7>/K_Qr8'
   *  Constant: '<S7>/K_Tf2'
   *  Constant: '<S7>/K_Tr2'
   *  Constant: '<S7>/Rho'
   */
  ctrl_TAPM_ActualForceandTorque(rtb_Integrator_h, ctrl_TAPM_P.K_q2f,
    ctrl_TAPM_P.K_T2f, ctrl_TAPM_P.K_T2r, ctrl_TAPM_P.K_q2r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_k,
    &ctrl_TAPM_B.sf_ActualForceandTorque_f);

  /* Integrator: '<S82>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_o,
                       ctrl_TAPM_B.reset_j);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_km = ctrl_TAPM_P.Integrator_IC_pl;
    }
  }

  rtb_Integrator_a = ctrl_TAPM_X.Integrator_CSTATE_km;

  /* MATLAB Function: '<S81>/Actual Force and Torque' incorporates:
   *  Constant: '<S52>/Losses (placeholder)'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Qr3'
   *  Constant: '<S7>/K_Qr9'
   *  Constant: '<S7>/K_Tf3'
   *  Constant: '<S7>/K_Tr3'
   *  Constant: '<S7>/Rho'
   */
  ctrl_TAPM_ActualForceandTorque(rtb_Integrator_a, ctrl_TAPM_P.K_q3f,
    ctrl_TAPM_P.K_T3f, ctrl_TAPM_P.K_T3r, ctrl_TAPM_P.K_q3r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_n,
    &ctrl_TAPM_B.sf_ActualForceandTorque_h);

  /* Integrator: '<S91>/Integrator' */
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

  /* MATLAB Function: '<S90>/Actual Force and Torque' incorporates:
   *  Constant: '<S53>/Losses (placeholder)'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Qr10'
   *  Constant: '<S7>/K_Qr4'
   *  Constant: '<S7>/K_Tf4'
   *  Constant: '<S7>/K_Tr4'
   *  Constant: '<S7>/Rho'
   */
  ctrl_TAPM_ActualForceandTorque(rtb_Integrator_k, ctrl_TAPM_P.K_q4f,
    ctrl_TAPM_P.K_T4f, ctrl_TAPM_P.K_T4r, ctrl_TAPM_P.K_q4r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_d,
    &ctrl_TAPM_B.sf_ActualForceandTorque_m);

  /* Integrator: '<S100>/Integrator' */
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

  /* MATLAB Function: '<S99>/Actual Force and Torque' incorporates:
   *  Constant: '<S54>/Losses (placeholder)'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Qr11'
   *  Constant: '<S7>/K_Qr5'
   *  Constant: '<S7>/K_Tf5'
   *  Constant: '<S7>/K_Tr5'
   *  Constant: '<S7>/Rho'
   */
  ctrl_TAPM_ActualForceandTorque(rtb_Integrator_c, ctrl_TAPM_P.K_q5f,
    ctrl_TAPM_P.K_T5f, ctrl_TAPM_P.K_T5r, ctrl_TAPM_P.K_q5r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_f,
    &ctrl_TAPM_B.sf_ActualForceandTorque_o);

  /* Integrator: '<S109>/Integrator' */
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

  /* MATLAB Function: '<S108>/Actual Force and Torque' incorporates:
   *  Constant: '<S55>/Losses (placeholder)'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Qr12'
   *  Constant: '<S7>/K_Qr6'
   *  Constant: '<S7>/K_Tf6'
   *  Constant: '<S7>/K_Tr6'
   *  Constant: '<S7>/Rho'
   */
  ctrl_TAPM_ActualForceandTorque(rtb_Integrator_m, ctrl_TAPM_P.K_q6f,
    ctrl_TAPM_P.K_T6f, ctrl_TAPM_P.K_T6r, ctrl_TAPM_P.K_q6r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.Lossesplaceholder_Value_h,
    &ctrl_TAPM_B.sf_ActualForceandTorque_j);

  /* MATLAB Function: '<S49>/MATLAB Function' incorporates:
   *  Gain: '<S49>/Gain'
   *  Gain: '<S49>/Gain1'
   *  Gain: '<S49>/Gain2'
   *  Gain: '<S49>/Gain3'
   *  Gain: '<S49>/Gain4'
   *  Gain: '<S49>/Gain5'
   *  SignalConversion: '<S56>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function': '<S56>:1' */
  if (ctrl_TAPM_B.Core_controller == 1.0) {
    /* '<S56>:1:3' */
    /* '<S56>:1:4' */
    ctrl_TAPM_B.output[0] = rtb_Ta;
    ctrl_TAPM_B.output[1] = ctrl_TAPM_P.Gain_Gain_d * ctrl_TAPM_B.rpm1;
    ctrl_TAPM_B.output[2] = ctrl_TAPM_B.sf_ActualForceandTorque_f.Ta;
    ctrl_TAPM_B.output[3] = ctrl_TAPM_P.Gain1_Gain * ctrl_TAPM_B.rpm2;
    ctrl_TAPM_B.output[4] = ctrl_TAPM_B.sf_ActualForceandTorque_h.Ta;
    ctrl_TAPM_B.output[5] = ctrl_TAPM_P.Gain2_Gain * ctrl_TAPM_B.rpm3;
    ctrl_TAPM_B.output[6] = ctrl_TAPM_B.sf_ActualForceandTorque_m.Ta;
    ctrl_TAPM_B.output[7] = ctrl_TAPM_P.Gain3_Gain * ctrl_TAPM_B.rpm4;
    ctrl_TAPM_B.output[8] = ctrl_TAPM_B.sf_ActualForceandTorque_o.Ta;
    ctrl_TAPM_B.output[9] = ctrl_TAPM_P.Gain4_Gain * ctrl_TAPM_B.rpm5;
    ctrl_TAPM_B.output[10] = ctrl_TAPM_B.sf_ActualForceandTorque_j.Ta;
    ctrl_TAPM_B.output[11] = ctrl_TAPM_P.Gain5_Gain * ctrl_TAPM_B.rpm6;

    /*      output = [input(1) input(2) input(3) input(4) input(5) input(6) input(7) input(8) input(9) input(10) input(11) input(12)]'; */
  } else {
    /* '<S56>:1:8' */
    ctrl_TAPM_B.output[0] = rtb_Ta;
    ctrl_TAPM_B.output[1] = rtb_Integrator_p;
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
  }

  /* End of MATLAB Function: '<S49>/MATLAB Function' */

  /* Saturate: '<S49>/Saturation 8' */
  if (ctrl_TAPM_B.output[2] > ctrl_TAPM_P.Max_thrust) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[2] < ctrl_TAPM_P.Saturation8_LowerSat) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation8_LowerSat;
  } else {
    rtb_eta_w_idx_2 = ctrl_TAPM_B.output[2];
  }

  /* End of Saturate: '<S49>/Saturation 8' */

  /* Polyval: '<S49>/positive thrust 2' */
  rtb_positivethrust2 = ctrl_TAPM_P.pwm_thr2_forward[0];
  for (res = 0; res < 5; res++) {
    rtb_positivethrust2 = rtb_positivethrust2 * rtb_eta_w_idx_2 +
      ctrl_TAPM_P.pwm_thr2_forward[res + 1];
  }

  /* End of Polyval: '<S49>/positive thrust 2' */

  /* Saturate: '<S49>/Saturation 9' */
  if (ctrl_TAPM_B.output[2] > ctrl_TAPM_P.Saturation9_UpperSat) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation9_UpperSat;
  } else if (ctrl_TAPM_B.output[2] < ctrl_TAPM_P.Min_thrust) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Min_thrust;
  } else {
    rtb_eta_w_idx_2 = ctrl_TAPM_B.output[2];
  }

  /* End of Saturate: '<S49>/Saturation 9' */

  /* Polyval: '<S49>/negative thrust 2' */
  rtb_negativethrust2 = ctrl_TAPM_P.pwm_thr2_backward[0];
  for (res = 0; res < 5; res++) {
    rtb_negativethrust2 = rtb_negativethrust2 * rtb_eta_w_idx_2 +
      ctrl_TAPM_P.pwm_thr2_backward[res + 1];
  }

  /* End of Polyval: '<S49>/negative thrust 2' */

  /* MATLAB Function: '<S49>/MATLAB Function2' */
  ctrl_TAPM_MATLABFunction2_i(rtb_positivethrust2, ctrl_TAPM_B.output[2],
    rtb_negativethrust2, &ctrl_TAPM_B.sf_MATLABFunction2_i);

  /* Saturate: '<S49>/Saturation 10' */
  if (ctrl_TAPM_B.output[4] > ctrl_TAPM_P.Max_thrust) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[4] < ctrl_TAPM_P.Saturation10_LowerSat) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation10_LowerSat;
  } else {
    rtb_eta_w_idx_2 = ctrl_TAPM_B.output[4];
  }

  /* End of Saturate: '<S49>/Saturation 10' */

  /* Polyval: '<S49>/positive thrust 3' */
  rtb_positivethrust3 = ctrl_TAPM_P.pwm_thr3_forward[0];
  for (res = 0; res < 5; res++) {
    rtb_positivethrust3 = rtb_positivethrust3 * rtb_eta_w_idx_2 +
      ctrl_TAPM_P.pwm_thr3_forward[res + 1];
  }

  /* End of Polyval: '<S49>/positive thrust 3' */

  /* Saturate: '<S49>/Saturation 11' */
  if (ctrl_TAPM_B.output[4] > ctrl_TAPM_P.Saturation11_UpperSat) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation11_UpperSat;
  } else if (ctrl_TAPM_B.output[4] < ctrl_TAPM_P.Min_thrust) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Min_thrust;
  } else {
    rtb_eta_w_idx_2 = ctrl_TAPM_B.output[4];
  }

  /* End of Saturate: '<S49>/Saturation 11' */

  /* Polyval: '<S49>/negative thrust 3' */
  rtb_negativethrust3 = ctrl_TAPM_P.pwm_thr3_backward[0];
  for (res = 0; res < 5; res++) {
    rtb_negativethrust3 = rtb_negativethrust3 * rtb_eta_w_idx_2 +
      ctrl_TAPM_P.pwm_thr3_backward[res + 1];
  }

  /* End of Polyval: '<S49>/negative thrust 3' */

  /* MATLAB Function: '<S49>/MATLAB Function3' */
  ctrl_TAPM_MATLABFunction2_i(rtb_positivethrust3, ctrl_TAPM_B.output[4],
    rtb_negativethrust3, &ctrl_TAPM_B.sf_MATLABFunction3_p);

  /* Saturate: '<S49>/Saturation 3' */
  if (ctrl_TAPM_B.output[6] > ctrl_TAPM_P.Max_thrust) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[6] < ctrl_TAPM_P.Saturation3_LowerSat) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation3_LowerSat;
  } else {
    rtb_eta_w_idx_2 = ctrl_TAPM_B.output[6];
  }

  /* End of Saturate: '<S49>/Saturation 3' */

  /* Polyval: '<S49>/positive thrust 4' */
  rtb_positivethrust4 = ctrl_TAPM_P.pwm_thr4_forward[0];
  for (res = 0; res < 5; res++) {
    rtb_positivethrust4 = rtb_positivethrust4 * rtb_eta_w_idx_2 +
      ctrl_TAPM_P.pwm_thr4_forward[res + 1];
  }

  /* End of Polyval: '<S49>/positive thrust 4' */

  /* Saturate: '<S49>/Saturation 4' */
  if (ctrl_TAPM_B.output[6] > ctrl_TAPM_P.Saturation4_UpperSat) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation4_UpperSat;
  } else if (ctrl_TAPM_B.output[6] < ctrl_TAPM_P.Min_thrust) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Min_thrust;
  } else {
    rtb_eta_w_idx_2 = ctrl_TAPM_B.output[6];
  }

  /* End of Saturate: '<S49>/Saturation 4' */

  /* Polyval: '<S49>/negative thrust 4' */
  rtb_negativethrust4 = ctrl_TAPM_P.pwm_thr4_backward[0];
  for (res = 0; res < 5; res++) {
    rtb_negativethrust4 = rtb_negativethrust4 * rtb_eta_w_idx_2 +
      ctrl_TAPM_P.pwm_thr4_backward[res + 1];
  }

  /* End of Polyval: '<S49>/negative thrust 4' */

  /* MATLAB Function: '<S49>/MATLAB Function4' */
  ctrl_TAPM_MATLABFunction2_i(rtb_positivethrust4, ctrl_TAPM_B.output[6],
    rtb_negativethrust4, &ctrl_TAPM_B.sf_MATLABFunction4_b);

  /* Saturate: '<S49>/Saturation 5' */
  if (ctrl_TAPM_B.output[8] > ctrl_TAPM_P.Max_thrust) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[8] < ctrl_TAPM_P.Saturation5_LowerSat) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation5_LowerSat;
  } else {
    rtb_eta_w_idx_2 = ctrl_TAPM_B.output[8];
  }

  /* End of Saturate: '<S49>/Saturation 5' */

  /* Polyval: '<S49>/positive thrust 5' */
  rtb_positivethrust5 = ctrl_TAPM_P.pwm_thr5_forward[0];
  for (res = 0; res < 5; res++) {
    rtb_positivethrust5 = rtb_positivethrust5 * rtb_eta_w_idx_2 +
      ctrl_TAPM_P.pwm_thr5_forward[res + 1];
  }

  /* End of Polyval: '<S49>/positive thrust 5' */

  /* Saturate: '<S49>/Saturation 6' */
  if (ctrl_TAPM_B.output[8] > ctrl_TAPM_P.Saturation6_UpperSat) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation6_UpperSat;
  } else if (ctrl_TAPM_B.output[8] < ctrl_TAPM_P.Min_thrust) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Min_thrust;
  } else {
    rtb_eta_w_idx_2 = ctrl_TAPM_B.output[8];
  }

  /* End of Saturate: '<S49>/Saturation 6' */

  /* Polyval: '<S49>/negative thrust 5' */
  rtb_negativethrust5 = ctrl_TAPM_P.pwm_thr5_backward[0];
  for (res = 0; res < 5; res++) {
    rtb_negativethrust5 = rtb_negativethrust5 * rtb_eta_w_idx_2 +
      ctrl_TAPM_P.pwm_thr5_backward[res + 1];
  }

  /* End of Polyval: '<S49>/negative thrust 5' */

  /* MATLAB Function: '<S49>/MATLAB Function5' */
  ctrl_TAPM_MATLABFunction2_i(rtb_positivethrust5, ctrl_TAPM_B.output[8],
    rtb_negativethrust5, &ctrl_TAPM_B.sf_MATLABFunction5_h);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Saturate: '<S48>/Saturation 2' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[1] > ctrl_TAPM_P.Saturation2_UpperSat) {
      ctrl_TAPM_B.Saturation2 = ctrl_TAPM_P.Saturation2_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[1] <
               ctrl_TAPM_P.Saturation2_LowerSat) {
      ctrl_TAPM_B.Saturation2 = ctrl_TAPM_P.Saturation2_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation2 = rtb_ImpAsg_InsertedFor_Out2_at_[1];
    }

    /* End of Saturate: '<S48>/Saturation 2' */
  }

  /* Saturate: '<S49>/Saturation 12' */
  if (ctrl_TAPM_B.output[10] > ctrl_TAPM_P.Max_thrust) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[10] < ctrl_TAPM_P.Saturation12_LowerSat) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation12_LowerSat;
  } else {
    rtb_eta_w_idx_2 = ctrl_TAPM_B.output[10];
  }

  /* End of Saturate: '<S49>/Saturation 12' */

  /* Polyval: '<S49>/positive thrust 6' */
  rtb_positivethrust6 = ctrl_TAPM_P.pwm_thr6_forward[0];
  for (res = 0; res < 5; res++) {
    rtb_positivethrust6 = rtb_positivethrust6 * rtb_eta_w_idx_2 +
      ctrl_TAPM_P.pwm_thr6_forward[res + 1];
  }

  /* End of Polyval: '<S49>/positive thrust 6' */

  /* Saturate: '<S49>/Saturation 13' */
  if (ctrl_TAPM_B.output[10] > ctrl_TAPM_P.Saturation13_UpperSat) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation13_UpperSat;
  } else if (ctrl_TAPM_B.output[10] < ctrl_TAPM_P.Min_thrust) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Min_thrust;
  } else {
    rtb_eta_w_idx_2 = ctrl_TAPM_B.output[10];
  }

  /* End of Saturate: '<S49>/Saturation 13' */

  /* Polyval: '<S49>/negative thrust 6' */
  rtb_negativethrust6 = ctrl_TAPM_P.pwm_thr6_backward[0];
  for (res = 0; res < 5; res++) {
    rtb_negativethrust6 = rtb_negativethrust6 * rtb_eta_w_idx_2 +
      ctrl_TAPM_P.pwm_thr6_backward[res + 1];
  }

  /* End of Polyval: '<S49>/negative thrust 6' */

  /* MATLAB Function: '<S49>/MATLAB Function6' */
  ctrl_TAPM_MATLABFunction2_i(rtb_positivethrust6, ctrl_TAPM_B.output[10],
    rtb_negativethrust6, &ctrl_TAPM_B.sf_MATLABFunction6_k);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Saturate: '<S48>/Saturation 3' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[2] > ctrl_TAPM_P.Saturation3_UpperSat) {
      ctrl_TAPM_B.Saturation3 = ctrl_TAPM_P.Saturation3_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[2] <
               ctrl_TAPM_P.Saturation3_LowerSat_f) {
      ctrl_TAPM_B.Saturation3 = ctrl_TAPM_P.Saturation3_LowerSat_f;
    } else {
      ctrl_TAPM_B.Saturation3 = rtb_ImpAsg_InsertedFor_Out2_at_[2];
    }

    /* End of Saturate: '<S48>/Saturation 3' */

    /* Saturate: '<S48>/Saturation 4' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[3] > ctrl_TAPM_P.Saturation4_UpperSat_p)
    {
      ctrl_TAPM_B.Saturation4 = ctrl_TAPM_P.Saturation4_UpperSat_p;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[3] <
               ctrl_TAPM_P.Saturation4_LowerSat) {
      ctrl_TAPM_B.Saturation4 = ctrl_TAPM_P.Saturation4_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation4 = rtb_ImpAsg_InsertedFor_Out2_at_[3];
    }

    /* End of Saturate: '<S48>/Saturation 4' */

    /* Saturate: '<S48>/Saturation 5' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[4] > ctrl_TAPM_P.Saturation5_UpperSat) {
      ctrl_TAPM_B.Saturation5 = ctrl_TAPM_P.Saturation5_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[4] <
               ctrl_TAPM_P.Saturation5_LowerSat_h) {
      ctrl_TAPM_B.Saturation5 = ctrl_TAPM_P.Saturation5_LowerSat_h;
    } else {
      ctrl_TAPM_B.Saturation5 = rtb_ImpAsg_InsertedFor_Out2_at_[4];
    }

    /* End of Saturate: '<S48>/Saturation 5' */

    /* Saturate: '<S48>/Saturation 6' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[5] > ctrl_TAPM_P.Saturation6_UpperSat_g)
    {
      ctrl_TAPM_B.Saturation6 = ctrl_TAPM_P.Saturation6_UpperSat_g;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[5] <
               ctrl_TAPM_P.Saturation6_LowerSat) {
      ctrl_TAPM_B.Saturation6 = ctrl_TAPM_P.Saturation6_LowerSat;
    } else {
      ctrl_TAPM_B.Saturation6 = rtb_ImpAsg_InsertedFor_Out2_at_[5];
    }

    /* End of Saturate: '<S48>/Saturation 6' */
  }

  /* Saturate: '<S49>/Saturation 7' */
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

  /* End of Saturate: '<S49>/Saturation 7' */

  /* Saturate: '<S49>/Saturation 1' */
  if (ctrl_TAPM_B.output[0] > ctrl_TAPM_P.Max_thrust) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Max_thrust;
  } else if (ctrl_TAPM_B.output[0] < ctrl_TAPM_P.Saturation1_LowerSat_h) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation1_LowerSat_h;
  } else {
    rtb_eta_w_idx_2 = ctrl_TAPM_B.output[0];
  }

  /* End of Saturate: '<S49>/Saturation 1' */

  /* Polyval: '<S49>/positive thrust 1' */
  rtb_Ta = ctrl_TAPM_P.pwm_thr1_forward[0];
  for (res = 0; res < 5; res++) {
    rtb_Ta = rtb_Ta * rtb_eta_w_idx_2 + ctrl_TAPM_P.pwm_thr1_forward[res + 1];
  }

  /* End of Polyval: '<S49>/positive thrust 1' */

  /* Saturate: '<S49>/Saturation 2' */
  if (ctrl_TAPM_B.output[0] > ctrl_TAPM_P.Saturation2_UpperSat_p) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Saturation2_UpperSat_p;
  } else if (ctrl_TAPM_B.output[0] < ctrl_TAPM_P.Min_thrust) {
    rtb_eta_w_idx_2 = ctrl_TAPM_P.Min_thrust;
  } else {
    rtb_eta_w_idx_2 = ctrl_TAPM_B.output[0];
  }

  /* End of Saturate: '<S49>/Saturation 2' */

  /* Polyval: '<S49>/negative thrust 1' */
  offset = ctrl_TAPM_P.pwm_thr1_backward[0];
  for (res = 0; res < 5; res++) {
    offset = offset * rtb_eta_w_idx_2 + ctrl_TAPM_P.pwm_thr1_backward[res + 1];
  }

  /* End of Polyval: '<S49>/negative thrust 1' */

  /* MATLAB Function: '<S49>/MATLAB Function1' */
  /* MATLAB Function 'Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function1': '<S57>:1' */
  if (ctrl_TAPM_B.output[0] >= 0.0) {
    /* '<S57>:1:4' */
    /* '<S57>:1:5' */
    ctrl_TAPM_B.Tc_out = rtb_Ta;
  } else {
    /* signal < 0 */
    /* '<S57>:1:7' */
    ctrl_TAPM_B.Tc_out = offset;
  }

  /* End of MATLAB Function: '<S49>/MATLAB Function1' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S4>/Gain' */
    ctrl_TAPM_B.Gain[0] = ctrl_TAPM_P.Gain_Gain_f * ctrl_TAPM_B.Saturation1;
    ctrl_TAPM_B.Gain[1] = ctrl_TAPM_P.Gain_Gain_f * ctrl_TAPM_B.Saturation2;
    ctrl_TAPM_B.Gain[2] = ctrl_TAPM_P.Gain_Gain_f * ctrl_TAPM_B.Saturation3;
    ctrl_TAPM_B.Gain[3] = ctrl_TAPM_P.Gain_Gain_f * ctrl_TAPM_B.Saturation4;
    ctrl_TAPM_B.Gain[4] = ctrl_TAPM_P.Gain_Gain_f * ctrl_TAPM_B.Saturation5;
    ctrl_TAPM_B.Gain[5] = ctrl_TAPM_P.Gain_Gain_f * ctrl_TAPM_B.Saturation6;
  }

  /* MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' incorporates:
   *  Constant: '<Root>/X-position Thruster'
   *  Constant: '<Root>/Y-position Thruster'
   */
  /* MATLAB Function 'Finding commanded forces in: [Surge,Sway,Yaw]': '<S1>:1' */
  /* '<S1>:1:4' */
  /* '<S1>:1:5' */
  /* '<S1>:1:6' */
  /* '<S1>:1:10' */
  ctrl_TAPM_B.commanded_tau[0] = 0.0;
  ctrl_TAPM_B.commanded_tau[1] = 0.0;
  ctrl_TAPM_B.commanded_tau[2] = 0.0;
  rtb_eta_w_idx_2 = ctrl_TAPM_B.Gain[0];
  ctrl_TAPM_cosd(&rtb_eta_w_idx_2);
  rtb_Ta = ctrl_TAPM_B.Gain[1];
  ctrl_TAPM_cosd(&rtb_Ta);
  offset = ctrl_TAPM_B.Gain[2];
  ctrl_TAPM_cosd(&offset);
  rtb_Row1 = ctrl_TAPM_B.Gain[3];
  ctrl_TAPM_cosd(&rtb_Row1);
  rtb_Row3 = ctrl_TAPM_B.Gain[4];
  ctrl_TAPM_cosd(&rtb_Row3);
  g = ctrl_TAPM_B.Gain[5];
  ctrl_TAPM_cosd(&g);
  h = ctrl_TAPM_B.Gain[0];
  ctrl_TAPM_sind(&h);
  rtb_Out2_CoreSubsysCanOut = ctrl_TAPM_B.Gain[1];
  ctrl_TAPM_sind(&rtb_Out2_CoreSubsysCanOut);
  rtb_TmpSignalConversionAtSFu__1 = ctrl_TAPM_B.Gain[2];
  ctrl_TAPM_sind(&rtb_TmpSignalConversionAtSFu__1);
  Alpha1_idx_0 = ctrl_TAPM_B.Gain[3];
  ctrl_TAPM_sind(&Alpha1_idx_0);
  Alpha1_idx_3 = ctrl_TAPM_B.Gain[4];
  ctrl_TAPM_sind(&Alpha1_idx_3);
  Alpha1_idx_4 = ctrl_TAPM_B.Gain[5];
  ctrl_TAPM_sind(&Alpha1_idx_4);
  rtb_eta_w_idx_0 = ctrl_TAPM_B.Gain[0];
  ctrl_TAPM_sind(&rtb_eta_w_idx_0);
  rtb_TmpSignalConversionAtSFu__0 = ctrl_TAPM_B.Gain[0];
  ctrl_TAPM_cosd(&rtb_TmpSignalConversionAtSFu__0);
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
  pos[0] = rtb_eta_w_idx_2;
  pos[3] = rtb_Ta;
  pos[6] = offset;
  pos[9] = rtb_Row1;
  pos[12] = rtb_Row3;
  pos[15] = g;
  pos[1] = h;
  pos[4] = rtb_Out2_CoreSubsysCanOut;
  pos[7] = rtb_TmpSignalConversionAtSFu__1;
  pos[10] = Alpha1_idx_0;
  pos[13] = Alpha1_idx_3;
  pos[16] = Alpha1_idx_4;
  pos[2] = rtb_eta_w_idx_0 * ctrl_TAPM_P.XpositionThruster_Value_e[0] -
    rtb_TmpSignalConversionAtSFu__0 * ctrl_TAPM_P.YpositionThruster_Value_o[0];
  pos[5] = p * ctrl_TAPM_P.XpositionThruster_Value_e[1] - q *
    ctrl_TAPM_P.YpositionThruster_Value_o[1];
  pos[8] = r * ctrl_TAPM_P.XpositionThruster_Value_e[2] - s_0 *
    ctrl_TAPM_P.YpositionThruster_Value_o[2];
  pos[11] = t * ctrl_TAPM_P.XpositionThruster_Value_e[3] - u *
    ctrl_TAPM_P.YpositionThruster_Value_o[3];
  pos[14] = v * ctrl_TAPM_P.XpositionThruster_Value_e[4] - w *
    ctrl_TAPM_P.YpositionThruster_Value_o[4];
  pos[17] = x * ctrl_TAPM_P.XpositionThruster_Value_e[5] - y *
    ctrl_TAPM_P.YpositionThruster_Value_o[5];
  for (i_0 = 0; i_0 < 3; i_0++) {
    ctrl_TAPM_B.commanded_tau[i_0] = 0.0;
    for (i = 0; i < 6; i++) {
      ctrl_TAPM_B.commanded_tau[i_0] += pos[3 * i + i_0] *
        ctrl_TAPM_B.Saturation7[i];
    }
  }

  /* End of MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */

  /* Sum: '<S18>/Sum2' incorporates:
   *  Integrator: '<S18>/Integrator1'
   *  Sum: '<S18>/Sum4'
   */
  rtb_eta_w_idx_0 = ctrl_TAPM_B.x_m - (ctrl_TAPM_X.Integrator1_CSTATE[0] +
    ctrl_TAPM_B.eta[0]);
  rtb_TmpSignalConversionAtSFu__1 = ctrl_TAPM_B.y_m -
    (ctrl_TAPM_X.Integrator1_CSTATE[1] + ctrl_TAPM_B.eta[1]);
  rtb_eta_w_idx_2 = ctrl_TAPM_B.psi_m - (ctrl_TAPM_X.Integrator1_CSTATE[2] +
    ctrl_TAPM_B.eta[2]);

  /* Gain: '<S18>/K4' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_bias[i_0] = ctrl_TAPM_P.Nonlinearpassiveobserver_K4[i_0 + 6] *
      rtb_eta_w_idx_2 + (ctrl_TAPM_P.Nonlinearpassiveobserver_K4[i_0 + 3] *
                         rtb_TmpSignalConversionAtSFu__1 +
                         ctrl_TAPM_P.Nonlinearpassiveobserver_K4[i_0] *
                         rtb_eta_w_idx_0);
  }

  /* End of Gain: '<S18>/K4' */

  /* Sum: '<S18>/Sum1' incorporates:
   *  Fcn: '<S30>/Row1'
   *  Fcn: '<S30>/Row2'
   *  Fcn: '<S30>/Row3'
   *  Integrator: '<S18>/Integrator3'
   */
  tmp_1[0] = cos(ctrl_TAPM_B.psi_m) * ctrl_TAPM_X.Integrator3_CSTATE[0] + sin
    (ctrl_TAPM_B.psi_m) * ctrl_TAPM_X.Integrator3_CSTATE[1];
  tmp_1[1] = -sin(ctrl_TAPM_B.psi_m) * ctrl_TAPM_X.Integrator3_CSTATE[0] + cos
    (ctrl_TAPM_B.psi_m) * ctrl_TAPM_X.Integrator3_CSTATE[1];
  tmp_1[2] = ctrl_TAPM_X.Integrator3_CSTATE[2];

  /* Sum: '<S18>/Sum8' incorporates:
   *  Fcn: '<S29>/Row1'
   *  Fcn: '<S29>/Row2'
   *  Fcn: '<S29>/Row3'
   *  Gain: '<S18>/Gain3'
   *  Gain: '<S18>/Gain6'
   *  Sum: '<S18>/Sum1'
   */
  tmp_2[0] = cos(ctrl_TAPM_B.psi_m) * rtb_bias[0] + sin(ctrl_TAPM_B.psi_m) *
    rtb_bias[1];
  tmp_2[1] = -sin(ctrl_TAPM_B.psi_m) * rtb_bias[0] + cos(ctrl_TAPM_B.psi_m) *
    rtb_bias[1];
  tmp_2[2] = rtb_bias[2];
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_bias[i_0] = ((tmp_1[i_0] + ctrl_TAPM_B.commanded_tau[i_0]) + tmp_2[i_0])
      - ((ctrl_TAPM_P.Nonlinearpassiveobserver_D[i_0 + 3] * ctrl_TAPM_B.nu[1] +
          ctrl_TAPM_P.Nonlinearpassiveobserver_D[i_0] * ctrl_TAPM_B.nu[0]) +
         ctrl_TAPM_P.Nonlinearpassiveobserver_D[i_0 + 6] * ctrl_TAPM_B.nu[2]);
  }

  /* End of Sum: '<S18>/Sum8' */

  /* Gain: '<S18>/Gain3' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    ctrl_TAPM_B.Gain3[i_0] = 0.0;
    ctrl_TAPM_B.Gain3[i_0] += ctrl_TAPM_P.Gain3_Gain_b[i_0] * rtb_bias[0];
    ctrl_TAPM_B.Gain3[i_0] += ctrl_TAPM_P.Gain3_Gain_b[i_0 + 3] * rtb_bias[1];
    ctrl_TAPM_B.Gain3[i_0] += ctrl_TAPM_P.Gain3_Gain_b[i_0 + 6] * rtb_bias[2];
  }

  /* Sum: '<S18>/Sum3' incorporates:
   *  Fcn: '<S28>/Fcn'
   *  Fcn: '<S28>/Fcn1'
   *  Fcn: '<S28>/Fcn2'
   *  Gain: '<S18>/K2'
   */
  tmp_3[0] = cos(ctrl_TAPM_B.psi_m) * ctrl_TAPM_B.nu[0] - sin(ctrl_TAPM_B.psi_m)
    * ctrl_TAPM_B.nu[1];
  tmp_3[1] = sin(ctrl_TAPM_B.psi_m) * ctrl_TAPM_B.nu[0] + cos(ctrl_TAPM_B.psi_m)
    * ctrl_TAPM_B.nu[1];
  tmp_3[2] = ctrl_TAPM_B.nu[2];
  for (i_0 = 0; i_0 < 3; i_0++) {
    ctrl_TAPM_B.Sum3[i_0] = ((ctrl_TAPM_P.Nonlinearpassiveobserver_w_c[i_0 + 3] *
      rtb_TmpSignalConversionAtSFu__1 +
      ctrl_TAPM_P.Nonlinearpassiveobserver_w_c[i_0] * rtb_eta_w_idx_0) +
      ctrl_TAPM_P.Nonlinearpassiveobserver_w_c[i_0 + 6] * rtb_eta_w_idx_2) +
      tmp_3[i_0];
  }

  /* End of Sum: '<S18>/Sum3' */

  /* Sum: '<S18>/Sum5' incorporates:
   *  Gain: '<S18>/K11'
   *  Integrator: '<S18>/Integrator1'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    ctrl_TAPM_B.psi_WF[i_0] = ((ctrl_TAPM_P.K11_Gain[i_0 + 3] *
      rtb_TmpSignalConversionAtSFu__1 + ctrl_TAPM_P.K11_Gain[i_0] *
      rtb_eta_w_idx_0) + ctrl_TAPM_P.K11_Gain[i_0 + 6] * rtb_eta_w_idx_2) +
      ctrl_TAPM_X.Integrator1_CSTATE[i_0];
  }

  /* End of Sum: '<S18>/Sum5' */

  /* Gain: '<S18>/K12' incorporates:
   *  Sum: '<S18>/Sum6'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_bias[i_0] = ctrl_TAPM_P.K12_Gain[i_0 + 6] * rtb_eta_w_idx_2 +
      (ctrl_TAPM_P.K12_Gain[i_0 + 3] * rtb_TmpSignalConversionAtSFu__1 +
       ctrl_TAPM_P.K12_Gain[i_0] * rtb_eta_w_idx_0);
  }

  /* End of Gain: '<S18>/K12' */

  /* Gain: '<S18>/Gain2' incorporates:
   *  Integrator: '<S18>/Integrator2'
   *  Sum: '<S18>/Sum6'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_0[i_0] = ctrl_TAPM_P.Gain2_Gain_a[i_0 + 6] *
      ctrl_TAPM_X.Integrator2_CSTATE[2] + (ctrl_TAPM_P.Gain2_Gain_a[i_0 + 3] *
      ctrl_TAPM_X.Integrator2_CSTATE[1] + ctrl_TAPM_P.Gain2_Gain_a[i_0] *
      ctrl_TAPM_X.Integrator2_CSTATE[0]);
  }

  /* End of Gain: '<S18>/Gain2' */

  /* Sum: '<S18>/Sum6' incorporates:
   *  Gain: '<S18>/Gain1'
   *  Integrator: '<S18>/Integrator1'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    ctrl_TAPM_B.Sum6[i_0] = (rtb_bias[i_0] - tmp_0[i_0]) -
      ((ctrl_TAPM_P.Gain1_Gain_i[i_0 + 3] * ctrl_TAPM_X.Integrator1_CSTATE[1] +
        ctrl_TAPM_P.Gain1_Gain_i[i_0] * ctrl_TAPM_X.Integrator1_CSTATE[0]) +
       ctrl_TAPM_P.Gain1_Gain_i[i_0 + 6] * ctrl_TAPM_X.Integrator1_CSTATE[2]);
  }

  /* Gain: '<S18>/inv(T_b)' incorporates:
   *  Integrator: '<S18>/Integrator3'
   *  Sum: '<S18>/Sum7'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    rtb_bias[i_0] = ctrl_TAPM_P.invT_b_Gain[i_0 + 6] *
      ctrl_TAPM_X.Integrator3_CSTATE[2] + (ctrl_TAPM_P.invT_b_Gain[i_0 + 3] *
      ctrl_TAPM_X.Integrator3_CSTATE[1] + ctrl_TAPM_P.invT_b_Gain[i_0] *
      ctrl_TAPM_X.Integrator3_CSTATE[0]);
  }

  /* End of Gain: '<S18>/inv(T_b)' */

  /* Sum: '<S18>/Sum7' incorporates:
   *  Gain: '<S18>/K3'
   */
  for (i_0 = 0; i_0 < 3; i_0++) {
    ctrl_TAPM_B.Sum7[i_0] = ((ctrl_TAPM_P.Nonlinearpassiveobserver_K3[i_0 + 3] *
      rtb_TmpSignalConversionAtSFu__1 +
      ctrl_TAPM_P.Nonlinearpassiveobserver_K3[i_0] * rtb_eta_w_idx_0) +
      ctrl_TAPM_P.Nonlinearpassiveobserver_K3[i_0 + 6] * rtb_eta_w_idx_2) -
      rtb_bias[i_0];
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
  }

  /* Integrator: '<S19>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_ax,
                       ctrl_TAPM_B.reset_n0);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_d = ctrl_TAPM_P.Integrator_IC_d;
    }
  }

  ctrl_TAPM_B.Integrator = ctrl_TAPM_X.Integrator_CSTATE_d;

  /* Sum: '<S20>/Sum' incorporates:
   *  Constant: '<S20>/Constant1'
   *  Gain: '<S2>/deg2rad'
   */
  ctrl_TAPM_B.Sum = ctrl_TAPM_P.deg2rad_Gain * ctrl_TAPM_B.wave_dir +
    ctrl_TAPM_P.Constant1_Value;

  /* Sum: '<S20>/Sum1' incorporates:
   *  Gain: '<S20>/Gain'
   *  Gain: '<S20>/Gain1'
   */
  ctrl_TAPM_B.Sum1[0] = (ctrl_TAPM_P.Gain1_Gain_ib[0] * ctrl_TAPM_B.eta[0] +
    ctrl_TAPM_P.Gain1_Gain_ib[2] * ctrl_TAPM_B.eta[1]) -
    (ctrl_TAPM_P.Gain_Gain_dl[0] * rtb_Integrator_idx_0 +
     ctrl_TAPM_P.Gain_Gain_dl[2] * rtb_Integrator_idx_1);
  ctrl_TAPM_B.Sum1[1] = (ctrl_TAPM_P.Gain1_Gain_ib[1] * ctrl_TAPM_B.eta[0] +
    ctrl_TAPM_P.Gain1_Gain_ib[3] * ctrl_TAPM_B.eta[1]) -
    (ctrl_TAPM_P.Gain_Gain_dl[1] * rtb_Integrator_idx_0 +
     ctrl_TAPM_P.Gain_Gain_dl[3] * rtb_Integrator_idx_1);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Delay: '<S8>/Delay' */
    for (i = 0; i < 6; i++) {
      ctrl_TAPM_B.Delay_n[i] = ctrl_TAPM_DW.Delay_DSTATE_i[i];
    }

    /* End of Delay: '<S8>/Delay' */

    /* Delay: '<S50>/Delay' */
    ctrl_TAPM_B.Delay_e = ctrl_TAPM_DW.Delay_DSTATE_f;

    /* Delay: '<S65>/Delay' */
    ctrl_TAPM_B.Delay_a = ctrl_TAPM_DW.Delay_DSTATE_fu;
  }

  /* MATLAB Function: '<S65>/MATLAB Function' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Tf1'
   *  Constant: '<S7>/K_Tr1'
   *  Constant: '<S7>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/MATLAB Function': '<S69>:1' */
  /* '<S69>:1:5' */
  if (rtb_sys[6] < 0.0) {
    rtb_eta_w_idx_0 = -1.0;
  } else if (rtb_sys[6] > 0.0) {
    rtb_eta_w_idx_0 = 1.0;
  } else if (rtb_sys[6] == 0.0) {
    rtb_eta_w_idx_0 = 0.0;
  } else {
    rtb_eta_w_idx_0 = rtb_sys[6];
  }

  rtb_eta_w_idx_2 = sqrt(fabs(rtb_sys[6]) / (ctrl_TAPM_P.Rho * rt_powd_snf
    (ctrl_TAPM_P.D, 4.0) * ctrl_TAPM_P.K_T1f)) * rtb_eta_w_idx_0;

  /* '<S69>:1:7' */
  offset = tanh(ctrl_TAPM_P.eps_c * rtb_eta_w_idx_2 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S69>:1:8' */
  /* '<S69>:1:10' */
  if (ctrl_TAPM_B.Delay_a < 0.0) {
    rtb_eta_w_idx_0 = -1.0;
  } else if (ctrl_TAPM_B.Delay_a > 0.0) {
    rtb_eta_w_idx_0 = 1.0;
  } else if (ctrl_TAPM_B.Delay_a == 0.0) {
    rtb_eta_w_idx_0 = 0.0;
  } else {
    rtb_eta_w_idx_0 = ctrl_TAPM_B.Delay_a;
  }

  rtb_T_r_c = ((1.0 - offset) * ctrl_TAPM_P.K_T1r + ctrl_TAPM_P.K_T1f * offset) *
    rtb_eta_w_idx_0 * ctrl_TAPM_P.Rho * rt_powd_snf(ctrl_TAPM_P.D, 4.0) *
    (ctrl_TAPM_B.Delay_a * ctrl_TAPM_B.Delay_a);
  ctrl_TAPM_B.n_d_b = rtb_eta_w_idx_2;

  /* End of MATLAB Function: '<S65>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S65>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S65>/Constant1'
     *  Constant: '<S65>/Constant2'
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

    /* SampleTimeMath: '<S68>/TSamp'
     *
     * About '<S68>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp = ctrl_TAPM_B.DiscreteTransferFcn * ctrl_TAPM_P.TSamp_WtEt;

    /* Sum: '<S68>/Diff' incorporates:
     *  UnitDelay: '<S68>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp - ctrl_TAPM_DW.UD_DSTATE;

    /* RateLimiter: '<S65>/Acceleration Limit' */
    rtb_eta_w_idx_2 = rtb_Sum_b - ctrl_TAPM_DW.PrevY;
    if (rtb_eta_w_idx_2 > ctrl_TAPM_P.AccelerationLimit_RisingLim) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY + ctrl_TAPM_P.AccelerationLimit_RisingLim;
    } else {
      if (rtb_eta_w_idx_2 < ctrl_TAPM_P.AccelerationLimit_FallingLim) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY +
          ctrl_TAPM_P.AccelerationLimit_FallingLim;
      }
    }

    ctrl_TAPM_DW.PrevY = rtb_Sum_b;

    /* End of RateLimiter: '<S65>/Acceleration Limit' */

    /* Gain: '<S65>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation = ctrl_TAPM_P.I_s * 2.0 * 3.1415926535897931
      * rtb_Sum_b;

    /* Sum: '<S65>/Sum1' incorporates:
     *  Gain: '<S65>/Qf_0'
     *  Gain: '<S65>/Qff_0(nr)'
     *  Gain: '<S65>/Qff_1(nr)'
     *  Trigonometry: '<S65>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_n = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn) * ctrl_TAPM_P.Q_f0 + ctrl_TAPM_P.K_omega *
      2.0 * 3.1415926535897931 * ctrl_TAPM_B.DiscreteTransferFcn;

    /* Memory: '<S65>/Memory' */
    ctrl_TAPM_B.Memory = ctrl_TAPM_DW.Memory_PreviousInput;

    /* Sum: '<S67>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn - ctrl_TAPM_B.Delay_n[0];

    /* Gain: '<S67>/Kp' */
    ctrl_TAPM_B.Kp = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S67>/Integrator' */
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

  rtb_Integrator_gu = ctrl_TAPM_X.Integrator_CSTATE_e;

  /* MATLAB Function: '<S67>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Qr1'
   *  Constant: '<S7>/K_Qr7'
   *  Constant: '<S7>/K_Tf1'
   *  Constant: '<S7>/K_Tr1'
   *  Constant: '<S7>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay_n[0], ctrl_TAPM_P.K_T1f,
    ctrl_TAPM_P.K_q1f, ctrl_TAPM_P.D, rtb_T_r_c, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.eps_c, ctrl_TAPM_P.K_T1r, ctrl_TAPM_P.K_q1r,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePowerand);

  /* MultiPortSwitch: '<S65>/Controller chosen' incorporates:
   *  Constant: '<S65>/NaN'
   *  Sum: '<S67>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory) {
   case 1:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.Kp + rtb_Integrator_gu;
    break;

   case 2:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowerand.Qcq;
    break;

   case 3:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowerand.Qcp;
    break;

   case 4:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowerand.Qcc;
    break;

   default:
    rtb_eta_w_idx_2 = ctrl_TAPM_P.NaN_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S65>/Controller chosen' */

  /* Sum: '<S65>/Sum' */
  ctrl_TAPM_B.Sum_k = (ctrl_TAPM_B.Inertiacompensation + ctrl_TAPM_B.Sum1_n) +
    rtb_eta_w_idx_2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S50>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S50>/Constant'
     *  Constant: '<S50>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a = ctrl_TAPM_B.Sum_k -
      ctrl_TAPM_P.Constant_Value_cs[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_d;
    ctrl_TAPM_B.DiscreteTransferFcn_d = ctrl_TAPM_P.Constant1_Value_k[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a + ctrl_TAPM_P.Constant1_Value_k[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_d;
  }

  /* Gain: '<S64>/Finding rotation speed' incorporates:
   *  Gain: '<S64>/K_omega'
   *  Sum: '<S64>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed = ((ctrl_TAPM_B.DiscreteTransferFcn_d -
    ctrl_TAPM_B.Delay_e) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_p) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S67>/Ki' */
    ctrl_TAPM_B.Ki = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;
  }

  /* MATLAB Function: '<S65>/Supervisor' */
  ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory, ctrl_TAPM_B.Core_controller,
                       ctrl_TAPM_B.Delay_n[0], &ctrl_TAPM_B.sf_Supervisor);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Delay: '<S51>/Delay' */
    ctrl_TAPM_B.Delay_b = ctrl_TAPM_DW.Delay_DSTATE_b;

    /* Delay: '<S74>/Delay' */
    ctrl_TAPM_B.Delay_bs = ctrl_TAPM_DW.Delay_DSTATE_d;
  }

  /* MATLAB Function: '<S74>/MATLAB Function' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Tf2'
   *  Constant: '<S7>/K_Tr2'
   *  Constant: '<S7>/Rho'
   */
  ctrl_TAPM_MATLABFunction_i(rtb_sys[7], ctrl_TAPM_P.K_T2f, ctrl_TAPM_P.K_T2r,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_B.Delay_bs,
    &ctrl_TAPM_B.sf_MATLABFunction_i);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S74>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S74>/Constant1'
     *  Constant: '<S74>/Constant2'
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

    /* SampleTimeMath: '<S77>/TSamp'
     *
     * About '<S77>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_n = ctrl_TAPM_B.DiscreteTransferFcn_e *
      ctrl_TAPM_P.TSamp_WtEt_k;

    /* Sum: '<S77>/Diff' incorporates:
     *  UnitDelay: '<S77>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_n - ctrl_TAPM_DW.UD_DSTATE_n;

    /* RateLimiter: '<S74>/Acceleration Limit' */
    rtb_eta_w_idx_2 = rtb_Sum_b - ctrl_TAPM_DW.PrevY_e;
    if (rtb_eta_w_idx_2 > ctrl_TAPM_P.AccelerationLimit_RisingLim_n) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_e +
        ctrl_TAPM_P.AccelerationLimit_RisingLim_n;
    } else {
      if (rtb_eta_w_idx_2 < ctrl_TAPM_P.AccelerationLimit_FallingLim_n) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_e +
          ctrl_TAPM_P.AccelerationLimit_FallingLim_n;
      }
    }

    ctrl_TAPM_DW.PrevY_e = rtb_Sum_b;

    /* End of RateLimiter: '<S74>/Acceleration Limit' */

    /* Gain: '<S74>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_e = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S74>/Sum1' incorporates:
     *  Gain: '<S74>/Qf_0'
     *  Gain: '<S74>/Qff_0(nr)'
     *  Gain: '<S74>/Qff_1(nr)'
     *  Trigonometry: '<S74>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_nn = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_e) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_e;

    /* Memory: '<S74>/Memory' */
    ctrl_TAPM_B.Memory_c = ctrl_TAPM_DW.Memory_PreviousInput_n;

    /* Sum: '<S76>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_e - ctrl_TAPM_B.Delay_n[1];

    /* Gain: '<S76>/Kp' */
    ctrl_TAPM_B.Kp_p = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S76>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_db,
                       ctrl_TAPM_B.reset_e);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM_X.Integrator_CSTATE_gg = ctrl_TAPM_P.Integrator_IC_fy;
    }
  }

  rtb_Integrator_f = ctrl_TAPM_X.Integrator_CSTATE_gg;

  /* MATLAB Function: '<S76>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Qr2'
   *  Constant: '<S7>/K_Qr8'
   *  Constant: '<S7>/K_Tf2'
   *  Constant: '<S7>/K_Tr2'
   *  Constant: '<S7>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay_n[1], ctrl_TAPM_P.K_T2f,
    ctrl_TAPM_P.K_q2f, ctrl_TAPM_P.D, ctrl_TAPM_B.sf_MATLABFunction_i.T_r,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.K_T2r, ctrl_TAPM_P.K_q2r,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePowera_o);

  /* MultiPortSwitch: '<S74>/Controller chosen' incorporates:
   *  Constant: '<S74>/NaN'
   *  Sum: '<S76>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_c) {
   case 1:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.Kp_p + rtb_Integrator_f;
    break;

   case 2:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_o.Qcq;
    break;

   case 3:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_o.Qcp;
    break;

   case 4:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_o.Qcc;
    break;

   default:
    rtb_eta_w_idx_2 = ctrl_TAPM_P.NaN_Value_l;
    break;
  }

  /* End of MultiPortSwitch: '<S74>/Controller chosen' */

  /* Sum: '<S74>/Sum' */
  ctrl_TAPM_B.Sum_h = (ctrl_TAPM_B.Inertiacompensation_e + ctrl_TAPM_B.Sum1_nn)
    + rtb_eta_w_idx_2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S51>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S51>/Constant'
     *  Constant: '<S51>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h = ctrl_TAPM_B.Sum_h -
      ctrl_TAPM_P.Constant_Value_h[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_m;
    ctrl_TAPM_B.DiscreteTransferFcn_k = ctrl_TAPM_P.Constant1_Value_j[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h + ctrl_TAPM_P.Constant1_Value_j[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_m;
  }

  /* Gain: '<S73>/Finding rotation speed' incorporates:
   *  Gain: '<S73>/K_omega'
   *  Sum: '<S73>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_a = ((ctrl_TAPM_B.DiscreteTransferFcn_k -
    ctrl_TAPM_B.Delay_b) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_h) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S76>/Ki' */
    ctrl_TAPM_B.Ki_o = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;
  }

  /* MATLAB Function: '<S74>/Supervisor' */
  ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_c, ctrl_TAPM_B.Core_controller,
                       ctrl_TAPM_B.Delay_n[1], &ctrl_TAPM_B.sf_Supervisor_h);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Delay: '<S52>/Delay' */
    ctrl_TAPM_B.Delay_i = ctrl_TAPM_DW.Delay_DSTATE_n;

    /* Delay: '<S83>/Delay' */
    ctrl_TAPM_B.Delay_by = ctrl_TAPM_DW.Delay_DSTATE_no;
  }

  /* MATLAB Function: '<S83>/MATLAB Function' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Tf3'
   *  Constant: '<S7>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 3/Thruster control/MATLAB Function': '<S87>:1' */
  /* '<S87>:1:5' */
  if (rtb_sys[8] < 0.0) {
    rtb_eta_w_idx_0 = -1.0;
  } else if (rtb_sys[8] > 0.0) {
    rtb_eta_w_idx_0 = 1.0;
  } else if (rtb_sys[8] == 0.0) {
    rtb_eta_w_idx_0 = 0.0;
  } else {
    rtb_eta_w_idx_0 = rtb_sys[8];
  }

  rtb_eta_w_idx_2 = sqrt(fabs(rtb_sys[8]) / (ctrl_TAPM_P.Rho * rt_powd_snf
    (ctrl_TAPM_P.D, 4.0) * ctrl_TAPM_P.K_T3f)) * rtb_eta_w_idx_0;

  /* '<S87>:1:7' */
  offset = tanh(ctrl_TAPM_P.eps_c * rtb_eta_w_idx_2 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S87>:1:8' */
  /* '<S87>:1:10' */
  if (ctrl_TAPM_B.Delay_by < 0.0) {
    rtb_eta_w_idx_0 = -1.0;
  } else if (ctrl_TAPM_B.Delay_by > 0.0) {
    rtb_eta_w_idx_0 = 1.0;
  } else if (ctrl_TAPM_B.Delay_by == 0.0) {
    rtb_eta_w_idx_0 = 0.0;
  } else {
    rtb_eta_w_idx_0 = ctrl_TAPM_B.Delay_by;
  }

  rtb_T_r_b = ((1.0 - offset) * ctrl_TAPM_P.K_T3f + ctrl_TAPM_P.K_T3f * offset) *
    rtb_eta_w_idx_0 * ctrl_TAPM_P.Rho * rt_powd_snf(ctrl_TAPM_P.D, 4.0) *
    (ctrl_TAPM_B.Delay_by * ctrl_TAPM_B.Delay_by);
  ctrl_TAPM_B.n_d_j = rtb_eta_w_idx_2;

  /* End of MATLAB Function: '<S83>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S83>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S83>/Constant1'
     *  Constant: '<S83>/Constant2'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_e = (ctrl_TAPM_B.n_d_j -
      ctrl_TAPM_P.Constant2_Value_h[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0]) -
      ctrl_TAPM_P.Constant2_Value_h[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[1];
    ctrl_TAPM_B.DiscreteTransferFcn_f = (ctrl_TAPM_P.Constant1_Value_g[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_e + ctrl_TAPM_P.Constant1_Value_g[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0]) +
      ctrl_TAPM_P.Constant1_Value_g[2] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[1];

    /* SampleTimeMath: '<S86>/TSamp'
     *
     * About '<S86>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_k = ctrl_TAPM_B.DiscreteTransferFcn_f *
      ctrl_TAPM_P.TSamp_WtEt_m;

    /* Sum: '<S86>/Diff' incorporates:
     *  UnitDelay: '<S86>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_k - ctrl_TAPM_DW.UD_DSTATE_i;

    /* RateLimiter: '<S83>/Acceleration limiter' */
    rtb_eta_w_idx_2 = rtb_Sum_b - ctrl_TAPM_DW.PrevY_o;
    if (rtb_eta_w_idx_2 > ctrl_TAPM_P.Accelerationlimiter_RisingLim) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_o +
        ctrl_TAPM_P.Accelerationlimiter_RisingLim;
    } else {
      if (rtb_eta_w_idx_2 < ctrl_TAPM_P.Accelerationlimiter_FallingLim) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_o +
          ctrl_TAPM_P.Accelerationlimiter_FallingLim;
      }
    }

    ctrl_TAPM_DW.PrevY_o = rtb_Sum_b;

    /* End of RateLimiter: '<S83>/Acceleration limiter' */

    /* Gain: '<S83>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_c = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S83>/Sum1' incorporates:
     *  Gain: '<S83>/Qf_0'
     *  Gain: '<S83>/Qff_0(nr)'
     *  Gain: '<S83>/Qff_1(nr)'
     *  Trigonometry: '<S83>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_i = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_f) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_f;

    /* Memory: '<S83>/Memory' */
    ctrl_TAPM_B.Memory_i = ctrl_TAPM_DW.Memory_PreviousInput_d;

    /* Sum: '<S85>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_f - ctrl_TAPM_B.Delay_n[2];

    /* Gain: '<S85>/Kp' */
    ctrl_TAPM_B.Kp_i = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S85>/Integrator' */
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

  /* MATLAB Function: '<S85>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Qr3'
   *  Constant: '<S7>/K_Qr9'
   *  Constant: '<S7>/K_Tf3'
   *  Constant: '<S7>/K_Tr3'
   *  Constant: '<S7>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay_n[2], ctrl_TAPM_P.K_T3f,
    ctrl_TAPM_P.K_q3f, ctrl_TAPM_P.D, rtb_T_r_b, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.eps_c, ctrl_TAPM_P.K_T3r, ctrl_TAPM_P.K_q3r,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePowera_n);

  /* MultiPortSwitch: '<S83>/Controller chosen' incorporates:
   *  Constant: '<S83>/NaN'
   *  Sum: '<S85>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_i) {
   case 1:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.Kp_i + rtb_Integrator_hl;
    break;

   case 2:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_n.Qcq;
    break;

   case 3:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_n.Qcp;
    break;

   case 4:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_n.Qcc;
    break;

   default:
    rtb_eta_w_idx_2 = ctrl_TAPM_P.NaN_Value_g;
    break;
  }

  /* End of MultiPortSwitch: '<S83>/Controller chosen' */

  /* Sum: '<S83>/Sum' */
  ctrl_TAPM_B.Sum_hf = (ctrl_TAPM_B.Inertiacompensation_c + ctrl_TAPM_B.Sum1_i)
    + rtb_eta_w_idx_2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S52>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S52>/Constant'
     *  Constant: '<S52>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_hh = ctrl_TAPM_B.Sum_hf -
      ctrl_TAPM_P.Constant_Value_n[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_k;
    ctrl_TAPM_B.DiscreteTransferFcn_n = ctrl_TAPM_P.Constant1_Value_a[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_hh + ctrl_TAPM_P.Constant1_Value_a[1]
      * ctrl_TAPM_DW.DiscreteTransferFcn_states_k;
  }

  /* Gain: '<S82>/Finding rotation speed' incorporates:
   *  Gain: '<S82>/K_omega'
   *  Sum: '<S82>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_m = ((ctrl_TAPM_B.DiscreteTransferFcn_n -
    ctrl_TAPM_B.Delay_i) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_a) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S85>/Ki' */
    ctrl_TAPM_B.Ki_n = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;
  }

  /* MATLAB Function: '<S83>/Supervisor' */
  ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_i, ctrl_TAPM_B.Core_controller,
                       ctrl_TAPM_B.Delay_n[2], &ctrl_TAPM_B.sf_Supervisor_l);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Delay: '<S53>/Delay' */
    ctrl_TAPM_B.Delay_g = ctrl_TAPM_DW.Delay_DSTATE_e;

    /* Delay: '<S92>/Delay' */
    ctrl_TAPM_B.Delay_l = ctrl_TAPM_DW.Delay_DSTATE_id;
  }

  /* MATLAB Function: '<S92>/MATLAB Function' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Tf4'
   *  Constant: '<S7>/K_Tr4'
   *  Constant: '<S7>/Rho'
   */
  ctrl_TAPM_MATLABFunction_i(rtb_sys[9], ctrl_TAPM_P.K_T4f, ctrl_TAPM_P.K_T4r,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_B.Delay_l,
    &ctrl_TAPM_B.sf_MATLABFunction_go);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S92>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S92>/Constant1'
     *  Constant: '<S92>/Constant2'
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

    /* SampleTimeMath: '<S95>/TSamp'
     *
     * About '<S95>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_a = ctrl_TAPM_B.DiscreteTransferFcn_l *
      ctrl_TAPM_P.TSamp_WtEt_h;

    /* Sum: '<S95>/Diff' incorporates:
     *  UnitDelay: '<S95>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_a - ctrl_TAPM_DW.UD_DSTATE_n4;

    /* RateLimiter: '<S92>/Acceleration limiter' */
    rtb_eta_w_idx_2 = rtb_Sum_b - ctrl_TAPM_DW.PrevY_c;
    if (rtb_eta_w_idx_2 > ctrl_TAPM_P.Accelerationlimiter_RisingLim_e) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_c +
        ctrl_TAPM_P.Accelerationlimiter_RisingLim_e;
    } else {
      if (rtb_eta_w_idx_2 < ctrl_TAPM_P.Accelerationlimiter_FallingLi_b) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_c +
          ctrl_TAPM_P.Accelerationlimiter_FallingLi_b;
      }
    }

    ctrl_TAPM_DW.PrevY_c = rtb_Sum_b;

    /* End of RateLimiter: '<S92>/Acceleration limiter' */

    /* Gain: '<S92>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_k = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S92>/Sum1' incorporates:
     *  Gain: '<S92>/Qf_0'
     *  Gain: '<S92>/Qff_0(nr)'
     *  Gain: '<S92>/Qff_1(nr)'
     *  Trigonometry: '<S92>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_b = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_l) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_l;

    /* Memory: '<S92>/Memory' */
    ctrl_TAPM_B.Memory_j = ctrl_TAPM_DW.Memory_PreviousInput_a;

    /* Sum: '<S94>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_l - ctrl_TAPM_B.Delay_n[3];

    /* Gain: '<S94>/Kp' */
    ctrl_TAPM_B.Kp_c = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S94>/Integrator' */
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

  rtb_Integrator_an = ctrl_TAPM_X.Integrator_CSTATE_le;

  /* MATLAB Function: '<S94>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Qr10'
   *  Constant: '<S7>/K_Qr4'
   *  Constant: '<S7>/K_Tf4'
   *  Constant: '<S7>/K_Tr4'
   *  Constant: '<S7>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay_n[3], ctrl_TAPM_P.K_T4f,
    ctrl_TAPM_P.K_q4f, ctrl_TAPM_P.D, ctrl_TAPM_B.sf_MATLABFunction_go.T_r,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.K_T4r, ctrl_TAPM_P.K_q4r,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePower_n3);

  /* MultiPortSwitch: '<S92>/Controller chosen' incorporates:
   *  Constant: '<S92>/NaN'
   *  Sum: '<S94>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_j) {
   case 1:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.Kp_c + rtb_Integrator_an;
    break;

   case 2:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePower_n3.Qcq;
    break;

   case 3:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePower_n3.Qcp;
    break;

   case 4:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePower_n3.Qcc;
    break;

   default:
    rtb_eta_w_idx_2 = ctrl_TAPM_P.NaN_Value_p;
    break;
  }

  /* End of MultiPortSwitch: '<S92>/Controller chosen' */

  /* Sum: '<S92>/Sum' */
  ctrl_TAPM_B.Sum_k2 = (ctrl_TAPM_B.Inertiacompensation_k + ctrl_TAPM_B.Sum1_b)
    + rtb_eta_w_idx_2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S53>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S53>/Constant'
     *  Constant: '<S53>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_n = ctrl_TAPM_B.Sum_k2 -
      ctrl_TAPM_P.Constant_Value_j[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_h0;
    ctrl_TAPM_B.DiscreteTransferFcn_b = ctrl_TAPM_P.Constant1_Value_oi[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_n + ctrl_TAPM_P.Constant1_Value_oi[1]
      * ctrl_TAPM_DW.DiscreteTransferFcn_states_h0;
  }

  /* Gain: '<S91>/Finding rotation speed' incorporates:
   *  Gain: '<S91>/K_omega'
   *  Sum: '<S91>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_ms = ((ctrl_TAPM_B.DiscreteTransferFcn_b -
    ctrl_TAPM_B.Delay_g) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_k) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S94>/Ki' */
    ctrl_TAPM_B.Ki_b = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;
  }

  /* MATLAB Function: '<S92>/Supervisor' */
  ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_j, ctrl_TAPM_B.Core_controller,
                       ctrl_TAPM_B.Delay_n[3], &ctrl_TAPM_B.sf_Supervisor_n);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Delay: '<S54>/Delay' */
    ctrl_TAPM_B.Delay_a5 = ctrl_TAPM_DW.Delay_DSTATE_j;

    /* Delay: '<S101>/Delay' */
    ctrl_TAPM_B.Delay_id = ctrl_TAPM_DW.Delay_DSTATE_a;
  }

  /* MATLAB Function: '<S101>/MATLAB Function' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Tf5'
   *  Constant: '<S7>/K_Tr5'
   *  Constant: '<S7>/Rho'
   */
  ctrl_TAPM_MATLABFunction_i(rtb_sys[10], ctrl_TAPM_P.K_T5f, ctrl_TAPM_P.K_T5r,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.D, ctrl_TAPM_P.eps_c, ctrl_TAPM_B.Delay_id,
    &ctrl_TAPM_B.sf_MATLABFunction_j);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S101>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S101>/Constant1'
     *  Constant: '<S101>/Constant2'
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

    /* SampleTimeMath: '<S104>/TSamp'
     *
     * About '<S104>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_m = ctrl_TAPM_B.DiscreteTransferFcn_o *
      ctrl_TAPM_P.TSamp_WtEt_o;

    /* Sum: '<S104>/Diff' incorporates:
     *  UnitDelay: '<S104>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_m - ctrl_TAPM_DW.UD_DSTATE_m;

    /* RateLimiter: '<S101>/Acceleration limiter' */
    rtb_eta_w_idx_2 = rtb_Sum_b - ctrl_TAPM_DW.PrevY_j;
    if (rtb_eta_w_idx_2 > ctrl_TAPM_P.Accelerationlimiter_RisingLim_b) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_j +
        ctrl_TAPM_P.Accelerationlimiter_RisingLim_b;
    } else {
      if (rtb_eta_w_idx_2 < ctrl_TAPM_P.Accelerationlimiter_FallingLi_d) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_j +
          ctrl_TAPM_P.Accelerationlimiter_FallingLi_d;
      }
    }

    ctrl_TAPM_DW.PrevY_j = rtb_Sum_b;

    /* End of RateLimiter: '<S101>/Acceleration limiter' */

    /* Gain: '<S101>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_f = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S101>/Sum1' incorporates:
     *  Gain: '<S101>/Qf_0'
     *  Gain: '<S101>/Qff_0(nr)'
     *  Gain: '<S101>/Qff_1(nr)'
     *  Trigonometry: '<S101>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_o = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_o) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_o;

    /* Memory: '<S101>/Memory' */
    ctrl_TAPM_B.Memory_d = ctrl_TAPM_DW.Memory_PreviousInput_b;

    /* Sum: '<S103>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_o - ctrl_TAPM_B.Delay_n[4];

    /* Gain: '<S103>/Kp' */
    ctrl_TAPM_B.Kp_j = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S103>/Integrator' */
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

  /* MATLAB Function: '<S103>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Qr11'
   *  Constant: '<S7>/K_Qr5'
   *  Constant: '<S7>/K_Tf5'
   *  Constant: '<S7>/K_Tr5'
   *  Constant: '<S7>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay_n[4], ctrl_TAPM_P.K_T5f,
    ctrl_TAPM_P.K_q5f, ctrl_TAPM_P.D, ctrl_TAPM_B.sf_MATLABFunction_j.T_r,
    ctrl_TAPM_P.Rho, ctrl_TAPM_P.eps_c, ctrl_TAPM_P.K_T5r, ctrl_TAPM_P.K_q5r,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePowera_h);

  /* MultiPortSwitch: '<S101>/Controller chosen' incorporates:
   *  Constant: '<S101>/NaN'
   *  Sum: '<S103>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_d) {
   case 1:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.Kp_j + rtb_Integrator_i;
    break;

   case 2:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_h.Qcq;
    break;

   case 3:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_h.Qcp;
    break;

   case 4:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePowera_h.Qcc;
    break;

   default:
    rtb_eta_w_idx_2 = ctrl_TAPM_P.NaN_Value_lq;
    break;
  }

  /* End of MultiPortSwitch: '<S101>/Controller chosen' */

  /* Sum: '<S101>/Sum' */
  ctrl_TAPM_B.Sum_i = (ctrl_TAPM_B.Inertiacompensation_f + ctrl_TAPM_B.Sum1_o) +
    rtb_eta_w_idx_2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S54>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S54>/Constant'
     *  Constant: '<S54>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_f = ctrl_TAPM_B.Sum_i -
      ctrl_TAPM_P.Constant_Value_i[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_dt;
    ctrl_TAPM_B.DiscreteTransferFcn_lz = ctrl_TAPM_P.Constant1_Value_h[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_f + ctrl_TAPM_P.Constant1_Value_h[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_dt;
  }

  /* Gain: '<S100>/Finding rotation speed' incorporates:
   *  Gain: '<S100>/K_omega'
   *  Sum: '<S100>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_ag = ((ctrl_TAPM_B.DiscreteTransferFcn_lz -
    ctrl_TAPM_B.Delay_a5) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_c) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S103>/Ki' */
    ctrl_TAPM_B.Ki_a = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;
  }

  /* MATLAB Function: '<S101>/Supervisor' */
  ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_d, ctrl_TAPM_B.Core_controller,
                       ctrl_TAPM_B.Delay_n[4], &ctrl_TAPM_B.sf_Supervisor_b);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Delay: '<S55>/Delay' */
    ctrl_TAPM_B.Delay_h = ctrl_TAPM_DW.Delay_DSTATE_dv;

    /* Delay: '<S110>/Delay' */
    ctrl_TAPM_B.Delay_il = ctrl_TAPM_DW.Delay_DSTATE_m;
  }

  /* MATLAB Function: '<S110>/MATLAB Function' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Tf6'
   *  Constant: '<S7>/K_Tr6'
   *  Constant: '<S7>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 6/Thruster control/MATLAB Function': '<S114>:1' */
  /* '<S114>:1:5' */
  if (rtb_sys[11] < 0.0) {
    rtb_eta_w_idx_0 = -1.0;
  } else if (rtb_sys[11] > 0.0) {
    rtb_eta_w_idx_0 = 1.0;
  } else if (rtb_sys[11] == 0.0) {
    rtb_eta_w_idx_0 = 0.0;
  } else {
    rtb_eta_w_idx_0 = rtb_sys[11];
  }

  rtb_eta_w_idx_2 = sqrt(fabs(rtb_sys[11]) / (ctrl_TAPM_P.Rho * rt_powd_snf
    (ctrl_TAPM_P.D, 4.0) * ctrl_TAPM_P.K_T6f)) * rtb_eta_w_idx_0;

  /* '<S114>:1:7' */
  offset = tanh(ctrl_TAPM_P.eps_c * rtb_eta_w_idx_2 / 27.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S114>:1:8' */
  /* '<S114>:1:10' */
  if (ctrl_TAPM_B.Delay_il < 0.0) {
    rtb_eta_w_idx_0 = -1.0;
  } else if (ctrl_TAPM_B.Delay_il > 0.0) {
    rtb_eta_w_idx_0 = 1.0;
  } else if (ctrl_TAPM_B.Delay_il == 0.0) {
    rtb_eta_w_idx_0 = 0.0;
  } else {
    rtb_eta_w_idx_0 = ctrl_TAPM_B.Delay_il;
  }

  rtb_T_r = ((1.0 - offset) * ctrl_TAPM_P.K_T6r + ctrl_TAPM_P.K_T6f * offset) *
    rtb_eta_w_idx_0 * ctrl_TAPM_P.Rho * rt_powd_snf(ctrl_TAPM_P.D, 4.0) *
    (ctrl_TAPM_B.Delay_il * ctrl_TAPM_B.Delay_il);
  ctrl_TAPM_B.n_d = rtb_eta_w_idx_2;

  /* End of MATLAB Function: '<S110>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S110>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S110>/Constant1'
     *  Constant: '<S110>/Constant2'
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

    /* SampleTimeMath: '<S113>/TSamp'
     *
     * About '<S113>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM_B.TSamp_o = ctrl_TAPM_B.DiscreteTransferFcn_j *
      ctrl_TAPM_P.TSamp_WtEt_kk;

    /* Sum: '<S113>/Diff' incorporates:
     *  UnitDelay: '<S113>/UD'
     */
    rtb_Sum_b = ctrl_TAPM_B.TSamp_o - ctrl_TAPM_DW.UD_DSTATE_l;

    /* RateLimiter: '<S110>/Acceleration limiter' */
    rtb_eta_w_idx_2 = rtb_Sum_b - ctrl_TAPM_DW.PrevY_h;
    if (rtb_eta_w_idx_2 > ctrl_TAPM_P.Accelerationlimiter_RisingLi_bi) {
      rtb_Sum_b = ctrl_TAPM_DW.PrevY_h +
        ctrl_TAPM_P.Accelerationlimiter_RisingLi_bi;
    } else {
      if (rtb_eta_w_idx_2 < ctrl_TAPM_P.Accelerationlimiter_FallingLi_p) {
        rtb_Sum_b = ctrl_TAPM_DW.PrevY_h +
          ctrl_TAPM_P.Accelerationlimiter_FallingLi_p;
      }
    }

    ctrl_TAPM_DW.PrevY_h = rtb_Sum_b;

    /* End of RateLimiter: '<S110>/Acceleration limiter' */

    /* Gain: '<S110>/Inertia compensation' */
    ctrl_TAPM_B.Inertiacompensation_e3 = ctrl_TAPM_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S110>/Sum1' incorporates:
     *  Gain: '<S110>/Qf_0'
     *  Gain: '<S110>/Qff_0(nr)'
     *  Gain: '<S110>/Qff_1(nr)'
     *  Trigonometry: '<S110>/Trigonometric Function'
     */
    ctrl_TAPM_B.Sum1_io = tanh(ctrl_TAPM_P.epsilon / ctrl_TAPM_P.n_max *
      ctrl_TAPM_B.DiscreteTransferFcn_j) * ctrl_TAPM_P.Q_f0 +
      ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM_B.DiscreteTransferFcn_j;

    /* Memory: '<S110>/Memory' */
    ctrl_TAPM_B.Memory_o = ctrl_TAPM_DW.Memory_PreviousInput_a4;

    /* Sum: '<S112>/Sum' */
    rtb_Sum_b = ctrl_TAPM_B.DiscreteTransferFcn_j - ctrl_TAPM_B.Delay_n[5];

    /* Gain: '<S112>/Kp' */
    ctrl_TAPM_B.Kp_l = ctrl_TAPM_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S112>/Integrator' */
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

  rtb_Integrator_ld = ctrl_TAPM_X.Integrator_CSTATE_gj;

  /* MATLAB Function: '<S112>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/D'
   *  Constant: '<S7>/K_Qr12'
   *  Constant: '<S7>/K_Qr6'
   *  Constant: '<S7>/K_Tf6'
   *  Constant: '<S7>/K_Tr6'
   *  Constant: '<S7>/Rho'
   */
  CorecontrollerTorquePowerandCom(ctrl_TAPM_P.k_cc, ctrl_TAPM_P.p_cc,
    ctrl_TAPM_P.r_cc, ctrl_TAPM_B.Delay_n[5], ctrl_TAPM_P.K_T6f,
    ctrl_TAPM_P.K_q6f, ctrl_TAPM_P.D, rtb_T_r, ctrl_TAPM_P.Rho,
    ctrl_TAPM_P.eps_c, ctrl_TAPM_P.K_T6r, ctrl_TAPM_P.K_q6r,
    &ctrl_TAPM_B.sf_CorecontrollerTorquePower_nf);

  /* MultiPortSwitch: '<S110>/Controller chosen' incorporates:
   *  Constant: '<S110>/NaN'
   *  Sum: '<S112>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM_B.Memory_o) {
   case 1:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.Kp_l + rtb_Integrator_ld;
    break;

   case 2:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePower_nf.Qcq;
    break;

   case 3:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePower_nf.Qcp;
    break;

   case 4:
    rtb_eta_w_idx_2 = ctrl_TAPM_B.sf_CorecontrollerTorquePower_nf.Qcc;
    break;

   default:
    rtb_eta_w_idx_2 = ctrl_TAPM_P.NaN_Value_j;
    break;
  }

  /* End of MultiPortSwitch: '<S110>/Controller chosen' */

  /* Sum: '<S110>/Sum' */
  ctrl_TAPM_B.Sum_f = (ctrl_TAPM_B.Inertiacompensation_e3 + ctrl_TAPM_B.Sum1_io)
    + rtb_eta_w_idx_2;
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* DiscreteTransferFcn: '<S55>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S55>/Constant'
     *  Constant: '<S55>/Constant1'
     */
    ctrl_TAPM_DW.DiscreteTransferFcn_tmp_cw = ctrl_TAPM_B.Sum_f -
      ctrl_TAPM_P.Constant_Value_ht[1] *
      ctrl_TAPM_DW.DiscreteTransferFcn_states_o;
    ctrl_TAPM_B.DiscreteTransferFcn_ea = ctrl_TAPM_P.Constant1_Value_gs[0] *
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_cw + ctrl_TAPM_P.Constant1_Value_gs[1]
      * ctrl_TAPM_DW.DiscreteTransferFcn_states_o;
  }

  /* Gain: '<S109>/Finding rotation speed' incorporates:
   *  Gain: '<S109>/K_omega'
   *  Sum: '<S109>/Sum'
   */
  ctrl_TAPM_B.Findingrotationspeed_c = ((ctrl_TAPM_B.DiscreteTransferFcn_ea -
    ctrl_TAPM_B.Delay_h) - ctrl_TAPM_P.K_omega * 2.0 * 3.1415926535897931 *
    rtb_Integrator_m) * (1.0 / (6.2831853071795862 * ctrl_TAPM_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Gain: '<S112>/Ki' */
    ctrl_TAPM_B.Ki_p = ctrl_TAPM_P.Kp / 0.05 * rtb_Sum_b;
  }

  /* MATLAB Function: '<S110>/Supervisor' */
  ctrl_TAPM_Supervisor(ctrl_TAPM_B.Memory_o, ctrl_TAPM_B.Core_controller,
                       ctrl_TAPM_B.Delay_n[5], &ctrl_TAPM_B.sf_Supervisor_e);
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* SignalConversion: '<S8>/TmpSignal ConversionAtDelayInport1' */
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[0] = ctrl_TAPM_B.output[1];
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[1] = ctrl_TAPM_B.output[3];
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[2] = ctrl_TAPM_B.output[5];
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[3] = ctrl_TAPM_B.output[7];
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[4] = ctrl_TAPM_B.output[9];
    ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[5] = ctrl_TAPM_B.output[11];
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
    /* Update for Delay: '<S19>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE = ctrl_TAPM_B.Integrator;
  }

  /* Update for Iterator SubSystem: '<S6>/Optimal angle path and  constraints on rotation speed' */
  for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
    /* Update for ForEachSliceSelector: '<S42>/ImpSel_InsertedFor_reset_at_outport_0' */
    rtb_ImpSel_InsertedFor_reset_at = ctrl_TAPM_B.reset[ForEach_itr];
    if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
      /* Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
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

      /* End of Update for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */

      /* Update for Delay: '<S42>/Delay' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_TAPM_B.CoreSubsys[ForEach_itr].angle;
    }
  }

  /* End of Update for SubSystem: '<S6>/Optimal angle path and  constraints on rotation speed' */
  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for Delay: '<S8>/Delay' */
    for (i = 0; i < 6; i++) {
      ctrl_TAPM_DW.Delay_DSTATE_i[i] =
        ctrl_TAPM_B.TmpSignalConversionAtDelayInpor[i];
    }

    /* End of Update for Delay: '<S8>/Delay' */

    /* Update for Delay: '<S50>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_f = ctrl_TAPM_B.Qa;

    /* Update for Delay: '<S65>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_fu = ctrl_TAPM_B.DiscreteTransferFcn;

    /* Update for DiscreteTransferFcn: '<S65>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp;

    /* Update for UnitDelay: '<S68>/UD' */
    ctrl_TAPM_DW.UD_DSTATE = ctrl_TAPM_B.TSamp;

    /* Update for Memory: '<S65>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput = ctrl_TAPM_B.sf_Supervisor.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S50>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_d =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_a;

    /* Update for Delay: '<S51>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_b = ctrl_TAPM_B.sf_ActualForceandTorque_f.Qa;

    /* Update for Delay: '<S74>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_d = ctrl_TAPM_B.DiscreteTransferFcn_e;

    /* Update for DiscreteTransferFcn: '<S74>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_h[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_d;

    /* Update for UnitDelay: '<S77>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_n = ctrl_TAPM_B.TSamp_n;

    /* Update for Memory: '<S74>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_n = ctrl_TAPM_B.sf_Supervisor_h.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S51>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_m =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h;

    /* Update for Delay: '<S52>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_n = ctrl_TAPM_B.sf_ActualForceandTorque_h.Qa;

    /* Update for Delay: '<S83>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_no = ctrl_TAPM_B.DiscreteTransferFcn_f;

    /* Update for DiscreteTransferFcn: '<S83>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_j[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_e;

    /* Update for UnitDelay: '<S86>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_i = ctrl_TAPM_B.TSamp_k;

    /* Update for Memory: '<S83>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_d = ctrl_TAPM_B.sf_Supervisor_l.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S52>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_k =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_hh;

    /* Update for Delay: '<S53>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_e = ctrl_TAPM_B.sf_ActualForceandTorque_m.Qa;

    /* Update for Delay: '<S92>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_id = ctrl_TAPM_B.DiscreteTransferFcn_l;

    /* Update for DiscreteTransferFcn: '<S92>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_i[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_i[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_i[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_k;

    /* Update for UnitDelay: '<S95>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_n4 = ctrl_TAPM_B.TSamp_a;

    /* Update for Memory: '<S92>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_a = ctrl_TAPM_B.sf_Supervisor_n.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S53>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h0 =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_n;

    /* Update for Delay: '<S54>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_j = ctrl_TAPM_B.sf_ActualForceandTorque_o.Qa;

    /* Update for Delay: '<S101>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_a = ctrl_TAPM_B.DiscreteTransferFcn_o;

    /* Update for DiscreteTransferFcn: '<S101>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_c;

    /* Update for UnitDelay: '<S104>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_m = ctrl_TAPM_B.TSamp_m;

    /* Update for Memory: '<S101>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_b = ctrl_TAPM_B.sf_Supervisor_b.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S54>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_dt =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_f;

    /* Update for Delay: '<S55>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_dv = ctrl_TAPM_B.sf_ActualForceandTorque_j.Qa;

    /* Update for Delay: '<S110>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_m = ctrl_TAPM_B.DiscreteTransferFcn_j;

    /* Update for DiscreteTransferFcn: '<S110>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_l[1] =
      ctrl_TAPM_DW.DiscreteTransferFcn_states_l[0];
    ctrl_TAPM_DW.DiscreteTransferFcn_states_l[0] =
      ctrl_TAPM_DW.DiscreteTransferFcn_tmp_h4;

    /* Update for UnitDelay: '<S113>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_l = ctrl_TAPM_B.TSamp_o;

    /* Update for Memory: '<S110>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_a4 = ctrl_TAPM_B.sf_Supervisor_e.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM_M)) {
    /* Update for DiscreteTransferFcn: '<S55>/Discrete Transfer Fcn' */
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

  /* Derivatives for Integrator: '<S18>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = ctrl_TAPM_B.Sum3[0];
  _rtXdot->Integrator_CSTATE[1] = ctrl_TAPM_B.Sum3[1];
  _rtXdot->Integrator_CSTATE[2] = ctrl_TAPM_B.Sum3[2];

  /* Derivatives for Integrator: '<S20>/Integrator' */
  _rtXdot->Integrator_CSTATE_l[0] = ctrl_TAPM_B.Sum1[0];
  _rtXdot->Integrator_CSTATE_l[1] = ctrl_TAPM_B.Sum1[1];

  /* Derivatives for TransferFcn: '<S20>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += ctrl_TAPM_P.TransferFcn2_A *
    ctrl_TAPM_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += ctrl_TAPM_B.Sum;

  /* Derivatives for Integrator: '<S31>/Integrator' */
  _rtXdot->Integrator_CSTATE_g[0] = ctrl_TAPM_B.TmpSignalConversionAtMatrixMult
    [0];
  _rtXdot->Integrator_CSTATE_g[1] = ctrl_TAPM_B.TmpSignalConversionAtMatrixMult
    [1];
  _rtXdot->Integrator_CSTATE_g[2] = ctrl_TAPM_B.TmpSignalConversionAtMatrixMult
    [2];

  /* Derivatives for Integrator: '<S18>/Integrator4' */
  _rtXdot->Integrator4_CSTATE[0] = ctrl_TAPM_B.Gain3[0];
  _rtXdot->Integrator4_CSTATE[1] = ctrl_TAPM_B.Gain3[1];
  _rtXdot->Integrator4_CSTATE[2] = ctrl_TAPM_B.Gain3[2];

  /* Derivatives for Integrator: '<S32>/Integrator' */
  _rtXdot->Integrator_CSTATE_k[0] = ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_b
    [0];
  _rtXdot->Integrator_CSTATE_k[1] = ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_b
    [1];
  _rtXdot->Integrator_CSTATE_k[2] = ctrl_TAPM_B.TmpSignalConversionAtMatrixMu_b
    [2];

  /* Derivatives for Integrator: '<S64>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_c =
      ctrl_TAPM_B.Findingrotationspeed;
  }

  /* Derivatives for Integrator: '<S73>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_p =
      ctrl_TAPM_B.Findingrotationspeed_a;
  }

  /* Derivatives for Integrator: '<S82>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_km =
      ctrl_TAPM_B.Findingrotationspeed_m;
  }

  /* Derivatives for Integrator: '<S91>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_n =
      ctrl_TAPM_B.Findingrotationspeed_ms;
  }

  /* Derivatives for Integrator: '<S100>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_cd =
      ctrl_TAPM_B.Findingrotationspeed_ag;
  }

  /* Derivatives for Integrator: '<S109>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_h =
      ctrl_TAPM_B.Findingrotationspeed_c;
  }

  /* Derivatives for Integrator: '<S18>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ctrl_TAPM_B.Sum6[0];
  _rtXdot->Integrator1_CSTATE[1] = ctrl_TAPM_B.Sum6[1];
  _rtXdot->Integrator1_CSTATE[2] = ctrl_TAPM_B.Sum6[2];

  /* Derivatives for Integrator: '<S18>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_TAPM_B.psi_WF[0];
  _rtXdot->Integrator2_CSTATE[1] = ctrl_TAPM_B.psi_WF[1];
  _rtXdot->Integrator2_CSTATE[2] = ctrl_TAPM_B.psi_WF[2];

  /* Derivatives for Integrator: '<S18>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[0] = ctrl_TAPM_B.Sum7[0];
  _rtXdot->Integrator3_CSTATE[1] = ctrl_TAPM_B.Sum7[1];
  _rtXdot->Integrator3_CSTATE[2] = ctrl_TAPM_B.Sum7[2];

  /* Derivatives for Integrator: '<S19>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_d =
      ctrl_TAPM_P.Constant_Value_o;
  }

  /* Derivatives for Integrator: '<S67>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_e =
      ctrl_TAPM_B.Ki;
  }

  /* Derivatives for Integrator: '<S76>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_gg =
      ctrl_TAPM_B.Ki_o;
  }

  /* Derivatives for Integrator: '<S85>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_i =
      ctrl_TAPM_B.Ki_n;
  }

  /* Derivatives for Integrator: '<S94>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_le =
      ctrl_TAPM_B.Ki_b;
  }

  /* Derivatives for Integrator: '<S103>/Integrator' */
  {
    ((XDot_ctrl_TAPM_T *) ctrl_TAPM_M->ModelData.derivs)->Integrator_CSTATE_n4 =
      ctrl_TAPM_B.Ki_a;
  }

  /* Derivatives for Integrator: '<S112>/Integrator' */
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

    /* Start for Iterator SubSystem: '<S6>/Optimal angle path and  constraints on rotation speed' */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].angle = 0.0;
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_DSTATE = 0.0;
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].Delay = 0.0;
      ctrl_TAPM_B.CoreSubsys[ForEach_itr].MaxRotationRate = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI = 1U;
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 2;

      /* InitializeConditions for Delay: '<S42>/Delay' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_TAPM_P.CoreSubsys.Delay_InitialCondition;
    }

    /* End of Start for SubSystem: '<S6>/Optimal angle path and  constraints on rotation speed' */
  }

  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_o = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
  ctrl_TAPM_PrevZCX.Integrator_Reset_ZCE_ax = UNINITIALIZED_ZCSIG;
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

    /* InitializeConditions for Delay: '<S19>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE = ctrl_TAPM_P.Delay_InitialCondition;

    /* InitializeConditions for Integrator: '<S18>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE[0] = ctrl_TAPM_P.Integrator_IC[0];
    ctrl_TAPM_X.Integrator_CSTATE[1] = ctrl_TAPM_P.Integrator_IC[1];
    ctrl_TAPM_X.Integrator_CSTATE[2] = ctrl_TAPM_P.Integrator_IC[2];

    /* InitializeConditions for MATLAB Function: '<S19>/MATLAB Function' */
    ctrl_TAPM_DW.controller = 1.0;
    ctrl_TAPM_DW.tmp = 0.0;

    /* InitializeConditions for Integrator: '<S20>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_l[0] = ctrl_TAPM_P.Integrator_IC_b[0];
    ctrl_TAPM_X.Integrator_CSTATE_l[1] = ctrl_TAPM_P.Integrator_IC_b[1];

    /* InitializeConditions for TransferFcn: '<S20>/Transfer Fcn2' */
    ctrl_TAPM_X.TransferFcn2_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S31>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_g[0] = ctrl_TAPM_P.Integrator_IC_f;
    ctrl_TAPM_X.Integrator_CSTATE_g[1] = ctrl_TAPM_P.Integrator_IC_f;
    ctrl_TAPM_X.Integrator_CSTATE_g[2] = ctrl_TAPM_P.Integrator_IC_f;

    /* InitializeConditions for Integrator: '<S18>/Integrator4' */
    ctrl_TAPM_X.Integrator4_CSTATE[0] = ctrl_TAPM_P.Integrator4_IC[0];
    ctrl_TAPM_X.Integrator4_CSTATE[1] = ctrl_TAPM_P.Integrator4_IC[1];
    ctrl_TAPM_X.Integrator4_CSTATE[2] = ctrl_TAPM_P.Integrator4_IC[2];

    /* InitializeConditions for Integrator: '<S32>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_k[0] = ctrl_TAPM_P.Integrator_IC_p;
    ctrl_TAPM_X.Integrator_CSTATE_k[1] = ctrl_TAPM_P.Integrator_IC_p;
    ctrl_TAPM_X.Integrator_CSTATE_k[2] = ctrl_TAPM_P.Integrator_IC_p;

    /* InitializeConditions for Iterator SubSystem: '<S6>/Optimal angle path and  constraints on rotation speed' */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      /* InitializeConditions for DiscreteIntegrator: '<S42>/Discrete-Time Integrator' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_IC_LOADI = 1U;
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].DiscreteTimeIntegrator_PrevRese = 2;

      /* InitializeConditions for Delay: '<S42>/Delay' */
      ctrl_TAPM_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        ctrl_TAPM_P.CoreSubsys.Delay_InitialCondition;
    }

    /* End of InitializeConditions for SubSystem: '<S6>/Optimal angle path and  constraints on rotation speed' */
    /* InitializeConditions for Integrator: '<S64>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_c = ctrl_TAPM_P.Integrator_IC_fg;

    /* InitializeConditions for Integrator: '<S73>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_p = ctrl_TAPM_P.Integrator_IC_fgw;

    /* InitializeConditions for Integrator: '<S82>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_km = ctrl_TAPM_P.Integrator_IC_pl;

    /* InitializeConditions for Integrator: '<S91>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_n = ctrl_TAPM_P.Integrator_IC_fv;

    /* InitializeConditions for Integrator: '<S100>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_cd = ctrl_TAPM_P.Integrator_IC_l;

    /* InitializeConditions for Integrator: '<S109>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_h = ctrl_TAPM_P.Integrator_IC_li;

    /* InitializeConditions for Integrator: '<S18>/Integrator1' */
    ctrl_TAPM_X.Integrator1_CSTATE[0] = ctrl_TAPM_P.Integrator1_IC;
    ctrl_TAPM_X.Integrator1_CSTATE[1] = ctrl_TAPM_P.Integrator1_IC;
    ctrl_TAPM_X.Integrator1_CSTATE[2] = ctrl_TAPM_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<S18>/Integrator2' */
    ctrl_TAPM_X.Integrator2_CSTATE[0] = ctrl_TAPM_P.Integrator2_IC;
    ctrl_TAPM_X.Integrator2_CSTATE[1] = ctrl_TAPM_P.Integrator2_IC;
    ctrl_TAPM_X.Integrator2_CSTATE[2] = ctrl_TAPM_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S18>/Integrator3' */
    ctrl_TAPM_X.Integrator3_CSTATE[0] = ctrl_TAPM_P.Integrator3_IC;
    ctrl_TAPM_X.Integrator3_CSTATE[1] = ctrl_TAPM_P.Integrator3_IC;
    ctrl_TAPM_X.Integrator3_CSTATE[2] = ctrl_TAPM_P.Integrator3_IC;

    /* InitializeConditions for Integrator: '<S19>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_d = ctrl_TAPM_P.Integrator_IC_d;

    /* InitializeConditions for Delay: '<S8>/Delay' */
    for (i = 0; i < 6; i++) {
      ctrl_TAPM_DW.Delay_DSTATE_i[i] = ctrl_TAPM_P.Delay_InitialCondition_j;
    }

    /* End of InitializeConditions for Delay: '<S8>/Delay' */

    /* InitializeConditions for Delay: '<S50>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_f = ctrl_TAPM_P.Delay_InitialCondition_i;

    /* InitializeConditions for Delay: '<S65>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_fu = ctrl_TAPM_P.Delay_InitialCondition_f;

    /* InitializeConditions for DiscreteTransferFcn: '<S65>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialStat;
    ctrl_TAPM_DW.DiscreteTransferFcn_states[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialStat;

    /* InitializeConditions for UnitDelay: '<S68>/UD' */
    ctrl_TAPM_DW.UD_DSTATE = ctrl_TAPM_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for RateLimiter: '<S65>/Acceleration Limit' */
    ctrl_TAPM_DW.PrevY = ctrl_TAPM_P.AccelerationLimit_IC;

    /* InitializeConditions for Memory: '<S65>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput = ctrl_TAPM_P.Memory_X0;

    /* InitializeConditions for Integrator: '<S67>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_e = ctrl_TAPM_P.Integrator_IC_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S50>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_d =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_h;

    /* InitializeConditions for Delay: '<S51>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_b = ctrl_TAPM_P.Delay_InitialCondition_l;

    /* InitializeConditions for Delay: '<S74>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_d = ctrl_TAPM_P.Delay_InitialCondition_iv;

    /* InitializeConditions for DiscreteTransferFcn: '<S74>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_hu;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_hu;

    /* InitializeConditions for UnitDelay: '<S77>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_n = ctrl_TAPM_P.DiscreteDerivative_ICPrevScal_p;

    /* InitializeConditions for RateLimiter: '<S74>/Acceleration Limit' */
    ctrl_TAPM_DW.PrevY_e = ctrl_TAPM_P.AccelerationLimit_IC_m;

    /* InitializeConditions for Memory: '<S74>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_n = ctrl_TAPM_P.Memory_X0_e;

    /* InitializeConditions for Integrator: '<S76>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_gg = ctrl_TAPM_P.Integrator_IC_fy;

    /* InitializeConditions for DiscreteTransferFcn: '<S51>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_m =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_f;

    /* InitializeConditions for Delay: '<S52>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_n = ctrl_TAPM_P.Delay_InitialCondition_d;

    /* InitializeConditions for Delay: '<S83>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_no = ctrl_TAPM_P.Delay_InitialCondition_h;

    /* InitializeConditions for DiscreteTransferFcn: '<S83>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_j[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_a;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_j[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_a;

    /* InitializeConditions for UnitDelay: '<S86>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_i = ctrl_TAPM_P.DiscreteDerivative_ICPrevSca_pl;

    /* InitializeConditions for RateLimiter: '<S83>/Acceleration limiter' */
    ctrl_TAPM_DW.PrevY_o = ctrl_TAPM_P.Accelerationlimiter_IC;

    /* InitializeConditions for Memory: '<S83>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_d = ctrl_TAPM_P.Memory_X0_g;

    /* InitializeConditions for Integrator: '<S85>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_i = ctrl_TAPM_P.Integrator_IC_j;

    /* InitializeConditions for DiscreteTransferFcn: '<S52>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_k =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_c;

    /* InitializeConditions for Delay: '<S53>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_e = ctrl_TAPM_P.Delay_InitialCondition_fb;

    /* InitializeConditions for Delay: '<S92>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_id = ctrl_TAPM_P.Delay_InitialCondition_g;

    /* InitializeConditions for DiscreteTransferFcn: '<S92>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_i[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_a1;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_i[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_a1;

    /* InitializeConditions for UnitDelay: '<S95>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_n4 = ctrl_TAPM_P.DiscreteDerivative_ICPrevScal_f;

    /* InitializeConditions for RateLimiter: '<S92>/Acceleration limiter' */
    ctrl_TAPM_DW.PrevY_c = ctrl_TAPM_P.Accelerationlimiter_IC_h;

    /* InitializeConditions for Memory: '<S92>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_a = ctrl_TAPM_P.Memory_X0_k;

    /* InitializeConditions for Integrator: '<S94>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_le = ctrl_TAPM_P.Integrator_IC_g;

    /* InitializeConditions for DiscreteTransferFcn: '<S53>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_h0 =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_p;

    /* InitializeConditions for Delay: '<S54>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_j = ctrl_TAPM_P.Delay_InitialCondition_fv;

    /* InitializeConditions for Delay: '<S101>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_a = ctrl_TAPM_P.Delay_InitialCondition_dz;

    /* InitializeConditions for DiscreteTransferFcn: '<S101>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_e;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_hb[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialSt_e;

    /* InitializeConditions for UnitDelay: '<S104>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_m = ctrl_TAPM_P.DiscreteDerivative_ICPrevScal_o;

    /* InitializeConditions for RateLimiter: '<S101>/Acceleration limiter' */
    ctrl_TAPM_DW.PrevY_j = ctrl_TAPM_P.Accelerationlimiter_IC_i;

    /* InitializeConditions for Memory: '<S101>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_b = ctrl_TAPM_P.Memory_X0_k3;

    /* InitializeConditions for Integrator: '<S103>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_n4 = ctrl_TAPM_P.Integrator_IC_aj;

    /* InitializeConditions for DiscreteTransferFcn: '<S54>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_dt =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_pj;

    /* InitializeConditions for Delay: '<S55>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_dv = ctrl_TAPM_P.Delay_InitialCondition_fi;

    /* InitializeConditions for Delay: '<S110>/Delay' */
    ctrl_TAPM_DW.Delay_DSTATE_m = ctrl_TAPM_P.Delay_InitialCondition_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S110>/Discrete Transfer Fcn' */
    ctrl_TAPM_DW.DiscreteTransferFcn_states_l[0] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_a4;
    ctrl_TAPM_DW.DiscreteTransferFcn_states_l[1] =
      ctrl_TAPM_P.DiscreteTransferFcn_InitialS_a4;

    /* InitializeConditions for UnitDelay: '<S113>/UD' */
    ctrl_TAPM_DW.UD_DSTATE_l = ctrl_TAPM_P.DiscreteDerivative_ICPrevScal_n;

    /* InitializeConditions for RateLimiter: '<S110>/Acceleration limiter' */
    ctrl_TAPM_DW.PrevY_h = ctrl_TAPM_P.Accelerationlimiter_IC_p;

    /* InitializeConditions for Memory: '<S110>/Memory' */
    ctrl_TAPM_DW.Memory_PreviousInput_a4 = ctrl_TAPM_P.Memory_X0_c;

    /* InitializeConditions for Integrator: '<S112>/Integrator' */
    ctrl_TAPM_X.Integrator_CSTATE_gj = ctrl_TAPM_P.Integrator_IC_h;

    /* InitializeConditions for DiscreteTransferFcn: '<S55>/Discrete Transfer Fcn' */
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
  ctrl_TAPM_M->Sizes.numContStates = (37);/* Number of continuous states */
  ctrl_TAPM_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_TAPM_M->Sizes.numY = (0);       /* Number of model outputs */
  ctrl_TAPM_M->Sizes.numU = (0);       /* Number of model inputs */
  ctrl_TAPM_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_TAPM_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_TAPM_M->Sizes.numBlocks = (549);/* Number of blocks */
  ctrl_TAPM_M->Sizes.numBlockIO = (214);/* Number of block outputs */
  ctrl_TAPM_M->Sizes.numBlockPrms = (969);/* Sum of parameter "widths" */
  return ctrl_TAPM_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_TAPM
 * Model version : 1.145
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Fri Jul 08 20:12:54 2016
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

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
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 39:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 40:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 41:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 43:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 45:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 46:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 51:
    return NIRT_GetValueByDataType(ptr,subindex,50,Complex);

   case 59:
    return NIRT_GetValueByDataType(ptr,subindex,58,Complex);

   case 67:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 68:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 69:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 70:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

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
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 39:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 40:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 41:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 43:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 45:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 46:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 51:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,50,Complex);

   case 59:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,58,Complex);

   case 67:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 68:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 69:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 70:
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

  // ctrl_TAPM/Input/Core_controller
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.Core_controller, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_i_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_i_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_d_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_d_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_d_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_d_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_d_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_d_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_i_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_i_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_i_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_i_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_p_psi
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_p_psi, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_p_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_p_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_p_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_p_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_d_psi1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_d_psi1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_d_x1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_d_x1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_d_y1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_d_y1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_i_psi1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_i_psi1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_i_x1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_i_x1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_i_y1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_i_y1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_p_psi1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_p_psi1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_p_x1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_p_x1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/Input/K_p_y1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM_B.K_p_y1, 0, data[index++], 0, 0);
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
      NIRT_SetValueByDataType(&ctrl_TAPM_B.reset, count, data[index++], 21, 0);
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
  return 57;
}

int32_t NumOutputPorts(void)
{
  return 36;
}

double ni_extout[36];

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
      (&ctrl_TAPM_B.sf_MATLABFunction2_i.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.sf_MATLABFunction3_p.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.sf_MATLABFunction4_b.Tc_out, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/pwm_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM_B.sf_MATLABFunction5_h.Tc_out, 0, 0, 0);
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
      (&ctrl_TAPM_B.sf_MATLABFunction6_k.Tc_out, 0, 0, 0);
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
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Tc_out, 0, 0, 0);
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
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.nu, 0, 26, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.nu, 1, 26, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.nu, 2, 26, 0);
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
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.MultiportSwitch, 0,
      26, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.MultiportSwitch, 1,
      26, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.MultiportSwitch, 2,
      26, 0);
  } else {
    index += 3;
  }

  // ctrl_TAPM/TAPM Controller w_observer/PID/controller: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.y, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM/TAPM Controller w_observer/PID/timer: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Delay, 0, 0, 0);
  } else {
    index += 1;
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
    (&ctrl_TAPM_B.sf_MATLABFunction2_i.Tc_out, 0, 0, 0);

  // ctrl_TAPM/pwm_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.sf_MATLABFunction3_p.Tc_out, 0, 0, 0);

  // ctrl_TAPM/pwm_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.sf_MATLABFunction4_b.Tc_out, 0, 0, 0);

  // ctrl_TAPM/pwm_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.sf_MATLABFunction5_h.Tc_out, 0, 0, 0);

  // ctrl_TAPM/alpha_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Saturation2, 0, 0, 0);

  // ctrl_TAPM/pwm_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.sf_MATLABFunction6_k.Tc_out, 0, 0, 0);

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
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Tc_out, 0, 0, 0);

  // ctrl_TAPM/tau_actual: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.commanded_tau, 0, 22,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.commanded_tau, 1, 22,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.commanded_tau, 2, 22,
    0);

  // ctrl_TAPM/TAPM Controller w_observer/eta_est: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.eta, 0, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.eta, 1, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.eta, 2, 22, 0);

  // ctrl_TAPM/TAPM Controller w_observer/nu_est: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.nu, 0, 26, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.nu, 1, 26, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.nu, 2, 26, 0);

  // ctrl_TAPM/TAPM Controller w_observer/SP: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.TmpSignalConversionAtSPInport1, 0, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.TmpSignalConversionAtSPInport1, 1, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM_B.TmpSignalConversionAtSPInport1, 2, 22, 0);

  // ctrl_TAPM/TAPM Controller w_observer/tau_des: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.MultiportSwitch, 0,
    26, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.MultiportSwitch, 1,
    26, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.MultiportSwitch, 2,
    26, 0);

  // ctrl_TAPM/TAPM Controller w_observer/PID/controller: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.y, 0, 0, 0);

  // ctrl_TAPM/TAPM Controller w_observer/PID/timer: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM_B.Delay, 0, 0, 0);

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
  { 0, "ctrl_tapm/Thrust allocation/C/Value", offsetof(P_ctrl_TAPM_T, C), 29, 24,
    2, 0, 0 },

  { 1, "ctrl_tapm/Thruster Parameters /D/Value", offsetof(P_ctrl_TAPM_T, D), 67,
    1, 2, 2, 0 },

  { 2,
    "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 67, 1, 2, 4, 0 },

  { 3,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 67, 1, 2, 6, 0 },

  { 4,
    "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 67, 1, 2, 8, 0 },

  { 5,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 67, 1, 2, 10, 0 },

  { 6,
    "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 67, 1, 2, 12, 0 },

  { 7,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 67, 1, 2, 14, 0 },

  { 8,
    "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 67, 1, 2, 16, 0 },

  { 9,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 67, 1, 2, 18, 0 },

  { 10,
    "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 67, 1, 2, 20, 0 },

  { 11,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 67, 1, 2, 22, 0 },

  { 12,
    "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 67, 1, 2, 24, 0 },

  { 13,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM_T, I_s), 67, 1, 2, 26, 0 },

  { 14, "ctrl_tapm/Thruster Parameters /K_Tf1/Value", offsetof(P_ctrl_TAPM_T,
    K_T1f), 67, 1, 2, 28, 0 },

  { 15, "ctrl_tapm/Thruster Parameters /K_Tr1/Value", offsetof(P_ctrl_TAPM_T,
    K_T1r), 67, 1, 2, 30, 0 },

  { 16, "ctrl_tapm/Thruster Parameters /K_Tf2/Value", offsetof(P_ctrl_TAPM_T,
    K_T2f), 67, 1, 2, 32, 0 },

  { 17, "ctrl_tapm/Thruster Parameters /K_Tr2/Value", offsetof(P_ctrl_TAPM_T,
    K_T2r), 67, 1, 2, 34, 0 },

  { 18, "ctrl_tapm/Thruster Parameters /K_Tf3/Value", offsetof(P_ctrl_TAPM_T,
    K_T3f), 67, 1, 2, 36, 0 },

  { 19, "ctrl_tapm/Thruster Parameters /K_Tr3/Value", offsetof(P_ctrl_TAPM_T,
    K_T3r), 67, 1, 2, 38, 0 },

  { 20, "ctrl_tapm/Thruster Parameters /K_Tf4/Value", offsetof(P_ctrl_TAPM_T,
    K_T4f), 67, 1, 2, 40, 0 },

  { 21, "ctrl_tapm/Thruster Parameters /K_Tr4/Value", offsetof(P_ctrl_TAPM_T,
    K_T4r), 67, 1, 2, 42, 0 },

  { 22, "ctrl_tapm/Thruster Parameters /K_Tf5/Value", offsetof(P_ctrl_TAPM_T,
    K_T5f), 67, 1, 2, 44, 0 },

  { 23, "ctrl_tapm/Thruster Parameters /K_Tr5/Value", offsetof(P_ctrl_TAPM_T,
    K_T5r), 67, 1, 2, 46, 0 },

  { 24, "ctrl_tapm/Thruster Parameters /K_Tf6/Value", offsetof(P_ctrl_TAPM_T,
    K_T6f), 67, 1, 2, 48, 0 },

  { 25, "ctrl_tapm/Thruster Parameters /K_Tr6/Value", offsetof(P_ctrl_TAPM_T,
    K_T6r), 67, 1, 2, 50, 0 },

  { 26, "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 67, 1, 2, 52, 0 },

  { 27, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 67, 1, 2, 54, 0 },

  { 28, "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 67, 1, 2, 56, 0 },

  { 29, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 67, 1, 2, 58, 0 },

  { 30, "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 67, 1, 2, 60, 0 },

  { 31, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 67, 1, 2, 62, 0 },

  { 32, "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 67, 1, 2, 64, 0 },

  { 33, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 67, 1, 2, 66, 0 },

  { 34, "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 67, 1, 2, 68, 0 },

  { 35, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 67, 1, 2, 70, 0 },

  { 36, "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 67, 1, 2, 72, 0 },

  { 37, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, K_omega), 67, 1, 2, 74, 0 },

  { 38, "ctrl_tapm/Thruster Parameters /K_Qr1/Value", offsetof(P_ctrl_TAPM_T,
    K_q1f), 67, 1, 2, 76, 0 },

  { 39, "ctrl_tapm/Thruster Parameters /K_Qr7/Value", offsetof(P_ctrl_TAPM_T,
    K_q1r), 67, 1, 2, 78, 0 },

  { 40, "ctrl_tapm/Thruster Parameters /K_Qr2/Value", offsetof(P_ctrl_TAPM_T,
    K_q2f), 67, 1, 2, 80, 0 },

  { 41, "ctrl_tapm/Thruster Parameters /K_Qr8/Value", offsetof(P_ctrl_TAPM_T,
    K_q2r), 67, 1, 2, 82, 0 },

  { 42, "ctrl_tapm/Thruster Parameters /K_Qr3/Value", offsetof(P_ctrl_TAPM_T,
    K_q3f), 67, 1, 2, 84, 0 },

  { 43, "ctrl_tapm/Thruster Parameters /K_Qr9/Value", offsetof(P_ctrl_TAPM_T,
    K_q3r), 67, 1, 2, 86, 0 },

  { 44, "ctrl_tapm/Thruster Parameters /K_Qr4/Value", offsetof(P_ctrl_TAPM_T,
    K_q4f), 67, 1, 2, 88, 0 },

  { 45, "ctrl_tapm/Thruster Parameters /K_Qr10/Value", offsetof(P_ctrl_TAPM_T,
    K_q4r), 67, 1, 2, 90, 0 },

  { 46, "ctrl_tapm/Thruster Parameters /K_Qr5/Value", offsetof(P_ctrl_TAPM_T,
    K_q5f), 67, 1, 2, 92, 0 },

  { 47, "ctrl_tapm/Thruster Parameters /K_Qr11/Value", offsetof(P_ctrl_TAPM_T,
    K_q5r), 67, 1, 2, 94, 0 },

  { 48, "ctrl_tapm/Thruster Parameters /K_Qr6/Value", offsetof(P_ctrl_TAPM_T,
    K_q6f), 67, 1, 2, 96, 0 },

  { 49, "ctrl_tapm/Thruster Parameters /K_Qr12/Value", offsetof(P_ctrl_TAPM_T,
    K_q6r), 67, 1, 2, 98, 0 },

  { 50,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 67, 1, 2, 100, 0 },

  { 51,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 67, 1, 2, 102, 0 },

  { 52,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 67, 1, 2, 104, 0 },

  { 53,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 67, 1, 2, 106, 0 },

  { 54,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 67, 1, 2, 108, 0 },

  { 55,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 67, 1, 2, 110, 0 },

  { 56,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 67, 1, 2, 112, 0 },

  { 57,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 67, 1, 2, 114, 0 },

  { 58,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 67, 1, 2, 116, 0 },

  { 59,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 67, 1, 2, 118, 0 },

  { 60,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 67, 1, 2, 120, 0 },

  { 61,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM_T, Kp), 67, 1, 2, 122, 0 },

  { 62,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Max Rotation Rate/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_rotation), 67, 1, 2, 124, 0 },

  { 63,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Max Rotation Rate/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Max_rotation), 67, 1, 2, 126, 0 },

  { 64,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 1/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 67, 1, 2, 128, 0 },

  { 65,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 10/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 67, 1, 2, 130, 0 },

  { 66,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 12/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 67, 1, 2, 132, 0 },

  { 67,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 3/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 67, 1, 2, 134, 0 },

  { 68,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 5/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 67, 1, 2, 136, 0 },

  { 69,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 67, 1, 2, 138, 0 },

  { 70,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 67, 1, 2, 140, 0 },

  { 71,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 8/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Max_thrust), 67, 1, 2, 142, 0 },

  { 72,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 11/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Min_thrust), 67, 1, 2, 144, 0 },

  { 73,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 13/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Min_thrust), 67, 1, 2, 146, 0 },

  { 74,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 2/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Min_thrust), 67, 1, 2, 148, 0 },

  { 75,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 4/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Min_thrust), 67, 1, 2, 150, 0 },

  { 76,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 6/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Min_thrust), 67, 1, 2, 152, 0 },

  { 77,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 9/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Min_thrust), 67, 1, 2, 154, 0 },

  { 78, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 67, 1, 2, 156, 0 },

  { 79, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 67, 1, 2, 158, 0 },

  { 80, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 67, 1, 2, 160, 0 },

  { 81, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 67, 1, 2, 162, 0 },

  { 82, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 67, 1, 2, 164, 0 },

  { 83, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM_T, Q_f0), 67, 1, 2, 166, 0 },

  { 84, "ctrl_tapm/Thruster Parameters /Rho/Value", offsetof(P_ctrl_TAPM_T, Rho),
    67, 1, 2, 168, 0 },

  { 85, "ctrl_tapm/Thrust allocation/Constant to avoid singularities/Value",
    offsetof(P_ctrl_TAPM_T, eps), 67, 1, 2, 170, 0 },

  { 86, "ctrl_tapm/Thruster Parameters /Constant/Value", offsetof(P_ctrl_TAPM_T,
    eps_c), 67, 1, 2, 172, 0 },

  { 87, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 67, 1, 2, 174, 0 },

  { 88, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 67, 1, 2, 176, 0 },

  { 89, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 67, 1, 2, 178, 0 },

  { 90, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 67, 1, 2, 180, 0 },

  { 91, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 67, 1, 2, 182, 0 },

  { 92, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, epsilon), 67, 1, 2, 184, 0 },

  { 93, "ctrl_tapm/Thruster Parameters /Constant1/Value", offsetof(P_ctrl_TAPM_T,
    k_cc), 67, 1, 2, 186, 0 },

  { 94, "ctrl_tapm/Thruster Parameters /Constant5/Value", offsetof(P_ctrl_TAPM_T,
    n_c), 67, 1, 2, 188, 0 },

  { 95, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 67, 1, 2, 190, 0 },

  { 96, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 67, 1, 2, 192, 0 },

  { 97, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 67, 1, 2, 194, 0 },

  { 98, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 67, 1, 2, 196, 0 },

  { 99, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 67, 1, 2, 198, 0 },

  { 100,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM_T, n_max), 67, 1, 2, 200, 0 },

  { 101, "ctrl_tapm/Thruster Parameters /Constant2/Value", offsetof
    (P_ctrl_TAPM_T, p_cc), 67, 1, 2, 202, 0 },

  { 102,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 1/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr1_backward), 37, 6, 2, 204, 0 },

  { 103,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 1/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr1_forward), 37, 6, 2, 206, 0 },

  { 104,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 2/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr2_backward), 37, 6, 2, 208, 0 },

  { 105,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 2/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr2_forward), 37, 6, 2, 210, 0 },

  { 106,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 3/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr3_backward), 37, 6, 2, 212, 0 },

  { 107,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 3/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr3_forward), 37, 6, 2, 214, 0 },

  { 108,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 4/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr4_backward), 37, 6, 2, 216, 0 },

  { 109,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 4/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr4_forward), 37, 6, 2, 218, 0 },

  { 110,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 5/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr5_backward), 37, 6, 2, 220, 0 },

  { 111,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 5/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr5_forward), 37, 6, 2, 222, 0 },

  { 112,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/negative thrust 6/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr6_backward), 37, 6, 2, 224, 0 },

  { 113,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/positive thrust 6/Coefs",
    offsetof(P_ctrl_TAPM_T, pwm_thr6_forward), 37, 6, 2, 226, 0 },

  { 114, "ctrl_tapm/Thruster Parameters /Constant3/Value", offsetof
    (P_ctrl_TAPM_T, r_cc), 67, 1, 2, 228, 0 },

  { 115,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain6/Gain",
    offsetof(P_ctrl_TAPM_T, Nonlinearpassiveobserver_D), 24, 9, 2, 230, 0 },

  { 116,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScaled), 67, 1, 2, 232, 0 },

  { 117,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScal_p), 67, 1, 2, 234, 0 },

  { 118,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevSca_pl), 67, 1, 2, 236, 0 },

  { 119,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScal_f), 67, 1, 2, 238, 0 },

  { 120,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScal_o), 67, 1, 2, 240, 0 },

  { 121,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM_T, DiscreteDerivative_ICPrevScal_n), 67, 1, 2, 242, 0 },

  { 122,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /K3/Gain",
    offsetof(P_ctrl_TAPM_T, Nonlinearpassiveobserver_K3), 24, 9, 2, 244, 0 },

  { 123,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /K4/Gain",
    offsetof(P_ctrl_TAPM_T, Nonlinearpassiveobserver_K4), 24, 9, 2, 246, 0 },

  { 124,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /K2/Gain",
    offsetof(P_ctrl_TAPM_T, Nonlinearpassiveobserver_w_c), 24, 9, 2, 248, 0 },

  { 125, "ctrl_tapm/TAPM Controller w_observer/PID/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition), 67, 1, 2, 250, 0 },

  { 126,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC), 26, 3, 2, 252, 0 },

  { 127,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_UpperSat), 67, 1, 2, 254, 0 },

  { 128,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_LowerSat), 67, 1, 2, 256, 0 },

  { 129,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain), 67, 1, 2, 258, 0 },

  { 130,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_TAPM_T, Constant_Value), 67, 1, 2, 260, 0 },

  { 131,
    "ctrl_tapm/TAPM Controller w_observer/SP Generator/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_b), 38, 2, 2, 262, 0 },

  { 132, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Transfer Fcn2/A",
    offsetof(P_ctrl_TAPM_T, TransferFcn2_A), 67, 1, 2, 264, 0 },

  { 133, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Transfer Fcn2/C",
    offsetof(P_ctrl_TAPM_T, TransferFcn2_C), 67, 1, 2, 266, 0 },

  { 134,
    "ctrl_tapm/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_UpperSat_g), 67, 1, 2, 268, 0 },

  { 135,
    "ctrl_tapm/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_LowerSat_h), 67, 1, 2, 270, 0 },

  { 136,
    "ctrl_tapm/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain_p), 67, 1, 2, 272, 0 },

  { 137,
    "ctrl_tapm/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_TAPM_T, Constant_Value_k), 67, 1, 2, 274, 0 },

  { 138,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_UpperSat_l), 67, 1, 2, 276, 0 },

  { 139,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_LowerSat_l), 67, 1, 2, 278, 0 },

  { 140,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain_l), 67, 1, 2, 280, 0 },

  { 141,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_TAPM_T, Constant_Value_e), 67, 1, 2, 282, 0 },

  { 142,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_f), 67, 1, 2, 284, 0 },

  { 143,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator4/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator4_IC), 26, 3, 2, 286, 0 },

  { 144,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_UpperSat_h), 67, 1, 2, 288, 0 },

  { 145,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_LowerSat_d), 67, 1, 2, 290, 0 },

  { 146,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain_n), 67, 1, 2, 292, 0 },

  { 147,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_TAPM_T, Constant_Value_d), 67, 1, 2, 294, 0 },

  { 148,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_UpperSat_a), 67, 1, 2, 296, 0 },

  { 149,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation_LowerSat_lh), 67, 1, 2, 298, 0 },

  { 150,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain_j), 67, 1, 2, 300, 0 },

  { 151,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller1/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_TAPM_T, Constant_Value_c), 67, 1, 2, 302, 0 },

  { 152,
    "ctrl_tapm/TAPM Controller w_observer/PID/DP controller1/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_p), 67, 1, 2, 304, 0 },

  { 153, "ctrl_tapm/Thrust allocation/Radians to Degrees/Gain/Gain", offsetof
    (P_ctrl_TAPM_T, Gain_Gain_o), 67, 1, 2, 306, 0 },

  { 154, "ctrl_tapm/Thrust allocation/X-position Thruster/Value", offsetof
    (P_ctrl_TAPM_T, XpositionThruster_Value), 37, 6, 2, 308, 0 },

  { 155, "ctrl_tapm/Thrust allocation/Y-position Thruster/Value", offsetof
    (P_ctrl_TAPM_T, YpositionThruster_Value), 37, 6, 2, 310, 0 },

  { 156, "ctrl_tapm/Thrust allocation/constant angle/Value", offsetof
    (P_ctrl_TAPM_T, constantangle_Value), 37, 6, 2, 312, 0 },

  { 157, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/Threshold",
    offsetof(P_ctrl_TAPM_T, ChoosingFixedAzimuthangle_Thres), 67, 1, 2, 314, 0 },

  { 158, "ctrl_tapm/Thruster control /Subsystem1/Saturation 1/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation1_UpperSat), 67, 1, 2, 316, 0 },

  { 159, "ctrl_tapm/Thruster control /Subsystem1/Saturation 1/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation1_LowerSat), 67, 1, 2, 318, 0 },

  { 160,
    "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_fg), 67, 1, 2, 320, 0 },

  { 161, "ctrl_tapm/Thruster control /Thruster 1/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value), 67, 1, 2, 322, 0 },

  { 162,
    "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_fgw), 67, 1, 2, 324, 0 },

  { 163, "ctrl_tapm/Thruster control /Thruster 2/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_k), 67, 1, 2, 326, 0 },

  { 164,
    "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_pl), 67, 1, 2, 328, 0 },

  { 165, "ctrl_tapm/Thruster control /Thruster 3/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_n), 67, 1, 2, 330, 0 },

  { 166,
    "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_fv), 67, 1, 2, 332, 0 },

  { 167, "ctrl_tapm/Thruster control /Thruster 4/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_d), 67, 1, 2, 334, 0 },

  { 168,
    "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_l), 67, 1, 2, 336, 0 },

  { 169, "ctrl_tapm/Thruster control /Thruster 5/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_f), 67, 1, 2, 338, 0 },

  { 170,
    "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_li), 67, 1, 2, 340, 0 },

  { 171, "ctrl_tapm/Thruster control /Thruster 6/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM_T, Lossesplaceholder_Value_h), 67, 1, 2, 342, 0 },

  { 172,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Gain/Gain",
    offsetof(P_ctrl_TAPM_T, Gain_Gain_d), 67, 1, 2, 344, 0 },

  { 173,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Gain1/Gain",
    offsetof(P_ctrl_TAPM_T, Gain1_Gain), 67, 1, 2, 346, 0 },

  { 174,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Gain2/Gain",
    offsetof(P_ctrl_TAPM_T, Gain2_Gain), 67, 1, 2, 348, 0 },

  { 175,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Gain3/Gain",
    offsetof(P_ctrl_TAPM_T, Gain3_Gain), 67, 1, 2, 350, 0 },

  { 176,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Gain4/Gain",
    offsetof(P_ctrl_TAPM_T, Gain4_Gain), 67, 1, 2, 352, 0 },

  { 177,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Gain5/Gain",
    offsetof(P_ctrl_TAPM_T, Gain5_Gain), 67, 1, 2, 354, 0 },

  { 178,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 8/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation8_LowerSat), 67, 1, 2, 356, 0 },

  { 179,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 9/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation9_UpperSat), 67, 1, 2, 358, 0 },

  { 180,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 10/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation10_LowerSat), 67, 1, 2, 360, 0 },

  { 181,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 11/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation11_UpperSat), 67, 1, 2, 362, 0 },

  { 182,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 3/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation3_LowerSat), 67, 1, 2, 364, 0 },

  { 183,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 4/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation4_UpperSat), 67, 1, 2, 366, 0 },

  { 184,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 5/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation5_LowerSat), 67, 1, 2, 368, 0 },

  { 185,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 6/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation6_UpperSat), 67, 1, 2, 370, 0 },

  { 186, "ctrl_tapm/Thruster control /Subsystem1/Saturation 2/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation2_UpperSat), 67, 1, 2, 372, 0 },

  { 187, "ctrl_tapm/Thruster control /Subsystem1/Saturation 2/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation2_LowerSat), 67, 1, 2, 374, 0 },

  { 188,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 12/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation12_LowerSat), 67, 1, 2, 376, 0 },

  { 189,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 13/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation13_UpperSat), 67, 1, 2, 378, 0 },

  { 190, "ctrl_tapm/Thruster control /Subsystem1/Saturation 3/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation3_UpperSat), 67, 1, 2, 380, 0 },

  { 191, "ctrl_tapm/Thruster control /Subsystem1/Saturation 3/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation3_LowerSat_f), 67, 1, 2, 382, 0 },

  { 192, "ctrl_tapm/Thruster control /Subsystem1/Saturation 4/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation4_UpperSat_p), 67, 1, 2, 384, 0 },

  { 193, "ctrl_tapm/Thruster control /Subsystem1/Saturation 4/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation4_LowerSat), 67, 1, 2, 386, 0 },

  { 194, "ctrl_tapm/Thruster control /Subsystem1/Saturation 5/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation5_UpperSat), 67, 1, 2, 388, 0 },

  { 195, "ctrl_tapm/Thruster control /Subsystem1/Saturation 5/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation5_LowerSat_h), 67, 1, 2, 390, 0 },

  { 196, "ctrl_tapm/Thruster control /Subsystem1/Saturation 6/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation6_UpperSat_g), 67, 1, 2, 392, 0 },

  { 197, "ctrl_tapm/Thruster control /Subsystem1/Saturation 6/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation6_LowerSat), 67, 1, 2, 394, 0 },

  { 198,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 1/LowerLimit",
    offsetof(P_ctrl_TAPM_T, Saturation1_LowerSat_h), 67, 1, 2, 396, 0 },

  { 199,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 2/UpperLimit",
    offsetof(P_ctrl_TAPM_T, Saturation2_UpperSat_p), 67, 1, 2, 398, 0 },

  { 200, "ctrl_tapm/Radians to Degrees/Gain/Gain", offsetof(P_ctrl_TAPM_T,
    Gain_Gain_f), 67, 1, 2, 400, 0 },

  { 201, "ctrl_tapm/X-position Thruster/Value", offsetof(P_ctrl_TAPM_T,
    XpositionThruster_Value_e), 37, 6, 2, 402, 0 },

  { 202, "ctrl_tapm/Y-position Thruster/Value", offsetof(P_ctrl_TAPM_T,
    YpositionThruster_Value_o), 37, 6, 2, 404, 0 },

  { 203,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator1/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator1_IC), 67, 1, 2, 406, 0 },

  { 204,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain1/Gain",
    offsetof(P_ctrl_TAPM_T, Gain1_Gain_i), 24, 9, 2, 408, 0 },

  { 205,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator2/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator2_IC), 67, 1, 2, 410, 0 },

  { 206,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain2/Gain",
    offsetof(P_ctrl_TAPM_T, Gain2_Gain_a), 24, 9, 2, 412, 0 },

  { 207,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator3/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator3_IC), 67, 1, 2, 414, 0 },

  { 208,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain3/Gain",
    offsetof(P_ctrl_TAPM_T, Gain3_Gain_b), 24, 9, 2, 416, 0 },

  { 209,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /K11/Gain",
    offsetof(P_ctrl_TAPM_T, K11_Gain), 24, 9, 2, 418, 0 },

  { 210,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /K12/Gain",
    offsetof(P_ctrl_TAPM_T, K12_Gain), 24, 9, 2, 420, 0 },

  { 211,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /inv(T_b)/Gain",
    offsetof(P_ctrl_TAPM_T, invT_b_Gain), 24, 9, 2, 422, 0 },

  { 212, "ctrl_tapm/TAPM Controller w_observer/PID/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_o), 67, 1, 2, 424, 0 },

  { 213, "ctrl_tapm/TAPM Controller w_observer/PID/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_d), 67, 1, 2, 426, 0 },

  { 214, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value), 67, 1, 2, 428, 0 },

  { 215, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Gain/Gain", offsetof
    (P_ctrl_TAPM_T, Gain_Gain_dl), 39, 4, 2, 430, 0 },

  { 216, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Gain1/Gain",
    offsetof(P_ctrl_TAPM_T, Gain1_Gain_ib), 39, 4, 2, 432, 0 },

  { 217, "ctrl_tapm/Input/deg2rad/Gain", offsetof(P_ctrl_TAPM_T, deg2rad_Gain),
    67, 1, 2, 434, 0 },

  { 218, "ctrl_tapm/Thruster control /Delay/InitialCondition", offsetof
    (P_ctrl_TAPM_T, Delay_InitialCondition_j), 67, 1, 2, 436, 0 },

  { 219, "ctrl_tapm/Thruster control /Thruster 1/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_cs), 38, 2, 2, 438, 0 },

  { 220, "ctrl_tapm/Thruster control /Thruster 1/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_k), 38, 2, 2, 440, 0 },

  { 221, "ctrl_tapm/Thruster control /Thruster 1/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_i), 67, 1, 2, 442, 0 },

  { 222,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_f), 67, 1, 2, 444, 0 },

  { 223,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_o), 31, 3, 2, 446, 0 },

  { 224,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value), 31, 3, 2, 448, 0 },

  { 225,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialStat), 67, 1, 2, 450, 0 },

  { 226,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt), 0, 1, 2, 452, 0 },

  { 227,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_RisingLim), 0, 1, 2, 454, 0 },

  { 228,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_FallingLim), 0, 1, 2, 456, 0 },

  { 229,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_IC), 67, 1, 2, 458, 0 },

  { 230, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0), 67, 1, 2, 460, 0 },

  { 231,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_a), 67, 1, 2, 462, 0 },

  { 232, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value), 67, 1, 2, 464, 0 },

  { 233,
    "ctrl_tapm/Thruster control /Thruster 1/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_h), 67, 1, 2, 466, 0 },

  { 234, "ctrl_tapm/Thruster control /Thruster 2/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_h), 38, 2, 2, 468, 0 },

  { 235, "ctrl_tapm/Thruster control /Thruster 2/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_j), 38, 2, 2, 470, 0 },

  { 236, "ctrl_tapm/Thruster control /Thruster 2/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_l), 67, 1, 2, 472, 0 },

  { 237,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_iv), 67, 1, 2, 474, 0 },

  { 238,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_b), 31, 3, 2, 476, 0 },

  { 239,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_i), 31, 3, 2, 478, 0 },

  { 240,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialS_hu), 67, 1, 2, 480, 0 },

  { 241,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_k), 0, 1, 2, 482, 0 },

  { 242,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_RisingLim_n), 0, 1, 2, 484, 0 },

  { 243,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_FallingLim_n), 0, 1, 2, 486, 0 },

  { 244,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_ctrl_TAPM_T, AccelerationLimit_IC_m), 67, 1, 2, 488, 0 },

  { 245, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_e), 67, 1, 2, 490, 0 },

  { 246,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_fy), 67, 1, 2, 492, 0 },

  { 247, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_l), 67, 1, 2, 494, 0 },

  { 248,
    "ctrl_tapm/Thruster control /Thruster 2/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_f), 67, 1, 2, 496, 0 },

  { 249, "ctrl_tapm/Thruster control /Thruster 3/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_n), 38, 2, 2, 498, 0 },

  { 250, "ctrl_tapm/Thruster control /Thruster 3/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_a), 38, 2, 2, 500, 0 },

  { 251, "ctrl_tapm/Thruster control /Thruster 3/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_d), 67, 1, 2, 502, 0 },

  { 252,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_h), 67, 1, 2, 504, 0 },

  { 253,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_g), 31, 3, 2, 506, 0 },

  { 254,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_h), 31, 3, 2, 508, 0 },

  { 255,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_a), 67, 1, 2, 510, 0 },

  { 256,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_m), 0, 1, 2, 512, 0 },

  { 257,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_RisingLim), 0, 1, 2, 514, 0 },

  { 258,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_FallingLim), 0, 1, 2, 516, 0 },

  { 259,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_IC), 67, 1, 2, 518, 0 },

  { 260, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_g), 67, 1, 2, 520, 0 },

  { 261,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_j), 67, 1, 2, 522, 0 },

  { 262, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_g), 67, 1, 2, 524, 0 },

  { 263,
    "ctrl_tapm/Thruster control /Thruster 3/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_c), 67, 1, 2, 526, 0 },

  { 264, "ctrl_tapm/Thruster control /Thruster 4/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_j), 38, 2, 2, 528, 0 },

  { 265, "ctrl_tapm/Thruster control /Thruster 4/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_oi), 38, 2, 2, 530, 0 },

  { 266, "ctrl_tapm/Thruster control /Thruster 4/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_fb), 67, 1, 2, 532, 0 },

  { 267,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_g), 67, 1, 2, 534, 0 },

  { 268,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_m), 31, 3, 2, 536, 0 },

  { 269,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_l), 31, 3, 2, 538, 0 },

  { 270,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialS_a1), 67, 1, 2, 540, 0 },

  { 271,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_h), 0, 1, 2, 542, 0 },

  { 272,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_RisingLim_e), 0, 1, 2, 544, 0 },

  { 273,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_FallingLi_b), 0, 1, 2, 546, 0 },

  { 274,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_IC_h), 67, 1, 2, 548, 0 },

  { 275, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_k), 67, 1, 2, 550, 0 },

  { 276,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_g), 67, 1, 2, 552, 0 },

  { 277, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_p), 67, 1, 2, 554, 0 },

  { 278,
    "ctrl_tapm/Thruster control /Thruster 4/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_p), 67, 1, 2, 556, 0 },

  { 279, "ctrl_tapm/Thruster control /Thruster 5/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_i), 38, 2, 2, 558, 0 },

  { 280, "ctrl_tapm/Thruster control /Thruster 5/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_h), 38, 2, 2, 560, 0 },

  { 281, "ctrl_tapm/Thruster control /Thruster 5/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_fv), 67, 1, 2, 562, 0 },

  { 282,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_dz), 67, 1, 2, 564, 0 },

  { 283,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_mk), 31, 3, 2, 566, 0 },

  { 284,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_p), 31, 3, 2, 568, 0 },

  { 285,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_e), 67, 1, 2, 570, 0 },

  { 286,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_o), 0, 1, 2, 572, 0 },

  { 287,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_RisingLim_b), 0, 1, 2, 574, 0 },

  { 288,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_FallingLi_d), 0, 1, 2, 576, 0 },

  { 289,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_IC_i), 67, 1, 2, 578, 0 },

  { 290, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_k3), 67, 1, 2, 580, 0 },

  { 291,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_aj), 67, 1, 2, 582, 0 },

  { 292, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_lq), 67, 1, 2, 584, 0 },

  { 293,
    "ctrl_tapm/Thruster control /Thruster 5/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialS_pj), 67, 1, 2, 586, 0 },

  { 294, "ctrl_tapm/Thruster control /Thruster 6/Constant/Value", offsetof
    (P_ctrl_TAPM_T, Constant_Value_ht), 38, 2, 2, 588, 0 },

  { 295, "ctrl_tapm/Thruster control /Thruster 6/Constant1/Value", offsetof
    (P_ctrl_TAPM_T, Constant1_Value_gs), 38, 2, 2, 590, 0 },

  { 296, "ctrl_tapm/Thruster control /Thruster 6/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_fi), 67, 1, 2, 592, 0 },

  { 297,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Delay_InitialCondition_a), 67, 1, 2, 594, 0 },

  { 298,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM_T, Constant1_Value_oa), 31, 3, 2, 596, 0 },

  { 299,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM_T, Constant2_Value_p3), 31, 3, 2, 598, 0 },

  { 300,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialS_a4), 67, 1, 2, 600, 0 },

  { 301,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM_T, TSamp_WtEt_kk), 0, 1, 2, 602, 0 },

  { 302,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_RisingLi_bi), 0, 1, 2, 604, 0 },

  { 303,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_FallingLi_p), 0, 1, 2, 606, 0 },

  { 304,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Accelerationlimiter_IC_p), 67, 1, 2, 608, 0 },

  { 305, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM_T, Memory_X0_c), 67, 1, 2, 610, 0 },

  { 306,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM_T, Integrator_IC_h), 67, 1, 2, 612, 0 },

  { 307, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM_T, NaN_Value_j), 67, 1, 2, 614, 0 },

  { 308,
    "ctrl_tapm/Thruster control /Thruster 6/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM_T, DiscreteTransferFcn_InitialSt_b), 67, 1, 2, 616, 0 },

  { 309, "ctrl_tapm/TAPM Controller w_observer/PID/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength), 68, 1, 2, 618, 0 },

  { 310, "ctrl_tapm/Thruster control /Delay/DelayLength", offsetof(P_ctrl_TAPM_T,
    Delay_DelayLength_m), 68, 1, 2, 620, 0 },

  { 311, "ctrl_tapm/Thruster control /Thruster 1/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_d), 68, 1, 2, 622, 0 },

  { 312,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_f), 68, 1, 2, 624, 0 },

  { 313, "ctrl_tapm/Thruster control /Thruster 2/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_m5), 68, 1, 2, 626, 0 },

  { 314,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_p), 68, 1, 2, 628, 0 },

  { 315, "ctrl_tapm/Thruster control /Thruster 3/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_h), 68, 1, 2, 630, 0 },

  { 316,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_b), 68, 1, 2, 632, 0 },

  { 317, "ctrl_tapm/Thruster control /Thruster 4/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_n), 68, 1, 2, 634, 0 },

  { 318,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_mj), 68, 1, 2, 636, 0 },

  { 319, "ctrl_tapm/Thruster control /Thruster 5/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_a), 68, 1, 2, 638, 0 },

  { 320,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_k), 68, 1, 2, 640, 0 },

  { 321, "ctrl_tapm/Thruster control /Thruster 6/Delay/DelayLength", offsetof
    (P_ctrl_TAPM_T, Delay_DelayLength_l), 68, 1, 2, 642, 0 },

  { 322,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, Delay_DelayLength_c), 68, 1, 2, 644, 0 },

  { 323,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Discrete-Time Integrator/gainval",
    offsetof(P_ctrl_TAPM_T, CoreSubsys.DiscreteTimeIntegrator_gainval), 0, 1, 2,
    646, 0 },

  { 324,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Degrees to Radians/Gain1/Gain",
    offsetof(P_ctrl_TAPM_T, CoreSubsys.Gain1_Gain), 67, 1, 2, 648, 0 },

  { 325,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM_T, CoreSubsys.Delay_InitialCondition), 67, 1, 2, 650, 0
  },

  { 326,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Delay/DelayLength",
    offsetof(P_ctrl_TAPM_T, CoreSubsys.Delay_DelayLength), 68, 1, 2, 652, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 327;
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
  3, 3,                                /* Parameter at index 115 */
  1, 1,                                /* Parameter at index 116 */
  1, 1,                                /* Parameter at index 117 */
  1, 1,                                /* Parameter at index 118 */
  1, 1,                                /* Parameter at index 119 */
  1, 1,                                /* Parameter at index 120 */
  1, 1,                                /* Parameter at index 121 */
  3, 3,                                /* Parameter at index 122 */
  3, 3,                                /* Parameter at index 123 */
  3, 3,                                /* Parameter at index 124 */
  1, 1,                                /* Parameter at index 125 */
  3, 1,                                /* Parameter at index 126 */
  1, 1,                                /* Parameter at index 127 */
  1, 1,                                /* Parameter at index 128 */
  1, 1,                                /* Parameter at index 129 */
  1, 1,                                /* Parameter at index 130 */
  1, 2,                                /* Parameter at index 131 */
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
  3, 1,                                /* Parameter at index 143 */
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
  1, 6,                                /* Parameter at index 154 */
  1, 6,                                /* Parameter at index 155 */
  1, 6,                                /* Parameter at index 156 */
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
  1, 1,                                /* Parameter at index 195 */
  1, 1,                                /* Parameter at index 196 */
  1, 1,                                /* Parameter at index 197 */
  1, 1,                                /* Parameter at index 198 */
  1, 1,                                /* Parameter at index 199 */
  1, 1,                                /* Parameter at index 200 */
  1, 6,                                /* Parameter at index 201 */
  1, 6,                                /* Parameter at index 202 */
  1, 1,                                /* Parameter at index 203 */
  3, 3,                                /* Parameter at index 204 */
  1, 1,                                /* Parameter at index 205 */
  3, 3,                                /* Parameter at index 206 */
  1, 1,                                /* Parameter at index 207 */
  3, 3,                                /* Parameter at index 208 */
  3, 3,                                /* Parameter at index 209 */
  3, 3,                                /* Parameter at index 210 */
  3, 3,                                /* Parameter at index 211 */
  1, 1,                                /* Parameter at index 212 */
  1, 1,                                /* Parameter at index 213 */
  1, 1,                                /* Parameter at index 214 */
  2, 2,                                /* Parameter at index 215 */
  2, 2,                                /* Parameter at index 216 */
  1, 1,                                /* Parameter at index 217 */
  1, 1,                                /* Parameter at index 218 */
  1, 2,                                /* Parameter at index 219 */
  1, 2,                                /* Parameter at index 220 */
  1, 1,                                /* Parameter at index 221 */
  1, 1,                                /* Parameter at index 222 */
  1, 3,                                /* Parameter at index 223 */
  1, 3,                                /* Parameter at index 224 */
  1, 1,                                /* Parameter at index 225 */
  1, 1,                                /* Parameter at index 226 */
  1, 1,                                /* Parameter at index 227 */
  1, 1,                                /* Parameter at index 228 */
  1, 1,                                /* Parameter at index 229 */
  1, 1,                                /* Parameter at index 230 */
  1, 1,                                /* Parameter at index 231 */
  1, 1,                                /* Parameter at index 232 */
  1, 1,                                /* Parameter at index 233 */
  1, 2,                                /* Parameter at index 234 */
  1, 2,                                /* Parameter at index 235 */
  1, 1,                                /* Parameter at index 236 */
  1, 1,                                /* Parameter at index 237 */
  1, 3,                                /* Parameter at index 238 */
  1, 3,                                /* Parameter at index 239 */
  1, 1,                                /* Parameter at index 240 */
  1, 1,                                /* Parameter at index 241 */
  1, 1,                                /* Parameter at index 242 */
  1, 1,                                /* Parameter at index 243 */
  1, 1,                                /* Parameter at index 244 */
  1, 1,                                /* Parameter at index 245 */
  1, 1,                                /* Parameter at index 246 */
  1, 1,                                /* Parameter at index 247 */
  1, 1,                                /* Parameter at index 248 */
  1, 2,                                /* Parameter at index 249 */
  1, 2,                                /* Parameter at index 250 */
  1, 1,                                /* Parameter at index 251 */
  1, 1,                                /* Parameter at index 252 */
  1, 3,                                /* Parameter at index 253 */
  1, 3,                                /* Parameter at index 254 */
  1, 1,                                /* Parameter at index 255 */
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
  1, 1,                                /* Parameter at index 309 */
  1, 1,                                /* Parameter at index 310 */
  1, 1,                                /* Parameter at index 311 */
  1, 1,                                /* Parameter at index 312 */
  1, 1,                                /* Parameter at index 313 */
  1, 1,                                /* Parameter at index 314 */
  1, 1,                                /* Parameter at index 315 */
  1, 1,                                /* Parameter at index 316 */
  1, 1,                                /* Parameter at index 317 */
  1, 1,                                /* Parameter at index 318 */
  1, 1,                                /* Parameter at index 319 */
  1, 1,                                /* Parameter at index 320 */
  1, 1,                                /* Parameter at index 321 */
  1, 1,                                /* Parameter at index 322 */
  1, 1,                                /* Parameter at index 323 */
  1, 1,                                /* Parameter at index 324 */
  1, 1,                                /* Parameter at index 325 */
  1, 1,                                /* Parameter at index 326 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_tapm/TAPM Controller w_observer/PID/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_tapm/Input/wave_dir", 0, "", offsetof(B_ctrl_TAPM_T, wave_dir) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_tapm/Input/fzp_x", 0, "", offsetof(B_ctrl_TAPM_T, fzp_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "ctrl_tapm/Input/fzp_y", 0, "", offsetof(B_ctrl_TAPM_T, fzp_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "ctrl_tapm/Input/r_max", 0, "", offsetof(B_ctrl_TAPM_T, r_max) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "ctrl_tapm/Input/Core_controller", 0, "", offsetof(B_ctrl_TAPM_T,
    Core_controller) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "ctrl_tapm/Input/K_i_y", 0, "", offsetof(B_ctrl_TAPM_T, K_i_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "ctrl_tapm/Input/K_d_psi", 0, "", offsetof(B_ctrl_TAPM_T, K_d_psi) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "ctrl_tapm/Input/K_d_x", 0, "", offsetof(B_ctrl_TAPM_T, K_d_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "ctrl_tapm/Input/K_d_y", 0, "", offsetof(B_ctrl_TAPM_T, K_d_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_tapm/Input/K_i_psi", 0, "", offsetof(B_ctrl_TAPM_T, K_i_psi) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_tapm/Input/K_i_x", 0, "", offsetof(B_ctrl_TAPM_T, K_i_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_tapm/Input/K_p_psi", 0, "", offsetof(B_ctrl_TAPM_T, K_p_psi) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_tapm/Input/K_p_x", 0, "", offsetof(B_ctrl_TAPM_T, K_p_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "ctrl_tapm/Input/K_p_y", 0, "", offsetof(B_ctrl_TAPM_T, K_p_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "ctrl_tapm/Input/K_d_psi1", 0, "", offsetof(B_ctrl_TAPM_T, K_d_psi1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "ctrl_tapm/Input/K_d_x1", 0, "", offsetof(B_ctrl_TAPM_T, K_d_x1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "ctrl_tapm/Input/K_d_y1", 0, "", offsetof(B_ctrl_TAPM_T, K_d_y1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 18, "ctrl_tapm/Input/K_i_psi1", 0, "", offsetof(B_ctrl_TAPM_T, K_i_psi1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 19, "ctrl_tapm/Input/K_i_x1", 0, "", offsetof(B_ctrl_TAPM_T, K_i_x1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "ctrl_tapm/Input/K_i_y1", 0, "", offsetof(B_ctrl_TAPM_T, K_i_y1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "ctrl_tapm/Input/K_p_psi1", 0, "", offsetof(B_ctrl_TAPM_T, K_p_psi1) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "ctrl_tapm/Input/K_p_x1", 0, "", offsetof(B_ctrl_TAPM_T, K_p_x1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 23, "ctrl_tapm/Input/K_p_y1", 0, "", offsetof(B_ctrl_TAPM_T, K_p_y1) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 24,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator",
    0, "eta(1, 1)", offsetof(B_ctrl_TAPM_T, eta) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 25,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator",
    0, "eta(1, 2)", offsetof(B_ctrl_TAPM_T, eta) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 26,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator",
    0, "eta(1, 3)", offsetof(B_ctrl_TAPM_T, eta) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 27,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator4",
    0, "nu(1, 1)", offsetof(B_ctrl_TAPM_T, nu) + (0*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 28,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator4",
    0, "nu(2, 1)", offsetof(B_ctrl_TAPM_T, nu) + (1*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 29,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Integrator4",
    0, "nu(3, 1)", offsetof(B_ctrl_TAPM_T, nu) + (2*sizeof(real_T)), BLOCKIO_SIG,
    26, 1, 2, 0, 0 },

  { 30, "ctrl_tapm/TAPM Controller w_observer/PID/Multiport Switch/(1, 1)", 0,
    "", offsetof(B_ctrl_TAPM_T, MultiportSwitch) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 31, "ctrl_tapm/TAPM Controller w_observer/PID/Multiport Switch/(2, 1)", 0,
    "", offsetof(B_ctrl_TAPM_T, MultiportSwitch) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 32, "ctrl_tapm/TAPM Controller w_observer/PID/Multiport Switch/(3, 1)", 0,
    "", offsetof(B_ctrl_TAPM_T, MultiportSwitch) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 33, "ctrl_tapm/Thruster measurment/thr_angle_1", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 34, "ctrl_tapm/Thruster measurment/thr_angle_2", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 35, "ctrl_tapm/Thruster measurment/thr_angle_3", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 36, "ctrl_tapm/Thruster measurment/thr_angle_4", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 37, "ctrl_tapm/Thruster measurment/thr_angle_5", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 38, "ctrl_tapm/Thruster measurment/thr_angle_6", 0, "", offsetof
    (B_ctrl_TAPM_T, thr_angle_6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 39, "ctrl_tapm/Thrust allocation/reset/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 40, "ctrl_tapm/Thrust allocation/reset/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 41, "ctrl_tapm/Thrust allocation/reset/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 42, "ctrl_tapm/Thrust allocation/reset/(1, 4)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset) + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 43, "ctrl_tapm/Thrust allocation/reset/(1, 5)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset) + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 44, "ctrl_tapm/Thrust allocation/reset/(1, 6)", 0, "", offsetof
    (B_ctrl_TAPM_T, reset) + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 45, "ctrl_tapm/Thrust allocation/Angle_controller", 0, "", offsetof
    (B_ctrl_TAPM_T, Angle_controller) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 46, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 1)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 47, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 2)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 48, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 3)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 49, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 4)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 50, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 5)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 51, "ctrl_tapm/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 6)", 0,
    "", offsetof(B_ctrl_TAPM_T, ChoosingFixedAzimuthangle) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 52, "ctrl_tapm/Thruster control /Subsystem1/Saturation 1", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 53, "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 54, "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 55, "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 56, "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 57, "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 58, "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 59, "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/rpm1",
    0, "", offsetof(B_ctrl_TAPM_T, rpm1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 60, "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/rpm2",
    0, "", offsetof(B_ctrl_TAPM_T, rpm2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 61, "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/rpm3",
    0, "", offsetof(B_ctrl_TAPM_T, rpm3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 62, "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/rpm4",
    0, "", offsetof(B_ctrl_TAPM_T, rpm4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 63, "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/rpm5",
    0, "", offsetof(B_ctrl_TAPM_T, rpm5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 64, "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/rpm6",
    0, "", offsetof(B_ctrl_TAPM_T, rpm6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 65, "ctrl_tapm/Thruster control /Subsystem1/Saturation 2", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 66, "ctrl_tapm/Thruster control /Subsystem1/Saturation 3", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 67, "ctrl_tapm/Thruster control /Subsystem1/Saturation 4", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 68, "ctrl_tapm/Thruster control /Subsystem1/Saturation 5", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 69, "ctrl_tapm/Thruster control /Subsystem1/Saturation 6", 0, "", offsetof
    (B_ctrl_TAPM_T, Saturation6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 70,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Saturation7) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 71,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 2)",
    0, "", offsetof(B_ctrl_TAPM_T, Saturation7) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 72,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 3)",
    0, "", offsetof(B_ctrl_TAPM_T, Saturation7) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 73,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 4)",
    0, "", offsetof(B_ctrl_TAPM_T, Saturation7) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 74,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 5)",
    0, "", offsetof(B_ctrl_TAPM_T, Saturation7) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 75,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/(1, 6)",
    0, "", offsetof(B_ctrl_TAPM_T, Saturation7) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 76, "ctrl_tapm/Radians to Degrees/Gain/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 77, "ctrl_tapm/Radians to Degrees/Gain/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 78, "ctrl_tapm/Radians to Degrees/Gain/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 79, "ctrl_tapm/Radians to Degrees/Gain/(1, 4)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 80, "ctrl_tapm/Radians to Degrees/Gain/(1, 5)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 81, "ctrl_tapm/Radians to Degrees/Gain/(1, 6)", 0, "", offsetof
    (B_ctrl_TAPM_T, Gain) + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 82, "ctrl_tapm/Pos measurements/x_m", 0, "", offsetof(B_ctrl_TAPM_T, x_m) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 83, "ctrl_tapm/Pos measurements/y_m", 0, "", offsetof(B_ctrl_TAPM_T, y_m) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 84, "ctrl_tapm/Pos measurements/psi_m", 0, "", offsetof(B_ctrl_TAPM_T, psi_m)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 85,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain3/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Gain3) + (0*sizeof(real_T)), BLOCKIO_SIG, 26,
    1, 2, 0, 0 },

  { 86,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain3/(2, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Gain3) + (1*sizeof(real_T)), BLOCKIO_SIG, 26,
    1, 2, 0, 0 },

  { 87,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Gain3/(3, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Gain3) + (2*sizeof(real_T)), BLOCKIO_SIG, 26,
    1, 2, 0, 0 },

  { 88,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum3/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum3) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 89,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum3/(1, 2)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum3) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 90,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum3/(1, 3)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum3) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 91, "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum5",
    0, "psi_WF(1, 1)", offsetof(B_ctrl_TAPM_T, psi_WF) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 92, "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum5",
    0, "psi_WF(2, 1)", offsetof(B_ctrl_TAPM_T, psi_WF) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 93, "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum5",
    0, "psi_WF(3, 1)", offsetof(B_ctrl_TAPM_T, psi_WF) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 26, 1, 2, 0, 0 },

  { 94,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum6/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum6) + (0*sizeof(real_T)), BLOCKIO_SIG, 26,
    1, 2, 0, 0 },

  { 95,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum6/(2, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum6) + (1*sizeof(real_T)), BLOCKIO_SIG, 26,
    1, 2, 0, 0 },

  { 96,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum6/(3, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum6) + (2*sizeof(real_T)), BLOCKIO_SIG, 26,
    1, 2, 0, 0 },

  { 97,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum7/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum7) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 98,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum7/(1, 2)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum7) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 99,
    "ctrl_tapm/TAPM Controller w_observer/Non-linear passive observer /Sum7/(1, 3)",
    0, "", offsetof(B_ctrl_TAPM_T, Sum7) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 100, "ctrl_tapm/TAPM Controller w_observer/PID/Integrator", 0, "", offsetof
    (B_ctrl_TAPM_T, Integrator) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 101, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 102, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Sum1/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0,
    0 },

  { 103, "ctrl_tapm/TAPM Controller w_observer/SP Generator/Sum1/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1) + (1*sizeof(real_T)), BLOCKIO_SIG, 25, 1, 2, 0,
    0 },

  { 104, "ctrl_tapm/Thruster control /Delay/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 105, "ctrl_tapm/Thruster control /Delay/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_n) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 106, "ctrl_tapm/Thruster control /Delay/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_n) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 107, "ctrl_tapm/Thruster control /Delay/(1, 4)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_n) + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 108, "ctrl_tapm/Thruster control /Delay/(1, 5)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_n) + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 109, "ctrl_tapm/Thruster control /Delay/(1, 6)", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_n) + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 110, "ctrl_tapm/Thruster control /Thruster 1/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 111, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 112,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 113,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 114,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 115, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 116, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 117,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 118,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_kk) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 119, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 120, "ctrl_tapm/Thruster control /Thruster 1/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 121,
    "ctrl_tapm/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 122,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 123, "ctrl_tapm/Thruster control /Thruster 2/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 124, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_bs) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 125,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 126,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 127,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 128, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_nn) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 129, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 130,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 131,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_e) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 132, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 133, "ctrl_tapm/Thruster control /Thruster 2/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 134,
    "ctrl_tapm/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 135,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 136, "ctrl_tapm/Thruster control /Thruster 3/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 137, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_by) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 138,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 139,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 140,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 141, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 142, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 143,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 144,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_j2) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 145, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_hf) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 146, "ctrl_tapm/Thruster control /Thruster 3/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 147,
    "ctrl_tapm/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 148,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 149, "ctrl_tapm/Thruster control /Thruster 4/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_g) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 150, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 151,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 152,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 153,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 154, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 155, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 156,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 157,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 158, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_k2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 159, "ctrl_tapm/Thruster control /Thruster 4/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 160,
    "ctrl_tapm/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_ms) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 161,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 162, "ctrl_tapm/Thruster control /Thruster 5/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_a5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 163, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_id) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 164,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 165,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_m) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 166,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 167, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 168, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 169,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 170,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 171, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 172, "ctrl_tapm/Thruster control /Thruster 5/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_lz) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 173,
    "ctrl_tapm/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_ag) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 174,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 175, "ctrl_tapm/Thruster control /Thruster 6/Delay", 0, "", offsetof
    (B_ctrl_TAPM_T, Delay_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 176, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Delay", 0, "",
    offsetof(B_ctrl_TAPM_T, Delay_il) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 177,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 178,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM_T, TSamp_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 179,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM_T, Inertiacompensation_e3) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 180, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum1_io) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 181, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM_T, Memory_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 182,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM_T, Kp_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 183,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM_T, reset_om) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 184, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM_T, Sum_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 185, "ctrl_tapm/Thruster control /Thruster 6/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM_T, DiscreteTransferFcn_ea) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 186,
    "ctrl_tapm/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM_T, Findingrotationspeed_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 187,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM_T, Ki_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 188,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, n_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 189,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, n_d_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 190,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, n_d_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 191,
    "ctrl_tapm/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, Qa) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 192,
    "ctrl_tapm/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    2, "", offsetof(B_ctrl_TAPM_T, Pa) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 193,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function1",
    0, "", offsetof(B_ctrl_TAPM_T, Tc_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 194,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 1)", offsetof(B_ctrl_TAPM_T, output) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 28, 1, 2, 0, 0 },

  { 195,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 2)", offsetof(B_ctrl_TAPM_T, output) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 28, 1, 2, 0, 0 },

  { 196,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 3)", offsetof(B_ctrl_TAPM_T, output) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 28, 1, 2, 0, 0 },

  { 197,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 4)", offsetof(B_ctrl_TAPM_T, output) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 28, 1, 2, 0, 0 },

  { 198,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 5)", offsetof(B_ctrl_TAPM_T, output) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 28, 1, 2, 0, 0 },

  { 199,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 6)", offsetof(B_ctrl_TAPM_T, output) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 28, 1, 2, 0, 0 },

  { 200,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 7)", offsetof(B_ctrl_TAPM_T, output) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 28, 1, 2, 0, 0 },

  { 201,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 8)", offsetof(B_ctrl_TAPM_T, output) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 28, 1, 2, 0, 0 },

  { 202,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 9)", offsetof(B_ctrl_TAPM_T, output) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 28, 1, 2, 0, 0 },

  { 203,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 10)", offsetof(B_ctrl_TAPM_T, output) + (9*sizeof(real_T)),
    BLOCKIO_SIG, 28, 1, 2, 0, 0 },

  { 204,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 11)", offsetof(B_ctrl_TAPM_T, output) + (10*sizeof(real_T)),
    BLOCKIO_SIG, 28, 1, 2, 0, 0 },

  { 205,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 12)", offsetof(B_ctrl_TAPM_T, output) + (11*sizeof(real_T)),
    BLOCKIO_SIG, 28, 1, 2, 0, 0 },

  { 206, "ctrl_tapm/TAPM Controller w_observer/PID/MATLAB Function", 0, "",
    offsetof(B_ctrl_TAPM_T, reset_n0) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 207, "ctrl_tapm/TAPM Controller w_observer/PID/MATLAB Function", 1, "",
    offsetof(B_ctrl_TAPM_T, y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 208, "ctrl_tapm/Finding commanded forces in: [Surge,Sway,Yaw]", 0, "(1, 1)",
    offsetof(B_ctrl_TAPM_T, commanded_tau) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 209, "ctrl_tapm/Finding commanded forces in: [Surge,Sway,Yaw]", 0, "(1, 2)",
    offsetof(B_ctrl_TAPM_T, commanded_tau) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 210, "ctrl_tapm/Finding commanded forces in: [Surge,Sway,Yaw]", 0, "(1, 3)",
    offsetof(B_ctrl_TAPM_T, commanded_tau) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 211, "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_e.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 212,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_nf.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 213,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_nf.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 214,
    "ctrl_tapm/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_nf.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 215,
    "ctrl_tapm/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_j.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 216,
    "ctrl_tapm/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_j.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 217, "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_b.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 218,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_j.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 219,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/MATLAB Function", 1,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_j.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 220,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_h.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 221,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_h.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 222,
    "ctrl_tapm/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_h.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 223,
    "ctrl_tapm/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_o.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 224,
    "ctrl_tapm/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_o.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 225, "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_n.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 226,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_go.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 227,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/MATLAB Function", 1,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_go.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 228,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_n3.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 229,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_n3.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 230,
    "ctrl_tapm/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePower_n3.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 231,
    "ctrl_tapm/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_m.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 232,
    "ctrl_tapm/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_m.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 233, "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_l.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 234,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_n.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 235,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_n.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 236,
    "ctrl_tapm/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_n.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 237,
    "ctrl_tapm/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_h.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 238,
    "ctrl_tapm/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_h.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 239, "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor_h.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 240,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/MATLAB Function", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_i.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 241,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/MATLAB Function", 1,
    "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction_i.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 242,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_o.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 243,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_o.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 244,
    "ctrl_tapm/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowera_o.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 245,
    "ctrl_tapm/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_f.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 246,
    "ctrl_tapm/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM_T, sf_ActualForceandTorque_f.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 247, "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Supervisor", 0,
    "", offsetof(B_ctrl_TAPM_T, sf_Supervisor.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 248,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowerand.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 249,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowerand.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 250,
    "ctrl_tapm/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM_T, sf_CorecontrollerTorquePowerand.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 251,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function6",
    0, "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction6_k.Tc_out) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 252,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function5",
    0, "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction5_h.Tc_out) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 253,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function4",
    0, "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction4_b.Tc_out) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 254,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function3",
    0, "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction3_p.Tc_out) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 255,
    "ctrl_tapm/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function2",
    0, "", offsetof(B_ctrl_TAPM_T, sf_MATLABFunction2_i.Tc_out) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 256,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Discrete-Time Integrator",
    0, "angle", offsetof(B_ctrl_TAPM_T, CoreSubsys[5].angle) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 257,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Delay",
    0, "", offsetof(B_ctrl_TAPM_T, CoreSubsys[5].Delay) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 258,
    "ctrl_tapm/Thrust allocation/Optimal angle path and  constraints on rotation speed/Max Rotation Rate",
    0, "", offsetof(B_ctrl_TAPM_T, CoreSubsys[5].MaxRotationRate) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 259, "ctrl_tapm/Input/MATLAB Function6", 0, "(1, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction6.K_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 260, "ctrl_tapm/Input/MATLAB Function6", 0, "(2, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction6.K_d) + (1*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 261, "ctrl_tapm/Input/MATLAB Function6", 0, "(3, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction6.K_d) + (2*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 262, "ctrl_tapm/Input/MATLAB Function6", 0, "(1, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction6.K_d) + (3*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 263, "ctrl_tapm/Input/MATLAB Function6", 0, "(2, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction6.K_d) + (4*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 264, "ctrl_tapm/Input/MATLAB Function6", 0, "(3, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction6.K_d) + (5*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 265, "ctrl_tapm/Input/MATLAB Function6", 0, "(1, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction6.K_d) + (6*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 266, "ctrl_tapm/Input/MATLAB Function6", 0, "(2, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction6.K_d) + (7*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 267, "ctrl_tapm/Input/MATLAB Function6", 0, "(3, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction6.K_d) + (8*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 268, "ctrl_tapm/Input/MATLAB Function5", 0, "(1, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction5.K_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 269, "ctrl_tapm/Input/MATLAB Function5", 0, "(2, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction5.K_i) + (1*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 270, "ctrl_tapm/Input/MATLAB Function5", 0, "(3, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction5.K_i) + (2*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 271, "ctrl_tapm/Input/MATLAB Function5", 0, "(1, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction5.K_i) + (3*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 272, "ctrl_tapm/Input/MATLAB Function5", 0, "(2, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction5.K_i) + (4*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 273, "ctrl_tapm/Input/MATLAB Function5", 0, "(3, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction5.K_i) + (5*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 274, "ctrl_tapm/Input/MATLAB Function5", 0, "(1, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction5.K_i) + (6*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 275, "ctrl_tapm/Input/MATLAB Function5", 0, "(2, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction5.K_i) + (7*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 276, "ctrl_tapm/Input/MATLAB Function5", 0, "(3, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction5.K_i) + (8*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 277, "ctrl_tapm/Input/MATLAB Function4", 0, "(1, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction4.K_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 278, "ctrl_tapm/Input/MATLAB Function4", 0, "(2, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction4.K_p) + (1*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 279, "ctrl_tapm/Input/MATLAB Function4", 0, "(3, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction4.K_p) + (2*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 280, "ctrl_tapm/Input/MATLAB Function4", 0, "(1, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction4.K_p) + (3*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 281, "ctrl_tapm/Input/MATLAB Function4", 0, "(2, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction4.K_p) + (4*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 282, "ctrl_tapm/Input/MATLAB Function4", 0, "(3, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction4.K_p) + (5*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 283, "ctrl_tapm/Input/MATLAB Function4", 0, "(1, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction4.K_p) + (6*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 284, "ctrl_tapm/Input/MATLAB Function4", 0, "(2, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction4.K_p) + (7*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 285, "ctrl_tapm/Input/MATLAB Function4", 0, "(3, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction4.K_p) + (8*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 286, "ctrl_tapm/Input/MATLAB Function2", 0, "(1, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction2.K_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 287, "ctrl_tapm/Input/MATLAB Function2", 0, "(2, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction2.K_d) + (1*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 288, "ctrl_tapm/Input/MATLAB Function2", 0, "(3, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction2.K_d) + (2*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 289, "ctrl_tapm/Input/MATLAB Function2", 0, "(1, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction2.K_d) + (3*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 290, "ctrl_tapm/Input/MATLAB Function2", 0, "(2, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction2.K_d) + (4*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 291, "ctrl_tapm/Input/MATLAB Function2", 0, "(3, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction2.K_d) + (5*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 292, "ctrl_tapm/Input/MATLAB Function2", 0, "(1, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction2.K_d) + (6*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 293, "ctrl_tapm/Input/MATLAB Function2", 0, "(2, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction2.K_d) + (7*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 294, "ctrl_tapm/Input/MATLAB Function2", 0, "(3, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction2.K_d) + (8*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 295, "ctrl_tapm/Input/MATLAB Function1", 0, "(1, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction1.K_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 296, "ctrl_tapm/Input/MATLAB Function1", 0, "(2, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction1.K_i) + (1*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 297, "ctrl_tapm/Input/MATLAB Function1", 0, "(3, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction1.K_i) + (2*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 298, "ctrl_tapm/Input/MATLAB Function1", 0, "(1, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction1.K_i) + (3*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 299, "ctrl_tapm/Input/MATLAB Function1", 0, "(2, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction1.K_i) + (4*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 300, "ctrl_tapm/Input/MATLAB Function1", 0, "(3, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction1.K_i) + (5*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 301, "ctrl_tapm/Input/MATLAB Function1", 0, "(1, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction1.K_i) + (6*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 302, "ctrl_tapm/Input/MATLAB Function1", 0, "(2, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction1.K_i) + (7*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 303, "ctrl_tapm/Input/MATLAB Function1", 0, "(3, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction1.K_i) + (8*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 304, "ctrl_tapm/Input/MATLAB Function", 0, "(1, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction_f.K_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 305, "ctrl_tapm/Input/MATLAB Function", 0, "(2, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction_f.K_p) + (1*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 306, "ctrl_tapm/Input/MATLAB Function", 0, "(3, 1)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction_f.K_p) + (2*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 307, "ctrl_tapm/Input/MATLAB Function", 0, "(1, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction_f.K_p) + (3*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 308, "ctrl_tapm/Input/MATLAB Function", 0, "(2, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction_f.K_p) + (4*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 309, "ctrl_tapm/Input/MATLAB Function", 0, "(3, 2)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction_f.K_p) + (5*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 310, "ctrl_tapm/Input/MATLAB Function", 0, "(1, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction_f.K_p) + (6*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 311, "ctrl_tapm/Input/MATLAB Function", 0, "(2, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction_f.K_p) + (7*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 312, "ctrl_tapm/Input/MATLAB Function", 0, "(3, 3)", offsetof(B_ctrl_TAPM_T,
    sf_MATLABFunction_f.K_p) + (8*sizeof(real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 313;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 78;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Input/wave_dir", 0, EXT_IN, 1, 1, 1 },

  { 2, "Input/fzp_x", 0, EXT_IN, 1, 1, 1 },

  { 3, "Input/fzp_y", 0, EXT_IN, 1, 1, 1 },

  { 4, "Input/r_max", 0, EXT_IN, 1, 1, 1 },

  { 5, "Input/Core_controller", 0, EXT_IN, 1, 1, 1 },

  { 6, "Input/K_i_y", 0, EXT_IN, 1, 1, 1 },

  { 7, "Input/K_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 8, "Input/K_d_x", 0, EXT_IN, 1, 1, 1 },

  { 9, "Input/K_d_y", 0, EXT_IN, 1, 1, 1 },

  { 10, "Input/K_i_psi", 0, EXT_IN, 1, 1, 1 },

  { 11, "Input/K_i_x", 0, EXT_IN, 1, 1, 1 },

  { 12, "Input/K_p_psi", 0, EXT_IN, 1, 1, 1 },

  { 13, "Input/K_p_x", 0, EXT_IN, 1, 1, 1 },

  { 14, "Input/K_p_y", 0, EXT_IN, 1, 1, 1 },

  { 15, "Input/K_d_psi1", 0, EXT_IN, 1, 1, 1 },

  { 16, "Input/K_d_x1", 0, EXT_IN, 1, 1, 1 },

  { 17, "Input/K_d_y1", 0, EXT_IN, 1, 1, 1 },

  { 18, "Input/K_i_psi1", 0, EXT_IN, 1, 1, 1 },

  { 19, "Input/K_i_x1", 0, EXT_IN, 1, 1, 1 },

  { 20, "Input/K_i_y1", 0, EXT_IN, 1, 1, 1 },

  { 21, "Input/K_p_psi1", 0, EXT_IN, 1, 1, 1 },

  { 22, "Input/K_p_x1", 0, EXT_IN, 1, 1, 1 },

  { 23, "Input/K_p_y1", 0, EXT_IN, 1, 1, 1 },

  { 24, "Thruster measurment/thr_angle_1", 0, EXT_IN, 1, 1, 1 },

  { 25, "Thruster measurment/thr_angle_2", 0, EXT_IN, 1, 1, 1 },

  { 26, "Thruster measurment/thr_angle_3", 0, EXT_IN, 1, 1, 1 },

  { 27, "Thruster measurment/thr_angle_4", 0, EXT_IN, 1, 1, 1 },

  { 28, "Thruster measurment/thr_angle_5", 0, EXT_IN, 1, 1, 1 },

  { 29, "Thruster measurment/thr_angle_6", 0, EXT_IN, 1, 1, 1 },

  { 30, "Thrust allocation/reset", 1, EXT_IN, 6, 6, 1 },

  { 31, "Thrust allocation/Angle_controller", 0, EXT_IN, 1, 1, 1 },

  { 32, "Thruster control /Thruster 1/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 33, "Thruster control /Thruster 2/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 34, "Thruster control /Thruster 3/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 35, "Thruster control /Thruster 4/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 36, "Thruster control /Thruster 5/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 37, "Thruster control /Thruster 6/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1
  },

  { 38, "Thruster control /Thrust and Shaft speed mapped to PWM/rpm1 ", 0,
    EXT_IN, 1, 1, 1 },

  { 39, "Thruster control /Thrust and Shaft speed mapped to PWM/rpm2", 0, EXT_IN,
    1, 1, 1 },

  { 40, "Thruster control /Thrust and Shaft speed mapped to PWM/rpm3", 0, EXT_IN,
    1, 1, 1 },

  { 41, "Thruster control /Thrust and Shaft speed mapped to PWM/rpm4", 0, EXT_IN,
    1, 1, 1 },

  { 42, "Thruster control /Thrust and Shaft speed mapped to PWM/rpm5", 0, EXT_IN,
    1, 1, 1 },

  { 43, "Thruster control /Thrust and Shaft speed mapped to PWM/rpm6", 0, EXT_IN,
    1, 1, 1 },

  { 44, "Pos measurements/x_m", 0, EXT_IN, 1, 1, 1 },

  { 45, "Pos measurements/y_m", 0, EXT_IN, 1, 1, 1 },

  { 46, "Pos measurements/psi_m", 0, EXT_IN, 1, 1, 1 },

  { 47, "Thruster control /Thruster 1/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 48, "Thruster control /Thruster 2/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 49, "Thruster control /Thruster 3/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 50, "Thruster control /Thruster 4/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 51, "Thruster control /Thruster 5/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 52, "Thruster control /Thruster 6/Thruster control/Core controller/reset", 0,
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

  { 24, "TAPM Controller w_observer/PID/controller", 0, EXT_OUT, 1, 1, 1 },

  { 25, "TAPM Controller w_observer/PID/timer", 1, EXT_OUT, 1, 1, 1 },

  { 26, "Thruster control /Thruster 1/Propeller Hydrodynamics/Control_test_Pa",
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
static const char* NI_CompiledModelVersion = "1.145";
static const char* NI_CompiledModelDateTime = "Fri Jul 08 20:12:54 2016";
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
      *numContStates = 37;
      *numDiscStates = 966.0;
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
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_l),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_l),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.TransferFcn2_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "TransferFcn2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_g),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_g),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_g),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator4_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator4_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator4_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_k),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_k");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_k),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_k");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_k),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_k");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_c),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_p),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_p");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_km),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_km");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_n),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_n");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_cd),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_cd");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_h),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_h");
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
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator3_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator3_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator3_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_d),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_d");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_e),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_gg),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_gg");
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
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states, 0, 25, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states, 1, 25, 0);
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
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_h, 0, 25, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_h, 1, 25, 0);
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
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_j, 0, 25, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_j, 1, 25, 0);
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
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_i, 0, 25, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_i, 1, 25, 0);
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
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb, 0, 25, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb, 1, 25, 0);
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
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_l, 0, 25, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.DiscreteTransferFcn_states_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.DiscreteTransferFcn_states_l, 1, 25, 0);
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
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM_DW.Core_controller_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM_DW.Core_controller_DWORK1");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_psi1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_psi1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_x1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_x1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_y1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_y1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_psi1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_psi1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_x1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_x1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_y1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_y1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_psi1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_psi1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_x1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_x1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_y1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_y1_DWORK1");
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
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.wave_dir_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.fzp_x_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.fzp_x_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.fzp_y_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.fzp_y_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.r_max_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.r_max_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Core_controller_DWORK2, count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Core_controller_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_y_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_y_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_psi_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_psi_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_x_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_x_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_y_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_y_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_psi_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_psi_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_x_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_x_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_psi_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_psi_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_x_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_x_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_y_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_y_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_psi1_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_psi1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_x1_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_x1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_d_y1_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_d_y1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_psi1_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_psi1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_x1_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_x1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_i_y1_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_i_y1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_psi1_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_psi1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_x1_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_x1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.K_p_y1_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.K_p_y1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_1_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_2_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_3_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_4_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_5_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.thr_angle_6_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.thr_angle_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Angle_controller_DWORK2, count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Angle_controller_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_1_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_j,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_j");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_o,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_o");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_i,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_i");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_k,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_k");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_a,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_a");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_m,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_m");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm1_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm2_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm3_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm4_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm5_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.rpm6_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.rpm6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_2_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_3_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_4_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_5_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_2_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_6_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_3_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_4_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_5_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.alpha_6_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_1_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_4_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_4_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_5_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_5_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_6_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_6_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_2_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_2_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.u_3_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.u_3_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.pwm_1_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.pwm_1_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_actual_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.x_m_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.x_m_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.y_m_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.y_m_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.psi_m_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.eta_est_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.eta_est_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.nu_est_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.nu_est_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.SP_DWORK2, count,
        23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.SP_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.tau_des_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.tau_des_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.controller_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.controller_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.timer_DWORK2,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.timer_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_n,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_n");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM_DW.Control_test_Pa_DWORK2, count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM_DW.Control_test_Pa_DWORK2");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_e,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_e");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_l,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_l");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_mb,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_mb");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_nu,
        count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM_DW.reset_DWORK2_nu");
    }

    for (count = 0; count < 10; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_f,
        count, 23, 0);
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
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_l), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_l), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.TransferFcn2_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_g), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_g), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_g), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator4_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator4_CSTATE), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator4_CSTATE), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_k), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_k), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_k), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_c), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_p), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_km), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_n), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_cd), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_h), 0,
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
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator3_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator3_CSTATE), 1, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator3_CSTATE), 2, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_d), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_e), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM_X.Integrator_CSTATE_gg), 0,
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
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states, 1,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_b, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_d, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_h, 0,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_h, 1,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_n, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_n, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_no, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_j, 0,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_j, 1,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_i, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_e, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_id, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_i, 0,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_i, 1,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_n4, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_h0, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_j, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_a, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb, 0,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_hb, 1,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.UD_DSTATE_m, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_dt, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_dv, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Delay_DSTATE_m, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_l, 0,
      discStates[idx++], 25, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.DiscreteTransferFcn_states_l, 1,
      discStates[idx++], 25, 0);
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
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Core_controller_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_psi1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_x1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_y1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_psi1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_x1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_y1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_psi1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_x1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_y1_DWORK1, 0, discStates[idx++], 0,
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
    NIRT_SetValueByDataType(&ctrl_TAPM_DW.Control_test_Pa_DWORK1, 0,
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
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.fzp_x_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.fzp_y_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.r_max_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Core_controller_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_y_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_psi_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_x_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_y_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_psi_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_x_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_psi_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_x_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_y_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_psi1_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_x1_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_d_y1_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_psi1_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_x1_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_i_y1_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_psi1_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_x1_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.K_p_y1_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_1_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_2_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_3_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_4_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_5_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.thr_angle_6_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Angle_controller_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_1_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_j, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_o, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_i, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_k, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_a, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_m, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm1_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm2_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm3_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm4_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm5_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.rpm6_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_2_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_3_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_4_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_5_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_2_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_6_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_3_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_4_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_5_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.alpha_6_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_1_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_4_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_5_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_6_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_2_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.u_3_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.pwm_1_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_actual_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.x_m_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.y_m_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.psi_m_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.eta_est_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.nu_est_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.SP_DWORK2, count, discStates[idx++],
        23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.tau_des_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.controller_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.timer_DWORK2, count, discStates[idx
        ++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_n, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.Control_test_Pa_DWORK2, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_e, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_l, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_mb, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_nu, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 10; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM_DW.reset_DWORK2_f, count,
        discStates[idx++], 23, 0);
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
