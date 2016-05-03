/*
 * ctrl_sixaxis2force.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ctrl_sixaxis2force".
 *
 * Model version              : 1.30
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Tue Apr 19 19:23:42 2016
 *
 * Target selection: NIVeriStand_VxWorks.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit Embedded Processor
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ctrl_sixaxis2force.h"
#include "ctrl_sixaxis2force_private.h"

/* Block signals (auto storage) */
B_ctrl_sixaxis2force_T ctrl_sixaxis2force_B;

/* Block states (auto storage) */
DW_ctrl_sixaxis2force_T ctrl_sixaxis2force_DW;

/* Real-time model */
RT_MODEL_ctrl_sixaxis2force_T ctrl_sixaxis2force_M_;
RT_MODEL_ctrl_sixaxis2force_T *const ctrl_sixaxis2force_M =
  &ctrl_sixaxis2force_M_;

/* Forward declaration for local functions */
static real_T ctrl_sixaxis2force_eml_xnrm2(int32_T n, const real_T x[18],
  int32_T ix0);
static real_T ctrl_sixaxis2force_eml_xnrm2_h(int32_T n, const real_T x[6],
  int32_T ix0);
static void ctrl_sixaxis2force_eml_xaxpy_jv(int32_T n, real_T a, const real_T x
  [3], int32_T ix0, real_T y[18], int32_T iy0);
