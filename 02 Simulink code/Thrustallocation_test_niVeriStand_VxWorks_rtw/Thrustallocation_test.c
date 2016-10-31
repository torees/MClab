/*
 * Thrustallocation_test.c
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

/* Block signals (auto storage) */
B_Thrustallocation_test_T Thrustallocation_test_B;

/* Continuous states */
X_Thrustallocation_test_T Thrustallocation_test_X;

/* Block states (auto storage) */
DW_Thrustallocation_test_T Thrustallocation_test_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Thrustallocation_test_T Thrustallocation_test_PrevZCX;

/* Real-time model */
RT_MODEL_Thrustallocation_tes_T Thrustallocation_test_M_;
RT_MODEL_Thrustallocation_tes_T *const Thrustallocation_test_M =
  &Thrustallocation_test_M_;

/* Forward declaration for local functions */
static real_T Thrustallocation_test_eml_xnrm2(int32_T n, const real_T x[36],
  int32_T ix0);
static real_T Thrustallocation_te_eml_xnrm2_b(int32_T n, const real_T x[12],
  int32_T ix0);
static void Thrustallocation_t_eml_xaxpy_mr(int32_T n, real_T a, const real_T x
  [3], int32_T ix0, real_T y[36], int32_T iy0);
static void Thrustallocation_te_eml_xaxpy_m(int32_T n, real_T a, const real_T x
  [36], int32_T ix0, real_T y[3], int32_T iy0);
static void Thrustallocation_test_eml_xscal(real_T a, real_T x[9], int32_T ix0);
static void Thrustallocation_te_eml_xscal_k(real_T a, real_T x[144], int32_T ix0);
static void Thrustallocation_test_eml_xswap(real_T x[144], int32_T ix0, int32_T
  iy0);
static void Thrustallocation_te_eml_xswap_o(real_T x[9], int32_T ix0, int32_T
  iy0);
static void Thrustallocation_test_eml_xrotg(real_T *a, real_T *b, real_T *c,
  real_T *s);
static void Thrustallocation_test_eml_xrot(real_T x[144], int32_T ix0, int32_T
  iy0, real_T c, real_T s);
static void Thrustallocation_tes_eml_xrot_j(real_T x[9], int32_T ix0, int32_T
  iy0, real_T c, real_T s);
static real_T Thrustallocation_t_eml_xdotc_hs(int32_T n, const real_T x[144],
  int32_T ix0, const real_T y[144], int32_T iy0);
static void Thrustallocation_eml_xaxpy_mr5p(int32_T n, real_T a, int32_T ix0,
  real_T y[144], int32_T iy0);
static real_T Thrustallocation_te_eml_xdotc_h(int32_T n, const real_T x[9],
  int32_T ix0, const real_T y[9], int32_T iy0);
static void Thrustallocation__eml_xaxpy_mr5(int32_T n, real_T a, int32_T ix0,
  real_T y[9], int32_T iy0);
static real_T Thrustallocation_test_eml_xdotc(int32_T n, const real_T x[36],
  int32_T ix0, const real_T y[36], int32_T iy0);
static void Thrustallocation_test_eml_xaxpy(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0);
static void Thrustallocation_tes_eml_xgesvd(const real_T A[36], real_T U[9],
  real_T S[3], real_T V[36]);
static void Thrustallocation_test_abs(const real_T x[2], real_T y[2]);
static void Thrustallocation_test_cosd(real_T *x);
static void Thrustallocation_test_sind(real_T *x);
static void Thrustallocation_test_cosd_o(real_T *x);
static void Thrustallocation_test_sind_i(real_T *x);

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
  int_T nXc = 18;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Thrustallocation_test_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Thrustallocation_test_output();
  Thrustallocation_test_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Thrustallocation_test_output();
  Thrustallocation_test_derivatives();

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
 *    '<S27>/Actual Force and Torque'
 *    '<S36>/Actual Force and Torque'
 *    '<S45>/Actual Force and Torque'
 *    '<S54>/Actual Force and Torque'
 *    '<S63>/Actual Force and Torque'
 *    '<S72>/Actual Force and Torque'
 */
void Thrustallo_ActualForceandTorque(real_T rtu_n, real_T rtu_Kq, real_T rtu_Kt,
  real_T rtu_Ktr, real_T rtu_Kqr, real_T rtu_Rho, real_T rtu_D, real_T rtu_eps_c,
  real_T rtu_env, B_ActualForceandTorque_Thrust_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_0;

  /* MATLAB Function 'Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque': '<S30>:1' */
  /* '<S30>:1:3' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S30>:1:4' */
  /* '<S30>:1:5' */
  /* '<S30>:1:7' */
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

  /* '<S30>:1:8' */
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
 *    '<S31>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S40>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S49>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S58>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S67>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S76>/Core controller: Torque,Power and Combined Torque//Power'
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

  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power': '<S35>:1' */
  /* '<S35>:1:4' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /* '<S35>:1:5' */
  K_TC = (1.0 - lambda_c) * rtu_K_t0r + rtu_K_t0 * lambda_c;

  /* '<S35>:1:6' */
  lambda_c = (1.0 - lambda_c) * rtu_K_q0r + rtu_K_q0 * lambda_c;

  /* '<S35>:1:7' */
  Qcq = lambda_c / K_TC * rtu_D * rtu_Tr;

  /* '<S35>:1:8' */
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

  /* '<S35>:1:9' */
  K_TC = exp(rt_powd_snf(fabs(rtu_p_cc * rtu_n), rtu_r_cc) * -rtu_k_cc);

  /* '<S35>:1:11' */
  localB->Qcc = (1.0 - K_TC) * lambda_c + K_TC * Qcq;
  localB->Qcq = Qcq;
  localB->Qcp = lambda_c;
}

/*
 * Output and update for atomic system:
 *    '<S29>/Supervisor'
 *    '<S38>/Supervisor'
 *    '<S47>/Supervisor'
 *    '<S56>/Supervisor'
 *    '<S65>/Supervisor'
 *    '<S74>/Supervisor'
 */
