#include "DxLib.h"

#include "Cube.h"
#include <iostream>

class Application
{
public:
	Application(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
		: m_width(640.f)
		, m_height(480.f)
	{

	}

	~Application()
	{
		::DxLib::DxLib_End();
	}


	bool Run()
	{
		int result = ::DxLib::SetGraphMode(
			static_cast<int>(m_width),
			static_cast<int>(m_height),
			32);

		::DxLib::ChangeWindowMode(TRUE);	// �E�C���h�E���[�h�ɕύX
		if (::DxLib::DxLib_Init() == -1)
		{
			MessageBox(nullptr, "Initializing error", "Error!", MB_ICONERROR | MB_TASKMODAL | MB_TOPMOST);
			return false;
		}


		// �`����ʂ𗠉�ʂɃZ�b�g
		SetDrawScreen(DX_SCREEN_BACK);


		float nearZ = 1.f, farZ = 100.f;

		SetCameraNearFar(nearZ, farZ);

		VECTOR3 cameraPos(0.f, 0.5f, -10.f);
		VECTOR3 targetPos(0.f, 0.f, 0.f);

		DxLib::SetCameraPositionAndTarget_UpVecY(cameraPos, targetPos);

		Cube cube(1.f);
		int keys[] = { KEY_INPUT_UP, KEY_INPUT_DOWN, KEY_INPUT_LEFT, KEY_INPUT_RIGHT };
		float val[] = { +0.1f, -0.1f, -0.1f, +0.1f };
		float* pos[][2] = { 
			{ &cameraPos.y, &targetPos.y },
			{ &cameraPos.y, &targetPos.y },
			{ &cameraPos.x, &targetPos.x },
			{ &cameraPos.x, &targetPos.x },
		};
		while (_LoopProc() && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
		{
			const std::vector<Face>& faces = cube.GetFaces();
			for (const Face& face : faces)
			{
				int vertexNum = static_cast<int>(face.GetVertexNum());
				
				for (int i = 0; i < vertexNum - 1; ++i)
				{
					int j = (i + 1) % vertexNum;

					// ���_�̎擾
					VECTOR4 from(face.GetVertexAt(i));
					VECTOR4 to(face.GetVertexAt(j));

					VECTOR3 from3d(from);
					VECTOR3 to3d(to);


					//------------------------------
					// ���W�ϊ�
					//------------------------------
					float dist = targetPos.z - cameraPos.z;
										
					MATRIX matT;
					CreateTranslationMatrix(matT, from.x, from.y, from.z);

					MATRIX matP;
					CreatePerspectiveLH(matP, m_width, m_height, nearZ, farZ);

					MATRIX mat;
					MultiplyMatrix(mat, matT, matP);
					
					Vector4Transform(from, from, mat);
					
					CreateTranslationMatrix(matT, to.x, to.y, to.z);
					MultiplyMatrix(mat, matT, matP);

					Vector4Transform(to, to, mat);

					/*
					D3DXMATRIX * D3DXMatrixPerspectiveLH(
						D3DXMATRIX * pOut,
						FLOAT w,	�߂��̃r���[ �v���[���ł̃r���[ �{�����[���̕�
						FLOAT h,	�߂��̃r���[ �v���[���ł̃r���[ �{�����[���̍���
						FLOAT zn,	�߂��̃r���[ �v���[���� z �l
						FLOAT zf	�����̃r���[ �v���[���� z �l
					);

					 2*zn/w  0       0              0 
					 0       2*zn/h  0              0 
					 0       0       zf/(zf-zn)     1 
					 0       0       zn*zf/(zn-zf)  0


					 D3DXMATRIX * D3DXMatrixPerspectiveRH(
						 D3DXMATRIX * pOut,
						 FLOAT w,	 FLOAT h,
						 FLOAT zn,	 FLOAT zf);
					 2*zn/w  0       0              0
					 0       2*zn/h  0              0
					 0       0       zf/(zn-zf)    -1
					 0       0       zn*zf/(zn-zf)  0
					*/
					
					
					/*
					D3DXMATRIX* D3DXMatrixPerspectiveFovLH(
						D3DXMATRIX * pOut,
						FLOAT fovy,		y �����̎���p (���W�A���P��)
						FLOAT Aspect,	�A�X�y�N�g�� (�r���[��Ԃ̕��������ŏ��Z���Ē�`(width/height))
						FLOAT zn,		�߂��̃r���[ �v���[���� z �l
						FLOAT zf		�����̃r���[ �v���[���� z �l
					);
					where: 
					yScale = cot(fovY/2)
					xScale = yScale / aspect ratio

					xScale     0          0               0
					0        yScale       0               0
					0          0       zf/(zf-zn)         1
					0          0       -zn*zf/(zf-zn)     0
					
					D3DXMATRIX * D3DXMatrixPerspectiveFovRH(
						  D3DXMATRIX * pOut,
						  FLOAT fovy, FLOAT Aspect,
						  FLOAT zn,	  FLOAT zf);
					xScale     0          0              0
					0        yScale       0              0
					0        0        zf/(zn-zf)        -1
					0        0        zn*zf/(zn-zf)      0
					
					*/

					/*
					D3DXMATRIX * D3DXMatrixLookAtLH(
						D3DXMATRIX * pOut,			�����̌��ʂ�\�� D3DXMATRIX �\���̂ւ̃|�C���^�[
						CONST D3DXVECTOR3 * pEye,	���_���`���� D3DXVECTOR3 �\���̂ւ̃|�C���^�[�ł��B���̒l�͕ϊ��Ɏg�p����܂��B
						CONST D3DXVECTOR3 * pAt,	�J�����̒����Ώۂ��`���� D3DXVECTOR3 �\���̂ւ̃|�C���^�[�ł��B
						CONST D3DXVECTOR3 * pUp		���݂̃��[���h���W�ɂ������������`���� D3DXVECTOR3 �\���̂ւ̃|�C���^�[�B���̍\���̂̒l�͒ʏ� [0, 1, 0] �ł��B
					);

					zaxis = normal(At - Eye)
					xaxis = normal(cross(Up, zaxis))
					yaxis = cross(zaxis, xaxis)
					xaxis.x           yaxis.x           zaxis.x          0
					xaxis.y           yaxis.y           zaxis.y          0
					xaxis.z           yaxis.z           zaxis.z          0
					-dot(xaxis, eye)  -dot(yaxis, eye)  -dot(zaxis, eye)  l

					D3DXMATRIX * D3DXMatrixLookAtRH(
						D3DXMATRIX * pOut,
						CONST D3DXVECTOR3 * pEye,
						CONST D3DXVECTOR3 * pAt,
						CONST D3DXVECTOR3 * pUp
					);
					zaxis = normal(Eye - At)
					xaxis = normal(cross(Up, zaxis))
					yaxis = cross(zaxis, xaxis)
					xaxis.x           yaxis.x           zaxis.x          0
					xaxis.y           yaxis.y           zaxis.y          0
					xaxis.z           yaxis.z           zaxis.z          0
					-dot(xaxis, eye)  -dot(yaxis, eye)  -dot(zaxis, eye)  l

					*/


					
					
					//------------------------------
					// �`��
					DxLib::DrawLine(from.x, from.y,
									to.x, to.y,
									GetColor(250, 0, 0));

					printf("from(%.1f, %.1f, %.1f) ", from.x, from.y, from.z);
					printf("to(%.1f, %.1f, %.1f)\n", to.x, to.y, to.z);

					DxLib::DrawLine3D(from3d, to3d, -1);
				}

			}

			{
				int i = 0;
				for (int key : keys)
				{
					if (CheckHitKey(key) != 0)
					{
						*pos[i][0] += val[i];
						*pos[i][1] += val[i];
					}
					++i;
				}
				DxLib::SetCameraPositionAndTarget_UpVecY(cameraPos, targetPos);
				DrawExtendFormatString(0, 0, 0.75, 0.75, -1, "camera(%.1f, %.1f, %.1f) target(%.1f, %.1f, %.1f)", cameraPos.x, cameraPos.y, cameraPos.z, targetPos.x, targetPos.y, targetPos.z);
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

private:
	float m_width;	//!< �E�B���h�E��
	float m_height;	//!< �E�B���h�E����
};


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�R���\�[����ʂ̌Ăяo��
	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONIN$", "r", stdin);

	Application app(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	if (!app.Run())return 1;


	FreeConsole();//�R���\�[���̉��
	return 0;
}