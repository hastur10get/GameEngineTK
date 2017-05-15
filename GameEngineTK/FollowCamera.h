#pragma once
#include "Camera.h"
class FollowCamera :public Camera
{
public:
	// 自機とカメラの距離
	static const float CAMERA_DISTANCE;
	FollowCamera(int width, int height);
	// 更新
	void Update() override;
	// 追従対処の座標をセット
	void SetTargetPos(const DirectX::SimpleMath::Vector3& targetpos);
	// 追従対象の回転角をセット
	void SetTargetAngle(float targetangle);
protected:
	// 追従対処の座標
	DirectX::SimpleMath::Vector3 m_targetPos;
	// 追従対象の回転角
	float m_targetAngle;
};