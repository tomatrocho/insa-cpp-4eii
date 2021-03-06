#pragma once

#include "MyGraphicObjectManager.hpp"
#include "MyGDIPlus.hpp"
#include "MyGraphicObject.hpp"

// replace int by strong typing for safer API
struct Position { 
	Position(int xx, int yy) : x(xx), y(yy) {};

	int x, y;
};

struct MySize { 
	MySize(int dxx, int dyy) : dx(dxx), dy(dyy) {}

	int dx, dy;
};

struct BoundingBox {
	Position p;
	MySize s;
};

struct Speed {
	Speed(int xx, int yy) : x(xx), y(yy) {};
	int x, y;
};

class MyGameElement {

public:	

	virtual ~MyGameElement(); // should always be virtual in case child have attributes

	void draw() const;
	virtual bool isHit(const BoundingBox &bb) const = 0;

	inline const BoundingBox &getBoundingBox() const {
		return bb_;
	}

protected :

    explicit MyGameElement(const Position &p, const MySize &s, Color c = Color::Black);
	explicit MyGameElement(const Position &p, int s, Color c = Color::Black);

	BoundingBox bb_;
	Color color_;
	MyGraphicObjectManager figures_;

	virtual void addGraphicObject() = 0;
};
