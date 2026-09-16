#pragma once
#include "Component.h"
class Collider : public Component
{
public:
    Collider();
    ~Collider();
public:
    // Component을(를) 통해 상속됨
    void LateUpdate() override;
    void Render(ComPtr<ID2D1RenderTarget> renderTarget) override {/* Empty */ }
public:
    void EnterCollision(Collider* other); // 충돌진입
    void StayCollision(Collider* other); // 충돌중
    void ExitCollision(Collider* other); // 충돌해제
    const UINT& GetID() const { return _id; }
public:
    void SetSize(Vec2 size) { _size = size; }
    const Vec2& GetSize() const { return _size; }
    void SetOffSetPosition(Vec2 offsetPosition)
    {
        _offsetPosition = offsetPosition;
    }
    const Vec2& GetOffSetPosition() const { return _offsetPosition; }
    const Vec2& GetLatedUpatedPos() const
    {
        return _latePosition;
    }
private:
    UINT _id; // 충돌체 고유 ID값
    static UINT _nextID;

    Vec2 _size; // 콜라이더 크기
    // Object로부터 상대적인 위치
    Vec2 _offsetPosition;
    // LateUpdate에서 매 프레임마다 오브젝트로부터 계산되는 위치
    Vec2 _latePosition;

};

