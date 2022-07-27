workspace "CS396_ECS_A2"        -- Solution Name
    location "projects"         -- Create Solution in "PotatoEngine" folder
	architecture "x64"          -- build for 64 bits systems
	startproject "CS396_ECS_A2" -- start with this project

	configurations
	{
		"Debug",
		"Release"
	}

-- Type Aliases
outputdir        	= "projects/bin/%{cfg.buildcfg}"
objOutputDir     	= "projects/bin-int/%{cfg.buildcfg}"
sourceFilesPath  	= "%{prj.location}/../../src"
projectFilesPath 	= "projects"
depFilePath			= "dependencies"

------ Include Directories -------------------------------------------
IncludeDir = {}
IncludeDir["freeglut"] 	= "%{prj.location}/../../dependencies/freeglut/include"

------ PotatoEngine --------------------------------------------------
project "CS396_ECS_A2"
	location (projectFilesPath)
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
    warnings "Extra"
	staticruntime "on"
    characterset "MBCS"
	editAndContinue "Off"

    targetdir ( outputdir )
    objdir    ( objOutputDir )

	targetname ("CS396 Assignment 02")

    -- Adding Files into project
	files
	{
		-- For example files
		projectFilesPath .. "/**.cpp",
		projectFilesPath .. "/**.h",
		projectFilesPath .. "/**.hpp",

		-- Actual ECS files
		sourceFilesPath .. "/**.h",
        sourceFilesPath .. "/**.hpp",
		sourceFilesPath .. "/**.cpp",
        
        -- External Dependencies
        "%{prj.location}/../../dependencies/xecs/dependencies/xcore/src/*.h",
        "%{prj.location}/../../dependencies/xecs/dependencies/xcore/src/*.hpp",
        "%{prj.location}/../../dependencies/xecs/dependencies/xcore/src/*.cpp",
        
        "%{prj.location}/../../dependencies/xecs/src/*.h",
        "%{prj.location}/../../dependencies/xecs/src/*.hpp",
        "%{prj.location}/../../dependencies/xecs/src/*.cpp"
	}
    
    -- Adding Filters into project (to be edited)
    vpaths
    {
        ["*"] = { "**.h", "**.hpp", "**.cpp"}
    }

    -- Include Directories under C/C++ General
	includedirs
	{
        -- Internal Source Files
		sourceFilesPath .. "/",
		sourceFilesPath .. "/Settings",
        
        -- External Libraries
		"%{IncludeDir.freeglut}",
		"%{prj.location}/../../dependencies/xecs/src",
	}
    
    -- Prepocessor defines
	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"NOMINMAX"
	}
	
    -- Build Flags for compiling / linking
	flags
	{
		"MultiProcessorCompile"
	}

	-- Lib files pathing
	libdirs
	{ 
		"%{prj.location}/../../dependencies/freeglut_lib_bin/lib",
        "%{prj.location}/../../dependencies/xecs/dependencies/xcore"
	}

    -- Properties under "All" Configuration
	filter "system:windows"
		staticruntime "On"
		systemversion "latest"
		disablewarnings "4201"
		buildoptions { "/Zi" }

    -- Properties under "Debug" Configuration
	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		linkoptions{"/NODEFAULTLIB:libcmt.lib"}

	postbuildcommands
	{
		"{copy} ../../dependencies/freeglut_lib_bin/bin/freeglut.dll bin/%{cfg.buildcfg}",
		"{copy} ../../dependencies/freeglut_lib_bin/bin/freeglutd.dll bin/%{cfg.buildcfg}"
	}

    -- Properties under "Release" Configuration
	filter "configurations:Release"
		runtime "Release"
		optimize "On"

	postbuildcommands
	{
		"{copy} ../../dependencies/freeglut_lib_bin/bin/freeglut.dll bin/%{cfg.buildcfg}",
		"{copy} ../../dependencies/freeglut_lib_bin/bin/freeglutd.dll bin/%{cfg.buildcfg}"
	}
