mpcblas_initialize(CLIENT, "127.0.0.1", 7766, bitlen);\subfloat[Χρήση CBLAS] {
    \inputminted[fontsize=\scriptsize,frame=single]{cpp}{./01_body/code/cblas-differences-1.cpp}
}\qquad
\subfloat[Χρήση MPC-BLAS] {
    \inputminted[fontsize=\scriptsize,frame=single,highlightlines={1,5,6,8},highlightcolor=lightgray]{cpp}{./01_body/code/mpc-blas-differences-1.cpp}
}

auto y = mpcblas_saxpy(4,
                       mpcblas_sdot(4,
                                    MPCBLAS_IGNORE, 1,
                                    test_vector_2, 1),
                       MPCBLAS_IGNORE, 1,
                       test_vector_2, 1);
result_2 = mpcblas_snrm2(4, y, 1)
            ->get_value();

mpcblas_uninitialize();