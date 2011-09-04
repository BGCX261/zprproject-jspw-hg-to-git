/*
 * RequestMessage.h
 *
 *  Created on: Jan 15, 2011
 *      Author: asia
 */

#ifndef REQUESTMESSAGE_H_
#define REQUESTMESSAGE_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>

class RequestMessage {
	public:
	    enum { header_length = 8 };
	    enum { max_body_length = 512 };

		void encode_header();
		bool decode_header();
		const char* data() const;
		char* data();
		const char* body() const;
		char* body();
		size_t length() const;
		void body_length(size_t length);
		size_t body_length() const;
		RequestMessage();
		~RequestMessage();
		char data_[header_length + max_body_length];
		int body_length_;
	private:
//	  char data_[header_length + max_body_length];


};

#endif /* REQUESTMESSAGE_H_ */
