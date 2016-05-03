/*
 * ctrl_DP_basic.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_DP_basic".
 *
 * Model version              : 1.48
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue May 03 13:33:01 2016
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
static real_T ctrl_DP_basic_eml_xnrm2(int32_T n, const real_T x[18], int32_T ix0);
static real_T ctrl_DP_basic_eml_xnrm2_o(int32_T n, const real_T x[6], int32_T
  ix0);
static void ctrl_DP_basic_eml_xaxpy_br(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[18], int32_T iy0);
static void ctrl_DP_basic_eml_xaxpy_b(int32_T n, real_T a, const real_T x[18],
  int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_DP_basic_eml_xscal(real_T a, real_T x[9], int32_T ix0);
static void ctrl_DP_basic_eml_xscal_h(real_T a, real_T x[36], int32_T ix0);
static void ctrl_DP_basic_eml_xswap(real_T x[36], int32_T ix0, int32_T iy0);
static void ctrl_DP_basic_eml_xswap_d(real_T x[9], int32_T ix0, int32_T iy0);
static void ctrl_DP_basic_eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void ctrl_DP_basic_eml_xrot(real_T x[36], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void ctrl_DP_basic_eml_xrot_e(real_T x[9], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static real_T ctrl_DP_basic_eml_xdotc_mw(int32_T n, const real_T x[36], int32_T
  ix0, const real_T y[36], int32_T iy0);
static void ctrl_DP_basic_eml_xaxpy_bryl(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0);
static real_T ctrl_DP_basic_eml_xdotc_m(int32_T n, const real_T x[9], int32_T
  ix0, const real_T y[9], int32_T iy0);
static void ctrl_DP_basic_eml_xaxpy_bry(int32_T n, real_T a, int32_T ix0, real_T
  y[9], int32_T iy0);
static real_T ctrl_DP_basic_eml_xdotc(int32_T n, const real_T x[18], int32_T ix0,
  const real_T y[18], int32_T iy0);
static void ctrl_DP_basic_eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y
  [18], int32_T iy0);
static void ctrl_DP_basic_eml_xgesvd(const real_T A[18], real_T U[9], real_T S[3],
  real_T V[18]);
static real_T ctrl_DP_basic_eml_xnrm2_op(int32_T n, const real_T x[36], int32_T
  ix0);
static real_T ctrl_DP_basic_eml_xnrm2_opq(int32_T n, const real_T x[12], int32_T
  ix0);
static void ctrl_DP_basic_eml_xaxpy_brylp0o(int32_T n, real_T a, const real_T x
  [3], int32_T ix0, real_T y[36], int32_T iy0);
static void ctrl_DP_basic_eml_xaxpy_brylp0(int32_T n, real_T a, const real_T x
  [36], int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_DP_basic_eml_xscal_hd(real_T a, real_T x[144], int32_T ix0);
static void ctrl_DP_basic_eml_xswap_dz(real_T x[144], int32_T ix0, int32_T iy0);
static void ctrl_DP_basic_eml_xrot_e4(real_T x[144], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static real_T ctrl_DP_basic_eml_xdotc_mwqn(int32_T n, const real_T x[144],
  int32_T ix0, const real_T y[144], int32_T iy0);
static void ctrl_DP_basi_eml_xaxpy_brylp0ow(int32_T n, real_T a, int32_T ix0,
  real_T y[144], int32_T iy0);
static real_T ctrl_DP_basic_eml_xdotc_mwq(int32_T n, const real_T x[36], int32_T
  ix0, const real_T y[36], int32_T iy0);
static void ctrl_DP_basic_eml_xaxpy_brylp(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0);
static void ctrl_DP_basic_eml_xgesvd_c(const real_T A[36], real_T U[9], real_T
  S[3], real_T V[36]);

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
 *    '<S22>/MATLAB Function'
 *    '<S24>/MATLAB Function'
 */
