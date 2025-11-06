#include <org_twopology_steamnetworks4j_SteamAppsNative.h>

//@line:7

		#include <steam_api.h>
	JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_isSubscribed(JNIEnv* env, jclass clazz) {


//@line:11

		return SteamApps()->BIsSubscribed();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_isLowViolence(JNIEnv* env, jclass clazz) {


//@line:15

		return SteamApps()->BIsLowViolence();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_isCybercafe(JNIEnv* env, jclass clazz) {


//@line:19

		return SteamApps()->BIsCybercafe();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_isVACBanned(JNIEnv* env, jclass clazz) {


//@line:23

		return SteamApps()->BIsVACBanned();
	

}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_getCurrentGameLanguage(JNIEnv* env, jclass clazz) {


//@line:27

        return env->NewStringUTF(SteamApps()->GetCurrentGameLanguage());
	

}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_getAvailableGameLanguages(JNIEnv* env, jclass clazz) {


//@line:31

        return env->NewStringUTF(SteamApps()->GetAvailableGameLanguages());
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_isSubscribedApp(JNIEnv* env, jclass clazz, jint appID) {


//@line:35

		return SteamApps()->BIsSubscribedApp((AppId_t) appID);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_isDlcInstalled(JNIEnv* env, jclass clazz, jint appID) {


//@line:39

		return SteamApps()->BIsDlcInstalled((AppId_t) appID);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_getEarliestPurchaseUnixTime(JNIEnv* env, jclass clazz, jint appID) {


//@line:43

		return SteamApps()->GetEarliestPurchaseUnixTime((AppId_t) appID);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_isSubscribedFromFreeWeekend(JNIEnv* env, jclass clazz) {


//@line:47

		return SteamApps()->BIsSubscribedFromFreeWeekend();
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_getDLCCount(JNIEnv* env, jclass clazz) {


//@line:51

		return SteamApps()->GetDLCCount();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_installDLC(JNIEnv* env, jclass clazz, jint appID) {


//@line:55

		SteamApps()->InstallDLC((AppId_t) appID);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_uninstallDLC(JNIEnv* env, jclass clazz, jint appID) {


//@line:59

		SteamApps()->UninstallDLC((AppId_t) appID);
    

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_getAppOwner(JNIEnv* env, jclass clazz) {


//@line:63

		CSteamID steamID = SteamApps()->GetAppOwner();
		return (int64) steamID.ConvertToUint64();
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_getAppBuildId(JNIEnv* env, jclass clazz) {


//@line:68

        return SteamApps()->GetAppBuildId();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamAppsNative_setDlcContext(JNIEnv* env, jclass clazz, jint appID) {


//@line:72

		return SteamApps()->SetDlcContext((AppId_t) appID);
	

}

