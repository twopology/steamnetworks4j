#include <org_twopology_steamnetworks4j_SteamGameServerStatsNative.h>

//@line:7

		#include "SteamGameServerStatsCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:11

		return (intp) new SteamGameServerStatsCallback(env, javaCallback);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_requestUserStats(JNIEnv* env, jclass clazz, jlong steamIDUser) {


//@line:15

		return SteamGameServerStats()->RequestUserStats((uint64) steamIDUser);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_getUserStat__JLjava_lang_String_2_3I
(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, jintArray obj_value, char* name, int* value) {

//@line:19

		return SteamGameServerStats()->GetUserStat((uint64) steamIDUser, name, &((int32*) value)[0]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_getUserStat__JLjava_lang_String_2_3I(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, jintArray obj_value) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);
	int* value = (int*)env->GetPrimitiveArrayCritical(obj_value, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_getUserStat__JLjava_lang_String_2_3I(env, clazz, steamIDUser, obj_name, obj_value, name, value);

	env->ReleasePrimitiveArrayCritical(obj_value, value, 0);
	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_getUserStat__JLjava_lang_String_2_3F
(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, jfloatArray obj_value, char* name, float* value) {

//@line:23

		return SteamGameServerStats()->GetUserStat((uint64) steamIDUser, name, &value[0]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_getUserStat__JLjava_lang_String_2_3F(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, jfloatArray obj_value) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);
	float* value = (float*)env->GetPrimitiveArrayCritical(obj_value, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_getUserStat__JLjava_lang_String_2_3F(env, clazz, steamIDUser, obj_name, obj_value, name, value);

	env->ReleasePrimitiveArrayCritical(obj_value, value, 0);
	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_getUserAchievement
(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, jbooleanArray obj_achieved, char* name, bool* achieved) {

//@line:27

		return SteamGameServerStats()->GetUserAchievement((uint64) steamIDUser, name, &achieved[0]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_getUserAchievement(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, jbooleanArray obj_achieved) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);
	bool* achieved = (bool*)env->GetPrimitiveArrayCritical(obj_achieved, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_getUserAchievement(env, clazz, steamIDUser, obj_name, obj_achieved, name, achieved);

	env->ReleasePrimitiveArrayCritical(obj_achieved, achieved, 0);
	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_setUserStat__JLjava_lang_String_2I
(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, jint value, char* name) {

//@line:31

		return SteamGameServerStats()->SetUserStat((uint64) steamIDUser, name, (int32) value);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_setUserStat__JLjava_lang_String_2I(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, jint value) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_setUserStat__JLjava_lang_String_2I(env, clazz, steamIDUser, obj_name, value, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_setUserStat__JLjava_lang_String_2F
(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, jfloat value, char* name) {

//@line:35

		return SteamGameServerStats()->SetUserStat((uint64) steamIDUser, name, value);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_setUserStat__JLjava_lang_String_2F(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, jfloat value) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_setUserStat__JLjava_lang_String_2F(env, clazz, steamIDUser, obj_name, value, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_updateUserAvgRateStat
(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, jfloat countThisSession, jdouble sessionLength, char* name) {

//@line:39

		return SteamGameServerStats()->UpdateUserAvgRateStat((uint64) steamIDUser, name, countThisSession, sessionLength);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_updateUserAvgRateStat(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, jfloat countThisSession, jdouble sessionLength) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_updateUserAvgRateStat(env, clazz, steamIDUser, obj_name, countThisSession, sessionLength, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_setUserAchievement
(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, char* name) {

//@line:43

		return SteamGameServerStats()->SetUserAchievement((uint64) steamIDUser, name);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_setUserAchievement(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_setUserAchievement(env, clazz, steamIDUser, obj_name, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_clearUserAchievement
(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name, char* name) {

//@line:47

		return SteamGameServerStats()->ClearUserAchievement((uint64) steamIDUser, name);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_clearUserAchievement(JNIEnv* env, jclass clazz, jlong steamIDUser, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_clearUserAchievement(env, clazz, steamIDUser, obj_name, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamGameServerStatsNative_storeUserStats(JNIEnv* env, jclass clazz, jlong steamIDUser) {


//@line:51

		return SteamGameServerStats()->StoreUserStats((uint64) steamIDUser);
	

}

