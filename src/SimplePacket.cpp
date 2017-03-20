/*
   Copyright (c) 2017 Boot&Work Corp., S.L. All rights reserved

   This library is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "SimplePacket.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
SimplePacket::SimplePacket() {
	_data = NULL;
	clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
SimplePacket::~SimplePacket() {
	clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::init(uint8_t len) {
	clear();

	if (len > 0) {
		_data = new uint8_t[len];
		if (!_data) {
			return false;
		}
		_len = len;
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void SimplePacket::clear() {
	if (_data) {
		delete[] _data;
		_data = NULL;
	}
	_len = 0;
	_destination = 0;
	_source = 0;
	_type = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::setData(bool data) {
	return setData((unsigned char) data ? 0x01 : 0x00);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::setData(char data) {
	return setData((uint8_t *) &data, sizeof(data));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::setData(unsigned char data) {
	return setData((uint8_t *) &data, sizeof(data));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::setData(int data) {
	return setData((uint8_t *) &data, sizeof(data));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::setData(unsigned int data) {
	return setData((uint8_t *) &data, sizeof(data));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::setData(long data) {
	return setData((uint8_t *) &data, sizeof(data));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::setData(unsigned long data) {
	return setData((uint8_t *) &data, sizeof(data));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::setData(double data) {
	return setData((uint8_t *) &data, sizeof(data));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::setData(const uint8_t *data, uint8_t len) {
	if (!data) {
		// Empty packet
		len = 0;
	}

	if (!init(len)) {
		// Memory error
		return false;
	}

	if (len > 0) {
		memcpy(_data, data, len);
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::setData(const char *data) {
	if (!data) {
		init(0);
		return true;
	}

	return setData((uint8_t *) data, strlen(data) + 1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::setData(const char *data, uint8_t len) {
	if (!data) {
		init(0);
		return true;
	}

	return setData((uint8_t *) data, len);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
bool SimplePacket::getBool() const {
	if (!_data) {
		return false;
	}

	return *(bool *) _data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
char SimplePacket::getChar() const {
	if (!_data) {
		return '\0';
	}

	return *(char *) _data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned char SimplePacket::getUChar() const {
	if (!_data) {
		return '\0';
	}

	return *(unsigned char *) _data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int SimplePacket::getInt() const {
	if (!_data) {
		return 0;
	}

	return *(int *) _data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned int SimplePacket::getUInt() const {
	if (!_data) {
		return 0;
	}

	return *(unsigned int *) _data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
long SimplePacket::getLong() const {
	if (!_data) {
		return 0L;
	}

	return *(long *) _data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned long SimplePacket::getULong() const {
	if (!_data) {
		return 0UL;
	}

	return *(unsigned long *) _data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
double SimplePacket::getDouble() const {
	if (!_data) {
		return 0.0L;
	}

	return *(double *) _data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const uint8_t *SimplePacket::getBuffer(uint8_t &len) const {
	len = _len;
	return _data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const char *SimplePacket::getString() const {
	uint8_t len;
	return (const char *) getBuffer(len);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
const char *SimplePacket::getString(uint8_t &len) const {
	return (const char *) getBuffer(len);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void SimplePacket::setSource(uint8_t source) {
	_source = source;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void SimplePacket::setDestination(uint8_t destination) {
	_destination = destination;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
void SimplePacket::setType(uint8_t type) {
	_type = type;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t SimplePacket::getSource() const {
	return _source;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t SimplePacket::getDestination() const {
	return _destination;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t SimplePacket::getType() const {
	return _type;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
uint8_t SimplePacket::getDataLength() const {
	return _len;
}
