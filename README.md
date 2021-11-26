# Hello-SGX

This is a simple program running on Linux based on sample codes
from [Intel(R) SGX SDK](https://github.com/intel/linux-sgx).

## How to run

Following these commands:

```shell
$ git clone https://github.com/iamywang/hello-sgx.git
$ make
$ ./app
```

Tested environment:

|Platform|Version|
|:----:|:----:|
|CPU|Intel i5-9400|
|OS|Manjaro Linux|
|Kernel|Linux 5.15.2-2-MANJARO|
|SGX Driver|2.14|
|SGX SDK|2.15.101.1|
|SGX PSW|2.15.101.1|

## Description

Define trusted functions and untrusted functions in Enclave.edl:

```c++
enclave {
    trusted {
        /* define ECALLs here. */
        public void ecall_print(void);
    };
    untrusted {
        /* define OCALLs here. */
        void ocall_print([in, string]const char* str);
    };
};
```

When executing this program, first `initialize_enclave()`, and then execute `ECALLs` to switch to enclave mode:
```c++
int main() {
    initialize_enclave(&global_eid, "enclave.token", "enclave.signed.so");
    ecall_print(global_eid);
    printf("uRTS: Hello untrusted env!\n");
    return 0;
}
```

Expected output of this program:

```shell
$ ./app
tRTS: Hello trusted env!
uRTS: Hello untrusted env!
```
