/* template main.h
 *
 * Copyright (C) 2006-2023 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */
#ifndef _MAIN_H_
#define _MAIN_H_

/* Espressif libraries */
#include "sdkconfig.h"
#include <nvs_flash.h>
#include <esp_log.h>

/* wolfSSL  */
#include <wolfssl/wolfcrypt/settings.h>
/* Reminder: settings.h includes wolfssl/user_settings.h */
#ifndef WOLFSSL_ESPIDF
    #error "Problem with wolfSSL user_settings."
    #error "Check components/wolfssl/include"
#endif
#include <wolfssl/version.h>

/* wolfSSH  */
#include <wolfssh/ssh.h>
#include <wolfssh/log.h>

/* Project settings */

/* See also user.settings.g, in particular DEFAULT_WINDOW_SZ
 * that can drammatically affect required memory. */
#define UART_RX_TASK_STACK_SIZE   ( 4 * 1024)
#define UART_TX_TASK_STACK_SIZE   ( 4 * 1024)

/* 20K is known to work for demo; 15K observed to fail with default settings */
#define SERVER_SESSION_STACK_SIZE (20 * 1024)

#endif /* _MAIN_H_ */
