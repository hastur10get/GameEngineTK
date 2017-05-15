#include"FollowCamera.h"
using namespace DirectX;
using namespace SimpleMath;
// 静的メンバ変数の初期化
const float FollowCamera::CAMERA_DISTANCE = 5.0f;

FollowCamera::FollowCamera(int width, int height):Camera(width,height)
{
	m_targetPos = Vector3::Zero;
	m_targetAngle = 0.0f;
}

void FollowCamera::Update()
{

	// 視点、参照点
	Vector3 eyepos, refpos;
	// 参照点座標を計算
	refpos = m_targetPos + Vector3(0, 2.0f, 0);
	// ターゲット座標からカメラ座標への差分
	Vector3 cameraV(0.0f, 0.0f, CAMERA_DISTANCE);
	// カメラの視線方向の逆方向に回転
	Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
	// カメラのベクトルを計算
	cameraV = Vector3::TransformNormal(cameraV, rotmat);
	// カメラ座標を計算
	eyepos = refpos + cameraV;

	SetEyePos(eyepos);
	SetRefPos(refpos);
	// 基底クラスの更新
	Camera::Update();
}

void FollowCamera::SetTargetPos(const DirectX::SimpleMath::Vector3 & targetpos)
{
	m_targetPos = targetpos;
}

void FollowCamera::SetTargetAngle(float targetangle)
{
	m_targetAngle = targetangle;
}
