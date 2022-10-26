mpcblas_initialize(CLIENT, "127.0.0.1",
                   7766, bitlen);

auto y = mpcblas_saxpy(4,
            mpcblas_sdot(4,
                MPCBLAS_IGNORE, 1,
                test_vector_2, 1),
            MPCBLAS_IGNORE, 1,
            test_vector_2, 1);
float result_2 = mpcblas_snrm2(4, y, 1)
            ->get_value();

mpcblas_uninitialize();