void ctrl_DP_basic_MATLABFunction(real_T rtu_K_p1, real_T rtu_K_p1_e, real_T
  rtu_K_p1_f, B_MATLABFunction_ctrl_DP_basi_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function': '<S25>:1' */
  /* '<S25>:1:4' */
  memset(&localB->K_p[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_p[0] = rtu_K_p1;
  localB->K_p[4] = rtu_K_p1_e;
  localB->K_p[8] = rtu_K_p1_f;
}

/*
 * Output and update for atomic system:
 *    '<S22>/MATLAB Function1'
 *    '<S24>/MATLAB Function1'
 */
void ctrl_DP_basic_MATLABFunction1(real_T rtu_K_i1, real_T rtu_K_i1_m, real_T
  rtu_K_i1_n, B_MATLABFunction1_ctrl_DP_bas_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function1': '<S26>:1' */
  /* '<S26>:1:4' */
  memset(&localB->K_i[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S26>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_i[0] = rtu_K_i1;
  localB->K_i[4] = rtu_K_i1_m;
  localB->K_i[8] = rtu_K_i1_n;
}

/*
 * Output and update for atomic system:
 *    '<S22>/MATLAB Function2'
 *    '<S24>/MATLAB Function2'
 */
void ctrl_DP_basic_MATLABFunction2(real_T rtu_K_d1, real_T rtu_K_d1_p, real_T
  rtu_K_d1_i, B_MATLABFunction2_ctrl_DP_bas_T *localB)
{
  /* MATLAB Function 'Input/Control Gains/MATLAB Function2': '<S27>:1' */
  /* '<S27>:1:4' */
  memset(&localB->K_d[0], 0, 9U * sizeof(real_T));

  /* SignalConversion: '<S27>/TmpSignal ConversionAt SFunction Inport1' */
  localB->K_d[0] = rtu_K_d1;
  localB->K_d[4] = rtu_K_d1_p;
  localB->K_d[8] = rtu_K_d1_i;
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static real_T ctrl_DP_basic_eml_xnrm2_o(int32_T n, const real_T x[6], int32_T
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xaxpy_br(int32_T n, real_T a, const real_T x[3],
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xscal(real_T a, real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xscal_h(real_T a, real_T x[36], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 5; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xswap_d(real_T x[9], int32_T ix0, int32_T iy0)
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xrot_e(real_T x[9], int32_T ix0, int32_T iy0,
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static real_T ctrl_DP_basic_eml_xdotc_mw(int32_T n, const real_T x[36], int32_T
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xaxpy_bryl(int32_T n, real_T a, int32_T ix0,
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static real_T ctrl_DP_basic_eml_xdotc_m(int32_T n, const real_T x[9], int32_T
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xaxpy_bry(int32_T n, real_T a, int32_T ix0, real_T
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
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

  ztest0 = ctrl_DP_basic_eml_xnrm2_o(5, e, 2);
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
      ctrl_DP_basic_eml_xaxpy_br(2, -e[i] / e[1], work, 2, b_A, 3 * i + 2);
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

  ztest0 = ctrl_DP_basic_eml_xnrm2_o(4, e, 3);
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
      ctrl_DP_basic_eml_xaxpy_br(1, -e[i] / e[2], work, 3, b_A, 3 * i + 3);
    }
  }

  for (i = 2; i + 1 < 7; i++) {
    Vf[i + 6] = e[i];
  }

  for (kase = 3; kase + 1 < 7; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = ctrl_DP_basic_eml_xnrm2_o(3, e, 4);
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
        ctrl_DP_basic_eml_xaxpy_bry(3 - qs, -(ctrl_DP_basic_eml_xdotc_m(3 - qs,
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
        ctrl_DP_basic_eml_xaxpy_bryl(5 - qs, -(ctrl_DP_basic_eml_xdotc_mw(5 - qs,
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
    ctrl_DP_basic_eml_xscal_h(ztest0, Vf, 7);
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
    ctrl_DP_basic_eml_xscal_h(ztest0, Vf, 13);
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
    ctrl_DP_basic_eml_xscal_h(ztest0, Vf, 19);
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
        ctrl_DP_basic_eml_xrot_e(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest, b);
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
          ctrl_DP_basic_eml_xrot_e(U, 1 + 3 * (kase - 1), 1 + 3 * kase, ztest0,
            ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_DP_basic_eml_xscal_h(-1.0, Vf, 1 + 6 * q);
      }

      i = q + 1;
      while ((q + 1 < 4) && (s[q] < s[i])) {
        ztest = s[q];
        s[q] = s[i];
        s[i] = ztest;
        ctrl_DP_basic_eml_xswap(Vf, 1 + 6 * q, 1 + 6 * (q + 1));
        if (q + 1 < 3) {
          ctrl_DP_basic_eml_xswap_d(U, 1 + 3 * q, 1 + 3 * (q + 1));
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static real_T ctrl_DP_basic_eml_xnrm2_op(int32_T n, const real_T x[36], int32_T
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static real_T ctrl_DP_basic_eml_xnrm2_opq(int32_T n, const real_T x[12], int32_T
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xaxpy_brylp0o(int32_T n, real_T a, const real_T x
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xaxpy_brylp0(int32_T n, real_T a, const real_T x
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xscal_hd(real_T a, real_T x[144], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 11; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xswap_dz(real_T x[144], int32_T ix0, int32_T iy0)
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xrot_e4(real_T x[144], int32_T ix0, int32_T iy0,
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static real_T ctrl_DP_basic_eml_xdotc_mwqn(int32_T n, const real_T x[144],
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basi_eml_xaxpy_brylp0ow(int32_T n, real_T a, int32_T ix0,
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static real_T ctrl_DP_basic_eml_xdotc_mwq(int32_T n, const real_T x[36], int32_T
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xaxpy_brylp(int32_T n, real_T a, int32_T ix0,
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_DP_basic_eml_xgesvd_c(const real_T A[36], real_T U[9], real_T
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
  ztest0 = ctrl_DP_basic_eml_xnrm2_op(3, b_A, 1);
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
      ctrl_DP_basic_eml_xaxpy_brylp(3, -(ctrl_DP_basic_eml_xdotc_mwq(3, b_A, 1,
        b_A, qp1jj + 1) / b_A[0]), 1, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 0; qp1 + 1 < 4; qp1++) {
    U[qp1] = b_A[qp1];
  }

  ztest0 = ctrl_DP_basic_eml_xnrm2_opq(11, e, 2);
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
      ctrl_DP_basic_eml_xaxpy_brylp0(2, e[qp1], b_A, 3 * qp1 + 2, work, 2);
    }

    for (qp1 = 1; qp1 + 1 < 13; qp1++) {
      ctrl_DP_basic_eml_xaxpy_brylp0o(2, -e[qp1] / e[1], work, 2, b_A, 3 * qp1 +
        2);
    }
  }

  for (qp1 = 1; qp1 + 1 < 13; qp1++) {
    Vf[qp1] = e[qp1];
  }

  apply_transform = false;
  ztest0 = ctrl_DP_basic_eml_xnrm2_op(2, b_A, 5);
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
      ctrl_DP_basic_eml_xaxpy_brylp(2, -(ctrl_DP_basic_eml_xdotc_mwq(2, b_A, 5,
        b_A, qp1jj + 1) / b_A[4]), 5, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 1; qp1 + 1 < 4; qp1++) {
    U[qp1 + 3] = b_A[qp1 + 3];
  }

  ztest0 = ctrl_DP_basic_eml_xnrm2_opq(10, e, 3);
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
      ctrl_DP_basic_eml_xaxpy_brylp0(1, e[qp1], b_A, 3 * qp1 + 3, work, 3);
    }

    for (qp1 = 2; qp1 + 1 < 13; qp1++) {
      ctrl_DP_basic_eml_xaxpy_brylp0o(1, -e[qp1] / e[2], work, 3, b_A, 3 * qp1 +
        3);
    }
  }

  for (qp1 = 2; qp1 + 1 < 13; qp1++) {
    Vf[qp1 + 12] = e[qp1];
  }

  for (kase = 3; kase + 1 < 13; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = ctrl_DP_basic_eml_xnrm2_opq(9, e, 4);
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
        ctrl_DP_basic_eml_xaxpy_bry(3 - qs, -(ctrl_DP_basic_eml_xdotc_m(3 - qs,
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
        ctrl_DP_basi_eml_xaxpy_brylp0ow(11 - qs, -(ctrl_DP_basic_eml_xdotc_mwqn
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
    ctrl_DP_basic_eml_xscal_hd(ztest0, Vf, 13);
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
    ctrl_DP_basic_eml_xscal_hd(ztest0, Vf, 25);
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
    ctrl_DP_basic_eml_xscal_hd(ztest0, Vf, 37);
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

        ctrl_DP_basic_eml_xrot_e4(Vf, 1 + 12 * kase, 1 + 12 * (m + 1), ztest, b);
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
        ctrl_DP_basic_eml_xrot_e(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest, b);
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
        ctrl_DP_basic_eml_xrot_e4(Vf, 1 + 12 * (kase - 1), 1 + 12 * kase, ztest0,
          ztest);
        ctrl_DP_basic_eml_xrotg(&f, &b, &ztest0, &ztest);
        s[kase - 1] = f;
        f = e[kase - 1] * ztest0 + ztest * s[kase];
        s[kase] = e[kase - 1] * -ztest + ztest0 * s[kase];
        b = ztest * e[kase];
        e[kase] *= ztest0;
        if (kase < 3) {
          ctrl_DP_basic_eml_xrot_e(U, 1 + 3 * (kase - 1), 1 + 3 * kase, ztest0,
            ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_DP_basic_eml_xscal_hd(-1.0, Vf, 1 + 12 * q);
      }

      qp1 = q + 1;
      while ((q + 1 < 4) && (s[q] < s[qp1])) {
        ztest = s[q];
        s[q] = s[qp1];
        s[qp1] = ztest;
        ctrl_DP_basic_eml_xswap_dz(Vf, 1 + 12 * q, 1 + 12 * (q + 1));
        if (q + 1 < 3) {
          ctrl_DP_basic_eml_xswap_d(U, 1 + 3 * q, 1 + 3 * (q + 1));
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

/* Model output function */
void ctrl_DP_basic_output(void)
{
  /* local block i/o variables */
  real_T rtb_MatrixMultiply[3];
  real_T T_surge[6];
  real_T T_sway[6];
  real_T T_yaw[6];
  real_T S_singular_cross[9];
  real_T S_ang[9];
  real_T T0[12];
  real_T U[9];
  real_T V[18];
  real_T b_V[36];
  static const real_T d[6] = { 1.201111111111111, 1.1244444444444446,
    1.1244444444444446, -1.0311111111111111, -0.85777777777777786,
    -0.85777777777777786 };

  static const real_T e[6] = { 0.0, 0.11, -0.11, 0.0, -0.16555555555555557,
    0.16555555555555557 };

  static const real_T A[36] = { 1.0, 0.0, 0.0, 0.0, 1.0, 1.201111111111111, 1.0,
    0.0, 0.11, 0.0, 1.0, 1.1244444444444446, 1.0, 0.0, -0.11, 0.0, 1.0,
    1.1244444444444446, 1.0, 0.0, 0.0, 0.0, 1.0, -1.0311111111111111, 1.0, 0.0,
    -0.16555555555555557, 0.0, 1.0, -0.85777777777777786, 1.0, 0.0,
    0.16555555555555557, 0.0, 1.0, -0.85777777777777786 };

  boolean_T f[9];
  int32_T p1;
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  real_T rtb_Row2;
  real_T rtb_Row1;
  real_T rtb_psi_dot;
  real_T rtb_Row1_o;
  real_T rtb_Sum[3];
  real_T rtb_TmpSignalConversionAtSFu_pa[3];
  real_T rtb_TmpSignalConversionAtSFunct[6];
  real_T rtb_y_n[9];
  real_T rtb_w_d[9];
  real_T T_surge_0[18];
  real_T b_V_0[36];
  real_T tmp[3];
  real_T tmp_0[9];
  real_T tmp_1[9];
  int32_T b_data[9];
  int32_T c_data[9];
  boolean_T f_0;
  real_T rtb_MatrixMultiply5_idx_2;
  real_T rtb_MatrixMultiply5_idx_0;
  real_T rtb_MatrixMultiply5_idx_1;
  real_T rtb_Row2_0;
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

  /* MATLAB Function: '<S22>/MATLAB Function' */
  ctrl_DP_basic_MATLABFunction(ctrl_DP_basic_B.K_p_x, ctrl_DP_basic_B.K_p_y,
    ctrl_DP_basic_B.K_p_psi, &ctrl_DP_basic_B.sf_MATLABFunction);

  /* Saturate: '<S14>/Saturation' incorporates:
   *  Fcn: '<S10>/yaw angle'
   */
  if (ctrl_DP_basic_B.psi > ctrl_DP_basic_P.Saturation_UpperSat) {
    rtb_Row2 = ctrl_DP_basic_P.Saturation_UpperSat;
  } else if (ctrl_DP_basic_B.psi < ctrl_DP_basic_P.Saturation_LowerSat) {
    rtb_Row2 = ctrl_DP_basic_P.Saturation_LowerSat;
  } else {
    rtb_Row2 = ctrl_DP_basic_B.psi;
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* Signum: '<S14>/Sign' */
  if (rtb_Row2 < 0.0) {
    rtb_Row2_0 = -1.0;
  } else if (rtb_Row2 > 0.0) {
    rtb_Row2_0 = 1.0;
  } else if (rtb_Row2 == 0.0) {
    rtb_Row2_0 = 0.0;
  } else {
    rtb_Row2_0 = rtb_Row2;
  }

  /* Gain: '<S14>/Gain' incorporates:
   *  Signum: '<S14>/Sign'
   */
  rtb_Row1 = ctrl_DP_basic_P.Gain_Gain * rtb_Row2_0;

  /* Sum: '<S14>/Sum1' */
  rtb_Row2 += rtb_Row1;

  /* Math: '<S14>/Math Function' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Row2 = rt_remd_snf(rtb_Row2, ctrl_DP_basic_P.Constant_Value);

  /* Sum: '<S14>/Sum' */
  rtb_Row2 -= rtb_Row1;

  /* MATLAB Function: '<S22>/MATLAB Function1' */
  ctrl_DP_basic_MATLABFunction1(ctrl_DP_basic_B.K_i_x, ctrl_DP_basic_B.K_i_y,
    ctrl_DP_basic_B.K_i_psi, &ctrl_DP_basic_B.sf_MATLABFunction1);

  /* MATLAB Function: '<S22>/MATLAB Function2' */
  ctrl_DP_basic_MATLABFunction2(ctrl_DP_basic_B.K_d_x, ctrl_DP_basic_B.K_d_y,
    ctrl_DP_basic_B.K_d_psi, &ctrl_DP_basic_B.sf_MATLABFunction2);
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* MATLAB Function: '<S24>/MATLAB Function2' incorporates:
     *  Constant: '<S24>/Constant6'
     *  Constant: '<S24>/Constant7'
     *  Constant: '<S24>/Constant8'
     */
    ctrl_DP_basic_MATLABFunction2(ctrl_DP_basic_P.Constant6_Value,
      ctrl_DP_basic_P.Constant7_Value, ctrl_DP_basic_P.Constant8_Value,
      &ctrl_DP_basic_B.sf_MATLABFunction2_p);
  }

  /* MATLAB Function: '<S23>/diag' incorporates:
   *  SignalConversion: '<S28>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Input/Guidance gains/diag': '<S28>:1' */
  /* '<S28>:1:4' */
  memset(&rtb_w_d[0], 0, 9U * sizeof(real_T));
  rtb_w_d[0] = ctrl_DP_basic_B.w_d_x;
  rtb_w_d[4] = ctrl_DP_basic_B.w_d_y;
  rtb_w_d[8] = ctrl_DP_basic_B.w_d_psi;

  /* Integrator: '<S15>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator1_Reset_ZCE,
                       ctrl_DP_basic_B.reset);

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

  /* Saturate: '<S16>/Saturation' */
  if (ctrl_DP_basic_B.Integrator1[2] > ctrl_DP_basic_P.Saturation_UpperSat_j) {
    rtb_Row1 = ctrl_DP_basic_P.Saturation_UpperSat_j;
  } else if (ctrl_DP_basic_B.Integrator1[2] <
             ctrl_DP_basic_P.Saturation_LowerSat_c) {
    rtb_Row1 = ctrl_DP_basic_P.Saturation_LowerSat_c;
  } else {
    rtb_Row1 = ctrl_DP_basic_B.Integrator1[2];
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* Signum: '<S16>/Sign' */
  if (rtb_Row1 < 0.0) {
    rtb_Row2_0 = -1.0;
  } else if (rtb_Row1 > 0.0) {
    rtb_Row2_0 = 1.0;
  } else if (rtb_Row1 == 0.0) {
    rtb_Row2_0 = 0.0;
  } else {
    rtb_Row2_0 = rtb_Row1;
  }

  /* Gain: '<S16>/Gain' incorporates:
   *  Signum: '<S16>/Sign'
   */
  rtb_psi_dot = ctrl_DP_basic_P.Gain_Gain_j * rtb_Row2_0;

  /* Sum: '<S16>/Sum1' */
  rtb_Row1 += rtb_psi_dot;

  /* Math: '<S16>/Math Function' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_Row1 = rt_remd_snf(rtb_Row1, ctrl_DP_basic_P.Constant_Value_f);

  /* Sum: '<S16>/Sum' */
  ctrl_DP_basic_B.Sum = rtb_Row1 - rtb_psi_dot;

  /* SignalConversion: '<S15>/TmpSignal ConversionAtMatrix Multiply2Inport2' */
  rtb_MatrixMultiply5_idx_0 = ctrl_DP_basic_B.Integrator1[0];
  rtb_MatrixMultiply5_idx_1 = ctrl_DP_basic_B.Integrator1[1];
  rtb_MatrixMultiply5_idx_2 = ctrl_DP_basic_B.Sum;

  /* Sum: '<S10>/Sum2' incorporates:
   *  SignalConversion: '<S15>/TmpSignal ConversionAtMatrix Multiply2Inport2'
   */
  ctrl_DP_basic_B.regulationerror[0] = ctrl_DP_basic_B.x -
    ctrl_DP_basic_B.Integrator1[0];
  ctrl_DP_basic_B.regulationerror[1] = ctrl_DP_basic_B.y -
    ctrl_DP_basic_B.Integrator1[1];
  ctrl_DP_basic_B.regulationerror[2] = ctrl_DP_basic_B.psi - ctrl_DP_basic_B.Sum;

  /* Saturate: '<S13>/Saturation' */
  if (ctrl_DP_basic_B.regulationerror[2] > ctrl_DP_basic_P.Saturation_UpperSat_a)
  {
    rtb_psi_dot = ctrl_DP_basic_P.Saturation_UpperSat_a;
  } else if (ctrl_DP_basic_B.regulationerror[2] <
             ctrl_DP_basic_P.Saturation_LowerSat_d) {
    rtb_psi_dot = ctrl_DP_basic_P.Saturation_LowerSat_d;
  } else {
    rtb_psi_dot = ctrl_DP_basic_B.regulationerror[2];
  }

  /* End of Saturate: '<S13>/Saturation' */

  /* Signum: '<S13>/Sign' */
  if (rtb_psi_dot < 0.0) {
    rtb_Row2_0 = -1.0;
  } else if (rtb_psi_dot > 0.0) {
    rtb_Row2_0 = 1.0;
  } else if (rtb_psi_dot == 0.0) {
    rtb_Row2_0 = 0.0;
  } else {
    rtb_Row2_0 = rtb_psi_dot;
  }

  /* Gain: '<S13>/Gain' incorporates:
   *  Signum: '<S13>/Sign'
   */
  rtb_Row1 = ctrl_DP_basic_P.Gain_Gain_g * rtb_Row2_0;

  /* Sum: '<S13>/Sum1' */
  rtb_psi_dot += rtb_Row1;

  /* Math: '<S13>/Math Function' incorporates:
   *  Constant: '<S13>/Constant'
   */
  rtb_psi_dot = rt_remd_snf(rtb_psi_dot, ctrl_DP_basic_P.Constant_Value_p);

  /* Sum: '<S13>/Sum' */
  rtb_psi_dot -= rtb_Row1;

  /* SignalConversion: '<S10>/TmpSignal ConversionAtMatrix MultiplyInport2' incorporates:
   *  Fcn: '<S11>/Row1'
   *  Fcn: '<S11>/Row2'
   *  Fcn: '<S11>/Row3'
   */
  ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[0] = cos(rtb_Row2) *
    ctrl_DP_basic_B.regulationerror[0] + sin(rtb_Row2) *
    ctrl_DP_basic_B.regulationerror[1];
  ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[1] = -sin(rtb_Row2) *
    ctrl_DP_basic_B.regulationerror[0] + cos(rtb_Row2) *
    ctrl_DP_basic_B.regulationerror[1];
  ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[2] = rtb_psi_dot;

  /* Product: '<S10>/Matrix Multiply' */
  for (itmp = 0; itmp < 3; itmp++) {
    rtb_TmpSignalConversionAtSFu_pa[itmp] =
      ctrl_DP_basic_B.sf_MATLABFunction.K_p[itmp + 6] *
      ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[2] +
      (ctrl_DP_basic_B.sf_MATLABFunction.K_p[itmp + 3] *
       ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[1] +
       ctrl_DP_basic_B.sf_MATLABFunction.K_p[itmp] *
       ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[0]);
  }

  /* End of Product: '<S10>/Matrix Multiply' */

  /* Integrator: '<S10>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator_Reset_ZCE,
                       ctrl_DP_basic_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_basic_X.Integrator_CSTATE[0] = ctrl_DP_basic_P.Integrator_IC;
      ctrl_DP_basic_X.Integrator_CSTATE[1] = ctrl_DP_basic_P.Integrator_IC;
      ctrl_DP_basic_X.Integrator_CSTATE[2] = ctrl_DP_basic_P.Integrator_IC;
    }
  }

  rtb_MatrixMultiply[0] = ctrl_DP_basic_X.Integrator_CSTATE[0];
  rtb_MatrixMultiply[1] = ctrl_DP_basic_X.Integrator_CSTATE[1];
  rtb_MatrixMultiply[2] = ctrl_DP_basic_X.Integrator_CSTATE[2];

  /* Product: '<S10>/Matrix Multiply1' */
  for (itmp = 0; itmp < 3; itmp++) {
    rtb_Sum[itmp] = ctrl_DP_basic_B.sf_MATLABFunction1.K_i[itmp + 6] *
      rtb_MatrixMultiply[2] + (ctrl_DP_basic_B.sf_MATLABFunction1.K_i[itmp + 3] *
      rtb_MatrixMultiply[1] + ctrl_DP_basic_B.sf_MATLABFunction1.K_i[itmp] *
      rtb_MatrixMultiply[0]);
  }

  /* End of Product: '<S10>/Matrix Multiply1' */

  /* Integrator: '<S6>/Integrator1' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator1_Reset_ZCE_e,
                       ctrl_DP_basic_B.reset);

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

  /* Integrator: '<S15>/Integrator3' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator3_Reset_ZCE,
                       ctrl_DP_basic_B.reset);

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

  /* Sum: '<S10>/Sum4' incorporates:
   *  Fcn: '<S10>/yaw angle1'
   *  Fcn: '<S12>/Row1'
   *  Fcn: '<S12>/Row2'
   *  Fcn: '<S12>/Row3'
   */
  ctrl_DP_basic_B.Sum4[0] = ctrl_DP_basic_B.Integrator1_g[0] - (cos
    (rtb_MatrixMultiply5_idx_2) * ctrl_DP_basic_B.Integrator3[0] + sin
    (rtb_MatrixMultiply5_idx_2) * ctrl_DP_basic_B.Integrator3[1]);
  ctrl_DP_basic_B.Sum4[1] = ctrl_DP_basic_B.Integrator1_g[1] - (-sin
    (rtb_MatrixMultiply5_idx_2) * ctrl_DP_basic_B.Integrator3[0] + cos
    (rtb_MatrixMultiply5_idx_2) * ctrl_DP_basic_B.Integrator3[1]);
  ctrl_DP_basic_B.Sum4[2] = ctrl_DP_basic_B.Integrator1_g[2] -
    ctrl_DP_basic_B.Integrator3[2];

  /* Product: '<S10>/Matrix Multiply2' */
  for (itmp = 0; itmp < 3; itmp++) {
    rtb_MatrixMultiply[itmp] = 0.0;
    rtb_MatrixMultiply[itmp] += ctrl_DP_basic_B.sf_MATLABFunction2.K_d[itmp] *
      ctrl_DP_basic_B.Sum4[0];
    rtb_MatrixMultiply[itmp] += ctrl_DP_basic_B.sf_MATLABFunction2.K_d[itmp + 3]
      * ctrl_DP_basic_B.Sum4[1];
    rtb_MatrixMultiply[itmp] += ctrl_DP_basic_B.sf_MATLABFunction2.K_d[itmp + 6]
      * ctrl_DP_basic_B.Sum4[2];
  }

  /* End of Product: '<S10>/Matrix Multiply2' */

  /* Sum: '<S10>/Sum3' */
  ctrl_DP_basic_B.Sum3[0] = ((0.0 - rtb_TmpSignalConversionAtSFu_pa[0]) -
    rtb_Sum[0]) - rtb_MatrixMultiply[0];
  ctrl_DP_basic_B.Sum3[1] = ((0.0 - rtb_TmpSignalConversionAtSFu_pa[1]) -
    rtb_Sum[1]) - rtb_MatrixMultiply[1];
  ctrl_DP_basic_B.Sum3[2] = ((0.0 - rtb_TmpSignalConversionAtSFu_pa[2]) -
    rtb_Sum[2]) - rtb_MatrixMultiply[2];

  /* SignalConversion: '<S8>/TmpSignal ConversionAt SFunction Inport2' incorporates:
   *  MATLAB Function: '<Root>/Thrust allocation'
   */
  rtb_TmpSignalConversionAtSFunct[0] = ctrl_DP_basic_B.thr_angle_1;
  rtb_TmpSignalConversionAtSFunct[1] = ctrl_DP_basic_B.thr_angle_2;
  rtb_TmpSignalConversionAtSFunct[2] = ctrl_DP_basic_B.thr_angle_3;
  rtb_TmpSignalConversionAtSFunct[3] = ctrl_DP_basic_B.thr_angle_4;
  rtb_TmpSignalConversionAtSFunct[4] = ctrl_DP_basic_B.thr_angle_5;
  rtb_TmpSignalConversionAtSFunct[5] = ctrl_DP_basic_B.thr_angle_6;

  /* MATLAB Function: '<Root>/Thrust allocation' */
  /* MATLAB Function 'Thrust allocation': '<S8>:1' */
  /* [m,m] */
  /* [m,m]  */
  /* [m,m] */
  /* '<S8>:1:12' */
  /* [x(1),x(2),x(3),x(4),x(5),x(6)]'; */
  /* '<S8>:1:13' */
  /* [x(7),x(8),x(9),x(10),x(11),x(12)]'; */
  /* '<S8>:1:18' */
  /*  Shells for faster computing */
  /* '<S8>:1:19' */
  /*  Shells for faster computing */
  /* '<S8>:1:20' */
  /*  Shells for faster computing */
  /* '<S8>:1:22' */
  for (p1 = 0; p1 < 6; p1++) {
    /* '<S8>:1:22' */
    /* '<S8>:1:23' */
    T_surge[p1] = cos(rtb_TmpSignalConversionAtSFunct[p1]);

    /* Thrust in x-direction for cartesian */
    /* '<S8>:1:24' */
    T_sway[p1] = sin(rtb_TmpSignalConversionAtSFunct[p1]);

    /* Thrust in y-direction for cartesian */
    /* '<S8>:1:25' */
    T_yaw[p1] = sin(rtb_TmpSignalConversionAtSFunct[p1]) * d[p1] - cos
      (rtb_TmpSignalConversionAtSFunct[p1]) * e[p1];

    /* '<S8>:1:22' */
  }

  /* '<S8>:1:28' */
  for (itmp = 0; itmp < 6; itmp++) {
    T_surge_0[3 * itmp] = T_surge[itmp];
  }

  for (itmp = 0; itmp < 6; itmp++) {
    T_surge_0[1 + 3 * itmp] = T_sway[itmp];
  }

  for (itmp = 0; itmp < 6; itmp++) {
    T_surge_0[2 + 3 * itmp] = T_yaw[itmp];
  }

  ctrl_DP_basic_eml_xgesvd(T_surge_0, U, rtb_TmpSignalConversionAtSFu_pa, V);
  memset(&S_singular_cross[0], 0, 9U * sizeof(real_T));
  S_singular_cross[0] = rtb_TmpSignalConversionAtSFu_pa[0];
  S_singular_cross[4] = rtb_TmpSignalConversionAtSFu_pa[1];
  S_singular_cross[8] = rtb_TmpSignalConversionAtSFu_pa[2];

  /* '<S8>:1:33' */
  /* '<S8>:1:34' */
  p1 = 0;
  for (itmp = 0; itmp < 9; itmp++) {
    rtb_Row2_0 = 1.0 / S_singular_cross[itmp];
    f_0 = !((!rtIsInf(rtb_Row2_0)) && (!rtIsNaN(rtb_Row2_0)));
    if (f_0) {
      p1++;
    }

    f[itmp] = f_0;
    S_singular_cross[itmp] = rtb_Row2_0;
  }

  p3 = p1;
  p1 = 0;
  for (p2 = 0; p2 < 9; p2++) {
    if (f[p2]) {
      b_data[p1] = p2 + 1;
      p1++;
    }
  }

  /* '<S8>:1:34' */
  for (itmp = 0; itmp < p3; itmp++) {
    S_singular_cross[b_data[itmp] - 1] = 0.0;
  }

  if (S_singular_cross[8] > 2.0 * S_singular_cross[4]) {
    /* '<S8>:1:35' */
    /* '<S8>:1:36' */
    S_singular_cross[8] = 0.0;
  }

  /* '<S8>:1:39' */
  /* '<S8>:1:40' */
  ctrl_DP_basic_eml_xgesvd_c(A, rtb_y_n, rtb_TmpSignalConversionAtSFu_pa, b_V);
  memset(&S_ang[0], 0, 9U * sizeof(real_T));
  S_ang[0] = rtb_TmpSignalConversionAtSFu_pa[0];
  S_ang[4] = rtb_TmpSignalConversionAtSFu_pa[1];
  S_ang[8] = rtb_TmpSignalConversionAtSFu_pa[2];

  /* '<S8>:1:48' */
  /* '<S8>:1:49' */
  p1 = 0;
  for (itmp = 0; itmp < 9; itmp++) {
    rtb_Row2_0 = 1.0 / S_ang[itmp];
    f_0 = !((!rtIsInf(rtb_Row2_0)) && (!rtIsNaN(rtb_Row2_0)));
    if (f_0) {
      p1++;
    }

    f[itmp] = f_0;
    S_ang[itmp] = rtb_Row2_0;
  }

  p3 = p1;
  p1 = 0;
  for (p2 = 0; p2 < 9; p2++) {
    if (f[p2]) {
      c_data[p1] = p2 + 1;
      p1++;
    }
  }

  /* '<S8>:1:49' */
  for (itmp = 0; itmp < p3; itmp++) {
    S_ang[c_data[itmp] - 1] = 0.0;
  }

  if (S_ang[8] > 2.0 * S_ang[4]) {
    /* '<S8>:1:50' */
    /* '<S8>:1:51' */
    S_ang[8] = 0.0;
  }

  /* '<S8>:1:53' */
  for (itmp = 0; itmp < 12; itmp++) {
    for (p3 = 0; p3 < 3; p3++) {
      b_V_0[itmp + 12 * p3] = 0.0;
      b_V_0[itmp + 12 * p3] += S_ang[3 * p3] * b_V[itmp];
      b_V_0[itmp + 12 * p3] += S_ang[3 * p3 + 1] * b_V[itmp + 12];
      b_V_0[itmp + 12 * p3] += S_ang[3 * p3 + 2] * b_V[itmp + 24];
    }
  }

  for (itmp = 0; itmp < 12; itmp++) {
    for (p3 = 0; p3 < 3; p3++) {
      b_V[itmp + 12 * p3] = 0.0;
      b_V[itmp + 12 * p3] += b_V_0[itmp] * rtb_y_n[p3];
      b_V[itmp + 12 * p3] += b_V_0[itmp + 12] * rtb_y_n[p3 + 3];
      b_V[itmp + 12 * p3] += b_V_0[itmp + 24] * rtb_y_n[p3 + 6];
    }
  }

  for (itmp = 0; itmp < 12; itmp++) {
    T0[itmp] = b_V[itmp + 24] * ctrl_DP_basic_B.Sum3[2] + (b_V[itmp + 12] *
      ctrl_DP_basic_B.Sum3[1] + b_V[itmp] * ctrl_DP_basic_B.Sum3[0]);
  }

  /* '<S8>:1:54' */
  /*  for i=1:1:n_t */
  /*    if alpha1(i) > 180 */
  /*        alpha1(i) = alpha1(i) - 360; */
  /*    elseif alpha1(i) < -180 */
  /*        alpha1(i) = alpha1(i) + 360; */
  /*    else */
  /*        alpha1(i); */
  /*    end */
  /*  end */
  /* '<S8>:1:66' */
  for (itmp = 0; itmp < 6; itmp++) {
    for (p3 = 0; p3 < 3; p3++) {
      T_surge_0[itmp + 6 * p3] = 0.0;
      T_surge_0[itmp + 6 * p3] += S_singular_cross[3 * p3] * V[itmp];
      T_surge_0[itmp + 6 * p3] += S_singular_cross[3 * p3 + 1] * V[itmp + 6];
      T_surge_0[itmp + 6 * p3] += S_singular_cross[3 * p3 + 2] * V[itmp + 12];
    }
  }

  for (itmp = 0; itmp < 6; itmp++) {
    for (p3 = 0; p3 < 3; p3++) {
      V[itmp + 6 * p3] = 0.0;
      V[itmp + 6 * p3] += T_surge_0[itmp] * U[p3];
      V[itmp + 6 * p3] += T_surge_0[itmp + 6] * U[p3 + 3];
      V[itmp + 6 * p3] += T_surge_0[itmp + 12] * U[p3 + 6];
    }
  }

  for (itmp = 0; itmp < 6; itmp++) {
    ctrl_DP_basic_B.u_out[itmp] = 0.0;
    ctrl_DP_basic_B.u_out[itmp] += V[itmp] * ctrl_DP_basic_B.Sum3[0];
    ctrl_DP_basic_B.u_out[itmp] += V[itmp + 6] * ctrl_DP_basic_B.Sum3[1];
    ctrl_DP_basic_B.u_out[itmp] += V[itmp + 12] * ctrl_DP_basic_B.Sum3[2];
  }

  /* '<S8>:1:67' */
  ctrl_DP_basic_B.alpha_out[0] = rt_atan2d_snf(T0[1], T0[0]);
  ctrl_DP_basic_B.alpha_out[1] = rt_atan2d_snf(T0[3], T0[2]);
  ctrl_DP_basic_B.alpha_out[2] = rt_atan2d_snf(T0[5], T0[4]);
  ctrl_DP_basic_B.alpha_out[3] = rt_atan2d_snf(T0[7], T0[6]);
  ctrl_DP_basic_B.alpha_out[4] = rt_atan2d_snf(T0[9], T0[8]);
  ctrl_DP_basic_B.alpha_out[5] = rt_atan2d_snf(T0[11], T0[10]);

  /* Integrator: '<S6>/Integrator' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator_Reset_ZCE_n,
                       ctrl_DP_basic_B.reset);

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

  /* Saturate: '<S38>/Saturation' */
  if (ctrl_DP_basic_B.Integrator[2] > ctrl_DP_basic_P.Saturation_UpperSat_l) {
    rtb_Row1_o = ctrl_DP_basic_P.Saturation_UpperSat_l;
  } else if (ctrl_DP_basic_B.Integrator[2] <
             ctrl_DP_basic_P.Saturation_LowerSat_cz) {
    rtb_Row1_o = ctrl_DP_basic_P.Saturation_LowerSat_cz;
  } else {
    rtb_Row1_o = ctrl_DP_basic_B.Integrator[2];
  }

  /* End of Saturate: '<S38>/Saturation' */

  /* Signum: '<S38>/Sign' */
  if (rtb_Row1_o < 0.0) {
    rtb_Row2_0 = -1.0;
  } else if (rtb_Row1_o > 0.0) {
    rtb_Row2_0 = 1.0;
  } else if (rtb_Row1_o == 0.0) {
    rtb_Row2_0 = 0.0;
  } else {
    rtb_Row2_0 = rtb_Row1_o;
  }

  /* Gain: '<S38>/Gain' incorporates:
   *  Signum: '<S38>/Sign'
   */
  rtb_psi_dot = ctrl_DP_basic_P.Gain_Gain_d * rtb_Row2_0;

  /* Sum: '<S38>/Sum1' */
  rtb_Row1_o += rtb_psi_dot;

  /* Math: '<S38>/Math Function' incorporates:
   *  Constant: '<S38>/Constant'
   */
  rtb_Row1_o = rt_remd_snf(rtb_Row1_o, ctrl_DP_basic_P.Constant_Value_p4);

  /* Sum: '<S38>/Sum' */
  ctrl_DP_basic_B.Sum_f = rtb_Row1_o - rtb_psi_dot;

  /* Saturate: '<S39>/Saturation' */
  if (ctrl_DP_basic_B.psi > ctrl_DP_basic_P.Saturation_UpperSat_o) {
    rtb_Row1_o = ctrl_DP_basic_P.Saturation_UpperSat_o;
  } else if (ctrl_DP_basic_B.psi < ctrl_DP_basic_P.Saturation_LowerSat_j) {
    rtb_Row1_o = ctrl_DP_basic_P.Saturation_LowerSat_j;
  } else {
    rtb_Row1_o = ctrl_DP_basic_B.psi;
  }

  /* End of Saturate: '<S39>/Saturation' */

  /* Signum: '<S39>/Sign' */
  if (rtb_Row1_o < 0.0) {
    rtb_Row2_0 = -1.0;
  } else if (rtb_Row1_o > 0.0) {
    rtb_Row2_0 = 1.0;
  } else if (rtb_Row1_o == 0.0) {
    rtb_Row2_0 = 0.0;
  } else {
    rtb_Row2_0 = rtb_Row1_o;
  }

  /* Gain: '<S39>/Gain' incorporates:
   *  Signum: '<S39>/Sign'
   */
  rtb_psi_dot = ctrl_DP_basic_P.Gain_Gain_h * rtb_Row2_0;

  /* Sum: '<S39>/Sum1' */
  rtb_Row1_o += rtb_psi_dot;

  /* Math: '<S39>/Math Function' incorporates:
   *  Constant: '<S39>/Constant'
   */
  rtb_Row1_o = rt_remd_snf(rtb_Row1_o, ctrl_DP_basic_P.Constant_Value_i);

  /* Sum: '<S39>/Sum' */
  rtb_Row1_o -= rtb_psi_dot;

  /* Fcn: '<S6>/Fcn' */
  rtb_psi_dot = rtb_Row1_o;

  /* Integrator: '<S6>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator2_Reset_ZCE,
                       ctrl_DP_basic_B.reset);

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
  rtb_Sum[0] = ctrl_DP_basic_B.x - ctrl_DP_basic_B.Integrator[0];
  rtb_Sum[1] = ctrl_DP_basic_B.y - ctrl_DP_basic_B.Integrator[1];
  rtb_Sum[2] = rtb_Row1_o - ctrl_DP_basic_B.Sum_f;

  /* Product: '<S6>/Matrix Multiply2' */
  for (itmp = 0; itmp < 3; itmp++) {
    rtb_MatrixMultiply[itmp] = 0.0;
    rtb_MatrixMultiply[itmp] += ctrl_DP_basic_B.sf_MATLABFunction2_p.K_d[itmp] *
      rtb_Sum[0];
    rtb_MatrixMultiply[itmp] += ctrl_DP_basic_B.sf_MATLABFunction2_p.K_d[itmp +
      3] * rtb_Sum[1];
    rtb_MatrixMultiply[itmp] += ctrl_DP_basic_B.sf_MATLABFunction2_p.K_d[itmp +
      6] * rtb_Sum[2];
  }

  /* End of Product: '<S6>/Matrix Multiply2' */

  /* Fcn: '<S36>/Row2' */
  rtb_Row2_0 = rtb_MatrixMultiply[0];
  rtb_Row1 = rtb_MatrixMultiply[1];

  /* Fcn: '<S36>/Row3' */
  rtb_Row2 = rtb_MatrixMultiply[2];

  /* Sum: '<S6>/Sum2' incorporates:
   *  Fcn: '<S36>/Row1'
   *  Fcn: '<S36>/Row2'
   *  Fcn: '<S36>/Row3'
   *  Fcn: '<S6>/Fcn'
   */
  rtb_MatrixMultiply[0] = (cos(rtb_Row1_o) * rtb_MatrixMultiply[0] + sin
    (rtb_Row1_o) * rtb_MatrixMultiply[1]) + ctrl_DP_basic_B.Sum3[0];
  rtb_MatrixMultiply[1] = (-sin(rtb_Row1_o) * rtb_Row2_0 + cos(rtb_Row1_o) *
    rtb_Row1) + ctrl_DP_basic_B.Sum3[1];
  rtb_MatrixMultiply[2] = rtb_Row2 + ctrl_DP_basic_B.Sum3[2];

  /* MATLAB Function: '<S6>/C(nu)*nu' */
  /* MATLAB Function 'Nonlinear Passisve Observer/D(nu)*nu': '<S34>:1' */
  /* '<S34>:1:3' */
  /* '<S34>:1:4' */
  /* '<S34>:1:5' */
  /* % DAMPING  */
  /*  Surge: */
  /*  Based on fitting of towing data from -0.8 < u < 0.8 m/s */
  /* '<S34>:1:11' */
  /*  Sway: */
  /*  Based on fitting of towing data from -0.45 < u < 0.45 m/s */
  /* '<S34>:1:17' */
  /*  Yaw: */
  /*  Based on fitting of towing data from -8 < u < 8 deg/s */
  /*  The fitting range is limited. Towing should be performed for higher */
  /*  velocities. */
  /* '<S34>:1:25' */
  /*  Y_vvv og N_rrr er fra curvefitting uten minus, men ser ut til å fungere */
  /*  med minus.  */
  /* % Assembly of the damping matrix */
  /* '<S34>:1:40' */
  /* '<S34>:1:41' */
  /* '<S34>:1:42' */
  /*  Y_r + Y_rr*abs(r) + Y_rrr*r^2 + Y_vr*abs(v); Not verified, temporarily disabled */
  /*  N_v + N_vv*abs(v) + N_vvv*v^2 + N_rv*abs(r); Not verified, temporarily disabled */
  /* '<S34>:1:47' */
  /* '<S34>:1:54' */
  /* MATLAB Function 'Nonlinear Passisve Observer/C(nu)*nu': '<S33>:1' */
  /* '<S33>:1:3' */
  /* '<S33>:1:4' */
  /* '<S33>:1:5' */
  /* % MATRICES */
  /* 0.0432; */
  /* % Added mass */
  /* % Correolis matrix */
  /* '<S33>:1:14' */
  rtb_Row2 = -99.03 * ctrl_DP_basic_B.Integrator1_g[1] - -0.525 *
    ctrl_DP_basic_B.Integrator1_g[2];

  /* '<S33>:1:15' */
  rtb_Row1 = 124.658 * ctrl_DP_basic_B.Integrator1_g[0];

  /* Sum: '<S6>/Sum3' incorporates:
   *  Fcn: '<S37>/Row1'
   *  Fcn: '<S37>/Row2'
   *  Fcn: '<S37>/Row3'
   *  Fcn: '<S6>/Fcn'
   */
  /* '<S33>:1:17' */
  /* '<S33>:1:24' */
  tmp[0] = cos(rtb_Row1_o) * ctrl_DP_basic_B.Integrator2[0] + sin(rtb_Row1_o) *
    ctrl_DP_basic_B.Integrator2[1];
  tmp[1] = -sin(rtb_Row1_o) * ctrl_DP_basic_B.Integrator2[0] + cos(rtb_Row1_o) *
    ctrl_DP_basic_B.Integrator2[1];
  tmp[2] = ctrl_DP_basic_B.Integrator2[2];

  /* MATLAB Function: '<S6>/D(nu)*nu' */
  tmp_0[0] = (0.0 * fabs(ctrl_DP_basic_B.Integrator1_g[0]) + -2.332) +
    ctrl_DP_basic_B.Integrator1_g[0] * ctrl_DP_basic_B.Integrator1_g[0] * -8.557;
  tmp_0[3] = 0.0;
  tmp_0[6] = 0.0;
  tmp_0[1] = 0.0;
  tmp_0[4] = (0.3976 * fabs(ctrl_DP_basic_B.Integrator1_g[1]) + -4.673) +
    ctrl_DP_basic_B.Integrator1_g[1] * ctrl_DP_basic_B.Integrator1_g[1] * -313.3;
  tmp_0[7] = 0.0;
  tmp_0[2] = 0.0;
  tmp_0[5] = 0.0;
  tmp_0[8] = (-0.01148 * fabs(ctrl_DP_basic_B.Integrator1_g[2]) + -0.01675) +
    ctrl_DP_basic_B.Integrator1_g[2] * ctrl_DP_basic_B.Integrator1_g[2] *
    -0.0003578;
  for (itmp = 0; itmp < 3; itmp++) {
    rtb_y_n[3 * itmp] = -tmp_0[3 * itmp];
    rtb_y_n[1 + 3 * itmp] = -tmp_0[3 * itmp + 1];
    rtb_y_n[2 + 3 * itmp] = -tmp_0[3 * itmp + 2];
  }

  /* MATLAB Function: '<S6>/C(nu)*nu' */
  tmp_1[0] = 0.0;
  tmp_1[3] = 0.0;
  tmp_1[6] = rtb_Row2;
  tmp_1[1] = 0.0;
  tmp_1[4] = 0.0;
  tmp_1[7] = rtb_Row1;
  tmp_1[2] = -rtb_Row2;
  tmp_1[5] = -rtb_Row1;
  tmp_1[8] = 0.0;

  /* Sum: '<S6>/Sum3' incorporates:
   *  MATLAB Function: '<S6>/D(nu)*nu'
   */
  for (itmp = 0; itmp < 3; itmp++) {
    rtb_TmpSignalConversionAtSFu_pa[itmp] = (tmp[itmp] + rtb_MatrixMultiply[itmp])
      - ((rtb_y_n[itmp + 3] * ctrl_DP_basic_B.Integrator1_g[1] + rtb_y_n[itmp] *
          ctrl_DP_basic_B.Integrator1_g[0]) + rtb_y_n[itmp + 6] *
         ctrl_DP_basic_B.Integrator1_g[2]);
  }

  /* MATLAB Function: '<S6>/C(nu)*nu' incorporates:
   *  Sum: '<S6>/Sum3'
   */
  for (itmp = 0; itmp < 3; itmp++) {
    tmp[itmp] = tmp_1[itmp + 6] * ctrl_DP_basic_B.Integrator1_g[2] + (tmp_1[itmp
      + 3] * ctrl_DP_basic_B.Integrator1_g[1] + tmp_1[itmp] *
      ctrl_DP_basic_B.Integrator1_g[0]);
  }

  /* Sum: '<S6>/Sum3' */
  rtb_MatrixMultiply[0] = rtb_TmpSignalConversionAtSFu_pa[0] - tmp[0];
  rtb_MatrixMultiply[1] = rtb_TmpSignalConversionAtSFu_pa[1] - tmp[1];
  rtb_MatrixMultiply[2] = rtb_TmpSignalConversionAtSFu_pa[2] - tmp[2];

  /* Gain: '<S6>/M^-1' */
  for (itmp = 0; itmp < 3; itmp++) {
    ctrl_DP_basic_B.M1[itmp] = 0.0;
    ctrl_DP_basic_B.M1[itmp] += ctrl_DP_basic_P.M1_Gain[itmp] *
      rtb_MatrixMultiply[0];
    ctrl_DP_basic_B.M1[itmp] += ctrl_DP_basic_P.M1_Gain[itmp + 3] *
      rtb_MatrixMultiply[1];
    ctrl_DP_basic_B.M1[itmp] += ctrl_DP_basic_P.M1_Gain[itmp + 6] *
      rtb_MatrixMultiply[2];
  }

  /* End of Gain: '<S6>/M^-1' */

  /* Integrator: '<S15>/Integrator2' */
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &ctrl_DP_basic_PrevZCX.Integrator2_Reset_ZCE_m,
                       ctrl_DP_basic_B.reset);

    /* evaluate zero-crossings */
    if (zcEvent) {
      ctrl_DP_basic_X.Integrator2_CSTATE_e[0] = ctrl_DP_basic_P.Integrator2_IC_h;
      ctrl_DP_basic_X.Integrator2_CSTATE_e[1] = ctrl_DP_basic_P.Integrator2_IC_h;
      ctrl_DP_basic_X.Integrator2_CSTATE_e[2] = ctrl_DP_basic_P.Integrator2_IC_h;
    }
  }

  rtb_MatrixMultiply[0] = ctrl_DP_basic_X.Integrator2_CSTATE_e[0];
  rtb_MatrixMultiply[1] = ctrl_DP_basic_X.Integrator2_CSTATE_e[1];
  rtb_MatrixMultiply[2] = ctrl_DP_basic_X.Integrator2_CSTATE_e[2];

  /* MATLAB Function: '<S15>/w_d^-2' */
  /* MATLAB Function 'Guidance/Reference model/w_d^3': '<S20>:1' */
  /* '<S20>:1:4' */
  /* MATLAB Function 'Guidance/Reference model/w_d^-2': '<S19>:1' */
  /* '<S19>:1:4' */
  for (itmp = 0; itmp < 3; itmp++) {
    for (p3 = 0; p3 < 3; p3++) {
      U[itmp + 3 * p3] = 0.0;
      U[itmp + 3 * p3] += rtb_w_d[3 * p3] * rtb_w_d[itmp];
      U[itmp + 3 * p3] += rtb_w_d[3 * p3 + 1] * rtb_w_d[itmp + 3];
      U[itmp + 3 * p3] += rtb_w_d[3 * p3 + 2] * rtb_w_d[itmp + 6];
    }
  }

  memcpy(&S_singular_cross[0], &U[0], 9U * sizeof(real_T));
  p1 = 0;
  p2 = 3;
  p3 = 6;
  rtb_Row2 = fabs(U[0]);
  rtb_Row1 = fabs(U[1]);
  rtb_Row1_o = fabs(U[2]);
  if ((rtb_Row1 > rtb_Row2) && (rtb_Row1 > rtb_Row1_o)) {
    p1 = 3;
    p2 = 0;
    S_singular_cross[0] = U[1];
    S_singular_cross[1] = U[0];
    S_singular_cross[3] = U[4];
    S_singular_cross[4] = U[3];
    S_singular_cross[6] = U[7];
    S_singular_cross[7] = U[6];
  } else {
    if (rtb_Row1_o > rtb_Row2) {
      p1 = 6;
      p3 = 0;
      S_singular_cross[0] = U[2];
      S_singular_cross[2] = U[0];
      S_singular_cross[3] = U[5];
      S_singular_cross[5] = U[3];
      S_singular_cross[6] = U[8];
      S_singular_cross[8] = U[6];
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
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    S_singular_cross[1] = rtb_Row1;
    S_singular_cross[2] = rtb_Row2;
    rtb_Row2 = S_singular_cross[4];
    S_singular_cross[4] = S_singular_cross[5];
    S_singular_cross[5] = rtb_Row2;
    rtb_Row2 = S_singular_cross[7];
    S_singular_cross[7] = S_singular_cross[8];
    S_singular_cross[8] = rtb_Row2;
  }

  rtb_Row1_o = S_singular_cross[5];
  rtb_Row2_0 = S_singular_cross[4];
  rtb_Row2 = S_singular_cross[5] / S_singular_cross[4];
  S_singular_cross[8] -= rtb_Row2 * S_singular_cross[7];
  rtb_Row2 = (rtb_Row2 * S_singular_cross[1] - S_singular_cross[2]) /
    S_singular_cross[8];
  rtb_Row1 = -(S_singular_cross[7] * rtb_Row2 + S_singular_cross[1]) /
    S_singular_cross[4];
  rtb_y_n[p1] = ((1.0 - S_singular_cross[3] * rtb_Row1) - S_singular_cross[6] *
                 rtb_Row2) / S_singular_cross[0];
  rtb_y_n[p1 + 1] = rtb_Row1;
  rtb_y_n[p1 + 2] = rtb_Row2;
  rtb_Row2 = -(rtb_Row1_o / rtb_Row2_0) / S_singular_cross[8];
  rtb_Row1 = (1.0 - S_singular_cross[7] * rtb_Row2) / S_singular_cross[4];
  rtb_y_n[p2] = -(S_singular_cross[3] * rtb_Row1 + S_singular_cross[6] *
                  rtb_Row2) / S_singular_cross[0];
  rtb_y_n[p2 + 1] = rtb_Row1;
  rtb_y_n[p2 + 2] = rtb_Row2;
  rtb_Row2 = 1.0 / S_singular_cross[8];
  rtb_Row1 = -S_singular_cross[7] * rtb_Row2 / S_singular_cross[4];
  rtb_y_n[p3] = -(S_singular_cross[3] * rtb_Row1 + S_singular_cross[6] *
                  rtb_Row2) / S_singular_cross[0];
  rtb_y_n[p3 + 1] = rtb_Row1;
  rtb_y_n[p3 + 2] = rtb_Row2;

  /* End of MATLAB Function: '<S15>/w_d^-2' */

  /* MATLAB Function: '<S15>/w_d^3' */
  for (itmp = 0; itmp < 3; itmp++) {
    for (p3 = 0; p3 < 3; p3++) {
      S_ang[itmp + 3 * p3] = 0.0;
      S_ang[itmp + 3 * p3] += rtb_w_d[3 * p3] * rtb_w_d[itmp];
      S_ang[itmp + 3 * p3] += rtb_w_d[3 * p3 + 1] * rtb_w_d[itmp + 3];
      S_ang[itmp + 3 * p3] += rtb_w_d[3 * p3 + 2] * rtb_w_d[itmp + 6];
    }
  }

  /* Product: '<S15>/Matrix Multiply1' incorporates:
   *  Sum: '<S15>/Sum'
   */
  for (itmp = 0; itmp < 3; itmp++) {
    rtb_TmpSignalConversionAtSFu_pa[itmp] = rtb_y_n[itmp + 6] *
      rtb_MatrixMultiply[2] + (rtb_y_n[itmp + 3] * rtb_MatrixMultiply[1] +
      rtb_y_n[itmp] * rtb_MatrixMultiply[0]);
  }

  /* End of Product: '<S15>/Matrix Multiply1' */

  /* MATLAB Function: '<S15>/w_d^3' incorporates:
   *  Product: '<S15>/Matrix Multiply'
   */
  for (itmp = 0; itmp < 3; itmp++) {
    for (p3 = 0; p3 < 3; p3++) {
      rtb_y_n[itmp + 3 * p3] = 0.0;
      rtb_y_n[itmp + 3 * p3] += S_ang[3 * p3] * rtb_w_d[itmp];
      rtb_y_n[itmp + 3 * p3] += S_ang[3 * p3 + 1] * rtb_w_d[itmp + 3];
      rtb_y_n[itmp + 3 * p3] += S_ang[3 * p3 + 2] * rtb_w_d[itmp + 6];
    }
  }

  /* Sum: '<S15>/Sum' incorporates:
   *  Product: '<S15>/Matrix Multiply'
   */
  rtb_Row2_0 = ctrl_DP_basic_B.x_ref - rtb_TmpSignalConversionAtSFu_pa[0];
  rtb_Row1 = ctrl_DP_basic_B.y_ref - rtb_TmpSignalConversionAtSFu_pa[1];
  rtb_Row2 = ctrl_DP_basic_B.psi_ref - rtb_TmpSignalConversionAtSFu_pa[2];

  /* Product: '<S15>/Matrix Multiply' */
  for (itmp = 0; itmp < 3; itmp++) {
    ctrl_DP_basic_B.MatrixMultiply[itmp] = 0.0;
    ctrl_DP_basic_B.MatrixMultiply[itmp] += rtb_y_n[itmp] * rtb_Row2_0;
    ctrl_DP_basic_B.MatrixMultiply[itmp] += rtb_y_n[itmp + 3] * rtb_Row1;
    ctrl_DP_basic_B.MatrixMultiply[itmp] += rtb_y_n[itmp + 6] * rtb_Row2;
  }

  /* MATLAB Function: '<S23>/diag1' incorporates:
   *  SignalConversion: '<S29>/TmpSignal ConversionAt SFunction Inport1'
   */
  /* MATLAB Function 'Guidance/Reference model/w_d*w_d': '<S17>:1' */
  /* '<S17>:1:4' */
  /* MATLAB Function 'Input/Guidance gains/diag1': '<S29>:1' */
  /* '<S29>:1:4' */
  memset(&rtb_y_n[0], 0, 9U * sizeof(real_T));
  rtb_y_n[0] = ctrl_DP_basic_B.zeta_x;
  rtb_y_n[4] = ctrl_DP_basic_B.zeta_y;
  rtb_y_n[8] = ctrl_DP_basic_B.zeta_psi;

  /* MATLAB Function: '<S15>/w_d*w_d' incorporates:
   *  Product: '<S15>/Matrix Multiply2'
   */
  /* MATLAB Function 'Guidance/Reference model/w_d*w_d1': '<S18>:1' */
  /* '<S18>:1:4' */
  for (itmp = 0; itmp < 3; itmp++) {
    for (p3 = 0; p3 < 3; p3++) {
      S_ang[itmp + 3 * p3] = 0.0;
      S_ang[itmp + 3 * p3] += rtb_w_d[3 * p3] * rtb_w_d[itmp];
      S_ang[itmp + 3 * p3] += rtb_w_d[3 * p3 + 1] * rtb_w_d[itmp + 3];
      S_ang[itmp + 3 * p3] += rtb_w_d[3 * p3 + 2] * rtb_w_d[itmp + 6];
    }
  }

  /* End of MATLAB Function: '<S15>/w_d*w_d' */

  /* MATLAB Function: '<S15>/w_d*w_d1' incorporates:
   *  Product: '<S15>/Matrix Multiply5'
   */
  for (itmp = 0; itmp < 3; itmp++) {
    for (p3 = 0; p3 < 3; p3++) {
      tmp_0[itmp + 3 * p3] = 0.0;
      tmp_0[itmp + 3 * p3] += 2.0 * rtb_y_n[itmp] * rtb_w_d[3 * p3];
      tmp_0[itmp + 3 * p3] += rtb_y_n[itmp + 3] * 2.0 * rtb_w_d[3 * p3 + 1];
      tmp_0[itmp + 3 * p3] += rtb_y_n[itmp + 6] * 2.0 * rtb_w_d[3 * p3 + 2];
    }
  }

  /* End of MATLAB Function: '<S15>/w_d*w_d1' */

  /* Sum: '<S15>/Sum2' incorporates:
   *  Product: '<S15>/Matrix Multiply2'
   *  Sum: '<S15>/Sum5'
   */
  for (itmp = 0; itmp < 3; itmp++) {
    tmp[itmp] = rtb_MatrixMultiply[itmp] - ((S_ang[itmp + 3] *
      rtb_MatrixMultiply5_idx_1 + S_ang[itmp] * rtb_MatrixMultiply5_idx_0) +
      S_ang[itmp + 6] * rtb_MatrixMultiply5_idx_2);
  }

  /* End of Sum: '<S15>/Sum2' */

  /* Product: '<S15>/Matrix Multiply5' incorporates:
   *  Sum: '<S15>/Sum5'
   */
  for (itmp = 0; itmp < 3; itmp++) {
    rtb_TmpSignalConversionAtSFu_pa[itmp] = tmp_0[itmp + 6] *
      ctrl_DP_basic_B.Integrator3[2] + (tmp_0[itmp + 3] *
      ctrl_DP_basic_B.Integrator3[1] + tmp_0[itmp] *
      ctrl_DP_basic_B.Integrator3[0]);
  }

  /* Sum: '<S15>/Sum5' */
  ctrl_DP_basic_B.Sum5[0] = tmp[0] - rtb_TmpSignalConversionAtSFu_pa[0];
  ctrl_DP_basic_B.Sum5[1] = tmp[1] - rtb_TmpSignalConversionAtSFu_pa[1];
  ctrl_DP_basic_B.Sum5[2] = tmp[2] - rtb_TmpSignalConversionAtSFu_pa[2];
  if (rtmIsMajorTimeStep(ctrl_DP_basic_M)) {
    /* MATLAB Function: '<S24>/MATLAB Function' incorporates:
     *  Constant: '<S24>/Constant'
     *  Constant: '<S24>/Constant1'
     *  Constant: '<S24>/Constant2'
     */
    ctrl_DP_basic_MATLABFunction(ctrl_DP_basic_P.Constant_Value_k,
      ctrl_DP_basic_P.Constant1_Value, ctrl_DP_basic_P.Constant2_Value,
      &ctrl_DP_basic_B.sf_MATLABFunction_l);

    /* MATLAB Function: '<S24>/MATLAB Function1' incorporates:
     *  Constant: '<S24>/Constant3'
     *  Constant: '<S24>/Constant4'
     *  Constant: '<S24>/Constant5'
     */
    ctrl_DP_basic_MATLABFunction1(ctrl_DP_basic_P.Constant3_Value,
      ctrl_DP_basic_P.Constant4_Value, ctrl_DP_basic_P.Constant5_Value,
      &ctrl_DP_basic_B.sf_MATLABFunction1_c);
  }

  /* Product: '<S6>/Matrix Multiply' */
  for (itmp = 0; itmp < 3; itmp++) {
    rtb_MatrixMultiply[itmp] = 0.0;
    rtb_MatrixMultiply[itmp] += ctrl_DP_basic_B.sf_MATLABFunction_l.K_p[itmp] *
      rtb_Sum[0];
    rtb_MatrixMultiply[itmp] += ctrl_DP_basic_B.sf_MATLABFunction_l.K_p[itmp + 3]
      * rtb_Sum[1];
    rtb_MatrixMultiply[itmp] += ctrl_DP_basic_B.sf_MATLABFunction_l.K_p[itmp + 6]
      * rtb_Sum[2];
  }

  /* End of Product: '<S6>/Matrix Multiply' */

  /* Product: '<S6>/Matrix Multiply1' */
  for (itmp = 0; itmp < 3; itmp++) {
    ctrl_DP_basic_B.MatrixMultiply1[itmp] = 0.0;
    ctrl_DP_basic_B.MatrixMultiply1[itmp] +=
      ctrl_DP_basic_B.sf_MATLABFunction1_c.K_i[itmp] * rtb_Sum[0];
    ctrl_DP_basic_B.MatrixMultiply1[itmp] +=
      ctrl_DP_basic_B.sf_MATLABFunction1_c.K_i[itmp + 3] * rtb_Sum[1];
    ctrl_DP_basic_B.MatrixMultiply1[itmp] +=
      ctrl_DP_basic_B.sf_MATLABFunction1_c.K_i[itmp + 6] * rtb_Sum[2];
  }

  /* End of Product: '<S6>/Matrix Multiply1' */

  /* Sum: '<S6>/Sum1' incorporates:
   *  Fcn: '<S35>/Fcn'
   *  Fcn: '<S35>/Fcn1'
   *  Fcn: '<S35>/Fcn2'
   */
  ctrl_DP_basic_B.Sum1[0] = (cos(rtb_psi_dot) * ctrl_DP_basic_B.Integrator1_g[0]
    - sin(rtb_psi_dot) * ctrl_DP_basic_B.Integrator1_g[1]) + rtb_MatrixMultiply
    [0];
  ctrl_DP_basic_B.Sum1[1] = (sin(rtb_psi_dot) * ctrl_DP_basic_B.Integrator1_g[0]
    + cos(rtb_psi_dot) * ctrl_DP_basic_B.Integrator1_g[1]) + rtb_MatrixMultiply
    [1];
  ctrl_DP_basic_B.Sum1[2] = rtb_MatrixMultiply[2] +
    ctrl_DP_basic_B.Integrator1_g[2];

  /* Fcn: '<S21>/Row3' */
  ctrl_DP_basic_B.Row3 = ctrl_DP_basic_B.Integrator3[2];

  /* Fcn: '<S21>/Row1' */
  ctrl_DP_basic_B.Row1 = cos(ctrl_DP_basic_B.Sum) * ctrl_DP_basic_B.Integrator3
    [0] + sin(ctrl_DP_basic_B.Sum) * ctrl_DP_basic_B.Integrator3[1];

  /* Fcn: '<S21>/Row2' */
  ctrl_DP_basic_B.Row2 = -sin(ctrl_DP_basic_B.Sum) *
    ctrl_DP_basic_B.Integrator3[0] + cos(ctrl_DP_basic_B.Sum) *
    ctrl_DP_basic_B.Integrator3[1];
}

/* Model update function */
void ctrl_DP_basic_update(void)
{
  /* Update for Integrator: '<S15>/Integrator1' */
  ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading = 0;

  /* Update for Integrator: '<S6>/Integrator' */
  ctrl_DP_basic_DW.Integrator_IWORK.IcNeedsLoading = 0;
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
  /* Derivatives for Integrator: '<S15>/Integrator1' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE[0] = ctrl_DP_basic_B.Integrator3[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE[1] = ctrl_DP_basic_B.Integrator3[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator1_CSTATE[2] = ctrl_DP_basic_B.Integrator3[2];
  }

  /* Derivatives for Integrator: '<S10>/Integrator' */
  {
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE[0] = ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[0];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE[1] = ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[1];
    ((XDot_ctrl_DP_basic_T *) ctrl_DP_basic_M->ModelData.derivs)
      ->Integrator_CSTATE[2] = ctrl_DP_basic_B.TmpSignalConversionAtMatrixMult[2];
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

  /* Derivatives for Integrator: '<S15>/Integrator3' */
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

  /* Derivatives for Integrator: '<S15>/Integrator2' */
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
  ctrl_DP_basic_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator1_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator3_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  ctrl_DP_basic_PrevZCX.Integrator2_Reset_ZCE_m = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S15>/Integrator1' */
  if (rtmIsFirstInitCond(ctrl_DP_basic_M)) {
    ctrl_DP_basic_X.Integrator1_CSTATE[0] = 0.0;
    ctrl_DP_basic_X.Integrator1_CSTATE[1] = 0.0;
    ctrl_DP_basic_X.Integrator1_CSTATE[2] = 0.0;
  }

  ctrl_DP_basic_DW.Integrator1_IWORK.IcNeedsLoading = 1;

  /* InitializeConditions for Integrator: '<S10>/Integrator' */
  ctrl_DP_basic_X.Integrator_CSTATE[0] = ctrl_DP_basic_P.Integrator_IC;
  ctrl_DP_basic_X.Integrator_CSTATE[1] = ctrl_DP_basic_P.Integrator_IC;
  ctrl_DP_basic_X.Integrator_CSTATE[2] = ctrl_DP_basic_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S6>/Integrator1' */
  ctrl_DP_basic_X.Integrator1_CSTATE_g[0] = (ctrl_DP_basic_P.Integrator1_IC[0]);
  ctrl_DP_basic_X.Integrator1_CSTATE_g[1] = (ctrl_DP_basic_P.Integrator1_IC[1]);
  ctrl_DP_basic_X.Integrator1_CSTATE_g[2] = (ctrl_DP_basic_P.Integrator1_IC[2]);

  /* InitializeConditions for Integrator: '<S15>/Integrator3' */
  ctrl_DP_basic_X.Integrator3_CSTATE[0] = ctrl_DP_basic_P.Integrator3_IC;
  ctrl_DP_basic_X.Integrator3_CSTATE[1] = ctrl_DP_basic_P.Integrator3_IC;
  ctrl_DP_basic_X.Integrator3_CSTATE[2] = ctrl_DP_basic_P.Integrator3_IC;

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

  /* InitializeConditions for Integrator: '<S15>/Integrator2' */
  ctrl_DP_basic_X.Integrator2_CSTATE_e[0] = ctrl_DP_basic_P.Integrator2_IC_h;
  ctrl_DP_basic_X.Integrator2_CSTATE_e[1] = ctrl_DP_basic_P.Integrator2_IC_h;
  ctrl_DP_basic_X.Integrator2_CSTATE_e[2] = ctrl_DP_basic_P.Integrator2_IC_h;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ctrl_DP_basic_M)) {
    rtmSetFirstInitCond(ctrl_DP_basic_M, 0);
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
  ctrl_DP_basic_M->Sizes.numBlocks = (195);/* Number of blocks */
  ctrl_DP_basic_M->Sizes.numBlockIO = (55);/* Number of block outputs */
  ctrl_DP_basic_M->Sizes.numBlockPrms = (449);/* Sum of parameter "widths" */
  return ctrl_DP_basic_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_DP_basic
 * Model version : 1.48
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Tue May 03 13:33:00 2016
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

   case 15:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 16:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 17:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 43:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
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

   case 15:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 16:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,6,Complex);

   case 17:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 21:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,8,Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 31:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 43:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
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

  // ctrl_DP_basic/Input/reset
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_DP_basic_B.reset, 0, data[index++], 0, 0);
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

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 28;
}

int32_t NumOutputPorts(void)
{
  return 39;
}

double ni_extout[39];

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

  // ctrl_DP_basic/u_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_out, 0, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/u_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_out, 1, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/u_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_out, 2, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/u_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_out, 3, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/u_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_out, 4, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/u_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_out, 5, 21,
      0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/alpha_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_out, 0,
      21, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/alpha_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_out, 1,
      21, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/alpha_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_out, 2,
      21, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/alpha_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_out, 3,
      21, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/alpha_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_out, 4,
      21, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /eta_hat output/x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator, 0,
      17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /eta_hat output/y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator, 1,
      17, 0);
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
      0, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /nu_hat output/v_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g,
      1, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /nu_hat output/r_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g,
      2, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1, 0, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1, 1, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1, 2, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2, 0,
      17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2, 1,
      17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2, 2,
      17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/alpha_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_out, 5,
      21, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/tau_N: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3, 2, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/tau_X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3, 0, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/tau_Y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3, 1, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/psi_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_B.regulationerror, 2, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/x_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_B.regulationerror, 0, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/y_tidle: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType
      (&ctrl_DP_basic_B.regulationerror, 1, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/r_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4, 2, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/u_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4, 0, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Control output/v_tilde: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4, 1, 17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance output/x_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1, 0,
      17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance output/y_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1, 1,
      17, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance output/psi_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance output/r_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row3, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance output/u_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row1, 0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_DP_basic/Guidance output/v_d: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row2, 0, 0, 0);
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

  // ctrl_DP_basic/u_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_out, 0, 21, 0);

  // ctrl_DP_basic/u_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_out, 1, 21, 0);

  // ctrl_DP_basic/u_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_out, 2, 21, 0);

  // ctrl_DP_basic/u_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_out, 3, 21, 0);

  // ctrl_DP_basic/u_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_out, 4, 21, 0);

  // ctrl_DP_basic/u_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.u_out, 5, 21, 0);

  // ctrl_DP_basic/alpha_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_out, 0, 21,
    0);

  // ctrl_DP_basic/alpha_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_out, 1, 21,
    0);

  // ctrl_DP_basic/alpha_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_out, 2, 21,
    0);

  // ctrl_DP_basic/alpha_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_out, 3, 21,
    0);

  // ctrl_DP_basic/alpha_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_out, 4, 21,
    0);

  // ctrl_DP_basic/Observer output /eta_hat output/x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator, 0,
    17, 0);

  // ctrl_DP_basic/Observer output /eta_hat output/y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator, 1,
    17, 0);

  // ctrl_DP_basic/Observer output /eta_hat output/psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum_f, 0, 0, 0);

  // ctrl_DP_basic/Observer output /nu_hat output/u_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g, 0,
    17, 0);

  // ctrl_DP_basic/Observer output /nu_hat output/v_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g, 1,
    17, 0);

  // ctrl_DP_basic/Observer output /nu_hat output/r_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1_g, 2,
    17, 0);

  // ctrl_DP_basic/Observer output /nu_dot_hat output/u_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1, 0, 17, 0);

  // ctrl_DP_basic/Observer output /nu_dot_hat output/v_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1, 1, 17, 0);

  // ctrl_DP_basic/Observer output /nu_dot_hat output/r_dot_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.M1, 2, 17, 0);

  // ctrl_DP_basic/Observer output /b_hat output/b_x_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2, 0,
    17, 0);

  // ctrl_DP_basic/Observer output /b_hat output/b_y_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2, 1,
    17, 0);

  // ctrl_DP_basic/Observer output /b_hat output/b_psi_hat: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator2, 2,
    17, 0);

  // ctrl_DP_basic/alpha_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.alpha_out, 5, 21,
    0);

  // ctrl_DP_basic/Control output/tau_N: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3, 2, 17, 0);

  // ctrl_DP_basic/Control output/tau_X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3, 0, 17, 0);

  // ctrl_DP_basic/Control output/tau_Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum3, 1, 17, 0);

  // ctrl_DP_basic/Control output/psi_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.regulationerror,
    2, 17, 0);

  // ctrl_DP_basic/Control output/x_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.regulationerror,
    0, 17, 0);

  // ctrl_DP_basic/Control output/y_tidle: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.regulationerror,
    1, 17, 0);

  // ctrl_DP_basic/Control output/r_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4, 2, 17, 0);

  // ctrl_DP_basic/Control output/u_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4, 0, 17, 0);

  // ctrl_DP_basic/Control output/v_tilde: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum4, 1, 17, 0);

  // ctrl_DP_basic/Guidance output/x_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1, 0,
    17, 0);

  // ctrl_DP_basic/Guidance output/y_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Integrator1, 1,
    17, 0);

  // ctrl_DP_basic/Guidance output/psi_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Sum, 0, 0, 0);

  // ctrl_DP_basic/Guidance output/r_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row3, 0, 0, 0);

  // ctrl_DP_basic/Guidance output/u_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row1, 0, 0, 0);

  // ctrl_DP_basic/Guidance output/v_d: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_DP_basic_B.Row2, 0, 0, 0);
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
  { 0,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat), 42, 1, 2, 0, 0 },

  { 1,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat), 42, 1, 2, 2, 0 },

  { 2, "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain), 42, 1, 2, 4, 0 },

  { 3,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value), 42, 1, 2, 6, 0 },

  { 4, "ctrl_dp_basic/Input/Observer Gains/Constant6/Value", offsetof
    (P_ctrl_DP_basic_T, Constant6_Value), 42, 1, 2, 8, 0 },

  { 5, "ctrl_dp_basic/Input/Observer Gains/Constant7/Value", offsetof
    (P_ctrl_DP_basic_T, Constant7_Value), 42, 1, 2, 10, 0 },

  { 6, "ctrl_dp_basic/Input/Observer Gains/Constant8/Value", offsetof
    (P_ctrl_DP_basic_T, Constant8_Value), 42, 1, 2, 12, 0 },

  { 7,
    "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat_j), 42, 1, 2, 14, 0 },

  { 8,
    "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat_c), 42, 1, 2, 16, 0 },

  { 9,
    "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_j), 42, 1, 2, 18, 0 },

  { 10,
    "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value_f), 42, 1, 2, 20, 0 },

  { 11,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat_a), 42, 1, 2, 22, 0 },

  { 12,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat_d), 42, 1, 2, 24, 0 },

  { 13, "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_g), 42, 1, 2, 26, 0 },

  { 14,
    "ctrl_dp_basic/Control/DP Controller/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value_p), 42, 1, 2, 28, 0 },

  { 15, "ctrl_dp_basic/Control/DP Controller/Integrator/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator_IC), 42, 1, 2, 30, 0 },

  { 16, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator1/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator1_IC), 25, 3, 2, 32, 0 },

  { 17, "ctrl_dp_basic/Guidance/Reference model/Integrator3/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator3_IC), 42, 1, 2, 34, 0 },

  { 18,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat_l), 42, 1, 2, 36, 0 },

  { 19,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat_cz), 42, 1, 2, 38, 0 },

  { 20,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_d), 42, 1, 2, 40, 0 },

  { 21,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value_p4), 42, 1, 2, 42, 0 },

  { 22,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/UpperLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_UpperSat_o), 42, 1, 2, 44, 0 },

  { 23,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Saturation/LowerLimit",
    offsetof(P_ctrl_DP_basic_T, Saturation_LowerSat_j), 42, 1, 2, 46, 0 },

  { 24,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Gain/Gain",
    offsetof(P_ctrl_DP_basic_T, Gain_Gain_h), 42, 1, 2, 48, 0 },

  { 25,
    "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]1/Constant/Value",
    offsetof(P_ctrl_DP_basic_T, Constant_Value_i), 42, 1, 2, 50, 0 },

  { 26, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator2_IC), 25, 3, 2, 52, 0 },

  { 27, "ctrl_dp_basic/Nonlinear Passisve Observer/M^-1/Gain", offsetof
    (P_ctrl_DP_basic_T, M1_Gain), 18, 9, 2, 54, 0 },

  { 28, "ctrl_dp_basic/Guidance/Reference model/Integrator2/InitialCondition",
    offsetof(P_ctrl_DP_basic_T, Integrator2_IC_h), 42, 1, 2, 56, 0 },

  { 29, "ctrl_dp_basic/Input/Observer Gains/Constant/Value", offsetof
    (P_ctrl_DP_basic_T, Constant_Value_k), 42, 1, 2, 58, 0 },

  { 30, "ctrl_dp_basic/Input/Observer Gains/Constant1/Value", offsetof
    (P_ctrl_DP_basic_T, Constant1_Value), 42, 1, 2, 60, 0 },

  { 31, "ctrl_dp_basic/Input/Observer Gains/Constant2/Value", offsetof
    (P_ctrl_DP_basic_T, Constant2_Value), 42, 1, 2, 62, 0 },

  { 32, "ctrl_dp_basic/Input/Observer Gains/Constant3/Value", offsetof
    (P_ctrl_DP_basic_T, Constant3_Value), 42, 1, 2, 64, 0 },

  { 33, "ctrl_dp_basic/Input/Observer Gains/Constant4/Value", offsetof
    (P_ctrl_DP_basic_T, Constant4_Value), 42, 1, 2, 66, 0 },

  { 34, "ctrl_dp_basic/Input/Observer Gains/Constant5/Value", offsetof
    (P_ctrl_DP_basic_T, Constant5_Value), 42, 1, 2, 68, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 35;
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
  3, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  3, 1,                                /* Parameter at index 26 */
  3, 3,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_dp_basic/Input/Control Gains/K_p_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_p_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 1, "ctrl_dp_basic/Input/Control Gains/K_p_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_p_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 2, "ctrl_dp_basic/Input/Control Gains/K_p_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_p_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 3, "ctrl_dp_basic/Input/Control Gains/K_i_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_i_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 4, "ctrl_dp_basic/Input/Control Gains/K_i_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_i_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 5, "ctrl_dp_basic/Input/Control Gains/K_i_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_i_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 6, "ctrl_dp_basic/Input/Control Gains/K_d_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 7, "ctrl_dp_basic/Input/Control Gains/K_d_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_d_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 8, "ctrl_dp_basic/Input/Control Gains/K_d_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, K_d_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 9, "ctrl_dp_basic/x", 0, "", offsetof(B_ctrl_DP_basic_T, x) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_dp_basic/y", 0, "", offsetof(B_ctrl_DP_basic_T, y) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_dp_basic/psi", 0, "", offsetof(B_ctrl_DP_basic_T, psi) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_dp_basic/Input/reset", 0, "", offsetof(B_ctrl_DP_basic_T, reset) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_dp_basic/Input/Guidance gains/w_d_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, w_d_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 14, "ctrl_dp_basic/Input/Guidance gains/w_d_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, w_d_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 15, "ctrl_dp_basic/Input/Guidance gains/w_d_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, w_d_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 16, "ctrl_dp_basic/Input/Guidance gains/zeta_psi", 0, "", offsetof
    (B_ctrl_DP_basic_T, zeta_psi) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0,
    0 },

  { 17, "ctrl_dp_basic/Input/Guidance gains/zeta_x", 0, "", offsetof
    (B_ctrl_DP_basic_T, zeta_x) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 18, "ctrl_dp_basic/Input/Guidance gains/zeta_y", 0, "", offsetof
    (B_ctrl_DP_basic_T, zeta_y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 19, "ctrl_dp_basic/Input/psi_ref", 0, "", offsetof(B_ctrl_DP_basic_T,
    psi_ref) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 20, "ctrl_dp_basic/Input/x_ref", 0, "", offsetof(B_ctrl_DP_basic_T, x_ref) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 21, "ctrl_dp_basic/Input/y_ref", 0, "", offsetof(B_ctrl_DP_basic_T, y_ref) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 22, "ctrl_dp_basic/Guidance/Reference model/Integrator1/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator1) + (0*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 23, "ctrl_dp_basic/Guidance/Reference model/Integrator1/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator1) + (1*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 24, "ctrl_dp_basic/Guidance/Reference model/Integrator1/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator1) + (2*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 25, "ctrl_dp_basic/Guidance/Reference model/[-inf inf] to [-pi pi]1/Sum", 0,
    "", offsetof(B_ctrl_DP_basic_T, Sum) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 26, "ctrl_dp_basic/Control/DP Controller/Sum2", 0, "regulation error(1, 1)",
    offsetof(B_ctrl_DP_basic_T, regulationerror) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 27, "ctrl_dp_basic/Control/DP Controller/Sum2", 0, "regulation error(1, 2)",
    offsetof(B_ctrl_DP_basic_T, regulationerror) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 28, "ctrl_dp_basic/Control/DP Controller/Sum2", 0, "regulation error(1, 3)",
    offsetof(B_ctrl_DP_basic_T, regulationerror) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 29, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator1/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator1_g) + (0*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 30, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator1/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator1_g) + (1*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 31, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator1/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator1_g) + (2*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 32, "ctrl_dp_basic/Guidance/Reference model/Integrator3/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator3) + (0*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 33, "ctrl_dp_basic/Guidance/Reference model/Integrator3/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator3) + (1*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 34, "ctrl_dp_basic/Guidance/Reference model/Integrator3/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator3) + (2*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 35, "ctrl_dp_basic/Control/DP Controller/Sum4/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum4) + (0*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0
  },

  { 36, "ctrl_dp_basic/Control/DP Controller/Sum4/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum4) + (1*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0
  },

  { 37, "ctrl_dp_basic/Control/DP Controller/Sum4/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum4) + (2*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0
  },

  { 38, "ctrl_dp_basic/Control/DP Controller/Sum3/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum3) + (0*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0
  },

  { 39, "ctrl_dp_basic/Control/DP Controller/Sum3/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum3) + (1*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0
  },

  { 40, "ctrl_dp_basic/Control/DP Controller/Sum3/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum3) + (2*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0
  },

  { 41, "ctrl_dp_basic/Thruster measurment/thr_angle_2", 0, "", offsetof
    (B_ctrl_DP_basic_T, thr_angle_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 42, "ctrl_dp_basic/Thruster measurment/thr_angle_3", 0, "", offsetof
    (B_ctrl_DP_basic_T, thr_angle_3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 43, "ctrl_dp_basic/Thruster measurment/thr_angle_4", 0, "", offsetof
    (B_ctrl_DP_basic_T, thr_angle_4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 44, "ctrl_dp_basic/Thruster measurment/thr_angle_5", 0, "", offsetof
    (B_ctrl_DP_basic_T, thr_angle_5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 45, "ctrl_dp_basic/Thruster measurment/thr_angle_6", 0, "", offsetof
    (B_ctrl_DP_basic_T, thr_angle_6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 46, "ctrl_dp_basic/Thruster measurment/thr_angle_1", 0, "", offsetof
    (B_ctrl_DP_basic_T, thr_angle_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 47, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator) + (0*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 48, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator) + (1*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 49, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator) + (2*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 50, "ctrl_dp_basic/Nonlinear Passisve Observer/[-inf inf] to [-pi pi]/Sum",
    0, "", offsetof(B_ctrl_DP_basic_T, Sum_f) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 51, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator2/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator2) + (0*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 52, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator2/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator2) + (1*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 53, "ctrl_dp_basic/Nonlinear Passisve Observer/Integrator2/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, Integrator2) + (2*sizeof(real_T)), BLOCKIO_SIG,
    17, 1, 2, 0, 0 },

  { 54, "ctrl_dp_basic/Nonlinear Passisve Observer/M^-1/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_basic_T, M1) + (0*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 55, "ctrl_dp_basic/Nonlinear Passisve Observer/M^-1/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_basic_T, M1) + (1*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 56, "ctrl_dp_basic/Nonlinear Passisve Observer/M^-1/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_basic_T, M1) + (2*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 57, "ctrl_dp_basic/Guidance/Reference model/Matrix Multiply/(1, 1)", 0, "",
    offsetof(B_ctrl_DP_basic_T, MatrixMultiply) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 58, "ctrl_dp_basic/Guidance/Reference model/Matrix Multiply/(1, 2)", 0, "",
    offsetof(B_ctrl_DP_basic_T, MatrixMultiply) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 59, "ctrl_dp_basic/Guidance/Reference model/Matrix Multiply/(1, 3)", 0, "",
    offsetof(B_ctrl_DP_basic_T, MatrixMultiply) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 60, "ctrl_dp_basic/Guidance/Reference model/Sum5", 0, "(1, 1)", offsetof
    (B_ctrl_DP_basic_T, Sum5) + (0*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0
  },

  { 61, "ctrl_dp_basic/Guidance/Reference model/Sum5", 0, "(1, 2)", offsetof
    (B_ctrl_DP_basic_T, Sum5) + (1*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0
  },

  { 62, "ctrl_dp_basic/Guidance/Reference model/Sum5", 0, "(1, 3)", offsetof
    (B_ctrl_DP_basic_T, Sum5) + (2*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0
  },

  { 63, "ctrl_dp_basic/Nonlinear Passisve Observer/Matrix Multiply1/(1, 1)", 0,
    "", offsetof(B_ctrl_DP_basic_T, MatrixMultiply1) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 64, "ctrl_dp_basic/Nonlinear Passisve Observer/Matrix Multiply1/(1, 2)", 0,
    "", offsetof(B_ctrl_DP_basic_T, MatrixMultiply1) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 65, "ctrl_dp_basic/Nonlinear Passisve Observer/Matrix Multiply1/(1, 3)", 0,
    "", offsetof(B_ctrl_DP_basic_T, MatrixMultiply1) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 17, 1, 2, 0, 0 },

  { 66, "ctrl_dp_basic/Nonlinear Passisve Observer/Sum1/(1, 1)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum1) + (0*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0
  },

  { 67, "ctrl_dp_basic/Nonlinear Passisve Observer/Sum1/(1, 2)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum1) + (1*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0
  },

  { 68, "ctrl_dp_basic/Nonlinear Passisve Observer/Sum1/(1, 3)", 0, "", offsetof
    (B_ctrl_DP_basic_T, Sum1) + (2*sizeof(real_T)), BLOCKIO_SIG, 17, 1, 2, 0, 0
  },

  { 69, "ctrl_dp_basic/Guidance output/Transposed rotation  matrix in yaw2/Row3",
    0, "", offsetof(B_ctrl_DP_basic_T, Row3) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 70, "ctrl_dp_basic/Guidance output/Transposed rotation  matrix in yaw2/Row1",
    0, "", offsetof(B_ctrl_DP_basic_T, Row1) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 71, "ctrl_dp_basic/Guidance output/Transposed rotation  matrix in yaw2/Row2",
    0, "", offsetof(B_ctrl_DP_basic_T, Row2) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 72, "ctrl_dp_basic/Thrust allocation", 0, "(1, 1)", offsetof
    (B_ctrl_DP_basic_T, u_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 73, "ctrl_dp_basic/Thrust allocation", 0, "(1, 2)", offsetof
    (B_ctrl_DP_basic_T, u_out) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 74, "ctrl_dp_basic/Thrust allocation", 0, "(1, 3)", offsetof
    (B_ctrl_DP_basic_T, u_out) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 75, "ctrl_dp_basic/Thrust allocation", 0, "(1, 4)", offsetof
    (B_ctrl_DP_basic_T, u_out) + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 76, "ctrl_dp_basic/Thrust allocation", 0, "(1, 5)", offsetof
    (B_ctrl_DP_basic_T, u_out) + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 77, "ctrl_dp_basic/Thrust allocation", 0, "(1, 6)", offsetof
    (B_ctrl_DP_basic_T, u_out) + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2, 0, 0
  },

  { 78, "ctrl_dp_basic/Thrust allocation", 1, "(1, 1)", offsetof
    (B_ctrl_DP_basic_T, alpha_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2,
    0, 0 },

  { 79, "ctrl_dp_basic/Thrust allocation", 1, "(1, 2)", offsetof
    (B_ctrl_DP_basic_T, alpha_out) + (1*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2,
    0, 0 },

  { 80, "ctrl_dp_basic/Thrust allocation", 1, "(1, 3)", offsetof
    (B_ctrl_DP_basic_T, alpha_out) + (2*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2,
    0, 0 },

  { 81, "ctrl_dp_basic/Thrust allocation", 1, "(1, 4)", offsetof
    (B_ctrl_DP_basic_T, alpha_out) + (3*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2,
    0, 0 },

  { 82, "ctrl_dp_basic/Thrust allocation", 1, "(1, 5)", offsetof
    (B_ctrl_DP_basic_T, alpha_out) + (4*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2,
    0, 0 },

  { 83, "ctrl_dp_basic/Thrust allocation", 1, "(1, 6)", offsetof
    (B_ctrl_DP_basic_T, alpha_out) + (5*sizeof(real_T)), BLOCKIO_SIG, 21, 1, 2,
    0, 0 },

  { 84, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(1, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 85, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(2, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 86, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(3, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 87, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(1, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 88, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(2, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 89, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(3, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 90, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(1, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 91, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(2, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 92, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function2", 0, "(3, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2_p.K_d) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 93, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(1, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 94, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(2, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 95, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(3, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 96, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(1, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 97, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(2, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 98, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(3, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 99, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(1, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 100, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(2, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 101, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function1", 0, "(3, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1_c.K_i) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 102, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(1, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 103, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(2, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 104, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(3, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 105, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(1, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 106, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(2, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 107, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(3, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 108, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(1, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 109, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(2, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 110, "ctrl_dp_basic/Input/Observer Gains/MATLAB Function", 0, "(3, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction_l.K_p) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 111, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(1, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 112, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(2, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 113, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(3, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 114, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(1, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 115, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(2, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 116, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(3, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 117, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(1, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 118, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(2, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 119, "ctrl_dp_basic/Input/Control Gains/MATLAB Function2", 0, "(3, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction2.K_d) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 120, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(1, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 121, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(2, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 122, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(3, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 123, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(1, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 124, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(2, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 125, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(3, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 126, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(1, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 127, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(2, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 128, "ctrl_dp_basic/Input/Control Gains/MATLAB Function1", 0, "(3, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction1.K_i) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 129, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(1, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 130, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(2, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 131, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(3, 1)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 132, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(1, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 133, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(2, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 134, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(3, 2)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 135, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(1, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 136, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(2, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p) + (7*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { 137, "ctrl_dp_basic/Input/Control Gains/MATLAB Function", 0, "(3, 3)",
    offsetof(B_ctrl_DP_basic_T, sf_MATLABFunction.K_p) + (8*sizeof(real_T)),
    BLOCKIO_SIG, 18, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 138;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 67;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "Input/Control Gains/K_p_x", 0, EXT_IN, 1, 1, 1 },

  { 2, "Input/Control Gains/K_p_y", 0, EXT_IN, 1, 1, 1 },

  { 3, "Input/Control Gains/K_p_psi", 0, EXT_IN, 1, 1, 1 },

  { 4, "Input/Control Gains/K_i_psi", 0, EXT_IN, 1, 1, 1 },

  { 5, "Input/Control Gains/K_i_x", 0, EXT_IN, 1, 1, 1 },

  { 6, "Input/Control Gains/K_i_y", 0, EXT_IN, 1, 1, 1 },

  { 7, "Input/Control Gains/K_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 8, "Input/Control Gains/K_d_x", 0, EXT_IN, 1, 1, 1 },

  { 9, "Input/Control Gains/K_d_y", 0, EXT_IN, 1, 1, 1 },

  { 10, "x", 0, EXT_IN, 1, 1, 1 },

  { 11, "y", 0, EXT_IN, 1, 1, 1 },

  { 12, "psi", 0, EXT_IN, 1, 1, 1 },

  { 13, "Input/reset", 0, EXT_IN, 1, 1, 1 },

  { 14, "Input/Guidance gains/w_d_x", 0, EXT_IN, 1, 1, 1 },

  { 15, "Input/Guidance gains/w_d_y", 0, EXT_IN, 1, 1, 1 },

  { 16, "Input/Guidance gains/w_d_psi", 0, EXT_IN, 1, 1, 1 },

  { 17, "Input/Guidance gains/zeta_psi", 0, EXT_IN, 1, 1, 1 },

  { 18, "Input/Guidance gains/zeta_x", 0, EXT_IN, 1, 1, 1 },

  { 19, "Input/Guidance gains/zeta_y", 0, EXT_IN, 1, 1, 1 },

  { 20, "Input/psi_ref", 0, EXT_IN, 1, 1, 1 },

  { 21, "Input/x_ref", 0, EXT_IN, 1, 1, 1 },

  { 22, "Input/y_ref", 0, EXT_IN, 1, 1, 1 },

  { 23, "Thruster measurment/thr_angle_2", 0, EXT_IN, 1, 1, 1 },

  { 24, "Thruster measurment/thr_angle_3", 0, EXT_IN, 1, 1, 1 },

  { 25, "Thruster measurment/thr_angle_4", 0, EXT_IN, 1, 1, 1 },

  { 26, "Thruster measurment/thr_angle_5", 0, EXT_IN, 1, 1, 1 },

  { 27, "Thruster measurment/thr_angle_6", 0, EXT_IN, 1, 1, 1 },

  { 28, "Thruster measurment/thr_angle_1", 0, EXT_IN, 1, 1, 1 },

  { 1, "u_1", 0, EXT_OUT, 1, 1, 1 },

  { 2, "u_2", 0, EXT_OUT, 1, 1, 1 },

  { 3, "u_3", 0, EXT_OUT, 1, 1, 1 },

  { 4, "u_4", 0, EXT_OUT, 1, 1, 1 },

  { 5, "u_5", 0, EXT_OUT, 1, 1, 1 },

  { 6, "u_6", 0, EXT_OUT, 1, 1, 1 },

  { 7, "alpha_1", 0, EXT_OUT, 1, 1, 1 },

  { 8, "alpha_2", 0, EXT_OUT, 1, 1, 1 },

  { 9, "alpha_3", 0, EXT_OUT, 1, 1, 1 },

  { 10, "alpha_4", 0, EXT_OUT, 1, 1, 1 },

  { 11, "alpha_5", 0, EXT_OUT, 1, 1, 1 },

  { 12, "Observer output /eta_hat output/x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 13, "Observer output /eta_hat output/y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 14, "Observer output /eta_hat output/psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 15, "Observer output /nu_hat output/u_hat", 0, EXT_OUT, 1, 1, 1 },

  { 16, "Observer output /nu_hat output/v_hat", 0, EXT_OUT, 1, 1, 1 },

  { 17, "Observer output /nu_hat output/r_hat", 0, EXT_OUT, 1, 1, 1 },

  { 18, "Observer output /nu_dot_hat output/u_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 19, "Observer output /nu_dot_hat output/v_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 20, "Observer output /nu_dot_hat output/r_dot_hat", 0, EXT_OUT, 1, 1, 1 },

  { 21, "Observer output /b_hat output/b_x_hat", 0, EXT_OUT, 1, 1, 1 },

  { 22, "Observer output /b_hat output/b_y_hat", 0, EXT_OUT, 1, 1, 1 },

  { 23, "Observer output /b_hat output/b_psi_hat", 0, EXT_OUT, 1, 1, 1 },

  { 24, "alpha_6", 0, EXT_OUT, 1, 1, 1 },

  { 25, "Control output/tau_N", 0, EXT_OUT, 1, 1, 1 },

  { 26, "Control output/tau_X", 0, EXT_OUT, 1, 1, 1 },

  { 27, "Control output/tau_Y", 0, EXT_OUT, 1, 1, 1 },

  { 28, "Control output/psi_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 29, "Control output/x_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 30, "Control output/y_tidle", 0, EXT_OUT, 1, 1, 1 },

  { 31, "Control output/r_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 32, "Control output/u_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 33, "Control output/v_tilde", 0, EXT_OUT, 1, 1, 1 },

  { 34, "Guidance output/x_d", 0, EXT_OUT, 1, 1, 1 },

  { 35, "Guidance output/y_d", 0, EXT_OUT, 1, 1, 1 },

  { 36, "Guidance output/psi_d", 0, EXT_OUT, 1, 1, 1 },

  { 37, "Guidance output/r_d", 0, EXT_OUT, 1, 1, 1 },

  { 38, "Guidance output/u_d", 0, EXT_OUT, 1, 1, 1 },

  { 39, "Guidance output/v_d", 0, EXT_OUT, 1, 1, 1 },

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
static const char* NI_CompiledModelVersion = "1.48";
static const char* NI_CompiledModelDateTime = "Tue May 03 13:33:00 2016";
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
  if ((numContStates != NULL) && (numDiscStates != NULL) && (numClockTicks !=
       NULL)) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 21;
      *numDiscStates = 1007;
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK1");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_1_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_2_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_3_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_4_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_5_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_6_DWORK1, 0, 0,
      0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_1_DWORK1");
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
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_6_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_6_DWORK1");
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
    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_x_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_p_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_p_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_x_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_i_y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_i_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_x_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.K_d_y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.K_d_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.reset_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_x_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.w_d_psi_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.w_d_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.zeta_psi_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.zeta_psi_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.zeta_x_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.zeta_x_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.zeta_y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.zeta_y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_ref_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_ref_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_ref_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_ref_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_ref_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_ref_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.thr_angle_2_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.thr_angle_2_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.thr_angle_3_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.thr_angle_3_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.thr_angle_4_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.thr_angle_4_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.thr_angle_5_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.thr_angle_5_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.thr_angle_6_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.thr_angle_6_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.thr_angle_1_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.thr_angle_1_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_1_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_1_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_2_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_2_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_3_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_3_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_4_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_4_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_5_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_5_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_6_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_6_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_1_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_2_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_3_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_4_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_5_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.u_dot_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.u_dot_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.v_dot_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.v_dot_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.r_dot_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.r_dot_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.b_x_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.b_x_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.b_y_hat_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.b_y_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.b_psi_hat_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.b_psi_hat_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.alpha_6_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_N_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_N_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_X_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_X_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.tau_Y_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.tau_Y_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_DP_basic_DW.psi_tilde_DWORK2, count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_DP_basic_DW.psi_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_tilde_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_tidle_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_tidle_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_tilde_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_tilde_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_tilde_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_tilde_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.x_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.x_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.y_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.y_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.psi_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.psi_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.r_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.r_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.u_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.u_d_DWORK2");
    }

    for (count = 0; count < 14; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_DP_basic_DW.v_d_DWORK2,
        count, 20, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_DP_basic_DW.v_d_DWORK2");
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
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_DWORK1, 0, discStates[idx++], 0,
      0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK1, 0, discStates[idx++],
      0, 0);
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
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_1_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_2_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_3_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_4_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_5_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_6_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_3_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_4_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_5_DWORK1, 0, discStates[idx
      ++], 0, 0);
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
    NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_6_DWORK1, 0, discStates[idx
      ++], 0, 0);
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
    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_x_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_p_psi_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_psi_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_x_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_i_y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_psi_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_x_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.K_d_y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_DWORK2, count, discStates[idx
        ++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.reset_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_x_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.w_d_psi_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_psi_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_x_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.zeta_y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_ref_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_ref_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_ref_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_3_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_4_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_5_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_6_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.thr_angle_1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_3_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_4_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_5_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_6_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_1_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_2_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_3_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_4_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_5_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_dot_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_dot_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_dot_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_x_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_y_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.b_psi_hat_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.alpha_6_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_N_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_X_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.tau_Y_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_tilde_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_tilde_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_tidle_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_tilde_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_tilde_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_tilde_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.x_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.y_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.psi_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.r_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.u_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }

    for (count = 0; count < 14; count++) {
      NIRT_SetValueByDataType(&ctrl_DP_basic_DW.v_d_DWORK2, count,
        discStates[idx++], 20, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
    S->Timing.clockTick1 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_DP_basic
