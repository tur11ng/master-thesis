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


float  cblas_sdsdot(const CBLAS_INT N, const float alpha, const float *X,
                  const CBLAS_INT incX, const float *Y, const CBLAS_INT incY);
double cblas_dsdot(const CBLAS_INT N, const float *X, const CBLAS_INT incX, const float *Y,
                  const CBLAS_INT incY);
float  cblas_sdot(const CBLAS_INT N, const float  *X, const CBLAS_INT incX,
                  const float  *Y, const CBLAS_INT incY);
double cblas_ddot(const CBLAS_INT N, const double *X, const CBLAS_INT incX,
                  const double *Y, const CBLAS_INT incY);
void   cblas_cdotu_sub(const CBLAS_INT N, const void *X, const CBLAS_INT incX,
                     const void *Y, const CBLAS_INT incY, void *dotu);
void   cblas_cdotc_sub(const CBLAS_INT N, const void *X, const CBLAS_INT incX,
                     const void *Y, const CBLAS_INT incY, void *dotc);

void   cblas_zdotu_sub(const CBLAS_INT N, const void *X, const CBLAS_INT incX,
                     const void *Y, const CBLAS_INT incY, void *dotu);
void   cblas_zdotc_sub(const CBLAS_INT N, const void *X, const CBLAS_INT incX,
                     const void *Y, const CBLAS_INT incY, void *dotc);