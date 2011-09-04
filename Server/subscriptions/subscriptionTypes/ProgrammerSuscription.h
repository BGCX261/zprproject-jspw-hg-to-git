/*
 * ProgrammerSuscription.h
 *
 *  Created on: Nov 20, 2010
 *      Author: asia
 */

#ifndef PROGRAMMERSUSCRIPTION_H_
#define PROGRAMMERSUSCRIPTION_H_

#include "../Subscription.h"
#include "../../Observer.h"
#include <vector>

namespace server {

	class ProgrammerSuscription: public server::Subscription {
	public:
		ProgrammerSuscription();
		virtual ~ProgrammerSuscription() ;
	};

}

#endif /* PROGRAMMERSUSCRIPTION_H_ */
