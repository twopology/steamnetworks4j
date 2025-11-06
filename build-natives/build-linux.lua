solution "steamnetworks4j"
	configurations { "release" }
	platforms { "x64" }

	buildoptions {
		"-std=c++11",
		"-Wall"
	}

	includedirs {
		"../java-wrapper/src/main/native/include/jni",
		"../java-wrapper/src/main/native/include/jni/linux",
		"../sdk/public/steam"
	}

	defines {
		"NDEBUG",
		"LINUX"
	}

	flags {
		"Optimize"
	}

	project "steamnetworks4j"

		kind "SharedLib"
		language "C++"

		files {
			"../java-wrapper/src/main/native/**.cpp"
		}

		includedirs {
			"../java-wrapper/src/main/native",
		}

        libdirs {
            "../sdk/redistributable_bin/linux64"
        }
        links {
            "steam_api"
        }

	project "steamnetworks4j-server"

		kind "SharedLib"
		language "C++"

		files {
			"../server/src/main/native/**.cpp"
		}

		excludes {
			"../server/src/main/native/**EncryptedAppTicket*.cpp"
		}

		includedirs {
			"../server/src/main/native",
		}

        libdirs {
            "../sdk/redistributable_bin/linux64"
        }
        links {
            "steam_api"
        }

	project "steamnetworks4j-encryptedappticket"

		kind "SharedLib"
		language "C++"

		files {
			"../server/src/main/native/**EncryptedAppTicket*.cpp"
		}

		includedirs {
			"../server/src/main/native",
		}

        libdirs {
            "../sdk/public/steam/lib/linux64"
        }
        links {
            "sdkencryptedappticket"
        }
