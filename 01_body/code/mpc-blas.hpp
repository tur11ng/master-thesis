#define MPCBLAS_INDEX uint32_t

/*
 * ==========================================================
 * Prototypes for level 1 single precision MPC-BLAS functions
 * ==========================================================
 */

mpcblas_value<float> *mpcblas_sdot(int N, std::optional<float *> X, int incX,
                                   std::optional<float *> Y, int incY);
mpcblas_value<float> *mpcblas_sdot(int N, mpcblas_value<float *> *s_X, int incX,
                                   std::optional<float *> Y, int incY);
mpcblas_value<float> *mpcblas_sdot(int N, std::optional<float *> X, int incX,
                                   mpcblas_value<float *> *s_Y, int incY);
mpcblas_value<float> *mpcblas_sdot(int N, mpcblas_value<float *> *X, int incX,
                                   mpcblas_value<float *> *Y, int incY);

mpcblas_value<float> *mpcblas_snrm2(int N, std::optional<float *> X, int incX);
mpcblas_value<float> *mpcblas_snrm2(int N, mpcblas_value<float *> *s_X, int incX);

mpcblas_value<float> *mpcblas_sasum(int N, std::optional<float *> X, int incX);
mpcblas_value<float> *mpcblas_sasum(int N, mpcblas_value<float *> *s_X, int incX);

mpcblas_value<MPCBLAS_INDEX> *mpcblas_isamax(int N, std::optional<float *> X, int incX);
mpcblas_value<MPCBLAS_INDEX> *mpcblas_isamax(int N, mpcblas_value<float *> *s_X, int incX);

/*
 * =========================================================
 * Prototypes for level 1 single precision MPC-BLAS routines
 * =========================================================
 */

mpcblas_values<types_list<share *, share *>, types_list<float *, float *>> *
mpcblas_sswap(int N, std::optional<float *> X, int incX,
              std::optional<float *> Y, int incY);
mpcblas_values<types_list<share *, share *>, types_list<float *, float *>> *
mpcblas_sswap(int N, mpcblas_value<float *> *s_X, int incX,
              std::optional<float *> Y, int incY);
mpcblas_values<types_list<share *, share *>, types_list<float *, float *>> *
mpcblas_sswap(int N, std::optional<float *> *X, int incX,
              mpcblas_value<float *> *&s_Y, int incY);
void mpcblas_sswap(int N, mpcblas_value<float *> *&s_X, int incX, mpcblas_value<float *> *&s_Y, int incY);

mpcblas_value<float *> *mpcblas_scopy(int N, std::optional<float *> X, int incX,
                                      std::optional<float *> Y, int incY);
mpcblas_value<float *> *mpcblas_scopy(int N, mpcblas_value<float *> *s_X, int incX,
                                      std::optional<float *> Y, int incY);
void mpcblas_sscopy(int N, std::optional<float *> X, int incX,
                    mpcblas_value<float *> *&s_Y, int incY);
void mpcblas_sscopy(int N, mpcblas_value<float *> *s_X, int incX,
                    mpcblas_value<float *> *&s_Y, int incY);

mpcblas_value<float *> *mpcblas_saxpy(int N, std::optional<float> alpha, std::optional<float *> X,
                                      int incX, std::optional<float *> Y, int incY);
mpcblas_value<float *> *mpcblas_saxpy(int N,
                                      mpcblas_value<float> *s_alpha,
                                      std::optional<float *> X,
                                      int incX,
                                      std::optional<float *> Y,
                                      int incY);
mpcblas_value<float *> *mpcblas_saxpy(int N,
                                      std::optional<float *> s_alpha,
                                      mpcblas_value<float *> *s_X,
                                      int incX,
                                      std::optional<float *> Y,
                                      int incY);
mpcblas_value<float *> *mpcblas_saxpy(int N,
                                      mpcblas_value<float> *s_alpha,
                                      mpcblas_value<float *> *s_X,
                                      int incX,
                                      std::optional<float *> Y,
                                      int incY);
void mpcblas_saxpy(int N,
                   std::optional<float> alpha,
                   std::optional<float *> X,
                   int incX,
                   mpcblas_value<float *> *&s_Y,
                   int incY);
void mpcblas_saxpy(int N,
                   mpcblas_value<float> s_alpha,
                   std::optional<float *> X,
                   int incX,
                   mpcblas_value<float *> *&s_Y,
                   int incY);
void mpcblas_saxpy(int N,
                   mpcblas_value<float> *alpha,
                   mpcblas_value<float *> *s_X,
                   int incX,
                   mpcblas_value<float *> *&s_Y,
                   int incY);

mpcblas_value<float *> *mpcblas_sscal(int N, std::optional<float> alpha, std::optional<float *> X, int incX);
void mpcblas_sscal(int N, mpcblas_value<float> *s_alpha, mpcblas_value<float *> *&s_X, int incX);
void mpcblas_sscal(int N, std::optional<float> alpha, mpcblas_value<float *> *&s_X, int incX);
mpcblas_value<float *> *mpcblas_sscal(int N, mpcblas_value<float> *s_alpha, std::optional<float *> X, int incX);