share *s_multiply, *s_add;

s_multiply = boolean_circuit->PutFPGate(s_X-, s_Y, MUL, BITLEN, N);

uint32_t pos[1] = {0};
s_add = boolean_circuit->PutSubsetGate(s_multiply, pos, 1);

for (uint32_t i = 1; i < N; i++) {
    pos[0] = i;
    s_add = boolean_circuit->PutFPGate(s_add,
                                       boolean_circuit->PutSubsetGate(s_multiply, pos, 1),
                                       ADD, BITLEN, 1);
}