void Thrustallocation_tes_Supervisor(real_T rtu_control, real_T rtu_input,
  real_T rtu_n, B_Supervisor_Thrustallocation_T *localB)
{
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Supervisor': '<S34>:1' */
  /* '<S34>:1:2' */
  localB->u = 1.0;
  if (rtu_control == 1.0) {
    /* '<S34>:1:3' */
    if (rtu_input == 1.0) {
      /* '<S34>:1:4' */
      /* '<S34>:1:5' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S34>:1:6' */
      /* '<S34>:1:7' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S34>:1:8' */
      /* '<S34>:1:9' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S34>:1:10' */
      /* '<S34>:1:11' */
      localB->u = 4.0;
    } else {
      /* '<S34>:1:13' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 2.0) {
    /* '<S34>:1:17' */
    if (rtu_input == 1.0) {
      /* '<S34>:1:18' */
      /* '<S34>:1:19' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S34>:1:20' */
      /* '<S34>:1:21' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S34>:1:22' */
      /* '<S34>:1:23' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S34>:1:24' */
      /* '<S34>:1:25' */
      localB->u = 4.0;
    } else {
      /* '<S34>:1:27' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 3.0) {
    /* '<S34>:1:31' */
    if (rtu_input == 1.0) {
      /* '<S34>:1:32' */
      /* '<S34>:1:33' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S34>:1:34' */
      /* '<S34>:1:35' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S34>:1:36' */
      /* '<S34>:1:37' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S34>:1:38' */
      /* '<S34>:1:39' */
      localB->u = 4.0;
    } else {
      /* '<S34>:1:41' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 4.0) {
    /* '<S34>:1:45' */
    if (rtu_input == 1.0) {
      /* '<S34>:1:46' */
      /* '<S34>:1:47' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S34>:1:48' */
      /* '<S34>:1:49' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S34>:1:50' */
      /* '<S34>:1:51' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S34>:1:52' */
      /* '<S34>:1:53' */
      localB->u = 4.0;
    } else {
      /* '<S34>:1:55' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 5.0) {
    /* '<S34>:1:59' */
    if (rtu_input == 1.0) {
      /* '<S34>:1:60' */
      /* '<S34>:1:61' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S34>:1:62' */
      /* '<S34>:1:63' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S34>:1:64' */
      /* '<S34>:1:65' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S34>:1:66' */
      /* '<S34>:1:67' */
      localB->u = 4.0;
    } else {
      /* '<S34>:1:69' */
      localB->u = 5.0;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S38>/MATLAB Function'
 *    '<S47>/MATLAB Function'
 *    '<S56>/MATLAB Function'
 *    '<S65>/MATLAB Function'
 */
void Thrustallocation_MATLABFunction(real_T rtu_Td, real_T rtu_K_t0, real_T
  rtu_K_t0r, real_T rtu_rho, real_T rtu_D, real_T rtu_eps_c, real_T rtu_n_r,
  B_MATLABFunction_Thrustalloca_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_r_0;
  real_T rtu_Td_0;

  /* MATLAB Function 'Thruster control /Thruster 2/Thruster control/MATLAB Function': '<S42>:1' */
  /* '<S42>:1:5' */
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

  /* '<S42>:1:7' */
  lambda_c = tanh(rtu_eps_c * rtu_Td_0 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S42>:1:8' */
  /* '<S42>:1:10' */
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static real_T Thrustallocation_test_eml_xnrm2(int32_T n, const real_T x[36],
  int32_T ix0)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static real_T Thrustallocation_te_eml_xnrm2_b(int32_T n, const real_T x[12],
  int32_T ix0)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_t_eml_xaxpy_mr(int32_T n, real_T a, const real_T x
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_te_eml_xaxpy_m(int32_T n, real_T a, const real_T x
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_test_eml_xscal(real_T a, real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_te_eml_xscal_k(real_T a, real_T x[144], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 11; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_test_eml_xswap(real_T x[144], int32_T ix0, int32_T
  iy0)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_te_eml_xswap_o(real_T x[9], int32_T ix0, int32_T
  iy0)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_test_eml_xrotg(real_T *a, real_T *b, real_T *c,
  real_T *s)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_test_eml_xrot(real_T x[144], int32_T ix0, int32_T
  iy0, real_T c, real_T s)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_tes_eml_xrot_j(real_T x[9], int32_T ix0, int32_T
  iy0, real_T c, real_T s)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static real_T Thrustallocation_t_eml_xdotc_hs(int32_T n, const real_T x[144],
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_eml_xaxpy_mr5p(int32_T n, real_T a, int32_T ix0,
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static real_T Thrustallocation_te_eml_xdotc_h(int32_T n, const real_T x[9],
  int32_T ix0, const real_T y[9], int32_T iy0)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation__eml_xaxpy_mr5(int32_T n, real_T a, int32_T ix0,
  real_T y[9], int32_T iy0)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static real_T Thrustallocation_test_eml_xdotc(int32_T n, const real_T x[36],
  int32_T ix0, const real_T y[36], int32_T iy0)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_test_eml_xaxpy(int32_T n, real_T a, int32_T ix0,
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_tes_eml_xgesvd(const real_T A[36], real_T U[9],
  real_T S[3], real_T V[36])
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
  ztest0 = Thrustallocation_test_eml_xnrm2(3, b_A, 1);
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
      Thrustallocation_test_eml_xaxpy(3, -(Thrustallocation_test_eml_xdotc(3,
        b_A, 1, b_A, qp1jj + 1) / b_A[0]), 1, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 0; qp1 + 1 < 4; qp1++) {
    U[qp1] = b_A[qp1];
  }

  ztest0 = Thrustallocation_te_eml_xnrm2_b(11, e, 2);
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
      Thrustallocation_te_eml_xaxpy_m(2, e[qp1], b_A, 3 * qp1 + 2, work, 2);
    }

    for (qp1 = 1; qp1 + 1 < 13; qp1++) {
      Thrustallocation_t_eml_xaxpy_mr(2, -e[qp1] / e[1], work, 2, b_A, 3 * qp1 +
        2);
    }
  }

  for (qp1 = 1; qp1 + 1 < 13; qp1++) {
    Vf[qp1] = e[qp1];
  }

  apply_transform = false;
  ztest0 = Thrustallocation_test_eml_xnrm2(2, b_A, 5);
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
      Thrustallocation_test_eml_xaxpy(2, -(Thrustallocation_test_eml_xdotc(2,
        b_A, 5, b_A, qp1jj + 1) / b_A[4]), 5, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 1; qp1 + 1 < 4; qp1++) {
    U[qp1 + 3] = b_A[qp1 + 3];
  }

  ztest0 = Thrustallocation_te_eml_xnrm2_b(10, e, 3);
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
      Thrustallocation_te_eml_xaxpy_m(1, e[qp1], b_A, 3 * qp1 + 3, work, 3);
    }

    for (qp1 = 2; qp1 + 1 < 13; qp1++) {
      Thrustallocation_t_eml_xaxpy_mr(1, -e[qp1] / e[2], work, 3, b_A, 3 * qp1 +
        3);
    }
  }

  for (qp1 = 2; qp1 + 1 < 13; qp1++) {
    Vf[qp1 + 12] = e[qp1];
  }

  for (kase = 3; kase + 1 < 13; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = Thrustallocation_te_eml_xnrm2_b(9, e, 4);
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
        Thrustallocation__eml_xaxpy_mr5(3 - qs,
          -(Thrustallocation_te_eml_xdotc_h(3 - qs, U, iter + 1, U, qp1jj) /
            U[iter]), iter + 1, U, qp1jj);
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
        Thrustallocation_eml_xaxpy_mr5p(11 - qs,
          -(Thrustallocation_t_eml_xdotc_hs(11 - qs, Vf, qp1, Vf, qp1jj) /
            Vf[qp1 - 1]), qp1, Vf, qp1jj);
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
    Thrustallocation_test_eml_xscal(ztest0, U, 1);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[1] *= ztest0;
    Thrustallocation_te_eml_xscal_k(ztest0, Vf, 13);
  }

  e[0] = b;
  b = e[1];
  if (s[1] != 0.0) {
    ztest = fabs(s[1]);
    ztest0 = s[1] / ztest;
    s[1] = ztest;
    b = e[1] / ztest0;
    Thrustallocation_test_eml_xscal(ztest0, U, 4);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[2] = b_A[8] * ztest0;
    Thrustallocation_te_eml_xscal_k(ztest0, Vf, 25);
  }

  e[1] = b;
  b = e[2];
  if (s[2] != 0.0) {
    ztest = fabs(s[2]);
    ztest0 = s[2] / ztest;
    s[2] = ztest;
    b = e[2] / ztest0;
    Thrustallocation_test_eml_xscal(ztest0, U, 7);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[3] = 0.0 * ztest0;
    Thrustallocation_te_eml_xscal_k(ztest0, Vf, 37);
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
        Thrustallocation_test_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        if (kase + 1 > q + 1) {
          f = e[kase - 1] * -b;
          e[kase - 1] *= ztest;
        }

        Thrustallocation_test_eml_xrot(Vf, 1 + 12 * kase, 1 + 12 * (m + 1),
          ztest, b);
      }
      break;

     case 2:
      f = e[q - 1];
      e[q - 1] = 0.0;
      for (kase = q; kase + 1 <= m + 2; kase++) {
        ztest0 = s[kase];
        Thrustallocation_test_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        f = -b * e[kase];
        e[kase] *= ztest;
        Thrustallocation_tes_eml_xrot_j(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest,
          b);
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
        Thrustallocation_test_eml_xrotg(&f, &b, &ztest0, &ztest);
        if (kase > q + 1) {
          e[kase - 2] = f;
        }

        f = s[kase - 1] * ztest0 + e[kase - 1] * ztest;
        e[kase - 1] = e[kase - 1] * ztest0 - s[kase - 1] * ztest;
        b = ztest * s[kase];
        s[kase] *= ztest0;
        Thrustallocation_test_eml_xrot(Vf, 1 + 12 * (kase - 1), 1 + 12 * kase,
          ztest0, ztest);
        Thrustallocation_test_eml_xrotg(&f, &b, &ztest0, &ztest);
        s[kase - 1] = f;
        f = e[kase - 1] * ztest0 + ztest * s[kase];
        s[kase] = e[kase - 1] * -ztest + ztest0 * s[kase];
        b = ztest * e[kase];
        e[kase] *= ztest0;
        if (kase < 3) {
          Thrustallocation_tes_eml_xrot_j(U, 1 + 3 * (kase - 1), 1 + 3 * kase,
            ztest0, ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        Thrustallocation_te_eml_xscal_k(-1.0, Vf, 1 + 12 * q);
      }

      qp1 = q + 1;
      while ((q + 1 < 4) && (s[q] < s[qp1])) {
        ztest = s[q];
        s[q] = s[qp1];
        s[qp1] = ztest;
        Thrustallocation_test_eml_xswap(Vf, 1 + 12 * q, 1 + 12 * (q + 1));
        if (q + 1 < 3) {
          Thrustallocation_te_eml_xswap_o(U, 1 + 3 * q, 1 + 3 * (q + 1));
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

/* Function for MATLAB Function: '<S4>/MATLAB Function2' */
static void Thrustallocation_test_abs(const real_T x[2], real_T y[2])
{
  y[0] = fabs(x[0]);
  y[1] = fabs(x[1]);
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

/* Function for MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */
static void Thrustallocation_test_cosd(real_T *x)
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
static void Thrustallocation_test_sind(real_T *x)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_test_cosd_o(real_T *x)
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

/* Function for MATLAB Function: '<S4>/MATLAB Function1' */
static void Thrustallocation_test_sind_i(real_T *x)
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
void Thrustallocation_test_output(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator;
  real_T rtb_Integrator_d;
  real_T rtb_Integrator_g;
  real_T rtb_Integrator_i;
  real_T rtb_Integrator_dt;
  real_T rtb_Integrator_h;
  real_T rtb_Position[3];
  real_T rtb_Integrator_m;
  real_T rtb_Integrator_i0;
  real_T rtb_Integrator_b;
  real_T rtb_Integrator_bu;
  real_T rtb_Integrator_k;
  real_T rtb_Integrator_gs;
  real_T rtb_T_r;
  real_T rtb_T_r_c;
  real_T rtb_ImpSel_InsertedFor_reset_at;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T b_signal;
  real_T s[6];
  real_T T_surge[6];
  real_T K[6];
  real_T S_singular_cross[9];
  real_T Aeq[27];
  int8_T d[36];
  real_T U[9];
  real_T s_0[3];
  real_T V[36];
  static const int8_T c[12] = { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 };

  static const int8_T e[12] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };

  boolean_T h[9];
  real_T c1[2];
  real_T varargin_1[2];
  int32_T ixstart;
  int32_T b_ixstart;
  boolean_T exitg11;
  real_T j;
  real_T k;
  real_T l;
  real_T m;
  real_T n;
  real_T o;
  real_T p;
  real_T q;
  real_T r;
  real_T s_1;
  real_T t;
  real_T u;
  real_T v;
  real_T w;
  real_T x;
  real_T y;
  real_T lambda_c;
  real_T rtb_y[6];
  real_T rtb_ImpAsg_InsertedFor_Out2_at_[6];
  real_T rtb_Sum_k;
  real_T rtb_TmpSignalConversionAtSFunct[12];
  real_T rtb_TmpSignalConversionAtSFu_la[6];
  real_T rtb_TmpSignalConversionAtSFun_k[10];
  int32_T i;
  real_T c1_0[2];
  real_T c1_1[2];
  real_T c1_2[2];
  real_T c1_3[2];
  real_T c1_4[2];
  real_T c1_5[2];
  real_T c_0[36];
  int8_T K_0;
  int8_T K_1;
  int8_T K_2;
  int8_T K_3;
  int8_T K_4;
  int32_T i_0;
  real_T T_surge_0[18];
  real_T T_surge_1[18];
  real_T tmp[6];
  real_T b_signal_0[18];
  real_T tmp_0[9];
  real_T tmp_1[9];
  int32_T b_data[9];
  real_T Alpha1_idx_0;
  real_T Alpha1_idx_1;
  real_T Alpha1_idx_2;
  real_T Alpha1_idx_3;
  real_T Alpha1_idx_4;
  real_T Alpha1_idx_5;
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* set solver stop time */
    if (!(Thrustallocation_test_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Thrustallocation_test_M->solverInfo,
                            ((Thrustallocation_test_M->Timing.clockTickH0 + 1) *
        Thrustallocation_test_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Thrustallocation_test_M->solverInfo,
                            ((Thrustallocation_test_M->Timing.clockTick0 + 1) *
        Thrustallocation_test_M->Timing.stepSize0 +
        Thrustallocation_test_M->Timing.clockTickH0 *
        Thrustallocation_test_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Thrustallocation_test_M)) {
    Thrustallocation_test_M->Timing.t[0] = rtsiGetT
      (&Thrustallocation_test_M->solverInfo);
  }

  /* Integrator: '<S28>/Integrator' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE,
                       Thrustallocation_test_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Thrustallocation_test_X.Integrator_CSTATE =
        Thrustallocation_test_P.Integrator_IC;
    }
  }

  rtb_Integrator = Thrustallocation_test_X.Integrator_CSTATE;

  /* MATLAB Function: '<S27>/Actual Force and Torque' incorporates:
   *  Constant: '<S20>/Losses (placeholder)'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kq'
   *  Constant: '<S2>/Kqr'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  Thrustallo_ActualForceandTorque(rtb_Integrator, Thrustallocation_test_P.Kq,
    Thrustallocation_test_P.Kt, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Kqr, Thrustallocation_test_P.Rho,
    Thrustallocation_test_P.D, Thrustallocation_test_P.eps_c,
    Thrustallocation_test_P.Lossesplaceholder_Value,
    &Thrustallocation_test_B.sf_ActualForceandTorque);

  /* Integrator: '<S37>/Integrator' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_b,
                       Thrustallocation_test_B.reset_e);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Thrustallocation_test_X.Integrator_CSTATE_o =
        Thrustallocation_test_P.Integrator_IC_c;
    }
  }

  rtb_Integrator_d = Thrustallocation_test_X.Integrator_CSTATE_o;

  /* MATLAB Function: '<S36>/Actual Force and Torque' incorporates:
   *  Constant: '<S21>/Losses (placeholder)'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kq'
   *  Constant: '<S2>/Kqr'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  Thrustallo_ActualForceandTorque(rtb_Integrator_d, Thrustallocation_test_P.Kq,
    Thrustallocation_test_P.Kt, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Kqr, Thrustallocation_test_P.Rho,
    Thrustallocation_test_P.D, Thrustallocation_test_P.eps_c,
    Thrustallocation_test_P.Lossesplaceholder_Value_f,
    &Thrustallocation_test_B.sf_ActualForceandTorque_k);

  /* Integrator: '<S46>/Integrator' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_m,
                       Thrustallocation_test_B.reset_l);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Thrustallocation_test_X.Integrator_CSTATE_p =
        Thrustallocation_test_P.Integrator_IC_g;
    }
  }

  rtb_Integrator_g = Thrustallocation_test_X.Integrator_CSTATE_p;

  /* MATLAB Function: '<S45>/Actual Force and Torque' incorporates:
   *  Constant: '<S22>/Losses (placeholder)'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kq'
   *  Constant: '<S2>/Kqr'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  Thrustallo_ActualForceandTorque(rtb_Integrator_g, Thrustallocation_test_P.Kq,
    Thrustallocation_test_P.Kt, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Kqr, Thrustallocation_test_P.Rho,
    Thrustallocation_test_P.D, Thrustallocation_test_P.eps_c,
    Thrustallocation_test_P.Lossesplaceholder_Value_fv,
    &Thrustallocation_test_B.sf_ActualForceandTorque_g);

  /* Integrator: '<S55>/Integrator' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_d,
                       Thrustallocation_test_B.reset_o);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Thrustallocation_test_X.Integrator_CSTATE_a =
        Thrustallocation_test_P.Integrator_IC_e;
    }
  }

  rtb_Integrator_i = Thrustallocation_test_X.Integrator_CSTATE_a;

  /* MATLAB Function: '<S54>/Actual Force and Torque' incorporates:
   *  Constant: '<S23>/Losses (placeholder)'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kq'
   *  Constant: '<S2>/Kqr'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  Thrustallo_ActualForceandTorque(rtb_Integrator_i, Thrustallocation_test_P.Kq,
    Thrustallocation_test_P.Kt, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Kqr, Thrustallocation_test_P.Rho,
    Thrustallocation_test_P.D, Thrustallocation_test_P.eps_c,
    Thrustallocation_test_P.Lossesplaceholder_Value_e,
    &Thrustallocation_test_B.sf_ActualForceandTorque_b);

  /* Integrator: '<S64>/Integrator' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_g,
                       Thrustallocation_test_B.reset_k);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Thrustallocation_test_X.Integrator_CSTATE_a0 =
        Thrustallocation_test_P.Integrator_IC_l;
    }
  }

  rtb_Integrator_dt = Thrustallocation_test_X.Integrator_CSTATE_a0;

  /* MATLAB Function: '<S63>/Actual Force and Torque' incorporates:
   *  Constant: '<S24>/Losses (placeholder)'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kq'
   *  Constant: '<S2>/Kqr'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  Thrustallo_ActualForceandTorque(rtb_Integrator_dt, Thrustallocation_test_P.Kq,
    Thrustallocation_test_P.Kt, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Kqr, Thrustallocation_test_P.Rho,
    Thrustallocation_test_P.D, Thrustallocation_test_P.eps_c,
    Thrustallocation_test_P.Lossesplaceholder_Value_a,
    &Thrustallocation_test_B.sf_ActualForceandTorque_m);

  /* Integrator: '<S73>/Integrator' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_f,
                       Thrustallocation_test_B.reset_km);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Thrustallocation_test_X.Integrator_CSTATE_d =
        Thrustallocation_test_P.Integrator_IC_j;
    }
  }

  rtb_Integrator_h = Thrustallocation_test_X.Integrator_CSTATE_d;

  /* MATLAB Function: '<S72>/Actual Force and Torque' incorporates:
   *  Constant: '<S25>/Losses (placeholder)'
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kq'
   *  Constant: '<S2>/Kqr'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  Thrustallo_ActualForceandTorque(rtb_Integrator_h, Thrustallocation_test_P.Kq,
    Thrustallocation_test_P.Kt, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Kqr, Thrustallocation_test_P.Rho,
    Thrustallocation_test_P.D, Thrustallocation_test_P.eps_c,
    Thrustallocation_test_P.Lossesplaceholder_Value_i,
    &Thrustallocation_test_B.sf_ActualForceandTorque_n);

  /* MATLAB Function: '<S19>/MATLAB Function' incorporates:
   *  Constant: '<S19>/Shaft speed thruster 1'
   *  Constant: '<S19>/Shaft speed thruster 2'
   *  Constant: '<S19>/Shaft speed thruster 3'
   *  Constant: '<S19>/Shaft speed thruster 4'
   *  Constant: '<S19>/Shaft speed thruster 5'
   *  Constant: '<S19>/Shaft speed thruster 6'
   *  SignalConversion: '<S26>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function': '<S26>:1' */
  if (Thrustallocation_test_B.core_controller == 1.0) {
    /* '<S26>:1:3' */
    /* '<S26>:1:4' */
    Thrustallocation_test_B.output[0] =
      Thrustallocation_test_B.sf_ActualForceandTorque.Ta;
    Thrustallocation_test_B.output[1] =
      Thrustallocation_test_P.Shaftspeedthruster1_Value;
    Thrustallocation_test_B.output[2] =
      Thrustallocation_test_B.sf_ActualForceandTorque_k.Ta;
    Thrustallocation_test_B.output[3] =
      Thrustallocation_test_P.Shaftspeedthruster2_Value;
    Thrustallocation_test_B.output[4] =
      Thrustallocation_test_B.sf_ActualForceandTorque_g.Ta;
    Thrustallocation_test_B.output[5] =
      Thrustallocation_test_P.Shaftspeedthruster3_Value;
    Thrustallocation_test_B.output[6] =
      Thrustallocation_test_B.sf_ActualForceandTorque_b.Ta;
    Thrustallocation_test_B.output[7] =
      Thrustallocation_test_P.Shaftspeedthruster4_Value;
    Thrustallocation_test_B.output[8] =
      Thrustallocation_test_B.sf_ActualForceandTorque_m.Ta;
    Thrustallocation_test_B.output[9] =
      Thrustallocation_test_P.Shaftspeedthruster5_Value;
    Thrustallocation_test_B.output[10] =
      Thrustallocation_test_B.sf_ActualForceandTorque_n.Ta;
    Thrustallocation_test_B.output[11] =
      Thrustallocation_test_P.Shaftspeedthruster6_Value;
  } else {
    /* '<S26>:1:6' */
    Thrustallocation_test_B.output[0] =
      Thrustallocation_test_B.sf_ActualForceandTorque.Ta;
    Thrustallocation_test_B.output[1] = rtb_Integrator;
    Thrustallocation_test_B.output[2] =
      Thrustallocation_test_B.sf_ActualForceandTorque_k.Ta;
    Thrustallocation_test_B.output[3] = rtb_Integrator_d;
    Thrustallocation_test_B.output[4] =
      Thrustallocation_test_B.sf_ActualForceandTorque_g.Ta;
    Thrustallocation_test_B.output[5] = rtb_Integrator_g;
    Thrustallocation_test_B.output[6] =
      Thrustallocation_test_B.sf_ActualForceandTorque_b.Ta;
    Thrustallocation_test_B.output[7] = rtb_Integrator_i;
    Thrustallocation_test_B.output[8] =
      Thrustallocation_test_B.sf_ActualForceandTorque_m.Ta;
    Thrustallocation_test_B.output[9] = rtb_Integrator_dt;
    Thrustallocation_test_B.output[10] =
      Thrustallocation_test_B.sf_ActualForceandTorque_n.Ta;
    Thrustallocation_test_B.output[11] = rtb_Integrator_h;
  }

  /* End of MATLAB Function: '<S19>/MATLAB Function' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* UnitDelay: '<S81>/Delay Input1' */
    Thrustallocation_test_B.Uk1 = Thrustallocation_test_DW.DelayInput1_DSTATE;
  }

  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* UnitDelay: '<S82>/Delay Input1' */
    Thrustallocation_test_B.Uk1_m =
      Thrustallocation_test_DW.DelayInput1_DSTATE_d;
  }

  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* UnitDelay: '<S83>/Delay Input1' */
    Thrustallocation_test_B.Uk1_h =
      Thrustallocation_test_DW.DelayInput1_DSTATE_c;
  }

  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Memory: '<S9>/Memory' */
    Thrustallocation_test_B.Memory =
      Thrustallocation_test_DW.Memory_PreviousInput;
  }

  /* MATLAB Function: '<S9>/MATLAB Function' incorporates:
   *  RelationalOperator: '<S81>/FixPt Relational Operator'
   *  RelationalOperator: '<S82>/FixPt Relational Operator'
   *  RelationalOperator: '<S83>/FixPt Relational Operator'
   */
  /* MATLAB Function 'u_limiter/MATLAB Function': '<S84>:1' */
  /* '<S84>:1:5' */
  b_signal = Thrustallocation_test_B.Memory;
  if (Thrustallocation_test_B.ArrowUp > Thrustallocation_test_B.Uk1) {
    /* '<S84>:1:7' */
    /* '<S84>:1:8' */
    b_signal = Thrustallocation_test_B.Memory + 0.05;
    if (Thrustallocation_test_B.Memory + 0.05 > 1.0) {
      /* '<S84>:1:10' */
      /* '<S84>:1:11' */
      b_signal = 1.0;
    }
  }

  if (Thrustallocation_test_B.ArrowDown > Thrustallocation_test_B.Uk1_m) {
    /* '<S84>:1:15' */
    /* '<S84>:1:16' */
    b_signal -= 0.05;
    if (b_signal < -1.0) {
      /* '<S84>:1:18' */
      /* '<S84>:1:19' */
      b_signal = -1.0;
    }
  }

  if (Thrustallocation_test_B.Start > Thrustallocation_test_B.Uk1_h) {
    /* '<S84>:1:23' */
    /* '<S84>:1:24' */
    b_signal = 0.0;
  }

  /* '<S84>:1:29' */
  Thrustallocation_test_B.y = b_signal;

  /* End of MATLAB Function: '<S9>/MATLAB Function' */

  /* SignalConversion: '<S14>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S4>/angle between  [180 -180]'
   */
  rtb_TmpSignalConversionAtSFu_la[0] = Thrustallocation_test_B.thr_angle_1;
  rtb_TmpSignalConversionAtSFu_la[1] = Thrustallocation_test_B.thr_angle_2;
  rtb_TmpSignalConversionAtSFu_la[2] = Thrustallocation_test_B.thr_angle_3;
  rtb_TmpSignalConversionAtSFu_la[3] = Thrustallocation_test_B.thr_angle_4;
  rtb_TmpSignalConversionAtSFu_la[4] = Thrustallocation_test_B.thr_angle_5;
  rtb_TmpSignalConversionAtSFu_la[5] = Thrustallocation_test_B.thr_angle_6;

  /* MATLAB Function: '<S4>/angle between  [180 -180]' */
  /* MATLAB Function 'Thrust allocation/angle between  [180 -180]': '<S14>:1' */
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
  /* '<S14>:1:39' */
  /* '<S14>:1:40' */
  /*  s = sign(angle); */
  /* '<S14>:1:43' */
  for (i = 0; i < 6; i++) {
    Alpha1_idx_0 = rt_remd_snf(rtb_TmpSignalConversionAtSFu_la[i] +
      3.1415926535897931, 6.2831853071795862) / 6.2831853071795862;
    Alpha1_idx_5 = fabs(Alpha1_idx_0);
    if (Alpha1_idx_5 > 0.0) {
      Alpha1_idx_5 = 1.0;
    } else {
      if (Alpha1_idx_5 == 0.0) {
        Alpha1_idx_5 = 0.0;
      }
    }

    if (rtb_TmpSignalConversionAtSFu_la[i] < 0.0) {
      Alpha1_idx_1 = -1.0;
    } else if (rtb_TmpSignalConversionAtSFu_la[i] > 0.0) {
      Alpha1_idx_1 = 1.0;
    } else if (rtb_TmpSignalConversionAtSFu_la[i] == 0.0) {
      Alpha1_idx_1 = 0.0;
    } else {
      Alpha1_idx_1 = rtb_TmpSignalConversionAtSFu_la[i];
    }

    s_1 = (Alpha1_idx_5 - 1.0) * 2.0 + Alpha1_idx_1;
    if (s_1 < 0.0) {
      s_1 = -1.0;
    } else if (s_1 > 0.0) {
      s_1 = 1.0;
    } else {
      if (s_1 == 0.0) {
        s_1 = 0.0;
      }
    }

    if (rtb_TmpSignalConversionAtSFu_la[i] < 0.0) {
      Alpha1_idx_1 = -1.0;
    } else if (rtb_TmpSignalConversionAtSFu_la[i] > 0.0) {
      Alpha1_idx_1 = 1.0;
    } else if (rtb_TmpSignalConversionAtSFu_la[i] == 0.0) {
      Alpha1_idx_1 = 0.0;
    } else {
      Alpha1_idx_1 = rtb_TmpSignalConversionAtSFu_la[i];
    }

    rtb_y[i] = rt_remd_snf(Alpha1_idx_1 * 3.1415926535897931 +
      rtb_TmpSignalConversionAtSFu_la[i], 6.2831853071795862) - s_1 *
      3.1415926535897931;
    rtb_TmpSignalConversionAtSFu_la[i] = Alpha1_idx_0;
  }

  /* Product: '<Root>/Product1' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  Thrustallocation_test_B.Product1 = Thrustallocation_test_P.Gain1_Gain *
    Thrustallocation_test_B.PosYLeft * Thrustallocation_test_B.y;

  /* Product: '<Root>/Product2' */
  Thrustallocation_test_B.Product2 = Thrustallocation_test_B.PosXLeft *
    Thrustallocation_test_B.y;

  /* Product: '<Root>/Product' incorporates:
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Sum'
   */
  Thrustallocation_test_B.Product = (Thrustallocation_test_B.L2_continuous -
    Thrustallocation_test_B.R2_continuous) * Thrustallocation_test_P.Gain_Gain_d
    * Thrustallocation_test_B.y;

  /* SignalConversion: '<S10>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Gain: '<S13>/Gain'
   *  MATLAB Function: '<S4>/MATLAB Function1'
   */
  rtb_TmpSignalConversionAtSFun_k[0] = Thrustallocation_test_B.Product1;
  rtb_TmpSignalConversionAtSFun_k[1] = Thrustallocation_test_B.Product2;
  rtb_TmpSignalConversionAtSFun_k[2] = Thrustallocation_test_B.Product;
  for (i = 0; i < 6; i++) {
    rtb_TmpSignalConversionAtSFun_k[i + 3] = Thrustallocation_test_P.Gain_Gain *
      rtb_y[i];
  }

  /* End of SignalConversion: '<S10>/TmpSignal ConversionAt SFunction Inport1' */

  /* MATLAB Function: '<S4>/MATLAB Function1' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/X-position Thruster1'
   *  Constant: '<S4>/Y-position Thruster2'
   */
  /* MATLAB Function 'Thrust allocation/MATLAB Function1': '<S10>:1' */
  /*  Function for finding optimal thrust and angle */
  /*  Work in progress   */
  /*  Author: Preben Frederich */
  /*  12/12-2015 */
  /*  Version 1.0 : Pseudo inverse optimalization created */
  /*                12/12-2015 Preben Frederich */
  /*  Version 1.1 : Desired angle implemented */
  /*                02/03-2016 Preben Frederich */
  /*  Version 1.2 : Individual & coupled constrained thrust allocation implemented */
  /*                07/04-2016 Preben Frederih */
  /*  Version 1.3 : Quadratic control allocation implemented with optimal */
  /*                angles found by pseudoinverse allocation */
  /*                15/04-2016 Preben Frederich */
  /*  Version 1.4 : Quadratic control allocation modified to optimize around */
  /*                the different thrusters when they are in forbidden zones */
  /*                20/04-2016 Preben Frederich */
  /*  Version 1.5 : Implemented constraints at forbidden zones varying depending  */
  /*                on length between each thruster. Retrived from Initfile as [C]. */
  /*                22/04-2016 Preben Frederich */
  /*  Version 1.6 : Implemented possibilities for using real model values for */
  /*                the quadratic regulator */
  /*                25/04-2016 Preben Frederich */
  /*  Version 1.7 : Initial conditions for Quadratic regulator is updated with */
  /*                the optimal solution from last time step. Makes the next */
  /*                timestep solution run much faster */
  /*                03/05-2016 Preben Frederich */
  /*  Complete system goes here! */
  /* ThrusterPosX = [Thruster.T1(1) Thruster.T2(1) Thruster.T3(1) Thruster.T4(1) Thruster.T5(1) Thruster.T6(1)];%[x(1),x(2),x(3),x(4),x(5),x(6)]'; */
  /* ThrusterPosY = [Thruster.T1(2) Thruster.T2(2) Thruster.T3(2) Thruster.T4(2) Thruster.T5(2) Thruster.T6(2)];%[x(7),x(8),x(9),x(10),x(11),x(12)]'; */
  /*  Parameters thrusters */
  /* '<S10>:1:35' */
  Thrustallocation_test_B.BMatrix[0] = rtb_TmpSignalConversionAtSFun_k[0];
  Thrustallocation_test_B.BMatrix[1] = rtb_TmpSignalConversionAtSFun_k[1];
  Thrustallocation_test_B.BMatrix[2] = rtb_TmpSignalConversionAtSFun_k[2];

  /* '<S10>:1:36' */
  rtb_TmpSignalConversionAtSFu_la[0] = rtb_TmpSignalConversionAtSFun_k[3];
  rtb_TmpSignalConversionAtSFu_la[1] = rtb_TmpSignalConversionAtSFun_k[4];
  rtb_TmpSignalConversionAtSFu_la[2] = rtb_TmpSignalConversionAtSFun_k[5];
  rtb_TmpSignalConversionAtSFu_la[3] = rtb_TmpSignalConversionAtSFun_k[6];
  rtb_TmpSignalConversionAtSFu_la[4] = rtb_TmpSignalConversionAtSFun_k[7];
  rtb_TmpSignalConversionAtSFu_la[5] = rtb_TmpSignalConversionAtSFun_k[8];

  /* alpha0 = [x(1),x(2),x(3),x(4),x(5),x(6)]'; */
  /*  Td_prev = [u(11) u(12) u(13) u(14) u(15) u(16)]; */
  /*  number of thrusters */
  /* '<S10>:1:43' */
  /*  Shells for faster computing */
  /* '<S10>:1:44' */
  /*  Shells for faster computing */
  /* '<S10>:1:45' */
  /*  Shells for faster computing */
  /* '<S10>:1:47' */
  for (ixstart = 0; ixstart < 6; ixstart++) {
    /* '<S10>:1:47' */
    /* '<S10>:1:48' */
    T_surge[ixstart] = rtb_TmpSignalConversionAtSFu_la[ixstart];
    Thrustallocation_test_cosd_o(&T_surge[ixstart]);

    /* Thrust in x-direction for cartesian */
    /* '<S10>:1:49' */
    rtb_y[ixstart] = rtb_TmpSignalConversionAtSFu_la[ixstart];
    Thrustallocation_test_sind_i(&rtb_y[ixstart]);

    /* Thrust in y-direction for cartesian */
    /* '<S10>:1:50' */
    Alpha1_idx_1 = rtb_TmpSignalConversionAtSFu_la[ixstart];
    Thrustallocation_test_sind_i(&Alpha1_idx_1);
    Alpha1_idx_2 = rtb_TmpSignalConversionAtSFu_la[ixstart];
    Thrustallocation_test_cosd_o(&Alpha1_idx_2);
    s[ixstart] = Alpha1_idx_1 *
      Thrustallocation_test_P.XpositionThruster1_Value[ixstart] - Alpha1_idx_2 *
      Thrustallocation_test_P.YpositionThruster2_Value[ixstart];

    /* '<S10>:1:47' */
  }

  /*  Constraints for Thruster-Thruster interaction. Can be seen in "Initfile" */
  /*  how they are found */
  /* '<S10>:1:55' */
  /* '<S10>:1:56' */
  /* '<S10>:1:57' */
  /* '<S10>:1:58' */
  /* '<S10>:1:59' */
  /* '<S10>:1:60' */
  /*  Ok 12.05/16 */
  if (((rtb_TmpSignalConversionAtSFun_k[3] < Thrustallocation_test_P.C[0] - 0.1)
       && (rtb_TmpSignalConversionAtSFun_k[3] > Thrustallocation_test_P.C[6] +
           0.1)) || ((rtb_TmpSignalConversionAtSFun_k[3] >
                      Thrustallocation_test_P.C[12] + 0.1) &&
                     (rtb_TmpSignalConversionAtSFun_k[3] <
                      Thrustallocation_test_P.C[18] - 0.1))) {
    /* '<S10>:1:65' */
    /* '<S10>:1:66' */
    K[0] = 0.0;
  } else {
    /* '<S10>:1:68' */
    K[0] = 1.0;
  }

  /*  OK 12.05/16 */
  if (((rtb_TmpSignalConversionAtSFun_k[4] < Thrustallocation_test_P.C[1] - 0.1)
       && (rtb_TmpSignalConversionAtSFun_k[4] > Thrustallocation_test_P.C[7] +
           0.1)) || ((rtb_TmpSignalConversionAtSFun_k[4] <
                      Thrustallocation_test_P.C[13] - 0.1) &&
                     (rtb_TmpSignalConversionAtSFun_k[4] >
                      Thrustallocation_test_P.C[19] + 0.1))) {
    /* '<S10>:1:71' */
    /* '<S10>:1:72' */
    K[1] = 0.0;
  } else {
    /* '<S10>:1:74' */
    K[1] = 1.0;
  }

  /*  OK 12.05/16 */
  if (((rtb_TmpSignalConversionAtSFun_k[5] > Thrustallocation_test_P.C[2] + 0.1)
       && (rtb_TmpSignalConversionAtSFun_k[5] < Thrustallocation_test_P.C[8] -
           0.1)) || ((rtb_TmpSignalConversionAtSFun_k[5] >
                      Thrustallocation_test_P.C[14] + 0.1) &&
                     (rtb_TmpSignalConversionAtSFun_k[5] <
                      Thrustallocation_test_P.C[20] - 0.1))) {
    /* '<S10>:1:77' */
    /* '<S10>:1:78' */
    K[2] = 0.0;
  } else {
    /* '<S10>:1:80' */
    K[2] = 1.0;
  }

  /*  OK 12.05/16 */
  if (((rtb_TmpSignalConversionAtSFun_k[6] > Thrustallocation_test_P.C[3] + 0.1)
       && (rtb_TmpSignalConversionAtSFun_k[6] < Thrustallocation_test_P.C[9] -
           0.1)) || ((rtb_TmpSignalConversionAtSFun_k[6] <
                      Thrustallocation_test_P.C[15] - 0.1) &&
                     (rtb_TmpSignalConversionAtSFun_k[6] >
                      Thrustallocation_test_P.C[21] + 0.1))) {
    /* '<S10>:1:83' */
    /* '<S10>:1:84' */
    K[3] = 0.0;
  } else {
    /* '<S10>:1:86' */
    K[3] = 1.0;
  }

  /*  OK 12.05/16 */
  if (((rtb_TmpSignalConversionAtSFun_k[7] > Thrustallocation_test_P.C[4] + 0.1)
       && (rtb_TmpSignalConversionAtSFun_k[7] < Thrustallocation_test_P.C[10] -
           0.1)) || ((rtb_TmpSignalConversionAtSFun_k[7] >
                      Thrustallocation_test_P.C[16] + 0.1) &&
                     (rtb_TmpSignalConversionAtSFun_k[7] <
                      Thrustallocation_test_P.C[22] - 0.1))) {
    /* '<S10>:1:89' */
    /* '<S10>:1:90' */
    K[4] = 0.0;
  } else {
    /* '<S10>:1:92' */
    K[4] = 1.0;
  }

  /*  OK 12.05/16 */
  if (((rtb_TmpSignalConversionAtSFun_k[8] < Thrustallocation_test_P.C[5] - 0.1)
       && (rtb_TmpSignalConversionAtSFun_k[8] > Thrustallocation_test_P.C[11] +
           0.1)) || ((rtb_TmpSignalConversionAtSFun_k[8] <
                      Thrustallocation_test_P.C[17] - 0.1) &&
                     (rtb_TmpSignalConversionAtSFun_k[8] >
                      Thrustallocation_test_P.C[23] + 0.1))) {
    /* '<S10>:1:95' */
    /* '<S10>:1:96' */
    K[5] = 0.0;
  } else {
    /* '<S10>:1:98' */
    K[5] = 1.0;
  }

  /* '<S10>:1:101' */
  K_0 = (int8_T)K[1];
  K_1 = (int8_T)K[2];
  K_2 = (int8_T)K[3];
  K_3 = (int8_T)K[4];
  K_4 = (int8_T)K[5];
  K[0] = (int8_T)K[0];
  K[1] = K_0;
  K[2] = K_1;
  K[3] = K_2;
  K[4] = K_3;
  K[5] = K_4;

  /* '<S10>:1:103' */
  /* '<S10>:1:104' */
  for (i_0 = 0; i_0 < 36; i_0++) {
    d[i_0] = 0;
  }

  for (i = 0; i < 6; i++) {
    d[i + 6 * i] = (int8_T)K[i];
  }

  /* '<S10>:1:105' */
  for (i_0 = 0; i_0 < 12; i_0++) {
    c_0[3 * i_0] = c[i_0];
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    c_0[1 + 3 * i_0] = e[i_0];
  }

  c_0[2] = Thrustallocation_test_P.YpositionThruster2_Value[0];
  c_0[5] = Thrustallocation_test_P.XpositionThruster1_Value[0];
  c_0[8] = Thrustallocation_test_P.YpositionThruster2_Value[1];
  c_0[11] = Thrustallocation_test_P.XpositionThruster1_Value[1];
  c_0[14] = Thrustallocation_test_P.YpositionThruster2_Value[2];
  c_0[17] = Thrustallocation_test_P.XpositionThruster1_Value[2];
  c_0[20] = Thrustallocation_test_P.YpositionThruster2_Value[3];
  c_0[23] = Thrustallocation_test_P.XpositionThruster1_Value[3];
  c_0[26] = Thrustallocation_test_P.YpositionThruster2_Value[4];
  c_0[29] = Thrustallocation_test_P.XpositionThruster1_Value[4];
  c_0[32] = Thrustallocation_test_P.YpositionThruster2_Value[5];
  c_0[35] = Thrustallocation_test_P.XpositionThruster1_Value[5];
  Thrustallocation_tes_eml_xgesvd(c_0, U, s_0, V);
  memset(&S_singular_cross[0], 0, 9U * sizeof(real_T));
  S_singular_cross[0] = s_0[0];
  S_singular_cross[4] = s_0[1];
  S_singular_cross[8] = s_0[2];

  /* '<S10>:1:110' */
  /* '<S10>:1:111' */
  ixstart = 0;
  for (i_0 = 0; i_0 < 9; i_0++) {
    Alpha1_idx_5 = 1.0 / S_singular_cross[i_0];
    exitg11 = !((!rtIsInf(Alpha1_idx_5)) && (!rtIsNaN(Alpha1_idx_5)));
    if (exitg11) {
      ixstart++;
    }

    h[i_0] = exitg11;
    S_singular_cross[i_0] = Alpha1_idx_5;
  }

  i = ixstart;
  ixstart = 0;
  for (b_ixstart = 0; b_ixstart < 9; b_ixstart++) {
    if (h[b_ixstart]) {
      b_data[ixstart] = b_ixstart + 1;
      ixstart++;
    }
  }

  /* '<S10>:1:111' */
  for (i_0 = 0; i_0 < i; i_0++) {
    S_singular_cross[b_data[i_0] - 1] = 0.0;
  }

  /*   if (S_singular_cross(3,3)>2*S_singular_cross(2,2))  */
  /*       S_singular_cross(3,3)=0; */
  /*   end */
  /* '<S10>:1:115' */
  for (i_0 = 0; i_0 < 12; i_0++) {
    for (i = 0; i < 3; i++) {
      c_0[i_0 + 12 * i] = 0.0;
      c_0[i_0 + 12 * i] += S_singular_cross[3 * i] * V[i_0];
      c_0[i_0 + 12 * i] += S_singular_cross[3 * i + 1] * V[i_0 + 12];
      c_0[i_0 + 12 * i] += S_singular_cross[3 * i + 2] * V[i_0 + 24];
    }
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    for (i = 0; i < 3; i++) {
      V[i_0 + 12 * i] = 0.0;
      V[i_0 + 12 * i] += c_0[i_0] * U[i];
      V[i_0 + 12 * i] += c_0[i_0 + 12] * U[i + 3];
      V[i_0 + 12 * i] += c_0[i_0 + 24] * U[i + 6];
    }
  }

  for (i_0 = 0; i_0 < 12; i_0++) {
    rtb_TmpSignalConversionAtSFunct[i_0] = V[i_0 + 24] *
      Thrustallocation_test_B.BMatrix[2] + (V[i_0 + 12] *
      Thrustallocation_test_B.BMatrix[1] + V[i_0] *
      Thrustallocation_test_B.BMatrix[0]);
  }

  /* '<S10>:1:116' */
  K[0] = 57.295779513082323 * rt_atan2d_snf(rtb_TmpSignalConversionAtSFunct[1],
    rtb_TmpSignalConversionAtSFunct[0]);
  K[1] = 57.295779513082323 * rt_atan2d_snf(rtb_TmpSignalConversionAtSFunct[3],
    rtb_TmpSignalConversionAtSFunct[2]);
  K[2] = 57.295779513082323 * rt_atan2d_snf(rtb_TmpSignalConversionAtSFunct[5],
    rtb_TmpSignalConversionAtSFunct[4]);
  K[3] = 57.295779513082323 * rt_atan2d_snf(rtb_TmpSignalConversionAtSFunct[7],
    rtb_TmpSignalConversionAtSFunct[6]);
  K[4] = 57.295779513082323 * rt_atan2d_snf(rtb_TmpSignalConversionAtSFunct[9],
    rtb_TmpSignalConversionAtSFunct[8]);
  K[5] = 57.295779513082323 * rt_atan2d_snf(rtb_TmpSignalConversionAtSFunct[11],
    rtb_TmpSignalConversionAtSFunct[10]);

  /*  Må kanskje ha denne for alpha in også */
  /* '<S10>:1:119' */
  for (ixstart = 0; ixstart < 6; ixstart++) {
    Alpha1_idx_5 = K[ixstart];

    /* '<S10>:1:119' */
    if (K[ixstart] > 180.0) {
      /* '<S10>:1:120' */
      /* '<S10>:1:121' */
      Alpha1_idx_5 = K[ixstart] - 360.0;
    } else {
      if (K[ixstart] < -180.0) {
        /* '<S10>:1:122' */
        /* '<S10>:1:123' */
        Alpha1_idx_5 = K[ixstart] + 360.0;
      }
    }

    /* '<S10>:1:119' */
    K[ixstart] = Alpha1_idx_5;
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  NOT IMPLEMENTED YET                                                     % */
  /*  Want to try to see if it can be used                                    % */
  /*  Cost function based upon error between desired angle and actual angle   % */
  /*  Angle_error = abs(alpha)-abs(alpha1');                                  % */
  /*  CostW = (abs(Angle_error)+1)/100;                                       % */
  /*  if CostW >= 1                                                           % */
  /*      CostW = 1;                                                          % */
  /*  end                                                                     % */
  /*  K = eye(n_t);%diag([ 5 5 5 5 5 5]);                                     % */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* zero3  = zeros(3,6); */
  /* '<S10>:1:148' */
  memset(&U[0], 0, 9U * sizeof(real_T));
  U[0] = 1.0;
  U[4] = 1.0;
  U[8] = 1.0;
  for (i_0 = 0; i_0 < 6; i_0++) {
    T_surge_0[3 * i_0] = T_surge[i_0];
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    T_surge_0[1 + 3 * i_0] = rtb_y[i_0];
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    T_surge_0[2 + 3 * i_0] = s[i_0];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 6; i++) {
      T_surge_1[i_0 + 3 * i] = 0.0;
      for (b_ixstart = 0; b_ixstart < 6; b_ixstart++) {
        T_surge_1[i_0 + 3 * i] += T_surge_0[3 * b_ixstart + i_0] * (real_T)d[6 *
          i + b_ixstart];
      }
    }
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    Aeq[3 * i_0] = T_surge_1[3 * i_0];
    Aeq[1 + 3 * i_0] = T_surge_1[3 * i_0 + 1];
    Aeq[2 + 3 * i_0] = T_surge_1[3 * i_0 + 2];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    Aeq[3 * (i_0 + 6)] = -U[3 * i_0];
    Aeq[1 + 3 * (i_0 + 6)] = -U[3 * i_0 + 1];
    Aeq[2 + 3 * (i_0 + 6)] = -U[3 * i_0 + 2];
  }

  /* ; zeros(12,15)]; */
  /* [diag(tc) zeros(3,2)]; */
  /* [0 0 0 0 0 0 -0.01 -0.01 -0.01]; */
  /* X0 = [u(11),u(12),u(13),u(14),u(15),u(16)]'; */
  /* '<S10>:1:153' */
  /* '<S10>:1:154' */
  /* '<S10>:1:155' */
  for (i_0 = 0; i_0 < 9; i_0++) {
    Thrustallocation_test_B.A1Matrix[i_0] = Aeq[3 * i_0];
    Thrustallocation_test_B.A2Matrix[i_0] = Aeq[3 * i_0 + 1];
    Thrustallocation_test_B.A3Matrix[i_0] = Aeq[3 * i_0 + 2];
  }

  /* '<S10>:1:156' */
  /* options = optimoptions('quadprog',... */
  /*     'Algorithm','interior-point-convex','Display','off'); */
  /*  X = quadprog(H,f,[],[],Aeq,Beq,lb,ub,X0,options); */
  /*  if numel(X) <= 6  */
  /*      X = [0 0 0 0 0 0 0 0 0]; */
  /*  end */
  /*  if sum(abs(X)) >= 10 */
  /*      X = [0 0 0 0 0 0 0 0 0]; */
  /*  end */
  /* T_d = [X(1) X(2) X(3) X(4) X(5) X(6)] ;      % Optimized Thrust */
  /* Desired_thrust = [T_d(1) T_d(2) T_d(3) T_d(4) T_d(5) T_d(6)]'; */
  /* '<S10>:1:170' */
  /* T_d = Desired_thrust; */
  /* % Update outputs */
  /* sys = [alpha_desired',T_d']; */

  /* MATLAB Function: '<S4>/MATLAB Function2' incorporates:
   *  Constant: '<S4>/Constant2'
   *  MATLAB Function: '<S4>/MATLAB Function1'
   */
  /* MATLAB Function 'Thrust allocation/MATLAB Function2': '<S11>:1' */
  /* '<S11>:1:3' */
  /* '<S11>:1:4' */
  /* '<S11>:1:5' */
  /* '<S11>:1:6' */
  /* '<S11>:1:7' */
  /* '<S11>:1:8' */
  /* '<S11>:1:10' */
  /* % Constraints */
  /* % Thruster 1 OK 13.05/16 */
  /* C1 = [49.7 29.4 -151 -130 ]; */
  if ((K[0] < Thrustallocation_test_P.C[0]) && (K[0] >
       Thrustallocation_test_P.C[6])) {
    /* '<S11>:1:16' */
    /* && T_d(1) > 0) || (alpha1(1) < C1(1)  && alpha1(1) > C1(2) && T_d(1) < 0) */
    /* '<S11>:1:17' */
    c1[0] = Thrustallocation_test_P.C[0];
    c1[1] = Thrustallocation_test_P.C[6];
    c1_5[0] = Thrustallocation_test_P.C[0] - K[0];
    c1_5[1] = Thrustallocation_test_P.C[6] - K[0];
    Thrustallocation_test_abs(c1_5, varargin_1);
    b_ixstart = 1;
    b_signal = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (ixstart < 3)) {
        b_ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          b_signal = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          ixstart = 3;
        }
      }
    }

    if ((b_ixstart < 2) && (varargin_1[1] < b_signal)) {
      i = 1;
    }

    /* '<S11>:1:19' */
    Alpha1_idx_0 = c1[i];
  } else if (((K[0] > Thrustallocation_test_P.C[12]) && (K[0] <
               Thrustallocation_test_P.C[18]) && (Thrustallocation_test_B.fmin[0]
    > 0.0)) || ((K[0] > Thrustallocation_test_P.C[12]) && (K[0] <
               Thrustallocation_test_P.C[18]) && (Thrustallocation_test_B.fmin[0]
    < 0.0))) {
    /* '<S11>:1:20' */
    /* '<S11>:1:21' */
    c1[0] = Thrustallocation_test_P.C[12];
    c1[1] = Thrustallocation_test_P.C[18];
    c1_5[0] = Thrustallocation_test_P.C[12] - K[0];
    c1_5[1] = Thrustallocation_test_P.C[18] - K[0];
    Thrustallocation_test_abs(c1_5, varargin_1);
    ixstart = 1;
    b_signal = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          b_signal = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < b_signal)) {
      i = 1;
    }

    /* '<S11>:1:23' */
    Alpha1_idx_0 = c1[i];
  } else {
    /* '<S11>:1:25' */
    Alpha1_idx_0 = K[0];
  }

  /* % Thruster 2 OK 13.05/16 */
  /* C2 = [99.85 80.15 50 29]; */
  if (((K[1] < Thrustallocation_test_P.C[1]) && (K[1] >
        Thrustallocation_test_P.C[7]) && (Thrustallocation_test_B.fmin[1] > 0.0))
      || ((K[1] < Thrustallocation_test_P.C[1]) && (K[1] >
        Thrustallocation_test_P.C[7]) && (Thrustallocation_test_B.fmin[1] < 0.0)))
  {
    /* '<S11>:1:35' */
    /* '<S11>:1:36' */
    c1[0] = Thrustallocation_test_P.C[1];
    c1[1] = Thrustallocation_test_P.C[7];
    c1_4[0] = Thrustallocation_test_P.C[1] - K[1];
    c1_4[1] = Thrustallocation_test_P.C[7] - K[1];
    Thrustallocation_test_abs(c1_4, varargin_1);
    ixstart = 1;
    b_signal = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          b_signal = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < b_signal)) {
      i = 1;
    }

    /* '<S11>:1:38' */
    Alpha1_idx_1 = c1[i];
  } else if (((K[1] < Thrustallocation_test_P.C[13]) && (K[1] >
               Thrustallocation_test_P.C[19]) && (Thrustallocation_test_B.fmin[1]
    > 0.0)) || ((K[1] < Thrustallocation_test_P.C[13]) && (K[1] >
               Thrustallocation_test_P.C[19]) && (Thrustallocation_test_B.fmin[1]
    < 0.0))) {
    /* '<S11>:1:39' */
    /* '<S11>:1:40' */
    c1[0] = Thrustallocation_test_P.C[13];
    c1[1] = Thrustallocation_test_P.C[19];
    c1_4[0] = Thrustallocation_test_P.C[13] - K[1];
    c1_4[1] = Thrustallocation_test_P.C[19] - K[1];
    Thrustallocation_test_abs(c1_4, varargin_1);
    ixstart = 1;
    b_signal = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          b_signal = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < b_signal)) {
      i = 1;
    }

    /* '<S11>:1:42' */
    Alpha1_idx_1 = c1[i];
  } else {
    /* '<S11>:1:44' */
    Alpha1_idx_1 = K[1];
  }

  /* % Thruster 3 OK 13.05/16 */
  /*  C3 = [-99.85 -80.15 -50 -29];  */
  if (((K[2] > Thrustallocation_test_P.C[2]) && (K[2] <
        Thrustallocation_test_P.C[8]) && (Thrustallocation_test_B.fmin[2] > 0.0))
      || ((K[2] > Thrustallocation_test_P.C[2]) && (K[2] <
        Thrustallocation_test_P.C[8]) && (Thrustallocation_test_B.fmin[2] < 0.0)))
  {
    /* '<S11>:1:55' */
    /* '<S11>:1:56' */
    c1[0] = Thrustallocation_test_P.C[2];
    c1[1] = Thrustallocation_test_P.C[8];
    c1_3[0] = Thrustallocation_test_P.C[2] - K[2];
    c1_3[1] = Thrustallocation_test_P.C[8] - K[2];
    Thrustallocation_test_abs(c1_3, varargin_1);
    ixstart = 1;
    b_signal = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          b_signal = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < b_signal)) {
      i = 1;
    }

    /* '<S11>:1:58' */
    Alpha1_idx_2 = c1[i];
  } else if (((K[2] > Thrustallocation_test_P.C[14]) && (K[2] <
               Thrustallocation_test_P.C[20]) && (Thrustallocation_test_B.fmin[2]
    > 0.0)) || ((K[2] > Thrustallocation_test_P.C[14]) && (K[2] <
               Thrustallocation_test_P.C[20]) && (Thrustallocation_test_B.fmin[2]
    < 0.0))) {
    /* '<S11>:1:59' */
    /* '<S11>:1:60' */
    c1[0] = Thrustallocation_test_P.C[14];
    c1[1] = Thrustallocation_test_P.C[20];
    c1_3[0] = Thrustallocation_test_P.C[14] - K[2];
    c1_3[1] = Thrustallocation_test_P.C[20] - K[2];
    Thrustallocation_test_abs(c1_3, varargin_1);
    ixstart = 1;
    b_signal = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          b_signal = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < b_signal)) {
      i = 1;
    }

    /* '<S11>:1:62' */
    Alpha1_idx_2 = c1[i];
  } else {
    /* '<S11>:1:64' */
    Alpha1_idx_2 = K[2];
  }

  /* % Thruster 4 OK 13.05/16 */
  /* C4 = [-52.8 -34.2 52.8 34.2];  */
  if (((K[3] > Thrustallocation_test_P.C[3]) && (K[3] <
        Thrustallocation_test_P.C[9]) && (Thrustallocation_test_B.fmin[3] > 0.0))
      || ((K[3] > Thrustallocation_test_P.C[3]) && (K[3] <
        Thrustallocation_test_P.C[9]) && (Thrustallocation_test_B.fmin[3] < 0.0)))
  {
    /* '<S11>:1:74' */
    /* '<S11>:1:75' */
    c1[0] = Thrustallocation_test_P.C[3];
    c1[1] = Thrustallocation_test_P.C[9];
    c1_2[0] = Thrustallocation_test_P.C[3] - K[3];
    c1_2[1] = Thrustallocation_test_P.C[9] - K[3];
    Thrustallocation_test_abs(c1_2, varargin_1);
    ixstart = 1;
    b_signal = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          b_signal = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < b_signal)) {
      i = 1;
    }

    /* '<S11>:1:77' */
    Alpha1_idx_3 = c1[i];
  } else if (((K[3] < Thrustallocation_test_P.C[15]) && (K[3] >
               Thrustallocation_test_P.C[21]) && (Thrustallocation_test_B.fmin[3]
    > 0.0)) || ((K[3] < Thrustallocation_test_P.C[15]) && (K[3] >
               Thrustallocation_test_P.C[21]) && (Thrustallocation_test_B.fmin[3]
    < 0.0))) {
    /* '<S11>:1:78' */
    /* '<S11>:1:79' */
    c1[0] = Thrustallocation_test_P.C[15];
    c1[1] = Thrustallocation_test_P.C[21];
    c1_2[0] = Thrustallocation_test_P.C[15] - K[3];
    c1_2[1] = Thrustallocation_test_P.C[21] - K[3];
    Thrustallocation_test_abs(c1_2, varargin_1);
    ixstart = 1;
    b_signal = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          b_signal = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < b_signal)) {
      i = 1;
    }

    /* '<S11>:1:81' */
    Alpha1_idx_3 = c1[i];
  } else {
    /* '<S11>:1:83' */
    Alpha1_idx_3 = K[3];
  }

  /* % Thruster 5 OK 13.05/16 */
  /* C5 = [-98.25 -81.75 -145.8 -127.2]; */
  if (((K[4] > Thrustallocation_test_P.C[4]) && (K[4] <
        Thrustallocation_test_P.C[10]) && (Thrustallocation_test_B.fmin[4] > 0.0))
      || ((K[4] > Thrustallocation_test_P.C[4]) && (K[4] <
        Thrustallocation_test_P.C[10]) && (Thrustallocation_test_B.fmin[4] < 0.0)))
  {
    /* '<S11>:1:93' */
    /* '<S11>:1:94' */
    c1[0] = Thrustallocation_test_P.C[4];
    c1[1] = Thrustallocation_test_P.C[10];
    c1_1[0] = Thrustallocation_test_P.C[4] - K[4];
    c1_1[1] = Thrustallocation_test_P.C[10] - K[4];
    Thrustallocation_test_abs(c1_1, varargin_1);
    ixstart = 1;
    b_signal = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          b_signal = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < b_signal)) {
      i = 1;
    }

    /* '<S11>:1:96' */
    Alpha1_idx_4 = c1[i];
  } else if (((K[4] > Thrustallocation_test_P.C[16]) && (K[4] <
               Thrustallocation_test_P.C[22]) && (Thrustallocation_test_B.fmin[4]
    > 0.0)) || ((K[4] > Thrustallocation_test_P.C[16]) && (K[4] <
               Thrustallocation_test_P.C[22]) && (Thrustallocation_test_B.fmin[4]
    < 0.0))) {
    /* '<S11>:1:97' */
    /* '<S11>:1:98' */
    c1[0] = Thrustallocation_test_P.C[16];
    c1[1] = Thrustallocation_test_P.C[22];
    c1_1[0] = Thrustallocation_test_P.C[16] - K[4];
    c1_1[1] = Thrustallocation_test_P.C[22] - K[4];
    Thrustallocation_test_abs(c1_1, varargin_1);
    ixstart = 1;
    b_signal = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          b_signal = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < b_signal)) {
      i = 1;
    }

    /* '<S11>:1:100' */
    Alpha1_idx_4 = c1[i];
  } else {
    /* '<S11>:1:102' */
    Alpha1_idx_4 = K[4];
  }

  /* % Thruster 6 OK 13.05/16 */
  /* C6 = [98.75 81.75 145.8 127.2]; */
  if (((K[5] < Thrustallocation_test_P.C[5]) && (K[5] >
        Thrustallocation_test_P.C[11]) && (Thrustallocation_test_B.fmin[5] > 0.0))
      || ((K[5] < Thrustallocation_test_P.C[5]) && (K[5] >
        Thrustallocation_test_P.C[11]) && (Thrustallocation_test_B.fmin[5] < 0.0)))
  {
    /* '<S11>:1:112' */
    /* '<S11>:1:113' */
    c1[0] = Thrustallocation_test_P.C[5];
    c1[1] = Thrustallocation_test_P.C[11];
    c1_0[0] = Thrustallocation_test_P.C[5] - K[5];
    c1_0[1] = Thrustallocation_test_P.C[11] - K[5];
    Thrustallocation_test_abs(c1_0, varargin_1);
    ixstart = 1;
    b_signal = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          b_signal = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < b_signal)) {
      i = 1;
    }

    /* '<S11>:1:115' */
    Alpha1_idx_5 = c1[i];
  } else if (((K[5] < Thrustallocation_test_P.C[17]) && (K[5] >
               Thrustallocation_test_P.C[23]) && (Thrustallocation_test_B.fmin[5]
    > 0.0)) || ((K[5] < Thrustallocation_test_P.C[17]) && (K[5] >
               Thrustallocation_test_P.C[23]) && (Thrustallocation_test_B.fmin[5]
    < 0.0))) {
    /* '<S11>:1:116' */
    /* '<S11>:1:117' */
    c1[0] = Thrustallocation_test_P.C[17];
    c1[1] = Thrustallocation_test_P.C[23];
    c1_0[0] = Thrustallocation_test_P.C[17] - K[5];
    c1_0[1] = Thrustallocation_test_P.C[23] - K[5];
    Thrustallocation_test_abs(c1_0, varargin_1);
    ixstart = 1;
    b_signal = varargin_1[0];
    i = 0;
    if (rtIsNaN(varargin_1[0])) {
      b_ixstart = 2;
      exitg11 = false;
      while ((!exitg11) && (b_ixstart < 3)) {
        ixstart = 2;
        if (!rtIsNaN(varargin_1[1])) {
          b_signal = varargin_1[1];
          i = 1;
          exitg11 = true;
        } else {
          b_ixstart = 3;
        }
      }
    }

    if ((ixstart < 2) && (varargin_1[1] < b_signal)) {
      i = 1;
    }

    /* '<S11>:1:119' */
    Alpha1_idx_5 = c1[i];
  } else {
    /* '<S11>:1:121' */
    Alpha1_idx_5 = K[5];
  }

  /*  Thruster 2&3  */
  if (Alpha1_idx_1 == Thrustallocation_test_P.C[7]) {
    /* '<S11>:1:130' */
    /* '<S11>:1:131' */
    Alpha1_idx_2 = K[1] - (Thrustallocation_test_P.C[7] - K[1]);
  } else if (Alpha1_idx_1 == Thrustallocation_test_P.C[1]) {
    /* '<S11>:1:132' */
    /* '<S11>:1:133' */
    Alpha1_idx_2 = K[1] - (Thrustallocation_test_P.C[1] - K[1]);
  } else if (Alpha1_idx_1 == Thrustallocation_test_P.C[13]) {
    /* '<S11>:1:134' */
    /* '<S11>:1:135' */
    Alpha1_idx_2 = K[1] - (Thrustallocation_test_P.C[13] - K[1]);
  } else if (Alpha1_idx_1 == Thrustallocation_test_P.C[19]) {
    /* '<S11>:1:136' */
    /* '<S11>:1:137' */
    Alpha1_idx_2 = K[1] - (Thrustallocation_test_P.C[19] - K[1]);
  } else if (Alpha1_idx_2 == Thrustallocation_test_P.C[8]) {
    /* '<S11>:1:139' */
    /* '<S11>:1:140' */
    Alpha1_idx_1 = K[2] - (Thrustallocation_test_P.C[8] - K[2]);
  } else if (Alpha1_idx_2 == Thrustallocation_test_P.C[2]) {
    /* '<S11>:1:141' */
    /* '<S11>:1:142' */
    Alpha1_idx_1 = K[2] - (Thrustallocation_test_P.C[2] - K[2]);
  } else if (Alpha1_idx_2 == Thrustallocation_test_P.C[14]) {
    /* '<S11>:1:143' */
    /* '<S11>:1:144' */
    Alpha1_idx_1 = K[2] - (Thrustallocation_test_P.C[14] - K[2]);
  } else {
    if (Alpha1_idx_2 == Thrustallocation_test_P.C[20]) {
      /* '<S11>:1:145' */
      /* '<S11>:1:146' */
      Alpha1_idx_1 = K[2] - (Thrustallocation_test_P.C[20] - K[2]);
    }
  }

  /*  Thruster 5&6 */
  if (Alpha1_idx_4 == Thrustallocation_test_P.C[10]) {
    /* '<S11>:1:150' */
    /* '<S11>:1:151' */
    Alpha1_idx_5 = K[4] - (Thrustallocation_test_P.C[10] - K[4]);
  } else if (Alpha1_idx_4 == Thrustallocation_test_P.C[4]) {
    /* '<S11>:1:152' */
    /* '<S11>:1:153' */
    Alpha1_idx_5 = K[4] - (Thrustallocation_test_P.C[4] - K[4]);
  } else if (Alpha1_idx_4 == Thrustallocation_test_P.C[16]) {
    /* '<S11>:1:154' */
    /* '<S11>:1:155' */
    Alpha1_idx_5 = K[4] - (Thrustallocation_test_P.C[16] - K[4]);
  } else if (Alpha1_idx_4 == Thrustallocation_test_P.C[22]) {
    /* '<S11>:1:156' */
    /* '<S11>:1:157' */
    Alpha1_idx_5 = K[4] - (Thrustallocation_test_P.C[22] - K[4]);
  } else if (Alpha1_idx_5 == Thrustallocation_test_P.C[11]) {
    /* '<S11>:1:159' */
    /* '<S11>:1:160' */
    Alpha1_idx_4 = K[5] - (Thrustallocation_test_P.C[11] - K[5]);
  } else if (Alpha1_idx_5 == Thrustallocation_test_P.C[5]) {
    /* '<S11>:1:161' */
    /* '<S11>:1:162' */
    Alpha1_idx_4 = K[5] - (Thrustallocation_test_P.C[5] - K[5]);
  } else if (Alpha1_idx_5 == Thrustallocation_test_P.C[17]) {
    /* '<S11>:1:163' */
    /* '<S11>:1:164' */
    Alpha1_idx_4 = K[5] - (Thrustallocation_test_P.C[17] - K[5]);
  } else {
    if (Alpha1_idx_5 == Thrustallocation_test_P.C[23]) {
      /* '<S11>:1:165' */
      /* '<S11>:1:166' */
      Alpha1_idx_4 = K[5] - (Thrustallocation_test_P.C[23] - K[5]);
    }
  }

  /*  Thruster 4 & 1 */
  if (Alpha1_idx_3 == Thrustallocation_test_P.C[9]) {
    /* '<S11>:1:169' */
    /* '<S11>:1:170' */
    Alpha1_idx_0 = K[3] - (Thrustallocation_test_P.C[9] - K[3]);
  } else if (Alpha1_idx_3 == Thrustallocation_test_P.C[3]) {
    /* '<S11>:1:171' */
    /* '<S11>:1:172' */
    Alpha1_idx_0 = K[3] - (Thrustallocation_test_P.C[3] - K[3]);
  } else if (Alpha1_idx_3 == Thrustallocation_test_P.C[15]) {
    /* '<S11>:1:173' */
    /* '<S11>:1:174' */
    Alpha1_idx_0 = K[3] - (Thrustallocation_test_P.C[15] - K[3]);
  } else {
    if (Alpha1_idx_3 == Thrustallocation_test_P.C[21]) {
      /* '<S11>:1:175' */
      /* '<S11>:1:176' */
      Alpha1_idx_0 = K[3] - (Thrustallocation_test_P.C[21] - K[3]);
    }
  }

  if (Alpha1_idx_0 == Thrustallocation_test_P.C[6]) {
    /* '<S11>:1:179' */
    /* '<S11>:1:180' */
    Alpha1_idx_3 = K[0] - (Thrustallocation_test_P.C[6] - K[0]);
  } else if (Alpha1_idx_0 == Thrustallocation_test_P.C[0]) {
    /* '<S11>:1:181' */
    /* '<S11>:1:182' */
    Alpha1_idx_3 = K[0] - (Thrustallocation_test_P.C[0] - K[0]);
  } else if (Alpha1_idx_0 == Thrustallocation_test_P.C[12]) {
    /* '<S11>:1:183' */
    /* '<S11>:1:184' */
    Alpha1_idx_3 = K[0] - (Thrustallocation_test_P.C[12] - K[0]);
  } else {
    if (Alpha1_idx_0 == Thrustallocation_test_P.C[18]) {
      /* '<S11>:1:185' */
      /* '<S11>:1:186' */
      Alpha1_idx_3 = K[0] - (Thrustallocation_test_P.C[18] - K[0]);
    }
  }

  /* Switch: '<S4>/Choosing Fixed // Azimuth angle' incorporates:
   *  Constant: '<S4>/constant angle'
   *  MATLAB Function: '<S4>/MATLAB Function2'
   */
  /* '<S11>:1:189' */
  if (Thrustallocation_test_B.Angle_controller >=
      Thrustallocation_test_P.ChoosingFixedAzimuthangle_Thres) {
    Thrustallocation_test_B.ChoosingFixedAzimuthangle[0] = Alpha1_idx_0;
    Thrustallocation_test_B.ChoosingFixedAzimuthangle[1] = Alpha1_idx_1;
    Thrustallocation_test_B.ChoosingFixedAzimuthangle[2] = Alpha1_idx_2;
    Thrustallocation_test_B.ChoosingFixedAzimuthangle[3] = Alpha1_idx_3;
    Thrustallocation_test_B.ChoosingFixedAzimuthangle[4] = Alpha1_idx_4;
    Thrustallocation_test_B.ChoosingFixedAzimuthangle[5] = Alpha1_idx_5;
  } else {
    Thrustallocation_test_B.ChoosingFixedAzimuthangle[0] =
      Thrustallocation_test_P.constantangle_Value[0];
    Thrustallocation_test_B.ChoosingFixedAzimuthangle[1] =
      Thrustallocation_test_P.constantangle_Value[1];
    Thrustallocation_test_B.ChoosingFixedAzimuthangle[2] =
      Thrustallocation_test_P.constantangle_Value[2];
    Thrustallocation_test_B.ChoosingFixedAzimuthangle[3] =
      Thrustallocation_test_P.constantangle_Value[3];
    Thrustallocation_test_B.ChoosingFixedAzimuthangle[4] =
      Thrustallocation_test_P.constantangle_Value[4];
    Thrustallocation_test_B.ChoosingFixedAzimuthangle[5] =
      Thrustallocation_test_P.constantangle_Value[5];
  }

  /* End of Switch: '<S4>/Choosing Fixed // Azimuth angle' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
  }

  /* Outputs for Iterator SubSystem: '<S4>/Optimal angle path and  constraints on rotation speed' incorporates:
   *  ForEach: '<S12>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
    /* ForEachSliceSelector: '<S12>/ImpSel_InsertedFor_reset_at_outport_0' */
    rtb_ImpSel_InsertedFor_reset_at =
      Thrustallocation_test_B.reset_c[ForEach_itr];
    if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
      /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
       *  Constant: '<S4>/constant angle'
       *  ForEachSliceSelector: '<S12>/ImpSel_InsertedFor_initial angle _at_outport_0'
       */
      if (Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
          DiscreteTimeIntegrator_IC_LOADI != 0) {
        Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
          DiscreteTimeIntegrator_DSTATE =
          Thrustallocation_test_P.constantangle_Value[ForEach_itr];
      }

      if (((rtb_ImpSel_InsertedFor_reset_at > 0.0) &&
           (Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
            DiscreteTimeIntegrator_PrevRese <= 0)) ||
          ((rtb_ImpSel_InsertedFor_reset_at <= 0.0) &&
           (Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
            DiscreteTimeIntegrator_PrevRese == 1))) {
        Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
          DiscreteTimeIntegrator_DSTATE =
          Thrustallocation_test_P.constantangle_Value[ForEach_itr];
      }

      Thrustallocation_test_B.CoreSubsys[ForEach_itr].angle =
        Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
        DiscreteTimeIntegrator_DSTATE;

      /* End of DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */

      /* Gain: '<S15>/Gain1' */
      b_signal = Thrustallocation_test_P.CoreSubsys.Gain1_Gain *
        Thrustallocation_test_B.CoreSubsys[ForEach_itr].angle;

      /* Delay: '<S12>/Delay' */
      Thrustallocation_test_B.CoreSubsys[ForEach_itr].Delay =
        Thrustallocation_test_DW.CoreSubsys[ForEach_itr].Delay_DSTATE;

      /* MATLAB Function: '<S12>/MATLAB Function' */
      /* MATLAB Function 'Thrust allocation/Optimal angle path and  constraints on rotation speed/MATLAB Function': '<S16>:1' */
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
      /* '<S16>:1:39' */
      /* '<S16>:1:40' */
      /*  s = sign(angle); */
      /* '<S16>:1:43' */
      u = fabs(rt_remd_snf(b_signal + 3.1415926535897931, 6.2831853071795862) /
               6.2831853071795862);
      if (b_signal < 0.0) {
        Alpha1_idx_5 = -1.0;
      } else if (b_signal > 0.0) {
        Alpha1_idx_5 = 1.0;
      } else if (b_signal == 0.0) {
        Alpha1_idx_5 = 0.0;
      } else {
        Alpha1_idx_5 = b_signal;
      }

      if (u > 0.0) {
        u = 1.0;
      } else {
        if (u == 0.0) {
          u = 0.0;
        }
      }

      u = (u - 1.0) * 2.0 + Alpha1_idx_5;
      if (b_signal < 0.0) {
        Alpha1_idx_5 = -1.0;
      } else if (b_signal > 0.0) {
        Alpha1_idx_5 = 1.0;
      } else if (b_signal == 0.0) {
        Alpha1_idx_5 = 0.0;
      } else {
        Alpha1_idx_5 = b_signal;
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

      lambda_c = rt_remd_snf(Alpha1_idx_5 * 3.1415926535897931 + b_signal,
        6.2831853071795862) - u * 3.1415926535897931;

      /* End of MATLAB Function: '<S12>/MATLAB Function' */
    }

    /* MATLAB Function: '<S12>/MATLAB Function1' incorporates:
     *  ForEachSliceSelector: '<S12>/ImpSel_InsertedFor_Desired Angle_at_outport_0'
     */
    /* MATLAB Function 'Thrust allocation/Optimal angle path and  constraints on rotation speed/MATLAB Function1': '<S17>:1' */
    /* '<S17>:1:3' */
    b_signal = Thrustallocation_test_B.ChoosingFixedAzimuthangle[ForEach_itr] -
      Thrustallocation_test_B.CoreSubsys[ForEach_itr].Delay;
    if (fabs(b_signal) >= 360.0) {
      /* '<S17>:1:4' */
      /* '<S17>:1:5' */
      b_signal = rt_remd_snf(b_signal, 360.0);
    }

    if (fabs(b_signal) >= 180.0) {
      /* '<S17>:1:8' */
      /* '<S17>:1:9' */
      if (b_signal < 0.0) {
        Alpha1_idx_5 = -1.0;
      } else if (b_signal > 0.0) {
        Alpha1_idx_5 = 1.0;
      } else if (b_signal == 0.0) {
        Alpha1_idx_5 = 0.0;
      } else {
        Alpha1_idx_5 = b_signal;
      }

      b_signal -= Alpha1_idx_5 * 360.0;
    }

    /* End of MATLAB Function: '<S12>/MATLAB Function1' */

    /* Saturate: '<S12>/Max Rotation Rate' */
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
    if (b_signal > Thrustallocation_test_P.Max_rotation) {
      Thrustallocation_test_B.CoreSubsys[ForEach_itr].MaxRotationRate =
        Thrustallocation_test_P.Max_rotation;
    } else if (b_signal < -Thrustallocation_test_P.Max_rotation) {
      Thrustallocation_test_B.CoreSubsys[ForEach_itr].MaxRotationRate =
        -Thrustallocation_test_P.Max_rotation;
    } else {
      Thrustallocation_test_B.CoreSubsys[ForEach_itr].MaxRotationRate = b_signal;
    }

    /* End of Saturate: '<S12>/Max Rotation Rate' */
    if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
      /* ForEachSliceAssignment: '<S12>/ImpAsg_InsertedFor_Out2 _at_inport_0' */
      rtb_ImpAsg_InsertedFor_Out2_at_[ForEach_itr] = lambda_c;
    }
  }

  /* End of Outputs for SubSystem: '<S4>/Optimal angle path and  constraints on rotation speed' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Saturate: '<S18>/Saturation 6' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[5] >
        Thrustallocation_test_P.Saturation6_UpperSat) {
      rtb_Sum_k = Thrustallocation_test_P.Saturation6_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[5] <
               Thrustallocation_test_P.Saturation6_LowerSat) {
      rtb_Sum_k = Thrustallocation_test_P.Saturation6_LowerSat;
    } else {
      rtb_Sum_k = rtb_ImpAsg_InsertedFor_Out2_at_[5];
    }

    /* End of Saturate: '<S18>/Saturation 6' */

    /* Saturate: '<S18>/Saturation 1' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[0] >
        Thrustallocation_test_P.Saturation1_UpperSat) {
      Alpha1_idx_5 = Thrustallocation_test_P.Saturation1_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[0] <
               Thrustallocation_test_P.Saturation1_LowerSat) {
      Alpha1_idx_5 = Thrustallocation_test_P.Saturation1_LowerSat;
    } else {
      Alpha1_idx_5 = rtb_ImpAsg_InsertedFor_Out2_at_[0];
    }

    /* Gain: '<S3>/Gain' incorporates:
     *  Saturate: '<S18>/Saturation 1'
     */
    Thrustallocation_test_B.Gain[0] = Thrustallocation_test_P.Gain_Gain_c *
      Alpha1_idx_5;

    /* Saturate: '<S18>/Saturation 2' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[1] >
        Thrustallocation_test_P.Saturation2_UpperSat) {
      Alpha1_idx_5 = Thrustallocation_test_P.Saturation2_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[1] <
               Thrustallocation_test_P.Saturation2_LowerSat) {
      Alpha1_idx_5 = Thrustallocation_test_P.Saturation2_LowerSat;
    } else {
      Alpha1_idx_5 = rtb_ImpAsg_InsertedFor_Out2_at_[1];
    }

    /* Gain: '<S3>/Gain' incorporates:
     *  Saturate: '<S18>/Saturation 2'
     */
    Thrustallocation_test_B.Gain[1] = Thrustallocation_test_P.Gain_Gain_c *
      Alpha1_idx_5;

    /* Saturate: '<S18>/Saturation 3' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[2] >
        Thrustallocation_test_P.Saturation3_UpperSat) {
      Alpha1_idx_5 = Thrustallocation_test_P.Saturation3_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[2] <
               Thrustallocation_test_P.Saturation3_LowerSat) {
      Alpha1_idx_5 = Thrustallocation_test_P.Saturation3_LowerSat;
    } else {
      Alpha1_idx_5 = rtb_ImpAsg_InsertedFor_Out2_at_[2];
    }

    /* Gain: '<S3>/Gain' incorporates:
     *  Saturate: '<S18>/Saturation 3'
     */
    Thrustallocation_test_B.Gain[2] = Thrustallocation_test_P.Gain_Gain_c *
      Alpha1_idx_5;

    /* Saturate: '<S18>/Saturation 4' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[3] >
        Thrustallocation_test_P.Saturation4_UpperSat) {
      Alpha1_idx_5 = Thrustallocation_test_P.Saturation4_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[3] <
               Thrustallocation_test_P.Saturation4_LowerSat) {
      Alpha1_idx_5 = Thrustallocation_test_P.Saturation4_LowerSat;
    } else {
      Alpha1_idx_5 = rtb_ImpAsg_InsertedFor_Out2_at_[3];
    }

    /* Gain: '<S3>/Gain' incorporates:
     *  Saturate: '<S18>/Saturation 4'
     */
    Thrustallocation_test_B.Gain[3] = Thrustallocation_test_P.Gain_Gain_c *
      Alpha1_idx_5;

    /* Saturate: '<S18>/Saturation 5' */
    if (rtb_ImpAsg_InsertedFor_Out2_at_[4] >
        Thrustallocation_test_P.Saturation5_UpperSat) {
      Alpha1_idx_5 = Thrustallocation_test_P.Saturation5_UpperSat;
    } else if (rtb_ImpAsg_InsertedFor_Out2_at_[4] <
               Thrustallocation_test_P.Saturation5_LowerSat) {
      Alpha1_idx_5 = Thrustallocation_test_P.Saturation5_LowerSat;
    } else {
      Alpha1_idx_5 = rtb_ImpAsg_InsertedFor_Out2_at_[4];
    }

    /* Gain: '<S3>/Gain' incorporates:
     *  Saturate: '<S18>/Saturation 5'
     */
    Thrustallocation_test_B.Gain[4] = Thrustallocation_test_P.Gain_Gain_c *
      Alpha1_idx_5;
    Thrustallocation_test_B.Gain[5] = Thrustallocation_test_P.Gain_Gain_c *
      rtb_Sum_k;
  }

  /* MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */
  /* MATLAB Function 'Finding commanded forces in: [Surge,Sway,Yaw]': '<S1>:1' */
  /* '<S1>:1:4' */
  /* '<S1>:1:5' */
  /* '<S1>:1:6' */
  /* '<S1>:1:10' */
  Thrustallocation_test_B.commanded_tau[0] = 0.0;
  Thrustallocation_test_B.commanded_tau[1] = 0.0;
  Thrustallocation_test_B.commanded_tau[2] = 0.0;
  b_signal = Thrustallocation_test_B.Gain[0];
  Thrustallocation_test_cosd(&b_signal);
  lambda_c = Thrustallocation_test_B.Gain[1];
  Thrustallocation_test_cosd(&lambda_c);
  Alpha1_idx_5 = Thrustallocation_test_B.Gain[2];
  Thrustallocation_test_cosd(&Alpha1_idx_5);
  Alpha1_idx_0 = Thrustallocation_test_B.Gain[3];
  Thrustallocation_test_cosd(&Alpha1_idx_0);
  Alpha1_idx_1 = Thrustallocation_test_B.Gain[4];
  Thrustallocation_test_cosd(&Alpha1_idx_1);
  Alpha1_idx_2 = Thrustallocation_test_B.Gain[5];
  Thrustallocation_test_cosd(&Alpha1_idx_2);
  Alpha1_idx_3 = Thrustallocation_test_B.Gain[0];
  Thrustallocation_test_sind(&Alpha1_idx_3);
  Alpha1_idx_4 = Thrustallocation_test_B.Gain[1];
  Thrustallocation_test_sind(&Alpha1_idx_4);
  j = Thrustallocation_test_B.Gain[2];
  Thrustallocation_test_sind(&j);
  k = Thrustallocation_test_B.Gain[3];
  Thrustallocation_test_sind(&k);
  l = Thrustallocation_test_B.Gain[4];
  Thrustallocation_test_sind(&l);
  m = Thrustallocation_test_B.Gain[5];
  Thrustallocation_test_sind(&m);
  n = Thrustallocation_test_B.Gain[0];
  Thrustallocation_test_sind(&n);
  o = Thrustallocation_test_B.Gain[0];
  Thrustallocation_test_cosd(&o);
  p = Thrustallocation_test_B.Gain[1];
  Thrustallocation_test_sind(&p);
  q = Thrustallocation_test_B.Gain[1];
  Thrustallocation_test_cosd(&q);
  r = Thrustallocation_test_B.Gain[2];
  Thrustallocation_test_sind(&r);
  s_1 = Thrustallocation_test_B.Gain[2];
  Thrustallocation_test_cosd(&s_1);
  t = Thrustallocation_test_B.Gain[3];
  Thrustallocation_test_sind(&t);
  u = Thrustallocation_test_B.Gain[3];
  Thrustallocation_test_cosd(&u);
  v = Thrustallocation_test_B.Gain[4];
  Thrustallocation_test_sind(&v);
  w = Thrustallocation_test_B.Gain[4];
  Thrustallocation_test_cosd(&w);
  x = Thrustallocation_test_B.Gain[5];
  Thrustallocation_test_sind(&x);
  y = Thrustallocation_test_B.Gain[5];
  Thrustallocation_test_cosd(&y);

  /* Saturate: '<S19>/Saturation 7' */
  tmp[0] = Thrustallocation_test_B.output[0];
  tmp[1] = Thrustallocation_test_B.output[2];
  tmp[2] = Thrustallocation_test_B.output[4];
  tmp[3] = Thrustallocation_test_B.output[6];
  tmp[4] = Thrustallocation_test_B.output[8];
  tmp[5] = Thrustallocation_test_B.output[10];

  /* MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' incorporates:
   *  Constant: '<Root>/X-position Thruster'
   *  Constant: '<Root>/Y-position Thruster'
   */
  b_signal_0[0] = b_signal;
  b_signal_0[3] = lambda_c;
  b_signal_0[6] = Alpha1_idx_5;
  b_signal_0[9] = Alpha1_idx_0;
  b_signal_0[12] = Alpha1_idx_1;
  b_signal_0[15] = Alpha1_idx_2;
  b_signal_0[1] = Alpha1_idx_3;
  b_signal_0[4] = Alpha1_idx_4;
  b_signal_0[7] = j;
  b_signal_0[10] = k;
  b_signal_0[13] = l;
  b_signal_0[16] = m;
  b_signal_0[2] = n * Thrustallocation_test_P.XpositionThruster_Value[0] - o *
    Thrustallocation_test_P.YpositionThruster_Value[0];
  b_signal_0[5] = p * Thrustallocation_test_P.XpositionThruster_Value[1] - q *
    Thrustallocation_test_P.YpositionThruster_Value[1];
  b_signal_0[8] = r * Thrustallocation_test_P.XpositionThruster_Value[2] - s_1 *
    Thrustallocation_test_P.YpositionThruster_Value[2];
  b_signal_0[11] = t * Thrustallocation_test_P.XpositionThruster_Value[3] - u *
    Thrustallocation_test_P.YpositionThruster_Value[3];
  b_signal_0[14] = v * Thrustallocation_test_P.XpositionThruster_Value[4] - w *
    Thrustallocation_test_P.YpositionThruster_Value[4];
  b_signal_0[17] = x * Thrustallocation_test_P.XpositionThruster_Value[5] - y *
    Thrustallocation_test_P.YpositionThruster_Value[5];

  /* Saturate: '<S19>/Saturation 7' incorporates:
   *  MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]'
   */
  for (i_0 = 0; i_0 < 6; i_0++) {
    if (tmp[i_0] > Thrustallocation_test_P.Max_thrust) {
      rtb_TmpSignalConversionAtSFu_la[i_0] = Thrustallocation_test_P.Max_thrust;
    } else if (tmp[i_0] < -Thrustallocation_test_P.Max_thrust) {
      rtb_TmpSignalConversionAtSFu_la[i_0] = -Thrustallocation_test_P.Max_thrust;
    } else {
      rtb_TmpSignalConversionAtSFu_la[i_0] = tmp[i_0];
    }
  }

  /* MATLAB Function: '<Root>/Finding commanded forces in: [Surge,Sway,Yaw]' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    Thrustallocation_test_B.commanded_tau[i_0] = 0.0;
    for (i = 0; i < 6; i++) {
      Thrustallocation_test_B.commanded_tau[i_0] += b_signal_0[3 * i + i_0] *
        rtb_TmpSignalConversionAtSFu_la[i];
    }
  }

  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Constant: '<Root>/Constant1' */
    Thrustallocation_test_B.Constant1[0] =
      Thrustallocation_test_P.Constant1_Value[0];
    Thrustallocation_test_B.Constant1[1] =
      Thrustallocation_test_P.Constant1_Value[1];
    Thrustallocation_test_B.Constant1[2] =
      Thrustallocation_test_P.Constant1_Value[2];
  }

  /* Integrator: '<Root>/Position' */
  if (Thrustallocation_test_DW.Position_IWORK.IcNeedsLoading) {
    Thrustallocation_test_X.Position_CSTATE[0] =
      Thrustallocation_test_B.Constant1[0];
    Thrustallocation_test_X.Position_CSTATE[1] =
      Thrustallocation_test_B.Constant1[1];
    Thrustallocation_test_X.Position_CSTATE[2] =
      Thrustallocation_test_B.Constant1[2];
  }

  rtb_Position[0] = Thrustallocation_test_X.Position_CSTATE[0];
  rtb_Position[1] = Thrustallocation_test_X.Position_CSTATE[1];
  rtb_Position[2] = Thrustallocation_test_X.Position_CSTATE[2];
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Delay: '<S5>/Delay' */
    for (i = 0; i < 6; i++) {
      Thrustallocation_test_B.Delay[i] = Thrustallocation_test_DW.Delay_DSTATE[i];
    }

    /* End of Delay: '<S5>/Delay' */

    /* Delay: '<S20>/Delay' */
    Thrustallocation_test_B.Delay_l = Thrustallocation_test_DW.Delay_DSTATE_l;

    /* Delay: '<S29>/Delay' */
    Thrustallocation_test_B.Delay_d = Thrustallocation_test_DW.Delay_DSTATE_g;
  }

  /* MATLAB Function: '<S29>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/MATLAB Function': '<S33>:1' */
  /* '<S33>:1:5' */
  if (Thrustallocation_test_B.fmin[0] < 0.0) {
    Alpha1_idx_5 = -1.0;
  } else if (Thrustallocation_test_B.fmin[0] > 0.0) {
    Alpha1_idx_5 = 1.0;
  } else if (Thrustallocation_test_B.fmin[0] == 0.0) {
    Alpha1_idx_5 = 0.0;
  } else {
    Alpha1_idx_5 = Thrustallocation_test_B.fmin[0];
  }

  b_signal = sqrt(fabs(Thrustallocation_test_B.fmin[0]) /
                  (Thrustallocation_test_P.Rho * rt_powd_snf
                   (Thrustallocation_test_P.D, 4.0) * Thrustallocation_test_P.Kt))
    * Alpha1_idx_5;

  /* '<S33>:1:7' */
  lambda_c = tanh(Thrustallocation_test_P.eps_c * b_signal / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S33>:1:8' */
  /* '<S33>:1:10' */
  if (Thrustallocation_test_B.Delay_d < 0.0) {
    Alpha1_idx_5 = -1.0;
  } else if (Thrustallocation_test_B.Delay_d > 0.0) {
    Alpha1_idx_5 = 1.0;
  } else if (Thrustallocation_test_B.Delay_d == 0.0) {
    Alpha1_idx_5 = 0.0;
  } else {
    Alpha1_idx_5 = Thrustallocation_test_B.Delay_d;
  }

  rtb_T_r_c = ((1.0 - lambda_c) * Thrustallocation_test_P.Ktr +
               Thrustallocation_test_P.Kt * lambda_c) * Alpha1_idx_5 *
    Thrustallocation_test_P.Rho * rt_powd_snf(Thrustallocation_test_P.D, 4.0) *
    (Thrustallocation_test_B.Delay_d * Thrustallocation_test_B.Delay_d);
  Thrustallocation_test_B.n_d_d = b_signal;

  /* End of MATLAB Function: '<S29>/MATLAB Function' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S29>/Constant1'
     *  Constant: '<S29>/Constant2'
     */
    Thrustallocation_test_DW.DiscreteTransferFcn_tmp =
      (Thrustallocation_test_B.n_d_d - Thrustallocation_test_P.Constant2_Value[1]
       * Thrustallocation_test_DW.DiscreteTransferFcn_states[0]) -
      Thrustallocation_test_P.Constant2_Value[2] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states[1];
    Thrustallocation_test_B.DiscreteTransferFcn =
      (Thrustallocation_test_P.Constant1_Value_i[0] *
       Thrustallocation_test_DW.DiscreteTransferFcn_tmp +
       Thrustallocation_test_P.Constant1_Value_i[1] *
       Thrustallocation_test_DW.DiscreteTransferFcn_states[0]) +
      Thrustallocation_test_P.Constant1_Value_i[2] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states[1];

    /* SampleTimeMath: '<S32>/TSamp'
     *
     * About '<S32>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    Thrustallocation_test_B.TSamp = Thrustallocation_test_B.DiscreteTransferFcn *
      Thrustallocation_test_P.TSamp_WtEt;

    /* Sum: '<S32>/Diff' incorporates:
     *  UnitDelay: '<S32>/UD'
     */
    rtb_Sum_k = Thrustallocation_test_B.TSamp -
      Thrustallocation_test_DW.UD_DSTATE;

    /* RateLimiter: '<S29>/Acceleration Limit' */
    b_signal = rtb_Sum_k - Thrustallocation_test_DW.PrevY;
    if (b_signal > Thrustallocation_test_P.AccelerationLimit_RisingLim) {
      rtb_Sum_k = Thrustallocation_test_DW.PrevY +
        Thrustallocation_test_P.AccelerationLimit_RisingLim;
    } else {
      if (b_signal < Thrustallocation_test_P.AccelerationLimit_FallingLim) {
        rtb_Sum_k = Thrustallocation_test_DW.PrevY +
          Thrustallocation_test_P.AccelerationLimit_FallingLim;
      }
    }

    Thrustallocation_test_DW.PrevY = rtb_Sum_k;

    /* End of RateLimiter: '<S29>/Acceleration Limit' */

    /* Gain: '<S29>/Inertia compensation' */
    Thrustallocation_test_B.Inertiacompensation = Thrustallocation_test_P.I_s *
      2.0 * 3.1415926535897931 * rtb_Sum_k;

    /* Sum: '<S29>/Sum1' incorporates:
     *  Gain: '<S29>/Qf_0'
     *  Gain: '<S29>/Qff_0(nr)'
     *  Gain: '<S29>/Qff_1(nr)'
     *  Trigonometry: '<S29>/Trigonometric Function'
     */
    Thrustallocation_test_B.Sum1 = tanh(Thrustallocation_test_P.epsilon /
      Thrustallocation_test_P.n_max *
      Thrustallocation_test_B.DiscreteTransferFcn) *
      Thrustallocation_test_P.Q_f0 + Thrustallocation_test_P.K_omega * 2.0 *
      3.1415926535897931 * Thrustallocation_test_B.DiscreteTransferFcn;

    /* Memory: '<S29>/Memory' */
    Thrustallocation_test_B.Memory_f =
      Thrustallocation_test_DW.Memory_PreviousInput_d;

    /* Sum: '<S31>/Sum' */
    rtb_Sum_k = Thrustallocation_test_B.DiscreteTransferFcn -
      Thrustallocation_test_B.Delay[0];

    /* Gain: '<S31>/Kp' */
    Thrustallocation_test_B.Kp = Thrustallocation_test_P.Kp * rtb_Sum_k;
  }

  /* Integrator: '<S31>/Integrator' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_c,
                       Thrustallocation_test_B.reset_j);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Thrustallocation_test_X.Integrator_CSTATE_j =
        Thrustallocation_test_P.Integrator_IC_p;
    }
  }

  rtb_Integrator_m = Thrustallocation_test_X.Integrator_CSTATE_j;

  /* MATLAB Function: '<S31>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kq'
   *  Constant: '<S2>/Kqr'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  CorecontrollerTorquePowerandCom(Thrustallocation_test_P.k_cc,
    Thrustallocation_test_P.p_cc, Thrustallocation_test_P.r_cc,
    Thrustallocation_test_B.Delay[0], Thrustallocation_test_P.Kt,
    Thrustallocation_test_P.Kq, Thrustallocation_test_P.D, rtb_T_r_c,
    Thrustallocation_test_P.eps, Thrustallocation_test_P.Rho,
    Thrustallocation_test_P.eps_c, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Kqr,
    &Thrustallocation_test_B.sf_CorecontrollerTorquePowerand);

  /* MultiPortSwitch: '<S29>/Controller chosen' incorporates:
   *  Constant: '<S29>/NaN'
   *  Sum: '<S31>/Sum1'
   */
  switch ((int32_T)Thrustallocation_test_B.Memory_f) {
   case 1:
    b_signal = Thrustallocation_test_B.Kp + rtb_Integrator_m;
    break;

   case 2:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowerand.Qcq;
    break;

   case 3:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowerand.Qcp;
    break;

   case 4:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowerand.Qcc;
    break;

   default:
    b_signal = Thrustallocation_test_P.NaN_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S29>/Controller chosen' */

  /* Sum: '<S29>/Sum' */
  Thrustallocation_test_B.Sum = (Thrustallocation_test_B.Inertiacompensation +
    Thrustallocation_test_B.Sum1) + b_signal;
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S20>/Constant'
     *  Constant: '<S20>/Constant1'
     */
    Thrustallocation_test_DW.DiscreteTransferFcn_tmp_d =
      Thrustallocation_test_B.Sum - Thrustallocation_test_P.Constant_Value[1] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_o;
    Thrustallocation_test_B.DiscreteTransferFcn_a =
      Thrustallocation_test_P.Constant1_Value_p[0] *
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_d +
      Thrustallocation_test_P.Constant1_Value_p[1] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_o;
  }

  /* Gain: '<S28>/Finding rotation speed' incorporates:
   *  Gain: '<S28>/K_omega'
   *  Sum: '<S28>/Sum'
   */
  Thrustallocation_test_B.Findingrotationspeed =
    ((Thrustallocation_test_B.DiscreteTransferFcn_a -
      Thrustallocation_test_B.Delay_l) - Thrustallocation_test_P.K_omega * 2.0 *
     3.1415926535897931 * rtb_Integrator) * (1.0 / (6.2831853071795862 *
    Thrustallocation_test_P.I_s));
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Gain: '<S31>/Ki' */
    Thrustallocation_test_B.Ki = Thrustallocation_test_P.Kp / 0.05 * rtb_Sum_k;
  }

  /* MATLAB Function: '<S29>/Supervisor' */
  Thrustallocation_tes_Supervisor(Thrustallocation_test_B.Memory_f,
    Thrustallocation_test_B.core_controller, Thrustallocation_test_B.Delay[0],
    &Thrustallocation_test_B.sf_Supervisor);
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Delay: '<S21>/Delay' */
    Thrustallocation_test_B.Delay_j = Thrustallocation_test_DW.Delay_DSTATE_c;

    /* Delay: '<S38>/Delay' */
    Thrustallocation_test_B.Delay_jf = Thrustallocation_test_DW.Delay_DSTATE_i;
  }

  /* MATLAB Function: '<S38>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  Thrustallocation_MATLABFunction(Thrustallocation_test_B.fmin[1],
    Thrustallocation_test_P.Kt, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Rho, Thrustallocation_test_P.D,
    Thrustallocation_test_P.eps_c, Thrustallocation_test_B.Delay_jf,
    &Thrustallocation_test_B.sf_MATLABFunction_a);
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S38>/Constant1'
     *  Constant: '<S38>/Constant2'
     */
    Thrustallocation_test_DW.DiscreteTransferFcn_tmp_l =
      (Thrustallocation_test_B.sf_MATLABFunction_a.n_d -
       Thrustallocation_test_P.Constant2_Value_a[1] *
       Thrustallocation_test_DW.DiscreteTransferFcn_states_f[0]) -
      Thrustallocation_test_P.Constant2_Value_a[2] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_f[1];
    Thrustallocation_test_B.DiscreteTransferFcn_d =
      (Thrustallocation_test_P.Constant1_Value_g[0] *
       Thrustallocation_test_DW.DiscreteTransferFcn_tmp_l +
       Thrustallocation_test_P.Constant1_Value_g[1] *
       Thrustallocation_test_DW.DiscreteTransferFcn_states_f[0]) +
      Thrustallocation_test_P.Constant1_Value_g[2] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_f[1];

    /* SampleTimeMath: '<S41>/TSamp'
     *
     * About '<S41>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    Thrustallocation_test_B.TSamp_d =
      Thrustallocation_test_B.DiscreteTransferFcn_d *
      Thrustallocation_test_P.TSamp_WtEt_j;

    /* Sum: '<S41>/Diff' incorporates:
     *  UnitDelay: '<S41>/UD'
     */
    rtb_Sum_k = Thrustallocation_test_B.TSamp_d -
      Thrustallocation_test_DW.UD_DSTATE_a;

    /* RateLimiter: '<S38>/Acceleration Limit' */
    b_signal = rtb_Sum_k - Thrustallocation_test_DW.PrevY_i;
    if (b_signal > Thrustallocation_test_P.AccelerationLimit_RisingLim_b) {
      rtb_Sum_k = Thrustallocation_test_DW.PrevY_i +
        Thrustallocation_test_P.AccelerationLimit_RisingLim_b;
    } else {
      if (b_signal < Thrustallocation_test_P.AccelerationLimit_FallingLim_f) {
        rtb_Sum_k = Thrustallocation_test_DW.PrevY_i +
          Thrustallocation_test_P.AccelerationLimit_FallingLim_f;
      }
    }

    Thrustallocation_test_DW.PrevY_i = rtb_Sum_k;

    /* End of RateLimiter: '<S38>/Acceleration Limit' */

    /* Gain: '<S38>/Inertia compensation' */
    Thrustallocation_test_B.Inertiacompensation_a = Thrustallocation_test_P.I_s *
      2.0 * 3.1415926535897931 * rtb_Sum_k;

    /* Sum: '<S38>/Sum1' incorporates:
     *  Gain: '<S38>/Qf_0'
     *  Gain: '<S38>/Qff_0(nr)'
     *  Gain: '<S38>/Qff_1(nr)'
     *  Trigonometry: '<S38>/Trigonometric Function'
     */
    Thrustallocation_test_B.Sum1_f = tanh(Thrustallocation_test_P.epsilon /
      Thrustallocation_test_P.n_max *
      Thrustallocation_test_B.DiscreteTransferFcn_d) *
      Thrustallocation_test_P.Q_f0 + Thrustallocation_test_P.K_omega * 2.0 *
      3.1415926535897931 * Thrustallocation_test_B.DiscreteTransferFcn_d;

    /* Memory: '<S38>/Memory' */
    Thrustallocation_test_B.Memory_a =
      Thrustallocation_test_DW.Memory_PreviousInput_c;

    /* Sum: '<S40>/Sum' */
    rtb_Sum_k = Thrustallocation_test_B.DiscreteTransferFcn_d -
      Thrustallocation_test_B.Delay[1];

    /* Gain: '<S40>/Kp' */
    Thrustallocation_test_B.Kp_c = Thrustallocation_test_P.Kp * rtb_Sum_k;
  }

  /* Integrator: '<S40>/Integrator' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_j,
                       Thrustallocation_test_B.reset_i);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Thrustallocation_test_X.Integrator_CSTATE_jg =
        Thrustallocation_test_P.Integrator_IC_o;
    }
  }

  rtb_Integrator_i0 = Thrustallocation_test_X.Integrator_CSTATE_jg;

  /* MATLAB Function: '<S40>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kq'
   *  Constant: '<S2>/Kqr'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  CorecontrollerTorquePowerandCom(Thrustallocation_test_P.k_cc,
    Thrustallocation_test_P.p_cc, Thrustallocation_test_P.r_cc,
    Thrustallocation_test_B.Delay[1], Thrustallocation_test_P.Kt,
    Thrustallocation_test_P.Kq, Thrustallocation_test_P.D,
    Thrustallocation_test_B.sf_MATLABFunction_a.T_r, Thrustallocation_test_P.eps,
    Thrustallocation_test_P.Rho, Thrustallocation_test_P.eps_c,
    Thrustallocation_test_P.Ktr, Thrustallocation_test_P.Kqr,
    &Thrustallocation_test_B.sf_CorecontrollerTorquePowera_g);

  /* MultiPortSwitch: '<S38>/Controller chosen' incorporates:
   *  Constant: '<S38>/NaN'
   *  Sum: '<S40>/Sum1'
   */
  switch ((int32_T)Thrustallocation_test_B.Memory_a) {
   case 1:
    b_signal = Thrustallocation_test_B.Kp_c + rtb_Integrator_i0;
    break;

   case 2:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_g.Qcq;
    break;

   case 3:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_g.Qcp;
    break;

   case 4:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_g.Qcc;
    break;

   default:
    b_signal = Thrustallocation_test_P.NaN_Value_j;
    break;
  }

  /* End of MultiPortSwitch: '<S38>/Controller chosen' */

  /* Sum: '<S38>/Sum' */
  Thrustallocation_test_B.Sum_i = (Thrustallocation_test_B.Inertiacompensation_a
    + Thrustallocation_test_B.Sum1_f) + b_signal;
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* DiscreteTransferFcn: '<S21>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S21>/Constant'
     *  Constant: '<S21>/Constant1'
     */
    Thrustallocation_test_DW.DiscreteTransferFcn_tmp_c =
      Thrustallocation_test_B.Sum_i - Thrustallocation_test_P.Constant_Value_i[1]
      * Thrustallocation_test_DW.DiscreteTransferFcn_states_a;
    Thrustallocation_test_B.DiscreteTransferFcn_l =
      Thrustallocation_test_P.Constant1_Value_b[0] *
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_c +
      Thrustallocation_test_P.Constant1_Value_b[1] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_a;
  }

  /* Gain: '<S37>/Finding rotation speed' incorporates:
   *  Gain: '<S37>/K_omega'
   *  Sum: '<S37>/Sum'
   */
  Thrustallocation_test_B.Findingrotationspeed_k =
    ((Thrustallocation_test_B.DiscreteTransferFcn_l -
      Thrustallocation_test_B.Delay_j) - Thrustallocation_test_P.K_omega * 2.0 *
     3.1415926535897931 * rtb_Integrator_d) * (1.0 / (6.2831853071795862 *
    Thrustallocation_test_P.I_s));
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Gain: '<S40>/Ki' */
    Thrustallocation_test_B.Ki_h = Thrustallocation_test_P.Kp / 0.05 * rtb_Sum_k;
  }

  /* MATLAB Function: '<S38>/Supervisor' */
  Thrustallocation_tes_Supervisor(Thrustallocation_test_B.Memory_a,
    Thrustallocation_test_B.core_controller, Thrustallocation_test_B.Delay[1],
    &Thrustallocation_test_B.sf_Supervisor_p);
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Delay: '<S22>/Delay' */
    Thrustallocation_test_B.Delay_i = Thrustallocation_test_DW.Delay_DSTATE_p;

    /* Delay: '<S47>/Delay' */
    Thrustallocation_test_B.Delay_c = Thrustallocation_test_DW.Delay_DSTATE_f;
  }

  /* MATLAB Function: '<S47>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  Thrustallocation_MATLABFunction(Thrustallocation_test_B.fmin[2],
    Thrustallocation_test_P.Kt, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Rho, Thrustallocation_test_P.D,
    Thrustallocation_test_P.eps_c, Thrustallocation_test_B.Delay_c,
    &Thrustallocation_test_B.sf_MATLABFunction_da);
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* DiscreteTransferFcn: '<S47>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S47>/Constant1'
     *  Constant: '<S47>/Constant2'
     */
    Thrustallocation_test_DW.DiscreteTransferFcn_tmp_i =
      (Thrustallocation_test_B.sf_MATLABFunction_da.n_d -
       Thrustallocation_test_P.Constant2_Value_g[1] *
       Thrustallocation_test_DW.DiscreteTransferFcn_states_m[0]) -
      Thrustallocation_test_P.Constant2_Value_g[2] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_m[1];
    Thrustallocation_test_B.DiscreteTransferFcn_k =
      (Thrustallocation_test_P.Constant1_Value_h[0] *
       Thrustallocation_test_DW.DiscreteTransferFcn_tmp_i +
       Thrustallocation_test_P.Constant1_Value_h[1] *
       Thrustallocation_test_DW.DiscreteTransferFcn_states_m[0]) +
      Thrustallocation_test_P.Constant1_Value_h[2] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_m[1];

    /* SampleTimeMath: '<S50>/TSamp'
     *
     * About '<S50>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    Thrustallocation_test_B.TSamp_f =
      Thrustallocation_test_B.DiscreteTransferFcn_k *
      Thrustallocation_test_P.TSamp_WtEt_l;

    /* Sum: '<S50>/Diff' incorporates:
     *  UnitDelay: '<S50>/UD'
     */
    rtb_Sum_k = Thrustallocation_test_B.TSamp_f -
      Thrustallocation_test_DW.UD_DSTATE_j;

    /* RateLimiter: '<S47>/Acceleration limiter' */
    b_signal = rtb_Sum_k - Thrustallocation_test_DW.PrevY_o;
    if (b_signal > Thrustallocation_test_P.Accelerationlimiter_RisingLim) {
      rtb_Sum_k = Thrustallocation_test_DW.PrevY_o +
        Thrustallocation_test_P.Accelerationlimiter_RisingLim;
    } else {
      if (b_signal < Thrustallocation_test_P.Accelerationlimiter_FallingLim) {
        rtb_Sum_k = Thrustallocation_test_DW.PrevY_o +
          Thrustallocation_test_P.Accelerationlimiter_FallingLim;
      }
    }

    Thrustallocation_test_DW.PrevY_o = rtb_Sum_k;

    /* End of RateLimiter: '<S47>/Acceleration limiter' */

    /* Gain: '<S47>/Inertia compensation' */
    Thrustallocation_test_B.Inertiacompensation_j = Thrustallocation_test_P.I_s *
      2.0 * 3.1415926535897931 * rtb_Sum_k;

    /* Sum: '<S47>/Sum1' incorporates:
     *  Gain: '<S47>/Qf_0'
     *  Gain: '<S47>/Qff_0(nr)'
     *  Gain: '<S47>/Qff_1(nr)'
     *  Trigonometry: '<S47>/Trigonometric Function'
     */
    Thrustallocation_test_B.Sum1_b = tanh(Thrustallocation_test_P.epsilon /
      Thrustallocation_test_P.n_max *
      Thrustallocation_test_B.DiscreteTransferFcn_k) *
      Thrustallocation_test_P.Q_f0 + Thrustallocation_test_P.K_omega * 2.0 *
      3.1415926535897931 * Thrustallocation_test_B.DiscreteTransferFcn_k;

    /* Memory: '<S47>/Memory' */
    Thrustallocation_test_B.Memory_n =
      Thrustallocation_test_DW.Memory_PreviousInput_l;

    /* Sum: '<S49>/Sum' */
    rtb_Sum_k = Thrustallocation_test_B.DiscreteTransferFcn_k -
      Thrustallocation_test_B.Delay[2];

    /* Gain: '<S49>/Kp' */
    Thrustallocation_test_B.Kp_j = Thrustallocation_test_P.Kp * rtb_Sum_k;
  }

  /* Integrator: '<S49>/Integrator' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_d5,
                       Thrustallocation_test_B.reset_e3);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Thrustallocation_test_X.Integrator_CSTATE_e =
        Thrustallocation_test_P.Integrator_IC_pf;
    }
  }

  rtb_Integrator_b = Thrustallocation_test_X.Integrator_CSTATE_e;

  /* MATLAB Function: '<S49>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kq'
   *  Constant: '<S2>/Kqr'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  CorecontrollerTorquePowerandCom(Thrustallocation_test_P.k_cc,
    Thrustallocation_test_P.p_cc, Thrustallocation_test_P.r_cc,
    Thrustallocation_test_B.Delay[2], Thrustallocation_test_P.Kt,
    Thrustallocation_test_P.Kq, Thrustallocation_test_P.D,
    Thrustallocation_test_B.sf_MATLABFunction_da.T_r,
    Thrustallocation_test_P.eps, Thrustallocation_test_P.Rho,
    Thrustallocation_test_P.eps_c, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Kqr,
    &Thrustallocation_test_B.sf_CorecontrollerTorquePowera_j);

  /* MultiPortSwitch: '<S47>/Controller chosen' incorporates:
   *  Constant: '<S47>/NaN'
   *  Sum: '<S49>/Sum1'
   */
  switch ((int32_T)Thrustallocation_test_B.Memory_n) {
   case 1:
    b_signal = Thrustallocation_test_B.Kp_j + rtb_Integrator_b;
    break;

   case 2:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_j.Qcq;
    break;

   case 3:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_j.Qcp;
    break;

   case 4:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_j.Qcc;
    break;

   default:
    b_signal = Thrustallocation_test_P.NaN_Value_e;
    break;
  }

  /* End of MultiPortSwitch: '<S47>/Controller chosen' */

  /* Sum: '<S47>/Sum' */
  Thrustallocation_test_B.Sum_o = (Thrustallocation_test_B.Inertiacompensation_j
    + Thrustallocation_test_B.Sum1_b) + b_signal;
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     */
    Thrustallocation_test_DW.DiscreteTransferFcn_tmp_ll =
      Thrustallocation_test_B.Sum_o - Thrustallocation_test_P.Constant_Value_g[1]
      * Thrustallocation_test_DW.DiscreteTransferFcn_states_d;
    Thrustallocation_test_B.DiscreteTransferFcn_o =
      Thrustallocation_test_P.Constant1_Value_a[0] *
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_ll +
      Thrustallocation_test_P.Constant1_Value_a[1] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_d;
  }

  /* Gain: '<S46>/Finding rotation speed' incorporates:
   *  Gain: '<S46>/K_omega'
   *  Sum: '<S46>/Sum'
   */
  Thrustallocation_test_B.Findingrotationspeed_j =
    ((Thrustallocation_test_B.DiscreteTransferFcn_o -
      Thrustallocation_test_B.Delay_i) - Thrustallocation_test_P.K_omega * 2.0 *
     3.1415926535897931 * rtb_Integrator_g) * (1.0 / (6.2831853071795862 *
    Thrustallocation_test_P.I_s));
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Gain: '<S49>/Ki' */
    Thrustallocation_test_B.Ki_e = Thrustallocation_test_P.Kp / 0.05 * rtb_Sum_k;
  }

  /* MATLAB Function: '<S47>/Supervisor' */
  Thrustallocation_tes_Supervisor(Thrustallocation_test_B.Memory_n,
    Thrustallocation_test_B.core_controller, Thrustallocation_test_B.Delay[2],
    &Thrustallocation_test_B.sf_Supervisor_b);
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Delay: '<S23>/Delay' */
    Thrustallocation_test_B.Delay_g = Thrustallocation_test_DW.Delay_DSTATE_ce;

    /* Delay: '<S56>/Delay' */
    Thrustallocation_test_B.Delay_m = Thrustallocation_test_DW.Delay_DSTATE_h;
  }

  /* MATLAB Function: '<S56>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  Thrustallocation_MATLABFunction(Thrustallocation_test_B.fmin[3],
    Thrustallocation_test_P.Kt, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Rho, Thrustallocation_test_P.D,
    Thrustallocation_test_P.eps_c, Thrustallocation_test_B.Delay_m,
    &Thrustallocation_test_B.sf_MATLABFunction_f);
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* DiscreteTransferFcn: '<S56>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S56>/Constant1'
     *  Constant: '<S56>/Constant2'
     */
    Thrustallocation_test_DW.DiscreteTransferFcn_tmp_p =
      (Thrustallocation_test_B.sf_MATLABFunction_f.n_d -
       Thrustallocation_test_P.Constant2_Value_i[1] *
       Thrustallocation_test_DW.DiscreteTransferFcn_states_j[0]) -
      Thrustallocation_test_P.Constant2_Value_i[2] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_j[1];
    Thrustallocation_test_B.DiscreteTransferFcn_ox =
      (Thrustallocation_test_P.Constant1_Value_f[0] *
       Thrustallocation_test_DW.DiscreteTransferFcn_tmp_p +
       Thrustallocation_test_P.Constant1_Value_f[1] *
       Thrustallocation_test_DW.DiscreteTransferFcn_states_j[0]) +
      Thrustallocation_test_P.Constant1_Value_f[2] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_j[1];

    /* SampleTimeMath: '<S59>/TSamp'
     *
     * About '<S59>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    Thrustallocation_test_B.TSamp_j =
      Thrustallocation_test_B.DiscreteTransferFcn_ox *
      Thrustallocation_test_P.TSamp_WtEt_n;

    /* Sum: '<S59>/Diff' incorporates:
     *  UnitDelay: '<S59>/UD'
     */
    rtb_Sum_k = Thrustallocation_test_B.TSamp_j -
      Thrustallocation_test_DW.UD_DSTATE_c;

    /* RateLimiter: '<S56>/Acceleration limiter' */
    b_signal = rtb_Sum_k - Thrustallocation_test_DW.PrevY_a;
    if (b_signal > Thrustallocation_test_P.Accelerationlimiter_RisingLim_n) {
      rtb_Sum_k = Thrustallocation_test_DW.PrevY_a +
        Thrustallocation_test_P.Accelerationlimiter_RisingLim_n;
    } else {
      if (b_signal < Thrustallocation_test_P.Accelerationlimiter_FallingLi_o) {
        rtb_Sum_k = Thrustallocation_test_DW.PrevY_a +
          Thrustallocation_test_P.Accelerationlimiter_FallingLi_o;
      }
    }

    Thrustallocation_test_DW.PrevY_a = rtb_Sum_k;

    /* End of RateLimiter: '<S56>/Acceleration limiter' */

    /* Gain: '<S56>/Inertia compensation' */
    Thrustallocation_test_B.Inertiacompensation_jx = Thrustallocation_test_P.I_s
      * 2.0 * 3.1415926535897931 * rtb_Sum_k;

    /* Sum: '<S56>/Sum1' incorporates:
     *  Gain: '<S56>/Qf_0'
     *  Gain: '<S56>/Qff_0(nr)'
     *  Gain: '<S56>/Qff_1(nr)'
     *  Trigonometry: '<S56>/Trigonometric Function'
     */
    Thrustallocation_test_B.Sum1_k = tanh(Thrustallocation_test_P.epsilon /
      Thrustallocation_test_P.n_max *
      Thrustallocation_test_B.DiscreteTransferFcn_ox) *
      Thrustallocation_test_P.Q_f0 + Thrustallocation_test_P.K_omega * 2.0 *
      3.1415926535897931 * Thrustallocation_test_B.DiscreteTransferFcn_ox;

    /* Memory: '<S56>/Memory' */
    Thrustallocation_test_B.Memory_aw =
      Thrustallocation_test_DW.Memory_PreviousInput_a;

    /* Sum: '<S58>/Sum' */
    rtb_Sum_k = Thrustallocation_test_B.DiscreteTransferFcn_ox -
      Thrustallocation_test_B.Delay[3];

    /* Gain: '<S58>/Kp' */
    Thrustallocation_test_B.Kp_m = Thrustallocation_test_P.Kp * rtb_Sum_k;
  }

  /* Integrator: '<S58>/Integrator' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_p,
                       Thrustallocation_test_B.reset_j4);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Thrustallocation_test_X.Integrator_CSTATE_jz =
        Thrustallocation_test_P.Integrator_IC_f;
    }
  }

  rtb_Integrator_bu = Thrustallocation_test_X.Integrator_CSTATE_jz;

  /* MATLAB Function: '<S58>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kq'
   *  Constant: '<S2>/Kqr'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  CorecontrollerTorquePowerandCom(Thrustallocation_test_P.k_cc,
    Thrustallocation_test_P.p_cc, Thrustallocation_test_P.r_cc,
    Thrustallocation_test_B.Delay[3], Thrustallocation_test_P.Kt,
    Thrustallocation_test_P.Kq, Thrustallocation_test_P.D,
    Thrustallocation_test_B.sf_MATLABFunction_f.T_r, Thrustallocation_test_P.eps,
    Thrustallocation_test_P.Rho, Thrustallocation_test_P.eps_c,
    Thrustallocation_test_P.Ktr, Thrustallocation_test_P.Kqr,
    &Thrustallocation_test_B.sf_CorecontrollerTorquePowera_e);

  /* MultiPortSwitch: '<S56>/Controller chosen' incorporates:
   *  Constant: '<S56>/NaN'
   *  Sum: '<S58>/Sum1'
   */
  switch ((int32_T)Thrustallocation_test_B.Memory_aw) {
   case 1:
    b_signal = Thrustallocation_test_B.Kp_m + rtb_Integrator_bu;
    break;

   case 2:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_e.Qcq;
    break;

   case 3:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_e.Qcp;
    break;

   case 4:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_e.Qcc;
    break;

   default:
    b_signal = Thrustallocation_test_P.NaN_Value_o;
    break;
  }

  /* End of MultiPortSwitch: '<S56>/Controller chosen' */

  /* Sum: '<S56>/Sum' */
  Thrustallocation_test_B.Sum_j =
    (Thrustallocation_test_B.Inertiacompensation_jx +
     Thrustallocation_test_B.Sum1_k) + b_signal;
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S23>/Constant'
     *  Constant: '<S23>/Constant1'
     */
    Thrustallocation_test_DW.DiscreteTransferFcn_tmp_o =
      Thrustallocation_test_B.Sum_j - Thrustallocation_test_P.Constant_Value_j[1]
      * Thrustallocation_test_DW.DiscreteTransferFcn_states_e;
    Thrustallocation_test_B.DiscreteTransferFcn_c =
      Thrustallocation_test_P.Constant1_Value_bp[0] *
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_o +
      Thrustallocation_test_P.Constant1_Value_bp[1] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_e;
  }

  /* Gain: '<S55>/Finding rotation speed' incorporates:
   *  Gain: '<S55>/K_omega'
   *  Sum: '<S55>/Sum'
   */
  Thrustallocation_test_B.Findingrotationspeed_n =
    ((Thrustallocation_test_B.DiscreteTransferFcn_c -
      Thrustallocation_test_B.Delay_g) - Thrustallocation_test_P.K_omega * 2.0 *
     3.1415926535897931 * rtb_Integrator_i) * (1.0 / (6.2831853071795862 *
    Thrustallocation_test_P.I_s));
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Gain: '<S58>/Ki' */
    Thrustallocation_test_B.Ki_j = Thrustallocation_test_P.Kp / 0.05 * rtb_Sum_k;
  }

  /* MATLAB Function: '<S56>/Supervisor' */
  Thrustallocation_tes_Supervisor(Thrustallocation_test_B.Memory_aw,
    Thrustallocation_test_B.core_controller, Thrustallocation_test_B.Delay[3],
    &Thrustallocation_test_B.sf_Supervisor_m);
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Delay: '<S24>/Delay' */
    Thrustallocation_test_B.Delay_f = Thrustallocation_test_DW.Delay_DSTATE_m;

    /* Delay: '<S65>/Delay' */
    Thrustallocation_test_B.Delay_fl = Thrustallocation_test_DW.Delay_DSTATE_k;
  }

  /* MATLAB Function: '<S65>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  Thrustallocation_MATLABFunction(Thrustallocation_test_B.fmin[4],
    Thrustallocation_test_P.Kt, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Rho, Thrustallocation_test_P.D,
    Thrustallocation_test_P.eps_c, Thrustallocation_test_B.Delay_fl,
    &Thrustallocation_test_B.sf_MATLABFunction_h);
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* DiscreteTransferFcn: '<S65>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S65>/Constant1'
     *  Constant: '<S65>/Constant2'
     */
    Thrustallocation_test_DW.DiscreteTransferFcn_tmp_c3 =
      (Thrustallocation_test_B.sf_MATLABFunction_h.n_d -
       Thrustallocation_test_P.Constant2_Value_n[1] *
       Thrustallocation_test_DW.DiscreteTransferFcn_states_du[0]) -
      Thrustallocation_test_P.Constant2_Value_n[2] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_du[1];
    Thrustallocation_test_B.DiscreteTransferFcn_f =
      (Thrustallocation_test_P.Constant1_Value_e[0] *
       Thrustallocation_test_DW.DiscreteTransferFcn_tmp_c3 +
       Thrustallocation_test_P.Constant1_Value_e[1] *
       Thrustallocation_test_DW.DiscreteTransferFcn_states_du[0]) +
      Thrustallocation_test_P.Constant1_Value_e[2] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_du[1];

    /* SampleTimeMath: '<S68>/TSamp'
     *
     * About '<S68>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    Thrustallocation_test_B.TSamp_n =
      Thrustallocation_test_B.DiscreteTransferFcn_f *
      Thrustallocation_test_P.TSamp_WtEt_m;

    /* Sum: '<S68>/Diff' incorporates:
     *  UnitDelay: '<S68>/UD'
     */
    rtb_Sum_k = Thrustallocation_test_B.TSamp_n -
      Thrustallocation_test_DW.UD_DSTATE_n;

    /* RateLimiter: '<S65>/Acceleration limiter' */
    b_signal = rtb_Sum_k - Thrustallocation_test_DW.PrevY_m;
    if (b_signal > Thrustallocation_test_P.Accelerationlimiter_RisingLim_j) {
      rtb_Sum_k = Thrustallocation_test_DW.PrevY_m +
        Thrustallocation_test_P.Accelerationlimiter_RisingLim_j;
    } else {
      if (b_signal < Thrustallocation_test_P.Accelerationlimiter_FallingLi_i) {
        rtb_Sum_k = Thrustallocation_test_DW.PrevY_m +
          Thrustallocation_test_P.Accelerationlimiter_FallingLi_i;
      }
    }

    Thrustallocation_test_DW.PrevY_m = rtb_Sum_k;

    /* End of RateLimiter: '<S65>/Acceleration limiter' */

    /* Gain: '<S65>/Inertia compensation' */
    Thrustallocation_test_B.Inertiacompensation_o = Thrustallocation_test_P.I_s *
      2.0 * 3.1415926535897931 * rtb_Sum_k;

    /* Sum: '<S65>/Sum1' incorporates:
     *  Gain: '<S65>/Qf_0'
     *  Gain: '<S65>/Qff_0(nr)'
     *  Gain: '<S65>/Qff_1(nr)'
     *  Trigonometry: '<S65>/Trigonometric Function'
     */
    Thrustallocation_test_B.Sum1_c = tanh(Thrustallocation_test_P.epsilon /
      Thrustallocation_test_P.n_max *
      Thrustallocation_test_B.DiscreteTransferFcn_f) *
      Thrustallocation_test_P.Q_f0 + Thrustallocation_test_P.K_omega * 2.0 *
      3.1415926535897931 * Thrustallocation_test_B.DiscreteTransferFcn_f;

    /* Memory: '<S65>/Memory' */
    Thrustallocation_test_B.Memory_i =
      Thrustallocation_test_DW.Memory_PreviousInput_f;

    /* Sum: '<S67>/Sum' */
    rtb_Sum_k = Thrustallocation_test_B.DiscreteTransferFcn_f -
      Thrustallocation_test_B.Delay[4];

    /* Gain: '<S67>/Kp' */
    Thrustallocation_test_B.Kp_a = Thrustallocation_test_P.Kp * rtb_Sum_k;
  }

  /* Integrator: '<S67>/Integrator' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_l,
                       Thrustallocation_test_B.reset_p);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Thrustallocation_test_X.Integrator_CSTATE_ai =
        Thrustallocation_test_P.Integrator_IC_e2;
    }
  }

  rtb_Integrator_k = Thrustallocation_test_X.Integrator_CSTATE_ai;

  /* MATLAB Function: '<S67>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kq'
   *  Constant: '<S2>/Kqr'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  CorecontrollerTorquePowerandCom(Thrustallocation_test_P.k_cc,
    Thrustallocation_test_P.p_cc, Thrustallocation_test_P.r_cc,
    Thrustallocation_test_B.Delay[4], Thrustallocation_test_P.Kt,
    Thrustallocation_test_P.Kq, Thrustallocation_test_P.D,
    Thrustallocation_test_B.sf_MATLABFunction_h.T_r, Thrustallocation_test_P.eps,
    Thrustallocation_test_P.Rho, Thrustallocation_test_P.eps_c,
    Thrustallocation_test_P.Ktr, Thrustallocation_test_P.Kqr,
    &Thrustallocation_test_B.sf_CorecontrollerTorquePowera_i);

  /* MultiPortSwitch: '<S65>/Controller chosen' incorporates:
   *  Constant: '<S65>/NaN'
   *  Sum: '<S67>/Sum1'
   */
  switch ((int32_T)Thrustallocation_test_B.Memory_i) {
   case 1:
    b_signal = Thrustallocation_test_B.Kp_a + rtb_Integrator_k;
    break;

   case 2:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_i.Qcq;
    break;

   case 3:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_i.Qcp;
    break;

   case 4:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_i.Qcc;
    break;

   default:
    b_signal = Thrustallocation_test_P.NaN_Value_d;
    break;
  }

  /* End of MultiPortSwitch: '<S65>/Controller chosen' */

  /* Sum: '<S65>/Sum' */
  Thrustallocation_test_B.Sum_n = (Thrustallocation_test_B.Inertiacompensation_o
    + Thrustallocation_test_B.Sum1_c) + b_signal;
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S24>/Constant'
     *  Constant: '<S24>/Constant1'
     */
    Thrustallocation_test_DW.DiscreteTransferFcn_tmp_k =
      Thrustallocation_test_B.Sum_n - Thrustallocation_test_P.Constant_Value_k[1]
      * Thrustallocation_test_DW.DiscreteTransferFcn_states_fv;
    Thrustallocation_test_B.DiscreteTransferFcn_e =
      Thrustallocation_test_P.Constant1_Value_n[0] *
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_k +
      Thrustallocation_test_P.Constant1_Value_n[1] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_fv;
  }

  /* Gain: '<S64>/Finding rotation speed' incorporates:
   *  Gain: '<S64>/K_omega'
   *  Sum: '<S64>/Sum'
   */
  Thrustallocation_test_B.Findingrotationspeed_j0 =
    ((Thrustallocation_test_B.DiscreteTransferFcn_e -
      Thrustallocation_test_B.Delay_f) - Thrustallocation_test_P.K_omega * 2.0 *
     3.1415926535897931 * rtb_Integrator_dt) * (1.0 / (6.2831853071795862 *
    Thrustallocation_test_P.I_s));
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Gain: '<S67>/Ki' */
    Thrustallocation_test_B.Ki_jy = Thrustallocation_test_P.Kp / 0.05 *
      rtb_Sum_k;
  }

  /* MATLAB Function: '<S65>/Supervisor' */
  Thrustallocation_tes_Supervisor(Thrustallocation_test_B.Memory_i,
    Thrustallocation_test_B.core_controller, Thrustallocation_test_B.Delay[4],
    &Thrustallocation_test_B.sf_Supervisor_mw);
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Delay: '<S25>/Delay' */
    Thrustallocation_test_B.Delay_cn = Thrustallocation_test_DW.Delay_DSTATE_cy;

    /* Delay: '<S74>/Delay' */
    Thrustallocation_test_B.Delay_n = Thrustallocation_test_DW.Delay_DSTATE_n;
  }

  /* MATLAB Function: '<S74>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  /* MATLAB Function 'Thruster control /Thruster 6/Thruster control/MATLAB Function': '<S78>:1' */
  /* '<S78>:1:5' */
  if (Thrustallocation_test_B.fmin[5] < 0.0) {
    Alpha1_idx_5 = -1.0;
  } else if (Thrustallocation_test_B.fmin[5] > 0.0) {
    Alpha1_idx_5 = 1.0;
  } else if (Thrustallocation_test_B.fmin[5] == 0.0) {
    Alpha1_idx_5 = 0.0;
  } else {
    Alpha1_idx_5 = Thrustallocation_test_B.fmin[5];
  }

  b_signal = sqrt(fabs(Thrustallocation_test_B.fmin[5]) /
                  (Thrustallocation_test_P.Rho * rt_powd_snf
                   (Thrustallocation_test_P.D, 4.0) * Thrustallocation_test_P.Kt))
    * Alpha1_idx_5;

  /* '<S78>:1:7' */
  lambda_c = tanh(Thrustallocation_test_P.eps_c * b_signal / 27.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S78>:1:8' */
  /* '<S78>:1:10' */
  if (Thrustallocation_test_B.Delay_n < 0.0) {
    Alpha1_idx_5 = -1.0;
  } else if (Thrustallocation_test_B.Delay_n > 0.0) {
    Alpha1_idx_5 = 1.0;
  } else if (Thrustallocation_test_B.Delay_n == 0.0) {
    Alpha1_idx_5 = 0.0;
  } else {
    Alpha1_idx_5 = Thrustallocation_test_B.Delay_n;
  }

  rtb_T_r = ((1.0 - lambda_c) * Thrustallocation_test_P.Ktr +
             Thrustallocation_test_P.Kt * lambda_c) * Alpha1_idx_5 *
    Thrustallocation_test_P.Rho * rt_powd_snf(Thrustallocation_test_P.D, 4.0) *
    (Thrustallocation_test_B.Delay_n * Thrustallocation_test_B.Delay_n);
  Thrustallocation_test_B.n_d = b_signal;

  /* End of MATLAB Function: '<S74>/MATLAB Function' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* DiscreteTransferFcn: '<S74>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S74>/Constant1'
     *  Constant: '<S74>/Constant2'
     */
    Thrustallocation_test_DW.DiscreteTransferFcn_tmp_a =
      (Thrustallocation_test_B.n_d - Thrustallocation_test_P.Constant2_Value_l[1]
       * Thrustallocation_test_DW.DiscreteTransferFcn_states_jo[0]) -
      Thrustallocation_test_P.Constant2_Value_l[2] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_jo[1];
    Thrustallocation_test_B.DiscreteTransferFcn_h =
      (Thrustallocation_test_P.Constant1_Value_j[0] *
       Thrustallocation_test_DW.DiscreteTransferFcn_tmp_a +
       Thrustallocation_test_P.Constant1_Value_j[1] *
       Thrustallocation_test_DW.DiscreteTransferFcn_states_jo[0]) +
      Thrustallocation_test_P.Constant1_Value_j[2] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_jo[1];

    /* SampleTimeMath: '<S77>/TSamp'
     *
     * About '<S77>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    Thrustallocation_test_B.TSamp_k =
      Thrustallocation_test_B.DiscreteTransferFcn_h *
      Thrustallocation_test_P.TSamp_WtEt_b;

    /* Sum: '<S77>/Diff' incorporates:
     *  UnitDelay: '<S77>/UD'
     */
    rtb_Sum_k = Thrustallocation_test_B.TSamp_k -
      Thrustallocation_test_DW.UD_DSTATE_f;

    /* RateLimiter: '<S74>/Acceleration limiter' */
    b_signal = rtb_Sum_k - Thrustallocation_test_DW.PrevY_f;
    if (b_signal > Thrustallocation_test_P.Accelerationlimiter_RisingLi_nn) {
      rtb_Sum_k = Thrustallocation_test_DW.PrevY_f +
        Thrustallocation_test_P.Accelerationlimiter_RisingLi_nn;
    } else {
      if (b_signal < Thrustallocation_test_P.Accelerationlimiter_FallingLi_a) {
        rtb_Sum_k = Thrustallocation_test_DW.PrevY_f +
          Thrustallocation_test_P.Accelerationlimiter_FallingLi_a;
      }
    }

    Thrustallocation_test_DW.PrevY_f = rtb_Sum_k;

    /* End of RateLimiter: '<S74>/Acceleration limiter' */

    /* Gain: '<S74>/Inertia compensation' */
    Thrustallocation_test_B.Inertiacompensation_g = Thrustallocation_test_P.I_s *
      2.0 * 3.1415926535897931 * rtb_Sum_k;

    /* Sum: '<S74>/Sum1' incorporates:
     *  Gain: '<S74>/Qf_0'
     *  Gain: '<S74>/Qff_0(nr)'
     *  Gain: '<S74>/Qff_1(nr)'
     *  Trigonometry: '<S74>/Trigonometric Function'
     */
    Thrustallocation_test_B.Sum1_a = tanh(Thrustallocation_test_P.epsilon /
      Thrustallocation_test_P.n_max *
      Thrustallocation_test_B.DiscreteTransferFcn_h) *
      Thrustallocation_test_P.Q_f0 + Thrustallocation_test_P.K_omega * 2.0 *
      3.1415926535897931 * Thrustallocation_test_B.DiscreteTransferFcn_h;

    /* Memory: '<S74>/Memory' */
    Thrustallocation_test_B.Memory_o =
      Thrustallocation_test_DW.Memory_PreviousInput_k;

    /* Sum: '<S76>/Sum' */
    rtb_Sum_k = Thrustallocation_test_B.DiscreteTransferFcn_h -
      Thrustallocation_test_B.Delay[5];

    /* Gain: '<S76>/Kp' */
    Thrustallocation_test_B.Kp_me = Thrustallocation_test_P.Kp * rtb_Sum_k;
  }

  /* Integrator: '<S76>/Integrator' */
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_dt,
                       Thrustallocation_test_B.reset_en);

    /* evaluate zero-crossings */
    if (zcEvent) {
      Thrustallocation_test_X.Integrator_CSTATE_g =
        Thrustallocation_test_P.Integrator_IC_eh;
    }
  }

  rtb_Integrator_gs = Thrustallocation_test_X.Integrator_CSTATE_g;

  /* MATLAB Function: '<S76>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/D'
   *  Constant: '<S2>/Kq'
   *  Constant: '<S2>/Kqr'
   *  Constant: '<S2>/Kt'
   *  Constant: '<S2>/Ktr'
   *  Constant: '<S2>/Rho'
   */
  CorecontrollerTorquePowerandCom(Thrustallocation_test_P.k_cc,
    Thrustallocation_test_P.p_cc, Thrustallocation_test_P.r_cc,
    Thrustallocation_test_B.Delay[5], Thrustallocation_test_P.Kt,
    Thrustallocation_test_P.Kq, Thrustallocation_test_P.D, rtb_T_r,
    Thrustallocation_test_P.eps, Thrustallocation_test_P.Rho,
    Thrustallocation_test_P.eps_c, Thrustallocation_test_P.Ktr,
    Thrustallocation_test_P.Kqr,
    &Thrustallocation_test_B.sf_CorecontrollerTorquePowera_f);

  /* MultiPortSwitch: '<S74>/Controller chosen' incorporates:
   *  Constant: '<S74>/NaN'
   *  Sum: '<S76>/Sum1'
   */
  switch ((int32_T)Thrustallocation_test_B.Memory_o) {
   case 1:
    b_signal = Thrustallocation_test_B.Kp_me + rtb_Integrator_gs;
    break;

   case 2:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_f.Qcq;
    break;

   case 3:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_f.Qcp;
    break;

   case 4:
    b_signal = Thrustallocation_test_B.sf_CorecontrollerTorquePowera_f.Qcc;
    break;

   default:
    b_signal = Thrustallocation_test_P.NaN_Value_eh;
    break;
  }

  /* End of MultiPortSwitch: '<S74>/Controller chosen' */

  /* Sum: '<S74>/Sum' */
  Thrustallocation_test_B.Sum_id =
    (Thrustallocation_test_B.Inertiacompensation_g +
     Thrustallocation_test_B.Sum1_a) + b_signal;
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S25>/Constant'
     *  Constant: '<S25>/Constant1'
     */
    Thrustallocation_test_DW.DiscreteTransferFcn_tmp_ov =
      Thrustallocation_test_B.Sum_id -
      Thrustallocation_test_P.Constant_Value_gp[1] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_df;
    Thrustallocation_test_B.DiscreteTransferFcn_p =
      Thrustallocation_test_P.Constant1_Value_c[0] *
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_ov +
      Thrustallocation_test_P.Constant1_Value_c[1] *
      Thrustallocation_test_DW.DiscreteTransferFcn_states_df;
  }

  /* Gain: '<S73>/Finding rotation speed' incorporates:
   *  Gain: '<S73>/K_omega'
   *  Sum: '<S73>/Sum'
   */
  Thrustallocation_test_B.Findingrotationspeed_h =
    ((Thrustallocation_test_B.DiscreteTransferFcn_p -
      Thrustallocation_test_B.Delay_cn) - Thrustallocation_test_P.K_omega * 2.0 *
     3.1415926535897931 * rtb_Integrator_h) * (1.0 / (6.2831853071795862 *
    Thrustallocation_test_P.I_s));
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Gain: '<S76>/Ki' */
    Thrustallocation_test_B.Ki_k = Thrustallocation_test_P.Kp / 0.05 * rtb_Sum_k;
  }

  /* MATLAB Function: '<S74>/Supervisor' */
  Thrustallocation_tes_Supervisor(Thrustallocation_test_B.Memory_o,
    Thrustallocation_test_B.core_controller, Thrustallocation_test_B.Delay[5],
    &Thrustallocation_test_B.sf_Supervisor_g);
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* SignalConversion: '<S5>/TmpSignal ConversionAtDelayInport1' */
    Thrustallocation_test_B.TmpSignalConversionAtDelayInpor[0] =
      Thrustallocation_test_B.output[1];
    Thrustallocation_test_B.TmpSignalConversionAtDelayInpor[1] =
      Thrustallocation_test_B.output[3];
    Thrustallocation_test_B.TmpSignalConversionAtDelayInpor[2] =
      Thrustallocation_test_B.output[5];
    Thrustallocation_test_B.TmpSignalConversionAtDelayInpor[3] =
      Thrustallocation_test_B.output[7];
    Thrustallocation_test_B.TmpSignalConversionAtDelayInpor[4] =
      Thrustallocation_test_B.output[9];
    Thrustallocation_test_B.TmpSignalConversionAtDelayInpor[5] =
      Thrustallocation_test_B.output[11];
  }

  /* MATLAB Function: '<Root>/kinematics' incorporates:
   *  Integrator: '<Root>/Velocity'
   */
  /* MATLAB Function 'kinematics': '<S7>:1' */
  /* '<S7>:1:3' */
  /* '<S7>:1:5' */
  /* '<S7>:1:9' */
  tmp_0[0] = cos(rtb_Position[2]);
  tmp_0[3] = -sin(rtb_Position[2]);
  tmp_0[6] = 0.0;
  tmp_0[1] = sin(rtb_Position[2]);
  tmp_0[4] = cos(rtb_Position[2]);
  tmp_0[7] = 0.0;
  tmp_0[2] = 0.0;
  tmp_0[5] = 0.0;
  tmp_0[8] = 1.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    Thrustallocation_test_B.eta_dot[i_0] = 0.0;
    Thrustallocation_test_B.eta_dot[i_0] += tmp_0[i_0] *
      Thrustallocation_test_X.Velocity_CSTATE[0];
    Thrustallocation_test_B.eta_dot[i_0] += tmp_0[i_0 + 3] *
      Thrustallocation_test_X.Velocity_CSTATE[1];
    Thrustallocation_test_B.eta_dot[i_0] += tmp_0[i_0 + 6] *
      Thrustallocation_test_X.Velocity_CSTATE[2];
  }

  /* End of MATLAB Function: '<Root>/kinematics' */

  /* MATLAB Function: '<Root>/kinetics' incorporates:
   *  Integrator: '<Root>/Velocity'
   */
  /* MATLAB Function 'kinetics': '<S8>:1' */
  /* '<S8>:1:3' */
  /* '<S8>:1:4' */
  /* '<S8>:1:5' */
  /* % MATRICES */
  /* 0.0432; */
  /* % Added mass */
  /* % Total mass matrix */
  /* % DAMPING  */
  /*  Surge: */
  /*  Based on fitting of towing data from -0.8 < u < 0.8 m/s */
  /* '<S8>:1:33' */
  /*  Sway: */
  /*  Based on fitting of towing data from -0.45 < u < 0.45 m/s */
  /* '<S8>:1:39' */
  /*  Yaw: */
  /*  Based on fitting of towing data from -8 < u < 8 deg/s */
  /*  The fitting range is limited. Towing should be performed for higher */
  /*  velocities. */
  /* '<S8>:1:47' */
  /*  Y_vvv og N_rrr er fra curvefitting uten minus, men ser ut til å fungere */
  /*  med minus.  */
  /* % Correolis matrix */
  /* % Assembly of the damping matrix */
  /* '<S8>:1:71' */
  /* '<S8>:1:72' */
  /* '<S8>:1:73' */
  /*  Y_r + Y_rr*abs(r) + Y_rrr*r^2 + Y_vr*abs(v); Not verified, temporarily disabled */
  /*  N_v + N_vv*abs(v) + N_vvv*v^2 + N_rv*abs(r); Not verified, temporarily disabled */
  /* '<S8>:1:78' */
  /* % CALCULATION */
  /* '<S8>:1:83' */
  tmp_1[0] = (0.0 * fabs(Thrustallocation_test_X.Velocity_CSTATE[0]) + -2.332) +
    Thrustallocation_test_X.Velocity_CSTATE[0] *
    Thrustallocation_test_X.Velocity_CSTATE[0] * -8.557;
  tmp_1[3] = 0.0;
  tmp_1[6] = 0.0;
  tmp_1[1] = 0.0;
  tmp_1[4] = (0.3976 * fabs(Thrustallocation_test_X.Velocity_CSTATE[1]) + -4.673)
    + Thrustallocation_test_X.Velocity_CSTATE[1] *
    Thrustallocation_test_X.Velocity_CSTATE[1] * -313.3;
  tmp_1[7] = 0.0;
  tmp_1[2] = 0.0;
  tmp_1[5] = 0.0;
  tmp_1[8] = (-0.01148 * fabs(Thrustallocation_test_X.Velocity_CSTATE[2]) +
              -0.01675) + Thrustallocation_test_X.Velocity_CSTATE[2] *
    Thrustallocation_test_X.Velocity_CSTATE[2] * -0.0003578;
  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_0[3 * i_0] = -tmp_1[3 * i_0];
    tmp_0[1 + 3 * i_0] = -tmp_1[3 * i_0 + 1];
    tmp_0[2 + 3 * i_0] = -tmp_1[3 * i_0 + 2];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    s_0[i_0] = Thrustallocation_test_B.commanded_tau[i_0] - ((tmp_0[i_0 + 3] *
      Thrustallocation_test_X.Velocity_CSTATE[1] + tmp_0[i_0] *
      Thrustallocation_test_X.Velocity_CSTATE[0]) + tmp_0[i_0 + 6] *
      Thrustallocation_test_X.Velocity_CSTATE[2]);
  }

  Thrustallocation_test_B.nu_dot[0] = s_0[0];
  Thrustallocation_test_B.nu_dot[1] = s_0[1] - Thrustallocation_test_B.nu_dot[0]
    * 0.0;
  Thrustallocation_test_B.nu_dot[2] = (s_0[2] - Thrustallocation_test_B.nu_dot[0]
    * 0.0) - Thrustallocation_test_B.nu_dot[1] * -0.0015853781682318489;
  Thrustallocation_test_B.nu_dot[2] /= 47.986167676461676;
  Thrustallocation_test_B.nu_dot[0] -= Thrustallocation_test_B.nu_dot[2] * 0.0;
  Thrustallocation_test_B.nu_dot[1] -= Thrustallocation_test_B.nu_dot[2] *
    -0.525;
  Thrustallocation_test_B.nu_dot[1] /= 99.03;
  Thrustallocation_test_B.nu_dot[0] -= Thrustallocation_test_B.nu_dot[1] * 0.0;
  Thrustallocation_test_B.nu_dot[0] /= 124.658;

  /* End of MATLAB Function: '<Root>/kinetics' */
}

