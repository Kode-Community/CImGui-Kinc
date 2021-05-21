// dear imgui: standalone example application for SDL2 + DirectX 11
// If you are new to dear imgui, see examples/README.txt and documentation at the top of imgui.cpp.
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan graphics context creation, etc.)

#include <kinc/pch.h>

#include <kinc/graphics4/graphics.h>
#include <kinc/system.h>


#include "imgui_impl_kinc.h"
#include "imgui_impl_g4.h"
#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#include "cimgui.h"

#include <stdio.h>

// Data

    bool show_demo_window = true;
    bool show_another_window = false;
	ImVec4* clear_color;

static void update()
{
	
	ImVec2 none = *ImVec2_ImVec2Nil();

	kinc_g4_begin(0);

	// Start the Dear ImGui frame
	ImGui_ImplG4_NewFrame();
	ImGui_ImplKinc_NewFrame(0);
	igNewFrame();

	// 1. Show the big demo window (Most of the sample code is in igShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
	/*if (show_demo_window)
		igShowDemoWindow(&show_demo_window);*/

	// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
	{
		static float f = 0.0f;
		static int counter = 0;
		bool open = true;
		igBegin("Hello, world!",&open,0);                          // Create a window called "Hello, world!" and append into it.

		igText("This is %s useful text.","other");               // Display some text (you can use a format strings too)
		igCheckbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
		igCheckbox("Another Window", &show_another_window);

		igSliderFloat("float", &f, 0.0f, 1.0f,"%.3f",0);            // Edit 1 float using a slider from 0.0f to 1.0f
		igColorEdit3("clear color", (float*)&clear_color,0); // Edit 3 floats representing a color

		if (igButton("Button",none))                            // Buttons return true when clicked (most widgets return true when edited/activated)
			counter++;
		igSameLine(0.0f,-1.0f);
		igText("counter = %d", counter);

		igText("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / igGetIO()->Framerate, igGetIO()->Framerate);
		igEnd();
	}

	// 3. Show another simple window.
	if (show_another_window)
	{
		igBegin("Another Window", &show_another_window,0);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
		igText("Hello from another window!");
		if (igButton("Close Me",none))
			show_another_window = false;
		igEnd();
	}

	// Rendering
	igRender();
	/*g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);*/
	kinc_g4_clear(KINC_G4_CLEAR_COLOR, 0xff0000ff, 0.0f, 0);
	ImGui_ImplG4_RenderDrawData(igGetDrawData());

	kinc_g4_end(0);
	kinc_g4_swap_buffers();
}

// Main code
int kickstart(int argc, char** argv)
{
    // Setup SDL
    // (Some versions of SDL before <2.0.10 appears to have performance/stalling issues on a minority of Windows systems,
    // depending on whether SDL_INIT_GAMECONTROLLER is enabled or disabled.. updating to latest version of SDL is recommended!)
	kinc_init("Dear ImGui", 1024, 768, NULL, NULL);

	clear_color = ImVec4_ImVec4Float(0.45f, 0.55f, 0.60f, 1.00f);
    // Setup Dear ImGui context
    // igGetVersion();
    ImGuiContext* ctx = igCreateContext((ImFontAtlas*)0);
    ImGuiIO* io = igGetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    igStyleColorsDark((ImGuiStyle*)0);
    //igStyleColorsClassic();

    // Setup Platform/Renderer bindings
    ImGui_ImplKinc_InitForG4(0);
    ImGui_ImplG4_Init(0);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use igPushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'misc/fonts/README.txt' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    // Our state

    

	kinc_set_update_callback(update);
	kinc_start();
    
    // Cleanup
    ImGui_ImplG4_Shutdown();
    ImGui_ImplKinc_Shutdown();
    igDestroyContext(ctx);

    return 0;
}