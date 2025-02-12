﻿#pragma once

#include <Windows.h>
#include <wrl.h>

#define DIRECTINPUT_VERSION     0x0800          // DirectInputのバージョン指定
#include <dinput.h>

#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")

/// <summary>
/// 入力
/// </summary>
class Input
{
public:
	struct MouseMove
	{
		LONG    lX;
		LONG    lY;
		LONG    lZ;
	};

private: // エイリアス
	// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public: // 静的メンバ変数
	static Input *GetInstance();

public: // メンバ関数
	/// <summary>
	/// 初期化
	/// </summary>
	/// <returns>成否</returns>
	bool Initialize(HINSTANCE hInstance, HWND hwnd);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// キーの押下をチェック
	/// </summary>
	/// <param name="keyNumber">キー番号( DIK_0 等)</param>
	/// <returns>押されているか</returns>
	bool isKey(BYTE keyNumber);

	/// <summary>
	/// キーのトリガーをチェック
	/// </summary>
	/// <param name="keyNumber">キー番号( DIK_0 等)</param>
	/// <returns>トリガーか</returns>
	bool isKeyTrigger(BYTE keyNumber);

	/// <summary>
	/// キーの左ボタン押下をチェック
	/// </summary>
	/// <returns>押されているか</returns>
	bool isMouseLeft();

	/// <summary>
	/// キーの中ボタン押下をチェック
	/// </summary>
	/// <returns>押されているか</returns>
	bool isMouseMiddle();

	/// <summary>
	/// キーの左ボタントリガーをチェック
	/// </summary>
	/// <returns>トリガーか</returns>
	bool isMouseLeftTrigger();

	/// <summary>
	/// キーの中ボタントリガーをチェック
	/// </summary>
	/// <returns>トリガーか</returns>
	bool isMouseMiddleTrigger();

	/// <summary>
	/// マウス移動量を取得
	/// </summary>
	/// <returns>マウス移動量</returns>
	MouseMove GetMouseMove();

private: // メンバ変数
	ComPtr<IDirectInput8> dinput;
	ComPtr<IDirectInputDevice8> devKeyboard;
	BYTE key[256] = {};
	BYTE keyPre[256] = {};
	ComPtr<IDirectInputDevice8> devMouse;
	DIMOUSESTATE2 mouseState = {};
	DIMOUSESTATE2 mouseStatePre = {};
};

