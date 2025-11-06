#include <org_twopology_steamnetworks4j_SteamUserStatsNative.h>

//@line:7

		#include <steam_api.h>
		#include "SteamUserStatsCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:12

		return (intp) new SteamUserStatsCallback(env, javaCallback);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getStat__Ljava_lang_String_2_3I
(JNIEnv* env, jclass clazz, jstring obj_name, jintArray obj_value, char* name, int* value) {

//@line:18

		return SteamUserStats()->GetStat(name, &((int32*) value)[0]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getStat__Ljava_lang_String_2_3I(JNIEnv* env, jclass clazz, jstring obj_name, jintArray obj_value) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);
	int* value = (int*)env->GetPrimitiveArrayCritical(obj_value, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getStat__Ljava_lang_String_2_3I(env, clazz, obj_name, obj_value, name, value);

	env->ReleasePrimitiveArrayCritical(obj_value, value, 0);
	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_setStat__Ljava_lang_String_2I
(JNIEnv* env, jclass clazz, jstring obj_name, jint value, char* name) {

//@line:22

		return SteamUserStats()->SetStat(name, (int32) value);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_setStat__Ljava_lang_String_2I(JNIEnv* env, jclass clazz, jstring obj_name, jint value) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_setStat__Ljava_lang_String_2I(env, clazz, obj_name, value, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getStat__Ljava_lang_String_2_3F
(JNIEnv* env, jclass clazz, jstring obj_name, jfloatArray obj_value, char* name, float* value) {

//@line:26

		return SteamUserStats()->GetStat(name, &value[0]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getStat__Ljava_lang_String_2_3F(JNIEnv* env, jclass clazz, jstring obj_name, jfloatArray obj_value) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);
	float* value = (float*)env->GetPrimitiveArrayCritical(obj_value, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getStat__Ljava_lang_String_2_3F(env, clazz, obj_name, obj_value, name, value);

	env->ReleasePrimitiveArrayCritical(obj_value, value, 0);
	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_setStat__Ljava_lang_String_2F
(JNIEnv* env, jclass clazz, jstring obj_name, jfloat value, char* name) {

//@line:30

		return SteamUserStats()->SetStat(name, value);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_setStat__Ljava_lang_String_2F(JNIEnv* env, jclass clazz, jstring obj_name, jfloat value) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_setStat__Ljava_lang_String_2F(env, clazz, obj_name, value, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getAchievement
(JNIEnv* env, jclass clazz, jstring obj_name, jbooleanArray obj_achieved, char* name, bool* achieved) {

//@line:34

		return SteamUserStats()->GetAchievement(name, &achieved[0]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getAchievement(JNIEnv* env, jclass clazz, jstring obj_name, jbooleanArray obj_achieved) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);
	bool* achieved = (bool*)env->GetPrimitiveArrayCritical(obj_achieved, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getAchievement(env, clazz, obj_name, obj_achieved, name, achieved);

	env->ReleasePrimitiveArrayCritical(obj_achieved, achieved, 0);
	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_setAchievement
(JNIEnv* env, jclass clazz, jstring obj_name, char* name) {

//@line:38

		return SteamUserStats()->SetAchievement(name);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_setAchievement(JNIEnv* env, jclass clazz, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_setAchievement(env, clazz, obj_name, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_clearAchievement
(JNIEnv* env, jclass clazz, jstring obj_name, char* name) {

//@line:42

		return SteamUserStats()->ClearAchievement(name);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_clearAchievement(JNIEnv* env, jclass clazz, jstring obj_name) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_clearAchievement(env, clazz, obj_name, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_storeStats(JNIEnv* env, jclass clazz) {


//@line:46

		return SteamUserStats()->StoreStats();
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_indicateAchievementProgress
(JNIEnv* env, jclass clazz, jstring obj_name, jint curProgress, jint maxProgress, char* name) {

//@line:51

		return SteamUserStats()->IndicateAchievementProgress(name, curProgress, maxProgress);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_indicateAchievementProgress(JNIEnv* env, jclass clazz, jstring obj_name, jint curProgress, jint maxProgress) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_indicateAchievementProgress(env, clazz, obj_name, curProgress, maxProgress, name);

	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getNumAchievements(JNIEnv* env, jclass clazz) {


//@line:55

		return SteamUserStats()->GetNumAchievements();
	

}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getAchievementName(JNIEnv* env, jclass clazz, jint index) {


//@line:59

		return env->NewStringUTF(SteamUserStats()->GetAchievementName(index));
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_resetAllStats(JNIEnv* env, jclass clazz, jboolean achievementsToo) {


//@line:63

		return SteamUserStats()->ResetAllStats(achievementsToo);
	

}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_findOrCreateLeaderboard
(JNIEnv* env, jclass clazz, jlong callback, jstring obj_leaderboardName, jint leaderboardSortMethod, jint leaderboardDisplayType, char* leaderboardName) {

//@line:68

		SteamUserStatsCallback* cb = (SteamUserStatsCallback*) callback;
		SteamAPICall_t handle = SteamUserStats()->FindOrCreateLeaderboard(leaderboardName,
			(ELeaderboardSortMethod) leaderboardSortMethod, (ELeaderboardDisplayType) leaderboardDisplayType);
		cb->onLeaderboardFindResultCall.Set(handle, cb, &SteamUserStatsCallback::onLeaderboardFindResult);
		return handle;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_findOrCreateLeaderboard(JNIEnv* env, jclass clazz, jlong callback, jstring obj_leaderboardName, jint leaderboardSortMethod, jint leaderboardDisplayType) {
	char* leaderboardName = (char*)env->GetStringUTFChars(obj_leaderboardName, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_findOrCreateLeaderboard(env, clazz, callback, obj_leaderboardName, leaderboardSortMethod, leaderboardDisplayType, leaderboardName);

	env->ReleaseStringUTFChars(obj_leaderboardName, leaderboardName);

	return JNI_returnValue;
}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_findLeaderboard
(JNIEnv* env, jclass clazz, jlong callback, jstring obj_leaderboardName, char* leaderboardName) {

//@line:76

		SteamUserStatsCallback* cb = (SteamUserStatsCallback*) callback;
		SteamAPICall_t handle = SteamUserStats()->FindLeaderboard(leaderboardName);
		cb->onLeaderboardFindResultCall.Set(handle, cb, &SteamUserStatsCallback::onLeaderboardFindResult);
		return handle;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_findLeaderboard(JNIEnv* env, jclass clazz, jlong callback, jstring obj_leaderboardName) {
	char* leaderboardName = (char*)env->GetStringUTFChars(obj_leaderboardName, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_findLeaderboard(env, clazz, callback, obj_leaderboardName, leaderboardName);

	env->ReleaseStringUTFChars(obj_leaderboardName, leaderboardName);

	return JNI_returnValue;
}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getLeaderboardName(JNIEnv* env, jclass clazz, jlong leaderboard) {


//@line:83

		return env->NewStringUTF(SteamUserStats()->GetLeaderboardName(leaderboard));
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getLeaderboardEntryCount(JNIEnv* env, jclass clazz, jlong leaderboard) {


//@line:87

		return SteamUserStats()->GetLeaderboardEntryCount(leaderboard);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getLeaderboardSortMethod(JNIEnv* env, jclass clazz, jlong leaderboard) {


//@line:91

		return SteamUserStats()->GetLeaderboardSortMethod(leaderboard);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getLeaderboardDisplayType(JNIEnv* env, jclass clazz, jlong leaderboard) {


//@line:95

		return SteamUserStats()->GetLeaderboardDisplayType(leaderboard);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_downloadLeaderboardEntries(JNIEnv* env, jclass clazz, jlong callback, jlong leaderboard, jint leaderboardDataRequest, jint rangeStart, jint rangeEnd) {


//@line:100


		SteamUserStatsCallback* cb = (SteamUserStatsCallback*) callback;

		SteamAPICall_t handle = SteamUserStats()->DownloadLeaderboardEntries(leaderboard,
			(ELeaderboardDataRequest) leaderboardDataRequest, rangeStart, rangeEnd);

		cb->onLeaderboardScoresDownloadedCall.Set(handle, cb,
			&SteamUserStatsCallback::onLeaderboardScoresDownloaded);

		return handle;
	

}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_downloadLeaderboardEntriesForUsers
(JNIEnv* env, jclass clazz, jlong callback, jlong leaderboard, jlongArray obj_users, jint count, long long* users) {

//@line:114

		SteamUserStatsCallback* cb = (SteamUserStatsCallback*) callback;

		SteamAPICall_t handle = SteamUserStats()->DownloadLeaderboardEntriesForUsers(leaderboard, (CSteamID*)users, count);

		cb->onLeaderboardScoresDownloadedCall.Set(handle, cb,
			&SteamUserStatsCallback::onLeaderboardScoresDownloaded);

		return handle;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_downloadLeaderboardEntriesForUsers(JNIEnv* env, jclass clazz, jlong callback, jlong leaderboard, jlongArray obj_users, jint count) {
	long long* users = (long long*)env->GetPrimitiveArrayCritical(obj_users, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_downloadLeaderboardEntriesForUsers(env, clazz, callback, leaderboard, obj_users, count, users);

	env->ReleasePrimitiveArrayCritical(obj_users, users, 0);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getDownloadedLeaderboardEntry__JILorg_twopology_steamnetworks4j_SteamLeaderboardEntry_2_3II
(JNIEnv* env, jclass clazz, jlong entries, jint index, jobject entry, jintArray obj_details, jint detailsMax, int* details) {

//@line:127


		LeaderboardEntry_t result;

		if (SteamUserStats()->GetDownloadedLeaderboardEntry(entries, index, &result, details, detailsMax)) {
			jclass clazz = env->GetObjectClass(entry);

			jfieldID field = env->GetFieldID(clazz, "steamIDUser", "J");
			env->SetLongField(entry, field, (jlong) result.m_steamIDUser.ConvertToUint64());

			field = env->GetFieldID(clazz, "globalRank", "I");
			env->SetIntField(entry, field, (jint) result.m_nGlobalRank);

			field = env->GetFieldID(clazz, "score", "I");
			env->SetIntField(entry, field, (jint) result.m_nScore);

			field = env->GetFieldID(clazz, "details", "I");
			env->SetIntField(entry, field, (jint) result.m_cDetails);

			return true;
		}

		return false;

	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getDownloadedLeaderboardEntry__JILorg_twopology_steamnetworks4j_SteamLeaderboardEntry_2_3II(JNIEnv* env, jclass clazz, jlong entries, jint index, jobject entry, jintArray obj_details, jint detailsMax) {
	int* details = (int*)env->GetPrimitiveArrayCritical(obj_details, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getDownloadedLeaderboardEntry__JILorg_twopology_steamnetworks4j_SteamLeaderboardEntry_2_3II(env, clazz, entries, index, entry, obj_details, detailsMax, details);

	env->ReleasePrimitiveArrayCritical(obj_details, details, 0);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getDownloadedLeaderboardEntry__JILorg_twopology_steamnetworks4j_SteamLeaderboardEntry_2(JNIEnv* env, jclass clazz, jlong entries, jint index, jobject entry) {


//@line:154


		LeaderboardEntry_t result;

		if (SteamUserStats()->GetDownloadedLeaderboardEntry(entries, index, &result, NULL, 0)) {
			jclass clazz = env->GetObjectClass(entry);

			jfieldID field = env->GetFieldID(clazz, "steamIDUser", "J");
			env->SetLongField(entry, field, (jlong) result.m_steamIDUser.ConvertToUint64());

			field = env->GetFieldID(clazz, "globalRank", "I");
			env->SetIntField(entry, field, (jint) result.m_nGlobalRank);

			field = env->GetFieldID(clazz, "score", "I");
			env->SetIntField(entry, field, (jint) result.m_nScore);

			field = env->GetFieldID(clazz, "details", "I");
			env->SetIntField(entry, field, (jint) result.m_cDetails);

			return true;
		}

		return false;

	

}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_uploadLeaderboardScore__JJII_3II
(JNIEnv* env, jclass clazz, jlong callback, jlong leaderboard, jint method, jint score, jintArray obj_scoreDetails, jint scoreDetailsCount, int* scoreDetails) {

//@line:182


		SteamUserStatsCallback* cb = (SteamUserStatsCallback*) callback;

		SteamAPICall_t handle = SteamUserStats()->UploadLeaderboardScore(leaderboard,
			(ELeaderboardUploadScoreMethod) method, score, scoreDetails, scoreDetailsCount);

		cb->onLeaderboardScoreUploadedCall.Set(handle, cb,
			&SteamUserStatsCallback::onLeaderboardScoreUploaded);

		return handle;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_uploadLeaderboardScore__JJII_3II(JNIEnv* env, jclass clazz, jlong callback, jlong leaderboard, jint method, jint score, jintArray obj_scoreDetails, jint scoreDetailsCount) {
	int* scoreDetails = (int*)env->GetPrimitiveArrayCritical(obj_scoreDetails, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_uploadLeaderboardScore__JJII_3II(env, clazz, callback, leaderboard, method, score, obj_scoreDetails, scoreDetailsCount, scoreDetails);

	env->ReleasePrimitiveArrayCritical(obj_scoreDetails, scoreDetails, 0);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_uploadLeaderboardScore__JJII(JNIEnv* env, jclass clazz, jlong callback, jlong leaderboard, jint method, jint score) {


//@line:196


		SteamUserStatsCallback* cb = (SteamUserStatsCallback*) callback;

		SteamAPICall_t handle = SteamUserStats()->UploadLeaderboardScore(leaderboard,
			(ELeaderboardUploadScoreMethod) method, score, NULL, 0);

		cb->onLeaderboardScoreUploadedCall.Set(handle, cb,
			&SteamUserStatsCallback::onLeaderboardScoreUploaded);

		return handle;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getNumberOfCurrentPlayers(JNIEnv* env, jclass clazz, jlong callback) {


//@line:209

		SteamUserStatsCallback* cb = (SteamUserStatsCallback*) callback;

		SteamAPICall_t handle = SteamUserStats()->GetNumberOfCurrentPlayers();

		cb->onNumberOfCurrentPlayersReceivedCall.Set(handle, cb, &SteamUserStatsCallback::onNumberOfCurrentPlayersReceived);

		return handle;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_requestGlobalStats(JNIEnv* env, jclass clazz, jlong callback, jint historyDays) {


//@line:219

		SteamUserStatsCallback* cb = (SteamUserStatsCallback*) callback;

		SteamAPICall_t handle = SteamUserStats()->RequestGlobalStats(historyDays);

		cb->onGlobalStatsReceivedCall.Set(handle, cb, &SteamUserStatsCallback::onGlobalStatsReceived);

		return handle;
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getGlobalStat__Ljava_lang_String_2_3J
(JNIEnv* env, jclass clazz, jstring obj_name, jlongArray obj_value, char* name, long long* value) {

//@line:229

		return SteamUserStats()->GetGlobalStat(name, &((int64*) value)[0]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getGlobalStat__Ljava_lang_String_2_3J(JNIEnv* env, jclass clazz, jstring obj_name, jlongArray obj_value) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);
	long long* value = (long long*)env->GetPrimitiveArrayCritical(obj_value, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getGlobalStat__Ljava_lang_String_2_3J(env, clazz, obj_name, obj_value, name, value);

	env->ReleasePrimitiveArrayCritical(obj_value, value, 0);
	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getGlobalStat__Ljava_lang_String_2_3D
(JNIEnv* env, jclass clazz, jstring obj_name, jdoubleArray obj_value, char* name, double* value) {

//@line:233

		return SteamUserStats()->GetGlobalStat(name, &value[0]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getGlobalStat__Ljava_lang_String_2_3D(JNIEnv* env, jclass clazz, jstring obj_name, jdoubleArray obj_value) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);
	double* value = (double*)env->GetPrimitiveArrayCritical(obj_value, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getGlobalStat__Ljava_lang_String_2_3D(env, clazz, obj_name, obj_value, name, value);

	env->ReleasePrimitiveArrayCritical(obj_value, value, 0);
	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getGlobalStatHistory__Ljava_lang_String_2_3JI
(JNIEnv* env, jclass clazz, jstring obj_name, jlongArray obj_values, jint count, char* name, long long* values) {

//@line:237

		return SteamUserStats()->GetGlobalStatHistory(name, values, count * sizeof(int64));
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getGlobalStatHistory__Ljava_lang_String_2_3JI(JNIEnv* env, jclass clazz, jstring obj_name, jlongArray obj_values, jint count) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);
	long long* values = (long long*)env->GetPrimitiveArrayCritical(obj_values, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getGlobalStatHistory__Ljava_lang_String_2_3JI(env, clazz, obj_name, obj_values, count, name, values);

	env->ReleasePrimitiveArrayCritical(obj_values, values, 0);
	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getGlobalStatHistory__Ljava_lang_String_2_3DI
(JNIEnv* env, jclass clazz, jstring obj_name, jdoubleArray obj_values, jint count, char* name, double* values) {

//@line:241

		return SteamUserStats()->GetGlobalStatHistory(name, values, count * sizeof(double));
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getGlobalStatHistory__Ljava_lang_String_2_3DI(JNIEnv* env, jclass clazz, jstring obj_name, jdoubleArray obj_values, jint count) {
	char* name = (char*)env->GetStringUTFChars(obj_name, 0);
	double* values = (double*)env->GetPrimitiveArrayCritical(obj_values, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUserStatsNative_getGlobalStatHistory__Ljava_lang_String_2_3DI(env, clazz, obj_name, obj_values, count, name, values);

	env->ReleasePrimitiveArrayCritical(obj_values, values, 0);
	env->ReleaseStringUTFChars(obj_name, name);

	return JNI_returnValue;
}

