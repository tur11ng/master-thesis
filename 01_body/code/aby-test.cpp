#include <iostream>

#include "abycore/sharing/sharing.h"
#include "abycore/circuit/booleancircuits.h"
#include "abycore/aby/abyparty.h"
#include "../extern/ENCRYPTO_utils/src/ENCRYPTO_utils/typedefs.h"
#include "../extern/ENCRYPTO_utils/src/ENCRYPTO_utils/constants.h"

#define CBLAS_INT int32_t

float  cblas_sdsdot(const CBLAS_INT N, const float alpha, const float *X,
                  const CBLAS_INT incX, const float *Y, const CBLAS_INT incY) {
ABYParty *party = new ABYParty(SERVER, addr="127.0.0.1", port=7766, seclvl=LT,
                                           bitlen=32, n_threads=2, mg_algo=MT_OT, reserve_gates=4000000, "OUR_ABY_CIRCUIT_PATH_HERE");
        BooleanCircuit *boolean_circuit = (BooleanCircuit *) party->GetSharings()[S_BOOL]->GetCircuitBuildRoutine();
        share *s_X, *s_Y

        if (s_X != nullptr) {
            float input_vector[N];
            convert_cblas_format_to_array<float>(N, s_X, inc, input_vector);
            s_X = boolean_circuit->PutSIMDINGate(N,
                                            (uint32_t *)s_X,
                                            BITLEN,
                                            boolean_circuit->GetRole()));
        } else {
            s_X = boolean_circuit->PutDummySIMDINGate(N, BITLEN);
        }

        if (s_X != nullptr) {
            float input_vector[N];
            convert_cblas_format_to_array<float>(N, s_Y, inc, input_vector);
            s_Y = boolean_circuit->PutSIMDINGate(N,
                                            (uint32_t *)s_Y,
                                            BITLEN,
                                            boolean_circuit->GetRole()));
        } else {
            s_Y = boolean_circuit->PutDummySIMDINGate(N, BITLEN);
        }

        share *s_multiply, *s_add;

        s_multiply = boolean_circuit->PutFPGate(s_X->get_sharing(), s_Y->get_sharing(), MUL, BITLEN, N);

        uint32_t pos[1] = {0};
        s_add = boolean_circuit->PutSubsetGate(s_multiply, pos, 1);

        for (uint32_t i = 1; i < N; i++) {
            pos[0] = i;
            s_add = boolean_circuit->PutFPGate(s_add,
                                               boolean_circuit->PutSubsetGate(s_multiply, pos, 1),
                                               ADD, BITLEN, 1);
        }

        share *s_out;
        s_out = mpcblas_get_circuit()->PutOUTGate(this->sharing, ALL);
        mpcblas_get_party()->ExecCircuit();

        uint32_t out_bitlen, out_nvals;
        uint32_t *out_values;
        s_out->get_clear_value_vec(&out_values, &out_bitlen, &out_nvals);

        std::cout << *((float *)(&out_values[0])) << std::endl;
}

int main() {
    const N, incX, incY;
    float *X = nullptr, *Y = nullptr;

    if(fork() != -1) {
        float test_vector_1[4] = {1.21, 5.33, 3.345, 4.213};
        std::cout << sdot(4, test_vector_1, 1, nullptr, 1) << std::endl;
    }

    if (fork() != -1) {
        float test_vector_2[4] = {0.01, 3.82, 1023.905, 92302.43};
        std::cout << sdot(4, nullptr, 1, test_vector_2, 1) << std::endl;
    }
}