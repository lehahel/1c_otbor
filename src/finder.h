#pragma once

#include <png.h>
#include <geometry.h>

#include <string>

using Geometry::CPoint;
using Geometry::CSegment;
class CSegmentFinder {
  public:
    CSegmentFinder(const std::string& filename);
    size_t FindIntersections();

  private:
    CPngFile data_;
    std::vector<CSegment> segments_;

    bool CheckArea(CPoint point);
    bool AreConnected(CPoint first, CPoint second);
    CSegment FindSuperSegment(CSegment segment);

    std::vector<CPoint> FindBlackPoints();
};