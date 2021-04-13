#include <geometry.h>

Geometry::CPoint::CPoint(long long x, long long y) : x(x), y(y){};

bool Geometry::ProjectionIntersect(long long start1, long long end1, long long start2,
                          long long end2) {
    if (start1 > end1) {
        std::swap(start1, end1);
    }
    if (start2 > end2) {
        std::swap(start2, end2);
    }
    return std::max(start1, start2) <= std::min(end1, end2);
}

Geometry::Sign Geometry::AreaSign(Geometry::CPoint pt1, 
        Geometry::CPoint pt2, Geometry::CPoint pt3) {
    long long area =
      (pt2.x - pt1.x) * (pt3.y - pt1.y) - (pt2.y - pt1.y) * (pt3.x - pt1.x);
    if (area == 0) {
        return Geometry::ZERO;
    }
    return area > 0 ? Geometry::PLUS : Geometry::MINUS;
};


Geometry::CSegment::CSegment(CPoint start, CPoint end) : start(start), end(end){};

long double Geometry::CSegment::GetY(long long x) const {
    if (start.x == end.x) {
        return start.y;
    }
    return static_cast<long double>(start.y) +
         static_cast<long double>((end.y - start.y) * (x - start.x)) /
             static_cast<long double>(end.x - start.x);
}

bool Geometry::Intersect(const Geometry::CSegment &first,
               const Geometry::CSegment &second) {
    return ProjectionIntersect(first.start.x, first.end.x, second.start.x,
                              second.end.x) &&
         ProjectionIntersect(first.start.y, first.end.y, second.start.y,
                              second.end.y) &&
         Geometry::AreaSign(first.start, first.end, second.start) *
                 Geometry::AreaSign(first.start, first.end, second.end) <= 0 &&
         Geometry::AreaSign(second.start, second.end, first.start) *
                 Geometry::AreaSign(second.start, second.end, first.end) <= 0;
}