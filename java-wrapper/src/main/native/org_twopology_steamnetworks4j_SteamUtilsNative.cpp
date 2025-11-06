#include <org_twopology_steamnetworks4j_SteamUtilsNative.h>

//@line:9

		#include "SteamUtilsCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:13

		return (intp) new SteamUtilsCallback(env, javaCallback);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_getSecondsSinceAppActive(JNIEnv* env, jclass clazz) {


//@line:17

		return SteamUtils()->GetSecondsSinceAppActive();
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_getSecondsSinceComputerActive(JNIEnv* env, jclass clazz) {


//@line:21

		return SteamUtils()->GetSecondsSinceComputerActive();
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_getConnectedUniverse(JNIEnv* env, jclass clazz) {


//@line:25

		return SteamUtils()->GetConnectedUniverse();
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_getServerRealTime(JNIEnv* env, jclass clazz) {


//@line:30

		return SteamUtils()->GetServerRealTime();
	

}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_getIPCountry(JNIEnv* env, jclass clazz) {


//@line:34

		return env->NewStringUTF(SteamUtils()->GetIPCountry());
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_getImageWidth(JNIEnv* env, jclass clazz, jint image) {


//@line:38

		uint32 width, height;
		bool result = SteamUtils()->GetImageSize(image, &width, &height);
		return result ? width : -1;
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_getImageHeight(JNIEnv* env, jclass clazz, jint image) {


//@line:44

		uint32 width, height;
		bool result = SteamUtils()->GetImageSize(image, &width, &height);
		return result ? height : -1;
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUtilsNative_getImageSize
(JNIEnv* env, jclass clazz, jint image, jintArray obj_size, int* size) {

//@line:50

		return SteamUtils()->GetImageSize(image, (uint32*) &size[0], (uint32*) &size[1]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_getImageSize(JNIEnv* env, jclass clazz, jint image, jintArray obj_size) {
	int* size = (int*)env->GetPrimitiveArrayCritical(obj_size, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUtilsNative_getImageSize(env, clazz, image, obj_size, size);

	env->ReleasePrimitiveArrayCritical(obj_size, size, 0);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUtilsNative_getImageRGBA
(JNIEnv* env, jclass clazz, jint image, jobject obj_dest, jint bufferOffset, jint bufferSize, char* dest) {

//@line:55

		return SteamUtils()->GetImageRGBA(image, (uint8*) &dest[bufferOffset], bufferSize);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_getImageRGBA(JNIEnv* env, jclass clazz, jint image, jobject obj_dest, jint bufferOffset, jint bufferSize) {
	char* dest = (char*)(obj_dest?env->GetDirectBufferAddress(obj_dest):0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUtilsNative_getImageRGBA(env, clazz, image, obj_dest, bufferOffset, bufferSize, dest);


	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_getAppID(JNIEnv* env, jclass clazz) {


//@line:59

		return (AppId_t) SteamUtils()->GetAppID();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_setOverlayNotificationPosition(JNIEnv* env, jclass clazz, jint position) {


//@line:63

		SteamUtils()->SetOverlayNotificationPosition((ENotificationPosition) position);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUtilsNative_isAPICallCompleted
(JNIEnv* env, jclass clazz, jlong handle, jbooleanArray obj_result, bool* result) {

//@line:67

		return SteamUtils()->IsAPICallCompleted((SteamAPICall_t) handle, &result[0]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_isAPICallCompleted(JNIEnv* env, jclass clazz, jlong handle, jbooleanArray obj_result) {
	bool* result = (bool*)env->GetPrimitiveArrayCritical(obj_result, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUtilsNative_isAPICallCompleted(env, clazz, handle, obj_result, result);

	env->ReleasePrimitiveArrayCritical(obj_result, result, 0);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_getAPICallFailureReason(JNIEnv* env, jclass clazz, jlong handle) {


//@line:71

		return SteamUtils()->GetAPICallFailureReason((SteamAPICall_t) handle);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_enableWarningMessageHook(JNIEnv* env, jclass clazz, jlong callback, jboolean enable) {


//@line:75

		SteamUtilsCallback* cb = (SteamUtilsCallback*) callback;
		cb->enableWarningMessageHook(enable);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_isOverlayEnabled(JNIEnv* env, jclass clazz) {


//@line:80

		return SteamUtils()->IsOverlayEnabled();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_isSteamInBigPictureMode(JNIEnv* env, jclass clazz) {


//@line:84

		return SteamUtils()->IsSteamInBigPictureMode();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_isSteamChinaLauncher(JNIEnv* env, jclass clazz) {


//@line:88

		return SteamUtils()->IsSteamChinaLauncher();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_isSteamRunningOnSteamDeck(JNIEnv* env, jclass clazz) {


//@line:92

		return SteamUtils()->IsSteamRunningOnSteamDeck();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_showFloatingGamepadTextInput(JNIEnv* env, jclass clazz, jint keyboardMode, jint textFieldXPosition, jint textFieldYPosition, jint textFieldWidth, jint textFieldHeight) {


//@line:98

		return SteamUtils()->ShowFloatingGamepadTextInput((EFloatingGamepadTextInputMode) keyboardMode,
			textFieldXPosition, textFieldYPosition, textFieldWidth, textFieldHeight);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_setGameLauncherMode(JNIEnv* env, jclass clazz, jboolean isLauncherMode) {


//@line:103

		SteamUtils()->SetGameLauncherMode(isLauncherMode);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_dismissFloatingGamepadTextInput(JNIEnv* env, jclass clazz) {


//@line:107

		return SteamUtils()->DismissFloatingGamepadTextInput();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUtilsNative_dismissGamepadTextInput(JNIEnv* env, jclass clazz) {


//@line:111

		return SteamUtils()->DismissGamepadTextInput();
	

}