/* Model update function */
void Thrustallocation_test_update(void)
{
  /* local block i/o variables */
  real_T rtb_ImpSel_InsertedFor_reset_at;

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T i;
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Update for UnitDelay: '<S81>/Delay Input1' */
    Thrustallocation_test_DW.DelayInput1_DSTATE =
      Thrustallocation_test_B.ArrowUp;

    /* Update for UnitDelay: '<S82>/Delay Input1' */
    Thrustallocation_test_DW.DelayInput1_DSTATE_d =
      Thrustallocation_test_B.ArrowDown;

    /* Update for UnitDelay: '<S83>/Delay Input1' */
    Thrustallocation_test_DW.DelayInput1_DSTATE_c =
      Thrustallocation_test_B.Start;

    /* Update for Memory: '<S9>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput = Thrustallocation_test_B.y;
  }

  /* Update for Iterator SubSystem: '<S4>/Optimal angle path and  constraints on rotation speed' */
  for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
    /* Update for ForEachSliceSelector: '<S12>/ImpSel_InsertedFor_reset_at_outport_0' */
    rtb_ImpSel_InsertedFor_reset_at =
      Thrustallocation_test_B.reset_c[ForEach_itr];
    if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
      /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
      Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
        DiscreteTimeIntegrator_IC_LOADI = 0U;
      Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
        DiscreteTimeIntegrator_DSTATE +=
        Thrustallocation_test_P.CoreSubsys.DiscreteTimeIntegrator_gainval *
        Thrustallocation_test_B.CoreSubsys[ForEach_itr].MaxRotationRate;
      if (rtb_ImpSel_InsertedFor_reset_at > 0.0) {
        Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
          DiscreteTimeIntegrator_PrevRese = 1;
      } else if (rtb_ImpSel_InsertedFor_reset_at < 0.0) {
        Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
          DiscreteTimeIntegrator_PrevRese = -1;
      } else if (rtb_ImpSel_InsertedFor_reset_at == 0.0) {
        Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
          DiscreteTimeIntegrator_PrevRese = 0;
      } else {
        Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
          DiscreteTimeIntegrator_PrevRese = 2;
      }

      /* End of Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */

      /* Update for Delay: '<S12>/Delay' */
      Thrustallocation_test_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        Thrustallocation_test_B.CoreSubsys[ForEach_itr].angle;
    }
  }

  /* End of Update for SubSystem: '<S4>/Optimal angle path and  constraints on rotation speed' */
  /* Update for Integrator: '<Root>/Position' */
  Thrustallocation_test_DW.Position_IWORK.IcNeedsLoading = 0;
  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Update for Delay: '<S5>/Delay' */
    for (i = 0; i < 6; i++) {
      Thrustallocation_test_DW.Delay_DSTATE[i] =
        Thrustallocation_test_B.TmpSignalConversionAtDelayInpor[i];
    }

    /* End of Update for Delay: '<S5>/Delay' */

    /* Update for Delay: '<S20>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_l =
      Thrustallocation_test_B.sf_ActualForceandTorque.Qa;

    /* Update for Delay: '<S29>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_g =
      Thrustallocation_test_B.DiscreteTransferFcn;

    /* Update for DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states[1] =
      Thrustallocation_test_DW.DiscreteTransferFcn_states[0];
    Thrustallocation_test_DW.DiscreteTransferFcn_states[0] =
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp;

    /* Update for UnitDelay: '<S32>/UD' */
    Thrustallocation_test_DW.UD_DSTATE = Thrustallocation_test_B.TSamp;

    /* Update for Memory: '<S29>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput_d =
      Thrustallocation_test_B.sf_Supervisor.u;
  }

  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Update for DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_o =
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_d;

    /* Update for Delay: '<S21>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_c =
      Thrustallocation_test_B.sf_ActualForceandTorque_k.Qa;

    /* Update for Delay: '<S38>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_i =
      Thrustallocation_test_B.DiscreteTransferFcn_d;

    /* Update for DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_f[1] =
      Thrustallocation_test_DW.DiscreteTransferFcn_states_f[0];
    Thrustallocation_test_DW.DiscreteTransferFcn_states_f[0] =
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_l;

    /* Update for UnitDelay: '<S41>/UD' */
    Thrustallocation_test_DW.UD_DSTATE_a = Thrustallocation_test_B.TSamp_d;

    /* Update for Memory: '<S38>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput_c =
      Thrustallocation_test_B.sf_Supervisor_p.u;
  }

  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Update for DiscreteTransferFcn: '<S21>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_a =
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_c;

    /* Update for Delay: '<S22>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_p =
      Thrustallocation_test_B.sf_ActualForceandTorque_g.Qa;

    /* Update for Delay: '<S47>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_f =
      Thrustallocation_test_B.DiscreteTransferFcn_k;

    /* Update for DiscreteTransferFcn: '<S47>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_m[1] =
      Thrustallocation_test_DW.DiscreteTransferFcn_states_m[0];
    Thrustallocation_test_DW.DiscreteTransferFcn_states_m[0] =
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_i;

    /* Update for UnitDelay: '<S50>/UD' */
    Thrustallocation_test_DW.UD_DSTATE_j = Thrustallocation_test_B.TSamp_f;

    /* Update for Memory: '<S47>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput_l =
      Thrustallocation_test_B.sf_Supervisor_b.u;
  }

  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Update for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_d =
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_ll;

    /* Update for Delay: '<S23>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_ce =
      Thrustallocation_test_B.sf_ActualForceandTorque_b.Qa;

    /* Update for Delay: '<S56>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_h =
      Thrustallocation_test_B.DiscreteTransferFcn_ox;

    /* Update for DiscreteTransferFcn: '<S56>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_j[1] =
      Thrustallocation_test_DW.DiscreteTransferFcn_states_j[0];
    Thrustallocation_test_DW.DiscreteTransferFcn_states_j[0] =
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_p;

    /* Update for UnitDelay: '<S59>/UD' */
    Thrustallocation_test_DW.UD_DSTATE_c = Thrustallocation_test_B.TSamp_j;

    /* Update for Memory: '<S56>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput_a =
      Thrustallocation_test_B.sf_Supervisor_m.u;
  }

  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_e =
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_o;

    /* Update for Delay: '<S24>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_m =
      Thrustallocation_test_B.sf_ActualForceandTorque_m.Qa;

    /* Update for Delay: '<S65>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_k =
      Thrustallocation_test_B.DiscreteTransferFcn_f;

    /* Update for DiscreteTransferFcn: '<S65>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_du[1] =
      Thrustallocation_test_DW.DiscreteTransferFcn_states_du[0];
    Thrustallocation_test_DW.DiscreteTransferFcn_states_du[0] =
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_c3;

    /* Update for UnitDelay: '<S68>/UD' */
    Thrustallocation_test_DW.UD_DSTATE_n = Thrustallocation_test_B.TSamp_n;

    /* Update for Memory: '<S65>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput_f =
      Thrustallocation_test_B.sf_Supervisor_mw.u;
  }

  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Update for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_fv =
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_k;

    /* Update for Delay: '<S25>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_cy =
      Thrustallocation_test_B.sf_ActualForceandTorque_n.Qa;

    /* Update for Delay: '<S74>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_n =
      Thrustallocation_test_B.DiscreteTransferFcn_h;

    /* Update for DiscreteTransferFcn: '<S74>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_jo[1] =
      Thrustallocation_test_DW.DiscreteTransferFcn_states_jo[0];
    Thrustallocation_test_DW.DiscreteTransferFcn_states_jo[0] =
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_a;

    /* Update for UnitDelay: '<S77>/UD' */
    Thrustallocation_test_DW.UD_DSTATE_f = Thrustallocation_test_B.TSamp_k;

    /* Update for Memory: '<S74>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput_k =
      Thrustallocation_test_B.sf_Supervisor_g.u;
  }

  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    /* Update for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_df =
      Thrustallocation_test_DW.DiscreteTransferFcn_tmp_ov;
  }

  if (rtmIsMajorTimeStep(Thrustallocation_test_M)) {
    rt_ertODEUpdateContinuousStates(&Thrustallocation_test_M->solverInfo);
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
  if (!(++Thrustallocation_test_M->Timing.clockTick0)) {
    ++Thrustallocation_test_M->Timing.clockTickH0;
  }

  Thrustallocation_test_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Thrustallocation_test_M->solverInfo);

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
    if (!(++Thrustallocation_test_M->Timing.clockTick1)) {
      ++Thrustallocation_test_M->Timing.clockTickH1;
    }

    Thrustallocation_test_M->Timing.t[1] =
      Thrustallocation_test_M->Timing.clockTick1 *
      Thrustallocation_test_M->Timing.stepSize1 +
      Thrustallocation_test_M->Timing.clockTickH1 *
      Thrustallocation_test_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Thrustallocation_test_derivatives(void)
{
  XDot_Thrustallocation_test_T *_rtXdot;
  _rtXdot = ((XDot_Thrustallocation_test_T *)
             Thrustallocation_test_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S28>/Integrator' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Integrator_CSTATE = Thrustallocation_test_B.Findingrotationspeed;
  }

  /* Derivatives for Integrator: '<S37>/Integrator' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Integrator_CSTATE_o = Thrustallocation_test_B.Findingrotationspeed_k;
  }

  /* Derivatives for Integrator: '<S46>/Integrator' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Integrator_CSTATE_p = Thrustallocation_test_B.Findingrotationspeed_j;
  }

  /* Derivatives for Integrator: '<S55>/Integrator' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Integrator_CSTATE_a = Thrustallocation_test_B.Findingrotationspeed_n;
  }

  /* Derivatives for Integrator: '<S64>/Integrator' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Integrator_CSTATE_a0 = Thrustallocation_test_B.Findingrotationspeed_j0;
  }

  /* Derivatives for Integrator: '<S73>/Integrator' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Integrator_CSTATE_d = Thrustallocation_test_B.Findingrotationspeed_h;
  }

  /* Derivatives for Integrator: '<Root>/Position' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Position_CSTATE[0] = Thrustallocation_test_B.eta_dot[0];
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Position_CSTATE[1] = Thrustallocation_test_B.eta_dot[1];
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Position_CSTATE[2] = Thrustallocation_test_B.eta_dot[2];
  }

  /* Derivatives for Integrator: '<S31>/Integrator' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Integrator_CSTATE_j = Thrustallocation_test_B.Ki;
  }

  /* Derivatives for Integrator: '<S40>/Integrator' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Integrator_CSTATE_jg = Thrustallocation_test_B.Ki_h;
  }

  /* Derivatives for Integrator: '<S49>/Integrator' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Integrator_CSTATE_e = Thrustallocation_test_B.Ki_e;
  }

  /* Derivatives for Integrator: '<S58>/Integrator' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Integrator_CSTATE_jz = Thrustallocation_test_B.Ki_j;
  }

  /* Derivatives for Integrator: '<S67>/Integrator' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Integrator_CSTATE_ai = Thrustallocation_test_B.Ki_jy;
  }

  /* Derivatives for Integrator: '<S76>/Integrator' */
  {
    ((XDot_Thrustallocation_test_T *) Thrustallocation_test_M->ModelData.derivs
      )->Integrator_CSTATE_g = Thrustallocation_test_B.Ki_k;
  }

  /* Derivatives for Integrator: '<Root>/Velocity' */
  _rtXdot->Velocity_CSTATE[0] = Thrustallocation_test_B.nu_dot[0];
  _rtXdot->Velocity_CSTATE[1] = Thrustallocation_test_B.nu_dot[1];
  _rtXdot->Velocity_CSTATE[2] = Thrustallocation_test_B.nu_dot[2];
}

