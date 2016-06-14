/*
 * ctrl_TAPM2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_TAPM2".
 *
 * Model version              : 1.39
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sun May 15 13:28:12 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_TAPM2.h"
#include "ctrl_TAPM2_private.h"

/* Block signals (auto storage) */
B_ctrl_TAPM2_T ctrl_TAPM2_B;

/* Continuous states */
X_ctrl_TAPM2_T ctrl_TAPM2_X;

/* Block states (auto storage) */
DW_ctrl_TAPM2_T ctrl_TAPM2_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ctrl_TAPM2_T ctrl_TAPM2_PrevZCX;

/* Real-time model */
RT_MODEL_ctrl_TAPM2_T ctrl_TAPM2_M_;
RT_MODEL_ctrl_TAPM2_T *const ctrl_TAPM2_M = &ctrl_TAPM2_M_;

/* Forward declaration for local functions */
static void ctrl_TAPM2_cosd(real_T *x);
static void ctrl_TAPM2_sind(real_T *x);

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
  int_T nXc = 30;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ctrl_TAPM2_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ctrl_TAPM2_output();
  ctrl_TAPM2_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ctrl_TAPM2_output();
  ctrl_TAPM2_derivatives();

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
 *    '<S42>/Actual Force and Torque'
 *    '<S52>/Actual Force and Torque'
 *    '<S62>/Actual Force and Torque'
 *    '<S72>/Actual Force and Torque'
 *    '<S82>/Actual Force and Torque'
 *    '<S92>/Actual Force and Torque'
 */
void ctrl_TAPM2_ActualForceandTorque(real_T rtu_n, real_T rtu_Kq, real_T rtu_Kt,
  real_T rtu_Ktr, real_T rtu_Kqr, real_T rtu_Rho, real_T rtu_D, real_T rtu_eps_c,
  real_T rtu_env, B_ActualForceandTorque_ctrl_T_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_0;

  /* MATLAB Function 'Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque': '<S45>:1' */
  /* '<S45>:1:3' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
  /* '<S45>:1:4' */
  /* '<S45>:1:5' */
  /* '<S45>:1:7' */
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

  /* '<S45>:1:8' */
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
 *    '<S46>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S56>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S66>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S76>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S86>/Core controller: Torque,Power and Combined Torque//Power'
 *    '<S96>/Core controller: Torque,Power and Combined Torque//Power'
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

  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power': '<S51>:1' */
  /* '<S51>:1:4' */
  lambda_c = tanh(rtu_eps_c * rtu_n / 5.0) * 0.5 + 0.5;

  /* '<S51>:1:5' */
  K_TC = (1.0 - lambda_c) * rtu_K_t0r + rtu_K_t0 * lambda_c;

  /* '<S51>:1:6' */
  lambda_c = (1.0 - lambda_c) * rtu_K_q0r + rtu_K_q0 * lambda_c;

  /* '<S51>:1:7' */
  Qcq = lambda_c / K_TC * rtu_D * rtu_Tr;

  /* '<S51>:1:8' */
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

  /* '<S51>:1:9' */
  K_TC = exp(rt_powd_snf(fabs(rtu_p_cc * rtu_n), rtu_r_cc) * -rtu_k_cc);

  /* '<S51>:1:11' */
  localB->Qcc = (1.0 - K_TC) * lambda_c + K_TC * Qcq;
  localB->Qcq = Qcq;
  localB->Qcp = lambda_c;
}

/*
 * Output and update for atomic system:
 *    '<S44>/Supervisor'
 *    '<S54>/Supervisor'
 *    '<S64>/Supervisor'
 *    '<S74>/Supervisor'
 *    '<S84>/Supervisor'
 *    '<S94>/Supervisor'
 */
