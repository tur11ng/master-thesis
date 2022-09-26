mpcblas_initialize(SERVER, "127.0.0.1", 7766, bitlen);

result_1 = mpcblas_sdot(4,
                        test_vector_1, 1,
                        MPCBLAS_IGNORE, 1)
            ->get_value();

mpcblas_uninitialize();