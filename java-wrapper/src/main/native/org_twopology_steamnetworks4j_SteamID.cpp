#include <org_twopology_steamnetworks4j_SteamID.h>

//@line:45

		#include <steam_api.h>
	JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamID_isValid(JNIEnv* env, jclass clazz, jlong handle) {


//@line:49

		return CSteamID((uint64) handle).IsValid();
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamID_getInvalidSteamID(JNIEnv* env, jclass clazz) {


//@line:53

		return k_steamIDNil.ConvertToUint64();
	

}

