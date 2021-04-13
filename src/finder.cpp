#include <finder.h>

#include <iostream>
#include <cmath>

const double POINTS_MATCH_REQUIRED = 0.9;

CSegmentFinder::CSegmentFinder(const std::string& filename)
    : data_(filename) {};

std::vector<CPoint> CSegmentFinder::FindBlackPoints() {
    std::vector<CPoint> black_points;
    size_t height = data_.GetHeight();
    size_t width = data_.GetWidth();
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            if (data_(i, j) == 0) {
                black_points.emplace_back(i, j);
            }
        }
    }
    return black_points;
}

bool CSegmentFinder::CheckArea(CPoint point) {
    bool res = true;
    size_t x = point.x;
    size_t y = point.y;

    if (x > 0 && y > 0 && x + 1 < data_.GetHeight()
                       && y + 1 < data_.GetWidth()) {
        res = res || (
                        data_(x - 1, y - 1) == 0 &&
                        data_(x - 1, y + 1) == 0 &&
                        data_(x - 1, y    ) == 0 &&
                        data_(x + 1, y - 1) == 0 &&
                        data_(x + 1, y + 1) == 0 &&
                        data_(x + 1, y    ) == 0 &&
                        data_(x    , y - 1) == 0 &&
                        data_(x    , y + 1) == 0 &&
                        data_(x    , y    ) == 0
                      );
    }
    return res;
}

bool CSegmentFinder::AreConnected(CPoint first, CPoint second) {
    if (first.x > second.x) {
        std::swap(first, second);
    }
    CSegment segment(first, second);
    size_t match_counter = 0;
    for (size_t x = first.x; x < second.x; ++x) {
        size_t y = static_cast<size_t>(round(segment.GetY(x)));
        if (CheckArea(CPoint(x, y))) {
            ++match_counter;
        }
    }
    int x_length = second.x - first.x;
    if (match_counter > static_cast<size_t>(x_length * POINTS_MATCH_REQUIRED)) {
        return true;
    }
    return false;
}

CSegment CSegmentFinder::FindSuperSegment(CSegment segment) {
    size_t x_start = segment.start.x;
    CPoint point1(x_start, static_cast<size_t>(round(segment.GetY(x_start))));
    while (point1.x > 0 && AreConnected(point1, segment.end)) {
        --point1.x;
    }

    size_t x_end = segment.end.x;
    CPoint point2(x_end, static_cast<size_t>(round(segment.GetY(x_end))));
    while (point2.x > 0 && AreConnected(point2, segment.start)) {
        ++point2.x;
    }
    return CSegment(point1, point2);
}

size_t CSegmentFinder::FindIntersections() {
    std::vector<CPoint> black_points = FindBlackPoints();
    for (CPoint start : black_points) {
        for (CPoint end : black_points) {
            if (start.x != end.x && AreConnected(start, end)) {
                segments_.push_back(FindSuperSegment(CSegment(start, end)));
            }
        }
    }
    size_t res = 0;
    for (auto seg_1 : segments_) {
        for (auto seg_2 : segments_) {
            if (Geometry::Intersect(seg_1, seg_2)) {
                ++res;
            }
        }
    }
    return res;
}