/* Model initialize function */
void Thrustallocation_test_initialize(void)
{
  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;

    /* Start for Iterator SubSystem: '<S4>/Optimal angle path and  constraints on rotation speed' */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      Thrustallocation_test_B.CoreSubsys[ForEach_itr].angle = 0.0;
      Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
        DiscreteTimeIntegrator_DSTATE = 0.0;
      Thrustallocation_test_B.CoreSubsys[ForEach_itr].Delay = 0.0;
      Thrustallocation_test_B.CoreSubsys[ForEach_itr].MaxRotationRate = 0.0;

      /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
      Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
        DiscreteTimeIntegrator_IC_LOADI = 1U;
      Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
        DiscreteTimeIntegrator_PrevRese = 2;

      /* InitializeConditions for Delay: '<S12>/Delay' */
      Thrustallocation_test_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        Thrustallocation_test_P.CoreSubsys.Delay_InitialCondition;
    }

    /* End of Start for SubSystem: '<S4>/Optimal angle path and  constraints on rotation speed' */

    /* Start for Constant: '<Root>/Constant1' */
    Thrustallocation_test_B.Constant1[0] =
      Thrustallocation_test_P.Constant1_Value[0];
    Thrustallocation_test_B.Constant1[1] =
      Thrustallocation_test_P.Constant1_Value[1];
    Thrustallocation_test_B.Constant1[2] =
      Thrustallocation_test_P.Constant1_Value[2];
  }

  Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
  Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_m = UNINITIALIZED_ZCSIG;
  Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
  Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
  Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_f = UNINITIALIZED_ZCSIG;
  Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_c = UNINITIALIZED_ZCSIG;
  Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_j = UNINITIALIZED_ZCSIG;
  Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_d5 = UNINITIALIZED_ZCSIG;
  Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
  Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
  Thrustallocation_test_PrevZCX.Integrator_Reset_ZCE_dt = UNINITIALIZED_ZCSIG;

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr;
    int32_T i;

    /* InitializeConditions for Integrator: '<S28>/Integrator' */
    Thrustallocation_test_X.Integrator_CSTATE =
      Thrustallocation_test_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S37>/Integrator' */
    Thrustallocation_test_X.Integrator_CSTATE_o =
      Thrustallocation_test_P.Integrator_IC_c;

    /* InitializeConditions for Integrator: '<S46>/Integrator' */
    Thrustallocation_test_X.Integrator_CSTATE_p =
      Thrustallocation_test_P.Integrator_IC_g;

    /* InitializeConditions for Integrator: '<S55>/Integrator' */
    Thrustallocation_test_X.Integrator_CSTATE_a =
      Thrustallocation_test_P.Integrator_IC_e;

    /* InitializeConditions for Integrator: '<S64>/Integrator' */
    Thrustallocation_test_X.Integrator_CSTATE_a0 =
      Thrustallocation_test_P.Integrator_IC_l;

    /* InitializeConditions for Integrator: '<S73>/Integrator' */
    Thrustallocation_test_X.Integrator_CSTATE_d =
      Thrustallocation_test_P.Integrator_IC_j;

    /* InitializeConditions for UnitDelay: '<S81>/Delay Input1' */
    Thrustallocation_test_DW.DelayInput1_DSTATE =
      Thrustallocation_test_P.DetectIncrease_vinit;

    /* InitializeConditions for UnitDelay: '<S82>/Delay Input1' */
    Thrustallocation_test_DW.DelayInput1_DSTATE_d =
      Thrustallocation_test_P.DetectIncrease1_vinit;

    /* InitializeConditions for UnitDelay: '<S83>/Delay Input1' */
    Thrustallocation_test_DW.DelayInput1_DSTATE_c =
      Thrustallocation_test_P.DetectIncrease2_vinit;

    /* InitializeConditions for Memory: '<S9>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput =
      Thrustallocation_test_P.Memory_X0;

    /* InitializeConditions for Iterator SubSystem: '<S4>/Optimal angle path and  constraints on rotation speed' */
    for (ForEach_itr = 0; ForEach_itr < 6; ForEach_itr++) {
      /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
      Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
        DiscreteTimeIntegrator_IC_LOADI = 1U;
      Thrustallocation_test_DW.CoreSubsys[ForEach_itr].
        DiscreteTimeIntegrator_PrevRese = 2;

      /* InitializeConditions for Delay: '<S12>/Delay' */
      Thrustallocation_test_DW.CoreSubsys[ForEach_itr].Delay_DSTATE =
        Thrustallocation_test_P.CoreSubsys.Delay_InitialCondition;
    }

    /* End of InitializeConditions for SubSystem: '<S4>/Optimal angle path and  constraints on rotation speed' */
    /* InitializeConditions for Integrator: '<Root>/Position' */
    if (rtmIsFirstInitCond(Thrustallocation_test_M)) {
      Thrustallocation_test_X.Position_CSTATE[0] = 0.0;
      Thrustallocation_test_X.Position_CSTATE[1] = 0.0;
      Thrustallocation_test_X.Position_CSTATE[2] = 0.0;
    }

    Thrustallocation_test_DW.Position_IWORK.IcNeedsLoading = 1;

    /* InitializeConditions for Delay: '<S5>/Delay' */
    for (i = 0; i < 6; i++) {
      Thrustallocation_test_DW.Delay_DSTATE[i] =
        Thrustallocation_test_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S5>/Delay' */

    /* InitializeConditions for Delay: '<S20>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_l =
      Thrustallocation_test_P.Delay_InitialCondition_m;

    /* InitializeConditions for Delay: '<S29>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_g =
      Thrustallocation_test_P.Delay_InitialCondition_mz;

    /* InitializeConditions for DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states[0] =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialStat;
    Thrustallocation_test_DW.DiscreteTransferFcn_states[1] =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialStat;

    /* InitializeConditions for UnitDelay: '<S32>/UD' */
    Thrustallocation_test_DW.UD_DSTATE =
      Thrustallocation_test_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for RateLimiter: '<S29>/Acceleration Limit' */
    Thrustallocation_test_DW.PrevY =
      Thrustallocation_test_P.AccelerationLimit_IC;

    /* InitializeConditions for Memory: '<S29>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput_d =
      Thrustallocation_test_P.Memory_X0_f;

    /* InitializeConditions for Integrator: '<S31>/Integrator' */
    Thrustallocation_test_X.Integrator_CSTATE_j =
      Thrustallocation_test_P.Integrator_IC_p;

    /* InitializeConditions for DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_o =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialSt_n;

    /* InitializeConditions for Delay: '<S21>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_c =
      Thrustallocation_test_P.Delay_InitialCondition_k;

    /* InitializeConditions for Delay: '<S38>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_i =
      Thrustallocation_test_P.Delay_InitialCondition_f;

    /* InitializeConditions for DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_f[0] =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialSt_c;
    Thrustallocation_test_DW.DiscreteTransferFcn_states_f[1] =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialSt_c;

    /* InitializeConditions for UnitDelay: '<S41>/UD' */
    Thrustallocation_test_DW.UD_DSTATE_a =
      Thrustallocation_test_P.DiscreteDerivative_ICPrevScal_p;

    /* InitializeConditions for RateLimiter: '<S38>/Acceleration Limit' */
    Thrustallocation_test_DW.PrevY_i =
      Thrustallocation_test_P.AccelerationLimit_IC_e;

    /* InitializeConditions for Memory: '<S38>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput_c =
      Thrustallocation_test_P.Memory_X0_h;

    /* InitializeConditions for Integrator: '<S40>/Integrator' */
    Thrustallocation_test_X.Integrator_CSTATE_jg =
      Thrustallocation_test_P.Integrator_IC_o;

    /* InitializeConditions for DiscreteTransferFcn: '<S21>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_a =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialSt_d;

    /* InitializeConditions for Delay: '<S22>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_p =
      Thrustallocation_test_P.Delay_InitialCondition_b;

    /* InitializeConditions for Delay: '<S47>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_f =
      Thrustallocation_test_P.Delay_InitialCondition_h;

    /* InitializeConditions for DiscreteTransferFcn: '<S47>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_m[0] =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialSt_m;
    Thrustallocation_test_DW.DiscreteTransferFcn_states_m[1] =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialSt_m;

    /* InitializeConditions for UnitDelay: '<S50>/UD' */
    Thrustallocation_test_DW.UD_DSTATE_j =
      Thrustallocation_test_P.DiscreteDerivative_ICPrevScal_c;

    /* InitializeConditions for RateLimiter: '<S47>/Acceleration limiter' */
    Thrustallocation_test_DW.PrevY_o =
      Thrustallocation_test_P.Accelerationlimiter_IC;

    /* InitializeConditions for Memory: '<S47>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput_l =
      Thrustallocation_test_P.Memory_X0_e;

    /* InitializeConditions for Integrator: '<S49>/Integrator' */
    Thrustallocation_test_X.Integrator_CSTATE_e =
      Thrustallocation_test_P.Integrator_IC_pf;

    /* InitializeConditions for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_d =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialS_nl;

    /* InitializeConditions for Delay: '<S23>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_ce =
      Thrustallocation_test_P.Delay_InitialCondition_g;

    /* InitializeConditions for Delay: '<S56>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_h =
      Thrustallocation_test_P.Delay_InitialCondition_e;

    /* InitializeConditions for DiscreteTransferFcn: '<S56>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_j[0] =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialS_mq;
    Thrustallocation_test_DW.DiscreteTransferFcn_states_j[1] =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialS_mq;

    /* InitializeConditions for UnitDelay: '<S59>/UD' */
    Thrustallocation_test_DW.UD_DSTATE_c =
      Thrustallocation_test_P.DiscreteDerivative_ICPrevScal_e;

    /* InitializeConditions for RateLimiter: '<S56>/Acceleration limiter' */
    Thrustallocation_test_DW.PrevY_a =
      Thrustallocation_test_P.Accelerationlimiter_IC_m;

    /* InitializeConditions for Memory: '<S56>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput_a =
      Thrustallocation_test_P.Memory_X0_d;

    /* InitializeConditions for Integrator: '<S58>/Integrator' */
    Thrustallocation_test_X.Integrator_CSTATE_jz =
      Thrustallocation_test_P.Integrator_IC_f;

    /* InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_e =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialSt_i;

    /* InitializeConditions for Delay: '<S24>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_m =
      Thrustallocation_test_P.Delay_InitialCondition_i;

    /* InitializeConditions for Delay: '<S65>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_k =
      Thrustallocation_test_P.Delay_InitialCondition_o;

    /* InitializeConditions for DiscreteTransferFcn: '<S65>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_du[0] =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialS_mc;
    Thrustallocation_test_DW.DiscreteTransferFcn_states_du[1] =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialS_mc;

    /* InitializeConditions for UnitDelay: '<S68>/UD' */
    Thrustallocation_test_DW.UD_DSTATE_n =
      Thrustallocation_test_P.DiscreteDerivative_ICPrevScal_f;

    /* InitializeConditions for RateLimiter: '<S65>/Acceleration limiter' */
    Thrustallocation_test_DW.PrevY_m =
      Thrustallocation_test_P.Accelerationlimiter_IC_e;

    /* InitializeConditions for Memory: '<S65>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput_f =
      Thrustallocation_test_P.Memory_X0_b;

    /* InitializeConditions for Integrator: '<S67>/Integrator' */
    Thrustallocation_test_X.Integrator_CSTATE_ai =
      Thrustallocation_test_P.Integrator_IC_e2;

    /* InitializeConditions for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_fv =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialSt_h;

    /* InitializeConditions for Delay: '<S25>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_cy =
      Thrustallocation_test_P.Delay_InitialCondition_bd;

    /* InitializeConditions for Delay: '<S74>/Delay' */
    Thrustallocation_test_DW.Delay_DSTATE_n =
      Thrustallocation_test_P.Delay_InitialCondition_j;

    /* InitializeConditions for DiscreteTransferFcn: '<S74>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_jo[0] =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialSt_l;
    Thrustallocation_test_DW.DiscreteTransferFcn_states_jo[1] =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialSt_l;

    /* InitializeConditions for UnitDelay: '<S77>/UD' */
    Thrustallocation_test_DW.UD_DSTATE_f =
      Thrustallocation_test_P.DiscreteDerivative_ICPrevSca_es;

    /* InitializeConditions for RateLimiter: '<S74>/Acceleration limiter' */
    Thrustallocation_test_DW.PrevY_f =
      Thrustallocation_test_P.Accelerationlimiter_IC_k;

    /* InitializeConditions for Memory: '<S74>/Memory' */
    Thrustallocation_test_DW.Memory_PreviousInput_k =
      Thrustallocation_test_P.Memory_X0_g;

    /* InitializeConditions for Integrator: '<S76>/Integrator' */
    Thrustallocation_test_X.Integrator_CSTATE_g =
      Thrustallocation_test_P.Integrator_IC_eh;

    /* InitializeConditions for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn' */
    Thrustallocation_test_DW.DiscreteTransferFcn_states_df =
      Thrustallocation_test_P.DiscreteTransferFcn_InitialS_dp;

    /* InitializeConditions for Integrator: '<Root>/Velocity' */
    Thrustallocation_test_X.Velocity_CSTATE[0] =
      Thrustallocation_test_P.Velocity_IC[0];
    Thrustallocation_test_X.Velocity_CSTATE[1] =
      Thrustallocation_test_P.Velocity_IC[1];
    Thrustallocation_test_X.Velocity_CSTATE[2] =
      Thrustallocation_test_P.Velocity_IC[2];

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(Thrustallocation_test_M)) {
      rtmSetFirstInitCond(Thrustallocation_test_M, 0);
    }
  }
}

