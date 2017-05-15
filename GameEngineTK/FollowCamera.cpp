#include"FollowCamera.h"
using namespace DirectX;
using namespace SimpleMath;
// �ÓI�����o�ϐ��̏�����
const float FollowCamera::CAMERA_DISTANCE = 5.0f;

FollowCamera::FollowCamera(int width, int height):Camera(width,height)
{
	m_targetPos = Vector3::Zero;
	m_targetAngle = 0.0f;
}

void FollowCamera::Update()
{

	// ���_�A�Q�Ɠ_
	Vector3 eyepos, refpos;
	// �Q�Ɠ_���W���v�Z
	refpos = m_targetPos + Vector3(0, 2.0f, 0);
	// �^�[�Q�b�g���W����J�������W�ւ̍���
	Vector3 cameraV(0.0f, 0.0f, CAMERA_DISTANCE);
	// �J�����̎��������̋t�����ɉ�]
	Matrix rotmat = Matrix::CreateRotationY(m_targetAngle);
	// �J�����̃x�N�g�����v�Z
	cameraV = Vector3::TransformNormal(cameraV, rotmat);
	// �J�������W���v�Z
	eyepos = refpos + cameraV;

	SetEyePos(eyepos);
	SetRefPos(refpos);
	// ���N���X�̍X�V
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
