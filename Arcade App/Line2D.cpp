#include "Line2D.h"

Line2D::Line2D() : Line2D(Vec2D::Zero, Vec2D::Zero)
{
}

Line2D::Line2D(float x0, float y0, float x1, float y1) : Line2D(Vec2D(x0, y0), Vec2D(x1, y1))
{
}

Line2D::Line2D(const Vec2D& p0, const Vec2D& p1) : mP0(p0), mP1(p1)
{
}
