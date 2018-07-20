/*
 * Copyright (C) 2018-2019 Tobias Brunner
 * Copyright (C) 2007 Martin Willi
 * HSR Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/**
 * @defgroup child_create child_create
 * @{ @ingroup tasks_v2
 */

#ifndef CHILD_CREATE_H_
#define CHILD_CREATE_H_

typedef struct child_create_t child_create_t;

#include <library.h>
#include <sa/ike_sa.h>
#include <sa/task.h>
#include <config/child_cfg.h>

/**
 * Task of type TASK_CHILD_CREATE, established a new CHILD_SA.
 *
 * This task may be included in the IKE_AUTH message or in a separate
 * CREATE_CHILD_SA exchange.
 */
struct child_create_t {

	/**
	 * Implements the task_t interface
	 */
	task_t task;

	/**
	 * Use a specific reqid for the CHILD_SA.
	 *
	 * When this task is used for rekeying, the same reqid is used
	 * for the new CHILD_SA.
	 *
	 * @param reqid		reqid to use
	 */
	void (*use_reqid) (child_create_t *this, uint32_t reqid);

	/**
	 * Use specific mark values to override configuration.
	 *
	 * @param in		inbound mark value
	 * @param out		outbound mark value
	 */
	void (*use_marks)(child_create_t *this, uint32_t in, uint32_t out);

	/**
	 * Use specific interface IDs, overriding configuration.
	 *
	 * @param in			inbound interface ID
	 * @param out			outbound interface ID
	 */
	void (*use_if_ids)(child_create_t *this, uint32_t in, uint32_t out);

	/**
	 * Set a proposal the initiator can use to e.g. determine what DH group
	 * to propose during a rekeying.
	 *
	 * @param proposal	previous proposal to use as blueprint (cloned)
	 */
	void (*use_proposal)(child_create_t *this, proposal_t *proposal);

	/**
	 * Get the lower of the two nonces, used for rekey collisions.
	 *
	 * @return			lower nonce
	 */
	chunk_t (*get_lower_nonce) (child_create_t *this);

	/**
	 * Get the CHILD_SA established/establishing by this task.
	 *
	 * @return			child_sa
	 */
	child_sa_t* (*get_child) (child_create_t *this);

	/**
	 * Enforce a specific CHILD_SA config as responder.
	 *
	 * @param cfg		configuration to enforce, reference gets owned
	 */
	void (*set_config)(child_create_t *this, child_cfg_t *cfg);
};

/**
 * Create a new child_create task.
 *
 * @param ike_sa		IKE_SA this task works for
 * @param config		child_cfg if task initiator, NULL if responder
 * @param rekey			whether we do a rekey or not
 * @param tsi			source of triggering packet, or NULL
 * @param tsr			destination of triggering packet, or NULL
 * @return				child_create task to handle by the task_manager
 */
child_create_t *child_create_create(ike_sa_t *ike_sa,
							child_cfg_t *config, bool rekey,
							traffic_selector_t *tsi, traffic_selector_t *tsr);

#endif /** CHILD_CREATE_H_ @}*/
