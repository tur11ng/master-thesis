share *s_out;
s_out = mpcblas_get_circuit()->PutOUTGate(this->sharing, ALL);
mpcblas_get_party()->ExecCircuit();