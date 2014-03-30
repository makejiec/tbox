/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="ssl://www.gnu.org/licenses/"> ssl://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2015, ruki All rights reserved.
 *
 * @author		ruki
 * @file		ssl.h
 * @ingroup 	asio
 *
 */
#ifndef TB_ASIO_SSL_H
#define TB_ASIO_SSL_H

/* ///////////////////////////////////////////////////////////////////////
 * includes
 */
#include "aicp.h"
#include "../network/ssl.h"

/* ///////////////////////////////////////////////////////////////////////
 * types
 */

/*! the aicp ssl open func type
 *
 * @param ssl 		the ssl handle
 * @param state 	the state
 * @param priv 		the func private data
 *
 * @return 			tb_true: ok, tb_false: error, but not break aicp
 */
typedef tb_bool_t 	(*tb_aicp_ssl_open_func_t)(tb_handle_t ssl, tb_size_t state, tb_pointer_t priv);

/*! the aicp ssl read func type
 *
 * @param ssl 		the ssl handle
 * @param state 	the state
 * @param data 		the readed data
 * @param real 		the real size, maybe zero
 * @param size 		the need size
 * @param priv 		the func private data
 *
 * @return 			tb_true: ok and continue it if need, tb_false: break it, but not break aicp
 */
typedef tb_bool_t 	(*tb_aicp_ssl_read_func_t)(tb_handle_t ssl, tb_size_t state, tb_byte_t const* data, tb_size_t real, tb_size_t size, tb_pointer_t priv);

/*! the aicp ssl task func type
 *
 * @param ssl 		the ssl handle
 * @param state 	the state
 * @param priv 		the func private data
 *
 * @return 			tb_true: ok, tb_false: error, but not break aicp
 */
typedef tb_bool_t 	(*tb_aicp_ssl_task_func_t)(tb_handle_t ssl, tb_size_t state, tb_pointer_t priv);

/* ///////////////////////////////////////////////////////////////////////
 * interfaces
 */

/*! init the ssl 
 *
 * @param aicp 		the aicp
 *
 * @return 			the ssl handle
 */
tb_handle_t 		tb_aicp_ssl_init(tb_aicp_t* aicp);

/*! kill the ssl
 *
 * @param handle 	the ssl handle
 */
tb_void_t 			tb_aicp_ssl_kill(tb_handle_t handle);

/*! close the ssl
 *
 * @param handle 	the ssl handle
 * @param bcalling 	close it at the self callback?
 */
tb_void_t 			tb_aicp_ssl_clos(tb_handle_t handle, tb_bool_t bcalling);

/*! exit the ssl
 *
 * @param handle 	the ssl handle
 * @param bcalling 	exit it at the self callback?
 */
tb_void_t 			tb_aicp_ssl_exit(tb_handle_t handle, tb_bool_t bcalling);

/*! open the ssl 
 *
 * @param handle 	the ssl handle
 * @param func 		the func
 * @param priv 		the func data
 *
 * @return 			tb_true or tb_false
 */
tb_bool_t 			tb_aicp_ssl_open(tb_handle_t handle, tb_aicp_ssl_open_func_t func, tb_pointer_t priv);

/*! read the ssl after the delay time
 *
 * @param handle 	the ssl handle
 * @param delay 	the delay time, ms
 * @param maxn 		the read maxn, using the default maxn if be zero
 * @param func 		the func
 * @param priv 		the func data
 *
 * @return 			tb_true or tb_false
 */
tb_bool_t 			tb_aicp_ssl_read(tb_handle_t handle, tb_size_t delay, tb_size_t maxn, tb_aicp_ssl_read_func_t func, tb_pointer_t priv);

/*! task the ssl
 *
 * @param handle 	the ssl handle
 * @param delay 	the delay time, ms
 * @param func 		the func
 * @param priv 		the func data
 *
 * @return 			tb_true or tb_false
 */
tb_bool_t 			tb_aicp_ssl_task(tb_handle_t handle, tb_size_t delay, tb_aicp_ssl_task_func_t func, tb_pointer_t priv);

/*! open and read the ssl, open it first if not opened 
 *
 * @param handle 	the ssl handle
 * @param maxn 		the read maxn, using the default maxn if be zero
 * @param func 		the func
 * @param priv 		the func data
 *
 * @return 			tb_true or tb_false
 */
tb_bool_t 			tb_aicp_ssl_oread(tb_handle_t handle, tb_size_t maxn, tb_aicp_ssl_read_func_t func, tb_pointer_t priv);

/*! the ssl aicp
 *
 * @param handle 	the ssl handle
 *
 * @return 			the aicp
 */
tb_aicp_t* 			tb_aicp_ssl_aicp(tb_handle_t handle);


#endif

