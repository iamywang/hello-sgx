#include <cstdio>
#include <iostream>
#include "Enclave_u.h"
#include "sgx_urts.h"
#include "App.h"

sgx_enclave_id_t global_eid = 0;

void ocall_print(const char *str) {
    printf("%s\n", str);
}

int main() {
    initialize_enclave(&global_eid, "enclave.token", "enclave.signed.so");
    ecall_print(global_eid);
    printf("uRTS: Hello untrusted env!\n");
    return 0;
}
