mpcblas_initialize(CLIENT, "127.0.0.1",
                   7766, bitlen);

float result = mpcblas_saxpy(4,
                   mpcblas_sdot(4,
                       MPCBLAS_IGNORE, 1,
                           test_vector_2, 1),
                   MPCBLAS_IGNORE, 1,
                   test_vector_2, 1);
              ->get_value();

mpcblas_uninitialize();