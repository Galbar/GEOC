#include <geoc/math/Math.h>
#include <geoc/math/Vector.h>

using namespace geoc;

num Math::orientation2D(const Vector3& p, const Vector3& q, const Vector3& r) {
	num q1_p1 = q[X] - p[X];
	num q2_p2 = q[Y] - p[Y];
	num r1_p1 = r[X] - p[X];
	num r2_p2 = r[Y] - p[Y];
	return 0.5 * ( q1_p1 * r2_p2 - r1_p1 * q2_p2 );
}

num Math::orientation25D(const Vector2& p, const Vector2& q, const Vector2& r, const Vector2& t) {
	//Exercise 3.
	return 0;
}
