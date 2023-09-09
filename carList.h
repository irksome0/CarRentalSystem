#pragma once

#include "connect.h"

#ifndef CARS_H
#define CARS_H

class carList : public connect {
public:
	cItem* head;
	carList();
	~carList();
	void add(const connect& new_data);
	void getCars();
	connect getNext();
};

#endif