/* Model terminate function */
void Thrustallocation_test_terminate(void)
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
  Thrustallocation_test_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Thrustallocation_test_update();
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
  Thrustallocation_test_initialize();
}

void MdlTerminate(void)
{
  Thrustallocation_test_terminate();
}

/* Registration function */
RT_MODEL_Thrustallocation_tes_T *Thrustallocation_test(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Thrustallocation_test_M, 0,
                sizeof(RT_MODEL_Thrustallocation_tes_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Thrustallocation_test_M->solverInfo,
                          &Thrustallocation_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&Thrustallocation_test_M->solverInfo, &rtmGetTPtr
                (Thrustallocation_test_M));
    rtsiSetStepSizePtr(&Thrustallocation_test_M->solverInfo,
                       &Thrustallocation_test_M->Timing.stepSize0);
    rtsiSetdXPtr(&Thrustallocation_test_M->solverInfo,
                 &Thrustallocation_test_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Thrustallocation_test_M->solverInfo, (real_T **)
                         &Thrustallocation_test_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Thrustallocation_test_M->solverInfo,
      &Thrustallocation_test_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Thrustallocation_test_M->solverInfo,
                          (&rtmGetErrorStatus(Thrustallocation_test_M)));
    rtsiSetRTModelPtr(&Thrustallocation_test_M->solverInfo,
                      Thrustallocation_test_M);
  }

  rtsiSetSimTimeStep(&Thrustallocation_test_M->solverInfo, MAJOR_TIME_STEP);
  Thrustallocation_test_M->ModelData.intgData.y =
    Thrustallocation_test_M->ModelData.odeY;
  Thrustallocation_test_M->ModelData.intgData.f[0] =
    Thrustallocation_test_M->ModelData.odeF[0];
  Thrustallocation_test_M->ModelData.intgData.f[1] =
    Thrustallocation_test_M->ModelData.odeF[1];
  Thrustallocation_test_M->ModelData.intgData.f[2] =
    Thrustallocation_test_M->ModelData.odeF[2];
  Thrustallocation_test_M->ModelData.contStates = ((real_T *)
    &Thrustallocation_test_X);
  rtsiSetSolverData(&Thrustallocation_test_M->solverInfo, (void *)
                    &Thrustallocation_test_M->ModelData.intgData);
  rtsiSetSolverName(&Thrustallocation_test_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Thrustallocation_test_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Thrustallocation_test_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Thrustallocation_test_M->Timing.sampleTimes =
      (&Thrustallocation_test_M->Timing.sampleTimesArray[0]);
    Thrustallocation_test_M->Timing.offsetTimes =
      (&Thrustallocation_test_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Thrustallocation_test_M->Timing.sampleTimes[0] = (0.0);
    Thrustallocation_test_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    Thrustallocation_test_M->Timing.offsetTimes[0] = (0.0);
    Thrustallocation_test_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Thrustallocation_test_M, &Thrustallocation_test_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Thrustallocation_test_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Thrustallocation_test_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Thrustallocation_test_M, -1);
  Thrustallocation_test_M->Timing.stepSize0 = 0.01;
  Thrustallocation_test_M->Timing.stepSize1 = 0.01;
  rtmSetFirstInitCond(Thrustallocation_test_M, 1);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Thrustallocation_test_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Thrustallocation_test_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Thrustallocation_test_M->rtwLogInfo, (NULL));
    rtliSetLogT(Thrustallocation_test_M->rtwLogInfo, "tout");
    rtliSetLogX(Thrustallocation_test_M->rtwLogInfo, "");
    rtliSetLogXFinal(Thrustallocation_test_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Thrustallocation_test_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Thrustallocation_test_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(Thrustallocation_test_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Thrustallocation_test_M->rtwLogInfo, 1);
    rtliSetLogY(Thrustallocation_test_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Thrustallocation_test_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Thrustallocation_test_M->rtwLogInfo, (NULL));
  }

  Thrustallocation_test_M->solverInfoPtr = (&Thrustallocation_test_M->solverInfo);
  Thrustallocation_test_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Thrustallocation_test_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Thrustallocation_test_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Thrustallocation_test_M->ModelData.blockIO = ((void *)
    &Thrustallocation_test_B);
  (void) memset(((void *) &Thrustallocation_test_B), 0,
                sizeof(B_Thrustallocation_test_T));

  /* parameters */
  Thrustallocation_test_M->ModelData.defaultParam = ((real_T *)
    &Thrustallocation_test_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Thrustallocation_test_X;
    Thrustallocation_test_M->ModelData.contStates = (x);
    (void) memset((void *)&Thrustallocation_test_X, 0,
                  sizeof(X_Thrustallocation_test_T));
  }

  /* states (dwork) */
  Thrustallocation_test_M->ModelData.dwork = ((void *) &Thrustallocation_test_DW);
  (void) memset((void *)&Thrustallocation_test_DW, 0,
                sizeof(DW_Thrustallocation_test_T));

  /* Initialize Sizes */
  Thrustallocation_test_M->Sizes.numContStates = (18);/* Number of continuous states */
  Thrustallocation_test_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Thrustallocation_test_M->Sizes.numY = (0);/* Number of model outputs */
  Thrustallocation_test_M->Sizes.numU = (0);/* Number of model inputs */
  Thrustallocation_test_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Thrustallocation_test_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Thrustallocation_test_M->Sizes.numBlocks = (356);/* Number of blocks */
  Thrustallocation_test_M->Sizes.numBlockIO = (171);/* Number of block outputs */
  Thrustallocation_test_M->Sizes.numBlockPrms = (497);/* Sum of parameter "widths" */
  return Thrustallocation_test_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : Thrustallocation_test
 * Model version : 1.10
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Fri Jun 17 16:52:41 2016
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_Thrustallocation_test
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

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

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 35:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 36:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 37:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 38:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 39:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,41,Complex);

   case 49:
    return NIRT_GetValueByDataType(ptr,subindex,48,Complex);

   case 57:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 58:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 59:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 60:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

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
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 38:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 39:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,41,Complex);

   case 49:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,48,Complex);

   case 57:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 58:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 59:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 60:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern Thrustallocation_test_rtModel *S;
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

  // Thrustallocation_test/Thruster control /Thruster 1/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.reset, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster control /Thruster 2/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.reset_e, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster control /Thruster 3/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.reset_l, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster control /Thruster 4/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.reset_o, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster control /Thruster 5/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.reset_k, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster control /Thruster 6/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.reset_km, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/core_controller
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.core_controller, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/ArrowUp
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.ArrowUp, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/ArrowDown
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.ArrowDown, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Start
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.Start, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/L2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.L2_continuous, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster measurment/thr_angle_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.thr_angle_1, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster measurment/thr_angle_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.thr_angle_2, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster measurment/thr_angle_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.thr_angle_3, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster measurment/thr_angle_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.thr_angle_4, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster measurment/thr_angle_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.thr_angle_5, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster measurment/thr_angle_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.thr_angle_6, 0, data[index
      ++], 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/PosYLeft
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.PosYLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/PosXLeft
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.PosXLeft, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/R2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.R2_continuous, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thrust allocation/Angle_controller
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.Angle_controller, 0,
      data[index++], 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thrust allocation/fmin
  if (TaskSampleHit[0]) {
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_B.fmin, count, data[index++],
        23, 0);
    }
  } else {
    index += 6;
  }

  // Thrustallocation_test/reset
  if (TaskSampleHit[1]) {
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_B.reset_c, count,
        data[index++], 23, 0);
    }
  } else {
    index += 6;
  }

  // Thrustallocation_test/Thruster control /Thruster 1/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.reset_j, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster control /Thruster 2/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.reset_i, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster control /Thruster 3/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.reset_e3, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster control /Thruster 4/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.reset_j4, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster control /Thruster 5/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.reset_p, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Thruster control /Thruster 6/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&Thrustallocation_test_B.reset_en, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 39;
}

