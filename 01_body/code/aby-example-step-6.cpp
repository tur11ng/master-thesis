uint32_t out_bitlen, out_nvals;
uint32_t *out_values;
s_out->get_clear_value_vec(&out_values, &out_bitlen, &out_nvals);

return *((float *)(&out_values[0]));