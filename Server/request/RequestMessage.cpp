/*
 * RequestMessage.cpp
 *
 *  Created on: Jan 15, 2011
 *      Author: asia
 */

#include "RequestMessage.h"

RequestMessage::RequestMessage() : body_length_(0) {
}

RequestMessage::~RequestMessage() {
}

const char* RequestMessage::data() const
{
  return data_;
}

char* RequestMessage::data()
{
  return data_;
}

size_t RequestMessage::length() const
{
  return header_length + body_length_;
}

const char* RequestMessage::body() const
{
  return data_ + header_length;
}

char* RequestMessage::body()
{
  return data_ + header_length;
}

void RequestMessage::encode_header()
{
  using namespace std;
  char header[header_length + 1] = "";
  sprintf(header, "%4d", body_length_);
  memcpy(data_, header, header_length);
}


bool RequestMessage::decode_header()
{
  using namespace std; // For strncat and atoi.
  char header[header_length + 1] = "";
  strncat(header, data_, header_length);
  body_length_ = atoi(header);
  if (body_length_ > max_body_length)
  {
    body_length_ = 0;
    return false;
  }
  return true;
}


void RequestMessage::body_length(size_t length)
{
  body_length_ = length;
  if (body_length_ > max_body_length)
    body_length_ = max_body_length;
}

size_t RequestMessage::body_length() const
{
  return body_length_;
}