void ctrl_TAPM2_Supervisor(real_T rtu_control, real_T rtu_input, real_T rtu_n,
  B_Supervisor_ctrl_TAPM2_T *localB)
{
  /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/Supervisor': '<S49>:1' */
  /* '<S49>:1:2' */
  localB->u = 1.0;
  if (rtu_control == 1.0) {
    /* '<S49>:1:3' */
    if (rtu_input == 1.0) {
      /* '<S49>:1:4' */
      /* '<S49>:1:5' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S49>:1:6' */
      /* '<S49>:1:7' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S49>:1:8' */
      /* '<S49>:1:9' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S49>:1:10' */
      /* '<S49>:1:11' */
      localB->u = 4.0;
    } else {
      /* '<S49>:1:13' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 2.0) {
    /* '<S49>:1:17' */
    if (rtu_input == 1.0) {
      /* '<S49>:1:18' */
      /* '<S49>:1:19' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S49>:1:20' */
      /* '<S49>:1:21' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S49>:1:22' */
      /* '<S49>:1:23' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S49>:1:24' */
      /* '<S49>:1:25' */
      localB->u = 4.0;
    } else {
      /* '<S49>:1:27' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 3.0) {
    /* '<S49>:1:31' */
    if (rtu_input == 1.0) {
      /* '<S49>:1:32' */
      /* '<S49>:1:33' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S49>:1:34' */
      /* '<S49>:1:35' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S49>:1:36' */
      /* '<S49>:1:37' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S49>:1:38' */
      /* '<S49>:1:39' */
      localB->u = 4.0;
    } else {
      /* '<S49>:1:41' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 4.0) {
    /* '<S49>:1:45' */
    if (rtu_input == 1.0) {
      /* '<S49>:1:46' */
      /* '<S49>:1:47' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S49>:1:48' */
      /* '<S49>:1:49' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S49>:1:50' */
      /* '<S49>:1:51' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S49>:1:52' */
      /* '<S49>:1:53' */
      localB->u = 4.0;
    } else {
      /* '<S49>:1:55' */
      localB->u = 5.0;
    }
  }

  if (rtu_control == 5.0) {
    /* '<S49>:1:59' */
    if (rtu_input == 1.0) {
      /* '<S49>:1:60' */
      /* '<S49>:1:61' */
      localB->u = 1.0;
    } else if (rtu_input == 2.0) {
      /* '<S49>:1:62' */
      /* '<S49>:1:63' */
      localB->u = 2.0;
    } else if (((rtu_input == 3.0) && (rtu_n > 0.0)) || ((rtu_input == 3.0) &&
                (rtu_n < 0.0))) {
      /* '<S49>:1:64' */
      /* '<S49>:1:65' */
      localB->u = 3.0;
    } else if ((rtu_input == 4.0) || ((rtu_input == 3.0) && (rtu_n == 0.0))) {
      /* '<S49>:1:66' */
      /* '<S49>:1:67' */
      localB->u = 4.0;
    } else {
      /* '<S49>:1:69' */
      localB->u = 5.0;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S54>/MATLAB Function'
 *    '<S64>/MATLAB Function'
 *    '<S74>/MATLAB Function'
 *    '<S84>/MATLAB Function'
 */
void ctrl_TAPM2_MATLABFunction(real_T rtu_Td, real_T rtu_K_t0, real_T rtu_K_t0r,
  real_T rtu_rho, real_T rtu_D, real_T rtu_eps_c, real_T rtu_n_r,
  B_MATLABFunction_ctrl_TAPM2_T *localB)
{
  real_T lambda_c;
  real_T rtu_n_r_0;
  real_T rtu_Td_0;

  /* MATLAB Function 'Thruster control /Thruster 2/Thruster control/MATLAB Function': '<S58>:1' */
  /* '<S58>:1:5' */
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

  /* '<S58>:1:7' */
  lambda_c = tanh(rtu_eps_c * rtu_Td_0 / 5.0) * 0.5 + 0.5;

  /*  Smooth switching between positive and negative thrust */
  /* '<S58>:1:8' */
  /* '<S58>:1:10' */
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

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void ctrl_TAPM2_cosd(real_T *x)
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
static void ctrl_TAPM2_sind(real_T *x)
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
void ctrl_TAPM2_output(void)
{
  /* local block i/o variables */
  real_T rtb_Integrator;
  real_T rtb_Integrator_f;
  real_T rtb_Integrator_h;
  real_T rtb_Integrator_a;
  real_T rtb_Integrator_i;
  real_T rtb_Integrator_l;
  real_T rtb_Delay[6];
  real_T rtb_Delay_b;
  real_T rtb_Delay_by;
  real_T rtb_Delay_l;
  real_T rtb_Delay_i;
  real_T rtb_T_r;
  real_T rtb_T_r_c;
  real_T l;
  real_T m;
  real_T n;
  real_T o;
  real_T p;
  real_T q;
  real_T r;
  real_T s;
  real_T t;
  real_T u;
  real_T v;
  real_T w;
  real_T x;
  real_T y;
  real_T offset;
  real_T absxk;
  real_T rtb_Saturation2;
  real_T rtb_Sum_b;
  real_T rtb_Row2;
  real_T rtb_bias[3];
  int32_T i;
  real_T rtb_Saturation2_0[18];
  int32_T i_0;
  real_T tmp[3];
  real_T tmp_0[3];
  real_T tmp_1[3];
  real_T rtb_output_idx_0;
  real_T rtb_output_idx_2;
  real_T rtb_output_idx_4;
  real_T rtb_output_idx_6;
  real_T rtb_output_idx_8;
  real_T rtb_output_idx_10;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* set solver stop time */
    if (!(ctrl_TAPM2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ctrl_TAPM2_M->solverInfo,
                            ((ctrl_TAPM2_M->Timing.clockTickH0 + 1) *
        ctrl_TAPM2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ctrl_TAPM2_M->solverInfo,
                            ((ctrl_TAPM2_M->Timing.clockTick0 + 1) *
        ctrl_TAPM2_M->Timing.stepSize0 + ctrl_TAPM2_M->Timing.clockTickH0 *
        ctrl_TAPM2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ctrl_TAPM2_M)) {
    ctrl_TAPM2_M->Timing.t[0] = rtsiGetT(&ctrl_TAPM2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Saturate: '<S34>/Saturation 1' incorporates:
     *  Constant: '<Root>/X-position Thruster1'
     */
    if (ctrl_TAPM2_P.XpositionThruster1_Value[1] >
        ctrl_TAPM2_P.Saturation1_UpperSat) {
      ctrl_TAPM2_B.Saturation1 = ctrl_TAPM2_P.Saturation1_UpperSat;
    } else if (ctrl_TAPM2_P.XpositionThruster1_Value[1] <
               ctrl_TAPM2_P.Saturation1_LowerSat) {
      ctrl_TAPM2_B.Saturation1 = ctrl_TAPM2_P.Saturation1_LowerSat;
    } else {
      ctrl_TAPM2_B.Saturation1 = ctrl_TAPM2_P.XpositionThruster1_Value[1];
    }

    /* End of Saturate: '<S34>/Saturation 1' */
  }

  /* Integrator: '<S43>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_TAPM2_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM2_X.Integrator_CSTATE = ctrl_TAPM2_P.Integrator_IC;
    }
  }

  ctrl_TAPM2_B.Integrator = ctrl_TAPM2_X.Integrator_CSTATE;

  /* MATLAB Function: '<S42>/Actual Force and Torque' incorporates:
   *  Constant: '<S35>/Losses (placeholder)'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM2_ActualForceandTorque(ctrl_TAPM2_B.Integrator, ctrl_TAPM2_P.Kq,
    ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Kqr, ctrl_TAPM2_P.Rho,
    ctrl_TAPM2_P.D, ctrl_TAPM2_P.eps_c, ctrl_TAPM2_P.Lossesplaceholder_Value,
    &ctrl_TAPM2_B.sf_ActualForceandTorque);

  /* Integrator: '<S53>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_n,
                       ctrl_TAPM2_B.reset_c);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM2_X.Integrator_CSTATE_p = ctrl_TAPM2_P.Integrator_IC_f;
    }
  }

  ctrl_TAPM2_B.Integrator_h = ctrl_TAPM2_X.Integrator_CSTATE_p;

  /* MATLAB Function: '<S52>/Actual Force and Torque' incorporates:
   *  Constant: '<S36>/Losses (placeholder)'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM2_ActualForceandTorque(ctrl_TAPM2_B.Integrator_h, ctrl_TAPM2_P.Kq,
    ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Kqr, ctrl_TAPM2_P.Rho,
    ctrl_TAPM2_P.D, ctrl_TAPM2_P.eps_c, ctrl_TAPM2_P.Lossesplaceholder_Value_k,
    &ctrl_TAPM2_B.sf_ActualForceandTorque_f);

  /* Integrator: '<S63>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_o,
                       ctrl_TAPM2_B.reset_j);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM2_X.Integrator_CSTATE_k = ctrl_TAPM2_P.Integrator_IC_p;
    }
  }

  ctrl_TAPM2_B.Integrator_a = ctrl_TAPM2_X.Integrator_CSTATE_k;

  /* MATLAB Function: '<S62>/Actual Force and Torque' incorporates:
   *  Constant: '<S37>/Losses (placeholder)'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM2_ActualForceandTorque(ctrl_TAPM2_B.Integrator_a, ctrl_TAPM2_P.Kq,
    ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Kqr, ctrl_TAPM2_P.Rho,
    ctrl_TAPM2_P.D, ctrl_TAPM2_P.eps_c, ctrl_TAPM2_P.Lossesplaceholder_Value_n,
    &ctrl_TAPM2_B.sf_ActualForceandTorque_h);

  /* Integrator: '<S73>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_i,
                       ctrl_TAPM2_B.reset_p);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM2_X.Integrator_CSTATE_n = ctrl_TAPM2_P.Integrator_IC_fv;
    }
  }

  ctrl_TAPM2_B.Integrator_k = ctrl_TAPM2_X.Integrator_CSTATE_n;

  /* MATLAB Function: '<S72>/Actual Force and Torque' incorporates:
   *  Constant: '<S38>/Losses (placeholder)'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM2_ActualForceandTorque(ctrl_TAPM2_B.Integrator_k, ctrl_TAPM2_P.Kq,
    ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Kqr, ctrl_TAPM2_P.Rho,
    ctrl_TAPM2_P.D, ctrl_TAPM2_P.eps_c, ctrl_TAPM2_P.Lossesplaceholder_Value_d,
    &ctrl_TAPM2_B.sf_ActualForceandTorque_m);

  /* Integrator: '<S83>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_a,
                       ctrl_TAPM2_B.reset_k);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM2_X.Integrator_CSTATE_c = ctrl_TAPM2_P.Integrator_IC_l;
    }
  }

  ctrl_TAPM2_B.Integrator_c = ctrl_TAPM2_X.Integrator_CSTATE_c;

  /* MATLAB Function: '<S82>/Actual Force and Torque' incorporates:
   *  Constant: '<S39>/Losses (placeholder)'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   */
  ctrl_TAPM2_ActualForceandTorque(ctrl_TAPM2_B.Integrator_c, ctrl_TAPM2_P.Kq,
    ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Kqr, ctrl_TAPM2_P.Rho,
    ctrl_TAPM2_P.D, ctrl_TAPM2_P.eps_c, ctrl_TAPM2_P.Lossesplaceholder_Value_f,
    &ctrl_TAPM2_B.sf_ActualForceandTorque_o);

  /* Integrator: '<S93>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_d,
                       ctrl_TAPM2_B.reset_i);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM2_X.Integrator_CSTATE_h = ctrl_TAPM2_P.Integrator_IC_li;
    }
  }

  ctrl_TAPM2_B.Integrator_m = ctrl_TAPM2_X.Integrator_CSTATE_h;

  /* MATLAB Function: '<S92>/Actual Force and Torque' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/D'
   *  Constant: '<S3>/Kq'
   *  Constant: '<S3>/Kqr'
   *  Constant: '<S3>/Kt'
   *  Constant: '<S3>/Ktr'
   *  Constant: '<S3>/Rho'
   *  Constant: '<S40>/Losses (placeholder)'
   */
  ctrl_TAPM2_ActualForceandTorque(ctrl_TAPM2_B.Integrator_m, ctrl_TAPM2_P.Kq,
    ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Kqr, ctrl_TAPM2_P.Rho,
    ctrl_TAPM2_P.D, ctrl_TAPM2_P.eps_c, ctrl_TAPM2_P.Lossesplaceholder_Value_h,
    &ctrl_TAPM2_B.sf_ActualForceandTorque_j);

  /* MATLAB Function: '<S33>/MATLAB Function' incorporates:
   *  Constant: '<S33>/Constant12'
   *  SignalConversion: '<S41>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Thruster control /Subsystem/MATLAB Function': '<S41>:1' */
  if (ctrl_TAPM2_P.Constant12_Value == 1.0) {
    /* '<S41>:1:3' */
    /* '<S41>:1:4' */
    rtb_output_idx_0 = 0.0;
    rtb_output_idx_2 = 0.0;
    rtb_output_idx_4 = 0.0;
    rtb_output_idx_6 = 0.0;
    rtb_output_idx_8 = 0.0;
    rtb_output_idx_10 = 0.0;
  } else {
    /* '<S41>:1:6' */
    rtb_output_idx_0 = ctrl_TAPM2_B.sf_ActualForceandTorque.Ta;
    rtb_output_idx_2 = ctrl_TAPM2_B.sf_ActualForceandTorque_f.Ta;
    rtb_output_idx_4 = ctrl_TAPM2_B.sf_ActualForceandTorque_h.Ta;
    rtb_output_idx_6 = ctrl_TAPM2_B.sf_ActualForceandTorque_m.Ta;
    rtb_output_idx_8 = ctrl_TAPM2_B.sf_ActualForceandTorque_o.Ta;
    rtb_output_idx_10 = ctrl_TAPM2_B.sf_ActualForceandTorque_j.Ta;
  }

  /* End of MATLAB Function: '<S33>/MATLAB Function' */

  /* Saturate: '<S33>/Saturation 2' */
  if (rtb_output_idx_2 > ctrl_TAPM2_P.Max_thrust) {
    rtb_Saturation2 = ctrl_TAPM2_P.Max_thrust;
  } else if (rtb_output_idx_2 < -ctrl_TAPM2_P.Max_thrust) {
    rtb_Saturation2 = -ctrl_TAPM2_P.Max_thrust;
  } else {
    rtb_Saturation2 = rtb_output_idx_2;
  }

  /* End of Saturate: '<S33>/Saturation 2' */

  /* Polyval: '<S33>/pwm thruster 2' */
  ctrl_TAPM2_B.pwmthruster2 = ctrl_TAPM2_P.thrust_to_pwm_coeff[0];
  for (i = 0; i < 5; i++) {
    ctrl_TAPM2_B.pwmthruster2 = ctrl_TAPM2_B.pwmthruster2 * rtb_Saturation2 +
      ctrl_TAPM2_P.thrust_to_pwm_coeff[i + 1];
  }

  /* End of Polyval: '<S33>/pwm thruster 2' */

  /* Saturate: '<S33>/Saturation 3' */
  if (rtb_output_idx_4 > ctrl_TAPM2_P.Max_thrust) {
    rtb_Saturation2 = ctrl_TAPM2_P.Max_thrust;
  } else if (rtb_output_idx_4 < -ctrl_TAPM2_P.Max_thrust) {
    rtb_Saturation2 = -ctrl_TAPM2_P.Max_thrust;
  } else {
    rtb_Saturation2 = rtb_output_idx_4;
  }

  /* End of Saturate: '<S33>/Saturation 3' */

  /* Polyval: '<S33>/pwm thruster 3' */
  ctrl_TAPM2_B.pwmthruster3 = ctrl_TAPM2_P.thrust_to_pwm_coeff[0];
  for (i = 0; i < 5; i++) {
    ctrl_TAPM2_B.pwmthruster3 = ctrl_TAPM2_B.pwmthruster3 * rtb_Saturation2 +
      ctrl_TAPM2_P.thrust_to_pwm_coeff[i + 1];
  }

  /* End of Polyval: '<S33>/pwm thruster 3' */

  /* Saturate: '<S33>/Saturation 4' */
  if (rtb_output_idx_6 > ctrl_TAPM2_P.Max_thrust) {
    rtb_Saturation2 = ctrl_TAPM2_P.Max_thrust;
  } else if (rtb_output_idx_6 < -ctrl_TAPM2_P.Max_thrust) {
    rtb_Saturation2 = -ctrl_TAPM2_P.Max_thrust;
  } else {
    rtb_Saturation2 = rtb_output_idx_6;
  }

  /* End of Saturate: '<S33>/Saturation 4' */

  /* Polyval: '<S33>/pwm thruster 4' */
  ctrl_TAPM2_B.pwmthruster4 = ctrl_TAPM2_P.thrust_to_pwm_coeff[0];
  for (i = 0; i < 5; i++) {
    ctrl_TAPM2_B.pwmthruster4 = ctrl_TAPM2_B.pwmthruster4 * rtb_Saturation2 +
      ctrl_TAPM2_P.thrust_to_pwm_coeff[i + 1];
  }

  /* End of Polyval: '<S33>/pwm thruster 4' */

  /* Saturate: '<S33>/Saturation 5' */
  if (rtb_output_idx_8 > ctrl_TAPM2_P.Max_thrust) {
    rtb_Saturation2 = ctrl_TAPM2_P.Max_thrust;
  } else if (rtb_output_idx_8 < -ctrl_TAPM2_P.Max_thrust) {
    rtb_Saturation2 = -ctrl_TAPM2_P.Max_thrust;
  } else {
    rtb_Saturation2 = rtb_output_idx_8;
  }

  /* End of Saturate: '<S33>/Saturation 5' */

  /* Polyval: '<S33>/pwm thruster 5' */
  ctrl_TAPM2_B.pwmthruster5 = ctrl_TAPM2_P.thrust_to_pwm_coeff[0];
  for (i = 0; i < 5; i++) {
    ctrl_TAPM2_B.pwmthruster5 = ctrl_TAPM2_B.pwmthruster5 * rtb_Saturation2 +
      ctrl_TAPM2_P.thrust_to_pwm_coeff[i + 1];
  }

  /* End of Polyval: '<S33>/pwm thruster 5' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Saturate: '<S34>/Saturation 2' incorporates:
     *  Constant: '<Root>/X-position Thruster1'
     */
    if (ctrl_TAPM2_P.XpositionThruster1_Value[3] >
        ctrl_TAPM2_P.Saturation2_UpperSat) {
      ctrl_TAPM2_B.Saturation2 = ctrl_TAPM2_P.Saturation2_UpperSat;
    } else if (ctrl_TAPM2_P.XpositionThruster1_Value[3] <
               ctrl_TAPM2_P.Saturation2_LowerSat) {
      ctrl_TAPM2_B.Saturation2 = ctrl_TAPM2_P.Saturation2_LowerSat;
    } else {
      ctrl_TAPM2_B.Saturation2 = ctrl_TAPM2_P.XpositionThruster1_Value[3];
    }

    /* End of Saturate: '<S34>/Saturation 2' */
  }

  /* Saturate: '<S33>/Saturation 6' */
  if (rtb_output_idx_10 > ctrl_TAPM2_P.Max_thrust) {
    rtb_Saturation2 = ctrl_TAPM2_P.Max_thrust;
  } else if (rtb_output_idx_10 < -ctrl_TAPM2_P.Max_thrust) {
    rtb_Saturation2 = -ctrl_TAPM2_P.Max_thrust;
  } else {
    rtb_Saturation2 = rtb_output_idx_10;
  }

  /* End of Saturate: '<S33>/Saturation 6' */

  /* Polyval: '<S33>/pwm thruster 6' */
  ctrl_TAPM2_B.pwmthruster6 = ctrl_TAPM2_P.thrust_to_pwm_coeff[0];
  for (i = 0; i < 5; i++) {
    ctrl_TAPM2_B.pwmthruster6 = ctrl_TAPM2_B.pwmthruster6 * rtb_Saturation2 +
      ctrl_TAPM2_P.thrust_to_pwm_coeff[i + 1];
  }

  /* End of Polyval: '<S33>/pwm thruster 6' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Saturate: '<S34>/Saturation 3' incorporates:
     *  Constant: '<Root>/X-position Thruster1'
     */
    if (ctrl_TAPM2_P.XpositionThruster1_Value[5] >
        ctrl_TAPM2_P.Saturation3_UpperSat) {
      ctrl_TAPM2_B.Saturation3 = ctrl_TAPM2_P.Saturation3_UpperSat;
    } else if (ctrl_TAPM2_P.XpositionThruster1_Value[5] <
               ctrl_TAPM2_P.Saturation3_LowerSat) {
      ctrl_TAPM2_B.Saturation3 = ctrl_TAPM2_P.Saturation3_LowerSat;
    } else {
      ctrl_TAPM2_B.Saturation3 = ctrl_TAPM2_P.XpositionThruster1_Value[5];
    }

    /* End of Saturate: '<S34>/Saturation 3' */

    /* Saturate: '<S34>/Saturation 4' incorporates:
     *  Constant: '<Root>/X-position Thruster1'
     */
    if (ctrl_TAPM2_P.XpositionThruster1_Value[7] >
        ctrl_TAPM2_P.Saturation4_UpperSat) {
      ctrl_TAPM2_B.Saturation4 = ctrl_TAPM2_P.Saturation4_UpperSat;
    } else if (ctrl_TAPM2_P.XpositionThruster1_Value[7] <
               ctrl_TAPM2_P.Saturation4_LowerSat) {
      ctrl_TAPM2_B.Saturation4 = ctrl_TAPM2_P.Saturation4_LowerSat;
    } else {
      ctrl_TAPM2_B.Saturation4 = ctrl_TAPM2_P.XpositionThruster1_Value[7];
    }

    /* End of Saturate: '<S34>/Saturation 4' */

    /* Saturate: '<S34>/Saturation 5' incorporates:
     *  Constant: '<Root>/X-position Thruster1'
     */
    if (ctrl_TAPM2_P.XpositionThruster1_Value[9] >
        ctrl_TAPM2_P.Saturation5_UpperSat) {
      ctrl_TAPM2_B.Saturation5 = ctrl_TAPM2_P.Saturation5_UpperSat;
    } else if (ctrl_TAPM2_P.XpositionThruster1_Value[9] <
               ctrl_TAPM2_P.Saturation5_LowerSat) {
      ctrl_TAPM2_B.Saturation5 = ctrl_TAPM2_P.Saturation5_LowerSat;
    } else {
      ctrl_TAPM2_B.Saturation5 = ctrl_TAPM2_P.XpositionThruster1_Value[9];
    }

    /* End of Saturate: '<S34>/Saturation 5' */

    /* Saturate: '<S34>/Saturation 6' incorporates:
     *  Constant: '<Root>/X-position Thruster1'
     */
    if (ctrl_TAPM2_P.XpositionThruster1_Value[11] >
        ctrl_TAPM2_P.Saturation6_UpperSat) {
      ctrl_TAPM2_B.Saturation6 = ctrl_TAPM2_P.Saturation6_UpperSat;
    } else if (ctrl_TAPM2_P.XpositionThruster1_Value[11] <
               ctrl_TAPM2_P.Saturation6_LowerSat) {
      ctrl_TAPM2_B.Saturation6 = ctrl_TAPM2_P.Saturation6_LowerSat;
    } else {
      ctrl_TAPM2_B.Saturation6 = ctrl_TAPM2_P.XpositionThruster1_Value[11];
    }

    /* End of Saturate: '<S34>/Saturation 6' */
  }

  /* Saturate: '<S33>/Saturation 7' */
  if (rtb_output_idx_0 > ctrl_TAPM2_P.Max_thrust) {
    ctrl_TAPM2_B.Saturation7[0] = ctrl_TAPM2_P.Max_thrust;
  } else if (rtb_output_idx_0 < -ctrl_TAPM2_P.Max_thrust) {
    ctrl_TAPM2_B.Saturation7[0] = -ctrl_TAPM2_P.Max_thrust;
  } else {
    ctrl_TAPM2_B.Saturation7[0] = rtb_output_idx_0;
  }

  if (rtb_output_idx_2 > ctrl_TAPM2_P.Max_thrust) {
    ctrl_TAPM2_B.Saturation7[1] = ctrl_TAPM2_P.Max_thrust;
  } else if (rtb_output_idx_2 < -ctrl_TAPM2_P.Max_thrust) {
    ctrl_TAPM2_B.Saturation7[1] = -ctrl_TAPM2_P.Max_thrust;
  } else {
    ctrl_TAPM2_B.Saturation7[1] = rtb_output_idx_2;
  }

  if (rtb_output_idx_4 > ctrl_TAPM2_P.Max_thrust) {
    ctrl_TAPM2_B.Saturation7[2] = ctrl_TAPM2_P.Max_thrust;
  } else if (rtb_output_idx_4 < -ctrl_TAPM2_P.Max_thrust) {
    ctrl_TAPM2_B.Saturation7[2] = -ctrl_TAPM2_P.Max_thrust;
  } else {
    ctrl_TAPM2_B.Saturation7[2] = rtb_output_idx_4;
  }

  if (rtb_output_idx_6 > ctrl_TAPM2_P.Max_thrust) {
    ctrl_TAPM2_B.Saturation7[3] = ctrl_TAPM2_P.Max_thrust;
  } else if (rtb_output_idx_6 < -ctrl_TAPM2_P.Max_thrust) {
    ctrl_TAPM2_B.Saturation7[3] = -ctrl_TAPM2_P.Max_thrust;
  } else {
    ctrl_TAPM2_B.Saturation7[3] = rtb_output_idx_6;
  }

  if (rtb_output_idx_8 > ctrl_TAPM2_P.Max_thrust) {
    ctrl_TAPM2_B.Saturation7[4] = ctrl_TAPM2_P.Max_thrust;
  } else if (rtb_output_idx_8 < -ctrl_TAPM2_P.Max_thrust) {
    ctrl_TAPM2_B.Saturation7[4] = -ctrl_TAPM2_P.Max_thrust;
  } else {
    ctrl_TAPM2_B.Saturation7[4] = rtb_output_idx_8;
  }

  if (rtb_output_idx_10 > ctrl_TAPM2_P.Max_thrust) {
    ctrl_TAPM2_B.Saturation7[5] = ctrl_TAPM2_P.Max_thrust;
  } else if (rtb_output_idx_10 < -ctrl_TAPM2_P.Max_thrust) {
    ctrl_TAPM2_B.Saturation7[5] = -ctrl_TAPM2_P.Max_thrust;
  } else {
    ctrl_TAPM2_B.Saturation7[5] = rtb_output_idx_10;
  }

  /* End of Saturate: '<S33>/Saturation 7' */

  /* Saturate: '<S33>/Saturation 1' */
  if (rtb_output_idx_0 > ctrl_TAPM2_P.Max_thrust) {
    rtb_Saturation2 = ctrl_TAPM2_P.Max_thrust;
  } else if (rtb_output_idx_0 < -ctrl_TAPM2_P.Max_thrust) {
    rtb_Saturation2 = -ctrl_TAPM2_P.Max_thrust;
  } else {
    rtb_Saturation2 = rtb_output_idx_0;
  }

  /* End of Saturate: '<S33>/Saturation 1' */

  /* Polyval: '<S33>/pwm thruster 1' */
  ctrl_TAPM2_B.pwmthruster1 = ctrl_TAPM2_P.thrust_to_pwm_coeff[0];
  for (i = 0; i < 5; i++) {
    ctrl_TAPM2_B.pwmthruster1 = ctrl_TAPM2_B.pwmthruster1 * rtb_Saturation2 +
      ctrl_TAPM2_P.thrust_to_pwm_coeff[i + 1];
  }

  /* End of Polyval: '<S33>/pwm thruster 1' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Gain: '<S5>/Gain' */
    ctrl_TAPM2_B.Gain[0] = ctrl_TAPM2_P.Gain_Gain * ctrl_TAPM2_B.Saturation1;
    ctrl_TAPM2_B.Gain[1] = ctrl_TAPM2_P.Gain_Gain * ctrl_TAPM2_B.Saturation2;
    ctrl_TAPM2_B.Gain[2] = ctrl_TAPM2_P.Gain_Gain * ctrl_TAPM2_B.Saturation3;
    ctrl_TAPM2_B.Gain[3] = ctrl_TAPM2_P.Gain_Gain * ctrl_TAPM2_B.Saturation4;
    ctrl_TAPM2_B.Gain[4] = ctrl_TAPM2_P.Gain_Gain * ctrl_TAPM2_B.Saturation5;
    ctrl_TAPM2_B.Gain[5] = ctrl_TAPM2_P.Gain_Gain * ctrl_TAPM2_B.Saturation6;
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
  ctrl_TAPM2_B.actual_tau[0] = 0.0;
  ctrl_TAPM2_B.actual_tau[1] = 0.0;
  ctrl_TAPM2_B.actual_tau[2] = 0.0;
  rtb_Saturation2 = ctrl_TAPM2_B.Gain[0];
  ctrl_TAPM2_cosd(&rtb_Saturation2);
  absxk = ctrl_TAPM2_B.Gain[1];
  ctrl_TAPM2_cosd(&absxk);
  offset = ctrl_TAPM2_B.Gain[2];
  ctrl_TAPM2_cosd(&offset);
  rtb_Row2 = ctrl_TAPM2_B.Gain[3];
  ctrl_TAPM2_cosd(&rtb_Row2);
  rtb_output_idx_0 = ctrl_TAPM2_B.Gain[4];
  ctrl_TAPM2_cosd(&rtb_output_idx_0);
  rtb_output_idx_2 = ctrl_TAPM2_B.Gain[5];
  ctrl_TAPM2_cosd(&rtb_output_idx_2);
  rtb_output_idx_4 = ctrl_TAPM2_B.Gain[0];
  ctrl_TAPM2_sind(&rtb_output_idx_4);
  rtb_output_idx_6 = ctrl_TAPM2_B.Gain[1];
  ctrl_TAPM2_sind(&rtb_output_idx_6);
  rtb_output_idx_8 = ctrl_TAPM2_B.Gain[2];
  ctrl_TAPM2_sind(&rtb_output_idx_8);
  rtb_output_idx_10 = ctrl_TAPM2_B.Gain[3];
  ctrl_TAPM2_sind(&rtb_output_idx_10);
  l = ctrl_TAPM2_B.Gain[4];
  ctrl_TAPM2_sind(&l);
  m = ctrl_TAPM2_B.Gain[5];
  ctrl_TAPM2_sind(&m);
  n = ctrl_TAPM2_B.Gain[0];
  ctrl_TAPM2_sind(&n);
  o = ctrl_TAPM2_B.Gain[0];
  ctrl_TAPM2_cosd(&o);
  p = ctrl_TAPM2_B.Gain[1];
  ctrl_TAPM2_sind(&p);
  q = ctrl_TAPM2_B.Gain[1];
  ctrl_TAPM2_cosd(&q);
  r = ctrl_TAPM2_B.Gain[2];
  ctrl_TAPM2_sind(&r);
  s = ctrl_TAPM2_B.Gain[2];
  ctrl_TAPM2_cosd(&s);
  t = ctrl_TAPM2_B.Gain[3];
  ctrl_TAPM2_sind(&t);
  u = ctrl_TAPM2_B.Gain[3];
  ctrl_TAPM2_cosd(&u);
  v = ctrl_TAPM2_B.Gain[4];
  ctrl_TAPM2_sind(&v);
  w = ctrl_TAPM2_B.Gain[4];
  ctrl_TAPM2_cosd(&w);
  x = ctrl_TAPM2_B.Gain[5];
  ctrl_TAPM2_sind(&x);
  y = ctrl_TAPM2_B.Gain[5];
  ctrl_TAPM2_cosd(&y);
  rtb_Saturation2_0[0] = rtb_Saturation2;
  rtb_Saturation2_0[3] = absxk;
  rtb_Saturation2_0[6] = offset;
  rtb_Saturation2_0[9] = rtb_Row2;
  rtb_Saturation2_0[12] = rtb_output_idx_0;
  rtb_Saturation2_0[15] = rtb_output_idx_2;
  rtb_Saturation2_0[1] = rtb_output_idx_4;
  rtb_Saturation2_0[4] = rtb_output_idx_6;
  rtb_Saturation2_0[7] = rtb_output_idx_8;
  rtb_Saturation2_0[10] = rtb_output_idx_10;
  rtb_Saturation2_0[13] = l;
  rtb_Saturation2_0[16] = m;
  rtb_Saturation2_0[2] = n * ctrl_TAPM2_P.XpositionThruster_Value[0] - o *
    ctrl_TAPM2_P.YpositionThruster_Value[0];
  rtb_Saturation2_0[5] = p * ctrl_TAPM2_P.XpositionThruster_Value[1] - q *
    ctrl_TAPM2_P.YpositionThruster_Value[1];
  rtb_Saturation2_0[8] = r * ctrl_TAPM2_P.XpositionThruster_Value[2] - s *
    ctrl_TAPM2_P.YpositionThruster_Value[2];
  rtb_Saturation2_0[11] = t * ctrl_TAPM2_P.XpositionThruster_Value[3] - u *
    ctrl_TAPM2_P.YpositionThruster_Value[3];
  rtb_Saturation2_0[14] = v * ctrl_TAPM2_P.XpositionThruster_Value[4] - w *
    ctrl_TAPM2_P.YpositionThruster_Value[4];
  rtb_Saturation2_0[17] = x * ctrl_TAPM2_P.XpositionThruster_Value[5] - y *
    ctrl_TAPM2_P.YpositionThruster_Value[5];
  for (i = 0; i < 3; i++) {
    ctrl_TAPM2_B.actual_tau[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      ctrl_TAPM2_B.actual_tau[i] += rtb_Saturation2_0[3 * i_0 + i] *
        ctrl_TAPM2_B.Saturation7[i_0];
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Delay: '<S8>/Delay' */
    for (i = 0; i < 6; i++) {
      rtb_Delay[i] = ctrl_TAPM2_DW.Delay_DSTATE[i];
    }

    /* End of Delay: '<S8>/Delay' */

    /* Delay: '<S35>/Delay' */
    ctrl_TAPM2_B.Delay = ctrl_TAPM2_DW.Delay_DSTATE_f;

    /* MATLAB Function: '<S44>/MATLAB Function' incorporates:
     *  Constant: '<Root>/X-position Thruster1'
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/D'
     *  Constant: '<S3>/Kt'
     *  Constant: '<S3>/Ktr'
     *  Constant: '<S3>/Rho'
     *  Delay: '<S44>/Delay'
     */
    /* MATLAB Function 'Thruster control /Thruster 1/Thruster control/MATLAB Function': '<S48>:1' */
    /* '<S48>:1:5' */
    if (ctrl_TAPM2_P.XpositionThruster1_Value[0] < 0.0) {
      rtb_output_idx_4 = -1.0;
    } else if (ctrl_TAPM2_P.XpositionThruster1_Value[0] > 0.0) {
      rtb_output_idx_4 = 1.0;
    } else if (ctrl_TAPM2_P.XpositionThruster1_Value[0] == 0.0) {
      rtb_output_idx_4 = 0.0;
    } else {
      rtb_output_idx_4 = ctrl_TAPM2_P.XpositionThruster1_Value[0];
    }

    absxk = sqrt(fabs(ctrl_TAPM2_P.XpositionThruster1_Value[0]) /
                 (ctrl_TAPM2_P.Rho * rt_powd_snf(ctrl_TAPM2_P.D, 4.0) *
                  ctrl_TAPM2_P.Kt)) * rtb_output_idx_4;

    /* '<S48>:1:7' */
    rtb_Saturation2 = tanh(ctrl_TAPM2_P.eps_c * absxk / 5.0) * 0.5 + 0.5;

    /*  Smooth switching between positive and negative thrust. 5 makes switch happen between -5 and 5 */
    /* '<S48>:1:8' */
    /* '<S48>:1:10' */
    if (ctrl_TAPM2_DW.Delay_DSTATE_fu < 0.0) {
      rtb_output_idx_4 = -1.0;
    } else if (ctrl_TAPM2_DW.Delay_DSTATE_fu > 0.0) {
      rtb_output_idx_4 = 1.0;
    } else if (ctrl_TAPM2_DW.Delay_DSTATE_fu == 0.0) {
      rtb_output_idx_4 = 0.0;
    } else {
      rtb_output_idx_4 = ctrl_TAPM2_DW.Delay_DSTATE_fu;
    }

    rtb_T_r_c = ((1.0 - rtb_Saturation2) * ctrl_TAPM2_P.Ktr + ctrl_TAPM2_P.Kt *
                 rtb_Saturation2) * rtb_output_idx_4 * ctrl_TAPM2_P.Rho *
      rt_powd_snf(ctrl_TAPM2_P.D, 4.0) * (ctrl_TAPM2_DW.Delay_DSTATE_fu *
      ctrl_TAPM2_DW.Delay_DSTATE_fu);

    /* DiscreteTransferFcn: '<S44>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S44>/Constant1'
     *  Constant: '<S44>/Constant2'
     *  MATLAB Function: '<S44>/MATLAB Function'
     */
    ctrl_TAPM2_DW.DiscreteTransferFcn_tmp = (absxk -
      ctrl_TAPM2_P.Constant2_Value[1] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states[0]) -
      ctrl_TAPM2_P.Constant2_Value[2] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states[1];
    ctrl_TAPM2_B.DiscreteTransferFcn = (ctrl_TAPM2_P.Constant1_Value_o[0] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp + ctrl_TAPM2_P.Constant1_Value_o[1] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states[0]) +
      ctrl_TAPM2_P.Constant1_Value_o[2] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states[1];

    /* SampleTimeMath: '<S47>/TSamp'
     *
     * About '<S47>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM2_B.TSamp = ctrl_TAPM2_B.DiscreteTransferFcn *
      ctrl_TAPM2_P.TSamp_WtEt;

    /* Sum: '<S47>/Diff' incorporates:
     *  UnitDelay: '<S47>/UD'
     */
    rtb_Sum_b = ctrl_TAPM2_B.TSamp - ctrl_TAPM2_DW.UD_DSTATE;

    /* RateLimiter: '<S44>/Acceleration Limit' */
    rtb_Saturation2 = rtb_Sum_b - ctrl_TAPM2_DW.PrevY;
    if (rtb_Saturation2 > ctrl_TAPM2_P.AccelerationLimit_RisingLim) {
      rtb_Sum_b = ctrl_TAPM2_DW.PrevY + ctrl_TAPM2_P.AccelerationLimit_RisingLim;
    } else {
      if (rtb_Saturation2 < ctrl_TAPM2_P.AccelerationLimit_FallingLim) {
        rtb_Sum_b = ctrl_TAPM2_DW.PrevY +
          ctrl_TAPM2_P.AccelerationLimit_FallingLim;
      }
    }

    ctrl_TAPM2_DW.PrevY = rtb_Sum_b;

    /* End of RateLimiter: '<S44>/Acceleration Limit' */

    /* Gain: '<S44>/Inertia compensation' */
    ctrl_TAPM2_B.Inertiacompensation = ctrl_TAPM2_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S44>/Sum1' incorporates:
     *  Gain: '<S44>/Qf_0'
     *  Gain: '<S44>/Qff_0(nr)'
     *  Gain: '<S44>/Qff_1(nr)'
     *  Trigonometry: '<S44>/Trigonometric Function'
     */
    ctrl_TAPM2_B.Sum1 = tanh(ctrl_TAPM2_P.epsilon / ctrl_TAPM2_P.n_max *
      ctrl_TAPM2_B.DiscreteTransferFcn) * ctrl_TAPM2_P.Q_f0 +
      ctrl_TAPM2_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM2_B.DiscreteTransferFcn;

    /* Memory: '<S44>/Memory' */
    ctrl_TAPM2_B.Memory = ctrl_TAPM2_DW.Memory_PreviousInput;

    /* Sum: '<S46>/Sum' */
    rtb_Sum_b = ctrl_TAPM2_B.DiscreteTransferFcn - rtb_Delay[0];

    /* Gain: '<S46>/Kp' */
    ctrl_TAPM2_B.Kp = ctrl_TAPM2_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S46>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_o3,
                       ctrl_TAPM2_B.reset_kk);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM2_X.Integrator_CSTATE_e = ctrl_TAPM2_P.Integrator_IC_a;
    }
  }

  rtb_Integrator = ctrl_TAPM2_X.Integrator_CSTATE_e;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* MATLAB Function: '<S46>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
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
    CorecontrollerTorquePowerandCom(ctrl_TAPM2_P.k_cc, ctrl_TAPM2_P.p_cc,
      ctrl_TAPM2_P.r_cc, rtb_Delay[0], ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Kq,
      ctrl_TAPM2_P.D, rtb_T_r_c, ctrl_TAPM2_P.eps, ctrl_TAPM2_P.Rho,
      ctrl_TAPM2_P.eps_c, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Kqr,
      &ctrl_TAPM2_B.sf_CorecontrollerTorquePowerand);
  }

  /* MultiPortSwitch: '<S44>/Controller chosen' incorporates:
   *  Constant: '<S44>/NaN'
   *  Sum: '<S46>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM2_B.Memory) {
   case 1:
    rtb_Row2 = ctrl_TAPM2_B.Kp + rtb_Integrator;
    break;

   case 2:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePowerand.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePowerand.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePowerand.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_TAPM2_P.NaN_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S44>/Controller chosen' */

  /* Sum: '<S44>/Sum' */
  ctrl_TAPM2_B.Sum = (ctrl_TAPM2_B.Inertiacompensation + ctrl_TAPM2_B.Sum1) +
    rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* DiscreteTransferFcn: '<S35>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S35>/Constant'
     *  Constant: '<S35>/Constant1'
     */
    ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_a = ctrl_TAPM2_B.Sum -
      ctrl_TAPM2_P.Constant_Value[1] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_d;
    ctrl_TAPM2_B.DiscreteTransferFcn_d = ctrl_TAPM2_P.Constant1_Value[0] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_a + ctrl_TAPM2_P.Constant1_Value[1] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_d;
  }

  /* Gain: '<S43>/Finding rotation speed' incorporates:
   *  Gain: '<S43>/K_omega'
   *  Sum: '<S43>/Sum'
   */
  ctrl_TAPM2_B.Findingrotationspeed = ((ctrl_TAPM2_B.DiscreteTransferFcn_d -
    ctrl_TAPM2_B.Delay) - ctrl_TAPM2_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_TAPM2_B.Integrator) * (1.0 / (6.2831853071795862 * ctrl_TAPM2_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Gain: '<S46>/Ki' */
    ctrl_TAPM2_B.Ki = ctrl_TAPM2_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S44>/Supervisor' incorporates:
     *  Constant: '<S44>/Switch controller'
     */
    ctrl_TAPM2_Supervisor(ctrl_TAPM2_B.Memory, ctrl_TAPM2_P.Thruster_control,
                          rtb_Delay[0], &ctrl_TAPM2_B.sf_Supervisor);

    /* Delay: '<S36>/Delay' */
    ctrl_TAPM2_B.Delay_b = ctrl_TAPM2_DW.Delay_DSTATE_b;

    /* Delay: '<S54>/Delay' */
    rtb_Delay_b = ctrl_TAPM2_DW.Delay_DSTATE_d;

    /* MATLAB Function: '<S54>/MATLAB Function' incorporates:
     *  Constant: '<Root>/X-position Thruster1'
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/D'
     *  Constant: '<S3>/Kt'
     *  Constant: '<S3>/Ktr'
     *  Constant: '<S3>/Rho'
     */
    ctrl_TAPM2_MATLABFunction(ctrl_TAPM2_P.XpositionThruster1_Value[2],
      ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Rho, ctrl_TAPM2_P.D,
      ctrl_TAPM2_P.eps_c, rtb_Delay_b, &ctrl_TAPM2_B.sf_MATLABFunction_i);

    /* DiscreteTransferFcn: '<S54>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S54>/Constant1'
     *  Constant: '<S54>/Constant2'
     */
    ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_d =
      (ctrl_TAPM2_B.sf_MATLABFunction_i.n_d - ctrl_TAPM2_P.Constant2_Value_i[1] *
       ctrl_TAPM2_DW.DiscreteTransferFcn_states_h[0]) -
      ctrl_TAPM2_P.Constant2_Value_i[2] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_h[1];
    ctrl_TAPM2_B.DiscreteTransferFcn_e = (ctrl_TAPM2_P.Constant1_Value_b[0] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_d + ctrl_TAPM2_P.Constant1_Value_b[1]
      * ctrl_TAPM2_DW.DiscreteTransferFcn_states_h[0]) +
      ctrl_TAPM2_P.Constant1_Value_b[2] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_h[1];

    /* SampleTimeMath: '<S57>/TSamp'
     *
     * About '<S57>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM2_B.TSamp_n = ctrl_TAPM2_B.DiscreteTransferFcn_e *
      ctrl_TAPM2_P.TSamp_WtEt_k;

    /* Sum: '<S57>/Diff' incorporates:
     *  UnitDelay: '<S57>/UD'
     */
    rtb_Sum_b = ctrl_TAPM2_B.TSamp_n - ctrl_TAPM2_DW.UD_DSTATE_n;

    /* RateLimiter: '<S54>/Acceleration Limit' */
    rtb_Saturation2 = rtb_Sum_b - ctrl_TAPM2_DW.PrevY_e;
    if (rtb_Saturation2 > ctrl_TAPM2_P.AccelerationLimit_RisingLim_n) {
      rtb_Sum_b = ctrl_TAPM2_DW.PrevY_e +
        ctrl_TAPM2_P.AccelerationLimit_RisingLim_n;
    } else {
      if (rtb_Saturation2 < ctrl_TAPM2_P.AccelerationLimit_FallingLim_n) {
        rtb_Sum_b = ctrl_TAPM2_DW.PrevY_e +
          ctrl_TAPM2_P.AccelerationLimit_FallingLim_n;
      }
    }

    ctrl_TAPM2_DW.PrevY_e = rtb_Sum_b;

    /* End of RateLimiter: '<S54>/Acceleration Limit' */

    /* Gain: '<S54>/Inertia compensation' */
    ctrl_TAPM2_B.Inertiacompensation_e = ctrl_TAPM2_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S54>/Sum1' incorporates:
     *  Gain: '<S54>/Qf_0'
     *  Gain: '<S54>/Qff_0(nr)'
     *  Gain: '<S54>/Qff_1(nr)'
     *  Trigonometry: '<S54>/Trigonometric Function'
     */
    ctrl_TAPM2_B.Sum1_n = tanh(ctrl_TAPM2_P.epsilon / ctrl_TAPM2_P.n_max *
      ctrl_TAPM2_B.DiscreteTransferFcn_e) * ctrl_TAPM2_P.Q_f0 +
      ctrl_TAPM2_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM2_B.DiscreteTransferFcn_e;

    /* Memory: '<S54>/Memory' */
    ctrl_TAPM2_B.Memory_c = ctrl_TAPM2_DW.Memory_PreviousInput_n;

    /* Sum: '<S56>/Sum' */
    rtb_Sum_b = ctrl_TAPM2_B.DiscreteTransferFcn_e - rtb_Delay[1];

    /* Gain: '<S56>/Kp' */
    ctrl_TAPM2_B.Kp_p = ctrl_TAPM2_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S56>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_db,
                       ctrl_TAPM2_B.reset_e);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM2_X.Integrator_CSTATE_g = ctrl_TAPM2_P.Integrator_IC_fy;
    }
  }

  rtb_Integrator_f = ctrl_TAPM2_X.Integrator_CSTATE_g;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* MATLAB Function: '<S56>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
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
    CorecontrollerTorquePowerandCom(ctrl_TAPM2_P.k_cc, ctrl_TAPM2_P.p_cc,
      ctrl_TAPM2_P.r_cc, rtb_Delay[1], ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Kq,
      ctrl_TAPM2_P.D, ctrl_TAPM2_B.sf_MATLABFunction_i.T_r, ctrl_TAPM2_P.eps,
      ctrl_TAPM2_P.Rho, ctrl_TAPM2_P.eps_c, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Kqr,
      &ctrl_TAPM2_B.sf_CorecontrollerTorquePowera_o);
  }

  /* MultiPortSwitch: '<S54>/Controller chosen' incorporates:
   *  Constant: '<S54>/NaN'
   *  Sum: '<S56>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM2_B.Memory_c) {
   case 1:
    rtb_Row2 = ctrl_TAPM2_B.Kp_p + rtb_Integrator_f;
    break;

   case 2:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePowera_o.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePowera_o.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePowera_o.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_TAPM2_P.NaN_Value_l;
    break;
  }

  /* End of MultiPortSwitch: '<S54>/Controller chosen' */

  /* Sum: '<S54>/Sum' */
  ctrl_TAPM2_B.Sum_h = (ctrl_TAPM2_B.Inertiacompensation_e + ctrl_TAPM2_B.Sum1_n)
    + rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S36>/Constant1'
     */
    ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_h = ctrl_TAPM2_B.Sum_h -
      ctrl_TAPM2_P.Constant_Value_h[1] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_m;
    ctrl_TAPM2_B.DiscreteTransferFcn_k = ctrl_TAPM2_P.Constant1_Value_j[0] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_h + ctrl_TAPM2_P.Constant1_Value_j[1]
      * ctrl_TAPM2_DW.DiscreteTransferFcn_states_m;
  }

  /* Gain: '<S53>/Finding rotation speed' incorporates:
   *  Gain: '<S53>/K_omega'
   *  Sum: '<S53>/Sum'
   */
  ctrl_TAPM2_B.Findingrotationspeed_a = ((ctrl_TAPM2_B.DiscreteTransferFcn_k -
    ctrl_TAPM2_B.Delay_b) - ctrl_TAPM2_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_TAPM2_B.Integrator_h) * (1.0 / (6.2831853071795862 * ctrl_TAPM2_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Gain: '<S56>/Ki' */
    ctrl_TAPM2_B.Ki_o = ctrl_TAPM2_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S54>/Supervisor' incorporates:
     *  Constant: '<S54>/Switch controller'
     */
    ctrl_TAPM2_Supervisor(ctrl_TAPM2_B.Memory_c, ctrl_TAPM2_P.Thruster_control,
                          rtb_Delay[1], &ctrl_TAPM2_B.sf_Supervisor_h);

    /* Delay: '<S37>/Delay' */
    ctrl_TAPM2_B.Delay_i = ctrl_TAPM2_DW.Delay_DSTATE_n;

    /* Delay: '<S64>/Delay' */
    rtb_Delay_by = ctrl_TAPM2_DW.Delay_DSTATE_no;

    /* MATLAB Function: '<S64>/MATLAB Function' incorporates:
     *  Constant: '<Root>/X-position Thruster1'
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/D'
     *  Constant: '<S3>/Kt'
     *  Constant: '<S3>/Ktr'
     *  Constant: '<S3>/Rho'
     */
    ctrl_TAPM2_MATLABFunction(ctrl_TAPM2_P.XpositionThruster1_Value[4],
      ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Rho, ctrl_TAPM2_P.D,
      ctrl_TAPM2_P.eps_c, rtb_Delay_by, &ctrl_TAPM2_B.sf_MATLABFunction_m);

    /* DiscreteTransferFcn: '<S64>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S64>/Constant1'
     *  Constant: '<S64>/Constant2'
     */
    ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_e =
      (ctrl_TAPM2_B.sf_MATLABFunction_m.n_d - ctrl_TAPM2_P.Constant2_Value_h[1] *
       ctrl_TAPM2_DW.DiscreteTransferFcn_states_j[0]) -
      ctrl_TAPM2_P.Constant2_Value_h[2] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_j[1];
    ctrl_TAPM2_B.DiscreteTransferFcn_f = (ctrl_TAPM2_P.Constant1_Value_g[0] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_e + ctrl_TAPM2_P.Constant1_Value_g[1]
      * ctrl_TAPM2_DW.DiscreteTransferFcn_states_j[0]) +
      ctrl_TAPM2_P.Constant1_Value_g[2] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_j[1];

    /* SampleTimeMath: '<S67>/TSamp'
     *
     * About '<S67>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM2_B.TSamp_k = ctrl_TAPM2_B.DiscreteTransferFcn_f *
      ctrl_TAPM2_P.TSamp_WtEt_m;

    /* Sum: '<S67>/Diff' incorporates:
     *  UnitDelay: '<S67>/UD'
     */
    rtb_Sum_b = ctrl_TAPM2_B.TSamp_k - ctrl_TAPM2_DW.UD_DSTATE_i;

    /* RateLimiter: '<S64>/Acceleration limiter' */
    rtb_Saturation2 = rtb_Sum_b - ctrl_TAPM2_DW.PrevY_o;
    if (rtb_Saturation2 > ctrl_TAPM2_P.Accelerationlimiter_RisingLim) {
      rtb_Sum_b = ctrl_TAPM2_DW.PrevY_o +
        ctrl_TAPM2_P.Accelerationlimiter_RisingLim;
    } else {
      if (rtb_Saturation2 < ctrl_TAPM2_P.Accelerationlimiter_FallingLim) {
        rtb_Sum_b = ctrl_TAPM2_DW.PrevY_o +
          ctrl_TAPM2_P.Accelerationlimiter_FallingLim;
      }
    }

    ctrl_TAPM2_DW.PrevY_o = rtb_Sum_b;

    /* End of RateLimiter: '<S64>/Acceleration limiter' */

    /* Gain: '<S64>/Inertia compensation' */
    ctrl_TAPM2_B.Inertiacompensation_c = ctrl_TAPM2_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S64>/Sum1' incorporates:
     *  Gain: '<S64>/Qf_0'
     *  Gain: '<S64>/Qff_0(nr)'
     *  Gain: '<S64>/Qff_1(nr)'
     *  Trigonometry: '<S64>/Trigonometric Function'
     */
    ctrl_TAPM2_B.Sum1_i = tanh(ctrl_TAPM2_P.epsilon / ctrl_TAPM2_P.n_max *
      ctrl_TAPM2_B.DiscreteTransferFcn_f) * ctrl_TAPM2_P.Q_f0 +
      ctrl_TAPM2_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM2_B.DiscreteTransferFcn_f;

    /* Memory: '<S64>/Memory' */
    ctrl_TAPM2_B.Memory_i = ctrl_TAPM2_DW.Memory_PreviousInput_d;

    /* Sum: '<S66>/Sum' */
    rtb_Sum_b = ctrl_TAPM2_B.DiscreteTransferFcn_f - rtb_Delay[2];

    /* Gain: '<S66>/Kp' */
    ctrl_TAPM2_B.Kp_i = ctrl_TAPM2_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S66>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_l,
                       ctrl_TAPM2_B.reset_j2);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM2_X.Integrator_CSTATE_i = ctrl_TAPM2_P.Integrator_IC_j;
    }
  }

  rtb_Integrator_h = ctrl_TAPM2_X.Integrator_CSTATE_i;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* MATLAB Function: '<S66>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
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
    CorecontrollerTorquePowerandCom(ctrl_TAPM2_P.k_cc, ctrl_TAPM2_P.p_cc,
      ctrl_TAPM2_P.r_cc, rtb_Delay[2], ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Kq,
      ctrl_TAPM2_P.D, ctrl_TAPM2_B.sf_MATLABFunction_m.T_r, ctrl_TAPM2_P.eps,
      ctrl_TAPM2_P.Rho, ctrl_TAPM2_P.eps_c, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Kqr,
      &ctrl_TAPM2_B.sf_CorecontrollerTorquePowera_n);
  }

  /* MultiPortSwitch: '<S64>/Controller chosen' incorporates:
   *  Constant: '<S64>/NaN'
   *  Sum: '<S66>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM2_B.Memory_i) {
   case 1:
    rtb_Row2 = ctrl_TAPM2_B.Kp_i + rtb_Integrator_h;
    break;

   case 2:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePowera_n.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePowera_n.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePowera_n.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_TAPM2_P.NaN_Value_g;
    break;
  }

  /* End of MultiPortSwitch: '<S64>/Controller chosen' */

  /* Sum: '<S64>/Sum' */
  ctrl_TAPM2_B.Sum_hf = (ctrl_TAPM2_B.Inertiacompensation_c +
    ctrl_TAPM2_B.Sum1_i) + rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S37>/Constant'
     *  Constant: '<S37>/Constant1'
     */
    ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_hh = ctrl_TAPM2_B.Sum_hf -
      ctrl_TAPM2_P.Constant_Value_n[1] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_k;
    ctrl_TAPM2_B.DiscreteTransferFcn_n = ctrl_TAPM2_P.Constant1_Value_a[0] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_hh + ctrl_TAPM2_P.Constant1_Value_a
      [1] * ctrl_TAPM2_DW.DiscreteTransferFcn_states_k;
  }

  /* Gain: '<S63>/Finding rotation speed' incorporates:
   *  Gain: '<S63>/K_omega'
   *  Sum: '<S63>/Sum'
   */
  ctrl_TAPM2_B.Findingrotationspeed_m = ((ctrl_TAPM2_B.DiscreteTransferFcn_n -
    ctrl_TAPM2_B.Delay_i) - ctrl_TAPM2_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_TAPM2_B.Integrator_a) * (1.0 / (6.2831853071795862 * ctrl_TAPM2_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Gain: '<S66>/Ki' */
    ctrl_TAPM2_B.Ki_n = ctrl_TAPM2_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S64>/Supervisor' incorporates:
     *  Constant: '<S64>/Switch controller'
     */
    ctrl_TAPM2_Supervisor(ctrl_TAPM2_B.Memory_i, ctrl_TAPM2_P.Thruster_control,
                          rtb_Delay[2], &ctrl_TAPM2_B.sf_Supervisor_l);

    /* Delay: '<S38>/Delay' */
    ctrl_TAPM2_B.Delay_g = ctrl_TAPM2_DW.Delay_DSTATE_e;

    /* Delay: '<S74>/Delay' */
    rtb_Delay_l = ctrl_TAPM2_DW.Delay_DSTATE_i;

    /* MATLAB Function: '<S74>/MATLAB Function' incorporates:
     *  Constant: '<Root>/X-position Thruster1'
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/D'
     *  Constant: '<S3>/Kt'
     *  Constant: '<S3>/Ktr'
     *  Constant: '<S3>/Rho'
     */
    ctrl_TAPM2_MATLABFunction(ctrl_TAPM2_P.XpositionThruster1_Value[6],
      ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Rho, ctrl_TAPM2_P.D,
      ctrl_TAPM2_P.eps_c, rtb_Delay_l, &ctrl_TAPM2_B.sf_MATLABFunction_g);

    /* DiscreteTransferFcn: '<S74>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S74>/Constant1'
     *  Constant: '<S74>/Constant2'
     */
    ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_k =
      (ctrl_TAPM2_B.sf_MATLABFunction_g.n_d - ctrl_TAPM2_P.Constant2_Value_l[1] *
       ctrl_TAPM2_DW.DiscreteTransferFcn_states_i[0]) -
      ctrl_TAPM2_P.Constant2_Value_l[2] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_i[1];
    ctrl_TAPM2_B.DiscreteTransferFcn_l = (ctrl_TAPM2_P.Constant1_Value_m[0] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_k + ctrl_TAPM2_P.Constant1_Value_m[1]
      * ctrl_TAPM2_DW.DiscreteTransferFcn_states_i[0]) +
      ctrl_TAPM2_P.Constant1_Value_m[2] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_i[1];

    /* SampleTimeMath: '<S77>/TSamp'
     *
     * About '<S77>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM2_B.TSamp_a = ctrl_TAPM2_B.DiscreteTransferFcn_l *
      ctrl_TAPM2_P.TSamp_WtEt_h;

    /* Sum: '<S77>/Diff' incorporates:
     *  UnitDelay: '<S77>/UD'
     */
    rtb_Sum_b = ctrl_TAPM2_B.TSamp_a - ctrl_TAPM2_DW.UD_DSTATE_n4;

    /* RateLimiter: '<S74>/Acceleration limiter' */
    rtb_Saturation2 = rtb_Sum_b - ctrl_TAPM2_DW.PrevY_c;
    if (rtb_Saturation2 > ctrl_TAPM2_P.Accelerationlimiter_RisingLim_e) {
      rtb_Sum_b = ctrl_TAPM2_DW.PrevY_c +
        ctrl_TAPM2_P.Accelerationlimiter_RisingLim_e;
    } else {
      if (rtb_Saturation2 < ctrl_TAPM2_P.Accelerationlimiter_FallingLi_b) {
        rtb_Sum_b = ctrl_TAPM2_DW.PrevY_c +
          ctrl_TAPM2_P.Accelerationlimiter_FallingLi_b;
      }
    }

    ctrl_TAPM2_DW.PrevY_c = rtb_Sum_b;

    /* End of RateLimiter: '<S74>/Acceleration limiter' */

    /* Gain: '<S74>/Inertia compensation' */
    ctrl_TAPM2_B.Inertiacompensation_k = ctrl_TAPM2_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S74>/Sum1' incorporates:
     *  Gain: '<S74>/Qf_0'
     *  Gain: '<S74>/Qff_0(nr)'
     *  Gain: '<S74>/Qff_1(nr)'
     *  Trigonometry: '<S74>/Trigonometric Function'
     */
    ctrl_TAPM2_B.Sum1_b = tanh(ctrl_TAPM2_P.epsilon / ctrl_TAPM2_P.n_max *
      ctrl_TAPM2_B.DiscreteTransferFcn_l) * ctrl_TAPM2_P.Q_f0 +
      ctrl_TAPM2_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM2_B.DiscreteTransferFcn_l;

    /* Memory: '<S74>/Memory' */
    ctrl_TAPM2_B.Memory_j = ctrl_TAPM2_DW.Memory_PreviousInput_a;

    /* Sum: '<S76>/Sum' */
    rtb_Sum_b = ctrl_TAPM2_B.DiscreteTransferFcn_l - rtb_Delay[3];

    /* Gain: '<S76>/Kp' */
    ctrl_TAPM2_B.Kp_c = ctrl_TAPM2_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S76>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_h,
                       ctrl_TAPM2_B.reset_n);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM2_X.Integrator_CSTATE_l = ctrl_TAPM2_P.Integrator_IC_g;
    }
  }

  rtb_Integrator_a = ctrl_TAPM2_X.Integrator_CSTATE_l;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* MATLAB Function: '<S76>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
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
    CorecontrollerTorquePowerandCom(ctrl_TAPM2_P.k_cc, ctrl_TAPM2_P.p_cc,
      ctrl_TAPM2_P.r_cc, rtb_Delay[3], ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Kq,
      ctrl_TAPM2_P.D, ctrl_TAPM2_B.sf_MATLABFunction_g.T_r, ctrl_TAPM2_P.eps,
      ctrl_TAPM2_P.Rho, ctrl_TAPM2_P.eps_c, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Kqr,
      &ctrl_TAPM2_B.sf_CorecontrollerTorquePower_n3);
  }

  /* MultiPortSwitch: '<S74>/Controller chosen' incorporates:
   *  Constant: '<S74>/NaN'
   *  Sum: '<S76>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM2_B.Memory_j) {
   case 1:
    rtb_Row2 = ctrl_TAPM2_B.Kp_c + rtb_Integrator_a;
    break;

   case 2:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePower_n3.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePower_n3.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePower_n3.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_TAPM2_P.NaN_Value_p;
    break;
  }

  /* End of MultiPortSwitch: '<S74>/Controller chosen' */

  /* Sum: '<S74>/Sum' */
  ctrl_TAPM2_B.Sum_k = (ctrl_TAPM2_B.Inertiacompensation_k + ctrl_TAPM2_B.Sum1_b)
    + rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S38>/Constant'
     *  Constant: '<S38>/Constant1'
     */
    ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_n = ctrl_TAPM2_B.Sum_k -
      ctrl_TAPM2_P.Constant_Value_j[1] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_h0;
    ctrl_TAPM2_B.DiscreteTransferFcn_b = ctrl_TAPM2_P.Constant1_Value_oi[0] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_n + ctrl_TAPM2_P.Constant1_Value_oi
      [1] * ctrl_TAPM2_DW.DiscreteTransferFcn_states_h0;
  }

  /* Gain: '<S73>/Finding rotation speed' incorporates:
   *  Gain: '<S73>/K_omega'
   *  Sum: '<S73>/Sum'
   */
  ctrl_TAPM2_B.Findingrotationspeed_ms = ((ctrl_TAPM2_B.DiscreteTransferFcn_b -
    ctrl_TAPM2_B.Delay_g) - ctrl_TAPM2_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_TAPM2_B.Integrator_k) * (1.0 / (6.2831853071795862 * ctrl_TAPM2_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Gain: '<S76>/Ki' */
    ctrl_TAPM2_B.Ki_b = ctrl_TAPM2_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S74>/Supervisor' incorporates:
     *  Constant: '<S74>/Switch controller'
     */
    ctrl_TAPM2_Supervisor(ctrl_TAPM2_B.Memory_j, ctrl_TAPM2_P.Thruster_control,
                          rtb_Delay[3], &ctrl_TAPM2_B.sf_Supervisor_n);

    /* Delay: '<S39>/Delay' */
    ctrl_TAPM2_B.Delay_a = ctrl_TAPM2_DW.Delay_DSTATE_j;

    /* Delay: '<S84>/Delay' */
    rtb_Delay_i = ctrl_TAPM2_DW.Delay_DSTATE_a;

    /* MATLAB Function: '<S84>/MATLAB Function' incorporates:
     *  Constant: '<Root>/X-position Thruster1'
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/D'
     *  Constant: '<S3>/Kt'
     *  Constant: '<S3>/Ktr'
     *  Constant: '<S3>/Rho'
     */
    ctrl_TAPM2_MATLABFunction(ctrl_TAPM2_P.XpositionThruster1_Value[8],
      ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Rho, ctrl_TAPM2_P.D,
      ctrl_TAPM2_P.eps_c, rtb_Delay_i, &ctrl_TAPM2_B.sf_MATLABFunction_j);

    /* DiscreteTransferFcn: '<S84>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S84>/Constant1'
     *  Constant: '<S84>/Constant2'
     */
    ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_c =
      (ctrl_TAPM2_B.sf_MATLABFunction_j.n_d - ctrl_TAPM2_P.Constant2_Value_p[1] *
       ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb[0]) -
      ctrl_TAPM2_P.Constant2_Value_p[2] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb[1];
    ctrl_TAPM2_B.DiscreteTransferFcn_o = (ctrl_TAPM2_P.Constant1_Value_mk[0] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_c + ctrl_TAPM2_P.Constant1_Value_mk
      [1] * ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb[0]) +
      ctrl_TAPM2_P.Constant1_Value_mk[2] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb[1];

    /* SampleTimeMath: '<S87>/TSamp'
     *
     * About '<S87>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM2_B.TSamp_m = ctrl_TAPM2_B.DiscreteTransferFcn_o *
      ctrl_TAPM2_P.TSamp_WtEt_o;

    /* Sum: '<S87>/Diff' incorporates:
     *  UnitDelay: '<S87>/UD'
     */
    rtb_Sum_b = ctrl_TAPM2_B.TSamp_m - ctrl_TAPM2_DW.UD_DSTATE_m;

    /* RateLimiter: '<S84>/Acceleration limiter' */
    rtb_Saturation2 = rtb_Sum_b - ctrl_TAPM2_DW.PrevY_j;
    if (rtb_Saturation2 > ctrl_TAPM2_P.Accelerationlimiter_RisingLim_b) {
      rtb_Sum_b = ctrl_TAPM2_DW.PrevY_j +
        ctrl_TAPM2_P.Accelerationlimiter_RisingLim_b;
    } else {
      if (rtb_Saturation2 < ctrl_TAPM2_P.Accelerationlimiter_FallingLi_d) {
        rtb_Sum_b = ctrl_TAPM2_DW.PrevY_j +
          ctrl_TAPM2_P.Accelerationlimiter_FallingLi_d;
      }
    }

    ctrl_TAPM2_DW.PrevY_j = rtb_Sum_b;

    /* End of RateLimiter: '<S84>/Acceleration limiter' */

    /* Gain: '<S84>/Inertia compensation' */
    ctrl_TAPM2_B.Inertiacompensation_f = ctrl_TAPM2_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S84>/Sum1' incorporates:
     *  Gain: '<S84>/Qf_0'
     *  Gain: '<S84>/Qff_0(nr)'
     *  Gain: '<S84>/Qff_1(nr)'
     *  Trigonometry: '<S84>/Trigonometric Function'
     */
    ctrl_TAPM2_B.Sum1_o = tanh(ctrl_TAPM2_P.epsilon / ctrl_TAPM2_P.n_max *
      ctrl_TAPM2_B.DiscreteTransferFcn_o) * ctrl_TAPM2_P.Q_f0 +
      ctrl_TAPM2_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM2_B.DiscreteTransferFcn_o;

    /* Memory: '<S84>/Memory' */
    ctrl_TAPM2_B.Memory_d = ctrl_TAPM2_DW.Memory_PreviousInput_b;

    /* Sum: '<S86>/Sum' */
    rtb_Sum_b = ctrl_TAPM2_B.DiscreteTransferFcn_o - rtb_Delay[4];

    /* Gain: '<S86>/Kp' */
    ctrl_TAPM2_B.Kp_j = ctrl_TAPM2_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S86>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_f,
                       ctrl_TAPM2_B.reset_f);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM2_X.Integrator_CSTATE_n4 = ctrl_TAPM2_P.Integrator_IC_aj;
    }
  }

  rtb_Integrator_i = ctrl_TAPM2_X.Integrator_CSTATE_n4;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* MATLAB Function: '<S86>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
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
    CorecontrollerTorquePowerandCom(ctrl_TAPM2_P.k_cc, ctrl_TAPM2_P.p_cc,
      ctrl_TAPM2_P.r_cc, rtb_Delay[4], ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Kq,
      ctrl_TAPM2_P.D, ctrl_TAPM2_B.sf_MATLABFunction_j.T_r, ctrl_TAPM2_P.eps,
      ctrl_TAPM2_P.Rho, ctrl_TAPM2_P.eps_c, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Kqr,
      &ctrl_TAPM2_B.sf_CorecontrollerTorquePowera_h);
  }

  /* MultiPortSwitch: '<S84>/Controller chosen' incorporates:
   *  Constant: '<S84>/NaN'
   *  Sum: '<S86>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM2_B.Memory_d) {
   case 1:
    rtb_Row2 = ctrl_TAPM2_B.Kp_j + rtb_Integrator_i;
    break;

   case 2:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePowera_h.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePowera_h.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePowera_h.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_TAPM2_P.NaN_Value_lq;
    break;
  }

  /* End of MultiPortSwitch: '<S84>/Controller chosen' */

  /* Sum: '<S84>/Sum' */
  ctrl_TAPM2_B.Sum_i = (ctrl_TAPM2_B.Inertiacompensation_f + ctrl_TAPM2_B.Sum1_o)
    + rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* DiscreteTransferFcn: '<S39>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S39>/Constant'
     *  Constant: '<S39>/Constant1'
     */
    ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_f = ctrl_TAPM2_B.Sum_i -
      ctrl_TAPM2_P.Constant_Value_i[1] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_dt;
    ctrl_TAPM2_B.DiscreteTransferFcn_lz = ctrl_TAPM2_P.Constant1_Value_h[0] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_f + ctrl_TAPM2_P.Constant1_Value_h[1]
      * ctrl_TAPM2_DW.DiscreteTransferFcn_states_dt;
  }

  /* Gain: '<S83>/Finding rotation speed' incorporates:
   *  Gain: '<S83>/K_omega'
   *  Sum: '<S83>/Sum'
   */
  ctrl_TAPM2_B.Findingrotationspeed_ag = ((ctrl_TAPM2_B.DiscreteTransferFcn_lz -
    ctrl_TAPM2_B.Delay_a) - ctrl_TAPM2_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_TAPM2_B.Integrator_c) * (1.0 / (6.2831853071795862 * ctrl_TAPM2_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Gain: '<S86>/Ki' */
    ctrl_TAPM2_B.Ki_a = ctrl_TAPM2_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S84>/Supervisor' incorporates:
     *  Constant: '<S84>/Switch controller'
     */
    ctrl_TAPM2_Supervisor(ctrl_TAPM2_B.Memory_d, ctrl_TAPM2_P.Thruster_control,
                          rtb_Delay[4], &ctrl_TAPM2_B.sf_Supervisor_b);

    /* Delay: '<S40>/Delay' */
    ctrl_TAPM2_B.Delay_h = ctrl_TAPM2_DW.Delay_DSTATE_dv;

    /* MATLAB Function: '<S94>/MATLAB Function' incorporates:
     *  Constant: '<Root>/X-position Thruster1'
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/D'
     *  Constant: '<S3>/Kt'
     *  Constant: '<S3>/Ktr'
     *  Constant: '<S3>/Rho'
     *  Delay: '<S94>/Delay'
     */
    /* MATLAB Function 'Thruster control /Thruster 6/Thruster control/MATLAB Function': '<S98>:1' */
    /* '<S98>:1:5' */
    if (ctrl_TAPM2_P.XpositionThruster1_Value[10] < 0.0) {
      rtb_output_idx_4 = -1.0;
    } else if (ctrl_TAPM2_P.XpositionThruster1_Value[10] > 0.0) {
      rtb_output_idx_4 = 1.0;
    } else if (ctrl_TAPM2_P.XpositionThruster1_Value[10] == 0.0) {
      rtb_output_idx_4 = 0.0;
    } else {
      rtb_output_idx_4 = ctrl_TAPM2_P.XpositionThruster1_Value[10];
    }

    absxk = sqrt(fabs(ctrl_TAPM2_P.XpositionThruster1_Value[10]) /
                 (ctrl_TAPM2_P.Rho * rt_powd_snf(ctrl_TAPM2_P.D, 4.0) *
                  ctrl_TAPM2_P.Kt)) * rtb_output_idx_4;

    /* '<S98>:1:7' */
    rtb_Saturation2 = tanh(ctrl_TAPM2_P.eps_c * absxk / 27.0) * 0.5 + 0.5;

    /*  Smooth switching between positive and negative thrust */
    /* '<S98>:1:8' */
    /* '<S98>:1:10' */
    if (ctrl_TAPM2_DW.Delay_DSTATE_m < 0.0) {
      rtb_output_idx_4 = -1.0;
    } else if (ctrl_TAPM2_DW.Delay_DSTATE_m > 0.0) {
      rtb_output_idx_4 = 1.0;
    } else if (ctrl_TAPM2_DW.Delay_DSTATE_m == 0.0) {
      rtb_output_idx_4 = 0.0;
    } else {
      rtb_output_idx_4 = ctrl_TAPM2_DW.Delay_DSTATE_m;
    }

    rtb_T_r = ((1.0 - rtb_Saturation2) * ctrl_TAPM2_P.Ktr + ctrl_TAPM2_P.Kt *
               rtb_Saturation2) * rtb_output_idx_4 * ctrl_TAPM2_P.Rho *
      rt_powd_snf(ctrl_TAPM2_P.D, 4.0) * (ctrl_TAPM2_DW.Delay_DSTATE_m *
      ctrl_TAPM2_DW.Delay_DSTATE_m);

    /* DiscreteTransferFcn: '<S94>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S94>/Constant1'
     *  Constant: '<S94>/Constant2'
     *  MATLAB Function: '<S94>/MATLAB Function'
     */
    ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_h4 = (absxk -
      ctrl_TAPM2_P.Constant2_Value_p3[1] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_l[0]) -
      ctrl_TAPM2_P.Constant2_Value_p3[2] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_l[1];
    ctrl_TAPM2_B.DiscreteTransferFcn_j = (ctrl_TAPM2_P.Constant1_Value_oa[0] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_h4 +
      ctrl_TAPM2_P.Constant1_Value_oa[1] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_l[0]) +
      ctrl_TAPM2_P.Constant1_Value_oa[2] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_l[1];

    /* SampleTimeMath: '<S97>/TSamp'
     *
     * About '<S97>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    ctrl_TAPM2_B.TSamp_o = ctrl_TAPM2_B.DiscreteTransferFcn_j *
      ctrl_TAPM2_P.TSamp_WtEt_kk;

    /* Sum: '<S97>/Diff' incorporates:
     *  UnitDelay: '<S97>/UD'
     */
    rtb_Sum_b = ctrl_TAPM2_B.TSamp_o - ctrl_TAPM2_DW.UD_DSTATE_l;

    /* RateLimiter: '<S94>/Acceleration limiter' */
    rtb_Saturation2 = rtb_Sum_b - ctrl_TAPM2_DW.PrevY_h;
    if (rtb_Saturation2 > ctrl_TAPM2_P.Accelerationlimiter_RisingLi_bi) {
      rtb_Sum_b = ctrl_TAPM2_DW.PrevY_h +
        ctrl_TAPM2_P.Accelerationlimiter_RisingLi_bi;
    } else {
      if (rtb_Saturation2 < ctrl_TAPM2_P.Accelerationlimiter_FallingLi_p) {
        rtb_Sum_b = ctrl_TAPM2_DW.PrevY_h +
          ctrl_TAPM2_P.Accelerationlimiter_FallingLi_p;
      }
    }

    ctrl_TAPM2_DW.PrevY_h = rtb_Sum_b;

    /* End of RateLimiter: '<S94>/Acceleration limiter' */

    /* Gain: '<S94>/Inertia compensation' */
    ctrl_TAPM2_B.Inertiacompensation_e3 = ctrl_TAPM2_P.I_s * 2.0 *
      3.1415926535897931 * rtb_Sum_b;

    /* Sum: '<S94>/Sum1' incorporates:
     *  Gain: '<S94>/Qf_0'
     *  Gain: '<S94>/Qff_0(nr)'
     *  Gain: '<S94>/Qff_1(nr)'
     *  Trigonometry: '<S94>/Trigonometric Function'
     */
    ctrl_TAPM2_B.Sum1_io = tanh(ctrl_TAPM2_P.epsilon / ctrl_TAPM2_P.n_max *
      ctrl_TAPM2_B.DiscreteTransferFcn_j) * ctrl_TAPM2_P.Q_f0 +
      ctrl_TAPM2_P.K_omega * 2.0 * 3.1415926535897931 *
      ctrl_TAPM2_B.DiscreteTransferFcn_j;

    /* Memory: '<S94>/Memory' */
    ctrl_TAPM2_B.Memory_o = ctrl_TAPM2_DW.Memory_PreviousInput_a4;

    /* Sum: '<S96>/Sum' */
    rtb_Sum_b = ctrl_TAPM2_B.DiscreteTransferFcn_j - rtb_Delay[5];

    /* Gain: '<S96>/Kp' */
    ctrl_TAPM2_B.Kp_l = ctrl_TAPM2_P.Kp * rtb_Sum_b;
  }

  /* Integrator: '<S96>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_i3,
                       ctrl_TAPM2_B.reset_o);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_TAPM2_X.Integrator_CSTATE_gj = ctrl_TAPM2_P.Integrator_IC_h;
    }
  }

  rtb_Integrator_l = ctrl_TAPM2_X.Integrator_CSTATE_gj;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* MATLAB Function: '<S96>/Core controller: Torque,Power and Combined Torque//Power' incorporates:
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
    CorecontrollerTorquePowerandCom(ctrl_TAPM2_P.k_cc, ctrl_TAPM2_P.p_cc,
      ctrl_TAPM2_P.r_cc, rtb_Delay[5], ctrl_TAPM2_P.Kt, ctrl_TAPM2_P.Kq,
      ctrl_TAPM2_P.D, rtb_T_r, ctrl_TAPM2_P.eps, ctrl_TAPM2_P.Rho,
      ctrl_TAPM2_P.eps_c, ctrl_TAPM2_P.Ktr, ctrl_TAPM2_P.Kqr,
      &ctrl_TAPM2_B.sf_CorecontrollerTorquePower_nf);
  }

  /* MultiPortSwitch: '<S94>/Controller chosen' incorporates:
   *  Constant: '<S94>/NaN'
   *  Sum: '<S96>/Sum1'
   */
  switch ((int32_T)ctrl_TAPM2_B.Memory_o) {
   case 1:
    rtb_Row2 = ctrl_TAPM2_B.Kp_l + rtb_Integrator_l;
    break;

   case 2:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePower_nf.Qcq;
    break;

   case 3:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePower_nf.Qcp;
    break;

   case 4:
    rtb_Row2 = ctrl_TAPM2_B.sf_CorecontrollerTorquePower_nf.Qcc;
    break;

   default:
    rtb_Row2 = ctrl_TAPM2_P.NaN_Value_j;
    break;
  }

  /* End of MultiPortSwitch: '<S94>/Controller chosen' */

  /* Sum: '<S94>/Sum' */
  ctrl_TAPM2_B.Sum_f = (ctrl_TAPM2_B.Inertiacompensation_e3 +
                        ctrl_TAPM2_B.Sum1_io) + rtb_Row2;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* DiscreteTransferFcn: '<S40>/Discrete Transfer Fcn' incorporates:
     *  Constant: '<S40>/Constant'
     *  Constant: '<S40>/Constant1'
     */
    ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_cw = ctrl_TAPM2_B.Sum_f -
      ctrl_TAPM2_P.Constant_Value_ht[1] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_o;
    ctrl_TAPM2_B.DiscreteTransferFcn_ea = ctrl_TAPM2_P.Constant1_Value_gs[0] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_cw +
      ctrl_TAPM2_P.Constant1_Value_gs[1] *
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_o;
  }

  /* Gain: '<S93>/Finding rotation speed' incorporates:
   *  Gain: '<S93>/K_omega'
   *  Sum: '<S93>/Sum'
   */
  ctrl_TAPM2_B.Findingrotationspeed_c = ((ctrl_TAPM2_B.DiscreteTransferFcn_ea -
    ctrl_TAPM2_B.Delay_h) - ctrl_TAPM2_P.K_omega * 2.0 * 3.1415926535897931 *
    ctrl_TAPM2_B.Integrator_m) * (1.0 / (6.2831853071795862 * ctrl_TAPM2_P.I_s));
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Gain: '<S96>/Ki' */
    ctrl_TAPM2_B.Ki_p = ctrl_TAPM2_P.Kp / 0.05 * rtb_Sum_b;

    /* MATLAB Function: '<S94>/Supervisor' incorporates:
     *  Constant: '<S94>/Switch controller'
     */
    ctrl_TAPM2_Supervisor(ctrl_TAPM2_B.Memory_o, ctrl_TAPM2_P.Thruster_control,
                          rtb_Delay[5], &ctrl_TAPM2_B.sf_Supervisor_e);

    /* SignalConversion: '<S8>/TmpSignal ConversionAtDelayInport1' */
    ctrl_TAPM2_B.TmpSignalConversionAtDelayInpor[0] = ctrl_TAPM2_B.Integrator;
    ctrl_TAPM2_B.TmpSignalConversionAtDelayInpor[1] = ctrl_TAPM2_B.Integrator_h;
    ctrl_TAPM2_B.TmpSignalConversionAtDelayInpor[2] = ctrl_TAPM2_B.Integrator_a;
    ctrl_TAPM2_B.TmpSignalConversionAtDelayInpor[3] = ctrl_TAPM2_B.Integrator_k;
    ctrl_TAPM2_B.TmpSignalConversionAtDelayInpor[4] = ctrl_TAPM2_B.Integrator_c;
    ctrl_TAPM2_B.TmpSignalConversionAtDelayInpor[5] = ctrl_TAPM2_B.Integrator_m;
  }

  /* Integrator: '<S12>/Integrator' */
  ctrl_TAPM2_B.eta[0] = ctrl_TAPM2_X.Integrator_CSTATE_c5[0];
  ctrl_TAPM2_B.eta[1] = ctrl_TAPM2_X.Integrator_CSTATE_c5[1];
  ctrl_TAPM2_B.eta[2] = ctrl_TAPM2_X.Integrator_CSTATE_c5[2];

  /* Integrator: '<S12>/Integrator4' */
  ctrl_TAPM2_B.nu[0] = ctrl_TAPM2_X.Integrator4_CSTATE[0];
  ctrl_TAPM2_B.nu[1] = ctrl_TAPM2_X.Integrator4_CSTATE[1];
  ctrl_TAPM2_B.nu[2] = ctrl_TAPM2_X.Integrator4_CSTATE[2];

  /* MATLAB Function: '<S13>/Set-Point Limiter' incorporates:
   *  Integrator: '<S13>/Integrator'
   *  MATLAB Function: '<S1>/MATLAB Function3'
   *  SignalConversion: '<S10>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Input/MATLAB Function3': '<S10>:1' */
  /* '<S10>:1:4' */
  /* MATLAB Function 'TAPM Controller w_observer/SP Generator/Set-Point Limiter': '<S25>:1' */
  /* '<S25>:1:3' */
  rtb_output_idx_2 = ctrl_TAPM2_X.Integrator_CSTATE_l0[0] - ctrl_TAPM2_B.fzp_x;
  rtb_output_idx_4 = ctrl_TAPM2_X.Integrator_CSTATE_l0[1] - ctrl_TAPM2_B.fzp_y;

  /* '<S25>:1:4' */
  rtb_Saturation2 = 2.2250738585072014E-308;
  absxk = fabs(rtb_output_idx_2);
  if (absxk > 2.2250738585072014E-308) {
    offset = 1.0;
    rtb_Saturation2 = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    offset = t * t;
  }

  absxk = fabs(rtb_output_idx_4);
  if (absxk > rtb_Saturation2) {
    t = rtb_Saturation2 / absxk;
    offset = offset * t * t + 1.0;
    rtb_Saturation2 = absxk;
  } else {
    t = absxk / rtb_Saturation2;
    offset += t * t;
  }

  offset = rtb_Saturation2 * sqrt(offset);

  /* '<S25>:1:5' */
  /* '<S25>:1:6' */
  /* '<S25>:1:7' */
  rtb_Saturation2 = rt_powd_snf(offset / ctrl_TAPM2_B.r_max, 5.0);
  if (rtb_Saturation2 > 1.0) {
    /* '<S25>:1:10' */
    /* '<S25>:1:11' */
    rtb_Saturation2 = 1.0;
  }

  /* '<S25>:1:14' */
  rtb_output_idx_2 = (ctrl_TAPM2_B.fzp_x + rtb_output_idx_2) - (rtb_output_idx_2
    - rtb_output_idx_2 / offset * ctrl_TAPM2_B.r_max) * rtb_Saturation2;
  rtb_output_idx_0 = (ctrl_TAPM2_B.fzp_y + rtb_output_idx_4) - (rtb_output_idx_4
    - rtb_output_idx_4 / offset * ctrl_TAPM2_B.r_max) * rtb_Saturation2;

  /* End of MATLAB Function: '<S13>/Set-Point Limiter' */

  /* TransferFcn: '<S13>/Transfer Fcn2' */
  rtb_Row2 = ctrl_TAPM2_P.TransferFcn2_C * ctrl_TAPM2_X.TransferFcn2_CSTATE;

  /* Saturate: '<S14>/Saturation' */
  if (rtb_Row2 > ctrl_TAPM2_P.Saturation_UpperSat) {
    rtb_Row2 = ctrl_TAPM2_P.Saturation_UpperSat;
  } else {
    if (rtb_Row2 < ctrl_TAPM2_P.Saturation_LowerSat) {
      rtb_Row2 = ctrl_TAPM2_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* Signum: '<S14>/Sign' */
  if (rtb_Row2 < 0.0) {
    rtb_output_idx_4 = -1.0;
  } else if (rtb_Row2 > 0.0) {
    rtb_output_idx_4 = 1.0;
  } else if (rtb_Row2 == 0.0) {
    rtb_output_idx_4 = 0.0;
  } else {
    rtb_output_idx_4 = rtb_Row2;
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  Signum: '<S14>/Sign'
   */
  rtb_Saturation2 = ctrl_TAPM2_P.Gain_Gain_p * rtb_output_idx_4;

  /* Sum: '<S14>/Sum1' */
  rtb_Row2 += rtb_Saturation2;

  /* Math: '<S14>/Math Function' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Row2 = rt_remd_snf(rtb_Row2, ctrl_TAPM2_P.Constant_Value_k);

  /* Sum: '<S14>/Sum' */
  rtb_Row2 -= rtb_Saturation2;

  /* SignalConversion: '<S6>/TmpSignal ConversionAtSPInport1' */
  ctrl_TAPM2_B.TmpSignalConversionAtSPInport1[0] = rtb_output_idx_2;
  ctrl_TAPM2_B.TmpSignalConversionAtSPInport1[1] = rtb_output_idx_0;
  ctrl_TAPM2_B.TmpSignalConversionAtSPInport1[2] = rtb_Row2;

  /* Sum: '<S12>/Sum2' incorporates:
   *  Integrator: '<S12>/Integrator1'
   *  Sum: '<S12>/Sum4'
   */
  rtb_output_idx_4 = ctrl_TAPM2_B.x_m - (ctrl_TAPM2_X.Integrator1_CSTATE[0] +
    ctrl_TAPM2_B.eta[0]);
  rtb_output_idx_0 = ctrl_TAPM2_B.y_m - (ctrl_TAPM2_X.Integrator1_CSTATE[1] +
    ctrl_TAPM2_B.eta[1]);
  rtb_output_idx_2 = ctrl_TAPM2_B.psi_m - (ctrl_TAPM2_X.Integrator1_CSTATE[2] +
    ctrl_TAPM2_B.eta[2]);

  /* Gain: '<S12>/K4' */
  for (i = 0; i < 3; i++) {
    rtb_bias[i] = ctrl_TAPM2_P.Nonlinearpassiveobserver_K4[i + 6] *
      rtb_output_idx_2 + (ctrl_TAPM2_P.Nonlinearpassiveobserver_K4[i + 3] *
                          rtb_output_idx_0 +
                          ctrl_TAPM2_P.Nonlinearpassiveobserver_K4[i] *
                          rtb_output_idx_4);
  }

  /* End of Gain: '<S12>/K4' */

  /* Sum: '<S12>/Sum1' incorporates:
   *  Fcn: '<S24>/Row1'
   *  Fcn: '<S24>/Row2'
   *  Fcn: '<S24>/Row3'
   *  Integrator: '<S12>/Integrator3'
   */
  tmp[0] = cos(ctrl_TAPM2_B.psi_m) * ctrl_TAPM2_X.Integrator3_CSTATE[0] + sin
    (ctrl_TAPM2_B.psi_m) * ctrl_TAPM2_X.Integrator3_CSTATE[1];
  tmp[1] = -sin(ctrl_TAPM2_B.psi_m) * ctrl_TAPM2_X.Integrator3_CSTATE[0] + cos
    (ctrl_TAPM2_B.psi_m) * ctrl_TAPM2_X.Integrator3_CSTATE[1];
  tmp[2] = ctrl_TAPM2_X.Integrator3_CSTATE[2];

  /* Sum: '<S12>/Sum8' incorporates:
   *  Fcn: '<S23>/Row1'
   *  Fcn: '<S23>/Row2'
   *  Fcn: '<S23>/Row3'
   *  Gain: '<S12>/Gain3'
   *  Gain: '<S12>/Gain6'
   *  Sum: '<S12>/Sum1'
   */
  tmp_0[0] = cos(ctrl_TAPM2_B.psi_m) * rtb_bias[0] + sin(ctrl_TAPM2_B.psi_m) *
    rtb_bias[1];
  tmp_0[1] = -sin(ctrl_TAPM2_B.psi_m) * rtb_bias[0] + cos(ctrl_TAPM2_B.psi_m) *
    rtb_bias[1];
  tmp_0[2] = rtb_bias[2];
  for (i = 0; i < 3; i++) {
    rtb_bias[i] = ((tmp[i] + ctrl_TAPM2_B.actual_tau[i]) + tmp_0[i]) -
      ((ctrl_TAPM2_P.Nonlinearpassiveobserver_D[i + 3] * ctrl_TAPM2_B.nu[1] +
        ctrl_TAPM2_P.Nonlinearpassiveobserver_D[i] * ctrl_TAPM2_B.nu[0]) +
       ctrl_TAPM2_P.Nonlinearpassiveobserver_D[i + 6] * ctrl_TAPM2_B.nu[2]);
  }

  /* End of Sum: '<S12>/Sum8' */

  /* Gain: '<S12>/Gain3' */
  for (i = 0; i < 3; i++) {
    ctrl_TAPM2_B.Gain3[i] = 0.0;
    ctrl_TAPM2_B.Gain3[i] += ctrl_TAPM2_P.Gain3_Gain[i] * rtb_bias[0];
    ctrl_TAPM2_B.Gain3[i] += ctrl_TAPM2_P.Gain3_Gain[i + 3] * rtb_bias[1];
    ctrl_TAPM2_B.Gain3[i] += ctrl_TAPM2_P.Gain3_Gain[i + 6] * rtb_bias[2];
  }

  /* Sum: '<S12>/Sum3' incorporates:
   *  Fcn: '<S22>/Fcn'
   *  Fcn: '<S22>/Fcn1'
   *  Fcn: '<S22>/Fcn2'
   *  Gain: '<S12>/K2'
   */
  tmp_1[0] = cos(ctrl_TAPM2_B.psi_m) * ctrl_TAPM2_B.nu[0] - sin
    (ctrl_TAPM2_B.psi_m) * ctrl_TAPM2_B.nu[1];
  tmp_1[1] = sin(ctrl_TAPM2_B.psi_m) * ctrl_TAPM2_B.nu[0] + cos
    (ctrl_TAPM2_B.psi_m) * ctrl_TAPM2_B.nu[1];
  tmp_1[2] = ctrl_TAPM2_B.nu[2];
  for (i = 0; i < 3; i++) {
    ctrl_TAPM2_B.Sum3[i] = ((ctrl_TAPM2_P.Nonlinearpassiveobserver_w_c[i + 3] *
      rtb_output_idx_0 + ctrl_TAPM2_P.Nonlinearpassiveobserver_w_c[i] *
      rtb_output_idx_4) + ctrl_TAPM2_P.Nonlinearpassiveobserver_w_c[i + 6] *
      rtb_output_idx_2) + tmp_1[i];
  }

  /* End of Sum: '<S12>/Sum3' */

  /* Sum: '<S12>/Sum5' incorporates:
   *  Gain: '<S12>/K11'
   *  Integrator: '<S12>/Integrator1'
   */
  for (i = 0; i < 3; i++) {
    ctrl_TAPM2_B.psi_WF[i] = ((ctrl_TAPM2_P.K11_Gain[i + 3] * rtb_output_idx_0 +
      ctrl_TAPM2_P.K11_Gain[i] * rtb_output_idx_4) + ctrl_TAPM2_P.K11_Gain[i + 6]
      * rtb_output_idx_2) + ctrl_TAPM2_X.Integrator1_CSTATE[i];
  }

  /* End of Sum: '<S12>/Sum5' */

  /* Gain: '<S12>/K12' incorporates:
   *  Sum: '<S12>/Sum6'
   */
  for (i = 0; i < 3; i++) {
    tmp[i] = ctrl_TAPM2_P.K12_Gain[i + 6] * rtb_output_idx_2 +
      (ctrl_TAPM2_P.K12_Gain[i + 3] * rtb_output_idx_0 + ctrl_TAPM2_P.K12_Gain[i]
       * rtb_output_idx_4);
  }

  /* End of Gain: '<S12>/K12' */

  /* Gain: '<S12>/Gain2' incorporates:
   *  Integrator: '<S12>/Integrator2'
   *  Sum: '<S12>/Sum6'
   */
  for (i = 0; i < 3; i++) {
    tmp_0[i] = ctrl_TAPM2_P.Gain2_Gain[i + 6] * ctrl_TAPM2_X.Integrator2_CSTATE
      [2] + (ctrl_TAPM2_P.Gain2_Gain[i + 3] * ctrl_TAPM2_X.Integrator2_CSTATE[1]
             + ctrl_TAPM2_P.Gain2_Gain[i] * ctrl_TAPM2_X.Integrator2_CSTATE[0]);
  }

  /* End of Gain: '<S12>/Gain2' */

  /* Sum: '<S12>/Sum6' incorporates:
   *  Gain: '<S12>/Gain1'
   *  Integrator: '<S12>/Integrator1'
   */
  for (i = 0; i < 3; i++) {
    ctrl_TAPM2_B.Sum6[i] = (tmp[i] - tmp_0[i]) - ((ctrl_TAPM2_P.Gain1_Gain[i + 3]
      * ctrl_TAPM2_X.Integrator1_CSTATE[1] + ctrl_TAPM2_P.Gain1_Gain[i] *
      ctrl_TAPM2_X.Integrator1_CSTATE[0]) + ctrl_TAPM2_P.Gain1_Gain[i + 6] *
      ctrl_TAPM2_X.Integrator1_CSTATE[2]);
  }

  /* Gain: '<S12>/inv(T_b)' incorporates:
   *  Integrator: '<S12>/Integrator3'
   *  Sum: '<S12>/Sum7'
   */
  for (i = 0; i < 3; i++) {
    tmp[i] = ctrl_TAPM2_P.invT_b_Gain[i + 6] * ctrl_TAPM2_X.Integrator3_CSTATE[2]
      + (ctrl_TAPM2_P.invT_b_Gain[i + 3] * ctrl_TAPM2_X.Integrator3_CSTATE[1] +
         ctrl_TAPM2_P.invT_b_Gain[i] * ctrl_TAPM2_X.Integrator3_CSTATE[0]);
  }

  /* End of Gain: '<S12>/inv(T_b)' */

  /* Sum: '<S12>/Sum7' incorporates:
   *  Gain: '<S12>/K3'
   */
  for (i = 0; i < 3; i++) {
    ctrl_TAPM2_B.Sum7[i] = ((ctrl_TAPM2_P.Nonlinearpassiveobserver_K3[i + 3] *
      rtb_output_idx_0 + ctrl_TAPM2_P.Nonlinearpassiveobserver_K3[i] *
      rtb_output_idx_4) + ctrl_TAPM2_P.Nonlinearpassiveobserver_K3[i + 6] *
      rtb_output_idx_2) - tmp[i];
  }

  /* Sum: '<S13>/Sum' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Gain: '<S1>/deg2rad'
   */
  ctrl_TAPM2_B.Sum_j = ctrl_TAPM2_P.deg2rad_Gain * ctrl_TAPM2_B.wave_dir +
    ctrl_TAPM2_P.Constant1_Value_p;

  /* Sum: '<S13>/Sum1' incorporates:
   *  Gain: '<S13>/Gain'
   *  Gain: '<S13>/Gain1'
   *  Integrator: '<S13>/Integrator'
   */
  ctrl_TAPM2_B.Sum1_bn[0] = (ctrl_TAPM2_P.Gain1_Gain_i[0] * ctrl_TAPM2_B.eta[0]
    + ctrl_TAPM2_P.Gain1_Gain_i[2] * ctrl_TAPM2_B.eta[1]) -
    (ctrl_TAPM2_P.Gain_Gain_d[0] * ctrl_TAPM2_X.Integrator_CSTATE_l0[0] +
     ctrl_TAPM2_P.Gain_Gain_d[2] * ctrl_TAPM2_X.Integrator_CSTATE_l0[1]);
  ctrl_TAPM2_B.Sum1_bn[1] = (ctrl_TAPM2_P.Gain1_Gain_i[1] * ctrl_TAPM2_B.eta[0]
    + ctrl_TAPM2_P.Gain1_Gain_i[3] * ctrl_TAPM2_B.eta[1]) -
    (ctrl_TAPM2_P.Gain_Gain_d[1] * ctrl_TAPM2_X.Integrator_CSTATE_l0[0] +
     ctrl_TAPM2_P.Gain_Gain_d[3] * ctrl_TAPM2_X.Integrator_CSTATE_l0[1]);
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Gain: '<S6>/Gain' incorporates:
     *  Constant: '<S6>/Constant'
     */
    ctrl_TAPM2_B.Gain_d[0] = ctrl_TAPM2_P.Gain_Gain_l[0] *
      ctrl_TAPM2_P.Constant_Value_hs[0];
    ctrl_TAPM2_B.Gain_d[1] = ctrl_TAPM2_P.Gain_Gain_l[1] *
      ctrl_TAPM2_P.Constant_Value_hs[1];
    ctrl_TAPM2_B.Gain_d[2] = ctrl_TAPM2_P.Gain_Gain_l[2] *
      ctrl_TAPM2_P.Constant_Value_hs[2];
  }
}

/* Model update function */
void ctrl_TAPM2_update(void)
{
  int32_T i;
  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Update for Delay: '<S8>/Delay' */
    for (i = 0; i < 6; i++) {
      ctrl_TAPM2_DW.Delay_DSTATE[i] =
        ctrl_TAPM2_B.TmpSignalConversionAtDelayInpor[i];
    }

    /* End of Update for Delay: '<S8>/Delay' */

    /* Update for Delay: '<S35>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_f = ctrl_TAPM2_B.sf_ActualForceandTorque.Qa;

    /* Update for Delay: '<S44>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_fu = ctrl_TAPM2_B.DiscreteTransferFcn;

    /* Update for DiscreteTransferFcn: '<S44>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states[1] =
      ctrl_TAPM2_DW.DiscreteTransferFcn_states[0];
    ctrl_TAPM2_DW.DiscreteTransferFcn_states[0] =
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp;

    /* Update for UnitDelay: '<S47>/UD' */
    ctrl_TAPM2_DW.UD_DSTATE = ctrl_TAPM2_B.TSamp;

    /* Update for Memory: '<S44>/Memory' */
    ctrl_TAPM2_DW.Memory_PreviousInput = ctrl_TAPM2_B.sf_Supervisor.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Update for DiscreteTransferFcn: '<S35>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_d =
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_a;

    /* Update for Delay: '<S36>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_b = ctrl_TAPM2_B.sf_ActualForceandTorque_f.Qa;

    /* Update for Delay: '<S54>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_d = ctrl_TAPM2_B.DiscreteTransferFcn_e;

    /* Update for DiscreteTransferFcn: '<S54>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_h[1] =
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_h[0];
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_h[0] =
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_d;

    /* Update for UnitDelay: '<S57>/UD' */
    ctrl_TAPM2_DW.UD_DSTATE_n = ctrl_TAPM2_B.TSamp_n;

    /* Update for Memory: '<S54>/Memory' */
    ctrl_TAPM2_DW.Memory_PreviousInput_n = ctrl_TAPM2_B.sf_Supervisor_h.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Update for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_m =
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_h;

    /* Update for Delay: '<S37>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_n = ctrl_TAPM2_B.sf_ActualForceandTorque_h.Qa;

    /* Update for Delay: '<S64>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_no = ctrl_TAPM2_B.DiscreteTransferFcn_f;

    /* Update for DiscreteTransferFcn: '<S64>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_j[1] =
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_j[0];
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_j[0] =
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_e;

    /* Update for UnitDelay: '<S67>/UD' */
    ctrl_TAPM2_DW.UD_DSTATE_i = ctrl_TAPM2_B.TSamp_k;

    /* Update for Memory: '<S64>/Memory' */
    ctrl_TAPM2_DW.Memory_PreviousInput_d = ctrl_TAPM2_B.sf_Supervisor_l.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Update for DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_k =
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_hh;

    /* Update for Delay: '<S38>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_e = ctrl_TAPM2_B.sf_ActualForceandTorque_m.Qa;

    /* Update for Delay: '<S74>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_i = ctrl_TAPM2_B.DiscreteTransferFcn_l;

    /* Update for DiscreteTransferFcn: '<S74>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_i[1] =
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_i[0];
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_i[0] =
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_k;

    /* Update for UnitDelay: '<S77>/UD' */
    ctrl_TAPM2_DW.UD_DSTATE_n4 = ctrl_TAPM2_B.TSamp_a;

    /* Update for Memory: '<S74>/Memory' */
    ctrl_TAPM2_DW.Memory_PreviousInput_a = ctrl_TAPM2_B.sf_Supervisor_n.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Update for DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_h0 =
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_n;

    /* Update for Delay: '<S39>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_j = ctrl_TAPM2_B.sf_ActualForceandTorque_o.Qa;

    /* Update for Delay: '<S84>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_a = ctrl_TAPM2_B.DiscreteTransferFcn_o;

    /* Update for DiscreteTransferFcn: '<S84>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb[1] =
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb[0];
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb[0] =
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_c;

    /* Update for UnitDelay: '<S87>/UD' */
    ctrl_TAPM2_DW.UD_DSTATE_m = ctrl_TAPM2_B.TSamp_m;

    /* Update for Memory: '<S84>/Memory' */
    ctrl_TAPM2_DW.Memory_PreviousInput_b = ctrl_TAPM2_B.sf_Supervisor_b.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Update for DiscreteTransferFcn: '<S39>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_dt =
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_f;

    /* Update for Delay: '<S40>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_dv = ctrl_TAPM2_B.sf_ActualForceandTorque_j.Qa;

    /* Update for Delay: '<S94>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_m = ctrl_TAPM2_B.DiscreteTransferFcn_j;

    /* Update for DiscreteTransferFcn: '<S94>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_l[1] =
      ctrl_TAPM2_DW.DiscreteTransferFcn_states_l[0];
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_l[0] =
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_h4;

    /* Update for UnitDelay: '<S97>/UD' */
    ctrl_TAPM2_DW.UD_DSTATE_l = ctrl_TAPM2_B.TSamp_o;

    /* Update for Memory: '<S94>/Memory' */
    ctrl_TAPM2_DW.Memory_PreviousInput_a4 = ctrl_TAPM2_B.sf_Supervisor_e.u;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    /* Update for DiscreteTransferFcn: '<S40>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_o =
      ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_cw;
  }

  if (rtmIsMajorTimeStep(ctrl_TAPM2_M)) {
    rt_ertODEUpdateContinuousStates(&ctrl_TAPM2_M->solverInfo);
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
  if (!(++ctrl_TAPM2_M->Timing.clockTick0)) {
    ++ctrl_TAPM2_M->Timing.clockTickH0;
  }

  ctrl_TAPM2_M->Timing.t[0] = rtsiGetSolverStopTime(&ctrl_TAPM2_M->solverInfo);

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
    if (!(++ctrl_TAPM2_M->Timing.clockTick1)) {
      ++ctrl_TAPM2_M->Timing.clockTickH1;
    }

    ctrl_TAPM2_M->Timing.t[1] = ctrl_TAPM2_M->Timing.clockTick1 *
      ctrl_TAPM2_M->Timing.stepSize1 + ctrl_TAPM2_M->Timing.clockTickH1 *
      ctrl_TAPM2_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ctrl_TAPM2_derivatives(void)
{
  XDot_ctrl_TAPM2_T *_rtXdot;
  _rtXdot = ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S43>/Integrator' */
  {
    ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs)->Integrator_CSTATE =
      ctrl_TAPM2_B.Findingrotationspeed;
  }

  /* Derivatives for Integrator: '<S53>/Integrator' */
  {
    ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs)->Integrator_CSTATE_p =
      ctrl_TAPM2_B.Findingrotationspeed_a;
  }

  /* Derivatives for Integrator: '<S63>/Integrator' */
  {
    ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs)->Integrator_CSTATE_k =
      ctrl_TAPM2_B.Findingrotationspeed_m;
  }

  /* Derivatives for Integrator: '<S73>/Integrator' */
  {
    ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs)->Integrator_CSTATE_n =
      ctrl_TAPM2_B.Findingrotationspeed_ms;
  }

  /* Derivatives for Integrator: '<S83>/Integrator' */
  {
    ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs)->Integrator_CSTATE_c =
      ctrl_TAPM2_B.Findingrotationspeed_ag;
  }

  /* Derivatives for Integrator: '<S93>/Integrator' */
  {
    ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs)->Integrator_CSTATE_h =
      ctrl_TAPM2_B.Findingrotationspeed_c;
  }

  /* Derivatives for Integrator: '<S46>/Integrator' */
  {
    ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs)->Integrator_CSTATE_e =
      ctrl_TAPM2_B.Ki;
  }

  /* Derivatives for Integrator: '<S56>/Integrator' */
  {
    ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs)->Integrator_CSTATE_g =
      ctrl_TAPM2_B.Ki_o;
  }

  /* Derivatives for Integrator: '<S66>/Integrator' */
  {
    ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs)->Integrator_CSTATE_i =
      ctrl_TAPM2_B.Ki_n;
  }

  /* Derivatives for Integrator: '<S76>/Integrator' */
  {
    ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs)->Integrator_CSTATE_l =
      ctrl_TAPM2_B.Ki_b;
  }

  /* Derivatives for Integrator: '<S86>/Integrator' */
  {
    ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs)->Integrator_CSTATE_n4
      = ctrl_TAPM2_B.Ki_a;
  }

  /* Derivatives for Integrator: '<S96>/Integrator' */
  {
    ((XDot_ctrl_TAPM2_T *) ctrl_TAPM2_M->ModelData.derivs)->Integrator_CSTATE_gj
      = ctrl_TAPM2_B.Ki_p;
  }

  /* Derivatives for Integrator: '<S12>/Integrator' */
  _rtXdot->Integrator_CSTATE_c5[0] = ctrl_TAPM2_B.Sum3[0];
  _rtXdot->Integrator_CSTATE_c5[1] = ctrl_TAPM2_B.Sum3[1];
  _rtXdot->Integrator_CSTATE_c5[2] = ctrl_TAPM2_B.Sum3[2];

  /* Derivatives for Integrator: '<S12>/Integrator4' */
  _rtXdot->Integrator4_CSTATE[0] = ctrl_TAPM2_B.Gain3[0];
  _rtXdot->Integrator4_CSTATE[1] = ctrl_TAPM2_B.Gain3[1];
  _rtXdot->Integrator4_CSTATE[2] = ctrl_TAPM2_B.Gain3[2];

  /* Derivatives for Integrator: '<S13>/Integrator' */
  _rtXdot->Integrator_CSTATE_l0[0] = ctrl_TAPM2_B.Sum1_bn[0];
  _rtXdot->Integrator_CSTATE_l0[1] = ctrl_TAPM2_B.Sum1_bn[1];

  /* Derivatives for TransferFcn: '<S13>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += ctrl_TAPM2_P.TransferFcn2_A *
    ctrl_TAPM2_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += ctrl_TAPM2_B.Sum_j;

  /* Derivatives for Integrator: '<S12>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = ctrl_TAPM2_B.Sum6[0];
  _rtXdot->Integrator1_CSTATE[1] = ctrl_TAPM2_B.Sum6[1];
  _rtXdot->Integrator1_CSTATE[2] = ctrl_TAPM2_B.Sum6[2];

  /* Derivatives for Integrator: '<S12>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = ctrl_TAPM2_B.psi_WF[0];
  _rtXdot->Integrator2_CSTATE[1] = ctrl_TAPM2_B.psi_WF[1];
  _rtXdot->Integrator2_CSTATE[2] = ctrl_TAPM2_B.psi_WF[2];

  /* Derivatives for Integrator: '<S12>/Integrator3' */
  _rtXdot->Integrator3_CSTATE[0] = ctrl_TAPM2_B.Sum7[0];
  _rtXdot->Integrator3_CSTATE[1] = ctrl_TAPM2_B.Sum7[1];
  _rtXdot->Integrator3_CSTATE[2] = ctrl_TAPM2_B.Sum7[2];
}