int32_t NumOutputPorts(void)
{
  return 37;
}

double ni_extout[37];

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

  // Thrustallocation_test/Thrust allocation/A1Matrix : Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    for (count = 0; count < 9; count++) {
      ni_extout[index++] = NIRT_GetValueByDataType
        (&Thrustallocation_test_B.A1Matrix, count, 25, 0);
    }
  } else {
    index += 9;
  }

  // Thrustallocation_test/Thrust allocation/A2Matrix: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    for (count = 0; count < 9; count++) {
      ni_extout[index++] = NIRT_GetValueByDataType
        (&Thrustallocation_test_B.A2Matrix, count, 25, 0);
    }
  } else {
    index += 9;
  }

  // Thrustallocation_test/Thrust allocation/A3Matrix: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    for (count = 0; count < 9; count++) {
      ni_extout[index++] = NIRT_GetValueByDataType
        (&Thrustallocation_test_B.A3Matrix, count, 25, 0);
    }
  } else {
    index += 9;
  }

  // Thrustallocation_test/Thrust allocation/BMatrix: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Thrustallocation_test_B.BMatrix, 0, 22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Thrustallocation_test_B.BMatrix, 1, 22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Thrustallocation_test_B.BMatrix, 2, 22, 0);
  } else {
    index += 3;
  }

  // Thrustallocation_test/tau_actual: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Thrustallocation_test_B.commanded_tau, 0, 22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Thrustallocation_test_B.commanded_tau, 1, 22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Thrustallocation_test_B.commanded_tau, 2, 22, 0);
  } else {
    index += 3;
  }

  // Thrustallocation_test/N: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Thrustallocation_test_B.Product, 0, 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Thrustallocation_test_B.Product1, 0, 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/Y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Thrustallocation_test_B.Product2, 0, 0, 0);
  } else {
    index += 1;
  }

  // Thrustallocation_test/u_limit: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&Thrustallocation_test_B.y, 0,
      0, 0);
  } else {
    index += 1;
  }

  if (data != NULL) {
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
  }
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

  // Thrustallocation_test/Thrust allocation/A1Matrix : Virtual Signal # 0
  for (count = 0; count < 9; count++) {
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Thrustallocation_test_B.A1Matrix, count, 25, 0);
  }

  // Thrustallocation_test/Thrust allocation/A2Matrix: Virtual Signal # 0
  for (count = 0; count < 9; count++) {
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Thrustallocation_test_B.A2Matrix, count, 25, 0);
  }

  // Thrustallocation_test/Thrust allocation/A3Matrix: Virtual Signal # 0
  for (count = 0; count < 9; count++) {
    ni_extout[index++] = NIRT_GetValueByDataType
      (&Thrustallocation_test_B.A3Matrix, count, 25, 0);
  }

  // Thrustallocation_test/Thrust allocation/BMatrix: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Thrustallocation_test_B.BMatrix,
    0, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&Thrustallocation_test_B.BMatrix,
    1, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&Thrustallocation_test_B.BMatrix,
    2, 22, 0);

  // Thrustallocation_test/tau_actual: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&Thrustallocation_test_B.commanded_tau, 0, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&Thrustallocation_test_B.commanded_tau, 1, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&Thrustallocation_test_B.commanded_tau, 2, 22, 0);

  // Thrustallocation_test/N: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Thrustallocation_test_B.Product,
    0, 0, 0);

  // Thrustallocation_test/X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Thrustallocation_test_B.Product1,
    0, 0, 0);

  // Thrustallocation_test/Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Thrustallocation_test_B.Product2,
    0, 0, 0);

  // Thrustallocation_test/u_limit: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&Thrustallocation_test_B.y, 0, 0,
    0);
  return NI_OK;
}

/* Undefine parameter macros. The undef allows us to access the real declarations.
   In the Simulink(R) generated code, the parameters are redefined to be the read-side of rtParameter.*/
#define _NI_UNDEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"

