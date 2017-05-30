#include <geoc/math/Math.h>
#include <geoc/math/Vector.h>

using namespace geoc;

inline num det2x2(num a, num b, num c, num d) {
	return a * d - b * c;
}

num Math::orientation2D(const Vector3& p, const Vector3& q, const Vector3& r) {
	num q1_p1 = q[X] - p[X];
	num q2_p2 = q[Y] - p[Y];
	num r1_p1 = r[X] - p[X];
	num r2_p2 = r[Y] - p[Y];
	return 0.5 * det2x2(q1_p1, r1_p1, q2_p2, r2_p2);
}

num Math::orientation25D(const Vector2& p, const Vector2& q, const Vector2& r, const Vector2& t) {
	num a, b, c,
		d, e, f,
		g, h, i;

	a = q[X] - p[X];
	b = q[Y] - p[Y];
	c = a * (q[X] + p[X]) + b * (q[Y] + p[Y]);
	d = r[X] - p[X];
	e = r[Y] - p[Y];
	f = d * (r[X] + p[X]) + e * (r[Y] + p[Y]);
	g = t[X] - p[X];
	h = t[Y] - p[Y];
	i = g * (t[X] + p[X]) + h * (t[Y] + p[Y]);
	return a * det2x2(e, f, h, i) - d * det2x2(b, c, h, i) + g * det2x2(b, c, e, f);
}