/* Model initialize function */
void ctrl_TAPM2_initialize(void)
{
  ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
  ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_o = UNINITIALIZED_ZCSIG;
  ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
  ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
  ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
  ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_o3 = UNINITIALIZED_ZCSIG;
  ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_db = UNINITIALIZED_ZCSIG;
  ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
  ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
  ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_f = UNINITIALIZED_ZCSIG;
  ctrl_TAPM2_PrevZCX.Integrator_Reset_ZCE_i3 = UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S43>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE = ctrl_TAPM2_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S53>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_p = ctrl_TAPM2_P.Integrator_IC_f;

    /* InitializeConditions for Integrator: '<S63>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_k = ctrl_TAPM2_P.Integrator_IC_p;

    /* InitializeConditions for Integrator: '<S73>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_n = ctrl_TAPM2_P.Integrator_IC_fv;

    /* InitializeConditions for Integrator: '<S83>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_c = ctrl_TAPM2_P.Integrator_IC_l;

    /* InitializeConditions for Integrator: '<S93>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_h = ctrl_TAPM2_P.Integrator_IC_li;

    /* InitializeConditions for Delay: '<S8>/Delay' */
    for (i = 0; i < 6; i++) {
      ctrl_TAPM2_DW.Delay_DSTATE[i] = ctrl_TAPM2_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S8>/Delay' */

    /* InitializeConditions for Delay: '<S35>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_f = ctrl_TAPM2_P.Delay_InitialCondition_i;

    /* InitializeConditions for Delay: '<S44>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_fu = ctrl_TAPM2_P.Delay_InitialCondition_f;

    /* InitializeConditions for DiscreteTransferFcn: '<S44>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states[0] =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialStat;
    ctrl_TAPM2_DW.DiscreteTransferFcn_states[1] =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialStat;

    /* InitializeConditions for UnitDelay: '<S47>/UD' */
    ctrl_TAPM2_DW.UD_DSTATE = ctrl_TAPM2_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for RateLimiter: '<S44>/Acceleration Limit' */
    ctrl_TAPM2_DW.PrevY = ctrl_TAPM2_P.AccelerationLimit_IC;

    /* InitializeConditions for Memory: '<S44>/Memory' */
    ctrl_TAPM2_DW.Memory_PreviousInput = ctrl_TAPM2_P.Memory_X0;

    /* InitializeConditions for Integrator: '<S46>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_e = ctrl_TAPM2_P.Integrator_IC_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S35>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_d =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialSt_h;

    /* InitializeConditions for Delay: '<S36>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_b = ctrl_TAPM2_P.Delay_InitialCondition_l;

    /* InitializeConditions for Delay: '<S54>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_d = ctrl_TAPM2_P.Delay_InitialCondition_iv;

    /* InitializeConditions for DiscreteTransferFcn: '<S54>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_h[0] =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialS_hu;
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_h[1] =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialS_hu;

    /* InitializeConditions for UnitDelay: '<S57>/UD' */
    ctrl_TAPM2_DW.UD_DSTATE_n = ctrl_TAPM2_P.DiscreteDerivative_ICPrevScal_p;

    /* InitializeConditions for RateLimiter: '<S54>/Acceleration Limit' */
    ctrl_TAPM2_DW.PrevY_e = ctrl_TAPM2_P.AccelerationLimit_IC_m;

    /* InitializeConditions for Memory: '<S54>/Memory' */
    ctrl_TAPM2_DW.Memory_PreviousInput_n = ctrl_TAPM2_P.Memory_X0_e;

    /* InitializeConditions for Integrator: '<S56>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_g = ctrl_TAPM2_P.Integrator_IC_fy;

    /* InitializeConditions for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_m =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialSt_f;

    /* InitializeConditions for Delay: '<S37>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_n = ctrl_TAPM2_P.Delay_InitialCondition_d;

    /* InitializeConditions for Delay: '<S64>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_no = ctrl_TAPM2_P.Delay_InitialCondition_h;

    /* InitializeConditions for DiscreteTransferFcn: '<S64>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_j[0] =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialSt_a;
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_j[1] =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialSt_a;

    /* InitializeConditions for UnitDelay: '<S67>/UD' */
    ctrl_TAPM2_DW.UD_DSTATE_i = ctrl_TAPM2_P.DiscreteDerivative_ICPrevSca_pl;

    /* InitializeConditions for RateLimiter: '<S64>/Acceleration limiter' */
    ctrl_TAPM2_DW.PrevY_o = ctrl_TAPM2_P.Accelerationlimiter_IC;

    /* InitializeConditions for Memory: '<S64>/Memory' */
    ctrl_TAPM2_DW.Memory_PreviousInput_d = ctrl_TAPM2_P.Memory_X0_g;

    /* InitializeConditions for Integrator: '<S66>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_i = ctrl_TAPM2_P.Integrator_IC_j;

    /* InitializeConditions for DiscreteTransferFcn: '<S37>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_k =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialSt_c;

    /* InitializeConditions for Delay: '<S38>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_e = ctrl_TAPM2_P.Delay_InitialCondition_fb;

    /* InitializeConditions for Delay: '<S74>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_i = ctrl_TAPM2_P.Delay_InitialCondition_g;

    /* InitializeConditions for DiscreteTransferFcn: '<S74>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_i[0] =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialS_a1;
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_i[1] =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialS_a1;

    /* InitializeConditions for UnitDelay: '<S77>/UD' */
    ctrl_TAPM2_DW.UD_DSTATE_n4 = ctrl_TAPM2_P.DiscreteDerivative_ICPrevScal_f;

    /* InitializeConditions for RateLimiter: '<S74>/Acceleration limiter' */
    ctrl_TAPM2_DW.PrevY_c = ctrl_TAPM2_P.Accelerationlimiter_IC_h;

    /* InitializeConditions for Memory: '<S74>/Memory' */
    ctrl_TAPM2_DW.Memory_PreviousInput_a = ctrl_TAPM2_P.Memory_X0_k;

    /* InitializeConditions for Integrator: '<S76>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_l = ctrl_TAPM2_P.Integrator_IC_g;

    /* InitializeConditions for DiscreteTransferFcn: '<S38>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_h0 =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialSt_p;

    /* InitializeConditions for Delay: '<S39>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_j = ctrl_TAPM2_P.Delay_InitialCondition_fv;

    /* InitializeConditions for Delay: '<S84>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_a = ctrl_TAPM2_P.Delay_InitialCondition_dz;

    /* InitializeConditions for DiscreteTransferFcn: '<S84>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb[0] =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialSt_e;
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb[1] =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialSt_e;

    /* InitializeConditions for UnitDelay: '<S87>/UD' */
    ctrl_TAPM2_DW.UD_DSTATE_m = ctrl_TAPM2_P.DiscreteDerivative_ICPrevScal_o;

    /* InitializeConditions for RateLimiter: '<S84>/Acceleration limiter' */
    ctrl_TAPM2_DW.PrevY_j = ctrl_TAPM2_P.Accelerationlimiter_IC_i;

    /* InitializeConditions for Memory: '<S84>/Memory' */
    ctrl_TAPM2_DW.Memory_PreviousInput_b = ctrl_TAPM2_P.Memory_X0_k3;

    /* InitializeConditions for Integrator: '<S86>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_n4 = ctrl_TAPM2_P.Integrator_IC_aj;

    /* InitializeConditions for DiscreteTransferFcn: '<S39>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_dt =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialS_pj;

    /* InitializeConditions for Delay: '<S40>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_dv = ctrl_TAPM2_P.Delay_InitialCondition_fi;

    /* InitializeConditions for Delay: '<S94>/Delay' */
    ctrl_TAPM2_DW.Delay_DSTATE_m = ctrl_TAPM2_P.Delay_InitialCondition_a;

    /* InitializeConditions for DiscreteTransferFcn: '<S94>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_l[0] =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialS_a4;
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_l[1] =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialS_a4;

    /* InitializeConditions for UnitDelay: '<S97>/UD' */
    ctrl_TAPM2_DW.UD_DSTATE_l = ctrl_TAPM2_P.DiscreteDerivative_ICPrevScal_n;

    /* InitializeConditions for RateLimiter: '<S94>/Acceleration limiter' */
    ctrl_TAPM2_DW.PrevY_h = ctrl_TAPM2_P.Accelerationlimiter_IC_p;

    /* InitializeConditions for Memory: '<S94>/Memory' */
    ctrl_TAPM2_DW.Memory_PreviousInput_a4 = ctrl_TAPM2_P.Memory_X0_c;

    /* InitializeConditions for Integrator: '<S96>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_gj = ctrl_TAPM2_P.Integrator_IC_h;

    /* InitializeConditions for DiscreteTransferFcn: '<S40>/Discrete Transfer Fcn' */
    ctrl_TAPM2_DW.DiscreteTransferFcn_states_o =
      ctrl_TAPM2_P.DiscreteTransferFcn_InitialSt_b;

    /* InitializeConditions for Integrator: '<S12>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_c5[0] = ctrl_TAPM2_P.Integrator_IC_i[0];
    ctrl_TAPM2_X.Integrator_CSTATE_c5[1] = ctrl_TAPM2_P.Integrator_IC_i[1];
    ctrl_TAPM2_X.Integrator_CSTATE_c5[2] = ctrl_TAPM2_P.Integrator_IC_i[2];

    /* InitializeConditions for Integrator: '<S12>/Integrator4' */
    ctrl_TAPM2_X.Integrator4_CSTATE[0] = ctrl_TAPM2_P.Integrator4_IC[0];
    ctrl_TAPM2_X.Integrator4_CSTATE[1] = ctrl_TAPM2_P.Integrator4_IC[1];
    ctrl_TAPM2_X.Integrator4_CSTATE[2] = ctrl_TAPM2_P.Integrator4_IC[2];

    /* InitializeConditions for Integrator: '<S13>/Integrator' */
    ctrl_TAPM2_X.Integrator_CSTATE_l0[0] = ctrl_TAPM2_P.Integrator_IC_b[0];
    ctrl_TAPM2_X.Integrator_CSTATE_l0[1] = ctrl_TAPM2_P.Integrator_IC_b[1];

    /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn2' */
    ctrl_TAPM2_X.TransferFcn2_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S12>/Integrator1' */
    ctrl_TAPM2_X.Integrator1_CSTATE[0] = ctrl_TAPM2_P.Integrator1_IC;
    ctrl_TAPM2_X.Integrator1_CSTATE[1] = ctrl_TAPM2_P.Integrator1_IC;
    ctrl_TAPM2_X.Integrator1_CSTATE[2] = ctrl_TAPM2_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<S12>/Integrator2' */
    ctrl_TAPM2_X.Integrator2_CSTATE[0] = ctrl_TAPM2_P.Integrator2_IC;
    ctrl_TAPM2_X.Integrator2_CSTATE[1] = ctrl_TAPM2_P.Integrator2_IC;
    ctrl_TAPM2_X.Integrator2_CSTATE[2] = ctrl_TAPM2_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S12>/Integrator3' */
    ctrl_TAPM2_X.Integrator3_CSTATE[0] = ctrl_TAPM2_P.Integrator3_IC;
    ctrl_TAPM2_X.Integrator3_CSTATE[1] = ctrl_TAPM2_P.Integrator3_IC;
    ctrl_TAPM2_X.Integrator3_CSTATE[2] = ctrl_TAPM2_P.Integrator3_IC;
  }
}

