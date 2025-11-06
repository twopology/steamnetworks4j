#include <org_twopology_steamnetworks4j_SteamUGCNative.h>

//@line:7

		#include <steam_api.h>
		#include "SteamUGCCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:12

		return (intp) new SteamUGCCallback(env, javaCallback);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_createQueryUserUGCRequest(JNIEnv* env, jclass clazz, jint accountID, jint listType, jint matchingType, jint sortOrder, jint creatorAppID, jint consumerAppID, jint page) {


//@line:18

		UGCQueryHandle_t query = SteamUGC()->CreateQueryUserUGCRequest(accountID, (EUserUGCList) listType,
			(EUGCMatchingUGCType) matchingType, (EUserUGCListSortOrder) sortOrder, creatorAppID, consumerAppID, page);
		return (intp) query;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_createQueryAllUGCRequest(JNIEnv* env, jclass clazz, jint queryType, jint matchingType, jint creatorAppID, jint consumerAppID, jint page) {


//@line:25

		UGCQueryHandle_t query = SteamUGC()->CreateQueryAllUGCRequest((EUGCQuery) queryType,
			(EUGCMatchingUGCType) matchingType, creatorAppID, consumerAppID, page);
		return (intp) query;
	

}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_createQueryUGCDetailsRequest
(JNIEnv* env, jclass clazz, jlongArray obj_publishedFileIDs, jint numPublishedFileIDs, long long* publishedFileIDs) {

//@line:31

		UGCQueryHandle_t query = SteamUGC()->CreateQueryUGCDetailsRequest((PublishedFileId_t*) publishedFileIDs, numPublishedFileIDs);
		return (intp) query;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_createQueryUGCDetailsRequest(JNIEnv* env, jclass clazz, jlongArray obj_publishedFileIDs, jint numPublishedFileIDs) {
	long long* publishedFileIDs = (long long*)env->GetPrimitiveArrayCritical(obj_publishedFileIDs, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_createQueryUGCDetailsRequest(env, clazz, obj_publishedFileIDs, numPublishedFileIDs, publishedFileIDs);

	env->ReleasePrimitiveArrayCritical(obj_publishedFileIDs, publishedFileIDs, 0);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_sendQueryUGCRequest(JNIEnv* env, jclass clazz, jlong callback, jlong query) {


//@line:36

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->SendQueryUGCRequest(query);
		cb->onUGCQueryCompletedCall.Set(handle, cb, &SteamUGCCallback::onUGCQueryCompleted);
		return handle;
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getQueryUGCResult(JNIEnv* env, jclass clazz, jlong query, jint index, jobject details) {


//@line:43

		SteamUGCDetails_t result;

		if (SteamUGC()->GetQueryUGCResult(query, index, &result)) {
			jclass clazz = env->GetObjectClass(details);

			jfieldID field = env->GetFieldID(clazz, "publishedFileID", "J");
			env->SetLongField(details, field, (jlong) result.m_nPublishedFileId);

			field = env->GetFieldID(clazz, "result", "I");
			env->SetIntField(details, field, (jint) result.m_eResult);

			field = env->GetFieldID(clazz, "fileType", "I");
			env->SetIntField(details, field, (jint) result.m_eFileType);

			jstring title = env->NewStringUTF(result.m_rgchTitle);
			field = env->GetFieldID(clazz, "title", "Ljava/lang/String;");
			env->SetObjectField(details, field, title);

			jstring description = env->NewStringUTF(result.m_rgchDescription);
			field = env->GetFieldID(clazz, "description", "Ljava/lang/String;");
			env->SetObjectField(details, field, description);

			field = env->GetFieldID(clazz, "ownerID", "J");
			env->SetLongField(details, field, (jlong) result.m_ulSteamIDOwner);

			field = env->GetFieldID(clazz, "timeCreated", "I");
			env->SetIntField(details, field, (jint) result.m_rtimeCreated);

			field = env->GetFieldID(clazz, "timeUpdated", "I");
			env->SetIntField(details, field, (jint) result.m_rtimeUpdated);

			field = env->GetFieldID(clazz, "tagsTruncated", "Z");
			env->SetBooleanField(details, field, (jboolean) result.m_bTagsTruncated);

			jstring tags = env->NewStringUTF(result.m_rgchTags);
			field = env->GetFieldID(clazz, "tags", "Ljava/lang/String;");
			env->SetObjectField(details, field, tags);

			field = env->GetFieldID(clazz, "fileHandle", "J");
			env->SetLongField(details, field, (jlong) result.m_hFile);

			field = env->GetFieldID(clazz, "previewFileHandle", "J");
			env->SetLongField(details, field, (jlong) result.m_hPreviewFile);

			jstring fileName = env->NewStringUTF(result.m_pchFileName);
			field = env->GetFieldID(clazz, "fileName", "Ljava/lang/String;");
			env->SetObjectField(details, field, fileName);

			field = env->GetFieldID(clazz, "fileSize", "I");
			env->SetIntField(details, field, (jint) result.m_nFileSize);

			field = env->GetFieldID(clazz, "previewFileSize", "I");
			env->SetIntField(details, field, (jint) result.m_nPreviewFileSize);

			jstring url = env->NewStringUTF(result.m_rgchURL);
			field = env->GetFieldID(clazz, "url", "Ljava/lang/String;");
			env->SetObjectField(details, field, url);

			field = env->GetFieldID(clazz, "votesUp", "I");
			env->SetIntField(details, field, (jint) result.m_unVotesUp);

			field = env->GetFieldID(clazz, "votesDown", "I");
			env->SetIntField(details, field, (jint) result.m_unVotesDown);

			return true;
		}

		return false;
	

}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getQueryUGCPreviewURL(JNIEnv* env, jclass clazz, jlong query, jint index) {


//@line:114

		char url[1024];

		if (SteamUGC()->GetQueryUGCPreviewURL(query, index, url, 1024)) {
			return env->NewStringUTF(url);
		}

		return nullptr;
	

}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getQueryUGCMetadata(JNIEnv* env, jclass clazz, jlong query, jint index) {


//@line:124

		char metadata[k_cchDeveloperMetadataMax];

		if (SteamUGC()->GetQueryUGCMetadata(query, index, metadata, k_cchDeveloperMetadataMax)) {
			return env->NewStringUTF(metadata);
		}

		return nullptr;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getQueryUGCStatistic(JNIEnv* env, jclass clazz, jlong query, jint index, jint statType) {


//@line:134

		uint64 statValue;

		if (SteamUGC()->GetQueryUGCStatistic(query, index, (EItemStatistic) statType, &statValue)) {
			return statValue;
		}

		return 0;
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getQueryUGCNumAdditionalPreviews(JNIEnv* env, jclass clazz, jlong query, jint index) {


//@line:144

		return SteamUGC()->GetQueryUGCNumAdditionalPreviews(query, index);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getQueryUGCAdditionalPreview(JNIEnv* env, jclass clazz, jlong query, jint index, jint previewIndex, jobject previewData) {


//@line:149

		char url[1024];
		char fileName[1024];
		EItemPreviewType type;

		bool success = SteamUGC()->GetQueryUGCAdditionalPreview(query, index, previewIndex, url, 1024, fileName, 1024, &type);

		if (success) {
			jclass clazz = env->GetObjectClass(previewData);

			jstring urlOrVideoID = env->NewStringUTF(url);
			jfieldID field = env->GetFieldID(clazz, "urlOrVideoID", "Ljava/lang/String;");
			env->SetObjectField(previewData, field, urlOrVideoID);

			jstring originalFileName = env->NewStringUTF(fileName);
			field = env->GetFieldID(clazz, "originalFileName", "Ljava/lang/String;");
			env->SetObjectField(previewData, field, originalFileName);

			field = env->GetFieldID(clazz, "previewType", "I");
			env->SetIntField(previewData, field, (jint) type);
		}

		return success;
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getQueryUGCNumKeyValueTags(JNIEnv* env, jclass clazz, jlong query, jint index) {


//@line:174

		return SteamUGC()->GetQueryUGCNumKeyValueTags(query, index);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getQueryUGCKeyValueTag(JNIEnv* env, jclass clazz, jlong query, jint index, jint keyValueTagIndex, jobjectArray keyAndValue) {


//@line:178

		char key[1024];
		char value[1024];

		bool success = SteamUGC()->GetQueryUGCKeyValueTag(query, index, keyValueTagIndex, key, 1024, value, 1024);

		if (success) {
			env->SetObjectArrayElement(keyAndValue, 0, env->NewStringUTF(key));
			env->SetObjectArrayElement(keyAndValue, 1, env->NewStringUTF(value));
		}

		return success;
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_releaseQueryUserUGCRequest(JNIEnv* env, jclass clazz, jlong query) {


//@line:192

		return SteamUGC()->ReleaseQueryUGCRequest(query);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_addRequiredTag
(JNIEnv* env, jclass clazz, jlong query, jstring obj_tagName, char* tagName) {

//@line:196

		return SteamUGC()->AddRequiredTag(query, tagName);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_addRequiredTag(JNIEnv* env, jclass clazz, jlong query, jstring obj_tagName) {
	char* tagName = (char*)env->GetStringUTFChars(obj_tagName, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_addRequiredTag(env, clazz, query, obj_tagName, tagName);

	env->ReleaseStringUTFChars(obj_tagName, tagName);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_addExcludedTag
(JNIEnv* env, jclass clazz, jlong query, jstring obj_tagName, char* tagName) {

//@line:200

		return SteamUGC()->AddExcludedTag(query, tagName);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_addExcludedTag(JNIEnv* env, jclass clazz, jlong query, jstring obj_tagName) {
	char* tagName = (char*)env->GetStringUTFChars(obj_tagName, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_addExcludedTag(env, clazz, query, obj_tagName, tagName);

	env->ReleaseStringUTFChars(obj_tagName, tagName);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setReturnOnlyIDs(JNIEnv* env, jclass clazz, jlong query, jboolean returnOnlyIDs) {


//@line:204

		return SteamUGC()->SetReturnOnlyIDs(query, returnOnlyIDs);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setReturnKeyValueTags(JNIEnv* env, jclass clazz, jlong query, jboolean returnKeyValueTags) {


//@line:208

		return SteamUGC()->SetReturnKeyValueTags(query, returnKeyValueTags);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setReturnLongDescription(JNIEnv* env, jclass clazz, jlong query, jboolean returnLongDescription) {


//@line:212

		return SteamUGC()->SetReturnLongDescription(query, returnLongDescription);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setReturnMetadata(JNIEnv* env, jclass clazz, jlong query, jboolean returnMetadata) {


//@line:216

		return SteamUGC()->SetReturnMetadata(query, returnMetadata);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setReturnChildren(JNIEnv* env, jclass clazz, jlong query, jboolean returnChildren) {


//@line:220

		return SteamUGC()->SetReturnChildren(query, returnChildren);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setReturnAdditionalPreviews(JNIEnv* env, jclass clazz, jlong query, jboolean returnAdditionalPreviews) {


//@line:224

		return SteamUGC()->SetReturnAdditionalPreviews(query, returnAdditionalPreviews);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setReturnTotalOnly(JNIEnv* env, jclass clazz, jlong query, jboolean returnTotalOnly) {


//@line:228

		return SteamUGC()->SetReturnTotalOnly(query, returnTotalOnly);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setReturnPlaytimeStats(JNIEnv* env, jclass clazz, jlong query, jint days) {


//@line:232

		return SteamUGC()->SetReturnPlaytimeStats(query, (uint32) days);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setLanguage
(JNIEnv* env, jclass clazz, jlong query, jstring obj_language, char* language) {

//@line:236

		return SteamUGC()->SetLanguage(query, language);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setLanguage(JNIEnv* env, jclass clazz, jlong query, jstring obj_language) {
	char* language = (char*)env->GetStringUTFChars(obj_language, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setLanguage(env, clazz, query, obj_language, language);

	env->ReleaseStringUTFChars(obj_language, language);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setAllowCachedResponse(JNIEnv* env, jclass clazz, jlong query, jint maxAgeSeconds) {


//@line:240

		return SteamUGC()->SetAllowCachedResponse(query, maxAgeSeconds);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setCloudFileNameFilter
(JNIEnv* env, jclass clazz, jlong query, jstring obj_matchCloudFileName, char* matchCloudFileName) {

//@line:244

		return SteamUGC()->SetCloudFileNameFilter(query, matchCloudFileName);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setCloudFileNameFilter(JNIEnv* env, jclass clazz, jlong query, jstring obj_matchCloudFileName) {
	char* matchCloudFileName = (char*)env->GetStringUTFChars(obj_matchCloudFileName, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setCloudFileNameFilter(env, clazz, query, obj_matchCloudFileName, matchCloudFileName);

	env->ReleaseStringUTFChars(obj_matchCloudFileName, matchCloudFileName);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setMatchAnyTag(JNIEnv* env, jclass clazz, jlong query, jboolean matchAnyTag) {


//@line:248

		return SteamUGC()->SetMatchAnyTag(query, matchAnyTag);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setSearchText
(JNIEnv* env, jclass clazz, jlong query, jstring obj_searchText, char* searchText) {

//@line:252

		return SteamUGC()->SetSearchText(query, searchText);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setSearchText(JNIEnv* env, jclass clazz, jlong query, jstring obj_searchText) {
	char* searchText = (char*)env->GetStringUTFChars(obj_searchText, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setSearchText(env, clazz, query, obj_searchText, searchText);

	env->ReleaseStringUTFChars(obj_searchText, searchText);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setRankedByTrendDays(JNIEnv* env, jclass clazz, jlong query, jint days) {


//@line:256

		return SteamUGC()->SetRankedByTrendDays(query, days);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_addRequiredKeyValueTag
(JNIEnv* env, jclass clazz, jlong query, jstring obj_key, jstring obj_value, char* key, char* value) {

//@line:260

		return SteamUGC()->AddRequiredKeyValueTag(query, key, value);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_addRequiredKeyValueTag(JNIEnv* env, jclass clazz, jlong query, jstring obj_key, jstring obj_value) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);
	char* value = (char*)env->GetStringUTFChars(obj_value, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_addRequiredKeyValueTag(env, clazz, query, obj_key, obj_value, key, value);

	env->ReleaseStringUTFChars(obj_key, key);
	env->ReleaseStringUTFChars(obj_value, value);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_requestUGCDetails(JNIEnv* env, jclass clazz, jlong callback, jlong publishedFileID, jint maxAgeSeconds) {


//@line:264

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->RequestUGCDetails(publishedFileID, maxAgeSeconds);
		cb->onRequestUGCDetailsCall.Set(handle, cb, &SteamUGCCallback::onRequestUGCDetails);
		return handle;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_createItem(JNIEnv* env, jclass clazz, jlong callback, jint consumerAppID, jint fileType) {


//@line:271

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->CreateItem(consumerAppID, (EWorkshopFileType) fileType);
		cb->onCreateItemCall.Set(handle, cb, &SteamUGCCallback::onCreateItem);
		return handle;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_startItemUpdate(JNIEnv* env, jclass clazz, jint consumerAppID, jlong publishedFileID) {


//@line:278

		return SteamUGC()->StartItemUpdate(consumerAppID, publishedFileID);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemTitle
(JNIEnv* env, jclass clazz, jlong update, jstring obj_title, char* title) {

//@line:282

		return SteamUGC()->SetItemTitle(update, title);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemTitle(JNIEnv* env, jclass clazz, jlong update, jstring obj_title) {
	char* title = (char*)env->GetStringUTFChars(obj_title, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemTitle(env, clazz, update, obj_title, title);

	env->ReleaseStringUTFChars(obj_title, title);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemDescription
(JNIEnv* env, jclass clazz, jlong update, jstring obj_description, char* description) {

//@line:286

		return SteamUGC()->SetItemDescription(update, description);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemDescription(JNIEnv* env, jclass clazz, jlong update, jstring obj_description) {
	char* description = (char*)env->GetStringUTFChars(obj_description, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemDescription(env, clazz, update, obj_description, description);

	env->ReleaseStringUTFChars(obj_description, description);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemUpdateLanguage
(JNIEnv* env, jclass clazz, jlong update, jstring obj_language, char* language) {

//@line:290

		return SteamUGC()->SetItemUpdateLanguage(update, language);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemUpdateLanguage(JNIEnv* env, jclass clazz, jlong update, jstring obj_language) {
	char* language = (char*)env->GetStringUTFChars(obj_language, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemUpdateLanguage(env, clazz, update, obj_language, language);

	env->ReleaseStringUTFChars(obj_language, language);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemMetadata
(JNIEnv* env, jclass clazz, jlong update, jstring obj_metaData, char* metaData) {

//@line:294

		return SteamUGC()->SetItemMetadata(update, metaData);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemMetadata(JNIEnv* env, jclass clazz, jlong update, jstring obj_metaData) {
	char* metaData = (char*)env->GetStringUTFChars(obj_metaData, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemMetadata(env, clazz, update, obj_metaData, metaData);

	env->ReleaseStringUTFChars(obj_metaData, metaData);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemVisibility(JNIEnv* env, jclass clazz, jlong update, jint visibility) {


//@line:298

		return SteamUGC()->SetItemVisibility(update, (ERemoteStoragePublishedFileVisibility) visibility);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemTags(JNIEnv* env, jclass clazz, jlong update, jobjectArray tags, jint numTags) {


//@line:302

		SteamParamStringArray_t arrayTags;
		arrayTags.m_ppStrings = (numTags > 0) ? new const char*[numTags] : NULL;
		arrayTags.m_nNumStrings = numTags;
		for (int t = 0; t < numTags; t++) {
			arrayTags.m_ppStrings[t] = env->GetStringUTFChars((jstring) env->GetObjectArrayElement(tags, t), 0);
		}

		bool result = SteamUGC()->SetItemTags(update, &arrayTags);

		for (int t = 0; t < numTags; t++) {
			env->ReleaseStringUTFChars((jstring) env->GetObjectArrayElement(tags, t), arrayTags.m_ppStrings[t]);
		}
		delete[] arrayTags.m_ppStrings;

		return result;
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemContent
(JNIEnv* env, jclass clazz, jlong update, jstring obj_contentFolder, char* contentFolder) {

//@line:320

		return SteamUGC()->SetItemContent(update, contentFolder);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemContent(JNIEnv* env, jclass clazz, jlong update, jstring obj_contentFolder) {
	char* contentFolder = (char*)env->GetStringUTFChars(obj_contentFolder, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemContent(env, clazz, update, obj_contentFolder, contentFolder);

	env->ReleaseStringUTFChars(obj_contentFolder, contentFolder);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemPreview
(JNIEnv* env, jclass clazz, jlong update, jstring obj_previewFile, char* previewFile) {

//@line:324

		return SteamUGC()->SetItemPreview(update, previewFile);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemPreview(JNIEnv* env, jclass clazz, jlong update, jstring obj_previewFile) {
	char* previewFile = (char*)env->GetStringUTFChars(obj_previewFile, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_setItemPreview(env, clazz, update, obj_previewFile, previewFile);

	env->ReleaseStringUTFChars(obj_previewFile, previewFile);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_removeItemKeyValueTags
(JNIEnv* env, jclass clazz, jlong update, jstring obj_key, char* key) {

//@line:328

		return SteamUGC()->RemoveItemKeyValueTags(update, key);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_removeItemKeyValueTags(JNIEnv* env, jclass clazz, jlong update, jstring obj_key) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_removeItemKeyValueTags(env, clazz, update, obj_key, key);

	env->ReleaseStringUTFChars(obj_key, key);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_addItemKeyValueTag
(JNIEnv* env, jclass clazz, jlong update, jstring obj_key, jstring obj_value, char* key, char* value) {

//@line:332

		return SteamUGC()->AddItemKeyValueTag(update, key, value);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_addItemKeyValueTag(JNIEnv* env, jclass clazz, jlong update, jstring obj_key, jstring obj_value) {
	char* key = (char*)env->GetStringUTFChars(obj_key, 0);
	char* value = (char*)env->GetStringUTFChars(obj_value, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_addItemKeyValueTag(env, clazz, update, obj_key, obj_value, key, value);

	env->ReleaseStringUTFChars(obj_key, key);
	env->ReleaseStringUTFChars(obj_value, value);

	return JNI_returnValue;
}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_submitItemUpdate
(JNIEnv* env, jclass clazz, jlong callback, jlong update, jstring obj_changeNote, char* changeNote) {

//@line:336

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		if (changeNote[0] == '\0') {
			changeNote = nullptr;
		}
		SteamAPICall_t handle = SteamUGC()->SubmitItemUpdate(update, changeNote);
		cb->onSubmitItemUpdateCall.Set(handle, cb, &SteamUGCCallback::onSubmitItemUpdate);
		return handle;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_submitItemUpdate(JNIEnv* env, jclass clazz, jlong callback, jlong update, jstring obj_changeNote) {
	char* changeNote = (char*)env->GetStringUTFChars(obj_changeNote, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_submitItemUpdate(env, clazz, callback, update, obj_changeNote, changeNote);

	env->ReleaseStringUTFChars(obj_changeNote, changeNote);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_getItemUpdateProgress
(JNIEnv* env, jclass clazz, jlong update, jlongArray obj_bytesProcessedAndTotal, long long* bytesProcessedAndTotal) {

//@line:346

		uint64* values = (uint64*) bytesProcessedAndTotal;
		return SteamUGC()->GetItemUpdateProgress(update, &values[0], &values[1]);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getItemUpdateProgress(JNIEnv* env, jclass clazz, jlong update, jlongArray obj_bytesProcessedAndTotal) {
	long long* bytesProcessedAndTotal = (long long*)env->GetPrimitiveArrayCritical(obj_bytesProcessedAndTotal, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_getItemUpdateProgress(env, clazz, update, obj_bytesProcessedAndTotal, bytesProcessedAndTotal);

	env->ReleasePrimitiveArrayCritical(obj_bytesProcessedAndTotal, bytesProcessedAndTotal, 0);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_setUserItemVote(JNIEnv* env, jclass clazz, jlong callback, jlong publishedFileID, jboolean voteUp) {


//@line:351

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->SetUserItemVote(publishedFileID, voteUp);
		cb->onSetUserItemVoteCall.Set(handle, cb, &SteamUGCCallback::onSetUserItemVote);
		return handle;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getUserItemVote(JNIEnv* env, jclass clazz, jlong callback, jlong publishedFileID) {


//@line:358

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->GetUserItemVote(publishedFileID);
		cb->onGetUserItemVoteCall.Set(handle, cb, &SteamUGCCallback::onGetUserItemVote);
		return handle;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_addItemToFavorites(JNIEnv* env, jclass clazz, jlong callback, jint appID, jlong publishedFileID) {


//@line:365

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->AddItemToFavorites(appID, publishedFileID);
		cb->onUserFavoriteItemsListChangedCall.Set(handle, cb, &SteamUGCCallback::onUserFavoriteItemsListChanged);
		return handle;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_removeItemFromFavorites(JNIEnv* env, jclass clazz, jlong callback, jint appID, jlong publishedFileID) {


//@line:372

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->RemoveItemFromFavorites(appID, publishedFileID);
		cb->onUserFavoriteItemsListChangedCall.Set(handle, cb, &SteamUGCCallback::onUserFavoriteItemsListChanged);
		return handle;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_subscribeItem(JNIEnv* env, jclass clazz, jlong callback, jlong publishedFileID) {


//@line:379

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->SubscribeItem(publishedFileID);
		cb->onSubscribeItemCall.Set(handle, cb, &SteamUGCCallback::onSubscribeItem);
		return handle;
	 

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_unsubscribeItem(JNIEnv* env, jclass clazz, jlong callback, jlong publishedFileID) {


//@line:386

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->UnsubscribeItem(publishedFileID);
		cb->onUnsubscribeItemCall.Set(handle, cb, &SteamUGCCallback::onUnsubscribeItem);
		return handle;
	 

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getNumSubscribedItems(JNIEnv* env, jclass clazz) {


//@line:393

		return SteamUGC()->GetNumSubscribedItems();
	

}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_getSubscribedItems
(JNIEnv* env, jclass clazz, jlongArray obj_files, jint maxEntries, long long* files) {

//@line:397

		return SteamUGC()->GetSubscribedItems((PublishedFileId_t*) files, maxEntries);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getSubscribedItems(JNIEnv* env, jclass clazz, jlongArray obj_files, jint maxEntries) {
	long long* files = (long long*)env->GetPrimitiveArrayCritical(obj_files, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_getSubscribedItems(env, clazz, obj_files, maxEntries, files);

	env->ReleasePrimitiveArrayCritical(obj_files, files, 0);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getItemState(JNIEnv* env, jclass clazz, jlong publishedFileID) {


//@line:401

		return SteamUGC()->GetItemState(publishedFileID);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getItemInstallInfo(JNIEnv* env, jclass clazz, jlong publishedFileID, jobject installInfo) {


//@line:405

		char folder[1024];
		uint64 sizeOnDisk;
		uint32 timeStamp;

		if (SteamUGC()->GetItemInstallInfo(publishedFileID, &sizeOnDisk, folder, 1024, &timeStamp)) {

			jclass clzz = env->GetObjectClass(installInfo);

			jstring folderString = env->NewStringUTF(folder);
			jfieldID field = env->GetFieldID(clzz, "folder", "Ljava/lang/String;");
			env->SetObjectField(installInfo, field, folderString);

			field = env->GetFieldID(clzz, "sizeOnDisk", "I");
			env->SetIntField(installInfo, field, (jint) sizeOnDisk);

			return true;
		}

		return false;
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_getItemDownloadInfo
(JNIEnv* env, jclass clazz, jlong publishedFileID, jlongArray obj_bytesDownloadedAndTotal, long long* bytesDownloadedAndTotal) {

//@line:428


		uint64* values = (uint64*) bytesDownloadedAndTotal;
		return SteamUGC()->GetItemDownloadInfo(publishedFileID, &values[0], &values[1]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_getItemDownloadInfo(JNIEnv* env, jclass clazz, jlong publishedFileID, jlongArray obj_bytesDownloadedAndTotal) {
	long long* bytesDownloadedAndTotal = (long long*)env->GetPrimitiveArrayCritical(obj_bytesDownloadedAndTotal, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_getItemDownloadInfo(env, clazz, publishedFileID, obj_bytesDownloadedAndTotal, bytesDownloadedAndTotal);

	env->ReleasePrimitiveArrayCritical(obj_bytesDownloadedAndTotal, bytesDownloadedAndTotal, 0);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_deleteItem(JNIEnv* env, jclass clazz, jlong callback, jlong publishedFileID) {


//@line:434

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->DeleteItem(publishedFileID);
		cb->onDeleteItemCall.Set(handle, cb, &SteamUGCCallback::onDeleteItem);
		return handle;
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_downloadItem(JNIEnv* env, jclass clazz, jlong publishedFileID, jboolean highPriority) {


//@line:441

		return SteamUGC()->DownloadItem(publishedFileID, highPriority);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_initWorkshopForGameServer
(JNIEnv* env, jclass clazz, jint workshopDepotID, jstring obj_folder, char* folder) {

//@line:445

		return SteamUGC()->BInitWorkshopForGameServer(workshopDepotID, folder);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_initWorkshopForGameServer(JNIEnv* env, jclass clazz, jint workshopDepotID, jstring obj_folder) {
	char* folder = (char*)env->GetStringUTFChars(obj_folder, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_initWorkshopForGameServer(env, clazz, workshopDepotID, obj_folder, folder);

	env->ReleaseStringUTFChars(obj_folder, folder);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_suspendDownloads(JNIEnv* env, jclass clazz, jboolean suspend) {


//@line:449

		SteamUGC()->SuspendDownloads(suspend);
	

}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_startPlaytimeTracking
(JNIEnv* env, jclass clazz, jlong callback, jlongArray obj_publishedFileIDs, jint numPublishedFileIDs, long long* publishedFileIDs) {

//@line:453

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->StartPlaytimeTracking((PublishedFileId_t*) publishedFileIDs, numPublishedFileIDs);
		cb->onStartPlaytimeTrackingCall.Set(handle, cb, &SteamUGCCallback::onStartPlaytimeTracking);
		return handle;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_startPlaytimeTracking(JNIEnv* env, jclass clazz, jlong callback, jlongArray obj_publishedFileIDs, jint numPublishedFileIDs) {
	long long* publishedFileIDs = (long long*)env->GetPrimitiveArrayCritical(obj_publishedFileIDs, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_startPlaytimeTracking(env, clazz, callback, obj_publishedFileIDs, numPublishedFileIDs, publishedFileIDs);

	env->ReleasePrimitiveArrayCritical(obj_publishedFileIDs, publishedFileIDs, 0);

	return JNI_returnValue;
}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_stopPlaytimeTracking
(JNIEnv* env, jclass clazz, jlong callback, jlongArray obj_publishedFileIDs, jint numPublishedFileIDs, long long* publishedFileIDs) {

//@line:460

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->StopPlaytimeTracking((PublishedFileId_t*) publishedFileIDs, numPublishedFileIDs);
		cb->onStopPlaytimeTrackingCall.Set(handle, cb, &SteamUGCCallback::onStopPlaytimeTracking);
		return handle;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_stopPlaytimeTracking(JNIEnv* env, jclass clazz, jlong callback, jlongArray obj_publishedFileIDs, jint numPublishedFileIDs) {
	long long* publishedFileIDs = (long long*)env->GetPrimitiveArrayCritical(obj_publishedFileIDs, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamUGCNative_stopPlaytimeTracking(env, clazz, callback, obj_publishedFileIDs, numPublishedFileIDs, publishedFileIDs);

	env->ReleasePrimitiveArrayCritical(obj_publishedFileIDs, publishedFileIDs, 0);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamUGCNative_stopPlaytimeTrackingForAllItems(JNIEnv* env, jclass clazz, jlong callback) {


//@line:467

		SteamUGCCallback* cb = (SteamUGCCallback*) callback;
		SteamAPICall_t handle = SteamUGC()->StopPlaytimeTrackingForAllItems();
		cb->onStopPlaytimeTrackingForAllItemsCall.Set(handle, cb, &SteamUGCCallback::onStopPlaytimeTrackingForAllItems);
		return handle;
	

}

