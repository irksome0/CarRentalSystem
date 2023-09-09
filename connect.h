#pragma once

#ifndef CONNECT_H
#define CONNECT_H
class connect
{
};

class cItem: public connect {
public:
	connect data;
	cItem* prev;
	cItem* next;
};

#endif CONNECT_H

