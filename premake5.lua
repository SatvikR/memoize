-- Project configuration via premake, download at https://premake.github.io/download/

workspace "MemoizeCPP"
	configurations { "Debug", "Release" }

project "memoize"
	kind "StaticLib"
	language "C++"
	
	files { "lib/**.cpp", "lib/**.h", "include/**.h" }
	includedirs { "./include" }
	
	filter "configurations:Debug"
	  defines { "DEBUG" }
	  symbols "On"

	filter "configurations:Release"
	  defines { "NDEBUG" }
	  optimize "On"



project "memoizeTests"
	kind "ConsoleApp"
	language "C++"

	files { "tests/**.cpp", "tests/**.cpp"  }
	includedirs { "./include" }
	libdirs { "bin/Release" }
	links { "memoize.lib" }

	filter "configurations:Debug"
	  defines { "DEBUG" }
	  symbols "On"

	filter "configurations:Release"
	  defines { "NDEBUG" }
	  optimize "On"
