#include <geoc/geometry/LineSegment.h>
#include <geoc/math/Math.h>
#include <sstream>

using namespace geoc;
using namespace std;

Vector3 operator *(Vector3 u, const Vector3& v)
{
	u[X] *= v[X];
	u[Y] *= v[Y];
	u[Z] *= v[Z];
	return u;
}

void geoc::classifyIntersection(const LineSegment& s, const LineSegment& t, Colour3& colour, std::string& desc) {
	num d[4];
	d[0] = Math::orientation2D(s[0], s[1], t[0]);
	d[1] = Math::orientation2D(s[0], s[1], t[1]);
	d[2] = Math::orientation2D(t[0], t[1], s[0]);
	d[3] = Math::orientation2D(t[0], t[1], s[1]);
	num det0 = d[0] * d[1];
	num det1 = d[2] * d[3];
	desc = "";
	if (det0 < 0 and det1 < 0)
	{
		colour = Colour3(0, 1, 0);
		desc = "Full intersection";
	}
	else if (d[0] == 0 and d[1] == 0 and d[2] == 0 and d[3] == 0)
	{
		num max_x = s[0][X] > s[1][X] ? s[0][X] : s[1][X];
		num min_x = s[0][X] < s[1][X] ? s[0][X] : s[1][X];
		num max_y = s[0][Y] > s[1][Y] ? s[0][Y] : s[1][Y];
		num min_y = s[0][Y] < s[1][Y] ? s[0][Y] : s[1][Y];
		if (max_x >= t[0][X] and min_x <= t[0][X] and max_y >= t[0][Y] and min_y <= t[0][Y])
		{
			colour = Colour3(0, 0, 1);
			desc = "Colinear";
		}
		else if (max_x >= t[1][X] and min_x <= t[1][X] and max_y >= t[1][Y] and min_y <= t[1][Y])
		{
			colour = Colour3(0, 0, 1);
			desc = "Colinear";
		}
	}
	else if (det0 == 0 and det1 == 0)
	{
		colour = Colour3(1, 1, 0);
		desc = "One point in common";
	}
	else if (d[0] == 0)
	{
		Vector3 v1, v2, v3;
		v1 = s.to_vector();
		v3 = (t[0] - s[0]);
		v2 = v1 * v3;
		if (v2[X] >= 0 and v2[Y] >= 0 and v3.norm() <= v1.norm())
		{
			colour = Colour3(1, 0, 1);
			desc = "One point on the other segment";
		}
	}
	else if (d[1] == 0)
	{
		Vector3 v1, v2, v3;
		v1 = s.to_vector();
		v3 = (t[1] - s[0]);
		v2 = v1 * v3;
		if (v2[X] >= 0 and v2[Y] >= 0 and v3.norm() <= v1.norm())
		{
			colour = Colour3(1, 0, 1);
			desc = "One point on the other segment";
		}
	}
	else if (d[2] == 0)
	{
		Vector3 v1, v2, v3;
		v1 = t.to_vector();
		v3 = (s[0] - t[0]);
		v2 = v1 * v3;
		if (v2[X] >= 0 and v2[Y] >= 0 and v3.norm() <= v1.norm())
		{
			colour = Colour3(1, 0, 1);
			desc = "One point on the other segment";
		}
	}
	else if (d[3] == 0)
	{
		Vector3 v1, v2, v3;
		v1 = t.to_vector();
		v3 = (s[1] - t[0]);
		v2 = v1 * v3;
		if (v2[X] >= 0 and v2[Y] >= 0 and v3.norm() <= v1.norm())
		{
			colour = Colour3(1, 0, 1);
			desc = "One point on the other segment";
		}
	}

	if (desc == "")
	{
		colour = Colour3(1, 1, 1);
		desc = "No intersection";
	}
}
