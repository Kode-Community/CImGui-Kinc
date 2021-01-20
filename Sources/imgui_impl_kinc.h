// dear imgui: Platform Binding for Kinc

// You can copy and use unmodified imgui_impl_* files in your project. See main.cpp for an example of using this.
// If you are new to dear imgui, read examples/README.txt and read the documentation at the top of imgui.cpp.
// https://github.com/ocornut/imgui

#pragma once


CIMGUI_API bool     ImGui_ImplKinc_InitForG4(int window);
CIMGUI_API void     ImGui_ImplKinc_Shutdown();
CIMGUI_API void     ImGui_ImplKinc_NewFrame(int window);
CIMGUI_API bool     ImGui_ImplKinc_ProcessEvent();
