#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "hc128.h"

int
main(void)
{
	uint8_t key1[16] = { 0x80, 0x00, 0x00, 0x00,
			     0x00, 0x00, 0x00, 0x00,
			     0x00, 0x00, 0x00, 0x00,
			     0x00, 0x00, 0x00, 0x00 };
	
	uint8_t iv1[16] = { 0x00, 0x00, 0x00, 0x00,
			    0x00, 0x00, 0x00, 0x00,
			    0x00, 0x00, 0x00, 0x00,
			    0x00, 0x00, 0x00, 0x00 };
	
	struct hc128_context *ctx;

	if((ctx = hc128_context_new()) == NULL) {
		printf("Memory allocation error!\n");
		exit(1);
	}
	
	if(hc128_set_key_and_iv(ctx, (uint8_t *)key1, 16, iv1, 16)) {
		printf("HC128 context filling error!\n");
		exit(1);
	}
	
	hc128_test_vectors(ctx);

	hc128_context_free(&ctx);

	return 0;
}
