#ifndef CBLAS_H
#define CBLAS_H
#include <stddef.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++ */
#endif /* __cplusplus */

/*
* Enumerated and derived types
*/
#define CBLAS_INDEX size_t /* this may vary between platforms */

/*
* Integer type
*/
#ifndef CBLAS_INT
#ifdef WeirdNEC
   #define CBLAS_INT int64_t
#else
   #define CBLAS_INT int32_t
#endif
#endif

typedef enum CBLAS_LAYOUT {CblasRowMajor=101, CblasColMajor=102} CBLAS_LAYOUT;
typedef enum CBLAS_TRANSPOSE {CblasNoTrans=111, CblasTrans=112, CblasConjTrans=113} CBLAS_TRANSPOSE;
typedef enum CBLAS_UPLO {CblasUpper=121, CblasLower=122} CBLAS_UPLO;
typedef enum CBLAS_DIAG {CblasNonUnit=131, CblasUnit=132} CBLAS_DIAG;
typedef enum CBLAS_SIDE {CblasLeft=141, CblasRight=142} CBLAS_SIDE;

#define CBLAS_ORDER CBLAS_LAYOUT /* this for backward compatibility with CBLAS_ORDER */

#include "cblas_mangling.h"

/*
* ===========================================================================
* Prototypes for level 1 BLAS functions (complex are recast as routines)
* ===========================================================================
*/

double cblas_dcabs1(const void  *z);
float  cblas_scabs1(const void  *c);

float  cblas_sdsdot(const CBLAS_INT N, const float alpha, const float *X,
                  const CBLAS_INT incX, const float *Y, const CBLAS_INT incY);
double cblas_dsdot(const CBLAS_INT N, const float *X, const CBLAS_INT incX, const float *Y,
                  const CBLAS_INT incY);
float  cblas_sdot(const CBLAS_INT N, const float  *X, const CBLAS_INT incX,
                  const float  *Y, const CBLAS_INT incY);
double cblas_ddot(const CBLAS_INT N, const double *X, const CBLAS_INT incX,
                  const double *Y, const CBLAS_INT incY);

/*
* Functions having prefixes Z and C only
*/
void   cblas_cdotu_sub(const CBLAS_INT N, const void *X, const CBLAS_INT incX,
                     const void *Y, const CBLAS_INT incY, void *dotu);
void   cblas_cdotc_sub(const CBLAS_INT N, const void *X, const CBLAS_INT incX,
                     const void *Y, const CBLAS_INT incY, void *dotc);

void   cblas_zdotu_sub(const CBLAS_INT N, const void *X, const CBLAS_INT incX,
                     const void *Y, const CBLAS_INT incY, void *dotu);
void   cblas_zdotc_sub(const CBLAS_INT N, const void *X, const CBLAS_INT incX,
                     const void *Y, const CBLAS_INT incY, void *dotc);


/*
* Functions having prefixes S D SC DZ
*/
float  cblas_snrm2(const CBLAS_INT N, const float *X, const CBLAS_INT incX);
float  cblas_sasum(const CBLAS_INT N, const float *X, const CBLAS_INT incX);

double cblas_dnrm2(const CBLAS_INT N, const double *X, const CBLAS_INT incX);
double cblas_dasum(const CBLAS_INT N, const double *X, const CBLAS_INT incX);

float  cblas_scnrm2(const CBLAS_INT N, const void *X, const CBLAS_INT incX);
float  cblas_scasum(const CBLAS_INT N, const void *X, const CBLAS_INT incX);

double cblas_dznrm2(const CBLAS_INT N, const void *X, const CBLAS_INT incX);
double cblas_dzasum(const CBLAS_INT N, const void *X, const CBLAS_INT incX);


