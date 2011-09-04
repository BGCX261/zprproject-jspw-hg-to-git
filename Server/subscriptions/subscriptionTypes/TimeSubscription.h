/*
 * TimeSubscription.h
 *
 *  Created on: Nov 20, 2010
 *      Author: asia
 */

#ifndef TIMESUBSCRIPTION_H_
#define TIMESUBSCRIPTION_H_

#include "../Subscription.h"
#include "../../Observer.h"
#include <vector>

namespace server {

	class TimeSubscription: public server::Subscription {
	public:
		TimeSubscription();
		virtual ~TimeSubscription();

	};

}

#endif /* TIMESUBSCRIPTION_H_ */
