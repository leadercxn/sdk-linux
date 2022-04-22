//  aes_crypt.h
//  WeChat Embedded
//
//  Created by harlliu on 14-02-26.
//  Copyright 2014 Tencent. All rights reserved.
//

#ifndef __AES_CRYPT_H__
#define __AES_CRYPT_H__

#include <stdint.h>
#include "aes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	AES_KEY key;
	uint8_t iv[16];
} AES_CTX;

int aes_cbc_encrypt_init(AES_CTX *c, const uint8_t key[16]);
int aes_cbc_encrypt_update(AES_CTX *c, const uint8_t in[16], uint8_t out[16]);
int aes_cbc_encrypt_final(AES_CTX *c, const uint8_t *in, int in_len, uint8_t out[32], int *out_len);

int aes_cbc_decrypt_init(AES_CTX *c, const uint8_t key[16]);
int aes_cbc_decrypt_update(AES_CTX *c, const uint8_t in[16], uint8_t out[16]);
int aes_cbc_decrypt_final(AES_CTX *c, const uint8_t in[16], uint8_t out[16], int *out_len);

void decrypt_data(uint8_t *data,int in_length,uint8_t* key,uint8_t *decrypt_buf, int *decrypt_len);
void encrypt_data(uint8_t *data,int in_length,uint8_t *key,uint8_t *encrypt_buf, int *encrypt_len);
#ifdef __cplusplus
}
#endif

#endif
