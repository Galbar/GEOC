#include <geoc/geometry/Circle.h>
#include <geoc/scene/Point.h>
#include <geoc/math/Math.h>

using namespace geoc;
using namespace std;

void geoc::classify(const Circle& c, const Vector3& p, Colour3& colour, std::string& desc) {
	bool circle_orientation = Math::orientation2D(c[0], c[1], c[2]) < 0;
	num orientation = Math::orientation25D(c[0], c[1], c[2], p);
	if (orientation == 0)
	{
		colour = Colour3(1, 1, 0);
		desc = "Boundary";
	}
	else if (circle_orientation == (orientation > 0))
	{
		colour = Colour3(0, 1, 0);
		desc = "Interior";
	}
	else
	{
		colour = Colour3(1, 0, 0);
		desc = "Exterior";
	}
}
