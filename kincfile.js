let project = new Project('DearImGui');

project.addDefine('IMGUI_USER_CONFIG="imguiconfig.h"');
project.addIncludeDir('include');

project.addIncludeDir('cimgui/imgui');
project.addIncludeDir('cimgui');
project.addFiles(
	'cimgui/cimgui.h',
	'cimgui/cimgui.cpp',
	'cimgui/imgui/imgui.h',
	'cimgui/imgui/imgui.cpp',
	'cimgui/imgui/imgui_draw.cpp',
	'cimgui/imgui/imgui_widgets.cpp',
	'cimgui/imgui/imgui_demo.cpp'
);

project.addFiles('Sources/**', 'include/**', 'Shaders/**');
project.setDebugDir('Deployment');

resolve(project);
