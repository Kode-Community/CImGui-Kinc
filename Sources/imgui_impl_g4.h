// dear imgui: Renderer for G4

// You can copy and use unmodified imgui_impl_* files in your project. See main.cpp for an example of using this.
// If you are new to dear imgui, read examples/README.txt and read the documentation at the top of imgui.cpp.
// https://github.com/ocornut/imgui

#pragma once

#ifdef __cplusplus
 extern "C" {
#endif
KINC_FUNC bool     ImGui_ImplG4_Init(int window);
KINC_FUNC void     ImGui_ImplG4_Shutdown();
KINC_FUNC void     ImGui_ImplG4_NewFrame();
KINC_FUNC void     ImGui_ImplG4_RenderDrawData(struct ImDrawData* draw_data);

// Use if you want to reset your rendering device without losing ImGui state.
KINC_FUNC void     ImGui_ImplG4_InvalidateDeviceObjects();
KINC_FUNC bool     ImGui_ImplG4_CreateDeviceObjects();
#ifdef __cplusplus
 }
#endif