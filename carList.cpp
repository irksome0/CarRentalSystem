#include <iostream>
#include <string>
#include "carList.h"

// STILL WORKING ON THIS. IT DOESN'T WORK PROPERLY

using namespace std;

carList::carList() { head = 0; }
carList::~carList() { delete[]  head; }

void carList::add(const connect& new_data) {
	cItem* temp = new cItem();
	temp->data = new_data;
	temp->next = head;
	head = temp;
}

connect carList::getNext() {
	connect result = head->data;
	head->prev = head;
	head = head->next;
	return result;
}

