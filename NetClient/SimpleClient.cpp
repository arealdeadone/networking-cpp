#include <iostream>

#include <ltr_net.h>

enum class CustomMsgTypes : uint32_t {
	FireBullet,
	MovePlayer
};


int main() {
	ltr::net::message<CustomMsgTypes> msg;
	msg.header.id = CustomMsgTypes::FireBullet;

	int a = 10;
	bool b = true;
	float c = 3.14159f;

	struct {
		int x;
		int y;
	} d[5];

	msg << a << b << c << d;
	
	a = 99;
	b = false;
	c = 80.55f;

	msg >> d >> c >> b >> a;

	return 0;
}