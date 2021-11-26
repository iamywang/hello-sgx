#include "Enclave_t.h"

void ecall_print() {
    ocall_print("tRTS: Hello trusted env!");
}
