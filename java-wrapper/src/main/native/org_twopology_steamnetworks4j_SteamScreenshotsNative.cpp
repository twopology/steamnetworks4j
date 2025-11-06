#include <org_twopology_steamnetworks4j_SteamScreenshotsNative.h>

//@line:9

		#include "SteamScreenshotsCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:13

		return (intp) new SteamScreenshotsCallback(env, javaCallback);
	

}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_writeScreenshot
(JNIEnv* env, jclass clazz, jobject obj_imageData, jint imageSize, jint width, jint height, char* imageData) {

//@line:18


		return SteamScreenshots()->WriteScreenshot(imageData, imageSize, width, height);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_writeScreenshot(JNIEnv* env, jclass clazz, jobject obj_imageData, jint imageSize, jint width, jint height) {
	char* imageData = (char*)(obj_imageData?env->GetDirectBufferAddress(obj_imageData):0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_writeScreenshot(env, clazz, obj_imageData, imageSize, width, height, imageData);


	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_addScreenshotToLibrary
(JNIEnv* env, jclass clazz, jstring obj_file, jstring obj_thumbnail, jint width, jint height, char* file, char* thumbnail) {

//@line:24


		return SteamScreenshots()->AddScreenshotToLibrary(file, thumbnail, width, height);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_addScreenshotToLibrary(JNIEnv* env, jclass clazz, jstring obj_file, jstring obj_thumbnail, jint width, jint height) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);
	char* thumbnail = (char*)env->GetStringUTFChars(obj_thumbnail, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_addScreenshotToLibrary(env, clazz, obj_file, obj_thumbnail, width, height, file, thumbnail);

	env->ReleaseStringUTFChars(obj_file, file);
	env->ReleaseStringUTFChars(obj_thumbnail, thumbnail);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_triggerScreenshot(JNIEnv* env, jclass clazz) {


//@line:29

		SteamScreenshots()->TriggerScreenshot();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_hookScreenshots(JNIEnv* env, jclass clazz, jboolean hook) {


//@line:33

		SteamScreenshots()->HookScreenshots(hook);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_setLocation
(JNIEnv* env, jclass clazz, jint screenshot, jstring obj_location, char* location) {

//@line:37

		return SteamScreenshots()->SetLocation(screenshot, location);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_setLocation(JNIEnv* env, jclass clazz, jint screenshot, jstring obj_location) {
	char* location = (char*)env->GetStringUTFChars(obj_location, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_setLocation(env, clazz, screenshot, obj_location, location);

	env->ReleaseStringUTFChars(obj_location, location);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_tagUser(JNIEnv* env, jclass clazz, jint screenshot, jlong steamID) {


//@line:41

		return SteamScreenshots()->TagUser(screenshot, (uint64) steamID);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_tagPublishedFile(JNIEnv* env, jclass clazz, jint screenshot, jlong publishedFileID) {


//@line:45

		return SteamScreenshots()->TagPublishedFile(screenshot, publishedFileID);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamScreenshotsNative_isScreenshotsHooked(JNIEnv* env, jclass clazz) {


//@line:49

		return SteamScreenshots()->IsScreenshotsHooked();
	

}