/* All elements by default (including scalars) have 2 dimensions [1,1] */
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0, "thrustallocation_test/Thrust allocation/Constant1/Value", offsetof
    (P_Thrustallocation_test_T, C), 27, 24, 2, 0, 0 },

  { 1, "thrustallocation_test/Thrust allocation/Constant2/Value", offsetof
    (P_Thrustallocation_test_T, C), 27, 24, 2, 2, 0 },

  { 2, "thrustallocation_test/Parameters From initfile distributed /D/Value",
    offsetof(P_Thrustallocation_test_T, D), 57, 1, 2, 4, 0 },

  { 3,
    "thrustallocation_test/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_Thrustallocation_test_T, I_s), 57, 1, 2, 6, 0 },

  { 4,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Inertia compensation/Gain",
    offsetof(P_Thrustallocation_test_T, I_s), 57, 1, 2, 8, 0 },

  { 5,
    "thrustallocation_test/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_Thrustallocation_test_T, I_s), 57, 1, 2, 10, 0 },

  { 6,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Inertia compensation/Gain",
    offsetof(P_Thrustallocation_test_T, I_s), 57, 1, 2, 12, 0 },

  { 7,
    "thrustallocation_test/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_Thrustallocation_test_T, I_s), 57, 1, 2, 14, 0 },

  { 8,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Inertia compensation/Gain",
    offsetof(P_Thrustallocation_test_T, I_s), 57, 1, 2, 16, 0 },

  { 9,
    "thrustallocation_test/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_Thrustallocation_test_T, I_s), 57, 1, 2, 18, 0 },

  { 10,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Inertia compensation/Gain",
    offsetof(P_Thrustallocation_test_T, I_s), 57, 1, 2, 20, 0 },

  { 11,
    "thrustallocation_test/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_Thrustallocation_test_T, I_s), 57, 1, 2, 22, 0 },

  { 12,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Inertia compensation/Gain",
    offsetof(P_Thrustallocation_test_T, I_s), 57, 1, 2, 24, 0 },

  { 13,
    "thrustallocation_test/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_Thrustallocation_test_T, I_s), 57, 1, 2, 26, 0 },

  { 14,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Inertia compensation/Gain",
    offsetof(P_Thrustallocation_test_T, I_s), 57, 1, 2, 28, 0 },

  { 15,
    "thrustallocation_test/Thruster control /Thruster 1/Shaft dynamics/K_omega/Gain",
    offsetof(P_Thrustallocation_test_T, K_omega), 57, 1, 2, 30, 0 },

  { 16,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, K_omega), 57, 1, 2, 32, 0 },

  { 17,
    "thrustallocation_test/Thruster control /Thruster 2/Shaft dynamics/K_omega/Gain",
    offsetof(P_Thrustallocation_test_T, K_omega), 57, 1, 2, 34, 0 },

  { 18,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, K_omega), 57, 1, 2, 36, 0 },

  { 19,
    "thrustallocation_test/Thruster control /Thruster 3/Shaft dynamics/K_omega/Gain",
    offsetof(P_Thrustallocation_test_T, K_omega), 57, 1, 2, 38, 0 },

  { 20,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, K_omega), 57, 1, 2, 40, 0 },

  { 21,
    "thrustallocation_test/Thruster control /Thruster 4/Shaft dynamics/K_omega/Gain",
    offsetof(P_Thrustallocation_test_T, K_omega), 57, 1, 2, 42, 0 },

  { 22,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, K_omega), 57, 1, 2, 44, 0 },

  { 23,
    "thrustallocation_test/Thruster control /Thruster 5/Shaft dynamics/K_omega/Gain",
    offsetof(P_Thrustallocation_test_T, K_omega), 57, 1, 2, 46, 0 },

  { 24,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, K_omega), 57, 1, 2, 48, 0 },

  { 25,
    "thrustallocation_test/Thruster control /Thruster 6/Shaft dynamics/K_omega/Gain",
    offsetof(P_Thrustallocation_test_T, K_omega), 57, 1, 2, 50, 0 },

  { 26,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, K_omega), 57, 1, 2, 52, 0 },

  { 27,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Core controller/Ki/Gain",
    offsetof(P_Thrustallocation_test_T, Kp), 57, 1, 2, 54, 0 },

  { 28,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Core controller/Kp/Gain",
    offsetof(P_Thrustallocation_test_T, Kp), 57, 1, 2, 56, 0 },

  { 29,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Core controller/Ki/Gain",
    offsetof(P_Thrustallocation_test_T, Kp), 57, 1, 2, 58, 0 },

  { 30,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Core controller/Kp/Gain",
    offsetof(P_Thrustallocation_test_T, Kp), 57, 1, 2, 60, 0 },

  { 31,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Core controller/Ki/Gain",
    offsetof(P_Thrustallocation_test_T, Kp), 57, 1, 2, 62, 0 },

  { 32,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Core controller/Kp/Gain",
    offsetof(P_Thrustallocation_test_T, Kp), 57, 1, 2, 64, 0 },

  { 33,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Core controller/Ki/Gain",
    offsetof(P_Thrustallocation_test_T, Kp), 57, 1, 2, 66, 0 },

  { 34,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Core controller/Kp/Gain",
    offsetof(P_Thrustallocation_test_T, Kp), 57, 1, 2, 68, 0 },

  { 35,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Core controller/Ki/Gain",
    offsetof(P_Thrustallocation_test_T, Kp), 57, 1, 2, 70, 0 },

  { 36,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Core controller/Kp/Gain",
    offsetof(P_Thrustallocation_test_T, Kp), 57, 1, 2, 72, 0 },

  { 37,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Core controller/Ki/Gain",
    offsetof(P_Thrustallocation_test_T, Kp), 57, 1, 2, 74, 0 },

  { 38,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Core controller/Kp/Gain",
    offsetof(P_Thrustallocation_test_T, Kp), 57, 1, 2, 76, 0 },

  { 39, "thrustallocation_test/Parameters From initfile distributed /Kq/Value",
    offsetof(P_Thrustallocation_test_T, Kq), 57, 1, 2, 78, 0 },

  { 40, "thrustallocation_test/Parameters From initfile distributed /Kqr/Value",
    offsetof(P_Thrustallocation_test_T, Kqr), 57, 1, 2, 80, 0 },

  { 41, "thrustallocation_test/Parameters From initfile distributed /Kt/Value",
    offsetof(P_Thrustallocation_test_T, Kt), 57, 1, 2, 82, 0 },

  { 42, "thrustallocation_test/Parameters From initfile distributed /Ktr/Value",
    offsetof(P_Thrustallocation_test_T, Ktr), 57, 1, 2, 84, 0 },

  { 43,
    "thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed/Max Rotation Rate/UpperLimit",
    offsetof(P_Thrustallocation_test_T, Max_rotation), 57, 1, 2, 86, 0 },

  { 44,
    "thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed/Max Rotation Rate/LowerLimit",
    offsetof(P_Thrustallocation_test_T, Max_rotation), 57, 1, 2, 88, 0 },

  { 45,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/UpperLimit",
    offsetof(P_Thrustallocation_test_T, Max_thrust), 57, 1, 2, 90, 0 },

  { 46,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/Saturation 7/LowerLimit",
    offsetof(P_Thrustallocation_test_T, Max_thrust), 57, 1, 2, 92, 0 },

  { 47,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Qf_0/Gain",
    offsetof(P_Thrustallocation_test_T, Q_f0), 57, 1, 2, 94, 0 },

  { 48,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Qf_0/Gain",
    offsetof(P_Thrustallocation_test_T, Q_f0), 57, 1, 2, 96, 0 },

  { 49,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Qf_0/Gain",
    offsetof(P_Thrustallocation_test_T, Q_f0), 57, 1, 2, 98, 0 },

  { 50,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Qf_0/Gain",
    offsetof(P_Thrustallocation_test_T, Q_f0), 57, 1, 2, 100, 0 },

  { 51,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Qf_0/Gain",
    offsetof(P_Thrustallocation_test_T, Q_f0), 57, 1, 2, 102, 0 },

  { 52,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Qf_0/Gain",
    offsetof(P_Thrustallocation_test_T, Q_f0), 57, 1, 2, 104, 0 },

  { 53, "thrustallocation_test/Parameters From initfile distributed /Rho/Value",
    offsetof(P_Thrustallocation_test_T, Rho), 57, 1, 2, 106, 0 },

  { 54,
    "thrustallocation_test/Parameters From initfile distributed /Constant4/Value",
    offsetof(P_Thrustallocation_test_T, eps), 57, 1, 2, 108, 0 },

  { 55,
    "thrustallocation_test/Thrust allocation/Constant to avoid singularities/Value",
    offsetof(P_Thrustallocation_test_T, eps), 57, 1, 2, 110, 0 },

  { 56,
    "thrustallocation_test/Parameters From initfile distributed /Constant/Value",
    offsetof(P_Thrustallocation_test_T, eps_c), 57, 1, 2, 112, 0 },

  { 57,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, epsilon), 57, 1, 2, 114, 0 },

  { 58,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, epsilon), 57, 1, 2, 116, 0 },

  { 59,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, epsilon), 57, 1, 2, 118, 0 },

  { 60,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, epsilon), 57, 1, 2, 120, 0 },

  { 61,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, epsilon), 57, 1, 2, 122, 0 },

  { 62,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, epsilon), 57, 1, 2, 124, 0 },

  { 63,
    "thrustallocation_test/Parameters From initfile distributed /Constant1/Value",
    offsetof(P_Thrustallocation_test_T, k_cc), 57, 1, 2, 126, 0 },

  { 64,
    "thrustallocation_test/Parameters From initfile distributed /Constant5/Value",
    offsetof(P_Thrustallocation_test_T, n_c), 57, 1, 2, 128, 0 },

  { 65,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, n_max), 57, 1, 2, 130, 0 },

  { 66,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, n_max), 57, 1, 2, 132, 0 },

  { 67,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, n_max), 57, 1, 2, 134, 0 },

  { 68,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, n_max), 57, 1, 2, 136, 0 },

  { 69,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, n_max), 57, 1, 2, 138, 0 },

  { 70,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_Thrustallocation_test_T, n_max), 57, 1, 2, 140, 0 },

  { 71,
    "thrustallocation_test/Parameters From initfile distributed /Constant2/Value",
    offsetof(P_Thrustallocation_test_T, p_cc), 57, 1, 2, 142, 0 },

  { 72,
    "thrustallocation_test/Parameters From initfile distributed /Constant3/Value",
    offsetof(P_Thrustallocation_test_T, r_cc), 57, 1, 2, 144, 0 },

  { 73,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_Thrustallocation_test_T, DiscreteDerivative_ICPrevScaled), 57, 1,
    2, 146, 0 },

  { 74,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_Thrustallocation_test_T, DiscreteDerivative_ICPrevScal_p), 57, 1,
    2, 148, 0 },

  { 75,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_Thrustallocation_test_T, DiscreteDerivative_ICPrevScal_c), 57, 1,
    2, 150, 0 },

  { 76,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_Thrustallocation_test_T, DiscreteDerivative_ICPrevScal_e), 57, 1,
    2, 152, 0 },

  { 77,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_Thrustallocation_test_T, DiscreteDerivative_ICPrevScal_f), 57, 1,
    2, 154, 0 },

  { 78,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_Thrustallocation_test_T, DiscreteDerivative_ICPrevSca_es), 57, 1,
    2, 156, 0 },

  { 79,
    "thrustallocation_test/u_limiter/Detect Increase/Delay Input1/InitialCondition",
    offsetof(P_Thrustallocation_test_T, DetectIncrease_vinit), 57, 1, 2, 158, 0
  },

  { 80,
    "thrustallocation_test/u_limiter/Detect Increase1/Delay Input1/InitialCondition",
    offsetof(P_Thrustallocation_test_T, DetectIncrease1_vinit), 57, 1, 2, 160, 0
  },

  { 81,
    "thrustallocation_test/u_limiter/Detect Increase2/Delay Input1/InitialCondition",
    offsetof(P_Thrustallocation_test_T, DetectIncrease2_vinit), 57, 1, 2, 162, 0
  },

  { 82,
    "thrustallocation_test/Thruster control /Thruster 1/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Integrator_IC), 57, 1, 2, 164, 0 },

  { 83,
    "thrustallocation_test/Thruster control /Thruster 1/Losses (placeholder)/Value",
    offsetof(P_Thrustallocation_test_T, Lossesplaceholder_Value), 57, 1, 2, 166,
    0 },

  { 84,
    "thrustallocation_test/Thruster control /Thruster 2/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Integrator_IC_c), 57, 1, 2, 168, 0 },

  { 85,
    "thrustallocation_test/Thruster control /Thruster 2/Losses (placeholder)/Value",
    offsetof(P_Thrustallocation_test_T, Lossesplaceholder_Value_f), 57, 1, 2,
    170, 0 },

  { 86,
    "thrustallocation_test/Thruster control /Thruster 3/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Integrator_IC_g), 57, 1, 2, 172, 0 },

  { 87,
    "thrustallocation_test/Thruster control /Thruster 3/Losses (placeholder)/Value",
    offsetof(P_Thrustallocation_test_T, Lossesplaceholder_Value_fv), 57, 1, 2,
    174, 0 },

  { 88,
    "thrustallocation_test/Thruster control /Thruster 4/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Integrator_IC_e), 57, 1, 2, 176, 0 },

  { 89,
    "thrustallocation_test/Thruster control /Thruster 4/Losses (placeholder)/Value",
    offsetof(P_Thrustallocation_test_T, Lossesplaceholder_Value_e), 57, 1, 2,
    178, 0 },

  { 90,
    "thrustallocation_test/Thruster control /Thruster 5/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Integrator_IC_l), 57, 1, 2, 180, 0 },

  { 91,
    "thrustallocation_test/Thruster control /Thruster 5/Losses (placeholder)/Value",
    offsetof(P_Thrustallocation_test_T, Lossesplaceholder_Value_a), 57, 1, 2,
    182, 0 },

  { 92,
    "thrustallocation_test/Thruster control /Thruster 6/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Integrator_IC_j), 57, 1, 2, 184, 0 },

  { 93,
    "thrustallocation_test/Thruster control /Thruster 6/Losses (placeholder)/Value",
    offsetof(P_Thrustallocation_test_T, Lossesplaceholder_Value_i), 57, 1, 2,
    186, 0 },

  { 94,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/Shaft speed thruster 1/Value",
    offsetof(P_Thrustallocation_test_T, Shaftspeedthruster1_Value), 57, 1, 2,
    188, 0 },

  { 95,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/Shaft speed thruster 2/Value",
    offsetof(P_Thrustallocation_test_T, Shaftspeedthruster2_Value), 57, 1, 2,
    190, 0 },

  { 96,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/Shaft speed thruster 3/Value",
    offsetof(P_Thrustallocation_test_T, Shaftspeedthruster3_Value), 57, 1, 2,
    192, 0 },

  { 97,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/Shaft speed thruster 4/Value",
    offsetof(P_Thrustallocation_test_T, Shaftspeedthruster4_Value), 57, 1, 2,
    194, 0 },

  { 98,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/Shaft speed thruster 5/Value",
    offsetof(P_Thrustallocation_test_T, Shaftspeedthruster5_Value), 57, 1, 2,
    196, 0 },

  { 99,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/Shaft speed thruster 6/Value",
    offsetof(P_Thrustallocation_test_T, Shaftspeedthruster6_Value), 57, 1, 2,
    198, 0 },

  { 100, "thrustallocation_test/u_limiter/Memory/X0", offsetof
    (P_Thrustallocation_test_T, Memory_X0), 57, 1, 2, 200, 0 },

  { 101, "thrustallocation_test/Thrust allocation/Radians to Degrees/Gain/Gain",
    offsetof(P_Thrustallocation_test_T, Gain_Gain), 57, 1, 2, 202, 0 },

  { 102, "thrustallocation_test/Thrust allocation/X-position Thruster1/Value",
    offsetof(P_Thrustallocation_test_T, XpositionThruster1_Value), 34, 6, 2, 204,
    0 },

  { 103, "thrustallocation_test/Thrust allocation/Y-position Thruster2/Value",
    offsetof(P_Thrustallocation_test_T, YpositionThruster2_Value), 34, 6, 2, 206,
    0 },

  { 104, "thrustallocation_test/Gain1/Gain", offsetof(P_Thrustallocation_test_T,
    Gain1_Gain), 57, 1, 2, 208, 0 },

  { 105, "thrustallocation_test/Gain/Gain", offsetof(P_Thrustallocation_test_T,
    Gain_Gain_d), 57, 1, 2, 210, 0 },

  { 106, "thrustallocation_test/Thrust allocation/constant angle/Value",
    offsetof(P_Thrustallocation_test_T, constantangle_Value), 34, 6, 2, 212, 0 },

  { 107,
    "thrustallocation_test/Thrust allocation/Choosing Fixed // Azimuth angle/Threshold",
    offsetof(P_Thrustallocation_test_T, ChoosingFixedAzimuthangle_Thres), 57, 1,
    2, 214, 0 },

  { 108,
    "thrustallocation_test/Thruster control /Subsystem1/Saturation 1/UpperLimit",
    offsetof(P_Thrustallocation_test_T, Saturation1_UpperSat), 57, 1, 2, 216, 0
  },

  { 109,
    "thrustallocation_test/Thruster control /Subsystem1/Saturation 1/LowerLimit",
    offsetof(P_Thrustallocation_test_T, Saturation1_LowerSat), 57, 1, 2, 218, 0
  },

  { 110,
    "thrustallocation_test/Thruster control /Subsystem1/Saturation 2/UpperLimit",
    offsetof(P_Thrustallocation_test_T, Saturation2_UpperSat), 57, 1, 2, 220, 0
  },

  { 111,
    "thrustallocation_test/Thruster control /Subsystem1/Saturation 2/LowerLimit",
    offsetof(P_Thrustallocation_test_T, Saturation2_LowerSat), 57, 1, 2, 222, 0
  },

  { 112,
    "thrustallocation_test/Thruster control /Subsystem1/Saturation 3/UpperLimit",
    offsetof(P_Thrustallocation_test_T, Saturation3_UpperSat), 57, 1, 2, 224, 0
  },

  { 113,
    "thrustallocation_test/Thruster control /Subsystem1/Saturation 3/LowerLimit",
    offsetof(P_Thrustallocation_test_T, Saturation3_LowerSat), 57, 1, 2, 226, 0
  },

  { 114,
    "thrustallocation_test/Thruster control /Subsystem1/Saturation 4/UpperLimit",
    offsetof(P_Thrustallocation_test_T, Saturation4_UpperSat), 57, 1, 2, 228, 0
  },

  { 115,
    "thrustallocation_test/Thruster control /Subsystem1/Saturation 4/LowerLimit",
    offsetof(P_Thrustallocation_test_T, Saturation4_LowerSat), 57, 1, 2, 230, 0
  },

  { 116,
    "thrustallocation_test/Thruster control /Subsystem1/Saturation 5/UpperLimit",
    offsetof(P_Thrustallocation_test_T, Saturation5_UpperSat), 57, 1, 2, 232, 0
  },

  { 117,
    "thrustallocation_test/Thruster control /Subsystem1/Saturation 5/LowerLimit",
    offsetof(P_Thrustallocation_test_T, Saturation5_LowerSat), 57, 1, 2, 234, 0
  },

  { 118,
    "thrustallocation_test/Thruster control /Subsystem1/Saturation 6/UpperLimit",
    offsetof(P_Thrustallocation_test_T, Saturation6_UpperSat), 57, 1, 2, 236, 0
  },

  { 119,
    "thrustallocation_test/Thruster control /Subsystem1/Saturation 6/LowerLimit",
    offsetof(P_Thrustallocation_test_T, Saturation6_LowerSat), 57, 1, 2, 238, 0
  },

  { 120, "thrustallocation_test/Radians to Degrees/Gain/Gain", offsetof
    (P_Thrustallocation_test_T, Gain_Gain_c), 57, 1, 2, 240, 0 },

  { 121, "thrustallocation_test/X-position Thruster/Value", offsetof
    (P_Thrustallocation_test_T, XpositionThruster_Value), 34, 6, 2, 242, 0 },

  { 122, "thrustallocation_test/Y-position Thruster/Value", offsetof
    (P_Thrustallocation_test_T, YpositionThruster_Value), 34, 6, 2, 244, 0 },

  { 123, "thrustallocation_test/Constant1/Value", offsetof
    (P_Thrustallocation_test_T, Constant1_Value), 35, 3, 2, 246, 0 },

  { 124, "thrustallocation_test/Thruster control /Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition), 57, 1, 2, 248,
    0 },

  { 125, "thrustallocation_test/Thruster control /Thruster 1/Constant/Value",
    offsetof(P_Thrustallocation_test_T, Constant_Value), 36, 2, 2, 250, 0 },

  { 126, "thrustallocation_test/Thruster control /Thruster 1/Constant1/Value",
    offsetof(P_Thrustallocation_test_T, Constant1_Value_p), 36, 2, 2, 252, 0 },

  { 127,
    "thrustallocation_test/Thruster control /Thruster 1/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition_m), 57, 1, 2, 254,
    0 },

  { 128,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition_mz), 57, 1, 2,
    256, 0 },

  { 129,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Constant1/Value",
    offsetof(P_Thrustallocation_test_T, Constant1_Value_i), 30, 3, 2, 258, 0 },

  { 130,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Constant2/Value",
    offsetof(P_Thrustallocation_test_T, Constant2_Value), 30, 3, 2, 260, 0 },

  { 131,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_Thrustallocation_test_T, DiscreteTransferFcn_InitialStat), 57, 1,
    2, 262, 0 },

  { 132,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_Thrustallocation_test_T, TSamp_WtEt), 0, 1, 2, 264, 0 },

  { 133,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_Thrustallocation_test_T, AccelerationLimit_RisingLim), 0, 1, 2,
    266, 0 },

  { 134,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_Thrustallocation_test_T, AccelerationLimit_FallingLim), 0, 1, 2,
    268, 0 },

  { 135,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_Thrustallocation_test_T, AccelerationLimit_IC), 57, 1, 2, 270, 0
  },

  { 136,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Memory/X0",
    offsetof(P_Thrustallocation_test_T, Memory_X0_f), 57, 1, 2, 272, 0 },

  { 137,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Integrator_IC_p), 57, 1, 2, 274, 0 },

  { 138,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/NaN/Value",
    offsetof(P_Thrustallocation_test_T, NaN_Value), 57, 1, 2, 276, 0 },

  { 139,
    "thrustallocation_test/Thruster control /Thruster 1/Discrete Transfer Fcn/Numerator",
    offsetof(P_Thrustallocation_test_T, DiscreteTransferFcn_InitialSt_n), 57, 1,
    2, 278, 0 },

  { 140, "thrustallocation_test/Thruster control /Thruster 2/Constant/Value",
    offsetof(P_Thrustallocation_test_T, Constant_Value_i), 36, 2, 2, 280, 0 },

  { 141, "thrustallocation_test/Thruster control /Thruster 2/Constant1/Value",
    offsetof(P_Thrustallocation_test_T, Constant1_Value_b), 36, 2, 2, 282, 0 },

  { 142,
    "thrustallocation_test/Thruster control /Thruster 2/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition_k), 57, 1, 2, 284,
    0 },

  { 143,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition_f), 57, 1, 2, 286,
    0 },

  { 144,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Constant1/Value",
    offsetof(P_Thrustallocation_test_T, Constant1_Value_g), 30, 3, 2, 288, 0 },

  { 145,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Constant2/Value",
    offsetof(P_Thrustallocation_test_T, Constant2_Value_a), 30, 3, 2, 290, 0 },

  { 146,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_Thrustallocation_test_T, DiscreteTransferFcn_InitialSt_c), 57, 1,
    2, 292, 0 },

  { 147,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_Thrustallocation_test_T, TSamp_WtEt_j), 0, 1, 2, 294, 0 },

  { 148,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_Thrustallocation_test_T, AccelerationLimit_RisingLim_b), 0, 1, 2,
    296, 0 },

  { 149,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_Thrustallocation_test_T, AccelerationLimit_FallingLim_f), 0, 1, 2,
    298, 0 },

  { 150,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_Thrustallocation_test_T, AccelerationLimit_IC_e), 57, 1, 2, 300,
    0 },

  { 151,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Memory/X0",
    offsetof(P_Thrustallocation_test_T, Memory_X0_h), 57, 1, 2, 302, 0 },

  { 152,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Integrator_IC_o), 57, 1, 2, 304, 0 },

  { 153,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/NaN/Value",
    offsetof(P_Thrustallocation_test_T, NaN_Value_j), 57, 1, 2, 306, 0 },

  { 154,
    "thrustallocation_test/Thruster control /Thruster 2/Discrete Transfer Fcn/Numerator",
    offsetof(P_Thrustallocation_test_T, DiscreteTransferFcn_InitialSt_d), 57, 1,
    2, 308, 0 },

  { 155, "thrustallocation_test/Thruster control /Thruster 3/Constant/Value",
    offsetof(P_Thrustallocation_test_T, Constant_Value_g), 36, 2, 2, 310, 0 },

  { 156, "thrustallocation_test/Thruster control /Thruster 3/Constant1/Value",
    offsetof(P_Thrustallocation_test_T, Constant1_Value_a), 36, 2, 2, 312, 0 },

  { 157,
    "thrustallocation_test/Thruster control /Thruster 3/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition_b), 57, 1, 2, 314,
    0 },

  { 158,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition_h), 57, 1, 2, 316,
    0 },

  { 159,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Constant1/Value",
    offsetof(P_Thrustallocation_test_T, Constant1_Value_h), 30, 3, 2, 318, 0 },

  { 160,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Constant2/Value",
    offsetof(P_Thrustallocation_test_T, Constant2_Value_g), 30, 3, 2, 320, 0 },

  { 161,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_Thrustallocation_test_T, DiscreteTransferFcn_InitialSt_m), 57, 1,
    2, 322, 0 },

  { 162,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_Thrustallocation_test_T, TSamp_WtEt_l), 0, 1, 2, 324, 0 },

  { 163,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_Thrustallocation_test_T, Accelerationlimiter_RisingLim), 0, 1, 2,
    326, 0 },

  { 164,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_Thrustallocation_test_T, Accelerationlimiter_FallingLim), 0, 1, 2,
    328, 0 },

  { 165,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Accelerationlimiter_IC), 57, 1, 2, 330,
    0 },

  { 166,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Memory/X0",
    offsetof(P_Thrustallocation_test_T, Memory_X0_e), 57, 1, 2, 332, 0 },

  { 167,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Integrator_IC_pf), 57, 1, 2, 334, 0 },

  { 168,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/NaN/Value",
    offsetof(P_Thrustallocation_test_T, NaN_Value_e), 57, 1, 2, 336, 0 },

  { 169,
    "thrustallocation_test/Thruster control /Thruster 3/Discrete Transfer Fcn/Numerator",
    offsetof(P_Thrustallocation_test_T, DiscreteTransferFcn_InitialS_nl), 57, 1,
    2, 338, 0 },

  { 170, "thrustallocation_test/Thruster control /Thruster 4/Constant/Value",
    offsetof(P_Thrustallocation_test_T, Constant_Value_j), 36, 2, 2, 340, 0 },

  { 171, "thrustallocation_test/Thruster control /Thruster 4/Constant1/Value",
    offsetof(P_Thrustallocation_test_T, Constant1_Value_bp), 36, 2, 2, 342, 0 },

  { 172,
    "thrustallocation_test/Thruster control /Thruster 4/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition_g), 57, 1, 2, 344,
    0 },

  { 173,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition_e), 57, 1, 2, 346,
    0 },

  { 174,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Constant1/Value",
    offsetof(P_Thrustallocation_test_T, Constant1_Value_f), 30, 3, 2, 348, 0 },

  { 175,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Constant2/Value",
    offsetof(P_Thrustallocation_test_T, Constant2_Value_i), 30, 3, 2, 350, 0 },

  { 176,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_Thrustallocation_test_T, DiscreteTransferFcn_InitialS_mq), 57, 1,
    2, 352, 0 },

  { 177,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_Thrustallocation_test_T, TSamp_WtEt_n), 0, 1, 2, 354, 0 },

  { 178,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_Thrustallocation_test_T, Accelerationlimiter_RisingLim_n), 0, 1,
    2, 356, 0 },

  { 179,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_Thrustallocation_test_T, Accelerationlimiter_FallingLi_o), 0, 1,
    2, 358, 0 },

  { 180,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Accelerationlimiter_IC_m), 57, 1, 2, 360,
    0 },

  { 181,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Memory/X0",
    offsetof(P_Thrustallocation_test_T, Memory_X0_d), 57, 1, 2, 362, 0 },

  { 182,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Integrator_IC_f), 57, 1, 2, 364, 0 },

  { 183,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/NaN/Value",
    offsetof(P_Thrustallocation_test_T, NaN_Value_o), 57, 1, 2, 366, 0 },

  { 184,
    "thrustallocation_test/Thruster control /Thruster 4/Discrete Transfer Fcn/Numerator",
    offsetof(P_Thrustallocation_test_T, DiscreteTransferFcn_InitialSt_i), 57, 1,
    2, 368, 0 },

  { 185, "thrustallocation_test/Thruster control /Thruster 5/Constant/Value",
    offsetof(P_Thrustallocation_test_T, Constant_Value_k), 36, 2, 2, 370, 0 },

  { 186, "thrustallocation_test/Thruster control /Thruster 5/Constant1/Value",
    offsetof(P_Thrustallocation_test_T, Constant1_Value_n), 36, 2, 2, 372, 0 },

  { 187,
    "thrustallocation_test/Thruster control /Thruster 5/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition_i), 57, 1, 2, 374,
    0 },

  { 188,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition_o), 57, 1, 2, 376,
    0 },

  { 189,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Constant1/Value",
    offsetof(P_Thrustallocation_test_T, Constant1_Value_e), 30, 3, 2, 378, 0 },

  { 190,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Constant2/Value",
    offsetof(P_Thrustallocation_test_T, Constant2_Value_n), 30, 3, 2, 380, 0 },

  { 191,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_Thrustallocation_test_T, DiscreteTransferFcn_InitialS_mc), 57, 1,
    2, 382, 0 },

  { 192,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_Thrustallocation_test_T, TSamp_WtEt_m), 0, 1, 2, 384, 0 },

  { 193,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_Thrustallocation_test_T, Accelerationlimiter_RisingLim_j), 0, 1,
    2, 386, 0 },

  { 194,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_Thrustallocation_test_T, Accelerationlimiter_FallingLi_i), 0, 1,
    2, 388, 0 },

  { 195,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Accelerationlimiter_IC_e), 57, 1, 2, 390,
    0 },

  { 196,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Memory/X0",
    offsetof(P_Thrustallocation_test_T, Memory_X0_b), 57, 1, 2, 392, 0 },

  { 197,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Integrator_IC_e2), 57, 1, 2, 394, 0 },

  { 198,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/NaN/Value",
    offsetof(P_Thrustallocation_test_T, NaN_Value_d), 57, 1, 2, 396, 0 },

  { 199,
    "thrustallocation_test/Thruster control /Thruster 5/Discrete Transfer Fcn/Numerator",
    offsetof(P_Thrustallocation_test_T, DiscreteTransferFcn_InitialSt_h), 57, 1,
    2, 398, 0 },

  { 200, "thrustallocation_test/Thruster control /Thruster 6/Constant/Value",
    offsetof(P_Thrustallocation_test_T, Constant_Value_gp), 36, 2, 2, 400, 0 },

  { 201, "thrustallocation_test/Thruster control /Thruster 6/Constant1/Value",
    offsetof(P_Thrustallocation_test_T, Constant1_Value_c), 36, 2, 2, 402, 0 },

  { 202,
    "thrustallocation_test/Thruster control /Thruster 6/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition_bd), 57, 1, 2,
    404, 0 },

  { 203,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Delay_InitialCondition_j), 57, 1, 2, 406,
    0 },

  { 204,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Constant1/Value",
    offsetof(P_Thrustallocation_test_T, Constant1_Value_j), 30, 3, 2, 408, 0 },

  { 205,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Constant2/Value",
    offsetof(P_Thrustallocation_test_T, Constant2_Value_l), 30, 3, 2, 410, 0 },

  { 206,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_Thrustallocation_test_T, DiscreteTransferFcn_InitialSt_l), 57, 1,
    2, 412, 0 },

  { 207,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_Thrustallocation_test_T, TSamp_WtEt_b), 0, 1, 2, 414, 0 },

  { 208,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_Thrustallocation_test_T, Accelerationlimiter_RisingLi_nn), 0, 1,
    2, 416, 0 },

  { 209,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_Thrustallocation_test_T, Accelerationlimiter_FallingLi_a), 0, 1,
    2, 418, 0 },

  { 210,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Accelerationlimiter_IC_k), 57, 1, 2, 420,
    0 },

  { 211,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Memory/X0",
    offsetof(P_Thrustallocation_test_T, Memory_X0_g), 57, 1, 2, 422, 0 },

  { 212,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_Thrustallocation_test_T, Integrator_IC_eh), 57, 1, 2, 424, 0 },

  { 213,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/NaN/Value",
    offsetof(P_Thrustallocation_test_T, NaN_Value_eh), 57, 1, 2, 426, 0 },

  { 214,
    "thrustallocation_test/Thruster control /Thruster 6/Discrete Transfer Fcn/Numerator",
    offsetof(P_Thrustallocation_test_T, DiscreteTransferFcn_InitialS_dp), 57, 1,
    2, 428, 0 },

  { 215, "thrustallocation_test/Velocity/InitialCondition", offsetof
    (P_Thrustallocation_test_T, Velocity_IC), 35, 3, 2, 430, 0 },

  { 216, "thrustallocation_test/Thruster control /Delay/DelayLength", offsetof
    (P_Thrustallocation_test_T, Delay_DelayLength), 58, 1, 2, 432, 0 },

  { 217, "thrustallocation_test/Thruster control /Thruster 1/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, Delay_DelayLength_f), 58, 1, 2, 434, 0 },

  { 218,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, Delay_DelayLength_o), 58, 1, 2, 436, 0 },

  { 219, "thrustallocation_test/Thruster control /Thruster 2/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, Delay_DelayLength_k), 58, 1, 2, 438, 0 },

  { 220,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, Delay_DelayLength_d), 58, 1, 2, 440, 0 },

  { 221, "thrustallocation_test/Thruster control /Thruster 3/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, Delay_DelayLength_j), 58, 1, 2, 442, 0 },

  { 222,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, Delay_DelayLength_n), 58, 1, 2, 444, 0 },

  { 223, "thrustallocation_test/Thruster control /Thruster 4/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, Delay_DelayLength_e), 58, 1, 2, 446, 0 },

  { 224,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, Delay_DelayLength_l), 58, 1, 2, 448, 0 },

  { 225, "thrustallocation_test/Thruster control /Thruster 5/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, Delay_DelayLength_m), 58, 1, 2, 450, 0 },

  { 226,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, Delay_DelayLength_g), 58, 1, 2, 452, 0 },

  { 227, "thrustallocation_test/Thruster control /Thruster 6/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, Delay_DelayLength_np), 58, 1, 2, 454, 0
  },

  { 228,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, Delay_DelayLength_c), 58, 1, 2, 456, 0 },

  { 229,
    "thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed/Discrete-Time Integrator/gainval",
    offsetof(P_Thrustallocation_test_T,
             CoreSubsys.DiscreteTimeIntegrator_gainval), 0, 1, 2, 458, 0 },

  { 230,
    "thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed/Degrees to Radians/Gain1/Gain",
    offsetof(P_Thrustallocation_test_T, CoreSubsys.Gain1_Gain), 57, 1, 2, 460, 0
  },

  { 231,
    "thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed/Delay/InitialCondition",
    offsetof(P_Thrustallocation_test_T, CoreSubsys.Delay_InitialCondition), 57,
    1, 2, 462, 0 },

  { 232,
    "thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed/Delay/DelayLength",
    offsetof(P_Thrustallocation_test_T, CoreSubsys.Delay_DelayLength), 58, 1, 2,
    464, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 233;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  6, 4,                                /* Parameter at index 0 */
  6, 4,                                /* Parameter at index 1 */
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
  1, 1,                                /* Parameter at index 104 */
  1, 1,                                /* Parameter at index 105 */
  1, 6,                                /* Parameter at index 106 */
  1, 1,                                /* Parameter at index 107 */
  1, 1,                                /* Parameter at index 108 */
  1, 1,                                /* Parameter at index 109 */
  1, 1,                                /* Parameter at index 110 */
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
  1, 6,                                /* Parameter at index 121 */
  1, 6,                                /* Parameter at index 122 */
  3, 1,                                /* Parameter at index 123 */
  1, 1,                                /* Parameter at index 124 */
  1, 2,                                /* Parameter at index 125 */
  1, 2,                                /* Parameter at index 126 */
  1, 1,                                /* Parameter at index 127 */
  1, 1,                                /* Parameter at index 128 */
  1, 3,                                /* Parameter at index 129 */
  1, 3,                                /* Parameter at index 130 */
  1, 1,                                /* Parameter at index 131 */
  1, 1,                                /* Parameter at index 132 */
  1, 1,                                /* Parameter at index 133 */
  1, 1,                                /* Parameter at index 134 */
  1, 1,                                /* Parameter at index 135 */
  1, 1,                                /* Parameter at index 136 */
  1, 1,                                /* Parameter at index 137 */
  1, 1,                                /* Parameter at index 138 */
  1, 1,                                /* Parameter at index 139 */
  1, 2,                                /* Parameter at index 140 */
  1, 2,                                /* Parameter at index 141 */
  1, 1,                                /* Parameter at index 142 */
  1, 1,                                /* Parameter at index 143 */
  1, 3,                                /* Parameter at index 144 */
  1, 3,                                /* Parameter at index 145 */
  1, 1,                                /* Parameter at index 146 */
  1, 1,                                /* Parameter at index 147 */
  1, 1,                                /* Parameter at index 148 */
  1, 1,                                /* Parameter at index 149 */
  1, 1,                                /* Parameter at index 150 */
  1, 1,                                /* Parameter at index 151 */
  1, 1,                                /* Parameter at index 152 */
  1, 1,                                /* Parameter at index 153 */
  1, 1,                                /* Parameter at index 154 */
  1, 2,                                /* Parameter at index 155 */
  1, 2,                                /* Parameter at index 156 */
  1, 1,                                /* Parameter at index 157 */
  1, 1,                                /* Parameter at index 158 */
  1, 3,                                /* Parameter at index 159 */
  1, 3,                                /* Parameter at index 160 */
  1, 1,                                /* Parameter at index 161 */
  1, 1,                                /* Parameter at index 162 */
  1, 1,                                /* Parameter at index 163 */
  1, 1,                                /* Parameter at index 164 */
  1, 1,                                /* Parameter at index 165 */
  1, 1,                                /* Parameter at index 166 */
  1, 1,                                /* Parameter at index 167 */
  1, 1,                                /* Parameter at index 168 */
  1, 1,                                /* Parameter at index 169 */
  1, 2,                                /* Parameter at index 170 */
  1, 2,                                /* Parameter at index 171 */
  1, 1,                                /* Parameter at index 172 */
  1, 1,                                /* Parameter at index 173 */
  1, 3,                                /* Parameter at index 174 */
  1, 3,                                /* Parameter at index 175 */
  1, 1,                                /* Parameter at index 176 */
  1, 1,                                /* Parameter at index 177 */
  1, 1,                                /* Parameter at index 178 */
  1, 1,                                /* Parameter at index 179 */
  1, 1,                                /* Parameter at index 180 */
  1, 1,                                /* Parameter at index 181 */
  1, 1,                                /* Parameter at index 182 */
  1, 1,                                /* Parameter at index 183 */
  1, 1,                                /* Parameter at index 184 */
  1, 2,                                /* Parameter at index 185 */
  1, 2,                                /* Parameter at index 186 */
  1, 1,                                /* Parameter at index 187 */
  1, 1,                                /* Parameter at index 188 */
  1, 3,                                /* Parameter at index 189 */
  1, 3,                                /* Parameter at index 190 */
  1, 1,                                /* Parameter at index 191 */
  1, 1,                                /* Parameter at index 192 */
  1, 1,                                /* Parameter at index 193 */
  1, 1,                                /* Parameter at index 194 */
  1, 1,                                /* Parameter at index 195 */
  1, 1,                                /* Parameter at index 196 */
  1, 1,                                /* Parameter at index 197 */
  1, 1,                                /* Parameter at index 198 */
  1, 1,                                /* Parameter at index 199 */
  1, 2,                                /* Parameter at index 200 */
  1, 2,                                /* Parameter at index 201 */
  1, 1,                                /* Parameter at index 202 */
  1, 1,                                /* Parameter at index 203 */
  1, 3,                                /* Parameter at index 204 */
  1, 3,                                /* Parameter at index 205 */
  1, 1,                                /* Parameter at index 206 */
  1, 1,                                /* Parameter at index 207 */
  1, 1,                                /* Parameter at index 208 */
  1, 1,                                /* Parameter at index 209 */
  1, 1,                                /* Parameter at index 210 */
  1, 1,                                /* Parameter at index 211 */
  1, 1,                                /* Parameter at index 212 */
  1, 1,                                /* Parameter at index 213 */
  1, 1,                                /* Parameter at index 214 */
  3, 1,                                /* Parameter at index 215 */
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
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "thrustallocation_test/Thruster control /Thruster 1/Shaft dynamics/reset",
    0, "", offsetof(B_Thrustallocation_test_T, reset) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "thrustallocation_test/Thruster control /Thruster 2/Shaft dynamics/reset",
    0, "", offsetof(B_Thrustallocation_test_T, reset_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "thrustallocation_test/Thruster control /Thruster 3/Shaft dynamics/reset",
    0, "", offsetof(B_Thrustallocation_test_T, reset_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "thrustallocation_test/Thruster control /Thruster 4/Shaft dynamics/reset",
    0, "", offsetof(B_Thrustallocation_test_T, reset_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "thrustallocation_test/Thruster control /Thruster 5/Shaft dynamics/reset",
    0, "", offsetof(B_Thrustallocation_test_T, reset_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "thrustallocation_test/Thruster control /Thruster 6/Shaft dynamics/reset",
    0, "", offsetof(B_Thrustallocation_test_T, reset_km) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "thrustallocation_test/core_controller", 0, "", offsetof
    (B_Thrustallocation_test_T, core_controller) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "thrustallocation_test/u_limiter/Detect Increase/Delay Input1", 0,
    "U(k-1)", offsetof(B_Thrustallocation_test_T, Uk1) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "thrustallocation_test/ArrowUp", 0, "", offsetof
    (B_Thrustallocation_test_T, ArrowUp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 9, "thrustallocation_test/u_limiter/Detect Increase1/Delay Input1", 0,
    "U(k-1)", offsetof(B_Thrustallocation_test_T, Uk1_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "thrustallocation_test/ArrowDown", 0, "", offsetof
    (B_Thrustallocation_test_T, ArrowDown) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 11, "thrustallocation_test/u_limiter/Detect Increase2/Delay Input1", 0,
    "U(k-1)", offsetof(B_Thrustallocation_test_T, Uk1_h) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "thrustallocation_test/Start", 0, "", offsetof(B_Thrustallocation_test_T,
    Start) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "thrustallocation_test/u_limiter/Memory", 0, "", offsetof
    (B_Thrustallocation_test_T, Memory) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 14, "thrustallocation_test/L2_continuous", 0, "", offsetof
    (B_Thrustallocation_test_T, L2_continuous) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 15, "thrustallocation_test/Thruster measurment/thr_angle_1", 0, "", offsetof
    (B_Thrustallocation_test_T, thr_angle_1) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 16, "thrustallocation_test/Thruster measurment/thr_angle_2", 0, "", offsetof
    (B_Thrustallocation_test_T, thr_angle_2) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 17, "thrustallocation_test/Thruster measurment/thr_angle_3", 0, "", offsetof
    (B_Thrustallocation_test_T, thr_angle_3) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 18, "thrustallocation_test/Thruster measurment/thr_angle_4", 0, "", offsetof
    (B_Thrustallocation_test_T, thr_angle_4) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 19, "thrustallocation_test/Thruster measurment/thr_angle_5", 0, "", offsetof
    (B_Thrustallocation_test_T, thr_angle_5) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 20, "thrustallocation_test/Thruster measurment/thr_angle_6", 0, "", offsetof
    (B_Thrustallocation_test_T, thr_angle_6) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 21, "thrustallocation_test/PosYLeft", 0, "", offsetof
    (B_Thrustallocation_test_T, PosYLeft) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 22, "thrustallocation_test/Product1", 0, "", offsetof
    (B_Thrustallocation_test_T, Product1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 23, "thrustallocation_test/PosXLeft", 0, "", offsetof
    (B_Thrustallocation_test_T, PosXLeft) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 24, "thrustallocation_test/Product2", 0, "", offsetof
    (B_Thrustallocation_test_T, Product2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 25, "thrustallocation_test/R2_continuous", 0, "", offsetof
    (B_Thrustallocation_test_T, R2_continuous) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 26, "thrustallocation_test/Product", 0, "", offsetof
    (B_Thrustallocation_test_T, Product) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 27, "thrustallocation_test/Thrust allocation/Angle_controller", 0, "",
    offsetof(B_Thrustallocation_test_T, Angle_controller) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 28, "thrustallocation_test/Thrust allocation/fmin/(1, 1)", 0, "", offsetof
    (B_Thrustallocation_test_T, fmin) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 29, "thrustallocation_test/Thrust allocation/fmin/(1, 2)", 0, "", offsetof
    (B_Thrustallocation_test_T, fmin) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 30, "thrustallocation_test/Thrust allocation/fmin/(1, 3)", 0, "", offsetof
    (B_Thrustallocation_test_T, fmin) + (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 31, "thrustallocation_test/Thrust allocation/fmin/(1, 4)", 0, "", offsetof
    (B_Thrustallocation_test_T, fmin) + (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 32, "thrustallocation_test/Thrust allocation/fmin/(1, 5)", 0, "", offsetof
    (B_Thrustallocation_test_T, fmin) + (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 33, "thrustallocation_test/Thrust allocation/fmin/(1, 6)", 0, "", offsetof
    (B_Thrustallocation_test_T, fmin) + (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 34,
    "thrustallocation_test/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 1)",
    0, "", offsetof(B_Thrustallocation_test_T, ChoosingFixedAzimuthangle) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 35,
    "thrustallocation_test/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 2)",
    0, "", offsetof(B_Thrustallocation_test_T, ChoosingFixedAzimuthangle) + (1*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 36,
    "thrustallocation_test/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 3)",
    0, "", offsetof(B_Thrustallocation_test_T, ChoosingFixedAzimuthangle) + (2*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 37,
    "thrustallocation_test/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 4)",
    0, "", offsetof(B_Thrustallocation_test_T, ChoosingFixedAzimuthangle) + (3*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 38,
    "thrustallocation_test/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 5)",
    0, "", offsetof(B_Thrustallocation_test_T, ChoosingFixedAzimuthangle) + (4*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 39,
    "thrustallocation_test/Thrust allocation/Choosing Fixed // Azimuth angle/(1, 6)",
    0, "", offsetof(B_Thrustallocation_test_T, ChoosingFixedAzimuthangle) + (5*
    sizeof(real_T)), BLOCKIO_SIG, 23, 1, 2, 0, 0 },

  { 40, "thrustallocation_test/reset/(1, 1)", 0, "", offsetof
    (B_Thrustallocation_test_T, reset_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 41, "thrustallocation_test/reset/(1, 2)", 0, "", offsetof
    (B_Thrustallocation_test_T, reset_c) + (1*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 42, "thrustallocation_test/reset/(1, 3)", 0, "", offsetof
    (B_Thrustallocation_test_T, reset_c) + (2*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 43, "thrustallocation_test/reset/(1, 4)", 0, "", offsetof
    (B_Thrustallocation_test_T, reset_c) + (3*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 44, "thrustallocation_test/reset/(1, 5)", 0, "", offsetof
    (B_Thrustallocation_test_T, reset_c) + (4*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 45, "thrustallocation_test/reset/(1, 6)", 0, "", offsetof
    (B_Thrustallocation_test_T, reset_c) + (5*sizeof(real_T)), BLOCKIO_SIG, 23,
    1, 2, 0, 0 },

  { 46, "thrustallocation_test/Radians to Degrees/Gain/(1, 1)", 0, "", offsetof
    (B_Thrustallocation_test_T, Gain) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 47, "thrustallocation_test/Radians to Degrees/Gain/(1, 2)", 0, "", offsetof
    (B_Thrustallocation_test_T, Gain) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 48, "thrustallocation_test/Radians to Degrees/Gain/(1, 3)", 0, "", offsetof
    (B_Thrustallocation_test_T, Gain) + (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 49, "thrustallocation_test/Radians to Degrees/Gain/(1, 4)", 0, "", offsetof
    (B_Thrustallocation_test_T, Gain) + (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 50, "thrustallocation_test/Radians to Degrees/Gain/(1, 5)", 0, "", offsetof
    (B_Thrustallocation_test_T, Gain) + (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 51, "thrustallocation_test/Radians to Degrees/Gain/(1, 6)", 0, "", offsetof
    (B_Thrustallocation_test_T, Gain) + (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 52, "thrustallocation_test/Constant1/(1, 1)", 0, "", offsetof
    (B_Thrustallocation_test_T, Constant1) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 53, "thrustallocation_test/Constant1/(1, 2)", 0, "", offsetof
    (B_Thrustallocation_test_T, Constant1) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 54, "thrustallocation_test/Constant1/(1, 3)", 0, "", offsetof
    (B_Thrustallocation_test_T, Constant1) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 55, "thrustallocation_test/Thruster control /Delay/(1, 1)", 0, "", offsetof
    (B_Thrustallocation_test_T, Delay) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 56, "thrustallocation_test/Thruster control /Delay/(1, 2)", 0, "", offsetof
    (B_Thrustallocation_test_T, Delay) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 57, "thrustallocation_test/Thruster control /Delay/(1, 3)", 0, "", offsetof
    (B_Thrustallocation_test_T, Delay) + (2*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 58, "thrustallocation_test/Thruster control /Delay/(1, 4)", 0, "", offsetof
    (B_Thrustallocation_test_T, Delay) + (3*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 59, "thrustallocation_test/Thruster control /Delay/(1, 5)", 0, "", offsetof
    (B_Thrustallocation_test_T, Delay) + (4*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 60, "thrustallocation_test/Thruster control /Delay/(1, 6)", 0, "", offsetof
    (B_Thrustallocation_test_T, Delay) + (5*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 61, "thrustallocation_test/Thruster control /Thruster 1/Delay", 0, "",
    offsetof(B_Thrustallocation_test_T, Delay_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 62,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Delay",
    0, "", offsetof(B_Thrustallocation_test_T, Delay_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 63,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_Thrustallocation_test_T, DiscreteTransferFcn) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 64,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_Thrustallocation_test_T, TSamp) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 65,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Inertia compensation",
    0, "", offsetof(B_Thrustallocation_test_T, Inertiacompensation) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 66,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Sum1",
    0, "", offsetof(B_Thrustallocation_test_T, Sum1) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 67,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Memory",
    0, "", offsetof(B_Thrustallocation_test_T, Memory_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 68,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Core controller/Kp",
    0, "", offsetof(B_Thrustallocation_test_T, Kp) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 69,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Core controller/reset",
    0, "", offsetof(B_Thrustallocation_test_T, reset_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 70,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Sum", 0,
    "", offsetof(B_Thrustallocation_test_T, Sum) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 71,
    "thrustallocation_test/Thruster control /Thruster 1/Discrete Transfer Fcn",
    0, "", offsetof(B_Thrustallocation_test_T, DiscreteTransferFcn_a) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 72,
    "thrustallocation_test/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_Thrustallocation_test_T, Findingrotationspeed) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 73,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Core controller/Ki",
    0, "", offsetof(B_Thrustallocation_test_T, Ki) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 74, "thrustallocation_test/Thruster control /Thruster 2/Delay", 0, "",
    offsetof(B_Thrustallocation_test_T, Delay_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 75,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Delay",
    0, "", offsetof(B_Thrustallocation_test_T, Delay_jf) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 76,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_Thrustallocation_test_T, DiscreteTransferFcn_d) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 77,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_Thrustallocation_test_T, TSamp_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 78,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Inertia compensation",
    0, "", offsetof(B_Thrustallocation_test_T, Inertiacompensation_a) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 79,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Sum1",
    0, "", offsetof(B_Thrustallocation_test_T, Sum1_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 80,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Memory",
    0, "", offsetof(B_Thrustallocation_test_T, Memory_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 81,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Core controller/Kp",
    0, "", offsetof(B_Thrustallocation_test_T, Kp_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 82,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Core controller/reset",
    0, "", offsetof(B_Thrustallocation_test_T, reset_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 83,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Sum", 0,
    "", offsetof(B_Thrustallocation_test_T, Sum_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 84,
    "thrustallocation_test/Thruster control /Thruster 2/Discrete Transfer Fcn",
    0, "", offsetof(B_Thrustallocation_test_T, DiscreteTransferFcn_l) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 85,
    "thrustallocation_test/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_Thrustallocation_test_T, Findingrotationspeed_k) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 86,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Core controller/Ki",
    0, "", offsetof(B_Thrustallocation_test_T, Ki_h) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 87, "thrustallocation_test/Thruster control /Thruster 3/Delay", 0, "",
    offsetof(B_Thrustallocation_test_T, Delay_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 88,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Delay",
    0, "", offsetof(B_Thrustallocation_test_T, Delay_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 89,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_Thrustallocation_test_T, DiscreteTransferFcn_k) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 90,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_Thrustallocation_test_T, TSamp_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 91,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Inertia compensation",
    0, "", offsetof(B_Thrustallocation_test_T, Inertiacompensation_j) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 92,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Sum1",
    0, "", offsetof(B_Thrustallocation_test_T, Sum1_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 93,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Memory",
    0, "", offsetof(B_Thrustallocation_test_T, Memory_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 94,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Core controller/Kp",
    0, "", offsetof(B_Thrustallocation_test_T, Kp_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 95,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Core controller/reset",
    0, "", offsetof(B_Thrustallocation_test_T, reset_e3) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 96,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Sum", 0,
    "", offsetof(B_Thrustallocation_test_T, Sum_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 97,
    "thrustallocation_test/Thruster control /Thruster 3/Discrete Transfer Fcn",
    0, "", offsetof(B_Thrustallocation_test_T, DiscreteTransferFcn_o) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 98,
    "thrustallocation_test/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_Thrustallocation_test_T, Findingrotationspeed_j) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 99,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Core controller/Ki",
    0, "", offsetof(B_Thrustallocation_test_T, Ki_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 100, "thrustallocation_test/Thruster control /Thruster 4/Delay", 0, "",
    offsetof(B_Thrustallocation_test_T, Delay_g) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 101,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Delay",
    0, "", offsetof(B_Thrustallocation_test_T, Delay_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 102,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_Thrustallocation_test_T, DiscreteTransferFcn_ox) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 103,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_Thrustallocation_test_T, TSamp_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 104,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Inertia compensation",
    0, "", offsetof(B_Thrustallocation_test_T, Inertiacompensation_jx) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 105,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Sum1",
    0, "", offsetof(B_Thrustallocation_test_T, Sum1_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 106,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Memory",
    0, "", offsetof(B_Thrustallocation_test_T, Memory_aw) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 107,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Core controller/Kp",
    0, "", offsetof(B_Thrustallocation_test_T, Kp_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 108,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Core controller/reset",
    0, "", offsetof(B_Thrustallocation_test_T, reset_j4) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 109,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Sum", 0,
    "", offsetof(B_Thrustallocation_test_T, Sum_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 110,
    "thrustallocation_test/Thruster control /Thruster 4/Discrete Transfer Fcn",
    0, "", offsetof(B_Thrustallocation_test_T, DiscreteTransferFcn_c) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 111,
    "thrustallocation_test/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_Thrustallocation_test_T, Findingrotationspeed_n) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 112,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Core controller/Ki",
    0, "", offsetof(B_Thrustallocation_test_T, Ki_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 113, "thrustallocation_test/Thruster control /Thruster 5/Delay", 0, "",
    offsetof(B_Thrustallocation_test_T, Delay_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 114,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Delay",
    0, "", offsetof(B_Thrustallocation_test_T, Delay_fl) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 115,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_Thrustallocation_test_T, DiscreteTransferFcn_f) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 116,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_Thrustallocation_test_T, TSamp_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 117,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Inertia compensation",
    0, "", offsetof(B_Thrustallocation_test_T, Inertiacompensation_o) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 118,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Sum1",
    0, "", offsetof(B_Thrustallocation_test_T, Sum1_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 119,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Memory",
    0, "", offsetof(B_Thrustallocation_test_T, Memory_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 120,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Core controller/Kp",
    0, "", offsetof(B_Thrustallocation_test_T, Kp_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 121,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Core controller/reset",
    0, "", offsetof(B_Thrustallocation_test_T, reset_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 122,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Sum", 0,
    "", offsetof(B_Thrustallocation_test_T, Sum_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 123,
    "thrustallocation_test/Thruster control /Thruster 5/Discrete Transfer Fcn",
    0, "", offsetof(B_Thrustallocation_test_T, DiscreteTransferFcn_e) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 124,
    "thrustallocation_test/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_Thrustallocation_test_T, Findingrotationspeed_j0) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 125,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Core controller/Ki",
    0, "", offsetof(B_Thrustallocation_test_T, Ki_jy) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 126, "thrustallocation_test/Thruster control /Thruster 6/Delay", 0, "",
    offsetof(B_Thrustallocation_test_T, Delay_cn) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 127,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Delay",
    0, "", offsetof(B_Thrustallocation_test_T, Delay_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 128,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_Thrustallocation_test_T, DiscreteTransferFcn_h) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 129,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_Thrustallocation_test_T, TSamp_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 130,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Inertia compensation",
    0, "", offsetof(B_Thrustallocation_test_T, Inertiacompensation_g) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 131,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Sum1",
    0, "", offsetof(B_Thrustallocation_test_T, Sum1_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 132,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Memory",
    0, "", offsetof(B_Thrustallocation_test_T, Memory_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 133,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Core controller/Kp",
    0, "", offsetof(B_Thrustallocation_test_T, Kp_me) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 134,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Core controller/reset",
    0, "", offsetof(B_Thrustallocation_test_T, reset_en) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 135,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Sum", 0,
    "", offsetof(B_Thrustallocation_test_T, Sum_id) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 136,
    "thrustallocation_test/Thruster control /Thruster 6/Discrete Transfer Fcn",
    0, "", offsetof(B_Thrustallocation_test_T, DiscreteTransferFcn_p) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 137,
    "thrustallocation_test/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_Thrustallocation_test_T, Findingrotationspeed_h) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 138,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Core controller/Ki",
    0, "", offsetof(B_Thrustallocation_test_T, Ki_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 139, "thrustallocation_test/u_limiter/MATLAB Function", 0, "", offsetof
    (B_Thrustallocation_test_T, y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 140, "thrustallocation_test/kinetics", 0, "(1, 1)", offsetof
    (B_Thrustallocation_test_T, nu_dot) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1,
    2, 0, 0 },

  { 141, "thrustallocation_test/kinetics", 0, "(1, 2)", offsetof
    (B_Thrustallocation_test_T, nu_dot) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1,
    2, 0, 0 },

  { 142, "thrustallocation_test/kinetics", 0, "(1, 3)", offsetof
    (B_Thrustallocation_test_T, nu_dot) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1,
    2, 0, 0 },

  { 143, "thrustallocation_test/kinematics", 0, "(1, 1)", offsetof
    (B_Thrustallocation_test_T, eta_dot) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 144, "thrustallocation_test/kinematics", 0, "(1, 2)", offsetof
    (B_Thrustallocation_test_T, eta_dot) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 145, "thrustallocation_test/kinematics", 0, "(1, 3)", offsetof
    (B_Thrustallocation_test_T, eta_dot) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 146,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/MATLAB Function",
    0, "", offsetof(B_Thrustallocation_test_T, n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 147,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/MATLAB Function",
    0, "", offsetof(B_Thrustallocation_test_T, n_d_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 148,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 1)", offsetof(B_Thrustallocation_test_T, output) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 149,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 2)", offsetof(B_Thrustallocation_test_T, output) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 150,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 3)", offsetof(B_Thrustallocation_test_T, output) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 151,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 4)", offsetof(B_Thrustallocation_test_T, output) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 152,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 5)", offsetof(B_Thrustallocation_test_T, output) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 153,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 6)", offsetof(B_Thrustallocation_test_T, output) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 154,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 7)", offsetof(B_Thrustallocation_test_T, output) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 155,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 8)", offsetof(B_Thrustallocation_test_T, output) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 156,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 9)", offsetof(B_Thrustallocation_test_T, output) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 157,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 10)", offsetof(B_Thrustallocation_test_T, output) + (9*sizeof(real_T)),
    BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 158,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 11)", offsetof(B_Thrustallocation_test_T, output) + (10*sizeof
    (real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 159,
    "thrustallocation_test/Thruster control /Thrust and Shaft speed mapped to PWM/MATLAB Function",
    0, "(1, 12)", offsetof(B_Thrustallocation_test_T, output) + (11*sizeof
    (real_T)), BLOCKIO_SIG, 24, 1, 2, 0, 0 },

  { 160, "thrustallocation_test/Thrust allocation/MATLAB Function1", 1, "(1, 1)",
    offsetof(B_Thrustallocation_test_T, A1Matrix) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 161, "thrustallocation_test/Thrust allocation/MATLAB Function1", 1, "(1, 2)",
    offsetof(B_Thrustallocation_test_T, A1Matrix) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 162, "thrustallocation_test/Thrust allocation/MATLAB Function1", 1, "(1, 3)",
    offsetof(B_Thrustallocation_test_T, A1Matrix) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 163, "thrustallocation_test/Thrust allocation/MATLAB Function1", 1, "(1, 4)",
    offsetof(B_Thrustallocation_test_T, A1Matrix) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 164, "thrustallocation_test/Thrust allocation/MATLAB Function1", 1, "(1, 5)",
    offsetof(B_Thrustallocation_test_T, A1Matrix) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 165, "thrustallocation_test/Thrust allocation/MATLAB Function1", 1, "(1, 6)",
    offsetof(B_Thrustallocation_test_T, A1Matrix) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 166, "thrustallocation_test/Thrust allocation/MATLAB Function1", 1, "(1, 7)",
    offsetof(B_Thrustallocation_test_T, A1Matrix) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 167, "thrustallocation_test/Thrust allocation/MATLAB Function1", 1, "(1, 8)",
    offsetof(B_Thrustallocation_test_T, A1Matrix) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 168, "thrustallocation_test/Thrust allocation/MATLAB Function1", 1, "(1, 9)",
    offsetof(B_Thrustallocation_test_T, A1Matrix) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 169, "thrustallocation_test/Thrust allocation/MATLAB Function1", 2, "(1, 1)",
    offsetof(B_Thrustallocation_test_T, A2Matrix) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 170, "thrustallocation_test/Thrust allocation/MATLAB Function1", 2, "(1, 2)",
    offsetof(B_Thrustallocation_test_T, A2Matrix) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 171, "thrustallocation_test/Thrust allocation/MATLAB Function1", 2, "(1, 3)",
    offsetof(B_Thrustallocation_test_T, A2Matrix) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 172, "thrustallocation_test/Thrust allocation/MATLAB Function1", 2, "(1, 4)",
    offsetof(B_Thrustallocation_test_T, A2Matrix) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 173, "thrustallocation_test/Thrust allocation/MATLAB Function1", 2, "(1, 5)",
    offsetof(B_Thrustallocation_test_T, A2Matrix) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 174, "thrustallocation_test/Thrust allocation/MATLAB Function1", 2, "(1, 6)",
    offsetof(B_Thrustallocation_test_T, A2Matrix) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 175, "thrustallocation_test/Thrust allocation/MATLAB Function1", 2, "(1, 7)",
    offsetof(B_Thrustallocation_test_T, A2Matrix) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 176, "thrustallocation_test/Thrust allocation/MATLAB Function1", 2, "(1, 8)",
    offsetof(B_Thrustallocation_test_T, A2Matrix) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 177, "thrustallocation_test/Thrust allocation/MATLAB Function1", 2, "(1, 9)",
    offsetof(B_Thrustallocation_test_T, A2Matrix) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 178, "thrustallocation_test/Thrust allocation/MATLAB Function1", 3, "(1, 1)",
    offsetof(B_Thrustallocation_test_T, A3Matrix) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 179, "thrustallocation_test/Thrust allocation/MATLAB Function1", 3, "(1, 2)",
    offsetof(B_Thrustallocation_test_T, A3Matrix) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 180, "thrustallocation_test/Thrust allocation/MATLAB Function1", 3, "(1, 3)",
    offsetof(B_Thrustallocation_test_T, A3Matrix) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 181, "thrustallocation_test/Thrust allocation/MATLAB Function1", 3, "(1, 4)",
    offsetof(B_Thrustallocation_test_T, A3Matrix) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 182, "thrustallocation_test/Thrust allocation/MATLAB Function1", 3, "(1, 5)",
    offsetof(B_Thrustallocation_test_T, A3Matrix) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 183, "thrustallocation_test/Thrust allocation/MATLAB Function1", 3, "(1, 6)",
    offsetof(B_Thrustallocation_test_T, A3Matrix) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 184, "thrustallocation_test/Thrust allocation/MATLAB Function1", 3, "(1, 7)",
    offsetof(B_Thrustallocation_test_T, A3Matrix) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 185, "thrustallocation_test/Thrust allocation/MATLAB Function1", 3, "(1, 8)",
    offsetof(B_Thrustallocation_test_T, A3Matrix) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 186, "thrustallocation_test/Thrust allocation/MATLAB Function1", 3, "(1, 9)",
    offsetof(B_Thrustallocation_test_T, A3Matrix) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 187, "thrustallocation_test/Thrust allocation/MATLAB Function1", 4, "(1, 1)",
    offsetof(B_Thrustallocation_test_T, BMatrix) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 188, "thrustallocation_test/Thrust allocation/MATLAB Function1", 4, "(1, 2)",
    offsetof(B_Thrustallocation_test_T, BMatrix) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 189, "thrustallocation_test/Thrust allocation/MATLAB Function1", 4, "(1, 3)",
    offsetof(B_Thrustallocation_test_T, BMatrix) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 190, "thrustallocation_test/Finding commanded forces in: [Surge,Sway,Yaw]",
    0, "(1, 1)", offsetof(B_Thrustallocation_test_T, commanded_tau) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 191, "thrustallocation_test/Finding commanded forces in: [Surge,Sway,Yaw]",
    0, "(1, 2)", offsetof(B_Thrustallocation_test_T, commanded_tau) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 192, "thrustallocation_test/Finding commanded forces in: [Surge,Sway,Yaw]",
    0, "(1, 3)", offsetof(B_Thrustallocation_test_T, commanded_tau) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 193,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Supervisor",
    0, "", offsetof(B_Thrustallocation_test_T, sf_Supervisor_g.u) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 194,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_f.Qcq) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 195,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_f.Qcp) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 196,
    "thrustallocation_test/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_f.Qcc) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 197,
    "thrustallocation_test/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_Thrustallocation_test_T, sf_ActualForceandTorque_n.Ta) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 198,
    "thrustallocation_test/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_Thrustallocation_test_T, sf_ActualForceandTorque_n.Qa) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 199,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Supervisor",
    0, "", offsetof(B_Thrustallocation_test_T, sf_Supervisor_mw.u) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 200,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/MATLAB Function",
    0, "", offsetof(B_Thrustallocation_test_T, sf_MATLABFunction_h.n_d) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 201,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/MATLAB Function",
    1, "", offsetof(B_Thrustallocation_test_T, sf_MATLABFunction_h.T_r) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 202,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_i.Qcq) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 203,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_i.Qcp) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 204,
    "thrustallocation_test/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_i.Qcc) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 205,
    "thrustallocation_test/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_Thrustallocation_test_T, sf_ActualForceandTorque_m.Ta) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 206,
    "thrustallocation_test/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_Thrustallocation_test_T, sf_ActualForceandTorque_m.Qa) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 207,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Supervisor",
    0, "", offsetof(B_Thrustallocation_test_T, sf_Supervisor_m.u) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 208,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/MATLAB Function",
    0, "", offsetof(B_Thrustallocation_test_T, sf_MATLABFunction_f.n_d) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 209,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/MATLAB Function",
    1, "", offsetof(B_Thrustallocation_test_T, sf_MATLABFunction_f.T_r) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 210,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_e.Qcq) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 211,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_e.Qcp) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 212,
    "thrustallocation_test/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_e.Qcc) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 213,
    "thrustallocation_test/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_Thrustallocation_test_T, sf_ActualForceandTorque_b.Ta) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 214,
    "thrustallocation_test/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_Thrustallocation_test_T, sf_ActualForceandTorque_b.Qa) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 215,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Supervisor",
    0, "", offsetof(B_Thrustallocation_test_T, sf_Supervisor_b.u) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 216,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/MATLAB Function",
    0, "", offsetof(B_Thrustallocation_test_T, sf_MATLABFunction_da.n_d) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 217,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/MATLAB Function",
    1, "", offsetof(B_Thrustallocation_test_T, sf_MATLABFunction_da.T_r) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 218,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_j.Qcq) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 219,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_j.Qcp) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 220,
    "thrustallocation_test/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_j.Qcc) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 221,
    "thrustallocation_test/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_Thrustallocation_test_T, sf_ActualForceandTorque_g.Ta) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 222,
    "thrustallocation_test/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_Thrustallocation_test_T, sf_ActualForceandTorque_g.Qa) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 223,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Supervisor",
    0, "", offsetof(B_Thrustallocation_test_T, sf_Supervisor_p.u) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 224,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/MATLAB Function",
    0, "", offsetof(B_Thrustallocation_test_T, sf_MATLABFunction_a.n_d) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 225,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/MATLAB Function",
    1, "", offsetof(B_Thrustallocation_test_T, sf_MATLABFunction_a.T_r) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 226,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_g.Qcq) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 227,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_g.Qcp) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 228,
    "thrustallocation_test/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowera_g.Qcc) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 229,
    "thrustallocation_test/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_Thrustallocation_test_T, sf_ActualForceandTorque_k.Ta) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 230,
    "thrustallocation_test/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_Thrustallocation_test_T, sf_ActualForceandTorque_k.Qa) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 231,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Supervisor",
    0, "", offsetof(B_Thrustallocation_test_T, sf_Supervisor.u) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 232,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowerand.Qcq) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 233,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowerand.Qcp) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 234,
    "thrustallocation_test/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_Thrustallocation_test_T,
                    sf_CorecontrollerTorquePowerand.Qcc) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 235,
    "thrustallocation_test/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_Thrustallocation_test_T, sf_ActualForceandTorque.Ta) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 236,
    "thrustallocation_test/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_Thrustallocation_test_T, sf_ActualForceandTorque.Qa) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 237,
    "thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed/Discrete-Time Integrator",
    0, "angle", offsetof(B_Thrustallocation_test_T, CoreSubsys[5].angle) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 238,
    "thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed/Delay",
    0, "", offsetof(B_Thrustallocation_test_T, CoreSubsys[5].Delay) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 239,
    "thrustallocation_test/Thrust allocation/Optimal angle path and  constraints on rotation speed/Max Rotation Rate",
    0, "", offsetof(B_Thrustallocation_test_T, CoreSubsys[5].MaxRotationRate) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 240;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 38;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Thruster control /Thruster 1/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1 },

  { 2, "Thruster control /Thruster 2/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1 },

  { 3, "Thruster control /Thruster 3/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1 },

  { 4, "Thruster control /Thruster 4/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1 },

  { 5, "Thruster control /Thruster 5/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1 },

  { 6, "Thruster control /Thruster 6/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1 },

  { 7, "core_controller", 0, EXT_IN, 1, 1, 1 },

  { 8, "ArrowUp", 0, EXT_IN, 1, 1, 1 },

  { 9, "ArrowDown", 0, EXT_IN, 1, 1, 1 },

  { 10, "Start", 0, EXT_IN, 1, 1, 1 },

  { 11, "L2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 12, "Thruster measurment/thr_angle_1", 0, EXT_IN, 1, 1, 1 },

  { 13, "Thruster measurment/thr_angle_2", 0, EXT_IN, 1, 1, 1 },

  { 14, "Thruster measurment/thr_angle_3", 0, EXT_IN, 1, 1, 1 },

  { 15, "Thruster measurment/thr_angle_4", 0, EXT_IN, 1, 1, 1 },

  { 16, "Thruster measurment/thr_angle_5", 0, EXT_IN, 1, 1, 1 },

  { 17, "Thruster measurment/thr_angle_6", 0, EXT_IN, 1, 1, 1 },

  { 18, "PosYLeft", 0, EXT_IN, 1, 1, 1 },

  { 19, "PosXLeft", 0, EXT_IN, 1, 1, 1 },

  { 20, "R2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 21, "Thrust allocation/Angle_controller", 0, EXT_IN, 1, 1, 1 },

  { 22, "Thrust allocation/fmin", 0, EXT_IN, 6, 6, 1 },

  { 23, "reset", 1, EXT_IN, 6, 6, 1 },

  { 24, "Thruster control /Thruster 1/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 25, "Thruster control /Thruster 2/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 26, "Thruster control /Thruster 3/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 27, "Thruster control /Thruster 4/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 28, "Thruster control /Thruster 5/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 29, "Thruster control /Thruster 6/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 1, "Thrust allocation/A1Matrix ", 0, EXT_OUT, 9, 1, 9 },

  { 2, "Thrust allocation/A2Matrix", 0, EXT_OUT, 9, 1, 9 },

  { 3, "Thrust allocation/A3Matrix", 0, EXT_OUT, 9, 1, 9 },

  { 4, "Thrust allocation/BMatrix", 0, EXT_OUT, 3, 3, 1 },

  { 5, "tau_actual", 0, EXT_OUT, 3, 3, 1 },

  { 6, "N", 0, EXT_OUT, 1, 1, 1 },

  { 7, "X", 0, EXT_OUT, 1, 1, 1 },

  { 8, "Y", 0, EXT_OUT, 1, 1, 1 },

  { 9, "u_limit", 0, EXT_OUT, 1, 1, 1 },

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
  "Thrustallocation_test";
static const char* NI_CompiledModelVersion = "1.10";
static const char* NI_CompiledModelDateTime = "Fri Jun 17 16:52:41 2016";
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
  memcpy(&rtParameter[0], &Thrustallocation_test_P, sizeof
         (P_Thrustallocation_test_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka Thrustallocation_test_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_Thrustallocation_test_T));
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
             (P_Thrustallocation_test_T));
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
               (P_Thrustallocation_test_T));
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
             (P_Thrustallocation_test_T));
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
           (P_Thrustallocation_test_T));
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
           (P_Thrustallocation_test_T));
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
      *numContStates = 18;
      *numDiscStates = 1007.0;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Integrator_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Integrator_CSTATE_o), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_o");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Integrator_CSTATE_p), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_p");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Integrator_CSTATE_a), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_a");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Integrator_CSTATE_a0), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_a0");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Integrator_CSTATE_d), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_d");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Position_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Position_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Position_CSTATE), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Position_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Position_CSTATE), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Position_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Integrator_CSTATE_j), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_j");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Integrator_CSTATE_jg), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_jg");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Integrator_CSTATE_e), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Integrator_CSTATE_jz), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_jz");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Integrator_CSTATE_ai), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_ai");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Integrator_CSTATE_g), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Velocity_CSTATE), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Velocity_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Velocity_CSTATE), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Velocity_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(Thrustallocation_test_X.Velocity_CSTATE), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Velocity_CSTATE");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DelayInput1_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DelayInput1_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DelayInput1_DSTATE_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DelayInput1_DSTATE_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DelayInput1_DSTATE_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DelayInput1_DSTATE_c");
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.Delay_DSTATE, count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.Delay_DSTATE");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Delay_DSTATE_l, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Delay_DSTATE_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Delay_DSTATE_g, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Delay_DSTATE_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states, 0, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states, 1, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.UD_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.UD_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Delay_DSTATE_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Delay_DSTATE_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Delay_DSTATE_i, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Delay_DSTATE_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_f, 0, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_f, 1, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.UD_DSTATE_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.UD_DSTATE_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Delay_DSTATE_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Delay_DSTATE_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Delay_DSTATE_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Delay_DSTATE_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_m, 0, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_m, 1, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.UD_DSTATE_j, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.UD_DSTATE_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Delay_DSTATE_ce, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Delay_DSTATE_ce");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Delay_DSTATE_h, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Delay_DSTATE_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_j, 0, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_j, 1, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.UD_DSTATE_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.UD_DSTATE_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_e, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Delay_DSTATE_m, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Delay_DSTATE_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Delay_DSTATE_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Delay_DSTATE_k");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_du, 0, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_du");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_du, 1, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_du");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.UD_DSTATE_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.UD_DSTATE_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_fv, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_fv");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Delay_DSTATE_cy, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Delay_DSTATE_cy");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Delay_DSTATE_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Delay_DSTATE_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_jo, 0, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_jo");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_jo, 1, 29, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_jo");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.UD_DSTATE_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.UD_DSTATE_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_df, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_states_df");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.reset_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.reset_DWORK1_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.reset_DWORK1_k");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.reset_DWORK1_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.reset_DWORK1_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.reset_DWORK1_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.reset_DWORK1_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.reset_DWORK1_i, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.reset_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.reset_DWORK1_j, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.reset_DWORK1_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.core_controller_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.core_controller_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.ArrowUp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.ArrowDown_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.ArrowDown_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Start_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Start_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Memory_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.thr_angle_1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.thr_angle_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.thr_angle_2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.thr_angle_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.thr_angle_3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.thr_angle_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.thr_angle_4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.thr_angle_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.thr_angle_5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.thr_angle_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.thr_angle_6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.thr_angle_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.PosYLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.PosXLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Angle_controller_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Angle_controller_DWORK1");
    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.A1Matrix_DWORK1, count, 26, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.A1Matrix_DWORK1");
    }

    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.fmin_DWORK1, count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.fmin_DWORK1");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.A2Matrix_DWORK1, count, 26, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.A2Matrix_DWORK1");
    }

    for (count = 0; count < 9; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.A3Matrix_DWORK1, count, 26, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.A3Matrix_DWORK1");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.BMatrix_DWORK1, 0, 22, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.BMatrix_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.BMatrix_DWORK1, 1, 22, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.BMatrix_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.BMatrix_DWORK1, 2, 22, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.BMatrix_DWORK1");
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK1_iq, count, 23, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK1_iq");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.tau_actual_DWORK1, 0, 22, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.tau_actual_DWORK1, 1, 22, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.tau_actual_DWORK1, 2, 22, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&Thrustallocation_test_DW.N_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&Thrustallocation_test_DW.N_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&Thrustallocation_test_DW.X_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&Thrustallocation_test_DW.X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&Thrustallocation_test_DW.Y_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&Thrustallocation_test_DW.Y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.u_limit_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.u_limit_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_tmp, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_tmp");
    discStates[idx] = NIRT_GetValueByDataType(&Thrustallocation_test_DW.PrevY, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&Thrustallocation_test_DW.PrevY");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Memory_PreviousInput_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Memory_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.reset_DWORK1_b, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.reset_DWORK1_b");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_l, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_l");
    discStates[idx] = NIRT_GetValueByDataType(&Thrustallocation_test_DW.PrevY_i,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&Thrustallocation_test_DW.PrevY_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Memory_PreviousInput_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Memory_PreviousInput_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.reset_DWORK1_m, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.reset_DWORK1_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_i, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_i");
    discStates[idx] = NIRT_GetValueByDataType(&Thrustallocation_test_DW.PrevY_o,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&Thrustallocation_test_DW.PrevY_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Memory_PreviousInput_l, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Memory_PreviousInput_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.reset_DWORK1_oc, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.reset_DWORK1_oc");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_ll, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_ll");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_p");
    discStates[idx] = NIRT_GetValueByDataType(&Thrustallocation_test_DW.PrevY_a,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&Thrustallocation_test_DW.PrevY_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Memory_PreviousInput_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Memory_PreviousInput_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.reset_DWORK1_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.reset_DWORK1_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_c3, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_c3");
    discStates[idx] = NIRT_GetValueByDataType(&Thrustallocation_test_DW.PrevY_m,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&Thrustallocation_test_DW.PrevY_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Memory_PreviousInput_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Memory_PreviousInput_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.reset_DWORK1_f4, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.reset_DWORK1_f4");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_k");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_a");
    discStates[idx] = NIRT_GetValueByDataType(&Thrustallocation_test_DW.PrevY_f,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&Thrustallocation_test_DW.PrevY_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Memory_PreviousInput_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Memory_PreviousInput_k");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.reset_DWORK1_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.reset_DWORK1_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_ov, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_ov");
    discStates[idx] = NIRT_GetValueByDataType
      (&Thrustallocation_test_DW.Position_IWORK.IcNeedsLoading, 0, 10, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&Thrustallocation_test_DW.Position_IWORK.IcNeedsLoading");
    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2_g, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2_g");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2_k, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2_k");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2_ga, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2_ga");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2_b, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2_b");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2_f, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2_f");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.core_controller_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.core_controller_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.ArrowUp_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.ArrowDown_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.Start_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.Start_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.L2_continuous_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.thr_angle_1_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.thr_angle_1_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.thr_angle_2_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.thr_angle_2_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.thr_angle_3_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.thr_angle_3_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.thr_angle_4_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.thr_angle_4_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.thr_angle_5_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.thr_angle_5_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.thr_angle_6_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.thr_angle_6_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.PosYLeft_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.PosXLeft_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.R2_continuous_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.Angle_controller_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.Angle_controller_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.A1Matrix_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.A1Matrix_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.fmin_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.fmin_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.A2Matrix_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.A2Matrix_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.A3Matrix_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.A3Matrix_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.BMatrix_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.BMatrix_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2_i, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2_i");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.tau_actual_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.tau_actual_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.N_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.N_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.X_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.X_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.Y_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.Y_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.u_limit_DWORK2, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.u_limit_DWORK2");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2_fa, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2_fa");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2_n, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2_n");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2_c, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2_c");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2_p, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2_p");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2_iu, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2_iu");
    }

    for (count = 0; count < 22; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.reset_DWORK2_o, count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.reset_DWORK2_o");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.CoreSubsys[ForEach_itr1].
         DiscreteTimeIntegrator_DSTATE, 0, 0, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_DSTATE");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.CoreSubsys[ForEach_itr1].Delay_DSTATE, 0, 0,
         0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.CoreSubsys[ForEach_itr1].Delay_DSTATE");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.CoreSubsys[ForEach_itr1].
         DiscreteTimeIntegrator_PrevRese, 0, 2, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_PrevRese");
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&Thrustallocation_test_DW.CoreSubsys[ForEach_itr1].
         DiscreteTimeIntegrator_IC_LOADI, 0, 3, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&Thrustallocation_test_DW.CoreSubsys[ForEach_itr1].DiscreteTimeIntegrator_IC_LOADI");
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
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Integrator_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Integrator_CSTATE_o), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Integrator_CSTATE_p), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Integrator_CSTATE_a), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Integrator_CSTATE_a0), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Integrator_CSTATE_d), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Position_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Position_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Position_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Integrator_CSTATE_j), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Integrator_CSTATE_jg), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Integrator_CSTATE_e), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Integrator_CSTATE_jz), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Integrator_CSTATE_ai), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Integrator_CSTATE_g), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Velocity_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Velocity_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(Thrustallocation_test_X.Velocity_CSTATE), 2,
      contStates[idx++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DelayInput1_DSTATE, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DelayInput1_DSTATE_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DelayInput1_DSTATE_c, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE, count,
        discStates[idx++], 23, 0);
    }

    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE_l, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE_g, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_states,
      0, discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_states,
      1, discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.UD_DSTATE, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_o, 0, discStates[idx
       ++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE_c, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE_i, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_f, 0, discStates[idx
       ++], 29, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_f, 1, discStates[idx
       ++], 29, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.UD_DSTATE_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_a, 0, discStates[idx
       ++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE_f, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_m, 0, discStates[idx
       ++], 29, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_m, 1, discStates[idx
       ++], 29, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.UD_DSTATE_j, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_d, 0, discStates[idx
       ++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE_ce, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE_h, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_j, 0, discStates[idx
       ++], 29, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_j, 1, discStates[idx
       ++], 29, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.UD_DSTATE_c, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_e, 0, discStates[idx
       ++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_du, 0,
       discStates[idx++], 29, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_du, 1,
       discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.UD_DSTATE_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_fv, 0,
       discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE_cy, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Delay_DSTATE_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_jo, 0,
       discStates[idx++], 29, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_jo, 1,
       discStates[idx++], 29, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.UD_DSTATE_f, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.DiscreteTransferFcn_states_df, 0,
       discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1_o, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1_f, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1_i, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1_j, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.core_controller_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.ArrowUp_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.ArrowDown_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Start_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.thr_angle_1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.thr_angle_2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.thr_angle_3_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.thr_angle_4_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.thr_angle_5_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.thr_angle_6_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.PosYLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.PosXLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Angle_controller_DWORK1, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.A1Matrix_DWORK1, count,
        discStates[idx++], 26, 0);
    }

    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.fmin_DWORK1, count,
        discStates[idx++], 23, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.A2Matrix_DWORK1, count,
        discStates[idx++], 26, 0);
    }

    for (count = 0; count < 9; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.A3Matrix_DWORK1, count,
        discStates[idx++], 26, 0);
    }

    NIRT_SetValueByDataType(&Thrustallocation_test_DW.BMatrix_DWORK1, 0,
      discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.BMatrix_DWORK1, 1,
      discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.BMatrix_DWORK1, 2,
      discStates[idx++], 22, 0);
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1_iq, count,
        discStates[idx++], 23, 0);
    }

    NIRT_SetValueByDataType(&Thrustallocation_test_DW.tau_actual_DWORK1, 0,
      discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.tau_actual_DWORK1, 1,
      discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.tau_actual_DWORK1, 2,
      discStates[idx++], 22, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.N_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.X_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Y_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.u_limit_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_tmp, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.PrevY, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Memory_PreviousInput_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1_b, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_d,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_l,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.PrevY_i, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Memory_PreviousInput_c, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_c,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_i,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.PrevY_o, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Memory_PreviousInput_l, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1_oc, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_ll,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_p,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.PrevY_a, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Memory_PreviousInput_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_o,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_c3,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.PrevY_m, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Memory_PreviousInput_f, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1_f4, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_k,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_a,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.PrevY_f, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.Memory_PreviousInput_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK1_c, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&Thrustallocation_test_DW.DiscreteTransferFcn_tmp_ov,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType
      (&Thrustallocation_test_DW.Position_IWORK.IcNeedsLoading, 0,
       discStates[idx++], 10, 0);
    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2_g, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2_k, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2_ga, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2_b, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2_f, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.core_controller_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.Start_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.L2_continuous_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.thr_angle_1_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.thr_angle_2_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.thr_angle_3_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.thr_angle_4_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.thr_angle_5_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.thr_angle_6_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.R2_continuous_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.Angle_controller_DWORK2,
        count, discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.A1Matrix_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.fmin_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.A2Matrix_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.A3Matrix_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.BMatrix_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2_i, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.tau_actual_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.N_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.X_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.Y_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.u_limit_DWORK2, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2_fa, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2_n, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2_c, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2_p, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2_iu, count,
        discStates[idx++], 21, 0);
    }

    for (count = 0; count < 22; count++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.reset_DWORK2_o, count,
        discStates[idx++], 21, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.CoreSubsys[ForEach_itr1]
        .DiscreteTimeIntegrator_DSTATE, 0, discStates[idx++], 0, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.CoreSubsys[ForEach_itr1]
        .Delay_DSTATE, 0, discStates[idx++], 0, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.CoreSubsys[ForEach_itr1]
        .DiscreteTimeIntegrator_PrevRese, 0, discStates[idx++], 2, 0);
    }

    for (ForEach_itr1 = 0; ForEach_itr1 < 6; ForEach_itr1++) {
      NIRT_SetValueByDataType(&Thrustallocation_test_DW.CoreSubsys[ForEach_itr1]
        .DiscreteTimeIntegrator_IC_LOADI, 0, discStates[idx++], 3, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_Thrustallocation_test
