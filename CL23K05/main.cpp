#include <iostream>
#include "CPoint.h"

int main(void) {
	CPoint<int> p1(10, 20, 30);
	CPoint<int> p2(10, 20, 30);
	p1.ShowPosition();
	p2.ShowPosition();

	p1 += p2;

	p1.ShowPosition();
	p2.ShowPosition();

	p1 += p2 + p2;
	p1.ShowPosition();
	p2.ShowPosition();

	p1.getDistance(p2);

	p1 /= 10;
	p1.getDistance(p2);

	p2.ShowPosition();
	p2.freeFall(1000);
	p2.ShowPosition();

	p2.verticalThrowUp(10000, 1);
	p2.ShowPosition();

	return 0;
}