#pragma once

struct MapRect
{
    float minX, minY, maxX, maxY;
};

class MapBounds
{
    DECLARE_SINGLE(MapBounds);
public:
    void Build();
    bool IsInside(const Vec2& pos) const;
    Vec2 ClosestPoint(const Vec2& pos) const;

private:
    vector<MapRect> _rects;
    const float EPS = 1.0f; // 인접 판정 오차 허용치(픽셀)
};

