#include "pch.h"
#include "MapBounds.h"
#include "Background.h"
#include "Collider.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Player.h"
#include "PlayerManager.h"

void MapBounds::Build()
{
    _rects.clear();

    vector<Object*> backgrounds = Object::FindObjects(LAYER::BACKGROUND);
    for (Object* obj : backgrounds)
    {
        Collider* col = obj->GetComponent<Collider>();
        if (col == nullptr) continue;

        Vec2 pos = obj->GetPosition();
        Vec2 size = col->GetSize();

        MapRect r;
        r.minX = pos.x - size.x / 2;
        r.maxX = pos.x + size.x / 2;
        r.minY = pos.y - size.y / 2;
        r.maxY = pos.y + size.y / 2;
        _rects.push_back(r);
    }

    Player* player = GET_SINGLE(PlayerManager)->player;
    Vec2 half = player->GetComponent<Collider>()->GetSize() * 0.5f;

    auto touchesRight = [&](int i) {
        for (int j = 0; j < (int)_rects.size(); ++j)
        {
            if (i == j) continue;
            if (abs(_rects[i].maxX - _rects[j].minX) < EPS &&
                _rects[i].minY < _rects[j].maxY - EPS &&
                _rects[i].maxY > _rects[j].minY + EPS)
                return true;
        }
        return false;
        };
    auto touchesLeft = [&](int i) {
        for (int j = 0; j < (int)_rects.size(); ++j)
        {
            if (i == j) continue;
            if (abs(_rects[i].minX - _rects[j].maxX) < EPS &&
                _rects[i].minY < _rects[j].maxY - EPS &&
                _rects[i].maxY > _rects[j].minY + EPS)
                return true;
        }
        return false;
        };
    auto touchesBottom = [&](int i) {
        for (int j = 0; j < (int)_rects.size(); ++j)
        {
            if (i == j) continue;
            if (abs(_rects[i].maxY - _rects[j].minY) < EPS &&
                _rects[i].minX < _rects[j].maxX - EPS &&
                _rects[i].maxX > _rects[j].minX + EPS)
                return true;
        }
        return false;
        };
    auto touchesTop = [&](int i) {
        for (int j = 0; j < (int)_rects.size(); ++j)
        {
            if (i == j) continue;
            if (abs(_rects[i].minY - _rects[j].maxY) < EPS &&
                _rects[i].minX < _rects[j].maxX - EPS &&
                _rects[i].maxX > _rects[j].minX + EPS)
                return true;
        }
        return false;
        };

    for (int i = 0; i < (int)_rects.size(); ++i)
    {
        if (!touchesLeft(i))   _rects[i].minX += half.x;
        if (!touchesRight(i))  _rects[i].maxX -= half.x;
        if (!touchesTop(i))    _rects[i].minY += half.y;
        if (!touchesBottom(i)) _rects[i].maxY -= half.y;
    }
}

bool MapBounds::IsInside(const Vec2& pos) const
{
    for (auto& r : _rects)
        if (pos.x >= r.minX && pos.x <= r.maxX && pos.y >= r.minY && pos.y <= r.maxY)
            return true;
    return false;
}

Vec2 MapBounds::ClosestPoint(const Vec2& pos) const
{
    Vec2 best = pos;
    float bestDistSq = FLT_MAX;
    for (auto& r : _rects)
    {
        Vec2 c;
        c.x = std::clamp(pos.x, r.minX, r.maxX);
        c.y = std::clamp(pos.y, r.minY, r.maxY);
        float d = (c - pos).LengthSquared();
        if (d < bestDistSq) { bestDistSq = d; best = c; }
    }
    return best;
}