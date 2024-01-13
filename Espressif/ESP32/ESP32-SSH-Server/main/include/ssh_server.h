/* ssh_server.h
 *
 * Copyright (C) 2014-2022 wolfSSL Inc.
 *
 * This file is part of wolfSSH.
 *
 * wolfSSH is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * wolfSSH is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with wolfSSH.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _SSH_SERVER_H_
#define _SSH_SERVER_H_

#include <freertos/FreeRTOS.h>

#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

/* make sure this appears before any other wolfSSL headers */
#ifdef WOLFSSL_USER_SETTINGS
    #include <wolfssl/wolfcrypt/settings.h>
#else
    #include <wolfssl/options.h>
#endif

/* wolfSSL */
#include <wolfssl/ssl.h>
#include <wolfssl/wolfcrypt/logging.h>
#include <wolfssl/wolfcrypt/sha256.h>
#include <wolfssl/wolfcrypt/coding.h>

/* wolfSSH */
#include <wolfssh/ssh.h>
#include <wolfssl/wolfcrypt/ecc.h>


#include <pthread.h>
#ifdef SINGLE_THREADED
    typedef void* THREAD_RETURN;
    typedef void* THREAD_TYPE;
    #define WOLFSSH_THREAD
#else
    #if defined(_POSIX_THREADS) && !defined(__MINGW32__)
        typedef void* THREAD_RETURN;
        typedef pthread_t     THREAD_TYPE;
        #define WOLFSSH_THREAD
        #define INFINITE -1
        #define WAIT_OBJECT_0 0L
    #elif defined(WOLFSSL_NUCLEUS) || defined(FREESCALE_MQX)
        typedef unsigned int  THREAD_RETURN;
        typedef intptr_t      THREAD_TYPE;
        #define WOLFSSH_THREAD
    #else
        typedef unsigned int  THREAD_RETURN;
        typedef intptr_t      THREAD_TYPE;
        #define WOLFSSH_THREAD __stdcall
    #endif
#endif

/* socket includes */
#include "lwip/netdb.h"
#include "lwip/sockets.h"



#ifdef NO_FILESYSTEM
    #include <wolfssh/certs_test.h>
    #ifdef WOLFSSH_SCP
        #include <wolfssh/wolfscp.h>
    #endif
#endif


/* the main SSH Server demo*/
void server_test(void *arg);

/* External buffer functions used between RTOS tasks. (typically the UART)
 * TODO: Implement interrupts rather than polling */
volatile char* __attribute__((optimize("O0"))) ExternalTransmitBuffer(void);
volatile char* __attribute__((optimize("O0"))) ExternalReceiveBuffer(void);

int ExternalTransmitBufferSz(void);
int ExternalReceiveBufferSz(void);

int Set_ExternalTransmitBufferSz(int n);
int Set_ExternalReceiveBufferSz(int n);

#endif /* _SSH_SERVER_H_ */
