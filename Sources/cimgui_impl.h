#pragma once 

extern bool     ImGui_ImplKinc_InitForG4(int window);
extern void     ImGui_ImplKinc_Shutdown();
extern void     ImGui_ImplKinc_NewFrame(int window);
extern bool     ImGui_ImplKinc_ProcessEvent();

extern bool     ImGui_ImplG4_Init(int window);
extern void     ImGui_ImplG4_Shutdown();
extern void     ImGui_ImplG4_NewFrame();
extern void     ImGui_ImplG4_RenderDrawData();

// Use if you want to reset your rendering device without losing ImGui state.
extern void     ImGui_ImplG4_InvalidateDeviceObjects();
extern bool     ImGui_ImplG4_CreateDeviceObjects();