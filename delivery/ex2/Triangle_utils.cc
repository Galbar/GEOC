#include <geoc/geometry/Triangle.h>
#include <geoc/geometry/LineSegment.h>
#include <geoc/scene/Point.h>
#include <geoc/math/Math.h>
#include <geoc/GeocException.h>

using namespace geoc;
using namespace std;

void geoc::classify(const Triangle& t, const Vector3& p, Colour3& colour, std::string& desc) {
	desc = "";
	num orientation = Math::orientation2D(t[0], t[1], t[2]);
	bool side = (orientation > 0);

	num or1 = Math::orientation2D(t[0], t[1], p);
	num or2 = Math::orientation2D(t[1], t[2], p);
	num or3 = Math::orientation2D(t[2], t[0], p);

	if (or1 == 0 and (or2 == 0 or or3 == 0) or or2 == 0 and or3 == 0)
	{
		colour = Colour3(0, 1, 1);
		desc = "On a vertex";
	}
	else if (or1 == 0 and side == (or2 > 0) and side == (or3 > 0)
			 or or2 == 0 and side == (or1 > 0) and side == (or3 > 0)
			 or or3 == 0 and side == (or2 > 0) and side == (or1 > 0))
	{
		colour = Colour3(1, 1, 0);
		desc = "Interior of edge";
	}
	else if (side == (or1 > 0) and side == (or2 > 0) and side == (or3 > 0))
	{
		colour = Colour3(0, 1, 0);
		desc = "Interior";
	}

	if (desc == "")
	{
		colour = Colour3(1, 0, 0);
		desc = "Exterior";
	}
}
