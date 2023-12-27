#include <stdio.h>
#include <stdlib.h>

#include "utils/result_types.h"

Result_uint32_t f1(uint32_t i) {
    if (i == 0) return Result_uint32_t_Err("Error");
    return Result_uint32_t_Ok(i);
}

Result_uint32_t f2(uint32_t i, uint32_t i2) {
    Result_uint32_t result = f1(i);
    RESULT_M_TRY_DECL(uint32_t, val, result);

    return Result_uint32_t_Ok(val + i2);
}

int main() {
    Result_uint32_t res = f2(0, 1);
    Result_uint32_t res2 = f2(1, 1);

    printf("hi %d\n", Result_uint32_t_unwrap_or(&res, 0));
    printf("hi %d\n", Result_uint32_t_unwrap_or(&res2, 0));

    fflush(stdout);

    if(Result_uint32_t_is_err(&res)) {
        printf("hi %s\n", Result_uint32_t_unwrap_err(&res));
    }
}
