

cblas_saxpy(4,
            cblas_sdot(4,
                       test_vector_1, 1,
                       test_vector_2, 1),
            test_vector_1, 1,
            test_vector_2, 1);



result = cblas_snrm2(4, test_vector_2, 1);