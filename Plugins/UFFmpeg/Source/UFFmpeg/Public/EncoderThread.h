// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "EncodeData.h"

/**
 * 
 */
class UCircleQueue;

DECLARE_DELEGATE_OneParam(VideoEncodeDelegate, uint8*)

class UFFMPEG_API FEncoderThread :public FRunnable 
{
public:

	FEncoderThread();
	~FEncoderThread();
	virtual bool Init() override; 
	virtual uint32 Run() override; 
	virtual void Stop() override;  
	virtual void Exit() override; 

	void CreateQueue(int video_data_size, int audio_data_size, int video_data_num, int audio_data_num);

	EncodeDelegate& GetAudioProcessDelegate();
	EncodeDelegate& GetAudioTimeProcessDelegate();

	bool InsertVideo(uint8* src);
	bool InsertAudio(uint8* src,uint8* time);

	FCriticalSection VideoBufferMutex;
	FCriticalSection AudioMutex;

	bool IsDone = false;
	VideoEncodeDelegate video_encode_delegate;
	void GetBufferData(uint8* data);

private:
	void RunEncode();
	void EncodeVideo();
	void EncodeAudio();

private:

	UCircleQueue* videobuffer_queue;
	UCircleQueue* audio_queue;
	UCircleQueue* audio_time_queue;

	uint8* video_data=nullptr;
};
