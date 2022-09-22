#include "../utils.hpp"
#include <iostream>
#include <gtest/gtest.h>
#include "../../core/mpc-blas.hpp"
#include "unistd.h"

TEST(TESTIntegrations, TESTxNRM2xAXPYxDOT) {
    float test_vector_1[4] = {1.21, 5.33, 3.345, 4.213};
    float test_vector_2[4] = {0.01, 3.82, 1023.905, 92302.43};

    uint32_t bitlen = 32;

    int pipe_fds_1[2];
    int pipe_fds_2[2];
    pipe(pipe_fds_1);
    pipe(pipe_fds_2);

    float result, result_1, result_2;

    if (!fork()) {
        close(pipe_fds_1[0]);

        mpcblas_initialize(SERVER, "127.0.0.1", 7766, bitlen);
        auto y = mpcblas_saxpy(4,
                               mpcblas_sdot(4, test_vector_1, 1, MPCBLAS_IGNORE, 1),
                               test_vector_1, 1,
                               MPCBLAS_IGNORE, 1);
        result_1 = mpcblas_snrm2(4, y, 1)->get_value();
        mpcblas_uninitialize();

        write(pipe_fds_1[1], (void *)&result_1, sizeof(result_1));
        exit(1);
    }

    if (!fork()) {
        close(pipe_fds_2[0]);

        mpcblas_initialize(CLIENT, "127.0.0.1", 7766, bitlen);
        auto y = mpcblas_saxpy(4,
                               mpcblas_sdot(4, MPCBLAS_IGNORE, 1, test_vector_2, 1),
                               MPCBLAS_IGNORE, 1,
                               test_vector_2, 1);
        result_2 = mpcblas_snrm2(4, y, 1)->get_value();
        mpcblas_uninitialize();

        write(pipe_fds_2[1], (void *)&result_2, sizeof(result_2));
        exit(1);
    }

    cblas_saxpy(4,
                cblas_sdot(4, test_vector_1, 1, test_vector_2, 1),
                test_vector_1, 1,
                test_vector_2, 1);

    result = cblas_snrm2(4, test_vector_2, 1);

    int out_1 = read(pipe_fds_1[0], (void *)&result_1, sizeof(result_1));
    int out_2 = read(pipe_fds_2[0], (void *)&result_2, sizeof(result_2));

    if (out_1 == 0 || out_2 == 0) {
        std::cout << "EOF" << std::endl;
        EXIT_FAILURE;
    }

    if (out_1 == -1 || out_2 == -1) {
        std::cout << "ERROR" << std::endl;
        EXIT_FAILURE;
    }
    close(pipe_fds_1[0]);
    close(pipe_fds_2[0]);

    EXPECT_FLOAT_EQ(result_1, result_2);
    EXPECT_FLOAT_EQ(result, result_2);
    EXPECT_FLOAT_EQ(result, result_1);
}