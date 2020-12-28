#ifndef SHAPES_CIRCLE_H_
#define SHAPES_CIRCLE_H_

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle();
	Circle(const Vec2D& center, float radius);
	inline virtual Vec2D GetCenterPoint() const override { return mPoints[0]; }
	inline float GetRadius() const { return mRadius; }
	inline void SetRadius(float radius) { mRadius = radius; }
private:
	float mRadius;
};

#endif