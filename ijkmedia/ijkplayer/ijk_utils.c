//
// Created by 余益栋 on 2017/9/4.
//
#include "stdlib.h"
#include "stdio.h"
#include "libavutil/dict.h"
#include <inttypes.h>
#include "j4a/class/tv/danmaku/ijk/media/player/IjkMediaPlayer.h"
#include <jni.h>
#include <string.h>
#include <android/log.h>

#define IJKVERSION_GET_MAJOR(x)     ((x >> 16) & 0xFF)
#define IJKVERSION_GET_MINOR(x)     ((x >>  8) & 0xFF)
#define IJKVERSION_GET_MICRO(x)     ((x      ) & 0xFF)

//字符串拼接
char *appendCharPointer(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL) {
        return NULL;
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

#define FFP_VERSION_MODULE_NAME_LENGTH 13
char *ffp_show_version_str_log(const char *module, const char *version) {
    //char s[50];
    //sprintf(s, "%-*s: %s\n", FFP_VERSION_MODULE_NAME_LENGTH, module, version);
}

//将i转化位字符串存入str
char *convertInt2Str(char *str ,unsigned i)
{
    sprintf(str, "%d", i);
    return str;
}

char *convertIntPRId642Str(char *str ,int64_t i)
{
    sprintf(str, "%"PRId64, i);
    return str;
}

//
char *logUnsigned(unsigned value) {
    char major[10];
    convertInt2Str(major, (unsigned int)IJKVERSION_GET_MAJOR(value));
    char minor[10];
    convertInt2Str(minor, (unsigned int)IJKVERSION_GET_MINOR(value));
    char micro[10];
    convertInt2Str(micro, (unsigned int)IJKVERSION_GET_MICRO(value));
    char *tmpMajor = appendCharPointer(major, ".");
    char *tmpMinor = appendCharPointer(tmpMajor, minor);
    char *tmpMinor2 = appendCharPointer(tmpMinor, ".");
    char *tmpMicro = appendCharPointer(tmpMinor2, micro);
    return tmpMicro;
}

char *logDict(char* label, AVDictionary *dict) {
    AVDictionaryEntry *t = NULL;
    char* value = NULL;
    while ((t = av_dict_get(dict, "", t, AV_DICT_IGNORE_SUFFIX))) {
        if (value) {
            char* tmp0 = appendCharPointer(value, "\n");
            char* tmp1 = appendCharPointer(tmp0, label);
            char* tmp2 = appendCharPointer(tmp1 ,t->key);
            char* tmp3 = appendCharPointer(tmp2 ," = ");
            value = appendCharPointer(tmp3, t->value);
        } else {
            char* tmp0 = appendCharPointer(label, t->key);
            char* tmp1 = appendCharPointer(tmp0, " = ");
            value = appendCharPointer(tmp1, t->value);
        }
    }
    return value;
}

void post_event_log(JNIEnv *env, jobject weak_this, int what, int arg1, int arg2, jobject obj)
{
    // MPTRACE("post_event2(%p, %p, %d, %d, %d, %p)", (void*)env, (void*) weak_this, what, arg1, arg2, (void*)obj);
    //J4AC_IjkMediaPlayer__postEventFromNative(env, weak_this, what, arg1, arg2, obj);
    // MPTRACE("post_event2()=void");
}

unsigned char writeFile(char* content) {
    /*FILE *fp;
    fp = fopen("/sdcard/tieba_video.log", "a+");
    if (fp == NULL) {
        fclose(fp);
        return false;
    }
    int length = strlen(content);
    //for (int i = 0; i < 5; i++) {
        fwrite(content, length, 1, fp);
    //
    fclose(fp);*/
    return true;

}


