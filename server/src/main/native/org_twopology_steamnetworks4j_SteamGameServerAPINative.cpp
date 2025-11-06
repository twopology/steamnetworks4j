#include <org_twopology_steamnetworks4j_SteamGameServerAPINative.h>

//@line:7

		 #include <steam_gameserver.h>
		 static JavaVM* staticVM = 0;
	static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerAPINative_nativeInit
(JNIEnv* env, jclass clazz, jint ip, jshort gamePort, jshort queryPort, jint serverMode, jstring obj_versionString, char* versionString) {

//@line:13


		 if (env->GetJavaVM(&staticVM) != 0) {
			 return false;
		 }

		 return SteamGameServer_Init(ip, gamePort, queryPort,
			static_cast<EServerMode>(serverMode), versionString);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerAPINative_nativeInit(JNIEnv* env, jclass clazz, jint ip, jshort gamePort, jshort queryPort, jint serverMode, jstring obj_versionString) {
	char* versionString = (char*)env->GetStringUTFChars(obj_versionString, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerAPINative_nativeInit(env, clazz, ip, gamePort, queryPort, serverMode, obj_versionString, versionString);

	env->ReleaseStringUTFChars(obj_versionString, versionString);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerAPINative_nativeShutdown(JNIEnv* env, jclass clazz) {


//@line:23

		SteamGameServer_Shutdown();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerAPINative_runCallbacks(JNIEnv* env, jclass clazz) {


//@line:27

		SteamGameServer_RunCallbacks();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerAPINative_isSecure(JNIEnv* env, jclass clazz) {


//@line:31

		return SteamGameServer_BSecure();
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerAPINative_nativeGetSteamID(JNIEnv* env, jclass clazz) {


//@line:35

		return SteamGameServer_GetSteamID();
	

}

