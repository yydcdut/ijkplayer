//
// Created by 余益栋 on 2017/9/4.
//

#ifndef IJKPLAYER_IJK_UTILS_H
#define IJKPLAYER_IJK_UTILS_H

#include "j4a/class/tv/danmaku/ijk/media/player/IjkMediaPlayer.h"

//字符串拼接
char *appendCharPointer(const char *s1, const char *s2);

char *convertInt2Str(char *str ,unsigned i);

char *convertIntPRId642Str(char *str ,int64_t i);

char *logUnsigned(unsigned value);

char *logDict(char* label, AVDictionary *dict);

void post_event_log(JNIEnv *env, jobject weak_this, int what, int arg1, int arg2, jobject obj);

unsigned char writeFile(char* content);

#endif //IJKPLAYER_IJK_UTILS_H
