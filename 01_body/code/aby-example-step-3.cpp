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