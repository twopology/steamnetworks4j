#include <org_twopology_steamnetworks4j_SteamControllerNative.h>

//@line:7

		#include <steam_api.h>
		#include "isteamcontroller.h"
	JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_init(JNIEnv* env, jclass clazz) {


//@line:12

		return SteamController()->Init();
	

}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_shutdown(JNIEnv* env, jclass clazz) {


//@line:16

		return SteamController()->Shutdown();
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_runFrame(JNIEnv* env, jclass clazz) {


//@line:20

		SteamController()->RunFrame();
	

}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamControllerNative_getConnectedControllers
(JNIEnv* env, jclass clazz, jlongArray obj_handlesOut, long long* handlesOut) {

//@line:24

		return SteamController()->GetConnectedControllers((ControllerHandle_t*) handlesOut);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getConnectedControllers(JNIEnv* env, jclass clazz, jlongArray obj_handlesOut) {
	long long* handlesOut = (long long*)env->GetPrimitiveArrayCritical(obj_handlesOut, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamControllerNative_getConnectedControllers(env, clazz, obj_handlesOut, handlesOut);

	env->ReleasePrimitiveArrayCritical(obj_handlesOut, handlesOut, 0);

	return JNI_returnValue;
}

JNIEXPORT jboolean JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_showBindingPanel(JNIEnv* env, jclass clazz, jlong controllerHandle) {


//@line:28

		return SteamController()->ShowBindingPanel((ControllerHandle_t) controllerHandle);
	

}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamControllerNative_getActionSetHandle
(JNIEnv* env, jclass clazz, jstring obj_actionSetName, char* actionSetName) {

//@line:32

		return SteamController()->GetActionSetHandle(actionSetName);
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getActionSetHandle(JNIEnv* env, jclass clazz, jstring obj_actionSetName) {
	char* actionSetName = (char*)env->GetStringUTFChars(obj_actionSetName, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamControllerNative_getActionSetHandle(env, clazz, obj_actionSetName, actionSetName);

	env->ReleaseStringUTFChars(obj_actionSetName, actionSetName);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_activateActionSet(JNIEnv* env, jclass clazz, jlong controllerHandle, jlong actionSetHandle) {


//@line:36

		SteamController()->ActivateActionSet((ControllerHandle_t) controllerHandle, (ControllerActionSetHandle_t) actionSetHandle);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getCurrentActionSet(JNIEnv* env, jclass clazz, jlong controllerHandle) {


//@line:40

		return SteamController()->GetCurrentActionSet((ControllerHandle_t) controllerHandle);
	

}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamControllerNative_getDigitalActionHandle
(JNIEnv* env, jclass clazz, jstring obj_actionName, char* actionName) {

//@line:44

		return SteamController()->GetDigitalActionHandle(actionName);
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getDigitalActionHandle(JNIEnv* env, jclass clazz, jstring obj_actionName) {
	char* actionName = (char*)env->GetStringUTFChars(obj_actionName, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamControllerNative_getDigitalActionHandle(env, clazz, obj_actionName, actionName);

	env->ReleaseStringUTFChars(obj_actionName, actionName);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getDigitalActionData(JNIEnv* env, jclass clazz, jlong controllerHandle, jlong digitalActionHandle, jobject digitalActionData) {


//@line:50


		ControllerDigitalActionData_t result = SteamController()->GetDigitalActionData(
			(ControllerHandle_t) controllerHandle, (ControllerDigitalActionHandle_t) digitalActionHandle);

		{
			jclass clazz = env->GetObjectClass(digitalActionData);

			jfieldID field = env->GetFieldID(clazz, "state", "Z");
			env->SetBooleanField(digitalActionData, field, (jboolean) result.bState);

			field = env->GetFieldID(clazz, "active", "Z");
			env->SetBooleanField(digitalActionData, field, (jboolean) result.bActive);
		}
	

}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamControllerNative_getDigitalActionOrigins
(JNIEnv* env, jclass clazz, jlong controllerHandle, jlong actionSetHandle, jlong digitalActionHandle, jintArray obj_originsOut, int* originsOut) {

//@line:69


		return SteamController()->GetDigitalActionOrigins((ControllerHandle_t) controllerHandle,
			(ControllerActionSetHandle_t) actionSetHandle, (ControllerDigitalActionHandle_t) digitalActionHandle,
			(EControllerActionOrigin*) originsOut);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getDigitalActionOrigins(JNIEnv* env, jclass clazz, jlong controllerHandle, jlong actionSetHandle, jlong digitalActionHandle, jintArray obj_originsOut) {
	int* originsOut = (int*)env->GetPrimitiveArrayCritical(obj_originsOut, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamControllerNative_getDigitalActionOrigins(env, clazz, controllerHandle, actionSetHandle, digitalActionHandle, obj_originsOut, originsOut);

	env->ReleasePrimitiveArrayCritical(obj_originsOut, originsOut, 0);

	return JNI_returnValue;
}

static inline jlong wrapped_Java_org_twopology_steamnetworks4j_SteamControllerNative_getAnalogActionHandle
(JNIEnv* env, jclass clazz, jstring obj_actionName, char* actionName) {

//@line:76

		return SteamController()->GetAnalogActionHandle(actionName);
	
}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getAnalogActionHandle(JNIEnv* env, jclass clazz, jstring obj_actionName) {
	char* actionName = (char*)env->GetStringUTFChars(obj_actionName, 0);

	jlong JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamControllerNative_getAnalogActionHandle(env, clazz, obj_actionName, actionName);

	env->ReleaseStringUTFChars(obj_actionName, actionName);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getAnalogActionData(JNIEnv* env, jclass clazz, jlong controllerHandle, jlong analogActionHandle, jobject analogActionData) {


//@line:82


		ControllerAnalogActionData_t result = SteamController()->GetAnalogActionData(
			(ControllerHandle_t) controllerHandle, (ControllerAnalogActionHandle_t) analogActionHandle);

		{
			jclass clazz = env->GetObjectClass(analogActionData);

			jfieldID field = env->GetFieldID(clazz, "mode", "I");
			env->SetIntField(analogActionData, field, (jint) result.eMode);

			field = env->GetFieldID(clazz, "x", "F");
			env->SetFloatField(analogActionData, field, (jfloat) result.x);

			field = env->GetFieldID(clazz, "y", "F");
			env->SetFloatField(analogActionData, field, (jfloat) result.y);

			field = env->GetFieldID(clazz, "active", "Z");
			env->SetBooleanField(analogActionData, field, (jboolean) result.bActive);
		}
	

}

static inline jint wrapped_Java_org_twopology_steamnetworks4j_SteamControllerNative_getAnalogActionOrigins
(JNIEnv* env, jclass clazz, jlong controllerHandle, jlong actionSetHandle, jlong analogActionHandle, jintArray obj_originsOut, int* originsOut) {

//@line:107


		return SteamController()->GetAnalogActionOrigins((ControllerHandle_t) controllerHandle,
			(ControllerActionSetHandle_t) actionSetHandle, (ControllerAnalogActionHandle_t) analogActionHandle,
			(EControllerActionOrigin*) originsOut);
	
}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getAnalogActionOrigins(JNIEnv* env, jclass clazz, jlong controllerHandle, jlong actionSetHandle, jlong analogActionHandle, jintArray obj_originsOut) {
	int* originsOut = (int*)env->GetPrimitiveArrayCritical(obj_originsOut, 0);

	jint JNI_returnValue = wrapped_Java_org_twopology_steamnetworks4j_SteamControllerNative_getAnalogActionOrigins(env, clazz, controllerHandle, actionSetHandle, analogActionHandle, obj_originsOut, originsOut);

	env->ReleasePrimitiveArrayCritical(obj_originsOut, originsOut, 0);

	return JNI_returnValue;
}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_stopAnalogActionMomentum(JNIEnv* env, jclass clazz, jlong controllerHandle, jlong analogActionHandle) {


//@line:115


		SteamController()->StopAnalogActionMomentum((ControllerHandle_t) controllerHandle,
			(ControllerAnalogActionHandle_t) analogActionHandle);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_triggerHapticPulse(JNIEnv* env, jclass clazz, jlong controllerHandle, jint targetPad, jint durationMicroSec) {


//@line:123


		SteamController()->TriggerHapticPulse((ControllerHandle_t) controllerHandle,
			(ESteamControllerPad) targetPad, (unsigned short) durationMicroSec);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_triggerRepeatedHapticPulse(JNIEnv* env, jclass clazz, jlong controllerHandle, jint targetPad, jint durationMicroSec, jint offMicroSec, jint repeat, jint flags) {


//@line:134


		SteamController()->TriggerRepeatedHapticPulse((ControllerHandle_t) controllerHandle,
				(ESteamControllerPad) targetPad, (unsigned short) durationMicroSec,
				(unsigned short) offMicroSec, (unsigned short) repeat, (unsigned int) flags);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_triggerVibration(JNIEnv* env, jclass clazz, jlong controllerHandle, jshort leftSpeed, jshort rightSpeed) {


//@line:143


		SteamController()->TriggerVibration((ControllerHandle_t) controllerHandle,
			(unsigned short) leftSpeed, (unsigned short) rightSpeed);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_setLEDColor(JNIEnv* env, jclass clazz, jlong controllerHandle, jbyte colorR, jbyte colorG, jbyte colorB, jint flags) {


//@line:150


		SteamController()->SetLEDColor((ControllerHandle_t) controllerHandle,
			colorR, colorG, colorB, (unsigned int) flags);
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getGamepadIndexForController(JNIEnv* env, jclass clazz, jlong controllerHandle) {


//@line:156

		return SteamController()->GetGamepadIndexForController((ControllerHandle_t) controllerHandle);
	

}

JNIEXPORT jlong JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getControllerForGamepadIndex(JNIEnv* env, jclass clazz, jint index) {


//@line:160

		return SteamController()->GetControllerForGamepadIndex(index);
	

}

JNIEXPORT void JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getMotionData(JNIEnv* env, jclass clazz, jlong controllerHandle, jfloatArray obj_motionData) {
	float* motionData = (float*)env->GetPrimitiveArrayCritical(obj_motionData, 0);


//@line:164

		ControllerMotionData_t data = SteamController()->GetMotionData((ControllerHandle_t) controllerHandle);

		motionData[0] = data.rotQuatX;
		motionData[1] = data.rotQuatY;
		motionData[2] = data.rotQuatZ;
		motionData[3] = data.rotQuatW;

		motionData[4] = data.posAccelX;
		motionData[5] = data.posAccelY;
		motionData[6] = data.posAccelZ;

		motionData[7] = data.rotVelX;
		motionData[8] = data.rotVelY;
		motionData[9] = data.rotVelZ;
	
	env->ReleasePrimitiveArrayCritical(obj_motionData, motionData, 0);

}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getStringForActionOrigin(JNIEnv* env, jclass clazz, jint origin) {


//@line:181

		return env->NewStringUTF(SteamController()->GetStringForActionOrigin((EControllerActionOrigin) origin));
	

}

JNIEXPORT jstring JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getGlyphForActionOrigin(JNIEnv* env, jclass clazz, jint origin) {


//@line:185

		return env->NewStringUTF(SteamController()->GetGlyphForActionOrigin((EControllerActionOrigin) origin));
	

}

JNIEXPORT jint JNICALL Java_org_twopology_steamnetworks4j_SteamControllerNative_getInputTypeForHandle(JNIEnv* env, jclass clazz, jlong controllerHandle) {


//@line:189

		return SteamController()->GetInputTypeForHandle((ControllerHandle_t) controllerHandle);
	

}

