#pragma once

#include <d3d11.h>
#include <SimpleMath.h>

class Camera {
public:
	//�������烁���o�֐�������
	Camera(int width,int height);
	virtual ~Camera();
	//�X�V
	virtual void Update();
	// �r���[�s��̎擾
	const DirectX::SimpleMath::Matrix& GetView();
	//�ˉe�s��̎擾
	const DirectX::SimpleMath::Matrix& GetProjection();
	//���_���W�̃Z�b�g
	void SetEyePos(const DirectX::SimpleMath::Vector3& eyepos);
	//�����_�̃Z�b�g
	void SetRefPos(const DirectX::SimpleMath::Vector3& refpos);
	//�J�����̏�����x�N�g���̃Z�b�g
	void SetUpvecPos(const DirectX::SimpleMath::Vector3& upvec);
	
	void SetFovY(float FovY);
	void SetAspect(float aspect);
	void SetNearClip(float nearclip);
	void SetFarClip(float farclip);


protected:
	//��������E�E

	//�J�����̈ʒu�i���_���W�j
	DirectX::SimpleMath::Vector3 m_eyepos;
	//�J�����̌��Ă����i�����_/�Q�Ɠ_�j
	DirectX::SimpleMath::Vector3 m_refpos;
	//�J�����̏�����x�N�g��
	DirectX::SimpleMath::Vector3 m_upvec;
	//�r���[�s��
	DirectX::SimpleMath::Matrix m_view;
	//�ˉe�s��
	DirectX::SimpleMath::Matrix m_proj;
	//������������p
	float m_fovY;
	//�A�X�y�N�g��(���c�̔䗦)
	float m_aspect;
	//�j�A�N���b�v(��O�̕\�����E����)
	float m_nearclip;
	//�t�@�[�N���b�v(���̕\�����E����)
	float m_farclip;
};