/*
 * TextSubscription.h
 *
 *  Created on: Jan 2, 2011
 *      Author: asia
 */

#ifndef TEXTSUBSCRIPTION_H_
#define TEXTSUBSCRIPTION_H_

#include "../Subscription.h"
#include "../../Observer.h"

namespace server {

	class TextSubscription : public server::Subscription{
	public:
		TextSubscription();
		virtual ~TextSubscription();
	};

}

#endif /* TEXTSUBSCRIPTION_H_ */