static void ctrl_sixaxis2force_eml_xaxpy_j(int32_T n, real_T a, const real_T x
  [18], int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_sixaxis2force_eml_xscal(real_T a, real_T x[9], int32_T ix0);
static void ctrl_sixaxis2force_eml_xscal_c(real_T a, real_T x[36], int32_T ix0);
static void ctrl_sixaxis2force_eml_xswap(real_T x[36], int32_T ix0, int32_T iy0);
static void ctrl_sixaxis2force_eml_xswap_f(real_T x[9], int32_T ix0, int32_T iy0);
static void ctrl_sixaxis2force_eml_xrotg(real_T *a, real_T *b, real_T *c, real_T
  *s);
static void ctrl_sixaxis2force_eml_xrot(real_T x[36], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void ctrl_sixaxis2force_eml_xrot_e(real_T x[9], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static real_T ctrl_sixaxis2force_eml_xdotc_e1(int32_T n, const real_T x[36],
  int32_T ix0, const real_T y[36], int32_T iy0);
static void ctrl_sixaxis2for_eml_xaxpy_jvvj(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0);
static real_T ctrl_sixaxis2force_eml_xdotc_e(int32_T n, const real_T x[9],
  int32_T ix0, const real_T y[9], int32_T iy0);
static void ctrl_sixaxis2forc_eml_xaxpy_jvv(int32_T n, real_T a, int32_T ix0,
  real_T y[9], int32_T iy0);
static real_T ctrl_sixaxis2force_eml_xdotc(int32_T n, const real_T x[18],
  int32_T ix0, const real_T y[18], int32_T iy0);
static void ctrl_sixaxis2force_eml_xaxpy(int32_T n, real_T a, int32_T ix0,
  real_T y[18], int32_T iy0);
static void ctrl_sixaxis2force_eml_xgesvd(const real_T A[18], real_T U[9],
  real_T S[3], real_T V[18]);
static real_T ctrl_sixaxis2force_eml_xnrm2_hu(int32_T n, const real_T x[36],
  int32_T ix0);
static real_T ctrl_sixaxis2forc_eml_xnrm2_huv(int32_T n, const real_T x[12],
  int32_T ix0);
static void ctrl_sixaxis2_eml_xaxpy_jvvjg4x(int32_T n, real_T a, const real_T x
  [3], int32_T ix0, real_T y[36], int32_T iy0);
static void ctrl_sixaxis2f_eml_xaxpy_jvvjg4(int32_T n, real_T a, const real_T x
  [36], int32_T ix0, real_T y[3], int32_T iy0);
static void ctrl_sixaxis2force_eml_xscal_c3(real_T a, real_T x[144], int32_T ix0);
static void ctrl_sixaxis2force_eml_xswap_fw(real_T x[144], int32_T ix0, int32_T
  iy0);
static void ctrl_sixaxis2force_eml_xrot_eb(real_T x[144], int32_T ix0, int32_T
  iy0, real_T c, real_T s);
static real_T ctrl_sixaxis2for_eml_xdotc_e1ga(int32_T n, const real_T x[144],
  int32_T ix0, const real_T y[144], int32_T iy0);
static void ctrl_sixaxis_eml_xaxpy_jvvjg4xw(int32_T n, real_T a, int32_T ix0,
  real_T y[144], int32_T iy0);
static real_T ctrl_sixaxis2forc_eml_xdotc_e1g(int32_T n, const real_T x[36],
  int32_T ix0, const real_T y[36], int32_T iy0);
static void ctrl_sixaxis2fo_eml_xaxpy_jvvjg(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0);
static void ctrl_sixaxis2force_eml_xgesvd_j(const real_T A[36], real_T U[9],
  real_T S[3], real_T V[36]);

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static real_T ctrl_sixaxis2force_eml_xnrm2(int32_T n, const real_T x[18],
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static real_T ctrl_sixaxis2force_eml_xnrm2_h(int32_T n, const real_T x[6],
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_sixaxis2force_eml_xaxpy_jv(int32_T n, real_T a, const real_T x
  [3], int32_T ix0, real_T y[18], int32_T iy0)
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
static void ctrl_sixaxis2force_eml_xaxpy_j(int32_T n, real_T a, const real_T x
  [18], int32_T ix0, real_T y[3], int32_T iy0)
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
static void ctrl_sixaxis2force_eml_xscal(real_T a, real_T x[9], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 2; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_sixaxis2force_eml_xscal_c(real_T a, real_T x[36], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 5; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_sixaxis2force_eml_xswap(real_T x[36], int32_T ix0, int32_T iy0)
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
static void ctrl_sixaxis2force_eml_xswap_f(real_T x[9], int32_T ix0, int32_T iy0)
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
static void ctrl_sixaxis2force_eml_xrotg(real_T *a, real_T *b, real_T *c, real_T
  *s)
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
static void ctrl_sixaxis2force_eml_xrot(real_T x[36], int32_T ix0, int32_T iy0,
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
static void ctrl_sixaxis2force_eml_xrot_e(real_T x[9], int32_T ix0, int32_T iy0,
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
static real_T ctrl_sixaxis2force_eml_xdotc_e1(int32_T n, const real_T x[36],
  int32_T ix0, const real_T y[36], int32_T iy0)
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
static void ctrl_sixaxis2for_eml_xaxpy_jvvj(int32_T n, real_T a, int32_T ix0,
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
static real_T ctrl_sixaxis2force_eml_xdotc_e(int32_T n, const real_T x[9],
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_sixaxis2forc_eml_xaxpy_jvv(int32_T n, real_T a, int32_T ix0,
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static real_T ctrl_sixaxis2force_eml_xdotc(int32_T n, const real_T x[18],
  int32_T ix0, const real_T y[18], int32_T iy0)
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
static void ctrl_sixaxis2force_eml_xaxpy(int32_T n, real_T a, int32_T ix0,
  real_T y[18], int32_T iy0)
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
static void ctrl_sixaxis2force_eml_xgesvd(const real_T A[18], real_T U[9],
  real_T S[3], real_T V[18])
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
  ztest0 = ctrl_sixaxis2force_eml_xnrm2(3, b_A, 1);
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
      ctrl_sixaxis2force_eml_xaxpy(3, -(ctrl_sixaxis2force_eml_xdotc(3, b_A, 1,
        b_A, qp1jj + 1) / b_A[0]), 1, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (i = 0; i + 1 < 4; i++) {
    U[i] = b_A[i];
  }

  ztest0 = ctrl_sixaxis2force_eml_xnrm2_h(5, e, 2);
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
      ctrl_sixaxis2force_eml_xaxpy_j(2, e[i], b_A, 3 * i + 2, work, 2);
    }

    for (i = 1; i + 1 < 7; i++) {
      ctrl_sixaxis2force_eml_xaxpy_jv(2, -e[i] / e[1], work, 2, b_A, 3 * i + 2);
    }
  }

  for (i = 1; i + 1 < 7; i++) {
    Vf[i] = e[i];
  }

  apply_transform = false;
  ztest0 = ctrl_sixaxis2force_eml_xnrm2(2, b_A, 5);
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
      ctrl_sixaxis2force_eml_xaxpy(2, -(ctrl_sixaxis2force_eml_xdotc(2, b_A, 5,
        b_A, qp1jj + 1) / b_A[4]), 5, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (i = 1; i + 1 < 4; i++) {
    U[i + 3] = b_A[i + 3];
  }

  ztest0 = ctrl_sixaxis2force_eml_xnrm2_h(4, e, 3);
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
      ctrl_sixaxis2force_eml_xaxpy_j(1, e[i], b_A, 3 * i + 3, work, 3);
    }

    for (i = 2; i + 1 < 7; i++) {
      ctrl_sixaxis2force_eml_xaxpy_jv(1, -e[i] / e[2], work, 3, b_A, 3 * i + 3);
    }
  }

  for (i = 2; i + 1 < 7; i++) {
    Vf[i + 6] = e[i];
  }

  for (kase = 3; kase + 1 < 7; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = ctrl_sixaxis2force_eml_xnrm2_h(3, e, 4);
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
        ctrl_sixaxis2forc_eml_xaxpy_jvv(3 - qs, -(ctrl_sixaxis2force_eml_xdotc_e
          (3 - qs, U, iter + 1, U, qp1jj) / U[iter]), iter + 1, U, qp1jj);
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
        ctrl_sixaxis2for_eml_xaxpy_jvvj(5 - qs,
          -(ctrl_sixaxis2force_eml_xdotc_e1(5 - qs, Vf, i, Vf, qp1jj) / Vf[i - 1]),
          i, Vf, qp1jj);
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
    ctrl_sixaxis2force_eml_xscal(ztest0, U, 1);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[1] *= ztest0;
    ctrl_sixaxis2force_eml_xscal_c(ztest0, Vf, 7);
  }

  e[0] = b;
  b = e[1];
  if (s[1] != 0.0) {
    ztest = fabs(s[1]);
    ztest0 = s[1] / ztest;
    s[1] = ztest;
    b = e[1] / ztest0;
    ctrl_sixaxis2force_eml_xscal(ztest0, U, 4);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[2] = b_A[8] * ztest0;
    ctrl_sixaxis2force_eml_xscal_c(ztest0, Vf, 13);
  }

  e[1] = b;
  b = e[2];
  if (s[2] != 0.0) {
    ztest = fabs(s[2]);
    ztest0 = s[2] / ztest;
    s[2] = ztest;
    b = e[2] / ztest0;
    ctrl_sixaxis2force_eml_xscal(ztest0, U, 7);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[3] = 0.0 * ztest0;
    ctrl_sixaxis2force_eml_xscal_c(ztest0, Vf, 19);
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
        ctrl_sixaxis2force_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        if (kase + 1 > q + 1) {
          f = e[kase - 1] * -b;
          e[kase - 1] *= ztest;
        }

        ctrl_sixaxis2force_eml_xrot(Vf, 1 + 6 * kase, 1 + 6 * (m + 1), ztest, b);
      }
      break;

     case 2:
      f = e[q - 1];
      e[q - 1] = 0.0;
      for (kase = q; kase + 1 <= m + 2; kase++) {
        ztest0 = s[kase];
        ctrl_sixaxis2force_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        f = -b * e[kase];
        e[kase] *= ztest;
        ctrl_sixaxis2force_eml_xrot_e(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest, b);
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
        ctrl_sixaxis2force_eml_xrotg(&f, &b, &ztest0, &ztest);
        if (kase > q + 1) {
          e[kase - 2] = f;
        }

        f = s[kase - 1] * ztest0 + e[kase - 1] * ztest;
        e[kase - 1] = e[kase - 1] * ztest0 - s[kase - 1] * ztest;
        b = ztest * s[kase];
        s[kase] *= ztest0;
        ctrl_sixaxis2force_eml_xrot(Vf, 1 + 6 * (kase - 1), 1 + 6 * kase, ztest0,
          ztest);
        ctrl_sixaxis2force_eml_xrotg(&f, &b, &ztest0, &ztest);
        s[kase - 1] = f;
        f = e[kase - 1] * ztest0 + ztest * s[kase];
        s[kase] = e[kase - 1] * -ztest + ztest0 * s[kase];
        b = ztest * e[kase];
        e[kase] *= ztest0;
        if (kase < 3) {
          ctrl_sixaxis2force_eml_xrot_e(U, 1 + 3 * (kase - 1), 1 + 3 * kase,
            ztest0, ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_sixaxis2force_eml_xscal_c(-1.0, Vf, 1 + 6 * q);
      }

      i = q + 1;
      while ((q + 1 < 4) && (s[q] < s[i])) {
        ztest = s[q];
        s[q] = s[i];
        s[i] = ztest;
        ctrl_sixaxis2force_eml_xswap(Vf, 1 + 6 * q, 1 + 6 * (q + 1));
        if (q + 1 < 3) {
          ctrl_sixaxis2force_eml_xswap_f(U, 1 + 3 * q, 1 + 3 * (q + 1));
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
static real_T ctrl_sixaxis2force_eml_xnrm2_hu(int32_T n, const real_T x[36],
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static real_T ctrl_sixaxis2forc_eml_xnrm2_huv(int32_T n, const real_T x[12],
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_sixaxis2_eml_xaxpy_jvvjg4x(int32_T n, real_T a, const real_T x
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
static void ctrl_sixaxis2f_eml_xaxpy_jvvjg4(int32_T n, real_T a, const real_T x
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
static void ctrl_sixaxis2force_eml_xscal_c3(real_T a, real_T x[144], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 11; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_sixaxis2force_eml_xswap_fw(real_T x[144], int32_T ix0, int32_T
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_sixaxis2force_eml_xrot_eb(real_T x[144], int32_T ix0, int32_T
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static real_T ctrl_sixaxis2for_eml_xdotc_e1ga(int32_T n, const real_T x[144],
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
static void ctrl_sixaxis_eml_xaxpy_jvvjg4xw(int32_T n, real_T a, int32_T ix0,
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
static real_T ctrl_sixaxis2forc_eml_xdotc_e1g(int32_T n, const real_T x[36],
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

/* Function for MATLAB Function: '<Root>/Thrust allocation' */
static void ctrl_sixaxis2fo_eml_xaxpy_jvvjg(int32_T n, real_T a, int32_T ix0,
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
static void ctrl_sixaxis2force_eml_xgesvd_j(const real_T A[36], real_T U[9],
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
  ztest0 = ctrl_sixaxis2force_eml_xnrm2_hu(3, b_A, 1);
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
      ctrl_sixaxis2fo_eml_xaxpy_jvvjg(3, -(ctrl_sixaxis2forc_eml_xdotc_e1g(3,
        b_A, 1, b_A, qp1jj + 1) / b_A[0]), 1, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 0; qp1 + 1 < 4; qp1++) {
    U[qp1] = b_A[qp1];
  }

  ztest0 = ctrl_sixaxis2forc_eml_xnrm2_huv(11, e, 2);
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
      ctrl_sixaxis2f_eml_xaxpy_jvvjg4(2, e[qp1], b_A, 3 * qp1 + 2, work, 2);
    }

    for (qp1 = 1; qp1 + 1 < 13; qp1++) {
      ctrl_sixaxis2_eml_xaxpy_jvvjg4x(2, -e[qp1] / e[1], work, 2, b_A, 3 * qp1 +
        2);
    }
  }

  for (qp1 = 1; qp1 + 1 < 13; qp1++) {
    Vf[qp1] = e[qp1];
  }

  apply_transform = false;
  ztest0 = ctrl_sixaxis2force_eml_xnrm2_hu(2, b_A, 5);
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
      ctrl_sixaxis2fo_eml_xaxpy_jvvjg(2, -(ctrl_sixaxis2forc_eml_xdotc_e1g(2,
        b_A, 5, b_A, qp1jj + 1) / b_A[4]), 5, b_A, qp1jj + 1);
    }

    e[kase] = b_A[qp1jj];
  }

  for (qp1 = 1; qp1 + 1 < 4; qp1++) {
    U[qp1 + 3] = b_A[qp1 + 3];
  }

  ztest0 = ctrl_sixaxis2forc_eml_xnrm2_huv(10, e, 3);
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
      ctrl_sixaxis2f_eml_xaxpy_jvvjg4(1, e[qp1], b_A, 3 * qp1 + 3, work, 3);
    }

    for (qp1 = 2; qp1 + 1 < 13; qp1++) {
      ctrl_sixaxis2_eml_xaxpy_jvvjg4x(1, -e[qp1] / e[2], work, 3, b_A, 3 * qp1 +
        3);
    }
  }

  for (qp1 = 2; qp1 + 1 < 13; qp1++) {
    Vf[qp1 + 12] = e[qp1];
  }

  for (kase = 3; kase + 1 < 13; kase++) {
    e[kase] = b_A[3 * kase + 2];
  }

  ztest0 = ctrl_sixaxis2forc_eml_xnrm2_huv(9, e, 4);
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
        ctrl_sixaxis2forc_eml_xaxpy_jvv(3 - qs, -(ctrl_sixaxis2force_eml_xdotc_e
          (3 - qs, U, iter + 1, U, qp1jj) / U[iter]), iter + 1, U, qp1jj);
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
        ctrl_sixaxis_eml_xaxpy_jvvjg4xw(11 - qs,
          -(ctrl_sixaxis2for_eml_xdotc_e1ga(11 - qs, Vf, qp1, Vf, qp1jj) /
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
    ctrl_sixaxis2force_eml_xscal(ztest0, U, 1);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[1] *= ztest0;
    ctrl_sixaxis2force_eml_xscal_c3(ztest0, Vf, 13);
  }

  e[0] = b;
  b = e[1];
  if (s[1] != 0.0) {
    ztest = fabs(s[1]);
    ztest0 = s[1] / ztest;
    s[1] = ztest;
    b = e[1] / ztest0;
    ctrl_sixaxis2force_eml_xscal(ztest0, U, 4);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[2] = b_A[8] * ztest0;
    ctrl_sixaxis2force_eml_xscal_c3(ztest0, Vf, 25);
  }

  e[1] = b;
  b = e[2];
  if (s[2] != 0.0) {
    ztest = fabs(s[2]);
    ztest0 = s[2] / ztest;
    s[2] = ztest;
    b = e[2] / ztest0;
    ctrl_sixaxis2force_eml_xscal(ztest0, U, 7);
  }

  if (b != 0.0) {
    ztest = fabs(b);
    ztest0 = ztest / b;
    b = ztest;
    s[3] = 0.0 * ztest0;
    ctrl_sixaxis2force_eml_xscal_c3(ztest0, Vf, 37);
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
        ctrl_sixaxis2force_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        if (kase + 1 > q + 1) {
          f = e[kase - 1] * -b;
          e[kase - 1] *= ztest;
        }

        ctrl_sixaxis2force_eml_xrot_eb(Vf, 1 + 12 * kase, 1 + 12 * (m + 1),
          ztest, b);
      }
      break;

     case 2:
      f = e[q - 1];
      e[q - 1] = 0.0;
      for (kase = q; kase + 1 <= m + 2; kase++) {
        ztest0 = s[kase];
        ctrl_sixaxis2force_eml_xrotg(&ztest0, &f, &ztest, &b);
        s[kase] = ztest0;
        f = -b * e[kase];
        e[kase] *= ztest;
        ctrl_sixaxis2force_eml_xrot_e(U, 1 + 3 * kase, 1 + 3 * (q - 1), ztest, b);
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
        ctrl_sixaxis2force_eml_xrotg(&f, &b, &ztest0, &ztest);
        if (kase > q + 1) {
          e[kase - 2] = f;
        }

        f = s[kase - 1] * ztest0 + e[kase - 1] * ztest;
        e[kase - 1] = e[kase - 1] * ztest0 - s[kase - 1] * ztest;
        b = ztest * s[kase];
        s[kase] *= ztest0;
        ctrl_sixaxis2force_eml_xrot_eb(Vf, 1 + 12 * (kase - 1), 1 + 12 * kase,
          ztest0, ztest);
        ctrl_sixaxis2force_eml_xrotg(&f, &b, &ztest0, &ztest);
        s[kase - 1] = f;
        f = e[kase - 1] * ztest0 + ztest * s[kase];
        s[kase] = e[kase - 1] * -ztest + ztest0 * s[kase];
        b = ztest * e[kase];
        e[kase] *= ztest0;
        if (kase < 3) {
          ctrl_sixaxis2force_eml_xrot_e(U, 1 + 3 * (kase - 1), 1 + 3 * kase,
            ztest0, ztest);
        }
      }

      e[m] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        ctrl_sixaxis2force_eml_xscal_c3(-1.0, Vf, 1 + 12 * q);
      }

      qp1 = q + 1;
      while ((q + 1 < 4) && (s[q] < s[qp1])) {
        ztest = s[q];
        s[q] = s[qp1];
        s[qp1] = ztest;
        ctrl_sixaxis2force_eml_xswap_fw(Vf, 1 + 12 * q, 1 + 12 * (q + 1));
        if (q + 1 < 3) {
          ctrl_sixaxis2force_eml_xswap_f(U, 1 + 3 * q, 1 + 3 * (q + 1));
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
static void ctrl_sixaxis2force_output(void)
{
  real_T b_signal;
  real_T T_surge[6];
  real_T T_sway[6];
  real_T T_yaw[6];
  real_T S_singular_cross[9];
  real_T S_ang[9];
  real_T T0[12];
  int32_T i;
  int32_T b_i;
  real_T U[9];
  real_T s[3];
  real_T V[18];
  real_T b_U[9];
  real_T b_V[36];
  static const real_T d[6] = { 1.0677777777777777, 0.99111111111111116,
    0.99111111111111116, -1.1644444444444444, -0.99111111111111116,
    -0.99111111111111116 };

  static const real_T e[6] = { 0.0, 0.11, -0.11, 0.0, -0.16555555555555557,
    0.16555555555555557 };

  static const real_T A[36] = { 1.0, 0.0, 0.0, 0.0, 1.0, 1.0677777777777777, 1.0,
    0.0, 0.11, 0.0, 1.0, 0.99111111111111116, 1.0, 0.0, -0.11, 0.0, 1.0,
    0.99111111111111116, 1.0, 0.0, 0.0, 0.0, 1.0, -1.1644444444444444, 1.0, 0.0,
    -0.16555555555555557, 0.0, 1.0, -0.99111111111111116, 1.0, 0.0,
    0.16555555555555557, 0.0, 1.0, -0.99111111111111116 };

  boolean_T f[9];
  real_T rtb_TmpSignalConversionAtSFunct[6];
  real_T T_surge_0[18];
  real_T b_V_0[36];
  int32_T b_data[9];
  int32_T b_sizes;
  int32_T c_data[9];
  boolean_T f_0;

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Memory: '<S2>/Memory'
   *  RelationalOperator: '<S3>/FixPt Relational Operator'
   *  RelationalOperator: '<S4>/FixPt Relational Operator'
   *  RelationalOperator: '<S5>/FixPt Relational Operator'
   *  UnitDelay: '<S3>/Delay Input1'
   *  UnitDelay: '<S4>/Delay Input1'
   *  UnitDelay: '<S5>/Delay Input1'
   */
  /* MATLAB Function 'u_limiter/MATLAB Function': '<S6>:1' */
  /* '<S6>:1:5' */
  b_signal = ctrl_sixaxis2force_DW.Memory_PreviousInput;
  if (ctrl_sixaxis2force_B.ArrowUp > ctrl_sixaxis2force_DW.DelayInput1_DSTATE) {
    /* '<S6>:1:7' */
    /* '<S6>:1:8' */
    b_signal = ctrl_sixaxis2force_DW.Memory_PreviousInput + 0.25;
    if (ctrl_sixaxis2force_DW.Memory_PreviousInput + 0.25 > 12.0) {
      /* '<S6>:1:10' */
      /* '<S6>:1:11' */
      b_signal = 12.0;
    }
  }

  if (ctrl_sixaxis2force_B.ArrowDown >
      ctrl_sixaxis2force_DW.DelayInput1_DSTATE_l) {
    /* '<S6>:1:15' */
    /* '<S6>:1:16' */
    b_signal -= 0.25;
    if (b_signal < -12.0) {
      /* '<S6>:1:18' */
      /* '<S6>:1:19' */
      b_signal = -12.0;
    }
  }

  if (ctrl_sixaxis2force_B.Start > ctrl_sixaxis2force_DW.DelayInput1_DSTATE_g) {
    /* '<S6>:1:23' */
    /* '<S6>:1:24' */
    b_signal = 0.0;
  }

  /* '<S6>:1:29' */
  ctrl_sixaxis2force_B.y = b_signal;

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* Product: '<Root>/Product1' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  ctrl_sixaxis2force_B.Product1 = ctrl_sixaxis2force_P.Gain1_Gain *
    ctrl_sixaxis2force_B.PosYLeft * ctrl_sixaxis2force_B.y;

  /* Product: '<Root>/Product2' */
  ctrl_sixaxis2force_B.Product2 = ctrl_sixaxis2force_B.PosXLeft *
    ctrl_sixaxis2force_B.y;

  /* Product: '<Root>/Product' incorporates:
   *  Gain: '<Root>/Gain'
   *  Sum: '<Root>/Sum'
   */
  ctrl_sixaxis2force_B.Product = (ctrl_sixaxis2force_B.L2_continuous -
    ctrl_sixaxis2force_B.R2_continuous) * ctrl_sixaxis2force_P.Gain_Gain *
    ctrl_sixaxis2force_B.y;

  /* SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport4' incorporates:
   *  MATLAB Function: '<Root>/Thrust allocation'
   */
  rtb_TmpSignalConversionAtSFunct[0] = ctrl_sixaxis2force_B.thr_angle_1;
  rtb_TmpSignalConversionAtSFunct[1] = ctrl_sixaxis2force_B.thr_angle_2;
  rtb_TmpSignalConversionAtSFunct[2] = ctrl_sixaxis2force_B.thr_angle_3;
  rtb_TmpSignalConversionAtSFunct[3] = ctrl_sixaxis2force_B.thr_angle_4;
  rtb_TmpSignalConversionAtSFunct[4] = ctrl_sixaxis2force_B.thr_angle_5;
  rtb_TmpSignalConversionAtSFunct[5] = ctrl_sixaxis2force_B.thr_angle_6;

  /* MATLAB Function: '<Root>/Thrust allocation' */
  /* MATLAB Function 'Thrust allocation': '<S1>:1' */
  /* '<S1>:1:4' */
  /* [m,m] */
  /* [m,m]  */
  /* [m,m] */
  /* '<S1>:1:12' */
  /* [x(1),x(2),x(3),x(4),x(5),x(6)]'; */
  /* '<S1>:1:13' */
  /* [x(7),x(8),x(9),x(10),x(11),x(12)]'; */
  /* '<S1>:1:18' */
  /*  Shells for faster computing */
  /* '<S1>:1:19' */
  /*  Shells for faster computing */
  /* '<S1>:1:20' */
  /*  Shells for faster computing */
  /* '<S1>:1:22' */
  for (i = 0; i < 6; i++) {
    /* '<S1>:1:22' */
    /* '<S1>:1:23' */
    T_surge[i] = cos(rtb_TmpSignalConversionAtSFunct[i]);

    /* Thrust in x-direction for cartesian */
    /* '<S1>:1:24' */
    T_sway[i] = sin(rtb_TmpSignalConversionAtSFunct[i]);

    /* Thrust in y-direction for cartesian */
    /* '<S1>:1:25' */
    T_yaw[i] = sin(rtb_TmpSignalConversionAtSFunct[i]) * d[i] - cos
      (rtb_TmpSignalConversionAtSFunct[i]) * e[i];

    /* '<S1>:1:22' */
  }

  /* '<S1>:1:28' */
  for (b_i = 0; b_i < 6; b_i++) {
    T_surge_0[3 * b_i] = T_surge[b_i];
  }

  for (b_i = 0; b_i < 6; b_i++) {
    T_surge_0[1 + 3 * b_i] = T_sway[b_i];
  }

  for (b_i = 0; b_i < 6; b_i++) {
    T_surge_0[2 + 3 * b_i] = T_yaw[b_i];
  }

  ctrl_sixaxis2force_eml_xgesvd(T_surge_0, U, s, V);
  memset(&S_singular_cross[0], 0, 9U * sizeof(real_T));
  S_singular_cross[0] = s[0];
  S_singular_cross[4] = s[1];
  S_singular_cross[8] = s[2];

  /* '<S1>:1:33' */
  /* '<S1>:1:34' */
  i = 0;
  for (b_i = 0; b_i < 9; b_i++) {
    b_signal = 1.0 / S_singular_cross[b_i];
    f_0 = !((!rtIsInf(b_signal)) && (!rtIsNaN(b_signal)));
    if (f_0) {
      i++;
    }

    f[b_i] = f_0;
    S_singular_cross[b_i] = b_signal;
  }

  b_sizes = i;
  i = 0;
  for (b_i = 0; b_i < 9; b_i++) {
    if (f[b_i]) {
      b_data[i] = b_i + 1;
      i++;
    }
  }

  /* '<S1>:1:34' */
  for (b_i = 0; b_i < b_sizes; b_i++) {
    S_singular_cross[b_data[b_i] - 1] = 0.0;
  }

  if (S_singular_cross[8] > 2.0 * S_singular_cross[4]) {
    /* '<S1>:1:35' */
    /* '<S1>:1:36' */
    S_singular_cross[8] = 0.0;
  }

  /* '<S1>:1:39' */
  /* '<S1>:1:40' */
  ctrl_sixaxis2force_eml_xgesvd_j(A, b_U, s, b_V);
  memset(&S_ang[0], 0, 9U * sizeof(real_T));
  S_ang[0] = s[0];
  S_ang[4] = s[1];
  S_ang[8] = s[2];

  /* '<S1>:1:48' */
  /* '<S1>:1:49' */
  i = 0;
  for (b_i = 0; b_i < 9; b_i++) {
    b_signal = 1.0 / S_ang[b_i];
    f_0 = !((!rtIsInf(b_signal)) && (!rtIsNaN(b_signal)));
    if (f_0) {
      i++;
    }

    f[b_i] = f_0;
    S_ang[b_i] = b_signal;
  }

  b_sizes = i;
  i = 0;
  for (b_i = 0; b_i < 9; b_i++) {
    if (f[b_i]) {
      c_data[i] = b_i + 1;
      i++;
    }
  }

  /* '<S1>:1:49' */
  for (b_i = 0; b_i < b_sizes; b_i++) {
    S_ang[c_data[b_i] - 1] = 0.0;
  }

  if (S_ang[8] > 2.0 * S_ang[4]) {
    /* '<S1>:1:50' */
    /* '<S1>:1:51' */
    S_ang[8] = 0.0;
  }

  /* '<S1>:1:53' */
  for (b_i = 0; b_i < 12; b_i++) {
    for (b_sizes = 0; b_sizes < 3; b_sizes++) {
      b_V_0[b_i + 12 * b_sizes] = 0.0;
      b_V_0[b_i + 12 * b_sizes] += S_ang[3 * b_sizes] * b_V[b_i];
      b_V_0[b_i + 12 * b_sizes] += S_ang[3 * b_sizes + 1] * b_V[b_i + 12];
      b_V_0[b_i + 12 * b_sizes] += S_ang[3 * b_sizes + 2] * b_V[b_i + 24];
    }
  }

  for (b_i = 0; b_i < 12; b_i++) {
    for (b_sizes = 0; b_sizes < 3; b_sizes++) {
      b_V[b_i + 12 * b_sizes] = 0.0;
      b_V[b_i + 12 * b_sizes] += b_V_0[b_i] * b_U[b_sizes];
      b_V[b_i + 12 * b_sizes] += b_V_0[b_i + 12] * b_U[b_sizes + 3];
      b_V[b_i + 12 * b_sizes] += b_V_0[b_i + 24] * b_U[b_sizes + 6];
    }
  }

  for (b_i = 0; b_i < 12; b_i++) {
    T0[b_i] = b_V[b_i + 24] * ctrl_sixaxis2force_B.Product + (b_V[b_i + 12] *
      ctrl_sixaxis2force_B.Product2 + b_V[b_i] * ctrl_sixaxis2force_B.Product1);
  }

  /* '<S1>:1:54' */
  /*  for i=1:1:n_t */
  /*    if alpha1(i) > 180 */
  /*        alpha1(i) = alpha1(i) - 360; */
  /*    elseif alpha1(i) < -180 */
  /*        alpha1(i) = alpha1(i) + 360; */
  /*    else */
  /*        alpha1(i); */
  /*    end */
  /*  end */
  /* '<S1>:1:66' */
  for (b_i = 0; b_i < 6; b_i++) {
    for (b_sizes = 0; b_sizes < 3; b_sizes++) {
      T_surge_0[b_i + 6 * b_sizes] = 0.0;
      T_surge_0[b_i + 6 * b_sizes] += S_singular_cross[3 * b_sizes] * V[b_i];
      T_surge_0[b_i + 6 * b_sizes] += S_singular_cross[3 * b_sizes + 1] * V[b_i
        + 6];
      T_surge_0[b_i + 6 * b_sizes] += S_singular_cross[3 * b_sizes + 2] * V[b_i
        + 12];
    }
  }

  for (b_i = 0; b_i < 6; b_i++) {
    for (b_sizes = 0; b_sizes < 3; b_sizes++) {
      V[b_i + 6 * b_sizes] = 0.0;
      V[b_i + 6 * b_sizes] += T_surge_0[b_i] * U[b_sizes];
      V[b_i + 6 * b_sizes] += T_surge_0[b_i + 6] * U[b_sizes + 3];
      V[b_i + 6 * b_sizes] += T_surge_0[b_i + 12] * U[b_sizes + 6];
    }
  }

  for (b_i = 0; b_i < 6; b_i++) {
    ctrl_sixaxis2force_B.u_out[b_i] = 0.0;
    ctrl_sixaxis2force_B.u_out[b_i] += V[b_i] * ctrl_sixaxis2force_B.Product1;
    ctrl_sixaxis2force_B.u_out[b_i] += V[b_i + 6] *
      ctrl_sixaxis2force_B.Product2;
    ctrl_sixaxis2force_B.u_out[b_i] += V[b_i + 12] *
      ctrl_sixaxis2force_B.Product;
  }

  /* '<S1>:1:67' */
  ctrl_sixaxis2force_B.alpha_out[0] = rt_atan2d_snf(T0[1], T0[0]);
  ctrl_sixaxis2force_B.alpha_out[1] = rt_atan2d_snf(T0[3], T0[2]);
  ctrl_sixaxis2force_B.alpha_out[2] = rt_atan2d_snf(T0[5], T0[4]);
  ctrl_sixaxis2force_B.alpha_out[3] = rt_atan2d_snf(T0[7], T0[6]);
  ctrl_sixaxis2force_B.alpha_out[4] = rt_atan2d_snf(T0[9], T0[8]);
  ctrl_sixaxis2force_B.alpha_out[5] = rt_atan2d_snf(T0[11], T0[10]);
}

/* Model update function */
static void ctrl_sixaxis2force_update(void)
{
  /* Update for UnitDelay: '<S3>/Delay Input1' */
  ctrl_sixaxis2force_DW.DelayInput1_DSTATE = ctrl_sixaxis2force_B.ArrowUp;

  /* Update for UnitDelay: '<S4>/Delay Input1' */
  ctrl_sixaxis2force_DW.DelayInput1_DSTATE_l = ctrl_sixaxis2force_B.ArrowDown;

  /* Update for UnitDelay: '<S5>/Delay Input1' */
  ctrl_sixaxis2force_DW.DelayInput1_DSTATE_g = ctrl_sixaxis2force_B.Start;

  /* Update for Memory: '<S2>/Memory' */
  ctrl_sixaxis2force_DW.Memory_PreviousInput = ctrl_sixaxis2force_B.y;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ctrl_sixaxis2force_M->Timing.clockTick0)) {
    ++ctrl_sixaxis2force_M->Timing.clockTickH0;
  }

  ctrl_sixaxis2force_M->Timing.t[0] = ctrl_sixaxis2force_M->Timing.clockTick0 *
    ctrl_sixaxis2force_M->Timing.stepSize0 +
    ctrl_sixaxis2force_M->Timing.clockTickH0 *
    ctrl_sixaxis2force_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void ctrl_sixaxis2force_initialize(void)
{
  /* InitializeConditions for UnitDelay: '<S3>/Delay Input1' */
  ctrl_sixaxis2force_DW.DelayInput1_DSTATE =
    ctrl_sixaxis2force_P.DetectIncrease_vinit;

  /* InitializeConditions for UnitDelay: '<S4>/Delay Input1' */
  ctrl_sixaxis2force_DW.DelayInput1_DSTATE_l =
    ctrl_sixaxis2force_P.DetectIncrease1_vinit;

  /* InitializeConditions for UnitDelay: '<S5>/Delay Input1' */
  ctrl_sixaxis2force_DW.DelayInput1_DSTATE_g =
    ctrl_sixaxis2force_P.DetectIncrease2_vinit;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  ctrl_sixaxis2force_DW.Memory_PreviousInput = ctrl_sixaxis2force_P.Memory_X0;
}

/* Model terminate function */
static void ctrl_sixaxis2force_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  ctrl_sixaxis2force_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ctrl_sixaxis2force_update();
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
  ctrl_sixaxis2force_initialize();
}

void MdlTerminate(void)
{
  ctrl_sixaxis2force_terminate();
}

/* Registration function */
RT_MODEL_ctrl_sixaxis2force_T *ctrl_sixaxis2force(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ctrl_sixaxis2force_M, 0,
                sizeof(RT_MODEL_ctrl_sixaxis2force_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ctrl_sixaxis2force_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    ctrl_sixaxis2force_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ctrl_sixaxis2force_M->Timing.sampleTimes =
      (&ctrl_sixaxis2force_M->Timing.sampleTimesArray[0]);
    ctrl_sixaxis2force_M->Timing.offsetTimes =
      (&ctrl_sixaxis2force_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ctrl_sixaxis2force_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    ctrl_sixaxis2force_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(ctrl_sixaxis2force_M, &ctrl_sixaxis2force_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ctrl_sixaxis2force_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    ctrl_sixaxis2force_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ctrl_sixaxis2force_M, -1);
  ctrl_sixaxis2force_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ctrl_sixaxis2force_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ctrl_sixaxis2force_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(ctrl_sixaxis2force_M->rtwLogInfo, (NULL));
    rtliSetLogT(ctrl_sixaxis2force_M->rtwLogInfo, "tout");
    rtliSetLogX(ctrl_sixaxis2force_M->rtwLogInfo, "");
    rtliSetLogXFinal(ctrl_sixaxis2force_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(ctrl_sixaxis2force_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(ctrl_sixaxis2force_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(ctrl_sixaxis2force_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(ctrl_sixaxis2force_M->rtwLogInfo, 1);
    rtliSetLogY(ctrl_sixaxis2force_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ctrl_sixaxis2force_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(ctrl_sixaxis2force_M->rtwLogInfo, (NULL));
  }

  ctrl_sixaxis2force_M->solverInfoPtr = (&ctrl_sixaxis2force_M->solverInfo);
  ctrl_sixaxis2force_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ctrl_sixaxis2force_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ctrl_sixaxis2force_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ctrl_sixaxis2force_M->ModelData.blockIO = ((void *) &ctrl_sixaxis2force_B);
  (void) memset(((void *) &ctrl_sixaxis2force_B), 0,
                sizeof(B_ctrl_sixaxis2force_T));

  /* parameters */
  ctrl_sixaxis2force_M->ModelData.defaultParam = ((real_T *)
    &ctrl_sixaxis2force_P);

  /* states (dwork) */
  ctrl_sixaxis2force_M->ModelData.dwork = ((void *) &ctrl_sixaxis2force_DW);
  (void) memset((void *)&ctrl_sixaxis2force_DW, 0,
                sizeof(DW_ctrl_sixaxis2force_T));

  /* Initialize Sizes */
  ctrl_sixaxis2force_M->Sizes.numContStates = (0);/* Number of continuous states */
  ctrl_sixaxis2force_M->Sizes.numY = (0);/* Number of model outputs */
  ctrl_sixaxis2force_M->Sizes.numU = (0);/* Number of model inputs */
  ctrl_sixaxis2force_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ctrl_sixaxis2force_M->Sizes.numSampTimes = (1);/* Number of sample times */
  ctrl_sixaxis2force_M->Sizes.numBlocks = (47);/* Number of blocks */
  ctrl_sixaxis2force_M->Sizes.numBlockIO = (19);/* Number of block outputs */
  ctrl_sixaxis2force_M->Sizes.numBlockPrms = (180);/* Sum of parameter "widths" */
  return ctrl_sixaxis2force_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : ctrl_sixaxis2force
 * Model version : 1.30
 * VeriStand Model Framework version : 2015.0.1.0 (2015 f1)
 * Source generated on : Tue Apr 19 19:23:42 2016
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_ctrl_sixaxis2force
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
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
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
    return NIRT_SetValueByDataType(ptr,subindex,value,3,Complex);

   case 18:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 19:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 20:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr,subindex,value,0,Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern ctrl_sixaxis2force_rtModel *S;
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

  // ctrl_sixaxis2force/ArrowUp
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.ArrowUp, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/ArrowDown
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.ArrowDown, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/Start
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.Start, 0, data[index++], 0, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/L2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.L2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/PosYLeft
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.PosYLeft, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/PosXLeft
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.PosXLeft, 0, data[index++], 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/R2_continuous
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.R2_continuous, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/thr_angle_1
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.thr_angle_1, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/thr_angle_2
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.thr_angle_2, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/thr_angle_3
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.thr_angle_3, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/thr_angle_4
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.thr_angle_4, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/thr_angle_5
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.thr_angle_5, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/thr_angle_6
  if (TaskSampleHit[0]) {
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_B.thr_angle_6, 0, data[index++],
      0, 0);
  } else {
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 13;
}

int32_t NumOutputPorts(void)
{
  return 16;
}

double ni_extout[16];

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

  // ctrl_sixaxis2force/u_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.u_out, 0,
      18, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/u_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.u_out, 1,
      18, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/u_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.u_out, 2,
      18, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/u_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.u_out, 3,
      18, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/u_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.u_out, 4,
      18, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/u_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.u_out, 5,
      18, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/alpha_1: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.alpha_out,
      0, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/alpha_2: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.alpha_out,
      1, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/alpha_3: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.alpha_out,
      2, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/alpha_4: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.alpha_out,
      3, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/alpha_5: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.alpha_out,
      4, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/alpha_6: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.alpha_out,
      5, 18, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/N: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.Product,
      0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/u_limit: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.y, 0, 0,
      0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/X: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.Product1,
      0, 0, 0);
  } else {
    index += 1;
  }

  // ctrl_sixaxis2force/Y: Virtual Signal # 0
  if (TaskSampleHit[0]) {              // sample and hold
    ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.Product2,
      0, 0, 0);
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

  // ctrl_sixaxis2force/u_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.u_out, 0,
    18, 0);

  // ctrl_sixaxis2force/u_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.u_out, 1,
    18, 0);

  // ctrl_sixaxis2force/u_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.u_out, 2,
    18, 0);

  // ctrl_sixaxis2force/u_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.u_out, 3,
    18, 0);

  // ctrl_sixaxis2force/u_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.u_out, 4,
    18, 0);

  // ctrl_sixaxis2force/u_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.u_out, 5,
    18, 0);

  // ctrl_sixaxis2force/alpha_1: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.alpha_out,
    0, 18, 0);

  // ctrl_sixaxis2force/alpha_2: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.alpha_out,
    1, 18, 0);

  // ctrl_sixaxis2force/alpha_3: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.alpha_out,
    2, 18, 0);

  // ctrl_sixaxis2force/alpha_4: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.alpha_out,
    3, 18, 0);

  // ctrl_sixaxis2force/alpha_5: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.alpha_out,
    4, 18, 0);

  // ctrl_sixaxis2force/alpha_6: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.alpha_out,
    5, 18, 0);

  // ctrl_sixaxis2force/N: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.Product, 0,
    0, 0);

  // ctrl_sixaxis2force/u_limit: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.y, 0, 0, 0);

  // ctrl_sixaxis2force/X: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.Product1, 0,
    0, 0);

  // ctrl_sixaxis2force/Y: Virtual Signal # 0
  ni_extout[index++] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_B.Product2, 0,
    0, 0);
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
    "ctrl_sixaxis2force/u_limiter/Detect Increase/Delay Input1/InitialCondition",
    offsetof(P_ctrl_sixaxis2force_T, DetectIncrease_vinit), 29, 1, 2, 0, 0 },

  { 1,
    "ctrl_sixaxis2force/u_limiter/Detect Increase1/Delay Input1/InitialCondition",
    offsetof(P_ctrl_sixaxis2force_T, DetectIncrease1_vinit), 29, 1, 2, 2, 0 },

  { 2,
    "ctrl_sixaxis2force/u_limiter/Detect Increase2/Delay Input1/InitialCondition",
    offsetof(P_ctrl_sixaxis2force_T, DetectIncrease2_vinit), 29, 1, 2, 4, 0 },

  { 3, "ctrl_sixaxis2force/u_limiter/Memory/X0", offsetof(P_ctrl_sixaxis2force_T,
    Memory_X0), 29, 1, 2, 6, 0 },

  { 4, "ctrl_sixaxis2force/Gain1/Gain", offsetof(P_ctrl_sixaxis2force_T,
    Gain1_Gain), 29, 1, 2, 8, 0 },

  { 5, "ctrl_sixaxis2force/Gain/Gain", offsetof(P_ctrl_sixaxis2force_T,
    Gain_Gain), 29, 1, 2, 10, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 6;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "ctrl_sixaxis2force/ArrowUp", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    ArrowUp) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "ctrl_sixaxis2force/ArrowDown", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    ArrowDown) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "ctrl_sixaxis2force/Start", 0, "", offsetof(B_ctrl_sixaxis2force_T, Start)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "ctrl_sixaxis2force/L2_continuous", 0, "", offsetof
    (B_ctrl_sixaxis2force_T, L2_continuous) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 4, "ctrl_sixaxis2force/PosYLeft", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    PosYLeft) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "ctrl_sixaxis2force/Product1", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    Product1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "ctrl_sixaxis2force/PosXLeft", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    PosXLeft) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "ctrl_sixaxis2force/Product2", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    Product2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "ctrl_sixaxis2force/R2_continuous", 0, "", offsetof
    (B_ctrl_sixaxis2force_T, R2_continuous) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 9, "ctrl_sixaxis2force/Product", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    Product) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 10, "ctrl_sixaxis2force/thr_angle_1", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    thr_angle_1) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 11, "ctrl_sixaxis2force/thr_angle_2", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    thr_angle_2) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "ctrl_sixaxis2force/thr_angle_3", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    thr_angle_3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "ctrl_sixaxis2force/thr_angle_4", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    thr_angle_4) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 14, "ctrl_sixaxis2force/thr_angle_5", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    thr_angle_5) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15, "ctrl_sixaxis2force/thr_angle_6", 0, "", offsetof(B_ctrl_sixaxis2force_T,
    thr_angle_6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "ctrl_sixaxis2force/u_limiter/MATLAB Function", 0, "", offsetof
    (B_ctrl_sixaxis2force_T, y) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0
  },

  { 17, "ctrl_sixaxis2force/Thrust allocation", 0, "(1, 1)", offsetof
    (B_ctrl_sixaxis2force_T, u_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 18, "ctrl_sixaxis2force/Thrust allocation", 0, "(1, 2)", offsetof
    (B_ctrl_sixaxis2force_T, u_out) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 19, "ctrl_sixaxis2force/Thrust allocation", 0, "(1, 3)", offsetof
    (B_ctrl_sixaxis2force_T, u_out) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 20, "ctrl_sixaxis2force/Thrust allocation", 0, "(1, 4)", offsetof
    (B_ctrl_sixaxis2force_T, u_out) + (3*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 21, "ctrl_sixaxis2force/Thrust allocation", 0, "(1, 5)", offsetof
    (B_ctrl_sixaxis2force_T, u_out) + (4*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 22, "ctrl_sixaxis2force/Thrust allocation", 0, "(1, 6)", offsetof
    (B_ctrl_sixaxis2force_T, u_out) + (5*sizeof(real_T)), BLOCKIO_SIG, 18, 1, 2,
    0, 0 },

  { 23, "ctrl_sixaxis2force/Thrust allocation", 1, "(1, 1)", offsetof
    (B_ctrl_sixaxis2force_T, alpha_out) + (0*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 24, "ctrl_sixaxis2force/Thrust allocation", 1, "(1, 2)", offsetof
    (B_ctrl_sixaxis2force_T, alpha_out) + (1*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 25, "ctrl_sixaxis2force/Thrust allocation", 1, "(1, 3)", offsetof
    (B_ctrl_sixaxis2force_T, alpha_out) + (2*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 26, "ctrl_sixaxis2force/Thrust allocation", 1, "(1, 4)", offsetof
    (B_ctrl_sixaxis2force_T, alpha_out) + (3*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 27, "ctrl_sixaxis2force/Thrust allocation", 1, "(1, 5)", offsetof
    (B_ctrl_sixaxis2force_T, alpha_out) + (4*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { 28, "ctrl_sixaxis2force/Thrust allocation", 1, "(1, 6)", offsetof
    (B_ctrl_sixaxis2force_T, alpha_out) + (5*sizeof(real_T)), BLOCKIO_SIG, 18, 1,
    2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 29;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 29;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "ArrowUp", 0, EXT_IN, 1, 1, 1 },

  { 2, "ArrowDown", 0, EXT_IN, 1, 1, 1 },

  { 3, "Start", 0, EXT_IN, 1, 1, 1 },

  { 4, "L2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 5, "PosYLeft", 0, EXT_IN, 1, 1, 1 },

  { 6, "PosXLeft", 0, EXT_IN, 1, 1, 1 },

  { 7, "R2_continuous", 0, EXT_IN, 1, 1, 1 },

  { 8, "thr_angle_1", 0, EXT_IN, 1, 1, 1 },

  { 9, "thr_angle_2", 0, EXT_IN, 1, 1, 1 },

  { 10, "thr_angle_3", 0, EXT_IN, 1, 1, 1 },

  { 11, "thr_angle_4", 0, EXT_IN, 1, 1, 1 },

  { 12, "thr_angle_5", 0, EXT_IN, 1, 1, 1 },

  { 13, "thr_angle_6", 0, EXT_IN, 1, 1, 1 },

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

  { 12, "alpha_6", 0, EXT_OUT, 1, 1, 1 },

  { 13, "N", 0, EXT_OUT, 1, 1, 1 },

  { 14, "u_limit", 0, EXT_OUT, 1, 1, 1 },

  { 15, "X", 0, EXT_OUT, 1, 1, 1 },

  { 16, "Y", 0, EXT_OUT, 1, 1, 1 },

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
  "ctrl_sixaxis2force";
static const char* NI_CompiledModelVersion = "1.30";
static const char* NI_CompiledModelDateTime = "Tue Apr 19 19:23:42 2016";
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
  memcpy(&rtParameter[0], &ctrl_sixaxis2force_P, sizeof(P_ctrl_sixaxis2force_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka ctrl_sixaxis2force_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_ctrl_sixaxis2force_T));
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
             (P_ctrl_sixaxis2force_T));
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
               (P_ctrl_sixaxis2force_T));
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
             (P_ctrl_sixaxis2force_T));
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
           (P_ctrl_sixaxis2force_T));
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
           (P_ctrl_sixaxis2force_T));
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
      *numContStates = 0;
      *numDiscStates = 584;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.DelayInput1_DSTATE, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.DelayInput1_DSTATE");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.DelayInput1_DSTATE_l, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.DelayInput1_DSTATE_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.DelayInput1_DSTATE_g, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.DelayInput1_DSTATE_g");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.ArrowUp_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.ArrowUp_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.ArrowDown_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.ArrowDown_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.Start_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.Start_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.Memory_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.L2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.L2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.PosYLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.PosYLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.PosXLeft_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.PosXLeft_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.R2_continuous_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.R2_continuous_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.thr_angle_1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.thr_angle_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.thr_angle_2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.thr_angle_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.thr_angle_3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.thr_angle_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.thr_angle_4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.thr_angle_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.thr_angle_5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.thr_angle_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.thr_angle_6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.thr_angle_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_DW.u_1_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_sixaxis2force_DW.u_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_DW.u_2_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_sixaxis2force_DW.u_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_DW.u_3_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_sixaxis2force_DW.u_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_DW.u_4_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_sixaxis2force_DW.u_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_DW.u_5_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_sixaxis2force_DW.u_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_DW.u_6_DWORK1,
      0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_sixaxis2force_DW.u_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.alpha_1_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.alpha_1_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.alpha_2_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.alpha_2_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.alpha_3_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.alpha_3_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.alpha_4_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.alpha_4_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.alpha_5_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.alpha_5_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.alpha_6_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.alpha_6_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_DW.N_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_sixaxis2force_DW.N_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType
      (&ctrl_sixaxis2force_DW.u_limit_DWORK1, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&ctrl_sixaxis2force_DW.u_limit_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_DW.X_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_sixaxis2force_DW.X_DWORK1");
    discStates[idx] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_DW.Y_DWORK1, 0,
      0, 0);
    strcpy(discStatesNames + (idx++ * 100), "&ctrl_sixaxis2force_DW.Y_DWORK1");
    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.ArrowUp_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.ArrowUp_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.ArrowDown_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.ArrowDown_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.Start_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.Start_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.L2_continuous_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.L2_continuous_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.PosYLeft_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.PosYLeft_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.PosXLeft_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.PosXLeft_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.R2_continuous_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.R2_continuous_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.thr_angle_1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.thr_angle_1_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.thr_angle_2_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.thr_angle_2_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.thr_angle_3_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.thr_angle_3_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.thr_angle_4_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.thr_angle_4_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.thr_angle_5_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.thr_angle_5_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.thr_angle_6_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.thr_angle_6_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.u_1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.u_1_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.u_2_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.u_2_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.u_3_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.u_3_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.u_4_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.u_4_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.u_5_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.u_5_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.u_6_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.u_6_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.alpha_1_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.alpha_1_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.alpha_2_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.alpha_2_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.alpha_3_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.alpha_3_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.alpha_4_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.alpha_4_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.alpha_5_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.alpha_5_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.alpha_6_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.alpha_6_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_DW.N_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_sixaxis2force_DW.N_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&ctrl_sixaxis2force_DW.u_limit_DWORK2, count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&ctrl_sixaxis2force_DW.u_limit_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_DW.X_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_sixaxis2force_DW.X_DWORK2");
    }

    for (count = 0; count < 19; count++) {
      discStates[idx] = NIRT_GetValueByDataType(&ctrl_sixaxis2force_DW.Y_DWORK2,
        count, 17, 0);
      strcpy(discStatesNames + (idx++ * 100), "&ctrl_sixaxis2force_DW.Y_DWORK2");
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
  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.DelayInput1_DSTATE, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.DelayInput1_DSTATE_l, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.DelayInput1_DSTATE_g, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.ArrowUp_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.ArrowDown_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.Start_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.L2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.PosYLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.PosXLeft_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.R2_continuous_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.thr_angle_1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.thr_angle_2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.thr_angle_3_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.thr_angle_4_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.thr_angle_5_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.thr_angle_6_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_1_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_2_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_3_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_4_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_5_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_6_DWORK1, 0, discStates[idx
      ++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.alpha_1_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.alpha_2_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.alpha_3_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.alpha_4_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.alpha_5_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.alpha_6_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.N_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_limit_DWORK1, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.X_DWORK1, 0, discStates[idx++],
      0, 0);
    NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.Y_DWORK1, 0, discStates[idx++],
      0, 0);
    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.ArrowUp_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.ArrowDown_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.Start_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.L2_continuous_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.PosYLeft_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.PosXLeft_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.R2_continuous_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.thr_angle_1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.thr_angle_2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.thr_angle_3_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.thr_angle_4_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.thr_angle_5_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.thr_angle_6_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_3_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_4_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_5_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_6_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.alpha_1_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.alpha_2_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.alpha_3_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.alpha_4_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.alpha_5_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.alpha_6_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.N_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.u_limit_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.X_DWORK2, count,
        discStates[idx++], 17, 0);
    }

    for (count = 0; count < 19; count++) {
      NIRT_SetValueByDataType(&ctrl_sixaxis2force_DW.Y_DWORK2, count,
        discStates[idx++], 17, 0);
    }
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_ctrl_sixaxis2force
