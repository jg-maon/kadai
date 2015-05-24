#include "DxLib.h"

#include "Cube.h"

class Window
{
public:
	Window()
		: m_initialized(false)
		, m_width(640)
		, m_height(480)
	{

	}


	Window(int width, int height)
		: m_initialized(false)
		, m_width(width)
		, m_height(height)
	{
	}

	~Window()
	{

	}

	bool Init()
	{
		if (m_initialized)
		{
			return false;
		}
		int result = ::DxLib::SetGraphMode(
			m_width,
			m_height,
			32);

		if (DX_CHANGESCREEN_OK != result)
		{
			return false;
		}



		m_initialized = true;
		return true;
	}


private:
	bool m_initialized;
	int m_width;
	int m_height;
};

class Application
{
public:
	Application(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
	{

	}

	~Application()
	{
		::DxLib::DxLib_End();
	}


	bool Run()
	{
		Window window(640, 480);
		if (!window.Init())
		{
			return false;
		}

		::DxLib::ChangeWindowMode(TRUE);	// ウインドウモードに変更
		if (::DxLib::DxLib_Init() == -1)
		{
			MessageBox(nullptr, "Initializing error", "Error!", MB_ICONERROR | MB_TASKMODAL | MB_TOPMOST);
			return false;
		}


		// 描画先画面を裏画面にセット
		SetDrawScreen(DX_SCREEN_BACK);

		SetCameraNearFar(1.f, 100.f);

		VECTOR3 cameraPos(0.f, 0.f, -10.f);
		VECTOR3 targetPos(0.f, 0.f, 0.f);

		DxLib::SetCameraPositionAndTarget_UpVecY(cameraPos, targetPos);

		Cube cube(1.f);
		while (_LoopProc() && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
		{
			const std::vector<Face>& faces = cube.GetFaces();
			for (const Face& face : faces)
			{
				int vertexNum = static_cast<int>(face.GetVertexNum());
				
				for (int i = 0; i < vertexNum - 1; ++i)
				{
					int j = (i + 1) % vertexNum;

					// 頂点の取得
					VECTOR3 from(face.GetVertexAt(i));
					VECTOR3 to(face.GetVertexAt(j));

					// 座標変換
					
					// 描画
					DxLib::DrawLine3D(from, to, -1);
				}

			}
		}


		return true;
	}

private:

	bool _LoopProc()
	{
		return ScreenFlip() == 0
			&& ProcessMessage() == 0
			&& ClearDrawScreen() == 0;
	}
};


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Application app(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	if (!app.Run())return 1;
	return 0;
}