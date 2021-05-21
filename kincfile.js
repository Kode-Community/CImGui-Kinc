let project = new Project('CImGui');

// project.addDefine('IMGUI_USER_CONFIG="imguiconfig.h"');

project.addExclude('cimgui/imgui/imconfig.h');
project.addDefine('IMGUI_INCLUDE_IMCONFIG_H');
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
	'cimgui/imgui/imgui_tables.cpp',
	'cimgui/imgui/imgui_demo.cpp'
);


project.addFiles('Sources/**', 'include/**', 'Shaders/**');
project.setDebugDir('Deployment');

resolve(project);
