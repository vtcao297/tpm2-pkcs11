/* SPDX-License-Identifier: BSD-2 */
/*
 * Copyright (c) 2018, Intel Corporation
 * All rights reserved.
 */
#ifndef SRC_TOKEN_H_
#define SRC_TOKEN_H_

#include "object.h"
#include "pkcs11.h"
#include "tpm.h"
#include "twist.h"
#include "utils.h"

typedef struct token token;
struct token {

    unsigned id;
    unsigned pid;
    unsigned char label[32];

    twist userpobjauthkeysalt;
    unsigned userpobjauthkeyiters;
    twist userpobjauth;

    twist sopobjauthkeysalt;
    unsigned sopobjauthkeyiters;
    twist sopobjauth;

    pobject pobject;

    sealobject sealobject;
    wrappingobject wrappingobject;

    sobject sobject;

    tobject *tobjects;

    struct {
        bool sym_support; /* use TPM for unwrapping if true else use software */
        bool is_initialized; /* token initialization state */
    } config;

};

void token_free(token *t);

void token_free_list(token *t, size_t len);

CK_RV token_get_info (CK_SLOT_ID slot_id, struct _CK_TOKEN_INFO *info);

#endif /* SRC_TOKEN_H_ */
