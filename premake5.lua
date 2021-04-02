-- Project configuration via premake, download at https://premake.github.io/download/

workspace "MemoizeCPP"
	configurations { "Debug", "Release" }

project "memoizeTests"
	kind "ConsoleApp"
	language "C++"

	files { "tests/**.cpp", "tests/**.h"  }
	includedirs { "./include" }

	filter "configurations:Debug"
	  defines { "DEBUG" }
	  symbols "On"

	filter "configurations:Release"
	  defines { "NDEBUG" }
	  optimize "On"
