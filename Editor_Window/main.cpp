﻿// Editor_Window.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#define BoradPos 100 , 100
#define BoradPosX 100
#define BoradPosY 100
#define BoradW 150
#define BoradH 450
#define BlockG 15

#include "framework.h"
#include "Editor_Window.h"

#include "..\\EX_Engine_SOURCE\\EApplication.h"
#include "..\\EX_Engine_Window\\ELoadScenes.h"
#include "..\\EX_Engine_Window\\ELoadResources.h"

EX::Application application;

ULONG_PTR gpToken;                  
Gdiplus::GdiplusStartupInput gpsi;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, // 프로그램의 인스턴스 핸들
                     _In_opt_ HINSTANCE hPrevInstance, // 바로앞에 실행된 현재 프로그램의 인스턴스 핸들, 없을경우에는 NULL
                                                        // 지금은 신경쓰지 않아도 되는 값
                     _In_ LPWSTR    lpCmdLine,          // 명령행으로 입력된 프로그램 인수
                     _In_ int       nCmdShow)           // 프로그램이 실행될 형태 , 보통 모양정보등이 전달됨.
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    //깃허브 테스트
    
    // TODO: 여기에 코드를 입력합니다.
    ///

    ///
    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EDITORWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOW));

    MSG msg;

    //(GetMessage(&msg, nullptr, 0, 0)
    // 프로세스에서 발생한 메세지를 메세지 큐에서 가져오는 ㅅ함수
    // 메세지큐에 아무것도 없다면??? 아무 메세지도 가져오지 않게된다

    // PeekMessage : 메세지큐에 메세지 유무에 상관없이 함수가 리턴된다.
    //                  리턴 값이 true인 경우 메세지가 있고 false인 경우는 메세지가 없다라고 가르켜준다.

    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            application.Run();
            // 메세지가 없을 경우 여기서 처리
            // 게임 로직이 들어가면 된다.
        }
    }

    // 기본 메시지 루프입니다:
    /*while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }*/
    Gdiplus::GdiplusShutdown(gpToken);

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EDITORWINDOW);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   const UINT width = 1600;
   const UINT height = 900;
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, width, height, 0, nullptr, nullptr, hInstance, nullptr);

   application.Initialize(hWnd, width, height);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   Gdiplus::GdiplusStartup(&gpToken, &gpsi, NULL);

   EX::LoadResources();
   EX::LoadScenes();
   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            
            PAINTSTRUCT ps;
           
            // DC란 화면에 출력에 필요한 모든 정보를 가지는 데이터 구조체이며
            // GDI모듈에 의해서 관리된다
            // 어떤 폰트를 사용할건가?, 어떤 선의 굵기를 정해줄건가 어떤 색상으로 그려줄껀가
            // 화면 출력에 필요한 모든 경우는 WINAPI에서는 DC를 통해서 작업을 진행할 수 있다.
            
            // 개인적인 생각
            // HDC는 필통정도로 생각함 그리기툴.

            HDC hdc = BeginPaint(hWnd, &ps);

            
            

            //HPEN redPen = CreatePen(PS_SOLID, 5, (RGB(255, 0, 0)));     //핸들선언과 동시에 초기화 
            //HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);              //이전핸들 저장
            //Ellipse(mHdc, 300, 300, 400, 400);                           //펜 사용
            //(HPEN)SelectObject(mHdc, oldPen);                            //이전브러쉬 되돌려놓기
            //DeleteObject(redPen);                                       //사용했던 브러쉬 삭제

            //// 스톡 오브젝트 (HBRUSH)GetStockObject( int Color );
            //					   /*""""""""""""""*/
            
            ////기본으로 자주사용 되는 GDI오브젝트를 미리 DC안에 만들어두었는데
            //// 그 오브젝트들을 스톡 오브젝트라고 한다.
            //HBRUSH graybrush = (HBRUSH)GetStockObject(GRAY_BRUSH);      //스톡오브젝트로 선언과 동시에 초기화
            //                         /*""""""""""""""*/
            //oldbrush = (HBRUSH)SelectObject(mHdc, graybrush);            //이전핸들 저장
            //Rectangle(mHdc, 100, 100, 300, 500);                         //브러쉬 사용
            //(HBRUSH)SelectObject(mHdc, oldbrush);                        //이전브러쉬 되돌려놓기
            //DeleteObject(graybrush);                                    //사용했던 브러쉬 삭제
            //Rectangle(mHdc, 500, 500, 600, 600);
            
            
            // 도형 ( 핸들 , 왼쪽 , 위 , 오른쪽 , 아래 )
            // 
            // 그린 순서대로 덮어씌워짐 (마지막에 그린 그림이 맨위에 위치함)
            
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
