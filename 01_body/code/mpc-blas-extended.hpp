void mpcblas_initialize(e_role role,
                        const std::string &address,
                        int port,
                        int bitlen,
                        seclvl security_level = LT,
                        int n_threads = 2,
                        e_mt_gen_alg mg_algo = MT_OT,
                        int reserve_gates = 4000000,
                        const std::string &aby_circ_dir = "/home/imslab/ABY/bin/circ/.");
void mpcblas_uninitialize();
void mpcblas_reset();
void mpcblas_set_party(mpcblas_party_t *context);
mpcblas_party_t *mpcblas_get_party();
BooleanCircuit *mpcblas_get_circuit();

template<typename... T>
class types_list;
template<typename... T>
class mpcblas_values;
template<typename... value_types, typename... sharings_types>
class mpcblas_values<types_list<value_types...>, types_list<sharings_types...>> {
 public:
    mpcblas_values(sharings_types ...shares1);
    mpcblas_values(value_types... values);
    std::tuple<sharings_types...> get_sharings();
    std::tuple<value_types...> get_values();
};

template<typename T>
class mpcblas_value {
 public:
    mpcblas_value(share *sharing);

    mpcblas_value(share *sharing, int nvals);

    mpcblas_value(T value);

    share *get_sharing();

    static mpcblas_value<T> *from_input(std::optional<T> input);

    static mpcblas_value<T> *from_input_ptr(int N, std::optional<T> input, int inc);

    T get_value();
};
