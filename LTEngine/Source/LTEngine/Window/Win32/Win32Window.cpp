#include "LTEngine/Window/Window.h"
#include <Windows.h>
#include <stdexcept>
#pragma once

static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch (msg)
	{
	case WM_CLOSE:
	{
		PostQuitMessage();
		break;
	}
	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
}
	return 0;
}


ltengine::Window::Window()
{
	WNDCLASSEX wc{};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"LTengineWindow";
	wc.lpfnWndProc = &WindowProcedure;
	auto windowClassId = RegisterClassEx(&wc);

	if (!windowClassId)
		throw std::runtime_error("RegisterClassEx failed.");

	RECT rc{ 0, 0, 1280, 720 };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

	m_handle = CreateWindowEx(NULL, MAKEINTATOM(windowClassId), L"Dogs May Cry",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top,
		NULL, NULL, NULL, NULL);

	if (!m_handle)
		throw std::runtime_error("CreateWindowEx failed");
	ShowWindow(static_cast<HWND>(m_handle), SW_SHOW);
	

}
ltengine::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(m_handle));
}
