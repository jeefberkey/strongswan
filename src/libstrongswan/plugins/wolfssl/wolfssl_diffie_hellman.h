/*
 * Copyright (C) 2019 Sean Parkinson, wolfSSL Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**
 * @defgroup wolfssl_diffie_hellman wolfssl_diffie_hellman
 * @{ @ingroup wolfssl_p
 */

#ifndef WOLFSSL_DIFFIE_HELLMAN_H_
#define WOLFSSL_DIFFIE_HELLMAN_H_

typedef struct wolfssl_diffie_hellman_t wolfssl_diffie_hellman_t;

#include <library.h>

/**
 * Implementation of the Diffie-Hellman algorithm using wolfSSL.
 */
struct wolfssl_diffie_hellman_t {

	/**
	 * Implements diffie_hellman_t interface.
	 */
	diffie_hellman_t dh;
};

/**
 * Creates a new wolfssl_diffie_hellman_t object.
 *
 * @param group			Diffie Hellman group number to use
 * @param ...			expects generator and prime as chunk_t if MODP_CUSTOM
 * @return				wolfssl_diffie_hellman_t object, NULL if not supported
 */
wolfssl_diffie_hellman_t *wolfssl_diffie_hellman_create(
											diffie_hellman_group_t group, ...);

#endif /** WOLFSSL_DIFFIE_HELLMAN_H_ @}*/

