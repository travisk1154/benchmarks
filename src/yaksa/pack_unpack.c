#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#include "yaksa.h"

#define NUM_SIZES 27
#define CONTIG_TYPE YAKSA_TYPE__INT

double pack_unpack(int);

int main()
{
    const int buf_counts[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256,
                              512, 1024, 2048, 4096, 8192, 16384,
                              32768, 65536, 131072, 262144, 524288,
                              1048576, 2097152, 4194304, 8388608,
                              16777216, 33554432};
    double yaksa_times[NUM_SIZES];
    double memcpy_times[NUM_SIZES];

    double yaksa_avg;
    double memcpy_avg;

    yaksa_init(NULL);
    srand(time(NULL));

    for(int i = 0; i < NUM_SIZES; i++)
    {
        yaksa_times[i] = pack_unpack(buf_counts[i]);
    }

    for(int i = 0; i < NUM_SIZES; i++)
    {
        printf("%d,%.10f\n", buf_counts[i], yaksa_times[i]);
    }

    yaksa_finalize();

    return 0;
}

double pack_unpack(int buf_count)
{
    int rc;
    int runs;
    int buf_size = buf_count * sizeof(int);
    int *input = (int*)malloc(buf_size);
    int *pack_buf = (int*)malloc(buf_size);
    int *unpack_buf = (int*)malloc(buf_size);
    yaksa_info_t yaksa_info = NULL;
    yaksa_request_t request;
    yaksa_type_t contig = YAKSA_TYPE__INT;
    uintptr_t actual_pack_bytes;
    uintptr_t actual_unpack_bytes;
    double total_time = 0.0;

    /* Create random buffer */
    for(int i=0; i < buf_count; i++)
    {
        input[i] = rand();    
    }
    
    //Do 1000 runs for messages < 1MB and 100 for greater
    if(buf_count > 262144){
        runs = 100;
    }else{
        runs = 1000;
    }

    for(int i = 0; i < runs; i++)
    {
        clock_t begin = clock();

        /* start packing */
        rc = yaksa_ipack(input, buf_count, contig, 0,
                        pack_buf, buf_size, &actual_pack_bytes, yaksa_info,
                        YAKSA_OP__REPLACE, &request);
        assert(rc == YAKSA_SUCCESS);

        /* wait for packing to complete */
        rc = yaksa_request_wait(request);
        assert(rc == YAKSA_SUCCESS);

        /* start unpacking */
        rc = yaksa_iunpack(pack_buf, buf_size, unpack_buf, buf_count, contig, 0,
                           &actual_unpack_bytes, yaksa_info,
                           YAKSA_OP__REPLACE, &request);
        assert(rc == YAKSA_SUCCESS);

        /* wait for unpacking to complete */
        rc = yaksa_request_wait(request);
        assert(rc == YAKSA_SUCCESS);
        clock_t end = clock();
        total_time += (double)(end - begin) / CLOCKS_PER_SEC;
    }

    free(input);
    free(pack_buf);
    free(unpack_buf);

    return total_time / runs;
}
