/*
 * Observer.h
 *
 *  Created on: Nov 20, 2010
 *      Author: asia
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

namespace server {

	class Observer {
	public:
		Observer();
		~Observer();
		virtual void update() = 0;
	};

}

#endif /* OBSERVER_H_ */