/* Model terminate function */
void ctrl_TAPM2_terminate(void)
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
  ctrl_TAPM2_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_TAPM2_update();
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
  ctrl_TAPM2_initialize();
}

void MdlTerminate(void)
{
  ctrl_TAPM2_terminate();
}

/* Registration function */
RT_MODEL_ctrl_TAPM2_T *ctrl_TAPM2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_TAPM2_M, 0,
                sizeof(RT_MODEL_ctrl_TAPM2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ctrl_TAPM2_M->solverInfo,
                          &ctrl_TAPM2_M->Timing.simTimeStep);
    rtsiSetTPtr(&ctrl_TAPM2_M->solverInfo, &rtmGetTPtr(ctrl_TAPM2_M));
    rtsiSetStepSizePtr(&ctrl_TAPM2_M->solverInfo,
                       &ctrl_TAPM2_M->Timing.stepSize0);
    rtsiSetdXPtr(&ctrl_TAPM2_M->solverInfo, &ctrl_TAPM2_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ctrl_TAPM2_M->solverInfo, (real_T **)
                         &ctrl_TAPM2_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ctrl_TAPM2_M->solverInfo,
      &ctrl_TAPM2_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ctrl_TAPM2_M->solverInfo, (&rtmGetErrorStatus
      (ctrl_TAPM2_M)));
    rtsiSetRTModelPtr(&ctrl_TAPM2_M->solverInfo, ctrl_TAPM2_M);
  }

  rtsiSetSimTimeStep(&ctrl_TAPM2_M->solverInfo, MAJOR_TIME_STEP);
  ctrl_TAPM2_M->ModelData.intgData.y = ctrl_TAPM2_M->ModelData.odeY;
  ctrl_TAPM2_M->ModelData.intgData.f[0] = ctrl_TAPM2_M->ModelData.odeF[0];
  ctrl_TAPM2_M->ModelData.intgData.f[1] = ctrl_TAPM2_M->ModelData.odeF[1];
  ctrl_TAPM2_M->ModelData.intgData.f[2] = ctrl_TAPM2_M->ModelData.odeF[2];
  ctrl_TAPM2_M->ModelData.contStates = ((real_T *) &ctrl_TAPM2_X);
  rtsiSetSolverData(&ctrl_TAPM2_M->solverInfo, (void *)
                    &ctrl_TAPM2_M->ModelData.intgData);
  rtsiSetSolverName(&ctrl_TAPM2_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_TAPM2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ctrl_TAPM2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_TAPM2_M->Timing.sampleTimes = (&ctrl_TAPM2_M->Timing.sampleTimesArray[0]);
    ctrl_TAPM2_M->Timing.offsetTimes = (&ctrl_TAPM2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_TAPM2_M->Timing.sampleTimes[0] = (0.0);
    ctrl_TAPM2_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ctrl_TAPM2_M->Timing.offsetTimes[0] = (0.0);
    ctrl_TAPM2_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ctrl_TAPM2_M, &ctrl_TAPM2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_TAPM2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ctrl_TAPM2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_TAPM2_M, -1);
  ctrl_TAPM2_M->Timing.stepSize0 = 0.01;
  ctrl_TAPM2_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_TAPM2_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_TAPM2_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_TAPM2_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_TAPM2_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_TAPM2_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_TAPM2_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_TAPM2_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_TAPM2_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_TAPM2_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_TAPM2_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_TAPM2_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_TAPM2_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_TAPM2_M->rtwLogInfo, (NULL));
  }

  ctrl_TAPM2_M->solverInfoPtr = (&ctrl_TAPM2_M->solverInfo);
  ctrl_TAPM2_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_TAPM2_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_TAPM2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_TAPM2_M->ModelData.blockIO = ((void *) &ctrl_TAPM2_B);
  (void) memset(((void *) &ctrl_TAPM2_B), 0,
                sizeof(B_ctrl_TAPM2_T));

  /* parameters */
  ctrl_TAPM2_M->ModelData.defaultParam = ((real_T *)&ctrl_TAPM2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ctrl_TAPM2_X;
    ctrl_TAPM2_M->ModelData.contStates = (x);
    (void) memset((void *)&ctrl_TAPM2_X, 0,
                  sizeof(X_ctrl_TAPM2_T));
  }

  /* states (dwork) */
  ctrl_TAPM2_M->ModelData.dwork = ((void *) &ctrl_TAPM2_DW);
  (void) memset((void *)&ctrl_TAPM2_DW, 0,
                sizeof(DW_ctrl_TAPM2_T));

  /* Initialize Sizes */
  ctrl_TAPM2_M->Sizes.numContStates = (30);/* Number of continuous states */
  ctrl_TAPM2_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ctrl_TAPM2_M->Sizes.numY = (0);      /* Number of model outputs */
  ctrl_TAPM2_M->Sizes.numU = (0);      /* Number of model inputs */
  ctrl_TAPM2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_TAPM2_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ctrl_TAPM2_M->Sizes.numBlocks = (380);/* Number of blocks */
  ctrl_TAPM2_M->Sizes.numBlockIO = (170);/* Number of block outputs */
  ctrl_TAPM2_M->Sizes.numBlockPrms = (633);/* Sum of parameter "widths" */
  return ctrl_TAPM2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_TAPM2
 * Model version : 1.39
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Sun May 15 13:28:12 2016
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_TAPM2
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

   case 53:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 54:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 55:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 56:
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

   case 53:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 54:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);

   case 55:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 56:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,7,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_TAPM2_rtModel *S;
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

  // ctrl_TAPM2/Thruster control /Thruster 1/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.reset, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster control /Thruster 2/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.reset_c, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster control /Thruster 3/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.reset_j, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster control /Thruster 4/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.reset_p, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster control /Thruster 5/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.reset_k, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster control /Thruster 6/Shaft dynamics/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.reset_i, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster control /Thruster 1/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.reset_kk, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster control /Thruster 2/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.reset_e, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster control /Thruster 3/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.reset_j2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster control /Thruster 4/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.reset_n, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster control /Thruster 5/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.reset_f, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster control /Thruster 6/Thruster control/Core controller/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.reset_o, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Pos measurements/x_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.x_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Pos measurements/y_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.y_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Pos measurements/psi_m
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.psi_m, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Input/wave_dir
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.wave_dir, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Input/fzp_x
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.fzp_x, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Input/fzp_y
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.fzp_y, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Input/r_max
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.r_max, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster measurment/thr_angle_1
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.thr_angle_1, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster measurment/thr_angle_2
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.thr_angle_2, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster measurment/thr_angle_3
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.thr_angle_3, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster measurment/thr_angle_4
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.thr_angle_4, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster measurment/thr_angle_5
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.thr_angle_5, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/Thruster measurment/thr_angle_6
  if (TaskSampleHit[1]) {
    NIRT_SetValueByDataType(&ctrl_TAPM2_B.thr_angle_6, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 25;
}

int32_t NumOutputPorts(void)
{
  return 33;
}

double ni_extout[33];

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

  // ctrl_TAPM2/alpha_1: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation1, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/pwm_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.pwmthruster2, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/pwm_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.pwmthruster3, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/pwm_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.pwmthruster4, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/pwm_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.pwmthruster5, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/alpha_2: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation2, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/pwm_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.pwmthruster6, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/alpha_3: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation3, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/alpha_4: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation4, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/alpha_5: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation5, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/alpha_6: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation6, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/u_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation7, 0,
      21, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/u_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation7, 3,
      21, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/u_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation7, 4,
      21, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/u_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation7, 5,
      21, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/u_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation7, 1,
      21, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/u_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation7, 2,
      21, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/pwm_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.pwmthruster1, 0,
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_TAPM2/tau_actual: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.actual_tau, 0, 22,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.actual_tau, 1, 22,
      0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.actual_tau, 2, 22,
      0);
  } else {
    index += 3;
  }

  // ctrl_TAPM2/TAPM Controller w_observer/eta_est: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.eta, 0, 25, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.eta, 1, 25, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.eta, 2, 25, 0);
  } else {
    index += 3;
  }

  // ctrl_TAPM2/TAPM Controller w_observer/nu_est: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.nu, 0, 25, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.nu, 1, 25, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.nu, 2, 25, 0);
  } else {
    index += 3;
  }

  // ctrl_TAPM2/TAPM Controller w_observer/SP: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_B.TmpSignalConversionAtSPInport1, 0, 22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_B.TmpSignalConversionAtSPInport1, 1, 22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_B.TmpSignalConversionAtSPInport1, 2, 22, 0);
  } else {
    index += 3;
  }

  // ctrl_TAPM2/TAPM Controller w_observer/tau_des: Virtual Signal # 0
  if (TaskSampleHit[1]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Gain_d, 0, 22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Gain_d, 1, 22, 0);
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Gain_d, 2, 22, 0);
  } else {
    index += 3;
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

  // ctrl_TAPM2/alpha_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation1, 0, 0,
    0);

  // ctrl_TAPM2/pwm_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.pwmthruster2, 0, 0,
    0);

  // ctrl_TAPM2/pwm_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.pwmthruster3, 0, 0,
    0);

  // ctrl_TAPM2/pwm_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.pwmthruster4, 0, 0,
    0);

  // ctrl_TAPM2/pwm_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.pwmthruster5, 0, 0,
    0);

  // ctrl_TAPM2/alpha_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation2, 0, 0,
    0);

  // ctrl_TAPM2/pwm_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.pwmthruster6, 0, 0,
    0);

  // ctrl_TAPM2/alpha_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation3, 0, 0,
    0);

  // ctrl_TAPM2/alpha_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation4, 0, 0,
    0);

  // ctrl_TAPM2/alpha_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation5, 0, 0,
    0);

  // ctrl_TAPM2/alpha_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation6, 0, 0,
    0);

  // ctrl_TAPM2/u_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation7, 0, 21,
    0);

  // ctrl_TAPM2/u_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation7, 3, 21,
    0);

  // ctrl_TAPM2/u_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation7, 4, 21,
    0);

  // ctrl_TAPM2/u_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation7, 5, 21,
    0);

  // ctrl_TAPM2/u_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation7, 1, 21,
    0);

  // ctrl_TAPM2/u_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Saturation7, 2, 21,
    0);

  // ctrl_TAPM2/pwm_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.pwmthruster1, 0, 0,
    0);

  // ctrl_TAPM2/tau_actual: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.actual_tau, 0, 22,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.actual_tau, 1, 22,
    0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.actual_tau, 2, 22,
    0);

  // ctrl_TAPM2/TAPM Controller w_observer/eta_est: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.eta, 0, 25, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.eta, 1, 25, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.eta, 2, 25, 0);

  // ctrl_TAPM2/TAPM Controller w_observer/nu_est: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.nu, 0, 25, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.nu, 1, 25, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.nu, 2, 25, 0);

  // ctrl_TAPM2/TAPM Controller w_observer/SP: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM2_B.TmpSignalConversionAtSPInport1, 0, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM2_B.TmpSignalConversionAtSPInport1, 1, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType
    (&ctrl_TAPM2_B.TmpSignalConversionAtSPInport1, 2, 22, 0);

  // ctrl_TAPM2/TAPM Controller w_observer/tau_des: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Gain_d, 0, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Gain_d, 1, 22, 0);
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_TAPM2_B.Gain_d, 2, 22, 0);
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
  { 0, "ctrl_tapm2/Parameters From initfile distributed /D/Value", offsetof
    (P_ctrl_TAPM2_T, D), 53, 1, 2, 0, 0 },

  { 1,
    "ctrl_tapm2/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM2_T, I_s), 53, 1, 2, 2, 0 },

  { 2,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM2_T, I_s), 53, 1, 2, 4, 0 },

  { 3,
    "ctrl_tapm2/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM2_T, I_s), 53, 1, 2, 6, 0 },

  { 4,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM2_T, I_s), 53, 1, 2, 8, 0 },

  { 5,
    "ctrl_tapm2/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM2_T, I_s), 53, 1, 2, 10, 0 },

  { 6,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM2_T, I_s), 53, 1, 2, 12, 0 },

  { 7,
    "ctrl_tapm2/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM2_T, I_s), 53, 1, 2, 14, 0 },

  { 8,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM2_T, I_s), 53, 1, 2, 16, 0 },

  { 9,
    "ctrl_tapm2/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM2_T, I_s), 53, 1, 2, 18, 0 },

  { 10,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM2_T, I_s), 53, 1, 2, 20, 0 },

  { 11,
    "ctrl_tapm2/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed/Gain",
    offsetof(P_ctrl_TAPM2_T, I_s), 53, 1, 2, 22, 0 },

  { 12,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Inertia compensation/Gain",
    offsetof(P_ctrl_TAPM2_T, I_s), 53, 1, 2, 24, 0 },

  { 13, "ctrl_tapm2/Thruster control /Thruster 1/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM2_T, K_omega), 53, 1, 2, 26, 0 },

  { 14,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, K_omega), 53, 1, 2, 28, 0 },

  { 15, "ctrl_tapm2/Thruster control /Thruster 2/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM2_T, K_omega), 53, 1, 2, 30, 0 },

  { 16,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, K_omega), 53, 1, 2, 32, 0 },

  { 17, "ctrl_tapm2/Thruster control /Thruster 3/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM2_T, K_omega), 53, 1, 2, 34, 0 },

  { 18,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, K_omega), 53, 1, 2, 36, 0 },

  { 19, "ctrl_tapm2/Thruster control /Thruster 4/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM2_T, K_omega), 53, 1, 2, 38, 0 },

  { 20,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, K_omega), 53, 1, 2, 40, 0 },

  { 21, "ctrl_tapm2/Thruster control /Thruster 5/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM2_T, K_omega), 53, 1, 2, 42, 0 },

  { 22,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, K_omega), 53, 1, 2, 44, 0 },

  { 23, "ctrl_tapm2/Thruster control /Thruster 6/Shaft dynamics/K_omega/Gain",
    offsetof(P_ctrl_TAPM2_T, K_omega), 53, 1, 2, 46, 0 },

  { 24,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Qff_1(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, K_omega), 53, 1, 2, 48, 0 },

  { 25,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM2_T, Kp), 53, 1, 2, 50, 0 },

  { 26,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM2_T, Kp), 53, 1, 2, 52, 0 },

  { 27,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM2_T, Kp), 53, 1, 2, 54, 0 },

  { 28,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM2_T, Kp), 53, 1, 2, 56, 0 },

  { 29,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM2_T, Kp), 53, 1, 2, 58, 0 },

  { 30,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM2_T, Kp), 53, 1, 2, 60, 0 },

  { 31,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM2_T, Kp), 53, 1, 2, 62, 0 },

  { 32,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM2_T, Kp), 53, 1, 2, 64, 0 },

  { 33,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM2_T, Kp), 53, 1, 2, 66, 0 },

  { 34,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM2_T, Kp), 53, 1, 2, 68, 0 },

  { 35,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Core controller/Ki/Gain",
    offsetof(P_ctrl_TAPM2_T, Kp), 53, 1, 2, 70, 0 },

  { 36,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Core controller/Kp/Gain",
    offsetof(P_ctrl_TAPM2_T, Kp), 53, 1, 2, 72, 0 },

  { 37, "ctrl_tapm2/Parameters From initfile distributed /Kq/Value", offsetof
    (P_ctrl_TAPM2_T, Kq), 53, 1, 2, 74, 0 },

  { 38, "ctrl_tapm2/Parameters From initfile distributed /Kqr/Value", offsetof
    (P_ctrl_TAPM2_T, Kqr), 53, 1, 2, 76, 0 },

  { 39, "ctrl_tapm2/Parameters From initfile distributed /Kt/Value", offsetof
    (P_ctrl_TAPM2_T, Kt), 53, 1, 2, 78, 0 },

  { 40, "ctrl_tapm2/Parameters From initfile distributed /Ktr/Value", offsetof
    (P_ctrl_TAPM2_T, Ktr), 53, 1, 2, 80, 0 },

  { 41, "ctrl_tapm2/Thruster control /Subsystem/Saturation 1/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 82, 0 },

  { 42, "ctrl_tapm2/Thruster control /Subsystem/Saturation 1/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 84, 0 },

  { 43, "ctrl_tapm2/Thruster control /Subsystem/Saturation 2/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 86, 0 },

  { 44, "ctrl_tapm2/Thruster control /Subsystem/Saturation 2/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 88, 0 },

  { 45, "ctrl_tapm2/Thruster control /Subsystem/Saturation 3/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 90, 0 },

  { 46, "ctrl_tapm2/Thruster control /Subsystem/Saturation 3/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 92, 0 },

  { 47, "ctrl_tapm2/Thruster control /Subsystem/Saturation 4/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 94, 0 },

  { 48, "ctrl_tapm2/Thruster control /Subsystem/Saturation 4/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 96, 0 },

  { 49, "ctrl_tapm2/Thruster control /Subsystem/Saturation 5/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 98, 0 },

  { 50, "ctrl_tapm2/Thruster control /Subsystem/Saturation 5/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 100, 0 },

  { 51, "ctrl_tapm2/Thruster control /Subsystem/Saturation 6/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 102, 0 },

  { 52, "ctrl_tapm2/Thruster control /Subsystem/Saturation 6/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 104, 0 },

  { 53, "ctrl_tapm2/Thruster control /Subsystem/Saturation 7/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 106, 0 },

  { 54, "ctrl_tapm2/Thruster control /Subsystem/Saturation 7/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Max_thrust), 53, 1, 2, 108, 0 },

  { 55, "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM2_T, Q_f0), 53, 1, 2, 110, 0 },

  { 56, "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM2_T, Q_f0), 53, 1, 2, 112, 0 },

  { 57, "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM2_T, Q_f0), 53, 1, 2, 114, 0 },

  { 58, "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM2_T, Q_f0), 53, 1, 2, 116, 0 },

  { 59, "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM2_T, Q_f0), 53, 1, 2, 118, 0 },

  { 60, "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Qf_0/Gain",
    offsetof(P_ctrl_TAPM2_T, Q_f0), 53, 1, 2, 120, 0 },

  { 61, "ctrl_tapm2/Parameters From initfile distributed /Rho/Value", offsetof
    (P_ctrl_TAPM2_T, Rho), 53, 1, 2, 122, 0 },

  { 62,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_TAPM2_T, Thruster_control), 53, 1, 2, 124, 0 },

  { 63,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_TAPM2_T, Thruster_control), 53, 1, 2, 126, 0 },

  { 64,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_TAPM2_T, Thruster_control), 53, 1, 2, 128, 0 },

  { 65,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_TAPM2_T, Thruster_control), 53, 1, 2, 130, 0 },

  { 66,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_TAPM2_T, Thruster_control), 53, 1, 2, 132, 0 },

  { 67,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Switch controller/Value",
    offsetof(P_ctrl_TAPM2_T, Thruster_control), 53, 1, 2, 134, 0 },

  { 68, "ctrl_tapm2/Parameters From initfile distributed /Constant4/Value",
    offsetof(P_ctrl_TAPM2_T, eps), 53, 1, 2, 136, 0 },

  { 69, "ctrl_tapm2/Parameters From initfile distributed /Constant/Value",
    offsetof(P_ctrl_TAPM2_T, eps_c), 53, 1, 2, 138, 0 },

  { 70,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, epsilon), 53, 1, 2, 140, 0 },

  { 71,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, epsilon), 53, 1, 2, 142, 0 },

  { 72,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, epsilon), 53, 1, 2, 144, 0 },

  { 73,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, epsilon), 53, 1, 2, 146, 0 },

  { 74,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, epsilon), 53, 1, 2, 148, 0 },

  { 75,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, epsilon), 53, 1, 2, 150, 0 },

  { 76, "ctrl_tapm2/Parameters From initfile distributed /Constant1/Value",
    offsetof(P_ctrl_TAPM2_T, k_cc), 53, 1, 2, 152, 0 },

  { 77, "ctrl_tapm2/Parameters From initfile distributed /Constant5/Value",
    offsetof(P_ctrl_TAPM2_T, n_c), 53, 1, 2, 154, 0 },

  { 78,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, n_max), 53, 1, 2, 156, 0 },

  { 79,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, n_max), 53, 1, 2, 158, 0 },

  { 80,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, n_max), 53, 1, 2, 160, 0 },

  { 81,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, n_max), 53, 1, 2, 162, 0 },

  { 82,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, n_max), 53, 1, 2, 164, 0 },

  { 83,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Qff_0(nr)/Gain",
    offsetof(P_ctrl_TAPM2_T, n_max), 53, 1, 2, 166, 0 },

  { 84, "ctrl_tapm2/Parameters From initfile distributed /Constant2/Value",
    offsetof(P_ctrl_TAPM2_T, p_cc), 53, 1, 2, 168, 0 },

  { 85, "ctrl_tapm2/Parameters From initfile distributed /Constant3/Value",
    offsetof(P_ctrl_TAPM2_T, r_cc), 53, 1, 2, 170, 0 },

  { 86, "ctrl_tapm2/Thruster control /Subsystem/pwm thruster 1/Coefs", offsetof
    (P_ctrl_TAPM2_T, thrust_to_pwm_coeff), 33, 6, 2, 172, 0 },

  { 87, "ctrl_tapm2/Thruster control /Subsystem/pwm thruster 2/Coefs", offsetof
    (P_ctrl_TAPM2_T, thrust_to_pwm_coeff), 33, 6, 2, 174, 0 },

  { 88, "ctrl_tapm2/Thruster control /Subsystem/pwm thruster 3/Coefs", offsetof
    (P_ctrl_TAPM2_T, thrust_to_pwm_coeff), 33, 6, 2, 176, 0 },

  { 89, "ctrl_tapm2/Thruster control /Subsystem/pwm thruster 4/Coefs", offsetof
    (P_ctrl_TAPM2_T, thrust_to_pwm_coeff), 33, 6, 2, 178, 0 },

  { 90, "ctrl_tapm2/Thruster control /Subsystem/pwm thruster 5/Coefs", offsetof
    (P_ctrl_TAPM2_T, thrust_to_pwm_coeff), 33, 6, 2, 180, 0 },

  { 91, "ctrl_tapm2/Thruster control /Subsystem/pwm thruster 6/Coefs", offsetof
    (P_ctrl_TAPM2_T, thrust_to_pwm_coeff), 33, 6, 2, 182, 0 },

  { 92,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Gain6/Gain",
    offsetof(P_ctrl_TAPM2_T, Nonlinearpassiveobserver_D), 35, 9, 2, 184, 0 },

  { 93,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, DiscreteDerivative_ICPrevScaled), 53, 1, 2, 186, 0
  },

  { 94,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, DiscreteDerivative_ICPrevScal_p), 53, 1, 2, 188, 0
  },

  { 95,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, DiscreteDerivative_ICPrevSca_pl), 53, 1, 2, 190, 0
  },

  { 96,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, DiscreteDerivative_ICPrevScal_f), 53, 1, 2, 192, 0
  },

  { 97,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, DiscreteDerivative_ICPrevScal_o), 53, 1, 2, 194, 0
  },

  { 98,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Discrete Derivative/UD/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, DiscreteDerivative_ICPrevScal_n), 53, 1, 2, 196, 0
  },

  { 99,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /K3/Gain",
    offsetof(P_ctrl_TAPM2_T, Nonlinearpassiveobserver_K3), 35, 9, 2, 198, 0 },

  { 100,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /K4/Gain",
    offsetof(P_ctrl_TAPM2_T, Nonlinearpassiveobserver_K4), 35, 9, 2, 200, 0 },

  { 101,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /K2/Gain",
    offsetof(P_ctrl_TAPM2_T, Nonlinearpassiveobserver_w_c), 35, 9, 2, 202, 0 },

  { 102, "ctrl_tapm2/X-position Thruster1/Value", offsetof(P_ctrl_TAPM2_T,
    XpositionThruster1_Value), 36, 12, 2, 204, 0 },

  { 103, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 1/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation1_UpperSat), 53, 1, 2, 206, 0 },

  { 104, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 1/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation1_LowerSat), 53, 1, 2, 208, 0 },

  { 105,
    "ctrl_tapm2/Thruster control /Thruster 1/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC), 53, 1, 2, 210, 0 },

  { 106, "ctrl_tapm2/Thruster control /Thruster 1/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM2_T, Lossesplaceholder_Value), 53, 1, 2, 212, 0 },

  { 107,
    "ctrl_tapm2/Thruster control /Thruster 2/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_f), 53, 1, 2, 214, 0 },

  { 108, "ctrl_tapm2/Thruster control /Thruster 2/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM2_T, Lossesplaceholder_Value_k), 53, 1, 2, 216, 0 },

  { 109,
    "ctrl_tapm2/Thruster control /Thruster 3/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_p), 53, 1, 2, 218, 0 },

  { 110, "ctrl_tapm2/Thruster control /Thruster 3/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM2_T, Lossesplaceholder_Value_n), 53, 1, 2, 220, 0 },

  { 111,
    "ctrl_tapm2/Thruster control /Thruster 4/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_fv), 53, 1, 2, 222, 0 },

  { 112, "ctrl_tapm2/Thruster control /Thruster 4/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM2_T, Lossesplaceholder_Value_d), 53, 1, 2, 224, 0 },

  { 113,
    "ctrl_tapm2/Thruster control /Thruster 5/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_l), 53, 1, 2, 226, 0 },

  { 114, "ctrl_tapm2/Thruster control /Thruster 5/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM2_T, Lossesplaceholder_Value_f), 53, 1, 2, 228, 0 },

  { 115,
    "ctrl_tapm2/Thruster control /Thruster 6/Shaft dynamics/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_li), 53, 1, 2, 230, 0 },

  { 116, "ctrl_tapm2/Thruster control /Thruster 6/Losses (placeholder)/Value",
    offsetof(P_ctrl_TAPM2_T, Lossesplaceholder_Value_h), 53, 1, 2, 232, 0 },

  { 117, "ctrl_tapm2/Thruster control /Subsystem/Constant12/Value", offsetof
    (P_ctrl_TAPM2_T, Constant12_Value), 53, 1, 2, 234, 0 },

  { 118, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 2/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation2_UpperSat), 53, 1, 2, 236, 0 },

  { 119, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 2/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation2_LowerSat), 53, 1, 2, 238, 0 },

  { 120, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 3/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation3_UpperSat), 53, 1, 2, 240, 0 },

  { 121, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 3/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation3_LowerSat), 53, 1, 2, 242, 0 },

  { 122, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 4/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation4_UpperSat), 53, 1, 2, 244, 0 },

  { 123, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 4/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation4_LowerSat), 53, 1, 2, 246, 0 },

  { 124, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 5/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation5_UpperSat), 53, 1, 2, 248, 0 },

  { 125, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 5/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation5_LowerSat), 53, 1, 2, 250, 0 },

  { 126, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 6/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation6_UpperSat), 53, 1, 2, 252, 0 },

  { 127, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 6/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation6_LowerSat), 53, 1, 2, 254, 0 },

  { 128, "ctrl_tapm2/Radians to Degrees/Gain/Gain", offsetof(P_ctrl_TAPM2_T,
    Gain_Gain), 53, 1, 2, 256, 0 },

  { 129, "ctrl_tapm2/X-position Thruster/Value", offsetof(P_ctrl_TAPM2_T,
    XpositionThruster_Value), 33, 6, 2, 258, 0 },

  { 130, "ctrl_tapm2/Y-position Thruster/Value", offsetof(P_ctrl_TAPM2_T,
    YpositionThruster_Value), 33, 6, 2, 260, 0 },

  { 131, "ctrl_tapm2/Thruster control /Delay/InitialCondition", offsetof
    (P_ctrl_TAPM2_T, Delay_InitialCondition), 53, 1, 2, 262, 0 },

  { 132, "ctrl_tapm2/Thruster control /Thruster 1/Constant/Value", offsetof
    (P_ctrl_TAPM2_T, Constant_Value), 37, 2, 2, 264, 0 },

  { 133, "ctrl_tapm2/Thruster control /Thruster 1/Constant1/Value", offsetof
    (P_ctrl_TAPM2_T, Constant1_Value), 37, 2, 2, 266, 0 },

  { 134, "ctrl_tapm2/Thruster control /Thruster 1/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Delay_InitialCondition_i), 53, 1, 2, 268, 0 },

  { 135,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Delay_InitialCondition_f), 53, 1, 2, 270, 0 },

  { 136,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM2_T, Constant1_Value_o), 30, 3, 2, 272, 0 },

  { 137,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM2_T, Constant2_Value), 30, 3, 2, 274, 0 },

  { 138,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM2_T, DiscreteTransferFcn_InitialStat), 53, 1, 2, 276, 0
  },

  { 139,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM2_T, TSamp_WtEt), 0, 1, 2, 278, 0 },

  { 140,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_ctrl_TAPM2_T, AccelerationLimit_RisingLim), 0, 1, 2, 280, 0 },

  { 141,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_ctrl_TAPM2_T, AccelerationLimit_FallingLim), 0, 1, 2, 282, 0 },

  { 142,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, AccelerationLimit_IC), 53, 1, 2, 284, 0 },

  { 143, "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM2_T, Memory_X0), 53, 1, 2, 286, 0 },

  { 144,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_a), 53, 1, 2, 288, 0 },

  { 145, "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM2_T, NaN_Value), 53, 1, 2, 290, 0 },

  { 146,
    "ctrl_tapm2/Thruster control /Thruster 1/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM2_T, DiscreteTransferFcn_InitialSt_h), 53, 1, 2, 292, 0
  },

  { 147, "ctrl_tapm2/Thruster control /Thruster 2/Constant/Value", offsetof
    (P_ctrl_TAPM2_T, Constant_Value_h), 37, 2, 2, 294, 0 },

  { 148, "ctrl_tapm2/Thruster control /Thruster 2/Constant1/Value", offsetof
    (P_ctrl_TAPM2_T, Constant1_Value_j), 37, 2, 2, 296, 0 },

  { 149, "ctrl_tapm2/Thruster control /Thruster 2/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Delay_InitialCondition_l), 53, 1, 2, 298, 0 },

  { 150,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Delay_InitialCondition_iv), 53, 1, 2, 300, 0 },

  { 151,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM2_T, Constant1_Value_b), 30, 3, 2, 302, 0 },

  { 152,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM2_T, Constant2_Value_i), 30, 3, 2, 304, 0 },

  { 153,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM2_T, DiscreteTransferFcn_InitialS_hu), 53, 1, 2, 306, 0
  },

  { 154,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM2_T, TSamp_WtEt_k), 0, 1, 2, 308, 0 },

  { 155,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Acceleration Limit/RisingSlewLimit",
    offsetof(P_ctrl_TAPM2_T, AccelerationLimit_RisingLim_n), 0, 1, 2, 310, 0 },

  { 156,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Acceleration Limit/FallingSlewLimit",
    offsetof(P_ctrl_TAPM2_T, AccelerationLimit_FallingLim_n), 0, 1, 2, 312, 0 },

  { 157,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Acceleration Limit/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, AccelerationLimit_IC_m), 53, 1, 2, 314, 0 },

  { 158, "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM2_T, Memory_X0_e), 53, 1, 2, 316, 0 },

  { 159,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_fy), 53, 1, 2, 318, 0 },

  { 160, "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM2_T, NaN_Value_l), 53, 1, 2, 320, 0 },

  { 161,
    "ctrl_tapm2/Thruster control /Thruster 2/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM2_T, DiscreteTransferFcn_InitialSt_f), 53, 1, 2, 322, 0
  },

  { 162, "ctrl_tapm2/Thruster control /Thruster 3/Constant/Value", offsetof
    (P_ctrl_TAPM2_T, Constant_Value_n), 37, 2, 2, 324, 0 },

  { 163, "ctrl_tapm2/Thruster control /Thruster 3/Constant1/Value", offsetof
    (P_ctrl_TAPM2_T, Constant1_Value_a), 37, 2, 2, 326, 0 },

  { 164, "ctrl_tapm2/Thruster control /Thruster 3/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Delay_InitialCondition_d), 53, 1, 2, 328, 0 },

  { 165,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Delay_InitialCondition_h), 53, 1, 2, 330, 0 },

  { 166,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM2_T, Constant1_Value_g), 30, 3, 2, 332, 0 },

  { 167,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM2_T, Constant2_Value_h), 30, 3, 2, 334, 0 },

  { 168,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM2_T, DiscreteTransferFcn_InitialSt_a), 53, 1, 2, 336, 0
  },

  { 169,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM2_T, TSamp_WtEt_m), 0, 1, 2, 338, 0 },

  { 170,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM2_T, Accelerationlimiter_RisingLim), 0, 1, 2, 340, 0 },

  { 171,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM2_T, Accelerationlimiter_FallingLim), 0, 1, 2, 342, 0 },

  { 172,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Accelerationlimiter_IC), 53, 1, 2, 344, 0 },

  { 173, "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM2_T, Memory_X0_g), 53, 1, 2, 346, 0 },

  { 174,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_j), 53, 1, 2, 348, 0 },

  { 175, "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM2_T, NaN_Value_g), 53, 1, 2, 350, 0 },

  { 176,
    "ctrl_tapm2/Thruster control /Thruster 3/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM2_T, DiscreteTransferFcn_InitialSt_c), 53, 1, 2, 352, 0
  },

  { 177, "ctrl_tapm2/Thruster control /Thruster 4/Constant/Value", offsetof
    (P_ctrl_TAPM2_T, Constant_Value_j), 37, 2, 2, 354, 0 },

  { 178, "ctrl_tapm2/Thruster control /Thruster 4/Constant1/Value", offsetof
    (P_ctrl_TAPM2_T, Constant1_Value_oi), 37, 2, 2, 356, 0 },

  { 179, "ctrl_tapm2/Thruster control /Thruster 4/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Delay_InitialCondition_fb), 53, 1, 2, 358, 0 },

  { 180,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Delay_InitialCondition_g), 53, 1, 2, 360, 0 },

  { 181,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM2_T, Constant1_Value_m), 30, 3, 2, 362, 0 },

  { 182,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM2_T, Constant2_Value_l), 30, 3, 2, 364, 0 },

  { 183,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM2_T, DiscreteTransferFcn_InitialS_a1), 53, 1, 2, 366, 0
  },

  { 184,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM2_T, TSamp_WtEt_h), 0, 1, 2, 368, 0 },

  { 185,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM2_T, Accelerationlimiter_RisingLim_e), 0, 1, 2, 370, 0 },

  { 186,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM2_T, Accelerationlimiter_FallingLi_b), 0, 1, 2, 372, 0 },

  { 187,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Accelerationlimiter_IC_h), 53, 1, 2, 374, 0 },

  { 188, "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM2_T, Memory_X0_k), 53, 1, 2, 376, 0 },

  { 189,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_g), 53, 1, 2, 378, 0 },

  { 190, "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM2_T, NaN_Value_p), 53, 1, 2, 380, 0 },

  { 191,
    "ctrl_tapm2/Thruster control /Thruster 4/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM2_T, DiscreteTransferFcn_InitialSt_p), 53, 1, 2, 382, 0
  },

  { 192, "ctrl_tapm2/Thruster control /Thruster 5/Constant/Value", offsetof
    (P_ctrl_TAPM2_T, Constant_Value_i), 37, 2, 2, 384, 0 },

  { 193, "ctrl_tapm2/Thruster control /Thruster 5/Constant1/Value", offsetof
    (P_ctrl_TAPM2_T, Constant1_Value_h), 37, 2, 2, 386, 0 },

  { 194, "ctrl_tapm2/Thruster control /Thruster 5/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Delay_InitialCondition_fv), 53, 1, 2, 388, 0 },

  { 195,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Delay_InitialCondition_dz), 53, 1, 2, 390, 0 },

  { 196,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM2_T, Constant1_Value_mk), 30, 3, 2, 392, 0 },

  { 197,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM2_T, Constant2_Value_p), 30, 3, 2, 394, 0 },

  { 198,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM2_T, DiscreteTransferFcn_InitialSt_e), 53, 1, 2, 396, 0
  },

  { 199,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM2_T, TSamp_WtEt_o), 0, 1, 2, 398, 0 },

  { 200,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM2_T, Accelerationlimiter_RisingLim_b), 0, 1, 2, 400, 0 },

  { 201,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM2_T, Accelerationlimiter_FallingLi_d), 0, 1, 2, 402, 0 },

  { 202,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Accelerationlimiter_IC_i), 53, 1, 2, 404, 0 },

  { 203, "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM2_T, Memory_X0_k3), 53, 1, 2, 406, 0 },

  { 204,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_aj), 53, 1, 2, 408, 0 },

  { 205, "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM2_T, NaN_Value_lq), 53, 1, 2, 410, 0 },

  { 206,
    "ctrl_tapm2/Thruster control /Thruster 5/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM2_T, DiscreteTransferFcn_InitialS_pj), 53, 1, 2, 412, 0
  },

  { 207, "ctrl_tapm2/Thruster control /Thruster 6/Constant/Value", offsetof
    (P_ctrl_TAPM2_T, Constant_Value_ht), 37, 2, 2, 414, 0 },

  { 208, "ctrl_tapm2/Thruster control /Thruster 6/Constant1/Value", offsetof
    (P_ctrl_TAPM2_T, Constant1_Value_gs), 37, 2, 2, 416, 0 },

  { 209, "ctrl_tapm2/Thruster control /Thruster 6/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Delay_InitialCondition_fi), 53, 1, 2, 418, 0 },

  { 210,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Delay/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Delay_InitialCondition_a), 53, 1, 2, 420, 0 },

  { 211,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Constant1/Value",
    offsetof(P_ctrl_TAPM2_T, Constant1_Value_oa), 30, 3, 2, 422, 0 },

  { 212,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Constant2/Value",
    offsetof(P_ctrl_TAPM2_T, Constant2_Value_p3), 30, 3, 2, 424, 0 },

  { 213,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM2_T, DiscreteTransferFcn_InitialS_a4), 53, 1, 2, 426, 0
  },

  { 214,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp/WtEt",
    offsetof(P_ctrl_TAPM2_T, TSamp_WtEt_kk), 0, 1, 2, 428, 0 },

  { 215,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Acceleration limiter/RisingSlewLimit",
    offsetof(P_ctrl_TAPM2_T, Accelerationlimiter_RisingLi_bi), 0, 1, 2, 430, 0 },

  { 216,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Acceleration limiter/FallingSlewLimit",
    offsetof(P_ctrl_TAPM2_T, Accelerationlimiter_FallingLi_p), 0, 1, 2, 432, 0 },

  { 217,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Acceleration limiter/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Accelerationlimiter_IC_p), 53, 1, 2, 434, 0 },

  { 218, "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Memory/X0",
    offsetof(P_ctrl_TAPM2_T, Memory_X0_c), 53, 1, 2, 436, 0 },

  { 219,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Core controller/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_h), 53, 1, 2, 438, 0 },

  { 220, "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/NaN/Value",
    offsetof(P_ctrl_TAPM2_T, NaN_Value_j), 53, 1, 2, 440, 0 },

  { 221,
    "ctrl_tapm2/Thruster control /Thruster 6/Discrete Transfer Fcn/Numerator",
    offsetof(P_ctrl_TAPM2_T, DiscreteTransferFcn_InitialSt_b), 53, 1, 2, 442, 0
  },

  { 222,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_i), 25, 3, 2, 444, 0 },

  { 223,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Integrator4/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator4_IC), 25, 3, 2, 446, 0 },

  { 224,
    "ctrl_tapm2/TAPM Controller w_observer/SP Generator/Integrator/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator_IC_b), 37, 2, 2, 448, 0 },

  { 225, "ctrl_tapm2/TAPM Controller w_observer/SP Generator/Transfer Fcn2/A",
    offsetof(P_ctrl_TAPM2_T, TransferFcn2_A), 53, 1, 2, 450, 0 },

  { 226, "ctrl_tapm2/TAPM Controller w_observer/SP Generator/Transfer Fcn2/C",
    offsetof(P_ctrl_TAPM2_T, TransferFcn2_C), 53, 1, 2, 452, 0 },

  { 227,
    "ctrl_tapm2/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation_UpperSat), 53, 1, 2, 454, 0 },

  { 228,
    "ctrl_tapm2/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_TAPM2_T, Saturation_LowerSat), 53, 1, 2, 456, 0 },

  { 229,
    "ctrl_tapm2/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_TAPM2_T, Gain_Gain_p), 53, 1, 2, 458, 0 },

  { 230,
    "ctrl_tapm2/TAPM Controller w_observer/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_TAPM2_T, Constant_Value_k), 53, 1, 2, 460, 0 },

  { 231,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Integrator1/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator1_IC), 53, 1, 2, 462, 0 },

  { 232,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Gain1/Gain",
    offsetof(P_ctrl_TAPM2_T, Gain1_Gain), 35, 9, 2, 464, 0 },

  { 233,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Integrator2/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator2_IC), 53, 1, 2, 466, 0 },

  { 234,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Gain2/Gain",
    offsetof(P_ctrl_TAPM2_T, Gain2_Gain), 35, 9, 2, 468, 0 },

  { 235,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Integrator3/InitialCondition",
    offsetof(P_ctrl_TAPM2_T, Integrator3_IC), 53, 1, 2, 470, 0 },

  { 236,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Gain3/Gain",
    offsetof(P_ctrl_TAPM2_T, Gain3_Gain), 35, 9, 2, 472, 0 },

  { 237,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /K11/Gain",
    offsetof(P_ctrl_TAPM2_T, K11_Gain), 35, 9, 2, 474, 0 },

  { 238,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /K12/Gain",
    offsetof(P_ctrl_TAPM2_T, K12_Gain), 35, 9, 2, 476, 0 },

  { 239,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /inv(T_b)/Gain",
    offsetof(P_ctrl_TAPM2_T, invT_b_Gain), 35, 9, 2, 478, 0 },

  { 240, "ctrl_tapm2/TAPM Controller w_observer/SP Generator/Constant1/Value",
    offsetof(P_ctrl_TAPM2_T, Constant1_Value_p), 53, 1, 2, 480, 0 },

  { 241, "ctrl_tapm2/TAPM Controller w_observer/SP Generator/Gain/Gain",
    offsetof(P_ctrl_TAPM2_T, Gain_Gain_d), 38, 4, 2, 482, 0 },

  { 242, "ctrl_tapm2/TAPM Controller w_observer/SP Generator/Gain1/Gain",
    offsetof(P_ctrl_TAPM2_T, Gain1_Gain_i), 38, 4, 2, 484, 0 },

  { 243, "ctrl_tapm2/Input/deg2rad/Gain", offsetof(P_ctrl_TAPM2_T, deg2rad_Gain),
    53, 1, 2, 486, 0 },

  { 244, "ctrl_tapm2/TAPM Controller w_observer/Constant/Value", offsetof
    (P_ctrl_TAPM2_T, Constant_Value_hs), 30, 3, 2, 488, 0 },

  { 245, "ctrl_tapm2/TAPM Controller w_observer/Gain/Gain", offsetof
    (P_ctrl_TAPM2_T, Gain_Gain_l), 25, 3, 2, 490, 0 },

  { 246, "ctrl_tapm2/Thruster control /Delay/DelayLength", offsetof
    (P_ctrl_TAPM2_T, Delay_DelayLength), 54, 1, 2, 492, 0 },

  { 247, "ctrl_tapm2/Thruster control /Thruster 1/Delay/DelayLength", offsetof
    (P_ctrl_TAPM2_T, Delay_DelayLength_d), 54, 1, 2, 494, 0 },

  { 248,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM2_T, Delay_DelayLength_f), 54, 1, 2, 496, 0 },

  { 249, "ctrl_tapm2/Thruster control /Thruster 2/Delay/DelayLength", offsetof
    (P_ctrl_TAPM2_T, Delay_DelayLength_m), 54, 1, 2, 498, 0 },

  { 250,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM2_T, Delay_DelayLength_p), 54, 1, 2, 500, 0 },

  { 251, "ctrl_tapm2/Thruster control /Thruster 3/Delay/DelayLength", offsetof
    (P_ctrl_TAPM2_T, Delay_DelayLength_h), 54, 1, 2, 502, 0 },

  { 252,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM2_T, Delay_DelayLength_b), 54, 1, 2, 504, 0 },

  { 253, "ctrl_tapm2/Thruster control /Thruster 4/Delay/DelayLength", offsetof
    (P_ctrl_TAPM2_T, Delay_DelayLength_n), 54, 1, 2, 506, 0 },

  { 254,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM2_T, Delay_DelayLength_mj), 54, 1, 2, 508, 0 },

  { 255, "ctrl_tapm2/Thruster control /Thruster 5/Delay/DelayLength", offsetof
    (P_ctrl_TAPM2_T, Delay_DelayLength_a), 54, 1, 2, 510, 0 },

  { 256,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM2_T, Delay_DelayLength_k), 54, 1, 2, 512, 0 },

  { 257, "ctrl_tapm2/Thruster control /Thruster 6/Delay/DelayLength", offsetof
    (P_ctrl_TAPM2_T, Delay_DelayLength_l), 54, 1, 2, 514, 0 },

  { 258,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Delay/DelayLength",
    offsetof(P_ctrl_TAPM2_T, Delay_DelayLength_c), 54, 1, 2, 516, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 259;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
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
  1, 6,                                /* Parameter at index 86 */
  1, 6,                                /* Parameter at index 87 */
  1, 6,                                /* Parameter at index 88 */
  1, 6,                                /* Parameter at index 89 */
  1, 6,                                /* Parameter at index 90 */
  1, 6,                                /* Parameter at index 91 */
  3, 3,                                /* Parameter at index 92 */
  1, 1,                                /* Parameter at index 93 */
  1, 1,                                /* Parameter at index 94 */
  1, 1,                                /* Parameter at index 95 */
  1, 1,                                /* Parameter at index 96 */
  1, 1,                                /* Parameter at index 97 */
  1, 1,                                /* Parameter at index 98 */
  3, 3,                                /* Parameter at index 99 */
  3, 3,                                /* Parameter at index 100 */
  3, 3,                                /* Parameter at index 101 */
  12, 1,                               /* Parameter at index 102 */
  1, 1,                                /* Parameter at index 103 */
  1, 1,                                /* Parameter at index 104 */
  1, 1,                                /* Parameter at index 105 */
  1, 1,                                /* Parameter at index 106 */
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
  1, 1,                                /* Parameter at index 121 */
  1, 1,                                /* Parameter at index 122 */
  1, 1,                                /* Parameter at index 123 */
  1, 1,                                /* Parameter at index 124 */
  1, 1,                                /* Parameter at index 125 */
  1, 1,                                /* Parameter at index 126 */
  1, 1,                                /* Parameter at index 127 */
  1, 1,                                /* Parameter at index 128 */
  1, 6,                                /* Parameter at index 129 */
  1, 6,                                /* Parameter at index 130 */
  1, 1,                                /* Parameter at index 131 */
  1, 2,                                /* Parameter at index 132 */
  1, 2,                                /* Parameter at index 133 */
  1, 1,                                /* Parameter at index 134 */
  1, 1,                                /* Parameter at index 135 */
  1, 3,                                /* Parameter at index 136 */
  1, 3,                                /* Parameter at index 137 */
  1, 1,                                /* Parameter at index 138 */
  1, 1,                                /* Parameter at index 139 */
  1, 1,                                /* Parameter at index 140 */
  1, 1,                                /* Parameter at index 141 */
  1, 1,                                /* Parameter at index 142 */
  1, 1,                                /* Parameter at index 143 */
  1, 1,                                /* Parameter at index 144 */
  1, 1,                                /* Parameter at index 145 */
  1, 1,                                /* Parameter at index 146 */
  1, 2,                                /* Parameter at index 147 */
  1, 2,                                /* Parameter at index 148 */
  1, 1,                                /* Parameter at index 149 */
  1, 1,                                /* Parameter at index 150 */
  1, 3,                                /* Parameter at index 151 */
  1, 3,                                /* Parameter at index 152 */
  1, 1,                                /* Parameter at index 153 */
  1, 1,                                /* Parameter at index 154 */
  1, 1,                                /* Parameter at index 155 */
  1, 1,                                /* Parameter at index 156 */
  1, 1,                                /* Parameter at index 157 */
  1, 1,                                /* Parameter at index 158 */
  1, 1,                                /* Parameter at index 159 */
  1, 1,                                /* Parameter at index 160 */
  1, 1,                                /* Parameter at index 161 */
  1, 2,                                /* Parameter at index 162 */
  1, 2,                                /* Parameter at index 163 */
  1, 1,                                /* Parameter at index 164 */
  1, 1,                                /* Parameter at index 165 */
  1, 3,                                /* Parameter at index 166 */
  1, 3,                                /* Parameter at index 167 */
  1, 1,                                /* Parameter at index 168 */
  1, 1,                                /* Parameter at index 169 */
  1, 1,                                /* Parameter at index 170 */
  1, 1,                                /* Parameter at index 171 */
  1, 1,                                /* Parameter at index 172 */
  1, 1,                                /* Parameter at index 173 */
  1, 1,                                /* Parameter at index 174 */
  1, 1,                                /* Parameter at index 175 */
  1, 1,                                /* Parameter at index 176 */
  1, 2,                                /* Parameter at index 177 */
  1, 2,                                /* Parameter at index 178 */
  1, 1,                                /* Parameter at index 179 */
  1, 1,                                /* Parameter at index 180 */
  1, 3,                                /* Parameter at index 181 */
  1, 3,                                /* Parameter at index 182 */
  1, 1,                                /* Parameter at index 183 */
  1, 1,                                /* Parameter at index 184 */
  1, 1,                                /* Parameter at index 185 */
  1, 1,                                /* Parameter at index 186 */
  1, 1,                                /* Parameter at index 187 */
  1, 1,                                /* Parameter at index 188 */
  1, 1,                                /* Parameter at index 189 */
  1, 1,                                /* Parameter at index 190 */
  1, 1,                                /* Parameter at index 191 */
  1, 2,                                /* Parameter at index 192 */
  1, 2,                                /* Parameter at index 193 */
  1, 1,                                /* Parameter at index 194 */
  1, 1,                                /* Parameter at index 195 */
  1, 3,                                /* Parameter at index 196 */
  1, 3,                                /* Parameter at index 197 */
  1, 1,                                /* Parameter at index 198 */
  1, 1,                                /* Parameter at index 199 */
  1, 1,                                /* Parameter at index 200 */
  1, 1,                                /* Parameter at index 201 */
  1, 1,                                /* Parameter at index 202 */
  1, 1,                                /* Parameter at index 203 */
  1, 1,                                /* Parameter at index 204 */
  1, 1,                                /* Parameter at index 205 */
  1, 1,                                /* Parameter at index 206 */
  1, 2,                                /* Parameter at index 207 */
  1, 2,                                /* Parameter at index 208 */
  1, 1,                                /* Parameter at index 209 */
  1, 1,                                /* Parameter at index 210 */
  1, 3,                                /* Parameter at index 211 */
  1, 3,                                /* Parameter at index 212 */
  1, 1,                                /* Parameter at index 213 */
  1, 1,                                /* Parameter at index 214 */
  1, 1,                                /* Parameter at index 215 */
  1, 1,                                /* Parameter at index 216 */
  1, 1,                                /* Parameter at index 217 */
  1, 1,                                /* Parameter at index 218 */
  1, 1,                                /* Parameter at index 219 */
  1, 1,                                /* Parameter at index 220 */
  1, 1,                                /* Parameter at index 221 */
  3, 1,                                /* Parameter at index 222 */
  3, 1,                                /* Parameter at index 223 */
  1, 2,                                /* Parameter at index 224 */
  1, 1,                                /* Parameter at index 225 */
  1, 1,                                /* Parameter at index 226 */
  1, 1,                                /* Parameter at index 227 */
  1, 1,                                /* Parameter at index 228 */
  1, 1,                                /* Parameter at index 229 */
  1, 1,                                /* Parameter at index 230 */
  1, 1,                                /* Parameter at index 231 */
  3, 3,                                /* Parameter at index 232 */
  1, 1,                                /* Parameter at index 233 */
  3, 3,                                /* Parameter at index 234 */
  1, 1,                                /* Parameter at index 235 */
  3, 3,                                /* Parameter at index 236 */
  3, 3,                                /* Parameter at index 237 */
  3, 3,                                /* Parameter at index 238 */
  3, 3,                                /* Parameter at index 239 */
  1, 1,                                /* Parameter at index 240 */
  2, 2,                                /* Parameter at index 241 */
  2, 2,                                /* Parameter at index 242 */
  1, 1,                                /* Parameter at index 243 */
  1, 3,                                /* Parameter at index 244 */
  3, 1,                                /* Parameter at index 245 */
  1, 1,                                /* Parameter at index 246 */
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
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 1", 0, "", offsetof
    (B_ctrl_TAPM2_T, Saturation1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 1, "ctrl_tapm2/Thruster control /Thruster 1/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM2_T, reset) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 2, "ctrl_tapm2/Thruster control /Thruster 1/Shaft dynamics/Integrator", 0,
    "", offsetof(B_ctrl_TAPM2_T, Integrator) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 3, "ctrl_tapm2/Thruster control /Thruster 2/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM2_T, reset_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 4, "ctrl_tapm2/Thruster control /Thruster 2/Shaft dynamics/Integrator", 0,
    "", offsetof(B_ctrl_TAPM2_T, Integrator_h) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 5, "ctrl_tapm2/Thruster control /Thruster 3/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM2_T, reset_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 6, "ctrl_tapm2/Thruster control /Thruster 3/Shaft dynamics/Integrator", 0,
    "", offsetof(B_ctrl_TAPM2_T, Integrator_a) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 7, "ctrl_tapm2/Thruster control /Thruster 4/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM2_T, reset_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 8, "ctrl_tapm2/Thruster control /Thruster 4/Shaft dynamics/Integrator", 0,
    "", offsetof(B_ctrl_TAPM2_T, Integrator_k) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 9, "ctrl_tapm2/Thruster control /Thruster 5/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM2_T, reset_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 10, "ctrl_tapm2/Thruster control /Thruster 5/Shaft dynamics/Integrator", 0,
    "", offsetof(B_ctrl_TAPM2_T, Integrator_c) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 11, "ctrl_tapm2/Thruster control /Thruster 6/Shaft dynamics/reset", 0, "",
    offsetof(B_ctrl_TAPM2_T, reset_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 12, "ctrl_tapm2/Thruster control /Thruster 6/Shaft dynamics/Integrator", 0,
    "", offsetof(B_ctrl_TAPM2_T, Integrator_m) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 13, "ctrl_tapm2/Thruster control /Subsystem/pwm thruster 2", 0, "", offsetof
    (B_ctrl_TAPM2_T, pwmthruster2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 14, "ctrl_tapm2/Thruster control /Subsystem/pwm thruster 3", 0, "", offsetof
    (B_ctrl_TAPM2_T, pwmthruster3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 15, "ctrl_tapm2/Thruster control /Subsystem/pwm thruster 4", 0, "", offsetof
    (B_ctrl_TAPM2_T, pwmthruster4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 16, "ctrl_tapm2/Thruster control /Subsystem/pwm thruster 5", 0, "", offsetof
    (B_ctrl_TAPM2_T, pwmthruster5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 17, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 2", 0, "", offsetof
    (B_ctrl_TAPM2_T, Saturation2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 18, "ctrl_tapm2/Thruster control /Subsystem/pwm thruster 6", 0, "", offsetof
    (B_ctrl_TAPM2_T, pwmthruster6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 19, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 3", 0, "", offsetof
    (B_ctrl_TAPM2_T, Saturation3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 20, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 4", 0, "", offsetof
    (B_ctrl_TAPM2_T, Saturation4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 21, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 5", 0, "", offsetof
    (B_ctrl_TAPM2_T, Saturation5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 22, "ctrl_tapm2/Thruster control /Subsystem1/Saturation 6", 0, "", offsetof
    (B_ctrl_TAPM2_T, Saturation6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 23, "ctrl_tapm2/Thruster control /Subsystem/Saturation 7/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM2_T, Saturation7) + (0*sizeof(real_T)), BLOCKIO_SIG, 21,
    1, 2, 0, 0 },

  { 24, "ctrl_tapm2/Thruster control /Subsystem/Saturation 7/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM2_T, Saturation7) + (1*sizeof(real_T)), BLOCKIO_SIG, 21,
    1, 2, 0, 0 },

  { 25, "ctrl_tapm2/Thruster control /Subsystem/Saturation 7/(1, 3)", 0, "",
    offsetof(B_ctrl_TAPM2_T, Saturation7) + (2*sizeof(real_T)), BLOCKIO_SIG, 21,
    1, 2, 0, 0 },

  { 26, "ctrl_tapm2/Thruster control /Subsystem/Saturation 7/(1, 4)", 0, "",
    offsetof(B_ctrl_TAPM2_T, Saturation7) + (3*sizeof(real_T)), BLOCKIO_SIG, 21,
    1, 2, 0, 0 },

  { 27, "ctrl_tapm2/Thruster control /Subsystem/Saturation 7/(1, 5)", 0, "",
    offsetof(B_ctrl_TAPM2_T, Saturation7) + (4*sizeof(real_T)), BLOCKIO_SIG, 21,
    1, 2, 0, 0 },

  { 28, "ctrl_tapm2/Thruster control /Subsystem/Saturation 7/(1, 6)", 0, "",
    offsetof(B_ctrl_TAPM2_T, Saturation7) + (5*sizeof(real_T)), BLOCKIO_SIG, 21,
    1, 2, 0, 0 },

  { 29, "ctrl_tapm2/Thruster control /Subsystem/pwm thruster 1", 0, "", offsetof
    (B_ctrl_TAPM2_T, pwmthruster1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 30, "ctrl_tapm2/Radians to Degrees/Gain/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM2_T, Gain) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 31, "ctrl_tapm2/Radians to Degrees/Gain/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM2_T, Gain) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 32, "ctrl_tapm2/Radians to Degrees/Gain/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM2_T, Gain) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 33, "ctrl_tapm2/Radians to Degrees/Gain/(1, 4)", 0, "", offsetof
    (B_ctrl_TAPM2_T, Gain) + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 34, "ctrl_tapm2/Radians to Degrees/Gain/(1, 5)", 0, "", offsetof
    (B_ctrl_TAPM2_T, Gain) + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 35, "ctrl_tapm2/Radians to Degrees/Gain/(1, 6)", 0, "", offsetof
    (B_ctrl_TAPM2_T, Gain) + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0 },

  { 36, "ctrl_tapm2/Thruster control /Thruster 1/Delay", 0, "", offsetof
    (B_ctrl_TAPM2_T, Delay) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 37,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM2_T, DiscreteTransferFcn) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 38,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM2_T, TSamp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 39,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM2_T, Inertiacompensation) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 40, "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 41, "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM2_T, Memory) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 42,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM2_T, Kp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 43,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM2_T, reset_kk) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 44, "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 45, "ctrl_tapm2/Thruster control /Thruster 1/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM2_T, DiscreteTransferFcn_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 46,
    "ctrl_tapm2/Thruster control /Thruster 1/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM2_T, Findingrotationspeed) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 47,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM2_T, Ki) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 48, "ctrl_tapm2/Thruster control /Thruster 2/Delay", 0, "", offsetof
    (B_ctrl_TAPM2_T, Delay_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 49,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM2_T, DiscreteTransferFcn_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 50,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM2_T, TSamp_n) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 51,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM2_T, Inertiacompensation_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 52, "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum1_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 53, "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM2_T, Memory_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 54,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM2_T, Kp_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 55,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM2_T, reset_e) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 56, "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 57, "ctrl_tapm2/Thruster control /Thruster 2/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM2_T, DiscreteTransferFcn_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 58,
    "ctrl_tapm2/Thruster control /Thruster 2/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM2_T, Findingrotationspeed_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 59,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM2_T, Ki_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 60, "ctrl_tapm2/Thruster control /Thruster 3/Delay", 0, "", offsetof
    (B_ctrl_TAPM2_T, Delay_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 61,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM2_T, DiscreteTransferFcn_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 62,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM2_T, TSamp_k) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 63,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM2_T, Inertiacompensation_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 64, "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum1_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 65, "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM2_T, Memory_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 66,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM2_T, Kp_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 67,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM2_T, reset_j2) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 68, "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum_hf) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 69, "ctrl_tapm2/Thruster control /Thruster 3/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM2_T, DiscreteTransferFcn_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 70,
    "ctrl_tapm2/Thruster control /Thruster 3/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM2_T, Findingrotationspeed_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 71,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM2_T, Ki_n) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 72, "ctrl_tapm2/Thruster control /Thruster 4/Delay", 0, "", offsetof
    (B_ctrl_TAPM2_T, Delay_g) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 73,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM2_T, DiscreteTransferFcn_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 74,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM2_T, TSamp_a) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 75,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM2_T, Inertiacompensation_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 76, "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum1_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 77, "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM2_T, Memory_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 78,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM2_T, Kp_c) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 79,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM2_T, reset_n) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 80, "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum_k) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 81, "ctrl_tapm2/Thruster control /Thruster 4/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM2_T, DiscreteTransferFcn_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 82,
    "ctrl_tapm2/Thruster control /Thruster 4/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM2_T, Findingrotationspeed_ms) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 83,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM2_T, Ki_b) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 84, "ctrl_tapm2/Thruster control /Thruster 5/Delay", 0, "", offsetof
    (B_ctrl_TAPM2_T, Delay_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 85,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM2_T, DiscreteTransferFcn_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 86,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM2_T, TSamp_m) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 87,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM2_T, Inertiacompensation_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 88, "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum1_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 89, "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Memory", 0, "",
    offsetof(B_ctrl_TAPM2_T, Memory_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 90,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM2_T, Kp_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 91,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM2_T, reset_f) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 92, "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum_i) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 93, "ctrl_tapm2/Thruster control /Thruster 5/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM2_T, DiscreteTransferFcn_lz) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 94,
    "ctrl_tapm2/Thruster control /Thruster 5/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM2_T, Findingrotationspeed_ag) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 95,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM2_T, Ki_a) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 96, "ctrl_tapm2/Thruster control /Thruster 6/Delay", 0, "", offsetof
    (B_ctrl_TAPM2_T, Delay_h) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 97,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Discrete Transfer Fcn",
    0, "", offsetof(B_ctrl_TAPM2_T, DiscreteTransferFcn_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 98,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Discrete Derivative/TSamp",
    0, "", offsetof(B_ctrl_TAPM2_T, TSamp_o) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 99,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Inertia compensation",
    0, "", offsetof(B_ctrl_TAPM2_T, Inertiacompensation_e3) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 100, "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Sum1", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum1_io) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 101, "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Memory", 0,
    "", offsetof(B_ctrl_TAPM2_T, Memory_o) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 102,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Core controller/Kp",
    0, "", offsetof(B_ctrl_TAPM2_T, Kp_l) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 103,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Core controller/reset",
    0, "", offsetof(B_ctrl_TAPM2_T, reset_o) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 104, "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Sum", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum_f) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 105, "ctrl_tapm2/Thruster control /Thruster 6/Discrete Transfer Fcn", 0, "",
    offsetof(B_ctrl_TAPM2_T, DiscreteTransferFcn_ea) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 106,
    "ctrl_tapm2/Thruster control /Thruster 6/Shaft dynamics/Finding rotation speed",
    0, "", offsetof(B_ctrl_TAPM2_T, Findingrotationspeed_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 107,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Core controller/Ki",
    0, "", offsetof(B_ctrl_TAPM2_T, Ki_p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 108, "ctrl_tapm2/Pos measurements/x_m", 0, "", offsetof(B_ctrl_TAPM2_T, x_m)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 109, "ctrl_tapm2/Pos measurements/y_m", 0, "", offsetof(B_ctrl_TAPM2_T, y_m)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 110, "ctrl_tapm2/Pos measurements/psi_m", 0, "", offsetof(B_ctrl_TAPM2_T,
    psi_m) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 111,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Integrator",
    0, "eta(1, 1)", offsetof(B_ctrl_TAPM2_T, eta) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 112,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Integrator",
    0, "eta(2, 1)", offsetof(B_ctrl_TAPM2_T, eta) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 113,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Integrator",
    0, "eta(3, 1)", offsetof(B_ctrl_TAPM2_T, eta) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 114,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Integrator4",
    0, "nu(1, 1)", offsetof(B_ctrl_TAPM2_T, nu) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 115,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Integrator4",
    0, "nu(2, 1)", offsetof(B_ctrl_TAPM2_T, nu) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 116,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Integrator4",
    0, "nu(3, 1)", offsetof(B_ctrl_TAPM2_T, nu) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 117, "ctrl_tapm2/Input/wave_dir", 0, "", offsetof(B_ctrl_TAPM2_T, wave_dir)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 118, "ctrl_tapm2/Input/fzp_x", 0, "", offsetof(B_ctrl_TAPM2_T, fzp_x) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 119, "ctrl_tapm2/Input/fzp_y", 0, "", offsetof(B_ctrl_TAPM2_T, fzp_y) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 120, "ctrl_tapm2/Input/r_max", 0, "", offsetof(B_ctrl_TAPM2_T, r_max) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 121,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Gain3/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM2_T, Gain3) + (0*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 122,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Gain3/(2, 1)",
    0, "", offsetof(B_ctrl_TAPM2_T, Gain3) + (1*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 123,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Gain3/(3, 1)",
    0, "", offsetof(B_ctrl_TAPM2_T, Gain3) + (2*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 124,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Sum3/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM2_T, Sum3) + (0*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 125,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Sum3/(2, 1)",
    0, "", offsetof(B_ctrl_TAPM2_T, Sum3) + (1*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 126,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Sum3/(3, 1)",
    0, "", offsetof(B_ctrl_TAPM2_T, Sum3) + (2*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 127,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Sum5", 0,
    "psi_WF(1, 1)", offsetof(B_ctrl_TAPM2_T, psi_WF) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 128,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Sum5", 0,
    "psi_WF(2, 1)", offsetof(B_ctrl_TAPM2_T, psi_WF) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 129,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Sum5", 0,
    "psi_WF(3, 1)", offsetof(B_ctrl_TAPM2_T, psi_WF) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 130,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Sum6/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM2_T, Sum6) + (0*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 131,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Sum6/(2, 1)",
    0, "", offsetof(B_ctrl_TAPM2_T, Sum6) + (1*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 132,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Sum6/(3, 1)",
    0, "", offsetof(B_ctrl_TAPM2_T, Sum6) + (2*sizeof(real_T)), BLOCKIO_SIG, 25,
    1, 2, 0, 0 },

  { 133,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Sum7/(1, 1)",
    0, "", offsetof(B_ctrl_TAPM2_T, Sum7) + (0*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 134,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Sum7/(1, 2)",
    0, "", offsetof(B_ctrl_TAPM2_T, Sum7) + (1*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 135,
    "ctrl_tapm2/TAPM Controller w_observer/Non-linear passive observer /Sum7/(1, 3)",
    0, "", offsetof(B_ctrl_TAPM2_T, Sum7) + (2*sizeof(real_T)), BLOCKIO_SIG, 22,
    1, 2, 0, 0 },

  { 136, "ctrl_tapm2/TAPM Controller w_observer/SP Generator/Sum", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum_j) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 137, "ctrl_tapm2/TAPM Controller w_observer/SP Generator/Sum1/(1, 1)", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum1_bn) + (0*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 138, "ctrl_tapm2/TAPM Controller w_observer/SP Generator/Sum1/(1, 2)", 0, "",
    offsetof(B_ctrl_TAPM2_T, Sum1_bn) + (1*sizeof(real_T)), BLOCKIO_SIG, 23, 1,
    2, 0, 0 },

  { 139, "ctrl_tapm2/TAPM Controller w_observer/Gain/(1, 1)", 0, "", offsetof
    (B_ctrl_TAPM2_T, Gain_d) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 140, "ctrl_tapm2/TAPM Controller w_observer/Gain/(1, 2)", 0, "", offsetof
    (B_ctrl_TAPM2_T, Gain_d) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 141, "ctrl_tapm2/TAPM Controller w_observer/Gain/(1, 3)", 0, "", offsetof
    (B_ctrl_TAPM2_T, Gain_d) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 142, "ctrl_tapm2/Thruster measurment/thr_angle_1", 0, "", offsetof
    (B_ctrl_TAPM2_T, thr_angle_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 143, "ctrl_tapm2/Thruster measurment/thr_angle_2", 0, "", offsetof
    (B_ctrl_TAPM2_T, thr_angle_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 144, "ctrl_tapm2/Thruster measurment/thr_angle_3", 0, "", offsetof
    (B_ctrl_TAPM2_T, thr_angle_3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 145, "ctrl_tapm2/Thruster measurment/thr_angle_4", 0, "", offsetof
    (B_ctrl_TAPM2_T, thr_angle_4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 146, "ctrl_tapm2/Thruster measurment/thr_angle_5", 0, "", offsetof
    (B_ctrl_TAPM2_T, thr_angle_5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 147, "ctrl_tapm2/Thruster measurment/thr_angle_6", 0, "", offsetof
    (B_ctrl_TAPM2_T, thr_angle_6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 148, "ctrl_tapm2/MATLAB Function", 0, "(1, 1)", offsetof(B_ctrl_TAPM2_T,
    actual_tau) + (0*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 149, "ctrl_tapm2/MATLAB Function", 0, "(1, 2)", offsetof(B_ctrl_TAPM2_T,
    actual_tau) + (1*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 150, "ctrl_tapm2/MATLAB Function", 0, "(1, 3)", offsetof(B_ctrl_TAPM2_T,
    actual_tau) + (2*sizeof(real_T)), BLOCKIO_SIG, 22, 1, 2, 0, 0 },

  { 151, "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Supervisor",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_Supervisor_e.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 152,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePower_nf.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 153,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePower_nf.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 154,
    "ctrl_tapm2/Thruster control /Thruster 6/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePower_nf.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 155,
    "ctrl_tapm2/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_ActualForceandTorque_j.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 156,
    "ctrl_tapm2/Thruster control /Thruster 6/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_ActualForceandTorque_j.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 157, "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Supervisor",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_Supervisor_b.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 158,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_MATLABFunction_j.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 159,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/MATLAB Function",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_MATLABFunction_j.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 160,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePowera_h.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 161,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePowera_h.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 162,
    "ctrl_tapm2/Thruster control /Thruster 5/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePowera_h.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 163,
    "ctrl_tapm2/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_ActualForceandTorque_o.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 164,
    "ctrl_tapm2/Thruster control /Thruster 5/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_ActualForceandTorque_o.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 165, "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Supervisor",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_Supervisor_n.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 166,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_MATLABFunction_g.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 167,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/MATLAB Function",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_MATLABFunction_g.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 168,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePower_n3.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 169,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePower_n3.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 170,
    "ctrl_tapm2/Thruster control /Thruster 4/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePower_n3.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 171,
    "ctrl_tapm2/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_ActualForceandTorque_m.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 172,
    "ctrl_tapm2/Thruster control /Thruster 4/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_ActualForceandTorque_m.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 173, "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Supervisor",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_Supervisor_l.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 174,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_MATLABFunction_m.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 175,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/MATLAB Function",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_MATLABFunction_m.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 176,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePowera_n.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 177,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePowera_n.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 178,
    "ctrl_tapm2/Thruster control /Thruster 3/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePowera_n.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 179,
    "ctrl_tapm2/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_ActualForceandTorque_h.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 180,
    "ctrl_tapm2/Thruster control /Thruster 3/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_ActualForceandTorque_h.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 181, "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Supervisor",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_Supervisor_h.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 182,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/MATLAB Function",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_MATLABFunction_i.n_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 183,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/MATLAB Function",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_MATLABFunction_i.T_r) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 184,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePowera_o.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 185,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePowera_o.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 186,
    "ctrl_tapm2/Thruster control /Thruster 2/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePowera_o.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 187,
    "ctrl_tapm2/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_ActualForceandTorque_f.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 188,
    "ctrl_tapm2/Thruster control /Thruster 2/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_ActualForceandTorque_f.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 189, "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Supervisor",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_Supervisor.u) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 190,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePowerand.Qcq) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 191,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePowerand.Qcp) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 192,
    "ctrl_tapm2/Thruster control /Thruster 1/Thruster control/Core controller/Core controller: Torque,Power and Combined Torque//Power",
    2, "", offsetof(B_ctrl_TAPM2_T, sf_CorecontrollerTorquePowerand.Qcc) + (0*
    sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 193,
    "ctrl_tapm2/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    0, "", offsetof(B_ctrl_TAPM2_T, sf_ActualForceandTorque.Ta) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 194,
    "ctrl_tapm2/Thruster control /Thruster 1/Propeller Hydrodynamics/Actual Force and Torque",
    1, "", offsetof(B_ctrl_TAPM2_T, sf_ActualForceandTorque.Qa) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 195;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 48;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Thruster control /Thruster 1/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1 },

  { 2, "Thruster control /Thruster 2/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1 },

  { 3, "Thruster control /Thruster 3/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1 },

  { 4, "Thruster control /Thruster 4/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1 },

  { 5, "Thruster control /Thruster 5/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1 },

  { 6, "Thruster control /Thruster 6/Shaft dynamics/reset", 0, EXT_IN, 1, 1, 1 },

  { 7, "Thruster control /Thruster 1/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 8, "Thruster control /Thruster 2/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 9, "Thruster control /Thruster 3/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 10, "Thruster control /Thruster 4/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 11, "Thruster control /Thruster 5/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 12, "Thruster control /Thruster 6/Thruster control/Core controller/reset", 0,
    EXT_IN, 1, 1, 1 },

  { 13, "Pos measurements/x_m", 0, EXT_IN, 1, 1, 1 },

  { 14, "Pos measurements/y_m", 0, EXT_IN, 1, 1, 1 },

  { 15, "Pos measurements/psi_m", 0, EXT_IN, 1, 1, 1 },

  { 16, "Input/wave_dir", 0, EXT_IN, 1, 1, 1 },

  { 17, "Input/fzp_x", 0, EXT_IN, 1, 1, 1 },

  { 18, "Input/fzp_y", 0, EXT_IN, 1, 1, 1 },

  { 19, "Input/r_max", 0, EXT_IN, 1, 1, 1 },

  { 20, "Thruster measurment/thr_angle_1", 1, EXT_IN, 1, 1, 1 },

  { 21, "Thruster measurment/thr_angle_2", 1, EXT_IN, 1, 1, 1 },

  { 22, "Thruster measurment/thr_angle_3", 1, EXT_IN, 1, 1, 1 },

  { 23, "Thruster measurment/thr_angle_4", 1, EXT_IN, 1, 1, 1 },

  { 24, "Thruster measurment/thr_angle_5", 1, EXT_IN, 1, 1, 1 },

  { 25, "Thruster measurment/thr_angle_6", 1, EXT_IN, 1, 1, 1 },

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

  { 23, "TAPM Controller w_observer/tau_des", 1, EXT_OUT, 3, 3, 1 },

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
  "ctrl_TAPM2";
static const char* NI_CompiledModelVersion = "1.39";
static const char* NI_CompiledModelDateTime = "Sun May 15 13:28:12 2016";
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
  memcpy(&rtParameter[0], &ctrl_TAPM2_P, sizeof(P_ctrl_TAPM2_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_TAPM2_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_TAPM2_T));
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
             (P_ctrl_TAPM2_T));
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
               (P_ctrl_TAPM2_T));
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
             (P_ctrl_TAPM2_T));
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
           (P_ctrl_TAPM2_T));
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
           (P_ctrl_TAPM2_T));
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
  if ((numContStates != NULL) && (numDiscStates != NULL) && (numClockTicks !=
       NULL)) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 30;
      *numDiscStates = 652;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((contStates != NULL) && (contStatesNames != NULL)) {
    idx = 0;
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_p),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_p");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_k),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_k");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_n),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_n");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_c),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_c");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_h),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_h");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_e),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_e");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_g),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_g");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_i),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_i");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_l),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_TAPM2_X.Integrator_CSTATE_n4), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_n4");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_TAPM2_X.Integrator_CSTATE_gj), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_gj");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_TAPM2_X.Integrator_CSTATE_c5), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_c5");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_TAPM2_X.Integrator_CSTATE_c5), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_c5");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_TAPM2_X.Integrator_CSTATE_c5), 2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_c5");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator4_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator4_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator4_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator4_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_TAPM2_X.Integrator_CSTATE_l0), 0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l0");
    contStates[idx] = NIRT_GetValueByDataType
      (&(ctrl_TAPM2_X.Integrator_CSTATE_l0), 1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator_CSTATE_l0");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.TransferFcn2_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "TransferFcn2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator1_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator1_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator1_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator1_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator2_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator2_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator2_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator2_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator3_CSTATE),
      0, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator3_CSTATE),
      1, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
    contStates[idx] = NIRT_GetValueByDataType(&(ctrl_TAPM2_X.Integrator3_CSTATE),
      2, 0, 0);
    strcpy(contStatesNames + (idx++ * 100), "Integrator3_CSTATE");
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    for (count = 0; count < 6; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE,
        count, 21, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE");
    }

    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_f, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE_f");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_fu, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE_fu");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states, 0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states, 1, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.UD_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.UD_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_b, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE_b");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_d, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE_d");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_h, 0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_h, 1, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_h");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.UD_DSTATE_n, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.UD_DSTATE_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_m, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_m");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_n, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE_n");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_no, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE_no");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_j, 0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_j, 1, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.UD_DSTATE_i, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.UD_DSTATE_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_e, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_i, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_i, 0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_i, 1, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_i");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.UD_DSTATE_n4, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.UD_DSTATE_n4");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_h0, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_h0");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_j, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE_j");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_a, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb, 0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb, 1, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.UD_DSTATE_m, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.UD_DSTATE_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_dt, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_dt");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_dv, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE_dv");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_m, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.Delay_DSTATE_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_l, 0, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_l, 1, 23, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_l");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.UD_DSTATE_l, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.UD_DSTATE_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_states_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_states_o");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.alpha_1_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.alpha_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_d, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK1_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_e, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK1_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_g, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK1_g");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_c, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK1_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_a, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK1_a");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.pwm_2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.pwm_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.pwm_3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.pwm_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.pwm_4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.pwm_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.pwm_5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.pwm_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.alpha_2_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.alpha_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.pwm_6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.pwm_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.alpha_3_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.alpha_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.alpha_4_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.alpha_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.alpha_5_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.alpha_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.alpha_6_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.alpha_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.u_1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.u_4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.u_5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.u_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.u_6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.u_2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.u_3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.pwm_1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.pwm_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.tau_actual_DWORK1,
      0, 22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.tau_actual_DWORK1,
      1, 22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.tau_actual_DWORK1,
      2, 22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.tau_actual_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.PrevY, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.PrevY");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.Memory_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_ec, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK1_ec");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.PrevY_e, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.PrevY_e");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.Memory_PreviousInput_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.Memory_PreviousInput_n");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_l, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK1_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_h, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_e, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_e");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.PrevY_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.PrevY_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.Memory_PreviousInput_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.Memory_PreviousInput_d");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_lw, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK1_lw");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_hh, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_hh");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_k, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_k");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.PrevY_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.PrevY_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.Memory_PreviousInput_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.Memory_PreviousInput_a");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_ct, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK1_ct");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_c, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_c");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.PrevY_j, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.PrevY_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.Memory_PreviousInput_b, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.Memory_PreviousInput_b");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_i, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK1_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_h4, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_h4");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.PrevY_h, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.PrevY_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.Memory_PreviousInput_a4, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.Memory_PreviousInput_a4");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_j, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK1_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_cw, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_cw");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.x_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.x_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.y_m_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.y_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.psi_m_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.psi_m_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.eta_est_DWORK1, 0,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.eta_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.eta_est_DWORK1, 1,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.eta_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.eta_est_DWORK1, 2,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.eta_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.nu_est_DWORK1, 0,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.nu_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.nu_est_DWORK1, 1,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.nu_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.nu_est_DWORK1, 2,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.nu_est_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.wave_dir_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.wave_dir_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.fzp_x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.fzp_x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.fzp_y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.fzp_y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.r_max_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.r_max_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.SP_DWORK1, 0, 22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.SP_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.SP_DWORK1, 1, 22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.SP_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.SP_DWORK1, 2, 22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.SP_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.tau_des_DWORK1, 0,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.tau_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.tau_des_DWORK1, 1,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.tau_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.tau_des_DWORK1, 2,
      22, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.tau_des_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.thr_angle_1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.thr_angle_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.thr_angle_2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.thr_angle_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.thr_angle_3_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.thr_angle_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.thr_angle_4_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.thr_angle_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.thr_angle_5_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.thr_angle_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.thr_angle_6_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.thr_angle_6_DWORK1");
    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.alpha_1_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_o,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK2_o");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_i,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK2_i");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_k,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK2_k");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_a,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK2_a");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_m,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK2_m");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.pwm_2_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.pwm_2_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.pwm_3_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.pwm_3_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.pwm_4_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.pwm_4_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.pwm_5_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.pwm_5_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.alpha_2_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.pwm_6_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.pwm_6_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.alpha_3_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.alpha_4_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.alpha_5_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.alpha_6_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.u_1_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.u_1_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.u_4_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.u_4_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.u_5_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.u_5_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.u_6_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.u_6_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.u_2_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.u_2_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.u_3_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.u_3_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.pwm_1_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.pwm_1_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.tau_actual_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.tau_actual_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_n,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK2_n");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_e,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK2_e");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_l,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK2_l");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_mb,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK2_mb");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_nu,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK2_nu");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_f,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.reset_DWORK2_f");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.x_m_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.x_m_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.y_m_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.y_m_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.psi_m_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.psi_m_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.eta_est_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.eta_est_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.nu_est_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.nu_est_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.wave_dir_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.wave_dir_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.fzp_x_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.fzp_x_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.fzp_y_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.fzp_y_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.r_max_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.r_max_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.SP_DWORK2, count,
        24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.SP_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_TAPM2_DW.tau_des_DWORK2,
        count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_TAPM2_DW.tau_des_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM2_DW.thr_angle_1_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM2_DW.thr_angle_1_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM2_DW.thr_angle_2_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM2_DW.thr_angle_2_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM2_DW.thr_angle_3_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM2_DW.thr_angle_3_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM2_DW.thr_angle_4_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM2_DW.thr_angle_4_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM2_DW.thr_angle_5_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM2_DW.thr_angle_5_DWORK2");
    }

    for (count = 0; count < 11; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_TAPM2_DW.thr_angle_6_DWORK2, count, 24, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_TAPM2_DW.thr_angle_6_DWORK2");
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
  if (contStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE), 0, contStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_p), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_k), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_n), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_c), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_h), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_e), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_g), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_i), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_l), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_n4), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_gj), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_c5), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_c5), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_c5), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator4_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator4_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator4_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_l0), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator_CSTATE_l0), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.TransferFcn2_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator1_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator1_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator1_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator2_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator2_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator2_CSTATE), 2,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator3_CSTATE), 0,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator3_CSTATE), 1,
      contStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&(ctrl_TAPM2_X.Integrator3_CSTATE), 2,
      contStates[idx++], 0, 0);
  }

  if (discStates != NULL) {
    idx = 0;
    for (count = 0; count < 6; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE, count, discStates[idx
        ++], 21, 0);
    }

    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_f, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_fu, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.UD_DSTATE, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_b, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_d, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_h, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_h, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.UD_DSTATE_n, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_n, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_no, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_j, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_j, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.UD_DSTATE_i, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_e, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_i, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_i, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_i, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.UD_DSTATE_n4, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_h0, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_j, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_a, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_hb, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.UD_DSTATE_m, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_dt, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_dv, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Delay_DSTATE_m, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_l, 0,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_l, 1,
      discStates[idx++], 23, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.UD_DSTATE_l, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_states_o, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.alpha_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_d, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_e, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_g, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_c, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_a, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.pwm_2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.pwm_3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.pwm_4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.pwm_5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.alpha_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.pwm_6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.alpha_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.alpha_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.alpha_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.alpha_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.u_1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.u_4_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.u_5_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.u_6_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.u_2_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.u_3_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.pwm_1_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.tau_actual_DWORK1, 0, discStates[idx
      ++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.tau_actual_DWORK1, 1, discStates[idx
      ++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.tau_actual_DWORK1, 2, discStates[idx
      ++], 22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.PrevY, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_ec, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.PrevY_e, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Memory_PreviousInput_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_l, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_h, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_e, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.PrevY_o, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Memory_PreviousInput_d, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_lw, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_hh, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_k, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.PrevY_c, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Memory_PreviousInput_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_ct, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_c, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.PrevY_j, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Memory_PreviousInput_b, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_i, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_f, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_h4, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.PrevY_h, 0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.Memory_PreviousInput_a4, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK1_j, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.DiscreteTransferFcn_tmp_cw, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.x_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.y_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.psi_m_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.eta_est_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.eta_est_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.eta_est_DWORK1, 2, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.nu_est_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.nu_est_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.nu_est_DWORK1, 2, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.wave_dir_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.fzp_x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.fzp_y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.r_max_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.SP_DWORK1, 0, discStates[idx++], 22,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.SP_DWORK1, 1, discStates[idx++], 22,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.SP_DWORK1, 2, discStates[idx++], 22,
      0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.tau_des_DWORK1, 0, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.tau_des_DWORK1, 1, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.tau_des_DWORK1, 2, discStates[idx++],
      22, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.thr_angle_1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.thr_angle_2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.thr_angle_3_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.thr_angle_4_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.thr_angle_5_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_TAPM2_DW.thr_angle_6_DWORK1, 0, discStates[idx
      ++], 0, 0);
    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.alpha_1_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_o, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_i, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_k, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_a, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_m, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.pwm_2_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.pwm_3_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.pwm_4_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.pwm_5_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.alpha_2_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.pwm_6_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.alpha_3_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.alpha_4_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.alpha_5_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.alpha_6_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.u_1_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.u_4_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.u_5_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.u_6_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.u_2_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.u_3_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.pwm_1_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.tau_actual_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_n, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_e, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_l, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_mb, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_nu, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.reset_DWORK2_f, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.x_m_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.y_m_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.psi_m_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.eta_est_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.nu_est_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.wave_dir_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.fzp_x_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.fzp_y_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.r_max_DWORK2, count, discStates[idx
        ++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.SP_DWORK2, count, discStates[idx++],
        24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.tau_des_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.thr_angle_1_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.thr_angle_2_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.thr_angle_3_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.thr_angle_4_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.thr_angle_5_DWORK2, count,
        discStates[idx++], 24, 0);
    }

    for (count = 0; count < 11; count++) {
      NIRT_SetValueByDataType(&ctrl_TAPM2_DW.thr_angle_6_DWORK2, count,
        discStates[idx++], 24, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_TAPM2
