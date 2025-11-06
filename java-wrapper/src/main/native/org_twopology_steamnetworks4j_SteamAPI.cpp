#include <org_twopology_steamnetworks4j_SteamAPI.h>

//@line:90

		#include <steam_api.h>

		static JavaVM* staticVM = 0;
	JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamAPI_nativeRestartAppIfNecessary(JNIEnv* env, jclass clazz, jint appId) {


//@line:96

		return SteamAPI_RestartAppIfNecessary(appId);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamAPI_releaseCurrentThreadMemory(JNIEnv* env, jclass clazz) {


//@line:100

		SteamAPI_ReleaseCurrentThreadMemory();
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamAPI_nativeInit(JNIEnv* env, jclass clazz) {


//@line:104

		if (env->GetJavaVM(&staticVM) != 0) {
			return false;
		}

		return SteamAPI_InitEx(nullptr);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamAPI_nativeShutdown(JNIEnv* env, jclass clazz) {


//@line:112

		SteamAPI_Shutdown();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamAPI_runCallbacks(JNIEnv* env, jclass clazz) {


//@line:116

		SteamAPI_RunCallbacks();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamAPI_isSteamRunningNative(JNIEnv* env, jclass clazz) {


//@line:120

		return SteamAPI_IsSteamRunning();
	

}

