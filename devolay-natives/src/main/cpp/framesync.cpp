#include "devolay.h"

#include "me_walkerknapp_devolay_DevolayFrameSync.h"

JNIEXPORT jlong JNICALL Java_me_walkerknapp_devolay_DevolayFrameSync_framesyncCreate(JNIEnv *env, jclass jClazz, jlong pReceiver) {
    return (jlong) getNDILib()->framesync_create(reinterpret_cast<NDIlib_recv_instance_t>(pReceiver));
}

JNIEXPORT void JNICALL Java_me_walkerknapp_devolay_DevolayFrameSync_framesyncDestroy(JNIEnv *env, jclass jClazz, jlong pFramesync) {
    getNDILib()->framesync_destroy(reinterpret_cast<NDIlib_framesync_instance_t>(pFramesync));
}

JNIEXPORT void JNICALL Java_me_walkerknapp_devolay_DevolayFrameSync_framesyncCaptureAudio
        (JNIEnv *env, jclass jClazz, jlong pFramesync, jlong pFrame, jint jSampleRate, jint jNoChannels, jint jNoSamples) {
    getNDILib()->framesync_capture_audio(reinterpret_cast<NDIlib_framesync_instance_t>(pFramesync),
            reinterpret_cast<NDIlib_audio_frame_v2_t *>(pFrame),
            jSampleRate, jNoChannels, jNoSamples);
}

// For some reason, this isn't implemented in the DynamicLoad spec for NDI. It may be added in a future version
/*JNIEXPORT jint Java_me_walkerknapp_devolay_DevolayFrameSync_framesyncAudioQueueDepth
        (JNIEnv *env, jclass jClazz, jlong pFramesync) {
    return getNDILib()->NDIlib_framesync_audio_queue_depth(reinterpret_cast<NDIlib_framesync_instance_t *>(pFramesync));
}*/

JNIEXPORT void JNICALL Java_me_walkerknapp_devolay_DevolayFrameSync_framesyncFreeAudio
        (JNIEnv *env, jclass jClazz, jlong pFramesync, jlong pFrame) {
    getNDILib()->framesync_free_audio(reinterpret_cast<NDIlib_framesync_instance_t>(pFramesync),
            reinterpret_cast<NDIlib_audio_frame_v2_t *>(pFrame));
}

JNIEXPORT jboolean JNICALL Java_me_walkerknapp_devolay_DevolayFrameSync_framesyncCaptureVideo
        (JNIEnv *env, jclass jClazz, jlong pFramesync, jlong pFrame, jint jFrameFormatType) {
    getNDILib()->framesync_capture_video(reinterpret_cast<NDIlib_framesync_instance_t>(pFramesync),
            reinterpret_cast<NDIlib_video_frame_v2_t *>(pFrame),
            (NDIlib_frame_format_type_e)jFrameFormatType);

    return reinterpret_cast<NDIlib_video_frame_v2_t *>(pFrame)->p_data != (uint8_t *)nullptr;
}

JNIEXPORT void JNICALL Java_me_walkerknapp_devolay_DevolayFrameSync_framesyncFreeVideo
        (JNIEnv *env, jclass jClazz, jlong pFramesync, jlong pFrame) {
    getNDILib()->framesync_free_video(reinterpret_cast<NDIlib_framesync_instance_t>(pFramesync),
            reinterpret_cast<NDIlib_video_frame_v2_t *>(pFrame));
}
