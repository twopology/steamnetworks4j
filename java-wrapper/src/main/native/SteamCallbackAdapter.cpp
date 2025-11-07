#include "SteamCallbackAdapter.h"
#include <iostream>
#include <cstdio>
#include <pthread.h>

SteamCallbackAdapter::SteamCallbackAdapter(JNIEnv* env, jobject callback) {
	fprintf(stderr, "[SteamCallbackAdapter v2.0] Constructor called, callback=%p\n", callback);
	fflush(stderr);
	env->GetJavaVM(&m_vm);
	if (callback != NULL) {
		m_callback = env->NewGlobalRef(callback);
		if (m_callback == NULL) {
			fprintf(stderr, "[SteamCallbackAdapter] ERROR: NewGlobalRef failed!\n");
			fflush(stderr);
			// NewGlobalRef failed - this is a serious error
			// Set to NULL explicitly to avoid crashes later
			m_callback = NULL;
		}
	} else {
		fprintf(stderr, "[SteamCallbackAdapter] WARNING: callback parameter is NULL\n");
		fflush(stderr);
		m_callback = NULL;
	}
	m_callbackClass = 0;
}

SteamCallbackAdapter::SteamCallbackAdapter(JNIEnv* env, jclass callbackClass) {
	env->GetJavaVM(&m_vm);
	m_callback = 0;
	m_callbackClass = callbackClass;
}

SteamCallbackAdapter::~SteamCallbackAdapter() {
    if (m_callback != 0) {
        JNIEnv* env;
        bool attached = attachThread(&env);
        env->DeleteGlobalRef(m_callback);
        if (attached) {
            detachThread();
        }
    }
}

void SteamCallbackAdapter::attach(SteamInvokeCallbackFunction fn) const {
    JNIEnv* env;
    bool attached = attachThread(&env);
    fn(env);
    if (attached) {
        detachThread();
    }
}

bool SteamCallbackAdapter::attachThread(JNIEnv** env) const {
    jint status = m_vm->GetEnv((void**) env, JNI_VERSION_1_6);
    if (status == JNI_EDETACHED) {
    	m_vm->AttachCurrentThread((void**) env, NULL);
    	return true;
    }
    return false;
}

void SteamCallbackAdapter::detachThread() const {
	m_vm->DetachCurrentThread();
}

void SteamCallbackAdapter::callVoidMethod(JNIEnv* env, const char* method, const char* signature, ...) const {
	pthread_t threadId = pthread_self();
	
	if (m_callback == NULL) {
		fprintf(stderr, "[SteamCallbackAdapter] ERROR: m_callback is NULL\n");
		fflush(stderr);
		jclass ex = env->FindClass("org/twopology/steamnetworks4j/SteamException");
		if (ex != NULL) {
			env->ThrowNew(ex, "Callback object is null - cannot invoke method.");
		}
		return;
	}
	
	// Check if env is valid and callback object is valid by trying to get a local ref first
	jobject localRef = env->NewLocalRef(m_callback);
	if (localRef == NULL) {
		fprintf(stderr, "[SteamCallbackAdapter] ERROR: NewLocalRef returned NULL - global ref is invalid\n");
		fflush(stderr);
		// Global ref is invalid - object was likely garbage collected or JNI error
		jclass ex = env->FindClass("org/twopology/steamnetworks4j/SteamException");
		if (ex != NULL) {
			env->ThrowNew(ex, "Callback object reference is invalid.");
		}
		return;
	}
	
	// Check for pending exceptions before calling GetObjectClass
	if (env->ExceptionCheck()) {
		fprintf(stderr, "[SteamCallbackAdapter] ERROR: Exception pending before GetObjectClass\n");
		fflush(stderr);
		env->ExceptionDescribe();
		env->ExceptionClear();
		env->DeleteLocalRef(localRef);
		return;
	}
	
	jclass clazz = NULL;
	// Try to get the class - this is where the crash happens
	clazz = env->GetObjectClass(localRef);
	
	// Check for exceptions after GetObjectClass
	if (env->ExceptionCheck()) {
		fprintf(stderr, "[SteamCallbackAdapter] ERROR: Exception occurred in GetObjectClass\n");
		fflush(stderr);
		env->ExceptionDescribe();
		env->ExceptionClear();
		env->DeleteLocalRef(localRef);
		return;
	}
	
	jclass ex = env->FindClass("org/twopology/steamnetworks4j/SteamException");
	if (clazz == 0 || clazz == NULL) {
		fprintf(stderr, "[SteamCallbackAdapter] ERROR: GetObjectClass returned NULL/0\n");
		fflush(stderr);
		env->DeleteLocalRef(localRef);
	    if (ex != NULL) {
			env->ThrowNew(ex, "Couldn't retrieve class for callback object.");
		}
	} else {
		jmethodID methodID = env->GetMethodID(clazz, method, signature);
		if (methodID == 0) {
			fprintf(stderr, "[SteamCallbackAdapter] ERROR: GetMethodID returned NULL for %s\n", method);
			fflush(stderr);
    	    env->ThrowNew(ex, "Couldn't retrieve callback method.");
		} else {
			va_list args;
			va_start(args, signature);
			env->CallVoidMethodV(localRef, methodID, args);
			va_end(args);

			jthrowable ex = env->ExceptionOccurred();
			if (ex != NULL) {
				fprintf(stderr, "[SteamCallbackAdapter] Exception occurred in callback method\n");
				fflush(stderr);
				env->ExceptionDescribe();
				env->ExceptionClear();
				env->DeleteLocalRef(ex);
			}
		}
		env->DeleteLocalRef(clazz);
		env->DeleteLocalRef(localRef);
	}
}

void SteamCallbackAdapter::callStaticVoidMethod(JNIEnv* env, const char* method, const char* signature, ...) const {
	jmethodID methodID = env->GetStaticMethodID(m_callbackClass, method, signature);
	jclass ex = env->FindClass("org/twopology/steamnetworks4j/SteamException");
	if (methodID == 0) {
	    env->ThrowNew(ex, "Couldn't retrieve static callback method.");
	} else {
		va_list args;
		va_start(args, signature);
		env->CallStaticVoidMethodV(m_callbackClass, methodID, args);
		va_end(args);

		jthrowable ex = env->ExceptionOccurred();
		if (ex != NULL) {
			env->ExceptionDescribe();
			env->ExceptionClear();
			env->DeleteLocalRef(ex);
		}
	}
}
