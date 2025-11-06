#include <org_twopology_steamnetworks4j_SteamRemoteStorageNative.h>

//@line:9

		#include "SteamRemoteStorageCallback.h"
	JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_createCallback(JNIEnv* env, jclass clazz, jobject javaCallback) {


//@line:13

		return (intp) new SteamRemoteStorageCallback(env, javaCallback);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWrite
(JNIEnv* env, jclass clazz, jstring obj_file, jobject obj_data, jint bufferOffset, jint bufferSize, char* data, char* file) {

//@line:18

		return SteamRemoteStorage()->FileWrite(file, &data[bufferOffset], bufferSize);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWrite(JNIEnv* env, jclass clazz, jstring obj_file, jobject obj_data, jint bufferOffset, jint bufferSize) {
	char* data = (char*)(obj_data?env->GetDirectBufferAddress(obj_data):0);
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWrite(env, clazz, obj_file, obj_data, bufferOffset, bufferSize, data, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileRead
(JNIEnv* env, jclass clazz, jstring obj_file, jobject obj_buffer, jint bufferOffset, jint bufferSize, char* buffer, char* file) {

//@line:23

		return (jint) SteamRemoteStorage()->FileRead(file, &buffer[bufferOffset], bufferSize);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileRead(JNIEnv* env, jclass clazz, jstring obj_file, jobject obj_buffer, jint bufferOffset, jint bufferSize) {
	char* buffer = (char*)(obj_buffer?env->GetDirectBufferAddress(obj_buffer):0);
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileRead(env, clazz, obj_file, obj_buffer, bufferOffset, bufferSize, buffer, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWriteAsync
(JNIEnv* env, jclass clazz, jlong callback, jstring obj_file, jobject obj_data, jint bufferOffset, jint bufferSize, char* data, char* file) {

//@line:28

		SteamRemoteStorageCallback* cb = (SteamRemoteStorageCallback*) callback;
		SteamAPICall_t handle = SteamRemoteStorage()->FileWriteAsync(file, &data[bufferOffset], (uint32) bufferSize);
		cb->onFileWriteAsyncCompleteCall.Set(handle, cb, &SteamRemoteStorageCallback::onFileWriteAsyncComplete);
		return handle;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWriteAsync(JNIEnv* env, jclass clazz, jlong callback, jstring obj_file, jobject obj_data, jint bufferOffset, jint bufferSize) {
	char* data = (char*)(obj_data?env->GetDirectBufferAddress(obj_data):0);
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWriteAsync(env, clazz, callback, obj_file, obj_data, bufferOffset, bufferSize, data, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileReadAsync
(JNIEnv* env, jclass clazz, jlong callback, jstring obj_file, jint offset, jint toRead, char* file) {

//@line:35

		SteamRemoteStorageCallback* cb = (SteamRemoteStorageCallback*) callback;
		SteamAPICall_t handle = SteamRemoteStorage()->FileReadAsync(file, (uint32) offset, (uint32) toRead);
        cb->onFileReadAsyncCompleteCall.Set(handle, cb, &SteamRemoteStorageCallback::onFileReadAsyncComplete);
		return handle;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileReadAsync(JNIEnv* env, jclass clazz, jlong callback, jstring obj_file, jint offset, jint toRead) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileReadAsync(env, clazz, callback, obj_file, offset, toRead, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileReadAsyncComplete
(JNIEnv* env, jclass clazz, jlong readCall, jobject obj_buffer, jlong bufferOffset, jint toRead, char* buffer) {

//@line:43

		return SteamRemoteStorage()->FileReadAsyncComplete((SteamAPICall_t) readCall, &buffer[bufferOffset], (uint32) toRead);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileReadAsyncComplete(JNIEnv* env, jclass clazz, jlong readCall, jobject obj_buffer, jlong bufferOffset, jint toRead) {
	char* buffer = (char*)(obj_buffer?env->GetDirectBufferAddress(obj_buffer):0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileReadAsyncComplete(env, clazz, readCall, obj_buffer, bufferOffset, toRead, buffer);


	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileForget
(JNIEnv* env, jclass clazz, jstring obj_file, char* file) {

//@line:47

		return SteamRemoteStorage()->FileForget(file);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileForget(JNIEnv* env, jclass clazz, jstring obj_file) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileForget(env, clazz, obj_file, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileDelete
(JNIEnv* env, jclass clazz, jstring obj_file, char* file) {

//@line:51

		return SteamRemoteStorage()->FileDelete(file);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileDelete(JNIEnv* env, jclass clazz, jstring obj_file) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileDelete(env, clazz, obj_file, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileShare
(JNIEnv* env, jclass clazz, jlong callback, jstring obj_file, char* file) {

//@line:55

		SteamRemoteStorageCallback* cb = (SteamRemoteStorageCallback*) callback;
		SteamAPICall_t handle = SteamRemoteStorage()->FileShare(file);
		cb->onFileShareResultCall.Set(handle, cb, &SteamRemoteStorageCallback::onFileShareResult);
		return handle;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileShare(JNIEnv* env, jclass clazz, jlong callback, jstring obj_file) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileShare(env, clazz, callback, obj_file, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_setSyncPlatforms
(JNIEnv* env, jclass clazz, jstring obj_file, jint remoteStoragePlatform, char* file) {

//@line:62

		return SteamRemoteStorage()->SetSyncPlatforms(file, (ERemoteStoragePlatform) remoteStoragePlatform);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_setSyncPlatforms(JNIEnv* env, jclass clazz, jstring obj_file, jint remoteStoragePlatform) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_setSyncPlatforms(env, clazz, obj_file, remoteStoragePlatform, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWriteStreamOpen
(JNIEnv* env, jclass clazz, jstring obj_file, char* file) {

//@line:66

		return SteamRemoteStorage()->FileWriteStreamOpen(file);
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWriteStreamOpen(JNIEnv* env, jclass clazz, jstring obj_file) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWriteStreamOpen(env, clazz, obj_file, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWriteStreamWriteChunk
(JNIEnv* env, jclass clazz, jlong stream, jobject obj_data, jint bufferOffset, jint length, char* data) {

//@line:71

		return SteamRemoteStorage()->FileWriteStreamWriteChunk((UGCFileWriteStreamHandle_t) stream, &data[bufferOffset], length);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWriteStreamWriteChunk(JNIEnv* env, jclass clazz, jlong stream, jobject obj_data, jint bufferOffset, jint length) {
	char* data = (char*)(obj_data?env->GetDirectBufferAddress(obj_data):0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWriteStreamWriteChunk(env, clazz, stream, obj_data, bufferOffset, length, data);


	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWriteStreamClose(JNIEnv* env, jclass clazz, jlong stream) {


//@line:75

		return SteamRemoteStorage()->FileWriteStreamClose((UGCFileWriteStreamHandle_t) stream);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileWriteStreamCancel(JNIEnv* env, jclass clazz, jlong stream) {


//@line:79

		return SteamRemoteStorage()->FileWriteStreamCancel((UGCFileWriteStreamHandle_t) stream);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileExists
(JNIEnv* env, jclass clazz, jstring obj_file, char* file) {

//@line:83

		return SteamRemoteStorage()->FileExists(file);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileExists(JNIEnv* env, jclass clazz, jstring obj_file) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_fileExists(env, clazz, obj_file, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_filePersisted
(JNIEnv* env, jclass clazz, jstring obj_file, char* file) {

//@line:87

		return SteamRemoteStorage()->FilePersisted(file);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_filePersisted(JNIEnv* env, jclass clazz, jstring obj_file) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_filePersisted(env, clazz, obj_file, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getFileSize
(JNIEnv* env, jclass clazz, jstring obj_file, char* file) {

//@line:91

		return SteamRemoteStorage()->GetFileSize(file);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getFileSize(JNIEnv* env, jclass clazz, jstring obj_file) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getFileSize(env, clazz, obj_file, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getFileTimestamp
(JNIEnv* env, jclass clazz, jstring obj_file, char* file) {

//@line:95

		return SteamRemoteStorage()->GetFileTimestamp(file);
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getFileTimestamp(JNIEnv* env, jclass clazz, jstring obj_file) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getFileTimestamp(env, clazz, obj_file, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getSyncPlatforms
(JNIEnv* env, jclass clazz, jstring obj_file, char* file) {

//@line:99

		return SteamRemoteStorage()->GetSyncPlatforms(file);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getSyncPlatforms(JNIEnv* env, jclass clazz, jstring obj_file) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getSyncPlatforms(env, clazz, obj_file, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getFileCount(JNIEnv* env, jclass clazz) {


//@line:103

		return SteamRemoteStorage()->GetFileCount();
	

}

static inline jstring wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getFileNameAndSize
(JNIEnv* env, jclass clazz, jint index, jintArray obj_sizes, int* sizes) {

//@line:107

		return env->NewStringUTF(SteamRemoteStorage()->GetFileNameAndSize(index, &sizes[0]));
	
}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getFileNameAndSize(JNIEnv* env, jclass clazz, jint index, jintArray obj_sizes) {
	int* sizes = (int*)env->GetPrimitiveArrayCritical(obj_sizes, 0);

	jstring JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getFileNameAndSize(env, clazz, index, obj_sizes, sizes);

	env->ReleasePrimitiveArrayCritical(obj_sizes, sizes, 0);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getQuota
(JNIEnv* env, jclass clazz, jlongArray obj_totalBytes, jlongArray obj_availableBytes, long long* totalBytes, long long* availableBytes) {

//@line:111

		return SteamRemoteStorage()->GetQuota((uint64*) &totalBytes[0], (uint64*) &availableBytes[0]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getQuota(JNIEnv* env, jclass clazz, jlongArray obj_totalBytes, jlongArray obj_availableBytes) {
	long long* totalBytes = (long long*)env->GetPrimitiveArrayCritical(obj_totalBytes, 0);
	long long* availableBytes = (long long*)env->GetPrimitiveArrayCritical(obj_availableBytes, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getQuota(env, clazz, obj_totalBytes, obj_availableBytes, totalBytes, availableBytes);

	env->ReleasePrimitiveArrayCritical(obj_totalBytes, totalBytes, 0);
	env->ReleasePrimitiveArrayCritical(obj_availableBytes, availableBytes, 0);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_isCloudEnabledForAccount(JNIEnv* env, jclass clazz) {


//@line:115

		return SteamRemoteStorage()->IsCloudEnabledForAccount();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_isCloudEnabledForApp(JNIEnv* env, jclass clazz) {


//@line:119

		return SteamRemoteStorage()->IsCloudEnabledForApp();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_setCloudEnabledForApp(JNIEnv* env, jclass clazz, jboolean enabled) {


//@line:123

		SteamRemoteStorage()->SetCloudEnabledForApp(enabled);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_ugcDownload(JNIEnv* env, jclass clazz, jlong callback, jlong content, jint priority) {


//@line:127

		SteamRemoteStorageCallback* cb = (SteamRemoteStorageCallback*) callback;
		SteamAPICall_t handle = SteamRemoteStorage()->UGCDownload(content, priority);
		cb->onDownloadUGCResultCall.Set(handle, cb, &SteamRemoteStorageCallback::onDownloadUGCResult);
		return handle;
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getUGCDownloadProgress
(JNIEnv* env, jclass clazz, jlong content, jintArray obj_bytesDownloaded, jintArray obj_bytesExpected, int* bytesDownloaded, int* bytesExpected) {

//@line:135


		return SteamRemoteStorage()->GetUGCDownloadProgress((UGCHandle_t) content, (int32*) &bytesDownloaded[0], (int32*) &bytesExpected[0]);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getUGCDownloadProgress(JNIEnv* env, jclass clazz, jlong content, jintArray obj_bytesDownloaded, jintArray obj_bytesExpected) {
	int* bytesDownloaded = (int*)env->GetPrimitiveArrayCritical(obj_bytesDownloaded, 0);
	int* bytesExpected = (int*)env->GetPrimitiveArrayCritical(obj_bytesExpected, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getUGCDownloadProgress(env, clazz, content, obj_bytesDownloaded, obj_bytesExpected, bytesDownloaded, bytesExpected);

	env->ReleasePrimitiveArrayCritical(obj_bytesDownloaded, bytesDownloaded, 0);
	env->ReleasePrimitiveArrayCritical(obj_bytesExpected, bytesExpected, 0);

	return JNI_returnValue;
}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_ugcRead
(JNIEnv* env, jclass clazz, jlong content, jobject obj_buffer, jint bufferOffset, jint dataToRead, jint offset, jint action, char* buffer) {

//@line:142


		return SteamRemoteStorage()->UGCRead(content, &buffer[bufferOffset], dataToRead, offset, (EUGCReadAction) action);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_ugcRead(JNIEnv* env, jclass clazz, jlong content, jobject obj_buffer, jint bufferOffset, jint dataToRead, jint offset, jint action) {
	char* buffer = (char*)(obj_buffer?env->GetDirectBufferAddress(obj_buffer):0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_ugcRead(env, clazz, content, obj_buffer, bufferOffset, dataToRead, offset, action, buffer);


	return JNI_returnValue;
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getCachedUGCCount(JNIEnv* env, jclass clazz) {


//@line:147

		return SteamRemoteStorage()->GetCachedUGCCount();
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_getCachedUGCHandle(JNIEnv* env, jclass clazz, jint cachedContent) {


//@line:151

		return SteamRemoteStorage()->GetCachedUGCHandle(cachedContent);
	

}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_publishWorkshopFile
(JNIEnv* env, jclass clazz, jlong callback, jstring obj_file, jstring obj_previewFile, jint consumerAppID, jstring obj_title, jstring obj_description, jint visibility, jobjectArray tags, jint numTags, jint workshopFileType, char* file, char* previewFile, char* title, char* description) {

//@line:158


		SteamParamStringArray_t arrayTags;
		arrayTags.m_ppStrings = (numTags > 0) ? new const char*[numTags] : NULL;
		arrayTags.m_nNumStrings = numTags;
		for (int t = 0; t < numTags; t++) {
			arrayTags.m_ppStrings[t] = env->GetStringUTFChars((jstring) env->GetObjectArrayElement(tags, t), 0);
		}

		SteamRemoteStorageCallback* cb = (SteamRemoteStorageCallback*) callback;

		SteamAPICall_t handle = SteamRemoteStorage()->PublishWorkshopFile(file, previewFile, consumerAppID, title, description,
			(ERemoteStoragePublishedFileVisibility) visibility, &arrayTags, (EWorkshopFileType) workshopFileType);

		cb->onPublishFileResultCall.Set(handle, cb, &SteamRemoteStorageCallback::onPublishFileResult);

		for (int t = 0; t < numTags; t++) {
			env->ReleaseStringUTFChars((jstring) env->GetObjectArrayElement(tags, t), arrayTags.m_ppStrings[t]);
		}
		delete[] arrayTags.m_ppStrings;

		return handle;
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_publishWorkshopFile(JNIEnv* env, jclass clazz, jlong callback, jstring obj_file, jstring obj_previewFile, jint consumerAppID, jstring obj_title, jstring obj_description, jint visibility, jobjectArray tags, jint numTags, jint workshopFileType) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);
	char* previewFile = (char*)env->GetStringUTFChars(obj_previewFile, 0);
	char* title = (char*)env->GetStringUTFChars(obj_title, 0);
	char* description = (char*)env->GetStringUTFChars(obj_description, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_publishWorkshopFile(env, clazz, callback, obj_file, obj_previewFile, consumerAppID, obj_title, obj_description, visibility, tags, numTags, workshopFileType, file, previewFile, title, description);

	env->ReleaseStringUTFChars(obj_file, file);
	env->ReleaseStringUTFChars(obj_previewFile, previewFile);
	env->ReleaseStringUTFChars(obj_title, title);
	env->ReleaseStringUTFChars(obj_description, description);

	return JNI_returnValue;
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_createPublishedFileUpdateRequest(JNIEnv* env, jclass clazz, jlong publishedFileID) {


//@line:182

		return SteamRemoteStorage()->CreatePublishedFileUpdateRequest(publishedFileID);
	

}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFileFile
(JNIEnv* env, jclass clazz, jlong updateHandle, jstring obj_file, char* file) {

//@line:186

		return SteamRemoteStorage()->UpdatePublishedFileFile(updateHandle, file);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFileFile(JNIEnv* env, jclass clazz, jlong updateHandle, jstring obj_file) {
	char* file = (char*)env->GetStringUTFChars(obj_file, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFileFile(env, clazz, updateHandle, obj_file, file);

	env->ReleaseStringUTFChars(obj_file, file);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFilePreviewFile
(JNIEnv* env, jclass clazz, jlong updateHandle, jstring obj_previewFile, char* previewFile) {

//@line:190

		return SteamRemoteStorage()->UpdatePublishedFilePreviewFile(updateHandle, previewFile);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFilePreviewFile(JNIEnv* env, jclass clazz, jlong updateHandle, jstring obj_previewFile) {
	char* previewFile = (char*)env->GetStringUTFChars(obj_previewFile, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFilePreviewFile(env, clazz, updateHandle, obj_previewFile, previewFile);

	env->ReleaseStringUTFChars(obj_previewFile, previewFile);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFileTitle
(JNIEnv* env, jclass clazz, jlong updateHandle, jstring obj_title, char* title) {

//@line:194

		return SteamRemoteStorage()->UpdatePublishedFileTitle(updateHandle, title);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFileTitle(JNIEnv* env, jclass clazz, jlong updateHandle, jstring obj_title) {
	char* title = (char*)env->GetStringUTFChars(obj_title, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFileTitle(env, clazz, updateHandle, obj_title, title);

	env->ReleaseStringUTFChars(obj_title, title);

	return JNI_returnValue;
}

static inline jboolean wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFileDescription
(JNIEnv* env, jclass clazz, jlong updateHandle, jstring obj_description, char* description) {

//@line:198

		return SteamRemoteStorage()->UpdatePublishedFileDescription(updateHandle, description);
	
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFileDescription(JNIEnv* env, jclass clazz, jlong updateHandle, jstring obj_description) {
	char* description = (char*)env->GetStringUTFChars(obj_description, 0);

	jboolean JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFileDescription(env, clazz, updateHandle, obj_description, description);

	env->ReleaseStringUTFChars(obj_description, description);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFileVisibility(JNIEnv* env, jclass clazz, jlong updateHandle, jint visibility) {


//@line:202

		return SteamRemoteStorage()->UpdatePublishedFileVisibility(updateHandle, (ERemoteStoragePublishedFileVisibility) visibility);
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_updatePublishedFileTags(JNIEnv* env, jclass clazz, jlong updateHandle, jobjectArray tags, jint numTags) {


//@line:206

		SteamParamStringArray_t arrayTags;
		arrayTags.m_ppStrings = (numTags > 0) ? new const char*[numTags] : NULL;
		arrayTags.m_nNumStrings = numTags;
		for (int t = 0; t < numTags; t++) {
			arrayTags.m_ppStrings[t] = env->GetStringUTFChars((jstring) env->GetObjectArrayElement(tags, t), 0);
		}

		bool result = SteamRemoteStorage()->UpdatePublishedFileTags(updateHandle, &arrayTags);

		for (int t = 0; t < numTags; t++) {
			env->ReleaseStringUTFChars((jstring) env->GetObjectArrayElement(tags, t), arrayTags.m_ppStrings[t]);
		}
		delete[] arrayTags.m_ppStrings;

		return result;
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamRemoteStorageNative_commitPublishedFileUpdate(JNIEnv* env, jclass clazz, jlong callback, jlong updateHandle) {


//@line:224

		SteamRemoteStorageCallback* cb = (SteamRemoteStorageCallback*) callback;
		SteamAPICall_t handle = SteamRemoteStorage()->CommitPublishedFileUpdate(updateHandle);
		cb->onUpdatePublishedFileResultCall.Set(handle, cb, &SteamRemoteStorageCallback::onUpdatePublishedFileResult);
		return handle;
	

}