/*
* Functions having standard 4 prefixes (S D C Z)
*/
CBLAS_INDEX cblas_isamax(const CBLAS_INT N, const float  *X, const CBLAS_INT incX);
CBLAS_INDEX cblas_idamax(const CBLAS_INT N, const double *X, const CBLAS_INT incX);
CBLAS_INDEX cblas_icamax(const CBLAS_INT N, const void   *X, const CBLAS_INT incX);
CBLAS_INDEX cblas_izamax(const CBLAS_INT N, const void   *X, const CBLAS_INT incX);

/*
* ===========================================================================
* Prototypes for level 1 BLAS routines
* ===========================================================================
*/

/*
* Routines with standard 4 prefixes (s, d, c, z)
*/
void cblas_sswap(const CBLAS_INT N, float *X, const CBLAS_INT incX,
               float *Y, const CBLAS_INT incY);
void cblas_scopy(const CBLAS_INT N, const float *X, const CBLAS_INT incX,
               float *Y, const CBLAS_INT incY);
void cblas_saxpy(const CBLAS_INT N, const float alpha, const float *X,
               const CBLAS_INT incX, float *Y, const CBLAS_INT incY);

void cblas_dswap(const CBLAS_INT N, double *X, const CBLAS_INT incX,
               double *Y, const CBLAS_INT incY);
void cblas_dcopy(const CBLAS_INT N, const double *X, const CBLAS_INT incX,
               double *Y, const CBLAS_INT incY);
void cblas_daxpy(const CBLAS_INT N, const double alpha, const double *X,
               const CBLAS_INT incX, double *Y, const CBLAS_INT incY);

void cblas_cswap(const CBLAS_INT N, void *X, const CBLAS_INT incX,
               void *Y, const CBLAS_INT incY);
void cblas_ccopy(const CBLAS_INT N, const void *X, const CBLAS_INT incX,
               void *Y, const CBLAS_INT incY);
void cblas_caxpy(const CBLAS_INT N, const void *alpha, const void *X,
               const CBLAS_INT incX, void *Y, const CBLAS_INT incY);

void cblas_zswap(const CBLAS_INT N, void *X, const CBLAS_INT incX,
               void *Y, const CBLAS_INT incY);
void cblas_zcopy(const CBLAS_INT N, const void *X, const CBLAS_INT incX,
               void *Y, const CBLAS_INT incY);
void cblas_zaxpy(const CBLAS_INT N, const void *alpha, const void *X,
               const CBLAS_INT incX, void *Y, const CBLAS_INT incY);


/*
* Routines with S and D prefix only
*/
void cblas_srotg(float *a, float *b, float *c, float *s);
void cblas_srotmg(float *d1, float *d2, float *b1, const float b2, float *P);
void cblas_srot(const CBLAS_INT N, float *X, const CBLAS_INT incX,
               float *Y, const CBLAS_INT incY, const float c, const float s);
void cblas_srotm(const CBLAS_INT N, float *X, const CBLAS_INT incX,
               float *Y, const CBLAS_INT incY, const float *P);

void cblas_drotg(double *a, double *b, double *c, double *s);
void cblas_drotmg(double *d1, double *d2, double *b1, const double b2, double *P);
void cblas_drot(const CBLAS_INT N, double *X, const CBLAS_INT incX,
               double *Y, const CBLAS_INT incY, const double c, const double  s);
void cblas_drotm(const CBLAS_INT N, double *X, const CBLAS_INT incX,
               double *Y, const CBLAS_INT incY, const double *P);


/*
* Routines with S D C Z CS and ZD prefixes
*/
void cblas_sscal(const CBLAS_INT N, const float alpha, float *X, const CBLAS_INT incX);
void cblas_dscal(const CBLAS_INT N, const double alpha, double *X, const CBLAS_INT incX);
void cblas_cscal(const CBLAS_INT N, const void *alpha, void *X, const CBLAS_INT incX);
void cblas_zscal(const CBLAS_INT N, const void *alpha, void *X, const CBLAS_INT incX);
void cblas_csscal(const CBLAS_INT N, const float alpha, void *X, const CBLAS_INT incX);
void cblas_zdscal(const CBLAS_INT N, const double alpha, void *X, const CBLAS_INT incX);

}
#endif