#pragma once

#include <iostream>

namespace Geometry {

struct CPoint {
    CPoint() = delete;
    CPoint(long long x, long long y);
    long long x;
    long long y;
};

enum Sign { MINUS = -1, ZERO = 0, PLUS = 1 };

bool ProjectionIntersect(long long start1, long long end1, long long start2,
                          long long end2);

Sign AreaSign(CPoint pt1, CPoint pt2, CPoint pt3);

struct CSegment {
    CSegment() = delete;
    CSegment(CPoint start, CPoint end);
    CPoint start;
    CPoint end;
    long double GetY(long long x) const;
};

bool Intersect(const CSegment &first, const CSegment &second);

} // namespace Geometry
