//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include "DebugCamera.h"
#include <Model.h>
#include <Keyboard.h>
#include "FollowCamera.h"
// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;
	//プリミティブバッチ
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionColor>> m_batch;
	//エフェクト
	std::unique_ptr<DirectX::BasicEffect> m_effect;
	//入力レイアウト
	Microsoft::WRL::ComPtr <ID3D11InputLayout > ｍ_inputLayout;

	std::unique_ptr<DirectX::CommonStates> m_states;
	//ワールド行列
	DirectX::SimpleMath::Matrix m_world;
	//ビュー行列
	DirectX::SimpleMath::Matrix m_view;
	//プロジェクション行列
	DirectX::SimpleMath::Matrix m_proj;

	//デバッグカメラ
	std::unique_ptr<DebugCamera> m_debugcamera;
	//エフェクトファクトリー
	std::unique_ptr<DirectX::EffectFactory> m_factory;
	//skyモデル
	std::unique_ptr<DirectX::Model> m_modelSkydome;
	//groundモデル
	std::unique_ptr<DirectX::Model> m_modelGround;
	//ballモデル
	std::unique_ptr<DirectX::Model> m_modelBall;
	//potモデル
	std::unique_ptr<DirectX::Model> m_modelTeapot;
	//頭
	std::unique_ptr<DirectX::Model> m_modelHead;

	//ballのワールド行列
	DirectX::SimpleMath::Matrix m_worldBall[10];
	DirectX::SimpleMath::Matrix m_worldBall1[10];
	//potのワールド行列
	DirectX::SimpleMath::Matrix m_worldPot[20];
	//カメラ
	std::unique_ptr<FollowCamera> m_Camera;
	std::unique_ptr<DirectX::Keyboard> m_keyboard;
	DirectX::SimpleMath::Vector3 head_pos;
	DirectX::SimpleMath::Matrix m_worldHead;
	float head_angle;

	float angle[20];
	float distance[20];
	float cnt,n;

};