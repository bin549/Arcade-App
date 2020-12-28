#include "AARectangle.h"


AARectangle::AARectangle() : AARectangle(Vec2D::Zero, Vec2D::Zero)
{
}

AARectangle::AARectangle(const Vec2D& topLeft, unsigned int width, unsigned int height)
{
	mPoints.push_back(topLeft);
	mPoints.push_back(Vec2D(topLeft.GetX() + width - 1, topLeft.GetY() + height - 1));
}

AARectangle::AARectangle(const Vec2D& topLeft, const Vec2D& bottomRight)
{
	mPoints.push_back(topLeft);
	mPoints.push_back(bottomRight);
}

float AARectangle::GetWidth() const
{
	return GetBottomRightPoint().GetX() - GetTopLeftPoint().GetX() + 1;
}

float AARectangle::GetHeight() const
{
	return GetBottomRightPoint().GetY() - GetTopLeftPoint().GetY() + 1;
}

std::vector<Vec2D> AARectangle::GetPoints() const
{
	std::vector<Vec2D> points;
	points.push_back(mPoints[0]);
	points.push_back(Vec2D(mPoints[1].GetX(), mPoints[0].GetY()));
	points.push_back(mPoints[1]);
	points.push_back(Vec2D(mPoints[0].GetX(), mPoints[1].GetY()));
	return points;
}

Vec2D AARectangle::GetCenterPoint() const
{
	return Vec2D(GetTopLeftPoint().GetX() + GetWidth() / 2.0f, GetTopLeftPoint().GetY() + GetHeight() / 2.0f);
}