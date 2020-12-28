#ifndef SHAPES_SHAPE_H_
#define SHAPES_SHAPE_H_

#include "Vec2D.h"
#include <vector>

class Shape
{
public:
	virtual Vec2D GetCenterPoint() const = 0;
	inline virtual std::vector<Vec2D> GetPoints() const { return mPoints; }
protected:
	std::vector<Vec2D> mPoints;
};

#endif